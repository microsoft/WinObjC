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

// WindowsUIXamlDocuments.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLEXPORT
#define OBJCUWPWINDOWSUIXAMLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXaml.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WUXDBlockCollection, WUXDInlineCollection, WUXDTextHighlighter, WUXDTextPointer, WUXDTypography, WUXDTextElement, WUXDTextHighlighterBase, WUXDBlock, WUXDInline, WUXDInlineUIContainer, WUXDLineBreak, WUXDParagraph, WUXDRun, WUXDSpan, WUXDBold, WUXDItalic, WUXDUnderline, WUXDHyperlink, WUXDHyperlinkClickEventArgs, WUXDGlyphs;
@class WUXDTextRange;
@protocol WUXDITextHighlighter, WUXDITextHighlighterStatics, WUXDITextHighlighterFactory, WUXDITextPointer, WUXDITypography, WUXDITypographyStatics, WUXDITextElement, WUXDITextElementOverrides, WUXDITextElementStatics, WUXDITextElementFactory, WUXDITextElement2, WUXDITextElementStatics2, WUXDITextElement3, WUXDITextElementStatics3, WUXDITextElement4, WUXDITextElementStatics4, WUXDITextHighlighterBase, WUXDITextHighlighterBaseFactory, WUXDIBlock, WUXDIBlockStatics, WUXDIBlockFactory, WUXDIBlock2, WUXDIBlockStatics2, WUXDIInline, WUXDIInlineFactory, WUXDIInlineUIContainer, WUXDILineBreak, WUXDIParagraph, WUXDIParagraphStatics, WUXDIRun, WUXDIRunStatics, WUXDISpan, WUXDISpanFactory, WUXDIBold, WUXDIItalic, WUXDIUnderline, WUXDIHyperlinkClickEventArgs, WUXDIGlyphs, WUXDIGlyphsStatics, WUXDIGlyphs2, WUXDIGlyphsStatics2, WUXDIHyperlink, WUXDIHyperlinkStatics, WUXDIHyperlink2, WUXDIHyperlinkStatics2, WUXDIHyperlink3, WUXDIHyperlinkStatics3, WUXDIHyperlink4, WUXDIHyperlinkStatics4, WUXDIHyperlink5, WUXDIHyperlinkStatics5;

// Windows.UI.Xaml.Documents.LogicalDirection
enum _WUXDLogicalDirection {
    WUXDLogicalDirectionBackward = 0,
    WUXDLogicalDirectionForward = 1,
};
typedef unsigned WUXDLogicalDirection;

// Windows.UI.Xaml.Documents.UnderlineStyle
enum _WUXDUnderlineStyle {
    WUXDUnderlineStyleNone = 0,
    WUXDUnderlineStyleSingle = 1,
};
typedef unsigned WUXDUnderlineStyle;

#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIXaml.h"
#include "WindowsFoundation.h"
#include "WindowsUIText.h"
#include "WindowsUICore.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUIXamlData.h"
#include "WindowsUIInput.h"
#include "WindowsUIXamlAutomationPeers.h"
#include "WindowsUIXamlMediaMedia3D.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void(^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void(^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void(^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void(^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void(^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void(^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void(^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void(^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void(^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void(^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void(^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void(^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void(^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void(^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED


#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Documents.TextRange
OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDTextRange : NSObject
+ (instancetype)new;
@property int startIndex;
@property int length;
@end

// Windows.UI.Xaml.Documents.ITextElementOverrides
#ifndef __WUXDITextElementOverrides_DEFINED__
#define __WUXDITextElementOverrides_DEFINED__

@protocol WUXDITextElementOverrides
- (void)onDisconnectVisualChildren;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDITextElementOverrides : RTObject <WUXDITextElementOverrides>
@end

#endif // __WUXDITextElementOverrides_DEFINED__

// Windows.UI.Xaml.Documents.BlockCollection
#ifndef __WUXDBlockCollection_DEFINED__
#define __WUXDBlockCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDBlockCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXDBlockCollection_DEFINED__

// Windows.UI.Xaml.Documents.InlineCollection
#ifndef __WUXDInlineCollection_DEFINED__
#define __WUXDInlineCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDInlineCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WUXDInlineCollection_DEFINED__

// Windows.UI.Xaml.Documents.TextHighlighter
#ifndef __WUXDTextHighlighter_DEFINED__
#define __WUXDTextHighlighter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDTextHighlighter : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMBrush* foreground;
@property (retain) WUXMBrush* background;
@property (readonly) NSMutableArray* /* WUXDTextRange* */ ranges;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)foregroundProperty;
@end

#endif // __WUXDTextHighlighter_DEFINED__

// Windows.UI.Xaml.Documents.TextPointer
#ifndef __WUXDTextPointer_DEFINED__
#define __WUXDTextPointer_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDTextPointer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXDLogicalDirection logicalDirection;
@property (readonly) int offset;
@property (readonly) WXDependencyObject* parent;
@property (readonly) WXFrameworkElement* visualParent;
- (WFRect*)getCharacterRect:(WUXDLogicalDirection)direction;
- (WUXDTextPointer*)getPositionAtOffset:(int)offset direction:(WUXDLogicalDirection)direction;
@end

#endif // __WUXDTextPointer_DEFINED__

// Windows.UI.Xaml.Documents.Typography
#ifndef __WUXDTypography_DEFINED__
#define __WUXDTypography_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDTypography : RTObject
+ (int)getAnnotationAlternates:(WXDependencyObject*)element;
+ (void)setAnnotationAlternates:(WXDependencyObject*)element value:(int)value;
+ (BOOL)getEastAsianExpertForms:(WXDependencyObject*)element;
+ (void)setEastAsianExpertForms:(WXDependencyObject*)element value:(BOOL)value;
+ (WXFontEastAsianLanguage)getEastAsianLanguage:(WXDependencyObject*)element;
+ (void)setEastAsianLanguage:(WXDependencyObject*)element value:(WXFontEastAsianLanguage)value;
+ (WXFontEastAsianWidths)getEastAsianWidths:(WXDependencyObject*)element;
+ (void)setEastAsianWidths:(WXDependencyObject*)element value:(WXFontEastAsianWidths)value;
+ (BOOL)getStandardLigatures:(WXDependencyObject*)element;
+ (void)setStandardLigatures:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getContextualLigatures:(WXDependencyObject*)element;
+ (void)setContextualLigatures:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getDiscretionaryLigatures:(WXDependencyObject*)element;
+ (void)setDiscretionaryLigatures:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getHistoricalLigatures:(WXDependencyObject*)element;
+ (void)setHistoricalLigatures:(WXDependencyObject*)element value:(BOOL)value;
+ (int)getStandardSwashes:(WXDependencyObject*)element;
+ (void)setStandardSwashes:(WXDependencyObject*)element value:(int)value;
+ (int)getContextualSwashes:(WXDependencyObject*)element;
+ (void)setContextualSwashes:(WXDependencyObject*)element value:(int)value;
+ (BOOL)getContextualAlternates:(WXDependencyObject*)element;
+ (void)setContextualAlternates:(WXDependencyObject*)element value:(BOOL)value;
+ (int)getStylisticAlternates:(WXDependencyObject*)element;
+ (void)setStylisticAlternates:(WXDependencyObject*)element value:(int)value;
+ (BOOL)getStylisticSet1:(WXDependencyObject*)element;
+ (void)setStylisticSet1:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet2:(WXDependencyObject*)element;
+ (void)setStylisticSet2:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet3:(WXDependencyObject*)element;
+ (void)setStylisticSet3:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet4:(WXDependencyObject*)element;
+ (void)setStylisticSet4:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet5:(WXDependencyObject*)element;
+ (void)setStylisticSet5:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet6:(WXDependencyObject*)element;
+ (void)setStylisticSet6:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet7:(WXDependencyObject*)element;
+ (void)setStylisticSet7:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet8:(WXDependencyObject*)element;
+ (void)setStylisticSet8:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet9:(WXDependencyObject*)element;
+ (void)setStylisticSet9:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet10:(WXDependencyObject*)element;
+ (void)setStylisticSet10:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet11:(WXDependencyObject*)element;
+ (void)setStylisticSet11:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet12:(WXDependencyObject*)element;
+ (void)setStylisticSet12:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet13:(WXDependencyObject*)element;
+ (void)setStylisticSet13:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet14:(WXDependencyObject*)element;
+ (void)setStylisticSet14:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet15:(WXDependencyObject*)element;
+ (void)setStylisticSet15:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet16:(WXDependencyObject*)element;
+ (void)setStylisticSet16:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet17:(WXDependencyObject*)element;
+ (void)setStylisticSet17:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet18:(WXDependencyObject*)element;
+ (void)setStylisticSet18:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet19:(WXDependencyObject*)element;
+ (void)setStylisticSet19:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getStylisticSet20:(WXDependencyObject*)element;
+ (void)setStylisticSet20:(WXDependencyObject*)element value:(BOOL)value;
+ (WXFontCapitals)getCapitals:(WXDependencyObject*)element;
+ (void)setCapitals:(WXDependencyObject*)element value:(WXFontCapitals)value;
+ (BOOL)getCapitalSpacing:(WXDependencyObject*)element;
+ (void)setCapitalSpacing:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getKerning:(WXDependencyObject*)element;
+ (void)setKerning:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getCaseSensitiveForms:(WXDependencyObject*)element;
+ (void)setCaseSensitiveForms:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getHistoricalForms:(WXDependencyObject*)element;
+ (void)setHistoricalForms:(WXDependencyObject*)element value:(BOOL)value;
+ (WXFontFraction)getFraction:(WXDependencyObject*)element;
+ (void)setFraction:(WXDependencyObject*)element value:(WXFontFraction)value;
+ (WXFontNumeralStyle)getNumeralStyle:(WXDependencyObject*)element;
+ (void)setNumeralStyle:(WXDependencyObject*)element value:(WXFontNumeralStyle)value;
+ (WXFontNumeralAlignment)getNumeralAlignment:(WXDependencyObject*)element;
+ (void)setNumeralAlignment:(WXDependencyObject*)element value:(WXFontNumeralAlignment)value;
+ (BOOL)getSlashedZero:(WXDependencyObject*)element;
+ (void)setSlashedZero:(WXDependencyObject*)element value:(BOOL)value;
+ (BOOL)getMathematicalGreek:(WXDependencyObject*)element;
+ (void)setMathematicalGreek:(WXDependencyObject*)element value:(BOOL)value;
+ (WXFontVariants)getVariants:(WXDependencyObject*)element;
+ (void)setVariants:(WXDependencyObject*)element value:(WXFontVariants)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WXDependencyProperty*)annotationAlternatesProperty;
+ (WXDependencyProperty*)capitalSpacingProperty;
+ (WXDependencyProperty*)capitalsProperty;
+ (WXDependencyProperty*)caseSensitiveFormsProperty;
+ (WXDependencyProperty*)contextualAlternatesProperty;
+ (WXDependencyProperty*)contextualLigaturesProperty;
+ (WXDependencyProperty*)contextualSwashesProperty;
+ (WXDependencyProperty*)discretionaryLigaturesProperty;
+ (WXDependencyProperty*)eastAsianExpertFormsProperty;
+ (WXDependencyProperty*)eastAsianLanguageProperty;
+ (WXDependencyProperty*)eastAsianWidthsProperty;
+ (WXDependencyProperty*)fractionProperty;
+ (WXDependencyProperty*)historicalFormsProperty;
+ (WXDependencyProperty*)historicalLigaturesProperty;
+ (WXDependencyProperty*)kerningProperty;
+ (WXDependencyProperty*)mathematicalGreekProperty;
+ (WXDependencyProperty*)numeralAlignmentProperty;
+ (WXDependencyProperty*)numeralStyleProperty;
+ (WXDependencyProperty*)slashedZeroProperty;
+ (WXDependencyProperty*)standardLigaturesProperty;
+ (WXDependencyProperty*)standardSwashesProperty;
+ (WXDependencyProperty*)stylisticAlternatesProperty;
+ (WXDependencyProperty*)stylisticSet10Property;
+ (WXDependencyProperty*)stylisticSet11Property;
+ (WXDependencyProperty*)stylisticSet12Property;
+ (WXDependencyProperty*)stylisticSet13Property;
+ (WXDependencyProperty*)stylisticSet14Property;
+ (WXDependencyProperty*)stylisticSet15Property;
+ (WXDependencyProperty*)stylisticSet16Property;
+ (WXDependencyProperty*)stylisticSet17Property;
+ (WXDependencyProperty*)stylisticSet18Property;
+ (WXDependencyProperty*)stylisticSet19Property;
+ (WXDependencyProperty*)stylisticSet1Property;
+ (WXDependencyProperty*)stylisticSet20Property;
+ (WXDependencyProperty*)stylisticSet2Property;
+ (WXDependencyProperty*)stylisticSet3Property;
+ (WXDependencyProperty*)stylisticSet4Property;
+ (WXDependencyProperty*)stylisticSet5Property;
+ (WXDependencyProperty*)stylisticSet6Property;
+ (WXDependencyProperty*)stylisticSet7Property;
+ (WXDependencyProperty*)stylisticSet8Property;
+ (WXDependencyProperty*)stylisticSet9Property;
+ (WXDependencyProperty*)variantsProperty;
@end

#endif // __WUXDTypography_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXDependencyObject : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCCoreDispatcher* dispatcher;
- (RTObject*)getValue:(WXDependencyProperty*)dp;
- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value;
- (void)clearValue:(WXDependencyProperty*)dp;
- (RTObject*)readLocalValue:(WXDependencyProperty*)dp;
- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp;
- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback;
- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Documents.TextElement
#ifndef __WUXDTextElement_DEFINED__
#define __WUXDTextElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDTextElement : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUTFontStretch fontStretch;
@property double fontSize;
@property (retain) NSString * language;
@property (retain) WUXMFontFamily* fontFamily;
@property (retain) WUXMBrush* foreground;
@property (retain) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property int characterSpacing;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) WUXDTextPointer* contentStart;
@property (readonly) WUXDTextPointer* elementEnd;
@property (readonly) WUXDTextPointer* elementStart;
@property (readonly) NSString * name;
@property BOOL isTextScaleFactorEnabled;
@property (retain) NSString * accessKey;
@property BOOL exitDisplayModeOnAccessKeyInvoked;
@property BOOL allowFocusOnInteraction;
@property double keyTipVerticalOffset;
@property WUXIKeyTipPlacementMode keyTipPlacementMode;
@property double keyTipHorizontalOffset;
@property BOOL isAccessKeyScope;
@property (retain) WXDependencyObject* accessKeyScopeOwner;
@property WUTTextDecorations textDecorations;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)exitDisplayModeOnAccessKeyInvokedProperty;
+ (WXDependencyProperty*)allowFocusOnInteractionProperty;
+ (WXDependencyProperty*)accessKeyProperty;
+ (WXDependencyProperty*)accessKeyScopeOwnerProperty;
+ (WXDependencyProperty*)isAccessKeyScopeProperty;
+ (WXDependencyProperty*)keyTipHorizontalOffsetProperty;
+ (WXDependencyProperty*)textDecorationsProperty;
+ (WXDependencyProperty*)keyTipVerticalOffsetProperty;
+ (WXDependencyProperty*)keyTipPlacementModeProperty;
- (EventRegistrationToken)addAccessKeyDisplayDismissedEvent:(void(^)(WUXDTextElement*, WUXIAccessKeyDisplayDismissedEventArgs*))del;
- (void)removeAccessKeyDisplayDismissedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayRequestedEvent:(void(^)(WUXDTextElement*, WUXIAccessKeyDisplayRequestedEventArgs*))del;
- (void)removeAccessKeyDisplayRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyInvokedEvent:(void(^)(WUXDTextElement*, WUXIAccessKeyInvokedEventArgs*))del;
- (void)removeAccessKeyInvokedEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString *)name;
- (void)onDisconnectVisualChildren;
@end

#endif // __WUXDTextElement_DEFINED__

// Windows.UI.Xaml.Documents.TextHighlighterBase
#ifndef __WUXDTextHighlighterBase_DEFINED__
#define __WUXDTextHighlighterBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDTextHighlighterBase : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXDTextHighlighterBase_DEFINED__

// Windows.UI.Xaml.Documents.Block
#ifndef __WUXDBlock_DEFINED__
#define __WUXDBlock_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDBlock : WUXDTextElement
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXTextAlignment textAlignment;
@property (retain) WXThickness* margin;
@property WXLineStackingStrategy lineStackingStrategy;
@property double lineHeight;
@property WXTextAlignment horizontalTextAlignment;
+ (WXDependencyProperty*)lineHeightProperty;
+ (WXDependencyProperty*)lineStackingStrategyProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)horizontalTextAlignmentProperty;
@end

#endif // __WUXDBlock_DEFINED__

// Windows.UI.Xaml.Documents.Inline
#ifndef __WUXDInline_DEFINED__
#define __WUXDInline_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDInline : WUXDTextElement
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXDInline_DEFINED__

// Windows.UI.Xaml.Documents.InlineUIContainer
#ifndef __WUXDInlineUIContainer_DEFINED__
#define __WUXDInlineUIContainer_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDInlineUIContainer : WUXDInline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXUIElement* child;
@end

#endif // __WUXDInlineUIContainer_DEFINED__

// Windows.UI.Xaml.Documents.LineBreak
#ifndef __WUXDLineBreak_DEFINED__
#define __WUXDLineBreak_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDLineBreak : WUXDInline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXDLineBreak_DEFINED__

// Windows.UI.Xaml.Documents.Paragraph
#ifndef __WUXDParagraph_DEFINED__
#define __WUXDParagraph_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDParagraph : WUXDBlock
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double textIndent;
@property (readonly) WUXDInlineCollection* inlines;
+ (WXDependencyProperty*)textIndentProperty;
@end

#endif // __WUXDParagraph_DEFINED__

// Windows.UI.Xaml.Documents.Run
#ifndef __WUXDRun_DEFINED__
#define __WUXDRun_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDRun : WUXDInline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * text;
@property WXFlowDirection flowDirection;
+ (WXDependencyProperty*)flowDirectionProperty;
@end

#endif // __WUXDRun_DEFINED__

// Windows.UI.Xaml.Documents.Span
#ifndef __WUXDSpan_DEFINED__
#define __WUXDSpan_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDSpan : WUXDInline
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXDInlineCollection* inlines;
@end

#endif // __WUXDSpan_DEFINED__

// Windows.UI.Xaml.Documents.Bold
#ifndef __WUXDBold_DEFINED__
#define __WUXDBold_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDBold : WUXDSpan
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXDBold_DEFINED__

// Windows.UI.Xaml.Documents.Italic
#ifndef __WUXDItalic_DEFINED__
#define __WUXDItalic_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDItalic : WUXDSpan
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXDItalic_DEFINED__

// Windows.UI.Xaml.Documents.Underline
#ifndef __WUXDUnderline_DEFINED__
#define __WUXDUnderline_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDUnderline : WUXDSpan
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXDUnderline_DEFINED__

// Windows.UI.Xaml.Documents.Hyperlink
#ifndef __WUXDHyperlink_DEFINED__
#define __WUXDHyperlink_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDHyperlink : WUXDSpan
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* navigateUri;
@property WUXDUnderlineStyle underlineStyle;
@property (retain) WXDependencyObject* xYFocusUp;
@property (retain) WXDependencyObject* xYFocusRight;
@property (retain) WXDependencyObject* xYFocusLeft;
@property (retain) WXDependencyObject* xYFocusDown;
@property WXElementSoundMode elementSoundMode;
@property WUXIXYFocusNavigationStrategy xYFocusDownNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusUpNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusRightNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusLeftNavigationStrategy;
@property (readonly) WXFocusState focusState;
@property BOOL isTabStop;
@property int tabIndex;
+ (WXDependencyProperty*)navigateUriProperty;
+ (WXDependencyProperty*)underlineStyleProperty;
+ (WXDependencyProperty*)xYFocusDownProperty;
+ (WXDependencyProperty*)xYFocusLeftProperty;
+ (WXDependencyProperty*)xYFocusRightProperty;
+ (WXDependencyProperty*)xYFocusUpProperty;
+ (WXDependencyProperty*)elementSoundModeProperty;
+ (WXDependencyProperty*)xYFocusUpNavigationStrategyProperty;
+ (WXDependencyProperty*)focusStateProperty;
+ (WXDependencyProperty*)xYFocusDownNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusLeftNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusRightNavigationStrategyProperty;
+ (WXDependencyProperty*)tabIndexProperty;
+ (WXDependencyProperty*)isTabStopProperty;
- (EventRegistrationToken)addClickEvent:(void(^)(WUXDHyperlink*, WUXDHyperlinkClickEventArgs*))del;
- (void)removeClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGotFocusEvent:(WXRoutedEventHandler)del;
- (void)removeGotFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLostFocusEvent:(WXRoutedEventHandler)del;
- (void)removeLostFocusEvent:(EventRegistrationToken)tok;
- (BOOL)focus:(WXFocusState)value;
@end

#endif // __WUXDHyperlink_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Documents.HyperlinkClickEventArgs
#ifndef __WUXDHyperlinkClickEventArgs_DEFINED__
#define __WUXDHyperlinkClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDHyperlinkClickEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WUXDHyperlinkClickEventArgs_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides
#ifndef __WXIFrameworkElementOverrides_DEFINED__
#define __WXIFrameworkElementOverrides_DEFINED__

@protocol WXIFrameworkElementOverrides
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIFrameworkElementOverrides : RTObject <WXIFrameworkElementOverrides>
@end

#endif // __WXIFrameworkElementOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides2
#ifndef __WXIFrameworkElementOverrides2_DEFINED__
#define __WXIFrameworkElementOverrides2_DEFINED__

@protocol WXIFrameworkElementOverrides2
- (BOOL)goToElementStateCore:(NSString *)stateName useTransitions:(BOOL)useTransitions;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIFrameworkElementOverrides2 : RTObject <WXIFrameworkElementOverrides2>
@end

#endif // __WXIFrameworkElementOverrides2_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides
#ifndef __WXIUIElementOverrides_DEFINED__
#define __WXIUIElementOverrides_DEFINED__

@protocol WXIUIElementOverrides
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIUIElementOverrides : RTObject <WXIUIElementOverrides>
@end

#endif // __WXIUIElementOverrides_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides7
#ifndef __WXIUIElementOverrides7_DEFINED__
#define __WXIUIElementOverrides7_DEFINED__

@protocol WXIUIElementOverrides7
- (id<NSFastEnumeration> /* WXDependencyObject* */)getChildrenInTabFocusOrder;
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIUIElementOverrides7 : RTObject <WXIUIElementOverrides7>
@end

#endif // __WXIUIElementOverrides7_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXUIElement : WXDependencyObject
+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isTapEnabled;
@property (retain) WUXMProjection* projection;
@property BOOL isRightTapEnabled;
@property BOOL isHoldingEnabled;
@property BOOL isHitTestVisible;
@property BOOL isDoubleTapEnabled;
@property BOOL allowDrop;
@property WUXIManipulationModes manipulationMode;
@property (retain) WUXMRectangleGeometry* clip;
@property (retain) WUXMCacheMode* cacheMode;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (retain) WUXMATransitionCollection* transitions;
@property (retain) WFPoint* renderTransformOrigin;
@property (retain) WUXMTransform* renderTransform;
@property double opacity;
@property (readonly) WFSize* desiredSize;
@property (readonly) NSArray* /* WUXIPointer* */ pointerCaptures;
@property (readonly) WFSize* renderSize;
@property WUXMElementCompositeMode compositeMode;
@property (retain) WUXMMTransform3D* transform3D;
@property BOOL canDrag;
@property BOOL isAccessKeyScope;
@property BOOL exitDisplayModeOnAccessKeyInvoked;
@property (retain) WUXCPFlyoutBase* contextFlyout;
@property (retain) WXDependencyObject* accessKeyScopeOwner;
@property (retain) NSString * accessKey;
@property double keyTipHorizontalOffset;
@property WXElementHighContrastAdjustment highContrastAdjustment;
@property WUXIXYFocusNavigationStrategy xYFocusUpNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusRightNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusLeftNavigationStrategy;
@property WUXIXYFocusKeyboardNavigationMode xYFocusKeyboardNavigation;
@property WUXIXYFocusNavigationStrategy xYFocusDownNavigationStrategy;
@property WUXIKeyboardNavigationMode tabFocusNavigation;
@property double keyTipVerticalOffset;
@property WUXIKeyTipPlacementMode keyTipPlacementMode;
@property (readonly) NSMutableArray* /* WUXMXamlLight* */ lights;
@property (readonly) NSMutableArray* /* WUXIKeyboardAccelerator* */ keyboardAccelerators;
+ (WXDependencyProperty*)opacityProperty;
+ (WXDependencyProperty*)allowDropProperty;
+ (WXDependencyProperty*)cacheModeProperty;
+ (WXDependencyProperty*)clipProperty;
+ (WXRoutedEvent*)doubleTappedEvent;
+ (WXRoutedEvent*)dragEnterEvent;
+ (WXRoutedEvent*)dragLeaveEvent;
+ (WXRoutedEvent*)dragOverEvent;
+ (WXRoutedEvent*)dropEvent;
+ (WXRoutedEvent*)holdingEvent;
+ (WXDependencyProperty*)isDoubleTapEnabledProperty;
+ (WXDependencyProperty*)isHitTestVisibleProperty;
+ (WXDependencyProperty*)isHoldingEnabledProperty;
+ (WXDependencyProperty*)isRightTapEnabledProperty;
+ (WXDependencyProperty*)isTapEnabledProperty;
+ (WXRoutedEvent*)keyDownEvent;
+ (WXRoutedEvent*)keyUpEvent;
+ (WXRoutedEvent*)manipulationCompletedEvent;
+ (WXRoutedEvent*)manipulationDeltaEvent;
+ (WXRoutedEvent*)manipulationInertiaStartingEvent;
+ (WXDependencyProperty*)manipulationModeProperty;
+ (WXRoutedEvent*)manipulationStartedEvent;
+ (WXRoutedEvent*)manipulationStartingEvent;
+ (WXRoutedEvent*)pointerCanceledEvent;
+ (WXRoutedEvent*)pointerCaptureLostEvent;
+ (WXDependencyProperty*)pointerCapturesProperty;
+ (WXRoutedEvent*)pointerEnteredEvent;
+ (WXRoutedEvent*)pointerExitedEvent;
+ (WXRoutedEvent*)pointerMovedEvent;
+ (WXRoutedEvent*)pointerPressedEvent;
+ (WXRoutedEvent*)pointerReleasedEvent;
+ (WXRoutedEvent*)pointerWheelChangedEvent;
+ (WXDependencyProperty*)projectionProperty;
+ (WXDependencyProperty*)renderTransformOriginProperty;
+ (WXDependencyProperty*)renderTransformProperty;
+ (WXRoutedEvent*)rightTappedEvent;
+ (WXRoutedEvent*)tappedEvent;
+ (WXDependencyProperty*)transitionsProperty;
+ (WXDependencyProperty*)useLayoutRoundingProperty;
+ (WXDependencyProperty*)visibilityProperty;
+ (WXDependencyProperty*)compositeModeProperty;
+ (WXDependencyProperty*)transform3DProperty;
+ (WXDependencyProperty*)canDragProperty;
+ (WXDependencyProperty*)accessKeyProperty;
+ (WXDependencyProperty*)isAccessKeyScopeProperty;
+ (WXDependencyProperty*)exitDisplayModeOnAccessKeyInvokedProperty;
+ (WXDependencyProperty*)contextFlyoutProperty;
+ (WXDependencyProperty*)accessKeyScopeOwnerProperty;
+ (WXDependencyProperty*)xYFocusKeyboardNavigationProperty;
+ (WXDependencyProperty*)xYFocusLeftNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusRightNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusUpNavigationStrategyProperty;
+ (WXDependencyProperty*)highContrastAdjustmentProperty;
+ (WXDependencyProperty*)xYFocusDownNavigationStrategyProperty;
+ (WXDependencyProperty*)keyTipHorizontalOffsetProperty;
+ (WXDependencyProperty*)keyTipPlacementModeProperty;
+ (WXDependencyProperty*)keyTipVerticalOffsetProperty;
+ (WXDependencyProperty*)lightsProperty;
+ (WXDependencyProperty*)tabFocusNavigationProperty;
+ (WXRoutedEvent*)noFocusCandidateFoundEvent;
+ (WXRoutedEvent*)losingFocusEvent;
+ (WXRoutedEvent*)gettingFocusEvent;
+ (WXRoutedEvent*)characterReceivedEvent;
+ (WXRoutedEvent*)previewKeyUpEvent;
+ (WXRoutedEvent*)previewKeyDownEvent;
- (EventRegistrationToken)addDoubleTappedEvent:(WUXIDoubleTappedEventHandler)del;
- (void)removeDoubleTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragEnterEvent:(WXDragEventHandler)del;
- (void)removeDragEnterEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragLeaveEvent:(WXDragEventHandler)del;
- (void)removeDragLeaveEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragOverEvent:(WXDragEventHandler)del;
- (void)removeDragOverEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropEvent:(WXDragEventHandler)del;
- (void)removeDropEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGotFocusEvent:(WXRoutedEventHandler)del;
- (void)removeGotFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldingEvent:(WUXIHoldingEventHandler)del;
- (void)removeHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyDownEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLostFocusEvent:(WXRoutedEventHandler)del;
- (void)removeLostFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCompletedEvent:(WUXIManipulationCompletedEventHandler)del;
- (void)removeManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationDeltaEvent:(WUXIManipulationDeltaEventHandler)del;
- (void)removeManipulationDeltaEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationInertiaStartingEvent:(WUXIManipulationInertiaStartingEventHandler)del;
- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartedEvent:(WUXIManipulationStartedEventHandler)del;
- (void)removeManipulationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartingEvent:(WUXIManipulationStartingEventHandler)del;
- (void)removeManipulationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCanceledEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(WUXIPointerEventHandler)del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRightTappedEvent:(WUXIRightTappedEventHandler)del;
- (void)removeRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTappedEvent:(WUXITappedEventHandler)del;
- (void)removeTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragStartingEvent:(void(^)(WXUIElement*, WXDragStartingEventArgs*))del;
- (void)removeDragStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropCompletedEvent:(void(^)(WXUIElement*, WXDropCompletedEventArgs*))del;
- (void)removeDropCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayDismissedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))del;
- (void)removeAccessKeyDisplayDismissedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayRequestedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))del;
- (void)removeAccessKeyDisplayRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyInvokedEvent:(void(^)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))del;
- (void)removeAccessKeyInvokedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextCanceledEvent:(void(^)(WXUIElement*, WXRoutedEventArgs*))del;
- (void)removeContextCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextRequestedEvent:(void(^)(WXUIElement*, WUXIContextRequestedEventArgs*))del;
- (void)removeContextRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGettingFocusEvent:(void(^)(WXUIElement*, WUXIGettingFocusEventArgs*))del;
- (void)removeGettingFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLosingFocusEvent:(void(^)(WXUIElement*, WUXILosingFocusEventArgs*))del;
- (void)removeLosingFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNoFocusCandidateFoundEvent:(void(^)(WXUIElement*, WUXINoFocusCandidateFoundEventArgs*))del;
- (void)removeNoFocusCandidateFoundEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCharacterReceivedEvent:(void(^)(WXUIElement*, WUXICharacterReceivedRoutedEventArgs*))del;
- (void)removeCharacterReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviewKeyDownEvent:(WUXIKeyEventHandler)del;
- (void)removePreviewKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviewKeyUpEvent:(WUXIKeyEventHandler)del;
- (void)removePreviewKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProcessKeyboardAcceleratorsEvent:(void(^)(WXUIElement*, WUXIProcessKeyboardAcceleratorEventArgs*))del;
- (void)removeProcessKeyboardAcceleratorsEvent:(EventRegistrationToken)tok;
- (void)measure:(WFSize*)availableSize;
- (void)arrange:(WFRect*)finalRect;
- (BOOL)capturePointer:(WUXIPointer*)value;
- (void)releasePointerCapture:(WUXIPointer*)value;
- (void)releasePointerCaptures;
- (void)addHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler handledEventsToo:(BOOL)handledEventsToo;
- (void)removeHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler;
- (WUXMGeneralTransform*)transformToVisual:(WXUIElement*)visual;
- (void)invalidateMeasure;
- (void)invalidateArrange;
- (void)updateLayout;
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
- (BOOL)cancelDirectManipulations;
- (void)startDragAsync:(WUIPointerPoint*)pointerPoint success:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure;
- (void)startBringIntoView;
- (void)startBringIntoViewWithOptions:(WXBringIntoViewOptions*)options;
- (void)tryInvokeKeyboardAccelerator:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
- (id<NSFastEnumeration> /* WXDependencyObject* */)getChildrenInTabFocusOrder;
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXFrameworkElement : WXUIElement
+ (void)deferTree:(WXDependencyObject*)element;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double height;
@property WXFlowDirection flowDirection;
@property (retain) RTObject* dataContext;
@property (retain) NSString * name;
@property double minWidth;
@property (retain) WXResourceDictionary* resources;
@property double minHeight;
@property double maxWidth;
@property double maxHeight;
@property (retain) WXThickness* margin;
@property (retain) NSString * language;
@property WXHorizontalAlignment horizontalAlignment;
@property WXVerticalAlignment verticalAlignment;
@property double width;
@property (retain) RTObject* tag;
@property (retain) WXStyle* style;
@property (readonly) double actualWidth;
@property (readonly) WFUri* baseUri;
@property (readonly) double actualHeight;
@property (readonly) WXDependencyObject* parent;
@property (readonly) WXTriggerCollection* triggers;
@property WXElementTheme requestedTheme;
@property (retain) WXThickness* focusVisualSecondaryThickness;
@property (retain) WUXMBrush* focusVisualSecondaryBrush;
@property (retain) WXThickness* focusVisualPrimaryThickness;
@property (retain) WUXMBrush* focusVisualPrimaryBrush;
@property (retain) WXThickness* focusVisualMargin;
@property BOOL allowFocusWhenDisabled;
@property BOOL allowFocusOnInteraction;
@property (readonly) WXElementTheme actualTheme;
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)actualHeightProperty;
+ (WXDependencyProperty*)actualWidthProperty;
+ (WXDependencyProperty*)dataContextProperty;
+ (WXDependencyProperty*)flowDirectionProperty;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)horizontalAlignmentProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)minHeightProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
+ (WXDependencyProperty*)focusVisualSecondaryThicknessProperty;
+ (WXDependencyProperty*)allowFocusOnInteractionProperty;
+ (WXDependencyProperty*)allowFocusWhenDisabledProperty;
+ (WXDependencyProperty*)focusVisualMarginProperty;
+ (WXDependencyProperty*)focusVisualPrimaryBrushProperty;
+ (WXDependencyProperty*)focusVisualPrimaryThicknessProperty;
+ (WXDependencyProperty*)focusVisualSecondaryBrushProperty;
+ (WXDependencyProperty*)actualThemeProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void(^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingEvent:(void(^)(WXFrameworkElement*, RTObject*))del;
- (void)removeLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addActualThemeChangedEvent:(void(^)(WXFrameworkElement*, RTObject*))del;
- (void)removeActualThemeChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString *)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (BOOL)goToElementStateCore:(NSString *)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Documents.Glyphs
#ifndef __WUXDGlyphs_DEFINED__
#define __WUXDGlyphs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDGlyphs : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * unicodeString;
@property WUXMStyleSimulations styleSimulations;
@property double originY;
@property double originX;
@property (retain) NSString * indices;
@property (retain) WFUri* fontUri;
@property double fontRenderingEmSize;
@property (retain) WUXMBrush* fill;
@property BOOL isColorFontEnabled;
@property int colorFontPaletteIndex;
+ (WXDependencyProperty*)fillProperty;
+ (WXDependencyProperty*)fontRenderingEmSizeProperty;
+ (WXDependencyProperty*)fontUriProperty;
+ (WXDependencyProperty*)indicesProperty;
+ (WXDependencyProperty*)originXProperty;
+ (WXDependencyProperty*)originYProperty;
+ (WXDependencyProperty*)styleSimulationsProperty;
+ (WXDependencyProperty*)unicodeStringProperty;
+ (WXDependencyProperty*)colorFontPaletteIndexProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
@end

#endif // __WUXDGlyphs_DEFINED__

