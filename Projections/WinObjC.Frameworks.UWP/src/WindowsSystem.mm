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

// WindowsSystem.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.System.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSystem.h"
#include "WindowsSystem_priv.h"

@implementation WSILauncherViewOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::ILauncherViewOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUVViewSizePreference)desiredRemainingView {
    ABI::Windows::UI::ViewManagement::ViewSizePreference unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherViewOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredRemainingView(&unmarshalledReturn));
    return (WUVViewSizePreference)unmarshalledReturn;
}

- (void)setDesiredRemainingView:(WUVViewSizePreference)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherViewOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredRemainingView((ABI::Windows::UI::ViewManagement::ViewSizePreference)value));
}

@end

@implementation WSAppMemoryUsageLimitChangingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IAppMemoryUsageLimitChangingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)oldLimit {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IAppMemoryUsageLimitChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)newLimit {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IAppMemoryUsageLimitChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSAppMemoryReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IAppMemoryReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)privateCommitUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IAppMemoryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrivateCommitUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)peakPrivateCommitUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IAppMemoryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PeakPrivateCommitUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)totalCommitUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IAppMemoryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalCommitUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)totalCommitLimit {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IAppMemoryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalCommitLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSProcessMemoryReport

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IProcessMemoryReport> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (uint64_t)privateWorkingSetUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessMemoryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrivateWorkingSetUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (uint64_t)totalWorkingSetUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessMemoryReport>(self);
    THROW_NS_IF_FAILED(_comInst->get_TotalWorkingSetUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSMemoryManager

ComPtr<ABI::Windows::System::IMemoryManagerStatics2> WSIMemoryManagerStatics2_inst() {
    ComPtr<ABI::Windows::System::IMemoryManagerStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.MemoryManager").Get(), &inst));
    return inst;
}

+ (WSAppMemoryReport*)getAppMemoryReport {
    ComPtr<ABI::Windows::System::IAppMemoryReport> unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetAppMemoryReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAppMemoryReport>(unmarshalledReturn.Get());
}

+ (WSProcessMemoryReport*)getProcessMemoryReport {
    ComPtr<ABI::Windows::System::IProcessMemoryReport> unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetProcessMemoryReport(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSProcessMemoryReport>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::System::IMemoryManagerStatics3> WSIMemoryManagerStatics3_inst() {
    ComPtr<ABI::Windows::System::IMemoryManagerStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.MemoryManager").Get(), &inst));
    return inst;
}

+ (BOOL)trySetAppMemoryUsageLimit:(uint64_t)value {
    boolean unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->TrySetAppMemoryUsageLimit(value, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::System::IMemoryManagerStatics> WSIMemoryManagerStatics_inst() {
    ComPtr<ABI::Windows::System::IMemoryManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.MemoryManager").Get(), &inst));
    return inst;
}

+ (uint64_t)appMemoryUsage {
    uint64_t unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AppMemoryUsage(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (uint64_t)appMemoryUsageLimit {
    uint64_t unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AppMemoryUsageLimit(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WSAppMemoryUsageLevel)appMemoryUsageLevel {
    ABI::Windows::System::AppMemoryUsageLevel unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AppMemoryUsageLevel(&unmarshalledReturn));
    return (WSAppMemoryUsageLevel)unmarshalledReturn;
}

+ (EventRegistrationToken)addAppMemoryUsageIncreasedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_AppMemoryUsageIncreased(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeAppMemoryUsageIncreasedEvent:(EventRegistrationToken)token {
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_AppMemoryUsageIncreased(token));
}

+ (EventRegistrationToken)addAppMemoryUsageDecreasedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_AppMemoryUsageDecreased(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeAppMemoryUsageDecreasedEvent:(EventRegistrationToken)token {
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_AppMemoryUsageDecreased(token));
}

+ (EventRegistrationToken)addAppMemoryUsageLimitChangingEvent:(void (^)(RTObject*, WSAppMemoryUsageLimitChangingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_AppMemoryUsageLimitChanging(Make<EventHandler_Windows_System_AppMemoryUsageLimitChangingEventArgs>(handler).Get(),
                                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeAppMemoryUsageLimitChangingEvent:(EventRegistrationToken)token {
    auto _comInst = WSIMemoryManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_AppMemoryUsageLimitChanging(token));
}

@end

@implementation WSProtocolForResultsOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IProtocolForResultsOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)reportCompleted:(WFCValueSet*)data {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProtocolForResultsOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(data).Get()));
}

@end

@implementation WSUserWatcher

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IUserWatcher> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSUserWatcherStatus)status {
    ABI::Windows::System::UserWatcherStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSUserWatcherStatus)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (EventRegistrationToken)addAddedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Added(Make<ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs>(handler).Get(),
                            &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAddedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Added(token));
}

- (EventRegistrationToken)addRemovedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Removed(Make<ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Removed(token));
}

- (EventRegistrationToken)addUpdatedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Updated(Make<ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs>(handler).Get(),
                              &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUpdatedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Updated(token));
}

- (EventRegistrationToken)addAuthenticationStatusChangedEvent:(void (^)(WSUserWatcher*, WSUserChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_AuthenticationStatusChanged(
        Make<ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserChangedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAuthenticationStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AuthenticationStatusChanged(token));
}

- (EventRegistrationToken)addAuthenticationStatusChangingEvent:(void (^)(WSUserWatcher*,
                                                                         WSUserAuthenticationStatusChangingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_AuthenticationStatusChanging(
        Make<ITypedEventHandler_Windows_System_UserWatcher_Windows_System_UserAuthenticationStatusChangingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAuthenticationStatusChangingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AuthenticationStatusChanging(token));
}

- (EventRegistrationToken)addEnumerationCompletedEvent:(void (^)(WSUserWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->add_EnumerationCompleted(Make<ITypedEventHandler_Windows_System_UserWatcher_System_Object>(handler).Get(),
                                                          &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeEnumerationCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_EnumerationCompleted(token));
}

- (EventRegistrationToken)addStoppedEvent:(void (^)(WSUserWatcher*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_Stopped(Make<ITypedEventHandler_Windows_System_UserWatcher_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStoppedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserWatcher>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Stopped(token));
}

@end

@implementation WSUser

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IUser> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::System::IUserStatics> WSIUserStatics_inst() {
    ComPtr<ABI::Windows::System::IUserStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.User").Get(), &inst));
    return inst;
}

+ (WSUserWatcher*)createWatcher {
    ComPtr<ABI::Windows::System::IUserWatcher> unmarshalledReturn;
    auto _comInst = WSIUserStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUserWatcher>(unmarshalledReturn.Get());
}

+ (void)findAllAsyncWithSuccess:(void (^)(NSArray* /* WSUser* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::System::User*>*>> unmarshalledReturn;
    auto _comInst = WSIUserStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::System::User*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::System::User*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::System::User*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSUser_create(result.Get()));
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

+ (void)findAllAsyncByType:(WSUserType)type success:(void (^)(NSArray* /* WSUser* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::System::User*>*>> unmarshalledReturn;
    auto _comInst = WSIUserStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsyncByType((ABI::Windows::System::UserType)type, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::System::User*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::System::User*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::System::User*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSUser_create(result.Get()));
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

+ (void)findAllAsyncByTypeAndStatus:(WSUserType)type
                             status:(WSUserAuthenticationStatus)status
                            success:(void (^)(NSArray* /* WSUser* */))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::System::User*>*>> unmarshalledReturn;
    auto _comInst = WSIUserStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllAsyncByTypeAndStatus((ABI::Windows::System::UserType)type,
                                                             (ABI::Windows::System::UserAuthenticationStatus)status,
                                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::System::User*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::System::User*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::System::User*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSUser_create(result.Get()));
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

+ (WSUser*)getFromId:(NSString*)nonRoamableId {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = WSIUserStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetFromId(nsStrToHstr(nonRoamableId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (NSString*)nonRoamableId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_NonRoamableId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSUserAuthenticationStatus)authenticationStatus {
    ABI::Windows::System::UserAuthenticationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticationStatus(&unmarshalledReturn));
    return (WSUserAuthenticationStatus)unmarshalledReturn;
}

- (WSUserType)type {
    ABI::Windows::System::UserType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUser>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WSUserType)unmarshalledReturn;
}

- (void)getPropertyAsync:(NSString*)value success:(void (^)(RTObject*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUser>(self);
    THROW_NS_IF_FAILED(_comInst->GetPropertyAsync(nsStrToHstr(value).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IInspectable*>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IInspectable*>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        ComPtr<IInspectable> result;
                        HRESULT hr = op->GetResults(result.GetAddressOf());
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(_createBareRTObj(result.Get()));
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

- (void)getPropertiesAsync:(NSArray* /* NSString * */)values
                   success:(void (^)(RTObject<WFCIPropertySet>*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Collections::IPropertySet*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUser>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetPropertiesAsync(static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToVectorView<NSString, HSTRING>(values).Get()),
                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Foundation::Collections::IPropertySet*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Foundation::Collections::IPropertySet*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WFCIPropertySet>(result.Get()));
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

- (void)getPictureAsync:(WSUserPictureSize)desiredSize
                success:(void (^)(RTObject<WSSIRandomAccessStreamReference>*))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamReference*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUser>(self);
    THROW_NS_IF_FAILED(_comInst->GetPictureAsync((ABI::Windows::System::UserPictureSize)desiredSize, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IRandomAccessStreamReference*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IRandomAccessStreamReference*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIRandomAccessStreamReference>(result.Get()));
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

@implementation WSUserChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IUserChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WSUserAuthenticationStatusChangingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IUserAuthenticationStatusChangingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSUserAuthenticationStatusChangeDeferral*)getDeferral {
    ComPtr<ABI::Windows::System::IUserAuthenticationStatusChangeDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserAuthenticationStatusChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUserAuthenticationStatusChangeDeferral>(unmarshalledReturn.Get());
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserAuthenticationStatusChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (WSUserAuthenticationStatus)newStatus {
    ABI::Windows::System::UserAuthenticationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserAuthenticationStatusChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewStatus(&unmarshalledReturn));
    return (WSUserAuthenticationStatus)unmarshalledReturn;
}

- (WSUserAuthenticationStatus)currentStatus {
    ABI::Windows::System::UserAuthenticationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserAuthenticationStatusChangingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentStatus(&unmarshalledReturn));
    return (WSUserAuthenticationStatus)unmarshalledReturn;
}

@end

@implementation WSUserAuthenticationStatusChangeDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IUserAuthenticationStatusChangeDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserAuthenticationStatusChangeDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WSKnownUserProperties

ComPtr<ABI::Windows::System::IKnownUserPropertiesStatics> WSIKnownUserPropertiesStatics_inst() {
    ComPtr<ABI::Windows::System::IKnownUserPropertiesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.KnownUserProperties").Get(), &inst));
    return inst;
}

+ (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)firstName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FirstName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)lastName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LastName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)providerName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ProviderName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)accountName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccountName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)guestHost {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GuestHost(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)principalName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PrincipalName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)domainName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DomainName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)sessionInitiationProtocolUri {
    HSTRING unmarshalledReturn;
    auto _comInst = WSIKnownUserPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SessionInitiationProtocolUri(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSUserPicker

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IUserPicker> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.System.UserPicker").Get(), &out));
    return [_createRtProxy<WSUserPicker>(out.Get()) retain];
}

ComPtr<ABI::Windows::System::IUserPickerStatics> WSIUserPickerStatics_inst() {
    ComPtr<ABI::Windows::System::IUserPickerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserPicker").Get(), &inst));
    return inst;
}

+ (BOOL)isSupported {
    boolean unmarshalledReturn;
    auto _comInst = WSIUserPickerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsSupported(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)allowGuestAccounts {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowGuestAccounts(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowGuestAccounts:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowGuestAccounts((boolean)value));
}

- (WSUser*)suggestedSelectedUser {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserPicker>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedSelectedUser(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (void)setSuggestedSelectedUser:(WSUser*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserPicker>(self);
    THROW_NS_IF_FAILED(_comInst->put_SuggestedSelectedUser(_getRtInterface<ABI::Windows::System::IUser>(value).Get()));
}

- (void)pickSingleUserAsyncWithSuccess:(void (^)(WSUser*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::User*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserPicker>(self);
    THROW_NS_IF_FAILED(_comInst->PickSingleUserAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::User*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::User*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::System::IUser> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSUser>(result.Get()));
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

@implementation WSUserDeviceAssociationChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IUserDeviceAssociationChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)deviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserDeviceAssociationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSUser*)newUser __attribute__((ns_returns_not_retained)) {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserDeviceAssociationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewUser(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (WSUser*)oldUser {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IUserDeviceAssociationChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldUser(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WSUserDeviceAssociation

ComPtr<ABI::Windows::System::IUserDeviceAssociationStatics> WSIUserDeviceAssociationStatics_inst() {
    ComPtr<ABI::Windows::System::IUserDeviceAssociationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.UserDeviceAssociation").Get(), &inst));
    return inst;
}

+ (WSUser*)findUserFromDeviceId:(NSString*)deviceId {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = WSIUserDeviceAssociationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindUserFromDeviceId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

+ (EventRegistrationToken)addUserDeviceAssociationChangedEvent:(void (^)(RTObject*, WSUserDeviceAssociationChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSIUserDeviceAssociationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_UserDeviceAssociationChanged(Make<EventHandler_Windows_System_UserDeviceAssociationChangedEventArgs>(handler).Get(),
                                                   &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeUserDeviceAssociationChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSIUserDeviceAssociationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_UserDeviceAssociationChanged(token));
}

@end

@implementation WSLaunchUriResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::ILaunchUriResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSLaunchUriStatus)status {
    ABI::Windows::System::LaunchUriStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILaunchUriResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSLaunchUriStatus)unmarshalledReturn;
}

- (WFCValueSet*)result {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILaunchUriResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCValueSet>(unmarshalledReturn.Get());
}

@end

@implementation WSLauncherUIOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::ILauncherUIOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* WFPoint* */)invocationPoint {
    ComPtr<IReference<ABI::Windows::Foundation::Point>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_InvocationPoint(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFPoint, ABI::Windows::Foundation::Point>::convert(unmarshalledReturn.Get());
}

- (void)setInvocationPoint:(id /* WFPoint* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_InvocationPoint(BuildNullable<ABI::Windows::Foundation::Point>(value)));
}

- (id /* WFRect* */)selectionRect {
    ComPtr<IReference<ABI::Windows::Foundation::Rect>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionRect(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFRect, ABI::Windows::Foundation::Rect>::convert(unmarshalledReturn.Get());
}

- (void)setSelectionRect:(id /* WFRect* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectionRect(BuildNullable<ABI::Windows::Foundation::Rect>(value)));
}

- (WUPPlacement)preferredPlacement {
    ABI::Windows::UI::Popups::Placement unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredPlacement(&unmarshalledReturn));
    return (WUPPlacement)unmarshalledReturn;
}

- (void)setPreferredPlacement:(WUPPlacement)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferredPlacement((ABI::Windows::UI::Popups::Placement)value));
}

@end

@implementation WSLauncherOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::ILauncherOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.System.LauncherOptions").Get(), &out));
    return [_createRtProxy<WSLauncherOptions>(out.Get()) retain];
}

- (BOOL)treatAsUntrusted {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_TreatAsUntrusted(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setTreatAsUntrusted:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_TreatAsUntrusted((boolean)value));
}

- (BOOL)displayApplicationPicker {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayApplicationPicker(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setDisplayApplicationPicker:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisplayApplicationPicker((boolean)value));
}

- (WSLauncherUIOptions*)uI {
    ComPtr<ABI::Windows::System::ILauncherUIOptions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_UI(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSLauncherUIOptions>(unmarshalledReturn.Get());
}

- (NSString*)preferredApplicationPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredApplicationPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPreferredApplicationPackageFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferredApplicationPackageFamilyName(nsStrToHstr(value).Get()));
}

- (NSString*)preferredApplicationDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredApplicationDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setPreferredApplicationDisplayName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_PreferredApplicationDisplayName(nsStrToHstr(value).Get()));
}

- (WFUri*)fallbackUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FallbackUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setFallbackUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FallbackUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSString*)contentType {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentType(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setContentType:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentType(nsStrToHstr(value).Get()));
}

- (WUVViewSizePreference)desiredRemainingView {
    ABI::Windows::UI::ViewManagement::ViewSizePreference unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherViewOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredRemainingView(&unmarshalledReturn));
    return (WUVViewSizePreference)unmarshalledReturn;
}

- (void)setDesiredRemainingView:(WUVViewSizePreference)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherViewOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredRemainingView((ABI::Windows::UI::ViewManagement::ViewSizePreference)value));
}

- (NSString*)targetApplicationPackageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetApplicationPackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetApplicationPackageFamilyName:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetApplicationPackageFamilyName(nsStrToHstr(value).Get()));
}

- (WSSStorageFileQueryResult*)neighboringFilesQuery {
    ComPtr<ABI::Windows::Storage::Search::IStorageFileQueryResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions2>(self);
    THROW_NS_IF_FAILED(_comInst->get_NeighboringFilesQuery(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSStorageFileQueryResult>(unmarshalledReturn.Get());
}

- (void)setNeighboringFilesQuery:(WSSStorageFileQueryResult*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_NeighboringFilesQuery(_getRtInterface<ABI::Windows::Storage::Search::IStorageFileQueryResult>(value).Get()));
}

- (BOOL)ignoreAppUriHandlers {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions3>(self);
    THROW_NS_IF_FAILED(_comInst->get_IgnoreAppUriHandlers(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIgnoreAppUriHandlers:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherOptions3>(self);
    THROW_NS_IF_FAILED(_comInst->put_IgnoreAppUriHandlers((boolean)value));
}

@end

@implementation WSRemoteLauncherOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IRemoteLauncherOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.System.RemoteLauncherOptions").Get(), &out));
    return [_createRtProxy<WSRemoteLauncherOptions>(out.Get()) retain];
}

- (WFUri*)fallbackUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IRemoteLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_FallbackUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)setFallbackUri:(WFUri*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IRemoteLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_FallbackUri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(value).Get()));
}

- (NSMutableArray* /* NSString * */)preferredAppIds {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IRemoteLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_PreferredAppIds(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSFolderLauncherOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IFolderLauncherOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.System.FolderLauncherOptions").Get(), &out));
    return [_createRtProxy<WSFolderLauncherOptions>(out.Get()) retain];
}

- (NSMutableArray* /* RTObject<WSIStorageItem>* */)itemsToSelect {
    ComPtr<IVector<ABI::Windows::Storage::IStorageItem*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IFolderLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemsToSelect(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WSIStorageItem_create(unmarshalledReturn.Get());
}

- (WUVViewSizePreference)desiredRemainingView {
    ABI::Windows::UI::ViewManagement::ViewSizePreference unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherViewOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredRemainingView(&unmarshalledReturn));
    return (WUVViewSizePreference)unmarshalledReturn;
}

- (void)setDesiredRemainingView:(WUVViewSizePreference)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::ILauncherViewOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredRemainingView((ABI::Windows::UI::ViewManagement::ViewSizePreference)value));
}

@end

@implementation WSLauncher

ComPtr<ABI::Windows::System::ILauncherStatics> WSILauncherStatics_inst() {
    ComPtr<ABI::Windows::System::ILauncherStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Launcher").Get(), &inst));
    return inst;
}

+ (void)launchFileAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

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

+ (void)launchFileWithOptionsAsync:(RTObject<WSIStorageFile>*)file
                           options:(WSLauncherOptions*)options
                           success:(void (^)(BOOL))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchFileWithOptionsAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                            _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
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

+ (void)launchUriAsync:(WFUri*)uri success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LaunchUriAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

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

+ (void)launchUriWithOptionsAsync:(WFUri*)uri
                          options:(WSLauncherOptions*)options
                          success:(void (^)(BOOL))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriWithOptionsAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                           _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
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

ComPtr<ABI::Windows::System::ILauncherStatics4> WSILauncherStatics4_inst() {
    ComPtr<ABI::Windows::System::ILauncherStatics4> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Launcher").Get(), &inst));
    return inst;
}

+ (void)queryAppUriSupportAsync:(WFUri*)uri success:(void (^)(WSLaunchQuerySupportStatus))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(
        _comInst->QueryAppUriSupportAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchQuerySupportStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::System::LaunchQuerySupportStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSLaunchQuerySupportStatus)result);
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

+ (void)queryAppUriSupportWithPackageFamilyNameAsync:(WFUri*)uri
                                   packageFamilyName:(NSString*)packageFamilyName
                                             success:(void (^)(WSLaunchQuerySupportStatus))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(
        _comInst->QueryAppUriSupportWithPackageFamilyNameAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                               nsStrToHstr(packageFamilyName).Get(),
                                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchQuerySupportStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::System::LaunchQuerySupportStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSLaunchQuerySupportStatus)result);
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

+ (void)findAppUriHandlersAsync:(WFUri*)uri success:(void (^)(NSArray* /* WAAppInfo* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindAppUriHandlersAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAppInfo_create(result.Get()));
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

+ (void)launchUriForUserAsync:(WSUser*)user
                          uri:(WFUri*)uri
                      success:(void (^)(WSLaunchUriStatus))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                       _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchUriStatus>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriStatus>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::LaunchUriStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSLaunchUriStatus)result);
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

+ (void)launchUriWithOptionsForUserAsync:(WSUser*)user
                                     uri:(WFUri*)uri
                                 options:(WSLauncherOptions*)options
                                 success:(void (^)(WSLaunchUriStatus))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriWithOptionsForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                  _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                                  _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
                                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchUriStatus>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriStatus>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::LaunchUriStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSLaunchUriStatus)result);
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

+ (void)launchUriWithDataForUserAsync:(WSUser*)user
                                  uri:(WFUri*)uri
                              options:(WSLauncherOptions*)options
                            inputData:(WFCValueSet*)inputData
                              success:(void (^)(WSLaunchUriStatus))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(
        _comInst->LaunchUriWithDataForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
                                                _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(inputData).Get(),
                                                &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchUriStatus>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriStatus>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::LaunchUriStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSLaunchUriStatus)result);
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

+ (void)launchUriForResultsForUserAsync:(WSUser*)user
                                    uri:(WFUri*)uri
                                options:(WSLauncherOptions*)options
                                success:(void (^)(WSLaunchUriResult*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriForResultsForUserAsync(_getRtInterface<ABI::Windows::System::IUser>(user).Get(),
                                                                 _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                                 _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
                                                                 &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchUriResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::System::ILaunchUriResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSLaunchUriResult>(result.Get()));
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

+ (void)launchUriForResultsWithDataForUserAsync:(WSUser*)user
                                            uri:(WFUri*)uri
                                        options:(WSLauncherOptions*)options
                                      inputData:(WFCValueSet*)inputData
                                        success:(void (^)(WSLaunchUriResult*))success
                                        failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriForResultsWithDataForUserAsync(
        _getRtInterface<ABI::Windows::System::IUser>(user).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(inputData).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchUriResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::System::ILaunchUriResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSLaunchUriResult>(result.Get()));
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

ComPtr<ABI::Windows::System::ILauncherStatics3> WSILauncherStatics3_inst() {
    ComPtr<ABI::Windows::System::ILauncherStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Launcher").Get(), &inst));
    return inst;
}

+ (void)launchFolderAsync:(RTObject<WSIStorageFolder>*)folder success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->LaunchFolderAsync(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(folder).Get(), &unmarshalledReturn));

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

+ (void)launchFolderWithOptionsAsync:(RTObject<WSIStorageFolder>*)folder
                             options:(WSFolderLauncherOptions*)options
                             success:(void (^)(BOOL))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchFolderWithOptionsAsync(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(folder).Get(),
                                                              _getRtInterface<ABI::Windows::System::IFolderLauncherOptions>(options).Get(),
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

ComPtr<ABI::Windows::System::ILauncherStatics2> WSILauncherStatics2_inst() {
    ComPtr<ABI::Windows::System::ILauncherStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.Launcher").Get(), &inst));
    return inst;
}

+ (void)launchUriForResultsAsync:(WFUri*)uri
                         options:(WSLauncherOptions*)options
                         success:(void (^)(WSLaunchUriResult*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriForResultsAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                          _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
                                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchUriResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::System::ILaunchUriResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSLaunchUriResult>(result.Get()));
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

+ (void)launchUriForResultsWithDataAsync:(WFUri*)uri
                                 options:(WSLauncherOptions*)options
                               inputData:(WFCValueSet*)inputData
                                 success:(void (^)(WSLaunchUriResult*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->LaunchUriForResultsWithDataAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                   _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
                                                   _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(inputData).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchUriResult*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchUriResult*>* op, AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::System::ILaunchUriResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSLaunchUriResult>(result.Get()));
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

+ (void)launchUriWithDataAsync:(WFUri*)uri
                       options:(WSLauncherOptions*)options
                     inputData:(WFCValueSet*)inputData
                       success:(void (^)(BOOL))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->LaunchUriWithDataAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                         _getRtInterface<ABI::Windows::System::ILauncherOptions>(options).Get(),
                                         _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(inputData).Get(),
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

+ (void)queryUriSupportAsync:(WFUri*)uri
      launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                     success:(void (^)(WSLaunchQuerySupportStatus))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->QueryUriSupportAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                      (ABI::Windows::System::LaunchQuerySupportType)launchQuerySupportType,
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchQuerySupportStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::System::LaunchQuerySupportStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSLaunchQuerySupportStatus)result);
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

+ (void)queryUriSupportWithPackageFamilyNameAsync:(WFUri*)uri
                           launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                                packageFamilyName:(NSString*)packageFamilyName
                                          success:(void (^)(WSLaunchQuerySupportStatus))success
                                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->QueryUriSupportWithPackageFamilyNameAsync(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
                                                            (ABI::Windows::System::LaunchQuerySupportType)launchQuerySupportType,
                                                            nsStrToHstr(packageFamilyName).Get(),
                                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchQuerySupportStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::System::LaunchQuerySupportStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSLaunchQuerySupportStatus)result);
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

+ (void)queryFileSupportAsync:(WSStorageFile*)file
                      success:(void (^)(WSLaunchQuerySupportStatus))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->QueryFileSupportAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchQuerySupportStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::System::LaunchQuerySupportStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSLaunchQuerySupportStatus)result);
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

+ (void)queryFileSupportWithPackageFamilyNameAsync:(WSStorageFile*)file
                                 packageFamilyName:(NSString*)packageFamilyName
                                           success:(void (^)(WSLaunchQuerySupportStatus))success
                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->QueryFileSupportWithPackageFamilyNameAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                             nsStrToHstr(packageFamilyName).Get(),
                                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::LaunchQuerySupportStatus>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::LaunchQuerySupportStatus>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::System::LaunchQuerySupportStatus result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WSLaunchQuerySupportStatus)result);
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

+ (void)findUriSchemeHandlersAsync:(NSString*)scheme
                           success:(void (^)(NSArray* /* WAAppInfo* */))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FindUriSchemeHandlersAsync(nsStrToHstr(scheme).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAppInfo_create(result.Get()));
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

+ (void)findUriSchemeHandlersWithLaunchUriTypeAsync:(NSString*)scheme
                             launchQuerySupportType:(WSLaunchQuerySupportType)launchQuerySupportType
                                            success:(void (^)(NSArray* /* WAAppInfo* */))success
                                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->FindUriSchemeHandlersWithLaunchUriTypeAsync(nsStrToHstr(scheme).Get(),
                                                              (ABI::Windows::System::LaunchQuerySupportType)launchQuerySupportType,
                                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAppInfo_create(result.Get()));
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

+ (void)findFileHandlersAsync:(NSString*)extension
                      success:(void (^)(NSArray* /* WAAppInfo* */))success
                      failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>> unmarshalledReturn;
    auto _comInst = WSILauncherStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->FindFileHandlersAsync(nsStrToHstr(extension).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAAppInfo_create(result.Get()));
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

@implementation WSRemoteLauncher

ComPtr<ABI::Windows::System::IRemoteLauncherStatics> WSIRemoteLauncherStatics_inst() {
    ComPtr<ABI::Windows::System::IRemoteLauncherStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.RemoteLauncher").Get(), &inst));
    return inst;
}

+ (void)launchUriAsync:(WSRRemoteSystemConnectionRequest*)remoteSystemConnectionRequest
                   uri:(WFUri*)uri
               success:(void (^)(WSRemoteLaunchUriStatus))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteLaunchUriStatus>> unmarshalledReturn;
    auto _comInst = WSIRemoteLauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriAsync(
        _getRtInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest>(remoteSystemConnectionRequest).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::RemoteLaunchUriStatus>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteLaunchUriStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::RemoteLaunchUriStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSRemoteLaunchUriStatus)result);
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

+ (void)launchUriWithOptionsAsync:(WSRRemoteSystemConnectionRequest*)remoteSystemConnectionRequest
                              uri:(WFUri*)uri
                          options:(WSRemoteLauncherOptions*)options
                          success:(void (^)(WSRemoteLaunchUriStatus))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteLaunchUriStatus>> unmarshalledReturn;
    auto _comInst = WSIRemoteLauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriWithOptionsAsync(
        _getRtInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest>(remoteSystemConnectionRequest).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        _getRtInterface<ABI::Windows::System::IRemoteLauncherOptions>(options).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::RemoteLaunchUriStatus>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteLaunchUriStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::RemoteLaunchUriStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSRemoteLaunchUriStatus)result);
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

+ (void)launchUriWithDataAsync:(WSRRemoteSystemConnectionRequest*)remoteSystemConnectionRequest
                           uri:(WFUri*)uri
                       options:(WSRemoteLauncherOptions*)options
                     inputData:(WFCValueSet*)inputData
                       success:(void (^)(WSRemoteLaunchUriStatus))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteLaunchUriStatus>> unmarshalledReturn;
    auto _comInst = WSIRemoteLauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchUriWithDataAsync(
        _getRtInterface<ABI::Windows::System::RemoteSystems::IRemoteSystemConnectionRequest>(remoteSystemConnectionRequest).Get(),
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        _getRtInterface<ABI::Windows::System::IRemoteLauncherOptions>(options).Get(),
        _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(inputData).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::RemoteLaunchUriStatus>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::RemoteLaunchUriStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::System::RemoteLaunchUriStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSRemoteLaunchUriStatus)result);
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

@implementation WSProcessLauncherOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IProcessLauncherOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.System.ProcessLauncherOptions").Get(), &out));
    return [_createRtProxy<WSProcessLauncherOptions>(out.Get()) retain];
}

- (RTObject<WSSIInputStream>*)standardInput {
    ComPtr<ABI::Windows::Storage::Streams::IInputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_StandardInput(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIInputStream>(unmarshalledReturn.Get());
}

- (void)setStandardInput:(RTObject<WSSIInputStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_StandardInput(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(value).Get()));
}

- (RTObject<WSSIOutputStream>*)standardOutput {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_StandardOutput(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (void)setStandardOutput:(RTObject<WSSIOutputStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_StandardOutput(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(value).Get()));
}

- (RTObject<WSSIOutputStream>*)standardError {
    ComPtr<ABI::Windows::Storage::Streams::IOutputStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_StandardError(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIOutputStream>(unmarshalledReturn.Get());
}

- (void)setStandardError:(RTObject<WSSIOutputStream>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_StandardError(_getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(value).Get()));
}

- (NSString*)workingDirectory {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_WorkingDirectory(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setWorkingDirectory:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_WorkingDirectory(nsStrToHstr(value).Get()));
}

@end

@implementation WSProcessLauncherResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::System::IProcessLauncherResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (unsigned int)exitCode {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::System::IProcessLauncherResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExitCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSProcessLauncher

ComPtr<ABI::Windows::System::IProcessLauncherStatics> WSIProcessLauncherStatics_inst() {
    ComPtr<ABI::Windows::System::IProcessLauncherStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.ProcessLauncher").Get(), &inst));
    return inst;
}

+ (void)runToCompletionAsync:(NSString*)fileName
                        args:(NSString*)args
                     success:(void (^)(WSProcessLauncherResult*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::ProcessLauncherResult*>> unmarshalledReturn;
    auto _comInst = WSIProcessLauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RunToCompletionAsync(nsStrToHstr(fileName).Get(), nsStrToHstr(args).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::ProcessLauncherResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::ProcessLauncherResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::System::IProcessLauncherResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSProcessLauncherResult>(result.Get()));
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

+ (void)runToCompletionAsyncWithOptions:(NSString*)fileName
                                   args:(NSString*)args
                                options:(WSProcessLauncherOptions*)options
                                success:(void (^)(WSProcessLauncherResult*))success
                                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::ProcessLauncherResult*>> unmarshalledReturn;
    auto _comInst = WSIProcessLauncherStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->RunToCompletionAsyncWithOptions(nsStrToHstr(fileName).Get(),
                                                  nsStrToHstr(args).Get(),
                                                  _getRtInterface<ABI::Windows::System::IProcessLauncherOptions>(options).Get(),
                                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::System::ProcessLauncherResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::System::ProcessLauncherResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::System::IProcessLauncherResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSProcessLauncherResult>(result.Get()));
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

@implementation WSShutdownManager

ComPtr<ABI::Windows::System::IShutdownManagerStatics> WSIShutdownManagerStatics_inst() {
    ComPtr<ABI::Windows::System::IShutdownManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.ShutdownManager").Get(), &inst));
    return inst;
}

+ (void)beginShutdown:(WSShutdownKind)shutdownKind timeout:(WFTimeSpan*)timeout {
    auto _comInst = WSIShutdownManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->BeginShutdown((ABI::Windows::System::ShutdownKind)shutdownKind, *[timeout internalStruct]));
}

+ (void)cancelShutdown {
    auto _comInst = WSIShutdownManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CancelShutdown());
}

@end

@implementation WSTimeZoneSettings

ComPtr<ABI::Windows::System::ITimeZoneSettingsStatics> WSITimeZoneSettingsStatics_inst() {
    ComPtr<ABI::Windows::System::ITimeZoneSettingsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.System.TimeZoneSettings").Get(), &inst));
    return inst;
}

+ (NSString*)currentTimeZoneDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = WSITimeZoneSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentTimeZoneDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSArray* /* NSString * */)supportedTimeZoneDisplayNames {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = WSITimeZoneSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedTimeZoneDisplayNames(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

+ (BOOL)canChangeTimeZone {
    boolean unmarshalledReturn;
    auto _comInst = WSITimeZoneSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanChangeTimeZone(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)changeTimeZoneByDisplayName:(NSString*)timeZoneDisplayName {
    auto _comInst = WSITimeZoneSettingsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ChangeTimeZoneByDisplayName(nsStrToHstr(timeZoneDisplayName).Get()));
}

@end

id RTProxiedNSArray_WAAppInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::AppInfo*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::IAppInfo*,
                                                    IVectorView<ABI::Windows::ApplicationModel::AppInfo*>,
                                                    WAAppInfo,
                                                    ABI::Windows::ApplicationModel::AppInfo*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSUser_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::System::User*>,
                                                                             RTArrayObj<ABI::Windows::System::IUser*,
                                                                                        IVectorView<ABI::Windows::System::User*>,
                                                                                        WSUser,
                                                                                        ABI::Windows::System::User*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WSIStorageItem_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Storage::IStorageItem*>,
                                                RTMutableArrayObj<ABI::Windows::Storage::IStorageItem*,
                                                                  IVector<ABI::Windows::Storage::IStorageItem*>,
                                                                  RTObject<WSIStorageItem>,
                                                                  ABI::Windows::Storage::IStorageItem*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
