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

// WindowsGamingInput.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Gaming.Input.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGamingInput.h"
#include "WindowsGamingInput_priv.h"

@implementation WGIIGameController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::IGameController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addHeadsetConnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetConnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetConnected(token));
}

- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetDisconnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetDisconnected(token));
}

- (EventRegistrationToken)addUserChangedEvent:(void (^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_UserChanged(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUserChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UserChanged(token));
}

- (WGIHeadset*)headset {
    ComPtr<ABI::Windows::Gaming::Input::IHeadset> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headset(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIHeadset>(unmarshalledReturn.Get());
}

- (BOOL)isWireless {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWireless(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WGIHeadset

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::IHeadset> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)captureDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IHeadset>(self);
    THROW_NS_IF_FAILED(_comInst->get_CaptureDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)renderDeviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IHeadset>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenderDeviceId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WGIArcadeStick

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::IArcadeStick> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Gaming::Input::IArcadeStickStatics> WGIIArcadeStickStatics_inst() {
    ComPtr<ABI::Windows::Gaming::Input::IArcadeStickStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Gaming.Input.ArcadeStick").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addArcadeStickAddedEvent:(void (^)(RTObject*, WGIArcadeStick*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIArcadeStickStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_ArcadeStickAdded(Make<EventHandler_Windows_Gaming_Input_ArcadeStick>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeArcadeStickAddedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIArcadeStickStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ArcadeStickAdded(token));
}

+ (EventRegistrationToken)addArcadeStickRemovedEvent:(void (^)(RTObject*, WGIArcadeStick*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIArcadeStickStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_ArcadeStickRemoved(Make<EventHandler_Windows_Gaming_Input_ArcadeStick>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeArcadeStickRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIArcadeStickStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_ArcadeStickRemoved(token));
}

+ (NSArray* /* WGIArcadeStick* */)arcadeSticks {
    ComPtr<IVectorView<ABI::Windows::Gaming::Input::ArcadeStick*>> unmarshalledReturn;
    auto _comInst = WGIIArcadeStickStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ArcadeSticks(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIArcadeStick_create(unmarshalledReturn.Get());
}

- (WGIGameControllerButtonLabel)getButtonLabel:(WGIArcadeStickButtons)button {
    ABI::Windows::Gaming::Input::GameControllerButtonLabel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IArcadeStick>(self);
    THROW_NS_IF_FAILED(_comInst->GetButtonLabel((ABI::Windows::Gaming::Input::ArcadeStickButtons)button, &unmarshalledReturn));
    return (WGIGameControllerButtonLabel)unmarshalledReturn;
}

- (WGIArcadeStickReading*)getCurrentReading {
    ABI::Windows::Gaming::Input::ArcadeStickReading unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IArcadeStick>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(&unmarshalledReturn));
    return WGIArcadeStickReading_create(unmarshalledReturn);
}

- (EventRegistrationToken)addHeadsetConnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetConnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetConnected(token));
}

- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetDisconnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetDisconnected(token));
}

- (EventRegistrationToken)addUserChangedEvent:(void (^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_UserChanged(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUserChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UserChanged(token));
}

- (WGIHeadset*)headset {
    ComPtr<ABI::Windows::Gaming::Input::IHeadset> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headset(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIHeadset>(unmarshalledReturn.Get());
}

- (BOOL)isWireless {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWireless(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WGIGamepad

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::IGamepad> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Gaming::Input::IGamepadStatics> WGIIGamepadStatics_inst() {
    ComPtr<ABI::Windows::Gaming::Input::IGamepadStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Gaming.Input.Gamepad").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addGamepadAddedEvent:(void (^)(RTObject*, WGIGamepad*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIGamepadStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_GamepadAdded(Make<EventHandler_Windows_Gaming_Input_Gamepad>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeGamepadAddedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIGamepadStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_GamepadAdded(token));
}

+ (EventRegistrationToken)addGamepadRemovedEvent:(void (^)(RTObject*, WGIGamepad*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIGamepadStatics_inst();
    THROW_NS_IF_FAILED(_comInst->add_GamepadRemoved(Make<EventHandler_Windows_Gaming_Input_Gamepad>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeGamepadRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIGamepadStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_GamepadRemoved(token));
}

+ (NSArray* /* WGIGamepad* */)gamepads {
    ComPtr<IVectorView<ABI::Windows::Gaming::Input::Gamepad*>> unmarshalledReturn;
    auto _comInst = WGIIGamepadStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_Gamepads(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIGamepad_create(unmarshalledReturn.Get());
}

- (WGIGamepadVibration*)vibration {
    ABI::Windows::Gaming::Input::GamepadVibration unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGamepad>(self);
    THROW_NS_IF_FAILED(_comInst->get_Vibration(&unmarshalledReturn));
    return WGIGamepadVibration_create(unmarshalledReturn);
}

- (void)setVibration:(WGIGamepadVibration*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGamepad>(self);
    THROW_NS_IF_FAILED(_comInst->put_Vibration(*[value internalStruct]));
}

- (WGIGamepadReading*)getCurrentReading {
    ABI::Windows::Gaming::Input::GamepadReading unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGamepad>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(&unmarshalledReturn));
    return WGIGamepadReading_create(unmarshalledReturn);
}

- (EventRegistrationToken)addHeadsetConnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetConnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetConnected(token));
}

- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetDisconnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetDisconnected(token));
}

- (EventRegistrationToken)addUserChangedEvent:(void (^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_UserChanged(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUserChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UserChanged(token));
}

- (WGIHeadset*)headset {
    ComPtr<ABI::Windows::Gaming::Input::IHeadset> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headset(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIHeadset>(unmarshalledReturn.Get());
}

- (BOOL)isWireless {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWireless(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

- (WGIGameControllerButtonLabel)getButtonLabel:(WGIGamepadButtons)button {
    ABI::Windows::Gaming::Input::GameControllerButtonLabel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGamepad2>(self);
    THROW_NS_IF_FAILED(_comInst->GetButtonLabel((ABI::Windows::Gaming::Input::GamepadButtons)button, &unmarshalledReturn));
    return (WGIGameControllerButtonLabel)unmarshalledReturn;
}

@end

@implementation WGIRacingWheel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::IRacingWheel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Gaming::Input::IRacingWheelStatics> WGIIRacingWheelStatics_inst() {
    ComPtr<ABI::Windows::Gaming::Input::IRacingWheelStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Gaming.Input.RacingWheel").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addRacingWheelAddedEvent:(void (^)(RTObject*, WGIRacingWheel*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIRacingWheelStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_RacingWheelAdded(Make<EventHandler_Windows_Gaming_Input_RacingWheel>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRacingWheelAddedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIRacingWheelStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RacingWheelAdded(token));
}

+ (EventRegistrationToken)addRacingWheelRemovedEvent:(void (^)(RTObject*, WGIRacingWheel*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIRacingWheelStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_RacingWheelRemoved(Make<EventHandler_Windows_Gaming_Input_RacingWheel>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeRacingWheelRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIRacingWheelStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_RacingWheelRemoved(token));
}

+ (NSArray* /* WGIRacingWheel* */)racingWheels {
    ComPtr<IVectorView<ABI::Windows::Gaming::Input::RacingWheel*>> unmarshalledReturn;
    auto _comInst = WGIIRacingWheelStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RacingWheels(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIRacingWheel_create(unmarshalledReturn.Get());
}

- (BOOL)hasClutch {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasClutch(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasHandbrake {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasHandbrake(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasPatternShifter {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasPatternShifter(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)maxPatternShifterGear {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxPatternShifterGear(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maxWheelAngle {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxWheelAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WGIFForceFeedbackMotor*)wheelMotor {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->get_WheelMotor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIFForceFeedbackMotor>(unmarshalledReturn.Get());
}

- (WGIGameControllerButtonLabel)getButtonLabel:(WGIRacingWheelButtons)button {
    ABI::Windows::Gaming::Input::GameControllerButtonLabel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->GetButtonLabel((ABI::Windows::Gaming::Input::RacingWheelButtons)button, &unmarshalledReturn));
    return (WGIGameControllerButtonLabel)unmarshalledReturn;
}

- (WGIRacingWheelReading*)getCurrentReading {
    ABI::Windows::Gaming::Input::RacingWheelReading unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IRacingWheel>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(&unmarshalledReturn));
    return WGIRacingWheelReading_create(unmarshalledReturn);
}

- (EventRegistrationToken)addHeadsetConnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetConnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetConnected(token));
}

- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetDisconnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetDisconnected(token));
}

- (EventRegistrationToken)addUserChangedEvent:(void (^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_UserChanged(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUserChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UserChanged(token));
}

- (WGIHeadset*)headset {
    ComPtr<ABI::Windows::Gaming::Input::IHeadset> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headset(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIHeadset>(unmarshalledReturn.Get());
}

- (BOOL)isWireless {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWireless(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WGIUINavigationController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::IUINavigationController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Gaming::Input::IUINavigationControllerStatics> WGIIUINavigationControllerStatics_inst() {
    ComPtr<ABI::Windows::Gaming::Input::IUINavigationControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Gaming.Input.UINavigationController").Get(),
                                                       &inst));
    return inst;
}

+ (EventRegistrationToken)addUINavigationControllerAddedEvent:(void (^)(RTObject*, WGIUINavigationController*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIUINavigationControllerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_UINavigationControllerAdded(Make<EventHandler_Windows_Gaming_Input_UINavigationController>(value).Get(),
                                                  &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeUINavigationControllerAddedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIUINavigationControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_UINavigationControllerAdded(token));
}

+ (EventRegistrationToken)addUINavigationControllerRemovedEvent:(void (^)(RTObject*, WGIUINavigationController*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WGIIUINavigationControllerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_UINavigationControllerRemoved(Make<EventHandler_Windows_Gaming_Input_UINavigationController>(value).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeUINavigationControllerRemovedEvent:(EventRegistrationToken)token {
    auto _comInst = WGIIUINavigationControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_UINavigationControllerRemoved(token));
}

+ (NSArray* /* WGIUINavigationController* */)uINavigationControllers {
    ComPtr<IVectorView<ABI::Windows::Gaming::Input::UINavigationController*>> unmarshalledReturn;
    auto _comInst = WGIIUINavigationControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_UINavigationControllers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGIUINavigationController_create(unmarshalledReturn.Get());
}

- (WGIUINavigationReading*)getCurrentReading {
    ABI::Windows::Gaming::Input::UINavigationReading unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IUINavigationController>(self);
    THROW_NS_IF_FAILED(_comInst->GetCurrentReading(&unmarshalledReturn));
    return WGIUINavigationReading_create(unmarshalledReturn);
}

- (WGIGameControllerButtonLabel)getOptionalButtonLabel:(WGIOptionalUINavigationButtons)button {
    ABI::Windows::Gaming::Input::GameControllerButtonLabel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IUINavigationController>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetOptionalButtonLabel((ABI::Windows::Gaming::Input::OptionalUINavigationButtons)button, &unmarshalledReturn));
    return (WGIGameControllerButtonLabel)unmarshalledReturn;
}

- (WGIGameControllerButtonLabel)getRequiredButtonLabel:(WGIRequiredUINavigationButtons)button {
    ABI::Windows::Gaming::Input::GameControllerButtonLabel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IUINavigationController>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetRequiredButtonLabel((ABI::Windows::Gaming::Input::RequiredUINavigationButtons)button, &unmarshalledReturn));
    return (WGIGameControllerButtonLabel)unmarshalledReturn;
}

- (EventRegistrationToken)addHeadsetConnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetConnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetConnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetConnected(token));
}

- (EventRegistrationToken)addHeadsetDisconnectedEvent:(void (^)(RTObject<WGIIGameController>*, WGIHeadset*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_HeadsetDisconnected(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHeadsetDisconnectedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HeadsetDisconnected(token));
}

- (EventRegistrationToken)addUserChangedEvent:(void (^)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->add_UserChanged(
        Make<ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs>(value).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUserChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UserChanged(token));
}

- (WGIHeadset*)headset {
    ComPtr<ABI::Windows::Gaming::Input::IHeadset> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_Headset(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGIHeadset>(unmarshalledReturn.Get());
}

- (BOOL)isWireless {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsWireless(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WSUser*)user {
    ComPtr<ABI::Windows::System::IUser> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::IGameController>(self);
    THROW_NS_IF_FAILED(_comInst->get_User(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSUser>(unmarshalledReturn.Get());
}

@end

@implementation WGIArcadeStickReading {
    ABI::Windows::Gaming::Input::ArcadeStickReading structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::ArcadeStickReading)s {
    WGIArcadeStickReading* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Gaming::Input::ArcadeStickReading*)internalStruct {
    return &structVal;
}
- (uint64_t)timestamp {
    return structVal.Timestamp;
}
- (void)setTimestamp:(uint64_t)val {
    structVal.Timestamp = val;
}
- (WGIArcadeStickButtons)buttons {
    return (WGIArcadeStickButtons)structVal.Buttons;
}
- (void)setButtons:(WGIArcadeStickButtons)val {
    structVal.Buttons = (ABI::Windows::Gaming::Input::ArcadeStickButtons)val;
}
@end
@implementation WGIGamepadReading {
    ABI::Windows::Gaming::Input::GamepadReading structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::GamepadReading)s {
    WGIGamepadReading* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Gaming::Input::GamepadReading*)internalStruct {
    return &structVal;
}
- (uint64_t)timestamp {
    return structVal.Timestamp;
}
- (void)setTimestamp:(uint64_t)val {
    structVal.Timestamp = val;
}
- (WGIGamepadButtons)buttons {
    return (WGIGamepadButtons)structVal.Buttons;
}
- (void)setButtons:(WGIGamepadButtons)val {
    structVal.Buttons = (ABI::Windows::Gaming::Input::GamepadButtons)val;
}
- (double)leftTrigger {
    return structVal.LeftTrigger;
}
- (void)setLeftTrigger:(double)val {
    structVal.LeftTrigger = val;
}
- (double)rightTrigger {
    return structVal.RightTrigger;
}
- (void)setRightTrigger:(double)val {
    structVal.RightTrigger = val;
}
- (double)leftThumbstickX {
    return structVal.LeftThumbstickX;
}
- (void)setLeftThumbstickX:(double)val {
    structVal.LeftThumbstickX = val;
}
- (double)leftThumbstickY {
    return structVal.LeftThumbstickY;
}
- (void)setLeftThumbstickY:(double)val {
    structVal.LeftThumbstickY = val;
}
- (double)rightThumbstickX {
    return structVal.RightThumbstickX;
}
- (void)setRightThumbstickX:(double)val {
    structVal.RightThumbstickX = val;
}
- (double)rightThumbstickY {
    return structVal.RightThumbstickY;
}
- (void)setRightThumbstickY:(double)val {
    structVal.RightThumbstickY = val;
}
@end
@implementation WGIGamepadVibration {
    ABI::Windows::Gaming::Input::GamepadVibration structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::GamepadVibration)s {
    WGIGamepadVibration* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Gaming::Input::GamepadVibration*)internalStruct {
    return &structVal;
}
- (double)leftMotor {
    return structVal.LeftMotor;
}
- (void)setLeftMotor:(double)val {
    structVal.LeftMotor = val;
}
- (double)rightMotor {
    return structVal.RightMotor;
}
- (void)setRightMotor:(double)val {
    structVal.RightMotor = val;
}
- (double)leftTrigger {
    return structVal.LeftTrigger;
}
- (void)setLeftTrigger:(double)val {
    structVal.LeftTrigger = val;
}
- (double)rightTrigger {
    return structVal.RightTrigger;
}
- (void)setRightTrigger:(double)val {
    structVal.RightTrigger = val;
}
@end
@implementation WGIRacingWheelReading {
    ABI::Windows::Gaming::Input::RacingWheelReading structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::RacingWheelReading)s {
    WGIRacingWheelReading* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Gaming::Input::RacingWheelReading*)internalStruct {
    return &structVal;
}
- (uint64_t)timestamp {
    return structVal.Timestamp;
}
- (void)setTimestamp:(uint64_t)val {
    structVal.Timestamp = val;
}
- (WGIRacingWheelButtons)buttons {
    return (WGIRacingWheelButtons)structVal.Buttons;
}
- (void)setButtons:(WGIRacingWheelButtons)val {
    structVal.Buttons = (ABI::Windows::Gaming::Input::RacingWheelButtons)val;
}
- (int)patternShifterGear {
    return structVal.PatternShifterGear;
}
- (void)setPatternShifterGear:(int)val {
    structVal.PatternShifterGear = val;
}
- (double)wheel {
    return structVal.Wheel;
}
- (void)setWheel:(double)val {
    structVal.Wheel = val;
}
- (double)throttle {
    return structVal.Throttle;
}
- (void)setThrottle:(double)val {
    structVal.Throttle = val;
}
- (double)brake {
    return structVal.Brake;
}
- (void)setBrake:(double)val {
    structVal.Brake = val;
}
- (double)clutch {
    return structVal.Clutch;
}
- (void)setClutch:(double)val {
    structVal.Clutch = val;
}
- (double)handbrake {
    return structVal.Handbrake;
}
- (void)setHandbrake:(double)val {
    structVal.Handbrake = val;
}
@end
@implementation WGIUINavigationReading {
    ABI::Windows::Gaming::Input::UINavigationReading structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::UINavigationReading)s {
    WGIUINavigationReading* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::Gaming::Input::UINavigationReading*)internalStruct {
    return &structVal;
}
- (uint64_t)timestamp {
    return structVal.Timestamp;
}
- (void)setTimestamp:(uint64_t)val {
    structVal.Timestamp = val;
}
- (WGIRequiredUINavigationButtons)requiredButtons {
    return (WGIRequiredUINavigationButtons)structVal.RequiredButtons;
}
- (void)setRequiredButtons:(WGIRequiredUINavigationButtons)val {
    structVal.RequiredButtons = (ABI::Windows::Gaming::Input::RequiredUINavigationButtons)val;
}
- (WGIOptionalUINavigationButtons)optionalButtons {
    return (WGIOptionalUINavigationButtons)structVal.OptionalButtons;
}
- (void)setOptionalButtons:(WGIOptionalUINavigationButtons)val {
    structVal.OptionalButtons = (ABI::Windows::Gaming::Input::OptionalUINavigationButtons)val;
}
@end
id RTProxiedNSArray_WGIArcadeStick_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Gaming::Input::ArcadeStick*>,
                                         RTArrayObj<ABI::Windows::Gaming::Input::IArcadeStick*,
                                                    IVectorView<ABI::Windows::Gaming::Input::ArcadeStick*>,
                                                    WGIArcadeStick,
                                                    ABI::Windows::Gaming::Input::ArcadeStick*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGIGamepad_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Gaming::Input::Gamepad*>,
                                                                             RTArrayObj<ABI::Windows::Gaming::Input::IGamepad*,
                                                                                        IVectorView<ABI::Windows::Gaming::Input::Gamepad*>,
                                                                                        WGIGamepad,
                                                                                        ABI::Windows::Gaming::Input::Gamepad*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGIRacingWheel_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Gaming::Input::RacingWheel*>,
                                         RTArrayObj<ABI::Windows::Gaming::Input::IRacingWheel*,
                                                    IVectorView<ABI::Windows::Gaming::Input::RacingWheel*>,
                                                    WGIRacingWheel,
                                                    ABI::Windows::Gaming::Input::RacingWheel*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGIUINavigationController_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Gaming::Input::UINavigationController*>,
                                         RTArrayObj<ABI::Windows::Gaming::Input::IUINavigationController*,
                                                    IVectorView<ABI::Windows::Gaming::Input::UINavigationController*>,
                                                    WGIUINavigationController,
                                                    ABI::Windows::Gaming::Input::UINavigationController*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
