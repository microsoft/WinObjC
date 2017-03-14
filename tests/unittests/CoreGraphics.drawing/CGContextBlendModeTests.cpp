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

struct CGNamedBlendMode {
    const char* name;
    CGBlendMode blendMode;
};

CGNamedBlendMode pdfBlendModes[] =
    { { "kCGBlendModeMultiply", kCGBlendModeMultiply },     { "kCGBlendModeScreen", kCGBlendModeScreen },
      { "kCGBlendModeDarken", kCGBlendModeDarken },         { "kCGBlendModeLighten", kCGBlendModeLighten },
      { "kCGBlendModeColorBurn", kCGBlendModeColorBurn },   { "kCGBlendModeColorDodge", kCGBlendModeColorDodge },
      { "kCGBlendModeOverlay", kCGBlendModeOverlay },       { "kCGBlendModeSoftLight", kCGBlendModeSoftLight },
      { "kCGBlendModeHardLight", kCGBlendModeHardLight },   { "kCGBlendModeDifference", kCGBlendModeDifference },
      { "kCGBlendModeExclusion", kCGBlendModeExclusion },   { "kCGBlendModeHue", kCGBlendModeHue },
      { "kCGBlendModeSaturation", kCGBlendModeSaturation }, { "kCGBlendModeColor", kCGBlendModeColor },
      { "kCGBlendModeLuminosity", kCGBlendModeLuminosity } };

CGNamedBlendMode blendOperators[] = { { "kCGBlendModeClear", kCGBlendModeClear } };

CGNamedBlendMode compositionModesWithoutPlusDarker[] = {
    { "kCGBlendModeNormal", kCGBlendModeNormal },
    { "kCGBlendModeDestinationOver", kCGBlendModeDestinationOver },
    { "kCGBlendModeSourceIn", kCGBlendModeSourceIn },
    { "kCGBlendModeDestinationIn", kCGBlendModeDestinationIn },
    { "kCGBlendModeSourceOut", kCGBlendModeSourceOut },
    { "kCGBlendModeDestinationOut", kCGBlendModeDestinationOut },
    { "kCGBlendModeSourceAtop", kCGBlendModeSourceAtop },
    { "kCGBlendModeDestinationAtop", kCGBlendModeDestinationAtop },
    { "kCGBlendModeXOR", kCGBlendModeXOR },
    { "kCGBlendModePlusLighter", kCGBlendModePlusLighter },
    { "kCGBlendModeCopy", kCGBlendModeCopy },
};

CGNamedBlendMode compositionModes[] = {
    { "kCGBlendModeNormal", kCGBlendModeNormal },
    { "kCGBlendModeDestinationOver", kCGBlendModeDestinationOver },
    { "kCGBlendModeSourceIn", kCGBlendModeSourceIn },
    { "kCGBlendModeDestinationIn", kCGBlendModeDestinationIn },
    { "kCGBlendModeSourceOut", kCGBlendModeSourceOut },
    { "kCGBlendModeDestinationOut", kCGBlendModeDestinationOut },
    { "kCGBlendModeSourceAtop", kCGBlendModeSourceAtop },
    { "kCGBlendModeDestinationAtop", kCGBlendModeDestinationAtop },
    { "kCGBlendModeXOR", kCGBlendModeXOR },
    { "kCGBlendModePlusLighter", kCGBlendModePlusLighter },
    { "kCGBlendModeCopy", kCGBlendModeCopy },
    { "kCGBlendModePlusDarker", kCGBlendModePlusDarker },
};

class CGContextBlendMode : public WhiteBackgroundTest<>, public ::testing::WithParamInterface<::testing::tuple<bool, CGNamedBlendMode>> {
    CFStringRef CreateOutputFilename() {
        const char* blendModeName = ::testing::get<1>(GetParam()).name;
        bool useTransparencyLayer = ::testing::get<0>(GetParam());
        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.CGContext.Blending_%s%s.png"), useTransparencyLayer ? "Layered_" : "", blendModeName);
    }
};

DRAW_TEST_P(CGContextBlendMode, OverlappedRects) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGBlendMode blendMode = ::testing::get<1>(GetParam()).blendMode;
    bool useTransparencyLayer = ::testing::get<0>(GetParam());

    bounds = CGRectInset(bounds, 8.f, 8.f);

    CGFloat unitHeight = bounds.size.height / 4.f;

    CGContextSetLineWidth(context, 6.0f);

    // Draw two rects and two lines, at both alphas.
    CGRect cursor = _CGRectCenteredOnPoint({2.f * bounds.size.width / 3.f, unitHeight}, {bounds.origin.x +(bounds.size.width / 3.f), bounds.origin.y + (unitHeight / 2.f)});

    CGContextSetRGBFillColor(context, .25, .71, .95, 1.0);
    CGContextSetRGBStrokeColor(context, .25, .71, .95, 1.0);

    CGContextFillRect(context, cursor);
    cursor.origin.y += unitHeight;
    CGContextMoveToPoint(context, CGRectGetMinX(cursor), CGRectGetMinY(cursor));
    CGContextAddLineToPoint(context, CGRectGetMaxX(cursor), CGRectGetMaxY(cursor));
    CGContextStrokePath(context);
    cursor.origin.y += unitHeight;

    CGContextSetRGBFillColor(context, .25, .71, .95, 0.5);
    CGContextSetRGBStrokeColor(context, .25, .71, .95, 0.5);

    CGContextFillRect(context, cursor);
    cursor.origin.y += unitHeight;
    CGContextMoveToPoint(context, CGRectGetMinX(cursor), CGRectGetMinY(cursor));
    CGContextAddLineToPoint(context, CGRectGetMaxX(cursor), CGRectGetMaxY(cursor));
    CGContextStrokePath(context);
    cursor.origin.y += unitHeight;

    CGContextSetBlendMode(context, blendMode);

    if (useTransparencyLayer) {
        CGContextBeginTransparencyLayer(context, nullptr);
    }

    cursor = _CGRectCenteredOnPoint({2.f * bounds.size.width / 3.f, unitHeight}, {bounds.origin.x +(2.f * bounds.size.width / 3.f), bounds.origin.y + (unitHeight / 2.f)});
    CGContextSetRGBFillColor(context, .95, .25, .66, 1.0);
    CGContextSetRGBStrokeColor(context, .95, .25, .66, 1.0);

    CGContextFillRect(context, cursor);
    cursor.origin.y += unitHeight;
    CGContextMoveToPoint(context, CGRectGetMinX(cursor), CGRectGetMaxY(cursor));
    CGContextAddLineToPoint(context, CGRectGetMaxX(cursor), CGRectGetMinY(cursor));
    CGContextStrokePath(context);
    cursor.origin.y += unitHeight;

    CGContextSetRGBFillColor(context, .95, .25, .66, 0.5);
    CGContextSetRGBStrokeColor(context, .95, .25, .66, 0.5);

    CGContextFillRect(context, cursor);
    cursor.origin.y += unitHeight;
    CGContextMoveToPoint(context, CGRectGetMinX(cursor), CGRectGetMaxY(cursor));
    CGContextAddLineToPoint(context, CGRectGetMaxX(cursor), CGRectGetMinY(cursor));
    CGContextStrokePath(context);
    cursor.origin.y += unitHeight;

    if (useTransparencyLayer) {
        CGContextEndTransparencyLayer(context);
    }
}

// Disabled: layered = false; not supported. plus darker; not supported.
DISABLED_INSTANTIATE_TEST_CASE_P(CompositionModes,
                                 CGContextBlendMode,
                                 ::testing::Combine(::testing::Values(true), ::testing::ValuesIn(compositionModesWithoutPlusDarker)),
                                 ::testing::Combine(::testing::Values(false), ::testing::ValuesIn(compositionModes)));

INSTANTIATE_TEST_CASE_P(AdobePDFBlendModes,
                        CGContextBlendMode,
                        ::testing::Combine(::testing::Values(false, true), ::testing::ValuesIn(pdfBlendModes)));

#if 0
// Disabled: there is no supported configuration of this test, so we cannot fulfill the requirement
// that DISABLED_INSTANTIATE_TEST_CASE_P have a set of "enabled" values.
INSTANTIATE_TEST_CASE_P(OperatorBlendModes,
                        CGContextBlendMode,
                        ::testing::Combine(::testing::Values(false, true), ::testing::ValuesIn(blendOperators)));
#endif
