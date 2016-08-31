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
#pragma once

#import "Starboard.h"
#include <COMIncludes.h>
#import <WRLHelpers.h>
#import <ErrorHandling.h>
#import <RawBuffer.h>
#import <wrl/client.h>
#import <wrl/implements.h>
#import <wrl/async.h>
#import <wrl/wrappers/corewrappers.h>
#import <windows.foundation.h>
#import <windows.ui.xaml.input.h>
#include <COMIncludes_end.h>

#import <UWP/WindowsUIXamlControls.h>
#import <UWP/WindowsUIXamlInput.h>

namespace XamlControls {

////////////////////////////////////////////////////////////////////////////////////
// Shared Helpers
////////////////////////////////////////////////////////////////////////////////////

// TODO: GitHub issue 508 and 509
// We need a type-safe way to do this with projections.  This is copied verbatim from the projections
// code and works perfectly for this limited usage, but we don't do any type validation below.
inline id _createRtProxy(Class cls, IInspectable* iface) {
    // Oddly, WinRT can hand us back NULL objects from successful function calls. Plumb these through as nil.
    if (!iface) {
        return nil;
    }

    RTObject* ret = [NSAllocateObject(cls, 0, 0) init];
    [ret setComObj:iface];
    return [ret autorelease];
}

inline RTObject* _createBareRTObj(IInspectable* obj) {
    return _createRtProxy(objc_getClass("RTObject"), obj);
}

template <typename I>
inline I* _createRtProxy(IInspectable* iface) {
    return _createRtProxy([I class], iface);
}

// TODO: Remove when we move our controls over to actual XAML-build control implementations
class WUXIPointerEventHandler_shim
    : public Microsoft::WRL::RuntimeClass<Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::WinRtClassicComMix>,
                                          ABI::Windows::UI::Xaml::Input::IPointerEventHandler> {
    void (^_delegate)(RTObject*, WUXIPointerRoutedEventArgs*);

public:
    WUXIPointerEventHandler_shim(void (^del)(RTObject*, WUXIPointerRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIPointerEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* arg1) override {
        NSAutoreleasePool* p = [NSAutoreleasePool new];
        _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIPointerRoutedEventArgs>(arg1));
        [p release];
        return 0;
    }
};

////////////////////////////////////////////////////////////////////////////////////
// Button
////////////////////////////////////////////////////////////////////////////////////
WXCButton* CreateButton();

void HookButtonPointerEvents(WXCButton* button,
                             WUXIPointerEventHandler pointerPressedHook,
                             WUXIPointerEventHandler pointerMovedHook,
                             WUXIPointerEventHandler pointerReleasedHook,
                             WUXIPointerEventHandler pointerCanceledHook,
                             WUXIPointerEventHandler pointerCaptureLostHook);

} // namespace XamlControls