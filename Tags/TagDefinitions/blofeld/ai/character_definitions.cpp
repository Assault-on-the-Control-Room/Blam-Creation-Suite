#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(character, CHARACTER_TAG, character_block_block );

	V5_TAG_BLOCK(character_voice_region_permutation_filter_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		{ _field_legacy, _field_string_id, "permutation name^" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_voice_region_filter_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_legacy, _field_string_id, "region name^" },
		{ _field_legacy, _field_block, "permutation filters", &character_voice_region_permutation_filter_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_voice_block, k_maximum_variants_per_model)
	{
		{ _field_legacy, _field_tag_reference, "dialogue^", &dialogue_reference$2 },
		{ _field_legacy, _field_string_id, "designator*" },
		{ _field_legacy, _field_real, "weight" },
		{ _field_legacy, _field_block, "region filters", &character_voice_region_filter_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_variants_block, k_maximum_variants_per_model)
	{
		{ _field_legacy, _field_string_id, "variant name^" },
		{ _field_legacy, _field_short_integer, "variant index*" },
		{ _field_legacy, _field_pad, "VN", 2 },
		{ _field_legacy, _field_block, "voices", &character_voice_block_block },
		{ _field_legacy, _field_string_id, "default dialogue effect id#gets applied if the vocalization has no dialogue effect id." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_voice_properties_block, c_character_voice_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_block, "voices", &character_voice_block_block },
		{ _field_legacy, _field_string_id, "default dialogue effect id#gets applied if the vocalization has no dialogue effect id." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(disallowed_weapons_for_trading_block, 32)
	{
		{ _field_legacy, _field_tag_reference, "weapon", &weapon_reference$2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_general_block, c_character_general_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "general flags", &general_flags },
		{ _field_legacy, _field_enum, "type", &actor_type_enum },
		{ _field_legacy, _field_short_integer, "rank#the rank of this character, helps us work out who in a squad should be a leader (0 is lowly, 32767 is highest)" },
		{ _field_legacy, _field_enum, "follower positioning#where should my followers try and position themselves when I am their leader\?", &combat_positioning_enum },
		{ _field_legacy, _field_pad, "post-combat-position-padding", 2 },
		{ _field_legacy, _field_real, "max leader dist#don\'t let my combat range get outside this distance from my leader when in combat (if 0 then defaults to 4wu)" },
		{ _field_legacy, _field_real, "absolute max leader dist#never select firing positions outside this range from the leader (if 0 then defaults to 8wu)" },
		{ _field_legacy, _field_real, "max player dialogue dist#never play dialogue if all players are outside of this range (if 0 then defaults to 20wu)" },
		{ _field_legacy, _field_real, "scariness#the inherent scariness of the character" },
		{ _field_legacy, _field_enum, "default grenade type", &global_ai_grenade_type_enum },
		{ _field_legacy, _field_enum, "behavior tree root", &behavior_tree_root_enum },
		{ _field_legacy, _field_block, "disallowed weapons from trading", &disallowed_weapons_for_trading_block_block },
	
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_tag_reference, "Initial Primary Weapon #Overrides initial primary weapon set in unit tag.", &weapon_reference$3 },
		{ _field_legacy, _field_tag_reference, "Initial Secondary Weapon #Overrides initial secondary weapon set in unit tag.", &weapon_reference$3 },
		{ _field_legacy, _field_tag_reference, "Initial Equipment #Fallback used if initial equipment not specified as drop item or in scenario.", &equipment_reference },
		
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_proto_spawn_block, c_character_proto_spawn_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_enum, "Proto Spawn Type #Can be used to automatically setup a character to be spawned by another character.", &proto_spawn_type_enum },
		{ _field_legacy, _field_pad, "post-proto-spawn-padding", 2 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_interact_block, c_character_interact_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "default maximum object interact range:wu" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_emotions_situational_danger_block, NUMBER_OF_PROP_CLASSES)
	{
		{ _field_legacy, _field_enum, "highest prop class^#The prop class that this block is describing", &prop_class_enum },
		{ _field_legacy, _field_pad, "obligatory pad", 2 },
		{ _field_legacy, _field_real, "situational danger#What should be the situational danger level for the prop class selected above" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_emotions_block, c_character_emotions_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_block, "situational danger", &character_emotions_situational_danger_block_block },
		{ _field_legacy, _field_real, "perceived danger increase half-life:seconds#How many seconds until it rises up to half between its current and target value" },
		{ _field_legacy, _field_real, "perceived danger decay half-life:seconds#How many seconds until it decays to half between its current and target values" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_vitality_block, c_character_vitality_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "vitality flags", &vitality_flags },
		{ _field_legacy, _field_real, "normal body vitality#maximum body vitality of our unit" },
		{ _field_legacy, _field_real, "normal shield vitality#maximum shield vitality of our unit" },
		{ _field_legacy, _field_real, "legendary body vitality#maximum body vitality of our unit (on legendary)" },
		{ _field_legacy, _field_real, "legendary shield vitality#maximum shield vitality of our unit (on legendary)" },
		{ _field_legacy, _field_real, "body recharge fraction#fraction of body health that can be regained after damage" },
		{ _field_legacy, _field_real, "soft ping threshold (with shields)#THIS IS NOW AN ABSOLUTE VALUE, NOT A FRACTION: damage necessary to trigger a soft ping when shields are up" },
		{ _field_legacy, _field_real, "soft ping threshold (no shields)#THIS IS NOW AN ABSOLUTE VALUE, NOT A FRACTION: damage necessary to trigger a soft ping when shields are down" },
		{ _field_legacy, _field_real, "hard ping threshold (with shields)# THIS IS NOW AN ABSOLUTE VALUE, NOT A FRACTION: damage necessary to trigger a hard ping when shields are up" },
		{ _field_legacy, _field_real, "hard ping threshold (no shields)#THIS IS NOW AN ABSOLUTE VALUE, NOT A FRACTION: damage necessary to trigger a hard ping when shields are down" },
		{ _field_legacy, _field_real, "hard ping cooldown time#minimum time before another hard ping can be triggered" },
		{ _field_legacy, _field_real, "body recharge delay time#amount of time delay before a shield begins to recharge" },
		{ _field_legacy, _field_real, "body recharge time#amount of time for shields to recharge completely" },
		{ _field_legacy, _field_real, "shield recharge delay time#amount of time delay before a shield begins to recharge" },
		{ _field_legacy, _field_real, "shield recharge time#amount of time for shields to recharge completely" },
		{ _field_legacy, _field_real, "extended shield damage threshold:%#Amount of shield damage sustained before it is considered \'extended\'" },
		{ _field_legacy, _field_real, "extended body damage threshold:%#Amount of body damage sustained before it is considered \'extended\'" },
		{ _field_legacy, _field_real, "suicide radius#when I die and explode, I damage stuff within this distance of me." },
		{ _field_legacy, _field_real, "runtime_body_recharge_velocity!" },
		{ _field_legacy, _field_real, "runtime_shield_recharge_velocity!" },
		{ _field_legacy, _field_tag_reference, "resurrect weapon#If I\'m being automatically resurrected then I pull out a ...", &weapon_reference$3 },
		{ _field_legacy, _field_real, "player damage_scale:[0-1]#If the player is hurting me, scale the damage by this amount. (0 value defaults to 1)" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach }, 
		{ _field_legacy, _field_real, "projectile attached detonation time scale" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_placement_block, c_character_placement_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_pad, "YJQV", 4 },
		{ _field_legacy, _field_real, "few upgrade chance (easy)" },
		{ _field_legacy, _field_real, "few upgrade chance (normal)" },
		{ _field_legacy, _field_real, "few upgrade chance (heroic)" },
		{ _field_legacy, _field_real, "few upgrade chance (legendary)" },
		{ _field_legacy, _field_real, "normal upgrade chance (easy)" },
		{ _field_legacy, _field_real, "normal upgrade chance (normal)" },
		{ _field_legacy, _field_real, "normal upgrade chance (heroic)" },
		{ _field_legacy, _field_real, "normal upgrade chance (legendary)" },
		{ _field_legacy, _field_real, "many upgrade chance (easy)" },
		{ _field_legacy, _field_real, "many upgrade chance (normal)" },
		{ _field_legacy, _field_real, "many upgrade chance (heroic)" },
		{ _field_legacy, _field_real, "many upgrade chance (legendary)" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_perception_block, c_character_perception_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_enum, "perception_mode^", &actor_perception_mode_definition },
		{ _field_legacy, _field_word_flags, "flags", &perception_flags },
		{ _field_legacy, _field_real, "maximum vision distance:world units#maximum range of sight" },
		{ _field_legacy, _field_real, "reliable vision distance:world units#reliable range of sight" },
		{ _field_legacy, _field_real, "maximum peripheral vision distance:world units#maximum range of peripheral vision" },
		{ _field_legacy, _field_real, "reliable peripheral vision distance:world units#reliable range of peripheral vision" },
		{ _field_legacy, _field_real, "minimum peripheral vision distance:world units#minimum range of peripheral vision (at peripheral vision angle)" },
		{ _field_legacy, _field_real, "minimum reliable peripheral vision distance:world units#minimum reliable range of peripheral vision (at peripheral vision angle)" },
		{ _field_legacy, _field_real, "surprise distance:world units#If a new prop is acknowledged within the given distance, surprise is registered" },
		{ _field_legacy, _field_angle, "focus interior angle:degrees#horizontal angle within which we see targets out to our maximum range" },
		{ _field_legacy, _field_angle, "focus exterior angle:degrees#horizontal angle within which we see targets at a range in between maximum and maximum peripheral" },
		{ _field_legacy, _field_angle, "peripheral vision angle:degrees#maximum horizontal angle within which we can see targets out of the corner of our eye up to maximum peripheral vision" },
		{ _field_legacy, _field_real, "hearing distance:world units#maximum range at which sounds can be heard" },
		{ _field_legacy, _field_real, "notice projectile chance:[0,1]#random chance of noticing a dangerous enemy projectile (e.g. grenade)" },
		{ _field_legacy, _field_real, "notice vehicle chance:[0,1]#random chance of noticing a dangerous vehicle" },
		{ _field_legacy, _field_real, "perception time:seconds#time required to acknowledge a visible enemy at optimal range" },
		{ _field_legacy, _field_real, "awareness glance level[0,1]#How aware of you while acknowledging an AI must be to glance at you" },
		{ _field_legacy, _field_real, "awareness glance delta#While acknowledging, the awareness delta at which an AI will glance at you" },
		{ _field_legacy, _field_real_fraction, "identify hologram chance:[0, 1]#The chance that an AI identifies a unit is actually a hologram" },
		{ _field_legacy, _field_real_bounds, "hologram ignore timer:seconds#The time after which we will ignore the hologram once seen" },
		{ _field_legacy, _field_real, "hologram ignore timer shot penalty:seconds#The number of seconds taken off of the ignore timer each time the hologram is shot" },
		{ _field_legacy, _field_real, "camouflaged enemy visible distance (normal):wu#Distance below which the AI becomes aware of you even if you are camouflaged, normal difficulty" },
		{ _field_legacy, _field_real, "camouflaged enemy visible distance (legendary):wu#Distance below which the AI becomes aware of you even if you are camouflaged, lengendary difficulty" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "mapping", &mapping_function_struct_definition },
		{ _field_legacy, _field_custom, "Normal active-camo perception" },
		{ _field_legacy, _field_struct, "normal active camo perception", &active_camo_perception_properties_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Legendary active-camo perception" },
		{ _field_legacy, _field_struct, "legendary active camo perception", &active_camo_perception_properties_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_target_block, c_character_target_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "player preference:[0-1]#How interested in the player I am on a scale of 0-1" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_look_block, c_character_look_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real_euler_angles_2d, "maximum aiming deviation:degrees#how far we can turn our weapon" },
		{ _field_legacy, _field_real_euler_angles_2d, "maximum looking deviation:degrees#how far we can turn our head" },
		{ _field_legacy, _field_real_euler_angles_2d, "runtime aiming deviation cosines!" },
		{ _field_legacy, _field_real_euler_angles_2d, "runtime looking deviation cosines!" },
		{ _field_legacy, _field_angle, "noncombat look delta L:degrees#how far we can turn our head left away from our aiming vector when not in combat" },
		{ _field_legacy, _field_angle, "noncombat look delta R:degrees#how far we can turn our head right away from our aiming vector when not in combat" },
		{ _field_legacy, _field_angle, "combat look delta L:degrees#how far we can turn our head left away from our aiming vector when in combat" },
		{ _field_legacy, _field_angle, "combat look delta R:degrees#how far we can turn our head right away from our aiming vector when in combat" },
		{ _field_legacy, _field_real_bounds, "noncombat idle looking:seconds#rate at which we change look around randomly when not in combat" },
		{ _field_legacy, _field_real_bounds, "noncombat idle aiming:seconds#rate at which we change aiming directions when looking around randomly when not in combat" },
		{ _field_legacy, _field_real_bounds, "combat idle looking:seconds#rate at which we change look around randomly when searching or in combat" },
		{ _field_legacy, _field_real_bounds, "combat idle aiming:seconds#rate at which we change aiming directions when looking around randomly when searching or in combat" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(characterHopDefinitionBlock, 1)
	{
		{ _field_legacy, _field_custom, "Default" },
		{ _field_legacy, _field_struct, "Default", &character_hop_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Passive" },
		{ _field_legacy, _field_struct, "Passive", &character_hop_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Aggressive" },
		{ _field_legacy, _field_struct, "Aggressive", &character_hop_struct_struct_definition },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_hopping_block, 1)
	{
		{ _field_legacy, _field_long_flags, "Hopping Flags", &hopping_flags },
		{ _field_legacy, _field_block, "Hopping Definition", &characterHopDefinitionBlock_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(movement_stationary_pause_block, 8)
	{
		{ _field_legacy, _field_explanation, "Inertial pause settings", "These values tell the actor to remain stationary for the specified number of ticks if he changes his direction of movement by at least \'change angle\'. Specifying an angle of 0 means pause this much every time you get to your destination." },
		{ _field_legacy, _field_angle, "direction change angle:degrees" },
		{ _field_legacy, _field_long_integer, "stationary change:ticks" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(movement_throttle_block, 16)
	{
		{ _field_legacy, _field_real, "distance:wus#If AI needs to move at greater or equal to this distance, they will move at the given throttle" },
		{ _field_legacy, _field_real, "throttle scale:[0-1]#Throttle scale between minimum and maximum throttle" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(movement_throttle_control_block, NUMBER_OF_ACTOR_COMBAT_STATUS_LEVELS)
	{
		{ _field_legacy, _field_enum, "combat status#When combat status is bigger or equal to this combat status, use the throttle settings below.", &combat_status_enum_definition },
		{ _field_legacy, _field_word_flags, "flags", &movement_throttle_control_flags },
		{ _field_legacy, _field_block, "throttle settings", &movement_throttle_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_movement_block, 1)
	{
		{ _field_legacy, _field_long_flags, "movement flags", &movement_flags },
		{ _field_legacy, _field_real, "pathfinding radius" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "avoidance radius#If 0, uses pathfinding radius." },

		{ _field_legacy, _field_real, "destination radius" },
		{ _field_legacy, _field_explanation, "Danger Zone Avoidance", "These values govern how we should avoid danger zones (like grenades and vehicles). If their sum is less than 1 then neither action will occur and instead we\'ll just try to walk out of the way with that remaining probability." },
		{ _field_legacy, _field_real, "armor lock chance#Chance the AI will use their armor lock equipment, assuming they have it" },
		{ _field_legacy, _field_real, "grenade stuck armor lock chance#Chance the AI will use their armor lock equipment if they have been stuck with a grenade, assuming they have it" },
		{ _field_legacy, _field_real, "armor lock safety duration#The number of seconds we will stay in armor lock for after danger has passed (default 1 second)" },
		{ _field_legacy, _field_real, "armor lock max duration#The longest we will stay in armor lock for regardless of danger (default 5 seconds)" },
		{ _field_legacy, _field_real, "armor lock cooldown#We won\'t go into armor lock again for this many seconds (default 0 seconds)" },
		{ _field_legacy, _field_real, "dive grenade chance" },
		{ _field_legacy, _field_real, "brace grenade chance" },
		{ _field_legacy, _field_enum, "obstacle leap min size", &obstacle_ignore_enum },
		{ _field_legacy, _field_enum, "obstacle leap max size", &obstacle_ignore_enum },
		{ _field_legacy, _field_enum, "obstacle ignore size", &obstacle_ignore_enum },
		{ _field_legacy, _field_enum, "obstacle smashable size", &obstacle_ignore_enum },
		{ _field_legacy, _field_pad, "RQEMJY", 2 },
		{ _field_legacy, _field_enum, "jump height", &global_ai_jump_height_enum },
		{ _field_legacy, _field_real, "maximum leap height:wus#.How high can a crate be for this unit to leap it." },
		{ _field_legacy, _field_real, "leap proximity fraction:[0-1]#How close to the obstacle should the actor be before leaping 1- too close, 0- as soon as he becomes aware of it" },
		{ _field_legacy, _field_real, "avoidance volume turn penalty distance:wus#The maximum distance penalty applied to an avoidance volume search path if we\'re facing away from the path. 1000 wu good for space, 5 wu good for ground." },
		{ _field_legacy, _field_long_flags, "movement hints", &movement_hint_enum },
		{ _field_legacy, _field_custom, "Throttle and inertia" },
		{ _field_legacy, _field_long_integer, "minimum movement ticks:ticks#We will move at least this long in a single direction when starting movement" },
		{ _field_legacy, _field_real, "minimum movement ticks reset angle:degrees#If the character changes movement direction by more than this angle, he will have to move for at least minimum movement ticks until he can change his mind." },
		{ _field_legacy, _field_block, "change direction pause", &movement_stationary_pause_block_block },
		{ _field_legacy, _field_real, "maximum throttle:[0-1]#The character will never throttle beyond this value" },
		{ _field_legacy, _field_real, "minimum throttle:[0-1]#The character will not throttle below this value" },
		{ _field_legacy, _field_block, "movement throttle control", &movement_throttle_control_block_block },
		{ _field_legacy, _field_real, "minimum juke throttle:[0-1]#The character will consider juking at this throttle and above" },
		{ _field_legacy, _field_angle, "minimum direction change juke angle:deg#If we change movement direction by more this angle, we will attempt a juke" },
		{ _field_legacy, _field_real, "non direction change juke probability#Probability to do a juke for a given tick, even if you are not planning to change direction (and provided you have not already performed a juke within the timeout time" },
		{ _field_legacy, _field_real, "non direction change juke timeout:seconds#After you do a change or no change of direction juke, you cannot perform a NON directional change juke for at least this many seconds. Direction change jukes will still happen" },
		{ _field_legacy, _field_long_integer, "minimum post juke movement ticks:ticks#How many ticks should the actor keep moving after a juke\? This may lower juke frequency." },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real, "stationary turn radius:[wu]#If this actor translates during turn animations, enter a radius that encloses the translation." },
		{ _field_legacy, _field_real, "localized move distance:[wu]#Distance to move as per the move_localized firing position evaluator (0 value resolves to 5wu)" },
		{ _field_legacy, _field_real_bounds, "move distance:[wu]#Distance to move as per the move_distance firing position evaluator (0 value resolves to 5wu for min, 10wu for max)" },
		{ _field_legacy, _field_real_bounds, "vehicle move distance:[wu]#Distance to move as per the vehicle_move_distance firing position evaluator (0 value resolves to 5wu for min, 10wu for max)" },
		{ _field_legacy, _field_real, "turn and run distance from target:wus#Actor will face away from his target and run to his destination if his target at a larger distance than this" },
		{ _field_legacy, _field_real, "turn and run distance to destination:wus#Firing point must be at least this distance away from the actor for him to consider turning and running to it" },
		{ _field_legacy, _field_real, "follow unit buffer distance:wus#When following a unit, such as the player, this is the additional buffer outside of the task follow radius that we are allowed to position ourselves before full firing position avoidance kicks in" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 14 },
		{ _field_legacy, _field_custom, "Phasing" },
		{ _field_legacy, _field_real, "phase chance" },
		{ _field_legacy, _field_real, "phase delay seconds#don\'t attempt again before given time since last phase" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_custom, "Movement Facing" },
		{ _field_legacy, _field_explanation, "Movement Facing", "Characters using composite animations can choose to align their facing with their aim-target or their destination. These settings control how the facing is determined." },
		{ _field_legacy, _field_real, "Departure Distance Min#min distance from departure point where facing should be aligned with aim" },
		{ _field_legacy, _field_real, "Departure Distance Range#max distance from departure point where facing should be aligned with heading" },
		{ _field_legacy, _field_real, "Arrival Distance Min#min distance from destination point where facing should be aligned with aim" },
		{ _field_legacy, _field_real, "Arrival Distance Range#max distance from destination point where facing should be aligned with heading" },
		{ _field_legacy, _field_angle, "Maximum Deviation Angle#how far we will allow the facing to deviate from the preference." },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_struct, "smooth throttle#Allows characters to be smooth throttle changes.", &SmoothThrottleStruct_struct_definition },
		{ _field_legacy, _field_struct, "smooth stopping#Allows characters to slow down smoothly when stopping.", &SmoothStoppingStruct_struct_definition },
		
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_throttle_style_block, c_character_throttle_style_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_string_id, "style name^" },
		{ _field_legacy, _field_real_fraction, "desired throttle:[0,1]" },
		{ _field_legacy, _field_real, "acceleration time:seconds" },
		{ _field_legacy, _field_struct, "acceleration function#Defines throttle as a function of time from start of style application", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_real, "deceleration distance:wu" },
		{ _field_legacy, _field_struct, "deceleration function#Defines throttle as a function of distance from the goal", &scalar_function_named_struct_struct_definition },
		{ _field_legacy, _field_string_id, "stance" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(movement_mapping_block, k_max_movement_variants)
	{
		{ _field_legacy, _field_real, "chance" },
		{ _field_legacy, _field_explanation, "MAPPING", "Movement type -> stance" },
		{ _field_legacy, _field_string_id, "idle" },
		{ _field_legacy, _field_string_id, "alert" },
		{ _field_legacy, _field_string_id, "engage" },
		{ _field_legacy, _field_string_id, "self_preserve" },
		{ _field_legacy, _field_string_id, "search" },
		{ _field_legacy, _field_string_id, "retreat" },
		{ _field_legacy, _field_string_id, "panic" },
		{ _field_legacy, _field_string_id, "flank" },
		{ _field_legacy, _field_string_id, "protected" },
		{ _field_legacy, _field_string_id, "stunned" },
		{ _field_legacy, _field_string_id, "post_combat" },
		{ _field_legacy, _field_string_id, "custom_1" },
		{ _field_legacy, _field_string_id, "custom_2" },
		{ _field_legacy, _field_string_id, "custom_3" },
		{ _field_legacy, _field_string_id, "custom_4" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_movement_set_block, k_max_movement_sets)
	{
		{ _field_legacy, _field_string_id, "name^" },
		{ _field_legacy, _field_block, "variants", &movement_mapping_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_flocking_block, c_character_flocking_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_explanation, "Jaime, don\'t touch this", "Ever." },
		{ _field_legacy, _field_real, "deceleration distance" },
		{ _field_legacy, _field_real, "normalized speed" },
		{ _field_legacy, _field_real, "buffer distance" },
		{ _field_legacy, _field_real_bounds, "throttle threshold bounds" },
		{ _field_legacy, _field_real, "deceleration stop time" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_swarm_block, c_character_swarm_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_short_integer, "scatter killed count#After the given number of deaths, the swarm scatters" },
		{ _field_legacy, _field_pad, "PEVUDXUKY", 2 },
		{ _field_legacy, _field_real, "scatter radius#the distance from the target that the swarm scatters" },
		{ _field_legacy, _field_real, "scatter time#amount of time to remain scattered" },
		{ _field_legacy, _field_real, "hound min distance" },
		{ _field_legacy, _field_real, "hound max distance" },
		{ _field_legacy, _field_real_bounds, "infection time:secs#how long the infection form and its victim will wrestle before the point of no return" },
		{ _field_legacy, _field_real, "perlin offset scale:[0-1]#amount of randomness added to creature\'s throttle" },
		{ _field_legacy, _field_real_bounds, "offset period:s#how fast the creature changes random offset to throttle" },
		{ _field_legacy, _field_real, "perlin idle movement threshold:[0-1]#a random offset lower then given threshold is made 0. (threshold of 1 = no movement)" },
		{ _field_legacy, _field_real, "perlin combat movement threshold:[0-1]#a random offset lower then given threshold is made 0. (threshold of 1 = no movement)" },
		{ _field_legacy, _field_real, "stuck time#how long we have to move (stuck distance) before we get deleted" },
		{ _field_legacy, _field_real, "stuck distance#how far we have to move in (stuck time) to not get deleted" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(evaluator_definition_block, k_fp_evaluator_count)
	{
		{ _field_legacy, _field_explanation, "EVALUATOR", "The firing point evaluation properties for a single evaluator. Treat with great care and respect." },
		{ _field_legacy, _field_long_enum, "evaluator^", &evaluator_enum },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_real, "preference weight" },
		{ _field_legacy, _field_real, "avoidance weight" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_firing_point_evaluator_block, c_character_firing_point_evaluation_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_enum, "mode^", &evaluation_modes },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_explanation, "DESIGNERS BEWARE", "If you want to screw the AI up, here\'s a great place to start. Please try not to." },
		{ _field_legacy, _field_block, "evaluators", &evaluator_definition_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_ready_block, c_character_ready_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real_bounds, "ready time bounds#Character will pause for given time before engaging threat" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_engage_block, c_character_engage_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "flags", &engage_flags },
		{ _field_legacy, _field_real_bounds, "Reposition bounds:s#How long should I remain at a firing position before moving\? (0 values will use the default values of 6 and 7 seconds)" },
		{ _field_legacy, _field_real, "Crouch danger threshold#When danger rises above the threshold, the actor crouches" },
		{ _field_legacy, _field_real, "Stand danger threshold#When danger drops below this threshold, the actor can stand again." },
		{ _field_legacy, _field_real, "Fight danger move threshold#When danger goes above given level, this actor switches firing positions" },
		{ _field_legacy, _field_short_bounds, "Fight danger move threshold cooldown:ticks#Wait at least this many ticks before relocating due to danger" },
		{ _field_legacy, _field_real, "fight flank chance:[0-1]#Chance of flanking when fighting someone who isn\'t paying attention to me" },
		{ _field_legacy, _field_tag_reference, "override grenade projectile#when I throw a grenade, forget what type I officially have: throw this type of projectile instead", &projectile_reference$2 },
		{ _field_legacy, _field_real, "minimum throw distance#Targets closer than this distance will not be attacked with a throw" },
		{ _field_legacy, _field_real, "maximum throw distance#Targets beyond this distance will not be attacked with a throw" },
		{ _field_legacy, _field_real, "throw search radius#How far does actor search for throwable items" },
		{ _field_legacy, _field_angle, "throw search angle#Angle (degrees) that the actor searches for throwable items (from his facing direction)" },
		{ _field_legacy, _field_real, "maximum throw force#Maximum throw force - it will not be used all the time" },
		{ _field_legacy, _field_real, "throw target point offset#Vertical offset from target position on ground where throw is aimed" },
		{ _field_legacy, _field_real, "throw delay min#How many seconds MUST pass until another throw is attempted" },
		{ _field_legacy, _field_real, "throw delay max#Up to how many seconds can elapse until another throw is attempted" },
		{ _field_legacy, _field_real_bounds, "default combat range:wus#If we are not holding a weapon, or we don\'t know how to use our weapon, use these bounds on my combat range" },
		{ _field_legacy, _field_real_bounds, "default firing range:wus#If we don\'t know how to use our weapon, use these bounds on my firing range" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_real_fraction, "Preferred engage fraction #0 will default to .3, other is ratio from min to max combat range preferred" },
		{ _field_legacy, _field_real, "Active Shield Fire Cutoff Delay#Number of seconds elapsed before stop firing at active shielded target." },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_charge_difficulty_limits_block, k_campaign_difficulty_levels_count)
	{
		{ _field_legacy, _field_explanation, "Difficulty Limits", "Per difficulty values to limit the number of guys in particular behaviours" },
		{ _field_legacy, _field_short_integer, "max kamikaze count#How many guys in a single clump can be kamikazing at one time" },
		{ _field_legacy, _field_short_integer, "max berserk count#How many guys in a single clump can be berserking at one time" },
		{ _field_legacy, _field_short_integer, "min berserk count#We\'d like at least this number of guys in a single clump can be berserking at one time (primarily combat forms)" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_charge_block, c_character_charge_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "Charge flags", &charge_flags },
		{ _field_legacy, _field_real, "melee consider range" },
		{ _field_legacy, _field_real, "melee chance#chance of initiating a melee within a 1 second period" },
		{ _field_legacy, _field_real, "melee attack range" },
		{ _field_legacy, _field_real, "melee abort range" },
		{ _field_legacy, _field_real, "melee attack timeout:seconds#Give up after given amount of time spent charging" },
		{ _field_legacy, _field_real, "melee attack delay timer:seconds#don\'t attempt again before given time since last melee" },
		{ _field_legacy, _field_real, "melee armor lock delay:seconds#don\'t attempt a melee on a recently armor locked target for this many seconds" },
		{ _field_legacy, _field_real_bounds, "melee leap range" },
		{ _field_legacy, _field_real, "melee leap chance" },
		{ _field_legacy, _field_real, "ideal leap velocity" },
		{ _field_legacy, _field_real, "max leap velocity" },
		{ _field_legacy, _field_real, "melee leap ballistic#min ballistic fraction" },
		{ _field_legacy, _field_real, "melee delay timer:seconds#time between melee leaps" },
		{ _field_legacy, _field_real, "melee leap prediction time#how far ahead (seconds) do we look at target for translational prediction\?" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "leader abandoned berserk chance#chance for a leader to berserk when all his followers die (actually charge, NOT berserk, but I\'m not changing the name of the variable)" },
		
		{ _field_legacy, _field_real_bounds, "shield-down berserk chance#lower bound is chance to berserk at max range, upper bound is chance to berserk at min range, requires shield depleted berserk impulse" },
		{ _field_legacy, _field_real_bounds, "shield-down berserk ranges" },
		{ _field_legacy, _field_real, "friendly killed max berserk distance:wu#The max range at which we will go berserk if we see a friendly AI of the same type (brute, etc) get killed" },
		{ _field_legacy, _field_real_fraction, "peer killed berserk chance:[0,1]#Chance that we will go berserk if we see a friendly AI of the same type (brute, etc) with the same or lower standing get killed" },
		{ _field_legacy, _field_real_fraction, "leader killed berserk chance:[0,1]#Chance that we will go berserk if we see a friendly AI of the same type (brute, etc) with higher standing get killed" },
		{ _field_legacy, _field_tag_reference, "berserk weapon#when I berserk, I pull out a ...", &weapon_reference$3 },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach }, 
		{ _field_legacy, _field_real_fraction, "Play Berserk Anim Chance When Stuck #Chance that AI will play berserk anim after getting stuck with a grenade.  Zero is 50%" },
	
		{ _field_legacy, _field_real, "Beserk cooldown:seconds#Time that I will stay in beserk after losing my target, and then revert back to normal" },
		{ _field_legacy, _field_real, "proximity berserk range:world units#If our target is closer than this distance, and not (in a vehicle/larger size than us/using a melee weapon), we will berserk. If our target is further than this distance, we will stop berserking. Set to 0 to disable proximity berserking." },
		{ _field_legacy, _field_real, "proximity berserk outside fp range:world units#We will never go more than this far outside our firing point areas when proximity-berserking. 0= no limit." },
		{ _field_legacy, _field_real_fraction, "proximity berserk chance:[0,1]#If we have a target close enough to berserk, this is the chance that we will do so. If chance fails, we will try again after timeout." },
		{ _field_legacy, _field_real, "proximity berserk timeout:seconds#We will not proximity-berserk unless it has been at least this long since we last stopped berserking. 0= no timeout." },
		{ _field_legacy, _field_real, "Broken kamikaze chance#Probability that I will run the kamikaze behaviour when my leader dies." },
		{ _field_legacy, _field_real, "Perimeter Range#How far we will melee charge outside our firing points before starting perimeter (defaults to 5wu)" },
		{ _field_legacy, _field_real, "Perimeter Range Close#How far we will melee charge outside our firing points before starting perimeter when the target is close to me (within 3wu) (defaults to 9wu)" },
		{ _field_legacy, _field_real, "Perimeter Damage Timeout:secs#How long will we take damage from our target before either seeking cover or berserking (defaults to 3secs)" },
		{ _field_legacy, _field_block, "difficulty limits", &character_charge_difficulty_limits_block_block },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 4 }, 
		{ _field_legacy, _field_real_bounds, "balling melee leap range" },
		{ _field_legacy, _field_real, "balling melee leap attack range" },
		{ _field_legacy, _field_real, "balling melee leap chance" },
		{ _field_legacy, _field_real, "balling melee attack delay timer:seconds#don\'t attempt again before given time since last melee" },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_evasion_block, c_character_evasion_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "Evasion danger threshold#Consider evading when immediate danger surpasses threshold" },
		{ _field_legacy, _field_real, "Evasion delay timer#Wait at least this delay between evasions" },
		{ _field_legacy, _field_real, "Evasion chance#If danger is above threshold, the chance that we will evade. Expressed as chance of evading within a 1 second time period" },
		{ _field_legacy, _field_real, "Evasion proximity threshold#If target is within given proximity, possibly evade" },
		{ _field_legacy, _field_real, "dive retreat chance#Chance of retreating (fleeing) after danger avoidance dive" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_cover_block, c_character_cover_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "cover flags", &cover_flags },
		{ _field_legacy, _field_real_bounds, "hide behind cover time:seconds#how long we stay behind cover after seeking cover" },
		{ _field_legacy, _field_explanation, "Hologram conditions", "The following fields dictate how hologram equipment is used by AI in cover." },
		{ _field_legacy, _field_real_bounds, "hologram cover wait time:seconds#how long we wait in cover before using the hologram" },
		{ _field_legacy, _field_real, "hologram cooldown delay:seconds#Amount of time I will wait before trying to use hologram equipment again (0 value defaults to 5 seconds)" },
		{ _field_legacy, _field_explanation, "Cover conditions", "The following fields dictate the conditions under which we will go into cover." },
		{ _field_legacy, _field_real, "Cover shield fraction#Only cover when shield falls below this level" },
		{ _field_legacy, _field_real, "Cover vitality threshold#Only cover when vitality falls below this level" },
		{ _field_legacy, _field_real, "Cover danger threshold#Danger must be this high to cover. " },
		{ _field_legacy, _field_custom, "Aggresive/Defensive cover properties" },
		{ _field_legacy, _field_real, "minimum defensive distance from target:wus#How far from the target should we switch from aggresive to defensive covering (0 always defensive, big number always offensive)" },
		{ _field_legacy, _field_real, "minimum defensive distance from cover:wus#If our cover point is less than this distance, we will never consider defensive covering" },
		{ _field_legacy, _field_real, "always defensive scary threshold#If the target has scarines bigger or equal to this, we will always cover defensively" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_explanation, "Other", "" },
		{ _field_legacy, _field_real, "Cover check delay:seconds#Amount of time I will wait before trying again after covering (0 value defaults to 2 seconds)" },
		{ _field_legacy, _field_real, "Cover pinned down check delay:seconds#Amount of time I will wait before issuing a pinned down message (0 value defaults to 2 seconds)" },
		{ _field_legacy, _field_real, "Emerge from cover when shield fraction reaches threshold#Emerge from cover when shield fraction reaches threshold" },
		{ _field_legacy, _field_real, "Proximity self-preserve:wus#Triggers self-preservation when target within this distance (assuming proximity_self_preserve_impulse is enabled)" },
		{ _field_legacy, _field_real, "proximity melee distance#When self preserving from a target less than given distance, causes melee attack (assuming proximity_melee_impulse is enabled)" },
		{ _field_legacy, _field_real, "unreachable enemy danger threshold#When danger from an unreachable enemy surpasses threshold, actor cover (assuming unreachable_enemy_cover impulse is enabled)" },
		{ _field_legacy, _field_real, "unassailable enemy danger threshold#When target is unassailable, and danger goes over this value - cover (assuming unassailable_enemy_cover impulse is enabled)" },
		{ _field_legacy, _field_real, "scary target threshold#When target is aware of me and surpasses the given scariness, self-preserve (assuming scary_target_cover_impulse is enabled)" },
		{ _field_legacy, _field_real, "Vitality fraction shield equipment{Vitality fraction bubbleshield}#Fraction of vitality below which an equipped shield equipment (instant cover/bubbleshield) will be activated (once damage has died down, and assuming shield_equipment_impulse is enabled)" },
		{ _field_legacy, _field_real, "Recent damage shield equipment#Must have less than this amount of recent body damage before we can deploy our equipped shield equipment." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_retreat_block, c_character_retreat_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "Retreat flags", &character_retreat_flags },
		{ _field_legacy, _field_real, "Shield threshold#When shield vitality drops below given amount, retreat is triggered by low_shield_retreat_impulse" },
		{ _field_legacy, _field_real, "Scary target threshold#When confronting an enemy of over the given scariness, retreat is triggered by scary_target_retreat_impulse" },
		{ _field_legacy, _field_real, "Danger threshold#When perceived danger rises above the given threshold, retreat is triggered by danger_retreat_impulse" },
		{ _field_legacy, _field_real, "Proximity threshold#When enemy closer than given threshold, retreat is triggered by proximity_retreat_impulse" },
		{ _field_legacy, _field_real_bounds, "min/max forced cower time bounds#actor cowers for at least the given amount of time" },
		{ _field_legacy, _field_real_bounds, "min/max cower timeout bounds#actor times out of cower after the given amount of time" },
		{ _field_legacy, _field_real, "proximity ambush threshold#If target reaches is within the given proximity, an ambush is triggered by the proximity ambush impulse" },
		{ _field_legacy, _field_real, "awareness ambush threshold#If target is less than threshold (0-1) aware of me, an ambush is triggered by the vulnerable enemy ambush impulse" },
		{ _field_legacy, _field_real, "leader dead retreat chance#If leader-dead-retreat-impulse is active, gives the chance that we will flee when our leader dies within 4 world units of us" },
		{ _field_legacy, _field_real, "peer dead retreat chance#If peer-dead-retreat-impulse is active, gives the chance that we will flee when one of our peers (friend of the same race) dies within 4 world units of us" },
		{ _field_legacy, _field_real, "second peer dead retreat chance#If peer-dead-retreat-impulse is active, gives the chance that we will flee when a second peer (friend of the same race) dies within 4 world units of us" },
		{ _field_legacy, _field_real, "flee timeout:seconds#Flee for no longer than this time (if there is no cover, then we will keep fleeing indefinitely). Value of 0 means \'no timeout\'" },
		{ _field_legacy, _field_angle, "zig-zag angle:degrees#The angle from the intended destination direction that a zig-zag will cause" },
		{ _field_legacy, _field_real, "zig-zag period:seconds#How long it takes to zig left and then zag right." },
		{ _field_legacy, _field_real, "retreat grenade chance#The likelihood of throwing down a grenade to cover our retreat" },
		{ _field_legacy, _field_tag_reference, "backup weapon#If I want to flee and I don\'t have flee animations with my current weapon, throw it away and try a ...", &weapon_reference$3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_search_block, c_character_search_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "Search flags", &character_search_flags },
		{ _field_legacy, _field_real_bounds, "search time" },
		{ _field_legacy, _field_real, "Search distance#Maximum distance away from our firing positions that we are happy to search (0 value will default to 3wu). Does not affect vehicle search distance (see maxd if you want that value too)." },
		{ _field_legacy, _field_explanation, "Uncover", "" },
		{ _field_legacy, _field_real_bounds, "Uncover distance bounds#Distance of uncover point from target. Hard lower limit, soft upper limit." },
		{ _field_legacy, _field_explanation, "Investigate", "Orphan offset: Offset from the orphan pos along the orphan hint vector that we will investigate to. Positive value means we are predicting where the target is going, negative value means that we would like to stand back a bit and look along the orphan vector." },
		{ _field_legacy, _field_real, "Orphan offset:wu#(0 value will default to 1.8wu)" },
		{ _field_legacy, _field_real, "Minimum offset:wu#Minimum offset from the target point to investigate, otherwise we just use the target point itself. Not entirely sure about the justification for this one..." },
		{ _field_legacy, _field_real_bounds, "vocalization time" },
		{ _field_legacy, _field_explanation, "Performances", "" },
		{ _field_legacy, _field_real, "Performance Cool-down Time#The number of seconds that must elapse before an actor will consider a search-performance again" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_presearch_block, c_character_presearch_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "Pre-search flags", &generic_flags },
		{ _field_legacy, _field_real_bounds, "max presearch time:seconds#Presearch turns off after the given time" },
		{ _field_legacy, _field_real, "max suppress time:seconds#Suppress turns off after the given time (0 defaults to 8 seconds)" },
		{ _field_legacy, _field_custom, "Child Weights" },
		{ _field_legacy, _field_real, "suppressing fire weight" },
		{ _field_legacy, _field_real, "uncover weight" },
		{ _field_legacy, _field_real, "leap on cover weight" },
		{ _field_legacy, _field_real, "destroy cover weight" },
		{ _field_legacy, _field_real, "guard weight" },
		{ _field_legacy, _field_real, "investigate weight" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_idle_block, c_character_idle_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_pad, "ZTG", 4 },
		{ _field_legacy, _field_real_bounds, "idle pose delay time:seconds#time range for delays between idle poses" },
		{ _field_legacy, _field_real_bounds, "wander delay time:seconds#time to pause at a point while wandering" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_vocalization_block, c_character_vocalization_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_explanation, "Skip Fraction", "For vocalization with priority < react, multiplies the skip fraction in the dialogue globals tag.\nFor priorities > react, multiplies the vocalization WEIGHT (i.e. the desire of that character to vocalize RELATIVE to other characters in the scene).\nThus if you hurt the arbiter, say, he\'s still going to yell at you, no matter what, and if you kill somebody and nobody else is there to witness it, he will yell at you.\nAs always, 0 means speak normally, 1 means skip everything (don\'t say shit)" },
		{ _field_legacy, _field_real, "character skip fraction:[0,1]" },
		{ _field_legacy, _field_real, "look comment time:s#How long does the player look at an AI before the AI responds\?" },
		{ _field_legacy, _field_real, "look long comment time:s#How long does the player look at the AI before he responds with his \'long look\' comment\?" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_vehicle_boarding_block, s_character_vehicle_boarding_properties::k_block_count)
	{
		{ _field_legacy, _field_tag_reference, "vehicle^", &unit_reference$2 },
		{ _field_legacy, _field_long_flags, "flags", &vehicle_boarding_flags },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_boarding_block, c_character_boarding_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "flags", &boarding_flags },
		{ _field_legacy, _field_real, "max distance:wus#maximum distance from entry point that we will consider boarding" },
		{ _field_legacy, _field_real, "abort distance:wus#give up trying to get in boarding seat if entry point is further away than this" },
		{ _field_legacy, _field_real, "max speed:wu/s#maximum speed at which we will consider boarding" },
		{ _field_legacy, _field_real, "board time:seconds#maximum time we will melee board for" },
		{ _field_legacy, _field_real_bounds, "boarding timeout:seconds#The amount of time after boarding before we\'ll consider boarding again" },
		{ _field_legacy, _field_block, "vehicle specific properties", &character_vehicle_boarding_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_kungfu_block, c_character_kungfu_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "kungfu override distance:wus#If the player is within this distance, open fire, even if your task is kungfu-fight disallowed" },
		{ _field_legacy, _field_real, "kungfu cover danger threshold#If you are kungfu disallowed and your danger is above this level, take cover" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_bunker_block, c_character_bunker_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_explanation, "DEFAULT TIMINGS", "" },
		{ _field_legacy, _field_struct, "default", &character_bunker_timings_struct_struct_definition },
		{ _field_legacy, _field_explanation, "FIGHT TIMINGS", "" },
		{ _field_legacy, _field_struct, "fight", &character_bunker_timings_struct_struct_definition },
		{ _field_legacy, _field_explanation, "COVER TIMINGS", "" },
		{ _field_legacy, _field_struct, "cover", &character_bunker_timings_struct_struct_definition },
		{ _field_legacy, _field_explanation, "GUARD TIMINGS", "" },
		{ _field_legacy, _field_struct, "guard", &character_bunker_timings_struct_struct_definition },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_guardian_block, c_character_guardian_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "surge time:seconds#length of time for which the guardian surges" },
		{ _field_legacy, _field_real, "surge delay time:seconds#minimum enforced delay between surges" },
		{ _field_legacy, _field_real, "proximity surge distance:wu#surge when our target gets closer than this to me (0 value defaults to 2wu)" },
		{ _field_legacy, _field_real, "phase time:seconds#length of time it takes the guardian to get to its phase destination" },
		{ _field_legacy, _field_real, "current position distance:wu#Minimum distance that I will consider phasing" },
		{ _field_legacy, _field_real, "target position distance:wu#Minimum distance from my target that I will phase to" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_combatform_block, c_character_combatform_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "berserk distance:wu#distance at which combatform will be forced into berserk" },
		{ _field_legacy, _field_real, "berserk chance#chance of berserking this second" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_engineer_block, c_character_engineer_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "death height:wu#try and rise this amount before dying" },
		{ _field_legacy, _field_real, "death rise time:seconds#spend this time rising" },
		{ _field_legacy, _field_real, "death detonation time:seconds#spend this time detonating" },
		{ _field_legacy, _field_real, "shield boost radius max#Boost the shields of allies within this radius during combat" },
		{ _field_legacy, _field_real, "shield boost period:seconds#Time between shield boost pings from the engineer" },
		{ _field_legacy, _field_string_id, "shield boost damage section name#The name of the damage section which will be activated by the engineer shield boost" },
		{ _field_legacy, _field_explanation, "Detonation Thresholds", "If shield vitality AND body vitality fall below the thresholds below, detonate" },
		{ _field_legacy, _field_real, "detonation shield threshold" },
		{ _field_legacy, _field_real, "detonation body vitality" },
		{ _field_legacy, _field_real, "proximity radius:wus#if target enters within this radius, either detonate or deploy equipment" },
		{ _field_legacy, _field_real, "proximity detonation chance#chance of detonating if target enters the drain radius radius" },
		{ _field_legacy, _field_tag_reference, "proximity equipment#if target enters radius and detonation is not chosen, deploy this equipment.", &equipment_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_inspect_block, c_character_inspect_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "stop distance:wu#distance from object at which to stop and turn on the inspection light" },
		{ _field_legacy, _field_real_bounds, "inspect time:seconds#time which we should inspect each object for" },
		{ _field_legacy, _field_real_bounds, "search range:wu#range in which we should search for objects to inspect" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_scarab_block, c_character_scarab_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "fighting min distance:wus#When target within this distance, the scarab will back up" },
		{ _field_legacy, _field_real, "fighting max distance:wus#When target outside this distance, the scarab will chase" },
		{ _field_legacy, _field_real_bounds, "anticipated aim radius:wus#When within these bounds distance from the target, we blend in our anticipated facing vector" },
		{ _field_legacy, _field_real, "snap forward angle:[0-1]#When moving forward within this dot of our desired facing, just move forward" },
		{ _field_legacy, _field_real, "snap forward angle max:[0-1]#When moving forward within this dot of our desired facing, just move forward" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_weapons_block, c_character_weapon_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "weapons flags", &weapon_flags },
		{ _field_legacy, _field_tag_reference, "weapon^", &weapon_reference$2 },
		{ _field_legacy, _field_explanation, "Combat ranges", "" },
		{ _field_legacy, _field_real, "maximum firing range:world units#we can only fire our weapon at targets within this distance" },
		{ _field_legacy, _field_real, "minimum firing range#weapon will not be fired at target closer than given distance" },
		{ _field_legacy, _field_real_bounds, "normal combat range:world units" },
		{ _field_legacy, _field_real, "bombardment range#we offset our burst targets randomly by this range when firing at non-visible enemies (zero = never)" },
		{ _field_legacy, _field_real, "Max special target distance:world units#Specific target regions on a vehicle or unit will be fired upon only under the given distance" },
		{ _field_legacy, _field_real, "Max extreme target distance:world units#within this distance actor will be able to do fallback engagement firing patterns. Use for extreme range engagements not otherwise permitted." },
		{ _field_legacy, _field_explanation, "Ballistic Firing", "" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "super-ballistic range#we try to aim our shots super-ballistically if target is outside this range (zero = never)" },

		{ _field_legacy, _field_real_bounds, "Ballistic firing bounds:world units#At the min range, the min ballistic fraction is used, at the max, the max ballistic fraction is used" },
		{ _field_legacy, _field_real_bounds, "Ballistic fraction bounds:[0-1]#Controls speed and degree of arc. 0 = high, slow, 1 = low, fast" },
		{ _field_legacy, _field_explanation, "Behavior", "" },
		{ _field_legacy, _field_real_bounds, "first burst delay time:seconds" },
		{ _field_legacy, _field_real, "surprise delay time:seconds" },
		{ _field_legacy, _field_real, "surprise fire-wildly time:seconds" },
		{ _field_legacy, _field_real, "death fire-wildly chance:[0,1]" },
		{ _field_legacy, _field_real, "death fire-wildly time:seconds" },
		{ _field_legacy, _field_real_vector_3d, "custom stand gun offset#custom standing gun offset for overriding the default in the base actor" },
		{ _field_legacy, _field_real_vector_3d, "custom crouch gun offset#custom crouching gun offset for overriding the default in the base actor" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "Blocked Shot Count# Number of projectiles blocked before the character is considered blocked. Zero defaults to 6." },

		{ _field_legacy, _field_explanation, "special-case firing properties", "" },
		{ _field_legacy, _field_enum, "special-fire mode#the type of special weapon fire that we can use", &actor_special_fire_mode_enum },
		{ _field_legacy, _field_enum, "special-fire situation#when we will decide to use our special weapon fire mode", &actor_special_fire_situation_enum },
		{ _field_legacy, _field_real, "special-fire chance:[0,1]#how likely we are to use our special weapon fire mode" },
		{ _field_legacy, _field_real, "special-fire delay:seconds#how long we must wait between uses of our special weapon fire mode" },
		{ _field_legacy, _field_real, "special damage modifier:[0,1]#damage modifier for special weapon fire (applied in addition to the normal damage modifier. zero = no change)" },
		{ _field_legacy, _field_angle, "special projectile error:degrees#projectile error angle for special weapon fire (applied in addition to the normal error)" },
		{ _field_legacy, _field_explanation, "Weapon drop when killed", "" },
		{ _field_legacy, _field_real_bounds, "drop weapon loaded#amount of ammo loaded into the weapon that we drop (in fractions of a clip, e.g. 0.3 to 0.5)" },
		{ _field_legacy, _field_short_bounds, "drop weapon ammo#total number of rounds in the weapon that we drop (ignored for energy weapons)" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_explanation, "Accuracy", "Parameters control how accuracy changes over the duration of a series of bursts\nAccuracy is an analog value between 0 and 1. At zero, the parameters of the first\nfiring-pattern block is used. At 1, the parameters in the second block is used. In\nbetween, all the values are linearly interpolated" },

		{ _field_legacy, _field_real_bounds, "normal accuracy bounds#Indicates starting and ending accuracies at normal difficulty" },
		{ _field_legacy, _field_real, "normal accuracy time#The amount of time it takes the accuracy to go from starting to ending" },
		{ _field_legacy, _field_real_bounds, "heroic accuracy bounds#Indicates starting and ending accuracies at heroic difficulty" },
		{ _field_legacy, _field_real, "heroic accuracy time#The amount of time it takes the accuracy to go from starting to ending" },
		{ _field_legacy, _field_real_bounds, "legendary accuracy bounds#Indicates starting and ending accuracies at legendary difficulty" },
		{ _field_legacy, _field_real, "legendary accuracy time#The amount of time it takes the accuracy to go from starting to ending" },
		{ _field_legacy, _field_tag_reference, "weapon melee damage", &damage_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_firing_pattern_block, 2+(k_num_ai_trait_weapon-2))
	{
		{ _field_legacy, _field_real, "rate of fire#how many times per second we pull the trigger (zero = continuously held down)" },
		{ _field_legacy, _field_real, "target tracking:[0,1]#how well our bursts track moving targets. 0.0= fire at the position they were standing when we started the burst. 1.0= fire at current position" },
		{ _field_legacy, _field_real, "target leading:[0,1]#how much we lead moving targets. 0.0= no prediction. 1.0= predict completely." },
		{ _field_legacy, _field_explanation, "burst geometry", "at the start of every burst we pick a random point near the target to fire at, on either the left or the right side.\nthe burst origin angle controls whether this error is exactly horizontal or might have some vertical component.\n\nover the course of the burst we move our projectiles back in the opposite direction towards the target. this return motion is also controlled by an angle that specifies how close to the horizontal it is.\n\nfor example if the burst origin angle and the burst return angle were both zero, and the return length was the same as the burst length, every burst would start the same amount away from the target (on either the left or right) and move back to exactly over the target at the end of the burst." },
		{ _field_legacy, _field_real, "burst origin radius:world units#how far away from the target the starting point is" },
		{ _field_legacy, _field_angle, "burst origin angle:degrees#the range from the horizontal that our starting error can be" },
		{ _field_legacy, _field_real_bounds, "burst return length:world units#how far the burst point moves back towards the target (could be negative)" },
		{ _field_legacy, _field_angle, "burst return angle:degrees#the range from the horizontal that the return direction can be" },
		{ _field_legacy, _field_real_bounds, "burst duration:seconds#how long each burst we fire is" },
		{ _field_legacy, _field_real_bounds, "burst separation:seconds#how long we wait between bursts" },
		{ _field_legacy, _field_real, "weapon damage modifier#what fraction of its normal damage our weapon inflicts (zero = no modifier)" },
		{ _field_legacy, _field_angle, "projectile error:degrees#error added to every projectile we fire" },
		{ _field_legacy, _field_angle, "burst angular velocity:degrees per second#the maximum rate at which we can sweep our fire (zero = unlimited)" },
		{ _field_legacy, _field_angle, "maximum error angle:degrees#cap on the maximum angle by which we will miss target (restriction on burst origin radius" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_firing_pattern_properties_block, c_character_firing_pattern_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_tag_reference, "weapon^", &weapon_reference$2 },
		{ _field_legacy, _field_block, "firing patterns", &character_firing_pattern_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_grenades_block, c_character_grenade_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "grenades flags", &grenades_flags },
		{ _field_legacy, _field_enum, "grenade type#type of grenades that we throw^", &global_grenade_type_enum },
		{ _field_legacy, _field_enum, "trajectory type#how we throw our grenades", &actor_grenade_trajectory_enum },
		{ _field_legacy, _field_pad, "YZNPI", 2 },
		{ _field_legacy, _field_short_integer, "minimum enemy count#how many enemies must be within the radius of the grenade before we will consider throwing there" },
		{ _field_legacy, _field_real, "enemy radius:world units#we consider enemies within this radius when determining where to throw" },
		{ _field_legacy, _field_real, "grenade ideal velocity:world units per second#how fast we LIKE to throw our grenades" },
		{ _field_legacy, _field_real, "grenade velocity:world units per second#the fastest we can possibly throw our grenades" },
		{ _field_legacy, _field_real_bounds, "grenade ranges:world units#ranges within which we will consider throwing a grenade" },
		{ _field_legacy, _field_real, "collateral damage radius:world units#we won\'t throw if there are friendlies around our target within this range" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real_fraction, "grenade chance:[0,1]#how likely we are to throw a grenade in one second" },

		{ _field_legacy, _field_real, "Active Shield Modifier#Throw chance multiplied by this value when target is using active shield." },
		{ _field_legacy, _field_real, "grenade throw delay:seconds#How long we have to wait after throwing a grenade before we can throw another one" },
		{ _field_legacy, _field_real_fraction, "grenade uncover chance:[0,1]#how likely we are to throw a grenade to flush out a target in one second" },
		{ _field_legacy, _field_real_fraction, "anti-vehicle grenade chance:[0,1]#how likely we are to throw a grenade against a vehicle" },
		{ _field_legacy, _field_explanation, "Grenade drop when killed", "" },
		{ _field_legacy, _field_short_bounds, "grenade count#number of grenades that we start with" },
		{ _field_legacy, _field_real, "dont drop grenades chance:[0,1]#how likely we are not to drop any grenades when we die, even if we still have some" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_vehicle_block, c_character_vehicle_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_tag_reference, "unit^", &unit_reference$2 },
		{ _field_legacy, _field_tag_reference, "style^", &style_reference },
		{ _field_legacy, _field_explanation, "Flying Avoidance", "" },
		{ _field_legacy, _field_real, "lookahead_time:seconds# How much in the future should we estimate a collision (affects collision ray length)" },
		{ _field_legacy, _field_real, "roll change magnitude:degrees#How fast to control the roll avoidance" },
		{ _field_legacy, _field_real, "roll decay multiplier:(0,1)#How fast roll goes back to 0- 1 means never, 0 means instantaneously" },
		{ _field_legacy, _field_real, "throttle grace period:seconds#How long after a collision should the vehicle keep moving at max throttle" },
		{ _field_legacy, _field_real, "minimum throttle:(-1,1)#Minimum throttle that the avoidance can slow down to" },
		{ _field_legacy, _field_real, "avoidance volume turn penalty distance:wus#The maximum distance penalty applied to an avoidance volume search path if we\'re facing away from the path. 1000 wu good for space, 5 wu good for ground." },
		{ _field_legacy, _field_explanation, "Vehicle flags", "" },
		{ _field_legacy, _field_long_flags, "vehicle flags", &vehicle_flags },
		{ _field_legacy, _field_explanation, "Hover Perturbation New", "" },
		{ _field_legacy, _field_real, "hover deceleration distance: wus#Distance defines a box outside of which we clamp perturbation. Value of zero causes fallback to run." },
		{ _field_legacy, _field_real, "hover offset distance: wus#The max radius of the XZ anchor perturbation. Value of zero causes fallback to run." },
		{ _field_legacy, _field_explanation, "Hover Perturbation Fallback", "" },
		{ _field_legacy, _field_real, "hover allow perturbation speed: wu/s#The speed the vehicle must be below for it to start running hover perturbation (default=0.4)." },
		{ _field_legacy, _field_real, "hover random x-axis period: sec#The number of seconds for the x component of the anchor perturbation to repeat itself (default=10)." },
		{ _field_legacy, _field_real, "hover random y-axis period: sec#The number of seconds for the y component of the anchor perturbation to repeat itself (default=7)." },
		{ _field_legacy, _field_real, "hover random z-axis period: sec#The number of seconds for the z component of the anchor perturbation to repeat itself (default=5)." },
		{ _field_legacy, _field_real, "hover random radius: wu#The radius of the anchor perturbation. (default=0)" },
		{ _field_legacy, _field_real, "hover anchor approach speed limit: wu/s#If we\'re traveling faster than this amount toward the anchor inside the max throttle distance, we drop throttle to the min. (default=0.2)" },
		{ _field_legacy, _field_real_bounds, "hover anchor throttle scale distance: wu#The distance from the anchor at which the min and max throttle scale occur. (default=[0.25, 2.0])" },
		{ _field_legacy, _field_real_bounds, "hover anchor xy-throttle scale: [0,1]#The xy-throttle scale at the min and max throttle scale distances. (default=[0.0, 0.2])" },
		{ _field_legacy, _field_real_bounds, "hover anchor z-throttle scale: [0,1]#The z-throttle scale at the min and max throttle scale distances. (default=[1.0, 1.0])" },
		{ _field_legacy, _field_real, "hover throttle min z: [-1, 1]#The minimum the z component of throttle is allowed to be (default=0.2)" },
		{ _field_legacy, _field_explanation, "Pathfinding", "" },
		{ _field_legacy, _field_real, "ai pathfinding radius:world units (Ground vehicles)" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "ai avoidance radius:world units (Ground vehicles)#If 0, uses pathfinding radius." },

		{ _field_legacy, _field_real, "ai destination radius:world units (All vehicles)#Distance within which goal is considered reached" },
		{ _field_legacy, _field_real, "ai deceleration distance{ai deceleration distanceworld units}:world units (All vehicles)#Distance from goal at which AI starts to decelerate" },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "roughly, the time it would take this vehicle to stop; default is 2 seconds" },

		{ _field_legacy, _field_explanation, "Turning", "" },
		{ _field_legacy, _field_real, "ai turning radius:world units (Warthog, Pelican, Ghost)#Idealized average turning radius (should reflect actual vehicle physics)" },
		{ _field_legacy, _field_real, "ai inner turning radius (< tr): (Warthogs)#Idealized minimum turning radius (should reflect actual vehicle physics)" },
		{ _field_legacy, _field_real, "ai ideal turning radius (> tr): (Warthogs, ghosts)#Ideal turning radius for rounding turns (barring obstacles, etc.)" },
		{ _field_legacy, _field_explanation, "Steering", "" },
		{ _field_legacy, _field_angle, "ai banshee steering maximum:(banshees,avoidance steering phantoms)#" },
		{ _field_legacy, _field_real, "ai max steering angle:degrees (warthogs, ghosts, wraiths)#Maximum steering angle from forward (ultimately controls turning speed)" },
		{ _field_legacy, _field_real, "ai max steering delta:degrees (warthogs, dropships, ghosts, wraiths)#Maximum delta in steering angle from one tick to the next (ultimately controls turn acceleration)" },
		{ _field_legacy, _field_real, "ai oversteering scale:(warthogs, ghosts, wraiths)" },
		{ _field_legacy, _field_angle_bounds, "ai oversteering bounds:(banshees)# Angle to goal at which AI will oversteer" },
		{ _field_legacy, _field_real, "ai sideslip distance:(ghosts, dropships)#Distance within which Ai will strafe to target (as opposed to turning)" },
		{ _field_legacy, _field_real, "ai avoidance distance:world units:(banshees)#Look-ahead distance for obstacle avoidance" },
		{ _field_legacy, _field_real, "ai min urgency:[0-1] (warthogs, banshees)#The minimum urgency with which a turn can be made (urgency = percent of maximum steering delta)" },
		{ _field_legacy, _field_angle, "destination behind angle:(dropships)#The angle from facing that is considered to be behind us (we do the ugly floaty slidey turn to things behind us)" },
		{ _field_legacy, _field_real, "skid scale:(warthogs)#When approaching a corner at speed, we may want to skid around that corner, by turning slightly too early. This is (roughly) how many seconds ahead we should start turning." },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_angle, "aiming velocity maximum:degrees per second" },
		{ _field_legacy, _field_angle, "aiming acceleration maximum:degrees per second squared" },

		{ _field_legacy, _field_explanation, "Throttle", "" },
		{ _field_legacy, _field_real, "ai throttle maximum:(0 - 1) (all vehicles)" },
		{ _field_legacy, _field_real, "ai reverse throttle maximum:(0 - 1) (ground only)#If zero, default to ai throttle maximum" },
		{ _field_legacy, _field_real, "ai goal min throttle scale: (warthogs, dropships, ghosts)#scale on throttle when within \'ai deceleration distance\' of goal (0...1)" },
		{ _field_legacy, _field_real, "ai turn min throttle scale: (warthogs, dropships, ghosts)# Scale on throttle due to nearness to a turn (0...1)" },
		{ _field_legacy, _field_real, "ai direction min throttle scale: (warthogs, dropships, ghosts)# Scale on throttle due to facing away from intended direction (0...1)" },
		{ _field_legacy, _field_real, "ai skid min throttle scale: (warthogs, dropships, ghosts)# Scale on throttle due to skidding (0...1)" },
		{ _field_legacy, _field_angle, "skid attentuation max angle#Maximise min throttle at this deviation of angles from current movement" },
		{ _field_legacy, _field_real, "ai acceleration scale:(0-1): (warthogs, ghosts)# The maximum allowable change in throttle between ticks" },
		{ _field_legacy, _field_real, "ai throttle blend:(0-1): (dropships, sentinels)# The degree of throttle blending between one tick and the next (0 = no blending)" },
		{ _field_legacy, _field_real, "theoretical max speed:wu/s (warthogs, dropships, ghosts)# About how fast I can go." },
		{ _field_legacy, _field_real, "error scale: (warthogs, dropships)# scale on the difference between desired and actual speed, applied to throttle" },
		{ _field_legacy, _field_explanation, "Combat", "" },
		{ _field_legacy, _field_angle, "ai allowable aim deviation angle" },
		{ _field_legacy, _field_explanation, "Behavior", "" },
		{ _field_legacy, _field_real, "ai charge tight angle distance: (all vehicles)# The distance at which the tight angle criterion is used for deciding to vehicle charge" },
		{ _field_legacy, _field_real, "ai charge tight angle:[0-1] (all vehicles)# Angle cosine within which the target must be when target is closer than tight angle distance in order to charge" },
		{ _field_legacy, _field_real, "ai charge repeat timeout: (all vehicles)# Time delay between vehicle charges" },
		{ _field_legacy, _field_real, "ai charge look-ahead time: (all vehicles)# In deciding when to abort vehicle charge, look ahead these many seconds to predict time of contact" },
		{ _field_legacy, _field_real, "ai charge consider distance: (all vehicles)# Consider charging the target when it is within this range (0 = infinite distance)" },
		{ _field_legacy, _field_real, "ai charge abort distance: (all vehicles)# Abort the charge when the target get more than this far away (0 = never abort)" },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_real, "ai charge abort close distance: (all vehicles)# Abort the charge when the target gets closer than this far away (0 = 3 times destination radius for historical purposes.)" },
		
		{ _field_legacy, _field_real, "ai charge armor locked target chance: [0-1] (all vehicles)#Probability that we decide to charge a target even if they are armor locked" },
		{ _field_legacy, _field_real, "vehicle ram timeout#The ram behavior stops after a maximum of the given number of seconds" },
		{ _field_legacy, _field_real, "ram paralysis time#The ram behavior freezes the vehicle for a given number of seconds after performing the ram" },
		{ _field_legacy, _field_real, "ai cover damage threshold: (all vehicles)# Trigger a cover when recent damage is above given threshold (damage_vehicle_cover impulse)" },
		{ _field_legacy, _field_real, "ai cover shield damage threshold: (all vehicles)# Trigger a cover when recent shied damage is above given threshold (flying_cover behavior)" },
		{ _field_legacy, _field_real, "ai cover min distance: (all vehicles)# When executing vehicle-cover, minimum distance from the target to flee to" },
		{ _field_legacy, _field_real, "ai cover time: (all vehicles)# How long to stay away from the target" },
		{ _field_legacy, _field_real, "ai cover min boost distance: (all vehicles)# Boosting allowed when distance to cover destination is greater then this." },
		{ _field_legacy, _field_real, "turtling recent damage threshold:%#If vehicle turtling behavior is enabled, turtling is initiated if \'recent damage\' surpasses the given threshold" },
		{ _field_legacy, _field_real, "turtling min time:seconds#If the vehicle turtling behavior is enabled, turtling occurs for at least the given time" },
		{ _field_legacy, _field_real, "turtling timeout:seconds#The turtled state times out after the given number of seconds" },
		{ _field_legacy, _field_enum, "obstacle ignore size", &obstacle_ignore_enum },
		{ _field_legacy, _field_pad, "I", 2 },
		{ _field_legacy, _field_short_integer, "max vehicle charge#max number of this type of vehicle in a task who can vehicle charge at once" },
		{ _field_legacy, _field_short_integer, "min vehicle charge#min number of this type of vehicle in a task who can vehicle charge at once (soft limit, just a desired number)" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_flying_movement_block, c_character_flying_movement_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_tag_reference, "vehicle^", &unit_reference$2 },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_explanation, "Vector Weights", "Think of this as firing point evaluation; how much do we want to weight each of the various vectors affecting our movement in space." },
		{ _field_legacy, _field_real, "facing#How much our current movement vector affects our new vector selection." },
		{ _field_legacy, _field_real, "perturbation#How much random deviation is applied to our vector selection." },
		{ _field_legacy, _field_real, "volume avoidance#How strongly we avoid our containing volume." },
		{ _field_legacy, _field_real, "volume perturbation#How strongly we are randomly perturbed by our containing volume." },
		{ _field_legacy, _field_real, "volume cover#How strongly are we attracted toward cover points." },
		{ _field_legacy, _field_real, "flocking#How much of a tendancy to flock we have." },
		{ _field_legacy, _field_real, "target#The weight of our movement towards our current target." },
		{ _field_legacy, _field_real, "target tail#The weight of our movement intended to keep our target in our tail." },
		{ _field_legacy, _field_explanation, "Area Selection", "" },
		{ _field_legacy, _field_real_bounds, "area reselect time:seconds#The time bounds on how long we should stay in an area before moving to another area." },
		{ _field_legacy, _field_explanation, "Idle", "" },
		{ _field_legacy, _field_real_bounds, "idle time:seconds#How long before reselecting a destination while idling." },
		{ _field_legacy, _field_explanation, "Cover", "" },
		{ _field_legacy, _field_real_bounds, "unsafe cover reselect time:seconds#How long after being exposed in cover before we reselect new cover." },
		{ _field_legacy, _field_real_bounds, "cover heading reselect time:seconds#The frequency at which we pick a new cover point on our current piece of cover." },
		{ _field_legacy, _field_real, "max cover search distance:wu#The farthest from ourselves that we will search for cover." },
		{ _field_legacy, _field_real, "max cover impulse distance:wu#The farthest our target can be from us when decided if we should go to cover." },
		{ _field_legacy, _field_real_bounds, "spline cooldown time:wu#The number of seconds we wait after traveling a spline to travel a spline again." },
		{ _field_legacy, _field_explanation, "Volume Avoidance", "" },
		{ _field_legacy, _field_real, "volume influence distance:wu#How far our volume influences our movement" },
		{ _field_legacy, _field_real, "volume perturbation phase:seconds#What is the frequency of oscillation of our volume perturbation vector" },
		{ _field_legacy, _field_real, "volume bounding distance:wu#How far we are allowed outside our volume before we started being forced to return (must be >= 0)" },
		{ _field_legacy, _field_explanation, "Approach", "" },
		{ _field_legacy, _field_real, "volume approach distance:wu#If our target is this close to our containing volume, then start attacking him" },
		{ _field_legacy, _field_real, "volume break off distance:wu#While attacking our target, if we get this far outside our containing volume, break off the attack and return home" },
		{ _field_legacy, _field_real, "minimum approach distance:wu#When this close to our target we will drop into the evade behaviour instead" },
		{ _field_legacy, _field_real_bounds, "collision avoidance range:wu#Zero collision avoidance at the high distance, Max avoidance at the low distance." },
		{ _field_legacy, _field_explanation, "Evasion", "" },
		{ _field_legacy, _field_real_bounds, "evade time:seconds#Bounds on how long we should evade for" },
		{ _field_legacy, _field_real_fraction, "evade body damage threshold:[0,1]#The recent body damage we should sustain before trying to evade." },
		{ _field_legacy, _field_real_fraction, "evade shield damage threshold:[0,1]#The recent shield damage we should sustain before trying to evade." },
		{ _field_legacy, _field_real, "bogey retreat time:seconds#How long we tolerate a bogey in our six, before we retreat back to our area." },
		{ _field_legacy, _field_real, "bogey retreat distance:wu#How close a bogey has to be before we\'ll even consider retreating." },
		{ _field_legacy, _field_explanation, "Flocking", "" },
		{ _field_legacy, _field_real_bounds, "flock radius:wu#Distance controls for flocking" },
		{ _field_legacy, _field_angle, "forward follow angle:degrees#How close we must be facing another friend to consider following him during flocking." },
		{ _field_legacy, _field_angle, "behind follow angle:degrees#The angle of the \'cone\' behind a friend who I am interested in following that I must be in to consider him during flocking." },
		{ _field_legacy, _field_explanation, "Tailing", "" },
		{ _field_legacy, _field_real, "min tailing time:seconds#The minimum amount of time we can be tailing" },
		{ _field_legacy, _field_real_bounds, "tailing radius:wu#Distance controls for tailing" },
		{ _field_legacy, _field_angle, "tailing cone angle:degrees#The angle of the \'cone\' behind a foe who I am interested in tailing after approaching." },
		{ _field_legacy, _field_explanation, "Strafing", "" },
		{ _field_legacy, _field_real, "volume strafe distance:wu#If our target is this close to our containing volume, then start strafing him" },
		{ _field_legacy, _field_real, "strafe min distance:wu#I need to be at least this far away from my target to consider strafing him (2D)" },
		{ _field_legacy, _field_real, "strafe above distance:wu#How high above our target we will aim for when strafing" },
		{ _field_legacy, _field_real, "strafe abort distance:wu#If I get this close to my target, stop strafing and retreat for a bit (2D)" },
		{ _field_legacy, _field_real, "strafe timeout:seconds#How long we go between strafes" },
		{ _field_legacy, _field_explanation, "Attitude Control", "" },
		{ _field_legacy, _field_angle, "max descend angle:degrees#The maximum angle at which we can descend." },
		{ _field_legacy, _field_angle, "max ascend angle:degrees#The maximum angle at which we can ascend." },
		{ _field_legacy, _field_explanation, "Shooting", "" },
		{ _field_legacy, _field_angle, "shooting cone angle:degrees#The angle of the shooting cone along the vehicle facing." },
		{ _field_legacy, _field_explanation, "Evasive Maneuvers", "" },
		{ _field_legacy, _field_real_fraction, "missile dodge change:percentage#The chance that an AI will dodge incoming missiles." },
		{ _field_legacy, _field_real, "ideal missile dodge distance:wu#The ideal distance a trick should take you away from danger." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_morph_block, c_character_morph_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_tag_reference, "ranged character", &character_reference$3 },
		{ _field_legacy, _field_tag_reference, "tank character", &character_reference$3 },
		{ _field_legacy, _field_tag_reference, "stealth character", &character_reference$3 },
		{ _field_legacy, _field_tag_reference, "morph muffins", &muffin_reference$2 },
		{ _field_legacy, _field_tag_reference, "ranged weapon", &weapon_reference$3 },
		{ _field_legacy, _field_tag_reference, "tank weapon", &weapon_reference$3 },
		{ _field_legacy, _field_tag_reference, "stealth weapon", &weapon_reference$3 },
		{ _field_legacy, _field_explanation, "Tank guy", "" },
		{ _field_legacy, _field_real, "distance damage outer radius#Considered damaging-outside-range when you START firing from outside this distance" },
		{ _field_legacy, _field_real, "distance damage inner radius#Considered damaging-outside-range when you CONTINUE firing from outside this distance" },
		{ _field_legacy, _field_real, "distance damage time#Damaging tank guy from outside-range for this long causes a morph" },
		{ _field_legacy, _field_real, "distance damage reset time#Damage timer is reset after this long of not damaging him from outside-range" },
		{ _field_legacy, _field_real_bounds, "throttle distance#Throttle the tank from running (far) to walking (near) across this range of distances. (defaults to 5 and 3)" },
		{ _field_legacy, _field_real, "protect damage amount#Once current damage reaches this amount, protect your special parts until no recent damage" },
		{ _field_legacy, _field_real, "protect time:seconds#How long should we protect our special parts for\?" },
		{ _field_legacy, _field_tag_reference, "spew infection character#What character should I throw up all over my target\? Carrots\?", &character_reference$3 },
		{ _field_legacy, _field_real, "spew chance#Probability of throwing up a bunch of infection forms when perimeterising" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "spew marker#From whence should the infection forms cometh\?" },
		{ _field_legacy, _field_real_bounds, "spew frequency:seconds#Min/max time between spawning each infection form during spew. (defaults to 0.1 and 0.3)" },
		{ _field_legacy, _field_explanation, "Stealth dude", "" },
		{ _field_legacy, _field_real, "stealth morph distance threshold#Morphing inside this range causes a tank guy, outside this range causes a ranged fella" },
		{ _field_legacy, _field_real, "stealth morph damage threshold#Percentage of body health he has to be taken down in order to cause a morph" },
		{ _field_legacy, _field_real, "stalk range min#We want to stalk our target from outside this radius" },
		{ _field_legacy, _field_real, "stalk range max#We want to stalk our target from inside this radius" },
		{ _field_legacy, _field_real, "stalk range hard max#We will never be able to pick a firing position more than this far from our target" },
		{ _field_legacy, _field_real, "stalk charge chance#While stalking, charge randomly with this probability per second (also will charge when on periphery, this is just some spice)" },
		{ _field_legacy, _field_explanation, "Ranged bloke", "" },
		{ _field_legacy, _field_real, "ranged proximity distance#Morph to tank/stalker when someone gets this close to me as a ranged form" },
		{ _field_legacy, _field_real, "turtle damage threshold#amount of damage necessary to trigger a turtle" },
		{ _field_legacy, _field_real_bounds, "turtle time#when turtling, turtle for a random time with these bounds:seconds" },
		{ _field_legacy, _field_real, "turtle distance#when I turtle I send out a stimulus to friends within this radius to also turtle:wus" },
		{ _field_legacy, _field_real, "turtle abort distance#when my target get within this range, abort turtling" },
		{ _field_legacy, _field_explanation, "General", "" },
		{ _field_legacy, _field_real, "group morph range#Follow the morph of any other form within this distance" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_equipment_usage_block, k_character_equipment_usage_when_count)
	{
		{ _field_legacy, _field_explanation, "Equipment Use", "How should I use this equipment\?" },
		{ _field_legacy, _field_enum, "use when^#When should we use this equipment\?", &character_equipment_usage_when_enum },
		{ _field_legacy, _field_enum, "use how#How should we use this equipment\?", &character_equipment_usage_how_enum },
		{ _field_legacy, _field_explanation, "Skip Fraction", "Given that we have decided to use this equipment, should we do so\? (0= always use it, 1= never use it). Heroic skip fraction is the average of normal and legendary chances." },
		{ _field_legacy, _field_real, "easy/normal:0-1#" },
		{ _field_legacy, _field_real, "legendary:0-1#" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_equipment_block, 8)
	{
		{ _field_legacy, _field_explanation, "Equipment", "Create one of these for each equipment type that you would like a character to be able to use. If you specify a relative drop chance of greater than zero then the character will use and drop this type of equipment with that (relative) chance. If you leave the equipment field empty, then there will be that (relative) chance of using and dropping no equipment at all." },
		{ _field_legacy, _field_tag_reference, "equipment#The equipment item that is to be usable", &equipment_reference },
		{ _field_legacy, _field_long_flags, "flags", &character_equipment_def_bits },
		{ _field_legacy, _field_real, "relative drop chance#The relative chance of this equipment being dropped with respect to the other pieces of equipment specified in this block" },
		{ _field_legacy, _field_block, "equipment use", &character_equipment_usage_block_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_stimuli_response_block, k_max_character_stimuli_responses)
	{
		{ _field_legacy, _field_explanation, "Stimulus Response", "Here you can define a character tag which will be applied on top of this one when the named stimulus is present on a character.In the case of multiple stimulus with character tag responses being present, the first listed will be used." },
		{ _field_legacy, _field_string_id, "stimulus name^" },
		{ _field_legacy, _field_tag_reference, "override character", &character_reference$3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_activity_object_block, 32)
	{
		{ _field_legacy, _field_string_id, "activity name" },
		{ _field_legacy, _field_tag_reference, "crate", &crate_reference$3 },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "crate marker name" },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_string_id, "unit marker name" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_pain_screen_block, c_character_pain_screen_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_explanation, "Pain Reactions", "" },
		{ _field_legacy, _field_real, "pain screen duration:seconds#The duration of the pain function\n0 defaults to 0.5" },
		{ _field_legacy, _field_real, "pain screen region fade out duration:seconds|CCBBAA#The time it takes to fade out a damage region that is no longer the most recent damage region to be hit" },
		{ _field_legacy, _field_real_fraction, "pain screen region fade out weight threshold:[0,1]#The threshold weight below which the focus channel must fall before we can cross fade to another region." },
		{ _field_legacy, _field_angle, "pain screen angle tolerance:degrees#The tolerance angle between next and previous damage directions, below which we randomly vary the ping direction." },
		{ _field_legacy, _field_angle, "pain screen angle randomness:degrees#The maximum random angle to vary the incoming ping direction by if it\'s too close to the previous ping." },
		{ _field_legacy, _field_explanation, "Defensive Reactions", "" },
		{ _field_legacy, _field_real, "defensive screen duration:seconds#The duration of the defensive function\n0 defaults to 2.0" },
		{ _field_legacy, _field_real_fraction, "defensive screen scrub fallback fraction:[0,1]#When receiving multiple pings, this is the min percentage of the defensive screen scrub value will fallback to." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_bishop_block, c_character_bishop_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_tag_reference, "junk collect effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "junk attack effect", &effect_reference },
		{ _field_legacy, _field_real_bounds, "junk attack prep time min / max (in seconds)" },
		{ _field_legacy, _field_real_bounds, "junk attack recharge time min / max (in seconds)" },
		{ _field_legacy, _field_tag_reference, "shield effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "shield crate", &crate_reference$4 },
		{ _field_legacy, _field_real_bounds, "shield lifetime min / max (in seconds)" },
		{ _field_legacy, _field_real_bounds, "shield recharge time min / max (in seconds)" },
		{ _field_legacy, _field_real, "shield range max (in world units)" },
		{ _field_legacy, _field_real, "shield offset max (in world units)#max distance of shield from shieldee" },
		{ _field_legacy, _field_real_bounds, "repair prep time min / max (in seconds)" },
		{ _field_legacy, _field_real_bounds, "repair recharge time min / max (in seconds)" },
		{ _field_legacy, _field_tag_reference, "repair beam effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "repair crate", &crate_reference$4 },
		{ _field_legacy, _field_real_bounds, "Orbit Distance #Min/Max distance that bishop will try to maintain orbit in." },
		{ _field_legacy, _field_real, "Min Follow Distance #Distance at which bishop will stop orbiting and try to catch up to allies." },
		{ _field_legacy, _field_real, "Vertical Offset #How high/low bishop will float relative to allies being protected." },
		{ _field_legacy, _field_real, "Real Line Distance #Controls how far bishop will hang back from combat." },
		{ _field_legacy, _field_real, "Follow Throttle (0 - 1) #Fraction of max throttle to use when catching up to allies." },
		{ _field_legacy, _field_real, "Orbit Throttle (0 - 1) #Fraction of max throttle to use when orbiting allies." },
		{ _field_legacy, _field_real_fraction, "Evasion Shield Level Trigger (0 - 1) #Fraction of shield level remaining required to trigger evasion." },
		{ _field_legacy, _field_real_fraction, "Evasion Body Level Trigger (0 - 1) #Fraction of body vitality remaining required to trigger evasion." },
		{ _field_legacy, _field_real, "Evasion Danger Threshold Trigger #Perceived danger required to trigger evasion." },
		{ _field_legacy, _field_real, "Resurrection Initiation Delay Time (seconds) #Time Bishop waits upon arriving at resurrection target before activating resurrection beam." },
		{ _field_legacy, _field_real, "Resurrection Charge Up Time (seconds) #Time from resurrection beam activation until actual resurrection is triggered." },
		{ _field_legacy, _field_real, "Resurrection Give Up Time (seconds) #If the resurrection target is not reached in this amount of time, the resurrection attempt is aborted." },
		{ _field_legacy, _field_tag_reference, "Resurrection Ground Effect #The effect created on the ground when resurrecting a dead ally.", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Res. Area Scan Start Effect #The effect created on the ground when scanning for a clear area before resurrection.", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Res. Area Scan Success Effect #The effect created on the ground when area scan succeeds.", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Res. Area Scan Failure Effect #The effect created on the ground when area scan fails.", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Shard Object #Created by bishop when shard spawning.  Runs spawning logic.", &crate_reference$4 },
		{ _field_legacy, _field_tag_reference, "Shard Spawn Ground Effect #The effect created on the ground when spawning shards (pawns).", &effect_reference },
		{ _field_legacy, _field_real, "Shard Creation Delay (seconds) #Time it takes for bishop to place shards after arriving at destination." },
		{ _field_legacy, _field_real_bounds, "Spawn Delay (seconds) #Min/max time it takes for shards to spawn actors." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_combotron_parent_block, c_character_combotron_parent_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_explanation, "combotron parent props", "" },
		{ _field_legacy, _field_real_bounds, "socket cooldown (seconds)#for each socket, this is the time to wait after desocketing before socketing something else into it" },
		{ _field_legacy, _field_real, "child scale#use this value to set scaling for child objects / etc..." },
		{ _field_legacy, _field_real, "shield scale#if a socketed child creates a shield for me, how big should it be\?" },
		{ _field_legacy, _field_string_id, "shield location (marker name)#when bishop is attached and shielding, where should the shield go\?" },
		{ _field_legacy, _field_tag_reference, "effect socket occupied", &effect_reference },
		{ _field_legacy, _field_tag_reference, "effect socket cooling", &effect_reference },
		{ _field_legacy, _field_tag_reference, "effect socket available", &effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_combotron_child_block, c_character_combotron_child_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_explanation, "combotron child props (anything that can socket into a rook)", "" },
		{ _field_legacy, _field_long_flags, "flags", &rook_flags },
		{ _field_legacy, _field_tag_reference, "socket weapon#When socketed, this guy turns into a weapon of the type referenced here", &weapon_reference$3 },
		{ _field_legacy, _field_tag_reference, "socket child#When socketed, this guy turns into a child of the type referenced here", &object_reference$2 },
		{ _field_legacy, _field_tag_reference, "socket character definition#Parent adopts this character definition when this guy is socketed", &character_reference$3 },
		{ _field_legacy, _field_real, "damage threshold when socketed#How much damage does this guy absorb before de-socketing" },
		{ _field_legacy, _field_real_bounds, "socketing cooldown (seconds)#After being de-socketed, wait this long before re-socketing" },
		{ _field_legacy, _field_real_bounds, "socketing attach distance (world units)#at what distance does the client particleize and attach to socket" },
		{ _field_legacy, _field_tag_reference, "effect socketing#this effect plays while a child is socketing into a parent", &effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_handle_dismemberment_block, c_character_handle_dismemberment_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_explanation, "dismemberment props", "" },
		{ _field_legacy, _field_string_id, "headshot freakout animation (animation string)" },
		{ _field_legacy, _field_string_id, "limb dismembered animation (animation string)" },
		{ _field_legacy, _field_tag_reference, "berserk persistent melee effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "alternate weapon#If I lose my firing arm then I pull out a ...", &weapon_reference$3 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_cover_fight_block, c_character_cover_fight_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real_bounds, "Cover fight min / max (in world units)#Character will prefer to use cover fighting between min/max distances" },
		{ _field_legacy, _field_real_bounds, "Wanted cover time(in seconds)#How much time do we want to spend before assessing other actions/spots." },
		{ _field_legacy, _field_real_bounds, "Wanted kneeling time(in seconds)#How long do we want to kneel." },
		{ _field_legacy, _field_real_bounds, "Wanted standing time(in seconds)#How long do we want to stand in cover." },
		{ _field_legacy, _field_real, "Realize no cover found (in seconds)#How long do we wait before we realize that no cover spot can be found." },
		{ _field_legacy, _field_real_bounds, "No cover found suppress (in seconds)#How long to disallow cover fight behavior when no cover is found." },
		{ _field_legacy, _field_real, "Fully exposed width (0-1 of bounding sphere)#How much of the character needs to be visible before cover is broken." },
		{ _field_legacy, _field_real, "Move exposed avoidance radius#How big is the area that I want to avoid when I am exposed." },
		{ _field_legacy, _field_real, "Move avoidance radius#How big is the area that I want to avoid when I move from cover to cover." },
		{ _field_legacy, _field_real, "Cover fight chance when found cover(0-1)#How often to go into cover fighting when found good cover." },
		{ _field_legacy, _field_real, "Balling chance(0-1)#How often to go into ball movement when moving from cover to cover." },
		{ _field_legacy, _field_real, "Prefer distance over flank movement(0-10)#How we rate distance vs side movement when choosing next cover spot." },
		{ _field_legacy, _field_real, "Chance of exiting cover fight when too close#Chance of exiting cover fight when too close." },
		{ _field_legacy, _field_real, "Balling interrupt damage#Damage delta when to interrupt balling." },
		{ _field_legacy, _field_string_id, "balling interrupt animation (animation string)" },
		{ _field_legacy, _field_tag_reference, "Into ball transition effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Out of ball transition effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Ball moving effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Ball interrupted effect", &effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_emerge_block, c_character_emerge_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_tag_reference, "Wall effect", &effect_reference },
		{ _field_legacy, _field_tag_reference, "Floor effect", &effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(dynamic_task_block, c_character_dynamic_task_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "Agent Filter Flags #Limits dynamic tasks that can be assigned to this AI.", &agent_filter_flags },
		{ _field_legacy, _field_long_flags, "Task Generation Flags #Controls which tasks can be generated by this AI.", &task_generation_flags },
		{ _field_legacy, _field_real_fraction, "Protect Request Shield Level #Shield vitality must be less than or equal to this level before AI will post Protect task." },
		{ _field_legacy, _field_real_fraction, "Protect Request Body Level #Body vitality must be less than or equal to this level before AI will post Protect task." },
		{ _field_legacy, _field_real_fraction, "Resurrection Req. Chance #Percent chance that actor will request to be resurrected on death." },
		{ _field_legacy, _field_real, "Shield Task Priority #Priority level of Shield task generated by this character." },
		{ _field_legacy, _field_real_bounds, "Protect Task Priorities (Min Health - Max Health) #Priority levels of Protect task as health drops." },
		{ _field_legacy, _field_real, "Resurrection Task Priority #Priority level of Resurrection task generated by this character." },
		{ _field_legacy, _field_real, "Shield During Resurrection Task Priority #Priority of the shield task generated while being resurrected." },
		{ _field_legacy, _field_tag_reference, "Shield Crate Override #Crate created to represent projected shield.", &crate_reference$4 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_advance_block, c_character_advance_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real_fraction, "Initiate Chance #Chance per second that actor will initiate an advance when able." },
		{ _field_legacy, _field_long_flags, "advance flags", &advance_flags },
		{ _field_legacy, _field_real_fraction, "Shield trigger vitality #shield level that triggers charge if charge on shields down is set." },
		{ _field_legacy, _field_real, "Max Range #Max allowed range to target for advance to trigger." },
		{ _field_legacy, _field_real, "Terminator Range #Distance at which terminator (slow advance) behavior can kick in." },
		{ _field_legacy, _field_string_id, "Terminator Throttle Style #Throttle used while terminating." },
		{ _field_legacy, _field_string_id, "Fast Charge Throttle Style #Throttle used for fast advance." },
		{ _field_legacy, _field_real, "Abort Danger Threshold #Advance will abort if danger goes above this value." },
		{ _field_legacy, _field_real, "Delay Timer #Cooldown time before advance can start again." },
		{ _field_legacy, _field_real, "Charge Range #Range at which melee charge behavior will trigger automatically during an advance." },
		{ _field_legacy, _field_real, "Minimum fast advance range #Shortest range for faster advance styles, including teleport and leap." },
		{ _field_legacy, _field_real_fraction, "Sword Flick Chance #Chance that sword flick will play at the start of advance behavior." },
		{ _field_legacy, _field_long_enum, "advance method", &character_advance_type_enum },
		{ _field_legacy, _field_real, "Teleport destination distance #How far from target to arrive" },
		{ _field_legacy, _field_real, "Teleport Sidestep distance #How far to appear to the side of teleport line for intermediate steps" },
		{ _field_legacy, _field_real, "Teleport Forward distance #How far to teleport forward for intermediate steps" },
		{ _field_legacy, _field_real, "Teleport runup time#Time between end of sword flick and first teleport" },
		{ _field_legacy, _field_real, "Teleport position time #Time spent at each teleport location" },
		{ _field_legacy, _field_real, "Teleport cooldown time #Time after attack before trying to get away" },
		{ _field_legacy, _field_real, "Teleport tracking distance #How far the landing point can move between jumps" },
		{ _field_legacy, _field_real, "Teleport tracking lockdown dist #How far from the target do we stop tracking" },
		{ _field_legacy, _field_tag_reference, "Teleport Launch FX #Effect to play at teleport launch point", &global_effect_reference },
		{ _field_legacy, _field_tag_reference, "Teleport Land FX #Effect to play at teleport destination point", &global_effect_reference },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_cover_evasion_block, c_character_cover_evasion_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "Initiate Danger Threshold #Danger level needed to trigger behavior." },
		{ _field_legacy, _field_real, "Abort Danger Threshold #Danger level that will cause behavior to be aborted." },
		{ _field_legacy, _field_real, "Cooldown #Seconds that must pass before behavior can trigger again." },
		{ _field_legacy, _field_real, "Cover Min Time #Min time character must spend in cover before stepping out." },
		{ _field_legacy, _field_real, "Fight Min Time #Min time that character must spend out of cover before stepping in." },
		{ _field_legacy, _field_real, "Step In Danger Threshold #Danger threshold that causes character to step behind cover again." },
		{ _field_legacy, _field_real, "Step In Chance #Chance per second that character will step into cover once danger threshold reached." },
		{ _field_legacy, _field_real, "Step Out Danger Threshold #Danger must be below this value before character can step out of cover." },
		{ _field_legacy, _field_real, "Step Out Chance #Chance per second that character will step out of cover." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_pack_stalk_block, c_character_pack_stalk_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "Min Wander Distance #Minimum distance pack must move when search for new cover position." },
		{ _field_legacy, _field_real, "Outside Area Border #Distance target must be from pack\'s assigned area before stalk triggers." },
		{ _field_legacy, _field_real_bounds, "Position Update Delay #Random time each member will wait before following leader." },
		{ _field_legacy, _field_real_fraction, "Throttle In Cover #Throttle used when slowing down behind cover." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_fight_circle_block, c_character_fight_circle_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real_bounds, "Strafe Time #Time spent facing the player and strafing after reaching a position." },
		{ _field_legacy, _field_real_bounds, "Extra Firing Time #Time after strafe that trigger is held down." },
		{ _field_legacy, _field_real, "Target Patience Time #Time allowed for turning back onto target at FP, not always counted against firing time." },
		{ _field_legacy, _field_angle, "Max Angle From ThreatAxis #Angle used by outside of spring evaluator, including rejector." },
		{ _field_legacy, _field_angle, "Nearby Inner Angle #Angle within which the nearby evaluator considers the point fully preferred." },
		{ _field_legacy, _field_angle, "Nearby Outer Angle #Angle outside which the nearby evaluator considers the point fully avoided." },
		{ _field_legacy, _field_string_id, "strafe throttle style #Throttle used in slow strafe mode" },
		{ _field_legacy, _field_string_id, "move throttle style #Throttle used moving to next firing point" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_hamstring_charge_block, c_character_hamstring_charge_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_angle, "Flank Angle #Angle from player facing where charge will begin." },
		{ _field_legacy, _field_real, "Flank Distance #Distance from player before dropping into charge." },
		{ _field_legacy, _field_real, "Outer Engage Distance #Close to this distance before picking target-relative flanking position." },
		{ _field_legacy, _field_real, "Hamstring Delay #Time after last hamstring or melee attack that behavior is banned." },
		{ _field_legacy, _field_real, "Initiate chance #Chance hamstring is initiated per second." },
		{ _field_legacy, _field_real, "Max Rush Time #Time to close from flank range to melee charge range." },
		{ _field_legacy, _field_real, "Melee Attack Time Min #Minimum time for terminal melee attack." },
		{ _field_legacy, _field_real, "Melee Attack Time Max #Maximum time for terminal melee attack." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_forerunner_block, c_character_forerunner_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_long_flags, "forerunner flags", &forerunner_flags },
		{ _field_legacy, _field_real, "order minion charge chance #Chance lackeys are ordered to charge when shield depleted." },
		{ _field_legacy, _field_real, "order minion charge radius #Radius within which lackeys can be ordered to charge." },
		{ _field_legacy, _field_real, "minion charge min time #min time for lackey charge." },
		{ _field_legacy, _field_real, "minion charge max time #max time for lackey charge." },
		{ _field_legacy, _field_real_bounds, "Phase To Position distance bounds #Below min, no phase. as distance moves from low to high, chance moves from low to high probabilities" },
		{ _field_legacy, _field_real_bounds, "Phase To Position Probability range #As distance moves from low to high, chance to phase moves from low to high values" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(character_gravity_jump_block, c_character_gravity_jump_properties_internal::k_block_count)
	{
		{ _field_legacy, _field_real, "Retreat Radius #Look for destination point within this distance." },
		{ _field_legacy, _field_real, "Float Time #Time spent at top of leap." },
		{ _field_legacy, _field_real, "Descend Gravity #Gravity multiplier during descent." },
		{ _field_legacy, _field_real, "Slow descend time #Time spent before full gravity returns." },
		{ _field_legacy, _field_real, "Jump Target Height #How high to attempt to jump for shot." },
		{ _field_legacy, _field_real, "Target Attractor #works as a sort of damped spring to draw the character to its landing point. Bigger is faster." },
		{ _field_legacy, _field_real, "Cooldown #Time before this character can gravjump again." },
		{ _field_legacy, _field_real, "Trigger Distance #How close your enemy has to be to trigger the jump." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(character_block, 1, character_struct_definition_struct_definition );

	V5_TAG_STRUCT(character_struct_definition)
	{
		{ _field_legacy, _field_long_flags, "Character flags", &character_flags },
		{ _field_legacy, _field_tag_reference, "parent character", &character_reference$3 },
		{ _field_legacy, _field_tag_reference, "unit", &unit_reference },
		{ _field_legacy, _field_tag_reference, "creature#Creature reference for swarm characters ONLY", &creature_reference },
		{ _field_legacy, _field_tag_reference, "style", &style_reference },
		{ _field_legacy, _field_tag_reference, "major character", &character_reference$3 },
		{ _field_legacy, _field_block, "variants", &character_variants_block_block },
		{ _field_legacy, _field_block, "voice", &character_voice_properties_block_block },
		{ _field_legacy, _field_block, "general properties", &character_general_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "proto spawn properties", &character_proto_spawn_block_block },

		{ _field_legacy, _field_block, "interact properties", &character_interact_block_block },
		{ _field_legacy, _field_block, "emotion properties", &character_emotions_block_block },
		{ _field_legacy, _field_block, "vitality properties", &character_vitality_block_block },
		{ _field_legacy, _field_block, "placement properties", &character_placement_block_block },
		{ _field_legacy, _field_block, "perception properties", &character_perception_block_block },
		{ _field_legacy, _field_block, "target properties", &character_target_block_block },
		{ _field_legacy, _field_block, "look properties", &character_look_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "hopping properties", &character_hopping_block_block },

		{ _field_legacy, _field_block, "movement properties", &character_movement_block_block },
		{ _field_legacy, _field_block, "throttle styles", &character_throttle_style_block_block },
		{ _field_legacy, _field_block, "movement sets", &character_movement_set_block_block },
		{ _field_legacy, _field_block, "flocking properties", &character_flocking_block_block },
		{ _field_legacy, _field_block, "swarm properties", &character_swarm_block_block },
		{ _field_legacy, _field_block, "firing point evaluator properties", &character_firing_point_evaluator_block_block },
		{ _field_legacy, _field_block, "ready properties", &character_ready_block_block },
		{ _field_legacy, _field_block, "engage properties", &character_engage_block_block },
		{ _field_legacy, _field_block, "charge properties", &character_charge_block_block },
		{ _field_legacy, _field_explanation, "Danger Values", "Danger values can be found in the ai-globals section of the globals tag." },
		{ _field_legacy, _field_block, "evasion properties", &character_evasion_block_block },
		{ _field_legacy, _field_block, "cover properties", &character_cover_block_block },
		{ _field_legacy, _field_block, "retreat properties", &character_retreat_block_block },
		{ _field_legacy, _field_block, "search properties", &character_search_block_block },
		{ _field_legacy, _field_block, "pre-search properties", &character_presearch_block_block },
		{ _field_legacy, _field_block, "idle properties", &character_idle_block_block },
		{ _field_legacy, _field_block, "vocalization properties", &character_vocalization_block_block },
		{ _field_legacy, _field_block, "boarding properties", &character_boarding_block_block },
		{ _field_legacy, _field_block, "kungfu properties", &character_kungfu_block_block },
		{ _field_legacy, _field_block, "bunker properties", &character_bunker_block_block },
		{ _field_legacy, _field_block, "guardian properties", &character_guardian_block_block },
		{ _field_legacy, _field_block, "combatform properties", &character_combatform_block_block },
		{ _field_legacy, _field_block, "engineer properties", &character_engineer_block_block },
		{ _field_legacy, _field_block, "inspect properties", &character_inspect_block_block },
		{ _field_legacy, _field_block, "scarab properties", &character_scarab_block_block },
		{ _field_legacy, _field_block, "weapons properties", &character_weapons_block_block },
		{ _field_legacy, _field_block, "firing pattern properties", &character_firing_pattern_properties_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_legacy, _field_block, "extreme range firing pattern properties", &character_firing_pattern_properties_block_block },

		{ _field_legacy, _field_block, "grenades properties", &character_grenades_block_block },
		{ _field_legacy, _field_block, "vehicle properties", &character_vehicle_block_block },
		{ _field_legacy, _field_block, "flying movement properties", &character_flying_movement_block_block },
		{ _field_legacy, _field_block, "morph properties", &character_morph_block_block },
		{ _field_legacy, _field_block, "equipment definitions", &character_equipment_block_block },
		{ _field_legacy, _field_block, "stimuli responses", &character_stimuli_response_block_block },
		{ _field_legacy, _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block_block },
		{ _field_legacy, _field_block, "activity objects", &character_activity_object_block_block },
		{ _field_legacy, _field_block, "pain screen properties", &character_pain_screen_block_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 14 },
		{ _field_legacy, _field_block, "bishop properties", &character_bishop_block_block },
		{ _field_legacy, _field_block, "combotron parent properties", &character_combotron_parent_block_block },
		{ _field_legacy, _field_block, "combotron child properties", &character_combotron_child_block_block },
		{ _field_legacy, _field_block, "handle dismemberment properties", &character_handle_dismemberment_block_block },
		{ _field_legacy, _field_block, "Fight From Cover", &character_cover_fight_block_block },
		{ _field_legacy, _field_block, "Emerge", &character_emerge_block_block },
		{ _field_legacy, _field_block, "Dynamic Task", &dynamic_task_block_block },
		{ _field_legacy, _field_block, "Advance Properties", &character_advance_block_block },
		{ _field_legacy, _field_block, "Cover Evasion", &character_cover_evasion_block_block },
		{ _field_legacy, _field_block, "Pack Stalk", &character_pack_stalk_block_block },
		{ _field_legacy, _field_block, "Fight Circle", &character_fight_circle_block_block },
		{ _field_legacy, _field_block, "Hamstring", &character_hamstring_charge_block_block },
		{ _field_legacy, _field_block, "Forerunner", &character_forerunner_block_block },
		{ _field_legacy, _field_block, "Gravity Jump", &character_gravity_jump_block_block },

		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(active_camo_perception_properties)
	{
		{ _field_legacy, _field_real_fraction, "partial invis amount:[0,1]#this amount of active camouflage makes a target \'partially invisible\'" },
		{ _field_legacy, _field_real, "partial invis vision distance:world units#maximum vision distance for partially invisible targets. 0= unlimited" },
		{ _field_legacy, _field_real, "partial invis awareness multiplier:[0,1]#multiplier on our awareness speed for partially invisible targets. 0= no change. Should be in (0, 1]." },
		{ _field_legacy, _field_real_fraction, "full invis amount:[0,1]#this amount of active camouflage makes a target \'fully invisible\'" },
		{ _field_legacy, _field_real, "full invis vision distance:world units#maximum vision distance for fully invisible targets. 0= unlimited" },
		{ _field_legacy, _field_real, "full invis awareness multiplier:[0,1]#multiplier on our awareness speed for fully invisible targets. 0= no change. Should be in (0, 1]." },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(character_hop_struct)
	{
		{ _field_legacy, _field_real, "Min hop distance#Pathing shorter than this, no hopping" },
		{ _field_legacy, _field_real, "Min hop distance to path end#Pathing shorter than this, no hopping to end of path" },
		{ _field_legacy, _field_real_bounds, "Hop wait timer min/max#Character will wait this random ranged timer before hopping again.(Seconds)" },
		{ _field_legacy, _field_real, "Max hop distance#Pathing longer than this, no hopping." },
		{ _field_legacy, _field_real, "pad!" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(SmoothThrottleStruct)
	{
		{ _field_legacy, _field_custom, "Smooth Throttle" },
		{ _field_legacy, _field_enum, "settings options", &character_smooth_movement_settings_options },
		{ _field_legacy, _field_explanation, "Override Settings", "The following setting are applied when the Override option is chosen" },
		{ _field_legacy, _field_pad, "csts_pad_2", 2 },
		{ _field_legacy, _field_real, "Starting Rate:(0.0 to 1.0)#interpolation weight used for the first frame of movement from a stopped position." },
		{ _field_legacy, _field_real, "Stopping Rate:(0.0 to 1.0)#interpolation weight used for transitioning to a zero (stopped) throttle." },
		{ _field_legacy, _field_real, "Max Linear Acceleration:throttle units per tick#maximum linear acceleration limit for throttle magnitude during regular movement." },
		{ _field_legacy, _field_real, "Max Linear Deceleration:throttle units per tick#maximum linear deceleration limit for throttle magnitude during regular movement." },
		{ _field_legacy, _field_angle, "Max Angular Acceleration:degrees per tick#maximum angular acceleration/deceleration limit for throttle changes." },
		{ _field_legacy, _field_real, "Max Reversal Linear Acceleration:throttle units per tick#maximum linear Accel/Decel limit for throttle magnitude when reversing direction." },
		{ _field_legacy, _field_angle, "Max Reversal Angular Acceleration:degrees per tick#maximum angular Accel/Decel limit for throttle heading when reversing direction." },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(SmoothStoppingStruct)
	{
		{ _field_legacy, _field_custom, "Smooth Stopping" },
		{ _field_legacy, _field_enum, "settings options", &character_smooth_movement_settings_options },
		{ _field_legacy, _field_explanation, "Override Settings", "The following setting are applied when the Override option is chosen" },
		{ _field_legacy, _field_pad, "csst_pad_2", 2 },
		{ _field_legacy, _field_real_bounds, "Stopping Distance:[wu]#Distance at which to begin slowing to a stop. Range provides variance." },
		{ _field_legacy, _field_real_bounds, "Arrival Throttle:range (0.05, 1.0)#Throttle magnitude desired upon arrival. Should be non zero, and greater than 0.1 to avoid super-slow stops" },
		{ _field_legacy, _field_real_bounds, "Stopping Power:exponent#Power value used to determine stopping curve. Values <1 produce sharper stops, >1 produce more ease-in." },
		{ _field_legacy, _field_real_bounds, "Idle Time:exponent#seconds to idle when stopped." },
		{ _field_legacy, _field_custom },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_STRUCT(character_bunker_timings_struct)
	{
		{ _field_legacy, _field_real_bounds, "open time:seconds#How long we should open for" },
		{ _field_legacy, _field_real, "closed min time:seconds#How long we must stay closed for before opening or peeking again" },
		{ _field_legacy, _field_real, "close danger level#Force close at this danger level" },
		{ _field_legacy, _field_real, "open chance:chance per second#What chance we have of opening per second" },
		{ _field_legacy, _field_real, "peek chance:chance per second#What chance we have of peeking per second" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(generic_flags)
	{
		"Flag1"
	};
	STRING_LIST(generic_flags, generic_flags_strings, _countof(generic_flags_strings));

	STRINGS(actor_type_enum)
	{
		"none",
		"player",
		"marine",
		"crew",
		"spartan",
		"elite",
		"jackal",
		"grunt",
		"brute",
		"hunter",
		"prophet",
		"bugger",
		"scarab",
		"engineer",
		"skirmisher",
		"bishop",
		"knight",
		"pawn",
		"rook",
		"mule",
		"mounted_weapon",
		"octopus"
	};
	STRING_LIST(actor_type_enum, actor_type_enum_strings, _countof(actor_type_enum_strings));

	STRINGS(global_ai_grenade_type_enum)
	{
		"NONE",
		"Human grenade",
		"Covenant Plasma",
		"Brute claymore",
		"Firebomb"
	};
	STRING_LIST(global_ai_grenade_type_enum, global_ai_grenade_type_enum_strings, _countof(global_ai_grenade_type_enum_strings));

	STRINGS(behavior_tree_root_enum)
	{
		"Default",
		"Scarab",
		"Flying"
	};
	STRING_LIST(behavior_tree_root_enum, behavior_tree_root_enum_strings, _countof(behavior_tree_root_enum_strings));

	STRINGS(general_flags)
	{
		"swarm",
		"flying",
		"dual wields",
		"uses gravemind",
		"gravemind chorus",
		"don\'t trade weapon",
		"don\'t stow weapon",
		"hero character",
		"leader independent positioning",
		"has active camo",
		"use head marker for looking",
		"space character",
		"do not drop equipment",
		"do not allow crouch",
		"do not allow moving crouch",
		"critical betrayal",
		"deathless critical betrayal"
	};
	STRING_LIST(general_flags, general_flags_strings, _countof(general_flags_strings));

	STRINGS(combat_positioning_enum)
	{
		"In front of me",
		"Behind me",
		"Tight"
	};
	STRING_LIST(combat_positioning_enum, combat_positioning_enum_strings, _countof(combat_positioning_enum_strings));

	STRINGS(proto_spawn_type_enum)
	{
		"None",
		"Limbo",
		"Spawner",
		"Birther"
	};
	STRING_LIST(proto_spawn_type_enum, proto_spawn_type_enum_strings, _countof(proto_spawn_type_enum_strings));

	STRINGS(prop_class_enum)
	{
		"none - actor has no targets whatsoever",
		"dead enemy- my only target is a dead enemy",
		"non-attacking enemy- I am debilitated and the enemy is not attacking me",
		"disregarded orphan- did not find my target and gave up searching",
		"inspected orphan- checked last know position and didn\'t find target; still searching",
		"uninspected orphan- can\'t see target, but have a good idea where they may be",
		"certain orphan- can\'t see target, but know exactly where they are",
		"visible enemy- I can see the target",
		"nearby enemy- I can see the target, and it\'s close",
		"potentially dangerous enemy- target is near and is facing me",
		"dangerous enemy- target is facing my way and fighting",
		"attacking enemy- target is aiming at me and shooting me",
		"very close enemy- enemy is really close",
		"damaging_enemy- enemy is damaging me"
	};
	STRING_LIST(prop_class_enum, prop_class_enum_strings, _countof(prop_class_enum_strings));

	STRINGS(vitality_flags)
	{
		"auto resurrect"
	};
	STRING_LIST(vitality_flags, vitality_flags_strings, _countof(vitality_flags_strings));

	STRINGS(perception_flags)
	{
		"character can see in darkness",
		"ignore tracking projectiles",
		"ignore minor tracking projectiles"
	};
	STRING_LIST(perception_flags, perception_flags_strings, _countof(perception_flags_strings));

	STRINGS(actor_perception_mode_definition)
	{
		"idle",
		"alert",
		"combat",
		"search",
		"patrol",
		"vehicle idle",
		"vehicle alert",
		"vehicle combat "
	};
	STRING_LIST(actor_perception_mode_definition, actor_perception_mode_definition_strings, _countof(actor_perception_mode_definition_strings));

	STRINGS(hopping_flags)
	{
		"to cover path segements",
		"to end of path",
		"forward only"
	};
	STRING_LIST(hopping_flags, hopping_flags_strings, _countof(hopping_flags_strings));

	STRINGS(movement_flags)
	{
		"danger crouch allow movement",
		"no side-step",
		"prefer to combar near friends",
		"allow boosted jump",
		"perch",
		"climb",
		"prefer wall movement",
		"has flying mode",
		"disallow crouch",
		"disallow all movement",
		"always use search points",
		"keep moving",
		"cure isolation jump",
		"gain elevation",
		"reposition distant",
		"only use aerial firing positions",
		"use high priority pathfinding",
		"lower weapon when no alert movement override",
		"phase",
		"no override when firing",
		"no stow during idle activities",
		"flip any vehicle"
	};
	STRING_LIST(movement_flags, movement_flags_strings, _countof(movement_flags_strings));

	STRINGS(obstacle_ignore_enum)
	{
		"none",
		"tiny",
		"small",
		"medium",
		"large",
		"huge",
		"immobile"
	};
	STRING_LIST(obstacle_ignore_enum, obstacle_ignore_enum_strings, _countof(obstacle_ignore_enum_strings));

	STRINGS(movement_hint_enum)
	{
		"vault step",
		"vault crouch",
		"unused0!",
		"unused1!",
		"unused2!",
		"mount step",
		"mount crouch",
		"mount stand",
		"unused3!",
		"unused4!",
		"unused5!",
		"hoist crouch",
		"hoist stand",
		"unused6!",
		"unused7!",
		"unused8!"
	};
	STRING_LIST(movement_hint_enum, movement_hint_enum_strings, _countof(movement_hint_enum_strings));

	STRINGS(global_ai_jump_height_enum)
	{
		"NONE",
		"down",
		"step",
		"crouch",
		"stand",
		"storey",
		"tower",
		"infinite"
	};
	STRING_LIST(global_ai_jump_height_enum, global_ai_jump_height_enum_strings, _countof(global_ai_jump_height_enum_strings));

	STRINGS(combat_status_enum_definition)
	{
		"asleep",
		"idle",
		"alert",
		"active",
		"uninspected orphan",
		"definite orphan",
		"certain orphan",
		"visible enemy",
		"clear enemy los",
		"dangerous enemy"
	};
	STRING_LIST(combat_status_enum_definition, combat_status_enum_definition_strings, _countof(combat_status_enum_definition_strings));

	STRINGS(movement_throttle_control_flags)
	{
		"resample distance every tick"
	};
	STRING_LIST(movement_throttle_control_flags, movement_throttle_control_flags_strings, _countof(movement_throttle_control_flags_strings));

	STRINGS(character_smooth_movement_settings_options)
	{
		"Use Engine Default Settings",
		"Use Override Settings Below",
		"Disable"
	};
	STRING_LIST(character_smooth_movement_settings_options, character_smooth_movement_settings_options_strings, _countof(character_smooth_movement_settings_options_strings));

	STRINGS(evaluator_enum)
	{
		"INVALID&INVALID (pre)",
		"attack_avoid_overhead&attack_avoid_overhead (pre)",
		"attack_dangerousenemy&attack_dangerousenemy (pre)",
		"attack_idealrange&attack_idealrange (pre)",
		"attack_leader_distance&attack_leader_distance (pre)",
		"attack_same_frame_of_reference&attack_same_frame_of_reference (pre)",
		"attack_weaponrange&attack_weaponrange (pre)",
		"combat_cue&combat_cue (pre)",
		"combatmove_elevation&combatmove_elevation (pre)",
		"combatmove_follow_unit&combatmove_follow_unit (pre)",
		"combatmove_lineoffire&combatmove_lineoffire (pre)",
		"combatmove_lineoffire_occluded&combatmove_lineoffire_occluded (pre)",
		"cover_near_friends&cover_near_friends (pre)",
		"current_position&current_position (pre)",
		"current_destination&current_destination (pre)",
		"cover_fight&cover_fight (pre)",
		"danger_zone&danger_zone (pre)",
		"directional_movement&directional_movement (pre)",
		"facing&facing (pre)",
		"fireteam_leader&fireteam_leader (pre)",
		"flag_preferences&flag_preferences (pre)",
		"flank&flank (pre)",
		"flee_to_leader&flee_to_leader (pre)",
		"friendly&friendly (pre)",
		"friend_bunkering&friend_bunkering (pre)",
		"goal_points_only&goal_points_only (pre)",
		"goal_preferences&goal_preferences (pre)",
		"heatmap&heatmap (pre)",
		"hide_equipment&hide_equipment (pre)",
		"idle_wander&idle_wander (pre)",
		"inertia_preservation&inertia_preservation (pre)",
		"leadership&leadership (pre)",
		"movement_planning&movement_planning (pre)",
		"move_into_danger_zone&move_into_danger_zone (pre)",
		"move_distance&move_distance (pre)",
		"move_localized&move_localized (pre)",
		"multi_target&multi_target (pre)",
		"pack_stalk&pack_stalk (pre)",
		"panic_closetotarget&panic_closetotarget (pre)",
		"panic_targetdistance&panic_targetdistance (pre)",
		"pathfinding&pathfinding (pre)",
		"perch_preferences&perch_preferences (pre)",
		"postsearch_prefer_original&postsearch_prefer_original (pre)",
		"previously_discarded&previously_discarded (pre)",
		"pursuit_search_pattern&pursuit_search_pattern (pre)",
		"ranged_fight&ranged_fight (pre)",
		"squad_patrol_search&squad_patrol_search (pre)",
		"stalking&stalking (pre)",
		"stimulus&stimulus (pre)",
		"task_direction&task_direction (pre)",
		"threat_axis_nearby&threat_axis_nearby (pre)",
		"threat_axis_quarter&threat_axis_quarter (pre)",
		"threat_axis_spring&threat_axis_spring (pre)",
		"threat_axis_spring_reject&threat_axis_spring_reject (pre)",
		"threat_axis_third&threat_axis_third (pre)",
		"score&score (pre)",
		"too_far_from_leader&too_far_from_leader (pre)",
		"vehicle_move_distance&vehicle_move_distance (pre)",
		"vehicle_pickup&vehicle_pickup (pre)",
		"wall_leanable&wall_leanable (pre)",
		"3d_path_available&3d_path_available (post)",
		"attack_visible&attack_visible (post)",
		"attack_visible_los_optional&attack_visible_los_optional (post)",
		"guard_cover&guard_cover (post)",
		"hide_cover&hide_cover (post)",
		"uncover_visible&uncover_visible (post)",
		"vehicle_hide_cover&vehicle_hide_cover (post)",
		"cover_fight_post&cover_fight_post (post)",
		"obstacle&obstacle (post)"
	};
	STRING_LIST(evaluator_enum, evaluator_enum_strings, _countof(evaluator_enum_strings));

	STRINGS(evaluation_modes)
	{
		"fight",
		"panic",
		"cover",
		"uncover",
		"guard",
		"pursue",
		"avoid",
		"vehicle_cover",
		"postsearch",
		"cover_fight",
		"cover_evasion"
	};
	STRING_LIST(evaluation_modes, evaluation_modes_strings, _countof(evaluation_modes_strings));

	STRINGS(engage_flags)
	{
		"engage perch",
		"fight constant movement",
		"flight fight constant movement",
		"disallow combat crouching",
		"disallow crouch shooting",
		"fight stable",
		"throw should lob",
		"allow positioning beyond ideal range",
		"can suppress"
	};
	STRING_LIST(engage_flags, engage_flags_strings, _countof(engage_flags_strings));

	STRINGS(cover_flags)
	{
		"Unassailable cover ends ONLY when target assailable",
		"Use Phasing"
	};
	STRING_LIST(cover_flags, cover_flags_strings, _countof(cover_flags_strings));

	STRINGS(character_search_flags)
	{
		"crouch on investigate",
		"walk on pursuit",
		"search forever",
		"search exclusively"
	};
	STRING_LIST(character_search_flags, character_search_flags_strings, _countof(character_search_flags_strings));

	STRINGS(character_retreat_flags)
	{
		"Zig-zag when fleeing",
		"Unused1"
	};
	STRING_LIST(character_retreat_flags, character_retreat_flags_strings, _countof(character_retreat_flags_strings));

	STRINGS(charge_flags)
	{
		"offhand melee allowed",
		"berserk whenever charge",
		"don\'t use berserk mode",
		"don\'t stow weapon during berserk",
		"allow dialogue while berserking",
		"don\'t play berserk animation",
		"don\'t shoot during charge",
		"allow leap with ranged weapons"
	};
	STRING_LIST(charge_flags, charge_flags_strings, _countof(charge_flags_strings));

	STRINGS(actor_special_fire_mode_enum)
	{
		"none",
		"overcharge",
		"secondary trigger"
	};
	STRING_LIST(actor_special_fire_mode_enum, actor_special_fire_mode_enum_strings, _countof(actor_special_fire_mode_enum_strings));

	STRINGS(actor_special_fire_situation_enum)
	{
		"never",
		"enemy visible",
		"enemy out of sight",
		"strafing"
	};
	STRING_LIST(actor_special_fire_situation_enum, actor_special_fire_situation_enum_strings, _countof(actor_special_fire_situation_enum_strings));

	STRINGS(weapon_flags)
	{
		"bursting inhibits movement",
		"must crouch to shoot",
		"use extended safe-to-save range",
		"fixed aiming vector",
		"aim at feet",
		"force aim from barrel position#use only for weapons with really, really long barrels (bfg), do NOT use for rotating turret weapons (warthog, falcon, etc)"
	};
	STRING_LIST(weapon_flags, weapon_flags_strings, _countof(weapon_flags_strings));

	STRINGS(actor_grenade_trajectory_enum)
	{
		"toss",
		"lob",
		"bounce"
	};
	STRING_LIST(actor_grenade_trajectory_enum, actor_grenade_trajectory_enum_strings, _countof(actor_grenade_trajectory_enum_strings));

	STRINGS(grenades_flags)
	{
		"do not throw while bunkering",
		"allow while berserking"
	};
	STRING_LIST(grenades_flags, grenades_flags_strings, _countof(grenades_flags_strings));

	STRINGS(vehicle_flags$2)
	{
		"passengers adopt original squad",
		"snap facing to forward (ghosts)",
		"throttle to target (hornets)",
		"stationary fight (tanks)",
		"keep moving",
		"can pathfind with avoidance only",
		"use volume avoidance",
		"target equality",
		"don\'t face target",
		"override aiming limits"
	};
	STRING_LIST(vehicle_flags$2, vehicle_flags$2_strings, _countof(vehicle_flags$2_strings));

	STRINGS(vehicle_boarding_flags)
	{
		"boarding does not enter seat"
	};
	STRING_LIST(vehicle_boarding_flags, vehicle_boarding_flags_strings, _countof(vehicle_boarding_flags_strings));

	STRINGS(boarding_flags)
	{
		"airborne boarding"
	};
	STRING_LIST(boarding_flags, boarding_flags_strings, _countof(boarding_flags_strings));

	STRINGS(rook_flags)
	{
		"active while socketed"
	};
	STRING_LIST(rook_flags, rook_flags_strings, _countof(rook_flags_strings));

	STRINGS(agent_filter_flags)
	{
		"Companion",
		"Protector",
		"Spawner",
		"Birther"
	};
	STRING_LIST(agent_filter_flags, agent_filter_flags_strings, _countof(agent_filter_flags_strings));

	STRINGS(task_generation_flags)
	{
		"Protect Me",
		"Resurrect On Death"
	};
	STRING_LIST(task_generation_flags, task_generation_flags_strings, _countof(task_generation_flags_strings));

	STRINGS(character_advance_type_enum)
	{
		"charge",
		"teleport",
		"leap"
	};
	STRING_LIST(character_advance_type_enum, character_advance_type_enum_strings, _countof(character_advance_type_enum_strings));

	STRINGS(advance_flags)
	{
		"charge on shield down"
	};
	STRING_LIST(advance_flags, advance_flags_strings, _countof(advance_flags_strings));

	STRINGS(forerunner_flags)
	{
		"charge on command",
		"Teleport to combat pos"
	};
	STRING_LIST(forerunner_flags, forerunner_flags_strings, _countof(forerunner_flags_strings));

	STRINGS(character_equipment_usage_when_enum)
	{
		"combat",
		"cover",
		"shield",
		"health",
		"uncover",
		"berserk",
		"investigate",
		"anti vehicle"
	};
	STRING_LIST(character_equipment_usage_when_enum, character_equipment_usage_when_enum_strings, _countof(character_equipment_usage_when_enum_strings));

	STRINGS(character_equipment_usage_how_enum)
	{
		"Attach to self",
		"Throw at enemy",
		"Throw at feet",
		"Use on self",
		"Stop using on self"
	};
	STRING_LIST(character_equipment_usage_how_enum, character_equipment_usage_how_enum_strings, _countof(character_equipment_usage_how_enum_strings));

	STRINGS(character_equipment_def_bits)
	{
		"Stop If No Energy"
	};
	STRING_LIST(character_equipment_def_bits, character_equipment_def_bits_strings, _countof(character_equipment_def_bits_strings));

	STRINGS(character_flags)
	{
		"Flag1"
	};
	STRING_LIST(character_flags, character_flags_strings, _countof(character_flags_strings));

} // namespace blofeld

