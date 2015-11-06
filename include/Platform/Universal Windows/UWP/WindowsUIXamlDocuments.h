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

// WindowsUIXamlDocuments.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXDBlockCollection, WUXDInlineCollection, WUXDTextPointer, WUXDTypography, WUXDTextElement, WUXDBlock, WUXDInline,
    WUXDInlineUIContainer, WUXDLineBreak, WUXDParagraph, WUXDRun, WUXDSpan, WUXDBold, WUXDItalic, WUXDUnderline, WUXDHyperlink,
    WUXDHyperlinkClickEventArgs, WUXDGlyphs;
@protocol WUXDITextPointer
, WUXDITypography, WUXDITypographyStatics, WUXDITextElement, WUXDITextElementOverrides, WUXDITextElementStatics, WUXDITextElementFactory,
    WUXDITextElement2, WUXDITextElementStatics2, WUXDIBlock, WUXDIBlockStatics, WUXDIBlockFactory, WUXDIInline, WUXDIInlineFactory,
    WUXDIInlineUIContainer, WUXDILineBreak, WUXDIParagraph, WUXDIParagraphStatics, WUXDIRun, WUXDIRunStatics, WUXDISpan, WUXDISpanFactory,
    WUXDIBold, WUXDIItalic, WUXDIUnderline, WUXDIHyperlinkClickEventArgs, WUXDIGlyphs, WUXDIGlyphsStatics, WUXDIGlyphs2,
    WUXDIGlyphsStatics2, WUXDIHyperlink, WUXDIHyperlinkStatics, WUXDIHyperlink2, WUXDIHyperlinkStatics2;

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

#include "WindowsFoundationCollections.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIXaml.h"
#include "WindowsFoundation.h"
#include "WindowsUIText.h"
#include "WindowsUICore.h"
#include "WindowsUIXamlData.h"
#include "WindowsUIInput.h"
#include "WindowsUIXamlAutomationPeers.h"
#include "WindowsUIXamlMediaMedia3D.h"
// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void (^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void (^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void (^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void (^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void (^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void (^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void (^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void (^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void (^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void (^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void (^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void (^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void (^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void (^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void (^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED

#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Documents.ITextElementOverrides
#ifndef __WUXDITextElementOverrides_DEFINED__
#define __WUXDITextElementOverrides_DEFINED__

@protocol WUXDITextElementOverrides
- (void)onDisconnectVisualChildren;
@end

#endif // __WUXDITextElementOverrides_DEFINED__

// Windows.UI.Xaml.Documents.BlockCollection
#ifndef __WUXDBlockCollection_DEFINED__
#define __WUXDBlockCollection_DEFINED__

WINRT_EXPORT
@interface WUXDBlockCollection : RTObject
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXDBlockCollection_DEFINED__

// Windows.UI.Xaml.Documents.InlineCollection
#ifndef __WUXDInlineCollection_DEFINED__
#define __WUXDInlineCollection_DEFINED__

WINRT_EXPORT
@interface WUXDInlineCollection : RTObject
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState*)state objects:(id __unsafe_unretained[])buffer count:(NSUInteger)len;

- (void)insertObject:(id)obj atIndex:(NSUInteger)idx;
- (void)removeObjectAtIndex:(NSUInteger)idx;
- (void)replaceObjectAtIndex:(NSUInteger)idx withObject:(id)obj;
- (void)addObject:(id)obj;
- (void)removeLastObject;

@end

#endif // __WUXDInlineCollection_DEFINED__

// Windows.UI.Xaml.Documents.TextPointer
#ifndef __WUXDTextPointer_DEFINED__
#define __WUXDTextPointer_DEFINED__

WINRT_EXPORT
@interface WUXDTextPointer : RTObject
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

WINRT_EXPORT
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

WINRT_EXPORT
@interface WXDependencyObject : RTObject
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WUXDTextElement : WXDependencyObject
@property (copy) NSString* language;
@property (copy) WUXMBrush* foreground;
@property (copy) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property (copy) WUXMFontFamily* fontFamily;
@property double fontSize;
@property WUTFontStretch fontStretch;
@property int characterSpacing;
@property (readonly) WUXDTextPointer* contentStart;
@property (readonly) WUXDTextPointer* elementEnd;
@property (readonly) WUXDTextPointer* elementStart;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) NSString* name;
@property BOOL isTextScaleFactorEnabled;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
- (RTObject*)findName:(NSString*)name;
- (void)onDisconnectVisualChildren;
@end

#endif // __WUXDTextElement_DEFINED__

// Windows.UI.Xaml.Documents.Block
#ifndef __WUXDBlock_DEFINED__
#define __WUXDBlock_DEFINED__

WINRT_EXPORT
@interface WUXDBlock : WUXDTextElement
+ (instancetype)create ACTIVATOR;
@property WXTextAlignment textAlignment;
@property (copy) WXThickness* margin;
@property WXLineStackingStrategy lineStackingStrategy;
@property double lineHeight;
+ (WXDependencyProperty*)lineHeightProperty;
+ (WXDependencyProperty*)lineStackingStrategyProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
@end

#endif // __WUXDBlock_DEFINED__

// Windows.UI.Xaml.Documents.Inline
#ifndef __WUXDInline_DEFINED__
#define __WUXDInline_DEFINED__

WINRT_EXPORT
@interface WUXDInline : WUXDTextElement
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXDInline_DEFINED__

// Windows.UI.Xaml.Documents.InlineUIContainer
#ifndef __WUXDInlineUIContainer_DEFINED__
#define __WUXDInlineUIContainer_DEFINED__

WINRT_EXPORT
@interface WUXDInlineUIContainer : WUXDInline
+ (instancetype)create ACTIVATOR;
@property (copy) WXUIElement* child;
@end

#endif // __WUXDInlineUIContainer_DEFINED__

// Windows.UI.Xaml.Documents.LineBreak
#ifndef __WUXDLineBreak_DEFINED__
#define __WUXDLineBreak_DEFINED__

WINRT_EXPORT
@interface WUXDLineBreak : WUXDInline
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXDLineBreak_DEFINED__

// Windows.UI.Xaml.Documents.Paragraph
#ifndef __WUXDParagraph_DEFINED__
#define __WUXDParagraph_DEFINED__

WINRT_EXPORT
@interface WUXDParagraph : WUXDBlock
+ (instancetype)create ACTIVATOR;
@property double textIndent;
@property (readonly) WUXDInlineCollection* inlines;
+ (WXDependencyProperty*)textIndentProperty;
@end

#endif // __WUXDParagraph_DEFINED__

// Windows.UI.Xaml.Documents.Run
#ifndef __WUXDRun_DEFINED__
#define __WUXDRun_DEFINED__

WINRT_EXPORT
@interface WUXDRun : WUXDInline
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* text;
@property WXFlowDirection flowDirection;
+ (WXDependencyProperty*)flowDirectionProperty;
@end

#endif // __WUXDRun_DEFINED__

// Windows.UI.Xaml.Documents.Span
#ifndef __WUXDSpan_DEFINED__
#define __WUXDSpan_DEFINED__

WINRT_EXPORT
@interface WUXDSpan : WUXDInline
+ (instancetype)create ACTIVATOR;
@property (copy) WUXDInlineCollection* inlines;
@end

#endif // __WUXDSpan_DEFINED__

// Windows.UI.Xaml.Documents.Bold
#ifndef __WUXDBold_DEFINED__
#define __WUXDBold_DEFINED__

WINRT_EXPORT
@interface WUXDBold : WUXDSpan
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXDBold_DEFINED__

// Windows.UI.Xaml.Documents.Italic
#ifndef __WUXDItalic_DEFINED__
#define __WUXDItalic_DEFINED__

WINRT_EXPORT
@interface WUXDItalic : WUXDSpan
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXDItalic_DEFINED__

// Windows.UI.Xaml.Documents.Underline
#ifndef __WUXDUnderline_DEFINED__
#define __WUXDUnderline_DEFINED__

WINRT_EXPORT
@interface WUXDUnderline : WUXDSpan
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXDUnderline_DEFINED__

// Windows.UI.Xaml.Documents.Hyperlink
#ifndef __WUXDHyperlink_DEFINED__
#define __WUXDHyperlink_DEFINED__

WINRT_EXPORT
@interface WUXDHyperlink : WUXDSpan
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* navigateUri;
@property WUXDUnderlineStyle underlineStyle;
+ (WXDependencyProperty*)navigateUriProperty;
+ (WXDependencyProperty*)underlineStyleProperty;
- (EventRegistrationToken)addClickEvent:(void (^)(WUXDHyperlink*, WUXDHyperlinkClickEventArgs*))del;
- (void)removeClickEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXDHyperlink_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Documents.HyperlinkClickEventArgs
#ifndef __WUXDHyperlinkClickEventArgs_DEFINED__
#define __WUXDHyperlinkClickEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXDHyperlinkClickEventArgs : WXRoutedEventArgs
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

#endif // __WXIFrameworkElementOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides2
#ifndef __WXIFrameworkElementOverrides2_DEFINED__
#define __WXIFrameworkElementOverrides2_DEFINED__

@protocol WXIFrameworkElementOverrides2
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXIFrameworkElementOverrides2_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides
#ifndef __WXIUIElementOverrides_DEFINED__
#define __WXIUIElementOverrides_DEFINED__

@protocol WXIUIElementOverrides
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration>)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
@end

#endif // __WXIUIElementOverrides_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

WINRT_EXPORT
@interface WXUIElement : WXDependencyObject
+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value;
@property BOOL isRightTapEnabled;
@property (copy) WUXMProjection* projection;
@property BOOL allowDrop;
@property BOOL isHitTestVisible;
@property double opacity;
@property (copy) WUXMCacheMode* cacheMode;
@property BOOL isDoubleTapEnabled;
@property BOOL isTapEnabled;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (copy) WUXMRectangleGeometry* clip;
@property (copy) WUXMATransitionCollection* transitions;
@property (copy) WFPoint* renderTransformOrigin;
@property (copy) WUXMTransform* renderTransform;
@property BOOL isHoldingEnabled;
@property WUXIManipulationModes manipulationMode;
@property (readonly) WFSize* renderSize;
@property (readonly) NSArray* pointerCaptures;
@property (readonly) WFSize* desiredSize;
@property WUXMElementCompositeMode compositeMode;
@property (copy) WUXMMTransform3D* transform3D;
@property BOOL canDrag;
+ (WXRoutedEvent*)dropEvent;
+ (WXDependencyProperty*)allowDropProperty;
+ (WXDependencyProperty*)cacheModeProperty;
+ (WXDependencyProperty*)clipProperty;
+ (WXRoutedEvent*)doubleTappedEvent;
+ (WXRoutedEvent*)dragEnterEvent;
+ (WXRoutedEvent*)dragLeaveEvent;
+ (WXRoutedEvent*)dragOverEvent;
+ (WXRoutedEvent*)pointerCanceledEvent;
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
+ (WXDependencyProperty*)opacityProperty;
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
- (EventRegistrationToken)addDragStartingEvent:(void (^)(WXUIElement*, WXDragStartingEventArgs*))del;
- (void)removeDragStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropCompletedEvent:(void (^)(WXUIElement*, WXDropCompletedEventArgs*))del;
- (void)removeDropCompletedEvent:(EventRegistrationToken)tok;
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
- (id<NSFastEnumeration>)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
- (BOOL)cancelDirectManipulations;
- (void)startDragAsync:(WUIPointerPoint*)pointerPoint
               success:(void (^)(WADDataPackageOperation))success
               failure:(void (^)(NSError*))failure;
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

WINRT_EXPORT
@interface WXFrameworkElement : WXUIElement
+ (instancetype)create ACTIVATOR;
@property (copy) WXThickness* margin;
@property (copy) NSString* language;
@property WXHorizontalAlignment horizontalAlignment;
@property double height;
@property WXFlowDirection flowDirection;
@property (copy) RTObject* dataContext;
@property WXVerticalAlignment verticalAlignment;
@property double maxWidth;
@property double maxHeight;
@property double minHeight;
@property double width;
@property (copy) RTObject* tag;
@property (copy) WXStyle* style;
@property (copy) WXResourceDictionary* resources;
@property (copy) NSString* name;
@property double minWidth;
@property (readonly) double actualWidth;
@property (readonly) WFUri* baseUri;
@property (readonly) WXTriggerCollection* triggers;
@property (readonly) double actualHeight;
@property (readonly) WXDependencyObject* parent;
@property WXElementTheme requestedTheme;
+ (WXDependencyProperty*)flowDirectionProperty;
+ (WXDependencyProperty*)actualHeightProperty;
+ (WXDependencyProperty*)actualWidthProperty;
+ (WXDependencyProperty*)dataContextProperty;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)horizontalAlignmentProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)minHeightProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void (^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingEvent:(void (^)(WXFrameworkElement*, RTObject*))del;
- (void)removeLoadingEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString*)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Documents.Glyphs
#ifndef __WUXDGlyphs_DEFINED__
#define __WUXDGlyphs_DEFINED__

WINRT_EXPORT
@interface WUXDGlyphs : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* unicodeString;
@property WUXMStyleSimulations styleSimulations;
@property double originY;
@property double originX;
@property (copy) NSString* indices;
@property (copy) WFUri* fontUri;
@property double fontRenderingEmSize;
@property (copy) WUXMBrush* fill;
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
