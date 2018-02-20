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

// WindowsUIXamlControls.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSUIXAMLEXPORT
#define OBJCUWPWINDOWSUIXAMLEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsUIXaml.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WXCColorChangedEventArgs, WXCNavigationViewDisplayModeChangedEventArgs, WXCNavigationViewSelectionChangedEventArgs, WXCNavigationViewItemInvokedEventArgs, WXCSwipeItemInvokedEventArgs, WXCBackClickEventArgs, WXCDragItemsStartingEventArgs, WXCNotifyEventArgs, WXCSemanticZoomViewChangedEventArgs, WXCTextControlPasteEventArgs, WXCContainerContentChangingEventArgs, WXCSemanticZoomLocation, WXCCandidateWindowBoundsChangedEventArgs, WXCChoosingGroupHeaderContainerEventArgs, WXCChoosingItemContainerEventArgs, WXCColumnDefinitionCollection, WXCDataTemplateSelector, WXCDragItemsCompletedEventArgs, WXCStyleSelector, WXCGroupStyle, WXCGroupStyleSelector, WXCIsTextTrimmedChangedEventArgs, WXCItemCollection, WXCItemContainerGenerator, WXCMediaTransportControlsHelper, WXCPasswordBoxPasswordChangingEventArgs, WXCRowDefinitionCollection, WXCTextBoxBeforeTextChangingEventArgs, WXCTextBoxTextChangingEventArgs, WXCTextCompositionChangedEventArgs, WXCTextCompositionEndedEventArgs, WXCTextCompositionStartedEventArgs, WXCTextControlCopyingToClipboardEventArgs, WXCTextControlCuttingToClipboardEventArgs, WXCToolTipService, WXCUIElementCollection, WXCCalendarViewDayItemChangingEventArgs, WXCHubSectionHeaderClickEventArgs, WXCSectionsInViewChangedEventArgs, WXCWebViewNavigationFailedEventArgs, WXCCalendarDatePickerDateChangedEventArgs, WXCCalendarViewSelectedDatesChangedEventArgs, WXCContentDialogButtonClickDeferral, WXCContentDialogButtonClickEventArgs, WXCContentDialogClosedEventArgs, WXCContentDialogClosingDeferral, WXCContentDialogClosingEventArgs, WXCContentDialogOpenedEventArgs, WXCDatePickerValueChangedEventArgs, WXCDynamicOverflowItemsChangingEventArgs, WXCHubSectionCollection, WXCListViewPersistenceHelper, WXCRichEditBoxTextChangingEventArgs, WXCScrollViewerView, WXCScrollViewerViewChangedEventArgs, WXCScrollViewerViewChangingEventArgs, WXCSearchBoxQueryChangedEventArgs, WXCSearchBoxQuerySubmittedEventArgs, WXCSearchBoxResultSuggestionChosenEventArgs, WXCSearchBoxSuggestionsRequestedEventArgs, WXCSplitViewPaneClosingEventArgs, WXCTimePickerValueChangedEventArgs, WXCWebViewContentLoadingEventArgs, WXCWebViewDeferredPermissionRequest, WXCWebViewDOMContentLoadedEventArgs, WXCWebViewLongRunningScriptDetectedEventArgs, WXCWebViewNavigationCompletedEventArgs, WXCWebViewNavigationStartingEventArgs, WXCWebViewNewWindowRequestedEventArgs, WXCWebViewPermissionRequest, WXCWebViewPermissionRequestedEventArgs, WXCWebViewSettings, WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs, WXCWebViewUnviewableContentIdentifiedEventArgs, WXCIconSource, WXCSymbolIconSource, WXCFontIconSource, WXCBitmapIconSource, WXCPathIconSource, WXCRatingItemInfo, WXCRatingItemFontInfo, WXCRatingItemImageInfo, WXCSwipeItem, WXCSwipeItems, WXCColumnDefinition, WXCRowDefinition, WXCAutoSuggestBoxQuerySubmittedEventArgs, WXCAutoSuggestBoxSuggestionChosenEventArgs, WXCAutoSuggestBoxTextChangedEventArgs, WXCCleanUpVirtualizedItemEventArgs, WXCContextMenuEventArgs, WXCItemClickEventArgs, WXCSelectionChangedEventArgs, WXCTextChangedEventArgs, WXCItemsPanelTemplate, WXCParallaxView, WXCPanel, WXCBorder, WXCCaptureElement, WXCContentPresenter, WXCImage, WXCItemsPresenter, WXCRichTextBlockOverflow, WXCRichTextBlock, WXCTextBlock, WXCViewbox, WXCCanvas, WXCGrid, WXCRelativePanel, WXCStackPanel, WXCVariableSizedWrapGrid, WXCVirtualizingPanel, WXCVirtualizingStackPanel, WXCIconElement, WXCInkCanvas, WXCMediaElement, WXCMediaPlayerPresenter, WXCWebView, WXCBitmapIcon, WXCFontIcon, WXCItemsStackPanel, WXCItemsWrapGrid, WXCPathIcon, WXCScrollContentPresenter, WXCSymbolIcon, WXCSwapChainBackgroundPanel, WXCSwapChainPanel, WXCWrapGrid, WXCFocusDisengagedEventArgs, WXCFocusEngagedEventArgs, WXCControlTemplate, WXCControl, WXCColorPicker, WXCPersonPicture, WXCRatingControl, WXCSemanticZoom, WXCContentControl, WXCNavigationView, WXCSwipeControl, WXCListViewBaseHeaderItem, WXCItemsControl, WXCMediaTransportControls, WXCPasswordBox, WXCProgressRing, WXCTextBox, WXCToggleSwitch, WXCUserControl, WXCGroupItem, WXCSettingsFlyout, WXCToolTip, WXCComboBoxItem, WXCFlipViewItem, WXCListBoxItem, WXCProgressBar, WXCSlider, WXCButton, WXCHyperlinkButton, WXCListViewBase, WXCComboBox, WXCFlipView, WXCListBox, WXCCheckBox, WXCRadioButton, WXCCalendarView, WXCCalendarViewDayItem, WXCHubSection, WXCMenuFlyoutItemBase, WXCAppBarSeparator, WXCCalendarDatePicker, WXCDatePicker, WXCHub, WXCMediaPlayerElement, WXCRichEditBox, WXCSearchBox, WXCSplitView, WXCTimePicker, WXCAppBar, WXCAutoSuggestBox, WXCCommandBarOverflowPresenter, WXCContentDialog, WXCFlyoutPresenter, WXCFrame, WXCMenuFlyoutItem, WXCMenuFlyoutPresenter, WXCMenuFlyoutSeparator, WXCMenuFlyoutSubItem, WXCPage, WXCScrollViewer, WXCCommandBar, WXCGridViewHeaderItem, WXCGridViewItem, WXCListViewHeaderItem, WXCListViewItem, WXCNavigationViewItemBase, WXCNavigationViewItem, WXCNavigationViewItemSeparator, WXCNavigationViewItemHeader, WXCToggleMenuFlyoutItem, WXCAppBarButton, WXCAppBarToggleButton, WXCGridView, WXCListView, WXCNavigationViewList, WXCFlyout, WXCMenuFlyout, WXCWebViewBrush, WXCInkToolbarIsStencilButtonCheckedChangedEventArgs, WXCInkToolbarCustomPen, WXCInkToolbar, WXCInkToolbarPenConfigurationControl, WXCInkToolbarFlyoutItem, WXCInkToolbarMenuButton, WXCInkToolbarStencilButton, WXCInkToolbarToggleButton, WXCInkToolbarToolButton, WXCInkToolbarCustomToggleButton, WXCInkToolbarCustomToolButton, WXCInkToolbarEraserButton, WXCInkToolbarPenButton, WXCInkToolbarRulerButton, WXCInkToolbarBallpointPenButton, WXCInkToolbarCustomPenButton, WXCInkToolbarHighlighterButton, WXCInkToolbarPencilButton, WXCPivotItemEventArgs, WXCDatePickedEventArgs, WXCDatePickerFlyoutItem, WXCItemsPickedEventArgs, WXCPickerConfirmedEventArgs, WXCTimePickedEventArgs, WXCDatePickerFlyoutPresenter, WXCListPickerFlyoutPresenter, WXCTimePickerFlyoutPresenter, WXCPickerFlyoutPresenter, WXCPivot, WXCPivotItem, WXCDatePickerFlyout, WXCListPickerFlyout, WXCPickerFlyout, WXCTimePickerFlyout;
@protocol WXCIColorChangedEventArgs, WXCIColorPicker, WXCIColorPickerStatics, WXCIColorPickerFactory, WXCIIconSource, WXCIIconSourceFactory, WXCIIconSourceStatics, WXCISymbolIconSource, WXCISymbolIconSourceFactory, WXCISymbolIconSourceStatics, WXCIFontIconSource, WXCIFontIconSourceFactory, WXCIFontIconSourceStatics, WXCIBitmapIconSource, WXCIBitmapIconSourceFactory, WXCIBitmapIconSourceStatics, WXCIPathIconSource, WXCIPathIconSourceFactory, WXCIPathIconSourceStatics, WXCINavigationViewDisplayModeChangedEventArgs, WXCINavigationViewSelectionChangedEventArgs, WXCINavigationViewItemInvokedEventArgs, WXCINavigationView, WXCINavigationViewFactory, WXCINavigationViewStatics, WXCINavigationViewList, WXCINavigationViewListFactory, WXCINavigationViewItemBase, WXCINavigationViewItemBaseFactory, WXCINavigationViewItem, WXCINavigationViewItemFactory, WXCINavigationViewItemStatics, WXCINavigationViewItemSeparator, WXCINavigationViewItemSeparatorFactory, WXCINavigationViewItemHeader, WXCINavigationViewItemHeaderFactory, WXCIParallaxView, WXCIParallaxViewStatics, WXCIParallaxViewFactory, WXCIPersonPicture, WXCIPersonPictureFactory, WXCIPersonPictureStatics, WXCIRatingItemInfo, WXCIRatingItemInfoFactory, WXCIRatingItemFontInfo, WXCIRatingItemFontInfoFactory, WXCIRatingItemFontInfoStatics, WXCIRatingItemImageInfo, WXCIRatingItemImageInfoFactory, WXCIRatingItemImageInfoStatics, WXCIRatingControl, WXCIRatingControlFactory, WXCIRatingControlStatics, WXCISwipeItem, WXCISwipeItemStatics, WXCISwipeItemFactory, WXCISwipeItemInvokedEventArgs, WXCISwipeItems, WXCISwipeItemsFactory, WXCISwipeItemsStatics, WXCISwipeControl, WXCISwipeControlFactory, WXCISwipeControlStatics, WXCIInsertionPanel, WXCIItemContainerMapping, WXCINavigate, WXCISemanticZoomInformation, WXCIBackClickEventArgs, WXCICandidateWindowBoundsChangedEventArgs, WXCIChoosingGroupHeaderContainerEventArgs, WXCIChoosingItemContainerEventArgs, WXCIContainerContentChangingEventArgs, WXCIDataTemplateSelector, WXCIDataTemplateSelectorOverrides, WXCIDataTemplateSelectorFactory, WXCIDataTemplateSelector2, WXCIDataTemplateSelectorOverrides2, WXCIDragItemsCompletedEventArgs, WXCIDragItemsStartingEventArgs, WXCIGroupStyle, WXCIGroupStyleFactory, WXCIGroupStyle2, WXCIGroupStyleSelector, WXCIGroupStyleSelectorOverrides, WXCIGroupStyleSelectorFactory, WXCIIsTextTrimmedChangedEventArgs, WXCIItemContainerGenerator, WXCIMediaTransportControlsHelper, WXCIMediaTransportControlsHelperStatics, WXCINotifyEventArgs, WXCINotifyEventArgs2, WXCIPasswordBoxPasswordChangingEventArgs, WXCISemanticZoomLocation, WXCISemanticZoomViewChangedEventArgs, WXCIStyleSelector, WXCIStyleSelectorOverrides, WXCIStyleSelectorFactory, WXCITextBoxBeforeTextChangingEventArgs, WXCITextBoxTextChangingEventArgs, WXCITextBoxTextChangingEventArgs2, WXCITextCompositionChangedEventArgs, WXCITextCompositionEndedEventArgs, WXCITextCompositionStartedEventArgs, WXCITextControlCopyingToClipboardEventArgs, WXCITextControlCuttingToClipboardEventArgs, WXCITextControlPasteEventArgs, WXCIToolTipService, WXCIToolTipServiceStatics, WXCIUIElementCollection, WXCICleanUpVirtualizedItemEventArgs, WXCIColumnDefinition, WXCIColumnDefinitionStatics, WXCIContextMenuEventArgs, WXCIItemClickEventArgs, WXCIRowDefinition, WXCIRowDefinitionStatics, WXCISelectionChangedEventArgs, WXCISelectionChangedEventArgsFactory, WXCITextChangedEventArgs, WXCIItemsPanelTemplate, WXCIBorder, WXCIBorderStatics, WXCICaptureElement, WXCICaptureElementStatics, WXCIContentPresenter, WXCIContentPresenterOverrides, WXCIContentPresenterStatics, WXCIContentPresenterFactory, WXCIContentPresenter2, WXCIContentPresenterStatics2, WXCIContentPresenter3, WXCIContentPresenterStatics3, WXCIContentPresenter4, WXCIContentPresenterStatics4, WXCIImage, WXCIImageStatics, WXCIImage2, WXCIImage3, WXCIItemsPresenter, WXCIItemsPresenterStatics, WXCIItemsPresenter2, WXCIItemsPresenterStatics2, WXCIPanel, WXCIPanelStatics, WXCIPanelFactory, WXCIRichTextBlock, WXCIRichTextBlockStatics, WXCIRichTextBlock2, WXCIRichTextBlockStatics2, WXCIRichTextBlock3, WXCIRichTextBlockStatics3, WXCIRichTextBlock4, WXCIRichTextBlockStatics4, WXCIRichTextBlock5, WXCIRichTextBlockStatics5, WXCIRichTextBlockOverflow, WXCIRichTextBlockOverflowStatics, WXCIRichTextBlockOverflow2, WXCIRichTextBlockOverflowStatics2, WXCIRichTextBlockOverflow3, WXCIRichTextBlockOverflowStatics3, WXCITextBlock, WXCITextBlockStatics, WXCITextBlock2, WXCITextBlockStatics2, WXCITextBlock3, WXCITextBlockStatics3, WXCITextBlock4, WXCITextBlock5, WXCITextBlockStatics5, WXCITextBlock6, WXCITextBlockStatics6, WXCIViewbox, WXCIViewboxStatics, WXCICanvas, WXCICanvasStatics, WXCICanvasFactory, WXCIContentControl, WXCIContentControlOverrides, WXCIContentControlStatics, WXCIContentControlFactory, WXCIContentControl2, WXCIGrid, WXCIGridStatics, WXCIGridFactory, WXCIGrid2, WXCIGridStatics2, WXCIGrid3, WXCIGridStatics3, WXCIItemsControl, WXCIItemsControlOverrides, WXCIItemsControlStatics, WXCIItemsControlFactory, WXCIItemsControl2, WXCIItemsControl3, WXCIMediaTransportControls, WXCIMediaTransportControlsStatics, WXCIMediaTransportControlsFactory, WXCIMediaTransportControls2, WXCIMediaTransportControlsStatics2, WXCIMediaTransportControls3, WXCIMediaTransportControlsStatics3, WXCIPasswordBox, WXCIPasswordBoxStatics, WXCIPasswordBox2, WXCIPasswordBoxStatics2, WXCIPasswordBox3, WXCIPasswordBoxStatics3, WXCIPasswordBox4, WXCIProgressRing, WXCIProgressRingStatics, WXCIRelativePanel, WXCIRelativePanelStatics, WXCIRelativePanelFactory, WXCISemanticZoom, WXCISemanticZoomStatics, WXCIStackPanel, WXCIStackPanelStatics, WXCIStackPanelFactory, WXCIStackPanel2, WXCIStackPanelStatics2, WXCIStackPanel4, WXCIStackPanelStatics4, WXCITextBox, WXCITextBoxStatics, WXCITextBoxFactory, WXCITextBox2, WXCITextBoxStatics2, WXCITextBox3, WXCITextBoxStatics3, WXCITextBox4, WXCITextBox5, WXCITextBoxStatics5, WXCITextBox6, WXCITextBoxStatics6, WXCIToggleSwitch, WXCIToggleSwitchOverrides, WXCIToggleSwitchStatics, WXCIUserControl, WXCIUserControlStatics, WXCIUserControlFactory, WXCIVariableSizedWrapGrid, WXCIVariableSizedWrapGridStatics, WXCIVirtualizingPanel, WXCIVirtualizingPanelOverrides, WXCIVirtualizingPanelProtected, WXCIVirtualizingPanelFactory, WXCIGroupItem, WXCIGroupItemFactory, WXCIListViewBaseHeaderItem, WXCIListViewBaseHeaderItemFactory, WXCIProgressBar, WXCIProgressBarStatics, WXCIProgressBarFactory, WXCISettingsFlyout, WXCISettingsFlyoutStatics, WXCISettingsFlyoutFactory, WXCISlider, WXCISliderStatics, WXCISliderFactory, WXCISlider2, WXCISliderStatics2, WXCIToolTip, WXCIToolTipStatics, WXCIToolTipFactory, WXCIButton, WXCIButtonFactory, WXCIButtonWithFlyout, WXCIButtonStaticsWithFlyout, WXCIComboBox, WXCIComboBoxOverrides, WXCIComboBoxStatics, WXCIComboBoxFactory, WXCIComboBox2, WXCIComboBoxStatics2, WXCIComboBox3, WXCIComboBoxStatics3, WXCIComboBox4, WXCIComboBoxStatics4, WXCIComboBox5, WXCIComboBoxStatics5, WXCIComboBoxItem, WXCIComboBoxItemFactory, WXCIFlipView, WXCIFlipViewFactory, WXCIFlipView2, WXCIFlipViewStatics2, WXCIFlipViewItem, WXCIFlipViewItemFactory, WXCIHyperlinkButton, WXCIHyperlinkButtonStatics, WXCIHyperlinkButtonFactory, WXCIListBox, WXCIListBoxStatics, WXCIListBoxFactory, WXCIListBox2, WXCIListBoxStatics2, WXCIListBoxItem, WXCIListBoxItemFactory, WXCIListViewBase, WXCIListViewBaseStatics, WXCIListViewBaseFactory, WXCIListViewBase2, WXCIListViewBaseStatics2, WXCIListViewBase3, WXCIListViewBaseStatics3, WXCIListViewBase4, WXCIListViewBaseStatics4, WXCIListViewBase5, WXCIListViewBaseStatics5, WXCIListViewBase6, WXCIVirtualizingStackPanel, WXCIVirtualizingStackPanelOverrides, WXCIVirtualizingStackPanelStatics, WXCICheckBox, WXCICheckBoxFactory, WXCIRadioButton, WXCIRadioButtonStatics, WXCIRadioButtonFactory, WXCICommandBarElement, WXCICommandBarElement2, WXCICalendarDatePickerDateChangedEventArgs, WXCICalendarViewDayItemChangingEventArgs, WXCICalendarViewSelectedDatesChangedEventArgs, WXCIContentDialogButtonClickDeferral, WXCIContentDialogButtonClickEventArgs, WXCIContentDialogClosedEventArgs, WXCIContentDialogClosingDeferral, WXCIContentDialogClosingEventArgs, WXCIContentDialogOpenedEventArgs, WXCIDatePickerValueChangedEventArgs, WXCIDynamicOverflowItemsChangingEventArgs, WXCIHubSectionHeaderClickEventArgs, WXCIListViewPersistenceHelper, WXCIListViewPersistenceHelperStatics, WXCIRichEditBoxTextChangingEventArgs, WXCIRichEditBoxTextChangingEventArgs2, WXCIScrollViewerView, WXCIScrollViewerViewChangedEventArgs, WXCIScrollViewerViewChangingEventArgs, WXCISearchBoxQueryChangedEventArgs, WXCISearchBoxQuerySubmittedEventArgs, WXCISearchBoxResultSuggestionChosenEventArgs, WXCISearchBoxSuggestionsRequestedEventArgs, WXCISectionsInViewChangedEventArgs, WXCISectionsInViewChangedEventArgsFactory, WXCISplitViewPaneClosingEventArgs, WXCITimePickerValueChangedEventArgs, WXCIWebViewContentLoadingEventArgs, WXCIWebViewDeferredPermissionRequest, WXCIWebViewDOMContentLoadedEventArgs, WXCIWebViewLongRunningScriptDetectedEventArgs, WXCIWebViewNavigationCompletedEventArgs, WXCIWebViewNavigationFailedEventArgs, WXCIWebViewNavigationStartingEventArgs, WXCIWebViewNewWindowRequestedEventArgs, WXCIWebViewPermissionRequest, WXCIWebViewPermissionRequestedEventArgs, WXCIWebViewSettings, WXCIWebViewUnsupportedUriSchemeIdentifiedEventArgs, WXCIWebViewUnviewableContentIdentifiedEventArgs, WXCIWebViewUnviewableContentIdentifiedEventArgs2, WXCIAutoSuggestBoxQuerySubmittedEventArgs, WXCIAutoSuggestBoxSuggestionChosenEventArgs, WXCIAutoSuggestBoxTextChangedEventArgs, WXCIAutoSuggestBoxTextChangedEventArgsStatics, WXCIFlyout, WXCIFlyoutStatics, WXCIFlyoutFactory, WXCIMenuFlyout, WXCIMenuFlyoutStatics, WXCIMenuFlyoutFactory, WXCIMenuFlyout2, WXCIIconElement, WXCIIconElementStatics, WXCIIconElementFactory, WXCIInkCanvas, WXCIInkCanvasFactory, WXCIMediaElement, WXCIMediaElementStatics, WXCIMediaElement2, WXCIMediaElementStatics2, WXCIMediaElement3, WXCIMediaPlayerPresenter, WXCIMediaPlayerPresenterStatics, WXCIMediaPlayerPresenterFactory, WXCIWebView, WXCIWebViewStatics, WXCIWebView2, WXCIWebViewStatics2, WXCIWebView3, WXCIWebViewStatics3, WXCIWebView4, WXCIWebViewStatics4, WXCIWebViewFactory4, WXCIWebView5, WXCIWebViewStatics5, WXCIWebViewBrush, WXCIWebViewBrushStatics, WXCIAppBarSeparator, WXCIAppBarSeparatorStatics, WXCIAppBarSeparatorFactory, WXCIAppBarSeparatorStatics3, WXCIBitmapIcon, WXCIBitmapIconStatics, WXCIBitmapIconFactory, WXCIBitmapIcon2, WXCIBitmapIconStatics2, WXCICalendarDatePicker, WXCICalendarDatePickerStatics, WXCICalendarDatePickerFactory, WXCICalendarDatePicker2, WXCICalendarDatePickerStatics2, WXCICalendarView, WXCICalendarViewStatics, WXCICalendarViewFactory, WXCICalendarViewDayItem, WXCICalendarViewDayItemStatics, WXCICalendarViewDayItemFactory, WXCIDatePicker, WXCIDatePickerStatics, WXCIDatePickerFactory, WXCIDatePicker2, WXCIDatePickerStatics2, WXCIFontIcon, WXCIFontIconStatics, WXCIFontIconFactory, WXCIFontIcon2, WXCIFontIconStatics2, WXCIFontIcon3, WXCIFontIconStatics3, WXCIHub, WXCIHubStatics, WXCIHubFactory, WXCIHubSection, WXCIHubSectionStatics, WXCIHubSectionFactory, WXCIItemsStackPanel, WXCIItemsStackPanelStatics, WXCIItemsStackPanel2, WXCIItemsStackPanelStatics2, WXCIItemsWrapGrid, WXCIItemsWrapGridStatics, WXCIItemsWrapGrid2, WXCIItemsWrapGridStatics2, WXCIMediaPlayerElement, WXCIMediaPlayerElementStatics, WXCIMediaPlayerElementFactory, WXCIMenuFlyoutItemBase, WXCIMenuFlyoutItemBaseFactory, WXCIPathIcon, WXCIPathIconStatics, WXCIPathIconFactory, WXCIRichEditBox, WXCIRichEditBoxStatics, WXCIRichEditBoxFactory, WXCIRichEditBox2, WXCIRichEditBoxStatics2, WXCIRichEditBox3, WXCIRichEditBoxStatics3, WXCIRichEditBox4, WXCIRichEditBoxStatics4, WXCIRichEditBox5, WXCIRichEditBoxStatics5, WXCIRichEditBox6, WXCIRichEditBoxStatics6, WXCIScrollContentPresenter, WXCISearchBox, WXCISearchBoxStatics, WXCISearchBoxFactory, WXCISplitView, WXCISplitViewStatics, WXCISplitViewFactory, WXCISplitView2, WXCISplitViewStatics2, WXCISplitView3, WXCISymbolIcon, WXCISymbolIconStatics, WXCISymbolIconFactory, WXCITimePicker, WXCITimePickerStatics, WXCITimePickerFactory, WXCITimePicker2, WXCITimePickerStatics2, WXCIAppBar, WXCIAppBarOverrides, WXCIAppBarStatics, WXCIAppBarFactory, WXCIAppBar2, WXCIAppBarStatics2, WXCIAppBar3, WXCIAppBarOverrides3, WXCIAppBar4, WXCIAppBarStatics4, WXCIAutoSuggestBox, WXCIAutoSuggestBoxStatics, WXCIAutoSuggestBox2, WXCIAutoSuggestBoxStatics2, WXCIAutoSuggestBox3, WXCIAutoSuggestBoxStatics3, WXCICommandBarOverflowPresenter, WXCICommandBarOverflowPresenterFactory, WXCIContentDialog, WXCIContentDialogStatics, WXCIContentDialogFactory, WXCIContentDialog2, WXCIContentDialogStatics2, WXCIContentDialog3, WXCIFlyoutPresenter, WXCIFlyoutPresenterFactory, WXCIFrame, WXCIFrameStatics, WXCIFrameFactory, WXCIFrame2, WXCIFrameStatics2, WXCIFrame3, WXCIFrame4, WXCIMenuFlyoutItem, WXCIMenuFlyoutItemStatics, WXCIMenuFlyoutItemFactory, WXCIMenuFlyoutItem2, WXCIMenuFlyoutItemStatics2, WXCIMenuFlyoutPresenter, WXCIMenuFlyoutPresenterFactory, WXCIMenuFlyoutPresenter2, WXCIMenuFlyoutSeparator, WXCIMenuFlyoutSeparatorFactory, WXCIMenuFlyoutSubItem, WXCIMenuFlyoutSubItemStatics, WXCIMenuFlyoutSubItem2, WXCIMenuFlyoutSubItemStatics2, WXCIPage, WXCIPageOverrides, WXCIPageStatics, WXCIPageFactory, WXCIScrollViewer, WXCIScrollViewerStatics, WXCIScrollViewer2, WXCIScrollViewerStatics2, WXCIScrollViewer3, WXCISwapChainBackgroundPanel, WXCISwapChainBackgroundPanelFactory, WXCISwapChainBackgroundPanel2, WXCISwapChainPanel, WXCISwapChainPanelStatics, WXCISwapChainPanelFactory, WXCICommandBar, WXCICommandBarStatics, WXCICommandBarFactory, WXCICommandBar2, WXCICommandBarStatics2, WXCICommandBar3, WXCICommandBarStatics3, WXCIGridViewHeaderItem, WXCIGridViewHeaderItemFactory, WXCIGridViewItem, WXCIGridViewItemFactory, WXCIListViewHeaderItem, WXCIListViewHeaderItemFactory, WXCIListViewItem, WXCIListViewItemFactory, WXCIToggleMenuFlyoutItem, WXCIToggleMenuFlyoutItemStatics, WXCIToggleMenuFlyoutItemFactory, WXCIWrapGrid, WXCIWrapGridStatics, WXCIAppBarButton, WXCIAppBarButtonStatics, WXCIAppBarButtonFactory, WXCIAppBarButton3, WXCIAppBarButtonStatics3, WXCIAppBarToggleButton, WXCIAppBarToggleButtonStatics, WXCIAppBarToggleButtonFactory, WXCIAppBarToggleButton3, WXCIAppBarToggleButtonStatics3, WXCIGridView, WXCIGridViewFactory, WXCIListView, WXCIListViewFactory, WXCIFocusDisengagedEventArgs, WXCIFocusEngagedEventArgs, WXCIFocusEngagedEventArgs2, WXCIControlTemplate, WXCIControl, WXCIControlOverrides, WXCIControlProtected, WXCIControlStatics, WXCIControlFactory, WXCIControl2, WXCIControlStatics2, WXCIControl3, WXCIControlStatics3, WXCIControl4, WXCIControlStatics4, WXCIControl5, WXCIControlStatics5, WXCIControlOverrides6, WXCIInkToolbarIsStencilButtonCheckedChangedEventArgs, WXCIInkToolbarCustomPen, WXCIInkToolbarCustomPenOverrides, WXCIInkToolbarCustomPenFactory, WXCIInkToolbar, WXCIInkToolbarStatics, WXCIInkToolbarFactory, WXCIInkToolbar2, WXCIInkToolbarStatics2, WXCIInkToolbarPenConfigurationControl, WXCIInkToolbarPenConfigurationControlStatics, WXCIInkToolbarPenConfigurationControlFactory, WXCIInkToolbarFlyoutItem, WXCIInkToolbarFlyoutItemStatics, WXCIInkToolbarFlyoutItemFactory, WXCIInkToolbarMenuButton, WXCIInkToolbarMenuButtonStatics, WXCIInkToolbarMenuButtonFactory, WXCIInkToolbarStencilButton, WXCIInkToolbarStencilButtonStatics, WXCIInkToolbarStencilButtonFactory, WXCIInkToolbarToggleButton, WXCIInkToolbarToggleButtonFactory, WXCIInkToolbarToolButton, WXCIInkToolbarToolButtonStatics, WXCIInkToolbarToolButtonFactory, WXCIInkToolbarCustomToggleButton, WXCIInkToolbarCustomToggleButtonFactory, WXCIInkToolbarCustomToolButton, WXCIInkToolbarCustomToolButtonStatics, WXCIInkToolbarCustomToolButtonFactory, WXCIInkToolbarEraserButton, WXCIInkToolbarEraserButtonFactory, WXCIInkToolbarEraserButton2, WXCIInkToolbarEraserButtonStatics2, WXCIInkToolbarPenButton, WXCIInkToolbarPenButtonStatics, WXCIInkToolbarPenButtonFactory, WXCIInkToolbarRulerButton, WXCIInkToolbarRulerButtonStatics, WXCIInkToolbarRulerButtonFactory, WXCIInkToolbarBallpointPenButton, WXCIInkToolbarBallpointPenButtonFactory, WXCIInkToolbarCustomPenButton, WXCIInkToolbarCustomPenButtonStatics, WXCIInkToolbarCustomPenButtonFactory, WXCIInkToolbarHighlighterButton, WXCIInkToolbarHighlighterButtonFactory, WXCIInkToolbarPencilButton, WXCIInkToolbarPencilButtonFactory, WXCIPivotItemEventArgs, WXCIDatePickedEventArgs, WXCIDatePickerFlyoutItem, WXCIDatePickerFlyoutItemStatics, WXCIItemsPickedEventArgs, WXCIPickerConfirmedEventArgs, WXCITimePickedEventArgs, WXCIDatePickerFlyout, WXCIDatePickerFlyoutStatics, WXCIDatePickerFlyout2, WXCIDatePickerFlyoutStatics2, WXCIListPickerFlyout, WXCIListPickerFlyoutStatics, WXCIPickerFlyout, WXCIPickerFlyoutStatics, WXCITimePickerFlyout, WXCITimePickerFlyoutStatics, WXCIDatePickerFlyoutPresenter, WXCIListPickerFlyoutPresenter, WXCITimePickerFlyoutPresenter, WXCIPickerFlyoutPresenter, WXCIPivot, WXCIPivotStatics, WXCIPivotFactory, WXCIPivot2, WXCIPivotStatics2, WXCIPivot3, WXCIPivotStatics3, WXCIPivotItem, WXCIPivotItemStatics, WXCIPivotItemFactory;

// Windows.UI.Xaml.Controls.ColorSpectrumShape
enum _WXCColorSpectrumShape {
    WXCColorSpectrumShapeBox = 0,
    WXCColorSpectrumShapeRing = 1,
};
typedef unsigned WXCColorSpectrumShape;

// Windows.UI.Xaml.Controls.ColorSpectrumComponents
enum _WXCColorSpectrumComponents {
    WXCColorSpectrumComponentsHueValue = 0,
    WXCColorSpectrumComponentsValueHue = 1,
    WXCColorSpectrumComponentsHueSaturation = 2,
    WXCColorSpectrumComponentsSaturationHue = 3,
    WXCColorSpectrumComponentsSaturationValue = 4,
    WXCColorSpectrumComponentsValueSaturation = 5,
};
typedef unsigned WXCColorSpectrumComponents;

// Windows.UI.Xaml.Controls.ColorPickerHsvChannel
enum _WXCColorPickerHsvChannel {
    WXCColorPickerHsvChannelHue = 0,
    WXCColorPickerHsvChannelSaturation = 1,
    WXCColorPickerHsvChannelValue = 2,
    WXCColorPickerHsvChannelAlpha = 3,
};
typedef unsigned WXCColorPickerHsvChannel;

// Windows.UI.Xaml.Controls.NavigationViewDisplayMode
enum _WXCNavigationViewDisplayMode {
    WXCNavigationViewDisplayModeMinimal = 0,
    WXCNavigationViewDisplayModeCompact = 1,
    WXCNavigationViewDisplayModeExpanded = 2,
};
typedef unsigned WXCNavigationViewDisplayMode;

// Windows.UI.Xaml.Controls.ParallaxSourceOffsetKind
enum _WXCParallaxSourceOffsetKind {
    WXCParallaxSourceOffsetKindAbsolute = 0,
    WXCParallaxSourceOffsetKindRelative = 1,
};
typedef unsigned WXCParallaxSourceOffsetKind;

// Windows.UI.Xaml.Controls.SwipeBehaviorOnInvoked
enum _WXCSwipeBehaviorOnInvoked {
    WXCSwipeBehaviorOnInvokedAuto = 0,
    WXCSwipeBehaviorOnInvokedClose = 1,
    WXCSwipeBehaviorOnInvokedRemainOpen = 2,
};
typedef unsigned WXCSwipeBehaviorOnInvoked;

// Windows.UI.Xaml.Controls.SwipeMode
enum _WXCSwipeMode {
    WXCSwipeModeReveal = 0,
    WXCSwipeModeExecute = 1,
};
typedef unsigned WXCSwipeMode;

// Windows.UI.Xaml.Controls.CandidateWindowAlignment
enum _WXCCandidateWindowAlignment {
    WXCCandidateWindowAlignmentDefault = 0,
    WXCCandidateWindowAlignmentBottomEdge = 1,
};
typedef unsigned WXCCandidateWindowAlignment;

// Windows.UI.Xaml.Controls.CharacterCasing
enum _WXCCharacterCasing {
    WXCCharacterCasingNormal = 0,
    WXCCharacterCasingLower = 1,
    WXCCharacterCasingUpper = 2,
};
typedef unsigned WXCCharacterCasing;

// Windows.UI.Xaml.Controls.ClickMode
enum _WXCClickMode {
    WXCClickModeRelease = 0,
    WXCClickModePress = 1,
    WXCClickModeHover = 2,
};
typedef unsigned WXCClickMode;

// Windows.UI.Xaml.Controls.ComboBoxSelectionChangedTrigger
enum _WXCComboBoxSelectionChangedTrigger {
    WXCComboBoxSelectionChangedTriggerCommitted = 0,
    WXCComboBoxSelectionChangedTriggerAlways = 1,
};
typedef unsigned WXCComboBoxSelectionChangedTrigger;

// Windows.UI.Xaml.Controls.DisabledFormattingAccelerators
enum _WXCDisabledFormattingAccelerators {
    WXCDisabledFormattingAcceleratorsNone = 0,
    WXCDisabledFormattingAcceleratorsBold = 1,
    WXCDisabledFormattingAcceleratorsItalic = 2,
    WXCDisabledFormattingAcceleratorsUnderline = 4,
    WXCDisabledFormattingAcceleratorsAll = -1,
};
typedef unsigned WXCDisabledFormattingAccelerators;

// Windows.UI.Xaml.Controls.IncrementalLoadingTrigger
enum _WXCIncrementalLoadingTrigger {
    WXCIncrementalLoadingTriggerNone = 0,
    WXCIncrementalLoadingTriggerEdge = 1,
};
typedef unsigned WXCIncrementalLoadingTrigger;

// Windows.UI.Xaml.Controls.ItemsUpdatingScrollMode
enum _WXCItemsUpdatingScrollMode {
    WXCItemsUpdatingScrollModeKeepItemsInView = 0,
    WXCItemsUpdatingScrollModeKeepScrollOffset = 1,
    WXCItemsUpdatingScrollModeKeepLastItemInView = 2,
};
typedef unsigned WXCItemsUpdatingScrollMode;

// Windows.UI.Xaml.Controls.ListViewReorderMode
enum _WXCListViewReorderMode {
    WXCListViewReorderModeDisabled = 0,
    WXCListViewReorderModeEnabled = 1,
};
typedef unsigned WXCListViewReorderMode;

// Windows.UI.Xaml.Controls.ListViewSelectionMode
enum _WXCListViewSelectionMode {
    WXCListViewSelectionModeNone = 0,
    WXCListViewSelectionModeSingle = 1,
    WXCListViewSelectionModeMultiple = 2,
    WXCListViewSelectionModeExtended = 3,
};
typedef unsigned WXCListViewSelectionMode;

// Windows.UI.Xaml.Controls.Orientation
enum _WXCOrientation {
    WXCOrientationVertical = 0,
    WXCOrientationHorizontal = 1,
};
typedef unsigned WXCOrientation;

// Windows.UI.Xaml.Controls.PanelScrollingDirection
enum _WXCPanelScrollingDirection {
    WXCPanelScrollingDirectionNone = 0,
    WXCPanelScrollingDirectionForward = 1,
    WXCPanelScrollingDirectionBackward = 2,
};
typedef unsigned WXCPanelScrollingDirection;

// Windows.UI.Xaml.Controls.PasswordRevealMode
enum _WXCPasswordRevealMode {
    WXCPasswordRevealModePeek = 0,
    WXCPasswordRevealModeHidden = 1,
    WXCPasswordRevealModeVisible = 2,
};
typedef unsigned WXCPasswordRevealMode;

// Windows.UI.Xaml.Controls.RichEditClipboardFormat
enum _WXCRichEditClipboardFormat {
    WXCRichEditClipboardFormatAllFormats = 0,
    WXCRichEditClipboardFormatPlainText = 1,
};
typedef unsigned WXCRichEditClipboardFormat;

// Windows.UI.Xaml.Controls.ScrollBarVisibility
enum _WXCScrollBarVisibility {
    WXCScrollBarVisibilityDisabled = 0,
    WXCScrollBarVisibilityAuto = 1,
    WXCScrollBarVisibilityHidden = 2,
    WXCScrollBarVisibilityVisible = 3,
};
typedef unsigned WXCScrollBarVisibility;

// Windows.UI.Xaml.Controls.ScrollIntoViewAlignment
enum _WXCScrollIntoViewAlignment {
    WXCScrollIntoViewAlignmentDefault = 0,
    WXCScrollIntoViewAlignmentLeading = 1,
};
typedef unsigned WXCScrollIntoViewAlignment;

// Windows.UI.Xaml.Controls.ScrollMode
enum _WXCScrollMode {
    WXCScrollModeDisabled = 0,
    WXCScrollModeEnabled = 1,
    WXCScrollModeAuto = 2,
};
typedef unsigned WXCScrollMode;

// Windows.UI.Xaml.Controls.SelectionMode
enum _WXCSelectionMode {
    WXCSelectionModeSingle = 0,
    WXCSelectionModeMultiple = 1,
    WXCSelectionModeExtended = 2,
};
typedef unsigned WXCSelectionMode;

// Windows.UI.Xaml.Controls.SnapPointsType
enum _WXCSnapPointsType {
    WXCSnapPointsTypeNone = 0,
    WXCSnapPointsTypeOptional = 1,
    WXCSnapPointsTypeMandatory = 2,
    WXCSnapPointsTypeOptionalSingle = 3,
    WXCSnapPointsTypeMandatorySingle = 4,
};
typedef unsigned WXCSnapPointsType;

// Windows.UI.Xaml.Controls.StretchDirection
enum _WXCStretchDirection {
    WXCStretchDirectionUpOnly = 0,
    WXCStretchDirectionDownOnly = 1,
    WXCStretchDirectionBoth = 2,
};
typedef unsigned WXCStretchDirection;

// Windows.UI.Xaml.Controls.VirtualizationMode
enum _WXCVirtualizationMode {
    WXCVirtualizationModeStandard = 0,
    WXCVirtualizationModeRecycling = 1,
};
typedef unsigned WXCVirtualizationMode;

// Windows.UI.Xaml.Controls.ZoomMode
enum _WXCZoomMode {
    WXCZoomModeDisabled = 0,
    WXCZoomModeEnabled = 1,
};
typedef unsigned WXCZoomMode;

// Windows.UI.Xaml.Controls.AppBarClosedDisplayMode
enum _WXCAppBarClosedDisplayMode {
    WXCAppBarClosedDisplayModeCompact = 0,
    WXCAppBarClosedDisplayModeMinimal = 1,
    WXCAppBarClosedDisplayModeHidden = 2,
};
typedef unsigned WXCAppBarClosedDisplayMode;

// Windows.UI.Xaml.Controls.AutoSuggestionBoxTextChangeReason
enum _WXCAutoSuggestionBoxTextChangeReason {
    WXCAutoSuggestionBoxTextChangeReasonUserInput = 0,
    WXCAutoSuggestionBoxTextChangeReasonProgrammaticChange = 1,
    WXCAutoSuggestionBoxTextChangeReasonSuggestionChosen = 2,
};
typedef unsigned WXCAutoSuggestionBoxTextChangeReason;

// Windows.UI.Xaml.Controls.CalendarViewDisplayMode
enum _WXCCalendarViewDisplayMode {
    WXCCalendarViewDisplayModeMonth = 0,
    WXCCalendarViewDisplayModeYear = 1,
    WXCCalendarViewDisplayModeDecade = 2,
};
typedef unsigned WXCCalendarViewDisplayMode;

// Windows.UI.Xaml.Controls.CalendarViewSelectionMode
enum _WXCCalendarViewSelectionMode {
    WXCCalendarViewSelectionModeNone = 0,
    WXCCalendarViewSelectionModeSingle = 1,
    WXCCalendarViewSelectionModeMultiple = 2,
};
typedef unsigned WXCCalendarViewSelectionMode;

// Windows.UI.Xaml.Controls.CommandBarDefaultLabelPosition
enum _WXCCommandBarDefaultLabelPosition {
    WXCCommandBarDefaultLabelPositionBottom = 0,
    WXCCommandBarDefaultLabelPositionRight = 1,
    WXCCommandBarDefaultLabelPositionCollapsed = 2,
};
typedef unsigned WXCCommandBarDefaultLabelPosition;

// Windows.UI.Xaml.Controls.CommandBarDynamicOverflowAction
enum _WXCCommandBarDynamicOverflowAction {
    WXCCommandBarDynamicOverflowActionAddingToOverflow = 0,
    WXCCommandBarDynamicOverflowActionRemovingFromOverflow = 1,
};
typedef unsigned WXCCommandBarDynamicOverflowAction;

// Windows.UI.Xaml.Controls.CommandBarLabelPosition
enum _WXCCommandBarLabelPosition {
    WXCCommandBarLabelPositionDefault = 0,
    WXCCommandBarLabelPositionCollapsed = 1,
};
typedef unsigned WXCCommandBarLabelPosition;

// Windows.UI.Xaml.Controls.CommandBarOverflowButtonVisibility
enum _WXCCommandBarOverflowButtonVisibility {
    WXCCommandBarOverflowButtonVisibilityAuto = 0,
    WXCCommandBarOverflowButtonVisibilityVisible = 1,
    WXCCommandBarOverflowButtonVisibilityCollapsed = 2,
};
typedef unsigned WXCCommandBarOverflowButtonVisibility;

// Windows.UI.Xaml.Controls.ContentDialogButton
enum _WXCContentDialogButton {
    WXCContentDialogButtonNone = 0,
    WXCContentDialogButtonPrimary = 1,
    WXCContentDialogButtonSecondary = 2,
    WXCContentDialogButtonClose = 3,
};
typedef unsigned WXCContentDialogButton;

// Windows.UI.Xaml.Controls.ContentDialogPlacement
enum _WXCContentDialogPlacement {
    WXCContentDialogPlacementPopup = 0,
    WXCContentDialogPlacementInPlace = 1,
};
typedef unsigned WXCContentDialogPlacement;

// Windows.UI.Xaml.Controls.ContentDialogResult
enum _WXCContentDialogResult {
    WXCContentDialogResultNone = 0,
    WXCContentDialogResultPrimary = 1,
    WXCContentDialogResultSecondary = 2,
};
typedef unsigned WXCContentDialogResult;

// Windows.UI.Xaml.Controls.SplitViewDisplayMode
enum _WXCSplitViewDisplayMode {
    WXCSplitViewDisplayModeOverlay = 0,
    WXCSplitViewDisplayModeInline = 1,
    WXCSplitViewDisplayModeCompactOverlay = 2,
    WXCSplitViewDisplayModeCompactInline = 3,
};
typedef unsigned WXCSplitViewDisplayMode;

// Windows.UI.Xaml.Controls.SplitViewPanePlacement
enum _WXCSplitViewPanePlacement {
    WXCSplitViewPanePlacementLeft = 0,
    WXCSplitViewPanePlacementRight = 1,
};
typedef unsigned WXCSplitViewPanePlacement;

// Windows.UI.Xaml.Controls.Symbol
enum _WXCSymbol {
    WXCSymbolPrevious = 57600,
    WXCSymbolNext = 57601,
    WXCSymbolPlay = 57602,
    WXCSymbolPause = 57603,
    WXCSymbolEdit = 57604,
    WXCSymbolSave = 57605,
    WXCSymbolClear = 57606,
    WXCSymbolDelete = 57607,
    WXCSymbolRemove = 57608,
    WXCSymbolAdd = 57609,
    WXCSymbolCancel = 57610,
    WXCSymbolAccept = 57611,
    WXCSymbolMore = 57612,
    WXCSymbolRedo = 57613,
    WXCSymbolUndo = 57614,
    WXCSymbolHome = 57615,
    WXCSymbolUp = 57616,
    WXCSymbolForward = 57617,
    WXCSymbolBack = 57618,
    WXCSymbolFavorite = 57619,
    WXCSymbolCamera = 57620,
    WXCSymbolSetting = 57621,
    WXCSymbolVideo = 57622,
    WXCSymbolSync = 57623,
    WXCSymbolDownload = 57624,
    WXCSymbolMail = 57625,
    WXCSymbolFind = 57626,
    WXCSymbolHelp = 57627,
    WXCSymbolUpload = 57628,
    WXCSymbolEmoji = 57629,
    WXCSymbolTwoPage = 57630,
    WXCSymbolLeaveChat = 57631,
    WXCSymbolMailForward = 57632,
    WXCSymbolClock = 57633,
    WXCSymbolSend = 57634,
    WXCSymbolCrop = 57635,
    WXCSymbolRotateCamera = 57636,
    WXCSymbolPeople = 57637,
    WXCSymbolOpenPane = 57638,
    WXCSymbolClosePane = 57639,
    WXCSymbolWorld = 57640,
    WXCSymbolFlag = 57641,
    WXCSymbolPreviewLink = 57642,
    WXCSymbolGlobe = 57643,
    WXCSymbolTrim = 57644,
    WXCSymbolAttachCamera = 57645,
    WXCSymbolZoomIn = 57646,
    WXCSymbolBookmarks = 57647,
    WXCSymbolDocument = 57648,
    WXCSymbolProtectedDocument = 57649,
    WXCSymbolPage = 57650,
    WXCSymbolBullets = 57651,
    WXCSymbolComment = 57652,
    WXCSymbolMailFilled = 57653,
    WXCSymbolContactInfo = 57654,
    WXCSymbolHangUp = 57655,
    WXCSymbolViewAll = 57656,
    WXCSymbolMapPin = 57657,
    WXCSymbolPhone = 57658,
    WXCSymbolVideoChat = 57659,
    WXCSymbolSwitch = 57660,
    WXCSymbolContact = 57661,
    WXCSymbolRename = 57662,
    WXCSymbolPin = 57665,
    WXCSymbolMusicInfo = 57666,
    WXCSymbolGo = 57667,
    WXCSymbolKeyboard = 57668,
    WXCSymbolDockLeft = 57669,
    WXCSymbolDockRight = 57670,
    WXCSymbolDockBottom = 57671,
    WXCSymbolRemote = 57672,
    WXCSymbolRefresh = 57673,
    WXCSymbolRotate = 57674,
    WXCSymbolShuffle = 57675,
    WXCSymbolList = 57676,
    WXCSymbolShop = 57677,
    WXCSymbolSelectAll = 57678,
    WXCSymbolOrientation = 57679,
    WXCSymbolImport = 57680,
    WXCSymbolImportAll = 57681,
    WXCSymbolBrowsePhotos = 57685,
    WXCSymbolWebCam = 57686,
    WXCSymbolPictures = 57688,
    WXCSymbolSaveLocal = 57689,
    WXCSymbolCaption = 57690,
    WXCSymbolStop = 57691,
    WXCSymbolShowResults = 57692,
    WXCSymbolVolume = 57693,
    WXCSymbolRepair = 57694,
    WXCSymbolMessage = 57695,
    WXCSymbolPage2 = 57696,
    WXCSymbolCalendarDay = 57697,
    WXCSymbolCalendarWeek = 57698,
    WXCSymbolCalendar = 57699,
    WXCSymbolCharacter = 57700,
    WXCSymbolMailReplyAll = 57701,
    WXCSymbolRead = 57702,
    WXCSymbolLink = 57703,
    WXCSymbolAccount = 57704,
    WXCSymbolShowBcc = 57705,
    WXCSymbolHideBcc = 57706,
    WXCSymbolCut = 57707,
    WXCSymbolAttach = 57708,
    WXCSymbolPaste = 57709,
    WXCSymbolFilter = 57710,
    WXCSymbolCopy = 57711,
    WXCSymbolEmoji2 = 57712,
    WXCSymbolImportant = 57713,
    WXCSymbolMailReply = 57714,
    WXCSymbolSlideShow = 57715,
    WXCSymbolSort = 57716,
    WXCSymbolManage = 57720,
    WXCSymbolAllApps = 57721,
    WXCSymbolDisconnectDrive = 57722,
    WXCSymbolMapDrive = 57723,
    WXCSymbolNewWindow = 57724,
    WXCSymbolOpenWith = 57725,
    WXCSymbolContactPresence = 57729,
    WXCSymbolPriority = 57730,
    WXCSymbolGoToToday = 57732,
    WXCSymbolFont = 57733,
    WXCSymbolFontColor = 57734,
    WXCSymbolContact2 = 57735,
    WXCSymbolFolder = 57736,
    WXCSymbolAudio = 57737,
    WXCSymbolPlaceholder = 57738,
    WXCSymbolView = 57739,
    WXCSymbolSetLockScreen = 57740,
    WXCSymbolSetTile = 57741,
    WXCSymbolClosedCaption = 57744,
    WXCSymbolStopSlideShow = 57745,
    WXCSymbolPermissions = 57746,
    WXCSymbolHighlight = 57747,
    WXCSymbolDisableUpdates = 57748,
    WXCSymbolUnFavorite = 57749,
    WXCSymbolUnPin = 57750,
    WXCSymbolOpenLocal = 57751,
    WXCSymbolMute = 57752,
    WXCSymbolItalic = 57753,
    WXCSymbolUnderline = 57754,
    WXCSymbolBold = 57755,
    WXCSymbolMoveToFolder = 57756,
    WXCSymbolLikeDislike = 57757,
    WXCSymbolDislike = 57758,
    WXCSymbolLike = 57759,
    WXCSymbolAlignRight = 57760,
    WXCSymbolAlignCenter = 57761,
    WXCSymbolAlignLeft = 57762,
    WXCSymbolZoom = 57763,
    WXCSymbolZoomOut = 57764,
    WXCSymbolOpenFile = 57765,
    WXCSymbolOtherUser = 57766,
    WXCSymbolAdmin = 57767,
    WXCSymbolStreet = 57795,
    WXCSymbolMap = 57796,
    WXCSymbolClearSelection = 57797,
    WXCSymbolFontDecrease = 57798,
    WXCSymbolFontIncrease = 57799,
    WXCSymbolFontSize = 57800,
    WXCSymbolCellPhone = 57801,
    WXCSymbolReShare = 57802,
    WXCSymbolTag = 57803,
    WXCSymbolRepeatOne = 57804,
    WXCSymbolRepeatAll = 57805,
    WXCSymbolOutlineStar = 57806,
    WXCSymbolSolidStar = 57807,
    WXCSymbolCalculator = 57808,
    WXCSymbolDirections = 57809,
    WXCSymbolTarget = 57810,
    WXCSymbolLibrary = 57811,
    WXCSymbolPhoneBook = 57812,
    WXCSymbolMemo = 57813,
    WXCSymbolMicrophone = 57814,
    WXCSymbolPostUpdate = 57815,
    WXCSymbolBackToWindow = 57816,
    WXCSymbolFullScreen = 57817,
    WXCSymbolNewFolder = 57818,
    WXCSymbolCalendarReply = 57819,
    WXCSymbolUnSyncFolder = 57821,
    WXCSymbolReportHacked = 57822,
    WXCSymbolSyncFolder = 57823,
    WXCSymbolBlockContact = 57824,
    WXCSymbolSwitchApps = 57825,
    WXCSymbolAddFriend = 57826,
    WXCSymbolTouchPointer = 57827,
    WXCSymbolGoToStart = 57828,
    WXCSymbolZeroBars = 57829,
    WXCSymbolOneBar = 57830,
    WXCSymbolTwoBars = 57831,
    WXCSymbolThreeBars = 57832,
    WXCSymbolFourBars = 57833,
    WXCSymbolScan = 58004,
    WXCSymbolPreview = 58005,
    WXCSymbolGlobalNavigationButton = 59136,
    WXCSymbolShare = 59181,
    WXCSymbolPrint = 59209,
    WXCSymbolXboxOneConsole = 59792,
};
typedef unsigned WXCSymbol;

// Windows.UI.Xaml.Controls.WebViewExecutionMode
enum _WXCWebViewExecutionMode {
    WXCWebViewExecutionModeSameThread = 0,
    WXCWebViewExecutionModeSeparateThread = 1,
};
typedef unsigned WXCWebViewExecutionMode;

// Windows.UI.Xaml.Controls.WebViewPermissionState
enum _WXCWebViewPermissionState {
    WXCWebViewPermissionStateUnknown = 0,
    WXCWebViewPermissionStateDefer = 1,
    WXCWebViewPermissionStateAllow = 2,
    WXCWebViewPermissionStateDeny = 3,
};
typedef unsigned WXCWebViewPermissionState;

// Windows.UI.Xaml.Controls.WebViewPermissionType
enum _WXCWebViewPermissionType {
    WXCWebViewPermissionTypeGeolocation = 0,
    WXCWebViewPermissionTypeUnlimitedIndexedDBQuota = 1,
    WXCWebViewPermissionTypeMedia = 2,
    WXCWebViewPermissionTypePointerLock = 3,
    WXCWebViewPermissionTypeWebNotifications = 4,
};
typedef unsigned WXCWebViewPermissionType;

// Windows.UI.Xaml.Controls.LightDismissOverlayMode
enum _WXCLightDismissOverlayMode {
    WXCLightDismissOverlayModeAuto = 0,
    WXCLightDismissOverlayModeOn = 1,
    WXCLightDismissOverlayModeOff = 2,
};
typedef unsigned WXCLightDismissOverlayMode;

// Windows.UI.Xaml.Controls.RequiresPointer
enum _WXCRequiresPointer {
    WXCRequiresPointerNever = 0,
    WXCRequiresPointerWhenEngaged = 1,
    WXCRequiresPointerWhenFocused = 2,
};
typedef unsigned WXCRequiresPointer;

// Windows.UI.Xaml.Controls.InkToolbarButtonFlyoutPlacement
enum _WXCInkToolbarButtonFlyoutPlacement {
    WXCInkToolbarButtonFlyoutPlacementAuto = 0,
    WXCInkToolbarButtonFlyoutPlacementTop = 1,
    WXCInkToolbarButtonFlyoutPlacementBottom = 2,
    WXCInkToolbarButtonFlyoutPlacementLeft = 3,
    WXCInkToolbarButtonFlyoutPlacementRight = 4,
};
typedef unsigned WXCInkToolbarButtonFlyoutPlacement;

// Windows.UI.Xaml.Controls.InkToolbarFlyoutItemKind
enum _WXCInkToolbarFlyoutItemKind {
    WXCInkToolbarFlyoutItemKindSimple = 0,
    WXCInkToolbarFlyoutItemKindRadio = 1,
    WXCInkToolbarFlyoutItemKindCheck = 2,
    WXCInkToolbarFlyoutItemKindRadioCheck = 3,
};
typedef unsigned WXCInkToolbarFlyoutItemKind;

// Windows.UI.Xaml.Controls.InkToolbarInitialControls
enum _WXCInkToolbarInitialControls {
    WXCInkToolbarInitialControlsAll = 0,
    WXCInkToolbarInitialControlsNone = 1,
    WXCInkToolbarInitialControlsPensOnly = 2,
    WXCInkToolbarInitialControlsAllExceptPens = 3,
};
typedef unsigned WXCInkToolbarInitialControls;

// Windows.UI.Xaml.Controls.InkToolbarMenuKind
enum _WXCInkToolbarMenuKind {
    WXCInkToolbarMenuKindStencil = 0,
};
typedef unsigned WXCInkToolbarMenuKind;

// Windows.UI.Xaml.Controls.InkToolbarStencilKind
enum _WXCInkToolbarStencilKind {
    WXCInkToolbarStencilKindRuler = 0,
    WXCInkToolbarStencilKindProtractor = 1,
};
typedef unsigned WXCInkToolbarStencilKind;

// Windows.UI.Xaml.Controls.InkToolbarToggle
enum _WXCInkToolbarToggle {
    WXCInkToolbarToggleRuler = 0,
    WXCInkToolbarToggleCustom = 1,
};
typedef unsigned WXCInkToolbarToggle;

// Windows.UI.Xaml.Controls.InkToolbarTool
enum _WXCInkToolbarTool {
    WXCInkToolbarToolBallpointPen = 0,
    WXCInkToolbarToolPencil = 1,
    WXCInkToolbarToolHighlighter = 2,
    WXCInkToolbarToolEraser = 3,
    WXCInkToolbarToolCustomPen = 4,
    WXCInkToolbarToolCustomTool = 5,
};
typedef unsigned WXCInkToolbarTool;

// Windows.UI.Xaml.Controls.ListPickerFlyoutSelectionMode
enum _WXCListPickerFlyoutSelectionMode {
    WXCListPickerFlyoutSelectionModeSingle = 0,
    WXCListPickerFlyoutSelectionModeMultiple = 1,
};
typedef unsigned WXCListPickerFlyoutSelectionMode;

// Windows.UI.Xaml.Controls.PivotHeaderFocusVisualPlacement
enum _WXCPivotHeaderFocusVisualPlacement {
    WXCPivotHeaderFocusVisualPlacementItemHeaders = 0,
    WXCPivotHeaderFocusVisualPlacementSelectedItemHeader = 1,
};
typedef unsigned WXCPivotHeaderFocusVisualPlacement;

// Windows.UI.Xaml.Controls.PivotSlideInAnimationGroup
enum _WXCPivotSlideInAnimationGroup {
    WXCPivotSlideInAnimationGroupDefault = 0,
    WXCPivotSlideInAnimationGroupGroupOne = 1,
    WXCPivotSlideInAnimationGroupGroupTwo = 2,
    WXCPivotSlideInAnimationGroupGroupThree = 3,
};
typedef unsigned WXCPivotSlideInAnimationGroup;

#include "WindowsUIXamlDocuments.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsApplicationModelContacts.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsUIXamlData.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsUI.h"
#include "WindowsFoundation.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIXaml.h"
#include "WindowsUIXamlInterop.h"
#include "WindowsUIText.h"
#include "WindowsMediaCapture.h"
#include "WindowsMediaPlayTo.h"
#include "WindowsMediaCasting.h"
#include "WindowsUIComposition.h"
#include "WindowsUIXamlMediaMedia3D.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsGlobalization.h"
#include "WindowsSystem.h"
#include "WindowsWeb.h"
#include "WindowsUIInputInking.h"
#include "WindowsMediaProtection.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaCore.h"
#include "WindowsMediaPlayback.h"
#include "WindowsWebHttp.h"
#include "WindowsUIXamlNavigation.h"
#include "WindowsUICore.h"
#include "WindowsUIInput.h"
#include "WindowsUIXamlAutomationPeers.h"
// Windows.UI.Xaml.Controls.BackClickEventHandler
#ifndef __WXCBackClickEventHandler__DEFINED
#define __WXCBackClickEventHandler__DEFINED
typedef void(^WXCBackClickEventHandler)(RTObject* sender, WXCBackClickEventArgs* e);
#endif // __WXCBackClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.CalendarViewDayItemChangingEventHandler
#ifndef __WXCCalendarViewDayItemChangingEventHandler__DEFINED
#define __WXCCalendarViewDayItemChangingEventHandler__DEFINED
typedef void(^WXCCalendarViewDayItemChangingEventHandler)(WXCCalendarView* sender, WXCCalendarViewDayItemChangingEventArgs* e);
#endif // __WXCCalendarViewDayItemChangingEventHandler__DEFINED

// Windows.UI.Xaml.Controls.CleanUpVirtualizedItemEventHandler
#ifndef __WXCCleanUpVirtualizedItemEventHandler__DEFINED
#define __WXCCleanUpVirtualizedItemEventHandler__DEFINED
typedef void(^WXCCleanUpVirtualizedItemEventHandler)(RTObject* sender, WXCCleanUpVirtualizedItemEventArgs* e);
#endif // __WXCCleanUpVirtualizedItemEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ContextMenuOpeningEventHandler
#ifndef __WXCContextMenuOpeningEventHandler__DEFINED
#define __WXCContextMenuOpeningEventHandler__DEFINED
typedef void(^WXCContextMenuOpeningEventHandler)(RTObject* sender, WXCContextMenuEventArgs* e);
#endif // __WXCContextMenuOpeningEventHandler__DEFINED

// Windows.UI.Xaml.Controls.DragItemsStartingEventHandler
#ifndef __WXCDragItemsStartingEventHandler__DEFINED
#define __WXCDragItemsStartingEventHandler__DEFINED
typedef void(^WXCDragItemsStartingEventHandler)(RTObject* sender, WXCDragItemsStartingEventArgs* e);
#endif // __WXCDragItemsStartingEventHandler__DEFINED

// Windows.UI.Xaml.Controls.HubSectionHeaderClickEventHandler
#ifndef __WXCHubSectionHeaderClickEventHandler__DEFINED
#define __WXCHubSectionHeaderClickEventHandler__DEFINED
typedef void(^WXCHubSectionHeaderClickEventHandler)(RTObject* sender, WXCHubSectionHeaderClickEventArgs* e);
#endif // __WXCHubSectionHeaderClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ItemClickEventHandler
#ifndef __WXCItemClickEventHandler__DEFINED
#define __WXCItemClickEventHandler__DEFINED
typedef void(^WXCItemClickEventHandler)(RTObject* sender, WXCItemClickEventArgs* e);
#endif // __WXCItemClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ListViewItemToKeyHandler
#ifndef __WXCListViewItemToKeyHandler__DEFINED
#define __WXCListViewItemToKeyHandler__DEFINED
typedef void(^WXCListViewItemToKeyHandler)(RTObject* item);
#endif // __WXCListViewItemToKeyHandler__DEFINED

// Windows.UI.Xaml.Controls.ListViewKeyToItemHandler
#ifndef __WXCListViewKeyToItemHandler__DEFINED
#define __WXCListViewKeyToItemHandler__DEFINED
typedef void(^WXCListViewKeyToItemHandler)(NSString * key);
#endif // __WXCListViewKeyToItemHandler__DEFINED

// Windows.UI.Xaml.Controls.NotifyEventHandler
#ifndef __WXCNotifyEventHandler__DEFINED
#define __WXCNotifyEventHandler__DEFINED
typedef void(^WXCNotifyEventHandler)(RTObject* sender, WXCNotifyEventArgs* e);
#endif // __WXCNotifyEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.ItemsChangedEventHandler
#ifndef __WUXCPItemsChangedEventHandler__DEFINED
#define __WUXCPItemsChangedEventHandler__DEFINED
typedef void(^WUXCPItemsChangedEventHandler)(RTObject* sender, WUXCPItemsChangedEventArgs* e);
#endif // __WUXCPItemsChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.RangeBaseValueChangedEventHandler
#ifndef __WUXCPRangeBaseValueChangedEventHandler__DEFINED
#define __WUXCPRangeBaseValueChangedEventHandler__DEFINED
typedef void(^WUXCPRangeBaseValueChangedEventHandler)(RTObject* sender, WUXCPRangeBaseValueChangedEventArgs* e);
#endif // __WUXCPRangeBaseValueChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SectionsInViewChangedEventHandler
#ifndef __WXCSectionsInViewChangedEventHandler__DEFINED
#define __WXCSectionsInViewChangedEventHandler__DEFINED
typedef void(^WXCSectionsInViewChangedEventHandler)(RTObject* sender, WXCSectionsInViewChangedEventArgs* e);
#endif // __WXCSectionsInViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SelectionChangedEventHandler
#ifndef __WXCSelectionChangedEventHandler__DEFINED
#define __WXCSelectionChangedEventHandler__DEFINED
typedef void(^WXCSelectionChangedEventHandler)(RTObject* sender, WXCSelectionChangedEventArgs* e);
#endif // __WXCSelectionChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SemanticZoomViewChangedEventHandler
#ifndef __WXCSemanticZoomViewChangedEventHandler__DEFINED
#define __WXCSemanticZoomViewChangedEventHandler__DEFINED
typedef void(^WXCSemanticZoomViewChangedEventHandler)(RTObject* sender, WXCSemanticZoomViewChangedEventArgs* e);
#endif // __WXCSemanticZoomViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextChangedEventHandler
#ifndef __WXCTextChangedEventHandler__DEFINED
#define __WXCTextChangedEventHandler__DEFINED
typedef void(^WXCTextChangedEventHandler)(RTObject* sender, WXCTextChangedEventArgs* e);
#endif // __WXCTextChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextControlPasteEventHandler
#ifndef __WXCTextControlPasteEventHandler__DEFINED
#define __WXCTextControlPasteEventHandler__DEFINED
typedef void(^WXCTextControlPasteEventHandler)(RTObject* sender, WXCTextControlPasteEventArgs* e);
#endif // __WXCTextControlPasteEventHandler__DEFINED

// Windows.UI.Xaml.Controls.WebViewNavigationFailedEventHandler
#ifndef __WXCWebViewNavigationFailedEventHandler__DEFINED
#define __WXCWebViewNavigationFailedEventHandler__DEFINED
typedef void(^WXCWebViewNavigationFailedEventHandler)(RTObject* sender, WXCWebViewNavigationFailedEventArgs* e);
#endif // __WXCWebViewNavigationFailedEventHandler__DEFINED

// Windows.UI.Xaml.Data.PropertyChangedEventHandler
#ifndef __WUXDPropertyChangedEventHandler__DEFINED
#define __WUXDPropertyChangedEventHandler__DEFINED
typedef void(^WUXDPropertyChangedEventHandler)(RTObject* sender, WUXDPropertyChangedEventArgs* e);
#endif // __WUXDPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void(^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedEventHandler
#ifndef __WXDependencyPropertyChangedEventHandler__DEFINED
#define __WXDependencyPropertyChangedEventHandler__DEFINED
typedef void(^WXDependencyPropertyChangedEventHandler)(RTObject* sender, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXDependencyPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void(^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.ExceptionRoutedEventHandler
#ifndef __WXExceptionRoutedEventHandler__DEFINED
#define __WXExceptionRoutedEventHandler__DEFINED
typedef void(^WXExceptionRoutedEventHandler)(RTObject* sender, WXExceptionRoutedEventArgs* e);
#endif // __WXExceptionRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void(^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void(^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void(^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void(^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void(^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void(^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void(^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void(^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void(^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void(^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void(^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.Media.RateChangedRoutedEventHandler
#ifndef __WUXMRateChangedRoutedEventHandler__DEFINED
#define __WUXMRateChangedRoutedEventHandler__DEFINED
typedef void(^WUXMRateChangedRoutedEventHandler)(RTObject* sender, WUXMRateChangedRoutedEventArgs* e);
#endif // __WUXMRateChangedRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Media.TimelineMarkerRoutedEventHandler
#ifndef __WUXMTimelineMarkerRoutedEventHandler__DEFINED
#define __WUXMTimelineMarkerRoutedEventHandler__DEFINED
typedef void(^WUXMTimelineMarkerRoutedEventHandler)(RTObject* sender, WUXMTimelineMarkerRoutedEventArgs* e);
#endif // __WUXMTimelineMarkerRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.LoadCompletedEventHandler
#ifndef __WUXNLoadCompletedEventHandler__DEFINED
#define __WUXNLoadCompletedEventHandler__DEFINED
typedef void(^WUXNLoadCompletedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNLoadCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigatedEventHandler
#ifndef __WUXNNavigatedEventHandler__DEFINED
#define __WUXNNavigatedEventHandler__DEFINED
typedef void(^WUXNNavigatedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNNavigatedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigatingCancelEventHandler
#ifndef __WUXNNavigatingCancelEventHandler__DEFINED
#define __WUXNNavigatingCancelEventHandler__DEFINED
typedef void(^WUXNNavigatingCancelEventHandler)(RTObject* sender, WUXNNavigatingCancelEventArgs* e);
#endif // __WUXNNavigatingCancelEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigationFailedEventHandler
#ifndef __WUXNNavigationFailedEventHandler__DEFINED
#define __WUXNNavigationFailedEventHandler__DEFINED
typedef void(^WUXNNavigationFailedEventHandler)(RTObject* sender, WUXNNavigationFailedEventArgs* e);
#endif // __WUXNNavigationFailedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigationStoppedEventHandler
#ifndef __WUXNNavigationStoppedEventHandler__DEFINED
#define __WUXNNavigationStoppedEventHandler__DEFINED
typedef void(^WUXNNavigationStoppedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNNavigationStoppedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void(^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void(^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED


#import <Foundation/Foundation.h>

// Windows.UI.Xaml.Controls.BackClickEventHandler
#ifndef __WXCBackClickEventHandler__DEFINED
#define __WXCBackClickEventHandler__DEFINED
typedef void(^WXCBackClickEventHandler)(RTObject* sender, WXCBackClickEventArgs* e);
#endif // __WXCBackClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.CleanUpVirtualizedItemEventHandler
#ifndef __WXCCleanUpVirtualizedItemEventHandler__DEFINED
#define __WXCCleanUpVirtualizedItemEventHandler__DEFINED
typedef void(^WXCCleanUpVirtualizedItemEventHandler)(RTObject* sender, WXCCleanUpVirtualizedItemEventArgs* e);
#endif // __WXCCleanUpVirtualizedItemEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ContextMenuOpeningEventHandler
#ifndef __WXCContextMenuOpeningEventHandler__DEFINED
#define __WXCContextMenuOpeningEventHandler__DEFINED
typedef void(^WXCContextMenuOpeningEventHandler)(RTObject* sender, WXCContextMenuEventArgs* e);
#endif // __WXCContextMenuOpeningEventHandler__DEFINED

// Windows.UI.Xaml.Controls.DragItemsStartingEventHandler
#ifndef __WXCDragItemsStartingEventHandler__DEFINED
#define __WXCDragItemsStartingEventHandler__DEFINED
typedef void(^WXCDragItemsStartingEventHandler)(RTObject* sender, WXCDragItemsStartingEventArgs* e);
#endif // __WXCDragItemsStartingEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ItemClickEventHandler
#ifndef __WXCItemClickEventHandler__DEFINED
#define __WXCItemClickEventHandler__DEFINED
typedef void(^WXCItemClickEventHandler)(RTObject* sender, WXCItemClickEventArgs* e);
#endif // __WXCItemClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.NotifyEventHandler
#ifndef __WXCNotifyEventHandler__DEFINED
#define __WXCNotifyEventHandler__DEFINED
typedef void(^WXCNotifyEventHandler)(RTObject* sender, WXCNotifyEventArgs* e);
#endif // __WXCNotifyEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SelectionChangedEventHandler
#ifndef __WXCSelectionChangedEventHandler__DEFINED
#define __WXCSelectionChangedEventHandler__DEFINED
typedef void(^WXCSelectionChangedEventHandler)(RTObject* sender, WXCSelectionChangedEventArgs* e);
#endif // __WXCSelectionChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SemanticZoomViewChangedEventHandler
#ifndef __WXCSemanticZoomViewChangedEventHandler__DEFINED
#define __WXCSemanticZoomViewChangedEventHandler__DEFINED
typedef void(^WXCSemanticZoomViewChangedEventHandler)(RTObject* sender, WXCSemanticZoomViewChangedEventArgs* e);
#endif // __WXCSemanticZoomViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextChangedEventHandler
#ifndef __WXCTextChangedEventHandler__DEFINED
#define __WXCTextChangedEventHandler__DEFINED
typedef void(^WXCTextChangedEventHandler)(RTObject* sender, WXCTextChangedEventArgs* e);
#endif // __WXCTextChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextControlPasteEventHandler
#ifndef __WXCTextControlPasteEventHandler__DEFINED
#define __WXCTextControlPasteEventHandler__DEFINED
typedef void(^WXCTextControlPasteEventHandler)(RTObject* sender, WXCTextControlPasteEventArgs* e);
#endif // __WXCTextControlPasteEventHandler__DEFINED

// Windows.UI.Xaml.Controls.CalendarViewDayItemChangingEventHandler
#ifndef __WXCCalendarViewDayItemChangingEventHandler__DEFINED
#define __WXCCalendarViewDayItemChangingEventHandler__DEFINED
typedef void(^WXCCalendarViewDayItemChangingEventHandler)(WXCCalendarView* sender, WXCCalendarViewDayItemChangingEventArgs* e);
#endif // __WXCCalendarViewDayItemChangingEventHandler__DEFINED

// Windows.UI.Xaml.Controls.HubSectionHeaderClickEventHandler
#ifndef __WXCHubSectionHeaderClickEventHandler__DEFINED
#define __WXCHubSectionHeaderClickEventHandler__DEFINED
typedef void(^WXCHubSectionHeaderClickEventHandler)(RTObject* sender, WXCHubSectionHeaderClickEventArgs* e);
#endif // __WXCHubSectionHeaderClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ListViewItemToKeyHandler
#ifndef __WXCListViewItemToKeyHandler__DEFINED
#define __WXCListViewItemToKeyHandler__DEFINED
typedef void(^WXCListViewItemToKeyHandler)(RTObject* item);
#endif // __WXCListViewItemToKeyHandler__DEFINED

// Windows.UI.Xaml.Controls.ListViewKeyToItemHandler
#ifndef __WXCListViewKeyToItemHandler__DEFINED
#define __WXCListViewKeyToItemHandler__DEFINED
typedef void(^WXCListViewKeyToItemHandler)(NSString * key);
#endif // __WXCListViewKeyToItemHandler__DEFINED

// Windows.UI.Xaml.Controls.SectionsInViewChangedEventHandler
#ifndef __WXCSectionsInViewChangedEventHandler__DEFINED
#define __WXCSectionsInViewChangedEventHandler__DEFINED
typedef void(^WXCSectionsInViewChangedEventHandler)(RTObject* sender, WXCSectionsInViewChangedEventArgs* e);
#endif // __WXCSectionsInViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.WebViewNavigationFailedEventHandler
#ifndef __WXCWebViewNavigationFailedEventHandler__DEFINED
#define __WXCWebViewNavigationFailedEventHandler__DEFINED
typedef void(^WXCWebViewNavigationFailedEventHandler)(RTObject* sender, WXCWebViewNavigationFailedEventArgs* e);
#endif // __WXCWebViewNavigationFailedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.IInsertionPanel
#ifndef __WXCIInsertionPanel_DEFINED__
#define __WXCIInsertionPanel_DEFINED__

@protocol WXCIInsertionPanel
- (void)getInsertionIndexes:(WFPoint*)position first:(int*)first second:(int*)second;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIInsertionPanel : RTObject <WXCIInsertionPanel>
@end

#endif // __WXCIInsertionPanel_DEFINED__

// Windows.UI.Xaml.Controls.IItemContainerMapping
#ifndef __WXCIItemContainerMapping_DEFINED__
#define __WXCIItemContainerMapping_DEFINED__

@protocol WXCIItemContainerMapping
- (RTObject*)itemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromItem:(RTObject*)item;
- (int)indexFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromIndex:(int)index;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIItemContainerMapping : RTObject <WXCIItemContainerMapping>
@end

#endif // __WXCIItemContainerMapping_DEFINED__

// Windows.UI.Xaml.Controls.INavigate
#ifndef __WXCINavigate_DEFINED__
#define __WXCINavigate_DEFINED__

@protocol WXCINavigate
- (BOOL)navigate:(WUXITypeName*)sourcePageType;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCINavigate : RTObject <WXCINavigate>
@end

#endif // __WXCINavigate_DEFINED__

// Windows.UI.Xaml.Controls.ISemanticZoomInformation
#ifndef __WXCISemanticZoomInformation_DEFINED__
#define __WXCISemanticZoomInformation_DEFINED__

@protocol WXCISemanticZoomInformation
@property BOOL isActiveView;
@property BOOL isZoomedInView;
@property (retain) WXCSemanticZoom* semanticZoomOwner;
- (void)initializeViewChange;
- (void)completeViewChange;
- (void)makeVisible:(WXCSemanticZoomLocation*)item;
- (void)startViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)startViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCISemanticZoomInformation : RTObject <WXCISemanticZoomInformation>
@end

#endif // __WXCISemanticZoomInformation_DEFINED__

// Windows.UI.Xaml.Controls.IDataTemplateSelectorOverrides
#ifndef __WXCIDataTemplateSelectorOverrides_DEFINED__
#define __WXCIDataTemplateSelectorOverrides_DEFINED__

@protocol WXCIDataTemplateSelectorOverrides
- (WXDataTemplate*)selectTemplateCore:(RTObject*)item container:(WXDependencyObject*)container;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIDataTemplateSelectorOverrides : RTObject <WXCIDataTemplateSelectorOverrides>
@end

#endif // __WXCIDataTemplateSelectorOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IDataTemplateSelectorOverrides2
#ifndef __WXCIDataTemplateSelectorOverrides2_DEFINED__
#define __WXCIDataTemplateSelectorOverrides2_DEFINED__

@protocol WXCIDataTemplateSelectorOverrides2
- (WXDataTemplate*)selectTemplateForItemCore:(RTObject*)item;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIDataTemplateSelectorOverrides2 : RTObject <WXCIDataTemplateSelectorOverrides2>
@end

#endif // __WXCIDataTemplateSelectorOverrides2_DEFINED__

// Windows.UI.Xaml.Controls.IGroupStyleSelectorOverrides
#ifndef __WXCIGroupStyleSelectorOverrides_DEFINED__
#define __WXCIGroupStyleSelectorOverrides_DEFINED__

@protocol WXCIGroupStyleSelectorOverrides
- (WXCGroupStyle*)selectGroupStyleCore:(RTObject*)group level:(unsigned int)level;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIGroupStyleSelectorOverrides : RTObject <WXCIGroupStyleSelectorOverrides>
@end

#endif // __WXCIGroupStyleSelectorOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IStyleSelectorOverrides
#ifndef __WXCIStyleSelectorOverrides_DEFINED__
#define __WXCIStyleSelectorOverrides_DEFINED__

@protocol WXCIStyleSelectorOverrides
- (WXStyle*)selectStyleCore:(RTObject*)item container:(WXDependencyObject*)container;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIStyleSelectorOverrides : RTObject <WXCIStyleSelectorOverrides>
@end

#endif // __WXCIStyleSelectorOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IContentPresenterOverrides
#ifndef __WXCIContentPresenterOverrides_DEFINED__
#define __WXCIContentPresenterOverrides_DEFINED__

@protocol WXCIContentPresenterOverrides
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIContentPresenterOverrides : RTObject <WXCIContentPresenterOverrides>
@end

#endif // __WXCIContentPresenterOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IContentControlOverrides
#ifndef __WXCIContentControlOverrides_DEFINED__
#define __WXCIContentControlOverrides_DEFINED__

@protocol WXCIContentControlOverrides
- (void)onContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIContentControlOverrides : RTObject <WXCIContentControlOverrides>
@end

#endif // __WXCIContentControlOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IItemsControlOverrides
#ifndef __WXCIItemsControlOverrides_DEFINED__
#define __WXCIItemsControlOverrides_DEFINED__

@protocol WXCIItemsControlOverrides
- (BOOL)isItemItsOwnContainerOverride:(RTObject*)item;
- (WXDependencyObject*)getContainerForItemOverride;
- (void)clearContainerForItemOverride:(WXDependencyObject*)element item:(RTObject*)item;
- (void)prepareContainerForItemOverride:(WXDependencyObject*)element item:(RTObject*)item;
- (void)onItemsChanged:(RTObject*)e;
- (void)onItemContainerStyleChanged:(WXStyle*)oldItemContainerStyle newItemContainerStyle:(WXStyle*)newItemContainerStyle;
- (void)onItemContainerStyleSelectorChanged:(WXCStyleSelector*)oldItemContainerStyleSelector newItemContainerStyleSelector:(WXCStyleSelector*)newItemContainerStyleSelector;
- (void)onItemTemplateChanged:(WXDataTemplate*)oldItemTemplate newItemTemplate:(WXDataTemplate*)newItemTemplate;
- (void)onItemTemplateSelectorChanged:(WXCDataTemplateSelector*)oldItemTemplateSelector newItemTemplateSelector:(WXCDataTemplateSelector*)newItemTemplateSelector;
- (void)onGroupStyleSelectorChanged:(WXCGroupStyleSelector*)oldGroupStyleSelector newGroupStyleSelector:(WXCGroupStyleSelector*)newGroupStyleSelector;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIItemsControlOverrides : RTObject <WXCIItemsControlOverrides>
@end

#endif // __WXCIItemsControlOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IToggleSwitchOverrides
#ifndef __WXCIToggleSwitchOverrides_DEFINED__
#define __WXCIToggleSwitchOverrides_DEFINED__

@protocol WXCIToggleSwitchOverrides
- (void)onToggled;
- (void)onOnContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onOffContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onHeaderChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIToggleSwitchOverrides : RTObject <WXCIToggleSwitchOverrides>
@end

#endif // __WXCIToggleSwitchOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IVirtualizingPanelOverrides
#ifndef __WXCIVirtualizingPanelOverrides_DEFINED__
#define __WXCIVirtualizingPanelOverrides_DEFINED__

@protocol WXCIVirtualizingPanelOverrides
- (void)onItemsChanged:(RTObject*)sender args:(WUXCPItemsChangedEventArgs*)args;
- (void)onClearChildren;
- (void)bringIndexIntoView:(int)index;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIVirtualizingPanelOverrides : RTObject <WXCIVirtualizingPanelOverrides>
@end

#endif // __WXCIVirtualizingPanelOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IComboBoxOverrides
#ifndef __WXCIComboBoxOverrides_DEFINED__
#define __WXCIComboBoxOverrides_DEFINED__

@protocol WXCIComboBoxOverrides
- (void)onDropDownClosed:(RTObject*)e;
- (void)onDropDownOpened:(RTObject*)e;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIComboBoxOverrides : RTObject <WXCIComboBoxOverrides>
@end

#endif // __WXCIComboBoxOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IVirtualizingStackPanelOverrides
#ifndef __WXCIVirtualizingStackPanelOverrides_DEFINED__
#define __WXCIVirtualizingStackPanelOverrides_DEFINED__

@protocol WXCIVirtualizingStackPanelOverrides
- (void)onCleanUpVirtualizedItem:(WXCCleanUpVirtualizedItemEventArgs*)e;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIVirtualizingStackPanelOverrides : RTObject <WXCIVirtualizingStackPanelOverrides>
@end

#endif // __WXCIVirtualizingStackPanelOverrides_DEFINED__

// Windows.UI.Xaml.Controls.ICommandBarElement
#ifndef __WXCICommandBarElement_DEFINED__
#define __WXCICommandBarElement_DEFINED__

@protocol WXCICommandBarElement
@property BOOL isCompact;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCICommandBarElement : RTObject <WXCICommandBarElement>
@end

#endif // __WXCICommandBarElement_DEFINED__

// Windows.UI.Xaml.Controls.ICommandBarElement2
#ifndef __WXCICommandBarElement2_DEFINED__
#define __WXCICommandBarElement2_DEFINED__

@protocol WXCICommandBarElement2
@property int dynamicOverflowOrder;
@property (readonly) BOOL isInOverflow;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCICommandBarElement2 : RTObject <WXCICommandBarElement2>
@end

#endif // __WXCICommandBarElement2_DEFINED__

// Windows.UI.Xaml.Controls.IAppBarOverrides
#ifndef __WXCIAppBarOverrides_DEFINED__
#define __WXCIAppBarOverrides_DEFINED__

@protocol WXCIAppBarOverrides
- (void)onClosed:(RTObject*)e;
- (void)onOpened:(RTObject*)e;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIAppBarOverrides : RTObject <WXCIAppBarOverrides>
@end

#endif // __WXCIAppBarOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IAppBarOverrides3
#ifndef __WXCIAppBarOverrides3_DEFINED__
#define __WXCIAppBarOverrides3_DEFINED__

@protocol WXCIAppBarOverrides3
- (void)onClosing:(RTObject*)e;
- (void)onOpening:(RTObject*)e;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIAppBarOverrides3 : RTObject <WXCIAppBarOverrides3>
@end

#endif // __WXCIAppBarOverrides3_DEFINED__

// Windows.UI.Xaml.Controls.IPageOverrides
#ifndef __WXCIPageOverrides_DEFINED__
#define __WXCIPageOverrides_DEFINED__

@protocol WXCIPageOverrides
- (void)onNavigatedFrom:(WUXNNavigationEventArgs*)e;
- (void)onNavigatedTo:(WUXNNavigationEventArgs*)e;
- (void)onNavigatingFrom:(WUXNNavigatingCancelEventArgs*)e;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIPageOverrides : RTObject <WXCIPageOverrides>
@end

#endif // __WXCIPageOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IControlOverrides
#ifndef __WXCIControlOverrides_DEFINED__
#define __WXCIControlOverrides_DEFINED__

@protocol WXCIControlOverrides
- (void)onPointerEntered:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerPressed:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerMoved:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerReleased:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerExited:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCaptureLost:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCanceled:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerWheelChanged:(WUXIPointerRoutedEventArgs*)e;
- (void)onTapped:(WUXITappedRoutedEventArgs*)e;
- (void)onDoubleTapped:(WUXIDoubleTappedRoutedEventArgs*)e;
- (void)onHolding:(WUXIHoldingRoutedEventArgs*)e;
- (void)onRightTapped:(WUXIRightTappedRoutedEventArgs*)e;
- (void)onManipulationStarting:(WUXIManipulationStartingRoutedEventArgs*)e;
- (void)onManipulationInertiaStarting:(WUXIManipulationInertiaStartingRoutedEventArgs*)e;
- (void)onManipulationStarted:(WUXIManipulationStartedRoutedEventArgs*)e;
- (void)onManipulationDelta:(WUXIManipulationDeltaRoutedEventArgs*)e;
- (void)onManipulationCompleted:(WUXIManipulationCompletedRoutedEventArgs*)e;
- (void)onKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onGotFocus:(WXRoutedEventArgs*)e;
- (void)onLostFocus:(WXRoutedEventArgs*)e;
- (void)onDragEnter:(WXDragEventArgs*)e;
- (void)onDragLeave:(WXDragEventArgs*)e;
- (void)onDragOver:(WXDragEventArgs*)e;
- (void)onDrop:(WXDragEventArgs*)e;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIControlOverrides : RTObject <WXCIControlOverrides>
@end

#endif // __WXCIControlOverrides_DEFINED__

// Windows.UI.Xaml.Controls.IControlOverrides6
#ifndef __WXCIControlOverrides6_DEFINED__
#define __WXCIControlOverrides6_DEFINED__

@protocol WXCIControlOverrides6
- (void)onPreviewKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onPreviewKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onCharacterReceived:(WUXICharacterReceivedRoutedEventArgs*)e;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIControlOverrides6 : RTObject <WXCIControlOverrides6>
@end

#endif // __WXCIControlOverrides6_DEFINED__

// Windows.UI.Xaml.Controls.IInkToolbarCustomPenOverrides
#ifndef __WXCIInkToolbarCustomPenOverrides_DEFINED__
#define __WXCIInkToolbarCustomPenOverrides_DEFINED__

@protocol WXCIInkToolbarCustomPenOverrides
- (WUIIInkDrawingAttributes*)createInkDrawingAttributesCore:(WUXMBrush*)brush strokeWidth:(double)strokeWidth;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIInkToolbarCustomPenOverrides : RTObject <WXCIInkToolbarCustomPenOverrides>
@end

#endif // __WXCIInkToolbarCustomPenOverrides_DEFINED__

// Windows.UI.Xaml.Controls.ColorChangedEventArgs
#ifndef __WXCColorChangedEventArgs_DEFINED__
#define __WXCColorChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCColorChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUColor* newColor __attribute__ ((ns_returns_not_retained));
@property (readonly) WUColor* oldColor;
@end

#endif // __WXCColorChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewDisplayModeChangedEventArgs
#ifndef __WXCNavigationViewDisplayModeChangedEventArgs_DEFINED__
#define __WXCNavigationViewDisplayModeChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewDisplayModeChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCNavigationViewDisplayMode displayMode;
@end

#endif // __WXCNavigationViewDisplayModeChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewSelectionChangedEventArgs
#ifndef __WXCNavigationViewSelectionChangedEventArgs_DEFINED__
#define __WXCNavigationViewSelectionChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewSelectionChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isSettingsSelected;
@property (readonly) RTObject* selectedItem;
@end

#endif // __WXCNavigationViewSelectionChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewItemInvokedEventArgs
#ifndef __WXCNavigationViewItemInvokedEventArgs_DEFINED__
#define __WXCNavigationViewItemInvokedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewItemInvokedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* invokedItem;
@property (readonly) BOOL isSettingsInvoked;
@end

#endif // __WXCNavigationViewItemInvokedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SwipeItemInvokedEventArgs
#ifndef __WXCSwipeItemInvokedEventArgs_DEFINED__
#define __WXCSwipeItemInvokedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSwipeItemInvokedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCSwipeControl* swipeControl;
@end

#endif // __WXCSwipeItemInvokedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.BackClickEventArgs
#ifndef __WXCBackClickEventArgs_DEFINED__
#define __WXCBackClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCBackClickEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WXCBackClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.DragItemsStartingEventArgs
#ifndef __WXCDragItemsStartingEventArgs_DEFINED__
#define __WXCDragItemsStartingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDragItemsStartingEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
@property (readonly) WADDataPackage* data;
@property (readonly) NSMutableArray* /* RTObject* */ items;
@end

#endif // __WXCDragItemsStartingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.NotifyEventArgs
#ifndef __WXCNotifyEventArgs_DEFINED__
#define __WXCNotifyEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNotifyEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * value;
@property (readonly) WFUri* callingUri;
@end

#endif // __WXCNotifyEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SemanticZoomViewChangedEventArgs
#ifndef __WXCSemanticZoomViewChangedEventArgs_DEFINED__
#define __WXCSemanticZoomViewChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSemanticZoomViewChangedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCSemanticZoomLocation* sourceItem;
@property BOOL isSourceZoomedInView;
@property (retain) WXCSemanticZoomLocation* destinationItem;
@end

#endif // __WXCSemanticZoomViewChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextControlPasteEventArgs
#ifndef __WXCTextControlPasteEventArgs_DEFINED__
#define __WXCTextControlPasteEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextControlPasteEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WXCTextControlPasteEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ContainerContentChangingEventArgs
#ifndef __WXCContainerContentChangingEventArgs_DEFINED__
#define __WXCContainerContentChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContainerContentChangingEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) BOOL inRecycleQueue;
@property (readonly) RTObject* item;
@property (readonly) WUXCPSelectorItem* itemContainer;
@property (readonly) int itemIndex;
@property (readonly) unsigned int phase;
- (void)registerUpdateCallback:(void(^)(WXCListViewBase*, WXCContainerContentChangingEventArgs*))callback;
- (void)registerUpdateCallbackWithPhase:(unsigned int)callbackPhase callback:(void(^)(WXCListViewBase*, WXCContainerContentChangingEventArgs*))callback;
@end

#endif // __WXCContainerContentChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SemanticZoomLocation
#ifndef __WXCSemanticZoomLocation_DEFINED__
#define __WXCSemanticZoomLocation_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSemanticZoomLocation : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* item;
@property (retain) WFRect* bounds;
@end

#endif // __WXCSemanticZoomLocation_DEFINED__

// Windows.UI.Xaml.Controls.CandidateWindowBoundsChangedEventArgs
#ifndef __WXCCandidateWindowBoundsChangedEventArgs_DEFINED__
#define __WXCCandidateWindowBoundsChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCandidateWindowBoundsChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFRect* bounds;
@end

#endif // __WXCCandidateWindowBoundsChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ChoosingGroupHeaderContainerEventArgs
#ifndef __WXCChoosingGroupHeaderContainerEventArgs_DEFINED__
#define __WXCChoosingGroupHeaderContainerEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCChoosingGroupHeaderContainerEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCListViewBaseHeaderItem* groupHeaderContainer;
@property (readonly) RTObject* group;
@property (readonly) int groupIndex;
@end

#endif // __WXCChoosingGroupHeaderContainerEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ChoosingItemContainerEventArgs
#ifndef __WXCChoosingItemContainerEventArgs_DEFINED__
#define __WXCChoosingItemContainerEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCChoosingItemContainerEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXCPSelectorItem* itemContainer;
@property BOOL isContainerPrepared;
@property (readonly) RTObject* item;
@property (readonly) int itemIndex;
@end

#endif // __WXCChoosingItemContainerEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ColumnDefinitionCollection
#ifndef __WXCColumnDefinitionCollection_DEFINED__
#define __WXCColumnDefinitionCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCColumnDefinitionCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WXCColumnDefinitionCollection_DEFINED__

// Windows.UI.Xaml.Controls.DataTemplateSelector
#ifndef __WXCDataTemplateSelector_DEFINED__
#define __WXCDataTemplateSelector_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDataTemplateSelector : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WXDataTemplate*)selectTemplate:(RTObject*)item container:(WXDependencyObject*)container;
- (WXDataTemplate*)selectTemplateCore:(RTObject*)item container:(WXDependencyObject*)container;
- (WXDataTemplate*)selectTemplateForItem:(RTObject*)item;
- (WXDataTemplate*)selectTemplateForItemCore:(RTObject*)item;
@end

#endif // __WXCDataTemplateSelector_DEFINED__

// Windows.UI.Xaml.Controls.DragItemsCompletedEventArgs
#ifndef __WXCDragItemsCompletedEventArgs_DEFINED__
#define __WXCDragItemsCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDragItemsCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WADDataPackageOperation dropResult;
@property (readonly) NSArray* /* RTObject* */ items;
@end

#endif // __WXCDragItemsCompletedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.StyleSelector
#ifndef __WXCStyleSelector_DEFINED__
#define __WXCStyleSelector_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCStyleSelector : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WXStyle*)selectStyle:(RTObject*)item container:(WXDependencyObject*)container;
- (WXStyle*)selectStyleCore:(RTObject*)item container:(WXDependencyObject*)container;
@end

#endif // __WXCStyleSelector_DEFINED__

// Windows.UI.Xaml.Data.INotifyPropertyChanged
#ifndef __WUXDINotifyPropertyChanged_DEFINED__
#define __WUXDINotifyPropertyChanged_DEFINED__

@protocol WUXDINotifyPropertyChanged
- (EventRegistrationToken)addPropertyChangedEvent:(WUXDPropertyChangedEventHandler)del;
- (void)removePropertyChangedEvent:(EventRegistrationToken)tok;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDINotifyPropertyChanged : RTObject <WUXDINotifyPropertyChanged>
@end

#endif // __WUXDINotifyPropertyChanged_DEFINED__

// Windows.UI.Xaml.Controls.GroupStyle
#ifndef __WXCGroupStyle_DEFINED__
#define __WXCGroupStyle_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCGroupStyle : RTObject <WUXDINotifyPropertyChanged>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCItemsPanelTemplate* panel;
@property BOOL hidesIfEmpty;
@property (retain) WXCDataTemplateSelector* headerTemplateSelector;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) WXCStyleSelector* containerStyleSelector;
@property (retain) WXStyle* containerStyle;
@property (retain) WXStyle* headerContainerStyle;
- (EventRegistrationToken)addPropertyChangedEvent:(WUXDPropertyChangedEventHandler)del;
- (void)removePropertyChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCGroupStyle_DEFINED__

// Windows.UI.Xaml.Controls.GroupStyleSelector
#ifndef __WXCGroupStyleSelector_DEFINED__
#define __WXCGroupStyleSelector_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCGroupStyleSelector : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WXCGroupStyle*)selectGroupStyle:(RTObject*)group level:(unsigned int)level;
- (WXCGroupStyle*)selectGroupStyleCore:(RTObject*)group level:(unsigned int)level;
@end

#endif // __WXCGroupStyleSelector_DEFINED__

// Windows.UI.Xaml.Controls.IsTextTrimmedChangedEventArgs
#ifndef __WXCIsTextTrimmedChangedEventArgs_DEFINED__
#define __WXCIsTextTrimmedChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIsTextTrimmedChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCIsTextTrimmedChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ItemCollection
#ifndef __WXCItemCollection_DEFINED__
#define __WXCItemCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
// Could not generate add_VectorChanged (Can't marshal Windows.Foundation.Collections.VectorChangedEventHandler`1<System.Object>)
- (void)removeVectorChangedEvent:(EventRegistrationToken)tok;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

- (EventRegistrationToken)addObserver: (RTCollectionListener)receiver;
- (void)removeObserver: (EventRegistrationToken)receiverToken;
@end

#endif // __WXCItemCollection_DEFINED__

// Windows.UI.Xaml.Controls.ItemContainerGenerator
#ifndef __WXCItemContainerGenerator_DEFINED__
#define __WXCItemContainerGenerator_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemContainerGenerator : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (EventRegistrationToken)addItemsChangedEvent:(WUXCPItemsChangedEventHandler)del;
- (void)removeItemsChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)itemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromItem:(RTObject*)item;
- (int)indexFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromIndex:(int)index;
- (WXCItemContainerGenerator*)getItemContainerGeneratorForPanel:(WXCPanel*)panel;
- (void)startAt:(WUXCPGeneratorPosition*)position direction:(WUXCPGeneratorDirection)direction allowStartAtRealizedItem:(BOOL)allowStartAtRealizedItem;
- (void)stop;
- (WXDependencyObject*)generateNext:(BOOL*)isNewlyRealized;
- (void)prepareItemContainer:(WXDependencyObject*)container;
- (void)removeAll;
- (void)remove:(WUXCPGeneratorPosition*)position count:(int)count;
- (WUXCPGeneratorPosition*)generatorPositionFromIndex:(int)itemIndex;
- (int)indexFromGeneratorPosition:(WUXCPGeneratorPosition*)position;
- (void)recycle:(WUXCPGeneratorPosition*)position count:(int)count;
@end

#endif // __WXCItemContainerGenerator_DEFINED__

// Windows.UI.Xaml.Controls.MediaTransportControlsHelper
#ifndef __WXCMediaTransportControlsHelper_DEFINED__
#define __WXCMediaTransportControlsHelper_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMediaTransportControlsHelper : RTObject
+ (id /* int */)getDropoutOrder:(WXUIElement*)element;
+ (void)setDropoutOrder:(WXUIElement*)element value:(id /* int */)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WXDependencyProperty*)dropoutOrderProperty;
@end

#endif // __WXCMediaTransportControlsHelper_DEFINED__

// Windows.UI.Xaml.Controls.PasswordBoxPasswordChangingEventArgs
#ifndef __WXCPasswordBoxPasswordChangingEventArgs_DEFINED__
#define __WXCPasswordBoxPasswordChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPasswordBoxPasswordChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isContentChanging;
@end

#endif // __WXCPasswordBoxPasswordChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.RowDefinitionCollection
#ifndef __WXCRowDefinitionCollection_DEFINED__
#define __WXCRowDefinitionCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRowDefinitionCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WXCRowDefinitionCollection_DEFINED__

// Windows.UI.Xaml.Controls.TextBoxBeforeTextChangingEventArgs
#ifndef __WXCTextBoxBeforeTextChangingEventArgs_DEFINED__
#define __WXCTextBoxBeforeTextChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextBoxBeforeTextChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
@property (readonly) NSString * newText __attribute__ ((ns_returns_not_retained));
@end

#endif // __WXCTextBoxBeforeTextChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextBoxTextChangingEventArgs
#ifndef __WXCTextBoxTextChangingEventArgs_DEFINED__
#define __WXCTextBoxTextChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextBoxTextChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isContentChanging;
@end

#endif // __WXCTextBoxTextChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextCompositionChangedEventArgs
#ifndef __WXCTextCompositionChangedEventArgs_DEFINED__
#define __WXCTextCompositionChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextCompositionChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int length;
@property (readonly) int startIndex;
@end

#endif // __WXCTextCompositionChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextCompositionEndedEventArgs
#ifndef __WXCTextCompositionEndedEventArgs_DEFINED__
#define __WXCTextCompositionEndedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextCompositionEndedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int length;
@property (readonly) int startIndex;
@end

#endif // __WXCTextCompositionEndedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextCompositionStartedEventArgs
#ifndef __WXCTextCompositionStartedEventArgs_DEFINED__
#define __WXCTextCompositionStartedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextCompositionStartedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) int length;
@property (readonly) int startIndex;
@end

#endif // __WXCTextCompositionStartedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextControlCopyingToClipboardEventArgs
#ifndef __WXCTextControlCopyingToClipboardEventArgs_DEFINED__
#define __WXCTextControlCopyingToClipboardEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextControlCopyingToClipboardEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WXCTextControlCopyingToClipboardEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextControlCuttingToClipboardEventArgs
#ifndef __WXCTextControlCuttingToClipboardEventArgs_DEFINED__
#define __WXCTextControlCuttingToClipboardEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextControlCuttingToClipboardEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WXCTextControlCuttingToClipboardEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ToolTipService
#ifndef __WXCToolTipService_DEFINED__
#define __WXCToolTipService_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCToolTipService : RTObject
+ (WUXCPPlacementMode)getPlacement:(WXDependencyObject*)element;
+ (void)setPlacement:(WXDependencyObject*)element value:(WUXCPPlacementMode)value;
+ (WXUIElement*)getPlacementTarget:(WXDependencyObject*)element;
+ (void)setPlacementTarget:(WXDependencyObject*)element value:(WXUIElement*)value;
+ (RTObject*)getToolTip:(WXDependencyObject*)element;
+ (void)setToolTip:(WXDependencyObject*)element value:(RTObject*)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WXDependencyProperty*)placementProperty;
+ (WXDependencyProperty*)placementTargetProperty;
+ (WXDependencyProperty*)toolTipProperty;
@end

#endif // __WXCToolTipService_DEFINED__

// Windows.UI.Xaml.Controls.UIElementCollection
#ifndef __WXCUIElementCollection_DEFINED__
#define __WXCUIElementCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCUIElementCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

- (void)move:(unsigned int)oldIndex newIndex:(unsigned int)newIndex;
@end

#endif // __WXCUIElementCollection_DEFINED__

// Windows.UI.Xaml.Controls.CalendarViewDayItemChangingEventArgs
#ifndef __WXCCalendarViewDayItemChangingEventArgs_DEFINED__
#define __WXCCalendarViewDayItemChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCalendarViewDayItemChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL inRecycleQueue;
@property (readonly) WXCCalendarViewDayItem* item;
@property (readonly) unsigned int phase;
- (void)registerUpdateCallback:(void(^)(WXCCalendarView*, WXCCalendarViewDayItemChangingEventArgs*))callback;
- (void)registerUpdateCallbackWithPhase:(unsigned int)callbackPhase callback:(void(^)(WXCCalendarView*, WXCCalendarViewDayItemChangingEventArgs*))callback;
@end

#endif // __WXCCalendarViewDayItemChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.HubSectionHeaderClickEventArgs
#ifndef __WXCHubSectionHeaderClickEventArgs_DEFINED__
#define __WXCHubSectionHeaderClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCHubSectionHeaderClickEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCHubSection* section;
@end

#endif // __WXCHubSectionHeaderClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SectionsInViewChangedEventArgs
#ifndef __WXCSectionsInViewChangedEventArgs_DEFINED__
#define __WXCSectionsInViewChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSectionsInViewChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* WXCHubSection* */ addedSections;
@property (readonly) NSMutableArray* /* WXCHubSection* */ removedSections;
@end

#endif // __WXCSectionsInViewChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewNavigationFailedEventArgs
#ifndef __WXCWebViewNavigationFailedEventArgs_DEFINED__
#define __WXCWebViewNavigationFailedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewNavigationFailedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFUri* uri;
@property (readonly) WWWebErrorStatus webErrorStatus;
@end

#endif // __WXCWebViewNavigationFailedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.CalendarDatePickerDateChangedEventArgs
#ifndef __WXCCalendarDatePickerDateChangedEventArgs_DEFINED__
#define __WXCCalendarDatePickerDateChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCalendarDatePickerDateChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) id /* WFDateTime* */ newDate __attribute__ ((ns_returns_not_retained));
@property (readonly) id /* WFDateTime* */ oldDate;
@end

#endif // __WXCCalendarDatePickerDateChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.CalendarViewSelectedDatesChangedEventArgs
#ifndef __WXCCalendarViewSelectedDatesChangedEventArgs_DEFINED__
#define __WXCCalendarViewSelectedDatesChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCalendarViewSelectedDatesChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* WFDateTime* */ addedDates;
@property (readonly) NSArray* /* WFDateTime* */ removedDates;
@end

#endif // __WXCCalendarViewSelectedDatesChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ContentDialogButtonClickDeferral
#ifndef __WXCContentDialogButtonClickDeferral_DEFINED__
#define __WXCContentDialogButtonClickDeferral_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentDialogButtonClickDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WXCContentDialogButtonClickDeferral_DEFINED__

// Windows.UI.Xaml.Controls.ContentDialogButtonClickEventArgs
#ifndef __WXCContentDialogButtonClickEventArgs_DEFINED__
#define __WXCContentDialogButtonClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentDialogButtonClickEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
- (WXCContentDialogButtonClickDeferral*)getDeferral;
@end

#endif // __WXCContentDialogButtonClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ContentDialogClosedEventArgs
#ifndef __WXCContentDialogClosedEventArgs_DEFINED__
#define __WXCContentDialogClosedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentDialogClosedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCContentDialogResult result;
@end

#endif // __WXCContentDialogClosedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ContentDialogClosingDeferral
#ifndef __WXCContentDialogClosingDeferral_DEFINED__
#define __WXCContentDialogClosingDeferral_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentDialogClosingDeferral : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (void)complete;
@end

#endif // __WXCContentDialogClosingDeferral_DEFINED__

// Windows.UI.Xaml.Controls.ContentDialogClosingEventArgs
#ifndef __WXCContentDialogClosingEventArgs_DEFINED__
#define __WXCContentDialogClosingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentDialogClosingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
@property (readonly) WXCContentDialogResult result;
- (WXCContentDialogClosingDeferral*)getDeferral;
@end

#endif // __WXCContentDialogClosingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ContentDialogOpenedEventArgs
#ifndef __WXCContentDialogOpenedEventArgs_DEFINED__
#define __WXCContentDialogOpenedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentDialogOpenedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCContentDialogOpenedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.DatePickerValueChangedEventArgs
#ifndef __WXCDatePickerValueChangedEventArgs_DEFINED__
#define __WXCDatePickerValueChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDatePickerValueChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* newDate __attribute__ ((ns_returns_not_retained));
@property (readonly) WFDateTime* oldDate;
@end

#endif // __WXCDatePickerValueChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.DynamicOverflowItemsChangingEventArgs
#ifndef __WXCDynamicOverflowItemsChangingEventArgs_DEFINED__
#define __WXCDynamicOverflowItemsChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDynamicOverflowItemsChangingEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCCommandBarDynamicOverflowAction action;
@end

#endif // __WXCDynamicOverflowItemsChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.HubSectionCollection
#ifndef __WXCHubSectionCollection_DEFINED__
#define __WXCHubSectionCollection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCHubSectionCollection : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WXCHubSectionCollection_DEFINED__

// Windows.UI.Xaml.Controls.ListViewPersistenceHelper
#ifndef __WXCListViewPersistenceHelper_DEFINED__
#define __WXCListViewPersistenceHelper_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListViewPersistenceHelper : RTObject
+ (NSString *)getRelativeScrollPosition:(WXCListViewBase*)listViewBase itemToKeyHandler:(WXCListViewItemToKeyHandler)itemToKeyHandler;
// Failed to generate member SetRelativeScrollPositionAsync (Can't marshal Windows.Foundation.IAsyncOperation`1<System.Object>)
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCListViewPersistenceHelper_DEFINED__

// Windows.UI.Xaml.Controls.RichEditBoxTextChangingEventArgs
#ifndef __WXCRichEditBoxTextChangingEventArgs_DEFINED__
#define __WXCRichEditBoxTextChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRichEditBoxTextChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isContentChanging;
@end

#endif // __WXCRichEditBoxTextChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewerView
#ifndef __WXCScrollViewerView_DEFINED__
#define __WXCScrollViewerView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCScrollViewerView : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) double horizontalOffset;
@property (readonly) double verticalOffset;
@property (readonly) float zoomFactor;
@end

#endif // __WXCScrollViewerView_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewerViewChangedEventArgs
#ifndef __WXCScrollViewerViewChangedEventArgs_DEFINED__
#define __WXCScrollViewerViewChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCScrollViewerViewChangedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isIntermediate;
@end

#endif // __WXCScrollViewerViewChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewerViewChangingEventArgs
#ifndef __WXCScrollViewerViewChangingEventArgs_DEFINED__
#define __WXCScrollViewerViewChangingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCScrollViewerViewChangingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCScrollViewerView* finalView;
@property (readonly) BOOL isInertial;
@property (readonly) WXCScrollViewerView* nextView;
@end

#endif // __WXCScrollViewerViewChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxQueryChangedEventArgs
#ifndef __WXCSearchBoxQueryChangedEventArgs_DEFINED__
#define __WXCSearchBoxQueryChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSearchBoxQueryChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString * queryText;
@end

#endif // __WXCSearchBoxQueryChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxQuerySubmittedEventArgs
#ifndef __WXCSearchBoxQuerySubmittedEventArgs_DEFINED__
#define __WXCSearchBoxQuerySubmittedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSearchBoxQuerySubmittedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSVirtualKeyModifiers keyModifiers;
@property (readonly) NSString * language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString * queryText;
@end

#endif // __WXCSearchBoxQuerySubmittedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxResultSuggestionChosenEventArgs
#ifndef __WXCSearchBoxResultSuggestionChosenEventArgs_DEFINED__
#define __WXCSearchBoxResultSuggestionChosenEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSearchBoxResultSuggestionChosenEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WSVirtualKeyModifiers keyModifiers;
@property (readonly) NSString * tag;
@end

#endif // __WXCSearchBoxResultSuggestionChosenEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxSuggestionsRequestedEventArgs
#ifndef __WXCSearchBoxSuggestionsRequestedEventArgs_DEFINED__
#define __WXCSearchBoxSuggestionsRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSearchBoxSuggestionsRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString * queryText;
@property (readonly) WASSearchSuggestionsRequest* request;
@end

#endif // __WXCSearchBoxSuggestionsRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SplitViewPaneClosingEventArgs
#ifndef __WXCSplitViewPaneClosingEventArgs_DEFINED__
#define __WXCSplitViewPaneClosingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSplitViewPaneClosingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
@end

#endif // __WXCSplitViewPaneClosingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TimePickerValueChangedEventArgs
#ifndef __WXCTimePickerValueChangedEventArgs_DEFINED__
#define __WXCTimePickerValueChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTimePickerValueChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* newTime __attribute__ ((ns_returns_not_retained));
@property (readonly) WFTimeSpan* oldTime;
@end

#endif // __WXCTimePickerValueChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewContentLoadingEventArgs
#ifndef __WXCWebViewContentLoadingEventArgs_DEFINED__
#define __WXCWebViewContentLoadingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewContentLoadingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewContentLoadingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewDeferredPermissionRequest
#ifndef __WXCWebViewDeferredPermissionRequest_DEFINED__
#define __WXCWebViewDeferredPermissionRequest_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewDeferredPermissionRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int id;
@property (readonly) WXCWebViewPermissionType permissionType;
@property (readonly) WFUri* uri;
- (void)allow;
- (void)deny;
@end

#endif // __WXCWebViewDeferredPermissionRequest_DEFINED__

// Windows.UI.Xaml.Controls.WebViewDOMContentLoadedEventArgs
#ifndef __WXCWebViewDOMContentLoadedEventArgs_DEFINED__
#define __WXCWebViewDOMContentLoadedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewDOMContentLoadedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewDOMContentLoadedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewLongRunningScriptDetectedEventArgs
#ifndef __WXCWebViewLongRunningScriptDetectedEventArgs_DEFINED__
#define __WXCWebViewLongRunningScriptDetectedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewLongRunningScriptDetectedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL stopPageScriptExecution;
@property (readonly) WFTimeSpan* executionTime;
@end

#endif // __WXCWebViewLongRunningScriptDetectedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewNavigationCompletedEventArgs
#ifndef __WXCWebViewNavigationCompletedEventArgs_DEFINED__
#define __WXCWebViewNavigationCompletedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewNavigationCompletedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) BOOL isSuccess;
@property (readonly) WFUri* uri;
@property (readonly) WWWebErrorStatus webErrorStatus;
@end

#endif // __WXCWebViewNavigationCompletedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewNavigationStartingEventArgs
#ifndef __WXCWebViewNavigationStartingEventArgs_DEFINED__
#define __WXCWebViewNavigationStartingEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewNavigationStartingEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewNavigationStartingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewNewWindowRequestedEventArgs
#ifndef __WXCWebViewNewWindowRequestedEventArgs_DEFINED__
#define __WXCWebViewNewWindowRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewNewWindowRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WFUri* referrer;
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewNewWindowRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewPermissionRequest
#ifndef __WXCWebViewPermissionRequest_DEFINED__
#define __WXCWebViewPermissionRequest_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewPermissionRequest : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int id;
@property (readonly) WXCWebViewPermissionType permissionType;
@property (readonly) WXCWebViewPermissionState state;
@property (readonly) WFUri* uri;
- (void)defer;
- (void)allow;
- (void)deny;
@end

#endif // __WXCWebViewPermissionRequest_DEFINED__

// Windows.UI.Xaml.Controls.WebViewPermissionRequestedEventArgs
#ifndef __WXCWebViewPermissionRequestedEventArgs_DEFINED__
#define __WXCWebViewPermissionRequestedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewPermissionRequestedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCWebViewPermissionRequest* permissionRequest;
@end

#endif // __WXCWebViewPermissionRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewSettings
#ifndef __WXCWebViewSettings_DEFINED__
#define __WXCWebViewSettings_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewSettings : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isJavaScriptEnabled;
@property BOOL isIndexedDBEnabled;
@end

#endif // __WXCWebViewSettings_DEFINED__

// Windows.UI.Xaml.Controls.WebViewUnsupportedUriSchemeIdentifiedEventArgs
#ifndef __WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs_DEFINED__
#define __WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewUnviewableContentIdentifiedEventArgs
#ifndef __WXCWebViewUnviewableContentIdentifiedEventArgs_DEFINED__
#define __WXCWebViewUnviewableContentIdentifiedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewUnviewableContentIdentifiedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFUri* referrer;
@property (readonly) WFUri* uri;
@property (readonly) NSString * mediaType;
@end

#endif // __WXCWebViewUnviewableContentIdentifiedEventArgs_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXDependencyObject : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUCCoreDispatcher* dispatcher;
- (RTObject*)getValue:(WXDependencyProperty*)dp;
- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value;
- (void)clearValue:(WXDependencyProperty*)dp;
- (RTObject*)readLocalValue:(WXDependencyProperty*)dp;
- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp;
- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback;
- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Controls.IconSource
#ifndef __WXCIconSource_DEFINED__
#define __WXCIconSource_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIconSource : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMBrush* foreground;
+ (WXDependencyProperty*)foregroundProperty;
@end

#endif // __WXCIconSource_DEFINED__

// Windows.UI.Xaml.Controls.SymbolIconSource
#ifndef __WXCSymbolIconSource_DEFINED__
#define __WXCSymbolIconSource_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSymbolIconSource : WXCIconSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCSymbol symbol;
+ (WXDependencyProperty*)symbolProperty;
@end

#endif // __WXCSymbolIconSource_DEFINED__

// Windows.UI.Xaml.Controls.FontIconSource
#ifndef __WXCFontIconSource_DEFINED__
#define __WXCFontIconSource_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFontIconSource : WXCIconSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL mirroredWhenRightToLeft;
@property BOOL isTextScaleFactorEnabled;
@property (retain) NSString * glyph;
@property (retain) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property double fontSize;
@property (retain) WUXMFontFamily* fontFamily;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)glyphProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)mirroredWhenRightToLeftProperty;
@end

#endif // __WXCFontIconSource_DEFINED__

// Windows.UI.Xaml.Controls.BitmapIconSource
#ifndef __WXCBitmapIconSource_DEFINED__
#define __WXCBitmapIconSource_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCBitmapIconSource : WXCIconSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* uriSource;
@property BOOL showAsMonochrome;
+ (WXDependencyProperty*)showAsMonochromeProperty;
+ (WXDependencyProperty*)uriSourceProperty;
@end

#endif // __WXCBitmapIconSource_DEFINED__

// Windows.UI.Xaml.Controls.PathIconSource
#ifndef __WXCPathIconSource_DEFINED__
#define __WXCPathIconSource_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPathIconSource : WXCIconSource
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMGeometry* data;
+ (WXDependencyProperty*)dataProperty;
@end

#endif // __WXCPathIconSource_DEFINED__

// Windows.UI.Xaml.Controls.RatingItemInfo
#ifndef __WXCRatingItemInfo_DEFINED__
#define __WXCRatingItemInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRatingItemInfo : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCRatingItemInfo_DEFINED__

// Windows.UI.Xaml.Controls.RatingItemFontInfo
#ifndef __WXCRatingItemFontInfo_DEFINED__
#define __WXCRatingItemFontInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRatingItemFontInfo : WXCRatingItemInfo
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * unsetGlyph;
@property (retain) NSString * pointerOverPlaceholderGlyph;
@property (retain) NSString * pointerOverGlyph;
@property (retain) NSString * placeholderGlyph;
@property (retain) NSString * glyph;
@property (retain) NSString * disabledGlyph;
+ (WXDependencyProperty*)disabledGlyphProperty;
+ (WXDependencyProperty*)glyphProperty;
+ (WXDependencyProperty*)placeholderGlyphProperty;
+ (WXDependencyProperty*)pointerOverGlyphProperty;
+ (WXDependencyProperty*)pointerOverPlaceholderGlyphProperty;
+ (WXDependencyProperty*)unsetGlyphProperty;
@end

#endif // __WXCRatingItemFontInfo_DEFINED__

// Windows.UI.Xaml.Controls.RatingItemImageInfo
#ifndef __WXCRatingItemImageInfo_DEFINED__
#define __WXCRatingItemImageInfo_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRatingItemImageInfo : WXCRatingItemInfo
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMImageSource* unsetImage;
@property (retain) WUXMImageSource* pointerOverPlaceholderImage;
@property (retain) WUXMImageSource* pointerOverImage;
@property (retain) WUXMImageSource* placeholderImage;
@property (retain) WUXMImageSource* image;
@property (retain) WUXMImageSource* disabledImage;
+ (WXDependencyProperty*)disabledImageProperty;
+ (WXDependencyProperty*)imageProperty;
+ (WXDependencyProperty*)placeholderImageProperty;
+ (WXDependencyProperty*)pointerOverImageProperty;
+ (WXDependencyProperty*)pointerOverPlaceholderImageProperty;
+ (WXDependencyProperty*)unsetImageProperty;
@end

#endif // __WXCRatingItemImageInfo_DEFINED__

// Windows.UI.Xaml.Controls.SwipeItem
#ifndef __WXCSwipeItem_DEFINED__
#define __WXCSwipeItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSwipeItem : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * text;
@property (retain) WXCIconSource* iconSource;
@property (retain) WUXMBrush* foreground;
@property (retain) RTObject* commandParameter;
@property (retain) RTObject<WUXIICommand>* command;
@property WXCSwipeBehaviorOnInvoked behaviorOnInvoked;
@property (retain) WUXMBrush* background;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)behaviorOnInvokedProperty;
+ (WXDependencyProperty*)commandParameterProperty;
+ (WXDependencyProperty*)commandProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)iconSourceProperty;
+ (WXDependencyProperty*)textProperty;
- (EventRegistrationToken)addInvokedEvent:(void(^)(WXCSwipeItem*, WXCSwipeItemInvokedEventArgs*))del;
- (void)removeInvokedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCSwipeItem_DEFINED__

// Windows.UI.Xaml.Controls.SwipeItems
#ifndef __WXCSwipeItems_DEFINED__
#define __WXCSwipeItems_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSwipeItems : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int size;
@property WXCSwipeMode mode;
+ (WXDependencyProperty*)modeProperty;
- (unsigned int)count;
- (id)objectAtIndex:(unsigned)idx;
- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
                                  objects:(id __unsafe_unretained [])buffer
                                    count:(NSUInteger)len;

- (void)insertObject: (id)obj atIndex: (NSUInteger)idx;
- (void)removeObjectAtIndex: (NSUInteger)idx;
- (void)replaceObjectAtIndex: (NSUInteger)idx withObject: (id)obj;
- (void)addObject: (id)obj;
- (void)removeLastObject;

@end

#endif // __WXCSwipeItems_DEFINED__

// Windows.UI.Xaml.Controls.ColumnDefinition
#ifndef __WXCColumnDefinition_DEFINED__
#define __WXCColumnDefinition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCColumnDefinition : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXGridLength* width;
@property double minWidth;
@property double maxWidth;
@property (readonly) double actualWidth;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)widthProperty;
@end

#endif // __WXCColumnDefinition_DEFINED__

// Windows.UI.Xaml.Controls.RowDefinition
#ifndef __WXCRowDefinition_DEFINED__
#define __WXCRowDefinition_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRowDefinition : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double minHeight;
@property double maxHeight;
@property (retain) WXGridLength* height;
@property (readonly) double actualHeight;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)minHeightProperty;
@end

#endif // __WXCRowDefinition_DEFINED__

// Windows.UI.Xaml.Controls.AutoSuggestBoxQuerySubmittedEventArgs
#ifndef __WXCAutoSuggestBoxQuerySubmittedEventArgs_DEFINED__
#define __WXCAutoSuggestBoxQuerySubmittedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAutoSuggestBoxQuerySubmittedEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* chosenSuggestion;
@property (readonly) NSString * queryText;
@end

#endif // __WXCAutoSuggestBoxQuerySubmittedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.AutoSuggestBoxSuggestionChosenEventArgs
#ifndef __WXCAutoSuggestBoxSuggestionChosenEventArgs_DEFINED__
#define __WXCAutoSuggestBoxSuggestionChosenEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAutoSuggestBoxSuggestionChosenEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* selectedItem;
@end

#endif // __WXCAutoSuggestBoxSuggestionChosenEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.AutoSuggestBoxTextChangedEventArgs
#ifndef __WXCAutoSuggestBoxTextChangedEventArgs_DEFINED__
#define __WXCAutoSuggestBoxTextChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAutoSuggestBoxTextChangedEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCAutoSuggestionBoxTextChangeReason reason;
+ (WXDependencyProperty*)reasonProperty;
- (BOOL)checkCurrent;
@end

#endif // __WXCAutoSuggestBoxTextChangedEventArgs_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.CleanUpVirtualizedItemEventArgs
#ifndef __WXCCleanUpVirtualizedItemEventArgs_DEFINED__
#define __WXCCleanUpVirtualizedItemEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCleanUpVirtualizedItemEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL cancel;
@property (readonly) WXUIElement* uIElement;
@property (readonly) RTObject* value;
@end

#endif // __WXCCleanUpVirtualizedItemEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ContextMenuEventArgs
#ifndef __WXCContextMenuEventArgs_DEFINED__
#define __WXCContextMenuEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContextMenuEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@property (readonly) double cursorLeft;
@property (readonly) double cursorTop;
@end

#endif // __WXCContextMenuEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ItemClickEventArgs
#ifndef __WXCItemClickEventArgs_DEFINED__
#define __WXCItemClickEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemClickEventArgs : WXRoutedEventArgs
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* clickedItem;
@end

#endif // __WXCItemClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SelectionChangedEventArgs
#ifndef __WXCSelectionChangedEventArgs_DEFINED__
#define __WXCSelectionChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSelectionChangedEventArgs : WXRoutedEventArgs
+ (WXCSelectionChangedEventArgs*)makeInstanceWithRemovedItemsAndAddedItems:(NSMutableArray* /* RTObject* */)removedItems addedItems:(NSMutableArray* /* RTObject* */)addedItems ACTIVATOR;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* RTObject* */ addedItems;
@property (readonly) NSMutableArray* /* RTObject* */ removedItems;
@end

#endif // __WXCSelectionChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextChangedEventArgs
#ifndef __WXCTextChangedEventArgs_DEFINED__
#define __WXCTextChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextChangedEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCTextChangedEventArgs_DEFINED__

// Windows.UI.Xaml.FrameworkTemplate
#ifndef __WXFrameworkTemplate_DEFINED__
#define __WXFrameworkTemplate_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXFrameworkTemplate : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXFrameworkTemplate_DEFINED__

// Windows.UI.Xaml.Controls.ItemsPanelTemplate
#ifndef __WXCItemsPanelTemplate_DEFINED__
#define __WXCItemsPanelTemplate_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemsPanelTemplate : WXFrameworkTemplate
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCItemsPanelTemplate_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides
#ifndef __WXIFrameworkElementOverrides_DEFINED__
#define __WXIFrameworkElementOverrides_DEFINED__

@protocol WXIFrameworkElementOverrides
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIFrameworkElementOverrides : RTObject <WXIFrameworkElementOverrides>
@end

#endif // __WXIFrameworkElementOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides2
#ifndef __WXIFrameworkElementOverrides2_DEFINED__
#define __WXIFrameworkElementOverrides2_DEFINED__

@protocol WXIFrameworkElementOverrides2
- (BOOL)goToElementStateCore:(NSString *)stateName useTransitions:(BOOL)useTransitions;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIFrameworkElementOverrides2 : RTObject <WXIFrameworkElementOverrides2>
@end

#endif // __WXIFrameworkElementOverrides2_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides
#ifndef __WXIUIElementOverrides_DEFINED__
#define __WXIUIElementOverrides_DEFINED__

@protocol WXIUIElementOverrides
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIUIElementOverrides : RTObject <WXIUIElementOverrides>
@end

#endif // __WXIUIElementOverrides_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides7
#ifndef __WXIUIElementOverrides7_DEFINED__
#define __WXIUIElementOverrides7_DEFINED__

@protocol WXIUIElementOverrides7
- (id<NSFastEnumeration> /* WXDependencyObject* */)getChildrenInTabFocusOrder;
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXIUIElementOverrides7 : RTObject <WXIUIElementOverrides7>
@end

#endif // __WXIUIElementOverrides7_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXUIElement : WXDependencyObject
+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isTapEnabled;
@property (retain) WUXMProjection* projection;
@property BOOL isRightTapEnabled;
@property BOOL isHoldingEnabled;
@property BOOL isHitTestVisible;
@property BOOL isDoubleTapEnabled;
@property BOOL allowDrop;
@property WUXIManipulationModes manipulationMode;
@property (retain) WUXMRectangleGeometry* clip;
@property (retain) WUXMCacheMode* cacheMode;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (retain) WUXMATransitionCollection* transitions;
@property (retain) WFPoint* renderTransformOrigin;
@property (retain) WUXMTransform* renderTransform;
@property double opacity;
@property (readonly) WFSize* desiredSize;
@property (readonly) NSArray* /* WUXIPointer* */ pointerCaptures;
@property (readonly) WFSize* renderSize;
@property WUXMElementCompositeMode compositeMode;
@property (retain) WUXMMTransform3D* transform3D;
@property BOOL canDrag;
@property BOOL isAccessKeyScope;
@property BOOL exitDisplayModeOnAccessKeyInvoked;
@property (retain) WUXCPFlyoutBase* contextFlyout;
@property (retain) WXDependencyObject* accessKeyScopeOwner;
@property (retain) NSString * accessKey;
@property double keyTipHorizontalOffset;
@property WXElementHighContrastAdjustment highContrastAdjustment;
@property WUXIXYFocusNavigationStrategy xYFocusUpNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusRightNavigationStrategy;
@property WUXIXYFocusNavigationStrategy xYFocusLeftNavigationStrategy;
@property WUXIXYFocusKeyboardNavigationMode xYFocusKeyboardNavigation;
@property WUXIXYFocusNavigationStrategy xYFocusDownNavigationStrategy;
@property WUXIKeyboardNavigationMode tabFocusNavigation;
@property double keyTipVerticalOffset;
@property WUXIKeyTipPlacementMode keyTipPlacementMode;
@property (readonly) NSMutableArray* /* WUXMXamlLight* */ lights;
@property (readonly) NSMutableArray* /* WUXIKeyboardAccelerator* */ keyboardAccelerators;
+ (WXDependencyProperty*)opacityProperty;
+ (WXDependencyProperty*)allowDropProperty;
+ (WXDependencyProperty*)cacheModeProperty;
+ (WXDependencyProperty*)clipProperty;
+ (WXRoutedEvent*)doubleTappedEvent;
+ (WXRoutedEvent*)dragEnterEvent;
+ (WXRoutedEvent*)dragLeaveEvent;
+ (WXRoutedEvent*)dragOverEvent;
+ (WXRoutedEvent*)dropEvent;
+ (WXRoutedEvent*)holdingEvent;
+ (WXDependencyProperty*)isDoubleTapEnabledProperty;
+ (WXDependencyProperty*)isHitTestVisibleProperty;
+ (WXDependencyProperty*)isHoldingEnabledProperty;
+ (WXDependencyProperty*)isRightTapEnabledProperty;
+ (WXDependencyProperty*)isTapEnabledProperty;
+ (WXRoutedEvent*)keyDownEvent;
+ (WXRoutedEvent*)keyUpEvent;
+ (WXRoutedEvent*)manipulationCompletedEvent;
+ (WXRoutedEvent*)manipulationDeltaEvent;
+ (WXRoutedEvent*)manipulationInertiaStartingEvent;
+ (WXDependencyProperty*)manipulationModeProperty;
+ (WXRoutedEvent*)manipulationStartedEvent;
+ (WXRoutedEvent*)manipulationStartingEvent;
+ (WXRoutedEvent*)pointerCanceledEvent;
+ (WXRoutedEvent*)pointerCaptureLostEvent;
+ (WXDependencyProperty*)pointerCapturesProperty;
+ (WXRoutedEvent*)pointerEnteredEvent;
+ (WXRoutedEvent*)pointerExitedEvent;
+ (WXRoutedEvent*)pointerMovedEvent;
+ (WXRoutedEvent*)pointerPressedEvent;
+ (WXRoutedEvent*)pointerReleasedEvent;
+ (WXRoutedEvent*)pointerWheelChangedEvent;
+ (WXDependencyProperty*)projectionProperty;
+ (WXDependencyProperty*)renderTransformOriginProperty;
+ (WXDependencyProperty*)renderTransformProperty;
+ (WXRoutedEvent*)rightTappedEvent;
+ (WXRoutedEvent*)tappedEvent;
+ (WXDependencyProperty*)transitionsProperty;
+ (WXDependencyProperty*)useLayoutRoundingProperty;
+ (WXDependencyProperty*)visibilityProperty;
+ (WXDependencyProperty*)compositeModeProperty;
+ (WXDependencyProperty*)transform3DProperty;
+ (WXDependencyProperty*)canDragProperty;
+ (WXDependencyProperty*)accessKeyProperty;
+ (WXDependencyProperty*)isAccessKeyScopeProperty;
+ (WXDependencyProperty*)exitDisplayModeOnAccessKeyInvokedProperty;
+ (WXDependencyProperty*)contextFlyoutProperty;
+ (WXDependencyProperty*)accessKeyScopeOwnerProperty;
+ (WXDependencyProperty*)xYFocusKeyboardNavigationProperty;
+ (WXDependencyProperty*)xYFocusLeftNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusRightNavigationStrategyProperty;
+ (WXDependencyProperty*)xYFocusUpNavigationStrategyProperty;
+ (WXDependencyProperty*)highContrastAdjustmentProperty;
+ (WXDependencyProperty*)xYFocusDownNavigationStrategyProperty;
+ (WXDependencyProperty*)keyTipHorizontalOffsetProperty;
+ (WXDependencyProperty*)keyTipPlacementModeProperty;
+ (WXDependencyProperty*)keyTipVerticalOffsetProperty;
+ (WXDependencyProperty*)lightsProperty;
+ (WXDependencyProperty*)tabFocusNavigationProperty;
+ (WXRoutedEvent*)noFocusCandidateFoundEvent;
+ (WXRoutedEvent*)losingFocusEvent;
+ (WXRoutedEvent*)gettingFocusEvent;
+ (WXRoutedEvent*)characterReceivedEvent;
+ (WXRoutedEvent*)previewKeyUpEvent;
+ (WXRoutedEvent*)previewKeyDownEvent;
- (EventRegistrationToken)addDoubleTappedEvent:(WUXIDoubleTappedEventHandler)del;
- (void)removeDoubleTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragEnterEvent:(WXDragEventHandler)del;
- (void)removeDragEnterEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragLeaveEvent:(WXDragEventHandler)del;
- (void)removeDragLeaveEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragOverEvent:(WXDragEventHandler)del;
- (void)removeDragOverEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropEvent:(WXDragEventHandler)del;
- (void)removeDropEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGotFocusEvent:(WXRoutedEventHandler)del;
- (void)removeGotFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addHoldingEvent:(WUXIHoldingEventHandler)del;
- (void)removeHoldingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyDownEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addKeyUpEvent:(WUXIKeyEventHandler)del;
- (void)removeKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLostFocusEvent:(WXRoutedEventHandler)del;
- (void)removeLostFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationCompletedEvent:(WUXIManipulationCompletedEventHandler)del;
- (void)removeManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationDeltaEvent:(WUXIManipulationDeltaEventHandler)del;
- (void)removeManipulationDeltaEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationInertiaStartingEvent:(WUXIManipulationInertiaStartingEventHandler)del;
- (void)removeManipulationInertiaStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartedEvent:(WUXIManipulationStartedEventHandler)del;
- (void)removeManipulationStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addManipulationStartingEvent:(WUXIManipulationStartingEventHandler)del;
- (void)removeManipulationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCanceledEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerCaptureLostEvent:(WUXIPointerEventHandler)del;
- (void)removePointerCaptureLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerEnteredEvent:(WUXIPointerEventHandler)del;
- (void)removePointerEnteredEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerExitedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerMovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerPressedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerReleasedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerWheelChangedEvent:(WUXIPointerEventHandler)del;
- (void)removePointerWheelChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRightTappedEvent:(WUXIRightTappedEventHandler)del;
- (void)removeRightTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTappedEvent:(WUXITappedEventHandler)del;
- (void)removeTappedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragStartingEvent:(void(^)(WXUIElement*, WXDragStartingEventArgs*))del;
- (void)removeDragStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropCompletedEvent:(void(^)(WXUIElement*, WXDropCompletedEventArgs*))del;
- (void)removeDropCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayDismissedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayDismissedEventArgs*))del;
- (void)removeAccessKeyDisplayDismissedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyDisplayRequestedEvent:(void(^)(WXUIElement*, WUXIAccessKeyDisplayRequestedEventArgs*))del;
- (void)removeAccessKeyDisplayRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addAccessKeyInvokedEvent:(void(^)(WXUIElement*, WUXIAccessKeyInvokedEventArgs*))del;
- (void)removeAccessKeyInvokedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextCanceledEvent:(void(^)(WXUIElement*, WXRoutedEventArgs*))del;
- (void)removeContextCanceledEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContextRequestedEvent:(void(^)(WXUIElement*, WUXIContextRequestedEventArgs*))del;
- (void)removeContextRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addGettingFocusEvent:(void(^)(WXUIElement*, WUXIGettingFocusEventArgs*))del;
- (void)removeGettingFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLosingFocusEvent:(void(^)(WXUIElement*, WUXILosingFocusEventArgs*))del;
- (void)removeLosingFocusEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNoFocusCandidateFoundEvent:(void(^)(WXUIElement*, WUXINoFocusCandidateFoundEventArgs*))del;
- (void)removeNoFocusCandidateFoundEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCharacterReceivedEvent:(void(^)(WXUIElement*, WUXICharacterReceivedRoutedEventArgs*))del;
- (void)removeCharacterReceivedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviewKeyDownEvent:(WUXIKeyEventHandler)del;
- (void)removePreviewKeyDownEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPreviewKeyUpEvent:(WUXIKeyEventHandler)del;
- (void)removePreviewKeyUpEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addProcessKeyboardAcceleratorsEvent:(void(^)(WXUIElement*, WUXIProcessKeyboardAcceleratorEventArgs*))del;
- (void)removeProcessKeyboardAcceleratorsEvent:(EventRegistrationToken)tok;
- (void)measure:(WFSize*)availableSize;
- (void)arrange:(WFRect*)finalRect;
- (BOOL)capturePointer:(WUXIPointer*)value;
- (void)releasePointerCapture:(WUXIPointer*)value;
- (void)releasePointerCaptures;
- (void)addHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler handledEventsToo:(BOOL)handledEventsToo;
- (void)removeHandler:(WXRoutedEvent*)routedEvent handler:(RTObject*)handler;
- (WUXMGeneralTransform*)transformToVisual:(WXUIElement*)visual;
- (void)invalidateMeasure;
- (void)invalidateArrange;
- (void)updateLayout;
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration> /* id<NSFastEnumeration> < WFPoint* > */)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
- (BOOL)cancelDirectManipulations;
- (void)startDragAsync:(WUIPointerPoint*)pointerPoint success:(void (^)(WADDataPackageOperation))success failure:(void (^)(NSError*))failure;
- (void)startBringIntoView;
- (void)startBringIntoViewWithOptions:(WXBringIntoViewOptions*)options;
- (void)tryInvokeKeyboardAccelerator:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
- (id<NSFastEnumeration> /* WXDependencyObject* */)getChildrenInTabFocusOrder;
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXFrameworkElement : WXUIElement
+ (void)deferTree:(WXDependencyObject*)element;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double height;
@property WXFlowDirection flowDirection;
@property (retain) RTObject* dataContext;
@property (retain) NSString * name;
@property double minWidth;
@property (retain) WXResourceDictionary* resources;
@property double minHeight;
@property double maxWidth;
@property double maxHeight;
@property (retain) WXThickness* margin;
@property (retain) NSString * language;
@property WXHorizontalAlignment horizontalAlignment;
@property WXVerticalAlignment verticalAlignment;
@property double width;
@property (retain) RTObject* tag;
@property (retain) WXStyle* style;
@property (readonly) double actualWidth;
@property (readonly) WFUri* baseUri;
@property (readonly) double actualHeight;
@property (readonly) WXDependencyObject* parent;
@property (readonly) WXTriggerCollection* triggers;
@property WXElementTheme requestedTheme;
@property (retain) WXThickness* focusVisualSecondaryThickness;
@property (retain) WUXMBrush* focusVisualSecondaryBrush;
@property (retain) WXThickness* focusVisualPrimaryThickness;
@property (retain) WUXMBrush* focusVisualPrimaryBrush;
@property (retain) WXThickness* focusVisualMargin;
@property BOOL allowFocusWhenDisabled;
@property BOOL allowFocusOnInteraction;
@property (readonly) WXElementTheme actualTheme;
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)actualHeightProperty;
+ (WXDependencyProperty*)actualWidthProperty;
+ (WXDependencyProperty*)dataContextProperty;
+ (WXDependencyProperty*)flowDirectionProperty;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)horizontalAlignmentProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)minHeightProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
+ (WXDependencyProperty*)focusVisualSecondaryThicknessProperty;
+ (WXDependencyProperty*)allowFocusOnInteractionProperty;
+ (WXDependencyProperty*)allowFocusWhenDisabledProperty;
+ (WXDependencyProperty*)focusVisualMarginProperty;
+ (WXDependencyProperty*)focusVisualPrimaryBrushProperty;
+ (WXDependencyProperty*)focusVisualPrimaryThicknessProperty;
+ (WXDependencyProperty*)focusVisualSecondaryBrushProperty;
+ (WXDependencyProperty*)actualThemeProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void(^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadingEvent:(void(^)(WXFrameworkElement*, RTObject*))del;
- (void)removeLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addActualThemeChangedEvent:(void(^)(WXFrameworkElement*, RTObject*))del;
- (void)removeActualThemeChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString *)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (BOOL)goToElementStateCore:(NSString *)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Controls.ParallaxView
#ifndef __WXCParallaxView_DEFINED__
#define __WXCParallaxView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCParallaxView : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double verticalSourceStartOffset;
@property WXCParallaxSourceOffsetKind verticalSourceOffsetKind;
@property double verticalSourceEndOffset;
@property double verticalShift;
@property (retain) WXUIElement* source;
@property double maxVerticalShiftRatio;
@property double maxHorizontalShiftRatio;
@property BOOL isVerticalShiftClamped;
@property BOOL isHorizontalShiftClamped;
@property double horizontalSourceStartOffset;
@property WXCParallaxSourceOffsetKind horizontalSourceOffsetKind;
@property double horizontalSourceEndOffset;
@property double horizontalShift;
@property (retain) WXUIElement* child;
+ (WXDependencyProperty*)childProperty;
+ (WXDependencyProperty*)horizontalShiftProperty;
+ (WXDependencyProperty*)horizontalSourceEndOffsetProperty;
+ (WXDependencyProperty*)horizontalSourceOffsetKindProperty;
+ (WXDependencyProperty*)horizontalSourceStartOffsetProperty;
+ (WXDependencyProperty*)isHorizontalShiftClampedProperty;
+ (WXDependencyProperty*)isVerticalShiftClampedProperty;
+ (WXDependencyProperty*)maxHorizontalShiftRatioProperty;
+ (WXDependencyProperty*)maxVerticalShiftRatioProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)verticalShiftProperty;
+ (WXDependencyProperty*)verticalSourceEndOffsetProperty;
+ (WXDependencyProperty*)verticalSourceOffsetKindProperty;
+ (WXDependencyProperty*)verticalSourceStartOffsetProperty;
- (void)refreshAutomaticHorizontalOffsets;
- (void)refreshAutomaticVerticalOffsets;
@end

#endif // __WXCParallaxView_DEFINED__

// Windows.UI.Xaml.Controls.Panel
#ifndef __WXCPanel_DEFINED__
#define __WXCPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPanel : WXFrameworkElement
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMATransitionCollection* childrenTransitions;
@property (retain) WUXMBrush* background;
@property (readonly) WXCUIElementCollection* children;
@property (readonly) BOOL isItemsHost;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)childrenTransitionsProperty;
+ (WXDependencyProperty*)isItemsHostProperty;
@end

#endif // __WXCPanel_DEFINED__

// Windows.UI.Xaml.Controls.Border
#ifndef __WXCBorder_DEFINED__
#define __WXCBorder_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCBorder : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXThickness* padding;
@property (retain) WXCornerRadius* cornerRadius;
@property (retain) WUXMATransitionCollection* childTransitions;
@property (retain) WXUIElement* child;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
@property (retain) WUXMBrush* background;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)childTransitionsProperty;
+ (WXDependencyProperty*)cornerRadiusProperty;
+ (WXDependencyProperty*)paddingProperty;
@end

#endif // __WXCBorder_DEFINED__

// Windows.UI.Xaml.Controls.CaptureElement
#ifndef __WXCCaptureElement_DEFINED__
#define __WXCCaptureElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCaptureElement : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMStretch stretch;
@property (retain) WMCMediaCapture* source;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WXCCaptureElement_DEFINED__

// Windows.UI.Xaml.Controls.ContentPresenter
#ifndef __WXCContentPresenter_DEFINED__
#define __WXCContentPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentPresenter : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMFontFamily* fontFamily;
@property (retain) WUXMATransitionCollection* contentTransitions;
@property (retain) WXCDataTemplateSelector* contentTemplateSelector;
@property (retain) WXDataTemplate* contentTemplate;
@property (retain) RTObject* content;
@property int characterSpacing;
@property double fontSize;
@property (retain) WUXMBrush* foreground;
@property (retain) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property WXOpticalMarginAlignment opticalMarginAlignment;
@property WXTextLineBounds textLineBounds;
@property BOOL isTextScaleFactorEnabled;
@property (retain) WXCornerRadius* cornerRadius;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
@property (retain) WUXMBrush* background;
@property WXHorizontalAlignment horizontalContentAlignment;
@property WXVerticalAlignment verticalContentAlignment;
@property WXTextWrapping textWrapping;
@property (retain) WXThickness* padding;
@property int maxLines;
@property WXLineStackingStrategy lineStackingStrategy;
@property double lineHeight;
+ (WXDependencyProperty*)contentTemplateProperty;
+ (WXDependencyProperty*)contentProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)contentTransitionsProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)contentTemplateSelectorProperty;
+ (WXDependencyProperty*)opticalMarginAlignmentProperty;
+ (WXDependencyProperty*)textLineBoundsProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)textWrappingProperty;
+ (WXDependencyProperty*)verticalContentAlignmentProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)maxLinesProperty;
+ (WXDependencyProperty*)lineStackingStrategyProperty;
+ (WXDependencyProperty*)lineHeightProperty;
+ (WXDependencyProperty*)horizontalContentAlignmentProperty;
+ (WXDependencyProperty*)cornerRadiusProperty;
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

#endif // __WXCContentPresenter_DEFINED__

// Windows.UI.Xaml.Controls.Image
#ifndef __WXCImage_DEFINED__
#define __WXCImage_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCImage : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMStretch stretch;
@property (retain) WUXMImageSource* source;
@property (retain) WXThickness* nineGrid;
@property (readonly) WMPPlayToSource* playToSource;
+ (WXDependencyProperty*)nineGridProperty;
+ (WXDependencyProperty*)playToSourceProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)stretchProperty;
- (EventRegistrationToken)addImageFailedEvent:(WXExceptionRoutedEventHandler)del;
- (void)removeImageFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImageOpenedEvent:(WXRoutedEventHandler)del;
- (void)removeImageOpenedEvent:(EventRegistrationToken)tok;
- (WMCCastingSource*)getAsCastingSource;
- (WUCCompositionBrush*)getAlphaMask;
@end

#endif // __WXCImage_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IScrollSnapPointsInfo
#ifndef __WUXCPIScrollSnapPointsInfo_DEFINED__
#define __WUXCPIScrollSnapPointsInfo_DEFINED__

@protocol WUXCPIScrollSnapPointsInfo
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPIScrollSnapPointsInfo : RTObject <WUXCPIScrollSnapPointsInfo>
@end

#endif // __WUXCPIScrollSnapPointsInfo_DEFINED__

// Windows.UI.Xaml.Controls.ItemsPresenter
#ifndef __WXCItemsPresenter_DEFINED__
#define __WXCItemsPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemsPresenter : WXFrameworkElement <WUXCPIScrollSnapPointsInfo>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXThickness* padding;
@property (retain) WUXMATransitionCollection* headerTransitions;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property (retain) WUXMATransitionCollection* footerTransitions;
@property (retain) WXDataTemplate* footerTemplate;
@property (retain) RTObject* footer;
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)headerTransitionsProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)footerProperty;
+ (WXDependencyProperty*)footerTemplateProperty;
+ (WXDependencyProperty*)footerTransitionsProperty;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WXCItemsPresenter_DEFINED__

// Windows.UI.Xaml.Controls.RichTextBlockOverflow
#ifndef __WXCRichTextBlockOverflow_DEFINED__
#define __WXCRichTextBlockOverflow_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRichTextBlockOverflow : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXThickness* padding;
@property (retain) WXCRichTextBlockOverflow* overflowContentTarget;
@property (readonly) double baselineOffset;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) WXCRichTextBlock* contentSource;
@property (readonly) WUXDTextPointer* contentStart;
@property (readonly) BOOL hasOverflowContent;
@property int maxLines;
@property (readonly) BOOL isTextTrimmed;
+ (WXDependencyProperty*)hasOverflowContentProperty;
+ (WXDependencyProperty*)overflowContentTargetProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)maxLinesProperty;
+ (WXDependencyProperty*)isTextTrimmedProperty;
- (EventRegistrationToken)addIsTextTrimmedChangedEvent:(void(^)(WXCRichTextBlockOverflow*, WXCIsTextTrimmedChangedEventArgs*))del;
- (void)removeIsTextTrimmedChangedEvent:(EventRegistrationToken)tok;
- (WUXDTextPointer*)getPositionFromPoint:(WFPoint*)point;
- (BOOL)focus:(WXFocusState)value;
@end

#endif // __WXCRichTextBlockOverflow_DEFINED__

// Windows.UI.Xaml.Controls.RichTextBlock
#ifndef __WXCRichTextBlock_DEFINED__
#define __WXCRichTextBlock_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRichTextBlock : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUTFontStretch fontStretch;
@property (retain) WUXMBrush* foreground;
@property (retain) WUXMFontFamily* fontFamily;
@property double lineHeight;
@property WXLineStackingStrategy lineStackingStrategy;
@property (retain) WXCRichTextBlockOverflow* overflowContentTarget;
@property WUTFontStyle fontStyle;
@property WXTextWrapping textWrapping;
@property WXTextTrimming textTrimming;
@property int characterSpacing;
@property double textIndent;
@property WXTextAlignment textAlignment;
@property BOOL isTextSelectionEnabled;
@property (retain) WXThickness* padding;
@property double fontSize;
@property (retain) WUTFontWeight* fontWeight;
@property (readonly) BOOL hasOverflowContent;
@property (readonly) NSString * selectedText;
@property (readonly) double baselineOffset;
@property (readonly) WUXDTextPointer* selectionEnd;
@property (readonly) WUXDTextPointer* selectionStart;
@property (readonly) WUXDBlockCollection* blocks;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) WUXDTextPointer* contentStart;
@property WXTextLineBounds textLineBounds;
@property (retain) WUXMSolidColorBrush* selectionHighlightColor;
@property WXOpticalMarginAlignment opticalMarginAlignment;
@property int maxLines;
@property BOOL isColorFontEnabled;
@property WXTextReadingOrder textReadingOrder;
@property BOOL isTextScaleFactorEnabled;
@property WUTTextDecorations textDecorations;
@property WXTextAlignment horizontalTextAlignment;
@property (readonly) BOOL isTextTrimmed;
@property (readonly) NSMutableArray* /* WUXDTextHighlighter* */ textHighlighters;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)hasOverflowContentProperty;
+ (WXDependencyProperty*)isTextSelectionEnabledProperty;
+ (WXDependencyProperty*)lineHeightProperty;
+ (WXDependencyProperty*)lineStackingStrategyProperty;
+ (WXDependencyProperty*)overflowContentTargetProperty;
+ (WXDependencyProperty*)selectedTextProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)textIndentProperty;
+ (WXDependencyProperty*)textTrimmingProperty;
+ (WXDependencyProperty*)textWrappingProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)maxLinesProperty;
+ (WXDependencyProperty*)opticalMarginAlignmentProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)textLineBoundsProperty;
+ (WXDependencyProperty*)textReadingOrderProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)textDecorationsProperty;
+ (WXDependencyProperty*)isTextTrimmedProperty;
+ (WXDependencyProperty*)horizontalTextAlignmentProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsTextTrimmedChangedEvent:(void(^)(WXCRichTextBlock*, WXCIsTextTrimmedChangedEventArgs*))del;
- (void)removeIsTextTrimmedChangedEvent:(EventRegistrationToken)tok;
- (void)selectAll;
- (void)select:(WUXDTextPointer*)start end:(WUXDTextPointer*)end;
- (WUXDTextPointer*)getPositionFromPoint:(WFPoint*)point;
- (BOOL)focus:(WXFocusState)value;
@end

#endif // __WXCRichTextBlock_DEFINED__

// Windows.UI.Xaml.Controls.TextBlock
#ifndef __WXCTextBlock_DEFINED__
#define __WXCTextBlock_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextBlock : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double fontSize;
@property WXLineStackingStrategy lineStackingStrategy;
@property double lineHeight;
@property int characterSpacing;
@property BOOL isTextSelectionEnabled;
@property (retain) WUTFontWeight* fontWeight;
@property (retain) WXThickness* padding;
@property (retain) WUXMBrush* foreground;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property (retain) WUXMFontFamily* fontFamily;
@property WXTextWrapping textWrapping;
@property WXTextTrimming textTrimming;
@property WXTextAlignment textAlignment;
@property (retain) NSString * text;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) WUXDTextPointer* contentStart;
@property (readonly) double baselineOffset;
@property (readonly) WUXDInlineCollection* inlines;
@property (readonly) NSString * selectedText;
@property (readonly) WUXDTextPointer* selectionEnd;
@property (readonly) WUXDTextPointer* selectionStart;
@property WXOpticalMarginAlignment opticalMarginAlignment;
@property WXTextReadingOrder textReadingOrder;
@property WXTextLineBounds textLineBounds;
@property (retain) WUXMSolidColorBrush* selectionHighlightColor;
@property int maxLines;
@property BOOL isColorFontEnabled;
@property BOOL isTextScaleFactorEnabled;
@property WUTTextDecorations textDecorations;
@property WXTextAlignment horizontalTextAlignment;
@property (readonly) BOOL isTextTrimmed;
@property (readonly) NSMutableArray* /* WUXDTextHighlighter* */ textHighlighters;
+ (WXDependencyProperty*)lineStackingStrategyProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)isTextSelectionEnabledProperty;
+ (WXDependencyProperty*)lineHeightProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)selectedTextProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)textTrimmingProperty;
+ (WXDependencyProperty*)textWrappingProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)maxLinesProperty;
+ (WXDependencyProperty*)opticalMarginAlignmentProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)textLineBoundsProperty;
+ (WXDependencyProperty*)textReadingOrderProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)textDecorationsProperty;
+ (WXDependencyProperty*)isTextTrimmedProperty;
+ (WXDependencyProperty*)horizontalTextAlignmentProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsTextTrimmedChangedEvent:(void(^)(WXCTextBlock*, WXCIsTextTrimmedChangedEventArgs*))del;
- (void)removeIsTextTrimmedChangedEvent:(EventRegistrationToken)tok;
- (void)selectAll;
- (void)select:(WUXDTextPointer*)start end:(WUXDTextPointer*)end;
- (BOOL)focus:(WXFocusState)value;
- (WUCCompositionBrush*)getAlphaMask;
@end

#endif // __WXCTextBlock_DEFINED__

// Windows.UI.Xaml.Controls.Viewbox
#ifndef __WXCViewbox_DEFINED__
#define __WXCViewbox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCViewbox : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCStretchDirection stretchDirection;
@property WUXMStretch stretch;
@property (retain) WXUIElement* child;
+ (WXDependencyProperty*)stretchDirectionProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WXCViewbox_DEFINED__

// Windows.UI.Xaml.Controls.Canvas
#ifndef __WXCCanvas_DEFINED__
#define __WXCCanvas_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCanvas : WXCPanel
+ (double)getLeft:(WXUIElement*)element;
+ (void)setLeft:(WXUIElement*)element length:(double)length;
+ (double)getTop:(WXUIElement*)element;
+ (void)setTop:(WXUIElement*)element length:(double)length;
+ (int)getZIndex:(WXUIElement*)element;
+ (void)setZIndex:(WXUIElement*)element value:(int)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WXDependencyProperty*)leftProperty;
+ (WXDependencyProperty*)topProperty;
+ (WXDependencyProperty*)zIndexProperty;
@end

#endif // __WXCCanvas_DEFINED__

// Windows.UI.Xaml.Controls.Grid
#ifndef __WXCGrid_DEFINED__
#define __WXCGrid_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCGrid : WXCPanel
+ (int)getRow:(WXFrameworkElement*)element;
+ (void)setRow:(WXFrameworkElement*)element value:(int)value;
+ (int)getColumn:(WXFrameworkElement*)element;
+ (void)setColumn:(WXFrameworkElement*)element value:(int)value;
+ (int)getRowSpan:(WXFrameworkElement*)element;
+ (void)setRowSpan:(WXFrameworkElement*)element value:(int)value;
+ (int)getColumnSpan:(WXFrameworkElement*)element;
+ (void)setColumnSpan:(WXFrameworkElement*)element value:(int)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCColumnDefinitionCollection* columnDefinitions;
@property (readonly) WXCRowDefinitionCollection* rowDefinitions;
@property (retain) WXThickness* padding;
@property (retain) WXCornerRadius* cornerRadius;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
@property double rowSpacing;
@property double columnSpacing;
+ (WXDependencyProperty*)columnProperty;
+ (WXDependencyProperty*)columnSpanProperty;
+ (WXDependencyProperty*)rowProperty;
+ (WXDependencyProperty*)rowSpanProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)cornerRadiusProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)columnSpacingProperty;
+ (WXDependencyProperty*)rowSpacingProperty;
@end

#endif // __WXCGrid_DEFINED__

// Windows.UI.Xaml.Controls.RelativePanel
#ifndef __WXCRelativePanel_DEFINED__
#define __WXCRelativePanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRelativePanel : WXCPanel
+ (RTObject*)getLeftOf:(WXUIElement*)element;
+ (void)setLeftOf:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getAbove:(WXUIElement*)element;
+ (void)setAbove:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getRightOf:(WXUIElement*)element;
+ (void)setRightOf:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getBelow:(WXUIElement*)element;
+ (void)setBelow:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getAlignHorizontalCenterWith:(WXUIElement*)element;
+ (void)setAlignHorizontalCenterWith:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getAlignVerticalCenterWith:(WXUIElement*)element;
+ (void)setAlignVerticalCenterWith:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getAlignLeftWith:(WXUIElement*)element;
+ (void)setAlignLeftWith:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getAlignTopWith:(WXUIElement*)element;
+ (void)setAlignTopWith:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getAlignRightWith:(WXUIElement*)element;
+ (void)setAlignRightWith:(WXUIElement*)element value:(RTObject*)value;
+ (RTObject*)getAlignBottomWith:(WXUIElement*)element;
+ (void)setAlignBottomWith:(WXUIElement*)element value:(RTObject*)value;
+ (BOOL)getAlignLeftWithPanel:(WXUIElement*)element;
+ (void)setAlignLeftWithPanel:(WXUIElement*)element value:(BOOL)value;
+ (BOOL)getAlignTopWithPanel:(WXUIElement*)element;
+ (void)setAlignTopWithPanel:(WXUIElement*)element value:(BOOL)value;
+ (BOOL)getAlignRightWithPanel:(WXUIElement*)element;
+ (void)setAlignRightWithPanel:(WXUIElement*)element value:(BOOL)value;
+ (BOOL)getAlignBottomWithPanel:(WXUIElement*)element;
+ (void)setAlignBottomWithPanel:(WXUIElement*)element value:(BOOL)value;
+ (BOOL)getAlignHorizontalCenterWithPanel:(WXUIElement*)element;
+ (void)setAlignHorizontalCenterWithPanel:(WXUIElement*)element value:(BOOL)value;
+ (BOOL)getAlignVerticalCenterWithPanel:(WXUIElement*)element;
+ (void)setAlignVerticalCenterWithPanel:(WXUIElement*)element value:(BOOL)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXThickness* padding;
@property (retain) WXCornerRadius* cornerRadius;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
+ (WXDependencyProperty*)aboveProperty;
+ (WXDependencyProperty*)alignBottomWithPanelProperty;
+ (WXDependencyProperty*)alignBottomWithProperty;
+ (WXDependencyProperty*)alignHorizontalCenterWithPanelProperty;
+ (WXDependencyProperty*)alignHorizontalCenterWithProperty;
+ (WXDependencyProperty*)alignLeftWithPanelProperty;
+ (WXDependencyProperty*)alignLeftWithProperty;
+ (WXDependencyProperty*)alignRightWithPanelProperty;
+ (WXDependencyProperty*)alignRightWithProperty;
+ (WXDependencyProperty*)alignTopWithPanelProperty;
+ (WXDependencyProperty*)alignTopWithProperty;
+ (WXDependencyProperty*)alignVerticalCenterWithPanelProperty;
+ (WXDependencyProperty*)alignVerticalCenterWithProperty;
+ (WXDependencyProperty*)belowProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)cornerRadiusProperty;
+ (WXDependencyProperty*)leftOfProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)rightOfProperty;
@end

#endif // __WXCRelativePanel_DEFINED__

// Windows.UI.Xaml.Controls.StackPanel
#ifndef __WXCStackPanel_DEFINED__
#define __WXCStackPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCStackPanel : WXCPanel <WUXCPIScrollSnapPointsInfo, WXCIInsertionPanel>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCOrientation orientation;
@property BOOL areScrollSnapPointsRegular;
@property (retain) WXThickness* padding;
@property (retain) WXCornerRadius* cornerRadius;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
@property double spacing;
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
+ (WXDependencyProperty*)areScrollSnapPointsRegularProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)cornerRadiusProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)spacingProperty;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
- (void)getInsertionIndexes:(WFPoint*)position first:(int*)first second:(int*)second;
@end

#endif // __WXCStackPanel_DEFINED__

// Windows.UI.Xaml.Controls.VariableSizedWrapGrid
#ifndef __WXCVariableSizedWrapGrid_DEFINED__
#define __WXCVariableSizedWrapGrid_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCVariableSizedWrapGrid : WXCPanel
+ (int)getRowSpan:(WXUIElement*)element;
+ (void)setRowSpan:(WXUIElement*)element value:(int)value;
+ (int)getColumnSpan:(WXUIElement*)element;
+ (void)setColumnSpan:(WXUIElement*)element value:(int)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXVerticalAlignment verticalChildrenAlignment;
@property WXCOrientation orientation;
@property int maximumRowsOrColumns;
@property double itemWidth;
@property double itemHeight;
@property WXHorizontalAlignment horizontalChildrenAlignment;
+ (WXDependencyProperty*)columnSpanProperty;
+ (WXDependencyProperty*)horizontalChildrenAlignmentProperty;
+ (WXDependencyProperty*)itemHeightProperty;
+ (WXDependencyProperty*)itemWidthProperty;
+ (WXDependencyProperty*)maximumRowsOrColumnsProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)rowSpanProperty;
+ (WXDependencyProperty*)verticalChildrenAlignmentProperty;
@end

#endif // __WXCVariableSizedWrapGrid_DEFINED__

// Windows.UI.Xaml.Controls.VirtualizingPanel
#ifndef __WXCVirtualizingPanel_DEFINED__
#define __WXCVirtualizingPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCVirtualizingPanel : WXCPanel
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCItemContainerGenerator* itemContainerGenerator;
- (void)onItemsChanged:(RTObject*)sender args:(WUXCPItemsChangedEventArgs*)args;
- (void)onClearChildren;
- (void)bringIndexIntoView:(int)index;
- (void)addInternalChild:(WXUIElement*)child;
- (void)insertInternalChild:(int)index child:(WXUIElement*)child;
- (void)removeInternalChildRange:(int)index range:(int)range;
@end

#endif // __WXCVirtualizingPanel_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.OrientedVirtualizingPanel
#ifndef __WUXCPOrientedVirtualizingPanel_DEFINED__
#define __WUXCPOrientedVirtualizingPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPOrientedVirtualizingPanel : WXCVirtualizingPanel <WUXCPIScrollSnapPointsInfo, WXCIInsertionPanel>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* scrollOwner;
@property BOOL canVerticallyScroll;
@property BOOL canHorizontallyScroll;
@property (readonly) double extentHeight;
@property (readonly) double extentWidth;
@property (readonly) double horizontalOffset;
@property (readonly) double verticalOffset;
@property (readonly) double viewportHeight;
@property (readonly) double viewportWidth;
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (void)lineUp;
- (void)lineDown;
- (void)lineLeft;
- (void)lineRight;
- (void)pageUp;
- (void)pageDown;
- (void)pageLeft;
- (void)pageRight;
- (void)mouseWheelUp;
- (void)mouseWheelDown;
- (void)mouseWheelLeft;
- (void)mouseWheelRight;
- (void)setHorizontalOffset:(double)offset;
- (void)setVerticalOffset:(double)offset;
- (WFRect*)makeVisible:(WXUIElement*)visual rectangle:(WFRect*)rectangle;
- (NSArray* /* float */)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
- (void)getInsertionIndexes:(WFPoint*)position first:(int*)first second:(int*)second;
@end

#endif // __WUXCPOrientedVirtualizingPanel_DEFINED__

// Windows.UI.Xaml.Controls.VirtualizingStackPanel
#ifndef __WXCVirtualizingStackPanel_DEFINED__
#define __WXCVirtualizingStackPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCVirtualizingStackPanel : WUXCPOrientedVirtualizingPanel
+ (WXCVirtualizationMode)getVirtualizationMode:(WXDependencyObject*)element;
+ (void)setVirtualizationMode:(WXDependencyObject*)element value:(WXCVirtualizationMode)value;
+ (BOOL)getIsVirtualizing:(WXDependencyObject*)o;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCOrientation orientation;
@property BOOL areScrollSnapPointsRegular;
+ (WXDependencyProperty*)areScrollSnapPointsRegularProperty;
+ (WXDependencyProperty*)isVirtualizingProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)virtualizationModeProperty;
- (EventRegistrationToken)addCleanUpVirtualizedItemEventEvent:(WXCCleanUpVirtualizedItemEventHandler)del;
- (void)removeCleanUpVirtualizedItemEventEvent:(EventRegistrationToken)tok;
- (void)onCleanUpVirtualizedItem:(WXCCleanUpVirtualizedItemEventArgs*)e;
@end

#endif // __WXCVirtualizingStackPanel_DEFINED__

// Windows.UI.Xaml.Controls.IconElement
#ifndef __WXCIconElement_DEFINED__
#define __WXCIconElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCIconElement : WXFrameworkElement
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMBrush* foreground;
+ (WXDependencyProperty*)foregroundProperty;
@end

#endif // __WXCIconElement_DEFINED__

// Windows.UI.Xaml.Controls.InkCanvas
#ifndef __WXCInkCanvas_DEFINED__
#define __WXCInkCanvas_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkCanvas : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIInkPresenter* inkPresenter;
@end

#endif // __WXCInkCanvas_DEFINED__

// Windows.UI.Xaml.Controls.MediaElement
#ifndef __WXCMediaElement_DEFINED__
#define __WXCMediaElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMediaElement : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double playbackRate;
@property BOOL autoPlay;
@property (retain) id /* int */ audioStreamIndex;
@property BOOL isMuted;
@property WUXMAudioCategory audioCategory;
@property double defaultPlaybackRate;
@property BOOL isLooping;
@property double balance;
@property WUXMAudioDeviceType audioDeviceType;
@property double volume;
@property WUXMStereo3DVideoRenderMode stereo3DVideoRenderMode;
@property WUXMStereo3DVideoPackingMode stereo3DVideoPackingMode;
@property (retain) WFUri* source;
@property BOOL realTimePlayback;
@property (retain) WMPMediaProtectionManager* protectionManager;
@property (retain) WUXMImageSource* posterSource;
@property (retain) WFTimeSpan* position;
@property (readonly) double downloadProgressOffset;
@property (readonly) BOOL isAudioOnly;
@property (readonly) BOOL isStereo3DVideo;
@property (readonly) WUXMTimelineMarkerCollection* markers;
@property (readonly) WXDuration* naturalDuration;
@property (readonly) int naturalVideoHeight;
@property (readonly) int naturalVideoWidth;
@property (readonly) WMPPlayToSource* playToSource;
@property (readonly) int aspectRatioHeight;
@property (readonly) int aspectRatioWidth;
@property (readonly) WUXMStereo3DVideoPackingMode actualStereo3DVideoPackingMode;
@property (readonly) int audioStreamCount;
@property (readonly) double bufferingProgress;
@property (readonly) BOOL canPause;
@property (readonly) BOOL canSeek;
@property (readonly) WUXMMediaElementState currentState;
@property (readonly) double downloadProgress;
@property WUXMStretch stretch;
@property (retain) WFUri* playToPreferredSourceUri;
@property BOOL isFullWindow;
@property BOOL areTransportControlsEnabled;
@property (retain) WXCMediaTransportControls* transportControls;
+ (WXDependencyProperty*)aspectRatioHeightProperty;
+ (WXDependencyProperty*)actualStereo3DVideoPackingModeProperty;
+ (WXDependencyProperty*)downloadProgressOffsetProperty;
+ (WXDependencyProperty*)aspectRatioWidthProperty;
+ (WXDependencyProperty*)audioCategoryProperty;
+ (WXDependencyProperty*)audioDeviceTypeProperty;
+ (WXDependencyProperty*)audioStreamCountProperty;
+ (WXDependencyProperty*)audioStreamIndexProperty;
+ (WXDependencyProperty*)autoPlayProperty;
+ (WXDependencyProperty*)balanceProperty;
+ (WXDependencyProperty*)bufferingProgressProperty;
+ (WXDependencyProperty*)canPauseProperty;
+ (WXDependencyProperty*)canSeekProperty;
+ (WXDependencyProperty*)currentStateProperty;
+ (WXDependencyProperty*)defaultPlaybackRateProperty;
+ (WXDependencyProperty*)downloadProgressProperty;
+ (WXDependencyProperty*)isAudioOnlyProperty;
+ (WXDependencyProperty*)isLoopingProperty;
+ (WXDependencyProperty*)isMutedProperty;
+ (WXDependencyProperty*)isStereo3DVideoProperty;
+ (WXDependencyProperty*)naturalDurationProperty;
+ (WXDependencyProperty*)naturalVideoHeightProperty;
+ (WXDependencyProperty*)naturalVideoWidthProperty;
+ (WXDependencyProperty*)playToSourceProperty;
+ (WXDependencyProperty*)playbackRateProperty;
+ (WXDependencyProperty*)positionProperty;
+ (WXDependencyProperty*)posterSourceProperty;
+ (WXDependencyProperty*)protectionManagerProperty;
+ (WXDependencyProperty*)realTimePlaybackProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)stereo3DVideoPackingModeProperty;
+ (WXDependencyProperty*)stereo3DVideoRenderModeProperty;
+ (WXDependencyProperty*)volumeProperty;
+ (WXDependencyProperty*)isFullWindowProperty;
+ (WXDependencyProperty*)playToPreferredSourceUriProperty;
+ (WXDependencyProperty*)stretchProperty;
+ (WXDependencyProperty*)areTransportControlsEnabledProperty;
- (EventRegistrationToken)addBufferingProgressChangedEvent:(WXRoutedEventHandler)del;
- (void)removeBufferingProgressChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCurrentStateChangedEvent:(WXRoutedEventHandler)del;
- (void)removeCurrentStateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDownloadProgressChangedEvent:(WXRoutedEventHandler)del;
- (void)removeDownloadProgressChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMarkerReachedEvent:(WUXMTimelineMarkerRoutedEventHandler)del;
- (void)removeMarkerReachedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaEndedEvent:(WXRoutedEventHandler)del;
- (void)removeMediaEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaFailedEvent:(WXExceptionRoutedEventHandler)del;
- (void)removeMediaFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addMediaOpenedEvent:(WXRoutedEventHandler)del;
- (void)removeMediaOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addRateChangedEvent:(WUXMRateChangedRoutedEventHandler)del;
- (void)removeRateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSeekCompletedEvent:(WXRoutedEventHandler)del;
- (void)removeSeekCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVolumeChangedEvent:(WXRoutedEventHandler)del;
- (void)removeVolumeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPartialMediaFailureDetectedEvent:(void(^)(WXCMediaElement*, WUXMPartialMediaFailureDetectedEventArgs*))del;
- (void)removePartialMediaFailureDetectedEvent:(EventRegistrationToken)tok;
- (void)stop;
- (void)play;
- (void)pause;
- (WUXMMediaCanPlayResponse)canPlayType:(NSString *)type;
- (void)setSource:(RTObject<WSSIRandomAccessStream>*)stream mimeType:(NSString *)mimeType;
- (NSString *)getAudioStreamLanguage:(id /* int */)index;
- (void)addAudioEffect:(NSString *)effectID effectOptional:(BOOL)effectOptional effectConfiguration:(RTObject<WFCIPropertySet>*)effectConfiguration;
- (void)addVideoEffect:(NSString *)effectID effectOptional:(BOOL)effectOptional effectConfiguration:(RTObject<WFCIPropertySet>*)effectConfiguration;
- (void)removeAllEffects;
- (void)setMediaStreamSource:(RTObject<WMCIMediaSource>*)source;
- (void)setPlaybackSource:(RTObject<WMPIMediaPlaybackSource>*)source;
- (WMCCastingSource*)getAsCastingSource;
@end

#endif // __WXCMediaElement_DEFINED__

// Windows.UI.Xaml.Controls.MediaPlayerPresenter
#ifndef __WXCMediaPlayerPresenter_DEFINED__
#define __WXCMediaPlayerPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMediaPlayerPresenter : WXFrameworkElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMStretch stretch;
@property (retain) WMPMediaPlayer* mediaPlayer;
@property BOOL isFullWindow;
+ (WXDependencyProperty*)isFullWindowProperty;
+ (WXDependencyProperty*)mediaPlayerProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WXCMediaPlayerPresenter_DEFINED__

// Windows.UI.Xaml.Controls.WebView
#ifndef __WXCWebView_DEFINED__
#define __WXCWebView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebView : WXFrameworkElement
+ (RTObject<WFIAsyncAction>*)clearTemporaryWebDataAsync;
+ (WXCWebView*)makeInstanceWithExecutionMode:(WXCWebViewExecutionMode)executionMode ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* source;
@property (retain) NSMutableArray* /* WFUri* */ allowedScriptNotifyUris;
@property (readonly) WADDataPackage* dataTransferPackage;
@property (retain) WUColor* defaultBackgroundColor;
@property (readonly) BOOL canGoBack;
@property (readonly) BOOL canGoForward;
@property (readonly) NSString * documentTitle;
@property (readonly) BOOL containsFullScreenElement;
@property (readonly) NSMutableArray* /* WXCWebViewDeferredPermissionRequest* */ deferredPermissionRequests;
@property (readonly) WXCWebViewExecutionMode executionMode;
@property (readonly) WXCWebViewSettings* settings;
@property (retain) WXDependencyObject* xYFocusRight;
@property (retain) WXDependencyObject* xYFocusLeft;
@property (retain) WXDependencyObject* xYFocusDown;
@property (retain) WXDependencyObject* xYFocusUp;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)dataTransferPackageProperty;
+ (NSMutableArray* /* WFUri* */)anyScriptNotifyUri;
+ (WXDependencyProperty*)allowedScriptNotifyUrisProperty;
+ (WXDependencyProperty*)documentTitleProperty;
+ (WXDependencyProperty*)canGoBackProperty;
+ (WXDependencyProperty*)canGoForwardProperty;
+ (WXDependencyProperty*)defaultBackgroundColorProperty;
+ (WXDependencyProperty*)containsFullScreenElementProperty;
+ (WXCWebViewExecutionMode)defaultExecutionMode;
+ (WXDependencyProperty*)xYFocusDownProperty;
+ (WXDependencyProperty*)xYFocusLeftProperty;
+ (WXDependencyProperty*)xYFocusRightProperty;
+ (WXDependencyProperty*)xYFocusUpProperty;
- (EventRegistrationToken)addLoadCompletedEvent:(WUXNLoadCompletedEventHandler)del;
- (void)removeLoadCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationFailedEvent:(WXCWebViewNavigationFailedEventHandler)del;
- (void)removeNavigationFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addScriptNotifyEvent:(WXCNotifyEventHandler)del;
- (void)removeScriptNotifyEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContentLoadingEvent:(void(^)(WXCWebView*, WXCWebViewContentLoadingEventArgs*))del;
- (void)removeContentLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDOMContentLoadedEvent:(void(^)(WXCWebView*, WXCWebViewDOMContentLoadedEventArgs*))del;
- (void)removeDOMContentLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameContentLoadingEvent:(void(^)(WXCWebView*, WXCWebViewContentLoadingEventArgs*))del;
- (void)removeFrameContentLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameDOMContentLoadedEvent:(void(^)(WXCWebView*, WXCWebViewDOMContentLoadedEventArgs*))del;
- (void)removeFrameDOMContentLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameNavigationCompletedEvent:(void(^)(WXCWebView*, WXCWebViewNavigationCompletedEventArgs*))del;
- (void)removeFrameNavigationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameNavigationStartingEvent:(void(^)(WXCWebView*, WXCWebViewNavigationStartingEventArgs*))del;
- (void)removeFrameNavigationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLongRunningScriptDetectedEvent:(void(^)(WXCWebView*, WXCWebViewLongRunningScriptDetectedEventArgs*))del;
- (void)removeLongRunningScriptDetectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationCompletedEvent:(void(^)(WXCWebView*, WXCWebViewNavigationCompletedEventArgs*))del;
- (void)removeNavigationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationStartingEvent:(void(^)(WXCWebView*, WXCWebViewNavigationStartingEventArgs*))del;
- (void)removeNavigationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnsafeContentWarningDisplayingEvent:(void(^)(WXCWebView*, RTObject*))del;
- (void)removeUnsafeContentWarningDisplayingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnviewableContentIdentifiedEvent:(void(^)(WXCWebView*, WXCWebViewUnviewableContentIdentifiedEventArgs*))del;
- (void)removeUnviewableContentIdentifiedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContainsFullScreenElementChangedEvent:(void(^)(WXCWebView*, RTObject*))del;
- (void)removeContainsFullScreenElementChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNewWindowRequestedEvent:(void(^)(WXCWebView*, WXCWebViewNewWindowRequestedEventArgs*))del;
- (void)removeNewWindowRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPermissionRequestedEvent:(void(^)(WXCWebView*, WXCWebViewPermissionRequestedEventArgs*))del;
- (void)removePermissionRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnsupportedUriSchemeIdentifiedEvent:(void(^)(WXCWebView*, WXCWebViewUnsupportedUriSchemeIdentifiedEventArgs*))del;
- (void)removeUnsupportedUriSchemeIdentifiedEvent:(EventRegistrationToken)tok;
- (NSString *)invokeScript:(NSString *)scriptName arguments:(NSArray* /* NSString * */)arguments;
- (void)navigate:(WFUri*)source;
- (void)navigateToString:(NSString *)text;
- (void)goForward;
- (void)goBack;
- (void)refresh;
- (void)stop;
- (RTObject<WFIAsyncAction>*)capturePreviewToStreamAsync:(RTObject<WSSIRandomAccessStream>*)stream;
- (void)invokeScriptAsync:(NSString *)scriptName arguments:(id<NSFastEnumeration> /* NSString * */)arguments success:(void (^)(NSString *))success failure:(void (^)(NSError*))failure;
- (void)captureSelectedContentToDataPackageAsyncWithSuccess:(void (^)(WADDataPackage*))success failure:(void (^)(NSError*))failure;
- (void)navigateToLocalStreamUri:(WFUri*)source streamResolver:(RTObject<WWIUriToStreamResolver>*)streamResolver;
- (WFUri*)buildLocalStreamUri:(NSString *)contentIdentifier relativePath:(NSString *)relativePath;
- (void)navigateWithHttpRequestMessage:(WWHHttpRequestMessage*)requestMessage;
- (BOOL)focus:(WXFocusState)value;
- (void)addWebAllowedObject:(NSString *)name pObject:(RTObject*)pObject;
- (WXCWebViewDeferredPermissionRequest*)deferredPermissionRequestById:(unsigned int)id;
@end

#endif // __WXCWebView_DEFINED__

// Windows.UI.Xaml.Controls.BitmapIcon
#ifndef __WXCBitmapIcon_DEFINED__
#define __WXCBitmapIcon_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCBitmapIcon : WXCIconElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* uriSource;
@property BOOL showAsMonochrome;
+ (WXDependencyProperty*)uriSourceProperty;
+ (WXDependencyProperty*)showAsMonochromeProperty;
@end

#endif // __WXCBitmapIcon_DEFINED__

// Windows.UI.Xaml.Controls.FontIcon
#ifndef __WXCFontIcon_DEFINED__
#define __WXCFontIcon_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFontIcon : WXCIconElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * glyph;
@property (retain) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property double fontSize;
@property (retain) WUXMFontFamily* fontFamily;
@property BOOL isTextScaleFactorEnabled;
@property BOOL mirroredWhenRightToLeft;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)glyphProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)mirroredWhenRightToLeftProperty;
@end

#endif // __WXCFontIcon_DEFINED__

// Windows.UI.Xaml.Controls.ItemsStackPanel
#ifndef __WXCItemsStackPanel_DEFINED__
#define __WXCItemsStackPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemsStackPanel : WXCPanel
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXCPGroupHeaderPlacement groupHeaderPlacement;
@property WXCItemsUpdatingScrollMode itemsUpdatingScrollMode;
@property (retain) WXThickness* groupPadding;
@property double cacheLength;
@property WXCOrientation orientation;
@property (readonly) int firstCacheIndex;
@property (readonly) int firstVisibleIndex;
@property (readonly) int lastCacheIndex;
@property (readonly) int lastVisibleIndex;
@property (readonly) WXCPanelScrollingDirection scrollingDirection;
@property BOOL areStickyGroupHeadersEnabled;
+ (WXDependencyProperty*)cacheLengthProperty;
+ (WXDependencyProperty*)groupHeaderPlacementProperty;
+ (WXDependencyProperty*)groupPaddingProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)areStickyGroupHeadersEnabledProperty;
@end

#endif // __WXCItemsStackPanel_DEFINED__

// Windows.UI.Xaml.Controls.ItemsWrapGrid
#ifndef __WXCItemsWrapGrid_DEFINED__
#define __WXCItemsWrapGrid_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemsWrapGrid : WXCPanel
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXThickness* groupPadding;
@property WUXCPGroupHeaderPlacement groupHeaderPlacement;
@property double itemWidth;
@property double itemHeight;
@property double cacheLength;
@property WXCOrientation orientation;
@property int maximumRowsOrColumns;
@property (readonly) int firstCacheIndex;
@property (readonly) int firstVisibleIndex;
@property (readonly) int lastCacheIndex;
@property (readonly) int lastVisibleIndex;
@property (readonly) WXCPanelScrollingDirection scrollingDirection;
@property BOOL areStickyGroupHeadersEnabled;
+ (WXDependencyProperty*)cacheLengthProperty;
+ (WXDependencyProperty*)groupHeaderPlacementProperty;
+ (WXDependencyProperty*)groupPaddingProperty;
+ (WXDependencyProperty*)itemHeightProperty;
+ (WXDependencyProperty*)itemWidthProperty;
+ (WXDependencyProperty*)maximumRowsOrColumnsProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)areStickyGroupHeadersEnabledProperty;
@end

#endif // __WXCItemsWrapGrid_DEFINED__

// Windows.UI.Xaml.Controls.PathIcon
#ifndef __WXCPathIcon_DEFINED__
#define __WXCPathIcon_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPathIcon : WXCIconElement
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMGeometry* data;
+ (WXDependencyProperty*)dataProperty;
@end

#endif // __WXCPathIcon_DEFINED__

// Windows.UI.Xaml.Controls.ScrollContentPresenter
#ifndef __WXCScrollContentPresenter_DEFINED__
#define __WXCScrollContentPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCScrollContentPresenter : WXCContentPresenter
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* scrollOwner;
@property BOOL canVerticallyScroll;
@property BOOL canHorizontallyScroll;
@property (readonly) double extentHeight;
@property (readonly) double extentWidth;
@property (readonly) double horizontalOffset;
@property (readonly) double verticalOffset;
@property (readonly) double viewportHeight;
@property (readonly) double viewportWidth;
- (void)lineUp;
- (void)lineDown;
- (void)lineLeft;
- (void)lineRight;
- (void)pageUp;
- (void)pageDown;
- (void)pageLeft;
- (void)pageRight;
- (void)mouseWheelUp;
- (void)mouseWheelDown;
- (void)mouseWheelLeft;
- (void)mouseWheelRight;
- (void)setHorizontalOffset:(double)offset;
- (void)setVerticalOffset:(double)offset;
- (WFRect*)makeVisible:(WXUIElement*)visual rectangle:(WFRect*)rectangle;
@end

#endif // __WXCScrollContentPresenter_DEFINED__

// Windows.UI.Xaml.Controls.SymbolIcon
#ifndef __WXCSymbolIcon_DEFINED__
#define __WXCSymbolIcon_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSymbolIcon : WXCIconElement
+ (WXCSymbolIcon*)makeInstanceWithSymbol:(WXCSymbol)symbol ACTIVATOR;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCSymbol symbol;
+ (WXDependencyProperty*)symbolProperty;
@end

#endif // __WXCSymbolIcon_DEFINED__

// Windows.UI.Xaml.Controls.SwapChainBackgroundPanel
#ifndef __WXCSwapChainBackgroundPanel_DEFINED__
#define __WXCSwapChainBackgroundPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSwapChainBackgroundPanel : WXCGrid
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WUCCoreIndependentInputSource*)createCoreIndependentInputSource:(WUCCoreInputDeviceTypes)deviceTypes;
@end

#endif // __WXCSwapChainBackgroundPanel_DEFINED__

// Windows.UI.Xaml.Controls.SwapChainPanel
#ifndef __WXCSwapChainPanel_DEFINED__
#define __WXCSwapChainPanel_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSwapChainPanel : WXCGrid
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) float compositionScaleX;
@property (readonly) float compositionScaleY;
+ (WXDependencyProperty*)compositionScaleXProperty;
+ (WXDependencyProperty*)compositionScaleYProperty;
- (EventRegistrationToken)addCompositionScaleChangedEvent:(void(^)(WXCSwapChainPanel*, RTObject*))del;
- (void)removeCompositionScaleChangedEvent:(EventRegistrationToken)tok;
- (WUCCoreIndependentInputSource*)createCoreIndependentInputSource:(WUCCoreInputDeviceTypes)deviceTypes;
@end

#endif // __WXCSwapChainPanel_DEFINED__

// Windows.UI.Xaml.Controls.WrapGrid
#ifndef __WXCWrapGrid_DEFINED__
#define __WXCWrapGrid_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWrapGrid : WUXCPOrientedVirtualizingPanel
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXVerticalAlignment verticalChildrenAlignment;
@property WXCOrientation orientation;
@property int maximumRowsOrColumns;
@property double itemWidth;
@property double itemHeight;
@property WXHorizontalAlignment horizontalChildrenAlignment;
+ (WXDependencyProperty*)horizontalChildrenAlignmentProperty;
+ (WXDependencyProperty*)itemHeightProperty;
+ (WXDependencyProperty*)itemWidthProperty;
+ (WXDependencyProperty*)maximumRowsOrColumnsProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)verticalChildrenAlignmentProperty;
@end

#endif // __WXCWrapGrid_DEFINED__

// Windows.UI.Xaml.Controls.FocusDisengagedEventArgs
#ifndef __WXCFocusDisengagedEventArgs_DEFINED__
#define __WXCFocusDisengagedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFocusDisengagedEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCFocusDisengagedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.FocusEngagedEventArgs
#ifndef __WXCFocusEngagedEventArgs_DEFINED__
#define __WXCFocusEngagedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFocusEngagedEventArgs : WXRoutedEventArgs
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL handled;
@end

#endif // __WXCFocusEngagedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ControlTemplate
#ifndef __WXCControlTemplate_DEFINED__
#define __WXCControlTemplate_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCControlTemplate : WXFrameworkTemplate
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXITypeName* targetType;
@end

#endif // __WXCControlTemplate_DEFINED__

// Windows.UI.Xaml.Controls.Control
#ifndef __WXCControl_DEFINED__
#define __WXCControl_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCControl : WXFrameworkElement
+ (BOOL)getIsTemplateFocusTarget:(WXFrameworkElement*)element;
+ (void)setIsTemplateFocusTarget:(WXFrameworkElement*)element value:(BOOL)value;
+ (BOOL)getIsTemplateKeyTipTarget:(WXDependencyObject*)element;
+ (void)setIsTemplateKeyTipTarget:(WXDependencyObject*)element value:(BOOL)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double fontSize;
@property (retain) WUXMFontFamily* fontFamily;
@property int tabIndex;
@property int characterSpacing;
@property (retain) WXThickness* borderThickness;
@property (retain) WUXMBrush* borderBrush;
@property WUTFontStretch fontStretch;
@property BOOL isTabStop;
@property BOOL isEnabled;
@property WXHorizontalAlignment horizontalContentAlignment;
@property (retain) WXThickness* padding;
@property (retain) WUXMBrush* foreground;
@property (retain) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property (retain) WUXMBrush* background;
@property WXVerticalAlignment verticalContentAlignment;
@property (retain) WXCControlTemplate* Template;
@property WUXIKeyboardNavigationMode tabNavigation;
@property (readonly) WXFocusState focusState;
@property BOOL isTextScaleFactorEnabled;
@property BOOL useSystemFocusVisuals;
@property (retain) WXDependencyObject* xYFocusDown;
@property (retain) WXDependencyObject* xYFocusUp;
@property BOOL isFocusEngagementEnabled;
@property (retain) WXDependencyObject* xYFocusLeft;
@property (retain) WXDependencyObject* xYFocusRight;
@property WXCRequiresPointer requiresPointer;
@property WXElementSoundMode elementSoundMode;
@property BOOL isFocusEngaged;
@property (retain) WFUri* defaultStyleResourceUri;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)defaultStyleKeyProperty;
+ (WXDependencyProperty*)focusStateProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)horizontalContentAlignmentProperty;
+ (WXDependencyProperty*)isEnabledProperty;
+ (WXDependencyProperty*)isTabStopProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)tabIndexProperty;
+ (WXDependencyProperty*)tabNavigationProperty;
+ (WXDependencyProperty*)templateProperty;
+ (WXDependencyProperty*)verticalContentAlignmentProperty;
+ (WXDependencyProperty*)isTextScaleFactorEnabledProperty;
+ (WXDependencyProperty*)isTemplateFocusTargetProperty;
+ (WXDependencyProperty*)useSystemFocusVisualsProperty;
+ (WXDependencyProperty*)requiresPointerProperty;
+ (WXDependencyProperty*)xYFocusDownProperty;
+ (WXDependencyProperty*)xYFocusLeftProperty;
+ (WXDependencyProperty*)xYFocusUpProperty;
+ (WXDependencyProperty*)xYFocusRightProperty;
+ (WXDependencyProperty*)elementSoundModeProperty;
+ (WXDependencyProperty*)isFocusEngagedProperty;
+ (WXDependencyProperty*)isFocusEngagementEnabledProperty;
+ (WXDependencyProperty*)isTemplateKeyTipTargetProperty;
+ (WXDependencyProperty*)defaultStyleResourceUriProperty;
- (EventRegistrationToken)addIsEnabledChangedEvent:(WXDependencyPropertyChangedEventHandler)del;
- (void)removeIsEnabledChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusDisengagedEvent:(void(^)(WXCControl*, WXCFocusDisengagedEventArgs*))del;
- (void)removeFocusDisengagedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusEngagedEvent:(void(^)(WXCControl*, WXCFocusEngagedEventArgs*))del;
- (void)removeFocusEngagedEvent:(EventRegistrationToken)tok;
- (BOOL)applyTemplate;
- (BOOL)focus:(WXFocusState)value;
- (void)onPointerEntered:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerPressed:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerMoved:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerReleased:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerExited:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCaptureLost:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerCanceled:(WUXIPointerRoutedEventArgs*)e;
- (void)onPointerWheelChanged:(WUXIPointerRoutedEventArgs*)e;
- (void)onTapped:(WUXITappedRoutedEventArgs*)e;
- (void)onDoubleTapped:(WUXIDoubleTappedRoutedEventArgs*)e;
- (void)onHolding:(WUXIHoldingRoutedEventArgs*)e;
- (void)onRightTapped:(WUXIRightTappedRoutedEventArgs*)e;
- (void)onManipulationStarting:(WUXIManipulationStartingRoutedEventArgs*)e;
- (void)onManipulationInertiaStarting:(WUXIManipulationInertiaStartingRoutedEventArgs*)e;
- (void)onManipulationStarted:(WUXIManipulationStartedRoutedEventArgs*)e;
- (void)onManipulationDelta:(WUXIManipulationDeltaRoutedEventArgs*)e;
- (void)onManipulationCompleted:(WUXIManipulationCompletedRoutedEventArgs*)e;
- (void)onKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onGotFocus:(WXRoutedEventArgs*)e;
- (void)onLostFocus:(WXRoutedEventArgs*)e;
- (void)onDragEnter:(WXDragEventArgs*)e;
- (void)onDragLeave:(WXDragEventArgs*)e;
- (void)onDragOver:(WXDragEventArgs*)e;
- (void)onDrop:(WXDragEventArgs*)e;
- (WXDependencyObject*)getTemplateChild:(NSString *)childName;
- (void)removeFocusEngagement;
- (void)onPreviewKeyDown:(WUXIKeyRoutedEventArgs*)e;
- (void)onPreviewKeyUp:(WUXIKeyRoutedEventArgs*)e;
- (void)onCharacterReceived:(WUXICharacterReceivedRoutedEventArgs*)e;
@end

#endif // __WXCControl_DEFINED__

// Windows.UI.Xaml.Controls.ColorPicker
#ifndef __WXCColorPicker_DEFINED__
#define __WXCColorPicker_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCColorPicker : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) id /* WUColor* */ previousColor;
@property int minValue;
@property int minSaturation;
@property int minHue;
@property int maxValue;
@property int maxSaturation;
@property int maxHue;
@property BOOL isMoreButtonVisible;
@property BOOL isHexInputVisible;
@property BOOL isColorSpectrumVisible;
@property BOOL isColorSliderVisible;
@property BOOL isColorPreviewVisible;
@property BOOL isColorChannelTextInputVisible;
@property BOOL isAlphaTextInputVisible;
@property BOOL isAlphaSliderVisible;
@property BOOL isAlphaEnabled;
@property WXCColorSpectrumShape colorSpectrumShape;
@property WXCColorSpectrumComponents colorSpectrumComponents;
@property (retain) WUColor* color;
+ (WXDependencyProperty*)colorProperty;
+ (WXDependencyProperty*)colorSpectrumComponentsProperty;
+ (WXDependencyProperty*)colorSpectrumShapeProperty;
+ (WXDependencyProperty*)isAlphaEnabledProperty;
+ (WXDependencyProperty*)isAlphaSliderVisibleProperty;
+ (WXDependencyProperty*)isAlphaTextInputVisibleProperty;
+ (WXDependencyProperty*)isColorChannelTextInputVisibleProperty;
+ (WXDependencyProperty*)isColorPreviewVisibleProperty;
+ (WXDependencyProperty*)isColorSliderVisibleProperty;
+ (WXDependencyProperty*)isColorSpectrumVisibleProperty;
+ (WXDependencyProperty*)isHexInputVisibleProperty;
+ (WXDependencyProperty*)isMoreButtonVisibleProperty;
+ (WXDependencyProperty*)maxHueProperty;
+ (WXDependencyProperty*)maxSaturationProperty;
+ (WXDependencyProperty*)maxValueProperty;
+ (WXDependencyProperty*)minHueProperty;
+ (WXDependencyProperty*)minSaturationProperty;
+ (WXDependencyProperty*)minValueProperty;
+ (WXDependencyProperty*)previousColorProperty;
- (EventRegistrationToken)addColorChangedEvent:(void(^)(WXCColorPicker*, WXCColorChangedEventArgs*))del;
- (void)removeColorChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCColorPicker_DEFINED__

// Windows.UI.Xaml.Controls.PersonPicture
#ifndef __WXCPersonPicture_DEFINED__
#define __WXCPersonPicture_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPersonPicture : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMImageSource* profilePicture;
@property BOOL preferSmallImage;
@property BOOL isGroup;
@property (retain) NSString * initials;
@property (retain) NSString * displayName;
@property (retain) WACContact* contact;
@property (retain) NSString * badgeText;
@property int badgeNumber;
@property (retain) WUXMImageSource* badgeImageSource;
@property (retain) NSString * badgeGlyph;
+ (WXDependencyProperty*)badgeGlyphProperty;
+ (WXDependencyProperty*)badgeImageSourceProperty;
+ (WXDependencyProperty*)badgeNumberProperty;
+ (WXDependencyProperty*)badgeTextProperty;
+ (WXDependencyProperty*)contactProperty;
+ (WXDependencyProperty*)displayNameProperty;
+ (WXDependencyProperty*)initialsProperty;
+ (WXDependencyProperty*)isGroupProperty;
+ (WXDependencyProperty*)preferSmallImageProperty;
+ (WXDependencyProperty*)profilePictureProperty;
@end

#endif // __WXCPersonPicture_DEFINED__

// Windows.UI.Xaml.Controls.RatingControl
#ifndef __WXCRatingControl_DEFINED__
#define __WXCRatingControl_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRatingControl : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double value;
@property double placeholderValue;
@property int maxRating;
@property (retain) WXCRatingItemInfo* itemInfo;
@property BOOL isReadOnly;
@property BOOL isClearEnabled;
@property int initialSetValue;
@property (retain) NSString * caption;
+ (WXDependencyProperty*)captionProperty;
+ (WXDependencyProperty*)initialSetValueProperty;
+ (WXDependencyProperty*)isClearEnabledProperty;
+ (WXDependencyProperty*)isReadOnlyProperty;
+ (WXDependencyProperty*)itemInfoProperty;
+ (WXDependencyProperty*)maxRatingProperty;
+ (WXDependencyProperty*)placeholderValueProperty;
+ (WXDependencyProperty*)valueProperty;
- (EventRegistrationToken)addValueChangedEvent:(void(^)(WXCRatingControl*, RTObject*))del;
- (void)removeValueChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCRatingControl_DEFINED__

// Windows.UI.Xaml.Controls.SemanticZoom
#ifndef __WXCSemanticZoom_DEFINED__
#define __WXCSemanticZoom_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSemanticZoom : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject<WXCISemanticZoomInformation>* zoomedOutView;
@property (retain) RTObject<WXCISemanticZoomInformation>* zoomedInView;
@property BOOL isZoomedInViewActive;
@property BOOL isZoomOutButtonEnabled;
@property BOOL canChangeViews;
+ (WXDependencyProperty*)canChangeViewsProperty;
+ (WXDependencyProperty*)isZoomOutButtonEnabledProperty;
+ (WXDependencyProperty*)isZoomedInViewActiveProperty;
+ (WXDependencyProperty*)zoomedInViewProperty;
+ (WXDependencyProperty*)zoomedOutViewProperty;
- (EventRegistrationToken)addViewChangeCompletedEvent:(WXCSemanticZoomViewChangedEventHandler)del;
- (void)removeViewChangeCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addViewChangeStartedEvent:(WXCSemanticZoomViewChangedEventHandler)del;
- (void)removeViewChangeStartedEvent:(EventRegistrationToken)tok;
- (void)toggleActiveView;
@end

#endif // __WXCSemanticZoom_DEFINED__

// Windows.UI.Xaml.Controls.ContentControl
#ifndef __WXCContentControl_DEFINED__
#define __WXCContentControl_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentControl : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMATransitionCollection* contentTransitions;
@property (retain) WXCDataTemplateSelector* contentTemplateSelector;
@property (retain) WXDataTemplate* contentTemplate;
@property (retain) RTObject* content;
@property (readonly) WXUIElement* contentTemplateRoot;
+ (WXDependencyProperty*)contentProperty;
+ (WXDependencyProperty*)contentTemplateProperty;
+ (WXDependencyProperty*)contentTemplateSelectorProperty;
+ (WXDependencyProperty*)contentTransitionsProperty;
- (void)onContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

#endif // __WXCContentControl_DEFINED__

// Windows.UI.Xaml.Controls.NavigationView
#ifndef __WXCNavigationView_DEFINED__
#define __WXCNavigationView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationView : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* selectedItem;
@property (retain) WXStyle* paneToggleButtonStyle;
@property (retain) WXUIElement* paneFooter;
@property double openPaneLength;
@property (retain) RTObject* menuItemsSource;
@property (retain) WXCDataTemplateSelector* menuItemTemplateSelector;
@property (retain) WXDataTemplate* menuItemTemplate;
@property (retain) WXCStyleSelector* menuItemContainerStyleSelector;
@property (retain) WXStyle* menuItemContainerStyle;
@property BOOL isSettingsVisible;
@property BOOL isPaneToggleButtonVisible;
@property BOOL isPaneOpen;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property double expandedModeThresholdWidth;
@property double compactPaneLength;
@property double compactModeThresholdWidth;
@property (retain) WXCAutoSuggestBox* autoSuggestBox;
@property BOOL alwaysShowHeader;
@property (readonly) WXCNavigationViewDisplayMode displayMode;
@property (readonly) NSMutableArray* /* RTObject* */ menuItems;
@property (readonly) RTObject* settingsItem;
+ (WXDependencyProperty*)alwaysShowHeaderProperty;
+ (WXDependencyProperty*)autoSuggestBoxProperty;
+ (WXDependencyProperty*)compactModeThresholdWidthProperty;
+ (WXDependencyProperty*)compactPaneLengthProperty;
+ (WXDependencyProperty*)displayModeProperty;
+ (WXDependencyProperty*)expandedModeThresholdWidthProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isPaneOpenProperty;
+ (WXDependencyProperty*)isPaneToggleButtonVisibleProperty;
+ (WXDependencyProperty*)isSettingsVisibleProperty;
+ (WXDependencyProperty*)menuItemContainerStyleProperty;
+ (WXDependencyProperty*)menuItemContainerStyleSelectorProperty;
+ (WXDependencyProperty*)menuItemTemplateProperty;
+ (WXDependencyProperty*)menuItemTemplateSelectorProperty;
+ (WXDependencyProperty*)menuItemsProperty;
+ (WXDependencyProperty*)menuItemsSourceProperty;
+ (WXDependencyProperty*)openPaneLengthProperty;
+ (WXDependencyProperty*)paneFooterProperty;
+ (WXDependencyProperty*)paneToggleButtonStyleProperty;
+ (WXDependencyProperty*)selectedItemProperty;
+ (WXDependencyProperty*)settingsItemProperty;
- (EventRegistrationToken)addDisplayModeChangedEvent:(void(^)(WXCNavigationView*, WXCNavigationViewDisplayModeChangedEventArgs*))del;
- (void)removeDisplayModeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemInvokedEvent:(void(^)(WXCNavigationView*, WXCNavigationViewItemInvokedEventArgs*))del;
- (void)removeItemInvokedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(void(^)(WXCNavigationView*, WXCNavigationViewSelectionChangedEventArgs*))del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)menuItemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromMenuItem:(RTObject*)item;
@end

#endif // __WXCNavigationView_DEFINED__

// Windows.UI.Xaml.Controls.SwipeControl
#ifndef __WXCSwipeControl_DEFINED__
#define __WXCSwipeControl_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSwipeControl : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCSwipeItems* topItems;
@property (retain) WXCSwipeItems* rightItems;
@property (retain) WXCSwipeItems* leftItems;
@property (retain) WXCSwipeItems* bottomItems;
+ (WXDependencyProperty*)bottomItemsProperty;
+ (WXDependencyProperty*)leftItemsProperty;
+ (WXDependencyProperty*)rightItemsProperty;
+ (WXDependencyProperty*)topItemsProperty;
- (void)close;
@end

#endif // __WXCSwipeControl_DEFINED__

// Windows.UI.Xaml.Controls.ListViewBaseHeaderItem
#ifndef __WXCListViewBaseHeaderItem_DEFINED__
#define __WXCListViewBaseHeaderItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListViewBaseHeaderItem : WXCContentControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCListViewBaseHeaderItem_DEFINED__

// Windows.UI.Xaml.Controls.ItemsControl
#ifndef __WXCItemsControl_DEFINED__
#define __WXCItemsControl_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemsControl : WXCControl <WXCIItemContainerMapping>
+ (WXCItemsControl*)getItemsOwner:(WXDependencyObject*)element;
+ (WXCItemsControl*)itemsControlFromItemContainer:(WXDependencyObject*)container;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCItemsPanelTemplate* itemsPanel;
@property (retain) RTObject* itemsSource;
@property (retain) WXCDataTemplateSelector* itemTemplateSelector;
@property (retain) WXDataTemplate* itemTemplate;
@property (retain) WXCStyleSelector* itemContainerStyleSelector;
@property (retain) WXStyle* itemContainerStyle;
@property (retain) WXCGroupStyleSelector* groupStyleSelector;
@property (retain) WUXMATransitionCollection* itemContainerTransitions;
@property (retain) NSString * displayMemberPath;
@property (readonly) WXCItemContainerGenerator* itemContainerGenerator;
@property (readonly) WXCItemCollection* items;
@property (readonly) NSMutableArray<RTObservableCollection>* /* WXCGroupStyle* */ groupStyle;
@property (readonly) BOOL isGrouping;
@property (readonly) WXCPanel* itemsPanelRoot;
+ (WXDependencyProperty*)displayMemberPathProperty;
+ (WXDependencyProperty*)groupStyleSelectorProperty;
+ (WXDependencyProperty*)isGroupingProperty;
+ (WXDependencyProperty*)itemContainerStyleProperty;
+ (WXDependencyProperty*)itemContainerStyleSelectorProperty;
+ (WXDependencyProperty*)itemContainerTransitionsProperty;
+ (WXDependencyProperty*)itemTemplateProperty;
+ (WXDependencyProperty*)itemTemplateSelectorProperty;
+ (WXDependencyProperty*)itemsPanelProperty;
+ (WXDependencyProperty*)itemsSourceProperty;
- (BOOL)isItemItsOwnContainerOverride:(RTObject*)item;
- (WXDependencyObject*)getContainerForItemOverride;
- (void)clearContainerForItemOverride:(WXDependencyObject*)element item:(RTObject*)item;
- (void)prepareContainerForItemOverride:(WXDependencyObject*)element item:(RTObject*)item;
- (void)onItemsChanged:(RTObject*)e;
- (void)onItemContainerStyleChanged:(WXStyle*)oldItemContainerStyle newItemContainerStyle:(WXStyle*)newItemContainerStyle;
- (void)onItemContainerStyleSelectorChanged:(WXCStyleSelector*)oldItemContainerStyleSelector newItemContainerStyleSelector:(WXCStyleSelector*)newItemContainerStyleSelector;
- (void)onItemTemplateChanged:(WXDataTemplate*)oldItemTemplate newItemTemplate:(WXDataTemplate*)newItemTemplate;
- (void)onItemTemplateSelectorChanged:(WXCDataTemplateSelector*)oldItemTemplateSelector newItemTemplateSelector:(WXCDataTemplateSelector*)newItemTemplateSelector;
- (void)onGroupStyleSelectorChanged:(WXCGroupStyleSelector*)oldGroupStyleSelector newGroupStyleSelector:(WXCGroupStyleSelector*)newGroupStyleSelector;
- (RTObject*)itemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromItem:(RTObject*)item;
- (int)indexFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromIndex:(int)index;
- (WXDependencyObject*)groupHeaderContainerFromItemContainer:(WXDependencyObject*)itemContainer;
@end

#endif // __WXCItemsControl_DEFINED__

// Windows.UI.Xaml.Controls.MediaTransportControls
#ifndef __WXCMediaTransportControls_DEFINED__
#define __WXCMediaTransportControls_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMediaTransportControls : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isFullWindowEnabled;
@property BOOL isFullWindowButtonVisible;
@property BOOL isFastRewindEnabled;
@property BOOL isFastRewindButtonVisible;
@property BOOL isFastForwardEnabled;
@property BOOL isFastForwardButtonVisible;
@property BOOL isVolumeButtonVisible;
@property BOOL isCompact;
@property BOOL isStopEnabled;
@property BOOL isStopButtonVisible;
@property BOOL isSeekBarVisible;
@property BOOL isPlaybackRateEnabled;
@property BOOL isPlaybackRateButtonVisible;
@property BOOL isSeekEnabled;
@property BOOL isZoomEnabled;
@property BOOL isZoomButtonVisible;
@property BOOL isVolumeEnabled;
@property BOOL isPreviousTrackButtonVisible;
@property BOOL isNextTrackButtonVisible;
@property WUXMFastPlayFallbackBehaviour fastPlayFallbackBehaviour;
@property BOOL isSkipForwardEnabled;
@property BOOL isSkipForwardButtonVisible;
@property BOOL isSkipBackwardEnabled;
@property BOOL isSkipBackwardButtonVisible;
@property BOOL showAndHideAutomatically;
@property BOOL isRepeatEnabled;
@property BOOL isRepeatButtonVisible;
+ (WXDependencyProperty*)isSeekEnabledProperty;
+ (WXDependencyProperty*)isCompactProperty;
+ (WXDependencyProperty*)isFastForwardButtonVisibleProperty;
+ (WXDependencyProperty*)isFastForwardEnabledProperty;
+ (WXDependencyProperty*)isFastRewindButtonVisibleProperty;
+ (WXDependencyProperty*)isFastRewindEnabledProperty;
+ (WXDependencyProperty*)isFullWindowButtonVisibleProperty;
+ (WXDependencyProperty*)isFullWindowEnabledProperty;
+ (WXDependencyProperty*)isPlaybackRateButtonVisibleProperty;
+ (WXDependencyProperty*)isPlaybackRateEnabledProperty;
+ (WXDependencyProperty*)isSeekBarVisibleProperty;
+ (WXDependencyProperty*)isStopButtonVisibleProperty;
+ (WXDependencyProperty*)isStopEnabledProperty;
+ (WXDependencyProperty*)isVolumeButtonVisibleProperty;
+ (WXDependencyProperty*)isVolumeEnabledProperty;
+ (WXDependencyProperty*)isZoomButtonVisibleProperty;
+ (WXDependencyProperty*)isZoomEnabledProperty;
+ (WXDependencyProperty*)isNextTrackButtonVisibleProperty;
+ (WXDependencyProperty*)fastPlayFallbackBehaviourProperty;
+ (WXDependencyProperty*)isPreviousTrackButtonVisibleProperty;
+ (WXDependencyProperty*)isSkipBackwardButtonVisibleProperty;
+ (WXDependencyProperty*)isSkipBackwardEnabledProperty;
+ (WXDependencyProperty*)isSkipForwardButtonVisibleProperty;
+ (WXDependencyProperty*)isSkipForwardEnabledProperty;
+ (WXDependencyProperty*)isRepeatEnabledProperty;
+ (WXDependencyProperty*)showAndHideAutomaticallyProperty;
+ (WXDependencyProperty*)isRepeatButtonVisibleProperty;
- (EventRegistrationToken)addThumbnailRequestedEvent:(void(^)(WXCMediaTransportControls*, WUXMMediaTransportControlsThumbnailRequestedEventArgs*))del;
- (void)removeThumbnailRequestedEvent:(EventRegistrationToken)tok;
- (void)show;
- (void)hide;
@end

#endif // __WXCMediaTransportControls_DEFINED__

// Windows.UI.Xaml.Controls.PasswordBox
#ifndef __WXCPasswordBox_DEFINED__
#define __WXCPasswordBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPasswordBox : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * passwordChar;
@property (retain) NSString * password;
@property int maxLength;
@property BOOL isPasswordRevealButtonEnabled;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property (retain) WUXMSolidColorBrush* selectionHighlightColor;
@property BOOL preventKeyboardDisplayOnProgrammaticFocus;
@property (retain) NSString * placeholderText;
@property WXTextReadingOrder textReadingOrder;
@property WXCPasswordRevealMode passwordRevealMode;
@property (retain) WUXIInputScope* inputScope;
+ (WXDependencyProperty*)passwordProperty;
+ (WXDependencyProperty*)passwordCharProperty;
+ (WXDependencyProperty*)maxLengthProperty;
+ (WXDependencyProperty*)isPasswordRevealButtonEnabledProperty;
+ (WXDependencyProperty*)preventKeyboardDisplayOnProgrammaticFocusProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)textReadingOrderProperty;
+ (WXDependencyProperty*)passwordRevealModeProperty;
+ (WXDependencyProperty*)inputScopeProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasswordChangedEvent:(WXRoutedEventHandler)del;
- (void)removePasswordChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasteEvent:(WXCTextControlPasteEventHandler)del;
- (void)removePasteEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasswordChangingEvent:(void(^)(WXCPasswordBox*, WXCPasswordBoxPasswordChangingEventArgs*))del;
- (void)removePasswordChangingEvent:(EventRegistrationToken)tok;
- (void)selectAll;
@end

#endif // __WXCPasswordBox_DEFINED__

// Windows.UI.Xaml.Controls.ProgressRing
#ifndef __WXCProgressRing_DEFINED__
#define __WXCProgressRing_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCProgressRing : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isActive;
@property (readonly) WUXCPProgressRingTemplateSettings* templateSettings;
+ (WXDependencyProperty*)isActiveProperty;
@end

#endif // __WXCProgressRing_DEFINED__

// Windows.UI.Xaml.Controls.TextBox
#ifndef __WXCTextBox_DEFINED__
#define __WXCTextBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTextBox : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property int maxLength;
@property BOOL isTextPredictionEnabled;
@property BOOL isSpellCheckEnabled;
@property BOOL isReadOnly;
@property (retain) WUXIInputScope* inputScope;
@property BOOL acceptsReturn;
@property (retain) NSString * selectedText;
@property WXTextWrapping textWrapping;
@property WXTextAlignment textAlignment;
@property (retain) NSString * text;
@property int selectionStart;
@property int selectionLength;
@property (retain) WUXMSolidColorBrush* selectionHighlightColor;
@property BOOL preventKeyboardDisplayOnProgrammaticFocus;
@property (retain) NSString * placeholderText;
@property BOOL isColorFontEnabled;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property WXTextReadingOrder textReadingOrder;
@property WXCCandidateWindowAlignment desiredCandidateWindowAlignment;
@property (retain) WUXMSolidColorBrush* selectionHighlightColorWhenNotFocused;
@property (retain) WUXMBrush* placeholderForeground;
@property WXTextAlignment horizontalTextAlignment;
@property WXCCharacterCasing characterCasing;
+ (WXDependencyProperty*)textWrappingProperty;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)maxLengthProperty;
+ (WXDependencyProperty*)isTextPredictionEnabledProperty;
+ (WXDependencyProperty*)isSpellCheckEnabledProperty;
+ (WXDependencyProperty*)inputScopeProperty;
+ (WXDependencyProperty*)acceptsReturnProperty;
+ (WXDependencyProperty*)isReadOnlyProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)preventKeyboardDisplayOnProgrammaticFocusProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)textReadingOrderProperty;
+ (WXDependencyProperty*)desiredCandidateWindowAlignmentProperty;
+ (WXDependencyProperty*)selectionHighlightColorWhenNotFocusedProperty;
+ (WXDependencyProperty*)placeholderForegroundProperty;
+ (WXDependencyProperty*)horizontalTextAlignmentProperty;
+ (WXDependencyProperty*)characterCasingProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextChangedEvent:(WXCTextChangedEventHandler)del;
- (void)removeTextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasteEvent:(WXCTextControlPasteEventHandler)del;
- (void)removePasteEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCandidateWindowBoundsChangedEvent:(void(^)(WXCTextBox*, WXCCandidateWindowBoundsChangedEventArgs*))del;
- (void)removeCandidateWindowBoundsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextChangingEvent:(void(^)(WXCTextBox*, WXCTextBoxTextChangingEventArgs*))del;
- (void)removeTextChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextCompositionChangedEvent:(void(^)(WXCTextBox*, WXCTextCompositionChangedEventArgs*))del;
- (void)removeTextCompositionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextCompositionEndedEvent:(void(^)(WXCTextBox*, WXCTextCompositionEndedEventArgs*))del;
- (void)removeTextCompositionEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextCompositionStartedEvent:(void(^)(WXCTextBox*, WXCTextCompositionStartedEventArgs*))del;
- (void)removeTextCompositionStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addBeforeTextChangingEvent:(void(^)(WXCTextBox*, WXCTextBoxBeforeTextChangingEventArgs*))del;
- (void)removeBeforeTextChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCopyingToClipboardEvent:(void(^)(WXCTextBox*, WXCTextControlCopyingToClipboardEventArgs*))del;
- (void)removeCopyingToClipboardEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCuttingToClipboardEvent:(void(^)(WXCTextBox*, WXCTextControlCuttingToClipboardEventArgs*))del;
- (void)removeCuttingToClipboardEvent:(EventRegistrationToken)tok;
- (void)select:(int)start length:(int)length;
- (void)selectAll;
- (WFRect*)getRectFromCharacterIndex:(int)charIndex trailingEdge:(BOOL)trailingEdge;
- (void)getLinguisticAlternativesAsyncWithSuccess:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXCTextBox_DEFINED__

// Windows.UI.Xaml.Controls.ToggleSwitch
#ifndef __WXCToggleSwitch_DEFINED__
#define __WXCToggleSwitch_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCToggleSwitch : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXDataTemplate* onContentTemplate;
@property (retain) RTObject* onContent;
@property (retain) WXDataTemplate* offContentTemplate;
@property (retain) RTObject* offContent;
@property BOOL isOn;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property (readonly) WUXCPToggleSwitchTemplateSettings* templateSettings;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isOnProperty;
+ (WXDependencyProperty*)offContentProperty;
+ (WXDependencyProperty*)offContentTemplateProperty;
+ (WXDependencyProperty*)onContentProperty;
+ (WXDependencyProperty*)onContentTemplateProperty;
- (EventRegistrationToken)addToggledEvent:(WXRoutedEventHandler)del;
- (void)removeToggledEvent:(EventRegistrationToken)tok;
- (void)onToggled;
- (void)onOnContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onOffContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onHeaderChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
@end

#endif // __WXCToggleSwitch_DEFINED__

// Windows.UI.Xaml.Controls.UserControl
#ifndef __WXCUserControl_DEFINED__
#define __WXCUserControl_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCUserControl : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXUIElement* content;
+ (WXDependencyProperty*)contentProperty;
@end

#endif // __WXCUserControl_DEFINED__

// Windows.UI.Xaml.Controls.GroupItem
#ifndef __WXCGroupItem_DEFINED__
#define __WXCGroupItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCGroupItem : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCGroupItem_DEFINED__

// Windows.UI.Xaml.Controls.SettingsFlyout
#ifndef __WXCSettingsFlyout_DEFINED__
#define __WXCSettingsFlyout_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSettingsFlyout : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * title;
@property (retain) WUXMImageSource* iconSource;
@property (retain) WUXMBrush* headerForeground;
@property (retain) WUXMBrush* headerBackground;
@property (readonly) WUXCPSettingsFlyoutTemplateSettings* templateSettings;
+ (WXDependencyProperty*)headerBackgroundProperty;
+ (WXDependencyProperty*)headerForegroundProperty;
+ (WXDependencyProperty*)iconSourceProperty;
+ (WXDependencyProperty*)titleProperty;
- (EventRegistrationToken)addBackClickEvent:(WXCBackClickEventHandler)del;
- (void)removeBackClickEvent:(EventRegistrationToken)tok;
- (void)show;
- (void)showIndependent;
- (void)hide;
@end

#endif // __WXCSettingsFlyout_DEFINED__

// Windows.UI.Xaml.Controls.ToolTip
#ifndef __WXCToolTip_DEFINED__
#define __WXCToolTip_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCToolTip : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double verticalOffset;
@property (retain) WXUIElement* placementTarget;
@property WUXCPPlacementMode placement;
@property BOOL isOpen;
@property double horizontalOffset;
@property (readonly) WUXCPToolTipTemplateSettings* templateSettings;
+ (WXDependencyProperty*)horizontalOffsetProperty;
+ (WXDependencyProperty*)isOpenProperty;
+ (WXDependencyProperty*)placementProperty;
+ (WXDependencyProperty*)placementTargetProperty;
+ (WXDependencyProperty*)verticalOffsetProperty;
- (EventRegistrationToken)addClosedEvent:(WXRoutedEventHandler)del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(WXRoutedEventHandler)del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCToolTip_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.SelectorItem
#ifndef __WUXCPSelectorItem_DEFINED__
#define __WUXCPSelectorItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPSelectorItem : WXCContentControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isSelected;
+ (WXDependencyProperty*)isSelectedProperty;
@end

#endif // __WUXCPSelectorItem_DEFINED__

// Windows.UI.Xaml.Controls.ComboBoxItem
#ifndef __WXCComboBoxItem_DEFINED__
#define __WXCComboBoxItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCComboBoxItem : WUXCPSelectorItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCComboBoxItem_DEFINED__

// Windows.UI.Xaml.Controls.FlipViewItem
#ifndef __WXCFlipViewItem_DEFINED__
#define __WXCFlipViewItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFlipViewItem : WUXCPSelectorItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCFlipViewItem_DEFINED__

// Windows.UI.Xaml.Controls.ListBoxItem
#ifndef __WXCListBoxItem_DEFINED__
#define __WXCListBoxItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListBoxItem : WUXCPSelectorItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCListBoxItem_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IRangeBaseOverrides
#ifndef __WUXCPIRangeBaseOverrides_DEFINED__
#define __WUXCPIRangeBaseOverrides_DEFINED__

@protocol WUXCPIRangeBaseOverrides
- (void)onMinimumChanged:(double)oldMinimum newMinimum:(double)newMinimum;
- (void)onMaximumChanged:(double)oldMaximum newMaximum:(double)newMaximum;
- (void)onValueChanged:(double)oldValue newValue:(double)newValue;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPIRangeBaseOverrides : RTObject <WUXCPIRangeBaseOverrides>
@end

#endif // __WUXCPIRangeBaseOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.RangeBase
#ifndef __WUXCPRangeBase_DEFINED__
#define __WUXCPRangeBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPRangeBase : WXCControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double value;
@property double smallChange;
@property double minimum;
@property double maximum;
@property double largeChange;
+ (WXDependencyProperty*)largeChangeProperty;
+ (WXDependencyProperty*)maximumProperty;
+ (WXDependencyProperty*)minimumProperty;
+ (WXDependencyProperty*)smallChangeProperty;
+ (WXDependencyProperty*)valueProperty;
- (EventRegistrationToken)addValueChangedEvent:(WUXCPRangeBaseValueChangedEventHandler)del;
- (void)removeValueChangedEvent:(EventRegistrationToken)tok;
- (void)onMinimumChanged:(double)oldMinimum newMinimum:(double)newMinimum;
- (void)onMaximumChanged:(double)oldMaximum newMaximum:(double)newMaximum;
- (void)onValueChanged:(double)oldValue newValue:(double)newValue;
@end

#endif // __WUXCPRangeBase_DEFINED__

// Windows.UI.Xaml.Controls.ProgressBar
#ifndef __WXCProgressBar_DEFINED__
#define __WXCProgressBar_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCProgressBar : WUXCPRangeBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL showPaused;
@property BOOL showError;
@property BOOL isIndeterminate;
@property (readonly) WUXCPProgressBarTemplateSettings* templateSettings;
+ (WXDependencyProperty*)isIndeterminateProperty;
+ (WXDependencyProperty*)showErrorProperty;
+ (WXDependencyProperty*)showPausedProperty;
@end

#endif // __WXCProgressBar_DEFINED__

// Windows.UI.Xaml.Controls.Slider
#ifndef __WXCSlider_DEFINED__
#define __WXCSlider_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSlider : WUXCPRangeBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double stepFrequency;
@property WUXCPSliderSnapsTo snapsTo;
@property WXCOrientation orientation;
@property BOOL isThumbToolTipEnabled;
@property BOOL isDirectionReversed;
@property double intermediateValue;
@property WUXCPTickPlacement tickPlacement;
@property double tickFrequency;
@property (retain) RTObject<WUXDIValueConverter>* thumbToolTipValueConverter;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
+ (WXDependencyProperty*)intermediateValueProperty;
+ (WXDependencyProperty*)isDirectionReversedProperty;
+ (WXDependencyProperty*)isThumbToolTipEnabledProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)snapsToProperty;
+ (WXDependencyProperty*)stepFrequencyProperty;
+ (WXDependencyProperty*)thumbToolTipValueConverterProperty;
+ (WXDependencyProperty*)tickFrequencyProperty;
+ (WXDependencyProperty*)tickPlacementProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)headerProperty;
@end

#endif // __WXCSlider_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ButtonBase
#ifndef __WUXCPButtonBase_DEFINED__
#define __WUXCPButtonBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPButtonBase : WXCContentControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* commandParameter;
@property (retain) RTObject<WUXIICommand>* command;
@property WXCClickMode clickMode;
@property (readonly) BOOL isPointerOver;
@property (readonly) BOOL isPressed;
+ (WXDependencyProperty*)clickModeProperty;
+ (WXDependencyProperty*)commandParameterProperty;
+ (WXDependencyProperty*)commandProperty;
+ (WXDependencyProperty*)isPointerOverProperty;
+ (WXDependencyProperty*)isPressedProperty;
- (EventRegistrationToken)addClickEvent:(WXRoutedEventHandler)del;
- (void)removeClickEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCPButtonBase_DEFINED__

// Windows.UI.Xaml.Controls.Button
#ifndef __WXCButton_DEFINED__
#define __WXCButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCButton : WUXCPButtonBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXCPFlyoutBase* flyout;
+ (WXDependencyProperty*)flyoutProperty;
@end

#endif // __WXCButton_DEFINED__

// Windows.UI.Xaml.Controls.HyperlinkButton
#ifndef __WXCHyperlinkButton_DEFINED__
#define __WXCHyperlinkButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCHyperlinkButton : WUXCPButtonBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFUri* navigateUri;
+ (WXDependencyProperty*)navigateUriProperty;
@end

#endif // __WXCHyperlinkButton_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.Selector
#ifndef __WUXCPSelector_DEFINED__
#define __WUXCPSelector_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPSelector : WXCItemsControl
+ (BOOL)getIsSelectionActive:(WXDependencyObject*)element;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * selectedValuePath;
@property (retain) RTObject* selectedValue;
@property (retain) RTObject* selectedItem;
@property int selectedIndex;
@property (retain) id /* BOOL */ isSynchronizedWithCurrentItem;
+ (WXDependencyProperty*)isSynchronizedWithCurrentItemProperty;
+ (WXDependencyProperty*)selectedIndexProperty;
+ (WXDependencyProperty*)selectedItemProperty;
+ (WXDependencyProperty*)selectedValuePathProperty;
+ (WXDependencyProperty*)selectedValueProperty;
- (EventRegistrationToken)addSelectionChangedEvent:(WXCSelectionChangedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCPSelector_DEFINED__

// Windows.UI.Xaml.Controls.ListViewBase
#ifndef __WXCListViewBase_DEFINED__
#define __WXCListViewBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListViewBase : WUXCPSelector <WXCISemanticZoomInformation>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCListViewSelectionMode selectionMode;
@property BOOL isSwipeEnabled;
@property BOOL isItemClickEnabled;
@property WXCIncrementalLoadingTrigger incrementalLoadingTrigger;
@property double incrementalLoadingThreshold;
@property BOOL canDragItems;
@property (retain) WUXMATransitionCollection* headerTransitions;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property double dataFetchSize;
@property BOOL canReorderItems;
@property (readonly) NSMutableArray* /* RTObject* */ selectedItems;
@property (retain) RTObject* footer;
@property (retain) WXDataTemplate* footerTemplate;
@property BOOL showsScrollingPlaceholders;
@property (retain) WUXMATransitionCollection* footerTransitions;
@property WXCListViewReorderMode reorderMode;
@property BOOL isMultiSelectCheckBoxEnabled;
@property (readonly) NSArray* /* WUXDItemIndexRange* */ selectedRanges;
@property BOOL singleSelectionFollowsFocus;
@property (retain) WXCSemanticZoom* semanticZoomOwner;
@property BOOL isZoomedInView;
@property BOOL isActiveView;
+ (WXDependencyProperty*)isSwipeEnabledProperty;
+ (WXDependencyProperty*)canDragItemsProperty;
+ (WXDependencyProperty*)canReorderItemsProperty;
+ (WXDependencyProperty*)dataFetchSizeProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)headerTransitionsProperty;
+ (WXDependencyProperty*)incrementalLoadingThresholdProperty;
+ (WXDependencyProperty*)incrementalLoadingTriggerProperty;
+ (WXDependencyProperty*)isActiveViewProperty;
+ (WXDependencyProperty*)isItemClickEnabledProperty;
+ (WXDependencyProperty*)isZoomedInViewProperty;
+ (WXDependencyProperty*)selectionModeProperty;
+ (WXDependencyProperty*)semanticZoomOwnerProperty;
+ (WXDependencyProperty*)footerProperty;
+ (WXDependencyProperty*)footerTemplateProperty;
+ (WXDependencyProperty*)footerTransitionsProperty;
+ (WXDependencyProperty*)showsScrollingPlaceholdersProperty;
+ (WXDependencyProperty*)reorderModeProperty;
+ (WXDependencyProperty*)isMultiSelectCheckBoxEnabledProperty;
+ (WXDependencyProperty*)singleSelectionFollowsFocusProperty;
- (EventRegistrationToken)addDragItemsStartingEvent:(WXCDragItemsStartingEventHandler)del;
- (void)removeDragItemsStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemClickEvent:(WXCItemClickEventHandler)del;
- (void)removeItemClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContainerContentChangingEvent:(void(^)(WXCListViewBase*, WXCContainerContentChangingEventArgs*))del;
- (void)removeContainerContentChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addChoosingGroupHeaderContainerEvent:(void(^)(WXCListViewBase*, WXCChoosingGroupHeaderContainerEventArgs*))del;
- (void)removeChoosingGroupHeaderContainerEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addChoosingItemContainerEvent:(void(^)(WXCListViewBase*, WXCChoosingItemContainerEventArgs*))del;
- (void)removeChoosingItemContainerEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragItemsCompletedEvent:(void(^)(WXCListViewBase*, WXCDragItemsCompletedEventArgs*))del;
- (void)removeDragItemsCompletedEvent:(EventRegistrationToken)tok;
- (void)scrollIntoView:(RTObject*)item;
- (void)selectAll;
- (void)loadMoreItemsAsyncWithSuccess:(void (^)(WUXDLoadMoreItemsResult*))success failure:(void (^)(NSError*))failure;
- (void)scrollIntoViewWithAlignment:(RTObject*)item alignment:(WXCScrollIntoViewAlignment)alignment;
- (void)initializeViewChange;
- (void)completeViewChange;
- (void)makeVisible:(WXCSemanticZoomLocation*)item;
- (void)startViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)startViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)setDesiredContainerUpdateDuration:(WFTimeSpan*)duration;
- (void)selectRange:(WUXDItemIndexRange*)itemIndexRange;
- (void)deselectRange:(WUXDItemIndexRange*)itemIndexRange;
- (BOOL)isDragSource;
- (void)tryStartConnectedAnimationAsync:(WUXMAConnectedAnimation*)animation item:(RTObject*)item elementName:(NSString *)elementName success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
- (WUXMAConnectedAnimation*)prepareConnectedAnimation:(NSString *)key item:(RTObject*)item elementName:(NSString *)elementName;
@end

#endif // __WXCListViewBase_DEFINED__

// Windows.UI.Xaml.Controls.ComboBox
#ifndef __WXCComboBox_DEFINED__
#define __WXCComboBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCComboBox : WUXCPSelector
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double maxDropDownHeight;
@property BOOL isDropDownOpen;
@property (readonly) BOOL isEditable;
@property (readonly) BOOL isSelectionBoxHighlighted;
@property (readonly) RTObject* selectionBoxItem;
@property (readonly) WXDataTemplate* selectionBoxItemTemplate;
@property (readonly) WUXCPComboBoxTemplateSettings* templateSettings;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) NSString * placeholderText;
@property (retain) RTObject* header;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
@property BOOL isTextSearchEnabled;
@property WXCComboBoxSelectionChangedTrigger selectionChangedTrigger;
@property (retain) WUXMBrush* placeholderForeground;
+ (WXDependencyProperty*)isDropDownOpenProperty;
+ (WXDependencyProperty*)maxDropDownHeightProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)isTextSearchEnabledProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
+ (WXDependencyProperty*)selectionChangedTriggerProperty;
+ (WXDependencyProperty*)placeholderForegroundProperty;
- (EventRegistrationToken)addDropDownClosedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeDropDownClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropDownOpenedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeDropDownOpenedEvent:(EventRegistrationToken)tok;
- (void)onDropDownClosed:(RTObject*)e;
- (void)onDropDownOpened:(RTObject*)e;
@end

#endif // __WXCComboBox_DEFINED__

// Windows.UI.Xaml.Controls.FlipView
#ifndef __WXCFlipView_DEFINED__
#define __WXCFlipView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFlipView : WUXCPSelector
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL useTouchAnimationsForAllNavigation;
+ (WXDependencyProperty*)useTouchAnimationsForAllNavigationProperty;
@end

#endif // __WXCFlipView_DEFINED__

// Windows.UI.Xaml.Controls.ListBox
#ifndef __WXCListBox_DEFINED__
#define __WXCListBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListBox : WUXCPSelector
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCSelectionMode selectionMode;
@property (readonly) NSMutableArray* /* RTObject* */ selectedItems;
@property BOOL singleSelectionFollowsFocus;
+ (WXDependencyProperty*)selectionModeProperty;
+ (WXDependencyProperty*)singleSelectionFollowsFocusProperty;
- (void)scrollIntoView:(RTObject*)item;
- (void)selectAll;
@end

#endif // __WXCListBox_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IToggleButtonOverrides
#ifndef __WUXCPIToggleButtonOverrides_DEFINED__
#define __WUXCPIToggleButtonOverrides_DEFINED__

@protocol WUXCPIToggleButtonOverrides
- (void)onToggle;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPIToggleButtonOverrides : RTObject <WUXCPIToggleButtonOverrides>
@end

#endif // __WUXCPIToggleButtonOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ToggleButton
#ifndef __WUXCPToggleButton_DEFINED__
#define __WUXCPToggleButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPToggleButton : WUXCPButtonBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isThreeState;
@property (retain) id /* BOOL */ isChecked;
+ (WXDependencyProperty*)isCheckedProperty;
+ (WXDependencyProperty*)isThreeStateProperty;
- (EventRegistrationToken)addCheckedEvent:(WXRoutedEventHandler)del;
- (void)removeCheckedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIndeterminateEvent:(WXRoutedEventHandler)del;
- (void)removeIndeterminateEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUncheckedEvent:(WXRoutedEventHandler)del;
- (void)removeUncheckedEvent:(EventRegistrationToken)tok;
- (void)onToggle;
@end

#endif // __WUXCPToggleButton_DEFINED__

// Windows.UI.Xaml.Controls.CheckBox
#ifndef __WXCCheckBox_DEFINED__
#define __WXCCheckBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCheckBox : WUXCPToggleButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCCheckBox_DEFINED__

// Windows.UI.Xaml.Controls.RadioButton
#ifndef __WXCRadioButton_DEFINED__
#define __WXCRadioButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRadioButton : WUXCPToggleButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * groupName;
+ (WXDependencyProperty*)groupNameProperty;
@end

#endif // __WXCRadioButton_DEFINED__

// Windows.UI.Xaml.Controls.CalendarView
#ifndef __WXCCalendarView_DEFINED__
#define __WXCCalendarView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCalendarView : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMBrush* calendarItemForeground;
@property (retain) WXThickness* calendarItemBorderThickness;
@property (retain) WUXMBrush* focusBorderBrush;
@property (retain) WUXMBrush* calendarItemBackground;
@property (retain) NSString * calendarIdentifier;
@property (retain) WXStyle* calendarViewDayItemStyle;
@property WXCCalendarViewDisplayMode displayMode;
@property (retain) NSString * dayOfWeekFormat;
@property (retain) WUTFontWeight* dayItemFontWeight;
@property WUTFontStyle dayItemFontStyle;
@property double dayItemFontSize;
@property (retain) WUXMFontFamily* dayItemFontFamily;
@property (retain) WUXMBrush* blackoutForeground;
@property (retain) WUXMFontFamily* firstOfYearDecadeLabelFontFamily;
@property (retain) WUTFontWeight* firstOfMonthLabelFontWeight;
@property WUTFontStyle firstOfMonthLabelFontStyle;
@property double firstOfMonthLabelFontSize;
@property (retain) WUXMFontFamily* firstOfMonthLabelFontFamily;
@property (retain) WUXMBrush* hoverBorderBrush;
@property WGDayOfWeek firstDayOfWeek;
@property WXHorizontalAlignment horizontalFirstOfMonthLabelAlignment;
@property WXHorizontalAlignment horizontalDayItemAlignment;
@property (retain) WUXMBrush* calendarItemBorderBrush;
@property (retain) WUTFontWeight* firstOfYearDecadeLabelFontWeight;
@property WUTFontStyle firstOfYearDecadeLabelFontStyle;
@property (retain) WUXMFontFamily* monthYearItemFontFamily;
@property (retain) WFDateTime* minDate;
@property (retain) WFDateTime* maxDate;
@property BOOL isTodayHighlighted;
@property BOOL isOutOfScopeEnabled;
@property BOOL isGroupLabelVisible;
@property double monthYearItemFontSize;
@property double firstOfYearDecadeLabelFontSize;
@property (retain) WUXMBrush* outOfScopeForeground;
@property (retain) WUXMBrush* outOfScopeBackground;
@property int numberOfWeeksInView;
@property (retain) WUTFontWeight* monthYearItemFontWeight;
@property WUTFontStyle monthYearItemFontStyle;
@property (retain) WUXMBrush* selectedHoverBorderBrush;
@property (retain) WUXMBrush* selectedForeground;
@property (retain) WUXMBrush* selectedPressedBorderBrush;
@property (retain) WUXMBrush* selectedBorderBrush;
@property (retain) WUXMBrush* pressedForeground;
@property (retain) WUXMBrush* pressedBorderBrush;
@property WXVerticalAlignment verticalFirstOfMonthLabelAlignment;
@property WXVerticalAlignment verticalDayItemAlignment;
@property (retain) WUXMBrush* todayForeground;
@property (retain) WUTFontWeight* todayFontWeight;
@property WXCCalendarViewSelectionMode selectionMode;
@property (readonly) NSMutableArray* /* WFDateTime* */ selectedDates;
@property (readonly) WUXCPCalendarViewTemplateSettings* templateSettings;
+ (WXDependencyProperty*)blackoutForegroundProperty;
+ (WXDependencyProperty*)calendarIdentifierProperty;
+ (WXDependencyProperty*)calendarItemBackgroundProperty;
+ (WXDependencyProperty*)calendarItemBorderBrushProperty;
+ (WXDependencyProperty*)calendarItemBorderThicknessProperty;
+ (WXDependencyProperty*)calendarItemForegroundProperty;
+ (WXDependencyProperty*)calendarViewDayItemStyleProperty;
+ (WXDependencyProperty*)dayItemFontFamilyProperty;
+ (WXDependencyProperty*)dayItemFontSizeProperty;
+ (WXDependencyProperty*)dayItemFontStyleProperty;
+ (WXDependencyProperty*)dayItemFontWeightProperty;
+ (WXDependencyProperty*)dayOfWeekFormatProperty;
+ (WXDependencyProperty*)displayModeProperty;
+ (WXDependencyProperty*)firstDayOfWeekProperty;
+ (WXDependencyProperty*)firstOfMonthLabelFontFamilyProperty;
+ (WXDependencyProperty*)firstOfMonthLabelFontSizeProperty;
+ (WXDependencyProperty*)firstOfMonthLabelFontStyleProperty;
+ (WXDependencyProperty*)firstOfMonthLabelFontWeightProperty;
+ (WXDependencyProperty*)firstOfYearDecadeLabelFontFamilyProperty;
+ (WXDependencyProperty*)firstOfYearDecadeLabelFontSizeProperty;
+ (WXDependencyProperty*)firstOfYearDecadeLabelFontStyleProperty;
+ (WXDependencyProperty*)firstOfYearDecadeLabelFontWeightProperty;
+ (WXDependencyProperty*)focusBorderBrushProperty;
+ (WXDependencyProperty*)horizontalDayItemAlignmentProperty;
+ (WXDependencyProperty*)horizontalFirstOfMonthLabelAlignmentProperty;
+ (WXDependencyProperty*)hoverBorderBrushProperty;
+ (WXDependencyProperty*)isGroupLabelVisibleProperty;
+ (WXDependencyProperty*)isOutOfScopeEnabledProperty;
+ (WXDependencyProperty*)isTodayHighlightedProperty;
+ (WXDependencyProperty*)maxDateProperty;
+ (WXDependencyProperty*)minDateProperty;
+ (WXDependencyProperty*)monthYearItemFontFamilyProperty;
+ (WXDependencyProperty*)monthYearItemFontSizeProperty;
+ (WXDependencyProperty*)monthYearItemFontStyleProperty;
+ (WXDependencyProperty*)monthYearItemFontWeightProperty;
+ (WXDependencyProperty*)numberOfWeeksInViewProperty;
+ (WXDependencyProperty*)outOfScopeBackgroundProperty;
+ (WXDependencyProperty*)outOfScopeForegroundProperty;
+ (WXDependencyProperty*)pressedBorderBrushProperty;
+ (WXDependencyProperty*)pressedForegroundProperty;
+ (WXDependencyProperty*)selectedBorderBrushProperty;
+ (WXDependencyProperty*)selectedDatesProperty;
+ (WXDependencyProperty*)selectedForegroundProperty;
+ (WXDependencyProperty*)selectedHoverBorderBrushProperty;
+ (WXDependencyProperty*)selectedPressedBorderBrushProperty;
+ (WXDependencyProperty*)selectionModeProperty;
+ (WXDependencyProperty*)templateSettingsProperty;
+ (WXDependencyProperty*)todayFontWeightProperty;
+ (WXDependencyProperty*)todayForegroundProperty;
+ (WXDependencyProperty*)verticalDayItemAlignmentProperty;
+ (WXDependencyProperty*)verticalFirstOfMonthLabelAlignmentProperty;
- (EventRegistrationToken)addCalendarViewDayItemChangingEvent:(void(^)(WXCCalendarView*, WXCCalendarViewDayItemChangingEventArgs*))del;
- (void)removeCalendarViewDayItemChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectedDatesChangedEvent:(void(^)(WXCCalendarView*, WXCCalendarViewSelectedDatesChangedEventArgs*))del;
- (void)removeSelectedDatesChangedEvent:(EventRegistrationToken)tok;
- (void)setDisplayDate:(WFDateTime*)date;
- (void)setYearDecadeDisplayDimensions:(int)columns rows:(int)rows;
@end

#endif // __WXCCalendarView_DEFINED__

// Windows.UI.Xaml.Controls.CalendarViewDayItem
#ifndef __WXCCalendarViewDayItem_DEFINED__
#define __WXCCalendarViewDayItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCalendarViewDayItem : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isBlackout;
@property (readonly) WFDateTime* date;
+ (WXDependencyProperty*)dateProperty;
+ (WXDependencyProperty*)isBlackoutProperty;
- (void)setDensityColors:(id<NSFastEnumeration> /* WUColor* */)colors;
@end

#endif // __WXCCalendarViewDayItem_DEFINED__

// Windows.UI.Xaml.Controls.HubSection
#ifndef __WXCHubSection_DEFINED__
#define __WXCHubSection_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCHubSection : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isHeaderInteractive;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property (retain) WXDataTemplate* contentTemplate;
+ (WXDependencyProperty*)contentTemplateProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isHeaderInteractiveProperty;
@end

#endif // __WXCHubSection_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutItemBase
#ifndef __WXCMenuFlyoutItemBase_DEFINED__
#define __WXCMenuFlyoutItemBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMenuFlyoutItemBase : WXCControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCMenuFlyoutItemBase_DEFINED__

// Windows.UI.Xaml.Controls.AppBarSeparator
#ifndef __WXCAppBarSeparator_DEFINED__
#define __WXCAppBarSeparator_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAppBarSeparator : WXCControl <WXCICommandBarElement, WXCICommandBarElement2>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isCompact;
@property int dynamicOverflowOrder;
@property (readonly) BOOL isInOverflow;
+ (WXDependencyProperty*)isCompactProperty;
+ (WXDependencyProperty*)dynamicOverflowOrderProperty;
+ (WXDependencyProperty*)isInOverflowProperty;
@end

#endif // __WXCAppBarSeparator_DEFINED__

// Windows.UI.Xaml.Controls.CalendarDatePicker
#ifndef __WXCCalendarDatePicker_DEFINED__
#define __WXCCalendarDatePicker_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCalendarDatePicker : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property WGDayOfWeek firstDayOfWeek;
@property WXCCalendarViewDisplayMode displayMode;
@property (retain) NSString * calendarIdentifier;
@property (retain) NSString * dateFormat;
@property (retain) WXStyle* calendarViewStyle;
@property (retain) NSString * dayOfWeekFormat;
@property (retain) NSString * placeholderText;
@property (retain) id /* WFDateTime* */ date;
@property (retain) WFDateTime* minDate;
@property (retain) WFDateTime* maxDate;
@property BOOL isTodayHighlighted;
@property BOOL isOutOfScopeEnabled;
@property BOOL isGroupLabelVisible;
@property BOOL isCalendarOpen;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
+ (WXDependencyProperty*)dateProperty;
+ (WXDependencyProperty*)calendarIdentifierProperty;
+ (WXDependencyProperty*)calendarViewStyleProperty;
+ (WXDependencyProperty*)dateFormatProperty;
+ (WXDependencyProperty*)isCalendarOpenProperty;
+ (WXDependencyProperty*)dayOfWeekFormatProperty;
+ (WXDependencyProperty*)displayModeProperty;
+ (WXDependencyProperty*)firstDayOfWeekProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isGroupLabelVisibleProperty;
+ (WXDependencyProperty*)isOutOfScopeEnabledProperty;
+ (WXDependencyProperty*)isTodayHighlightedProperty;
+ (WXDependencyProperty*)maxDateProperty;
+ (WXDependencyProperty*)minDateProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
- (EventRegistrationToken)addCalendarViewDayItemChangingEvent:(WXCCalendarViewDayItemChangingEventHandler)del;
- (void)removeCalendarViewDayItemChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDateChangedEvent:(void(^)(WXCCalendarDatePicker*, WXCCalendarDatePickerDateChangedEventArgs*))del;
- (void)removeDateChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (void)setDisplayDate:(WFDateTime*)date;
- (void)setYearDecadeDisplayDimensions:(int)columns rows:(int)rows;
@end

#endif // __WXCCalendarDatePicker_DEFINED__

// Windows.UI.Xaml.Controls.DatePicker
#ifndef __WXCDatePicker_DEFINED__
#define __WXCDatePicker_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDatePicker : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFDateTime* maxYear;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property (retain) NSString * calendarIdentifier;
@property BOOL dayVisible;
@property (retain) NSString * dayFormat;
@property (retain) WFDateTime* date;
@property (retain) WFDateTime* minYear;
@property (retain) NSString * yearFormat;
@property BOOL yearVisible;
@property WXCOrientation orientation;
@property BOOL monthVisible;
@property (retain) NSString * monthFormat;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
+ (WXDependencyProperty*)dayFormatProperty;
+ (WXDependencyProperty*)calendarIdentifierProperty;
+ (WXDependencyProperty*)dateProperty;
+ (WXDependencyProperty*)minYearProperty;
+ (WXDependencyProperty*)dayVisibleProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)maxYearProperty;
+ (WXDependencyProperty*)monthFormatProperty;
+ (WXDependencyProperty*)monthVisibleProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)yearFormatProperty;
+ (WXDependencyProperty*)yearVisibleProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
- (EventRegistrationToken)addDateChangedEvent:(void(^)(RTObject*, WXCDatePickerValueChangedEventArgs*))del;
- (void)removeDateChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCDatePicker_DEFINED__

// Windows.UI.Xaml.Controls.Hub
#ifndef __WXCHub_DEFINED__
#define __WXCHub_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCHub : WXCControl <WXCISemanticZoomInformation>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCOrientation orientation;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property int defaultSectionIndex;
@property (readonly) NSMutableArray<RTObservableCollection>* /* RTObject* */ sectionHeaders;
@property (readonly) NSMutableArray* /* WXCHubSection* */ sections;
@property (readonly) NSMutableArray* /* WXCHubSection* */ sectionsInView;
@property (retain) WXCSemanticZoom* semanticZoomOwner;
@property BOOL isZoomedInView;
@property BOOL isActiveView;
+ (WXDependencyProperty*)defaultSectionIndexProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isActiveViewProperty;
+ (WXDependencyProperty*)isZoomedInViewProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)semanticZoomOwnerProperty;
- (EventRegistrationToken)addSectionHeaderClickEvent:(WXCHubSectionHeaderClickEventHandler)del;
- (void)removeSectionHeaderClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSectionsInViewChangedEvent:(WXCSectionsInViewChangedEventHandler)del;
- (void)removeSectionsInViewChangedEvent:(EventRegistrationToken)tok;
- (void)scrollToSection:(WXCHubSection*)section;
- (void)initializeViewChange;
- (void)completeViewChange;
- (void)makeVisible:(WXCSemanticZoomLocation*)item;
- (void)startViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)startViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
@end

#endif // __WXCHub_DEFINED__

// Windows.UI.Xaml.Controls.MediaPlayerElement
#ifndef __WXCMediaPlayerElement_DEFINED__
#define __WXCMediaPlayerElement_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMediaPlayerElement : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCMediaTransportControls* transportControls;
@property WUXMStretch stretch;
@property (retain) RTObject<WMPIMediaPlaybackSource>* source;
@property (retain) WUXMImageSource* posterSource;
@property BOOL isFullWindow;
@property BOOL autoPlay;
@property BOOL areTransportControlsEnabled;
@property (readonly) WMPMediaPlayer* mediaPlayer;
+ (WXDependencyProperty*)areTransportControlsEnabledProperty;
+ (WXDependencyProperty*)autoPlayProperty;
+ (WXDependencyProperty*)isFullWindowProperty;
+ (WXDependencyProperty*)mediaPlayerProperty;
+ (WXDependencyProperty*)posterSourceProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)stretchProperty;
- (void)setMediaPlayer:(WMPMediaPlayer*)mediaPlayer;
@end

#endif // __WXCMediaPlayerElement_DEFINED__

// Windows.UI.Xaml.Controls.RichEditBox
#ifndef __WXCRichEditBox_DEFINED__
#define __WXCRichEditBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCRichEditBox : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isSpellCheckEnabled;
@property BOOL isReadOnly;
@property (retain) WUXIInputScope* inputScope;
@property BOOL isTextPredictionEnabled;
@property BOOL acceptsReturn;
@property WXTextWrapping textWrapping;
@property WXTextAlignment textAlignment;
@property (readonly) RTObject<WUTITextDocument>* document;
@property BOOL isColorFontEnabled;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property (retain) WUXMSolidColorBrush* selectionHighlightColor;
@property BOOL preventKeyboardDisplayOnProgrammaticFocus;
@property (retain) NSString * placeholderText;
@property WXTextReadingOrder textReadingOrder;
@property WXCCandidateWindowAlignment desiredCandidateWindowAlignment;
@property WXCRichEditClipboardFormat clipboardCopyFormat;
@property (retain) WUXMSolidColorBrush* selectionHighlightColorWhenNotFocused;
@property int maxLength;
@property WXCDisabledFormattingAccelerators disabledFormattingAccelerators;
@property WXCCharacterCasing characterCasing;
@property WXTextAlignment horizontalTextAlignment;
+ (WXDependencyProperty*)isReadOnlyProperty;
+ (WXDependencyProperty*)inputScopeProperty;
+ (WXDependencyProperty*)acceptsReturnProperty;
+ (WXDependencyProperty*)textWrappingProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)isTextPredictionEnabledProperty;
+ (WXDependencyProperty*)isSpellCheckEnabledProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)preventKeyboardDisplayOnProgrammaticFocusProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)textReadingOrderProperty;
+ (WXDependencyProperty*)desiredCandidateWindowAlignmentProperty;
+ (WXDependencyProperty*)clipboardCopyFormatProperty;
+ (WXDependencyProperty*)selectionHighlightColorWhenNotFocusedProperty;
+ (WXDependencyProperty*)maxLengthProperty;
+ (WXDependencyProperty*)disabledFormattingAcceleratorsProperty;
+ (WXDependencyProperty*)horizontalTextAlignmentProperty;
+ (WXDependencyProperty*)characterCasingProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextChangedEvent:(WXRoutedEventHandler)del;
- (void)removeTextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasteEvent:(WXCTextControlPasteEventHandler)del;
- (void)removePasteEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCandidateWindowBoundsChangedEvent:(void(^)(WXCRichEditBox*, WXCCandidateWindowBoundsChangedEventArgs*))del;
- (void)removeCandidateWindowBoundsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextChangingEvent:(void(^)(WXCRichEditBox*, WXCRichEditBoxTextChangingEventArgs*))del;
- (void)removeTextChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextCompositionChangedEvent:(void(^)(WXCRichEditBox*, WXCTextCompositionChangedEventArgs*))del;
- (void)removeTextCompositionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextCompositionEndedEvent:(void(^)(WXCRichEditBox*, WXCTextCompositionEndedEventArgs*))del;
- (void)removeTextCompositionEndedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextCompositionStartedEvent:(void(^)(WXCRichEditBox*, WXCTextCompositionStartedEventArgs*))del;
- (void)removeTextCompositionStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCopyingToClipboardEvent:(void(^)(WXCRichEditBox*, WXCTextControlCopyingToClipboardEventArgs*))del;
- (void)removeCopyingToClipboardEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCuttingToClipboardEvent:(void(^)(WXCRichEditBox*, WXCTextControlCuttingToClipboardEventArgs*))del;
- (void)removeCuttingToClipboardEvent:(EventRegistrationToken)tok;
- (void)getLinguisticAlternativesAsyncWithSuccess:(void (^)(NSArray* /* NSString * */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXCRichEditBox_DEFINED__

// Windows.UI.Xaml.Controls.SearchBox
#ifndef __WXCSearchBox_DEFINED__
#define __WXCSearchBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSearchBox : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL searchHistoryEnabled;
@property (retain) NSString * searchHistoryContext;
@property (retain) NSString * queryText;
@property (retain) NSString * placeholderText;
@property BOOL focusOnKeyboardInput;
@property BOOL chooseSuggestionOnEnter;
+ (WXDependencyProperty*)chooseSuggestionOnEnterProperty;
+ (WXDependencyProperty*)focusOnKeyboardInputProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)queryTextProperty;
+ (WXDependencyProperty*)searchHistoryContextProperty;
+ (WXDependencyProperty*)searchHistoryEnabledProperty;
- (EventRegistrationToken)addPrepareForFocusOnKeyboardInputEvent:(void(^)(WXCSearchBox*, WXRoutedEventArgs*))del;
- (void)removePrepareForFocusOnKeyboardInputEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQueryChangedEvent:(void(^)(WXCSearchBox*, WXCSearchBoxQueryChangedEventArgs*))del;
- (void)removeQueryChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuerySubmittedEvent:(void(^)(WXCSearchBox*, WXCSearchBoxQuerySubmittedEventArgs*))del;
- (void)removeQuerySubmittedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResultSuggestionChosenEvent:(void(^)(WXCSearchBox*, WXCSearchBoxResultSuggestionChosenEventArgs*))del;
- (void)removeResultSuggestionChosenEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSuggestionsRequestedEvent:(void(^)(WXCSearchBox*, WXCSearchBoxSuggestionsRequestedEventArgs*))del;
- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)tok;
- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings;
@end

#endif // __WXCSearchBox_DEFINED__

// Windows.UI.Xaml.Controls.SplitView
#ifndef __WXCSplitView_DEFINED__
#define __WXCSplitView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCSplitView : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCSplitViewPanePlacement panePlacement;
@property (retain) WUXMBrush* paneBackground;
@property (retain) WXUIElement* pane;
@property double openPaneLength;
@property BOOL isPaneOpen;
@property WXCSplitViewDisplayMode displayMode;
@property (retain) WXUIElement* content;
@property double compactPaneLength;
@property (readonly) WUXCPSplitViewTemplateSettings* templateSettings;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
+ (WXDependencyProperty*)compactPaneLengthProperty;
+ (WXDependencyProperty*)contentProperty;
+ (WXDependencyProperty*)displayModeProperty;
+ (WXDependencyProperty*)isPaneOpenProperty;
+ (WXDependencyProperty*)openPaneLengthProperty;
+ (WXDependencyProperty*)paneBackgroundProperty;
+ (WXDependencyProperty*)panePlacementProperty;
+ (WXDependencyProperty*)paneProperty;
+ (WXDependencyProperty*)templateSettingsProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
- (EventRegistrationToken)addPaneClosedEvent:(void(^)(WXCSplitView*, RTObject*))del;
- (void)removePaneClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPaneClosingEvent:(void(^)(WXCSplitView*, WXCSplitViewPaneClosingEventArgs*))del;
- (void)removePaneClosingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPaneOpenedEvent:(void(^)(WXCSplitView*, RTObject*))del;
- (void)removePaneOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPaneOpeningEvent:(void(^)(WXCSplitView*, RTObject*))del;
- (void)removePaneOpeningEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCSplitView_DEFINED__

// Windows.UI.Xaml.Controls.TimePicker
#ifndef __WXCTimePicker_DEFINED__
#define __WXCTimePicker_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTimePicker : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* time;
@property int minuteIncrement;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) RTObject* header;
@property (retain) NSString * clockIdentifier;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
+ (WXDependencyProperty*)clockIdentifierProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)minuteIncrementProperty;
+ (WXDependencyProperty*)timeProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
- (EventRegistrationToken)addTimeChangedEvent:(void(^)(RTObject*, WXCTimePickerValueChangedEventArgs*))del;
- (void)removeTimeChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCTimePicker_DEFINED__

// Windows.UI.Xaml.Controls.AppBar
#ifndef __WXCAppBar_DEFINED__
#define __WXCAppBar_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAppBar : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isSticky;
@property BOOL isOpen;
@property WXCAppBarClosedDisplayMode closedDisplayMode;
@property (readonly) WUXCPAppBarTemplateSettings* templateSettings;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
+ (WXDependencyProperty*)isOpenProperty;
+ (WXDependencyProperty*)isStickyProperty;
+ (WXDependencyProperty*)closedDisplayModeProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
- (EventRegistrationToken)addClosedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosingEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeClosingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpeningEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeOpeningEvent:(EventRegistrationToken)tok;
- (void)onClosed:(RTObject*)e;
- (void)onOpened:(RTObject*)e;
- (void)onClosing:(RTObject*)e;
- (void)onOpening:(RTObject*)e;
@end

#endif // __WXCAppBar_DEFINED__

// Windows.UI.Xaml.Controls.AutoSuggestBox
#ifndef __WXCAutoSuggestBox_DEFINED__
#define __WXCAutoSuggestBox_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAutoSuggestBox : WXCItemsControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * text;
@property (retain) NSString * placeholderText;
@property double maxSuggestionListHeight;
@property BOOL isSuggestionListOpen;
@property (retain) RTObject* header;
@property BOOL autoMaximizeSuggestionArea;
@property BOOL updateTextOnSelect;
@property (retain) NSString * textMemberPath;
@property (retain) WXStyle* textBoxStyle;
@property (retain) WXCIconElement* queryIcon;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
+ (WXDependencyProperty*)autoMaximizeSuggestionAreaProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)isSuggestionListOpenProperty;
+ (WXDependencyProperty*)maxSuggestionListHeightProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)textBoxStyleProperty;
+ (WXDependencyProperty*)textMemberPathProperty;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)updateTextOnSelectProperty;
+ (WXDependencyProperty*)queryIconProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
- (EventRegistrationToken)addSuggestionChosenEvent:(void(^)(WXCAutoSuggestBox*, WXCAutoSuggestBoxSuggestionChosenEventArgs*))del;
- (void)removeSuggestionChosenEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextChangedEvent:(void(^)(WXCAutoSuggestBox*, WXCAutoSuggestBoxTextChangedEventArgs*))del;
- (void)removeTextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuerySubmittedEvent:(void(^)(WXCAutoSuggestBox*, WXCAutoSuggestBoxQuerySubmittedEventArgs*))del;
- (void)removeQuerySubmittedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCAutoSuggestBox_DEFINED__

// Windows.UI.Xaml.Controls.CommandBarOverflowPresenter
#ifndef __WXCCommandBarOverflowPresenter_DEFINED__
#define __WXCCommandBarOverflowPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCommandBarOverflowPresenter : WXCItemsControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCCommandBarOverflowPresenter_DEFINED__

// Windows.UI.Xaml.Controls.ContentDialog
#ifndef __WXCContentDialog_DEFINED__
#define __WXCContentDialog_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCContentDialog : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * secondaryButtonText;
@property (retain) RTObject* title;
@property (retain) RTObject<WUXIICommand>* secondaryButtonCommand;
@property (retain) NSString * primaryButtonText;
@property BOOL fullSizeDesired;
@property (retain) RTObject<WUXIICommand>* primaryButtonCommand;
@property (retain) RTObject* secondaryButtonCommandParameter;
@property BOOL isPrimaryButtonEnabled;
@property (retain) RTObject* primaryButtonCommandParameter;
@property BOOL isSecondaryButtonEnabled;
@property (retain) WXDataTemplate* titleTemplate;
@property (retain) WXStyle* closeButtonStyle;
@property (retain) WXStyle* primaryButtonStyle;
@property WXCContentDialogButton defaultButton;
@property (retain) NSString * closeButtonText;
@property (retain) WXStyle* secondaryButtonStyle;
@property (retain) RTObject* closeButtonCommandParameter;
@property (retain) RTObject<WUXIICommand>* closeButtonCommand;
+ (WXDependencyProperty*)secondaryButtonCommandParameterProperty;
+ (WXDependencyProperty*)fullSizeDesiredProperty;
+ (WXDependencyProperty*)isPrimaryButtonEnabledProperty;
+ (WXDependencyProperty*)isSecondaryButtonEnabledProperty;
+ (WXDependencyProperty*)primaryButtonCommandParameterProperty;
+ (WXDependencyProperty*)primaryButtonCommandProperty;
+ (WXDependencyProperty*)primaryButtonTextProperty;
+ (WXDependencyProperty*)secondaryButtonCommandProperty;
+ (WXDependencyProperty*)secondaryButtonTextProperty;
+ (WXDependencyProperty*)titleProperty;
+ (WXDependencyProperty*)titleTemplateProperty;
+ (WXDependencyProperty*)closeButtonCommandParameterProperty;
+ (WXDependencyProperty*)closeButtonCommandProperty;
+ (WXDependencyProperty*)closeButtonStyleProperty;
+ (WXDependencyProperty*)closeButtonTextProperty;
+ (WXDependencyProperty*)defaultButtonProperty;
+ (WXDependencyProperty*)primaryButtonStyleProperty;
+ (WXDependencyProperty*)secondaryButtonStyleProperty;
- (EventRegistrationToken)addClosedEvent:(void(^)(WXCContentDialog*, WXCContentDialogClosedEventArgs*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosingEvent:(void(^)(WXCContentDialog*, WXCContentDialogClosingEventArgs*))del;
- (void)removeClosingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void(^)(WXCContentDialog*, WXCContentDialogOpenedEventArgs*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPrimaryButtonClickEvent:(void(^)(WXCContentDialog*, WXCContentDialogButtonClickEventArgs*))del;
- (void)removePrimaryButtonClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSecondaryButtonClickEvent:(void(^)(WXCContentDialog*, WXCContentDialogButtonClickEventArgs*))del;
- (void)removeSecondaryButtonClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCloseButtonClickEvent:(void(^)(WXCContentDialog*, WXCContentDialogButtonClickEventArgs*))del;
- (void)removeCloseButtonClickEvent:(EventRegistrationToken)tok;
- (void)hide;
- (void)showAsyncWithSuccess:(void (^)(WXCContentDialogResult))success failure:(void (^)(NSError*))failure;
- (void)showAsyncWithPlacement:(WXCContentDialogPlacement)placement success:(void (^)(WXCContentDialogResult))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXCContentDialog_DEFINED__

// Windows.UI.Xaml.Controls.FlyoutPresenter
#ifndef __WXCFlyoutPresenter_DEFINED__
#define __WXCFlyoutPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFlyoutPresenter : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.Frame
#ifndef __WXCFrame_DEFINED__
#define __WXCFrame_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFrame : WXCContentControl <WXCINavigate>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXITypeName* sourcePageType;
@property int cacheSize;
@property (readonly) int backStackDepth;
@property (readonly) BOOL canGoBack;
@property (readonly) BOOL canGoForward;
@property (readonly) WUXITypeName* currentSourcePageType;
@property (readonly) NSMutableArray* /* WUXNPageStackEntry* */ backStack;
@property (readonly) NSMutableArray* /* WUXNPageStackEntry* */ forwardStack;
+ (WXDependencyProperty*)backStackDepthProperty;
+ (WXDependencyProperty*)cacheSizeProperty;
+ (WXDependencyProperty*)canGoBackProperty;
+ (WXDependencyProperty*)canGoForwardProperty;
+ (WXDependencyProperty*)currentSourcePageTypeProperty;
+ (WXDependencyProperty*)sourcePageTypeProperty;
+ (WXDependencyProperty*)backStackProperty;
+ (WXDependencyProperty*)forwardStackProperty;
- (EventRegistrationToken)addNavigatedEvent:(WUXNNavigatedEventHandler)del;
- (void)removeNavigatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigatingEvent:(WUXNNavigatingCancelEventHandler)del;
- (void)removeNavigatingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationFailedEvent:(WUXNNavigationFailedEventHandler)del;
- (void)removeNavigationFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationStoppedEvent:(WUXNNavigationStoppedEventHandler)del;
- (void)removeNavigationStoppedEvent:(EventRegistrationToken)tok;
- (void)goBack;
- (void)goForward;
- (BOOL)navigate:(WUXITypeName*)sourcePageType parameter:(RTObject*)parameter;
- (NSString *)getNavigationState;
- (void)setNavigationState:(NSString *)navigationState;
- (BOOL)navigate:(WUXITypeName*)sourcePageType;
- (BOOL)navigate:(WUXITypeName*)sourcePageType parameter:(RTObject*)parameter infoOverride:(WUXMANavigationTransitionInfo*)infoOverride;
- (void)goBack:(WUXMANavigationTransitionInfo*)transitionInfoOverride;
- (void)setNavigationStateWithNavigationControl:(NSString *)navigationState suppressNavigate:(BOOL)suppressNavigate;
@end

#endif // __WXCFrame_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutItem
#ifndef __WXCMenuFlyoutItem_DEFINED__
#define __WXCMenuFlyoutItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMenuFlyoutItem : WXCMenuFlyoutItemBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * text;
@property (retain) RTObject* commandParameter;
@property (retain) RTObject<WUXIICommand>* command;
@property (retain) WXCIconElement* icon;
+ (WXDependencyProperty*)commandParameterProperty;
+ (WXDependencyProperty*)commandProperty;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)iconProperty;
- (EventRegistrationToken)addClickEvent:(WXRoutedEventHandler)del;
- (void)removeClickEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCMenuFlyoutItem_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutPresenter
#ifndef __WXCMenuFlyoutPresenter_DEFINED__
#define __WXCMenuFlyoutPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMenuFlyoutPresenter : WXCItemsControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCPMenuFlyoutPresenterTemplateSettings* templateSettings;
@end

#endif // __WXCMenuFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutSeparator
#ifndef __WXCMenuFlyoutSeparator_DEFINED__
#define __WXCMenuFlyoutSeparator_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMenuFlyoutSeparator : WXCMenuFlyoutItemBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCMenuFlyoutSeparator_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutSubItem
#ifndef __WXCMenuFlyoutSubItem_DEFINED__
#define __WXCMenuFlyoutSubItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMenuFlyoutSubItem : WXCMenuFlyoutItemBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * text;
@property (readonly) NSMutableArray* /* WXCMenuFlyoutItemBase* */ items;
@property (retain) WXCIconElement* icon;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)iconProperty;
@end

#endif // __WXCMenuFlyoutSubItem_DEFINED__

// Windows.UI.Xaml.Controls.Page
#ifndef __WXCPage_DEFINED__
#define __WXCPage_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPage : WXCUserControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCAppBar* topAppBar;
@property WUXNNavigationCacheMode navigationCacheMode;
@property (retain) WXCAppBar* bottomAppBar;
@property (readonly) WXCFrame* frame;
+ (WXDependencyProperty*)bottomAppBarProperty;
+ (WXDependencyProperty*)frameProperty;
+ (WXDependencyProperty*)topAppBarProperty;
- (void)onNavigatedFrom:(WUXNNavigationEventArgs*)e;
- (void)onNavigatedTo:(WUXNNavigationEventArgs*)e;
- (void)onNavigatingFrom:(WUXNNavigatingCancelEventArgs*)e;
@end

#endif // __WXCPage_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewer
#ifndef __WXCScrollViewer_DEFINED__
#define __WXCScrollViewer_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCScrollViewer : WXCContentControl
+ (WXCScrollBarVisibility)getHorizontalScrollBarVisibility:(WXDependencyObject*)element;
+ (void)setHorizontalScrollBarVisibility:(WXDependencyObject*)element horizontalScrollBarVisibility:(WXCScrollBarVisibility)horizontalScrollBarVisibility;
+ (WXCScrollBarVisibility)getVerticalScrollBarVisibility:(WXDependencyObject*)element;
+ (void)setVerticalScrollBarVisibility:(WXDependencyObject*)element verticalScrollBarVisibility:(WXCScrollBarVisibility)verticalScrollBarVisibility;
+ (BOOL)getIsHorizontalRailEnabled:(WXDependencyObject*)element;
+ (void)setIsHorizontalRailEnabled:(WXDependencyObject*)element isHorizontalRailEnabled:(BOOL)isHorizontalRailEnabled;
+ (BOOL)getIsVerticalRailEnabled:(WXDependencyObject*)element;
+ (void)setIsVerticalRailEnabled:(WXDependencyObject*)element isVerticalRailEnabled:(BOOL)isVerticalRailEnabled;
+ (BOOL)getIsHorizontalScrollChainingEnabled:(WXDependencyObject*)element;
+ (void)setIsHorizontalScrollChainingEnabled:(WXDependencyObject*)element isHorizontalScrollChainingEnabled:(BOOL)isHorizontalScrollChainingEnabled;
+ (BOOL)getIsVerticalScrollChainingEnabled:(WXDependencyObject*)element;
+ (void)setIsVerticalScrollChainingEnabled:(WXDependencyObject*)element isVerticalScrollChainingEnabled:(BOOL)isVerticalScrollChainingEnabled;
+ (BOOL)getIsZoomChainingEnabled:(WXDependencyObject*)element;
+ (void)setIsZoomChainingEnabled:(WXDependencyObject*)element isZoomChainingEnabled:(BOOL)isZoomChainingEnabled;
+ (BOOL)getIsScrollInertiaEnabled:(WXDependencyObject*)element;
+ (void)setIsScrollInertiaEnabled:(WXDependencyObject*)element isScrollInertiaEnabled:(BOOL)isScrollInertiaEnabled;
+ (BOOL)getIsZoomInertiaEnabled:(WXDependencyObject*)element;
+ (void)setIsZoomInertiaEnabled:(WXDependencyObject*)element isZoomInertiaEnabled:(BOOL)isZoomInertiaEnabled;
+ (WXCScrollMode)getHorizontalScrollMode:(WXDependencyObject*)element;
+ (void)setHorizontalScrollMode:(WXDependencyObject*)element horizontalScrollMode:(WXCScrollMode)horizontalScrollMode;
+ (WXCScrollMode)getVerticalScrollMode:(WXDependencyObject*)element;
+ (void)setVerticalScrollMode:(WXDependencyObject*)element verticalScrollMode:(WXCScrollMode)verticalScrollMode;
+ (WXCZoomMode)getZoomMode:(WXDependencyObject*)element;
+ (void)setZoomMode:(WXDependencyObject*)element zoomMode:(WXCZoomMode)zoomMode;
+ (BOOL)getIsDeferredScrollingEnabled:(WXDependencyObject*)element;
+ (void)setIsDeferredScrollingEnabled:(WXDependencyObject*)element isDeferredScrollingEnabled:(BOOL)isDeferredScrollingEnabled;
+ (BOOL)getBringIntoViewOnFocusChange:(WXDependencyObject*)element;
+ (void)setBringIntoViewOnFocusChange:(WXDependencyObject*)element bringIntoViewOnFocusChange:(BOOL)bringIntoViewOnFocusChange;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCScrollBarVisibility horizontalScrollBarVisibility;
@property BOOL isZoomInertiaEnabled;
@property BOOL isZoomChainingEnabled;
@property BOOL isVerticalScrollChainingEnabled;
@property BOOL isVerticalRailEnabled;
@property float maxZoomFactor;
@property BOOL isScrollInertiaEnabled;
@property BOOL isHorizontalScrollChainingEnabled;
@property BOOL isHorizontalRailEnabled;
@property BOOL isDeferredScrollingEnabled;
@property WXCSnapPointsType horizontalSnapPointsType;
@property WUXCPSnapPointsAlignment horizontalSnapPointsAlignment;
@property WXCScrollMode horizontalScrollMode;
@property BOOL bringIntoViewOnFocusChange;
@property WXCSnapPointsType zoomSnapPointsType;
@property WXCZoomMode zoomMode;
@property WXCSnapPointsType verticalSnapPointsType;
@property WUXCPSnapPointsAlignment verticalSnapPointsAlignment;
@property float minZoomFactor;
@property WXCScrollBarVisibility verticalScrollBarVisibility;
@property WXCScrollMode verticalScrollMode;
@property (readonly) double scrollableHeight;
@property (readonly) double scrollableWidth;
@property (readonly) double verticalOffset;
@property (readonly) WXVisibility computedVerticalScrollBarVisibility;
@property (readonly) double extentHeight;
@property (readonly) double viewportHeight;
@property (readonly) double viewportWidth;
@property (readonly) float zoomFactor;
@property (readonly) WXVisibility computedHorizontalScrollBarVisibility;
@property (readonly) double extentWidth;
@property (readonly) NSMutableArray* /* float */ zoomSnapPoints;
@property (readonly) double horizontalOffset;
@property (retain) WXUIElement* topHeader;
@property (retain) WXUIElement* leftHeader;
@property (retain) WXUIElement* topLeftHeader;
+ (WXDependencyProperty*)extentWidthProperty;
+ (WXDependencyProperty*)bringIntoViewOnFocusChangeProperty;
+ (WXDependencyProperty*)computedHorizontalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)computedVerticalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)extentHeightProperty;
+ (WXDependencyProperty*)isZoomInertiaEnabledProperty;
+ (WXDependencyProperty*)horizontalOffsetProperty;
+ (WXDependencyProperty*)horizontalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)horizontalScrollModeProperty;
+ (WXDependencyProperty*)horizontalSnapPointsAlignmentProperty;
+ (WXDependencyProperty*)horizontalSnapPointsTypeProperty;
+ (WXDependencyProperty*)isDeferredScrollingEnabledProperty;
+ (WXDependencyProperty*)isHorizontalRailEnabledProperty;
+ (WXDependencyProperty*)isHorizontalScrollChainingEnabledProperty;
+ (WXDependencyProperty*)isScrollInertiaEnabledProperty;
+ (WXDependencyProperty*)isVerticalRailEnabledProperty;
+ (WXDependencyProperty*)isVerticalScrollChainingEnabledProperty;
+ (WXDependencyProperty*)isZoomChainingEnabledProperty;
+ (WXDependencyProperty*)maxZoomFactorProperty;
+ (WXDependencyProperty*)minZoomFactorProperty;
+ (WXDependencyProperty*)scrollableHeightProperty;
+ (WXDependencyProperty*)scrollableWidthProperty;
+ (WXDependencyProperty*)verticalOffsetProperty;
+ (WXDependencyProperty*)verticalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)verticalScrollModeProperty;
+ (WXDependencyProperty*)verticalSnapPointsAlignmentProperty;
+ (WXDependencyProperty*)verticalSnapPointsTypeProperty;
+ (WXDependencyProperty*)viewportHeightProperty;
+ (WXDependencyProperty*)viewportWidthProperty;
+ (WXDependencyProperty*)zoomFactorProperty;
+ (WXDependencyProperty*)zoomModeProperty;
+ (WXDependencyProperty*)zoomSnapPointsProperty;
+ (WXDependencyProperty*)zoomSnapPointsTypeProperty;
+ (WXDependencyProperty*)topHeaderProperty;
+ (WXDependencyProperty*)topLeftHeaderProperty;
+ (WXDependencyProperty*)leftHeaderProperty;
- (EventRegistrationToken)addViewChangedEvent:(void(^)(RTObject*, WXCScrollViewerViewChangedEventArgs*))del;
- (void)removeViewChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addViewChangingEvent:(void(^)(RTObject*, WXCScrollViewerViewChangingEventArgs*))del;
- (void)removeViewChangingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDirectManipulationCompletedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeDirectManipulationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDirectManipulationStartedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeDirectManipulationStartedEvent:(EventRegistrationToken)tok;
- (void)scrollToHorizontalOffset:(double)offset;
- (void)scrollToVerticalOffset:(double)offset;
- (void)zoomToFactor:(float)factor;
- (void)invalidateScrollInfo;
- (BOOL)changeView:(id /* double */)horizontalOffset verticalOffset:(id /* double */)verticalOffset zoomFactor:(id /* float */)zoomFactor;
- (BOOL)changeViewWithOptionalAnimation:(id /* double */)horizontalOffset verticalOffset:(id /* double */)verticalOffset zoomFactor:(id /* float */)zoomFactor disableAnimation:(BOOL)disableAnimation;
@end

#endif // __WXCScrollViewer_DEFINED__

// Windows.UI.Xaml.Controls.CommandBar
#ifndef __WXCCommandBar_DEFINED__
#define __WXCCommandBar_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCCommandBar : WXCAppBar
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray<RTObservableCollection>* /* RTObject<WXCICommandBarElement>* */ primaryCommands;
@property (readonly) NSMutableArray<RTObservableCollection>* /* RTObject<WXCICommandBarElement>* */ secondaryCommands;
@property (retain) WXStyle* commandBarOverflowPresenterStyle;
@property (readonly) WUXCPCommandBarTemplateSettings* commandBarTemplateSettings;
@property WXCCommandBarOverflowButtonVisibility overflowButtonVisibility;
@property BOOL isDynamicOverflowEnabled;
@property WXCCommandBarDefaultLabelPosition defaultLabelPosition;
+ (WXDependencyProperty*)primaryCommandsProperty;
+ (WXDependencyProperty*)secondaryCommandsProperty;
+ (WXDependencyProperty*)commandBarOverflowPresenterStyleProperty;
+ (WXDependencyProperty*)defaultLabelPositionProperty;
+ (WXDependencyProperty*)isDynamicOverflowEnabledProperty;
+ (WXDependencyProperty*)overflowButtonVisibilityProperty;
- (EventRegistrationToken)addDynamicOverflowItemsChangingEvent:(void(^)(WXCCommandBar*, WXCDynamicOverflowItemsChangingEventArgs*))del;
- (void)removeDynamicOverflowItemsChangingEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCCommandBar_DEFINED__

// Windows.UI.Xaml.Controls.GridViewHeaderItem
#ifndef __WXCGridViewHeaderItem_DEFINED__
#define __WXCGridViewHeaderItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCGridViewHeaderItem : WXCListViewBaseHeaderItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCGridViewHeaderItem_DEFINED__

// Windows.UI.Xaml.Controls.GridViewItem
#ifndef __WXCGridViewItem_DEFINED__
#define __WXCGridViewItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCGridViewItem : WUXCPSelectorItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCPGridViewItemTemplateSettings* templateSettings;
@end

#endif // __WXCGridViewItem_DEFINED__

// Windows.UI.Xaml.Controls.ListViewHeaderItem
#ifndef __WXCListViewHeaderItem_DEFINED__
#define __WXCListViewHeaderItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListViewHeaderItem : WXCListViewBaseHeaderItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCListViewHeaderItem_DEFINED__

// Windows.UI.Xaml.Controls.ListViewItem
#ifndef __WXCListViewItem_DEFINED__
#define __WXCListViewItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListViewItem : WUXCPSelectorItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUXCPListViewItemTemplateSettings* templateSettings;
@end

#endif // __WXCListViewItem_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewItemBase
#ifndef __WXCNavigationViewItemBase_DEFINED__
#define __WXCNavigationViewItemBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewItemBase : WXCListViewItem
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCNavigationViewItemBase_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewItem
#ifndef __WXCNavigationViewItem_DEFINED__
#define __WXCNavigationViewItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewItem : WXCNavigationViewItemBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCIconElement* icon;
@property (readonly) double compactPaneLength;
+ (WXDependencyProperty*)compactPaneLengthProperty;
+ (WXDependencyProperty*)iconProperty;
@end

#endif // __WXCNavigationViewItem_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewItemSeparator
#ifndef __WXCNavigationViewItemSeparator_DEFINED__
#define __WXCNavigationViewItemSeparator_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewItemSeparator : WXCNavigationViewItemBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCNavigationViewItemSeparator_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewItemHeader
#ifndef __WXCNavigationViewItemHeader_DEFINED__
#define __WXCNavigationViewItemHeader_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewItemHeader : WXCNavigationViewItemBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCNavigationViewItemHeader_DEFINED__

// Windows.UI.Xaml.Controls.ToggleMenuFlyoutItem
#ifndef __WXCToggleMenuFlyoutItem_DEFINED__
#define __WXCToggleMenuFlyoutItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCToggleMenuFlyoutItem : WXCMenuFlyoutItem
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isChecked;
+ (WXDependencyProperty*)isCheckedProperty;
@end

#endif // __WXCToggleMenuFlyoutItem_DEFINED__

// Windows.UI.Xaml.Controls.AppBarButton
#ifndef __WXCAppBarButton_DEFINED__
#define __WXCAppBarButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAppBarButton : WXCButton <WXCICommandBarElement, WXCICommandBarElement2>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * label;
@property (retain) WXCIconElement* icon;
@property WXCCommandBarLabelPosition labelPosition;
@property BOOL isCompact;
@property int dynamicOverflowOrder;
@property (readonly) BOOL isInOverflow;
+ (WXDependencyProperty*)iconProperty;
+ (WXDependencyProperty*)isCompactProperty;
+ (WXDependencyProperty*)labelProperty;
+ (WXDependencyProperty*)dynamicOverflowOrderProperty;
+ (WXDependencyProperty*)isInOverflowProperty;
+ (WXDependencyProperty*)labelPositionProperty;
@end

#endif // __WXCAppBarButton_DEFINED__

// Windows.UI.Xaml.Controls.AppBarToggleButton
#ifndef __WXCAppBarToggleButton_DEFINED__
#define __WXCAppBarToggleButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCAppBarToggleButton : WUXCPToggleButton <WXCICommandBarElement, WXCICommandBarElement2>
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * label;
@property (retain) WXCIconElement* icon;
@property WXCCommandBarLabelPosition labelPosition;
@property BOOL isCompact;
@property int dynamicOverflowOrder;
@property (readonly) BOOL isInOverflow;
+ (WXDependencyProperty*)iconProperty;
+ (WXDependencyProperty*)isCompactProperty;
+ (WXDependencyProperty*)labelProperty;
+ (WXDependencyProperty*)dynamicOverflowOrderProperty;
+ (WXDependencyProperty*)isInOverflowProperty;
+ (WXDependencyProperty*)labelPositionProperty;
@end

#endif // __WXCAppBarToggleButton_DEFINED__

// Windows.UI.Xaml.Controls.GridView
#ifndef __WXCGridView_DEFINED__
#define __WXCGridView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCGridView : WXCListViewBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCGridView_DEFINED__

// Windows.UI.Xaml.Controls.ListView
#ifndef __WXCListView_DEFINED__
#define __WXCListView_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListView : WXCListViewBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCListView_DEFINED__

// Windows.UI.Xaml.Controls.NavigationViewList
#ifndef __WXCNavigationViewList_DEFINED__
#define __WXCNavigationViewList_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCNavigationViewList : WXCListView
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCNavigationViewList_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IFlyoutBaseOverrides
#ifndef __WUXCPIFlyoutBaseOverrides_DEFINED__
#define __WUXCPIFlyoutBaseOverrides_DEFINED__

@protocol WUXCPIFlyoutBaseOverrides
- (WXCControl*)createPresenter;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPIFlyoutBaseOverrides : RTObject <WUXCPIFlyoutBaseOverrides>
@end

#endif // __WUXCPIFlyoutBaseOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IFlyoutBaseOverrides4
#ifndef __WUXCPIFlyoutBaseOverrides4_DEFINED__
#define __WUXCPIFlyoutBaseOverrides4_DEFINED__

@protocol WUXCPIFlyoutBaseOverrides4
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPIFlyoutBaseOverrides4 : RTObject <WUXCPIFlyoutBaseOverrides4>
@end

#endif // __WUXCPIFlyoutBaseOverrides4_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.FlyoutBase
#ifndef __WUXCPFlyoutBase_DEFINED__
#define __WUXCPFlyoutBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPFlyoutBase : WXDependencyObject
+ (WUXCPFlyoutBase*)getAttachedFlyout:(WXFrameworkElement*)element;
+ (void)setAttachedFlyout:(WXFrameworkElement*)element value:(WUXCPFlyoutBase*)value;
+ (void)showAttachedFlyout:(WXFrameworkElement*)flyoutOwner;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXCPFlyoutPlacementMode placement;
@property WXCLightDismissOverlayMode lightDismissOverlayMode;
@property WXElementSoundMode elementSoundMode;
@property BOOL allowFocusWhenDisabled;
@property BOOL allowFocusOnInteraction;
@property (readonly) WXFrameworkElement* target;
@property (retain) WXDependencyObject* overlayInputPassThroughElement;
+ (WXDependencyProperty*)attachedFlyoutProperty;
+ (WXDependencyProperty*)placementProperty;
+ (WXDependencyProperty*)allowFocusOnInteractionProperty;
+ (WXDependencyProperty*)allowFocusWhenDisabledProperty;
+ (WXDependencyProperty*)elementSoundModeProperty;
+ (WXDependencyProperty*)lightDismissOverlayModeProperty;
+ (WXDependencyProperty*)overlayInputPassThroughElementProperty;
- (EventRegistrationToken)addClosedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpeningEvent:(void(^)(RTObject*, RTObject*))del;
- (void)removeOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addClosingEvent:(void(^)(WUXCPFlyoutBase*, WUXCPFlyoutBaseClosingEventArgs*))del;
- (void)removeClosingEvent:(EventRegistrationToken)tok;
- (void)showAt:(WXFrameworkElement*)placementTarget;
- (void)hide;
- (WXCControl*)createPresenter;
- (void)tryInvokeKeyboardAccelerator:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
- (void)onProcessKeyboardAccelerators:(WUXIProcessKeyboardAcceleratorEventArgs*)args;
@end

#endif // __WUXCPFlyoutBase_DEFINED__

// Windows.UI.Xaml.Controls.Flyout
#ifndef __WXCFlyout_DEFINED__
#define __WXCFlyout_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCFlyout : WUXCPFlyoutBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXStyle* flyoutPresenterStyle;
@property (retain) WXUIElement* content;
+ (WXDependencyProperty*)contentProperty;
+ (WXDependencyProperty*)flyoutPresenterStyleProperty;
@end

#endif // __WXCFlyout_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyout
#ifndef __WXCMenuFlyout_DEFINED__
#define __WXCMenuFlyout_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCMenuFlyout : WUXCPFlyoutBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXStyle* menuFlyoutPresenterStyle;
@property (readonly) NSMutableArray* /* WXCMenuFlyoutItemBase* */ items;
+ (WXDependencyProperty*)menuFlyoutPresenterStyleProperty;
- (void)showAt:(WXUIElement*)targetElement point:(WFPoint*)point;
@end

#endif // __WXCMenuFlyout_DEFINED__

// Windows.UI.Xaml.Media.Brush
#ifndef __WUXMBrush_DEFINED__
#define __WUXMBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMBrush : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WUXMTransform* transform;
@property (retain) WUXMTransform* relativeTransform;
@property double opacity;
+ (WXDependencyProperty*)opacityProperty;
+ (WXDependencyProperty*)relativeTransformProperty;
+ (WXDependencyProperty*)transformProperty;
@end

#endif // __WUXMBrush_DEFINED__

// Windows.UI.Xaml.Media.TileBrush
#ifndef __WUXMTileBrush_DEFINED__
#define __WUXMTileBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXMTileBrush : WUXMBrush
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WUXMStretch stretch;
@property WUXMAlignmentY alignmentY;
@property WUXMAlignmentX alignmentX;
+ (WXDependencyProperty*)alignmentXProperty;
+ (WXDependencyProperty*)alignmentYProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WUXMTileBrush_DEFINED__

// Windows.UI.Xaml.Controls.WebViewBrush
#ifndef __WXCWebViewBrush_DEFINED__
#define __WXCWebViewBrush_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCWebViewBrush : WUXMTileBrush
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * sourceName;
+ (WXDependencyProperty*)sourceNameProperty;
- (void)redraw;
- (void)setSource:(WXCWebView*)source;
@end

#endif // __WXCWebViewBrush_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarIsStencilButtonCheckedChangedEventArgs
#ifndef __WXCInkToolbarIsStencilButtonCheckedChangedEventArgs_DEFINED__
#define __WXCInkToolbarIsStencilButtonCheckedChangedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarIsStencilButtonCheckedChangedEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCInkToolbarStencilButton* stencilButton;
@property (readonly) WXCInkToolbarStencilKind stencilKind;
@end

#endif // __WXCInkToolbarIsStencilButtonCheckedChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarCustomPen
#ifndef __WXCInkToolbarCustomPen_DEFINED__
#define __WXCInkToolbarCustomPen_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarCustomPen : WXDependencyObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
- (WUIIInkDrawingAttributes*)createInkDrawingAttributes:(WUXMBrush*)brush strokeWidth:(double)strokeWidth;
- (WUIIInkDrawingAttributes*)createInkDrawingAttributesCore:(WUXMBrush*)brush strokeWidth:(double)strokeWidth;
@end

#endif // __WXCInkToolbarCustomPen_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbar
#ifndef __WXCInkToolbar_DEFINED__
#define __WXCInkToolbar_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbar : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCInkCanvas* targetInkCanvas;
@property BOOL isRulerButtonChecked;
@property WXCInkToolbarInitialControls initialControls;
@property (retain) WXCInkToolbarToolButton* activeTool;
@property (readonly) WXDependencyObjectCollection* children;
@property (readonly) WUIIInkDrawingAttributes* inkDrawingAttributes;
@property WXCOrientation orientation;
@property BOOL isStencilButtonChecked;
@property WXCInkToolbarButtonFlyoutPlacement buttonFlyoutPlacement;
+ (WXDependencyProperty*)activeToolProperty;
+ (WXDependencyProperty*)childrenProperty;
+ (WXDependencyProperty*)initialControlsProperty;
+ (WXDependencyProperty*)inkDrawingAttributesProperty;
+ (WXDependencyProperty*)isRulerButtonCheckedProperty;
+ (WXDependencyProperty*)targetInkCanvasProperty;
+ (WXDependencyProperty*)buttonFlyoutPlacementProperty;
+ (WXDependencyProperty*)isStencilButtonCheckedProperty;
+ (WXDependencyProperty*)orientationProperty;
- (EventRegistrationToken)addActiveToolChangedEvent:(void(^)(WXCInkToolbar*, RTObject*))del;
- (void)removeActiveToolChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEraseAllClickedEvent:(void(^)(WXCInkToolbar*, RTObject*))del;
- (void)removeEraseAllClickedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addInkDrawingAttributesChangedEvent:(void(^)(WXCInkToolbar*, RTObject*))del;
- (void)removeInkDrawingAttributesChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsRulerButtonCheckedChangedEvent:(void(^)(WXCInkToolbar*, RTObject*))del;
- (void)removeIsRulerButtonCheckedChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addIsStencilButtonCheckedChangedEvent:(void(^)(WXCInkToolbar*, WXCInkToolbarIsStencilButtonCheckedChangedEventArgs*))del;
- (void)removeIsStencilButtonCheckedChangedEvent:(EventRegistrationToken)tok;
- (WXCInkToolbarToolButton*)getToolButton:(WXCInkToolbarTool)tool;
- (WXCInkToolbarToggleButton*)getToggleButton:(WXCInkToolbarToggle)tool;
- (WXCInkToolbarMenuButton*)getMenuButton:(WXCInkToolbarMenuKind)menu;
@end

#endif // __WXCInkToolbar_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarPenConfigurationControl
#ifndef __WXCInkToolbarPenConfigurationControl_DEFINED__
#define __WXCInkToolbarPenConfigurationControl_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarPenConfigurationControl : WXCControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCInkToolbarPenButton* penButton;
+ (WXDependencyProperty*)penButtonProperty;
@end

#endif // __WXCInkToolbarPenConfigurationControl_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarFlyoutItem
#ifndef __WXCInkToolbarFlyoutItem_DEFINED__
#define __WXCInkToolbarFlyoutItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarFlyoutItem : WUXCPButtonBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCInkToolbarFlyoutItemKind kind;
@property BOOL isChecked;
+ (WXDependencyProperty*)isCheckedProperty;
+ (WXDependencyProperty*)kindProperty;
- (EventRegistrationToken)addCheckedEvent:(void(^)(WXCInkToolbarFlyoutItem*, RTObject*))del;
- (void)removeCheckedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUncheckedEvent:(void(^)(WXCInkToolbarFlyoutItem*, RTObject*))del;
- (void)removeUncheckedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCInkToolbarFlyoutItem_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarMenuButton
#ifndef __WXCInkToolbarMenuButton_DEFINED__
#define __WXCInkToolbarMenuButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarMenuButton : WUXCPToggleButton
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isExtensionGlyphShown;
@property (readonly) WXCInkToolbarMenuKind menuKind;
+ (WXDependencyProperty*)isExtensionGlyphShownProperty;
@end

#endif // __WXCInkToolbarMenuButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarStencilButton
#ifndef __WXCInkToolbarStencilButton_DEFINED__
#define __WXCInkToolbarStencilButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarStencilButton : WXCInkToolbarMenuButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCInkToolbarStencilKind selectedStencil;
@property BOOL isRulerItemVisible;
@property BOOL isProtractorItemVisible;
@property (readonly) WUIIInkPresenterProtractor* protractor;
@property (readonly) WUIIInkPresenterRuler* ruler;
+ (WXDependencyProperty*)isProtractorItemVisibleProperty;
+ (WXDependencyProperty*)isRulerItemVisibleProperty;
+ (WXDependencyProperty*)protractorProperty;
+ (WXDependencyProperty*)rulerProperty;
+ (WXDependencyProperty*)selectedStencilProperty;
@end

#endif // __WXCInkToolbarStencilButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarToggleButton
#ifndef __WXCInkToolbarToggleButton_DEFINED__
#define __WXCInkToolbarToggleButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarToggleButton : WXCCheckBox
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WXCInkToolbarToggle toggleKind;
@end

#endif // __WXCInkToolbarToggleButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarToolButton
#ifndef __WXCInkToolbarToolButton_DEFINED__
#define __WXCInkToolbarToolButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarToolButton : WXCRadioButton
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isExtensionGlyphShown;
@property (readonly) WXCInkToolbarTool toolKind;
+ (WXDependencyProperty*)isExtensionGlyphShownProperty;
@end

#endif // __WXCInkToolbarToolButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarCustomToggleButton
#ifndef __WXCInkToolbarCustomToggleButton_DEFINED__
#define __WXCInkToolbarCustomToggleButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarCustomToggleButton : WXCInkToolbarToggleButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCInkToolbarCustomToggleButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarCustomToolButton
#ifndef __WXCInkToolbarCustomToolButton_DEFINED__
#define __WXCInkToolbarCustomToolButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarCustomToolButton : WXCInkToolbarToolButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXUIElement* configurationContent;
+ (WXDependencyProperty*)configurationContentProperty;
@end

#endif // __WXCInkToolbarCustomToolButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarEraserButton
#ifndef __WXCInkToolbarEraserButton_DEFINED__
#define __WXCInkToolbarEraserButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarEraserButton : WXCInkToolbarToolButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL isClearAllVisible;
+ (WXDependencyProperty*)isClearAllVisibleProperty;
@end

#endif // __WXCInkToolbarEraserButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarPenButton
#ifndef __WXCInkToolbarPenButton_DEFINED__
#define __WXCInkToolbarPenButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarPenButton : WXCInkToolbarToolButton
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property double selectedStrokeWidth;
@property int selectedBrushIndex;
@property (retain) NSMutableArray* /* WUXMBrush* */ palette;
@property double minStrokeWidth;
@property double maxStrokeWidth;
@property (readonly) WUXMBrush* selectedBrush;
+ (WXDependencyProperty*)maxStrokeWidthProperty;
+ (WXDependencyProperty*)minStrokeWidthProperty;
+ (WXDependencyProperty*)paletteProperty;
+ (WXDependencyProperty*)selectedBrushIndexProperty;
+ (WXDependencyProperty*)selectedBrushProperty;
+ (WXDependencyProperty*)selectedStrokeWidthProperty;
@end

#endif // __WXCInkToolbarPenButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarRulerButton
#ifndef __WXCInkToolbarRulerButton_DEFINED__
#define __WXCInkToolbarRulerButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarRulerButton : WXCInkToolbarToggleButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WUIIInkPresenterRuler* ruler;
+ (WXDependencyProperty*)rulerProperty;
@end

#endif // __WXCInkToolbarRulerButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarBallpointPenButton
#ifndef __WXCInkToolbarBallpointPenButton_DEFINED__
#define __WXCInkToolbarBallpointPenButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarBallpointPenButton : WXCInkToolbarPenButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCInkToolbarBallpointPenButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarCustomPenButton
#ifndef __WXCInkToolbarCustomPenButton_DEFINED__
#define __WXCInkToolbarCustomPenButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarCustomPenButton : WXCInkToolbarPenButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCInkToolbarCustomPen* customPen;
@property (retain) WXUIElement* configurationContent;
+ (WXDependencyProperty*)configurationContentProperty;
+ (WXDependencyProperty*)customPenProperty;
@end

#endif // __WXCInkToolbarCustomPenButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarHighlighterButton
#ifndef __WXCInkToolbarHighlighterButton_DEFINED__
#define __WXCInkToolbarHighlighterButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarHighlighterButton : WXCInkToolbarPenButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCInkToolbarHighlighterButton_DEFINED__

// Windows.UI.Xaml.Controls.InkToolbarPencilButton
#ifndef __WXCInkToolbarPencilButton_DEFINED__
#define __WXCInkToolbarPencilButton_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCInkToolbarPencilButton : WXCInkToolbarPenButton
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCInkToolbarPencilButton_DEFINED__

// Windows.UI.Xaml.Controls.PivotItemEventArgs
#ifndef __WXCPivotItemEventArgs_DEFINED__
#define __WXCPivotItemEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPivotItemEventArgs : RTObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXCPivotItem* item;
@end

#endif // __WXCPivotItemEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.DatePickedEventArgs
#ifndef __WXCDatePickedEventArgs_DEFINED__
#define __WXCDatePickedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDatePickedEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFDateTime* newDate __attribute__ ((ns_returns_not_retained));
@property (readonly) WFDateTime* oldDate;
@end

#endif // __WXCDatePickedEventArgs_DEFINED__

// Windows.UI.Xaml.Data.ICustomPropertyProvider
#ifndef __WUXDICustomPropertyProvider_DEFINED__
#define __WUXDICustomPropertyProvider_DEFINED__

@protocol WUXDICustomPropertyProvider
@property (readonly) WUXITypeName* type;
- (RTObject<WUXDICustomProperty>*)getCustomProperty:(NSString *)name;
- (RTObject<WUXDICustomProperty>*)getIndexedProperty:(NSString *)name type:(WUXITypeName*)type;
- (NSString *)getStringRepresentation;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXDICustomPropertyProvider : RTObject <WUXDICustomPropertyProvider>
@end

#endif // __WUXDICustomPropertyProvider_DEFINED__

// Windows.UI.Xaml.Controls.DatePickerFlyoutItem
#ifndef __WXCDatePickerFlyoutItem_DEFINED__
#define __WXCDatePickerFlyoutItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDatePickerFlyoutItem : WXDependencyObject <WUXDICustomPropertyProvider>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * secondaryText;
@property (retain) NSString * primaryText;
@property (readonly) WUXITypeName* type;
+ (WXDependencyProperty*)primaryTextProperty;
+ (WXDependencyProperty*)secondaryTextProperty;
- (RTObject<WUXDICustomProperty>*)getCustomProperty:(NSString *)name;
- (RTObject<WUXDICustomProperty>*)getIndexedProperty:(NSString *)name type:(WUXITypeName*)type;
- (NSString *)getStringRepresentation;
@end

#endif // __WXCDatePickerFlyoutItem_DEFINED__

// Windows.UI.Xaml.Controls.ItemsPickedEventArgs
#ifndef __WXCItemsPickedEventArgs_DEFINED__
#define __WXCItemsPickedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCItemsPickedEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* RTObject* */ addedItems;
@property (readonly) NSMutableArray* /* RTObject* */ removedItems;
@end

#endif // __WXCItemsPickedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.PickerConfirmedEventArgs
#ifndef __WXCPickerConfirmedEventArgs_DEFINED__
#define __WXCPickerConfirmedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPickerConfirmedEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCPickerConfirmedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TimePickedEventArgs
#ifndef __WXCTimePickedEventArgs_DEFINED__
#define __WXCTimePickedEventArgs_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTimePickedEventArgs : WXDependencyObject
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WFTimeSpan* newTime __attribute__ ((ns_returns_not_retained));
@property (readonly) WFTimeSpan* oldTime;
@end

#endif // __WXCTimePickedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.DatePickerFlyoutPresenter
#ifndef __WXCDatePickerFlyoutPresenter_DEFINED__
#define __WXCDatePickerFlyoutPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDatePickerFlyoutPresenter : WXCControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCDatePickerFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.ListPickerFlyoutPresenter
#ifndef __WXCListPickerFlyoutPresenter_DEFINED__
#define __WXCListPickerFlyoutPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListPickerFlyoutPresenter : WXCControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCListPickerFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.TimePickerFlyoutPresenter
#ifndef __WXCTimePickerFlyoutPresenter_DEFINED__
#define __WXCTimePickerFlyoutPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTimePickerFlyoutPresenter : WXCControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCTimePickerFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.PickerFlyoutPresenter
#ifndef __WXCPickerFlyoutPresenter_DEFINED__
#define __WXCPickerFlyoutPresenter_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPickerFlyoutPresenter : WXCContentControl
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@end

#endif // __WXCPickerFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.Pivot
#ifndef __WXCPivot_DEFINED__
#define __WXCPivot_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPivot : WXCItemsControl
+ (WXCPivotSlideInAnimationGroup)getSlideInAnimationGroup:(WXFrameworkElement*)element;
+ (void)setSlideInAnimationGroup:(WXFrameworkElement*)element value:(WXCPivotSlideInAnimationGroup)value;
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXDataTemplate* titleTemplate;
@property (retain) RTObject* title;
@property (retain) RTObject* selectedItem;
@property int selectedIndex;
@property BOOL isLocked;
@property (retain) WXDataTemplate* headerTemplate;
@property (retain) WXDataTemplate* rightHeaderTemplate;
@property (retain) RTObject* rightHeader;
@property (retain) WXDataTemplate* leftHeaderTemplate;
@property (retain) RTObject* leftHeader;
@property BOOL isHeaderItemsCarouselEnabled;
@property WXCPivotHeaderFocusVisualPlacement headerFocusVisualPlacement;
+ (WXDependencyProperty*)isLockedProperty;
+ (WXDependencyProperty*)selectedItemProperty;
+ (WXDependencyProperty*)slideInAnimationGroupProperty;
+ (WXDependencyProperty*)titleProperty;
+ (WXDependencyProperty*)titleTemplateProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)selectedIndexProperty;
+ (WXDependencyProperty*)leftHeaderProperty;
+ (WXDependencyProperty*)leftHeaderTemplateProperty;
+ (WXDependencyProperty*)rightHeaderProperty;
+ (WXDependencyProperty*)rightHeaderTemplateProperty;
+ (WXDependencyProperty*)isHeaderItemsCarouselEnabledProperty;
+ (WXDependencyProperty*)headerFocusVisualPlacementProperty;
- (EventRegistrationToken)addPivotItemLoadedEvent:(void(^)(WXCPivot*, WXCPivotItemEventArgs*))del;
- (void)removePivotItemLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPivotItemLoadingEvent:(void(^)(WXCPivot*, WXCPivotItemEventArgs*))del;
- (void)removePivotItemLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPivotItemUnloadedEvent:(void(^)(WXCPivot*, WXCPivotItemEventArgs*))del;
- (void)removePivotItemUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPivotItemUnloadingEvent:(void(^)(WXCPivot*, WXCPivotItemEventArgs*))del;
- (void)removePivotItemUnloadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXCSelectionChangedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCPivot_DEFINED__

// Windows.UI.Xaml.Controls.PivotItem
#ifndef __WXCPivotItem_DEFINED__
#define __WXCPivotItem_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPivotItem : WXCContentControl
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) RTObject* header;
+ (WXDependencyProperty*)headerProperty;
@end

#endif // __WXCPivotItem_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IPickerFlyoutBaseOverrides
#ifndef __WUXCPIPickerFlyoutBaseOverrides_DEFINED__
#define __WUXCPIPickerFlyoutBaseOverrides_DEFINED__

@protocol WUXCPIPickerFlyoutBaseOverrides
- (void)onConfirmed;
- (BOOL)shouldShowConfirmationButtons;
@end

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPIPickerFlyoutBaseOverrides : RTObject <WUXCPIPickerFlyoutBaseOverrides>
@end

#endif // __WUXCPIPickerFlyoutBaseOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.PickerFlyoutBase
#ifndef __WUXCPPickerFlyoutBase_DEFINED__
#define __WUXCPPickerFlyoutBase_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WUXCPPickerFlyoutBase : WUXCPFlyoutBase
+ (NSString *)getTitle:(WXDependencyObject*)element;
+ (void)setTitle:(WXDependencyObject*)element value:(NSString *)value;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
+ (WXDependencyProperty*)titleProperty;
- (void)onConfirmed;
- (BOOL)shouldShowConfirmationButtons;
@end

#endif // __WUXCPPickerFlyoutBase_DEFINED__

// Windows.UI.Xaml.Controls.DatePickerFlyout
#ifndef __WXCDatePickerFlyout_DEFINED__
#define __WXCDatePickerFlyout_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCDatePickerFlyout : WUXCPPickerFlyoutBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property BOOL yearVisible;
@property BOOL monthVisible;
@property (retain) WFDateTime* minYear;
@property (retain) WFDateTime* maxYear;
@property BOOL dayVisible;
@property (retain) WFDateTime* date;
@property (retain) NSString * calendarIdentifier;
@property (retain) NSString * yearFormat;
@property (retain) NSString * monthFormat;
@property (retain) NSString * dayFormat;
+ (WXDependencyProperty*)calendarIdentifierProperty;
+ (WXDependencyProperty*)dateProperty;
+ (WXDependencyProperty*)dayVisibleProperty;
+ (WXDependencyProperty*)maxYearProperty;
+ (WXDependencyProperty*)minYearProperty;
+ (WXDependencyProperty*)monthVisibleProperty;
+ (WXDependencyProperty*)yearVisibleProperty;
+ (WXDependencyProperty*)dayFormatProperty;
+ (WXDependencyProperty*)monthFormatProperty;
+ (WXDependencyProperty*)yearFormatProperty;
- (EventRegistrationToken)addDatePickedEvent:(void(^)(WXCDatePickerFlyout*, WXCDatePickedEventArgs*))del;
- (void)removeDatePickedEvent:(EventRegistrationToken)tok;
- (void)showAtAsync:(WXFrameworkElement*)target success:(void (^)(id /* WFDateTime* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXCDatePickerFlyout_DEFINED__

// Windows.UI.Xaml.Controls.ListPickerFlyout
#ifndef __WXCListPickerFlyout_DEFINED__
#define __WXCListPickerFlyout_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCListPickerFlyout : WUXCPPickerFlyoutBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property WXCListPickerFlyoutSelectionMode selectionMode;
@property (retain) NSString * selectedValuePath;
@property (retain) RTObject* selectedValue;
@property (retain) RTObject* selectedItem;
@property int selectedIndex;
@property (retain) RTObject* itemsSource;
@property (retain) WXDataTemplate* itemTemplate;
@property (retain) NSString * displayMemberPath;
@property (readonly) NSMutableArray* /* RTObject* */ selectedItems;
+ (WXDependencyProperty*)displayMemberPathProperty;
+ (WXDependencyProperty*)itemTemplateProperty;
+ (WXDependencyProperty*)itemsSourceProperty;
+ (WXDependencyProperty*)selectedIndexProperty;
+ (WXDependencyProperty*)selectedItemProperty;
+ (WXDependencyProperty*)selectedValuePathProperty;
+ (WXDependencyProperty*)selectedValueProperty;
+ (WXDependencyProperty*)selectionModeProperty;
- (EventRegistrationToken)addItemsPickedEvent:(void(^)(WXCListPickerFlyout*, WXCItemsPickedEventArgs*))del;
- (void)removeItemsPickedEvent:(EventRegistrationToken)tok;
- (void)showAtAsync:(WXFrameworkElement*)target success:(void (^)(NSArray* /* RTObject* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXCListPickerFlyout_DEFINED__

// Windows.UI.Xaml.Controls.PickerFlyout
#ifndef __WXCPickerFlyout_DEFINED__
#define __WXCPickerFlyout_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCPickerFlyout : WUXCPPickerFlyoutBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WXUIElement* content;
@property BOOL confirmationButtonsVisible;
+ (WXDependencyProperty*)confirmationButtonsVisibleProperty;
+ (WXDependencyProperty*)contentProperty;
- (EventRegistrationToken)addConfirmedEvent:(void(^)(WXCPickerFlyout*, WXCPickerConfirmedEventArgs*))del;
- (void)removeConfirmedEvent:(EventRegistrationToken)tok;
- (void)showAtAsync:(WXFrameworkElement*)target success:(void (^)(BOOL))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXCPickerFlyout_DEFINED__

// Windows.UI.Xaml.Controls.TimePickerFlyout
#ifndef __WXCTimePickerFlyout_DEFINED__
#define __WXCTimePickerFlyout_DEFINED__

OBJCUWPWINDOWSUIXAMLEXPORT
@interface WXCTimePickerFlyout : WUXCPPickerFlyoutBase
+ (instancetype)make __attribute__ ((ns_returns_retained));
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WFTimeSpan* time;
@property int minuteIncrement;
@property (retain) NSString * clockIdentifier;
+ (WXDependencyProperty*)clockIdentifierProperty;
+ (WXDependencyProperty*)minuteIncrementProperty;
+ (WXDependencyProperty*)timeProperty;
- (EventRegistrationToken)addTimePickedEvent:(void(^)(WXCTimePickerFlyout*, WXCTimePickedEventArgs*))del;
- (void)removeTimePickedEvent:(EventRegistrationToken)tok;
- (void)showAtAsync:(WXFrameworkElement*)target success:(void (^)(id /* WFTimeSpan* */))success failure:(void (^)(NSError*))failure;
@end

#endif // __WXCTimePickerFlyout_DEFINED__

