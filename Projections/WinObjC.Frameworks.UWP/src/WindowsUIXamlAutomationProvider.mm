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

// WindowsUIXamlAutomationProvider.mm
// Generated from winmd2objc

#include <COMIncludes.h>
#undef GetCurrentTime
#include <Windows.UI.Xaml.Automation.Provider.h>
#include <COMIncludes_End.h>
#include <UWP/RTHelpers.h>
#include "Starboard.h"
#include "WindowsUIXamlAutomationProvider.h"
#include "WindowsUIXamlAutomationProvider_priv.h"

@implementation WUXAPIAnnotationProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IAnnotationProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)annotationTypeId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IAnnotationProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnnotationTypeId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)annotationTypeName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IAnnotationProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_AnnotationTypeName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)author {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IAnnotationProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Author(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)dateTime {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IAnnotationProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DateTime(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUXAPIRawElementProviderSimple*)target {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IAnnotationProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Target(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPIDockProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IDockProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXADockPosition)dockPosition {
    ABI::Windows::UI::Xaml::Automation::DockPosition unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDockProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DockPosition(&unmarshalledReturn));
    return (WUXADockPosition)unmarshalledReturn;
}

- (void)setDockPosition:(WUXADockPosition)dockPosition {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDockProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetDockPosition((ABI::Windows::UI::Xaml::Automation::DockPosition)dockPosition));
}

@end

@implementation WUXAPIDragProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IDragProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isGrabbed {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDragProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsGrabbed(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)dropEffect {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDragProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropEffect(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)dropEffects {
    HSTRING* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDragProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropEffects(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_NSString_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getGrabbedItems {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDragProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetGrabbedItems(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPIDropTargetProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IDropTargetProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)dropEffect {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropEffect(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* NSString * */)dropEffects {
    HSTRING* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IDropTargetProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DropEffects(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_NSString_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPIExpandCollapseProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXAExpandCollapseState)expandCollapseState {
    ABI::Windows::UI::Xaml::Automation::ExpandCollapseState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExpandCollapseState(&unmarshalledReturn));
    return (WUXAExpandCollapseState)unmarshalledReturn;
}

- (void)collapse {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Collapse());
}

- (void)expand {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IExpandCollapseProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Expand());
}

@end

@implementation WUXAPIGridItemProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IGridItemProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)column {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Column(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)columnSpan {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColumnSpan(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXAPIRawElementProviderSimple*)containingGrid {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ContainingGrid(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (int)row {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Row(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)rowSpan {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_RowSpan(&unmarshalledReturn));
    return unmarshalledReturn;
}

@end

@implementation WUXAPIGridProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IGridProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)columnCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ColumnCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)rowCount {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_RowCount(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (WUXAPIRawElementProviderSimple*)getItem:(int)row column:(int)column {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IGridProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetItem(row, column, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPIInvokeProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IInvokeProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)invoke {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IInvokeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Invoke());
}

@end

@implementation WUXAPIItemContainerProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IItemContainerProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXAPIRawElementProviderSimple*)findItemByProperty:(WUXAPIRawElementProviderSimple*)startAfter
                                   automationProperty:(WUXAAutomationProperty*)automationProperty
                                                value:(RTObject*)value {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IItemContainerProvider>(self);
    THROW_NS_IF_FAILED(_comInst->FindItemByProperty(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(startAfter).Get(),
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::IAutomationProperty>(automationProperty).Get(),
        [value comObj].Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPIMultipleViewProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (int)currentView {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CurrentView(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSArray* /* int */)getSupportedViews {
    int* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSupportedViews(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_Int32_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSString*)getViewName:(int)viewId {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetViewName(viewId, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setCurrentView:(int)viewId {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IMultipleViewProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetCurrentView(viewId));
}

@end

@implementation WUXAPIObjectModelProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IObjectModelProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)getUnderlyingObjectModel {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IObjectModelProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetUnderlyingObjectModel(unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WUXAPIRangeValueProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)largeChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_LargeChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maximum {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maximum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)minimum {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Minimum(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)smallChange {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SmallChange(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)value {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)setValue:(double)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IRangeValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetValue(value));
}

@end

@implementation WUXAPIScrollItemProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)scrollIntoView {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView());
}

@end

@implementation WUXAPIScrollProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)horizontallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)horizontalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)horizontalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_HorizontalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (BOOL)verticallyScrollable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticallyScrollable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)verticalScrollPercent {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalScrollPercent(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)verticalViewSize {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VerticalViewSize(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)scroll:(WUXAScrollAmount)horizontalAmount verticalAmount:(WUXAScrollAmount)verticalAmount {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Scroll((ABI::Windows::UI::Xaml::Automation::ScrollAmount)horizontalAmount,
                                        (ABI::Windows::UI::Xaml::Automation::ScrollAmount)verticalAmount));
}

- (void)setScrollPercent:(double)horizontalPercent verticalPercent:(double)verticalPercent {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IScrollProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetScrollPercent(horizontalPercent, verticalPercent));
}

@end

@implementation WUXAPISelectionItemProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isSelected {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelected(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAPIRawElementProviderSimple*)selectionContainer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SelectionContainer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (void)addToSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AddToSelection());
}

- (void)removeFromSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFromSelection());
}

- (void)select {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Select());
}

@end

@implementation WUXAPISelectionProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canSelectMultiple {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanSelectMultiple(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isSelectionRequired {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsSelectionRequired(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getSelection {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISelectionProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelection(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPISpreadsheetItemProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)formula {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Formula(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getAnnotationObjects {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnnotationObjects(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* WUXAAnnotationType */)getAnnotationTypes {
    ABI::Windows::UI::Xaml::Automation::AnnotationType* unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetAnnotationTypes(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAAnnotationType_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPISpreadsheetProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXAPIRawElementProviderSimple*)getItemByName:(NSString*)name {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISpreadsheetProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetItemByName(nsStrToHstr(name).Get(), unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPIStylesProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSString*)extendedProperties {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ExtendedProperties(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (WUColor*)fillColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (WUColor*)fillPatternColor {
    ABI::Windows::UI::Color unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillPatternColor(&unmarshalledReturn));
    return WUColor_create(unmarshalledReturn);
}

- (NSString*)fillPatternStyle {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_FillPatternStyle(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (NSString*)shape {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Shape(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)styleId {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_StyleId(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (NSString*)styleName {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IStylesProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_StyleName(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

@end

@implementation WUXAPISynchronizedInputProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ISynchronizedInputProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)cancel {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISynchronizedInputProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Cancel());
}

- (void)startListening:(WUXASynchronizedInputType)inputType {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ISynchronizedInputProvider>(self);
    THROW_NS_IF_FAILED(_comInst->StartListening((ABI::Windows::UI::Xaml::Automation::SynchronizedInputType)inputType));
}

@end

@implementation WUXAPITableItemProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITableItemProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getColumnHeaderItems {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITableItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetColumnHeaderItems(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getRowHeaderItems {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITableItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetRowHeaderItems(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPITableProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITableProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXARowOrColumnMajor)rowOrColumnMajor {
    ABI::Windows::UI::Xaml::Automation::RowOrColumnMajor unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITableProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_RowOrColumnMajor(&unmarshalledReturn));
    return (WUXARowOrColumnMajor)unmarshalledReturn;
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getColumnHeaders {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITableProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetColumnHeaders(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getRowHeaders {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITableProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetRowHeaders(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPITextChildProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextChildProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXAPIRawElementProviderSimple*)textContainer {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextChildProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextContainer(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)textRange {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextChildProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_TextRange(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPITextRangeProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXAPITextRangeProvider>*)clone {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (BOOL)compare:(RTObject<WUXAPITextRangeProvider>*)textRangeProvider {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->Compare(_getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(textRangeProvider).Get(),
                          &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)compareEndpoints:(WUXATTextPatternRangeEndpoint)endpoint
      textRangeProvider:(RTObject<WUXAPITextRangeProvider>*)textRangeProvider
         targetEndpoint:(WUXATTextPatternRangeEndpoint)targetEndpoint {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->CompareEndpoints(
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)endpoint,
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(textRangeProvider).Get(),
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)targetEndpoint,
        &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)expandToEnclosingUnit:(WUXATTextUnit)unit {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ExpandToEnclosingUnit((ABI::Windows::UI::Xaml::Automation::Text::TextUnit)unit));
}

- (RTObject<WUXAPITextRangeProvider>*)findAttribute:(int)attributeId value:(RTObject*)value backward:(BOOL)backward {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->FindAttribute(attributeId, [value comObj].Get(), (boolean)backward, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)findText:(NSString*)text backward:(BOOL)backward ignoreCase:(BOOL)ignoreCase {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindText(nsStrToHstr(text).Get(), (boolean)backward, (boolean)ignoreCase, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject*)getAttributeValue:(int)attributeId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetAttributeValue(attributeId, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)getBoundingRectangles:(NSArray* /* double */*)returnValue {
    UINT32 __returnValue_ArrayLen = 0;
    double* __returnValue_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoundingRectangles(&__returnValue_ArrayLen, &__returnValue_Array));
    *returnValue = RTProxiedNSArray_C_Double_create(__returnValue_ArrayLen, __returnValue_Array);
}

- (WUXAPIRawElementProviderSimple*)getEnclosingElement {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetEnclosingElement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (NSString*)getText:(int)maxLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetText(maxLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)move:(WUXATTextUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Move((ABI::Windows::UI::Xaml::Automation::Text::TextUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveEndpointByUnit:(WUXATTextPatternRangeEndpoint)endpoint unit:(WUXATTextUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->MoveEndpointByUnit((ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)endpoint,
                                                    (ABI::Windows::UI::Xaml::Automation::Text::TextUnit)unit,
                                                    count,
                                                    &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)moveEndpointByRange:(WUXATTextPatternRangeEndpoint)endpoint
          textRangeProvider:(RTObject<WUXAPITextRangeProvider>*)textRangeProvider
             targetEndpoint:(WUXATTextPatternRangeEndpoint)targetEndpoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->MoveEndpointByRange(
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)endpoint,
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(textRangeProvider).Get(),
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)targetEndpoint));
}

- (void)select {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Select());
}

- (void)addToSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AddToSelection());
}

- (void)removeFromSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFromSelection());
}

- (void)scrollIntoView:(BOOL)alignToTop {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView((boolean)alignToTop));
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getChildren {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetChildren(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPITextProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXAPITextRangeProvider>*)documentRange {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentRange(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (WUXASupportedTextSelection)supportedTextSelection {
    ABI::Windows::UI::Xaml::Automation::SupportedTextSelection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedTextSelection(&unmarshalledReturn));
    return (WUXASupportedTextSelection)unmarshalledReturn;
}

- (NSArray* /* RTObject<WUXAPITextRangeProvider>* */)getSelection {
    ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelection(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* RTObject<WUXAPITextRangeProvider>* */)getVisibleRanges {
    ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetVisibleRanges(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (RTObject<WUXAPITextRangeProvider>*)rangeFromChild:(WUXAPIRawElementProviderSimple*)childElement {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RangeFromChild(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(childElement).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)rangeFromPoint:(WFPoint*)screenLocation {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RangeFromPoint(*[screenLocation internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPITextProvider2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXAPITextRangeProvider>*)rangeFromAnnotation:(WUXAPIRawElementProviderSimple*)annotationElement {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->RangeFromAnnotation(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(annotationElement).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)getCaretRange:(BOOL*)isActive {
    boolean isActiveOutUnmarshaled;
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->GetCaretRange(&isActiveOutUnmarshaled, unmarshalledReturn.GetAddressOf()));
    *isActive = (BOOL)isActiveOutUnmarshaled;
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)documentRange {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentRange(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (WUXASupportedTextSelection)supportedTextSelection {
    ABI::Windows::UI::Xaml::Automation::SupportedTextSelection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedTextSelection(&unmarshalledReturn));
    return (WUXASupportedTextSelection)unmarshalledReturn;
}

- (NSArray* /* RTObject<WUXAPITextRangeProvider>* */)getSelection {
    ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelection(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* RTObject<WUXAPITextRangeProvider>* */)getVisibleRanges {
    ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetVisibleRanges(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (RTObject<WUXAPITextRangeProvider>*)rangeFromChild:(WUXAPIRawElementProviderSimple*)childElement {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RangeFromChild(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(childElement).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)rangeFromPoint:(WFPoint*)screenLocation {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RangeFromPoint(*[screenLocation internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPITextRangeProvider2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)showContextMenu {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->ShowContextMenu());
}

- (RTObject<WUXAPITextRangeProvider>*)clone {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Clone(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (BOOL)compare:(RTObject<WUXAPITextRangeProvider>*)textRangeProvider {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->Compare(_getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(textRangeProvider).Get(),
                          &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (int)compareEndpoints:(WUXATTextPatternRangeEndpoint)endpoint
      textRangeProvider:(RTObject<WUXAPITextRangeProvider>*)textRangeProvider
         targetEndpoint:(WUXATTextPatternRangeEndpoint)targetEndpoint {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->CompareEndpoints(
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)endpoint,
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(textRangeProvider).Get(),
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)targetEndpoint,
        &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)expandToEnclosingUnit:(WUXATTextUnit)unit {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ExpandToEnclosingUnit((ABI::Windows::UI::Xaml::Automation::Text::TextUnit)unit));
}

- (RTObject<WUXAPITextRangeProvider>*)findAttribute:(int)attributeId value:(RTObject*)value backward:(BOOL)backward {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->FindAttribute(attributeId, [value comObj].Get(), (boolean)backward, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)findText:(NSString*)text backward:(BOOL)backward ignoreCase:(BOOL)ignoreCase {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(
        _comInst->FindText(nsStrToHstr(text).Get(), (boolean)backward, (boolean)ignoreCase, unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject*)getAttributeValue:(int)attributeId {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetAttributeValue(attributeId, unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

- (void)getBoundingRectangles:(NSArray* /* double */*)returnValue {
    UINT32 __returnValue_ArrayLen = 0;
    double* __returnValue_Array = NULL;

    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetBoundingRectangles(&__returnValue_ArrayLen, &__returnValue_Array));
    *returnValue = RTProxiedNSArray_C_Double_create(__returnValue_ArrayLen, __returnValue_Array);
}

- (WUXAPIRawElementProviderSimple*)getEnclosingElement {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetEnclosingElement(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPIRawElementProviderSimple>(unmarshalledReturn.Get());
}

- (NSString*)getText:(int)maxLength {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetText(maxLength, &unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (int)move:(WUXATTextUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Move((ABI::Windows::UI::Xaml::Automation::Text::TextUnit)unit, count, &unmarshalledReturn));
    return unmarshalledReturn;
}

- (int)moveEndpointByUnit:(WUXATTextPatternRangeEndpoint)endpoint unit:(WUXATTextUnit)unit count:(int)count {
    int unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->MoveEndpointByUnit((ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)endpoint,
                                                    (ABI::Windows::UI::Xaml::Automation::Text::TextUnit)unit,
                                                    count,
                                                    &unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)moveEndpointByRange:(WUXATTextPatternRangeEndpoint)endpoint
          textRangeProvider:(RTObject<WUXAPITextRangeProvider>*)textRangeProvider
             targetEndpoint:(WUXATTextPatternRangeEndpoint)targetEndpoint {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->MoveEndpointByRange(
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)endpoint,
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(textRangeProvider).Get(),
        (ABI::Windows::UI::Xaml::Automation::Text::TextPatternRangeEndpoint)targetEndpoint));
}

- (void)select {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Select());
}

- (void)addToSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->AddToSelection());
}

- (void)removeFromSelection {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RemoveFromSelection());
}

- (void)scrollIntoView:(BOOL)alignToTop {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->ScrollIntoView((boolean)alignToTop));
}

- (NSArray* /* WUXAPIRawElementProviderSimple* */)getChildren {
    ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetChildren(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_WUXAPIRawElementProviderSimple_create(unmarshalledReturnLen, unmarshalledReturn);
}

@end

@implementation WUXAPIToggleProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (WUXAToggleState)toggleState {
    ABI::Windows::UI::Xaml::Automation::ToggleState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_ToggleState(&unmarshalledReturn));
    return (WUXAToggleState)unmarshalledReturn;
}

- (void)toggle {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IToggleProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Toggle());
}

@end

@implementation WUXAPITransformProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canMove {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanMove(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canResize {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanResize(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canRotate {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRotate(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)move:(double)x y:(double)y {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Move(x, y));
}

- (void)resize:(double)width height:(double)height {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Resize(width, height));
}

- (void)rotate:(double)degrees {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Rotate(degrees));
}

@end

@implementation WUXAPITransformProvider2

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)canZoom {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanZoom(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (double)zoomLevel {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->get_ZoomLevel(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)maxZoom {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MaxZoom(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (double)minZoom {
    double unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->get_MinZoom(&unmarshalledReturn));
    return unmarshalledReturn;
}

- (void)zoom:(double)zoom {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->Zoom(zoom));
}

- (void)zoomByUnit:(WUXAZoomUnit)zoomUnit {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider2>(self);
    THROW_NS_IF_FAILED(_comInst->ZoomByUnit((ABI::Windows::UI::Xaml::Automation::ZoomUnit)zoomUnit));
}

- (BOOL)canMove {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanMove(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canResize {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanResize(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)canRotate {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_CanRotate(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (void)move:(double)x y:(double)y {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Move(x, y));
}

- (void)resize:(double)width height:(double)height {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Resize(width, height));
}

- (void)rotate:(double)degrees {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITransformProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Rotate(degrees));
}

@end

@implementation WUXAPIValueProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isReadOnly {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsReadOnly(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (NSString*)value {
    HSTRING unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Value(&unmarshalledReturn));
    return hstrToNSStr(unmarshalledReturn);
}

- (void)setValue:(NSString*)value {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IValueProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetValue(nsStrToHstr(value).Get()));
}

@end

@implementation WUXAPIVirtualizedItemProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (void)realize {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IVirtualizedItemProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Realize());
}

@end

@implementation WUXAPIWindowProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (BOOL)isModal {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsModal(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)isTopmost {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_IsTopmost(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)maximizable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Maximizable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (BOOL)minimizable {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_Minimizable(&unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

- (WUXAWindowInteractionState)interactionState {
    ABI::Windows::UI::Xaml::Automation::WindowInteractionState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_InteractionState(&unmarshalledReturn));
    return (WUXAWindowInteractionState)unmarshalledReturn;
}

- (WUXAWindowVisualState)visualState {
    ABI::Windows::UI::Xaml::Automation::WindowVisualState unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_VisualState(&unmarshalledReturn));
    return (WUXAWindowVisualState)unmarshalledReturn;
}

- (void)close {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->Close());
}

- (void)setVisualState:(WUXAWindowVisualState)state {
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->SetVisualState((ABI::Windows::UI::Xaml::Automation::WindowVisualState)state));
}

- (BOOL)waitForInputIdle:(int)milliseconds {
    boolean unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::IWindowProvider>(self);
    THROW_NS_IF_FAILED(_comInst->WaitForInputIdle(milliseconds, &unmarshalledReturn));
    return (BOOL)unmarshalledReturn;
}

@end

@implementation WUXAPICustomNavigationProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ICustomNavigationProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject*)navigateCustom:(WUXAPAutomationNavigationDirection)direction {
    ComPtr<IInspectable> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ICustomNavigationProvider>(self);
    THROW_NS_IF_FAILED(_comInst->NavigateCustom((ABI::Windows::UI::Xaml::Automation::Peers::AutomationNavigationDirection)direction,
                                                unmarshalledReturn.GetAddressOf()));
    return _createBareRTObj(unmarshalledReturn.Get());
}

@end

@implementation WUXAPITextEditProvider

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextEditProvider> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

- (RTObject<WUXAPITextRangeProvider>*)getActiveComposition {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextEditProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetActiveComposition(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)getConversionTarget {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextEditProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetConversionTarget(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)documentRange {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_DocumentRange(unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (WUXASupportedTextSelection)supportedTextSelection {
    ABI::Windows::UI::Xaml::Automation::SupportedTextSelection unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->get_SupportedTextSelection(&unmarshalledReturn));
    return (WUXASupportedTextSelection)unmarshalledReturn;
}

- (NSArray* /* RTObject<WUXAPITextRangeProvider>* */)getSelection {
    ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetSelection(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (NSArray* /* RTObject<WUXAPITextRangeProvider>* */)getVisibleRanges {
    ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** unmarshalledReturn;
    UINT32 unmarshalledReturnLen = 0;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->GetVisibleRanges(&unmarshalledReturnLen, &unmarshalledReturn));
    return RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(unmarshalledReturnLen, unmarshalledReturn);
}

- (RTObject<WUXAPITextRangeProvider>*)rangeFromChild:(WUXAPIRawElementProviderSimple*)childElement {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RangeFromChild(
        _getRtInterface<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple>(childElement).Get(),
        unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

- (RTObject<WUXAPITextRangeProvider>*)rangeFromPoint:(WFPoint*)screenLocation {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider> unmarshalledReturn;
    auto _comInst = _getInnerInterface<ABI::Windows::UI::Xaml::Automation::Provider::ITextProvider>(self);
    THROW_NS_IF_FAILED(_comInst->RangeFromPoint(*[screenLocation internalStruct], unmarshalledReturn.GetAddressOf()));
    return _createRtProxy<WUXAPITextRangeProvider>(unmarshalledReturn.Get());
}

@end

@implementation WUXAPIRawElementProviderSimple

+ (instancetype)createWith:(IInspectable*)obj {
    ComPtr<ABI::Windows::UI::Xaml::Automation::Provider::IIRawElementProviderSimple> defaultInterface;
    ComPtr<IInspectable> inspectableInterface(obj);
    return SUCCEEDED(inspectableInterface.As(&defaultInterface)) ? _createRtProxy(self, obj) : nil;
}

@end

id RTProxiedNSArray_C_Double_create(UINT32 size, double* val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<double, RTCArrayObj<double, double, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_Int32_create(UINT32 size, int* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<CArrayAdapterObj<int, RTCArrayObj<int, int, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_RTObject_WUXAPITextRangeProvider_create(UINT32 size,
                                                              ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider** val) {
    std::unique_ptr<CArrayAdapter> adapter =
        std::make_unique<CArrayAdapterObj<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider*,
                                          RTCArrayObj<ABI::Windows::UI::Xaml::Automation::Provider::ITextRangeProvider*,
                                                      RTObject<WUXAPITextRangeProvider>,
                                                      dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}

id RTProxiedNSArray_C_WUXAAnnotationType_create(UINT32 size, ABI::Windows::UI::Xaml::Automation::AnnotationType* val) {
    std::unique_ptr<CArrayAdapter> adapter = std::make_unique<
        CArrayAdapterObj<ABI::Windows::UI::Xaml::Automation::AnnotationType,
                         RTCArrayObj<ABI::Windows::UI::Xaml::Automation::AnnotationType, WUXAAnnotationType, dummyObjCCreator>>>(size, val);
    return [[[RTProxiedNSArrayFull alloc] initWithAdapter:std::move(adapter)] autorelease];
}
