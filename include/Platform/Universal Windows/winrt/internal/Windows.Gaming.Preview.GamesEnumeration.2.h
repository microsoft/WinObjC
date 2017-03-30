// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Gaming.Preview.GamesEnumeration.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
#define WINRT_GENERIC_09335560_6c6b_5a26_9348_97b781132b20
template <> struct __declspec(uuid("09335560-6c6b-5a26-9348-97b781132b20")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::IInspectable> : impl_IKeyValuePair<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
#define WINRT_GENERIC_bb78502a_f79d_54fa_92c9_90c5039fdf7e
template <> struct __declspec(uuid("bb78502a-f79d-54fa-92c9-90c5039fdf7e")) __declspec(novtable) IMapView<hstring, Windows::Foundation::IInspectable> : impl_IMapView<hstring, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_0eea1ad9_03e2_5ba9_ae02_daca432f362a
#define WINRT_GENERIC_0eea1ad9_03e2_5ba9_ae02_daca432f362a
template <> struct __declspec(uuid("0eea1ad9-03e2-5ba9-ae02-daca432f362a")) __declspec(novtable) IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry> : impl_IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_ed5b903e_5aeb_5d8c_9538_8306f02926c3
#define WINRT_GENERIC_ed5b903e_5aeb_5d8c_9538_8306f02926c3
template <> struct __declspec(uuid("ed5b903e-5aeb-5d8c-9538-8306f02926c3")) __declspec(novtable) IIterator<Windows::Gaming::Preview::GamesEnumeration::GameListEntry> : impl_IIterator<Windows::Gaming::Preview::GamesEnumeration::GameListEntry> {};
#endif

#ifndef WINRT_GENERIC_42b8c8a0_3d03_5d5f_817e_4405c850f646
#define WINRT_GENERIC_42b8c8a0_3d03_5d5f_817e_4405c850f646
template <> struct __declspec(uuid("42b8c8a0-3d03-5d5f-817e-4405c850f646")) __declspec(novtable) IIterable<Windows::Gaming::Preview::GamesEnumeration::GameListEntry> : impl_IIterable<Windows::Gaming::Preview::GamesEnumeration::GameListEntry> {};
#endif

#ifndef WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
#define WINRT_GENERIC_fe2f3d47_5d47_5499_8374_430c7cda0204
template <> struct __declspec(uuid("fe2f3d47-5d47-5499-8374-430c7cda0204")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_721a94fb_a733_5e19_8abf_03249c29870e
#define WINRT_GENERIC_721a94fb_a733_5e19_8abf_03249c29870e
template <> struct __declspec(uuid("721a94fb-a733-5e19-8abf-03249c29870e")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
#define WINRT_GENERIC_5db5fa32_707c_5849_a06b_91c8eb9d10e8
template <> struct __declspec(uuid("5db5fa32-707c-5849-a06b-91c8eb9d10e8")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::IInspectable>> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_eadac44b_7fdd_5589_b093_1bb73cc64f02
#define WINRT_GENERIC_eadac44b_7fdd_5589_b093_1bb73cc64f02
template <> struct __declspec(uuid("eadac44b-7fdd-5589-b093-1bb73cc64f02")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::Gaming::Preview::GamesEnumeration::GameListEntry>> {};
#endif


}

namespace Windows::Gaming::Preview::GamesEnumeration {

struct GameListChangedEventHandler : Windows::Foundation::IUnknown
{
    GameListChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> GameListChangedEventHandler(L lambda);
    template <typename F> GameListChangedEventHandler (F * function);
    template <typename O, typename M> GameListChangedEventHandler(O * object, M method);
    void operator()(const Windows::Gaming::Preview::GamesEnumeration::GameListEntry & game) const;
};

struct GameListRemovedEventHandler : Windows::Foundation::IUnknown
{
    GameListRemovedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> GameListRemovedEventHandler(L lambda);
    template <typename F> GameListRemovedEventHandler (F * function);
    template <typename O, typename M> GameListRemovedEventHandler(O * object, M method);
    void operator()(hstring_view identifier) const;
};

struct IGameListEntry :
    Windows::Foundation::IInspectable,
    impl::consume<IGameListEntry>
{
    IGameListEntry(std::nullptr_t = nullptr) noexcept {}
};

struct IGameListStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IGameListStatics>
{
    IGameListStatics(std::nullptr_t = nullptr) noexcept {}
};

}

}
