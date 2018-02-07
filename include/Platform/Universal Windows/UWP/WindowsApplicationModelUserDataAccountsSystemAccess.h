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

// WindowsApplicationModelUserDataAccountsSystemAccess.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSAPPLICATIONMODELUSERDATAACCOUNTSSYSTEMACCESSEXPORT
#define OBJCUWPWINDOWSAPPLICATIONMODELUSERDATAACCOUNTSSYSTEMACCESSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsApplicationModelUserDataAccountsSystemAccess.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WAUSDeviceAccountConfiguration, WAUSUserDataAccountSystemAccessManager;
@protocol WAUSIDeviceAccountConfiguration, WAUSIDeviceAccountConfiguration2, WAUSIUserDataAccountSystemAccessManagerStatics, WAUSIUserDataAccountSystemAccessManagerStatics2;

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountServerType
enum _WAUSDeviceAccountServerType {
    WAUSDeviceAccountServerTypeExchange = 0,
    WAUSDeviceAccountServerTypePop = 1,
    WAUSDeviceAccountServerTypeImap = 2,
};
typedef unsigned WAUSDeviceAccountServerType;

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountAuthenticationType
enum _WAUSDeviceAccountAuthenticationType {
    WAUSDeviceAccountAuthenticationTypeBasic = 0,
    WAUSDeviceAccountAuthenticationTypeOAuth = 1,
    WAUSDeviceAccountAuthenticationTypeSingleSignOn = 2,
};
typedef unsigned WAUSDeviceAccountAuthenticationType;

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountSyncScheduleKind
enum _WAUSDeviceAccountSyncScheduleKind {
    WAUSDeviceAccountSyncScheduleKindManual = 0,
    WAUSDeviceAccountSyncScheduleKindEvery15Minutes = 1,
    WAUSDeviceAccountSyncScheduleKindEvery30Minutes = 2,
    WAUSDeviceAccountSyncScheduleKindEvery60Minutes = 3,
    WAUSDeviceAccountSyncScheduleKindEvery2Hours = 4,
    WAUSDeviceAccountSyncScheduleKindDaily = 5,
    WAUSDeviceAccountSyncScheduleKindAsItemsArrive = 6,
};
typedef unsigned WAUSDeviceAccountSyncScheduleKind;

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountMailAgeFilter
enum _WAUSDeviceAccountMailAgeFilter {
    WAUSDeviceAccountMailAgeFilterAll = 0,
    WAUSDeviceAccountMailAgeFilterLast1Day = 1,
    WAUSDeviceAccountMailAgeFilterLast3Days = 2,
    WAUSDeviceAccountMailAgeFilterLast7Days = 3,
    WAUSDeviceAccountMailAgeFilterLast14Days = 4,
    WAUSDeviceAccountMailAgeFilterLast30Days = 5,
    WAUSDeviceAccountMailAgeFilterLast90Days = 6,
};
typedef unsigned WAUSDeviceAccountMailAgeFilter;

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountIconId
enum _WAUSDeviceAccountIconId {
    WAUSDeviceAccountIconIdExchange = 0,
    WAUSDeviceAccountIconIdMsa = 1,
    WAUSDeviceAccountIconIdOutlook = 2,
    WAUSDeviceAccountIconIdGeneric = 3,
};
typedef unsigned WAUSDeviceAccountIconId;

#include "WindowsSecurityCredentials.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.DeviceAccountConfiguration
#ifndef __WAUSDeviceAccountConfiguration_DEFINED__
#define __WAUSDeviceAccountConfiguration_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATAACCOUNTSSYSTEMACCESSEXPORT
@interface WAUSDeviceAccountConfiguration : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * emailAddress;
@property (retain) NSString * domain;
@property (retain) NSString * deviceAccountTypeId;
@property (retain) NSString * outgoingServerAddress;
@property BOOL contactsSyncEnabled;
@property BOOL calendarSyncEnabled;
@property (retain) NSString * accountName;
@property (retain) NSString * incomingServerUsername;
@property BOOL incomingServerRequiresSsl;
@property int incomingServerPort;
@property (retain) NSString * incomingServerAddress;
@property BOOL emailSyncEnabled;
@property WAUSDeviceAccountServerType serverType;
@property (retain) NSString * outgoingServerUsername;
@property BOOL outgoingServerRequiresSsl;
@property int outgoingServerPort;
@property WAUSDeviceAccountIconId accountIconId;
@property (retain) WFUri* calDavServerUrl;
@property BOOL calDavRequiresSsl;
@property BOOL autoSelectAuthenticationCertificate;
@property WAUSDeviceAccountAuthenticationType authenticationType;
@property (retain) NSString * authenticationCertificateId;
@property BOOL isOutgoingServerAuthenticationEnabled;
@property BOOL isClientAuthenticationCertificateRequired;
@property (retain) WSCPasswordCredential* incomingServerCredential;
@property BOOL isOutgoingServerAuthenticationRequired;
@property WAUSDeviceAccountSyncScheduleKind cardDavSyncScheduleKind;
@property BOOL alwaysDownloadFullMessage;
@property (retain) WFUri* cardDavServerUrl;
@property BOOL cardDavRequiresSsl;
@property WAUSDeviceAccountSyncScheduleKind calDavSyncScheduleKind;
@property (retain) NSString * incomingServerCertificateHash;
@property BOOL wasOutgoingServerCertificateHashConfirmed;
@property BOOL wasModifiedByUser;
@property WAUSDeviceAccountSyncScheduleKind syncScheduleKind;
@property (retain) NSString * ssoAccountId;
@property BOOL wasIncomingServerCertificateHashConfirmed;
@property (retain) NSString * oAuthRefreshToken;
@property BOOL isExternallyManaged;
@property WAUSDeviceAccountMailAgeFilter mailAgeFilter;
@property BOOL isSyncScheduleManagedBySystem;
@property (retain) NSString * outgoingServerCertificateHash;
@property (retain) WSCPasswordCredential* outgoingServerCredential;
@property (readonly) BOOL doesPolicyAllowMailSync;
@property (readonly) BOOL isSsoAuthenticationSupported;
@end

#endif // __WAUSDeviceAccountConfiguration_DEFINED__

// Windows.ApplicationModel.UserDataAccounts.SystemAccess.UserDataAccountSystemAccessManager
#ifndef __WAUSUserDataAccountSystemAccessManager_DEFINED__
#define __WAUSUserDataAccountSystemAccessManager_DEFINED__

OBJCUWPWINDOWSAPPLICATIONMODELUSERDATAACCOUNTSSYSTEMACCESSEXPORT
@interface WAUSUserDataAccountSystemAccessManager : RTObject
+ (RTObject<WFIAsyncAction>*)suppressLocalAccountWithAccountAsync:(NSString *)userDataAccountId;
+ (void)createDeviceAccountAsync:(WAUSDeviceAccountConfiguration*)account success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
+ (RTObject<WFIAsyncAction>*)deleteDeviceAccountAsync:(NSString *)accountId;
+ (void)getDeviceAccountConfigurationAsync:(NSString *)accountId success:(void (^)(WAUSDeviceAccountConfiguration*))success failure:(void (^)(NSError*))failure;
+ (void)addAndShowDeviceAccountsAsync:(id<NSFastEnumeration> /* WAUSDeviceAccountConfiguration* */)accounts success:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WAUSUserDataAccountSystemAccessManager_DEFINED__

