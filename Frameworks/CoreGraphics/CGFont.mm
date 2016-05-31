//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <StubReturn.h>
#import <Starboard.h>
#import <algorithm>
#import <vector>
#import <map>
#import "CGContextInternal.h"
#import "CGFontInternal.h"
#import "UIFontInternal.h"
#import "Etc.h"

extern "C" {
#import <ft2build.h>
#import FT_FREETYPE_H
#import <ftglyph.h>
#import <tttables.h>
#import <ftadvanc.h>
#import <ftsizes.h>
#import <ftsnames.h>
#import <ttnameid.h>
}

const CFStringRef kCGFontVariationAxisName = static_cast<CFStringRef>(@"kCGFontVariationAxisName");
const CFStringRef kCGFontVariationAxisMinValue = static_cast<CFStringRef>(@"kCGFontVariationAxisMinValue");
const CFStringRef kCGFontVariationAxisMaxValue = static_cast<CFStringRef>(@"kCGFontVariationAxisMaxValue");
const CFStringRef kCGFontVariationAxisDefaultValue = static_cast<CFStringRef>(@"kCGFontVariationAxisDefaultValue");

DWORD CGFontGetFontBBox(CGRect* ret, id font);

static IWLazyClassLookup _LazyUIFont("UIFont");
static IWLazyIvarLookup<float> _LazyUIFontHorizontalScale(_LazyUIFont, "_horizontalScale");

#include "LoggingNative.h"

static const wchar_t* TAG = L"CGFont";

static float spacing = 1.0f;

static DWORD textureBuffer[1024];
static DWORD destBuffer[1024];

#define USE_CAIRO

void CGFontSetFTFontSize(id uiFont, void* ftFont, float pointSize, float scale) {
    UIFont* fontInfo = uiFont;

    FT_Set_Char_Size((FT_Face)ftFont,
                     0,
                     (FT_F26Dot6)(pointSize * 64.0f),
                     (FT_UInt)(72.f * scale * _LazyUIFontHorizontalScale.member(fontInfo)),
                     (FT_UInt)(72.f * scale));
}

CGSize CGFontDrawGlyphsToContext(CGContextRef ctx, WORD* glyphs, DWORD length, float x, float y) {
    return ctx->Backing()->CGFontDrawGlyphsToContext(glyphs, length, x, y);
}

DWORD CGFontFitChars(id font, float size, WORD* chars, unsigned count, float width, CGSize* sizeOut) {
    DWORD i;

    _CGFontLock();

    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    if (!face) {
        _CGFontUnlock();
        return 0;
    }

    FT_Error error;
    FT_GlyphSlot slot = face->glyph;

    CGFontSetFTFontSize(font, face, size);

    FT_Pos penX = 0;
    FT_Pos penY = 0;

    DWORD lastNonWhiteSpace = 0, lastNonWhiteSpaceWidth = 0;
    DWORD lastGoodIndex = 0, lastGoodWidth = 0;

    //  Lookup each glyph
    for (i = 0; i < count; i++) {
        if (chars[i] == 10 || (i > 0 && chars[i - 1] == 13)) {
            float curWidth = ((float)(penX)) / 64.0f;
            if (curWidth > width && width != 0.0f) {
                break;
            }

            lastGoodIndex = lastNonWhiteSpace + 1;
            lastGoodWidth = lastNonWhiteSpaceWidth;
            break;
        }

        FT_Vector advance;

        if (chars[i] != 13) {
            FT_UInt index = FT_Get_Char_Index(face, chars[i]);

            error = FT_Load_Glyph(face, index, FT_LOAD_NO_HINTING);
            assert(error == 0);
            advance = slot->advance;
        } else {
            advance.x = 0;
            advance.y = 0;
        }

        if ((chars[i] != ' ' && chars[i] != 13) || count == 1) {
            /* increment pen position */
            penX += advance.x;
            penY += advance.y;

            lastNonWhiteSpace = i + 1;
            lastNonWhiteSpaceWidth = penX;
        }

        if ((chars[i] == ' ' || chars[i] == 13) || i == count - 1) {
            float curWidth;

            curWidth = ((float)(penX)) / 64.0f;
            if (curWidth > width && width != 0.0f) {
                break;
            }

            if (i == count - 1) {
                lastNonWhiteSpace = i + 1;
                lastNonWhiteSpaceWidth = penX;
            }

            /* increment pen position */
            penX += advance.x;
            penY += advance.y;

            lastGoodIndex = lastNonWhiteSpace;
            lastGoodWidth = lastNonWhiteSpaceWidth;
        }
    }

    if (sizeOut) {
        sizeOut->width = ((float)lastGoodWidth) / 64.0f;
        sizeOut->height = ((float)(face->size->metrics.ascender - face->size->metrics.descender)) * spacing / 64.0f;
    }

    if (lastGoodIndex == 0)
        lastGoodIndex = count;

    _CGFontUnlock();

    return lastGoodIndex;
}

int freeTypeGetCharWidth(WORD* str, void* opaque, unsigned idx) {
    FT_Face face = (FT_Face)opaque;
    if (!face)
        return 1;

    FT_Error error;
    int ret = 0;
    int c = str[idx];

    if (c != 13) {
        FT_UInt index = FT_Get_Char_Index(face, c);

        error = FT_Load_Glyph(face, index, FT_LOAD_NO_HINTING);
        FT_GlyphSlot slot = face->glyph;

        if (error == 0) {
            ret = slot->advance.x;
        } else {
            TraceWarning(TAG, L"Glyph %d not found", c);
        }
    }

    return ret;
}

bool CGFontWrapFunc(CGFontWrapState* state,
                    float width,
                    CGSize* sizeOut,
                    int (*getCharWidth)(WORD*, void* opaque, unsigned idx),
                    void* opaque,
                    bool wrapChars) {
    FT_Pos penX = 0;

    FT_Pos lastPossibleBreakWidth = 0;
    int lastPossibleBreakPos = -1;

    bool ret = state->curIndex < state->count;
    if (state->hitLinebreak)
        ret = true;
    state->hitLinebreak = false;

    state->lineStart = &state->chars[state->curIndex];
    state->lineLen = -1;

    //  Lookup each glyph
    while (state->curIndex < state->count) {
        if (state->chars[state->curIndex] == 10 ||
            (state->curIndex > 0 && state->chars[state->curIndex - 1] == 13 && &state->chars[state->curIndex - 1] >= state->lineStart)) {
            if ((state->curIndex > 0 && state->chars[state->curIndex - 1] == 13 && state->chars[state->curIndex] != 10)) {
                state->curIndex--;
            }
            state->lineLen = &state->chars[state->curIndex] - state->lineStart;
            if (state->lineLen < 0)
                state->lineLen = 0;

            //  We have hit a hard linebreak, consume it
            state->curIndex++;
            state->hitLinebreak = true;

            if (sizeOut) {
                sizeOut->width = ((float)penX) / 64.0f;
            }
            break;
        }

        FT_Vector advance;
        int curChar = state->chars[state->curIndex];

        advance.x = 0;
        advance.y = 0;
        advance.x = getCharWidth(state->chars, opaque, state->curIndex);

        if (curChar == ' ' || wrapChars) {
            //  Soft linebreak possibility
            lastPossibleBreakPos = state->curIndex;
            lastPossibleBreakWidth = penX;
        }
        if (curChar != 13) {
            penX += advance.x;
        }

        float curWidth;

        curWidth = ((float)(penX)) / 64.0f;
        if (curWidth > width && curChar != ' ') {
            if (lastPossibleBreakPos != -1) {
                //  We must now perform a soft break
                state->lineLen = &state->chars[lastPossibleBreakPos] - state->lineStart;
                state->curIndex = lastPossibleBreakPos + 1;

                if (curChar == ' ') {
                    //  Do a hard line break
                    state->hitLinebreak = true;
                }
                if (sizeOut) {
                    sizeOut->width = ((float)lastPossibleBreakWidth) / 64.0f;
                }
            } else {
                //  Draw as many characters as we can
                if (state->lineStart != &state->chars[state->curIndex]) {
                    state->lineLen = &state->chars[state->curIndex] - state->lineStart;
                    penX -= advance.x;

                    if (sizeOut) {
                        sizeOut->width = ((float)penX) / 64.0f;
                    }
                    break;
                } else {
                    //  Draw at least one char
                    state->lineLen = 1;
                    state->curIndex++;

                    if (sizeOut) {
                        sizeOut->width = ((float)penX) / 64.0f;
                    }
                    break;
                }
            }
            break;
        }

        state->curIndex++;
    }

    //  Did not wrap
    if (state->lineLen == -1) {
        state->lineLen = &state->chars[state->count] - state->lineStart;
        if (sizeOut) {
            sizeOut->width = ((float)penX) / 64.0f;
        }
    }

    return ret;
}

bool CGFontWrap(id font, float size, CGFontWrapState* state, float width, CGSize* sizeOut) {
    if (!font) {
        if (sizeOut) {
            sizeOut->width = 0;
            sizeOut->height = 0;
        }
        return false;
    }

    _CGFontLock();

    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    CGFontSetFTFontSize(font, face, size);

    if (sizeOut && face) {
        sizeOut->width = 0;
        sizeOut->height = ((float)(face->size->metrics.ascender - face->size->metrics.descender)) * spacing / 64.0f;
    }

    bool ret = CGFontWrapFunc(state, width, sizeOut, freeTypeGetCharWidth, face);

    _CGFontUnlock();

    return ret;
}

DWORD CGFontMeasureGlyphs(id font, float size, WORD* glyphs, unsigned count, CGSize* sizeOut) {
    DWORD i;

    _CGFontLock();

    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    FT_Error error;
    FT_GlyphSlot slot = face->glyph;

    CGFontSetFTFontSize(font, face, size);

    FT_Pos penX = 0;
    FT_Pos penY = 0;

    //  Lookup each glyph
    for (i = 0; i < count; i++) {
        error = FT_Load_Glyph(face, glyphs[i], FT_LOAD_NO_HINTING);
        if (error != 0) {
            TraceError(TAG, L"CGFontMeasureGlyphs: unknown char %x err=%d", glyphs[i], error);
        } else {
            /* increment pen position */
            penX += slot->advance.x;
            penY += slot->advance.y;
        }
    }

    sizeOut->width = ((float)penX) / 64.0f;
    sizeOut->height = ((float)face->size->metrics.ascender - face->size->metrics.descender) * spacing / 64.0f;

    _CGFontUnlock();

    return count;
}

DWORD CGFontGetGlyphs(id font, WORD* str, DWORD length, WORD* glyphs) {
    DWORD i;
    int glyphsOut = 0;

    _CGFontLock();

    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];

    //  Lookup each glyph
    for (i = 0; i < length; i++) {
        glyphs[glyphsOut] = FT_Get_Char_Index(face, str[i]);
        if (glyphs[glyphsOut] == 0)
            continue;
        glyphsOut++;
    }

    _CGFontUnlock();

    return glyphsOut;
}

/**
 @Status Interoperable
*/
CFDataRef CGFontCopyTableForTag(CGFontRef font, uint32_t tag) {
    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];

    _CGFontLock();
    FT_Error err;

    DWORD numBytes = 0;
    err = FT_Load_Sfnt_Table(face, tag, 0, NULL, &numBytes);

    char* pData = (char*)IwMalloc(numBytes);
    err = FT_Load_Sfnt_Table(face, tag, 0, (FT_Byte*)pData, &numBytes);

    id ret = [[NSData alloc] initWithBytes:pData length:numBytes];
    IwFree(pData);

    _CGFontUnlock();

    return (CFDataRef)ret;
}

/**
 @Status Caveat
 @Notes Returns family name
*/
CFStringRef CGFontCopyFullName(CGFontRef font) {
    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];

    if (face->family_name == NULL)
        return nullptr;

    return (CFStringRef)[[NSString stringWithCString:face->family_name] retain];
}

/**
 @Status Interoperable
*/
CGFontRef CGFontCreateWithDataProvider(CGDataProviderRef cgDataProvider) {
    CFRetain(cgDataProvider);
    return (CGFontRef)[[_LazyUIFont fontWithData:(NSData*)cgDataProvider] retain];
}

/**
 @Status Interoperable
*/
void CGFontRelease(CGFontRef font) {
    [(id)font release];
}

/**
 @Status Interoperable
*/
CGFontRef CGFontRetain(CGFontRef font) {
    [(id)font retain];

    return font;
}

/**
 @Status Interoperable
*/
int CGFontGetUnitsPerEm(CGFontRef font) {
    //  Get the font
    FT_Face face = (FT_Face)[font _sizingFontHandle];
    return face->units_per_EM;
}

/**
 @Status Interoperable
*/
int CGFontGetXHeight(CGFontRef font) {
    return (int)[font xHeight];
}

/**
 @Status Interoperable
*/
CGFontRef CGFontCreateWithFontName(CFStringRef name) {
    return (CGFontRef)[[_LazyUIFont fontWithName:(NSString*)name size:1.0f] retain];
}

/**
 @Status Interoperable
*/
bool CGFontGetGlyphAdvances(CGFontRef font, const CGGlyph* glyphs, size_t count, int* advances) {
    DWORD i;

    _CGFontLock();
    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];

    FT_Error error;
    FT_GlyphSlot slot = face->glyph;

    //  Lookup each glyph
    for (i = 0; i < count; i++) {
        FT_Fixed fixed;

        error = FT_Get_Advance(face, glyphs[i], FT_LOAD_NO_SCALE | FT_LOAD_IGNORE_TRANSFORM, &fixed);
        assert(error == 0);

        advances[i] = fixed;
    }
    _CGFontUnlock();

    return 1;
}

/**
 @Status Interoperable
*/
CGRect CGFontGetFontBBox(CGFontRef font) {
    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];

    CGRect ret;
    ret.origin.x = (float)face->bbox.xMin;
    ret.origin.y = (float)face->bbox.yMin;
    ret.size.width = (float)(face->bbox.xMax - face->bbox.xMin);
    ret.size.height = (float)(face->bbox.yMax - face->bbox.yMin);

    return ret;
}

/**
 @Status Interoperable
*/
bool CGFontGetGlyphBBoxes(CGFontRef font, const CGGlyph* glyphs, size_t count, CGRect bboxes[]) {
    DWORD i;

    _CGFontLock();

    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    FT_Error error;
    FT_GlyphSlot slot = face->glyph;

    //  Lookup each glyph
    for (i = 0; i < count; i++) {
        FT_Glyph glyph;

        error = FT_Load_Glyph(face, glyphs[i], FT_LOAD_NO_SCALE | FT_LOAD_IGNORE_TRANSFORM);
        if (error != 0) {
            TraceError(TAG, L"CGFontGetGlyphBBoxes: unknown char %x err=%d", glyphs[i], error);

            bboxes[i].origin.x = 0;
            bboxes[i].origin.y = 0;
            bboxes[i].size.width = 1;
            bboxes[i].size.height = 1;
        } else {
            error = FT_Get_Glyph(slot, &glyph);

            //  Get the controlbox
            FT_BBox bbox;
            FT_Glyph_Get_CBox(glyph, FT_GLYPH_BBOX_UNSCALED, &bbox);

            bboxes[i].origin.x = (float)bbox.xMin;
            bboxes[i].origin.y = (float)bbox.yMin;
            bboxes[i].size.width = (float)(bbox.xMax - bbox.xMin);
            bboxes[i].size.height = (float)(bbox.yMax - bbox.yMin);

            FT_Done_Glyph(glyph);
        }
    }

    _CGFontUnlock();

    return TRUE;
}

/**
 @Status Stub
*/
int CGFontGetLeading(CGFontRef font) {
    UNIMPLEMENTED();
    //  Get the font
    FT_Face face = (FT_Face)[font _sizingFontHandle];

    /* [BUG: Not sure where to find this value] */
    return 5;
}

/**
 @Status Interoperable
*/
int CGFontGetAscent(CGFontRef font) {
    //  Get the font
    FT_Face face = (FT_Face)[font _sizingFontHandle];
    return face->ascender;
}

/**
 @Status Interoperable
*/
int CGFontGetDescent(CGFontRef font) {
    FT_Face face = (FT_Face)[font _sizingFontHandle];
    return face->descender;
}

/**
 @Status Interoperable
*/
int CGFontGetCapHeight(CGFontRef font) {
    FT_Face face = (FT_Face)[font _sizingFontHandle];

    int ret;
    _CGFontLock();
    TT_PCLT* ttFontInfo = (TT_PCLT*)FT_Get_Sfnt_Table(face, ft_sfnt_pclt);

    if (ttFontInfo) {
        ret = (signed int)ttFontInfo->CapHeight;
        _CGFontUnlock();
        return ret;
    } else {
        const char* string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int length = strlen(string);
        int ret = 0;
        FT_Error error;
        FT_GlyphSlot slot = face->glyph;

        //  Lookup each glyph
        for (int i = 0; i < length; i++) {
            WORD index = FT_Get_Char_Index(face, string[i]);

            FT_Glyph glyph;

            error = FT_Load_Glyph(face, index, FT_LOAD_NO_SCALE | FT_LOAD_IGNORE_TRANSFORM);
            assert(error == 0);
            error = FT_Get_Glyph(slot, &glyph);

            //  Get the controlbox
            FT_BBox bbox;
            FT_Glyph_Get_CBox(glyph, FT_GLYPH_BBOX_UNSCALED, &bbox);

            if (bbox.yMax > ret)
                ret = bbox.yMax;

            FT_Done_Glyph(glyph);
        }
        _CGFontUnlock();

        return ret;
    }
}

/**
 @Status Stub
 @Notes
*/
bool CGFontCanCreatePostScriptSubset(CGFontRef font, CGFontPostScriptFormat format) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CGFontCopyGlyphNameForGlyph(CGFontRef font, CGGlyph glyph) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFStringRef CGFontCopyPostScriptName(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CGFontCopyTableTags(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFArrayRef CGFontCopyVariationAxes(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CGFontCopyVariations(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGFontRef CGFontCreateCopyWithVariations(CGFontRef font, CFDictionaryRef variations) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CGFontCreatePostScriptEncoding(CGFontRef font, const CGGlyph encoding[256]) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDataRef CGFontCreatePostScriptSubset(CGFontRef font,
                                       CFStringRef subsetName,
                                       CGFontPostScriptFormat format,
                                       const CGGlyph* glyphs,
                                       size_t count,
                                       const CGGlyph encoding[256]) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGGlyph CGFontGetGlyphWithGlyphName(CGFontRef font, CFStringRef name) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGFloat CGFontGetItalicAngle(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CGFontGetNumberOfGlyphs(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGFloat CGFontGetStemV(CGFontRef font) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGFontGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

// TODO: functions below are not part of offical exports, but they are also exported
// to be used by other framework components, we should consider moving them to a shared library
unsigned long CGFontGetGlyphsForUnichars(id font, unsigned short* chars, unsigned short* glyphs, int num) {
    CGFontGetGlyphs(font, chars, num, glyphs);
    return TRUE;
}

float CGFontGetDescentAtSize(id font, float size) {
    _CGFontLock();
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    CGFontSetFTFontSize(font, face, size);

    float ret = ((float)face->size->metrics.descender) / 64.0f;
    _CGFontUnlock();

    return ret;
}

float CGFontGetAscentAtSize(id font, float size) {
    _CGFontLock();
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    CGFontSetFTFontSize(font, face, size);

    float ret = ((float)face->size->metrics.ascender) / 64.0f;
    _CGFontUnlock();

    return ret;
}

static pthread_mutex_t _fontLock = PTHREAD_MUTEX_INITIALIZER;

void _CGFontLock() {
    pthread_mutex_lock(&_fontLock);
}

void _CGFontUnlock() {
    pthread_mutex_unlock(&_fontLock);
}
