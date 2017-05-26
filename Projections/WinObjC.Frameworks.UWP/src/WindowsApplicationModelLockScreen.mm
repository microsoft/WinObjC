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

// WindowsApplicationModelLockScreen.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.LockScreen.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelLockScreen.h"
#include "WindowsApplicationModelLockScreen_priv.h"

@implementation WALLockScreenInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addLockScreenImageChangedEvent:(void (^)(WALLockScreenInfo*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_LockScreenImageChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_LockScreen_LockScreenInfo_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeLockScreenImageChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_LockScreenImageChanged(token));
}

- (RTObject<WSSIRandomAccessStream>*)lockScreenImage {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_LockScreenImage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addBadgesChangedEvent:(void (^)(WALLockScreenInfo*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_BadgesChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_LockScreen_LockScreenInfo_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeBadgesChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_BadgesChanged(token));
}

- (NSArray* /* WALLockScreenBadge* */)badges {
    ComPtr<IVectorView<ABI::Windows::ApplicationModel::LockScreen::LockScreenBadge*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_Badges(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WALLockScreenBadge_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addDetailTextChangedEvent:(void (^)(WALLockScreenInfo*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_DetailTextChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_LockScreen_LockScreenInfo_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDetailTextChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DetailTextChanged(token));
}

- (NSArray* /* NSString * */)detailText {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_DetailText(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addAlarmIconChangedEvent:(void (^)(WALLockScreenInfo*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_AlarmIconChanged(
        Make<ITypedEventHandler_Windows_ApplicationModel_LockScreen_LockScreenInfo_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAlarmIconChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AlarmIconChanged(token));
}

- (RTObject<WSSIRandomAccessStream>*)alarmIcon {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlarmIcon(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

@end

@implementation WALLockScreenBadge

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSSIRandomAccessStream>*)logo {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge>(self);
    THROW_NS_IF_FAILED(_comInst->get_Logo(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStream>*)glyph {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStream> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge>(self);
    THROW_NS_IF_FAILED(_comInst->get_Glyph(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStream>(unmarshalledReturn.Get());
}

- (id /* unsigned int */)number {
    ComPtr<IReference<unsigned int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge>(self);
    THROW_NS_IF_FAILED(_comInst->get_Number(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<unsigned int, unsigned int>::convert(unmarshalledReturn.Get());
}

- (NSString*)automationName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutomationName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)launchApp {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge>(self);
    THROW_NS_IF_FAILED(_comInst->LaunchApp());
}

@end

@implementation WALLockScreenUnlockingDeferral

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)complete {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral>(self);
    THROW_NS_IF_FAILED(_comInst->Complete());
}

@end

@implementation WALLockApplicationHost

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHost> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHostStatics> WALILockApplicationHostStatics_inst() {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHostStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.ApplicationModel.LockScreen.LockApplicationHost").Get(), &inst));
    return inst;
}

+ (WALLockApplicationHost*)getForCurrentView {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHost> unmarshalledReturn;
    auto _comInst = WALILockApplicationHostStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WALLockApplicationHost>(unmarshalledReturn.Get());
}

- (void)requestUnlock {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHost>(self);
    THROW_NS_IF_FAILED(_comInst->RequestUnlock());
}

- (EventRegistrationToken)addUnlockingEvent:(void (^)(WALLockApplicationHost*, WALLockScreenUnlockingEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHost>(self);
    THROW_NS_IF_FAILED(_comInst->add_Unlocking(
        Make<
            ITypedEventHandler_Windows_ApplicationModel_LockScreen_LockApplicationHost_Windows_ApplicationModel_LockScreen_LockScreenUnlockingEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUnlockingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockApplicationHost>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Unlocking(token));
}

@end

@implementation WALLockScreenUnlockingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WALLockScreenUnlockingDeferral*)getDeferral {
    ComPtr<ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingDeferral> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->GetDeferral(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WALLockScreenUnlockingDeferral>(unmarshalledReturn.Get());
}

- (WFDateTime*)deadline {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::LockScreen::ILockScreenUnlockingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Deadline(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

@end

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WALLockScreenBadge_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::ApplicationModel::LockScreen::LockScreenBadge*>,
                                         RTArrayObj<ABI::Windows::ApplicationModel::LockScreen::ILockScreenBadge*,
                                                    IVectorView<ABI::Windows::ApplicationModel::LockScreen::LockScreenBadge*>,
                                                    WALLockScreenBadge,
                                                    ABI::Windows::ApplicationModel::LockScreen::LockScreenBadge*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
