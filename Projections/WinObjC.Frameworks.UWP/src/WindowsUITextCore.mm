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

// WindowsUITextCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Text.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUITextCore.h"
#include "WindowsUITextCore_priv.h"

@implementation WUTCCoreTextTextRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextTextRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextRange*)range {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Range(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextSelectionRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextRange*)selection {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Selection(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

- (void)setSelection:(WUTCCoreTextRange*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->put_Selection(*[value internalStruct]));
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextLayoutBounds

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextLayoutBounds> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)textBounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutBounds>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextBounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setTextBounds:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutBounds>(self);
    THROW_NS_IF_FAILED(_comInst->put_TextBounds(*[value internalStruct]));
}

- (WFRect*)controlBounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutBounds>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlBounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setControlBounds:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutBounds>(self);
    THROW_NS_IF_FAILED(_comInst->put_ControlBounds(*[value internalStruct]));
}

@end

@implementation WUTCCoreTextLayoutRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextRange*)range {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Range(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

- (WUTCCoreTextLayoutBounds*)layoutBounds {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextLayoutBounds> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_LayoutBounds(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTCCoreTextLayoutBounds>(unmarshalledReturn.Get());
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequest>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextCompositionSegment

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextCompositionSegment> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)preconversionString {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextCompositionSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreconversionString(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUTCCoreTextRange*)range {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextCompositionSegment>(self);
    THROW_NS_IF_FAILED(_comInst->get_Range(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

@end

@implementation WUTCCoreTextEditContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextEditContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(value).Get()));
}

- (WUTCCoreTextInputScope)inputScope {
    ABI::Windows::UI::Text::Core::CoreTextInputScope unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputScope(&unmarshalledReturn));
    return (WUTCCoreTextInputScope)unmarshalledReturn;
}

- (void)setInputScope:(WUTCCoreTextInputScope)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_InputScope((ABI::Windows::UI::Text::Core::CoreTextInputScope)value));
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsReadOnly:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsReadOnly((boolean)value));
}

- (WUTCCoreTextInputPaneDisplayPolicy)inputPaneDisplayPolicy {
    ABI::Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputPaneDisplayPolicy(&unmarshalledReturn));
    return (WUTCCoreTextInputPaneDisplayPolicy)unmarshalledReturn;
}

- (void)setInputPaneDisplayPolicy:(WUTCCoreTextInputPaneDisplayPolicy)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_InputPaneDisplayPolicy((ABI::Windows::UI::Text::Core::CoreTextInputPaneDisplayPolicy)value));
}

- (EventRegistrationToken)addTextRequestedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextTextRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_TextRequested(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTextRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TextRequested(cookie));
}

- (EventRegistrationToken)addSelectionRequestedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_SelectionRequested(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSelectionRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SelectionRequested(cookie));
}

- (EventRegistrationToken)addLayoutRequestedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextLayoutRequestedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_LayoutRequested(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextLayoutRequestedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLayoutRequestedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LayoutRequested(cookie));
}

- (EventRegistrationToken)addTextUpdatingEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextTextUpdatingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_TextUpdating(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextTextUpdatingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTextUpdatingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TextUpdating(cookie));
}

- (EventRegistrationToken)addSelectionUpdatingEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionUpdatingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_SelectionUpdating(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextSelectionUpdatingEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSelectionUpdatingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SelectionUpdating(cookie));
}

- (EventRegistrationToken)addFormatUpdatingEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextFormatUpdatingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_FormatUpdating(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextFormatUpdatingEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFormatUpdatingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FormatUpdating(cookie));
}

- (EventRegistrationToken)addCompositionStartedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextCompositionStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_CompositionStarted(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionStartedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompositionStartedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CompositionStarted(cookie));
}

- (EventRegistrationToken)addCompositionCompletedEvent:(void (^)(WUTCCoreTextEditContext*,
                                                                 WUTCCoreTextCompositionCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->add_CompositionCompleted(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_Windows_UI_Text_Core_CoreTextCompositionCompletedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompositionCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_CompositionCompleted(cookie));
}

- (EventRegistrationToken)addFocusRemovedEvent:(void (^)(WUTCCoreTextEditContext*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_FocusRemoved(Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_System_Object>(handler).Get(),
                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFocusRemovedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FocusRemoved(cookie));
}

- (void)notifyFocusEnter {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyFocusEnter());
}

- (void)notifyFocusLeave {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyFocusLeave());
}

- (void)notifyTextChanged:(WUTCCoreTextRange*)modifiedRange newLength:(int)newLength newSelection:(WUTCCoreTextRange*)newSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyTextChanged(*[modifiedRange internalStruct], newLength, *[newSelection internalStruct]));
}

- (void)notifySelectionChanged:(WUTCCoreTextRange*)selection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->NotifySelectionChanged(*[selection internalStruct]));
}

- (void)notifyLayoutChanged {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext>(self);
    THROW_NS_IF_FAILED(_comInst->NotifyLayoutChanged());
}

- (EventRegistrationToken)addNotifyFocusLeaveCompletedEvent:(void (^)(WUTCCoreTextEditContext*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext2>(self);
    THROW_NS_IF_FAILED(_comInst->add_NotifyFocusLeaveCompleted(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextEditContext_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeNotifyFocusLeaveCompletedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextEditContext2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_NotifyFocusLeaveCompleted(cookie));
}

@end

@implementation WUTCCoreTextTextRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextTextRequest*)request {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextTextRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTCCoreTextTextRequest>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextSelectionRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextSelectionRequest*)request {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTCCoreTextSelectionRequest>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextLayoutRequestedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextLayoutRequest*)request {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextLayoutRequestedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTCCoreTextLayoutRequest>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextTextUpdatingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextRange*)range {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Range(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUTCCoreTextRange*)newSelection __attribute__((ns_returns_not_retained)) {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewSelection(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

- (WGLanguage*)inputLanguage {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGLanguage>(unmarshalledReturn.Get());
}

- (WUTCCoreTextTextUpdatingResult)result {
    ABI::Windows::UI::Text::Core::CoreTextTextUpdatingResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(&unmarshalledReturn));
    return (WUTCCoreTextTextUpdatingResult)unmarshalledReturn;
}

- (void)setResult:(WUTCCoreTextTextUpdatingResult)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Result((ABI::Windows::UI::Text::Core::CoreTextTextUpdatingResult)value));
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextTextUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextSelectionUpdatingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextRange*)selection {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Selection(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

- (WUTCCoreTextSelectionUpdatingResult)result {
    ABI::Windows::UI::Text::Core::CoreTextSelectionUpdatingResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(&unmarshalledReturn));
    return (WUTCCoreTextSelectionUpdatingResult)unmarshalledReturn;
}

- (void)setResult:(WUTCCoreTextSelectionUpdatingResult)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Result((ABI::Windows::UI::Text::Core::CoreTextSelectionUpdatingResult)value));
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextFormatUpdatingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUTCCoreTextRange*)range {
    ABI::Windows::UI::Text::Core::CoreTextRange unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Range(&unmarshalledReturn));
    return WUTCCoreTextRange_create(unmarshalledReturn);
}

- (id /* WUVUIElementType */)textColor {
    ComPtr<IReference<ABI::Windows::UI::ViewManagement::UIElementType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUVUIElementType, ABI::Windows::UI::ViewManagement::UIElementType>::convert(unmarshalledReturn.Get());
}

- (id /* WUVUIElementType */)backgroundColor {
    ComPtr<IReference<ABI::Windows::UI::ViewManagement::UIElementType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUVUIElementType, ABI::Windows::UI::ViewManagement::UIElementType>::convert(unmarshalledReturn.Get());
}

- (id /* WUVUIElementType */)underlineColor {
    ComPtr<IReference<ABI::Windows::UI::ViewManagement::UIElementType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnderlineColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUVUIElementType, ABI::Windows::UI::ViewManagement::UIElementType>::convert(unmarshalledReturn.Get());
}

- (id /* WUTUnderlineType */)underlineType {
    ComPtr<IReference<ABI::Windows::UI::Text::UnderlineType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnderlineType(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUTUnderlineType, ABI::Windows::UI::Text::UnderlineType>::convert(unmarshalledReturn.Get());
}

- (WUTCCoreTextFormatUpdatingReason)reason {
    ABI::Windows::UI::Text::Core::CoreTextFormatUpdatingReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Reason(&unmarshalledReturn));
    return (WUTCCoreTextFormatUpdatingReason)unmarshalledReturn;
}

- (WUTCCoreTextFormatUpdatingResult)result {
    ABI::Windows::UI::Text::Core::CoreTextFormatUpdatingResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(&unmarshalledReturn));
    return (WUTCCoreTextFormatUpdatingResult)unmarshalledReturn;
}

- (void)setResult:(WUTCCoreTextFormatUpdatingResult)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Result((ABI::Windows::UI::Text::Core::CoreTextFormatUpdatingResult)value));
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextCompositionStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextCompositionStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextCompositionCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isCanceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCanceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WUTCCoreTextCompositionSegment* */)compositionSegments {
    ComPtr<IVectorView<ABI::Windows::UI::Text::Core::CoreTextCompositionSegment*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompositionSegments(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WUTCCoreTextCompositionSegment_create(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextCompositionCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextServicesManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesManagerStatics> WUTCICoreTextServicesManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Text.Core.CoreTextServicesManager").Get(),
                                                       &inst));
    return inst;
}

+ (WUTCCoreTextServicesManager*)getForCurrentView {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesManager> unmarshalledReturn;
    auto _comInst = WUTCICoreTextServicesManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTCCoreTextServicesManager>(unmarshalledReturn.Get());
}

- (WGLanguage*)inputLanguage {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextServicesManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGLanguage>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addInputLanguageChangedEvent:(void (^)(WUTCCoreTextServicesManager*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextServicesManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_InputLanguageChanged(
        Make<ITypedEventHandler_Windows_UI_Text_Core_CoreTextServicesManager_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeInputLanguageChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextServicesManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_InputLanguageChanged(cookie));
}

- (WUTCCoreTextEditContext*)createEditContext {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextEditContext> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Text::Core::ICoreTextServicesManager>(self);
    THROW_NS_IF_FAILED(_comInst->CreateEditContext(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUTCCoreTextEditContext>(unmarshalledReturn.Get());
}

@end

@implementation WUTCCoreTextServicesConstants

ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesStatics> WUTCICoreTextServicesStatics_inst() {
    ComPtr<ABI::Windows::UI::Text::Core::ICoreTextServicesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Text.Core.CoreTextServicesConstants").Get(),
                                                       &inst));
    return inst;
}

+ (wchar_t)hiddenCharacter {
    wchar_t unmarshalledReturn;
    auto _comInst = WUTCICoreTextServicesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HiddenCharacter(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUTCCoreTextRange {
    ABI::Windows::UI::Text::Core::CoreTextRange structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Text::Core::CoreTextRange)s {
    WUTCCoreTextRange* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Text::Core::CoreTextRange*)internalStruct {
    return &structVal;
}
- (int)startCaretPosition {
    return structVal.StartCaretPosition;
}
- (void)setStartCaretPosition:(int)val {
    structVal.StartCaretPosition = val;
}
- (int)endCaretPosition {
    return structVal.EndCaretPosition;
}
- (void)setEndCaretPosition:(int)val {
    structVal.EndCaretPosition = val;
}
@end
id RTProxiedNSArray_WUTCCoreTextCompositionSegment_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Text::Core::CoreTextCompositionSegment*>,
                                         RTArrayObj<ABI::Windows::UI::Text::Core::ICoreTextCompositionSegment*,
                                                    IVectorView<ABI::Windows::UI::Text::Core::CoreTextCompositionSegment*>,
                                                    WUTCCoreTextCompositionSegment,
                                                    ABI::Windows::UI::Text::Core::CoreTextCompositionSegment*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
