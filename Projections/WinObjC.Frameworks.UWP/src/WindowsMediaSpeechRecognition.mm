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

// WindowsMediaSpeechRecognition.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.SpeechRecognition.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaSpeechRecognition.h"
#include "WindowsMediaSpeechRecognition_priv.h"

@implementation WMSISpeechRecognitionConstraint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (WMSSpeechRecognitionConstraintType)type {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintType)unmarshalledReturn;
}

- (WMSSpeechRecognitionConstraintProbability)probability {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Probability(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintProbability)unmarshalledReturn;
}

- (void)setProbability:(WMSSpeechRecognitionConstraintProbability)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Probability((ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability)value));
}

@end

@implementation WMSSpeechRecognitionSemanticInterpretation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSDictionary* /* NSString *, NSArray* < NSString * > */)properties {
    ComPtr<IMapView<HSTRING, IVectorView<HSTRING>*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

@end

@implementation WMSSpeechRecognitionResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognitionResultStatus)status {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMSSpeechRecognitionResultStatus)unmarshalledReturn;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WMSSpeechRecognitionConfidence)confidence {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConfidence unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Confidence(&unmarshalledReturn));
    return (WMSSpeechRecognitionConfidence)unmarshalledReturn;
}

- (WMSSpeechRecognitionSemanticInterpretation*)semanticInterpretation {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_SemanticInterpretation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechRecognitionSemanticInterpretation>(unmarshalledReturn.Get());
}

- (NSArray* /* WMSSpeechRecognitionResult* */)getAlternates:(unsigned int)maxAlternates {
    ComPtr<IVectorView<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->GetAlternates(maxAlternates, unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMSSpeechRecognitionResult_create(unmarshalledReturn.Get());
}

- (RTObject<WMSISpeechRecognitionConstraint>*)constraint {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Constraint(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSISpeechRecognitionConstraint>(unmarshalledReturn.Get());
}

- (NSArray* /* NSString * */)rulePath {
    ComPtr<IVectorView<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_RulePath(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_NSString_create(unmarshalledReturn.Get());
}

- (double)rawConfidence {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_RawConfidence(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFDateTime*)phraseStartTime {
    ABI::Windows::Foundation::DateTime unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhraseStartTime(&unmarshalledReturn));
    return WFDateTime_create(unmarshalledReturn);
}

- (WFTimeSpan*)phraseDuration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PhraseDuration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

@end

@implementation WMSSpeechRecognitionTopicConstraint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory>
WMSISpeechRecognitionTopicConstraintFactory_inst() {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraintFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.SpeechRecognition.SpeechRecognitionTopicConstraint").Get(), &inst));
    return inst;
}

+ (WMSSpeechRecognitionTopicConstraint*)make:(WMSSpeechRecognitionScenario)scenario topicHint:(NSString*)topicHint {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognitionTopicConstraintFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create((ABI::Windows::Media::SpeechRecognition::SpeechRecognitionScenario)scenario,
                                        nsStrToHstr(topicHint).Get(),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMSSpeechRecognitionTopicConstraint>(unmarshalledReturn.Get()) retain];
}

+ (WMSSpeechRecognitionTopicConstraint*)makeWithTag:(WMSSpeechRecognitionScenario)scenario
                                          topicHint:(NSString*)topicHint
                                                tag:(NSString*)tag {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognitionTopicConstraintFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTag((ABI::Windows::Media::SpeechRecognition::SpeechRecognitionScenario)scenario,
                                               nsStrToHstr(topicHint).Get(),
                                               nsStrToHstr(tag).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMSSpeechRecognitionTopicConstraint>(unmarshalledReturn.Get()) retain];
}

- (WMSSpeechRecognitionScenario)scenario {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionScenario unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scenario(&unmarshalledReturn));
    return (WMSSpeechRecognitionScenario)unmarshalledReturn;
}

- (NSString*)topicHint {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_TopicHint(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (WMSSpeechRecognitionConstraintType)type {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintType)unmarshalledReturn;
}

- (WMSSpeechRecognitionConstraintProbability)probability {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Probability(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintProbability)unmarshalledReturn;
}

- (void)setProbability:(WMSSpeechRecognitionConstraintProbability)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Probability((ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability)value));
}

@end

@implementation WMSSpeechRecognitionListConstraint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory>
WMSISpeechRecognitionListConstraintFactory_inst() {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraintFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.SpeechRecognition.SpeechRecognitionListConstraint").Get(), &inst));
    return inst;
}

+ (WMSSpeechRecognitionListConstraint*)make:(id<NSFastEnumeration> /* NSString * */)commands {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognitionListConstraintFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                            ConvertToIterable<NSString, HSTRING>(commands).Get()),
                                        unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMSSpeechRecognitionListConstraint>(unmarshalledReturn.Get()) retain];
}

+ (WMSSpeechRecognitionListConstraint*)makeWithTag:(id<NSFastEnumeration> /* NSString * */)commands tag:(NSString*)tag {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognitionListConstraintFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateWithTag(static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                    ConvertToIterable<NSString, HSTRING>(commands).Get()),
                                nsStrToHstr(tag).Get(),
                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMSSpeechRecognitionListConstraint>(unmarshalledReturn.Get()) retain];
}

- (NSMutableArray* /* NSString * */)commands {
    ComPtr<IVector<HSTRING>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionListConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Commands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_NSString_create(unmarshalledReturn.Get());
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (WMSSpeechRecognitionConstraintType)type {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintType)unmarshalledReturn;
}

- (WMSSpeechRecognitionConstraintProbability)probability {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Probability(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintProbability)unmarshalledReturn;
}

- (void)setProbability:(WMSSpeechRecognitionConstraintProbability)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Probability((ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability)value));
}

@end

@implementation WMSSpeechRecognitionGrammarFileConstraint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory>
WMSISpeechRecognitionGrammarFileConstraintFactory_inst() {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraintFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Media.SpeechRecognition.SpeechRecognitionGrammarFileConstraint").Get(), &inst));
    return inst;
}

+ (WMSSpeechRecognitionGrammarFileConstraint*)make:(WSStorageFile*)file {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognitionGrammarFileConstraintFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMSSpeechRecognitionGrammarFileConstraint>(unmarshalledReturn.Get()) retain];
}

+ (WMSSpeechRecognitionGrammarFileConstraint*)makeWithTag:(WSStorageFile*)file tag:(NSString*)tag {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognitionGrammarFileConstraintFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithTag(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                               nsStrToHstr(tag).Get(),
                                               unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMSSpeechRecognitionGrammarFileConstraint>(unmarshalledReturn.Get()) retain];
}

- (WSStorageFile*)grammarFile {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_GrammarFile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (WMSSpeechRecognitionConstraintType)type {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintType)unmarshalledReturn;
}

- (WMSSpeechRecognitionConstraintProbability)probability {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Probability(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintProbability)unmarshalledReturn;
}

- (void)setProbability:(WMSSpeechRecognitionConstraintProbability)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Probability((ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability)value));
}

@end

@implementation WMSSpeechRecognizerTimeouts

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)initialSilenceTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialSilenceTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setInitialSilenceTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>(self);
    THROW_NS_IF_FAILED(_comInst->put_InitialSilenceTimeout(*[value internalStruct]));
}

- (WFTimeSpan*)endSilenceTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndSilenceTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setEndSilenceTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndSilenceTimeout(*[value internalStruct]));
}

- (WFTimeSpan*)babbleTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>(self);
    THROW_NS_IF_FAILED(_comInst->get_BabbleTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setBabbleTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts>(self);
    THROW_NS_IF_FAILED(_comInst->put_BabbleTimeout(*[value internalStruct]));
}

@end

@implementation WMSSpeechRecognizerUIOptions

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)exampleText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExampleText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setExampleText:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_ExampleText(nsStrToHstr(value).Get()));
}

- (NSString*)audiblePrompt {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudiblePrompt(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setAudiblePrompt:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudiblePrompt(nsStrToHstr(value).Get()));
}

- (BOOL)isReadBackEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadBackEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsReadBackEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsReadBackEnabled((boolean)value));
}

- (BOOL)showConfirmation {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShowConfirmation(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShowConfirmation:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShowConfirmation((boolean)value));
}

@end

@implementation WMSSpeechRecognitionCompilationResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognitionResultStatus)status {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMSSpeechRecognitionResultStatus)unmarshalledReturn;
}

@end

@implementation WMSSpeechRecognizer

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerFactory> WMSISpeechRecognizerFactory_inst() {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.SpeechRecognition.SpeechRecognizer").Get(),
                                                       &inst));
    return inst;
}

+ (WMSSpeechRecognizer*)make:(WGLanguage*)language {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognizerFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Globalization::ILanguage>(language).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMSSpeechRecognizer>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.SpeechRecognition.SpeechRecognizer").Get(), &out));
    return [_createRtProxy<WMSSpeechRecognizer>(out.Get()) retain];
}

ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStatics> WMSISpeechRecognizerStatics_inst() {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.SpeechRecognition.SpeechRecognizer").Get(),
                                                       &inst));
    return inst;
}

+ (WGLanguage*)systemSpeechLanguage {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognizerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SystemSpeechLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGLanguage>(unmarshalledReturn.Get());
}

+ (NSArray* /* WGLanguage* */)supportedTopicLanguages {
    ComPtr<IVectorView<ABI::Windows::Globalization::Language*>> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognizerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedTopicLanguages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGLanguage_create(unmarshalledReturn.Get());
}

+ (NSArray* /* WGLanguage* */)supportedGrammarLanguages {
    ComPtr<IVectorView<ABI::Windows::Globalization::Language*>> unmarshalledReturn;
    auto _comInst = WMSISpeechRecognizerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedGrammarLanguages(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WGLanguage_create(unmarshalledReturn.Get());
}

- (WGLanguage*)currentLanguage {
    ComPtr<ABI::Windows::Globalization::ILanguage> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentLanguage(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGLanguage>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WMSISpeechRecognitionConstraint>* */)constraints {
    ComPtr<IVector<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Constraints(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMSISpeechRecognitionConstraint_create(unmarshalledReturn.Get());
}

- (WMSSpeechRecognizerTimeouts*)timeouts {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerTimeouts> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_Timeouts(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechRecognizerTimeouts>(unmarshalledReturn.Get());
}

- (WMSSpeechRecognizerUIOptions*)uIOptions {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerUIOptions> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->get_UIOptions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechRecognizerUIOptions>(unmarshalledReturn.Get());
}

- (void)compileConstraintsAsyncWithSuccess:(void (^)(WMSSpeechRecognitionCompilationResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult*>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->CompileConstraintsAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult*>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionCompilationResult*>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionCompilationResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMSSpeechRecognitionCompilationResult>(result.Get()));
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                    }
                }
            } else {
                if (failureRc) {
                    failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                }
            }
            return S_OK;
        }
    });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)recognizeAsyncWithSuccess:(void (^)(WMSSpeechRecognitionResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->RecognizeAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMSSpeechRecognitionResult>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (void)recognizeWithUIAsyncWithSuccess:(void (^)(WMSSpeechRecognitionResult*))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->RecognizeWithUIAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>,
        FtmBase>>(
        [successRc,
         failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>* op,
                    AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMSSpeechRecognitionResult>(result.Get()));
                        }
                    } else {
                        if (failureRc) {
                            failureRc([NSError errorWithDomain:@"HRESULT" code:hr userInfo:nil]);
                        }
                    }
                } else {
                    if (failureRc) {
                        failureRc([NSError errorWithDomain:@"Async" code:(int)status userInfo:nil]);
                    }
                }
                return S_OK;
            }
        });

    unmarshalledReturn->put_Completed(completionHandler.Get());
}

- (EventRegistrationToken)addRecognitionQualityDegradingEvent:
    (void (^)(WMSSpeechRecognizer*, WMSSpeechRecognitionQualityDegradingEventArgs*))speechRecognitionQualityDegradingHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_RecognitionQualityDegrading(
        Make<
            ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionQualityDegradingEventArgs>(
            speechRecognitionQualityDegradingHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRecognitionQualityDegradingEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RecognitionQualityDegrading(cookie));
}

- (EventRegistrationToken)addStateChangedEvent:(void (^)(WMSSpeechRecognizer*,
                                                         WMSSpeechRecognizerStateChangedEventArgs*))stateChangedHandler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->add_StateChanged(
        Make<
            ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognizerStateChangedEventArgs>(
            stateChangedHandler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeStateChangedEvent:(EventRegistrationToken)cookie {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer>(self);
    THROW_NS_IF_FAILED(_comInst->remove_StateChanged(cookie));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WMSSpeechContinuousRecognitionSession*)continuousRecognitionSession {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContinuousRecognitionSession(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechContinuousRecognitionSession>(unmarshalledReturn.Get());
}

- (WMSSpeechRecognizerState)state {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognizerState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer2>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WMSSpeechRecognizerState)unmarshalledReturn;
}

- (RTObject<WFIAsyncAction>*)stopRecognitionAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer2>(self);
    THROW_NS_IF_FAILED(_comInst->StopRecognitionAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addHypothesisGeneratedEvent:(void (^)(WMSSpeechRecognizer*,
                                                                WMSSpeechRecognitionHypothesisGeneratedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer2>(self);
    THROW_NS_IF_FAILED(_comInst->add_HypothesisGenerated(
        Make<
            ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechRecognizer_Windows_Media_SpeechRecognition_SpeechRecognitionHypothesisGeneratedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHypothesisGeneratedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizer2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HypothesisGenerated(value));
}

@end

@implementation WMSSpeechRecognitionQualityDegradingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognitionAudioProblem)problem {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionAudioProblem unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Problem(&unmarshalledReturn));
    return (WMSSpeechRecognitionAudioProblem)unmarshalledReturn;
}

@end

@implementation WMSSpeechRecognizerStateChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognizerState)state {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognizerState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WMSSpeechRecognizerState)unmarshalledReturn;
}

@end

@implementation WMSSpeechRecognitionVoiceCommandDefinitionConstraint

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsEnabled((boolean)value));
}

- (NSString*)tag {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Tag(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTag:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Tag(nsStrToHstr(value).Get()));
}

- (WMSSpeechRecognitionConstraintType)type {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintType)unmarshalledReturn;
}

- (WMSSpeechRecognitionConstraintProbability)probability {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->get_Probability(&unmarshalledReturn));
    return (WMSSpeechRecognitionConstraintProbability)unmarshalledReturn;
}

- (void)setProbability:(WMSSpeechRecognitionConstraintProbability)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint>(self);
    THROW_NS_IF_FAILED(_comInst->put_Probability((ABI::Windows::Media::SpeechRecognition::SpeechRecognitionConstraintProbability)value));
}

@end

@implementation WMSSpeechContinuousRecognitionSession

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)autoStopSilenceTimeout {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->get_AutoStopSilenceTimeout(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setAutoStopSilenceTimeout:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->put_AutoStopSilenceTimeout(*[value internalStruct]));
}

- (RTObject<WFIAsyncAction>*)startAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->StartAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)startWithModeAsync:(WMSSpeechContinuousRecognitionMode)mode {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->StartWithModeAsync((ABI::Windows::Media::SpeechRecognition::SpeechContinuousRecognitionMode)mode,
                                                    unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)stopAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->StopAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)cancelAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->CancelAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (RTObject<WFIAsyncAction>*)pauseAsync {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->PauseAsync(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(WMSSpeechContinuousRecognitionSession*,
                                                      WMSSpeechContinuousRecognitionCompletedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(
        Make<
            ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionCompletedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(value));
}

- (EventRegistrationToken)addResultGeneratedEvent:(void (^)(WMSSpeechContinuousRecognitionSession*,
                                                            WMSSpeechContinuousRecognitionResultGeneratedEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->add_ResultGenerated(
        Make<
            ITypedEventHandler_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionSession_Windows_Media_SpeechRecognition_SpeechContinuousRecognitionResultGeneratedEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeResultGeneratedEvent:(EventRegistrationToken)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionSession>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ResultGenerated(value));
}

@end

@implementation WMSSpeechRecognitionHypothesisGeneratedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognitionHypothesis*)hypothesis {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Hypothesis(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechRecognitionHypothesis>(unmarshalledReturn.Get());
}

@end

@implementation WMSSpeechRecognitionHypothesis

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)text {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionHypothesis>(self);
    THROW_NS_IF_FAILED(_comInst->get_Text(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WMSSpeechContinuousRecognitionCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognitionResultStatus)status {
    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResultStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMSSpeechRecognitionResultStatus)unmarshalledReturn;
}

@end

@implementation WMSSpeechContinuousRecognitionResultGeneratedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMSSpeechRecognitionResult*)result {
    ComPtr<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Result(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMSSpeechRecognitionResult>(unmarshalledReturn.Get());
}

@end

@implementation WMSVoiceCommandManager

ComPtr<ABI::Windows::Media::SpeechRecognition::IVoiceCommandManager> WMSIVoiceCommandManager_inst() {
    ComPtr<ABI::Windows::Media::SpeechRecognition::IVoiceCommandManager> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.SpeechRecognition.VoiceCommandManager").Get(),
                                                       &inst));
    return inst;
}

+ (RTObject<WFIAsyncAction>*)installCommandSetsFromStorageFileAsync:(WSStorageFile*)file {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = WMSIVoiceCommandManager_inst();
    THROW_NS_IF_FAILED(_comInst->InstallCommandSetsFromStorageFileAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                                        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

+ (NSDictionary* /* NSString *, WMSVoiceCommandSet* */)installedCommandSets {
    ComPtr<IMapView<HSTRING, ABI::Windows::Media::SpeechRecognition::VoiceCommandSet*>> unmarshalledReturn;
    auto _comInst = WMSIVoiceCommandManager_inst();
    THROW_NS_IF_FAILED(_comInst->get_InstalledCommandSets(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSDictionary_NSString_WMSVoiceCommandSet_create(unmarshalledReturn.Get());
}

@end

@implementation WMSVoiceCommandSet

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::SpeechRecognition::IVoiceCommandSet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)language {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::IVoiceCommandSet>(self);
    THROW_NS_IF_FAILED(_comInst->get_Language(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::IVoiceCommandSet>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFIAsyncAction>*)setPhraseListAsync:(NSString*)phraseListName phraseList:(id<NSFastEnumeration> /* NSString * */)phraseList {
    ComPtr<ABI::Windows::Foundation::IAsyncAction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::SpeechRecognition::IVoiceCommandSet>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetPhraseListAsync(nsStrToHstr(phraseListName).Get(),
                                     static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
                                         ConvertToIterable<NSString, HSTRING>(phraseList).Get()),
                                     unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFIAsyncAction>(unmarshalledReturn.Get());
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<HSTRING>,
                                         RTArrayObj<HSTRING, IVectorView<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(
            val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WGLanguage_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter = std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Globalization::Language*>,
                                                                             RTArrayObj<ABI::Windows::Globalization::ILanguage*,
                                                                                        IVectorView<ABI::Windows::Globalization::Language*>,
                                                                                        WGLanguage,
                                                                                        ABI::Windows::Globalization::Language*,
                                                                                        dummyObjCCreator,
                                                                                        dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMSSpeechRecognitionResult_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>,
                                         RTArrayObj<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionResult*,
                                                    IVectorView<ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*>,
                                                    WMSSpeechRecognitionResult,
                                                    ABI::Windows::Media::SpeechRecognition::SpeechRecognitionResult*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_RTProxiedNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<
        DictionaryAdapterObj<IMapView<HSTRING, IVectorView<HSTRING>*>,
                             DictionaryKeyEnumeratorAdapterObj<RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, IVectorView<HSTRING>*>>,
                             RTMapViewObj<HSTRING,
                                          HSTRING,
                                          IVectorView<HSTRING>*,
                                          IVectorView<HSTRING>*,
                                          NSString,
                                          RTProxiedNSArray,
                                          IMapView<HSTRING, IVectorView<HSTRING>*>,
                                          dummyObjCCreator,
                                          RTProxiedNSArray_NSString_create,
                                          dummyWRLCreator,
                                          ConvertToVectorView<NSString, HSTRING>>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSDictionary_NSString_WMSVoiceCommandSet_create(IInspectable* val) {
    std::unique_ptr<DictionaryAdapter> adapter = std::make_unique<DictionaryAdapterObj<
        IMapView<HSTRING, ABI::Windows::Media::SpeechRecognition::VoiceCommandSet*>,
        DictionaryKeyEnumeratorAdapterObj<
            RTMapViewKeyEnumerator<HSTRING, HSTRING, NSString, ABI::Windows::Media::SpeechRecognition::VoiceCommandSet*>>,
        RTMapViewObj<HSTRING,
                     HSTRING,
                     ABI::Windows::Media::SpeechRecognition::VoiceCommandSet*,
                     ABI::Windows::Media::SpeechRecognition::IVoiceCommandSet*,
                     NSString,
                     WMSVoiceCommandSet,
                     IMapView<HSTRING, ABI::Windows::Media::SpeechRecognition::VoiceCommandSet*>,
                     dummyObjCCreator,
                     dummyObjCCreator,
                     dummyWRLCreator,
                     dummyWRLCreator>>>(val);
    return [[[RTProxiedNSDictionary alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_NSString_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<HSTRING>,
                               RTMutableArrayObj<HSTRING, IVector<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WMSISpeechRecognitionConstraint_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter = std::make_unique<
        MutableArrayAdapterObj<IVector<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint*>,
                               RTMutableArrayObj<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint*,
                                                 IVector<ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint*>,
                                                 RTObject<WMSISpeechRecognitionConstraint>,
                                                 ABI::Windows::Media::SpeechRecognition::ISpeechRecognitionConstraint*,
                                                 dummyObjCCreator,
                                                 dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
