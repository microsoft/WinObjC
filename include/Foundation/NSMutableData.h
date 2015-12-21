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

#import <Foundation/NSData.h>

FOUNDATION_EXPORT_CLASS
@interface NSMutableData : NSData {
    NSUInteger _capacity;
}

// Creating and Initializing an NSMutableData Object
+ (instancetype)dataWithCapacity:(NSUInteger)capacity;
+ (instancetype)dataWithLength:(NSUInteger)length;

- (instancetype)initWithCapacity:(NSUInteger)capacity;
- (instancetype)initWithLength:(NSUInteger)length;

// Accessing Data
- (void*)mutableBytes NS_RETURNS_INNER_POINTER;

// Adding Data
- (void)appendBytes:(const void*)bytes length:(NSUInteger)length;
- (void)appendData:(NSData*)data;

// Modifying Data
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)bytes;
- (void)replaceBytesInRange:(NSRange)range withBytes:(const void*)bytes length:(NSUInteger)bytesLength;
- (void)resetBytesInRange:(NSRange)range;
- (void)setData:(NSData*)data;

// Adjusting Capacity
@property NSUInteger length;
- (void)increaseLengthBy:(NSUInteger)delta;

@end
