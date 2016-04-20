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

#import "NSRaise.h"
#include <StubReturn.h>
#import <UIKit/UIGeometry.h>

@implementation NSCoder (UIGeometryKeyedCoding)

/**
@Status Interoperable
*/
- (void)encodeCGPoint:(CGPoint)point forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeCGRect:(CGRect)rect forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeCGSize:(CGSize)size forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeCGVector:(CGVector)vector forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeUIEdgeInsets:(UIEdgeInsets)insets forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeUIOffset:(UIOffset)offset forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (void)encodeCGAffineTransform:(CGAffineTransform)transform forKey:(NSString*)key {
    NSInvalidAbstractInvocation();
}

/**
@Status Interoperable
*/
- (CGPoint)decodeCGPointForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (CGRect)decodeCGRectForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (CGSize)decodeCGSizeForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (CGVector)decodeCGVectorForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (UIEdgeInsets)decodeUIEdgeInsetsForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (UIOffset)decodeUIOffsetForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

/**
@Status Interoperable
*/
- (CGAffineTransform)decodeCGAffineTransformForKey:(NSString*)key {
    return NSInvalidAbstractInvocationReturn();
}

@end

@implementation NSKeyedArchiver (UIGeometryKeyedCoding)

/**
 @Status Interoperable
*/
- (void)encodeCGPoint:(CGPoint)point forKey:(NSString*)aKey {
    [self encodeObject:[NSValue valueWithCGPoint:point] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeCGRect:(CGRect)rect forKey:(NSString*)aKey {
    [self encodeObject:[NSValue valueWithCGRect:rect] forKey:aKey];
}

/**
 @Status Interoperable
*/
- (void)encodeCGSize:(CGSize)size forKey:(NSString*)aKey {
    [self encodeObject:[NSValue valueWithCGSize:size] forKey:aKey];
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeCGVector:(CGVector)vector forKey:(NSString*)key STUB_METHOD {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeUIEdgeInsets:(UIEdgeInsets)insets forKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeUIOffset:(UIOffset)offset forKey:(NSString*)key {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeCGAffineTransform:(CGAffineTransform)transform forKey:(NSString*)key {
    UNIMPLEMENTED();
}
@end

@implementation NSKeyedUnarchiver (UIGeometryKeyedCoding)

/**
 @Status Interoperable
*/
- (CGPoint)decodeCGPointForKey:(NSString*)key {
    CGPoint ret = { 0, 0 };
    id value = [self decodeObjectForKey:key];

    if (value != nil) {
        ret = [value CGPointValue];
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (CGRect)decodeCGRectForKey:(NSString*)key {
    CGRect ret = CGRectMake(0, 0, 0, 0);
    id value = [self decodeObjectForKey:key];

    if (value != nil) {
        ret = [value CGRectValue];
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (CGSize)decodeCGSizeForKey:(NSString*)key {
    CGSize ret = { 0, 0 };
    id value = [self decodeObjectForKey:key];

    if (value != nil) {
        ret = [value CGSizeValue];
    }

    return ret;
}

/**
 @Status Stub
 @Notes
*/
- (CGVector)decodeCGVectorForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (UIEdgeInsets)decodeUIEdgeInsetsForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (UIOffset)decodeUIOffsetForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (CGAffineTransform)decodeCGAffineTransformForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}
@end