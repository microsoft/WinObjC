//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

// WindowsMediaSpeechRecognition_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsGlobalization_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsStorage_priv.h"
static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>
WMSISpeechRecognitionTopicConstraintFactory_inst();
static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>
WMSISpeechRecognitionListConstraintFactory_inst();
static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>
WMSISpeechRecognitionGrammarFileConstraintFactory_inst();
static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerFactory> WMSISpeechRecognizerFactory_inst();
ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStatics> WMSISpeechRecognizerStatics_inst();
ComPtr<ABI::Windows::Media::SpeechRecognition::IVoiceCommandManager> WMSIVoiceCommandManager_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_WGLanguage_create(IInspectable* val);
id RTProxiedNSArray_WMSSpeechRecognitionResult_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSDictionary_NSString_WMSVoiceCommandSet_create(IInspectable* val);
id RTProxiedNSMutableArray_NSString_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_WMSISpeechRecognitionConstraint_create(IInspectable* val);

@class RTProxiedIterableNSArray_NSString, RTProxiedNSArray_NSString, RTProxiedNSArray_WGLanguage,
    RTProxiedNSArray_WMSSpeechRecognitionResult;
@class RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString, RTProxiedNSDictionary_NSString_WMSVoiceCommandSet,
    RTProxiedNSMutableArray_NSString;
@class RTProxiedNSMutableArray_RTObject_WMSISpeechRecognitionConstraint;

#ifndef __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionCompletedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession*,
                              ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionCompletedEventArgs*>> {
    void (^_delegate)(WMSSpeechContinuousRecognitionSession*, WMSSpeechContinuousRecognitionCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionCompletedEventArgs(
        void (^del)(WMSSpeechContinuousRecognitionSession*, WMSSpeechContinuousRecognitionCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession* arg0,
           ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSSpeechContinuousRecognitionSession>(arg0),
                      _createRtProxy<WMSSpeechContinuousRecognitionCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionResultGeneratedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionResultGeneratedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionResultGeneratedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionSession*,
                              ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionResultGeneratedEventArgs*>> {
    void (^_delegate)(WMSSpeechContinuousRecognitionSession*, WMSSpeechContinuousRecognitionResultGeneratedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionResultGeneratedEventArgs(
        void (^del)(WMSSpeechContinuousRecognitionSession*, WMSSpeechContinuousRecognitionResultGeneratedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionResultGeneratedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession* arg0,
           ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSSpeechContinuousRecognitionSession>(arg0),
                      _createRtProxy<WMSSpeechContinuousRecognitionResultGeneratedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionHypothesisGeneratedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionHypothesisGeneratedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionHypothesisGeneratedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::SpeechRecognition::SpeechRecognizer*,
                              ABI::Windows::Media::SpeechRecognition::SpeechRecognitionHypothesisGeneratedEventArgs*>> {
    void (^_delegate)(WMSSpeechRecognizer*, WMSSpeechRecognitionHypothesisGeneratedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionHypothesisGeneratedEventArgs(
        void (^del)(WMSSpeechRecognizer*, WMSSpeechRecognitionHypothesisGeneratedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionHypothesisGeneratedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer* arg0,
           ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSSpeechRecognizer>(arg0), _createRtProxy<WMSSpeechRecognitionHypothesisGeneratedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionQualityDegradingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionQualityDegradingEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionQualityDegradingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<
                              ABI::Windows::Media::SpeechRecognition::SpeechRecognizer*,
                              ABI::Windows::Media::SpeechRecognition::SpeechRecognitionQualityDegradingEventArgs*>> {
    void (^_delegate)(WMSSpeechRecognizer*, WMSSpeechRecognitionQualityDegradingEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionQualityDegradingEventArgs(
        void (^del)(WMSSpeechRecognizer*, WMSSpeechRecognitionQualityDegradingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionQualityDegradingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer* arg0,
           ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSSpeechRecognizer>(arg0), _createRtProxy<WMSSpeechRecognitionQualityDegradingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognizerStateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognizerStateChangedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognizerStateChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::Media::SpeechRecognition::SpeechRecognizer*,
                                                       ABI::Windows::Media::SpeechRecognition::SpeechRecognizerStateChangedEventArgs*>> {
    void (^_delegate)(WMSSpeechRecognizer*, WMSSpeechRecognizerStateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognizerStateChangedEventArgs(
        void (^del)(WMSSpeechRecognizer*, WMSSpeechRecognizerStateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognizerStateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer* arg0,
           ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WMSSpeechRecognizer>(arg0), _createRtProxy<WMSSpeechRecognizerStateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif
