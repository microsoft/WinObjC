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

@class HMAccessory;
@class HMActionSet;
@class NSError;
@class HMHome;
@class HMRoom;
@class HMService;
@class HMServiceGroup;
@class HMTrigger;
@class HMUser;
@class HMZone;

@protocol HMHomeDelegate <NSObject>
@optional
- (void)homeDidUpdateName:(HMHome*)home;
- (void)home:(HMHome*)home didAddAccessory:(HMAccessory*)accessory;
- (void)home:(HMHome*)home didUpdateRoom:(HMRoom*)room forAccessory:(HMAccessory*)accessory;
- (void)home:(HMHome*)home didRemoveAccessory:(HMAccessory*)accessory;
- (void)home:(HMHome*)home didAddRoom:(HMRoom*)room;
- (void)home:(HMHome*)home didUpdateNameForRoom:(HMRoom*)room;
- (void)home:(HMHome*)home didAddRoom:(HMRoom*)room toZone:(HMZone*)zone;
- (void)home:(HMHome*)home didRemoveRoom:(HMRoom*)room fromZone:(HMZone*)zone;
- (void)home:(HMHome*)home didRemoveRoom:(HMRoom*)room;
- (void)home:(HMHome*)home didAddZone:(HMZone*)zone;
- (void)home:(HMHome*)home didUpdateNameForZone:(HMZone*)zone;
- (void)home:(HMHome*)home didRemoveZone:(HMZone*)zone;
- (void)home:(HMHome*)home didAddUser:(HMUser*)user;
- (void)home:(HMHome*)home didRemoveUser:(HMUser*)user;
- (void)home:(HMHome*)home didAddServiceGroup:(HMServiceGroup*)group;
- (void)home:(HMHome*)home didUpdateNameForServiceGroup:(HMServiceGroup*)group;
- (void)home:(HMHome*)home didAddService:(HMService*)service toServiceGroup:(HMServiceGroup*)group;
- (void)home:(HMHome*)home didRemoveService:(HMService*)service fromServiceGroup:(HMServiceGroup*)group;
- (void)home:(HMHome*)home didRemoveServiceGroup:(HMServiceGroup*)group;
- (void)home:(HMHome*)home didAddActionSet:(HMActionSet*)actionSet;
- (void)home:(HMHome*)home didUpdateNameForActionSet:(HMActionSet*)actionSet;
- (void)home:(HMHome*)home didUpdateActionsForActionSet:(HMActionSet*)actionSet;
- (void)home:(HMHome*)home didRemoveActionSet:(HMActionSet*)actionSet;
- (void)home:(HMHome*)home didAddTrigger:(HMTrigger*)trigger;
- (void)home:(HMHome*)home didUpdateNameForTrigger:(HMTrigger*)trigger;
- (void)home:(HMHome*)home didUpdateTrigger:(HMTrigger*)trigger;
- (void)home:(HMHome*)home didRemoveTrigger:(HMTrigger*)trigger;
- (void)home:(HMHome*)home didEncounterError:(NSError*)error forAccessory:(HMAccessory*)accessory;
- (void)home:(HMHome*)home didUnblockAccessory:(HMAccessory*)accessory;
@end
