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

// WindowsApplicationModelCommunicationBlocking.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWP_WINDOWS_APPLICATIONMODEL_COMMUNICATIONBLOCKING_EXPORT
#define OBJCUWP_WINDOWS_APPLICATIONMODEL_COMMUNICATIONBLOCKING_EXPORT __declspec(dllimport)
#ifndef IN_OBJCUWP_BUILD
#pragma comment(lib, "ObjCUWP_Windows_ApplicationModel_CommunicationBlocking.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACCommunicationBlockingAppManager, WACCommunicationBlockingAccessManager;
@protocol WACICommunicationBlockingAppManagerStatics, WACICommunicationBlockingAppManagerStatics2, WACICommunicationBlockingAccessManagerStatics;

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAppManager
#ifndef __WACCommunicationBlockingAppManager_DEFINED__
#define __WACCommunicationBlockingAppManager_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_COMMUNICATIONBLOCKING_EXPORT
@interface WACCommunicationBlockingAppManager : RTObject
+ (void)requestSetAsActiveBlockingAppAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)showCommunicationBlockingSettingsUI;
+ (void)showCommunicationBlockingSettingsUI;
+ (BOOL)isCurrentAppActiveBlockingApp;
@end

#endif // __WACCommunicationBlockingAppManager_DEFINED__

// Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAccessManager
#ifndef __WACCommunicationBlockingAccessManager_DEFINED__
#define __WACCommunicationBlockingAccessManager_DEFINED__

OBJCUWP_WINDOWS_APPLICATIONMODEL_COMMUNICATIONBLOCKING_EXPORT
@interface WACCommunicationBlockingAccessManager : RTObject
+ (void)isBlockedNumberAsync:(NSString *)number success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (BOOL)showBlockNumbersUI:(id<NSFastEnumeration> /* NSString * */)phoneNumbers;
+ (BOOL)showUnblockNumbersUI:(id<NSFastEnumeration> /* NSString * */)phoneNumbers;
+ (void)showBlockedCallsUI;
+ (void)showBlockedMessagesUI;
+ (BOOL)isBlockingActive;
@end

#endif // __WACCommunicationBlockingAccessManager_DEFINED__

