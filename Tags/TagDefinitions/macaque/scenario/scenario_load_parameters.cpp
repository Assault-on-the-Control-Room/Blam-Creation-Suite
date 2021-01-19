#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_SCENARIO_LOAD_PARAMETERS_BLOCK_ID { 0x4B6AED51, 0xF0454236, 0x871E52C4, 0xA013780C }
	TAG_BLOCK(
		global_scenario_load_parameters_block,
		"scenario load parameters",
		k_scenario_load_maximum_parameter_blocks,
		"s_scenario_load_parameters",
		GLOBAL_SCENARIO_LOAD_PARAMETERS_BLOCK_ID)
	{
		{ _field_explanation, "SCENARIO LOAD PARAMETERS", "strip-variant <variant-name>\nstrips a given variant out of the model tag\nstrip-dialogue\nstrips all the dialogue for this model i.e. cinematic only" },
		{ _field_tag_reference, "scenario^", &scenario_reference$2 },
		{ _field_data, "parameters" },
		{ _field_pad, "BDZDSK", 32 },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

