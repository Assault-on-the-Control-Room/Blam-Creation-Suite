#include "shared-private-pch.h"

ID3D11InputLayout* BoxRenderer::pVertexLayout;
ID3D11PixelShader* BoxRenderer::pPixelShader = nullptr;
ID3D11VertexShader* BoxRenderer::pVertexShader = nullptr;
ID3D11RasterizerState* BoxRenderer::pSolidRasterState = nullptr;
ID3D11RasterizerState* BoxRenderer::pWireframeRasterState = nullptr;
ID3D11Buffer* BoxRenderer::pVertexBuffer = nullptr;
ID3D11Buffer* BoxRenderer::pSolidIndexBuffer = nullptr;
ID3D11Buffer* BoxRenderer::pWireframeIndexBuffer = nullptr;
volatile uint32_t BoxRenderer::nextConstantBufferIndex = 0;
volatile uint32_t BoxRenderer::nextBoxIndex = 0;
ID3D11Buffer* BoxRenderer::ppInstanceConstantsBuffers[c_primitive_render_manager::kNumConstantsBuffers] = {};
ID3D11Buffer* BoxRenderer::pCurrentInstanceConstantsBuffer = nullptr;
BoxRenderer::PerObjectConstants* BoxRenderer::pPerObjectConstantsArray = nullptr;

void BoxRenderer::SetupWireframeGeometry()
{
	using namespace DirectX;

	if (pWireframeIndexBuffer == nullptr)
	{
		const uint32_t boxIndices[] = {


			///*0*/ {-0.5f, -0.5f, -0.5f},
			///*1*/ {-0.5f, 0.5f, -0.5f},
			///*2*/ {0.5f, 0.5f, -0.5f},
			///*3*/ {0.5f, -0.5f, -0.5f},
			///*4*/ {-0.5f, -0.5f, 0.5f},
			///*5*/ {-0.5f, 0.5f, 0.5f},
			///*6*/ {0.5f, 0.5f, 0.5f},
			///*7*/ {0.5f, -0.5f, 0.5f},


			0, 1,
			1, 2,
			2, 3,
			3, 0,

			4, 5,
			5, 6,
			6, 7,
			7, 4,

			0, 4,
			1, 5,
			2, 6,
			3, 7
		};

		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof(boxIndices);
		bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		// Fill in the subresource data.
		D3D11_SUBRESOURCE_DATA vertexBufferSubResourceData;
		vertexBufferSubResourceData.pSysMem = boxIndices;
		vertexBufferSubResourceData.SysMemPitch = 0;
		vertexBufferSubResourceData.SysMemSlicePitch = 0;

		HRESULT createBufferResult = c_render::s_device->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &pWireframeIndexBuffer);
		ASSERT(SUCCEEDED(createBufferResult));
		ASSERT(pWireframeIndexBuffer != nullptr);
	}
}

void BoxRenderer::SetupSolidGeometry()
{
	using namespace DirectX;

	if (pVertexBuffer == nullptr)
	{
		XMFLOAT3 vertexData[] = {
			{-0.5f, -0.5f, -0.5f},
			{-0.5f, 0.5f, -0.5f},
			{0.5f, 0.5f, -0.5f},
			{0.5f, -0.5f, -0.5f},
			{-0.5f, -0.5f, 0.5f},
			{-0.5f, 0.5f, 0.5f},
			{0.5f, 0.5f, 0.5f},
			{0.5f, -0.5f, 0.5f},
		};

		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof(vertexData);
		bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		// Fill in the subresource data.
		D3D11_SUBRESOURCE_DATA vertexBufferSubResourceData;
		vertexBufferSubResourceData.pSysMem = vertexData;
		vertexBufferSubResourceData.SysMemPitch = 0;
		vertexBufferSubResourceData.SysMemSlicePitch = 0;

		HRESULT createBufferResult = c_render::s_device->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &pVertexBuffer);
		ASSERT(SUCCEEDED(createBufferResult));
		ASSERT(pVertexBuffer != nullptr);
	}

	if (pSolidIndexBuffer == nullptr)
	{
		const uint32_t boxIndices[] = {
			// front
			0,1,2,
			0,2,3,
			// back
			4,6,5,
			4,7,6,
			// left
			4,5,1,
			4,1,0,
			// right
			3,2,6,
			3,6,7,
			//top
			1,5,6,
			1,6,2,
			// bottom
			4,0,3,
			4,3,7
		};

		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DEFAULT;
		bufferDesc.ByteWidth = sizeof(boxIndices);
		bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
		bufferDesc.CPUAccessFlags = 0;
		bufferDesc.MiscFlags = 0;

		// Fill in the subresource data.
		D3D11_SUBRESOURCE_DATA vertexBufferSubResourceData;
		vertexBufferSubResourceData.pSysMem = boxIndices;
		vertexBufferSubResourceData.SysMemPitch = 0;
		vertexBufferSubResourceData.SysMemSlicePitch = 0;

		HRESULT createBufferResult = c_render::s_device->CreateBuffer(&bufferDesc, &vertexBufferSubResourceData, &pSolidIndexBuffer);
		ASSERT(SUCCEEDED(createBufferResult));
		ASSERT(pSolidIndexBuffer != nullptr);
	}
}

void BoxRenderer::SetupShaders()
{
	if (pPixelShader == nullptr)
	{
		char* pShaderBinary = nullptr;
		size_t shaderFileLength = 0;
		if (!c_resources_manager::get_resource(_bcs_resource_type_box_pixel_shader, &pShaderBinary, &shaderFileLength))
		{
			c_console::write_line_verbose("Warning: Failed to find Box pixel shader resource! Attempting to read BoxShaderPS.cso");
			pShaderBinary = filesystem_read_to_memory_legacy(L"BoxShaderPS.cso", &shaderFileLength);
		}
		ASSERT(pShaderBinary != nullptr);

		c_render::s_device->CreatePixelShader(pShaderBinary, shaderFileLength, NULL, &pPixelShader);
		ASSERT(pPixelShader != nullptr);

		delete[] pShaderBinary;
	}

	char* pVertexShaderBinary = nullptr;
	size_t vertexShaderBinaryLength = 0;
	if (pVertexShader == nullptr)
	{
		if (!c_resources_manager::get_resource(_bcs_resource_type_box_vertex_shader, &pVertexShaderBinary, &vertexShaderBinaryLength))
		{
			c_console::write_line_verbose("Warning: Failed to find Box vertex shader resource! Attempting to read BoxShaderVS.cso");
			pVertexShaderBinary = filesystem_read_to_memory_legacy(L"BoxShaderVS.cso", &vertexShaderBinaryLength);
		}
		ASSERT(pVertexShaderBinary != nullptr);

		c_render::s_device->CreateVertexShader(pVertexShaderBinary, vertexShaderBinaryLength, NULL, &pVertexShader);
		ASSERT(pVertexShader != nullptr);
	}

	if (pSolidRasterState == nullptr)
	{
		D3D11_RASTERIZER_DESC rasterizerDescription = {};
		rasterizerDescription.FillMode = D3D11_FILL_SOLID;
		rasterizerDescription.CullMode = D3D11_CULL_BACK;
		c_render::s_device->CreateRasterizerState(&rasterizerDescription, &pSolidRasterState);
	}

	if (pWireframeRasterState == nullptr)
	{
		D3D11_RASTERIZER_DESC rasterizerDescription = {};
		rasterizerDescription.FillMode = D3D11_FILL_WIREFRAME;
		rasterizerDescription.CullMode = D3D11_CULL_NONE;
		c_render::s_device->CreateRasterizerState(&rasterizerDescription, &pWireframeRasterState);
	}

	if (pVertexLayout == nullptr)
	{
		D3D11_INPUT_ELEMENT_DESC inputDescriptions[1] = {};

		inputDescriptions[0].SemanticName = "POSITION";
		inputDescriptions[0].SemanticIndex = 0;
		inputDescriptions[0].Format = DXGI_FORMAT_R32G32B32_FLOAT;
		inputDescriptions[0].InputSlot = 0;
		inputDescriptions[0].AlignedByteOffset = 0;
		inputDescriptions[0].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
		inputDescriptions[0].InstanceDataStepRate = 0;

		HRESULT createInputLayoutResult = c_render::s_device->CreateInputLayout(inputDescriptions, 1, pVertexShaderBinary, vertexShaderBinaryLength, &pVertexLayout);
		ASSERT(SUCCEEDED(createInputLayoutResult));
		ASSERT(pVertexLayout != nullptr);
	}

	if (pVertexShaderBinary != nullptr)
	{
		delete[] pVertexShaderBinary;
	}
}

void BoxRenderer::SetupConstantBuffers()
{
	if (ppInstanceConstantsBuffers[c_primitive_render_manager::kNumConstantsBuffers - 1] == nullptr)
	{
		D3D11_BUFFER_DESC bufferDesc = {};
		bufferDesc.Usage = D3D11_USAGE_DYNAMIC;
		bufferDesc.ByteWidth = sizeof(PerObjectConstants) * kMaxBoxesPerFrame;
		bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
		bufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
		bufferDesc.MiscFlags = 0;
		bufferDesc.StructureByteStride = 0;

		for (uint32_t i = 0; i < c_primitive_render_manager::kNumConstantsBuffers; i++)
		{
			ID3D11Buffer*& pConstantsBuffer = ppInstanceConstantsBuffers[i];

			HRESULT createBufferResult = c_render::s_device->CreateBuffer(&bufferDesc, NULL, &pConstantsBuffer);
			ASSERT(SUCCEEDED(createBufferResult));
			ASSERT(pConstantsBuffer != nullptr);
		}
	}
}

void BoxRenderer::GetNextConstantsBuffer()
{
	uint32_t currentConstantBufferIndex = (InterlockedIncrement(&nextConstantBufferIndex) - 1) % c_primitive_render_manager::kNumConstantsBuffers;
	pCurrentInstanceConstantsBuffer = ppInstanceConstantsBuffers[currentConstantBufferIndex];
	ASSERT(pCurrentInstanceConstantsBuffer != nullptr);
}

void BoxRenderer::MapConstantsBuffer()
{
	D3D11_MAPPED_SUBRESOURCE mappedResource = {};
	HRESULT mapResult = c_render::s_device_context->Map(pCurrentInstanceConstantsBuffer, 0, D3D11_MAP_WRITE_DISCARD, 0, &mappedResource);
	ASSERT(SUCCEEDED(mapResult));

	// contigious memory
	pPerObjectConstantsArray = static_cast<PerObjectConstants*>(mappedResource.pData);
}

void BoxRenderer::UnmapConstantsBuffer()
{
	c_render::s_device_context->Unmap(pCurrentInstanceConstantsBuffer, 0);
	pPerObjectConstantsArray = nullptr;
}

void BoxRenderer::BeginRenderBox()
{
	SetupShaders();
	SetupWireframeGeometry();
	SetupSolidGeometry();
	SetupConstantBuffers();
	GetNextConstantsBuffer();
	MapConstantsBuffer();
}

void BoxRenderer::RenderBox(
	DirectX::XMFLOAT3 const& position,
	DirectX::XMFLOAT3 const& dimensions,
	DirectX::XMFLOAT4 const& color
)
{
	using namespace DirectX;

	uint32_t currentBoxIndex = InterlockedIncrement(&nextBoxIndex) - 1;

	if (currentBoxIndex >= kMaxBoxesPerFrame)
	{
		return; // we've hit the maximum number of boxes that we can render per frame
	}

	PerObjectConstants& rPerObjectConstants = pPerObjectConstantsArray[currentBoxIndex];
	rPerObjectConstants.m_modelMatrix = XMMatrixScaling(dimensions.x, dimensions.y, dimensions.z);
	rPerObjectConstants.m_modelMatrix *= XMMatrixTranslation(position.x, position.y, position.z);
	rPerObjectConstants.m_modelMatrix = XMMatrixTranspose(rPerObjectConstants.m_modelMatrix);
	rPerObjectConstants.m_color = color;

}

void BoxRenderer::RenderBoxGeometry()
{
	using namespace DirectX;

	if (nextBoxIndex > 0)
	{
		const UINT vertexStride = sizeof(XMFLOAT3);
		const UINT vertexOffset = 0;

		c_render::s_device_context->RSSetState(pWireframeRasterState);
		c_render::s_device_context->VSSetShader(pVertexShader, NULL, 0);
		c_render::s_device_context->PSSetShader(pPixelShader, NULL, 0);
		c_render::s_device_context->IASetInputLayout(pVertexLayout);
		c_render::s_device_context->IASetVertexBuffers(0, 1, &pVertexBuffer, &vertexStride, &vertexOffset);

		bool solid = false;
		if (solid)
		{
			c_render::s_device_context->IASetIndexBuffer(pSolidIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
			c_render::s_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		}
		else
		{
			c_render::s_device_context->IASetIndexBuffer(pWireframeIndexBuffer, DXGI_FORMAT_R32_UINT, 0);
			c_render::s_device_context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINELIST);
		}

		const uint32_t maxInstances = 4096 / sizeof(PerObjectConstants);
		//const uint32_t maxInstancesPow2 = 1u << ilogb(maxInstances);
		const uint32_t maxInstancesPow2 = 16;

		c_render::s_device_context->VSSetConstantBuffers(0, 1, &c_primitive_render_manager::GetConstantsBuffer());
		c_render::s_device_context->PSSetConstantBuffers(0, 1, &c_primitive_render_manager::GetConstantsBuffer());

		const uint32_t numBoxes = __min(kMaxBoxesPerFrame, nextBoxIndex);
		for (uint32_t i = 0; i < numBoxes;)
		{
			uint32_t remainingBoxes = numBoxes - i;
			uint32_t boxesToDrawThisCall = __min(remainingBoxes, maxInstancesPow2);

			boxesToDrawThisCall = 1; // #TODO: Rendering more than 1 box at a time causes issues. Not sure why.

			UINT firstConstant = (sizeof(PerObjectConstants) * i) / 16;
			UINT numConstants = sizeof(PerObjectConstants);

			c_render::s_device_context->VSSetConstantBuffers1(1, 1, &pCurrentInstanceConstantsBuffer, &firstConstant, &numConstants);
			c_render::s_device_context->PSSetConstantBuffers1(1, 1, &pCurrentInstanceConstantsBuffer, &firstConstant, &numConstants);

			if (solid)
			{
				c_render::s_device_context->DrawIndexedInstanced(36, boxesToDrawThisCall, 0, 0, 0);
			}
			else
			{
				c_render::s_device_context->DrawIndexedInstanced(36, boxesToDrawThisCall, 0, 0, 0);
			}

			i += boxesToDrawThisCall;
		}
	}
}

void BoxRenderer::EndRenderBox()
{
	using namespace DirectX;

	UnmapConstantsBuffer();

	c_render::begin_frame(false, nullptr, false);
	RenderBoxGeometry();
	//c_render::EndFrame();

	pCurrentInstanceConstantsBuffer = nullptr;
	nextBoxIndex = 0;
}

