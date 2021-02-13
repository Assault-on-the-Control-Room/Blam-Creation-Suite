#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		emblem_library_group,
		EMBLEM_LIBRARY_TAG,
		nullptr,
		INVALID_TAG,
		emblem_library_block );

	TAG_BLOCK_FROM_STRUCT(
		emblem_library_block,
		"emblem_library_block",
		1,
		emblem_library_struct_definition);

	#define EMBLEM_BITMAP_LIST_ID { 0xEB13477E, 0x34BA4731, 0xA70A97E4, 0x46849752 }
	TAG_BLOCK(
		emblem_bitmap_list_block,
		"emblem_bitmap_list",
		s_emblem_library::k_max_bitmap_list_count,
		"s_emblem_library::s_bitmap",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_BITMAP_LIST_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_short_integer, "bitmap index", "the index of the bitmap in the bitmap group" },
		FIELD_PAD("ASDFJIJJGHJFL", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "gradient size", "the size of the gradient (from white to black) in this bitmap", "pixels" },
		{ _field_terminator }
	};

	#define EMBLEM_SHAPE_LIST_ID { 0x4D04961E, 0x238E4D15, 0xB14D0036, 0x3247A29B }
	TAG_BLOCK(
		emblem_shape_list_block,
		"emblem_shape_list",
		s_emblem_library::k_max_shape_list_count,
		"s_emblem_library::s_shape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_SHAPE_LIST_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		{ _field_short_block_index, "bitmap", &emblem_bitmap_list_block },
		{ _field_enum, "address mode x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "address mode y", &render_method_bitmap_address_mode_enum },
		FIELD_PAD("FGKKGKHL", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_struct, "transform", &emblem_transform },
		{ _field_terminator }
	};

	#define EMBLEM_FRONT_LIST_ID { 0x898E38AB, 0xA7AF4A7D, 0x9EA80F57, 0x753E62B1 }
	TAG_BLOCK(
		emblem_front_list_block,
		"emblem_front_list",
		s_emblem_library::k_max_front_emblem_count,
		"s_emblem_library::s_emblem_front",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_FRONT_LIST_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		FIELD_EXPLANATION("Layer 0 (foreground)", nullptr, FIELD_FLAG_NONE, "Composed of two shapes\n"),
		{ _field_struct, "layer 0", &emblem_layer },
		FIELD_EXPLANATION("Layer 1 (midground)", nullptr, FIELD_FLAG_NONE, "This layer is behind the foreground, and in front of the background\n"),
		{ _field_struct, "layer 1", &emblem_layer },
		FIELD_EXPLANATION("Misc", nullptr, FIELD_FLAG_NONE, "Extra configuration\n"),
		{ _field_char_enum, "primary layer", "layer that is considered \"primary\" and which will use the primary color", &front_emblem_primary_layer },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define EMBLEM_BACK_LIST_ID { 0xFE53E62D, 0x2E2D4D7F, 0x84DFF768, 0x1B3C9141 }
	TAG_BLOCK(
		emblem_back_list_block,
		"emblem_back_list",
		s_emblem_library::k_max_back_emblem_count,
		"s_emblem_library::s_emblem_back",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_BACK_LIST_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_INDEX },
		FIELD_EXPLANATION("Layer 2 (background)", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_struct, "layer 2", &emblem_layer },
		{ _field_terminator }
	};

	#define EMBLEM_RUNTIME_FRONT_LIST_ID { 0x3B8760F9, 0x21E54DA1, 0xB61FE7D6, 0x960C88FB }
	TAG_BLOCK(
		emblem_runtime_front_list_block,
		"emblem_runtime_front_list",
		s_emblem_library::k_max_front_emblem_count,
		"s_emblem_library::s_emblem_front_runtime",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_RUNTIME_FRONT_LIST_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "name0" },

		{ _field_short_integer, "bitmap0_index" },
		{ _field_enum, "bitmap0_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap0_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_short_integer, "bitmap1_index" },
		{ _field_enum, "bitmap1_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap1_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_real_quaternion, "bitmap_transform0" },
		{ _field_real_quaternion, "bitmap_transform1" },
		{ _field_real_quaternion, "bitmap_transform2" },
		{ _field_real_quaternion, "bitmap_transform3" },
		{ _field_real_quaternion, "bitmap_params0" },
		{ _field_real_quaternion, "bitmap_params1" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "name1" },

		{ _field_short_integer, "bitmap2_index" },
		{ _field_enum, "bitmap2_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap2_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_short_integer, "bitmap3_index" },
		{ _field_enum, "bitmap3_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap3_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_real_quaternion, "bitmap_transform4" },
		{ _field_real_quaternion, "bitmap_transform5" },
		{ _field_real_quaternion, "bitmap_transform6" },
		{ _field_real_quaternion, "bitmap_transform7" },
		{ _field_real_quaternion, "bitmap_params2" },
		{ _field_real_quaternion, "bitmap_params3" },
		{ _field_char_enum, "primary layer", &front_emblem_primary_layer },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD("pad1", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define EMBLEM_RUNTIME_BACK_LIST_ID { 0xABFE5171, 0xF0184FFA, 0x8F2E9E1C, 0x87E32991 }
	TAG_BLOCK(
		emblem_runtime_back_list_block,
		"emblem_runtime_back_list",
		s_emblem_library::k_max_back_emblem_count,
		"s_emblem_library::s_emblem_runtime",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_RUNTIME_BACK_LIST_ID)
	{
		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "name" },

		{ _field_short_integer, "bitmap0_index" },
		{ _field_enum, "bitmap0_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap0_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_short_integer, "bitmap1_index" },
		{ _field_enum, "bitmap1_address_x", &render_method_bitmap_address_mode_enum },
		{ _field_enum, "bitmap1_address_y", &render_method_bitmap_address_mode_enum },
		{ _field_real_quaternion, "bitmap_transform0" },
		{ _field_real_quaternion, "bitmap_transform1" },
		{ _field_real_quaternion, "bitmap_transform2" },
		{ _field_real_quaternion, "bitmap_transform3" },
		{ _field_real_quaternion, "bitmap_params0" },
		{ _field_real_quaternion, "bitmap_params1" },
		{ _field_terminator }
	};

	#define EMBLEM_LIBRARY_STRUCT_DEFINITION_ID { 0x814BB579, 0x186448AC, 0x92B45BA7, 0x59274B33 }
	TAG_STRUCT(
		emblem_library_struct_definition,
		"emblem_library_struct_definition",
		"s_emblem_library",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | 
		SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_LIBRARY_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Emblem Library", nullptr, FIELD_FLAG_NONE, "This library contains the definitions of all the player emblems\nAll the compositions and transformations that build an emblem are defined in this tag.\nEach emblem is composed of a number of shapes.\nAnd each shape is defined by transformations on an emblem bitmap.\n"),
		{ _field_short_integer, "version", FIELD_FLAG_UNKNOWN0 },
		FIELD_PAD("jfejkjjg", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_CUSTOM("Bitmaps", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("Bitmaps", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_real, "bitmap resolution", "used to calculate appropriate antialiasing settings", "pixels" },
		{ _field_real, "antialias sharpen", "default 1.0, global control on antialias sharpness" },
		{ _field_tag_reference, "emblem bitmaps", &global_bitmap_reference },
		{ _field_tag_reference, "emblem bitmaps hi rez", &global_bitmap_reference },
		{ _field_block, "bitmaps", &emblem_bitmap_list_block },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_EXPLANATION("Shapes", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_block, "shapes", &emblem_shape_list_block },
		FIELD_EXPLANATION("Emblems", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_block, "front emblems", &emblem_front_list_block },
		{ _field_block, "back emblems", &emblem_back_list_block },
		{ _field_block, "runtime front", FIELD_FLAG_UNKNOWN0, &emblem_runtime_front_list_block },
		{ _field_block, "runtime back", FIELD_FLAG_UNKNOWN0, &emblem_runtime_back_list_block },
		{ _field_terminator }
	};

	#define EMBLEM_TRANSFORM_ID { 0x3B858486, 0xC9084CB7, 0xAA9ED045, 0x0801349C }
	TAG_STRUCT(
		emblem_transform,
		"emblem_transform",
		"s_emblem_library::s_transform",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_TRANSFORM_ID)
	{
		{ _field_real_point_2d, "scale" },
		{ _field_real_point_2d, "shear" },
		{ _field_real, "rotation" },
		{ _field_real_point_2d, "offset" },
		{ _field_real, "expand contract", "amount to expand (positive) or contract (negative) the shape outline" },
		{ _field_real, "blur", "amount to blur the shape outline" },
		{ _field_terminator }
	};

	#define EMBLEM_LAYER_ID { 0x60368EF4, 0xCA0A4F22, 0x9D380D1C, 0x9383D8C0 }
	TAG_STRUCT(
		emblem_layer,
		"emblem_layer",
		"s_emblem_library::s_layer",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		EMBLEM_LAYER_ID)
	{
		FIELD_EXPLANATION("Shape 0", nullptr, FIELD_FLAG_NONE, "Multiplier allows you to control how these shapes are combined.\nFor example, mult0= 1.0 and mult1= -1.0 causes shape 1 to be subtracted from shape 0.\n"),
		{ _field_short_block_index, "shape 0", &emblem_shape_list_block },
		FIELD_PAD("fkkfkll", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "multiplier 0" },
		{ _field_struct, "transform 0", &emblem_transform },
		FIELD_EXPLANATION("Shape 1", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_short_block_index, "shape 1", &emblem_shape_list_block },
		FIELD_PAD("fkkfkllf", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_real, "multiplier 1" },
		{ _field_struct, "transform 1", &emblem_transform },
		{ _field_terminator }
	};

	STRINGS(front_emblem_primary_layer)
	{
		"Layer 0 (foreground)",
		"Layer 1 (midground)"
	};
	STRING_LIST(front_emblem_primary_layer, front_emblem_primary_layer_strings, _countof(front_emblem_primary_layer_strings));

	TAG_REFERENCE(global_emblem_library_parameters_reference, EMBLEM_LIBRARY_TAG);

} // namespace macaque

} // namespace blofeld

