//
// Copyright (c) 2002-2013 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// winrtutils.h: Common WinRT utilities.

#ifndef COMMON_WINRTUTILS_H_
#define COMMON_WINRTUTILS_H_

#include <wrl\client.h>
#include <windows.ui.core.h>
#include <windows.graphics.display.h>

#include <string>

namespace winrt 
{

ABI::Windows::Graphics::Display::DisplayOrientations GetDisplayOrientation();


// Method to convert a length in device-independent pixels (DIPs) to a length in physical pixels.
float convertDipsToPixels(float dips);

bool isSwapChainBackgroundPanel(Microsoft::WRL::ComPtr<IUnknown> window);

HRESULT getWindowDimensions(Microsoft::WRL::ComPtr<ABI::Windows::UI::Core::ICoreWindow> window, int& width, int& height);

Microsoft::WRL::ComPtr<ABI::Windows::UI::Core::ICoreWindow> getCurrentWindowForThread();

HRESULT getCurrentWindowDimensions(int& width, int& height);

std::string getTemporaryFilePath();


} // namespace winrt



#endif // COMMON_WINRTUTILS_H_
