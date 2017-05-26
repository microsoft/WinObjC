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

// WindowsUICoreAnimationMetrics.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Core.AnimationMetrics.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUICoreAnimationMetrics.h"
#include "WindowsUICoreAnimationMetrics_priv.h"

@implementation WUCAIPropertyAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCAPropertyAnimationType)type {
    ABI::Windows::UI::Core::AnimationMetrics::PropertyAnimationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUCAPropertyAnimationType)unmarshalledReturn;
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFPoint*)control1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)control2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUCAAnimationDescription

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

static ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescriptionFactory> WUCAIAnimationDescriptionFactory_inst() {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescriptionFactory> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Core.AnimationMetrics.AnimationDescription").Get(), &inst));
    return inst;
}

+ (WUCAAnimationDescription*)makeInstance:(WUCAAnimationEffect)effect target:(WUCAAnimationEffectTarget)target {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription> unmarshalledReturn;
    auto _comInst = WUCAIAnimationDescriptionFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateInstance((ABI::Windows::UI::Core::AnimationMetrics::AnimationEffect)effect,
                                                (ABI::Windows::UI::Core::AnimationMetrics::AnimationEffectTarget)target,
                                                unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUCAAnimationDescription>(unmarshalledReturn.Get()) retain];
}

- (NSArray* /* RTObject<WUCAIPropertyAnimation>* */)animations {
    ComPtr<IVectorView<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_Animations(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_RTObject_WUCAIPropertyAnimation_create(unmarshalledReturn.Get());
}

- (WFTimeSpan*)staggerDelay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_StaggerDelay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (float)staggerDelayFactor {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_StaggerDelayFactor(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFTimeSpan*)delayLimit {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_DelayLimit(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (int)zOrder {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IAnimationDescription>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZOrder(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUCAPropertyAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCAPropertyAnimationType)type {
    ABI::Windows::UI::Core::AnimationMetrics::PropertyAnimationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUCAPropertyAnimationType)unmarshalledReturn;
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFPoint*)control1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)control2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUCAScaleAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IScaleAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* float */)initialScaleX {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IScaleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialScaleX(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (id /* float */)initialScaleY {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IScaleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialScaleY(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (float)finalScaleX {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IScaleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FinalScaleX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (float)finalScaleY {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IScaleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FinalScaleY(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFPoint*)normalizedOrigin {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IScaleAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalizedOrigin(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WUCAPropertyAnimationType)type {
    ABI::Windows::UI::Core::AnimationMetrics::PropertyAnimationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUCAPropertyAnimationType)unmarshalledReturn;
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFPoint*)control1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)control2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUCATranslationAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUCAPropertyAnimationType)type {
    ABI::Windows::UI::Core::AnimationMetrics::PropertyAnimationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUCAPropertyAnimationType)unmarshalledReturn;
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFPoint*)control1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)control2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

@implementation WUCAOpacityAnimation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Core::AnimationMetrics::IOpacityAnimation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (id /* float */)initialOpacity {
    ComPtr<IReference<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IOpacityAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_InitialOpacity(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<float, float>::convert(unmarshalledReturn.Get());
}

- (float)finalOpacity {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IOpacityAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_FinalOpacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUCAPropertyAnimationType)type {
    ABI::Windows::UI::Core::AnimationMetrics::PropertyAnimationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUCAPropertyAnimationType)unmarshalledReturn;
}

- (WFTimeSpan*)delay {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFTimeSpan*)duration {
    ABI::Windows::Foundation::TimeSpan unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Duration(&unmarshalledReturn));
    return WFTimeSpan_create(unmarshalledReturn);
}

- (WFPoint*)control1 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control1(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

- (WFPoint*)control2 {
    ABI::Windows::Foundation::Point unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Control2(&unmarshalledReturn));
    return WFPoint_create(unmarshalledReturn);
}

@end

id RTProxiedNSArray_RTObject_WUCAIPropertyAnimation_create(IInspectable* val) {
    std::unique_ptr<ArrayAdapter> adapter =
        std::make_unique<ArrayAdapterObj<IVectorView<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation*>,
                                         RTArrayObj<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation*,
                                                    IVectorView<ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation*>,
                                                    RTObject<WUCAIPropertyAnimation>,
                                                    ABI::Windows::UI::Core::AnimationMetrics::IPropertyAnimation*,
                                                    dummyObjCCreator,
                                                    dummyWRLCreator>>>(val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
