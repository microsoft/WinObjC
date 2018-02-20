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

// WindowsGlobalizationFonts.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGLOBALIZATIONFONTSEXPORT
#define OBJCUWPWINDOWSGLOBALIZATIONFONTSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGlobalizationFonts.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGFLanguageFont, WGFLanguageFontGroup;
@protocol WGFILanguageFontGroup, WGFILanguageFontGroupFactory, WGFILanguageFont;

#include "WindowsUIText.h"

#import <Foundation/Foundation.h>

// Windows.Globalization.Fonts.LanguageFont
#ifndef __WGFLanguageFont_DEFINED__
#define __WGFLanguageFont_DEFINED__

OBJCUWPWINDOWSGLOBALIZATIONFONTSEXPORT
@interface WGFLanguageFont : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * fontFamily;
@property (readonly) WUTFontStretch fontStretch;
@property (readonly) WUTFontStyle fontStyle;
@property (readonly) WUTFontWeight* fontWeight;
@property (readonly) double scaleFactor;
@end

#endif // __WGFLanguageFont_DEFINED__

// Windows.Globalization.Fonts.LanguageFontGroup
#ifndef __WGFLanguageFontGroup_DEFINED__
#define __WGFLanguageFontGroup_DEFINED__

OBJCUWPWINDOWSGLOBALIZATIONFONTSEXPORT
@interface WGFLanguageFontGroup : RTObject
+ (WGFLanguageFontGroup*)makeLanguageFontGroup:(NSString *)languageTag ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
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

