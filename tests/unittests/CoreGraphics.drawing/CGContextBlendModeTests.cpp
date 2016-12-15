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

CGNamedBlendMode porterDuffBlendModes[] =
    { { "kCGBlendModeMultiply", kCGBlendModeMultiply },     { "kCGBlendModeScreen", kCGBlendModeScreen },
      { "kCGBlendModeDarken", kCGBlendModeDarken },         { "kCGBlendModeLighten", kCGBlendModeLighten },
      { "kCGBlendModeColorBurn", kCGBlendModeColorBurn },   { "kCGBlendModeColorDodge", kCGBlendModeColorDodge },
      { "kCGBlendModeOverlay", kCGBlendModeOverlay },       { "kCGBlendModeSoftLight", kCGBlendModeSoftLight },
      { "kCGBlendModeHardLight", kCGBlendModeHardLight },   { "kCGBlendModeDifference", kCGBlendModeDifference },
      { "kCGBlendModeExclusion", kCGBlendModeExclusion },   { "kCGBlendModeHue", kCGBlendModeHue },
      { "kCGBlendModeSaturation", kCGBlendModeSaturation }, { "kCGBlendModeColor", kCGBlendModeColor },
      { "kCGBlendModeLuminosity", kCGBlendModeLuminosity } };

CGNamedBlendMode blendOperators[] = { { "kCGBlendModeClear", kCGBlendModeClear } };

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

static CGFloat alphas[] = { 0.5f, 1.f };

class CGContextBlendMode : public WhiteBackgroundTest<>, public ::testing::WithParamInterface<::testing::tuple<CGFloat, CGNamedBlendMode>> {
    CFStringRef CreateOutputFilename() {
        const char* blendModeName = ::testing::get<1>(GetParam()).name;
        CGFloat alpha = ::testing::get<0>(GetParam());
        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.CGContext.Blending_%s.A%1.01f.png"), blendModeName, alpha);
    }
};

DRAW_TEST_P(CGContextBlendMode, OverlappedRects) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();
    CGBlendMode blendMode = ::testing::get<1>(GetParam()).blendMode;
    CGFloat alpha = ::testing::get<0>(GetParam());

    bounds = CGRectInset(bounds, 16.f, 16.f);

    CGPoint firstEllipseCenter{ bounds.origin.x + bounds.size.width / 3.f, bounds.origin.y + bounds.size.height / 2.f };
    CGPoint secondEllipseCenter{ firstEllipseCenter.x + (bounds.size.width / 3.f), firstEllipseCenter.y };

    CGContextSetRGBFillColor(context, .25, .71, .95, alpha);
    CGContextFillRect(context, _CGRectCenteredOnPoint({ bounds.size.height, bounds.size.height }, firstEllipseCenter));

    CGContextSetBlendMode(context, blendMode);

    CGContextSetRGBFillColor(context, .95, .25, .66, alpha);
    CGContextFillRect(context, _CGRectCenteredOnPoint({ bounds.size.height, bounds.size.height }, secondEllipseCenter));
}

INSTANTIATE_TEST_CASE_P(DISABLED_CompositionModes,
                        CGContextBlendMode,
                        ::testing::Combine(::testing::ValuesIn(alphas), ::testing::ValuesIn(compositionModes)));

INSTANTIATE_TEST_CASE_P(DISABLED_PorterDuffModes,
                        CGContextBlendMode,
                        ::testing::Combine(::testing::ValuesIn(alphas), ::testing::ValuesIn(porterDuffBlendModes)));

INSTANTIATE_TEST_CASE_P(DISABLED_OperatorBlendModes,
                        CGContextBlendMode,
                        ::testing::Combine(::testing::ValuesIn(alphas), ::testing::ValuesIn(blendOperators)));
