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

// WindowsPerceptionPeople.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPERCEPTIONPEOPLEEXPORT
#define OBJCUWPWINDOWSPERCEPTIONPEOPLEEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPerceptionPeople.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPPHeadPose;
@protocol WPPIHeadPose;

#include "WindowsFoundationNumerics.h"

#import <Foundation/Foundation.h>

// Windows.Perception.People.HeadPose
#ifndef __WPPHeadPose_DEFINED__
#define __WPPHeadPose_DEFINED__

OBJCUWPWINDOWSPERCEPTIONPEOPLEEXPORT
@interface WPPHeadPose : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFNVector3* forwardDirection;
@property (readonly) WFNVector3* position;
@property (readonly) WFNVector3* upDirection;
@end

#endif // __WPPHeadPose_DEFINED__

