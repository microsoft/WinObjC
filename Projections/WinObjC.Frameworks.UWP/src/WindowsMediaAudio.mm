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

// WindowsMediaAudio.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Audio.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaAudio.h"
#include "WindowsMediaAudio_priv.h"

@implementation WMAIAudioNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMAIAudioNodeWithListener

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeWithListener> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setListener:(WMAAudioNodeListener*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeWithListener>(self);
    THROW_NS_IF_FAILED(_comInst->put_Listener(_getRtInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(value).Get()));
}

- (WMAAudioNodeListener*)listener {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeListener> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeWithListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_Listener(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeListener>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

@end

@implementation WMAIAudioInputNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioInputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WMAAudioGraphConnection* */)outgoingConnections {
    ComPtr<IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingConnections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMAAudioGraphConnection_create(unmarshalledReturn.Get());
}

- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->AddOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOutgoingConnectionWithGain(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get(), gain));
}

- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMAIAudioInputNode2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioInputNode2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAAudioNodeEmitter*)emitter {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emitter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitter>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSArray* /* WMAAudioGraphConnection* */)outgoingConnections {
    ComPtr<IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingConnections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMAAudioGraphConnection_create(unmarshalledReturn.Get());
}

- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->AddOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOutgoingConnectionWithGain(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get(), gain));
}

- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

@end

@implementation WMAAudioGraph

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraph> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Audio::IAudioGraphStatics> WMAIAudioGraphStatics_inst() {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraphStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.AudioGraph").Get(), &inst));
    return inst;
}

+ (void)createAsync:(WMAAudioGraphSettings*)settings
            success:(void (^)(WMACreateAudioGraphResult*))success
            failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioGraphResult*>> unmarshalledReturn;
    auto _comInst = WMAIAudioGraphStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateAsync(_getRtInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(settings).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioGraphResult*>,
        FtmBase>>([successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioGraphResult*>* op,
                                         AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Audio::ICreateAudioGraphResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMACreateAudioGraphResult>(result.Get()));
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

- (WMAAudioFrameInputNode*)createFrameInputNode {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFrameInputNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioFrameInputNode>(unmarshalledReturn.Get());
}

- (WMAAudioFrameInputNode*)createFrameInputNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFrameInputNodeWithFormat(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioFrameInputNode>(unmarshalledReturn.Get());
}

- (void)createDeviceInputNodeAsync:(WMCMediaCategory)category
                           success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success
                           failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDeviceInputNodeAsync((ABI::Windows::Media::Capture::MediaCategory)category, &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioDeviceInputNodeResult>(result.Get()));
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

- (void)createDeviceInputNodeWithFormatAsync:(WMCMediaCategory)category
                          encodingProperties:(WMMAudioEncodingProperties*)encodingProperties
                                     success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success
                                     failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDeviceInputNodeWithFormatAsync(
        (ABI::Windows::Media::Capture::MediaCategory)category,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioDeviceInputNodeResult>(result.Get()));
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

- (void)createDeviceInputNodeWithFormatOnDeviceAsync:(WMCMediaCategory)category
                                  encodingProperties:(WMMAudioEncodingProperties*)encodingProperties
                                              device:(WDEDeviceInformation*)device
                                             success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success
                                             failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDeviceInputNodeWithFormatOnDeviceAsync(
        (ABI::Windows::Media::Capture::MediaCategory)category,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        _getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(device).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioDeviceInputNodeResult>(result.Get()));
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

- (WMAAudioFrameOutputNode*)createFrameOutputNode {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameOutputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFrameOutputNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioFrameOutputNode>(unmarshalledReturn.Get());
}

- (WMAAudioFrameOutputNode*)createFrameOutputNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameOutputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFrameOutputNodeWithFormat(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioFrameOutputNode>(unmarshalledReturn.Get());
}

- (void)createDeviceOutputNodeAsyncWithSuccess:(void (^)(WMACreateAudioDeviceOutputNodeResult*))success
                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceOutputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDeviceOutputNodeAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioDeviceOutputNodeResult*>,
        FtmBase>>([successRc,
                   failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceOutputNodeResult*>* op,
                              AsyncStatus status) {
        @autoreleasepool {
            if (!_handleAsyncErrorCode(op, failureRc)) {
                return S_OK;
            }
            if (status == AsyncStatus::Completed) {
                ComPtr<ABI::Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult> result;
                HRESULT hr = op->GetResults(result.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    if (successRc) {
                        successRc(_createRtProxy<WMACreateAudioDeviceOutputNodeResult>(result.Get()));
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

- (void)createFileInputNodeAsync:(RTObject<WSIStorageFile>*)file
                         success:(void (^)(WMACreateAudioFileInputNodeResult*))success
                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileInputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateFileInputNodeAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioFileInputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileInputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioFileInputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioFileInputNodeResult>(result.Get()));
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

- (void)createFileOutputNodeAsync:(RTObject<WSIStorageFile>*)file
                          success:(void (^)(WMACreateAudioFileOutputNodeResult*))success
                          failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileOutputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateFileOutputNodeAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(), &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioFileOutputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileOutputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioFileOutputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioFileOutputNodeResult>(result.Get()));
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

- (void)createFileOutputNodeWithFileProfileAsync:(RTObject<WSIStorageFile>*)file
                             fileEncodingProfile:(WMMMediaEncodingProfile*)fileEncodingProfile
                                         success:(void (^)(WMACreateAudioFileOutputNodeResult*))success
                                         failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileOutputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFileOutputNodeWithFileProfileAsync(
        _getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
        _getRtInterface<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile>(fileEncodingProfile).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioFileOutputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileOutputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioFileOutputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioFileOutputNodeResult>(result.Get()));
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

- (WMAAudioSubmixNode*)createSubmixNode {
    ComPtr<ABI::Windows::Media::Audio::IAudioInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateSubmixNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioSubmixNode>(unmarshalledReturn.Get());
}

- (WMAAudioSubmixNode*)createSubmixNodeWithFormat:(WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::Audio::IAudioInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->CreateSubmixNodeWithFormat(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioSubmixNode>(unmarshalledReturn.Get());
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)resetAllNodes {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->ResetAllNodes());
}

- (EventRegistrationToken)addQuantumStartedEvent:(void (^)(WMAAudioGraph*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->add_QuantumStarted(Make<ITypedEventHandler_Windows_Media_Audio_AudioGraph_System_Object>(handler).Get(),
                                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeQuantumStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->remove_QuantumStarted(token));
}

- (EventRegistrationToken)addQuantumProcessedEvent:(void (^)(WMAAudioGraph*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->add_QuantumProcessed(Make<ITypedEventHandler_Windows_Media_Audio_AudioGraph_System_Object>(handler).Get(),
                                                      &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeQuantumProcessedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->remove_QuantumProcessed(token));
}

- (EventRegistrationToken)addUnrecoverableErrorOccurredEvent:(void (^)(WMAAudioGraph*,
                                                                       WMAAudioGraphUnrecoverableErrorOccurredEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->add_UnrecoverableErrorOccurred(
        Make<ITypedEventHandler_Windows_Media_Audio_AudioGraph_Windows_Media_Audio_AudioGraphUnrecoverableErrorOccurredEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUnrecoverableErrorOccurredEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->remove_UnrecoverableErrorOccurred(token));
}

- (uint64_t)completedQuantumCount {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompletedQuantumCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (int)latencyInSamples {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_LatencyInSamples(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WDEDeviceInformation*)primaryRenderDevice {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrimaryRenderDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (WMAudioProcessing)renderDeviceAudioProcessing {
    ABI::Windows::Media::AudioProcessing unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_RenderDeviceAudioProcessing(&unmarshalledReturn));
    return (WMAudioProcessing)unmarshalledReturn;
}

- (int)samplesPerQuantum {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph>(self);
    THROW_NS_IF_FAILED(_comInst->get_SamplesPerQuantum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WMAAudioFrameInputNode*)createFrameInputNodeWithFormatAndEmitter:(WMMAudioEncodingProperties*)encodingProperties
                                                            emitter:(WMAAudioNodeEmitter*)emitter {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateFrameInputNodeWithFormatAndEmitter(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        _getRtInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(emitter).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioFrameInputNode>(unmarshalledReturn.Get());
}

- (void)createDeviceInputNodeWithFormatAndEmitterOnDeviceAsync:(WMCMediaCategory)category
                                            encodingProperties:(WMMAudioEncodingProperties*)encodingProperties
                                                        device:(WDEDeviceInformation*)device
                                                       emitter:(WMAAudioNodeEmitter*)emitter
                                                       success:(void (^)(WMACreateAudioDeviceInputNodeResult*))success
                                                       failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDeviceInputNodeWithFormatAndEmitterOnDeviceAsync(
        (ABI::Windows::Media::Capture::MediaCategory)category,
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        _getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(device).Get(),
        _getRtInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(emitter).Get(),
        &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioDeviceInputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioDeviceInputNodeResult>(result.Get()));
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

- (void)createFileInputNodeWithEmitterAsync:(RTObject<WSIStorageFile>*)file
                                    emitter:(WMAAudioNodeEmitter*)emitter
                                    success:(void (^)(WMACreateAudioFileInputNodeResult*))success
                                    failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileInputNodeResult*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph2>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateFileInputNodeWithEmitterAsync(_getRtInterface<ABI::Windows::Storage::IStorageFile>(file).Get(),
                                                      _getRtInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(emitter).Get(),
                                                      &unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Audio::CreateAudioFileInputNodeResult*>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Audio::CreateAudioFileInputNodeResult*>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ComPtr<ABI::Windows::Media::Audio::ICreateAudioFileInputNodeResult> result;
                    HRESULT hr = op->GetResults(result.GetAddressOf());
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc(_createRtProxy<WMACreateAudioFileInputNodeResult>(result.Get()));
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

- (WMAAudioSubmixNode*)createSubmixNodeWithFormatAndEmitter:(WMMAudioEncodingProperties*)encodingProperties
                                                    emitter:(WMAAudioNodeEmitter*)emitter {
    ComPtr<ABI::Windows::Media::Audio::IAudioInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateSubmixNodeWithFormatAndEmitter(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get(),
        _getRtInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(emitter).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioSubmixNode>(unmarshalledReturn.Get());
}

- (WMAAudioGraphBatchUpdater*)createBatchUpdater {
    ComPtr<ABI::Windows::Foundation::IClosable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraph2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateBatchUpdater(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioGraphBatchUpdater>(unmarshalledReturn.Get());
}

@end

@implementation WMACreateAudioGraphResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::ICreateAudioGraphResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAAudioGraphCreationStatus)status {
    ABI::Windows::Media::Audio::AudioGraphCreationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioGraphResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMAAudioGraphCreationStatus)unmarshalledReturn;
}

- (WMAAudioGraph*)graph {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraph> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioGraphResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Graph(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioGraph>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioGraphSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraphSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Audio::IAudioGraphSettingsFactory> WMAIAudioGraphSettingsFactory_inst() {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraphSettingsFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.AudioGraphSettings").Get(), &inst));
    return inst;
}

+ (WMAAudioGraphSettings*)make:(WMRAudioRenderCategory)audioRenderCategory {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraphSettings> unmarshalledReturn;
    auto _comInst = WMAIAudioGraphSettingsFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create((ABI::Windows::Media::Render::AudioRenderCategory)audioRenderCategory, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMAAudioGraphSettings>(unmarshalledReturn.Get()) retain];
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (void)setEncodingProperties:(WMMAudioEncodingProperties*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_EncodingProperties(_getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(value).Get()));
}

- (WDEDeviceInformation*)primaryRenderDevice {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_PrimaryRenderDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (void)setPrimaryRenderDevice:(WDEDeviceInformation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_PrimaryRenderDevice(_getRtInterface<ABI::Windows::Devices::Enumeration::IDeviceInformation>(value).Get()));
}

- (WMAQuantumSizeSelectionMode)quantumSizeSelectionMode {
    ABI::Windows::Media::Audio::QuantumSizeSelectionMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_QuantumSizeSelectionMode(&unmarshalledReturn));
    return (WMAQuantumSizeSelectionMode)unmarshalledReturn;
}

- (void)setQuantumSizeSelectionMode:(WMAQuantumSizeSelectionMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_QuantumSizeSelectionMode((ABI::Windows::Media::Audio::QuantumSizeSelectionMode)value));
}

- (int)desiredSamplesPerQuantum {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredSamplesPerQuantum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDesiredSamplesPerQuantum:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredSamplesPerQuantum(value));
}

- (WMRAudioRenderCategory)audioRenderCategory {
    ABI::Windows::Media::Render::AudioRenderCategory unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioRenderCategory(&unmarshalledReturn));
    return (WMRAudioRenderCategory)unmarshalledReturn;
}

- (void)setAudioRenderCategory:(WMRAudioRenderCategory)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_AudioRenderCategory((ABI::Windows::Media::Render::AudioRenderCategory)value));
}

- (WMAudioProcessing)desiredRenderDeviceAudioProcessing {
    ABI::Windows::Media::AudioProcessing unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DesiredRenderDeviceAudioProcessing(&unmarshalledReturn));
    return (WMAudioProcessing)unmarshalledReturn;
}

- (void)setDesiredRenderDeviceAudioProcessing:(WMAudioProcessing)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphSettings>(self);
    THROW_NS_IF_FAILED(_comInst->put_DesiredRenderDeviceAudioProcessing((ABI::Windows::Media::AudioProcessing)value));
}

@end

@implementation WMAAudioDeviceInputNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioDeviceInputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)device {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioDeviceInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (NSArray* /* WMAAudioGraphConnection* */)outgoingConnections {
    ComPtr<IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingConnections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMAAudioGraphConnection_create(unmarshalledReturn.Get());
}

- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->AddOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOutgoingConnectionWithGain(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get(), gain));
}

- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WMAAudioNodeEmitter*)emitter {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emitter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitter>(unmarshalledReturn.Get());
}

@end

@implementation WMACreateAudioDeviceInputNodeResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAAudioDeviceNodeCreationStatus)status {
    ABI::Windows::Media::Audio::AudioDeviceNodeCreationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMAAudioDeviceNodeCreationStatus)unmarshalledReturn;
}

- (WMAAudioDeviceInputNode*)deviceInputNode {
    ComPtr<ABI::Windows::Media::Audio::IAudioDeviceInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioDeviceInputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceInputNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioDeviceInputNode>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioDeviceOutputNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioDeviceOutputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WDEDeviceInformation*)device {
    ComPtr<ABI::Windows::Devices::Enumeration::IDeviceInformation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioDeviceOutputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Device(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WDEDeviceInformation>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)setListener:(WMAAudioNodeListener*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeWithListener>(self);
    THROW_NS_IF_FAILED(_comInst->put_Listener(_getRtInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(value).Get()));
}

- (WMAAudioNodeListener*)listener {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeListener> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeWithListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_Listener(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeListener>(unmarshalledReturn.Get());
}

@end

@implementation WMACreateAudioDeviceOutputNodeResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAAudioDeviceNodeCreationStatus)status {
    ABI::Windows::Media::Audio::AudioDeviceNodeCreationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMAAudioDeviceNodeCreationStatus)unmarshalledReturn;
}

- (WMAAudioDeviceOutputNode*)deviceOutputNode {
    ComPtr<ABI::Windows::Media::Audio::IAudioDeviceOutputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioDeviceOutputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_DeviceOutputNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioDeviceOutputNode>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioFileInputNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioFileInputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setPlaybackSpeedFactor:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaybackSpeedFactor(value));
}

- (double)playbackSpeedFactor {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackSpeedFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)position {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)seek:(WFTimeSpan*)position {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->Seek(*[position internalStruct]));
}

- (id /* WFTimeSpan* */)startTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_StartTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setStartTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_StartTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* WFTimeSpan* */)endTime {
    ComPtr<IReference<ABI::Windows::Foundation::TimeSpan>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EndTime(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<WFTimeSpan, ABI::Windows::Foundation::TimeSpan>::convert(unmarshalledReturn.Get());
}

- (void)setEndTime:(id /* WFTimeSpan* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_EndTime(BuildNullable<ABI::Windows::Foundation::TimeSpan>(value)));
}

- (id /* int */)loopCount {
    ComPtr<IReference<int>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_LoopCount(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<int, int>::convert(unmarshalledReturn.Get());
}

- (void)setLoopCount:(id /* int */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_LoopCount(BuildNullable<int>(value)));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WSStorageFile*)sourceFile {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_SourceFile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSStorageFile>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addFileCompletedEvent:(void (^)(WMAAudioFileInputNode*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->add_FileCompleted(Make<ITypedEventHandler_Windows_Media_Audio_AudioFileInputNode_System_Object>(handler).Get(),
                                    &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeFileCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->remove_FileCompleted(token));
}

- (NSArray* /* WMAAudioGraphConnection* */)outgoingConnections {
    ComPtr<IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingConnections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMAAudioGraphConnection_create(unmarshalledReturn.Get());
}

- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->AddOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOutgoingConnectionWithGain(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get(), gain));
}

- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WMAAudioNodeEmitter*)emitter {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emitter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitter>(unmarshalledReturn.Get());
}

@end

@implementation WMACreateAudioFileInputNodeResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::ICreateAudioFileInputNodeResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAAudioFileNodeCreationStatus)status {
    ABI::Windows::Media::Audio::AudioFileNodeCreationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioFileInputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMAAudioFileNodeCreationStatus)unmarshalledReturn;
}

- (WMAAudioFileInputNode*)fileInputNode {
    ComPtr<ABI::Windows::Media::Audio::IAudioFileInputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioFileInputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileInputNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioFileInputNode>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioFileOutputNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioFileOutputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WSIStorageFile>*)file {
    ComPtr<ABI::Windows::Storage::IStorageFile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileOutputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_File(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSIStorageFile>(unmarshalledReturn.Get());
}

- (WMMMediaEncodingProfile*)fileEncodingProfile {
    ComPtr<ABI::Windows::Media::MediaProperties::IMediaEncodingProfile> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileOutputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileEncodingProfile(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMMediaEncodingProfile>(unmarshalledReturn.Get());
}

- (void)finalizeAsyncWithSuccess:(void (^)(WMTTranscodeFailureReason))success failure:(void (^)(NSError*))failure {
    ComPtr<ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::TranscodeFailureReason>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFileOutputNode>(self);
    THROW_NS_IF_FAILED(_comInst->FinalizeAsync(&unmarshalledReturn));

    auto successRc = makeBlockHolder(success);
    auto failureRc = makeBlockHolder(failure);
    auto completionHandler = ::Microsoft::WRL::Callback<::Microsoft::WRL::Implements<
        ::Microsoft::WRL::RuntimeClassFlags<::Microsoft::WRL::WinRtClassicComMix>,
        ABI::Windows::Foundation::IAsyncOperationCompletedHandler<ABI::Windows::Media::Transcoding::TranscodeFailureReason>,
        FtmBase>>(
        [successRc, failureRc](ABI::Windows::Foundation::IAsyncOperation<ABI::Windows::Media::Transcoding::TranscodeFailureReason>* op,
                               AsyncStatus status) {
            @autoreleasepool {
                if (!_handleAsyncErrorCode(op, failureRc)) {
                    return S_OK;
                }
                if (status == AsyncStatus::Completed) {
                    ABI::Windows::Media::Transcoding::TranscodeFailureReason result;
                    HRESULT hr = op->GetResults(&result);
                    if (SUCCEEDED(hr)) {
                        if (successRc) {
                            successRc((WMTTranscodeFailureReason)result);
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

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMACreateAudioFileOutputNodeResult

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::ICreateAudioFileOutputNodeResult> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAAudioFileNodeCreationStatus)status {
    ABI::Windows::Media::Audio::AudioFileNodeCreationStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioFileOutputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_Status(&unmarshalledReturn));
    return (WMAAudioFileNodeCreationStatus)unmarshalledReturn;
}

- (WMAAudioFileOutputNode*)fileOutputNode {
    ComPtr<ABI::Windows::Media::Audio::IAudioFileOutputNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ICreateAudioFileOutputNodeResult>(self);
    THROW_NS_IF_FAILED(_comInst->get_FileOutputNode(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioFileOutputNode>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioGraphUnrecoverableErrorOccurredEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAAudioGraphUnrecoverableError)error {
    ABI::Windows::Media::Audio::AudioGraphUnrecoverableError unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphUnrecoverableErrorOccurredEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Error(&unmarshalledReturn));
    return (WMAAudioGraphUnrecoverableError)unmarshalledReturn;
}

@end

@implementation WMAAudioGraphBatchUpdater

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Foundation::IClosable> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMAAudioFrameInputNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameInputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)setPlaybackSpeedFactor:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaybackSpeedFactor(value));
}

- (double)playbackSpeedFactor {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaybackSpeedFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)addFrame:(WMAudioFrame*)frame {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->AddFrame(_getRtInterface<ABI::Windows::Media::IAudioFrame>(frame).Get()));
}

- (void)discardQueuedFrames {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->DiscardQueuedFrames());
}

- (uint64_t)queuedSampleCount {
    uint64_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_QueuedSampleCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (EventRegistrationToken)addAudioFrameCompletedEvent:(void (^)(WMAAudioFrameInputNode*, WMAAudioFrameCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->add_AudioFrameCompleted(
        Make<ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_AudioFrameCompletedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAudioFrameCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AudioFrameCompleted(token));
}

- (EventRegistrationToken)addQuantumStartedEvent:(void (^)(WMAAudioFrameInputNode*, WMAFrameInputNodeQuantumStartedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->add_QuantumStarted(
        Make<ITypedEventHandler_Windows_Media_Audio_AudioFrameInputNode_Windows_Media_Audio_FrameInputNodeQuantumStartedEventArgs>(handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeQuantumStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->remove_QuantumStarted(token));
}

- (NSArray* /* WMAAudioGraphConnection* */)outgoingConnections {
    ComPtr<IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingConnections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMAAudioGraphConnection_create(unmarshalledReturn.Get());
}

- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->AddOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOutgoingConnectionWithGain(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get(), gain));
}

- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WMAAudioNodeEmitter*)emitter {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emitter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitter>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioFrameOutputNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameOutputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAudioFrame*)getFrame {
    ComPtr<ABI::Windows::Media::IAudioFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameOutputNode>(self);
    THROW_NS_IF_FAILED(_comInst->GetFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAudioFrame>(unmarshalledReturn.Get());
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

@end

@implementation WMAAudioSubmixNode

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioInputNode> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WMAAudioGraphConnection* */)outgoingConnections {
    ComPtr<IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingConnections(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMAAudioGraphConnection_create(unmarshalledReturn.Get());
}

- (void)addOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->AddOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (void)addOutgoingConnectionWithGain:(RTObject<WMAIAudioNode>*)destination gain:(double)gain {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->AddOutgoingConnectionWithGain(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get(), gain));
}

- (void)removeOutgoingConnection:(RTObject<WMAIAudioNode>*)destination {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveOutgoingConnection(_getRtInterface<ABI::Windows::Media::Audio::IAudioNode>(destination).Get()));
}

- (NSMutableArray* /* RTObject<WMEIAudioEffectDefinition>* */)effectDefinitions {
    ComPtr<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectDefinitions(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(unmarshalledReturn.Get());
}

- (void)setOutgoingGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutgoingGain(value));
}

- (double)outgoingGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutgoingGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMMAudioEncodingProperties*)encodingProperties {
    ComPtr<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_EncodingProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMMAudioEncodingProperties>(unmarshalledReturn.Get());
}

- (BOOL)consumeInput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConsumeInput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setConsumeInput:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConsumeInput((boolean)value));
}

- (void)start {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Start());
}

- (void)stop {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Stop());
}

- (void)reset {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(_comInst->Reset());
}

- (void)disableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->DisableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)enableEffectsByDefinition:(RTObject<WMEIAudioEffectDefinition>*)definition {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNode>(self);
    THROW_NS_IF_FAILED(
        _comInst->EnableEffectsByDefinition(_getRtInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(definition).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WMAAudioNodeEmitter*)emitter {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitter> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioInputNode2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Emitter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitter>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioNodeEmitter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterFactory> WMAIAudioNodeEmitterFactory_inst() {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.AudioNodeEmitter").Get(), &inst));
    return inst;
}

+ (WMAAudioNodeEmitter*)makeAudioNodeEmitter:(WMAAudioNodeEmitterShape*)shape
                                  decayModel:(WMAAudioNodeEmitterDecayModel*)decayModel
                                    settings:(WMAAudioNodeEmitterSettings)settings {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitter> unmarshalledReturn;
    auto _comInst = WMAIAudioNodeEmitterFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateAudioNodeEmitter(_getRtInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterShape>(shape).Get(),
                                         _getRtInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel>(decayModel).Get(),
                                         (ABI::Windows::Media::Audio::AudioNodeEmitterSettings)settings,
                                         unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMAAudioNodeEmitter>(unmarshalledReturn.Get()) retain];
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Audio.AudioNodeEmitter").Get(), &out));
    return [_createRtProxy<WMAAudioNodeEmitter>(out.Get()) retain];
}

- (WFNVector3*)position {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setPosition:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (WFNVector3*)direction {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direction(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setDirection:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Direction(*[value internalStruct]));
}

- (WMAAudioNodeEmitterShape*)shape {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterShape> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Shape(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterShape>(unmarshalledReturn.Get());
}

- (WMAAudioNodeEmitterDecayModel*)decayModel {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecayModel(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterDecayModel>(unmarshalledReturn.Get());
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

- (double)distanceScale {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DistanceScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDistanceScale:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DistanceScale(value));
}

- (double)dopplerScale {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DopplerScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDopplerScale:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DopplerScale(value));
}

- (WFNVector3*)dopplerVelocity {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DopplerVelocity(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setDopplerVelocity:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DopplerVelocity(*[value internalStruct]));
}

- (BOOL)isDopplerDisabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDopplerDisabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WMASpatialAudioModel)spatialAudioModel {
    ABI::Windows::Media::Audio::SpatialAudioModel unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpatialAudioModel(&unmarshalledReturn));
    return (WMASpatialAudioModel)unmarshalledReturn;
}

- (void)setSpatialAudioModel:(WMASpatialAudioModel)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpatialAudioModel((ABI::Windows::Media::Audio::SpatialAudioModel)value));
}

@end

@implementation WMAAudioNodeListener

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeListener> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Audio.AudioNodeListener").Get(), &out));
    return [_createRtProxy<WMAAudioNodeListener>(out.Get()) retain];
}

- (WFNVector3*)position {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setPosition:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->put_Position(*[value internalStruct]));
}

- (WFNQuaternion*)orientation {
    ABI::Windows::Foundation::Numerics::Quaternion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return WFNQuaternion_create(unmarshalledReturn);
}

- (void)setOrientation:(WFNQuaternion*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->put_Orientation(*[value internalStruct]));
}

- (double)speedOfSound {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpeedOfSound(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpeedOfSound:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpeedOfSound(value));
}

- (WFNVector3*)dopplerVelocity {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->get_DopplerVelocity(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setDopplerVelocity:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeListener>(self);
    THROW_NS_IF_FAILED(_comInst->put_DopplerVelocity(*[value internalStruct]));
}

@end

@implementation WMAAudioGraphConnection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioGraphConnection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WMAIAudioNode>*)destination {
    ComPtr<ABI::Windows::Media::Audio::IAudioNode> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphConnection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Destination(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAIAudioNode>(unmarshalledReturn.Get());
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphConnection>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioGraphConnection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMAAudioFrameCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioFrameCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAudioFrame*)frame {
    ComPtr<ABI::Windows::Media::IAudioFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioFrameCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Frame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAudioFrame>(unmarshalledReturn.Get());
}

@end

@implementation WMAFrameInputNodeQuantumStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)requiredSamples {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IFrameInputNodeQuantumStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_RequiredSamples(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMAEqualizerBand

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IEqualizerBand> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)bandwidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEqualizerBand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bandwidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBandwidth:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEqualizerBand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Bandwidth(value));
}

- (double)frequencyCenter {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEqualizerBand>(self);
    THROW_NS_IF_FAILED(_comInst->get_FrequencyCenter(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFrequencyCenter:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEqualizerBand>(self);
    THROW_NS_IF_FAILED(_comInst->put_FrequencyCenter(value));
}

- (double)gain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEqualizerBand>(self);
    THROW_NS_IF_FAILED(_comInst->get_Gain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEqualizerBand>(self);
    THROW_NS_IF_FAILED(_comInst->put_Gain(value));
}

@end

@implementation WMAEqualizerEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IEqualizerEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Audio::IEqualizerEffectDefinitionFactory> WMAIEqualizerEffectDefinitionFactory_inst() {
    ComPtr<ABI::Windows::Media::Audio::IEqualizerEffectDefinitionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.EqualizerEffectDefinition").Get(),
                                                       &inst));
    return inst;
}

+ (WMAEqualizerEffectDefinition*)make:(WMAAudioGraph*)audioGraph {
    ComPtr<ABI::Windows::Media::Audio::IEqualizerEffectDefinition> unmarshalledReturn;
    auto _comInst = WMAIEqualizerEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::Audio::IAudioGraph>(audioGraph).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMAEqualizerEffectDefinition>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* WMAEqualizerBand* */)bands {
    ComPtr<IVectorView<ABI::Windows::Media::Audio::EqualizerBand*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEqualizerEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Bands(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMAEqualizerBand_create(unmarshalledReturn.Get());
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMAReverbEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IReverbEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Audio::IReverbEffectDefinitionFactory> WMAIReverbEffectDefinitionFactory_inst() {
    ComPtr<ABI::Windows::Media::Audio::IReverbEffectDefinitionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.ReverbEffectDefinition").Get(), &inst));
    return inst;
}

+ (WMAReverbEffectDefinition*)make:(WMAAudioGraph*)audioGraph {
    ComPtr<ABI::Windows::Media::Audio::IReverbEffectDefinition> unmarshalledReturn;
    auto _comInst = WMAIReverbEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::Audio::IAudioGraph>(audioGraph).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMAReverbEffectDefinition>(unmarshalledReturn.Get()) retain];
}

- (void)setWetDryMix:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_WetDryMix(value));
}

- (double)wetDryMix {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_WetDryMix(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReflectionsDelay:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReflectionsDelay(value));
}

- (unsigned int)reflectionsDelay {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReflectionsDelay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReverbDelay:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReverbDelay(value));
}

- (uint8_t)reverbDelay {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReverbDelay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRearDelay:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_RearDelay(value));
}

- (uint8_t)rearDelay {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_RearDelay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPositionLeft:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionLeft(value));
}

- (uint8_t)positionLeft {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionLeft(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPositionRight:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionRight(value));
}

- (uint8_t)positionRight {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionRight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPositionMatrixLeft:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionMatrixLeft(value));
}

- (uint8_t)positionMatrixLeft {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionMatrixLeft(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setPositionMatrixRight:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_PositionMatrixRight(value));
}

- (uint8_t)positionMatrixRight {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_PositionMatrixRight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setEarlyDiffusion:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_EarlyDiffusion(value));
}

- (uint8_t)earlyDiffusion {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_EarlyDiffusion(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLateDiffusion:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_LateDiffusion(value));
}

- (uint8_t)lateDiffusion {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_LateDiffusion(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLowEQGain:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_LowEQGain(value));
}

- (uint8_t)lowEQGain {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_LowEQGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLowEQCutoff:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_LowEQCutoff(value));
}

- (uint8_t)lowEQCutoff {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_LowEQCutoff(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHighEQGain:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_HighEQGain(value));
}

- (uint8_t)highEQGain {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_HighEQGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHighEQCutoff:(uint8_t)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_HighEQCutoff(value));
}

- (uint8_t)highEQCutoff {
    uint8_t unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_HighEQCutoff(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRoomFilterFreq:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoomFilterFreq(value));
}

- (double)roomFilterFreq {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoomFilterFreq(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRoomFilterMain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoomFilterMain(value));
}

- (double)roomFilterMain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoomFilterMain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRoomFilterHF:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoomFilterHF(value));
}

- (double)roomFilterHF {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoomFilterHF(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReflectionsGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReflectionsGain(value));
}

- (double)reflectionsGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReflectionsGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReverbGain:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReverbGain(value));
}

- (double)reverbGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReverbGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDecayTime:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_DecayTime(value));
}

- (double)decayTime {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_DecayTime(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDensity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Density(value));
}

- (double)density {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Density(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRoomSize:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_RoomSize(value));
}

- (double)roomSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_RoomSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDisableLateField:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisableLateField((boolean)value));
}

- (BOOL)disableLateField {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IReverbEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisableLateField(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMAEchoEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IEchoEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Audio::IEchoEffectDefinitionFactory> WMAIEchoEffectDefinitionFactory_inst() {
    ComPtr<ABI::Windows::Media::Audio::IEchoEffectDefinitionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.EchoEffectDefinition").Get(), &inst));
    return inst;
}

+ (WMAEchoEffectDefinition*)make:(WMAAudioGraph*)audioGraph {
    ComPtr<ABI::Windows::Media::Audio::IEchoEffectDefinition> unmarshalledReturn;
    auto _comInst = WMAIEchoEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::Audio::IAudioGraph>(audioGraph).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMAEchoEffectDefinition>(unmarshalledReturn.Get()) retain];
}

- (void)setWetDryMix:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEchoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_WetDryMix(value));
}

- (double)wetDryMix {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEchoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_WetDryMix(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFeedback:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEchoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Feedback(value));
}

- (double)feedback {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEchoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Feedback(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDelay:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEchoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Delay(value));
}

- (double)delay {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IEchoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMALimiterEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::ILimiterEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Audio::ILimiterEffectDefinitionFactory> WMAILimiterEffectDefinitionFactory_inst() {
    ComPtr<ABI::Windows::Media::Audio::ILimiterEffectDefinitionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.LimiterEffectDefinition").Get(),
                                                       &inst));
    return inst;
}

+ (WMALimiterEffectDefinition*)make:(WMAAudioGraph*)audioGraph {
    ComPtr<ABI::Windows::Media::Audio::ILimiterEffectDefinition> unmarshalledReturn;
    auto _comInst = WMAILimiterEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->Create(_getRtInterface<ABI::Windows::Media::Audio::IAudioGraph>(audioGraph).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMALimiterEffectDefinition>(unmarshalledReturn.Get()) retain];
}

- (void)setRelease:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ILimiterEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Release(value));
}

- (unsigned int)Release {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ILimiterEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Release(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLoudness:(unsigned int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ILimiterEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Loudness(value));
}

- (unsigned int)loudness {
    unsigned int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::ILimiterEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Loudness(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioNodeEmitterConeProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterConeProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)innerAngle {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterConeProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)outerAngle {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterConeProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_OuterAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)outerAngleGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterConeProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_OuterAngleGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMAAudioNodeEmitterShape

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterShape> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterShapeStatics> WMAIAudioNodeEmitterShapeStatics_inst() {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterShapeStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.AudioNodeEmitterShape").Get(), &inst));
    return inst;
}

+ (WMAAudioNodeEmitterShape*)createCone:(double)innerAngle outerAngle:(double)outerAngle outerAngleGain:(double)outerAngleGain {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterShape> unmarshalledReturn;
    auto _comInst = WMAIAudioNodeEmitterShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCone(innerAngle, outerAngle, outerAngleGain, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterShape>(unmarshalledReturn.Get());
}

+ (WMAAudioNodeEmitterShape*)createOmnidirectional {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterShape> unmarshalledReturn;
    auto _comInst = WMAIAudioNodeEmitterShapeStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateOmnidirectional(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterShape>(unmarshalledReturn.Get());
}

- (WMAAudioNodeEmitterShapeKind)kind {
    ABI::Windows::Media::Audio::AudioNodeEmitterShapeKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WMAAudioNodeEmitterShapeKind)unmarshalledReturn;
}

- (WMAAudioNodeEmitterConeProperties*)coneProperties {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterConeProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterShape>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConeProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterConeProperties>(unmarshalledReturn.Get());
}

@end

@implementation WMAAudioNodeEmitterNaturalDecayModelProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)unityGainDistance {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_UnityGainDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)cutoffDistance {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties>(self);
    THROW_NS_IF_FAILED(_comInst->get_CutoffDistance(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WMAAudioNodeEmitterDecayModel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModelStatics> WMAIAudioNodeEmitterDecayModelStatics_inst() {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModelStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Audio.AudioNodeEmitterDecayModel").Get(),
                                                       &inst));
    return inst;
}

+ (WMAAudioNodeEmitterDecayModel*)createNatural:(double)minGain
                                        maxGain:(double)maxGain
                              unityGainDistance:(double)unityGainDistance
                                 cutoffDistance:(double)cutoffDistance {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel> unmarshalledReturn;
    auto _comInst = WMAIAudioNodeEmitterDecayModelStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateNatural(minGain, maxGain, unityGainDistance, cutoffDistance, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterDecayModel>(unmarshalledReturn.Get());
}

+ (WMAAudioNodeEmitterDecayModel*)createCustom:(double)minGain maxGain:(double)maxGain {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel> unmarshalledReturn;
    auto _comInst = WMAIAudioNodeEmitterDecayModelStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateCustom(minGain, maxGain, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterDecayModel>(unmarshalledReturn.Get());
}

- (WMAAudioNodeEmitterDecayKind)kind {
    ABI::Windows::Media::Audio::AudioNodeEmitterDecayKind unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_Kind(&unmarshalledReturn));
    return (WMAAudioNodeEmitterDecayKind)unmarshalledReturn;
}

- (double)minGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maxGain {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxGain(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WMAAudioNodeEmitterNaturalDecayModelProperties*)naturalProperties {
    ComPtr<ABI::Windows::Media::Audio::IAudioNodeEmitterNaturalDecayModelProperties> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Audio::IAudioNodeEmitterDecayModel>(self);
    THROW_NS_IF_FAILED(_comInst->get_NaturalProperties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAAudioNodeEmitterNaturalDecayModelProperties>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_WMAAudioGraphConnection_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>,
                                         RTArrayObj<ABI::Windows::Media::Audio::IAudioGraphConnection*,
                                                    IVectorView<ABI::Windows::Media::Audio::AudioGraphConnection*>,
                                                    WMAAudioGraphConnection,
                                                    ABI::Windows::Media::Audio::AudioGraphConnection*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMAEqualizerBand_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Audio::EqualizerBand*>,
                                         RTArrayObj<ABI::Windows::Media::Audio::IEqualizerBand*,
                                                    IVectorView<ABI::Windows::Media::Audio::EqualizerBand*>,
                                                    WMAEqualizerBand,
                                                    ABI::Windows::Media::Audio::EqualizerBand*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_RTObject_WMEIAudioEffectDefinition_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>,
                                                RTMutableArrayObj<ABI::Windows::Media::Effects::IAudioEffectDefinition*,
                                                                  IVector<ABI::Windows::Media::Effects::IAudioEffectDefinition*>,
                                                                  RTObject<WMEIAudioEffectDefinition>,
                                                                  ABI::Windows::Media::Effects::IAudioEffectDefinition*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
