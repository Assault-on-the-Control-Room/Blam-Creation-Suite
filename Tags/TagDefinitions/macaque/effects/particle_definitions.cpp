#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		particle_group,
		PARTICLE_TAG,
		nullptr,
		INVALID_TAG,
		particle_block );

	TAG_BLOCK_FROM_STRUCT(
		particle_block,
		"particle_block",
		1,
		particle_struct_definition);

	#define GPU_VARIANTS_BLOCK_ID { 0x7820CC6F, 0x022840F4, 0x93225BE7, 0x818DBD97 }
	TAG_BLOCK(
		gpu_variants_block,
		"gpu_variants_block",
		sizeof(c_particle_definition::s_gpu_data::s_frames)/sizeof(real_vector4d),
		"real_vector4d",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GPU_VARIANTS_BLOCK_ID,
		4)
	{
		{ _field_array, "runtime m_count", FIELD_FLAG_UNKNOWN0, &gpu_single_constant_register_array },
		{ _field_terminator }
	};

	#define ATTACHMENT_BLOCK_ID { 0xDB309672, 0x396440FD, 0x8DB1932A, 0xD3071736 }
	TAG_BLOCK(
		attachment_block,
		"attachment_block",
		4,
		"s_particle_attachment",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		ATTACHMENT_BLOCK_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &attachment_flags },
		FIELD_PAD("gerrrrr", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_tag_reference, "type", &attachment_block_type_reference },
		{ _field_char_enum, "trigger", &attachment_type_enum },
		{ _field_byte_integer, "skip fraction", "0 will always play, 127 will be extremely rare", nullptr, "[0-127]" },
		{ _field_char_enum, "primary scale", &game_state_type_enum },
		{ _field_char_enum, "secondary scale", &game_state_type_enum },
		{ _field_terminator }
	};

	#define GPU_SPRITE_BLOCK_ID { 0x821F9C90, 0x95844863, 0x9425371D, 0x7AB8E8DD }
	TAG_BLOCK(
		gpu_sprite_block,
		"gpu_sprite_block",
		1,
		"(*((c_particle_definition*",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GPU_SPRITE_BLOCK_ID,
		4)
	{
		{ _field_array, "runtime gpu_sprite_array", FIELD_FLAG_UNKNOWN0, &gpu_single_constant_register_array },
		{ _field_terminator }
	};

	#define GPU_SINGLE_CONSTANT_REGISTER_ARRAY_ID { 0xA2794AE9, 0x58564257, 0xA6A57292, 0x7319E3F2 }
	TAG_ARRAY(
		gpu_single_constant_register_array,
		"gpu_single_constant_register_array",
		sizeof(real_vector4d)/sizeof(real),
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GPU_SINGLE_CONSTANT_REGISTER_ARRAY_ID)
	{
		{ _field_real, "runtime gpu_real", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define PARTICLE_STRUCT_DEFINITION_ID { 0x9ED62376, 0x9F9E4A9D, 0x9DE72B9D, 0x51E76D25 }
	TAG_STRUCT(
		particle_struct_definition,
		"particle_struct_definition",
		"c_particle_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PARTICLE_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_begin),
		{ _field_long_flags, "main flags", &particle_main_flags },
		{ _field_block, "attachments", &attachment_block },
		FIELD_EXPLANATION("PARTICLE APPEARANCE", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_flags, "appearance flags", &particle_appearance_flags },
		{ _field_enum, "particle billboard style", &particle_billboard_type_enum },
		FIELD_PAD("NQCLLBQ", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_short_integer, "first sequence index" },
		{ _field_short_integer, "sequence count" },
		{ _field_real, "low res switch distance", "the distance at which we switch from low res (close) to high res (far)", "wu" },
		{ _field_real_point_2d, "center offset" },
		{ _field_real, "curvature", nullptr, "0=flat, 1=hemisphere" },
		{ _field_real, "angle fade range", "degrees beyond cutoff over which particles fade", "degrees" },
		{ _field_real, "angle fade cutoff", "degrees away from edge-on where fade is total", "degrees" },
		{ _field_real, "motion blur translation scale", "affects billboard tilt from observer motion" },
		{ _field_real, "motion blur rotation scale", "affects billboard tilt from observer turning" },
		{ _field_real, "motion blur aspect scale", "affects aspect ratio stretching from particle and observer motion" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_explanation, "Render Method" }, // Unknown field ID, leaving as legacy
		{ _field_legacy, _field_struct, "render method", &render_method_struct_definition },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		FIELD_CUSTOM("material", nullptr, FIELD_FLAG_NONE, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_begin),
		{ _field_struct, "actual material?", &material_struct },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 10 },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_real, "unknown@" },
		{ _field_legacy, _field_tag_reference, "unknown@" },

		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_end),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_unknown_end),
		{ _field_struct, "aspect ratio", &particle_property_scalar_struct_new },
		{ _field_struct, "color", "controls how the color of the particle changes as a function of its input", "RGB", &particle_property_color_struct_new },
		{ _field_struct, "intensity", "multiplies color to give dynamic range outside [0,1]", &particle_property_scalar_struct_new },
		{ _field_struct, "alpha", "separate from color, controls how the particle fades as a function of its input", &particle_property_scalar_struct_new },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_real, "tint factor", "switches between modulate (multiply) and tint(preserve whites)", "0=modulate, 1=tint" },

		FIELD_EXPLANATION("PARTICLE ANIMATION", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_long_flags, "animation flags", &particle_animation_flags },

		{ _field_struct, "frame index", "0=first frame, 1=last frame", &particle_property_scalar_struct_new },
		{ _field_struct, "animation rate", nullptr, "index cycles per second", &particle_property_scalar_struct_new },
		{ _field_struct, "palette animation", nullptr, "v coord of palette", &particle_property_scalar_struct_new },
		FIELD_EXPLANATION("Mesh data, if this is a mesh particle", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_tag_reference, "Model", &particle_model_reference$2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		FIELD_CUSTOM("OLD DEPRECATED shader definition", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_CUSTOM("shader", nullptr, FIELD_FLAG_NONE, _field_id_shader_template),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_begin),
		{ _field_struct, "actual shader?", &shader_particle_struct_definition },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_hidd_end),

		{ _field_dword_integer, "runtime m_used_particle_states", FIELD_FLAG_UNKNOWN0 },
		{ _field_dword_integer, "runtime m_constant_per_particle_properties", FIELD_FLAG_UNKNOWN0 },
		{ _field_dword_integer, "runtime m_constant_over_time_properties", FIELD_FLAG_UNKNOWN0 },
		{ _field_struct, "runtime m_gpu_data", FIELD_FLAG_UNKNOWN0, &gpu_data_struct$2 },
		{ _field_terminator }
	};

	#define GPU_DATA_STRUCT$2_ID { 0x62F911D6, 0x9725493B, 0x8FFDB178, 0x0608FC7B }
	TAG_STRUCT(
		gpu_data_struct$2,
		"gpu_data_struct",
		"c_particle_definition::s_gpu_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GPU_DATA_STRUCT$2_ID)
	{
		{ _field_block, "runtime m_sprite", FIELD_FLAG_UNKNOWN0, &gpu_sprite_block },
		{ _field_block, "runtime m_frames", FIELD_FLAG_UNKNOWN0, &gpu_variants_block },
		{ _field_terminator }
	};

	STRINGS(particle_main_flags)
	{
		"dies at rest",
		"dies on structure collision",
		"dies in water",
		"dies in air",
		"has sweetener",
		"uses cheap shader"
		// { _field_version_platform_include, _platform_type_pc, 4 },
		// "bit 7",
		// "bit 8",
		// "bit 9",
		// "bit 10",
	};
	STRING_LIST(particle_main_flags, particle_main_flags_strings, _countof(particle_main_flags_strings));

	STRINGS(particle_appearance_flags)
	{
		"random u mirror",
		"random v mirror",
		"random starting rotation",
		"tint from lightmap",
		"tint from diffuse texture",
		"bitmap authored vertically",
		"intensity affects alpha",
		"fade when viewed edge-on",
		"motion blur",
		"double-sided",
		"low res#renders heavy overdraw particles faster",
		"low res tighter mask#requires depth fade",
		"never kill verts on GPU (expensive)",
		"particle velocity relative to camera#makes parallel and perpindicular to velocity behave differently based upon camera motion"
		// { _field_legacy, _field_version_platform_include, _platform_type_pc, 9 },
		// "unknown bit 15",
		// "unknown bit 16",
		// "unknown bit 17",
		// "unknown bit 18",
		// "unknown bit 19",
		// "unknown bit 20",
		// "unknown bit 21",
		// "unknown bit 22",
		// "unknown bit 23",

	};
	STRING_LIST(particle_appearance_flags, particle_appearance_flags_strings, _countof(particle_appearance_flags_strings));

	STRINGS(particle_animation_flags)
	{
		"frame animation one shot",
		"can animate backwards"
		// { _field_legacy, _field_version_platform_include, _platform_type_pc, 2 },
		// "bit 3",
		// "bit 4"
	};
	STRING_LIST(particle_animation_flags, particle_animation_flags_strings, _countof(particle_animation_flags_strings));

	STRINGS(particle_billboard_type_enum)
	{
		"screen facing",
		"camera facing",
		"parallel to direction",
		"perpendicular to direction",
		"vertical",
		"horizontal",
		"local vertical",
		"local horizontal",
		"world (particle models)",
		"velocity horizontal (particle models)"
	};
	STRING_LIST(particle_billboard_type_enum, particle_billboard_type_enum_strings, _countof(particle_billboard_type_enum_strings));

	STRINGS(attachment_type_enum)
	{
		"birth",
		"collision",
		"death",
		"first collision"
	};
	STRING_LIST(attachment_type_enum, attachment_type_enum_strings, _countof(attachment_type_enum_strings));

	STRINGS(attachment_flags)
	{
		"disabled for debugging"
	};
	STRING_LIST(attachment_flags, attachment_flags_strings, _countof(attachment_flags_strings));

} // namespace macaque

} // namespace blofeld

