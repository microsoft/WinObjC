//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreGraphics/CGGeometry.h>

typedef struct {
    CGFloat a;
    CGFloat b;
    CGFloat c;
    CGFloat d;
    CGFloat tx;
    CGFloat ty;
} CGAffineTransform;

COREGRAPHICS_EXPORT const CGAffineTransform CGAffineTransformIdentity;

COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformMake(CGFloat a, CGFloat b, CGFloat c, CGFloat d, CGFloat tx, CGFloat ty);

COREGRAPHICS_EXPORT CGPoint CGPointApplyAffineTransform(CGPoint point, CGAffineTransform xform);

COREGRAPHICS_EXPORT CGSize CGSizeApplyAffineTransform(CGSize size, CGAffineTransform xform);

COREGRAPHICS_EXPORT CGRect CGRectApplyAffineTransform(CGRect rect, CGAffineTransform t);

COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformMakeRotation(CGFloat radians);
COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformMakeScale(CGFloat scalex, CGFloat scaley);
COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformMakeTranslation(CGFloat tx, CGFloat ty);

COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformConcat(CGAffineTransform xform, CGAffineTransform append);
COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformInvert(CGAffineTransform xform);

COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformRotate(CGAffineTransform xform, CGFloat radians);
COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformScale(CGAffineTransform xform, CGFloat scalex, CGFloat scaley);
COREGRAPHICS_EXPORT CGAffineTransform CGAffineTransformTranslate(CGAffineTransform xform, CGFloat tx, CGFloat ty);
COREGRAPHICS_EXPORT bool CGAffineTransformIsIdentity(CGAffineTransform t);

COREGRAPHICS_EXPORT bool CGAffineTransformEqualToTransform(CGAffineTransform t1, CGAffineTransform t2);
