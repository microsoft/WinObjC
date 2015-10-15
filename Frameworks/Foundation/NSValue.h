//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "EmuTransform3D.h"

typedef enum {
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

@interface NSValue : NSObject {
@public
    NSValueType _valueType;

    typedef struct {
        char* pType;
        int size;
        void* copy;
    } objcValue;

    union {
        CGPoint pointValue;
        CGSize sizeValue;
        CGRect rectValue;
        CATransform3D transformValue;
        CGAffineTransform affineTransformValue;
        void* pointerValue;
        objcValue genericValue;
    } v;
}
- (float)scale;
- (id)initWithCoder:(NSCoder*)coder;
- (void)encodeWithCoder:(NSCoder*)coder;
- (void*)pointerValue;
- (id)nonretainedObjectValue;
- (void)getValue:(void*)dest;
- (BOOL)isEqualToValue:(NSValue*)toValue;
- (unsigned)hash;
- (NSObject*)copyWithZone:(NSZone*)zone;
- (NSString*)description;
- (const char*)objCType;
- (void)dealloc;
- (CGPoint)CGPointValue;
- (CGSize)CGSizeValue;
- (CGRect)CGRectValue;
- (CATransform3D)CATransform3DValue;
- (CGAffineTransform)CGAffineTransformValue;
+ (NSValue*)valueWithCGPoint:(CGPoint)point;
+ (NSValue*)valueWithUIOffset:(CGPoint)point;
+ (NSValue*)valueWithCGSize:(CGSize)size;
+ (NSValue*)valueWithCGRect:(CGRect)rect;
+ (NSValue*)valueWithPointer:(void*)ptr;
+ (NSValue*)valueWithNonretainedObject:(id)obj;
+ (NSValue*)valueWithCATransform3DPtr:(CATransform3D*)pTransform;
+ (NSValue*)valueWithBytes:(void*)value objCType:(char*)objCType;
+ (NSValue*)value:(void*)value withObjCType:(char*)objCType;
+ (NSValue*)valueWithCATransform3D:(CATransform3D)transform;
+ (NSValue*)valueWithCGAffineTransform:(CGAffineTransform)transform;
@end
