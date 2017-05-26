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

// WindowsApplicationModelCore.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Core.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelCore.h"
#include "WindowsApplicationModelCore_priv.h"

@implementation WACIFrameworkView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::IFrameworkView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)Initialize:(WACCoreApplicationView*)applicationView {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(
        _comInst->Initialize(_getRtInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView>(applicationView).Get()));
}

- (void)setWindow:(WUCCoreWindow*)window {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->SetWindow(_getRtInterface<ABI::Windows::UI::Core::ICoreWindow>(window).Get()));
}

- (void)Load:(NSString*)entryPoint {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->Load(nsStrToHstr(entryPoint).Get()));
}

- (void)run {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->Run());
}

- (void)uninitialize {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkView>(self);
    THROW_NS_IF_FAILED(_comInst->Uninitialize());
}

@end

@implementation WACIFrameworkViewSource

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::IFrameworkViewSource> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WACIFrameworkView>*)createView {
    ComPtr<ABI::Windows::ApplicationModel::Core::IFrameworkView> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IFrameworkViewSource>(self);
    THROW_NS_IF_FAILED(_comInst->CreateView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACIFrameworkView>(unmarshalledReturn.Get());
}

@end

@implementation WACICoreApplicationUnhandledError

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addUnhandledErrorDetectedEvent:(void (^)(RTObject*, WACUnhandledErrorDetectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError>(self);
    THROW_NS_IF_FAILED(_comInst->add_UnhandledErrorDetected(
        Make<EventHandler_Windows_ApplicationModel_Core_UnhandledErrorDetectedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUnhandledErrorDetectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UnhandledErrorDetected(token));
}

@end

@implementation WACAppListEntry

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::IAppListEntry> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAAppDisplayInfo*)displayInfo {
    ComPtr<ABI::Windows::ApplicationModel::IAppDisplayInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IAppListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAppDisplayInfo>(unmarshalledReturn.Get());
}

- (void)launchAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IAppListEntry>(self);
    THROW_NS_IF_FAILED(_comInst->LaunchAsync(&unmarshalledReturn));

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

@end

@implementation WACCoreApplication

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationExit> WACICoreApplicationExit_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationExit> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (void)exit {
    auto _comInst = WACICoreApplicationExit_inst();
    THROW_NS_IF_FAILED(_comInst->Exit());
}

+ (EventRegistrationToken)addExitingEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACICoreApplicationExit_inst();
    THROW_NS_IF_FAILED(_comInst->add_Exiting(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeExitingEvent:(EventRegistrationToken)token {
    auto _comInst = WACICoreApplicationExit_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Exiting(token));
}

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication> WACICoreImmersiveApplication_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (NSArray* /* WACCoreApplicationView* */)views {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Core::CoreApplicationView*>> unmarshalledReturn;
    auto _comInst = WACICoreImmersiveApplication_inst();
    THROW_NS_IF_FAILED(_comInst->get_Views(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WACCoreApplicationView_create(unmarshalledReturn.Get());
}

+ (WACCoreApplicationView*)createNewView:(NSString*)runtimeType entryPoint:(NSString*)entryPoint {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationView> unmarshalledReturn;
    auto _comInst = WACICoreImmersiveApplication_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateNewView(nsStrToHstr(runtimeType).Get(), nsStrToHstr(entryPoint).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACCoreApplicationView>(unmarshalledReturn.Get());
}

+ (WACCoreApplicationView*)mainView {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationView> unmarshalledReturn;
    auto _comInst = WACICoreImmersiveApplication_inst();
    THROW_NS_IF_FAILED(_comInst->get_MainView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACCoreApplicationView>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError> WACICoreApplicationUnhandledError_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationUnhandledError> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (EventRegistrationToken)addUnhandledErrorDetectedEvent:(void (^)(RTObject*, WACUnhandledErrorDetectedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACICoreApplicationUnhandledError_inst();
    THROW_NS_IF_FAILED(_comInst->add_UnhandledErrorDetected(
        Make<EventHandler_Windows_ApplicationModel_Core_UnhandledErrorDetectedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeUnhandledErrorDetectedEvent:(EventRegistrationToken)token {
    auto _comInst = WACICoreApplicationUnhandledError_inst();
    THROW_NS_IF_FAILED(_comInst->remove_UnhandledErrorDetected(token));
}

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationUseCount> WACICoreApplicationUseCount_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationUseCount> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (void)incrementApplicationUseCount {
    auto _comInst = WACICoreApplicationUseCount_inst();
    THROW_NS_IF_FAILED(_comInst->IncrementApplicationUseCount());
}

+ (void)decrementApplicationUseCount {
    auto _comInst = WACICoreApplicationUseCount_inst();
    THROW_NS_IF_FAILED(_comInst->DecrementApplicationUseCount());
}

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication2> WACICoreApplication2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (EventRegistrationToken)addBackgroundActivatedEvent:(void (^)(RTObject*, WAABackgroundActivatedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACICoreApplication2_inst();
    THROW_NS_IF_FAILED(_comInst->add_BackgroundActivated(
        Make<EventHandler_Windows_ApplicationModel_Activation_BackgroundActivatedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeBackgroundActivatedEvent:(EventRegistrationToken)token {
    auto _comInst = WACICoreApplication2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_BackgroundActivated(token));
}

+ (EventRegistrationToken)addLeavingBackgroundEvent:(void (^)(RTObject*, WALeavingBackgroundEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACICoreApplication2_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_LeavingBackground(Make<EventHandler_Windows_ApplicationModel_LeavingBackgroundEventArgs>(handler).Get(),
                                        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeLeavingBackgroundEvent:(EventRegistrationToken)token {
    auto _comInst = WACICoreApplication2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_LeavingBackground(token));
}

+ (EventRegistrationToken)addEnteredBackgroundEvent:(void (^)(RTObject*, WAEnteredBackgroundEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACICoreApplication2_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_EnteredBackground(Make<EventHandler_Windows_ApplicationModel_EnteredBackgroundEventArgs>(handler).Get(),
                                        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeEnteredBackgroundEvent:(EventRegistrationToken)token {
    auto _comInst = WACICoreApplication2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_EnteredBackground(token));
}

+ (void)enablePrelaunch:(BOOL)value {
    auto _comInst = WACICoreApplication2_inst();
    THROW_NS_IF_FAILED(_comInst->EnablePrelaunch((boolean)value));
}

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication2> WACICoreImmersiveApplication2_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (WACCoreApplicationView*)createNewViewFromMainView {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationView> unmarshalledReturn;
    auto _comInst = WACICoreImmersiveApplication2_inst();
    THROW_NS_IF_FAILED(_comInst->CreateNewViewFromMainView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACCoreApplicationView>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication3> WACICoreImmersiveApplication3_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreImmersiveApplication3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (WACCoreApplicationView*)createNewViewWithViewSource:(RTObject<WACIFrameworkViewSource>*)viewSource {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationView> unmarshalledReturn;
    auto _comInst = WACICoreImmersiveApplication3_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateNewViewWithViewSource(_getRtInterface<ABI::Windows::ApplicationModel::Core::IFrameworkViewSource>(viewSource).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACCoreApplicationView>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication> WACICoreApplication_inst() {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplication> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Core.CoreApplication").Get(),
                                                       &inst));
    return inst;
}

+ (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (EventRegistrationToken)addSuspendingEvent:(void (^)(RTObject*, WASuspendingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_Suspending(Make<EventHandler_Windows_ApplicationModel_SuspendingEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeSuspendingEvent:(EventRegistrationToken)token {
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Suspending(token));
}

+ (EventRegistrationToken)addResumingEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->add_Resuming(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeResumingEvent:(EventRegistrationToken)token {
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->remove_Resuming(token));
}

+ (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

+ (WACCoreApplicationView*)getCurrentView {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationView> unmarshalledReturn;
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->GetCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACCoreApplicationView>(unmarshalledReturn.Get());
}

+ (void)run:(RTObject<WACIFrameworkViewSource>*)viewSource {
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->Run(_getRtInterface<ABI::Windows::ApplicationModel::Core::IFrameworkViewSource>(viewSource).Get()));
}

+ (void)runWithActivationFactories:(RTObject<WFIGetActivationFactory>*)activationFactoryCallback {
    auto _comInst = WACICoreApplication_inst();
    THROW_NS_IF_FAILED(_comInst->RunWithActivationFactories(
        _getRtInterface<ABI::Windows::Foundation::IGetActivationFactory>(activationFactoryCallback).Get()));
}

@end

@implementation WACCoreApplicationView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCoreWindow*)coreWindow {
    ComPtr<ABI::Windows::UI::Core::ICoreWindow> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoreWindow(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreWindow>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addActivatedEvent:(void (^)(WACCoreApplicationView*, RTObject<WAAIActivatedEventArgs>*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->add_Activated(
        Make<ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Activation_IActivatedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeActivatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Activated(token));
}

- (BOOL)isMain {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsMain(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isHosted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsHosted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (BOOL)isComponent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsComponent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WACCoreApplicationViewTitleBar*)titleBar {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->get_TitleBar(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACCoreApplicationViewTitleBar>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addHostedViewClosingEvent:(void (^)(WACCoreApplicationView*, WACHostedViewClosingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->add_HostedViewClosing(
        Make<ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationView_Windows_ApplicationModel_Core_HostedViewClosingEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHostedViewClosingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationView3>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HostedViewClosing(token));
}

@end

@implementation WACCoreApplicationViewTitleBar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setExtendViewIntoTitleBar:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExtendViewIntoTitleBar((boolean)value));
}

- (BOOL)extendViewIntoTitleBar {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendViewIntoTitleBar(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)systemOverlayLeftInset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemOverlayLeftInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)systemOverlayRightInset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_SystemOverlayRightInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)height {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Height(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addLayoutMetricsChangedEvent:(void (^)(WACCoreApplicationViewTitleBar*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_LayoutMetricsChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationViewTitleBar_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLayoutMetricsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LayoutMetricsChanged(token));
}

- (BOOL)isVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addIsVisibleChangedEvent:(void (^)(WACCoreApplicationViewTitleBar*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_IsVisibleChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_Core_CoreApplicationViewTitleBar_System_Object>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeIsVisibleChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::ICoreApplicationViewTitleBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_IsVisibleChanged(token));
}

@end

@implementation WACUnhandledErrorDetectedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACUnhandledError*)unhandledError {
    ComPtr<ABI::Windows::ApplicationModel::Core::IUnhandledError> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnhandledError(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACUnhandledError>(unmarshalledReturn.Get());
}

@end

@implementation WACHostedViewClosingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::IHostedViewClosingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IHostedViewClosingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WACUnhandledError

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Core::IUnhandledError> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IUnhandledError>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)propagate {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Core::IUnhandledError>(self);
    THROW_NS_IF_FAILED(_comInst->Propagate());
}

@end

id RTProxiedNSArray_WACCoreApplicationView_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Core::CoreApplicationView*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Core::ICoreApplicationView*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Core::CoreApplicationView*>,
                                                    WACCoreApplicationView,
                                                    ABI::Windows::ApplicationModel::Core::CoreApplicationView*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
