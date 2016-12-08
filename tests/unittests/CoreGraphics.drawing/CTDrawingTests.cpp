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
#include <CoreText/CoreText.h>
#include <Starboard/SmartTypes.h>

#ifdef WINOBJC
static NSURL* __GetURLFromPathRelativeToModuleDirectory(NSString* relativePath) {
    static char fullPath[_MAX_PATH];
    static int unused = [](char* path) { return GetModuleFileNameA(NULL, path, _MAX_PATH); }(fullPath);
    return [NSURL fileURLWithPath:[[@(fullPath) stringByDeletingLastPathComponent] stringByAppendingPathComponent:relativePath]];
}
#endif // WINOBJC

DISABLED_DRAW_TEST_F(CTFrame, BasicDrawingTest, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting;
    CTTextAlignment alignment = kCTCenterTextAlignment;
    setting.spec = kCTParagraphStyleSpecifierAlignment;
    setting.valueSize = sizeof(CTTextAlignment);
    setting.value = &alignment;
    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value) };

    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    woc::unique_cf<CFDictionaryRef> dict{ CFDictionaryCreate(nullptr,
                                                             (const void**)keys,
                                                             (const void**)values,
                                                             std::extent<decltype(keys)>::value,
                                                             &kCFTypeDictionaryKeyCallBacks,
                                                             &kCFTypeDictionaryValueCallBacks) };

    woc::unique_cf<CFAttributedStringRef> attrString{ CFAttributedStringCreate(nullptr, CFSTR("TEST TEXT.\ntext to test."), dict.get()) };

    woc::unique_cf<CTFramesetterRef> framesetter{ CTFramesetterCreateWithAttributedString(attrString.get()) };

    // Creates frame for framesetter with current attributed string
    woc::unique_cf<CTFrameRef> frame{ CTFramesetterCreateFrame(framesetter.get(), CFRangeMake(0, 0), path.get(), NULL) };

    // Draws the text in the frame
    CTFrameDraw(frame.get(), context);
}

DISABLED_DRAW_TEST_F(CTFrame, BasicUIKitMimicDrawingTest, UIKitMimicTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting;
    CTTextAlignment alignment = kCTCenterTextAlignment;
    setting.spec = kCTParagraphStyleSpecifierAlignment;
    setting.valueSize = sizeof(CTTextAlignment);
    setting.value = &alignment;
    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value) };

    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    woc::unique_cf<CFDictionaryRef> dict{ CFDictionaryCreate(nullptr,
                                                             (const void**)keys,
                                                             (const void**)values,
                                                             std::extent<decltype(keys)>::value,
                                                             &kCFTypeDictionaryKeyCallBacks,
                                                             &kCFTypeDictionaryValueCallBacks) };

    woc::unique_cf<CFAttributedStringRef> attrString{ CFAttributedStringCreate(nullptr, CFSTR("TEST TEXT.\ntext to test."), dict.get()) };

    woc::unique_cf<CTFramesetterRef> framesetter{ CTFramesetterCreateWithAttributedString(attrString.get()) };

    // Creates frame for framesetter with current attributed string
    woc::unique_cf<CTFrameRef> frame{ CTFramesetterCreateFrame(framesetter.get(), CFRangeMake(0, 0), path.get(), NULL) };

    // Draws the text in the frame
    CTFrameDraw(frame.get(), context);
}

DISABLED_DRAW_TEST_F(CTFrame, BasicUnicodeTest, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting;
    CTTextAlignment alignment = kCTCenterTextAlignment;
    setting.spec = kCTParagraphStyleSpecifierAlignment;
    setting.valueSize = sizeof(CTTextAlignment);
    setting.value = &alignment;
    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value) };

    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    woc::unique_cf<CFDictionaryRef> dict{ CFDictionaryCreate(nullptr,
                                                             (const void**)keys,
                                                             (const void**)values,
                                                             std::extent<decltype(keys)>::value,
                                                             &kCFTypeDictionaryKeyCallBacks,
                                                             &kCFTypeDictionaryValueCallBacks) };

    woc::unique_cf<CFAttributedStringRef> attrString{
        CFAttributedStringCreate(nullptr, CFSTR("он прошел այն անցավ ມັນຜ່ານໄປ ਇਸ ਨੂੰ ਪਾਸ ਕੀਤਾ 它通過了 그것이 통과했다 minęło"), dict.get())
    };

    woc::unique_cf<CTFramesetterRef> framesetter{ CTFramesetterCreateWithAttributedString(attrString.get()) };

    // Creates frame for framesetter with current attributed string
    woc::unique_cf<CTFrameRef> frame{ CTFramesetterCreateFrame(framesetter.get(), CFRangeMake(0, 0), path.get(), NULL) };

    // Draws the text in the frame
    CTFrameDraw(frame.get(), context);
}

class CTFrame : public WhiteBackgroundTest,
                public ::testing::WithParamInterface<::testing::tuple<CTTextAlignment, CTLineBreakMode, CTWritingDirection, CGFloat>> {
    CFStringRef CreateOutputFilename() {
        CTTextAlignment alignment = ::testing::get<0>(GetParam());
        CTLineBreakMode lineBreakMode = ::testing::get<1>(GetParam());
        CTWritingDirection writingDirection = ::testing::get<2>(GetParam());
        CGFloat fontSize = ::testing::get<3>(GetParam());
        return CFStringCreateWithFormat(nullptr,
                                        nullptr,
                                        CFSTR("TestImage.CT.Alignment.%d.LineBreakMode.%d.WritingDirection.%d.FontSize.%.02f.png"),
                                        alignment,
                                        lineBreakMode,
                                        writingDirection,
                                        fontSize);
    }
};

template <size_t size>
static void __DrawLoremIpsum(CGContextRef context, CGPathRef path, const CFStringRef (&keys)[size], const CFTypeRef (&values)[size]) {
    woc::unique_cf<CFDictionaryRef> dict{ CFDictionaryCreate(
        nullptr, (const void**)keys, (const void**)values, size, &kCFTypeDictionaryKeyCallBacks, &kCFTypeDictionaryValueCallBacks) };

    woc::unique_cf<CFAttributedStringRef> attrString{
        CFAttributedStringCreate(nullptr,
                                 CFSTR("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut "
                                       "labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
                                       "nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit "
                                       "esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt "
                                       "in culpa qui officia deserunt mollit anim id est laborum."),
                                 dict.get())
    };

    woc::unique_cf<CTFramesetterRef> framesetter{ CTFramesetterCreateWithAttributedString(attrString.get()) };

    // Creates frame for framesetter with current attributed string
    woc::unique_cf<CTFrameRef> frame{ CTFramesetterCreateFrame(framesetter.get(), CFRangeMake(0, 0), path, NULL) };

    // Draws the text in the frame
    CTFrameDraw(frame.get(), context);
}

DISABLED_DRAW_TEST_P(CTFrame, AlignLBMFontSize) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting[3];
    CTTextAlignment alignment = ::testing::get<0>(GetParam());
    setting[0].spec = kCTParagraphStyleSpecifierAlignment;
    setting[0].valueSize = sizeof(CTTextAlignment);
    setting[0].value = &alignment;

    CTLineBreakMode lineBreakMode = ::testing::get<1>(GetParam());
    setting[1].spec = kCTParagraphStyleSpecifierLineBreakMode;
    setting[1].valueSize = sizeof(CTLineBreakMode);
    setting[1].value = &lineBreakMode;

    CTWritingDirection writingDirection = ::testing::get<2>(GetParam());
    setting[2].spec = kCTParagraphStyleSpecifierBaseWritingDirection;
    setting[2].valueSize = sizeof(CTWritingDirection);
    setting[2].value = &writingDirection;

    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(setting, 3) };
    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), ::testing::get<3>(GetParam()), nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };
    __DrawLoremIpsum(context, path.get(), keys, values);
}

static constexpr CTTextAlignment c_alignments[] = { kCTLeftTextAlignment,
                                                    kCTRightTextAlignment,
                                                    kCTCenterTextAlignment,
                                                    kCTJustifiedTextAlignment,
                                                    kCTNaturalTextAlignment };
static constexpr CTLineBreakMode c_lineBreakModes[] = { kCTLineBreakByWordWrapping, kCTLineBreakByCharWrapping, kCTLineBreakByClipping };
static constexpr CTWritingDirection c_writingDirections[] = { kCTWritingDirectionNatural,
                                                              kCTWritingDirectionLeftToRight,
                                                              kCTWritingDirectionRightToLeft };
static constexpr CGFloat c_fontSizes[]{ 8.0, 25.5, 91.25 };

INSTANTIATE_TEST_CASE_P(TestAlignmentLineBreakMode,
                        CTFrame,
                        ::testing::Combine(::testing::ValuesIn(c_alignments),
                                           ::testing::ValuesIn(c_lineBreakModes),
                                           ::testing::ValuesIn(c_writingDirections),
                                           ::testing::ValuesIn(c_fontSizes)));

class TransformTextMatrix : public WhiteBackgroundTest, public ::testing::WithParamInterface<CGAffineTransform> {
    CFStringRef CreateOutputFilename() {
        CGAffineTransform textTransform = GetParam();
        return CFStringCreateWithFormat(nullptr,
                                        nullptr,
                                        CFSTR("TestImage.TransformCTM.%.02f.%.02f.%.02f.%.02f.%.02f.%.02f.png"),
                                        textTransform.a,
                                        textTransform.b,
                                        textTransform.c,
                                        textTransform.d,
                                        textTransform.tx,
                                        textTransform.ty);
    }
};

DISABLED_DRAW_TEST_P(TransformTextMatrix, TextTextMatrix) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSetTextMatrix(context, GetParam());

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting[1];
    CTTextAlignment alignment = kCTCenterTextAlignment;
    setting[0].spec = kCTParagraphStyleSpecifierAlignment;
    setting[0].valueSize = sizeof(CTTextAlignment);
    setting[0].value = &alignment;

    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(setting, std::extent<decltype(setting)>::value) };
    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    __DrawLoremIpsum(context, path.get(), keys, values);
}

static const CGAffineTransform c_textTransforms[] = { CGAffineTransformMakeRotation(30.0 * M_PI / 180.0),
                                                      CGAffineTransformMakeRotation(60.0 * M_PI / 180.0),
                                                      CGAffineTransformMakeRotation(-45.0 * M_PI / 180.0),
                                                      CGAffineTransformMakeScale(2.0, 1.0),
                                                      CGAffineTransformMakeScale(1.0, 2.0),
                                                      CGAffineTransformMakeScale(2.0, 1.0),
                                                      { 2, 2, 0, 2, 0, 0 },
                                                      { 2, 0, 2, 2, 0, 0 },
                                                      { 2, 2, 1.75, 2, 0, 0 } };
INSTANTIATE_TEST_CASE_P(TestDrawingTextWithTransformedTextMatrix, TransformTextMatrix, ::testing::ValuesIn(c_textTransforms));

class RotateCTM : public WhiteBackgroundTest, public ::testing::WithParamInterface<CGFloat> {
    CFStringRef CreateOutputFilename() {
        CGFloat rotation = GetParam();
        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.RotateCTM.%.02f.png"), rotation);
    }
};

DISABLED_DRAW_TEST_P(RotateCTM, TestRotatingCTM) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextRotateCTM(context, GetParam());

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting[1];
    CTTextAlignment alignment = kCTLeftTextAlignment;
    setting[0].spec = kCTParagraphStyleSpecifierAlignment;
    setting[0].valueSize = sizeof(CTTextAlignment);
    setting[0].value = &alignment;

    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(setting, std::extent<decltype(setting)>::value) };
    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    __DrawLoremIpsum(context, path.get(), keys, values);
}

static constexpr CGFloat c_rotations[] = { 30.0 * M_PI / 180.0, 60.0 * M_PI / 180.0, -45.0 * M_PI / 180.0 };
INSTANTIATE_TEST_CASE_P(TestDrawingTextInRotatedCTM, RotateCTM, ::testing::ValuesIn(c_rotations));

class ExtraKerning : public WhiteBackgroundTest, public ::testing::WithParamInterface<CGFloat> {
    CFStringRef CreateOutputFilename() {
        CGFloat extraKerning = GetParam();
        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.ExtraKerning.%.02f.png"), extraKerning);
    }
};

DISABLED_DRAW_TEST_P(ExtraKerning, TestExtraKerning) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting[1];
    CTTextAlignment alignment = kCTLeftTextAlignment;
    setting[0].spec = kCTParagraphStyleSpecifierAlignment;
    setting[0].valueSize = sizeof(CTTextAlignment);
    setting[0].value = &alignment;

    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(setting, std::extent<decltype(setting)>::value) };
    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CGFloat extraKerning = GetParam();
    woc::unique_cf<CFNumberRef> kerning{ CFNumberCreate(nullptr, kCFNumberCGFloatType, &extraKerning) };

    CFStringRef keys[3] = { kCTFontAttributeName, kCTParagraphStyleAttributeName, kCTKernAttributeName };
    CFTypeRef values[3] = { myCFFont.get(), paragraphStyle.get(), kerning.get() };

    __DrawLoremIpsum(context, path.get(), keys, values);
}

static constexpr CGFloat c_extraKernings[] = { -1.0, 1.0, 5.25, 25.75 };
INSTANTIATE_TEST_CASE_P(TestDrawingTextInExtraKerning, ExtraKerning, ::testing::ValuesIn(c_extraKernings));

class LineHeightMultiple : public WhiteBackgroundTest, public ::testing::WithParamInterface<CGFloat> {
    CFStringRef CreateOutputFilename() {
        CGFloat lineHeightMultiple = GetParam();
        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.LineHeightMultiple.%.02f.png"), lineHeightMultiple);
    }
};

DISABLED_DRAW_TEST_P(LineHeightMultiple, TestLineHeightMultiple) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting[2];
    CTTextAlignment alignment = kCTLeftTextAlignment;
    setting[0].spec = kCTParagraphStyleSpecifierAlignment;
    setting[0].valueSize = sizeof(CTTextAlignment);
    setting[0].value = &alignment;
    CGFloat lineHeightMultiple = GetParam();
    setting[0].spec = kCTParagraphStyleSpecifierLineHeightMultiple;
    setting[0].valueSize = sizeof(CGFloat);
    setting[0].value = &lineHeightMultiple;

    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(setting, std::extent<decltype(setting)>::value) };
    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    __DrawLoremIpsum(context, path.get(), keys, values);
}

static constexpr CGFloat c_lineHeightMultiples[] = { -1.0, .75, 1.25 };
INSTANTIATE_TEST_CASE_P(TestDrawingTextInLineHeightMultiple, LineHeightMultiple, ::testing::ValuesIn(c_lineHeightMultiples));

DISABLED_DRAW_TEST_F(CTRun, BasicDrawingTest, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[1] = { kCTFontAttributeName };
    CFTypeRef values[1] = { myCFFont.get() };

    woc::unique_cf<CFDictionaryRef> dict{ CFDictionaryCreate(nullptr,
                                                             (const void**)keys,
                                                             (const void**)values,
                                                             std::extent<decltype(keys)>::value,
                                                             &kCFTypeDictionaryKeyCallBacks,
                                                             &kCFTypeDictionaryValueCallBacks) };

    woc::unique_cf<CFAttributedStringRef> attrString{ CFAttributedStringCreate(nullptr, CFSTR("TEST TEXT. text to test."), dict.get()) };

    woc::unique_cf<CTLineRef> line{ CTLineCreateWithAttributedString(attrString.get()) };

    // Draws the text in the frame
    CTLineDraw(line.get(), context);
}

DISABLED_DRAW_TEST_F(CTLine, BasicDrawingTest, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("Arial"), 20, nullptr) };

    CFStringRef keys[1] = { kCTFontAttributeName };
    CFTypeRef values[1] = { myCFFont.get() };

    woc::unique_cf<CFDictionaryRef> dict{ CFDictionaryCreate(nullptr,
                                                             (const void**)keys,
                                                             (const void**)values,
                                                             std::extent<decltype(keys)>::value,
                                                             &kCFTypeDictionaryKeyCallBacks,
                                                             &kCFTypeDictionaryValueCallBacks) };

    woc::unique_cf<CFAttributedStringRef> attrString{ CFAttributedStringCreate(nullptr, CFSTR("TEST TEXT. text to test."), dict.get()) };

    woc::unique_cf<CTLineRef> line{ CTLineCreateWithAttributedString(attrString.get()) };
    CFArrayRef runs = CTLineGetGlyphRuns(line.get());
    CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 0));

    // Draws the text in the frame
    CTRunDraw(run, context, {});
}

class Fonts : public WhiteBackgroundTest, public ::testing::WithParamInterface<CFStringRef> {
    CFStringRef CreateOutputFilename() {
        CFStringRef fontName = GetParam();
        return CFStringCreateWithFormat(nullptr, nullptr, CFSTR("TestImage.Fonts.%@.png"), fontName);
    }
};

DISABLED_DRAW_TEST_P(Fonts, TestFonts) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting[1];
    CTTextAlignment alignment = kCTLeftTextAlignment;
    setting[0].spec = kCTParagraphStyleSpecifierAlignment;
    setting[0].valueSize = sizeof(CTTextAlignment);
    setting[0].value = &alignment;

    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(setting, std::extent<decltype(setting)>::value) };

    CFStringRef fontName = GetParam();
    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(fontName, 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    __DrawLoremIpsum(context, path.get(), keys, values);
}

static CFStringRef c_fontNames[] = { CFSTR("Arial"), CFSTR("Times New Roman"), CFSTR("Wingdings"), CFSTR("Segoe UI") };
INSTANTIATE_TEST_CASE_P(TestDrawingTextInFonts, Fonts, ::testing::ValuesIn(c_fontNames));

#ifdef WINOBJC
DISABLED_DRAW_TEST_F(CTFontManager, DrawWithCustomFont, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting;
    CTTextAlignment alignment = kCTCenterTextAlignment;
    setting.spec = kCTParagraphStyleSpecifierAlignment;
    setting.valueSize = sizeof(CTTextAlignment);
    setting.value = &alignment;
    woc::unique_cf<CTParagraphStyleRef> paragraphStyle{ CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value) };

    NSURL* testFileURL = __GetURLFromPathRelativeToModuleDirectory(@"/data/WinObjC.ttf");
    CTFontManagerRegisterFontsForURL((__bridge CFURLRef)testFileURL, kCTFontManagerScopeSession, nullptr);
    woc::unique_cf<CTFontRef> myCFFont{ CTFontCreateWithName(CFSTR("WinObjC"), 20, nullptr) };

    CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
    CFTypeRef values[2] = { myCFFont.get(), paragraphStyle.get() };

    woc::unique_cf<CFDictionaryRef> dict{ CFDictionaryCreate(nullptr,
                                                             (const void**)keys,
                                                             (const void**)values,
                                                             std::extent<decltype(keys)>::value,
                                                             &kCFTypeDictionaryKeyCallBacks,
                                                             &kCFTypeDictionaryValueCallBacks) };

    woc::unique_cf<CFAttributedStringRef> attrString{
        CFAttributedStringCreate(nullptr,
                                 CFSTR("GUR DHVPX OEBJA SBK WHZCF BIRE GUR YNML QBT. gur dhvpx oebja qbt whzcf bire gur ynml sbk."),
                                 dict.get())
    };

    woc::unique_cf<CTFramesetterRef> framesetter{ CTFramesetterCreateWithAttributedString(attrString.get()) };

    // Creates frame for framesetter with current attributed string
    woc::unique_cf<CTFrameRef> frame{ CTFramesetterCreateFrame(framesetter.get(), CFRangeMake(0, 0), path.get(), NULL) };

    // Draws the text in the frame
    CTFrameDraw(frame.get(), context);
    CTFontManagerUnregisterFontsForURL((__bridge CFURLRef)testFileURL, kCTFontManagerScopeSession, nullptr);
}
#endif // WINOBJC

DISABLED_DRAW_TEST_F(CTFont, DrawGlyphs, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);
    woc::unique_cf<CTFontRef> font{ CTFontCreateWithName(CFSTR("Segoe UI"), 20, nullptr) };
    UniChar chars[4] = { 'T', 'E', 'S', 'T' };
    CGGlyph glyphs[4];
    CTFontGetGlyphsForCharacters(font.get(), chars, glyphs, 4);
    CGPoint positions[4] = { { 0, 0 }, { 10, 10 }, { 25, 25 }, { 65, 15 } };
    CTFontDrawGlyphs(font.get(), glyphs, positions, 4, context);
}