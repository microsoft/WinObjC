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
- (id)initWithCGSize:(CGSize)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGSize)];
}

- (id)initWithCGVector:(CGVector)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGVector)];
}

- (id)initWithCGPoint:(CGPoint)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGPoint)];
}

- (id)initWithCGRect:(CGRect)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGRect)];
}

- (id)initWithUIOffset:(UIOffset)value {
    return [self initWithBytes:(void*)&value objCType:@encode(UIOffset)];
}

- (id)initWithCATransform3D:(CATransform3D)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CATransform3D)];
}

- (id)initWithCGAffineTransform:(CGAffineTransform)value {
    return [self initWithBytes:(void*)&value objCType:@encode(CGAffineTransform)];
}

- (id)initWithUIEdgeInsets:(UIEdgeInsets)value {
    return [self initWithBytes:(void*)&value objCType:@encode(UIEdgeInsets)];
}

+ (NSValue*)valueWithCGSize:(CGSize)value {
    return [[[self alloc] initWithCGSize:value] autorelease];
}

+ (NSValue*)valueWithCGVector:(CGVector)value {
    return [[[self alloc] initWithCGVector:value] autorelease];
}

+ (NSValue*)valueWithCGPoint:(CGPoint)value {
    return [[[self alloc] initWithCGPoint:value] autorelease];
}

+ (NSValue*)valueWithCGRect:(CGRect)value {
    return [[[self alloc] initWithCGRect:value] autorelease];
}

+ (NSValue*)valueWithUIOffset:(UIOffset)value {
    return [[[self alloc] initWithUIOffset:value] autorelease];
}

+ (NSValue*)valueWithCATransform3D:(CATransform3D)value {
    return [[[self alloc] initWithCATransform3D:value] autorelease];
}

+ (NSValue*)valueWithCGAffineTransform:(CGAffineTransform)value {
    return [[[self alloc] initWithCGAffineTransform:value] autorelease];
}

+ (NSValue*)valueWithUIEdgeInsets:(UIEdgeInsets)value {
    return [[[self alloc] initWithUIEdgeInsets:value] autorelease];
}

- (CGSize)sizeValue {
    CGSize val;
    [self getValue:&val];
    return val;
}

- (CGSize)CGSizeValue {
    CGSize val;
    [self getValue:&val];
    return val;
}

- (CGVector)vectorValue {
    CGVector val;
    [self getValue:&val];
    return val;
}

- (CGVector)CGVectorValue {
    CGVector val;
    [self getValue:&val];
    return val;
}

- (CGPoint)pointValue {
    CGPoint val;
    [self getValue:&val];
    return val;
}

- (CGPoint)CGPointValue {
    CGPoint val;
    [self getValue:&val];
    return val;
}

- (CGRect)rectValue {
    CGRect val;
    [self getValue:&val];
    return val;
}

- (CGRect)CGRectValue {
    CGRect val;
    [self getValue:&val];
    return val;
}

- (UIOffset)UIOffsetValue {
    UIOffset val;
    [self getValue:&val];
    return val;
}

- (CATransform3D)CATransform3DValue {
    CATransform3D val;
    [self getValue:&val];
    return val;
}

- (CGAffineTransform)affineTransformValue {
    CGAffineTransform val;
    [self getValue:&val];
    return val;
}

- (CGAffineTransform)CGAffineTransformValue {
    CGAffineTransform val;
    [self getValue:&val];
    return val;
}

- (UIEdgeInsets)edgeInsetsValue {
    UIEdgeInsets val;
    [self getValue:&val];
    return val;
}

- (UIEdgeInsets)UIEdgeInsetsValue {
    UIEdgeInsets val;
    [self getValue:&val];
    return val;
}

@end

void NSValueForceinclude() {
    [NSValue class];
}
