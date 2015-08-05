#pragma once

#include "AngleBase.h"
#include <DirectXMath.h>


// This class renders a simple spinning cube.
ref class CubeRenderer sealed : public AngleBase
{
public:
	CubeRenderer();

	// AngleBase methods.
	// Method for updating time-dependent objects.
	void Update(float timeTotal, float timeDelta);
	virtual void OnOrientationChanged() override;
    void BackgroundColorNext();
    void BackgroundColorPrevious();

protected:
    virtual void OnRender() override;
    virtual void CreateGLResources() override;

private:
    void UpdatePerspectiveMatrix();

    bool m_loadingComplete;
    GLuint m_colorProgram;
    GLint a_positionColor;
    GLint a_colorColor;
    GLint u_mvpColor;
    DirectX::XMMATRIX m_projectionMatrix;
    DirectX::XMMATRIX m_viewMatrix;
    DirectX::XMMATRIX m_modelMatrix;
    int m_currentColor;
};