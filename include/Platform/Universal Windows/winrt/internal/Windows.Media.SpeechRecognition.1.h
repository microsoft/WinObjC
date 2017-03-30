// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once

#include "../base.h"
#include "Windows.Media.SpeechRecognition.0.h"
#include "Windows.Foundation.0.h"
#include "Windows.Globalization.0.h"
#include "Windows.Storage.0.h"
#include "Windows.Foundation.Collections.1.h"
#include "Windows.Foundation.1.h"
#include "Windows.Globalization.1.h"

WINRT_EXPORT namespace winrt {

namespace ABI::Windows::Media::SpeechRecognition {

struct __declspec(uuid("e3d069bb-e30c-5e18-424b-7fbe81f8fbd0")) __declspec(novtable) ISpeechContinuousRecognitionCompletedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus * value) = 0;
};

struct __declspec(uuid("19091e1e-6e7e-5a46-40fb-76594f786504")) __declspec(novtable) ISpeechContinuousRecognitionResultGeneratedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Result(Windows::Media::SpeechRecognition::ISpeechRecognitionResult ** value) = 0;
};

struct __declspec(uuid("6a213c04-6614-49f8-99a2-b5e9b3a085c8")) __declspec(novtable) ISpeechContinuousRecognitionSession : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_AutoStopSilenceTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_AutoStopSilenceTimeout(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall abi_StartAsync(Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_StartWithModeAsync(winrt::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionMode mode, Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_StopAsync(Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_CancelAsync(Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_PauseAsync(Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall abi_Resume() = 0;
    virtual HRESULT __stdcall add_Completed(Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> * value, event_token * returnValue) = 0;
    virtual HRESULT __stdcall remove_Completed(event_token value) = 0;
    virtual HRESULT __stdcall add_ResultGenerated(Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> * value, event_token * returnValue) = 0;
    virtual HRESULT __stdcall remove_ResultGenerated(event_token value) = 0;
};

struct __declspec(uuid("407e6c5d-6ac7-4da4-9cc1-2fce32cf7489")) __declspec(novtable) ISpeechRecognitionCompilationResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus * value) = 0;
};

struct __declspec(uuid("79ac1628-4d68-43c4-8911-40dc4101b55b")) __declspec(novtable) ISpeechRecognitionConstraint : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_IsEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_Tag(hstring * value) = 0;
    virtual HRESULT __stdcall put_Tag(hstring value) = 0;
    virtual HRESULT __stdcall get_Type(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType * value) = 0;
    virtual HRESULT __stdcall get_Probability(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability * value) = 0;
    virtual HRESULT __stdcall put_Probability(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability value) = 0;
};

struct __declspec(uuid("b5031a8f-85ca-4fa4-b11a-474fc41b3835")) __declspec(novtable) ISpeechRecognitionGrammarFileConstraint : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_GrammarFile(Windows::Storage::IStorageFile ** value) = 0;
};

struct __declspec(uuid("3da770eb-c479-4c27-9f19-89974ef392d1")) __declspec(novtable) ISpeechRecognitionGrammarFileConstraintFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Storage::IStorageFile * file, Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint ** constraint) = 0;
    virtual HRESULT __stdcall abi_CreateWithTag(Windows::Storage::IStorageFile * file, hstring tag, Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint ** constraint) = 0;
};

struct __declspec(uuid("7a7b25b0-99c5-4f7d-bf84-10aa1302b634")) __declspec(novtable) ISpeechRecognitionHypothesis : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
};

struct __declspec(uuid("55161a7a-8023-5866-411d-1213bb271476")) __declspec(novtable) ISpeechRecognitionHypothesisGeneratedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Hypothesis(Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis ** value) = 0;
};

struct __declspec(uuid("09c487e9-e4ad-4526-81f2-4946fb481d98")) __declspec(novtable) ISpeechRecognitionListConstraint : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Commands(Windows::Foundation::Collections::IVector<hstring> ** value) = 0;
};

struct __declspec(uuid("40f3cdc7-562a-426a-9f3b-3b4e282be1d5")) __declspec(novtable) ISpeechRecognitionListConstraintFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Foundation::Collections::IIterable<hstring> * commands, Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint ** constraint) = 0;
    virtual HRESULT __stdcall abi_CreateWithTag(Windows::Foundation::Collections::IIterable<hstring> * commands, hstring tag, Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint ** constraint) = 0;
};

struct __declspec(uuid("4fe24105-8c3a-4c7e-8d0a-5bd4f5b14ad8")) __declspec(novtable) ISpeechRecognitionQualityDegradingEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Problem(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionAudioProblem * value) = 0;
};

struct __declspec(uuid("4e303157-034e-4652-857e-d0454cc4beec")) __declspec(novtable) ISpeechRecognitionResult : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Status(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus * value) = 0;
    virtual HRESULT __stdcall get_Text(hstring * value) = 0;
    virtual HRESULT __stdcall get_Confidence(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionConfidence * value) = 0;
    virtual HRESULT __stdcall get_SemanticInterpretation(Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation ** value) = 0;
    virtual HRESULT __stdcall abi_GetAlternates(uint32_t maxAlternates, Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechRecognition::SpeechRecognitionResult> ** alternates) = 0;
    virtual HRESULT __stdcall get_Constraint(Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint ** value) = 0;
    virtual HRESULT __stdcall get_RulePath(Windows::Foundation::Collections::IVectorView<hstring> ** value) = 0;
    virtual HRESULT __stdcall get_RawConfidence(double * value) = 0;
};

struct __declspec(uuid("af7ed1ba-451b-4166-a0c1-1ffe84032d03")) __declspec(novtable) ISpeechRecognitionResult2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_PhraseStartTime(Windows::Foundation::DateTime * value) = 0;
    virtual HRESULT __stdcall get_PhraseDuration(Windows::Foundation::TimeSpan * value) = 0;
};

struct __declspec(uuid("aae1da9b-7e32-4c1f-89fe-0c65f486f52e")) __declspec(novtable) ISpeechRecognitionSemanticInterpretation : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Properties(Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> ** value) = 0;
};

struct __declspec(uuid("bf6fdf19-825d-4e69-a681-36e48cf1c93e")) __declspec(novtable) ISpeechRecognitionTopicConstraint : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Scenario(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionScenario * value) = 0;
    virtual HRESULT __stdcall get_TopicHint(hstring * value) = 0;
};

struct __declspec(uuid("6e6863df-ec05-47d7-a5df-56a3431e58d2")) __declspec(novtable) ISpeechRecognitionTopicConstraintFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring topicHint, Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint ** constraint) = 0;
    virtual HRESULT __stdcall abi_CreateWithTag(winrt::Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring topicHint, hstring tag, Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint ** constraint) = 0;
};

struct __declspec(uuid("f2791c2b-1ef4-4ae7-9d77-b6ff10b8a3c2")) __declspec(novtable) ISpeechRecognitionVoiceCommandDefinitionConstraint : Windows::Foundation::IInspectable
{
};

struct __declspec(uuid("0bc3c9cb-c26a-40f2-aeb5-8096b2e48073")) __declspec(novtable) ISpeechRecognizer : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_CurrentLanguage(Windows::Globalization::ILanguage ** language) = 0;
    virtual HRESULT __stdcall get_Constraints(Windows::Foundation::Collections::IVector<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> ** value) = 0;
    virtual HRESULT __stdcall get_Timeouts(Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts ** value) = 0;
    virtual HRESULT __stdcall get_UIOptions(Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions ** value) = 0;
    virtual HRESULT __stdcall abi_CompileConstraintsAsync(Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_RecognizeAsync(Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> ** asyncOperation) = 0;
    virtual HRESULT __stdcall abi_RecognizeWithUIAsync(Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> ** asyncOperation) = 0;
    virtual HRESULT __stdcall add_RecognitionQualityDegrading(Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> * speechRecognitionQualityDegradingHandler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_RecognitionQualityDegrading(event_token cookie) = 0;
    virtual HRESULT __stdcall add_StateChanged(Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> * stateChangedHandler, event_token * cookie) = 0;
    virtual HRESULT __stdcall remove_StateChanged(event_token cookie) = 0;
};

struct __declspec(uuid("63c9baf1-91e3-4ea4-86a1-7c3867d084a6")) __declspec(novtable) ISpeechRecognizer2 : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ContinuousRecognitionSession(Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession ** value) = 0;
    virtual HRESULT __stdcall get_State(winrt::Windows::Media::SpeechRecognition::SpeechRecognizerState * value) = 0;
    virtual HRESULT __stdcall abi_StopRecognitionAsync(Windows::Foundation::IAsyncAction ** value) = 0;
    virtual HRESULT __stdcall add_HypothesisGenerated(Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> * value, event_token * returnValue) = 0;
    virtual HRESULT __stdcall remove_HypothesisGenerated(event_token value) = 0;
};

struct __declspec(uuid("60c488dd-7fb8-4033-ac70-d046f64818e1")) __declspec(novtable) ISpeechRecognizerFactory : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_Create(Windows::Globalization::ILanguage * language, Windows::Media::SpeechRecognition::ISpeechRecognizer ** recognizer) = 0;
};

struct __declspec(uuid("563d4f09-ba03-4bad-ad81-ddc6c4dab0c3")) __declspec(novtable) ISpeechRecognizerStateChangedEventArgs : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_State(winrt::Windows::Media::SpeechRecognition::SpeechRecognizerState * value) = 0;
};

struct __declspec(uuid("87a35eac-a7dc-4b0b-bcc9-24f47c0b7ebf")) __declspec(novtable) ISpeechRecognizerStatics : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_SystemSpeechLanguage(Windows::Globalization::ILanguage ** language) = 0;
    virtual HRESULT __stdcall get_SupportedTopicLanguages(Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> ** languages) = 0;
    virtual HRESULT __stdcall get_SupportedGrammarLanguages(Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> ** languages) = 0;
};

struct __declspec(uuid("2ef76fca-6a3c-4dca-a153-df1bc88a79af")) __declspec(novtable) ISpeechRecognizerTimeouts : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_InitialSilenceTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_InitialSilenceTimeout(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_EndSilenceTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_EndSilenceTimeout(Windows::Foundation::TimeSpan value) = 0;
    virtual HRESULT __stdcall get_BabbleTimeout(Windows::Foundation::TimeSpan * value) = 0;
    virtual HRESULT __stdcall put_BabbleTimeout(Windows::Foundation::TimeSpan value) = 0;
};

struct __declspec(uuid("7888d641-b92b-44ba-a25f-d1864630641f")) __declspec(novtable) ISpeechRecognizerUIOptions : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_ExampleText(hstring * value) = 0;
    virtual HRESULT __stdcall put_ExampleText(hstring value) = 0;
    virtual HRESULT __stdcall get_AudiblePrompt(hstring * value) = 0;
    virtual HRESULT __stdcall put_AudiblePrompt(hstring value) = 0;
    virtual HRESULT __stdcall get_IsReadBackEnabled(bool * value) = 0;
    virtual HRESULT __stdcall put_IsReadBackEnabled(bool value) = 0;
    virtual HRESULT __stdcall get_ShowConfirmation(bool * value) = 0;
    virtual HRESULT __stdcall put_ShowConfirmation(bool value) = 0;
};

struct __declspec(uuid("aa3a8dd5-b6e7-4ee2-baa9-dd6baced0a2b")) __declspec(novtable) IVoiceCommandManager : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall abi_InstallCommandSetsFromStorageFileAsync(Windows::Storage::IStorageFile * file, Windows::Foundation::IAsyncAction ** installAction) = 0;
    virtual HRESULT __stdcall get_InstalledCommandSets(Windows::Foundation::Collections::IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> ** voiceCommandSets) = 0;
};

struct __declspec(uuid("0bedda75-46e6-4b11-a088-5c68632899b5")) __declspec(novtable) IVoiceCommandSet : Windows::Foundation::IInspectable
{
    virtual HRESULT __stdcall get_Language(hstring * value) = 0;
    virtual HRESULT __stdcall get_Name(hstring * value) = 0;
    virtual HRESULT __stdcall abi_SetPhraseListAsync(hstring phraseListName, Windows::Foundation::Collections::IIterable<hstring> * phraseList, Windows::Foundation::IAsyncAction ** updateAction) = 0;
};

}

namespace ABI {

template <> struct traits<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> { using default_interface = Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> { using default_interface = Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession> { using default_interface = Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionHypothesis> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionResult> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionResult; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionVoiceCommandDefinitionConstraint> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizer> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognizer; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizerTimeouts> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts; };
template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizerUIOptions> { using default_interface = Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions; };
template <> struct traits<Windows::Media::SpeechRecognition::VoiceCommandSet> { using default_interface = Windows::Media::SpeechRecognition::IVoiceCommandSet; };

}

namespace Windows::Media::SpeechRecognition {

template <typename D>
struct WINRT_EBO impl_ISpeechContinuousRecognitionCompletedEventArgs
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechContinuousRecognitionResultGeneratedEventArgs
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResult Result() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechContinuousRecognitionSession
{
    Windows::Foundation::TimeSpan AutoStopSilenceTimeout() const;
    void AutoStopSilenceTimeout(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::IAsyncAction StartAsync() const;
    Windows::Foundation::IAsyncAction StartAsync(Windows::Media::SpeechRecognition::SpeechContinuousRecognitionMode mode) const;
    Windows::Foundation::IAsyncAction StopAsync() const;
    Windows::Foundation::IAsyncAction CancelAsync() const;
    Windows::Foundation::IAsyncAction PauseAsync() const;
    void Resume() const;
    event_token Completed(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> & value) const;
    using Completed_revoker = event_revoker<ISpeechContinuousRecognitionSession>;
    Completed_revoker Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> & value) const;
    void Completed(event_token value) const;
    event_token ResultGenerated(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> & value) const;
    using ResultGenerated_revoker = event_revoker<ISpeechContinuousRecognitionSession>;
    ResultGenerated_revoker ResultGenerated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> & value) const;
    void ResultGenerated(event_token value) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionCompilationResult
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus Status() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionConstraint
{
    bool IsEnabled() const;
    void IsEnabled(bool value) const;
    hstring Tag() const;
    void Tag(hstring_view value) const;
    Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType Type() const;
    Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability Probability() const;
    void Probability(Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability value) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionGrammarFileConstraint
{
    Windows::Storage::StorageFile GrammarFile() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionGrammarFileConstraintFactory
{
    Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint Create(const Windows::Storage::StorageFile & file) const;
    Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint CreateWithTag(const Windows::Storage::StorageFile & file, hstring_view tag) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionHypothesis
{
    hstring Text() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionHypothesisGeneratedEventArgs
{
    Windows::Media::SpeechRecognition::SpeechRecognitionHypothesis Hypothesis() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionListConstraint
{
    Windows::Foundation::Collections::IVector<hstring> Commands() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionListConstraintFactory
{
    Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint Create(iterable<hstring> commands) const;
    Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint CreateWithTag(iterable<hstring> commands, hstring_view tag) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionQualityDegradingEventArgs
{
    Windows::Media::SpeechRecognition::SpeechRecognitionAudioProblem Problem() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionResult
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus Status() const;
    hstring Text() const;
    Windows::Media::SpeechRecognition::SpeechRecognitionConfidence Confidence() const;
    Windows::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation SemanticInterpretation() const;
    Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechRecognition::SpeechRecognitionResult> GetAlternates(uint32_t maxAlternates) const;
    Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint Constraint() const;
    Windows::Foundation::Collections::IVectorView<hstring> RulePath() const;
    double RawConfidence() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionResult2
{
    Windows::Foundation::DateTime PhraseStartTime() const;
    Windows::Foundation::TimeSpan PhraseDuration() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionSemanticInterpretation
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> Properties() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionTopicConstraint
{
    Windows::Media::SpeechRecognition::SpeechRecognitionScenario Scenario() const;
    hstring TopicHint() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionTopicConstraintFactory
{
    Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint Create(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring_view topicHint) const;
    Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint CreateWithTag(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring_view topicHint, hstring_view tag) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognitionVoiceCommandDefinitionConstraint
{
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognizer
{
    Windows::Globalization::Language CurrentLanguage() const;
    Windows::Foundation::Collections::IVector<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> Constraints() const;
    Windows::Media::SpeechRecognition::SpeechRecognizerTimeouts Timeouts() const;
    Windows::Media::SpeechRecognition::SpeechRecognizerUIOptions UIOptions() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> CompileConstraintsAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> RecognizeAsync() const;
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> RecognizeWithUIAsync() const;
    event_token RecognitionQualityDegrading(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> & speechRecognitionQualityDegradingHandler) const;
    using RecognitionQualityDegrading_revoker = event_revoker<ISpeechRecognizer>;
    RecognitionQualityDegrading_revoker RecognitionQualityDegrading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> & speechRecognitionQualityDegradingHandler) const;
    void RecognitionQualityDegrading(event_token cookie) const;
    event_token StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> & stateChangedHandler) const;
    using StateChanged_revoker = event_revoker<ISpeechRecognizer>;
    StateChanged_revoker StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> & stateChangedHandler) const;
    void StateChanged(event_token cookie) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognizer2
{
    Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession ContinuousRecognitionSession() const;
    Windows::Media::SpeechRecognition::SpeechRecognizerState State() const;
    Windows::Foundation::IAsyncAction StopRecognitionAsync() const;
    event_token HypothesisGenerated(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> & value) const;
    using HypothesisGenerated_revoker = event_revoker<ISpeechRecognizer2>;
    HypothesisGenerated_revoker HypothesisGenerated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> & value) const;
    void HypothesisGenerated(event_token value) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognizerFactory
{
    Windows::Media::SpeechRecognition::SpeechRecognizer Create(const Windows::Globalization::Language & language) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognizerStateChangedEventArgs
{
    Windows::Media::SpeechRecognition::SpeechRecognizerState State() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognizerStatics
{
    Windows::Globalization::Language SystemSpeechLanguage() const;
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> SupportedTopicLanguages() const;
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> SupportedGrammarLanguages() const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognizerTimeouts
{
    Windows::Foundation::TimeSpan InitialSilenceTimeout() const;
    void InitialSilenceTimeout(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan EndSilenceTimeout() const;
    void EndSilenceTimeout(const Windows::Foundation::TimeSpan & value) const;
    Windows::Foundation::TimeSpan BabbleTimeout() const;
    void BabbleTimeout(const Windows::Foundation::TimeSpan & value) const;
};

template <typename D>
struct WINRT_EBO impl_ISpeechRecognizerUIOptions
{
    hstring ExampleText() const;
    void ExampleText(hstring_view value) const;
    hstring AudiblePrompt() const;
    void AudiblePrompt(hstring_view value) const;
    bool IsReadBackEnabled() const;
    void IsReadBackEnabled(bool value) const;
    bool ShowConfirmation() const;
    void ShowConfirmation(bool value) const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandManager
{
    Windows::Foundation::IAsyncAction InstallCommandSetsFromStorageFileAsync(const Windows::Storage::StorageFile & file) const;
    Windows::Foundation::Collections::IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> InstalledCommandSets() const;
};

template <typename D>
struct WINRT_EBO impl_IVoiceCommandSet
{
    hstring Language() const;
    hstring Name() const;
    Windows::Foundation::IAsyncAction SetPhraseListAsync(hstring_view phraseListName, iterable<hstring> phraseList) const;
};

}

namespace impl {

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechContinuousRecognitionCompletedEventArgs<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechContinuousRecognitionResultGeneratedEventArgs<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechContinuousRecognitionSession<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionCompilationResult<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionConstraint<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionGrammarFileConstraint<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionGrammarFileConstraintFactory<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionHypothesis<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionHypothesisGeneratedEventArgs<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionListConstraint<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionListConstraintFactory<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionQualityDegradingEventArgs<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionResult>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionResult<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionResult2>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult2;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionResult2<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionSemanticInterpretation<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionTopicConstraint<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionTopicConstraintFactory<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognitionVoiceCommandDefinitionConstraint<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognizer>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognizer<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognizer2>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer2;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognizer2<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognizerFactory>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerFactory;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognizerFactory<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognizerStateChangedEventArgs<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognizerStatics>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStatics;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognizerStatics<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognizerTimeouts<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>
{
    using abi = ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_ISpeechRecognizerUIOptions<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::IVoiceCommandManager>
{
    using abi = ABI::Windows::Media::SpeechRecognition::IVoiceCommandManager;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_IVoiceCommandManager<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::IVoiceCommandSet>
{
    using abi = ABI::Windows::Media::SpeechRecognition::IVoiceCommandSet;
    template <typename D> using consume = Windows::Media::SpeechRecognition::impl_IVoiceCommandSet<D>;
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechContinuousRecognitionCompletedEventArgs"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechContinuousRecognitionResultGeneratedEventArgs"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechContinuousRecognitionSession"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionCompilationResult"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionGrammarFileConstraint"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionHypothesis>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionHypothesis;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionHypothesis"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionHypothesisGeneratedEventArgs"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionListConstraint"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionQualityDegradingEventArgs"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionResult>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionResult"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionSemanticInterpretation"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionTopicConstraint"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognitionVoiceCommandDefinitionConstraint>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognitionVoiceCommandDefinitionConstraint;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognitionVoiceCommandDefinitionConstraint"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizer>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognizer;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognizer"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognizerStateChangedEventArgs"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizerTimeouts>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognizerTimeouts;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognizerTimeouts"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::SpeechRecognizerUIOptions>
{
    using abi = ABI::Windows::Media::SpeechRecognition::SpeechRecognizerUIOptions;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.SpeechRecognizerUIOptions"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::VoiceCommandManager>
{
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.VoiceCommandManager"; }
};

template <> struct traits<Windows::Media::SpeechRecognition::VoiceCommandSet>
{
    using abi = ABI::Windows::Media::SpeechRecognition::VoiceCommandSet;
    static constexpr const wchar_t * name() noexcept { return L"Windows.Media.SpeechRecognition.VoiceCommandSet"; }
};

}

}
