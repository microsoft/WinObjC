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

// WindowsUIText.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUTTextConstants, WUTFontWeights;
@class WUTFontWeight;
@protocol WUTITextConstantsStatics
, WUTITextDocument, WUTITextRange, WUTITextSelection, WUTITextCharacterFormat, WUTITextParagraphFormat, WUTIFontWeights,
    WUTIFontWeightsStatics;

// Windows.UI.Text.CaretType
enum _WUTCaretType {
    WUTCaretTypeNormal = 0,
    WUTCaretTypeNull = 1,
};
typedef unsigned WUTCaretType;

// Windows.UI.Text.FindOptions
enum _WUTFindOptions {
    WUTFindOptionsNone = 0,
    WUTFindOptionsWord = 2,
    WUTFindOptionsCase = 4,
};
typedef unsigned WUTFindOptions;

// Windows.UI.Text.FormatEffect
enum _WUTFormatEffect {
    WUTFormatEffectOff = 0,
    WUTFormatEffectOn = 1,
    WUTFormatEffectToggle = 2,
    WUTFormatEffectUndefined = 3,
};
typedef unsigned WUTFormatEffect;

// Windows.UI.Text.HorizontalCharacterAlignment
enum _WUTHorizontalCharacterAlignment {
    WUTHorizontalCharacterAlignmentLeft = 0,
    WUTHorizontalCharacterAlignmentRight = 1,
    WUTHorizontalCharacterAlignmentCenter = 2,
};
typedef unsigned WUTHorizontalCharacterAlignment;

// Windows.UI.Text.LetterCase
enum _WUTLetterCase {
    WUTLetterCaseLower = 0,
    WUTLetterCaseUpper = 1,
};
typedef unsigned WUTLetterCase;

// Windows.UI.Text.LineSpacingRule
enum _WUTLineSpacingRule {
    WUTLineSpacingRuleUndefined = 0,
    WUTLineSpacingRuleSingle = 1,
    WUTLineSpacingRuleOneAndHalf = 2,
    WUTLineSpacingRuleDouble = 3,
    WUTLineSpacingRuleAtLeast = 4,
    WUTLineSpacingRuleExactly = 5,
    WUTLineSpacingRuleMultiple = 6,
    WUTLineSpacingRulePercent = 7,
};
typedef unsigned WUTLineSpacingRule;

// Windows.UI.Text.LinkType
enum _WUTLinkType {
    WUTLinkTypeUndefined = 0,
    WUTLinkTypeNotALink = 1,
    WUTLinkTypeClientLink = 2,
    WUTLinkTypeFriendlyLinkName = 3,
    WUTLinkTypeFriendlyLinkAddress = 4,
    WUTLinkTypeAutoLink = 5,
    WUTLinkTypeAutoLinkEmail = 6,
    WUTLinkTypeAutoLinkPhone = 7,
    WUTLinkTypeAutoLinkPath = 8,
};
typedef unsigned WUTLinkType;

// Windows.UI.Text.MarkerAlignment
enum _WUTMarkerAlignment {
    WUTMarkerAlignmentUndefined = 0,
    WUTMarkerAlignmentLeft = 1,
    WUTMarkerAlignmentCenter = 2,
    WUTMarkerAlignmentRight = 3,
};
typedef unsigned WUTMarkerAlignment;

// Windows.UI.Text.MarkerStyle
enum _WUTMarkerStyle {
    WUTMarkerStyleUndefined = 0,
    WUTMarkerStyleParenthesis = 1,
    WUTMarkerStyleParentheses = 2,
    WUTMarkerStylePeriod = 3,
    WUTMarkerStylePlain = 4,
    WUTMarkerStyleMinus = 5,
    WUTMarkerStyleNoNumber = 6,
};
typedef unsigned WUTMarkerStyle;

// Windows.UI.Text.MarkerType
enum _WUTMarkerType {
    WUTMarkerTypeUndefined = 0,
    WUTMarkerTypeNone = 1,
    WUTMarkerTypeBullet = 2,
    WUTMarkerTypeArabic = 3,
    WUTMarkerTypeLowercaseEnglishLetter = 4,
    WUTMarkerTypeUppercaseEnglishLetter = 5,
    WUTMarkerTypeLowercaseRoman = 6,
    WUTMarkerTypeUppercaseRoman = 7,
    WUTMarkerTypeUnicodeSequence = 8,
    WUTMarkerTypeCircledNumber = 9,
    WUTMarkerTypeBlackCircleWingding = 10,
    WUTMarkerTypeWhiteCircleWingding = 11,
    WUTMarkerTypeArabicWide = 12,
    WUTMarkerTypeSimplifiedChinese = 13,
    WUTMarkerTypeTraditionalChinese = 14,
    WUTMarkerTypeJapanSimplifiedChinese = 15,
    WUTMarkerTypeJapanKorea = 16,
    WUTMarkerTypeArabicDictionary = 17,
    WUTMarkerTypeArabicAbjad = 18,
    WUTMarkerTypeHebrew = 19,
    WUTMarkerTypeThaiAlphabetic = 20,
    WUTMarkerTypeThaiNumeric = 21,
    WUTMarkerTypeDevanagariVowel = 22,
    WUTMarkerTypeDevanagariConsonant = 23,
    WUTMarkerTypeDevanagariNumeric = 24,
};
typedef unsigned WUTMarkerType;

// Windows.UI.Text.ParagraphAlignment
enum _WUTParagraphAlignment {
    WUTParagraphAlignmentUndefined = 0,
    WUTParagraphAlignmentLeft = 1,
    WUTParagraphAlignmentCenter = 2,
    WUTParagraphAlignmentRight = 3,
    WUTParagraphAlignmentJustify = 4,
};
typedef unsigned WUTParagraphAlignment;

// Windows.UI.Text.ParagraphStyle
enum _WUTParagraphStyle {
    WUTParagraphStyleUndefined = 0,
    WUTParagraphStyleNone = 1,
    WUTParagraphStyleNormal = 2,
    WUTParagraphStyleHeading1 = 3,
    WUTParagraphStyleHeading2 = 4,
    WUTParagraphStyleHeading3 = 5,
    WUTParagraphStyleHeading4 = 6,
    WUTParagraphStyleHeading5 = 7,
    WUTParagraphStyleHeading6 = 8,
    WUTParagraphStyleHeading7 = 9,
    WUTParagraphStyleHeading8 = 10,
    WUTParagraphStyleHeading9 = 11,
};
typedef unsigned WUTParagraphStyle;

// Windows.UI.Text.PointOptions
enum _WUTPointOptions {
    WUTPointOptionsNone = 0,
    WUTPointOptionsIncludeInset = 1,
    WUTPointOptionsStart = 32,
    WUTPointOptionsClientCoordinates = 256,
    WUTPointOptionsAllowOffClient = 512,
    WUTPointOptionsTransform = 1024,
    WUTPointOptionsNoHorizontalScroll = 65536,
    WUTPointOptionsNoVerticalScroll = 262144,
};
typedef unsigned WUTPointOptions;

// Windows.UI.Text.RangeGravity
enum _WUTRangeGravity {
    WUTRangeGravityUIBehavior = 0,
    WUTRangeGravityBackward = 1,
    WUTRangeGravityForward = 2,
    WUTRangeGravityInward = 3,
    WUTRangeGravityOutward = 4,
};
typedef unsigned WUTRangeGravity;

// Windows.UI.Text.SelectionOptions
enum _WUTSelectionOptions {
    WUTSelectionOptionsStartActive = 1,
    WUTSelectionOptionsAtEndOfLine = 2,
    WUTSelectionOptionsOvertype = 4,
    WUTSelectionOptionsActive = 8,
    WUTSelectionOptionsReplace = 16,
};
typedef unsigned WUTSelectionOptions;

// Windows.UI.Text.SelectionType
enum _WUTSelectionType {
    WUTSelectionTypeNone = 0,
    WUTSelectionTypeInsertionPoint = 1,
    WUTSelectionTypeNormal = 2,
    WUTSelectionTypeInlineShape = 7,
    WUTSelectionTypeShape = 8,
};
typedef unsigned WUTSelectionType;

// Windows.UI.Text.TabAlignment
enum _WUTTabAlignment {
    WUTTabAlignmentLeft = 0,
    WUTTabAlignmentCenter = 1,
    WUTTabAlignmentRight = 2,
    WUTTabAlignmentDecimal = 3,
    WUTTabAlignmentBar = 4,
};
typedef unsigned WUTTabAlignment;

// Windows.UI.Text.TabLeader
enum _WUTTabLeader {
    WUTTabLeaderSpaces = 0,
    WUTTabLeaderDots = 1,
    WUTTabLeaderDashes = 2,
    WUTTabLeaderLines = 3,
    WUTTabLeaderThickLines = 4,
    WUTTabLeaderEquals = 5,
};
typedef unsigned WUTTabLeader;

// Windows.UI.Text.TextGetOptions
enum _WUTTextGetOptions {
    WUTTextGetOptionsNone = 0,
    WUTTextGetOptionsAdjustCrlf = 1,
    WUTTextGetOptionsUseCrlf = 2,
    WUTTextGetOptionsUseObjectText = 4,
    WUTTextGetOptionsAllowFinalEop = 8,
    WUTTextGetOptionsNoHidden = 32,
    WUTTextGetOptionsIncludeNumbering = 64,
    WUTTextGetOptionsFormatRtf = 8192,
};
typedef unsigned WUTTextGetOptions;

// Windows.UI.Text.TextSetOptions
enum _WUTTextSetOptions {
    WUTTextSetOptionsNone = 0,
    WUTTextSetOptionsUnicodeBidi = 1,
    WUTTextSetOptionsUnlink = 8,
    WUTTextSetOptionsUnhide = 16,
    WUTTextSetOptionsCheckTextLimit = 32,
    WUTTextSetOptionsFormatRtf = 8192,
    WUTTextSetOptionsApplyRtfDocumentDefaults = 16384,
};
typedef unsigned WUTTextSetOptions;

// Windows.UI.Text.TextRangeUnit
enum _WUTTextRangeUnit {
    WUTTextRangeUnitCharacter = 0,
    WUTTextRangeUnitWord = 1,
    WUTTextRangeUnitSentence = 2,
    WUTTextRangeUnitParagraph = 3,
    WUTTextRangeUnitLine = 4,
    WUTTextRangeUnitStory = 5,
    WUTTextRangeUnitScreen = 6,
    WUTTextRangeUnitSection = 7,
    WUTTextRangeUnitWindow = 8,
    WUTTextRangeUnitCharacterFormat = 9,
    WUTTextRangeUnitParagraphFormat = 10,
    WUTTextRangeUnitObject = 11,
    WUTTextRangeUnitHardParagraph = 12,
    WUTTextRangeUnitCluster = 13,
    WUTTextRangeUnitBold = 14,
    WUTTextRangeUnitItalic = 15,
    WUTTextRangeUnitUnderline = 16,
    WUTTextRangeUnitStrikethrough = 17,
    WUTTextRangeUnitProtectedText = 18,
    WUTTextRangeUnitLink = 19,
    WUTTextRangeUnitSmallCaps = 20,
    WUTTextRangeUnitAllCaps = 21,
    WUTTextRangeUnitHidden = 22,
    WUTTextRangeUnitOutline = 23,
    WUTTextRangeUnitShadow = 24,
    WUTTextRangeUnitImprint = 25,
    WUTTextRangeUnitDisabled = 26,
    WUTTextRangeUnitRevised = 27,
    WUTTextRangeUnitSubscript = 28,
    WUTTextRangeUnitSuperscript = 29,
    WUTTextRangeUnitFontBound = 30,
    WUTTextRangeUnitLinkProtected = 31,
};
typedef unsigned WUTTextRangeUnit;

// Windows.UI.Text.TextScript
enum _WUTTextScript {
    WUTTextScriptUndefined = 0,
    WUTTextScriptAnsi = 1,
    WUTTextScriptEastEurope = 2,
    WUTTextScriptCyrillic = 3,
    WUTTextScriptGreek = 4,
    WUTTextScriptTurkish = 5,
    WUTTextScriptHebrew = 6,
    WUTTextScriptArabic = 7,
    WUTTextScriptBaltic = 8,
    WUTTextScriptVietnamese = 9,
    WUTTextScriptDefault = 10,
    WUTTextScriptSymbol = 11,
    WUTTextScriptThai = 12,
    WUTTextScriptShiftJis = 13,
    WUTTextScriptGB2312 = 14,
    WUTTextScriptHangul = 15,
    WUTTextScriptBig5 = 16,
    WUTTextScriptPC437 = 17,
    WUTTextScriptOem = 18,
    WUTTextScriptMac = 19,
    WUTTextScriptArmenian = 20,
    WUTTextScriptSyriac = 21,
    WUTTextScriptThaana = 22,
    WUTTextScriptDevanagari = 23,
    WUTTextScriptBengali = 24,
    WUTTextScriptGurmukhi = 25,
    WUTTextScriptGujarati = 26,
    WUTTextScriptOriya = 27,
    WUTTextScriptTamil = 28,
    WUTTextScriptTelugu = 29,
    WUTTextScriptKannada = 30,
    WUTTextScriptMalayalam = 31,
    WUTTextScriptSinhala = 32,
    WUTTextScriptLao = 33,
    WUTTextScriptTibetan = 34,
    WUTTextScriptMyanmar = 35,
    WUTTextScriptGeorgian = 36,
    WUTTextScriptJamo = 37,
    WUTTextScriptEthiopic = 38,
    WUTTextScriptCherokee = 39,
    WUTTextScriptAboriginal = 40,
    WUTTextScriptOgham = 41,
    WUTTextScriptRunic = 42,
    WUTTextScriptKhmer = 43,
    WUTTextScriptMongolian = 44,
    WUTTextScriptBraille = 45,
    WUTTextScriptYi = 46,
    WUTTextScriptLimbu = 47,
    WUTTextScriptTaiLe = 48,
    WUTTextScriptNewTaiLue = 49,
    WUTTextScriptSylotiNagri = 50,
    WUTTextScriptKharoshthi = 51,
    WUTTextScriptKayahli = 52,
    WUTTextScriptUnicodeSymbol = 53,
    WUTTextScriptEmoji = 54,
    WUTTextScriptGlagolitic = 55,
    WUTTextScriptLisu = 56,
    WUTTextScriptVai = 57,
    WUTTextScriptNKo = 58,
    WUTTextScriptOsmanya = 59,
    WUTTextScriptPhagsPa = 60,
    WUTTextScriptGothic = 61,
    WUTTextScriptDeseret = 62,
    WUTTextScriptTifinagh = 63,
};
typedef unsigned WUTTextScript;

// Windows.UI.Text.UnderlineType
enum _WUTUnderlineType {
    WUTUnderlineTypeUndefined = 0,
    WUTUnderlineTypeNone = 1,
    WUTUnderlineTypeSingle = 2,
    WUTUnderlineTypeWords = 3,
    WUTUnderlineTypeDouble = 4,
    WUTUnderlineTypeDotted = 5,
    WUTUnderlineTypeDash = 6,
    WUTUnderlineTypeDashDot = 7,
    WUTUnderlineTypeDashDotDot = 8,
    WUTUnderlineTypeWave = 9,
    WUTUnderlineTypeThick = 10,
    WUTUnderlineTypeThin = 11,
    WUTUnderlineTypeDoubleWave = 12,
    WUTUnderlineTypeHeavyWave = 13,
    WUTUnderlineTypeLongDash = 14,
    WUTUnderlineTypeThickDash = 15,
    WUTUnderlineTypeThickDashDot = 16,
    WUTUnderlineTypeThickDashDotDot = 17,
    WUTUnderlineTypeThickDotted = 18,
    WUTUnderlineTypeThickLongDash = 19,
};
typedef unsigned WUTUnderlineType;

// Windows.UI.Text.VerticalCharacterAlignment
enum _WUTVerticalCharacterAlignment {
    WUTVerticalCharacterAlignmentTop = 0,
    WUTVerticalCharacterAlignmentBaseline = 1,
    WUTVerticalCharacterAlignmentBottom = 2,
};
typedef unsigned WUTVerticalCharacterAlignment;

// Windows.UI.Text.FontStretch
enum _WUTFontStretch {
    WUTFontStretchUndefined = 0,
    WUTFontStretchUltraCondensed = 1,
    WUTFontStretchExtraCondensed = 2,
    WUTFontStretchCondensed = 3,
    WUTFontStretchSemiCondensed = 4,
    WUTFontStretchNormal = 5,
    WUTFontStretchSemiExpanded = 6,
    WUTFontStretchExpanded = 7,
    WUTFontStretchExtraExpanded = 8,
    WUTFontStretchUltraExpanded = 9,
};
typedef unsigned WUTFontStretch;

// Windows.UI.Text.FontStyle
enum _WUTFontStyle {
    WUTFontStyleNormal = 0,
    WUTFontStyleOblique = 1,
    WUTFontStyleItalic = 2,
};
typedef unsigned WUTFontStyle;

#include "WindowsUI.h"
#include "WindowsFoundation.h"
#include "WindowsStorageStreams.h"

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Text.FontWeight
WINRT_EXPORT
@interface WUTFontWeight : NSObject
+ (instancetype) new;
@property unsigned short weight;
@end

// Windows.UI.Text.ITextDocument
#ifndef __WUTITextDocument_DEFINED__
#define __WUTITextDocument_DEFINED__

@protocol WUTITextDocument
@property WUTCaretType caretType;
@property float defaultTabStop;
@property (readonly) RTObject<WUTITextSelection>* selection;
@property unsigned int undoLimit;
- (BOOL)canCopy;
- (BOOL)canPaste;
- (BOOL)canRedo;
- (BOOL)canUndo;
- (int)applyDisplayUpdates;
- (int)batchDisplayUpdates;
- (void)beginUndoGroup;
- (void)endUndoGroup;
- (RTObject<WUTITextCharacterFormat>*)getDefaultCharacterFormat;
- (RTObject<WUTITextParagraphFormat>*)getDefaultParagraphFormat;
- (RTObject<WUTITextRange>*)getRange:(int)startPosition endPosition:(int)endPosition;
- (RTObject<WUTITextRange>*)getRangeFromPoint:(WFPoint*)point options:(WUTPointOptions)options;
- (void)getText:(WUTTextGetOptions)options value:(NSString**)value;
- (void)loadFromStream:(WUTTextSetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value;
- (void)redo;
- (void)saveToStream:(WUTTextGetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value;
- (void)setDefaultCharacterFormat:(RTObject<WUTITextCharacterFormat>*)value;
- (void)setDefaultParagraphFormat:(RTObject<WUTITextParagraphFormat>*)value;
- (void)setText:(WUTTextSetOptions)options value:(NSString*)value;
- (void)undo;
@end

#endif // __WUTITextDocument_DEFINED__

// Windows.UI.Text.ITextRange
#ifndef __WUTITextRange_DEFINED__
#define __WUTITextRange_DEFINED__

@protocol WUTITextRange
@property WCHAR character;
@property (copy) RTObject<WUTITextCharacterFormat>* characterFormat;
@property int endPosition;
@property (copy) RTObject<WUTITextRange>* formattedText;
@property WUTRangeGravity gravity;
@property (readonly) int length;
@property (copy) NSString* link;
@property (copy) RTObject<WUTITextParagraphFormat>* paragraphFormat;
@property int startPosition;
@property (readonly) int storyLength;
@property (copy) NSString* text;
- (BOOL)canPaste:(int)format;
- (void)changeCase:(WUTLetterCase)value;
- (void)collapse:(BOOL)value;
- (void)copy;
- (void)cut;
- (int)Delete:(WUTTextRangeUnit)unit count:(int)count;
- (int)endOf:(WUTTextRangeUnit)unit extend:(BOOL)extend;
- (int)expand:(WUTTextRangeUnit)unit;
- (int)findText:(NSString*)value scanLength:(int)scanLength options:(WUTFindOptions)options;
- (void)getCharacterUtf32:(unsigned int*)value offset:(int)offset;
- (RTObject<WUTITextRange>*)getClone;
- (int)getIndex:(WUTTextRangeUnit)unit;
- (void)getPoint:(WUTHorizontalCharacterAlignment)horizontalAlign
   verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
         options:(WUTPointOptions)options
           point:(WFPoint**)point;
- (void)getRect:(WUTPointOptions)options rect:(WFRect**)rect hit:(int*)hit;
- (void)getText:(WUTTextGetOptions)options value:(NSString**)value;
- (void)getTextViaStream:(WUTTextGetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value;
- (BOOL)inRange:(RTObject<WUTITextRange>*)range;
- (void)insertImage:(int)width
             height:(int)height
             ascent:(int)ascent
      verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
      alternateText:(NSString*)alternateText
              value:(RTObject<WSSIRandomAccessStream>*)value;
- (BOOL)inStory:(RTObject<WUTITextRange>*)range;
- (BOOL)isEqual:(RTObject<WUTITextRange>*)range;
- (int)move:(WUTTextRangeUnit)unit count:(int)count;
- (int)moveEnd:(WUTTextRangeUnit)unit count:(int)count;
- (int)moveStart:(WUTTextRangeUnit)unit count:(int)count;
- (void)paste:(int)format;
- (void)scrollIntoView:(WUTPointOptions)value;
- (void)matchSelection;
- (void)setIndex:(WUTTextRangeUnit)unit index:(int)index extend:(BOOL)extend;
- (void)setPoint:(WFPoint*)point options:(WUTPointOptions)options extend:(BOOL)extend;
- (void)setRange:(int)startPosition endPosition:(int)endPosition;
- (void)setText:(WUTTextSetOptions)options value:(NSString*)value;
- (void)setTextViaStream:(WUTTextSetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value;
- (int)startOf:(WUTTextRangeUnit)unit extend:(BOOL)extend;
@end

#endif // __WUTITextRange_DEFINED__

// Windows.UI.Text.ITextSelection
#ifndef __WUTITextSelection_DEFINED__
#define __WUTITextSelection_DEFINED__

@protocol WUTITextSelection <WUTITextRange>
@property WUTSelectionOptions options;
@property (readonly) WUTSelectionType type;
- (int)endKey:(WUTTextRangeUnit)unit extend:(BOOL)extend;
- (int)homeKey:(WUTTextRangeUnit)unit extend:(BOOL)extend;
- (int)moveDown:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend;
- (int)moveLeft:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend;
- (int)moveRight:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend;
- (int)moveUp:(WUTTextRangeUnit)unit count:(int)count extend:(BOOL)extend;
- (void)typeText:(NSString*)value;
- (BOOL)canPaste:(int)format;
- (void)changeCase:(WUTLetterCase)value;
- (void)collapse:(BOOL)value;
- (void)copy;
- (void)cut;
- (int)Delete:(WUTTextRangeUnit)unit count:(int)count;
- (int)endOf:(WUTTextRangeUnit)unit extend:(BOOL)extend;
- (int)expand:(WUTTextRangeUnit)unit;
- (int)findText:(NSString*)value scanLength:(int)scanLength options:(WUTFindOptions)options;
- (void)getCharacterUtf32:(unsigned int*)value offset:(int)offset;
- (RTObject<WUTITextRange>*)getClone;
- (int)getIndex:(WUTTextRangeUnit)unit;
- (void)getPoint:(WUTHorizontalCharacterAlignment)horizontalAlign
   verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
         options:(WUTPointOptions)options
           point:(WFPoint**)point;
- (void)getRect:(WUTPointOptions)options rect:(WFRect**)rect hit:(int*)hit;
- (void)getText:(WUTTextGetOptions)options value:(NSString**)value;
- (void)getTextViaStream:(WUTTextGetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value;
- (BOOL)inRange:(RTObject<WUTITextRange>*)range;
- (void)insertImage:(int)width
             height:(int)height
             ascent:(int)ascent
      verticalAlign:(WUTVerticalCharacterAlignment)verticalAlign
      alternateText:(NSString*)alternateText
              value:(RTObject<WSSIRandomAccessStream>*)value;
- (BOOL)inStory:(RTObject<WUTITextRange>*)range;
- (BOOL)isEqual:(RTObject<WUTITextRange>*)range;
- (int)move:(WUTTextRangeUnit)unit count:(int)count;
- (int)moveEnd:(WUTTextRangeUnit)unit count:(int)count;
- (int)moveStart:(WUTTextRangeUnit)unit count:(int)count;
- (void)paste:(int)format;
- (void)scrollIntoView:(WUTPointOptions)value;
- (void)matchSelection;
- (void)setIndex:(WUTTextRangeUnit)unit index:(int)index extend:(BOOL)extend;
- (void)setPoint:(WFPoint*)point options:(WUTPointOptions)options extend:(BOOL)extend;
- (void)setRange:(int)startPosition endPosition:(int)endPosition;
- (void)setText:(WUTTextSetOptions)options value:(NSString*)value;
- (void)setTextViaStream:(WUTTextSetOptions)options value:(RTObject<WSSIRandomAccessStream>*)value;
- (int)startOf:(WUTTextRangeUnit)unit extend:(BOOL)extend;
@end

#endif // __WUTITextSelection_DEFINED__

// Windows.UI.Text.ITextCharacterFormat
#ifndef __WUTITextCharacterFormat_DEFINED__
#define __WUTITextCharacterFormat_DEFINED__

@protocol WUTITextCharacterFormat
@property WUTFormatEffect allCaps;
@property (copy) WUColor* backgroundColor;
@property WUTFormatEffect bold;
@property WUTFontStretch fontStretch;
@property WUTFontStyle fontStyle;
@property (copy) WUColor* foregroundColor;
@property WUTFormatEffect hidden;
@property WUTFormatEffect italic;
@property float kerning;
@property (copy) NSString* languageTag;
@property (readonly) WUTLinkType linkType;
@property (copy) NSString* name;
@property WUTFormatEffect outline;
@property float position;
@property WUTFormatEffect protectedText;
@property float size;
@property WUTFormatEffect smallCaps;
@property float spacing;
@property WUTFormatEffect strikethrough;
@property WUTFormatEffect subscript;
@property WUTFormatEffect superscript;
@property WUTTextScript textScript;
@property WUTUnderlineType underline;
@property int weight;
- (void)setClone:(RTObject<WUTITextCharacterFormat>*)value;
- (RTObject<WUTITextCharacterFormat>*)getClone;
- (BOOL)isEqual:(RTObject<WUTITextCharacterFormat>*)format;
@end

#endif // __WUTITextCharacterFormat_DEFINED__

// Windows.UI.Text.ITextParagraphFormat
#ifndef __WUTITextParagraphFormat_DEFINED__
#define __WUTITextParagraphFormat_DEFINED__

@protocol WUTITextParagraphFormat
@property WUTParagraphAlignment alignment;
@property (readonly) float firstLineIndent;
@property WUTFormatEffect keepTogether;
@property WUTFormatEffect keepWithNext;
@property (readonly) float leftIndent;
@property (readonly) float lineSpacing;
@property (readonly) WUTLineSpacingRule lineSpacingRule;
@property WUTMarkerAlignment listAlignment;
@property int listLevelIndex;
@property int listStart;
@property WUTMarkerStyle listStyle;
@property float listTab;
@property WUTMarkerType listType;
@property WUTFormatEffect noLineNumber;
@property WUTFormatEffect pageBreakBefore;
@property float rightIndent;
@property WUTFormatEffect rightToLeft;
@property float spaceAfter;
@property float spaceBefore;
@property WUTParagraphStyle style;
@property (readonly) int tabCount;
@property WUTFormatEffect widowControl;
- (void)addTab:(float)position align:(WUTTabAlignment)align leader:(WUTTabLeader)leader;
- (void)clearAllTabs;
- (void)deleteTab:(float)position;
- (RTObject<WUTITextParagraphFormat>*)getClone;
- (void)getTab:(int)index position:(float*)position align:(WUTTabAlignment*)align leader:(WUTTabLeader*)leader;
- (BOOL)isEqual:(RTObject<WUTITextParagraphFormat>*)format;
- (void)setClone:(RTObject<WUTITextParagraphFormat>*)format;
- (void)setIndents:(float)start left:(float)left right:(float)right;
- (void)setLineSpacing:(WUTLineSpacingRule)rule spacing:(float)spacing;
@end

#endif // __WUTITextParagraphFormat_DEFINED__

// Windows.UI.Text.TextConstants
#ifndef __WUTTextConstants_DEFINED__
#define __WUTTextConstants_DEFINED__

WINRT_EXPORT
@interface WUTTextConstants : RTObject
+ (WUColor*)autoColor;
+ (int)maxUnitCount;
+ (int)minUnitCount;
+ (WUColor*)undefinedColor;
+ (float)undefinedFloatValue;
+ (WUTFontStretch)undefinedFontStretch;
+ (WUTFontStyle)undefinedFontStyle;
+ (int)undefinedInt32Value;
@end

#endif // __WUTTextConstants_DEFINED__

// Windows.UI.Text.FontWeights
#ifndef __WUTFontWeights_DEFINED__
#define __WUTFontWeights_DEFINED__

WINRT_EXPORT
@interface WUTFontWeights : RTObject
+ (WUTFontWeight*)black;
+ (WUTFontWeight*)bold;
+ (WUTFontWeight*)extraBlack;
+ (WUTFontWeight*)extraBold;
+ (WUTFontWeight*)extraLight;
+ (WUTFontWeight*)light;
+ (WUTFontWeight*)medium;
+ (WUTFontWeight*)normal;
+ (WUTFontWeight*)semiBold;
+ (WUTFontWeight*)semiLight;
+ (WUTFontWeight*)thin;
@end

#endif // __WUTFontWeights_DEFINED__
