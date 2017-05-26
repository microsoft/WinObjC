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

// WindowsDevicesPwmProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Pwm.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPwmProvider.h"
#include "WindowsDevicesPwmProvider_priv.h"

@implementation WDPPIPwmControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)pinCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)actualFrequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActualFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)setDesiredFrequency:(double)frequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetDesiredFrequency(frequency, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maxFrequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)minFrequency {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinFrequency(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)acquirePin:(int)pin {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AcquirePin(pin));
}

- (void)releasePin:(int)pin {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ReleasePin(pin));
}

- (void)enablePin:(int)pin {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->EnablePin(pin));
}

- (void)disablePin:(int)pin {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->DisablePin(pin));
}

- (void)setPulseParameters:(int)pin dutyCycle:(double)dutyCycle invertPolarity:(BOOL)invertPolarity {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetPulseParameters(pin, dutyCycle, (boolean)invertPolarity));
}

@end

@implementation WDPPIPwmProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Pwm::Provider::IPwmProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject<WDPPIPwmControllerProvider>* */)getControllers {
    ComPtr<IVectorView<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Pwm::Provider::IPwmProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetControllers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WDPPIPwmControllerProvider_create(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_RTObject_WDPPIPwmControllerProvider_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider*>,
                                         RTArrayObj<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider*,
                                                    IVectorView<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider*>,
                                                    RTObject<WDPPIPwmControllerProvider>,
                                                    ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
