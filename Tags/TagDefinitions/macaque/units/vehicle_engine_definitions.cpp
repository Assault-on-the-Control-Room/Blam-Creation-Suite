#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GEAR_BLOCK_ID { 0x43A70404, 0x7A0440D7, 0xA12F738C, 0x29E046A5 }
	TAG_BLOCK(
		gear_block,
		"gear_block",
		s_vehicle_engine_definition::k_gear_count_max,
		"s_vehicle_gear_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GEAR_BLOCK_ID)
	{
		FIELD_EXPLANATION("loaded torque", nullptr, FIELD_FLAG_NONE, ""),

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 6 }, // Struct but linker time yo
		{ _field_real, "min torque" },
		{ _field_real, "max torque" },
		{ _field_real, "peak torque scale" },
		{ _field_real, "past peak torque scale exponent" },
		{ _field_real, "torque at max angular velocity" },
		{ _field_real, "torque at 2x max angular velocity" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_struct, "loaded torque curve", &torque_curve_struct },

		FIELD_EXPLANATION("cruising torque", nullptr, FIELD_FLAG_NONE, ""),

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 6 }, // Struct but linker time yo
		{ _field_real, "min torque" },
		{ _field_real, "max torque" },
		{ _field_real, "peak torque scale" },
		{ _field_real, "past peak torque scale exponent" },
		{ _field_real, "torque at max angular velocity" },
		{ _field_real, "torque at 2x max angular velocity" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_struct, "cruising torque curve", &torque_curve_struct },

		FIELD_EXPLANATION("gearing", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "min time to upshift", "seconds" },
		{ _field_real, "engine up-shift scale", "0-1" },
		{ _field_real, "gear ratio" },
		{ _field_real, "min time to downshift", "seconds" },
		{ _field_real, "engine down-shift scale", "0-1" },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_real, "@unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "gear shift sound - shifting up", &global_sound_reference },
		{ _field_tag_reference, "gear shift sound - shifting down", &global_sound_reference },
		{ _field_terminator }
	};

	#define LOAD_AND_CRUISE_BLOCK_ID { 0x9CF23975, 0xE2494C32, 0x95369BF4, 0x4DD24649 }
	TAG_BLOCK(
		load_and_cruise_block,
		"load_and_cruise_block",
		s_vehicle_engine_definition::k_load_and_cruise_looping_sound_max,
		"s_vehicle_load_and_cruise_definition",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LOAD_AND_CRUISE_BLOCK_ID)
	{
		{ _field_string_id, "load cruise function" },
		{ _field_long_block_index, "attachment index", &global_object_attachment_block },
		{ _field_terminator }
	};

	#define GLOBAL_VEHICLE_ENGINE_STRUCT_ID { 0xB2086F9C, 0xE80E4D79, 0x81DDEB34, 0xBA677DA4 }
	TAG_STRUCT(
		global_vehicle_engine_struct,
		"global_vehicle_engine_struct",
		"s_vehicle_engine_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GLOBAL_VEHICLE_ENGINE_STRUCT_ID)
	{
		FIELD_EXPLANATION("engine", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "engine moment", "higher moments make engine spin up slower" },
		{ _field_real, "engine max angular velocity", "higher moments make engine spin up slower" },
		{ _field_block, "gears", &gear_block },
		{ _field_tag_reference, "gear shift sound", &global_sound_reference },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "load and cruise sound", &load_and_cruise_block },

		{ _field_terminator }
	};

	#define TORQUE_CURVE_STRUCT_ID { 0xA1B86A30, 0x21864A2C, 0xB26E5CA6, 0xF2DB9FC3 }
	TAG_STRUCT(
		torque_curve_struct,
		"torque_curve_struct",
		"s_toruqe_curve_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TORQUE_CURVE_STRUCT_ID)
	{
		{ _field_struct, "function", &scalar_function_named_struct },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

