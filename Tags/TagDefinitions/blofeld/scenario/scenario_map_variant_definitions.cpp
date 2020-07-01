#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(mapVariantPaletteDependencyBlock, k_maximum_simultaneous_tag_instances)
	{
		{ _field_tag, "tag" },
		{ _field_terminator }
	};

	TAG_BLOCK(resourceHandleBlock, k_maximum_simultaneous_tag_instances)
	{
		{ _field_long_integer, "resourceHandle" },
		{ _field_terminator }
	};

	TAG_BLOCK(map_variant_object_variant_block, k_maximum_object_variants_per_map_variant_palette_entry)
	{
		{ _field_string_id, "display name^" },
		{ _field_tag_reference, "object", &object_reference$9 },
		{ _field_string_id, "variant name" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_struct, "resource dependencies!*", &mapVariantResourceManifest_struct_definition },

		{ _field_terminator }
	};

	TAG_BLOCK(map_variant_palette_entry_block, k_maximum_map_variant_palette_entries)
	{
		{ _field_string_id, "name^" },
		{ _field_block, "variants", &map_variant_object_variant_block_block },
		{ _field_long_integer, "maximum allowed#if this is <= 0, these are \'unlimited\' (up to a reasonable code-defined maximum)" },
		{ _field_long_integer, "price per instance" },

		{ _field_version_platform_include, _platform_type_pc, 2 },
		{ _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_long_integer, "thorage" },

		{ _field_terminator }
	};

	TAG_BLOCK(map_variant_palette_block, k_maximum_map_variant_palettes)
	{
		{ _field_string_id, "name^" },
		{ _field_byte_flags, "flags", &map_variant_palette_flags },

		{ _field_version_not_equal, _engine_type_haloreach, 1 },
		{ _field_pad, "pad", 3 },

		{ _field_version_equal, _engine_type_haloreach, 4 },
		{ _field_version_platform_include, _platform_type_pc, 3 },
		{ _field_pad, "pad", 1 },
		{ _field_char_integer, "thorage" },
		{ _field_pad, "pad", 1 },

		{ _field_block, "entries", &map_variant_palette_entry_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK(map_variant_legacy_build_info_block, k_maximum_map_variant_palettes)
	{
		{ _field_long_integer, "unknown" },				
		{ _field_long_integer, "quota count" },			
		{ _field_long_integer, "unknown" },				
		{ _field_long_integer, "unknown" },				
		{ _field_string, "build number" },				
		{ _field_terminator }
	};

	TAG_BLOCK(map_variant_legacy_palette_info_block, k_maximum_map_variant_palettes)
	{
		{ _field_block, "builds", &map_variant_legacy_build_info_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(mapVariantResourceManifest)
	{
		{ _field_block, "attachedResourceOwners", &mapVariantPaletteDependencyBlock_block },
		{ _field_block, "topLevelResourceOwners", &mapVariantPaletteDependencyBlock_block },
		{ _field_block, "attachedResources", &resourceHandleBlock_block },
		{ _field_block, "orphanedResources", &resourceHandleBlock_block },
		{ _field_terminator }
	};

	STRINGS(map_variant_palette_flags)
	{
		"hidden#this palette is only visible in superforge, and objects within it are only editable in superforge"
	};
	STRING_LIST(map_variant_palette_flags, map_variant_palette_flags_strings, _countof(map_variant_palette_flags_strings));

} // namespace blofeld

