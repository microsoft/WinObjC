#include "pch.h"
#include "AngleBase.h"

using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;
using namespace Windows::Graphics::Display;

// Constructor.
AngleBase::AngleBase()
    : m_bAngleInitialized(false)
    , m_eglDisplay(nullptr)
    , m_eglSurface(nullptr)
    , m_eglContext(nullptr)
    , m_eglWindow(nullptr)
    , m_eglPhoneWindow(nullptr)
    , m_d3dDeferredContext(nullptr)
{
}

// Initialize the Direct3D resources required to run.
void AngleBase::Initialize()
{
}

// These are the resources that depend on the device.
void AngleBase::CreateDeviceResources()
{
}

void AngleBase::UpdateDevice(ID3D11Device1* device, ID3D11DeviceContext1* context, ID3D11RenderTargetView* renderTargetView)
{
    m_d3dContext = context;
    m_d3dRenderTargetView = renderTargetView;
    m_featureLevel = device->GetFeatureLevel();

    if (m_d3dDevice.Get() != device)
    {
        CloseAngle();
        m_d3dDevice = device;
        CreateDeviceResources();

        // Force call to CreateWindowSizeDependentResources
        m_renderTargetSize.Width  = -1;
        m_renderTargetSize.Height = -1;

        m_d3dDeferredContext = nullptr;

    }

    ComPtr<ID3D11Resource> renderTargetViewResource;
    m_d3dRenderTargetView->GetResource(&renderTargetViewResource);

    ComPtr<ID3D11Texture2D> backBuffer;
    DX::ThrowIfFailed(
        renderTargetViewResource.As(&backBuffer)
        );

    // Cache the rendertarget dimensions in our helper class for convenient use.
    D3D11_TEXTURE2D_DESC backBufferDesc;
    backBuffer->GetDesc(&backBufferDesc);

    if (m_renderTargetSize.Width  != static_cast<float>(backBufferDesc.Width) ||
        m_renderTargetSize.Height != static_cast<float>(backBufferDesc.Height))
    {
        m_renderTargetSize.Width  = static_cast<float>(backBufferDesc.Width);
        m_renderTargetSize.Height = static_cast<float>(backBufferDesc.Height);
        CreateWindowSizeDependentResources();
    }

    if(!m_bAngleInitialized)
    {
        InitializeAngle();
        CreateGLResources();
    }
    else
    {
        m_eglPhoneWindow->Update(m_d3dDevice.Get(), m_d3dContext.Get(), m_d3dRenderTargetView.Get());
    }
}


void AngleBase::UpdateForWindowSizeChange(float width, float height)
{
    if (width != m_windowBounds.Width || height != m_windowBounds.Height)
    {
        m_windowBounds.Width  = width;
        m_windowBounds.Height = height;
    }
}

// Allocate all memory resources that depend on the window size.
void AngleBase::CreateWindowSizeDependentResources()
{


}

void AngleBase::OnOrientationChanged(DisplayOrientations orientation)
{
    m_aspectRatio = m_renderTargetSize.Width / m_renderTargetSize.Height;

	switch(orientation)
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
    if (m_d3dDeferredContext.Get() == nullptr)
    {
        m_d3dDevice.Get()->CreateDeferredContext(0, &m_d3dDeferredContext);
    }

    ComPtr<ID3D11DeviceContext1> deferredContect;
    DX::ThrowIfFailed(m_d3dDeferredContext.As(&deferredContect));
    m_eglPhoneWindow->Update(m_d3dDevice.Get(), deferredContect.Get(), m_d3dRenderTargetView.Get());
    OnRender();
    ComPtr<ID3D11CommandList> d3dCommandList;
    m_d3dDeferredContext->FinishCommandList(FALSE, &d3dCommandList);
    m_d3dContext->ExecuteCommandList(d3dCommandList.Get(), FALSE);
    m_eglPhoneWindow->Update(m_d3dDevice.Get(), m_d3dContext.Get(), m_d3dRenderTargetView.Get());
	eglSwapBuffers(m_eglDisplay, m_eglSurface);
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

    if(m_eglPhoneWindow != nullptr)
    {
         m_eglPhoneWindow->Update(nullptr, nullptr, nullptr);
    }

    eglMakeCurrent(NULL, NULL, NULL, NULL);


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

	switch(m_featureLevel)
	{
	case ANGLE_D3D_FEATURE_LEVEL_9_3:
		featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_3;
		break;
				
	case ANGLE_D3D_FEATURE_LEVEL_9_2:
		featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_2;
		break;
					
	case ANGLE_D3D_FEATURE_LEVEL_9_1:
		featureLevel = ANGLE_D3D_FEATURE_LEVEL::ANGLE_D3D_FEATURE_LEVEL_9_1;
		break;
	}		

    if (m_eglPhoneWindow == nullptr)
    {
	    DX::ThrowIfFailed(
            CreateWinPhone8XamlWindow(&m_eglPhoneWindow)
            );
    }


    m_eglPhoneWindow->Update(m_d3dDevice.Get(), m_d3dContext.Get(), m_d3dRenderTargetView.Get());

    if (m_eglWindow == nullptr)
    {
 	    DX::ThrowIfFailed(
            CreateWinrtEglWindow(WINRT_EGL_IUNKNOWN(m_eglPhoneWindow.Get()), featureLevel, m_eglWindow.GetAddressOf())
            );
    }

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
