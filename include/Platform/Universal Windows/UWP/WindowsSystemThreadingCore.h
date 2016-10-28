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

// WindowsSystemThreadingCore.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_SYSTEM_THREADING_CORE_EXPORT
#define OBJCUWP_WINDOWS_SYSTEM_THREADING_CORE_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_System_Threading_Core.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WSTCSignalNotifier, WSTCPreallocatedWorkItem;
@protocol WSTCISignalNotifierStatics
, WSTCIPreallocatedWorkItemFactory, WSTCIPreallocatedWorkItem, WSTCISignalNotifier;

#include "WindowsFoundation.h"
#include "WindowsSystemThreading.h"
// Windows.System.Threading.Core.SignalHandler
#ifndef __WSTCSignalHandler__DEFINED
#define __WSTCSignalHandler__DEFINED
typedef void (^WSTCSignalHandler)(WSTCSignalNotifier* signalNotifier, BOOL timedOut);
#endif // __WSTCSignalHandler__DEFINED

// Windows.System.Threading.WorkItemHandler
#ifndef __WSTWorkItemHandler__DEFINED
#define __WSTWorkItemHandler__DEFINED
typedef void (^WSTWorkItemHandler)(RTObject<WFIAsyncAction>* operation);
#endif // __WSTWorkItemHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.System.Threading.Core.SignalHandler
#ifndef __WSTCSignalHandler__DEFINED
#define __WSTCSignalHandler__DEFINED
typedef void (^WSTCSignalHandler)(WSTCSignalNotifier* signalNotifier, BOOL timedOut);
#endif // __WSTCSignalHandler__DEFINED

// Windows.System.Threading.Core.SignalNotifier
#ifndef __WSTCSignalNotifier_DEFINED__
#define __WSTCSignalNotifier_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_THREADING_CORE_EXPORT
@interface WSTCSignalNotifier : RTObject
+ (WSTCSignalNotifier*)attachToEvent:(NSString*)name handler:(WSTCSignalHandler)handler;
+ (WSTCSignalNotifier*)attachToEventWithTimeout:(NSString*)name handler:(WSTCSignalHandler)handler timeout:(WFTimeSpan*)timeout;
+ (WSTCSignalNotifier*)attachToSemaphore:(NSString*)name handler:(WSTCSignalHandler)handler;
+ (WSTCSignalNotifier*)attachToSemaphoreWithTimeout:(NSString*)name handler:(WSTCSignalHandler)handler timeout:(WFTimeSpan*)timeout;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (void)enable;
- (void)terminate;
@end

#endif // __WSTCSignalNotifier_DEFINED__

// Windows.System.Threading.Core.PreallocatedWorkItem
#ifndef __WSTCPreallocatedWorkItem_DEFINED__
#define __WSTCPreallocatedWorkItem_DEFINED__

OBJCUWP_WINDOWS_SYSTEM_THREADING_CORE_EXPORT
@interface WSTCPreallocatedWorkItem : RTObject
+ (WSTCPreallocatedWorkItem*)makeWorkItem:(WSTWorkItemHandler)handler ACTIVATOR;
+ (WSTCPreallocatedWorkItem*)makeWorkItemWithPriority:(WSTWorkItemHandler)handler priority:(WSTWorkItemPriority)priority ACTIVATOR;
+ (WSTCPreallocatedWorkItem*)makeWorkItemWithPriorityAndOptions:(WSTWorkItemHandler)handler
                                                       priority:(WSTWorkItemPriority)priority
                                                        options:(WSTWorkItemOptions)options ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
- (RTObject<WFIAsyncAction>*)runAsync;
@end

#endif // __WSTCPreallocatedWorkItem_DEFINED__
