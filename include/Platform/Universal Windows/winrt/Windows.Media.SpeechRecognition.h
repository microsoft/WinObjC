// C++ for the Windows Runtime v1.0.170224.5
// Copyright (c) 2017 Microsoft Corporation. All rights reserved.

#pragma once
#pragma warning(push)
#pragma warning(disable: 4996)

#include "internal/Windows.Foundation.3.h"
#include "internal/Windows.Foundation.Collections.3.h"
#include "internal/Windows.Storage.3.h"
#include "internal/Windows.Globalization.3.h"
#include "internal/Windows.Media.SpeechRecognition.3.h"
#include "Windows.Media.h"
#include "Windows.Foundation.h"

WINRT_EXPORT namespace winrt {

namespace impl {

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs>
{
    HRESULT __stdcall get_Status(Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs>
{
    HRESULT __stdcall get_Result(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionResult> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Result());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>
{
    HRESULT __stdcall get_AutoStopSilenceTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AutoStopSilenceTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AutoStopSilenceTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoStopSilenceTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StartWithModeAsync(Windows::Media::SpeechRecognition::SpeechContinuousRecognitionMode mode, impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StartAsync(mode));
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StopAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CancelAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().CancelAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_PauseAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PauseAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_Resume() noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_Completed(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs>> value, event_token * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().Completed(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_Completed(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_ResultGenerated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs>> value, event_token * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().ResultGenerated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_ResultGenerated(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResultGenerated(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult>
{
    HRESULT __stdcall get_Status(Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>
{
    HRESULT __stdcall get_IsEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Tag(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Tag());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Tag(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tag(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Type(Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Type());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Probability(Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Probability());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_Probability(Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Probability(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint>
{
    HRESULT __stdcall get_GrammarFile(impl::abi_arg_out<Windows::Storage::IStorageFile> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().GrammarFile());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint> constraint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *constraint = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *constraint = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTag(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_in<hstring> tag, impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint> constraint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *constraint = detach_abi(this->shim().CreateWithTag(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file), *reinterpret_cast<const hstring *>(&tag)));
            return S_OK;
        }
        catch (...)
        {
            *constraint = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis>
{
    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs>
{
    HRESULT __stdcall get_Hypothesis(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Hypothesis());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint>
{
    HRESULT __stdcall get_Commands(impl::abi_arg_out<Windows::Foundation::Collections::IVector<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Commands());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> commands, impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint> constraint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *constraint = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&commands)));
            return S_OK;
        }
        catch (...)
        {
            *constraint = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTag(impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> commands, impl::abi_arg_in<hstring> tag, impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint> constraint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *constraint = detach_abi(this->shim().CreateWithTag(*reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&commands), *reinterpret_cast<const hstring *>(&tag)));
            return S_OK;
        }
        catch (...)
        {
            *constraint = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs>
{
    HRESULT __stdcall get_Problem(Windows::Media::SpeechRecognition::SpeechRecognitionAudioProblem * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Problem());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionResult> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionResult>
{
    HRESULT __stdcall get_Status(Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Status());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Text(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Text());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Confidence(Windows::Media::SpeechRecognition::SpeechRecognitionConfidence * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Confidence());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SemanticInterpretation(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().SemanticInterpretation());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_GetAlternates(uint32_t maxAlternates, impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechRecognition::SpeechRecognitionResult>> alternates) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *alternates = detach_abi(this->shim().GetAlternates(maxAlternates));
            return S_OK;
        }
        catch (...)
        {
            *alternates = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Constraint(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Constraint());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RulePath(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<hstring>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RulePath());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_RawConfidence(double * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().RawConfidence());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionResult2> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionResult2>
{
    HRESULT __stdcall get_PhraseStartTime(impl::abi_arg_out<Windows::Foundation::DateTime> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhraseStartTime());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_PhraseDuration(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().PhraseDuration());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation>
{
    HRESULT __stdcall get_Properties(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Properties());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>
{
    HRESULT __stdcall get_Scenario(Windows::Media::SpeechRecognition::SpeechRecognitionScenario * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Scenario());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_TopicHint(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().TopicHint());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>
{
    HRESULT __stdcall abi_Create(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, impl::abi_arg_in<hstring> topicHint, impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint> constraint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *constraint = detach_abi(this->shim().Create(scenario, *reinterpret_cast<const hstring *>(&topicHint)));
            return S_OK;
        }
        catch (...)
        {
            *constraint = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CreateWithTag(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, impl::abi_arg_in<hstring> topicHint, impl::abi_arg_in<hstring> tag, impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint> constraint) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *constraint = detach_abi(this->shim().CreateWithTag(scenario, *reinterpret_cast<const hstring *>(&topicHint), *reinterpret_cast<const hstring *>(&tag)));
            return S_OK;
        }
        catch (...)
        {
            *constraint = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint>
{};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognizer> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognizer>
{
    HRESULT __stdcall get_CurrentLanguage(impl::abi_arg_out<Windows::Globalization::ILanguage> language) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *language = detach_abi(this->shim().CurrentLanguage());
            return S_OK;
        }
        catch (...)
        {
            *language = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Constraints(impl::abi_arg_out<Windows::Foundation::Collections::IVector<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Constraints());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Timeouts(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Timeouts());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_UIOptions(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().UIOptions());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_CompileConstraintsAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().CompileConstraintsAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RecognizeAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().RecognizeAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_RecognizeWithUIAsync(impl::abi_arg_out<Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult>> asyncOperation) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_abi(this->shim().RecognizeWithUIAsync());
            return S_OK;
        }
        catch (...)
        {
            *asyncOperation = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_RecognitionQualityDegrading(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs>> speechRecognitionQualityDegradingHandler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().RecognitionQualityDegrading(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> *>(&speechRecognitionQualityDegradingHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_RecognitionQualityDegrading(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RecognitionQualityDegrading(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_StateChanged(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs>> stateChangedHandler, event_token * cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *cookie = detach_abi(this->shim().StateChanged(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> *>(&stateChangedHandler)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_StateChanged(event_token cookie) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(cookie);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognizer2> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognizer2>
{
    HRESULT __stdcall get_ContinuousRecognitionSession(impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ContinuousRecognitionSession());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_State(Windows::Media::SpeechRecognition::SpeechRecognizerState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_StopRecognitionAsync(impl::abi_arg_out<Windows::Foundation::IAsyncAction> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().StopRecognitionAsync());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall add_HypothesisGenerated(impl::abi_arg_in<Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs>> value, event_token * returnValue) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_abi(this->shim().HypothesisGenerated(*reinterpret_cast<const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> *>(&value)));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall remove_HypothesisGenerated(event_token value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HypothesisGenerated(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognizerFactory> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognizerFactory>
{
    HRESULT __stdcall abi_Create(impl::abi_arg_in<Windows::Globalization::ILanguage> language, impl::abi_arg_out<Windows::Media::SpeechRecognition::ISpeechRecognizer> recognizer) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *recognizer = detach_abi(this->shim().Create(*reinterpret_cast<const Windows::Globalization::Language *>(&language)));
            return S_OK;
        }
        catch (...)
        {
            *recognizer = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs>
{
    HRESULT __stdcall get_State(Windows::Media::SpeechRecognition::SpeechRecognizerState * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().State());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognizerStatics> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognizerStatics>
{
    HRESULT __stdcall get_SystemSpeechLanguage(impl::abi_arg_out<Windows::Globalization::ILanguage> language) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *language = detach_abi(this->shim().SystemSpeechLanguage());
            return S_OK;
        }
        catch (...)
        {
            *language = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedTopicLanguages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language>> languages) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *languages = detach_abi(this->shim().SupportedTopicLanguages());
            return S_OK;
        }
        catch (...)
        {
            *languages = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_SupportedGrammarLanguages(impl::abi_arg_out<Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language>> languages) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *languages = detach_abi(this->shim().SupportedGrammarLanguages());
            return S_OK;
        }
        catch (...)
        {
            *languages = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>
{
    HRESULT __stdcall get_InitialSilenceTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().InitialSilenceTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_InitialSilenceTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialSilenceTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_EndSilenceTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().EndSilenceTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_EndSilenceTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndSilenceTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_BabbleTimeout(impl::abi_arg_out<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().BabbleTimeout());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_BabbleTimeout(impl::abi_arg_in<Windows::Foundation::TimeSpan> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BabbleTimeout(*reinterpret_cast<const Windows::Foundation::TimeSpan *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions> : produce_base<D, Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>
{
    HRESULT __stdcall get_ExampleText(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ExampleText());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ExampleText(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExampleText(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_AudiblePrompt(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().AudiblePrompt());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_AudiblePrompt(impl::abi_arg_in<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AudiblePrompt(*reinterpret_cast<const hstring *>(&value));
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_IsReadBackEnabled(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().IsReadBackEnabled());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_IsReadBackEnabled(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsReadBackEnabled(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_ShowConfirmation(bool * value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().ShowConfirmation());
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall put_ShowConfirmation(bool value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowConfirmation(value);
            return S_OK;
        }
        catch (...)
        {
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::IVoiceCommandManager> : produce_base<D, Windows::Media::SpeechRecognition::IVoiceCommandManager>
{
    HRESULT __stdcall abi_InstallCommandSetsFromStorageFileAsync(impl::abi_arg_in<Windows::Storage::IStorageFile> file, impl::abi_arg_out<Windows::Foundation::IAsyncAction> installAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *installAction = detach_abi(this->shim().InstallCommandSetsFromStorageFileAsync(*reinterpret_cast<const Windows::Storage::StorageFile *>(&file)));
            return S_OK;
        }
        catch (...)
        {
            *installAction = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_InstalledCommandSets(impl::abi_arg_out<Windows::Foundation::Collections::IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet>> voiceCommandSets) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *voiceCommandSets = detach_abi(this->shim().InstalledCommandSets());
            return S_OK;
        }
        catch (...)
        {
            *voiceCommandSets = nullptr;
            return impl::to_hresult();
        }
    }
};

template <typename D>
struct produce<D, Windows::Media::SpeechRecognition::IVoiceCommandSet> : produce_base<D, Windows::Media::SpeechRecognition::IVoiceCommandSet>
{
    HRESULT __stdcall get_Language(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Language());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall get_Name(impl::abi_arg_out<hstring> value) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_abi(this->shim().Name());
            return S_OK;
        }
        catch (...)
        {
            *value = nullptr;
            return impl::to_hresult();
        }
    }

    HRESULT __stdcall abi_SetPhraseListAsync(impl::abi_arg_in<hstring> phraseListName, impl::abi_arg_in<Windows::Foundation::Collections::IIterable<hstring>> phraseList, impl::abi_arg_out<Windows::Foundation::IAsyncAction> updateAction) noexcept override
    {
        try
        {
            typename D::abi_guard guard(this->shim());
            *updateAction = detach_abi(this->shim().SetPhraseListAsync(*reinterpret_cast<const hstring *>(&phraseListName), *reinterpret_cast<const Windows::Foundation::Collections::IIterable<hstring> *>(&phraseList)));
            return S_OK;
        }
        catch (...)
        {
            *updateAction = nullptr;
            return impl::to_hresult();
        }
    }
};

}

namespace Windows::Media::SpeechRecognition {

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus impl_ISpeechRecognitionCompilationResult<D>::Status() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionCompilationResult)->get_Status(&value));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ISpeechRecognizerTimeouts<D>::InitialSilenceTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISpeechRecognizerTimeouts)->get_InitialSilenceTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechRecognizerTimeouts<D>::InitialSilenceTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizerTimeouts)->put_InitialSilenceTimeout(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ISpeechRecognizerTimeouts<D>::EndSilenceTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISpeechRecognizerTimeouts)->get_EndSilenceTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechRecognizerTimeouts<D>::EndSilenceTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizerTimeouts)->put_EndSilenceTimeout(get_abi(value)));
}

template <typename D> Windows::Foundation::TimeSpan impl_ISpeechRecognizerTimeouts<D>::BabbleTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISpeechRecognizerTimeouts)->get_BabbleTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechRecognizerTimeouts<D>::BabbleTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizerTimeouts)->put_BabbleTimeout(get_abi(value)));
}

template <typename D> hstring impl_ISpeechRecognizerUIOptions<D>::ExampleText() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->get_ExampleText(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechRecognizerUIOptions<D>::ExampleText(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->put_ExampleText(get_abi(value)));
}

template <typename D> hstring impl_ISpeechRecognizerUIOptions<D>::AudiblePrompt() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->get_AudiblePrompt(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechRecognizerUIOptions<D>::AudiblePrompt(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->put_AudiblePrompt(get_abi(value)));
}

template <typename D> bool impl_ISpeechRecognizerUIOptions<D>::IsReadBackEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->get_IsReadBackEnabled(&value));
    return value;
}

template <typename D> void impl_ISpeechRecognizerUIOptions<D>::IsReadBackEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->put_IsReadBackEnabled(value));
}

template <typename D> bool impl_ISpeechRecognizerUIOptions<D>::ShowConfirmation() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->get_ShowConfirmation(&value));
    return value;
}

template <typename D> void impl_ISpeechRecognizerUIOptions<D>::ShowConfirmation(bool value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizerUIOptions)->put_ShowConfirmation(value));
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus impl_ISpeechRecognitionResult<D>::Status() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->get_Status(&value));
    return value;
}

template <typename D> hstring impl_ISpeechRecognitionResult<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionConfidence impl_ISpeechRecognitionResult<D>::Confidence() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionConfidence value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->get_Confidence(&value));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation impl_ISpeechRecognitionResult<D>::SemanticInterpretation() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionSemanticInterpretation value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->get_SemanticInterpretation(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechRecognition::SpeechRecognitionResult> impl_ISpeechRecognitionResult<D>::GetAlternates(uint32_t maxAlternates) const
{
    Windows::Foundation::Collections::IVectorView<Windows::Media::SpeechRecognition::SpeechRecognitionResult> alternates;
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->abi_GetAlternates(maxAlternates, put_abi(alternates)));
    return alternates;
}

template <typename D> Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint impl_ISpeechRecognitionResult<D>::Constraint() const
{
    Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->get_Constraint(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IVectorView<hstring> impl_ISpeechRecognitionResult<D>::RulePath() const
{
    Windows::Foundation::Collections::IVectorView<hstring> value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->get_RulePath(put_abi(value)));
    return value;
}

template <typename D> double impl_ISpeechRecognitionResult<D>::RawConfidence() const
{
    double value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult)->get_RawConfidence(&value));
    return value;
}

template <typename D> bool impl_ISpeechRecognitionConstraint<D>::IsEnabled() const
{
    bool value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionConstraint)->get_IsEnabled(&value));
    return value;
}

template <typename D> void impl_ISpeechRecognitionConstraint<D>::IsEnabled(bool value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognitionConstraint)->put_IsEnabled(value));
}

template <typename D> hstring impl_ISpeechRecognitionConstraint<D>::Tag() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionConstraint)->get_Tag(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechRecognitionConstraint<D>::Tag(hstring_view value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognitionConstraint)->put_Tag(get_abi(value)));
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType impl_ISpeechRecognitionConstraint<D>::Type() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionConstraint)->get_Type(&value));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability impl_ISpeechRecognitionConstraint<D>::Probability() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionConstraint)->get_Probability(&value));
    return value;
}

template <typename D> void impl_ISpeechRecognitionConstraint<D>::Probability(Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognitionConstraint)->put_Probability(value));
}

template <typename D> Windows::Foundation::DateTime impl_ISpeechRecognitionResult2<D>::PhraseStartTime() const
{
    Windows::Foundation::DateTime value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult2)->get_PhraseStartTime(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ISpeechRecognitionResult2<D>::PhraseDuration() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionResult2)->get_PhraseDuration(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> impl_ISpeechRecognitionSemanticInterpretation<D>::Properties() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Foundation::Collections::IVectorView<hstring>> value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionSemanticInterpretation)->get_Properties(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionScenario impl_ISpeechRecognitionTopicConstraint<D>::Scenario() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionScenario value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionTopicConstraint)->get_Scenario(&value));
    return value;
}

template <typename D> hstring impl_ISpeechRecognitionTopicConstraint<D>::TopicHint() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionTopicConstraint)->get_TopicHint(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint impl_ISpeechRecognitionTopicConstraintFactory<D>::Create(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring_view topicHint) const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint constraint { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionTopicConstraintFactory)->abi_Create(scenario, get_abi(topicHint), put_abi(constraint)));
    return constraint;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint impl_ISpeechRecognitionTopicConstraintFactory<D>::CreateWithTag(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring_view topicHint, hstring_view tag) const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionTopicConstraint constraint { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionTopicConstraintFactory)->abi_CreateWithTag(scenario, get_abi(topicHint), get_abi(tag), put_abi(constraint)));
    return constraint;
}

template <typename D> Windows::Foundation::Collections::IVector<hstring> impl_ISpeechRecognitionListConstraint<D>::Commands() const
{
    Windows::Foundation::Collections::IVector<hstring> value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionListConstraint)->get_Commands(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint impl_ISpeechRecognitionListConstraintFactory<D>::Create(iterable<hstring> commands) const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint constraint { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionListConstraintFactory)->abi_Create(get_abi(commands), put_abi(constraint)));
    return constraint;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint impl_ISpeechRecognitionListConstraintFactory<D>::CreateWithTag(iterable<hstring> commands, hstring_view tag) const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionListConstraint constraint { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionListConstraintFactory)->abi_CreateWithTag(get_abi(commands), get_abi(tag), put_abi(constraint)));
    return constraint;
}

template <typename D> Windows::Storage::StorageFile impl_ISpeechRecognitionGrammarFileConstraint<D>::GrammarFile() const
{
    Windows::Storage::StorageFile value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionGrammarFileConstraint)->get_GrammarFile(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint impl_ISpeechRecognitionGrammarFileConstraintFactory<D>::Create(const Windows::Storage::StorageFile & file) const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint constraint { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionGrammarFileConstraintFactory)->abi_Create(get_abi(file), put_abi(constraint)));
    return constraint;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint impl_ISpeechRecognitionGrammarFileConstraintFactory<D>::CreateWithTag(const Windows::Storage::StorageFile & file, hstring_view tag) const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionGrammarFileConstraint constraint { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionGrammarFileConstraintFactory)->abi_CreateWithTag(get_abi(file), get_abi(tag), put_abi(constraint)));
    return constraint;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionAudioProblem impl_ISpeechRecognitionQualityDegradingEventArgs<D>::Problem() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionAudioProblem value {};
    check_hresult(WINRT_SHIM(ISpeechRecognitionQualityDegradingEventArgs)->get_Problem(&value));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognizerState impl_ISpeechRecognizerStateChangedEventArgs<D>::State() const
{
    Windows::Media::SpeechRecognition::SpeechRecognizerState value {};
    check_hresult(WINRT_SHIM(ISpeechRecognizerStateChangedEventArgs)->get_State(&value));
    return value;
}

template <typename D> Windows::Globalization::Language impl_ISpeechRecognizer<D>::CurrentLanguage() const
{
    Windows::Globalization::Language language { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->get_CurrentLanguage(put_abi(language)));
    return language;
}

template <typename D> Windows::Foundation::Collections::IVector<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> impl_ISpeechRecognizer<D>::Constraints() const
{
    Windows::Foundation::Collections::IVector<Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> value;
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->get_Constraints(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognizerTimeouts impl_ISpeechRecognizer<D>::Timeouts() const
{
    Windows::Media::SpeechRecognition::SpeechRecognizerTimeouts value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->get_Timeouts(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognizerUIOptions impl_ISpeechRecognizer<D>::UIOptions() const
{
    Windows::Media::SpeechRecognition::SpeechRecognizerUIOptions value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->get_UIOptions(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> impl_ISpeechRecognizer<D>::CompileConstraintsAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult> asyncOperation;
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->abi_CompileConstraintsAsync(put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> impl_ISpeechRecognizer<D>::RecognizeAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> asyncOperation;
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->abi_RecognizeAsync(put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> impl_ISpeechRecognizer<D>::RecognizeWithUIAsync() const
{
    Windows::Foundation::IAsyncOperation<Windows::Media::SpeechRecognition::SpeechRecognitionResult> asyncOperation;
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->abi_RecognizeWithUIAsync(put_abi(asyncOperation)));
    return asyncOperation;
}

template <typename D> event_token impl_ISpeechRecognizer<D>::RecognitionQualityDegrading(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> & speechRecognitionQualityDegradingHandler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->add_RecognitionQualityDegrading(get_abi(speechRecognitionQualityDegradingHandler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISpeechRecognizer> impl_ISpeechRecognizer<D>::RecognitionQualityDegrading(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs> & speechRecognitionQualityDegradingHandler) const
{
    return impl::make_event_revoker<D, ISpeechRecognizer>(this, &ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer::remove_RecognitionQualityDegrading, RecognitionQualityDegrading(speechRecognitionQualityDegradingHandler));
}

template <typename D> void impl_ISpeechRecognizer<D>::RecognitionQualityDegrading(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->remove_RecognitionQualityDegrading(cookie));
}

template <typename D> event_token impl_ISpeechRecognizer<D>::StateChanged(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> & stateChangedHandler) const
{
    event_token cookie {};
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->add_StateChanged(get_abi(stateChangedHandler), &cookie));
    return cookie;
}

template <typename D> event_revoker<ISpeechRecognizer> impl_ISpeechRecognizer<D>::StateChanged(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs> & stateChangedHandler) const
{
    return impl::make_event_revoker<D, ISpeechRecognizer>(this, &ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer::remove_StateChanged, StateChanged(stateChangedHandler));
}

template <typename D> void impl_ISpeechRecognizer<D>::StateChanged(event_token cookie) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizer)->remove_StateChanged(cookie));
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognizer impl_ISpeechRecognizerFactory<D>::Create(const Windows::Globalization::Language & language) const
{
    Windows::Media::SpeechRecognition::SpeechRecognizer recognizer { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognizerFactory)->abi_Create(get_abi(language), put_abi(recognizer)));
    return recognizer;
}

template <typename D> Windows::Globalization::Language impl_ISpeechRecognizerStatics<D>::SystemSpeechLanguage() const
{
    Windows::Globalization::Language language { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognizerStatics)->get_SystemSpeechLanguage(put_abi(language)));
    return language;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> impl_ISpeechRecognizerStatics<D>::SupportedTopicLanguages() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> languages;
    check_hresult(WINRT_SHIM(ISpeechRecognizerStatics)->get_SupportedTopicLanguages(put_abi(languages)));
    return languages;
}

template <typename D> Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> impl_ISpeechRecognizerStatics<D>::SupportedGrammarLanguages() const
{
    Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> languages;
    check_hresult(WINRT_SHIM(ISpeechRecognizerStatics)->get_SupportedGrammarLanguages(put_abi(languages)));
    return languages;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession impl_ISpeechRecognizer2<D>::ContinuousRecognitionSession() const
{
    Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognizer2)->get_ContinuousRecognitionSession(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognizerState impl_ISpeechRecognizer2<D>::State() const
{
    Windows::Media::SpeechRecognition::SpeechRecognizerState value {};
    check_hresult(WINRT_SHIM(ISpeechRecognizer2)->get_State(&value));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISpeechRecognizer2<D>::StopRecognitionAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ISpeechRecognizer2)->abi_StopRecognitionAsync(put_abi(value)));
    return value;
}

template <typename D> event_token impl_ISpeechRecognizer2<D>::HypothesisGenerated(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> & value) const
{
    event_token returnValue {};
    check_hresult(WINRT_SHIM(ISpeechRecognizer2)->add_HypothesisGenerated(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> event_revoker<ISpeechRecognizer2> impl_ISpeechRecognizer2<D>::HypothesisGenerated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechRecognizer, Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ISpeechRecognizer2>(this, &ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer2::remove_HypothesisGenerated, HypothesisGenerated(value));
}

template <typename D> void impl_ISpeechRecognizer2<D>::HypothesisGenerated(event_token value) const
{
    check_hresult(WINRT_SHIM(ISpeechRecognizer2)->remove_HypothesisGenerated(value));
}

template <typename D> hstring impl_ISpeechRecognitionHypothesis<D>::Text() const
{
    hstring value;
    check_hresult(WINRT_SHIM(ISpeechRecognitionHypothesis)->get_Text(put_abi(value)));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionHypothesis impl_ISpeechRecognitionHypothesisGeneratedEventArgs<D>::Hypothesis() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionHypothesis value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechRecognitionHypothesisGeneratedEventArgs)->get_Hypothesis(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::TimeSpan impl_ISpeechContinuousRecognitionSession<D>::AutoStopSilenceTimeout() const
{
    Windows::Foundation::TimeSpan value {};
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->get_AutoStopSilenceTimeout(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechContinuousRecognitionSession<D>::AutoStopSilenceTimeout(const Windows::Foundation::TimeSpan & value) const
{
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->put_AutoStopSilenceTimeout(get_abi(value)));
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISpeechContinuousRecognitionSession<D>::StartAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->abi_StartAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISpeechContinuousRecognitionSession<D>::StartAsync(Windows::Media::SpeechRecognition::SpeechContinuousRecognitionMode mode) const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->abi_StartWithModeAsync(mode, put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISpeechContinuousRecognitionSession<D>::StopAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->abi_StopAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISpeechContinuousRecognitionSession<D>::CancelAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->abi_CancelAsync(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_ISpeechContinuousRecognitionSession<D>::PauseAsync() const
{
    Windows::Foundation::IAsyncAction value;
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->abi_PauseAsync(put_abi(value)));
    return value;
}

template <typename D> void impl_ISpeechContinuousRecognitionSession<D>::Resume() const
{
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->abi_Resume());
}

template <typename D> event_token impl_ISpeechContinuousRecognitionSession<D>::Completed(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> & value) const
{
    event_token returnValue {};
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->add_Completed(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> event_revoker<ISpeechContinuousRecognitionSession> impl_ISpeechContinuousRecognitionSession<D>::Completed(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ISpeechContinuousRecognitionSession>(this, &ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession::remove_Completed, Completed(value));
}

template <typename D> void impl_ISpeechContinuousRecognitionSession<D>::Completed(event_token value) const
{
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->remove_Completed(value));
}

template <typename D> event_token impl_ISpeechContinuousRecognitionSession<D>::ResultGenerated(const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> & value) const
{
    event_token returnValue {};
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->add_ResultGenerated(get_abi(value), &returnValue));
    return returnValue;
}

template <typename D> event_revoker<ISpeechContinuousRecognitionSession> impl_ISpeechContinuousRecognitionSession<D>::ResultGenerated(auto_revoke_t, const Windows::Foundation::TypedEventHandler<Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession, Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs> & value) const
{
    return impl::make_event_revoker<D, ISpeechContinuousRecognitionSession>(this, &ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession::remove_ResultGenerated, ResultGenerated(value));
}

template <typename D> void impl_ISpeechContinuousRecognitionSession<D>::ResultGenerated(event_token value) const
{
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionSession)->remove_ResultGenerated(value));
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus impl_ISpeechContinuousRecognitionCompletedEventArgs<D>::Status() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus value {};
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionCompletedEventArgs)->get_Status(&value));
    return value;
}

template <typename D> Windows::Media::SpeechRecognition::SpeechRecognitionResult impl_ISpeechContinuousRecognitionResultGeneratedEventArgs<D>::Result() const
{
    Windows::Media::SpeechRecognition::SpeechRecognitionResult value { nullptr };
    check_hresult(WINRT_SHIM(ISpeechContinuousRecognitionResultGeneratedEventArgs)->get_Result(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandManager<D>::InstallCommandSetsFromStorageFileAsync(const Windows::Storage::StorageFile & file) const
{
    Windows::Foundation::IAsyncAction installAction;
    check_hresult(WINRT_SHIM(IVoiceCommandManager)->abi_InstallCommandSetsFromStorageFileAsync(get_abi(file), put_abi(installAction)));
    return installAction;
}

template <typename D> Windows::Foundation::Collections::IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> impl_IVoiceCommandManager<D>::InstalledCommandSets() const
{
    Windows::Foundation::Collections::IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> voiceCommandSets;
    check_hresult(WINRT_SHIM(IVoiceCommandManager)->get_InstalledCommandSets(put_abi(voiceCommandSets)));
    return voiceCommandSets;
}

template <typename D> hstring impl_IVoiceCommandSet<D>::Language() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandSet)->get_Language(put_abi(value)));
    return value;
}

template <typename D> hstring impl_IVoiceCommandSet<D>::Name() const
{
    hstring value;
    check_hresult(WINRT_SHIM(IVoiceCommandSet)->get_Name(put_abi(value)));
    return value;
}

template <typename D> Windows::Foundation::IAsyncAction impl_IVoiceCommandSet<D>::SetPhraseListAsync(hstring_view phraseListName, iterable<hstring> phraseList) const
{
    Windows::Foundation::IAsyncAction updateAction;
    check_hresult(WINRT_SHIM(IVoiceCommandSet)->abi_SetPhraseListAsync(get_abi(phraseListName), get_abi(phraseList), put_abi(updateAction)));
    return updateAction;
}

inline SpeechRecognitionGrammarFileConstraint::SpeechRecognitionGrammarFileConstraint(const Windows::Storage::StorageFile & file) :
    SpeechRecognitionGrammarFileConstraint(get_activation_factory<SpeechRecognitionGrammarFileConstraint, ISpeechRecognitionGrammarFileConstraintFactory>().Create(file))
{}

inline SpeechRecognitionGrammarFileConstraint::SpeechRecognitionGrammarFileConstraint(const Windows::Storage::StorageFile & file, hstring_view tag) :
    SpeechRecognitionGrammarFileConstraint(get_activation_factory<SpeechRecognitionGrammarFileConstraint, ISpeechRecognitionGrammarFileConstraintFactory>().CreateWithTag(file, tag))
{}

inline SpeechRecognitionListConstraint::SpeechRecognitionListConstraint(iterable<hstring> commands) :
    SpeechRecognitionListConstraint(get_activation_factory<SpeechRecognitionListConstraint, ISpeechRecognitionListConstraintFactory>().Create(commands))
{}

inline SpeechRecognitionListConstraint::SpeechRecognitionListConstraint(iterable<hstring> commands, hstring_view tag) :
    SpeechRecognitionListConstraint(get_activation_factory<SpeechRecognitionListConstraint, ISpeechRecognitionListConstraintFactory>().CreateWithTag(commands, tag))
{}

inline SpeechRecognitionTopicConstraint::SpeechRecognitionTopicConstraint(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring_view topicHint) :
    SpeechRecognitionTopicConstraint(get_activation_factory<SpeechRecognitionTopicConstraint, ISpeechRecognitionTopicConstraintFactory>().Create(scenario, topicHint))
{}

inline SpeechRecognitionTopicConstraint::SpeechRecognitionTopicConstraint(Windows::Media::SpeechRecognition::SpeechRecognitionScenario scenario, hstring_view topicHint, hstring_view tag) :
    SpeechRecognitionTopicConstraint(get_activation_factory<SpeechRecognitionTopicConstraint, ISpeechRecognitionTopicConstraintFactory>().CreateWithTag(scenario, topicHint, tag))
{}

inline SpeechRecognizer::SpeechRecognizer() :
    SpeechRecognizer(activate_instance<SpeechRecognizer>())
{}

inline SpeechRecognizer::SpeechRecognizer(const Windows::Globalization::Language & language) :
    SpeechRecognizer(get_activation_factory<SpeechRecognizer, ISpeechRecognizerFactory>().Create(language))
{}

inline Windows::Globalization::Language SpeechRecognizer::SystemSpeechLanguage()
{
    return get_activation_factory<SpeechRecognizer, ISpeechRecognizerStatics>().SystemSpeechLanguage();
}

inline Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> SpeechRecognizer::SupportedTopicLanguages()
{
    return get_activation_factory<SpeechRecognizer, ISpeechRecognizerStatics>().SupportedTopicLanguages();
}

inline Windows::Foundation::Collections::IVectorView<Windows::Globalization::Language> SpeechRecognizer::SupportedGrammarLanguages()
{
    return get_activation_factory<SpeechRecognizer, ISpeechRecognizerStatics>().SupportedGrammarLanguages();
}

inline Windows::Foundation::IAsyncAction VoiceCommandManager::InstallCommandSetsFromStorageFileAsync(const Windows::Storage::StorageFile & file)
{
    return get_activation_factory<VoiceCommandManager, IVoiceCommandManager>().InstallCommandSetsFromStorageFileAsync(file);
}

inline Windows::Foundation::Collections::IMapView<hstring, Windows::Media::SpeechRecognition::VoiceCommandSet> VoiceCommandManager::InstalledCommandSets()
{
    return get_activation_factory<VoiceCommandManager, IVoiceCommandManager>().InstalledCommandSets();
}

}

}
#pragma warning(pop)
