// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.UI.Xaml.Interop.3.h"
#include "internal/Windows.UI.Xaml.Media.Animation.3.h"
#include "internal/Windows.UI.Xaml.3.h"
#include "internal/Windows.UI.Xaml.Navigation.3.h"
#include "Windows.UI.Xaml.h"

WINRT_EXPORT namespace winrt {

namespace Windows::UI::Xaml::Navigation {

template <typename L> LoadCompletedEventHandler::LoadCompletedEventHandler(L lambda) :
    LoadCompletedEventHandler(impl::make_delegate<impl_LoadCompletedEventHandler<L>, LoadCompletedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> LoadCompletedEventHandler::LoadCompletedEventHandler(F * function) :
    LoadCompletedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> LoadCompletedEventHandler::LoadCompletedEventHandler(O * object, M method) :
    LoadCompletedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void LoadCompletedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const
{
    check_hresult((*(abi<LoadCompletedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> NavigatedEventHandler::NavigatedEventHandler(L lambda) :
    NavigatedEventHandler(impl::make_delegate<impl_NavigatedEventHandler<L>, NavigatedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> NavigatedEventHandler::NavigatedEventHandler(F * function) :
    NavigatedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> NavigatedEventHandler::NavigatedEventHandler(O * object, M method) :
    NavigatedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void NavigatedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const
{
    check_hresult((*(abi<NavigatedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> NavigatingCancelEventHandler::NavigatingCancelEventHandler(L lambda) :
    NavigatingCancelEventHandler(impl::make_delegate<impl_NavigatingCancelEventHandler<L>, NavigatingCancelEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> NavigatingCancelEventHandler::NavigatingCancelEventHandler(F * function) :
    NavigatingCancelEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> NavigatingCancelEventHandler::NavigatingCancelEventHandler(O * object, M method) :
    NavigatingCancelEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void NavigatingCancelEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigatingCancelEventArgs & e) const
{
    check_hresult((*(abi<NavigatingCancelEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> NavigationFailedEventHandler::NavigationFailedEventHandler(L lambda) :
    NavigationFailedEventHandler(impl::make_delegate<impl_NavigationFailedEventHandler<L>, NavigationFailedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> NavigationFailedEventHandler::NavigationFailedEventHandler(F * function) :
    NavigationFailedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> NavigationFailedEventHandler::NavigationFailedEventHandler(O * object, M method) :
    NavigationFailedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void NavigationFailedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationFailedEventArgs & e) const
{
    check_hresult((*(abi<NavigationFailedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

template <typename L> NavigationStoppedEventHandler::NavigationStoppedEventHandler(L lambda) :
    NavigationStoppedEventHandler(impl::make_delegate<impl_NavigationStoppedEventHandler<L>, NavigationStoppedEventHandler>(std::forward<L>(lambda)))
{}

template <typename F> NavigationStoppedEventHandler::NavigationStoppedEventHandler(F * function) :
    NavigationStoppedEventHandler([=](auto && ... args) { function(args ...); })
{}

template <typename O, typename M> NavigationStoppedEventHandler::NavigationStoppedEventHandler(O * object, M method) :
    NavigationStoppedEventHandler([=](auto && ... args) { ((*object).*(method))(args ...); })
{}

inline void NavigationStoppedEventHandler::operator()(const Windows::Foundation::IInspectable & sender, const Windows::UI::Xaml::Navigation::NavigationEventArgs & e) const
{
    check_hresult((*(abi<NavigationStoppedEventHandler> **)this)->abi_Invoke(get_abi(sender), get_abi(e)));
}

}

namespace impl {

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs> : produce_base<D, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs>
{
    HRESULT __stdcall get_Cancel(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Cancel());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Cancel(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NavigationMode(Windows::UI::Xaml::Navigation::NavigationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NavigationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePageType(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2> : produce_base<D, Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs2>
{
    HRESULT __stdcall get_Parameter(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NavigationTransitionInfo(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NavigationTransitionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::INavigationEventArgs> : produce_base<D, Windows::UI::Xaml::Navigation::INavigationEventArgs>
{
    HRESULT __stdcall get_Content(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Content());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parameter(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePageType(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NavigationMode(Windows::UI::Xaml::Navigation::NavigationMode * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NavigationMode());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Uri(impl::abi_arg_out<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Uri());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Uri(impl::abi_arg_in<Windows::Foundation::IUriRuntimeClass> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<const Windows::Foundation::Uri *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::INavigationEventArgs2> : produce_base<D, Windows::UI::Xaml::Navigation::INavigationEventArgs2>
{
    HRESULT __stdcall get_NavigationTransitionInfo(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NavigationTransitionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::INavigationFailedEventArgs> : produce_base<D, Windows::UI::Xaml::Navigation::INavigationFailedEventArgs>
{
    HRESULT __stdcall get_Exception(HRESULT * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Exception());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Handled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Handled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Handled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SourcePageType(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::IPageStackEntry> : produce_base<D, Windows::UI::Xaml::Navigation::IPageStackEntry>
{
    HRESULT __stdcall get_SourcePageType(impl::abi_arg_out<Windows::UI::Xaml::Interop::TypeName> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePageType());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Parameter(impl::abi_arg_out<Windows::Foundation::IInspectable> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Parameter());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_NavigationTransitionInfo(impl::abi_arg_out<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().NavigationTransitionInfo());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::IPageStackEntryFactory> : produce_base<D, Windows::UI::Xaml::Navigation::IPageStackEntryFactory>
{
    HRESULT __stdcall abi_CreateInstance(impl::abi_arg_in<Windows::UI::Xaml::Interop::TypeName> sourcePageType, impl::abi_arg_in<Windows::Foundation::IInspectable> parameter, impl::abi_arg_in<Windows::UI::Xaml::Media::Animation::INavigationTransitionInfo> navigationTransitionInfo, impl::abi_arg_out<Windows::UI::Xaml::Navigation::IPageStackEntry> instance) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *instance = detach_abi(this->shim().CreateInstance(*reinterpret_cast<const Windows::UI::Xaml::Interop::TypeName *>(&sourcePageType), *reinterpret_cast<const Windows::Foundation::IInspectable *>(&parameter), *reinterpret_cast<const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo *>(&navigationTransitionInfo)));
            return S_OK;
        }
        catch (...)
        {
            *instance = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::UI::Xaml::Navigation::IPageStackEntryStatics> : produce_base<D, Windows::UI::Xaml::Navigation::IPageStackEntryStatics>
{
    HRESULT __stdcall get_SourcePageTypeProperty(impl::abi_arg_out<Windows::UI::Xaml::IDependencyProperty> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SourcePageTypeProperty());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::UI::Xaml::Navigation {

template <typename D> bool impl_INavigatingCancelEventArgs<D>::Cancel() const
{
    bool value {};
    check_hresult(WINRT_SHIM(INavigatingCancelEventArgs)->get_Cancel(&value));
    return value;
}

template <typename D> void impl_INavigatingCancelEventArgs<D>::Cancel(bool value) const
{
    check_hresult(WINRT_SHIM(INavigatingCancelEventArgs)->put_Cancel(value));
}

template <typename D> Windows::UI::Xaml::Navigation::NavigationMode impl_INavigatingCancelEventArgs<D>::NavigationMode() const
{
    Windows::UI::Xaml::Navigation::NavigationMode value {};
    check_hresult(WINRT_SHIM(INavigatingCancelEventArgs)->get_NavigationMode(&value));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_INavigatingCancelEventArgs<D>::SourcePageType() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(INavigatingCancelEventArgs)->get_SourcePageType(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_INavigatingCancelEventArgs2<D>::Parameter() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(INavigatingCancelEventArgs2)->get_Parameter(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo impl_INavigatingCancelEventArgs2<D>::NavigationTransitionInfo() const
{
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo value { nullptr };
    check_hresult(WINRT_SHIM(INavigatingCancelEventArgs2)->get_NavigationTransitionInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_INavigationEventArgs<D>::Content() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(INavigationEventArgs)->get_Content(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_INavigationEventArgs<D>::Parameter() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(INavigationEventArgs)->get_Parameter(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_INavigationEventArgs<D>::SourcePageType() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(INavigationEventArgs)->get_SourcePageType(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Navigation::NavigationMode impl_INavigationEventArgs<D>::NavigationMode() const
{
    Windows::UI::Xaml::Navigation::NavigationMode value {};
    check_hresult(WINRT_SHIM(INavigationEventArgs)->get_NavigationMode(&value));
    return value;
}

template <typename D> Windows::Foundation::Uri impl_INavigationEventArgs<D>::Uri() const
{
    Windows::Foundation::Uri value { nullptr };
    check_hresult(WINRT_SHIM(INavigationEventArgs)->get_Uri(put_abi(value)));
    return value;
}

template <typename D> void impl_INavigationEventArgs<D>::Uri(const Windows::Foundation::Uri & value) const
{
    check_hresult(WINRT_SHIM(INavigationEventArgs)->put_Uri(get_abi(value)));
}

template <typename D> Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo impl_INavigationEventArgs2<D>::NavigationTransitionInfo() const
{
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo value { nullptr };
    check_hresult(WINRT_SHIM(INavigationEventArgs2)->get_NavigationTransitionInfo(put_abi(value)));
    return value;
}

template <typename D> HRESULT impl_INavigationFailedEventArgs<D>::Exception() const
{
    HRESULT value {};
    check_hresult(WINRT_SHIM(INavigationFailedEventArgs)->get_Exception(&value));
    return value;
}

template <typename D> bool impl_INavigationFailedEventArgs<D>::Handled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(INavigationFailedEventArgs)->get_Handled(&value));
    return value;
}

template <typename D> void impl_INavigationFailedEventArgs<D>::Handled(bool value) const
{
    check_hresult(WINRT_SHIM(INavigationFailedEventArgs)->put_Handled(value));
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_INavigationFailedEventArgs<D>::SourcePageType() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(INavigationFailedEventArgs)->get_SourcePageType(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Interop::TypeName impl_IPageStackEntry<D>::SourcePageType() const
{
    Windows::UI::Xaml::Interop::TypeName value {};
    check_hresult(WINRT_SHIM(IPageStackEntry)->get_SourcePageType(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IInspectable impl_IPageStackEntry<D>::Parameter() const
{
    Windows::Foundation::IInspectable value;
    check_hresult(WINRT_SHIM(IPageStackEntry)->get_Parameter(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo impl_IPageStackEntry<D>::NavigationTransitionInfo() const
{
    Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo value { nullptr };
    check_hresult(WINRT_SHIM(IPageStackEntry)->get_NavigationTransitionInfo(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::DependencyProperty impl_IPageStackEntryStatics<D>::SourcePageTypeProperty() const
{
    Windows::UI::Xaml::DependencyProperty value { nullptr };
    check_hresult(WINRT_SHIM(IPageStackEntryStatics)->get_SourcePageTypeProperty(put_abi(value)));
    return value;
}

template <typename D> Windows::UI::Xaml::Navigation::PageStackEntry impl_IPageStackEntryFactory<D>::CreateInstance(const Windows::UI::Xaml::Interop::TypeName & sourcePageType, const Windows::Foundation::IInspectable & parameter, const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo & navigationTransitionInfo) const
{
    Windows::UI::Xaml::Navigation::PageStackEntry instance { nullptr };
    check_hresult(WINRT_SHIM(IPageStackEntryFactory)->abi_CreateInstance(get_abi(sourcePageType), get_abi(parameter), get_abi(navigationTransitionInfo), put_abi(instance)));
    return instance;
}

inline PageStackEntry::PageStackEntry(const Windows::UI::Xaml::Interop::TypeName & sourcePageType, const Windows::Foundation::IInspectable & parameter, const Windows::UI::Xaml::Media::Animation::NavigationTransitionInfo & navigationTransitionInfo) :
    PageStackEntry(get_activation_factory<PageStackEntry, IPageStackEntryFactory>().CreateInstance(sourcePageType, parameter, navigationTransitionInfo))
{}

inline Windows::UI::Xaml::DependencyProperty PageStackEntry::SourcePageTypeProperty()
{
    return get_activation_factory<PageStackEntry, IPageStackEntryStatics>().SourcePageTypeProperty();
}

}

}
#pragma warning(pop)
