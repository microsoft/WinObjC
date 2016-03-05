//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import <QuartzCore/CoreAnimationExport.h>
#import <CoreFoundation/CFDate.h>
#import <Foundation/NSObject.h>

@class NSString;
@class CAMediaTimingFunction;

CA_EXPORT NSString* const kCATransactionAnimationDuration;
CA_EXPORT NSString* const kCATransactionDisableActions;
CA_EXPORT NSString* const kCATransactionAnimationTimingFunction;
CA_EXPORT NSString* const kCATransactionCompletionBlock;

CA_EXPORT_CLASS
@interface CATransaction : NSObject {
}
+ (BOOL)disableActions;
+ (CFTimeInterval)animationDuration;
+ (CAMediaTimingFunction*)animationTimingFunction;
+ (id)valueForKey:(NSString*)key;

+ (void)setAnimationDuration:(CFTimeInterval)duration;
+ (void)setAnimationTimingFunction:(CAMediaTimingFunction*)function;
+ (void)setDisableActions:(BOOL)flag;
+ (void)setValue:(id)anObject forKey:(NSString*)key;

+ (void)begin;
+ (void)commit;
+ (void)flush;

+ (void)lock;
+ (void)unlock;

+ (void)setCompletionBlock:(void (^)(void))block;
+ (void (^)(void))completionBlock;

@end
