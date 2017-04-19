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

#import <CoreText/CTLine.h>
#import <StubReturn.h>
#import "CoreTextInternal.h"
#import "CGContextInternal.h"
#import "DWriteWrapper_CoreText.h"
#import <CoreText/CTTypesetter.h>
#import <CoreFoundation/CFString.h>

#include <memory>
#import <algorithm>
#import <numeric>
#import <cwchar>
#import <vector>

static CFStringRef __CTCreateReversedString(CFStringRef string) {
    if (string == nullptr) {
        return nullptr;
    }

    CFIndex length = CFStringGetLength(string);
    CFIndex usedBufLen;
    CFStringGetBytes(string, CFRangeMake(0, length), kCFStringEncodingUTF16, 0, false, nullptr, length, &usedBufLen);

    if (length < 2) {
        return CFStringCreateCopy(kCFAllocatorDefault, string);
    }

    CFIndex bufLen = (usedBufLen / sizeof(UniChar));
    std::unique_ptr<UniChar[]> characters(new UniChar[bufLen + 1]);
    characters[bufLen] = L'\0';

    CFStringGetBytes(
        string, CFRangeMake(0, length), kCFStringEncodingUTF16, 0, false, reinterpret_cast<UInt8*>(characters.get()), usedBufLen, nullptr);

    wchar_t* result = _wcsrev(reinterpret_cast<wchar_t*>(characters.get()));
    if (result == nullptr) {
        return nullptr;
    }

    return CFStringCreateWithCharactersNoCopy(kCFAllocatorDefault, characters.release(), bufLen, nullptr);
}

static NSMutableAttributedString* _getTruncatedStringFromSourceLine(CTLineRef line,
                                                                    CTLineTruncationType truncationType,
                                                                    double widthToExtract);

@implementation _CTLine : NSObject
- (instancetype)init {
    if (self = [super init]) {
        _runs.attach(CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks));
    }
    return self;
}

- (instancetype)copyWithZone:(NSZone*)zone {
    _CTLine* ret = [_CTLine new];
    ret->_strRange = _strRange;
    ret->_width = _width;
    ret->_ascent = _ascent;
    ret->_descent = _descent;
    ret->_leading = _leading;
    ret->_glyphCount = _glyphCount;
    ret->_runs.attach(CFArrayCreateMutableCopy(kCFAllocatorDefault, 0, _runs));
    ret->_relativeXOffset = _relativeXOffset;

    return ret;
}
@end

/**
 @Status Interoperable
*/
CTLineRef CTLineCreateWithAttributedString(CFAttributedStringRef string) {
    return string ? static_cast<CTLineRef>(_DWriteGetLine(string)) : nil;
}

/**
 @Status Interoperable
*/
CTLineRef CTLineCreateTruncatedLine(CTLineRef sourceLine, double width, CTLineTruncationType truncationType, CTLineRef truncationToken) {
    if (sourceLine == nil) {
        return nil;
    }

    // get the truncationToken width, use it to calculate the exact width that should be extracted from the sourceLine.
    CGFloat truncationTokenWidth;
    if (truncationToken == nil) {
        truncationTokenWidth = 0.0f;
    } else {
        truncationTokenWidth = (static_cast<_CTLine*>(truncationToken))->_width;
    }

    if (width <= 0 || truncationTokenWidth > width) {
        return nil;
    }

    CGFloat sourceLineWidth = static_cast<_CTLine*>(sourceLine)->_width;
    if (width >= sourceLineWidth || sourceLineWidth == truncationTokenWidth) {
        // return a copy of sourceLine
        return static_cast<CTLineRef>([static_cast<_CTLine*>(sourceLine) copy]);
    }

    // widthToExtract is the width that will be extracted from the sourceLine and merged with truncationToken finally
    double widthToExtract;
    if (truncationToken == nil) {
        widthToExtract = width;
    } else {
        widthToExtract = width - truncationTokenWidth;
    }

    // get an NSAttributed string from truncationToken by looping across its runs and extracting the run attribuets.
    NSMutableAttributedString* stringFromToken = [NSMutableAttributedString new];
    CFArrayRef tokenRuns = CTLineGetGlyphRuns(truncationToken);
    if (tokenRuns != nil) {
        CFIndex numberOfRuns = CFArrayGetCount(tokenRuns);
        for (int i = 0; i < numberOfRuns; ++i) {
            CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(tokenRuns, i));
            CFDictionaryRef attribs = CTRunGetAttributes(run);
            NSAttributedString* string = [[NSAttributedString alloc] initWithString:static_cast<NSString*>(run->_stringFragment.get())
                                                                         attributes:(NSDictionary*)attribs];
            [stringFromToken appendAttributedString:string];
            [string release];
        }
    }

    NSMutableAttributedString* finalString = nil;
    NSMutableAttributedString* truncatedStringFromLeft = nil;
    NSMutableAttributedString* truncatedStringFromRight = nil;

    switch (truncationType) {
        case kCTLineTruncationStart:
            truncatedStringFromRight = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationStart, widthToExtract);
            [stringFromToken appendAttributedString:truncatedStringFromRight];
            finalString = stringFromToken;

            break;
        case kCTLineTruncationMiddle:
            widthToExtract = widthToExtract / 2;
            truncatedStringFromLeft = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationEnd, widthToExtract);
            truncatedStringFromRight = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationStart, widthToExtract);
            [truncatedStringFromLeft appendAttributedString:stringFromToken];
            [truncatedStringFromLeft appendAttributedString:truncatedStringFromRight];
            finalString = truncatedStringFromLeft;

            break;
        case kCTLineTruncationEnd:
            truncatedStringFromLeft = _getTruncatedStringFromSourceLine(sourceLine, kCTLineTruncationEnd, widthToExtract);
            [truncatedStringFromLeft appendAttributedString:stringFromToken];
            finalString = truncatedStringFromLeft;

            break;
        default:
            return nil;
    }

    CTLineRef ret = CTLineCreateWithAttributedString(static_cast<CFAttributedStringRef>(finalString));
    [stringFromToken release];

    return ret;
}

static NSMutableAttributedString* _getTruncatedStringFromSourceLine(CTLineRef sourceLine,
                                                                    CTLineTruncationType truncationType,
                                                                    double widthToExtract) {
    NSMutableAttributedString* ret = [NSMutableAttributedString new];
    CFArrayRef glyphRuns = CTLineGetGlyphRuns(sourceLine);
    CFIndex numberOfRuns = CFArrayGetCount(glyphRuns);
    double extractedWidth = 0;
    bool done = 0;

    for (int i = 0; i < numberOfRuns; ++i) {
        int runIndex;
        if (truncationType == kCTLineTruncationStart) {
            runIndex = numberOfRuns - i - 1;
        } else if (truncationType == kCTLineTruncationEnd) {
            runIndex = i;
        }

        CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(glyphRuns, runIndex));
        NSMutableString* runString = [NSMutableString new];

        int numberOfGlyphs = run->_dwriteGlyphRun.glyphCount;
        for (int j = 0; j < numberOfGlyphs; ++j) {
            int glyphIndex;
            if (truncationType == kCTLineTruncationStart) {
                glyphIndex = numberOfGlyphs - j - 1;
            } else if (truncationType == kCTLineTruncationEnd) {
                glyphIndex = j;
            }

            if (extractedWidth + run->_dwriteGlyphRun.glyphAdvances[glyphIndex] > widthToExtract) {
                done = 1;
                break;
            }

            extractedWidth += run->_dwriteGlyphRun.glyphAdvances[glyphIndex];
            char glyph = CFStringGetCharacterAtIndex(run->_stringFragment, glyphIndex);
            [runString appendString:[NSString stringWithFormat:@"%c", glyph]];
        }

        CFDictionaryRef attribs = CTRunGetAttributes(run);

        if (truncationType == kCTLineTruncationStart) {
            auto reverse = woc::MakeStrongCF<CFStringRef>(__CTCreateReversedString(static_cast<CFStringRef>(runString)));
            NSAttributedString* string =
                [[NSAttributedString alloc] initWithString:static_cast<NSString*>(reverse.get()) attributes:(NSDictionary*)attribs];
            [ret insertAttributedString:string atIndex:0];
            [string release];
        } else if (truncationType == kCTLineTruncationEnd) {
            NSAttributedString* string = [[NSAttributedString alloc] initWithString:runString attributes:(NSDictionary*)attribs];
            [ret appendAttributedString:string];
            [string release];
        }
        [runString release];
        if (done) {
            break;
        }
    }

    return [ret autorelease];
}

/**
 @Status NotInPlan
 @Notes This would be hard to get right for justfication factors (0, 1).
*/

CTLineRef CTLineCreateJustifiedLine(CTLineRef line, CGFloat justificationFactor, double justificationWidth) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CTLineDraw(CTLineRef lineRef, CGContextRef ctx) {
    if (lineRef == nil || ctx == nil) {
        return;
    }

    _CTLine* line = static_cast<_CTLine*>(lineRef);
    std::vector<GlyphRunData> runs;

    // Translate by the inverse of the relativeXOffset to draw at the text position
    CGPoint relativePosition = { -line->_relativeXOffset, 0 };
    CFIndex count = CFArrayGetCount(line->_runs);
    for (CFIndex i = 0; i < count; ++i) {
        __CTRun* curRun = const_cast<__CTRun*>(static_cast<CTRunRef>(CFArrayGetValueAtIndex(line->_runs, i)));
        // Adjusts x position relative to the last run drawn
        relativePosition.x += curRun->_relativeXOffset;
        runs.emplace_back(GlyphRunData{ &curRun->_dwriteGlyphRun, relativePosition, curRun->_attributes });
    }

    if (!runs.empty()) {
        _CGContextPushBeginDraw(ctx);
        auto popEnd = wil::ScopeExit([ctx]() { _CGContextPopEndDraw(ctx); });
        _CGContextDrawGlyphRuns(ctx, runs.data(), runs.size());
    }
}

/**
 @Status Interoperable
*/
CFIndex CTLineGetGlyphCount(CTLineRef line) {
    return line ? static_cast<_CTLine*>(line)->_glyphCount : 0;
}

/**
 @Status Interoperable
*/
CFArrayRef CTLineGetGlyphRuns(CTLineRef line) {
    return line ? static_cast<CFArrayRef>(static_cast<_CTLine*>(line)->_runs.get()) : nil;
}

/**
 @Status Interoperable
*/
CFRange CTLineGetStringRange(CTLineRef line) {
    return line ? static_cast<_CTLine*>(line)->_strRange : CFRangeMake(0, 0);
}

/**
 @Status Caveat
 @Notes Returns 0.0
*/
double CTLineGetPenOffsetForFlush(CTLineRef line, CGFloat flushFactor, double flushWidth) {
    UNIMPLEMENTED();
    return 0.0;
}

/**
 @Status Interoperable
 @Notes
*/
CGRect CTLineGetImageBounds(CTLineRef line, CGContextRef context) {
    if (!line || !context) {
        return CGRectNull;
    }

    CGFloat ascent, descent;
    double width = CTLineGetTypographicBounds(line, &ascent, &descent, nullptr);
    return { CGContextGetTextPosition(context), { width, ascent - descent } };
}

/**
 @Status Interoperable
*/
double CTLineGetTypographicBounds(CTLineRef lineRef, CGFloat* ascent, CGFloat* descent, CGFloat* leading) {
    _CTLine* line = static_cast<_CTLine*>(lineRef);

    RETURN_RESULT_IF((!line) || (CFArrayGetCount(line->_runs) == 0), 0);

    // Created with impossible values -FLT_MAX which signify they need to be populated
    if ((line->_ascent == -FLT_MAX || line->_descent == -FLT_MAX || line->_leading == -FLT_MAX) && (ascent || descent || leading)) {
        CFIndex count = CFArrayGetCount(line->_runs);
        for (CFIndex i = 0; i < count; ++i) {
            CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(line->_runs, i));
            CGFloat newAscent, newDescent, newLeading;
            CTRunGetTypographicBounds(run, { 0, 0 }, &newAscent, &newDescent, &newLeading);
            line->_ascent = std::max(line->_ascent, newAscent);
            line->_descent = std::max(line->_descent, newDescent);
            line->_leading = std::max(line->_leading, newLeading);
        }
    }

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
 @Notes
*/
double CTLineGetTrailingWhitespaceWidth(CTLineRef line) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CFIndex CTLineGetStringIndexForPosition(CTLineRef lineRef, CGPoint position) {
    _CTLine* line = static_cast<_CTLine*>(lineRef);
    if (!line || line->_glyphCount == 0) {
        return kCFNotFound;
    }

    CGFloat curPos = 0;
    CFIndex count = CFArrayGetCount(line->_runs);
    for (CFIndex i = 0; i < count; ++i) {
        CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(line->_runs, i));
        curPos += run->_relativeXOffset;
        CGFloat runPos = curPos;
        for (int i = 0; i < run->_dwriteGlyphRun.glyphCount; i++) {
            if (_GlyphRunIsRTL(run->_dwriteGlyphRun)) {
                if (runPos <= position.x) {
                    return run->_stringIndices[i];
                }

                runPos -= run->_dwriteGlyphRun.glyphAdvances[i];
            } else {
                runPos += run->_dwriteGlyphRun.glyphAdvances[i];
                if (runPos >= position.x) {
                    return run->_stringIndices[i];
                }
            }
        }
    }

    return line->_strRange.location + line->_strRange.length;
}

/**
 @Status Interoperable
*/
CGFloat CTLineGetOffsetForStringIndex(CTLineRef lineRef, CFIndex charIndex, CGFloat* secondaryOffset) {
    CGFloat ret = 0.0;
    if (lineRef && charIndex >= 0) {
        _CTLine* line = static_cast<_CTLine*>(lineRef);
        if (charIndex > line->_strRange.location + line->_strRange.length) {
            ret = line->_width;
        } else {
            CFIndex count = CFArrayGetCount(line->_runs);
            for (CFIndex i = 0; i < count; ++i) {
                CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(line->_runs, i));
                if (run->_range.location + run->_range.length >= charIndex && run->_stringIndices.size() > 0) {
                    int index = std::upper_bound(run->_stringIndices.begin(), run->_stringIndices.end(), charIndex) -
                                run->_stringIndices.begin() - 1;

                    if (index >= 0) {
                        if (_GlyphRunIsRTL(run->_dwriteGlyphRun)) {
                            ret += std::accumulate(run->_dwriteGlyphRun.glyphAdvances,
                                                   run->_dwriteGlyphRun.glyphAdvances + index,
                                                   run->_relativeXOffset,
                                                   std::minus<CGFloat>());
                        } else {
                            ret += std::accumulate(run->_dwriteGlyphRun.glyphAdvances,
                                                   run->_dwriteGlyphRun.glyphAdvances + index,
                                                   run->_relativeXOffset);
                        }
                    }

                    break;
                }

                ret += run->_relativeXOffset;
            }
        }
    }

    if (secondaryOffset) {
        *secondaryOffset = ret;
    }
    return ret;
}

/**
 @Status NotInPlan
 @Notes This API is mostly un-documented and appears to be very low usage.
*/

CGRect CTLineGetBoundsWithOptions(CTLineRef line, CTLineBoundsOptions options) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status NotInPlan
 @Notes this would require us to move to using bridged type implementation, seems of little value at this point
*/
CFTypeID CTLineGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}
