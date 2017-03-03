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

#import "Starboard.h"
#import <UIKit/NSValue+UIKitAdditions.h>

@implementation NSValue (UIKitAdditions)

/**
 @Status Interoperable
*/
- (id)initWithCGSize:(CGSize)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGSize)];
}

/**
 @Status Interoperable
*/
- (id)initWithCGVector:(CGVector)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGVector)];
}

/**
 @Status Interoperable
*/
- (id)initWithCGPoint:(CGPoint)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGPoint)];
}

/**
 @Status Interoperable
*/
- (id)initWithCGRect:(CGRect)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGRect)];
}

/**
 @Status Interoperable
*/
- (id)initWithUIOffset:(UIOffset)value {
    return [self initWithBytes:(void*)&value objCType:@encode(UIOffset)];
}

/**
 @Status Interoperable
*/
- (id)initWithCATransform3D:(CATransform3D)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CATransform3D)];
}

/**
 @Status Interoperable
*/
- (id)initWithCGAffineTransform:(CGAffineTransform)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGAffineTransform)];
}

/**
 @Status Interoperable
*/
- (id)initWithUIEdgeInsets:(UIEdgeInsets)value {
    return [self initWithBytes:(void*)&value objCType:@encode(UIEdgeInsets)];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithCGSize:(CGSize)value {
    return [[[self alloc] initWithCGSize:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithCGVector:(CGVector)value {
    return [[[self alloc] initWithCGVector:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithCGPoint:(CGPoint)value {
    return [[[self alloc] initWithCGPoint:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithCGRect:(CGRect)value {
    return [[[self alloc] initWithCGRect:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithUIOffset:(UIOffset)value {
    return [[[self alloc] initWithUIOffset:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithCATransform3D:(CATransform3D)value {
    return [[[self alloc] initWithCATransform3D:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithCGAffineTransform:(CGAffineTransform)value {
    return [[[self alloc] initWithCGAffineTransform:value] autorelease];
}

/**
 @Status Interoperable
*/
+ (NSValue*)valueWithUIEdgeInsets:(UIEdgeInsets)value {
    return [[[self alloc] initWithUIEdgeInsets:value] autorelease];
}

/**
 @Status Interoperable
*/
- (CGSize)sizeValue {
    CGSize val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGSize)CGSizeValue {
    CGSize val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGVector)vectorValue {
    CGVector val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGVector)CGVectorValue {
    CGVector val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGPoint)pointValue {
    CGPoint val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGPoint)CGPointValue {
    CGPoint val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGRect)rectValue {
    CGRect val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGRect)CGRectValue {
    CGRect val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (UIOffset)UIOffsetValue {
    UIOffset val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CATransform3D)CATransform3DValue {
    CATransform3D val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGAffineTransform)affineTransformValue {
    CGAffineTransform val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (CGAffineTransform)CGAffineTransformValue {
    CGAffineTransform val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)edgeInsetsValue {
    UIEdgeInsets val;
    [self getValue:&val];
    return val;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)UIEdgeInsetsValue {
    UIEdgeInsets val;
    [self getValue:&val];
    return val;
}

@end

void NSValueForceinclude() {
    [NSValue class];
}
