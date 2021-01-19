#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define POLYART_ASSET_STRUCT_DEFINITION_ID { 0x45F0FE75, 0xE82041BA, 0x98938411, 0xCA2B86CF }
	TAG_BLOCK(
		polyart_asset_block,
		"polyart_asset_block",
		1,
		"PolyartAsset",
		POLYART_ASSET_STRUCT_DEFINITION_ID)
	{
		{ _field_char_enum, "runtime flags*!", &g_polyartAssetStateFlags },
		{ _field_char_enum, "Polyart vertex type", &PolyartVertexFormatTypeEnum },
		{ _field_char_integer, "uvSet index" },
		{ _field_pad, "MERP", 1 },
		{ _field_real, "antialiasing extent size" },
		{ _field_block, "placement data", &polyartCameraBlock_block },
		{ _field_block, "vertices*", &polyartVertexBlock_block },
		{ _field_block, "indices*", &polyartIndexBlock_block },
		{ _field_block, "pc vertex buffers*", &vertexBuffersBlock_block },
		{ _field_block, "pc index buffers*", &indexBuffersBlock_block },
		{ _field_api_interop, "vertex buffer interop*", &polyartVertexBufferDescriptorStruct },
		{ _field_api_interop, "index buffer interop*", &polyartIndexBufferDescriptorStruct },
		{ _field_terminator }
	};

	TAG_GROUP(
		polyart_asset_group,
		POLYART_ASSET_TAG,
		nullptr,
		INVALID_TAG,
		polyart_asset_block );

	#define POLYARTCAMERABLOCK_ID { 0x99094E2A, 0xF7534A48, 0x81EC3343, 0x0888B0CD }
	TAG_BLOCK(
		polyartCameraBlock_block,
		"polyartCameraBlock",
		1,
		"PolyartCamera",
		POLYARTCAMERABLOCK_ID)
	{
		{ _field_real, "horizontal fov" },
		{ _field_real, "vertical fov" },
		{ _field_real, "near z plane distance" },
		{ _field_real, "far z plane distance" },
		{ _field_real_point_3d, "camera position" },
		{ _field_terminator }
	};

	#define POLYARTVERTEXBUFFERDESCRIPTORSTRUCT_ID { 0xDCA698FD, 0x811B4662, 0xA0E506EA, 0x7ED63171 }
	TAG_STRUCT(
		polyartVertexBufferDescriptorStruct,
		"polyartVertexBufferDescriptorStruct",
		"PolyartVertexBufferDescriptor",
		POLYARTVERTEXBUFFERDESCRIPTORSTRUCT_ID)
	{
		{ _field_data, "vertices*" },
		{ _field_long_integer, "vertex type*" },
		{ _field_terminator }
	};

	#define POLYARTINDEXBUFFERDESCRIPTORSTRUCT_ID { 0xC68DB74F, 0x2B9B4252, 0xB42C6C75, 0x53870BEA }
	TAG_STRUCT(
		polyartIndexBufferDescriptorStruct,
		"polyartIndexBufferDescriptorStruct",
		"PolyartIndexBufferDescriptor",
		POLYARTINDEXBUFFERDESCRIPTORSTRUCT_ID)
	{
		{ _field_data, "index_data*" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

