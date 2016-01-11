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

#include <CoreText/CoreText.h>
#include "CGContextInternal.h"
#include "CGFontInternal.h"
#include "CoreText/CoreText.h"

#include "Etc.h"

#include <vector>
#include <algorithm>

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
const CFStringRef kCTFontAttributeName = static_cast<CFStringRef>(@"NSFont");
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
    CFRetain(cgDataProvider);
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

@interface _CTTypesetter : NSObject {
@public
    NSAttributedString* _attributedString;
    NSString* _string;
    WORD* _characters;
    CFIndex _charactersLen;
}
@end

@implementation _CTTypesetter
- (instancetype)initWithAttributedString:(NSAttributedString*)str {
    _attributedString = [str retain];
    _string = [[str string] retain];

    //  Measure the string
    _charactersLen = [_string length];
    _characters = (WORD*)malloc(sizeof(WORD) * _charactersLen);
    [_string getCharacters:_characters];

    return self;
}

- (void)dealloc {
    if (_characters) {
        free(_characters);
    }
    [_string release];
    [_attributedString release];
    [super dealloc];
}
@end

@interface _CTFrameSetter : NSObject {
@public
    idretaintype(_CTTypesetter) _typesetter;
}
@end

@implementation _CTFrameSetter : NSObject
- (void)dealloc {
    [super dealloc];
}
@end

@interface _CTFrame : NSObject {
@public
    _CTFrameSetter* _frameSetter;
    CGRect _frameRect;
    CGSize _totalSize;
    idretaintype(NSMutableArray) _lines;
    std::vector<CGPoint> _lineOrigins;
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
    NSRange _strRange;
    CGFloat _width;
    CGFloat _ascent, _descent, _leading;
    idretaintype(NSMutableArray) _runs;
}
@end

@implementation _CTLine : NSObject
- (void)dealloc {
    _runs = nil;
    [super dealloc];
}

@end

@interface _CTRun : NSObject {
@public
    CFRange _range;
    float _xPos;
    idretaintype(UIFont) _font;
    idretaintype(UIColor) _textColor;
    idretaintype(NSString) _stringFragment;
    std::vector<CGPoint> _glyphOrigins;
    std::vector<CGSize> _glyphAdvances;
    std::vector<WORD> _characters;
}
@end

@implementation _CTRun : NSObject
- (void)dealloc {
    _font = nil;
    _stringFragment = nil;
    _textColor = nil;
    [super dealloc];
}

@end

CTTypesetterRef CTTypesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTTypesetter* ret = [[_CTTypesetter alloc] initWithAttributedString:(NSAttributedString*)string];
    return (CTTypesetterRef)ret;

    /**
     @Status Interoperable
    */
}

CTFramesetterRef CTFramesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTFrameSetter* ret = [_CTFrameSetter alloc];
    ret->_typesetter = (_CTTypesetter*)CTTypesetterCreateWithAttributedString(string);
    return (CTFramesetterRef)ret;
}

#if 0
static int attributeGetCharWidth(WORD* str, void* opaque, unsigned idx) {
    attributeWrapState* state = (attributeWrapState*)opaque;

    if (!state->haveRange || idx < state->curRange.location || idx >= (state->curRange.location + state->curRange.length)) {
        state->haveRange = true;
        id attribs = [state->attributedString attributesAtIndex:idx effectiveRange:&state->curRange];
        id font = [attribs objectForKey:(id)kCTFontAttributeName];
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
#endif

typedef float (*WidthFinderFunc)(void* opaque, CFIndex idx, float offset, float height);

static CFIndex DoWrap(CTTypesetterRef ts, CFRange range, WidthFinderFunc widthFunc, void* widthParam, double offset, CTLineRef* outLine) {
    _CTTypesetter* typeSetter = (_CTTypesetter*)ts;
    _CTLine* line = NULL;

    if (outLine) {
        line = [_CTLine new];
        *outLine = (CTLineRef)line;
    }

    if (range.length == -1) {
        range.length = typeSetter->_charactersLen - range.location;
    }

    //  Measure the string
    WORD* chars = typeSetter->_characters;
    int curIndex = range.location;
    int count = range.location + range.length;
    bool hitLinebreak = false;

    CFIndex lineStart = NULL;

    std::vector<CGPoint> glyphOrigins;
    std::vector<CGSize> glyphAdvances;
    std::vector<WORD> characters;
    float lineWidth = 0.0f;

    FT_Pos penX = 0;

    FT_Pos lastPossibleBreakWidth = 0;
    int lastPossibleBreakPos = -1;

    lineStart = curIndex;

    NSRange curAttributeRange = { 0 };
    FT_Face curFace;
    float curFontHeight = 0.0f;
    float maxWidth = FLT_MAX;

    //  Lookup each glyph
    while (curIndex < count) {
        glyphOrigins.push_back(CGPointMake(((float)penX) / 64.0f, 0.0f));
        glyphAdvances.push_back(CGSizeMake(0, 0));

        int curChar = chars[curIndex];

        if (curChar != 10 && curChar != 13 && curChar != 9) {
            characters.push_back((WORD)curChar);
        } else {
            characters.push_back((WORD)0);
        }

        auto& glyphOrigin = glyphOrigins.back();
        auto& glyphAdvance = glyphAdvances.back();

        if (chars[curIndex] == 10 || (curIndex > 0 && chars[curIndex - 1] == 13 && curIndex - 1 >= lineStart)) {
            if ((curIndex > 0 && chars[curIndex - 1] == 13 && chars[curIndex] != 10)) {
                curIndex--;
            }

            //  We have hit a hard linebreak, consume it
            curIndex++;

            lineWidth = ((float)penX) / 64.0f;
            break;
        }

        FT_Vector advance;

        advance.x = 0;
        advance.y = 0;

        //  Have we reached a new attribute range?
        if (curIndex < curAttributeRange.location || curIndex >= (curAttributeRange.location + curAttributeRange.length)) {
            //  Grab and set the new font
            NSDictionary* attribs = [typeSetter->_attributedString attributesAtIndex:curIndex effectiveRange:&curAttributeRange];
            UIFont* font = [attribs objectForKey:(NSString*)kCTFontAttributeName];
            curFace = (FT_Face)[font _sizingFontHandle];
            CGFontSetFTFontSize(font, curFace, [font pointSize]);

            float fontHeight = ((float)(curFace->size->metrics.ascender - curFace->size->metrics.descender)) * spacing / 64.0f;
            float curX = ((float)penX) / 64.0f;
            float width = widthFunc(widthParam, curIndex, curX, fontHeight);

            maxWidth = curX + width;
        }

        //  Grab the width of the current character
        FT_Error error;

        if (curChar != 13) {
            FT_UInt index = FT_Get_Char_Index(curFace, curChar);

            error = FT_Load_Glyph(curFace, index, FT_LOAD_NO_HINTING);
            FT_GlyphSlot slot = curFace->glyph;

            if (error == 0) {
                advance.x = slot->advance.x;
            } else {
                EbrDebugLog("Glyph %d not found\n", curChar);
            }

            if (curChar == ' ') {
                //  Soft linebreak possibility
                lastPossibleBreakPos = curIndex;
                lastPossibleBreakWidth = penX;
            }
            penX += advance.x;

            glyphAdvance.width = ((float)advance.x) / 64.0f;
        }

        float curWidth;

        if ((penX / 64.0f) > maxWidth && curChar != ' ') {
            if (lastPossibleBreakPos != -1) {
                //  We must now perform a soft break
                curIndex = lastPossibleBreakPos + 1;

                if (curChar == ' ') {
                    //  Do a hard line break
                    hitLinebreak = true;
                }
                lineWidth = ((float)lastPossibleBreakWidth) / 64.0f;
            } else {
                if (lineStart != curIndex) {
                    //  Back out the last character
                    penX -= advance.x;
                }
                lineWidth = ((float)penX) / 64.0f;
                break;
            }
            break;
        }

        curIndex++;
    }

    if (curIndex >= count) {
        lineWidth = ((float)penX) / 64.0f;
    }

    if (line) {
        NSRange lineRange = NSMakeRange(range.location, range.length);
        line->_runs.attach([NSMutableArray new]);
        line->_strRange = lineRange;
        line->_width = lineWidth;

        unsigned curIdx = lineRange.location;
        float ascender = 0.0f;
        float descender = 0.0f;
        float leading = 0.0f;
        NSRange curRange;
        unsigned glyphIdx = 0;

        while (curIdx < lineRange.location + lineRange.length) {
            id attribs = [typeSetter->_attributedString attributesAtIndex:curIdx effectiveRange:&curRange];
            int fragmentLen = curRange.location + curRange.length - curIdx;

            NSRange runRange;
            runRange.location = curIdx;
            runRange.length = (curRange.location + curRange.length) - curIdx;
            if (runRange.location + runRange.length > lineRange.location + lineRange.length) {
                runRange.length = lineRange.location + lineRange.length - runRange.location;
            }
            _CTRun* run = [_CTRun new];
            run->_font = [attribs objectForKey:(id)kCTFontAttributeName];
            if ([run->_font ascender] > ascender) {
                ascender = [run->_font ascender];
            }
            if ([run->_font descender] < descender) {
                descender = [run->_font descender];
            }
            if ([run->_font leading] > leading) {
                leading = [run->_font leading];
            }

            id color = [attribs objectForKey:(id)kCTForegroundColorAttributeName];
            run->_textColor = color;
            run->_range.location = runRange.location;
            run->_range.length = runRange.length;
            run->_stringFragment = [typeSetter->_string substringWithRange:runRange];
            run->_glyphOrigins.assign(glyphOrigins.begin() + glyphIdx, glyphOrigins.begin() + glyphIdx + runRange.length);
            run->_glyphAdvances.assign(glyphAdvances.begin() + glyphIdx, glyphAdvances.begin() + glyphIdx + runRange.length);
            run->_characters.assign(characters.begin() + glyphIdx, characters.begin() + glyphIdx + runRange.length);
            run->_characters.erase(std::remove(run->_characters.begin(), run->_characters.end(), 0), run->_characters.end());
            glyphIdx += runRange.length;
            [line->_runs addObject:(id)run];
            CFRelease(run);

            curIdx = curRange.location + curRange.length;
        }

        line->_ascent = ascender;
        line->_descent = descender;
        line->_leading = leading;
    }

    return curIndex;
}

static float FixedWidthFinderFunc(void* opaque, CFIndex idx, float offset, float height) {
    return *((double*)opaque) - offset;
}

static float UnlimitedWidthFinderFunc(void* opaque, CFIndex idx, float offset, float height) {
    return FLT_MAX;
}

CFIndex CTTypesetterSuggestLineBreakWithOffsetAndCallback(
    CTTypesetterRef ts, CFIndex index, double offset, WidthCalculationCallback callback, void* opaque) {
    return DoWrap(ts, CFRangeMake(index, -1), callback, opaque, offset, NULL);
}

CFIndex CTTypesetterSuggestLineBreakWithOffset(CTTypesetterRef ts, CFIndex index, double width, double offset) {
    return CTTypesetterSuggestLineBreakWithOffsetAndCallback(ts, index, offset, FixedWidthFinderFunc, &width);
}

CTLineRef CTTypesetterCreateLineWithOffset(CTTypesetterRef ts, CFRange range, double offset) {
    CTLineRef ret = NULL;

    DoWrap(ts, range, UnlimitedWidthFinderFunc, NULL, offset, &ret);

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

    sizeOut->width = 0;
    sizeOut->height = 0;

    float y = frameSize.size.height; //[font ascender];
    CFIndex curIdx = 0;
    NSString* string = [frameSetter->_typesetter->_attributedString string];
    CFIndex stringRange = [string length];

    for (;;) {
        CFIndex pos = CTTypesetterSuggestLineBreakWithOffset((CTTypesetterRef)(_CTTypesetter*)frameSetter->_typesetter,
                                                             curIdx,
                                                             frameSize.size.width,
                                                             0.0f);
        if (pos == curIdx)
            break;

        CFRange lineRange;
        lineRange.location = curIdx;
        lineRange.length = pos - curIdx;

        CTLineRef line = CTTypesetterCreateLineWithOffset((CTTypesetterRef)(_CTTypesetter*)frameSetter->_typesetter, lineRange, 0.0f);

        float ascent = 0.0f, descent = 0.0f, leading = 0.0f;
        float width = CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
        float lineHeight = ascent - descent + leading;

        if (ret) {
            CGPoint lineOrigin;
            lineOrigin.x = 0.0f;
            lineOrigin.y = y - ascent;
            [ret->_lines addObject:(id)line];
            ret->_lineOrigins.push_back(lineOrigin);
        }
        [line release];

        curIdx = pos;
        if (width > sizeOut->width) {
            sizeOut->width = width;
        }

        sizeOut->height += lineHeight;

        y -= lineHeight;
    }

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
    NSString* str = [(NSAttributedString*)string string];
    NSRange lineRange;
    lineRange.location = 0;
    lineRange.length = [str length];

    _CTLine* line = [_CTLine new];
    line->_strRange = lineRange;

    return (CTLineRef)line;
}

/**
 @Status Stub
 @Notes Line is not truncated
*/
CTLineRef CTLineCreateTruncatedLine(CTLineRef line, double width, CTLineTruncationType truncationType, CTLineRef truncationToken) {
    UNIMPLEMENTED();
    NSRange lineRange = ((_CTLine*)line)->_strRange;

    _CTLine* ret = [_CTLine new];
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
        origins[idx] = ((_CTFrame*)frame)->_lineOrigins[i];
        idx++;
    }
}

void CTFrameDraw(CTFrameRef frame, CGContextRef ctx) {
    unsigned count = [((_CTFrame*)frame)->_lines count];
    CGPoint curTextPos;

    curTextPos = CGContextGetTextPosition(ctx);

    for (unsigned i = 0; i < count; i++) {
        _CTLine* curLine = [((_CTFrame*)frame)->_lines objectAtIndex:i];

        CGPoint newPos = curTextPos + ((_CTFrame*)frame)->_lineOrigins[i];
        CGContextSetTextPosition(ctx, newPos.x, newPos.y);
        CTLineDraw((CTLineRef)curLine, ctx);
    }
}

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

double CTLineGetTypographicBounds(CTLineRef lineRef, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    _CTLine* line = (_CTLine*)lineRef;
    if (ascent) {
        *ascent = line->_ascent;
    }
    if (descent) {
        *descent = line->_descent;
    }
    if (leading) {
        *leading = line->_leading;
    }

    return line->_width;
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

CFRange CTRunGetStringRange(CTRunRef run) {
    _CTRun* curRun = (_CTRun*)run;

    return curRun->_range;
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

void CTRunGetPositions(CTRunRef run, CFRange runRange, CGPoint* outPositions) {
    _CTRun* curRun = (_CTRun*)run;

    if (runRange.length == 0) {
        runRange.location = 0;
        runRange.length = curRun->_range.length;
    }

    memcpy(outPositions, &curRun->_glyphOrigins[runRange.location], sizeof(CGPoint) * runRange.length);
}

void CTRunGetAdvances(CTRunRef run, CFRange runRange, CGSize* outAdvances) {
    _CTRun* curRun = (_CTRun*)run;

    if (runRange.length == 0) {
        runRange.location = 0;
        runRange.length = curRun->_range.length;
    }

    memcpy(outAdvances, &curRun->_glyphAdvances[runRange.location], sizeof(CGSize) * runRange.length);
}

void CTRunDraw(CTRunRef run, CGContextRef ctx, CFRange textRange) {
    _CTRun* curRun = (_CTRun*)run;

    NSString* string = curRun->_stringFragment;

    NSRange range;
    range.location = textRange.location;
    range.length = textRange.length;

    if (range.length == 0) {
        range.location = 0;
        range.length = [string length];
    }

    int numGlyphs = curRun->_characters.size();
    WORD* glyphs = (WORD*)malloc(sizeof(WORD) * numGlyphs);

    id font = curRun->_font;
    CGFontGetGlyphsForUnichars(font, curRun->_characters.data(), glyphs, numGlyphs);
    CGContextSetFont(ctx, font);
    CGContextSetFontSize(ctx, [font pointSize]);

    CGContextSetFillColorWithColor(ctx, (CGColorRef)(id)curRun->_textColor);
    CGContextSetStrokeColorWithColor(ctx, (CGColorRef)(id)CGColorGetConstantColor((CFStringRef) @"WHITE"));

    CGPoint curTextPos;
    ctx->Backing()->CGContextGetTextPosition(&curTextPos);

    CGContextShowGlyphsAtPoint(ctx, curTextPos.x, curTextPos.y, glyphs, numGlyphs);
    free(glyphs);
}

void CTLineDraw(CTLineRef lineRef, CGContextRef ctx) {
    _CTLine* line = (_CTLine*)lineRef;

    CGPoint start;
    ctx->Backing()->CGContextGetTextPosition(&start);

    for (_CTRun* curRun in(NSArray*)line->_runs) {
        CFRange range = { 0 };

        CGPoint outputPoint = start;
        if (curRun->_glyphOrigins.size() > 0) {
            outputPoint = CGPointMake(start.x + curRun->_glyphOrigins[0].x, start.y + +curRun->_glyphOrigins[0].y);
        }
        ctx->Backing()->CGContextSetTextPosition(outputPoint.x, outputPoint.y);

        CTRunDraw((CTRunRef)curRun, ctx, range);
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

CTFontRef CTFontCreateWithGraphicsFont(CGFontRef cgFont, CGFloat size, const CGAffineTransform* xform, id attributes) {
    /**
     @Status Caveat
     @Notes transform and attributes parameters not supported
    */
    if (size == 0.0f)
        size = 12.0f;
    id ret = [[(UIFont*)cgFont fontWithSize:size] retain];
    return (CTFontRef)ret;
}

/**
 @Status Caveat
 @Notes orientation parameter not supported
*/
CTFontRef CTFontCreateWithName(CFStringRef name, CGFloat size, const CGAffineTransform* xform) {
    if (size == 0.0f)
        size = 12.0f;
    UIFont* ret = [[_LazyUIFont fontWithName:(NSString*)name size:size] retain];
    return (CTFontRef)ret;
}

double CTFontGetAdvancesForGlyphs(CTFontRef font, int orientation, const CGGlyph* glyphs, CGSize* advances, size_t count) {
    DWORD i;
    double total = 0.0f;

    _CGFontLock();
    //  Get the font
    FT_Face face = (FT_Face)[(UIFont*)font _sizingFontHandle];
    CGFontSetFTFontSize((CGFontRef)font, face, [(UIFont*)font pointSize]);

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
    return [(UIFont*)font ascender];
}

/**
 @Status Interoperable
*/
float CTFontGetDescent(CTFontRef font) {
    return [(UIFont*)font descender];
}

/**
 @Status Interoperable
*/
float CTFontGetSize(CTFontRef font) {
    float ret = [(UIFont*)font pointSize];

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
    return (CFStringRef)[[(UIFont*)font fontName] retain];
}

/**
 @Status Interoperable
*/
CFStringRef CTFontCopyFamilyName(CTFontRef font) {
    return (CFStringRef)[[(UIFont*)font fontName] retain];
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
    idretaintype(UITextPosition) _start, _end;
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
