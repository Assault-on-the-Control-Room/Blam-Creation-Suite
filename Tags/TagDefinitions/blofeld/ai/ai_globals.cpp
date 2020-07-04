#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(ai_globals, AI_GLOBALS_TAG, ai_globals_block_block );

	TAG_BLOCK(ai_globals_gravemind_block, 1)
	{
		{ _field_real, "min retreat time:secs" },
		{ _field_real, "ideal retreat time:secs" },
		{ _field_real, "max retreat time:secs" },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_formation_block, k_global_formations_count)
	{
		{ _field_tag_reference, "formation^", &formation_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_squad_template_block, k_global_squad_templates_count)
	{
		{ _field_tag_reference, "squad_template^", &squad_template_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_squad_template_sub_folder_block, k_global_squad_template_folder_count)
	{
		{ _field_string_id, "sub folder name^" },
		{ _field_block, "templates", &ai_globals_squad_template_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_squad_template_folder_block, k_global_squad_template_folder_count)
	{
		{ _field_string_id, "folder name^" },
		{ _field_block, "sub folders", &ai_globals_squad_template_sub_folder_block_block },
		{ _field_block, "templates", &ai_globals_squad_template_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_performance_template_block, k_global_performance_templates_count)
	{
		{ _field_tag_reference, "thespian_template^", &performance_template_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_performance_template_sub_folder_block, k_global_performance_template_folder_count)
	{
		{ _field_string_id, "sub folder name^" },
		{ _field_block, "templates", &ai_globals_performance_template_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_performance_template_folder_block, k_global_performance_template_folder_count)
	{
		{ _field_string_id, "folder name^" },
		{ _field_block, "sub folders", &ai_globals_performance_template_sub_folder_block_block },
		{ _field_block, "templates", &ai_globals_performance_template_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_custom_stimuli_block, k_max_custom_stimuli_count)
	{
		{ _field_string_id, "name^" },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_trait_vision_block, k_num_ai_trait_vision-2)
	{
		{ _field_explanation, "Vision Traits", "Traits that affect the AI\'s vision" },
		{ _field_real, "vision distance scale#Scale the distance at which an AI can see their target." },
		{ _field_real, "vision angle scale#Scale the angles of the AI\'s vision cone." },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_trait_sound_block, k_num_ai_trait_sound-2)
	{
		{ _field_explanation, "Sound Traits", "Traits that affect the AI\'s sound awareness" },
		{ _field_real, "hearing distance scale#Scale the character\'s hearing distance." },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_trait_luck_block, k_num_ai_trait_luck-2)
	{
		{ _field_explanation, "Luck Traits", "Traits that affect the AI\'s luck" },
		{ _field_real, "evasion chance scale#Scale the chance of evading fire." },
		{ _field_real, "grenade dive chance scale#Scale the chance of diving from grenades." },
		{ _field_real, "broken kamikaze chance scale#Scale the chance of going kamikaze when broken." },
		{ _field_real, "leader dead retreat chance scale#Scale the chance of retreating when your leader dies." },
		{ _field_real, "dive retreat chance scale#Scale the chance of retreating after a dive." },
		{ _field_real, "shield depleted berserk chance scale#Scale the chance of berserking when your shield is depleted." },
		{ _field_real, "leader abandoned berserk chance scale#Scale the chance of a leader berserking when all his followers die." },
		{ _field_real, "melee attack delay timer scale#Scale the time between melee attacks." },
		{ _field_real, "melee chance scale#Scale the chance of meleeing." },
		{ _field_real, "melee leap delay timer scale#Scale the delay for performing melee leaps." },
		{ _field_real, "throw grenade delay scale#Scale the time between grenade throws." },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_trait_grenade_block, k_num_ai_trait_grenade-2)
	{
		{ _field_explanation, "Grenade Traits", "Traits that affect the AI\'s grenade use" },
		{ _field_real, "velocity scale#Scale the velocity at which AI throws grenades" },
		{ _field_real, "throw grenade delay scale#Scale the time between grenade throws." },
		{ _field_real, "don\'t drop grenades chance scale" },
		{ _field_real, "grenade uncover chance scale" },
		{ _field_real, "retreat throw grenade chance scale" },
		{ _field_real, "anti vehicle grenade chance scale" },
		{ _field_real, "throw grenade chance scale" },
		{ _field_terminator }
	};

	TAG_BLOCK(ai_globals_data_block, 1)
	{
		{ _field_real, "AI infantry-on-AI weapon damage scale:[0,1]#Global scale on weapon damage made by AI on other AI" },
		{ _field_real, "AI vehicle-on-AI weapon damage scale:[0,1]#Global scale on weapon damage made by AI in a vehicle on other AI" },
		{ _field_real, "AI player vehicle-on-AI weapon damage scale:[0,1]#Global scale on weapon damage made by AI in a vehicle with the player on other AI" },
		{ _field_real, "danger broadly facing" },
		{ _field_real, "danger shooting near" },
		{ _field_real, "danger shooting at" },
		{ _field_real, "danger extremely close" },
		{ _field_real, "danger shield damage" },
		{ _field_real, "danger exetended shield damage" },
		{ _field_real, "danger body damage" },
		{ _field_real, "danger extended body damage" },
		{ _field_tag_reference, "global dialogue tag", &ai_dialogue_globals_reference },
		{ _field_string_id, "default mission dialogue sound effect" },
		{ _field_real, "jump down:wu/tick" },
		{ _field_real, "jump step:wu/tick" },
		{ _field_real, "jump crouch:wu/tick" },
		{ _field_real, "jump stand:wu/tick" },
		{ _field_real, "jump storey:wu/tick" },
		{ _field_real, "jump tower:wu/tick" },
		{ _field_pad, "jump leap placeholder", 4 },
		{ _field_real, "max jump down height down:wu" },
		{ _field_real, "max jump down height step:wu" },
		{ _field_real, "max jump down height crouch:wu" },
		{ _field_real, "max jump down height stand:wu" },
		{ _field_real, "max jump down height storey:wu" },
		{ _field_real, "max jump down height tower:wu" },
		{ _field_pad, "another leap placeholder", 4 },
		{ _field_real_bounds, "hoist step:wus" },
		{ _field_real_bounds, "hoist crouch:wus" },
		{ _field_real_bounds, "hoist stand:wus" },
		{ _field_real_bounds, "vault step:wus" },
		{ _field_real_bounds, "vault crouch:wus" },
		{ _field_explanation, "PATHFINDING SEARCH RANGES", "The maximum ranges to which firing point evaluations will do pathfinding searches. INCREASING THESE VALUES WILL ALMOST CERTAINLY HAVE A NEGATIVE IMPACT ON PERFORMANCE." },
		{ _field_real, "search range infantry:wus" },
		{ _field_real, "search range flying:wus" },
		{ _field_real, "search range vehicle:wus" },
		{ _field_real, "search range giant:wus" },
		{ _field_block, "gravemind properties", &ai_globals_gravemind_block_block },
		{ _field_real, "scary target threhold#A target of this scariness is offically considered scary (by combat dialogue, etc.)" },
		{ _field_real, "scary weapon threhold#A weapon of this scariness is offically considered scary (by combat dialogue, etc.)" },
		{ _field_real, "player scariness" },
		{ _field_real, "berserking actor scariness" },
		{ _field_real, "kamikazeing actor scariness" },
		{ _field_real, "invincible scariness#when an actor\'s target is invincible, he is this much more scared" },
		{ _field_explanation, "RESURRECTION", "A few properties to help define when it is safe for a mission critical character to ressurect." },
		{ _field_real, "min death time:seconds#I will be dead for at least this long" },
		{ _field_real, "projectile distance:wu#If there is a projectile within this distance of me, I\'ll stay dead" },
		{ _field_real, "idle clump distance:wu#If there is any enemy clump within this distance of me, I\'ll stay dead" },
		{ _field_real, "dangerous clump distance:wu#If there is any enemy clump with a status higher than idle within this distance of me, I\'ll stay dead" },
		{ _field_explanation, "TELEPORTATION", "A few properties to help define when it is safe for a mission critical character to teleport." },
		{ _field_real, "cover search duration:seconds#The number of seconds that must elapse before we try to look for a firing point behind cover to teleport to." },
		{ _field_real, "task direction search duration:seconds#The number of seconds we try to look for a firing point that aligns us with the actor\'s task direction." },
		{ _field_block, "spawn formations", &ai_globals_formation_block_block },
		{ _field_block, "squad template folders", &ai_globals_squad_template_folder_block_block },
		{ _field_block, "performance template folders", &ai_globals_performance_template_folder_block_block },
		
		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_block, "custom stimuli", &ai_globals_custom_stimuli_block_block },
		{ _field_block, "cue templates", &ai_cue_template_block_block },

		{ _field_explanation, "CLUMP THROTTLING", "Some values to help you control how much guys will throttle when they want to stick with the rest of their squad." },
		{ _field_real, "stop dist:wu#At this distance from the squad, stop." },
		{ _field_real, "resume dist:wu#At this distance from the squad, start again." },
		{ _field_real, "min dist:wu#Start throttling back at this distance" },
		{ _field_real, "max dist:wu#Maximum trottle scale at this distance" },
		{ _field_real, "min scale:0-1#Minimum throttle value." },
		{ _field_explanation, "SQUAD PATROLLING", "Parameters related to squad patrolling." },
		{ _field_real, "passthrough chance#Chance of passing through a patrol objective without pausing" },
		{ _field_real, "search phase skip chance#Chance of skipping the search phase when stopped at a patrol objective" },
		{ _field_real, "patrol transition timeout:seconds#If the squad takes more than this time to get to their new patrol point, cancel it and go on to the next." },
		{ _field_real, "patrol maneuver timeout:seconds#If the squad takes longer than this time to reposition within a patrol point (e.g. searching and pausing), cancel the point and go on to the next." },
		{ _field_real_bounds, "patrol search firing point time:seconds#spend this amount of time at a search firing position when in search phase" },
		{ _field_real, "patrol isolation distance:wus#If you are more than this distance from your nearest squadmate, you are officially isolated." },
		{ _field_real, "patrol isolation time:seconds#If you are isolated for more than this time, you get deleted." },
		{ _field_explanation, "KUNGFU CONTROL", "These parameters control how the kung-fu circle works (i.e. when tasks have kungfu-count associated with them)" },
		{ _field_real, "kungfu deactivation delay:seconds#When a task is disallowed from shooting, turn it off after this delay" },
		{ _field_custom, "Presearch Child Counts (0 means no limit)" },
		{ _field_short_integer, "suppressing fire count" },
		{ _field_short_integer, "uncover count" },
		{ _field_short_integer, "leap on cover count" },
		{ _field_short_integer, "destroy cover count" },
		{ _field_short_integer, "guard count" },
		{ _field_short_integer, "investigate count" },
		{ _field_custom },
		{ _field_block, "vision traits", &ai_trait_vision_block_block },
		{ _field_block, "sound traits", &ai_trait_sound_block_block },
		{ _field_block, "luck traits", &ai_trait_luck_block_block },
		{ _field_block, "grenade traits", &ai_trait_grenade_block_block },
		{ _field_custom, "Search Pattern Specification" },
		{ _field_real, "max decay time" },
		{ _field_real, "decay time ping" },
		{ _field_real, "search pattern radius" },
		{ _field_short_integer, "search pattern shell count" },
		{ _field_short_bounds, "search pattern cells per shell range" },
		{ _field_pad, "MOOOOOOO", 2 },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(ai_globals_block, 1, ai_globals_struct_definition_struct_definition );

	TAG_STRUCT(ai_globals_struct_definition)
	{
		{ _field_block, "data", &ai_globals_data_block_block },
		{ _field_terminator }
	};

} // namespace blofeld

