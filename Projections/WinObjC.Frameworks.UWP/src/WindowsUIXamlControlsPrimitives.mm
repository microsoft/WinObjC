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

// WindowsUIXamlControlsPrimitives.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Controls.Primitives.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUIXamlControlsPrimitives_priv.h"

@implementation WUXCPIScrollSnapPointsInfo

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)areHorizontalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreHorizontalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)areVerticalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreVerticalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_HorizontalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HorizontalSnapPointsChanged(token));
}

- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_VerticalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VerticalSnapPointsChanged(token));
}

- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment {
    ComPtr<IVectorView<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetIrregularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                        (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_Single_create(unmarshalledReturn.Get());
}

- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset {
    float offsetOutUnmarshaled;
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetRegularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                      (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                      &offsetOutUnmarshaled,
                                                      &unmarshalledReturn));
    *offset = offsetOutUnmarshaled;
    return unmarshalledReturn;
}

@end

@implementation WUXCPItemsChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)action {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Action(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXCPGeneratorPosition*)position {
    ABI::Windows::UI::Xaml::Controls::Primitives::GeneratorPosition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Position(&unmarshalledReturn));
    return WUXCPGeneratorPosition_create(unmarshalledReturn);
}

- (WUXCPGeneratorPosition*)oldPosition {
    ABI::Windows::UI::Xaml::Controls::Primitives::GeneratorPosition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldPosition(&unmarshalledReturn));
    return WUXCPGeneratorPosition_create(unmarshalledReturn);
}

- (int)itemCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)itemUICount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemUICount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPLayoutInformation

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILayoutInformation> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILayoutInformationStatics> WUXCPILayoutInformationStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILayoutInformationStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.LayoutInformation").Get(), &inst));
    return inst;
}

+ (WXUIElement*)getLayoutExceptionElement:(RTObject*)dispatcher {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = WUXCPILayoutInformationStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetLayoutExceptionElement([dispatcher comObj].Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

+ (WFRect*)getLayoutSlot:(WXFrameworkElement*)element {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = WUXCPILayoutInformationStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetLayoutSlot(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(element).Get(), &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

@end

@implementation WUXCPGeneratorPositionHelper

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGeneratorPositionHelper> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGeneratorPositionHelperStatics> WUXCPIGeneratorPositionHelperStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGeneratorPositionHelperStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.GeneratorPositionHelper").Get(), &inst));
    return inst;
}

+ (WUXCPGeneratorPosition*)fromIndexAndOffset:(int)index offset:(int)offset {
    ABI::Windows::UI::Xaml::Controls::Primitives::GeneratorPosition unmarshalledReturn;
    auto _comInst = WUXCPIGeneratorPositionHelperStatics_inst();
    THROW_NS_IF_FAILED(_comInst->FromIndexAndOffset(index, offset, &unmarshalledReturn));
    return WUXCPGeneratorPosition_create(unmarshalledReturn);
}

@end

@implementation WUXCPProgressRingTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)ellipseDiameter {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EllipseDiameter(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WXThickness*)ellipseOffset {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EllipseOffset(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (double)maxSideLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressRingTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxSideLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPToggleSwitchTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)knobCurrentToOnOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_KnobCurrentToOnOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)knobCurrentToOffOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_KnobCurrentToOffOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)knobOnToOffOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_KnobOnToOffOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)knobOffToOnOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_KnobOffToOnOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)curtainCurrentToOnOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurtainCurrentToOnOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)curtainCurrentToOffOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurtainCurrentToOffOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)curtainOnToOffOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurtainOnToOffOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)curtainOffToOnOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleSwitchTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurtainOffToOnOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPProgressBarTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)ellipseDiameter {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EllipseDiameter(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)ellipseOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EllipseOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)ellipseAnimationWellPosition {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EllipseAnimationWellPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)ellipseAnimationEndPosition {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_EllipseAnimationEndPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)containerAnimationStartPosition {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContainerAnimationStartPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)containerAnimationEndPosition {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContainerAnimationEndPosition(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)indicatorLengthDelta {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IProgressBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IndicatorLengthDelta(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPSettingsFlyoutTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXMBrush*)headerBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (WUXMBrush*)headerForeground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderForeground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (WUXMBrush*)borderBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_BorderBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (WXThickness*)borderThickness {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_BorderThickness(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (WUXMImageSource*)iconSource {
    ComPtr<ABI::Windows::UI::Xaml::Media::IImageSource> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_IconSource(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMImageSource>(unmarshalledReturn.Get());
}

- (WUXMATransitionCollection*)contentTransitions {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::Transition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISettingsFlyoutTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentTransitions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMATransitionCollection>(unmarshalledReturn.Get());
}

@end

@implementation WUXCPToolTipTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IToolTipTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)fromHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToolTipTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)fromVerticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToolTipTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_FromVerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPComboBoxTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)dropDownOpenedHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropDownOpenedHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)dropDownClosedHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropDownClosedHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)dropDownOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropDownOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXCPAnimationDirection)selectedItemDirection {
    ABI::Windows::UI::Xaml::Controls::Primitives::AnimationDirection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedItemDirection(&unmarshalledReturn));
    return (WUXCPAnimationDirection)unmarshalledReturn;
}

- (double)dropDownContentMinWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IComboBoxTemplateSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropDownContentMinWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPGridViewItemTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)dragItemsCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragItemsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPListViewItemTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)dragItemsCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragItemsCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPMenuFlyoutPresenterTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IMenuFlyoutPresenterTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)flyoutContentMinWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IMenuFlyoutPresenterTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_FlyoutContentMinWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPCalendarViewTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)minViewWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinViewWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)headerText {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HeaderText(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weekDay1 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekDay1(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weekDay2 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekDay2(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weekDay3 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekDay3(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weekDay4 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekDay4(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weekDay5 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekDay5(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weekDay6 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekDay6(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)weekDay7 {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_WeekDay7(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (BOOL)hasMoreContentAfter {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasMoreContentAfter(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasMoreContentBefore {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasMoreContentBefore(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)hasMoreViews {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HasMoreViews(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WFRect*)clipRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClipRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (double)centerX {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterX(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)centerY {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CenterY(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPSplitViewTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)openPaneLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenPaneLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)negativeOpenPaneLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_NegativeOpenPaneLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)openPaneLengthMinusCompactLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenPaneLengthMinusCompactLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)negativeOpenPaneLengthMinusCompactLength {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_NegativeOpenPaneLengthMinusCompactLength(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WXGridLength*)openPaneGridLength {
    ABI::Windows::UI::Xaml::GridLength unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OpenPaneGridLength(&unmarshalledReturn));
    return WXGridLength_create(unmarshalledReturn);
}

- (WXGridLength*)compactPaneGridLength {
    ABI::Windows::UI::Xaml::GridLength unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISplitViewTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompactPaneGridLength(&unmarshalledReturn));
    return WXGridLength_create(unmarshalledReturn);
}

@end

@implementation WUXCPAppBarTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WFRect*)clipRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClipRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (double)compactVerticalDelta {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompactVerticalDelta(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WXThickness*)compactRootMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_CompactRootMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (double)minimalVerticalDelta {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimalVerticalDelta(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WXThickness*)minimalRootMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinimalRootMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (double)hiddenVerticalDelta {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HiddenVerticalDelta(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WXThickness*)hiddenRootMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IAppBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_HiddenRootMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

@end

@implementation WUXCPCommandBarTemplateSettings

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)contentHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WFRect*)overflowContentClipRect {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverflowContentClipRect(&unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (double)overflowContentMinWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverflowContentMinWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)overflowContentMaxHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverflowContentMaxHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)overflowContentHorizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverflowContentHorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)overflowContentHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverflowContentHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)negativeOverflowContentHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings>(self);
    THROW_NS_IF_FAILED(_comInst->get_NegativeOverflowContentHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)overflowContentMaxWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings2>(self);
    THROW_NS_IF_FAILED(_comInst->get_OverflowContentMaxWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WXVisibility)effectiveOverflowButtonVisibility {
    ABI::Windows::UI::Xaml::Visibility unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICommandBarTemplateSettings3>(self);
    THROW_NS_IF_FAILED(_comInst->get_EffectiveOverflowButtonVisibility(&unmarshalledReturn));
    return (WXVisibility)unmarshalledReturn;
}

@end

@implementation WUXCPDragCompletedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXCPDragCompletedEventArgs*)makeInstanceWithHorizontalChangeVerticalChangeAndCanceled:(double)horizontalChange
                                                                           verticalChange:(double)verticalChange
                                                                                 canceled:(BOOL)canceled {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgsFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.DragCompletedEventArgs").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(factory->CreateInstanceWithHorizontalChangeVerticalChangeAndCanceled(
        horizontalChange, verticalChange, (boolean)canceled, outer.Get(), &inner, &instance));
    WUXCPDragCompletedEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (double)horizontalChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)canceled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IDragCompletedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Canceled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXCPDragDeltaEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXCPDragDeltaEventArgs*)makeInstanceWithHorizontalChangeAndVerticalChange:(double)horizontalChange
                                                               verticalChange:(double)verticalChange {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgsFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.DragDeltaEventArgs").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithHorizontalChangeAndVerticalChange(horizontalChange, verticalChange, outer.Get(), &inner, &instance));
    WUXCPDragDeltaEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (double)horizontalChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IDragDeltaEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPDragStartedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (WUXCPDragStartedEventArgs*)makeInstanceWithHorizontalOffsetAndVerticalOffset:(double)horizontalOffset
                                                                 verticalOffset:(double)verticalOffset {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgsFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.DragStartedEventArgs").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    THROW_NS_IF_FAILED(
        factory->CreateInstanceWithHorizontalOffsetAndVerticalOffset(horizontalOffset, verticalOffset, outer.Get(), &inner, &instance));
    WUXCPDragStartedEventArgs* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    return ret;
}

- (double)horizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IDragStartedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPRangeBaseValueChangedEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (double)oldValue {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_OldValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)newValue {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXCPScrollEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ScrollEventArgs").Get(), &out));
    return [_createRtProxy<WUXCPScrollEventArgs>(out.Get()) retain];
}

- (double)newValue {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_NewValue(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXCPScrollEventType)scrollEventType {
    ABI::Windows::UI::Xaml::Controls::Primitives::ScrollEventType unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScrollEventType(&unmarshalledReturn));
    return (WUXCPScrollEventType)unmarshalledReturn;
}

@end

@implementation WUXCPPopup

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.Popup").Get(), &out));
    return [_createRtProxy<WUXCPPopup>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPopupStatics> WUXCPIPopupStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPopupStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.Popup").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)childProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPopupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChildProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isOpenProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPopupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsOpenProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)horizontalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPopupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_HorizontalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)verticalOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPopupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_VerticalOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)childTransitionsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPopupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ChildTransitionsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isLightDismissEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPopupStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsLightDismissEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPopupStatics2> WUXCPIPopupStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPopupStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.Popup").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)lightDismissOverlayModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPopupStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightDismissOverlayModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WXUIElement*)child {
    ComPtr<ABI::Windows::UI::Xaml::IUIElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->get_Child(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXUIElement>(unmarshalledReturn.Get());
}

- (void)setChild:(WXUIElement*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->put_Child(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(value).Get()));
}

- (BOOL)isOpen {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsOpen(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsOpen:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsOpen((boolean)value));
}

- (double)horizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setHorizontalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->put_HorizontalOffset(value));
}

- (double)verticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setVerticalOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->put_VerticalOffset(value));
}

- (WUXMATransitionCollection*)childTransitions {
    ComPtr<IVector<ABI::Windows::UI::Xaml::Media::Animation::Transition*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->get_ChildTransitions(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMATransitionCollection>(unmarshalledReturn.Get());
}

- (void)setChildTransitions:(WUXMATransitionCollection*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(
        _comInst->put_ChildTransitions(_getRtInterface<IVector<ABI::Windows::UI::Xaml::Media::Animation::Transition*>>(value).Get()));
}

- (BOOL)isLightDismissEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsLightDismissEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsLightDismissEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsLightDismissEnabled((boolean)value));
}

- (EventRegistrationToken)addOpenedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->add_Opened(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Opened(token));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(token));
}

- (WXCLightDismissOverlayMode)lightDismissOverlayMode {
    ABI::Windows::UI::Xaml::Controls::LightDismissOverlayMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LightDismissOverlayMode(&unmarshalledReturn));
    return (WXCLightDismissOverlayMode)unmarshalledReturn;
}

- (void)setLightDismissOverlayMode:(WXCLightDismissOverlayMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPopup2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LightDismissOverlayMode((ABI::Windows::UI::Xaml::Controls::LightDismissOverlayMode)value));
}

@end

@implementation WUXCPTickBar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ITickBar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.TickBar").Get(), &out));
    return [_createRtProxy<WUXCPTickBar>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ITickBarStatics> WUXCPITickBarStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ITickBarStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.TickBar").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)fillProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPITickBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FillProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMBrush*)fill {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ITickBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Fill(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFill:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ITickBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Fill(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

@end

@implementation WUXCPCarouselPanel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanelFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.CarouselPanel").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WXCIVirtualizingPanelOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WXCIVirtualizingPanelOverrides)]) {
        typedOuter = Make<WXCIVirtualizingPanelOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCPCarouselPanel* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

- (BOOL)canVerticallyScroll {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanVerticallyScroll(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanVerticallyScroll:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanVerticallyScroll((boolean)value));
}

- (BOOL)canHorizontallyScroll {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanHorizontallyScroll(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanHorizontallyScroll:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanHorizontallyScroll((boolean)value));
}

- (double)extentWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtentWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)extentHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtentHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)viewportWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewportWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)viewportHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewportHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)horizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject*)scrollOwner {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScrollOwner(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setScrollOwner:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScrollOwner([value comObj].Get()));
}

- (void)lineUp {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineUp());
}

- (void)lineDown {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineDown());
}

- (void)lineLeft {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineLeft());
}

- (void)lineRight {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineRight());
}

- (void)pageUp {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageUp());
}

- (void)pageDown {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageDown());
}

- (void)pageLeft {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageLeft());
}

- (void)pageRight {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageRight());
}

- (void)mouseWheelUp {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelUp());
}

- (void)mouseWheelDown {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelDown());
}

- (void)mouseWheelLeft {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelLeft());
}

- (void)mouseWheelRight {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelRight());
}

- (void)setHorizontalOffset:(double)offset {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->SetHorizontalOffset(offset));
}

- (void)setVerticalOffset:(double)offset {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->SetVerticalOffset(offset));
}

- (WFRect*)makeVisible:(WXUIElement*)visual rectangle:(WFRect*)rectangle {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ICarouselPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MakeVisible(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(visual).Get(),
                                             *[rectangle internalStruct],
                                             &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)areHorizontalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreHorizontalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)areVerticalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreVerticalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_HorizontalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HorizontalSnapPointsChanged(token));
}

- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_VerticalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VerticalSnapPointsChanged(token));
}

- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment {
    ComPtr<IVectorView<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetIrregularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                        (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_Single_create(unmarshalledReturn.Get());
}

- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset {
    float offsetOutUnmarshaled;
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetRegularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                      (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                      &offsetOutUnmarshaled,
                                                      &unmarshalledReturn));
    *offset = offsetOutUnmarshaled;
    return unmarshalledReturn;
}

@end

@implementation WUXCPOrientedVirtualizingPanel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canVerticallyScroll {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanVerticallyScroll(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanVerticallyScroll:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanVerticallyScroll((boolean)value));
}

- (BOOL)canHorizontallyScroll {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanHorizontallyScroll(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCanHorizontallyScroll:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->put_CanHorizontallyScroll((boolean)value));
}

- (double)extentWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtentWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)extentHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtentHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)viewportWidth {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewportWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)viewportHeight {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewportHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)horizontalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (RTObject*)scrollOwner {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->get_ScrollOwner(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setScrollOwner:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->put_ScrollOwner([value comObj].Get()));
}

- (void)lineUp {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineUp());
}

- (void)lineDown {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineDown());
}

- (void)lineLeft {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineLeft());
}

- (void)lineRight {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->LineRight());
}

- (void)pageUp {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageUp());
}

- (void)pageDown {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageDown());
}

- (void)pageLeft {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageLeft());
}

- (void)pageRight {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->PageRight());
}

- (void)mouseWheelUp {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelUp());
}

- (void)mouseWheelDown {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelDown());
}

- (void)mouseWheelLeft {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelLeft());
}

- (void)mouseWheelRight {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MouseWheelRight());
}

- (void)setHorizontalOffset:(double)offset {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->SetHorizontalOffset(offset));
}

- (void)setVerticalOffset:(double)offset {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->SetVerticalOffset(offset));
}

- (WFRect*)makeVisible:(WXUIElement*)visual rectangle:(WFRect*)rectangle {
    ABI::Windows::Foundation::Rect unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IOrientedVirtualizingPanel>(self);
    THROW_NS_IF_FAILED(_comInst->MakeVisible(_getRtInterface<ABI::Windows::UI::Xaml::IUIElement>(visual).Get(),
                                             *[rectangle internalStruct],
                                             &unmarshalledReturn));
    return WFRect_create(unmarshalledReturn);
}

- (BOOL)areHorizontalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreHorizontalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)areVerticalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreVerticalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_HorizontalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HorizontalSnapPointsChanged(token));
}

- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_VerticalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VerticalSnapPointsChanged(token));
}

- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment {
    ComPtr<IVectorView<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetIrregularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                        (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_Single_create(unmarshalledReturn.Get());
}

- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset {
    float offsetOutUnmarshaled;
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetRegularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                      (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                      &offsetOutUnmarshaled,
                                                      &unmarshalledReturn));
    *offset = offsetOutUnmarshaled;
    return unmarshalledReturn;
}

- (void)getInsertionIndexes:(WFPoint*)position first:(int*)first second:(int*)second {
    int firstOutUnmarshaled;
    int secondOutUnmarshaled;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::IInsertionPanel>(self);
    THROW_NS_IF_FAILED(_comInst->GetInsertionIndexes(*[position internalStruct], &firstOutUnmarshaled, &secondOutUnmarshaled));
    *first = firstOutUnmarshaled;
    *second = secondOutUnmarshaled;
}

@end

@implementation WUXCPCalendarPanel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ICalendarPanel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.CalendarPanel").Get(), &out));
    return [_createRtProxy<WUXCPCalendarPanel>(out.Get()) retain];
}

@end

@implementation WUXCPGridViewItemPresenter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenterFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.GridViewItemPresenter").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WXCIContentPresenterOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WXCIContentPresenterOverrides)]) {
        typedOuter = Make<WXCIContentPresenterOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCPGridViewItemPresenter* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenterStatics> WUXCPIGridViewItemPresenterStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenterStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.GridViewItemPresenter").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)selectionCheckMarkVisualEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectionCheckMarkVisualEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkHintBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckHintBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkSelectingBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckSelectingBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)dragBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)dragForegroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragForegroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusBorderBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusBorderBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)placeholderBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PlaceholderBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointerOverBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedForegroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedForegroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedPointerOverBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedPointerOverBorderBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBorderBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedBorderThicknessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedBorderThicknessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)disabledOpacityProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisabledOpacityProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)dragOpacityProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragOpacityProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)reorderHintOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ReorderHintOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)gridViewItemPresenterHorizontalContentAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GridViewItemPresenterHorizontalContentAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)gridViewItemPresenterVerticalContentAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GridViewItemPresenterVerticalContentAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)gridViewItemPresenterPaddingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_GridViewItemPresenterPaddingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointerOverBackgroundMarginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackgroundMarginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentMarginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIGridViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentMarginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)selectionCheckMarkVisualEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionCheckMarkVisualEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSelectionCheckMarkVisualEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectionCheckMarkVisualEnabled((boolean)value));
}

- (WUXMBrush*)checkHintBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckHintBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setCheckHintBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckHintBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)checkSelectingBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckSelectingBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setCheckSelectingBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckSelectingBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)checkBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setCheckBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)dragBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setDragBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DragBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)dragForeground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragForeground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setDragForeground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DragForeground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)focusBorderBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusBorderBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFocusBorderBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusBorderBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)placeholderBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaceholderBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setPlaceholderBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaceholderBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)pointerOverBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setPointerOverBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerOverBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedForeground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedForeground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedForeground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedForeground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedPointerOverBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedPointerOverBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedPointerOverBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedPointerOverBorderBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBorderBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedPointerOverBorderBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedPointerOverBorderBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WXThickness*)selectedBorderThickness {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedBorderThickness(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setSelectedBorderThickness:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedBorderThickness(*[value internalStruct]));
}

- (double)disabledOpacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisabledOpacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDisabledOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisabledOpacity(value));
}

- (double)dragOpacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragOpacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDragOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DragOpacity(value));
}

- (double)reorderHintOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReorderHintOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReorderHintOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReorderHintOffset(value));
}

- (WXHorizontalAlignment)gridViewItemPresenterHorizontalContentAlignment {
    ABI::Windows::UI::Xaml::HorizontalAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_GridViewItemPresenterHorizontalContentAlignment(&unmarshalledReturn));
    return (WXHorizontalAlignment)unmarshalledReturn;
}

- (void)setGridViewItemPresenterHorizontalContentAlignment:(WXHorizontalAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_GridViewItemPresenterHorizontalContentAlignment((ABI::Windows::UI::Xaml::HorizontalAlignment)value));
}

- (WXVerticalAlignment)gridViewItemPresenterVerticalContentAlignment {
    ABI::Windows::UI::Xaml::VerticalAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_GridViewItemPresenterVerticalContentAlignment(&unmarshalledReturn));
    return (WXVerticalAlignment)unmarshalledReturn;
}

- (void)setGridViewItemPresenterVerticalContentAlignment:(WXVerticalAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_GridViewItemPresenterVerticalContentAlignment((ABI::Windows::UI::Xaml::VerticalAlignment)value));
}

- (WXThickness*)gridViewItemPresenterPadding {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_GridViewItemPresenterPadding(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setGridViewItemPresenterPadding:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_GridViewItemPresenterPadding(*[value internalStruct]));
}

- (WXThickness*)pointerOverBackgroundMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackgroundMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setPointerOverBackgroundMargin:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerOverBackgroundMargin(*[value internalStruct]));
}

- (WXThickness*)contentMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setContentMargin:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IGridViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentMargin(*[value internalStruct]));
}

@end

@implementation WUXCPListViewItemPresenter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenterFactory> factory;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter").Get(), &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WXCIContentPresenterOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WXCIContentPresenterOverrides)]) {
        typedOuter = Make<WXCIContentPresenterOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCPListViewItemPresenter* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenterStatics2> WUXCPIListViewItemPresenterStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenterStatics2> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)selectedPressedBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedPressedBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pressedBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PressedBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkBoxBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckBoxBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusSecondaryBorderBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusSecondaryBorderBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointerOverForegroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerOverForegroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenterStatics> WUXCPIListViewItemPresenterStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenterStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)selectionCheckMarkVisualEnabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectionCheckMarkVisualEnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkHintBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckHintBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkSelectingBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckSelectingBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)checkBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CheckBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)dragBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)dragForegroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragForegroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)focusBorderBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_FocusBorderBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)placeholderBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PlaceholderBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointerOverBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedForegroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedForegroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedPointerOverBackgroundProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBackgroundProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedPointerOverBorderBrushProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBorderBrushProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedBorderThicknessProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedBorderThicknessProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)disabledOpacityProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisabledOpacityProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)dragOpacityProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DragOpacityProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)reorderHintOffsetProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ReorderHintOffsetProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)listViewItemPresenterHorizontalContentAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ListViewItemPresenterHorizontalContentAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)listViewItemPresenterVerticalContentAlignmentProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ListViewItemPresenterVerticalContentAlignmentProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)listViewItemPresenterPaddingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ListViewItemPresenterPaddingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)pointerOverBackgroundMarginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackgroundMarginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)contentMarginProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIListViewItemPresenterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ContentMarginProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)selectionCheckMarkVisualEnabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionCheckMarkVisualEnabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setSelectionCheckMarkVisualEnabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectionCheckMarkVisualEnabled((boolean)value));
}

- (WUXMBrush*)checkHintBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckHintBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setCheckHintBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckHintBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)checkSelectingBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckSelectingBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setCheckSelectingBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckSelectingBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)checkBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setCheckBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)dragBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setDragBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DragBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)dragForeground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragForeground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setDragForeground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DragForeground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)focusBorderBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusBorderBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFocusBorderBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusBorderBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)placeholderBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PlaceholderBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setPlaceholderBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_PlaceholderBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)pointerOverBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setPointerOverBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerOverBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedForeground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedForeground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedForeground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedForeground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedPointerOverBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedPointerOverBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedPointerOverBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)selectedPointerOverBorderBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedPointerOverBorderBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedPointerOverBorderBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedPointerOverBorderBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WXThickness*)selectedBorderThickness {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedBorderThickness(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setSelectedBorderThickness:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedBorderThickness(*[value internalStruct]));
}

- (double)disabledOpacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DisabledOpacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDisabledOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DisabledOpacity(value));
}

- (double)dragOpacity {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_DragOpacity(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDragOpacity:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_DragOpacity(value));
}

- (double)reorderHintOffset {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ReorderHintOffset(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setReorderHintOffset:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ReorderHintOffset(value));
}

- (WXHorizontalAlignment)listViewItemPresenterHorizontalContentAlignment {
    ABI::Windows::UI::Xaml::HorizontalAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListViewItemPresenterHorizontalContentAlignment(&unmarshalledReturn));
    return (WXHorizontalAlignment)unmarshalledReturn;
}

- (void)setListViewItemPresenterHorizontalContentAlignment:(WXHorizontalAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListViewItemPresenterHorizontalContentAlignment((ABI::Windows::UI::Xaml::HorizontalAlignment)value));
}

- (WXVerticalAlignment)listViewItemPresenterVerticalContentAlignment {
    ABI::Windows::UI::Xaml::VerticalAlignment unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListViewItemPresenterVerticalContentAlignment(&unmarshalledReturn));
    return (WXVerticalAlignment)unmarshalledReturn;
}

- (void)setListViewItemPresenterVerticalContentAlignment:(WXVerticalAlignment)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListViewItemPresenterVerticalContentAlignment((ABI::Windows::UI::Xaml::VerticalAlignment)value));
}

- (WXThickness*)listViewItemPresenterPadding {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ListViewItemPresenterPadding(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setListViewItemPresenterPadding:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ListViewItemPresenterPadding(*[value internalStruct]));
}

- (WXThickness*)pointerOverBackgroundMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerOverBackgroundMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setPointerOverBackgroundMargin:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerOverBackgroundMargin(*[value internalStruct]));
}

- (WXThickness*)contentMargin {
    ABI::Windows::UI::Xaml::Thickness unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContentMargin(&unmarshalledReturn));
    return WXThickness_create(unmarshalledReturn);
}

- (void)setContentMargin:(WXThickness*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter>(self);
    THROW_NS_IF_FAILED(_comInst->put_ContentMargin(*[value internalStruct]));
}

- (WUXMBrush*)selectedPressedBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedPressedBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setSelectedPressedBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedPressedBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)pressedBackground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PressedBackground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setPressedBackground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PressedBackground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)checkBoxBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckBoxBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setCheckBoxBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckBoxBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)focusSecondaryBorderBrush {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_FocusSecondaryBorderBrush(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setFocusSecondaryBorderBrush:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_FocusSecondaryBorderBrush(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXCPListViewItemPresenterCheckMode)checkMode {
    ABI::Windows::UI::Xaml::Controls::Primitives::ListViewItemPresenterCheckMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CheckMode(&unmarshalledReturn));
    return (WUXCPListViewItemPresenterCheckMode)unmarshalledReturn;
}

- (void)setCheckMode:(WUXCPListViewItemPresenterCheckMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_CheckMode((ABI::Windows::UI::Xaml::Controls::Primitives::ListViewItemPresenterCheckMode)value));
}

- (WUXMBrush*)pointerOverForeground {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->get_PointerOverForeground(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setPointerOverForeground:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IListViewItemPresenter2>(self);
    THROW_NS_IF_FAILED(_comInst->put_PointerOverForeground(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

@end

@implementation WUXCPSelectorItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISelectorItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISelectorItemStatics> WUXCPISelectorItemStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISelectorItemStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.SelectorItem").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)isSelectedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPISelectorItemStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsSelectedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelectorItem>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsSelected:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelectorItem>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSelected((boolean)value));
}

@end

@implementation WUXCPRangeBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseStatics> WUXCPIRangeBaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.RangeBase").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)minimumProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIRangeBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MinimumProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)maximumProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIRangeBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_MaximumProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)smallChangeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIRangeBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SmallChangeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)largeChangeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIRangeBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_LargeChangeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)valueProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIRangeBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (double)minimum {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Minimum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMinimum:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Minimum(value));
}

- (double)maximum {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maximum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setMaximum:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Maximum(value));
}

- (double)smallChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmallChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSmallChange:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_SmallChange(value));
}

- (double)largeChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_LargeChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setLargeChange:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_LargeChange(value));
}

- (double)value {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Value(value));
}

- (EventRegistrationToken)addValueChangedEvent:(WUXCPRangeBaseValueChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_ValueChanged(Make<WUXCPRangeBaseValueChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeValueChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_ValueChanged(token));
}

- (void)onMinimumChanged:(double)oldMinimum newMinimum:(double)newMinimum {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnMinimumChanged(oldMinimum, newMinimum));
}

- (void)onMaximumChanged:(double)oldMaximum newMaximum:(double)newMaximum {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnMaximumChanged(oldMaximum, newMaximum));
}

- (void)onValueChanged:(double)oldValue newValue:(double)newValue {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnValueChanged(oldValue, newValue));
}

@end

@implementation WUXCPThumb

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.Thumb").Get(), &out));
    return [_createRtProxy<WUXCPThumb>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IThumbStatics> WUXCPIThumbStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IThumbStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.Thumb").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)isDraggingProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIThumbStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsDraggingProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)isDragging {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsDragging(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addDragStartedEvent:(WUXCPDragStartedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->add_DragStarted(Make<WUXCPDragStartedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDragStartedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DragStarted(token));
}

- (EventRegistrationToken)addDragDeltaEvent:(WUXCPDragDeltaEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->add_DragDelta(Make<WUXCPDragDeltaEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDragDeltaEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DragDelta(token));
}

- (EventRegistrationToken)addDragCompletedEvent:(WUXCPDragCompletedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->add_DragCompleted(Make<WUXCPDragCompletedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeDragCompletedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->remove_DragCompleted(token));
}

- (void)cancelDrag {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IThumb>(self);
    THROW_NS_IF_FAILED(_comInst->CancelDrag());
}

@end

@implementation WUXCPButtonBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBaseStatics> WUXCPIButtonBaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ButtonBase").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)clickModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIButtonBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ClickModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isPointerOverProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIButtonBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPointerOverProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isPressedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIButtonBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsPressedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)commandProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIButtonBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CommandProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)commandParameterProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIButtonBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_CommandParameterProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WXCClickMode)clickMode {
    ABI::Windows::UI::Xaml::Controls::ClickMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_ClickMode(&unmarshalledReturn));
    return (WXCClickMode)unmarshalledReturn;
}

- (void)setClickMode:(WXCClickMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_ClickMode((ABI::Windows::UI::Xaml::Controls::ClickMode)value));
}

- (BOOL)isPointerOver {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPointerOver(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isPressed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsPressed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (RTObject<WUXIICommand>*)command {
    ComPtr<ABI::Windows::UI::Xaml::Input::ICommand> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Command(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXIICommand>(unmarshalledReturn.Get());
}

- (void)setCommand:(RTObject<WUXIICommand>*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Command(_getRtInterface<ABI::Windows::UI::Xaml::Input::ICommand>(value).Get()));
}

- (RTObject*)commandParameter {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_CommandParameter(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setCommandParameter:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_CommandParameter([value comObj].Get()));
}

- (EventRegistrationToken)addClickEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_Click(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClickEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IButtonBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Click(token));
}

@end

@implementation WUXCPScrollBar

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ScrollBar").Get(), &out));
    return [_createRtProxy<WUXCPScrollBar>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBarStatics> WUXCPIScrollBarStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBarStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ScrollBar").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)orientationProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIScrollBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_OrientationProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)viewportSizeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIScrollBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ViewportSizeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)indicatorModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIScrollBarStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IndicatorModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WXCOrientation)orientation {
    ABI::Windows::UI::Xaml::Controls::Orientation unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_Orientation(&unmarshalledReturn));
    return (WXCOrientation)unmarshalledReturn;
}

- (void)setOrientation:(WXCOrientation)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_Orientation((ABI::Windows::UI::Xaml::Controls::Orientation)value));
}

- (double)viewportSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_ViewportSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setViewportSize:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_ViewportSize(value));
}

- (WUXCPScrollingIndicatorMode)indicatorMode {
    ABI::Windows::UI::Xaml::Controls::Primitives::ScrollingIndicatorMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->get_IndicatorMode(&unmarshalledReturn));
    return (WUXCPScrollingIndicatorMode)unmarshalledReturn;
}

- (void)setIndicatorMode:(WUXCPScrollingIndicatorMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->put_IndicatorMode((ABI::Windows::UI::Xaml::Controls::Primitives::ScrollingIndicatorMode)value));
}

- (EventRegistrationToken)addScrollEvent:(WUXCPScrollEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->add_Scroll(Make<WUXCPScrollEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeScrollEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollBar>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Scroll(token));
}

@end

@implementation WUXCPSelector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISelectorStatics> WUXCPISelectorStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ISelectorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.Selector").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)selectedIndexProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPISelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedIndexProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedItemProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPISelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedItemProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedValueProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPISelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedValueProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedValuePathProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPISelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedValuePathProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isSynchronizedWithCurrentItemProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPISelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsSynchronizedWithCurrentItemProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (BOOL)getIsSelectionActive:(WXDependencyObject*)element {
    boolean unmarshalledReturn;
    auto _comInst = WUXCPISelectorStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->GetIsSelectionActive(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)selectedIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSelectedIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedIndex(value));
}

- (RTObject*)selectedItem {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedItem(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setSelectedItem:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedItem([value comObj].Get()));
}

- (RTObject*)selectedValue {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedValue(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setSelectedValue:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedValue([value comObj].Get()));
}

- (NSString*)selectedValuePath {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedValuePath(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setSelectedValuePath:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedValuePath(nsStrToHstr(value).Get()));
}

- (id /* BOOL */)isSynchronizedWithCurrentItem {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSynchronizedWithCurrentItem(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (void)setIsSynchronizedWithCurrentItem:(id /* BOOL */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsSynchronizedWithCurrentItem(
        BuildNullable<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>(value)));
}

- (EventRegistrationToken)addSelectionChangedEvent:(WXCSelectionChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->add_SelectionChanged(Make<WXCSelectionChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSelectionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ISelector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SelectionChanged(token));
}

@end

@implementation WUXCPRepeatButton

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButton> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.RepeatButton").Get(), &out));
    return [_createRtProxy<WUXCPRepeatButton>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButtonStatics> WUXCPIRepeatButtonStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButtonStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.RepeatButton").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)delayProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIRepeatButtonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DelayProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)intervalProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIRepeatButtonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IntervalProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (int)delay {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_Delay(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setDelay:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_Delay(value));
}

- (int)interval {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_Interval(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setInterval:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IRepeatButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_Interval(value));
}

@end

@implementation WUXCPToggleButton

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ToggleButton").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WUXCPIToggleButtonOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WUXCPIToggleButtonOverrides)]) {
        typedOuter = Make<WUXCPIToggleButtonOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCPToggleButton* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonStatics> WUXCPIToggleButtonStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.ToggleButton").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)isCheckedProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIToggleButtonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsCheckedProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)isThreeStateProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIToggleButtonStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_IsThreeStateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (id /* BOOL */)isChecked {
    ComPtr<IReference<bool>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsChecked(unmarshalledReturn.GetAddressOf()));
    return MakeFromNullable<BOOL, ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>::convert(unmarshalledReturn.Get());
}

- (void)setIsChecked:(id /* BOOL */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsChecked(BuildNullable<ABI::Windows::Foundation::Internal::AggregateType<bool, boolean>>(value)));
}

- (BOOL)isThreeState {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsThreeState(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setIsThreeState:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->put_IsThreeState((boolean)value));
}

- (EventRegistrationToken)addCheckedEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->add_Checked(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeCheckedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Checked(token));
}

- (EventRegistrationToken)addUncheckedEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->add_Unchecked(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeUncheckedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Unchecked(token));
}

- (EventRegistrationToken)addIndeterminateEvent:(WXRoutedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->add_Indeterminate(Make<WXRoutedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeIndeterminateEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButton>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Indeterminate(token));
}

- (void)onToggle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IToggleButtonOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnToggle());
}

@end

@implementation WUXCPFlyoutBaseClosingEventArgs

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseClosingEventArgs> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)cancel {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseClosingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->get_Cancel(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setCancel:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseClosingEventArgs>(self);
    THROW_NS_IF_FAILED(_comInst->put_Cancel((boolean)value));
}

@end

@implementation WUXCPFlyoutBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseStatics> WUXCPIFlyoutBaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.FlyoutBase").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)placementProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_PlacementProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)attachedFlyoutProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_AttachedFlyoutProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WUXCPFlyoutBase*)getAttachedFlyout:(WXFrameworkElement*)element {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase> unmarshalledReturn;
    auto _comInst = WUXCPIFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetAttachedFlyout(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(element).Get(),
                                                   unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXCPFlyoutBase>(unmarshalledReturn.Get());
}

+ (void)setAttachedFlyout:(WXFrameworkElement*)element value:(WUXCPFlyoutBase*)value {
    auto _comInst = WUXCPIFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetAttachedFlyout(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(element).Get(),
                                    _getRtInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(value).Get()));
}

+ (void)showAttachedFlyout:(WXFrameworkElement*)flyoutOwner {
    auto _comInst = WUXCPIFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->ShowAttachedFlyout(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(flyoutOwner).Get()));
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseStatics2> WUXCPIFlyoutBaseStatics2_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseStatics2> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.FlyoutBase").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)allowFocusOnInteractionProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIFlyoutBaseStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusOnInteractionProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)lightDismissOverlayModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIFlyoutBaseStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_LightDismissOverlayModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)allowFocusWhenDisabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIFlyoutBaseStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusWhenDisabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)elementSoundModeProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIFlyoutBaseStatics2_inst();
    THROW_NS_IF_FAILED(_comInst->get_ElementSoundModeProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXCPFlyoutPlacementMode)placement {
    ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->get_Placement(&unmarshalledReturn));
    return (WUXCPFlyoutPlacementMode)unmarshalledReturn;
}

- (void)setPlacement:(WUXCPFlyoutPlacementMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->put_Placement((ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutPlacementMode)value));
}

- (EventRegistrationToken)addOpenedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_Opened(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOpenedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Opened(token));
}

- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closed(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closed(token));
}

- (EventRegistrationToken)addOpeningEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->add_Opening(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeOpeningEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Opening(token));
}

- (void)showAt:(WXFrameworkElement*)placementTarget {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->ShowAt(_getRtInterface<ABI::Windows::UI::Xaml::IFrameworkElement>(placementTarget).Get()));
}

- (void)hide {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase>(self);
    THROW_NS_IF_FAILED(_comInst->Hide());
}

- (WXCControl*)createPresenter {
    ComPtr<ABI::Windows::UI::Xaml::Controls::IControl> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->CreatePresenter(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXCControl>(unmarshalledReturn.Get());
}

- (WXFrameworkElement*)target {
    ComPtr<ABI::Windows::UI::Xaml::IFrameworkElement> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->get_Target(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXFrameworkElement>(unmarshalledReturn.Get());
}

- (BOOL)allowFocusOnInteraction {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusOnInteraction(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowFocusOnInteraction:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowFocusOnInteraction((boolean)value));
}

- (WXCLightDismissOverlayMode)lightDismissOverlayMode {
    ABI::Windows::UI::Xaml::Controls::LightDismissOverlayMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->get_LightDismissOverlayMode(&unmarshalledReturn));
    return (WXCLightDismissOverlayMode)unmarshalledReturn;
}

- (void)setLightDismissOverlayMode:(WXCLightDismissOverlayMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->put_LightDismissOverlayMode((ABI::Windows::UI::Xaml::Controls::LightDismissOverlayMode)value));
}

- (BOOL)allowFocusWhenDisabled {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->get_AllowFocusWhenDisabled(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setAllowFocusWhenDisabled:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->put_AllowFocusWhenDisabled((boolean)value));
}

- (WXElementSoundMode)elementSoundMode {
    ABI::Windows::UI::Xaml::ElementSoundMode unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ElementSoundMode(&unmarshalledReturn));
    return (WXElementSoundMode)unmarshalledReturn;
}

- (void)setElementSoundMode:(WXElementSoundMode)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->put_ElementSoundMode((ABI::Windows::UI::Xaml::ElementSoundMode)value));
}

- (EventRegistrationToken)addClosingEvent:(void (^)(WUXCPFlyoutBase*, WUXCPFlyoutBaseClosingEventArgs*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->add_Closing(
        Make<
            ITypedEventHandler_Windows_UI_Xaml_Controls_Primitives_FlyoutBase_Windows_UI_Xaml_Controls_Primitives_FlyoutBaseClosingEventArgs>(
            value)
            .Get(),
        &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeClosingEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase2>(self);
    THROW_NS_IF_FAILED(_comInst->remove_Closing(token));
}

@end

@implementation WUXCPJumpListItemBackgroundConverter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.JumpListItemBackgroundConverter").Get(), &out));
    return [_createRtProxy<WUXCPJumpListItemBackgroundConverter>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverterStatics>
WUXCPIJumpListItemBackgroundConverterStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverterStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.JumpListItemBackgroundConverter").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)enabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIJumpListItemBackgroundConverterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)disabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIJumpListItemBackgroundConverterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMBrush*)enabled {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setEnabled:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)disabled {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Disabled(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setDisabled:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemBackgroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Disabled(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (RTObject*)convert:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IValueConverter>(self);
    THROW_NS_IF_FAILED(_comInst->Convert([value comObj].Get(),
                                         *[targetType internalStruct],
                                         [parameter comObj].Get(),
                                         nsStrToHstr(language).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)convertBack:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IValueConverter>(self);
    THROW_NS_IF_FAILED(_comInst->ConvertBack([value comObj].Get(),
                                             *[targetType internalStruct],
                                             [parameter comObj].Get(),
                                             nsStrToHstr(language).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WUXCPJumpListItemForegroundConverter

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(Windows::Foundation::ActivateInstance(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.JumpListItemForegroundConverter").Get(), &out));
    return [_createRtProxy<WUXCPJumpListItemForegroundConverter>(out.Get()) retain];
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverterStatics>
WUXCPIJumpListItemForegroundConverterStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverterStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.JumpListItemForegroundConverter").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)enabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIJumpListItemForegroundConverterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_EnabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)disabledProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIJumpListItemForegroundConverterStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_DisabledProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (WUXMBrush*)enabled {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Enabled(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setEnabled:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Enabled(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (WUXMBrush*)disabled {
    ComPtr<ABI::Windows::UI::Xaml::Media::IBrush> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->get_Disabled(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXMBrush>(unmarshalledReturn.Get());
}

- (void)setDisabled:(WUXMBrush*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IJumpListItemForegroundConverter>(self);
    THROW_NS_IF_FAILED(_comInst->put_Disabled(_getRtInterface<ABI::Windows::UI::Xaml::Media::IBrush>(value).Get()));
}

- (RTObject*)convert:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IValueConverter>(self);
    THROW_NS_IF_FAILED(_comInst->Convert([value comObj].Get(),
                                         *[targetType internalStruct],
                                         [parameter comObj].Get(),
                                         nsStrToHstr(language).Get(),
                                         unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (RTObject*)convertBack:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Data::IValueConverter>(self);
    THROW_NS_IF_FAILED(_comInst->ConvertBack([value comObj].Get(),
                                             *[targetType internalStruct],
                                             [parameter comObj].Get(),
                                             nsStrToHstr(language).Get(),
                                             unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WUXCPPickerFlyoutBase

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBase> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseStatics> WUXCPIPickerFlyoutBaseStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseStatics> inst;
    THROW_NS_IF_FAILED(ABI::Windows::Foundation::GetActivationFactory(
        HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.PickerFlyoutBase").Get(), &inst));
    return inst;
}

+ (WXDependencyProperty*)titleProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPIPickerFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_TitleProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (NSString*)getTitle:(WXDependencyObject*)element {
    HSTRING unmarshalledReturn;
    auto _comInst = WUXCPIPickerFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(_comInst->GetTitle(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

+ (void)setTitle:(WXDependencyObject*)element value:(NSString*)value {
    auto _comInst = WUXCPIPickerFlyoutBaseStatics_inst();
    THROW_NS_IF_FAILED(
        _comInst->SetTitle(_getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(element).Get(), nsStrToHstr(value).Get()));
}

- (void)onConfirmed {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->OnConfirmed());
}

- (BOOL)shouldShowConfirmationButtons {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IPickerFlyoutBaseOverrides>(self);
    THROW_NS_IF_FAILED(_comInst->ShouldShowConfirmationButtons(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXCPLoopingSelector

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelectorStatics> WUXCPILoopingSelectorStatics_inst() {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelectorStatics> inst;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.LoopingSelector").Get(),
                                                       &inst));
    return inst;
}

+ (WXDependencyProperty*)shouldLoopProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPILoopingSelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ShouldLoopProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)itemsProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPILoopingSelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemsProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedIndexProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPILoopingSelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedIndexProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)selectedItemProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPILoopingSelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_SelectedItemProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)itemWidthProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPILoopingSelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemWidthProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)itemHeightProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPILoopingSelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemHeightProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

+ (WXDependencyProperty*)itemTemplateProperty {
    ComPtr<ABI::Windows::UI::Xaml::IDependencyProperty> unmarshalledReturn;
    auto _comInst = WUXCPILoopingSelectorStatics_inst();
    THROW_NS_IF_FAILED(_comInst->get_ItemTemplateProperty(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDependencyProperty>(unmarshalledReturn.Get());
}

- (BOOL)shouldLoop {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_ShouldLoop(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)setShouldLoop:(BOOL)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_ShouldLoop((boolean)value));
}

- (NSMutableArray* /* RTObject* */)items {
    ComPtr<IVector<IInspectable*>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_Items(unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSMutableArray_RTObject_create(unmarshalledReturn.Get());
}

- (void)setItems:(NSMutableArray* /* RTObject* */)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_Items(static_cast<IVector<typename ABI::Windows::Foundation::Internal::GetLogicalType<
                                               ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>::type>*>(
        ConvertToVector<RTObject, ABI::Windows::Foundation::Internal::AggregateType<IInspectable*, IInspectable*>>(value).Get())));
}

- (int)selectedIndex {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedIndex(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setSelectedIndex:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedIndex(value));
}

- (RTObject*)selectedItem {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectedItem(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)setSelectedItem:(RTObject*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_SelectedItem([value comObj].Get()));
}

- (int)itemWidth {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemWidth(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setItemWidth:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_ItemWidth(value));
}

- (int)itemHeight {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemHeight(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setItemHeight:(int)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_ItemHeight(value));
}

- (WXDataTemplate*)itemTemplate {
    ComPtr<ABI::Windows::UI::Xaml::IDataTemplate> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->get_ItemTemplate(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WXDataTemplate>(unmarshalledReturn.Get());
}

- (void)setItemTemplate:(WXDataTemplate*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->put_ItemTemplate(_getRtInterface<ABI::Windows::UI::Xaml::IDataTemplate>(value).Get()));
}

- (EventRegistrationToken)addSelectionChangedEvent:(WXCSelectionChangedEventHandler)value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->add_SelectionChanged(Make<WXCSelectionChangedEventHandler_shim>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeSelectionChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelector>(self);
    THROW_NS_IF_FAILED(_comInst->remove_SelectionChanged(token));
}

@end

@implementation WUXCPPivotPanel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPivotPanel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.PivotPanel").Get(), &out));
    return [_createRtProxy<WUXCPPivotPanel>(out.Get()) retain];
}

- (BOOL)areHorizontalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreHorizontalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)areVerticalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreVerticalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_HorizontalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HorizontalSnapPointsChanged(token));
}

- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_VerticalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VerticalSnapPointsChanged(token));
}

- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment {
    ComPtr<IVectorView<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetIrregularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                        (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_Single_create(unmarshalledReturn.Get());
}

- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset {
    float offsetOutUnmarshaled;
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetRegularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                      (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                      &offsetOutUnmarshaled,
                                                      &unmarshalledReturn));
    *offset = offsetOutUnmarshaled;
    return unmarshalledReturn;
}

@end

@implementation WUXCPLoopingSelectorItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelectorItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

@implementation WUXCPLoopingSelectorPanel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::ILoopingSelectorPanel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)areHorizontalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreHorizontalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)areVerticalSnapPointsRegular {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->get_AreVerticalSnapPointsRegular(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_HorizontalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_HorizontalSnapPointsChanged(token));
}

- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))value {
    EventRegistrationToken unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->add_VerticalSnapPointsChanged(Make<EventHandler_System_Object>(value).Get(), &unmarshalledReturn));
    return (EventRegistrationToken)unmarshalledReturn;
}

- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)token {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->remove_VerticalSnapPointsChanged(token));
}

- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment {
    ComPtr<IVectorView<float>> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetIrregularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                        (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                        unmarshalledReturn.GetAddressOf()));
    return RTProxiedNSArray_Single_create(unmarshalledReturn.Get());
}

- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset {
    float offsetOutUnmarshaled;
    float unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Controls::Primitives::IScrollSnapPointsInfo>(self);
    THROW_NS_IF_FAILED(_comInst->GetRegularSnapPoints((ABI::Windows::UI::Xaml::Controls::Orientation)orientation,
                                                      (ABI::Windows::UI::Xaml::Controls::Primitives::SnapPointsAlignment)alignment,
                                                      &offsetOutUnmarshaled,
                                                      &unmarshalledReturn));
    *offset = offsetOutUnmarshaled;
    return unmarshalledReturn;
}

@end

@implementation WUXCPPivotHeaderItem

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItemFactory> factory;
    THROW_NS_IF_FAILED(
        ABI::Windows::Foundation::GetActivationFactory(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.PivotHeaderItem").Get(),
                                                       &factory));
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPivotHeaderItem> instance;
    ComPtr<IInspectable> outer = nullptr;
    ComPtr<IInspectable> inner = nullptr;
    ComPtr<WXCIContentControlOverrides_RtProxy> typedOuter;
    if ([self conformsToProtocol:@protocol(WXCIContentControlOverrides)]) {
        typedOuter = Make<WXCIContentControlOverrides_RtProxy>();
        outer = typedOuter;
    }
    factory->CreateInstance(outer.Get(), &inner, &instance);
    WUXCPPivotHeaderItem* ret = [_createRtProxy(self, instance.Get()) retain];
    [ret setInnerInterface:inner.Get()];
    if (typedOuter) {
        typedOuter->_inner = (id)ret;
        typedOuter->SetComposableBasePointers(inner.Get());
    }
    return ret;
}

@end

@implementation WUXCPPivotHeaderPanel

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Controls::Primitives::IPivotHeaderPanel> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

+ (instancetype)make {
    ComPtr<IInspectable> out;
    LOG_IF_FAILED(
        Windows::Foundation::ActivateInstance(HString::MakeReference(L"Windows.UI.Xaml.Controls.Primitives.PivotHeaderPanel").Get(), &out));
    return [_createRtProxy<WUXCPPivotHeaderPanel>(out.Get()) retain];
}

@end

@implementation WUXCPGeneratorPosition {
    ABI::Windows::UI::Xaml::Controls::Primitives::GeneratorPosition structVal;
}
+ (instancetype) new {
    return [super new];
}
+ (instancetype)createWith:(ABI::Windows::UI::Xaml::Controls::Primitives::GeneratorPosition)s {
    WUXCPGeneratorPosition* ret = [[self new] autorelease];
    ret->structVal = s;
    return ret;
}
- (ABI::Windows::UI::Xaml::Controls::Primitives::GeneratorPosition*)internalStruct {
    return &structVal;
}
- (int)index {
    return structVal.Index;
}
- (void)setIndex:(int)val {
    structVal.Index = val;
}
- (int)offset {
    return structVal.Offset;
}
- (void)setOffset:(int)val {
    structVal.Offset = val;
}
@end
