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

@protocol NSPortDelegate;
@class NSDate;
@class NSMutableArray;
@class NSRunLoop;
@class NSString;
@class NSPortMessage;

FOUNDATION_EXPORT NSString* const NSPortDidBecomeInvalidNotification;

FOUNDATION_EXPORT NSString* const NSPortTimeoutException;
FOUNDATION_EXPORT NSString* const NSInvalidSendPortException;
FOUNDATION_EXPORT NSString* const NSInvalidReceivePortException;
FOUNDATION_EXPORT NSString* const NSPortSendException;
FOUNDATION_EXPORT NSString* const NSPortReceiveException;
FOUNDATION_EXPORT NSString* const NSOldStyleException;

FOUNDATION_EXPORT_CLASS
@interface NSPort : NSObject <NSCoding, NSCopying>
+ (id)allocWithZone:(NSZone*)zone;
+ (NSPort*)port;
- (void)invalidate;
@property (readonly, getter=isValid) BOOL valid;
- (void)setDelegate:(id<NSPortDelegate>)anObject;
- (id<NSPortDelegate>)delegate;
- (BOOL)sendBeforeDate:(NSDate*)limitDate
            components:(NSMutableArray*)components
                  from:(NSPort*)receivePort
              reserved:(NSUInteger)headerSpaceReserved;
- (BOOL)sendBeforeDate:(NSDate*)limitDate
                 msgid:(NSUInteger)msgID
            components:(NSMutableArray*)components
                  from:(NSPort*)receivePort
              reserved:(NSUInteger)headerSpaceReserved;
@property (readonly) NSUInteger reservedSpaceLength;
- (void)removeFromRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode;
- (void)scheduleInRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode;
@end

@protocol NSPortDelegate <NSObject>
@optional
- (void)handlePortMessage:(NSPortMessage*)portMessage;

@end
