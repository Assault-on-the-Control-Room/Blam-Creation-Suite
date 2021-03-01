#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define EFFECT_STRUCT_DEFINITION_ID { 0x6C1AEA4A, 0x31EA4E8B, 0xB019756D, 0xBD1D9033 }
	TAG_BLOCK(
		effect_block,
		"effect_block",
		1,
		"effect_definition",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &effect_flags },
		{ _field_dword_integer, "fixed random seed", "If this is non-zero, the effect will usually be exactly repeatable" },
		{ _field_real, "restart if within", nullptr, "world units", MAKE_OLD_NAMES("overlap threshold") },
		{ _field_real, "continue if within", nullptr, "world units" },
		{ _field_real, "death_delay" },
		{ _field_short_block_index, "loop start event", &effect_event_block },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_char_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_char_enum, "priority", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_effect_priority_enum },

		FIELD_PAD("asdfsdf", nullptr, FIELD_FLAG_NONE, 1),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_real, "global size scale" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_string_id, "scale A override", "Handle with care. FYI only works if the effect is attached to an object" },
		{ _field_string_id, "scale B override", "Handle with care. FYI only works if the effect is attached to an object" },
		{ _field_real, "runtime danger radius", FIELD_FLAG_UNKNOWN0 },

		{ _field_block, "locations", &effect_locations_block, _field_id_slap },
		{ _field_block, "events", &effect_event_block },
		{ _field_block, "looping sounds", &effect_looping_sound_block },
		{ _field_real, "always play distance" },
		{ _field_real, "never play distance" },
		{ _field_real, "runtime lightprobe_death_delay", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "runtime local_space_death_delay", FIELD_FLAG_UNKNOWN0 },
		{ _field_block, "conical distribution", &effect_conical_distribution_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		effect_group,
		EFFECT_TAG,
		nullptr,
		INVALID_TAG,
		effect_block );

	#define EFFECT_LOCATIONS_BLOCK_ID { 0xF2742E8C, 0xCAA34E8B, 0xBD3E6DF9, 0x3868BCB3 }
	TAG_BLOCK(
		effect_locations_block,
		"effect_locations_block",
		k_maximum_effect_locations_count,
		"effect_location_definition",
		SET_UNKNOWN0 | SET_UNKNOWN3 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_LOCATIONS_BLOCK_ID)
	{
		FIELD_EXPLANATION("MARKER NAMES", nullptr, FIELD_FLAG_NONE, "In addition to the marker in the render model there are several special marker names:\n\nreplace\nReplace allows you to use the same effect with different markers. Damage transition effects support this for example.\n\ngravity, up\nThe direction of gravity (down) and the opposite direction (up).  Always supplied\n\nnormal\nVector pointing directly away from the surface you collided with. Supplied for effects from collision.\n\nforward\nThe \'negative incident\' vector i.e. the direction the object is moving in. Most commonly used to generated decals. Supplied for effects from collision.\n\nbackward\nThe \'incident\' vector i.e. the opposite of the direction the object is moving in. Supplied for effects from collision.\n\nreflection\nThe way the effect would reflect off the surface it hit. Supplied for effects from collision.\n\nroot\nThe object root (pivot). These can used for all effects which are associated with an object.\n\nimpact\nThe location of a havok impact.\n\nwater_surface\nPoint of the effect projected to the water surface above it. Otherwise it just returns the effect position.\n\nchild\nThe location of the last detonated projectile, in case the parent object is a weapon (tracers only)\n\n"),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_old_string_id, "marker name", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &effect_location_flags },
		{ _field_char_enum, "priority", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_effect_priority_enum },
		FIELD_PAD("RGEWNQIG", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define EFFECT_EVENT_BLOCK_ID { 0x45ADB157, 0x3FEF4708, 0xB03F70BB, 0x8CF7F2FE }
	TAG_BLOCK(
		effect_event_block,
		"effect_event_block",
		k_maximum_effect_events_count,
		"effect_event_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_EVENT_BLOCK_ID)
	{
		{ _field_string_id, "event name", FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &event_flags },
		{ _field_char_enum, "priority", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_effect_priority_enum },
		FIELD_PAD("EVUIQSNDS", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_real_fraction, "skip fraction", "chance that this event will be skipped entirely" },
		FIELD_CUSTOM("delay bounds", "delay before this event takes place", FIELD_FLAG_NONE, _field_id_unknown_mela),
		{ _field_real_bounds, "delay bounds", "delay before this event takes place", "seconds" },
		FIELD_CUSTOM("duration bounds", "duration of this event", FIELD_FLAG_NONE, _field_id_unknown_mela),
		{ _field_real_bounds, "duration bounds", "duration of this event", "seconds" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		FIELD_EXPLANATION("event age duration override", nullptr, FIELD_FLAG_NONE, "Parts and particle systems can take \"event age\" as a function input.  Typically that goes from 0 to 1 over the event duration.  If you want a different time, specify it here.  0 means use the duration bounds above."),
		{ _field_real, "event age duration override", "the amount of time over which the \"event age\" function input goes from 0 to 1", "seconds" },

		{ _field_block, "parts", &effect_part_block },
		{ _field_block, "accelerations", &effect_accelerations_block },
		{ _field_block, "particle systems", &particle_system_definition_block_new_block },
		{ _field_terminator }
	};

	#define EFFECT_PART_BLOCK_ID { 0x10814B9B, 0xE63D42D7, 0x945DD824, 0x6CF277F8 }
	TAG_BLOCK(
		effect_part_block,
		"effect_part_block",
		k_maximum_effect_parts_per_event_count,
		"effect_part_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_PART_BLOCK_ID)
	{
		{ _field_enum, "create in", &effect_environments },
		{ _field_enum, "violence mode", &effect_dispositions },
		{ _field_short_block_index, "location", &effect_locations_block },
		{ _field_short_block_index, "secondary location (beams)", &effect_locations_block },
		{ _field_word_flags, "flags", &effect_part_flags },
		{ _field_char_enum, "priority", &global_effect_priority_enum },
		{ _field_char_enum, "camera mode", "Currently, the only supported use is to turn parts off in first-person view.", &effect_camera_modes },
		{ _field_tag, "runtime base group tag", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_enum, "game mode", &effectPartGameModeDefinition },
		{ _field_char_enum, "damage reporting type", &global_damage_reporting_enum_definition },
		FIELD_PAD("JCIOEHR", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_tag_reference, "type", FIELD_FLAG_INDEX, &effect_part_block_type_reference },
		FIELD_CUSTOM("velocity bounds", "initial velocity along the location's forward, for decals the distance at which decal is created (defaults to 0.5)", FIELD_FLAG_NONE, _field_id_unknown_mela),
		{ _field_real_bounds, "velocity bounds", "initial velocity along the location's forward, for decals the distance at which decal is created (defaults to 0.5)", "world units per second" },
		{ _field_real_euler_angles_2d, "velocity orientation (yaw, pitch)", "NOT USED", FIELD_FLAG_UNKNOWN0 },
		{ _field_angle, "velocity cone angle", "initial velocity will be inside the cone defined by this angle.", "degrees" },
		{ _field_angle_bounds, "angular velocity bounds", nullptr, "degrees per second" },
		FIELD_CUSTOM("radius modifier bounds", nullptr, FIELD_FLAG_NONE, _field_id_unknown_mela),
		{ _field_real_bounds, "radius modifier bounds" },
		{ _field_real_point_3d, "relative offset" },
		{ _field_real_euler_angles_2d, "relative orientation (yaw, pitch)" },
		FIELD_EXPLANATION("SCALE MODIFIERS", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_flags, "A scales values", &effect_part_scaleable_values },
		{ _field_long_flags, "B scales values", &effect_part_scaleable_values },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_tag_reference, "particleize", "optional particleization effect definition, if you want this to particleize on spawn", &global_particleize_parameters_reference },

		{ _field_terminator }
	};

	#define EFFECT_ACCELERATIONS_BLOCK_ID { 0x007DDA95, 0x2A084D2A, 0x8AE44F3A, 0x4F217DD2 }
	TAG_BLOCK(
		effect_accelerations_block,
		"effect_accelerations_block",
		k_maximum_effect_accelerations_per_event_count,
		"effect_acceleration_definition",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_ACCELERATIONS_BLOCK_ID)
	{
		{ _field_enum, "create in", &effect_environments },
		{ _field_enum, "violence mode", &effect_dispositions },
		{ _field_short_block_index, "location", &effect_locations_block },
		FIELD_PAD("THY", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "acceleration" },
		{ _field_real, "inner cone angle", nullptr, "degrees" },
		{ _field_real, "outer cone angle", nullptr, "degrees" },
		{ _field_terminator }
	};

	#define EFFECT_LOOPING_SOUND_BLOCK_STRUCT_ID { 0xB07D23C9, 0xEC514DE9, 0x827535F2, 0x48CD794B }
	TAG_BLOCK(
		effect_looping_sound_block,
		"effect_looping_sound_block",
		k_maximum_effect_looping_sounds_count,
		"effect_looping_sound_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_LOOPING_SOUND_BLOCK_STRUCT_ID)
	{
		{ _field_tag_reference, "looping sound", FIELD_FLAG_INDEX, &global_looping_sound_reference },
		{ _field_short_block_index, "location", &effect_locations_block },
		{ _field_short_block_index, "bind scale to event", &effect_event_block },
		{ _field_terminator }
	};

	#define EFFECT_CONICAL_DISTRIBUTION_BLOCK_ID { 0x3B2368F1, 0x9891495D, 0xB02F5E1C, 0x5B933025 }
	TAG_BLOCK(
		effect_conical_distribution_block,
		"effect_conical_distribution_block",
		1,
		"s_effect_conical_distribution_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EFFECT_CONICAL_DISTRIBUTION_BLOCK_ID)
	{
		FIELD_EXPLANATION("conical_projection: AKA shotgun", nullptr, FIELD_FLAG_NONE, "projectile_count = yaw_count*pitch_count"),
		{ _field_short_integer, "yaw count" },
		{ _field_short_integer, "pitch count" },
		{ _field_real, "distribution exponent", "exp==.5 even distribution, exp>.5== tighter" },
		{ _field_angle, "spread", "degrees" },
		{ _field_terminator }
	};

	STRINGS(effect_dispositions)
	{
		"either mode",
		"violent mode only",
		"nonviolent mode only"
	};
	STRING_LIST(effect_dispositions, effect_dispositions_strings, _countof(effect_dispositions_strings));

	STRINGS(effect_environments)
	{
		"any environment",
		"air only",
		"water only",
		"space only",
		"wet only",
		"dry only"
	};
	STRING_LIST(effect_environments, effect_environments_strings, _countof(effect_environments_strings));

	STRINGS(effect_camera_modes)
	{
		"independent of camera mode",
		"only in first person",
		"only in third person",
		"both first and third"
	};
	STRING_LIST(effect_camera_modes, effect_camera_modes_strings, _countof(effect_camera_modes_strings));

	STRINGS(effect_location_flags)
	{
		"optional (no error if not found)",
		"destructible (no error if goes away)",
		"track sub-frame movements#When effect moves multiple times within one frame, update location each time",
		"never stagger across markers#Even if this effect is told to stagger across available markers, always fire from all instances"
	};
	STRING_LIST(effect_location_flags, effect_location_flags_strings, _countof(effect_location_flags_strings));

	STRINGS(effect_part_scaleable_values)
	{
		"velocity",
		"velocity delta",
		"velocity cone angle",
		"angular velocity",
		"angular velocity delta",
		"type-specific scale"
	};
	STRING_LIST(effect_part_scaleable_values, effect_part_scaleable_values_strings, _countof(effect_part_scaleable_values_strings));

	STRINGS(effect_part_flags)
	{
		"face down regardless of location (decals)",
		"offset origin away from geometry (lights)",
		"never attached to object",
		"disabled for debugging",
		"draw regardless of distance",
		"make every tick",
		"inherit parent variant",
		"batch AOE damage",
		"create even when event loops back to self",
		"face up regardless of location (replace_up)",
		"sound only plays in killcam#NOTE this is only for sound, and really only for firing effect sounds"
	};
	STRING_LIST(effect_part_flags, effect_part_flags_strings, _countof(effect_part_flags_strings));

	STRINGS(effectPartGameModeDefinition)
	{
		"any",
		"campaign only",
		"multiplayer only",
		"campaign only not cinematics",
		"campaign cinematics only",
		"campaign solo only"
	};
	STRING_LIST(effectPartGameModeDefinition, effectPartGameModeDefinition_strings, _countof(effectPartGameModeDefinition_strings));

	STRINGS(event_flags)
	{
		"disabled for debugging",
		"particles die when effect ends{particles die when event ends}",
		"loop event age duration override"
	};
	STRING_LIST(event_flags, event_flags_strings, _countof(event_flags_strings));

	STRINGS(effect_flags)
	{
		"deleted when attachment deactivates",
		"run events in parallel",
		"do not re-use parts when looping#This option will hurt performance on effects with very short duration.",
		"age creator\'s weapon",
		"use parent position but world orientation",
		"can penetrate walls (expensive)",
		"cannot be restarted#Will help performance for parallel events of different lengths, if the effect is unlikely to be reused",
		"force use own lightprobe#Do not adopt parent object\'s lightprobe, even when it\'s available",
		"force looping#Do not use this unless you know you stop the effect at some point",
		"ordnance droppod locator#trigger creation of player\'s ordnance droppod",
		"render in hologram pass#this effect should be lumped in with Cortana and other holograms when rendered",
		"lightprobe only sample airprobes#Only works with \"force use own lightprobe\"; causes effect to never sample lightmap, only placed light probes",
		"play effect even outside bsps (expensive)",
		"draw .parts when stopped{draw lens flares when stopped}",
		"kill particles when stopped#particularly useful for particles that live forever",
		"play even on hidden objects",
		"disable first person parts in blind skull#blind skull hides the first person weapon",
		"hides associated object on effect deletion#when the effect is deleted, it hides the object it is associated with (for hologram in mp)",
		"bypass mp throttle#effect can not ignore generated crates or be non-networked"
	};
	STRING_LIST(effect_flags, effect_flags_strings, _countof(effect_flags_strings));

	TAG_REFERENCE(global_effect_reference, EFFECT_TAG);

	TAG_REFERENCE(globalEffectReferenceNonResourceDependency, EFFECT_TAG, _tag_reference_flag_not_a_resource_dependency);

} // namespace macaque

} // namespace blofeld

