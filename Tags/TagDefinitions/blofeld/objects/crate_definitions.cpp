#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(crate, CRATE_TAG, object, OBJECT_TAG, crate_block_block );

	TAG_BLOCK_FROM_STRUCT(crate_block, 1, crate_struct_definition_struct_definition );

	TAG_STRUCT(crate_struct_definition)
	{
		{ _field_struct, "object", &object_struct_definition_struct_definition },
		{ _field_custom, "$$$ CRATE $$$" },
		{ _field_word_flags, "flags", &crate_flags },
		{ _field_pad, "KOQVK", 2 },
		{ _field_block, "campaign metagame bucket", &campaign_metagame_bucket_block_block },
		{ _field_long_integer, "self destruction timer:seconds" },

		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_tag_reference, "particleize#optional particleization effect definition, if you want this to particleize when it takes damage", &global_particleize_parameters_reference },
		{ _field_string_id, "grab animation set#the animation set to use when this crate is grabbed" },
		{ _field_string_id, "grab pickup string#the string to display when the player can grab this object, from ui/hud/hud_messages" },
		{ _field_tag_reference, "projectile bounce effect#effect to play when a projectile bounces because of the \"all projectiles bounce off\" flag", &global_effect_reference },
		{ _field_custom },

		{ _field_terminator }
	};

	STRINGS(crate_flags)
	{
		"does not block AOE",
		"attach texture camera hack",
		"can be grabbed",
		"all projectiles bounce off",
		"targetable",
		"crate walls block AOE#for crates that behave like a bubble shield but are not attached to equipment",
		"crate blocks damage flash damage response",
		"crate blocks rumble damage response",
		"crate takes top level aoe damage#crate takes top level aoe damage when parented to another object",
		"crate blocks forced projectile overpenetration#so that the active shield can block the splaser",
		"unimportant#some rotational and velocity attributes are not synchronized from host to client"
	};
	STRING_LIST(crate_flags, crate_flags_strings, _countof(crate_flags_strings));

} // namespace blofeld

