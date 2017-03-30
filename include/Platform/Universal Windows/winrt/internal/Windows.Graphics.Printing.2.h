// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Graphics.Printing.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
#define WINRT_GENERIC_98b9acc1_4b56_532e_ac73_03d5291cca90
template <> struct __declspec(uuid("98b9acc1-4b56-532e-ac73-03d5291cca90")) __declspec(novtable) IVector<hstring> : impl_IVector<hstring> {};
#endif

#ifndef WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
#define WINRT_GENERIC_2f13c006_a03a_5f69_b090_75a43e33423e
template <> struct __declspec(uuid("2f13c006-a03a-5f69-b090-75a43e33423e")) __declspec(novtable) IVectorView<hstring> : impl_IVectorView<hstring> {};
#endif

#ifndef WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
#define WINRT_GENERIC_e2fcc7c1_3bfc_5a0b_b2b0_72e769d1cb7e
template <> struct __declspec(uuid("e2fcc7c1-3bfc-5a0b-b2b0-72e769d1cb7e")) __declspec(novtable) IIterable<hstring> : impl_IIterable<hstring> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4cc141d4_c0d9_5220_b1ce_80fff3bd2d44
#define WINRT_GENERIC_4cc141d4_c0d9_5220_b1ce_80fff3bd2d44
template <> struct __declspec(uuid("4cc141d4-c0d9-5220-b1ce-80fff3bd2d44")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_c08d0524_5899_536c_8f46_55fdaa4cf78b
#define WINRT_GENERIC_c08d0524_5899_536c_8f46_55fdaa4cf78b
template <> struct __declspec(uuid("c08d0524-5899-536c-8f46-55fdaa4cf78b")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskProgressingEventArgs> : impl_TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskProgressingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b0b02549_b9ad_5226_898a_7b563b46640c
#define WINRT_GENERIC_b0b02549_b9ad_5226_898a_7b563b46640c
template <> struct __declspec(uuid("b0b02549-b9ad-5226-898a-7b563b46640c")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskCompletedEventArgs> : impl_TypedEventHandler<Windows::Graphics::Printing::PrintTask, Windows::Graphics::Printing::PrintTaskCompletedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_8a8cb877_70c5_54ce_8b42_d790e2914859
#define WINRT_GENERIC_8a8cb877_70c5_54ce_8b42_d790e2914859
template <> struct __declspec(uuid("8a8cb877-70c5-54ce-8b42-d790e2914859")) __declspec(novtable) TypedEventHandler<Windows::Graphics::Printing::PrintManager, Windows::Graphics::Printing::PrintTaskRequestedEventArgs> : impl_TypedEventHandler<Windows::Graphics::Printing::PrintManager, Windows::Graphics::Printing::PrintTaskRequestedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif


}

namespace Windows::Graphics::Printing {

struct PrintTaskSourceRequestedHandler : Windows::Foundation::IUnknown
{
    PrintTaskSourceRequestedHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> PrintTaskSourceRequestedHandler(L lambda);
    template <typename F> PrintTaskSourceRequestedHandler (F * function);
    template <typename O, typename M> PrintTaskSourceRequestedHandler(O * object, M method);
    void operator()(const Windows::Graphics::Printing::PrintTaskSourceRequestedArgs & args) const;
};

struct IPrintDocumentSource :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintDocumentSource>
{
    IPrintDocumentSource(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintManager :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintManager>
{
    IPrintManager(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintManagerStatic :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintManagerStatic>
{
    IPrintManagerStatic(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintManagerStatic2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintManagerStatic2>
{
    IPrintManagerStatic2(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintPageInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintPageInfo>
{
    IPrintPageInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTask :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTask>
{
    IPrintTask(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTask2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTask2>
{
    IPrintTask2(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskCompletedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskCompletedEventArgs>
{
    IPrintTaskCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskOptions :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskOptions>
{
    IPrintTaskOptions(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskOptionsCore :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskOptionsCore>
{
    IPrintTaskOptionsCore(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskOptionsCoreProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskOptionsCoreProperties>
{
    IPrintTaskOptionsCoreProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskOptionsCoreUIConfiguration :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskOptionsCoreUIConfiguration>
{
    IPrintTaskOptionsCoreUIConfiguration(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskProgressingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskProgressingEventArgs>
{
    IPrintTaskProgressingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskRequest>
{
    IPrintTaskRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskRequestedDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskRequestedDeferral>
{
    IPrintTaskRequestedDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskRequestedEventArgs>
{
    IPrintTaskRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskSourceRequestedArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskSourceRequestedArgs>
{
    IPrintTaskSourceRequestedArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskSourceRequestedDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskSourceRequestedDeferral>
{
    IPrintTaskSourceRequestedDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct IPrintTaskTargetDeviceSupport :
    Windows::Foundation::IInspectable,
    impl::consume<IPrintTaskTargetDeviceSupport>
{
    IPrintTaskTargetDeviceSupport(std::nullptr_t = nullptr) noexcept {}
};

struct IStandardPrintTaskOptionsStatic :
    Windows::Foundation::IInspectable,
    impl::consume<IStandardPrintTaskOptionsStatic>
{
    IStandardPrintTaskOptionsStatic(std::nullptr_t = nullptr) noexcept {}
};

struct IStandardPrintTaskOptionsStatic2 :
    Windows::Foundation::IInspectable,
    impl::consume<IStandardPrintTaskOptionsStatic2>
{
    IStandardPrintTaskOptionsStatic2(std::nullptr_t = nullptr) noexcept {}
};

}

}
