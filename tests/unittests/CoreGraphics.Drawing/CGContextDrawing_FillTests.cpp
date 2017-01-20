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

DRAW_TEST_F(CGContextFill, ClearRect, WhiteBackgroundTest<>) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSetRGBFillColor(context, 1.0, 0.0, 0.0, 1);
    CGContextFillRect(context, bounds);

    CGRect borderRect = CGRectInset(bounds, 30, 50);
    CGContextClearRect(context, borderRect);
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
