#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(cui_logic, CUI_LOGIC_TAG, cui_logic_block_block );

	TAG_GROUP_FROM_BLOCK(cui_screen, CUI_SCREEN_TAG, cui_screen_block_block );

	TAG_GROUP_FROM_BLOCK(cui_static_data, CUI_STATIC_DATA_TAG, cui_static_data_block_block );

	TAG_BLOCK(template_instantiation_block_definition, k_cui_max_component_count)
	{
		{ _field_tag_reference, "screen reference", &Tag::Reference<struct CuiScreenDefinition>::s_defaultDefinition },
		{ _field_terminator }
	};

	TAG_BLOCK(component_definition, k_cui_max_component_count)
	{
		{ _field_string_id, "type" },
		{ _field_string_id, "name^" },
		{ _field_string_id, "parent" },
		{ _field_word_flags, "flags", &component_definition_flags },
		{ _field_short_block_index, "template instantiation index" },
		{ _field_terminator }
	};

	TAG_BLOCK(component_index_block_definition, k_cui_max_component_count)
	{
		{ _field_string_id, "name^" },
		{ _field_short_block_index, "component definition index" },
		{ _field_pad, "pad0", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(property_long_value, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_long_integer, "value" },
		{ _field_terminator }
	};

	TAG_BLOCK(property_real_value, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_real, "value" },
		{ _field_terminator }
	};

	TAG_BLOCK(property_string_id_value, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "value" },
		{ _field_terminator }
	};

	TAG_BLOCK(propertyComponentPtrValue, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "value" },
		{ _field_byte_flags, "flags", &propertyComponentPtrFlags },
		{ _field_pad, "pad0", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK(property_tag_reference_value, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_tag_reference, "value", &property_tag_reference_value_value_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(property_text_value, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_long_string, "value" },
		{ _field_terminator }
	};

	TAG_BLOCK(property_argb_color_value, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_real_argb_color, "value" },
		{ _field_terminator }
	};

	TAG_BLOCK(component_properties_definition, k_cui_max_component_count)
	{
		{ _field_string_id, "name^" },
		{ _field_struct, "property values", &properties_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_property_keyframe_real_value, 8*k_kilo)
	{
		{ _field_long_integer, "duration:milliseconds#the amount of time from the previous keyframe to this keyframe" },
		{ _field_real, "value#the value when the current time is on this keyframe" },
		{ _field_struct, "transition function", &animation_scalar_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_component_real_property, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_enum, "composition", &animation_property_composition_type },
		{ _field_byte_flags, "flags", &animation_property_flags },
		{ _field_pad, "pad0", 1 },
		{ _field_long_integer, "total milliseconds" },
		{ _field_block, "real keyframes", &animation_property_keyframe_real_value_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_property_keyframe_argb_color_value, 8*k_kilo)
	{
		{ _field_long_integer, "duration:milliseconds#the amount of time from the previous keyframe to this keyframe" },
		{ _field_real_argb_color, "color#the value when the current time is on this keyframe" },
		{ _field_struct, "transition function", &animation_scalar_function_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_component_argb_color_property, 8*k_kilo)
	{
		{ _field_string_id, "name^" },
		{ _field_enum, "composition", &animation_property_composition_type },
		{ _field_byte_flags, "flags", &animation_property_flags },
		{ _field_pad, "pad0", 1 },
		{ _field_long_integer, "total milliseconds" },
		{ _field_block, "argb color keyframes", &animation_property_keyframe_argb_color_value_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_component_definition, k_cui_max_component_count)
	{
		{ _field_string_id, "name^" },
		{ _field_long_integer, "total milliseconds" },
		{ _field_block, "real properties", &animation_component_real_property_block },
		{ _field_block, "argb color properties", &animation_component_argb_color_property_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_definition, k_cui_max_animation_count)
	{
		{ _field_string_id, "name^" },

		{ _field_version_greater, _engine_type_haloreach, 4},
		{ _field_real, "time base offset" },
		{ _field_real, "time exponential offset" },
		{ _field_char_enum, "animation input", &animationInputType },
		{ _field_pad, "pad0", 3 },

		{ _field_block, "components", &animation_component_definition_block },
		{ _field_terminator }
	};

	TAG_BLOCK(overlay_definition, k_cui_max_overlay_count)
	{
		{ _field_string_id, "resolution" },
		{ _field_string_id, "theme" },
		{ _field_block, "components", &component_properties_definition_block },
		{ _field_block, "animations", &animation_definition_block },
		{ _field_terminator }
	};

	TAG_BLOCK(property_editor_only_definition, k_cui_max_property_count)
	{
		{ _field_string_id, "name^" },
		{ _field_byte_flags, "flags", &editor_property_info_flags },
		{ _field_pad, "pad0", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK(component_editor_only_definition, k_cui_max_component_count)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "properties editor only", &property_editor_only_definition_block },
		{ _field_terminator }
	};

	TAG_BLOCK(animation_editor_only_definition, k_cui_max_animation_count)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "components editor only", &component_editor_only_definition_block },
		{ _field_terminator }
	};

	TAG_BLOCK(overlay_editor_only_definition, k_cui_max_overlay_count)
	{
		{ _field_string_id, "resolution" },
		{ _field_string_id, "theme" },
		{ _field_byte_flags, "flags", &editor_overlay_info_flags },
		{ _field_block, "components editor only", &component_editor_only_definition_block },
		{ _field_block, "animations editor only", &animation_editor_only_definition_block },
		{ _field_pad, "pad0", 3 },
		{ _field_terminator }
	};

	TAG_BLOCK(property_binding, k_cui_max_property_binding_count)
	{
		{ _field_word_flags, "flags", &property_binding_flags },
		{ _field_enum, "conversion function", &binding_conversion_function_enum_definition },
		{ _field_string_id, "source component name" },
		{ _field_string_id, "source property name" },
		{ _field_string_id, "target component name" },
		{ _field_string_id, "target property name" },
		{ _field_terminator }
	};

	TAG_BLOCK(binding_conversion_long_comparison_block_definition, k_cui_max_property_binding_count)
	{
		{ _field_string_id, "target component name" },
		{ _field_string_id, "target property name" },
		{ _field_char_enum, "comparison operator", &binding_conversion_comparison_operator_enum_definition },
		{ _field_pad, "pad0", 3 },
		{ _field_long_integer, "comparison value" },
		{ _field_terminator }
	};

	TAG_BLOCK(static_data_column, 128)
	{
		{ _field_string_id, "name^" },
		{ _field_enum, "type", &property_type },
		{ _field_pad, "pad0", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(static_data_row, 256, properties_struct_struct_definition );

	TAG_BLOCK(static_data_table, 128)
	{
		{ _field_string_id, "name^" },
		{ _field_string_id, "mock data for component#a component on this screen that gets replaced in simulation with this data table" },
		{ _field_struct, "static data", &static_data_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(expression_step, s_cui_expression_step_definition::k_maximum_step_count)
	{
		{ _field_char_enum, "step type^", &step_type },
		{ _field_char_enum, "operator", &step_operator },
		{ _field_char_enum, "variable", &step_variable },
		{ _field_pad, "pad0", 1 },
		{ _field_real, "value&real value" },
		{ _field_string_id, "string id value" },
		{ _field_terminator }
	};

	TAG_BLOCK(expression, 128)
	{
		{ _field_string_id, "name^" },
		{ _field_long_string, "expression text" },
		{ _field_block, "steps", &expression_step_block },
		{ _field_terminator }
	};

	TAG_BLOCK(encapsulatedProperties, k_cuiMaxEncapsulationCount)
	{
		{ _field_string_id, "encapsulation name^" },
		{ _field_block, "properties", &static_data_column_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(cui_logic_block, 1, cui_logic_struct_definition_struct_definition );

	TAG_BLOCK(string_file_references, 16)
	{
		{ _field_tag_reference, "string list", &global_multilingual_unicode_string_list_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(cui_screen_block, 1, cui_screen_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(cui_static_data_block, 1, cui_static_data_struct_definition_struct_definition );

	TAG_STRUCT(cui_logic_struct_definition)
	{
		{ _field_string_id, "logic name" },
		{ _field_tag_reference, "string list", &global_multilingual_unicode_string_list_reference },
		{ _field_struct, "system", &cui_system_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(cui_system)
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

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "encapsulated properties", &encapsulatedProperties_block },

		{ _field_terminator }
	};

	TAG_STRUCT(properties_struct)
	{
		{ _field_block, "long properties", &property_long_value_block },
		{ _field_block, "real properties", &property_real_value_block },
		{ _field_block, "string_id properties", &property_string_id_value_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "component ptr properties", &propertyComponentPtrValue_block },

		{ _field_block, "tag reference properties", &property_tag_reference_value_block },
		{ _field_block, "string properties", &property_text_value_block },
		{ _field_block, "argb color properties", &property_argb_color_value_block },
		{ _field_terminator }
	};

	TAG_STRUCT(animation_scalar_function)
	{
		{ _field_custom },
		{ _field_struct, "scalar function", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(static_data_struct)
	{
		{ _field_block, "columns", &static_data_column_block },
		{ _field_block, "rows", &static_data_row_block },
		{ _field_terminator }
	};

	TAG_STRUCT(cui_screen_struct_definition)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "string list", &global_multilingual_unicode_string_list_reference },
		{ _field_struct, "system", &cui_system_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_block, "string references", &string_file_references_block },
		{ _field_tag_reference, "logic", &cui_logic_reference },
		{ _field_struct, "system", &cui_system_struct_definition },

		{ _field_terminator }
	};

	TAG_STRUCT(cui_static_data_struct_definition)
	{
		{ _field_struct, "static data", &static_data_struct_struct_definition },
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

} // namespace blofeld

