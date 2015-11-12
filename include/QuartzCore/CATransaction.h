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

#ifndef _CATRANSACTION_H_
#define _CATRANSACTION_H_

#import <Foundation/NSObject.h>
#import <QuartzCore/CABase.h>

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
+ valueForKey:(NSString*)key;

+ (void)setAnimationDuration:(CFTimeInterval)value;
+ (void)setAnimationTimingFunction:(CAMediaTimingFunction*)value;
+ (void)setDisableActions:(BOOL)value;
+ (void)setValue:value forKey:(NSString*)key;

+ (void)begin;
+ (void)commit;
+ (void)flush;

+ (void)lock;
+ (void)unlock;

#if __BLOCKS__
+ (void)setCompletionBlock:(void (^)(void))block;
+ (void (^)(void))completionBlock;
#endif

@end

#endif /* _CATRANSACTION_H_ */