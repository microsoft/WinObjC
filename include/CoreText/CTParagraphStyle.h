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

#ifndef _CTPARAGRAPHSTYLE_H_
#define _CTPARAGRAPHSTYLE_H_

#import "CoreTextExport.h"
#import <CoreFoundation/CFBase.h>

typedef struct __CTParagraphStyle* CTParagraphStyleRef;

enum {
    kCTParagraphStyleSpecifierAlignment = 0,
    kCTParagraphStyleSpecifierFirstLineHeadIndent = 1,
    kCTParagraphStyleSpecifierHeadIndent = 2,
    kCTParagraphStyleSpecifierTailIndent = 3,
    kCTParagraphStyleSpecifierTabStops = 4,
    kCTParagraphStyleSpecifierDefaultTabInterval = 5,
    kCTParagraphStyleSpecifierLineBreakMode = 6,
    kCTParagraphStyleSpecifierLineHeightMultiple = 7,
    kCTParagraphStyleSpecifierMaximumLineHeight = 8,
    kCTParagraphStyleSpecifierMinimumLineHeight = 9,
    kCTParagraphStyleSpecifierLineSpacing = 10,
    kCTParagraphStyleSpecifierParagraphSpacing = 11,
    kCTParagraphStyleSpecifierParagraphSpacingBefore = 12,
    kCTParagraphStyleSpecifierBaseWritingDirection = 13,
    kCTParagraphStyleSpecifierMaximumLineSpacing = 14,
    kCTParagraphStyleSpecifierMinimumLineSpacing = 15,
    kCTParagraphStyleSpecifierLineSpacingAdjustment = 16,
    kCTParagraphStyleSpecifierCount = 17
};
typedef uint32_t CTParagraphStyleSpecifier;

typedef struct CTParagraphStyleSetting {
    CTParagraphStyleSpecifier spec;
    size_t valueSize;
    const void* value;
} CTParagraphStyleSetting;

enum {
    kCTLeftTextAlignment = 0,
    kCTRightTextAlignment = 1,
    kCTCenterTextAlignment = 2,
    kCTJustifiedTextAlignment = 3,
    kCTNaturalTextAlignment = 4
};
typedef uint32_t CTTextAlignment;

enum {
    kCTLineBreakByWordWrapping = 0,
    kCTLineBreakByCharWrapping = 1,
    kCTLineBreakByClipping = 2,
    kCTLineBreakByTruncatingHead = 3,
    kCTLineBreakByTruncatingTail = 4,
    kCTLineBreakByTruncatingMiddle = 5
};
typedef uint32_t CTLineBreakMode;

enum {
    kCTWritingDirectionNatural = -1,
    kCTWritingDirectionLeftToRight = 0,
    kCTWritingDirectionRightToLeft = 1,
};
typedef int8_t CTWritingDirection;

CORETEXT_EXPORT CTParagraphStyleRef CTParagraphStyleCreate(const CTParagraphStyleSetting* settings, CFIndex settingCount);
CORETEXT_EXPORT bool CTParagraphStyleGetValueForSpecifier(CTParagraphStyleRef paragraphStyle,
                                                          CTParagraphStyleSpecifier spec,
                                                          size_t valueBufferSize,
                                                          void* valueBuffer);

#endif /* _CTPARAGRAPHSTYLE_H_ */