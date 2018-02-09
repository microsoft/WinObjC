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

// WindowsManagement.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSMANAGEMENTEXPORT
#define OBJCUWPWINDOWSMANAGEMENTEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsManagement.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WMMdmAlert, WMMdmSession, WMMdmSessionManager;
@protocol WMIMdmAlert, WMIMdmSession, WMIMdmSessionManagerStatics;

// Windows.Management.MdmAlertMark
enum _WMMdmAlertMark {
    WMMdmAlertMarkNone = 0,
    WMMdmAlertMarkFatal = 1,
    WMMdmAlertMarkCritical = 2,
    WMMdmAlertMarkWarning = 3,
    WMMdmAlertMarkInformational = 4,
};
typedef unsigned WMMdmAlertMark;

// Windows.Management.MdmAlertDataType
enum _WMMdmAlertDataType {
    WMMdmAlertDataTypeString = 0,
    WMMdmAlertDataTypeBase64 = 1,
    WMMdmAlertDataTypeBoolean = 2,
    WMMdmAlertDataTypeInteger = 3,
};
typedef unsigned WMMdmAlertDataType;

// Windows.Management.MdmSessionState
enum _WMMdmSessionState {
    WMMdmSessionStateNotStarted = 0,
    WMMdmSessionStateStarting = 1,
    WMMdmSessionStateConnecting = 2,
    WMMdmSessionStateCommunicating = 3,
    WMMdmSessionStateAlertStatusAvailable = 4,
    WMMdmSessionStateRetrying = 5,
    WMMdmSessionStateCompleted = 6,
};
typedef unsigned WMMdmSessionState;

#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Management.MdmAlert
#ifndef __WMMdmAlert_DEFINED__
#define __WMMdmAlert_DEFINED__

OBJCUWPWINDOWSMANAGEMENTEXPORT
@interface WMMdmAlert : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * type;
@property (retain) NSString * target;
@property (retain) NSString * source;
@property WMMdmAlertMark mark;
@property WMMdmAlertDataType format;
@property (retain) NSString * data;
@property (readonly) unsigned int status;
@end

#endif // __WMMdmAlert_DEFINED__

// Windows.Management.MdmSession
#ifndef __WMMdmSession_DEFINED__
#define __WMMdmSession_DEFINED__

OBJCUWPWINDOWSMANAGEMENTEXPORT
@interface WMMdmSession : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WMMdmAlert* */ alerts;
@property (readonly) HRESULT extendedError;
@property (readonly) NSString * id;
@property (readonly) WMMdmSessionState state;
- (RTObject<WFIAsyncAction>*)attachAsync;
- (void)Delete;
- (RTObject<WFIAsyncAction>*)startAsync;
- (RTObject<WFIAsyncAction>*)startWithAlertsAsync:(id<NSFastEnumeration> /* WMMdmAlert* */)alerts;
@end

#endif // __WMMdmSession_DEFINED__

// Windows.Management.MdmSessionManager
#ifndef __WMMdmSessionManager_DEFINED__
#define __WMMdmSessionManager_DEFINED__

OBJCUWPWINDOWSMANAGEMENTEXPORT
@interface WMMdmSessionManager : RTObject
+ (WMMdmSession*)tryCreateSession;
+ (void)deleteSessionById:(NSString *)sessionId;
+ (WMMdmSession*)getSessionById:(NSString *)sessionId;
+ (NSArray* /* NSString * */)sessionIds;
@end

#endif // __WMMdmSessionManager_DEFINED__

