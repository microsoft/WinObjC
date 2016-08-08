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

#import <CoreText/CTTypesetter.h>
#import <StubReturn.h>

#import "CoreTextInternal.h"
#import "CGFontInternal.h"
#import "UIFontInternal.h"

#import <Foundation/NSAttributedString.h>

#include <algorithm>

extern "C" {
#include <ft2build.h>
#include FT_FREETYPE_H
#include <ftglyph.h>
#include <tttables.h>
#include <ftadvanc.h>
#include <ftsizes.h>
#include <ftsnames.h>
#include <ttnameid.h>
}

#include "LoggingNative.h"

static const wchar_t* TAG = L"CTTypesetter";

const CFStringRef kCTTypesetterOptionDisableBidiProcessing = static_cast<CFStringRef>(@"kCTTypesetterOptionDisableBidiProcessing");
const CFStringRef kCTTypesetterOptionForcedEmbeddingLevel = static_cast<CFStringRef>(@"kCTTypesetterOptionForcedEmbeddingLevel");

static IWLazyClassLookup _LazyUIFont("UIFont");

static const float c_spacing = 1.0f;
static const float default_system_font_size = 15.0f;

@implementation _CTTypesetter
- (instancetype)initWithAttributedString:(NSAttributedString*)str {
    _attributedString = [str retain];
    _string = [[str string] retain];

    //  Measure the string
    _charactersLen = [_string length];
    _characters = (WORD*)IwMalloc(sizeof(WORD) * _charactersLen);
    [_string getCharacters:_characters];

    return self;
}

- (void)dealloc {
    if (_characters) {
        IwFree(_characters);
    }
    [_string release];
    [_attributedString release];
    [super dealloc];
}
@end

static CFIndex _DoWrap(CTTypesetterRef ts, CFRange range, WidthFinderFunc widthFunc, void* widthParam, double offset, CTLineRef* outLine) {
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
    int lastGlyphToPrintPos = -1;

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
                --curIndex;
            }

            if (curIndex > lineStart && chars[curIndex - 1] == ' ') {
                // Ending line with trailing spaces, only want width up to last printable glyph
                lineWidth = ((float)lastPossibleBreakWidth) / 64.0f;
            } else {
                // No trailing spaces, so we print everything with the current width
                lastGlyphToPrintPos = curIndex - 1;
                lineWidth = ((float)penX) / 64.0f;
            }

            //  We have hit a hard linebreak, consume it
            ++curIndex;

            //  Do a hard line break
            hitLinebreak = true;
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
            if (font == nil) {
                font = [_LazyUIFont systemFontOfSize:default_system_font_size];
            }
            curFace = (FT_Face)[font _sizingFontHandle];
            CGFontSetFTFontSize(font, curFace, [font pointSize]);

            float fontHeight = ((float)(curFace->size->metrics.ascender - curFace->size->metrics.descender)) * c_spacing / 64.0f;
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
                TraceWarning(TAG, L"Glyph %d not found", curChar);
            }

            if (curChar == ' ') {
                //  Soft linebreak possibility
                lastPossibleBreakPos = curIndex;
                if (curIndex > lineStart && chars[curIndex - 1] != ' ') {
                    lastGlyphToPrintPos = curIndex - 1;
                    lastPossibleBreakWidth = penX;
                }
            }
            penX += advance.x;

            glyphAdvance.width = ((float)advance.x) / 64.0f;
        }

        float curWidth;

        if ((penX / 64.0f) > maxWidth && curChar != ' ') {
            if (lastPossibleBreakPos != -1) {
                //  We must now perform a soft break
                curIndex = lastPossibleBreakPos + 1;
                lineWidth = ((float)lastPossibleBreakWidth) / 64.0f;
            } else {
                if (lineStart != curIndex) {
                    //  Back out the last character
                    penX -= advance.x;
                    lastGlyphToPrintPos = curIndex - 1;
                } else {
                    lastGlyphToPrintPos = curIndex;
                }
                lineWidth = ((float)penX) / 64.0f;
            }

            //  Do a hard line break
            hitLinebreak = true;
            break;
        }

        ++curIndex;
    }

    if (curIndex >= count && !hitLinebreak) {
        // Ran out of characters to print before establishing width
        if (chars[count - 1] == ' ') {
            // Ending line with trailing spaces, only want width up to last printable glyph
            lineWidth = ((float)lastPossibleBreakWidth) / 64.0f;
        } else {
            // No trailing spaces, so we print everything with the current width
            lineWidth = ((float)penX) / 64.0f;
            lastGlyphToPrintPos = count - 1;
        }
    }
    if (line) {
        if (lastGlyphToPrintPos != curIndex && lastGlyphToPrintPos >= 0) {
            // Remove any trailing whitespace
            glyphOrigins.erase(glyphOrigins.begin() + (lastGlyphToPrintPos - lineStart + 1), glyphOrigins.end());
            glyphAdvances.erase(glyphAdvances.begin() + (lastGlyphToPrintPos - lineStart + 1), glyphAdvances.end());
            characters.erase(characters.begin() + (lastGlyphToPrintPos - lineStart + 1), characters.end());
        }

        NSRange lineRange = NSMakeRange(lineStart, lastGlyphToPrintPos - lineStart + 1);
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

            _CTRun* run = [[_CTRun alloc] init];
            UIFont* runFont = [attribs objectForKey:(id)kCTFontAttributeName];
            if (runFont == nil) {
                runFont = [_LazyUIFont systemFontOfSize:15];
            }
            [run->_attributes setObject:runFont forKey:(id)kCTFontAttributeName];

            if ([runFont ascender] > ascender) {
                ascender = [runFont ascender];
            }
            if ([runFont descender] < descender) {
                descender = [runFont descender];
            }
            if ([runFont leading] > leading) {
                leading = [runFont leading];
            }

            // adding all the other attributes
            NSEnumerator* enumerator = [attribs keyEnumerator];
            id key;
            while ((key = [enumerator nextObject])) {
                if ([run->_attributes valueForKey:key] == nil) {
                    [run->_attributes setObject:[attribs objectForKey:key] forKey:key];
                }
            }

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

/**
@Status Interoperable
*/
CTTypesetterRef CTTypesetterCreateWithAttributedString(CFAttributedStringRef string) {
    _CTTypesetter* ret = [[_CTTypesetter alloc] initWithAttributedString:(NSAttributedString*)string];
    return (CTTypesetterRef)ret;
}

/**
 @Status Stub
 @Notes
*/
CTTypesetterRef CTTypesetterCreateWithAttributedStringAndOptions(CFAttributedStringRef string, CFDictionaryRef options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CTLineRef CTTypesetterCreateLine(CTTypesetterRef typesetter, CFRange stringRange) {
    return CTTypesetterCreateLineWithOffset(typesetter, stringRange, 0.0f);
}

/**
 @Status Interoperable
 @Notes
*/
CTLineRef CTTypesetterCreateLineWithOffset(CTTypesetterRef ts, CFRange range, double offset) {
    CTLineRef ret = NULL;

    _DoWrap(ts, range, UnlimitedWidthFinderFunc, NULL, offset, &ret);

    return ret;
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTTypesetterSuggestLineBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width) {
    return CTTypesetterSuggestLineBreakWithOffset(typesetter, startIndex, width, 0.0f);
}

// Private/exported function
CFIndex _CTTypesetterSuggestLineBreakWithOffsetAndCallback(
    CTTypesetterRef ts, CFIndex index, double offset, WidthFinderFunc callback, void* opaque) {
    return _DoWrap(ts, CFRangeMake(index, -1), callback, opaque, offset, NULL);
}

/**
 @Status Interoperable
 @Notes
*/
CFIndex CTTypesetterSuggestLineBreakWithOffset(CTTypesetterRef ts, CFIndex index, double width, double offset) {
    return _CTTypesetterSuggestLineBreakWithOffsetAndCallback(ts, index, offset, FixedWidthFinderFunc, &width);
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTTypesetterSuggestClusterBreak(CTTypesetterRef typesetter, CFIndex startIndex, double width) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFIndex CTTypesetterSuggestClusterBreakWithOffset(CTTypesetterRef typesetter, CFIndex startIndex, double width, double offset) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CTTypesetterGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
