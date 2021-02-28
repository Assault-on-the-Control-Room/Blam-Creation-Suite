#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(object, OBJECT_TAG, object_block_block );

	V5_TAG_BLOCK(sidecarBlock, 1)
	{
		{ _field_legacy, _field_long_string, "sidecar path*" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_early_mover_obb_block, 1)
	{
		{ _field_legacy, _field_string_id, "node name#empty mean object space" },
		{ _field_legacy, _field_long_integer, "runtime node index*!" },
		{ _field_legacy, _field_real, "x0" },
		{ _field_legacy, _field_real, "x1" },
		{ _field_legacy, _field_real, "y0" },
		{ _field_legacy, _field_real, "y1" },
		{ _field_legacy, _field_real, "z0" },
		{ _field_legacy, _field_real, "z1" },
		{ _field_legacy, _field_real_euler_angles_3d, "angles" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_ai_properties_block, 1)
	{
		{ _field_legacy, _field_long_flags, "ai flags", &ai_properties_flags },
		{ _field_legacy, _field_string_id, "ai type name#used for combat dialogue, etc." },

		{ _field_legacy, _field_version_not_equal, _engine_type_halo3odst },
		{ _field_legacy, _field_string_id, "interaction name#if you checked the consider for interaction flag, type what interaction the AI should do with this object (NYI - you can use any)" },

		{ _field_legacy, _field_enum, "ai size", &ai_size_enum },
		{ _field_legacy, _field_enum, "leap jump speed", &global_ai_jump_height_enum },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_function_interpolation_block, 2)
	{
		{ _field_legacy, _field_long_enum, "interpolation mode", &object_function_interpolation_mode_enum },
		{ _field_legacy, _field_real, "linear travel time:s#used by constant velocity" },
		{ _field_legacy, _field_real, "acceleration:1/s/s#used by linear acceleration" },
		{ _field_legacy, _field_explanation, "springs", "the damping ratio is c/(2*sqrt(k)). if this ratio is:\n= 0 : oscillates forever\n< 1 : oscillates with decreasing amplitude\n= 1 : reaches the target precisely and quickly (no oscillation)\n> 1 : reaches the target slowly\nthe higher the value of k, the quicker the system will reach the target value" },
		{ _field_legacy, _field_real, "spring k#used by damped spring\ndetermines acceleration by displacement" },
		{ _field_legacy, _field_real, "spring c#used by damped spring\ndetermines damping based on velocity" },
		{ _field_legacy, _field_real, "fraction:0-1#used by fractional\nhow mush of the distance to the target to cover each update" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_function_block, k_maximum_object_functions)
	{
		{ _field_legacy, _field_long_flags, "flags", &object_function_flags },
		{ _field_legacy, _field_string_id, "import name#if you leave this field blank then you can set this function\'s input value with the hs_function object_set_function_variable" },
		{ _field_legacy, _field_string_id, "export name" },
		{ _field_legacy, _field_string_id, "turn off with#if the specified function is off, so is this function" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_string_id, "ranged interpolation name#if you have the ranged button checked" },

		{ _field_legacy, _field_real, "min value#function must exceed this value (after mapping) to be active 0. means do nothing" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "default function", &mapping_function_struct_definition },
		{ _field_legacy, _field_string_id, "scale by" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "interpolation", &object_function_interpolation_block_block },
		{ _field_legacy, _field_long_block_index, "runtime interpolator index*!" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_runtime_interpolator_functions_block, k_maximum_object_functions)
	{
		{ _field_legacy, _field_long_integer, "runtime interpolator to object function mapping*!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(objectFunctionSwitchFunctionBlock, ObjectFunctionSwitchDefinition::Function::k_maxCount)
	{
		{ _field_legacy, _field_real_bounds, "selection bounds#if the switch function is between these values, this function will be picked" },
		{ _field_legacy, _field_string_id, "function name^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(objectFunctionSwitchBlock, ObjectFunctionSwitchDefinition::k_maxCount)
	{
		{ _field_legacy, _field_string_id, "switch function name" },
		{ _field_legacy, _field_string_id, "export name" },
		{ _field_legacy, _field_block, "switched functions", &objectFunctionSwitchFunctionBlock_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(global_object_attachment_flags)
	{
		"gameplay vision mode",
		"theater vision mode"
	};
	STRING_LIST(global_object_attachment_flags, global_object_attachment_flags_strings, _countof(global_object_attachment_flags_strings));

	V5_TAG_BLOCK(global_object_attachment_block, k_maximum_number_of_attachments_per_object)
	{
		{ _field_legacy, _field_version_equal, _engine_type_halo3odst },
		{ _field_legacy, _field_long_flags, "atlas flags", &global_object_attachment_flags },

		{ _field_legacy, _field_tag_reference, "type^", &global_object_attachment_block_type_reference },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_old_string_id, "marker" },
		{ _field_legacy, _field_char_enum, "change color", &global_object_change_color_enum },
		{ _field_legacy, _field_byte_flags, "flags", &object_attachment_flags },
		{ _field_legacy, _field_pad, "DPKP", 2 },
		{ _field_legacy, _field_string_id, "primary scale" },
		{ _field_legacy, _field_string_id, "secondary scale" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_widget_block, MAXIMUM_WIDGETS_PER_OBJECT)
	{
		{ _field_legacy, _field_tag_reference, "type", &object_widget_block_type_reference },
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_change_color_initial_permutation, MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_INITIAL_PERMUTATIONS)
	{
		{ _field_legacy, _field_real, "weight" },
		{ _field_legacy, _field_real_rgb_color, "color lower bound" },
		{ _field_legacy, _field_real_rgb_color, "color upper bound" },
		{ _field_legacy, _field_string_id, "variant name#if empty, may be used by any model variant" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_change_color_function, MAXIMUM_NUMBER_OF_OBJECT_CHANGE_COLOR_FUNCTIONS)
	{
		{ _field_legacy, _field_pad, "TJJWBYNU", 4 },
		{ _field_legacy, _field_long_flags, "scale flags", &global_rgb_interpolation_flags },
		{ _field_legacy, _field_real_rgb_color, "color lower bound" },
		{ _field_legacy, _field_real_rgb_color, "color upper bound" },
		{ _field_legacy, _field_string_id, "darken by" },
		{ _field_legacy, _field_string_id, "scale by" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_change_colors, k_object_change_color_count)
	{
		{ _field_legacy, _field_useless_pad },
		{ _field_legacy, _field_block, "initial permutations", &object_change_color_initial_permutation_block },
		{ _field_legacy, _field_block, "functions", &object_change_color_function_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(multiplayer_object_block, k_maximum_multiplayer_object_blocks)
	{
		{ _field_legacy, _field_explanation, "GAME ENGINE INCLUSION", "Set which game engines you desire this object to appear in" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_word_flags, "game engine flags", &global_game_engine_type_flags },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_byte_flags, "game engine flags", &global_game_engine_type_flags },

		{ _field_legacy, _field_explanation, "TYPE AND FLAGS", "Type pertains to how you want the game engine to handle this object\nCertain flags applicable only to certain object types, should be self evident" },
		{ _field_legacy, _field_char_enum, "type", &multiplayer_object_type },
		{ _field_legacy, _field_byte_flags, "teleporter passability:used only for teleporters", &teleporter_passability_flags },

		{ _field_legacy, _field_version_less, _engine_type_haloreach },
		{ _field_legacy, _field_word_flags, "flags", &multiplayer_object_flags },

		{ _field_legacy, _field_version_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "pad_shape", 1 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_char_enum, "spawn timer type", &multiplayer_object_spawn_timer_types }, // moved after reach

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_explanation, "GOAL & RESPAWN ZONE OBJECT BOUNDARY", "These fields are only used for goal area objects with boundaries, and for respawn zones" },
		{ _field_legacy, _field_real, "boundary width/radius" },
		{ _field_legacy, _field_real, "boundary box length" },
		{ _field_legacy, _field_real, "boundary +height" },
		{ _field_legacy, _field_real, "boundary -height" },

		{ _field_legacy, _field_char_enum, "boundary shape", &multiplayer_object_boundary_shape },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_char_enum, "spawn timer type", &multiplayer_object_spawn_timer_types }, // moved after reach

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "pad_shape", 3 },

		{ _field_legacy, _field_explanation, "SPAWNING DATA", "These fields are used for default spawning times and remapping" },
		{ _field_legacy, _field_short_integer, "default spawn time:seconds" },
		{ _field_legacy, _field_short_integer, "default abandonment time:seconds" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_explanation, "GOAL & RESPAWN ZONE OBJECT BOUNDARY", "These fields are only used for goal area objects with boundaries, and for respawn zones" },
		{ _field_legacy, _field_real, "boundary width/radius" },
		{ _field_legacy, _field_real, "boundary box length" },
		{ _field_legacy, _field_real, "boundary +height" },
		{ _field_legacy, _field_real, "boundary -height" },

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_word_flags, "flags", &multiplayer_object_flags },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "pad1", 2 },

		{ _field_legacy, _field_explanation, "RESPAWN ZONE DATA", "These are respawn zone weights, used only for respawn zones" },
		{ _field_legacy, _field_real, "normal weight:aka natural weight" },

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real, "unknown weight" },
		{ _field_legacy, _field_real, "unknown weight" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "falloff function#Multiplier applied to weight (domain is center to radius, range should be 0 to 1).", &spawn_influence_weight_falloff_function_block_block },

		{ _field_legacy, _field_explanation, "MARKER DATA", "These fields are only used for defining certain, special markers to use for positional locations if the default position (object origin) is not sufficient" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "boundary center marker" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "spawned object marker name" },
		{ _field_legacy, _field_explanation, "SPAWNED OBJECT", "If this object is intended to spawn something, the object it spawns should be specified here" },
		{ _field_legacy, _field_tag_reference, "spawned object", &object_reference },
		{ _field_legacy, _field_string_id, "NYI boundary material" },
		{ _field_legacy, _field_explanation, "BOUNDARY SHADER - DEFAULT", "These are default shaders used for boundary geometry" },
		{ _field_legacy, _field_tag_reference, "boundary standard shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_tag_reference, "boundary opaque shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_explanation, "BOUNDARY SHADER - SPHERE", "These are custom shaders used for spherical boundary geometry" },
		{ _field_legacy, _field_tag_reference, "sphere standard shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_tag_reference, "sphere opaque shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_explanation, "BOUNDARY SHADER - CYLINDER", "These are custom shaders used for cylindrical boundary geometry" },
		{ _field_legacy, _field_tag_reference, "cylinder standard shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_tag_reference, "cylinder opaque shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_explanation, "BOUNDARY SHADER - BOX", "These are custom shaders used for box boundary geometry" },
		{ _field_legacy, _field_tag_reference, "box standard shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_tag_reference, "box opaque shader", &multiplayer_object_block_boundary_standard_shader_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(object_spawn_effects_block, 1)
	{
		{ _field_legacy, _field_explanation, "Spawn Effects", "Effect played when an object of this type spawns in during each game mode.\nUnlike creation effect, it is only played when the object spawns in through certain methods, not whenever one is created." },
		{ _field_legacy, _field_tag_reference, "multiplayer spawn effect#effect played when this object spawns in MP games", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "survival spawn effect#effect played when this object spawns in Firefight games", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "campaign spawn effect#effect played when this object spawns in Campaign games", &global_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(object_block, 1, object_struct_definition_struct_definition );

	V5_TAG_STRUCT(object_struct_definition)
	{
		{ _field_legacy, _field_custom, "OBJECT" },
		{ _field_legacy, _field_short_integer, "runtime object type!" },

		{ _field_legacy, _field_version_equal, {_engine_type_haloreach} },
		{ _field_legacy, _field_short_integer, "unknown@" },

		{ _field_legacy, _field_version_greater, {_engine_type_haloreach}, 4 },
		{ _field_legacy, _field_char_enum, "Nav Mesh Cutting", &NavMeshCuttingOverrideEnum },
		{ _field_legacy, _field_char_enum, "Nav Mesh Obstacle", &BooleanOverrideEnum },
		{ _field_legacy, _field_real_vector_3d, "Nav Mesh Cutting OBB Offset" },
		{ _field_legacy, _field_real_vector_3d, "Nav Mesh Cutting OBB Scale" },

		{ _field_legacy, _field_version_less, {_engine_type_haloreach} },
		{ _field_legacy, _field_word_flags, "flags", &object_definition_flags },

		{ _field_legacy, _field_version_greater_or_equal, {_engine_type_haloreach} },
		{ _field_legacy, _field_long_flags, "flags", &object_definition_flags },

		{ _field_legacy, _field_real, "bounding radius#If you edit this field manually, beware that the render model is no longer respected for radius calculation and that you need to set the bounding offset as well." },
		{ _field_legacy, _field_real_point_3d, "bounding offset" },

		{ _field_legacy, _field_version_less, {_engine_type_haloreach} },
		{ _field_legacy, _field_real, "acceleration scale:[0,+inf]" },

		{ _field_legacy, _field_version_greater_or_equal, {_engine_type_haloreach}, 3 },
		{ _field_legacy, _field_real, "horizontal acceleration scale{acceleration scale}:[0,+inf]" },
		{ _field_legacy, _field_real, "vertical acceleration scale" },
		{ _field_legacy, _field_real, "angular acceleration scale" },

		{ _field_legacy, _field_enum, "lightmap shadow mode", &lightmap_shadow_mode_enum },
		{ _field_legacy, _field_char_enum, "sweetener size", &sweetener_size_enum },
		{ _field_legacy, _field_char_enum, "water density", &water_density_type_enum },
		{ _field_legacy, _field_long_integer, "runtime flags!*" },
		{ _field_legacy, _field_real, "dynamic light sphere radius#sphere to use for dynamic lights and shadows. only used if not 0" },
		{ _field_legacy, _field_real_point_3d, "dynamic light sphere offset#only used if radius not 0" },

		{ _field_legacy, _field_version_greater_or_equal, {_engine_type_haloreach}, 3 },
		{ _field_legacy, _field_string_id, "generic hud text" },
		{ _field_legacy, _field_tag_reference, "generic name list", &global_multilingual_unicode_string_list_reference },
		{ _field_legacy, _field_tag_reference, "generic service tag list", &global_multilingual_unicode_string_list_reference },

		{ _field_legacy, _field_version_greater, {_engine_type_haloreach} },
		{ _field_legacy, _field_block, "source sidecar", &sidecarBlock_block },

		{ _field_legacy, _field_string_id, "default model variant" },
		{ _field_legacy, _field_tag_reference, "model", &model_reference$2 },
		{ _field_legacy, _field_tag_reference, "crate object", &crate_reference },
		{ _field_legacy, _field_explanation, "only set this tag if you want to override the default collision damage values in globals.globals", "" },
		{ _field_legacy, _field_tag_reference, "collision damage", &collision_damage_reference },

		{ _field_legacy, _field_version_greater_or_equal, {_engine_type_haloreach}, 1 },
		{ _field_legacy, _field_tag_reference, "brittle collision damage", &collision_damage_reference },

		{ _field_legacy, _field_block, "early mover OBB", &object_early_mover_obb_block_block },
		{ _field_legacy, _field_tag_reference, "creation effect", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "material effects", &global_material_effects_reference },
		{ _field_legacy, _field_tag_reference, "melee sound#this is the sound that is made when I am meleed.  This overrides the sweetener sound of my material.", &global_sound_reference },

		{ _field_legacy, _field_version_greater, {_engine_type_haloreach} },
		{ _field_legacy, _field_real, "self-destruct time:seconds#if non-zero, any instances of this object will destroy themselves after this many seconds." },

		{ _field_legacy, _field_block, "ai properties", &object_ai_properties_block_block },
		{ _field_legacy, _field_block, "functions", &object_function_block_block },
		
		{ _field_legacy, _field_version_greater_or_equal, {_engine_type_haloreach} },
		{ _field_legacy, _field_block, "runtime interpolator functions*!", &object_runtime_interpolator_functions_block_block },

		{ _field_legacy, _field_version_greater, {_engine_type_haloreach} },
		{ _field_legacy, _field_block, "function switches", &objectFunctionSwitchBlock_block },

		{ _field_legacy, _field_short_integer, "hud text message index" },
		{ _field_legacy, _field_word_flags, "secondary flags", &object_definition_secondary_flags },
		{ _field_legacy, _field_block, "attachments", &global_object_attachment_block_block },

		{ _field_legacy, _field_version_greater_or_equal, {_engine_type_haloreach}, 2 },
		{ _field_legacy, _field_block, "hull surfaces", &water_physics_hull_surface_definition_block_block },
		{ _field_legacy, _field_block, "jetwash", &jetwash_definition_block_block },

		{ _field_legacy, _field_block, "widgets", &object_widget_block_block },
		{ _field_legacy, _field_block, "change colors", &object_change_colors_block },
		{ _field_legacy, _field_block, "predicted resources*", &g_null_block_block },
		{ _field_legacy, _field_block, "multiplayer object", &multiplayer_object_block_block },

		{ _field_legacy, _field_version_greater_or_equal, {_engine_type_haloreach}, 2 },
		{ _field_legacy, _field_tag_reference, "simulation_interpolation#Set to a specific interpolation definition, or leave blank to inherit the default for the object type (there are defaults for bipeds, vehicles, and crates in multiplayer_globals).  To disable interpolation on a particular object whose type has interpolation by default, set this reference to the special disable_interpolation.simulation_interpolation tag.", &global_simulation_interpolation_reference },
		{ _field_legacy, _field_block, "spawn effects", &object_spawn_effects_block_block },

		{ _field_legacy, _field_version_greater, {_engine_type_haloreach}, 7 },
		{ _field_legacy, _field_block, "model dissolve data", &modelDissolveDataBlock_block },
		{ _field_legacy, _field_struct, "script data*!", &hs_script_data_struct_struct_definition },
		{ _field_legacy, _field_block, "script tagalongs", &hs_references_block_block },
		{ _field_legacy, _field_block, "scripted dependencies", &hs_references_block_block },
		{ _field_legacy, _field_explanation, "Object Abandoment", "" },
		{ _field_legacy, _field_struct, "object abandonment", &object_abandonment_struct_struct_definition },
		{ _field_legacy, _field_custom },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(object_abandonment_struct)
	{
		{ _field_legacy, _field_real, "Vitality Limit To Start Countdown" },
		{ _field_legacy, _field_real, "Countdown Time In Seconds" },
		{ _field_legacy, _field_byte_flags, "flags", &object_abandonment_flags },
		{ _field_legacy, _field_pad, "DPKP", 3 },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(water_density_type_enum)
	{
		"default",
		"super_floater",
		"floater",
		"neutral",
		"sinker",
		"super_sinker",
		"none"
	};
	STRING_LIST(water_density_type_enum, water_density_type_enum_strings, _countof(water_density_type_enum_strings));

	STRINGS(global_object_change_color_enum)
	{
		"none",
		"primary",
		"secondary",
		"tertiary",
		"quaternary"
	};
	STRING_LIST(global_object_change_color_enum, global_object_change_color_enum_strings, _countof(global_object_change_color_enum_strings));

	STRINGS(object_function_interpolation_mode_enum)
	{
		"constant velocity",
		"linear acceleration",
		"damped spring",
		"fractional#covers a fixed fraction of the distance to the target on each update"
	};
	STRING_LIST(object_function_interpolation_mode_enum, object_function_interpolation_mode_enum_strings, _countof(object_function_interpolation_mode_enum_strings));

	STRINGS(object_function_flags)
	{
		"invert#result of function is one minus actual result",
		"mapping does not controls active#the curve mapping can make the function active/inactive",
		"always active#function does not deactivate when at or below lower bound",
		"random time offset#function offsets periodic function input by random value between 0 and 1",
		"always exports value#when this function is deactivated, it still exports its value",
		"turn off with uses magnitude#the function will be turned off if the value of the turns_off_with function is 0"
	};
	STRING_LIST(object_function_flags, object_function_flags_strings, _countof(object_function_flags_strings));

	STRINGS(object_abandonment_flags)
	{
		"Enable In Multiplayer",
		"Enable In Single Player"
	};
	STRING_LIST(object_abandonment_flags, object_abandonment_flags_strings, _countof(object_abandonment_flags_strings));

	STRINGS(object_attachment_flags)
	{
		"force always on#when this flag is clear we only create the attachment when the function object function is active or set to empty string",
		"effect size scale from object scale"
	};
	STRING_LIST(object_attachment_flags, object_attachment_flags_strings, _countof(object_attachment_flags_strings));

	STRINGS(global_rgb_interpolation_flags)
	{
		"blend in hsv#blends colors in hsv rather than rgb space",
		"...more colors#blends colors through more hues (goes the long way around the color wheel)"
	};
	STRING_LIST(global_rgb_interpolation_flags, global_rgb_interpolation_flags_strings, _countof(global_rgb_interpolation_flags_strings));

	STRINGS(multiplayer_object_flags)
	{
		"only visible in editor",
		"phased physics in forge",
		"valid initial player spawn",
		"fixed boundary orientation",
		"candy monitor should ignore",
		"inherit owning team color",
		"boundary volume doesn\'t kill immediately"
	};
	STRING_LIST(multiplayer_object_flags, multiplayer_object_flags_strings, _countof(multiplayer_object_flags_strings));

	STRINGS(multiplayer_object_spawn_timer_types)
	{
		"starts on death",
		"starts on disturbance"
	};
	STRING_LIST(multiplayer_object_spawn_timer_types, multiplayer_object_spawn_timer_types_strings, _countof(multiplayer_object_spawn_timer_types_strings));

	STRINGS(teleporter_passability_flags)
	{
		"disallow players",
		"allow light land vehicles",
		"allow heavy land vehicles",
		"allow flying vehicles",
		"allow projectiles"
	};
	STRING_LIST(teleporter_passability_flags, teleporter_passability_flags_strings, _countof(teleporter_passability_flags_strings));

	STRINGS(ai_size_enum)
	{
		"default",
		"tiny",
		"small",
		"medium",
		"large",
		"huge",
		"immobile"
	};
	STRING_LIST(ai_size_enum, ai_size_enum_strings, _countof(ai_size_enum_strings));

	STRINGS(ai_properties_flags)
	{
		"detroyable cover",
		"pathfinding ignore when dead",
		"dynamic cover",
		"non flight-blocking",
		"dynamic cover from centre",
		"has corner markers!",
		"idle when flying",
		"consider for interaction"
	};
	STRING_LIST(ai_properties_flags, ai_properties_flags_strings, _countof(ai_properties_flags_strings));

	STRINGS(lightmap_shadow_mode_enum)
	{
		"default",
		"never",
		"always",
		"blur"
	};
	STRING_LIST(lightmap_shadow_mode_enum, lightmap_shadow_mode_enum_strings, _countof(lightmap_shadow_mode_enum_strings));

	STRINGS(sweetener_size_enum)
	{
		"default",
		"small",
		"medium",
		"large"
	};
	STRING_LIST(sweetener_size_enum, sweetener_size_enum_strings, _countof(sweetener_size_enum_strings));

	STRINGS(NavMeshCuttingOverrideEnum)
	{
		"Default",
		"Cut",
		"NotCut"
	};
	STRING_LIST(NavMeshCuttingOverrideEnum, NavMeshCuttingOverrideEnum_strings, _countof(NavMeshCuttingOverrideEnum_strings));

	STRINGS(BooleanOverrideEnum)
	{
		"Default",
		"Yes",
		"No"
	};
	STRING_LIST(BooleanOverrideEnum, BooleanOverrideEnum_strings, _countof(BooleanOverrideEnum_strings));

	STRINGS(object_definition_flags)
	{
		"does not cast shadow",

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 },
		"children do not cast shadow",
		"first class child",
		"object samples lightprobes only",
		"object uses only own static lightmap",

		"search cardinal direction lightmaps on failure",
		"preserves initial damage owner",
		"not a pathfinding obstacle",
		"extension of parent#object uses parent\'s markers",
		"does not cause collision damage",
		"early mover",
		"early mover localized physics",

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		"use static massive lightmap sample",

		"object scales attachments",
		"inherits player\'s appearance",

		{ _field_legacy, _field_version_less, _engine_type_haloreach, 2 },
		"dead bipeds cant localize",
		"attach to clusters by dynamic sphere",

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		"non physical in map editor",
		"object is always on the ceiling",
		"sample enviroment lighting only ignore object lighting",

		"effects created by this object do not spawn objects in multiplayer",
		"does not collide with camera#force camera not to collide with object.  By default small sweetener objects do not collide", // #TODO: test these 2 flags in h3
		"force collide with camera#force the camera to collide with this object,  By default small sweetener objects do not collide",

		{ _field_legacy, _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		"damage not blocked by obstructions#AOE damage being applied to this object does not test for obstrutions.",
		"does not damage breakable surfaces",

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 9 },
		"early mover localize projectiles",
		"requires shadow bounds visibility test",
		"grab parent object in forge editing",
		"never use imposter for shadow generation",
		"Hoistable from stand",
		"Hoistable from crouch",
		"vaultable",
		"collides with own projectiles",
		"object rejects dynamic decals"
	};
	STRING_LIST(object_definition_flags, object_definition_flags_strings, _countof(object_definition_flags_strings));

	STRINGS(object_definition_secondary_flags)
	{
		"does not affect projectile aiming",
		"update state animation and keyframe rigid bodies every frame"
	};
	STRING_LIST(object_definition_secondary_flags, object_definition_secondary_flags_strings, _countof(object_definition_secondary_flags_strings));

} // namespace blofeld

