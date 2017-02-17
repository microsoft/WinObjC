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

// WindowsPerception.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_PERCEPTION_EXPORT
#define OBJCUWP_WINDOWS_PERCEPTION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Perception.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPPerceptionTimestamp, WPPerceptionTimestampHelper;
@protocol WPIPerceptionTimestamp, WPIPerceptionTimestampHelperStatics;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Perception.PerceptionTimestamp
#ifndef __WPPerceptionTimestamp_DEFINED__
#define __WPPerceptionTimestamp_DEFINED__

OBJCUWP_WINDOWS_PERCEPTION_EXPORT
@interface WPPerceptionTimestamp : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* predictionAmount;
@property (readonly) WFDateTime* targetTime;
@end

#endif // __WPPerceptionTimestamp_DEFINED__

// Windows.Perception.PerceptionTimestampHelper
#ifndef __WPPerceptionTimestampHelper_DEFINED__
#define __WPPerceptionTimestampHelper_DEFINED__

OBJCUWP_WINDOWS_PERCEPTION_EXPORT
@interface WPPerceptionTimestampHelper : RTObject
+ (WPPerceptionTimestamp*)fromHistoricalTargetTime:(WFDateTime*)targetTime;
@end

#endif // __WPPerceptionTimestampHelper_DEFINED__

