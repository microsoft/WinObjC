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

@class HMHome;
@class NSArray;
@class NSError;
@class NSString;

@protocol HMHomeManagerDelegate;

HOMEKIT_EXPORT_CLASS
@interface HMHomeManager : NSObject
@property (readonly, nonatomic, strong) HMHome* primaryHome STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* homes STUB_PROPERTY;
- (void)addHomeWithName:(NSString*)homeName completionHandler:(void (^)(HMHome*, NSError*))completion STUB_METHOD;
- (void)removeHome:(HMHome*)home completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)updatePrimaryHome:(HMHome*)home completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (nonatomic, weak) id<HMHomeManagerDelegate> delegate STUB_PROPERTY;

@end
