//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsPhoneMediaDevices.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONEMEDIADEVICESEXPORT
#define OBJCUWPWINDOWSPHONEMEDIADEVICESEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhoneMediaDevices.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPMDAudioRoutingManager;
@protocol WPMDIAudioRoutingManager, WPMDIAudioRoutingManagerStatics;

// Windows.Phone.Media.Devices.AudioRoutingEndpoint
enum _WPMDAudioRoutingEndpoint {
    WPMDAudioRoutingEndpointDefault = 0,
    WPMDAudioRoutingEndpointEarpiece = 1,
    WPMDAudioRoutingEndpointSpeakerphone = 2,
    WPMDAudioRoutingEndpointBluetooth = 3,
    WPMDAudioRoutingEndpointWiredHeadset = 4,
    WPMDAudioRoutingEndpointWiredHeadsetSpeakerOnly = 5,
    WPMDAudioRoutingEndpointBluetoothWithNoiseAndEchoCancellation = 6,
    WPMDAudioRoutingEndpointBluetoothPreferred = 7,
};
typedef unsigned WPMDAudioRoutingEndpoint;

// Windows.Phone.Media.Devices.AvailableAudioRoutingEndpoints
enum _WPMDAvailableAudioRoutingEndpoints {
    WPMDAvailableAudioRoutingEndpointsNone = 0,
    WPMDAvailableAudioRoutingEndpointsEarpiece = 1,
    WPMDAvailableAudioRoutingEndpointsSpeakerphone = 2,
    WPMDAvailableAudioRoutingEndpointsBluetooth = 4,
};
typedef unsigned WPMDAvailableAudioRoutingEndpoints;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Phone.Media.Devices.AudioRoutingManager
#ifndef __WPMDAudioRoutingManager_DEFINED__
#define __WPMDAudioRoutingManager_DEFINED__

OBJCUWPWINDOWSPHONEMEDIADEVICESEXPORT
@interface WPMDAudioRoutingManager : RTObject
+ (WPMDAudioRoutingManager*)getDefault;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WPMDAvailableAudioRoutingEndpoints availableAudioEndpoints;
- (EventRegistrationToken)addAudioEndpointChangedEvent:(void(^)(WPMDAudioRoutingManager*, RTObject*))del;
- (void)removeAudioEndpointChangedEvent:(EventRegistrationToken)tok;
- (WPMDAudioRoutingEndpoint)getAudioEndpoint;
- (void)setAudioEndpoint:(WPMDAudioRoutingEndpoint)endpoint;
@end

#endif // __WPMDAudioRoutingManager_DEFINED__

