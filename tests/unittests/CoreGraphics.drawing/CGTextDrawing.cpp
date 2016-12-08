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

void __CreateGlyphs(CGGlyph glyphs[4]) {
    UniChar chars[4] = { 'T', 'E', 'S', 'T' };
    woc::unique_cf<CTFontRef> ctfont{ CTFontCreateWithName(CFSTR("Arial"), 144, nullptr) };
    CTFontGetGlyphsForCharacters(ctfont.get(), chars, glyphs, 4);
}

void __SetFontForContext(CGContextRef context) {
    woc::unique_cf<CGFontRef> font{ CGFontCreateWithFontName(CFSTR("Arial")) };
    CGContextSetFont(context, font.get());
    CGContextSetFontSize(context, 144);
}

DISABLED_DRAW_TEST_F(CGContext, ShowGlyphs, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGGlyph glyphs[4];
    __CreateGlyphs(glyphs);
    __SetFontForContext(context);
    CGContextSetTextPosition(context, 25, 50);
    CGContextShowGlyphs(context, glyphs, 4);
}

DISABLED_DRAW_TEST_F(CGContext, ShowGlyphsAtPoint, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGGlyph glyphs[4];
    __CreateGlyphs(glyphs);
    __SetFontForContext(context);
    CGContextShowGlyphsAtPoint(context, 25, 50, glyphs, 4);
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