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

// WindowsUICompositionEffects.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Composition.Effects.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUICompositionEffects.h"
#include "WindowsUICompositionEffects_priv.h"

@implementation WUCESceneLightingEffect

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Composition.Effects.SceneLightingEffect").Get(), &out));
    return [_createRtProxy<WUCESceneLightingEffect>(out.Get()) retain];
}

- (float)ambientAmount {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_AmbientAmount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setAmbientAmount:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_AmbientAmount(value));
}

- (float)diffuseAmount {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_DiffuseAmount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDiffuseAmount:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_DiffuseAmount(value));
}

- (RTObject<WGEIGraphicsEffectSource>*)normalMapSource {
    ComPtr<ABI::Windows::Graphics::Effects::IGraphicsEffectSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_NormalMapSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WGEIGraphicsEffectSource>(unmarshalledReturn.Get());
}

- (void)setNormalMapSource:(RTObject<WGEIGraphicsEffectSource>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_NormalMapSource(_getRtInterface<ABI::Windows::Graphics::Effects::IGraphicsEffectSource>(value).Get()));
}

- (float)specularAmount {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpecularAmount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpecularAmount:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpecularAmount(value));
}

- (float)specularShine {
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_SpecularShine(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSpecularShine:(float)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Composition::Effects::ISceneLightingEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_SpecularShine(value));
}

- (NSString*)name {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Effects::IGraphicsEffect>(self);
    THROW_NS_IF_FAILED(_comInst->get_Name(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setName:(NSString*)name {
    auto _comInst = _getInnerInterface<ABI::Windows::Graphics::Effects::IGraphicsEffect>(self);
    THROW_NS_IF_FAILED(_comInst->put_Name(nsStrToHstr(name).Get()));
}

@end
