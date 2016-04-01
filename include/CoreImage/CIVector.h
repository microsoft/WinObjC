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

#import <CoreImage/CoreImageExport.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/NSObject.h>

@class NSString;

COREIMAGE_EXPORT_CLASS
@interface CIVector : NSObject <NSCopying, NSSecureCoding> {
    size_t _count;
    CGFloat* _values;
}

+ (instancetype)vectorWithValues:(const CGFloat*)values count:(size_t)count STUB_METHOD;
+ (instancetype)vectorWithX:(CGFloat)x STUB_METHOD;
+ (instancetype)vectorWithX:(CGFloat)x Y:(CGFloat)y STUB_METHOD;
+ (instancetype)vectorWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z STUB_METHOD;
+ (instancetype)vectorWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z W:(CGFloat)w STUB_METHOD;
+ (instancetype)vectorWithString:(NSString*)representation STUB_METHOD;
+ (instancetype)vectorWithCGAffineTransform:(CGAffineTransform)t STUB_METHOD;
+ (instancetype)vectorWithCGPoint:(CGPoint)p STUB_METHOD;
+ (instancetype)vectorWithCGRect:(CGRect)r STUB_METHOD;
- (instancetype)initWithValues:(const CGFloat*)values count:(size_t)count STUB_METHOD;
- (instancetype)initWithX:(CGFloat)x STUB_METHOD;
- (instancetype)initWithX:(CGFloat)x Y:(CGFloat)y STUB_METHOD;
- (instancetype)initWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z STUB_METHOD;
- (instancetype)initWithX:(CGFloat)x Y:(CGFloat)y Z:(CGFloat)z W:(CGFloat)w STUB_METHOD;
- (instancetype)initWithString:(NSString*)representation STUB_METHOD;
- (instancetype)initWithCGAffineTransform:(CGAffineTransform)r STUB_METHOD;
- (instancetype)initWithCGPoint:(CGPoint)p STUB_METHOD;
- (instancetype)initWithCGRect:(CGRect)r STUB_METHOD;
- (CGFloat)valueAtIndex:(size_t)index STUB_METHOD;
@property (readonly) size_t count STUB_PROPERTY;
@property (readonly) CGFloat X STUB_PROPERTY;
@property (readonly) CGFloat Y STUB_PROPERTY;
@property (readonly) CGFloat Z STUB_PROPERTY;
@property (readonly) CGFloat W STUB_PROPERTY;
@property (readonly) NSString* stringRepresentation STUB_PROPERTY;
@property (readonly) CGAffineTransform CGAffineTransformValue STUB_PROPERTY;
@property (readonly) CGPoint CGPointValue STUB_PROPERTY;
@property (readonly) CGRect CGRectValue STUB_PROPERTY;
@end
