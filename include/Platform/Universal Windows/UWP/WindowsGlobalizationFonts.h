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

// WindowsGlobalizationFonts.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGFLanguageFont, WGFLanguageFontGroup;
@protocol WGFILanguageFontGroup
, WGFILanguageFontGroupFactory, WGFILanguageFont;

#include "WindowsUIText.h"

#import <Foundation/Foundation.h>

// Windows.Globalization.Fonts.LanguageFont
#ifndef __WGFLanguageFont_DEFINED__
#define __WGFLanguageFont_DEFINED__

WINRT_EXPORT
@interface WGFLanguageFont : RTObject
@property (readonly) NSString* fontFamily;
@property (readonly) WUTFontStretch fontStretch;
@property (readonly) WUTFontStyle fontStyle;
@property (readonly) WUTFontWeight* fontWeight;
@property (readonly) double scaleFactor;
@end

#endif // __WGFLanguageFont_DEFINED__

// Windows.Globalization.Fonts.LanguageFontGroup
#ifndef __WGFLanguageFontGroup_DEFINED__
#define __WGFLanguageFontGroup_DEFINED__

WINRT_EXPORT
@interface WGFLanguageFontGroup : RTObject
+ (WGFLanguageFontGroup*)createLanguageFontGroup:(NSString*)languageTag ACTIVATOR;
@property (readonly) WGFLanguageFont* documentAlternate1Font;
@property (readonly) WGFLanguageFont* documentAlternate2Font;
@property (readonly) WGFLanguageFont* documentHeadingFont;
@property (readonly) WGFLanguageFont* fixedWidthTextFont;
@property (readonly) WGFLanguageFont* modernDocumentFont;
@property (readonly) WGFLanguageFont* traditionalDocumentFont;
@property (readonly) WGFLanguageFont* uICaptionFont;
@property (readonly) WGFLanguageFont* uIHeadingFont;
@property (readonly) WGFLanguageFont* uINotificationHeadingFont;
@property (readonly) WGFLanguageFont* uITextFont;
@property (readonly) WGFLanguageFont* uITitleFont;
@end

#endif // __WGFLanguageFontGroup_DEFINED__
