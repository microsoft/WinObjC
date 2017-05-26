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

// WindowsPhoneMediaDevices.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Phone.Media.Devices.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsPhoneMediaDevices.h"
#include "WindowsPhoneMediaDevices_priv.h"

@implementation WPMDAudioRoutingManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Phone::Media::Devices::IAudioRoutingManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Phone::Media::Devices::IAudioRoutingManagerStatics> WPMDIAudioRoutingManagerStatics_inst() {
    ComPtr<ABI::Windows::Phone::Media::Devices::IAudioRoutingManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Phone.Media.Devices.AudioRoutingManager").Get(),
                                                       &inst));
    return inst;
}

+ (WPMDAudioRoutingManager*)getDefault {
    ComPtr<ABI::Windows::Phone::Media::Devices::IAudioRoutingManager> unmarshalledReturn;
    auto _comInst = WPMDIAudioRoutingManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetDefault(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WPMDAudioRoutingManager>(unmarshalledReturn.Get());
}

- (WPMDAudioRoutingEndpoint)getAudioEndpoint {
    ABI::Windows::Phone::Media::Devices::AudioRoutingEndpoint unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Media::Devices::IAudioRoutingManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetAudioEndpoint(&unmarshalledReturn));
    return (WPMDAudioRoutingEndpoint)unmarshalledReturn;
}

- (void)setAudioEndpoint:(WPMDAudioRoutingEndpoint)endpoint {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Media::Devices::IAudioRoutingManager>(self);
    THROW_NS_IF_FAILED(_comInst->SetAudioEndpoint((ABI::Windows::Phone::Media::Devices::AudioRoutingEndpoint)endpoint));
}

- (EventRegistrationToken)addAudioEndpointChangedEvent:(void (^)(WPMDAudioRoutingManager*, RTObject*))endpointChangeHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Media::Devices::IAudioRoutingManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_AudioEndpointChanged(
        Make<ITypedEventHandler_Windows_Phone_Media_Devices_AudioRoutingManager_System_Object>(endpointChangeHandler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAudioEndpointChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Media::Devices::IAudioRoutingManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AudioEndpointChanged(token));
}

- (WPMDAvailableAudioRoutingEndpoints)availableAudioEndpoints {
    ABI::Windows::Phone::Media::Devices::AvailableAudioRoutingEndpoints unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Phone::Media::Devices::IAudioRoutingManager>(self);
    THROW_NS_IF_FAILED(_comInst->get_AvailableAudioEndpoints(&unmarshalledReturn));
    return (WPMDAvailableAudioRoutingEndpoints)unmarshalledReturn;
}

@end
