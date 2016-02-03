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

#import <Foundation/NSPort.h>

@class NSRunLoop;
@class NSString;
@protocol NSMachPortDelegate;

enum { NSMachPortDeallocateNone = 0, NSMachPortDeallocateSendRight = (1 << 0), NSMachPortDeallocateReceiveRight = (1 << 1) };

typedef NSUInteger NSMachPortOptions;

FOUNDATION_EXPORT_CLASS
@interface NSMachPort : NSPort <NSCoding, NSCopying>
+ (NSPort*)portWithMachPort:(uint32_t)machPort STUB_METHOD;
+ (NSPort*)portWithMachPort:(uint32_t)machPort options:(NSMachPortOptions)options STUB_METHOD;
- (instancetype)initWithMachPort:(uint32_t)machPort STUB_METHOD;
- (instancetype)initWithMachPort:(uint32_t)machPort options:(NSMachPortOptions)options STUB_METHOD;
@property (readonly) uint32_t machPort STUB_PROPERTY;
- (void)removeFromRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode STUB_METHOD;
- (void)scheduleInRunLoop:(NSRunLoop*)runLoop forMode:(NSString*)mode STUB_METHOD;
- (id<NSMachPortDelegate>)delegate STUB_METHOD;
- (void)setDelegate:(id<NSMachPortDelegate>)anObject STUB_METHOD;
@end

@protocol NSMachPortDelegate <NSObject>
@optional
- (void)handleMachMessage:(void*)machMessage;

@end
