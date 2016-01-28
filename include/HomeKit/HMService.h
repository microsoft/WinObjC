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

HOMEKIT_EXPORT NSString* const HMServiceTypeLightbulb;
HOMEKIT_EXPORT NSString* const HMServiceTypeSwitch;
HOMEKIT_EXPORT NSString* const HMServiceTypeThermostat;
HOMEKIT_EXPORT NSString* const HMServiceTypeGarageDoorOpener;
HOMEKIT_EXPORT NSString* const HMServiceTypeAccessoryInformation;
HOMEKIT_EXPORT NSString* const HMServiceTypeFan;
HOMEKIT_EXPORT NSString* const HMServiceTypeOutlet;
HOMEKIT_EXPORT NSString* const HMServiceTypeLockMechanism;
HOMEKIT_EXPORT NSString* const HMServiceTypeLockManagement;

HOMEKIT_EXPORT_CLASS
@interface HMService : NSObject
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
- (void)updateName:(NSString*)name completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSString* serviceType STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSString* associatedServiceType STUB_PROPERTY;
- (void)updateAssociatedServiceType:(NSString*)serviceType completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* characteristics STUB_PROPERTY;
@property (readonly, nonatomic, weak) HMAccessory* accessory STUB_PROPERTY;

@end
