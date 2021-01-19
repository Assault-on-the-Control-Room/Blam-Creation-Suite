#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define DIALOGUE_STRUCT_DEFINITION_ID { 0xAA0A2CFC, 0xE8A4480C, 0xAFF53536, 0x20BCFEF8 }
	TAG_BLOCK(
		dialogue_block,
		"dialogue_block",
		1,
		"s_dialogue_definition",
		DIALOGUE_STRUCT_DEFINITION_ID)
	{
		{ _field_tag_reference, "global dialogue info", &global_dialogue_reference },
		{ _field_long_flags, "flags", &dialogue_flags },
		{ _field_block, "vocalizations", &sound_references_block },
		{ _field_string_id, "mission dialogue designator#3-letter mission dialogue designator name" },
		{ _field_terminator }
	};

	TAG_GROUP(
		dialogue_group,
		DIALOGUE_TAG,
		nullptr,
		INVALID_TAG,
		dialogue_block );

	#define SOUND_REFERENCES_BLOCK_ID { 0x6751BC80, 0xAF514348, 0x886AF0F0, 0x68DB8F16 }
	TAG_BLOCK(
		sound_references_block,
		"sound_references_block",
		500,
		"sound_references_block",
		SOUND_REFERENCES_BLOCK_ID)
	{
		{ _field_string_id, "vocalization^" },
		{ _field_block, "stimuli", &vocalization_stimuli_block_definition_block },
		{ _field_terminator }
	};

	#define VOCALIZATION_STIMULI_BLOCK_DEFINITION_ID { 0x8EA8B87C, 0xE73C4EE8, 0x8C95D4FE, 0xB6EF9EC6 }
	TAG_BLOCK(
		vocalization_stimuli_block_definition_block,
		"vocalization_stimuli_block_definition",
		6,
		"s_vocalization_stimulus",
		VOCALIZATION_STIMULI_BLOCK_DEFINITION_ID)
	{
		{ _field_word_flags, "flags", &vocalization_stimulus_flags },
		{ _field_pad, "AN", 2 },
		{ _field_string_id, "stimulus^" },
		{ _field_tag_reference, "sound", &sound_reference$4 },
		{ _field_terminator }
	};

	STRINGS(vocalization_stimulus_flags)
	{
		"additive#this stimulus should add to the default vocalization instead of replacing it",
		"don\'t suppress#this stimulus cannot be suppressed"
	};
	STRING_LIST(vocalization_stimulus_flags, vocalization_stimulus_flags_strings, _countof(vocalization_stimulus_flags_strings));

	STRINGS(dialogue_flags)
	{
		"female"
	};
	STRING_LIST(dialogue_flags, dialogue_flags_strings, _countof(dialogue_flags_strings));

} // namespace macaque

} // namespace blofeld

