// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System {

struct WINRT_EBO AppMemoryReport :
    Windows::System::IAppMemoryReport
{
    AppMemoryReport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppMemoryUsageLimitChangingEventArgs :
    Windows::System::IAppMemoryUsageLimitChangingEventArgs
{
    AppMemoryUsageLimitChangingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FolderLauncherOptions :
    Windows::System::IFolderLauncherOptions,
    impl::require<FolderLauncherOptions, Windows::System::ILauncherViewOptions>
{
    FolderLauncherOptions(std::nullptr_t) noexcept {}
    FolderLauncherOptions();
};

struct KnownUserProperties
{
    KnownUserProperties() = delete;
    static hstring DisplayName();
    static hstring FirstName();
    static hstring LastName();
    static hstring ProviderName();
    static hstring AccountName();
    static hstring GuestHost();
    static hstring PrincipalName();
    static hstring DomainName();
    static hstring SessionInitiationProtocolUri();
};

struct WINRT_EBO LaunchUriResult :
    Windows::System::ILaunchUriResult
{
    LaunchUriResult(std::nullptr_t) noexcept {}
};

struct Launcher
{
    Launcher() = delete;
    static Windows::Foundation::IAsyncOperation<bool> LaunchFileAsync(const Windows::Storage::IStorageFile & file);
    static Windows::Foundation::IAsyncOperation<bool> LaunchFileAsync(const Windows::Storage::IStorageFile & file, const Windows::System::LauncherOptions & options);
    static Windows::Foundation::IAsyncOperation<bool> LaunchUriAsync(const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<bool> LaunchUriAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options);
    static Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> LaunchUriForResultsAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options);
    static Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> LaunchUriForResultsAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData);
    static Windows::Foundation::IAsyncOperation<bool> LaunchUriAsync(const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> QueryUriSupportAsync(const Windows::Foundation::Uri & uri, Windows::System::LaunchQuerySupportType launchQuerySupportType);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> QueryUriSupportAsync(const Windows::Foundation::Uri & uri, Windows::System::LaunchQuerySupportType launchQuerySupportType, hstring_view packageFamilyName);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> QueryFileSupportAsync(const Windows::Storage::StorageFile & file);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> QueryFileSupportAsync(const Windows::Storage::StorageFile & file, hstring_view packageFamilyName);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> FindUriSchemeHandlersAsync(hstring_view scheme);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> FindUriSchemeHandlersAsync(hstring_view scheme, Windows::System::LaunchQuerySupportType launchQuerySupportType);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> FindFileHandlersAsync(hstring_view extension);
    static Windows::Foundation::IAsyncOperation<bool> LaunchFolderAsync(const Windows::Storage::IStorageFolder & folder);
    static Windows::Foundation::IAsyncOperation<bool> LaunchFolderAsync(const Windows::Storage::IStorageFolder & folder, const Windows::System::FolderLauncherOptions & options);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> QueryAppUriSupportAsync(const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchQuerySupportStatus> QueryAppUriSupportAsync(const Windows::Foundation::Uri & uri, hstring_view packageFamilyName);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> FindAppUriHandlersAsync(const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::LaunchUriStatus> LaunchUriForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData);
    static Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> LaunchUriForResultsForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options);
    static Windows::Foundation::IAsyncOperation<Windows::System::LaunchUriResult> LaunchUriForResultsForUserAsync(const Windows::System::User & user, const Windows::Foundation::Uri & uri, const Windows::System::LauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData);
};

struct WINRT_EBO LauncherOptions :
    Windows::System::ILauncherOptions,
    impl::require<LauncherOptions, Windows::System::ILauncherOptions2, Windows::System::ILauncherOptions3, Windows::System::ILauncherViewOptions>
{
    LauncherOptions(std::nullptr_t) noexcept {}
    LauncherOptions();
};

struct WINRT_EBO LauncherUIOptions :
    Windows::System::ILauncherUIOptions
{
    LauncherUIOptions(std::nullptr_t) noexcept {}
};

struct MemoryManager
{
    MemoryManager() = delete;
    static uint64_t AppMemoryUsage();
    static uint64_t AppMemoryUsageLimit();
    static Windows::System::AppMemoryUsageLevel AppMemoryUsageLevel();
    static event_token AppMemoryUsageIncreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using AppMemoryUsageIncreased_revoker = factory_event_revoker<IMemoryManagerStatics>;
    static AppMemoryUsageIncreased_revoker AppMemoryUsageIncreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void AppMemoryUsageIncreased(event_token token);
    static event_token AppMemoryUsageDecreased(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    using AppMemoryUsageDecreased_revoker = factory_event_revoker<IMemoryManagerStatics>;
    static AppMemoryUsageDecreased_revoker AppMemoryUsageDecreased(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & handler);
    static void AppMemoryUsageDecreased(event_token token);
    static event_token AppMemoryUsageLimitChanging(const Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs> & handler);
    using AppMemoryUsageLimitChanging_revoker = factory_event_revoker<IMemoryManagerStatics>;
    static AppMemoryUsageLimitChanging_revoker AppMemoryUsageLimitChanging(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::System::AppMemoryUsageLimitChangingEventArgs> & handler);
    static void AppMemoryUsageLimitChanging(event_token token);
    static Windows::System::AppMemoryReport GetAppMemoryReport();
    static Windows::System::ProcessMemoryReport GetProcessMemoryReport();
    static bool TrySetAppMemoryUsageLimit(uint64_t value);
};

struct ProcessLauncher
{
    ProcessLauncher() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> RunToCompletionAsync(hstring_view fileName, hstring_view args);
    static Windows::Foundation::IAsyncOperation<Windows::System::ProcessLauncherResult> RunToCompletionAsync(hstring_view fileName, hstring_view args, const Windows::System::ProcessLauncherOptions & options);
};

struct WINRT_EBO ProcessLauncherOptions :
    Windows::System::IProcessLauncherOptions
{
    ProcessLauncherOptions(std::nullptr_t) noexcept {}
    ProcessLauncherOptions();
};

struct WINRT_EBO ProcessLauncherResult :
    Windows::System::IProcessLauncherResult
{
    ProcessLauncherResult(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProcessMemoryReport :
    Windows::System::IProcessMemoryReport
{
    ProcessMemoryReport(std::nullptr_t) noexcept {}
};

struct WINRT_EBO ProtocolForResultsOperation :
    Windows::System::IProtocolForResultsOperation
{
    ProtocolForResultsOperation(std::nullptr_t) noexcept {}
};

struct RemoteLauncher
{
    RemoteLauncher() = delete;
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri, const Windows::System::RemoteLauncherOptions & options);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::RemoteLaunchUriStatus> LaunchUriAsync(const Windows::System::RemoteSystems::RemoteSystemConnectionRequest & remoteSystemConnectionRequest, const Windows::Foundation::Uri & uri, const Windows::System::RemoteLauncherOptions & options, const Windows::Foundation::Collections::ValueSet & inputData);
};

struct WINRT_EBO RemoteLauncherOptions :
    Windows::System::IRemoteLauncherOptions
{
    RemoteLauncherOptions(std::nullptr_t) noexcept {}
    RemoteLauncherOptions();
};

struct ShutdownManager
{
    ShutdownManager() = delete;
    static void BeginShutdown(Windows::System::ShutdownKind shutdownKind, const Windows::Foundation::TimeSpan & timeout);
    static void CancelShutdown();
};

struct TimeZoneSettings
{
    TimeZoneSettings() = delete;
    static hstring CurrentTimeZoneDisplayName();
    static Windows::Foundation::Collections::IVectorView<hstring> SupportedTimeZoneDisplayNames();
    static bool CanChangeTimeZone();
    static void ChangeTimeZoneByDisplayName(hstring_view timeZoneDisplayName);
};

struct WINRT_EBO User :
    Windows::System::IUser
{
    User(std::nullptr_t) noexcept {}
    static Windows::System::UserWatcher CreateWatcher();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> FindAllAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> FindAllAsync(Windows::System::UserType type);
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::System::User>> FindAllAsync(Windows::System::UserType type, Windows::System::UserAuthenticationStatus status);
    static Windows::System::User GetFromId(hstring_view nonRoamableId);
};

struct WINRT_EBO UserAuthenticationStatusChangeDeferral :
    Windows::System::IUserAuthenticationStatusChangeDeferral
{
    UserAuthenticationStatusChangeDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserAuthenticationStatusChangingEventArgs :
    Windows::System::IUserAuthenticationStatusChangingEventArgs
{
    UserAuthenticationStatusChangingEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserChangedEventArgs :
    Windows::System::IUserChangedEventArgs
{
    UserChangedEventArgs(std::nullptr_t) noexcept {}
};

struct UserDeviceAssociation
{
    UserDeviceAssociation() = delete;
    static Windows::System::User FindUserFromDeviceId(hstring_view deviceId);
    static event_token UserDeviceAssociationChanged(const Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs> & handler);
    using UserDeviceAssociationChanged_revoker = factory_event_revoker<IUserDeviceAssociationStatics>;
    static UserDeviceAssociationChanged_revoker UserDeviceAssociationChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::System::UserDeviceAssociationChangedEventArgs> & handler);
    static void UserDeviceAssociationChanged(event_token token);
};

struct WINRT_EBO UserDeviceAssociationChangedEventArgs :
    Windows::System::IUserDeviceAssociationChangedEventArgs
{
    UserDeviceAssociationChangedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO UserPicker :
    Windows::System::IUserPicker
{
    UserPicker(std::nullptr_t) noexcept {}
    UserPicker();
    static bool IsSupported();
};

struct WINRT_EBO UserWatcher :
    Windows::System::IUserWatcher
{
    UserWatcher(std::nullptr_t) noexcept {}
};

}

}
