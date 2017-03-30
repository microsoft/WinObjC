// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.UI.Xaml.Documents.1.h"
#include "Windows.UI.Xaml.1.h"
#include "Windows.UI.Xaml.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3ee78a34_160e_50ff_b5aa_09f263a669f8
#define WINRT_GENERIC_3ee78a34_160e_50ff_b5aa_09f263a669f8
template <> struct __declspec(uuid("3ee78a34-160e-50ff-b5aa-09f263a669f8")) __declspec(novtable) IVector<Windows::UI::Xaml::Documents::Block> : impl_IVector<Windows::UI::Xaml::Documents::Block> {};
#endif

#ifndef WINRT_GENERIC_f7023b9a_e6d1_5e2d_8f41_b28c33323e04
#define WINRT_GENERIC_f7023b9a_e6d1_5e2d_8f41_b28c33323e04
template <> struct __declspec(uuid("f7023b9a-e6d1-5e2d-8f41-b28c33323e04")) __declspec(novtable) IIterable<Windows::UI::Xaml::Documents::Block> : impl_IIterable<Windows::UI::Xaml::Documents::Block> {};
#endif

#ifndef WINRT_GENERIC_92ec9252_8ee3_55d6_84b4_30b635077778
#define WINRT_GENERIC_92ec9252_8ee3_55d6_84b4_30b635077778
template <> struct __declspec(uuid("92ec9252-8ee3-55d6-84b4-30b635077778")) __declspec(novtable) IVector<Windows::UI::Xaml::Documents::Inline> : impl_IVector<Windows::UI::Xaml::Documents::Inline> {};
#endif

#ifndef WINRT_GENERIC_e1d2b910_18c2_5906_8f8a_d62a63f93f18
#define WINRT_GENERIC_e1d2b910_18c2_5906_8f8a_d62a63f93f18
template <> struct __declspec(uuid("e1d2b910-18c2-5906-8f8a-d62a63f93f18")) __declspec(novtable) IIterable<Windows::UI::Xaml::Documents::Inline> : impl_IIterable<Windows::UI::Xaml::Documents::Inline> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_5fead0d2_e657_5aef_a91b_7f52ead17fe3
#define WINRT_GENERIC_5fead0d2_e657_5aef_a91b_7f52ead17fe3
template <> struct __declspec(uuid("5fead0d2-e657-5aef-a91b-7f52ead17fe3")) __declspec(novtable) TypedEventHandler<Windows::UI::Xaml::Documents::Hyperlink, Windows::UI::Xaml::Documents::HyperlinkClickEventArgs> : impl_TypedEventHandler<Windows::UI::Xaml::Documents::Hyperlink, Windows::UI::Xaml::Documents::HyperlinkClickEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_798d518e_a9f8_5fc7_8ccc_2a49069aba05
#define WINRT_GENERIC_798d518e_a9f8_5fc7_8ccc_2a49069aba05
template <> struct __declspec(uuid("798d518e-a9f8-5fc7-8ccc-2a49069aba05")) __declspec(novtable) IIterator<Windows::UI::Xaml::Documents::Block> : impl_IIterator<Windows::UI::Xaml::Documents::Block> {};
#endif

#ifndef WINRT_GENERIC_995f73c4_7cf8_5b59_a0fb_7e0c6477172e
#define WINRT_GENERIC_995f73c4_7cf8_5b59_a0fb_7e0c6477172e
template <> struct __declspec(uuid("995f73c4-7cf8-5b59-a0fb-7e0c6477172e")) __declspec(novtable) IVectorView<Windows::UI::Xaml::Documents::Block> : impl_IVectorView<Windows::UI::Xaml::Documents::Block> {};
#endif

#ifndef WINRT_GENERIC_f80dc964_2542_5c6a_ba65_b04824b5ed75
#define WINRT_GENERIC_f80dc964_2542_5c6a_ba65_b04824b5ed75
template <> struct __declspec(uuid("f80dc964-2542-5c6a-ba65-b04824b5ed75")) __declspec(novtable) IIterator<Windows::UI::Xaml::Documents::Inline> : impl_IIterator<Windows::UI::Xaml::Documents::Inline> {};
#endif

#ifndef WINRT_GENERIC_c2dd082f_8cb4_51d6_b91b_7e2377780cee
#define WINRT_GENERIC_c2dd082f_8cb4_51d6_b91b_7e2377780cee
template <> struct __declspec(uuid("c2dd082f-8cb4-51d6-b91b-7e2377780cee")) __declspec(novtable) IVectorView<Windows::UI::Xaml::Documents::Inline> : impl_IVectorView<Windows::UI::Xaml::Documents::Inline> {};
#endif


}

namespace Windows::UI::Xaml::Documents {

struct IBlock :
    Windows::Foundation::IInspectable,
    impl::consume<IBlock>
{
    IBlock(std::nullptr_t = nullptr) noexcept {}
};

struct IBlockFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IBlockFactory>
{
    IBlockFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IBlockStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IBlockStatics>
{
    IBlockStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IBold :
    Windows::Foundation::IInspectable,
    impl::consume<IBold>
{
    IBold(std::nullptr_t = nullptr) noexcept {}
};

struct IGlyphs :
    Windows::Foundation::IInspectable,
    impl::consume<IGlyphs>
{
    IGlyphs(std::nullptr_t = nullptr) noexcept {}
};

struct IGlyphs2 :
    Windows::Foundation::IInspectable,
    impl::consume<IGlyphs2>
{
    IGlyphs2(std::nullptr_t = nullptr) noexcept {}
};

struct IGlyphsStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGlyphsStatics>
{
    IGlyphsStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IGlyphsStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IGlyphsStatics2>
{
    IGlyphsStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IHyperlink :
    Windows::Foundation::IInspectable,
    impl::consume<IHyperlink>
{
    IHyperlink(std::nullptr_t = nullptr) noexcept {}
};

struct IHyperlink2 :
    Windows::Foundation::IInspectable,
    impl::consume<IHyperlink2>
{
    IHyperlink2(std::nullptr_t = nullptr) noexcept {}
};

struct IHyperlink3 :
    Windows::Foundation::IInspectable,
    impl::consume<IHyperlink3>
{
    IHyperlink3(std::nullptr_t = nullptr) noexcept {}
};

struct IHyperlinkClickEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IHyperlinkClickEventArgs>
{
    IHyperlinkClickEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IHyperlinkStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IHyperlinkStatics>
{
    IHyperlinkStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHyperlinkStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<IHyperlinkStatics2>
{
    IHyperlinkStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct IHyperlinkStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<IHyperlinkStatics3>
{
    IHyperlinkStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct IInline :
    Windows::Foundation::IInspectable,
    impl::consume<IInline>
{
    IInline(std::nullptr_t = nullptr) noexcept {}
};

struct IInlineFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IInlineFactory>
{
    IInlineFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IInlineUIContainer :
    Windows::Foundation::IInspectable,
    impl::consume<IInlineUIContainer>
{
    IInlineUIContainer(std::nullptr_t = nullptr) noexcept {}
};

struct IItalic :
    Windows::Foundation::IInspectable,
    impl::consume<IItalic>
{
    IItalic(std::nullptr_t = nullptr) noexcept {}
};

struct ILineBreak :
    Windows::Foundation::IInspectable,
    impl::consume<ILineBreak>
{
    ILineBreak(std::nullptr_t = nullptr) noexcept {}
};

struct IParagraph :
    Windows::Foundation::IInspectable,
    impl::consume<IParagraph>
{
    IParagraph(std::nullptr_t = nullptr) noexcept {}
};

struct IParagraphStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IParagraphStatics>
{
    IParagraphStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IRun :
    Windows::Foundation::IInspectable,
    impl::consume<IRun>
{
    IRun(std::nullptr_t = nullptr) noexcept {}
};

struct IRunStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IRunStatics>
{
    IRunStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpan :
    Windows::Foundation::IInspectable,
    impl::consume<ISpan>
{
    ISpan(std::nullptr_t = nullptr) noexcept {}
};

struct ISpanFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISpanFactory>
{
    ISpanFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElement :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElement>
{
    ITextElement(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElement2 :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElement2>
{
    ITextElement2(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElement3 :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElement3>
{
    ITextElement3(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElementFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElementFactory>
{
    ITextElementFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElementOverrides :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElementOverrides>
{
    ITextElementOverrides(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElementStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElementStatics>
{
    ITextElementStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElementStatics2 :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElementStatics2>
{
    ITextElementStatics2(std::nullptr_t = nullptr) noexcept {}
};

struct ITextElementStatics3 :
    Windows::Foundation::IInspectable,
    impl::consume<ITextElementStatics3>
{
    ITextElementStatics3(std::nullptr_t = nullptr) noexcept {}
};

struct ITextPointer :
    Windows::Foundation::IInspectable,
    impl::consume<ITextPointer>
{
    ITextPointer(std::nullptr_t = nullptr) noexcept {}
};

struct ITypography :
    Windows::Foundation::IInspectable,
    impl::consume<ITypography>
{
    ITypography(std::nullptr_t = nullptr) noexcept {}
};

struct ITypographyStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ITypographyStatics>
{
    ITypographyStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IUnderline :
    Windows::Foundation::IInspectable,
    impl::consume<IUnderline>
{
    IUnderline(std::nullptr_t = nullptr) noexcept {}
};

}

}
