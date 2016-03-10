//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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

@class NSDate;
@class NSArray;
@class NSMutableDictionary;
@class NSString;

FOUNDATION_EXPORT NSString* const NSDidBecomeSingleThreadedNotification;
FOUNDATION_EXPORT NSString* const NSWillBecomeMultiThreadedNotification;
FOUNDATION_EXPORT NSString* const NSThreadWillExitNotification;

FOUNDATION_EXPORT_CLASS
@interface NSThread : NSObject
- (instancetype)init;
- (instancetype)initWithTarget:(id)target selector:(SEL)selector object:(id)argument;
+ (void)detachNewThreadSelector:(SEL)aSelector toTarget:(id)aTarget withObject:(id)anArgument;
- (void)start;
- (void)main;
+ (void)sleepUntilDate:(NSDate*)aDate;
+ (void)sleepForTimeInterval:(NSTimeInterval)ti;
+ (void)exit STUB_METHOD;
- (void)cancel;
@property (readonly, getter=isExecuting) BOOL executing;
@property (readonly, getter=isFinished) BOOL finished;
@property (readonly, getter=isCancelled) BOOL cancelled;
+ (BOOL)isMainThread;
@property (readonly) BOOL isMainThread;
+ (NSThread*)mainThread;
+ (BOOL)isMultiThreaded;
+ (NSThread*)currentThread;
+ (NSArray*)callStackReturnAddresses STUB_METHOD;
+ (NSArray*)callStackSymbols STUB_METHOD;
@property (readonly, retain) NSMutableDictionary* threadDictionary;
@property (copy) NSString* name;
@property NSUInteger stackSize;
+ (double)threadPriority;
@property (readwrite) double threadPriority;
+ (BOOL)setThreadPriority:(double)priority;
@end

@interface NSObject (NSThreadPerformAdditions)
- (void)performSelector:(SEL)selector
               onThread:(NSThread*)thread
             withObject:(id)object
          waitUntilDone:(BOOL)waitUntilDone
                  modes:(NSArray*)modes;
- (void)performSelector:(SEL)selector onThread:(NSThread*)thread withObject:(id)object waitUntilDone:(BOOL)waitUntilDone;
- (void)performSelectorOnMainThread:(SEL)selector withObject:object waitUntilDone:(BOOL)waitUntilDone modes:(NSArray*)modes;
- (void)performSelectorOnMainThread:(SEL)selector withObject:object waitUntilDone:(BOOL)waitUntilDone;
- (void)performSelectorInBackground:(SEL)selector withObject:object;
@end