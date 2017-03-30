// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
#define WINRT_GENERIC_cdb5efb3_5788_509d_9be1_71ccb8a3362a
template <> struct __declspec(uuid("cdb5efb3-5788-509d-9be1-71ccb8a3362a")) __declspec(novtable) IAsyncOperation<bool> : impl_IAsyncOperation<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_69ad6aa7_0c49_5f27_a5eb_ef4d59467b6d
#define WINRT_GENERIC_69ad6aa7_0c49_5f27_a5eb_ef4d59467b6d
template <> struct __declspec(uuid("69ad6aa7-0c49-5f27-a5eb-ef4d59467b6d")) __declspec(novtable) IIterable<Windows::ApplicationModel::Package> : impl_IIterable<Windows::ApplicationModel::Package> {};
#endif

#ifndef WINRT_GENERIC_0263c4d4_195c_5dc5_a7ca_6806ceca420b
#define WINRT_GENERIC_0263c4d4_195c_5dc5_a7ca_6806ceca420b
template <> struct __declspec(uuid("0263c4d4-195c-5dc5-a7ca-6806ceca420b")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Package> : impl_IVectorView<Windows::ApplicationModel::Package> {};
#endif

#ifndef WINRT_GENERIC_920c8b92_d5ef_5899_8776_2ad97aca6e1d
#define WINRT_GENERIC_920c8b92_d5ef_5899_8776_2ad97aca6e1d
template <> struct __declspec(uuid("920c8b92-d5ef-5899-8776-2ad97aca6e1d")) __declspec(novtable) IVectorView<Windows::ApplicationModel::Core::AppListEntry> : impl_IVectorView<Windows::ApplicationModel::Core::AppListEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_1726f52d_2b8c_524a_98c6_f2cf0893c0f2
#define WINRT_GENERIC_1726f52d_2b8c_524a_98c6_f2cf0893c0f2
template <> struct __declspec(uuid("1726f52d-2b8c-524a-98c6-f2cf0893c0f2")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStagingEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStagingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_a8a900c6_da0b_5bcc_a71a_be0b9265d87a
#define WINRT_GENERIC_a8a900c6_da0b_5bcc_a71a_be0b9265d87a
template <> struct __declspec(uuid("a8a900c6-da0b-5bcc-a71a-be0b9265d87a")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageInstallingEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageInstallingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_c23e15f6_c618_522a_82ab_4fab36665ce5
#define WINRT_GENERIC_c23e15f6_c618_522a_82ab_4fab36665ce5
template <> struct __declspec(uuid("c23e15f6-c618-522a-82ab-4fab36665ce5")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUpdatingEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUpdatingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_bd636cf1_541f_53ea_8efc_e1604a395b1a
#define WINRT_GENERIC_bd636cf1_541f_53ea_8efc_e1604a395b1a
template <> struct __declspec(uuid("bd636cf1-541f-53ea-8efc-e1604a395b1a")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUninstallingEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageUninstallingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_b32d7d63_cd0e_5c2e_a251_fb8d290824e4
#define WINRT_GENERIC_b32d7d63_cd0e_5c2e_a251_fb8d290824e4
template <> struct __declspec(uuid("b32d7d63-cd0e-5c2e-a251-fb8d290824e4")) __declspec(novtable) TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStatusChangedEventArgs> : impl_TypedEventHandler<Windows::ApplicationModel::PackageCatalog, Windows::ApplicationModel::PackageStatusChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_5239a934_80e2_518f_b819_1f316f379a3f
#define WINRT_GENERIC_5239a934_80e2_518f_b819_1f316f379a3f
template <> struct __declspec(uuid("5239a934-80e2-518f-b819-1f316f379a3f")) __declspec(novtable) IAsyncOperation<winrt::Windows::ApplicationModel::StartupTaskState> : impl_IAsyncOperation<winrt::Windows::ApplicationModel::StartupTaskState> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_ea3b1b7a_5071_5986_88fc_912dbbf845fb
#define WINRT_GENERIC_ea3b1b7a_5071_5986_88fc_912dbbf845fb
template <> struct __declspec(uuid("ea3b1b7a-5071-5986-88fc-912dbbf845fb")) __declspec(novtable) IVectorView<Windows::ApplicationModel::StartupTask> : impl_IVectorView<Windows::ApplicationModel::StartupTask> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_cbec7a4e_a046_5330_873d_0fce228792fa
#define WINRT_GENERIC_cbec7a4e_a046_5330_873d_0fce228792fa
template <> struct __declspec(uuid("cbec7a4e-a046-5330-873d-0fce228792fa")) __declspec(novtable) IAsyncOperation<Windows::ApplicationModel::StartupTask> : impl_IAsyncOperation<Windows::ApplicationModel::StartupTask> {};
#endif

#ifndef WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
#define WINRT_GENERIC_c1d3d1a2_ae17_5a5f_b5a2_bdcc8844889a
template <> struct __declspec(uuid("c1d3d1a2-ae17-5a5f-b5a2-bdcc8844889a")) __declspec(novtable) AsyncOperationCompletedHandler<bool> : impl_AsyncOperationCompletedHandler<bool> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_0217f069_025c_5ee6_a87f_e782e3b623ae
#define WINRT_GENERIC_0217f069_025c_5ee6_a87f_e782e3b623ae
template <> struct __declspec(uuid("0217f069-025c-5ee6-a87f-e782e3b623ae")) __declspec(novtable) IIterator<Windows::ApplicationModel::Package> : impl_IIterator<Windows::ApplicationModel::Package> {};
#endif

#ifndef WINRT_GENERIC_b93e2028_50bc_599e_b3d9_427b61d26c01
#define WINRT_GENERIC_b93e2028_50bc_599e_b3d9_427b61d26c01
template <> struct __declspec(uuid("b93e2028-50bc-599e-b3d9-427b61d26c01")) __declspec(novtable) IIterator<Windows::ApplicationModel::Core::AppListEntry> : impl_IIterator<Windows::ApplicationModel::Core::AppListEntry> {};
#endif

#ifndef WINRT_GENERIC_86f4d4ef_d8fd_5fb5_807c_72da8fc9e544
#define WINRT_GENERIC_86f4d4ef_d8fd_5fb5_807c_72da8fc9e544
template <> struct __declspec(uuid("86f4d4ef-d8fd-5fb5-807c-72da8fc9e544")) __declspec(novtable) IIterable<Windows::ApplicationModel::Core::AppListEntry> : impl_IIterable<Windows::ApplicationModel::Core::AppListEntry> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_70a0bf67_19e8_5a86_a32e_3c9863825a04
#define WINRT_GENERIC_70a0bf67_19e8_5a86_a32e_3c9863825a04
template <> struct __declspec(uuid("70a0bf67-19e8-5a86-a32e-3c9863825a04")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::StartupTaskState> : impl_AsyncOperationCompletedHandler<winrt::Windows::ApplicationModel::StartupTaskState> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_14653598_9065_508e_b37b_44eb28d51cb7
#define WINRT_GENERIC_14653598_9065_508e_b37b_44eb28d51cb7
template <> struct __declspec(uuid("14653598-9065-508e-b37b-44eb28d51cb7")) __declspec(novtable) IIterator<Windows::ApplicationModel::StartupTask> : impl_IIterator<Windows::ApplicationModel::StartupTask> {};
#endif

#ifndef WINRT_GENERIC_61885ead_bf9e_5e9f_af04_6296b336930b
#define WINRT_GENERIC_61885ead_bf9e_5e9f_af04_6296b336930b
template <> struct __declspec(uuid("61885ead-bf9e-5e9f-af04-6296b336930b")) __declspec(novtable) IIterable<Windows::ApplicationModel::StartupTask> : impl_IIterable<Windows::ApplicationModel::StartupTask> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_741f7697_2452_5c80_83c6_3b6f822b904c
#define WINRT_GENERIC_741f7697_2452_5c80_83c6_3b6f822b904c
template <> struct __declspec(uuid("741f7697-2452-5c80-83c6-3b6f822b904c")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::ApplicationModel::StartupTask> : impl_AsyncOperationCompletedHandler<Windows::ApplicationModel::StartupTask> {};
#endif

#ifndef WINRT_GENERIC_d3bcf8a0_3538_5dae_98d7_1f2ab88c3f01
#define WINRT_GENERIC_d3bcf8a0_3538_5dae_98d7_1f2ab88c3f01
template <> struct __declspec(uuid("d3bcf8a0-3538-5dae-98d7-1f2ab88c3f01")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>> {};
#endif

#ifndef WINRT_GENERIC_16543165_5b65_5683_8a02_c385659158bd
#define WINRT_GENERIC_16543165_5b65_5683_8a02_c385659158bd
template <> struct __declspec(uuid("16543165-5b65-5683-8a02-c385659158bd")) __declspec(novtable) IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::StartupTask>> : impl_IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::StartupTask>> {};
#endif

#ifndef WINRT_GENERIC_51c74372_9452_57ce_9270_762009fbfe4d
#define WINRT_GENERIC_51c74372_9452_57ce_9270_762009fbfe4d
template <> struct __declspec(uuid("51c74372-9452-57ce-9270-762009fbfe4d")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::Core::AppListEntry>> {};
#endif

#ifndef WINRT_GENERIC_15d40795_41f9_50d7_a39e_5390981af651
#define WINRT_GENERIC_15d40795_41f9_50d7_a39e_5390981af651
template <> struct __declspec(uuid("15d40795-41f9-50d7-a39e-5390981af651")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::StartupTask>> : impl_AsyncOperationCompletedHandler<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::StartupTask>> {};
#endif


}

namespace Windows::ApplicationModel {

struct IAppDisplayInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IAppDisplayInfo>
{
    IAppDisplayInfo(std::nullptr_t = nullptr) noexcept {}
};

struct IAppInfo :
    Windows::Foundation::IInspectable,
    impl::consume<IAppInfo>
{
    IAppInfo(std::nullptr_t = nullptr) noexcept {}
};

struct ICameraApplicationManagerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ICameraApplicationManagerStatics>
{
    ICameraApplicationManagerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IDesignModeStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IDesignModeStatics>
{
    IDesignModeStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IEnteredBackgroundEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IEnteredBackgroundEventArgs>
{
    IEnteredBackgroundEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IFullTrustProcessLauncherStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IFullTrustProcessLauncherStatics>
{
    IFullTrustProcessLauncherStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ILeavingBackgroundEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ILeavingBackgroundEventArgs>
{
    ILeavingBackgroundEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPackage :
    Windows::Foundation::IInspectable,
    impl::consume<IPackage>
{
    IPackage(std::nullptr_t = nullptr) noexcept {}
};

struct IPackage2 :
    Windows::Foundation::IInspectable,
    impl::consume<IPackage2>
{
    IPackage2(std::nullptr_t = nullptr) noexcept {}
};

struct IPackage3 :
    Windows::Foundation::IInspectable,
    impl::consume<IPackage3>
{
    IPackage3(std::nullptr_t = nullptr) noexcept {}
};

struct IPackage4 :
    Windows::Foundation::IInspectable,
    impl::consume<IPackage4>
{
    IPackage4(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageCatalog :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageCatalog>
{
    IPackageCatalog(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageCatalogStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageCatalogStatics>
{
    IPackageCatalogStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageId :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageId>
{
    IPackageId(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageIdWithMetadata :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageIdWithMetadata>
{
    IPackageIdWithMetadata(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageInstallingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageInstallingEventArgs>
{
    IPackageInstallingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageStagingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageStagingEventArgs>
{
    IPackageStagingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageStatics>
{
    IPackageStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageStatus :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageStatus>
{
    IPackageStatus(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageStatusChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageStatusChangedEventArgs>
{
    IPackageStatusChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageUninstallingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageUninstallingEventArgs>
{
    IPackageUninstallingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageUpdatingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageUpdatingEventArgs>
{
    IPackageUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IPackageWithMetadata :
    Windows::Foundation::IInspectable,
    impl::consume<IPackageWithMetadata>
{
    IPackageWithMetadata(std::nullptr_t = nullptr) noexcept {}
};

struct IStartupTask :
    Windows::Foundation::IInspectable,
    impl::consume<IStartupTask>
{
    IStartupTask(std::nullptr_t = nullptr) noexcept {}
};

struct IStartupTaskStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IStartupTaskStatics>
{
    IStartupTaskStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISuspendingDeferral :
    Windows::Foundation::IInspectable,
    impl::consume<ISuspendingDeferral>
{
    ISuspendingDeferral(std::nullptr_t = nullptr) noexcept {}
};

struct ISuspendingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISuspendingEventArgs>
{
    ISuspendingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISuspendingOperation :
    Windows::Foundation::IInspectable,
    impl::consume<ISuspendingOperation>
{
    ISuspendingOperation(std::nullptr_t = nullptr) noexcept {}
};

}

}
