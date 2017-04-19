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

#import <CoreText/CoreText.h>
#import <CoreGraphics/CoreGraphics.h>
#import <Starboard/SmartTypes.h>
#import <UIKit/UIKit.h>
#import <CGContextInternal.h>
#import <CppUtils.h>

#import "Benchmark.h"

static constexpr CGSize sc_defaultSize{ 512.f, 256.f };
static const NSString* sc_frameText = @"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut "
                                      @"labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris "
                                      @"nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate "
                                      @"velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non "
                                      @"proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
static constexpr UniChar sc_chars[4] = { 'T', 'E', 'S', 'T' };

class CTFramesetterBase : public ::benchmark::BenchmarkCaseBase {
public:
    CTFramesetterBase(CGSize size) {
        CTParagraphStyleSetting setting;
        CTTextAlignment alignment = kCTCenterTextAlignment;
        setting.spec = kCTParagraphStyleSpecifierAlignment;
        setting.valueSize = sizeof(CTTextAlignment);
        setting.value = &alignment;
        auto paragraphStyle = woc::MakeAutoCF<CTParagraphStyleRef>(CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value));
        UIFont* font = [UIFont systemFontOfSize:24];

        CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
        CFTypeRef values[2] = { font, paragraphStyle };
        auto dict = woc::MakeAutoCF<CFDictionaryRef>(CFDictionaryCreate(nullptr,
                                                                        (const void**)keys,
                                                                        (const void**)values,
                                                                        std::extent<decltype(keys)>::value,
                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                        &kCFTypeDictionaryValueCallBacks));

        auto attrString = woc::MakeAutoCF<CFAttributedStringRef>(CFAttributedStringCreate(nullptr, (CFStringRef)sc_frameText, dict));
        m_framesetter = woc::MakeAutoCF<CTFramesetterRef>(CTFramesetterCreateWithAttributedString(attrString));
        m_size = size;
    }

    size_t GetRunCount() const {
        return 1000;
    }

protected:
    woc::AutoCF<CTFramesetterRef> m_framesetter;
    CGSize m_size;
};

class CTFramesetterCreateFrameTest : public CTFramesetterBase {
    woc::StrongCF<CGMutablePathRef> m_path;

public:
    CTFramesetterCreateFrameTest(CGSize size) : CTFramesetterBase(size), m_path(woc::TakeOwnership, CGPathCreateMutable()) {
        CGPathAddRect(m_path, nullptr, CGRect{ CGPointZero, size });
    }

    inline void Run() {
        auto frame = woc::MakeAutoCF<CTFrameRef>(CTFramesetterCreateFrame(m_framesetter, CFRange{ 0, 0 }, m_path, nullptr));
    }
};

class CTFramesetterSuggestFrameSizeTest : public CTFramesetterBase {
public:
    CTFramesetterSuggestFrameSizeTest(CGSize size) : CTFramesetterBase(size) {
    }

    inline void Run() {
        CTFramesetterSuggestFrameSizeWithConstraints(m_framesetter, CFRange{}, nullptr, m_size, nullptr);
    }
};

static constexpr CGSize c_sizes[] = { { 0, 0 }, { 0, 512 }, { 256, 0 }, { 256, 512 } };
BENCHMARK_REGISTER_CASE_P(CoreText, CTFramesetterCreateFrameTest, ::testing::ValuesIn(c_sizes), CGSize);
BENCHMARK_REGISTER_CASE_P(CoreText, CTFramesetterSuggestFrameSizeTest, ::testing::ValuesIn(c_sizes), CGSize);

class CTLineCreateTest : public ::benchmark::BenchmarkCaseBase {
    woc::AutoCF<CFAttributedStringRef> m_attrString;

public:
    CTLineCreateTest() {
        UIFont* font = [UIFont systemFontOfSize:24];

        CFStringRef keys[1] = { kCTFontAttributeName };
        CFTypeRef values[1] = { font };
        auto dict = woc::MakeAutoCF<CFDictionaryRef>(CFDictionaryCreate(nullptr,
                                                                        (const void**)keys,
                                                                        (const void**)values,
                                                                        std::extent<decltype(keys)>::value,
                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                        &kCFTypeDictionaryValueCallBacks));
        m_attrString = woc::MakeAutoCF<CFAttributedStringRef>(CFAttributedStringCreate(nullptr, (CFStringRef)sc_frameText, dict));
    }

    inline void Run() {
        auto line = woc::MakeAutoCF<CTLineRef>(CTLineCreateWithAttributedString(m_attrString));
    }

    size_t GetRunCount() const {
        return 1000;
    }
};

BENCHMARK_F(CoreText, CTLineCreateTest);

class TextBenchmarkBase : public ::benchmark::BenchmarkCaseBase {
public:
    TextBenchmarkBase() {
        auto colorspace = woc::MakeAutoCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceRGB());
        m_context = woc::MakeAutoCF<CGContextRef>(CGBitmapContextCreate(nullptr,
                                                                        sc_defaultSize.width,
                                                                        sc_defaultSize.height,
                                                                        8,
                                                                        sc_defaultSize.width * 4,
                                                                        colorspace,
                                                                        kCGImageAlphaPremultipliedFirst));
    }

protected:
    woc::AutoCF<CGContextRef> m_context;
};

class CTFrameDrawBase : public TextBenchmarkBase {
public:
    CTFrameDrawBase() {
        CTParagraphStyleSetting setting;
        CTTextAlignment alignment = kCTCenterTextAlignment;
        setting.spec = kCTParagraphStyleSpecifierAlignment;
        setting.valueSize = sizeof(CTTextAlignment);
        setting.value = &alignment;
        auto paragraphStyle = woc::MakeAutoCF<CTParagraphStyleRef>(CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value));
        UIFont* font = [UIFont systemFontOfSize:24];

        CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
        CFTypeRef values[2] = { font, paragraphStyle };
        auto dict = woc::MakeAutoCF<CFDictionaryRef>(CFDictionaryCreate(nullptr,
                                                                        (const void**)keys,
                                                                        (const void**)values,
                                                                        std::extent<decltype(keys)>::value,
                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                        &kCFTypeDictionaryValueCallBacks));

        auto attrString = woc::MakeAutoCF<CFAttributedStringRef>(CFAttributedStringCreate(nullptr, (CFStringRef)sc_frameText, dict));
        auto framesetter = woc::MakeAutoCF<CTFramesetterRef>(CTFramesetterCreateWithAttributedString(attrString));
        auto path = woc::MakeAutoCF<CGMutablePathRef>(CGPathCreateMutable());
        CGPathAddRect(path, nullptr, CGRect{ CGPointZero, sc_defaultSize });
        m_frame = woc::MakeAutoCF<CTFrameRef>(CTFramesetterCreateFrame(framesetter, CFRange{ 0, 0 }, path, nullptr));
    }

protected:
    woc::AutoCF<CTFrameRef> m_frame;
};

class CTFrameDrawSingle : public CTFrameDrawBase {
public:
    inline void Run() {
        CTFrameDraw(m_frame, m_context);
    }

    size_t GetRunCount() const {
        return 1000;
    }
};

class CTFrameDrawGroup : public CTFrameDrawBase {
public:
    inline void Run() {
        _CGContextPushBeginDraw(m_context);
        for (size_t i = 0; i < 100; ++i) {
            CTFrameDraw(m_frame, m_context);
        }
        _CGContextPopEndDraw(m_context);
    }

    size_t GetRunCount() const {
        return 50;
    }
};

BENCHMARK_F(CoreText, CTFrameDrawSingle);
BENCHMARK_F(CoreText, CTFrameDrawGroup);

class CTFrameDrawComplete : public TextBenchmarkBase {
public:
    inline void Run() {
        CTParagraphStyleSetting setting;
        CTTextAlignment alignment = kCTCenterTextAlignment;
        setting.spec = kCTParagraphStyleSpecifierAlignment;
        setting.valueSize = sizeof(CTTextAlignment);
        setting.value = &alignment;
        auto paragraphStyle = woc::MakeAutoCF<CTParagraphStyleRef>(CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value));
        UIFont* font = [UIFont systemFontOfSize:24];

        CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
        CFTypeRef values[2] = { font, paragraphStyle };
        auto dict = woc::MakeAutoCF<CFDictionaryRef>(CFDictionaryCreate(nullptr,
                                                                        (const void**)keys,
                                                                        (const void**)values,
                                                                        std::extent<decltype(keys)>::value,
                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                        &kCFTypeDictionaryValueCallBacks));

        auto attrString = woc::MakeAutoCF<CFAttributedStringRef>(CFAttributedStringCreate(nullptr, (CFStringRef)sc_frameText, dict));
        auto framesetter = woc::MakeAutoCF<CTFramesetterRef>(CTFramesetterCreateWithAttributedString(attrString));
        auto path = woc::MakeAutoCF<CGMutablePathRef>(CGPathCreateMutable());
        CGPathAddRect(path, nullptr, CGRect{ CGPointZero, sc_defaultSize });
        auto frame = woc::MakeAutoCF<CTFrameRef>(CTFramesetterCreateFrame(framesetter, CFRange{ 0, 0 }, path, nullptr));
        CTFrameDraw(frame, m_context);
    }

    size_t GetRunCount() const {
        return 1000;
    }
};

BENCHMARK_F(CoreText, CTFrameDrawComplete);

class CTFrameDrawHuge : public TextBenchmarkBase {
public:
    CTFrameDrawHuge() {
        CTParagraphStyleSetting setting;
        CTTextAlignment alignment = kCTCenterTextAlignment;
        setting.spec = kCTParagraphStyleSpecifierAlignment;
        setting.valueSize = sizeof(CTTextAlignment);
        setting.value = &alignment;
        auto paragraphStyle = woc::MakeAutoCF<CTParagraphStyleRef>(CTParagraphStyleCreate(&setting, std::extent<decltype(setting)>::value));
        UIFont* font = [UIFont systemFontOfSize:24];

        CFStringRef keys[2] = { kCTFontAttributeName, kCTParagraphStyleAttributeName };
        CFTypeRef values[2] = { font, paragraphStyle };
        auto dict = woc::MakeAutoCF<CFDictionaryRef>(CFDictionaryCreate(nullptr,
                                                                        (const void**)keys,
                                                                        (const void**)values,
                                                                        std::extent<decltype(keys)>::value,
                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                        &kCFTypeDictionaryValueCallBacks));

        StrongId<NSMutableString*> str = [NSMutableString stringWithCapacity:100 * sc_frameText.length];
        for (size_t i = 0; i < 100; ++i) {
            [str appendString:(NSString*)sc_frameText];
        }

        auto attrString = woc::MakeAutoCF<CFAttributedStringRef>(CFAttributedStringCreate(nullptr, (CFStringRef)str.get(), dict));
        auto framesetter = woc::MakeAutoCF<CTFramesetterRef>(CTFramesetterCreateWithAttributedString(attrString));
        auto path = woc::MakeAutoCF<CGMutablePathRef>(CGPathCreateMutable());
        CGPathAddRect(path, nullptr, CGRect{ CGPointZero, sc_defaultSize * 10.0 });
        m_frame = woc::MakeAutoCF<CTFrameRef>(CTFramesetterCreateFrame(framesetter, CFRange{ 0, 0 }, path, nullptr));
    }

    inline void Run() {
        CTFrameDraw(m_frame, m_context);
    }

    size_t GetRunCount() const {
        return 100;
    }

private:
    woc::AutoCF<CTFrameRef> m_frame;
};

BENCHMARK_F(CoreText, CTFrameDrawHuge);

class CTLineDrawBase : public TextBenchmarkBase {
public:
    CTLineDrawBase() {
        UIFont* font = [UIFont systemFontOfSize:24];

        CFStringRef keys[1] = { kCTFontAttributeName };
        CFTypeRef values[1] = { font };
        auto dict = woc::MakeAutoCF<CFDictionaryRef>(CFDictionaryCreate(nullptr,
                                                                        (const void**)keys,
                                                                        (const void**)values,
                                                                        std::extent<decltype(keys)>::value,
                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                        &kCFTypeDictionaryValueCallBacks));
        auto attrString = woc::MakeAutoCF<CFAttributedStringRef>(CFAttributedStringCreate(nullptr, (CFStringRef)sc_frameText, dict));
        m_line = woc::MakeAutoCF<CTLineRef>(CTLineCreateWithAttributedString(attrString));
    }

protected:
    woc::AutoCF<CTLineRef> m_line;
};

class CTLineDrawSingle : public CTLineDrawBase {
public:
    inline void Run() {
        CTLineDraw(m_line, m_context);
    }

    size_t GetRunCount() const {
        return 10000;
    }
};

class CTLineDrawGroup : public CTLineDrawBase {
public:
    inline void Run() {
        _CGContextPushBeginDraw(m_context);
        for (size_t i = 0; i < 10000; ++i) {
            CTLineDraw(m_line, m_context);
        }
        _CGContextPopEndDraw(m_context);
    }

    size_t GetRunCount() const {
        return 50;
    }
};

BENCHMARK_F(CoreText, CTLineDrawSingle);
BENCHMARK_F(CoreText, CTLineDrawGroup);

class CTLineDrawComplete : public TextBenchmarkBase {
public:
    inline void Run() {
        UIFont* font = [UIFont systemFontOfSize:24];

        CFStringRef keys[1] = { kCTFontAttributeName };
        CFTypeRef values[1] = { font };
        auto dict = woc::MakeAutoCF<CFDictionaryRef>(CFDictionaryCreate(nullptr,
                                                                        (const void**)keys,
                                                                        (const void**)values,
                                                                        std::extent<decltype(keys)>::value,
                                                                        &kCFTypeDictionaryKeyCallBacks,
                                                                        &kCFTypeDictionaryValueCallBacks));
        auto attrString = woc::MakeAutoCF<CFAttributedStringRef>(CFAttributedStringCreate(nullptr, (CFStringRef)sc_frameText, dict));
        auto line = woc::MakeAutoCF<CTLineRef>(CTLineCreateWithAttributedString(attrString));
        CTLineDraw(line, m_context);
    }

    size_t GetRunCount() const {
        return 1000;
    }
};

BENCHMARK_F(CoreText, CTLineDrawComplete);

class CTRunDrawBase : public CTLineDrawBase {
public:
    CTRunDrawBase() : m_run((CTRunRef)CFArrayGetValueAtIndex(CTLineGetGlyphRuns(m_line), 0)) {
    }

protected:
    // Weak reference to a run since it's owned by the CTLine in the base class
    CTRunRef m_run;
};

class CTRunDrawSingle : public CTRunDrawBase {
public:
    inline void Run() {
        CTRunDraw(m_run, m_context, CFRange{});
    }

    size_t GetRunCount() const {
        return 10000;
    }
};

class CTRunDrawGroup : public CTRunDrawBase {
public:
    inline void Run() {
        _CGContextPushBeginDraw(m_context);
        for (size_t i = 0; i < 10000; ++i) {
            CTRunDraw(m_run, m_context, CFRange{});
        }
        _CGContextPopEndDraw(m_context);
    }

    size_t GetRunCount() const {
        return 50;
    }
};

class CTRunDrawRotated : public CTRunDrawSingle {
public:
    CTRunDrawRotated() {
        CGAffineTransform textMatrix = CGContextGetTextMatrix(m_context);
        CGContextSetTextMatrix(m_context, CGAffineTransformRotate(textMatrix, 45.0 * M_PI / 180.0));
    }
};

BENCHMARK_F(CoreText, CTRunDrawSingle);
BENCHMARK_F(CoreText, CTRunDrawGroup);
BENCHMARK_F(CoreText, CTRunDrawRotated);

class ShowGlyphsBase : public TextBenchmarkBase {
public:
    ShowGlyphsBase()
        : m_glyphs(std::extent<decltype(sc_chars)>::value), m_font(woc::TakeOwnership, CGFontCreateWithFontName(CFSTR("Arial"))) {
        CGContextSetFont(m_context, m_font);
        CGContextSetFontSize(m_context, 20);

        auto ctFont = woc::MakeAutoCF<CTFontRef>(CTFontCreateWithName(CFSTR("Arial"), 20, nullptr));
        EXPECT_TRUE(CTFontGetGlyphsForCharacters(ctFont, sc_chars, m_glyphs.data(), std::extent<decltype(sc_chars)>::value));
    }

    size_t GetRunCount() const {
        return 100000;
    }

protected:
    std::vector<CGGlyph> m_glyphs;
    woc::AutoCF<CGFontRef> m_font;
};

class ShowGlyphsTest : public ShowGlyphsBase {
public:
    inline void Run() {
        CGContextShowGlyphs(m_context, m_glyphs.data(), m_glyphs.size());
    }
};

class ShowGlyphsWithAdvances : public ShowGlyphsBase {
    std::vector<CGSize> m_advances;

public:
    ShowGlyphsWithAdvances() : m_advances(m_glyphs.size(), CGSize{ 5.0, 10.0 }) {
    }

    inline void Run() {
        CGContextShowGlyphsWithAdvances(m_context, m_glyphs.data(), m_advances.data(), m_glyphs.size());
    }
};

BENCHMARK_F(CGContext, ShowGlyphsTest);
BENCHMARK_F(CGContext, ShowGlyphsWithAdvances);

class NSString_UIKitBase : public TextBenchmarkBase {
public:
    NSString_UIKitBase() : m_font([UIFont systemFontOfSize:20]) {
        UIGraphicsPushContext(m_context);
    }

    ~NSString_UIKitBase() {
        UIGraphicsPopContext();
    }

protected:
    StrongId<UIFont> m_font;
};

class DrawAtPoint : public NSString_UIKitBase {
public:
    inline void Run() {
        [sc_frameText drawAtPoint:{ 0, 0 } withFont:m_font];
    }

    size_t GetRunCount() const {
        return 1000;
    }
};

class DrawAtPointGroup : public NSString_UIKitBase {
public:
    inline void Run() {
        _CGContextPushBeginDraw(m_context);
        for (size_t i = 0; i < 100; ++i) {
            [sc_frameText drawAtPoint:{ 0, 0 } withFont:m_font];
        }
        _CGContextPopEndDraw(m_context);
    }

    size_t GetRunCount() const {
        return 50;
    }
};

BENCHMARK_F(NSString, DrawAtPoint);
BENCHMARK_F(NSString, DrawAtPointGroup);

class DrawInRect : public NSString_UIKitBase {
    CGSize m_rectSize;

public:
    DrawInRect(CGSize size) : m_rectSize(size) {
    }

    inline void Run() {
        [sc_frameText drawInRect:{ { 0, 0 }, m_rectSize } withFont:m_font];
    }

    size_t GetRunCount() const {
        return 1000;
    }
};

class DrawInRectGroup : public NSString_UIKitBase {
    CGSize m_rectSize;

public:
    DrawInRectGroup(CGSize size) : m_rectSize(size) {
    }

    inline void Run() {
        _CGContextPushBeginDraw(m_context);
        for (size_t i = 0; i < 100; ++i) {
            [sc_frameText drawInRect:{ { 0, 0 }, m_rectSize } withFont:m_font];
        }
        _CGContextPopEndDraw(m_context);
    }

    size_t GetRunCount() const {
        return 50;
    }
};

BENCHMARK_REGISTER_CASE_P(NSString, DrawInRect, ::testing::ValuesIn(c_sizes), CGSize);
BENCHMARK_REGISTER_CASE_P(NSString, DrawInRectGroup, ::testing::ValuesIn(c_sizes), CGSize);

class SizeWithFont : public NSString_UIKitBase {
public:
    SizeWithFont(CGSize size) : m_rectSize(size) {
    }

    inline void Run() {
        [sc_frameText sizeWithFont:m_font constrainedToSize:m_rectSize];
    }

    size_t GetRunCount() const {
        return 1000;
    }

protected:
    CGSize m_rectSize;
};

BENCHMARK_REGISTER_CASE_P(NSString, SizeWithFont, ::testing::ValuesIn(c_sizes), CGSize);

BENCHMARK(CoreText, CTFontCreateWithName, 10000) {
    CTFontRef font = CTFontCreateWithName(CFSTR("Arial"), 24, nullptr);
    CFRelease(font);
}

BENCHMARK(CoreText, CTFontDescriptor, 10000) {
    CTFontDescriptorRef descriptor = CTFontDescriptorCreateWithNameAndSize(CFSTR("Arial"), 88.5);
    CTFontRef font = CTFontCreateWithFontDescriptor(descriptor, 25.25, nullptr);
    CFRelease(descriptor);
    CFRelease(font);
}

class CTFontGetGlyphsTest : public ::benchmark::BenchmarkCaseBase {
    woc::AutoCF<CTFontRef> m_font;
    std::vector<CGGlyph> m_glyphs;

public:
    CTFontGetGlyphsTest()
        : m_font(woc::TakeOwnership, CTFontCreateWithName(CFSTR("Arial"), 25, nullptr)), m_glyphs(std::extent<decltype(sc_chars)>::value) {
    }
    inline void Run() {
        CTFontGetGlyphsForCharacters(m_font, sc_chars, m_glyphs.data(), m_glyphs.size());
    }

    size_t GetRunCount() const {
        return 1000;
    }
};

BENCHMARK_F(CoreText, CTFontGetGlyphsTest);
