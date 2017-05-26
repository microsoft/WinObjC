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

// WindowsUIXamlHosting.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Hosting.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlHosting.h"
#include "WindowsUIXamlHosting_priv.h"

@implementation WUXHIXamlUIPresenterHost

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)resolveFileResource:(NSString*)path {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost>(self);
    THROW_NS_IF_FAILED(_comInst->ResolveFileResource(nsStrToHstr(path).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUXHIXamlUIPresenterHost2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)getGenericXamlFilePath {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost2>(self);
    THROW_NS_IF_FAILED(_comInst->GetGenericXamlFilePath(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUXHIXamlUIPresenterHost3

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost3> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)resolveDictionaryResource:(WXResourceDictionary*)dictionary
                         dictionaryKey:(RTObject*)dictionaryKey
                        suggestedValue:(RTObject*)suggestedValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost3>(self);
    THROW_NS_IF_FAILED(_comInst->ResolveDictionaryResource(_getRtInterface<ABI::Windows::UI::Xaml::IResourceDictionary>(dictionary).Get(),
                                                           [dictionaryKey comObj].Get(),
                                                           [suggestedValue comObj].Get(),
                                                           unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WUXHElementCompositionPreview

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreview> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> WUXHIElementCompositionPreviewStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IElementCompositionPreviewStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Hosting.ElementCompositionPreview").Get(),
                                                       &inst));
    return inst;
}

+ (WUCVisual*)getElementVisual:(WXUIElement*)element {
    ComPtr<ABI::Windows::UI::Composition::IVisual> unmarshalledReturn;
    auto _comInst = WUXHIElementCompositionPreviewStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetElementVisual(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisual>(unmarshalledReturn.Get());
}

+ (WUCVisual*)getElementChildVisual:(WXUIElement*)element {
    ComPtr<ABI::Windows::UI::Composition::IVisual> unmarshalledReturn;
    auto _comInst = WUXHIElementCompositionPreviewStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetElementChildVisual(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(),
                                                       unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCVisual>(unmarshalledReturn.Get());
}

+ (void)setElementChildVisual:(WXUIElement*)element visual:(WUCVisual*)visual {
    auto _comInst = WUXHIElementCompositionPreviewStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetElementChildVisual(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(),
                                                       _getRtInterface<ABI::Windows::UI::Composition::IVisual>(visual).Get()));
}

+ (WUCCompositionPropertySet*)getScrollViewerManipulationPropertySet:(WXCScrollViewer*)scrollViewer {
    ComPtr<ABI::Windows::UI::Composition::ICompositionPropertySet> unmarshalledReturn;
    auto _comInst = WUXHIElementCompositionPreviewStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetScrollViewerManipulationPropertySet(
        _getRtInterface<ABI::Windows::UI::Xaml::Controls::IScrollViewer>(scrollViewer).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUCCompositionPropertySet>(unmarshalledReturn.Get());
}

@end

@implementation WUXHXamlUIPresenter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics> WUXHIXamlUIPresenterStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Hosting.XamlUIPresenter").Get(), &inst));
    return inst;
}

+ (BOOL)completeTimelinesAutomatically {
    boolean unmarshalledReturn;
    auto _comInst = WUXHIXamlUIPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CompleteTimelinesAutomatically(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setCompleteTimelinesAutomatically:(BOOL)value {
    auto _comInst = WUXHIXamlUIPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->put_CompleteTimelinesAutomatically((boolean)value));
}

+ (void)setHost:(RTObject<WUXHIXamlUIPresenterHost>*)host {
    auto _comInst = WUXHIXamlUIPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetHost(_getRtInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterHost>(host).Get()));
}

+ (void)notifyWindowSizeChanged {
    auto _comInst = WUXHIXamlUIPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->NotifyWindowSizeChanged());
}

ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics2> WUXHIXamlUIPresenterStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenterStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Hosting.XamlUIPresenter").Get(), &inst));
    return inst;
}

+ (WFRect*)getFlyoutPlacementTargetInfo:(WXFrameworkElement*)placementTarget
                     preferredPlacement:(WUXCPFlyoutPlacementMode)preferredPlacement
               targetPreferredPlacement:(WUXCPFlyoutPlacementMode*)targetPreferredPlacement
                         allowFallbacks:(BOOL*)allowFallbacks {
    ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode targetPreferredPlacementOutUnmarshaled;
    boolean allowFallbacksOutUnmarshaled;
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WUXHIXamlUIPresenterStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetFlyoutPlacementTargetInfo(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(placementTarget).Get(),
                                               (ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode)preferredPlacement,
                                               &targetPreferredPlacementOutUnmarshaled,
                                               &allowFallbacksOutUnmarshaled,
                                               &unmarshalledReturn));
    *targetPreferredPlacement = (WUXCPFlyoutPlacementMode)targetPreferredPlacementOutUnmarshaled;
    *allowFallbacks = (BOOL)allowFallbacksOutUnmarshaled;
    return WFRect_create(unmarshalledReturn);
}

+ (WFRect*)getFlyoutPlacement:(WFRect*)placementTargetBounds
                  controlSize:(WFSize*)controlSize
               minControlSize:(WFSize*)minControlSize
                containerRect:(WFRect*)containerRect
     targetPreferredPlacement:(WUXCPFlyoutPlacementMode)targetPreferredPlacement
               allowFallbacks:(BOOL)allowFallbacks
              chosenPlacement:(WUXCPFlyoutPlacementMode*)chosenPlacement {
    ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode chosenPlacementOutUnmarshaled;
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WUXHIXamlUIPresenterStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetFlyoutPlacement(*[placementTargetBounds internalStruct],
                                     *[controlSize internalStruct],
                                     *[minControlSize internalStruct],
                                     *[containerRect internalStruct],
                                     (ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode)targetPreferredPlacement,
                                     (boolean)allowFallbacks,
                                     &chosenPlacementOutUnmarshaled,
                                     &unmarshalledReturn));
    *chosenPlacement = (WUXCPFlyoutPlacementMode)chosenPlacementOutUnmarshaled;
    return WFRect_create(unmarshalledReturn);
}

- (WXUIElement*)rootElement {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_RootElement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (void)setRootElement:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_RootElement(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

- (NSString*)themeKey {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThemeKey(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setThemeKey:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ThemeKey(nsStrToHstr(value).Get()));
}

- (NSString*)themeResourcesXaml {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ThemeResourcesXaml(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setThemeResourcesXaml:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ThemeResourcesXaml(nsStrToHstr(value).Get()));
}

- (void)setSize:(int)width height:(int)height {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->SetSize(width, height));
}

- (void)render {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->Render());
}

- (void)present {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Hosting::IXamlUIPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->Present());
}

@end
