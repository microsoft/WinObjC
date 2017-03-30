// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Documents {

template <typename D, typename ... Interfaces> struct BlockT :
    overrides<D, Windows::UI::Xaml::Documents::ITextElementOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IBlock, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = Block;

protected:

    BlockT()
    {
        get_activation_factory<Block, IBlockFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct InlineT :
    overrides<D, Windows::UI::Xaml::Documents::ITextElementOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = Inline;

protected:

    InlineT()
    {
        get_activation_factory<Inline, IInlineFactory>().CreateInstance(*this, this->m_inner);
    }
};

template <typename D, typename ... Interfaces> struct SpanT :
    overrides<D, Windows::UI::Xaml::Documents::ITextElementOverridesT<D>, Interfaces ...>,
    impl::require<D, Windows::UI::Xaml::Documents::ITextElement, Windows::UI::Xaml::Documents::ITextElement2, Windows::UI::Xaml::Documents::ITextElement3, Windows::UI::Xaml::Documents::IInline, Windows::UI::Xaml::Documents::ISpan, Windows::UI::Xaml::IDependencyObject, Windows::UI::Xaml::IDependencyObject2>
{
    using composable = Span;

protected:

    SpanT()
    {
        get_activation_factory<Span, ISpanFactory>().CreateInstance(*this, this->m_inner);
    }
};

}

}
