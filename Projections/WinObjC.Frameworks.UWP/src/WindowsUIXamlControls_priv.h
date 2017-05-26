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

// WindowsUIXamlControls_priv.h
// Forward decls for private object generation
#pragma once

#include "WindowsFoundationCollections_priv.h"
#include "WindowsUIXamlMediaAnimation_priv.h"
#include "WindowsUIXamlDocuments_priv.h"
#include "WindowsApplicationModelDataTransfer_priv.h"
#include "WindowsUIXamlMedia_priv.h"
#include "WindowsFoundation_priv.h"
#include "WindowsUIXaml_priv.h"
#include "WindowsUIXamlInterop_priv.h"
#include "WindowsUI_priv.h"
#include "WindowsUIXamlData_priv.h"
#include "WindowsUIXamlControlsPrimitives_priv.h"
#include "WindowsMediaCapture_priv.h"
#include "WindowsUIText_priv.h"
#include "WindowsMediaPlayTo_priv.h"
#include "WindowsMediaCasting_priv.h"
#include "WindowsUIComposition_priv.h"
#include "WindowsUIXamlInput_priv.h"
#include "WindowsUIXamlMediaMedia3D_priv.h"
#include "WindowsApplicationModelSearch_priv.h"
#include "WindowsGlobalization_priv.h"
#include "WindowsSystem_priv.h"
#include "WindowsWeb_priv.h"
#include "WindowsUIInputInking_priv.h"
#include "WindowsMediaProtection_priv.h"
#include "WindowsStorageStreams_priv.h"
#include "WindowsMediaCore_priv.h"
#include "WindowsMediaPlayback_priv.h"
#include "WindowsWebHttp_priv.h"
#include "WindowsUIXamlNavigation_priv.h"
#include "WindowsUICore_priv.h"
#include "WindowsUIInput_priv.h"
#include "WindowsUIXamlAutomationPeers_priv.h"
ComPtr<ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsHelperStatics> WXCIMediaTransportControlsHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IToolTipServiceStatics> WXCIToolTipServiceStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListViewPersistenceHelperStatics> WXCIListViewPersistenceHelperStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IColumnDefinitionStatics> WXCIColumnDefinitionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRowDefinitionStatics> WXCIRowDefinitionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgsStatics> WXCIAutoSuggestBoxTextChangedEventArgsStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPanelStatics> WXCIPanelStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IBorderStatics> WXCIBorderStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICaptureElementStatics> WXCICaptureElementStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics3> WXCIContentPresenterStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics> WXCIContentPresenterStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics4> WXCIContentPresenterStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IContentPresenterStatics2> WXCIContentPresenterStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IImageStatics> WXCIImageStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IItemsPresenterStatics> WXCIItemsPresenterStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IItemsPresenterStatics2> WXCIItemsPresenterStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichTextBlockOverflowStatics2> WXCIRichTextBlockOverflowStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichTextBlockOverflowStatics> WXCIRichTextBlockOverflowStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichTextBlockStatics> WXCIRichTextBlockStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichTextBlockStatics3> WXCIRichTextBlockStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichTextBlockStatics2> WXCIRichTextBlockStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITextBlockStatics2> WXCITextBlockStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITextBlockStatics> WXCITextBlockStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITextBlockStatics3> WXCITextBlockStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IViewboxStatics> WXCIViewboxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICanvasStatics> WXCICanvasStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IGridStatics> WXCIGridStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IGridStatics2> WXCIGridStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRelativePanelStatics> WXCIRelativePanelStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IStackPanelStatics2> WXCIStackPanelStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IStackPanelStatics> WXCIStackPanelStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IVariableSizedWrapGridStatics> WXCIVariableSizedWrapGridStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelStatics> WXCIVirtualizingStackPanelStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IIconElementStatics> WXCIIconElementStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMediaElementStatics2> WXCIMediaElementStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMediaElementStatics> WXCIMediaElementStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMediaPlayerPresenterStatics> WXCIMediaPlayerPresenterStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Controls::IWebViewFactory4> WXCIWebViewFactory4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IWebViewStatics2> WXCIWebViewStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IWebViewStatics4> WXCIWebViewStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IWebViewStatics> WXCIWebViewStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IWebViewStatics5> WXCIWebViewStatics5_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IWebViewStatics3> WXCIWebViewStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IBitmapIconStatics> WXCIBitmapIconStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IFontIconStatics> WXCIFontIconStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IFontIconStatics3> WXCIFontIconStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IFontIconStatics2> WXCIFontIconStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IItemsStackPanelStatics2> WXCIItemsStackPanelStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IItemsStackPanelStatics> WXCIItemsStackPanelStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IItemsWrapGridStatics2> WXCIItemsWrapGridStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IItemsWrapGridStatics> WXCIItemsWrapGridStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPathIconStatics> WXCIPathIconStatics_inst();
static ComPtr<ABI::Windows::UI::Xaml::Controls::ISymbolIconFactory> WXCISymbolIconFactory_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISymbolIconStatics> WXCISymbolIconStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISwapChainPanelStatics> WXCISwapChainPanelStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IWrapGridStatics> WXCIWrapGridStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IControlStatics4> WXCIControlStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IControlStatics2> WXCIControlStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IControlStatics> WXCIControlStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IControlStatics3> WXCIControlStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISemanticZoomStatics> WXCISemanticZoomStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IContentControlStatics> WXCIContentControlStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IItemsControlStatics> WXCIItemsControlStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsStatics2> WXCIMediaTransportControlsStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMediaTransportControlsStatics> WXCIMediaTransportControlsStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPasswordBoxStatics3> WXCIPasswordBoxStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPasswordBoxStatics> WXCIPasswordBoxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPasswordBoxStatics2> WXCIPasswordBoxStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IProgressRingStatics> WXCIProgressRingStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics3> WXCIRichEditBoxStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics4> WXCIRichEditBoxStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics2> WXCIRichEditBoxStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRichEditBoxStatics> WXCIRichEditBoxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITextBoxStatics3> WXCITextBoxStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITextBoxStatics> WXCITextBoxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITextBoxStatics2> WXCITextBoxStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IToggleSwitchStatics> WXCIToggleSwitchStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IUserControlStatics> WXCIUserControlStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISettingsFlyoutStatics> WXCISettingsFlyoutStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IToolTipStatics> WXCIToolTipStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IProgressBarStatics> WXCIProgressBarStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISliderStatics2> WXCISliderStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISliderStatics> WXCISliderStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IButtonStaticsWithFlyout> WXCIButtonStaticsWithFlyout_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IHyperlinkButtonStatics> WXCIHyperlinkButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics4> WXCIListViewBaseStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics2> WXCIListViewBaseStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics3> WXCIListViewBaseStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics> WXCIListViewBaseStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListViewBaseStatics5> WXCIListViewBaseStatics5_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IComboBoxStatics> WXCIComboBoxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IComboBoxStatics3> WXCIComboBoxStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IComboBoxStatics2> WXCIComboBoxStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IFlipViewStatics2> WXCIFlipViewStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListBoxStatics2> WXCIListBoxStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListBoxStatics> WXCIListBoxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IRadioButtonStatics> WXCIRadioButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICalendarViewStatics> WXCICalendarViewStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItemStatics> WXCICalendarViewDayItemStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IHubSectionStatics> WXCIHubSectionStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarSeparatorStatics3> WXCIAppBarSeparatorStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarSeparatorStatics> WXCIAppBarSeparatorStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICalendarDatePickerStatics2> WXCICalendarDatePickerStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICalendarDatePickerStatics> WXCICalendarDatePickerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IDatePickerStatics2> WXCIDatePickerStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IDatePickerStatics> WXCIDatePickerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IHubStatics> WXCIHubStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMediaPlayerElementStatics> WXCIMediaPlayerElementStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISearchBoxStatics> WXCISearchBoxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISplitViewStatics> WXCISplitViewStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ISplitViewStatics2> WXCISplitViewStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITimePickerStatics2> WXCITimePickerStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITimePickerStatics> WXCITimePickerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarStatics2> WXCIAppBarStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarStatics4> WXCIAppBarStatics4_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarStatics> WXCIAppBarStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics2> WXCIAutoSuggestBoxStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics3> WXCIAutoSuggestBoxStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxStatics> WXCIAutoSuggestBoxStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IContentDialogStatics> WXCIContentDialogStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IFrameStatics2> WXCIFrameStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IFrameStatics> WXCIFrameStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMenuFlyoutItemStatics> WXCIMenuFlyoutItemStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMenuFlyoutSubItemStatics> WXCIMenuFlyoutSubItemStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPageStatics> WXCIPageStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IScrollViewerStatics2> WXCIScrollViewerStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IScrollViewerStatics> WXCIScrollViewerStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICommandBarStatics3> WXCICommandBarStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICommandBarStatics2> WXCICommandBarStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ICommandBarStatics> WXCICommandBarStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IToggleMenuFlyoutItemStatics> WXCIToggleMenuFlyoutItemStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarButtonStatics> WXCIAppBarButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarButtonStatics3> WXCIAppBarButtonStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarToggleButtonStatics> WXCIAppBarToggleButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IAppBarToggleButtonStatics3> WXCIAppBarToggleButtonStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IFlyoutStatics> WXCIFlyoutStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IMenuFlyoutStatics> WXCIMenuFlyoutStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IWebViewBrushStatics> WXCIWebViewBrushStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IInkToolbarStatics> WXCIInkToolbarStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IInkToolbarPenConfigurationControlStatics> WXCIInkToolbarPenConfigurationControlStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IInkToolbarToolButtonStatics> WXCIInkToolbarToolButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomToolButtonStatics> WXCIInkToolbarCustomToolButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IInkToolbarPenButtonStatics> WXCIInkToolbarPenButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IInkToolbarRulerButtonStatics> WXCIInkToolbarRulerButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenButtonStatics> WXCIInkToolbarCustomPenButtonStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutItemStatics> WXCIDatePickerFlyoutItemStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPivotStatics2> WXCIPivotStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPivotStatics> WXCIPivotStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPivotStatics3> WXCIPivotStatics3_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPivotItemStatics> WXCIPivotItemStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutStatics2> WXCIDatePickerFlyoutStatics2_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IDatePickerFlyoutStatics> WXCIDatePickerFlyoutStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IListPickerFlyoutStatics> WXCIListPickerFlyoutStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::IPickerFlyoutStatics> WXCIPickerFlyoutStatics_inst();
ComPtr<ABI::Windows::UI::Xaml::Controls::ITimePickerFlyoutStatics> WXCITimePickerFlyoutStatics_inst();

id RTProxiedIterableNSArray_NSString_create(IInspectable* val);
id RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint_create(IInspectable* val);
id RTProxiedIterableNSArray_WFPoint_create(IInspectable* val);
id RTProxiedIterableNSArray_WUColor_create(IInspectable* val);
id RTProxiedNSArray_C_NSString_create(UINT32 size, HSTRING* val);
id RTProxiedNSArray_NSString_create(IInspectable* val);
id RTProxiedNSArray_RTObject_create(IInspectable* val);
id RTProxiedNSArray_Single_create(IInspectable* val);
id RTProxiedNSArray_WFDateTime_create(IInspectable* val);
id RTProxiedNSArray_WUXDItemIndexRange_create(IInspectable* val);
id RTProxiedNSArray_WUXIPointer_create(IInspectable* val);
id RTProxiedNSMutableArray_RTObject_create(IInspectable* val);
id RTProxiedNSMutableArray_Single_create(IInspectable* val);
id RTProxiedNSMutableArray_WFDateTime_create(IInspectable* val);
id RTProxiedNSMutableArray_WFUri_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXMBrush_create(IInspectable* val);
id RTProxiedNSMutableArray_WUXNPageStackEntry_create(IInspectable* val);
id RTProxiedNSMutableArray_WXCHubSection_create(IInspectable* val);
id RTProxiedNSMutableArray_WXCMenuFlyoutItemBase_create(IInspectable* val);
id RTProxiedNSMutableArray_WXCWebViewDeferredPermissionRequest_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_RTObject_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_RTObject_WXCICommandBarElement_create(IInspectable* val);
id RTProxiedObservableNSMutableArray_WXCGroupStyle_create(IInspectable* val);

@class Nullable_Boolean, Nullable_Double, Nullable_Int32, Nullable_Single, Nullable_WFDateTime, Nullable_WFTimeSpan,
    RTProxiedIterableNSArray_NSString;
@class RTProxiedIterableNSArray_RTProxiedIterableNSArray_WFPoint, RTProxiedIterableNSArray_WFPoint, RTProxiedIterableNSArray_WUColor;
@class RTProxiedNSArray_C_NSString, RTProxiedNSArray_NSString, RTProxiedNSArray_RTObject, RTProxiedNSArray_Single,
    RTProxiedNSArray_WFDateTime;
@class RTProxiedNSArray_WUXDItemIndexRange, RTProxiedNSArray_WUXIPointer, RTProxiedNSMutableArray_RTObject, RTProxiedNSMutableArray_Single;
@class RTProxiedNSMutableArray_WFDateTime, RTProxiedNSMutableArray_WFUri, RTProxiedNSMutableArray_WUXMBrush,
    RTProxiedNSMutableArray_WUXNPageStackEntry;
@class RTProxiedNSMutableArray_WXCHubSection, RTProxiedNSMutableArray_WXCMenuFlyoutItemBase,
    RTProxiedNSMutableArray_WXCWebViewDeferredPermissionRequest;
@class RTProxiedObservableNSMutableArray_RTObject, RTProxiedObservableNSMutableArray_RTObject_WXCICommandBarElement,
    RTProxiedObservableNSMutableArray_WXCGroupStyle;

#ifndef __EventHandler_System_Object__DEFINED
#define __EventHandler_System_Object__DEFINED
class EventHandler_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::Foundation::IEventHandler<IInspectable*>> {
    void (^_delegate)(RTObject*, RTObject*);

public:
    EventHandler_System_Object(void (^del)(RTObject*, RTObject*)) : _delegate([del copy]) {
    }
    ~EventHandler_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_UI_Xaml_Controls_DatePickerValueChangedEventArgs__DEFINED
#define __EventHandler_Windows_UI_Xaml_Controls_DatePickerValueChangedEventArgs__DEFINED
class EventHandler_Windows_UI_Xaml_Controls_DatePickerValueChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::UI::Xaml::Controls::DatePickerValueChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WXCDatePickerValueChangedEventArgs*);

public:
    EventHandler_Windows_UI_Xaml_Controls_DatePickerValueChangedEventArgs(void (^del)(RTObject*, WXCDatePickerValueChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_UI_Xaml_Controls_DatePickerValueChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IDatePickerValueChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCDatePickerValueChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangedEventArgs__DEFINED
#define __EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangedEventArgs__DEFINED
class EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::UI::Xaml::Controls::ScrollViewerViewChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WXCScrollViewerViewChangedEventArgs*);

public:
    EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangedEventArgs(void (^del)(RTObject*, WXCScrollViewerViewChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IScrollViewerViewChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCScrollViewerViewChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangingEventArgs__DEFINED
#define __EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangingEventArgs__DEFINED
class EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::UI::Xaml::Controls::ScrollViewerViewChangingEventArgs*>> {
    void (^_delegate)(RTObject*, WXCScrollViewerViewChangingEventArgs*);

public:
    EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangingEventArgs(void (^del)(RTObject*, WXCScrollViewerViewChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_UI_Xaml_Controls_ScrollViewerViewChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IScrollViewerViewChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCScrollViewerViewChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __EventHandler_Windows_UI_Xaml_Controls_TimePickerValueChangedEventArgs__DEFINED
#define __EventHandler_Windows_UI_Xaml_Controls_TimePickerValueChangedEventArgs__DEFINED
class EventHandler_Windows_UI_Xaml_Controls_TimePickerValueChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::IEventHandler<ABI::Windows::UI::Xaml::Controls::TimePickerValueChangedEventArgs*>> {
    void (^_delegate)(RTObject*, WXCTimePickerValueChangedEventArgs*);

public:
    EventHandler_Windows_UI_Xaml_Controls_TimePickerValueChangedEventArgs(void (^del)(RTObject*, WXCTimePickerValueChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~EventHandler_Windows_UI_Xaml_Controls_TimePickerValueChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITimePickerValueChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCTimePickerValueChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxQuerySubmittedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxQuerySubmittedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxQuerySubmittedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::AutoSuggestBox*,
                                                       ABI::Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs*>> {
    void (^_delegate)(WXCAutoSuggestBox*, WXCAutoSuggestBoxQuerySubmittedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxQuerySubmittedEventArgs(
        void (^del)(WXCAutoSuggestBox*, WXCAutoSuggestBoxQuerySubmittedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxQuerySubmittedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IAutoSuggestBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxQuerySubmittedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCAutoSuggestBox>(arg0), _createRtProxy<WXCAutoSuggestBoxQuerySubmittedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxSuggestionChosenEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxSuggestionChosenEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxSuggestionChosenEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::AutoSuggestBox*,
                                                       ABI::Windows::UI::Xaml::Controls::AutoSuggestBoxSuggestionChosenEventArgs*>> {
    void (^_delegate)(WXCAutoSuggestBox*, WXCAutoSuggestBoxSuggestionChosenEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxSuggestionChosenEventArgs(
        void (^del)(WXCAutoSuggestBox*, WXCAutoSuggestBoxSuggestionChosenEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxSuggestionChosenEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IAutoSuggestBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxSuggestionChosenEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCAutoSuggestBox>(arg0), _createRtProxy<WXCAutoSuggestBoxSuggestionChosenEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxTextChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxTextChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxTextChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::AutoSuggestBox*,
                                                       ABI::Windows::UI::Xaml::Controls::AutoSuggestBoxTextChangedEventArgs*>> {
    void (^_delegate)(WXCAutoSuggestBox*, WXCAutoSuggestBoxTextChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxTextChangedEventArgs(
        void (^del)(WXCAutoSuggestBox*, WXCAutoSuggestBoxTextChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_AutoSuggestBox_Windows_UI_Xaml_Controls_AutoSuggestBoxTextChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IAutoSuggestBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IAutoSuggestBoxTextChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCAutoSuggestBox>(arg0), _createRtProxy<WXCAutoSuggestBoxTextChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarDatePicker_Windows_UI_Xaml_Controls_CalendarDatePickerDateChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarDatePicker_Windows_UI_Xaml_Controls_CalendarDatePickerDateChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarDatePicker_Windows_UI_Xaml_Controls_CalendarDatePickerDateChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::CalendarDatePicker*,
                                                       ABI::Windows::UI::Xaml::Controls::CalendarDatePickerDateChangedEventArgs*>> {
    void (^_delegate)(WXCCalendarDatePicker*, WXCCalendarDatePickerDateChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarDatePicker_Windows_UI_Xaml_Controls_CalendarDatePickerDateChangedEventArgs(
        void (^del)(WXCCalendarDatePicker*, WXCCalendarDatePickerDateChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarDatePicker_Windows_UI_Xaml_Controls_CalendarDatePickerDateChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ICalendarDatePicker* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ICalendarDatePickerDateChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCCalendarDatePicker>(arg0), _createRtProxy<WXCCalendarDatePickerDateChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewDayItemChangingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewDayItemChangingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewDayItemChangingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::CalendarView*,
                                                       ABI::Windows::UI::Xaml::Controls::CalendarViewDayItemChangingEventArgs*>> {
    void (^_delegate)(WXCCalendarView*, WXCCalendarViewDayItemChangingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewDayItemChangingEventArgs(
        void (^del)(WXCCalendarView*, WXCCalendarViewDayItemChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewDayItemChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ICalendarView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCCalendarView>(arg0), _createRtProxy<WXCCalendarViewDayItemChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewSelectedDatesChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewSelectedDatesChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewSelectedDatesChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::CalendarView*,
                                                       ABI::Windows::UI::Xaml::Controls::CalendarViewSelectedDatesChangedEventArgs*>> {
    void (^_delegate)(WXCCalendarView*, WXCCalendarViewSelectedDatesChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewSelectedDatesChangedEventArgs(
        void (^del)(WXCCalendarView*, WXCCalendarViewSelectedDatesChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_CalendarView_Windows_UI_Xaml_Controls_CalendarViewSelectedDatesChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ICalendarView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ICalendarViewSelectedDatesChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCCalendarView>(arg0), _createRtProxy<WXCCalendarViewSelectedDatesChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_CommandBar_Windows_UI_Xaml_Controls_DynamicOverflowItemsChangingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_CommandBar_Windows_UI_Xaml_Controls_DynamicOverflowItemsChangingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_CommandBar_Windows_UI_Xaml_Controls_DynamicOverflowItemsChangingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::CommandBar*,
                                                       ABI::Windows::UI::Xaml::Controls::DynamicOverflowItemsChangingEventArgs*>> {
    void (^_delegate)(WXCCommandBar*, WXCDynamicOverflowItemsChangingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_CommandBar_Windows_UI_Xaml_Controls_DynamicOverflowItemsChangingEventArgs(
        void (^del)(WXCCommandBar*, WXCDynamicOverflowItemsChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_CommandBar_Windows_UI_Xaml_Controls_DynamicOverflowItemsChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ICommandBar* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IDynamicOverflowItemsChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCCommandBar>(arg0), _createRtProxy<WXCDynamicOverflowItemsChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogButtonClickEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogButtonClickEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogButtonClickEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ContentDialog*,
                                                       ABI::Windows::UI::Xaml::Controls::ContentDialogButtonClickEventArgs*>> {
    void (^_delegate)(WXCContentDialog*, WXCContentDialogButtonClickEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogButtonClickEventArgs(
        void (^del)(WXCContentDialog*, WXCContentDialogButtonClickEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogButtonClickEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IContentDialog* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IContentDialogButtonClickEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCContentDialog>(arg0), _createRtProxy<WXCContentDialogButtonClickEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ContentDialog*,
                                                                       ABI::Windows::UI::Xaml::Controls::ContentDialogClosedEventArgs*>> {
    void (^_delegate)(WXCContentDialog*, WXCContentDialogClosedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosedEventArgs(
        void (^del)(WXCContentDialog*, WXCContentDialogClosedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IContentDialog* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IContentDialogClosedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCContentDialog>(arg0), _createRtProxy<WXCContentDialogClosedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ContentDialog*,
                                                                       ABI::Windows::UI::Xaml::Controls::ContentDialogClosingEventArgs*>> {
    void (^_delegate)(WXCContentDialog*, WXCContentDialogClosingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosingEventArgs(
        void (^del)(WXCContentDialog*, WXCContentDialogClosingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogClosingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IContentDialog* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IContentDialogClosingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCContentDialog>(arg0), _createRtProxy<WXCContentDialogClosingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogOpenedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogOpenedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogOpenedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ContentDialog*,
                                                                       ABI::Windows::UI::Xaml::Controls::ContentDialogOpenedEventArgs*>> {
    void (^_delegate)(WXCContentDialog*, WXCContentDialogOpenedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogOpenedEventArgs(
        void (^del)(WXCContentDialog*, WXCContentDialogOpenedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ContentDialog_Windows_UI_Xaml_Controls_ContentDialogOpenedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IContentDialog* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IContentDialogOpenedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCContentDialog>(arg0), _createRtProxy<WXCContentDialogOpenedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Control*,
                                                                       ABI::Windows::UI::Xaml::Controls::FocusDisengagedEventArgs*>> {
    void (^_delegate)(WXCControl*, WXCFocusDisengagedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs(
        void (^del)(WXCControl*, WXCFocusDisengagedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusDisengagedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IFocusDisengagedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCControl>(arg0), _createRtProxy<WXCFocusDisengagedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Control*,
                                                                       ABI::Windows::UI::Xaml::Controls::FocusEngagedEventArgs*>> {
    void (^_delegate)(WXCControl*, WXCFocusEngagedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs(
        void (^del)(WXCControl*, WXCFocusEngagedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Control_Windows_UI_Xaml_Controls_FocusEngagedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IControl* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IFocusEngagedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCControl>(arg0), _createRtProxy<WXCFocusEngagedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_DatePickerFlyout_Windows_UI_Xaml_Controls_DatePickedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_DatePickerFlyout_Windows_UI_Xaml_Controls_DatePickedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_DatePickerFlyout_Windows_UI_Xaml_Controls_DatePickedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::DatePickerFlyout*,
                                                                       ABI::Windows::UI::Xaml::Controls::DatePickedEventArgs*>> {
    void (^_delegate)(WXCDatePickerFlyout*, WXCDatePickedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_DatePickerFlyout_Windows_UI_Xaml_Controls_DatePickedEventArgs(
        void (^del)(WXCDatePickerFlyout*, WXCDatePickedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_DatePickerFlyout_Windows_UI_Xaml_Controls_DatePickedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IDatePickerFlyout* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IDatePickedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCDatePickerFlyout>(arg0), _createRtProxy<WXCDatePickedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_InkToolbar_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_InkToolbar_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_InkToolbar_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::InkToolbar*, IInspectable*>> {
    void (^_delegate)(WXCInkToolbar*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_InkToolbar_System_Object(void (^del)(WXCInkToolbar*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_InkToolbar_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IInkToolbar* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCInkToolbar>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ListPickerFlyout_Windows_UI_Xaml_Controls_ItemsPickedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ListPickerFlyout_Windows_UI_Xaml_Controls_ItemsPickedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ListPickerFlyout_Windows_UI_Xaml_Controls_ItemsPickedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ListPickerFlyout*,
                                                                       ABI::Windows::UI::Xaml::Controls::ItemsPickedEventArgs*>> {
    void (^_delegate)(WXCListPickerFlyout*, WXCItemsPickedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ListPickerFlyout_Windows_UI_Xaml_Controls_ItemsPickedEventArgs(
        void (^del)(WXCListPickerFlyout*, WXCItemsPickedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ListPickerFlyout_Windows_UI_Xaml_Controls_ItemsPickedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IListPickerFlyout* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IItemsPickedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCListPickerFlyout>(arg0), _createRtProxy<WXCItemsPickedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingGroupHeaderContainerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingGroupHeaderContainerEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingGroupHeaderContainerEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ListViewBase*,
                                                       ABI::Windows::UI::Xaml::Controls::ChoosingGroupHeaderContainerEventArgs*>> {
    void (^_delegate)(WXCListViewBase*, WXCChoosingGroupHeaderContainerEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingGroupHeaderContainerEventArgs(
        void (^del)(WXCListViewBase*, WXCChoosingGroupHeaderContainerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingGroupHeaderContainerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IListViewBase* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IChoosingGroupHeaderContainerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCListViewBase>(arg0), _createRtProxy<WXCChoosingGroupHeaderContainerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingItemContainerEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingItemContainerEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingItemContainerEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ListViewBase*,
                                                                       ABI::Windows::UI::Xaml::Controls::ChoosingItemContainerEventArgs*>> {
    void (^_delegate)(WXCListViewBase*, WXCChoosingItemContainerEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingItemContainerEventArgs(
        void (^del)(WXCListViewBase*, WXCChoosingItemContainerEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ChoosingItemContainerEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IListViewBase* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IChoosingItemContainerEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCListViewBase>(arg0), _createRtProxy<WXCChoosingItemContainerEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ContainerContentChangingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ContainerContentChangingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ContainerContentChangingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ListViewBase*,
                                                       ABI::Windows::UI::Xaml::Controls::ContainerContentChangingEventArgs*>> {
    void (^_delegate)(WXCListViewBase*, WXCContainerContentChangingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ContainerContentChangingEventArgs(
        void (^del)(WXCListViewBase*, WXCContainerContentChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_ContainerContentChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IListViewBase* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IContainerContentChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCListViewBase>(arg0), _createRtProxy<WXCContainerContentChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_DragItemsCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_DragItemsCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_DragItemsCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::ListViewBase*,
                                                                       ABI::Windows::UI::Xaml::Controls::DragItemsCompletedEventArgs*>> {
    void (^_delegate)(WXCListViewBase*, WXCDragItemsCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_DragItemsCompletedEventArgs(
        void (^del)(WXCListViewBase*, WXCDragItemsCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_ListViewBase_Windows_UI_Xaml_Controls_DragItemsCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IListViewBase* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IDragItemsCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCListViewBase>(arg0), _createRtProxy<WXCDragItemsCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_MediaElement_Windows_UI_Xaml_Media_PartialMediaFailureDetectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_MediaElement_Windows_UI_Xaml_Media_PartialMediaFailureDetectedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_MediaElement_Windows_UI_Xaml_Media_PartialMediaFailureDetectedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::MediaElement*,
                                                       ABI::Windows::UI::Xaml::Media::PartialMediaFailureDetectedEventArgs*>> {
    void (^_delegate)(WXCMediaElement*, WUXMPartialMediaFailureDetectedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_MediaElement_Windows_UI_Xaml_Media_PartialMediaFailureDetectedEventArgs(
        void (^del)(WXCMediaElement*, WUXMPartialMediaFailureDetectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_MediaElement_Windows_UI_Xaml_Media_PartialMediaFailureDetectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IMediaElement* arg0,
                                             ABI::Windows::UI::Xaml::Media::IPartialMediaFailureDetectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCMediaElement>(arg0), _createRtProxy<WUXMPartialMediaFailureDetectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_MediaTransportControls_Windows_UI_Xaml_Media_MediaTransportControlsThumbnailRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_MediaTransportControls_Windows_UI_Xaml_Media_MediaTransportControlsThumbnailRequestedEventArgs__DEFINED
class
    ITypedEventHandler_Windows_UI_Xaml_Controls_MediaTransportControls_Windows_UI_Xaml_Media_MediaTransportControlsThumbnailRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::MediaTransportControls*,
                                                       ABI::Windows::UI::Xaml::Media::MediaTransportControlsThumbnailRequestedEventArgs*>> {
    void (^_delegate)(WXCMediaTransportControls*, WUXMMediaTransportControlsThumbnailRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_MediaTransportControls_Windows_UI_Xaml_Media_MediaTransportControlsThumbnailRequestedEventArgs(
        void (^del)(WXCMediaTransportControls*, WUXMMediaTransportControlsThumbnailRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_MediaTransportControls_Windows_UI_Xaml_Media_MediaTransportControlsThumbnailRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::IMediaTransportControls* arg0,
           ABI::Windows::UI::Xaml::Media::IMediaTransportControlsThumbnailRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCMediaTransportControls>(arg0),
                      _createRtProxy<WUXMMediaTransportControlsThumbnailRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_PickerFlyout_Windows_UI_Xaml_Controls_PickerConfirmedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_PickerFlyout_Windows_UI_Xaml_Controls_PickerConfirmedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_PickerFlyout_Windows_UI_Xaml_Controls_PickerConfirmedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::PickerFlyout*,
                                                                       ABI::Windows::UI::Xaml::Controls::PickerConfirmedEventArgs*>> {
    void (^_delegate)(WXCPickerFlyout*, WXCPickerConfirmedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_PickerFlyout_Windows_UI_Xaml_Controls_PickerConfirmedEventArgs(
        void (^del)(WXCPickerFlyout*, WXCPickerConfirmedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_PickerFlyout_Windows_UI_Xaml_Controls_PickerConfirmedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IPickerFlyout* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IPickerConfirmedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCPickerFlyout>(arg0), _createRtProxy<WXCPickerConfirmedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Pivot_Windows_UI_Xaml_Controls_PivotItemEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Pivot_Windows_UI_Xaml_Controls_PivotItemEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Pivot_Windows_UI_Xaml_Controls_PivotItemEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Pivot*,
                                                                       ABI::Windows::UI::Xaml::Controls::PivotItemEventArgs*>> {
    void (^_delegate)(WXCPivot*, WXCPivotItemEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Pivot_Windows_UI_Xaml_Controls_PivotItemEventArgs(void (^del)(WXCPivot*,
                                                                                                              WXCPivotItemEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Pivot_Windows_UI_Xaml_Controls_PivotItemEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IPivot* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IPivotItemEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCPivot>(arg0), _createRtProxy<WXCPivotItemEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_Primitives_FlyoutBase_Windows_UI_Xaml_Controls_Primitives_FlyoutBaseClosingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_Primitives_FlyoutBase_Windows_UI_Xaml_Controls_Primitives_FlyoutBaseClosingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_Primitives_FlyoutBase_Windows_UI_Xaml_Controls_Primitives_FlyoutBaseClosingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutBase*,
                                                       ABI::Windows::UI::Xaml::Controls::Primitives::FlyoutBaseClosingEventArgs*>> {
    void (^_delegate)(WUXCPFlyoutBase*, WUXCPFlyoutBaseClosingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_Primitives_FlyoutBase_Windows_UI_Xaml_Controls_Primitives_FlyoutBaseClosingEventArgs(
        void (^del)(WUXCPFlyoutBase*, WUXCPFlyoutBaseClosingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_Primitives_FlyoutBase_Windows_UI_Xaml_Controls_Primitives_FlyoutBaseClosingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBase* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Primitives::IFlyoutBaseClosingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WUXCPFlyoutBase>(arg0), _createRtProxy<WUXCPFlyoutBaseClosingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::RichEditBox*,
                                                       ABI::Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs*>> {
    void (^_delegate)(WXCRichEditBox*, WXCCandidateWindowBoundsChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs(
        void (^del)(WXCRichEditBox*, WXCCandidateWindowBoundsChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IRichEditBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ICandidateWindowBoundsChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCRichEditBox>(arg0), _createRtProxy<WXCCandidateWindowBoundsChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_RichEditBoxTextChangingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_RichEditBoxTextChangingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_RichEditBoxTextChangingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::RichEditBox*,
                                                       ABI::Windows::UI::Xaml::Controls::RichEditBoxTextChangingEventArgs*>> {
    void (^_delegate)(WXCRichEditBox*, WXCRichEditBoxTextChangingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_RichEditBoxTextChangingEventArgs(
        void (^del)(WXCRichEditBox*, WXCRichEditBoxTextChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_RichEditBoxTextChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IRichEditBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IRichEditBoxTextChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCRichEditBox>(arg0), _createRtProxy<WXCRichEditBoxTextChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::RichEditBox*,
                                                       ABI::Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs*>> {
    void (^_delegate)(WXCRichEditBox*, WXCTextCompositionChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs(
        void (^del)(WXCRichEditBox*, WXCTextCompositionChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IRichEditBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextCompositionChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCRichEditBox>(arg0), _createRtProxy<WXCTextCompositionChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::RichEditBox*,
                                                                       ABI::Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs*>> {
    void (^_delegate)(WXCRichEditBox*, WXCTextCompositionEndedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs(
        void (^del)(WXCRichEditBox*, WXCTextCompositionEndedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IRichEditBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextCompositionEndedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCRichEditBox>(arg0), _createRtProxy<WXCTextCompositionEndedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::RichEditBox*,
                                                       ABI::Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs*>> {
    void (^_delegate)(WXCRichEditBox*, WXCTextCompositionStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs(
        void (^del)(WXCRichEditBox*, WXCTextCompositionStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_RichEditBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IRichEditBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextCompositionStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCRichEditBox>(arg0), _createRtProxy<WXCTextCompositionStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQueryChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQueryChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQueryChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SearchBox*,
                                                                       ABI::Windows::UI::Xaml::Controls::SearchBoxQueryChangedEventArgs*>> {
    void (^_delegate)(WXCSearchBox*, WXCSearchBoxQueryChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQueryChangedEventArgs(
        void (^del)(WXCSearchBox*, WXCSearchBoxQueryChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQueryChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISearchBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISearchBoxQueryChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSearchBox>(arg0), _createRtProxy<WXCSearchBoxQueryChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQuerySubmittedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQuerySubmittedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQuerySubmittedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SearchBox*,
                                                       ABI::Windows::UI::Xaml::Controls::SearchBoxQuerySubmittedEventArgs*>> {
    void (^_delegate)(WXCSearchBox*, WXCSearchBoxQuerySubmittedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQuerySubmittedEventArgs(
        void (^del)(WXCSearchBox*, WXCSearchBoxQuerySubmittedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxQuerySubmittedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISearchBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISearchBoxQuerySubmittedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSearchBox>(arg0), _createRtProxy<WXCSearchBoxQuerySubmittedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxResultSuggestionChosenEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxResultSuggestionChosenEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxResultSuggestionChosenEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SearchBox*,
                                                       ABI::Windows::UI::Xaml::Controls::SearchBoxResultSuggestionChosenEventArgs*>> {
    void (^_delegate)(WXCSearchBox*, WXCSearchBoxResultSuggestionChosenEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxResultSuggestionChosenEventArgs(
        void (^del)(WXCSearchBox*, WXCSearchBoxResultSuggestionChosenEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxResultSuggestionChosenEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISearchBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISearchBoxResultSuggestionChosenEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSearchBox>(arg0), _createRtProxy<WXCSearchBoxResultSuggestionChosenEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxSuggestionsRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxSuggestionsRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxSuggestionsRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SearchBox*,
                                                       ABI::Windows::UI::Xaml::Controls::SearchBoxSuggestionsRequestedEventArgs*>> {
    void (^_delegate)(WXCSearchBox*, WXCSearchBoxSuggestionsRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxSuggestionsRequestedEventArgs(
        void (^del)(WXCSearchBox*, WXCSearchBoxSuggestionsRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_Controls_SearchBoxSuggestionsRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISearchBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISearchBoxSuggestionsRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSearchBox>(arg0), _createRtProxy<WXCSearchBoxSuggestionsRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_RoutedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_RoutedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_RoutedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SearchBox*,
                                                                       ABI::Windows::UI::Xaml::RoutedEventArgs*>> {
    void (^_delegate)(WXCSearchBox*, WXRoutedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_RoutedEventArgs(void (^del)(WXCSearchBox*, WXRoutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SearchBox_Windows_UI_Xaml_RoutedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISearchBox* arg0,
                                             ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSearchBox>(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SplitView*, IInspectable*>> {
    void (^_delegate)(WXCSplitView*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_System_Object(void (^del)(WXCSplitView*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISplitView* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSplitView>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_Windows_UI_Xaml_Controls_SplitViewPaneClosingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_Windows_UI_Xaml_Controls_SplitViewPaneClosingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_Windows_UI_Xaml_Controls_SplitViewPaneClosingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SplitView*,
                                                                       ABI::Windows::UI::Xaml::Controls::SplitViewPaneClosingEventArgs*>> {
    void (^_delegate)(WXCSplitView*, WXCSplitViewPaneClosingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_Windows_UI_Xaml_Controls_SplitViewPaneClosingEventArgs(
        void (^del)(WXCSplitView*, WXCSplitViewPaneClosingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SplitView_Windows_UI_Xaml_Controls_SplitViewPaneClosingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISplitView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISplitViewPaneClosingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSplitView>(arg0), _createRtProxy<WXCSplitViewPaneClosingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_SwapChainPanel_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_SwapChainPanel_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_SwapChainPanel_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::SwapChainPanel*, IInspectable*>> {
    void (^_delegate)(WXCSwapChainPanel*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_SwapChainPanel_System_Object(void (^del)(WXCSwapChainPanel*, RTObject*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_SwapChainPanel_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ISwapChainPanel* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCSwapChainPanel>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::TextBox*,
                                                       ABI::Windows::UI::Xaml::Controls::CandidateWindowBoundsChangedEventArgs*>> {
    void (^_delegate)(WXCTextBox*, WXCCandidateWindowBoundsChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs(
        void (^del)(WXCTextBox*, WXCCandidateWindowBoundsChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_CandidateWindowBoundsChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ITextBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ICandidateWindowBoundsChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCTextBox>(arg0), _createRtProxy<WXCCandidateWindowBoundsChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextBoxTextChangingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextBoxTextChangingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextBoxTextChangingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::TextBox*,
                                                                       ABI::Windows::UI::Xaml::Controls::TextBoxTextChangingEventArgs*>> {
    void (^_delegate)(WXCTextBox*, WXCTextBoxTextChangingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextBoxTextChangingEventArgs(
        void (^del)(WXCTextBox*, WXCTextBoxTextChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextBoxTextChangingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ITextBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextBoxTextChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCTextBox>(arg0), _createRtProxy<WXCTextBoxTextChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::TextBox*,
                                                       ABI::Windows::UI::Xaml::Controls::TextCompositionChangedEventArgs*>> {
    void (^_delegate)(WXCTextBox*, WXCTextCompositionChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs(
        void (^del)(WXCTextBox*, WXCTextCompositionChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ITextBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextCompositionChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCTextBox>(arg0), _createRtProxy<WXCTextCompositionChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::TextBox*,
                                                                       ABI::Windows::UI::Xaml::Controls::TextCompositionEndedEventArgs*>> {
    void (^_delegate)(WXCTextBox*, WXCTextCompositionEndedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs(
        void (^del)(WXCTextBox*, WXCTextCompositionEndedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionEndedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ITextBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextCompositionEndedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCTextBox>(arg0), _createRtProxy<WXCTextCompositionEndedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::TextBox*,
                                                       ABI::Windows::UI::Xaml::Controls::TextCompositionStartedEventArgs*>> {
    void (^_delegate)(WXCTextBox*, WXCTextCompositionStartedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs(
        void (^del)(WXCTextBox*, WXCTextCompositionStartedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_TextBox_Windows_UI_Xaml_Controls_TextCompositionStartedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ITextBox* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextCompositionStartedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCTextBox>(arg0), _createRtProxy<WXCTextCompositionStartedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_TimePickerFlyout_Windows_UI_Xaml_Controls_TimePickedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_TimePickerFlyout_Windows_UI_Xaml_Controls_TimePickedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_TimePickerFlyout_Windows_UI_Xaml_Controls_TimePickedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::TimePickerFlyout*,
                                                                       ABI::Windows::UI::Xaml::Controls::TimePickedEventArgs*>> {
    void (^_delegate)(WXCTimePickerFlyout*, WXCTimePickedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_TimePickerFlyout_Windows_UI_Xaml_Controls_TimePickedEventArgs(
        void (^del)(WXCTimePickerFlyout*, WXCTimePickedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_TimePickerFlyout_Windows_UI_Xaml_Controls_TimePickedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ITimePickerFlyout* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITimePickedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCTimePickerFlyout>(arg0), _createRtProxy<WXCTimePickedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*, IInspectable*>> {
    void (^_delegate)(WXCWebView*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_System_Object(void (^del)(WXCWebView*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewContentLoadingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewContentLoadingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewContentLoadingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                                       ABI::Windows::UI::Xaml::Controls::WebViewContentLoadingEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewContentLoadingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewContentLoadingEventArgs(
        void (^del)(WXCWebView*, WXCWebViewContentLoadingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewContentLoadingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewContentLoadingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewContentLoadingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewDOMContentLoadedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewDOMContentLoadedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewDOMContentLoadedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewDOMContentLoadedEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewDOMContentLoadedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewDOMContentLoadedEventArgs(
        void (^del)(WXCWebView*, WXCWebViewDOMContentLoadedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewDOMContentLoadedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewDOMContentLoadedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewDOMContentLoadedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewLongRunningScriptDetectedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewLongRunningScriptDetectedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewLongRunningScriptDetectedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewLongRunningScriptDetectedEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewLongRunningScriptDetectedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewLongRunningScriptDetectedEventArgs(
        void (^del)(WXCWebView*, WXCWebViewLongRunningScriptDetectedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewLongRunningScriptDetectedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewLongRunningScriptDetectedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewLongRunningScriptDetectedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationCompletedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewNavigationCompletedEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewNavigationCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationCompletedEventArgs(
        void (^del)(WXCWebView*, WXCWebViewNavigationCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewNavigationCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewNavigationCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationStartingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationStartingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationStartingEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewNavigationStartingEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewNavigationStartingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationStartingEventArgs(
        void (^del)(WXCWebView*, WXCWebViewNavigationStartingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNavigationStartingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewNavigationStartingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewNavigationStartingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNewWindowRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNewWindowRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNewWindowRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewNewWindowRequestedEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewNewWindowRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNewWindowRequestedEventArgs(
        void (^del)(WXCWebView*, WXCWebViewNewWindowRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewNewWindowRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewNewWindowRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewNewWindowRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewPermissionRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewPermissionRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewPermissionRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewPermissionRequestedEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewPermissionRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewPermissionRequestedEventArgs(
        void (^del)(WXCWebView*, WXCWebViewPermissionRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewPermissionRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewPermissionRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewPermissionRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnsupportedUriSchemeIdentifiedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnsupportedUriSchemeIdentifiedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnsupportedUriSchemeIdentifiedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewUnsupportedUriSchemeIdentifiedEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnsupportedUriSchemeIdentifiedEventArgs(
        void (^del)(WXCWebView*, WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnsupportedUriSchemeIdentifiedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
           ABI::Windows::UI::Xaml::Controls::IWebViewUnsupportedUriSchemeIdentifiedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnviewableContentIdentifiedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnviewableContentIdentifiedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnviewableContentIdentifiedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::Controls::WebView*,
                                                       ABI::Windows::UI::Xaml::Controls::WebViewUnviewableContentIdentifiedEventArgs*>> {
    void (^_delegate)(WXCWebView*, WXCWebViewUnviewableContentIdentifiedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnviewableContentIdentifiedEventArgs(
        void (^del)(WXCWebView*, WXCWebViewUnviewableContentIdentifiedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_Controls_WebView_Windows_UI_Xaml_Controls_WebViewUnviewableContentIdentifiedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE
    Invoke(ABI::Windows::UI::Xaml::Controls::IWebView* arg0,
           ABI::Windows::UI::Xaml::Controls::IWebViewUnviewableContentIdentifiedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCWebView>(arg0), _createRtProxy<WXCWebViewUnviewableContentIdentifiedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::FrameworkElement*, IInspectable*>> {
    void (^_delegate)(WXFrameworkElement*, RTObject*);

public:
    ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object(void (^del)(WXFrameworkElement*, RTObject*)) : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_System_Object() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IFrameworkElement* arg0, IInspectable* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXFrameworkElement>(arg0), _createBareRTObj(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::FrameworkElement*,
                                                                       ABI::Windows::UI::Xaml::DataContextChangedEventArgs*>> {
    void (^_delegate)(WXFrameworkElement*, WXDataContextChangedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs(
        void (^del)(WXFrameworkElement*, WXDataContextChangedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_FrameworkElement_Windows_UI_Xaml_DataContextChangedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IFrameworkElement* arg0,
                                             ABI::Windows::UI::Xaml::IDataContextChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXFrameworkElement>(arg0), _createRtProxy<WXDataContextChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::DragStartingEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXDragStartingEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs(void (^del)(WXUIElement*, WXDragStartingEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DragStartingEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IDragStartingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXDragStartingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::DropCompletedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXDropCompletedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs(void (^del)(WXUIElement*,
                                                                                                    WXDropCompletedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_DropCompletedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IDropCompletedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXDropCompletedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                       ABI::Windows::UI::Xaml::Input::AccessKeyDisplayDismissedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayDismissedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayDismissedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyDisplayDismissedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                       ABI::Windows::UI::Xaml::Input::AccessKeyDisplayRequestedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyDisplayRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyDisplayRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyDisplayRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::Input::AccessKeyInvokedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs(
        void (^del)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_AccessKeyInvokedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IAccessKeyInvokedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIAccessKeyInvokedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*,
                                                                       ABI::Windows::UI::Xaml::Input::ContextRequestedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WUXIContextRequestedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs(
        void (^del)(WXUIElement*, WUXIContextRequestedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_Input_ContextRequestedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::Input::IContextRequestedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WUXIContextRequestedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs__DEFINED
#define __ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs__DEFINED
class ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs
    : public RuntimeClass<
          RuntimeClassFlags<WinRtClassicComMix>,
          ABI::Windows::Foundation::ITypedEventHandler<ABI::Windows::UI::Xaml::UIElement*, ABI::Windows::UI::Xaml::RoutedEventArgs*>> {
    void (^_delegate)(WXUIElement*, WXRoutedEventArgs*);

public:
    ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs(void (^del)(WXUIElement*, WXRoutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~ITypedEventHandler_Windows_UI_Xaml_UIElement_Windows_UI_Xaml_RoutedEventArgs() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IUIElement* arg0,
                                             ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXUIElement>(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXCPItemsChangedEventHandler_shim__DEFINED
#define __WUXCPItemsChangedEventHandler_shim__DEFINED
class WUXCPItemsChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventHandler> {
    void (^_delegate)(RTObject*, WUXCPItemsChangedEventArgs*);

public:
    WUXCPItemsChangedEventHandler_shim(void (^del)(RTObject*, WUXCPItemsChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXCPItemsChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXCPItemsChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXCPRangeBaseValueChangedEventHandler_shim__DEFINED
#define __WUXCPRangeBaseValueChangedEventHandler_shim__DEFINED
class WUXCPRangeBaseValueChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventHandler> {
    void (^_delegate)(RTObject*, WUXCPRangeBaseValueChangedEventArgs*);

public:
    WUXCPRangeBaseValueChangedEventHandler_shim(void (^del)(RTObject*, WUXCPRangeBaseValueChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXCPRangeBaseValueChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::Primitives::IRangeBaseValueChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXCPRangeBaseValueChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXDPropertyChangedEventHandler_shim__DEFINED
#define __WUXDPropertyChangedEventHandler_shim__DEFINED
class WUXDPropertyChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Data::IPropertyChangedEventHandler> {
    void (^_delegate)(RTObject*, WUXDPropertyChangedEventArgs*);

public:
    WUXDPropertyChangedEventHandler_shim(void (^del)(RTObject*, WUXDPropertyChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXDPropertyChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Data::IPropertyChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXDPropertyChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIDoubleTappedEventHandler_shim__DEFINED
#define __WUXIDoubleTappedEventHandler_shim__DEFINED
class WUXIDoubleTappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IDoubleTappedEventHandler> {
    void (^_delegate)(RTObject*, WUXIDoubleTappedRoutedEventArgs*);

public:
    WUXIDoubleTappedEventHandler_shim(void (^del)(RTObject*, WUXIDoubleTappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIDoubleTappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIDoubleTappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIHoldingEventHandler_shim__DEFINED
#define __WUXIHoldingEventHandler_shim__DEFINED
class WUXIHoldingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IHoldingEventHandler> {
    void (^_delegate)(RTObject*, WUXIHoldingRoutedEventArgs*);

public:
    WUXIHoldingEventHandler_shim(void (^del)(RTObject*, WUXIHoldingRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIHoldingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIHoldingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIKeyEventHandler_shim__DEFINED
#define __WUXIKeyEventHandler_shim__DEFINED
class WUXIKeyEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IKeyEventHandler> {
    void (^_delegate)(RTObject*, WUXIKeyRoutedEventArgs*);

public:
    WUXIKeyEventHandler_shim(void (^del)(RTObject*, WUXIKeyRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIKeyEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIKeyRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationCompletedEventHandler_shim__DEFINED
#define __WUXIManipulationCompletedEventHandler_shim__DEFINED
class WUXIManipulationCompletedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationCompletedEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationCompletedRoutedEventArgs*);

public:
    WUXIManipulationCompletedEventHandler_shim(void (^del)(RTObject*, WUXIManipulationCompletedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationCompletedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationCompletedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationDeltaEventHandler_shim__DEFINED
#define __WUXIManipulationDeltaEventHandler_shim__DEFINED
class WUXIManipulationDeltaEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationDeltaEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationDeltaRoutedEventArgs*);

public:
    WUXIManipulationDeltaEventHandler_shim(void (^del)(RTObject*, WUXIManipulationDeltaRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationDeltaEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationDeltaRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationInertiaStartingEventHandler_shim__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler_shim__DEFINED
class WUXIManipulationInertiaStartingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationInertiaStartingRoutedEventArgs*);

public:
    WUXIManipulationInertiaStartingEventHandler_shim(void (^del)(RTObject*, WUXIManipulationInertiaStartingRoutedEventArgs*))
        : _delegate([del copy]) {
    }
    ~WUXIManipulationInertiaStartingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationInertiaStartingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationStartedEventHandler_shim__DEFINED
#define __WUXIManipulationStartedEventHandler_shim__DEFINED
class WUXIManipulationStartedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationStartedEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationStartedRoutedEventArgs*);

public:
    WUXIManipulationStartedEventHandler_shim(void (^del)(RTObject*, WUXIManipulationStartedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationStartedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationStartedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIManipulationStartingEventHandler_shim__DEFINED
#define __WUXIManipulationStartingEventHandler_shim__DEFINED
class WUXIManipulationStartingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IManipulationStartingEventHandler> {
    void (^_delegate)(RTObject*, WUXIManipulationStartingRoutedEventArgs*);

public:
    WUXIManipulationStartingEventHandler_shim(void (^del)(RTObject*, WUXIManipulationStartingRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIManipulationStartingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIManipulationStartingRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIPointerEventHandler_shim__DEFINED
#define __WUXIPointerEventHandler_shim__DEFINED
class WUXIPointerEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IPointerEventHandler> {
    void (^_delegate)(RTObject*, WUXIPointerRoutedEventArgs*);

public:
    WUXIPointerEventHandler_shim(void (^del)(RTObject*, WUXIPointerRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIPointerEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIPointerRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXIRightTappedEventHandler_shim__DEFINED
#define __WUXIRightTappedEventHandler_shim__DEFINED
class WUXIRightTappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::IRightTappedEventHandler> {
    void (^_delegate)(RTObject*, WUXIRightTappedRoutedEventArgs*);

public:
    WUXIRightTappedEventHandler_shim(void (^del)(RTObject*, WUXIRightTappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXIRightTappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXIRightTappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXITappedEventHandler_shim__DEFINED
#define __WUXITappedEventHandler_shim__DEFINED
class WUXITappedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Input::ITappedEventHandler> {
    void (^_delegate)(RTObject*, WUXITappedRoutedEventArgs*);

public:
    WUXITappedEventHandler_shim(void (^del)(RTObject*, WUXITappedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXITappedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXITappedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXMRateChangedRoutedEventHandler_shim__DEFINED
#define __WUXMRateChangedRoutedEventHandler_shim__DEFINED
class WUXMRateChangedRoutedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Media::IRateChangedRoutedEventHandler> {
    void (^_delegate)(RTObject*, WUXMRateChangedRoutedEventArgs*);

public:
    WUXMRateChangedRoutedEventHandler_shim(void (^del)(RTObject*, WUXMRateChangedRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXMRateChangedRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Media::IRateChangedRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXMRateChangedRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXMTimelineMarkerRoutedEventHandler_shim__DEFINED
#define __WUXMTimelineMarkerRoutedEventHandler_shim__DEFINED
class WUXMTimelineMarkerRoutedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventHandler> {
    void (^_delegate)(RTObject*, WUXMTimelineMarkerRoutedEventArgs*);

public:
    WUXMTimelineMarkerRoutedEventHandler_shim(void (^del)(RTObject*, WUXMTimelineMarkerRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXMTimelineMarkerRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Media::ITimelineMarkerRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXMTimelineMarkerRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXNLoadCompletedEventHandler_shim__DEFINED
#define __WUXNLoadCompletedEventHandler_shim__DEFINED
class WUXNLoadCompletedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Navigation::ILoadCompletedEventHandler> {
    void (^_delegate)(RTObject*, WUXNNavigationEventArgs*);

public:
    WUXNLoadCompletedEventHandler_shim(void (^del)(RTObject*, WUXNNavigationEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXNLoadCompletedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXNNavigationEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXNNavigatedEventHandler_shim__DEFINED
#define __WUXNNavigatedEventHandler_shim__DEFINED
class WUXNNavigatedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Navigation::INavigatedEventHandler> {
    void (^_delegate)(RTObject*, WUXNNavigationEventArgs*);

public:
    WUXNNavigatedEventHandler_shim(void (^del)(RTObject*, WUXNNavigationEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXNNavigatedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXNNavigationEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXNNavigatingCancelEventHandler_shim__DEFINED
#define __WUXNNavigatingCancelEventHandler_shim__DEFINED
class WUXNNavigatingCancelEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventHandler> {
    void (^_delegate)(RTObject*, WUXNNavigatingCancelEventArgs*);

public:
    WUXNNavigatingCancelEventHandler_shim(void (^del)(RTObject*, WUXNNavigatingCancelEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXNNavigatingCancelEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXNNavigatingCancelEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXNNavigationFailedEventHandler_shim__DEFINED
#define __WUXNNavigationFailedEventHandler_shim__DEFINED
class WUXNNavigationFailedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventHandler> {
    void (^_delegate)(RTObject*, WUXNNavigationFailedEventArgs*);

public:
    WUXNNavigationFailedEventHandler_shim(void (^del)(RTObject*, WUXNNavigationFailedEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXNNavigationFailedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Navigation::INavigationFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXNNavigationFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WUXNNavigationStoppedEventHandler_shim__DEFINED
#define __WUXNNavigationStoppedEventHandler_shim__DEFINED
class WUXNNavigationStoppedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Navigation::INavigationStoppedEventHandler> {
    void (^_delegate)(RTObject*, WUXNNavigationEventArgs*);

public:
    WUXNNavigationStoppedEventHandler_shim(void (^del)(RTObject*, WUXNNavigationEventArgs*)) : _delegate([del copy]) {
    }
    ~WUXNNavigationStoppedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WUXNNavigationEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCBackClickEventHandler_shim__DEFINED
#define __WXCBackClickEventHandler_shim__DEFINED
class WXCBackClickEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::IBackClickEventHandler> {
    void (^_delegate)(RTObject*, WXCBackClickEventArgs*);

public:
    WXCBackClickEventHandler_shim(void (^del)(RTObject*, WXCBackClickEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCBackClickEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Controls::IBackClickEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCBackClickEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCCalendarViewDayItemChangingEventHandler_shim__DEFINED
#define __WXCCalendarViewDayItemChangingEventHandler_shim__DEFINED
class WXCCalendarViewDayItemChangingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>,
                          ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventHandler> {
    void (^_delegate)(WXCCalendarView*, WXCCalendarViewDayItemChangingEventArgs*);

public:
    WXCCalendarViewDayItemChangingEventHandler_shim(void (^del)(WXCCalendarView*, WXCCalendarViewDayItemChangingEventArgs*))
        : _delegate([del copy]) {
    }
    ~WXCCalendarViewDayItemChangingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::Controls::ICalendarView* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ICalendarViewDayItemChangingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXCCalendarView>(arg0), _createRtProxy<WXCCalendarViewDayItemChangingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCCleanUpVirtualizedItemEventHandler_shim__DEFINED
#define __WXCCleanUpVirtualizedItemEventHandler_shim__DEFINED
class WXCCleanUpVirtualizedItemEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventHandler> {
    void (^_delegate)(RTObject*, WXCCleanUpVirtualizedItemEventArgs*);

public:
    WXCCleanUpVirtualizedItemEventHandler_shim(void (^del)(RTObject*, WXCCleanUpVirtualizedItemEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCCleanUpVirtualizedItemEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCCleanUpVirtualizedItemEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCContextMenuOpeningEventHandler_shim__DEFINED
#define __WXCContextMenuOpeningEventHandler_shim__DEFINED
class WXCContextMenuOpeningEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::IContextMenuOpeningEventHandler> {
    void (^_delegate)(RTObject*, WXCContextMenuEventArgs*);

public:
    WXCContextMenuOpeningEventHandler_shim(void (^del)(RTObject*, WXCContextMenuEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCContextMenuOpeningEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Controls::IContextMenuEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCContextMenuEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCDragItemsStartingEventHandler_shim__DEFINED
#define __WXCDragItemsStartingEventHandler_shim__DEFINED
class WXCDragItemsStartingEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::IDragItemsStartingEventHandler> {
    void (^_delegate)(RTObject*, WXCDragItemsStartingEventArgs*);

public:
    WXCDragItemsStartingEventHandler_shim(void (^del)(RTObject*, WXCDragItemsStartingEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCDragItemsStartingEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IDragItemsStartingEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCDragItemsStartingEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCHubSectionHeaderClickEventHandler_shim__DEFINED
#define __WXCHubSectionHeaderClickEventHandler_shim__DEFINED
class WXCHubSectionHeaderClickEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventHandler> {
    void (^_delegate)(RTObject*, WXCHubSectionHeaderClickEventArgs*);

public:
    WXCHubSectionHeaderClickEventHandler_shim(void (^del)(RTObject*, WXCHubSectionHeaderClickEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCHubSectionHeaderClickEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IHubSectionHeaderClickEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCHubSectionHeaderClickEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCItemClickEventHandler_shim__DEFINED
#define __WXCItemClickEventHandler_shim__DEFINED
class WXCItemClickEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::IItemClickEventHandler> {
    void (^_delegate)(RTObject*, WXCItemClickEventArgs*);

public:
    WXCItemClickEventHandler_shim(void (^del)(RTObject*, WXCItemClickEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCItemClickEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Controls::IItemClickEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCItemClickEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCListViewItemToKeyHandler_shim__DEFINED
#define __WXCListViewItemToKeyHandler_shim__DEFINED
class WXCListViewItemToKeyHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::IListViewItemToKeyHandler> {
    void (^_delegate)(RTObject*);

public:
    WXCListViewItemToKeyHandler_shim(void (^del)(RTObject*)) : _delegate([del copy]) {
    }
    ~WXCListViewItemToKeyHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, HSTRING*) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0));
            return 0;
        };
    }
};
#endif

#ifndef __WXCNotifyEventHandler_shim__DEFINED
#define __WXCNotifyEventHandler_shim__DEFINED
class WXCNotifyEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::INotifyEventHandler> {
    void (^_delegate)(RTObject*, WXCNotifyEventArgs*);

public:
    WXCNotifyEventHandler_shim(void (^del)(RTObject*, WXCNotifyEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCNotifyEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Controls::INotifyEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCNotifyEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCSectionsInViewChangedEventHandler_shim__DEFINED
#define __WXCSectionsInViewChangedEventHandler_shim__DEFINED
class WXCSectionsInViewChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::ISectionsInViewChangedEventHandler> {
    void (^_delegate)(RTObject*, WXCSectionsInViewChangedEventArgs*);

public:
    WXCSectionsInViewChangedEventHandler_shim(void (^del)(RTObject*, WXCSectionsInViewChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCSectionsInViewChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISectionsInViewChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCSectionsInViewChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCSelectionChangedEventHandler_shim__DEFINED
#define __WXCSelectionChangedEventHandler_shim__DEFINED
class WXCSelectionChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::ISelectionChangedEventHandler> {
    void (^_delegate)(RTObject*, WXCSelectionChangedEventArgs*);

public:
    WXCSelectionChangedEventHandler_shim(void (^del)(RTObject*, WXCSelectionChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCSelectionChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISelectionChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCSelectionChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCSemanticZoomViewChangedEventHandler_shim__DEFINED
#define __WXCSemanticZoomViewChangedEventHandler_shim__DEFINED
class WXCSemanticZoomViewChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventHandler> {
    void (^_delegate)(RTObject*, WXCSemanticZoomViewChangedEventArgs*);

public:
    WXCSemanticZoomViewChangedEventHandler_shim(void (^del)(RTObject*, WXCSemanticZoomViewChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCSemanticZoomViewChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ISemanticZoomViewChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCSemanticZoomViewChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCTextChangedEventHandler_shim__DEFINED
#define __WXCTextChangedEventHandler_shim__DEFINED
class WXCTextChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::ITextChangedEventHandler> {
    void (^_delegate)(RTObject*, WXCTextChangedEventArgs*);

public:
    WXCTextChangedEventHandler_shim(void (^del)(RTObject*, WXCTextChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCTextChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::Controls::ITextChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCTextChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCTextControlPasteEventHandler_shim__DEFINED
#define __WXCTextControlPasteEventHandler_shim__DEFINED
class WXCTextControlPasteEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::ITextControlPasteEventHandler> {
    void (^_delegate)(RTObject*, WXCTextControlPasteEventArgs*);

public:
    WXCTextControlPasteEventHandler_shim(void (^del)(RTObject*, WXCTextControlPasteEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCTextControlPasteEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::ITextControlPasteEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCTextControlPasteEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXCWebViewNavigationFailedEventHandler_shim__DEFINED
#define __WXCWebViewNavigationFailedEventHandler_shim__DEFINED
class WXCWebViewNavigationFailedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventHandler> {
    void (^_delegate)(RTObject*, WXCWebViewNavigationFailedEventArgs*);

public:
    WXCWebViewNavigationFailedEventHandler_shim(void (^del)(RTObject*, WXCWebViewNavigationFailedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXCWebViewNavigationFailedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::Controls::IWebViewNavigationFailedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXCWebViewNavigationFailedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDependencyPropertyChangedCallback_shim__DEFINED
#define __WXDependencyPropertyChangedCallback_shim__DEFINED
class WXDependencyPropertyChangedCallback_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDependencyPropertyChangedCallback> {
    void (^_delegate)(WXDependencyObject*, WXDependencyProperty*);

public:
    WXDependencyPropertyChangedCallback_shim(void (^del)(WXDependencyObject*, WXDependencyProperty*)) : _delegate([del copy]) {
    }
    ~WXDependencyPropertyChangedCallback_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(ABI::Windows::UI::Xaml::IDependencyObject* arg0,
                                             ABI::Windows::UI::Xaml::IDependencyProperty* arg1) override {
        @autoreleasepool {
            _delegate(_createRtProxy<WXDependencyObject>(arg0), _createRtProxy<WXDependencyProperty>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDependencyPropertyChangedEventHandler_shim__DEFINED
#define __WXDependencyPropertyChangedEventHandler_shim__DEFINED
class WXDependencyPropertyChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventHandler> {
    void (^_delegate)(RTObject*, WXDependencyPropertyChangedEventArgs*);

public:
    WXDependencyPropertyChangedEventHandler_shim(void (^del)(RTObject*, WXDependencyPropertyChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXDependencyPropertyChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0,
                                             ABI::Windows::UI::Xaml::IDependencyPropertyChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXDependencyPropertyChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXDragEventHandler_shim__DEFINED
#define __WXDragEventHandler_shim__DEFINED
class WXDragEventHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IDragEventHandler> {
    void (^_delegate)(RTObject*, WXDragEventArgs*);

public:
    WXDragEventHandler_shim(void (^del)(RTObject*, WXDragEventArgs*)) : _delegate([del copy]) {
    }
    ~WXDragEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IDragEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXDragEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXExceptionRoutedEventHandler_shim__DEFINED
#define __WXExceptionRoutedEventHandler_shim__DEFINED
class WXExceptionRoutedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IExceptionRoutedEventHandler> {
    void (^_delegate)(RTObject*, WXExceptionRoutedEventArgs*);

public:
    WXExceptionRoutedEventHandler_shim(void (^del)(RTObject*, WXExceptionRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXExceptionRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IExceptionRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXExceptionRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXRoutedEventHandler_shim__DEFINED
#define __WXRoutedEventHandler_shim__DEFINED
class WXRoutedEventHandler_shim : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::IRoutedEventHandler> {
    void (^_delegate)(RTObject*, WXRoutedEventArgs*);

public:
    WXRoutedEventHandler_shim(void (^del)(RTObject*, WXRoutedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXRoutedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::IRoutedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXRoutedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

#ifndef __WXSizeChangedEventHandler_shim__DEFINED
#define __WXSizeChangedEventHandler_shim__DEFINED
class WXSizeChangedEventHandler_shim
    : public RuntimeClass<RuntimeClassFlags<WinRtClassicComMix>, ABI::Windows::UI::Xaml::ISizeChangedEventHandler> {
    void (^_delegate)(RTObject*, WXSizeChangedEventArgs*);

public:
    WXSizeChangedEventHandler_shim(void (^del)(RTObject*, WXSizeChangedEventArgs*)) : _delegate([del copy]) {
    }
    ~WXSizeChangedEventHandler_shim() {
        [_delegate release];
    }
    virtual HRESULT STDMETHODCALLTYPE GetTrustLevel(TrustLevel* trustLevel) override {
        *trustLevel = BaseTrust;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE Invoke(IInspectable* arg0, ABI::Windows::UI::Xaml::ISizeChangedEventArgs* arg1) override {
        @autoreleasepool {
            _delegate(_createBareRTObj(arg0), _createRtProxy<WXSizeChangedEventArgs>(arg1));
            return 0;
        };
    }
};
#endif

class WXCIDataTemplateSelectorOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIDataTemplateSelectorOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXCIDataTemplateSelectorOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE SelectTemplateCore(IInspectable* item_in,
                                                 ABI::Windows::UI::Xaml::IDependencyObject* container_in,
                                                 ABI::Windows::UI::Xaml::IDataTemplate** ret) override {
        auto unmarshaledRet =
            [_inner selectTemplateCore:_createBareRTObj(item_in) container:_createRtProxy<WXDependencyObject>(container_in)];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::IDataTemplate>(unmarshaledRet).Detach();
        return 0;
    }
};

class WXCIDataTemplateSelectorOverrides2_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IDataTemplateSelectorOverrides2, ComposableBase<>> {
    InspectableClass(L"WXCIDataTemplateSelectorOverrides2_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXCIDataTemplateSelectorOverrides2>* _inner;
    HRESULT STDMETHODCALLTYPE SelectTemplateForItemCore(IInspectable* item_in, ABI::Windows::UI::Xaml::IDataTemplate** ret) override {
        auto unmarshaledRet = [_inner selectTemplateForItemCore:_createBareRTObj(item_in)];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::IDataTemplate>(unmarshaledRet).Detach();
        return 0;
    }
};

class WXCIGroupStyleSelectorOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IGroupStyleSelectorOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIGroupStyleSelectorOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXCIGroupStyleSelectorOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE SelectGroupStyleCore(IInspectable* group_in,
                                                   unsigned int level_in,
                                                   ABI::Windows::UI::Xaml::Controls::IGroupStyle** ret) override {
        auto unmarshaledRet = [_inner selectGroupStyleCore:_createBareRTObj(group_in) level:level_in];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::Controls::IGroupStyle>(unmarshaledRet).Detach();
        return 0;
    }
};

class WXCIStyleSelectorOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IStyleSelectorOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIStyleSelectorOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIStyleSelectorOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE SelectStyleCore(IInspectable* item_in,
                                              ABI::Windows::UI::Xaml::IDependencyObject* container_in,
                                              ABI::Windows::UI::Xaml::IStyle** ret) override {
        auto unmarshaledRet = [_inner selectStyleCore:_createBareRTObj(item_in) container:_createRtProxy<WXDependencyObject>(container_in)];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::IStyle>(unmarshaledRet).Detach();
        return 0;
    }
};

class WXCIContentPresenterOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IContentPresenterOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIContentPresenterOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXCIContentPresenterOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnContentTemplateChanged(ABI::Windows::UI::Xaml::IDataTemplate* oldContentTemplate_in,
                                                       ABI::Windows::UI::Xaml::IDataTemplate* newContentTemplate_in) override {
        [_inner onContentTemplateChanged:_createRtProxy<WXDataTemplate>(oldContentTemplate_in)
                      newContentTemplate:_createRtProxy<WXDataTemplate>(newContentTemplate_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnContentTemplateSelectorChanged(ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector* oldContentTemplateSelector_in,
                                     ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector* newContentTemplateSelector_in) override {
        [_inner onContentTemplateSelectorChanged:_createRtProxy<WXCDataTemplateSelector>(oldContentTemplateSelector_in)
                      newContentTemplateSelector:_createRtProxy<WXCDataTemplateSelector>(newContentTemplateSelector_in)];
        return 0;
    }
};

class WXCIContentControlOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IContentControlOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIContentControlOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIContentControlOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnContentChanged(IInspectable* oldContent_in, IInspectable* newContent_in) override {
        [_inner onContentChanged:_createBareRTObj(oldContent_in) newContent:_createBareRTObj(newContent_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnContentTemplateChanged(ABI::Windows::UI::Xaml::IDataTemplate* oldContentTemplate_in,
                                                       ABI::Windows::UI::Xaml::IDataTemplate* newContentTemplate_in) override {
        [_inner onContentTemplateChanged:_createRtProxy<WXDataTemplate>(oldContentTemplate_in)
                      newContentTemplate:_createRtProxy<WXDataTemplate>(newContentTemplate_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnContentTemplateSelectorChanged(ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector* oldContentTemplateSelector_in,
                                     ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector* newContentTemplateSelector_in) override {
        [_inner onContentTemplateSelectorChanged:_createRtProxy<WXCDataTemplateSelector>(oldContentTemplateSelector_in)
                      newContentTemplateSelector:_createRtProxy<WXCDataTemplateSelector>(newContentTemplateSelector_in)];
        return 0;
    }
};

class WXCIItemsControlOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IItemsControlOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIItemsControlOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIItemsControlOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE IsItemItsOwnContainerOverride(IInspectable* item_in, boolean* ret) override {
        auto unmarshaledRet = [_inner isItemItsOwnContainerOverride:_createBareRTObj(item_in)];
        *ret = (boolean)unmarshaledRet;
        return 0;
    }
    HRESULT STDMETHODCALLTYPE GetContainerForItemOverride(ABI::Windows::UI::Xaml::IDependencyObject** ret) override {
        auto unmarshaledRet = [_inner getContainerForItemOverride];
        *ret = _getRtInterface<ABI::Windows::UI::Xaml::IDependencyObject>(unmarshaledRet).Detach();
        return 0;
    }
    HRESULT STDMETHODCALLTYPE ClearContainerForItemOverride(ABI::Windows::UI::Xaml::IDependencyObject* element_in,
                                                            IInspectable* item_in) override {
        [_inner clearContainerForItemOverride:_createRtProxy<WXDependencyObject>(element_in) item:_createBareRTObj(item_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE PrepareContainerForItemOverride(ABI::Windows::UI::Xaml::IDependencyObject* element_in,
                                                              IInspectable* item_in) override {
        [_inner prepareContainerForItemOverride:_createRtProxy<WXDependencyObject>(element_in) item:_createBareRTObj(item_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnItemsChanged(IInspectable* e_in) override {
        [_inner onItemsChanged:_createBareRTObj(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnItemContainerStyleChanged(ABI::Windows::UI::Xaml::IStyle* oldItemContainerStyle_in,
                                                          ABI::Windows::UI::Xaml::IStyle* newItemContainerStyle_in) override {
        [_inner onItemContainerStyleChanged:_createRtProxy<WXStyle>(oldItemContainerStyle_in)
                      newItemContainerStyle:_createRtProxy<WXStyle>(newItemContainerStyle_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnItemContainerStyleSelectorChanged(ABI::Windows::UI::Xaml::Controls::IStyleSelector* oldItemContainerStyleSelector_in,
                                        ABI::Windows::UI::Xaml::Controls::IStyleSelector* newItemContainerStyleSelector_in) override {
        [_inner onItemContainerStyleSelectorChanged:_createRtProxy<WXCStyleSelector>(oldItemContainerStyleSelector_in)
                      newItemContainerStyleSelector:_createRtProxy<WXCStyleSelector>(newItemContainerStyleSelector_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnItemTemplateChanged(ABI::Windows::UI::Xaml::IDataTemplate* oldItemTemplate_in,
                                                    ABI::Windows::UI::Xaml::IDataTemplate* newItemTemplate_in) override {
        [_inner onItemTemplateChanged:_createRtProxy<WXDataTemplate>(oldItemTemplate_in)
                      newItemTemplate:_createRtProxy<WXDataTemplate>(newItemTemplate_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnItemTemplateSelectorChanged(ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector* oldItemTemplateSelector_in,
                                  ABI::Windows::UI::Xaml::Controls::IDataTemplateSelector* newItemTemplateSelector_in) override {
        [_inner onItemTemplateSelectorChanged:_createRtProxy<WXCDataTemplateSelector>(oldItemTemplateSelector_in)
                      newItemTemplateSelector:_createRtProxy<WXCDataTemplateSelector>(newItemTemplateSelector_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnGroupStyleSelectorChanged(ABI::Windows::UI::Xaml::Controls::IGroupStyleSelector* oldGroupStyleSelector_in,
                                ABI::Windows::UI::Xaml::Controls::IGroupStyleSelector* newGroupStyleSelector_in) override {
        [_inner onGroupStyleSelectorChanged:_createRtProxy<WXCGroupStyleSelector>(oldGroupStyleSelector_in)
                      newGroupStyleSelector:_createRtProxy<WXCGroupStyleSelector>(newGroupStyleSelector_in)];
        return 0;
    }
};

class WXCIToggleSwitchOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IToggleSwitchOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIToggleSwitchOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIToggleSwitchOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnToggled() override {
        [_inner onToggled];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnOnContentChanged(IInspectable* oldContent_in, IInspectable* newContent_in) override {
        [_inner onOnContentChanged:_createBareRTObj(oldContent_in) newContent:_createBareRTObj(newContent_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnOffContentChanged(IInspectable* oldContent_in, IInspectable* newContent_in) override {
        [_inner onOffContentChanged:_createBareRTObj(oldContent_in) newContent:_createBareRTObj(newContent_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnHeaderChanged(IInspectable* oldContent_in, IInspectable* newContent_in) override {
        [_inner onHeaderChanged:_createBareRTObj(oldContent_in) newContent:_createBareRTObj(newContent_in)];
        return 0;
    }
};

class WXCIVirtualizingPanelOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IVirtualizingPanelOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIVirtualizingPanelOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXCIVirtualizingPanelOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnItemsChanged(IInspectable* sender_in,
                                             ABI::Windows::UI::Xaml::Controls::Primitives::IItemsChangedEventArgs* args_in) override {
        [_inner onItemsChanged:_createBareRTObj(sender_in) args:_createRtProxy<WUXCPItemsChangedEventArgs>(args_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnClearChildren() override {
        [_inner onClearChildren];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE BringIndexIntoView(int index_in) override {
        [_inner bringIndexIntoView:index_in];
        return 0;
    }
};

class WXCIComboBoxOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IComboBoxOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIComboBoxOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIComboBoxOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnDropDownClosed(IInspectable* e_in) override {
        [_inner onDropDownClosed:_createBareRTObj(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnDropDownOpened(IInspectable* e_in) override {
        [_inner onDropDownOpened:_createBareRTObj(e_in)];
        return 0;
    }
};

class WXCIVirtualizingStackPanelOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IVirtualizingStackPanelOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIVirtualizingStackPanelOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXCIVirtualizingStackPanelOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnCleanUpVirtualizedItem(ABI::Windows::UI::Xaml::Controls::ICleanUpVirtualizedItemEventArgs* e_in) override {
        [_inner onCleanUpVirtualizedItem:_createRtProxy<WXCCleanUpVirtualizedItemEventArgs>(e_in)];
        return 0;
    }
};

class WXCIAppBarOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IAppBarOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIAppBarOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIAppBarOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnClosed(IInspectable* e_in) override {
        [_inner onClosed:_createBareRTObj(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnOpened(IInspectable* e_in) override {
        [_inner onOpened:_createBareRTObj(e_in)];
        return 0;
    }
};

class WXCIAppBarOverrides3_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IAppBarOverrides3, ComposableBase<>> {
    InspectableClass(L"WXCIAppBarOverrides3_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIAppBarOverrides3>* _inner;
    HRESULT STDMETHODCALLTYPE OnClosing(IInspectable* e_in) override {
        [_inner onClosing:_createBareRTObj(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnOpening(IInspectable* e_in) override {
        [_inner onOpening:_createBareRTObj(e_in)];
        return 0;
    }
};

class WXCIPageOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IPageOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIPageOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIPageOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnNavigatedFrom(ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs* e_in) override {
        [_inner onNavigatedFrom:_createRtProxy<WUXNNavigationEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnNavigatedTo(ABI::Windows::UI::Xaml::Navigation::INavigationEventArgs* e_in) override {
        [_inner onNavigatedTo:_createRtProxy<WUXNNavigationEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnNavigatingFrom(ABI::Windows::UI::Xaml::Navigation::INavigatingCancelEventArgs* e_in) override {
        [_inner onNavigatingFrom:_createRtProxy<WUXNNavigatingCancelEventArgs>(e_in)];
        return 0;
    }
};

class WXCIControlOverrides_RtProxy : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IControlOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIControlOverrides_RtProxy", TrustLevel::BaseTrust) public : RTObject<WXCIControlOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE OnPointerEntered(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerEntered:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnPointerPressed(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerPressed:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnPointerMoved(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerMoved:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnPointerReleased(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerReleased:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnPointerExited(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerExited:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnPointerCaptureLost(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerCaptureLost:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnPointerCanceled(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerCanceled:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnPointerWheelChanged(ABI::Windows::UI::Xaml::Input::IPointerRoutedEventArgs* e_in) override {
        [_inner onPointerWheelChanged:_createRtProxy<WUXIPointerRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnTapped(ABI::Windows::UI::Xaml::Input::ITappedRoutedEventArgs* e_in) override {
        [_inner onTapped:_createRtProxy<WUXITappedRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnDoubleTapped(ABI::Windows::UI::Xaml::Input::IDoubleTappedRoutedEventArgs* e_in) override {
        [_inner onDoubleTapped:_createRtProxy<WUXIDoubleTappedRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnHolding(ABI::Windows::UI::Xaml::Input::IHoldingRoutedEventArgs* e_in) override {
        [_inner onHolding:_createRtProxy<WUXIHoldingRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnRightTapped(ABI::Windows::UI::Xaml::Input::IRightTappedRoutedEventArgs* e_in) override {
        [_inner onRightTapped:_createRtProxy<WUXIRightTappedRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnManipulationStarting(ABI::Windows::UI::Xaml::Input::IManipulationStartingRoutedEventArgs* e_in) override {
        [_inner onManipulationStarting:_createRtProxy<WUXIManipulationStartingRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE
    OnManipulationInertiaStarting(ABI::Windows::UI::Xaml::Input::IManipulationInertiaStartingRoutedEventArgs* e_in) override {
        [_inner onManipulationInertiaStarting:_createRtProxy<WUXIManipulationInertiaStartingRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnManipulationStarted(ABI::Windows::UI::Xaml::Input::IManipulationStartedRoutedEventArgs* e_in) override {
        [_inner onManipulationStarted:_createRtProxy<WUXIManipulationStartedRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnManipulationDelta(ABI::Windows::UI::Xaml::Input::IManipulationDeltaRoutedEventArgs* e_in) override {
        [_inner onManipulationDelta:_createRtProxy<WUXIManipulationDeltaRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnManipulationCompleted(ABI::Windows::UI::Xaml::Input::IManipulationCompletedRoutedEventArgs* e_in) override {
        [_inner onManipulationCompleted:_createRtProxy<WUXIManipulationCompletedRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnKeyUp(ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs* e_in) override {
        [_inner onKeyUp:_createRtProxy<WUXIKeyRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnKeyDown(ABI::Windows::UI::Xaml::Input::IKeyRoutedEventArgs* e_in) override {
        [_inner onKeyDown:_createRtProxy<WUXIKeyRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnGotFocus(ABI::Windows::UI::Xaml::IRoutedEventArgs* e_in) override {
        [_inner onGotFocus:_createRtProxy<WXRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnLostFocus(ABI::Windows::UI::Xaml::IRoutedEventArgs* e_in) override {
        [_inner onLostFocus:_createRtProxy<WXRoutedEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnDragEnter(ABI::Windows::UI::Xaml::IDragEventArgs* e_in) override {
        [_inner onDragEnter:_createRtProxy<WXDragEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnDragLeave(ABI::Windows::UI::Xaml::IDragEventArgs* e_in) override {
        [_inner onDragLeave:_createRtProxy<WXDragEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnDragOver(ABI::Windows::UI::Xaml::IDragEventArgs* e_in) override {
        [_inner onDragOver:_createRtProxy<WXDragEventArgs>(e_in)];
        return 0;
    }
    HRESULT STDMETHODCALLTYPE OnDrop(ABI::Windows::UI::Xaml::IDragEventArgs* e_in) override {
        [_inner onDrop:_createRtProxy<WXDragEventArgs>(e_in)];
        return 0;
    }
};

class WXCIInkToolbarCustomPenOverrides_RtProxy
    : public RuntimeClass<ABI::Windows::UI::Xaml::Controls::IInkToolbarCustomPenOverrides, ComposableBase<>> {
    InspectableClass(L"WXCIInkToolbarCustomPenOverrides_RtProxy", TrustLevel::BaseTrust) public
        : RTObject<WXCIInkToolbarCustomPenOverrides>* _inner;
    HRESULT STDMETHODCALLTYPE CreateInkDrawingAttributesCore(ABI::Windows::UI::Xaml::Media::IBrush* brush_in,
                                                             double strokeWidth_in,
                                                             ABI::Windows::UI::Input::Inking::IInkDrawingAttributes** ret) override {
        auto unmarshaledRet = [_inner createInkDrawingAttributesCore:_createRtProxy<WUXMBrush>(brush_in) strokeWidth:strokeWidth_in];
        *ret = _getRtInterface<ABI::Windows::UI::Input::Inking::IInkDrawingAttributes>(unmarshaledRet).Detach();
        return 0;
    }
};
