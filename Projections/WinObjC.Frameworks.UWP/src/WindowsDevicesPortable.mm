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

// WindowsDevicesPortable.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Devices.Portable.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsDevicesPortable.h"
#include "WindowsDevicesPortable_priv.h"

@implementation WDPStorageDevice

ComPtr<ABI::Windows::Devices::Portable::IStorageDeviceStatics> WDPIStorageDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Portable::IStorageDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Portable.StorageDevice").Get(), &inst));
    return inst;
}

+ (WSStorageFolder*)fromId:(NSString*)deviceId {
    ComPtr<ABI::Windows::Storage::IStorageFolder> unmarshalledReturn;
    auto _comInst = WDPIStorageDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromId(nsStrToHstr(deviceId).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFolder>(unmarshalledReturn.Get());
}

+ (NSString*)getDeviceSelector {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIStorageDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WDPServiceDevice

ComPtr<ABI::Windows::Devices::Portable::IServiceDeviceStatics> WDPIServiceDeviceStatics_inst() {
    ComPtr<ABI::Windows::Devices::Portable::IServiceDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Devices.Portable.ServiceDevice").Get(), &inst));
    return inst;
}

+ (NSString*)getDeviceSelector:(WDPServiceDeviceType)serviceType {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIServiceDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelector((ABI::Windows::Devices::Portable::ServiceDeviceType)serviceType, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (NSString*)getDeviceSelectorFromServiceId:(WFGUID*)serviceId {
    HSTRING unmarshalledReturn;
    auto _comInst = WDPIServiceDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDeviceSelectorFromServiceId(serviceId.guidValue, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end
