#pragma once

namespace blofeld
{
	enum e_field : unsigned long
	{
		_field_string,
		_field_long_string,
		_field_string_id,
		_field_old_string_id,
		_field_char_integer,
		_field_short_integer,
		_field_long_integer,
		_field_int64_integer,
		_field_angle,
		_field_tag,
		_field_char_enum,
		_field_enum,
		_field_long_enum,
		_field_long_flags,
		_field_word_flags,
		_field_byte_flags,
		_field_point_2d,
		_field_rectangle_2d,
		_field_rgb_color,
		_field_argb_color,
		_field_real,
		_field_real_fraction,
		_field_real_point_2d,
		_field_real_point_3d,
		_field_real_vector_2d,
		_field_real_vector_3d,
		_field_real_quaternion,
		_field_real_euler_angles_2d,
		_field_real_euler_angles_3d,
		_field_real_plane_2d,
		_field_real_plane_3d,
		_field_real_rgb_color,
		_field_real_argb_color,
		_field_real_hsv_color,
		_field_real_ahsv_color,
		_field_short_bounds,
		_field_angle_bounds,
		_field_real_bounds,
		_field_real_fraction_bounds,
		_field_tag_reference,
		_field_block,
		_field_long_block_flags,
		_field_word_block_flags,
		_field_byte_block_flags,
		_field_char_block_index,
		_field_custom_char_block_index,
		_field_short_block_index,
		_field_custom_short_block_index,
		_field_long_block_index,
		_field_custom_long_block_index,
		_field_data,
		_field_vertex_buffer,
		_field_pad,
		_field_useless_pad,
		_field_skip,
		_field_non_cache_runtime_value,
		_field_explanation,
		_field_custom,
		_field_struct,
		_field_array,
		_field_pageable,
		_field_api_interop,
		_field_terminator,
		_field_byte_integer,
		_field_word_integer,
		_field_dword_integer,
		_field_qword_integer,

		_field_type_non_standard_custom_type, // custom fields begin here
		_field_pointer,
		_field_half,
		_field_type_non_standard, // custom fields begin here
		_field_version_equal,
		_field_version_not_equal,
		_field_version_less,
		_field_version_greater,
		_field_version_less_or_equal,
		_field_version_greater_or_equal,
		_field_version_platform_include,
		_field_version_platform_exclude,
		_field_version_custom,
		k_number_of_blofeld_field_types
	};

	inline uint32_t get_blofeld_field_size(e_platform_type platform_type, e_field field)
	{
		if (field > _field_type_non_standard)
		{
			return 0;
		}
		switch (field)
		{
		case _field_string:							return sizeof(::c_static_string<32>);
		case _field_long_string:					return sizeof(::c_static_string<256>);
		case _field_string_id:						return sizeof(string_id);
		case _field_old_string_id:					return sizeof(::c_old_string_id);
		case _field_char_integer:					return sizeof(char);
		case _field_short_integer:					return sizeof(short);
		case _field_long_integer:					return sizeof(long);
		case _field_int64_integer:					return sizeof(long long);
		case _field_angle:							return sizeof(angle);
		case _field_tag:							return sizeof(tag);
		case _field_char_enum:						return sizeof(char);
		case _field_enum:							return sizeof(short);
		case _field_long_enum:						return sizeof(long);
		case _field_long_flags:						return sizeof(long);
		case _field_word_flags:						return sizeof(word);
		case _field_byte_flags:						return sizeof(byte);
		case _field_point_2d:						return sizeof(::s_point2d);
		case _field_rectangle_2d:					return sizeof(::s_rectangle2d);
		case _field_rgb_color:						return sizeof(::pixel32);
		case _field_argb_color:						return sizeof(::pixel32);
		case _field_real:							return sizeof(::real);
		case _field_real_fraction:					return sizeof(::real_fraction);
		case _field_real_point_2d:					return sizeof(::real_point2d);
		case _field_real_point_3d:					return sizeof(::real_point3d);
		case _field_real_vector_2d:					return sizeof(::real_vector2d);
		case _field_real_vector_3d:					return sizeof(::real_vector3d);
		case _field_real_quaternion:				return sizeof(::real_quaternion);
		case _field_real_euler_angles_2d:			return sizeof(::real_euler_angles2d);
		case _field_real_euler_angles_3d:			return sizeof(::real_euler_angles3d);
		case _field_real_plane_2d:					return sizeof(::real_plane2d);
		case _field_real_plane_3d:					return sizeof(::real_plane3d);
		case _field_real_rgb_color:					return sizeof(::rgb_color);
		case _field_real_argb_color:				return sizeof(::argb_color);
		case _field_real_hsv_color:					return sizeof(::real_hsv_color);
		case _field_real_ahsv_color:				return sizeof(::real_ahsv_color);
		case _field_short_bounds:					return sizeof(::short_bounds);
		case _field_angle_bounds:					return sizeof(::angle_bounds);
		case _field_real_bounds:					return sizeof(::real_bounds);
		case _field_real_fraction_bounds:			return sizeof(::real_fraction_bounds);
		case _field_tag_reference:					return sizeof(::s_tag_reference);
		case _field_block:							return sizeof(::s_tag_block);
		case _field_long_block_flags:				return sizeof(long);
		case _field_word_block_flags:				return sizeof(word);
		case _field_byte_block_flags:				return sizeof(byte);
		case _field_char_block_index:				return sizeof(char);
		case _field_custom_char_block_index:		return sizeof(char);
		case _field_short_block_index:				return sizeof(short);
		case _field_custom_short_block_index:		return sizeof(short);
		case _field_long_block_index:				return sizeof(long);
		case _field_custom_long_block_index:		return sizeof(long);
		case _field_data:							return sizeof(::s_tag_data);
		case _field_vertex_buffer:					return sizeof(::s_tag_d3d_vertex_buffer);
		case _field_pad:							return 0;	// dynamic
		case _field_useless_pad:					return 0;	// dynamic
		case _field_skip:							return 0;	// dynamic
		case _field_non_cache_runtime_value:		return sizeof(long);
		case _field_explanation:					return 0;	// empty
		case _field_custom:							return 0;	// empty
		case _field_struct:							return 0;	// dynamic
		case _field_array:							return 0;	// dynamic
		case _field_pageable:						return sizeof(::s_tag_resource);
		case _field_api_interop:					return sizeof(::s_tag_interop);
		case _field_terminator:						return 0;	// empty
		case _field_byte_integer:					return sizeof(byte);
		case _field_word_integer:					return sizeof(word);
		case _field_dword_integer:					return sizeof(dword);
		case _field_qword_integer:					return sizeof(qword);
		case _field_pointer:						return get_platform_pointer_size(platform_type); // #NONSTANDARD
		case _field_half:							return sizeof(uint16_t);
		default: FATAL_ERROR(L"unknown field type");
		}
	}

	inline const char* field_to_string(e_field field)
	{
		switch (field)
		{
		case _field_string:									return "string";
		case _field_long_string:							return "long string";
		case _field_string_id:								return "string id";
		case _field_old_string_id:							return "old string id";
		case _field_char_integer:							return "char integer";
		case _field_short_integer:							return "short integer";
		case _field_long_integer:							return "long integer";
		case _field_int64_integer:							return "int64 integer";
		case _field_angle:									return "angle";
		case _field_tag:									return "tag";
		case _field_char_enum:								return "char enum";
		case _field_enum:									return "short enum";
		case _field_long_enum:								return "long enum";
		case _field_long_flags:								return "long flags";
		case _field_word_flags:								return "word flags";
		case _field_byte_flags:								return "byte flags";
		case _field_point_2d:								return "point 2d";
		case _field_rectangle_2d:							return "rectangle 2d";
		case _field_rgb_color:								return "rgb color";
		case _field_argb_color:								return "argb color";
		case _field_real:									return "real";
		case _field_real_fraction:							return "real fraction";
		case _field_real_point_2d:							return "real point 2d";
		case _field_real_point_3d:							return "real point 3d";
		case _field_real_vector_2d:							return "real vector 2d";
		case _field_real_vector_3d:							return "real vector 3d";
		case _field_real_quaternion:						return "real quaternion";
		case _field_real_euler_angles_2d:					return "real euler angles 2d";
		case _field_real_euler_angles_3d:					return "real euler angles 3d";
		case _field_real_plane_2d:							return "real plane 2d";
		case _field_real_plane_3d:							return "real plane 3d";
		case _field_real_rgb_color:							return "real rgb color";
		case _field_real_argb_color:						return "real argb color";
		case _field_real_hsv_color:							return "real hsv color";
		case _field_real_ahsv_color:						return "real ahsv color";
		case _field_short_bounds:							return "short integer bounds";
		case _field_angle_bounds:							return "angle bounds";
		case _field_real_bounds:							return "real bounds";
		case _field_real_fraction_bounds:					return "fraction bounds";
		case _field_tag_reference:							return "tag reference";
		case _field_block:									return "block";
		case _field_long_block_flags:						return "long block flags";
		case _field_word_block_flags:						return "word block flags";
		case _field_byte_block_flags:						return "byte block flags";
		case _field_char_block_index:						return "char block index";
		case _field_custom_char_block_index:				return "custom char block index";
		case _field_short_block_index:						return "short block index";
		case _field_custom_short_block_index:				return "custom short block index";
		case _field_long_block_index:						return "long block index";
		case _field_custom_long_block_index:				return "custom long block index";
		case _field_data:									return "data";
		case _field_vertex_buffer:							return "vertex buffer";
		case _field_pad:									return "pad";
		case _field_useless_pad:							return "useless pad";
		case _field_skip:									return "skip";
		case _field_non_cache_runtime_value:				return "non-cache runtime value";
		case _field_explanation:							return "explanation";
		case _field_custom:									return "custom";
		case _field_struct:									return "struct";
		case _field_array:									return "array";
		case _field_pageable:								return "pageable resource";
		case _field_api_interop:							return "api interop";
		case _field_terminator:								return "terminator X";
		case _field_byte_integer:							return "byte integer";
		case _field_word_integer:							return "word integer";
		case _field_dword_integer:							return "dword integer";
		case _field_qword_integer:							return "qword integer";
		case _field_pointer:								return "pointer"; // #NONSTANDARD
		case _field_half:									return "half"; // #NONSTANDARD
		}
		return nullptr;
	}
}
