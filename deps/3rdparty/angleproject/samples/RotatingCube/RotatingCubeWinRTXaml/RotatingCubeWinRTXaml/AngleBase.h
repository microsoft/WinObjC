#pragma once

#include "DirectXHelper.h"
#include "EGL/egl.h"
#include "EGL/eglext.h"
#include "EGL/eglplatform.h"
#include "GLES2/gl2.h"
#include "GLES2/gl2ext.h"
#include "winrtangle.h"

// Helper class that initializes DirectX APIs for 3D rendering.
ref class AngleBase abstract
{
internal:
	AngleBase();

public:
	virtual void Initialize(Windows::UI::Core::CoreWindow^ window, Windows::UI::Xaml::Controls::SwapChainBackgroundPanel^ panel, float dpi);
	virtual void HandleDeviceLost();
	virtual void ValidateDevice();
	virtual void CreateDeviceResources();
	virtual void CreateWindowSizeDependentResources();
	virtual void UpdateForWindowSizeChange();
	virtual void ReleaseResourcesForSuspending();
	virtual void OnOrientationChanged();
	virtual void SetDpi(float dpi);

	virtual void Render();
	virtual void Present();
	virtual float ConvertDipsToPixels(float dips);

protected:
    virtual void CreateGLResources() = 0;
	virtual void OnRender() = 0;
    bool InitializeAngle();
    void CloseAngle();

protected private:
	Windows::Foundation::Size m_renderTargetSize;
	Windows::Foundation::Rect m_windowBounds;
	Platform::Agile<Windows::UI::Core::CoreWindow> m_window;
	Windows::UI::Xaml::Controls::SwapChainBackgroundPanel^ m_panel;
	float m_dpi;

    // Angle EGL 
    bool m_bAngleInitialized;
	EGLDisplay m_eglDisplay;
	EGLContext m_eglContext;
	EGLSurface m_eglSurface;
	Microsoft::WRL::ComPtr<IWinrtEglWindow> m_eglWindow;
	Microsoft::WRL::ComPtr<IWinPhone8XamlD3DWindow> m_eglPhoneWindow;
    DirectX::XMMATRIX m_orientationMatrix;
    Windows::Graphics::Display::DisplayOrientations m_orientation;
    float m_aspectRatio;
};