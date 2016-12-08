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

static std::vector<CGGlyph> __CreateGlyphs() {
    UniChar chars[4] = { 'T', 'E', 'S', 'T' };
    std::vector<CGGlyph> glyphs(4);
    woc::unique_cf<CTFontRef> ctfont{ CTFontCreateWithName(CFSTR("Arial"), 144, nullptr) };
    CTFontGetGlyphsForCharacters(ctfont.get(), chars, glyphs.data(), 4);
    return glyphs;
}

static void __SetFontForContext(CGContextRef context) {
    woc::unique_cf<CGFontRef> font{ CGFontCreateWithFontName(CFSTR("Arial")) };
    CGContextSetFont(context, font.get());
    CGContextSetFontSize(context, 144);
}

DISABLED_DRAW_TEST_F(CGContext, ShowGlyphs, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    std::vector<CGGlyph> glyphs{ __CreateGlyphs() };
    __SetFontForContext(context);
    CGContextSetTextPosition(context, 25, 50);
    CGContextShowGlyphs(context, glyphs.data(), glyphs.size());
}

DISABLED_DRAW_TEST_F(CGContext, ShowGlyphsAtPoint, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    std::vector<CGGlyph> glyphs{ __CreateGlyphs() };
    __SetFontForContext(context);
    CGContextShowGlyphsAtPoint(context, 25, 50, glyphs.data(), glyphs.size());
}

DISABLED_DRAW_TEST_F(CGContext, DrawWithRotatedTextMatrix, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    std::vector<CGGlyph> glyphs{ __CreateGlyphs() };
    __SetFontForContext(context);
    CGAffineTransform textMatrix = CGContextGetTextMatrix(context);
    CGContextSetTextMatrix(context, CGAffineTransformRotate(textMatrix, 45.0 * M_PI / 180.0));
    CGContextShowGlyphsAtPoint(context, 25, 50, glyphs.data(), glyphs.size());
}

// On reference platform, CGContextShowText* can only be used with CGContextSelectFont
// Which we do not currently support.
#ifdef WINOBJC
DISABLED_DRAW_TEST_F(CGContext, ShowTextAtPoint, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    __SetFontForContext(context);
    CGContextShowTextAtPoint(context, 25, 50, "TEST", 4);
}
#endif // WINOBJC