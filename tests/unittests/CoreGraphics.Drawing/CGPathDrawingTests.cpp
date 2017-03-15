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

#include "DrawingTest.h"

DRAW_TEST_F(CGPath, AddCurveToPoint, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, NULL, 30, 100);
    CGPathAddCurveToPoint(thepath, NULL, 47.0f, 67.0f, 50.0f, 55.0f, 45.0f, 50.0f);
    CGPathAddCurveToPoint(thepath, NULL, 42.0f, 47.0f, 37.0f, 46.0f, 30.0f, 55.0f);

    CGPathAddCurveToPoint(thepath, NULL, 23.0f, 46.0f, 18.0f, 47.0f, 15.0f, 50.0f);
    CGPathAddCurveToPoint(thepath, NULL, 10.0f, 55.0f, 13.0f, 67.0f, 30.0f, 100.0f);

    CGPathCloseSubpath(thepath);
    CGContextAddPath(context, thepath);

    CGContextStrokePath(context);

    CGPathRelease(thepath);
}

DISABLED_DRAW_TEST_F(CGPath, AddEllipse, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGRect theRectangle = CGRectMake(50, 50, 300, 200);

    CGMutablePathRef thepath = CGPathCreateMutable();

    CGPathAddEllipseInRect(thepath, NULL, theRectangle);
    CGPathCloseSubpath(thepath);
    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    // A very transparent rectangle to show where the elipse has been drawn inside of.
    CGFloat colorComponents[] = { 1, 1, 1, .2 };
    CGContextSetStrokeColor(context, colorComponents);
    // Draw the rectangle individually just to show where the elipse should be.
    CGContextStrokeRect(context, theRectangle);

    CGPathRelease(thepath);
}

DRAW_TEST_F(CGPath, AddLineToPoint, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, NULL, 200, 35);
    CGPathAddLineToPoint(thepath, NULL, 165, 100);
    CGPathAddLineToPoint(thepath, NULL, 100, 100);
    CGPathAddLineToPoint(thepath, NULL, 150, 150);
    CGPathAddLineToPoint(thepath, NULL, 135, 225);
    CGPathAddLineToPoint(thepath, NULL, 200, 170);
    CGPathAddLineToPoint(thepath, NULL, 265, 225);
    CGPathAddLineToPoint(thepath, NULL, 250, 150);
    CGPathAddLineToPoint(thepath, NULL, 300, 100);
    CGPathAddLineToPoint(thepath, NULL, 235, 100);

    // Unnecessary as close subpath will finish this line off but for the sake of consistency, have this here.
    CGPathAddLineToPoint(thepath, NULL, 200, 35);

    CGPathCloseSubpath(thepath);
    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGPathRelease(thepath);
}

DRAW_TEST_F(CGPath, AddPath, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGMutablePathRef theFirstPath = CGPathCreateMutable();
    CGMutablePathRef theSecondPath = CGPathCreateMutable();

    CGPathMoveToPoint(theFirstPath, NULL, 200, 35);
    CGPathAddLineToPoint(theFirstPath, NULL, 165, 100);
    CGPathAddLineToPoint(theFirstPath, NULL, 100, 100);
    CGPathAddLineToPoint(theFirstPath, NULL, 150, 150);
    CGPathAddLineToPoint(theFirstPath, NULL, 135, 225);
    CGPathAddLineToPoint(theFirstPath, NULL, 200, 170);
    CGPathAddLineToPoint(theFirstPath, NULL, 265, 225);

    CGPathMoveToPoint(theSecondPath, NULL, 265, 225);

    CGPathAddLineToPoint(theSecondPath, NULL, 350, 225);
    CGPathAddLineToPoint(theSecondPath, NULL, 350, 35);
    CGPathAddLineToPoint(theSecondPath, NULL, 200, 35);

    CGPathAddPath(theFirstPath, NULL, theSecondPath);
    CGContextAddPath(context, theFirstPath);

    // Closing the path will close the subpath created from adding the second path to the first.
    CGContextClosePath(context);
    CGContextStrokePath(context);

    CGPathRelease(theFirstPath);
    CGPathRelease(theSecondPath);
}

DRAW_TEST_F(CGPath, AddQuadCurveToPoint, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGMutablePathRef thePath = CGPathCreateMutable();

    CGPathMoveToPoint(thePath, NULL, 100, 50);
    CGPathAddQuadCurveToPoint(thePath, NULL, 125, 25, 150, 50);

    CGPathMoveToPoint(thePath, NULL, 200, 50);
    CGPathAddQuadCurveToPoint(thePath, NULL, 225, 25, 250, 50);

    CGPathMoveToPoint(thePath, NULL, 100, 150);
    CGPathAddQuadCurveToPoint(thePath, NULL, 200, 200, 300, 100);

    CGPathMoveToPoint(thePath, NULL, 285, 105);
    CGPathAddQuadCurveToPoint(thePath, NULL, 300, 90, 310, 110);

    CGContextAddPath(context, thePath);

    CGContextStrokePath(context);

    CGPathRelease(thePath);
}

DRAW_TEST_F(CGPath, AddRect, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGMutablePathRef thePath = CGPathCreateMutable();

    CGPathMoveToPoint(thePath, NULL, 50, 50);
    CGPathAddLineToPoint(thePath, NULL, 100, 100);

    CGPathAddRect(thePath, NULL, CGRectMake(100, 100, 200, 100));

    CGContextAddPath(context, thePath);

    CGContextStrokePath(context);

    CGPathRelease(thePath);
}

DRAW_TEST_F(CGPath, Apply, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    auto CGPathApplyCallback = [](void* voidContext, const CGPathElement* element) {
        CGContextRef context = (CGContextRef)voidContext;
        CGPoint* points = element->points;
        CGContextMoveToPoint(context, 200, 125);
        CGContextAddLineToPoint(context, points[0].x, points[0].y);
        CGContextStrokePath(context);
    };

    CGMutablePathRef thepath = CGPathCreateMutable();

    CGPathMoveToPoint(thepath, NULL, 200, 35);
    CGPathAddLineToPoint(thepath, NULL, 165, 100);
    CGPathAddLineToPoint(thepath, NULL, 100, 100);
    CGPathAddLineToPoint(thepath, NULL, 150, 150);
    CGPathAddLineToPoint(thepath, NULL, 135, 225);
    CGPathAddLineToPoint(thepath, NULL, 200, 170);
    CGPathAddLineToPoint(thepath, NULL, 265, 225);
    CGPathAddLineToPoint(thepath, NULL, 250, 150);
    CGPathAddLineToPoint(thepath, NULL, 300, 100);
    CGPathAddLineToPoint(thepath, NULL, 235, 100);
    // This function draws a line from the center of the star (200,125) to each segment's starting point.
    CGPathApply(thepath, context, CGPathApplyCallback);

    // Unnecessary as close subpath will finish this line off but for the sake of consistency, have this here.
    CGPathAddLineToPoint(thepath, NULL, 200, 35);

    CGPathCloseSubpath(thepath);
    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGPathRelease(thepath);
}

DRAW_TEST_F(CGPath, CloseSubpath, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGMutablePathRef thePath = CGPathCreateMutable();
    CGPathMoveToPoint(thePath, NULL, 50, 50);
    CGPathAddLineToPoint(thePath, NULL, 50, 100);
    CGPathAddLineToPoint(thePath, NULL, 100, 100);
    CGPathCloseSubpath(thePath);

    CGPathMoveToPoint(thePath, NULL, 200, 50);
    CGPathAddLineToPoint(thePath, NULL, 200, 100);
    CGPathAddLineToPoint(thePath, NULL, 150, 100);
    CGPathCloseSubpath(thePath);

    CGPathMoveToPoint(thePath, NULL, 100, 200);
    CGPathAddLineToPoint(thePath, NULL, 125, 150);
    CGPathAddLineToPoint(thePath, NULL, 150, 200);
    CGPathCloseSubpath(thePath);

    CGPathCloseSubpath(thePath);
    CGContextAddPath(context, thePath);
    CGContextStrokePath(context);

    CGPathRelease(thePath);
}

// TODO : Enable this test when #2301 is fixed
DISABLED_DRAW_TEST_F(CGPath, GetBoundingBox, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, NULL, 200, 35);
    CGPathAddLineToPoint(thepath, NULL, 165, 100);
    CGPathAddLineToPoint(thepath, NULL, 100, 100);
    CGPathAddLineToPoint(thepath, NULL, 150, 150);
    CGPathAddLineToPoint(thepath, NULL, 135, 225);
    CGPathAddLineToPoint(thepath, NULL, 200, 170);
    CGPathAddLineToPoint(thepath, NULL, 265, 225);
    CGPathAddLineToPoint(thepath, NULL, 250, 150);
    CGPathAddLineToPoint(thepath, NULL, 300, 100);
    CGPathAddLineToPoint(thepath, NULL, 235, 100);
    CGPathAddLineToPoint(thepath, NULL, 200, 35);
    CGPathCloseSubpath(thepath);

    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGRect boundingBox = CGPathGetBoundingBox(thepath);
    CGContextStrokeRect(context, boundingBox);

    CGPathRelease(thepath);
}

static CGRect applyBounds;

static void CGPathApplyCallback(void* context, const CGPathElement* element) {
    CGPoint* points = element->points;
    CGContextMoveToPoint((CGContextRef)context,
                         applyBounds.origin.x + applyBounds.size.width / 2,
                         applyBounds.origin.y + applyBounds.size.height / 2);
    CGContextAddLineToPoint((CGContextRef)context, points[0].x, points[0].y);
    CGContextStrokePath((CGContextRef)context);
}

DRAW_TEST_F(CGPath, PathApplyDraw, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    applyBounds = GetDrawingBounds();
    CGFloat width = applyBounds.size.width;
    CGFloat height = applyBounds.size.height;
    CGFloat xstart = applyBounds.origin.x;
    CGFloat ystart = applyBounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, NULL, xstart + .5 * width, ystart + .1 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .35 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .1 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .3 * width, ystart + .5 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .25 * width, ystart + .9 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .5 * width, ystart + .7 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .75 * width, ystart + .9 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .7 * width, ystart + .5 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .9 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .65 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .5 * width, ystart + .1 * height);
    CGPathCloseSubpath(thepath);

    CGPathApply(thepath, context, CGPathApplyCallback);

    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGPathRelease(thepath);
}

static void _drawArcWithParams(CGContextRef context,
                               CGFloat width,
                               CGFloat height,
                               CGFloat xstart,
                               CGFloat ystart,
                               CGAffineTransform transformation,
                               CGFloat startAngle,
                               CGFloat endAngle,
                               bool clockwise,
                               CGPathDrawingMode mode,
                               int moveToPoint) {
    CGMutablePathRef thepath = CGPathCreateMutable();
    switch (moveToPoint) {
        case 1:
            CGPathMoveToPoint(thepath, &transformation, xstart + .75 * width, ystart);
            break;
        case 2:
            CGPathMoveToPoint(thepath, &transformation, xstart + .75 * width, ystart + .5 * height);
            break;
        case 0:
        default:
            break;
    }
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, startAngle, endAngle, clockwise);

    CGContextAddPath(context, thepath);
    CGContextDrawPath(context, mode);

    CGPathRelease(thepath);
}

static void _drawTest(CGContextRef context,
                      CGFloat width,
                      CGFloat height,
                      CGFloat xstart,
                      CGFloat ystart,
                      CGAffineTransform transformation,
                      CGFloat startAngle,
                      CGFloat endAngle,
                      CGPathDrawingMode mode,
                      int moveToPoint) {
    _drawArcWithParams(context, width, height, xstart, ystart, transformation, startAngle, endAngle, true, mode, moveToPoint);
    transformation = CGAffineTransformTranslate(transformation, .60 * width, 0);
    _drawArcWithParams(context, width, height, xstart, ystart, transformation, endAngle, startAngle, true, mode, moveToPoint);
    transformation = CGAffineTransformTranslate(transformation, width, 0);
    _drawArcWithParams(context, width, height, xstart, ystart, transformation, startAngle, endAngle, false, mode, moveToPoint);
    transformation = CGAffineTransformTranslate(transformation, 1.2 * width, 0);
    _drawArcWithParams(context, width, height, xstart, ystart, transformation, endAngle, startAngle, false, mode, moveToPoint);
}

DRAW_TEST_F(CGPath, ArcCircles_MoveToStart, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();
    CGFloat width = drawingBounds.size.width;
    CGFloat height = drawingBounds.size.height;
    CGFloat xstart = drawingBounds.origin.x;
    CGFloat ystart = drawingBounds.origin.y;

    CGContextSetRGBFillColor(context, 0, 0, 1, 1);
    CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .1 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, 2 * M_PI, kCGPathFillStroke, 2);

    transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .6 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, 2 * M_PI, kCGPathEOFillStroke, 2);
}

DRAW_TEST_F(CGPath, ArcCircles_MoveToSidePoint, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();
    CGFloat width = drawingBounds.size.width;
    CGFloat height = drawingBounds.size.height;
    CGFloat xstart = drawingBounds.origin.x;
    CGFloat ystart = drawingBounds.origin.y;

    CGContextSetRGBFillColor(context, 0, 0, 1, 1);
    CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .1 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, 2 * M_PI, kCGPathFillStroke, 1);

    transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .6 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, 2 * M_PI, kCGPathEOFillStroke, 1);
}

DRAW_TEST_F(CGPath, ArcCircles_NoMove, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();
    CGFloat width = drawingBounds.size.width;
    CGFloat height = drawingBounds.size.height;
    CGFloat xstart = drawingBounds.origin.x;
    CGFloat ystart = drawingBounds.origin.y;

    CGContextSetRGBFillColor(context, 0, 0, 1, 1);
    CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .1 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, 2 * M_PI, kCGPathFillStroke, 0);

    transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .6 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, 2 * M_PI, kCGPathEOFillStroke, 0);
}

DRAW_TEST_F(CGPath, ArcCircles_HalfCircle, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();
    CGFloat width = drawingBounds.size.width;
    CGFloat height = drawingBounds.size.height;
    CGFloat xstart = drawingBounds.origin.x;
    CGFloat ystart = drawingBounds.origin.y;

    CGContextSetRGBFillColor(context, 0, 0, 1, 1);
    CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .1 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, M_PI, kCGPathFillStroke, 1);

    transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformTranslate(transformation, 0, .6 * height);
    transformation = CGAffineTransformScale(transformation, .25, .25);

    _drawTest(context, width, height, xstart, ystart, transformation, 0, M_PI, kCGPathEOFillStroke, 2);
}

static void _CGContextOutlinePoint(CGContextRef context, CGPoint point, CGFloat r, CGFloat g, CGFloat b) {
    CGContextSetRGBStrokeColor(context, r, g, b, 1);

    CGContextStrokeRect(context, CGRectMake(point.x - 2, point.y - 2, 5, 5));
}

static void CGPathControlPointCallback(void* context, const CGPathElement* element) {
    switch (element->type) {
        case kCGPathElementMoveToPoint:
            _CGContextOutlinePoint((CGContextRef)context, element->points[0], 1, 0, 0);
            break;
        case kCGPathElementAddLineToPoint:
            _CGContextOutlinePoint((CGContextRef)context, element->points[0], 0, 1, 0);
            break;
        case kCGPathElementAddQuadCurveToPoint:
            _CGContextOutlinePoint((CGContextRef)context, element->points[0], 0, 1, 1);
            _CGContextOutlinePoint((CGContextRef)context, element->points[1], 0, 1, 1);
            break;
        case kCGPathElementAddCurveToPoint:
            _CGContextOutlinePoint((CGContextRef)context, element->points[0], 1, 0, 1);
            _CGContextOutlinePoint((CGContextRef)context, element->points[1], 1, 0, 1);
            _CGContextOutlinePoint((CGContextRef)context, element->points[2], 1, 0, 1);
            break;
        case kCGPathElementCloseSubpath:
            break;
    }
}

// TODO : Enable this test when #2301 is fixed
DISABLED_DRAW_TEST_F(CGPath, PathApplyControlPointsQuadCurve, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;
    CGFloat xstart = bounds.origin.x;
    CGFloat ystart = bounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, NULL, xstart + .25 * width, ystart + .25 * height);
    CGPathAddQuadCurveToPoint(thepath, NULL, xstart + .31 * width, ystart + .12 * height, xstart + .37 * width, ystart + .25 * height);
    CGPathMoveToPoint(thepath, NULL, xstart + .5 * width, ystart + .25 * height);
    CGPathAddQuadCurveToPoint(thepath, NULL, xstart + .56 * width, ystart + .12 * height, xstart + .62 * width, ystart + .25 * height);
    CGPathMoveToPoint(thepath, NULL, xstart + .25 * width, ystart + .5 * height);
    CGPathAddQuadCurveToPoint(thepath, NULL, xstart + .5 * width, ystart + .78 * height, xstart + .75 * width, ystart + .25 * height);
    CGPathMoveToPoint(thepath, NULL, xstart + .71 * width, ystart + .26 * height);
    CGPathAddQuadCurveToPoint(thepath, NULL, xstart + .75 * width, ystart + .22 * height, xstart + .79 * width, ystart + .27 * height);

    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGPathApply(thepath, context, CGPathControlPointCallback);

    CGPathRelease(thepath);
}

// TODO : Enable this test when #2301 is fixed
DISABLED_DRAW_TEST_F(CGPath, PathApplyControlPointsArcs, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;
    CGFloat xstart = bounds.origin.x;
    CGFloat ystart = bounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformScale(transformation, .8, .8);
    transformation = CGAffineTransformTranslate(transformation, .1 * width, .1 * height);

    CGPathMoveToPoint(thepath, &transformation, xstart + .75 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, M_PI / 2, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .25 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .25 * height, M_PI, 0, false);
    CGPathMoveToPoint(thepath, &transformation, xstart + .5 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .25 * height, M_PI, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .4375 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .125 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .125 * height, M_PI / 2, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .6875 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .125 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .125 * height, M_PI / 2, 0, true);

    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGPathApply(thepath, context, CGPathControlPointCallback);

    CGPathRelease(thepath);
}

// TODO : Enable this test when #2301 is fixed
DISABLED_DRAW_TEST_F(CGPath, PathApplyControlPointsArcsSimple, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;
    CGFloat xstart = bounds.origin.x;
    CGFloat ystart = bounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();

    CGPathMoveToPoint(thepath, NULL, xstart + .5 * width, ystart + .5 * height);
    CGPathAddArc(thepath, NULL, xstart + .5 * width, ystart + .5 * height, .4 * height, 0, M_PI / 2, true);
    CGPathCloseSubpath(thepath);

    CGPathMoveToPoint(thepath, NULL, xstart + .55 * width, ystart + .45 * height);
    CGPathAddArc(thepath, NULL, xstart + .55 * width, ystart + .45 * height, .4 * height, M_PI / 2, 0, true);
    CGPathCloseSubpath(thepath);

    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGPathApply(thepath, context, CGPathControlPointCallback);

    CGPathRelease(thepath);
}

// Fill Tests
DRAW_TEST_F(CGPath, FillArcsSimple, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;
    CGFloat xstart = bounds.origin.x;
    CGFloat ystart = bounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();

    CGPathMoveToPoint(thepath, NULL, xstart + .5 * width, ystart + .5 * height);
    CGPathAddArc(thepath, NULL, xstart + .5 * width, ystart + .5 * height, .4 * height, 0, M_PI / 2, true);
    CGPathCloseSubpath(thepath);

    CGPathMoveToPoint(thepath, NULL, xstart + .55 * width, ystart + .45 * height);
    CGPathAddArc(thepath, NULL, xstart + .55 * width, ystart + .45 * height, .4 * height, M_PI / 2, 0, true);
    CGPathCloseSubpath(thepath);

    CGContextAddPath(context, thepath);
    CGContextSetRGBFillColor(context, 0, 0, 1, 1);
    CGContextFillPath(context);

    CGPathRelease(thepath);
}

// TODO : Enable this test when #2301 is fixed
DISABLED_DRAW_TEST_F(CGPath, BoundingBoxes, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;
    CGFloat xstart = bounds.origin.x;
    CGFloat ystart = bounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformScale(transformation, .8, .8);
    transformation = CGAffineTransformTranslate(transformation, .1 * width, .1 * height);

    CGPathMoveToPoint(thepath, &transformation, xstart + .75 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, M_PI / 2, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .25 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .25 * height, M_PI, 0, false);
    CGPathMoveToPoint(thepath, &transformation, xstart + .5 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .25 * height, M_PI, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .4375 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .125 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .125 * height, M_PI / 2, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .6875 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .125 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .125 * height, M_PI / 2, 0, true);

    // Draw the control points as those affect the bounding box.
    CGPathApply(thepath, context, CGPathControlPointCallback);

    // Don't draw the path itself, we only care about the bounding boxes for these paths.
    CGContextAddRect(context, CGPathGetPathBoundingBox(thepath));
    CGContextSetRGBStrokeColor(context, 1, 0, 0, 1);
    CGContextStrokePath(context);

    CGContextAddRect(context, CGPathGetBoundingBox(thepath));
    CGContextSetRGBStrokeColor(context, 0, 0, 1, 1);
    CGContextStrokePath(context);

    CGPathRelease(thepath);
}

DRAW_TEST_F(CGPath, AddRects, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;
    CGFloat xstart = bounds.origin.x;
    CGFloat ystart = bounds.origin.y;

    CGRect rects[] = { CGRectMake(xstart + width * .1, ystart + height * .1, width * .3, height * .3),
                       CGRectMake(xstart + width * .6, ystart + height * .1, width * .3, height * .3),
                       CGRectMake(xstart + width * .1, ystart + height * .6, width * .3, height * .3),
                       CGRectMake(xstart + width * .6, ystart + height * .6, width * .3, height * .3) };

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, NULL, xstart + width * .1, ystart + height * .1);
    CGPathAddRects(thepath, NULL, rects, 4);
    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);
    CGPathRelease(thepath);
}

DRAW_TEST_F(CGPath, FillArcsComplex, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;
    CGFloat xstart = bounds.origin.x;
    CGFloat ystart = bounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformScale(transformation, .8, .8);
    transformation = CGAffineTransformTranslate(transformation, .1 * width, .1 * height);

    CGPathMoveToPoint(thepath, &transformation, xstart + .75 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, M_PI / 2, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .25 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .25 * height, M_PI, 0, false);
    CGPathMoveToPoint(thepath, &transformation, xstart + .5 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .25 * height, M_PI, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .4375 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .125 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .375 * width, ystart + .5 * height, .125 * height, M_PI / 2, 0, true);
    CGPathMoveToPoint(thepath, &transformation, xstart + .6875 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .125 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .625 * width, ystart + .5 * height, .125 * height, M_PI / 2, 0, true);

    CGContextAddPath(context, thepath);
    CGContextSetRGBFillColor(context, 0, 0, 1, 1);
    CGContextFillPath(context);

    CGPathRelease(thepath);
}

DRAW_TEST_F(CGPath, FillStraightLines, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();
    CGFloat width = drawingBounds.size.width;
    CGFloat height = drawingBounds.size.height;
    CGFloat xstart = drawingBounds.origin.x;
    CGFloat ystart = drawingBounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, NULL, xstart + .5 * width, ystart + .1 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .35 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .1 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .3 * width, ystart + .5 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .25 * width, ystart + .9 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .5 * width, ystart + .7 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .75 * width, ystart + .9 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .7 * width, ystart + .5 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .9 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .65 * width, ystart + .3 * height);
    CGPathAddLineToPoint(thepath, NULL, xstart + .5 * width, ystart + .1 * height);
    CGPathCloseSubpath(thepath);

    CGContextAddPath(context, thepath);
    CGContextSetRGBFillColor(context, 0, 0, 1, 1);
    CGContextFillPath(context);

    CGPathRelease(thepath);
}

DRAW_TEST_F(CGPath, AddLinesWithoutMove, UIKitMimicTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();
    CGFloat width = drawingBounds.size.width;
    CGFloat height = drawingBounds.size.height;
    CGFloat xstart = drawingBounds.origin.x;
    CGFloat ystart = drawingBounds.origin.y;

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPoint points[20];

    for (int i = 0; i < 20; i += 2) {
        points[i] = { xstart + ((i + 1) / 20.0) * width, ystart + height * .2 };
        points[i + 1] = { xstart + ((i + 1) / 20.0) * width, ystart + height * .8 };
    }
    CGPathAddLines(thepath, NULL, points, 20);
    CGContextAddPath(context, thepath);
    CGContextStrokePath(context);

    CGPathRelease(thepath);
}