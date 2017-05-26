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

// WindowsSecurityAuthenticationOnlineId.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Security.Authentication.OnlineId.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsSecurityAuthenticationOnlineId.h"
#include "WindowsSecurityAuthenticationOnlineId_priv.h"

@implementation WSAOOnlineIdServiceTicketRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory>
WSAOIOnlineIdServiceTicketRequestFactory_inst() {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequestFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Security.Authentication.OnlineId.OnlineIdServiceTicketRequest").Get(), &inst));
    return inst;
}

+ (WSAOOnlineIdServiceTicketRequest*)makeOnlineIdServiceTicketRequest:(NSString*)service policy:(NSString*)policy {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> unmarshalledReturn;
    auto _comInst = WSAOIOnlineIdServiceTicketRequestFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateOnlineIdServiceTicketRequest(nsStrToHstr(service).Get(),
                                                                    nsStrToHstr(policy).Get(),
                                                                    unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAOOnlineIdServiceTicketRequest>(unmarshalledReturn.Get()) retain];
}

+ (WSAOOnlineIdServiceTicketRequest*)makeOnlineIdServiceTicketRequestAdvanced:(NSString*)service {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> unmarshalledReturn;
    auto _comInst = WSAOIOnlineIdServiceTicketRequestFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateOnlineIdServiceTicketRequestAdvanced(nsStrToHstr(service).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WSAOOnlineIdServiceTicketRequest>(unmarshalledReturn.Get()) retain];
}

- (NSString*)service {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Service(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)policy {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Policy(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WSAOOnlineIdServiceTicket

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WSAOOnlineIdServiceTicketRequest*)request {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicketRequest> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAOOnlineIdServiceTicketRequest>(unmarshalledReturn.Get());
}

- (int)errorCode {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WSAOUserAuthenticationOperation

// Failed to get type for default interface: Can't marshal
// Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity>
// Could not find base class Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity> type information
- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSAOSignOutUserOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setCompleted:(WFAsyncActionCompletedHandler)handler {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->put_Completed(Make<WFAsyncActionCompletedHandler_shim>(handler).Get()));
}

- (WFAsyncActionCompletedHandler)completed {
    ComPtr<ABI::Windows::Foundation::IAsyncActionCompletedHandler> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->get_Completed(unmarshalledReturn.GetAddressOf()));
    return nil;
}

- (void)getResults {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncAction>(self);
    THROW_NS_IF_FAILED(_comInst->GetResults());
}

- (unsigned int)id {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFAsyncStatus)status {
    AsyncStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (unsigned)unmarshalledReturn;
}

- (HRESULT)errorCode {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_ErrorCode(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IAsyncInfo>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WSAOUserIdentity

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WSAOOnlineIdServiceTicket* */)tickets {
    ComPtr<IVectorView<ABI::Windows::Security::Authentication::OnlineId::OnlineIdServiceTicket*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tickets(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WSAOOnlineIdServiceTicket_create(unmarshalledReturn.Get());
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)safeCustomerId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_SafeCustomerId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)signInName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_SignInName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)firstName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_FirstName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)lastName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_LastName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isBetaAccount {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsBetaAccount(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isConfirmedPC {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IUserIdentity>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsConfirmedPC(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WSAOOnlineIdAuthenticator

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.Security.Authentication.OnlineId.OnlineIdAuthenticator").Get(), &out));
    return [_createRtProxy<WSAOOnlineIdAuthenticator>(out.Get()) retain];
}

// Failed to generate member AuthenticateUserAsync (Can't marshal
// Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity>)
// Failed to generate member AuthenticateUserAsync (Can't marshal
// Windows.Foundation.IAsyncOperation`1<Windows.Security.Authentication.OnlineId.UserIdentity>)
- (WSAOSignOutUserOperation*)signOutUserAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator>(self);
    THROW_NS_IF_FAILED(_comInst->SignOutUserAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSAOSignOutUserOperation>(unmarshalledReturn.Get());
}

- (void)setApplicationId:(WFGUID*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator>(self);
    THROW_NS_IF_FAILED(_comInst->put_ApplicationId(value.guidValue));
}

- (WFGUID*)applicationId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator>(self);
    THROW_NS_IF_FAILED(_comInst->get_ApplicationId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (BOOL)canSignOut {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSignOut(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)authenticatedSafeCustomerId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdAuthenticator>(self);
    THROW_NS_IF_FAILED(_comInst->get_AuthenticatedSafeCustomerId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

id RTProxiedNSArray_WSAOOnlineIdServiceTicket_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Security::Authentication::OnlineId::OnlineIdServiceTicket*>,
                                         RTArrayObj<ABI::Windows::Security::Authentication::OnlineId::IOnlineIdServiceTicket*,
                                                    IVectorView<ABI::Windows::Security::Authentication::OnlineId::OnlineIdServiceTicket*>,
                                                    WSAOOnlineIdServiceTicket,
                                                    ABI::Windows::Security::Authentication::OnlineId::OnlineIdServiceTicket*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
