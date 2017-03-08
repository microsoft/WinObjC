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

#import <QuartzCore/CoreAnimationExport.h>
#import <Foundation/NSString.h>
#import <CoreGraphics/CGColor.h>
#import <QuartzCore/CALayer.h>

CA_EXPORT NSString* const kCAFillRuleNonZero;
CA_EXPORT NSString* const kCAFillRuleEvenOdd;
CA_EXPORT NSString* const kCALineJoinMiter;
CA_EXPORT NSString* const kCALineJoinRound;
CA_EXPORT NSString* const kCALineJoinBevel;
CA_EXPORT NSString* const kCALineCapButt;
CA_EXPORT NSString* const kCALineCapRound;
CA_EXPORT NSString* const kCALineCapSquare;

CA_EXPORT_CLASS
@interface CAShapeLayer : CALayer <CAMediaTiming, NSCoding>

@property CGPathRef path;
@property CGColorRef fillColor;
@property (copy) NSString* fillRule;
@property (copy) NSString* lineCap;
@property (copy) NSArray* lineDashPattern STUB_PROPERTY;
@property CGFloat lineDashPhase STUB_PROPERTY;
@property (copy) NSString* lineJoin STUB_PROPERTY;
@property CGFloat lineWidth;
@property CGFloat miterLimit STUB_PROPERTY;
@property CGColorRef strokeColor;
@property CGFloat strokeStart STUB_PROPERTY;
@property CGFloat strokeEnd STUB_PROPERTY;

@end
