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

// WindowsMediaEffects.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.Media.Effects.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsMediaEffects.h"
#include "WindowsMediaEffects_priv.h"

@implementation WMEIVideoCompositorDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositorDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositorDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMEIVideoCompositor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoCompositor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)timeIndependent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositor>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeIndependent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setEncodingProperties:(WMMVideoEncodingProperties*)backgroundProperties device:(RTObject<WGDDIDirect3DDevice>*)device {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositor>(self);
    THROW_NS_IF_FAILED(_comInst->SetEncodingProperties(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(backgroundProperties).Get(),
        _getRtInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>(device).Get()));
}

- (void)compositeFrame:(WMECompositeVideoFrameContext*)context {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CompositeFrame(_getRtInterface<ABI::Windows::Media::Effects::ICompositeVideoFrameContext>(context).Get()));
}

- (void)close:(WMEMediaEffectClosedReason)reason {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositor>(self);
    THROW_NS_IF_FAILED(_comInst->Close((ABI::Windows::Media::Effects::MediaEffectClosedReason)reason));
}

- (void)discardQueuedFrames {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositor>(self);
    THROW_NS_IF_FAILED(_comInst->DiscardQueuedFrames());
}

- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtension>(self);
    THROW_NS_IF_FAILED(_comInst->SetProperties(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMEIAudioEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IAudioEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
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

@implementation WMEIVideoEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMEIBasicVideoEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IBasicVideoEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WMEMediaMemoryTypes)supportedMemoryTypes {
    ABI::Windows::Media::Effects::MediaMemoryTypes unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedMemoryTypes(&unmarshalledReturn));
    return (WMEMediaMemoryTypes)unmarshalledReturn;
}

- (BOOL)timeIndependent {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeIndependent(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMMVideoEncodingProperties* */)supportedEncodingProperties {
    ComPtr<IVectorView<ABI::Windows::Media::MediaProperties::VideoEncodingProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedEncodingProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMMVideoEncodingProperties_create(unmarshalledReturn.Get());
}

- (void)setEncodingProperties:(WMMVideoEncodingProperties*)encodingProperties device:(RTObject<WGDDIDirect3DDevice>*)device {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetEncodingProperties(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties>(encodingProperties).Get(),
        _getRtInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DDevice>(device).Get()));
}

- (void)processFrame:(WMEProcessVideoFrameContext*)context {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessFrame(_getRtInterface<ABI::Windows::Media::Effects::IProcessVideoFrameContext>(context).Get()));
}

- (void)close:(WMEMediaEffectClosedReason)reason {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Close((ABI::Windows::Media::Effects::MediaEffectClosedReason)reason));
}

- (void)discardQueuedFrames {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicVideoEffect>(self);
    THROW_NS_IF_FAILED(_comInst->DiscardQueuedFrames());
}

- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtension>(self);
    THROW_NS_IF_FAILED(_comInst->SetProperties(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMEIBasicAudioEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IBasicAudioEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)useInputFrameForOutput {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicAudioEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_UseInputFrameForOutput(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WMMAudioEncodingProperties* */)supportedEncodingProperties {
    ComPtr<IVectorView<ABI::Windows::Media::MediaProperties::AudioEncodingProperties*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicAudioEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedEncodingProperties(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMMAudioEncodingProperties_create(unmarshalledReturn.Get());
}

- (void)setEncodingProperties:(WMMAudioEncodingProperties*)encodingProperties {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicAudioEffect>(self);
    THROW_NS_IF_FAILED(_comInst->SetEncodingProperties(
        _getRtInterface<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties>(encodingProperties).Get()));
}

- (void)processFrame:(WMEProcessAudioFrameContext*)context {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicAudioEffect>(self);
    THROW_NS_IF_FAILED(_comInst->ProcessFrame(_getRtInterface<ABI::Windows::Media::Effects::IProcessAudioFrameContext>(context).Get()));
}

- (void)close:(WMEMediaEffectClosedReason)reason {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicAudioEffect>(self);
    THROW_NS_IF_FAILED(_comInst->Close((ABI::Windows::Media::Effects::MediaEffectClosedReason)reason));
}

- (void)discardQueuedFrames {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IBasicAudioEffect>(self);
    THROW_NS_IF_FAILED(_comInst->DiscardQueuedFrames());
}

- (void)setProperties:(RTObject<WFCIPropertySet>*)configuration {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::IMediaExtension>(self);
    THROW_NS_IF_FAILED(_comInst->SetProperties(_getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(configuration).Get()));
}

@end

@implementation WMEVideoCompositorDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinitionFactory> WMEIVideoCompositorDefinitionFactory_inst() {
    ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinitionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Effects.VideoCompositorDefinition").Get(),
                                                       &inst));
    return inst;
}

+ (WMEVideoCompositorDefinition*)make:(NSString*)activatableClassId {
    ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinition> unmarshalledReturn;
    auto _comInst = WMEIVideoCompositorDefinitionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(activatableClassId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEVideoCompositorDefinition>(unmarshalledReturn.Get()) retain];
}

+ (WMEVideoCompositorDefinition*)makeWithProperties:(NSString*)activatableClassId props:(RTObject<WFCIPropertySet>*)props {
    ComPtr<ABI::Windows::Media::Effects::IVideoCompositorDefinition> unmarshalledReturn;
    auto _comInst = WMEIVideoCompositorDefinitionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithProperties(nsStrToHstr(activatableClassId).Get(),
                                                      _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(props).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEVideoCompositorDefinition>(unmarshalledReturn.Get()) retain];
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositorDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoCompositorDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMECompositeVideoFrameContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::ICompositeVideoFrameContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* RTObject<WGDDIDirect3DSurface>* */)surfacesToOverlay {
    ComPtr<IVectorView<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::ICompositeVideoFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_SurfacesToOverlay(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WGDDIDirect3DSurface_create(unmarshalledReturn.Get());
}

- (WMVideoFrame*)backgroundFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::ICompositeVideoFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackgroundFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (WMVideoFrame*)outputFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::ICompositeVideoFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (WMEMediaOverlay*)getOverlayForSurface:(RTObject<WGDDIDirect3DSurface>*)surfaceToOverlay {
    ComPtr<ABI::Windows::Media::Editing::IMediaOverlay> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::ICompositeVideoFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->GetOverlayForSurface(
        _getRtInterface<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface>(surfaceToOverlay).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEMediaOverlay>(unmarshalledReturn.Get());
}

@end

@implementation WMEAudioEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IAudioEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMEAudioEffectType)audioEffectType {
    ABI::Windows::Media::Effects::AudioEffectType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_AudioEffectType(&unmarshalledReturn));
    return (WMEAudioEffectType)unmarshalledReturn;
}

@end

@implementation WMEAudioRenderEffectsManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IAudioRenderEffectsManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAudioRenderEffectsChangedEvent:(void (^)(WMEAudioRenderEffectsManager*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioRenderEffectsManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_AudioRenderEffectsChanged(
        Make<ITypedEventHandler_Windows_Media_Effects_AudioRenderEffectsManager_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAudioRenderEffectsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioRenderEffectsManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AudioRenderEffectsChanged(token));
}

- (NSArray* /* WMEAudioEffect* */)getAudioRenderEffects {
    ComPtr<IVectorView<ABI::Windows::Media::Effects::AudioEffect*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioRenderEffectsManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetAudioRenderEffects(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMEAudioEffect_create(unmarshalledReturn.Get());
}

- (RTObject<WSSIRandomAccessStreamWithContentType>*)effectsProviderThumbnail {
    ComPtr<ABI::Windows::Storage::Streams::IRandomAccessStreamWithContentType> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioRenderEffectsManager2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectsProviderThumbnail(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WSSIRandomAccessStreamWithContentType>(unmarshalledReturn.Get());
}

- (NSString*)effectsProviderSettingsLabel {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioRenderEffectsManager2>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectsProviderSettingsLabel(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)showSettingsUI {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioRenderEffectsManager2>(self);
    THROW_NS_IF_FAILED(_comInst->ShowSettingsUI());
}

@end

@implementation WMEAudioCaptureEffectsManager

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IAudioCaptureEffectsManager> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (EventRegistrationToken)addAudioCaptureEffectsChangedEvent:(void (^)(WMEAudioCaptureEffectsManager*, RTObject*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioCaptureEffectsManager>(self);
    THROW_NS_IF_FAILED(_comInst->add_AudioCaptureEffectsChanged(
        Make<ITypedEventHandler_Windows_Media_Effects_AudioCaptureEffectsManager_System_Object>(handler).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeAudioCaptureEffectsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioCaptureEffectsManager>(self);
    THROW_NS_IF_FAILED(_comInst->remove_AudioCaptureEffectsChanged(token));
}

- (NSArray* /* WMEAudioEffect* */)getAudioCaptureEffects {
    ComPtr<IVectorView<ABI::Windows::Media::Effects::AudioEffect*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IAudioCaptureEffectsManager>(self);
    THROW_NS_IF_FAILED(_comInst->GetAudioCaptureEffects(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_WMEAudioEffect_create(unmarshalledReturn.Get());
}

@end

@implementation WMEAudioEffectsManager

ComPtr<ABI::Windows::Media::Effects::IAudioEffectsManagerStatics> WMEIAudioEffectsManagerStatics_inst() {
    ComPtr<ABI::Windows::Media::Effects::IAudioEffectsManagerStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Effects.AudioEffectsManager").Get(), &inst));
    return inst;
}

+ (WMEAudioRenderEffectsManager*)createAudioRenderEffectsManager:(NSString*)deviceId category:(WMRAudioRenderCategory)category {
    ComPtr<ABI::Windows::Media::Effects::IAudioRenderEffectsManager> unmarshalledReturn;
    auto _comInst = WMEIAudioEffectsManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAudioRenderEffectsManager(nsStrToHstr(deviceId).Get(),
                                                                 (ABI::Windows::Media::Render::AudioRenderCategory)category,
                                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEAudioRenderEffectsManager>(unmarshalledReturn.Get());
}

+ (WMEAudioRenderEffectsManager*)createAudioRenderEffectsManagerWithMode:(NSString*)deviceId
                                                                category:(WMRAudioRenderCategory)category
                                                                    mode:(WMAudioProcessing)mode {
    ComPtr<ABI::Windows::Media::Effects::IAudioRenderEffectsManager> unmarshalledReturn;
    auto _comInst = WMEIAudioEffectsManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAudioRenderEffectsManagerWithMode(nsStrToHstr(deviceId).Get(),
                                                                         (ABI::Windows::Media::Render::AudioRenderCategory)category,
                                                                         (ABI::Windows::Media::AudioProcessing)mode,
                                                                         unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEAudioRenderEffectsManager>(unmarshalledReturn.Get());
}

+ (WMEAudioCaptureEffectsManager*)createAudioCaptureEffectsManager:(NSString*)deviceId category:(WMCMediaCategory)category {
    ComPtr<ABI::Windows::Media::Effects::IAudioCaptureEffectsManager> unmarshalledReturn;
    auto _comInst = WMEIAudioEffectsManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAudioCaptureEffectsManager(nsStrToHstr(deviceId).Get(),
                                                                  (ABI::Windows::Media::Capture::MediaCategory)category,
                                                                  unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEAudioCaptureEffectsManager>(unmarshalledReturn.Get());
}

+ (WMEAudioCaptureEffectsManager*)createAudioCaptureEffectsManagerWithMode:(NSString*)deviceId
                                                                  category:(WMCMediaCategory)category
                                                                      mode:(WMAudioProcessing)mode {
    ComPtr<ABI::Windows::Media::Effects::IAudioCaptureEffectsManager> unmarshalledReturn;
    auto _comInst = WMEIAudioEffectsManagerStatics_inst();
    THROW_NS_IF_FAILED(_comInst->CreateAudioCaptureEffectsManagerWithMode(nsStrToHstr(deviceId).Get(),
                                                                          (ABI::Windows::Media::Capture::MediaCategory)category,
                                                                          (ABI::Windows::Media::AudioProcessing)mode,
                                                                          unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMEAudioCaptureEffectsManager>(unmarshalledReturn.Get());
}

@end

@implementation WMEVideoEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinitionFactory> WMEIVideoEffectDefinitionFactory_inst() {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinitionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Effects.VideoEffectDefinition").Get(),
                                                       &inst));
    return inst;
}

+ (WMEVideoEffectDefinition*)make:(NSString*)activatableClassId {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> unmarshalledReturn;
    auto _comInst = WMEIVideoEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(activatableClassId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEVideoEffectDefinition>(unmarshalledReturn.Get()) retain];
}

+ (WMEVideoEffectDefinition*)makeWithProperties:(NSString*)activatableClassId props:(RTObject<WFCIPropertySet>*)props {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> unmarshalledReturn;
    auto _comInst = WMEIVideoEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithProperties(nsStrToHstr(activatableClassId).Get(),
                                                      _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(props).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEVideoEffectDefinition>(unmarshalledReturn.Get()) retain];
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WMEAudioEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IAudioEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::Media::Effects::IAudioEffectDefinitionFactory> WMEIAudioEffectDefinitionFactory_inst() {
    ComPtr<ABI::Windows::Media::Effects::IAudioEffectDefinitionFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.Media.Effects.AudioEffectDefinition").Get(),
                                                       &inst));
    return inst;
}

+ (WMEAudioEffectDefinition*)make:(NSString*)activatableClassId {
    ComPtr<ABI::Windows::Media::Effects::IAudioEffectDefinition> unmarshalledReturn;
    auto _comInst = WMEIAudioEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(activatableClassId).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEAudioEffectDefinition>(unmarshalledReturn.Get()) retain];
}

+ (WMEAudioEffectDefinition*)makeWithProperties:(NSString*)activatableClassId props:(RTObject<WFCIPropertySet>*)props {
    ComPtr<ABI::Windows::Media::Effects::IAudioEffectDefinition> unmarshalledReturn;
    auto _comInst = WMEIAudioEffectDefinitionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithProperties(nsStrToHstr(activatableClassId).Get(),
                                                      _getRtInterface<ABI::Windows::Foundation::Collections::IPropertySet>(props).Get(),
                                                      unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WMEAudioEffectDefinition>(unmarshalledReturn.Get()) retain];
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

@implementation WMEProcessVideoFrameContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IProcessVideoFrameContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMVideoFrame*)inputFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IProcessVideoFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

- (WMVideoFrame*)outputFrame {
    ComPtr<ABI::Windows::Media::IVideoFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IProcessVideoFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMVideoFrame>(unmarshalledReturn.Get());
}

@end

@implementation WMEProcessAudioFrameContext

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IProcessAudioFrameContext> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WMAudioFrame*)inputFrame {
    ComPtr<ABI::Windows::Media::IAudioFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IProcessAudioFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_InputFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAudioFrame>(unmarshalledReturn.Get());
}

- (WMAudioFrame*)outputFrame {
    ComPtr<ABI::Windows::Media::IAudioFrame> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IProcessAudioFrameContext>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputFrame(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WMAudioFrame>(unmarshalledReturn.Get());
}

@end

@implementation WMEVideoTransformEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::IVideoEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Effects.VideoTransformEffectDefinition").Get(), &out));
    return [_createRtProxy<WMEVideoTransformEffectDefinition>(out.Get()) retain];
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

- (WUColor*)paddingColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_PaddingColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setPaddingColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_PaddingColor(*[value internalStruct]));
}

- (WFSize*)outputSize {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_OutputSize(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

- (void)setOutputSize:(WFSize*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_OutputSize(*[value internalStruct]));
}

- (WFRect*)cropRectangle {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_CropRectangle(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (void)setCropRectangle:(WFRect*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_CropRectangle(*[value internalStruct]));
}

- (WMMMediaRotation)rotation {
    ABI::Windows::Media::MediaProperties::MediaRotation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Rotation(&unmarshalledReturn));
    return (WMMMediaRotation)unmarshalledReturn;
}

- (void)setRotation:(WMMMediaRotation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Rotation((ABI::Windows::Media::MediaProperties::MediaRotation)value));
}

- (WMMMediaMirroringOptions)mirror {
    ABI::Windows::Media::MediaProperties::MediaMirroringOptions unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mirror(&unmarshalledReturn));
    return (WMMMediaMirroringOptions)unmarshalledReturn;
}

- (void)setMirror:(WMMMediaMirroringOptions)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mirror((ABI::Windows::Media::MediaProperties::MediaMirroringOptions)value));
}

- (void)setProcessingAlgorithm:(WMTMediaVideoProcessingAlgorithm)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_ProcessingAlgorithm((ABI::Windows::Media::Transcoding::MediaVideoProcessingAlgorithm)value));
}

- (WMTMediaVideoProcessingAlgorithm)processingAlgorithm {
    ABI::Windows::Media::Transcoding::MediaVideoProcessingAlgorithm unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoTransformEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ProcessingAlgorithm(&unmarshalledReturn));
    return (WMTMediaVideoProcessingAlgorithm)unmarshalledReturn;
}

@end

@implementation WMESlowMotionEffectDefinition

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::Media::Effects::ISlowMotionEffectDefinition> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.Media.Effects.SlowMotionEffectDefinition").Get(), &out));
    return [_createRtProxy<WMESlowMotionEffectDefinition>(out.Get()) retain];
}

- (double)timeStretchRate {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::ISlowMotionEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_TimeStretchRate(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTimeStretchRate:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::ISlowMotionEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->put_TimeStretchRate(value));
}

- (NSString*)activatableClassId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_ActivatableClassId(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (RTObject<WFCIPropertySet>*)properties {
    ComPtr<ABI::Windows::Foundation::Collections::IPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Media::Effects::IVideoEffectDefinition>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WFCIPropertySet>(unmarshalledReturn.Get());
}

@end

id RTProxiedNSArray_RTObject_WGDDIDirect3DSurface_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface*>,
                                         RTArrayObj<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface*,
                                                    IVectorView<ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface*>,
                                                    RTObject<WGDDIDirect3DSurface>,
                                                    ABI::Windows::Graphics::DirectX::Direct3D11::IDirect3DSurface*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMEAudioEffect_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::Effects::AudioEffect*>,
                                         RTArrayObj<ABI::Windows::Media::Effects::IAudioEffect*,
                                                    IVectorView<ABI::Windows::Media::Effects::AudioEffect*>,
                                                    WMEAudioEffect,
                                                    ABI::Windows::Media::Effects::AudioEffect*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMMAudioEncodingProperties_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::MediaProperties::AudioEncodingProperties*>,
                                         RTArrayObj<ABI::Windows::Media::MediaProperties::IAudioEncodingProperties*,
                                                    IVectorView<ABI::Windows::Media::MediaProperties::AudioEncodingProperties*>,
                                                    WMMAudioEncodingProperties,
                                                    ABI::Windows::Media::MediaProperties::AudioEncodingProperties*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_WMMVideoEncodingProperties_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::Media::MediaProperties::VideoEncodingProperties*>,
                                         RTArrayObj<ABI::Windows::Media::MediaProperties::IVideoEncodingProperties*,
                                                    IVectorView<ABI::Windows::Media::MediaProperties::VideoEncodingProperties*>,
                                                    WMMVideoEncodingProperties,
                                                    ABI::Windows::Media::MediaProperties::VideoEncodingProperties*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
