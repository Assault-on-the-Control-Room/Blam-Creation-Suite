#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(scenario_object_node_orientations_bit_vector_block, 2*(((((MAXIMUM_NODES_PER_MODEL)+(k_int32_bits-1))>>k_int32_bits_bits))*sizeof(int32)))
	{
		{ _field_byte_integer, "data*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_object_node_orientations_orientations_block, MAXIMUM_NODES_PER_MODEL*7)
	{
		{ _field_short_integer, "number*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_object_node_orientations_block, 1)
	{
		{ _field_short_integer, "node count*!" },
		{ _field_pad, "paddington", 2 },
		{ _field_block, "bit vector*!", &scenario_object_node_orientations_bit_vector_block_block },
		{ _field_block, "orientations*!", &scenario_object_node_orientations_orientations_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(scriptListBlock, k_maximum_hs_source_files_per_context)
	{
		{ _field_string_id, "script name^" },
		{ _field_terminator }
	};

	TAG_BLOCK(commandLinkBlock, CommandDispatcher::MAX_LINKS)
	{
		{ _field_long_enum, "Trigger^", &internal_event_enum_definition },
		{ _field_long_block_index, "Target" },
		{ _field_long_enum, "Command", &command_event_enum_definition },
		{ _field_real, "Delay (sec)" },
		{ _field_long_flags, "Flags", &commandLinkFlags },
		{ _field_terminator }
	};

	TAG_BLOCK(pathfinding_object_index_list_block, MAXIMUM_STRUCTURE_BSPS_PER_SCENARIO)
	{
		{ _field_short_integer, "bsp index" },
		{ _field_short_integer, "pathfinding object index" },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_scenery_block, MAXIMUM_SCENERY_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "scenery data", &scenario_scenery_datum_struct_v4_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_scenery_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &scenery_reference$4 },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_biped_block, MAXIMUM_BIPED_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "unit data", &scenario_unit_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },

		{ _field_terminator }
	};

	TAG_BLOCK(scenario_biped_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &biped_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_vehicle_block, MAXIMUM_VEHICLE_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "unit data", &scenario_unit_struct_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "vehicle data", &scenario_vehicle_datum_struct_struct_definition },

		{ _field_terminator }
	};

	TAG_BLOCK(scenario_vehicle_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &vehicle_reference$2 },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_equipment_block, MAXIMUM_EQUIPMENT_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "equipment data", &scenario_equipment_datum_struct_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_equipment_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &equipment_reference$3 },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_weapon_block, MAXIMUM_WEAPON_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "weapon data", &scenario_weapon_datum_struct_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_weapon_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &weapon_reference$7 },
		{ _field_terminator }
	};

	TAG_BLOCK(device_group_block, MAXIMUM_DEVICE_GROUPS_PER_SCENARIO)
	{
		{ _field_string, "name^" },
		{ _field_real, "initial value:[0,1]" },
		{ _field_long_flags, "flags", &device_group_flags },
		{ _field_short_block_index, "editor folder!" },
		{ _field_pad, "WAFNDIO", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_machine_block, MAXIMUM_MACHINE_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "device data", &scenario_device_struct_struct_definition },
		{ _field_struct, "machine data", &scenario_machine_struct_v3_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_machine_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &device_machine_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_terminal_block, MAXIMUM_TERMINAL_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "device data", &scenario_device_struct_struct_definition },
		{ _field_struct, "terminal data", &scenario_terminal_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_terminal_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &device_terminal_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_control_block, MAXIMUM_CONTROL_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "device data", &scenario_device_struct_struct_definition },
		{ _field_struct, "control data", &scenario_control_struct_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_control_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &device_control_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(ScenarioDispenserBlock, MAXIMUM_DISPENSER_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "device data", &scenario_device_struct_struct_definition },
		{ _field_struct, "dispenser data", &ScenarioDispenserStruct_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(ScenarioDispenserPaletteBlock, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &device_dispenser_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_sound_scenery_block, MAXIMUM_SOUND_SCENERY_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "sound_scenery", &sound_scenery_datum_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_sound_scenery_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &sound_scenery_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_giant_block, MAXIMUM_GIANT_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "unit data", &scenario_unit_struct_struct_definition },
		{ _field_struct, "giant data", &scenario_giant_datum_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_giant_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &giant_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_effect_scenery_block, MAXIMUM_EFFECT_SCENERY_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "effect scenery data", &scenario_effect_scenery_datum_struct_struct_definition },

		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_effect_scenery_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &effect_scenery_reference$2 },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_spawner_block, MAXIMUM_SPAWNER_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "Entity Data", &ScenarioEntityStruct_struct_definition },
		{ _field_struct, "Spawner Data", &ScenarioSpawnerStruct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_spawner_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &spawner_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_requisition_palette_block, MAXIMUM_REQUISITION_MENU_SIZE)
	{
		{ _field_explanation, "CUSTOM APPS", "If you want the award to be a custom app, point at globals/custom_app_globals, and match one of the names from that tag for \"display_name\"" },
		{ _field_tag_reference, "name^", &scenario_requisition_palette_block_name_reference },
		{ _field_tag_reference, "second name^", &scenario_requisition_palette_block_name_reference },
		{ _field_tag_reference, "third name^", &scenario_requisition_palette_block_name_reference },
		{ _field_string_id, "display_name^" },
		{ _field_long_enum, "Submenu#controls which requisition submenu this object should appear in", &requisition_submenu_global_enum },
		{ _field_long_integer, "maximum allowed#cant buy more if there are too many in play" },
		{ _field_real, "price per instance" },
		{ _field_string_id, "model variant name" },
		{ _field_real, "bounty for destruction" },
		{ _field_short_integer, "min fireteam tier#0=Bronze, 1=Silver, or 2=Gold" },
		{ _field_byte_integer, "additional frag grenades" },
		{ _field_byte_integer, "additional plasma grenades" },
		{ _field_long_flags, "built-in palettes for which item is enabled by default", &scenario_requisition_palette_presence },
		{ _field_long_enum, "special buy", &requisition_special_buy_enum },
		{ _field_long_integer, "starting ammo#1..100 for ammoless weapons, 0 = default for all weapons" },
		{ _field_real, "warm-up time:seconds#item will be unavailable until x seconds into the scenario" },
		{ _field_real, "player purchase frequency:seconds" },
		{ _field_real, "team purchase frequency:seconds" },
		{ _field_real, "price increase factor#price = original-price x increase-factor to-the n_times_bought" },
		{ _field_byte_integer, "maximum buy count:per player" },
		{ _field_byte_integer, "total maximum buy count:per team" },
		{ _field_pad, "SMYE", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_crate_block, MAXIMUM_CRATE_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_struct, "permutation data", &scenario_object_permutation_struct_struct_definition },
		{ _field_struct, "crate data", &scenario_crate_datum_struct_struct_definition },
		{ _field_struct, "multiplayer data", &scenario_multiplayer_object_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_crate_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &crate_reference$6 },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_creature_block, MAXIMUM_CREATURE_DATUMS_PER_SCENARIO)
	{
		{ _field_custom },
		{ _field_short_block_index, "type" },
		{ _field_custom },
		{ _field_short_block_index, "name^" },
		{ _field_struct, "object data", &scenario_object_datum_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(scenario_creature_palette_block, MAXIMUM_SCENARIO_OBJECT_PALETTE_ENTRIES_PER_BLOCK)
	{
		{ _field_tag_reference, "name^", &creature_reference$2 },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_object_id_struct)
	{
		{ _field_long_integer, "unique id*" },
		{ _field_short_block_index, "origin bsp index*" },
		{ _field_char_enum, "type*", &object_type_enum_definition },
		{ _field_char_enum, "source*", &object_source_enum_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_object_reference_struct)
	{
		{ _field_short_integer, "object index*" },
		{ _field_short_integer, "scenario object index*" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_object_datum_struct)
	{
		{ _field_custom },
		{ _field_long_flags, "placement flags", &object_location_placement_flags },
		{ _field_real_point_3d, "position" },
		{ _field_real_euler_angles_3d, "rotation" },
		{ _field_real, "scale" },
		{ _field_block, "node orientations!*", &scenario_object_node_orientations_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_pad, "pad", 3 }, // #TODO: Poke around these values
		{ _field_char_enum, "bsp policy", &scenario_object_bsp_placement_policy_definition },
		{ _field_short_integer, "manual bsp flags*" },
		{ _field_pad, "pad", 2 }, // #TODO: Poke around these values

		{ _field_version_greater, _engine_type_haloreach, 8 },
		{ _field_real, "gravity override" },
		{ _field_byte_flags, "gravity flags", &object_gravity_flags },
		{ _field_pad, "ZEE", 1 },
		{ _field_char_enum, "bsp policy", &scenario_object_bsp_placement_policy_definition },
		{ _field_byte_flags, "script flags", &scenarioObjectScriptFlagsDefinition },
		{ _field_block, "force enabled scripts", &scriptListBlock_block },
		{ _field_block, "disabled scripts", &scriptListBlock_block },
		{ _field_struct, "manual bsp flags*", &manualBspFlagsReferences_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_word_flags, "transform flags!", &object_transform_flags },
		{ _field_char_enum, "Nav Mesh Cutting", &NavMeshCuttingOverrideEnum },
		{ _field_char_enum, "Nav Mesh Obstacle", &BooleanOverrideEnum },
		{ _field_byte_flags, "Nav Mesh Flags", &object_navmesh_flags },
		{ _field_pad, "ZEE2", 3 },

		{ _field_string_id, "light airprobe name" },
		{ _field_struct, "object id", &scenario_object_id_struct_struct_definition },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_long_flags, "Light Channels:", &channelDefinitionFlags },
		{ _field_non_cache_runtime_value, "runtimeObjectHandle!*" },

		{ _field_short_block_index, "editor folder!" },
		{ _field_pad, "NCIUNE", 2 },
		{ _field_struct, "parent id", &scenario_object_parent_struct_struct_definition },
		{ _field_long_block_flags, "can attach to bsp flags*!" },

		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_real, "Directional Acceleration Mult. #Multiplier applied to all phantoms\' direction acceleration factors.  Used to scale man-cannon strength." },
		{ _field_block, "Command Links", &commandLinkBlock_block },

		{ _field_terminator }
	};

	TAG_STRUCT(scenario_object_parent_struct)
	{
		{ _field_pad, "der", 2 },
		{ _field_short_block_index, "parent object#if an object with this name exists, we attach to it as a child" },
		{ _field_string_id, "parent marker" },
		{ _field_custom },
		{ _field_string_id, "connection marker" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_object_permutation_struct)
	{
		{ _field_string_id, "variant name" },
		{ _field_byte_flags, "active change colors", &scenario_object_active_change_color_flags },
		{ _field_pad, "SLCJNEROH", 3 },
		{ _field_rgb_color, "primary color" },
		{ _field_rgb_color, "secondary color" },
		{ _field_rgb_color, "tertiary color" },
		{ _field_rgb_color, "quaternary color" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_scenery_datum_struct_v4)
	{
		{ _field_custom },
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		{ _field_enum, "Lightmapping policy", &scenery_lightmap_policy_enum },
		{ _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block },
		{ _field_short_integer, "havok mopp index!" },
		{ _field_short_block_index, "ai spawning squad" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_multiplayer_object_struct)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach, 23 },
		{ _field_explanation, "Multiplayer Data", "object data for multiplayer game use" },
		{ _field_string, "megalo label" },
		{ _field_long_enum, "game engine symmetric placement", &game_engine_symmetry_placement_flags },
		{ _field_byte_flags, "game engine flags", &global_game_engine_type_flags },
		{ _field_char_enum, "owner team", &global_multiplayer_team_designator_enum_definition },
		{ _field_pad, "pad", 2 },
		{ _field_char_integer, "unknown" },
		{ _field_char_integer, "quota minimum" },
		{ _field_char_integer, "quota maximum:<=0 for unlimited" },
		{ _field_byte_flags, "spawn flags", &multiplayer_object_placement_spawn_flags },
		{ _field_short_integer, "spawn time:seconds" },
		{ _field_short_integer, "abandonment time:seconds" },
		{ _field_real, "boundary width or radius" },
		{ _field_real, "boundary box length" },
		{ _field_real, "boundary positive height" },
		{ _field_real, "boundary negative height" },
		{ _field_char_enum, "boundary shape", &multiplayer_goal_area_boundary_shape_enum },
		{ _field_pad, "boundary_pad", 1 },
		{ _field_char_enum, "teleporter channel", &multiplayer_teleporter_channel },
		{ _field_byte_flags, "teleporter passability", &teleporter_passability_flags },
		{ _field_string_id, "location name" },
		{ _field_struct, "map variant parent", &scenario_object_parent_struct_struct_definition },
		{ _field_pad, "unknown", 4 },

		{ _field_version_greater, _engine_type_haloreach, 27 },
		{ _field_explanation, "Multiplayer Data", "object data for multiplayer game use" },
		{ _field_string, "megalo label" },
		{ _field_string, "megalo label 2" },
		{ _field_string, "megalo label 3" },
		{ _field_string, "megalo label 4" },
		{ _field_char_enum, "game engine symmetric placement", &game_engine_symmetry_placement_flags },
		{ _field_byte_flags, "game engine flags", &global_game_engine_type_flags },
		{ _field_char_enum, "owner team", &global_multiplayer_team_designator_enum_definition },
		{ _field_byte_flags, "spawn flags", &multiplayer_object_placement_spawn_flags },
		{ _field_char_integer, "quota minimum" },
		{ _field_char_integer, "quota maximum:<=0 for unlimited" },
		{ _field_char_enum, "remapping policy", &multiplayer_object_remapping_policy },
		{ _field_char_enum, "teleporter channel", &multiplayer_teleporter_channel },
		{ _field_byte_flags, "teleporter passability", &teleporter_passability_flags },
		{ _field_char_integer, "spawn order:-1 for random" },
		{ _field_char_integer, "user data 2" },
		{ _field_char_enum, "trait zone channel", &multiplayer_teleporter_channel },
		{ _field_real, "boundary width or radius" },
		{ _field_real, "boundary box length" },
		{ _field_real, "boundary positive height" },
		{ _field_real, "boundary negative height" },
		{ _field_char_enum, "boundary shape", &multiplayer_goal_area_boundary_shape_enum },
		{ _field_pad, "boundary_pad", 3 },
		{ _field_short_integer, "spawn time:seconds" },
		{ _field_short_integer, "abandonment time:seconds" },
		{ _field_string_id, "location name" },
		{ _field_struct, "map variant parent", &scenario_object_parent_struct_struct_definition },

		{ _field_terminator }
	};

	TAG_STRUCT(scenario_unit_struct)
	{
		{ _field_real, "body vitality:[0,1]" },
		{ _field_long_flags, "flags", &scenario_unit_datum_flags },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_vehicle_datum_struct)
	{
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		{ _field_pad, "post-pathfinding", 2 },
		{ _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_equipment_datum_struct)
	{
		{ _field_long_flags, "equipment flags", &scenario_equipment_flags_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_weapon_datum_struct)
	{
		{ _field_short_integer, "rounds left" },
		{ _field_short_integer, "rounds loaded" },
		{ _field_long_flags, "flags", &scenario_weapon_datum_flags },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_device_struct)
	{
		{ _field_short_block_index, "power group" },
		{ _field_short_block_index, "position group" },
		{ _field_long_flags, "flags", &scenario_device_flags },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_machine_struct_v3)
	{
		{ _field_long_flags, "flags", &scenario_machine_flags },
		{ _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block },
		{ _field_enum, "pathfinding policy", &scenario_machine_pathfinding_policy_enum },
		{ _field_pad, "post-pathfinding-policy", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_terminal_struct)
	{
		{ _field_long_integer, "pah pah" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_control_struct)
	{
		{ _field_long_flags, "flags", &scenario_control_flags },
		{ _field_short_integer, "DON\'T TOUCH THIS!*" },
		{ _field_short_integer, "health station charges#if this control is a health station, this sets the number of charges it contains.\nUse 0 for infinite" },
		{ _field_enum, "allowed players", &scenario_control_character_types },
		{ _field_pad, "SCSP1", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(ScenarioDispenserStruct)
	{
		{ _field_byte_flags, "flags", &ScenarioDispenserFlags },
		{ _field_pad, "pad", 3 },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_scenery_datum_struct)
	{
		{ _field_long_enum, "volume type", &sound_volume_type_enumeration },
		{ _field_real, "height" },
		{ _field_angle_bounds, "override cone angle bounds" },
		{ _field_real, "override outer cone gain:dB" },
		{ _field_struct, "override distance parameters", &sound_distance_parameters_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_giant_datum_struct)
	{
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		{ _field_pad, "post-pathfinding", 2 },
		{ _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_effect_scenery_datum_struct)
	{
		{ _field_real, "effect size scale" },
		{ _field_terminator }
	};

	TAG_STRUCT(ScenarioEntityStruct)
	{
		{ _field_real, "Entity Placeholder" },
		{ _field_terminator }
	};

	TAG_STRUCT(ScenarioSpawnerStruct)
	{
		{ _field_real, "Spawner Placeholder" },
		{ _field_terminator }
	};

	TAG_STRUCT(scenario_crate_datum_struct)
	{
		{ _field_enum, "Pathfinding policy", &pathfinding_policy_enum },
		{ _field_pad, "post-path-policy", 2 },
		{ _field_block, "pathfinding references*", &pathfinding_object_index_list_block_block },
		{ _field_terminator }
	};

	STRINGS(object_location_placement_flags)
	{
		"not automatically",
		"unused0",
		"unused1",
		"unused2",
		"lock type to env. object",
		"lock transform to env. object",
		"never placed",
		"lock name to env. object",
		"create at rest",
		"store orientations",
		"pvs bound",
		"startup",
		"attach physically",
		"attach with scale",
		"no parent lighting"
	};
	STRING_LIST(object_location_placement_flags, object_location_placement_flags_strings, _countof(object_location_placement_flags_strings));

	STRINGS(object_gravity_flags)
	{
		"apply override",
		"apply to children also"
	};
	STRING_LIST(object_gravity_flags, object_gravity_flags_strings, _countof(object_gravity_flags_strings));

	STRINGS(object_navmesh_flags)
	{
		"children inherit navmesh interaction",
		"navmesh always loaded"
	};
	STRING_LIST(object_navmesh_flags, object_navmesh_flags_strings, _countof(object_navmesh_flags_strings));

	STRINGS(object_transform_flags)
	{
		"mirrored"
	};
	STRING_LIST(object_transform_flags, object_transform_flags_strings, _countof(object_transform_flags_strings));

	STRINGS(scenario_object_active_change_color_flags)
	{
		"primary",
		"secondary",
		"tertiary",
		"quaternary"
	};
	STRING_LIST(scenario_object_active_change_color_flags, scenario_object_active_change_color_flags_strings, _countof(scenario_object_active_change_color_flags_strings));

	STRINGS(scenarioObjectScriptFlagsDefinition)
	{
		"scripts disabled",
		"use override lists",
		"scripts always run"
	};
	STRING_LIST(scenarioObjectScriptFlagsDefinition, scenarioObjectScriptFlagsDefinition_strings, _countof(scenarioObjectScriptFlagsDefinition_strings));

	STRINGS(object_type_enum_definition)
	{
		"biped",
		"vehicle",
		"weapon",
		"equipment",
		"terminal",
		"projectile",
		"scenery",
		"machine",
		"control",
		"dispenser",
		"sound_scenery",
		"crate",
		"creature",
		"giant",
		"effect_scenery",
		"spawner"
	};
	STRING_LIST(object_type_enum_definition, object_type_enum_definition_strings, _countof(object_type_enum_definition_strings));

	STRINGS(object_source_enum_definition)
	{
		"structure",
		"editor",
		"dynamic",
		"legacy",
		"sky",
		"parent"
	};
	STRING_LIST(object_source_enum_definition, object_source_enum_definition_strings, _countof(object_source_enum_definition_strings));

	STRINGS(command_event_enum_definition)
	{
		"Interact",
		"InitShardSpawn",
		"InitKnightTaint"
	};
	STRING_LIST(command_event_enum_definition, command_event_enum_definition_strings, _countof(command_event_enum_definition_strings));

	STRINGS(internal_event_enum_definition)
	{
		"OnBirth",
		"OnDeath",
		"OnInteract",
		"OnInitSpawnerShard",
		"OnInitKnightTaint"
	};
	STRING_LIST(internal_event_enum_definition, internal_event_enum_definition_strings, _countof(internal_event_enum_definition_strings));

	STRINGS(commandLinkFlags)
	{
		"Fire Once"
	};
	STRING_LIST(commandLinkFlags, commandLinkFlags_strings, _countof(commandLinkFlags_strings));

	STRINGS(scenario_object_bsp_placement_policy_definition)
	{
		"default",
		"always placed",
		"manual bsp placement"
	};
	STRING_LIST(scenario_object_bsp_placement_policy_definition, scenario_object_bsp_placement_policy_definition_strings, _countof(scenario_object_bsp_placement_policy_definition_strings));

	STRINGS(game_engine_symmetry_placement_flags)
	{
		"ignore",
		"symmetric",
		"asymmetric"
	};
	STRING_LIST(game_engine_symmetry_placement_flags, game_engine_symmetry_placement_flags_strings, _countof(game_engine_symmetry_placement_flags_strings));

	STRINGS(global_game_engine_type_flags)
	{
		"none",
		"sandbox",
		"megalogamengine",
		"campaign",
		"survival",

		{ _field_version_greater, _engine_type_haloreach },
		"firefight"
	};
	STRING_LIST(global_game_engine_type_flags, global_game_engine_type_flags_strings, _countof(global_game_engine_type_flags_strings));

	STRINGS(multiplayer_object_remapping_policy)
	{
		"normal-default",
		"do not replace",
		"only replace"
	};
	STRING_LIST(multiplayer_object_remapping_policy, multiplayer_object_remapping_policy_strings, _countof(multiplayer_object_remapping_policy_strings));

	STRINGS(multiplayer_goal_area_boundary_shape_enum)
	{
		"unused",
		"sphere",
		"cylinder",
		"box"
	};
	STRING_LIST(multiplayer_goal_area_boundary_shape_enum, multiplayer_goal_area_boundary_shape_enum_strings, _countof(multiplayer_goal_area_boundary_shape_enum_strings));

	STRINGS(multiplayer_teleporter_channel)
	{
		"alpha",
		"bravo",
		"charlie",
		"delta",
		"echo",
		"foxtrot",
		"golf",
		"hotel",
		"india",
		"juliet",
		"kilo",
		"lima",
		"mike",
		"november",
		"oscar",
		"papa",
		"quebec",
		"romeo",
		"sierra",
		"tango",
		"uniform",
		"victor",
		"whiskey",
		"xray",
		"yankee",
		"zulu"
	};
	STRING_LIST(multiplayer_teleporter_channel, multiplayer_teleporter_channel_strings, _countof(multiplayer_teleporter_channel_strings));

	STRINGS(multiplayer_object_placement_spawn_flags)
	{
		"unique spawn",
		"not initially placed",
		"hide unless megalo required",
		"is shortcut object",
		"can spawn on bipeds",
		"spawner starts inactive"
	};
	STRING_LIST(multiplayer_object_placement_spawn_flags, multiplayer_object_placement_spawn_flags_strings, _countof(multiplayer_object_placement_spawn_flags_strings));

	STRINGS(pathfinding_policy_enum)
	{
		"Tag Default",
		"Pathfinding DYNAMIC",
		"Pathfinding CUT-OUT",
		"Pathfinding STATIC",
		"Pathfinding NONE"
	};
	STRING_LIST(pathfinding_policy_enum, pathfinding_policy_enum_strings, _countof(pathfinding_policy_enum_strings));

	STRINGS(scenery_lightmap_policy_enum)
	{
		"Tag Default",
		"Dynamic",
		"Per-Vertex"
	};
	STRING_LIST(scenery_lightmap_policy_enum, scenery_lightmap_policy_enum_strings, _countof(scenery_lightmap_policy_enum_strings));

	STRINGS(scenario_equipment_flags_definition)
	{
		"OBSOLETE0",
		"OBSOLETE1",
		"does accelerate (moves due to explosions)"
	};
	STRING_LIST(scenario_equipment_flags_definition, scenario_equipment_flags_definition_strings, _countof(scenario_equipment_flags_definition_strings));

	STRINGS(scenario_weapon_datum_flags)
	{
		"initially at rest (doesn\'t fall)",
		"obsolete",
		"does accelerate (moves due to explosions)"
	};
	STRING_LIST(scenario_weapon_datum_flags, scenario_weapon_datum_flags_strings, _countof(scenario_weapon_datum_flags_strings));

	STRINGS(scenario_unit_datum_flags)
	{
		"dead",
		"opened",
		"not enterable by player"
	};
	STRING_LIST(scenario_unit_datum_flags, scenario_unit_datum_flags_strings, _countof(scenario_unit_datum_flags_strings));

	STRINGS(requisition_submenu_global_enum)
	{
		"Support"
	};
	STRING_LIST(requisition_submenu_global_enum, requisition_submenu_global_enum_strings, _countof(requisition_submenu_global_enum_strings));

	STRINGS(scenario_requisition_palette_presence)
	{
		"empty palette",
		"full palette",
		"spartan palette",
		"elite palette"
	};
	STRING_LIST(scenario_requisition_palette_presence, scenario_requisition_palette_presence_strings, _countof(scenario_requisition_palette_presence_strings));

	STRINGS(device_group_flags)
	{
		"can change only once"
	};
	STRING_LIST(device_group_flags, device_group_flags_strings, _countof(device_group_flags_strings));

	STRINGS(scenario_device_flags)
	{
		"initially open (1.0)",
		"initially off (0.0)",
		"can change only once",
		"position reversed",
		"not usable from any side",
		"closes without power"
	};
	STRING_LIST(scenario_device_flags, scenario_device_flags_strings, _countof(scenario_device_flags_strings));

	STRINGS(scenario_machine_flags)
	{
		"does not operate automatically",
		"one-sided",
		"never appears locked",
		"opened by melee attack",
		"one-sided for player",
		"does not close automatically",
		"ignores player",
		"ignores ai"
	};
	STRING_LIST(scenario_machine_flags, scenario_machine_flags_strings, _countof(scenario_machine_flags_strings));

	STRINGS(scenario_machine_pathfinding_policy_enum)
	{
		"default",
		"discs",
		"sectors",
		"cut-out",
		"none"
	};
	STRING_LIST(scenario_machine_pathfinding_policy_enum, scenario_machine_pathfinding_policy_enum_strings, _countof(scenario_machine_pathfinding_policy_enum_strings));

	STRINGS(scenario_control_flags)
	{
		"usable from both sides"
	};
	STRING_LIST(scenario_control_flags, scenario_control_flags_strings, _countof(scenario_control_flags_strings));

	STRINGS(scenario_control_character_types)
	{
		"any",
		"spartan",
		"elite"
	};
	STRING_LIST(scenario_control_character_types, scenario_control_character_types_strings, _countof(scenario_control_character_types_strings));

	STRINGS(ScenarioDispenserFlags)
	{
		"usable from front only"
	};
	STRING_LIST(ScenarioDispenserFlags, ScenarioDispenserFlags_strings, _countof(ScenarioDispenserFlags_strings));

	STRINGS(sound_volume_type_enumeration)
	{
		"sphere",
		"vertical cylinder",
		"pill{volume pill}"
	};
	STRING_LIST(sound_volume_type_enumeration, sound_volume_type_enumeration_strings, _countof(sound_volume_type_enumeration_strings));

} // namespace blofeld

