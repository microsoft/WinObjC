//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#include "interopBase.h"
@class WXCBackClickEventArgs, WXCDragItemsStartingEventArgs, WXCNotifyEventArgs, WXCSemanticZoomViewChangedEventArgs,
    WXCTextControlPasteEventArgs, WXCColumnDefinitionCollection, WXCContainerContentChangingEventArgs, WXCDataTemplateSelector,
    WXCDatePickerValueChangedEventArgs, WXCRowDefinitionCollection, WXCStyleSelector, WXCGroupStyle, WXCGroupStyleSelector,
    WXCSemanticZoomLocation, WXCItemCollection, WXCItemContainerGenerator, WXCUIElementCollection, WXCScrollViewerViewChangedEventArgs,
    WXCScrollViewerViewChangingEventArgs, WXCScrollViewerView, WXCToolTipService, WXCHubSectionHeaderClickEventArgs,
    WXCSectionsInViewChangedEventArgs, WXCWebViewNavigationFailedEventArgs, WXCHubSectionCollection, WXCSearchBoxQueryChangedEventArgs,
    WXCSearchBoxSuggestionsRequestedEventArgs, WXCSearchBoxQuerySubmittedEventArgs, WXCSearchBoxResultSuggestionChosenEventArgs,
    WXCTimePickerValueChangedEventArgs, WXCWebViewNavigationStartingEventArgs, WXCWebViewContentLoadingEventArgs,
    WXCWebViewDOMContentLoadedEventArgs, WXCWebViewNavigationCompletedEventArgs, WXCWebViewLongRunningScriptDetectedEventArgs,
    WXCWebViewUnviewableContentIdentifiedEventArgs, WXCColumnDefinition, WXCRowDefinition, WXCFlyout, WXCMenuFlyout,
    WXCCleanUpVirtualizedItemEventArgs, WXCContextMenuEventArgs, WXCItemClickEventArgs, WXCSelectionChangedEventArgs,
    WXCTextChangedEventArgs, WXCItemsPanelTemplate, WXCBorder, WXCCaptureElement, WXCContentPresenter, WXCImage, WXCPanel, WXCCanvas,
    WXCGrid, WXCItemsPresenter, WXCMediaElement, WXCRichTextBlockOverflow, WXCRichTextBlock, WXCScrollContentPresenter, WXCStackPanel,
    WXCTextBlock, WXCVariableSizedWrapGrid, WXCViewbox, WXCVirtualizingPanel, WXCVirtualizingStackPanel, WXCIconElement, WXCBitmapIcon,
    WXCFontIcon, WXCItemsStackPanel, WXCItemsWrapGrid, WXCPathIcon, WXCSwapChainBackgroundPanel, WXCSwapChainPanel, WXCSymbolIcon,
    WXCWebView, WXCWrapGrid, WXCWebViewBrush, WXCControl, WXCContentControl, WXCComboBoxItem, WXCDatePicker, WXCFlipViewItem,
    WXCGridViewItem, WXCGroupItem, WXCSemanticZoom, WXCItemsControl, WXCListBoxItem, WXCListViewItem, WXCPasswordBox, WXCProgressRing,
    WXCRichEditBox, WXCScrollViewer, WXCSettingsFlyout, WXCTextBox, WXCToggleSwitch, WXCToolTip, WXCUserControl, WXCButton,
    WXCHyperlinkButton, WXCProgressBar, WXCSlider, WXCComboBox, WXCListViewBase, WXCFlipView, WXCGridView, WXCListBox, WXCListView,
    WXCCheckBox, WXCRadioButton, WXCAppBar, WXCAppBarButton, WXCAppBarSeparator, WXCAppBarToggleButton, WXCCommandBar, WXCFlyoutPresenter,
    WXCFrame, WXCHubSection, WXCHub, WXCListViewBaseHeaderItem, WXCGridViewHeaderItem, WXCListViewHeaderItem, WXCMenuFlyoutItemBase,
    WXCMenuFlyoutItem, WXCMenuFlyoutPresenter, WXCMenuFlyoutSeparator, WXCPage, WXCSearchBox, WXCTimePicker, WXCToggleMenuFlyoutItem,
    WXCControlTemplate;
@protocol WXCIBackClickEventArgs
, WXCIBorder, WXCIBorderStatics, WXCIButton, WXCIButtonFactory, WXCIButtonWithFlyout, WXCIButtonStaticsWithFlyout, WXCICanvas,
    WXCICanvasStatics, WXCICanvasFactory, WXCICaptureElement, WXCICaptureElementStatics, WXCICheckBox, WXCICheckBoxFactory,
    WXCICleanUpVirtualizedItemEventArgs, WXCIColumnDefinition, WXCIColumnDefinitionStatics, WXCIComboBox, WXCIComboBoxOverrides,
    WXCIComboBoxStatics, WXCIComboBoxFactory, WXCIComboBox2, WXCIComboBoxStatics2, WXCIComboBoxItem, WXCIComboBoxItemFactory,
    WXCIContainerContentChangingEventArgs, WXCIContentControl, WXCIContentControlOverrides, WXCIContentControlStatics,
    WXCIContentControlFactory, WXCIContentControl2, WXCIContentPresenter, WXCIContentPresenterOverrides, WXCIContentPresenterStatics,
    WXCIContentPresenterFactory, WXCIContentPresenter2, WXCIContentPresenterStatics2, WXCIContextMenuEventArgs, WXCIDataTemplateSelector,
    WXCIDataTemplateSelectorOverrides, WXCIDataTemplateSelectorFactory, WXCIDataTemplateSelector2, WXCIDataTemplateSelectorOverrides2,
    WXCIDatePicker, WXCIDatePickerStatics, WXCIDatePickerFactory, WXCIDatePickerValueChangedEventArgs, WXCIDragItemsStartingEventArgs,
    WXCIFlipView, WXCIFlipViewFactory, WXCIFlipView2, WXCIFlipViewStatics2, WXCIFlipViewItem, WXCIFlipViewItemFactory, WXCIGrid,
    WXCIGridStatics, WXCIGridFactory, WXCIGridView, WXCIGridViewFactory, WXCIGridViewItem, WXCIGridViewItemFactory, WXCIGroupItem,
    WXCIGroupItemFactory, WXCIGroupStyle, WXCIGroupStyleFactory, WXCIGroupStyle2, WXCIGroupStyleSelector, WXCIGroupStyleSelectorOverrides,
    WXCIGroupStyleSelectorFactory, WXCIHyperlinkButton, WXCIHyperlinkButtonStatics, WXCIHyperlinkButtonFactory, WXCIItemContainerMapping,
    WXCIImage, WXCIImageStatics, WXCINavigate, WXCISemanticZoomInformation, WXCIItemClickEventArgs, WXCIItemContainerGenerator,
    WXCIItemsControl, WXCIItemsControlOverrides, WXCIItemsControlStatics, WXCIItemsControlFactory, WXCIItemsControl2,
    WXCIItemsPanelTemplate, WXCIItemsPresenter, WXCIItemsPresenterStatics, WXCIItemsPresenter2, WXCIItemsPresenterStatics2, WXCIListBox,
    WXCIListBoxStatics, WXCIListBoxFactory, WXCIListBoxItem, WXCIListBoxItemFactory, WXCIListView, WXCIListViewFactory, WXCIListViewBase,
    WXCIListViewBaseStatics, WXCIListViewBaseFactory, WXCIListViewBase2, WXCIListViewBaseStatics2, WXCIListViewItem,
    WXCIListViewItemFactory, WXCIMediaElement, WXCIMediaElementStatics, WXCIMediaElement2, WXCIMediaElementStatics2, WXCINotifyEventArgs,
    WXCINotifyEventArgs2, WXCIPanel, WXCIPanelStatics, WXCIPanelFactory, WXCIPasswordBox, WXCIPasswordBoxStatics, WXCIPasswordBox2,
    WXCIPasswordBoxStatics2, WXCIProgressBar, WXCIProgressBarStatics, WXCIProgressBarFactory, WXCIProgressRing, WXCIProgressRingStatics,
    WXCIRadioButton, WXCIRadioButtonStatics, WXCIRadioButtonFactory, WXCIRichEditBox, WXCIRichEditBoxStatics, WXCIRichEditBoxFactory,
    WXCIRichEditBox2, WXCIRichEditBoxStatics2, WXCIRichTextBlock, WXCIRichTextBlockStatics, WXCIRichTextBlock2, WXCIRichTextBlockStatics2,
    WXCIRichTextBlockOverflow, WXCIRichTextBlockOverflowStatics, WXCIRichTextBlockOverflow2, WXCIRichTextBlockOverflowStatics2,
    WXCIRowDefinition, WXCIRowDefinitionStatics, WXCIScrollContentPresenter, WXCIScrollViewer, WXCIScrollViewerStatics, WXCIScrollViewer2,
    WXCIScrollViewerStatics2, WXCIScrollViewerView, WXCIScrollViewerViewChangedEventArgs, WXCIScrollViewerViewChangingEventArgs,
    WXCISelectionChangedEventArgs, WXCISelectionChangedEventArgsFactory, WXCISemanticZoom, WXCISemanticZoomStatics,
    WXCISemanticZoomLocation, WXCISemanticZoomViewChangedEventArgs, WXCISettingsFlyout, WXCISettingsFlyoutStatics,
    WXCISettingsFlyoutFactory, WXCISlider, WXCISliderStatics, WXCISliderFactory, WXCISlider2, WXCISliderStatics2, WXCIStackPanel,
    WXCIStackPanelStatics, WXCIStackPanelFactory, WXCIStyleSelector, WXCIStyleSelectorOverrides, WXCIStyleSelectorFactory, WXCITextBlock,
    WXCITextBlockStatics, WXCITextBlock2, WXCITextBlockStatics2, WXCITextBox, WXCITextBoxStatics, WXCITextBoxFactory, WXCITextBox2,
    WXCITextBoxStatics2, WXCITextChangedEventArgs, WXCITextControlPasteEventArgs, WXCIToggleSwitch, WXCIToggleSwitchOverrides,
    WXCIToggleSwitchStatics, WXCIToolTip, WXCIToolTipStatics, WXCIToolTipFactory, WXCIToolTipService, WXCIToolTipServiceStatics,
    WXCIUIElementCollection, WXCIUserControl, WXCIUserControlStatics, WXCIUserControlFactory, WXCIVariableSizedWrapGrid,
    WXCIVariableSizedWrapGridStatics, WXCIViewbox, WXCIViewboxStatics, WXCIVirtualizingPanel, WXCIVirtualizingPanelOverrides,
    WXCIVirtualizingPanelProtected, WXCIVirtualizingPanelFactory, WXCIVirtualizingStackPanel, WXCIVirtualizingStackPanelOverrides,
    WXCIVirtualizingStackPanelStatics, WXCIAppBar, WXCIAppBarOverrides, WXCIAppBarStatics, WXCIAppBarFactory, WXCIAppBarButton,
    WXCIAppBarButtonStatics, WXCIAppBarButtonFactory, WXCIAppBarSeparator, WXCIAppBarSeparatorStatics, WXCIAppBarSeparatorFactory,
    WXCIAppBarToggleButton, WXCIAppBarToggleButtonStatics, WXCIAppBarToggleButtonFactory, WXCIBitmapIcon, WXCIBitmapIconStatics,
    WXCIBitmapIconFactory, WXCICommandBar, WXCICommandBarElement, WXCICommandBarStatics, WXCICommandBarFactory, WXCIFlyout,
    WXCIFlyoutStatics, WXCIFlyoutFactory, WXCIFlyoutPresenter, WXCIFlyoutPresenterFactory, WXCIFontIcon, WXCIFontIconStatics,
    WXCIFontIconFactory, WXCIFrame, WXCIFrameStatics, WXCIFrameFactory, WXCIFrame2, WXCIFrameStatics2, WXCIGridViewHeaderItem,
    WXCIGridViewHeaderItemFactory, WXCIHub, WXCIHubStatics, WXCIHubFactory, WXCIHubSection, WXCIHubSectionStatics, WXCIHubSectionFactory,
    WXCIHubSectionHeaderClickEventArgs, WXCIIconElement, WXCIIconElementStatics, WXCIIconElementFactory, WXCIItemsStackPanel,
    WXCIItemsStackPanelStatics, WXCIItemsWrapGrid, WXCIItemsWrapGridStatics, WXCIListViewBaseHeaderItem, WXCIListViewBaseHeaderItemFactory,
    WXCIListViewHeaderItem, WXCIListViewHeaderItemFactory, WXCIMenuFlyout, WXCIMenuFlyoutStatics, WXCIMenuFlyoutFactory, WXCIMenuFlyoutItem,
    WXCIMenuFlyoutItemStatics, WXCIMenuFlyoutItemFactory, WXCIMenuFlyoutItemBase, WXCIMenuFlyoutItemBaseFactory, WXCIMenuFlyoutPresenter,
    WXCIMenuFlyoutPresenterFactory, WXCIMenuFlyoutSeparator, WXCIMenuFlyoutSeparatorFactory, WXCIPage, WXCIPageOverrides, WXCIPageStatics,
    WXCIPageFactory, WXCIPathIcon, WXCIPathIconStatics, WXCIPathIconFactory, WXCISearchBox, WXCISearchBoxStatics, WXCISearchBoxFactory,
    WXCISearchBoxQueryChangedEventArgs, WXCISearchBoxQuerySubmittedEventArgs, WXCISearchBoxResultSuggestionChosenEventArgs,
    WXCISearchBoxSuggestionsRequestedEventArgs, WXCISectionsInViewChangedEventArgs, WXCISectionsInViewChangedEventArgsFactory,
    WXCISwapChainBackgroundPanel, WXCISwapChainBackgroundPanelFactory, WXCISwapChainBackgroundPanel2, WXCISwapChainPanel,
    WXCISwapChainPanelStatics, WXCISwapChainPanelFactory, WXCISymbolIcon, WXCISymbolIconStatics, WXCISymbolIconFactory, WXCITimePicker,
    WXCITimePickerStatics, WXCITimePickerFactory, WXCITimePickerValueChangedEventArgs, WXCIToggleMenuFlyoutItem,
    WXCIToggleMenuFlyoutItemStatics, WXCIToggleMenuFlyoutItemFactory, WXCIWebView, WXCIWebViewStatics, WXCIWebView2, WXCIWebViewStatics2,
    WXCIWebViewBrush, WXCIWebViewBrushStatics, WXCIWebViewContentLoadingEventArgs, WXCIWebViewDOMContentLoadedEventArgs,
    WXCIWebViewLongRunningScriptDetectedEventArgs, WXCIWebViewNavigationCompletedEventArgs, WXCIWebViewNavigationFailedEventArgs,
    WXCIWebViewNavigationStartingEventArgs, WXCIWebViewUnviewableContentIdentifiedEventArgs, WXCIWrapGrid, WXCIWrapGridStatics, WXCIControl,
    WXCIControlOverrides, WXCIControlProtected, WXCIControlStatics, WXCIControlFactory, WXCIControlTemplate;

// Windows.UI.Xaml.Controls.ClickMode
enum _WXCClickMode {
    WXCClickModeRelease = 0,
    WXCClickModePress = 1,
    WXCClickModeHover = 2,
};
typedef unsigned WXCClickMode;

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
};
typedef unsigned WXCItemsUpdatingScrollMode;

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
};
typedef unsigned WXCSymbol;

#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUIXamlDocuments.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsUIXaml.h"
#include "WindowsUI.h"
#include "WindowsUIXamlData.h"
#include "WindowsUIXamlControlsPrimitives.h"
#include "WindowsMediaCapture.h"
#include "WindowsFoundation.h"
#include "WindowsUIText.h"
#include "WindowsMediaPlayTo.h"
#include "WindowsUIXamlInterop.h"
#include "WindowsMediaProtection.h"
#include "WindowsStorageStreams.h"
#include "WindowsMediaCore.h"
#include "WindowsUIXamlInput.h"
#include "WindowsWebHttp.h"
#include "WindowsUIXamlNavigation.h"
#include "WindowsApplicationModelSearch.h"
#include "WindowsSystem.h"
#include "WindowsUICore.h"
#include "WindowsWeb.h"
#include "WindowsUIXamlAutomationPeers.h"
// Windows.UI.Xaml.Controls.BackClickEventHandler
#ifndef __WXCBackClickEventHandler__DEFINED
#define __WXCBackClickEventHandler__DEFINED
typedef void (^WXCBackClickEventHandler)(RTObject* sender, WXCBackClickEventArgs* e);
#endif // __WXCBackClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.CleanUpVirtualizedItemEventHandler
#ifndef __WXCCleanUpVirtualizedItemEventHandler__DEFINED
#define __WXCCleanUpVirtualizedItemEventHandler__DEFINED
typedef void (^WXCCleanUpVirtualizedItemEventHandler)(RTObject* sender, WXCCleanUpVirtualizedItemEventArgs* e);
#endif // __WXCCleanUpVirtualizedItemEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ContextMenuOpeningEventHandler
#ifndef __WXCContextMenuOpeningEventHandler__DEFINED
#define __WXCContextMenuOpeningEventHandler__DEFINED
typedef void (^WXCContextMenuOpeningEventHandler)(RTObject* sender, WXCContextMenuEventArgs* e);
#endif // __WXCContextMenuOpeningEventHandler__DEFINED

// Windows.UI.Xaml.Controls.DragItemsStartingEventHandler
#ifndef __WXCDragItemsStartingEventHandler__DEFINED
#define __WXCDragItemsStartingEventHandler__DEFINED
typedef void (^WXCDragItemsStartingEventHandler)(RTObject* sender, WXCDragItemsStartingEventArgs* e);
#endif // __WXCDragItemsStartingEventHandler__DEFINED

// Windows.UI.Xaml.Controls.HubSectionHeaderClickEventHandler
#ifndef __WXCHubSectionHeaderClickEventHandler__DEFINED
#define __WXCHubSectionHeaderClickEventHandler__DEFINED
typedef void (^WXCHubSectionHeaderClickEventHandler)(RTObject* sender, WXCHubSectionHeaderClickEventArgs* e);
#endif // __WXCHubSectionHeaderClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ItemClickEventHandler
#ifndef __WXCItemClickEventHandler__DEFINED
#define __WXCItemClickEventHandler__DEFINED
typedef void (^WXCItemClickEventHandler)(RTObject* sender, WXCItemClickEventArgs* e);
#endif // __WXCItemClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.NotifyEventHandler
#ifndef __WXCNotifyEventHandler__DEFINED
#define __WXCNotifyEventHandler__DEFINED
typedef void (^WXCNotifyEventHandler)(RTObject* sender, WXCNotifyEventArgs* e);
#endif // __WXCNotifyEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.ItemsChangedEventHandler
#ifndef __WUXCPItemsChangedEventHandler__DEFINED
#define __WUXCPItemsChangedEventHandler__DEFINED
typedef void (^WUXCPItemsChangedEventHandler)(RTObject* sender, WUXCPItemsChangedEventArgs* e);
#endif // __WUXCPItemsChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.RangeBaseValueChangedEventHandler
#ifndef __WUXCPRangeBaseValueChangedEventHandler__DEFINED
#define __WUXCPRangeBaseValueChangedEventHandler__DEFINED
typedef void (^WUXCPRangeBaseValueChangedEventHandler)(RTObject* sender, WUXCPRangeBaseValueChangedEventArgs* e);
#endif // __WUXCPRangeBaseValueChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SectionsInViewChangedEventHandler
#ifndef __WXCSectionsInViewChangedEventHandler__DEFINED
#define __WXCSectionsInViewChangedEventHandler__DEFINED
typedef void (^WXCSectionsInViewChangedEventHandler)(RTObject* sender, WXCSectionsInViewChangedEventArgs* e);
#endif // __WXCSectionsInViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SelectionChangedEventHandler
#ifndef __WXCSelectionChangedEventHandler__DEFINED
#define __WXCSelectionChangedEventHandler__DEFINED
typedef void (^WXCSelectionChangedEventHandler)(RTObject* sender, WXCSelectionChangedEventArgs* e);
#endif // __WXCSelectionChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SemanticZoomViewChangedEventHandler
#ifndef __WXCSemanticZoomViewChangedEventHandler__DEFINED
#define __WXCSemanticZoomViewChangedEventHandler__DEFINED
typedef void (^WXCSemanticZoomViewChangedEventHandler)(RTObject* sender, WXCSemanticZoomViewChangedEventArgs* e);
#endif // __WXCSemanticZoomViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextChangedEventHandler
#ifndef __WXCTextChangedEventHandler__DEFINED
#define __WXCTextChangedEventHandler__DEFINED
typedef void (^WXCTextChangedEventHandler)(RTObject* sender, WXCTextChangedEventArgs* e);
#endif // __WXCTextChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextControlPasteEventHandler
#ifndef __WXCTextControlPasteEventHandler__DEFINED
#define __WXCTextControlPasteEventHandler__DEFINED
typedef void (^WXCTextControlPasteEventHandler)(RTObject* sender, WXCTextControlPasteEventArgs* e);
#endif // __WXCTextControlPasteEventHandler__DEFINED

// Windows.UI.Xaml.Controls.WebViewNavigationFailedEventHandler
#ifndef __WXCWebViewNavigationFailedEventHandler__DEFINED
#define __WXCWebViewNavigationFailedEventHandler__DEFINED
typedef void (^WXCWebViewNavigationFailedEventHandler)(RTObject* sender, WXCWebViewNavigationFailedEventArgs* e);
#endif // __WXCWebViewNavigationFailedEventHandler__DEFINED

// Windows.UI.Xaml.Data.PropertyChangedEventHandler
#ifndef __WUXDPropertyChangedEventHandler__DEFINED
#define __WUXDPropertyChangedEventHandler__DEFINED
typedef void (^WUXDPropertyChangedEventHandler)(RTObject* sender, WUXDPropertyChangedEventArgs* e);
#endif // __WUXDPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedEventHandler
#ifndef __WXDependencyPropertyChangedEventHandler__DEFINED
#define __WXDependencyPropertyChangedEventHandler__DEFINED
typedef void (^WXDependencyPropertyChangedEventHandler)(RTObject* sender, WXDependencyPropertyChangedEventArgs* e);
#endif // __WXDependencyPropertyChangedEventHandler__DEFINED

// Windows.UI.Xaml.DragEventHandler
#ifndef __WXDragEventHandler__DEFINED
#define __WXDragEventHandler__DEFINED
typedef void (^WXDragEventHandler)(RTObject* sender, WXDragEventArgs* e);
#endif // __WXDragEventHandler__DEFINED

// Windows.UI.Xaml.ExceptionRoutedEventHandler
#ifndef __WXExceptionRoutedEventHandler__DEFINED
#define __WXExceptionRoutedEventHandler__DEFINED
typedef void (^WXExceptionRoutedEventHandler)(RTObject* sender, WXExceptionRoutedEventArgs* e);
#endif // __WXExceptionRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Input.DoubleTappedEventHandler
#ifndef __WUXIDoubleTappedEventHandler__DEFINED
#define __WUXIDoubleTappedEventHandler__DEFINED
typedef void (^WUXIDoubleTappedEventHandler)(RTObject* sender, WUXIDoubleTappedRoutedEventArgs* e);
#endif // __WUXIDoubleTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.HoldingEventHandler
#ifndef __WUXIHoldingEventHandler__DEFINED
#define __WUXIHoldingEventHandler__DEFINED
typedef void (^WUXIHoldingEventHandler)(RTObject* sender, WUXIHoldingRoutedEventArgs* e);
#endif // __WUXIHoldingEventHandler__DEFINED

// Windows.UI.Xaml.Input.KeyEventHandler
#ifndef __WUXIKeyEventHandler__DEFINED
#define __WUXIKeyEventHandler__DEFINED
typedef void (^WUXIKeyEventHandler)(RTObject* sender, WUXIKeyRoutedEventArgs* e);
#endif // __WUXIKeyEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationCompletedEventHandler
#ifndef __WUXIManipulationCompletedEventHandler__DEFINED
#define __WUXIManipulationCompletedEventHandler__DEFINED
typedef void (^WUXIManipulationCompletedEventHandler)(RTObject* sender, WUXIManipulationCompletedRoutedEventArgs* e);
#endif // __WUXIManipulationCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationDeltaEventHandler
#ifndef __WUXIManipulationDeltaEventHandler__DEFINED
#define __WUXIManipulationDeltaEventHandler__DEFINED
typedef void (^WUXIManipulationDeltaEventHandler)(RTObject* sender, WUXIManipulationDeltaRoutedEventArgs* e);
#endif // __WUXIManipulationDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationInertiaStartingEventHandler
#ifndef __WUXIManipulationInertiaStartingEventHandler__DEFINED
#define __WUXIManipulationInertiaStartingEventHandler__DEFINED
typedef void (^WUXIManipulationInertiaStartingEventHandler)(RTObject* sender, WUXIManipulationInertiaStartingRoutedEventArgs* e);
#endif // __WUXIManipulationInertiaStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartedEventHandler
#ifndef __WUXIManipulationStartedEventHandler__DEFINED
#define __WUXIManipulationStartedEventHandler__DEFINED
typedef void (^WUXIManipulationStartedEventHandler)(RTObject* sender, WUXIManipulationStartedRoutedEventArgs* e);
#endif // __WUXIManipulationStartedEventHandler__DEFINED

// Windows.UI.Xaml.Input.ManipulationStartingEventHandler
#ifndef __WUXIManipulationStartingEventHandler__DEFINED
#define __WUXIManipulationStartingEventHandler__DEFINED
typedef void (^WUXIManipulationStartingEventHandler)(RTObject* sender, WUXIManipulationStartingRoutedEventArgs* e);
#endif // __WUXIManipulationStartingEventHandler__DEFINED

// Windows.UI.Xaml.Input.PointerEventHandler
#ifndef __WUXIPointerEventHandler__DEFINED
#define __WUXIPointerEventHandler__DEFINED
typedef void (^WUXIPointerEventHandler)(RTObject* sender, WUXIPointerRoutedEventArgs* e);
#endif // __WUXIPointerEventHandler__DEFINED

// Windows.UI.Xaml.Input.RightTappedEventHandler
#ifndef __WUXIRightTappedEventHandler__DEFINED
#define __WUXIRightTappedEventHandler__DEFINED
typedef void (^WUXIRightTappedEventHandler)(RTObject* sender, WUXIRightTappedRoutedEventArgs* e);
#endif // __WUXIRightTappedEventHandler__DEFINED

// Windows.UI.Xaml.Input.TappedEventHandler
#ifndef __WUXITappedEventHandler__DEFINED
#define __WUXITappedEventHandler__DEFINED
typedef void (^WUXITappedEventHandler)(RTObject* sender, WUXITappedRoutedEventArgs* e);
#endif // __WUXITappedEventHandler__DEFINED

// Windows.UI.Xaml.Media.RateChangedRoutedEventHandler
#ifndef __WUXMRateChangedRoutedEventHandler__DEFINED
#define __WUXMRateChangedRoutedEventHandler__DEFINED
typedef void (^WUXMRateChangedRoutedEventHandler)(RTObject* sender, WUXMRateChangedRoutedEventArgs* e);
#endif // __WUXMRateChangedRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Media.TimelineMarkerRoutedEventHandler
#ifndef __WUXMTimelineMarkerRoutedEventHandler__DEFINED
#define __WUXMTimelineMarkerRoutedEventHandler__DEFINED
typedef void (^WUXMTimelineMarkerRoutedEventHandler)(RTObject* sender, WUXMTimelineMarkerRoutedEventArgs* e);
#endif // __WUXMTimelineMarkerRoutedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.LoadCompletedEventHandler
#ifndef __WUXNLoadCompletedEventHandler__DEFINED
#define __WUXNLoadCompletedEventHandler__DEFINED
typedef void (^WUXNLoadCompletedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNLoadCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigatedEventHandler
#ifndef __WUXNNavigatedEventHandler__DEFINED
#define __WUXNNavigatedEventHandler__DEFINED
typedef void (^WUXNNavigatedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNNavigatedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigatingCancelEventHandler
#ifndef __WUXNNavigatingCancelEventHandler__DEFINED
#define __WUXNNavigatingCancelEventHandler__DEFINED
typedef void (^WUXNNavigatingCancelEventHandler)(RTObject* sender, WUXNNavigatingCancelEventArgs* e);
#endif // __WUXNNavigatingCancelEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigationFailedEventHandler
#ifndef __WUXNNavigationFailedEventHandler__DEFINED
#define __WUXNNavigationFailedEventHandler__DEFINED
typedef void (^WUXNNavigationFailedEventHandler)(RTObject* sender, WUXNNavigationFailedEventArgs* e);
#endif // __WUXNNavigationFailedEventHandler__DEFINED

// Windows.UI.Xaml.Navigation.NavigationStoppedEventHandler
#ifndef __WUXNNavigationStoppedEventHandler__DEFINED
#define __WUXNNavigationStoppedEventHandler__DEFINED
typedef void (^WUXNNavigationStoppedEventHandler)(RTObject* sender, WUXNNavigationEventArgs* e);
#endif // __WUXNNavigationStoppedEventHandler__DEFINED

// Windows.UI.Xaml.RoutedEventHandler
#ifndef __WXRoutedEventHandler__DEFINED
#define __WXRoutedEventHandler__DEFINED
typedef void (^WXRoutedEventHandler)(RTObject* sender, WXRoutedEventArgs* e);
#endif // __WXRoutedEventHandler__DEFINED

// Windows.UI.Xaml.SizeChangedEventHandler
#ifndef __WXSizeChangedEventHandler__DEFINED
#define __WXSizeChangedEventHandler__DEFINED
typedef void (^WXSizeChangedEventHandler)(RTObject* sender, WXSizeChangedEventArgs* e);
#endif // __WXSizeChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.BackClickEventHandler
#ifndef __WXCBackClickEventHandler__DEFINED
#define __WXCBackClickEventHandler__DEFINED
typedef void (^WXCBackClickEventHandler)(RTObject* sender, WXCBackClickEventArgs* e);
#endif // __WXCBackClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.CleanUpVirtualizedItemEventHandler
#ifndef __WXCCleanUpVirtualizedItemEventHandler__DEFINED
#define __WXCCleanUpVirtualizedItemEventHandler__DEFINED
typedef void (^WXCCleanUpVirtualizedItemEventHandler)(RTObject* sender, WXCCleanUpVirtualizedItemEventArgs* e);
#endif // __WXCCleanUpVirtualizedItemEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ContextMenuOpeningEventHandler
#ifndef __WXCContextMenuOpeningEventHandler__DEFINED
#define __WXCContextMenuOpeningEventHandler__DEFINED
typedef void (^WXCContextMenuOpeningEventHandler)(RTObject* sender, WXCContextMenuEventArgs* e);
#endif // __WXCContextMenuOpeningEventHandler__DEFINED

// Windows.UI.Xaml.Controls.DragItemsStartingEventHandler
#ifndef __WXCDragItemsStartingEventHandler__DEFINED
#define __WXCDragItemsStartingEventHandler__DEFINED
typedef void (^WXCDragItemsStartingEventHandler)(RTObject* sender, WXCDragItemsStartingEventArgs* e);
#endif // __WXCDragItemsStartingEventHandler__DEFINED

// Windows.UI.Xaml.Controls.ItemClickEventHandler
#ifndef __WXCItemClickEventHandler__DEFINED
#define __WXCItemClickEventHandler__DEFINED
typedef void (^WXCItemClickEventHandler)(RTObject* sender, WXCItemClickEventArgs* e);
#endif // __WXCItemClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.NotifyEventHandler
#ifndef __WXCNotifyEventHandler__DEFINED
#define __WXCNotifyEventHandler__DEFINED
typedef void (^WXCNotifyEventHandler)(RTObject* sender, WXCNotifyEventArgs* e);
#endif // __WXCNotifyEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SelectionChangedEventHandler
#ifndef __WXCSelectionChangedEventHandler__DEFINED
#define __WXCSelectionChangedEventHandler__DEFINED
typedef void (^WXCSelectionChangedEventHandler)(RTObject* sender, WXCSelectionChangedEventArgs* e);
#endif // __WXCSelectionChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SemanticZoomViewChangedEventHandler
#ifndef __WXCSemanticZoomViewChangedEventHandler__DEFINED
#define __WXCSemanticZoomViewChangedEventHandler__DEFINED
typedef void (^WXCSemanticZoomViewChangedEventHandler)(RTObject* sender, WXCSemanticZoomViewChangedEventArgs* e);
#endif // __WXCSemanticZoomViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextChangedEventHandler
#ifndef __WXCTextChangedEventHandler__DEFINED
#define __WXCTextChangedEventHandler__DEFINED
typedef void (^WXCTextChangedEventHandler)(RTObject* sender, WXCTextChangedEventArgs* e);
#endif // __WXCTextChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.TextControlPasteEventHandler
#ifndef __WXCTextControlPasteEventHandler__DEFINED
#define __WXCTextControlPasteEventHandler__DEFINED
typedef void (^WXCTextControlPasteEventHandler)(RTObject* sender, WXCTextControlPasteEventArgs* e);
#endif // __WXCTextControlPasteEventHandler__DEFINED

// Windows.UI.Xaml.Controls.HubSectionHeaderClickEventHandler
#ifndef __WXCHubSectionHeaderClickEventHandler__DEFINED
#define __WXCHubSectionHeaderClickEventHandler__DEFINED
typedef void (^WXCHubSectionHeaderClickEventHandler)(RTObject* sender, WXCHubSectionHeaderClickEventArgs* e);
#endif // __WXCHubSectionHeaderClickEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SectionsInViewChangedEventHandler
#ifndef __WXCSectionsInViewChangedEventHandler__DEFINED
#define __WXCSectionsInViewChangedEventHandler__DEFINED
typedef void (^WXCSectionsInViewChangedEventHandler)(RTObject* sender, WXCSectionsInViewChangedEventArgs* e);
#endif // __WXCSectionsInViewChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.WebViewNavigationFailedEventHandler
#ifndef __WXCWebViewNavigationFailedEventHandler__DEFINED
#define __WXCWebViewNavigationFailedEventHandler__DEFINED
typedef void (^WXCWebViewNavigationFailedEventHandler)(RTObject* sender, WXCWebViewNavigationFailedEventArgs* e);
#endif // __WXCWebViewNavigationFailedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.IItemContainerMapping
#ifndef __WXCIItemContainerMapping_DEFINED__
#define __WXCIItemContainerMapping_DEFINED__

@protocol WXCIItemContainerMapping
- (RTObject*)itemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromItem:(RTObject*)item;
- (int)indexFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromIndex:(int)index;
@end

#endif // __WXCIItemContainerMapping_DEFINED__

// Windows.UI.Xaml.Controls.INavigate
#ifndef __WXCINavigate_DEFINED__
#define __WXCINavigate_DEFINED__

@protocol WXCINavigate
- (BOOL)navigate:(WUXITypeName*)sourcePageType;
@end

#endif // __WXCINavigate_DEFINED__

// Windows.UI.Xaml.Controls.ISemanticZoomInformation
#ifndef __WXCISemanticZoomInformation_DEFINED__
#define __WXCISemanticZoomInformation_DEFINED__

@protocol WXCISemanticZoomInformation
@property BOOL isActiveView;
@property BOOL isZoomedInView;
@property (copy) WXCSemanticZoom* semanticZoomOwner;
- (void)initializeViewChange;
- (void)completeViewChange;
- (void)makeVisible:(WXCSemanticZoomLocation*)item;
- (void)startViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)startViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
@end

#endif // __WXCISemanticZoomInformation_DEFINED__

// Windows.UI.Xaml.Controls.ICommandBarElement
#ifndef __WXCICommandBarElement_DEFINED__
#define __WXCICommandBarElement_DEFINED__

@protocol WXCICommandBarElement
@property BOOL isCompact;
@end

#endif // __WXCICommandBarElement_DEFINED__

// Windows.UI.Xaml.Controls.BackClickEventArgs
#ifndef __WXCBackClickEventArgs_DEFINED__
#define __WXCBackClickEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCBackClickEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL handled;
@end

#endif // __WXCBackClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.DragItemsStartingEventArgs
#ifndef __WXCDragItemsStartingEventArgs_DEFINED__
#define __WXCDragItemsStartingEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCDragItemsStartingEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL cancel;
@property (readonly) WADDataPackage* data;
// Failed to generate property Items (Cannot marshal contained object of unknown type System.Object)
// Failed to generate member get_Items (Cannot marshal contained object of unknown type System.Object)
@end

#endif // __WXCDragItemsStartingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.NotifyEventArgs
#ifndef __WXCNotifyEventArgs_DEFINED__
#define __WXCNotifyEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCNotifyEventArgs : RTObject
@property (readonly) NSString* value;
@property (readonly) WFUri* callingUri;
@end

#endif // __WXCNotifyEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SemanticZoomViewChangedEventArgs
#ifndef __WXCSemanticZoomViewChangedEventArgs_DEFINED__
#define __WXCSemanticZoomViewChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCSemanticZoomViewChangedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) WXCSemanticZoomLocation* sourceItem;
@property BOOL isSourceZoomedInView;
@property (copy) WXCSemanticZoomLocation* destinationItem;
@end

#endif // __WXCSemanticZoomViewChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextControlPasteEventArgs
#ifndef __WXCTextControlPasteEventArgs_DEFINED__
#define __WXCTextControlPasteEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCTextControlPasteEventArgs : RTObject
@property BOOL handled;
@end

#endif // __WXCTextControlPasteEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ColumnDefinitionCollection
#ifndef __WXCColumnDefinitionCollection_DEFINED__
#define __WXCColumnDefinitionCollection_DEFINED__

WINRT_EXPORT
@interface WXCColumnDefinitionCollection : RTObject
@property (readonly) unsigned size;
@end

#endif // __WXCColumnDefinitionCollection_DEFINED__

// Windows.UI.Xaml.Controls.ContainerContentChangingEventArgs
#ifndef __WXCContainerContentChangingEventArgs_DEFINED__
#define __WXCContainerContentChangingEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCContainerContentChangingEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property BOOL handled;
@property (readonly) BOOL inRecycleQueue;
@property (readonly) RTObject* item;
@property (readonly) WUXCPSelectorItem* itemContainer;
@property (readonly) int itemIndex;
@property (readonly) unsigned phase;
- (void)registerUpdateCallback:(void (^)(WXCListViewBase*, WXCContainerContentChangingEventArgs*))callback;
- (void)registerUpdateCallbackWithPhase:(unsigned)callbackPhase
                               callback:(void (^)(WXCListViewBase*, WXCContainerContentChangingEventArgs*))callback;
@end

#endif // __WXCContainerContentChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.DataTemplateSelector
#ifndef __WXCDataTemplateSelector_DEFINED__
#define __WXCDataTemplateSelector_DEFINED__

WINRT_EXPORT
@interface WXCDataTemplateSelector : RTObject
+ (instancetype)create ACTIVATOR;
- (WXDataTemplate*)selectTemplate:(RTObject*)item container:(WXDependencyObject*)container;
- (WXDataTemplate*)selectTemplateForItem:(RTObject*)item;
- (WXDataTemplate*)selectTemplateCore:(RTObject*)item container:(WXDependencyObject*)container;
- (WXDataTemplate*)selectTemplateForItemCore:(RTObject*)item;
@end

#endif // __WXCDataTemplateSelector_DEFINED__

// Windows.UI.Xaml.Controls.DatePickerValueChangedEventArgs
#ifndef __WXCDatePickerValueChangedEventArgs_DEFINED__
#define __WXCDatePickerValueChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCDatePickerValueChangedEventArgs : RTObject
@property (readonly) WFDateTime* newDate;
@property (readonly) WFDateTime* oldDate;
@end

#endif // __WXCDatePickerValueChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.RowDefinitionCollection
#ifndef __WXCRowDefinitionCollection_DEFINED__
#define __WXCRowDefinitionCollection_DEFINED__

WINRT_EXPORT
@interface WXCRowDefinitionCollection : RTObject
@property (readonly) unsigned size;
@end

#endif // __WXCRowDefinitionCollection_DEFINED__

// Windows.UI.Xaml.Controls.StyleSelector
#ifndef __WXCStyleSelector_DEFINED__
#define __WXCStyleSelector_DEFINED__

WINRT_EXPORT
@interface WXCStyleSelector : RTObject
+ (instancetype)create ACTIVATOR;
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

#endif // __WUXDINotifyPropertyChanged_DEFINED__

// Windows.UI.Xaml.Controls.GroupStyle
#ifndef __WXCGroupStyle_DEFINED__
#define __WXCGroupStyle_DEFINED__

WINRT_EXPORT
@interface WXCGroupStyle : RTObject <WUXDINotifyPropertyChanged>
+ (instancetype)create ACTIVATOR;
@property (copy) WXCItemsPanelTemplate* panel;
@property BOOL hidesIfEmpty;
@property (copy) WXCDataTemplateSelector* headerTemplateSelector;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) WXCStyleSelector* containerStyleSelector;
@property (copy) WXStyle* containerStyle;
@property (copy) WXStyle* headerContainerStyle;
- (EventRegistrationToken)addPropertyChangedEvent:(WUXDPropertyChangedEventHandler)del;
- (void)removePropertyChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCGroupStyle_DEFINED__

// Windows.UI.Xaml.Controls.GroupStyleSelector
#ifndef __WXCGroupStyleSelector_DEFINED__
#define __WXCGroupStyleSelector_DEFINED__

WINRT_EXPORT
@interface WXCGroupStyleSelector : RTObject
+ (instancetype)create ACTIVATOR;
- (WXCGroupStyle*)selectGroupStyle:(RTObject*)group level:(unsigned)level;
- (WXCGroupStyle*)selectGroupStyleCore:(RTObject*)group level:(unsigned)level;
@end

#endif // __WXCGroupStyleSelector_DEFINED__

// Windows.UI.Xaml.Controls.SemanticZoomLocation
#ifndef __WXCSemanticZoomLocation_DEFINED__
#define __WXCSemanticZoomLocation_DEFINED__

WINRT_EXPORT
@interface WXCSemanticZoomLocation : RTObject
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* item;
@property (copy) WFRect* bounds;
@end

#endif // __WXCSemanticZoomLocation_DEFINED__

// Windows.UI.Xaml.Controls.ItemCollection
#ifndef __WXCItemCollection_DEFINED__
#define __WXCItemCollection_DEFINED__

WINRT_EXPORT
@interface WXCItemCollection : RTObject
@property (readonly) unsigned size;
// Could not generate add_VectorChanged (Can't marshal Windows.Foundation.Collections.VectorChangedEventHandler`1<System.Object>)
- (void)removeVectorChangedEvent:(EventRegistrationToken)tok;
// Could not find base class Windows.Foundation.Collections.IObservableVector`1<System.Object> type information
@end

#endif // __WXCItemCollection_DEFINED__

// Windows.UI.Xaml.Controls.ItemContainerGenerator
#ifndef __WXCItemContainerGenerator_DEFINED__
#define __WXCItemContainerGenerator_DEFINED__

WINRT_EXPORT
@interface WXCItemContainerGenerator : RTObject
- (EventRegistrationToken)addItemsChangedEvent:(WUXCPItemsChangedEventHandler)del;
- (void)removeItemsChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)itemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromItem:(RTObject*)item;
- (int)indexFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromIndex:(int)index;
- (WXCItemContainerGenerator*)getItemContainerGeneratorForPanel:(WXCPanel*)panel;
- (void)startAt:(WUXCPGeneratorPosition*)position
                   direction:(WUXCPGeneratorDirection)direction
    allowStartAtRealizedItem:(BOOL)allowStartAtRealizedItem;
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

// Windows.UI.Xaml.Controls.UIElementCollection
#ifndef __WXCUIElementCollection_DEFINED__
#define __WXCUIElementCollection_DEFINED__

WINRT_EXPORT
@interface WXCUIElementCollection : RTObject
@property (readonly) unsigned size;
- (void)move:(unsigned)oldIndex newIndex:(unsigned)newIndex;
@end

#endif // __WXCUIElementCollection_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewerViewChangedEventArgs
#ifndef __WXCScrollViewerViewChangedEventArgs_DEFINED__
#define __WXCScrollViewerViewChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCScrollViewerViewChangedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) BOOL isIntermediate;
@end

#endif // __WXCScrollViewerViewChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewerViewChangingEventArgs
#ifndef __WXCScrollViewerViewChangingEventArgs_DEFINED__
#define __WXCScrollViewerViewChangingEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCScrollViewerViewChangingEventArgs : RTObject
@property (readonly) WXCScrollViewerView* finalView;
@property (readonly) BOOL isInertial;
@property (readonly) WXCScrollViewerView* nextView;
@end

#endif // __WXCScrollViewerViewChangingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewerView
#ifndef __WXCScrollViewerView_DEFINED__
#define __WXCScrollViewerView_DEFINED__

WINRT_EXPORT
@interface WXCScrollViewerView : RTObject
@property (readonly) double horizontalOffset;
@property (readonly) double verticalOffset;
@property (readonly) float zoomFactor;
@end

#endif // __WXCScrollViewerView_DEFINED__

// Windows.UI.Xaml.Controls.ToolTipService
#ifndef __WXCToolTipService_DEFINED__
#define __WXCToolTipService_DEFINED__

WINRT_EXPORT
@interface WXCToolTipService : RTObject
+ (WUXCPPlacementMode)getPlacement:(WXDependencyObject*)element;
+ (void)setPlacement:(WXDependencyObject*)element value:(WUXCPPlacementMode)value;
+ (WXUIElement*)getPlacementTarget:(WXDependencyObject*)element;
+ (void)setPlacementTarget:(WXDependencyObject*)element value:(WXUIElement*)value;
+ (RTObject*)getToolTip:(WXDependencyObject*)element;
+ (void)setToolTip:(WXDependencyObject*)element value:(RTObject*)value;
+ (WXDependencyProperty*)placementProperty;
+ (WXDependencyProperty*)placementTargetProperty;
+ (WXDependencyProperty*)toolTipProperty;
@end

#endif // __WXCToolTipService_DEFINED__

// Windows.UI.Xaml.Controls.HubSectionHeaderClickEventArgs
#ifndef __WXCHubSectionHeaderClickEventArgs_DEFINED__
#define __WXCHubSectionHeaderClickEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCHubSectionHeaderClickEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WXCHubSection* section;
@end

#endif // __WXCHubSectionHeaderClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SectionsInViewChangedEventArgs
#ifndef __WXCSectionsInViewChangedEventArgs_DEFINED__
#define __WXCSectionsInViewChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCSectionsInViewChangedEventArgs : RTObject
@property (readonly) id<NSFastEnumeration> /*WXCHubSection*/ addedSections;
@property (readonly) id<NSFastEnumeration> /*WXCHubSection*/ removedSections;
@end

#endif // __WXCSectionsInViewChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewNavigationFailedEventArgs
#ifndef __WXCWebViewNavigationFailedEventArgs_DEFINED__
#define __WXCWebViewNavigationFailedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCWebViewNavigationFailedEventArgs : RTObject
@property (readonly) WFUri* uri;
@property (readonly) WWWebErrorStatus webErrorStatus;
@end

#endif // __WXCWebViewNavigationFailedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.HubSectionCollection
#ifndef __WXCHubSectionCollection_DEFINED__
#define __WXCHubSectionCollection_DEFINED__

WINRT_EXPORT
@interface WXCHubSectionCollection : RTObject
@property (readonly) unsigned size;
@end

#endif // __WXCHubSectionCollection_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxQueryChangedEventArgs
#ifndef __WXCSearchBoxQueryChangedEventArgs_DEFINED__
#define __WXCSearchBoxQueryChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCSearchBoxQueryChangedEventArgs : RTObject
@property (readonly) NSString* language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* queryText;
@end

#endif // __WXCSearchBoxQueryChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxSuggestionsRequestedEventArgs
#ifndef __WXCSearchBoxSuggestionsRequestedEventArgs_DEFINED__
#define __WXCSearchBoxSuggestionsRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCSearchBoxSuggestionsRequestedEventArgs : RTObject
@property (readonly) NSString* language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* queryText;
@property (readonly) WASSearchSuggestionsRequest* request;
@end

#endif // __WXCSearchBoxSuggestionsRequestedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxQuerySubmittedEventArgs
#ifndef __WXCSearchBoxQuerySubmittedEventArgs_DEFINED__
#define __WXCSearchBoxQuerySubmittedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCSearchBoxQuerySubmittedEventArgs : RTObject
@property (readonly) WSVirtualKeyModifiers keyModifiers;
@property (readonly) NSString* language;
@property (readonly) WASSearchQueryLinguisticDetails* linguisticDetails;
@property (readonly) NSString* queryText;
@end

#endif // __WXCSearchBoxQuerySubmittedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SearchBoxResultSuggestionChosenEventArgs
#ifndef __WXCSearchBoxResultSuggestionChosenEventArgs_DEFINED__
#define __WXCSearchBoxResultSuggestionChosenEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCSearchBoxResultSuggestionChosenEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WSVirtualKeyModifiers keyModifiers;
@property (readonly) NSString* tag;
@end

#endif // __WXCSearchBoxResultSuggestionChosenEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TimePickerValueChangedEventArgs
#ifndef __WXCTimePickerValueChangedEventArgs_DEFINED__
#define __WXCTimePickerValueChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCTimePickerValueChangedEventArgs : RTObject
@property (readonly) WFTimeSpan* newTime;
@property (readonly) WFTimeSpan* oldTime;
@end

#endif // __WXCTimePickerValueChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewNavigationStartingEventArgs
#ifndef __WXCWebViewNavigationStartingEventArgs_DEFINED__
#define __WXCWebViewNavigationStartingEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCWebViewNavigationStartingEventArgs : RTObject
@property BOOL cancel;
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewNavigationStartingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewContentLoadingEventArgs
#ifndef __WXCWebViewContentLoadingEventArgs_DEFINED__
#define __WXCWebViewContentLoadingEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCWebViewContentLoadingEventArgs : RTObject
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewContentLoadingEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewDOMContentLoadedEventArgs
#ifndef __WXCWebViewDOMContentLoadedEventArgs_DEFINED__
#define __WXCWebViewDOMContentLoadedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCWebViewDOMContentLoadedEventArgs : RTObject
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewDOMContentLoadedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewNavigationCompletedEventArgs
#ifndef __WXCWebViewNavigationCompletedEventArgs_DEFINED__
#define __WXCWebViewNavigationCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCWebViewNavigationCompletedEventArgs : RTObject
@property (readonly) BOOL isSuccess;
@property (readonly) WFUri* uri;
@property (readonly) WWWebErrorStatus webErrorStatus;
@end

#endif // __WXCWebViewNavigationCompletedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewLongRunningScriptDetectedEventArgs
#ifndef __WXCWebViewLongRunningScriptDetectedEventArgs_DEFINED__
#define __WXCWebViewLongRunningScriptDetectedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCWebViewLongRunningScriptDetectedEventArgs : RTObject
@property BOOL stopPageScriptExecution;
@property (readonly) WFTimeSpan* executionTime;
@end

#endif // __WXCWebViewLongRunningScriptDetectedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.WebViewUnviewableContentIdentifiedEventArgs
#ifndef __WXCWebViewUnviewableContentIdentifiedEventArgs_DEFINED__
#define __WXCWebViewUnviewableContentIdentifiedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCWebViewUnviewableContentIdentifiedEventArgs : RTObject
@property (readonly) WFUri* referrer;
@property (readonly) WFUri* uri;
@end

#endif // __WXCWebViewUnviewableContentIdentifiedEventArgs_DEFINED__

// Windows.UI.Xaml.DependencyObject
#ifndef __WXDependencyObject_DEFINED__
#define __WXDependencyObject_DEFINED__

WINRT_EXPORT
@interface WXDependencyObject : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) WUCCoreDispatcher* dispatcher;
- (RTObject*)getValue:(WXDependencyProperty*)dp;
- (void)setValue:(WXDependencyProperty*)dp value:(RTObject*)value;
- (void)clearValue:(WXDependencyProperty*)dp;
- (RTObject*)readLocalValue:(WXDependencyProperty*)dp;
- (RTObject*)getAnimationBaseValue:(WXDependencyProperty*)dp;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Controls.ColumnDefinition
#ifndef __WXCColumnDefinition_DEFINED__
#define __WXCColumnDefinition_DEFINED__

WINRT_EXPORT
@interface WXCColumnDefinition : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WXGridLength* width;
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

WINRT_EXPORT
@interface WXCRowDefinition : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property double minHeight;
@property double maxHeight;
@property (copy) WXGridLength* height;
@property (readonly) double actualHeight;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)minHeightProperty;
@end

#endif // __WXCRowDefinition_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.FlyoutBase
#ifndef __WUXCPFlyoutBase_DEFINED__
#define __WUXCPFlyoutBase_DEFINED__

WINRT_EXPORT
@interface WUXCPFlyoutBase : WXDependencyObject
+ (WUXCPFlyoutBase*)getAttachedFlyout:(WXFrameworkElement*)element;
+ (void)setAttachedFlyout:(WXFrameworkElement*)element value:(WUXCPFlyoutBase*)value;
+ (void)showAttachedFlyout:(WXFrameworkElement*)flyoutOwner;
+ (instancetype)create ACTIVATOR;
@property WUXCPFlyoutPlacementMode placement;
+ (WXDependencyProperty*)attachedFlyoutProperty;
+ (WXDependencyProperty*)placementProperty;
- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpeningEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeOpeningEvent:(EventRegistrationToken)tok;
- (void)showAt:(WXFrameworkElement*)placementTarget;
- (void)hide;
- (WXCControl*)createPresenter;
@end

#endif // __WUXCPFlyoutBase_DEFINED__

// Windows.UI.Xaml.Controls.Flyout
#ifndef __WXCFlyout_DEFINED__
#define __WXCFlyout_DEFINED__

WINRT_EXPORT
@interface WXCFlyout : WUXCPFlyoutBase
+ (instancetype)create ACTIVATOR;
@property (copy) WXStyle* flyoutPresenterStyle;
@property (copy) WXUIElement* content;
+ (WXDependencyProperty*)contentProperty;
+ (WXDependencyProperty*)flyoutPresenterStyleProperty;
@end

#endif // __WXCFlyout_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyout
#ifndef __WXCMenuFlyout_DEFINED__
#define __WXCMenuFlyout_DEFINED__

WINRT_EXPORT
@interface WXCMenuFlyout : WUXCPFlyoutBase
+ (instancetype)create ACTIVATOR;
@property (copy) WXStyle* menuFlyoutPresenterStyle;
@property (readonly) id<NSFastEnumeration> /*WXCMenuFlyoutItemBase*/ items;
+ (WXDependencyProperty*)menuFlyoutPresenterStyleProperty;
@end

#endif // __WXCMenuFlyout_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.CleanUpVirtualizedItemEventArgs
#ifndef __WXCCleanUpVirtualizedItemEventArgs_DEFINED__
#define __WXCCleanUpVirtualizedItemEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCCleanUpVirtualizedItemEventArgs : WXRoutedEventArgs
@property BOOL cancel;
@property (readonly) WXUIElement* uIElement;
@property (readonly) RTObject* value;
@end

#endif // __WXCCleanUpVirtualizedItemEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ContextMenuEventArgs
#ifndef __WXCContextMenuEventArgs_DEFINED__
#define __WXCContextMenuEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCContextMenuEventArgs : WXRoutedEventArgs
@property BOOL handled;
@property (readonly) double cursorLeft;
@property (readonly) double cursorTop;
@end

#endif // __WXCContextMenuEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.ItemClickEventArgs
#ifndef __WXCItemClickEventArgs_DEFINED__
#define __WXCItemClickEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCItemClickEventArgs : WXRoutedEventArgs
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject* clickedItem;
@end

#endif // __WXCItemClickEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.SelectionChangedEventArgs
#ifndef __WXCSelectionChangedEventArgs_DEFINED__
#define __WXCSelectionChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCSelectionChangedEventArgs : WXRoutedEventArgs
// Failed to generate property AddedItems (Cannot marshal contained object of unknown type System.Object)
// Failed to generate property RemovedItems (Cannot marshal contained object of unknown type System.Object)
// Failed to generate member get_AddedItems (Cannot marshal contained object of unknown type System.Object)
// Failed to generate member get_RemovedItems (Cannot marshal contained object of unknown type System.Object)
@end

#endif // __WXCSelectionChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.TextChangedEventArgs
#ifndef __WXCTextChangedEventArgs_DEFINED__
#define __WXCTextChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXCTextChangedEventArgs : WXRoutedEventArgs
@end

#endif // __WXCTextChangedEventArgs_DEFINED__

// Windows.UI.Xaml.FrameworkTemplate
#ifndef __WXFrameworkTemplate_DEFINED__
#define __WXFrameworkTemplate_DEFINED__

WINRT_EXPORT
@interface WXFrameworkTemplate : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXFrameworkTemplate_DEFINED__

// Windows.UI.Xaml.Controls.ItemsPanelTemplate
#ifndef __WXCItemsPanelTemplate_DEFINED__
#define __WXCItemsPanelTemplate_DEFINED__

WINRT_EXPORT
@interface WXCItemsPanelTemplate : WXFrameworkTemplate
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCItemsPanelTemplate_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

WINRT_EXPORT
@interface WXUIElement : WXDependencyObject
@property BOOL isTapEnabled;
@property BOOL isRightTapEnabled;
@property BOOL isHoldingEnabled;
@property BOOL isHitTestVisible;
@property BOOL isDoubleTapEnabled;
@property WUXIManipulationModes manipulationMode;
@property (copy) WUXMRectangleGeometry* clip;
@property (copy) WUXMCacheMode* cacheMode;
@property BOOL allowDrop;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (copy) WUXMATransitionCollection* transitions;
@property (copy) WFPoint* renderTransformOrigin;
@property (copy) WUXMTransform* renderTransform;
@property (copy) WUXMProjection* projection;
@property double opacity;
@property (readonly) WFSize* desiredSize;
@property (readonly) id<NSFastEnumeration> /*WUXIPointer*/ pointerCaptures;
@property (readonly) WFSize* renderSize;
@property WUXMElementCompositeMode compositeMode;
+ (WXDependencyProperty*)compositeModeProperty;
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
+ (WXDependencyProperty*)opacityProperty;
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
- (BOOL)cancelDirectManipulations;
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
// Failed to generate member FindSubElementsForTouchTargeting (Cannot marshal contained object of unknown type
// Windows.Foundation.Collections.IIterable`1<Windows.Foundation.Point>)
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

WINRT_EXPORT
@interface WXFrameworkElement : WXUIElement
+ (instancetype)create ACTIVATOR;
@property WXElementTheme requestedTheme;
@property (copy) NSString* name;
@property (copy) NSString* language;
@property WXHorizontalAlignment horizontalAlignment;
@property double height;
@property WXFlowDirection flowDirection;
@property (copy) RTObject* dataContext;
@property double maxWidth;
@property double maxHeight;
@property (copy) WXStyle* style;
@property double width;
@property WXVerticalAlignment verticalAlignment;
@property (copy) RTObject* tag;
@property (copy) WXResourceDictionary* resources;
@property (copy) WXThickness* margin;
@property double minWidth;
@property double minHeight;
@property (readonly) double actualHeight;
@property (readonly) double actualWidth;
@property (readonly) WXDependencyObject* parent;
@property (readonly) WFUri* baseUri;
@property (readonly) WXTriggerCollection* triggers;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
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
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)requestedThemeProperty;
- (EventRegistrationToken)addLayoutUpdatedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeLayoutUpdatedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLoadedEvent:(WXRoutedEventHandler)del;
- (void)removeLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSizeChangedEvent:(WXSizeChangedEventHandler)del;
- (void)removeSizeChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnloadedEvent:(WXRoutedEventHandler)del;
- (void)removeUnloadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDataContextChangedEvent:(void (^)(WXFrameworkElement*, WXDataContextChangedEventArgs*))del;
- (void)removeDataContextChangedEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString*)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Controls.Border
#ifndef __WXCBorder_DEFINED__
#define __WXCBorder_DEFINED__

WINRT_EXPORT
@interface WXCBorder : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WXThickness* padding;
@property (copy) WXCornerRadius* cornerRadius;
@property (copy) WUXMATransitionCollection* childTransitions;
@property (copy) WXUIElement* child;
@property (copy) WXThickness* borderThickness;
@property (copy) WUXMBrush* borderBrush;
@property (copy) WUXMBrush* background;
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

WINRT_EXPORT
@interface WXCCaptureElement : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property WUXMStretch stretch;
@property (copy) WMCMediaCapture* source;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WXCCaptureElement_DEFINED__

// Windows.UI.Xaml.Controls.ContentPresenter
#ifndef __WXCContentPresenter_DEFINED__
#define __WXCContentPresenter_DEFINED__

WINRT_EXPORT
@interface WXCContentPresenter : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMBrush* foreground;
@property (copy) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property double fontSize;
@property (copy) WUXMFontFamily* fontFamily;
@property (copy) WUXMATransitionCollection* contentTransitions;
@property (copy) WXCDataTemplateSelector* contentTemplateSelector;
@property (copy) WXDataTemplate* contentTemplate;
@property (copy) RTObject* content;
@property int characterSpacing;
@property WXTextLineBounds textLineBounds;
@property WXOpticalMarginAlignment opticalMarginAlignment;
+ (WXDependencyProperty*)opticalMarginAlignmentProperty;
+ (WXDependencyProperty*)textLineBoundsProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)contentProperty;
+ (WXDependencyProperty*)contentTemplateProperty;
+ (WXDependencyProperty*)contentTemplateSelectorProperty;
+ (WXDependencyProperty*)contentTransitionsProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)foregroundProperty;
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector
              newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

#endif // __WXCContentPresenter_DEFINED__

// Windows.UI.Xaml.Controls.Image
#ifndef __WXCImage_DEFINED__
#define __WXCImage_DEFINED__

WINRT_EXPORT
@interface WXCImage : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property WUXMStretch stretch;
@property (copy) WUXMImageSource* source;
@property (copy) WXThickness* nineGrid;
@property (readonly) WMPPlayToSource* playToSource;
+ (WXDependencyProperty*)nineGridProperty;
+ (WXDependencyProperty*)playToSourceProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)stretchProperty;
- (EventRegistrationToken)addImageFailedEvent:(WXExceptionRoutedEventHandler)del;
- (void)removeImageFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addImageOpenedEvent:(WXRoutedEventHandler)del;
- (void)removeImageOpenedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCImage_DEFINED__

// Windows.UI.Xaml.Controls.Panel
#ifndef __WXCPanel_DEFINED__
#define __WXCPanel_DEFINED__

WINRT_EXPORT
@interface WXCPanel : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMATransitionCollection* childrenTransitions;
@property (copy) WUXMBrush* background;
@property (readonly) WXCUIElementCollection* children;
@property (readonly) BOOL isItemsHost;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)childrenTransitionsProperty;
+ (WXDependencyProperty*)isItemsHostProperty;
@end

#endif // __WXCPanel_DEFINED__

// Windows.UI.Xaml.Controls.Canvas
#ifndef __WXCCanvas_DEFINED__
#define __WXCCanvas_DEFINED__

WINRT_EXPORT
@interface WXCCanvas : WXCPanel
+ (double)getLeft:(WXUIElement*)element;
+ (void)setLeft:(WXUIElement*)element length:(double)length;
+ (double)getTop:(WXUIElement*)element;
+ (void)setTop:(WXUIElement*)element length:(double)length;
+ (int)getZIndex:(WXUIElement*)element;
+ (void)setZIndex:(WXUIElement*)element value:(int)value;
+ (instancetype)create ACTIVATOR;
+ (WXDependencyProperty*)leftProperty;
+ (WXDependencyProperty*)topProperty;
+ (WXDependencyProperty*)zIndexProperty;
@end

#endif // __WXCCanvas_DEFINED__

// Windows.UI.Xaml.Controls.Grid
#ifndef __WXCGrid_DEFINED__
#define __WXCGrid_DEFINED__

WINRT_EXPORT
@interface WXCGrid : WXCPanel
+ (int)getRow:(WXFrameworkElement*)element;
+ (void)setRow:(WXFrameworkElement*)element value:(int)value;
+ (int)getColumn:(WXFrameworkElement*)element;
+ (void)setColumn:(WXFrameworkElement*)element value:(int)value;
+ (int)getRowSpan:(WXFrameworkElement*)element;
+ (void)setRowSpan:(WXFrameworkElement*)element value:(int)value;
+ (int)getColumnSpan:(WXFrameworkElement*)element;
+ (void)setColumnSpan:(WXFrameworkElement*)element value:(int)value;
+ (instancetype)create ACTIVATOR;
@property (readonly) WXCColumnDefinitionCollection* columnDefinitions;
@property (readonly) WXCRowDefinitionCollection* rowDefinitions;
+ (WXDependencyProperty*)columnProperty;
+ (WXDependencyProperty*)columnSpanProperty;
+ (WXDependencyProperty*)rowProperty;
+ (WXDependencyProperty*)rowSpanProperty;
@end

#endif // __WXCGrid_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IScrollSnapPointsInfo
#ifndef __WUXCPIScrollSnapPointsInfo_DEFINED__
#define __WUXCPIScrollSnapPointsInfo_DEFINED__

@protocol WUXCPIScrollSnapPointsInfo
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*Single*/)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WUXCPIScrollSnapPointsInfo_DEFINED__

// Windows.UI.Xaml.Controls.ItemsPresenter
#ifndef __WXCItemsPresenter_DEFINED__
#define __WXCItemsPresenter_DEFINED__

WINRT_EXPORT
@interface WXCItemsPresenter : WXFrameworkElement <WUXCPIScrollSnapPointsInfo>
+ (instancetype)create ACTIVATOR;
@property (copy) WXThickness* padding;
@property (copy) WUXMATransitionCollection* headerTransitions;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
@property (copy) WUXMATransitionCollection* footerTransitions;
@property (copy) WXDataTemplate* footerTemplate;
@property (copy) RTObject* footer;
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
+ (WXDependencyProperty*)footerProperty;
+ (WXDependencyProperty*)footerTemplateProperty;
+ (WXDependencyProperty*)footerTransitionsProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)headerTransitionsProperty;
+ (WXDependencyProperty*)paddingProperty;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*Single*/)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WXCItemsPresenter_DEFINED__

// Windows.UI.Xaml.Controls.MediaElement
#ifndef __WXCMediaElement_DEFINED__
#define __WXCMediaElement_DEFINED__

WINRT_EXPORT
@interface WXCMediaElement : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* playToPreferredSourceUri;
@property BOOL isFullWindow;
@property BOOL areTransportControlsEnabled;
@property WUXMStretch stretch;
@property (copy) WFTimeSpan* position;
@property double playbackRate;
@property BOOL realTimePlayback;
@property BOOL autoPlay;
@property (copy) NSNumber* audioStreamIndex;
@property BOOL isMuted;
@property WUXMAudioDeviceType audioDeviceType;
@property WUXMAudioCategory audioCategory;
@property (copy) WMPMediaProtectionManager* protectionManager;
@property BOOL isLooping;
@property double balance;
@property (copy) WFUri* source;
@property double defaultPlaybackRate;
@property (copy) WUXMImageSource* posterSource;
@property double volume;
@property WUXMStereo3DVideoRenderMode stereo3DVideoRenderMode;
@property WUXMStereo3DVideoPackingMode stereo3DVideoPackingMode;
@property (readonly) WXDuration* naturalDuration;
@property (readonly) int naturalVideoHeight;
@property (readonly) int naturalVideoWidth;
@property (readonly) WMPPlayToSource* playToSource;
@property (readonly) WUXMStereo3DVideoPackingMode actualStereo3DVideoPackingMode;
@property (readonly) int aspectRatioHeight;
@property (readonly) int aspectRatioWidth;
@property (readonly) int audioStreamCount;
@property (readonly) double bufferingProgress;
@property (readonly) BOOL canPause;
@property (readonly) BOOL canSeek;
@property (readonly) WUXMMediaElementState currentState;
@property (readonly) double downloadProgress;
@property (readonly) double downloadProgressOffset;
@property (readonly) BOOL isAudioOnly;
@property (readonly) BOOL isStereo3DVideo;
@property (readonly) WUXMTimelineMarkerCollection* markers;
+ (WXDependencyProperty*)areTransportControlsEnabledProperty;
+ (WXDependencyProperty*)isFullWindowProperty;
+ (WXDependencyProperty*)playToPreferredSourceUriProperty;
+ (WXDependencyProperty*)stretchProperty;
+ (WXDependencyProperty*)audioStreamCountProperty;
+ (WXDependencyProperty*)playToSourceProperty;
+ (WXDependencyProperty*)actualStereo3DVideoPackingModeProperty;
+ (WXDependencyProperty*)aspectRatioHeightProperty;
+ (WXDependencyProperty*)aspectRatioWidthProperty;
+ (WXDependencyProperty*)audioCategoryProperty;
+ (WXDependencyProperty*)audioDeviceTypeProperty;
+ (WXDependencyProperty*)audioStreamIndexProperty;
+ (WXDependencyProperty*)autoPlayProperty;
+ (WXDependencyProperty*)balanceProperty;
+ (WXDependencyProperty*)bufferingProgressProperty;
+ (WXDependencyProperty*)canPauseProperty;
+ (WXDependencyProperty*)canSeekProperty;
+ (WXDependencyProperty*)currentStateProperty;
+ (WXDependencyProperty*)defaultPlaybackRateProperty;
+ (WXDependencyProperty*)downloadProgressOffsetProperty;
+ (WXDependencyProperty*)downloadProgressProperty;
+ (WXDependencyProperty*)isAudioOnlyProperty;
+ (WXDependencyProperty*)isLoopingProperty;
+ (WXDependencyProperty*)isMutedProperty;
+ (WXDependencyProperty*)isStereo3DVideoProperty;
+ (WXDependencyProperty*)naturalDurationProperty;
+ (WXDependencyProperty*)naturalVideoHeightProperty;
+ (WXDependencyProperty*)naturalVideoWidthProperty;
+ (WXDependencyProperty*)playbackRateProperty;
+ (WXDependencyProperty*)positionProperty;
+ (WXDependencyProperty*)posterSourceProperty;
+ (WXDependencyProperty*)protectionManagerProperty;
+ (WXDependencyProperty*)realTimePlaybackProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)stereo3DVideoPackingModeProperty;
+ (WXDependencyProperty*)stereo3DVideoRenderModeProperty;
+ (WXDependencyProperty*)volumeProperty;
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
- (void)stop;
- (void)play;
- (void)pause;
- (WUXMMediaCanPlayResponse)canPlayType:(NSString*)type;
- (void)setSource:(RTObject<WSSIRandomAccessStream>*)stream mimeType:(NSString*)mimeType;
- (NSString*)getAudioStreamLanguage:(NSNumber*)index;
- (void)addAudioEffect:(NSString*)effectID
        effectOptional:(BOOL)effectOptional
   effectConfiguration:(RTObject<WFCIPropertySet>*)effectConfiguration;
- (void)addVideoEffect:(NSString*)effectID
        effectOptional:(BOOL)effectOptional
   effectConfiguration:(RTObject<WFCIPropertySet>*)effectConfiguration;
- (void)removeAllEffects;
- (void)setMediaStreamSource:(RTObject<WMCIMediaSource>*)source;
@end

#endif // __WXCMediaElement_DEFINED__

// Windows.UI.Xaml.Controls.RichTextBlockOverflow
#ifndef __WXCRichTextBlockOverflow_DEFINED__
#define __WXCRichTextBlockOverflow_DEFINED__

WINRT_EXPORT
@interface WXCRichTextBlockOverflow : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WXThickness* padding;
@property (copy) WXCRichTextBlockOverflow* overflowContentTarget;
@property (readonly) double baselineOffset;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) WXCRichTextBlock* contentSource;
@property (readonly) WUXDTextPointer* contentStart;
@property (readonly) BOOL hasOverflowContent;
@property int maxLines;
+ (WXDependencyProperty*)hasOverflowContentProperty;
+ (WXDependencyProperty*)overflowContentTargetProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)maxLinesProperty;
- (WUXDTextPointer*)getPositionFromPoint:(WFPoint*)point;
- (BOOL)focus:(WXFocusState)value;
@end

#endif // __WXCRichTextBlockOverflow_DEFINED__

// Windows.UI.Xaml.Controls.RichTextBlock
#ifndef __WXCRichTextBlock_DEFINED__
#define __WXCRichTextBlock_DEFINED__

WINRT_EXPORT
@interface WXCRichTextBlock : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property WXTextWrapping textWrapping;
@property WXTextTrimming textTrimming;
@property double textIndent;
@property WXTextAlignment textAlignment;
@property (copy) WXThickness* padding;
@property (copy) WXCRichTextBlockOverflow* overflowContentTarget;
@property (copy) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property double fontSize;
@property (copy) WUXMFontFamily* fontFamily;
@property double lineHeight;
@property BOOL isTextSelectionEnabled;
@property int characterSpacing;
@property WXLineStackingStrategy lineStackingStrategy;
@property (copy) WUXMBrush* foreground;
@property (readonly) WUXDBlockCollection* blocks;
@property (readonly) NSString* selectedText;
@property (readonly) WUXDTextPointer* selectionEnd;
@property (readonly) WUXDTextPointer* selectionStart;
@property (readonly) WUXDTextPointer* contentStart;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) BOOL hasOverflowContent;
@property (readonly) double baselineOffset;
@property WXTextLineBounds textLineBounds;
@property (copy) WUXMSolidColorBrush* selectionHighlightColor;
@property WXOpticalMarginAlignment opticalMarginAlignment;
@property WXTextReadingOrder textReadingOrder;
@property int maxLines;
@property BOOL isColorFontEnabled;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)maxLinesProperty;
+ (WXDependencyProperty*)opticalMarginAlignmentProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)textLineBoundsProperty;
+ (WXDependencyProperty*)textReadingOrderProperty;
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
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)selectedTextProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)textIndentProperty;
+ (WXDependencyProperty*)textTrimmingProperty;
+ (WXDependencyProperty*)textWrappingProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (void)selectAll;
- (void)select:(WUXDTextPointer*)start end:(WUXDTextPointer*)end;
- (WUXDTextPointer*)getPositionFromPoint:(WFPoint*)point;
- (BOOL)focus:(WXFocusState)value;
@end

#endif // __WXCRichTextBlock_DEFINED__

// Windows.UI.Xaml.Controls.ScrollContentPresenter
#ifndef __WXCScrollContentPresenter_DEFINED__
#define __WXCScrollContentPresenter_DEFINED__

WINRT_EXPORT
@interface WXCScrollContentPresenter : WXCContentPresenter
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* scrollOwner;
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

// Windows.UI.Xaml.Controls.StackPanel
#ifndef __WXCStackPanel_DEFINED__
#define __WXCStackPanel_DEFINED__

WINRT_EXPORT
@interface WXCStackPanel : WXCPanel <WUXCPIScrollSnapPointsInfo>
+ (instancetype)create ACTIVATOR;
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
@property WXCOrientation orientation;
@property BOOL areScrollSnapPointsRegular;
+ (WXDependencyProperty*)areScrollSnapPointsRegularProperty;
+ (WXDependencyProperty*)orientationProperty;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (id<NSFastEnumeration> /*Single*/)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WXCStackPanel_DEFINED__

// Windows.UI.Xaml.Controls.TextBlock
#ifndef __WXCTextBlock_DEFINED__
#define __WXCTextBlock_DEFINED__

WINRT_EXPORT
@interface WXCTextBlock : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property WXTextReadingOrder textReadingOrder;
@property WXTextLineBounds textLineBounds;
@property int maxLines;
@property BOOL isColorFontEnabled;
@property WXOpticalMarginAlignment opticalMarginAlignment;
@property (copy) WUXMSolidColorBrush* selectionHighlightColor;
@property WXLineStackingStrategy lineStackingStrategy;
@property (copy) WUXMBrush* foreground;
@property (copy) WUTFontWeight* fontWeight;
@property WXTextAlignment textAlignment;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property double fontSize;
@property (copy) WUXMFontFamily* fontFamily;
@property double lineHeight;
@property BOOL isTextSelectionEnabled;
@property int characterSpacing;
@property (copy) NSString* text;
@property WXTextWrapping textWrapping;
@property (copy) WXThickness* padding;
@property WXTextTrimming textTrimming;
@property (readonly) NSString* selectedText;
@property (readonly) WUXDTextPointer* selectionEnd;
@property (readonly) WUXDTextPointer* selectionStart;
@property (readonly) WUXDInlineCollection* inlines;
@property (readonly) WUXDTextPointer* contentEnd;
@property (readonly) WUXDTextPointer* contentStart;
@property (readonly) double baselineOffset;
+ (WXDependencyProperty*)textReadingOrderProperty;
+ (WXDependencyProperty*)textLineBoundsProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)opticalMarginAlignmentProperty;
+ (WXDependencyProperty*)maxLinesProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)isTextSelectionEnabledProperty;
+ (WXDependencyProperty*)lineHeightProperty;
+ (WXDependencyProperty*)lineStackingStrategyProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)selectedTextProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)textTrimmingProperty;
+ (WXDependencyProperty*)textWrappingProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (void)selectAll;
- (void)select:(WUXDTextPointer*)start end:(WUXDTextPointer*)end;
- (BOOL)focus:(WXFocusState)value;
@end

#endif // __WXCTextBlock_DEFINED__

// Windows.UI.Xaml.Controls.VariableSizedWrapGrid
#ifndef __WXCVariableSizedWrapGrid_DEFINED__
#define __WXCVariableSizedWrapGrid_DEFINED__

WINRT_EXPORT
@interface WXCVariableSizedWrapGrid : WXCPanel
+ (int)getRowSpan:(WXUIElement*)element;
+ (void)setRowSpan:(WXUIElement*)element value:(int)value;
+ (int)getColumnSpan:(WXUIElement*)element;
+ (void)setColumnSpan:(WXUIElement*)element value:(int)value;
+ (instancetype)create ACTIVATOR;
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

// Windows.UI.Xaml.Controls.Viewbox
#ifndef __WXCViewbox_DEFINED__
#define __WXCViewbox_DEFINED__

WINRT_EXPORT
@interface WXCViewbox : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property WXCStretchDirection stretchDirection;
@property WUXMStretch stretch;
@property (copy) WXUIElement* child;
+ (WXDependencyProperty*)stretchDirectionProperty;
+ (WXDependencyProperty*)stretchProperty;
@end

#endif // __WXCViewbox_DEFINED__

// Windows.UI.Xaml.Controls.VirtualizingPanel
#ifndef __WXCVirtualizingPanel_DEFINED__
#define __WXCVirtualizingPanel_DEFINED__

WINRT_EXPORT
@interface WXCVirtualizingPanel : WXCPanel
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

WINRT_EXPORT
@interface WUXCPOrientedVirtualizingPanel : WXCVirtualizingPanel <WUXCPIScrollSnapPointsInfo>
@property (copy) RTObject* scrollOwner;
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
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
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
- (id<NSFastEnumeration> /*Single*/)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WUXCPOrientedVirtualizingPanel_DEFINED__

// Windows.UI.Xaml.Controls.VirtualizingStackPanel
#ifndef __WXCVirtualizingStackPanel_DEFINED__
#define __WXCVirtualizingStackPanel_DEFINED__

WINRT_EXPORT
@interface WXCVirtualizingStackPanel : WUXCPOrientedVirtualizingPanel
+ (WXCVirtualizationMode)getVirtualizationMode:(WXDependencyObject*)element;
+ (void)setVirtualizationMode:(WXDependencyObject*)element value:(WXCVirtualizationMode)value;
+ (BOOL)getIsVirtualizing:(WXDependencyObject*)o;
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WXCIconElement : WXFrameworkElement
@property (copy) WUXMBrush* foreground;
+ (WXDependencyProperty*)foregroundProperty;
@end

#endif // __WXCIconElement_DEFINED__

// Windows.UI.Xaml.Controls.BitmapIcon
#ifndef __WXCBitmapIcon_DEFINED__
#define __WXCBitmapIcon_DEFINED__

WINRT_EXPORT
@interface WXCBitmapIcon : WXCIconElement
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* uriSource;
+ (WXDependencyProperty*)uriSourceProperty;
@end

#endif // __WXCBitmapIcon_DEFINED__

// Windows.UI.Xaml.Controls.FontIcon
#ifndef __WXCFontIcon_DEFINED__
#define __WXCFontIcon_DEFINED__

WINRT_EXPORT
@interface WXCFontIcon : WXCIconElement
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* glyph;
@property (copy) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property double fontSize;
@property (copy) WUXMFontFamily* fontFamily;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)glyphProperty;
@end

#endif // __WXCFontIcon_DEFINED__

// Windows.UI.Xaml.Controls.ItemsStackPanel
#ifndef __WXCItemsStackPanel_DEFINED__
#define __WXCItemsStackPanel_DEFINED__

WINRT_EXPORT
@interface WXCItemsStackPanel : WXCPanel
+ (instancetype)create ACTIVATOR;
@property WXCOrientation orientation;
@property WXCItemsUpdatingScrollMode itemsUpdatingScrollMode;
@property (copy) WXThickness* groupPadding;
@property WUXCPGroupHeaderPlacement groupHeaderPlacement;
@property double cacheLength;
@property (readonly) int firstCacheIndex;
@property (readonly) int firstVisibleIndex;
@property (readonly) int lastCacheIndex;
@property (readonly) int lastVisibleIndex;
@property (readonly) WXCPanelScrollingDirection scrollingDirection;
+ (WXDependencyProperty*)cacheLengthProperty;
+ (WXDependencyProperty*)groupHeaderPlacementProperty;
+ (WXDependencyProperty*)groupPaddingProperty;
+ (WXDependencyProperty*)orientationProperty;
@end

#endif // __WXCItemsStackPanel_DEFINED__

// Windows.UI.Xaml.Controls.ItemsWrapGrid
#ifndef __WXCItemsWrapGrid_DEFINED__
#define __WXCItemsWrapGrid_DEFINED__

WINRT_EXPORT
@interface WXCItemsWrapGrid : WXCPanel
+ (instancetype)create ACTIVATOR;
@property WXCOrientation orientation;
@property int maximumRowsOrColumns;
@property double itemWidth;
@property double itemHeight;
@property (copy) WXThickness* groupPadding;
@property WUXCPGroupHeaderPlacement groupHeaderPlacement;
@property double cacheLength;
@property (readonly) int firstCacheIndex;
@property (readonly) int firstVisibleIndex;
@property (readonly) int lastCacheIndex;
@property (readonly) int lastVisibleIndex;
@property (readonly) WXCPanelScrollingDirection scrollingDirection;
+ (WXDependencyProperty*)cacheLengthProperty;
+ (WXDependencyProperty*)groupHeaderPlacementProperty;
+ (WXDependencyProperty*)groupPaddingProperty;
+ (WXDependencyProperty*)itemHeightProperty;
+ (WXDependencyProperty*)itemWidthProperty;
+ (WXDependencyProperty*)maximumRowsOrColumnsProperty;
+ (WXDependencyProperty*)orientationProperty;
@end

#endif // __WXCItemsWrapGrid_DEFINED__

// Windows.UI.Xaml.Controls.PathIcon
#ifndef __WXCPathIcon_DEFINED__
#define __WXCPathIcon_DEFINED__

WINRT_EXPORT
@interface WXCPathIcon : WXCIconElement
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMGeometry* data;
+ (WXDependencyProperty*)dataProperty;
@end

#endif // __WXCPathIcon_DEFINED__

// Windows.UI.Xaml.Controls.SwapChainBackgroundPanel
#ifndef __WXCSwapChainBackgroundPanel_DEFINED__
#define __WXCSwapChainBackgroundPanel_DEFINED__

WINRT_EXPORT
@interface WXCSwapChainBackgroundPanel : WXCGrid
+ (instancetype)create ACTIVATOR;
- (WUCCoreIndependentInputSource*)createCoreIndependentInputSource:(WUCCoreInputDeviceTypes)deviceTypes;
@end

#endif // __WXCSwapChainBackgroundPanel_DEFINED__

// Windows.UI.Xaml.Controls.SwapChainPanel
#ifndef __WXCSwapChainPanel_DEFINED__
#define __WXCSwapChainPanel_DEFINED__

WINRT_EXPORT
@interface WXCSwapChainPanel : WXCGrid
+ (instancetype)create ACTIVATOR;
@property (readonly) float compositionScaleX;
@property (readonly) float compositionScaleY;
+ (WXDependencyProperty*)compositionScaleXProperty;
+ (WXDependencyProperty*)compositionScaleYProperty;
- (EventRegistrationToken)addCompositionScaleChangedEvent:(void (^)(WXCSwapChainPanel*, RTObject*))del;
- (void)removeCompositionScaleChangedEvent:(EventRegistrationToken)tok;
- (WUCCoreIndependentInputSource*)createCoreIndependentInputSource:(WUCCoreInputDeviceTypes)deviceTypes;
@end

#endif // __WXCSwapChainPanel_DEFINED__

// Windows.UI.Xaml.Controls.SymbolIcon
#ifndef __WXCSymbolIcon_DEFINED__
#define __WXCSymbolIcon_DEFINED__

WINRT_EXPORT
@interface WXCSymbolIcon : WXCIconElement
+ (WXCSymbolIcon*)createInstanceWithSymbol:(WXCSymbol)symbol ACTIVATOR;
+ (instancetype)create ACTIVATOR;
@property WXCSymbol symbol;
+ (WXDependencyProperty*)symbolProperty;
@end

#endif // __WXCSymbolIcon_DEFINED__

// Windows.UI.Xaml.Controls.WebView
#ifndef __WXCWebView_DEFINED__
#define __WXCWebView_DEFINED__

WINRT_EXPORT
@interface WXCWebView : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* source;
@property (copy) id<NSFastEnumeration> /*WFUri*/ allowedScriptNotifyUris;
@property (readonly) WADDataPackage* dataTransferPackage;
@property (copy) WUColor* defaultBackgroundColor;
@property (readonly) BOOL canGoBack;
@property (readonly) BOOL canGoForward;
@property (readonly) NSString* documentTitle;
+ (WXDependencyProperty*)allowedScriptNotifyUrisProperty;
+ (id<NSFastEnumeration> /*WFUri*/)anyScriptNotifyUri;
+ (WXDependencyProperty*)dataTransferPackageProperty;
+ (WXDependencyProperty*)sourceProperty;
+ (WXDependencyProperty*)canGoBackProperty;
+ (WXDependencyProperty*)canGoForwardProperty;
+ (WXDependencyProperty*)defaultBackgroundColorProperty;
+ (WXDependencyProperty*)documentTitleProperty;
- (EventRegistrationToken)addLoadCompletedEvent:(WUXNLoadCompletedEventHandler)del;
- (void)removeLoadCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationFailedEvent:(WXCWebViewNavigationFailedEventHandler)del;
- (void)removeNavigationFailedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addScriptNotifyEvent:(WXCNotifyEventHandler)del;
- (void)removeScriptNotifyEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContentLoadingEvent:(void (^)(WXCWebView*, WXCWebViewContentLoadingEventArgs*))del;
- (void)removeContentLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDOMContentLoadedEvent:(void (^)(WXCWebView*, WXCWebViewDOMContentLoadedEventArgs*))del;
- (void)removeDOMContentLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameContentLoadingEvent:(void (^)(WXCWebView*, WXCWebViewContentLoadingEventArgs*))del;
- (void)removeFrameContentLoadingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameDOMContentLoadedEvent:(void (^)(WXCWebView*, WXCWebViewDOMContentLoadedEventArgs*))del;
- (void)removeFrameDOMContentLoadedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameNavigationCompletedEvent:(void (^)(WXCWebView*, WXCWebViewNavigationCompletedEventArgs*))del;
- (void)removeFrameNavigationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFrameNavigationStartingEvent:(void (^)(WXCWebView*, WXCWebViewNavigationStartingEventArgs*))del;
- (void)removeFrameNavigationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLongRunningScriptDetectedEvent:(void (^)(WXCWebView*, WXCWebViewLongRunningScriptDetectedEventArgs*))del;
- (void)removeLongRunningScriptDetectedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationCompletedEvent:(void (^)(WXCWebView*, WXCWebViewNavigationCompletedEventArgs*))del;
- (void)removeNavigationCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addNavigationStartingEvent:(void (^)(WXCWebView*, WXCWebViewNavigationStartingEventArgs*))del;
- (void)removeNavigationStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnsafeContentWarningDisplayingEvent:(void (^)(WXCWebView*, RTObject*))del;
- (void)removeUnsafeContentWarningDisplayingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addUnviewableContentIdentifiedEvent:(void (^)(WXCWebView*, WXCWebViewUnviewableContentIdentifiedEventArgs*))del;
- (void)removeUnviewableContentIdentifiedEvent:(EventRegistrationToken)tok;
- (NSString*)invokeScript:(NSString*)scriptName arguments:(id<NSFastEnumeration> /*String*/)arguments;
- (void)navigate:(WFUri*)source;
- (void)navigateToString:(NSString*)text;
- (void)goForward;
- (void)goBack;
- (void)refresh;
- (void)stop;
- (RTObject<WFIAsyncAction>*)capturePreviewToStreamAsync:(RTObject<WSSIRandomAccessStream>*)stream;
- (void)invokeScriptAsync:(NSString*)scriptName
                arguments:(id<NSFastEnumeration> /*String*/)arguments
                  success:(void (^)(NSString*))success
                  failure:(void (^)(NSError*))failure;
- (void)captureSelectedContentToDataPackageAsyncWithSuccess:(void (^)(WADDataPackage*))success failure:(void (^)(NSError*))failure;
- (void)navigateToLocalStreamUri:(WFUri*)source streamResolver:(RTObject<WWIUriToStreamResolver>*)streamResolver;
- (WFUri*)buildLocalStreamUri:(NSString*)contentIdentifier relativePath:(NSString*)relativePath;
- (void)navigateWithHttpRequestMessage:(WWHHttpRequestMessage*)requestMessage;
- (BOOL)focus:(WXFocusState)value;
@end

#endif // __WXCWebView_DEFINED__

// Windows.UI.Xaml.Controls.WrapGrid
#ifndef __WXCWrapGrid_DEFINED__
#define __WXCWrapGrid_DEFINED__

WINRT_EXPORT
@interface WXCWrapGrid : WUXCPOrientedVirtualizingPanel
+ (instancetype)create ACTIVATOR;
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

// Windows.UI.Xaml.Media.Brush
#ifndef __WUXMBrush_DEFINED__
#define __WUXMBrush_DEFINED__

WINRT_EXPORT
@interface WUXMBrush : WXDependencyObject
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMTransform* transform;
@property (copy) WUXMTransform* relativeTransform;
@property double opacity;
+ (WXDependencyProperty*)opacityProperty;
+ (WXDependencyProperty*)relativeTransformProperty;
+ (WXDependencyProperty*)transformProperty;
@end

#endif // __WUXMBrush_DEFINED__

// Windows.UI.Xaml.Media.TileBrush
#ifndef __WUXMTileBrush_DEFINED__
#define __WUXMTileBrush_DEFINED__

WINRT_EXPORT
@interface WUXMTileBrush : WUXMBrush
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WXCWebViewBrush : WUXMTileBrush
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* sourceName;
+ (WXDependencyProperty*)sourceNameProperty;
- (void)redraw;
- (void)setSource:(WXCWebView*)source;
@end

#endif // __WXCWebViewBrush_DEFINED__

// Windows.UI.Xaml.Controls.Control
#ifndef __WXCControl_DEFINED__
#define __WXCControl_DEFINED__

WINRT_EXPORT
@interface WXCControl : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property double fontSize;
@property (copy) WUXMFontFamily* fontFamily;
@property (copy) WUTFontWeight* fontWeight;
@property int characterSpacing;
@property (copy) WXThickness* borderThickness;
@property (copy) WUXMBrush* borderBrush;
@property (copy) WUXMBrush* background;
@property WXVerticalAlignment verticalContentAlignment;
@property (copy) WXCControlTemplate* Template;
@property WUXIKeyboardNavigationMode tabNavigation;
@property int tabIndex;
@property (copy) WXThickness* padding;
@property BOOL isTabStop;
@property BOOL isEnabled;
@property WXHorizontalAlignment horizontalContentAlignment;
@property (copy) WUXMBrush* foreground;
@property (readonly) WXFocusState focusState;
@property (copy) RTObject* defaultStyleKey;
+ (WXDependencyProperty*)verticalContentAlignmentProperty;
+ (WXDependencyProperty*)templateProperty;
+ (WXDependencyProperty*)tabNavigationProperty;
+ (WXDependencyProperty*)tabIndexProperty;
+ (WXDependencyProperty*)paddingProperty;
+ (WXDependencyProperty*)isTabStopProperty;
+ (WXDependencyProperty*)isEnabledProperty;
+ (WXDependencyProperty*)horizontalContentAlignmentProperty;
+ (WXDependencyProperty*)foregroundProperty;
+ (WXDependencyProperty*)fontWeightProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)focusStateProperty;
+ (WXDependencyProperty*)defaultStyleKeyProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)backgroundProperty;
- (EventRegistrationToken)addIsEnabledChangedEvent:(WXDependencyPropertyChangedEventHandler)del;
- (void)removeIsEnabledChangedEvent:(EventRegistrationToken)tok;
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
- (WXDependencyObject*)getTemplateChild:(NSString*)childName;
@end

#endif // __WXCControl_DEFINED__

// Windows.UI.Xaml.Controls.ContentControl
#ifndef __WXCContentControl_DEFINED__
#define __WXCContentControl_DEFINED__

WINRT_EXPORT
@interface WXCContentControl : WXCControl
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMATransitionCollection* contentTransitions;
@property (copy) WXCDataTemplateSelector* contentTemplateSelector;
@property (copy) WXDataTemplate* contentTemplate;
@property (copy) RTObject* content;
@property (readonly) WXUIElement* contentTemplateRoot;
+ (WXDependencyProperty*)contentProperty;
+ (WXDependencyProperty*)contentTemplateProperty;
+ (WXDependencyProperty*)contentTemplateSelectorProperty;
+ (WXDependencyProperty*)contentTransitionsProperty;
- (void)onContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector
              newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

#endif // __WXCContentControl_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.SelectorItem
#ifndef __WUXCPSelectorItem_DEFINED__
#define __WUXCPSelectorItem_DEFINED__

WINRT_EXPORT
@interface WUXCPSelectorItem : WXCContentControl
+ (instancetype)create ACTIVATOR;
@property BOOL isSelected;
+ (WXDependencyProperty*)isSelectedProperty;
@end

#endif // __WUXCPSelectorItem_DEFINED__

// Windows.UI.Xaml.Controls.ComboBoxItem
#ifndef __WXCComboBoxItem_DEFINED__
#define __WXCComboBoxItem_DEFINED__

WINRT_EXPORT
@interface WXCComboBoxItem : WUXCPSelectorItem
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCComboBoxItem_DEFINED__

// Windows.UI.Xaml.Controls.DatePicker
#ifndef __WXCDatePicker_DEFINED__
#define __WXCDatePicker_DEFINED__

WINRT_EXPORT
@interface WXCDatePicker : WXCControl
+ (instancetype)create ACTIVATOR;
@property BOOL yearVisible;
@property (copy) NSString* yearFormat;
@property WXCOrientation orientation;
@property BOOL monthVisible;
@property (copy) NSString* monthFormat;
@property (copy) WFDateTime* minYear;
@property (copy) WFDateTime* maxYear;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
@property BOOL dayVisible;
@property (copy) NSString* dayFormat;
@property (copy) WFDateTime* date;
@property (copy) NSString* calendarIdentifier;
+ (WXDependencyProperty*)calendarIdentifierProperty;
+ (WXDependencyProperty*)dateProperty;
+ (WXDependencyProperty*)dayFormatProperty;
+ (WXDependencyProperty*)dayVisibleProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)maxYearProperty;
+ (WXDependencyProperty*)minYearProperty;
+ (WXDependencyProperty*)monthFormatProperty;
+ (WXDependencyProperty*)monthVisibleProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)yearFormatProperty;
+ (WXDependencyProperty*)yearVisibleProperty;
- (EventRegistrationToken)addDateChangedEvent:(void (^)(RTObject*, WXCDatePickerValueChangedEventArgs*))del;
- (void)removeDateChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCDatePicker_DEFINED__

// Windows.UI.Xaml.Controls.FlipViewItem
#ifndef __WXCFlipViewItem_DEFINED__
#define __WXCFlipViewItem_DEFINED__

WINRT_EXPORT
@interface WXCFlipViewItem : WUXCPSelectorItem
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCFlipViewItem_DEFINED__

// Windows.UI.Xaml.Controls.GridViewItem
#ifndef __WXCGridViewItem_DEFINED__
#define __WXCGridViewItem_DEFINED__

WINRT_EXPORT
@interface WXCGridViewItem : WUXCPSelectorItem
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXCPGridViewItemTemplateSettings* templateSettings;
@end

#endif // __WXCGridViewItem_DEFINED__

// Windows.UI.Xaml.Controls.GroupItem
#ifndef __WXCGroupItem_DEFINED__
#define __WXCGroupItem_DEFINED__

WINRT_EXPORT
@interface WXCGroupItem : WXCContentControl
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCGroupItem_DEFINED__

// Windows.UI.Xaml.Controls.SemanticZoom
#ifndef __WXCSemanticZoom_DEFINED__
#define __WXCSemanticZoom_DEFINED__

WINRT_EXPORT
@interface WXCSemanticZoom : WXCControl
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject<WXCISemanticZoomInformation>* zoomedOutView;
@property (copy) RTObject<WXCISemanticZoomInformation>* zoomedInView;
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

// Windows.UI.Xaml.Controls.ItemsControl
#ifndef __WXCItemsControl_DEFINED__
#define __WXCItemsControl_DEFINED__

WINRT_EXPORT
@interface WXCItemsControl : WXCControl <WXCIItemContainerMapping>
+ (WXCItemsControl*)getItemsOwner:(WXDependencyObject*)element;
+ (WXCItemsControl*)itemsControlFromItemContainer:(WXDependencyObject*)container;
+ (instancetype)create ACTIVATOR;
@property (readonly) WXCPanel* itemsPanelRoot;
@property (copy) RTObject* itemsSource;
@property (copy) WXCItemsPanelTemplate* itemsPanel;
@property (copy) WXCDataTemplateSelector* itemTemplateSelector;
@property (copy) WXDataTemplate* itemTemplate;
@property (copy) WUXMATransitionCollection* itemContainerTransitions;
@property (copy) WXCStyleSelector* itemContainerStyleSelector;
@property (copy) WXStyle* itemContainerStyle;
@property (copy) WXCGroupStyleSelector* groupStyleSelector;
@property (copy) NSString* displayMemberPath;
// Failed to generate property GroupStyle (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.UI.Xaml.Controls.GroupStyle>)
@property (readonly) BOOL isGrouping;
@property (readonly) WXCItemContainerGenerator* itemContainerGenerator;
@property (readonly) WXCItemCollection* items;
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
// Failed to generate member get_GroupStyle (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.UI.Xaml.Controls.GroupStyle>)
- (RTObject*)itemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromItem:(RTObject*)item;
- (int)indexFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromIndex:(int)index;
- (BOOL)isItemItsOwnContainerOverride:(RTObject*)item;
- (WXDependencyObject*)getContainerForItemOverride;
- (void)clearContainerForItemOverride:(WXDependencyObject*)element item:(RTObject*)item;
- (void)prepareContainerForItemOverride:(WXDependencyObject*)element item:(RTObject*)item;
- (void)onItemsChanged:(RTObject*)e;
- (void)onItemContainerStyleChanged:(WXStyle*)oldItemContainerStyle newItemContainerStyle:(WXStyle*)newItemContainerStyle;
- (void)onItemContainerStyleSelectorChanged:(WXCStyleSelector*)oldItemContainerStyleSelector
              newItemContainerStyleSelector:(WXCStyleSelector*)newItemContainerStyleSelector;
- (void)onItemTemplateChanged:(WXDataTemplate*)oldItemTemplate newItemTemplate:(WXDataTemplate*)newItemTemplate;
- (void)onItemTemplateSelectorChanged:(WXCDataTemplateSelector*)oldItemTemplateSelector
              newItemTemplateSelector:(WXCDataTemplateSelector*)newItemTemplateSelector;
- (void)onGroupStyleSelectorChanged:(WXCGroupStyleSelector*)oldGroupStyleSelector
              newGroupStyleSelector:(WXCGroupStyleSelector*)newGroupStyleSelector;
@end

#endif // __WXCItemsControl_DEFINED__

// Windows.UI.Xaml.Controls.ListBoxItem
#ifndef __WXCListBoxItem_DEFINED__
#define __WXCListBoxItem_DEFINED__

WINRT_EXPORT
@interface WXCListBoxItem : WUXCPSelectorItem
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCListBoxItem_DEFINED__

// Windows.UI.Xaml.Controls.ListViewItem
#ifndef __WXCListViewItem_DEFINED__
#define __WXCListViewItem_DEFINED__

WINRT_EXPORT
@interface WXCListViewItem : WUXCPSelectorItem
+ (instancetype)create ACTIVATOR;
@property (readonly) WUXCPListViewItemTemplateSettings* templateSettings;
@end

#endif // __WXCListViewItem_DEFINED__

// Windows.UI.Xaml.Controls.PasswordBox
#ifndef __WXCPasswordBox_DEFINED__
#define __WXCPasswordBox_DEFINED__

WINRT_EXPORT
@interface WXCPasswordBox : WXCControl
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* passwordChar;
@property (copy) NSString* password;
@property int maxLength;
@property BOOL isPasswordRevealButtonEnabled;
@property (copy) WUXMSolidColorBrush* selectionHighlightColor;
@property BOOL preventKeyboardDisplayOnProgrammaticFocus;
@property (copy) NSString* placeholderText;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)preventKeyboardDisplayOnProgrammaticFocusProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)isPasswordRevealButtonEnabledProperty;
+ (WXDependencyProperty*)maxLengthProperty;
+ (WXDependencyProperty*)passwordCharProperty;
+ (WXDependencyProperty*)passwordProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasswordChangedEvent:(WXRoutedEventHandler)del;
- (void)removePasswordChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasteEvent:(WXCTextControlPasteEventHandler)del;
- (void)removePasteEvent:(EventRegistrationToken)tok;
- (void)selectAll;
@end

#endif // __WXCPasswordBox_DEFINED__

// Windows.UI.Xaml.Controls.ProgressRing
#ifndef __WXCProgressRing_DEFINED__
#define __WXCProgressRing_DEFINED__

WINRT_EXPORT
@interface WXCProgressRing : WXCControl
+ (instancetype)create ACTIVATOR;
@property BOOL isActive;
@property (readonly) WUXCPProgressRingTemplateSettings* templateSettings;
+ (WXDependencyProperty*)isActiveProperty;
@end

#endif // __WXCProgressRing_DEFINED__

// Windows.UI.Xaml.Controls.RichEditBox
#ifndef __WXCRichEditBox_DEFINED__
#define __WXCRichEditBox_DEFINED__

WINRT_EXPORT
@interface WXCRichEditBox : WXCControl
+ (instancetype)create ACTIVATOR;
@property WXTextWrapping textWrapping;
@property WXTextAlignment textAlignment;
@property BOOL isTextPredictionEnabled;
@property BOOL isSpellCheckEnabled;
@property BOOL isReadOnly;
@property (copy) WUXIInputScope* inputScope;
@property BOOL acceptsReturn;
@property (readonly) RTObject<WUTITextDocument>* document;
@property (copy) WUXMSolidColorBrush* selectionHighlightColor;
@property BOOL preventKeyboardDisplayOnProgrammaticFocus;
@property (copy) NSString* placeholderText;
@property BOOL isColorFontEnabled;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)preventKeyboardDisplayOnProgrammaticFocusProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)acceptsReturnProperty;
+ (WXDependencyProperty*)inputScopeProperty;
+ (WXDependencyProperty*)isReadOnlyProperty;
+ (WXDependencyProperty*)isSpellCheckEnabledProperty;
+ (WXDependencyProperty*)isTextPredictionEnabledProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)textWrappingProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextChangedEvent:(WXRoutedEventHandler)del;
- (void)removeTextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasteEvent:(WXCTextControlPasteEventHandler)del;
- (void)removePasteEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCRichEditBox_DEFINED__

// Windows.UI.Xaml.Controls.ScrollViewer
#ifndef __WXCScrollViewer_DEFINED__
#define __WXCScrollViewer_DEFINED__

WINRT_EXPORT
@interface WXCScrollViewer : WXCContentControl
+ (WXCScrollBarVisibility)getHorizontalScrollBarVisibility:(WXDependencyObject*)element;
+ (void)setHorizontalScrollBarVisibility:(WXDependencyObject*)element
           horizontalScrollBarVisibility:(WXCScrollBarVisibility)horizontalScrollBarVisibility;
+ (WXCScrollBarVisibility)getVerticalScrollBarVisibility:(WXDependencyObject*)element;
+ (void)setVerticalScrollBarVisibility:(WXDependencyObject*)element
           verticalScrollBarVisibility:(WXCScrollBarVisibility)verticalScrollBarVisibility;
+ (BOOL)getIsHorizontalRailEnabled:(WXDependencyObject*)element;
+ (void)setIsHorizontalRailEnabled:(WXDependencyObject*)element isHorizontalRailEnabled:(BOOL)isHorizontalRailEnabled;
+ (BOOL)getIsVerticalRailEnabled:(WXDependencyObject*)element;
+ (void)setIsVerticalRailEnabled:(WXDependencyObject*)element isVerticalRailEnabled:(BOOL)isVerticalRailEnabled;
+ (BOOL)getIsHorizontalScrollChainingEnabled:(WXDependencyObject*)element;
+ (void)setIsHorizontalScrollChainingEnabled:(WXDependencyObject*)element
           isHorizontalScrollChainingEnabled:(BOOL)isHorizontalScrollChainingEnabled;
+ (BOOL)getIsVerticalScrollChainingEnabled:(WXDependencyObject*)element;
+ (void)setIsVerticalScrollChainingEnabled:(WXDependencyObject*)element
           isVerticalScrollChainingEnabled:(BOOL)isVerticalScrollChainingEnabled;
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
+ (instancetype)create ACTIVATOR;
@property BOOL isHorizontalScrollChainingEnabled;
@property BOOL isHorizontalRailEnabled;
@property BOOL isDeferredScrollingEnabled;
@property WXCSnapPointsType horizontalSnapPointsType;
@property BOOL isZoomInertiaEnabled;
@property WUXCPSnapPointsAlignment horizontalSnapPointsAlignment;
@property WXCScrollMode horizontalScrollMode;
@property WXCScrollBarVisibility horizontalScrollBarVisibility;
@property BOOL isZoomChainingEnabled;
@property BOOL isVerticalScrollChainingEnabled;
@property BOOL isVerticalRailEnabled;
@property BOOL isScrollInertiaEnabled;
@property BOOL bringIntoViewOnFocusChange;
@property WXCSnapPointsType zoomSnapPointsType;
@property WXCZoomMode zoomMode;
@property WXCSnapPointsType verticalSnapPointsType;
@property WUXCPSnapPointsAlignment verticalSnapPointsAlignment;
@property float minZoomFactor;
@property WXCScrollBarVisibility verticalScrollBarVisibility;
@property WXCScrollMode verticalScrollMode;
@property float maxZoomFactor;
@property (readonly) double extentWidth;
@property (readonly) double extentHeight;
@property (readonly) double scrollableHeight;
@property (readonly) double scrollableWidth;
@property (readonly) double verticalOffset;
@property (readonly) WXVisibility computedHorizontalScrollBarVisibility;
@property (readonly) WXVisibility computedVerticalScrollBarVisibility;
@property (readonly) double viewportHeight;
@property (readonly) double viewportWidth;
@property (readonly) float zoomFactor;
@property (readonly) id<NSFastEnumeration> /*Single*/ zoomSnapPoints;
@property (readonly) double horizontalOffset;
@property (copy) WXUIElement* topHeader;
@property (copy) WXUIElement* leftHeader;
@property (copy) WXUIElement* topLeftHeader;
+ (WXDependencyProperty*)leftHeaderProperty;
+ (WXDependencyProperty*)topHeaderProperty;
+ (WXDependencyProperty*)topLeftHeaderProperty;
+ (WXDependencyProperty*)horizontalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)verticalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)bringIntoViewOnFocusChangeProperty;
+ (WXDependencyProperty*)computedHorizontalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)computedVerticalScrollBarVisibilityProperty;
+ (WXDependencyProperty*)extentHeightProperty;
+ (WXDependencyProperty*)extentWidthProperty;
+ (WXDependencyProperty*)horizontalOffsetProperty;
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
+ (WXDependencyProperty*)isZoomInertiaEnabledProperty;
+ (WXDependencyProperty*)maxZoomFactorProperty;
+ (WXDependencyProperty*)minZoomFactorProperty;
+ (WXDependencyProperty*)scrollableHeightProperty;
+ (WXDependencyProperty*)scrollableWidthProperty;
+ (WXDependencyProperty*)verticalOffsetProperty;
+ (WXDependencyProperty*)verticalScrollModeProperty;
+ (WXDependencyProperty*)verticalSnapPointsAlignmentProperty;
+ (WXDependencyProperty*)verticalSnapPointsTypeProperty;
+ (WXDependencyProperty*)viewportHeightProperty;
+ (WXDependencyProperty*)viewportWidthProperty;
+ (WXDependencyProperty*)zoomFactorProperty;
+ (WXDependencyProperty*)zoomModeProperty;
+ (WXDependencyProperty*)zoomSnapPointsProperty;
+ (WXDependencyProperty*)zoomSnapPointsTypeProperty;
- (EventRegistrationToken)addViewChangedEvent:(void (^)(RTObject*, WXCScrollViewerViewChangedEventArgs*))del;
- (void)removeViewChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addViewChangingEvent:(void (^)(RTObject*, WXCScrollViewerViewChangingEventArgs*))del;
- (void)removeViewChangingEvent:(EventRegistrationToken)tok;
- (void)scrollToHorizontalOffset:(double)offset;
- (void)scrollToVerticalOffset:(double)offset;
- (void)zoomToFactor:(float)factor;
- (void)invalidateScrollInfo;
- (BOOL)changeView:(NSNumber*)horizontalOffset verticalOffset:(NSNumber*)verticalOffset zoomFactor:(NSNumber*)zoomFactor;
- (BOOL)changeViewWithOptionalAnimation:(NSNumber*)horizontalOffset
                         verticalOffset:(NSNumber*)verticalOffset
                             zoomFactor:(NSNumber*)zoomFactor
                       disableAnimation:(BOOL)disableAnimation;
@end

#endif // __WXCScrollViewer_DEFINED__

// Windows.UI.Xaml.Controls.SettingsFlyout
#ifndef __WXCSettingsFlyout_DEFINED__
#define __WXCSettingsFlyout_DEFINED__

WINRT_EXPORT
@interface WXCSettingsFlyout : WXCContentControl
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* title;
@property (copy) WUXMImageSource* iconSource;
@property (copy) WUXMBrush* headerForeground;
@property (copy) WUXMBrush* headerBackground;
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

// Windows.UI.Xaml.Controls.TextBox
#ifndef __WXCTextBox_DEFINED__
#define __WXCTextBox_DEFINED__

WINRT_EXPORT
@interface WXCTextBox : WXCControl
+ (instancetype)create ACTIVATOR;
@property int selectionStart;
@property int selectionLength;
@property (copy) NSString* selectedText;
@property int maxLength;
@property BOOL isTextPredictionEnabled;
@property BOOL isSpellCheckEnabled;
@property BOOL isReadOnly;
@property (copy) WUXIInputScope* inputScope;
@property BOOL acceptsReturn;
@property WXTextWrapping textWrapping;
@property WXTextAlignment textAlignment;
@property (copy) NSString* text;
@property (copy) WUXMSolidColorBrush* selectionHighlightColor;
@property BOOL preventKeyboardDisplayOnProgrammaticFocus;
@property (copy) NSString* placeholderText;
@property BOOL isColorFontEnabled;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isColorFontEnabledProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)preventKeyboardDisplayOnProgrammaticFocusProperty;
+ (WXDependencyProperty*)selectionHighlightColorProperty;
+ (WXDependencyProperty*)acceptsReturnProperty;
+ (WXDependencyProperty*)inputScopeProperty;
+ (WXDependencyProperty*)isReadOnlyProperty;
+ (WXDependencyProperty*)isSpellCheckEnabledProperty;
+ (WXDependencyProperty*)isTextPredictionEnabledProperty;
+ (WXDependencyProperty*)maxLengthProperty;
+ (WXDependencyProperty*)textAlignmentProperty;
+ (WXDependencyProperty*)textProperty;
+ (WXDependencyProperty*)textWrappingProperty;
- (EventRegistrationToken)addContextMenuOpeningEvent:(WXCContextMenuOpeningEventHandler)del;
- (void)removeContextMenuOpeningEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionChangedEvent:(WXRoutedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextChangedEvent:(WXCTextChangedEventHandler)del;
- (void)removeTextChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPasteEvent:(WXCTextControlPasteEventHandler)del;
- (void)removePasteEvent:(EventRegistrationToken)tok;
- (void)select:(int)start length:(int)length;
- (void)selectAll;
- (WFRect*)getRectFromCharacterIndex:(int)charIndex trailingEdge:(BOOL)trailingEdge;
@end

#endif // __WXCTextBox_DEFINED__

// Windows.UI.Xaml.Controls.ToggleSwitch
#ifndef __WXCToggleSwitch_DEFINED__
#define __WXCToggleSwitch_DEFINED__

WINRT_EXPORT
@interface WXCToggleSwitch : WXCControl
+ (instancetype)create ACTIVATOR;
@property (copy) WXDataTemplate* onContentTemplate;
@property (copy) RTObject* onContent;
@property (copy) WXDataTemplate* offContentTemplate;
@property (copy) RTObject* offContent;
@property BOOL isOn;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
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

// Windows.UI.Xaml.Controls.ToolTip
#ifndef __WXCToolTip_DEFINED__
#define __WXCToolTip_DEFINED__

WINRT_EXPORT
@interface WXCToolTip : WXCContentControl
+ (instancetype)create ACTIVATOR;
@property double verticalOffset;
@property (copy) WXUIElement* placementTarget;
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

// Windows.UI.Xaml.Controls.UserControl
#ifndef __WXCUserControl_DEFINED__
#define __WXCUserControl_DEFINED__

WINRT_EXPORT
@interface WXCUserControl : WXCControl
+ (instancetype)create ACTIVATOR;
@property (copy) WXUIElement* content;
+ (WXDependencyProperty*)contentProperty;
@end

#endif // __WXCUserControl_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ButtonBase
#ifndef __WUXCPButtonBase_DEFINED__
#define __WUXCPButtonBase_DEFINED__

WINRT_EXPORT
@interface WUXCPButtonBase : WXCContentControl
+ (instancetype)create ACTIVATOR;
@property (copy) RTObject* commandParameter;
@property (copy) RTObject<WUXIICommand>* command;
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

WINRT_EXPORT
@interface WXCButton : WUXCPButtonBase
+ (instancetype)create ACTIVATOR;
@property (copy) WUXCPFlyoutBase* flyout;
+ (WXDependencyProperty*)flyoutProperty;
@end

#endif // __WXCButton_DEFINED__

// Windows.UI.Xaml.Controls.HyperlinkButton
#ifndef __WXCHyperlinkButton_DEFINED__
#define __WXCHyperlinkButton_DEFINED__

WINRT_EXPORT
@interface WXCHyperlinkButton : WUXCPButtonBase
+ (instancetype)create ACTIVATOR;
@property (copy) WFUri* navigateUri;
+ (WXDependencyProperty*)navigateUriProperty;
@end

#endif // __WXCHyperlinkButton_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.RangeBase
#ifndef __WUXCPRangeBase_DEFINED__
#define __WUXCPRangeBase_DEFINED__

WINRT_EXPORT
@interface WUXCPRangeBase : WXCControl
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WXCProgressBar : WUXCPRangeBase
+ (instancetype)create ACTIVATOR;
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

WINRT_EXPORT
@interface WXCSlider : WUXCPRangeBase
+ (instancetype)create ACTIVATOR;
@property WUXCPTickPlacement tickPlacement;
@property double tickFrequency;
@property (copy) RTObject<WUXDIValueConverter>* thumbToolTipValueConverter;
@property double stepFrequency;
@property WUXCPSliderSnapsTo snapsTo;
@property WXCOrientation orientation;
@property BOOL isThumbToolTipEnabled;
@property BOOL isDirectionReversed;
@property double intermediateValue;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
+ (WXDependencyProperty*)intermediateValueProperty;
+ (WXDependencyProperty*)isDirectionReversedProperty;
+ (WXDependencyProperty*)isThumbToolTipEnabledProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)snapsToProperty;
+ (WXDependencyProperty*)stepFrequencyProperty;
+ (WXDependencyProperty*)thumbToolTipValueConverterProperty;
+ (WXDependencyProperty*)tickFrequencyProperty;
+ (WXDependencyProperty*)tickPlacementProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
@end

#endif // __WXCSlider_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.Selector
#ifndef __WUXCPSelector_DEFINED__
#define __WUXCPSelector_DEFINED__

WINRT_EXPORT
@interface WUXCPSelector : WXCItemsControl
+ (BOOL)getIsSelectionActive:(WXDependencyObject*)element;
@property (copy) NSString* selectedValuePath;
@property (copy) RTObject* selectedValue;
@property (copy) RTObject* selectedItem;
@property int selectedIndex;
@property (copy) NSNumber* isSynchronizedWithCurrentItem;
+ (WXDependencyProperty*)isSynchronizedWithCurrentItemProperty;
+ (WXDependencyProperty*)selectedIndexProperty;
+ (WXDependencyProperty*)selectedItemProperty;
+ (WXDependencyProperty*)selectedValuePathProperty;
+ (WXDependencyProperty*)selectedValueProperty;
- (EventRegistrationToken)addSelectionChangedEvent:(WXCSelectionChangedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCPSelector_DEFINED__

// Windows.UI.Xaml.Controls.ComboBox
#ifndef __WXCComboBox_DEFINED__
#define __WXCComboBox_DEFINED__

WINRT_EXPORT
@interface WXCComboBox : WUXCPSelector
+ (instancetype)create ACTIVATOR;
@property double maxDropDownHeight;
@property BOOL isDropDownOpen;
@property (readonly) BOOL isEditable;
@property (readonly) BOOL isSelectionBoxHighlighted;
@property (readonly) RTObject* selectionBoxItem;
@property (readonly) WXDataTemplate* selectionBoxItemTemplate;
@property (readonly) WUXCPComboBoxTemplateSettings* templateSettings;
@property (copy) NSString* placeholderText;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)isDropDownOpenProperty;
+ (WXDependencyProperty*)maxDropDownHeightProperty;
- (EventRegistrationToken)addDropDownClosedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeDropDownClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropDownOpenedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeDropDownOpenedEvent:(EventRegistrationToken)tok;
- (void)onDropDownClosed:(RTObject*)e;
- (void)onDropDownOpened:(RTObject*)e;
@end

#endif // __WXCComboBox_DEFINED__

// Windows.UI.Xaml.Controls.ListViewBase
#ifndef __WXCListViewBase_DEFINED__
#define __WXCListViewBase_DEFINED__

WINRT_EXPORT
@interface WXCListViewBase : WUXCPSelector <WXCISemanticZoomInformation>
+ (instancetype)create ACTIVATOR;
@property BOOL showsScrollingPlaceholders;
@property (copy) WUXMATransitionCollection* footerTransitions;
@property (copy) WXDataTemplate* footerTemplate;
@property (copy) RTObject* footer;
@property BOOL isItemClickEnabled;
@property WXCIncrementalLoadingTrigger incrementalLoadingTrigger;
@property double incrementalLoadingThreshold;
@property (copy) WUXMATransitionCollection* headerTransitions;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
@property double dataFetchSize;
@property BOOL canReorderItems;
@property BOOL canDragItems;
@property BOOL isSwipeEnabled;
@property WXCListViewSelectionMode selectionMode;
// Failed to generate property SelectedItems (Cannot marshal contained object of unknown type System.Object)
@property (copy) WXCSemanticZoom* semanticZoomOwner;
@property BOOL isZoomedInView;
@property BOOL isActiveView;
+ (WXDependencyProperty*)footerProperty;
+ (WXDependencyProperty*)footerTemplateProperty;
+ (WXDependencyProperty*)footerTransitionsProperty;
+ (WXDependencyProperty*)showsScrollingPlaceholdersProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)headerTransitionsProperty;
+ (WXDependencyProperty*)incrementalLoadingThresholdProperty;
+ (WXDependencyProperty*)incrementalLoadingTriggerProperty;
+ (WXDependencyProperty*)isActiveViewProperty;
+ (WXDependencyProperty*)isItemClickEnabledProperty;
+ (WXDependencyProperty*)isSwipeEnabledProperty;
+ (WXDependencyProperty*)isZoomedInViewProperty;
+ (WXDependencyProperty*)selectionModeProperty;
+ (WXDependencyProperty*)semanticZoomOwnerProperty;
+ (WXDependencyProperty*)canDragItemsProperty;
+ (WXDependencyProperty*)canReorderItemsProperty;
+ (WXDependencyProperty*)dataFetchSizeProperty;
+ (WXDependencyProperty*)headerProperty;
- (EventRegistrationToken)addDragItemsStartingEvent:(WXCDragItemsStartingEventHandler)del;
- (void)removeDragItemsStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addItemClickEvent:(WXCItemClickEventHandler)del;
- (void)removeItemClickEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addContainerContentChangingEvent:(void (^)(WXCListViewBase*, WXCContainerContentChangingEventArgs*))del;
- (void)removeContainerContentChangingEvent:(EventRegistrationToken)tok;
// Failed to generate member get_SelectedItems (Cannot marshal contained object of unknown type System.Object)
- (void)scrollIntoView:(RTObject*)item;
- (void)selectAll;
- (void)loadMoreItemsAsyncWithSuccess:(void (^)(WUXDLoadMoreItemsResult*))success failure:(void (^)(NSError*))failure;
- (void)scrollIntoViewWithAlignment:(RTObject*)item alignment:(WXCScrollIntoViewAlignment)alignment;
- (void)setDesiredContainerUpdateDuration:(WFTimeSpan*)duration;
- (void)initializeViewChange;
- (void)completeViewChange;
- (void)makeVisible:(WXCSemanticZoomLocation*)item;
- (void)startViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)startViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeFrom:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
- (void)completeViewChangeTo:(WXCSemanticZoomLocation*)source destination:(WXCSemanticZoomLocation*)destination;
@end

#endif // __WXCListViewBase_DEFINED__

// Windows.UI.Xaml.Controls.FlipView
#ifndef __WXCFlipView_DEFINED__
#define __WXCFlipView_DEFINED__

WINRT_EXPORT
@interface WXCFlipView : WUXCPSelector
+ (instancetype)create ACTIVATOR;
@property BOOL useTouchAnimationsForAllNavigation;
+ (WXDependencyProperty*)useTouchAnimationsForAllNavigationProperty;
@end

#endif // __WXCFlipView_DEFINED__

// Windows.UI.Xaml.Controls.GridView
#ifndef __WXCGridView_DEFINED__
#define __WXCGridView_DEFINED__

WINRT_EXPORT
@interface WXCGridView : WXCListViewBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCGridView_DEFINED__

// Windows.UI.Xaml.Controls.ListBox
#ifndef __WXCListBox_DEFINED__
#define __WXCListBox_DEFINED__

WINRT_EXPORT
@interface WXCListBox : WUXCPSelector
+ (instancetype)create ACTIVATOR;
@property WXCSelectionMode selectionMode;
// Failed to generate property SelectedItems (Cannot marshal contained object of unknown type System.Object)
+ (WXDependencyProperty*)selectionModeProperty;
// Failed to generate member get_SelectedItems (Cannot marshal contained object of unknown type System.Object)
- (void)scrollIntoView:(RTObject*)item;
- (void)selectAll;
@end

#endif // __WXCListBox_DEFINED__

// Windows.UI.Xaml.Controls.ListView
#ifndef __WXCListView_DEFINED__
#define __WXCListView_DEFINED__

WINRT_EXPORT
@interface WXCListView : WXCListViewBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCListView_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ToggleButton
#ifndef __WUXCPToggleButton_DEFINED__
#define __WUXCPToggleButton_DEFINED__

WINRT_EXPORT
@interface WUXCPToggleButton : WUXCPButtonBase
+ (instancetype)create ACTIVATOR;
@property BOOL isThreeState;
@property (copy) NSNumber* isChecked;
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

WINRT_EXPORT
@interface WXCCheckBox : WUXCPToggleButton
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCCheckBox_DEFINED__

// Windows.UI.Xaml.Controls.RadioButton
#ifndef __WXCRadioButton_DEFINED__
#define __WXCRadioButton_DEFINED__

WINRT_EXPORT
@interface WXCRadioButton : WUXCPToggleButton
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* groupName;
+ (WXDependencyProperty*)groupNameProperty;
@end

#endif // __WXCRadioButton_DEFINED__

// Windows.UI.Xaml.Controls.AppBar
#ifndef __WXCAppBar_DEFINED__
#define __WXCAppBar_DEFINED__

WINRT_EXPORT
@interface WXCAppBar : WXCContentControl
+ (instancetype)create ACTIVATOR;
@property BOOL isSticky;
@property BOOL isOpen;
+ (WXDependencyProperty*)isOpenProperty;
+ (WXDependencyProperty*)isStickyProperty;
- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
- (void)onClosed:(RTObject*)e;
- (void)onOpened:(RTObject*)e;
@end

#endif // __WXCAppBar_DEFINED__

// Windows.UI.Xaml.Controls.AppBarButton
#ifndef __WXCAppBarButton_DEFINED__
#define __WXCAppBarButton_DEFINED__

WINRT_EXPORT
@interface WXCAppBarButton : WXCButton <WXCICommandBarElement>
+ (instancetype)create ACTIVATOR;
@property BOOL isCompact;
@property (copy) NSString* label;
@property (copy) WXCIconElement* icon;
+ (WXDependencyProperty*)iconProperty;
+ (WXDependencyProperty*)isCompactProperty;
+ (WXDependencyProperty*)labelProperty;
@end

#endif // __WXCAppBarButton_DEFINED__

// Windows.UI.Xaml.Controls.AppBarSeparator
#ifndef __WXCAppBarSeparator_DEFINED__
#define __WXCAppBarSeparator_DEFINED__

WINRT_EXPORT
@interface WXCAppBarSeparator : WXCControl <WXCICommandBarElement>
+ (instancetype)create ACTIVATOR;
@property BOOL isCompact;
+ (WXDependencyProperty*)isCompactProperty;
@end

#endif // __WXCAppBarSeparator_DEFINED__

// Windows.UI.Xaml.Controls.AppBarToggleButton
#ifndef __WXCAppBarToggleButton_DEFINED__
#define __WXCAppBarToggleButton_DEFINED__

WINRT_EXPORT
@interface WXCAppBarToggleButton : WUXCPToggleButton <WXCICommandBarElement>
+ (instancetype)create ACTIVATOR;
@property BOOL isCompact;
@property (copy) NSString* label;
@property (copy) WXCIconElement* icon;
+ (WXDependencyProperty*)iconProperty;
+ (WXDependencyProperty*)isCompactProperty;
+ (WXDependencyProperty*)labelProperty;
@end

#endif // __WXCAppBarToggleButton_DEFINED__

// Windows.UI.Xaml.Controls.CommandBar
#ifndef __WXCCommandBar_DEFINED__
#define __WXCCommandBar_DEFINED__

WINRT_EXPORT
@interface WXCCommandBar : WXCAppBar
+ (instancetype)create ACTIVATOR;
// Failed to generate property PrimaryCommands (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.UI.Xaml.Controls.ICommandBarElement>)
// Failed to generate property SecondaryCommands (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.UI.Xaml.Controls.ICommandBarElement>)
+ (WXDependencyProperty*)primaryCommandsProperty;
+ (WXDependencyProperty*)secondaryCommandsProperty;
// Failed to generate member get_PrimaryCommands (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.UI.Xaml.Controls.ICommandBarElement>)
// Failed to generate member get_SecondaryCommands (Can't marshal
// Windows.Foundation.Collections.IObservableVector`1<Windows.UI.Xaml.Controls.ICommandBarElement>)
@end

#endif // __WXCCommandBar_DEFINED__

// Windows.UI.Xaml.Controls.FlyoutPresenter
#ifndef __WXCFlyoutPresenter_DEFINED__
#define __WXCFlyoutPresenter_DEFINED__

WINRT_EXPORT
@interface WXCFlyoutPresenter : WXCContentControl
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.Frame
#ifndef __WXCFrame_DEFINED__
#define __WXCFrame_DEFINED__

WINRT_EXPORT
@interface WXCFrame : WXCContentControl <WXCINavigate>
+ (instancetype)create ACTIVATOR;
@property (readonly) id<NSFastEnumeration> /*WUXNPageStackEntry*/ backStack;
@property (readonly) id<NSFastEnumeration> /*WUXNPageStackEntry*/ forwardStack;
@property (copy) WUXITypeName* sourcePageType;
@property int cacheSize;
@property (readonly) int backStackDepth;
@property (readonly) BOOL canGoBack;
@property (readonly) BOOL canGoForward;
@property (readonly) WUXITypeName* currentSourcePageType;
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
- (NSString*)getNavigationState;
- (void)setNavigationState:(NSString*)navigationState;
- (BOOL)navigate:(WUXITypeName*)sourcePageType parameter:(RTObject*)parameter infoOverride:(WUXMANavigationTransitionInfo*)infoOverride;
- (BOOL)navigate:(WUXITypeName*)sourcePageType;
@end

#endif // __WXCFrame_DEFINED__

// Windows.UI.Xaml.Controls.HubSection
#ifndef __WXCHubSection_DEFINED__
#define __WXCHubSection_DEFINED__

WINRT_EXPORT
@interface WXCHubSection : WXCControl
+ (instancetype)create ACTIVATOR;
@property BOOL isHeaderInteractive;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
@property (copy) WXDataTemplate* contentTemplate;
+ (WXDependencyProperty*)contentTemplateProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)isHeaderInteractiveProperty;
@end

#endif // __WXCHubSection_DEFINED__

// Windows.UI.Xaml.Controls.Hub
#ifndef __WXCHub_DEFINED__
#define __WXCHub_DEFINED__

WINRT_EXPORT
@interface WXCHub : WXCControl <WXCISemanticZoomInformation>
+ (instancetype)create ACTIVATOR;
@property WXCOrientation orientation;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
@property int defaultSectionIndex;
// Failed to generate property SectionHeaders (Can't marshal Windows.Foundation.Collections.IObservableVector`1<System.Object>)
@property (readonly) id<NSFastEnumeration> /*WXCHubSection*/ sections;
@property (readonly) id<NSFastEnumeration> /*WXCHubSection*/ sectionsInView;
@property (copy) WXCSemanticZoom* semanticZoomOwner;
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
// Failed to generate member get_SectionHeaders (Can't marshal Windows.Foundation.Collections.IObservableVector`1<System.Object>)
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

// Windows.UI.Xaml.Controls.ListViewBaseHeaderItem
#ifndef __WXCListViewBaseHeaderItem_DEFINED__
#define __WXCListViewBaseHeaderItem_DEFINED__

WINRT_EXPORT
@interface WXCListViewBaseHeaderItem : WXCContentControl
@end

#endif // __WXCListViewBaseHeaderItem_DEFINED__

// Windows.UI.Xaml.Controls.GridViewHeaderItem
#ifndef __WXCGridViewHeaderItem_DEFINED__
#define __WXCGridViewHeaderItem_DEFINED__

WINRT_EXPORT
@interface WXCGridViewHeaderItem : WXCListViewBaseHeaderItem
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCGridViewHeaderItem_DEFINED__

// Windows.UI.Xaml.Controls.ListViewHeaderItem
#ifndef __WXCListViewHeaderItem_DEFINED__
#define __WXCListViewHeaderItem_DEFINED__

WINRT_EXPORT
@interface WXCListViewHeaderItem : WXCListViewBaseHeaderItem
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCListViewHeaderItem_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutItemBase
#ifndef __WXCMenuFlyoutItemBase_DEFINED__
#define __WXCMenuFlyoutItemBase_DEFINED__

WINRT_EXPORT
@interface WXCMenuFlyoutItemBase : WXCControl
@end

#endif // __WXCMenuFlyoutItemBase_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutItem
#ifndef __WXCMenuFlyoutItem_DEFINED__
#define __WXCMenuFlyoutItem_DEFINED__

WINRT_EXPORT
@interface WXCMenuFlyoutItem : WXCMenuFlyoutItemBase
+ (instancetype)create ACTIVATOR;
@property (copy) NSString* text;
@property (copy) RTObject* commandParameter;
@property (copy) RTObject<WUXIICommand>* command;
+ (WXDependencyProperty*)commandParameterProperty;
+ (WXDependencyProperty*)commandProperty;
+ (WXDependencyProperty*)textProperty;
- (EventRegistrationToken)addClickEvent:(WXRoutedEventHandler)del;
- (void)removeClickEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCMenuFlyoutItem_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutPresenter
#ifndef __WXCMenuFlyoutPresenter_DEFINED__
#define __WXCMenuFlyoutPresenter_DEFINED__

WINRT_EXPORT
@interface WXCMenuFlyoutPresenter : WXCItemsControl
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCMenuFlyoutPresenter_DEFINED__

// Windows.UI.Xaml.Controls.MenuFlyoutSeparator
#ifndef __WXCMenuFlyoutSeparator_DEFINED__
#define __WXCMenuFlyoutSeparator_DEFINED__

WINRT_EXPORT
@interface WXCMenuFlyoutSeparator : WXCMenuFlyoutItemBase
+ (instancetype)create ACTIVATOR;
@end

#endif // __WXCMenuFlyoutSeparator_DEFINED__

// Windows.UI.Xaml.Controls.Page
#ifndef __WXCPage_DEFINED__
#define __WXCPage_DEFINED__

WINRT_EXPORT
@interface WXCPage : WXCUserControl
+ (instancetype)create ACTIVATOR;
@property (copy) WXCAppBar* topAppBar;
@property WUXNNavigationCacheMode navigationCacheMode;
@property (copy) WXCAppBar* bottomAppBar;
@property (readonly) WXCFrame* frame;
+ (WXDependencyProperty*)bottomAppBarProperty;
+ (WXDependencyProperty*)frameProperty;
+ (WXDependencyProperty*)topAppBarProperty;
- (void)onNavigatedFrom:(WUXNNavigationEventArgs*)e;
- (void)onNavigatedTo:(WUXNNavigationEventArgs*)e;
- (void)onNavigatingFrom:(WUXNNavigatingCancelEventArgs*)e;
@end

#endif // __WXCPage_DEFINED__

// Windows.UI.Xaml.Controls.SearchBox
#ifndef __WXCSearchBox_DEFINED__
#define __WXCSearchBox_DEFINED__

WINRT_EXPORT
@interface WXCSearchBox : WXCControl
+ (instancetype)create ACTIVATOR;
@property BOOL searchHistoryEnabled;
@property (copy) NSString* searchHistoryContext;
@property (copy) NSString* queryText;
@property (copy) NSString* placeholderText;
@property BOOL focusOnKeyboardInput;
@property BOOL chooseSuggestionOnEnter;
+ (WXDependencyProperty*)chooseSuggestionOnEnterProperty;
+ (WXDependencyProperty*)focusOnKeyboardInputProperty;
+ (WXDependencyProperty*)placeholderTextProperty;
+ (WXDependencyProperty*)queryTextProperty;
+ (WXDependencyProperty*)searchHistoryContextProperty;
+ (WXDependencyProperty*)searchHistoryEnabledProperty;
- (EventRegistrationToken)addPrepareForFocusOnKeyboardInputEvent:(void (^)(WXCSearchBox*, WXRoutedEventArgs*))del;
- (void)removePrepareForFocusOnKeyboardInputEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQueryChangedEvent:(void (^)(WXCSearchBox*, WXCSearchBoxQueryChangedEventArgs*))del;
- (void)removeQueryChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addQuerySubmittedEvent:(void (^)(WXCSearchBox*, WXCSearchBoxQuerySubmittedEventArgs*))del;
- (void)removeQuerySubmittedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addResultSuggestionChosenEvent:(void (^)(WXCSearchBox*, WXCSearchBoxResultSuggestionChosenEventArgs*))del;
- (void)removeResultSuggestionChosenEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSuggestionsRequestedEvent:(void (^)(WXCSearchBox*, WXCSearchBoxSuggestionsRequestedEventArgs*))del;
- (void)removeSuggestionsRequestedEvent:(EventRegistrationToken)tok;
- (void)setLocalContentSuggestionSettings:(WASLocalContentSuggestionSettings*)settings;
@end

#endif // __WXCSearchBox_DEFINED__

// Windows.UI.Xaml.Controls.TimePicker
#ifndef __WXCTimePicker_DEFINED__
#define __WXCTimePicker_DEFINED__

WINRT_EXPORT
@interface WXCTimePicker : WXCControl
+ (instancetype)create ACTIVATOR;
@property (copy) WFTimeSpan* time;
@property int minuteIncrement;
@property (copy) WXDataTemplate* headerTemplate;
@property (copy) RTObject* header;
@property (copy) NSString* clockIdentifier;
+ (WXDependencyProperty*)clockIdentifierProperty;
+ (WXDependencyProperty*)headerProperty;
+ (WXDependencyProperty*)headerTemplateProperty;
+ (WXDependencyProperty*)minuteIncrementProperty;
+ (WXDependencyProperty*)timeProperty;
- (EventRegistrationToken)addTimeChangedEvent:(void (^)(RTObject*, WXCTimePickerValueChangedEventArgs*))del;
- (void)removeTimeChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WXCTimePicker_DEFINED__

// Windows.UI.Xaml.Controls.ToggleMenuFlyoutItem
#ifndef __WXCToggleMenuFlyoutItem_DEFINED__
#define __WXCToggleMenuFlyoutItem_DEFINED__

WINRT_EXPORT
@interface WXCToggleMenuFlyoutItem : WXCMenuFlyoutItem
+ (instancetype)create ACTIVATOR;
@property BOOL isChecked;
+ (WXDependencyProperty*)isCheckedProperty;
@end

#endif // __WXCToggleMenuFlyoutItem_DEFINED__

// Windows.UI.Xaml.Controls.ControlTemplate
#ifndef __WXCControlTemplate_DEFINED__
#define __WXCControlTemplate_DEFINED__

WINRT_EXPORT
@interface WXCControlTemplate : WXFrameworkTemplate
+ (instancetype)create ACTIVATOR;
@property (copy) WUXITypeName* targetType;
@end

#endif // __WXCControlTemplate_DEFINED__
