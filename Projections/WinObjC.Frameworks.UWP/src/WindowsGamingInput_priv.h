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

// WindowsGamingInput_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundation_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsGamingInputForceFeedback_priv.h"
ComPtr<ABI::Windows::Gaming::Input::IArcadeStickStatics> WGIIArcadeStickStatics_inst();
ComPtr<ABI::Windows::Gaming::Input::IGamepadStatics> WGIIGamepadStatics_inst();
ComPtr<ABI::Windows::Gaming::Input::IRacingWheelStatics> WGIIRacingWheelStatics_inst();
ComPtr<ABI::Windows::Gaming::Input::IUINavigationControllerStatics> WGIIUINavigationControllerStatics_inst();
@interface WGIArcadeStickReading (Internal)
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::ArcadeStickReading)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Gaming::Input::ArcadeStickReading*)internalStruct;
@end
inline WGIArcadeStickReading* WGIArcadeStickReading_create(ABI::Windows::Gaming::Input::ArcadeStickReading val) {
    return [WGIArcadeStickReading createWith:val];
}
@interface WGIGamepadReading (Internal)
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::GamepadReading)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Gaming::Input::GamepadReading*)internalStruct;
@end
inline WGIGamepadReading* WGIGamepadReading_create(ABI::Windows::Gaming::Input::GamepadReading val) {
    return [WGIGamepadReading createWith:val];
}
@interface WGIGamepadVibration (Internal)
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::GamepadVibration)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Gaming::Input::GamepadVibration*)internalStruct;
@end
inline WGIGamepadVibration* WGIGamepadVibration_create(ABI::Windows::Gaming::Input::GamepadVibration val) {
    return [WGIGamepadVibration createWith:val];
}
@interface WGIRacingWheelReading (Internal)
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::RacingWheelReading)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Gaming::Input::RacingWheelReading*)internalStruct;
@end
inline WGIRacingWheelReading* WGIRacingWheelReading_create(ABI::Windows::Gaming::Input::RacingWheelReading val) {
    return [WGIRacingWheelReading createWith:val];
}
@interface WGIUINavigationReading (Internal)
+ (instancetype)createWith:(ABI::Windows::Gaming::Input::UINavigationReading)s __attribute__((ns_returns_autoreleased));
- (ABI::Windows::Gaming::Input::UINavigationReading*)internalStruct;
@end
inline WGIUINavigationReading* WGIUINavigationReading_create(ABI::Windows::Gaming::Input::UINavigationReading val) {
    return [WGIUINavigationReading createWith:val];
}

id RTProxiedNSArray_WGIArcadeStick_create(IInspectable* val);
id RTProxiedNSArray_WGIGamepad_create(IInspectable* val);
id RTProxiedNSArray_WGIRacingWheel_create(IInspectable* val);
id RTProxiedNSArray_WGIUINavigationController_create(IInspectable* val);

@class RTProxiedNSArray_WGIArcadeStick, RTProxiedNSArray_WGIGamepad, RTProxiedNSArray_WGIRacingWheel,
    RTProxiedNSArray_WGIUINavigationController;

#ifndef __EventHandler_Windows_Gaming_Input_ArcadeStick__DEFINED
#define __EventHandler_Windows_Gaming_Input_ArcadeStick__DEFINED
class EventHandler_Windows_Gaming_Input_ArcadeStick
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Gaming::Input::ArcadeStick*>> {
    void (^_delegate)(RTObject*, WGIArcadeStick*);

public:
    EventHandler_Windows_Gaming_Input_ArcadeStick(void (^del)(RTObject*, WGIArcadeStick*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Gaming_Input_ArcadeStick() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::Gaming::Input::IArcadeStick* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WGIArcadeStick>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Gaming_Input_Gamepad__DEFINED
#define __EventHandler_Windows_Gaming_Input_Gamepad__DEFINED
class EventHandler_Windows_Gaming_Input_Gamepad
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Gaming::Input::Gamepad*>> {
    void (^_delegate)(RTObject*, WGIGamepad*);

public:
    EventHandler_Windows_Gaming_Input_Gamepad(void (^del)(RTObject*, WGIGamepad*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Gaming_Input_Gamepad() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::Gaming::Input::IGamepad* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WGIGamepad>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Gaming_Input_RacingWheel__DEFINED
#define __EventHandler_Windows_Gaming_Input_RacingWheel__DEFINED
class EventHandler_Windows_Gaming_Input_RacingWheel
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Gaming::Input::RacingWheel*>> {
    void (^_delegate)(RTObject*, WGIRacingWheel*);

public:
    EventHandler_Windows_Gaming_Input_RacingWheel(void (^del)(RTObject*, WGIRacingWheel*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Gaming_Input_RacingWheel() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::Gaming::Input::IRacingWheel* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WGIRacingWheel>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_Gaming_Input_UINavigationController__DEFINED
#define __EventHandler_Windows_Gaming_Input_UINavigationController__DEFINED
class EventHandler_Windows_Gaming_Input_UINavigationController
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::Gaming::Input::UINavigationController*>> {
    void (^_delegate)(RTObject*, WGIUINavigationController*);

public:
    EventHandler_Windows_Gaming_Input_UINavigationController(void (^del)(RTObject*, WGIUINavigationController*)) : _delegate([del copy]) {
    }
    ~EventHandler_Windows_Gaming_Input_UINavigationController() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::Gaming::Input::IUINavigationController* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WGIUINavigationController>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset__DEFINED
#define __ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset__DEFINED
class ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Gaming::Input::IGameController*,
                                                                       ABI::Windows::Gaming::Input::Headset*>> {
    void (^_delegate)(RTObject<WGIIGameController>*, WGIHeadset*);

public:
    ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset(void (^del)(RTObject<WGIIGameController>*,
                                                                                                     WGIHeadset*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_Gaming_Input_Headset() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Gaming::Input::IGameController* arg0,
                                             ABI::Windows::Gaming::Input::IHeadset* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGIIGameController>(arg0), _createRtProxy<WGIHeadset>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Gaming::Input::IGameController*,
                                                                       ABI::Windows::System::UserChangedEventArgs*>> {
    void (^_delegate)(RTObject<WGIIGameController>*, WSUserChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs(void (^del)(RTObject<WGIIGameController>*,
                                                                                                            WSUserChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Gaming_Input_IGameController_Windows_System_UserChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::Gaming::Input::IGameController* arg0,
                                             ABI::Windows::System::IUserChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WGIIGameController>(arg0), _createRtProxy<WSUserChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
