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

#import <UIKit/UIKitExport.h>
#import <UIKit/UIKitTypes.h>
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIGeometry.h>
#import <QuartzCore/CoreAnimation.h>

@interface NSValue (UIKitAdditions)
- (id)initWithCGSize:(CGSize)value;
- (id)initWithCGVector:(CGVector)value;
- (id)initWithCGPoint:(CGPoint)value;
- (id)initWithCGRect:(CGRect)value;
- (id)initWithUIOffset:(UIOffset)value;
- (id)initWithCATransform3D:(CATransform3D)value;
- (id)initWithCGAffineTransform:(CGAffineTransform)value;
- (id)initWithUIEdgeInsets:(UIEdgeInsets)value;
+ (NSValue*)valueWithCGSize:(CGSize)value;
+ (NSValue*)valueWithCGVector:(CGVector)value;
+ (NSValue*)valueWithCGPoint:(CGPoint)value;
+ (NSValue*)valueWithCGRect:(CGRect)value;
+ (NSValue*)valueWithUIOffset:(UIOffset)value;
+ (NSValue*)valueWithCATransform3D:(CATransform3D)value;
+ (NSValue*)valueWithCGAffineTransform:(CGAffineTransform)value;
+ (NSValue*)valueWithUIEdgeInsets:(UIEdgeInsets)value;
- (CGSize)sizeValue;
- (CGSize)CGSizeValue;
- (CGVector)vectorValue;
- (CGVector)CGVectorValue;
- (CGPoint)pointValue;
- (CGPoint)CGPointValue;
- (CGRect)rectValue;
- (CGRect)CGRectValue;
- (UIOffset)UIOffsetValue;
- (CATransform3D)CATransform3DValue;
- (CGAffineTransform)affineTransformValue;
- (CGAffineTransform)CGAffineTransformValue;
- (UIEdgeInsets)edgeInsetsValue;
- (UIEdgeInsets)UIEdgeInsetsValue;
@end
