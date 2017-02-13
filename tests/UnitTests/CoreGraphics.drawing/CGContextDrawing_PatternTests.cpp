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

#pragma region Stencil Pattern

static void drawStencilStar(void* info, CGContextRef context) {
    double r = 0.8 * 16 / 2;
    double theta = 2 * M_PI * (2.0 / 5.0); // 144 degrees

    CGContextTranslateCTM(context, 16 / 2, 16 / 2);

    CGContextMoveToPoint(context, 0, r);
    for (int i = 1; i < 5; i++) {
        CGContextAddLineToPoint(context, r * sin(i * theta), r * cos(i * theta));
    }
    CGContextClosePath(context);
    CGContextFillPath(context);
}

static void drawStencilBox(void* info, CGContextRef context) {
    CGContextFillRect(context, CGRectMake(0, 0, 8, 8));
}

struct PatternCallback {
    const char* name;
    CGPatternDrawPatternCallback callback;
};

struct StencilColor {
    const char* name;
    float color[4];
};

PatternCallback stencilPatternCallback[] = { { "drawStencilStar", &drawStencilStar }, { "drawStencilBox", &drawStencilBox } };

StencilColor stencilColors[] = { { "orange", { 1, 0.64, 0, 1 } }, { "gold", { 1, 0.84, 0, 1 } },    { "red", { 1, 0, 0, 1 } },
                                 { "green", { 0, 1, 0, 1 } },     { "blue", { 0, 0, 1, 1 } },       { "cyan", { 0, 1, 1, 1 } },
                                 { "teal", { 0, 0.5, 0.5, 1 } },  { "purple", { 0.5, 0, 0.5, 1 } }, { "Maroon", { 0.5, 0, 0, 1 } } };

int patternsizes[] = { 1, 2, 4, 8, 13, 10, 16, 20, 32, 128, 241 };

//<PatternCallback,StencilColor,pattern size>
class CGPatternStencil : public WhiteBackgroundTest<>,
                         public ::testing::WithParamInterface<::testing::tuple<PatternCallback, StencilColor, int>> {
    CFStringRef CreateOutputFilename() {
        PatternCallback stencil = ::testing::get<0>(GetParam());
        StencilColor stencilColor = ::testing::get<1>(GetParam());
        int size = ::testing::get<2>(GetParam());

        return CFStringCreateWithFormat(nullptr,
                                        nullptr,
                                        CFSTR("TestImage.CGContext.CGPatternStencil.%s.%s.%d.png"),
                                        stencil.name,
                                        stencilColor.name,
                                        size);
    }
};

TEST_P(CGPatternStencil, DrawStencils) {
    CGPatternDrawPatternCallback callback = ::testing::get<0>(GetParam()).callback;
    const CGFloat* stencilColor = ::testing::get<1>(GetParam()).color;
    int size = ::testing::get<2>(GetParam());

    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    static const CGPatternCallbacks callbacks = { 0, callback, NULL };

    CGColorSpaceRef baseSpace = CGColorSpaceCreateDeviceRGB();
    CGColorSpaceRef patternSpace = CGColorSpaceCreatePattern(baseSpace);
    CGContextSetFillColorSpace(context, patternSpace);
    CGColorSpaceRelease(patternSpace);
    CGColorSpaceRelease(baseSpace);

    CGPatternRef pattern = CGPatternCreate(
        NULL, CGRectMake(0, 0, size, size), CGAffineTransformIdentity, size, size, kCGPatternTilingConstantSpacing, false, &callbacks);

    CGContextSetFillPattern(context, pattern, stencilColor);
    CGPatternRelease(pattern);
    CGContextFillRect(context, bounds);
}

INSTANTIATE_TEST_CASE_P(CGPatternTests,
                        CGPatternStencil,
                        ::testing::Combine(::testing::ValuesIn(stencilPatternCallback),
                                           ::testing::ValuesIn(stencilColors),
                                           ::testing::ValuesIn(patternsizes)));

#pragma endregion Stencil Pattern

#pragma region Colored Pattern

void drawColoredPatternMultiSquare(void* info, CGContextRef context) {
    CGFloat subunit = 5; // the pattern cell itself is 16 by 18

    CGRect myRect1 = { { 0, 0 }, { subunit, subunit } }, myRect2 = { { subunit, subunit }, { subunit, subunit } },
           myRect3 = { { 0, subunit }, { subunit, subunit } }, myRect4 = { { subunit, 0 }, { subunit, subunit } };

    CGContextSetRGBFillColor(context, 0, 0, 1, 0.5);
    CGContextFillRect(context, myRect1);
    CGContextSetRGBFillColor(context, 1, 0, 0, 0.5);
    CGContextFillRect(context, myRect2);
    CGContextSetRGBFillColor(context, 0, 1, 0, 0.5);
    CGContextFillRect(context, myRect3);
    CGContextSetRGBFillColor(context, .5, 0, .5, 0.5);
    CGContextFillRect(context, myRect4);
}

PatternCallback ColoredPatternCallback[] = { { "drawColoredPatternMultiSquare", &drawColoredPatternMultiSquare } };

//<PatternCallback,alpha,pattern size>
class CGPatternColored : public WhiteBackgroundTest<>,
                         public ::testing::WithParamInterface<::testing::tuple<PatternCallback, CGFloat, int>> {
    CFStringRef CreateOutputFilename() {
        PatternCallback pattern = ::testing::get<0>(GetParam());
        CGFloat alpha = ::testing::get<1>(GetParam());
        int size = ::testing::get<2>(GetParam());

        return CFStringCreateWithFormat(nullptr,
                                        nullptr,
                                        CFSTR("TestImage.CGContext.CGPatternColored.%s.size.%d.A%1.01f.png"),
                                        pattern.name,
                                        size,
                                        alpha);
    }
};

TEST_P(CGPatternColored, ColoredSquare) {
    CGPatternDrawPatternCallback callback = ::testing::get<0>(GetParam()).callback;
    CGFloat alpha = ::testing::get<1>(GetParam());
    int size = ::testing::get<2>(GetParam());

    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    static const CGPatternCallbacks callbacks = { 0, callback, NULL };

    CGColorSpaceRef patternSpace = CGColorSpaceCreatePattern(NULL);
    CGContextSetFillColorSpace(context, patternSpace);
    CGColorSpaceRelease(patternSpace);

    CGPatternRef pattern = CGPatternCreate(NULL,
                                           CGRectMake(0, 0, size / 2, size / 2),
                                           CGAffineTransformMake(1, 0, 0, 1, 0, 0),
                                           size,
                                           size,
                                           kCGPatternTilingConstantSpacing,
                                           true,
                                           &callbacks);

    CGContextSetFillPattern(context, pattern, &alpha);
    CGPatternRelease(pattern);
    CGContextFillRect(context, bounds);
}

static CGFloat alphas[] = { 0.0f, 0.25f, 0.35f, 0.42f, 0.5f, 0.75f, 0.85f, 0.95f, 1.f };

INSTANTIATE_TEST_CASE_P(CGPatternTests,
                        CGPatternColored,
                        ::testing::Combine(::testing::ValuesIn(ColoredPatternCallback),
                                           ::testing::ValuesIn(alphas),
                                           ::testing::ValuesIn(patternsizes)));

#pragma endregion Colored Pattern