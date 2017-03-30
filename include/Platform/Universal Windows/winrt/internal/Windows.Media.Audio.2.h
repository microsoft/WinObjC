// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.Audio.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Media.Effects.1.h"
#include "Windows.Foundation.2.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
#define WINRT_GENERIC_604d0c4c_91de_5c2a_935f_362f13eaf800
template <> struct __declspec(uuid("604d0c4c-91de-5c2a-935f-362f13eaf800")) __declspec(novtable) IReference<Windows::Foundation::TimeSpan> : impl_IReference<Windows::Foundation::TimeSpan> {};
#endif

#ifndef WINRT_GENERIC_548cefbd_bc8a_5fa0_8df2_957440fc8bf4
#define WINRT_GENERIC_548cefbd_bc8a_5fa0_8df2_957440fc8bf4
template <> struct __declspec(uuid("548cefbd-bc8a-5fa0-8df2-957440fc8bf4")) __declspec(novtable) IReference<int32_t> : impl_IReference<int32_t> {};
#endif

#ifndef WINRT_GENERIC_3e13b431_65ce_5bfb_b0aa_fac8df958b95
#define WINRT_GENERIC_3e13b431_65ce_5bfb_b0aa_fac8df958b95
template <> struct __declspec(uuid("3e13b431-65ce-5bfb-b0aa-fac8df958b95")) __declspec(novtable) IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult> : impl_IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult> {};
#endif

#ifndef WINRT_GENERIC_71ab4481_ec4a_5ee9_a342_3a31747829b8
#define WINRT_GENERIC_71ab4481_ec4a_5ee9_a342_3a31747829b8
template <> struct __declspec(uuid("71ab4481-ec4a-5ee9-a342-3a31747829b8")) __declspec(novtable) IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> : impl_IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> {};
#endif

#ifndef WINRT_GENERIC_f810d730_de15_58e0_a5f4_c159f73669ed
#define WINRT_GENERIC_f810d730_de15_58e0_a5f4_c159f73669ed
template <> struct __declspec(uuid("f810d730-de15-58e0-a5f4-c159f73669ed")) __declspec(novtable) IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> : impl_IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> {};
#endif

#ifndef WINRT_GENERIC_473b06bf_387b_56ca_bee1_527480272b0f
#define WINRT_GENERIC_473b06bf_387b_56ca_bee1_527480272b0f
template <> struct __declspec(uuid("473b06bf-387b-56ca-bee1-527480272b0f")) __declspec(novtable) IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> : impl_IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> {};
#endif

#ifndef WINRT_GENERIC_1164517d_e953_5415_a5b3_4249a969be7b
#define WINRT_GENERIC_1164517d_e953_5415_a5b3_4249a969be7b
template <> struct __declspec(uuid("1164517d-e953-5415-a5b3-4249a969be7b")) __declspec(novtable) IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> : impl_IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> {};
#endif

#ifndef WINRT_GENERIC_e1407134_09e7_53de_b54c_8a0659397b88
#define WINRT_GENERIC_e1407134_09e7_53de_b54c_8a0659397b88
template <> struct __declspec(uuid("e1407134-09e7-53de-b54c-8a0659397b88")) __declspec(novtable) TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_899670c9_dd7f_5f12_98cb_8b17fe80a47f
#define WINRT_GENERIC_899670c9_dd7f_5f12_98cb_8b17fe80a47f
template <> struct __declspec(uuid("899670c9-dd7f-5f12-98cb-8b17fe80a47f")) __declspec(novtable) TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> : impl_TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2828a982_d849_5fc9_84ce_f9a4b3b4d341
#define WINRT_GENERIC_2828a982_d849_5fc9_84ce_f9a4b3b4d341
template <> struct __declspec(uuid("2828a982-d849-5fc9-84ce-f9a4b3b4d341")) __declspec(novtable) IVector<Windows::Media::Effects::IAudioEffectDefinition> : impl_IVector<Windows::Media::Effects::IAudioEffectDefinition> {};
#endif

#ifndef WINRT_GENERIC_8485aed1_9b0c_59d2_a206_699bf746c3ff
#define WINRT_GENERIC_8485aed1_9b0c_59d2_a206_699bf746c3ff
template <> struct __declspec(uuid("8485aed1-9b0c-59d2-a206-699bf746c3ff")) __declspec(novtable) IVectorView<Windows::Media::Audio::AudioGraphConnection> : impl_IVectorView<Windows::Media::Audio::AudioGraphConnection> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_ad59dcfe_71b0_5e16_99c2_cd90644d8ee8
#define WINRT_GENERIC_ad59dcfe_71b0_5e16_99c2_cd90644d8ee8
template <> struct __declspec(uuid("ad59dcfe-71b0-5e16-99c2-cd90644d8ee8")) __declspec(novtable) TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> : impl_TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_4530d121_bb9a_57fe_922f_a98eeedf59af
#define WINRT_GENERIC_4530d121_bb9a_57fe_922f_a98eeedf59af
template <> struct __declspec(uuid("4530d121-bb9a-57fe-922f-a98eeedf59af")) __declspec(novtable) TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> : impl_TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_4481085b_8b8b_5520_9825_e9671da2a89f
#define WINRT_GENERIC_4481085b_8b8b_5520_9825_e9671da2a89f
template <> struct __declspec(uuid("4481085b-8b8b-5520-9825-e9671da2a89f")) __declspec(novtable) TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> : impl_TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> {};
#endif

#ifndef WINRT_GENERIC_02132510_3899_5257_bed9_a43e5149d28c
#define WINRT_GENERIC_02132510_3899_5257_bed9_a43e5149d28c
template <> struct __declspec(uuid("02132510-3899-5257-bed9-a43e5149d28c")) __declspec(novtable) IAsyncOperation<winrt::Windows::Media::Transcoding::TranscodeFailureReason> : impl_IAsyncOperation<winrt::Windows::Media::Transcoding::TranscodeFailureReason> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_48f26053_ea7d_59e1_952b_fb78af42d2e2
#define WINRT_GENERIC_48f26053_ea7d_59e1_952b_fb78af42d2e2
template <> struct __declspec(uuid("48f26053-ea7d-59e1-952b-fb78af42d2e2")) __declspec(novtable) IVectorView<Windows::Media::Audio::EqualizerBand> : impl_IVectorView<Windows::Media::Audio::EqualizerBand> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_4e660bda_d438_5741_8b66_85fe72574aab
#define WINRT_GENERIC_4e660bda_d438_5741_8b66_85fe72574aab
template <> struct __declspec(uuid("4e660bda-d438-5741-8b66-85fe72574aab")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioGraphResult> : impl_AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioGraphResult> {};
#endif

#ifndef WINRT_GENERIC_6cc56450_e4e8_59c9_83d8_63e46eacb20b
#define WINRT_GENERIC_6cc56450_e4e8_59c9_83d8_63e46eacb20b
template <> struct __declspec(uuid("6cc56450-e4e8-59c9-83d8-63e46eacb20b")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> : impl_AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> {};
#endif

#ifndef WINRT_GENERIC_edbc9b59_7cae_513f_b0dc_17666d37ba77
#define WINRT_GENERIC_edbc9b59_7cae_513f_b0dc_17666d37ba77
template <> struct __declspec(uuid("edbc9b59-7cae-513f-b0dc-17666d37ba77")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> : impl_AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> {};
#endif

#ifndef WINRT_GENERIC_504d1efd_c11c_506e_b8c9_af17c771efb5
#define WINRT_GENERIC_504d1efd_c11c_506e_b8c9_af17c771efb5
template <> struct __declspec(uuid("504d1efd-c11c-506e-b8c9-af17c771efb5")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioFileInputNodeResult> : impl_AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioFileInputNodeResult> {};
#endif

#ifndef WINRT_GENERIC_a7a95713_a08f_5fdf_89c6_9627bcf5d80a
#define WINRT_GENERIC_a7a95713_a08f_5fdf_89c6_9627bcf5d80a
template <> struct __declspec(uuid("a7a95713-a08f-5fdf-89c6-9627bcf5d80a")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioFileOutputNodeResult> : impl_AsyncOperationCompletedHandler<Windows::Media::Audio::CreateAudioFileOutputNodeResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_ec0f39fc_6959_5423_9e1a_f7cb8e845ca1
#define WINRT_GENERIC_ec0f39fc_6959_5423_9e1a_f7cb8e845ca1
template <> struct __declspec(uuid("ec0f39fc-6959-5423-9e1a-f7cb8e845ca1")) __declspec(novtable) IIterator<Windows::Media::Effects::IAudioEffectDefinition> : impl_IIterator<Windows::Media::Effects::IAudioEffectDefinition> {};
#endif

#ifndef WINRT_GENERIC_607a20bf_32b4_5b8e_a793_3024f8d3582a
#define WINRT_GENERIC_607a20bf_32b4_5b8e_a793_3024f8d3582a
template <> struct __declspec(uuid("607a20bf-32b4-5b8e-a793-3024f8d3582a")) __declspec(novtable) IIterable<Windows::Media::Effects::IAudioEffectDefinition> : impl_IIterable<Windows::Media::Effects::IAudioEffectDefinition> {};
#endif

#ifndef WINRT_GENERIC_de9e6a7f_d28e_5ef1_916a_efa880b489d1
#define WINRT_GENERIC_de9e6a7f_d28e_5ef1_916a_efa880b489d1
template <> struct __declspec(uuid("de9e6a7f-d28e-5ef1-916a-efa880b489d1")) __declspec(novtable) IVectorView<Windows::Media::Effects::IAudioEffectDefinition> : impl_IVectorView<Windows::Media::Effects::IAudioEffectDefinition> {};
#endif

#ifndef WINRT_GENERIC_4af6a8fc_e7fb_5957_91c1_2df9600b22eb
#define WINRT_GENERIC_4af6a8fc_e7fb_5957_91c1_2df9600b22eb
template <> struct __declspec(uuid("4af6a8fc-e7fb-5957-91c1-2df9600b22eb")) __declspec(novtable) IIterator<Windows::Media::Audio::AudioGraphConnection> : impl_IIterator<Windows::Media::Audio::AudioGraphConnection> {};
#endif

#ifndef WINRT_GENERIC_96168d06_a51a_5480_9403_fbd7631e3b3c
#define WINRT_GENERIC_96168d06_a51a_5480_9403_fbd7631e3b3c
template <> struct __declspec(uuid("96168d06-a51a-5480-9403-fbd7631e3b3c")) __declspec(novtable) IIterable<Windows::Media::Audio::AudioGraphConnection> : impl_IIterable<Windows::Media::Audio::AudioGraphConnection> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_c42ae2bf_e194_5179_b8ad_03b51c04e1da
#define WINRT_GENERIC_c42ae2bf_e194_5179_b8ad_03b51c04e1da
template <> struct __declspec(uuid("c42ae2bf-e194-5179-b8ad-03b51c04e1da")) __declspec(novtable) AsyncOperationCompletedHandler<winrt::Windows::Media::Transcoding::TranscodeFailureReason> : impl_AsyncOperationCompletedHandler<winrt::Windows::Media::Transcoding::TranscodeFailureReason> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_eb4f8b6a_7928_5f2f_b7f2_7b90c084356f
#define WINRT_GENERIC_eb4f8b6a_7928_5f2f_b7f2_7b90c084356f
template <> struct __declspec(uuid("eb4f8b6a-7928-5f2f-b7f2-7b90c084356f")) __declspec(novtable) IIterator<Windows::Media::Audio::EqualizerBand> : impl_IIterator<Windows::Media::Audio::EqualizerBand> {};
#endif

#ifndef WINRT_GENERIC_6f76d148_023e_565a_9f09_4ad4a32ad74f
#define WINRT_GENERIC_6f76d148_023e_565a_9f09_4ad4a32ad74f
template <> struct __declspec(uuid("6f76d148-023e-565a-9f09-4ad4a32ad74f")) __declspec(novtable) IIterable<Windows::Media::Audio::EqualizerBand> : impl_IIterable<Windows::Media::Audio::EqualizerBand> {};
#endif


}

namespace Windows::Media::Audio {

struct IAudioDeviceInputNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioDeviceInputNode>,
    impl::require<IAudioDeviceInputNode, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioInputNode, Windows::Media::Audio::IAudioNode>
{
    IAudioDeviceInputNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioDeviceOutputNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioDeviceOutputNode>,
    impl::require<IAudioDeviceOutputNode, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioNode>
{
    IAudioDeviceOutputNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioFileInputNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioFileInputNode>,
    impl::require<IAudioFileInputNode, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioInputNode, Windows::Media::Audio::IAudioNode>
{
    IAudioFileInputNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioFileOutputNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioFileOutputNode>,
    impl::require<IAudioFileOutputNode, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioNode>
{
    IAudioFileOutputNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioFrameCompletedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioFrameCompletedEventArgs>
{
    IAudioFrameCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioFrameInputNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioFrameInputNode>,
    impl::require<IAudioFrameInputNode, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioInputNode, Windows::Media::Audio::IAudioNode>
{
    IAudioFrameInputNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioFrameOutputNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioFrameOutputNode>,
    impl::require<IAudioFrameOutputNode, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioNode>
{
    IAudioFrameOutputNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioGraph :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioGraph>,
    impl::require<IAudioGraph, Windows::Foundation::IClosable>
{
    IAudioGraph(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioGraph2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioGraph2>,
    impl::require<IAudioGraph2, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioGraph>
{
    IAudioGraph2(std::nullptr_t = nullptr) noexcept {}
    using impl_IAudioGraph::CreateDeviceInputNodeAsync;
    using impl_IAudioGraph::CreateFileInputNodeAsync;
    using impl_IAudioGraph::CreateFrameInputNode;
    using impl_IAudioGraph::CreateSubmixNode;
    using impl_IAudioGraph2::CreateDeviceInputNodeAsync;
    using impl_IAudioGraph2::CreateFileInputNodeAsync;
    using impl_IAudioGraph2::CreateFrameInputNode;
    using impl_IAudioGraph2::CreateSubmixNode;
};

struct IAudioGraphConnection :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioGraphConnection>
{
    IAudioGraphConnection(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioGraphSettings :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioGraphSettings>
{
    IAudioGraphSettings(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioGraphSettingsFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioGraphSettingsFactory>
{
    IAudioGraphSettingsFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioGraphStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioGraphStatics>
{
    IAudioGraphStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioGraphUnrecoverableErrorOccurredEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioGraphUnrecoverableErrorOccurredEventArgs>
{
    IAudioGraphUnrecoverableErrorOccurredEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioInputNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioInputNode>,
    impl::require<IAudioInputNode, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioNode>
{
    IAudioInputNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioInputNode2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioInputNode2>,
    impl::require<IAudioInputNode2, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioInputNode, Windows::Media::Audio::IAudioNode>
{
    IAudioInputNode2(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNode :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNode>,
    impl::require<IAudioNode, Windows::Foundation::IClosable>
{
    IAudioNode(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitter :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitter>
{
    IAudioNodeEmitter(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitter2 :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitter2>
{
    IAudioNodeEmitter2(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitterConeProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitterConeProperties>
{
    IAudioNodeEmitterConeProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitterDecayModel :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitterDecayModel>
{
    IAudioNodeEmitterDecayModel(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitterDecayModelStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitterDecayModelStatics>
{
    IAudioNodeEmitterDecayModelStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitterFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitterFactory>
{
    IAudioNodeEmitterFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitterNaturalDecayModelProperties :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitterNaturalDecayModelProperties>
{
    IAudioNodeEmitterNaturalDecayModelProperties(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitterShape :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitterShape>
{
    IAudioNodeEmitterShape(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeEmitterShapeStatics :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeEmitterShapeStatics>
{
    IAudioNodeEmitterShapeStatics(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeListener :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeListener>
{
    IAudioNodeListener(std::nullptr_t = nullptr) noexcept {}
};

struct IAudioNodeWithListener :
    Windows::Foundation::IInspectable,
    impl::consume<IAudioNodeWithListener>,
    impl::require<IAudioNodeWithListener, Windows::Foundation::IClosable, Windows::Media::Audio::IAudioNode>
{
    IAudioNodeWithListener(std::nullptr_t = nullptr) noexcept {}
};

struct ICreateAudioDeviceInputNodeResult :
    Windows::Foundation::IInspectable,
    impl::consume<ICreateAudioDeviceInputNodeResult>
{
    ICreateAudioDeviceInputNodeResult(std::nullptr_t = nullptr) noexcept {}
};

struct ICreateAudioDeviceOutputNodeResult :
    Windows::Foundation::IInspectable,
    impl::consume<ICreateAudioDeviceOutputNodeResult>
{
    ICreateAudioDeviceOutputNodeResult(std::nullptr_t = nullptr) noexcept {}
};

struct ICreateAudioFileInputNodeResult :
    Windows::Foundation::IInspectable,
    impl::consume<ICreateAudioFileInputNodeResult>
{
    ICreateAudioFileInputNodeResult(std::nullptr_t = nullptr) noexcept {}
};

struct ICreateAudioFileOutputNodeResult :
    Windows::Foundation::IInspectable,
    impl::consume<ICreateAudioFileOutputNodeResult>
{
    ICreateAudioFileOutputNodeResult(std::nullptr_t = nullptr) noexcept {}
};

struct ICreateAudioGraphResult :
    Windows::Foundation::IInspectable,
    impl::consume<ICreateAudioGraphResult>
{
    ICreateAudioGraphResult(std::nullptr_t = nullptr) noexcept {}
};

struct IEchoEffectDefinition :
    Windows::Foundation::IInspectable,
    impl::consume<IEchoEffectDefinition>,
    impl::require<IEchoEffectDefinition, Windows::Media::Effects::IAudioEffectDefinition>
{
    IEchoEffectDefinition(std::nullptr_t = nullptr) noexcept {}
};

struct IEchoEffectDefinitionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEchoEffectDefinitionFactory>
{
    IEchoEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IEqualizerBand :
    Windows::Foundation::IInspectable,
    impl::consume<IEqualizerBand>
{
    IEqualizerBand(std::nullptr_t = nullptr) noexcept {}
};

struct IEqualizerEffectDefinition :
    Windows::Foundation::IInspectable,
    impl::consume<IEqualizerEffectDefinition>,
    impl::require<IEqualizerEffectDefinition, Windows::Media::Effects::IAudioEffectDefinition>
{
    IEqualizerEffectDefinition(std::nullptr_t = nullptr) noexcept {}
};

struct IEqualizerEffectDefinitionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IEqualizerEffectDefinitionFactory>
{
    IEqualizerEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IFrameInputNodeQuantumStartedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<IFrameInputNodeQuantumStartedEventArgs>
{
    IFrameInputNodeQuantumStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ILimiterEffectDefinition :
    Windows::Foundation::IInspectable,
    impl::consume<ILimiterEffectDefinition>,
    impl::require<ILimiterEffectDefinition, Windows::Media::Effects::IAudioEffectDefinition>
{
    ILimiterEffectDefinition(std::nullptr_t = nullptr) noexcept {}
};

struct ILimiterEffectDefinitionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ILimiterEffectDefinitionFactory>
{
    ILimiterEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
};

struct IReverbEffectDefinition :
    Windows::Foundation::IInspectable,
    impl::consume<IReverbEffectDefinition>,
    impl::require<IReverbEffectDefinition, Windows::Media::Effects::IAudioEffectDefinition>
{
    IReverbEffectDefinition(std::nullptr_t = nullptr) noexcept {}
};

struct IReverbEffectDefinitionFactory :
    Windows::Foundation::IInspectable,
    impl::consume<IReverbEffectDefinitionFactory>
{
    IReverbEffectDefinitionFactory(std::nullptr_t = nullptr) noexcept {}
};

}

}
