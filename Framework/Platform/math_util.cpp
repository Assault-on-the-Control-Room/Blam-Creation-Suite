#include "platform-private-pch.h"

// float->half variants.
// by Fabian "ryg" Giesen.
//
// I hereby place this code in the public domain, as per the terms of the
// CC0 license:
//
//   https://creativecommons.org/publicdomain/zero/1.0/
//
// float_to_half_full: This is basically the ISPC stdlib code, except
// I preserve the sign of NaNs (any good reason not to?)
//
// float_to_half_fast: Almost the same, with some unnecessary cases cut.
//
// float_to_half_fast2: This is where it gets a bit weird. See lengthy
// commentary inside the function code. I'm a bit on the fence about two
// things:
// 1. This *will* behave differently based on whether flush-to-zero is
//    enabled or not. Is this acceptable for ISPC?
// 2. I'm a bit on the fence about NaNs. For half->float, I opted to extend
//    the mantissa (preserving both qNaN and sNaN contents) instead of always
//    returning a qNaN like the original ISPC stdlib code did. For float->half
//    the "natural" thing would be just taking the top mantissa bits, except
//    that doesn't work; if they're all zero, we might turn a sNaN into an
//    Infinity (seriously bad!). I could test for this case and do a sticky
//    bit-like mechanism, but that's pretty ugly. Instead I go with ISPC
//    std lib behavior in this case and just return a qNaN - not quite symmetric
//    but at least it's always safe. Any opinions?
//
// I'll just go ahead and give "fast2" the same treatment as my half->float code,
// but if there's concerns with the way it works I might revise it later, so watch
// this spot.
//
// float_to_half_fast3: Bitfields removed. Ready for SSE2-ification :)
//
// float_to_half_SSE2: Exactly what it says on the tin. Beware, this works slightly
// differently from float_to_half_fast3 - the clamp and bias steps in the "normal" path
// are interchanged, since I get "minps" on every SSE2 target, but "pminsd" only for
// SSE4.1 targets. This code does what it should and is remarkably short, but the way
// it ended up working is "nonobvious" to phrase it politely.
//
// approx_float_to_half: Simpler (but less accurate) version that matches the Fox
// toolkit float->half conversions: http://blog.fox-toolkit.org/?p=40 - note that this
// also (incorrectly) translates some sNaNs into infinity, so be careful!
//
// approx_float_to_half_SSE2: SSE2 version of above.
//
// ----
//
// UPDATE 2016-01-25: Now also with a variant that implements proper round-to-nearest-even.
// It's a bit more expensive and has seen less tweaking than the other variants. On the
// plus side, it doesn't produce subnormal FP32 values as part of generating subnormal
// FP16 values, so the performance is a lot more consistent.
//
// float_to_half_rtne_full: Unoptimized round-to-nearest-break-ties-to-even reference
// implementation.
// 
// float_to_half_fast3_rtne: Variant of float_to_half_fast3 that performs round-to-
// nearest-even.
//
// float_to_half_rtne_SSE2: SSE2 implementation of float_to_half_fast3_rtne.
//
// All three functions have been exhaustively tested to produce the same results on
// all 32-bit floating-point numbers with SSE arithmetic in round-to-nearest-even mode.
// No guarantees for what happens with other rounding modes! (See testbed code.)
//
// ----
//
// Oh, and enumerating+testing all 32-bit floats takes some time, especially since
// we will snap a significant fraction of the overall FP32 range to denormals, not
// exactly a fast operation. There's a reason this one prints regular progress
// reports. You've been warned.

#include <stdint.h>

typedef unsigned int uint;

union FP32
{
	uint u;
	float f;
	struct
	{
		uint Mantissa : 23;
		uint Exponent : 8;
		uint Sign : 1;
	};
};

union FP16
{
	unsigned short u;
	struct
	{
		uint Mantissa : 10;
		uint Exponent : 5;
		uint Sign : 1;
	};
};

// Original ISPC reference version; this always rounds ties up.
static FP16 _float_to_half(FP32 f)
{
	FP16 o = { 0 };

	// Based on ISPC reference code (with minor modifications)
	if (f.Exponent == 0) // Signed zero/denormal (which will underflow)
		o.Exponent = 0;
	else if (f.Exponent == 255) // Inf or NaN (all exponent bits set)
	{
		o.Exponent = 31;
		o.Mantissa = f.Mantissa ? 0x200 : 0; // NaN->qNaN and Inf->Inf
	}
	else // Normalized number
	{
		// Exponent unbias the single, then bias the halfp
		int newexp = f.Exponent - 127 + 15;
		if (newexp >= 31) // Overflow, return signed infinity
			o.Exponent = 31;
		else if (newexp <= 0) // Underflow
		{
			if ((14 - newexp) <= 24) // Mantissa might be non-zero
			{
				uint mant = f.Mantissa | 0x800000; // Hidden 1 bit
				o.Mantissa = mant >> (14 - newexp);
				if ((mant >> (13 - newexp)) & 1) // Check for rounding
					o.u++; // Round, might overflow into exp bit, but this is OK
			}
		}
		else
		{
			o.Exponent = newexp;
			o.Mantissa = f.Mantissa >> 13;
			if (f.Mantissa & 0x1000) // Check for rounding
				o.u++; // Round, might overflow to inf, this is OK
		}
	}

	o.Sign = f.Sign;
	return o;
}

// from half->float code - just for verification.
static FP32 _half_to_float(FP16 h)
{
	static const FP32 magic = { 113 << 23 };
	static const uint shifted_exp = 0x7c00 << 13; // exponent mask after shift
	FP32 o;

	o.u = (h.u & 0x7fff) << 13;     // exponent/mantissa bits
	uint exp = shifted_exp & o.u;   // just the exponent
	o.u += (127 - 15) << 23;        // exponent adjust

	// handle exponent special cases
	if (exp == shifted_exp) // Inf/NaN?
		o.u += (128 - 16) << 23;    // extra exp adjust
	else if (exp == 0) // Zero/Denormal?
	{
		o.u += 1 << 23;             // extra exp adjust
		o.f -= magic.f;             // renormalize
	}

	o.u |= (h.u & 0x8000) << 16;    // sign bit
	return o;
}

float half_to_float(uint16_t a)
{
	FP16 h;
	h.u = a;
	FP32 f = _half_to_float(h);
	return f.f;

}

uint16_t float_to_half(float a)
{
	FP32 f;
	f.f = a;

	FP16 h = _float_to_half(f);

	return h.u;
}

extern "C" float __gnu_h2f_ieee(uint16_t a)
{
	FP16 h;
	h.u = a;
	FP32 f = _half_to_float(h);
	return f.f;

}

extern "C" uint16_t __gnu_f2h_ieee(float a)
{
	FP32 f;
	f.f = a;

	FP16 h = _float_to_half(f);

	return h.u;
}
