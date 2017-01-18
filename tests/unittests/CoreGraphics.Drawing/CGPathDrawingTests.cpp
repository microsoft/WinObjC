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

DISABLED_DRAW_TEST_F(CGPath, AddCurveToPoint, UIKitMimicTest<>) {
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

DISABLED_DRAW_TEST_F(CGPath, AddLineToPoint, UIKitMimicTest<>) {
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

DISABLED_DRAW_TEST_F(CGPath, AddPath, UIKitMimicTest<>) {
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

DISABLED_DRAW_TEST_F(CGPath, AddQuadCurveToPoint, UIKitMimicTest<>) {
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

DISABLED_DRAW_TEST_F(CGPath, AddRect, UIKitMimicTest<>) {
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

DISABLED_DRAW_TEST_F(CGPath, Apply, UIKitMimicTest<>) {
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

DISABLED_DRAW_TEST_F(CGPath, CloseSubpath, UIKitMimicTest<>) {
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
