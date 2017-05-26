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

// WindowsApplicationModel.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModel.h"
#include "WindowsApplicationModel_priv.h"

@implementation WAISuspendingDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WAISuspendingOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASuspendingDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASuspendingDeferral>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WAISuspendingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASuspendingOperation*)suspendingOperation {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuspendingOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASuspendingOperation>(unmarshalledReturn.Get());
}

@end

@implementation WAILeavingBackgroundEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAIEnteredBackgroundEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAFullTrustProcessLauncher

ComPtr<ABI::Windows::ApplicationModel::IFullTrustProcessLauncherStatics> WAIFullTrustProcessLauncherStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::IFullTrustProcessLauncherStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.FullTrustProcessLauncher").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForCurrentAppAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAIFullTrustProcessLauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchFullTrustProcessForCurrentAppAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForCurrentAppWithParametersAsync:(NSString*)parameterGroupId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAIFullTrustProcessLauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchFullTrustProcessForCurrentAppWithParametersAsync(nsStrToHstr(parameterGroupId).Get(),
                                                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForAppAsync:(NSString*)fullTrustPackageRelativeAppId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAIFullTrustProcessLauncherStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LaunchFullTrustProcessForAppAsync(nsStrToHstr(fullTrustPackageRelativeAppId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)launchFullTrustProcessForAppWithParametersAsync:(NSString*)fullTrustPackageRelativeAppId
                                                            parameterGroupId:(NSString*)parameterGroupId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WAIFullTrustProcessLauncherStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LaunchFullTrustProcessForAppWithParametersAsync(nsStrToHstr(fullTrustPackageRelativeAppId).Get(),
                                                                                 nsStrToHstr(parameterGroupId).Get(),
                                                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WAStartupTask

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IStartupTask> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::IStartupTaskStatics> WAIStartupTaskStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::IStartupTaskStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.StartupTask").Get(), &inst));
    return inst;
}

+ (void)getForCurrentPackageAsyncWithSuccess:(void (^)(NSArray* /* WAStartupTask* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::StartupTask*>*>> unmarshalledReturn;
    auto _comInst = WAIStartupTaskStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentPackageAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::StartupTask*>*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::StartupTask*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::StartupTask*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WAStartupTask_create(result.Get()));
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

+ (void)getAsync:(NSString*)taskId success:(void (^)(WAStartupTask*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::StartupTask*>> unmarshalledReturn;
    auto _comInst = WAIStartupTaskStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAsync(nsStrToHstr(taskId).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::StartupTask*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::StartupTask*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::ApplicationModel::IStartupTask> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WAStartupTask>(result.Get()));
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

- (void)requestEnableAsyncWithSuccess:(void (^)(WAStartupTaskState))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::StartupTaskState>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IStartupTask>(self);
    THROW_NS_IF_FAILED(_comInst->RequestEnableAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::ApplicationModel::StartupTaskState>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::ApplicationModel::StartupTaskState>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::ApplicationModel::StartupTaskState result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WAStartupTaskState)result);
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

- (void)disable {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IStartupTask>(self);
    THROW_NS_IF_FAILED(_comInst->Disable());
}

- (WAStartupTaskState)state {
    ABI::Windows::ApplicationModel::StartupTaskState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IStartupTask>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WAStartupTaskState)unmarshalledReturn;
}

- (NSString*)taskId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IStartupTask>(self);
    THROW_NS_IF_FAILED(_comInst->get_TaskId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WAAppDisplayInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IAppDisplayInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IAppDisplayInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IAppDisplayInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSSRandomAccessStreamReference*)getLogo:(WFSize*)size {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamReference> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IAppDisplayInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetLogo(*[size internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSRandomAccessStreamReference>(unmarshalledReturn.Get());
}

@end

@implementation WAAppInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IAppInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IAppInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)appUserModelId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IAppInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AppUserModelId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAAppDisplayInfo*)displayInfo {
    ComPtr<ABI::Windows::ApplicationModel::IAppDisplayInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IAppInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAAppDisplayInfo>(unmarshalledReturn.Get());
}

- (NSString*)packageFamilyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IAppInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_PackageFamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WASuspendingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASuspendingOperation*)suspendingOperation {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuspendingOperation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASuspendingOperation>(unmarshalledReturn.Get());
}

@end

@implementation WALeavingBackgroundEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ILeavingBackgroundEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WAEnteredBackgroundEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IEnteredBackgroundEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WASuspendingDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WASuspendingOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WASuspendingDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::ISuspendingDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WASuspendingDeferral>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::ISuspendingOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

@implementation WAPackageStatus

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageStatus> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)verifyIsOK {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->VerifyIsOK(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)notAvailable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_NotAvailable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)packageOffline {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_PackageOffline(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)dataOffline {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataOffline(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)disabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_Disabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)needsRemediation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_NeedsRemediation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)licenseIssue {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_LicenseIssue(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)modified {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_Modified(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)tampered {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tampered(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)dependencyIssue {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_DependencyIssue(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)servicing {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_Servicing(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)deploymentInProgress {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatus>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeploymentInProgress(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WAPackageId

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageId> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WAPackageVersion*)Version {
    ABI::Windows::ApplicationModel::PackageVersion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Version(&unmarshalledReturn));
    return WAPackageVersion_create(unmarshalledReturn);
}

- (WSProcessorArchitecture)architecture {
    ABI::Windows::System::ProcessorArchitecture unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Architecture(&unmarshalledReturn));
    return (WSProcessorArchitecture)unmarshalledReturn;
}

- (NSString*)resourceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResourceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)publisher {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_Publisher(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)publisherId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublisherId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)fullName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_FullName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)familyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageId>(self);
    THROW_NS_IF_FAILED(_comInst->get_FamilyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)productId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageIdWithMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProductId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)author {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageIdWithMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_Author(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WAPackage

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::IPackageStatics> WAIPackageStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::IPackageStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.Package").Get(), &inst));
    return inst;
}

+ (WAPackage*)current {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = WAIPackageStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (WAPackageId*)id {
    ComPtr<ABI::Windows::ApplicationModel::IPackageId> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackageId>(unmarshalledReturn.Get());
}

- (WSStorageFolder*)installedLocation {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstalledLocation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

- (BOOL)isFramework {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFramework(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WAPackage* */)dependencies {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Package*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dependencies(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAPackage_create(unmarshalledReturn.Get());
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)publisherDisplayName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PublisherDisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)Description {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Description(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFUri*)logo {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (BOOL)isResourcePackage {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsResourcePackage(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isBundle {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBundle(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isDevelopmentMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage2>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDevelopmentMode(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WAPackageStatus*)status {
    ComPtr<ABI::Windows::ApplicationModel::IPackageStatus> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackageStatus>(unmarshalledReturn.Get());
}

- (WFDateTime*)installedDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage3>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstalledDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (void)getAppListEntriesAsyncWithSuccess:(void (^)(NSArray* /* WACAppListEntry* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry*>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage3>(self);
    THROW_NS_IF_FAILED(_comInst->GetAppListEntriesAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry*>*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WACAppListEntry_create(result.Get()));
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

- (WFDateTime*)installDate {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageWithMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->get_InstallDate(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (NSString*)getThumbnailToken {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageWithMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->GetThumbnailToken(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)launch:(NSString*)parameters {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageWithMetadata>(self);
    THROW_NS_IF_FAILED(_comInst->Launch(nsStrToHstr(parameters).Get()));
}

- (WAPackageSignatureKind)signatureKind {
    ABI::Windows::ApplicationModel::PackageSignatureKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage4>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignatureKind(&unmarshalledReturn));
    return (WAPackageSignatureKind)unmarshalledReturn;
}

- (BOOL)isOptional {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage4>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOptional(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)verifyContentIntegrityAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackage4>(self);
    THROW_NS_IF_FAILED(_comInst->VerifyContentIntegrityAsync(&unmarshalledReturn));

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

@implementation WAPackageStagingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageStagingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStagingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStagingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (double)progress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStagingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isComplete {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStagingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsComplete(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStagingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WAPackageInstallingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageInstallingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageInstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageInstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (double)progress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageInstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isComplete {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageInstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsComplete(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageInstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WAPackageUpdatingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WAPackage*)sourcePackage {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourcePackage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (WAPackage*)targetPackage {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetPackage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (double)progress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isComplete {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsComplete(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUpdatingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WAPackageUninstallingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)activityId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivityId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

- (double)progress {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Progress(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)isComplete {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsComplete(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageUninstallingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

@end

@implementation WAPackageStatusChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageStatusChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAPackage*)package {
    ComPtr<ABI::Windows::ApplicationModel::IPackage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageStatusChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Package(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackage>(unmarshalledReturn.Get());
}

@end

@implementation WAPackageCatalog

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::IPackageCatalog> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::IPackageCatalogStatics> WAIPackageCatalogStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::IPackageCatalogStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.PackageCatalog").Get(), &inst));
    return inst;
}

+ (WAPackageCatalog*)openForCurrentPackage {
    ComPtr<ABI::Windows::ApplicationModel::IPackageCatalog> unmarshalledReturn;
    auto _comInst = WAIPackageCatalogStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenForCurrentPackage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackageCatalog>(unmarshalledReturn.Get());
}

+ (WAPackageCatalog*)openForCurrentUser {
    ComPtr<ABI::Windows::ApplicationModel::IPackageCatalog> unmarshalledReturn;
    auto _comInst = WAIPackageCatalogStatics_inst();
    THROW_NS_IF_FAILED(_comInst->OpenForCurrentUser(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WAPackageCatalog>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addPackageStagingEvent:(void (^)(WAPackageCatalog*, WAPackageStagingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageStaging(
        Make<ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStagingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageStagingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageStaging(token));
}

- (EventRegistrationToken)addPackageInstallingEvent:(void (^)(WAPackageCatalog*, WAPackageInstallingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageInstalling(
        Make<ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageInstallingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageInstallingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageInstalling(token));
}

- (EventRegistrationToken)addPackageUpdatingEvent:(void (^)(WAPackageCatalog*, WAPackageUpdatingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageUpdating(
        Make<ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUpdatingEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageUpdatingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageUpdating(token));
}

- (EventRegistrationToken)addPackageUninstallingEvent:(void (^)(WAPackageCatalog*, WAPackageUninstallingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageUninstalling(
        Make<ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageUninstallingEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageUninstallingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageUninstalling(token));
}

- (EventRegistrationToken)addPackageStatusChangedEvent:(void (^)(WAPackageCatalog*, WAPackageStatusChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->add_PackageStatusChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_PackageCatalog_Windows_ApplicationModel_PackageStatusChangedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removePackageStatusChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::IPackageCatalog>(self);
    THROW_NS_IF_FAILED(_comInst->remove_PackageStatusChanged(token));
}

@end

@implementation WADesignMode

ComPtr<ABI::Windows::ApplicationModel::IDesignModeStatics> WAIDesignModeStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::IDesignModeStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.DesignMode").Get(), &inst));
    return inst;
}

+ (BOOL)designModeEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WAIDesignModeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DesignModeEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WACameraApplicationManager

ComPtr<ABI::Windows::ApplicationModel::ICameraApplicationManagerStatics> WAICameraApplicationManagerStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::ICameraApplicationManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.ApplicationModel.CameraApplicationManager").Get(),
                                                       &inst));
    return inst;
}

+ (void)showInstalledApplicationsUI {
    auto _comInst = WAICameraApplicationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowInstalledApplicationsUI());
}

@end

@implementation WAPackageVersion {
    ABI::Windows::ApplicationModel::PackageVersion structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::ApplicationModel::PackageVersion)s {
    WAPackageVersion* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::ApplicationModel::PackageVersion*)internalStruct {
    return &structVal;
}
- (unsigned short)major {
    return structVal.Major;
}
- (void)setMajor:(unsigned short)val {
    structVal.Major = val;
}
- (unsigned short)minor {
    return structVal.Minor;
}
- (void)setMinor:(unsigned short)val {
    structVal.Minor = val;
}
- (unsigned short)build {
    return structVal.Build;
}
- (void)setBuild:(unsigned short)val {
    structVal.Build = val;
}
- (unsigned short)revision {
    return structVal.Revision;
}
- (void)setRevision:(unsigned short)val {
    structVal.Revision = val;
}
@end
id RTProxiedNSArray_WACAppListEntry_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::Core::IAppListEntry*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Core::AppListEntry*>,
                                                    WACAppListEntry,
                                                    ABI::Windows::ApplicationModel::Core::AppListEntry*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAPackage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::Package*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::IPackage*,
                                                    IVectorView<ABI::Windows::ApplicationModel::Package*>,
                                                    WAPackage,
                                                    ABI::Windows::ApplicationModel::Package*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WAStartupTask_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::StartupTask*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::IStartupTask*,
                                                    IVectorView<ABI::Windows::ApplicationModel::StartupTask*>,
                                                    WAStartupTask,
                                                    ABI::Windows::ApplicationModel::StartupTask*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
