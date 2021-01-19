#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_ERROR_REPORT_CATEGORIES_BLOCK_ID { 0x3CBB78D5, 0xCA074D83, 0x8994291A, 0x8E13F496 }
	TAG_BLOCK(
		global_error_report_categories_block,
		"error report category",
		MAXIMUM_ERROR_REPORT_CATEGORIES,
		"error_report_category",
		GLOBAL_ERROR_REPORT_CATEGORIES_BLOCK_ID)
	{
		{ _field_long_string, "name^*" },
		{ _field_enum, "report type*", &error_report_types },
		{ _field_word_flags, "flags*", &error_report_flags },
		{ _field_short_integer, "runtime generation flags!" },
		{ _field_pad, "WVTP", 2 },
		{ _field_long_integer, "runtime something~!" },
		{ _field_block, "reports*", &error_reports_block },
		{ _field_terminator }
	};

	#define ERROR_REPORTS_BLOCK_ID { 0xEE6AAB20, 0x3227499F, 0x914508D6, 0x40FCAA9E }
	TAG_BLOCK(
		error_reports_block,
		"error report",
		MAXIMUM_REPORTS_PER_ERROR_REPORT_CATEGORY,
		"error_report",
		ERROR_REPORTS_BLOCK_ID)
	{
		{ _field_char_enum, "type*", &error_report_types },
		{ _field_char_enum, "source*", &error_report_source },
		{ _field_word_flags, "flags*", &error_report_flags },
		{ _field_data, "text*" },
		{ _field_long_integer, "source identifier*" },
		{ _field_string, "source filename*" },
		{ _field_long_integer, "source line number*" },
		{ _field_block, "vertices*", &error_report_vertices_block },
		{ _field_block, "vectors*", &error_report_vectors_block },
		{ _field_block, "lines*", &error_report_lines_block },
		{ _field_block, "triangles*", &error_report_triangles_block },
		{ _field_block, "quads*", &error_report_quads_block },
		{ _field_block, "comments*", &error_report_comments_block },
		{ _field_long_integer, "report key*" },
		{ _field_long_integer, "node index*" },
		{ _field_real_bounds, "bounds x*" },
		{ _field_real_bounds, "bounds y*" },
		{ _field_real_bounds, "bounds z*" },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	#define ERROR_REPORT_VERTICES_BLOCK_ID { 0xB44D11D1, 0xA884463D, 0xB9552513, 0x0E390450 }
	TAG_BLOCK(
		error_report_vertices_block,
		"error report vertex",
		MAXIMUM_VERTICES_PER_ERROR_REPORT,
		"error_report_vertex",
		ERROR_REPORT_VERTICES_BLOCK_ID)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_real_argb_color, "color*" },
		{ _field_real, "screen size*" },
		{ _field_terminator }
	};

	#define ERROR_REPORT_VECTORS_BLOCK_ID { 0xF617E038, 0x0B4E4E8D, 0xAF4F86B9, 0x02745E1F }
	TAG_BLOCK(
		error_report_vectors_block,
		"error report vector",
		MAXIMUM_VECTORS_PER_ERROR_REPORT,
		"error_report_vector",
		ERROR_REPORT_VECTORS_BLOCK_ID)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_real_argb_color, "color*" },
		{ _field_real_vector_3d, "normal*" },
		{ _field_real, "screen length*" },
		{ _field_terminator }
	};

	#define ERROR_REPORT_LINES_BLOCK_ID { 0x1C172D3C, 0x604A4356, 0x8F1BDE48, 0xE0CA8284 }
	TAG_BLOCK(
		error_report_lines_block,
		"error report line",
		MAXIMUM_LINES_PER_ERROR_REPORT,
		"error_report_line",
		ERROR_REPORT_LINES_BLOCK_ID)
	{
		{ _field_array, "points*", &error_report_line_point_array },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	#define ERROR_REPORT_TRIANGLES_BLOCK_ID { 0xF926E761, 0x001244E3, 0x85173116, 0x2B96347A }
	TAG_BLOCK(
		error_report_triangles_block,
		"error report triangle",
		MAXIMUM_TRIANGLES_PER_ERROR_REPORT,
		"error_report_triangle",
		ERROR_REPORT_TRIANGLES_BLOCK_ID)
	{
		{ _field_array, "points*", &error_report_triangle_point_array },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	#define ERROR_REPORT_QUADS_BLOCK_ID { 0xD1071621, 0xE7D84305, 0x8AEA9FCC, 0xC52955BF }
	TAG_BLOCK(
		error_report_quads_block,
		"error report quad",
		MAXIMUM_QUADS_PER_ERROR_REPORT,
		"error_report_quad",
		ERROR_REPORT_QUADS_BLOCK_ID)
	{
		{ _field_array, "points*", &error_report_quad_point_array },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	#define ERROR_REPORT_COMMENTS_BLOCK_ID { 0x709A9566, 0xDEA34617, 0x8AFF50B9, 0xDB6DE950 }
	TAG_BLOCK(
		error_report_comments_block,
		"error report comment",
		MAXIMUM_COMMENTS_PER_ERROR_REPORT,
		"error_report_comment",
		ERROR_REPORT_COMMENTS_BLOCK_ID)
	{
		{ _field_data, "text*" },
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_real_argb_color, "color*" },
		{ _field_terminator }
	};

	TAG_ARRAY(error_point_node_index_array, MAXIMUM_NODE_INDICES_PER_ERROR_POINT)
	{
		{ _field_char_integer, "node index*" },
		{ _field_terminator }
	};

	TAG_ARRAY(error_point_node_weight_array, MAXIMUM_NODE_INDICES_PER_ERROR_POINT)
	{
		{ _field_real, "node weight*" },
		{ _field_terminator }
	};

	TAG_ARRAY(error_report_line_point_array, k_vertices_per_line_count)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_terminator }
	};

	TAG_ARRAY(error_report_triangle_point_array, k_vertices_per_triangle_count)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_terminator }
	};

	TAG_ARRAY(error_report_quad_point_array, k_vertices_per_quadrilateral_count)
	{
		{ _field_struct, "point", &error_report_point_definition },
		{ _field_terminator }
	};

	#define ERROR_REPORT_POINT_DEFINITION_ID { 0xB6C2368C, 0x78534A62, 0x9882F40C, 0xE2181EF5 }
	TAG_STRUCT(
		error_report_point_definition,
		"error_report_point_definition",
		"error_report_point",
		ERROR_REPORT_POINT_DEFINITION_ID)
	{
		{ _field_real_point_3d, "position*" },
		{ _field_array, "node indices*", &error_point_node_index_array },
		{ _field_array, "node weights*", &error_point_node_weight_array },
		{ _field_terminator }
	};

	STRINGS(error_report_types)
	{
		"silent",
		"comment",
		"warning",
		"error"
	};
	STRING_LIST(error_report_types, error_report_types_strings, _countof(error_report_types_strings));

	STRINGS(error_report_source)
	{
		"none",
		"structure",
		"poop",
		"lightmap",
		"pathfinding"
	};
	STRING_LIST(error_report_source, error_report_source_strings, _countof(error_report_source_strings));

	STRINGS(error_report_flags)
	{
		"rendered",
		"tangent-space",
		"non-critical",
		"lightmap light",
		"report key is valid"
	};
	STRING_LIST(error_report_flags, error_report_flags_strings, _countof(error_report_flags_strings));

} // namespace macaque

} // namespace blofeld

