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

// WindowsSecurityEnterpriseData.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.EnterpriseData.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityEnterpriseData.h"
#include "WindowsSecurityEnterpriseData_priv.h"

@implementation WSEFileProtectionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSEFileProtectionStatus)status {
    ABI::Windows::Security::EnterpriseData::FileProtectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IFileProtectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSEFileProtectionStatus)unmarshalledReturn;
}

- (BOOL)isRoamable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IFileProtectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsRoamable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)identity {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IFileProtectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Identity(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSEProtectedContainerExportResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContainerExportResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSEProtectedImportExportStatus)status {
    ABI::Windows::Security::EnterpriseData::ProtectedImportExportStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedContainerExportResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSEProtectedImportExportStatus)unmarshalledReturn;
}

- (WSStorageFile*)file {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedContainerExportResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_File(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

@end

@implementation WSEProtectedContainerImportResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContainerImportResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSEProtectedImportExportStatus)status {
    ABI::Windows::Security::EnterpriseData::ProtectedImportExportStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedContainerImportResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSEProtectedImportExportStatus)unmarshalledReturn;
}

- (WSStorageFile*)file {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedContainerImportResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_File(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

@end

@implementation WSEProtectedFileCreateResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedFileCreateResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSStorageFile*)file {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedFileCreateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_File(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStream>*)stream {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedFileCreateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stream(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (WSEFileProtectionInfo*)protectionInfo {
    ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedFileCreateResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSEFileProtectionInfo>(unmarshalledReturn.Get());
}

@end

@implementation WSEBufferProtectUnprotectResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IBufferProtectUnprotectResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIBuffer>*)buffer {
    ComPtr<ABI::Windows::Storage::Streams::IBuffer> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IBufferProtectUnprotectResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Buffer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIBuffer>(unmarshalledReturn.Get());
}

- (WSEDataProtectionInfo*)protectionInfo {
    ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IBufferProtectUnprotectResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProtectionInfo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSEDataProtectionInfo>(unmarshalledReturn.Get());
}

@end

@implementation WSEDataProtectionInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSEDataProtectionStatus)status {
    ABI::Windows::Security::EnterpriseData::DataProtectionStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WSEDataProtectionStatus)unmarshalledReturn;
}

- (NSString*)identity {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Identity(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSEProtectionPolicyAuditInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfoFactory> WSEIProtectionPolicyAuditInfoFactory_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfoFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.ProtectionPolicyAuditInfo").Get(), &inst));
    return inst;
}

+ (WSEProtectionPolicyAuditInfo*)make:(WSEProtectionPolicyAuditAction)action
                      dataDescription:(NSString*)dataDescription
                    sourceDescription:(NSString*)sourceDescription
                    targetDescription:(NSString*)targetDescription {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyAuditInfoFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::Security::EnterpriseData::ProtectionPolicyAuditAction)action,
                                        nsStrToHstr(dataDescription).Get(),
                                        nsStrToHstr(sourceDescription).Get(),
                                        nsStrToHstr(targetDescription).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSEProtectionPolicyAuditInfo>(unmarshalledReturn.Get()) retain];
}

+ (WSEProtectionPolicyAuditInfo*)makeWithActionAndDataDescription:(WSEProtectionPolicyAuditAction)action
                                                  dataDescription:(NSString*)dataDescription {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo> unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyAuditInfoFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithActionAndDataDescription((ABI::Windows::Security::EnterpriseData::ProtectionPolicyAuditAction)action,
                                                     nsStrToHstr(dataDescription).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSEProtectionPolicyAuditInfo>(unmarshalledReturn.Get()) retain];
}

- (void)setAction:(WSEProtectionPolicyAuditAction)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_Action((ABI::Windows::Security::EnterpriseData::ProtectionPolicyAuditAction)value));
}

- (WSEProtectionPolicyAuditAction)action {
    ABI::Windows::Security::EnterpriseData::ProtectionPolicyAuditAction unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Action(&unmarshalledReturn));
    return (WSEProtectionPolicyAuditAction)unmarshalledReturn;
}

- (void)setDataDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_DataDescription(nsStrToHstr(value).Get()));
}

- (NSString*)dataDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DataDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSourceDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_SourceDescription(nsStrToHstr(value).Get()));
}

- (NSString*)sourceDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTargetDescription:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->put_TargetDescription(nsStrToHstr(value).Get()));
}

- (NSString*)targetDescription {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TargetDescription(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSEThreadNetworkContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IThreadNetworkContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSEProtectionPolicyManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics> WSEIProtectionPolicyManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.ProtectionPolicyManager").Get(), &inst));
    return inst;
}

+ (BOOL)isIdentityManaged:(NSString*)identity {
    boolean unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->IsIdentityManaged(nsStrToHstr(identity).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)tryApplyProcessUIPolicy:(NSString*)identity {
    boolean unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->TryApplyProcessUIPolicy(nsStrToHstr(identity).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)clearProcessUIPolicy {
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ClearProcessUIPolicy());
}

+ (WSEThreadNetworkContext*)createCurrentThreadNetworkContext:(NSString*)identity {
    ComPtr<ABI::Windows::Security::EnterpriseData::IThreadNetworkContext> unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCurrentThreadNetworkContext(nsStrToHstr(identity).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSEThreadNetworkContext>(unmarshalledReturn.Get());
}

+ (void)getPrimaryManagedIdentityForNetworkEndpointAsync:(WNHostName*)endpointHost
                                                 success:(void (^)(NSString*))success
                                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<HSTRING>> unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetPrimaryManagedIdentityForNetworkEndpointAsync(_getRtInterface<ABI::Windows::Networking::IHostName>(endpointHost).Get(),
                                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<HSTRING>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<HSTRING>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        HSTRING result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc(hstrToNSStr(result));
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

+ (void)revokeContent:(NSString*)identity {
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->RevokeContent(nsStrToHstr(identity).Get()));
}

+ (WSEProtectionPolicyManager*)getForCurrentView {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManager> unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSEProtectionPolicyManager>(unmarshalledReturn.Get());
}

+ (EventRegistrationToken)addProtectedAccessSuspendingEvent:(void (^)(RTObject*, WSEProtectedAccessSuspendingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_ProtectedAccessSuspending(
        Make<EventHandler_Windows_Security_EnterpriseData_ProtectedAccessSuspendingEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeProtectedAccessSuspendingEvent:(EventRegistrationToken)token {
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ProtectedAccessSuspending(token));
}

+ (EventRegistrationToken)addProtectedAccessResumedEvent:(void (^)(RTObject*, WSEProtectedAccessResumedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_ProtectedAccessResumed(
        Make<EventHandler_Windows_Security_EnterpriseData_ProtectedAccessResumedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeProtectedAccessResumedEvent:(EventRegistrationToken)token {
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ProtectedAccessResumed(token));
}

+ (EventRegistrationToken)addProtectedContentRevokedEvent:(void (^)(RTObject*, WSEProtectedContentRevokedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_ProtectedContentRevoked(
        Make<EventHandler_Windows_Security_EnterpriseData_ProtectedContentRevokedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeProtectedContentRevokedEvent:(EventRegistrationToken)token {
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ProtectedContentRevoked(token));
}

+ (WSEProtectionPolicyEvaluationResult)checkAccess:(NSString*)sourceIdentity targetIdentity:(NSString*)targetIdentity {
    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CheckAccess(nsStrToHstr(sourceIdentity).Get(), nsStrToHstr(targetIdentity).Get(), &unmarshalledReturn));
    return (WSEProtectionPolicyEvaluationResult)unmarshalledReturn;
}

+ (void)requestAccessAsync:(NSString*)sourceIdentity
            targetIdentity:(NSString*)targetIdentity
                   success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->RequestAccessAsync(nsStrToHstr(sourceIdentity).Get(), nsStrToHstr(targetIdentity).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics2> WSEIProtectionPolicyManagerStatics2_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.ProtectionPolicyManager").Get(), &inst));
    return inst;
}

+ (BOOL)hasContentBeenRevokedSince:(NSString*)identity since:(WFDateTime*)since {
    boolean unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->HasContentBeenRevokedSince(nsStrToHstr(identity).Get(), *[since internalStruct], &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (WSEProtectionPolicyEvaluationResult)checkAccessForApp:(NSString*)sourceIdentity appPackageFamilyName:(NSString*)appPackageFamilyName {
    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->CheckAccessForApp(nsStrToHstr(sourceIdentity).Get(), nsStrToHstr(appPackageFamilyName).Get(), &unmarshalledReturn));
    return (WSEProtectionPolicyEvaluationResult)unmarshalledReturn;
}

+ (void)requestAccessForAppAsync:(NSString*)sourceIdentity
            appPackageFamilyName:(NSString*)appPackageFamilyName
                         success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessForAppAsync(nsStrToHstr(sourceIdentity).Get(),
                                                          nsStrToHstr(appPackageFamilyName).Get(),
                                                          &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

+ (WSEEnforcementLevel)getEnforcementLevel:(NSString*)identity {
    ABI::Windows::Security::EnterpriseData::EnforcementLevel unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetEnforcementLevel(nsStrToHstr(identity).Get(), &unmarshalledReturn));
    return (WSEEnforcementLevel)unmarshalledReturn;
}

+ (BOOL)isUserDecryptionAllowed:(NSString*)identity {
    boolean unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->IsUserDecryptionAllowed(nsStrToHstr(identity).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (BOOL)isProtectionUnderLockRequired:(NSString*)identity {
    boolean unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->IsProtectionUnderLockRequired(nsStrToHstr(identity).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (EventRegistrationToken)addPolicyChangedEvent:(void (^)(RTObject*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->add_PolicyChanged(Make<EventHandler_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removePolicyChangedEvent:(EventRegistrationToken)token {
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_PolicyChanged(token));
}

+ (BOOL)isProtectionEnabled {
    boolean unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsProtectionEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics3> WSEIProtectionPolicyManagerStatics3_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManagerStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.ProtectionPolicyManager").Get(), &inst));
    return inst;
}

+ (void)requestAccessWithAuditingInfoAsync:(NSString*)sourceIdentity
                            targetIdentity:(NSString*)targetIdentity
                                 auditInfo:(WSEProtectionPolicyAuditInfo*)auditInfo
                                   success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessWithAuditingInfoAsync(
        nsStrToHstr(sourceIdentity).Get(),
        nsStrToHstr(targetIdentity).Get(),
        _getRtInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(auditInfo).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

+ (void)requestAccessWithMessageAsync:(NSString*)sourceIdentity
                       targetIdentity:(NSString*)targetIdentity
                            auditInfo:(WSEProtectionPolicyAuditInfo*)auditInfo
                       messageFromApp:(NSString*)messageFromApp
                              success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessWithMessageAsync(
        nsStrToHstr(sourceIdentity).Get(),
        nsStrToHstr(targetIdentity).Get(),
        _getRtInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(auditInfo).Get(),
        nsStrToHstr(messageFromApp).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

+ (void)requestAccessForAppWithAuditingInfoAsync:(NSString*)sourceIdentity
                            appPackageFamilyName:(NSString*)appPackageFamilyName
                                       auditInfo:(WSEProtectionPolicyAuditInfo*)auditInfo
                                         success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessForAppWithAuditingInfoAsync(
        nsStrToHstr(sourceIdentity).Get(),
        nsStrToHstr(appPackageFamilyName).Get(),
        _getRtInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(auditInfo).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

+ (void)requestAccessForAppWithMessageAsync:(NSString*)sourceIdentity
                       appPackageFamilyName:(NSString*)appPackageFamilyName
                                  auditInfo:(WSEProtectionPolicyAuditInfo*)auditInfo
                             messageFromApp:(NSString*)messageFromApp
                                    success:(void (^)(WSEProtectionPolicyEvaluationResult))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>>
        unmarshalledReturn;
    auto _comInst = WSEIProtectionPolicyManagerStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->RequestAccessForAppWithMessageAsync(
        nsStrToHstr(sourceIdentity).Get(),
        nsStrToHstr(appPackageFamilyName).Get(),
        _getRtInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(auditInfo).Get(),
        nsStrToHstr(messageFromApp).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::ProtectionPolicyEvaluationResult result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEProtectionPolicyEvaluationResult)result);
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

+ (void)logAuditEvent:(NSString*)sourceIdentity
       targetIdentity:(NSString*)targetIdentity
            auditInfo:(WSEProtectionPolicyAuditInfo*)auditInfo {
    auto _comInst = WSEIProtectionPolicyManagerStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->LogAuditEvent(nsStrToHstr(sourceIdentity).Get(),
                                nsStrToHstr(targetIdentity).Get(),
                                _getRtInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyAuditInfo>(auditInfo).Get()));
}

- (void)setIdentity:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManager>(self);
    THROW_NS_IF_FAILED(_comInst->put_Identity(nsStrToHstr(value).Get()));
}

- (NSString*)identity {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_Identity(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setShowEnterpriseIndicator:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManager2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShowEnterpriseIndicator((boolean)value));
}

- (BOOL)showEnterpriseIndicator {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectionPolicyManager2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShowEnterpriseIndicator(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSEProtectedAccessSuspendingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* NSString * */)identities {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Identities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WSEProtectedAccessResumedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedAccessResumedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* NSString * */)identities {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedAccessResumedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Identities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSEProtectedContentRevokedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContentRevokedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* NSString * */)identities {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::EnterpriseData::IProtectedContentRevokedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Identities(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WSEFileRevocationManager

ComPtr<ABI::Windows::Security::EnterpriseData::IFileRevocationManagerStatics> WSEIFileRevocationManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IFileRevocationManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.FileRevocationManager").Get(), &inst));
    return inst;
}

+ (void)protectAsync:(RTObject<WSIStorageItem>*)storageItem
    enterpriseIdentity:(NSString*)enterpriseIdentity
               success:(void (^)(WSEFileProtectionStatus))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionStatus>> unmarshalledReturn;
    auto _comInst = WSEIFileRevocationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ProtectAsync(_getRtInterface<ABI::Windows::Storage::IStorageItem>(storageItem).Get(),
                                              nsStrToHstr(enterpriseIdentity).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::FileProtectionStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::FileProtectionStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEFileProtectionStatus)result);
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

+ (void)copyProtectionAsync:(RTObject<WSIStorageItem>*)sourceStorageItem
          targetStorageItem:(RTObject<WSIStorageItem>*)targetStorageItem
                    success:(void (^)(BOOL))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSEIFileRevocationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CopyProtectionAsync(_getRtInterface<ABI::Windows::Storage::IStorageItem>(sourceStorageItem).Get(),
                                                     _getRtInterface<ABI::Windows::Storage::IStorageItem>(targetStorageItem).Get(),
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

+ (void)revoke:(NSString*)enterpriseIdentity {
    auto _comInst = WSEIFileRevocationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->Revoke(nsStrToHstr(enterpriseIdentity).Get()));
}

+ (void)getStatusAsync:(RTObject<WSIStorageItem>*)storageItem
               success:(void (^)(WSEFileProtectionStatus))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionStatus>> unmarshalledReturn;
    auto _comInst = WSEIFileRevocationManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStatusAsync(_getRtInterface<ABI::Windows::Storage::IStorageItem>(storageItem).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::FileProtectionStatus>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionStatus>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Security::EnterpriseData::FileProtectionStatus result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WSEFileProtectionStatus)result);
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

@implementation WSEFileProtectionManager

ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionManagerStatics> WSEIFileProtectionManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.FileProtectionManager").Get(), &inst));
    return inst;
}

+ (void)protectAsync:(RTObject<WSIStorageItem>*)target
            identity:(NSString*)identity
             success:(void (^)(WSEFileProtectionInfo*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionInfo*>> unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ProtectAsync(_getRtInterface<ABI::Windows::Storage::IStorageItem>(target).Get(),
                                              nsStrToHstr(identity).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::FileProtectionInfo*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionInfo*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionInfo> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEFileProtectionInfo>(result.Get()));
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

+ (void)copyProtectionAsync:(RTObject<WSIStorageItem>*)source
                     target:(RTObject<WSIStorageItem>*)target
                    success:(void (^)(BOOL))success
                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CopyProtectionAsync(_getRtInterface<ABI::Windows::Storage::IStorageItem>(source).Get(),
                                                     _getRtInterface<ABI::Windows::Storage::IStorageItem>(target).Get(),
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

+ (void)getProtectionInfoAsync:(RTObject<WSIStorageItem>*)source
                       success:(void (^)(WSEFileProtectionInfo*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionInfo*>> unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetProtectionInfoAsync(_getRtInterface<ABI::Windows::Storage::IStorageItem>(source).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::FileProtectionInfo*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::FileProtectionInfo*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionInfo> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEFileProtectionInfo>(result.Get()));
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

+ (void)saveFileAsContainerAsync:(RTObject<WSIStorageFile>*)protectedFile
                         success:(void (^)(WSEProtectedContainerExportResult*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerExportResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SaveFileAsContainerAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(protectedFile).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectedContainerExportResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerExportResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContainerExportResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEProtectedContainerExportResult>(result.Get()));
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

+ (void)loadFileFromContainerAsync:(RTObject<WSIStorageFile>*)containerFile
                           success:(void (^)(WSEProtectedContainerImportResult*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->LoadFileFromContainerAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(containerFile).Get(),
                                                            &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContainerImportResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEProtectedContainerImportResult>(result.Get()));
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

+ (void)loadFileFromContainerWithTargetAsync:(RTObject<WSIStorageFile>*)containerFile
                                      target:(RTObject<WSIStorageItem>*)target
                                     success:(void (^)(WSEProtectedContainerImportResult*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->LoadFileFromContainerWithTargetAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(containerFile).Get(),
                                                       _getRtInterface<ABI::Windows::Storage::IStorageItem>(target).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContainerImportResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEProtectedContainerImportResult>(result.Get()));
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

+ (void)createProtectedAndOpenAsync:(RTObject<WSIStorageFolder>*)parentFolder
                        desiredName:(NSString*)desiredName
                           identity:(NSString*)identity
                    collisionOption:(WSCreationCollisionOption)collisionOption
                            success:(void (^)(WSEProtectedFileCreateResult*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedFileCreateResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateProtectedAndOpenAsync(_getRtInterface<ABI::Windows::Storage::IStorageFolder>(parentFolder).Get(),
                                                             nsStrToHstr(desiredName).Get(),
                                                             nsStrToHstr(identity).Get(),
                                                             (ABI::Windows::Storage::CreationCollisionOption)collisionOption,
                                                             &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectedFileCreateResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedFileCreateResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedFileCreateResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEProtectedFileCreateResult>(result.Get()));
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

ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionManagerStatics2> WSEIFileProtectionManagerStatics2_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IFileProtectionManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.FileProtectionManager").Get(), &inst));
    return inst;
}

+ (void)isContainerAsync:(RTObject<WSIStorageFile>*)file success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->IsContainerAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

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

+ (void)loadFileFromContainerWithTargetAndNameCollisionOptionAsync:(RTObject<WSIStorageFile>*)containerFile
                                                            target:(RTObject<WSIStorageItem>*)target
                                                   collisionOption:(WSNameCollisionOption)collisionOption
                                                           success:(void (^)(WSEProtectedContainerImportResult*))success
                                                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->LoadFileFromContainerWithTargetAndNameCollisionOptionAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(containerFile).Get(),
        _getRtInterface<ABI::Windows::Storage::IStorageItem>(target).Get(),
        (ABI::Windows::Storage::NameCollisionOption)collisionOption,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerImportResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContainerImportResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEProtectedContainerImportResult>(result.Get()));
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

+ (void)saveFileAsContainerWithSharingAsync:(RTObject<WSIStorageFile>*)protectedFile
                       sharedWithIdentities:(id<NSFastEnumeration> /* NSString * */)sharedWithIdentities
                                    success:(void (^)(WSEProtectedContainerExportResult*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerExportResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIFileProtectionManagerStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->SaveFileAsContainerWithSharingAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(protectedFile).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(sharedWithIdentities).Get()),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::ProtectedContainerExportResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::ProtectedContainerExportResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IProtectedContainerExportResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEProtectedContainerExportResult>(result.Get()));
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

@implementation WSEDataProtectionManager

ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionManagerStatics> WSEIDataProtectionManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.EnterpriseData.DataProtectionManager").Get(), &inst));
    return inst;
}

+ (void)protectAsync:(RTObject<WSSIBuffer>*)data
            identity:(NSString*)identity
             success:(void (^)(WSEBufferProtectUnprotectResult*))success
             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::BufferProtectUnprotectResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIDataProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ProtectAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(),
                                              nsStrToHstr(identity).Get(),
                                              &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::BufferProtectUnprotectResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::BufferProtectUnprotectResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IBufferProtectUnprotectResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEBufferProtectUnprotectResult>(result.Get()));
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

+ (void)unprotectAsync:(RTObject<WSSIBuffer>*)data
               success:(void (^)(WSEBufferProtectUnprotectResult*))success
               failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::BufferProtectUnprotectResult*>>
        unmarshalledReturn;
    auto _comInst = WSEIDataProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UnprotectAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(data).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::BufferProtectUnprotectResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::BufferProtectUnprotectResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IBufferProtectUnprotectResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEBufferProtectUnprotectResult>(result.Get()));
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

+ (void)protectStreamAsync:(RTObject<WSSIInputStream>*)unprotectedStream
                  identity:(NSString*)identity
           protectedStream:(RTObject<WSSIOutputStream>*)protectedStream
                   success:(void (^)(WSEDataProtectionInfo*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>> unmarshalledReturn;
    auto _comInst = WSEIDataProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ProtectStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(unprotectedStream).Get(),
                                                    nsStrToHstr(identity).Get(),
                                                    _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(protectedStream).Get(),
                                                    &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEDataProtectionInfo>(result.Get()));
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

+ (void)unprotectStreamAsync:(RTObject<WSSIInputStream>*)protectedStream
           unprotectedStream:(RTObject<WSSIOutputStream>*)unprotectedStream
                     success:(void (^)(WSEDataProtectionInfo*))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>> unmarshalledReturn;
    auto _comInst = WSEIDataProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->UnprotectStreamAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(protectedStream).Get(),
                                       _getRtInterface<ABI::Windows::Storage::Streams::IOutputStream>(unprotectedStream).Get(),
                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEDataProtectionInfo>(result.Get()));
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

+ (void)getProtectionInfoAsync:(RTObject<WSSIBuffer>*)protectedData
                       success:(void (^)(WSEDataProtectionInfo*))success
                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>> unmarshalledReturn;
    auto _comInst = WSEIDataProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetProtectionInfoAsync(_getRtInterface<ABI::Windows::Storage::Streams::IBuffer>(protectedData).Get(),
                                                        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEDataProtectionInfo>(result.Get()));
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

+ (void)getStreamProtectionInfoAsync:(RTObject<WSSIInputStream>*)protectedStream
                             success:(void (^)(WSEDataProtectionInfo*))success
                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>> unmarshalledReturn;
    auto _comInst = WSEIDataProtectionManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetStreamProtectionInfoAsync(_getRtInterface<ABI::Windows::Storage::Streams::IInputStream>(protectedStream).Get(),
                                               &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::EnterpriseData::DataProtectionInfo*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::EnterpriseData::IDataProtectionInfo> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSEDataProtectionInfo>(result.Get()));
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

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
