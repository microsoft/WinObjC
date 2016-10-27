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

// WindowsApplicationModelExtendedExecution.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_APPLICATIONMODEL_EXTENDEDEXECUTION_EXPORT
#define OBJCUWP_WINDOWS_APPLICATIONMODEL_EXTENDEDEXECUTION_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_ApplicationModel_ExtendedExecution.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAEExtendedExecutionRevokedEventArgs, WAEExtendedExecutionSession;
@protocol WAEIExtendedExecutionRevokedEventArgs
, WAEIExtendedExecutionSession;

// Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionReason
enum _WAEExtendedExecutionReason {
    WAEExtendedExecutionReasonUnspecified = 0,
    WAEExtendedExecutionReasonLocationTracking = 1,
    WAEExtendedExecutionReasonSavingData = 2,
};
typedef unsigned WAEExtendedExecutionReason;

// Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionResult
enum _WAEExtendedExecutionResult {
    WAEExtendedExecutionResultAllowed = 0,
    WAEExtendedExecutionResultDenied = 1,
};
typedef unsigned WAEExtendedExecutionResult;

// Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionRevokedReason
enum _WAEExtendedExecutionRevokedReason {
    WAEExtendedExecutionRevokedReasonResumed = 0,
    WAEExtendedExecutionRevokedReasonSystemPolicy = 1,
};
typedef unsigned WAEExtendedExecutionRevokedReason;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionRevokedEventArgs
#ifndef __WAEExtendedExecutionRevokedEventArgs_DEFINED__
#define __WAEExtendedExecutionRevokedEventArgs_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_EXTENDEDEXECUTION_EXPORT
@interface WAEExtendedExecutionRevokedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property (readonly) WAEExtendedExecutionRevokedReason reason;
@end

#endif // __WAEExtendedExecutionRevokedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

OBJCUWP_WINDOWS_APPLICATIONMODEL_EXTENDEDEXECUTION_EXPORT
@interface WFIClosable : RTObject <WFIClosable>
@end

#endif // __WFIClosable_DEFINED__

// Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionSession
#ifndef __WAEExtendedExecutionSession_DEFINED__
#define __WAEExtendedExecutionSession_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_EXTENDEDEXECUTION_EXPORT
@interface WAEExtendedExecutionSession : RTObject <WFIClosable>
+ (instancetype)make ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj;
#endif
@property WAEExtendedExecutionReason reason;
@property unsigned int percentProgress;
@property (retain) NSString* Description;
- (EventRegistrationToken)addRevokedEvent:(void (^)(RTObject*, WAEExtendedExecutionRevokedEventArgs*))del;
- (void)removeRevokedEvent:(EventRegistrationToken)tok;
- (void)requestExtensionAsyncWithSuccess:(void (^)(WAEExtendedExecutionResult))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WAEExtendedExecutionSession_DEFINED__
