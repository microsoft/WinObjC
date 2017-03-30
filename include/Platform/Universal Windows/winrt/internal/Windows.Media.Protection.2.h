// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Protection.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_3623cc0c_c765_57fb_967d_c7cb6097bd78
#define WINRT_GENERIC_3623cc0c_c765_57fb_967d_c7cb6097bd78
template <> struct __declspec(uuid("3623cc0c-c765-57fb-967d-c7cb6097bd78")) __declspec(novtable) IVector<Windows::Media::Protection::RevocationAndRenewalItem> : impl_IVector<Windows::Media::Protection::RevocationAndRenewalItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_8e330979_2fef_5d68_88aa_a9ee6697d117
#define WINRT_GENERIC_8e330979_2fef_5d68_88aa_a9ee6697d117
template <> struct __declspec(uuid("8e330979-2fef-5d68-88aa-a9ee6697d117")) __declspec(novtable) IReference<winrt::Windows::Media::Protection::HdcpProtection> : impl_IReference<winrt::Windows::Media::Protection::HdcpProtection> {};
#endif

#ifndef WINRT_GENERIC_5061ee0f_899a_569c_a0a3_c2566eb88142
#define WINRT_GENERIC_5061ee0f_899a_569c_a0a3_c2566eb88142
template <> struct __declspec(uuid("5061ee0f-899a-569c-a0a3-c2566eb88142")) __declspec(novtable) IAsyncOperation<winrt::Windows::Media::Protection::HdcpSetProtectionResult> : impl_IAsyncOperation<winrt::Windows::Media::Protection::HdcpSetProtectionResult> {};
#endif

#ifndef WINRT_GENERIC_f82ae043_54fb_5366_a607_19b68e6bab8c
#define WINRT_GENERIC_f82ae043_54fb_5366_a607_19b68e6bab8c
template <> struct __declspec(uuid("f82ae043-54fb-5366-a607-19b68e6bab8c")) __declspec(novtable) TypedEventHandler<Windows::Media::Protection::HdcpSession, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Protection::HdcpSession, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_595dcc09_9ad3_5094_800a_0883cce1ef01
#define WINRT_GENERIC_595dcc09_9ad3_5094_800a_0883cce1ef01
template <> struct __declspec(uuid("595dcc09-9ad3-5094-800a-0883cce1ef01")) __declspec(novtable) IAsyncOperationWithProgress<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> : impl_IAsyncOperationWithProgress<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_dfb9655c_8b22_511f_8eaf_3aea7521802b
#define WINRT_GENERIC_dfb9655c_8b22_511f_8eaf_3aea7521802b
template <> struct __declspec(uuid("dfb9655c-8b22-511f-8eaf-3aea7521802b")) __declspec(novtable) IIterator<Windows::Media::Protection::RevocationAndRenewalItem> : impl_IIterator<Windows::Media::Protection::RevocationAndRenewalItem> {};
#endif

#ifndef WINRT_GENERIC_07015868_578c_556b_8a35_4039a35d1d92
#define WINRT_GENERIC_07015868_578c_556b_8a35_4039a35d1d92
template <> struct __declspec(uuid("07015868-578c-556b-8a35-4039a35d1d92")) __declspec(novtable) IIterable<Windows::Media::Protection::RevocationAndRenewalItem> : impl_IIterable<Windows::Media::Protection::RevocationAndRenewalItem> {};
#endif

#ifndef WINRT_GENERIC_4a8793e2_33b8_5850_9943_6a94375caa89
#define WINRT_GENERIC_4a8793e2_33b8_5850_9943_6a94375caa89
template <> struct __declspec(uuid("4a8793e2-33b8-5850-9943-6a94375caa89")) __declspec(novtable) IVectorView<Windows::Media::Protection::RevocationAndRenewalItem> : impl_IVectorView<Windows::Media::Protection::RevocationAndRenewalItem> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_19344a58_a5c1_5168_803e_632771628143
#define WINRT_GENERIC_19344a58_a5c1_5168_803e_632771628143
template <> struct __declspec(uuid("19344a58-a5c1-5168-803e-632771628143")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Media::Protection::HdcpSetProtectionResult> : impl_AsyncOperationCompletedHandler<winrt::Windows::Media::Protection::HdcpSetProtectionResult> {};
#endif

#ifndef WINRT_GENERIC_b9da4aa0_26e0_5d69_a0c8_05716a406235
#define WINRT_GENERIC_b9da4aa0_26e0_5d69_a0c8_05716a406235
template <> struct __declspec(uuid("b9da4aa0-26e0-5d69-a0c8-05716a406235")) __declspec(novtable) AsyncOperationProgressHandler<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> : impl_AsyncOperationProgressHandler<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> {};
#endif

#ifndef WINRT_GENERIC_ec067827_67d9_59a6_a57b_3e7ca12b89c1
#define WINRT_GENERIC_ec067827_67d9_59a6_a57b_3e7ca12b89c1
template <> struct __declspec(uuid("ec067827-67d9-59a6-a57b-3e7ca12b89c1")) __declspec(novtable) AsyncOperationWithProgressCompletedHandler<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> : impl_AsyncOperationWithProgressCompletedHandler<winrt::Windows::Media::Protection::RenewalStatus, uint32_t> {};
#endif


}

namespace Windows::Media::Protection {

struct ComponentLoadFailedEventHandler : Windows::Foundation::IUnknown
{
    ComponentLoadFailedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ComponentLoadFailedEventHandler(L lambda);
    template <typename F> ComponentLoadFailedEventHandler (F * function);
    template <typename O, typename M> ComponentLoadFailedEventHandler(O * object, M method);
    void operator()(const Windows::Media::Protection::MediaProtectionManager & sender, const Windows::Media::Protection::ComponentLoadFailedEventArgs & e) const;
};

struct RebootNeededEventHandler : Windows::Foundation::IUnknown
{
    RebootNeededEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> RebootNeededEventHandler(L lambda);
    template <typename F> RebootNeededEventHandler (F * function);
    template <typename O, typename M> RebootNeededEventHandler(O * object, M method);
    void operator()(const Windows::Media::Protection::MediaProtectionManager & sender) const;
};

struct ServiceRequestedEventHandler : Windows::Foundation::IUnknown
{
    ServiceRequestedEventHandler(std::nullptr_t = nullptr) noexcept {}
    template <typename L> ServiceRequestedEventHandler(L lambda);
    template <typename F> ServiceRequestedEventHandler (F * function);
    template <typename O, typename M> ServiceRequestedEventHandler(O * object, M method);
    void operator()(const Windows::Media::Protection::MediaProtectionManager & sender, const Windows::Media::Protection::ServiceRequestedEventArgs & e) const;
};

struct IComponentLoadFailedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IComponentLoadFailedEventArgs>
{
    IComponentLoadFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IComponentRenewalStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IComponentRenewalStatics>
{
    IComponentRenewalStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IHdcpSession :
    Windows::Foundation::IInspectable,
    impl::consume<IHdcpSession>,
    impl::require<IHdcpSession, Windows::Foundation::IClosable>
{
    IHdcpSession(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaProtectionManager :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaProtectionManager>
{
    IMediaProtectionManager(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaProtectionPMPServer :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaProtectionPMPServer>
{
    IMediaProtectionPMPServer(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaProtectionPMPServerFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaProtectionPMPServerFactory>
{
    IMediaProtectionPMPServerFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaProtectionServiceCompletion :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaProtectionServiceCompletion>
{
    IMediaProtectionServiceCompletion(std::nullptr_t = nullptr) noexcept {}
};

struct IMediaProtectionServiceRequest :
    Windows::Foundation::IInspectable,
    impl::consume<IMediaProtectionServiceRequest>
{
    IMediaProtectionServiceRequest(std::nullptr_t = nullptr) noexcept {}
};

struct IProtectionCapabilities :
    Windows::Foundation::IInspectable,
    impl::consume<IProtectionCapabilities>
{
    IProtectionCapabilities(std::nullptr_t = nullptr) noexcept {}
};

struct IRevocationAndRenewalInformation :
    Windows::Foundation::IInspectable,
    impl::consume<IRevocationAndRenewalInformation>
{
    IRevocationAndRenewalInformation(std::nullptr_t = nullptr) noexcept {}
};

struct IRevocationAndRenewalItem :
    Windows::Foundation::IInspectable,
    impl::consume<IRevocationAndRenewalItem>
{
    IRevocationAndRenewalItem(std::nullptr_t = nullptr) noexcept {}
};

struct IServiceRequestedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IServiceRequestedEventArgs>
{
    IServiceRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IServiceRequestedEventArgs2 :
    Windows::Foundation::IInspectable,
    impl::consume<IServiceRequestedEventArgs2>
{
    IServiceRequestedEventArgs2(std::nullptr_t = nullptr) noexcept {}
};

}

}
