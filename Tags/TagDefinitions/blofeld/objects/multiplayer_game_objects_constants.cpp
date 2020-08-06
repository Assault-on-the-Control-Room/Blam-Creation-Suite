#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	STRINGS(multiplayer_object_boundary_shape)
	{
		"unused",
		"sphere",
		"cylinder",
		"box"
	};
	STRING_LIST(multiplayer_object_boundary_shape, multiplayer_object_boundary_shape_strings, _countof(multiplayer_object_boundary_shape_strings));

	STRINGS(multiplayer_object_type)
	{
		"ordinary",
		"weapon",
		"grenade",
		"projectile",
		"powerup",
		"equipment",
		"ammo pack",
		"light land vehicle",
		"heavy land vehicle",
		"flying vehicle",
		"turret",
		"device",

		{ _field_version_greater, _engine_type_haloreach },
		"dispenser",

		"teleporter 2way",
		"teleporter sender",
		"teleporter receiver",
		"player spawn location",
		"player respawn zone",

		{ _field_version_less, _engine_type_haloreach, 10 },
		"hold spawn objective",
		"capture spawn objective",
		"hold destination objective",
		"capture destination objective",
		"hill objective",
		"infection haven objective",
		"territory objective",
		"vip boundary objective",
		"vip destination objective",
		"juggernaut destination objective",

		{ _field_version_greater_or_equal, _engine_type_haloreach, 11 },
		"secondary objective",
		"primary objective",
		"named location area",
		"danger zone",
		"fireteam 1 respawn zone",
		"fireteam 2 respawn zone",
		"fireteam 3 respawn zone",
		"fireteam 4 respawn zone",
		"safe volume",
		"kill volume",
		"cinematic camera position",

		{ _field_version_greater, _engine_type_haloreach, 7 },
		"mosh enemy spawn location",
		"ordnance drop point",
		"trait zone",
		"initial ordnance drop point",
		"random ordnance drop point",
		"objective ordnance drop point",
		"personal ordnance drop point"
	};
	STRING_LIST(multiplayer_object_type, multiplayer_object_type_strings, _countof(multiplayer_object_type_strings));

} // namespace blofeld

