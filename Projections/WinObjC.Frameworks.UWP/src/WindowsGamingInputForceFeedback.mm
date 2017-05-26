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

// WindowsGamingInputForceFeedback.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Gaming.Input.ForceFeedback.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsGamingInputForceFeedback.h"
#include "WindowsGamingInputForceFeedback_priv.h"

@implementation WGIFIForceFeedbackEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

- (WGIFForceFeedbackEffectState)state {
    ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGIFForceFeedbackEffectState)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

@end

@implementation WGIFConditionForceEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IConditionForceEffectFactory> WGIFIConditionForceEffectFactory_inst() {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IConditionForceEffectFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Gaming.Input.ForceFeedback.ConditionForceEffect").Get(), &inst));
    return inst;
}

+ (WGIFConditionForceEffect*)makeInstance:(WGIFConditionForceEffectKind)effectKind {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> unmarshalledReturn;
    auto _comInst = WGIFIConditionForceEffectFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance((ABI::Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind)effectKind,
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGIFConditionForceEffect>(unmarshalledReturn.Get()) retain];
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

- (WGIFForceFeedbackEffectState)state {
    ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGIFForceFeedbackEffectState)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (WGIFConditionForceEffectKind)kind {
    ABI::Windows::Gaming::Input::ForceFeedback::ConditionForceEffectKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IConditionForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WGIFConditionForceEffectKind)unmarshalledReturn;
}

- (void)setParameters:(WFNVector3*)direction
     positiveCoefficient:(float)positiveCoefficient
     negativeCoefficient:(float)negativeCoefficient
    maxPositiveMagnitude:(float)maxPositiveMagnitude
    maxNegativeMagnitude:(float)maxNegativeMagnitude
                deadZone:(float)deadZone
                    bias:(float)bias {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IConditionForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetParameters(
        *[direction internalStruct], positiveCoefficient, negativeCoefficient, maxPositiveMagnitude, maxNegativeMagnitude, deadZone, bias));
}

@end

@implementation WGIFPeriodicForceEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory> WGIFIPeriodicForceEffectFactory_inst() {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffectFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.Gaming.Input.ForceFeedback.PeriodicForceEffect").Get(), &inst));
    return inst;
}

+ (WGIFPeriodicForceEffect*)makeInstance:(WGIFPeriodicForceEffectKind)effectKind {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> unmarshalledReturn;
    auto _comInst = WGIFIPeriodicForceEffectFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance((ABI::Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind)effectKind,
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WGIFPeriodicForceEffect>(unmarshalledReturn.Get()) retain];
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

- (WGIFForceFeedbackEffectState)state {
    ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGIFForceFeedbackEffectState)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (WGIFPeriodicForceEffectKind)kind {
    ABI::Windows::Gaming::Input::ForceFeedback::PeriodicForceEffectKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WGIFPeriodicForceEffectKind)unmarshalledReturn;
}

- (void)setParameters:(WFNVector3*)vector frequency:(float)frequency phase:(float)phase bias:(float)bias duration:(WFTimeSpan*)duration {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetParameters(*[vector internalStruct], frequency, phase, bias, *[duration internalStruct]));
}

- (void)setParametersWithEnvelope:(WFNVector3*)vector
                        frequency:(float)frequency
                            phase:(float)phase
                             bias:(float)bias
                       attackGain:(float)attackGain
                      sustainGain:(float)sustainGain
                      releaseGain:(float)releaseGain
                       startDelay:(WFTimeSpan*)startDelay
                   attackDuration:(WFTimeSpan*)attackDuration
                  sustainDuration:(WFTimeSpan*)sustainDuration
                  releaseDuration:(WFTimeSpan*)releaseDuration
                      repeatCount:(unsigned int)repeatCount {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IPeriodicForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetParametersWithEnvelope(*[vector internalStruct],
                                                           frequency,
                                                           phase,
                                                           bias,
                                                           attackGain,
                                                           sustainGain,
                                                           releaseGain,
                                                           *[startDelay internalStruct],
                                                           *[attackDuration internalStruct],
                                                           *[sustainDuration internalStruct],
                                                           *[releaseDuration internalStruct],
                                                           repeatCount));
}

@end

@implementation WGIFConstantForceEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Gaming.Input.ForceFeedback.ConstantForceEffect").Get(),
                                              &out));
    return [_createRtProxy<WGIFConstantForceEffect>(out.Get()) retain];
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

- (WGIFForceFeedbackEffectState)state {
    ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGIFForceFeedbackEffectState)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)setParameters:(WFNVector3*)vector duration:(WFTimeSpan*)duration {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IConstantForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetParameters(*[vector internalStruct], *[duration internalStruct]));
}

- (void)setParametersWithEnvelope:(WFNVector3*)vector
                       attackGain:(float)attackGain
                      sustainGain:(float)sustainGain
                      releaseGain:(float)releaseGain
                       startDelay:(WFTimeSpan*)startDelay
                   attackDuration:(WFTimeSpan*)attackDuration
                  sustainDuration:(WFTimeSpan*)sustainDuration
                  releaseDuration:(WFTimeSpan*)releaseDuration
                      repeatCount:(unsigned int)repeatCount {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IConstantForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetParametersWithEnvelope(*[vector internalStruct],
                                                           attackGain,
                                                           sustainGain,
                                                           releaseGain,
                                                           *[startDelay internalStruct],
                                                           *[attackDuration internalStruct],
                                                           *[sustainDuration internalStruct],
                                                           *[releaseDuration internalStruct],
                                                           repeatCount));
}

@end

@implementation WGIFRampForceEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Gaming.Input.ForceFeedback.RampForceEffect").Get(), &out));
    return [_createRtProxy<WGIFRampForceEffect>(out.Get()) retain];
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

- (WGIFForceFeedbackEffectState)state {
    ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_State(&unmarshalledReturn));
    return (WGIFForceFeedbackEffectState)unmarshalledReturn;
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)setParameters:(WFNVector3*)startVector endVector:(WFNVector3*)endVector duration:(WFTimeSpan*)duration {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IRampForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetParameters(*[startVector internalStruct], *[endVector internalStruct], *[duration internalStruct]));
}

- (void)setParametersWithEnvelope:(WFNVector3*)startVector
                        endVector:(WFNVector3*)endVector
                       attackGain:(float)attackGain
                      sustainGain:(float)sustainGain
                      releaseGain:(float)releaseGain
                       startDelay:(WFTimeSpan*)startDelay
                   attackDuration:(WFTimeSpan*)attackDuration
                  sustainDuration:(WFTimeSpan*)sustainDuration
                  releaseDuration:(WFTimeSpan*)releaseDuration
                      repeatCount:(unsigned int)repeatCount {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IRampForceEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetParametersWithEnvelope(*[startVector internalStruct],
                                                           *[endVector internalStruct],
                                                           attackGain,
                                                           sustainGain,
                                                           releaseGain,
                                                           *[startDelay internalStruct],
                                                           *[attackDuration internalStruct],
                                                           *[sustainDuration internalStruct],
                                                           *[releaseDuration internalStruct],
                                                           repeatCount));
}

@end

@implementation WGIFForceFeedbackMotor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)areEffectsPaused {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreEffectsPaused(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)masterGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->get_MasterGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMasterGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->put_MasterGain(value));
}

- (BOOL)isEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WGIFForceFeedbackEffectAxes)supportedAxes {
    ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackEffectAxes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedAxes(&unmarshalledReturn));
    return (WGIFForceFeedbackEffectAxes)unmarshalledReturn;
}

- (void)loadEffectAsync:(RTObject<WGIFIForceFeedbackEffect>*)effect
                success:(void (^)(WGIFForceFeedbackLoadEffectResult))success
                failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult>>
        unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(
        _comInst->LoadEffectAsync(_getRtInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(effect).Get(),
                                  &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<
        ::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                     ABI::Windows::Foundation::IAsyncOperationCompletedHandler<
                                         ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult>,
                                     FtmBase>>([successRc, failureRc](
        ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult>* op,
        AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ABI::Windows::Gaming::Input::ForceFeedback::ForceFeedbackLoadEffectResult result;
                HRESULT hr = op->GetResults(&result);
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc((WGIFForceFeedbackLoadEffectResult)result);
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

- (void)pauseAllEffects {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->PauseAllEffects());
}

- (void)resumeAllEffects {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->ResumeAllEffects());
}

- (void)stopAllEffects {
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->StopAllEffects());
}

- (void)tryDisableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->TryDisableAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)tryEnableAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->TryEnableAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)tryResetAsyncWithSuccess:(void (^)(BOOL))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(_comInst->TryResetAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

- (void)tryUnloadEffectAsync:(RTObject<WGIFIForceFeedbackEffect>*)effect
                     success:(void (^)(BOOL))success
                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackMotor>(self);
    THROW_NS_IF_FAILED(
        _comInst->TryUnloadEffectAsync(_getRtInterface<ABI::Windows::Gaming::Input::ForceFeedback::IForceFeedbackEffect>(effect).Get(),
                                       &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler =
        ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
                                                                ABI::Windows::Foundation::IAsyncOperationCompletedHandler<bool>,
                                                                FtmBase>>(
            [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<bool>* op, AsyncStatus status) {
                @autoreleasepool {
                    if (!_handleAsyncErrorCode(op, failureRc)) {
                        return S_OK;
                    }
                    if (status == AsyncStatus::Completed) {
                        boolean result;
                        HRESULT hr = op->GetResults(&result);
                        if (SUCCEEDED(hr)) {
                            if (successRc) {
                                successRc((BOOL)result);
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

@end
