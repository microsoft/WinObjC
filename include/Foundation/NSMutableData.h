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

#import <Foundation/NSData.h>

FOUNDATION_EXPORT_CLASS
@interface NSMutableData : NSData <NSCopying, NSMutableCopying, NSSecureCoding>
+ (instancetype)dataWithCapacity:(NSUInteger)aNumItems;
+ (instancetype)dataWithLength:(NSUInteger)length;
- (instancetype)initWithCapacity:(NSUInteger)capacity;
- (instancetype)initWithLength:(NSUInteger)length;
@property NSUInteger length;
- (void)increaseLengthBy:(NSUInteger)extraLength;
@property (readonly) void* mutableBytes;
- (void)appendBytes:(const void*)bytes length:(NSUInteger)length;
- (void)appendData:(NSData*)otherData;
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)bytes;
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)replacementBytes length:(NSUInteger)replacementLength;
- (void)resetBytesInRange:(NSRange)range;
- (void)setData:(NSData*)aData;
@end
