#include "pch.h"
#include "AngleBase.h"

using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::UI::Core;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

// Constructor.
AngleBase::AngleBase()
    : m_bAngleInitialized(false)
    , m_eglDisplay(nullptr)
    , m_eglSurface(nullptr)
    , m_eglContext(nullptr)
    , m_eglWindow(nullptr)
    , m_orientation(DisplayOrientations::Portrait)
{
}

// Initialize the Direct3D resources required to run.
void AngleBase::Initialize(CoreWindow^ window)
{
	m_window = window;

	CreateDeviceResources();
	CreateWindowSizeDependentResources();
}

// Recreate all device resources and set them back to the current state.
void AngleBase::HandleDeviceLost()
{
    CloseAngle();
	// Reset these member variables to ensure that UpdateForWindowSizeChange recreates all resources.
	m_windowBounds.Width = 0;
	m_windowBounds.Height = 0;

	CreateDeviceResources();
	UpdateForWindowSizeChange();
}

// releases device memory allocated by the graphics driver thereby reducing the app's memory profile while it is suspended.
void AngleBase::Trim()
{
    ComPtr<IDXGIDevice3> dxgiDevice;
    if (m_eglWindow && m_eglWindow.Get() != nullptr)
    {
        ComPtr<IUnknown> device = m_eglWindow.Get()->GetAngleD3DDevice();
        if (device != nullptr)
        {
            ComPtr<ID3D11Device> d3dDevice;
            HRESULT result = device.As(&d3dDevice);
            if (SUCCEEDED(result))
            {
                ComPtr<IDXGIDevice3> dxgiDevice;
                result = d3dDevice.As(&dxgiDevice);
                if (SUCCEEDED(result))
                {
                    dxgiDevice->Trim();
                }
            }
        }
    }
}

// These are the resources that depend on the device.
void AngleBase::CreateDeviceResources()
{
    InitializeAngle();
    CreateGLResources();
}

// Allocate all memory resources that depend on the window size.
void AngleBase::CreateWindowSizeDependentResources()
{
    OnOrientationChanged();
}



// This method is called in the event handler for the SizeChanged event.
void AngleBase::UpdateForWindowSizeChange()
{
    Windows::Foundation::Rect windowBounds = Windows::UI::Core::CoreWindow::GetForCurrentThread()->Bounds;
    if (windowBounds.Width  != m_windowBounds.Width ||
        windowBounds.Height != m_windowBounds.Height ||
        m_orientation != DisplayInformation::GetForCurrentView()->CurrentOrientation)
    {
		CreateWindowSizeDependentResources();
	}
}

void AngleBase::ReleaseResourcesForSuspending()
{
	// Phone applications operate in a memory-constrained environment, so when entering
	// the background it is a good idea to free memory-intensive objects that will be
	// easy to restore upon reactivation. The swapchain and backbuffer are good candidates
	// here, as they consume a large amount of memory and can be reinitialized quickly.
    CloseAngle();
}

// Method to deliver the final image to the display.
void AngleBase::Present()
{
    if(eglSwapBuffers(m_eglDisplay, m_eglSurface) != GL_TRUE)
    {
        HandleDeviceLost();
    }
}

// Method to convert a length in device-independent pixels (DIPs) to a length in physical pixels.
float AngleBase::ConvertDipsToPixels(float dips)
{
	static const float dipsPerInch = 96.0f;
    return floor(dips * DisplayInformation::GetForCurrentView()->LogicalDpi / dipsPerInch + 0.5f); // Round to nearest integer.
}

void AngleBase::OnOrientationChanged()
{
	m_windowBounds = Windows::UI::Core::CoreWindow::GetForCurrentThread()->Bounds;
	m_renderTargetSize.Width = ConvertDipsToPixels(m_windowBounds.Width);
	m_renderTargetSize.Height = ConvertDipsToPixels(m_windowBounds.Height);
    m_aspectRatio = m_renderTargetSize.Width / m_renderTargetSize.Height;
    m_orientation = DisplayInformation::GetForCurrentView()->CurrentOrientation;

	switch(m_orientation)
	{
		case DisplayOrientations::Portrait:
			m_orientationMatrix = XMMatrixIdentity();
			break;

		case DisplayOrientations::PortraitFlipped:
			m_orientationMatrix = XMMatrixRotationZ(XM_PI);
			break;

		case DisplayOrientations::Landscape:
			m_orientationMatrix = XMMatrixRotationZ(-XM_PIDIV2);
			break;
			
		case DisplayOrientations::LandscapeFlipped:
			m_orientationMatrix = XMMatrixRotationZ(XM_PIDIV2);
			break;
	}
}

void AngleBase::Render()
{
    OnRender();
}

void AngleBase::CloseAngle()
{
	if(m_eglDisplay && m_eglSurface)
    {
        eglDestroySurface(m_eglDisplay, m_eglSurface);
        m_eglSurface = nullptr;
    }

	if(m_eglDisplay && m_eglContext)
    {
        eglDestroyContext(m_eglDisplay, m_eglContext);
        m_eglContext = nullptr;
    }    

	if(m_eglDisplay)
    {
        eglTerminate(m_eglDisplay);
        m_eglDisplay = nullptr;
    }

    m_eglWindow = nullptr;

    m_bAngleInitialized = false;
}

bool AngleBase::InitializeAngle()
{
	// setup EGL
	EGLint configAttribList[] = {
		EGL_RED_SIZE,       8,
		EGL_GREEN_SIZE,     8,
		EGL_BLUE_SIZE,      8,
		EGL_ALPHA_SIZE,     8,
		EGL_DEPTH_SIZE,     8,
		EGL_STENCIL_SIZE,   8,
		EGL_SAMPLE_BUFFERS, 0,
		EGL_NONE
	};
	EGLint surfaceAttribList[] = {
		EGL_NONE, EGL_NONE
	};

	EGLint numConfigs;
	EGLint majorVersion;
	EGLint minorVersion;
	EGLDisplay display;
	EGLContext context;
	EGLSurface surface;
	EGLConfig config;
	EGLint contextAttribs[] = { EGL_CONTEXT_CLIENT_VERSION, 2, EGL_NONE, EGL_NONE };

    // we need to select the correct DirectX feature level depending on the platform
    // default is D3D_FEATURE_LEVEL_9_3 Windows Phone 8.0
    ANGLE_D3D_FEATURE_LEVEL featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_3;


 	DX::ThrowIfFailed(
        CreateWinrtEglWindow(WINRT_EGL_IUNKNOWN(m_window.Get()), featureLevel, m_eglWindow.GetAddressOf())
        );

	display = eglGetDisplay(m_eglWindow);
	if(display == EGL_NO_DISPLAY){
		//ofLogError("ofAppWinRTWindow") << "couldn't get EGL display";
		return false;
	}

	if(!eglInitialize(display, &majorVersion, &minorVersion)){
		//ofLogError("ofAppWinRTWindow") << "failed to initialize EGL";
		return false;
	}

	// Get configs
	if ( !eglGetConfigs(display, NULL, 0, &numConfigs) ){
		//ofLogError("ofAppWinRTWindow") << "failed to get configurations";
		return false;
	}

	// Choose config
	if(!eglChooseConfig(display, configAttribList, &config, 1, &numConfigs)){
		//ofLogError("ofAppWinRTWindow") << "failed to choose configuration";
		return false;
	}

    // Create a surface
    surface = eglCreateWindowSurface(display, config, m_eglWindow, surfaceAttribList);
    if(surface == EGL_NO_SURFACE){
        //ofLogError("ofAppWinRTWindow") << "failed to create EGL window surface";
        return false;
    }  

	// Create a GL context
	context = eglCreateContext(display, config, EGL_NO_CONTEXT, contextAttribs);
	if(context == EGL_NO_CONTEXT){
		//ofLogError("ofAppWinRTWindow") << "failed to create EGL context";
		return false;
	}   

	// Make the context current
	if (!eglMakeCurrent(display, surface, surface, context)){
		//ofLogError("ofAppWinRTWindow") << "failed to make EGL context current";
		return false;
	}

	m_eglDisplay = display;
	m_eglSurface = surface;
	m_eglContext = context;

    m_bAngleInitialized = true;
    return true;
}
