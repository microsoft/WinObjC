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

// WindowsUIComposition.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Composition.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIComposition.h"
#include "WindowsUIComposition_priv.h"

@implementation WUCICompositionAnimationBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionAnimationBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCICompositionSurface

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionSurface> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCCompositionObject

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionObject> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositor*)compositor {
    ComPtr<ABI::Windows::UI::Composition::ICompositor> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Compositor(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositor>(unmarshalledReturn.Get());
}

- (WUCCoreDispatcher*)dispatcher {
    ComPtr<ABI::Windows::UI::Core::ICoreDispatcher> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Dispatcher(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCoreDispatcher>(unmarshalledReturn.Get());
}

- (WUCCompositionPropertySet*)properties {
    ComPtr<ABI::Windows::UI::Composition::ICompositionPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject>(self);
    THROW_NS_IF_FAILED(_comInst->get_Properties(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionPropertySet>(unmarshalledReturn.Get());
}

- (void)startAnimation:(NSString*)propertyName animation:(WUCCompositionAnimation*)animation {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject>(self);
    THROW_NS_IF_FAILED(_comInst->StartAnimation(nsStrToHstr(propertyName).Get(),
                                                _getRtInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(animation).Get()));
}

- (void)stopAnimation:(NSString*)propertyName {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject>(self);
    THROW_NS_IF_FAILED(_comInst->StopAnimation(nsStrToHstr(propertyName).Get()));
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (NSString*)comment {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Comment(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setComment:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Comment(nsStrToHstr(value).Get()));
}

- (WUCImplicitAnimationCollection*)implicitAnimations {
    ComPtr<ABI::Windows::UI::Composition::IImplicitAnimationCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ImplicitAnimations(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCImplicitAnimationCollection>(unmarshalledReturn.Get());
}

- (void)setImplicitAnimations:(WUCImplicitAnimationCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject2>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ImplicitAnimations(_getRtInterface<ABI::Windows::UI::Composition::IImplicitAnimationCollection>(value).Get()));
}

- (void)startAnimationGroup:(RTObject<WUCICompositionAnimationBase>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject2>(self);
    THROW_NS_IF_FAILED(
        _comInst->StartAnimationGroup(_getRtInterface<ABI::Windows::UI::Composition::ICompositionAnimationBase>(value).Get()));
}

- (void)stopAnimationGroup:(RTObject<WUCICompositionAnimationBase>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionObject2>(self);
    THROW_NS_IF_FAILED(
        _comInst->StopAnimationGroup(_getRtInterface<ABI::Windows::UI::Composition::ICompositionAnimationBase>(value).Get()));
}

@end

@implementation WUCCompositionAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)clearAllParameters {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->ClearAllParameters());
}

- (void)clearParameter:(NSString*)key {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->ClearParameter(nsStrToHstr(key).Get()));
}

- (void)setColorParameter:(NSString*)key value:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetColorParameter(nsStrToHstr(key).Get(), *[value internalStruct]));
}

- (void)setMatrix3x2Parameter:(NSString*)key value:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetMatrix3x2Parameter(nsStrToHstr(key).Get(), *[value internalStruct]));
}

- (void)setMatrix4x4Parameter:(NSString*)key value:(WFNMatrix4x4*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetMatrix4x4Parameter(nsStrToHstr(key).Get(), *[value internalStruct]));
}

- (void)setQuaternionParameter:(NSString*)key value:(WFNQuaternion*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetQuaternionParameter(nsStrToHstr(key).Get(), *[value internalStruct]));
}

- (void)setReferenceParameter:(NSString*)key compositionObject:(WUCCompositionObject*)compositionObject {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(
        _comInst->SetReferenceParameter(nsStrToHstr(key).Get(),
                                        _getRtInterface<ABI::Windows::UI::Composition::ICompositionObject>(compositionObject).Get()));
}

- (void)setScalarParameter:(NSString*)key value:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetScalarParameter(nsStrToHstr(key).Get(), value));
}

- (void)setVector2Parameter:(NSString*)key value:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetVector2Parameter(nsStrToHstr(key).Get(), *[value internalStruct]));
}

- (void)setVector3Parameter:(NSString*)key value:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetVector3Parameter(nsStrToHstr(key).Get(), *[value internalStruct]));
}

- (void)setVector4Parameter:(NSString*)key value:(WFNVector4*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->SetVector4Parameter(nsStrToHstr(key).Get(), *[value internalStruct]));
}

- (void)setBooleanParameter:(NSString*)key value:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation2>(self);
    THROW_NS_IF_FAILED(_comInst->SetBooleanParameter(nsStrToHstr(key).Get(), (boolean)value));
}

- (NSString*)target {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Target(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setTarget:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimation2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Target(nsStrToHstr(value).Get()));
}

@end

@implementation WUCCompositionBatchCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBatchCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCCompositionEasingFunction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEasingFunction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCCompositionBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCCompositionEffectBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionBrush*)getSourceParameter:(NSString*)name {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionEffectBrush>(self);
    THROW_NS_IF_FAILED(_comInst->GetSourceParameter(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBrush>(unmarshalledReturn.Get());
}

- (void)setSourceParameter:(NSString*)name source:(WUCCompositionBrush*)source {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionEffectBrush>(self);
    THROW_NS_IF_FAILED(_comInst->SetSourceParameter(nsStrToHstr(name).Get(),
                                                    _getRtInterface<ABI::Windows::UI::Composition::ICompositionBrush>(source).Get()));
}

@end

@implementation WUCCompositionEffectSourceParameter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectSourceParameter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Composition::ICompositionEffectSourceParameterFactory> WUCICompositionEffectSourceParameterFactory_inst() {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectSourceParameterFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Composition.CompositionEffectSourceParameter").Get(), &inst));
    return inst;
}

+ (WUCCompositionEffectSourceParameter*)make:(NSString*)name {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectSourceParameter> unmarshalledReturn;
    auto _comInst = WUCICompositionEffectSourceParameterFactory_inst();
    THROW_NS_IF_FAILED(_comInst->Create(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUCCompositionEffectSourceParameter>(unmarshalledReturn.Get()) retain];
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionEffectSourceParameter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUCCompositionGraphicsDevice

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionGraphicsDevice> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionDrawingSurface*)createDrawingSurface:(WFSize*)sizePixels
                                          pixelFormat:(WGDDirectXPixelFormat)pixelFormat
                                            alphaMode:(WGDDirectXAlphaMode)alphaMode {
    ComPtr<ABI::Windows::UI::Composition::ICompositionDrawingSurface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionGraphicsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDrawingSurface(*[sizePixels internalStruct],
                                                      (ABI::Windows::Graphics::DirectX::DirectXPixelFormat)pixelFormat,
                                                      (ABI::Windows::Graphics::DirectX::DirectXAlphaMode)alphaMode,
                                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionDrawingSurface>(unmarshalledReturn.Get());
}

- (EventRegistrationToken)addRenderingDeviceReplacedEvent:(void (^)(WUCCompositionGraphicsDevice*,
                                                                    WUCRenderingDeviceReplacedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionGraphicsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->add_RenderingDeviceReplaced(
        Make<ITypedEventHandler_Windows_UI_Composition_CompositionGraphicsDevice_Windows_UI_Composition_RenderingDeviceReplacedEventArgs>(
            handler)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeRenderingDeviceReplacedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionGraphicsDevice>(self);
    THROW_NS_IF_FAILED(_comInst->remove_RenderingDeviceReplaced(token));
}

@end

@implementation WUCCompositor

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositor> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Composition.Compositor").Get(), &out));
    return [_createRtProxy<WUCCompositor>(out.Get()) retain];
}

- (WUCColorKeyFrameAnimation*)createColorKeyFrameAnimation {
    ComPtr<ABI::Windows::UI::Composition::IColorKeyFrameAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateColorKeyFrameAnimation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCColorKeyFrameAnimation>(unmarshalledReturn.Get());
}

- (WUCCompositionColorBrush*)createColorBrush {
    ComPtr<ABI::Windows::UI::Composition::ICompositionColorBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateColorBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionColorBrush>(unmarshalledReturn.Get());
}

- (WUCCompositionColorBrush*)createColorBrushWithColor:(WUColor*)color {
    ComPtr<ABI::Windows::UI::Composition::ICompositionColorBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateColorBrushWithColor(*[color internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionColorBrush>(unmarshalledReturn.Get());
}

- (WUCContainerVisual*)createContainerVisual {
    ComPtr<ABI::Windows::UI::Composition::IContainerVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateContainerVisual(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCContainerVisual>(unmarshalledReturn.Get());
}

- (WUCCubicBezierEasingFunction*)createCubicBezierEasingFunction:(WFNVector2*)controlPoint1 controlPoint2:(WFNVector2*)controlPoint2 {
    ComPtr<ABI::Windows::UI::Composition::ICubicBezierEasingFunction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateCubicBezierEasingFunction(*[controlPoint1 internalStruct],
                                                                 *[controlPoint2 internalStruct],
                                                                 unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCubicBezierEasingFunction>(unmarshalledReturn.Get());
}

- (WUCCompositionEffectFactory*)createEffectFactory:(RTObject<WGEIGraphicsEffect>*)graphicsEffect {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectFactory> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateEffectFactory(_getRtInterface<ABI::Windows::Graphics::Effects::IGraphicsEffect>(graphicsEffect).Get(),
                                      unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionEffectFactory>(unmarshalledReturn.Get());
}

- (WUCCompositionEffectFactory*)createEffectFactoryWithProperties:(RTObject<WGEIGraphicsEffect>*)graphicsEffect
                                             animatableProperties:(id<NSFastEnumeration> /* NSString * */)animatableProperties {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectFactory> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateEffectFactoryWithProperties(
        _getRtInterface<ABI::Windows::Graphics::Effects::IGraphicsEffect>(graphicsEffect).Get(),
        static_cast<IIterable<typename ABI::Windows::Foundation::Internal::GetLogicalType<HSTRING>::type>*>(
            ConvertToIterable<NSString, HSTRING>(animatableProperties).Get()),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionEffectFactory>(unmarshalledReturn.Get());
}

- (WUCExpressionAnimation*)createExpressionAnimation {
    ComPtr<ABI::Windows::UI::Composition::IExpressionAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateExpressionAnimation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCExpressionAnimation>(unmarshalledReturn.Get());
}

- (WUCExpressionAnimation*)createExpressionAnimationWithExpression:(NSString*)expression {
    ComPtr<ABI::Windows::UI::Composition::IExpressionAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateExpressionAnimationWithExpression(nsStrToHstr(expression).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCExpressionAnimation>(unmarshalledReturn.Get());
}

- (WUCInsetClip*)createInsetClip {
    ComPtr<ABI::Windows::UI::Composition::IInsetClip> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateInsetClip(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCInsetClip>(unmarshalledReturn.Get());
}

- (WUCInsetClip*)createInsetClipWithInsets:(float)leftInset
                                  topInset:(float)topInset
                                rightInset:(float)rightInset
                               bottomInset:(float)bottomInset {
    ComPtr<ABI::Windows::UI::Composition::IInsetClip> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateInsetClipWithInsets(leftInset, topInset, rightInset, bottomInset, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCInsetClip>(unmarshalledReturn.Get());
}

- (WUCLinearEasingFunction*)createLinearEasingFunction {
    ComPtr<ABI::Windows::UI::Composition::ILinearEasingFunction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLinearEasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCLinearEasingFunction>(unmarshalledReturn.Get());
}

- (WUCCompositionPropertySet*)createPropertySet {
    ComPtr<ABI::Windows::UI::Composition::ICompositionPropertySet> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreatePropertySet(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionPropertySet>(unmarshalledReturn.Get());
}

- (WUCQuaternionKeyFrameAnimation*)createQuaternionKeyFrameAnimation {
    ComPtr<ABI::Windows::UI::Composition::IQuaternionKeyFrameAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateQuaternionKeyFrameAnimation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCQuaternionKeyFrameAnimation>(unmarshalledReturn.Get());
}

- (WUCScalarKeyFrameAnimation*)createScalarKeyFrameAnimation {
    ComPtr<ABI::Windows::UI::Composition::IScalarKeyFrameAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateScalarKeyFrameAnimation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCScalarKeyFrameAnimation>(unmarshalledReturn.Get());
}

- (WUCCompositionScopedBatch*)createScopedBatch:(WUCCompositionBatchTypes)batchType {
    ComPtr<ABI::Windows::UI::Composition::ICompositionScopedBatch> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateScopedBatch((ABI::Windows::UI::Composition::CompositionBatchTypes)batchType, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionScopedBatch>(unmarshalledReturn.Get());
}

- (WUCSpriteVisual*)createSpriteVisual {
    ComPtr<ABI::Windows::UI::Composition::ISpriteVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateSpriteVisual(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCSpriteVisual>(unmarshalledReturn.Get());
}

- (WUCCompositionSurfaceBrush*)createSurfaceBrush {
    ComPtr<ABI::Windows::UI::Composition::ICompositionSurfaceBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateSurfaceBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionSurfaceBrush>(unmarshalledReturn.Get());
}

- (WUCCompositionSurfaceBrush*)createSurfaceBrushWithSurface:(RTObject<WUCICompositionSurface>*)surface {
    ComPtr<ABI::Windows::UI::Composition::ICompositionSurfaceBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(
        _comInst->CreateSurfaceBrushWithSurface(_getRtInterface<ABI::Windows::UI::Composition::ICompositionSurface>(surface).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionSurfaceBrush>(unmarshalledReturn.Get());
}

- (WUCCompositionTarget*)createTargetForCurrentView {
    ComPtr<ABI::Windows::UI::Composition::ICompositionTarget> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateTargetForCurrentView(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionTarget>(unmarshalledReturn.Get());
}

- (WUCVector2KeyFrameAnimation*)createVector2KeyFrameAnimation {
    ComPtr<ABI::Windows::UI::Composition::IVector2KeyFrameAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVector2KeyFrameAnimation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVector2KeyFrameAnimation>(unmarshalledReturn.Get());
}

- (WUCVector3KeyFrameAnimation*)createVector3KeyFrameAnimation {
    ComPtr<ABI::Windows::UI::Composition::IVector3KeyFrameAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVector3KeyFrameAnimation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVector3KeyFrameAnimation>(unmarshalledReturn.Get());
}

- (WUCVector4KeyFrameAnimation*)createVector4KeyFrameAnimation {
    ComPtr<ABI::Windows::UI::Composition::IVector4KeyFrameAnimation> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(_comInst->CreateVector4KeyFrameAnimation(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVector4KeyFrameAnimation>(unmarshalledReturn.Get());
}

- (WUCCompositionCommitBatch*)getCommitBatch:(WUCCompositionBatchTypes)batchType {
    ComPtr<ABI::Windows::UI::Composition::ICompositionCommitBatch> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor>(self);
    THROW_NS_IF_FAILED(
        _comInst->GetCommitBatch((ABI::Windows::UI::Composition::CompositionBatchTypes)batchType, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionCommitBatch>(unmarshalledReturn.Get());
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::Foundation::IClosable>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (WUCAmbientLight*)createAmbientLight {
    ComPtr<ABI::Windows::UI::Composition::IAmbientLight> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAmbientLight(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCAmbientLight>(unmarshalledReturn.Get());
}

- (WUCCompositionAnimationGroup*)createAnimationGroup {
    ComPtr<ABI::Windows::UI::Composition::ICompositionAnimationGroup> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateAnimationGroup(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionAnimationGroup>(unmarshalledReturn.Get());
}

- (WUCCompositionBackdropBrush*)createBackdropBrush {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBackdropBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateBackdropBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBackdropBrush>(unmarshalledReturn.Get());
}

- (WUCDistantLight*)createDistantLight {
    ComPtr<ABI::Windows::UI::Composition::IDistantLight> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDistantLight(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCDistantLight>(unmarshalledReturn.Get());
}

- (WUCDropShadow*)createDropShadow {
    ComPtr<ABI::Windows::UI::Composition::IDropShadow> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateDropShadow(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCDropShadow>(unmarshalledReturn.Get());
}

- (WUCImplicitAnimationCollection*)createImplicitAnimationCollection {
    ComPtr<ABI::Windows::UI::Composition::IImplicitAnimationCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateImplicitAnimationCollection(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCImplicitAnimationCollection>(unmarshalledReturn.Get());
}

- (WUCLayerVisual*)createLayerVisual {
    ComPtr<ABI::Windows::UI::Composition::ILayerVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateLayerVisual(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCLayerVisual>(unmarshalledReturn.Get());
}

- (WUCCompositionMaskBrush*)createMaskBrush {
    ComPtr<ABI::Windows::UI::Composition::ICompositionMaskBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateMaskBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionMaskBrush>(unmarshalledReturn.Get());
}

- (WUCCompositionNineGridBrush*)createNineGridBrush {
    ComPtr<ABI::Windows::UI::Composition::ICompositionNineGridBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateNineGridBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionNineGridBrush>(unmarshalledReturn.Get());
}

- (WUCPointLight*)createPointLight {
    ComPtr<ABI::Windows::UI::Composition::IPointLight> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreatePointLight(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCPointLight>(unmarshalledReturn.Get());
}

- (WUCSpotLight*)createSpotLight {
    ComPtr<ABI::Windows::UI::Composition::ISpotLight> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateSpotLight(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCSpotLight>(unmarshalledReturn.Get());
}

- (WUCStepEasingFunction*)createStepEasingFunction {
    ComPtr<ABI::Windows::UI::Composition::IStepEasingFunction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateStepEasingFunction(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCStepEasingFunction>(unmarshalledReturn.Get());
}

- (WUCStepEasingFunction*)createStepEasingFunctionWithStepCount:(int)stepCount {
    ComPtr<ABI::Windows::UI::Composition::IStepEasingFunction> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositor2>(self);
    THROW_NS_IF_FAILED(_comInst->CreateStepEasingFunctionWithStepCount(stepCount, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCStepEasingFunction>(unmarshalledReturn.Get());
}

@end

@implementation WUCCompositionPropertySet

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionPropertySet> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)insertColor:(NSString*)propertyName value:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertColor(nsStrToHstr(propertyName).Get(), *[value internalStruct]));
}

- (void)insertMatrix3x2:(NSString*)propertyName value:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertMatrix3x2(nsStrToHstr(propertyName).Get(), *[value internalStruct]));
}

- (void)insertMatrix4x4:(NSString*)propertyName value:(WFNMatrix4x4*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertMatrix4x4(nsStrToHstr(propertyName).Get(), *[value internalStruct]));
}

- (void)insertQuaternion:(NSString*)propertyName value:(WFNQuaternion*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertQuaternion(nsStrToHstr(propertyName).Get(), *[value internalStruct]));
}

- (void)insertScalar:(NSString*)propertyName value:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertScalar(nsStrToHstr(propertyName).Get(), value));
}

- (void)insertVector2:(NSString*)propertyName value:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertVector2(nsStrToHstr(propertyName).Get(), *[value internalStruct]));
}

- (void)insertVector3:(NSString*)propertyName value:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertVector3(nsStrToHstr(propertyName).Get(), *[value internalStruct]));
}

- (void)insertVector4:(NSString*)propertyName value:(WFNVector4*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->InsertVector4(nsStrToHstr(propertyName).Get(), *[value internalStruct]));
}

- (WUCCompositionGetValueStatus)tryGetColor:(NSString*)propertyName value:(WUColor**)value {
    ABI::Windows::UI::Color valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetColor(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = WUColor_create(valueOutUnmarshaled);
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (WUCCompositionGetValueStatus)tryGetMatrix3x2:(NSString*)propertyName value:(WFNMatrix3x2**)value {
    ABI::Windows::Foundation::Numerics::Matrix3x2 valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetMatrix3x2(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = WFNMatrix3x2_create(valueOutUnmarshaled);
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (WUCCompositionGetValueStatus)tryGetMatrix4x4:(NSString*)propertyName value:(WFNMatrix4x4**)value {
    ABI::Windows::Foundation::Numerics::Matrix4x4 valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetMatrix4x4(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = WFNMatrix4x4_create(valueOutUnmarshaled);
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (WUCCompositionGetValueStatus)tryGetQuaternion:(NSString*)propertyName value:(WFNQuaternion**)value {
    ABI::Windows::Foundation::Numerics::Quaternion valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetQuaternion(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = WFNQuaternion_create(valueOutUnmarshaled);
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (WUCCompositionGetValueStatus)tryGetScalar:(NSString*)propertyName value:(float*)value {
    float valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetScalar(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = valueOutUnmarshaled;
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (WUCCompositionGetValueStatus)tryGetVector2:(NSString*)propertyName value:(WFNVector2**)value {
    ABI::Windows::Foundation::Numerics::Vector2 valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetVector2(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = WFNVector2_create(valueOutUnmarshaled);
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (WUCCompositionGetValueStatus)tryGetVector3:(NSString*)propertyName value:(WFNVector3**)value {
    ABI::Windows::Foundation::Numerics::Vector3 valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetVector3(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = WFNVector3_create(valueOutUnmarshaled);
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (WUCCompositionGetValueStatus)tryGetVector4:(NSString*)propertyName value:(WFNVector4**)value {
    ABI::Windows::Foundation::Numerics::Vector4 valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetVector4(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = WFNVector4_create(valueOutUnmarshaled);
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

- (void)insertBoolean:(NSString*)propertyName value:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBoolean(nsStrToHstr(propertyName).Get(), (boolean)value));
}

- (WUCCompositionGetValueStatus)tryGetBoolean:(NSString*)propertyName value:(BOOL*)value {
    boolean valueOutUnmarshaled;
    ABI::Windows::UI::Composition::CompositionGetValueStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionPropertySet2>(self);
    THROW_NS_IF_FAILED(_comInst->TryGetBoolean(nsStrToHstr(propertyName).Get(), &valueOutUnmarshaled, &unmarshalledReturn));
    *value = (BOOL)valueOutUnmarshaled;
    return (WUCCompositionGetValueStatus)unmarshalledReturn;
}

@end

@implementation WUCCompositionDrawingSurface

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionDrawingSurface> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WGDDirectXAlphaMode)alphaMode {
    ABI::Windows::Graphics::DirectX::DirectXAlphaMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionDrawingSurface>(self);
    THROW_NS_IF_FAILED(_comInst->get_AlphaMode(&unmarshalledReturn));
    return (WGDDirectXAlphaMode)unmarshalledReturn;
}

- (WGDDirectXPixelFormat)pixelFormat {
    ABI::Windows::Graphics::DirectX::DirectXPixelFormat unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionDrawingSurface>(self);
    THROW_NS_IF_FAILED(_comInst->get_PixelFormat(&unmarshalledReturn));
    return (WGDDirectXPixelFormat)unmarshalledReturn;
}

- (WFSize*)size {
    ABI::Windows::Foundation::Size unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionDrawingSurface>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFSize_create(unmarshalledReturn);
}

@end

@implementation WUCCompositionColorBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionColorBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionColorBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionColorBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

@end

@implementation WUCCompositionEffectFactory

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectFactory> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionEffectBrush*)createBrush {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionEffectFactory>(self);
    THROW_NS_IF_FAILED(_comInst->CreateBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionEffectBrush>(unmarshalledReturn.Get());
}

- (HRESULT)extendedError {
    HRESULT unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionEffectFactory>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedError(&unmarshalledReturn));
    return (HRESULT)unmarshalledReturn;
}

- (WUCCompositionEffectFactoryLoadStatus)loadStatus {
    ABI::Windows::UI::Composition::CompositionEffectFactoryLoadStatus unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionEffectFactory>(self);
    THROW_NS_IF_FAILED(_comInst->get_LoadStatus(&unmarshalledReturn));
    return (WUCCompositionEffectFactoryLoadStatus)unmarshalledReturn;
}

@end

@implementation WUCCompositionScopedBatch

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionScopedBatch> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionScopedBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionScopedBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)end {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionScopedBatch>(self);
    THROW_NS_IF_FAILED(_comInst->End());
}

- (void)resume {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionScopedBatch>(self);
    THROW_NS_IF_FAILED(_comInst->Resume());
}

- (void)suspend {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionScopedBatch>(self);
    THROW_NS_IF_FAILED(_comInst->Suspend());
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(RTObject*, WUCCompositionBatchCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionScopedBatch>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(
        Make<ITypedEventHandler_System_Object_Windows_UI_Composition_CompositionBatchCompletedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionScopedBatch>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(token));
}

@end

@implementation WUCCompositionSurfaceBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionSurfaceBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionBitmapInterpolationMode)bitmapInterpolationMode {
    ABI::Windows::UI::Composition::CompositionBitmapInterpolationMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_BitmapInterpolationMode(&unmarshalledReturn));
    return (WUCCompositionBitmapInterpolationMode)unmarshalledReturn;
}

- (void)setBitmapInterpolationMode:(WUCCompositionBitmapInterpolationMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_BitmapInterpolationMode((ABI::Windows::UI::Composition::CompositionBitmapInterpolationMode)value));
}

- (float)horizontalAlignmentRatio {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalAlignmentRatio(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHorizontalAlignmentRatio:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_HorizontalAlignmentRatio(value));
}

- (WUCCompositionStretch)stretch {
    ABI::Windows::UI::Composition::CompositionStretch unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Stretch(&unmarshalledReturn));
    return (WUCCompositionStretch)unmarshalledReturn;
}

- (void)setStretch:(WUCCompositionStretch)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Stretch((ABI::Windows::UI::Composition::CompositionStretch)value));
}

- (RTObject<WUCICompositionSurface>*)surface {
    ComPtr<ABI::Windows::UI::Composition::ICompositionSurface> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Surface(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCICompositionSurface>(unmarshalledReturn.Get());
}

- (void)setSurface:(RTObject<WUCICompositionSurface>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Surface(_getRtInterface<ABI::Windows::UI::Composition::ICompositionSurface>(value).Get()));
}

- (float)verticalAlignmentRatio {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalAlignmentRatio(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVerticalAlignmentRatio:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_VerticalAlignmentRatio(value));
}

- (WFNVector2*)anchorPoint {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnchorPoint(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setAnchorPoint:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AnchorPoint(*[value internalStruct]));
}

- (WFNVector2*)centerPoint {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterPoint(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setCenterPoint:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterPoint(*[value internalStruct]));
}

- (WFNVector2*)offset {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setOffset:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(*[value internalStruct]));
}

- (float)rotationAngle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationAngle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAngle(value));
}

- (float)rotationAngleInDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngleInDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationAngleInDegrees:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAngleInDegrees(value));
}

- (WFNVector2*)scale {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scale(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setScale:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Scale(*[value internalStruct]));
}

- (WFNMatrix3x2*)transformMatrix {
    ABI::Windows::Foundation::Numerics::Matrix3x2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransformMatrix(&unmarshalledReturn));
    return WFNMatrix3x2_create(unmarshalledReturn);
}

- (void)setTransformMatrix:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionSurfaceBrush2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransformMatrix(*[value internalStruct]));
}

@end

@implementation WUCCompositionTarget

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionTarget> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCVisual*)root {
    ComPtr<ABI::Windows::UI::Composition::IVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionTarget>(self);
    THROW_NS_IF_FAILED(_comInst->get_Root(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisual>(unmarshalledReturn.Get());
}

- (void)setRoot:(WUCVisual*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionTarget>(self);
    THROW_NS_IF_FAILED(_comInst->put_Root(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(value).Get()));
}

@end

@implementation WUCCompositionCommitBatch

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionCommitBatch> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isActive {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionCommitBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsActive(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isEnded {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionCommitBatch>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsEnded(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addCompletedEvent:(void (^)(RTObject*, WUCCompositionBatchCompletedEventArgs*))handler {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionCommitBatch>(self);
    THROW_NS_IF_FAILED(_comInst->add_Completed(
        Make<ITypedEventHandler_System_Object_Windows_UI_Composition_CompositionBatchCompletedEventArgs>(handler).Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionCommitBatch>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Completed(token));
}

@end

@implementation WUCCompositionAnimationGroup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionAnimationGroup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimationGroup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Count(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)add:(WUCCompositionAnimation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimationGroup>(self);
    THROW_NS_IF_FAILED(_comInst->Add(_getRtInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(value).Get()));
}

- (void)remove:(WUCCompositionAnimation*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimationGroup>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(_getRtInterface<ABI::Windows::UI::Composition::ICompositionAnimation>(value).Get()));
}

- (void)removeAll {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionAnimationGroup>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAll());
}

@end

@implementation WUCCompositionBackdropBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBackdropBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCCompositionMaskBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionMaskBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionBrush*)mask {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionMaskBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mask(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBrush>(unmarshalledReturn.Get());
}

- (void)setMask:(WUCCompositionBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionMaskBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mask(_getRtInterface<ABI::Windows::UI::Composition::ICompositionBrush>(value).Get()));
}

- (WUCCompositionBrush*)source {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionMaskBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBrush>(unmarshalledReturn.Get());
}

- (void)setSource:(WUCCompositionBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionMaskBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source(_getRtInterface<ABI::Windows::UI::Composition::ICompositionBrush>(value).Get()));
}

@end

@implementation WUCCompositionNineGridBrush

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionNineGridBrush> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (float)bottomInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_BottomInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBottomInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_BottomInset(value));
}

- (float)bottomInsetScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_BottomInsetScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBottomInsetScale:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_BottomInsetScale(value));
}

- (BOOL)isCenterHollow {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsCenterHollow(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsCenterHollow:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsCenterHollow((boolean)value));
}

- (float)leftInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_LeftInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLeftInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_LeftInset(value));
}

- (float)leftInsetScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_LeftInsetScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLeftInsetScale:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_LeftInsetScale(value));
}

- (float)rightInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_RightInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRightInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_RightInset(value));
}

- (float)rightInsetScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_RightInsetScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRightInsetScale:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_RightInsetScale(value));
}

- (WUCCompositionBrush*)source {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_Source(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBrush>(unmarshalledReturn.Get());
}

- (void)setSource:(WUCCompositionBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_Source(_getRtInterface<ABI::Windows::UI::Composition::ICompositionBrush>(value).Get()));
}

- (float)topInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_TopInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTopInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_TopInset(value));
}

- (float)topInsetScale {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->get_TopInsetScale(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTopInsetScale:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->put_TopInsetScale(value));
}

- (void)setInsets:(float)inset {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->SetInsets(inset));
}

- (void)setInsetsWithValues:(float)left top:(float)top right:(float)right bottom:(float)bottom {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->SetInsetsWithValues(left, top, right, bottom));
}

- (void)setInsetScales:(float)scale {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->SetInsetScales(scale));
}

- (void)setInsetScalesWithValues:(float)left top:(float)top right:(float)right bottom:(float)bottom {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionNineGridBrush>(self);
    THROW_NS_IF_FAILED(_comInst->SetInsetScalesWithValues(left, top, right, bottom));
}

@end

@implementation WUCCubicBezierEasingFunction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICubicBezierEasingFunction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector2*)controlPoint1 {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICubicBezierEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlPoint1(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (WFNVector2*)controlPoint2 {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICubicBezierEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->get_ControlPoint2(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

@end

@implementation WUCExpressionAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IExpressionAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)expression {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IExpressionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Expression(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setExpression:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IExpressionAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Expression(nsStrToHstr(value).Get()));
}

@end

@implementation WUCImplicitAnimationCollection {
    RTMapObj<HSTRING,
             HSTRING,
             ABI::Windows::UI::Composition::ICompositionAnimationBase*,
             ABI::Windows::UI::Composition::ICompositionAnimationBase*,
             NSString,
             RTObject<WUCICompositionAnimationBase>,
             IMap<HSTRING, ABI::Windows::UI::Composition::ICompositionAnimationBase*>,
             dummyObjCCreator,
             dummyObjCCreator,
             dummyWRLCreator,
             dummyWRLCreator>
        _map;
}
INTEROP_IMPL_MAP(self.comObj,
                 RTProxiedNSMutableDictionary_NSString_RTObject_WUCICompositionAnimationBase,
                 HSTRING,
                 HSTRING,
                 ABI::Windows::UI::Composition::ICompositionAnimationBase*,
                 ABI::Windows::UI::Composition::ICompositionAnimationBase*,
                 NSString,
                 RTObject<WUCICompositionAnimationBase>)

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IImplicitAnimationCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCLinearEasingFunction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ILinearEasingFunction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCRenderingDeviceReplacedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IRenderingDeviceReplacedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionGraphicsDevice*)graphicsDevice {
    ComPtr<ABI::Windows::UI::Composition::ICompositionGraphicsDevice> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IRenderingDeviceReplacedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_GraphicsDevice(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionGraphicsDevice>(unmarshalledReturn.Get());
}

@end

@implementation WUCCompositionShadow

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionShadow> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUCDropShadow

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IDropShadow> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (float)blurRadius {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->get_BlurRadius(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBlurRadius:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->put_BlurRadius(value));
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

- (WUCCompositionBrush*)mask {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Mask(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBrush>(unmarshalledReturn.Get());
}

- (void)setMask:(WUCCompositionBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->put_Mask(_getRtInterface<ABI::Windows::UI::Composition::ICompositionBrush>(value).Get()));
}

- (WFNVector3*)offset {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setOffset:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(*[value internalStruct]));
}

- (float)opacity {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpacity:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDropShadow>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opacity(value));
}

@end

@implementation WUCStepEasingFunction

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IStepEasingFunction> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)finalStep {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->get_FinalStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setFinalStep:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->put_FinalStep(value));
}

- (int)initialStep {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialStep(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInitialStep:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->put_InitialStep(value));
}

- (BOOL)isFinalStepSingleFrame {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsFinalStepSingleFrame(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsFinalStepSingleFrame:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsFinalStepSingleFrame((boolean)value));
}

- (BOOL)isInitialStepSingleFrame {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsInitialStepSingleFrame(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsInitialStepSingleFrame:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsInitialStepSingleFrame((boolean)value));
}

- (int)stepCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->get_StepCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setStepCount:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IStepEasingFunction>(self);
    THROW_NS_IF_FAILED(_comInst->put_StepCount(value));
}

@end

@implementation WUCVisual

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IVisual> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector2*)anchorPoint {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnchorPoint(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setAnchorPoint:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_AnchorPoint(*[value internalStruct]));
}

- (WUCCompositionBackfaceVisibility)backfaceVisibility {
    ABI::Windows::UI::Composition::CompositionBackfaceVisibility unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_BackfaceVisibility(&unmarshalledReturn));
    return (WUCCompositionBackfaceVisibility)unmarshalledReturn;
}

- (void)setBackfaceVisibility:(WUCCompositionBackfaceVisibility)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_BackfaceVisibility((ABI::Windows::UI::Composition::CompositionBackfaceVisibility)value));
}

- (WUCCompositionBorderMode)borderMode {
    ABI::Windows::UI::Composition::CompositionBorderMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_BorderMode(&unmarshalledReturn));
    return (WUCCompositionBorderMode)unmarshalledReturn;
}

- (void)setBorderMode:(WUCCompositionBorderMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_BorderMode((ABI::Windows::UI::Composition::CompositionBorderMode)value));
}

- (WFNVector3*)centerPoint {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterPoint(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setCenterPoint:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterPoint(*[value internalStruct]));
}

- (WUCCompositionClip*)clip {
    ComPtr<ABI::Windows::UI::Composition::ICompositionClip> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Clip(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionClip>(unmarshalledReturn.Get());
}

- (void)setClip:(WUCCompositionClip*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Clip(_getRtInterface<ABI::Windows::UI::Composition::ICompositionClip>(value).Get()));
}

- (WUCCompositionCompositeMode)compositeMode {
    ABI::Windows::UI::Composition::CompositionCompositeMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompositeMode(&unmarshalledReturn));
    return (WUCCompositionCompositeMode)unmarshalledReturn;
}

- (void)setCompositeMode:(WUCCompositionCompositeMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_CompositeMode((ABI::Windows::UI::Composition::CompositionCompositeMode)value));
}

- (BOOL)isVisible {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsVisible(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsVisible:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsVisible((boolean)value));
}

- (WFNVector3*)offset {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setOffset:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(*[value internalStruct]));
}

- (float)opacity {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Opacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOpacity:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Opacity(value));
}

- (WFNQuaternion*)orientation {
    ABI::Windows::Foundation::Numerics::Quaternion unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return WFNQuaternion_create(unmarshalledReturn);
}

- (void)setOrientation:(WFNQuaternion*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Orientation(*[value internalStruct]));
}

- (WUCContainerVisual*)parent {
    ComPtr<ABI::Windows::UI::Composition::IContainerVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Parent(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCContainerVisual>(unmarshalledReturn.Get());
}

- (float)rotationAngle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationAngle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAngle(value));
}

- (float)rotationAngleInDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngleInDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationAngleInDegrees:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAngleInDegrees(value));
}

- (WFNVector3*)rotationAxis {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAxis(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setRotationAxis:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAxis(*[value internalStruct]));
}

- (WFNVector3*)scale {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scale(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setScale:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Scale(*[value internalStruct]));
}

- (WFNVector2*)size {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Size(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setSize:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Size(*[value internalStruct]));
}

- (WFNMatrix4x4*)transformMatrix {
    ABI::Windows::Foundation::Numerics::Matrix4x4 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransformMatrix(&unmarshalledReturn));
    return WFNMatrix4x4_create(unmarshalledReturn);
}

- (void)setTransformMatrix:(WFNMatrix4x4*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransformMatrix(*[value internalStruct]));
}

@end

@implementation WUCContainerVisual

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IContainerVisual> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCVisualCollection*)children {
    ComPtr<ABI::Windows::UI::Composition::IVisualCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IContainerVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Children(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisualCollection>(unmarshalledReturn.Get());
}

@end

@implementation WUCSpriteVisual

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ISpriteVisual> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionBrush*)brush {
    ComPtr<ABI::Windows::UI::Composition::ICompositionBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpriteVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Brush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionBrush>(unmarshalledReturn.Get());
}

- (void)setBrush:(WUCCompositionBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpriteVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Brush(_getRtInterface<ABI::Windows::UI::Composition::ICompositionBrush>(value).Get()));
}

- (WUCCompositionShadow*)shadow {
    ComPtr<ABI::Windows::UI::Composition::ICompositionShadow> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpriteVisual2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Shadow(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionShadow>(unmarshalledReturn.Get());
}

- (void)setShadow:(WUCCompositionShadow*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpriteVisual2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Shadow(_getRtInterface<ABI::Windows::UI::Composition::ICompositionShadow>(value).Get()));
}

@end

@implementation WUCLayerVisual

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ILayerVisual> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionEffectBrush*)effect {
    ComPtr<ABI::Windows::UI::Composition::ICompositionEffectBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ILayerVisual>(self);
    THROW_NS_IF_FAILED(_comInst->get_Effect(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionEffectBrush>(unmarshalledReturn.Get());
}

- (void)setEffect:(WUCCompositionEffectBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ILayerVisual>(self);
    THROW_NS_IF_FAILED(_comInst->put_Effect(_getRtInterface<ABI::Windows::UI::Composition::ICompositionEffectBrush>(value).Get()));
}

@end

@implementation WUCCompositionClip

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionClip> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFNVector2*)anchorPoint {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnchorPoint(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setAnchorPoint:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AnchorPoint(*[value internalStruct]));
}

- (WFNVector2*)centerPoint {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterPoint(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setCenterPoint:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CenterPoint(*[value internalStruct]));
}

- (WFNVector2*)offset {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setOffset:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(*[value internalStruct]));
}

- (float)rotationAngle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationAngle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAngle(value));
}

- (float)rotationAngleInDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->get_RotationAngleInDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRotationAngleInDegrees:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->put_RotationAngleInDegrees(value));
}

- (WFNVector2*)scale {
    ABI::Windows::Foundation::Numerics::Vector2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Scale(&unmarshalledReturn));
    return WFNVector2_create(unmarshalledReturn);
}

- (void)setScale:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Scale(*[value internalStruct]));
}

- (WFNMatrix3x2*)transformMatrix {
    ABI::Windows::Foundation::Numerics::Matrix3x2 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->get_TransformMatrix(&unmarshalledReturn));
    return WFNMatrix3x2_create(unmarshalledReturn);
}

- (void)setTransformMatrix:(WFNMatrix3x2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionClip2>(self);
    THROW_NS_IF_FAILED(_comInst->put_TransformMatrix(*[value internalStruct]));
}

@end

@implementation WUCInsetClip

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IInsetClip> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (float)bottomInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_BottomInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setBottomInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_BottomInset(value));
}

- (float)leftInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_LeftInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLeftInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_LeftInset(value));
}

- (float)rightInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_RightInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setRightInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_RightInset(value));
}

- (float)topInset {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->get_TopInset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setTopInset:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IInsetClip>(self);
    THROW_NS_IF_FAILED(_comInst->put_TopInset(value));
}

@end

@implementation WUCVisualCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IVisualCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Count(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)insertAbove:(WUCVisual*)newChild sibling:(WUCVisual*)sibling {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualCollection>(self);
    THROW_NS_IF_FAILED(_comInst->InsertAbove(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(newChild).Get(),
                                             _getRtInterface<ABI::Windows::UI::Composition::IVisual>(sibling).Get()));
}

- (void)insertAtBottom:(WUCVisual*)newChild {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualCollection>(self);
    THROW_NS_IF_FAILED(_comInst->InsertAtBottom(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(newChild).Get()));
}

- (void)insertAtTop:(WUCVisual*)newChild {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualCollection>(self);
    THROW_NS_IF_FAILED(_comInst->InsertAtTop(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(newChild).Get()));
}

- (void)insertBelow:(WUCVisual*)newChild sibling:(WUCVisual*)sibling {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualCollection>(self);
    THROW_NS_IF_FAILED(_comInst->InsertBelow(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(newChild).Get(),
                                             _getRtInterface<ABI::Windows::UI::Composition::IVisual>(sibling).Get()));
}

- (void)remove:(WUCVisual*)child {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualCollection>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(child).Get()));
}

- (void)removeAll {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualCollection>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAll());
}

@end

@implementation WUCVisualUnorderedCollection

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IVisualUnorderedCollection> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualUnorderedCollection>(self);
    THROW_NS_IF_FAILED(_comInst->get_Count(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)add:(WUCVisual*)newVisual {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualUnorderedCollection>(self);
    THROW_NS_IF_FAILED(_comInst->Add(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(newVisual).Get()));
}

- (void)remove:(WUCVisual*)visual {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualUnorderedCollection>(self);
    THROW_NS_IF_FAILED(_comInst->Remove(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(visual).Get()));
}

- (void)removeAll {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVisualUnorderedCollection>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveAll());
}

@end

@implementation WUCCompositionLight

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ICompositionLight> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCVisualUnorderedCollection*)targets {
    ComPtr<ABI::Windows::UI::Composition::IVisualUnorderedCollection> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ICompositionLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Targets(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisualUnorderedCollection>(unmarshalledReturn.Get());
}

@end

@implementation WUCAmbientLight

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IAmbientLight> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IAmbientLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IAmbientLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

@end

@implementation WUCDistantLight

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IDistantLight> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDistantLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDistantLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

- (WUCVisual*)coordinateSpace {
    ComPtr<ABI::Windows::UI::Composition::IVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDistantLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSpace(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisual>(unmarshalledReturn.Get());
}

- (void)setCoordinateSpace:(WUCVisual*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDistantLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_CoordinateSpace(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(value).Get()));
}

- (WFNVector3*)direction {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDistantLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direction(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setDirection:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IDistantLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_Direction(*[value internalStruct]));
}

@end

@implementation WUCPointLight

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IPointLight> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUColor*)color {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Color(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_Color(*[value internalStruct]));
}

- (float)constantAttenuation {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConstantAttenuation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setConstantAttenuation:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConstantAttenuation(value));
}

- (WUCVisual*)coordinateSpace {
    ComPtr<ABI::Windows::UI::Composition::IVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSpace(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisual>(unmarshalledReturn.Get());
}

- (void)setCoordinateSpace:(WUCVisual*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_CoordinateSpace(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(value).Get()));
}

- (float)linearAttenuation {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinearAttenuation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLinearAttenuation:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_LinearAttenuation(value));
}

- (WFNVector3*)offset {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setOffset:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(*[value internalStruct]));
}

- (float)quadraticAttenuation {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_QuadraticAttenuation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setQuadraticAttenuation:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IPointLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_QuadraticAttenuation(value));
}

@end

@implementation WUCSpotLight

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::ISpotLight> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (float)constantAttenuation {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_ConstantAttenuation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setConstantAttenuation:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_ConstantAttenuation(value));
}

- (WUCVisual*)coordinateSpace {
    ComPtr<ABI::Windows::UI::Composition::IVisual> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_CoordinateSpace(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisual>(unmarshalledReturn.Get());
}

- (void)setCoordinateSpace:(WUCVisual*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_CoordinateSpace(_getRtInterface<ABI::Windows::UI::Composition::IVisual>(value).Get()));
}

- (WFNVector3*)direction {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direction(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setDirection:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_Direction(*[value internalStruct]));
}

- (float)innerConeAngle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerConeAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInnerConeAngle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerConeAngle(value));
}

- (float)innerConeAngleInDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerConeAngleInDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInnerConeAngleInDegrees:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerConeAngleInDegrees(value));
}

- (WUColor*)innerConeColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_InnerConeColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setInnerConeColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_InnerConeColor(*[value internalStruct]));
}

- (float)linearAttenuation {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_LinearAttenuation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLinearAttenuation:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_LinearAttenuation(value));
}

- (WFNVector3*)offset {
    ABI::Windows::Foundation::Numerics::Vector3 unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_Offset(&unmarshalledReturn));
    return WFNVector3_create(unmarshalledReturn);
}

- (void)setOffset:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_Offset(*[value internalStruct]));
}

- (float)outerConeAngle {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_OuterConeAngle(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOuterConeAngle:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_OuterConeAngle(value));
}

- (float)outerConeAngleInDegrees {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_OuterConeAngleInDegrees(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setOuterConeAngleInDegrees:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_OuterConeAngleInDegrees(value));
}

- (WUColor*)outerConeColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_OuterConeColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (void)setOuterConeColor:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_OuterConeColor(*[value internalStruct]));
}

- (float)quadraticAttenuation {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->get_QuadraticAttenuation(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setQuadraticAttenuation:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::ISpotLight>(self);
    THROW_NS_IF_FAILED(_comInst->put_QuadraticAttenuation(value));
}

@end

@implementation WUCKeyFrameAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IKeyFrameAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFTimeSpan*)delayTime {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_DelayTime(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDelayTime:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_DelayTime(*[value internalStruct]));
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (void)setDuration:(WFTimeSpan*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Duration(*[value internalStruct]));
}

- (WUCAnimationIterationBehavior)iterationBehavior {
    ABI::Windows::UI::Composition::AnimationIterationBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IterationBehavior(&unmarshalledReturn));
    return (WUCAnimationIterationBehavior)unmarshalledReturn;
}

- (void)setIterationBehavior:(WUCAnimationIterationBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_IterationBehavior((ABI::Windows::UI::Composition::AnimationIterationBehavior)value));
}

- (int)iterationCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_IterationCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setIterationCount:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_IterationCount(value));
}

- (int)keyFrameCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_KeyFrameCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUCAnimationStopBehavior)stopBehavior {
    ABI::Windows::UI::Composition::AnimationStopBehavior unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_StopBehavior(&unmarshalledReturn));
    return (WUCAnimationStopBehavior)unmarshalledReturn;
}

- (void)setStopBehavior:(WUCAnimationStopBehavior)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_StopBehavior((ABI::Windows::UI::Composition::AnimationStopBehavior)value));
}

- (void)insertExpressionKeyFrame:(float)normalizedProgressKey value:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertExpressionKeyFrame(normalizedProgressKey, nsStrToHstr(value).Get()));
}

- (void)insertExpressionKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                             value:(NSString*)value
                                    easingFunction:(WUCCompositionEasingFunction*)easingFunction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertExpressionKeyFrameWithEasingFunction(
        normalizedProgressKey,
        nsStrToHstr(value).Get(),
        _getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(easingFunction).Get()));
}

- (WUCAnimationDirection)direction {
    ABI::Windows::UI::Composition::AnimationDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Direction(&unmarshalledReturn));
    return (WUCAnimationDirection)unmarshalledReturn;
}

- (void)setDirection:(WUCAnimationDirection)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IKeyFrameAnimation2>(self);
    THROW_NS_IF_FAILED(_comInst->put_Direction((ABI::Windows::UI::Composition::AnimationDirection)value));
}

@end

@implementation WUCColorKeyFrameAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IColorKeyFrameAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCCompositionColorSpace)interpolationColorSpace {
    ABI::Windows::UI::Composition::CompositionColorSpace unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IColorKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InterpolationColorSpace(&unmarshalledReturn));
    return (WUCCompositionColorSpace)unmarshalledReturn;
}

- (void)setInterpolationColorSpace:(WUCCompositionColorSpace)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IColorKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->put_InterpolationColorSpace((ABI::Windows::UI::Composition::CompositionColorSpace)value));
}

- (void)insertKeyFrame:(float)normalizedProgressKey value:(WUColor*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IColorKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrame(normalizedProgressKey, *[value internalStruct]));
}

- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WUColor*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IColorKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrameWithEasingFunction(
        normalizedProgressKey,
        *[value internalStruct],
        _getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(easingFunction).Get()));
}

@end

@implementation WUCQuaternionKeyFrameAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IQuaternionKeyFrameAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNQuaternion*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IQuaternionKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrame(normalizedProgressKey, *[value internalStruct]));
}

- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WFNQuaternion*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IQuaternionKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrameWithEasingFunction(
        normalizedProgressKey,
        *[value internalStruct],
        _getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(easingFunction).Get()));
}

@end

@implementation WUCScalarKeyFrameAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IScalarKeyFrameAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)insertKeyFrame:(float)normalizedProgressKey value:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IScalarKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrame(normalizedProgressKey, value));
}

- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(float)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IScalarKeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrameWithEasingFunction(
        normalizedProgressKey, value, _getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(easingFunction).Get()));
}

@end

@implementation WUCVector2KeyFrameAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IVector2KeyFrameAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector2*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVector2KeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrame(normalizedProgressKey, *[value internalStruct]));
}

- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WFNVector2*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVector2KeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrameWithEasingFunction(
        normalizedProgressKey,
        *[value internalStruct],
        _getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(easingFunction).Get()));
}

@end

@implementation WUCVector3KeyFrameAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IVector3KeyFrameAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector3*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVector3KeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrame(normalizedProgressKey, *[value internalStruct]));
}

- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WFNVector3*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVector3KeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrameWithEasingFunction(
        normalizedProgressKey,
        *[value internalStruct],
        _getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(easingFunction).Get()));
}

@end

@implementation WUCVector4KeyFrameAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::IVector4KeyFrameAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)insertKeyFrame:(float)normalizedProgressKey value:(WFNVector4*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVector4KeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrame(normalizedProgressKey, *[value internalStruct]));
}

- (void)insertKeyFrameWithEasingFunction:(float)normalizedProgressKey
                                   value:(WFNVector4*)value
                          easingFunction:(WUCCompositionEasingFunction*)easingFunction {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::IVector4KeyFrameAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->InsertKeyFrameWithEasingFunction(
        normalizedProgressKey,
        *[value internalStruct],
        _getRtInterface<ABI::Windows::UI::Composition::ICompositionEasingFunction>(easingFunction).Get()));
}

@end

id RTProxiedIterableNSArray_NSString_create(IInspectable* val) {
    std::unique_ptr<IterableArrayAdapter> adapter = std::make_unique<
        IterableArrayAdapterObj<IIterable<HSTRING>,
                                RTIterableObj<HSTRING, IIterable<HSTRING>, NSString, HSTRING, dummyObjCCreator, dummyWRLCreator>>>(val);
    return [[[RTProxiedIterableNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
