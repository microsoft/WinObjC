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

#ifndef _CTFONTTRAITS_H_
#define _CTFONTTRAITS_H_

#import <StarboardExport.h>
#import <CoreFoundation/CFString.h>

enum {
    kCTFontClassMaskShift = 28,
};

enum {
    kCTFontItalicTrait = (1 << 0),
    kCTFontBoldTrait = (1 << 1),
    kCTFontExpandedTrait = (1 << 5),
    kCTFontCondensedTrait = (1 << 6),
    kCTFontMonoSpaceTrait = (1 << 10),
    kCTFontVerticalTrait = (1 << 11),
    kCTFontUIOptimizedTrait = (1 << 12),
    kCTFontClassMaskTrait = (15 << kCTFontClassMaskShift),

    kCTFontTraitItalic = kCTFontItalicTrait,
    kCTFontTraitBold = kCTFontBoldTrait,
    kCTFontTraitExpanded = kCTFontExpandedTrait,
    kCTFontTraitCondensed = kCTFontCondensedTrait,
    kCTFontTraitMonoSpace = kCTFontMonoSpaceTrait,
    kCTFontTraitVertical = kCTFontVerticalTrait,
    kCTFontTraitUIOptimized = kCTFontUIOptimizedTrait,
    kCTFontTraitClassMask = kCTFontClassMaskTrait,
};
typedef uint32_t CTFontSymbolicTraits;

SB_EXPORT const CFStringRef kCTFontSymbolicTrait;
SB_EXPORT const CFStringRef kCTFontWeightTrait;
SB_EXPORT const CFStringRef kCTFontWidthTrait;
SB_EXPORT const CFStringRef kCTFontSlantTrait;

#endif /* _CTFONTTRAITS_H_ */