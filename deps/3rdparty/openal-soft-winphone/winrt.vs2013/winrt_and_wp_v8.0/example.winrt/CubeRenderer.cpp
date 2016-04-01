#include "pch.h"
#include "CubeRenderer.h"

#include <alSimple3DSound.h>

using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::System::Threading;

#define SOUND_DISTANCE_SCALE 10.0f
#define SOUND_VOLUME 2.0f

CubeRenderer::CubeRenderer() :
	m_loadingComplete(false),
	m_firstUpdate(true),
	m_indexCount(0),
	m_oriPosition(-0.375f, -0.375f, -0.375f)
{
}

CubeRenderer::~CubeRenderer()
{
}

void CubeRenderer::CreateDeviceResources()
{
	Direct3DBase::CreateDeviceResources();

	auto loadVSTask = DX::ReadDataAsync("SimpleVertexShader.cso");
	auto loadPSTask = DX::ReadDataAsync("SimplePixelShader.cso");

	auto createVSTask = loadVSTask.then([this](Platform::Array<byte>^ fileData) {
		DX::ThrowIfFailed(
			m_d3dDevice->CreateVertexShader(
 				fileData->Data,
				fileData->Length,
				nullptr,
				&m_vertexShader
				)
			);

		const D3D11_INPUT_ELEMENT_DESC vertexDesc[] = 
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR",    0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		};

		DX::ThrowIfFailed(
			m_d3dDevice->CreateInputLayout(
				vertexDesc,
				ARRAYSIZE(vertexDesc),
				fileData->Data,
				fileData->Length,
				&m_inputLayout
				)
			);
	});

	auto createPSTask = loadPSTask.then([this](Platform::Array<byte>^ fileData) {
		DX::ThrowIfFailed(
			m_d3dDevice->CreatePixelShader(
				fileData->Data,
				fileData->Length,
				nullptr,
				&m_pixelShader
				)
			);

		CD3D11_BUFFER_DESC constantBufferDesc(sizeof(ModelViewProjectionConstantBuffer), D3D11_BIND_CONSTANT_BUFFER);
		DX::ThrowIfFailed(
			m_d3dDevice->CreateBuffer(
				&constantBufferDesc,
				nullptr,
				&m_constantBuffer
				)
			);
	});

	auto createCubeTask = (createPSTask && createVSTask).then([this] () {
		VertexPositionColor cubeVertices[] = 
		{
			{XMFLOAT3(m_oriPosition.x - 0.125f, m_oriPosition.y - 0.125f, m_oriPosition.z - 0.125f), XMFLOAT3(0.0f, 0.0f, 0.0f)},
			{XMFLOAT3(m_oriPosition.x - 0.125f, m_oriPosition.y - 0.125f, m_oriPosition.z + 0.125f), XMFLOAT3(0.0f, 0.0f, 1.0f)},
			{XMFLOAT3(m_oriPosition.x - 0.125f, m_oriPosition.y + 0.125f, m_oriPosition.z - 0.125f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
			{XMFLOAT3(m_oriPosition.x - 0.125f, m_oriPosition.y + 0.125f, m_oriPosition.z + 0.125f), XMFLOAT3(0.0f, 1.0f, 1.0f)},
			{XMFLOAT3(m_oriPosition.x + 0.125f, m_oriPosition.y - 0.125f, m_oriPosition.z - 0.125f), XMFLOAT3(1.0f, 0.0f, 0.0f)},
			{XMFLOAT3(m_oriPosition.x + 0.125f, m_oriPosition.y - 0.125f, m_oriPosition.z + 0.125f), XMFLOAT3(1.0f, 0.0f, 1.0f)},
			{XMFLOAT3(m_oriPosition.x + 0.125f, m_oriPosition.y + 0.125f, m_oriPosition.z - 0.125f), XMFLOAT3(1.0f, 1.0f, 0.0f)},
			{XMFLOAT3(m_oriPosition.x + 0.125f, m_oriPosition.y + 0.125f, m_oriPosition.z + 0.125f), XMFLOAT3(1.0f, 1.0f, 1.0f)},
		};

		D3D11_SUBRESOURCE_DATA vertexBufferData = {0};
		vertexBufferData.pSysMem = cubeVertices;
		vertexBufferData.SysMemPitch = 0;
		vertexBufferData.SysMemSlicePitch = 0;
		CD3D11_BUFFER_DESC vertexBufferDesc(sizeof(cubeVertices), D3D11_BIND_VERTEX_BUFFER);
		DX::ThrowIfFailed(
			m_d3dDevice->CreateBuffer(
				&vertexBufferDesc,
				&vertexBufferData,
				&m_vertexBuffer
				)
			);

		unsigned short cubeIndices[] = 
		{
			0,2,1, // -x
			1,2,3,

			4,5,6, // +x
			5,7,6,

			0,1,5, // -y
			0,5,4,

			2,6,7, // +y
			2,7,3,

			0,4,6, // -z
			0,6,2,

			1,3,7, // +z
			1,7,5,
		};

		m_indexCount = ARRAYSIZE(cubeIndices);

		D3D11_SUBRESOURCE_DATA indexBufferData = {0};
		indexBufferData.pSysMem = cubeIndices;
		indexBufferData.SysMemPitch = 0;
		indexBufferData.SysMemSlicePitch = 0;
		CD3D11_BUFFER_DESC indexBufferDesc(sizeof(cubeIndices), D3D11_BIND_INDEX_BUFFER);
		DX::ThrowIfFailed(
			m_d3dDevice->CreateBuffer(
				&indexBufferDesc,
				&indexBufferData,
				&m_indexBuffer
				)
			);
	});

	createCubeTask.then([this] () {
		alSimple3DSound::release();
		//windows store app must open OpenAL device asynchronously since it is illegal to do it on UI thread
		alSimple3DSound::initSoundAsync(
			"DST-10Class.WAV",
			[this](bool succeeded){
				m_loadingComplete = true;
			});
	});
}

void CubeRenderer::CreateWindowSizeDependentResources()
{
	Direct3DBase::CreateWindowSizeDependentResources();

	float aspectRatio = m_windowBounds.Width / m_windowBounds.Height;
	float fovAngleY = 70.0f * XM_PI / 180.0f;

	// Note that the m_orientationTransform3D matrix is post-multiplied here
	// in order to correctly orient the scene to match the display orientation.
	// This post-multiplication step is required for any draw calls that are
	// made to the swap chain render target. For draw calls to other targets,
	// this transform should not be applied.
	XMStoreFloat4x4(
		&m_constantBufferData.projection,
		XMMatrixTranspose(
			XMMatrixMultiply(
				XMMatrixPerspectiveFovRH(
					fovAngleY,
					aspectRatio,
					0.01f,
					100.0f
					),
				XMLoadFloat4x4(&m_orientationTransform3D)
				)
			)
		);
}

void CubeRenderer::Update(float timeTotal, float timeDelta)
{
	(void) timeDelta; // Unused parameter.

	XMVECTOR simd_eye = XMVectorSet(0.0f, 0.7f, 1.5f, 0.0f);
	XMVECTOR simd_at = XMVectorSet(0.0f, -0.1f, 0.0f, 0.0f);
	XMVECTOR simd_up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	XMVECTOR simd_rotAxis = XMVector3Normalize( XMVectorSet(0, 1, 0, 0));

	XMVECTOR simdOriPosition = XMLoadFloat3(&m_oriPosition);
	XMMATRIX simd_world_matrix = XMMatrixRotationAxis(simd_rotAxis, timeTotal * XM_PIDIV4);
	XMVECTOR simd_world_pos = XMVector3TransformCoord(simdOriPosition, simd_world_matrix);
	
	XMStoreFloat4x4(&m_constantBufferData.view, XMMatrixTranspose(XMMatrixLookAtRH(simd_eye, simd_at, simd_up)));
	XMStoreFloat4x4(&m_constantBufferData.model, XMMatrixTranspose(simd_world_matrix));


	//update sound
	if (m_loadingComplete)
	{
		//init sound
		if (m_firstUpdate)
		{
			m_firstUpdate = false;

			//start the sound
			alSimple3DSound::start(SOUND_VOLUME);
		}

		XMVECTOR simd_listenerDirection = XMVector3Normalize( simd_at - simd_eye);
		XMVectorSetY(simd_listenerDirection, 0);

		XMFLOAT3 listener(0, m_oriPosition.y * SOUND_DISTANCE_SCALE, 0),//listener is at the center
			listener_direction, 
			listener_up(0, 1, 0);
		XMFLOAT3 world_pos;//sound world position

		XMStoreFloat3(&listener_direction, simd_listenerDirection);
		XMStoreFloat3(&world_pos, simd_world_pos * SOUND_DISTANCE_SCALE);

		alSimple3DSound::setListenerOrientations((float*)&listener_up, (float*)&listener_direction);
		alSimple3DSound::setListenerPosition((float*)&listener);

		alSimple3DSound::setSoundPosition((float*)&world_pos);
	}
}

void CubeRenderer::Render()
{
	const float midnightBlue[] = { 0.098f, 0.098f, 0.439f, 1.000f };
	m_d3dContext->ClearRenderTargetView(
		m_renderTargetView.Get(),
		midnightBlue
		);

	m_d3dContext->ClearDepthStencilView(
		m_depthStencilView.Get(),
		D3D11_CLEAR_DEPTH,
		1.0f,
		0
		);

	// Only draw the cube once it is loaded (loading is asynchronous).
	if (!m_loadingComplete)
	{
		return;
	}

	m_d3dContext->OMSetRenderTargets(
		1,
		m_renderTargetView.GetAddressOf(),
		m_depthStencilView.Get()
		);

	m_d3dContext->UpdateSubresource(
		m_constantBuffer.Get(),
		0,
		NULL,
		&m_constantBufferData,
		0,
		0
		);

	UINT stride = sizeof(VertexPositionColor);
	UINT offset = 0;
	m_d3dContext->IASetVertexBuffers(
		0,
		1,
		m_vertexBuffer.GetAddressOf(),
		&stride,
		&offset
		);

	m_d3dContext->IASetIndexBuffer(
		m_indexBuffer.Get(),
		DXGI_FORMAT_R16_UINT,
		0
		);

	m_d3dContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	m_d3dContext->IASetInputLayout(m_inputLayout.Get());

	m_d3dContext->VSSetShader(
		m_vertexShader.Get(),
		nullptr,
		0
		);

	m_d3dContext->VSSetConstantBuffers(
		0,
		1,
		m_constantBuffer.GetAddressOf()
		);

	m_d3dContext->PSSetShader(
		m_pixelShader.Get(),
		nullptr,
		0
		);

	m_d3dContext->DrawIndexed(
		m_indexCount,
		0,
		0
		);
}
