#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(gear_block, s_vehicle_engine_definition::k_gear_count_max)
	{
		{ _field_explanation, "loaded torque", "" },
		{ _field_struct, "loaded torque curve", &torque_curve_struct_struct_definition },
		{ _field_explanation, "cruising torque", "" },
		{ _field_struct, "cruising torque curve", &torque_curve_struct_struct_definition },
		{ _field_explanation, "gearing", "" },
		{ _field_real, "min time to upshift#seconds" },
		{ _field_real, "engine up-shift scale#0-1" },
		{ _field_real, "gear ratio" },
		{ _field_real, "min time to downshift#seconds" },
		{ _field_real, "engine down-shift scale#0-1" },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real, "unknown@" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "gear shift sound - shifting up", &global_sound_reference },
		{ _field_tag_reference, "gear shift sound - shifting down", &global_sound_reference },

		{ _field_terminator }
	};

	TAG_BLOCK(load_and_cruise_block, s_vehicle_engine_definition::k_load_and_cruise_looping_sound_max)
	{
		{ _field_string_id, "load cruise function" },
		{ _field_long_block_index, "attachment index" },
		{ _field_terminator }
	};

	TAG_STRUCT(global_vehicle_engine_struct)
	{
		{ _field_explanation, "engine", "" },
		{ _field_real, "engine moment#higher moments make engine spin up slower" },
		{ _field_real, "engine max angular velocity#higher moments make engine spin up slower" },
		{ _field_block, "gears", &gear_block_block },
		{ _field_tag_reference, "gear shift sound", &global_sound_reference },
		{ _field_block, "load and cruise sound", &load_and_cruise_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(torque_curve_struct)
	{
		{ _field_struct, "function", &scalar_function_named_struct_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_real, "unknown@" },

		{ _field_terminator }
	};

} // namespace blofeld

