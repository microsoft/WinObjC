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

// WindowsApplicationModelUserActivitiesCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESCOREEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESCOREEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelUserActivitiesCore.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAUCCoreUserActivityManager;
@protocol WAUCICoreUserActivityManagerStatics;

#include "WindowsApplicationModelUserActivities.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserActivities.Core.CoreUserActivityManager
#ifndef __WAUCCoreUserActivityManager_DEFINED__
#define __WAUCCoreUserActivityManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERACTIVITIESCOREEXPORT
@interface WAUCCoreUserActivityManager : RTObject
+ (WAUUserActivitySession*)createUserActivitySessionInBackground:(WAUUserActivity*)activity;
+ (RTObject<WFIAsyncAction>*)deleteUserActivitySessionsInTimeRangeAsync:(WAUUserActivityChannel*)channel startTime:(WFDateTime*)startTime endTime:(WFDateTime*)endTime;
@end

#endif // __WAUCCoreUserActivityManager_DEFINED__

