//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsUIStartScreen_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsUIPopups_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUI_priv.h"
ComPtr<ABI::Windows::UI::StartScreen::IJumpListItemStatics> WUSIJumpListItemStatics_inst();
ComPtr<ABI::Windows::UI::StartScreen::IJumpListStatics> WUSIJumpListStatics_inst();
static ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileFactory> WUSISecondaryTileFactory_inst();
static ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileFactory2> WUSISecondaryTileFactory2_inst();
ComPtr<ABI::Windows::UI::StartScreen::ISecondaryTileStatics> WUSISecondaryTileStatics_inst();

id RTProxiedNSArray_WUSSecondaryTile_create(IInspectable* val);
id RTProxiedNSArray_WUSSecondaryTileVisualElements_create(IInspectable* val);
id RTProxiedNSMutableArray_WUSJumpListItem_create(IInspectable* val);

@class RTProxiedNSArray_WUSSecondaryTile, RTProxiedNSArray_WUSSecondaryTileVisualElements, RTProxiedNSMutableArray_WUSJumpListItem;

#ifndef __ITypedEventHandler_Windows_UI_StartScreen_SecondaryTile_Windows_UI_StartScreen_VisualElementsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_StartScreen_SecondaryTile_Windows_UI_StartScreen_VisualElementsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_StartScreen_SecondaryTile_Windows_UI_StartScreen_VisualElementsRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::StartScreen::SecondaryTile*,
                                                                       ABI::Windows::UI::StartScreen::VisualElementsRequestedEventArgs*>> {
    void (^_delegate)(WUSSecondaryTile*, WUSVisualElementsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_StartScreen_SecondaryTile_Windows_UI_StartScreen_VisualElementsRequestedEventArgs(
        void (^del)(WUSSecondaryTile*, WUSVisualElementsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_StartScreen_SecondaryTile_Windows_UI_StartScreen_VisualElementsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::StartScreen::ISecondaryTile* arg0,
                                             ABI::Windows::UI::StartScreen::IVisualElementsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUSSecondaryTile>(arg0), _createRtProxy<WUSVisualElementsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
