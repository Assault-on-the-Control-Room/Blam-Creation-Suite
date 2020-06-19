#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(physics_model, PHYSICS_MODEL_TAG, physics_model_block_block );

	TAG_BLOCK(spheres_block, k_maximum_shapes_per_physics_model)
	{
		{ _field_struct, "base", &havok_primitive_struct_struct_definition },

		{ _field_struct, "sphere shape", &havok_convex_shape_struct_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },

		{ _field_pad, "algn344", 12 },
		{ _field_struct, "translate shape", &havok_convex_translate_shape_struct_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 4 },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },

		{ _field_terminator }
	};

	TAG_BLOCK(pills_block, k_maximum_shapes_per_physics_model)
	{
		{ _field_struct, "base", &havok_primitive_struct_struct_definition },
		{ _field_struct, "capsule shape", &havok_convex_shape_struct_struct_definition },
		{ _field_pad, "algn243", 12 },
		{ _field_real_vector_3d, "bottom*!" },
		{ _field_real, "havok w bottom*!!" },
		{ _field_real_vector_3d, "top*!" },
		{ _field_real, "havok w top*!!" },
		{ _field_terminator }
	};

	TAG_BLOCK(lists_block, k_maximum_rigid_bodies_per_physics_model)
	{
		{ _field_struct, "base", &havok_shape_collection_struct_2010_2_struct_definition },
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_long_integer, "child shapes size*" },
		{ _field_long_integer, "child shapes capacity*!" },
		{ _field_pad, "nail_in_dick", 12 },
		{ _field_real_vector_3d, "aabb half extents!*!" },
		{ _field_real, "havok w aabb half extents!*!!" },
		{ _field_real_vector_3d, "aabb center!*!" },
		{ _field_real, "havok w aabb center!*!!" },
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

	TAG_BLOCK(list_shapes_block, k_maximum_list_shapes_per_physics_model)
	{
		{ _field_struct, "shape reference", &havok_shape_reference_struct_struct_definition },
		{ _field_long_integer, "collision filter*" },
		{ _field_long_integer, "shape size*" },
		{ _field_long_integer, "num child shapes*" },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_damped_spring_motor_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_string_id, "name" },
		{ _field_real, "maximum force#0 defaults to k_real_max" },
		{ _field_real, "minimum force#0 defaults to maximum force.  In general you should leave this alone unless working on ragdolls or something like them" },
		{ _field_real, "spring k" },
		{ _field_real, "damping#0 means default daming of 1.0f" },
		{ _field_real, "initial position" },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_position_motor_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_string_id, "name" },
		{ _field_real, "maximum force" },
		{ _field_real, "minimum force#0 defaults to maximum force.  In general you should leave this alone unless working on ragdolls or something like them" },
		{ _field_real, "tau#from 0-1.  relative stiffness" },
		{ _field_real, "damping#from 0-1" },
		{ _field_real, "proportion recover vel#fraction of recover velocity used.  0 defaults to 1" },
		{ _field_real, "consant recover vel#velocity used to recover when errors happen.  in degress per second" },
		{ _field_real, "initial position" },
		{ _field_terminator }
	};

	TAG_BLOCK(phantom_types_block, k_maximum_phantom_types_per_physics_model)
	{
		{ _field_long_flags, "flags", &PhantomFlagsV2 },
		{ _field_real, "brittle timer:seconds#objects in this phantom volume will be set to brittle collision damage for this amount of time." },
		{ _field_char_enum, "minimum size", &rigid_body_size_enum },
		{ _field_char_enum, "maximum size", &rigid_body_size_enum },
		{ _field_pad, "OF", 2 },
		{ _field_custom },
		{ _field_string_id, "marker name#you don\'t need this if you\'re just generating effects.  If empty it defaults to the up of the object" },
		{ _field_custom },
		{ _field_string_id, "alignment marker name#you don\'t need this if you\'re just generating effects.  If empty it defaults to \"marker name\"" },
		{ _field_explanation, "Linear Motion", "0 - means do nothing\nCENTER: motion towards marker position \nAXIS: motion towards marker axis, such that object is on the axis\nDIRECTION: motion along marker direction" },
		{ _field_pad, "WTBFO", 8 },
		{ _field_real, "hookes law e#0 if you don\'t want this to behave like spring.  1 is a good starting point if you do." },
		{ _field_real, "linear dead radius#radius from linear motion origin in which acceleration is dead." },
		{ _field_real, "center acc" },
		{ _field_real, "center max vel" },
		{ _field_real, "axis acc" },
		{ _field_real, "axis max vel" },
		{ _field_real, "direction acc" },
		{ _field_real, "direction max vel" },
		{ _field_real, "orbit acc#negative values spin the opposite direction from positive ones" },
		{ _field_real, "orbit max vel" },
		{ _field_pad, "TF", 28 },
		{ _field_explanation, "Angular Motion", "0 - means do nothing\nALIGNMENT: algin objects in the phantom with the marker\nSPIN: spin the object about the marker axis" },
		{ _field_real, "alignment hookes law e#0 if you don\'t want this to behave like spring.  1 is a good starting point if you do." },
		{ _field_real, "alignment acc" },
		{ _field_real, "alignment max vel" },
		{ _field_pad, "TYXJL", 8 },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_powered_chain_nodes_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_short_block_index, "node" },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_powered_chain_constraints_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_enum, "constraint type", &rigid_constraint_types_enum },
		{ _field_custom_short_block_index, "constraint index" },
		{ _field_struct, "motor x", &physics_model_motor_reference_struct_struct_definition },
		{ _field_struct, "motor y", &physics_model_motor_reference_struct_struct_definition },
		{ _field_struct, "motor z", &physics_model_motor_reference_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_powered_chains_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_block, "nodes", &physics_model_powered_chain_nodes_block_block },
		{ _field_block, "constraints", &physics_model_powered_chain_constraints_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_ragdoll_motors_block, 1)
	{
		{ _field_explanation, "twist", "" },
		{ _field_struct, "twist motor", &physics_model_motor_reference_struct_struct_definition },
		{ _field_explanation, "cone", "" },
		{ _field_struct, "cone motor", &physics_model_motor_reference_struct_struct_definition },
		{ _field_explanation, "plane", "" },
		{ _field_struct, "plane motor", &physics_model_motor_reference_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_limited_hinge_motors_block, 1)
	{
		{ _field_struct, "motor", &physics_model_motor_reference_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_constraint_edge_constraint_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_enum, "type*!", &rigid_constraint_types_enum },
		{ _field_custom_short_block_index, "index*!" },
		{ _field_long_flags, "flags", &rigid_body_constraint_edge_constraint_flags_definition },
		{ _field_real, "friction#0 is the default (takes what it was set in max) anything else overrides that value" },
		{ _field_block, "ragdoll motors", &physics_model_ragdoll_motors_block_block },
		{ _field_block, "limited hinge motors", &physics_model_limited_hinge_motors_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(physics_model_node_constraint_edge_block, k_maximum_node_constraint_edges_per_physics_model)
	{
		{ _field_short_integer, "runtime material type a!" },
		{ _field_short_integer, "runtime material type b!" },
		{ _field_short_block_index, "node a*!" },
		{ _field_short_block_index, "node b*!" },
		{ _field_block, "constraints*", &physics_model_constraint_edge_constraint_block_block },
		{ _field_string_id, "node a material#if you don\'t fill this out we will pluck the material from the first primitive, of the first rigid body attached to node a" },
		{ _field_string_id, "node b material#if you don\'t fill this out we will pluck the material from the first primitive, of the first rigid body attached to node b, if node b is none we use whatever material a has" },
		{ _field_terminator }
	};

	TAG_BLOCK(rigid_bodies_block, k_maximum_rigid_bodies_per_physics_model)
	{
		{ _field_short_block_index, "node*" },
		{ _field_short_block_index, "region*" },
		{ _field_custom_short_block_index, "permutattion*" },
		{ _field_short_block_index, "serialized shapes*" },
		{ _field_real_point_3d, "bouding sphere offset*!" },
		{ _field_real, "bounding sphere radius*!" },
		{ _field_word_flags, "flags", &rigid_body_flags },
		{ _field_short_block_index, "no phantom power alt" },
		{ _field_char_enum, "motion type", &rigid_body_motion_enum },
		{ _field_explanation, "collision group override", "This value overrides the default group.  It also overrides values specified in the materials block of this tag. Values set here can be overridden per shape through the shape primitive blocks." },
		{ _field_char_enum, "proxy collision group", &physics_material_proxy_collision_groups },
		{ _field_enum, "size", &rigid_body_size_enum },
		{ _field_explanation, "inertia tensor scales", "if you want to set he scale uniforml just set \"inertia tensor scale\".  If you want to set the values seperately per axis you can set \"inertia tensor scale x\\y\\z\"" },
		{ _field_real, "inertia tensor scale#0.0 defaults to 1.0" },
		{ _field_real, "inertia tensor scale x#0.0 defaults to 1.0" },
		{ _field_real, "inertia tensor scale y#0.0 defaults to 1.0" },
		{ _field_real, "inertia tensor scale z#0.0 defaults to 1.0" },
		{ _field_real, "linear damping#this goes from 0-10 (10 is really, really high)" },
		{ _field_real, "angular damping#this goes from 0-10 (10 is really, really high)" },
		{ _field_real_vector_3d, "center off mass offset" },
		{ _field_explanation, "water physics bounding box", "if any of these fields are non-zero, this overrides the bounding box used for water physics" },
		{ _field_real, "water physics x0#x0 value of the water physics aabb" },
		{ _field_real, "water physics x1#x1 value of the water physics aabb" },
		{ _field_real, "water physics y0#y0 value of the water physics aabb" },
		{ _field_real, "water physics y1#y1 value of the water physics aabb" },
		{ _field_real, "water physics z0#z0 value of the water physics aabb" },
		{ _field_real, "water physics z1#z1 value of the water physics aabb" },
		{ _field_long_integer, "Runtime Shape Pointer*~!" },
		{ _field_real_vector_3d, "center of mass*!" },
		{ _field_real, "havok w center of mass*!!" },
		{ _field_real_vector_3d, "intertia tensor x*!" },
		{ _field_real, "havok w intertia tensor x*!!" },
		{ _field_real_vector_3d, "intertia tensor y*!" },
		{ _field_real, "havok w intertia tensor y*!!" },
		{ _field_real_vector_3d, "intertia tensor z*!" },
		{ _field_real, "havok w intertia tensor z*!!" },
		{ _field_long_integer, "runtime havok group mask *!" },
		{ _field_struct, "shape reference", &havok_shape_reference_struct_struct_definition },
		{ _field_real, "mass:kg*!" },
		{ _field_real, "bounding sphere pad#the bounding sphere for this rigid body will be outset by this much" },
		{ _field_char_enum, "collision quality override type", &rigid_body_collision_quality_enum },
		{ _field_pad, "pad3", 1 },
		{ _field_short_integer, "runtime_flags*!" },
		{ _field_explanation, "Stupid mass override", "If you want to override what the calculated mass distribution or artist set mass is, this is where you do it. Also, this will show up as n/100 in the game debugger. Awesome." },
		{ _field_real, "Mass body override" },
		{ _field_pad, "pad4", 8 },
		{ _field_terminator }
	};

	TAG_BLOCK(materials_block$3, k_maximum_materials_per_physics_model)
	{
		{ _field_string_id, "name^*!" },
		{ _field_byte_flags, "flags", &physics_material_flags },
		{ _field_pad, "flags pad", 3 },
		{ _field_string_id, "global material name" },
		{ _field_short_block_index, "phantom type" },
		{ _field_explanation, "collision group override", "This value overrides the default collision group.  It is overridden by any values specified rigid bodies block that overlap. Values set here can be overridden per shape through the shape primitive blocks." },
		{ _field_char_enum, "proxy collision group", &physics_material_proxy_collision_groups },
		{ _field_char_integer, "runtime collision group*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(multi_spheres_block, k_maximum_shapes_per_physics_model)
	{
		{ _field_struct, "base", &havok_primitive_struct_struct_definition },
		{ _field_struct, "sphere rep shape", &havok_shape_struct_struct_definition },
		{ _field_long_integer, "num spheres*!" },
		{ _field_pad, "bull434", 12 },
		{ _field_array, "four vectors storage*!", &multi_sphere_vector_storage_array },
		{ _field_terminator }
	};

	TAG_BLOCK(boxes_block, k_maximum_shapes_per_physics_model)
	{
		{ _field_struct, "base", &havok_primitive_struct_struct_definition },
		{ _field_struct, "box shape", &havok_convex_shape_struct_struct_definition },
		{ _field_pad, "algn3473", 12 },
		{ _field_real_vector_3d, "half extents*!" },
		{ _field_real, "havok w half extents*!!" },
		{ _field_struct, "convex transform shape", &havok_convex_transform_shape_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(triangles_block, k_maximum_shapes_per_physics_model)
	{
		{ _field_struct, "base", &havok_primitive_struct_struct_definition },
		{ _field_struct, "triangle shape", &havok_convex_shape_struct_2010_2_struct_definition },
		{ _field_short_integer, "welding info*!" },
		{ _field_char_integer, "welding type*!" },
		{ _field_char_integer, "is extruded*!" },
		{ _field_pad, "algn92", 8 },
		{ _field_real_vector_3d, "point a*!" },
		{ _field_real, "havok w point a*!!" },
		{ _field_real_vector_3d, "point b*!" },
		{ _field_real, "havok w point b*!!" },
		{ _field_real_vector_3d, "point c*!" },
		{ _field_real, "havok w point c*!!" },
		{ _field_real_vector_3d, "extrusion*!" },
		{ _field_real, "havok w extrusion*!!" },
		{ _field_terminator }
	};

	TAG_BLOCK(polyhedra_block, k_maximum_shapes_per_physics_model)
	{
		{ _field_struct, "base", &havok_primitive_struct_struct_definition },
		{ _field_struct, "polyhedron shape", &havok_convex_shape_struct_struct_definition },
		{ _field_pad, "algn743", 12 },
		{ _field_real_vector_3d, "aabb half extents*" },
		{ _field_real, "havok w aabb half extents*!" },
		{ _field_real_vector_3d, "aabb center*" },
		{ _field_real, "havok w aabb center*!" },
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_long_integer, "four vectors size*" },
		{ _field_long_integer, "four vectors capacity*!" },
		{ _field_long_integer, "num vertices*" },
		{ _field_char_integer, "m_useSpuBuffer*" },
		{ _field_pad, "algn434", 3 },
		{ _field_long_integer, "another field pointer skip!~" },
		{ _field_long_integer, "plane equations size*" },
		{ _field_long_integer, "plane equations capacity*!" },
		{ _field_long_integer, "connectivity*!" },
		{ _field_pad, "SAMTRA", 12 },
		{ _field_terminator }
	};

	TAG_BLOCK(polyhedron_four_vectors_block, k_maximum_four_vectors_per_physics_model)
	{
		{ _field_real_vector_3d, "four vectors x*" },
		{ _field_real, "havok w four vectors x*!" },
		{ _field_real_vector_3d, "four vectors y*" },
		{ _field_real, "havok w four vectors y*!" },
		{ _field_real_vector_3d, "four vectors z*" },
		{ _field_real, "havok w four vectors z*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(polyhedron_plane_equations_block, k_maximum_plane_equations_per_physics_model)
	{
		{ _field_real_vector_3d, "plane equations*!" },
		{ _field_real, "havok w plane equations*!!" },
		{ _field_terminator }
	};

	TAG_BLOCK(mass_distributions_block, k_maximum_inertia_tensors_per_physics_model)
	{
		{ _field_real_vector_3d, "center of mass*" },
		{ _field_real, "havok w center of mass*!" },
		{ _field_real_vector_3d, "inertia tensor i*" },
		{ _field_real, "havok w inertia tensor i*!" },
		{ _field_real_vector_3d, "inertia tensor j*" },
		{ _field_real, "havok w inertia tensor j*!" },
		{ _field_real_vector_3d, "inertia tensor k*" },
		{ _field_real, "havok w inertia tensor k*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(mopps_block, k_maximum_rigid_bodies_per_physics_model)
	{
		{ _field_struct, "base", &havok_shape_struct_struct_definition },
		{ _field_pad, "m_bvTreeType", 1 },
		{ _field_pad, "3 other bytes", 3 },
		{ _field_long_integer, "mopp code pointer!~" },
		{ _field_long_integer, "mopp data skip!~" },
		{ _field_long_integer, "mopp data size~" },
		{ _field_real_vector_3d, "m_codeInfoCopy*" },
		{ _field_real, "havok w m_codeInfoCopy*!" },
		{ _field_long_integer, "child shape vtable*!~" },
		{ _field_struct, "childShapePointer!~", &havok_shape_reference_struct_struct_definition },
		{ _field_long_integer, "child size!~" },
		{ _field_pad, "mopp alignment*!~", 4 },
		{ _field_real, "scale*!" },
		{ _field_pad, "final alignment*!~", 12 },
		{ _field_terminator }
	};

	TAG_BLOCK(hinge_constraints_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition },
		{ _field_pad, "JENFOXHY", 4 },
		{ _field_terminator }
	};

	TAG_BLOCK(ragdoll_constraints_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition },
		{ _field_pad, "OVIM", 4 },
		{ _field_real, "min twist*!" },
		{ _field_real, "max twist*!" },
		{ _field_real, "min cone*!" },
		{ _field_real, "max cone*!" },
		{ _field_real, "min plane*!" },
		{ _field_real, "max plane*!" },
		{ _field_real, "max friciton torque*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(rigid_body_indices_block, k_maximum_rigid_bodies_per_physics_model)
	{
		{ _field_short_block_index, "rigid body^*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(permutations_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		{ _field_string_id, "name^*!" },
		{ _field_block, "rigid bodies", &rigid_body_indices_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(regions_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_string_id, "name^*!" },
		{ _field_block, "permutations", &permutations_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(nodes_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_string_id, "name^*!" },
		{ _field_word_flags, "flags", &nodes_flags },
		{ _field_short_block_index, "parent*!" },
		{ _field_short_block_index, "sibling*!" },
		{ _field_short_block_index, "child*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(point_to_path_curve_point_block, 1024)
	{
		{ _field_real_point_3d, "position*!" },
		{ _field_real, "t value*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(point_to_path_curve_block, k_maximum_rigid_bodies_per_physics_model)
	{
		{ _field_string_id, "name^*!" },
		{ _field_short_block_index, "node index*!" },
		{ _field_pad, "TNLRSOSY", 2 },
		{ _field_block, "points*!", &point_to_path_curve_point_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(limited_hinge_constraints_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition },
		{ _field_pad, "TC", 4 },
		{ _field_real, "limit friction*!" },
		{ _field_real, "limit min angle*!" },
		{ _field_real, "limit max angle*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(ball_and_socket_constraints_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition },
		{ _field_pad, "UPDLSKB", 4 },
		{ _field_terminator }
	};

	TAG_BLOCK(stiff_spring_constraints_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition },
		{ _field_pad, "KGB", 4 },
		{ _field_real, "spring_length*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(prismatic_constraints_block, k_maximum_constraints_per_physics_model)
	{
		{ _field_struct, "constraint bodies*!", &constraint_bodies_struct_struct_definition },
		{ _field_pad, "XVEPD", 4 },
		{ _field_real, "min_limit*!" },
		{ _field_real, "max_limit*!" },
		{ _field_real, "max_friction_force*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(phantoms_block, k_maximum_phantoms_per_physics_model)
	{
		{ _field_struct, "bv shape", &havok_shape_struct_struct_definition },
		{ _field_struct, "havok shape reference struct1", &havok_shape_reference_struct_struct_definition },
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_long_integer, "child shape pointer!~" },
		{ _field_struct, "phantom shape", &havok_shape_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(MoppSerializedHavokDataBlock, k_maximum_rigid_bodies_per_physics_model)
	{
		{ _field_struct, "base", &havok_primitive_struct_struct_definition },
		{ _field_long_integer, "version*" },
		{ _field_long_integer, "Runtime Deserialized Shape Pointer*~!" },
		{ _field_data, "Serialized Havok Data*" },
		{ _field_data, "Serialized Havok Data Any Temp*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(RigidBodySerializedShapesBlock, k_maximum_shapes_per_physics_model)
	{
		{ _field_block, "Mopp Serialized Havok Data", &MoppSerializedHavokDataBlock_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(physics_model_block, 1, physics_model_struct_definition_struct_definition );

	TAG_ARRAY(multi_sphere_vector_storage, 8)
	{
		{ _field_real_vector_3d, "sphere*!" },
		{ _field_real, "havok w sphere*!!" },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_primitive_struct)
	{
		{ _field_string_id, "name^*!" },
		{ _field_char_block_index, "material*" },
		{ _field_byte_flags, "material flags*", &physics_material_flags },
		{ _field_short_integer, "runtime material type*~!" },
		{ _field_real, "relative mass scale" },
		{ _field_real_fraction, "friction" },
		{ _field_real_fraction, "restitution" },
		{ _field_real, "volume *" },
		{ _field_real, "mass*!" },
		{ _field_short_integer, "mass distribution index!" },
		{ _field_char_block_index, "phantom*" },
		{ _field_explanation, "collision group override", "This value overrides the default group, model, and rigid body." },
		{ _field_char_enum, "proxy collision group", &physics_material_proxy_collision_groups },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_convex_shape_struct)
	{
		{ _field_struct, "base", & havok_shape_struct_struct_definition },

		{ _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },

		{ _field_real, "radius*!" },

		{ _field_terminator }
	};

	TAG_STRUCT(havok_shape_struct)
	{
		{ _field_version_less_or_equal, _engine_type_haloreach },
		{ _field_long_integer, "unknown@" },

		{ _field_long_integer, "field pointer skip!~" },
		{ _field_short_integer, "size*~!" },
		{ _field_short_integer, "count*~!" },
		{ _field_char_integer, "type*~!" },
		{ _field_char_integer, "dispatchType*~!" },
		{ _field_char_integer, "bitsPerKey*~!" },
		{ _field_char_integer, "codecType*~!" },
		{ _field_long_integer, "user data*~!" },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_convex_translate_shape_struct)
	{
		{ _field_struct, "convex", &havok_convex_shape_struct_struct_definition },
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_struct, "havok shape reference struct", &havok_shape_reference_struct_struct_definition },
		{ _field_long_integer, "child shape size" },
		{ _field_real_vector_3d, "translation*!" },
		{ _field_real, "havok w translation*!!" },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_shape_reference_struct)
	{
		{ _field_enum, "shape type*", &shape_enum },
		{ _field_custom_short_block_index, "shape*" },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_shape_collection_struct_2010_2)
	{
		{ _field_struct, "base", &havok_shape_struct_2010_2_struct_definition },
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_char_integer, "disable welding*~" },
		{ _field_char_integer, "collection type*~" },
		{ _field_pad, "VDVAPBSS", 2 },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_shape_struct_2010_2)
	{
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_short_integer, "size*~!" },
		{ _field_short_integer, "count*~!" },
		{ _field_long_integer, "user data*~!" },
		{ _field_long_integer, "type*~!" },
		{ _field_terminator }
	};

	TAG_STRUCT(physics_model_struct_definition)
	{
		{ _field_long_flags, "flags", &physics_model_flags },
		{ _field_real, "mass scale#scales the mass of each rigid body.  If you leave this field as 0, then it will be calculated from the total mass below." },
		{ _field_real, "mass#override total mass of all rigid bodies.  Note that this will NOT be the mass of the object if not all rigid bodies are present (for example if you are using permutations)\nIf you set a mass scale above, this field is unused." },
		{ _field_real, "low freq. deactivation scale#0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." },
		{ _field_real, "high freq. deactivation scale#0 is default (1). LESS than 1 deactivates less aggressively. GREATER than 1 is more agressive." },
		{ _field_real, "custom shape radius!#0 defaults to .016.  This field is intentionally hidden because we should only alter this for very special situations.  Lower number == lower performance" },
		{ _field_real, "maximum penetration depth scale#0 is default (1). for objects that are prone to falling through the world we can reduce this number at the cost of performance" },
		{ _field_char_integer, "import version*!" },
		{ _field_pad, "pad0", 3 },
		{ _field_block, "damped spring motors", &physics_model_damped_spring_motor_block_block },
		{ _field_block, "position motors", &physics_model_position_motor_block_block },
		{ _field_block, "phantom types", &phantom_types_block_block },
		{ _field_block, "powered chains", &physics_model_powered_chains_block_block },
		{ _field_block, "node edges*", &physics_model_node_constraint_edge_block_block },
		{ _field_block, "rigid bodies*", &rigid_bodies_block_block },
		{ _field_block, "materials*", &materials_block$3_block },
		{ _field_block, "spheres*", &spheres_block_block },
		{ _field_block, "multi spheres*", &multi_spheres_block_block },
		{ _field_block, "pills*", &pills_block_block },
		{ _field_block, "boxes*", &boxes_block_block },
		{ _field_block, "triangles*", &triangles_block_block },
		{ _field_block, "polyhedra*", &polyhedra_block_block },
		{ _field_block, "polyhedron four vectors*!", &polyhedron_four_vectors_block_block },
		{ _field_block, "polyhedron plane equations*!", &polyhedron_plane_equations_block_block },
		{ _field_block, "mass distributions*!", &mass_distributions_block_block },
		{ _field_block, "lists*!", &lists_block_block },
		{ _field_block, "list shapes*!", &list_shapes_block_block },
		{ _field_block, "mopps*!", &mopps_block_block },
		{ _field_data, "mopp codes*!" },
		{ _field_block, "hinge constraints*!", &hinge_constraints_block_block },
		{ _field_block, "ragdoll constraints*!", &ragdoll_constraints_block_block },
		{ _field_block, "regions*", &regions_block_block },
		{ _field_block, "nodes*", &nodes_block_block },
		{ _field_block, "errors*!", &global_error_report_categories_block_block },
		{ _field_block, "point to path curves*!", &point_to_path_curve_block_block },
		{ _field_block, "limited hinge constraints*!", &limited_hinge_constraints_block_block },
		{ _field_block, "ball and socket constraints*!", &ball_and_socket_constraints_block_block },
		{ _field_block, "stiff spring constraints*!", &stiff_spring_constraints_block_block },
		{ _field_block, "prismatic constraints*!", &prismatic_constraints_block_block },
		{ _field_block, "phantoms*!", &phantoms_block_block },
		{ _field_block, "RigidBody Serialized Shapes*", &RigidBodySerializedShapesBlock_block },
		{ _field_terminator }
	};

	TAG_STRUCT(physics_model_motor_reference_struct)
	{
		{ _field_enum, "motor type", &physics_model_motor_types_enum },
		{ _field_custom_short_block_index, "index" },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_convex_transform_shape_struct)
	{
		{ _field_struct, "convex", &havok_convex_shape_struct_struct_definition },
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_struct, "havok shape reference struct", &havok_shape_reference_struct_struct_definition },
		{ _field_long_integer, "child shape size" },
		{ _field_real_vector_3d, "rotation i*!" },
		{ _field_real, "havok w rotation i*!!" },
		{ _field_real_vector_3d, "rotation j*!" },
		{ _field_real, "havok w rotation j*!!" },
		{ _field_real_vector_3d, "rotation k*!" },
		{ _field_real, "havok w rotation k*!!" },
		{ _field_real_vector_3d, "translation*!" },
		{ _field_real, "havok w translation*!!" },
		{ _field_terminator }
	};

	TAG_STRUCT(havok_convex_shape_struct_2010_2)
	{
		{ _field_struct, "base", &havok_shape_struct_2010_2_struct_definition },
		{ _field_real, "radius*!" },
		{ _field_terminator }
	};

	TAG_STRUCT(constraint_bodies_struct)
	{
		{ _field_string_id, "name^*!" },
		{ _field_short_block_index, "node a*!" },
		{ _field_short_block_index, "node b*!" },
		{ _field_real, "a scale*!" },
		{ _field_real_vector_3d, "a forward*!" },
		{ _field_real_vector_3d, "a left*!" },
		{ _field_real_vector_3d, "a up*!" },
		{ _field_real_point_3d, "a position*!" },
		{ _field_real, "b scale*!" },
		{ _field_real_vector_3d, "b forward*!" },
		{ _field_real_vector_3d, "b left*!" },
		{ _field_real_vector_3d, "b up*!" },
		{ _field_real_point_3d, "b position*!" },
		{ _field_short_block_index, "edge index*!" },
		{ _field_pad, "H", 2 },
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

} // namespace blofeld

