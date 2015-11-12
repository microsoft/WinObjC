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

#include "interopBase.h"
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

WINRT_EXPORT
@interface WAEExtendedExecutionRevokedEventArgs : RTObject
@property (readonly) WAEExtendedExecutionRevokedReason reason;
@end

#endif // __WAEExtendedExecutionRevokedEventArgs_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.ApplicationModel.ExtendedExecution.ExtendedExecutionSession
#ifndef __WAEExtendedExecutionSession_DEFINED__
#define __WAEExtendedExecutionSession_DEFINED__

WINRT_EXPORT
@interface WAEExtendedExecutionSession : RTObject <WFIClosable>
+ (instancetype)create ACTIVATOR;
@property WAEExtendedExecutionReason reason;
@property unsigned int percentProgress;
@property (copy) NSString* description;
- (EventRegistrationToken)addRevokedEvent:(void (^)(RTObject*, WAEExtendedExecutionRevokedEventArgs*))del;
- (void)removeRevokedEvent:(EventRegistrationToken)tok;
- (void)requestExtensionAsyncWithSuccess:(void (^)(WAEExtendedExecutionResult))success failure:(void (^)(NSError*))failure;
- (void)close;
@end

#endif // __WAEExtendedExecutionSession_DEFINED__
