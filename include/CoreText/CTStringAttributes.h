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

SB_EXPORT const CFStringRef kCTCharacterShapeAttributeName;
SB_EXPORT const CFStringRef kCTFontAttributeName;
SB_EXPORT const CFStringRef kCTKernAttributeName;
SB_EXPORT const CFStringRef kCTLigatureAttributeName;
SB_EXPORT const CFStringRef kCTForegroundColorAttributeName;
SB_EXPORT const CFStringRef kCTForegroundColorFromContextAttributeName;
SB_EXPORT const CFStringRef kCTParagraphStyleAttributeName;
SB_EXPORT const CFStringRef kCTStrokeWidthAttributeName;
SB_EXPORT const CFStringRef kCTStrokeColorAttributeName;
SB_EXPORT const CFStringRef kCTSuperscriptAttributeName;
SB_EXPORT const CFStringRef kCTUnderlineColorAttributeName;
SB_EXPORT const CFStringRef kCTUnderlineStyleAttributeName;
SB_EXPORT const CFStringRef kCTVerticalFormsAttributeName;
SB_EXPORT const CFStringRef kCTGlyphInfoAttributeName;
SB_EXPORT const CFStringRef kCTRunDelegateAttributeName;

#endif /* _CTSTRINGATTRIBUTES_H_ */