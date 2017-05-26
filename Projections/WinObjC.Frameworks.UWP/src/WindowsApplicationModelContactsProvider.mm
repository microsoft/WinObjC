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

// WindowsApplicationModelContactsProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Contacts.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelContactsProvider.h"
#include "WindowsApplicationModelContactsProvider_priv.h"

@implementation WACPContactRemovedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)id {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactRemovedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Id(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACPContactPickerUI

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WACPAddContactResult)addContact:(NSString*)id contact:(WACContact*)contact {
    ABI::Windows::ApplicationModel::Contacts::Provider::AddContactResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->AddContact(nsStrToHstr(id).Get(),
                                            _getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(),
                                            &unmarshalledReturn));
    return (WACPAddContactResult)unmarshalledReturn;
}

- (void)removeContact:(NSString*)id {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveContact(nsStrToHstr(id).Get()));
}

- (BOOL)containsContact:(NSString*)id {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->ContainsContact(nsStrToHstr(id).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* NSString * */)desiredFields {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredFields(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (WACContactSelectionMode)selectionMode {
    ABI::Windows::ApplicationModel::Contacts::ContactSelectionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionMode(&unmarshalledReturn));
    return (WACContactSelectionMode)unmarshalledReturn;
}

- (EventRegistrationToken)addContactRemovedEvent:(void (^)(WACPContactPickerUI*, WACPContactRemovedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->add_ContactRemoved(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_Contacts_Provider_ContactPickerUI_Windows_ApplicationModel_Contacts_Provider_ContactRemovedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeContactRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ContactRemoved(token));
}

- (WACPAddContactResult)addContact:(WACContact*)contact {
    ABI::Windows::ApplicationModel::Contacts::Provider::AddContactResult unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI2>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddContact(_getRtInterface<ABI::Windows::ApplicationModel::Contacts::IContact>(contact).Get(), &unmarshalledReturn));
    return (WACPAddContactResult)unmarshalledReturn;
}

- (NSMutableArray* /* WACContactFieldType */)desiredFieldsWithContactFieldType {
    ComPtr<IVector<ABI::Windows::ApplicationModel::Contacts::ContactFieldType>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Contacts::Provider::IContactPickerUI2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredFieldsWithContactFieldType(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WACContactFieldType_create(unmarshalledReturn.Get());
}

@end
