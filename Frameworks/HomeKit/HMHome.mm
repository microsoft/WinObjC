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

#import <StubReturn.h>

#import <HomeKit/HMHome.h>
#import "AssertARCEnabled.h"

NSString* const HMUserFailedAccessoriesKey = @"HMUserFailedAccessoriesKey";

@implementation HMHome

/**
 @Status Stub
 @Notes
*/
- (void)updateName:(NSString*)name completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addAccessory:(HMAccessory*)accessory completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)assignAccessory:(HMAccessory*)accessory toRoom:(HMRoom*)room completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeAccessory:(HMAccessory*)accessory completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)unblockAccessory:(HMAccessory*)accessory completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (HMRoom*)roomForEntireHome {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addRoomWithName:(NSString*)roomName completionHandler:(void (^)(HMRoom*, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeRoom:(HMRoom*)room completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addZoneWithName:(NSString*)zoneName completionHandler:(void (^)(HMZone*, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeZone:(HMZone*)zone completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)servicesWithTypes:(NSArray*)serviceTypes {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addServiceGroupWithName:(NSString*)serviceGroupName completionHandler:(void (^)(HMServiceGroup*, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeServiceGroup:(HMServiceGroup*)group completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addActionSetWithName:(NSString*)actionSetName completionHandler:(void (^)(HMActionSet*, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeActionSet:(HMActionSet*)actionSet completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)executeActionSet:(HMActionSet*)actionSet completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addTrigger:(HMTrigger*)trigger completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeTrigger:(HMTrigger*)trigger completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addUserWithCompletionHandler:(void (^)(HMUser*, NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeUser:(HMUser*)user completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

@end
