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

// WindowsPhonePersonalInformationProvisioning.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSPHONEPERSONALINFORMATIONPROVISIONINGEXPORT
#define OBJCUWPWINDOWSPHONEPERSONALINFORMATIONPROVISIONINGEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsPhonePersonalInformationProvisioning.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WPPPContactPartnerProvisioningManager, WPPPMessagePartnerProvisioningManager;
@protocol WPPPIContactPartnerProvisioningManagerStatics, WPPPIContactPartnerProvisioningManagerStatics2, WPPPIMessagePartnerProvisioningManagerStatics;

#include "WindowsPhonePersonalInformation.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// Windows.Phone.PersonalInformation.Provisioning.ContactPartnerProvisioningManager
#ifndef __WPPPContactPartnerProvisioningManager_DEFINED__
#define __WPPPContactPartnerProvisioningManager_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONPROVISIONINGEXPORT
@interface WPPPContactPartnerProvisioningManager : RTObject
+ (RTObject<WFIAsyncAction>*)associateSocialNetworkAccountAsync:(WPPContactStore*)store networkName:(NSString *)networkName networkAccountId:(NSString *)networkAccountId;
+ (RTObject<WFIAsyncAction>*)associateNetworkAccountAsync:(WPPContactStore*)store networkName:(NSString *)networkName networkAccountId:(NSString *)networkAccountId;
+ (RTObject<WFIAsyncAction>*)importVcardToSystemAsync:(RTObject<WSSIInputStream>*)stream;
@end

#endif // __WPPPContactPartnerProvisioningManager_DEFINED__

// Windows.Phone.PersonalInformation.Provisioning.MessagePartnerProvisioningManager
#ifndef __WPPPMessagePartnerProvisioningManager_DEFINED__
#define __WPPPMessagePartnerProvisioningManager_DEFINED__

OBJCUWPWINDOWSPHONEPERSONALINFORMATIONPROVISIONINGEXPORT
@interface WPPPMessagePartnerProvisioningManager : RTObject
+ (RTObject<WFIAsyncAction>*)importSmsToSystemAsync:(BOOL)incoming read:(BOOL)read body:(NSString *)body sender:(NSString *)sender recipients:(NSArray* /* NSString * */)recipients deliveryTime:(WFDateTime*)deliveryTime;
+ (RTObject<WFIAsyncAction>*)importMmsToSystemAsync:(BOOL)incoming read:(BOOL)read subject:(NSString *)subject sender:(NSString *)sender recipients:(NSArray* /* NSString * */)recipients deliveryTime:(WFDateTime*)deliveryTime attachments:(NSArray* /* NSDictionary* < NSString *, RTObject* > */)attachments;
@end

#endif // __WPPPMessagePartnerProvisioningManager_DEFINED__

