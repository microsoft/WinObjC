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

// WindowsUIViewManagement.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.ViewManagement.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIViewManagement.h"
#include "WindowsUIViewManagement_priv.h"

@implementation WUVApplicationView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics2> WUVIApplicationViewStatics2_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationView").Get(), &inst));
    return inst;
}

+ (WUVApplicationView*)getForCurrentView {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationView> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVApplicationView>(unmarshalledReturn.Get());
}

+ (BOOL)terminateAppOnFinalViewClose {
    boolean unmarshalledReturn;
    auto _comInst = WUVIApplicationViewStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_TerminateAppOnFinalViewClose(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setTerminateAppOnFinalViewClose:(BOOL)value {
    auto _comInst = WUVIApplicationViewStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->put_TerminateAppOnFinalViewClose((boolean)value));
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewFullscreenStatics> WUVIApplicationViewFullscreenStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewFullscreenStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationView").Get(), &inst));
    return inst;
}

+ (BOOL)tryUnsnapToFullscreen {
    boolean unmarshalledReturn;
    auto _comInst = WUVIApplicationViewFullscreenStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryUnsnapToFullscreen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics3> WUVIApplicationViewStatics3_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationView").Get(), &inst));
    return inst;
}

+ (WUVApplicationViewWindowingMode)preferredLaunchWindowingMode {
    ABI::Windows::UI::ViewManagement::ApplicationViewWindowingMode unmarshalledReturn;
    auto _comInst = WUVIApplicationViewStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_PreferredLaunchWindowingMode(&unmarshalledReturn));
    return (WUVApplicationViewWindowingMode)unmarshalledReturn;
}

+ (void)setPreferredLaunchWindowingMode:(WUVApplicationViewWindowingMode)value {
    auto _comInst = WUVIApplicationViewStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->put_PreferredLaunchWindowingMode((ABI::Windows::UI::ViewManagement::ApplicationViewWindowingMode)value));
}

+ (WFSize*)preferredLaunchViewSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = WUVIApplicationViewStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_PreferredLaunchViewSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

+ (void)setPreferredLaunchViewSize:(WFSize*)value {
    auto _comInst = WUVIApplicationViewStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->put_PreferredLaunchViewSize(*[value internalStruct]));
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewInteropStatics> WUVIApplicationViewInteropStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewInteropStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationView").Get(), &inst));
    return inst;
}

+ (int)getApplicationViewIdForWindow:(RTObject<WUCICoreWindow>*)window {
    int unmarshalledReturn;
    auto _comInst = WUVIApplicationViewInteropStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetApplicationViewIdForWindow(_getRtInterface<ABI::Windows::UI::Core::ICoreWindow>(window).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics> WUVIApplicationViewStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationView").Get(), &inst));
    return inst;
}

+ (WUVApplicationViewState)value {
    ABI::Windows::UI::ViewManagement::ApplicationViewState unmarshalledReturn;
    auto _comInst = WUVIApplicationViewStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return (WUVApplicationViewState)unmarshalledReturn;
}

+ (BOOL)tryUnsnap {
    boolean unmarshalledReturn;
    auto _comInst = WUVIApplicationViewStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryUnsnap(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUVApplicationViewOrientation)orientation {
    ABI::Windows::UI::ViewManagement::ApplicationViewOrientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WUVApplicationViewOrientation)unmarshalledReturn;
}

- (BOOL)adjacentToLeftDisplayEdge {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdjacentToLeftDisplayEdge(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)adjacentToRightDisplayEdge {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdjacentToRightDisplayEdge(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isFullScreen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFullScreen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isOnLockScreen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOnLockScreen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isScreenCaptureEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsScreenCaptureEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsScreenCaptureEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsScreenCaptureEnabled((boolean)value));
}

- (void)setTitle:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->put_Title(nsStrToHstr(value).Get()));
}

- (NSString*)title {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Title(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)id {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addConsolidatedEvent:(void (^)(WUVApplicationView*, WUVApplicationViewConsolidatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->add_Consolidated(
        Make<ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_Windows_UI_ViewManagement_ApplicationViewConsolidatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeConsolidatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Consolidated(token));
}

- (BOOL)suppressSystemOverlays {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuppressSystemOverlays(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSuppressSystemOverlays:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuppressSystemOverlays((boolean)value));
}

- (WFRect*)visibleBounds {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_VisibleBounds(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (EventRegistrationToken)addVisibleBoundsChangedEvent:(void (^)(WUVApplicationView*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView2>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_VisibleBoundsChanged(Make<ITypedEventHandler_Windows_UI_ViewManagement_ApplicationView_System_Object>(handler).Get(),
                                           &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVisibleBoundsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VisibleBoundsChanged(token));
}

- (BOOL)setDesiredBoundsMode:(WUVApplicationViewBoundsMode)boundsMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView2>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetDesiredBoundsMode((ABI::Windows::UI::ViewManagement::ApplicationViewBoundsMode)boundsMode, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUVApplicationViewBoundsMode)desiredBoundsMode {
    ABI::Windows::UI::ViewManagement::ApplicationViewBoundsMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredBoundsMode(&unmarshalledReturn));
    return (WUVApplicationViewBoundsMode)unmarshalledReturn;
}

- (WUVApplicationViewTitleBar*)titleBar {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->get_TitleBar(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVApplicationViewTitleBar>(unmarshalledReturn.Get());
}

- (WUVFullScreenSystemOverlayMode)fullScreenSystemOverlayMode {
    ABI::Windows::UI::ViewManagement::FullScreenSystemOverlayMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullScreenSystemOverlayMode(&unmarshalledReturn));
    return (WUVFullScreenSystemOverlayMode)unmarshalledReturn;
}

- (void)setFullScreenSystemOverlayMode:(WUVFullScreenSystemOverlayMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->put_FullScreenSystemOverlayMode((ABI::Windows::UI::ViewManagement::FullScreenSystemOverlayMode)value));
}

- (BOOL)isFullScreenMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFullScreenMode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tryEnterFullScreenMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->TryEnterFullScreenMode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)exitFullScreenMode {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->ExitFullScreenMode());
}

- (void)showStandardSystemOverlays {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->ShowStandardSystemOverlays());
}

- (BOOL)tryResizeView:(WFSize*)value {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->TryResizeView(*[value internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setPreferredMinSize:(WFSize*)minSize {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->SetPreferredMinSize(*[minSize internalStruct]));
}

@end

@implementation WUVApplicationViewConsolidatedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isUserInitiated {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewConsolidatedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsUserInitiated(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUVApplicationViewTitleBar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setForegroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)foregroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setBackgroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)backgroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonForegroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonForegroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonForegroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonForegroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonBackgroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonBackgroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonBackgroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonBackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonHoverForegroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonHoverForegroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonHoverForegroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonHoverForegroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonHoverBackgroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonHoverBackgroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonHoverBackgroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonHoverBackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonPressedForegroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonPressedForegroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonPressedForegroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonPressedForegroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonPressedBackgroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonPressedBackgroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonPressedBackgroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonPressedBackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setInactiveForegroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_InactiveForegroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)inactiveForegroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_InactiveForegroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setInactiveBackgroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_InactiveBackgroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)inactiveBackgroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_InactiveBackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonInactiveForegroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonInactiveForegroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonInactiveForegroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonInactiveForegroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setButtonInactiveBackgroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ButtonInactiveBackgroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)buttonInactiveBackgroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ButtonInactiveBackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

@end

@implementation WUVApplicationViewSwitcher

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics> WUVIApplicationViewSwitcherStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationViewSwitcher").Get(),
                                                       &inst));
    return inst;
}

+ (void)disableShowingMainViewOnActivation {
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DisableShowingMainViewOnActivation());
}

+ (void)tryShowAsStandaloneAsync:(int)viewId success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryShowAsStandaloneAsync(viewId, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)tryShowAsStandaloneWithSizePreferenceAsync:(int)viewId
                                    sizePreference:(WUVViewSizePreference)sizePreference
                                           success:(void (^)(BOOL))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->TryShowAsStandaloneWithSizePreferenceAsync(viewId,
                                                             (ABI::Windows::UI::ViewManagement::ViewSizePreference)sizePreference,
                                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)tryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync:(int)viewId
                                                 sizePreference:(WUVViewSizePreference)sizePreference
                                                   anchorViewId:(int)anchorViewId
                                           anchorSizePreference:(WUVViewSizePreference)anchorSizePreference
                                                        success:(void (^)(BOOL))success
                                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync(
        viewId,
        (ABI::Windows::UI::ViewManagement::ViewSizePreference)sizePreference,
        anchorViewId,
        (ABI::Windows::UI::ViewManagement::ViewSizePreference)anchorSizePreference,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (RTObject<WFIAsyncAction>*)switchAsync:(int)viewId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SwitchAsync(viewId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)switchFromViewAsync:(int)toViewId fromViewId:(int)fromViewId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SwitchFromViewAsync(toViewId, fromViewId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)switchFromViewWithOptionsAsync:(int)toViewId
                                                 fromViewId:(int)fromViewId
                                                    options:(WUVApplicationViewSwitchingOptions)options {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SwitchFromViewWithOptionsAsync(toViewId,
                                                                fromViewId,
                                                                (ABI::Windows::UI::ViewManagement::ApplicationViewSwitchingOptions)options,
                                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)prepareForCustomAnimatedSwitchAsync:(int)toViewId
                                 fromViewId:(int)fromViewId
                                    options:(WUVApplicationViewSwitchingOptions)options
                                    success:(void (^)(BOOL))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WUVIApplicationViewSwitcherStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->PrepareForCustomAnimatedSwitchAsync(toViewId,
                                                      fromViewId,
                                                      (ABI::Windows::UI::ViewManagement::ApplicationViewSwitchingOptions)options,
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics2> WUVIApplicationViewSwitcherStatics2_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewSwitcherStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationViewSwitcher").Get(),
                                                       &inst));
    return inst;
}

+ (void)disableSystemViewActivationPolicy {
    auto _comInst = WUVIApplicationViewSwitcherStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->DisableSystemViewActivationPolicy());
}

@end

@implementation WUVActivationViewSwitcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)showAsStandaloneAsync:(int)viewId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsStandaloneAsync(viewId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)showAsStandaloneWithSizePreferenceAsync:(int)viewId sizePreference:(WUVViewSizePreference)sizePreference {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->ShowAsStandaloneWithSizePreferenceAsync(viewId,
                                                          (ABI::Windows::UI::ViewManagement::ViewSizePreference)sizePreference,
                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (BOOL)isViewPresentedOnActivationVirtualDesktop:(int)viewId {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IActivationViewSwitcher>(self);
    THROW_NS_IF_FAILED(_comInst->IsViewPresentedOnActivationVirtualDesktop(viewId, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUVApplicationViewTransferContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewTransferContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationViewTransferContext").Get(),
                                              &out));
    return [_createRtProxy<WUVApplicationViewTransferContext>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewTransferContextStatics> WUVIApplicationViewTransferContextStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewTransferContextStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationViewTransferContext").Get(), &inst));
    return inst;
}

+ (NSString*)dataPackageFormatId {
    HSTRING unmarshalledReturn;
    auto _comInst = WUVIApplicationViewTransferContextStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DataPackageFormatId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)viewId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTransferContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setViewId:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IApplicationViewTransferContext>(self);
    THROW_NS_IF_FAILED(_comInst->put_ViewId(value));
}

@end

@implementation WUVInputPaneVisibilityEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)occludedRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OccludedRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setEnsuredFocusedElementInView:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_EnsuredFocusedElementInView((boolean)value));
}

- (BOOL)ensuredFocusedElementInView {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPaneVisibilityEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_EnsuredFocusedElementInView(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUVInputPane

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IInputPane> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::ViewManagement::IInputPaneStatics> WUVIInputPaneStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IInputPaneStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.InputPane").Get(), &inst));
    return inst;
}

+ (WUVInputPane*)getForCurrentView {
    ComPtr<ABI::Windows::UI::ViewManagement::IInputPane> unmarshalledReturn;
    auto _comInst = WUVIInputPaneStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVInputPane>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addShowingEvent:(void (^)(WUVInputPane*, WUVInputPaneVisibilityEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_Showing(
        Make<ITypedEventHandler_Windows_UI_ViewManagement_InputPane_Windows_UI_ViewManagement_InputPaneVisibilityEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeShowingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Showing(token));
}

- (EventRegistrationToken)addHidingEvent:(void (^)(WUVInputPane*, WUVInputPaneVisibilityEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPane>(self);
    THROW_NS_IF_FAILED(_comInst->add_Hiding(
        Make<ITypedEventHandler_Windows_UI_ViewManagement_InputPane_Windows_UI_ViewManagement_InputPaneVisibilityEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHidingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPane>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Hiding(token));
}

- (WFRect*)occludedRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPane>(self);
    THROW_NS_IF_FAILED(_comInst->get_OccludedRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)tryShow {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPane2>(self);
    THROW_NS_IF_FAILED(_comInst->TryShow(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tryHide {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPane2>(self);
    THROW_NS_IF_FAILED(_comInst->TryHide(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)visible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPaneControl>(self);
    THROW_NS_IF_FAILED(_comInst->get_Visible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IInputPaneControl>(self);
    THROW_NS_IF_FAILED(_comInst->put_Visible((boolean)value));
}

@end

@implementation WUVProjectionManager

ComPtr<ABI::Windows::UI::ViewManagement::IProjectionManagerStatics> WUVIProjectionManagerStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IProjectionManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ProjectionManager").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)startProjectingAsync:(int)projectionViewId anchorViewId:(int)anchorViewId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->StartProjectingAsync(projectionViewId, anchorViewId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)swapDisplaysForViewsAsync:(int)projectionViewId anchorViewId:(int)anchorViewId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SwapDisplaysForViewsAsync(projectionViewId, anchorViewId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)stopProjectingAsync:(int)projectionViewId anchorViewId:(int)anchorViewId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->StopProjectingAsync(projectionViewId, anchorViewId, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (BOOL)projectionDisplayAvailable {
    boolean unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProjectionDisplayAvailable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (EventRegistrationToken)addProjectionDisplayAvailableChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_ProjectionDisplayAvailableChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeProjectionDisplayAvailableChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WUVIProjectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ProjectionDisplayAvailableChanged(token));
}

ComPtr<ABI::Windows::UI::ViewManagement::IProjectionManagerStatics2> WUVIProjectionManagerStatics2_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IProjectionManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ProjectionManager").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)startProjectingWithDeviceInfoAsync:(int)projectionViewId
                                                   anchorViewId:(int)anchorViewId
                                              displayDeviceInfo:(WDEDeviceInformation*)displayDeviceInfo {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->StartProjectingWithDeviceInfoAsync(
        projectionViewId,
        anchorViewId,
        _getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(displayDeviceInfo).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)requestStartProjectingAsync:(int)projectionViewId
                       anchorViewId:(int)anchorViewId
                          selection:(WFRect*)selection
                            success:(void (^)(BOOL))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestStartProjectingAsync(projectionViewId, anchorViewId, *[selection internalStruct], &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (void)requestStartProjectingWithPlacementAsync:(int)projectionViewId
                                    anchorViewId:(int)anchorViewId
                                       selection:(WFRect*)selection
                              prefferedPlacement:(WUPPlacement)prefferedPlacement
                                         success:(void (^)(BOOL))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestStartProjectingWithPlacementAsync(projectionViewId,
                                                                          anchorViewId,
                                                                          *[selection internalStruct],
                                                                          (ABI::Windows::UI::Popups::Placement)prefferedPlacement,
                                                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
                            }
                        } else {
                            if (failureRc) {
                                failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                            }
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                        }
                    }
                    return S_OK;
                }
            });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WUVIProjectionManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUVUIViewSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IUIViewSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::ViewManagement::IUIViewSettingsStatics> WUVIUIViewSettingsStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IUIViewSettingsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.UIViewSettings").Get(), &inst));
    return inst;
}

+ (WUVUIViewSettings*)getForCurrentView {
    ComPtr<ABI::Windows::UI::ViewManagement::IUIViewSettings> unmarshalledReturn;
    auto _comInst = WUVIUIViewSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVUIViewSettings>(unmarshalledReturn.Get());
}

- (WUVUserInteractionMode)userInteractionMode {
    ABI::Windows::UI::ViewManagement::UserInteractionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUIViewSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserInteractionMode(&unmarshalledReturn));
    return (WUVUserInteractionMode)unmarshalledReturn;
}

@end

@implementation WUVAccessibilitySettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IAccessibilitySettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.ViewManagement.AccessibilitySettings").Get(), &out));
    return [_createRtProxy<WUVAccessibilitySettings>(out.Get()) retain];
}

- (BOOL)highContrast {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IAccessibilitySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HighContrast(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)highContrastScheme {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IAccessibilitySettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HighContrastScheme(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (EventRegistrationToken)addHighContrastChangedEvent:(void (^)(WUVAccessibilitySettings*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IAccessibilitySettings>(self);
    THROW_NS_IF_FAILED(_comInst->add_HighContrastChanged(
        Make<ITypedEventHandler_Windows_UI_ViewManagement_AccessibilitySettings_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHighContrastChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IAccessibilitySettings>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HighContrastChanged(cookie));
}

@end

@implementation WUVUISettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IUISettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.ViewManagement.UISettings").Get(), &out));
    return [_createRtProxy<WUVUISettings>(out.Get()) retain];
}

- (WUVHandPreference)handPreference {
    ABI::Windows::UI::ViewManagement::HandPreference unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HandPreference(&unmarshalledReturn));
    return (WUVHandPreference)unmarshalledReturn;
}

- (WFSize*)cursorSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CursorSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)scrollBarSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScrollBarSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)scrollBarArrowSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScrollBarArrowSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (WFSize*)scrollBarThumbBoxSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScrollBarThumbBoxSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (unsigned int)messageDuration {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MessageDuration(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)animationsEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnimationsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)caretBrowsingEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaretBrowsingEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (unsigned int)caretBlinkRate {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaretBlinkRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)caretWidth {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaretWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)doubleClickTime {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DoubleClickTime(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (unsigned int)mouseHoverTime {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MouseHoverTime(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUColor*)uIElementColor:(WUVUIElementType)desiredElement {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings>(self);
    THROW_NS_IF_FAILED(_comInst->UIElementColor((ABI::Windows::UI::ViewManagement::UIElementType)desiredElement, &unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (double)textScaleFactor {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextScaleFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addTextScaleFactorChangedEvent:(void (^)(WUVUISettings*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings2>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_TextScaleFactorChanged(Make<ITypedEventHandler_Windows_UI_ViewManagement_UISettings_System_Object>(handler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeTextScaleFactorChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_TextScaleFactorChanged(cookie));
}

- (WUColor*)getColorValue:(WUVUIColorType)desiredColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings3>(self);
    THROW_NS_IF_FAILED(_comInst->GetColorValue((ABI::Windows::UI::ViewManagement::UIColorType)desiredColor, &unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (EventRegistrationToken)addColorValuesChangedEvent:(void (^)(WUVUISettings*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings3>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_ColorValuesChanged(Make<ITypedEventHandler_Windows_UI_ViewManagement_UISettings_System_Object>(handler).Get(),
                                         &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeColorValuesChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IUISettings3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ColorValuesChanged(cookie));
}

@end

@implementation WUVStatusBar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IStatusBar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::ViewManagement::IStatusBarStatics> WUVIStatusBarStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IStatusBarStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.StatusBar").Get(), &inst));
    return inst;
}

+ (WUVStatusBar*)getForCurrentView {
    ComPtr<ABI::Windows::UI::ViewManagement::IStatusBar> unmarshalledReturn;
    auto _comInst = WUVIStatusBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVStatusBar>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)showAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)hideAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->HideAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (double)backgroundOpacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundOpacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBackgroundOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundOpacity(value));
}

- (id /* WUColor* */)foregroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ForegroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setForegroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ForegroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (id /* WUColor* */)backgroundColor {
    ComPtr<IReference<ABI::Windows::UI::Color>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundColor(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WUColor, ABI::Windows::UI::Color>::convert(unmarshalledReturn.Get());
}

- (void)setBackgroundColor:(id /* WUColor* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackgroundColor(BuildNullable<ABI::Windows::UI::Color>(value)));
}

- (WUVStatusBarProgressIndicator*)progressIndicator {
    ComPtr<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProgressIndicator(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUVStatusBarProgressIndicator>(unmarshalledReturn.Get());
}

- (WFRect*)occludedRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_OccludedRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (EventRegistrationToken)addShowingEvent:(void (^)(WUVStatusBar*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_Showing(Make<ITypedEventHandler_Windows_UI_ViewManagement_StatusBar_System_Object>(eventHandler).Get(),
                                             &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeShowingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Showing(token));
}

- (EventRegistrationToken)addHidingEvent:(void (^)(WUVStatusBar*, RTObject*))eventHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_Hiding(Make<ITypedEventHandler_Windows_UI_ViewManagement_StatusBar_System_Object>(eventHandler).Get(),
                                            &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHidingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Hiding(token));
}

@end

@implementation WUVStatusBarProgressIndicator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WFIAsyncAction>*)showAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)hideAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator>(self);
    THROW_NS_IF_FAILED(_comInst->HideAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator>(self);
    THROW_NS_IF_FAILED(_comInst->put_Text(nsStrToHstr(value).Get()));
}

- (id /* double */)progressValue {
    ComPtr<IReference<double>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProgressValue(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<double, double>::convert(unmarshalledReturn.Get());
}

- (void)setProgressValue:(id /* double */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::ViewManagement::IStatusBarProgressIndicator>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProgressValue(BuildNullable<double>(value)));
}

@end

@implementation WUVApplicationViewScaling

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewScaling> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewScalingStatics> WUVIApplicationViewScalingStatics_inst() {
    ComPtr<ABI::Windows::UI::ViewManagement::IApplicationViewScalingStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.ViewManagement.ApplicationViewScaling").Get(),
                                                       &inst));
    return inst;
}

+ (BOOL)disableLayoutScaling {
    boolean unmarshalledReturn;
    auto _comInst = WUVIApplicationViewScalingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisableLayoutScaling(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)trySetDisableLayoutScaling:(BOOL)disableLayoutScaling {
    boolean unmarshalledReturn;
    auto _comInst = WUVIApplicationViewScalingStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TrySetDisableLayoutScaling((boolean)disableLayoutScaling, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end
