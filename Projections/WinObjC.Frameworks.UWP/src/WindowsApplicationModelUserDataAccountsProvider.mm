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

// WindowsApplicationModelUserDataAccountsProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.UserDataAccounts.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelUserDataAccountsProvider.h"
#include "WindowsApplicationModelUserDataAccountsProvider_priv.h"

@implementation WAUPIUserDataAccountProviderOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAUPUserDataAccountProviderOperationKind)kind {
    ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAUPUserDataAccountProviderOperationKind)unmarshalledReturn;
}

@end

@implementation WAUPUserDataAccountPartnerAccountInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)displayName {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisplayName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (unsigned int)priority {
    unsigned int unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Priority(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WAUPUserDataAccountProviderPartnerAccountKind)accountKind {
    ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderPartnerAccountKind unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AccountKind(&unmarshalledReturn));
    return (WAUPUserDataAccountProviderPartnerAccountKind)unmarshalledReturn;
}

@end

@implementation WAUPUserDataAccountProviderAddAccountOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WAUUserDataAccountContentKinds)contentKinds {
    ABI::Windows::ApplicationModel::UserDataAccounts::UserDataAccountContentKinds unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentKinds(&unmarshalledReturn));
    return (WAUUserDataAccountContentKinds)unmarshalledReturn;
}

- (NSArray* /* WAUPUserDataAccountPartnerAccountInfo* */)partnerAccountInfos {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo*>> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_PartnerAccountInfos(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WAUPUserDataAccountPartnerAccountInfo_create(unmarshalledReturn.Get());
}

- (void)reportCompleted:(NSString*)userDataAccountId {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderAddAccountOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted(nsStrToHstr(userDataAccountId).Get()));
}

- (WAUPUserDataAccountProviderOperationKind)kind {
    ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAUPUserDataAccountProviderOperationKind)unmarshalledReturn;
}

@end

@implementation WAUPUserDataAccountProviderSettingsOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)userDataAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_UserDataAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)reportCompleted {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderSettingsOperation>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (WAUPUserDataAccountProviderOperationKind)kind {
    ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAUPUserDataAccountProviderOperationKind)unmarshalledReturn;
}

@end

@implementation WAUPUserDataAccountProviderResolveErrorsOperation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)userDataAccountId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation>(
            self);
    THROW_NS_IF_FAILED(_comInst->get_UserDataAccountId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)reportCompleted {
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderResolveErrorsOperation>(
            self);
    THROW_NS_IF_FAILED(_comInst->ReportCompleted());
}

- (WAUPUserDataAccountProviderOperationKind)kind {
    ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountProviderOperationKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WAUPUserDataAccountProviderOperationKind)unmarshalledReturn;
}

@end

id RTProxiedNSArray_WAUPUserDataAccountPartnerAccountInfo_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<
        IVectorView<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo*>,
        RTArrayObj<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountPartnerAccountInfo*,
                   IVectorView<ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo*>,
                   WAUPUserDataAccountPartnerAccountInfo,
                   ABI::Windows::ApplicationModel::UserDataAccounts::Provider::UserDataAccountPartnerAccountInfo*,
                   dummyObjCCreator,
                   dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
