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

// WindowsDevices.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevices.h"
#include "WindowsDevices_priv.h"

@implementation WDILowLevelDevicesAggregateProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WDAPIAdcControllerProvider>*)adcControllerProvider {
    ComPtr<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdcControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAPIAdcControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDPPIPwmControllerProvider>*)pwmControllerProvider {
    ComPtr<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_PwmControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPIPwmControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDGPIGpioControllerProvider>*)gpioControllerProvider {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_GpioControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGPIGpioControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDIPII2cControllerProvider>*)i2cControllerProvider {
    ComPtr<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_I2cControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDIPII2cControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDSPISpiControllerProvider>*)spiControllerProvider {
    ComPtr<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpiControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSPISpiControllerProvider>(unmarshalledReturn.Get());
}

@end

@implementation WDLowLevelDevicesAggregateProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Devices::ILowLevelDevicesAggregateProviderFactory> WDILowLevelDevicesAggregateProviderFactory_inst() {
    ComPtr<ABI::Windows::Devices::ILowLevelDevicesAggregateProviderFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.LowLevelDevicesAggregateProvider").Get(),
                                                       &inst));
    return inst;
}

+ (WDLowLevelDevicesAggregateProvider*)make:(RTObject<WDAPIAdcControllerProvider>*)adc
                                        pwm:(RTObject<WDPPIPwmControllerProvider>*)pwm
                                       gpio:(RTObject<WDGPIGpioControllerProvider>*)gpio
                                        i2c:(RTObject<WDIPII2cControllerProvider>*)i2c
                                        spi:(RTObject<WDSPISpiControllerProvider>*)spi {
    ComPtr<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider> unmarshalledReturn;
    auto _comInst = WDILowLevelDevicesAggregateProviderFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(_getRtInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(adc).Get(),
                                        _getRtInterface<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider>(pwm).Get(),
                                        _getRtInterface<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider>(gpio).Get(),
                                        _getRtInterface<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider>(i2c).Get(),
                                        _getRtInterface<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider>(spi).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WDLowLevelDevicesAggregateProvider>(unmarshalledReturn.Get()) retain];
}

- (RTObject<WDAPIAdcControllerProvider>*)adcControllerProvider {
    ComPtr<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AdcControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDAPIAdcControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDPPIPwmControllerProvider>*)pwmControllerProvider {
    ComPtr<ABI::Windows::Devices::Pwm::Provider::IPwmControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_PwmControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDPPIPwmControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDGPIGpioControllerProvider>*)gpioControllerProvider {
    ComPtr<ABI::Windows::Devices::Gpio::Provider::IGpioControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_GpioControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDGPIGpioControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDIPII2cControllerProvider>*)i2cControllerProvider {
    ComPtr<ABI::Windows::Devices::I2c::Provider::II2cControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_I2cControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDIPII2cControllerProvider>(unmarshalledReturn.Get());
}

- (RTObject<WDSPISpiControllerProvider>*)spiControllerProvider {
    ComPtr<ABI::Windows::Devices::Spi::Provider::ISpiControllerProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpiControllerProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDSPISpiControllerProvider>(unmarshalledReturn.Get());
}

@end

@implementation WDLowLevelDevicesController

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::ILowLevelDevicesController> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Devices::ILowLevelDevicesControllerStatics> WDILowLevelDevicesControllerStatics_inst() {
    ComPtr<ABI::Windows::Devices::ILowLevelDevicesControllerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.LowLevelDevicesController").Get(), &inst));
    return inst;
}

+ (RTObject<WDILowLevelDevicesAggregateProvider>*)defaultProvider {
    ComPtr<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider> unmarshalledReturn;
    auto _comInst = WDILowLevelDevicesControllerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DefaultProvider(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDILowLevelDevicesAggregateProvider>(unmarshalledReturn.Get());
}

+ (void)setDefaultProvider:(RTObject<WDILowLevelDevicesAggregateProvider>*)value {
    auto _comInst = WDILowLevelDevicesControllerStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->put_DefaultProvider(_getRtInterface<ABI::Windows::Devices::ILowLevelDevicesAggregateProvider>(value).Get()));
}

@end
