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

// WindowsMediaCorePreview.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMEDIACOREPREVIEWEXPORT
#define OBJCUWPWINDOWSMEDIACOREPREVIEWEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsMediaCorePreview.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMCPSoundLevelBroker;
@protocol WMCPISoundLevelBrokerStatics;

#include "WindowsMedia.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Media.Core.Preview.SoundLevelBroker
#ifndef __WMCPSoundLevelBroker_DEFINED__
#define __WMCPSoundLevelBroker_DEFINED__

OBJCUWPWINDOWSMEDIACOREPREVIEWEXPORT
@interface WMCPSoundLevelBroker : RTObject
+ (WMSoundLevel)soundLevel;
+ (EventRegistrationToken)addSoundLevelChangedEvent:(void(^)(RTObject*, RTObject*))del;
+ (void)removeSoundLevelChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WMCPSoundLevelBroker_DEFINED__

