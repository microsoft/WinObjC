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

@class NSString;
@class NSOperationQueue;
@class NSNotification;
@class NSDictionary;

FOUNDATION_EXPORT_CLASS
@interface NSNotificationCenter : NSObject
+ (NSNotificationCenter*)defaultCenter;
- (id<NSObject>)addObserverForName:(NSString*)name
                            object:(id)obj
                             queue:(NSOperationQueue*)queue
                        usingBlock:(void (^)(NSNotification*))block;
- (void)addObserver:(id)notificationObserver
           selector:(SEL)notificationSelector
               name:(NSString*)notificationName
             object:(id)notificationSender;
- (void)removeObserver:(id)notificationObserver;
- (void)removeObserver:(id)notificationObserver name:(NSString*)notificationName object:(id)notificationSender;
- (void)postNotification:(NSNotification*)notification;
- (void)postNotificationName:(NSString*)notificationName object:(id)notificationSender;
- (void)postNotificationName:(NSString*)notificationName object:(id)notificationSender userInfo:(NSDictionary*)userInfo;
@end
