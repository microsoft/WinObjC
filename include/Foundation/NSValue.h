/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>
#import <Foundation/NSGeometry.h>
#import <Foundation/NSRange.h>

typedef enum 
{
    notSetType,
    pointType,
    offsetType,
    sizeType,
    rectType,
    transformType,
    affineTransformType,
    pointerType,
    objcType,
    nonRetainedObjectType,
} NSValueType;

struct CBAffineTransform {
    CGFloat a;
    CGFloat b;
    CGFloat c;
    CGFloat d;
    CGFloat tx;
    CGFloat ty;
};

struct CBTransform3D {
    union {
        struct {
            float m11, m12, m13, m14;
            float m21, m22, m23, m24;
            float m31, m32, m33, m34;
            float m41, m42, m43, m44;
        };
        float m[4][4];
    };
};

struct objcValue {
    char *pType;
    int   size;
    void *copy;
};

FOUNDATION_EXPORT_CLASS
@interface NSValue : NSObject <NSCopying,NSCoding> {
@public
    NSValueType _valueType;

    union {
        CGPoint pointValue;
        CGSize sizeValue;
        CGRect rectValue;
        struct CBTransform3D transformValue;
        struct CBAffineTransform affineTransformValue;
        void*  pointerValue;
        struct objcValue genericValue;
    } v;
}

-initWithBytes:(const void *)value objCType:(const char *)type;
+(NSValue *)valueWithBytes:(const void *)value objCType:(const char *)type;
+(NSValue *)value:(const void *)value withObjCType:(const char *)type;

+(NSValue *)valueWithNonretainedObject:object;
+(NSValue *)valueWithPointer:(const void *)pointer;
+(NSValue *)valueWithPoint:(NSPoint)point;
+(NSValue *)valueWithSize:(NSSize)size;
+(NSValue *)valueWithRect:(NSRect)rect;
+(NSValue *)valueWithRange:(NSRange)range;

-(BOOL)isEqualToValue:(NSValue *)other;

-(void)getValue:(void *)value;
-(const char *)objCType;

-nonretainedObjectValue;

-(void *)pointerValue;

-(NSPoint)pointValue;
-(NSSize)sizeValue;
-(NSRect)rectValue;
-(NSRange)rangeValue;

@end

#import <Foundation/NSNumber.h>
