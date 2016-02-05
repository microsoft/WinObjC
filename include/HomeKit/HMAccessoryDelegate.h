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
@class HMService;
@class HMCharacteristic;

@protocol HMAccessoryDelegate <NSObject>
@optional
- (void)accessoryDidUpdateName:(HMAccessory*)accessory;
- (void)accessoryDidUpdateReachability:(HMAccessory*)accessory;
- (void)accessoryDidUpdateServices:(HMAccessory*)accessory;
- (void)accessory:(HMAccessory*)accessory didUpdateNameForService:(HMService*)service;
- (void)accessory:(HMAccessory*)accessory service:(HMService*)service didUpdateValueForCharacteristic:(HMCharacteristic*)characteristic;
- (void)accessory:(HMAccessory*)accessory didUpdateAssociatedServiceTypeForService:(HMService*)service;
@end
