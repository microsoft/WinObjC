#include "precompiled.h"

#include "winrtangle.h"
#include "angleutils.h"
#include <windows.h>
#include <crtdbg.h>

using namespace Microsoft::WRL;

#define TRACE OutputDebugString
#define ASSERT _ASSERTE

class WinPhone8XamlD3DWindow : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IWinPhone8XamlD3DWindow>
{
public:
    WinPhone8XamlD3DWindow() 
        : m_device(nullptr)
        , m_context(nullptr)
        , m_renderTarget(nullptr)
    {
        //TRACE((LPCWSTR)"WinPhone8XamlD3DWindow()\n");
    }

    ~WinPhone8XamlD3DWindow()
    {
        release();
        //TRACE((LPCWSTR)"~WinPhone8XamlD3DWindow()\n");
    }

    //
    // IWinPhone8XamlD3DWindow
    //

    virtual ID3D11Device1* __stdcall GetDevice() const override
    {
        if(m_device)
        {
            m_device->AddRef();
        }
        return m_device;
    }

   virtual  ID3D11DeviceContext1* __stdcall GetContext() const override
    {
        if(m_context)
        {
            m_context->AddRef();
        }       
        return m_context;
    }

    virtual ID3D11RenderTargetView* __stdcall GetRenderTarget() const override
    {
        if(m_renderTarget)
        {
            m_renderTarget->AddRef();
        }    
        return m_renderTarget;
    }

    virtual void __stdcall Update(ID3D11Device1* device, ID3D11DeviceContext1* context, ID3D11RenderTargetView* renderTarget) override
    {
        release();

        if(device)
        {
            device->AddRef();
        }

        if(context)
        {
            context->AddRef();
        }

        if(renderTarget)
        {
            renderTarget->AddRef();
        }

        m_device = device;
        m_context = context;
        m_renderTarget = renderTarget;
    }

    virtual HRESULT getBackBuffer(ID3D11Texture2D** buffer) const override
    {
        HRESULT result = S_OK;
        *buffer = NULL;

        ComPtr<ID3D11Resource> renderTargetViewResource;
        ComPtr<ID3D11Texture2D> texture2d;

        if(m_renderTarget)
        {
            m_renderTarget->GetResource(&renderTargetViewResource);

            if(renderTargetViewResource != NULL)
            {
                result = renderTargetViewResource.As(&texture2d);
                if(SUCCEEDED(result))
                {
                    *buffer = texture2d.Get();
                    (*buffer)->AddRef();
                }
            }
        }

	    return result;
    }

private:

    void release()
    {
        SafeRelease(m_device);
        SafeRelease(m_context);
        SafeRelease(m_renderTarget);
    }

    ID3D11Device1* m_device;
    ID3D11DeviceContext1* m_context;
    ID3D11RenderTargetView* m_renderTarget;
};

HRESULT __stdcall CreateWinPhone8XamlWindow(IWinPhone8XamlD3DWindow ** result)
{
    ASSERT(result);
    *result = nullptr;

    ComPtr<IWinPhone8XamlD3DWindow> iWindow = Make<WinPhone8XamlD3DWindow>();

    if (!iWindow)
    {
        return E_OUTOFMEMORY;
    }

    *result = iWindow.Detach();
    return S_OK;
}

class WinrtEglWindow : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IWinrtEglWindow>
{
public:
    WinrtEglWindow(IUnknown* windowInterface, ANGLE_D3D_FEATURE_LEVEL featureLevel) 
        : m_featureLevel(featureLevel)
        , m_windowInterface(NULL)
        , m_device(NULL)
    {
        if (windowInterface != NULL)
		{
 			windowInterface->AddRef();
 			m_windowInterface = windowInterface;
		}
        //TRACE((LPCWSTR)"WinrtEglWindow()\n");
    }

    ~WinrtEglWindow()
    {
        release();
        //TRACE((LPCWSTR)"~WinrtEglWindow()\n");
    }

    void release()
    {
        SafeRelease(m_windowInterface);
        SafeRelease(m_device);
    }

    //
    // IWinrtEglWindow
    //

    virtual void __stdcall SetAngleD3DDevice(ID3D11Device* device) override
    {
        SafeRelease(m_device);
        if (device)
        {
            device->AddRef();
            m_device = device;
        }
    }

    virtual ID3D11Device* __stdcall GetAngleD3DDevice() const override
    {
        if (m_device)
        {
            m_device->AddRef();
        }

        return m_device;
    }

    virtual ANGLE_D3D_FEATURE_LEVEL __stdcall GetAngleD3DFeatureLevel() const override
    {
        return m_featureLevel;
    }

    virtual D3D_FEATURE_LEVEL __stdcall getD3DFeatureLevel() const override
    {
	    D3D_FEATURE_LEVEL level = D3D_FEATURE_LEVEL_11_0;

	    switch(m_featureLevel)
	    {
		    case ANGLE_D3D_FEATURE_LEVEL_ANY:
		    case ANGLE_D3D_FEATURE_LEVEL_11_0:
			    level = D3D_FEATURE_LEVEL_11_0;
			    break;
		    case ANGLE_D3D_FEATURE_LEVEL_10_1:
			    level = D3D_FEATURE_LEVEL_10_1;
			    break;
		    case ANGLE_D3D_FEATURE_LEVEL_10_0:
			    level = D3D_FEATURE_LEVEL_10_0;
			    break;
		    case ANGLE_D3D_FEATURE_LEVEL_9_3:
			    level = D3D_FEATURE_LEVEL_9_3;
			    break;
		    case ANGLE_D3D_FEATURE_LEVEL_9_2:
			    level = D3D_FEATURE_LEVEL_9_2;
			    break;		
		    case ANGLE_D3D_FEATURE_LEVEL_9_1:
			    level = D3D_FEATURE_LEVEL_9_1;
			    break;
	    }

	    return level;
    }   

    virtual IUnknown* __stdcall GetWindowInterface() const override
    {
        if(m_windowInterface)
        {
            m_windowInterface->AddRef();
        }
        return m_windowInterface;
    }

private:
    ANGLE_D3D_FEATURE_LEVEL m_featureLevel;
    IUnknown* m_windowInterface;
    ID3D11Device* m_device;
};

HRESULT __stdcall CreateWinrtEglWindow(IUnknown* windowInterface, ANGLE_D3D_FEATURE_LEVEL featureLevel, IWinrtEglWindow ** result)
{
    ASSERT(result);
    *result = NULL;

    ComPtr<IWinrtEglWindow> iWindow = Make<WinrtEglWindow>(windowInterface, featureLevel);

    if (!iWindow)
    {
        return E_OUTOFMEMORY;
    }

    *result = iWindow.Detach();
    return S_OK;
}


