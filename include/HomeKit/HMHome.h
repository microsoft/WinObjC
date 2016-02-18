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

#import <HomeKit/HomeKitExport.h>
#import <Foundation/NSObject.h>

@class NSArray;
@class NSError;
@class NSString;
@class HMAccessory;
@class HMRoom;
@class HMZone;
@class HMServiceGroup;
@class HMActionSet;
@class HMTrigger;
@class HMUser;

@protocol HMHomeDelegate;

HOMEKIT_EXPORT NSString* const HMUserFailedAccessoriesKey;

HOMEKIT_EXPORT_CLASS
@interface HMHome : NSObject
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
- (void)updateName:(NSString*)name completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, getter=isPrimary, nonatomic) BOOL primary STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* accessories STUB_PROPERTY;
- (void)addAccessory:(HMAccessory*)accessory completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)assignAccessory:(HMAccessory*)accessory toRoom:(HMRoom*)room completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)removeAccessory:(HMAccessory*)accessory completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)unblockAccessory:(HMAccessory*)accessory completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* rooms STUB_PROPERTY;
- (HMRoom*)roomForEntireHome STUB_METHOD;
- (void)addRoomWithName:(NSString*)roomName completionHandler:(void (^)(HMRoom*, NSError*))completion STUB_METHOD;
- (void)removeRoom:(HMRoom*)room completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* zones STUB_PROPERTY;
- (void)addZoneWithName:(NSString*)zoneName completionHandler:(void (^)(HMZone*, NSError*))completion STUB_METHOD;
- (void)removeZone:(HMZone*)zone completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (NSArray*)servicesWithTypes:(NSArray*)serviceTypes STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* serviceGroups STUB_PROPERTY;
- (void)addServiceGroupWithName:(NSString*)serviceGroupName completionHandler:(void (^)(HMServiceGroup*, NSError*))completion STUB_METHOD;
- (void)removeServiceGroup:(HMServiceGroup*)group completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* actionSets STUB_PROPERTY;
- (void)addActionSetWithName:(NSString*)actionSetName completionHandler:(void (^)(HMActionSet*, NSError*))completion STUB_METHOD;
- (void)removeActionSet:(HMActionSet*)actionSet completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)executeActionSet:(HMActionSet*)actionSet completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* triggers STUB_PROPERTY;
- (void)addTrigger:(HMTrigger*)trigger completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)removeTrigger:(HMTrigger*)trigger completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)addUserWithCompletionHandler:(void (^)(HMUser*, NSError*))completion STUB_METHOD;
- (void)removeUser:(HMUser*)user completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* users STUB_PROPERTY;
@property (nonatomic, weak) id<HMHomeDelegate> delegate STUB_PROPERTY;

@end
