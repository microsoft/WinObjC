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

// WindowsSystemThreading.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSTThreadPoolTimer, WSTThreadPool;
@protocol WSTIThreadPoolStatics
, WSTIThreadPoolTimer, WSTIThreadPoolTimerStatics;

// Windows.System.Threading.WorkItemPriority
enum _WSTWorkItemPriority {
    WSTWorkItemPriorityLow = -1,
    WSTWorkItemPriorityNormal = 0,
    WSTWorkItemPriorityHigh = 1,
};
typedef unsigned WSTWorkItemPriority;

// Windows.System.Threading.WorkItemOptions
enum _WSTWorkItemOptions {
    WSTWorkItemOptionsNone = 0,
    WSTWorkItemOptionsTimeSliced = 1,
};
typedef unsigned WSTWorkItemOptions;

#include "WindowsFoundation.h"
// Windows.System.Threading.TimerDestroyedHandler
#ifndef __WSTTimerDestroyedHandler__DEFINED
#define __WSTTimerDestroyedHandler__DEFINED
typedef void (^WSTTimerDestroyedHandler)(WSTThreadPoolTimer* timer);
#endif // __WSTTimerDestroyedHandler__DEFINED

// Windows.System.Threading.TimerElapsedHandler
#ifndef __WSTTimerElapsedHandler__DEFINED
#define __WSTTimerElapsedHandler__DEFINED
typedef void (^WSTTimerElapsedHandler)(WSTThreadPoolTimer* timer);
#endif // __WSTTimerElapsedHandler__DEFINED

// Windows.System.Threading.WorkItemHandler
#ifndef __WSTWorkItemHandler__DEFINED
#define __WSTWorkItemHandler__DEFINED
typedef void (^WSTWorkItemHandler)(RTObject<WFIAsyncAction>* operation);
#endif // __WSTWorkItemHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.System.Threading.TimerElapsedHandler
#ifndef __WSTTimerElapsedHandler__DEFINED
#define __WSTTimerElapsedHandler__DEFINED
typedef void (^WSTTimerElapsedHandler)(WSTThreadPoolTimer* timer);
#endif // __WSTTimerElapsedHandler__DEFINED

// Windows.System.Threading.TimerDestroyedHandler
#ifndef __WSTTimerDestroyedHandler__DEFINED
#define __WSTTimerDestroyedHandler__DEFINED
typedef void (^WSTTimerDestroyedHandler)(WSTThreadPoolTimer* timer);
#endif // __WSTTimerDestroyedHandler__DEFINED

// Windows.System.Threading.WorkItemHandler
#ifndef __WSTWorkItemHandler__DEFINED
#define __WSTWorkItemHandler__DEFINED
typedef void (^WSTWorkItemHandler)(RTObject<WFIAsyncAction>* operation);
#endif // __WSTWorkItemHandler__DEFINED

// Windows.System.Threading.ThreadPoolTimer
#ifndef __WSTThreadPoolTimer_DEFINED__
#define __WSTThreadPoolTimer_DEFINED__

WINRT_EXPORT
@interface WSTThreadPoolTimer : RTObject
+ (WSTThreadPoolTimer*)createPeriodicTimer:(WSTTimerElapsedHandler)handler period:(WFTimeSpan*)period;
+ (WSTThreadPoolTimer*)createTimer:(WSTTimerElapsedHandler)handler delay:(WFTimeSpan*)delay;
+ (WSTThreadPoolTimer*)createPeriodicTimerWithCompletion:(WSTTimerElapsedHandler)handler
                                                  period:(WFTimeSpan*)period
                                               destroyed:(WSTTimerDestroyedHandler)destroyed;
+ (WSTThreadPoolTimer*)createTimerWithCompletion:(WSTTimerElapsedHandler)handler
                                           delay:(WFTimeSpan*)delay
                                       destroyed:(WSTTimerDestroyedHandler)destroyed;
@property (readonly) WFTimeSpan* delay;
@property (readonly) WFTimeSpan* period;
- (void)cancel;
@end

#endif // __WSTThreadPoolTimer_DEFINED__

// Windows.System.Threading.ThreadPool
#ifndef __WSTThreadPool_DEFINED__
#define __WSTThreadPool_DEFINED__

WINRT_EXPORT
@interface WSTThreadPool : RTObject
+ (RTObject<WFIAsyncAction>*)runAsync:(WSTWorkItemHandler)handler;
+ (RTObject<WFIAsyncAction>*)runWithPriorityAsync:(WSTWorkItemHandler)handler priority:(WSTWorkItemPriority)priority;
+ (RTObject<WFIAsyncAction>*)runWithPriorityAndOptionsAsync:(WSTWorkItemHandler)handler
                                                   priority:(WSTWorkItemPriority)priority
                                                    options:(WSTWorkItemOptions)options;
@end

#endif // __WSTThreadPool_DEFINED__
