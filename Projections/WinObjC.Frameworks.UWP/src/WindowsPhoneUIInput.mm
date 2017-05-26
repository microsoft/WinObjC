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

// WindowsPhoneUIInput.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.UI.Input.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneUIInput.h"
#include "WindowsPhoneUIInput_priv.h"

@implementation WPUIBackPressedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::UI::Input::IBackPressedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)handled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::UI::Input::IBackPressedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Handled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setHandled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::UI::Input::IBackPressedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Handled((boolean)value));
}

@end

@implementation WPUICameraEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::UI::Input::ICameraEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WPUIHardwareButtons

ComPtr<ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2> WPUIIHardwareButtonsStatics2_inst() {
    ComPtr<ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.UI.Input.HardwareButtons").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addCameraHalfPressedEvent:(void (^)(RTObject*, WPUICameraEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WPUIIHardwareButtonsStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_CameraHalfPressed(Make<EventHandler_Windows_Phone_UI_Input_CameraEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeCameraHalfPressedEvent:(EventRegistrationToken)token {
    auto _comInst = WPUIIHardwareButtonsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_CameraHalfPressed(token));
}

+ (EventRegistrationToken)addCameraPressedEvent:(void (^)(RTObject*, WPUICameraEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WPUIIHardwareButtonsStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_CameraPressed(Make<EventHandler_Windows_Phone_UI_Input_CameraEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeCameraPressedEvent:(EventRegistrationToken)token {
    auto _comInst = WPUIIHardwareButtonsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_CameraPressed(token));
}

+ (EventRegistrationToken)addCameraReleasedEvent:(void (^)(RTObject*, WPUICameraEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WPUIIHardwareButtonsStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_CameraReleased(Make<EventHandler_Windows_Phone_UI_Input_CameraEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeCameraReleasedEvent:(EventRegistrationToken)token {
    auto _comInst = WPUIIHardwareButtonsStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->remove_CameraReleased(token));
}

ComPtr<ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics> WPUIIHardwareButtonsStatics_inst() {
    ComPtr<ABI::Windows::Phone::UI::Input::IHardwareButtonsStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.UI.Input.HardwareButtons").Get(), &inst));
    return inst;
}

+ (EventRegistrationToken)addBackPressedEvent:(void (^)(RTObject*, WPUIBackPressedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = WPUIIHardwareButtonsStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->add_BackPressed(Make<EventHandler_Windows_Phone_UI_Input_BackPressedEventArgs>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

+ (void)removeBackPressedEvent:(EventRegistrationToken)token {
    auto _comInst = WPUIIHardwareButtonsStatics_inst();
    THROW_NS_IF_FAILED(_comInst->remove_BackPressed(token));
}

@end
