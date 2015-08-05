#include "pch.h"
#include "CubeRenderer.h"
#include "..\..\..\shader.h"

using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;

struct VertexPositionColor
{
	XMFLOAT3 pos;
	XMFLOAT3 color;
};

CubeRenderer::CubeRenderer(): m_loadingComplete(false)
{
}

void CubeRenderer::CreateDeviceResources()
{
	AngleBase::CreateDeviceResources();
}

void CubeRenderer::CreateGLResources()
{
    m_colorProgram = glCreateProgram();
    glProgramBinaryOES(m_colorProgram, GL_PROGRAM_BINARY_ANGLE, gProgram, sizeof(gProgram));
    a_positionColor = glGetAttribLocation(m_colorProgram, "a_position");
    a_colorColor = glGetAttribLocation(m_colorProgram, "a_color");
    u_mvpColor = glGetUniformLocation(m_colorProgram, "u_mvp");

	//glViewport(0, 0, static_cast<UINT>(m_renderTargetSize.Width), static_cast<UINT>(m_renderTargetSize.Height));
    glEnable(GL_DEPTH_TEST);
    m_loadingComplete = true;
}

void CubeRenderer::CreateWindowSizeDependentResources()
{
	AngleBase::CreateWindowSizeDependentResources();
}

void CubeRenderer::UpdatePerspectiveMatrix()
{
    float fovAngleY = 70.0f * XM_PI / 180.0f;
    m_projectionMatrix = XMMatrixPerspectiveFovRH(fovAngleY, m_aspectRatio, 0.01f, 100.0f);

    // In Windows Phone 8.0 C++ apps, we need to rotate the projection matrix by the 
    // device's current rotation matrix
    m_projectionMatrix = XMMatrixMultiply(m_orientationMatrix, m_projectionMatrix);
}

void CubeRenderer::OnOrientationChanged(Windows::Graphics::Display::DisplayOrientations orientation)
{
	AngleBase::OnOrientationChanged(orientation);
    UpdatePerspectiveMatrix();
}

void CubeRenderer::Update(float timeTotal, float timeDelta)
{
	(void) timeDelta;

    XMVECTOR eye = XMVectorSet(0.0f, 0.7f, 1.5f, 0.0f);
	XMVECTOR at = XMVectorSet(0.0f, -0.1f, 0.0f, 0.0f);
	XMVECTOR up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
            
	m_viewMatrix = XMMatrixLookAtRH(eye, at, up);
	m_modelMatrix = XMMatrixRotationY(timeTotal * XM_PIDIV4);
}

void CubeRenderer::OnRender()
{
    XMFLOAT4X4 mvp;
    XMStoreFloat4x4(&mvp, (XMMatrixMultiply(XMMatrixMultiply(m_modelMatrix, m_viewMatrix), m_projectionMatrix)));

    glClearColor(0.098f, 0.098f, 0.439f, 1.000f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(m_colorProgram);
    glUniformMatrix4fv(u_mvpColor, 1, GL_FALSE, &mvp.m[0][0]);

    VertexPositionColor cubeVertices[] = 
	{
		{XMFLOAT3(-0.5f, -0.5f, -0.5f), XMFLOAT3(0.0f, 0.0f, 0.0f)},
		{XMFLOAT3(-0.5f, -0.5f,  0.5f), XMFLOAT3(0.0f, 0.0f, 1.0f)},
		{XMFLOAT3(-0.5f,  0.5f, -0.5f), XMFLOAT3(0.0f, 1.0f, 0.0f)},
		{XMFLOAT3(-0.5f,  0.5f,  0.5f), XMFLOAT3(0.0f, 1.0f, 1.0f)},
		{XMFLOAT3( 0.5f, -0.5f, -0.5f), XMFLOAT3(1.0f, 0.0f, 0.0f)},
		{XMFLOAT3( 0.5f, -0.5f,  0.5f), XMFLOAT3(1.0f, 0.0f, 1.0f)},
		{XMFLOAT3( 0.5f,  0.5f, -0.5f), XMFLOAT3(1.0f, 1.0f, 0.0f)},
		{XMFLOAT3( 0.5f,  0.5f,  0.5f), XMFLOAT3(1.0f, 1.0f, 1.0f)},
	};
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

    glEnableVertexAttribArray(a_positionColor);
    glEnableVertexAttribArray(a_colorColor);
    glVertexAttribPointer(a_positionColor, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), cubeVertices);
    glVertexAttribPointer(a_colorColor, 3, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), reinterpret_cast<char*>(cubeVertices) + sizeof(XMFLOAT3));
    glDrawElements(GL_TRIANGLES, ARRAYSIZE(cubeIndices), GL_UNSIGNED_SHORT, cubeIndices);
    glDisableVertexAttribArray(a_positionColor);
    glDisableVertexAttribArray(a_colorColor);
}

