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

// WindowsDevicesGpioProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Gpio.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesGpioProvider.h"
#include "WindowsDevicesGpioProvider_priv.h"

@implementation WDGPIGpioPinProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addValueChangedEvent:(void (^)(RTObject<WDGPIGpioPinProvider>*,
                                                         WDGPGpioPinProviderValueChangedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->add_ValueChanged(
        Make<
            ITypedEventHandler_Windows_Devices_Gpio_Provider_IGpioPinProvider_Windows_Devices_Gpio_Provider_GpioPinProviderValueChangedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeValueChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ValueChanged(token));
}

- (WFTimeSpan*)debounceTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DebounceTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDebounceTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->put_DebounceTimeout(*[value internalStruct]));
}

- (int)pinNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinNumber(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDGPProviderGpioSharingMode)sharingMode {
    ABI::Windows::Devices::Gpio::Provider::ProviderGpioSharingMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SharingMode(&unmarshalledReturn));
    return (WDGPProviderGpioSharingMode)unmarshalledReturn;
}

- (BOOL)isDriveModeSupported:(WDGPProviderGpioPinDriveMode)driveMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsDriveModeSupported((ABI::Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode)driveMode, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WDGPProviderGpioPinDriveMode)getDriveMode {
    ABI::Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetDriveMode(&unmarshalledReturn));
    return (WDGPProviderGpioPinDriveMode)unmarshalledReturn;
}

- (void)setDriveMode:(WDGPProviderGpioPinDriveMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetDriveMode((ABI::Windows::Devices::Gpio::Provider::ProviderGpioPinDriveMode)value));
}

- (void)write:(WDGPProviderGpioPinValue)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Write((ABI::Windows::Devices::Gpio::Provider::ProviderGpioPinValue)value));
}

- (WDGPProviderGpioPinValue)read {
    ABI::Windows::Devices::Gpio::Provider::ProviderGpioPinValue unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Read(&unmarshalledReturn));
    return (WDGPProviderGpioPinValue)unmarshalledReturn;
}

@end

@implementation WDGPIGpioControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)pinCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_PinCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject<WDGPIGpioPinProvider>*)openPinProvider:(int)pin sharingMode:(WDGPProviderGpioSharingMode)sharingMode {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioPinProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->OpenPinProvider(pin,
                                                 (ABI::Windows::Devices::Gpio::Provider::ProviderGpioSharingMode)sharingMode,
                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGPIGpioPinProvider>(unmarshalledReturn.Get());
}

@end

@implementation WDGPIGpioProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject<WDGPIGpioControllerProvider>* */)getControllers {
    ComPtr<IVectorView<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetControllers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WDGPIGpioControllerProvider_create(unmarshalledReturn.Get());
}

@end

@implementation WDGPGpioPinProviderValueChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>
WDGPIGpioPinProviderValueChangedEventArgsFactory_inst() {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Devices.Gpio.Provider.GpioPinProviderValueChangedEventArgs").Get(), &inst));
    return inst;
}

+ (WDGPGpioPinProviderValueChangedEventArgs*)make:(WDGPProviderGpioPinEdge)edge {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs> unmarshalledReturn;
    auto _comInst = WDGPIGpioPinProviderValueChangedEventArgsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Devices::Gpio::Provider::ProviderGpioPinEdge)edge, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDGPGpioPinProviderValueChangedEventArgs>(unmarshalledReturn.Get()) retain];
}

- (WDGPProviderGpioPinEdge)edge {
    ABI::Windows::Devices::Gpio::Provider::ProviderGpioPinEdge unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Edge(&unmarshalledReturn));
    return (WDGPProviderGpioPinEdge)unmarshalledReturn;
}

@end

id RTProxiedNSArray_RTObject_WDGPIGpioControllerProvider_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider*>,
                                         RTArrayObj<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider*,
                                                    IVectorView<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider*>,
                                                    RTObject<WDGPIGpioControllerProvider>,
                                                    ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
