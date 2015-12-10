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

#ifndef _CTSTRINGATTRIBUTES_H_
#define _CTSTRINGATTRIBUTES_H_

#import <StarboardExport.h>
#import <CoreFoundation/CFString.h>

enum {
    kCTUnderlineStyleNone = 0x00,
    kCTUnderlineStyleSingle = 0x01,
    kCTUnderlineStyleThick = 0x02,
    kCTUnderlineStyleDouble = 0x09,
};
typedef int32_t CTUnderlineStyle;

enum {
    kCTUnderlinePatternSolid = 0x0000,
    kCTUnderlinePatternDot = 0x0100,
    kCTUnderlinePatternDash = 0x0200,
    kCTUnderlinePatternDashDot = 0x0300,
    kCTUnderlinePatternDashDotDot = 0x0400
};
typedef int32_t CTUnderlineStyleModifiers;

CORETEXT_EXPORT const CFStringRef kCTCharacterShapeAttributeName;
CORETEXT_EXPORT const CFStringRef kCTFontAttributeName;
CORETEXT_EXPORT const CFStringRef kCTKernAttributeName;
CORETEXT_EXPORT const CFStringRef kCTLigatureAttributeName;
CORETEXT_EXPORT const CFStringRef kCTForegroundColorAttributeName;
CORETEXT_EXPORT const CFStringRef kCTForegroundColorFromContextAttributeName;
CORETEXT_EXPORT const CFStringRef kCTParagraphStyleAttributeName;
CORETEXT_EXPORT const CFStringRef kCTStrokeWidthAttributeName;
CORETEXT_EXPORT const CFStringRef kCTStrokeColorAttributeName;
CORETEXT_EXPORT const CFStringRef kCTSuperscriptAttributeName;
CORETEXT_EXPORT const CFStringRef kCTUnderlineColorAttributeName;
CORETEXT_EXPORT const CFStringRef kCTUnderlineStyleAttributeName;
CORETEXT_EXPORT const CFStringRef kCTVerticalFormsAttributeName;
CORETEXT_EXPORT const CFStringRef kCTGlyphInfoAttributeName;
CORETEXT_EXPORT const CFStringRef kCTRunDelegateAttributeName;

#endif /* _CTSTRINGATTRIBUTES_H_ */