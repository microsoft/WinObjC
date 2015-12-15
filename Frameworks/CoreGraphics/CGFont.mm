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

#include "Starboard.h"

#include "CGContextInternal.h"
#include "CGFontInternal.h"
#include "CoreText/CoreText.h"

#include "Etc.h"

DWORD CGFontGetFontBBox(CGRect* ret, id font);

static IWLazyClassLookup _LazyUIFont("UIFont");
static IWLazyIvarLookup<float> _LazyUIFontHorizontalScale(_LazyUIFont, "_horizontalScale");

extern "C" {
#include <ft2build.h>
#include FT_FREETYPE_H
#include <ftglyph.h>
#include <tttables.h>
#include <ftadvanc.h>
#include <ftsizes.h>
}

const CFStringRef kCTCharacterShapeAttributeName = static_cast<CFStringRef>(@"kCTCharacterShapeAttributeName");
const CFStringRef kCTFontAttributeName = static_cast<CFStringRef>(@"NSFontAttributeName");
const CFStringRef kCTKernAttributeName = static_cast<CFStringRef>(@"kCTKernAttributeName");
const CFStringRef kCTLigatureAttributeName = static_cast<CFStringRef>(@"kCTLigatureAttributeName");
const CFStringRef kCTForegroundColorAttributeName = static_cast<CFStringRef>(@"NSForegroundColorAttributeName");
const CFStringRef kCTForegroundColorFromContextAttributeName = static_cast<CFStringRef>(@"kCTForegroundColorFromContextAttributeName");
const CFStringRef kCTParagraphStyleAttributeName = static_cast<CFStringRef>(@"kCTParagraphStyleAttributeName");
const CFStringRef kCTStrokeWidthAttributeName = static_cast<CFStringRef>(@"kCTStrokeWidthAttributeName");
const CFStringRef kCTStrokeColorAttributeName = static_cast<CFStringRef>(@"kCTStrokeColorAttributeName");
const CFStringRef kCTSuperscriptAttributeName = static_cast<CFStringRef>(@"kCTSuperscriptAttributeName");
const CFStringRef kCTUnderlineColorAttributeName = static_cast<CFStringRef>(@"kCTUnderlineColorAttributeName");
const CFStringRef kCTUnderlineStyleAttributeName = static_cast<CFStringRef>(@"kCTUnderlineStyleAttributeName");
const CFStringRef kCTVerticalFormsAttributeName = static_cast<CFStringRef>(@"kCTVerticalFormsAttributeName");
const CFStringRef kCTGlyphInfoAttributeName = static_cast<CFStringRef>(@"kCTGlyphInfoAttributeName");
const CFStringRef kCTRunDelegateAttributeName = static_cast<CFStringRef>(@"kCTRunDelegateAttributeName");
const CFStringRef kCTBackgroundStrokeColorAttributeName = static_cast<CFStringRef>(@"kCTBackgroundStrokeColorAttributeName");
const CFStringRef kCTBackgroundFillColorAttributeName = static_cast<CFStringRef>(@"kCTBackgroundFillColorAttributeName");
const CFStringRef kCTBackgroundCornerRadiusAttributeName = static_cast<CFStringRef>(@"kCTBackgroundCornerRadiusAttributeName");
const CFStringRef kCTBackgroundLineWidthAttributeName = static_cast<CFStringRef>(@"kCTBackgroundLineWidthAttributeName");
const CFStringRef kCTFontPostScriptNameKey = static_cast<CFStringRef>(@"kCTFontPostScriptNameKey");

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
            EbrDebugLog("Glyph %d not found\n", c);
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
            EbrDebugLog("CGFontMeasureGlyphs: unknown char %x err=%d\n", glyphs[i], error);
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

    char* pData = (char*)EbrMalloc(numBytes);
    err = FT_Load_Sfnt_Table(face, tag, 0, (FT_Byte*)pData, &numBytes);

    id ret = [[NSData alloc] initWithBytes:pData length:numBytes];
    EbrFree(pData);

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
    [cgDataProvider retain];
    return (CGFontRef)[[_LazyUIFont fontWithData:cgDataProvider] retain];
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
            EbrDebugLog("CGFontGetGlyphBBoxes: unknown char %x err=%d\n", glyphs[i], error);

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
        char* string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
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

DWORD CGFontGetGlyphsForUnichars(id font, WORD* chars, WORD* glyphs, int num) {
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

static EbrLock _fontLock = EBRLOCK_INITIALIZE;

void _CGFontLock() {
    EbrLockEnter(_fontLock);
}

void _CGFontUnlock() {
    EbrLockLeave(_fontLock);
}

@interface _CTFrameSetter : NSObject {
@public
    idretain _attributedString;
}
@end

@implementation _CTFrameSetter : NSObject
- (void)dealloc {
    _attributedString = nil;
    [super dealloc];
}

@end

@interface _CTFrame : NSObject {
@public
    _CTFrameSetter* _frameSetter;
    CGRect _frameRect;
    CGSize _totalSize;
    idretain _lines;
}
@end

@implementation _CTFrame : NSObject
- (void)dealloc {
    [_frameSetter release];
    [super dealloc];
}

@end

@interface _CTLine : NSObject {
@public
    idretain _str;
    NSRange _strRange;
    CGPoint _origin;
    idretain _runs;
}
@end

@implementation _CTLine : NSObject
- (void)dealloc {
    _runs = nil;
    _str = nil;
    [super dealloc];
}

@end

@interface _CTRun : NSObject {
@public
    _CTLine* _line;
    float _xPos;
    idretain _font;
    idretain _textColor;
    idretain _stringFragment;
}
@end

@implementation _CTRun : NSObject
- (void)dealloc {
    [_line release];
    _font = nil;
    _stringFragment = nil;
    _textColor = nil;
    [super dealloc];
}

@end

/**
 @Status Interoperable
*/
CTFramesetterRef CTFramesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTFrameSetter* ret = [_CTFrameSetter alloc];
    ret->_attributedString = (NSString*)string;
    return (CTFramesetterRef)ret;
}

typedef struct {
    id attributedString;
    CGSize* sizeOut;
    bool haveRange;
    NSRange curRange;
    FT_Face curFace;
} attributeWrapState;

static int attributeGetCharWidth(WORD* str, void* opaque, unsigned idx) {
    attributeWrapState* state = (attributeWrapState*)opaque;

    if (!state->haveRange || idx < state->curRange.location || idx >= (state->curRange.location + state->curRange.length)) {
        state->haveRange = true;
        id attribs = [state->attributedString attributesAtIndex:idx effectiveRange:&state->curRange];
        id font = [attribs objectForKey:@"kCTFontAttributeName"];
        state->curFace = (FT_Face)(DWORD)[font _sizingFontHandle];
        CGFontSetFTFontSize(font, state->curFace, [font pointSize]);
    }

    float height = ((float)(state->curFace->size->metrics.ascender - state->curFace->size->metrics.descender)) * spacing / 64.0f;
    if (height > state->sizeOut->height) {
        state->sizeOut->height = height;
    }
    FT_Error error;
    int ret = 0;
    int c = str[idx];

    if (c != 13) {
        FT_UInt index = FT_Get_Char_Index(state->curFace, c);

        error = FT_Load_Glyph(state->curFace, index, FT_LOAD_NO_HINTING);
        FT_GlyphSlot slot = state->curFace->glyph;

        if (error == 0) {
            ret = slot->advance.x;
        } else {
            EbrDebugLog("Glyph %d not found\n", c);
        }
    }

    return ret;
}

bool CGFontWrapWithAttributes(id attributedString, CGFontWrapState* state, float width, CGSize* sizeOut) {
    _CGFontLock();

    attributeWrapState wrapState = { 0 };
    wrapState.sizeOut = sizeOut;
    wrapState.attributedString = attributedString;
    sizeOut->height = 0.0f;

    bool ret = CGFontWrapFunc(state, width, sizeOut, attributeGetCharWidth, &wrapState);

    _CGFontUnlock();

    return ret;
}

static id createFrame(_CTFrameSetter* frameSetter, CGRect frameSize, CGSize* sizeOut, bool createFrame) {
    _CTFrame* ret = nil;

    if (createFrame) {
        ret = [_CTFrame alloc];
        ret->_frameSetter = [frameSetter retain];
        ret->_frameRect = frameSize;

        ret->_lines.attach([NSMutableArray new]);
    }

    id string = [frameSetter->_attributedString string];

    CGFontWrapState state;
    WORD* str;
    DWORD strLength;

    memset(&state, 0, sizeof(state));
    strLength = [string length];
    str = (WORD*)malloc(sizeof(WORD) * strLength);
    [string getCharacters:str];

    state.chars = str;
    state.count = strLength;
    state.curIndex = 0;
    float y = frameSize.size.height; //[font ascender];

    CGSize fitSize;
    float fitWidth = frameSize.size.width;

    sizeOut->width = 0;
    sizeOut->height = 0;

    //  Keep drawing lines of text until we're out of characters
    while (CGFontWrapWithAttributes(frameSetter->_attributedString, &state, fitWidth, &fitSize)) {
        if (ret) {
            NSRange lineRange;
            lineRange.location = state.lineStart - state.chars;
            lineRange.length = state.lineLen;

            _CTLine* line = [_CTLine new];
            line->_origin.x = 0.0f;
            line->_str = [string substringWithRange:lineRange];
            line->_runs.attach([NSMutableArray new]);
            line->_strRange = lineRange;

            unsigned curIdx = lineRange.location;
            float ascender = 0.0f;
            NSRange curRange;
            while (curIdx < lineRange.location + lineRange.length) {
                id attribs = [frameSetter->_attributedString attributesAtIndex:curIdx effectiveRange:&curRange];
                int fragmentLen = curRange.location + curRange.length - curIdx;

                NSRange runRange;
                runRange.location = curIdx;
                runRange.length = (curRange.location + curRange.length) - curIdx;
                if (runRange.location + runRange.length > lineRange.location + lineRange.length) {
                    runRange.length = lineRange.location + lineRange.length - runRange.location;
                }
                _CTRun* run = [_CTRun new];
                run->_font = [attribs objectForKey:@"kCTFontAttributeName"];
                if ([run->_font ascender] > ascender) {
                    ascender = [run->_font ascender];
                }
                id color = [attribs objectForKey:@"kCTForegroundColorAttributeName"];
                run->_textColor = color;
                run->_line = line;
                run->_stringFragment = [string substringWithRange:runRange];
                [line->_runs addObject:(id)run];

                curIdx = curRange.location + curRange.length;
            }

            line->_origin.y = y - ascender;
            [ret->_lines addObject:(id)line];
            [line release];
        }

        if (fitSize.width > sizeOut->width)
            sizeOut->width = fitSize.width;
        sizeOut->height += fitSize.height;

        y -= fitSize.height;
    }

    free(str);

    if (ret) {
        ret->_totalSize = *sizeOut;
    }

    return ret;
}

/**
 @Status Interoperable
*/
CTFrameRef CTFramesetterCreateFrame(CTFramesetterRef framesetter, CFRange stringRange, CGPathRef path, CFDictionaryRef frameAttributes) {
    CGRect frameSize;
    [path _getBoundingBox:&frameSize];

    CGSize sizeOut;
    id ret = createFrame((_CTFrameSetter*)framesetter, frameSize, &sizeOut, true);

    return (CTFrameRef)ret;
}

/**
 @Status Interoperable
*/
CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef string) {
    id str = [string string];
    NSRange lineRange;
    lineRange.location = 0;
    lineRange.length = [str length];

    _CTLine* line = [_CTLine new];
    line->_origin.x = 0.0f;
    line->_origin.y = 0.0f;
    line->_str = (NSString*)str;
    line->_strRange = lineRange;

    return (CTLineRef)line;
}

/**
 @Status Stub
 @Notes Line is not truncated
*/
CTLineRef CTLineCreateTruncatedLine(CTLineRef line, double width, CTLineTruncationType truncationType, CTLineRef truncationToken) {
    UNIMPLEMENTED();
    id str = ((_CTLine*)line)->_str;
    NSRange lineRange = ((_CTLine*)line)->_strRange;

    _CTLine* ret = [_CTLine new];
    ret->_origin.x = 0.0f;
    ret->_origin.y = 0.0f;
    ret->_str = (NSString*)str;
    ret->_strRange = lineRange;

    return (CTLineRef)ret;
}

/**
 @Status Caveat
*/
CGSize CTFramesetterSuggestFrameSizeWithConstraints(
    CTFramesetterRef framesetter, CFRange stringRange, CFDictionaryRef frameAttributes, CGSize constraints, CFRange* fitRange) {
    CGSize ret;
    if (fitRange)
        *fitRange = stringRange;

    CGRect frameSize = { 0, 0, 0, 0 };
    frameSize.size = constraints;

    createFrame((_CTFrameSetter*)framesetter, frameSize, &ret, false);

    return ret;
}

/**
 @Status Interoperable
*/
CFArrayRef CTFrameGetLines(CTFrameRef frame) {
    return (CFArrayRef)(id)((_CTFrame*)frame)->_lines;
}

/**
 @Status Interoperable
*/
void CTFrameGetLineOrigins(CTFrameRef frame, CFRange range, CGPoint origins[]) {
    if (range.length == 0) {
        range.length = 0x7FFFFFF;
    }

    unsigned count = [((_CTFrame*)frame)->_lines count];
    int idx = 0;

    for (unsigned i = range.location; i < count && i < range.location + range.length; i++) {
        _CTLine* curLine = [((_CTFrame*)frame)->_lines objectAtIndex:i];
        origins[idx] = curLine->_origin;
        idx++;
    }
}

/**
 @Status Interoperable
*/
CFRange CTLineGetStringRange(CTLineRef line) {
    CFRange ret;
    NSRange range = ((_CTLine*)line)->_strRange;
    ret.length = range.length;
    ret.location = range.location;

    return ret;
}

/**
 @Status Caveat
 @Notes Values only reflect the typographical maximums for the font - string is only evaulated
        for width
*/
double CTLineGetTypographicBounds(CTLineRef line, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    id font = [_LazyUIFont defaultFont];
    if (ascent)
        *ascent = [font ascender];
    if (descent)
        *descent = [font descender];
    if (leading)
        *leading = [font leading];

    CGSize size;
    size = [((_CTLine*)line)->_str sizeWithFont:font];

    return size.width;
}

/**
 @Status Stub
 @Notes Returns 0.0
*/
double CTLineGetPenOffsetForFlush(CTLineRef line, CGFloat flushFactor, double flushWidth) {
    UNIMPLEMENTED();
    return 0.0;
}

/**
 @Status Interoperable
*/
CFArrayRef CTLineGetGlyphRuns(CTLineRef line) {
    return (CFArrayRef)[((_CTLine*)line)->_runs retain];
}

/**
 @Status Stub
*/
CFDictionaryRef CTRunGetAttributes(CTRunRef run) {
    UNIMPLEMENTED();
    id ret = [NSMutableDictionary new];
    [ret setObject:(id)CGColorGetConstantColor((CFStringRef) @"BLACK") forKey:(id)kCTBackgroundStrokeColorAttributeName];
    [ret setObject:(id)CGColorGetConstantColor((CFStringRef) @"WHITE") forKey:(id)kCTBackgroundFillColorAttributeName];
    [ret setObject:[NSNumber numberWithFloat:3.0f] forKey:(id)kCTBackgroundCornerRadiusAttributeName];
    [ret setObject:[NSNumber numberWithFloat:1.0f] forKey:(id)kCTBackgroundLineWidthAttributeName];

    return (CFDictionaryRef)ret;
}

/**
 @Status Caveat
 @Notes Only font face, size and text color attributes are supported.  Background fill is
        always white.
*/
void CTLineDraw(CTLineRef line, CGContextRef ctx) {
    for (_CTRun* curRun in (NSArray*)((_CTLine*)line)->_runs) {
        id string = curRun->_stringFragment;
        NSRange range;
        range.location = 0;
        range.length = [string length];

        WORD* characters = (WORD*)EbrMalloc(sizeof(WORD) * (range.length + 1));
        WORD* glyphs = (WORD*)EbrMalloc(sizeof(WORD) * (range.length + 1));
        [string getCharacters:characters range:range];

        id font = curRun->_font;
        CGFontGetGlyphsForUnichars(font, characters, glyphs, range.length);
        CGContextSetFont(ctx, font);
        CGContextSetFontSize(ctx, [font pointSize]);

        CGContextSetFillColorWithColor(ctx, (CGColorRef)(id)curRun->_textColor);
        CGContextSetStrokeColorWithColor(ctx, (CGColorRef)(id)CGColorGetConstantColor((CFStringRef) @"WHITE"));

        CGPoint curTextPos;
        ctx->Backing()->CGContextGetTextPosition(&curTextPos);

        CGContextShowGlyphsAtPoint(ctx, curTextPos.x, curTextPos.y, glyphs, range.length);
        EbrFree(glyphs);
        EbrFree(characters);
    }
}

/**
 @Status Interoperable
*/
id CTFontDescriptorCreateWithAttributes(id fontAttributes) {
    return [fontAttributes copy];
}

/**
 @Status Stub
 @Notes Always returns Helvetica 12-point font
*/
CTFontRef CTFontCreateWithFontDescriptor(CTFontDescriptorRef descriptor, CGFloat size, const CGAffineTransform* matrix) {
    UNIMPLEMENTED();
    if (size == 0.0f)
        size = 12.0f;
    id ret = [[_LazyUIFont fontWithName:@"Helvetica" size:size] retain];
    return (CTFontRef)ret;
}

/**
 @Status Caveat
 @Notes transform and attributes parameters not supported
*/
CTFontRef CTFontCreateWithGraphicsFont(CGFontRef cgFont, CGFloat size, CGAffineTransform* xform, id attributes) {
    if (size == 0.0f)
        size = 12.0f;
    id ret = [[(UIFont*)cgFont fontWithSize:size] retain];
    return (CTFontRef)ret;
}

/**
 @Status Caveat
 @Notes orientation parameter not supported
*/
double CTFontGetAdvancesForGlyphs(CTFontRef font, int orientation, const CGGlyph* glyphs, CGSize* advances, size_t count) {
    DWORD i;
    double total = 0.0f;

    _CGFontLock();
    //  Get the font
    FT_Face face = (FT_Face)(DWORD)[font _sizingFontHandle];
    CGFontSetFTFontSize((CGFontRef)font, face, [font pointSize]);

    FT_Error error;
    FT_GlyphSlot slot = face->glyph;

    //  Lookup each glyph
    for (i = 0; i < count; i++) {
        error = FT_Load_Glyph(face, glyphs[i], FT_LOAD_NO_HINTING);
        FT_GlyphSlot slot = face->glyph;

        CGSize size = { 0, 0 };
        if (error == 0) {
            size.width = ((float)(slot->advance.x)) / 64.0f;
        }

        if (advances)
            advances[i] = size;
        total += size.width;
    }
    _CGFontUnlock();

    return total;
}

/**
 @Status Interoperable
*/
float CTFontGetAscent(CTFontRef font) {
    //  Get the font
    return [font ascender];
}

/**
 @Status Interoperable
*/
float CTFontGetDescent(CTFontRef font) {
    return [font descender];
}

/**
 @Status Interoperable
*/
float CTFontGetSize(CTFontRef font) {
    float ret = [font pointSize];

    return ret;
}

CTFontRef CTFontCopyGraphicsFont(CGFontRef font, CFDictionaryRef attributes) {
    return (CTFontRef)[font retain];
}

/**
 @Status Caveat
 @Notes Always returns font family name
*/
CFStringRef CTFontCopyPostScriptName(CTFontRef font) {
    return (CFStringRef)[[font fontName] retain];
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyFamilyName(CTFontRef font) {
    return (CFStringRef)[[font fontName] retain];
}

/**
 @Status Stub
*/
CTParagraphStyleRef CTParagraphStyleCreate(const CTParagraphStyleSetting* settings, CFIndex settingCount) {
    UNIMPLEMENTED();
    return (CTParagraphStyleRef)[NSObject new];
}

@implementation UITextPosition
@end

@implementation UITextRange {
@public
    idretain _start, _end;
    BOOL _empty;
}
+ (instancetype)textRangeWithPositon:(int)position length:(int)length {
    UITextRange* ret = [self alloc];

    ret->_start.attach([UITextPosition new]);
    ret->_end.attach([UITextPosition new]);
    ret->_empty = length == 0;

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (BOOL)isEmpty {
    return _empty;
}

/**
 @Status Interoperable
*/
- (UITextPosition*)start {
    return _start;
}

/**
 @Status Interoperable
*/
- (UITextPosition*)end {
    return _end;
}

- (void)dealloc {
    _start = nil;
    _end = nil;
    [super dealloc];
}
@end

/**
 @Status Stub
*/
CTFontRef CTFontCreateCopyWithSymbolicTraits(
    CTFontRef font, CGFloat size, const CGAffineTransform* matrix, CTFontSymbolicTraits symTraitValue, CTFontSymbolicTraits symTraitMask) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
void CTFrameDraw(CTFrameRef frame, CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
CFIndex CTLineGetStringIndexForPosition(CTLineRef line, CGPoint position) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
CFStringRef CTFontCopyName(CTFontRef font, CFStringRef nameKey) {
    UNIMPLEMENTED();
    return nullptr;
}

/**
 @Status Stub
*/
CGFloat CTFontGetUnderlineThickness(CTFontRef self) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
CGFloat CTLineGetOffsetForStringIndex(CTLineRef line, CFIndex charIndex, CGFloat* secondaryOffset) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
double CTRunGetTypographicBounds(CTRunRef run, CFRange range, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    UNIMPLEMENTED();
    return 0;
}

/**
 @Status Stub
*/
CFRange CTRunGetStringRange(CTRunRef run) {
    UNIMPLEMENTED();
    return { 0, 0 };
}
