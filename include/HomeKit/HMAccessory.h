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
@class NSUUID;
@class HMRoom;

@protocol HMAccessoryDelegate;

HOMEKIT_EXPORT_CLASS
@interface HMAccessory : NSObject
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
- (void)updateName:(NSString*)name completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSUUID* identifier STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* services STUB_PROPERTY;
@property (readonly, getter=isReachable, nonatomic) BOOL reachable STUB_PROPERTY;
@property (readonly, getter=isBlocked, nonatomic) BOOL blocked STUB_PROPERTY;
- (void)identifyWithCompletionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, getter=isBridged, nonatomic) BOOL bridged STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* identifiersForBridgedAccessories STUB_PROPERTY;
@property (readonly, nonatomic, weak) HMRoom* room STUB_PROPERTY;
@property (nonatomic, weak) id<HMAccessoryDelegate> delegate STUB_PROPERTY;

@end
