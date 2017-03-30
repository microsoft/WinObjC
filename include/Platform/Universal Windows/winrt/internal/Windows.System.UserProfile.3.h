// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.System.UserProfile.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::System::UserProfile {

struct AdvertisingManager
{
    AdvertisingManager() = delete;
    static hstring AdvertisingId();
    static Windows::System::UserProfile::AdvertisingManagerForUser GetForUser(const Windows::System::User & user);
};

struct WINRT_EBO AdvertisingManagerForUser :
    Windows::System::UserProfile::IAdvertisingManagerForUser
{
    AdvertisingManagerForUser(std::nullptr_t) noexcept {}
};

struct WINRT_EBO FirstSignInSettings :
    Windows::System::UserProfile::IFirstSignInSettings
{
    FirstSignInSettings(std::nullptr_t) noexcept {}
    static Windows::System::UserProfile::FirstSignInSettings GetDefault();
};

struct GlobalizationPreferences
{
    GlobalizationPreferences() = delete;
    static Windows::Foundation::Collections::IVectorView<hstring> Calendars();
    static Windows::Foundation::Collections::IVectorView<hstring> Clocks();
    static Windows::Foundation::Collections::IVectorView<hstring> Currencies();
    static Windows::Foundation::Collections::IVectorView<hstring> Languages();
    static hstring HomeGeographicRegion();
    static Windows::Globalization::DayOfWeek WeekStartsOn();
};

struct LockScreen
{
    LockScreen() = delete;
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::UserProfile::SetImageFeedResult> RequestSetImageFeedAsync(const Windows::Foundation::Uri & syndicationFeedUri);
    static bool TryRemoveImageFeed();
    static Windows::Foundation::Uri OriginalImageFile();
    static Windows::Storage::Streams::IRandomAccessStream GetImageStream();
    static Windows::Foundation::IAsyncAction SetImageFileAsync(const Windows::Storage::IStorageFile & value);
    static Windows::Foundation::IAsyncAction SetImageStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & value);
};

struct UserInformation
{
    UserInformation() = delete;
    static bool AccountPictureChangeEnabled();
    static bool NameAccessAllowed();
    static Windows::Storage::IStorageFile GetAccountPicture(Windows::System::UserProfile::AccountPictureKind kind);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::UserProfile::SetAccountPictureResult> SetAccountPictureAsync(const Windows::Storage::IStorageFile & image);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::UserProfile::SetAccountPictureResult> SetAccountPicturesAsync(const Windows::Storage::IStorageFile & smallImage, const Windows::Storage::IStorageFile & largeImage, const Windows::Storage::IStorageFile & video);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::UserProfile::SetAccountPictureResult> SetAccountPictureFromStreamAsync(const Windows::Storage::Streams::IRandomAccessStream & image);
    static Windows::Foundation::IAsyncOperation<winrt::Windows::System::UserProfile::SetAccountPictureResult> SetAccountPicturesFromStreamsAsync(const Windows::Storage::Streams::IRandomAccessStream & smallImage, const Windows::Storage::Streams::IRandomAccessStream & largeImage, const Windows::Storage::Streams::IRandomAccessStream & video);
    static event_token AccountPictureChanged(const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler);
    using AccountPictureChanged_revoker = factory_event_revoker<IUserInformationStatics>;
    static AccountPictureChanged_revoker AccountPictureChanged(auto_revoke_t, const Windows::Foundation::EventHandler<Windows::Foundation::IInspectable> & changeHandler);
    static void AccountPictureChanged(event_token token);
    static Windows::Foundation::IAsyncOperation<hstring> GetDisplayNameAsync();
    static Windows::Foundation::IAsyncOperation<hstring> GetFirstNameAsync();
    static Windows::Foundation::IAsyncOperation<hstring> GetLastNameAsync();
    static Windows::Foundation::IAsyncOperation<hstring> GetPrincipalNameAsync();
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Uri> GetSessionInitiationProtocolUriAsync();
    static Windows::Foundation::IAsyncOperation<hstring> GetDomainNameAsync();
};

struct WINRT_EBO UserProfilePersonalizationSettings :
    Windows::System::UserProfile::IUserProfilePersonalizationSettings
{
    UserProfilePersonalizationSettings(std::nullptr_t) noexcept {}
    static Windows::System::UserProfile::UserProfilePersonalizationSettings Current();
    static bool IsSupported();
};

}

}
