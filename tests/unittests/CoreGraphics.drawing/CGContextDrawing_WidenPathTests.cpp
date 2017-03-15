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

CGLineCap lineCaps[] = { kCGLineCapButt, kCGLineCapSquare, kCGLineCapRound };
CGLineJoin lineJoins[] = { kCGLineJoinMiter, kCGLineJoinBevel, kCGLineJoinRound };
CGFloat lineWidths[] = { 0, 1, 10, 20 };
CGFloat miterLimits[] = { 0, 1, 5 };
bool shouldUseContext[] = { false, true };

class CGPathCopyByStroking_Lines : public WhiteBackgroundTest<>,
                                   public ::testing::WithParamInterface<::testing::tuple<CGLineCap, CGLineJoin, CGFloat, CGFloat, bool>> {
    CFStringRef CreateOutputFilename() {
        CGLineCap lineCap = ::testing::get<0>(GetParam());
        CGLineJoin lineJoin = ::testing::get<1>(GetParam());
        CGFloat lineWidth = ::testing::get<2>(GetParam());
        CGFloat miterLimit = ::testing::get<3>(GetParam());

        char* lineCapName;
        switch (lineCap) {
            case kCGLineCapButt:
                lineCapName = "LineCapButt";
                break;
            case kCGLineCapSquare:
                lineCapName = "LineCapSquare";
                break;
            case kCGLineCapRound:
                lineCapName = "LineCapRound";
                break;
            default:
                break;
        }

        char* lineJoinName;
        switch (lineJoin) {
            case kCGLineJoinMiter:
                lineJoinName = "LineJoinMiter";
                break;
            case kCGLineJoinBevel:
                lineJoinName = "LineJoinBevel";
                break;
            case kCGLineJoinRound:
                lineJoinName = "LineJoinRound";
                break;
            default:
                break;
        }

        return CFStringCreateWithFormat(
            nullptr, nullptr, CFSTR("TestImage.CopyByStroking_Lines.%f.%f.%s.%s.png"), lineWidth, miterLimit, lineJoinName, lineCapName);
    }
};

class CGPathCopyByStroking_Curves : public WhiteBackgroundTest<>,
                                    public ::testing::WithParamInterface<::testing::tuple<CGLineCap, CGLineJoin, CGFloat, CGFloat, bool>> {
    CFStringRef CreateOutputFilename() {
        CGLineCap lineCap = ::testing::get<0>(GetParam());
        CGLineJoin lineJoin = ::testing::get<1>(GetParam());
        CGFloat lineWidth = ::testing::get<2>(GetParam());
        CGFloat miterLimit = ::testing::get<3>(GetParam());

        char* lineCapName;
        switch (lineCap) {
            case kCGLineCapButt:
                lineCapName = "LineCapButt";
                break;
            case kCGLineCapSquare:
                lineCapName = "LineCapSquare";
                break;
            case kCGLineCapRound:
                lineCapName = "LineCapRound";
                break;
            default:
                break;
        }

        char* lineJoinName;
        switch (lineJoin) {
            case kCGLineJoinMiter:
                lineJoinName = "LineJoinMiter";
                break;
            case kCGLineJoinBevel:
                lineJoinName = "LineJoinBevel";
                break;
            case kCGLineJoinRound:
                lineJoinName = "LineJoinRound";
                break;
            default:
                break;
        }

        return CFStringCreateWithFormat(
            nullptr, nullptr, CFSTR("TestImage.CopyByStroking_Arcs.%f.%f.%s.%s.png"), lineWidth, miterLimit, lineJoinName, lineCapName);
    }
};

void drawStrokeTestWithParams(
    CGContextRef context, CGPathRef path, CGLineCap cap, CGLineJoin join, CGFloat lineWidth, CGFloat miterLimit, bool useContext) {
    if (useContext) {
        CGContextSaveGState(context);
        CGContextAddPath(context, path);
        CGContextSetLineWidth(context, lineWidth);
        CGContextSetLineJoin(context, join);
        CGContextSetLineCap(context, cap);
        CGContextSetMiterLimit(context, miterLimit);

        CGContextReplacePathWithStrokedPath(context);
        CGContextRestoreGState(context);
    } else {
        auto widenedPath = woc::MakeStrongCF<CGPathRef>(CGPathCreateCopyByStrokingPath(path, NULL, lineWidth, cap, join, miterLimit));
        CGContextAddPath(context, widenedPath);
    }
    CGContextSetRGBStrokeColor(context, 0, 0, 1, 1);
    CGContextStrokePath(context);
}

DRAW_TEST_P(CGPathCopyByStroking_Lines, PathWiden) {
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

    CGLineCap lineCap = ::testing::get<0>(GetParam());
    CGLineJoin lineJoin = ::testing::get<1>(GetParam());
    CGFloat lineWidth = ::testing::get<2>(GetParam());
    CGFloat miterLimit = ::testing::get<3>(GetParam());
    bool useContext = ::testing::get<4>(GetParam());

    drawStrokeTestWithParams(context, thepath, lineCap, lineJoin, lineWidth, miterLimit, useContext);

    CGPathRelease(thepath);
}

DRAW_TEST_P(CGPathCopyByStroking_Curves, PathWiden) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();
    CGFloat width = drawingBounds.size.width;
    CGFloat height = drawingBounds.size.height;
    CGFloat xstart = drawingBounds.origin.x;
    CGFloat ystart = drawingBounds.origin.y;

    CGAffineTransform transformation = CGAffineTransformIdentity;
    transformation = CGAffineTransformScale(transformation, .8, .8);
    transformation = CGAffineTransformTranslate(transformation, .1 * width, .1 * height);

    CGMutablePathRef thepath = CGPathCreateMutable();
    CGPathMoveToPoint(thepath, &transformation, xstart + .75 * width, ystart + .5 * height);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, 0, M_PI / 2, true);
    CGPathAddArc(thepath, &transformation, xstart + .5 * width, ystart + .5 * height, .5 * height, M_PI / 2, 0, true);

    CGLineCap lineCap = ::testing::get<0>(GetParam());
    CGLineJoin lineJoin = ::testing::get<1>(GetParam());
    CGFloat lineWidth = ::testing::get<2>(GetParam());
    CGFloat miterLimit = ::testing::get<3>(GetParam());
    bool useContext = ::testing::get<4>(GetParam());

    drawStrokeTestWithParams(context, thepath, lineCap, lineJoin, lineWidth, miterLimit, useContext);

    CGPathRelease(thepath);
}

INSTANTIATE_TEST_CASE_P(CGPathWidenTest,
                        CGPathCopyByStroking_Lines,
                        ::testing::Combine(::testing::ValuesIn(lineCaps),
                                           ::testing::ValuesIn(lineJoins),
                                           ::testing::ValuesIn(lineWidths),
                                           ::testing::ValuesIn(miterLimits),
                                           ::testing::ValuesIn(shouldUseContext)));
INSTANTIATE_TEST_CASE_P(CGPathWidenTest,
                        CGPathCopyByStroking_Curves,
                        ::testing::Combine(::testing::ValuesIn(lineCaps),
                                           ::testing::ValuesIn(lineJoins),
                                           ::testing::ValuesIn(lineWidths),
                                           ::testing::ValuesIn(miterLimits),
                                           ::testing::ValuesIn(shouldUseContext)));
