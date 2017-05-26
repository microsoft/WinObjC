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

// WindowsApplicationModelContactsDataProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Contacts.DataProvider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelContactsDataProvider.h"
#include "WindowsApplicationModelContactsDataProvider_priv.h"

@implementation WACDContactDataProviderConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addSyncRequestedEvent:(void (^)(WACDContactDataProviderConnection*,
                                                          WACDContactListSyncManagerSyncRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_SyncRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListSyncManagerSyncRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSyncRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SyncRequested(token));
}

- (EventRegistrationToken)addServerSearchReadBatchRequestedEvent:(void (^)(WACDContactDataProviderConnection*,
                                                                           WACDContactListServerSearchReadBatchRequestEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->add_ServerSearchReadBatchRequested(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Contacts_DataProvider_ContactDataProviderConnection_Windows_ApplicationModel_Contacts_DataProvider_ContactListServerSearchReadBatchRequestEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeServerSearchReadBatchRequestedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ServerSearchReadBatchRequested(token));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

@end

@implementation WACDContactListSyncManagerSyncRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACDContactListSyncManagerSyncRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACDContactListSyncManagerSyncRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WACDContactListServerSearchReadBatchRequestEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACDContactListServerSearchReadBatchRequest*)request {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Request(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACDContactListServerSearchReadBatchRequest>(unmarshalledReturn.Get());
}

- (WFDeferral*)getDeferral {
    ComPtr<ABI::Windows::Foundation::IDeferral> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFDeferral>(unmarshalledReturn.Get());
}

@end

@implementation WACDContactDataProviderTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACDContactDataProviderConnection*)connection {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_Connection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACDContactDataProviderConnection>(unmarshalledReturn.Get());
}

@end

@implementation WACDContactListSyncManagerSyncRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)contactListId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactListId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

@implementation WACDContactListServerSearchReadBatchRequest

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)sessionId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SessionId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)contactListId {
    HSTRING unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContactListId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WACContactQueryOptions*)options {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::IContactQueryOptions> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_Options(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WACContactQueryOptions>(unmarshalledReturn.Get());
}

- (unsigned int)suggestedBatchSize {
    unsigned int unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->get_SuggestedBatchSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)saveContactAsync:(WACContact*)contact {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->SaveContactAsync(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportCompletedAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportCompletedAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)reportFailedAsync:(WACContactBatchStatus)batchStatus {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst =
        _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest>(self);
    THROW_NS_IF_FAILED(_comInst->ReportFailedAsync((ABI::Windows::ApplicationModel::Contacts::ContactBatchStatus)batchStatus,
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end
