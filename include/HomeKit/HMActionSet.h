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

@class NSString;
@class NSError;
@class NSSet;
@class HMAction;

HOMEKIT_EXPORT_CLASS
@interface HMActionSet : NSObject
@property (readonly, copy, nonatomic) NSString* name STUB_PROPERTY;
- (void)updateName:(NSString*)name completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, copy, nonatomic) NSSet* actions STUB_PROPERTY;
- (void)addAction:(HMAction*)action completionHandler:(void (^)(NSError*))completion STUB_METHOD;
- (void)removeAction:(HMAction*)action completionHandler:(void (^)(NSError*))completion STUB_METHOD;
@property (readonly, getter=isExecuting, nonatomic) BOOL executing STUB_PROPERTY;
@end
