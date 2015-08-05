//
// Copyright (c) 2002-2010 The ANGLE Project Authors. All rights reserved.Microsoft::WR::
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// winrtutils.cpp: WinRT/WP8 utilities.

#include "common/winrtutils.h"


#include <wrl\implements.h>
#include <wrl\module.h>
#include <wrl\event.h>
#include <wrl\wrappers\corewrappers.h>
#include <windows.applicationmodel.core.h>
#include <math.h>

#include "common/winrtplatform.h"

#if !defined(ANGLE_PLATFORM_WP8)
#include <windows.ui.xaml.media.dxinterop.h>
#endif // !defined(ANGLE_PLATFORM_WP8)

using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Storage;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::Windows::ApplicationModel;
using namespace ABI::Windows::Graphics::Display;
using namespace ABI::Windows::UI::Core;

namespace winrt 
{

DisplayOrientations GetDisplayOrientation()
{
#if defined(ANGLE_PLATFORM_WINRT)
    ComPtr<IDisplayPropertiesStatics> dp;
    DisplayOrientations orientation = DisplayOrientations_None;

    if (SUCCEEDED(GetActivationFactory(HStringReference(RuntimeClass_Windows_Graphics_Display_DisplayProperties).Get(), dp.GetAddressOf()))) 
    {
        if (SUCCEEDED(dp->get_CurrentOrientation(&orientation))) 
        {
            return orientation;
        }
    }
#endif
    return DisplayOrientations_None;
}

static float GetLogicalDpi()
{
#if defined(ANGLE_PLATFORM_WINRT)
    ComPtr<IDisplayPropertiesStatics> dp;
    FLOAT dpi = 1.0;

    if (SUCCEEDED(GetActivationFactory(HStringReference(RuntimeClass_Windows_Graphics_Display_DisplayProperties).Get(), dp.GetAddressOf()))) 
    {
        if (SUCCEEDED(dp->get_LogicalDpi(&dpi)))
        {
            return dpi;
        }
    }
#endif
    return 1.0;
}


// Method to convert a length in device-independent pixels (DIPs) to a length in physical pixels.
float convertDipsToPixels(float dips)
{
   static const float dipsPerInch = 96.0f;
   return floor(dips * GetLogicalDpi() / dipsPerInch + 0.5f); // Round to nearest integer.
}

bool isSwapChainBackgroundPanel(ComPtr<IUnknown> window)
{
#if defined(ANGLE_PLATFORM_WP8)
    return FALSE;
#else
    ComPtr<ISwapChainBackgroundPanelNative> panelNative;
    return S_OK == (window.As(&panelNative));
#endif // #if defined(ANGLE_PLATFORM_WP8)
}


ComPtr<ICoreWindow> getCurrentWindowForThread()
{
#if defined(ANGLE_PLATFORM_WINRT)
    HRESULT result = S_OK;
    ComPtr<ICoreWindow> window;
    ComPtr<ICoreWindowStatic> staticWindow;
    result = GetActivationFactory(HStringReference(L"Windows.UI.Core.CoreWindow").Get(), staticWindow.GetAddressOf());
    if(SUCCEEDED(S_OK))
    {
        result = staticWindow->GetForCurrentThread(window.GetAddressOf());
    } 
    if(SUCCEEDED(S_OK))
    {
        return window;
    }
#endif
    return nullptr;
}

HRESULT getWindowDimensions(ComPtr<ICoreWindow> window, int& width, int& height)
{
    width = 0;
    height = 0;
    Rect bounds;
    HRESULT result = window->get_Bounds(&bounds);

    if(SUCCEEDED(result))
    {
        width = static_cast<int>(convertDipsToPixels(bounds.Width));    
        height = static_cast<int>(convertDipsToPixels(bounds.Height));   
    }
    return result;
}

HRESULT getCurrentWindowDimensions(int& width, int& height)
{
    width = 0;
    height = 0;
    HRESULT result = -1;

    ComPtr<ICoreWindow> window = getCurrentWindowForThread();
    if(window.Get() != nullptr)
    {
        result = getWindowDimensions(window,width, height);
    }

    return result;
}

std::string getTemporaryFilePath()
{
#if defined(ANGLE_PLATFORM_WINRT)
    HString hstrAppData;
    hstrAppData.Set(RuntimeClass_Windows_ApplicationModel_Package);
    ComPtr<IActivationFactory> pActivationFactory;
    HRESULT hr = GetActivationFactory(hstrAppData.Get(), &pActivationFactory);
    std::string result = "";

    ComPtr<IPackageStatics> packageStatics;
    hr = pActivationFactory.As(&packageStatics);	
    if(SUCCEEDED(hr))
    {
        ComPtr<IPackage> package;
        hr = packageStatics->get_Current(&package);
        if(SUCCEEDED(hr))
        {
            ComPtr<IStorageFolder> storageFolder;
            hr = package->get_InstalledLocation(&storageFolder);
            if(SUCCEEDED(hr))
            {
                ComPtr<IStorageItem> storageItem;
                hr = storageFolder.As(&storageItem);
                if(SUCCEEDED(hr))
                {
                    HSTRING hsPath;
                    storageItem->get_Path(&hsPath);
                    std::wstring t = std::wstring(WindowsGetStringRawBuffer(hsPath,0));
                    result = std::string(t.begin(),t.end());
                }
            }
        }
    }

    return result;
#else
	TCHAR buf[4096];
	GetTempPath(4096, buf);
	return std::string(buf);
#endif
}

}
