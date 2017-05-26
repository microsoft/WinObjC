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

// WindowsDevicesAdcProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Adc.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesAdcProvider.h"
#include "WindowsDevicesAdcProvider_priv.h"

@implementation WDAPIAdcControllerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)channelCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChannelCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)resolutionInBits {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ResolutionInBits(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)minValue {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)maxValue {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDAPProviderAdcChannelMode)channelMode {
    ABI::Windows::Devices::Adc::Provider::ProviderAdcChannelMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChannelMode(&unmarshalledReturn));
    return (WDAPProviderAdcChannelMode)unmarshalledReturn;
}

- (void)setChannelMode:(WDAPProviderAdcChannelMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->put_ChannelMode((ABI::Windows::Devices::Adc::Provider::ProviderAdcChannelMode)value));
}

- (BOOL)isChannelModeSupported:(WDAPProviderAdcChannelMode)channelMode {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->IsChannelModeSupported((ABI::Windows::Devices::Adc::Provider::ProviderAdcChannelMode)channelMode, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)acquireChannel:(int)channel {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AcquireChannel(channel));
}

- (void)releaseChannel:(int)channel {
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ReleaseChannel(channel));
}

- (int)readValue:(int)channelNumber {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ReadValue(channelNumber, &unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WDAPIAdcProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Devices::Adc::Provider::IAdcProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject<WDAPIAdcControllerProvider>* */)getControllers {
    ComPtr<IVectorView<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Devices::Adc::Provider::IAdcProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetControllers(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WDAPIAdcControllerProvider_create(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_RTObject_WDAPIAdcControllerProvider_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider*>,
                                         RTArrayObj<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider*,
                                                    IVectorView<ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider*>,
                                                    RTObject<WDAPIAdcControllerProvider>,
                                                    ABI::Windows::Devices::Adc::Provider::IAdcControllerProvider*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
