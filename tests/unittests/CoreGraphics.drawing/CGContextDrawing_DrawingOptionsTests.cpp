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

static CGLineCap lineCaps[] = { kCGLineCapButt, kCGLineCapSquare, kCGLineCapRound };
static CGLineJoin lineJoins[] = { kCGLineJoinBevel, kCGLineJoinRound };
static CGFloat miterLimits[] = { 1.5, 1.8, 2, 3 };
struct PhaseDashCount {
    CGFloat phase;
    const CGFloat dashPattern[4];
    size_t count;
};

struct PhaseDashCount dashParams[] = { { 0, { 5, 2 }, 2 },
                                       { 5, { 5, 2 }, 2 },
                                       { 0, { 5, 2, 3, 1 }, 4 },
                                       { 0, { 1, 1 }, 2 },
                                       { 1, { 1, 1 }, 2 } };

class CGDrawLineCaps : public WhiteBackgroundTest<>, public ::testing::WithParamInterface<CGLineCap> {
    CFStringRef CreateOutputFilename() {
        CGLineCap lineCap = GetParam();

        const char* lineCapName;
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

        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.LineWithCap.%s.png"), lineCapName);
    }
};

class CGDrawLineJoins : public WhiteBackgroundTest<>, public ::testing::WithParamInterface<CGLineJoin> {
    CFStringRef CreateOutputFilename() {
        CGLineJoin lineJoin = GetParam();

        const char* lineJoinName;
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

        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.LineWithJoin.%s.png"), lineJoinName);
    }
};

class CGDrawLineMiter : public WhiteBackgroundTest<>, public ::testing::WithParamInterface<CGFloat> {
    CFStringRef CreateOutputFilename() {
        CGFloat miterLimit = GetParam();

        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.LineWithMiter.%f.png"), miterLimit);
    }
};

class CGDrawLineDash : public WhiteBackgroundTest<>, public ::testing::WithParamInterface<struct PhaseDashCount> {
    CFStringRef CreateOutputFilename() {
        PhaseDashCount dashes = GetParam();

        CFMutableStringRef dashString =
            CFStringCreateMutableCopy(NULL, 0, CFStringCreateWithFormat(nullptr, nullptr, CFSTR("%f"), dashes.dashPattern[0]));
        for (int i = 1; i < dashes.count; i++) {
            CFStringAppendFormat(dashString, NULL, CFSTR(".%f"), dashes.dashPattern[i]);
        }

        return CFStringCreateWithFormat(nullptr,
                                        nullptr,
                                        CFSTR("TestImage.LineWithPhaseDashes.%f.%@.%lu.png"),
                                        dashes.phase,
                                        dashString,
                                        dashes.count);
    }
};

static void drawStrokeTestWithParams(CGContextRef context, CGRect bounds) {
    CGContextSetLineWidth(context, 25);
    CGContextSetRGBStrokeColor(context, 0, 0, 0, 1);

    CGFloat x = bounds.origin.x;
    CGFloat y = bounds.origin.y;
    CGFloat width = bounds.size.width;
    CGFloat height = bounds.size.height;

    CGContextMoveToPoint(context, x + width * .1, y + height * .25);
    CGContextAddLineToPoint(context, x + width * .2, y + height * .75);
    CGContextAddLineToPoint(context, x + width * .3, y + height * .25);
    CGContextAddLineToPoint(context, x + width * .4, y + height * .75);
    CGContextAddLineToPoint(context, x + width * .6, y + height * .25);
    CGContextAddLineToPoint(context, x + width * .8, y + height * .75);

    CGContextStrokePath(context);
}

DRAW_TEST_P(CGDrawLineJoins, LineJoin) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();

    CGLineJoin lineJoin = GetParam();
    CGContextSetLineJoin(context, lineJoin);
    drawStrokeTestWithParams(context, drawingBounds);
}

DRAW_TEST_P(CGDrawLineCaps, LineCap) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();

    CGLineCap lineCap = GetParam();
    CGContextSetLineCap(context, lineCap);
    drawStrokeTestWithParams(context, drawingBounds);
}

DRAW_TEST_P(CGDrawLineMiter, LineMiter) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();

    CGFloat miterLimit = GetParam();
    CGContextSetLineJoin(context, kCGLineJoinMiter);
    CGContextSetMiterLimit(context, miterLimit);
    drawStrokeTestWithParams(context, drawingBounds);
}

DRAW_TEST_P(CGDrawLineDash, LineDash) {
    CGContextRef context = GetDrawingContext();
    CGRect drawingBounds = GetDrawingBounds();

    struct PhaseDashCount dashes = GetParam();
    CGContextSetLineDash(context, dashes.phase, dashes.dashPattern, dashes.count);
    drawStrokeTestWithParams(context, drawingBounds);
}

INSTANTIATE_TEST_CASE_P(CGContextLineOptions, CGDrawLineJoins, ::testing::ValuesIn(lineJoins));

INSTANTIATE_TEST_CASE_P(CGContextLineOptions, CGDrawLineCaps, ::testing::ValuesIn(lineCaps));

INSTANTIATE_TEST_CASE_P(CGContextLineOptions, CGDrawLineMiter, ::testing::ValuesIn(miterLimits));

INSTANTIATE_TEST_CASE_P(CGContextLineOptions, CGDrawLineDash, ::testing::ValuesIn(dashParams));