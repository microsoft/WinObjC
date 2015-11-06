//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

// WindowsMediaSpeechRecognition.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WMSSpeechRecognitionSemanticInterpretation, WMSSpeechRecognitionResult, WMSSpeechRecognitionTopicConstraint,
    WMSSpeechRecognitionListConstraint, WMSSpeechRecognitionGrammarFileConstraint, WMSSpeechRecognizerTimeouts,
    WMSSpeechRecognizerUIOptions, WMSSpeechRecognitionCompilationResult, WMSSpeechRecognizer, WMSSpeechRecognitionQualityDegradingEventArgs,
    WMSSpeechRecognizerStateChangedEventArgs, WMSSpeechRecognitionVoiceCommandDefinitionConstraint, WMSSpeechContinuousRecognitionSession,
    WMSSpeechRecognitionHypothesisGeneratedEventArgs, WMSSpeechRecognitionHypothesis, WMSSpeechContinuousRecognitionCompletedEventArgs,
    WMSSpeechContinuousRecognitionResultGeneratedEventArgs;
@protocol WMSISpeechRecognitionCompilationResult
, WMSISpeechRecognizerTimeouts, WMSISpeechRecognizerUIOptions, WMSISpeechRecognitionResult, WMSISpeechRecognitionConstraint,
    WMSISpeechRecognitionResult2, WMSISpeechRecognitionSemanticInterpretation, WMSISpeechRecognitionTopicConstraint,
    WMSISpeechRecognitionTopicConstraintFactory, WMSISpeechRecognitionListConstraint, WMSISpeechRecognitionListConstraintFactory,
    WMSISpeechRecognitionGrammarFileConstraint, WMSISpeechRecognitionGrammarFileConstraintFactory,
    WMSISpeechRecognitionVoiceCommandDefinitionConstraint, WMSISpeechRecognitionQualityDegradingEventArgs,
    WMSISpeechRecognizerStateChangedEventArgs, WMSISpeechRecognizer, WMSISpeechRecognizerFactory, WMSISpeechRecognizerStatics,
    WMSISpeechRecognizer2, WMSISpeechRecognitionHypothesis, WMSISpeechRecognitionHypothesisGeneratedEventArgs,
    WMSISpeechContinuousRecognitionSession, WMSISpeechContinuousRecognitionCompletedEventArgs,
    WMSISpeechContinuousRecognitionResultGeneratedEventArgs;

// Windows.Media.SpeechRecognition.SpeechRecognitionConstraintProbability
enum _WMSSpeechRecognitionConstraintProbability {
    WMSSpeechRecognitionConstraintProbabilityDefault = 0,
    WMSSpeechRecognitionConstraintProbabilityMin = 1,
    WMSSpeechRecognitionConstraintProbabilityMax = 2,
};
typedef unsigned WMSSpeechRecognitionConstraintProbability;

// Windows.Media.SpeechRecognition.SpeechRecognitionConfidence
enum _WMSSpeechRecognitionConfidence {
    WMSSpeechRecognitionConfidenceHigh = 0,
    WMSSpeechRecognitionConfidenceMedium = 1,
    WMSSpeechRecognitionConfidenceLow = 2,
    WMSSpeechRecognitionConfidenceRejected = 3,
};
typedef unsigned WMSSpeechRecognitionConfidence;

// Windows.Media.SpeechRecognition.SpeechRecognitionScenario
enum _WMSSpeechRecognitionScenario {
    WMSSpeechRecognitionScenarioWebSearch = 0,
    WMSSpeechRecognitionScenarioDictation = 1,
    WMSSpeechRecognitionScenarioFormFilling = 2,
};
typedef unsigned WMSSpeechRecognitionScenario;

// Windows.Media.SpeechRecognition.SpeechRecognitionConstraintType
enum _WMSSpeechRecognitionConstraintType {
    WMSSpeechRecognitionConstraintTypeTopic = 0,
    WMSSpeechRecognitionConstraintTypeList = 1,
    WMSSpeechRecognitionConstraintTypeGrammar = 2,
    WMSSpeechRecognitionConstraintTypeVoiceCommandDefinition = 3,
};
typedef unsigned WMSSpeechRecognitionConstraintType;

// Windows.Media.SpeechRecognition.SpeechRecognizerState
enum _WMSSpeechRecognizerState {
    WMSSpeechRecognizerStateIdle = 0,
    WMSSpeechRecognizerStateCapturing = 1,
    WMSSpeechRecognizerStateProcessing = 2,
    WMSSpeechRecognizerStateSoundStarted = 3,
    WMSSpeechRecognizerStateSoundEnded = 4,
    WMSSpeechRecognizerStateSpeechDetected = 5,
    WMSSpeechRecognizerStatePaused = 6,
};
typedef unsigned WMSSpeechRecognizerState;

// Windows.Media.SpeechRecognition.SpeechRecognitionAudioProblem
enum _WMSSpeechRecognitionAudioProblem {
    WMSSpeechRecognitionAudioProblemNone = 0,
    WMSSpeechRecognitionAudioProblemTooNoisy = 1,
    WMSSpeechRecognitionAudioProblemNoSignal = 2,
    WMSSpeechRecognitionAudioProblemTooLoud = 3,
    WMSSpeechRecognitionAudioProblemTooQuiet = 4,
    WMSSpeechRecognitionAudioProblemTooFast = 5,
    WMSSpeechRecognitionAudioProblemTooSlow = 6,
};
typedef unsigned WMSSpeechRecognitionAudioProblem;

// Windows.Media.SpeechRecognition.SpeechRecognitionResultStatus
enum _WMSSpeechRecognitionResultStatus {
    WMSSpeechRecognitionResultStatusSuccess = 0,
    WMSSpeechRecognitionResultStatusTopicLanguageNotSupported = 1,
    WMSSpeechRecognitionResultStatusGrammarLanguageMismatch = 2,
    WMSSpeechRecognitionResultStatusGrammarCompilationFailure = 3,
    WMSSpeechRecognitionResultStatusAudioQualityFailure = 4,
    WMSSpeechRecognitionResultStatusUserCanceled = 5,
    WMSSpeechRecognitionResultStatusUnknown = 6,
    WMSSpeechRecognitionResultStatusTimeoutExceeded = 7,
    WMSSpeechRecognitionResultStatusPauseLimitExceeded = 8,
    WMSSpeechRecognitionResultStatusNetworkFailure = 9,
    WMSSpeechRecognitionResultStatusMicrophoneUnavailable = 10,
};
typedef unsigned WMSSpeechRecognitionResultStatus;

// Windows.Media.SpeechRecognition.SpeechContinuousRecognitionMode
enum _WMSSpeechContinuousRecognitionMode {
    WMSSpeechContinuousRecognitionModeDefault = 0,
    WMSSpeechContinuousRecognitionModePauseOnRecognition = 1,
};
typedef unsigned WMSSpeechContinuousRecognitionMode;

#include "WindowsGlobalization.h"
#include "WindowsFoundation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsStorage.h"

#import <Foundation/Foundation.h>

// Windows.Media.SpeechRecognition.ISpeechRecognitionConstraint
#ifndef __WMSISpeechRecognitionConstraint_DEFINED__
#define __WMSISpeechRecognitionConstraint_DEFINED__

@protocol WMSISpeechRecognitionConstraint
@property BOOL isEnabled;
@property WMSSpeechRecognitionConstraintProbability probability;
@property (copy) NSString* tag;
@property (readonly) WMSSpeechRecognitionConstraintType type;
@end

#endif // __WMSISpeechRecognitionConstraint_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionSemanticInterpretation
#ifndef __WMSSpeechRecognitionSemanticInterpretation_DEFINED__
#define __WMSSpeechRecognitionSemanticInterpretation_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionSemanticInterpretation : RTObject
@property (readonly) NSDictionary* properties;
@end

#endif // __WMSSpeechRecognitionSemanticInterpretation_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionResult
#ifndef __WMSSpeechRecognitionResult_DEFINED__
#define __WMSSpeechRecognitionResult_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionResult : RTObject
@property (readonly) WMSSpeechRecognitionConfidence confidence;
@property (readonly) RTObject<WMSISpeechRecognitionConstraint>* constraint;
@property (readonly) double rawConfidence;
@property (readonly) NSArray* rulePath;
@property (readonly) WMSSpeechRecognitionSemanticInterpretation* semanticInterpretation;
@property (readonly) WMSSpeechRecognitionResultStatus status;
@property (readonly) NSString* text;
@property (readonly) WFTimeSpan* phraseDuration;
@property (readonly) WFDateTime* phraseStartTime;
- (NSArray*)getAlternates:(unsigned int)maxAlternates;
@end

#endif // __WMSSpeechRecognitionResult_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionTopicConstraint
#ifndef __WMSSpeechRecognitionTopicConstraint_DEFINED__
#define __WMSSpeechRecognitionTopicConstraint_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionTopicConstraint : RTObject <WMSISpeechRecognitionConstraint>
+ (WMSSpeechRecognitionTopicConstraint*)create:(WMSSpeechRecognitionScenario)scenario topicHint:(NSString*)topicHint ACTIVATOR;
+ (WMSSpeechRecognitionTopicConstraint*)createWithTag:(WMSSpeechRecognitionScenario)scenario
                                            topicHint:(NSString*)topicHint
                                                  tag:(NSString*)tag ACTIVATOR;
@property (copy) NSString* tag;
@property WMSSpeechRecognitionConstraintProbability probability;
@property BOOL isEnabled;
@property (readonly) WMSSpeechRecognitionConstraintType type;
@property (readonly) WMSSpeechRecognitionScenario scenario;
@property (readonly) NSString* topicHint;
@end

#endif // __WMSSpeechRecognitionTopicConstraint_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionListConstraint
#ifndef __WMSSpeechRecognitionListConstraint_DEFINED__
#define __WMSSpeechRecognitionListConstraint_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionListConstraint : RTObject <WMSISpeechRecognitionConstraint>
+ (WMSSpeechRecognitionListConstraint*)create:(id<NSFastEnumeration> /* NSString * */)commands ACTIVATOR;
+ (WMSSpeechRecognitionListConstraint*)createWithTag:(id<NSFastEnumeration> /* NSString * */)commands tag:(NSString*)tag ACTIVATOR;
@property (copy) NSString* tag;
@property WMSSpeechRecognitionConstraintProbability probability;
@property BOOL isEnabled;
@property (readonly) WMSSpeechRecognitionConstraintType type;
@property (readonly) NSMutableArray* commands;
@end

#endif // __WMSSpeechRecognitionListConstraint_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionGrammarFileConstraint
#ifndef __WMSSpeechRecognitionGrammarFileConstraint_DEFINED__
#define __WMSSpeechRecognitionGrammarFileConstraint_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionGrammarFileConstraint : RTObject <WMSISpeechRecognitionConstraint>
+ (WMSSpeechRecognitionGrammarFileConstraint*)create:(WSStorageFile*)file ACTIVATOR;
+ (WMSSpeechRecognitionGrammarFileConstraint*)createWithTag:(WSStorageFile*)file tag:(NSString*)tag ACTIVATOR;
@property (copy) NSString* tag;
@property WMSSpeechRecognitionConstraintProbability probability;
@property BOOL isEnabled;
@property (readonly) WMSSpeechRecognitionConstraintType type;
@property (readonly) WSStorageFile* grammarFile;
@end

#endif // __WMSSpeechRecognitionGrammarFileConstraint_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognizerTimeouts
#ifndef __WMSSpeechRecognizerTimeouts_DEFINED__
#define __WMSSpeechRecognizerTimeouts_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognizerTimeouts : RTObject
@property (copy) WFTimeSpan* initialSilenceTimeout;
@property (copy) WFTimeSpan* endSilenceTimeout;
@property (copy) WFTimeSpan* babbleTimeout;
@end

#endif // __WMSSpeechRecognizerTimeouts_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognizerUIOptions
#ifndef __WMSSpeechRecognizerUIOptions_DEFINED__
#define __WMSSpeechRecognizerUIOptions_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognizerUIOptions : RTObject
@property BOOL showConfirmation;
@property BOOL isReadBackEnabled;
@property (copy) NSString* exampleText;
@property (copy) NSString* audiblePrompt;
@end

#endif // __WMSSpeechRecognizerUIOptions_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionCompilationResult
#ifndef __WMSSpeechRecognitionCompilationResult_DEFINED__
#define __WMSSpeechRecognitionCompilationResult_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionCompilationResult : RTObject
@property (readonly) WMSSpeechRecognitionResultStatus status;
@end

#endif // __WMSSpeechRecognitionCompilationResult_DEFINED__

// Windows.Foundation.IClosable
#ifndef __WFIClosable_DEFINED__
#define __WFIClosable_DEFINED__

@protocol WFIClosable
- (void)close;
@end

#endif // __WFIClosable_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognizer
#ifndef __WMSSpeechRecognizer_DEFINED__
#define __WMSSpeechRecognizer_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognizer : RTObject <WFIClosable>
+ (WMSSpeechRecognizer*)create:(WGLanguage*)language ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property (readonly) NSMutableArray* constraints;
@property (readonly) WGLanguage* currentLanguage;
@property (readonly) WMSSpeechRecognizerTimeouts* timeouts;
@property (readonly) WMSSpeechRecognizerUIOptions* uIOptions;
@property (readonly) WMSSpeechContinuousRecognitionSession* continuousRecognitionSession;
@property (readonly) WMSSpeechRecognizerState state;
+ (NSArray*)supportedGrammarLanguages;
+ (NSArray*)supportedTopicLanguages;
+ (WGLanguage*)systemSpeechLanguage;
- (EventRegistrationToken)addRecognitionQualityDegradingEvent:(void (^)(WMSSpeechRecognizer*,
                                                                        WMSSpeechRecognitionQualityDegradingEventArgs*))del;
- (void)removeRecognitionQualityDegradingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMSSpeechRecognizer*, WMSSpeechRecognizerStateChangedEventArgs*))del;
- (void)removeStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHypothesisGeneratedEvent:(void (^)(WMSSpeechRecognizer*,
                                                                WMSSpeechRecognitionHypothesisGeneratedEventArgs*))del;
- (void)removeHypothesisGeneratedEvent:(EventRegistrationToken)tok;
- (void)compileConstraintsAsyncWithSuccess:(void (^)(WMSSpeechRecognitionCompilationResult*))success failure:(void (^)(NSError*))failure;
- (void)recognizeAsyncWithSuccess:(void (^)(WMSSpeechRecognitionResult*))success failure:(void (^)(NSError*))failure;
- (void)recognizeWithUIAsyncWithSuccess:(void (^)(WMSSpeechRecognitionResult*))success failure:(void (^)(NSError*))failure;
- (void)close;
- (RTObject<WFIAsyncAction>*)stopRecognitionAsync;
@end

#endif // __WMSSpeechRecognizer_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionQualityDegradingEventArgs
#ifndef __WMSSpeechRecognitionQualityDegradingEventArgs_DEFINED__
#define __WMSSpeechRecognitionQualityDegradingEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionQualityDegradingEventArgs : RTObject
@property (readonly) WMSSpeechRecognitionAudioProblem problem;
@end

#endif // __WMSSpeechRecognitionQualityDegradingEventArgs_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognizerStateChangedEventArgs
#ifndef __WMSSpeechRecognizerStateChangedEventArgs_DEFINED__
#define __WMSSpeechRecognizerStateChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognizerStateChangedEventArgs : RTObject
@property (readonly) WMSSpeechRecognizerState state;
@end

#endif // __WMSSpeechRecognizerStateChangedEventArgs_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionVoiceCommandDefinitionConstraint
#ifndef __WMSSpeechRecognitionVoiceCommandDefinitionConstraint_DEFINED__
#define __WMSSpeechRecognitionVoiceCommandDefinitionConstraint_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionVoiceCommandDefinitionConstraint : RTObject <WMSISpeechRecognitionConstraint>
@property (copy) NSString* tag;
@property WMSSpeechRecognitionConstraintProbability probability;
@property BOOL isEnabled;
@property (readonly) WMSSpeechRecognitionConstraintType type;
@end

#endif // __WMSSpeechRecognitionVoiceCommandDefinitionConstraint_DEFINED__

// Windows.Media.SpeechRecognition.SpeechContinuousRecognitionSession
#ifndef __WMSSpeechContinuousRecognitionSession_DEFINED__
#define __WMSSpeechContinuousRecognitionSession_DEFINED__

WINRT_EXPORT
@interface WMSSpeechContinuousRecognitionSession : RTObject
@property (copy) WFTimeSpan* autoStopSilenceTimeout;
- (EventRegistrationToken)addCompletedEvent:(void (^)(WMSSpeechContinuousRecognitionSession*,
                                                      WMSSpeechContinuousRecognitionCompletedEventArgs*))del;
- (void)removeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResultGeneratedEvent:(void (^)(WMSSpeechContinuousRecognitionSession*,
                                                            WMSSpeechContinuousRecognitionResultGeneratedEventArgs*))del;
- (void)removeResultGeneratedEvent:(EventRegistrationToken)tok;
- (RTObject<WFIAsyncAction>*)startAsync;
- (RTObject<WFIAsyncAction>*)startWithModeAsync:(WMSSpeechContinuousRecognitionMode)mode;
- (RTObject<WFIAsyncAction>*)stopAsync;
- (RTObject<WFIAsyncAction>*)cancelAsync;
- (RTObject<WFIAsyncAction>*)pauseAsync;
- (void)resume;
@end

#endif // __WMSSpeechContinuousRecognitionSession_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionHypothesisGeneratedEventArgs
#ifndef __WMSSpeechRecognitionHypothesisGeneratedEventArgs_DEFINED__
#define __WMSSpeechRecognitionHypothesisGeneratedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionHypothesisGeneratedEventArgs : RTObject
@property (readonly) WMSSpeechRecognitionHypothesis* hypothesis;
@end

#endif // __WMSSpeechRecognitionHypothesisGeneratedEventArgs_DEFINED__

// Windows.Media.SpeechRecognition.SpeechRecognitionHypothesis
#ifndef __WMSSpeechRecognitionHypothesis_DEFINED__
#define __WMSSpeechRecognitionHypothesis_DEFINED__

WINRT_EXPORT
@interface WMSSpeechRecognitionHypothesis : RTObject
@property (readonly) NSString* text;
@end

#endif // __WMSSpeechRecognitionHypothesis_DEFINED__

// Windows.Media.SpeechRecognition.SpeechContinuousRecognitionCompletedEventArgs
#ifndef __WMSSpeechContinuousRecognitionCompletedEventArgs_DEFINED__
#define __WMSSpeechContinuousRecognitionCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSSpeechContinuousRecognitionCompletedEventArgs : RTObject
@property (readonly) WMSSpeechRecognitionResultStatus status;
@end

#endif // __WMSSpeechContinuousRecognitionCompletedEventArgs_DEFINED__

// Windows.Media.SpeechRecognition.SpeechContinuousRecognitionResultGeneratedEventArgs
#ifndef __WMSSpeechContinuousRecognitionResultGeneratedEventArgs_DEFINED__
#define __WMSSpeechContinuousRecognitionResultGeneratedEventArgs_DEFINED__

WINRT_EXPORT
@interface WMSSpeechContinuousRecognitionResultGeneratedEventArgs : RTObject
@property (readonly) WMSSpeechRecognitionResult* result;
@end

#endif // __WMSSpeechContinuousRecognitionResultGeneratedEventArgs_DEFINED__
