#include "mandrilllib-private-pch.h"

c_gen3_resource_manager::c_gen3_resource_manager(c_gen3_cache_file& cache_file) :
	cache_file(cache_file)
{
	cache_file.on_init.register_callback(this, [this] { init_resources(); });
	resource_files.push_back(&cache_file);
}

c_gen3_resource_manager::~c_gen3_resource_manager()
{
	deinit_resources();
}

#include <zlib/zlib/zlib.h>

enum e_bitmap_format3
{
	_bitmap_format3_a8,
	_bitmap_format3_y8,
	_bitmap_format3_ay8,
	_bitmap_format3_a8y8,
	_bitmap_format3_unused1,
	_bitmap_format3_unused2,
	_bitmap_format3_r5g6b5,
	_bitmap_format3_unused3,
	_bitmap_format3_a1r5g5b5,
	_bitmap_format3_a4r4g4b4,
	_bitmap_format3_x8r8g8b8,
	_bitmap_format3_a8r8g8b8,
	_bitmap_format3_unused4,
	_bitmap_format3_dxt5_bias_alpha,
	_bitmap_format3_dxt1,
	_bitmap_format3_dxt3,
	_bitmap_format3_dxt5,
	_bitmap_format3_a4r4g4b4_font,
	_bitmap_format3_unused7,
	_bitmap_format3_unused8,
	_bitmap_format3_software_rgbfp32,
	_bitmap_format3_unused9,
	_bitmap_format3_v8u8,
	_bitmap_format3_g8b8,
	_bitmap_format3_abgrfp32,
	_bitmap_format3_abgrfp16,
	_bitmap_format3_16f_mono,
	_bitmap_format3_16f_red,
	_bitmap_format3_q8w8v8u8,
	_bitmap_format3_a2r10g10b10,
	_bitmap_format3_a16b16g16r16,
	_bitmap_format3_v16u16,
	_bitmap_format3_l16,
	_bitmap_format3_r16g16,
	_bitmap_format3_signedr16g16b16a16,
	_bitmap_format3_dxt3a,
	_bitmap_format3_dxt5a,
	_bitmap_format3_dxt3a_1111,
	_bitmap_format3_dxn,
	_bitmap_format3_ctx1,
	_bitmap_format3_dxt3a_alpha,
	_bitmap_format3_dxt3a_mono,
	_bitmap_format3_dxt5a_alpha,
	_bitmap_format3_dxt5a_mono,
	_bitmap_format3_dxn_mono_alpha,
	_bitmap_format3_dxt5_red,
	_bitmap_format3_dxt5_green,
	_bitmap_format3_dxt5_blue,
	_bitmap_format3_depth_24
};

const DirectX::DDS_PIXELFORMAT* bitmap_format_to_dds_pixel_format(e_bitmap_format3 bitmap_format, bool& is_linear_format)
{
	using namespace DirectX;

	is_linear_format = false;

	switch (bitmap_format)
	{
	case _bitmap_format3_a8:														return &DDSPF_A8;
	case _bitmap_format3_y8:														return &DDSPF_L8;
	case _bitmap_format3_ay8:														return &DDSPF_A8L8;
	case _bitmap_format3_a8y8:														return &DDSPF_A8L8_ALT;
	case _bitmap_format3_unused1:													return nullptr;
	case _bitmap_format3_unused2:													return nullptr;
	case _bitmap_format3_r5g6b5:													return &DDSPF_R5G6B5;
	case _bitmap_format3_unused3:													return nullptr;
	case _bitmap_format3_a1r5g5b5:													return &DDSPF_A1R5G5B5;
	case _bitmap_format3_a4r4g4b4:													return &DDSPF_A4R4G4B4;
	case _bitmap_format3_x8r8g8b8:													return &DDSPF_X8R8G8B8;
	case _bitmap_format3_a8r8g8b8:													return &DDSPF_A8R8G8B8;
	case _bitmap_format3_unused4:													return nullptr;
	case _bitmap_format3_dxt5_bias_alpha:											return nullptr;
	case _bitmap_format3_dxt1:							is_linear_format = true;	return &DDSPF_DXT1;
	case _bitmap_format3_dxt3:							is_linear_format = true;	return &DDSPF_DXT3;
	case _bitmap_format3_dxt5:							is_linear_format = true;	return &DDSPF_DXT5;
	case _bitmap_format3_a4r4g4b4_font:												return &DDSPF_A4R4G4B4;
	case _bitmap_format3_unused7:													return nullptr;
	case _bitmap_format3_unused8:													return nullptr;
	case _bitmap_format3_software_rgbfp32:											return nullptr; // #TODO: DX10 header
	case _bitmap_format3_unused9:													return nullptr;
	case _bitmap_format3_v8u8:														return &DDSPF_V8U8;
	case _bitmap_format3_g8b8:														return nullptr; // unknown
	case _bitmap_format3_abgrfp32:													return nullptr; // DirectX 10
	case _bitmap_format3_abgrfp16:													return nullptr; // DirectX 10
	case _bitmap_format3_16f_mono:													return &DDSPF_L16;
	case _bitmap_format3_16f_red:													return nullptr;
	case _bitmap_format3_q8w8v8u8:													return &DDSPF_Q8W8V8U8;
	case _bitmap_format3_a2r10g10b10:												return nullptr; // DirectX 10
	case _bitmap_format3_a16b16g16r16:												return nullptr; // DirectX 10
	case _bitmap_format3_v16u16:													return &DDSPF_V16U16;
	case _bitmap_format3_l16:														return &DDSPF_L16;
	case _bitmap_format3_r16g16:  // DirectX 10 ?
	{
		static const DDS_PIXELFORMAT DDSPF_R16G16 = { sizeof(DDS_PIXELFORMAT), DDS_RGB,  0, 32, 0xffff0000, 0x0000ffff, 0x00000000, 0x00000000 };
		return &DDSPF_R16G16;
	}
	case _bitmap_format3_signedr16g16b16a16:										return nullptr; // DirectX 10
	case _bitmap_format3_dxt3a:														return nullptr;
	case _bitmap_format3_dxt5a:														return nullptr;
	case _bitmap_format3_dxt3a_1111:												return nullptr;
	case _bitmap_format3_dxn:							is_linear_format = true;	return &DDSPF_BC5_SNORM;
	case _bitmap_format3_ctx1:														return nullptr; // Xbox 360
	case _bitmap_format3_dxt3a_alpha:					is_linear_format = true;	return &DDSPF_DXT3;
	case _bitmap_format3_dxt3a_mono:					is_linear_format = true;	return &DDSPF_DXT3;
	case _bitmap_format3_dxt5a_alpha:					is_linear_format = true;	return &DDSPF_DXT5;
	case _bitmap_format3_dxt5a_mono:					is_linear_format = true;	return &DDSPF_DXT5;
	case _bitmap_format3_dxn_mono_alpha:											return nullptr;
	case _bitmap_format3_dxt5_red:													return nullptr;
	case _bitmap_format3_dxt5_green:												return nullptr;
	case _bitmap_format3_dxt5_blue:													return nullptr;
	case _bitmap_format3_depth_24:													return nullptr;
	default: throw;
	}
}

void c_gen3_resource_manager::init_resources()
{
	c_tag_group_interface* cache_file_resource_gestalt_group = cache_file.get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_GESTALT_TAG);
	if (cache_file_resource_gestalt_group == nullptr || cache_file_resource_gestalt_group->get_tag_interfaces_count() == 0)
	{
		return;
	}

	c_tag_interface* cache_file_resource_gestalt = *cache_file_resource_gestalt_group->get_tag_interfaces();
	ASSERT(cache_file_resource_gestalt != nullptr);
	ASSERT(!cache_file_resource_gestalt->is_null());

	if (v_tag<blofeld::haloreach::s_cache_file_resource_gestalt_block_struct>* haloreach_cache_file_resource_gestalt = dynamic_cast<decltype(haloreach_cache_file_resource_gestalt)>(cache_file_resource_gestalt->get_virtual_tag_interface()))
	{
		using namespace blofeld::haloreach;

		c_tag_group_interface* cache_file_resource_layout_table_group = cache_file.get_tag_group_interface_by_group_id(blofeld::CACHE_FILE_RESOURCE_LAYOUT_TABLE_TAG);
		if (cache_file_resource_layout_table_group == nullptr || cache_file_resource_layout_table_group->get_tag_interfaces_count() == 0)
		{
			return;
		}

		c_tag_interface* cache_file_resource_layout_table = *cache_file_resource_layout_table_group->get_tag_interfaces();
		ASSERT(cache_file_resource_layout_table != nullptr);
		ASSERT(!cache_file_resource_layout_table->is_null());

		v_tag<s_cache_file_resource_layout_table_block_struct>* haloreach_cache_file_resource_layout_table = dynamic_cast<decltype(haloreach_cache_file_resource_layout_table)>(cache_file_resource_layout_table->get_virtual_tag_interface());
		ASSERT(haloreach_cache_file_resource_layout_table != nullptr);

		for (auto x : haloreach_cache_file_resource_layout_table->shared_files_block)
		{
			c_fixed_wide_path filename;
			filename.format(L"%S", x->dvd_relative_path.get_string() + strlen("maps\\"));
			c_fixed_wide_path filepath;
			PathCombineW(filepath.str(), cache_file.get_directory(), filename.c_str());
			c_cache_file* new_cache_file = c_cache_file::create_cache_file(filepath.c_str());
			c_gen3_cache_file* gen3_cache_file = dynamic_cast<c_gen3_cache_file*>(new_cache_file);
			if (new_cache_file)
			{
				ASSERT(gen3_cache_file != nullptr);
			}
			resource_files.push_back(gen3_cache_file);
		}

		tbb::task_group g;
		for (auto file_page : haloreach_cache_file_resource_layout_table->file_pages_block)
		{
			uint32_t resource_file_index = static_cast<uint32_t>(file_page->shared_file + 1);
			c_gen3_cache_file* resource_file = resource_files[resource_file_index];
			ASSERT(resource_file != nullptr);

			char* const raw_resource_data = resource_file->get_resources_section().data + file_page->file_offset;

			c_gen3_file_page_manager* file_page_manager = new c_gen3_file_page_manager(
				*this,
				raw_resource_data,
				file_page->file_size,
				file_page->size,
				file_page->codec,
				&g);

			file_page_managers.push_back(file_page_manager);
		}
		g.wait();

		resources.resize(haloreach_cache_file_resource_gestalt->resources_block.count);
		for (uint32_t resources_block_index = 0; resources_block_index < haloreach_cache_file_resource_gestalt->resources_block.count; resources_block_index++)
		{
			v_struct<s_cache_file_resource_data_block_block_struct>& cache_file_resource_data_block = haloreach_cache_file_resource_gestalt->resources_block[resources_block_index];
			c_tag_interface* owner = cache_file_resource_data_block.owner_tag;

			c_gen3_resource* resource = new c_gen3_resource(*this);

			if (~cache_file_resource_data_block.page != 0)
			{
				v_struct<s_cache_file_resource_section_block_block_struct>& cache_file_resource_section = haloreach_cache_file_resource_layout_table->sections_block[cache_file_resource_data_block.page];

				for (uint32_t resource_section_type = 0; resource_section_type < 2; resource_section_type++)
				{
					short page_index = cache_file_resource_section.file_page_indexes[resource_section_type].page_index;
					if (~page_index == 0)
					{
						continue;
					}

					long offset = cache_file_resource_section.page_offsets[resource_section_type].offset;

					//auto& file_page = haloreach_cache_file_resource_layout_table->file_pages_block[page_index];

					auto file_page_manager = file_page_managers[page_index];

					char* resource_data = file_page_manager->resource_data + offset;

					if (resource_section_type == 1)
					{
						if (v_tag<s_bitmap_block_struct>* haloreach_bitmap = dynamic_cast<decltype(haloreach_bitmap)>(owner->get_virtual_tag_interface()))
						{
							for (uint32_t bitmap_index = 0; bitmap_index < haloreach_bitmap->bitmaps_block.count; bitmap_index++)
							{
								v_struct<s_bitmap_data_block_def_block_struct>& bitmap_data_block_def = haloreach_bitmap->bitmaps_block[bitmap_index];

								char* pixel_data = resource_data + bitmap_data_block_def.pixels_offset_bytes;

								char* high_res_data = pixel_data;
								char* low_res_data = pixel_data + bitmap_data_block_def.high_res_pixels_size;

								using namespace DirectX;
								size_t dds_file_data_size = sizeof(int) + sizeof(DDS_HEADER) + bitmap_data_block_def.high_res_pixels_size;
								char* dds_file_data = new char[dds_file_data_size] {};
								bool is_linear_format = false;
								const DirectX::DDS_PIXELFORMAT* dds_pixel_format = bitmap_format_to_dds_pixel_format((e_bitmap_format3)bitmap_data_block_def.format, is_linear_format);
								if (dds_pixel_format == nullptr)
								{
									continue;
								}

								{
									int& dds_magic = *reinterpret_cast<int*>(dds_file_data);
									DDS_HEADER& dds_header = *reinterpret_cast<DDS_HEADER*>(&dds_magic + 1);
									char* dds_data = reinterpret_cast<char*>(&dds_header + 1);

									dds_magic = DDS_MAGIC;
									dds_header.size = sizeof(DDS_HEADER);											
									dds_header.flags = DDS_HEADER_FLAGS_TEXTURE | DDS_HEADER_FLAGS_MIPMAP;
									dds_header.height = bitmap_data_block_def.height;
									dds_header.width = bitmap_data_block_def.width;
									dds_header.depth = 0;															
									dds_header.mipMapCount = 1; // #TODO: export other mips
									dds_header.ddspf = *dds_pixel_format;
									dds_header.caps = DDS_SURFACE_FLAGS_TEXTURE | DDS_SURFACE_FLAGS_MIPMAP;

									if (is_linear_format)
									{
										dds_header.flags |= DDS_HEADER_FLAGS_LINEARSIZE;
										dds_header.pitchOrLinearSize = bitmap_data_block_def.high_res_pixels_size;
									}
									else
									{
										// #TODO: calculate pitch correctly
										dds_header.pitchOrLinearSize = (dds_header.ddspf.RGBBitCount * dds_header.width) / 8;
									}

									memcpy(dds_data, high_res_data, bitmap_data_block_def.high_res_pixels_size);
								}

								c_gen3_tag_interface* tag_interface = dynamic_cast<c_gen3_tag_interface*>(&haloreach_bitmap->tag_interface);
								ASSERT(tag_interface != nullptr);

								c_fixed_path filepath;
								if (haloreach_bitmap->bitmaps_block.count == 1)
								{
									filepath.format("data\\%s.dds", tag_interface->get_filepath());
								}
								else
								{
									filepath.format("data\\%s[%u].dds", tag_interface->get_filepath(), bitmap_index);
								}
								filesystem_write_file_from_memory(filepath.c_str(), dds_file_data, dds_file_data_size);
								delete[] dds_file_data;

								debug_point;
								break;
							}

							debug_point;
						}
					}

					debug_point;
				}
			}

			resources[resources_block_index] = resource;
		}
	}

}

void c_gen3_resource_manager::deinit_resources()
{

}

c_gen3_resource::c_gen3_resource(c_gen3_resource_manager& resource_manager) :
	resource_manager(resource_manager)
{

}

c_gen3_file_page_manager::c_gen3_file_page_manager(
	c_gen3_resource_manager& resource_manager,
	char* raw_resource_data,
	uint32_t compressed_size,
	uint32_t uncompressed_size,
	int32_t codec,
	tbb::task_group* g) :
	resource_manager(resource_manager),
	raw_resource_data(raw_resource_data),
	compressed_size(compressed_size),
	uncompressed_size(uncompressed_size),
	codec(codec),
	resource_data(nullptr)
{
	if (g != nullptr)
	{
		g->run([this] { read_file_page(); });
	}
	else
	{
		read_file_page();
	}
}

c_gen3_file_page_manager::~c_gen3_file_page_manager()
{
	if (resource_data)
	{
		delete[] resource_data;
	}
}

void c_gen3_file_page_manager::read_file_page()
{
	resource_data = new char[uncompressed_size];

	switch (codec)
	{
	case -1:
	{
		memcpy(resource_data, raw_resource_data, uncompressed_size);
		break;
	}
	case 0:
	{
		z_stream stream{};
		stream.avail_out = uncompressed_size;
		stream.next_out = (Bytef*)resource_data;
		stream.avail_in = compressed_size;
		stream.next_in = (Bytef*)raw_resource_data;
		int inflateInitResult = inflateInit2(&stream, -15);
		ASSERT(inflateInitResult >= Z_OK);
		int inflateResult = inflate(&stream, Z_SYNC_FLUSH);
		ASSERT(inflateResult >= Z_OK);
		int inflateEndResult = inflateEnd(&stream);
		ASSERT(inflateEndResult >= Z_OK);

		break;
	}
	default:
		FATAL_ERROR(L"Unsupported resource file page codec");
	}
}
