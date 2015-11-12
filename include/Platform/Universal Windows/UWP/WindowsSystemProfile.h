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

// WindowsSystemProfile.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSPAnalyticsVersionInfo, WSPAnalyticsInfo;
@protocol WSPIAnalyticsInfoStatics
, WSPIAnalyticsVersionInfo;

#import <Foundation/Foundation.h>

// Windows.System.Profile.AnalyticsVersionInfo
#ifndef __WSPAnalyticsVersionInfo_DEFINED__
#define __WSPAnalyticsVersionInfo_DEFINED__

WINRT_EXPORT
@interface WSPAnalyticsVersionInfo : RTObject
@property (readonly) NSString* deviceFamily;
@property (readonly) NSString* deviceFamilyVersion;
@end

#endif // __WSPAnalyticsVersionInfo_DEFINED__

// Windows.System.Profile.AnalyticsInfo
#ifndef __WSPAnalyticsInfo_DEFINED__
#define __WSPAnalyticsInfo_DEFINED__

WINRT_EXPORT
@interface WSPAnalyticsInfo : RTObject
+ (NSString*)deviceForm;
+ (WSPAnalyticsVersionInfo*)versionInfo;
@end

#endif // __WSPAnalyticsInfo_DEFINED__
