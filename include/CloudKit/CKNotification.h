//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#pragma once

#import <CloudKit/CloudKitExport.h>
#import <Foundation/NSObject.h>

@class NSDictionary;
@class CKNotificationID;
@class NSString;
@class NSArray;
@class NSNumber;

typedef enum CKNotificationType : NSInteger {
    CKNotificationTypeQuery = 1,
    CKNotificationTypeRecordZone = 2,
    CKNotificationTypeReadNotification = 3,
} CKNotificationType;

CLOUDKIT_EXPORT_CLASS
@interface CKNotification : NSObject
+ (instancetype)notificationFromRemoteNotificationDictionary:(NSDictionary*)notificationDictionary STUB_METHOD;
@property (readonly, copy, nonatomic) CKNotificationID* notificationID STUB_PROPERTY;
@property (readonly, assign, nonatomic) CKNotificationType notificationType STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* containerIdentifier STUB_PROPERTY;
@property (readonly, assign, nonatomic) BOOL isPruned STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* alertBody STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* alertLocalizationKey STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* alertLocalizationArgs STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* alertActionLocalizationKey STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* alertLaunchImage STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* soundName STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSNumber* badge STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* category STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* subscriptionID STUB_PROPERTY;
@end