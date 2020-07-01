#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(g_scenario_editor_folder_block, k_maximum_scenario_editor_folders)
	{
		{ _field_long_block_index, "parent folder" },
		{ _field_long_string, "name^" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_pad, "pad", 4 },
		{ _field_int64_integer, "offset*!" },

		{ _field_terminator }
	};

} // namespace blofeld

