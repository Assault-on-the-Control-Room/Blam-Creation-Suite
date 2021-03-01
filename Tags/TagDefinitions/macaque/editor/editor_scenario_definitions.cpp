#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define G_SCENARIO_EDITOR_FOLDER_BLOCK_ID { 0x0B9D6A59, 0x9A5741CB, 0xA1D7A5D1, 0x9F085A3D }
	TAG_BLOCK(
		g_scenario_editor_folder_block,
		"g_scenario_editor_folder_block",
		k_maximum_scenario_editor_folders,
		"s_scenario_editor_folder",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		G_SCENARIO_EDITOR_FOLDER_BLOCK_ID)
	{
		{ _field_long_block_index, "parent folder", &g_scenario_editor_folder_block },
		{ _field_long_string, "name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_PAD("pad", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_int64_integer, "offset", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

