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

// WindowsApplicationModelUserDataAccountsSystemAccess.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WAUSDeviceAccountConfiguration, WAUSUserDataAccountSystemAccessManager;
@protocol WAUSIDeviceAccountConfiguration
, WAUSIUserDataAccountSystemAccessManagerStatics;

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountServerType
enum _WAUSDeviceAccountServerType {
    WAUSDeviceAccountServerTypeExchange = 0,
    WAUSDeviceAccountServerTypePop = 1,
    WAUSDeviceAccountServerTypeImap = 2,
};
typedef unsigned WAUSDeviceAccountServerType;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountConfiguration
#ifndef __WAUSDeviceAccountConfiguration_DEFINED__
#define __WAUSDeviceAccountConfiguration_DEFINED__

WINRT_EXPORT
@interface WAUSDeviceAccountConfiguration : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* incomingServerAddress;
@property (copy) NSString* incomingServerUsername;
@property (copy) NSString* emailAddress;
@property (copy) NSString* accountName;
@property (copy) NSString* deviceAccountTypeId;
@property BOOL calendarSyncEnabled;
@property (copy) NSString* domain;
@property int incomingServerPort;
@property WAUSDeviceAccountServerType serverType;
@property (copy) NSString* outgoingServerUsername;
@property BOOL contactsSyncEnabled;
@property BOOL outgoingServerRequiresSsl;
@property int outgoingServerPort;
@property (copy) NSString* outgoingServerAddress;
@property BOOL emailSyncEnabled;
@property BOOL incomingServerRequiresSsl;
@end

#endif // __WAUSDeviceAccountConfiguration_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.UserDataAccountSystemAccessManager
#ifndef __WAUSUserDataAccountSystemAccessManager_DEFINED__
#define __WAUSUserDataAccountSystemAccessManager_DEFINED__

WINRT_EXPORT
@interface WAUSUserDataAccountSystemAccessManager : RTObject
+ (void)addAndShowDeviceAccountsAsync:(id<NSFastEnumeration> /* WAUSDeviceAccountConfiguration* */)accounts
                              success:(void (^)(NSArray*))success
                              failure:(void (^)(NSError*))failure;
@end

#endif // __WAUSUserDataAccountSystemAccessManager_DEFINED__
