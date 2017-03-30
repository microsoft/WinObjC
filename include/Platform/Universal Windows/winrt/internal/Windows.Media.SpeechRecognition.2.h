// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "Windows.Media.SpeechRecognition.1.h"
#include "Windows.Foundation.1.h"

WINRT_EXPORT namespace winrt {

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

#ifndef WINRT_GENERIC_144b0f3d_2d59_5dd2_b012_908ec3e06435
#define WINRT_GENERIC_144b0f3d_2d59_5dd2_b012_908ec3e06435
template <> struct __declspec(uuid("144b0f3d-2d59-5dd2-b012-908ec3e06435")) __declspec(novtable) IVectorView<Windows::Globalization::Language> : impl_IVectorView<Windows::Globalization::Language> {};
#endif

#ifndef WINRT_GENERIC_0e37810f_1de6_5199_833f_5a6b0bd91e23
#define WINRT_GENERIC_0e37810f_1de6_5199_833f_5a6b0bd91e23
template <> struct __declspec(uuid("0e37810f-1de6-5199-833f-5a6b0bd91e23")) __declspec(novtable) IVectorView<Windows::Media::SpeechRecognition::SpeechRecognitionResult> : impl_IVectorView<Windows::Media::SpeechRecognition::SpeechRecognitionResult> {};
#endif

#ifndef WINRT_GENERIC_2691d763_561e_5060_bbc9_7b07361acc95
#define WINRT_GENERIC_2691d763_561e_5060_bbc9_7b07361acc95
template <> struct __declspec(uuid("2691d763-561e-5060-bbc9-7b07361acc95")) __declspec(novtable) IVector<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> : impl_IVector<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_a392249a_e28a_564a_9e73_1dda63ca643c
#define WINRT_GENERIC_a392249a_e28a_564a_9e73_1dda63ca643c
template <> struct __declspec(uuid("a392249a-e28a-564a-9e73-1dda63ca643c")) __declspec(novtable) IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> : impl_IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> {};
#endif

#ifndef WINRT_GENERIC_ba3eebe8_8d7c_51f2_9ed4_ebafe3674db4
#define WINRT_GENERIC_ba3eebe8_8d7c_51f2_9ed4_ebafe3674db4
template <> struct __declspec(uuid("ba3eebe8-8d7c-51f2-9ed4-ebafe3674db4")) __declspec(novtable) IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> : impl_IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> {};
#endif

#ifndef WINRT_GENERIC_15ca7918_61d2_57b2_b933_44063e8bb662
#define WINRT_GENERIC_15ca7918_61d2_57b2_b933_44063e8bb662
template <> struct __declspec(uuid("15ca7918-61d2-57b2-b933-44063e8bb662")) __declspec(novtable) TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> : impl_TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> {};
#endif

#ifndef WINRT_GENERIC_d1185e92_5c30_5561_b3e2_e82ddbd872c3
#define WINRT_GENERIC_d1185e92_5c30_5561_b3e2_e82ddbd872c3
template <> struct __declspec(uuid("d1185e92-5c30-5561-b3e2-e82ddbd872c3")) __declspec(novtable) TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> : impl_TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_4cb45aba_7573_545a_b29a_e9be35bd4682
#define WINRT_GENERIC_4cb45aba_7573_545a_b29a_e9be35bd4682
template <> struct __declspec(uuid("4cb45aba-7573-545a-b29a-e9be35bd4682")) __declspec(novtable) TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> : impl_TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_8103c018_7952_59f9_9f41_23b17d6e452d
#define WINRT_GENERIC_8103c018_7952_59f9_9f41_23b17d6e452d
template <> struct __declspec(uuid("8103c018-7952-59f9-9f41-23b17d6e452d")) __declspec(novtable) TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> : impl_TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> {};
#endif

#ifndef WINRT_GENERIC_26192073_a2c9_527d_9bd3_911c05e0011e
#define WINRT_GENERIC_26192073_a2c9_527d_9bd3_911c05e0011e
template <> struct __declspec(uuid("26192073-a2c9-527d-9bd3-911c05e0011e")) __declspec(novtable) TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> : impl_TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_48409a10_61b6_5db1_a69d_8abc46ac608a
#define WINRT_GENERIC_48409a10_61b6_5db1_a69d_8abc46ac608a
template <> struct __declspec(uuid("48409a10-61b6-5db1-a69d-8abc46ac608a")) __declspec(novtable) IIterable<Windows::Globalization::Language> : impl_IIterable<Windows::Globalization::Language> {};
#endif

#ifndef WINRT_GENERIC_121115fd_3858_5888_8626_b69ded969bd6
#define WINRT_GENERIC_121115fd_3858_5888_8626_b69ded969bd6
template <> struct __declspec(uuid("121115fd-3858-5888-8626-b69ded969bd6")) __declspec(novtable) IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> : impl_IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> {};
#endif

#ifndef WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
#define WINRT_GENERIC_8c304ebb_6615_50a4_8829_879ecd443236
template <> struct __declspec(uuid("8c304ebb-6615-50a4-8829-879ecd443236")) __declspec(novtable) IIterator<hstring> : impl_IIterator<hstring> {};
#endif

#ifndef WINRT_GENERIC_30e99ae6_f414_5243_8db2_aab38ea3f1f1
#define WINRT_GENERIC_30e99ae6_f414_5243_8db2_aab38ea3f1f1
template <> struct __declspec(uuid("30e99ae6-f414-5243-8db2-aab38ea3f1f1")) __declspec(novtable) IIterator<Windows::Globalization::Language> : impl_IIterator<Windows::Globalization::Language> {};
#endif

#ifndef WINRT_GENERIC_20756dd2_6d3f_5409_846a_0f0f01d7bf9a
#define WINRT_GENERIC_20756dd2_6d3f_5409_846a_0f0f01d7bf9a
template <> struct __declspec(uuid("20756dd2-6d3f-5409-846a-0f0f01d7bf9a")) __declspec(novtable) IIterator<Windows::Media::SpeechRecognition::SpeechRecognitionResult> : impl_IIterator<Windows::Media::SpeechRecognition::SpeechRecognitionResult> {};
#endif

#ifndef WINRT_GENERIC_0d9b7b48_98a1_5b22_9a66_6f812f5947aa
#define WINRT_GENERIC_0d9b7b48_98a1_5b22_9a66_6f812f5947aa
template <> struct __declspec(uuid("0d9b7b48-98a1-5b22-9a66-6f812f5947aa")) __declspec(novtable) IIterable<Windows::Media::SpeechRecognition::SpeechRecognitionResult> : impl_IIterable<Windows::Media::SpeechRecognition::SpeechRecognitionResult> {};
#endif

#ifndef WINRT_GENERIC_738f00b1_e18c_5140_a53a_f1788d10c93d
#define WINRT_GENERIC_738f00b1_e18c_5140_a53a_f1788d10c93d
template <> struct __declspec(uuid("738f00b1-e18c-5140-a53a-f1788d10c93d")) __declspec(novtable) IIterator<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> : impl_IIterator<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> {};
#endif

#ifndef WINRT_GENERIC_88e6436c_3253_520b_9ed8_a63b178c44a2
#define WINRT_GENERIC_88e6436c_3253_520b_9ed8_a63b178c44a2
template <> struct __declspec(uuid("88e6436c-3253-520b-9ed8-a63b178c44a2")) __declspec(novtable) IIterable<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> : impl_IIterable<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> {};
#endif

#ifndef WINRT_GENERIC_341dee1d_6ac2_5d06_9026_b30ada205665
#define WINRT_GENERIC_341dee1d_6ac2_5d06_9026_b30ada205665
template <> struct __declspec(uuid("341dee1d-6ac2-5d06-9026-b30ada205665")) __declspec(novtable) IVectorView<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> : impl_IVectorView<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> {};
#endif


}

namespace ABI::Windows::Foundation {

#ifndef WINRT_GENERIC_78c859bd_14d4_5c40_abff_490616d5e92d
#define WINRT_GENERIC_78c859bd_14d4_5c40_abff_490616d5e92d
template <> struct __declspec(uuid("78c859bd-14d4-5c40-abff-490616d5e92d")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> : impl_AsyncOperationCompletedHandler<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> {};
#endif

#ifndef WINRT_GENERIC_c2195c7d_dcc2_5c6d_9162_c8df66528762
#define WINRT_GENERIC_c2195c7d_dcc2_5c6d_9162_c8df66528762
template <> struct __declspec(uuid("c2195c7d-dcc2-5c6d-9162-c8df66528762")) __declspec(novtable) AsyncOperationCompletedHandler<Windows::Media::SpeechRecognition::SpeechRecognitionResult> : impl_AsyncOperationCompletedHandler<Windows::Media::SpeechRecognition::SpeechRecognitionResult> {};
#endif


}

namespace ABI::Windows::Foundation::Collections {

#ifndef WINRT_GENERIC_2bda6840_c39e_5534_8099_22004ab33fc2
#define WINRT_GENERIC_2bda6840_c39e_5534_8099_22004ab33fc2
template <> struct __declspec(uuid("2bda6840-c39e-5534-8099-22004ab33fc2")) __declspec(novtable) IKeyValuePair<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> : impl_IKeyValuePair<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> {};
#endif

#ifndef WINRT_GENERIC_2843d34f_d3e5_5fca_9fdc_b568dd5c1e64
#define WINRT_GENERIC_2843d34f_d3e5_5fca_9fdc_b568dd5c1e64
template <> struct __declspec(uuid("2843d34f-d3e5-5fca-9fdc-b568dd5c1e64")) __declspec(novtable) IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> : impl_IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif

#ifndef WINRT_GENERIC_bcde03ad_ea71_5077_a961_1c0ecff57202
#define WINRT_GENERIC_bcde03ad_ea71_5077_a961_1c0ecff57202
template <> struct __declspec(uuid("bcde03ad-ea71-5077-a961-1c0ecff57202")) __declspec(novtable) IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>> : impl_IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>> {};
#endif

#ifndef WINRT_GENERIC_d19b13f3_9058_53bd_8d53_3ee1ea84389b
#define WINRT_GENERIC_d19b13f3_9058_53bd_8d53_3ee1ea84389b
template <> struct __declspec(uuid("d19b13f3-9058-53bd-8d53-3ee1ea84389b")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet>> {};
#endif

#ifndef WINRT_GENERIC_86e4878a_45de_5203_be77_81c04c9b44e6
#define WINRT_GENERIC_86e4878a_45de_5203_be77_81c04c9b44e6
template <> struct __declspec(uuid("86e4878a-45de-5203-be77-81c04c9b44e6")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet>> {};
#endif

#ifndef WINRT_GENERIC_643b6d83_457e_5a43_800f_b0449f91d96b
#define WINRT_GENERIC_643b6d83_457e_5a43_800f_b0449f91d96b
template <> struct __declspec(uuid("643b6d83-457e-5a43-800f-b0449f91d96b")) __declspec(novtable) IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> : impl_IIterator<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> {};
#endif

#ifndef WINRT_GENERIC_a4cd6151_2cc1_56f1_9014_df6ba3410beb
#define WINRT_GENERIC_a4cd6151_2cc1_56f1_9014_df6ba3410beb
template <> struct __declspec(uuid("a4cd6151-2cc1-56f1-9014-df6ba3410beb")) __declspec(novtable) IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> : impl_IIterable<Windows::Foundation::Collections::IKeyValuePair<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> {};
#endif


}

namespace Windows::Media::SpeechRecognition {

struct ISpeechContinuousRecognitionCompletedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechContinuousRecognitionCompletedEventArgs>
{
    ISpeechContinuousRecognitionCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechContinuousRecognitionResultGeneratedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechContinuousRecognitionResultGeneratedEventArgs>
{
    ISpeechContinuousRecognitionResultGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechContinuousRecognitionSession :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechContinuousRecognitionSession>
{
    ISpeechContinuousRecognitionSession(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionCompilationResult :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionCompilationResult>
{
    ISpeechRecognitionCompilationResult(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionConstraint :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionConstraint>
{
    ISpeechRecognitionConstraint(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionGrammarFileConstraint :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionGrammarFileConstraint>,
    impl::require<ISpeechRecognitionGrammarFileConstraint, Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>
{
    ISpeechRecognitionGrammarFileConstraint(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionGrammarFileConstraintFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionGrammarFileConstraintFactory>
{
    ISpeechRecognitionGrammarFileConstraintFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionHypothesis :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionHypothesis>
{
    ISpeechRecognitionHypothesis(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionHypothesisGeneratedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionHypothesisGeneratedEventArgs>
{
    ISpeechRecognitionHypothesisGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionListConstraint :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionListConstraint>,
    impl::require<ISpeechRecognitionListConstraint, Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>
{
    ISpeechRecognitionListConstraint(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionListConstraintFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionListConstraintFactory>
{
    ISpeechRecognitionListConstraintFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionQualityDegradingEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionQualityDegradingEventArgs>
{
    ISpeechRecognitionQualityDegradingEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionResult :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionResult>
{
    ISpeechRecognitionResult(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionResult2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionResult2>
{
    ISpeechRecognitionResult2(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionSemanticInterpretation :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionSemanticInterpretation>
{
    ISpeechRecognitionSemanticInterpretation(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionTopicConstraint :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionTopicConstraint>,
    impl::require<ISpeechRecognitionTopicConstraint, Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>
{
    ISpeechRecognitionTopicConstraint(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionTopicConstraintFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionTopicConstraintFactory>
{
    ISpeechRecognitionTopicConstraintFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognitionVoiceCommandDefinitionConstraint :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognitionVoiceCommandDefinitionConstraint>,
    impl::require<ISpeechRecognitionVoiceCommandDefinitionConstraint, Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>
{
    ISpeechRecognitionVoiceCommandDefinitionConstraint(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognizer :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognizer>,
    impl::require<ISpeechRecognizer, Windows::Foundation::IClosable>
{
    ISpeechRecognizer(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognizer2 :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognizer2>
{
    ISpeechRecognizer2(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognizerFactory :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognizerFactory>
{
    ISpeechRecognizerFactory(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognizerStateChangedEventArgs :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognizerStateChangedEventArgs>
{
    ISpeechRecognizerStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognizerStatics :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognizerStatics>
{
    ISpeechRecognizerStatics(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognizerTimeouts :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognizerTimeouts>
{
    ISpeechRecognizerTimeouts(std::nullptr_t = nullptr) noexcept {}
};

struct ISpeechRecognizerUIOptions :
    Windows::Foundation::IInspectable,
    impl::consume<ISpeechRecognizerUIOptions>
{
    ISpeechRecognizerUIOptions(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandManager :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandManager>
{
    IVoiceCommandManager(std::nullptr_t = nullptr) noexcept {}
};

struct IVoiceCommandSet :
    Windows::Foundation::IInspectable,
    impl::consume<IVoiceCommandSet>
{
    IVoiceCommandSet(std::nullptr_t = nullptr) noexcept {}
};

}

}
