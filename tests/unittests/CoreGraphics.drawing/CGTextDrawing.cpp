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

DRAW_TEST_F(CGContext, ShowGlyphs, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);
    woc::unique_cf<CTFontRef> ctfont{ CTFontCreateWithName(CFSTR("Arial"), 144, nullptr) };
    woc::unique_cf<CFStringRef> text{ CFSTR("TEST") };
    UniChar chars[4];
    CFStringGetCharacters(text.get(), { 0, 4 }, chars);
    CGGlyph glyphs[4];
    CTFontGetGlyphsForCharacters(ctfont.get(), chars, glyphs, 4);
    woc::unique_cf<CGFontRef> font{ CGFontCreateWithFontName(CFSTR("Arial")) };
    CGContextSetFont(context, font.get());
    CGContextSetFontSize(context, 144);
    CGContextSetTextPosition(context, 25, 50);
    CGContextShowGlyphs(context, glyphs, 4);
}

DRAW_TEST_F(CGContext, ShowGlyphsAtPoint, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);
    woc::unique_cf<CTFontRef> ctfont{ CTFontCreateWithName(CFSTR("Arial"), 144, nullptr) };
    woc::unique_cf<CFStringRef> text{ CFSTR("TEST") };
    UniChar chars[4];
    CFStringGetCharacters(text.get(), { 0, 4 }, chars);
    CGGlyph glyphs[4];
    CTFontGetGlyphsForCharacters(ctfont.get(), chars, glyphs, 4);
    woc::unique_cf<CGFontRef> font{ CGFontCreateWithFontName(CFSTR("Arial")) };
    CGContextSetFont(context, font.get());
    CGContextSetFontSize(context, 144);
    CGContextShowGlyphsAtPoint(context, 25, 50, glyphs, 4);
}

// On reference platform, CGContextShowText* can only be used with CGContextSelectFont
// Which we do not currently support.
#ifdef WINOBJC
DRAW_TEST_F(CGContext, ShowTextAtPoint, WhiteBackgroundTest) {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    // Creates path with current rectangle
    woc::unique_cf<CGMutablePathRef> path{ CGPathCreateMutable() };
    CGPathAddRect(path.get(), nullptr, bounds);
    woc::unique_cf<CGFontRef> font{ CGFontCreateWithFontName(CFSTR("Arial")) };
    CGContextSetFont(context, font.get());
    CGContextSetFontSize(context, 144);
    CGContextShowTextAtPoint(context, 25, 50, "TEST", 4);
}
#endif // WINOBJC