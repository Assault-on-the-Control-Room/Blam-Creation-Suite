#pragma once

enum e_h4_field_type : uint32_t
{
	_h4_field_type_string,
	_h4_field_type_long_string,
	_h4_field_type_string_id,
	_h4_field_type_old_string_id,
	_h4_field_type_char_integer,
	_h4_field_type_short_integer,
	_h4_field_type_long_integer,
	_h4_field_type_int64_integer,
	_h4_field_type_angle,
	_h4_field_type_tag,
	_h4_field_type_char_enum,
	_h4_field_type_enum,
	_h4_field_type_long_enum,
	_h4_field_type_long_flags,
	_h4_field_type_word_flags,
	_h4_field_type_byte_flags,
	_h4_field_type_point_2d,
	_h4_field_type_rectangle_2d,
	_h4_field_type_rgb_color,
	_h4_field_type_argb_color,
	_h4_field_type_real,
	_h4_field_type_real_fraction,
	_h4_field_type_real_point_2d,
	_h4_field_type_real_point_3d,
	_h4_field_type_real_vector_2d,
	_h4_field_type_real_vector_3d,
	_h4_field_type_real_quaternion,
	_h4_field_type_real_euler_angles_2d,
	_h4_field_type_real_euler_angles_3d,
	_h4_field_type_real_plane_2d,
	_h4_field_type_real_plane_3d,
	_h4_field_type_real_rgb_color,
	_h4_field_type_real_argb_color,
	_h4_field_type_real_hsv_color,
	_h4_field_type_real_ahsv_color,
	_h4_field_type_short_bounds,
	_h4_field_type_angle_bounds,
	_h4_field_type_real_bounds,
	_h4_field_type_real_fraction_bounds,
	_h4_field_type_tag_reference,
	_h4_field_type_block,
	_h4_field_type_long_block_flags,
	_h4_field_type_word_block_flags,
	_h4_field_type_byte_block_flags,
	_h4_field_type_char_block_index,
	_h4_field_type_custom_char_block_index,
	_h4_field_type_short_block_index,
	_h4_field_type_custom_short_block_index,
	_h4_field_type_long_block_index,
	_h4_field_type_custom_long_block_index,
	_h4_field_type_data,
	_h4_field_type_vertex_buffer,
	_h4_field_type_pad,
	_h4_field_type_useless_pad,
	_h4_field_type_skip,
	_h4_field_type_non_cache_runtime_value,
	_h4_field_type_explanation,
	_h4_field_type_custom,
	_h4_field_type_struct,
	_h4_field_type_array,
	_h4_field_type_pageable,
	_h4_field_type_api_interop,
	_h4_field_type_terminator,
	_h4_field_type_byte_integer,
	_h4_field_type_word_integer,
	_h4_field_type_dword_integer,
	_h4_field_type_qword_integer,


	_h4_field_type_max,
};

inline uint32_t h4_field_type_get_size(e_h4_field_type field_type)
{
	switch (field_type)
	{
	case _h4_field_type_string: return 32;
	case _h4_field_type_long_string: return 256;
	case _h4_field_type_string_id: return 4;
	case _h4_field_type_old_string_id: return 4;
	case _h4_field_type_char_integer: return 1;
	case _h4_field_type_short_integer: return 2;
	case _h4_field_type_long_integer: return 4;
	case _h4_field_type_int64_integer: return 8;
	case _h4_field_type_angle: return 4;
	case _h4_field_type_tag: return 4;
	case _h4_field_type_char_enum: return 1;
	case _h4_field_type_enum: return 2;
	case _h4_field_type_long_enum: return 4;
	case _h4_field_type_long_flags: return 4;
	case _h4_field_type_word_flags: return 2;
	case _h4_field_type_byte_flags: return 1;
	case _h4_field_type_point_2d: return 4;
	case _h4_field_type_rectangle_2d: return 8;
	case _h4_field_type_rgb_color: return 4;
	case _h4_field_type_argb_color: return 4;
	case _h4_field_type_real: return 4;
	case _h4_field_type_real_fraction: return 4;
	case _h4_field_type_real_point_2d: return 8;
	case _h4_field_type_real_point_3d: return 12;
	case _h4_field_type_real_vector_2d: return 8;
	case _h4_field_type_real_vector_3d: return 12;
	case _h4_field_type_real_quaternion: return 16;
	case _h4_field_type_real_euler_angles_2d: return 8;
	case _h4_field_type_real_euler_angles_3d: return 12;
	case _h4_field_type_real_plane_2d: return 12;
	case _h4_field_type_real_plane_3d: return 16;
	case _h4_field_type_real_rgb_color: return 12;
	case _h4_field_type_real_argb_color: return 16;
	case _h4_field_type_real_hsv_color: return 12;
	case _h4_field_type_real_ahsv_color: return 16;
	case _h4_field_type_short_bounds: return 4;
	case _h4_field_type_angle_bounds: return 8;
	case _h4_field_type_real_bounds: return 8;
	case _h4_field_type_real_fraction_bounds: return 8;
	case _h4_field_type_tag_reference: return 16;
	case _h4_field_type_block: return 12;
	case _h4_field_type_long_block_flags: return 4;
	case _h4_field_type_word_block_flags: return 2;
	case _h4_field_type_byte_block_flags: return 1;
	case _h4_field_type_char_block_index: return 1;
	case _h4_field_type_custom_char_block_index: return 1;
	case _h4_field_type_short_block_index: return 2;
	case _h4_field_type_custom_short_block_index: return 2;
	case _h4_field_type_long_block_index: return 4;
	case _h4_field_type_custom_long_block_index: return 4;
	case _h4_field_type_data: return 20;
	case _h4_field_type_vertex_buffer: return 32;
	case _h4_field_type_pad: return 0;
	case _h4_field_type_useless_pad: return 0;
	case _h4_field_type_skip: return 0;
	case _h4_field_type_non_cache_runtime_value: return 4;
	case _h4_field_type_explanation: return 0;
	case _h4_field_type_custom: return 0;
	case _h4_field_type_struct: return 0;
	case _h4_field_type_array: return 0;
	case _h4_field_type_pageable: return 8;
	case _h4_field_type_api_interop: return 12;
	case _h4_field_type_terminator: return 0;
	case _h4_field_type_byte_integer: return 1;
	case _h4_field_type_word_integer: return 2;
	case _h4_field_type_dword_integer: return 4;
	case _h4_field_type_qword_integer: return 8;
	}
	throw;
}

inline const char* h4_field_type_to_generic_field_type(e_h4_field_type field_type)
{
	switch (field_type)
	{
	case _h4_field_type_string:										return "_field_string";
	case _h4_field_type_long_string:								return "_field_long_string";
	case _h4_field_type_string_id:									return "_field_string_id";
	case _h4_field_type_old_string_id:								return "_field_old_string_id";
	case _h4_field_type_char_integer:								return "_field_char_integer";
	case _h4_field_type_short_integer:								return "_field_short_integer";
	case _h4_field_type_long_integer:								return "_field_long_integer";
	case _h4_field_type_int64_integer:								return "_field_int64_integer";
	case _h4_field_type_angle:										return "_field_angle";
	case _h4_field_type_tag:										return "_field_tag";
	case _h4_field_type_char_enum:									return "_field_char_enum";
	case _h4_field_type_enum:										return "_field_enum";
	case _h4_field_type_long_enum:									return "_field_long_enum";
	case _h4_field_type_long_flags:									return "_field_long_flags";
	case _h4_field_type_word_flags:									return "_field_word_flags";
	case _h4_field_type_byte_flags:									return "_field_byte_flags";
	case _h4_field_type_point_2d:									return "_field_point_2d";
	case _h4_field_type_rectangle_2d:								return "_field_rectangle_2d";
	case _h4_field_type_rgb_color:									return "_field_rgb_color";
	case _h4_field_type_argb_color:									return "_field_argb_color";
	case _h4_field_type_real:										return "_field_real";
	case _h4_field_type_real_fraction:								return "_field_real_fraction";
	case _h4_field_type_real_point_2d:								return "_field_real_point_2d";
	case _h4_field_type_real_point_3d:								return "_field_real_point_3d";
	case _h4_field_type_real_vector_2d:								return "_field_real_vector_2d";
	case _h4_field_type_real_vector_3d:								return "_field_real_vector_3d";
	case _h4_field_type_real_quaternion:							return "_field_real_quaternion";
	case _h4_field_type_real_euler_angles_2d:						return "_field_real_euler_angles_2d";
	case _h4_field_type_real_euler_angles_3d:						return "_field_real_euler_angles_3d";
	case _h4_field_type_real_plane_2d:								return "_field_real_plane_2d";
	case _h4_field_type_real_plane_3d:								return "_field_real_plane_3d";
	case _h4_field_type_real_rgb_color:								return "_field_real_rgb_color";
	case _h4_field_type_real_argb_color:							return "_field_real_argb_color";
	case _h4_field_type_real_hsv_color:								return "_field_real_hsv_color";
	case _h4_field_type_real_ahsv_color:							return "_field_real_ahsv_color";
	case _h4_field_type_short_bounds:								return "_field_short_bounds";
	case _h4_field_type_angle_bounds:								return "_field_angle_bounds";
	case _h4_field_type_real_bounds:								return "_field_real_bounds";
	case _h4_field_type_real_fraction_bounds:						return "_field_real_fraction_bounds";
	case _h4_field_type_tag_reference:								return "_field_tag_reference";
	case _h4_field_type_block:										return "_field_block";
	case _h4_field_type_long_block_flags:							return "_field_long_block_flags";
	case _h4_field_type_word_block_flags:							return "_field_word_block_flags";
	case _h4_field_type_byte_block_flags:							return "_field_byte_block_flags";
	case _h4_field_type_char_block_index:							return "_field_char_block_index";
	case _h4_field_type_short_block_index:							return "_field_short_block_index";
	case _h4_field_type_long_block_index:							return "_field_long_block_index";
	case _h4_field_type_custom_char_block_index:					return "_field_custom_char_block_index";
	case _h4_field_type_custom_short_block_index:					return "_field_custom_short_block_index";
	case _h4_field_type_custom_long_block_index:					return "_field_custom_long_block_index";
	case _h4_field_type_data:										return "_field_data";
	case _h4_field_type_vertex_buffer:								return "_field_vertex_buffer";
	case _h4_field_type_pad:										return "_field_pad";
	case _h4_field_type_useless_pad:								return "_field_useless_pad";
	case _h4_field_type_skip:										return "_field_skip";
	case _h4_field_type_non_cache_runtime_value:					return "_field_non_cache_runtime_value";
	case _h4_field_type_explanation:								return "_field_explanation";
	case _h4_field_type_custom:										return "_field_custom";
	case _h4_field_type_struct:										return "_field_struct";
	case _h4_field_type_array:										return "_field_array";
	case _h4_field_type_pageable:									return "_field_pageable";
	case _h4_field_type_api_interop:								return "_field_api_interop";
	case _h4_field_type_terminator:									return "_field_terminator";
	case _h4_field_type_byte_integer:								return "_field_byte_integer";
	case _h4_field_type_word_integer:								return "_field_word_integer";
	case _h4_field_type_dword_integer:								return "_field_dword_integer";
	case _h4_field_type_qword_integer:								return "_field_qword_integer";
	}
	throw;
}

enum e_h4_custom_field_type
{
	_h4_custom_field_function_group_begin = 'fgrb',
	_h4_custom_field_function_group_end = 'fgre',
	_h4_custom_field_point = 'poin',
	_h4_custom_field_orientation = 'orie',
	_h4_custom_field_scale = 'scal',
	_h4_custom_field_decibels = '+dB+',
	_h4_custom_field_cents = 'cent',
	_h4_custom_field_zero_data = 'nuke',
	_h4_custom_field_hide = 'ugly',
	_h4_custom_field_hidd_begin = 'hide',
	_h4_custom_field_hidd_end = 'edih',
	_h4_custom_field_filter = 'filt',
	_h4_custom_field_type = 'type',
	_h4_custom_field_name = 'name',
	_h4_custom_field_marker = 'amkr',
	_h4_custom_field_slider_editor = 'sled',
	_h4_custom_field_halo_script_block = 'hsbl',
	_h4_custom_field_unknown_facing = 'cfpf',

	_h4_custom_field_unknown_checksum_begin = 'dnc+',
	_h4_custom_field_unknown_checksum_end = 'dnc-',

	_h4_custom_field_cinematic_playback = 'cnpb',
	_h4_custom_field_cinematic_scene_flags = 'csfs',
	_h4_custom_field_cinematic_frame_index = 'cifi',
	_h4_custom_field_cinematic_version = 'cvmf',
	_h4_custom_field_cinematic_dynamic_light = 'cdlt',
	_h4_custom_field_camera_matrix_editor = 'cmed',
	_h4_custom_field_loop_cinematic_shot = 'lpsh',
	_h4_custom_field_loop_cinematic_scene = 'lpsc',

	_h4_custom_field_function_input_scalar = 'fnin',
	_h4_custom_field_function_input_range = 'fnir',
	_h4_custom_field_function_output_modifier = 'fnom',
	_h4_custom_field_function_unknown = 'fn**',

	_h4_custom_field_pathfinding = 'path',
	_h4_custom_field_object_id = 'obj#',
	_h4_custom_field_object_variant = 'vari',
	_h4_custom_field_environment_unknown = 'envf',
	_h4_custom_field_squad_template = 'sqdt',
	_h4_custom_field_bitmap_show = 'bshw',
	_h4_custom_field_manual_bsp_flags = 'mbsp',
	_h4_custom_field_scenario_zone_set_index = 'szsi',

	_h4_custom_field_block_index_flags = 'bifs',
	_h4_custom_field_block_flags_32bit = 'bf32',

	_h4_custom_field_shader_template = 'tmpl',
	_h4_custom_field_shader_unknown = 'ick!',

	_h4_custom_field_import_model = 'ipmi',
	_h4_custom_field_high_level_model_tag = 'hlmt',

	_h4_custom_field_sound_player = 'snpl',
	_h4_custom_field_unknown_player = 'mkpl',

	_h4_custom_field_unknown_maeo = 'maeo',
	_h4_custom_field_unknown_ohoc = 'ohoc',
	_h4_custom_field_unknown_function = 'coff',
	_h4_custom_field_unknown_compile = 'ctcd',

	_h4_custom_field_decorator_brush_unknown = 'cbif',
	_h4_custom_field_text_unknown = 'tcwd',
	_h4_custom_field_unknown_ugh = 'ugh@',
	_h4_custom_field_unknown_mela = 'mela',
	_h4_custom_field_unknown_begin = 'ifp+',
	_h4_custom_field_unknown_end = 'ifp-',

	_h4_custom_field_authored_light_probe = 'aulp',
	_h4_custom_field_particle_estimate_overdraw_unknown = 'eoci',
	_h4_custom_field_hologram_light = 'holl',
	_h4_custom_field_object_editor = 'obed',

};

inline const char* h4_custom_field_type_to_generic_custom_field_type(e_h4_custom_field_type custom_field_type)
{
	switch (custom_field_type)
	{
	case _h4_custom_field_function_group_begin:						return "_custom_field_function_group_begin";
	case _h4_custom_field_function_group_end:					  	return "_custom_field_function_group_end";
	case _h4_custom_field_point:									return "_custom_field_point";
	case _h4_custom_field_orientation:							  	return "_custom_field_orientation";
	case _h4_custom_field_scale:									return "_custom_field_scale";
	case _h4_custom_field_decibels:								  	return "_custom_field_decibels";
	case _h4_custom_field_cents:									return "_custom_field_cents";
	case _h4_custom_field_zero_data:								return "_custom_field_zero_data";
	case _h4_custom_field_hide:									  	return "_custom_field_hide";
	case _h4_custom_field_hidd_begin:							  	return "_custom_field_hidd_begin";
	case _h4_custom_field_hidd_end:								  	return "_custom_field_hidd_end";
	case _h4_custom_field_filter:								  	return "_custom_field_filter";
	case _h4_custom_field_type:									  	return "_custom_field_type";
	case _h4_custom_field_name:									  	return "_custom_field_name";
	case _h4_custom_field_marker:								  	return "_custom_field_marker";
	case _h4_custom_field_slider_editor:							return "_custom_field_slider_editor";
	case _h4_custom_field_halo_script_block:						return "_custom_field_halo_script_block";
	case _h4_custom_field_unknown_facing:						  	return "_custom_field_unknown_facing";
	case _h4_custom_field_unknown_checksum_begin:				  	return "_custom_field_unknown_checksum_begin";
	case _h4_custom_field_unknown_checksum_end:					  	return "_custom_field_unknown_checksum_end";
	case _h4_custom_field_cinematic_playback:					  	return "_custom_field_cinematic_playback";
	case _h4_custom_field_cinematic_scene_flags:					return "_custom_field_cinematic_scene_flags";
	case _h4_custom_field_cinematic_frame_index:					return "_custom_field_cinematic_frame_index";
	case _h4_custom_field_cinematic_version:						return "_custom_field_cinematic_version";
	case _h4_custom_field_cinematic_dynamic_light:					return "_custom_field_cinematic_dynamic_light";
	case _h4_custom_field_camera_matrix_editor:					  	return "_custom_field_camera_matrix_editor";
	case _h4_custom_field_loop_cinematic_shot:					  	return "_custom_field_loop_cinematic_shot";
	case _h4_custom_field_loop_cinematic_scene:					  	return "_custom_field_loop_cinematic_scene";
	case _h4_custom_field_function_input_scalar:					return "_custom_field_function_input_scalar";
	case _h4_custom_field_function_input_range:					  	return "_custom_field_function_input_range";
	case _h4_custom_field_function_output_modifier:				  	return "_custom_field_function_output_modifier";
	case _h4_custom_field_function_unknown:						  	return "_custom_field_function_unknown";
	case _h4_custom_field_pathfinding:							  	return "_custom_field_pathfinding";
	case _h4_custom_field_object_id:								return "_custom_field_object_id";
	case _h4_custom_field_object_variant:						  	return "_custom_field_object_variant";
	case _h4_custom_field_environment_unknown:					  	return "_custom_field_environment_unknown";
	case _h4_custom_field_squad_template:						  	return "_custom_field_squad_template";
	case _h4_custom_field_bitmap_show:							  	return "_custom_field_bitmap_show";
	case _h4_custom_field_manual_bsp_flags:						  	return "_custom_field_manual_bsp_flags";
	case _h4_custom_field_scenario_zone_set_index:				  	return "_custom_field_scenario_zone_set_index";
	case _h4_custom_field_block_index_flags:						return "_custom_field_block_index_flags";
	case _h4_custom_field_block_flags_32bit:						return "_custom_field_block_flags_32bit";
	case _h4_custom_field_shader_template:						  	return "_custom_field_shader_template";
	case _h4_custom_field_shader_unknown:						  	return "_custom_field_shader_unknown";
	case _h4_custom_field_import_model:							  	return "_custom_field_import_model";
	case _h4_custom_field_high_level_model_tag:					  	return "_custom_field_high_level_model_tag";
	case _h4_custom_field_sound_player:							  	return "_custom_field_sound_player";
	case _h4_custom_field_unknown_player:						  	return "_custom_field_unknown_player";
	case _h4_custom_field_unknown_maeo:							  	return "_custom_field_unknown_maeo";
	case _h4_custom_field_unknown_ohoc:							  	return "_custom_field_unknown_ohoc";
	case _h4_custom_field_unknown_function:						  	return "_custom_field_unknown_function";
	case _h4_custom_field_unknown_compile:						  	return "_custom_field_unknown_compile";
	case _h4_custom_field_decorator_brush_unknown:				  	return "_custom_field_decorator_brush_unknown";
	case _h4_custom_field_text_unknown:							  	return "_custom_field_text_unknown";
	case _h4_custom_field_unknown_ugh:							  	return "_custom_field_unknown_ugh";
	case _h4_custom_field_unknown_mela:							  	return "_custom_field_unknown_mela";
	case _h4_custom_field_unknown_begin:							return "_custom_field_unknown_begin";
	case _h4_custom_field_unknown_end:							  	return "_custom_field_unknown_end";
	case _h4_custom_field_authored_light_probe:						return "_custom_field_authored_light_probe";
	case _h4_custom_field_particle_estimate_overdraw_unknown:		return "_custom_field_particle_estimate_overdraw_unknown";
	case _h4_custom_field_hologram_light:							return "_custom_field_hologram_light";
	case _h4_custom_field_object_editor:							return "_custom_field_object_editor";
	}
	throw;
}





