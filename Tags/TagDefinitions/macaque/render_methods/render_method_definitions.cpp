#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		render_method_group,
		RENDER_METHOD_TAG,
		nullptr,
		INVALID_TAG,
		render_method_block );

	TAG_GROUP(
		render_method_definition_group,
		RENDER_METHOD_DEFINITION_TAG,
		nullptr,
		INVALID_TAG,
		render_method_definition_block );

	TAG_GROUP(
		render_method_option_group,
		RENDER_METHOD_OPTION_TAG,
		nullptr,
		INVALID_TAG,
		render_method_option_block );

	TAG_GROUP(
		render_method_template_group,
		RENDER_METHOD_TEMPLATE_TAG,
		nullptr,
		INVALID_TAG,
		render_method_template_block );

	TAG_BLOCK_FROM_STRUCT(
		render_method_block,
		"render_method_block",
		1,
		render_method_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		render_method_definition_block,
		"render_method_definition_block",
		1,
		render_method_definition_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		render_method_option_block,
		"render_method_option_block",
		1,
		render_method_option_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		render_method_template_block,
		"render_method_template_block",
		1,
		render_method_template_struct_definition);

	#define SHORT_BLOCK_ID { 0x66A4C53E, 0x850348A6, 0xA9769EA5, 0xA0DFBC08 }
	TAG_BLOCK(
		short_block,
		"short_block",
		k_kilo,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SHORT_BLOCK_ID)
	{
		{ _field_short_integer, "short" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_PARAMETER_BLOCK_ID { 0x1EF54661, 0x630F4E8D, 0xAD88BD76, 0x5BBF101C }
	TAG_BLOCK(
		render_method_parameter_block,
		"render_method_parameter_block",
		c_render_method::k_maximum_parameters,
		"s_render_method_parameter",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_PARAMETER_BLOCK_ID)
	{
		{ _field_string_id, "parameter name", FIELD_FLAG_INDEX },
		{ _field_long_enum, "parameter type", &render_method_parameter_type_enum },
		{ _field_tag_reference, "bitmap", &bitmap_reference },
		{ _field_real, "real" },
		{ _field_long_integer, "int/bool" },
		{ _field_word_integer, "bitmap flags" },
		{ _field_word_integer, "bitmap filter mode" },
		{ _field_word_integer, "bitmap address mode" },
		{ _field_word_integer, "bitmap address mode x" },
		{ _field_word_integer, "bitmap address mode y" },
		{ _field_short_integer, "bitmap anisotropy amount" },
		{ _field_short_integer, "bitmap extern RTT mode" },
		{ _field_word_integer, "bitmap sharpen mode" },
		{ _field_block, "animated parameters", &render_method_animated_parameter_block },
		{ _field_terminator }
	};

	#define RENDER_METHOD_ANIMATED_PARAMETER_BLOCK_ID { 0x70665B4B, 0xBE174B76, 0x87B39EE2, 0x0B5CC3A0 }
	TAG_BLOCK(
		render_method_animated_parameter_block,
		"render_method_animated_parameter_block",
		k_kilo,
		"s_render_method_animated_parameter",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_ANIMATED_PARAMETER_BLOCK_ID)
	{
		{ _field_long_enum, "type", FIELD_FLAG_INDEX, &render_method_animated_parameter_type_enum },
		{ _field_string_id, "input name", _field_id_function_input_scalar },
		{ _field_string_id, "range name", _field_id_function_input_range },
		{ _field_real, "time period", nullptr, "seconds", _field_id_function_unknown },
		FIELD_EXPLANATION("FUNCTION", nullptr, FIELD_FLAG_NONE, ""),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "function", &mapping_function },
		{ _field_terminator }
	};

	#define RENDER_METHOD_POSTPROCESS_BLOCK_ID { 0x448CE620, 0x8C944D92, 0xBCD05705, 0x362CBBF6 }
	TAG_BLOCK(
		render_method_postprocess_block,
		"render_method_postprocess_block",
		1,
		"s_render_method_postprocess_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_POSTPROCESS_BLOCK_ID)
	{
		{ _field_tag_reference, "shader template", &render_method_template_reference },
		{ _field_block, "textures", &render_method_postprocess_texture_block },
		{ _field_block, "real vectors", &real_vector4d_block },
		{ _field_block, "int constants", &int_block },
		{ _field_long_integer, "bool constants" },
		{ _field_block, "entry points", &tag_block_index_block },
		{ _field_block, "passes", &render_method_postprocess_pass_block },
		{ _field_block, "routing info", &render_method_routing_info_block },
		{ _field_block, "overlays", &render_method_animated_parameter_block },
		{ _field_long_integer, "blend mode" },
		{ _field_long_integer, "flags" },
		{ _field_long_integer, "im_so_fired_pad", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_array, "runtime queryable properties table", &runtime_queryable_properties_array },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pageable, "unknown pageable" },

		{ _field_terminator }
	};

	#define RENDER_METHOD_POSTPROCESS_TEXTURE_BLOCK_ID { 0x9491A651, 0xAFB44C1E, 0x9822B53F, 0x607F03C2 }
	TAG_BLOCK(
		render_method_postprocess_texture_block,
		"render_method_postprocess_texture_block",
		c_render_method::k_maximum_postprocess_textures,
		"s_render_method_postprocess_texture",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_POSTPROCESS_TEXTURE_BLOCK_ID)
	{
		{ _field_tag_reference, "bitmap reference", &global_bitmap_reference },
		{ _field_short_integer, "bitmap index" },
		{ _field_byte_integer, "address mode" },
		{ _field_byte_integer, "filter mode" },
		{ _field_byte_integer, "extern texture mode" },
		{ _field_char_block_index, "texture transform constant index", &g_null_block },
		{ _field_struct, "texture transform overlay indices", &tag_block_index_struct },
		{ _field_terminator }
	};

	#define REAL_VECTOR4D_BLOCK_ID { 0xFF9E024C, 0x7D184C50, 0x90D73F8E, 0x22EF3A5D }
	TAG_BLOCK(
		real_vector4d_block,
		"real_vector4d_block",
		k_kilo,
		"real_vector4d",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		REAL_VECTOR4D_BLOCK_ID)
	{
		{ _field_real_vector_3d, "vector" },
		{ _field_real, "vector w" },
		{ _field_terminator }
	};

	#define INT_BLOCK_ID { 0x484FD1FE, 0x4FD7488B, 0xAFAAE8DB, 0x731747C0 }
	TAG_BLOCK(
		int_block,
		"int_block",
		k_kilo,
		"int",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INT_BLOCK_ID)
	{
		{ _field_long_integer, "int value" },
		{ _field_terminator }
	};

	#define TAG_BLOCK_INDEX_BLOCK_ID { 0x4CD511CB, 0xE05742A6, 0x9B31EFB8, 0x74D7BEE6 }
	TAG_BLOCK(
		tag_block_index_block,
		"tag_block_index_block",
		k_kilo,
		"s_tag_block_index",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TAG_BLOCK_INDEX_BLOCK_ID)
	{
		{ _field_struct, "block index", &tag_block_index_struct },
		{ _field_terminator }
	};

	#define RENDER_METHOD_POSTPROCESS_PASS_BLOCK_ID { 0x920AA523, 0xD662493D, 0x887E528D, 0xAFE64288 }
	TAG_BLOCK(
		render_method_postprocess_pass_block,
		"render_method_postprocess_pass_block",
		k_kilo,
		"s_render_method_postprocess_pass",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_POSTPROCESS_PASS_BLOCK_ID)
	{
		{ _field_word_integer, "bitmaps", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex real", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel real", "divide by 1024 for count, remainder is start index" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_ROUTING_INFO_BLOCK_ID { 0x3D3CBE29, 0x43EC44D6, 0x961AE5CB, 0x249A1D37 }
	TAG_BLOCK(
		render_method_routing_info_block,
		"render_method_routing_info_block",
		c_render_method_template::k_maximum_routing_info,
		"s_render_method_routing_info",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_ROUTING_INFO_BLOCK_ID)
	{
		{ _field_word_integer, "destination index", "D3D constant index or sampler index" },
		{ _field_byte_integer, "source index", "into constant tables below, unless this is an extern parameter" },
		{ _field_byte_integer, "type specific", "bitmap flags or shader component mask" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_LOCKED_PARAMETER_BLOCK_ID { 0x08F4FC57, 0xD7B146CC, 0x925B90EE, 0x3108E35E }
	TAG_BLOCK(
		render_method_locked_parameter_block,
		"render_method_locked_parameter_block",
		c_render_method_option::k_maximum_parameters,
		"s_render_method_locked_parameter",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_LOCKED_PARAMETER_BLOCK_ID)
	{
		{ _field_string_id, "parameter name" },
		{ _field_long_enum, "parameter type", &render_method_parameter_type_enum },
		{ _field_dword_integer, "animated parameter flags" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_CATEGORY_BLOCK_ID { 0xE2DDAEE5, 0x1BE349F1, 0xAB13830F, 0x6F22F795 }
	TAG_BLOCK(
		render_method_category_block,
		"render_method_category_block",
		c_render_method_definition::k_maximum_categories,
		"s_render_method_definition_category",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_CATEGORY_BLOCK_ID)
	{
		{ _field_string_id, "category name" },
		{ _field_block, "options", &render_method_options_block },
		{ _field_string_id, "vertex function" },
		{ _field_string_id, "pixel function" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_OPTIONS_BLOCK_ID { 0xDC643C49, 0x41DB4D7D, 0xBB8D4C90, 0x71AEF410 }
	TAG_BLOCK(
		render_method_options_block,
		"render_method_options_block",
		c_render_method_definition::k_maximum_category_options,
		"s_render_method_definition_category_option",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_OPTIONS_BLOCK_ID)
	{
		{ _field_string_id, "option name" },
		{ _field_tag_reference, "option", &render_method_option_reference },
		{ _field_string_id, "vertex function" },
		{ _field_string_id, "pixel function" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_ENTRY_POINTS_BLOCK_ID { 0xB66B69D3, 0x677844FA, 0xAC873549, 0xC59E32FB }
	TAG_BLOCK(
		render_method_entry_points_block,
		"render_method_entry_points_block",
		c_render_method_definition::k_maximum_entry_points,
		"s_render_method_entry_point",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_ENTRY_POINTS_BLOCK_ID)
	{
		{ _field_long_enum, "entry point", &entry_point_enum },
		{ _field_block, "passes", &render_method_pass_block },
		{ _field_terminator }
	};

	#define RENDER_METHOD_PASS_BLOCK_ID { 0xF41A0813, 0xBFB7492D, 0x8B50A95B, 0x2474B0C0 }
	TAG_BLOCK(
		render_method_pass_block,
		"render_method_pass_block",
		k_kilo,
		"s_render_method_pass",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_PASS_BLOCK_ID)
	{
		{ _field_word_flags, "flags", &render_method_pass_flags },
		FIELD_PAD("nothing", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "category dependencies&shared PS category dependencies", &render_method_pass_category_dependencies_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "shared VS category dependencies", &render_method_pass_category_dependencies_block },

		{ _field_terminator }
	};

	#define RENDER_METHOD_PASS_CATEGORY_DEPENDENCIES_ID { 0xC2CF2C86, 0x74B042BC, 0xB50C5874, 0xEC6E468D }
	TAG_BLOCK(
		render_method_pass_category_dependencies_block,
		"render_method_pass_category_dependencies",
		1,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_PASS_CATEGORY_DEPENDENCIES_ID)
	{
		{ _field_short_block_index, "category", &render_method_category_block },
		{ _field_terminator }
	};

	#define VERTEX_TYPES_BLOCK_ID { 0x10D75123, 0xB1E940D6, 0x93113433, 0x80D97C43 }
	TAG_BLOCK(
		vertex_types_block,
		"vertex_types_block",
		k_number_of_vertex_types,
		"s_render_method_vertex_types",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		VERTEX_TYPES_BLOCK_ID)
	{
		{ _field_enum, "vertex type", &vertex_types_names_enum },
		FIELD_PAD("blahasdf", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define RENDER_METHOD_OPTION_PARAMETER_BLOCK_ID { 0x11BB68C2, 0x756A4F92, 0xBC2DAAF6, 0xEF1AB32E }
	TAG_BLOCK(
		render_method_option_parameter_block,
		"render_method_option_parameter_block",
		c_render_method_option::k_maximum_parameters,
		"s_render_method_option_parameter",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_OPTION_PARAMETER_BLOCK_ID)
	{
		{ _field_string_id, "parameter name" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "parameter ui override name" },

		{ _field_long_enum, "parameter type", &render_method_parameter_type_enum },
		{ _field_long_enum, "source extern", &render_method_extern_enum },
		{ _field_tag_reference, "default bitmap", &global_bitmap_reference },
		{ _field_real, "default real value" },
		{ _field_long_integer, "default int/bool value" },
		{ _field_word_integer, "flags" },
		{ _field_enum, "default filter mode", &render_method_bitmap_filter_mode_enum },
		{ _field_enum, "default address mode", &render_method_bitmap_address_mode_enum },
		{ _field_word_integer, "anisotropy amount" },
		{ _field_argb_color, "default color" },
		{ _field_real, "default bitmap scale" },
		{ _field_long_flags, "usage flags", &ui_and_usage_flags },
		{ _field_enum, "force function type", &function_type_enum_definition },
		{ _field_enum, "force function color count", &color_graph_type_enum_definition },
		{ _field_real, "suggested real min" },
		{ _field_real, "suggested real max" },
		{ _field_long_integer, "ticks from min to max" },

		{ _field_legacy, _field_version_equal, _engine_type_halo3odst, 4 },
		{ _field_legacy, _field_long_integer, "@unknown" },
		{ _field_legacy, _field_long_integer, "@unknown" },
		{ _field_legacy, _field_long_integer, "@unknown" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_data, "help text" },

		{ _field_terminator }
	};

	#define RENDER_METHOD_TEMPLATE_PASS_BLOCK_ID { 0x10A89CAE, 0x02C24E53, 0xB26A4E02, 0x2A6E6525 }
	TAG_BLOCK(
		render_method_template_pass_block,
		"render_method_template_pass_block",
		c_render_method_template::k_maximum_passes,
		"s_render_method_template_pass",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_TEMPLATE_PASS_BLOCK_ID)
	{
		{ _field_word_integer, "bitmaps", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex real constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex int constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "vertex bool constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel real constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel int constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "pixel bool constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern bitmaps", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern vertex real constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern vertex int constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern pixel real constants", "divide by 1024 for count, remainder is start index" },
		{ _field_word_integer, "extern pixel int constants", "divide by 1024 for count, remainder is start index" },
		{ _field_long_integer, "alpha blend mode" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown@" },

		{ _field_terminator }
	};

	#define RENDER_METHOD_TEMPLATE_CONSTANT_TABLE_BLOCK_ID { 0x17C33ABC, 0xC3DE46B7, 0xB84ECBCA, 0x13595216 }
	TAG_BLOCK(
		render_method_template_constant_table_block,
		"render_method_template_constant_table_block",
		254,
		"c_render_method_template::s_constant_table_entry",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_TEMPLATE_CONSTANT_TABLE_BLOCK_ID)
	{
		{ _field_string_id, "parameter name" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_TEMPLATE_PLATFORM_BLOCK_ID { 0x1926C436, 0x483246AA, 0x86067626, 0x533DDEA8 }
	TAG_BLOCK(
		render_method_template_platform_block,
		"render_method_template_platform_block",
		1,
		"c_render_method_template::s_platform_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_TEMPLATE_PLATFORM_BLOCK_ID)
	{
		{ _field_tag_reference, "vertex shader", &vertex_shader_reference },
		{ _field_tag_reference, "pixel shader", &pixel_shader_reference },
		{ _field_dword_integer, "available entry_points", FIELD_FLAG_READ_ONLY },
		{ _field_block, "entry points", &tag_block_index_block },
		{ _field_block, "passes", &render_method_template_pass_block },
		{ _field_block, "routing info", &render_method_routing_info_block },
		{ _field_block, "float constants", &render_method_template_constant_table_block },
		{ _field_block, "int constants", &render_method_template_constant_table_block },
		{ _field_block, "bool constants", &render_method_template_constant_table_block },
		{ _field_block, "textures", &render_method_template_constant_table_block },
		{ _field_terminator }
	};

	#define RUNTIME_QUERYABLE_PROPERTIES_ID { 0x0C5470BA, 0x5AEE4BEC, 0xBEC72F30, 0x08902CAC }
	TAG_ARRAY(
		runtime_queryable_properties_array,
		"runtime_queryable_properties",
		s_render_method_postprocess_definition::k_runtime_queryable_properties_count,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RUNTIME_QUERYABLE_PROPERTIES_ID)
	{
		{ _field_short_block_index, "index", &g_null_block },
		{ _field_terminator }
	};

	#define RENDER_METHOD_STRUCT_DEFINITION_ID { 0xE5438218, 0x3A6340DC, 0x9DAFA818, 0x761ADDF3 }
	TAG_STRUCT(
		render_method_struct_definition,
		"render_method_struct_definition",
		"c_render_method",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_tag_reference, "definition", FIELD_FLAG_READ_ONLY, &render_method_definition_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_tag_reference, "reference", &render_method_reference },
		
		{ _field_block, "options", &short_block },
		{ _field_block, "parameters", &render_method_parameter_block },
		{ _field_block, "postprocess", &render_method_postprocess_block },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_long_integer, "is template" },
		{ _field_long_flags, "locked options", &global_render_method_lock_option_flags_defintion },
		{ _field_block, "locked parameters", &render_method_locked_parameter_block },
		
		{ _field_word_flags, "shader flags", FIELD_FLAG_READ_ONLY, &global_render_method_flags_defintion },
		{ _field_char_enum, "sort layer", FIELD_FLAG_READ_ONLY, &global_sort_layer_enum_defintion },
		{ _field_char_integer, "version", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "Custom fog setting index" },
		{ _field_long_block_index, "prediction atom index", FIELD_FLAG_UNKNOWN0, &g_null_block },
		{ _field_terminator }
	};

	#define RENDER_METHOD_DEFINITION_STRUCT_DEFINITION_ID { 0x45573089, 0x681B4D5B, 0xB00F0E44, 0xDE8E72DC }
	TAG_STRUCT(
		render_method_definition_struct_definition,
		"render_method_definition_struct_definition",
		"c_render_method_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_DEFINITION_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "global options", &render_method_option_reference },
		{ _field_block, "categories", &render_method_category_block },
		{ _field_block, "entry_points", &render_method_entry_points_block },
		{ _field_block, "vertex_types", &vertex_types_block },
		{ _field_tag_reference, "shared pixel shaders", FIELD_FLAG_READ_ONLY, &global_pixel_shader_reference },
		{ _field_tag_reference, "shared vertex shaders", FIELD_FLAG_READ_ONLY, &global_vertex_shader_reference },
		{ _field_long_flags, "flags", &render_method_definition_flags },
		{ _field_dword_integer, "version", nullptr, "bump to force recompile" },
		FIELD_EXPLANATION("source file location", nullptr, FIELD_FLAG_NONE, "like templated\\shader ..."),
		{ _field_long_string, "location" },
		{ _field_terminator }
	};

	#define RENDER_METHOD_OPTION_STRUCT_DEFINITION_ID { 0x64873A7E, 0x31464CE2, 0xBB5A3107, 0xBCDDB84C }
	TAG_STRUCT(
		render_method_option_struct_definition,
		"render_method_option_struct_definition",
		"c_render_method_option",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_OPTION_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "parameters", &render_method_option_parameter_block },
		{ _field_terminator }
	};

	#define RENDER_METHOD_TEMPLATE_STRUCT_DEFINITION_ID { 0xE29233A9, 0xAE7B4321, 0x93DFA5CE, 0x4E5BD1D5 }
	TAG_STRUCT(
		render_method_template_struct_definition,
		"render_method_template_struct_definition",
		"c_render_method_template",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_METHOD_TEMPLATE_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "vertex shader", &vertex_shader_reference },
		{ _field_tag_reference, "pixel shader", &pixel_shader_reference },
		{ _field_dword_integer, "available entry points", FIELD_FLAG_READ_ONLY },
		{ _field_block, "entry points", &tag_block_index_block },
		{ _field_block, "passes", &render_method_template_pass_block },
		{ _field_block, "routing info", &render_method_routing_info_block },
		{ _field_block, "float constants", &render_method_template_constant_table_block },
		{ _field_block, "int constants", &render_method_template_constant_table_block },
		{ _field_block, "bool constants", &render_method_template_constant_table_block },
		{ _field_block, "textures", &render_method_template_constant_table_block },
		{ _field_block, "other platforms", &render_method_template_platform_block },
		{ _field_terminator }
	};

	#define TAG_BLOCK_INDEX_STRUCT_ID { 0xA7D748C4, 0x6A624229, 0xB70B7DC6, 0x27861D70 }
	TAG_STRUCT(
		tag_block_index_struct,
		"tag_block_index_struct",
		"s_tag_block_index",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TAG_BLOCK_INDEX_STRUCT_ID)
	{
		{ _field_word_integer, "block index data", "divide by 1024 for count, remainder is start index" },
		{ _field_terminator }
	};

	STRINGS(render_method_parameter_type_enum)
	{
		"bitmap",
		"color",
		"real",
		"int",
		"bool",
		"argb color"
	};
	STRING_LIST(render_method_parameter_type_enum, render_method_parameter_type_enum_strings, _countof(render_method_parameter_type_enum_strings));

	STRINGS(render_method_bitmap_filter_mode_enum)
	{
		"trilinear",
		"point",
		"bilinear",
		"UNUSED 0",
		"anisotropic (2) expensive",
		"UNUSED 1",
		"anisotropic (4) EXPENSIVE",
		"lightprobe texture array",
		"texture array quadlinear",
		"texture array quadanisotropic (2)"
	};
	STRING_LIST(render_method_bitmap_filter_mode_enum, render_method_bitmap_filter_mode_enum_strings, _countof(render_method_bitmap_filter_mode_enum_strings));

	STRINGS(render_method_bitmap_address_mode_enum)
	{
		"wrap",
		"clamp",
		"mirror",
		"black border",
		"mirroronce",
		"mirroronce border"
	};
	STRING_LIST(render_method_bitmap_address_mode_enum, render_method_bitmap_address_mode_enum_strings, _countof(render_method_bitmap_address_mode_enum_strings));

	STRINGS(render_method_animated_parameter_type_enum)
	{
		"value",
		"color",
		"scale uniform",
		"scale x",
		"scale y",
		"translation x",
		"translation y",
		"frame index",
		"alpha"
	};
	STRING_LIST(render_method_animated_parameter_type_enum, render_method_animated_parameter_type_enum_strings, _countof(render_method_animated_parameter_type_enum_strings));

	STRINGS(render_method_extern_enum)
	{
		"none",
		"texaccum target",
		"normal target",
		"z target",
		"shadow mask",
		"shadow 1 target",
		"shadow 2 target",
		"shadow 3 target",
		"shadow 4 target",
		"texture camera target",
		"reflection target",
		"refraction target",
		"dualvmf direction ps",
		"dualvmf intensity ps",
		"dualvmf direction vs",
		"dualvmf intensity vs",
		"gel texture of analytical light",
		"unused 1",
		"unused 2",
		"change color primary",
		"change color secondary",
		"change color tertiary",
		"change color quaternary",
		"emblem color background",
		"emblem color primary",
		"emblem color secondary",
		"dynamic environment map 1",
		"dynamic environment map 2",
		"cook torrance array",
		"vmf diffuse table",
		"vmf diffuse table vs",
		"direction lut",
		"zonal rotation table",
		"phong specular table",
		"diffuse power specular table",
		"light dir 0",
		"light color 0",
		"light dir 1",
		"light color 1",
		"light dir 2",
		"light color 2",
		"light dir 3",
		"light color 3",
		"unused 3",
		"unused 4",
		"unused 5",
		"dynamic light gel 0",
		"flat envmap matrix x",
		"flat envmap matrix y",
		"flat envmap matrix z",
		"debug tint",
		"screen constants",
		"active camo distortion texture",
		"scene ldr texture",
		"water memexport addr",
		"tree animation timer",
		"depth constants",
		"camera forward",
		"wrinkle weights a",
		"wrinkle weights b",
		"static lighting previs"
	};
	STRING_LIST(render_method_extern_enum, render_method_extern_enum_strings, _countof(render_method_extern_enum_strings));

	STRINGS(render_method_definition_flags)
	{
		"use automatic macros",
		"build constant table in shader"
	};
	STRING_LIST(render_method_definition_flags, render_method_definition_flags_strings, _countof(render_method_definition_flags_strings));

	STRINGS(entry_point_enum)
	{
		"default",
		"albedo",
		"static_per_pixel",
		"static_per_pixel_hybrid_refinement",
		"static_per_pixel_analytic",
		"static_per_pixel_analytic_hybrid_refinement",
		"static_per_pixel_floating_shadow",
		"static_per_vertex",
		"static_probe",
		"static_per_pixel_forge",
		"static_per_pixel_object",
		"static_per_vertex_object",
		"dynamic_light",
		"shadow_generate",
		"shadow_apply",
		"active_camo",
		"lightmap_debug_mode",
		"vertex_color_lighting",
		"water_tessellation",
		"water_shading",
		"unused2",
		"single_pass_per_pixel",
		"single_pass_per_vertex",
		"single_pass_single_probe",
		"single_pass_as_decal",
		"midnight_spotlight",
		"midnight_spotlight_transparents",
		"motion_blur",
		"volume_fog_stencil",
		"volume_fog_depth",
		"curved_cui",
		"single_pass_shadowed_no_fog_per_pixel",
		"single_pass_shadowed_no_fog_per_vertex",
		"single_pass_shadowed_no_fog_single_probe",
		"static_per_pixel_floating_shadow_simple",
		"static_per_pixel_simple",
		"static_per_pixel_ao",
		"static_per_vertex_ao",
		"static_lit_cui",
		"curved_static_lit_cui"
	};
	STRING_LIST(entry_point_enum, entry_point_enum_strings, _countof(entry_point_enum_strings));

	STRINGS(render_method_pass_flags)
	{
		"shared entry point compilation&shared pixel shader compilation",
		"shared VS only care non-default option of depended category",
		"only be compiled to xenon platform",
		"allow failed shader compile"
	};
	STRING_LIST(render_method_pass_flags, render_method_pass_flags_strings, _countof(render_method_pass_flags_strings));

	STRINGS(vertex_types_names_enum)
	{
		"world",
		"rigid",
		"skinned",
		"particle_model",
		"flat_world",
		"flat_rigid",
		"flat_skinned",
		"screen",
		"debug",
		"transparent",
		"particle",
		"rigid2uv",
		"light_volume",
		"chud_simple",
		"chud_fancy",
		"decorator",
		"tiny position",
		"patchy fog",
		"water",
		"ripple",
		"implicit geometry",
		"skinned2uv",
		"world_tessellated",
		"rigid_tessellated",
		"skinned_tessellated",
		"shader_cache",
		"structure_instance_imposter",
		"object_imposter",
		"rigid compressed",
		"skinned uncompressed",
		"light_volume_precompiled",
		"blendshape_rigid",
		"blendshape_rigid_blendshaped",
		"rigid_blendshaped",
		"blendshape_skinned",
		"blendshape_skinned_blendshaped",
		"skinned_blendshaped",
		"VirtualGeometryHWtess",
		"VirtualGeometryMemexport",
		"position_only",
		"VirtualGeometryDebug",
		"BlendshapeRigidCompressedPosition",
		"SkinnedUncompressedPositionBlendshaped",
		"BlendshapeSkinnedUncompressedPosition",
		"tracer",
		"polyart",
		"vectorart",
		"rigid_boned",
		"rigid_boned_2uv",
		"blendshape_skinned_2uv",
		"blendshape_skinned_2uv_blendshaped",
		"skinned_2uv_blendshaped",
		"polyartUV",
		"BlendshapeSkinnedUncompressedPositionBlendshaped"
	};
	STRING_LIST(vertex_types_names_enum, vertex_types_names_enum_strings, _countof(vertex_types_names_enum_strings));

	STRINGS(ui_and_usage_flags)
	{
		"use force function type",
		"use force function color count",
		"parameter invisible in ui",
		"lock function value"
	};
	STRING_LIST(ui_and_usage_flags, ui_and_usage_flags_strings, _countof(ui_and_usage_flags_strings));

	STRINGS(global_render_method_lock_option_flags_defintion)
	{
		"option 0",
		"option 1",
		"option 2",
		"option 3",
		"option 4",
		"option 5",
		"option 6",
		"option 7",
		"option 8",
		"option 9",
		"option 10",
		"option 11",
		"option 12",
		"option 13",
		"option 14",
		"option 15",
		"option 16",
		"option 17",
		"option 18",
		"option 19",
		"option 20",
		"option 21",
		"option 22",
		"option 23",
		"option 24",
		"option 25",
		"option 26",
		"option 27",
		"option 28",
		"option 29",
		"option 30",
		"option 31"
	};
	STRING_LIST(global_render_method_lock_option_flags_defintion, global_render_method_lock_option_flags_defintion_strings, _countof(global_render_method_lock_option_flags_defintion_strings));

	STRINGS(global_render_method_flags_defintion)
	{
		"don\'t fog me",
		"use custom setting",
		"calculate Z camera",
		"never render for shields",
		"only render for shields"
	};
	STRING_LIST(global_render_method_flags_defintion, global_render_method_flags_defintion_strings, _countof(global_render_method_flags_defintion_strings));

	STRINGS(global_sort_layer_enum_defintion)
	{
		"invalid",
		"pre-pass",
		"normal",
		"post-pass"
	};
	STRING_LIST(global_sort_layer_enum_defintion, global_sort_layer_enum_defintion_strings, _countof(global_sort_layer_enum_defintion_strings));

} // namespace macaque

} // namespace blofeld

