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

@class HMActionSet;
@class NSArray;
@class NSDate;
@class NSError;
@class NSString;

HOMEKIT_EXPORT_CLASS
@interface HMTrigger : NSObject
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
- (void)updateName:(NSString*)name completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, getter=isEnabled, nonatomic) BOOL enabled STUB_PROPERTY;
- (void)enable:(BOOL)enable completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSDate* lastFireDate STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* actionSets STUB_PROPERTY;
- (void)addActionSet:(HMActionSet*)actionSet completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)removeActionSet:(HMActionSet*)actionSet completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@end
