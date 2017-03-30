// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.ApplicationModel.AppService.2.h"

WINRT_EXPORT namespace winrt {

namespace Windows::ApplicationModel::AppService {

struct AppServiceCatalog
{
    AppServiceCatalog() = delete;
    static Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVectorView<Windows::ApplicationModel::AppInfo>> FindAppServiceProvidersAsync(hstring_view appServiceName);
};

struct WINRT_EBO AppServiceClosedEventArgs :
    Windows::ApplicationModel::AppService::IAppServiceClosedEventArgs
{
    AppServiceClosedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppServiceConnection :
    Windows::ApplicationModel::AppService::IAppServiceConnection,
    impl::require<AppServiceConnection, Windows::ApplicationModel::AppService::IAppServiceConnection2>
{
    AppServiceConnection(std::nullptr_t) noexcept {}
    AppServiceConnection();
};

struct WINRT_EBO AppServiceDeferral :
    Windows::ApplicationModel::AppService::IAppServiceDeferral
{
    AppServiceDeferral(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppServiceRequest :
    Windows::ApplicationModel::AppService::IAppServiceRequest
{
    AppServiceRequest(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppServiceRequestReceivedEventArgs :
    Windows::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs
{
    AppServiceRequestReceivedEventArgs(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppServiceResponse :
    Windows::ApplicationModel::AppService::IAppServiceResponse
{
    AppServiceResponse(std::nullptr_t) noexcept {}
};

struct WINRT_EBO AppServiceTriggerDetails :
    Windows::ApplicationModel::AppService::IAppServiceTriggerDetails,
    impl::require<AppServiceTriggerDetails, Windows::ApplicationModel::AppService::IAppServiceTriggerDetails2>
{
    AppServiceTriggerDetails(std::nullptr_t) noexcept {}
};

}

}
