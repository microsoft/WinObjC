#include "pch.h"
#include <ppltasks.h>

using namespace DirectX;
#include "Direct3DInterop.h"
#include "Direct3DContentProvider.h"

using namespace Windows::Foundation;
using namespace Windows::UI::Core;
using namespace Windows::UI::Input;
using namespace Microsoft::WRL;
using namespace Windows::Phone::Graphics::Interop;
using namespace Windows::Phone::Input::Interop;
using namespace Windows::Graphics::Display;
using namespace Concurrency;

namespace PhoneDirect3DXamlAppComponent
{

Direct3DInterop::Direct3DInterop() 
    : m_timer(ref new BasicTimer())
    , mCurrentOrientation(DisplayOrientations::None)
{
    m_renderer = ref new CubeRenderer();


    //Profiler::Initialize();
}




IDrawingSurfaceBackgroundContentProvider^ Direct3DInterop::CreateContentProvider()
{
    ComPtr<Direct3DContentProvider> provider = Make<Direct3DContentProvider>(this);
    return reinterpret_cast<IDrawingSurfaceBackgroundContentProvider^>(provider.Get());
}



// IDrawingSurfaceManipulationHandler
void Direct3DInterop::SetManipulationHost(DrawingSurfaceManipulationHost^ manipulationHost)
{
    manipulationHost->PointerPressed +=
        ref new TypedEventHandler<DrawingSurfaceManipulationHost^, PointerEventArgs^>(this, &Direct3DInterop::OnPointerPressed);

    manipulationHost->PointerMoved +=
        ref new TypedEventHandler<DrawingSurfaceManipulationHost^, PointerEventArgs^>(this, &Direct3DInterop::OnPointerMoved);

    manipulationHost->PointerReleased +=
        ref new TypedEventHandler<DrawingSurfaceManipulationHost^, PointerEventArgs^>(this, &Direct3DInterop::OnPointerReleased);
}

void Direct3DInterop::UpdateForWindowSizeChange(float width, float height)
{
    m_renderer->UpdateForWindowSizeChange(width, height);
}

void Direct3DInterop::OnFocusChange(bool active)
{
   // m_renderer->OnFocusChange(active);
}

void Direct3DInterop::OnResuming()
{
    //m_renderer->OnResuming();
}

IAsyncAction^ Direct3DInterop::OnSuspending()
{
   // return m_renderer->OnSuspending();
    return create_async([]() { });
}

bool Direct3DInterop::IsBackKeyHandled()
{
    //return m_renderer->OnBackPressed();
    return false;
}


// Event Handlers
void Direct3DInterop::OnPointerPressed(DrawingSurfaceManipulationHost^ sender, PointerEventArgs^ args)
{
    PointerPoint^ point = args->CurrentPoint;

    //m_renderer->AddTouch(point->PointerId, ::Windows::Foundation::Point(point->RawPosition.X, point->RawPosition.Y));
}

void Direct3DInterop::OnPointerMoved(DrawingSurfaceManipulationHost^ sender, PointerEventArgs^ args)
{
    PointerPoint^ point = args->CurrentPoint;

    //m_renderer->UpdateTouch(point->PointerId, ::Windows::Foundation::Point(point->RawPosition.X, point->RawPosition.Y));
}

void Direct3DInterop::OnPointerReleased(DrawingSurfaceManipulationHost^ sender, PointerEventArgs^ args)
{
    //m_renderer->RemoveTouch(args->CurrentPoint->PointerId);
}

// Interface With Direct3DContentProvider
HRESULT Direct3DInterop::Connect(_In_ IDrawingSurfaceRuntimeHostNative* host, _In_ ID3D11Device1* device)
{
    // Restart timer after renderer has finished initializing.
    m_timer->Reset();
    return S_OK;
}

void Direct3DInterop::Disconnect()
{
}

HRESULT Direct3DInterop::PrepareResources(_In_ const LARGE_INTEGER* presentTargetTime, _Inout_ DrawingSurfaceSizeF* desiredRenderTargetSize)
{
    //Profiler::FrameStart();
    m_timer->Update();
    m_renderer->Update(m_timer->Total, m_timer->Delta);
    return S_OK;

}

HRESULT Direct3DInterop::Draw(_In_ ID3D11Device1* device, _In_ ID3D11DeviceContext1* context, _In_ ID3D11RenderTargetView* renderTargetView)
{
    m_renderer->UpdateDevice(device, context, renderTargetView);

    if(mCurrentOrientation != WindowOrientation)
    {
        mCurrentOrientation = WindowOrientation;
        m_renderer->OnOrientationChanged(mCurrentOrientation);
    }

    m_renderer->Render();
    RequestAdditionalFrame();

    return S_OK;

    //Profiler::Render(device, context);
}

}
