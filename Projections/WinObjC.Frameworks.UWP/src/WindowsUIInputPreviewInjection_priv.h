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

// WindowsUIInputPreviewInjection_priv.h
// Forward decls for private object generation
#pragma once

ComPtr<ABI::Windows::UI::Input::Preview::Injection::IInputInjectorStatics> WUIPIIInputInjectorStatics_inst();
@interface WUIPIInjectedInputRectangle (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle*)internalStruct;
@end
inline WUIPIInjectedInputRectangle* WUIPIInjectedInputRectangle_create(
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputRectangle val) {
    return [WUIPIInjectedInputRectangle createWith:val];
}
@interface WUIPIInjectedInputPoint (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint*)internalStruct;
@end
inline WUIPIInjectedInputPoint* WUIPIInjectedInputPoint_create(ABI::Windows::UI::Input::Preview::Injection::InjectedInputPoint val) {
    return [WUIPIInjectedInputPoint createWith:val];
}
@interface WUIPIInjectedInputPointerInfo (Internal)
+ (instancetype)createWith:(ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo)s
    __attribute__((ns_returns_autoreleased));
- (ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo*)internalStruct;
@end
inline WUIPIInjectedInputPointerInfo* WUIPIInjectedInputPointerInfo_create(
    ABI::Windows::UI::Input::Preview::Injection::InjectedInputPointerInfo val) {
    return [WUIPIInjectedInputPointerInfo createWith:val];
}

id RTProxiedIterableNSArray_WUIPIInjectedInputKeyboardInfo_create(IInspectable* val);
id RTProxiedIterableNSArray_WUIPIInjectedInputMouseInfo_create(IInspectable* val);
id RTProxiedIterableNSArray_WUIPIInjectedInputTouchInfo_create(IInspectable* val);

@class RTProxiedIterableNSArray_WUIPIInjectedInputKeyboardInfo, RTProxiedIterableNSArray_WUIPIInjectedInputMouseInfo,
    RTProxiedIterableNSArray_WUIPIInjectedInputTouchInfo;
