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

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSInvocation;
@class NSDate;

FOUNDATION_EXPORT_CLASS
@interface NSTimer : NSObject
+ (NSTimer*)scheduledTimerWithTimeInterval:(NSTimeInterval)seconds invocation:(NSInvocation*)invocation repeats:(BOOL)repeats;
+ (NSTimer*)scheduledTimerWithTimeInterval:(NSTimeInterval)seconds
                                    target:(id)target
                                  selector:(SEL)aSelector
                                  userInfo:(id)userInfo
                                   repeats:(BOOL)repeats;
+ (NSTimer*)timerWithTimeInterval:(NSTimeInterval)seconds invocation:(NSInvocation*)invocation repeats:(BOOL)repeats;
+ (NSTimer*)timerWithTimeInterval:(NSTimeInterval)seconds
                           target:(id)target
                         selector:(SEL)aSelector
                         userInfo:(id)userInfo
                          repeats:(BOOL)repeats;
- (instancetype)initWithFireDate:(NSDate*)date
                        interval:(NSTimeInterval)seconds
                          target:(id)target
                        selector:(SEL)aSelector
                        userInfo:(id)userInfo
                         repeats:(BOOL)repeats;
- (void)fire;
- (void)invalidate;
@property (readonly, getter=isValid) BOOL valid;
@property (copy) NSDate* fireDate;
@property (readonly) NSTimeInterval timeInterval;
@property (readonly, retain) id userInfo;
@property NSTimeInterval tolerance;
@end
