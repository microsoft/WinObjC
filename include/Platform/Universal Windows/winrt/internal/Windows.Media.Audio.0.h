// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once


WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::Audio {

struct IAudioDeviceInputNode;
struct IAudioDeviceOutputNode;
struct IAudioFileInputNode;
struct IAudioFileOutputNode;
struct IAudioFrameCompletedEventArgs;
struct IAudioFrameInputNode;
struct IAudioFrameOutputNode;
struct IAudioGraph;
struct IAudioGraph2;
struct IAudioGraphConnection;
struct IAudioGraphSettings;
struct IAudioGraphSettingsFactory;
struct IAudioGraphStatics;
struct IAudioGraphUnrecoverableErrorOccurredEventArgs;
struct IAudioInputNode;
struct IAudioInputNode2;
struct IAudioNode;
struct IAudioNodeEmitter;
struct IAudioNodeEmitter2;
struct IAudioNodeEmitterConeProperties;
struct IAudioNodeEmitterDecayModel;
struct IAudioNodeEmitterDecayModelStatics;
struct IAudioNodeEmitterFactory;
struct IAudioNodeEmitterNaturalDecayModelProperties;
struct IAudioNodeEmitterShape;
struct IAudioNodeEmitterShapeStatics;
struct IAudioNodeListener;
struct IAudioNodeWithListener;
struct ICreateAudioDeviceInputNodeResult;
struct ICreateAudioDeviceOutputNodeResult;
struct ICreateAudioFileInputNodeResult;
struct ICreateAudioFileOutputNodeResult;
struct ICreateAudioGraphResult;
struct IEchoEffectDefinition;
struct IEchoEffectDefinitionFactory;
struct IEqualizerBand;
struct IEqualizerEffectDefinition;
struct IEqualizerEffectDefinitionFactory;
struct IFrameInputNodeQuantumStartedEventArgs;
struct ILimiterEffectDefinition;
struct ILimiterEffectDefinitionFactory;
struct IReverbEffectDefinition;
struct IReverbEffectDefinitionFactory;
struct AudioDeviceInputNode;
struct AudioDeviceOutputNode;
struct AudioFileInputNode;
struct AudioFileOutputNode;
struct AudioFrameCompletedEventArgs;
struct AudioFrameInputNode;
struct AudioFrameOutputNode;
struct AudioGraph;
struct AudioGraphBatchUpdater;
struct AudioGraphConnection;
struct AudioGraphSettings;
struct AudioGraphUnrecoverableErrorOccurredEventArgs;
struct AudioNodeEmitter;
struct AudioNodeEmitterConeProperties;
struct AudioNodeEmitterDecayModel;
struct AudioNodeEmitterNaturalDecayModelProperties;
struct AudioNodeEmitterShape;
struct AudioNodeListener;
struct AudioSubmixNode;
struct CreateAudioDeviceInputNodeResult;
struct CreateAudioDeviceOutputNodeResult;
struct CreateAudioFileInputNodeResult;
struct CreateAudioFileOutputNodeResult;
struct CreateAudioGraphResult;
struct EchoEffectDefinition;
struct EqualizerBand;
struct EqualizerEffectDefinition;
struct FrameInputNodeQuantumStartedEventArgs;
struct LimiterEffectDefinition;
struct ReverbEffectDefinition;

}

namespace Windows::Media::Audio {

struct IAudioDeviceInputNode;
struct IAudioDeviceOutputNode;
struct IAudioFileInputNode;
struct IAudioFileOutputNode;
struct IAudioFrameCompletedEventArgs;
struct IAudioFrameInputNode;
struct IAudioFrameOutputNode;
struct IAudioGraph;
struct IAudioGraph2;
struct IAudioGraphConnection;
struct IAudioGraphSettings;
struct IAudioGraphSettingsFactory;
struct IAudioGraphStatics;
struct IAudioGraphUnrecoverableErrorOccurredEventArgs;
struct IAudioInputNode;
struct IAudioInputNode2;
struct IAudioNode;
struct IAudioNodeEmitter;
struct IAudioNodeEmitter2;
struct IAudioNodeEmitterConeProperties;
struct IAudioNodeEmitterDecayModel;
struct IAudioNodeEmitterDecayModelStatics;
struct IAudioNodeEmitterFactory;
struct IAudioNodeEmitterNaturalDecayModelProperties;
struct IAudioNodeEmitterShape;
struct IAudioNodeEmitterShapeStatics;
struct IAudioNodeListener;
struct IAudioNodeWithListener;
struct ICreateAudioDeviceInputNodeResult;
struct ICreateAudioDeviceOutputNodeResult;
struct ICreateAudioFileInputNodeResult;
struct ICreateAudioFileOutputNodeResult;
struct ICreateAudioGraphResult;
struct IEchoEffectDefinition;
struct IEchoEffectDefinitionFactory;
struct IEqualizerBand;
struct IEqualizerEffectDefinition;
struct IEqualizerEffectDefinitionFactory;
struct IFrameInputNodeQuantumStartedEventArgs;
struct ILimiterEffectDefinition;
struct ILimiterEffectDefinitionFactory;
struct IReverbEffectDefinition;
struct IReverbEffectDefinitionFactory;
struct AudioDeviceInputNode;
struct AudioDeviceOutputNode;
struct AudioFileInputNode;
struct AudioFileOutputNode;
struct AudioFrameCompletedEventArgs;
struct AudioFrameInputNode;
struct AudioFrameOutputNode;
struct AudioGraph;
struct AudioGraphBatchUpdater;
struct AudioGraphConnection;
struct AudioGraphSettings;
struct AudioGraphUnrecoverableErrorOccurredEventArgs;
struct AudioNodeEmitter;
struct AudioNodeEmitterConeProperties;
struct AudioNodeEmitterDecayModel;
struct AudioNodeEmitterNaturalDecayModelProperties;
struct AudioNodeEmitterShape;
struct AudioNodeListener;
struct AudioSubmixNode;
struct CreateAudioDeviceInputNodeResult;
struct CreateAudioDeviceOutputNodeResult;
struct CreateAudioFileInputNodeResult;
struct CreateAudioFileOutputNodeResult;
struct CreateAudioGraphResult;
struct EchoEffectDefinition;
struct EqualizerBand;
struct EqualizerEffectDefinition;
struct FrameInputNodeQuantumStartedEventArgs;
struct LimiterEffectDefinition;
struct ReverbEffectDefinition;

}

namespace Windows::Media::Audio {

template <typename T> struct impl_IAudioDeviceInputNode;
template <typename T> struct impl_IAudioDeviceOutputNode;
template <typename T> struct impl_IAudioFileInputNode;
template <typename T> struct impl_IAudioFileOutputNode;
template <typename T> struct impl_IAudioFrameCompletedEventArgs;
template <typename T> struct impl_IAudioFrameInputNode;
template <typename T> struct impl_IAudioFrameOutputNode;
template <typename T> struct impl_IAudioGraph;
template <typename T> struct impl_IAudioGraph2;
template <typename T> struct impl_IAudioGraphConnection;
template <typename T> struct impl_IAudioGraphSettings;
template <typename T> struct impl_IAudioGraphSettingsFactory;
template <typename T> struct impl_IAudioGraphStatics;
template <typename T> struct impl_IAudioGraphUnrecoverableErrorOccurredEventArgs;
template <typename T> struct impl_IAudioInputNode;
template <typename T> struct impl_IAudioInputNode2;
template <typename T> struct impl_IAudioNode;
template <typename T> struct impl_IAudioNodeEmitter;
template <typename T> struct impl_IAudioNodeEmitter2;
template <typename T> struct impl_IAudioNodeEmitterConeProperties;
template <typename T> struct impl_IAudioNodeEmitterDecayModel;
template <typename T> struct impl_IAudioNodeEmitterDecayModelStatics;
template <typename T> struct impl_IAudioNodeEmitterFactory;
template <typename T> struct impl_IAudioNodeEmitterNaturalDecayModelProperties;
template <typename T> struct impl_IAudioNodeEmitterShape;
template <typename T> struct impl_IAudioNodeEmitterShapeStatics;
template <typename T> struct impl_IAudioNodeListener;
template <typename T> struct impl_IAudioNodeWithListener;
template <typename T> struct impl_ICreateAudioDeviceInputNodeResult;
template <typename T> struct impl_ICreateAudioDeviceOutputNodeResult;
template <typename T> struct impl_ICreateAudioFileInputNodeResult;
template <typename T> struct impl_ICreateAudioFileOutputNodeResult;
template <typename T> struct impl_ICreateAudioGraphResult;
template <typename T> struct impl_IEchoEffectDefinition;
template <typename T> struct impl_IEchoEffectDefinitionFactory;
template <typename T> struct impl_IEqualizerBand;
template <typename T> struct impl_IEqualizerEffectDefinition;
template <typename T> struct impl_IEqualizerEffectDefinitionFactory;
template <typename T> struct impl_IFrameInputNodeQuantumStartedEventArgs;
template <typename T> struct impl_ILimiterEffectDefinition;
template <typename T> struct impl_ILimiterEffectDefinitionFactory;
template <typename T> struct impl_IReverbEffectDefinition;
template <typename T> struct impl_IReverbEffectDefinitionFactory;

}

namespace Windows::Media::Audio {

enum class AudioDeviceNodeCreationStatus
{
    Success = 0,
    DeviceNotAvailable = 1,
    FormatNotSupported = 2,
    UnknownFailure = 3,
    AccessDenied = 4,
};

enum class AudioFileNodeCreationStatus
{
    Success = 0,
    FileNotFound = 1,
    InvalidFileType = 2,
    FormatNotSupported = 3,
    UnknownFailure = 4,
};

enum class AudioGraphCreationStatus
{
    Success = 0,
    DeviceNotAvailable = 1,
    FormatNotSupported = 2,
    UnknownFailure = 3,
};

enum class AudioGraphUnrecoverableError
{
    None = 0,
    AudioDeviceLost = 1,
    AudioSessionDisconnected = 2,
    UnknownFailure = 3,
};

enum class AudioNodeEmitterDecayKind
{
    Natural = 0,
    Custom = 1,
};

enum class AudioNodeEmitterSettings : unsigned
{
    None = 0x0,
    DisableDoppler = 0x1,
};

DEFINE_ENUM_FLAG_OPERATORS(AudioNodeEmitterSettings)

enum class AudioNodeEmitterShapeKind
{
    Omnidirectional = 0,
    Cone = 1,
};

enum class QuantumSizeSelectionMode
{
    SystemDefault = 0,
    LowestLatency = 1,
    ClosestToDesired = 2,
};

enum class SpatialAudioModel
{
    ObjectBased = 0,
    FoldDown = 1,
};

}

}
