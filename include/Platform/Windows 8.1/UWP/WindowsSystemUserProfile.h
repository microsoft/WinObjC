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

// WindowsSystemUserProfile.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WSUAdvertisingManager, WSUUserInformation, WSULockScreen, WSUGlobalizationPreferences;
@protocol WSUIAdvertisingManagerStatics
, WSUIUserInformationStatics, WSUILockScreenStatics, WSUILockScreenImageFeedStatics, WSUIGlobalizationPreferencesStatics;

// Windows.System.UserProfile.AccountPictureKind
enum _WSUAccountPictureKind {
    WSUAccountPictureKindSmallImage = 0,
    WSUAccountPictureKindLargeImage = 1,
    WSUAccountPictureKindVideo = 2,
};
typedef unsigned WSUAccountPictureKind;

// Windows.System.UserProfile.SetAccountPictureResult
enum _WSUSetAccountPictureResult {
    WSUSetAccountPictureResultSuccess = 0,
    WSUSetAccountPictureResultChangeDisabled = 1,
    WSUSetAccountPictureResultLargeOrDynamicError = 2,
    WSUSetAccountPictureResultVideoFrameSizeError = 3,
    WSUSetAccountPictureResultFileSizeError = 4,
    WSUSetAccountPictureResultFailure = 5,
};
typedef unsigned WSUSetAccountPictureResult;

// Windows.System.UserProfile.SetImageFeedResult
enum _WSUSetImageFeedResult {
    WSUSetImageFeedResultSuccess = 0,
    WSUSetImageFeedResultChangeDisabled = 1,
    WSUSetImageFeedResultUserCanceled = 2,
};
typedef unsigned WSUSetImageFeedResult;

#include "WindowsStorage.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorageStreams.h"
#include "WindowsGlobalization.h"

// Windows.System.UserProfile.AdvertisingManager
#ifndef __WSUAdvertisingManager_DEFINED__
#define __WSUAdvertisingManager_DEFINED__

WINRT_EXPORT
@interface WSUAdvertisingManager : RTObject
+ (NSString*)advertisingId;
@end

#endif // __WSUAdvertisingManager_DEFINED__

// Windows.System.UserProfile.UserInformation
#ifndef __WSUUserInformation_DEFINED__
#define __WSUUserInformation_DEFINED__

WINRT_EXPORT
@interface WSUUserInformation : RTObject
+ (RTObject<WSIStorageFile>*)getAccountPicture:(WSUAccountPictureKind)kind;
+ (void)setAccountPictureAsync:(RTObject<WSIStorageFile>*)image
                       success:(void (^)(WSUSetAccountPictureResult))success
                       failure:(void (^)(NSError*))failure;
+ (void)setAccountPicturesAsync:(RTObject<WSIStorageFile>*)smallImage
                     largeImage:(RTObject<WSIStorageFile>*)largeImage
                          video:(RTObject<WSIStorageFile>*)video
                        success:(void (^)(WSUSetAccountPictureResult))success
                        failure:(void (^)(NSError*))failure;
+ (void)setAccountPictureFromStreamAsync:(RTObject<WSSIRandomAccessStream>*)image
                                 success:(void (^)(WSUSetAccountPictureResult))success
                                 failure:(void (^)(NSError*))failure;
+ (void)setAccountPicturesFromStreamsAsync:(RTObject<WSSIRandomAccessStream>*)smallImage
                                largeImage:(RTObject<WSSIRandomAccessStream>*)largeImage
                                     video:(RTObject<WSSIRandomAccessStream>*)video
                                   success:(void (^)(WSUSetAccountPictureResult))success
                                   failure:(void (^)(NSError*))failure;
+ (void)getDisplayNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)getFirstNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)getLastNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)getPrincipalNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (void)getSessionInitiationProtocolUriAsyncWithSuccess:(void (^)(WFUri*))success failure:(void (^)(NSError*))failure;
+ (void)getDomainNameAsyncWithSuccess:(void (^)(NSString*))success failure:(void (^)(NSError*))failure;
+ (BOOL)accountPictureChangeEnabled;
+ (BOOL)nameAccessAllowed;
+ (EventRegistrationToken)addAccountPictureChangedEvent:(void (^)(RTObject*, RTObject*))del;
+ (void)removeAccountPictureChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WSUUserInformation_DEFINED__

// Windows.System.UserProfile.LockScreen
#ifndef __WSULockScreen_DEFINED__
#define __WSULockScreen_DEFINED__

WINRT_EXPORT
@interface WSULockScreen : RTObject
+ (RTObject<WSSIRandomAccessStream>*)getImageStream;
+ (RTObject<WFIAsyncAction>*)setImageFileAsync:(RTObject<WSIStorageFile>*)value;
+ (RTObject<WFIAsyncAction>*)setImageStreamAsync:(RTObject<WSSIRandomAccessStream>*)value;
+ (void)requestSetImageFeedAsync:(WFUri*)syndicationFeedUri
                         success:(void (^)(WSUSetImageFeedResult))success
                         failure:(void (^)(NSError*))failure;
+ (BOOL)tryRemoveImageFeed;
+ (WFUri*)originalImageFile;
@end

#endif // __WSULockScreen_DEFINED__

// Windows.System.UserProfile.GlobalizationPreferences
#ifndef __WSUGlobalizationPreferences_DEFINED__
#define __WSUGlobalizationPreferences_DEFINED__

WINRT_EXPORT
@interface WSUGlobalizationPreferences : RTObject
+ (id<NSFastEnumeration> /*String*/)calendars;
+ (id<NSFastEnumeration> /*String*/)clocks;
+ (id<NSFastEnumeration> /*String*/)currencies;
+ (NSString*)homeGeographicRegion;
+ (id<NSFastEnumeration> /*String*/)languages;
+ (WGDayOfWeek)weekStartsOn;
@end

#endif // __WSUGlobalizationPreferences_DEFINED__
