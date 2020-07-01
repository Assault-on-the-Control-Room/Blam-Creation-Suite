#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK_FROM_STRUCT(scenario_acoustics_palette_block_definition, k_maximum_cluster_sound_palette_entries_per_structure, scenario_acoustics_palette_block_definition_struct_struct_definition );

	TAG_BLOCK(acoustic_sector_point_block, k_maximum_points_per_sector)
	{
		{ _field_real_point_3d, "position" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_acoustic_sector_block, s_scenario_acoustic_sector::k_maximum_scenario_acoustic_sectors)
	{
		{ _field_block, "points", &acoustic_sector_point_block_block },
		{ _field_real_plane_3d, "top plane!" },
		{ _field_real_plane_3d, "bottom plane!" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_flags, "flags", &acousticPaletteFlags },
		{ _field_real, "occlusion value" },

		{ _field_short_block_index, "acoustics^" },
		{ _field_short_block_index, "editor folder!" },
		{ _field_real, "height" },
		{ _field_real, "sink" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_acoustic_transition_block, s_scenario_acoustic_transition::k_maximum_scenario_acoustic_transitions)
	{
		{ _field_real_point_3d, "center!" },
		{ _field_real_point_3d, "forward!" },
		{ _field_real_point_3d, "up!" },
		{ _field_real, "half width!" },
		{ _field_real, "half height!" },
		{ _field_real, "sample point offset 0!" },
		{ _field_real, "sample point offset 1!" },
		{ _field_short_block_index, "sample 0*" },
		{ _field_short_block_index, "sample 1*" },
		{ _field_struct, "location 0*!", &scenario_acoustic_location_definition_struct_definition },
		{ _field_struct, "location 1*!", &scenario_acoustic_location_definition_struct_definition },
		{ _field_short_block_index, "editor folder!" },
		{ _field_pad, "CKJEWRSDF", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_acoustics_palette_block_definition_struct)
	{
		{ _field_string_id, "name^" },
		{ _field_explanation, "SOUND ENVIRONMENT", "" },
		{ _field_struct, "reverb", &scenario_acoustics_environment_definition_struct_definition },
		{ _field_explanation, "BACKGROUND SOUND", "" },
		{ _field_struct, "ambience", &scenario_acoustics_ambience_definition_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_explanation, "SOUND BANK", "" },
		{ _field_tag_reference, "Sound bank tag", &global_soundbank_reference },
		{ _field_tag_reference, "DVD Only sound bank tag", &global_soundbank_reference },

		{ _field_terminator }
	};

	TAG_STRUCT(scenario_acoustics_environment_definition)
	{
		{ _field_tag_reference, "sound environment", &global_sound_environment_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_long_enum, "type", &sound_class_acoustics_string_definition },

		{ _field_real, "cutoff distance" },
		{ _field_real, "interpolation time{interpolation speed}:seconds" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_acoustics_ambience_definition)
	{
		{ _field_tag_reference, "background sound", &global_looping_sound_reference },
		{ _field_tag_reference, "weather sound#plays when rain is active, weather rate gets applied to scale.", &global_looping_sound_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "entry sound#plays when entering this area", &global_sound_reference },
		{ _field_tag_reference, "exit sound#plays when leaving this area", &global_sound_reference },

		{ _field_real, "cutoff distance" },
		{ _field_real, "interpolation time{interpolation speed}:seconds" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_long_flags, "scale flags", &background_sound_scale_flags_definition },
		{ _field_real_fraction, "interior scale" },
		{ _field_real_fraction, "portal scale" },
		{ _field_real_fraction, "exterior scale" },


		{ _field_version_greater, _engine_type_haloreach, 4 },
		{ _field_long_flags, "scale flags DEPRICATED!", &background_sound_scale_flags_definition },
		{ _field_real_fraction, "interior scale DEPRICATED!" },
		{ _field_real_fraction, "portal scale DEPRICATED!" },
		{ _field_real_fraction, "exterior scale DEPRICATED!" },

		{ _field_terminator }
	};

	TAG_STRUCT(scenario_acoustic_location_definition)
	{
		{ _field_short_block_index, "sector index*!" },
		{ _field_struct, "cluster reference*!", &scenario_acoustic_cluster_reference_definition_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_acoustic_cluster_reference_definition)
	{
		{ _field_char_integer, "bsp index*!" },
		{ _field_byte_integer, "cluster index*!" },
		{ _field_terminator }
	};

	STRINGS(background_sound_scale_flags_definition)
	{
		"override default scale",
		"use adjacent cluster as portal scale",
		"use adjacent cluster as exterior scale",
		"scale with weather intensity"
	};
	STRING_LIST(background_sound_scale_flags_definition, background_sound_scale_flags_definition_strings, _countof(background_sound_scale_flags_definition_strings));

	STRINGS(acousticPaletteFlags)
	{
		"occlude if above",
		"occlude if below"
	};
	STRING_LIST(acousticPaletteFlags, acousticPaletteFlags_strings, _countof(acousticPaletteFlags_strings));

} // namespace blofeld

