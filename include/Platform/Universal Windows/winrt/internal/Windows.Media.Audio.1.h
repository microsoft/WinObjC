// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.Audio.0.h"
#include "Windows.Devices.Enumeration.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Media.0.h"
#include "Windows.Media.Capture.0.h"
#include "Windows.Media.Effects.0.h"
#include "Windows.Media.MediaProperties.0.h"
#include "Windows.Media.Render.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Foundation.1.h"
#include "Windows.Media.Effects.1.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Media.Transcoding.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Audio {

struct __declspec(uuid("b01b6be1-6f4e-49e2-ac01-559d62beb3a9")) __declspec(novtable) IAudioDeviceInputNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Device(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
};

struct __declspec(uuid("362edbff-ff1c-4434-9e0f-bd2ef522ac82")) __declspec(novtable) IAudioDeviceOutputNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Device(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
};

struct __declspec(uuid("905b67c8-6f65-4cd4-8890-4694843c276d")) __declspec(novtable) IAudioFileInputNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_PlaybackSpeedFactor(double value) = 0;
    virtual HRESULT __stdcall get_PlaybackSpeedFactor(double * value) = 0;
    virtual HRESULT __stdcall get_Position(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall abi_Seek(Windows::Foundation::TimeSpan position) = 0;
    virtual HRESULT __stdcall get_StartTime(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_StartTime(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_EndTime(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> ** value) = 0;
    virtual HRESULT __stdcall put_EndTime(Windows::Foundation::IReference<Windows::Foundation::TimeSpan> * value) = 0;
    virtual HRESULT __stdcall get_LoopCount(Windows::Foundation::IReference<int32_t> ** value) = 0;
    virtual HRESULT __stdcall put_LoopCount(Windows::Foundation::IReference<int32_t> * value) = 0;
    virtual HRESULT __stdcall get_Duration(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall get_SourceFile(Windows::Storage::IStorageFile ** value) = 0;
    virtual HRESULT __stdcall add_FileCompleted(Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_FileCompleted(event_token token) = 0;
};

struct __declspec(uuid("50e01980-5166-4093-80f8-ada00089e9cf")) __declspec(novtable) IAudioFileOutputNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_File(Windows::Storage::IStorageFile ** value) = 0;
    virtual HRESULT __stdcall get_FileEncodingProfile(Windows::Media::MediaProperties::IMediaEncodingProfile ** value) = 0;
    virtual HRESULT __stdcall abi_FinalizeAsync(Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Transcoding::TranscodeFailureReason> ** result) = 0;
};

struct __declspec(uuid("dc7c829e-0208-4504-a5a8-f0f268920a65")) __declspec(novtable) IAudioFrameCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Frame(Windows::Media::IAudioFrame ** value) = 0;
};

struct __declspec(uuid("01b266c7-fd96-4ff5-a3c5-d27a9bf44237")) __declspec(novtable) IAudioFrameInputNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_PlaybackSpeedFactor(double value) = 0;
    virtual HRESULT __stdcall get_PlaybackSpeedFactor(double * value) = 0;
    virtual HRESULT __stdcall abi_AddFrame(Windows::Media::IAudioFrame * frame) = 0;
    virtual HRESULT __stdcall abi_DiscardQueuedFrames() = 0;
    virtual HRESULT __stdcall get_QueuedSampleCount(uint64_t * value) = 0;
    virtual HRESULT __stdcall add_AudioFrameCompleted(Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_AudioFrameCompleted(event_token token) = 0;
    virtual HRESULT __stdcall add_QuantumStarted(Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QuantumStarted(event_token token) = 0;
};

struct __declspec(uuid("b847371b-3299-45f5-88b3-c9d12a3f1cc8")) __declspec(novtable) IAudioFrameOutputNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_GetFrame(Windows::Media::IAudioFrame ** audioFrame) = 0;
};

struct __declspec(uuid("1ad46eed-e48c-4e14-9660-2c4f83e9cdd8")) __declspec(novtable) IAudioGraph : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFrameInputNode(Windows::Media::Audio::IAudioFrameInputNode ** frameInputNode) = 0;
    virtual HRESULT __stdcall abi_CreateFrameInputNodeWithFormat(Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Media::Audio::IAudioFrameInputNode ** frameInputNode) = 0;
    virtual HRESULT __stdcall abi_CreateDeviceInputNodeAsync(winrt::Windows::Media::Capture::MediaCategory category, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDeviceInputNodeWithFormatAsync(winrt::Windows::Media::Capture::MediaCategory category, Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateDeviceInputNodeWithFormatOnDeviceAsync(winrt::Windows::Media::Capture::MediaCategory category, Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Devices::Enumeration::IDeviceInformation * device, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFrameOutputNode(Windows::Media::Audio::IAudioFrameOutputNode ** frameOutputNode) = 0;
    virtual HRESULT __stdcall abi_CreateFrameOutputNodeWithFormat(Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Media::Audio::IAudioFrameOutputNode ** frameOutputNode) = 0;
    virtual HRESULT __stdcall abi_CreateDeviceOutputNodeAsync(Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFileInputNodeAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFileOutputNodeAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFileOutputNodeWithFileProfileAsync(Windows::Storage::IStorageFile * file, Windows::Media::MediaProperties::IMediaEncodingProfile * fileEncodingProfile, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateSubmixNode(Windows::Media::Audio::IAudioInputNode ** submixNode) = 0;
    virtual HRESULT __stdcall abi_CreateSubmixNodeWithFormat(Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Media::Audio::IAudioInputNode ** submixNode) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_ResetAllNodes() = 0;
    virtual HRESULT __stdcall add_QuantumStarted(Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QuantumStarted(event_token token) = 0;
    virtual HRESULT __stdcall add_QuantumProcessed(Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_QuantumProcessed(event_token token) = 0;
    virtual HRESULT __stdcall add_UnrecoverableErrorOccurred(Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> * handler, event_token * token) = 0;
    virtual HRESULT __stdcall remove_UnrecoverableErrorOccurred(event_token token) = 0;
    virtual HRESULT __stdcall get_CompletedQuantumCount(uint64_t * value) = 0;
    virtual HRESULT __stdcall get_EncodingProperties(Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall get_LatencyInSamples(int32_t * value) = 0;
    virtual HRESULT __stdcall get_PrimaryRenderDevice(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
    virtual HRESULT __stdcall get_RenderDeviceAudioProcessing(winrt::Windows::Media::AudioProcessing * value) = 0;
    virtual HRESULT __stdcall get_SamplesPerQuantum(int32_t * value) = 0;
};

struct __declspec(uuid("4e4c3bd5-4fc1-45f6-a947-3cd38f4fd839")) __declspec(novtable) IAudioGraph2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateFrameInputNodeWithFormatAndEmitter(Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Media::Audio::IAudioNodeEmitter * emitter, Windows::Media::Audio::IAudioFrameInputNode ** frameInputNode) = 0;
    virtual HRESULT __stdcall abi_CreateDeviceInputNodeWithFormatAndEmitterOnDeviceAsync(winrt::Windows::Media::Capture::MediaCategory category, Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Devices::Enumeration::IDeviceInformation * device, Windows::Media::Audio::IAudioNodeEmitter * emitter, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateFileInputNodeWithEmitterAsync(Windows::Storage::IStorageFile * file, Windows::Media::Audio::IAudioNodeEmitter * emitter, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> ** result) = 0;
    virtual HRESULT __stdcall abi_CreateSubmixNodeWithFormatAndEmitter(Windows::Media::MediaProperties::IAudioEncodingProperties * encodingProperties, Windows::Media::Audio::IAudioNodeEmitter * emitter, Windows::Media::Audio::IAudioInputNode ** submixNode) = 0;
    virtual HRESULT __stdcall abi_CreateBatchUpdater(Windows::Foundation::IClosable ** updater) = 0;
};

struct __declspec(uuid("763070ed-d04e-4fac-b233-600b42edd469")) __declspec(novtable) IAudioGraphConnection : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Destination(Windows::Media::Audio::IAudioNode ** value) = 0;
    virtual HRESULT __stdcall put_Gain(double value) = 0;
    virtual HRESULT __stdcall get_Gain(double * value) = 0;
};

struct __declspec(uuid("1d59647f-e6fe-4628-84f8-9d8bdba25785")) __declspec(novtable) IAudioGraphSettings : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EncodingProperties(Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall put_EncodingProperties(Windows::Media::MediaProperties::IAudioEncodingProperties * value) = 0;
    virtual HRESULT __stdcall get_PrimaryRenderDevice(Windows::Devices::Enumeration::IDeviceInformation ** value) = 0;
    virtual HRESULT __stdcall put_PrimaryRenderDevice(Windows::Devices::Enumeration::IDeviceInformation * value) = 0;
    virtual HRESULT __stdcall get_QuantumSizeSelectionMode(winrt::Windows::Media::Audio::QuantumSizeSelectionMode * value) = 0;
    virtual HRESULT __stdcall put_QuantumSizeSelectionMode(winrt::Windows::Media::Audio::QuantumSizeSelectionMode value) = 0;
    virtual HRESULT __stdcall get_DesiredSamplesPerQuantum(int32_t * value) = 0;
    virtual HRESULT __stdcall put_DesiredSamplesPerQuantum(int32_t value) = 0;
    virtual HRESULT __stdcall get_AudioRenderCategory(winrt::Windows::Media::Render::AudioRenderCategory * value) = 0;
    virtual HRESULT __stdcall put_AudioRenderCategory(winrt::Windows::Media::Render::AudioRenderCategory value) = 0;
    virtual HRESULT __stdcall get_DesiredRenderDeviceAudioProcessing(winrt::Windows::Media::AudioProcessing * value) = 0;
    virtual HRESULT __stdcall put_DesiredRenderDeviceAudioProcessing(winrt::Windows::Media::AudioProcessing value) = 0;
};

struct __declspec(uuid("a5d91cc6-c2eb-4a61-a214-1d66d75f83da")) __declspec(novtable) IAudioGraphSettingsFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Media::Render::AudioRenderCategory audioRenderCategory, Windows::Media::Audio::IAudioGraphSettings ** value) = 0;
};

struct __declspec(uuid("76ec3132-e159-4ab7-a82a-17beb4b31e94")) __declspec(novtable) IAudioGraphStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAsync(Windows::Media::Audio::IAudioGraphSettings * settings, Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult> ** result) = 0;
};

struct __declspec(uuid("c3d9cbe0-3ff6-4fb3-b262-50d435c55423")) __declspec(novtable) IAudioGraphUnrecoverableErrorOccurredEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Error(winrt::Windows::Media::Audio::AudioGraphUnrecoverableError * value) = 0;
};

struct __declspec(uuid("d148005c-8428-4784-b7fd-a99d468c5d20")) __declspec(novtable) IAudioInputNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_OutgoingConnections(Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::AudioGraphConnection> ** value) = 0;
    virtual HRESULT __stdcall abi_AddOutgoingConnection(Windows::Media::Audio::IAudioNode * destination) = 0;
    virtual HRESULT __stdcall abi_AddOutgoingConnectionWithGain(Windows::Media::Audio::IAudioNode * destination, double gain) = 0;
    virtual HRESULT __stdcall abi_RemoveOutgoingConnection(Windows::Media::Audio::IAudioNode * destination) = 0;
};

struct __declspec(uuid("905156b7-ca68-4c6d-a8bc-e3ee17fe3fd2")) __declspec(novtable) IAudioInputNode2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Emitter(Windows::Media::Audio::IAudioNodeEmitter ** value) = 0;
};

struct __declspec(uuid("15389d7f-dbd8-4819-bf03-668e9357cd6d")) __declspec(novtable) IAudioNode : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_EffectDefinitions(Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> ** value) = 0;
    virtual HRESULT __stdcall put_OutgoingGain(double value) = 0;
    virtual HRESULT __stdcall get_OutgoingGain(double * value) = 0;
    virtual HRESULT __stdcall get_EncodingProperties(Windows::Media::MediaProperties::IAudioEncodingProperties ** value) = 0;
    virtual HRESULT __stdcall get_ConsumeInput(bool * value) = 0;
    virtual HRESULT __stdcall put_ConsumeInput(bool value) = 0;
    virtual HRESULT __stdcall abi_Start() = 0;
    virtual HRESULT __stdcall abi_Stop() = 0;
    virtual HRESULT __stdcall abi_Reset() = 0;
    virtual HRESULT __stdcall abi_DisableEffectsByDefinition(Windows::Media::Effects::IAudioEffectDefinition * definition) = 0;
    virtual HRESULT __stdcall abi_EnableEffectsByDefinition(Windows::Media::Effects::IAudioEffectDefinition * definition) = 0;
};

struct __declspec(uuid("3676971d-880a-47b8-adf7-1323a9d965be")) __declspec(novtable) IAudioNodeEmitter : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall put_Position(Windows::Foundation::Numerics::float3 value) = 0;
    virtual HRESULT __stdcall get_Direction(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall put_Direction(Windows::Foundation::Numerics::float3 value) = 0;
    virtual HRESULT __stdcall get_Shape(Windows::Media::Audio::IAudioNodeEmitterShape ** value) = 0;
    virtual HRESULT __stdcall get_DecayModel(Windows::Media::Audio::IAudioNodeEmitterDecayModel ** value) = 0;
    virtual HRESULT __stdcall get_Gain(double * value) = 0;
    virtual HRESULT __stdcall put_Gain(double value) = 0;
    virtual HRESULT __stdcall get_DistanceScale(double * value) = 0;
    virtual HRESULT __stdcall put_DistanceScale(double value) = 0;
    virtual HRESULT __stdcall get_DopplerScale(double * value) = 0;
    virtual HRESULT __stdcall put_DopplerScale(double value) = 0;
    virtual HRESULT __stdcall get_DopplerVelocity(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall put_DopplerVelocity(Windows::Foundation::Numerics::float3 value) = 0;
    virtual HRESULT __stdcall get_IsDopplerDisabled(bool * value) = 0;
};

struct __declspec(uuid("4ab6eecb-ec29-47f8-818c-b6b660a5aeb1")) __declspec(novtable) IAudioNodeEmitter2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SpatialAudioModel(winrt::Windows::Media::Audio::SpatialAudioModel * value) = 0;
    virtual HRESULT __stdcall put_SpatialAudioModel(winrt::Windows::Media::Audio::SpatialAudioModel value) = 0;
};

struct __declspec(uuid("e99b2cee-02ca-4375-9326-0c6ae4bcdfb5")) __declspec(novtable) IAudioNodeEmitterConeProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InnerAngle(double * value) = 0;
    virtual HRESULT __stdcall get_OuterAngle(double * value) = 0;
    virtual HRESULT __stdcall get_OuterAngleGain(double * value) = 0;
};

struct __declspec(uuid("1d1d5af7-0d53-4fa9-bd84-d5816a86f3ff")) __declspec(novtable) IAudioNodeEmitterDecayModel : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::Media::Audio::AudioNodeEmitterDecayKind * value) = 0;
    virtual HRESULT __stdcall get_MinGain(double * value) = 0;
    virtual HRESULT __stdcall get_MaxGain(double * value) = 0;
    virtual HRESULT __stdcall get_NaturalProperties(Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties ** value) = 0;
};

struct __declspec(uuid("c7787ca8-f178-462f-bc81-8dd5cbe5dae8")) __declspec(novtable) IAudioNodeEmitterDecayModelStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateNatural(double minGain, double maxGain, double unityGainDistance, double cutoffDistance, Windows::Media::Audio::IAudioNodeEmitterDecayModel ** decayModel) = 0;
    virtual HRESULT __stdcall abi_CreateCustom(double minGain, double maxGain, Windows::Media::Audio::IAudioNodeEmitterDecayModel ** decayModel) = 0;
};

struct __declspec(uuid("fdc8489a-6ad6-4ce4-b7f7-a99370df7ee9")) __declspec(novtable) IAudioNodeEmitterFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateAudioNodeEmitter(Windows::Media::Audio::IAudioNodeEmitterShape * shape, Windows::Media::Audio::IAudioNodeEmitterDecayModel * decayModel, winrt::Windows::Media::Audio::AudioNodeEmitterSettings settings, Windows::Media::Audio::IAudioNodeEmitter ** emitter) = 0;
};

struct __declspec(uuid("48934bcf-cf2c-4efc-9331-75bd22df1f0c")) __declspec(novtable) IAudioNodeEmitterNaturalDecayModelProperties : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_UnityGainDistance(double * value) = 0;
    virtual HRESULT __stdcall get_CutoffDistance(double * value) = 0;
};

struct __declspec(uuid("ea0311c5-e73d-44bc-859c-45553bbc4828")) __declspec(novtable) IAudioNodeEmitterShape : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Kind(winrt::Windows::Media::Audio::AudioNodeEmitterShapeKind * value) = 0;
    virtual HRESULT __stdcall get_ConeProperties(Windows::Media::Audio::IAudioNodeEmitterConeProperties ** value) = 0;
};

struct __declspec(uuid("57bb2771-ffa5-4b86-a779-e264aeb9145f")) __declspec(novtable) IAudioNodeEmitterShapeStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_CreateCone(double innerAngle, double outerAngle, double outerAngleGain, Windows::Media::Audio::IAudioNodeEmitterShape ** shape) = 0;
    virtual HRESULT __stdcall abi_CreateOmnidirectional(Windows::Media::Audio::IAudioNodeEmitterShape ** shape) = 0;
};

struct __declspec(uuid("d9722e16-0c0a-41da-b755-6c77835fb1eb")) __declspec(novtable) IAudioNodeListener : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Position(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall put_Position(Windows::Foundation::Numerics::float3 value) = 0;
    virtual HRESULT __stdcall get_Orientation(Windows::Foundation::Numerics::quaternion * value) = 0;
    virtual HRESULT __stdcall put_Orientation(Windows::Foundation::Numerics::quaternion value) = 0;
    virtual HRESULT __stdcall get_SpeedOfSound(double * value) = 0;
    virtual HRESULT __stdcall put_SpeedOfSound(double value) = 0;
    virtual HRESULT __stdcall get_DopplerVelocity(Windows::Foundation::Numerics::float3 * value) = 0;
    virtual HRESULT __stdcall put_DopplerVelocity(Windows::Foundation::Numerics::float3 value) = 0;
};

struct __declspec(uuid("0e0f907c-79ff-4544-9eeb-01257b15105a")) __declspec(novtable) IAudioNodeWithListener : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Listener(Windows::Media::Audio::IAudioNodeListener * value) = 0;
    virtual HRESULT __stdcall get_Listener(Windows::Media::Audio::IAudioNodeListener ** value) = 0;
};

struct __declspec(uuid("16eec7a8-1ca7-40ef-91a4-d346e0aa1bba")) __declspec(novtable) ICreateAudioDeviceInputNodeResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::Audio::AudioDeviceNodeCreationStatus * value) = 0;
    virtual HRESULT __stdcall get_DeviceInputNode(Windows::Media::Audio::IAudioDeviceInputNode ** value) = 0;
};

struct __declspec(uuid("f7776d27-1d9a-47f7-9cd4-2859cc1b7bff")) __declspec(novtable) ICreateAudioDeviceOutputNodeResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::Audio::AudioDeviceNodeCreationStatus * value) = 0;
    virtual HRESULT __stdcall get_DeviceOutputNode(Windows::Media::Audio::IAudioDeviceOutputNode ** value) = 0;
};

struct __declspec(uuid("ce83d61c-e297-4c50-9ce7-1c7a69d6bd09")) __declspec(novtable) ICreateAudioFileInputNodeResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::Audio::AudioFileNodeCreationStatus * value) = 0;
    virtual HRESULT __stdcall get_FileInputNode(Windows::Media::Audio::IAudioFileInputNode ** value) = 0;
};

struct __declspec(uuid("47d6ba7b-e909-453f-866e-5540cda734ff")) __declspec(novtable) ICreateAudioFileOutputNodeResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::Audio::AudioFileNodeCreationStatus * value) = 0;
    virtual HRESULT __stdcall get_FileOutputNode(Windows::Media::Audio::IAudioFileOutputNode ** value) = 0;
};

struct __declspec(uuid("5453ef7e-7bde-4b76-bb5d-48f79cfc8c0b")) __declspec(novtable) ICreateAudioGraphResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::Audio::AudioGraphCreationStatus * value) = 0;
    virtual HRESULT __stdcall get_Graph(Windows::Media::Audio::IAudioGraph ** value) = 0;
};

struct __declspec(uuid("0e4d3faa-36b8-4c91-b9da-11f44a8a6610")) __declspec(novtable) IEchoEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_WetDryMix(double value) = 0;
    virtual HRESULT __stdcall get_WetDryMix(double * value) = 0;
    virtual HRESULT __stdcall put_Feedback(double value) = 0;
    virtual HRESULT __stdcall get_Feedback(double * value) = 0;
    virtual HRESULT __stdcall put_Delay(double value) = 0;
    virtual HRESULT __stdcall get_Delay(double * value) = 0;
};

struct __declspec(uuid("0d4e2257-aaf2-4e86-a54c-fb79db8f6c12")) __declspec(novtable) IEchoEffectDefinitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Media::Audio::IAudioGraph * audioGraph, Windows::Media::Audio::IEchoEffectDefinition ** value) = 0;
};

struct __declspec(uuid("c00a5a6a-262d-4b85-9bb7-43280b62ed0c")) __declspec(novtable) IEqualizerBand : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Bandwidth(double * value) = 0;
    virtual HRESULT __stdcall put_Bandwidth(double value) = 0;
    virtual HRESULT __stdcall get_FrequencyCenter(double * value) = 0;
    virtual HRESULT __stdcall put_FrequencyCenter(double value) = 0;
    virtual HRESULT __stdcall get_Gain(double * value) = 0;
    virtual HRESULT __stdcall put_Gain(double value) = 0;
};

struct __declspec(uuid("023f6f1f-83fe-449a-a822-c696442d16b0")) __declspec(novtable) IEqualizerEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Bands(Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::EqualizerBand> ** value) = 0;
};

struct __declspec(uuid("d2876fc4-d410-4eb5-9e69-c9aa1277eaf0")) __declspec(novtable) IEqualizerEffectDefinitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Media::Audio::IAudioGraph * audioGraph, Windows::Media::Audio::IEqualizerEffectDefinition ** value) = 0;
};

struct __declspec(uuid("3d9bd498-a306-4f06-bd9f-e9efc8226304")) __declspec(novtable) IFrameInputNodeQuantumStartedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_RequiredSamples(int32_t * value) = 0;
};

struct __declspec(uuid("6b755d19-2603-47ba-bdeb-39055e3486dc")) __declspec(novtable) ILimiterEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_Release(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Release(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_Loudness(uint32_t value) = 0;
    virtual HRESULT __stdcall get_Loudness(uint32_t * value) = 0;
};

struct __declspec(uuid("ecbae6f1-61ff-45ef-b8f5-48659a57c72d")) __declspec(novtable) ILimiterEffectDefinitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Media::Audio::IAudioGraph * audioGraph, Windows::Media::Audio::ILimiterEffectDefinition ** value) = 0;
};

struct __declspec(uuid("4606aa89-f563-4d0a-8f6e-f0cddff35d84")) __declspec(novtable) IReverbEffectDefinition : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall put_WetDryMix(double value) = 0;
    virtual HRESULT __stdcall get_WetDryMix(double * value) = 0;
    virtual HRESULT __stdcall put_ReflectionsDelay(uint32_t value) = 0;
    virtual HRESULT __stdcall get_ReflectionsDelay(uint32_t * value) = 0;
    virtual HRESULT __stdcall put_ReverbDelay(uint8_t value) = 0;
    virtual HRESULT __stdcall get_ReverbDelay(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_RearDelay(uint8_t value) = 0;
    virtual HRESULT __stdcall get_RearDelay(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_PositionLeft(uint8_t value) = 0;
    virtual HRESULT __stdcall get_PositionLeft(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_PositionRight(uint8_t value) = 0;
    virtual HRESULT __stdcall get_PositionRight(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_PositionMatrixLeft(uint8_t value) = 0;
    virtual HRESULT __stdcall get_PositionMatrixLeft(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_PositionMatrixRight(uint8_t value) = 0;
    virtual HRESULT __stdcall get_PositionMatrixRight(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_EarlyDiffusion(uint8_t value) = 0;
    virtual HRESULT __stdcall get_EarlyDiffusion(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_LateDiffusion(uint8_t value) = 0;
    virtual HRESULT __stdcall get_LateDiffusion(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_LowEQGain(uint8_t value) = 0;
    virtual HRESULT __stdcall get_LowEQGain(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_LowEQCutoff(uint8_t value) = 0;
    virtual HRESULT __stdcall get_LowEQCutoff(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_HighEQGain(uint8_t value) = 0;
    virtual HRESULT __stdcall get_HighEQGain(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_HighEQCutoff(uint8_t value) = 0;
    virtual HRESULT __stdcall get_HighEQCutoff(uint8_t * value) = 0;
    virtual HRESULT __stdcall put_RoomFilterFreq(double value) = 0;
    virtual HRESULT __stdcall get_RoomFilterFreq(double * value) = 0;
    virtual HRESULT __stdcall put_RoomFilterMain(double value) = 0;
    virtual HRESULT __stdcall get_RoomFilterMain(double * value) = 0;
    virtual HRESULT __stdcall put_RoomFilterHF(double value) = 0;
    virtual HRESULT __stdcall get_RoomFilterHF(double * value) = 0;
    virtual HRESULT __stdcall put_ReflectionsGain(double value) = 0;
    virtual HRESULT __stdcall get_ReflectionsGain(double * value) = 0;
    virtual HRESULT __stdcall put_ReverbGain(double value) = 0;
    virtual HRESULT __stdcall get_ReverbGain(double * value) = 0;
    virtual HRESULT __stdcall put_DecayTime(double value) = 0;
    virtual HRESULT __stdcall get_DecayTime(double * value) = 0;
    virtual HRESULT __stdcall put_Density(double value) = 0;
    virtual HRESULT __stdcall get_Density(double * value) = 0;
    virtual HRESULT __stdcall put_RoomSize(double value) = 0;
    virtual HRESULT __stdcall get_RoomSize(double * value) = 0;
    virtual HRESULT __stdcall put_DisableLateField(bool value) = 0;
    virtual HRESULT __stdcall get_DisableLateField(bool * value) = 0;
};

struct __declspec(uuid("a7d5cbfe-100b-4ff0-9da6-dc4e05a759f0")) __declspec(novtable) IReverbEffectDefinitionFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Media::Audio::IAudioGraph * audioGraph, Windows::Media::Audio::IReverbEffectDefinition ** value) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::Audio::AudioDeviceInputNode> { using default_interface = Windows::Media::Audio::IAudioDeviceInputNode; };
template <> struct traits<Windows::Media::Audio::AudioDeviceOutputNode> { using default_interface = Windows::Media::Audio::IAudioDeviceOutputNode; };
template <> struct traits<Windows::Media::Audio::AudioFileInputNode> { using default_interface = Windows::Media::Audio::IAudioFileInputNode; };
template <> struct traits<Windows::Media::Audio::AudioFileOutputNode> { using default_interface = Windows::Media::Audio::IAudioFileOutputNode; };
template <> struct traits<Windows::Media::Audio::AudioFrameCompletedEventArgs> { using default_interface = Windows::Media::Audio::IAudioFrameCompletedEventArgs; };
template <> struct traits<Windows::Media::Audio::AudioFrameInputNode> { using default_interface = Windows::Media::Audio::IAudioFrameInputNode; };
template <> struct traits<Windows::Media::Audio::AudioFrameOutputNode> { using default_interface = Windows::Media::Audio::IAudioFrameOutputNode; };
template <> struct traits<Windows::Media::Audio::AudioGraph> { using default_interface = Windows::Media::Audio::IAudioGraph; };
template <> struct traits<Windows::Media::Audio::AudioGraphBatchUpdater> { using default_interface = Windows::Foundation::IClosable; };
template <> struct traits<Windows::Media::Audio::AudioGraphConnection> { using default_interface = Windows::Media::Audio::IAudioGraphConnection; };
template <> struct traits<Windows::Media::Audio::AudioGraphSettings> { using default_interface = Windows::Media::Audio::IAudioGraphSettings; };
template <> struct traits<Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> { using default_interface = Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs; };
template <> struct traits<Windows::Media::Audio::AudioNodeEmitter> { using default_interface = Windows::Media::Audio::IAudioNodeEmitter; };
template <> struct traits<Windows::Media::Audio::AudioNodeEmitterConeProperties> { using default_interface = Windows::Media::Audio::IAudioNodeEmitterConeProperties; };
template <> struct traits<Windows::Media::Audio::AudioNodeEmitterDecayModel> { using default_interface = Windows::Media::Audio::IAudioNodeEmitterDecayModel; };
template <> struct traits<Windows::Media::Audio::AudioNodeEmitterNaturalDecayModelProperties> { using default_interface = Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties; };
template <> struct traits<Windows::Media::Audio::AudioNodeEmitterShape> { using default_interface = Windows::Media::Audio::IAudioNodeEmitterShape; };
template <> struct traits<Windows::Media::Audio::AudioNodeListener> { using default_interface = Windows::Media::Audio::IAudioNodeListener; };
template <> struct traits<Windows::Media::Audio::AudioSubmixNode> { using default_interface = Windows::Media::Audio::IAudioInputNode; };
template <> struct traits<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> { using default_interface = Windows::Media::Audio::ICreateAudioDeviceInputNodeResult; };
template <> struct traits<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> { using default_interface = Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult; };
template <> struct traits<Windows::Media::Audio::CreateAudioFileInputNodeResult> { using default_interface = Windows::Media::Audio::ICreateAudioFileInputNodeResult; };
template <> struct traits<Windows::Media::Audio::CreateAudioFileOutputNodeResult> { using default_interface = Windows::Media::Audio::ICreateAudioFileOutputNodeResult; };
template <> struct traits<Windows::Media::Audio::CreateAudioGraphResult> { using default_interface = Windows::Media::Audio::ICreateAudioGraphResult; };
template <> struct traits<Windows::Media::Audio::EchoEffectDefinition> { using default_interface = Windows::Media::Audio::IEchoEffectDefinition; };
template <> struct traits<Windows::Media::Audio::EqualizerBand> { using default_interface = Windows::Media::Audio::IEqualizerBand; };
template <> struct traits<Windows::Media::Audio::EqualizerEffectDefinition> { using default_interface = Windows::Media::Audio::IEqualizerEffectDefinition; };
template <> struct traits<Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> { using default_interface = Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs; };
template <> struct traits<Windows::Media::Audio::LimiterEffectDefinition> { using default_interface = Windows::Media::Audio::ILimiterEffectDefinition; };
template <> struct traits<Windows::Media::Audio::ReverbEffectDefinition> { using default_interface = Windows::Media::Audio::IReverbEffectDefinition; };

}

namespace Windows::Media::Audio {

template <typename D>
struct WINRT_EBO impl_IAudioDeviceInputNode
{
    Windows::Devices::Enumeration::DeviceInformation Device() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioDeviceOutputNode
{
    Windows::Devices::Enumeration::DeviceInformation Device() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioFileInputNode
{
    void PlaybackSpeedFactor(double value) const;
    double PlaybackSpeedFactor() const;
    Windows::Foundation::TimeSpan Position() const;
    void Seek(const Windows::Foundation::TimeSpan & position) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> StartTime() const;
    void StartTime(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Foundation::IReference<Windows::Foundation::TimeSpan> EndTime() const;
    void EndTime(const optional<Windows::Foundation::TimeSpan> & value) const;
    Windows::Foundation::IReference<int32_t> LoopCount() const;
    void LoopCount(const optional<int32_t> & value) const;
    Windows::Foundation::TimeSpan Duration() const;
    Windows::Storage::StorageFile SourceFile() const;
    event_token FileCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> & handler) const;
    using FileCompleted_revoker = event_revoker<IAudioFileInputNode>;
    FileCompleted_revoker FileCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFileInputNode, Windows::Foundation::IInspectable> & handler) const;
    void FileCompleted(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioFileOutputNode
{
    Windows::Storage::IStorageFile File() const;
    Windows::Media::MediaProperties::MediaEncodingProfile FileEncodingProfile() const;
    Windows::Foundation::IAsyncOperation<winrt::Windows::Media::Transcoding::TranscodeFailureReason> FinalizeAsync() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioFrameCompletedEventArgs
{
    Windows::Media::AudioFrame Frame() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioFrameInputNode
{
    void PlaybackSpeedFactor(double value) const;
    double PlaybackSpeedFactor() const;
    void AddFrame(const Windows::Media::AudioFrame & frame) const;
    void DiscardQueuedFrames() const;
    uint64_t QueuedSampleCount() const;
    event_token AudioFrameCompleted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> & handler) const;
    using AudioFrameCompleted_revoker = event_revoker<IAudioFrameInputNode>;
    AudioFrameCompleted_revoker AudioFrameCompleted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::AudioFrameCompletedEventArgs> & handler) const;
    void AudioFrameCompleted(event_token token) const;
    event_token QuantumStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> & handler) const;
    using QuantumStarted_revoker = event_revoker<IAudioFrameInputNode>;
    QuantumStarted_revoker QuantumStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioFrameInputNode, Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs> & handler) const;
    void QuantumStarted(event_token token) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioFrameOutputNode
{
    Windows::Media::AudioFrame GetFrame() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioGraph
{
    Windows::Media::Audio::AudioFrameInputNode CreateFrameInputNode() const;
    Windows::Media::Audio::AudioFrameInputNode CreateFrameInputNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category, const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category, const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Devices::Enumeration::DeviceInformation & device) const;
    Windows::Media::Audio::AudioFrameOutputNode CreateFrameOutputNode() const;
    Windows::Media::Audio::AudioFrameOutputNode CreateFrameOutputNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult> CreateDeviceOutputNodeAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> CreateFileInputNodeAsync(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> CreateFileOutputNodeAsync(const Windows::Storage::IStorageFile & file) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileOutputNodeResult> CreateFileOutputNodeAsync(const Windows::Storage::IStorageFile & file, const Windows::Media::MediaProperties::MediaEncodingProfile & fileEncodingProfile) const;
    Windows::Media::Audio::AudioSubmixNode CreateSubmixNode() const;
    Windows::Media::Audio::AudioSubmixNode CreateSubmixNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties) const;
    void Start() const;
    void Stop() const;
    void ResetAllNodes() const;
    event_token QuantumStarted(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const;
    using QuantumStarted_revoker = event_revoker<IAudioGraph>;
    QuantumStarted_revoker QuantumStarted(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const;
    void QuantumStarted(event_token token) const;
    event_token QuantumProcessed(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const;
    using QuantumProcessed_revoker = event_revoker<IAudioGraph>;
    QuantumProcessed_revoker QuantumProcessed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Foundation::IInspectable> & handler) const;
    void QuantumProcessed(event_token token) const;
    event_token UnrecoverableErrorOccurred(const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> & handler) const;
    using UnrecoverableErrorOccurred_revoker = event_revoker<IAudioGraph>;
    UnrecoverableErrorOccurred_revoker UnrecoverableErrorOccurred(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::Audio::AudioGraph, Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs> & handler) const;
    void UnrecoverableErrorOccurred(event_token token) const;
    uint64_t CompletedQuantumCount() const;
    Windows::Media::MediaProperties::AudioEncodingProperties EncodingProperties() const;
    int32_t LatencyInSamples() const;
    Windows::Devices::Enumeration::DeviceInformation PrimaryRenderDevice() const;
    Windows::Media::AudioProcessing RenderDeviceAudioProcessing() const;
    int32_t SamplesPerQuantum() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioGraph2
{
    Windows::Media::Audio::AudioFrameInputNode CreateFrameInputNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Media::Audio::AudioNodeEmitter & emitter) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioDeviceInputNodeResult> CreateDeviceInputNodeAsync(Windows::Media::Capture::MediaCategory category, const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Devices::Enumeration::DeviceInformation & device, const Windows::Media::Audio::AudioNodeEmitter & emitter) const;
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioFileInputNodeResult> CreateFileInputNodeAsync(const Windows::Storage::IStorageFile & file, const Windows::Media::Audio::AudioNodeEmitter & emitter) const;
    Windows::Media::Audio::AudioSubmixNode CreateSubmixNode(const Windows::Media::MediaProperties::AudioEncodingProperties & encodingProperties, const Windows::Media::Audio::AudioNodeEmitter & emitter) const;
    Windows::Media::Audio::AudioGraphBatchUpdater CreateBatchUpdater() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioGraphConnection
{
    Windows::Media::Audio::IAudioNode Destination() const;
    void Gain(double value) const;
    double Gain() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioGraphSettings
{
    Windows::Media::MediaProperties::AudioEncodingProperties EncodingProperties() const;
    void EncodingProperties(const Windows::Media::MediaProperties::AudioEncodingProperties & value) const;
    Windows::Devices::Enumeration::DeviceInformation PrimaryRenderDevice() const;
    void PrimaryRenderDevice(const Windows::Devices::Enumeration::DeviceInformation & value) const;
    Windows::Media::Audio::QuantumSizeSelectionMode QuantumSizeSelectionMode() const;
    void QuantumSizeSelectionMode(Windows::Media::Audio::QuantumSizeSelectionMode value) const;
    int32_t DesiredSamplesPerQuantum() const;
    void DesiredSamplesPerQuantum(int32_t value) const;
    Windows::Media::Render::AudioRenderCategory AudioRenderCategory() const;
    void AudioRenderCategory(Windows::Media::Render::AudioRenderCategory value) const;
    Windows::Media::AudioProcessing DesiredRenderDeviceAudioProcessing() const;
    void DesiredRenderDeviceAudioProcessing(Windows::Media::AudioProcessing value) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioGraphSettingsFactory
{
    Windows::Media::Audio::AudioGraphSettings Create(Windows::Media::Render::AudioRenderCategory audioRenderCategory) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioGraphStatics
{
    Windows::Foundation::IAsyncOperation<Windows::Media::Audio::CreateAudioGraphResult> CreateAsync(const Windows::Media::Audio::AudioGraphSettings & settings) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioGraphUnrecoverableErrorOccurredEventArgs
{
    Windows::Media::Audio::AudioGraphUnrecoverableError Error() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioInputNode
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::AudioGraphConnection> OutgoingConnections() const;
    void AddOutgoingConnection(const Windows::Media::Audio::IAudioNode & destination) const;
    void AddOutgoingConnection(const Windows::Media::Audio::IAudioNode & destination, double gain) const;
    void RemoveOutgoingConnection(const Windows::Media::Audio::IAudioNode & destination) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioInputNode2
{
    Windows::Media::Audio::AudioNodeEmitter Emitter() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNode
{
    Windows::Foundation::Collections::IVector<Windows::Media::Effects::IAudioEffectDefinition> EffectDefinitions() const;
    void OutgoingGain(double value) const;
    double OutgoingGain() const;
    Windows::Media::MediaProperties::AudioEncodingProperties EncodingProperties() const;
    bool ConsumeInput() const;
    void ConsumeInput(bool value) const;
    void Start() const;
    void Stop() const;
    void Reset() const;
    void DisableEffectsByDefinition(const Windows::Media::Effects::IAudioEffectDefinition & definition) const;
    void EnableEffectsByDefinition(const Windows::Media::Effects::IAudioEffectDefinition & definition) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitter
{
    Windows::Foundation::Numerics::float3 Position() const;
    void Position(const Windows::Foundation::Numerics::float3 & value) const;
    Windows::Foundation::Numerics::float3 Direction() const;
    void Direction(const Windows::Foundation::Numerics::float3 & value) const;
    Windows::Media::Audio::AudioNodeEmitterShape Shape() const;
    Windows::Media::Audio::AudioNodeEmitterDecayModel DecayModel() const;
    double Gain() const;
    void Gain(double value) const;
    double DistanceScale() const;
    void DistanceScale(double value) const;
    double DopplerScale() const;
    void DopplerScale(double value) const;
    Windows::Foundation::Numerics::float3 DopplerVelocity() const;
    void DopplerVelocity(const Windows::Foundation::Numerics::float3 & value) const;
    bool IsDopplerDisabled() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitter2
{
    Windows::Media::Audio::SpatialAudioModel SpatialAudioModel() const;
    void SpatialAudioModel(Windows::Media::Audio::SpatialAudioModel value) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitterConeProperties
{
    double InnerAngle() const;
    double OuterAngle() const;
    double OuterAngleGain() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitterDecayModel
{
    Windows::Media::Audio::AudioNodeEmitterDecayKind Kind() const;
    double MinGain() const;
    double MaxGain() const;
    Windows::Media::Audio::AudioNodeEmitterNaturalDecayModelProperties NaturalProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitterDecayModelStatics
{
    Windows::Media::Audio::AudioNodeEmitterDecayModel CreateNatural(double minGain, double maxGain, double unityGainDistance, double cutoffDistance) const;
    Windows::Media::Audio::AudioNodeEmitterDecayModel CreateCustom(double minGain, double maxGain) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitterFactory
{
    Windows::Media::Audio::AudioNodeEmitter CreateAudioNodeEmitter(const Windows::Media::Audio::AudioNodeEmitterShape & shape, const Windows::Media::Audio::AudioNodeEmitterDecayModel & decayModel, Windows::Media::Audio::AudioNodeEmitterSettings settings) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitterNaturalDecayModelProperties
{
    double UnityGainDistance() const;
    double CutoffDistance() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitterShape
{
    Windows::Media::Audio::AudioNodeEmitterShapeKind Kind() const;
    Windows::Media::Audio::AudioNodeEmitterConeProperties ConeProperties() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeEmitterShapeStatics
{
    Windows::Media::Audio::AudioNodeEmitterShape CreateCone(double innerAngle, double outerAngle, double outerAngleGain) const;
    Windows::Media::Audio::AudioNodeEmitterShape CreateOmnidirectional() const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeListener
{
    Windows::Foundation::Numerics::float3 Position() const;
    void Position(const Windows::Foundation::Numerics::float3 & value) const;
    Windows::Foundation::Numerics::quaternion Orientation() const;
    void Orientation(const Windows::Foundation::Numerics::quaternion & value) const;
    double SpeedOfSound() const;
    void SpeedOfSound(double value) const;
    Windows::Foundation::Numerics::float3 DopplerVelocity() const;
    void DopplerVelocity(const Windows::Foundation::Numerics::float3 & value) const;
};

template <typename D>
struct WINRT_EBO impl_IAudioNodeWithListener
{
    void Listener(const Windows::Media::Audio::AudioNodeListener & value) const;
    Windows::Media::Audio::AudioNodeListener Listener() const;
};

template <typename D>
struct WINRT_EBO impl_ICreateAudioDeviceInputNodeResult
{
    Windows::Media::Audio::AudioDeviceNodeCreationStatus Status() const;
    Windows::Media::Audio::AudioDeviceInputNode DeviceInputNode() const;
};

template <typename D>
struct WINRT_EBO impl_ICreateAudioDeviceOutputNodeResult
{
    Windows::Media::Audio::AudioDeviceNodeCreationStatus Status() const;
    Windows::Media::Audio::AudioDeviceOutputNode DeviceOutputNode() const;
};

template <typename D>
struct WINRT_EBO impl_ICreateAudioFileInputNodeResult
{
    Windows::Media::Audio::AudioFileNodeCreationStatus Status() const;
    Windows::Media::Audio::AudioFileInputNode FileInputNode() const;
};

template <typename D>
struct WINRT_EBO impl_ICreateAudioFileOutputNodeResult
{
    Windows::Media::Audio::AudioFileNodeCreationStatus Status() const;
    Windows::Media::Audio::AudioFileOutputNode FileOutputNode() const;
};

template <typename D>
struct WINRT_EBO impl_ICreateAudioGraphResult
{
    Windows::Media::Audio::AudioGraphCreationStatus Status() const;
    Windows::Media::Audio::AudioGraph Graph() const;
};

template <typename D>
struct WINRT_EBO impl_IEchoEffectDefinition
{
    void WetDryMix(double value) const;
    double WetDryMix() const;
    void Feedback(double value) const;
    double Feedback() const;
    void Delay(double value) const;
    double Delay() const;
};

template <typename D>
struct WINRT_EBO impl_IEchoEffectDefinitionFactory
{
    Windows::Media::Audio::EchoEffectDefinition Create(const Windows::Media::Audio::AudioGraph & audioGraph) const;
};

template <typename D>
struct WINRT_EBO impl_IEqualizerBand
{
    double Bandwidth() const;
    void Bandwidth(double value) const;
    double FrequencyCenter() const;
    void FrequencyCenter(double value) const;
    double Gain() const;
    void Gain(double value) const;
};

template <typename D>
struct WINRT_EBO impl_IEqualizerEffectDefinition
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::Audio::EqualizerBand> Bands() const;
};

template <typename D>
struct WINRT_EBO impl_IEqualizerEffectDefinitionFactory
{
    Windows::Media::Audio::EqualizerEffectDefinition Create(const Windows::Media::Audio::AudioGraph & audioGraph) const;
};

template <typename D>
struct WINRT_EBO impl_IFrameInputNodeQuantumStartedEventArgs
{
    int32_t RequiredSamples() const;
};

template <typename D>
struct WINRT_EBO impl_ILimiterEffectDefinition
{
    void Release(uint32_t value) const;
    uint32_t Release() const;
    void Loudness(uint32_t value) const;
    uint32_t Loudness() const;
};

template <typename D>
struct WINRT_EBO impl_ILimiterEffectDefinitionFactory
{
    Windows::Media::Audio::LimiterEffectDefinition Create(const Windows::Media::Audio::AudioGraph & audioGraph) const;
};

template <typename D>
struct WINRT_EBO impl_IReverbEffectDefinition
{
    void WetDryMix(double value) const;
    double WetDryMix() const;
    void ReflectionsDelay(uint32_t value) const;
    uint32_t ReflectionsDelay() const;
    void ReverbDelay(uint8_t value) const;
    uint8_t ReverbDelay() const;
    void RearDelay(uint8_t value) const;
    uint8_t RearDelay() const;
    void PositionLeft(uint8_t value) const;
    uint8_t PositionLeft() const;
    void PositionRight(uint8_t value) const;
    uint8_t PositionRight() const;
    void PositionMatrixLeft(uint8_t value) const;
    uint8_t PositionMatrixLeft() const;
    void PositionMatrixRight(uint8_t value) const;
    uint8_t PositionMatrixRight() const;
    void EarlyDiffusion(uint8_t value) const;
    uint8_t EarlyDiffusion() const;
    void LateDiffusion(uint8_t value) const;
    uint8_t LateDiffusion() const;
    void LowEQGain(uint8_t value) const;
    uint8_t LowEQGain() const;
    void LowEQCutoff(uint8_t value) const;
    uint8_t LowEQCutoff() const;
    void HighEQGain(uint8_t value) const;
    uint8_t HighEQGain() const;
    void HighEQCutoff(uint8_t value) const;
    uint8_t HighEQCutoff() const;
    void RoomFilterFreq(double value) const;
    double RoomFilterFreq() const;
    void RoomFilterMain(double value) const;
    double RoomFilterMain() const;
    void RoomFilterHF(double value) const;
    double RoomFilterHF() const;
    void ReflectionsGain(double value) const;
    double ReflectionsGain() const;
    void ReverbGain(double value) const;
    double ReverbGain() const;
    void DecayTime(double value) const;
    double DecayTime() const;
    void Density(double value) const;
    double Density() const;
    void RoomSize(double value) const;
    double RoomSize() const;
    void DisableLateField(bool value) const;
    bool DisableLateField() const;
};

template <typename D>
struct WINRT_EBO impl_IReverbEffectDefinitionFactory
{
    Windows::Media::Audio::ReverbEffectDefinition Create(const Windows::Media::Audio::AudioGraph & audioGraph) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::Audio::IAudioDeviceInputNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioDeviceInputNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioDeviceInputNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioDeviceOutputNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioDeviceOutputNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioDeviceOutputNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioFileInputNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioFileInputNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioFileInputNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioFileOutputNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioFileOutputNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioFileOutputNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioFrameCompletedEventArgs>
{
    using abi = ABI::Windows::Media::Audio::IAudioFrameCompletedEventArgs;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioFrameCompletedEventArgs<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioFrameInputNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioFrameInputNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioFrameInputNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioFrameOutputNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioFrameOutputNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioFrameOutputNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioGraph>
{
    using abi = ABI::Windows::Media::Audio::IAudioGraph;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioGraph<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioGraph2>
{
    using abi = ABI::Windows::Media::Audio::IAudioGraph2;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioGraph2<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioGraphConnection>
{
    using abi = ABI::Windows::Media::Audio::IAudioGraphConnection;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioGraphConnection<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioGraphSettings>
{
    using abi = ABI::Windows::Media::Audio::IAudioGraphSettings;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioGraphSettings<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioGraphSettingsFactory>
{
    using abi = ABI::Windows::Media::Audio::IAudioGraphSettingsFactory;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioGraphSettingsFactory<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioGraphStatics>
{
    using abi = ABI::Windows::Media::Audio::IAudioGraphStatics;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioGraphStatics<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs>
{
    using abi = ABI::Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioGraphUnrecoverableErrorOccurredEventArgs<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioInputNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioInputNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioInputNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioInputNode2>
{
    using abi = ABI::Windows::Media::Audio::IAudioInputNode2;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioInputNode2<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNode>
{
    using abi = ABI::Windows::Media::Audio::IAudioNode;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNode<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitter>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitter;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitter<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitter2>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitter2;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitter2<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitterConeProperties>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitterConeProperties;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitterConeProperties<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitterDecayModel>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitterDecayModel<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitterDecayModelStatics>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModelStatics;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitterDecayModelStatics<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitterFactory>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitterFactory;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitterFactory<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitterNaturalDecayModelProperties<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitterShape>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitterShape;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitterShape<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeEmitterShapeStatics>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeEmitterShapeStatics;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeEmitterShapeStatics<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeListener>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeListener;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeListener<D>;
};

template <> struct traits<Windows::Media::Audio::IAudioNodeWithListener>
{
    using abi = ABI::Windows::Media::Audio::IAudioNodeWithListener;
    template <typename D> using consume = Windows::Media::Audio::impl_IAudioNodeWithListener<D>;
};

template <> struct traits<Windows::Media::Audio::ICreateAudioDeviceInputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult;
    template <typename D> using consume = Windows::Media::Audio::impl_ICreateAudioDeviceInputNodeResult<D>;
};

template <> struct traits<Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult;
    template <typename D> using consume = Windows::Media::Audio::impl_ICreateAudioDeviceOutputNodeResult<D>;
};

template <> struct traits<Windows::Media::Audio::ICreateAudioFileInputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::ICreateAudioFileInputNodeResult;
    template <typename D> using consume = Windows::Media::Audio::impl_ICreateAudioFileInputNodeResult<D>;
};

template <> struct traits<Windows::Media::Audio::ICreateAudioFileOutputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::ICreateAudioFileOutputNodeResult;
    template <typename D> using consume = Windows::Media::Audio::impl_ICreateAudioFileOutputNodeResult<D>;
};

template <> struct traits<Windows::Media::Audio::ICreateAudioGraphResult>
{
    using abi = ABI::Windows::Media::Audio::ICreateAudioGraphResult;
    template <typename D> using consume = Windows::Media::Audio::impl_ICreateAudioGraphResult<D>;
};

template <> struct traits<Windows::Media::Audio::IEchoEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::IEchoEffectDefinition;
    template <typename D> using consume = Windows::Media::Audio::impl_IEchoEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Audio::IEchoEffectDefinitionFactory>
{
    using abi = ABI::Windows::Media::Audio::IEchoEffectDefinitionFactory;
    template <typename D> using consume = Windows::Media::Audio::impl_IEchoEffectDefinitionFactory<D>;
};

template <> struct traits<Windows::Media::Audio::IEqualizerBand>
{
    using abi = ABI::Windows::Media::Audio::IEqualizerBand;
    template <typename D> using consume = Windows::Media::Audio::impl_IEqualizerBand<D>;
};

template <> struct traits<Windows::Media::Audio::IEqualizerEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::IEqualizerEffectDefinition;
    template <typename D> using consume = Windows::Media::Audio::impl_IEqualizerEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Audio::IEqualizerEffectDefinitionFactory>
{
    using abi = ABI::Windows::Media::Audio::IEqualizerEffectDefinitionFactory;
    template <typename D> using consume = Windows::Media::Audio::impl_IEqualizerEffectDefinitionFactory<D>;
};

template <> struct traits<Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs>
{
    using abi = ABI::Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs;
    template <typename D> using consume = Windows::Media::Audio::impl_IFrameInputNodeQuantumStartedEventArgs<D>;
};

template <> struct traits<Windows::Media::Audio::ILimiterEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::ILimiterEffectDefinition;
    template <typename D> using consume = Windows::Media::Audio::impl_ILimiterEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Audio::ILimiterEffectDefinitionFactory>
{
    using abi = ABI::Windows::Media::Audio::ILimiterEffectDefinitionFactory;
    template <typename D> using consume = Windows::Media::Audio::impl_ILimiterEffectDefinitionFactory<D>;
};

template <> struct traits<Windows::Media::Audio::IReverbEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::IReverbEffectDefinition;
    template <typename D> using consume = Windows::Media::Audio::impl_IReverbEffectDefinition<D>;
};

template <> struct traits<Windows::Media::Audio::IReverbEffectDefinitionFactory>
{
    using abi = ABI::Windows::Media::Audio::IReverbEffectDefinitionFactory;
    template <typename D> using consume = Windows::Media::Audio::impl_IReverbEffectDefinitionFactory<D>;
};

template <> struct traits<Windows::Media::Audio::AudioDeviceInputNode>
{
    using abi = ABI::Windows::Media::Audio::AudioDeviceInputNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioDeviceInputNode"; }
};

template <> struct traits<Windows::Media::Audio::AudioDeviceOutputNode>
{
    using abi = ABI::Windows::Media::Audio::AudioDeviceOutputNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioDeviceOutputNode"; }
};

template <> struct traits<Windows::Media::Audio::AudioFileInputNode>
{
    using abi = ABI::Windows::Media::Audio::AudioFileInputNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioFileInputNode"; }
};

template <> struct traits<Windows::Media::Audio::AudioFileOutputNode>
{
    using abi = ABI::Windows::Media::Audio::AudioFileOutputNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioFileOutputNode"; }
};

template <> struct traits<Windows::Media::Audio::AudioFrameCompletedEventArgs>
{
    using abi = ABI::Windows::Media::Audio::AudioFrameCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioFrameCompletedEventArgs"; }
};

template <> struct traits<Windows::Media::Audio::AudioFrameInputNode>
{
    using abi = ABI::Windows::Media::Audio::AudioFrameInputNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioFrameInputNode"; }
};

template <> struct traits<Windows::Media::Audio::AudioFrameOutputNode>
{
    using abi = ABI::Windows::Media::Audio::AudioFrameOutputNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioFrameOutputNode"; }
};

template <> struct traits<Windows::Media::Audio::AudioGraph>
{
    using abi = ABI::Windows::Media::Audio::AudioGraph;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioGraph"; }
};

template <> struct traits<Windows::Media::Audio::AudioGraphBatchUpdater>
{
    using abi = ABI::Windows::Media::Audio::AudioGraphBatchUpdater;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioGraphBatchUpdater"; }
};

template <> struct traits<Windows::Media::Audio::AudioGraphConnection>
{
    using abi = ABI::Windows::Media::Audio::AudioGraphConnection;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioGraphConnection"; }
};

template <> struct traits<Windows::Media::Audio::AudioGraphSettings>
{
    using abi = ABI::Windows::Media::Audio::AudioGraphSettings;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioGraphSettings"; }
};

template <> struct traits<Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs>
{
    using abi = ABI::Windows::Media::Audio::AudioGraphUnrecoverableErrorOccurredEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioGraphUnrecoverableErrorOccurredEventArgs"; }
};

template <> struct traits<Windows::Media::Audio::AudioNodeEmitter>
{
    using abi = ABI::Windows::Media::Audio::AudioNodeEmitter;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioNodeEmitter"; }
};

template <> struct traits<Windows::Media::Audio::AudioNodeEmitterConeProperties>
{
    using abi = ABI::Windows::Media::Audio::AudioNodeEmitterConeProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioNodeEmitterConeProperties"; }
};

template <> struct traits<Windows::Media::Audio::AudioNodeEmitterDecayModel>
{
    using abi = ABI::Windows::Media::Audio::AudioNodeEmitterDecayModel;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioNodeEmitterDecayModel"; }
};

template <> struct traits<Windows::Media::Audio::AudioNodeEmitterNaturalDecayModelProperties>
{
    using abi = ABI::Windows::Media::Audio::AudioNodeEmitterNaturalDecayModelProperties;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioNodeEmitterNaturalDecayModelProperties"; }
};

template <> struct traits<Windows::Media::Audio::AudioNodeEmitterShape>
{
    using abi = ABI::Windows::Media::Audio::AudioNodeEmitterShape;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioNodeEmitterShape"; }
};

template <> struct traits<Windows::Media::Audio::AudioNodeListener>
{
    using abi = ABI::Windows::Media::Audio::AudioNodeListener;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioNodeListener"; }
};

template <> struct traits<Windows::Media::Audio::AudioSubmixNode>
{
    using abi = ABI::Windows::Media::Audio::AudioSubmixNode;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.AudioSubmixNode"; }
};

template <> struct traits<Windows::Media::Audio::CreateAudioDeviceInputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.CreateAudioDeviceInputNodeResult"; }
};

template <> struct traits<Windows::Media::Audio::CreateAudioDeviceOutputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::CreateAudioDeviceOutputNodeResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.CreateAudioDeviceOutputNodeResult"; }
};

template <> struct traits<Windows::Media::Audio::CreateAudioFileInputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::CreateAudioFileInputNodeResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.CreateAudioFileInputNodeResult"; }
};

template <> struct traits<Windows::Media::Audio::CreateAudioFileOutputNodeResult>
{
    using abi = ABI::Windows::Media::Audio::CreateAudioFileOutputNodeResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.CreateAudioFileOutputNodeResult"; }
};

template <> struct traits<Windows::Media::Audio::CreateAudioGraphResult>
{
    using abi = ABI::Windows::Media::Audio::CreateAudioGraphResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.CreateAudioGraphResult"; }
};

template <> struct traits<Windows::Media::Audio::EchoEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::EchoEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.EchoEffectDefinition"; }
};

template <> struct traits<Windows::Media::Audio::EqualizerBand>
{
    using abi = ABI::Windows::Media::Audio::EqualizerBand;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.EqualizerBand"; }
};

template <> struct traits<Windows::Media::Audio::EqualizerEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::EqualizerEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.EqualizerEffectDefinition"; }
};

template <> struct traits<Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs>
{
    using abi = ABI::Windows::Media::Audio::FrameInputNodeQuantumStartedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.FrameInputNodeQuantumStartedEventArgs"; }
};

template <> struct traits<Windows::Media::Audio::LimiterEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::LimiterEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.LimiterEffectDefinition"; }
};

template <> struct traits<Windows::Media::Audio::ReverbEffectDefinition>
{
    using abi = ABI::Windows::Media::Audio::ReverbEffectDefinition;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.Audio.ReverbEffectDefinition"; }
};

}

}
