/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the
following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#pragma once

#import <Foundation/NSException.h>
#import <Foundation/NSDate.h>

@class NSDictionary, NSMutableDictionary, NSAutoreleasePool, NSLock, NSRunLoop;

FOUNDATION_EXPORT NSString* const NSDidBecomeSingleThreadedNotification;
FOUNDATION_EXPORT NSString* const NSWillBecomeMultiThreadedNotification;
FOUNDATION_EXPORT NSString* const NSThreadWillExitNotification;

FOUNDATION_EXPORT_CLASS
@interface NSThread : NSObject

+ (BOOL)isMultiThreaded;
+ (BOOL)isMainThread;

+ (NSThread*)mainThread;

+ (void)detachNewThreadSelector:(SEL)selector toTarget:target withObject:argument;

+ (NSThread*)currentThread;
+ (NSArray*)callStackReturnAddresses;
+ (NSArray*)callStackSymbols;

+ (double)threadPriority;
+ (void)setThreadPriority:(double)value;

+ (void)sleepUntilDate:(NSDate*)date;
+ (void)sleepForTimeInterval:(NSTimeInterval)value;

- (instancetype)init;
- (instancetype)initWithTarget:(id)target selector:(SEL)selector object:(id)argument;

- (void)start;
- (void)cancel;
- (void)main;
+ (void)exit;

@property (copy) NSString* name;
@property (assign) NSUInteger stackSize;
@property (assign) double threadPriority;

@property (readonly) BOOL isMainThread;
@property (atomic, readonly, getter=isExecuting) BOOL executing;
@property (atomic, readonly, getter=isCancelled) BOOL cancelled;
@property (atomic, readonly, getter=isFinished) BOOL finished;

@property (readonly, retain) NSMutableDictionary* threadDictionary;
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