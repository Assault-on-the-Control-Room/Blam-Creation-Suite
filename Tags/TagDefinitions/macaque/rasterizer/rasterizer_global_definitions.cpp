#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		rasterizer_globals_group,
		RASTERIZER_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		rasterizer_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		rasterizer_globals_block,
		"rasterizer_globals_block",
		1,
		rasterizer_globals_struct_definition);

	#define DEFAULT_TEXTURES_REFS_BLOCK_ID { 0x7B0790D8, 0xD39D47C8, 0x85721089, 0x8A80F128 }
	TAG_BLOCK(
		default_textures_refs_block,
		"default_textures_refs_block",
		32,
		"s_global_bitmaps",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DEFAULT_TEXTURES_REFS_BLOCK_ID)
	{
		{ _field_long_flags, "options", &global_bitmap_flags },
		{ _field_tag_reference, "default bitmaps", &bitmap_reference$11 },
		{ _field_terminator }
	};

	#define MATERIAL_TEXTURES_REFS_BLOCK_ID { 0x0F4DB844, 0xFD9F48CD, 0xB9DCAA47, 0x2D47CCD4 }
	TAG_BLOCK(
		material_textures_refs_block,
		"material_textures_refs_block",
		16,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_TEXTURES_REFS_BLOCK_ID)
	{
		{ _field_tag_reference, "material textures", &global_bitmap_reference },
		{ _field_terminator }
	};

	#define EXPLICIT_SHADER_REFS_BLOCK_ID { 0xD3D3046B, 0xF1924CAB, 0x95BC117B, 0x3CCD846F }
	TAG_BLOCK(
		explicit_shader_refs_block,
		"explicit_shader_refs_block",
		256,
		"c_rasterizer_globals::s_explicit_shader",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EXPLICIT_SHADER_REFS_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "name" },


		{ _field_tag_reference, "explicit vertex shader", &explicit_shader_refs_block_explicit_vertex_shader_reference },
		{ _field_tag_reference, "explicit pixel shader", FIELD_FLAG_INDEX, &explicit_shader_refs_block_explicit_pixel_shader_reference },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_legacy, _field_version_less, _engine_type_halo4, 1 },
		{ _field_legacy, _field_tag_reference, "explicit compute shader^", &explicit_shader_refs_block_explicit_pixel_shader_reference },


		{ _field_terminator }
	};

	#define RASTERIZER_GLOBALS_STRUCT_DEFINITION_ID { 0x1E0FE0EA, 0x9D3048D5, 0x9D86E7F7, 0xCAA91C4A }
	TAG_STRUCT(
		rasterizer_globals_struct_definition,
		"rasterizer_globals_struct_definition",
		"c_rasterizer_globals",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RASTERIZER_GLOBALS_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("default bitmaps", nullptr, FIELD_FLAG_NONE, "0:  ............... default 2D texture (white)\n1:  ............... default normal map (no bump)\n2:  ............... default cube map (error pattern)\n3:  ............... color bars\n4:  ............... black 2D texture\n5:  ............... transparent black 2D texture\n6:  ............... gray 2D texture\n7:  ............... auto exposure weight\n8:  ............... auto exposure weight (4x3)\n9:  ............... stencil dither pattern\n10: ............... smooth noise warp\n11: ............... ripple pattern\n12: ............... rain ripple\n13: ............... unsigned noise\n14: ............... MLAA area map\n15: ............... red 2D texture\n16: ............... green 2D texture\n17: ............... blue 2D texture\n18: ............... cyan 2D texture\n19: ............... dxt5 atlas texture\n20: ............... dxn atlas texture\n"),
		{ _field_block, "default bitmaps", &default_textures_refs_block },
		FIELD_EXPLANATION("material textures", nullptr, FIELD_FLAG_NONE, "0: ............... lightmap falloff sharpening\n6: ............... Approximate specular curve\n"),
		{ _field_block, "material textures", &material_textures_refs_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_tag_reference, "simple vertex shader", &global_vertex_shader_reference },
		{ _field_legacy, _field_tag_reference, "simple pixel shader", &global_pixel_shader_reference },

		FIELD_EXPLANATION("explicit shaders", nullptr, FIELD_FLAG_NONE, "0: ............... debug\n1: ............... debug2d\n2: ............... copy w/ scale\n3: ............... edge detect\n4: ............... blendshape generate\n5: ............... bloom: downsample 4x4 (with bloom curve)\n6: ............... bloom: downsample 4x4\n7: ............... bloom: copy RGBE -> RGB\n8: ............... debug_mesh\n9: ............... bloom: add downsampled\n10: ...............bloom: add\n11: .............. bloom: kernel blur (11 horizontal)\n12: .............. bloom: kernel blur (11 vertical)\n13: .............. cubemap: blur (phi)\n14: .............. cubemap: blur (theta)\n15: .............. cubemap: clamp\n16: .............. cubemap: divide\n17: .............. write depth\n18: .............. final composite\n19: .............. tracer stateless setup\n20: .............. transparent\n21: .............. ordnance map generate\n22: .............. postprocess hologram\n23: .............. overhead map geometry\n24: .............. hologram composite\n25: .............. volume fog\n26: .............. particle update\n27: .............. particle spawn\n28: .............. screenshot combine\n29: .............. downsample 2x2\n30: .............. rotate 2d\n31: .............. bspline resample\n32: .............. bloom; downsample 4x4 (with bloom curve + DOF)\n33: .............. final composite (with DOF)\n34: .............. convolve 5-tap kernel\n35: .............. exposure downsample\n36: .............. yuv to rgb\n37: .............. displacement\n38: .............. screenshot display\n39: .............. downsample 4x4 block\n40: .............. crop\n41: .............. screenshot combine (with DOF)\n42: .............. gamma correction\n43: .............. poisson blur (alpha)\n44: .............. poisson blur (depth)\n45: .............. stencil 8x8 dither pattern\n46: .............. lens flare render\n47: .............. decorator render wind billboard\n48: .............. bloom: NEW downsample 4x4 block (with bloom curve)\n49: .............. bloom: NEW downsample 4x4 gaussian\n50: .............. apply color matrix\n51: .............. copy\n52: .............. shadow geometry\n53: .............. shadow apply\n54: .............. gradient\n55: .............. alpha test\n56: .............. patchy fog\n57: .............. light volume\n58: .............. water ripple\n59: .............. double gradient\n60: .............. sniper scope\n61: .............. shield impact\n62: .............. cheap particle spawn explicit\n63: .............. player emblem-screen\n64: .............. implicit hill\n65: .............. chud overlay blend\n66: .............. bloom add alpha1\n67: .............. lightmap debug\n68: .............. restore LDR, HDR, and depth to EDRAM\n69: .............. unused\n70: .............. decorators static billboard\n71: .............. decorators mesh\n72: .............. decorators far object\n73: .............. decorators underwater\n74: .............. final composite zoom\n75: .............. shadow apply clouds\n76: .............. shadow apply point\n77: .............. shadow apply bilinear\n78: .............. shadow apply fancy\n79: .............. shadow apply faster\n81: .............. displacement with motion blur\n82: .............. decorators volume\n83: .............. screenshot memexport\n84: .............. shadow apply variance\n85: .............. shadow generate variance\n86: .............. shadow apply blob\n87: .............. shadow apply variance no normal test\n88: .............. custom gamma correct\n89: .............. pixel copy\n90: .............. antialias blur combine\n91: .............. UNUSED\n92: .............. hud camera\n93: .............. hud camera nightvision\n94: .............. hud camera mask\n.\n.\n99-114 screen space light...\n.\n.\n116: .............. render imposter\n109: .\n110: .\n119.................shield impact procedural uv\n120.................render_rain_particles\n121.................weather wet\n122-118 rain splash...\n127.................rain sheets\n128.................screen space atmosphere fog\n129.................debug portals\n130.................shader light debug\n131.................shader light debug frustum\n132.................cui copy\n133.................cui change channel\n134.................cui linear gradient\n135.................cui directional blur\n136.................cui overlay mask\n137.................initialize cheap particles\n138.................update cheap particles\n139.................render cheap particles\n140.................spawn cheap particles\n141.................cui emblem\n142.................planar fog\n.\n.\n155.................cui debug\n156.................rigid world geometry\n157.................effects debug wireframe\n158.................effects debug heatmap\n159.................downsample 2x2 block bloom\n160.................kernel 5 sqrt\n161: ............. gaussian shadow\n162: ............. poisson shadow\n163: ............. vector hud\n176: ............. restore depth to EDRAM\n177: ............. restore color to EDRAM\n179: ............. midnight light parfait\n180: ............. particleize\n181: ............. midgraph poisson shadow 8\n182: ............. midgraph poisson shadow 6\n183: ............. gobo parfait\n184: ............. specular parfait\n185: ............. spotlight specular parfait\n186: ............. spotlight gobo specular parfait\n187: ............. gobo specular parfait\n188: ............. forge lightmap render sun structure\n189: ............. forge lightmap render sun\n190: ............. forge shadow render\n191: ............. forge lightmap render\n192: ............. forge lightmap block merge\n193: ............. forge lightmap block compress\n194: ............. forge lightmap error\n195: ............. character lighting\n196: ............. vision environment shader\n197: ............. vision object shader\n198: ............. forge lightmap postprocess\n199: ............. cui gamma correct copy\n200: ............. cui gamma correct overlay mask\n201: ............. copy surface sqrt\n202: ............. copy surface gamma 2.2\n203: ............. decorator_wind_volume\n204: ............. Midnight Point Physically Correct\n205: ............. tracer spawn\n206: ............. tracer update\n207: ............. polyart render\n208: ............. gamma correct double draw text\n209: ............. volumetric light shafts\n210: ............. Cui: Gamma correct text\n211: ............. MLAA Generate\n212: ............. FXAA\n213: ............. Hud Meter\n214: ............. Quadrant Gradient\n215: ............. Blend: Overlay\n216: ............. Filter: DropShadow\n217: ............. Filter: OuterGlow\n218: ............. Filter: InnerGlow\n219: ............. Filter: Stroke\n220: ............. Filter: EdgeDetectSetup\n221: ............. Cui: Clip corners\n222: ............. Cui: Chromatic aberration\n223: ............. Cui: Hud Meter Two Tone\n224: ............. Cui: Background blur\n225: ............. Cui: high contrast additive\n226: ............. Cui: double draw additive\n227: ............. Cui: Adjust hsv\n228: ............. Cui: Hud meter radial\n229: ............. Cui: Hud meter color blend\n230: ............. Chud: Damage generate\n231: ............. Chud: Damage apply\n232: ............. Forge: Tint highlighted\n233: ............. Forge: Tint selected\n234: ............. Forge: Tint locked\n235: ............. Cui: Shearing\n"),
		{ _field_block, "explicit shaders", &explicit_shader_refs_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_block, "unknown@", &g_null_block },
		{ _field_legacy, _field_long_integer, "unknown@" },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_legacy, _field_version_not_equal, _engine_type_haloreach },
		{ _field_tag_reference, "Active Camo Distortion Texture", &global_bitmap_reference },

		{ _field_tag_reference, "default performance throttles", &global_performance_throttles_reference },
		{ _field_tag_reference, "Logo Texture", &global_bitmap_reference },

		{ _field_legacy, _field_version_greater, _engine_type_halo3, 2 },
		{ _field_tag_reference, "Cheap Particle Type Library", &cheap_particle_type_library_reference$2 },
		{ _field_tag_reference, "Emblem Library", &global_emblem_library_parameters_reference },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_long_integer, "unknown@" },

		FIELD_EXPLANATION("Motion blur parameters", nullptr, FIELD_FLAG_NONE, "max blur:............  max amount to blur, as a percentage of the screen\nblur scale:..........  scales blur for a given velocity\ncenter falloff:....... reduces motion blur around the screen center (larger values give smaller reduction regions...)\nexpected dt:.......... expected time per tick, in seconds (used to correct motion blur in fast/slow frames)\n"),
		{ _field_real, "max blur", "max amount to blur, as a percentage of the screen", nullptr, "[0 - 0.2]", MAKE_OLD_NAMES("max blur x") },
		{ _field_real, "blur scale", "scales blur for a given velocity", nullptr, "[0 - 0.5]", MAKE_OLD_NAMES("blur scale x") },
		{ _field_real, "center falloff x", "larger values make smaller areas of no blur", nullptr, "[0 - 20]" },
		{ _field_real, "center falloff y", "larger values make smaller areas of no blur", nullptr, "[0 - 20]" },
		FIELD_EXPLANATION("screen space light parameters", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "cheap albedo blend", "for all screen space light without shader reference" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 1 },
		{ _field_legacy, _field_real, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		FIELD_EXPLANATION("Lighting layer debug mode albedo override", nullptr, FIELD_FLAG_NONE, "By default the engine uses linear 50% grey\nSet a non-black color to override this debug color\n"),
		{ _field_real_rgb_color, "lighting layer albedo color", "the floating point values are linear and what the shader will sample for albedo" },
		{ _field_tag_reference, "Hologram Camera FX", &global_camera_fx_settings_reference },
		{ _field_tag_reference, "Global load screen model", &global_loadscreen_reference },
		{ _field_real, "Global load screen gradient coordinate" },
		{ _field_tag_reference, "airprobe render model", &render_model_reference$8 },

		{ _field_terminator }
	};

	STRINGS(global_bitmap_flags)
	{
		"don\'t load bitmap by default"
	};
	STRING_LIST(global_bitmap_flags, global_bitmap_flags_strings, _countof(global_bitmap_flags_strings));

	TAG_REFERENCE(global_rasterizer_globals_reference, RASTERIZER_GLOBALS_TAG);

} // namespace macaque

} // namespace blofeld

