#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(model, MODEL_TAG)
	{
		{ _field_explanation, "MODEL", "" },
		{ _field_custom },
		{ _field_tag_reference, "render model", &render_model_reference$2 },
		{ _field_tag_reference, "collision model", &collision_model_reference },
		{ _field_tag_reference, "animation", &global_animation_graph_reference },
		{ _field_tag_reference, "physics_model", &physics_model_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "imposter model", &imposter_model_reference$2 },
		{ _field_long_integer, "runtime render checksum*!" },
		{ _field_long_integer, "runtime collision checksum*!" },

		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_explanation, "Optional Static Lightmap", "\n" },
		{ _field_tag_reference, "Lighting Info^", &structure_lighting_bsp_reference },
		{ _field_long_enum, "Size Class", &scenario_structure_size_enum },
		{ _field_long_flags, "Lightmap Flags{PVS flags}", &model_lightmap_flags_definition },
		{ _field_long_block_index, "Lightmap Variant" },

		{ _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_explanation, "PVS", "\n" },
		{ _field_real, "PVS bounding box extension factor #How much we extend the PVS region around the objects AABB : [good initial value 2.5]" },
		{ _field_real_vector_3d, "PVS block size #How big a single PVS block is, in world units : [good initial value (2.0,2.0,2.0)]" },
		{ _field_long_integer, "PVS sampling subdivision per axis #How many sample subdivisions we perform per PVS block when generating the data : [good initial value 2]" },
		{ _field_real, "PVS visibility threshold #Minimum amount we need to see of an individual part mesh to care about it : [good initial value 0.004]" },
		
		{ _field_explanation, "level of detail", "\n" },
		{ _field_real, "disappear distance:world units" },
		{ _field_real, "begin fade distance:world units" },
		{ _field_real, "animation lod distance:world units" },
		{ _field_real, "shadow fade distance:world units#NOTE this is only a maximum distance, shadows may fade closer when you exceed the shadow budget, you should balance the total shadows in a scene" },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 4 },
		{ _field_real, "imposter render distance:world units" },
		{ _field_enum, "imposter quality", &imposter_quality_definition },
		{ _field_enum, "imposter policy", &imposter_policy_definition },
		{ _field_real, "imposter brightness adjustment" },

		{ _field_real, "instance disappear distance:world units" },

		{ _field_version_less, _engine_type_haloreach, 1 },
		{ _field_tag_reference, "lod render model", &render_model_reference$2 },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_real, "midrange detail disappear distance:world units#distance at which the midrange detail disappears" },
		{ _field_real, "close detail disappear distance:world units#distance at which the close detail disappears" },
		{ _field_real, "tessellation max draw distance:world units" },

		{ _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_long_flags, "resource distance override flags", &model_lod_resource_distance_flags_definition },
		{ _field_real, "medium priority distance" },
		{ _field_real, "low priority distance" },

		{ _field_block, "variants", &model_variant_block_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_block, "region sort", &region_name_block_block },

		{ _field_block, "instance groups", &global_model_instance_group_block_block },

		{ _field_version_equal, _engine_type_haloreach },
		{ _field_block, "old materials", &model_material_block_new_block },

		{ _field_block, "model materials*", &model_material_block_new_block },
		{ _field_block, "new damage info!", &global_damage_info_block_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_struct, "damage info", &model_damage_info_struct_struct_definition },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_block, "targets!", &model_target_block_old_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_block, "targets old{targets}!", &model_target_block_old_block },
		{ _field_block, "model targets", &model_target_block_new_block },

		{ _field_block, "runtime regions!", &model_region_block_block },
		{ _field_block, "runtime nodes!", &model_node_block_block },
		{ _field_long_integer, "runtime node list checksum!" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_block, "model object data", &model_object_data_block_block },

		{ _field_explanation, "more stuff", "" },
		{ _field_tag_reference, "default dialogue#The default dialogue tag for this model (overriden by variants)", &dialogue_reference$3 },
		{ _field_tag_reference, "default dialogue female#The default FEMALE dialogue tag for this model (overriden by variants)", &dialogue_reference$3 },
		{ _field_long_flags, "flags", &model_flags_definition },
		{ _field_string_id, "default dialogue effect#The default dialogue tag for this model (overriden by variants)" },
		{ _field_array, "render-only node flags*!", &g_node_flag_storage_array_array },
		{ _field_array, "render-only section flags*!", &g_node_flag_storage_array_array },
		{ _field_long_flags, "runtime flags*!", &model_private_flags_definition },
		{ _field_block, "scenario load parameters", &global_scenario_load_parameters_block_block },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_block, "game mode render model override", &model_game_mode_render_model_override_block },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 5 },
		{ _field_real_fraction, "Sky parallax percent#If flag checked % between sky pos and camera pos 0=camera" },
		{ _field_real, "shadow depth compare bias#Default is 0.002" },
		{ _field_real, "shadow slope scale bias:degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" },
		{ _field_real, "shadow depth compare bias (dynamic lights)#Default is 0.0008" },
		{ _field_real, "shadow slope scale bias (dynamic lights):degrees#controls cutoff point for shadows around edges.  Default is 81 degrees" },
		
		{ _field_explanation, "PRT Shadows (soft self-shadow)", "By default, the shadows on each permutation are computed using the first permutation in\nevery other region as shadow casters.  You can override this behavior below by specifying\nwhich permutation to use as a shadow caster in a given region.\n\n  PRT shadow bounces:\n    the number of light bounces to use when computing the global illumination.\n    (0 bounces gets only direct light).  Increasing the number of bounces\n    increases the calculation time.  1 or 2 bounces should be good enough for\n    almost all models.\n" },
		{ _field_char_enum, "PRT shadow detail!#how much information is recorded about different light directions", &model_self_shadow_detail_definition },
		{ _field_char_enum, "PRT shadow bounces#0 means direct light only", &model_self_shadow_bounces_definition },
		{ _field_pad, "NCFGBA", 2 },
		{ _field_block, "shadow cast override", &model_self_shadow_region_cast_override_block_block },
		{ _field_block, "shadow receive override", &model_self_shadow_region_receive_override_block_block },
		{ _field_block, "occlusion spheres", &model_occlusion_sphere_block_block },
		{ _field_explanation, "Shield impact overrides!", "Regular and 1st person shield impact effect overrides\n" },
		{ _field_tag_reference, "shield impact parameter override!", &global_shield_parameters_reference },
		{ _field_tag_reference, "1st person shield impact parameter override!", &global_shield_parameters_reference },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_real, "runtime bounding radius:world units*!" },
		{ _field_real_point_3d, "runtime bounding offset*!" },

		{ _field_terminator }
	};

	TAG_BLOCK(model_variant_state_block, MAXIMUM_STATES_PER_MODEL_PERMUTATION)
	{
		{ _field_string_id, "permutation name" },
		{ _field_char_integer, "runtime permutation index!" },
		{ _field_byte_flags, "property flags", &model_state_property_flags_definition },
		{ _field_enum, "state^", &model_state_enum_definition },

		{ _field_version_less, _engine_type_haloreach, 2 },
		{ _field_tag_reference, "looping effect", &effect_reference },
		{ _field_string_id, "looping effect marker name" },

		{ _field_real_fraction, "initial probability" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_variant_permutation_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		{ _field_string_id, "permutation name^" },
		{ _field_char_integer, "runtime permutation index!" },
		{ _field_byte_flags, "flags", &model_variant_permutation_flags_definition },
		{ _field_pad, "KSJOSR", 2 },
		{ _field_real, "probability:(0,+inf)" },
		{ _field_block, "states", &model_variant_state_block_block },
		{ _field_array, "runtime state permutation indices!", &model_state_permutation_index_array_array },
		{ _field_pad, "LOOEL", 7 },
		{ _field_terminator }
	};

	TAG_BLOCK(model_variant_region_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_string_id, "region name^:must match region name in render_model" },
		{ _field_char_integer, "runtime region index!" },
		{ _field_byte_integer, "runtime flags!" },
		{ _field_short_block_index, "parent variant" },
		{ _field_block, "permutations", &model_variant_permutation_block_block },
		{ _field_enum, "sort order#negative values mean closer to the camera", &region_sort_enum },
		{ _field_pad, "JO", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(model_variant_object_block, k_maximum_objects_per_model_variant)
	{
		{ _field_custom },
		{ _field_string_id, "parent marker^" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_string_id, "parent controlling seat label^#the seat in my parent that will control me" },

		{ _field_custom },
		{ _field_string_id, "child marker" },
		{ _field_string_id, "child variant name#optional" },
		{ _field_tag_reference, "child object", &object_reference$5 },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 3 },
		{ _field_short_block_index, "damage section" },
		{ _field_byte_flags, "flags", &ModelVariantObjectFlagsDefinition },
		{ _field_pad, "MVOBP1", 1 },

		{ _field_terminator }
	};

	TAG_BLOCK(model_variant_muted_node_block, k_maximum_muted_nodes_per_model_variant)
	{
		{ _field_string_id, "node name^:must match node name in render_model" },
		{ _field_terminator }
	};

	// fixup as older blocks differ in count from global array definition
	TAG_ARRAY(g_model_node_flag_storage_array, k_model_flag_chunk_count /*c_node_flags::k_flag_chunk_count*/)
	{
		{ _field_long_integer, "flag data" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_variant_block, k_maximum_variants_per_model)
	{
		{ _field_string_id, "name^" },
		{ _field_array, "runtime variant region indices!", &runtime_region_index_array_array },
			
		{ _field_block, "regions", &model_variant_region_block_block },
		{ _field_block, "objects", &model_variant_object_block_block },
		{ _field_long_block_index, "instance group#selects an instance group for this variant" },

		{ _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_block, "muted nodes#turn off animation on these named nodes and children", &model_variant_muted_node_block_block },

		{ _field_array, "muted flag*!", &g_model_node_flag_storage_array_array },

		{ _field_terminator }
	};

	TAG_BLOCK(region_name_block, k_kilo)
	{
		{ _field_string_id, "name" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_instance_group_member_block, k_maximum_members_per_instance_group)
	{
		{ _field_long_block_index, "subgroup#if this member is chosen, this subgroup will be chosen as well" },
		{ _field_string_id, "instances#instance name, a partial name will choose all matching instances, leave blank for NONE" },
		{ _field_real, "probability:> 0.0#higher numbers make it more likely" },
		{ _field_long_integer, "instance placement mask 0!" },
		{ _field_long_integer, "instance placement mask 1!" },
		{ _field_long_integer, "instance placement mask 2!" },
		{ _field_long_integer, "instance placement mask 3!" },
		{ _field_terminator }
	};

	TAG_BLOCK(global_model_instance_group_block, k_maximum_instance_groups_per_model)
	{
		{ _field_string_id, "name^#name of this instance group" },
		{ _field_long_enum, "choice#how to choose members", &model_instance_group_choice_enum },
		{ _field_block, "member list", &model_instance_group_member_block_block },
		{ _field_real, "total probability!" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_material_block_new, MAXIMUM_MATERIALS_PER_MODEL)
	{
		{ _field_string_id, "material name*" },
		{ _field_pad, "unused flags", 2 },
		{ _field_short_block_index, "damage section" },
		{ _field_short_integer, "runtime collision material index!" },
		{ _field_short_integer, "runtime damager material index!" },
		{ _field_string_id, "global material name" },
		{ _field_short_integer, "runtime global material index!" },
		{ _field_pad, "SEWETKHRE", 2 },
		{ _field_terminator }
	};

	TAG_BLOCK(model_target_block_old, MAXIMUM_MODEL_TARGETS_PER_MODEL)
	{
		{ _field_custom },
		{ _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" },
		{ _field_real, "size#sphere radius" },
		{ _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" },
		{ _field_custom_short_block_index, "damage section#the target is associated with this damage section" },
		{ _field_short_block_index, "variant#the target will only appear with this variant" },
		{ _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" },
		{ _field_real, "aoe exclusion radius#ignored if zero" },
		{ _field_struct, "lock-on data", &model_target_lock_on_data_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(model_target_block_new, MAXIMUM_MODEL_TARGETS_PER_MODEL)
	{
		{ _field_byte_flags, "flags", &model_target_flags_definition },
		{ _field_pad, "MTBNP1", 3 },
		{ _field_custom },
		{ _field_string_id, "marker name^#multiple markers become multiple spheres of the same radius" },
		{ _field_real, "size#sphere radius" },
		{ _field_angle, "cone angle#the target is only visible when viewed within this angle of the marker\'s x axis" },
		{ _field_short_block_index, "damage section#the target is associated with this damage section" },
		{ _field_short_block_index, "variant#the target will only appear with this variant" },
		{ _field_real_fraction, "targeting relevance#higher relevances turn into stronger magnetisms" },
		{ _field_real, "aoe exclusion radius#ignored if zero" },
		{ _field_struct, "lock-on data", &model_target_lock_on_data_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(model_permutation_block, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
	{
		{ _field_string_id, "name*^" },
		{ _field_byte_flags, "flags*", &model_permutation_flags_definition },
		{ _field_char_integer, "collision permutation index*" },
		{ _field_char_integer, "physics permutation index*" },
		{ _field_pad, "AVZQS", 1 },
		{ _field_terminator }
	};

	TAG_BLOCK(model_region_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_string_id, "name*^" },
		{ _field_char_integer, "collision region index*" },
		{ _field_char_integer, "physics region index*" },
		{ _field_pad, "QDSJS", 2 },
		{ _field_block, "permutations*", &model_permutation_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(model_node_block, MAXIMUM_NODES_PER_MODEL)
	{
		{ _field_string_id, "name*^" },
		{ _field_short_block_index, "parent node*" },
		{ _field_short_block_index, "first child node*" },
		{ _field_short_block_index, "next sibling node*" },
		{ _field_pad, "GHTI", 2 },
		{ _field_real_point_3d, "default translation*" },
		{ _field_real_quaternion, "default rotation*" },
		{ _field_real, "default inverse scale*" },
		{ _field_real_vector_3d, "default inverse forward*" },
		{ _field_real_vector_3d, "default inverse left*" },
		{ _field_real_vector_3d, "default inverse up*" },
		{ _field_real_point_3d, "default inverse position*" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_object_data_block, 65535)
	{
		{ _field_short_integer, "type" }, // lazy fucker
		{ _field_short_integer, "@unknown" },
		{ _field_real_point_3d, "offset" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_game_mode_render_model_override, k_maximum_model_game_mode_types)
	{
		{ _field_enum, "game mode^", &model_game_mode_types },
		{ _field_pad, "BL", 2 },
		{ _field_tag_reference, "render model override", &render_model_reference$3 },
		{ _field_terminator }
	};

	TAG_BLOCK(model_self_shadow_region_cast_override_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_string_id, "region" },
		{ _field_string_id, "shadow cast permutation#leave blank for none" },
		{ _field_terminator }
	};

	TAG_BLOCK(model_self_shadow_region_receive_override_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_string_id, "region" },
		{ _field_long_enum, "shadow type", &model_prt_shadow_receive_mode_definition },
		{ _field_terminator }
	};

	TAG_BLOCK(model_occlusion_sphere_block, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_custom },
		{ _field_string_id, "marker 1 name" },
		{ _field_long_integer, "marker 1 index" },
		{ _field_custom },
		{ _field_string_id, "marker 2 name" },
		{ _field_long_integer, "marker 2 index" },
		{ _field_real, "radius" },
		{ _field_terminator }
	};

	TAG_ARRAY(runtime_region_index_array, MAXIMUM_REGIONS_PER_MODEL)
	{
		{ _field_char_integer, "runtime region index!" },
		{ _field_terminator }
	};

	TAG_ARRAY(model_state_permutation_index_array, k_number_of_model_states)
	{
		{ _field_char_integer, "runtime permutation index!" },
		{ _field_terminator }
	};

	TAG_STRUCT(model_target_lock_on_data_struct)
	{
		{ _field_explanation, "lock-on fields", "" },

		{ _field_version_less, _engine_type_haloreach },
		{ _field_long_flags, "flags", &model_target_lock_on_flags_definition },

		{ _field_version_greater_or_equal, _engine_type_haloreach, 2 },
		{ _field_byte_flags, "flags", &model_target_lock_on_flags_definition },
		{ _field_pad, "SVLKJERAF", 3 },

		{ _field_real, "lock on distance" },

		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_string_id, "tracking type#a weapon can track/lock on this target if this string is in the weapon\'s tracking block" },

		{ _field_terminator }
	};

	STRINGS(model_flags_definition)
	{
		"active camo always on",
		"active camo never",
		"inconsequential target#used in magnetism and campaign saving",
		"model use airprobe lighting first{model use airprobe lighting}",
		"locked precomputed probes#air or scenery probe",
		"If sky attaches to camera#parallax % between sky pos and camera pos below",
		"model is big battle object",
		"model never uses compressed vertex position",
		"model is invisible, even attachments",
		"model can have shield impact effect!*",
		"model is good z occluder",
		"no child objects in lightmap shadow",
		"should include model in floating shadow",

		{ _field_version_equal, _engine_type_haloreach, 5 },
		"bit 14",
		"bit 15",
		"bit 16",
		"bit 17",
		"bit 18",
	};
	STRING_LIST(model_flags_definition, model_flags_definition_strings, _countof(model_flags_definition_strings));

	STRINGS(model_private_flags_definition)
	{
		"contains run-time nodes"
	};
	STRING_LIST(model_private_flags_definition, model_private_flags_definition_strings, _countof(model_private_flags_definition_strings));

	STRINGS(model_lightmap_flags_definition)
	{
		"pvs enabled",
		"per vertex all",
		"generate forge atlas"
	};
	STRING_LIST(model_lightmap_flags_definition, model_lightmap_flags_definition_strings, _countof(model_lightmap_flags_definition_strings));

	STRINGS(model_lod_resource_distance_flags_definition)
	{
		"override enabled"
	};
	STRING_LIST(model_lod_resource_distance_flags_definition, model_lod_resource_distance_flags_definition_strings, _countof(model_lod_resource_distance_flags_definition_strings));

	STRINGS(imposter_quality_definition)
	{
		"default",
		"high",
		"super"
	};
	STRING_LIST(imposter_quality_definition, imposter_quality_definition_strings, _countof(imposter_quality_definition_strings));

	STRINGS(imposter_policy_definition)
	{
		"default",
		"never",
		"always"
	};
	STRING_LIST(imposter_policy_definition, imposter_policy_definition_strings, _countof(imposter_policy_definition_strings));

	STRINGS(model_game_mode_types)
	{
		"campaign",
		"multiplayer",
		"firefight",
		"mainmenu"
	};
	STRING_LIST(model_game_mode_types, model_game_mode_types_strings, _countof(model_game_mode_types_strings));

	STRINGS(model_variant_permutation_flags_definition)
	{
		{
			_engine_type_not_set,
			_versioned_string_list_mode_new,
			{
				"copy states to all permutations"
			}
		},
		{
			_engine_type_haloreach,
			_versioned_string_list_mode_append,
			{
				"unknown_1",
				"unknown_2"
			}
		},
		{
			_engine_type_gen3_xbox360,
			_versioned_string_list_mode_new,
			{
				"copy states to all permutations"
			}
		},
	};
	STRING_LIST(model_variant_permutation_flags_definition, model_variant_permutation_flags_definition_strings, _countof(model_variant_permutation_flags_definition_strings));

	STRINGS(model_state_property_flags_definition)
	{
		"blurred",
		"hella blurred",
		"unshielded{shielded}",
		"battery depleted"
	};
	STRING_LIST(model_state_property_flags_definition, model_state_property_flags_definition_strings, _countof(model_state_property_flags_definition_strings));

	STRINGS(region_sort_enum)
	{
		"no sorting",
		"-5 (closest)",
		"-4",
		"-3",
		"-2",
		"-1",
		"0 (same as model)",
		"1",
		"2",
		"3",
		"4",
		"5 (farthest)"
	};
	STRING_LIST(region_sort_enum, region_sort_enum_strings, _countof(region_sort_enum_strings));

	STRINGS(ModelVariantObjectFlagsDefinition)
	{
		"enable physics"
	};
	STRING_LIST(ModelVariantObjectFlagsDefinition, ModelVariantObjectFlagsDefinition_strings, _countof(ModelVariantObjectFlagsDefinition_strings));

	STRINGS(model_instance_group_choice_enum)
	{
		"choose one member",
		"choose all members"
	};
	STRING_LIST(model_instance_group_choice_enum, model_instance_group_choice_enum_strings, _countof(model_instance_group_choice_enum_strings));

	STRINGS(model_target_lock_on_flags_definition)
	{
		"headshot",
		"vulnerable",
		"ignored on local physics",
		"use for network lead vector only",
		"bit 4",
		"bit 5",
		"bit 6"

	};
	STRING_LIST(model_target_lock_on_flags_definition, model_target_lock_on_flags_definition_strings, _countof(model_target_lock_on_flags_definition_strings));

	STRINGS(model_target_flags_definition)
	{
		"aoe top level",
		"aoe test obstruction",
		"shows tracking reticle#use this model targets center for displaying the targetting reticle"
	};
	STRING_LIST(model_target_flags_definition, model_target_flags_definition_strings, _countof(model_target_flags_definition_strings));

	STRINGS(model_permutation_flags_definition)
	{
		"cannot be chosen randomly"
	};
	STRING_LIST(model_permutation_flags_definition, model_permutation_flags_definition_strings, _countof(model_permutation_flags_definition_strings));

	STRINGS(model_self_shadow_detail_definition)
	{
		"Ambient Occlusion (2 bytes per vertex){0}",
		"Linear (8 bytes per vertex){1}",
		"Quadratic (18 bytes per vertex){2}"
	};
	STRING_LIST(model_self_shadow_detail_definition, model_self_shadow_detail_definition_strings, _countof(model_self_shadow_detail_definition_strings));

	STRINGS(model_self_shadow_bounces_definition)
	{
		"0 bounces (very fast, direct light only)",
		"1 bounce  (slower, pretty good)",
		"2 bounces (molasses, very good)",
		"3 bounces (sloth in molasses, overkill really)"
	};
	STRING_LIST(model_self_shadow_bounces_definition, model_self_shadow_bounces_definition_strings, _countof(model_self_shadow_bounces_definition_strings));

	STRINGS(model_prt_shadow_receive_mode_definition)
	{
		"PRT shadows from all regions (default permutations)",
		"PRT self-shadow only (no shadows from other regions)",
		"No PRT shadows at all (probably not useful)"
	};
	STRING_LIST(model_prt_shadow_receive_mode_definition, model_prt_shadow_receive_mode_definition_strings, _countof(model_prt_shadow_receive_mode_definition_strings));

} // namespace blofeld

