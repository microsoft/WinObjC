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
#import <HomeKit/HMAction.h>

@class HMCharacteristic;
@class NSError;

typedef id<NSCopying> _Nonnull TargetValueType;

HOMEKIT_EXPORT_CLASS
@interface HMCharacteristicWriteAction : HMAction
- (instancetype)initWithCharacteristic:(HMCharacteristic*)characteristic targetValue:(TargetValueType)targetValue STUB_METHOD;
@property (readonly, nonatomic, strong) HMCharacteristic* characteristic STUB_PROPERTY;
@property (readonly, copy, nonatomic) TargetValueType targetValue STUB_PROPERTY;
- (void)updateTargetValue:(TargetValueType)targetValue completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@end
