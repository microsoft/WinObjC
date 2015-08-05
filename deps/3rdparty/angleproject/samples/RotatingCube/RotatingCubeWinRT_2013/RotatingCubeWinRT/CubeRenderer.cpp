#include "pch.h"
#include "CubeRenderer.h"

using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::Graphics::Display;

#define STRINGIFY(x) #x

const char g_colorVertexShader[] = STRINGIFY(
    precision mediump float;
attribute vec3 a_position;
attribute vec3 a_color;
varying vec4 v_color;
uniform mat4 u_mvp;
void main(void)
{
    gl_Position = u_mvp * vec4(a_position, 1);
    v_color = vec4(a_color, 1);
}
);

const char g_colorFragmentShader[] = STRINGIFY(
    precision mediump float;
varying vec4 v_color;
void main(void)
{
    gl_FragColor = v_color;
}
);

struct VertexPositionColor
{
	XMFLOAT3 pos;
	XMFLOAT3 color;
};

CubeRenderer::CubeRenderer(): m_loadingComplete(false)
{
}

// The GL Context is ready. Load your resources
void CubeRenderer::CreateGLResources()
{
    m_colorProgram = LoadProgram(g_colorVertexShader, g_colorFragmentShader);
    a_positionColor = glGetAttribLocation(m_colorProgram, "a_position");
    a_colorColor = glGetAttribLocation(m_colorProgram, "a_color");
    u_mvpColor = glGetUniformLocation(m_colorProgram, "u_mvp");
    glEnable(GL_DEPTH_TEST);
    m_loadingComplete = true;
}

void CubeRenderer::UpdatePerspectiveMatrix()
{
	float fovAngleY = 70.0f * XM_PI / 180.0f;

	// This is a simple example of change that can be made when the app is in
	// portrait or snapped view.
	if (m_aspectRatio < 1.0f)
	{
		fovAngleY *= 2.0f;
	}
    m_projectionMatrix = XMMatrixPerspectiveFovRH(fovAngleY, m_aspectRatio, 0.01f, 100.0f);
    glViewport(0, 0, static_cast<UINT>(m_renderTargetSize.Width), static_cast<UINT>(m_renderTargetSize.Height));
}

// called when the device rotation has changed
void CubeRenderer::OnOrientationChanged()
{
	AngleBase::OnOrientationChanged();
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

// render your OpenGL scene
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

GLuint CubeRenderer::LoadProgram(const char *vertShaderSrc, const char *fragShaderSrc)
{
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    // Load the vertex/fragment shaders
    vertexShader = LoadShader(GL_VERTEX_SHADER, vertShaderSrc);
    if (vertexShader == 0)
        return 0;

    fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fragShaderSrc);
    if (fragmentShader == 0)
    {
        glDeleteShader(vertexShader);
        return 0;
    }

    // Create the program object
    programObject = glCreateProgram();

    if (programObject == 0)
        return 0;

    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);

    // Link the program
    glLinkProgram(programObject);

    // Check the link status
    glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

    if (!linked)
    {
        GLint infoLen = 0;

        glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = (char*) malloc(sizeof(char) * infoLen);

            glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
            //esLogMessage("Error linking program:\n%s\n", infoLog);

            free(infoLog);
        }

        glDeleteProgram(programObject);
        return 0;
    }

    // Free up no longer needed shader resources
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return programObject;
}

GLuint CubeRenderer::LoadShader(GLenum type, const char *shaderSrc)
{
    GLuint shader;
    GLint compiled;

    // Create the shader object
    shader = glCreateShader(type);

    if (shader == 0)
        return 0;

    // Load the shader source
    glShaderSource(shader, 1, &shaderSrc, NULL);

    // Compile the shader
    glCompileShader(shader);

    // Check the compile status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled)
    {
        GLint infoLen = 0;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = (char*) malloc(sizeof(char) * infoLen);

            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            //esLogMessage("Error compiling shader:\n%s\n", infoLog);

            free(infoLog);
        }

        glDeleteShader(shader);
        return 0;
    }

    return shader;

}


