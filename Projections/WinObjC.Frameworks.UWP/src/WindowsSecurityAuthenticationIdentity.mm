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

// WindowsSecurityAuthenticationIdentity.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Authentication.Identity.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityAuthenticationIdentity.h"
#include "WindowsSecurityAuthenticationIdentity_priv.h"

@implementation WSAIEnterpriseKeyCredentialRegistrationInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)tenantId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TenantId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)tenantName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_TenantName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)subject {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Subject(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)keyId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)keyName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSAIEnterpriseKeyCredentialRegistrationManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManagerStatics>
WSAIIEnterpriseKeyCredentialRegistrationManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Identity.EnterpriseKeyCredentialRegistrationManager").Get(), &inst));
    return inst;
}

+ (WSAIEnterpriseKeyCredentialRegistrationManager*)current {
    ComPtr<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager> unmarshalledReturn;
    auto _comInst = WSAIIEnterpriseKeyCredentialRegistrationManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Current(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAIEnterpriseKeyCredentialRegistrationManager>(unmarshalledReturn.Get());
}

- (void)getRegistrationsAsyncWithSuccess:(void (^)(NSArray* /* WSAIEnterpriseKeyCredentialRegistrationInfo* */))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo*>*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetRegistrationsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<
                                         ABI::Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo*>*>,
                                     FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<
                        IVectorView<ABI::Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo*>*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSAIEnterpriseKeyCredentialRegistrationInfo_create(result.Get()));
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

id RTProxiedNSArray_WSAIEnterpriseKeyCredentialRegistrationInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo*>,
                        RTArrayObj<ABI::Windows::Security::Authentication::Identity::IEnterpriseKeyCredentialRegistrationInfo*,
                                   IVectorView<ABI::Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo*>,
                                   WSAIEnterpriseKeyCredentialRegistrationInfo,
                                   ABI::Windows::Security::Authentication::Identity::EnterpriseKeyCredentialRegistrationInfo*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
