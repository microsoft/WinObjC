// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Documents.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Documents {

struct WINRT_EBO Block :
    Windows::UI::Xaml::Documents::IBlock,
    impl::bases<Block, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement>,
    impl::require<Block, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Block(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty TextAlignmentProperty();
    static Windows::UI::Xaml::DependencyProperty LineHeightProperty();
    static Windows::UI::Xaml::DependencyProperty LineStackingStrategyProperty();
    static Windows::UI::Xaml::DependencyProperty MarginProperty();
};

struct WINRT_EBO BlockCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Documents::Block>
{
    BlockCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Bold :
    Windows::UI::Xaml::Documents::IBold,
    impl::bases<Bold, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline, Windows::UI::Xaml::Documents::Span>,
    impl::require<Bold, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Bold(std::nullptr_t) noexcept {}
    Bold();
};

struct WINRT_EBO Glyphs :
    Windows::UI::Xaml::Documents::IGlyphs,
    impl::bases<Glyphs, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::UIElement, Windows::UI::Xaml::FrameworkElement>,
    impl::require<Glyphs, Windows::UI::Xaml::Documents::IGlyphs2, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2, Windows::UI::Xaml::IUIElement, Windows::UI::Xaml::IUIElementOverrides, Windows::UI::Xaml::IUIElement2, Windows::UI::Xaml::IUIElement3, Windows::UI::Xaml::IUIElement4, Windows::UI::Xaml::IFrameworkElement, Windows::UI::Xaml::IFrameworkElementOverrides, Windows::UI::Xaml::IFrameworkElement2, Windows::UI::Xaml::IFrameworkElementOverrides2, Windows::UI::Xaml::IFrameworkElement3, Windows::UI::Xaml::IFrameworkElement4>
{
    Glyphs(std::nullptr_t) noexcept {}
    Glyphs();
    static Windows::UI::Xaml::DependencyProperty UnicodeStringProperty();
    static Windows::UI::Xaml::DependencyProperty IndicesProperty();
    static Windows::UI::Xaml::DependencyProperty FontUriProperty();
    static Windows::UI::Xaml::DependencyProperty StyleSimulationsProperty();
    static Windows::UI::Xaml::DependencyProperty FontRenderingEmSizeProperty();
    static Windows::UI::Xaml::DependencyProperty OriginXProperty();
    static Windows::UI::Xaml::DependencyProperty OriginYProperty();
    static Windows::UI::Xaml::DependencyProperty FillProperty();
    static Windows::UI::Xaml::DependencyProperty IsColorFontEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty ColorFontPaletteIndexProperty();
};

struct WINRT_EBO Hyperlink :
    Windows::UI::Xaml::Documents::IHyperlink,
    impl::bases<Hyperlink, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline, Windows::UI::Xaml::Documents::Span>,
    impl::require<Hyperlink, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan, Windows::UI::Xaml::Documents::IHyperlink2, Windows::UI::Xaml::Documents::IHyperlink3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Hyperlink(std::nullptr_t) noexcept {}
    Hyperlink();
    static Windows::UI::Xaml::DependencyProperty NavigateUriProperty();
    static Windows::UI::Xaml::DependencyProperty UnderlineStyleProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusLeftProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusRightProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusUpProperty();
    static Windows::UI::Xaml::DependencyProperty XYFocusDownProperty();
    static Windows::UI::Xaml::DependencyProperty ElementSoundModeProperty();
};

struct WINRT_EBO HyperlinkClickEventArgs :
    Windows::UI::Xaml::Documents::IHyperlinkClickEventArgs,
    impl::bases<HyperlinkClickEventArgs, Windows::UI::Xaml::RoutedEventArgs>,
    impl::require<HyperlinkClickEventArgs, Windows::UI::Xaml::IRoutedEventArgs>
{
    HyperlinkClickEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Inline :
    Windows::UI::Xaml::Documents::IInline,
    impl::bases<Inline, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement>,
    impl::require<Inline, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Inline(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InlineCollection :
    Windows::Foundation::Collections::IVector<Windows::UI::Xaml::Documents::Inline>
{
    InlineCollection(std::nullptr_t) noexcept {}
};

struct WINRT_EBO InlineUIContainer :
    Windows::UI::Xaml::Documents::IInlineUIContainer,
    impl::bases<InlineUIContainer, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline>,
    impl::require<InlineUIContainer, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    InlineUIContainer(std::nullptr_t) noexcept {}
    InlineUIContainer();
};

struct WINRT_EBO Italic :
    Windows::UI::Xaml::Documents::IItalic,
    impl::bases<Italic, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline, Windows::UI::Xaml::Documents::Span>,
    impl::require<Italic, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Italic(std::nullptr_t) noexcept {}
    Italic();
};

struct WINRT_EBO LineBreak :
    Windows::UI::Xaml::Documents::ILineBreak,
    impl::bases<LineBreak, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline>,
    impl::require<LineBreak, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    LineBreak(std::nullptr_t) noexcept {}
    LineBreak();
};

struct WINRT_EBO Paragraph :
    Windows::UI::Xaml::Documents::IParagraph,
    impl::bases<Paragraph, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Block>,
    impl::require<Paragraph, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IBlock, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Paragraph(std::nullptr_t) noexcept {}
    Paragraph();
    static Windows::UI::Xaml::DependencyProperty TextIndentProperty();
};

struct WINRT_EBO Run :
    Windows::UI::Xaml::Documents::IRun,
    impl::bases<Run, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline>,
    impl::require<Run, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Run(std::nullptr_t) noexcept {}
    Run();
    static Windows::UI::Xaml::DependencyProperty FlowDirectionProperty();
};

struct WINRT_EBO Span :
    Windows::UI::Xaml::Documents::ISpan,
    impl::bases<Span, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline>,
    impl::require<Span, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Span(std::nullptr_t) noexcept {}
    Span();
};

struct WINRT_EBO TextElement :
    Windows::UI::Xaml::Documents::ITextElement,
    impl::bases<TextElement, Windows::UI::Xaml::DependencyObject>,
    impl::require<TextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    TextElement(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty FontSizeProperty();
    static Windows::UI::Xaml::DependencyProperty FontFamilyProperty();
    static Windows::UI::Xaml::DependencyProperty FontWeightProperty();
    static Windows::UI::Xaml::DependencyProperty FontStyleProperty();
    static Windows::UI::Xaml::DependencyProperty FontStretchProperty();
    static Windows::UI::Xaml::DependencyProperty CharacterSpacingProperty();
    static Windows::UI::Xaml::DependencyProperty ForegroundProperty();
    static Windows::UI::Xaml::DependencyProperty LanguageProperty();
    static Windows::UI::Xaml::DependencyProperty IsTextScaleFactorEnabledProperty();
    static Windows::UI::Xaml::DependencyProperty AllowFocusOnInteractionProperty();
    static Windows::UI::Xaml::DependencyProperty AccessKeyProperty();
    static Windows::UI::Xaml::DependencyProperty ExitDisplayModeOnAccessKeyInvokedProperty();
};

struct WINRT_EBO TextPointer :
    Windows::UI::Xaml::Documents::ITextPointer
{
    TextPointer(std::nullptr_t) noexcept {}
};

struct WINRT_EBO Typography :
    Windows::UI::Xaml::Documents::ITypography
{
    Typography(std::nullptr_t) noexcept {}
    static Windows::UI::Xaml::DependencyProperty AnnotationAlternatesProperty();
    static int32_t GetAnnotationAlternates(const Windows::UI::Xaml::DependencyObject & element);
    static void SetAnnotationAlternates(const Windows::UI::Xaml::DependencyObject & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty EastAsianExpertFormsProperty();
    static bool GetEastAsianExpertForms(const Windows::UI::Xaml::DependencyObject & element);
    static void SetEastAsianExpertForms(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty EastAsianLanguageProperty();
    static Windows::UI::Xaml::FontEastAsianLanguage GetEastAsianLanguage(const Windows::UI::Xaml::DependencyObject & element);
    static void SetEastAsianLanguage(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontEastAsianLanguage value);
    static Windows::UI::Xaml::DependencyProperty EastAsianWidthsProperty();
    static Windows::UI::Xaml::FontEastAsianWidths GetEastAsianWidths(const Windows::UI::Xaml::DependencyObject & element);
    static void SetEastAsianWidths(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontEastAsianWidths value);
    static Windows::UI::Xaml::DependencyProperty StandardLigaturesProperty();
    static bool GetStandardLigatures(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStandardLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty ContextualLigaturesProperty();
    static bool GetContextualLigatures(const Windows::UI::Xaml::DependencyObject & element);
    static void SetContextualLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty DiscretionaryLigaturesProperty();
    static bool GetDiscretionaryLigatures(const Windows::UI::Xaml::DependencyObject & element);
    static void SetDiscretionaryLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty HistoricalLigaturesProperty();
    static bool GetHistoricalLigatures(const Windows::UI::Xaml::DependencyObject & element);
    static void SetHistoricalLigatures(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StandardSwashesProperty();
    static int32_t GetStandardSwashes(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStandardSwashes(const Windows::UI::Xaml::DependencyObject & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty ContextualSwashesProperty();
    static int32_t GetContextualSwashes(const Windows::UI::Xaml::DependencyObject & element);
    static void SetContextualSwashes(const Windows::UI::Xaml::DependencyObject & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty ContextualAlternatesProperty();
    static bool GetContextualAlternates(const Windows::UI::Xaml::DependencyObject & element);
    static void SetContextualAlternates(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticAlternatesProperty();
    static int32_t GetStylisticAlternates(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticAlternates(const Windows::UI::Xaml::DependencyObject & element, int32_t value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet1Property();
    static bool GetStylisticSet1(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet1(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet2Property();
    static bool GetStylisticSet2(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet2(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet3Property();
    static bool GetStylisticSet3(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet3(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet4Property();
    static bool GetStylisticSet4(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet4(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet5Property();
    static bool GetStylisticSet5(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet5(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet6Property();
    static bool GetStylisticSet6(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet6(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet7Property();
    static bool GetStylisticSet7(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet7(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet8Property();
    static bool GetStylisticSet8(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet8(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet9Property();
    static bool GetStylisticSet9(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet9(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet10Property();
    static bool GetStylisticSet10(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet10(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet11Property();
    static bool GetStylisticSet11(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet11(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet12Property();
    static bool GetStylisticSet12(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet12(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet13Property();
    static bool GetStylisticSet13(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet13(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet14Property();
    static bool GetStylisticSet14(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet14(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet15Property();
    static bool GetStylisticSet15(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet15(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet16Property();
    static bool GetStylisticSet16(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet16(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet17Property();
    static bool GetStylisticSet17(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet17(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet18Property();
    static bool GetStylisticSet18(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet18(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet19Property();
    static bool GetStylisticSet19(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet19(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty StylisticSet20Property();
    static bool GetStylisticSet20(const Windows::UI::Xaml::DependencyObject & element);
    static void SetStylisticSet20(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty CapitalsProperty();
    static Windows::UI::Xaml::FontCapitals GetCapitals(const Windows::UI::Xaml::DependencyObject & element);
    static void SetCapitals(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontCapitals value);
    static Windows::UI::Xaml::DependencyProperty CapitalSpacingProperty();
    static bool GetCapitalSpacing(const Windows::UI::Xaml::DependencyObject & element);
    static void SetCapitalSpacing(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty KerningProperty();
    static bool GetKerning(const Windows::UI::Xaml::DependencyObject & element);
    static void SetKerning(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty CaseSensitiveFormsProperty();
    static bool GetCaseSensitiveForms(const Windows::UI::Xaml::DependencyObject & element);
    static void SetCaseSensitiveForms(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty HistoricalFormsProperty();
    static bool GetHistoricalForms(const Windows::UI::Xaml::DependencyObject & element);
    static void SetHistoricalForms(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty FractionProperty();
    static Windows::UI::Xaml::FontFraction GetFraction(const Windows::UI::Xaml::DependencyObject & element);
    static void SetFraction(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontFraction value);
    static Windows::UI::Xaml::DependencyProperty NumeralStyleProperty();
    static Windows::UI::Xaml::FontNumeralStyle GetNumeralStyle(const Windows::UI::Xaml::DependencyObject & element);
    static void SetNumeralStyle(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontNumeralStyle value);
    static Windows::UI::Xaml::DependencyProperty NumeralAlignmentProperty();
    static Windows::UI::Xaml::FontNumeralAlignment GetNumeralAlignment(const Windows::UI::Xaml::DependencyObject & element);
    static void SetNumeralAlignment(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontNumeralAlignment value);
    static Windows::UI::Xaml::DependencyProperty SlashedZeroProperty();
    static bool GetSlashedZero(const Windows::UI::Xaml::DependencyObject & element);
    static void SetSlashedZero(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty MathematicalGreekProperty();
    static bool GetMathematicalGreek(const Windows::UI::Xaml::DependencyObject & element);
    static void SetMathematicalGreek(const Windows::UI::Xaml::DependencyObject & element, bool value);
    static Windows::UI::Xaml::DependencyProperty VariantsProperty();
    static Windows::UI::Xaml::FontVariants GetVariants(const Windows::UI::Xaml::DependencyObject & element);
    static void SetVariants(const Windows::UI::Xaml::DependencyObject & element, Windows::UI::Xaml::FontVariants value);
};

struct WINRT_EBO Underline :
    Windows::UI::Xaml::Documents::IUnderline,
    impl::bases<Underline, Windows::UI::Xaml::DependencyObject, Windows::UI::Xaml::Documents::TextElement, Windows::UI::Xaml::Documents::Inline, Windows::UI::Xaml::Documents::Span>,
    impl::require<Underline, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElementOverrides, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    Underline(std::nullptr_t) noexcept {}
    Underline();
};

}

}
