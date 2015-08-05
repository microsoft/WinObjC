#include "winrtangleutils.h"
#include "winrtutils.h"

using namespace Microsoft::WRL;

namespace winrtangleutils
{

bool hasIPhoneXamlWindow(ComPtr<IWinrtEglWindow>& iWindow)
{
	ComPtr<IWinPhone8XamlD3DWindow> iPhoneXamlWindow;
	ComPtr<IUnknown> iWindowInterface = iWindow.Get()->GetWindowInterface();
	return iWindowInterface == nullptr ? false : iWindowInterface.As(&iPhoneXamlWindow) == S_OK;
}

HRESULT getIWinRTWindow(ComPtr<IUnknown>& iWindow, ComPtr<IWinrtEglWindow> *iWinRTWindow)
{
	return iWindow.As(iWinRTWindow);
}

HRESULT getIPhoneXamlWindow(ComPtr<IUnknown>& iWindow, ComPtr<IWinPhone8XamlD3DWindow> *iPhoneXamlWindow)
{
	ComPtr<IWinrtEglWindow> iWinRTWindow;
	HRESULT result = getIWinRTWindow(iWindow, &iWinRTWindow);
    if (SUCCEEDED(result))
	{
		ComPtr<IUnknown> iWindowInterface = iWinRTWindow.Get()->GetWindowInterface();
		result = iWindowInterface.Get() == nullptr? S_FALSE : iWindowInterface.As(iPhoneXamlWindow);
	}
	return result;
}



HRESULT getWindowSize(ComPtr<IUnknown>& iWindow, int& width, int& height)
{
	ComPtr<IWinPhone8XamlD3DWindow> iPhoneWindow;
	HRESULT result = getIPhoneXamlWindow(iWindow, &iPhoneWindow);
  
    if (SUCCEEDED(result))
    {
		ID3D11Texture2D* backBuffer;
		result = iPhoneWindow->getBackBuffer(&backBuffer);

		if(SUCCEEDED(result))
		{
			D3D11_TEXTURE2D_DESC backBufferDesc;
			backBuffer->GetDesc(&backBufferDesc);
			width = backBufferDesc.Width;
			height = backBufferDesc.Height;
		}
        backBuffer->Release();
    }
	else
	{
		 winrt::getCurrentWindowDimensions(width, height);
	}

	return result;
}



} //namespace winrtangleutils 
