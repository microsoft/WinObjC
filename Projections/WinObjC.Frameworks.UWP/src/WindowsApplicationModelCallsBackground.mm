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

// WindowsApplicationModelCallsBackground.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.ApplicationModel.Calls.Background.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsApplicationModelCallsBackground.h"
#include "WindowsApplicationModelCallsBackground_priv.h"

@implementation WACBPhoneCallBlockedTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)phoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WFGUID*)lineId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WACBPhoneCallBlockedReason)callBlockedReason {
    ABI::Windows::ApplicationModel::Calls::Background::PhoneCallBlockedReason unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_CallBlockedReason(&unmarshalledReturn));
    return (WACBPhoneCallBlockedReason)unmarshalledReturn;
}

@end

@implementation WACBPhoneCallOriginDataRequestTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)requestId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequestId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (NSString*)phoneNumber {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhoneNumber(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACBPhoneNewVoicemailMessageTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)lineId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (int)voicemailCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_VoicemailCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)operatorMessage {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_OperatorMessage(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WACBPhoneLineChangedTriggerDetails

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFGUID*)lineId {
    GUID unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_LineId(&unmarshalledReturn));
    return _makeObjcFrom<GUID>(unmarshalledReturn);
}

- (WACBPhoneLineChangeKind)changeType {
    ABI::Windows::ApplicationModel::Calls::Background::PhoneLineChangeKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChangeType(&unmarshalledReturn));
    return (WACBPhoneLineChangeKind)unmarshalledReturn;
}

- (BOOL)hasLinePropertyChanged:(WACBPhoneLineProperties)lineProperty {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails>(self);
    THROW_NS_IF_FAILED(
        _comInst->HasLinePropertyChanged((ABI::Windows::ApplicationModel::Calls::Background::PhoneLineProperties)lineProperty,
                                         &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end
