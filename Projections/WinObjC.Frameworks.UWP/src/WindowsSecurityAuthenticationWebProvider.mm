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

// WindowsSecurityAuthenticationWebProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Authentication.Web.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityAuthenticationWebProvider.h"
#include "WindowsSecurityAuthenticationWebProvider_priv.h"

@implementation WSAWPIWebAccountProviderOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

@end

@implementation WSAWPIWebAccountProviderBaseReportOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPIWebAccountProviderUIReportOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)reportUserCanceled {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportUserCanceled());
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPIWebAccountProviderSilentReportOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)reportUserInteractionRequired {
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportUserInteractionRequired());
}

- (void)reportUserInteractionRequiredWithError:(WSAWCWebProviderError*)value {
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportUserInteractionRequiredWithError(
        _getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPIWebAccountProviderTokenOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAWPWebProviderTokenRequest*)providerRequest {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWPWebProviderTokenRequest>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WSAWPWebProviderTokenResponse* */)providerResponses {
    ComPtr<IVector<ABI::Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderResponses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSAWPWebProviderTokenResponse_create(unmarshalledReturn.Get());
}

- (void)setCacheExpirationTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CacheExpirationTime(*[value internalStruct]));
}

- (WFDateTime*)cacheExpirationTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheExpirationTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

@end

@implementation WSAWPIWebAccountProviderTokenObjects

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSAWPIWebAccountProviderOperation>*)operation {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects>(self);
    THROW_NS_IF_FAILED(_comInst->get_Operation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWPIWebAccountProviderOperation>(unmarshalledReturn.Get());
}

@end

@implementation WSAWPWebProviderTokenRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAWCWebTokenRequest*)clientRequest {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWCWebTokenRequest>(unmarshalledReturn.Get());
}

- (NSArray* /* WSCWebAccount* */)webAccounts {
    ComPtr<IVectorView<ABI::Windows::Security::Credentials::WebAccount*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccounts(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSCWebAccount_create(unmarshalledReturn.Get());
}

- (WSAWPWebAccountSelectionOptions)webAccountSelectionOptions {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountSelectionOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccountSelectionOptions(&unmarshalledReturn));
    return (WSAWPWebAccountSelectionOptions)unmarshalledReturn;
}

- (WFUri*)applicationCallbackUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationCallbackUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (void)getApplicationTokenBindingKeyAsync:(WSAWTokenBindingKeyType)keyType
                                    target:(WFUri*)target
                                   success:(void (^)(WSCCCryptographicKey*))success
                                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Core::CryptographicKey*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetApplicationTokenBindingKeyAsync((ABI::Windows::Security::Authentication::Web::TokenBindingKeyType)keyType,
                                                     _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(target).Get(),
                                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Cryptography::Core::CryptographicKey*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Cryptography::Core::CryptographicKey*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Security::Cryptography::Core::ICryptographicKey> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSCCCryptographicKey>(result.Get()));
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

- (void)getApplicationTokenBindingKeyIdAsync:(WSAWTokenBindingKeyType)keyType
                                      target:(WFUri*)target
                                     success:(void (^)(RTObject<WSSIBuffer>*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest2>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetApplicationTokenBindingKeyIdAsync((ABI::Windows::Security::Authentication::Web::TokenBindingKeyType)keyType,
                                                       _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(target).Get(),
                                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Storage::Streams::IBuffer*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Storage::Streams::IBuffer*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Storage::Streams::IBuffer> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WSSIBuffer>(result.Get()));
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

@implementation WSAWPWebProviderTokenResponse

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponseFactory>
WSAWPIWebProviderTokenResponseFactory_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponseFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Provider.WebProviderTokenResponse").Get(), &inst));
    return inst;
}

+ (WSAWPWebProviderTokenResponse*)make:(WSAWCWebTokenResponse*)webTokenResponse {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse> unmarshalledReturn;
    auto _comInst = WSAWPIWebProviderTokenResponseFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse>(webTokenResponse).Get(),
                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWPWebProviderTokenResponse>(unmarshalledReturn.Get()) retain];
}

- (WSAWCWebTokenResponse*)clientResponse {
    ComPtr<ABI::Windows::Security::Authentication::Web::Core::IWebTokenResponse> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientResponse(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWCWebTokenResponse>(unmarshalledReturn.Get());
}

@end

@implementation WSAWPWebAccountClientView

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientViewFactory>
WSAWPIWebAccountClientViewFactory_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientViewFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Provider.WebAccountClientView").Get(), &inst));
    return inst;
}

+ (WSAWPWebAccountClientView*)make:(WSAWPWebAccountClientViewType)viewType applicationCallbackUri:(WFUri*)applicationCallbackUri {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountClientViewFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientViewType)viewType,
                                        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(applicationCallbackUri).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWPWebAccountClientView>(unmarshalledReturn.Get()) retain];
}

+ (WSAWPWebAccountClientView*)makeWithPairwiseId:(WSAWPWebAccountClientViewType)viewType
                          applicationCallbackUri:(WFUri*)applicationCallbackUri
                               accountPairwiseId:(NSString*)accountPairwiseId {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountClientViewFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithPairwiseId((ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientViewType)viewType,
                                       _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(applicationCallbackUri).Get(),
                                       nsStrToHstr(accountPairwiseId).Get(),
                                       unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAWPWebAccountClientView>(unmarshalledReturn.Get()) retain];
}

- (WFUri*)applicationCallbackUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationCallbackUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WSAWPWebAccountClientViewType)type {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientViewType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WSAWPWebAccountClientViewType)unmarshalledReturn;
}

- (NSString*)accountPairwiseId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountPairwiseId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSAWPWebAccountManager

ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics2> WSAWPIWebAccountManagerStatics2_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Provider.WebAccountManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)pullCookiesAsync:(NSString*)uriString callerPFN:(NSString*)callerPFN {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->PullCookiesAsync(nsStrToHstr(uriString).Get(), nsStrToHstr(callerPFN).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountScopeManagerStatics> WSAWPIWebAccountScopeManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountScopeManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Provider.WebAccountManager").Get(), &inst));
    return inst;
}

+ (void)addWebAccountWithScopeAsync:(NSString*)webAccountId
                 webAccountUserName:(NSString*)webAccountUserName
                              props:(NSDictionary* /* NSString *, NSString * */)props
                              scope:(WSAWPWebAccountScope)scope
                            success:(void (^)(WSCWebAccount*))success
                            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountScopeManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AddWebAccountWithScopeAsync(
        nsStrToHstr(webAccountId).Get(),
        nsStrToHstr(webAccountUserName).Get(),
        static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                             typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToMapView<NSString, HSTRING, NSString, HSTRING>(props).Get()),
        (ABI::Windows::Security::Authentication::Web::Provider::WebAccountScope)scope,
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccount*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Credentials::IWebAccount> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSCWebAccount>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)setScopeAsync:(WSCWebAccount*)webAccount scope:(WSAWPWebAccountScope)scope {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountScopeManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetScopeAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                               (ABI::Windows::Security::Authentication::Web::Provider::WebAccountScope)scope,
                                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (WSAWPWebAccountScope)getScope:(WSCWebAccount*)webAccount {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountScope unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountScopeManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetScope(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(), &unmarshalledReturn));
    return (WSAWPWebAccountScope)unmarshalledReturn;
}

ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountMapManagerStatics> WSAWPIWebAccountMapManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountMapManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Provider.WebAccountManager").Get(), &inst));
    return inst;
}

+ (void)addWebAccountWithScopeAndMapAsync:(NSString*)webAccountId
                       webAccountUserName:(NSString*)webAccountUserName
                                    props:(NSDictionary* /* NSString *, NSString * */)props
                                    scope:(WSAWPWebAccountScope)scope
                      perUserWebAccountId:(NSString*)perUserWebAccountId
                                  success:(void (^)(WSCWebAccount*))success
                                  failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountMapManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->AddWebAccountWithScopeAndMapAsync(
        nsStrToHstr(webAccountId).Get(),
        nsStrToHstr(webAccountUserName).Get(),
        static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                             typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToMapView<NSString, HSTRING, NSString, HSTRING>(props).Get()),
        (ABI::Windows::Security::Authentication::Web::Provider::WebAccountScope)scope,
        nsStrToHstr(perUserWebAccountId).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccount*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Credentials::IWebAccount> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSCWebAccount>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)setPerAppToPerUserAccountAsync:(WSCWebAccount*)perAppAccount
                                        perUserWebAccountId:(NSString*)perUserWebAccountId {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountMapManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetPerAppToPerUserAccountAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(perAppAccount).Get(),
                                                 nsStrToHstr(perUserWebAccountId).Get(),
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)getPerUserFromPerAppAccountAsync:(WSCWebAccount*)perAppAccount
                                 success:(void (^)(WSCWebAccount*))success
                                 failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountMapManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetPerUserFromPerAppAccountAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(perAppAccount).Get(),
                                                   &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccount*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Credentials::IWebAccount> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSCWebAccount>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)clearPerUserFromPerAppAccountAsync:(WSCWebAccount*)perAppAccount {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountMapManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ClearPerUserFromPerAppAccountAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(perAppAccount).Get(),
                                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics> WSAWPIWebAccountManagerStatics_inst() {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountManagerStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.Web.Provider.WebAccountManager").Get(), &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)updateWebAccountPropertiesAsync:(WSCWebAccount*)webAccount
                                          webAccountUserName:(NSString*)webAccountUserName
                                        additionalProperties:(NSDictionary* /* NSString *, NSString * */)additionalProperties {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->UpdateWebAccountPropertiesAsync(
        _getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
        nsStrToHstr(webAccountUserName).Get(),
        static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                             typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToMapView<NSString, HSTRING, NSString, HSTRING>(additionalProperties).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)addWebAccountAsync:(NSString*)webAccountId
        webAccountUserName:(NSString*)webAccountUserName
                     props:(NSDictionary* /* NSString *, NSString * */)props
                   success:(void (^)(WSCWebAccount*))success
                   failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->AddWebAccountAsync(nsStrToHstr(webAccountId).Get(),
                                     nsStrToHstr(webAccountUserName).Get(),
                                     static_cast<IMapView<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type,
                                                          typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToMapView<NSString, HSTRING, NSString, HSTRING>(props).Get()),
                                     &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Security::Credentials::WebAccount*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Security::Credentials::WebAccount*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Security::Credentials::IWebAccount> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WSCWebAccount>(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)deleteWebAccountAsync:(WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->DeleteWebAccountAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)findAllProviderWebAccountsAsyncWithSuccess:(void (^)(NSArray* /* WSCWebAccount* */))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Security::Credentials::WebAccount*>*>> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FindAllProviderWebAccountsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<IVectorView<ABI::Windows::Security::Credentials::WebAccount*>*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<IVectorView<ABI::Windows::Security::Credentials::WebAccount*>*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<IVectorView<ABI::Windows::Security::Credentials::WebAccount*>> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(RTProxiedNSArray_WSCWebAccount_create(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)pushCookiesAsync:(WFUri*)uri cookies:(NSArray* /* WWHHttpCookie* */)cookies {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->PushCookiesAsync(
        _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get(),
        static_cast<IVectorView<typename ABI::Windows::Foundation::Internal::GetLogicalType<
            ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Web::Http::HttpCookie*,
                                                              ABI::Windows::Web::Http::IHttpCookie*>>::type>*>(
            ConvertToVectorView<WWHHttpCookie,
                                ABI::Windows::Foundation::Internal::AggregateType<ABI::Windows::Web::Http::HttpCookie*,
                                                                                  ABI::Windows::Web::Http::IHttpCookie*>>(cookies)
                .Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)setViewAsync:(WSCWebAccount*)webAccount view:(WSAWPWebAccountClientView*)view {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetViewAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                               _getRtInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView>(view).Get(),
                               unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)clearViewAsync:(WSCWebAccount*)webAccount applicationCallbackUri:(WFUri*)applicationCallbackUri {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ClearViewAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                                _getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(applicationCallbackUri).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (void)getViewsAsync:(WSCWebAccount*)webAccount
              success:(void (^)(NSArray* /* WSAWPWebAccountClientView* */))success
              failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<
        IVectorView<ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientView*>*>>
        unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetViewsAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         IVectorView<ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientView*>*>,
                                     FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<
                                   IVectorView<ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientView*>*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<IVectorView<ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientView*>> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(RTProxiedNSArray_WSAWPWebAccountClientView_create(result.Get()));
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

+ (RTObject<WFIAsyncAction>*)setWebAccountPictureAsync:(WSCWebAccount*)webAccount
                                     webAccountPicture:(RTObject<WSSIRandomAccessStream>*)webAccountPicture {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetWebAccountPictureAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                            _getRtInterface<ABI::Windows::Storage::Streams::IRandomAccessStream>(webAccountPicture).Get(),
                                            unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (RTObject<WFIAsyncAction>*)clearWebAccountPictureAsync:(WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WSAWPIWebAccountManagerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->ClearWebAccountPictureAsync(_getRtInterface<ABI::Windows::Security::Credentials::IWebAccount>(webAccount).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WSAWPWebAccountProviderRequestTokenOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAWPWebProviderTokenRequest*)providerRequest {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWPWebProviderTokenRequest>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WSAWPWebProviderTokenResponse* */)providerResponses {
    ComPtr<IVector<ABI::Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderResponses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSAWPWebProviderTokenResponse_create(unmarshalledReturn.Get());
}

- (void)setCacheExpirationTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CacheExpirationTime(*[value internalStruct]));
}

- (WFDateTime*)cacheExpirationTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheExpirationTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

- (void)reportUserCanceled {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportUserCanceled());
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPWebAccountProviderGetTokenSilentOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSAWPWebProviderTokenRequest*)providerRequest {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderRequest(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWPWebProviderTokenRequest>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WSAWPWebProviderTokenResponse* */)providerResponses {
    ComPtr<IVector<ABI::Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProviderResponses(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WSAWPWebProviderTokenResponse_create(unmarshalledReturn.Get());
}

- (void)setCacheExpirationTime:(WFDateTime*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->put_CacheExpirationTime(*[value internalStruct]));
}

- (WFDateTime*)cacheExpirationTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_CacheExpirationTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

- (void)reportUserInteractionRequired {
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportUserInteractionRequired());
}

- (void)reportUserInteractionRequiredWithError:(WSAWCWebProviderError*)value {
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportUserInteractionRequiredWithError(
        _getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPWebAccountProviderAddAccountOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

@end

@implementation WSAWPWebAccountProviderManageAccountOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccount(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccount>(unmarshalledReturn.Get());
}

- (void)reportCompleted {
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

@end

@implementation WSAWPWebAccountProviderDeleteAccountOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccount(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccount>(unmarshalledReturn.Get());
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPWebAccountProviderSignOutAccountOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WSCWebAccount*)webAccount {
    ComPtr<ABI::Windows::Security::Credentials::IWebAccount> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_WebAccount(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSCWebAccount>(unmarshalledReturn.Get());
}

- (WFUri*)applicationCallbackUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationCallbackUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSString*)clientId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClientId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPWebAccountProviderRetrieveCookiesOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFUri*)context {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Context(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* WWHHttpCookie* */)cookies {
    ComPtr<IVector<ABI::Windows::Web::Http::HttpCookie*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cookies(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WWHHttpCookie_create(unmarshalledReturn.Get());
}

- (void)setUri:(WFUri*)uri {
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Uri(_getRtInterface<ABI::Windows::Foundation::IUriRuntimeClass>(uri).Get()));
}

- (WFUri*)uri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Uri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WFUri*)applicationCallbackUri {
    ComPtr<ABI::Windows::Foundation::IUriRuntimeClass> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationCallbackUri(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFUri>(unmarshalledReturn.Get());
}

- (WSAWPWebAccountProviderOperationKind)kind {
    ABI::Windows::Security::Authentication::Web::Provider::WebAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WSAWPWebAccountProviderOperationKind)unmarshalledReturn;
}

- (void)reportCompleted {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (void)reportError:(WSAWCWebProviderError*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>(self);
    THROW_NS_IF_FAILED(
        _comInst->ReportError(_getRtInterface<ABI::Windows::Security::Authentication::Web::Core::IWebProviderError>(value).Get()));
}

@end

@implementation WSAWPWebAccountProviderTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSAWPIWebAccountProviderOperation>*)operation {
    ComPtr<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderOperation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects>(self);
    THROW_NS_IF_FAILED(_comInst->get_Operation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAWPIWebAccountProviderOperation>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WSAWPWebAccountClientView_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<
        ArrayAdapterObj<IVectorView<ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientView*>,
                        RTArrayObj<ABI::Windows::Security::Authentication::Web::Provider::IWebAccountClientView*,
                                   IVectorView<ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientView*>,
                                   WSAWPWebAccountClientView,
                                   ABI::Windows::Security::Authentication::Web::Provider::WebAccountClientView*,
                                   dummyObjCCreator,
                                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WSCWebAccount_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Credentials::WebAccount*>,
                                         RTArrayObj<ABI::Windows::Security::Credentials::IWebAccount*,
                                                    IVectorView<ABI::Windows::Security::Credentials::WebAccount*>,
                                                    WSCWebAccount,
                                                    ABI::Windows::Security::Credentials::WebAccount*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WWHHttpCookie_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Web::Http::HttpCookie*>,
                                                                             RTArrayObj<ABI::Windows::Web::Http::IHttpCookie*,
                                                                                        IVectorView<ABI::Windows::Web::Http::HttpCookie*>,
                                                                                        WWHHttpCookie,
                                                                                        ABI::Windows::Web::Http::HttpCookie*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_NSString_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, HSTRING>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, HSTRING>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          HSTRING,
                                          NSString,
                                          NSString,
                                          IMapView<HSTRING, HSTRING>,
                                          dummyObjCCreator,
                                          dummyObjCCreator,
                                          dummyWRLCreator,
                                          dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WSAWPWebProviderTokenResponse_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse*>,
                               RTMutableArrayObj<ABI::Windows::Security::Authentication::Web::Provider::IWebProviderTokenResponse*,
                                                 IVector<ABI::Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse*>,
                                                 WSAWPWebProviderTokenResponse,
                                                 ABI::Windows::Security::Authentication::Web::Provider::WebProviderTokenResponse*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WWHHttpCookie_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Web::Http::HttpCookie*>,
                                                RTMutableArrayObj<ABI::Windows::Web::Http::IHttpCookie*,
                                                                  IVector<ABI::Windows::Web::Http::HttpCookie*>,
                                                                  WWHHttpCookie,
                                                                  ABI::Windows::Web::Http::HttpCookie*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
