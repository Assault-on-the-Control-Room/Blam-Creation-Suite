#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_REFERENCE(chud_animation_reference, CHUD_ANIMATION_TAG);
	TAG_REFERENCE(chud_reference, CHUD_TAG);
	TAG_REFERENCE(chud_globals_reference, CHUD_GLOBALS_TAG);

	TAG_GROUP(chud_animation, CHUD_ANIMATION_TAG)
	{
		{ _field_terminator }
	};

	TAG_GROUP(chud, CHUD_TAG)
	{
		{ _field_terminator }
	};

	TAG_GROUP(chud_globals, CHUD_GLOBALS_TAG)
	{
		{ _field_terminator }
	};

}

