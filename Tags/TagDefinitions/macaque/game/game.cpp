#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	STRINGS(global_campaign_difficulty_enum)
	{
		"easy",
		"normal",
		"heroic",
		"legendary"
	};
	STRING_LIST(global_campaign_difficulty_enum, global_campaign_difficulty_enum_strings, _countof(global_campaign_difficulty_enum_strings));

	STRINGS(global_campaign_difficulty_flags)
	{
		"easy",
		"normal",
		"heroic",
		"legendary"
	};
	STRING_LIST(global_campaign_difficulty_flags, global_campaign_difficulty_flags_strings, _countof(global_campaign_difficulty_flags_strings));

} // namespace macaque

} // namespace blofeld

