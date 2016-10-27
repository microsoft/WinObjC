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

// WindowsManagementOrchestration.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_MANAGEMENT_ORCHESTRATION_EXPORT
#define OBJCUWP_WINDOWS_MANAGEMENT_ORCHESTRATION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_Management_Orchestration.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMOCurrentAppOrchestration, WMOSingleAppModeContext;
@protocol WMOICurrentAppOrchestrationStatics
, WMOICurrentAppOrchestration, WMOISingleAppModeContext;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Management.Orchestration.CurrentAppOrchestration
#ifndef __WMOCurrentAppOrchestration_DEFINED__
#define __WMOCurrentAppOrchestration_DEFINED__

OBJCUWP_WINDOWS_MANAGEMENT_ORCHESTRATION_EXPORT
@interface WMOCurrentAppOrchestration : RTObject
+ (WMOCurrentAppOrchestration*)getForCurrentView;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (WMOSingleAppModeContext*)startSingleAppMode;
@end

#endif // __WMOCurrentAppOrchestration_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_MANAGEMENT_ORCHESTRATION_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.Management.Orchestration.SingleAppModeContext
#ifndef __WMOSingleAppModeContext_DEFINED__
#define __WMOSingleAppModeContext_DEFINED__

OBJCUWP_WINDOWS_MANAGEMENT_ORCHESTRATION_EXPORT
@interface WMOSingleAppModeContext : RTObject <WFIClosable>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)close;
@end

#endif // __WMOSingleAppModeContext_DEFINED__
