/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSRange.h>
#import <Foundation/NSNumber.h>

typedef enum : NSUInteger {
    NSValueTypeUnknown,
    NSValueTypeCGPoint,
    NSValueTypeUIOffset,
    NSValueTypeCGSize,
    NSValueTypeCGRect,
    NSValueTypeCATransform3D,
    NSValueTypeCGAffineTransform,
    NSValueTypePointer,
    NSValueTypeGeneric,
    NSValueTypeNonretainedObject,
    NSValueTypeNSRange,
} NSValueType;

FOUNDATION_EXPORT_CLASS
@interface NSValue : NSObject <NSCopying, NSCoding> {
@public
    NSValueType _valueType;
}

- (NSValue*)initWithBytes:(const void*)value objCType:(const char*)type;
+ (NSValue*)valueWithBytes:(const void*)value objCType:(const char*)type;
+ (NSValue*)value:(const void*)value withObjCType:(const char*)type;

- (BOOL)isEqualToValue:(NSValue*)other;

+ (NSValue*)valueWithNonretainedObject:(__unsafe_unretained id)object;
- (__unsafe_unretained id)nonretainedObjectValue;

+ (NSValue*)valueWithPointer:(const void*)pointer;
- (const void*)pointerValue;

/* Core Graphics Geometry Values */
+ (NSValue*)valueWithCGPoint:(NSPoint)point;
+ (NSValue*)valueWithCGSize:(NSSize)size;
+ (NSValue*)valueWithCGRect:(NSRect)rect;
- (CGPoint)pointValue;
- (CGPoint)CGPointValue;
- (CGSize)sizeValue;
- (CGSize)CGSizeValue;
- (CGRect)rectValue;
- (CGRect)CGRectValue;

/* Foundation Type Values */
+ (NSValue*)valueWithRange:(NSRange)range;
- (NSRange)rangeValue;

- (void)getValue:(void*)value;
- (const char*)objCType;

- (NSValue*)initWithCGSize:(CGSize)val;
- (NSValue*)initWithCGPoint:(CGPoint)val;
- (NSValue*)initWithCGRect:(CGRect)val;

@end
