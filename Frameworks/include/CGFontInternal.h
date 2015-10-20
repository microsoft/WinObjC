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

COREGRAPHICS_EXPORT DWORD CGFontMeasureGlyphs(id font, float size, WORD* glyphs, unsigned count, CGSize* sizeOut);
COREGRAPHICS_EXPORT DWORD CGFontFitChars(id font, float size, WORD* chars, unsigned count, float width, CGSize* sizeOut);
COREGRAPHICS_EXPORT DWORD CGFontGetGlyphs(id font, WORD* str, DWORD length, WORD* glyphs);
CGSize CGFontDrawGlyphsToContext(CGContextRef ctx, WORD* glyphs, DWORD length, float x, float y);
float CGFontGetDescentAtSize(id font, float size);
float CGFontGetAscentAtSize(id font, float size);
DWORD CGFontGetFontBBox(CGRect* ret, id font);
COREGRAPHICS_EXPORT void CGFontSetFTFontSize(id uiFont, void* ftFont, float pointSize, float scale = 1.0f);

typedef struct {
    //  The array of characters
    WORD* chars;
    int curIndex;
    int count;
    bool hitLinebreak;

    //  The start of the line to draw, and it's length
    WORD* lineStart;
    int lineLen;
} CGFontWrapState;

COREGRAPHICS_EXPORT bool CGFontWrap(id font, float size, CGFontWrapState* state, float width, CGSize* sizeOut);
COREGRAPHICS_EXPORT bool CGFontWrapFunc(CGFontWrapState* state,
                                        float width,
                                        CGSize* sizeOut,
                                        int (*getCharWidth)(WORD*, void* opaque, unsigned idx),
                                        void* opaque,
                                        bool wrapChars = false);

COREGRAPHICS_EXPORT void _CGFontLock();
COREGRAPHICS_EXPORT void _CGFontUnlock();

#endif
