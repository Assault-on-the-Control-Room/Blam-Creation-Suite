#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		physics_model_group,
		PHYSICS_MODEL_TAG,
		nullptr,
		INVALID_TAG,
		physics_model_block );

	TAG_BLOCK_FROM_STRUCT(
		physics_model_block,
		"physics_model_block",
		1,
		physics_model_struct_definition);

	#define SPHERES_BLOCK_STRUCT_ID { 0xCDB1A7ED, 0x43BC4585, 0x97CCF77D, 0x018678C4 }
	TAG_BLOCK(
		spheres_block,
		"spheres_block",
		k_maximum_shapes_per_physics_model,
		"s_physics_model_sphere",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		SPHERES_BLOCK_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_primitive_struct },
		{ _field_struct, "sphere shape", &havok_convex_shape_struct },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "unknown padding", 4 },
		
		FIELD_PAD("algn344", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_struct, "translate shape", &havok_convex_translate_shape_struct },
		{ _field_terminator }
	};

	#define MATERIALS_BLOCK_ID { 0xAC367567, 0x39714E57, 0x9B17ED70, 0x20402724 }
	TAG_BLOCK(
		materials_block,
		"materials_block",
		k_maximum_materials_per_physics_model,
		"s_physics_model_material",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIALS_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_byte_flags, "flags", &physics_material_flags },
		FIELD_PAD("flags pad", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_string_id, "global material name" },
		{ _field_short_block_index, "phantom type", &phantom_types_block },
		FIELD_EXPLANATION("collision group override", nullptr, FIELD_FLAG_NONE, "This value overrides the default collision group.  It is overridden by any values specified rigid bodies block that overlap. Values set here can be overridden per shape through the shape primitive blocks."),
		{ _field_char_enum, "proxy collision group", &physics_material_proxy_collision_groups },
		{ _field_char_integer, "runtime collision group", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PHANTOM_TYPES_BLOCK_STRUCT_ID { 0xF2904025, 0x298545D0, 0x9C80A4E1, 0xCA6BA6FE }
	TAG_BLOCK(
		phantom_types_block,
		"phantom_types_block",
		k_maximum_phantom_types_per_physics_model,
		"s_physics_model_phantom_type",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHANTOM_TYPES_BLOCK_STRUCT_ID)
	{
		{ _field_long_flags, "flags", &PhantomFlagsV2 },
		{ _field_real, "brittle timer", "objects in this phantom volume will be set to brittle collision damage for this amount of time.", "seconds" },
		{ _field_char_enum, "minimum size", &rigid_body_size_enum },
		{ _field_char_enum, "maximum size", &rigid_body_size_enum },
		FIELD_PAD("OF", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "marker name", "you don't need this if you're just generating effects.  If empty it defaults to the up of the object" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "alignment marker name", "you don't need this if you're just generating effects.  If empty it defaults to \"marker name\"" },
		FIELD_EXPLANATION("Linear Motion", nullptr, FIELD_FLAG_NONE, "0 - means do nothing\nCENTER: motion towards marker position \nAXIS: motion towards marker axis, such that object is on the axis\nDIRECTION: motion along marker direction"),
		FIELD_PAD("WTBFO", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real, "hookes law e", "0 if you don't want this to behave like spring.  1 is a good starting point if you do." },
		{ _field_real, "linear dead radius", "radius from linear motion origin in which acceleration is dead." },
		{ _field_real, "center acc" },
		{ _field_real, "center max vel" },
		{ _field_real, "axis acc" },
		{ _field_real, "axis max vel" },
		{ _field_real, "direction acc" },
		{ _field_real, "direction max vel" },
		{ _field_real, "orbit acc", "negative values spin the opposite direction from positive ones" },
		{ _field_real, "orbit max vel" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		FIELD_PAD("TF", nullptr, FIELD_FLAG_NONE, 20),

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		FIELD_PAD("TF", nullptr, FIELD_FLAG_NONE, 28),

		FIELD_EXPLANATION("Angular Motion", nullptr, FIELD_FLAG_NONE, "0 - means do nothing\nALIGNMENT: algin objects in the phantom with the marker\nSPIN: spin the object about the marker axis"),
		{ _field_real, "alignment hookes law e", "0 if you don't want this to behave like spring.  1 is a good starting point if you do." },
		{ _field_real, "alignment acc" },
		{ _field_real, "alignment max vel" },
		FIELD_PAD("TYXJL", nullptr, FIELD_FLAG_NONE, 8),

		{ _field_terminator }
	};

	V5_TAG_STRUCT(havok_shape_struct_2010_2)
	{
		// hkBaseObject
		{ _field_legacy, _field_pointer, "field pointer skip!~" },

			// hkReferencedObject
		{ _field_legacy, _field_short_integer, "size*~!" },
		{ _field_legacy, _field_short_integer, "count*~!" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkReferencedObject 8byte alignment", 4 },

			// hkpShape
		{ _field_legacy, _field_pointer, "user data*~!" }, // TYPE_ULONG
		{ _field_legacy, _field_long_integer, "type*~!" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkpShape 8byte alignment", 4 },

		{ _field_legacy, _field_terminator }
	};

	#define PHANTOMS_BLOCK_STRUCT_ID { 0x9825B672, 0xFCDE4371, 0xA3E1D01A, 0xC83E8BD0 }
	TAG_BLOCK(
		phantoms_block,
		"phantoms_block",
		k_maximum_phantoms_per_physics_model,
		"s_physics_model_phantom",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		PHANTOMS_BLOCK_STRUCT_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "bv shape", &havok_shape_struct_2010_2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "bv shape", &havok_shape_struct },

		{ _field_struct, "havok shape reference struct1", &havok_shape_reference_struct },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" }, // likely "child size"

		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "child shape pointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_struct, "phantom shape", &havok_shape_struct_2010_2 },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "phantom shape", &havok_shape_struct },

		{ _field_terminator }
	};

	#define PILLS_BLOCK_STRUCT_ID { 0x0E2750B3, 0x8BBA4B7F, 0xADA773AF, 0x644AD79A }
	TAG_BLOCK(
		pills_block,
		"pills_block",
		k_maximum_shapes_per_physics_model,
		"s_physics_model_pill",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		PILLS_BLOCK_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_primitive_struct },
		{ _field_struct, "capsule shape", &havok_convex_shape_struct },

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		FIELD_PAD("algn243", nullptr, FIELD_FLAG_NONE, 12),
		
		{ _field_real_vector_3d, "bottom", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w bottom", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "top", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w top", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define LISTS_BLOCK_ID { 0xD663F86E, 0xB8D94D62, 0x922BA3C3, 0xBB29D488 }
	TAG_BLOCK(
		lists_block,
		"lists_block",
		k_maximum_rigid_bodies_per_physics_model,
		"s_physics_model_list",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		LISTS_BLOCK_ID,
		4)
	{
		{ _field_struct, "base", &havok_shape_collection_struct_2010_2 },

		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "child shapes size", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "child shapes capacity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("nail_in_dick", nullptr, FIELD_FLAG_NONE, 12), // lol

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		FIELD_PAD("8byte alignment", nullptr, FIELD_FLAG_NONE, 4),

		{ _field_real_vector_3d, "aabb half extents", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w aabb half extents", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "aabb center", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w aabb center", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "enabled children0" },
		{ _field_long_integer, "enabled children1" },
		{ _field_long_integer, "enabled children2" },
		{ _field_long_integer, "enabled children3" },
		{ _field_long_integer, "enabled children4" },
		{ _field_long_integer, "enabled children5" },
		{ _field_long_integer, "enabled children6" },
		{ _field_long_integer, "enabled children7" },
		{ _field_terminator }
	};

	#define LIST_SHAPES_BLOCK_STRUCT_ID { 0xB12BCE87, 0xDE7F4555, 0xAB450E06, 0x37A15489 }
	TAG_BLOCK(
		list_shapes_block,
		"list_shapes_block",
		k_maximum_list_shapes_per_physics_model,
		"hkpListShape::ChildInfo",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_NON_ALIASED),
		LIST_SHAPES_BLOCK_STRUCT_ID)
	{
		{ _field_struct, "shape reference", &havok_shape_reference_struct },
		{ _field_long_integer, "collision filter", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "shape size", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "num child shapes", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_DAMPED_SPRING_MOTOR_BLOCK_ID { 0x60496061, 0xD264415C, 0xAF53227C, 0x68D09DA9 }
	TAG_BLOCK(
		physics_model_damped_spring_motor_block,
		"physics_model_damped_spring_motor_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_damped_spring_motor",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_DAMPED_SPRING_MOTOR_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_real, "maximum force", "0 defaults to k_real_max" },
		{ _field_real, "minimum force", "0 defaults to maximum force.  In general you should leave this alone unless working on ragdolls or something like them" },
		{ _field_real, "spring k" },
		{ _field_real, "damping", "0 means default daming of 1.0f" },
		{ _field_real, "initial position" },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_POSITION_MOTOR_BLOCK_ID { 0xC0C65573, 0xE34244CE, 0xBFDAC94B, 0xF92ECE8C }
	TAG_BLOCK(
		physics_model_position_motor_block,
		"physics_model_position_motor_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_position_motor",
		SET_UNKNOWN0 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_POSITION_MOTOR_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_real, "maximum force" },
		{ _field_real, "minimum force", "0 defaults to maximum force.  In general you should leave this alone unless working on ragdolls or something like them" },
		{ _field_real, "tau", "from 0-1.  relative stiffness" },
		{ _field_real, "damping", "from 0-1" },
		{ _field_real, "proportion recover vel", "fraction of recover velocity used.  0 defaults to 1" },
		{ _field_real, "consant recover vel", "velocity used to recover when errors happen.  in degress per second" },
		{ _field_real, "initial position" },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_POWERED_CHAINS_BLOCK_ID { 0xABC31F9B, 0x1DEF46A0, 0x12354B86, 0x462CEBA3 }
	TAG_BLOCK(
		physics_model_powered_chains_block,
		"physics_model_powered_chains_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_powered_chain",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_POWERED_CHAINS_BLOCK_ID)
	{
		{ _field_block, "nodes", &physics_model_powered_chain_nodes_block },
		{ _field_block, "constraints", &physics_model_powered_chain_constraints_block },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_POWERED_CHAIN_NODES_BLOCK_ID { 0xBBC31F9B, 0x1DEF4AA0, 0x02354B86, 0x462AEBA3 }
	TAG_BLOCK(
		physics_model_powered_chain_nodes_block,
		"physics_model_powered_chain_nodes_block",
		MAXIMUM_NODES_PER_MODEL,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_POWERED_CHAIN_NODES_BLOCK_ID)
	{
		{ _field_short_block_index, "node", &nodes_block },
		{ _field_terminator }
	};

	#define NODES_BLOCK_ID { 0xF92912E1, 0xA4364CD1, 0xA65724A1, 0xBB8A252B }
	TAG_BLOCK(
		nodes_block,
		"nodes_block",
		MAXIMUM_NODES_PER_MODEL,
		"s_physics_model_node",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		NODES_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_word_flags, "flags", &nodes_flags },
		{ _field_short_block_index, "parent", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_short_block_index, "sibling", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_short_block_index, "child", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_POWERED_CHAIN_CONSTRAINTS_BLOCK_ID { 0xBB331F9B, 0x1CEF4AA0, 0x0A354B86, 0x462AEBB3 }
	TAG_BLOCK(
		physics_model_powered_chain_constraints_block,
		"physics_model_powered_chain_constraints_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_powered_chain_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_POWERED_CHAIN_CONSTRAINTS_BLOCK_ID)
	{
		{ _field_enum, "constraint type", &rigid_constraint_types_enum },
		{ _field_custom_short_block_index, "constraint index" },
		{ _field_struct, "motor x", &physics_model_motor_reference_struct },
		{ _field_struct, "motor y", &physics_model_motor_reference_struct },
		{ _field_struct, "motor z", &physics_model_motor_reference_struct },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_NODE_CONSTRAINT_EDGE_BLOCK_ID { 0x1E831F9B, 0x155146A0, 0x9A054B86, 0x462C1033 }
	TAG_BLOCK(
		physics_model_node_constraint_edge_block,
		"physics_model_node_constraint_edge_block",
		k_maximum_node_constraint_edges_per_physics_model,
		"s_physics_model_node_constraint_edge",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_NODE_CONSTRAINT_EDGE_BLOCK_ID)
	{
		{ _field_short_integer, "runtime material type a", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_integer, "runtime material type b", FIELD_FLAG_UNKNOWN0 },
		{ _field_short_block_index, "node a", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_short_block_index, "node b", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_block, "constraints", FIELD_FLAG_READ_ONLY, &physics_model_constraint_edge_constraint_block },
		{ _field_string_id, "node a material", "if you don't fill this out we will pluck the material from the first primitive, of the first rigid body attached to node a" },
		{ _field_string_id, "node b material", "if you don't fill this out we will pluck the material from the first primitive, of the first rigid body attached to node b, if node b is none we use whatever material a has" },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_CONSTRAINT_EDGE_CONSTRAINT_BLOCK_ID { 0x47C5C654, 0x707F4F7B, 0x956BA9B5, 0xAC3E2279 }
	TAG_BLOCK(
		physics_model_constraint_edge_constraint_block,
		"physics_model_constraint_edge_constraint_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_node_constraint_edge_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_CONSTRAINT_EDGE_CONSTRAINT_BLOCK_ID)
	{
		{ _field_enum, "type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &rigid_constraint_types_enum },
		{ _field_custom_short_block_index, "index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_flags, "flags", &rigid_body_constraint_edge_constraint_flags_definition },
		{ _field_real, "friction", "0 is the default (takes what it was set in max) anything else overrides that value" },
		{ _field_block, "ragdoll motors", &physics_model_ragdoll_motors_block },
		{ _field_block, "limited hinge motors", &physics_model_limited_hinge_motors_block },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_RAGDOLL_MOTORS_BLOCK_ID { 0x62A96AB5, 0x48164E64, 0xA529F07B, 0x62FA3B40 }
	TAG_BLOCK(
		physics_model_ragdoll_motors_block,
		"physics_model_ragdoll_motors_block",
		1,
		"s_physics_model_ragdoll_motors",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_RAGDOLL_MOTORS_BLOCK_ID)
	{
		FIELD_EXPLANATION("twist", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "twist motor", &physics_model_motor_reference_struct },
		FIELD_EXPLANATION("cone", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "cone motor", &physics_model_motor_reference_struct },
		FIELD_EXPLANATION("plane", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "plane motor", &physics_model_motor_reference_struct },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_LIMITED_HINGE_MOTORS_BLOCK_ID { 0xB4F83810, 0x94E14E38, 0x95347376, 0xA5785B3A }
	TAG_BLOCK(
		physics_model_limited_hinge_motors_block,
		"physics_model_limited_hinge_motors_block",
		1,
		"s_physics_model_limited_hinge_motors",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_LIMITED_HINGE_MOTORS_BLOCK_ID)
	{
		{ _field_struct, "motor", &physics_model_motor_reference_struct },
		{ _field_terminator }
	};

	#define RIGID_BODIES_BLOCK_ID { 0xF902EE13, 0xFEA643C7, 0x9C90BED0, 0xF9D06754 }
	TAG_BLOCK(
		rigid_bodies_block,
		"rigid_bodies_block",
		k_maximum_rigid_bodies_per_physics_model,
		"rigid_bodies_block",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		RIGID_BODIES_BLOCK_ID,
		4)
	{
		{ _field_short_block_index, "node", FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_short_block_index, "region", FIELD_FLAG_READ_ONLY, &regions_block },
		{ _field_custom_short_block_index, "permutattion", FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "serialized shapes", FIELD_FLAG_READ_ONLY, &RigidBodySerializedShapesBlock_block },
		{ _field_real_point_3d, "bouding sphere offset", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "bounding sphere radius", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_word_flags, "flags", &rigid_body_flags },
		{ _field_short_block_index, "no phantom power alt", &rigid_bodies_block },
		{ _field_char_enum, "motion type", &rigid_body_motion_enum },
		FIELD_EXPLANATION("collision group override", nullptr, FIELD_FLAG_NONE, "This value overrides the default group.  It also overrides values specified in the materials block of this tag. Values set here can be overridden per shape through the shape primitive blocks."),
		{ _field_char_enum, "proxy collision group", &physics_material_proxy_collision_groups },
		{ _field_enum, "size", &rigid_body_size_enum },
		FIELD_EXPLANATION("inertia tensor scales", nullptr, FIELD_FLAG_NONE, "if you want to set he scale uniforml just set \"inertia tensor scale\".  If you want to set the values seperately per axis you can set \"inertia tensor scale x\\y\\z\""),
		{ _field_real, "inertia tensor scale", "0.0 defaults to 1.0" },
		{ _field_real, "inertia tensor scale x", "0.0 defaults to 1.0" },
		{ _field_real, "inertia tensor scale y", "0.0 defaults to 1.0" },
		{ _field_real, "inertia tensor scale z", "0.0 defaults to 1.0" },
		{ _field_real, "linear damping", "this goes from 0-10 (10 is really, really high)" },
		{ _field_real, "angular damping", "this goes from 0-10 (10 is really, really high)" },
		{ _field_real_vector_3d, "center off mass offset" },
		FIELD_EXPLANATION("water physics bounding box", nullptr, FIELD_FLAG_NONE, "if any of these fields are non-zero, this overrides the bounding box used for water physics"),
		{ _field_real, "water physics x0", "x0 value of the water physics aabb" },
		{ _field_real, "water physics x1", "x1 value of the water physics aabb" },
		{ _field_real, "water physics y0", "y0 value of the water physics aabb" },
		{ _field_real, "water physics y1", "y1 value of the water physics aabb" },
		{ _field_real, "water physics z0", "z0 value of the water physics aabb" },
		{ _field_real, "water physics z1", "z1 value of the water physics aabb" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_pointer, "Runtime Shape Pointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "padding", 4 },

		{ _field_real_vector_3d, "center of mass", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w center of mass", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "intertia tensor x", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w intertia tensor x", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "intertia tensor y", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w intertia tensor y", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "intertia tensor z", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w intertia tensor z", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "runtime havok group mask ", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "padding", 4 },

		{ _field_struct, "shape reference", &havok_shape_reference_struct },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_long_integer, "unknown" }, // likely "child size"

		{ _field_real, "mass", nullptr, "kg", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "bounding sphere pad", "the bounding sphere for this rigid body will be outset by this much" },
		{ _field_char_enum, "collision quality override type", &rigid_body_collision_quality_enum },
		FIELD_PAD("pad3", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_short_integer, "runtime_flags", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_EXPLANATION("Stupid mass override", nullptr, FIELD_FLAG_NONE, "If you want to override what the calculated mass distribution or artist set mass is, this is where you do it. Also, this will show up as n/100 in the game debugger. Awesome."),
		{ _field_real, "Mass body override" },
		FIELD_PAD("pad4", nullptr, FIELD_FLAG_NONE, 8),

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_legacy, _field_pad, "unknown", 8 }, // assumed

		{ _field_terminator }
	};

	#define REGIONS_BLOCK_ID { 0x43CF00C4, 0x48FA425D, 0x9F3945E3, 0xC0CC414D }
	TAG_BLOCK(
		regions_block,
		"regions_block",
		MAXIMUM_REGIONS_PER_MODEL,
		"s_physics_model_region",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		REGIONS_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "permutations", &permutations_block },
		{ _field_terminator }
	};

	#define PERMUTATIONS_BLOCK_ID { 0xB9073D8F, 0x99774226, 0x951F4436, 0x864FD834 }
	TAG_BLOCK(
		permutations_block,
		"permutations_block",
		MAXIMUM_PERMUTATIONS_PER_MODEL_REGION,
		"s_physics_model_permutation",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PERMUTATIONS_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_block, "rigid bodies", &rigid_body_indices_block },
		{ _field_terminator }
	};

	#define RIGID_BODY_INDICES_BLOCK_ID { 0xC6210EEA, 0x4B0D46CA, 0xB5ECB5CE, 0xFCB173A7 }
	TAG_BLOCK(
		rigid_body_indices_block,
		"rigid_body_indices_block",
		k_maximum_rigid_bodies_per_physics_model,
		"short",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RIGID_BODY_INDICES_BLOCK_ID)
	{
		{ _field_short_block_index, "rigid body", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX, &rigid_bodies_block },
		{ _field_terminator }
	};

	#define RIGIDBODYSERIALIZEDSHAPESBLOCK_ID { 0x7AF718AD, 0x225C48BE, 0xB2985BDF, 0x8251524D }
	TAG_BLOCK(
		RigidBodySerializedShapesBlock_block,
		"RigidBodySerializedShapesBlock",
		k_maximum_shapes_per_physics_model,
		"RigidBodySerializedShapes",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RIGIDBODYSERIALIZEDSHAPESBLOCK_ID)
	{
		{ _field_block, "Mopp Serialized Havok Data", &MoppSerializedHavokDataBlock_block },
		{ _field_terminator }
	};

	#define MOPPSERIALIZEDHAVOKDATABLOCK_ID { 0x93514036, 0x6411412D, 0x9DFEAC70, 0x1D84C668 }
	TAG_BLOCK(
		MoppSerializedHavokDataBlock_block,
		"MoppSerializedHavokDataBlock",
		k_maximum_rigid_bodies_per_physics_model,
		"MoppSerializedHavokData",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		MOPPSERIALIZEDHAVOKDATABLOCK_ID)
	{
		{ _field_struct, "base", &havok_primitive_struct },
		{ _field_long_integer, "version", FIELD_FLAG_READ_ONLY },
		{ _field_pointer, "Runtime Deserialized Shape Pointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_data, "Serialized Havok Data", FIELD_FLAG_READ_ONLY },
		{ _field_data, "Serialized Havok Data Any Temp", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define MULTI_SPHERES_BLOCK_STRUCT_ID { 0x2190C1C0, 0xB31C4810, 0x88FABD1C, 0x7E8CF19D }
	TAG_BLOCK(
		multi_spheres_block,
		"multi_spheres_block",
		k_maximum_shapes_per_physics_model,
		"s_physics_model_multi_sphere",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		MULTI_SPHERES_BLOCK_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_primitive_struct },
		{ _field_struct, "sphere rep shape", &havok_shape_struct },
		{ _field_long_integer, "num spheres", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("bull434", nullptr, FIELD_FLAG_NONE, 12),
		{ _field_array, "four vectors storage", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &multi_sphere_vector_storage_array },
		{ _field_terminator }
	};

	#define BOXES_BLOCK_STRUCT_ID { 0xD726D425, 0x6D9147FF, 0xB52DC314, 0xEBCCB77C }
	TAG_BLOCK(
		boxes_block,
		"boxes_block",
		k_maximum_shapes_per_physics_model,
		"s_physics_model_box",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		BOXES_BLOCK_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_primitive_struct },
		{ _field_struct, "box shape", &havok_convex_shape_struct },

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		FIELD_PAD("algn3473", nullptr, FIELD_FLAG_NONE, 12),

		{ _field_real_vector_3d, "half extents", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w half extents", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_struct, "convex transform shape", &havok_convex_transform_shape_struct },

		{ _field_terminator }
	};

	#define TRIANGLES_BLOCK_STRUCT_ID { 0x28B29A3B, 0x475246DE, 0xA5371B35, 0x9316A629 }
	TAG_BLOCK(
		triangles_block,
		"triangles_block",
		k_maximum_shapes_per_physics_model,
		"s_physics_model_triangle",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		TRIANGLES_BLOCK_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_primitive_struct },
		{ _field_struct, "triangle shape", &havok_convex_shape_struct_2010_2 },
		{ _field_short_integer, "welding info", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "welding type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "is extruded", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("algn92", nullptr, FIELD_FLAG_NONE, 8),
		{ _field_real_vector_3d, "point a", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w point a", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "point b", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w point b", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "point c", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w point c", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "extrusion", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w extrusion", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define POLYHEDRA_BLOCK_STRUCT_ID { 0xF4968889, 0xF5C145D7, 0x99A8D99E, 0x17508FB6 }
	TAG_BLOCK(
		polyhedra_block,
		"polyhedra_block",
		k_maximum_shapes_per_physics_model,
		"s_physics_model_polyhedron",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		POLYHEDRA_BLOCK_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_primitive_struct },
		{ _field_struct, "polyhedron shape", &havok_convex_shape_struct },

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		FIELD_PAD("algn743", nullptr, FIELD_FLAG_NONE, 12),

		// aabbHalfExtents
		{ _field_real_vector_3d, "aabb half extents", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w aabb half extents", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		// aabbCenter
		{ _field_real_vector_3d, "aabb center", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w aabb center", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		// rotatedVertices
		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "four vectors size", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "four vectors capacity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		// numVertices
		{ _field_long_integer, "num vertices", FIELD_FLAG_READ_ONLY },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkReferencedObject 8byte alignment", 4 },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach },
		// convexPiece
		{ _field_legacy, _field_pointer, "convex piece pointer skip!~" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		// useSpuBuffer
		{ _field_char_integer, "m_useSpuBuffer", FIELD_FLAG_READ_ONLY },
		FIELD_PAD("algn434", nullptr, FIELD_FLAG_NONE, 3),

		// hkArray planeEquations
		{ _field_pointer, "another field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "plane equations size", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "plane equations capacity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_pointer, "connectivity", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_POINTER, _field_id_zero_data },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		FIELD_PAD("SAMTRA", nullptr, FIELD_FLAG_NONE, 8),

		{ _field_legacy, _field_version_platform_exclude, _platform_type_pc },
		FIELD_PAD("SAMTRA", nullptr, FIELD_FLAG_NONE, 12),

		{ _field_terminator }
	};

	#define POLYHEDRON_FOUR_VECTORS_BLOCK_ID { 0x919AD72B, 0xA3A24A74, 0xAC7F3BB6, 0x43B76BC1 }
	TAG_BLOCK(
		polyhedron_four_vectors_block,
		"polyhedron_four_vectors_block",
		k_maximum_four_vectors_per_physics_model,
		"hkVector4",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		POLYHEDRON_FOUR_VECTORS_BLOCK_ID,
		4)
	{
		{ _field_real_vector_3d, "four vectors x", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w four vectors x", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "four vectors y", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w four vectors y", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "four vectors z", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w four vectors z", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define POLYHEDRON_PLANE_EQUATIONS_BLOCK_ID { 0x6C2FB23C, 0xBA2C4042, 0xBFBACDF2, 0x2191CAB5 }
	TAG_BLOCK(
		polyhedron_plane_equations_block,
		"polyhedron_plane_equations_block",
		k_maximum_plane_equations_per_physics_model,
		"hkVector4",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		POLYHEDRON_PLANE_EQUATIONS_BLOCK_ID,
		4)
	{
		{ _field_real_vector_3d, "plane equations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w plane equations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define MASS_DISTRIBUTIONS_BLOCK_ID { 0xD795D66A, 0x38FD48C4, 0x9283011C, 0xB7D8ACA0 }
	TAG_BLOCK(
		mass_distributions_block,
		"mass_distributions_block",
		k_maximum_inertia_tensors_per_physics_model,
		"s_physics_model_mass_distribution",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MASS_DISTRIBUTIONS_BLOCK_ID,
		4)
	{
		{ _field_real_vector_3d, "center of mass", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w center of mass", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "inertia tensor i", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w inertia tensor i", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "inertia tensor j", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w inertia tensor j", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "inertia tensor k", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w inertia tensor k", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define MOPPS_BLOCK_STRUCT_ID { 0xE4F5D223, 0x227240B1, 0xA6CE731C, 0x47D19CDC }
	TAG_BLOCK(
		mopps_block,
		"mopps_block",
		k_maximum_rigid_bodies_per_physics_model,
		"s_physics_model_mopp",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		MOPPS_BLOCK_STRUCT_ID,
		4)
	{
		{ _field_struct, "base", &havok_shape_struct },
		FIELD_PAD("m_bvTreeType", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD("3 other bytes", nullptr, FIELD_FLAG_NONE, 3),

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		// hkMoppBvTreeShapeBase
		{ _field_pointer, "mopp code pointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_pointer, "mopp data skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_long_integer, "mopp data size", FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		{ _field_real_vector_3d, "m_codeInfoCopy", FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w m_codeInfoCopy", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },

		// hkpSingleShapeContainer
		{ _field_pointer, "child shape vtable", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_struct, "childShapePointer", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3, &havok_shape_reference_struct },
		{ _field_long_integer, "child size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "8byte alignment", 4 },

		FIELD_PAD("mopp alignment", nullptr, FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, 4),
		{ _field_real, "scale", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("final alignment", nullptr, FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3, 12),

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "16 byte align pad", 8 },

		{ _field_terminator }
	};

	#define HINGE_CONSTRAINTS_BLOCK_ID { 0xAF7DC3D5, 0x530140B4, 0x91B125D8, 0x62093ACB }
	TAG_BLOCK(
		hinge_constraints_block,
		"hinge_constraints_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_hinge_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HINGE_CONSTRAINTS_BLOCK_ID)
	{
		{ _field_struct, "constraint bodies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &constraint_bodies_struct },
		FIELD_PAD("JENFOXHY", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	#define RAGDOLL_CONSTRAINTS_BLOCK_ID { 0x71F3DE11, 0xA1B24FB1, 0xAEBDF8E1, 0x2005975C }
	TAG_BLOCK(
		ragdoll_constraints_block,
		"ragdoll_constraints_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_ragdoll_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		RAGDOLL_CONSTRAINTS_BLOCK_ID)
	{
		{ _field_struct, "constraint bodies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &constraint_bodies_struct },
		FIELD_PAD("OVIM", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "min twist", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "max twist", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "min cone", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "max cone", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "min plane", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "max plane", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "max friciton torque", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define POINT_TO_PATH_CURVE_BLOCK_ID { 0x295B83E5, 0x915B4FEA, 0xB9C37400, 0xF93E5BD0 }
	TAG_BLOCK(
		point_to_path_curve_block,
		"point_to_path_curve_block",
		k_maximum_rigid_bodies_per_physics_model,
		"s_physics_model_point_to_path_curve",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		POINT_TO_PATH_CURVE_BLOCK_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_block_index, "node index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		FIELD_PAD("TNLRSOSY", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_block, "points", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &point_to_path_curve_point_block },
		{ _field_terminator }
	};

	#define POINT_TO_PATH_CURVE_POINT_BLOCK_ID { 0x7D8769F4, 0xBCD646C2, 0x99D3A2DC, 0x900FAE2F }
	TAG_BLOCK(
		point_to_path_curve_point_block,
		"point_to_path_curve_point_block",
		1024,
		"s_physics_model_point_to_path_curve_point",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		POINT_TO_PATH_CURVE_POINT_BLOCK_ID)
	{
		{ _field_real_point_3d, "position", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "t value", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define LIMITED_HINGE_CONSTRAINTS_BLOCK_ID { 0xCA7D0DCC, 0x98DD4A69, 0x99C928CE, 0xB478F286 }
	TAG_BLOCK(
		limited_hinge_constraints_block,
		"limited_hinge_constraints_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_limited_hinge_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		LIMITED_HINGE_CONSTRAINTS_BLOCK_ID)
	{
		{ _field_struct, "constraint bodies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &constraint_bodies_struct },
		FIELD_PAD("TC", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "limit friction", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "limit min angle", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "limit max angle", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define BALL_AND_SOCKET_CONSTRAINTS_BLOCK_ID { 0x96EF29F8, 0xD4CB4C71, 0x8E24795D, 0xBC63D57D }
	TAG_BLOCK(
		ball_and_socket_constraints_block,
		"ball_and_socket_constraints_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_ball_and_socket_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		BALL_AND_SOCKET_CONSTRAINTS_BLOCK_ID)
	{
		{ _field_struct, "constraint bodies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &constraint_bodies_struct },
		FIELD_PAD("UPDLSKB", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_terminator }
	};

	#define STIFF_SPRING_CONSTRAINTS_BLOCK_ID { 0xB171A408, 0xC3E44FA9, 0x9B290904, 0xF448E781 }
	TAG_BLOCK(
		stiff_spring_constraints_block,
		"stiff_spring_constraints_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_stiff_spring_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STIFF_SPRING_CONSTRAINTS_BLOCK_ID)
	{
		{ _field_struct, "constraint bodies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &constraint_bodies_struct },
		FIELD_PAD("KGB", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "spring_length", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PRISMATIC_CONSTRAINTS_BLOCK_ID { 0x6514A948, 0x92AC4D16, 0x807D1F7F, 0x6DF5D8A4 }
	TAG_BLOCK(
		prismatic_constraints_block,
		"prismatic_constraints_block",
		k_maximum_constraints_per_physics_model,
		"s_physics_model_prismatic_constraint",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PRISMATIC_CONSTRAINTS_BLOCK_ID)
	{
		{ _field_struct, "constraint bodies", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &constraint_bodies_struct },
		FIELD_PAD("XVEPD", nullptr, FIELD_FLAG_NONE, 4),
		{ _field_real, "min_limit", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "max_limit", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "max_friction_force", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define MULTI_SPHERE_VECTOR_STORAGE_ID { 0xC2F4C73E, 0xD6904055, 0xB0613D10, 0x58830BA2 }
	TAG_ARRAY(
		multi_sphere_vector_storage_array,
		"multi_sphere_vector_storage",
		8,
		"hkVector4",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MULTI_SPHERE_VECTOR_STORAGE_ID)
	{
		{ _field_real_vector_3d, "sphere", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w sphere", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define PHYSICS_MODEL_STRUCT_DEFINITION_ID { 0xB3439E17, 0x0DDD4542, 0xB8B59423, 0x9665EE90 }
	TAG_STRUCT(
		physics_model_struct_definition,
		"physics_model_struct_definition",
		"physics_model_struct_definition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | 
		SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &physics_model_flags },
		{ _field_real, "mass scale", "scales the mass of each rigid body.  If you leave this field as 0, then it will be calculated from the total mass below." },
		{ _field_real, "mass", "override total mass of all rigid bodies.  Note that this will NOT be the mass of the object if not all rigid bodies are present (for example if you are using permutations)\nIf you set a mass scale above, this field is unused." },
		{ _field_real, "low freq. deactivation scale", "0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." },
		{ _field_real, "high freq. deactivation scale", "0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." },
		{ _field_real, "custom shape radius", "0 defaults to .016.  This field is intentionally hidden because we should only alter this for very special situations.  Lower number == lower performance", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "maximum penetration depth scale", "0 is default (1). for objects that are prone to falling through the world we can reduce this number at the cost of performance" },
		{ _field_char_integer, "import version", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		FIELD_PAD("pad0", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_block, "damped spring motors", &physics_model_damped_spring_motor_block },
		{ _field_block, "position motors", &physics_model_position_motor_block },
		{ _field_block, "phantom types", &phantom_types_block },
		{ _field_block, "powered chains", &physics_model_powered_chains_block },
		{ _field_block, "node edges", FIELD_FLAG_READ_ONLY, &physics_model_node_constraint_edge_block },
		{ _field_block, "rigid bodies", FIELD_FLAG_READ_ONLY, &rigid_bodies_block },
		{ _field_block, "materials", FIELD_FLAG_READ_ONLY, &materials_block },
		{ _field_block, "spheres", FIELD_FLAG_READ_ONLY, &spheres_block },
		{ _field_block, "multi spheres", FIELD_FLAG_READ_ONLY, &multi_spheres_block },
		{ _field_block, "pills", FIELD_FLAG_READ_ONLY, &pills_block },
		{ _field_block, "boxes", FIELD_FLAG_READ_ONLY, &boxes_block },
		{ _field_block, "triangles", FIELD_FLAG_READ_ONLY, &triangles_block },
		{ _field_block, "polyhedra", FIELD_FLAG_READ_ONLY, &polyhedra_block },
		{ _field_block, "polyhedron four vectors", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &polyhedron_four_vectors_block },
		{ _field_block, "polyhedron plane equations", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &polyhedron_plane_equations_block },
		{ _field_block, "mass distributions", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &mass_distributions_block },
		{ _field_block, "lists", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &lists_block },
		{ _field_block, "list shapes", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &list_shapes_block },
		{ _field_block, "mopps", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &mopps_block },
		{ _field_data, "mopp codes", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_block, "hinge constraints", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &hinge_constraints_block },
		{ _field_block, "ragdoll constraints", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &ragdoll_constraints_block },
		{ _field_block, "regions", FIELD_FLAG_READ_ONLY, &regions_block },
		{ _field_block, "nodes", FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_block, "errors", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &global_error_report_categories_block },
		{ _field_block, "point to path curves", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &point_to_path_curve_block },
		{ _field_block, "limited hinge constraints", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &limited_hinge_constraints_block },
		{ _field_block, "ball and socket constraints", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &ball_and_socket_constraints_block },
		{ _field_block, "stiff spring constraints", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &stiff_spring_constraints_block },
		{ _field_block, "prismatic constraints", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &prismatic_constraints_block },
		{ _field_block, "phantoms", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &phantoms_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach },
		{ _field_block, "RigidBody Serialized Shapes", FIELD_FLAG_READ_ONLY, &RigidBodySerializedShapesBlock_block },

		{ _field_terminator }
	};

	#define HAVOK_PRIMITIVE_STRUCT_ID { 0xEA25BEF8, 0x01384DFD, 0x886C4497, 0x7BE57757 }
	TAG_STRUCT(
		havok_primitive_struct,
		"havok_primitive_struct",
		"s_physics_model_primitive",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE),
		HAVOK_PRIMITIVE_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_char_block_index, "material", FIELD_FLAG_READ_ONLY, &materials_block },
		{ _field_byte_flags, "material flags", FIELD_FLAG_READ_ONLY, &physics_material_flags },
		{ _field_short_integer, "runtime material type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_real, "relative mass scale" },
		{ _field_real_fraction, "friction" },
		{ _field_real_fraction, "restitution" },
		{ _field_real, "volume ", FIELD_FLAG_READ_ONLY },
		{ _field_real, "mass", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "mass distribution index", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_block_index, "phantom", FIELD_FLAG_READ_ONLY, &phantoms_block },
		FIELD_EXPLANATION("collision group override", nullptr, FIELD_FLAG_NONE, "This value overrides the default group, model, and rigid body."),
		{ _field_char_enum, "proxy collision group", &physics_material_proxy_collision_groups },
		{ _field_terminator }
	};

	#define HAVOK_SHAPE_STRUCT_ID { 0x2957D592, 0x3C7D4521, 0x830D6134, 0x29B7361B }
	TAG_STRUCT(
		havok_shape_struct,
		"havok_shape_struct",
		"hkpShape",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_SHAPE_STRUCT_ID)
	{
		// hkBaseObject
		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },

			// hkReferencedObject
		{ _field_short_integer, "size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkReferencedObject 8byte alignment", 4 },

		{ _field_char_integer, "type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_char_integer, "dispatchType", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_char_integer, "bitsPerKey", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_char_integer, "codecType", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkReferencedObject 8byte alignment", 4 },

		{ _field_pointer, "user data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_terminator }
	};

	#define HAVOK_SHAPE_REFERENCE_STRUCT_ID { 0x573EF14C, 0x91AC4F07, 0xA1702B47, 0x7875B0E0 }
	TAG_STRUCT(
		havok_shape_reference_struct,
		"havok_shape_reference_struct",
		"hkpShape *",
		SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_SHAPE_REFERENCE_STRUCT_ID)
	{
		{ _field_enum, "shape type", FIELD_FLAG_READ_ONLY | FIELD_FLAG_POINTER, &shape_enum },
		{ _field_custom_short_block_index, "shape", FIELD_FLAG_READ_ONLY | FIELD_FLAG_POINTER },
		{ _field_terminator }
	};

	#define HAVOK_CONVEX_SHAPE_STRUCT_ID { 0x65BCED0A, 0xC7424242, 0x98E46503, 0x0E2E0DDA }
	TAG_STRUCT(
		havok_convex_shape_struct,
		"havok_convex_shape_struct",
		"hkpConvexShape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_CONVEX_SHAPE_STRUCT_ID)
	{
		{ _field_struct, "base", &havok_shape_struct },
		{ _field_real, "radius", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define HAVOK_CONVEX_TRANSLATE_SHAPE_STRUCT_ID { 0xCB9F81C2, 0x7F4B47B5, 0x8FE0AB7C, 0x8BB17123 }
	TAG_STRUCT(
		havok_convex_translate_shape_struct,
		"havok_convex_translate_shape_struct",
		"hkpConvexTranslateShape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_CONVEX_TRANSLATE_SHAPE_STRUCT_ID)
	{
		{ _field_struct, "convex", &havok_convex_shape_struct },
		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_struct, "havok shape reference struct", &havok_shape_reference_struct },
		{ _field_long_integer, "child shape size" },
		{ _field_real_vector_3d, "translation", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w translation", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define HAVOK_SHAPE_COLLECTION_STRUCT_2010_2_ID { 0xDD6DCE26, 0x88D54E3D, 0x87B805A2, 0xD7E20D10 }
	TAG_STRUCT(
		havok_shape_collection_struct_2010_2,
		"havok_shape_collection_struct_2010_2",
		"hkpShapeCollection_hk2010_2",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_SHAPE_COLLECTION_STRUCT_2010_2_ID)
	{
		{ _field_struct, "base", &havok_shape_struct_2010_2 },
		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_char_integer, "disable welding", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_char_integer, "collection type", FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		FIELD_PAD("VDVAPBSS", nullptr, FIELD_FLAG_NONE, 2),

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkReferencedObjectClass 8byte alignment", 4 },

		{ _field_terminator }
	};

	#define HAVOK_SHAPE_STRUCT_2010_2_ID { 0xCC42E7A1, 0x996A46EB, 0xA0A3AB5E, 0x7120F79C }
	TAG_STRUCT(
		havok_shape_struct_2010_2,
		"havok_shape_struct_2010_2",
		"hkpShape_hk2010_2",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_SHAPE_STRUCT_2010_2_ID)
	{
		// hkBaseObject
		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },

		// hkReferencedObject
		{ _field_short_integer, "size", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },
		{ _field_short_integer, "count", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkReferencedObject 8byte alignment", 4 },

		// hkpShape
		{ _field_pointer, "user data", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 }, // TYPE_ULONG
		{ _field_long_integer, "type", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_UNKNOWN3 },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc },
		{ _field_legacy, _field_pad, "hkpShape 8byte alignment", 4 },

		{ _field_terminator }
	};

	#define PHYSICS_MODEL_MOTOR_REFERENCE_STRUCT_ID { 0xAB7B559D, 0x0D744412, 0x84CDF67A, 0x370BCC34 }
	TAG_STRUCT(
		physics_model_motor_reference_struct,
		"physics_model_motor_reference_struct",
		"s_physics_model_motor_reference",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		PHYSICS_MODEL_MOTOR_REFERENCE_STRUCT_ID)
	{
		{ _field_enum, "motor type", &physics_model_motor_types_enum },
		{ _field_custom_short_block_index, "index" },
		{ _field_terminator }
	};

	#define HAVOK_CONVEX_TRANSFORM_SHAPE_STRUCT_ID { 0x13B806D5, 0x795947E2, 0xBB5E8C84, 0x747D768C }
	TAG_STRUCT(
		havok_convex_transform_shape_struct,
		"havok_convex_transform_shape_struct",
		"hkpConvexTransformShape",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_UNKNOWN15,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_CONVEX_TRANSFORM_SHAPE_STRUCT_ID)
	{
		{ _field_struct, "convex", &havok_convex_shape_struct },
		{ _field_pointer, "field pointer skip", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_UNKNOWN3 | FIELD_FLAG_POINTER, _field_id_zero_data },
		{ _field_struct, "havok shape reference struct", &havok_shape_reference_struct },
		{ _field_long_integer, "child shape size" },
		{ _field_real_vector_3d, "rotation i", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w rotation i", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "rotation j", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w rotation j", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "rotation k", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w rotation k", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "translation", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "havok w translation", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define HAVOK_CONVEX_SHAPE_STRUCT_2010_2_ID { 0x47913899, 0x5D904202, 0x851C913C, 0xE4EB9434 }
	TAG_STRUCT(
		havok_convex_shape_struct_2010_2,
		"havok_convex_shape_struct_2010_2",
		"hkpConvexShape_hk2010_2",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_WRITEABLE | TAG_MEMORY_USAGE_NON_ALIASED),
		HAVOK_CONVEX_SHAPE_STRUCT_2010_2_ID)
	{
		{ _field_struct, "base", &havok_shape_struct_2010_2 },
		{ _field_real, "radius", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define CONSTRAINT_BODIES_STRUCT_ID { 0x8C776F54, 0x79CD4488, 0xA821DD34, 0xBD455BC0 }
	TAG_STRUCT(
		constraint_bodies_struct,
		"constraint_bodies_struct",
		"s_physics_model_constraint_bodies",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CONSTRAINT_BODIES_STRUCT_ID)
	{
		{ _field_string_id, "name", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_short_block_index, "node a", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_short_block_index, "node b", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &nodes_block },
		{ _field_real, "a scale", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "a forward", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "a left", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "a up", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "a position", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real, "b scale", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "b forward", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "b left", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_vector_3d, "b up", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_real_point_3d, "b position", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_short_block_index, "edge index", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &physics_model_node_constraint_edge_block },
		FIELD_PAD("H", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	STRINGS(physics_material_flags)
	{
		"supresses effects",
		"force enable collision with player#enables collision with the player regardless of the collision group"
	};
	STRING_LIST(physics_material_flags, physics_material_flags_strings, _countof(physics_material_flags_strings));

	STRINGS(PhantomFlagsV2)
	{
		"UNUSED",
		"use acc as force",
		"negates gravity",
		"ignores players",
		"ignores nonplayers",
		"ignores bipeds",
		"ignores vehicles",
		"ignores weapons",
		"ignores equipment",
		"ignores projectiles",
		"ignores scenery",
		"ignores devices",
		"ignores crates",
		"ignores creatures",
		"ignores giants",
		"ignores spawners",
		"ignores mechs",
		"ignores team objects",
		"smart directional acceleration",
		"ignores grounded bipeds",
		"localizes physics",
		"disable linear damping",
		"disable angular damping",
		"ignores dead bipeds",
		"ignores live bipeds",
		"reciprocal acc",
		"reciprocal acc ONLY",
		"latching disabled",
		"mirrored axis",
		"activate ragdolls",
		"ignores forge editor"
	};
	STRING_LIST(PhantomFlagsV2, PhantomFlagsV2_strings, _countof(PhantomFlagsV2_strings));

	STRINGS(rigid_body_size_enum)
	{
		"default",
		"tiny",
		"small",
		"medium",
		"large",
		"huge",
		"extra huge"
	};
	STRING_LIST(rigid_body_size_enum, rigid_body_size_enum_strings, _countof(rigid_body_size_enum_strings));

	STRINGS(physics_material_proxy_collision_groups)
	{
		"NONE",
		"small crate",
		"crate",
		"huge crate",
		"item",
		"projectile",
		"biped",
		"machine",
		"early mover machine",
		"only collide with environment",
		"tech art custom",
		"small expensive plant",
		"ignore environment",
		"huge vehicle",
		"ragdoll",
		"super collidable ragdoll",
		"item blocker",
		"user00",
		"user01",
		"everything",
		"creatures"
	};
	STRING_LIST(physics_material_proxy_collision_groups, physics_material_proxy_collision_groups_strings, _countof(physics_material_proxy_collision_groups_strings));

	STRINGS(shape_enum)
	{
		"sphere",
		"pill",
		"box",
		"triangle",
		"polyhedron",
		"multi sphere",
		"unused 0",
		"unused 1",
		"unused 2",
		"unused 3",
		"unused 4",
		"unused 5",
		"unused 6",
		"unused 7",
		"list",
		"mopp"
	};
	STRING_LIST(shape_enum, shape_enum_strings, _countof(shape_enum_strings));

	STRINGS(physics_model_flags)
	{
		"mopp codes dirty*!",
		"serialized havok data converted to target platform!*",
		"make physical children keyframed",
		"shrink radius by havok complex radius"
	};
	STRING_LIST(physics_model_flags, physics_model_flags_strings, _countof(physics_model_flags_strings));

	STRINGS(rigid_constraint_types_enum)
	{
		"hinge",
		"limited hinge",
		"ragdoll",
		"stiff spring",
		"ball and socket",
		"prismatic",
		"powered chain"
	};
	STRING_LIST(rigid_constraint_types_enum, rigid_constraint_types_enum_strings, _countof(rigid_constraint_types_enum_strings));

	STRINGS(physics_model_motor_types_enum)
	{
		"none",
		"damped spring",
		"stongest force"
	};
	STRING_LIST(physics_model_motor_types_enum, physics_model_motor_types_enum_strings, _countof(physics_model_motor_types_enum_strings));

	STRINGS(rigid_body_constraint_edge_constraint_flags_definition)
	{
		"is physical child#this constraint will only be created when this object is a child of another physical object (turrets on vehicles for example)",
		"is rigid#this constraint makes the edge rigid until it is loosened by damage",
		"disable effects#this constraint will not generate impact effects",
		"not created automatically#this flag is used for special systems that need to create constraints dynamically"
	};
	STRING_LIST(rigid_body_constraint_edge_constraint_flags_definition, rigid_body_constraint_edge_constraint_flags_definition_strings, _countof(rigid_body_constraint_edge_constraint_flags_definition_strings));

	STRINGS(nodes_flags)
	{
		"does not animate"
	};
	STRING_LIST(nodes_flags, nodes_flags_strings, _countof(nodes_flags_strings));

	STRINGS(rigid_body_flags)
	{
		"has no phantom power version#don\'t check this flag without talking to eamon",
		"infinite intertia tensor#rigid body will never have angular velocity",
		"can use mopps#this flag was invented for the behemoth and is dangerous to use anywhere else (obsolete)!",
		"Havok rigid body#rigid body properties like center of mass and inertia tensor come from Havok Content Tools (and shouldn\'t be edited in Bonobo)",
		"explicit mass#the mass is explicit, and not computed based on volume and density",
		"absolute center of mass#the \'center of mass offset\' is relative to the pivot and not to the computed center",
		"force keyframed#rigid body is always keyframed and can\'t be overriden to dynamic or fixed",
		"force not cut NavMesh#this rigid body will not generate a cutting silhouette"
	};
	STRING_LIST(rigid_body_flags, rigid_body_flags_strings, _countof(rigid_body_flags_strings));

	STRINGS(rigid_body_motion_enum)
	{
		"sphere",
		"stabilized sphere",
		"box",
		"stabilized box",
		"keyframed",
		"fixed"
	};
	STRING_LIST(rigid_body_motion_enum, rigid_body_motion_enum_strings, _countof(rigid_body_motion_enum_strings));

	STRINGS(rigid_body_collision_quality_enum)
	{
		"none",
		"debris_simple_toi",
		"moving",
		"critical",
		"bullet",
		"character",
		"fixed"
	};
	STRING_LIST(rigid_body_collision_quality_enum, rigid_body_collision_quality_enum_strings, _countof(rigid_body_collision_quality_enum_strings));

} // namespace macaque

} // namespace blofeld

