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

// WindowsUIXamlAutomation.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Automation.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlAutomation.h"
#include "WindowsUIXamlAutomation_priv.h"

@implementation WUXAAutomationProperty

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXAAnnotationPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiersStatics> WUXAIAnnotationPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAnnotationPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.AnnotationPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)annotationTypeIdProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAnnotationPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AnnotationTypeIdProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)annotationTypeNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAnnotationPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AnnotationTypeNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)authorProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAnnotationPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AuthorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)dateTimeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAnnotationPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DateTimeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)targetProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAnnotationPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TargetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAAutomationElementIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics4> WUXAIAutomationElementIdentifiersStatics4_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics4> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationElementIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)landmarkTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_LandmarkTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)localizedLandmarkTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalizedLandmarkTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics> WUXAIAutomationElementIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationElementIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)acceleratorKeyProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AcceleratorKeyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)accessKeyProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccessKeyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)automationIdProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutomationIdProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)boundingRectangleProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_BoundingRectangleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)classNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClassNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)clickablePointProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClickablePointProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)controlTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ControlTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)hasKeyboardFocusProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HasKeyboardFocusProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)helpTextProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HelpTextProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isContentElementProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsContentElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isControlElementProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsControlElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isKeyboardFocusableProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsKeyboardFocusableProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isOffscreenProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsOffscreenProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isPasswordProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPasswordProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isRequiredForFormProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsRequiredForFormProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)itemStatusProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemStatusProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)itemTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)labeledByProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LabeledByProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)localizedControlTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalizedControlTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)nameProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)orientationProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OrientationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)liveSettingProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LiveSettingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics3> WUXAIAutomationElementIdentifiersStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics3> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationElementIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)positionInSetProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_PositionInSetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)sizeOfSetProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_SizeOfSetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)levelProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_LevelProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)annotationsProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_AnnotationsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics5> WUXAIAutomationElementIdentifiersStatics5_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics5> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationElementIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)isPeripheralProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPeripheralProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isDataValidForFormProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsDataValidForFormProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)fullDescriptionProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_FullDescriptionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)describedByProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_DescribedByProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)flowsToProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_FlowsToProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)flowsFromProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_FlowsFromProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics2> WUXAIAutomationElementIdentifiersStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationElementIdentifiersStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationElementIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)controlledPeersProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationElementIdentifiersStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ControlledPeersProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAAutomationProperties

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperties> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics2> WUXAIAutomationPropertiesStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationProperties").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)accessibilityViewProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccessibilityViewProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WUXAPAccessibilityView)getAccessibilityView:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::Automation::Peers::AccessibilityView unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetAccessibilityView(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WUXAPAccessibilityView)unmarshalledReturn;
}

+ (void)setAccessibilityView:(WXDependencyObject*)element value:(WUXAPAccessibilityView)value {
    auto _comInst = WUXAIAutomationPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->SetAccessibilityView(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                      (ABI::Windows::UI::Xaml::Automation::Peers::AccessibilityView)value));
}

+ (WXDependencyProperty*)controlledPeersProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ControlledPeersProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WXUIElement* */)getControlledPeers:(WXDependencyObject*)element {
    ComPtr<IVector<ABI::Windows::UI::Xaml::UIElement*>> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->GetControlledPeers(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                    unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXUIElement_create(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics4> WUXAIAutomationPropertiesStatics4_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics4> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationProperties").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)landmarkTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_LandmarkTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WUXAPAutomationLandmarkType)getLandmarkType:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics4_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetLandmarkType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WUXAPAutomationLandmarkType)unmarshalledReturn;
}

+ (void)setLandmarkType:(WXDependencyObject*)element value:(WUXAPAutomationLandmarkType)value {
    auto _comInst = WUXAIAutomationPropertiesStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->SetLandmarkType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                 (ABI::Windows::UI::Xaml::Automation::Peers::AutomationLandmarkType)value));
}

+ (WXDependencyProperty*)localizedLandmarkTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalizedLandmarkTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getLocalizedLandmarkType:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics4_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetLocalizedLandmarkType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setLocalizedLandmarkType:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics4_inst();
    THROW_NS_IF_FAILED(_comInst->SetLocalizedLandmarkType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                          nsStrToHstr(value).Get()));
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics> WUXAIAutomationPropertiesStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationProperties").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)acceleratorKeyProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AcceleratorKeyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getAcceleratorKey:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetAcceleratorKey(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setAcceleratorKey:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetAcceleratorKey(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)accessKeyProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AccessKeyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getAccessKey:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetAccessKey(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setAccessKey:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetAccessKey(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)automationIdProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AutomationIdProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getAutomationId:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetAutomationId(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setAutomationId:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetAutomationId(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)helpTextProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HelpTextProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getHelpText:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetHelpText(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setHelpText:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetHelpText(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)isRequiredForFormProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsRequiredForFormProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsRequiredForForm:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIsRequiredForForm(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setIsRequiredForForm:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetIsRequiredForForm(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)itemStatusProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemStatusProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getItemStatus:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetItemStatus(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setItemStatus:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetItemStatus(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)itemTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getItemType:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetItemType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setItemType:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetItemType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)labeledByProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LabeledByProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXUIElement*)getLabeledBy:(WXDependencyObject*)element {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLabeledBy(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

+ (void)setLabeledBy:(WXDependencyObject*)element value:(WXUIElement*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetLabeledBy(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                              _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

+ (WXDependencyProperty*)nameProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getName:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetName(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setName:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetName(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)liveSettingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LiveSettingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WUXAPAutomationLiveSetting)getLiveSetting:(WXDependencyObject*)element {
    ABI::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetLiveSetting(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (WUXAPAutomationLiveSetting)unmarshalledReturn;
}

+ (void)setLiveSetting:(WXDependencyObject*)element value:(WUXAPAutomationLiveSetting)value {
    auto _comInst = WUXAIAutomationPropertiesStatics_inst();
    THROW_NS_IF_FAILED(_comInst->SetLiveSetting(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                (ABI::Windows::UI::Xaml::Automation::Peers::AutomationLiveSetting)value));
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics5> WUXAIAutomationPropertiesStatics5_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics5> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationProperties").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)isPeripheralProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPeripheralProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsPeripheral:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIsPeripheral(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setIsPeripheral:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetIsPeripheral(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)isDataValidForFormProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsDataValidForFormProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsDataValidForForm:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIsDataValidForForm(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

+ (void)setIsDataValidForForm:(WXDependencyObject*)element value:(BOOL)value {
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetIsDataValidForForm(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), (boolean)value));
}

+ (WXDependencyProperty*)fullDescriptionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_FullDescriptionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getFullDescription:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetFullDescription(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setFullDescription:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetFullDescription(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)localizedControlTypeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_LocalizedControlTypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getLocalizedControlType:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetLocalizedControlType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setLocalizedControlType:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->SetLocalizedControlType(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                         nsStrToHstr(value).Get()));
}

+ (WXDependencyProperty*)describedByProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_DescribedByProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WXDependencyObject* */)getDescribedBy:(WXDependencyObject*)element {
    ComPtr<IVector<ABI::Windows::UI::Xaml::DependencyObject*>> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->GetDescribedBy(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXDependencyObject_create(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)flowsToProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_FlowsToProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WXDependencyObject* */)getFlowsTo:(WXDependencyObject*)element {
    ComPtr<IVector<ABI::Windows::UI::Xaml::DependencyObject*>> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetFlowsTo(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXDependencyObject_create(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)flowsFromProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->get_FlowsFromProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WXDependencyObject* */)getFlowsFrom:(WXDependencyObject*)element {
    ComPtr<IVector<ABI::Windows::UI::Xaml::DependencyObject*>> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics5_inst();
    THROW_NS_IF_FAILED(_comInst->GetFlowsFrom(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                              unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WXDependencyObject_create(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics3> WUXAIAutomationPropertiesStatics3_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationPropertiesStatics3> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationProperties").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)positionInSetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_PositionInSetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (int)getPositionInSet:(WXDependencyObject*)element {
    int unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetPositionInSet(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setPositionInSet:(WXDependencyObject*)element value:(int)value {
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->SetPositionInSet(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), value));
}

+ (WXDependencyProperty*)sizeOfSetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_SizeOfSetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (int)getSizeOfSet:(WXDependencyObject*)element {
    int unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetSizeOfSet(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setSizeOfSet:(WXDependencyObject*)element value:(int)value {
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->SetSizeOfSet(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), value));
}

+ (WXDependencyProperty*)levelProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_LevelProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (int)getLevel:(WXDependencyObject*)element {
    int unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetLevel(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return unmarshalledReturn;
}

+ (void)setLevel:(WXDependencyObject*)element value:(int)value {
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->SetLevel(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), value));
}

+ (WXDependencyProperty*)annotationsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->get_AnnotationsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSMutableArray* /* WUXAAutomationAnnotation* */)getAnnotations:(WXDependencyObject*)element {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Automation::AutomationAnnotation*>> unmarshalledReturn;
    auto _comInst = WUXAIAutomationPropertiesStatics3_inst();
    THROW_NS_IF_FAILED(_comInst->GetAnnotations(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(),
                                                unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_WUXAAutomationAnnotation_create(unmarshalledReturn.Get());
}

@end

@implementation WUXADockPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IDockPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IDockPatternIdentifiersStatics> WUXAIDockPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IDockPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.DockPatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)dockPositionProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIDockPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DockPositionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXADragPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IDragPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IDragPatternIdentifiersStatics> WUXAIDragPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IDragPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.DragPatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)dropEffectProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIDragPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DropEffectProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)dropEffectsProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIDragPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DropEffectsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)grabbedItemsProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIDragPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GrabbedItemsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isGrabbedProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIDragPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsGrabbedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXADropTargetPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiersStatics> WUXAIDropTargetPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IDropTargetPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.DropTargetPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)dropTargetEffectProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIDropTargetPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DropTargetEffectProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)dropTargetEffectsProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIDropTargetPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DropTargetEffectsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAExpandCollapsePatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiersStatics> WUXAIExpandCollapsePatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IExpandCollapsePatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.ExpandCollapsePatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)expandCollapseStateProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIExpandCollapsePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExpandCollapseStateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAGridItemPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IGridItemPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IGridItemPatternIdentifiersStatics> WUXAIGridItemPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IGridItemPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.GridItemPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)columnProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIGridItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColumnProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)columnSpanProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIGridItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColumnSpanProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)containingGridProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIGridItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContainingGridProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)rowProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIGridItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RowProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)rowSpanProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIGridItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RowSpanProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAGridPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IGridPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IGridPatternIdentifiersStatics> WUXAIGridPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IGridPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.GridPatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)columnCountProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIGridPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColumnCountProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)rowCountProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIGridPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RowCountProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAMultipleViewPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiersStatics> WUXAIMultipleViewPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IMultipleViewPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.MultipleViewPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)currentViewProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIMultipleViewPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CurrentViewProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)supportedViewsProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIMultipleViewPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SupportedViewsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXARangeValuePatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiersStatics> WUXAIRangeValuePatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IRangeValuePatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.RangeValuePatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)isReadOnlyProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIRangeValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnlyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)largeChangeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIRangeValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LargeChangeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)maximumProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIRangeValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaximumProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)minimumProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIRangeValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinimumProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)smallChangeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIRangeValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SmallChangeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)valueProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIRangeValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAScrollPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IScrollPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IScrollPatternIdentifiersStatics> WUXAIScrollPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IScrollPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.ScrollPatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)horizontallyScrollableProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIScrollPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HorizontallyScrollableProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)horizontalScrollPercentProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIScrollPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HorizontalScrollPercentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)horizontalViewSizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIScrollPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HorizontalViewSizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (double)noScroll {
    double unmarshalledReturn;
    auto _comInst = WUXAIScrollPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_NoScroll(&unmarshalledReturn));
    return unmarshalledReturn;
}

+ (WUXAAutomationProperty*)verticallyScrollableProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIScrollPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VerticallyScrollableProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)verticalScrollPercentProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIScrollPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VerticalScrollPercentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)verticalViewSizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIScrollPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VerticalViewSizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXASelectionItemPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiersStatics> WUXAISelectionItemPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionItemPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.SelectionItemPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)isSelectedProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAISelectionItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsSelectedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)selectionContainerProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAISelectionItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectionContainerProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXASelectionPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionPatternIdentifiersStatics> WUXAISelectionPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ISelectionPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.SelectionPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)canSelectMultipleProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAISelectionPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanSelectMultipleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isSelectionRequiredProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAISelectionPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsSelectionRequiredProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)selectionProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAISelectionPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXASpreadsheetItemPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiersStatics> WUXAISpreadsheetItemPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ISpreadsheetItemPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.SpreadsheetItemPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)formulaProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAISpreadsheetItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FormulaProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAStylesPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IStylesPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IStylesPatternIdentifiersStatics> WUXAIStylesPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IStylesPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.StylesPatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)extendedPropertiesProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIStylesPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ExtendedPropertiesProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)fillColorProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIStylesPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillColorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)fillPatternColorProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIStylesPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillPatternColorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)fillPatternStyleProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIStylesPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillPatternStyleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)shapeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIStylesPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ShapeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)styleIdProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIStylesPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StyleIdProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)styleNameProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIStylesPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_StyleNameProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXATableItemPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITableItemPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ITableItemPatternIdentifiersStatics> WUXAITableItemPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITableItemPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.TableItemPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)columnHeaderItemsProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITableItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColumnHeaderItemsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)rowHeaderItemsProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITableItemPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RowHeaderItemsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXATablePatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITablePatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ITablePatternIdentifiersStatics> WUXAITablePatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITablePatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.TablePatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)columnHeadersProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITablePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ColumnHeadersProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)rowHeadersProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITablePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RowHeadersProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)rowOrColumnMajorProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITablePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_RowOrColumnMajorProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXATogglePatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITogglePatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ITogglePatternIdentifiersStatics> WUXAITogglePatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITogglePatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.TogglePatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)toggleStateProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITogglePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ToggleStateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXATransformPattern2Identifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPattern2Identifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPattern2IdentifiersStatics> WUXAITransformPattern2IdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPattern2IdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.TransformPattern2Identifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)canZoomProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITransformPattern2IdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanZoomProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)zoomLevelProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITransformPattern2IdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevelProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)maxZoomProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITransformPattern2IdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaxZoomProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)minZoomProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITransformPattern2IdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinZoomProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXATransformPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPatternIdentifiersStatics> WUXAITransformPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::ITransformPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Automation.TransformPatternIdentifiers").Get(), &inst));
    return inst;
}

+ (WUXAAutomationProperty*)canMoveProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITransformPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanMoveProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)canResizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITransformPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanResizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)canRotateProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAITransformPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanRotateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAValuePatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IValuePatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IValuePatternIdentifiersStatics> WUXAIValuePatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IValuePatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.ValuePatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)isReadOnlyProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnlyProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)valueProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIValuePatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAWindowPatternIdentifiers

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IWindowPatternIdentifiers> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IWindowPatternIdentifiersStatics> WUXAIWindowPatternIdentifiersStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IWindowPatternIdentifiersStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.WindowPatternIdentifiers").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationProperty*)canMaximizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIWindowPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanMaximizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)canMinimizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIWindowPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CanMinimizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isModalProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIWindowPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsModalProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)isTopmostProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIWindowPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsTopmostProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)windowInteractionStateProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIWindowPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WindowInteractionStateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

+ (WUXAAutomationProperty*)windowVisualStateProperty {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationProperty> unmarshalledReturn;
    auto _comInst = WUXAIWindowPatternIdentifiersStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_WindowVisualStateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAAutomationProperty>(unmarshalledReturn.Get());
}

@end

@implementation WUXAAutomationAnnotation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationAnnotation").Get(), &out));
    return [_createRtProxy<WUXAAutomationAnnotation>(out.Get()) retain];
}

static ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationFactory> WUXAIAutomationAnnotationFactory_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationFactory> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationAnnotation").Get(),
                                                       &inst));
    return inst;
}

+ (WUXAAutomationAnnotation*)makeInstance:(WUXAAnnotationType)type {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation> unmarshalledReturn;
    auto _comInst = WUXAIAutomationAnnotationFactory_inst();
    THROW_NS_IF_FAILED(
        _comInst->CreateInstance((ABI::Windows::UI::Xaml::Automation::AnnotationType)type, unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAAutomationAnnotation>(unmarshalledReturn.Get()) retain];
}

+ (WUXAAutomationAnnotation*)makeWithElementParameter:(WUXAAnnotationType)type element:(WXUIElement*)element {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation> unmarshalledReturn;
    auto _comInst = WUXAIAutomationAnnotationFactory_inst();
    THROW_NS_IF_FAILED(_comInst->CreateWithElementParameter((ABI::Windows::UI::Xaml::Automation::AnnotationType)type,
                                                            _getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(element).Get(),
                                                            unmarshalledReturn.GetAddressOf()));
    return [_createRtProxy<WUXAAutomationAnnotation>(unmarshalledReturn.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationStatics> WUXAIAutomationAnnotationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotationStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Automation.AutomationAnnotation").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)typeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationAnnotationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TypeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)elementProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXAIAutomationAnnotationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ElementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXAAnnotationType)type {
    ABI::Windows::UI::Xaml::Automation::AnnotationType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Type(&unmarshalledReturn));
    return (WUXAAnnotationType)unmarshalledReturn;
}

- (void)setType:(WUXAAnnotationType)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Type((ABI::Windows::UI::Xaml::Automation::AnnotationType)value));
}

- (WXUIElement*)element {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->get_Element(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (void)setElement:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation>(self);
    THROW_NS_IF_FAILED(_comInst->put_Element(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

@end

id RTProxiedNSMutableArray_WUXAAutomationAnnotation_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::Automation::AutomationAnnotation*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::Automation::IAutomationAnnotation*,
                                                                  IVector<ABI::Windows::UI::Xaml::Automation::AutomationAnnotation*>,
                                                                  WUXAAutomationAnnotation,
                                                                  ABI::Windows::UI::Xaml::Automation::AutomationAnnotation*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WXDependencyObject_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::DependencyObject*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IDependencyObject*,
                                                                  IVector<ABI::Windows::UI::Xaml::DependencyObject*>,
                                                                  WXDependencyObject,
                                                                  ABI::Windows::UI::Xaml::DependencyObject*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSMutableArray_WXUIElement_create(IInspectable* val) {
    std::unique_ptr<MutableArrayAdapter> adapter =
        std::make_unique<MutableArrayAdapterObj<IVector<ABI::Windows::UI::Xaml::UIElement*>,
                                                RTMutableArrayObj<ABI::Windows::UI::Xaml::IUIElement*,
                                                                  IVector<ABI::Windows::UI::Xaml::UIElement*>,
                                                                  WXUIElement,
                                                                  ABI::Windows::UI::Xaml::UIElement*,
                                                                  dummyObjCCreator,
                                                                  dummyWRLCreator>>>(val);
    return [[[RTProxiedNSMutableArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
