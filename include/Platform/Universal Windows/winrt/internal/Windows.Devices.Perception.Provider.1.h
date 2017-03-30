// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Devices.Perception.Provider.0.h"
#include "Windows.Devices.Perception.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Foundation.Collections.0.h"
#include "Windows.Graphics.Imaging.0.h"
#include "Windows.Media.0.h"
#include "Windows.Foundation.Collections.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Devices::Perception::Provider {

struct __declspec(uuid("3ae651d6-9669-4106-9fae-4835c1b96104")) __declspec(novtable) IKnownPerceptionFrameKindStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Color(hstring * value) = 0;
    virtual HRESULT __stdcall get_Depth(hstring * value) = 0;
    virtual HRESULT __stdcall get_Infrared(hstring * value) = 0;
};

struct __declspec(uuid("172c4882-2fd9-4c4e-ba34-fdf20a73dde5")) __declspec(novtable) IPerceptionControlGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameProviderIds(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("2f1af2e0-baf1-453b-bed4-cd9d4619154c")) __declspec(novtable) IPerceptionControlGroupFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<hstring> * ids, Windows::Devices::Perception::Provider::IPerceptionControlGroup ** result) = 0;
};

struct __declspec(uuid("b4131a82-dff5-4047-8a19-3b4d805f7176")) __declspec(novtable) IPerceptionCorrelation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_TargetId(hstring * value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall get_Orientation(Windows::Foundation::Numerics::quaternion * value) = 0;
};

struct __declspec(uuid("d4a6c425-2884-4a8f-8134-2835d7286cbf")) __declspec(novtable) IPerceptionCorrelationFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(hstring targetId, Windows::Foundation::Numerics::float3 position, Windows::Foundation::Numerics::quaternion orientation, Windows::Devices::Perception::Provider::IPerceptionCorrelation ** result) = 0;
};

struct __declspec(uuid("752a0906-36a7-47bb-9b79-56cc6b746770")) __declspec(novtable) IPerceptionCorrelationGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RelativeLocations(Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::Provider::PerceptionCorrelation> ** value) = 0;
};

struct __declspec(uuid("7dfe2088-63df-48ed-83b1-4ab829132995")) __declspec(novtable) IPerceptionCorrelationGroupFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<Windows::Devices::Perception::Provider::PerceptionCorrelation> * relativeLocations, Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup ** result) = 0;
};

struct __declspec(uuid("e8019814-4a91-41b0-83a6-881a1775353e")) __declspec(novtable) IPerceptionFaceAuthenticationGroup : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameProviderIds(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
};

struct __declspec(uuid("e68a05d4-b60c-40f4-bcb9-f24d46467320")) __declspec(novtable) IPerceptionFaceAuthenticationGroupFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<hstring> * ids, Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler * startHandler, Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler * stopHandler, Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup ** result) = 0;
};

struct __declspec(uuid("7cfe7825-54bb-4d9d-bec5-8ef66151d2ac")) __declspec(novtable) IPerceptionFrame : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RelativeTime(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_RelativeTime(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall get_FrameData(Windows::Foundation::IMemoryBuffer ** value) = 0;
};

struct __declspec(uuid("794f7ab9-b37d-3b33-a10d-30626419ce65")) __declspec(novtable) IPerceptionFrameProvider : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_FrameProviderInfo(Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo ** result) = 0;
    virtual HRESULT __stdcall get_Available(bool * value) = 0;
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IPropertySet ** value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_SetProperty(Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest * value) = 0;
};

struct __declspec(uuid("cca959e8-797e-4e83-9b87-036a74142fc4")) __declspec(novtable) IPerceptionFrameProviderInfo : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Id(hstring * value) = 0;
    virtual HRESULT __stdcall put_Id(hstring value) = 0;
    virtual HRESULT __stdcall get_DisplayName(hstring * value) = 0;
    virtual HRESULT __stdcall put_DisplayName(hstring value) = 0;
    virtual HRESULT __stdcall get_DeviceKind(hstring * value) = 0;
    virtual HRESULT __stdcall put_DeviceKind(hstring value) = 0;
    virtual HRESULT __stdcall get_FrameKind(hstring * value) = 0;
    virtual HRESULT __stdcall put_FrameKind(hstring value) = 0;
    virtual HRESULT __stdcall get_Hidden(bool * value) = 0;
    virtual HRESULT __stdcall put_Hidden(bool value) = 0;
};

struct __declspec(uuid("a959ce07-ead3-33df-8ec1-b924abe019c4")) __declspec(novtable) IPerceptionFrameProviderManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetFrameProvider(Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo * frameProviderInfo, Windows::Devices::Perception::Provider::IPerceptionFrameProvider ** result) = 0;
};

struct __declspec(uuid("ae8386e6-cad9-4359-8f96-8eae51810526")) __declspec(novtable) IPerceptionFrameProviderManagerServiceStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_RegisterFrameProviderInfo(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo * frameProviderInfo) = 0;
    virtual HRESULT __stdcall abi_UnregisterFrameProviderInfo(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo * frameProviderInfo) = 0;
    virtual HRESULT __stdcall abi_RegisterFaceAuthenticationGroup(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup * faceAuthenticationGroup) = 0;
    virtual HRESULT __stdcall abi_UnregisterFaceAuthenticationGroup(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup * faceAuthenticationGroup) = 0;
    virtual HRESULT __stdcall abi_RegisterControlGroup(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionControlGroup * controlGroup) = 0;
    virtual HRESULT __stdcall abi_UnregisterControlGroup(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionControlGroup * controlGroup) = 0;
    virtual HRESULT __stdcall abi_RegisterCorrelationGroup(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup * correlationGroup) = 0;
    virtual HRESULT __stdcall abi_UnregisterCorrelationGroup(Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager * manager, Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup * correlationGroup) = 0;
    virtual HRESULT __stdcall abi_UpdateAvailabilityForProvider(Windows::Devices::Perception::Provider::IPerceptionFrameProvider * provider, bool available) = 0;
    virtual HRESULT __stdcall abi_PublishFrameForProvider(Windows::Devices::Perception::Provider::IPerceptionFrameProvider * provider, Windows::Devices::Perception::Provider::IPerceptionFrame * frame) = 0;
};

struct __declspec(uuid("3c5aeb51-350b-4df8-9414-59e09815510b")) __declspec(novtable) IPerceptionPropertyChangeRequest : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall get_Value(Windows::Foundation::IInspectable ** value) = 0;
    virtual HRESULT __stdcall get_Status(winrt::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus * value) = 0;
    virtual HRESULT __stdcall put_Status(winrt::Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus value) = 0;
    virtual HRESULT __stdcall abi_GetDeferral(Windows::Foundation::IDeferral ** result) = 0;
};

struct __declspec(uuid("4c38a7da-fdd8-4ed4-a039-2a6f9b235038")) __declspec(novtable) IPerceptionVideoFrameAllocator : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_AllocateFrame(Windows::Devices::Perception::Provider::IPerceptionFrame ** value) = 0;
    virtual HRESULT __stdcall abi_CopyFromVideoFrame(Windows::Media::IVideoFrame * frame, Windows::Devices::Perception::Provider::IPerceptionFrame ** value) = 0;
};

struct __declspec(uuid("1a58b0e1-e91a-481e-b876-a89e2bbc6b33")) __declspec(novtable) IPerceptionVideoFrameAllocatorFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(uint32_t maxOutstandingFrameCountForWrite, winrt::Windows::Graphics::Imaging::BitmapPixelFormat format, Windows::Foundation::Size resolution, winrt::Windows::Graphics::Imaging::BitmapAlphaMode alpha, Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator ** result) = 0;
};

struct __declspec(uuid("74816d2a-2090-4670-8c48-ef39e7ff7c26")) __declspec(novtable) PerceptionStartFaceAuthenticationHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup * sender, bool * result) = 0;
};

struct __declspec(uuid("387ee6aa-89cd-481e-aade-dd92f70b2ad7")) __declspec(novtable) PerceptionStopFaceAuthenticationHandler : IUnknown
{
    virtual HRESULT __stdcall abi_Invoke(Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup * sender) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionControlGroup> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionControlGroup; };
template <> struct traits<Windows::Devices::Perception::Provider::PerceptionCorrelation> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionCorrelation; };
template <> struct traits<Windows::Devices::Perception::Provider::PerceptionCorrelationGroup> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup; };
template <> struct traits<Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup; };
template <> struct traits<Windows::Devices::Perception::Provider::PerceptionFrame> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionFrame; };
template <> struct traits<Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo; };
template <> struct traits<Windows::Devices::Perception::Provider::PerceptionPropertyChangeRequest> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest; };
template <> struct traits<Windows::Devices::Perception::Provider::PerceptionVideoFrameAllocator> { using default_interface = Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator; };

}

namespace Windows::Devices::Perception::Provider {

template <typename D>
struct WINRT_EBO impl_IKnownPerceptionFrameKindStatics
{
    hstring Color() const;
    hstring Depth() const;
    hstring Infrared() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionControlGroup
{
    Windows::Foundation::Collections::IVectorView<hstring> FrameProviderIds() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionControlGroupFactory
{
    Windows::Devices::Perception::Provider::PerceptionControlGroup Create(iterable<hstring> ids) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionCorrelation
{
    hstring TargetId() const;
    Windows::Foundation::Numerics::float3 Position() const;
    Windows::Foundation::Numerics::quaternion Orientation() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionCorrelationFactory
{
    Windows::Devices::Perception::Provider::PerceptionCorrelation Create(hstring_view targetId, const Windows::Foundation::Numerics::float3 & position, const Windows::Foundation::Numerics::quaternion & orientation) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionCorrelationGroup
{
    Windows::Foundation::Collections::IVectorView<Windows::Devices::Perception::Provider::PerceptionCorrelation> RelativeLocations() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionCorrelationGroupFactory
{
    Windows::Devices::Perception::Provider::PerceptionCorrelationGroup Create(iterable<Windows::Devices::Perception::Provider::PerceptionCorrelation> relativeLocations) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFaceAuthenticationGroup
{
    Windows::Foundation::Collections::IVectorView<hstring> FrameProviderIds() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFaceAuthenticationGroupFactory
{
    Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup Create(iterable<hstring> ids, const Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler & startHandler, const Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler & stopHandler) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFrame
{
    Windows::Foundation::TimeSpan RelativeTime() const;
    void RelativeTime(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::Collections::ValueSet Properties() const;
    Windows::Foundation::IMemoryBuffer FrameData() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFrameProvider
{
    Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo FrameProviderInfo() const;
    bool Available() const;
    Windows::Foundation::Collections::IPropertySet Properties() const;
    void Start() const;
    void Stop() const;
    void SetProperty(const Windows::Devices::Perception::Provider::PerceptionPropertyChangeRequest & value) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFrameProviderInfo
{
    hstring Id() const;
    void Id(hstring_view value) const;
    hstring DisplayName() const;
    void DisplayName(hstring_view value) const;
    hstring DeviceKind() const;
    void DeviceKind(hstring_view value) const;
    hstring FrameKind() const;
    void FrameKind(hstring_view value) const;
    bool Hidden() const;
    void Hidden(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFrameProviderManager
{
    Windows::Devices::Perception::Provider::IPerceptionFrameProvider GetFrameProvider(const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionFrameProviderManagerServiceStatics
{
    void RegisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo) const;
    void UnregisterFrameProviderInfo(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo & frameProviderInfo) const;
    void RegisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup) const;
    void UnregisterFaceAuthenticationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup & faceAuthenticationGroup) const;
    void RegisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup) const;
    void UnregisterControlGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionControlGroup & controlGroup) const;
    void RegisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup) const;
    void UnregisterCorrelationGroup(const Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager & manager, const Windows::Devices::Perception::Provider::PerceptionCorrelationGroup & correlationGroup) const;
    void UpdateAvailabilityForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, bool available) const;
    void PublishFrameForProvider(const Windows::Devices::Perception::Provider::IPerceptionFrameProvider & provider, const Windows::Devices::Perception::Provider::PerceptionFrame & frame) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionPropertyChangeRequest
{
    hstring Name() const;
    Windows::Foundation::IInspectable Value() const;
    Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus Status() const;
    void Status(Windows::Devices::Perception::PerceptionFrameSourcePropertyChangeStatus value) const;
    Windows::Foundation::Deferral GetDeferral() const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionVideoFrameAllocator
{
    Windows::Devices::Perception::Provider::PerceptionFrame AllocateFrame() const;
    Windows::Devices::Perception::Provider::PerceptionFrame CopyFromVideoFrame(const Windows::Media::VideoFrame & frame) const;
};

template <typename D>
struct WINRT_EBO impl_IPerceptionVideoFrameAllocatorFactory
{
    Windows::Devices::Perception::Provider::PerceptionVideoFrameAllocator Create(uint32_t maxOutstandingFrameCountForWrite, Windows::Graphics::Imaging::BitmapPixelFormat format, const Windows::Foundation::Size & resolution, Windows::Graphics::Imaging::BitmapAlphaMode alpha) const;
};

}

namespace impl {

template <> struct traits<Windows::Devices::Perception::Provider::IKnownPerceptionFrameKindStatics>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IKnownPerceptionFrameKindStatics;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IKnownPerceptionFrameKindStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionControlGroup>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroup;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionControlGroup<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionControlGroupFactory>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionControlGroupFactory;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionControlGroupFactory<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionCorrelation>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelation;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionCorrelation<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionCorrelationFactory>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationFactory;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionCorrelationFactory<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroup;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionCorrelationGroup<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionCorrelationGroupFactory>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionCorrelationGroupFactory;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionCorrelationGroupFactory<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroup;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionFaceAuthenticationGroup<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroupFactory>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionFaceAuthenticationGroupFactory;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionFaceAuthenticationGroupFactory<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionFrame>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionFrame;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionFrame<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionFrameProvider>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProvider;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionFrameProvider<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderInfo;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionFrameProviderInfo<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManager;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionFrameProviderManager<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionFrameProviderManagerServiceStatics>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionFrameProviderManagerServiceStatics;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionFrameProviderManagerServiceStatics<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionPropertyChangeRequest;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionPropertyChangeRequest<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocator;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionVideoFrameAllocator<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocatorFactory>
{
    using abi = ABI::Windows::Devices::Perception::Provider::IPerceptionVideoFrameAllocatorFactory;
    template <typename D> using consume = Windows::Devices::Perception::Provider::impl_IPerceptionVideoFrameAllocatorFactory<D>;
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionStartFaceAuthenticationHandler;
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionStopFaceAuthenticationHandler;
};

template <> struct traits<Windows::Devices::Perception::Provider::KnownPerceptionFrameKind>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.KnownPerceptionFrameKind"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionControlGroup>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionControlGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionControlGroup"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionCorrelation>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionCorrelation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionCorrelation"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionCorrelationGroup>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionCorrelationGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionCorrelationGroup"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionFaceAuthenticationGroup;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionFaceAuthenticationGroup"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionFrame>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionFrame;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionFrame"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionFrameProviderInfo;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionFrameProviderInfo"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionFrameProviderManagerService>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionFrameProviderManagerService"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionPropertyChangeRequest>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionPropertyChangeRequest;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionPropertyChangeRequest"; }
};

template <> struct traits<Windows::Devices::Perception::Provider::PerceptionVideoFrameAllocator>
{
    using abi = ABI::Windows::Devices::Perception::Provider::PerceptionVideoFrameAllocator;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Devices.Perception.Provider.PerceptionVideoFrameAllocator"; }
};

}

}
