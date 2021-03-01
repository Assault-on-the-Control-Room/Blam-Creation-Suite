#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cui_logic_group,
		CUI_LOGIC_TAG,
		nullptr,
		INVALID_TAG,
		cui_logic_block );

	TAG_GROUP(
		cui_screen_group,
		CUI_SCREEN_TAG,
		nullptr,
		INVALID_TAG,
		cui_screen_block );

	TAG_GROUP(
		cui_static_data_group,
		CUI_STATIC_DATA_TAG,
		nullptr,
		INVALID_TAG,
		cui_static_data_block );

	TAG_BLOCK_FROM_STRUCT(
		cui_logic_block,
		"cui_logic_block",
		1,
		cui_logic_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		cui_screen_block,
		"cui_screen_block",
		1,
		cui_screen_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		cui_static_data_block,
		"cui_static_data_block",
		1,
		cui_static_data_struct_definition);

	#define TEMPLATE_INSTANTIATION_BLOCK_DEFINITION_ID { 0x147959FC, 0xBEE943BB, 0xBBE561E4, 0x8E81088F }
	TAG_BLOCK(
		template_instantiation_block_definition_block,
		"template_instantiation_block_definition",
		k_cui_max_component_count,
		"s_cui_template_instantiation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TEMPLATE_INSTANTIATION_BLOCK_DEFINITION_ID)
	{
		{ _field_tag_reference, "screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_terminator }
	};

	#define COMPONENT_DEFINITION_ID { 0xBD11BC6F, 0x13294A69, 0xA305D2C5, 0x095132FA }
	TAG_BLOCK(
		component_definition_block,
		"component_definition",
		k_cui_max_component_count,
		"s_cui_component_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMPONENT_DEFINITION_ID)
	{
		{ _field_string_id, "type" },
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "parent" },
		{ _field_word_flags, "flags", &component_definition_flags },
		{ _field_short_block_index, "template instantiation index", &template_instantiation_block_definition_block },
		{ _field_terminator }
	};

	#define COMPONENT_INDEX_BLOCK_DEFINITION_ID { 0xA6D04B81, 0x50744188, 0x85E92731, 0xCD29119E }
	TAG_BLOCK(
		component_index_block_definition_block,
		"component_index_block_definition",
		k_cui_max_component_count,
		"s_cui_component_index_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		COMPONENT_INDEX_BLOCK_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "component definition index", &component_definition_block },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define OVERLAY_DEFINITION_ID { 0x8836D58B, 0x4A6A6F0A, 0x66733DA3, 0x9BCB5AF9 }
	TAG_BLOCK(
		overlay_definition_block,
		"overlay_definition",
		k_cui_max_overlay_count,
		"s_cui_overlay_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		OVERLAY_DEFINITION_ID)
	{
		{ _field_string_id, "resolution" },
		{ _field_string_id, "theme" },
		{ _field_block, "components", &component_properties_definition_block },
		{ _field_block, "animations", &animation_definition_block },
		{ _field_terminator }
	};

	#define COMPONENT_PROPERTIES_DEFINITION_ID { 0x8420F7CF, 0x438C8C23, 0xFAC7919C, 0xF4E1FEF7 }
	TAG_BLOCK(
		component_properties_definition_block,
		"component_properties_definition",
		k_cui_max_component_count,
		"s_cui_component_properties_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMPONENT_PROPERTIES_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_struct, "property values", &properties_struct },
		{ _field_terminator }
	};

	#define PROPERTY_LONG_VALUE_ID { 0x63DD2829, 0xD1F14D14, 0x96387952, 0x8FCC1FFC }
	TAG_BLOCK(
		property_long_value_block,
		"property_long_value",
		8*k_kilo,
		"s_cui_property_value_long_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_LONG_VALUE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_integer, "value" },
		{ _field_terminator }
	};

	#define PROPERTY_REAL_VALUE_ID { 0x758DA8A4, 0x59124090, 0xA1FB5462, 0xD2453C69 }
	TAG_BLOCK(
		property_real_value_block,
		"property_real_value",
		8*k_kilo,
		"s_cui_property_value_real_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_REAL_VALUE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real, "value" },
		{ _field_terminator }
	};

	#define PROPERTY_STRING_ID_VALUE_ID { 0x63CAF970, 0x0FAF4EA9, 0xB3FEB12C, 0xA47C0015 }
	TAG_BLOCK(
		property_string_id_value_block,
		"property_string_id_value",
		8*k_kilo,
		"s_cui_property_value_string_id_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_STRING_ID_VALUE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "value" },
		{ _field_terminator }
	};

	#define PROPERTYCOMPONENTPTRVALUE_ID { 0xB824C8C9, 0x9FE444AF, 0xA4AA330E, 0x970B0EB6 }
	TAG_BLOCK(
		propertyComponentPtrValue_block,
		"propertyComponentPtrValue",
		8*k_kilo,
		"CuiPropertyValueComponentPtrDefinition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTYCOMPONENTPTRVALUE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "value" },
		{ _field_byte_flags, "flags", &propertyComponentPtrFlags },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define PROPERTY_TAG_REFERENCE_VALUE_ID { 0xCAA80A14, 0x9B1245B5, 0xA53A40F5, 0xFFA44C2E }
	TAG_BLOCK(
		property_tag_reference_value_block,
		"property_tag_reference_value",
		8*k_kilo,
		"s_cui_property_value_tag_reference_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_TAG_REFERENCE_VALUE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_tag_reference, "value", &property_tag_reference_value_value_reference },
		{ _field_terminator }
	};

	#define PROPERTY_TEXT_VALUE_ID { 0x9B80DCD3, 0xD0F84F46, 0xAF7A6043, 0x97549DDA }
	TAG_BLOCK(
		property_text_value_block,
		"property_text_value",
		8*k_kilo,
		"s_cui_property_value_text_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_TEXT_VALUE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_string, "value" },
		{ _field_terminator }
	};

	#define PROPERTY_ARGB_COLOR_VALUE_ID { 0xA86FC89B, 0x478A4BAC, 0x97ED6B44, 0xC3099AB8 }
	TAG_BLOCK(
		property_argb_color_value_block,
		"property_argb_color_value",
		8*k_kilo,
		"s_cui_property_value_argb_color_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_ARGB_COLOR_VALUE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_real_argb_color, "value" },
		{ _field_terminator }
	};

	#define ANIMATION_DEFINITION_ID { 0x28C2D946, 0x48183940, 0x28327897, 0x19C0A450 }
	TAG_BLOCK(
		animation_definition_block,
		"animation_definition",
		k_cui_max_animation_count,
		"s_cui_animation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_real, "time base offset" },
		{ _field_real, "time exponential offset" },
		{ _field_char_enum, "animation input", &animationInputType },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_block, "components", &animation_component_definition_block },
		{ _field_terminator }
	};

	#define ANIMATION_COMPONENT_DEFINITION_ID { 0x37944A2F, 0x45B1B916, 0x3E72528B, 0xBE822639 }
	TAG_BLOCK(
		animation_component_definition_block,
		"animation_component_definition",
		k_cui_max_component_count,
		"s_cui_animation_component_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_COMPONENT_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_integer, "total milliseconds" },
		{ _field_block, "real properties", &animation_component_real_property_block },
		{ _field_block, "argb color properties", &animation_component_argb_color_property_block },
		{ _field_terminator }
	};

	#define ANIMATION_COMPONENT_REAL_PROPERTY_ID { 0xAD69E811, 0x433F6A19, 0x387DC3A8, 0x5FDA1B89 }
	TAG_BLOCK(
		animation_component_real_property_block,
		"animation_component_real_property",
		8*k_kilo,
		"s_cui_animation_component_property_real_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_COMPONENT_REAL_PROPERTY_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_enum, "composition", &animation_property_composition_type },
		{ _field_byte_flags, "flags", &animation_property_flags },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_long_integer, "total milliseconds" },
		{ _field_block, "real keyframes", &animation_property_keyframe_real_value_block },
		{ _field_terminator }
	};

	#define ANIMATION_PROPERTY_KEYFRAME_REAL_VALUE_ID { 0xB0607499, 0x47B406C2, 0xB23AF68C, 0x3D147AFE }
	TAG_BLOCK(
		animation_property_keyframe_real_value_block,
		"animation_property_keyframe_real_value",
		8*k_kilo,
		"s_cui_animation_property_keyframe_value_real_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_PROPERTY_KEYFRAME_REAL_VALUE_ID)
	{
		{ _field_long_integer, "duration", "the amount of time from the previous keyframe to this keyframe", "milliseconds" },
		{ _field_real, "value", "the value when the current time is on this keyframe" },
		{ _field_struct, "transition function", &animation_scalar_function },
		{ _field_terminator }
	};

	#define ANIMATION_COMPONENT_ARGB_COLOR_PROPERTY_ID { 0xF78AE30C, 0x400115B4, 0x80F685AF, 0xE11A81EC }
	TAG_BLOCK(
		animation_component_argb_color_property_block,
		"animation_component_argb_color_property",
		8*k_kilo,
		"s_cui_animation_component_property_argb_color_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_COMPONENT_ARGB_COLOR_PROPERTY_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_enum, "composition", &animation_property_composition_type },
		{ _field_byte_flags, "flags", &animation_property_flags },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_long_integer, "total milliseconds" },
		{ _field_block, "argb color keyframes", &animation_property_keyframe_argb_color_value_block },
		{ _field_terminator }
	};

	#define ANIMATION_PROPERTY_KEYFRAME_ARGB_COLOR_VALUE_ID { 0xF1EB2044, 0x455A54EA, 0x853771B2, 0x0ECC1161 }
	TAG_BLOCK(
		animation_property_keyframe_argb_color_value_block,
		"animation_property_keyframe_argb_color_value",
		8*k_kilo,
		"s_cui_animation_property_keyframe_value_argb_color_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_PROPERTY_KEYFRAME_ARGB_COLOR_VALUE_ID)
	{
		{ _field_long_integer, "duration", "the amount of time from the previous keyframe to this keyframe", "milliseconds" },
		{ _field_real_argb_color, "color", "the value when the current time is on this keyframe" },
		{ _field_struct, "transition function", &animation_scalar_function },
		{ _field_terminator }
	};

	#define OVERLAY_EDITOR_ONLY_DEFINITION_ID { 0xE972B73F, 0x46783E11, 0x5D16EAAB, 0xC2D1B897 }
	TAG_BLOCK(
		overlay_editor_only_definition_block,
		"overlay_editor_only_definition",
		k_cui_max_overlay_count,
		"s_cui_overlay_editor_only_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		OVERLAY_EDITOR_ONLY_DEFINITION_ID)
	{
		{ _field_string_id, "resolution" },
		{ _field_string_id, "theme" },
		{ _field_byte_flags, "flags", &editor_overlay_info_flags },
		{ _field_block, "components editor only", &component_editor_only_definition_block },
		{ _field_block, "animations editor only", &animation_editor_only_definition_block },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define COMPONENT_EDITOR_ONLY_DEFINITION_ID { 0x6F53BEF3, 0x4AB6A37E, 0xF0C815BF, 0x45DEED38 }
	TAG_BLOCK(
		component_editor_only_definition_block,
		"component_editor_only_definition",
		k_cui_max_component_count,
		"s_cui_component_editor_only_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		COMPONENT_EDITOR_ONLY_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "properties editor only", &property_editor_only_definition_block },
		{ _field_terminator }
	};

	#define PROPERTY_EDITOR_ONLY_DEFINITION_ID { 0x4F28B89C, 0x45CE002A, 0xE2FCC3A9, 0xC080DDDE }
	TAG_BLOCK(
		property_editor_only_definition_block,
		"property_editor_only_definition",
		k_cui_max_property_count,
		"s_cui_property_editor_only_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_EDITOR_ONLY_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &editor_property_info_flags },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_terminator }
	};

	#define ANIMATION_EDITOR_ONLY_DEFINITION_ID { 0xC40BEC36, 0x4C9065D3, 0x6192C5BE, 0x9CAE89F6 }
	TAG_BLOCK(
		animation_editor_only_definition_block,
		"animation_editor_only_definition",
		k_cui_max_animation_count,
		"s_cui_animation_editor_only_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_EDITOR_ONLY_DEFINITION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_block, "components editor only", &component_editor_only_definition_block },
		{ _field_terminator }
	};

	#define PROPERTY_BINDING_ID { 0x4888CD37, 0xF2EF410F, 0xB0BBC0C9, 0xD9F1582E }
	TAG_BLOCK(
		property_binding_block,
		"property_binding",
		k_cui_max_property_binding_count,
		"s_cui_property_binding_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTY_BINDING_ID)
	{
		{ _field_word_flags, "flags", &property_binding_flags },
		{ _field_enum, "conversion function", &binding_conversion_function_enum_definition },
		{ _field_string_id, "source component name" },
		{ _field_string_id, "source property name" },
		{ _field_string_id, "target component name" },
		{ _field_string_id, "target property name" },
		{ _field_terminator }
	};

	#define BINDING_CONVERSION_LONG_COMPARISON_BLOCK_DEFINITION_ID { 0x6D6E5043, 0x13D046D7, 0xB40DF853, 0xD5C4E390 }
	TAG_BLOCK(
		binding_conversion_long_comparison_block_definition_block,
		"binding_conversion_long_comparison_block_definition",
		k_cui_max_property_binding_count,
		"s_cui_binding_conversion_long_comparison_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BINDING_CONVERSION_LONG_COMPARISON_BLOCK_DEFINITION_ID)
	{
		{ _field_string_id, "target component name" },
		{ _field_string_id, "target property name" },
		{ _field_char_enum, "comparison operator", &binding_conversion_comparison_operator_enum_definition },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_long_integer, "comparison value" },
		{ _field_terminator }
	};

	#define STATIC_DATA_TABLE_ID { 0x5F2AD34A, 0x125E4C65, 0x9E9134E6, 0xD3E61871 }
	TAG_BLOCK(
		static_data_table_block,
		"static_data_table",
		128,
		"s_cui_static_data_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STATIC_DATA_TABLE_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_string_id, "mock data for component", "a component on this screen that gets replaced in simulation with this data table" },
		{ _field_struct, "static data", &static_data_struct },
		{ _field_terminator }
	};

	#define STATIC_DATA_COLUMN_ID { 0x1FC0B041, 0xCFB94409, 0xBEB29306, 0x05894CD1 }
	TAG_BLOCK(
		static_data_column_block,
		"static_data_column",
		128,
		"s_cui_static_data_column_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STATIC_DATA_COLUMN_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_enum, "type", &property_type },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		static_data_row_block,
		"static_data_row",
		256,
		properties_struct);

	#define EXPRESSION_ID { 0xF090B187, 0x9D744CDD, 0x8C3A7A52, 0x1D6BE899 }
	TAG_BLOCK(
		expression_block,
		"expression",
		128,
		"s_cui_expression_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EXPRESSION_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_long_string, "expression text" },
		{ _field_block, "steps", &expression_step_block },
		{ _field_terminator }
	};

	#define EXPRESSION_STEP_ID { 0xCC3B2DB9, 0x9A254A83, 0x8CA2994F, 0xF92E432B }
	TAG_BLOCK(
		expression_step_block,
		"expression_step",
		s_cui_expression_step_definition::k_maximum_step_count,
		"s_cui_expression_step_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EXPRESSION_STEP_ID)
	{
		{ _field_char_enum, "step type", FIELD_FLAG_INDEX, &step_type },
		{ _field_char_enum, "operator", &step_operator },
		{ _field_char_enum, "variable", &step_variable },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_real, "value&real value" },
		{ _field_string_id, "string id value" },
		{ _field_terminator }
	};

	#define ENCAPSULATEDPROPERTIES_ID { 0x926E4316, 0xCAA24436, 0xA4CB6C9D, 0x7E9FEB81 }
	TAG_BLOCK(
		encapsulatedProperties_block,
		"encapsulatedProperties",
		k_cuiMaxEncapsulationCount,
		"CuiEncapsulatedProperties",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ENCAPSULATEDPROPERTIES_ID)
	{
		{ _field_string_id, "encapsulation name", FIELD_FLAG_INDEX },
		{ _field_block, "properties", &static_data_column_block },
		{ _field_terminator }
	};

	#define STRING_FILE_REFERENCES_ID { 0xF35BA8A6, 0x4CA54CEC, 0x94707022, 0x2117E522 }
	TAG_BLOCK(
		string_file_references_block,
		"string_file_references",
		16,
		"s_tag_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRING_FILE_REFERENCES_ID)
	{
		{ _field_tag_reference, "string list", &global_multilingual_unicode_string_list_reference },
		{ _field_terminator }
	};

	#define CUI_LOGIC_STRUCT_DEFINITION_ID { 0xAAD80006, 0x56CB4A4F, 0x9D7EF532, 0xAEC09825 }
	TAG_STRUCT(
		cui_logic_struct_definition,
		"cui_logic_struct_definition",
		"CuiLogicDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_LOGIC_STRUCT_DEFINITION_ID)
	{
		{ _field_string_id, "logic name" },
		{ _field_tag_reference, "string list", &global_multilingual_unicode_string_list_reference },
		{ _field_struct, "system", &cui_system },
		{ _field_terminator }
	};

	#define CUI_SCREEN_STRUCT_DEFINITION_ID { 0x7139CC11, 0x87E842E4, 0x94C5ED2B, 0x2A19EAA8 }
	TAG_STRUCT(
		cui_screen_struct_definition,
		"cui_screen_struct_definition",
		"CuiScreenDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_SCREEN_STRUCT_DEFINITION_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_tag_reference, "string list", &global_multilingual_unicode_string_list_reference },
		{ _field_struct, "system", &cui_system },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "string references", &string_file_references_block },
		{ _field_tag_reference, "logic", &cui_logic_reference },
		{ _field_struct, "system", &cui_system },

		{ _field_terminator }
	};

	#define CUI_STATIC_DATA_STRUCT_DEFINITION_ID { 0xA9592261, 0x3F3E4E98, 0xB9AA7A18, 0x4F381A53 }
	TAG_STRUCT(
		cui_static_data_struct_definition,
		"cui_static_data_struct_definition",
		"s_cui_static_data_group_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_STATIC_DATA_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "static data", &static_data_struct },
		{ _field_terminator }
	};

	#define CUI_SYSTEM_ID { 0x923E721C, 0xFE154F87, 0x8C081FF3, 0x2CE0E8E5 }
	TAG_STRUCT(
		cui_system,
		"cui_system",
		"CuiSystemDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		CUI_SYSTEM_ID)
	{
		{ _field_block, "template instantiations", &template_instantiation_block_definition_block },
		{ _field_block, "components", &component_definition_block },
		{ _field_block, "component indices", &component_index_block_definition_block },
		{ _field_block, "overlays", &overlay_definition_block },
		{ _field_block, "overlays editor only", &overlay_editor_only_definition_block },
		{ _field_block, "property bindings", &property_binding_block },
		{ _field_block, "binding conversion long comparisons", &binding_conversion_long_comparison_block_definition_block },
		{ _field_block, "static data tables", &static_data_table_block },
		{ _field_block, "expressions", &expression_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "encapsulated properties", &encapsulatedProperties_block },

		{ _field_terminator }
	};

	#define PROPERTIES_STRUCT_ID { 0xB1A7EC45, 0xBC3D439E, 0xA6D9F1A4, 0xA30957AF }
	TAG_STRUCT(
		properties_struct,
		"properties_struct",
		"s_cui_properties_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PROPERTIES_STRUCT_ID)
	{
		{ _field_block, "long properties", &property_long_value_block },
		{ _field_block, "real properties", &property_real_value_block },
		{ _field_block, "string_id properties", &property_string_id_value_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "component ptr properties", &propertyComponentPtrValue_block },

		{ _field_block, "tag reference properties", &property_tag_reference_value_block },
		{ _field_block, "string properties", &property_text_value_block },
		{ _field_block, "argb color properties", &property_argb_color_value_block },
		{ _field_terminator }
	};

	#define ANIMATION_SCALAR_FUNCTION_ID { 0x93DF7492, 0x416A1688, 0x609C91AE, 0xC3D187EE }
	TAG_STRUCT(
		animation_scalar_function,
		"animation_scalar_function",
		"s_cui_animation_scalar_function",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		ANIMATION_SCALAR_FUNCTION_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_default),
		{ _field_struct, "scalar function", &mapping_function },
		{ _field_terminator }
	};

	#define STATIC_DATA_STRUCT_ID { 0x2618E512, 0x8FF9442B, 0x9F93FFB2, 0x90B8121F }
	TAG_STRUCT(
		static_data_struct,
		"static_data_struct",
		"s_cui_static_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STATIC_DATA_STRUCT_ID)
	{
		{ _field_block, "columns", &static_data_column_block },
		{ _field_block, "rows", &static_data_row_block },
		{ _field_terminator }
	};

	STRINGS(propertyComponentPtrFlags)
	{
		"source is in external system"
	};
	STRING_LIST(propertyComponentPtrFlags, propertyComponentPtrFlags_strings, _countof(propertyComponentPtrFlags_strings));

	STRINGS(property_type)
	{
		"boolean",
		"long",
		"real",
		"string",
		"component",
		"tag reference",
		"string id",
		"argb color",
		"emblem info"
	};
	STRING_LIST(property_type, property_type_strings, _countof(property_type_strings));

	STRINGS(property_binding_flags)
	{
		"source is in external screen",
		"source is in external system",
		"target is in external system"
	};
	STRING_LIST(property_binding_flags, property_binding_flags_strings, _countof(property_binding_flags_strings));

	STRINGS(binding_conversion_function_enum_definition)
	{
		"none",
		"negate bool",
		"compare long"
	};
	STRING_LIST(binding_conversion_function_enum_definition, binding_conversion_function_enum_definition_strings, _countof(binding_conversion_function_enum_definition_strings));

	STRINGS(binding_conversion_comparison_operator_enum_definition)
	{
		"equality",
		"inequality",
		"less than",
		"less than or equal",
		"greater than or equal",
		"greater than"
	};
	STRING_LIST(binding_conversion_comparison_operator_enum_definition, binding_conversion_comparison_operator_enum_definition_strings, _countof(binding_conversion_comparison_operator_enum_definition_strings));

	STRINGS(animation_property_composition_type)
	{
		"relative to current",
		"absolute to screen",
		"absolute to parent"
	};
	STRING_LIST(animation_property_composition_type, animation_property_composition_type_strings, _countof(animation_property_composition_type_strings));

	STRINGS(animation_property_flags)
	{
		"loop"
	};
	STRING_LIST(animation_property_flags, animation_property_flags_strings, _countof(animation_property_flags_strings));

	STRINGS(animationInputType)
	{
		"time",
		"binding"
	};
	STRING_LIST(animationInputType, animationInputType_strings, _countof(animationInputType_strings));

	STRINGS(step_type)
	{
		"operator",
		"variable",
		"real value",
		"string id value"
	};
	STRING_LIST(step_type, step_type_strings, _countof(step_type_strings));

	STRINGS(step_operator)
	{
		"add",
		"subtract",
		"multiply",
		"divide",
		"negate",
		"not",
		"less than",
		"less than or equal to",
		"greater than",
		"greater than or equal to",
		"equals",
		"not equals",
		"and",
		"or",
		"mod"
	};
	STRING_LIST(step_operator, step_operator_strings, _countof(step_operator_strings));

	STRINGS(step_variable)
	{
		"variable a",
		"variable b",
		"variable c",
		"variable d",
		"variable e",
		"variable f",
		"variable g",
		"variable h"
	};
	STRING_LIST(step_variable, step_variable_strings, _countof(step_variable_strings));

	STRINGS(component_definition_flags)
	{
		"hidden to tools user"
	};
	STRING_LIST(component_definition_flags, component_definition_flags_strings, _countof(component_definition_flags_strings));

	STRINGS(editor_overlay_info_flags)
	{
		"exclude overlay"
	};
	STRING_LIST(editor_overlay_info_flags, editor_overlay_info_flags_strings, _countof(editor_overlay_info_flags_strings));

	STRINGS(editor_property_info_flags)
	{
		"default value"
	};
	STRING_LIST(editor_property_info_flags, editor_property_info_flags_strings, _countof(editor_property_info_flags_strings));

} // namespace macaque

} // namespace blofeld

