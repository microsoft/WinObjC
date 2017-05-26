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

// WindowsPhoneDevicesNotification.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.Devices.Notification.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneDevicesNotification.h"
#include "WindowsPhoneDevicesNotification_priv.h"

@implementation WPDNVibrationDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Devices::Notification::IVibrationDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Phone::Devices::Notification::IVibrationDeviceStatics> WPDNIVibrationDeviceStatics_inst() {
    ComPtr<ABI::Windows::Phone::Devices::Notification::IVibrationDeviceStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.Devices.Notification.VibrationDevice").Get(),
                                                       &inst));
    return inst;
}

+ (WPDNVibrationDevice*)getDefault {
    ComPtr<ABI::Windows::Phone::Devices::Notification::IVibrationDevice> unmarshalledReturn;
    auto _comInst = WPDNIVibrationDeviceStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPDNVibrationDevice>(unmarshalledReturn.Get());
}

- (void)vibrate:(WFTimeSpan*)duration {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Devices::Notification::IVibrationDevice>(self);
    THROW_NS_IF_FAILED(_comInst->Vibrate(*[duration internalStruct]));
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Devices::Notification::IVibrationDevice>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

@end
