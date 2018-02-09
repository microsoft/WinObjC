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

// WindowsApplicationModelCommunicationBlocking.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELCOMMUNICATIONBLOCKINGEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELCOMMUNICATIONBLOCKINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelCommunicationBlocking.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WACCommunicationBlockingAppManager, WACCommunicationBlockingAccessManager;
@protocol WACICommunicationBlockingAppManagerStatics, WACICommunicationBlockingAppManagerStatics2, WACICommunicationBlockingAccessManagerStatics;

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAppManager
#ifndef __WACCommunicationBlockingAppManager_DEFINED__
#define __WACCommunicationBlockingAppManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCOMMUNICATIONBLOCKINGEXPORT
@interface WACCommunicationBlockingAppManager : RTObject
+ (void)showCommunicationBlockingSettingsUI;
+ (void)requestSetAsActiveBlockingAppAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (void)showCommunicationBlockingSettingsUI;
+ (BOOL)isCurrentAppActiveBlockingApp;
@end

#endif // __WACCommunicationBlockingAppManager_DEFINED__

// Windows.ApplicationModel.CommunicationBlocking.CommunicationBlockingAccessManager
#ifndef __WACCommunicationBlockingAccessManager_DEFINED__
#define __WACCommunicationBlockingAccessManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELCOMMUNICATIONBLOCKINGEXPORT
@interface WACCommunicationBlockingAccessManager : RTObject
+ (void)isBlockedNumberAsync:(NSString *)number success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
+ (BOOL)showBlockNumbersUI:(id<NSFastEnumeration> /* NSString * */)phoneNumbers;
+ (BOOL)showUnblockNumbersUI:(id<NSFastEnumeration> /* NSString * */)phoneNumbers;
+ (void)showBlockedCallsUI;
+ (void)showBlockedMessagesUI;
+ (BOOL)isBlockingActive;
@end

#endif // __WACCommunicationBlockingAccessManager_DEFINED__

