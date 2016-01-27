//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef __CGFONT_H
#define __CGFONT_H

#define FT_EXPORT(x) extern "C" x

COREGRAPHICS_EXPORT unsigned long CGFontMeasureGlyphs(id font, float size, unsigned short* glyphs, unsigned count, CGSize* sizeOut);
COREGRAPHICS_EXPORT unsigned long CGFontFitChars(id font, float size, unsigned short* chars, unsigned count, float width, CGSize* sizeOut);
COREGRAPHICS_EXPORT unsigned long CGFontGetGlyphs(id font, unsigned short* str, unsigned long length, unsigned short* glyphs);
COREGRAPHICS_EXPORT unsigned long CGFontGetGlyphsForUnichars(id font, unsigned short* chars, unsigned short* glyphs, int num);
CGSize CGFontDrawGlyphsToContext(CGContextRef ctx, unsigned short* glyphs, unsigned long length, float x, float y);
float CGFontGetDescentAtSize(id font, float size);
float CGFontGetAscentAtSize(id font, float size);
unsigned long CGFontGetFontBBox(CGRect* ret, id font);
COREGRAPHICS_EXPORT void CGFontSetFTFontSize(id uiFont, void* ftFont, float pointSize, float scale = 1.0f);

typedef struct {
    //  The array of characters
    unsigned short* chars;
    int curIndex;
    int count;
    bool hitLinebreak;

    //  The start of the line to draw, and it's length
    unsigned short* lineStart;
    int lineLen;
} CGFontWrapState;

COREGRAPHICS_EXPORT bool CGFontWrap(id font, float size, CGFontWrapState* state, float width, CGSize* sizeOut);
COREGRAPHICS_EXPORT bool CGFontWrapFunc(CGFontWrapState* state,
                                        float width,
                                        CGSize* sizeOut,
                                        int (*getCharWidth)(unsigned short*, void* opaque, unsigned idx),
                                        void* opaque,
                                        bool wrapChars = false);

COREGRAPHICS_EXPORT void _CGFontLock();
COREGRAPHICS_EXPORT void _CGFontUnlock();

#endif
