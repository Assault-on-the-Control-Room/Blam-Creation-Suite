#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MATERIAL_EFFECTS_STRUCT_DEFINITION_ID { 0x1B36A19F, 0x5F674BCE, 0x97D54F55, 0xE0F07B7A }
	TAG_BLOCK(
		material_effects_block,
		"material_effects_block",
		1,
		"s_material_effects_definition",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_EFFECTS_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "effects", &material_effect_block_v2_block },
		{ _field_useless_pad, "" },
		{ _field_terminator }
	};

	TAG_GROUP(
		material_effects_group,
		MATERIAL_EFFECTS_TAG,
		nullptr,
		INVALID_TAG,
		material_effects_block );

	#define MATERIAL_EFFECT_BLOCK_V2_ID { 0xB0032D67, 0x821D41B8, 0xAE3F37AC, 0x6CC0FD16 }
	TAG_BLOCK(
		material_effect_block_v2_block,
		"material_effect_block_v2",
		k_material_effect_type_count,
		"s_material_effect",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_EFFECT_BLOCK_V2_ID)
	{
		{ _field_block, "old materials (DO NOT USE)", FIELD_FLAG_UNKNOWN0, &old_material_effect_material_block },
		{ _field_block, "sounds", &material_effect_material_block },
		{ _field_block, "effects", &material_effect_material_block },
		{ _field_terminator }
	};

	#define OLD_MATERIAL_EFFECT_MATERIAL_BLOCK_ID { 0x4F36A27D, 0x89FD4598, 0x8E5E3AD5, 0xF3F90ADA }
	TAG_BLOCK(
		old_material_effect_material_block,
		"old_material_effect_material_block",
		33,
		"s_material_effect_material_old",
		SET_UNKNOWN0 | SET_UNKNOWN4 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		OLD_MATERIAL_EFFECT_MATERIAL_BLOCK_ID)
	{
		{ _field_tag_reference, "effect", &global_effect_reference },
		{ _field_tag_reference, "sound", &global_sound_and_looping_sound_reference },
		{ _field_string_id, "material name", FIELD_FLAG_INDEX },
		{ _field_short_integer, "runtime material index", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("KTRVUIKB", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_char_enum, "sweetener mode", &sweeneter_mode_enum },
		FIELD_PAD("QNGPTA", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_useless_pad, "" },
		{ _field_terminator }
	};

	#define MATERIAL_EFFECT_MATERIAL_BLOCK_ID { 0x8FCE6765, 0x945C435C, 0x9241DE33, 0xDC8ED887 }
	TAG_BLOCK(
		material_effect_material_block,
		"material_effect_material_block",
		k_maximum_material_effect_blocks,
		"material_effect_material_block",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_EFFECT_MATERIAL_BLOCK_ID)
	{
		{ _field_tag_reference, "tag (effect or sound)", &material_effect_material_block_tag_effect_or_sound_reference },
		{ _field_tag_reference, "secondary tag (effect or sound)", &material_effect_material_block_tag_effect_or_sound_reference },
		{ _field_string_id, "material name", FIELD_FLAG_INDEX },
		{ _field_short_integer, "runtime material index", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_enum, "sweetener mode", &sweeneter_mode_enum },
		FIELD_PAD("L", nullptr, FIELD_FLAG_NONE, 1),

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_real, "max_visibility_distance", "manual override for the max distance this effect can be from the camera and still be rendered (not valid for sounds)." },

		{ _field_terminator }
	};

	STRINGS(sweeneter_mode_enum)
	{
		"sweetener default",
		"sweetener enabled",
		"sweetener disabled"
	};
	STRING_LIST(sweeneter_mode_enum, sweeneter_mode_enum_strings, _countof(sweeneter_mode_enum_strings));

	TAG_REFERENCE(global_material_effects_reference, MATERIAL_EFFECTS_TAG);

} // namespace macaque

} // namespace blofeld

