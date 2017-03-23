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

DISABLED_DRAW_TEST_F(CGContextFill, ConcentricCirclesWinding, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGPoint center = _CGRectGetCenter(bounds);

    CGMutablePathRef concentricCirclesPath = CGPathCreateMutable();

    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 50, 50 }, center));
    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 100, 100 }, center));
    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 150, 150 }, center));
    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 200, 200 }, center));

    CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 0.5);
    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);

    CGContextAddPath(context, concentricCirclesPath);
    CGContextDrawPath(context, kCGPathFillStroke);

    CGPathRelease(concentricCirclesPath);
}

DISABLED_DRAW_TEST_F(CGContextFill, ConcentricCirclesEvenOdd, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGPoint center = _CGRectGetCenter(bounds);

    CGMutablePathRef concentricCirclesPath = CGPathCreateMutable();

    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 50, 50 }, center));
    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 100, 100 }, center));
    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 150, 150 }, center));
    CGPathAddEllipseInRect(concentricCirclesPath, nullptr, _CGRectCenteredOnPoint({ 200, 200 }, center));

    CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 0.5);
    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);

    CGContextAddPath(context, concentricCirclesPath);
    CGContextDrawPath(context, kCGPathEOFillStroke);

    CGPathRelease(concentricCirclesPath);
}

DISABLED_DRAW_TEST_F(CGContextFill, ConcentricRectsWinding, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGPoint center = _CGRectGetCenter(bounds);

    CGMutablePathRef path = CGPathCreateMutable();

    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 50, 50 }, center));
    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 100, 100 }, center));
    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 150, 150 }, center));
    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 200, 200 }, center));

    CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 0.5);
    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);

    CGContextAddPath(context, path);
    CGContextDrawPath(context, kCGPathFillStroke);

    CGPathRelease(path);
}

DISABLED_DRAW_TEST_F(CGContextFill, ConcentricRectsEvenOdd, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGPoint center = _CGRectGetCenter(bounds);

    CGMutablePathRef path = CGPathCreateMutable();

    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 50, 50 }, center));
    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 100, 100 }, center));
    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 150, 150 }, center));
    CGPathAddRect(path, nullptr, _CGRectCenteredOnPoint({ 200, 200 }, center));

    CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 0.5);
    CGContextSetRGBStrokeColor(context, 1.0, 0.0, 0.0, 1.0);

    CGContextAddPath(context, path);
    CGContextDrawPath(context, kCGPathEOFillStroke);

    CGPathRelease(path);
}

class CGContextArcFill : public WhiteBackgroundTest<>, public ::testing::WithParamInterface<::testing::tuple<CGPoint, int>> {
    CFStringRef CreateOutputFilename() {
        CGPoint sweep = ::testing::get<0>(GetParam());
        int direction = ::testing::get<1>(GetParam());
        return CFStringCreateWithFormat(nullptr,
                                        nullptr,
                                        CFSTR("TestImage.CGContextFill.Arc.sweep(%0.0f--%0.0f).direction.%d.png"),
                                        sweep.x,
                                        sweep.y,
                                        direction);
    }
};

DRAW_TEST_P(CGContextArcFill, FillArc) {
    CGContextRef context = GetDrawingContext();
    CGPoint sweep = ::testing::get<0>(GetParam());
    int direction = ::testing::get<1>(GetParam());
    CGContextAddArc(context, 50, 50, 50, sweep.x, sweep.y, direction);
    CGContextFillPath(context);
}

static CGPoint sweep[] = { CGPointMake(0, M_PI),
                           CGPointMake(2 * M_PI, 0),
                           CGPointMake(0.3 * M_PI, 0.6 * M_PI),
                           CGPointMake(0, 1.9 * M_PI) };
static int directions[] = { 0, 1 };

INSTANTIATE_TEST_CASE_P(CGContextFill, CGContextArcFill, ::testing::Combine(::testing::ValuesIn(sweep), ::testing::ValuesIn(directions)));
