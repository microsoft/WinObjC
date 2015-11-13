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

// WindowsUIXamlControlsPrimitives.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUXCPItemsChangedEventArgs, WUXCPLayoutInformation, WUXCPGeneratorPositionHelper, WUXCPProgressRingTemplateSettings,
    WUXCPToggleSwitchTemplateSettings, WUXCPProgressBarTemplateSettings, WUXCPSettingsFlyoutTemplateSettings, WUXCPToolTipTemplateSettings,
    WUXCPFlyoutBase, WUXCPComboBoxTemplateSettings, WUXCPGridViewItemTemplateSettings, WUXCPListViewItemTemplateSettings,
    WUXCPCalendarViewTemplateSettings, WUXCPSplitViewTemplateSettings, WUXCPAppBarTemplateSettings, WUXCPCommandBarTemplateSettings,
    WUXCPDragCompletedEventArgs, WUXCPDragDeltaEventArgs, WUXCPDragStartedEventArgs, WUXCPRangeBaseValueChangedEventArgs,
    WUXCPScrollEventArgs, WUXCPPopup, WUXCPTickBar, WUXCPCarouselPanel, WUXCPOrientedVirtualizingPanel, WUXCPCalendarPanel,
    WUXCPGridViewItemPresenter, WUXCPListViewItemPresenter, WUXCPSelectorItem, WUXCPRangeBase, WUXCPThumb, WUXCPButtonBase, WUXCPScrollBar,
    WUXCPSelector, WUXCPRepeatButton, WUXCPToggleButton, WUXCPJumpListItemBackgroundConverter, WUXCPJumpListItemForegroundConverter,
    WUXCPPickerFlyoutBase, WUXCPLoopingSelector, WUXCPPivotPanel, WUXCPLoopingSelectorItem, WUXCPLoopingSelectorPanel, WUXCPPivotHeaderItem,
    WUXCPPivotHeaderPanel;
@class WUXCPGeneratorPosition;
@protocol WUXCPIScrollSnapPointsInfo
, WUXCPIItemsChangedEventArgs, WUXCPILayoutInformation, WUXCPILayoutInformationStatics, WUXCPIComboBoxTemplateSettings,
    WUXCPIDragCompletedEventArgs, WUXCPIDragCompletedEventArgsFactory, WUXCPIDragDeltaEventArgs, WUXCPIDragDeltaEventArgsFactory,
    WUXCPIDragStartedEventArgs, WUXCPIDragStartedEventArgsFactory, WUXCPIFlyoutBase, WUXCPIFlyoutBaseOverrides, WUXCPIFlyoutBaseStatics,
    WUXCPIFlyoutBaseFactory, WUXCPIGridViewItemTemplateSettings, WUXCPIListViewItemTemplateSettings, WUXCPIProgressBarTemplateSettings,
    WUXCPIProgressRingTemplateSettings, WUXCPIRangeBaseValueChangedEventArgs, WUXCPIScrollEventArgs, WUXCPISettingsFlyoutTemplateSettings,
    WUXCPIToggleSwitchTemplateSettings, WUXCPIToolTipTemplateSettings, WUXCPIPopup, WUXCPIPopupStatics, WUXCPITickBar, WUXCPITickBarStatics,
    WUXCPIRangeBase, WUXCPIRangeBaseOverrides, WUXCPIRangeBaseStatics, WUXCPIRangeBaseFactory, WUXCPIThumb, WUXCPIThumbStatics,
    WUXCPIButtonBase, WUXCPIButtonBaseStatics, WUXCPIButtonBaseFactory, WUXCPICarouselPanel, WUXCPICarouselPanelFactory,
    WUXCPIOrientedVirtualizingPanel, WUXCPIOrientedVirtualizingPanelFactory, WUXCPIScrollBar, WUXCPIScrollBarStatics, WUXCPISelector,
    WUXCPISelectorStatics, WUXCPISelectorFactory, WUXCPISelectorItem, WUXCPISelectorItemStatics, WUXCPISelectorItemFactory,
    WUXCPIRepeatButton, WUXCPIRepeatButtonStatics, WUXCPIToggleButton, WUXCPIToggleButtonOverrides, WUXCPIToggleButtonStatics,
    WUXCPIToggleButtonFactory, WUXCPIAppBarTemplateSettings, WUXCPICalendarViewTemplateSettings, WUXCPICommandBarTemplateSettings,
    WUXCPISplitViewTemplateSettings, WUXCPICalendarPanel, WUXCPIGridViewItemPresenter, WUXCPIGridViewItemPresenterStatics,
    WUXCPIGridViewItemPresenterFactory, WUXCPIListViewItemPresenter, WUXCPIListViewItemPresenterStatics, WUXCPIListViewItemPresenterFactory,
    WUXCPIListViewItemPresenter2, WUXCPIListViewItemPresenterStatics2, WUXCPIGeneratorPositionHelper, WUXCPIGeneratorPositionHelperStatics,
    WUXCPIJumpListItemBackgroundConverter, WUXCPIJumpListItemBackgroundConverterStatics, WUXCPIJumpListItemForegroundConverter,
    WUXCPIJumpListItemForegroundConverterStatics, WUXCPIPickerFlyoutBase, WUXCPIPickerFlyoutBaseOverrides, WUXCPIPickerFlyoutBaseStatics,
    WUXCPIPickerFlyoutBaseFactory, WUXCPILoopingSelector, WUXCPILoopingSelectorStatics, WUXCPIPivotPanel, WUXCPILoopingSelectorItem,
    WUXCPILoopingSelectorPanel, WUXCPIPivotHeaderItem, WUXCPIPivotHeaderItemFactory, WUXCPIPivotHeaderPanel;

// Windows.UI.Xaml.Controls.Primitives.GeneratorDirection
enum _WUXCPGeneratorDirection {
    WUXCPGeneratorDirectionForward = 0,
    WUXCPGeneratorDirectionBackward = 1,
};
typedef unsigned WUXCPGeneratorDirection;

// Windows.UI.Xaml.Controls.Primitives.GroupHeaderPlacement
enum _WUXCPGroupHeaderPlacement {
    WUXCPGroupHeaderPlacementTop = 0,
    WUXCPGroupHeaderPlacementLeft = 1,
};
typedef unsigned WUXCPGroupHeaderPlacement;

// Windows.UI.Xaml.Controls.Primitives.PlacementMode
enum _WUXCPPlacementMode {
    WUXCPPlacementModeBottom = 2,
    WUXCPPlacementModeLeft = 9,
    WUXCPPlacementModeMouse = 7,
    WUXCPPlacementModeRight = 4,
    WUXCPPlacementModeTop = 10,
};
typedef unsigned WUXCPPlacementMode;

// Windows.UI.Xaml.Controls.Primitives.ScrollEventType
enum _WUXCPScrollEventType {
    WUXCPScrollEventTypeSmallDecrement = 0,
    WUXCPScrollEventTypeSmallIncrement = 1,
    WUXCPScrollEventTypeLargeDecrement = 2,
    WUXCPScrollEventTypeLargeIncrement = 3,
    WUXCPScrollEventTypeThumbPosition = 4,
    WUXCPScrollEventTypeThumbTrack = 5,
    WUXCPScrollEventTypeFirst = 6,
    WUXCPScrollEventTypeLast = 7,
    WUXCPScrollEventTypeEndScroll = 8,
};
typedef unsigned WUXCPScrollEventType;

// Windows.UI.Xaml.Controls.Primitives.ScrollingIndicatorMode
enum _WUXCPScrollingIndicatorMode {
    WUXCPScrollingIndicatorModeNone = 0,
    WUXCPScrollingIndicatorModeTouchIndicator = 1,
    WUXCPScrollingIndicatorModeMouseIndicator = 2,
};
typedef unsigned WUXCPScrollingIndicatorMode;

// Windows.UI.Xaml.Controls.Primitives.SliderSnapsTo
enum _WUXCPSliderSnapsTo {
    WUXCPSliderSnapsToStepValues = 0,
    WUXCPSliderSnapsToTicks = 1,
};
typedef unsigned WUXCPSliderSnapsTo;

// Windows.UI.Xaml.Controls.Primitives.SnapPointsAlignment
enum _WUXCPSnapPointsAlignment {
    WUXCPSnapPointsAlignmentNear = 0,
    WUXCPSnapPointsAlignmentCenter = 1,
    WUXCPSnapPointsAlignmentFar = 2,
};
typedef unsigned WUXCPSnapPointsAlignment;

// Windows.UI.Xaml.Controls.Primitives.TickPlacement
enum _WUXCPTickPlacement {
    WUXCPTickPlacementNone = 0,
    WUXCPTickPlacementTopLeft = 1,
    WUXCPTickPlacementBottomRight = 2,
    WUXCPTickPlacementOutside = 3,
    WUXCPTickPlacementInline = 4,
};
typedef unsigned WUXCPTickPlacement;

// Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenterCheckMode
enum _WUXCPListViewItemPresenterCheckMode {
    WUXCPListViewItemPresenterCheckModeInline = 0,
    WUXCPListViewItemPresenterCheckModeOverlay = 1,
};
typedef unsigned WUXCPListViewItemPresenterCheckMode;

// Windows.UI.Xaml.Controls.Primitives.AnimationDirection
enum _WUXCPAnimationDirection {
    WUXCPAnimationDirectionLeft = 0,
    WUXCPAnimationDirectionTop = 1,
    WUXCPAnimationDirectionRight = 2,
    WUXCPAnimationDirectionBottom = 3,
};
typedef unsigned WUXCPAnimationDirection;

// Windows.UI.Xaml.Controls.Primitives.ComponentResourceLocation
enum _WUXCPComponentResourceLocation {
    WUXCPComponentResourceLocationApplication = 0,
    WUXCPComponentResourceLocationNested = 1,
};
typedef unsigned WUXCPComponentResourceLocation;

// Windows.UI.Xaml.Controls.Primitives.EdgeTransitionLocation
enum _WUXCPEdgeTransitionLocation {
    WUXCPEdgeTransitionLocationLeft = 0,
    WUXCPEdgeTransitionLocationTop = 1,
    WUXCPEdgeTransitionLocationRight = 2,
    WUXCPEdgeTransitionLocationBottom = 3,
};
typedef unsigned WUXCPEdgeTransitionLocation;

// Windows.UI.Xaml.Controls.Primitives.FlyoutPlacementMode
enum _WUXCPFlyoutPlacementMode {
    WUXCPFlyoutPlacementModeTop = 0,
    WUXCPFlyoutPlacementModeBottom = 1,
    WUXCPFlyoutPlacementModeLeft = 2,
    WUXCPFlyoutPlacementModeRight = 3,
    WUXCPFlyoutPlacementModeFull = 4,
};
typedef unsigned WUXCPFlyoutPlacementMode;

#include "WindowsUIXamlData.h"
#include "WindowsFoundation.h"
#include "WindowsUIXamlControls.h"
#include "WindowsFoundationCollections.h"
#include "WindowsUIXamlMediaAnimation.h"
#include "WindowsApplicationModelDataTransfer.h"
#include "WindowsUIXamlMedia.h"
#include "WindowsUIXamlInput.h"
#include "WindowsUIXaml.h"
#include "WindowsUICore.h"
#include "WindowsUIInput.h"
#include "WindowsUIXamlAutomationPeers.h"
#include "WindowsUIXamlMediaMedia3D.h"
#include "WindowsUIText.h"
#include "WindowsUIXamlInterop.h"
// Windows.UI.Xaml.Controls.Primitives.DragCompletedEventHandler
#ifndef __WUXCPDragCompletedEventHandler__DEFINED
#define __WUXCPDragCompletedEventHandler__DEFINED
typedef void (^WUXCPDragCompletedEventHandler)(RTObject* sender, WUXCPDragCompletedEventArgs* e);
#endif // __WUXCPDragCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.DragDeltaEventHandler
#ifndef __WUXCPDragDeltaEventHandler__DEFINED
#define __WUXCPDragDeltaEventHandler__DEFINED
typedef void (^WUXCPDragDeltaEventHandler)(RTObject* sender, WUXCPDragDeltaEventArgs* e);
#endif // __WUXCPDragDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.DragStartedEventHandler
#ifndef __WUXCPDragStartedEventHandler__DEFINED
#define __WUXCPDragStartedEventHandler__DEFINED
typedef void (^WUXCPDragStartedEventHandler)(RTObject* sender, WUXCPDragStartedEventArgs* e);
#endif // __WUXCPDragStartedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.RangeBaseValueChangedEventHandler
#ifndef __WUXCPRangeBaseValueChangedEventHandler__DEFINED
#define __WUXCPRangeBaseValueChangedEventHandler__DEFINED
typedef void (^WUXCPRangeBaseValueChangedEventHandler)(RTObject* sender, WUXCPRangeBaseValueChangedEventArgs* e);
#endif // __WUXCPRangeBaseValueChangedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.ScrollEventHandler
#ifndef __WUXCPScrollEventHandler__DEFINED
#define __WUXCPScrollEventHandler__DEFINED
typedef void (^WUXCPScrollEventHandler)(RTObject* sender, WUXCPScrollEventArgs* e);
#endif // __WUXCPScrollEventHandler__DEFINED

// Windows.UI.Xaml.Controls.SelectionChangedEventHandler
#ifndef __WXCSelectionChangedEventHandler__DEFINED
#define __WXCSelectionChangedEventHandler__DEFINED
typedef void (^WXCSelectionChangedEventHandler)(RTObject* sender, WXCSelectionChangedEventArgs* e);
#endif // __WXCSelectionChangedEventHandler__DEFINED

// Windows.UI.Xaml.DependencyPropertyChangedCallback
#ifndef __WXDependencyPropertyChangedCallback__DEFINED
#define __WXDependencyPropertyChangedCallback__DEFINED
typedef void (^WXDependencyPropertyChangedCallback)(WXDependencyObject* sender, WXDependencyProperty* dp);
#endif // __WXDependencyPropertyChangedCallback__DEFINED

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

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Xaml.Controls.Primitives.GeneratorPosition
WINRT_EXPORT
@interface WUXCPGeneratorPosition : NSObject
+ (instancetype) new;
@property int index;
@property int offset;
@end

// Windows.UI.Xaml.Controls.Primitives.DragCompletedEventHandler
#ifndef __WUXCPDragCompletedEventHandler__DEFINED
#define __WUXCPDragCompletedEventHandler__DEFINED
typedef void (^WUXCPDragCompletedEventHandler)(RTObject* sender, WUXCPDragCompletedEventArgs* e);
#endif // __WUXCPDragCompletedEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.DragDeltaEventHandler
#ifndef __WUXCPDragDeltaEventHandler__DEFINED
#define __WUXCPDragDeltaEventHandler__DEFINED
typedef void (^WUXCPDragDeltaEventHandler)(RTObject* sender, WUXCPDragDeltaEventArgs* e);
#endif // __WUXCPDragDeltaEventHandler__DEFINED

// Windows.UI.Xaml.Controls.Primitives.DragStartedEventHandler
#ifndef __WUXCPDragStartedEventHandler__DEFINED
#define __WUXCPDragStartedEventHandler__DEFINED
typedef void (^WUXCPDragStartedEventHandler)(RTObject* sender, WUXCPDragStartedEventArgs* e);
#endif // __WUXCPDragStartedEventHandler__DEFINED

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

// Windows.UI.Xaml.Controls.Primitives.ScrollEventHandler
#ifndef __WUXCPScrollEventHandler__DEFINED
#define __WUXCPScrollEventHandler__DEFINED
typedef void (^WUXCPScrollEventHandler)(RTObject* sender, WUXCPScrollEventArgs* e);
#endif // __WUXCPScrollEventHandler__DEFINED

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
- (NSArray*)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WUXCPIScrollSnapPointsInfo_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IFlyoutBaseOverrides
#ifndef __WUXCPIFlyoutBaseOverrides_DEFINED__
#define __WUXCPIFlyoutBaseOverrides_DEFINED__

@protocol WUXCPIFlyoutBaseOverrides
- (WXCControl*)createPresenter;
@end

#endif // __WUXCPIFlyoutBaseOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IRangeBaseOverrides
#ifndef __WUXCPIRangeBaseOverrides_DEFINED__
#define __WUXCPIRangeBaseOverrides_DEFINED__

@protocol WUXCPIRangeBaseOverrides
- (void)onMinimumChanged:(double)oldMinimum newMinimum:(double)newMinimum;
- (void)onMaximumChanged:(double)oldMaximum newMaximum:(double)newMaximum;
- (void)onValueChanged:(double)oldValue newValue:(double)newValue;
@end

#endif // __WUXCPIRangeBaseOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IToggleButtonOverrides
#ifndef __WUXCPIToggleButtonOverrides_DEFINED__
#define __WUXCPIToggleButtonOverrides_DEFINED__

@protocol WUXCPIToggleButtonOverrides
- (void)onToggle;
@end

#endif // __WUXCPIToggleButtonOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.IPickerFlyoutBaseOverrides
#ifndef __WUXCPIPickerFlyoutBaseOverrides_DEFINED__
#define __WUXCPIPickerFlyoutBaseOverrides_DEFINED__

@protocol WUXCPIPickerFlyoutBaseOverrides
- (void)onConfirmed;
- (BOOL)shouldShowConfirmationButtons;
@end

#endif // __WUXCPIPickerFlyoutBaseOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ItemsChangedEventArgs
#ifndef __WUXCPItemsChangedEventArgs_DEFINED__
#define __WUXCPItemsChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCPItemsChangedEventArgs : RTObject
@property (readonly) int action;
@property (readonly) int itemCount;
@property (readonly) int itemUICount;
@property (readonly) WUXCPGeneratorPosition* oldPosition;
@property (readonly) WUXCPGeneratorPosition* position;
@end

#endif // __WUXCPItemsChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.LayoutInformation
#ifndef __WUXCPLayoutInformation_DEFINED__
#define __WUXCPLayoutInformation_DEFINED__

WINRT_EXPORT
@interface WUXCPLayoutInformation : RTObject
+ (WXUIElement*)getLayoutExceptionElement:(RTObject*)dispatcher;
+ (WFRect*)getLayoutSlot:(WXFrameworkElement*)element;
@end

#endif // __WUXCPLayoutInformation_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.GeneratorPositionHelper
#ifndef __WUXCPGeneratorPositionHelper_DEFINED__
#define __WUXCPGeneratorPositionHelper_DEFINED__

WINRT_EXPORT
@interface WUXCPGeneratorPositionHelper : RTObject
+ (WUXCPGeneratorPosition*)fromIndexAndOffset:(int)index offset:(int)offset;
@end

#endif // __WUXCPGeneratorPositionHelper_DEFINED__

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
- (int64_t)registerPropertyChangedCallback:(WXDependencyProperty*)dp callback:(WXDependencyPropertyChangedCallback)callback;
- (void)unregisterPropertyChangedCallback:(WXDependencyProperty*)dp token:(int64_t)token;
@end

#endif // __WXDependencyObject_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ProgressRingTemplateSettings
#ifndef __WUXCPProgressRingTemplateSettings_DEFINED__
#define __WUXCPProgressRingTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPProgressRingTemplateSettings : WXDependencyObject
@property (readonly) double ellipseDiameter;
@property (readonly) WXThickness* ellipseOffset;
@property (readonly) double maxSideLength;
@end

#endif // __WUXCPProgressRingTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ToggleSwitchTemplateSettings
#ifndef __WUXCPToggleSwitchTemplateSettings_DEFINED__
#define __WUXCPToggleSwitchTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPToggleSwitchTemplateSettings : WXDependencyObject
@property (readonly) double curtainCurrentToOffOffset;
@property (readonly) double curtainCurrentToOnOffset;
@property (readonly) double curtainOffToOnOffset;
@property (readonly) double curtainOnToOffOffset;
@property (readonly) double knobCurrentToOffOffset;
@property (readonly) double knobCurrentToOnOffset;
@property (readonly) double knobOffToOnOffset;
@property (readonly) double knobOnToOffOffset;
@end

#endif // __WUXCPToggleSwitchTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ProgressBarTemplateSettings
#ifndef __WUXCPProgressBarTemplateSettings_DEFINED__
#define __WUXCPProgressBarTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPProgressBarTemplateSettings : WXDependencyObject
@property (readonly) double containerAnimationEndPosition;
@property (readonly) double containerAnimationStartPosition;
@property (readonly) double ellipseAnimationEndPosition;
@property (readonly) double ellipseAnimationWellPosition;
@property (readonly) double ellipseDiameter;
@property (readonly) double ellipseOffset;
@property (readonly) double indicatorLengthDelta;
@end

#endif // __WUXCPProgressBarTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.SettingsFlyoutTemplateSettings
#ifndef __WUXCPSettingsFlyoutTemplateSettings_DEFINED__
#define __WUXCPSettingsFlyoutTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPSettingsFlyoutTemplateSettings : WXDependencyObject
@property (readonly) WUXMBrush* borderBrush;
@property (readonly) WXThickness* borderThickness;
@property (readonly) WUXMATransitionCollection* contentTransitions;
@property (readonly) WUXMBrush* headerBackground;
@property (readonly) WUXMBrush* headerForeground;
@property (readonly) WUXMImageSource* iconSource;
@end

#endif // __WUXCPSettingsFlyoutTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ToolTipTemplateSettings
#ifndef __WUXCPToolTipTemplateSettings_DEFINED__
#define __WUXCPToolTipTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPToolTipTemplateSettings : WXDependencyObject
@property (readonly) double fromHorizontalOffset;
@property (readonly) double fromVerticalOffset;
@end

#endif // __WUXCPToolTipTemplateSettings_DEFINED__

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

// Windows.UI.Xaml.Controls.Primitives.ComboBoxTemplateSettings
#ifndef __WUXCPComboBoxTemplateSettings_DEFINED__
#define __WUXCPComboBoxTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPComboBoxTemplateSettings : WXDependencyObject
@property (readonly) double dropDownClosedHeight;
@property (readonly) double dropDownOffset;
@property (readonly) double dropDownOpenedHeight;
@property (readonly) WUXCPAnimationDirection selectedItemDirection;
@end

#endif // __WUXCPComboBoxTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.GridViewItemTemplateSettings
#ifndef __WUXCPGridViewItemTemplateSettings_DEFINED__
#define __WUXCPGridViewItemTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPGridViewItemTemplateSettings : WXDependencyObject
@property (readonly) int dragItemsCount;
@end

#endif // __WUXCPGridViewItemTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ListViewItemTemplateSettings
#ifndef __WUXCPListViewItemTemplateSettings_DEFINED__
#define __WUXCPListViewItemTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPListViewItemTemplateSettings : WXDependencyObject
@property (readonly) int dragItemsCount;
@end

#endif // __WUXCPListViewItemTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.CalendarViewTemplateSettings
#ifndef __WUXCPCalendarViewTemplateSettings_DEFINED__
#define __WUXCPCalendarViewTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPCalendarViewTemplateSettings : WXDependencyObject
@property (readonly) double centerX;
@property (readonly) double centerY;
@property (readonly) WFRect* clipRect;
@property (readonly) BOOL hasMoreContentAfter;
@property (readonly) BOOL hasMoreContentBefore;
@property (readonly) BOOL hasMoreViews;
@property (readonly) NSString* headerText;
@property (readonly) double minViewWidth;
@property (readonly) NSString* weekDay1;
@property (readonly) NSString* weekDay2;
@property (readonly) NSString* weekDay3;
@property (readonly) NSString* weekDay4;
@property (readonly) NSString* weekDay5;
@property (readonly) NSString* weekDay6;
@property (readonly) NSString* weekDay7;
@end

#endif // __WUXCPCalendarViewTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.SplitViewTemplateSettings
#ifndef __WUXCPSplitViewTemplateSettings_DEFINED__
#define __WUXCPSplitViewTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPSplitViewTemplateSettings : WXDependencyObject
@property (readonly) WXGridLength* compactPaneGridLength;
@property (readonly) double negativeOpenPaneLength;
@property (readonly) double negativeOpenPaneLengthMinusCompactLength;
@property (readonly) WXGridLength* openPaneGridLength;
@property (readonly) double openPaneLength;
@property (readonly) double openPaneLengthMinusCompactLength;
@end

#endif // __WUXCPSplitViewTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.AppBarTemplateSettings
#ifndef __WUXCPAppBarTemplateSettings_DEFINED__
#define __WUXCPAppBarTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPAppBarTemplateSettings : WXDependencyObject
@property (readonly) WFRect* clipRect;
@property (readonly) WXThickness* compactRootMargin;
@property (readonly) double compactVerticalDelta;
@property (readonly) WXThickness* hiddenRootMargin;
@property (readonly) double hiddenVerticalDelta;
@property (readonly) WXThickness* minimalRootMargin;
@property (readonly) double minimalVerticalDelta;
@end

#endif // __WUXCPAppBarTemplateSettings_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.CommandBarTemplateSettings
#ifndef __WUXCPCommandBarTemplateSettings_DEFINED__
#define __WUXCPCommandBarTemplateSettings_DEFINED__

WINRT_EXPORT
@interface WUXCPCommandBarTemplateSettings : WXDependencyObject
@property (readonly) double contentHeight;
@property (readonly) double negativeOverflowContentHeight;
@property (readonly) WFRect* overflowContentClipRect;
@property (readonly) double overflowContentHeight;
@property (readonly) double overflowContentHorizontalOffset;
@property (readonly) double overflowContentMaxHeight;
@property (readonly) double overflowContentMinWidth;
@end

#endif // __WUXCPCommandBarTemplateSettings_DEFINED__

// Windows.UI.Xaml.RoutedEventArgs
#ifndef __WXRoutedEventArgs_DEFINED__
#define __WXRoutedEventArgs_DEFINED__

WINRT_EXPORT
@interface WXRoutedEventArgs : RTObject
+ (instancetype)create ACTIVATOR;
@property (readonly) RTObject* originalSource;
@end

#endif // __WXRoutedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.DragCompletedEventArgs
#ifndef __WUXCPDragCompletedEventArgs_DEFINED__
#define __WUXCPDragCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCPDragCompletedEventArgs : WXRoutedEventArgs
@property (readonly) BOOL canceled;
@property (readonly) double horizontalChange;
@property (readonly) double verticalChange;
@end

#endif // __WUXCPDragCompletedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.DragDeltaEventArgs
#ifndef __WUXCPDragDeltaEventArgs_DEFINED__
#define __WUXCPDragDeltaEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCPDragDeltaEventArgs : WXRoutedEventArgs
@property (readonly) double horizontalChange;
@property (readonly) double verticalChange;
@end

#endif // __WUXCPDragDeltaEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.DragStartedEventArgs
#ifndef __WUXCPDragStartedEventArgs_DEFINED__
#define __WUXCPDragStartedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCPDragStartedEventArgs : WXRoutedEventArgs
@property (readonly) double horizontalOffset;
@property (readonly) double verticalOffset;
@end

#endif // __WUXCPDragStartedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.RangeBaseValueChangedEventArgs
#ifndef __WUXCPRangeBaseValueChangedEventArgs_DEFINED__
#define __WUXCPRangeBaseValueChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCPRangeBaseValueChangedEventArgs : WXRoutedEventArgs
@property (readonly) double newValue;
@property (readonly) double oldValue;
@end

#endif // __WUXCPRangeBaseValueChangedEventArgs_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ScrollEventArgs
#ifndef __WUXCPScrollEventArgs_DEFINED__
#define __WUXCPScrollEventArgs_DEFINED__

WINRT_EXPORT
@interface WUXCPScrollEventArgs : WXRoutedEventArgs
+ (instancetype)create ACTIVATOR;
@property (readonly) double newValue;
@property (readonly) WUXCPScrollEventType scrollEventType;
@end

#endif // __WUXCPScrollEventArgs_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides
#ifndef __WXIFrameworkElementOverrides_DEFINED__
#define __WXIFrameworkElementOverrides_DEFINED__

@protocol WXIFrameworkElementOverrides
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
@end

#endif // __WXIFrameworkElementOverrides_DEFINED__

// Windows.UI.Xaml.IFrameworkElementOverrides2
#ifndef __WXIFrameworkElementOverrides2_DEFINED__
#define __WXIFrameworkElementOverrides2_DEFINED__

@protocol WXIFrameworkElementOverrides2
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXIFrameworkElementOverrides2_DEFINED__

// Windows.UI.Xaml.IUIElementOverrides
#ifndef __WXIUIElementOverrides_DEFINED__
#define __WXIUIElementOverrides_DEFINED__

@protocol WXIUIElementOverrides
- (WUXAPAutomationPeer*)onCreateAutomationPeer;
- (void)onDisconnectVisualChildren;
- (id<NSFastEnumeration>)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
@end

#endif // __WXIUIElementOverrides_DEFINED__

// Windows.UI.Xaml.UIElement
#ifndef __WXUIElement_DEFINED__
#define __WXUIElement_DEFINED__

WINRT_EXPORT
@interface WXUIElement : WXDependencyObject
+ (BOOL)tryStartDirectManipulation:(WUXIPointer*)value;
@property BOOL isRightTapEnabled;
@property (copy) WUXMProjection* projection;
@property BOOL allowDrop;
@property BOOL isHitTestVisible;
@property double opacity;
@property (copy) WUXMCacheMode* cacheMode;
@property BOOL isDoubleTapEnabled;
@property BOOL isTapEnabled;
@property WXVisibility visibility;
@property BOOL useLayoutRounding;
@property (copy) WUXMRectangleGeometry* clip;
@property (copy) WUXMATransitionCollection* transitions;
@property (copy) WFPoint* renderTransformOrigin;
@property (copy) WUXMTransform* renderTransform;
@property BOOL isHoldingEnabled;
@property WUXIManipulationModes manipulationMode;
@property (readonly) WFSize* renderSize;
@property (readonly) NSArray* pointerCaptures;
@property (readonly) WFSize* desiredSize;
@property WUXMElementCompositeMode compositeMode;
@property (copy) WUXMMTransform3D* transform3D;
@property BOOL canDrag;
+ (WXRoutedEvent*)dropEvent;
+ (WXDependencyProperty*)allowDropProperty;
+ (WXDependencyProperty*)cacheModeProperty;
+ (WXDependencyProperty*)clipProperty;
+ (WXRoutedEvent*)doubleTappedEvent;
+ (WXRoutedEvent*)dragEnterEvent;
+ (WXRoutedEvent*)dragLeaveEvent;
+ (WXRoutedEvent*)dragOverEvent;
+ (WXRoutedEvent*)pointerCanceledEvent;
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
- (EventRegistrationToken)addDragStartingEvent:(void (^)(WXUIElement*, WXDragStartingEventArgs*))del;
- (void)removeDragStartingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDropCompletedEvent:(void (^)(WXUIElement*, WXDropCompletedEventArgs*))del;
- (void)removeDropCompletedEvent:(EventRegistrationToken)tok;
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
- (id<NSFastEnumeration>)findSubElementsForTouchTargeting:(WFPoint*)point boundingRect:(WFRect*)boundingRect;
- (BOOL)cancelDirectManipulations;
- (void)startDragAsync:(WUIPointerPoint*)pointerPoint
               success:(void (^)(WADDataPackageOperation))success
               failure:(void (^)(NSError*))failure;
@end

#endif // __WXUIElement_DEFINED__

// Windows.UI.Xaml.FrameworkElement
#ifndef __WXFrameworkElement_DEFINED__
#define __WXFrameworkElement_DEFINED__

WINRT_EXPORT
@interface WXFrameworkElement : WXUIElement
+ (instancetype)create ACTIVATOR;
@property (copy) WXThickness* margin;
@property (copy) NSString* language;
@property WXHorizontalAlignment horizontalAlignment;
@property double height;
@property WXFlowDirection flowDirection;
@property (copy) RTObject* dataContext;
@property WXVerticalAlignment verticalAlignment;
@property double maxWidth;
@property double maxHeight;
@property double minHeight;
@property double width;
@property (copy) RTObject* tag;
@property (copy) WXStyle* style;
@property (copy) WXResourceDictionary* resources;
@property (copy) NSString* name;
@property double minWidth;
@property (readonly) double actualWidth;
@property (readonly) WFUri* baseUri;
@property (readonly) WXTriggerCollection* triggers;
@property (readonly) double actualHeight;
@property (readonly) WXDependencyObject* parent;
@property WXElementTheme requestedTheme;
+ (WXDependencyProperty*)flowDirectionProperty;
+ (WXDependencyProperty*)actualHeightProperty;
+ (WXDependencyProperty*)actualWidthProperty;
+ (WXDependencyProperty*)dataContextProperty;
+ (WXDependencyProperty*)maxWidthProperty;
+ (WXDependencyProperty*)heightProperty;
+ (WXDependencyProperty*)horizontalAlignmentProperty;
+ (WXDependencyProperty*)languageProperty;
+ (WXDependencyProperty*)marginProperty;
+ (WXDependencyProperty*)maxHeightProperty;
+ (WXDependencyProperty*)minHeightProperty;
+ (WXDependencyProperty*)minWidthProperty;
+ (WXDependencyProperty*)nameProperty;
+ (WXDependencyProperty*)styleProperty;
+ (WXDependencyProperty*)tagProperty;
+ (WXDependencyProperty*)verticalAlignmentProperty;
+ (WXDependencyProperty*)widthProperty;
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
- (EventRegistrationToken)addLoadingEvent:(void (^)(WXFrameworkElement*, RTObject*))del;
- (void)removeLoadingEvent:(EventRegistrationToken)tok;
- (RTObject*)findName:(NSString*)name;
- (void)setBinding:(WXDependencyProperty*)dp binding:(WUXDBindingBase*)binding;
- (WFSize*)measureOverride:(WFSize*)availableSize;
- (WFSize*)arrangeOverride:(WFSize*)finalSize;
- (void)onApplyTemplate;
- (WUXDBindingExpression*)getBindingExpression:(WXDependencyProperty*)dp;
- (BOOL)goToElementStateCore:(NSString*)stateName useTransitions:(BOOL)useTransitions;
@end

#endif // __WXFrameworkElement_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.Popup
#ifndef __WUXCPPopup_DEFINED__
#define __WUXCPPopup_DEFINED__

WINRT_EXPORT
@interface WUXCPPopup : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property double verticalOffset;
@property BOOL isOpen;
@property BOOL isLightDismissEnabled;
@property double horizontalOffset;
@property (copy) WUXMATransitionCollection* childTransitions;
@property (copy) WXUIElement* child;
+ (WXDependencyProperty*)childProperty;
+ (WXDependencyProperty*)childTransitionsProperty;
+ (WXDependencyProperty*)horizontalOffsetProperty;
+ (WXDependencyProperty*)isLightDismissEnabledProperty;
+ (WXDependencyProperty*)isOpenProperty;
+ (WXDependencyProperty*)verticalOffsetProperty;
- (EventRegistrationToken)addClosedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOpenedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeOpenedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCPPopup_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.TickBar
#ifndef __WUXCPTickBar_DEFINED__
#define __WUXCPTickBar_DEFINED__

WINRT_EXPORT
@interface WUXCPTickBar : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMBrush* fill;
+ (WXDependencyProperty*)fillProperty;
@end

#endif // __WUXCPTickBar_DEFINED__

// Windows.UI.Xaml.Controls.IVirtualizingPanelOverrides
#ifndef __WXCIVirtualizingPanelOverrides_DEFINED__
#define __WXCIVirtualizingPanelOverrides_DEFINED__

@protocol WXCIVirtualizingPanelOverrides
- (void)onItemsChanged:(RTObject*)sender args:(WUXCPItemsChangedEventArgs*)args;
- (void)onClearChildren;
- (void)bringIndexIntoView:(int)index;
@end

#endif // __WXCIVirtualizingPanelOverrides_DEFINED__

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

// Windows.UI.Xaml.Controls.Primitives.CarouselPanel
#ifndef __WUXCPCarouselPanel_DEFINED__
#define __WUXCPCarouselPanel_DEFINED__

WINRT_EXPORT
@interface WUXCPCarouselPanel : WXCVirtualizingPanel <WUXCPIScrollSnapPointsInfo>
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
- (NSArray*)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WUXCPCarouselPanel_DEFINED__

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
- (NSArray*)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WUXCPOrientedVirtualizingPanel_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.CalendarPanel
#ifndef __WUXCPCalendarPanel_DEFINED__
#define __WUXCPCalendarPanel_DEFINED__

WINRT_EXPORT
@interface WUXCPCalendarPanel : WXCPanel
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXCPCalendarPanel_DEFINED__

// Windows.UI.Xaml.Controls.IContentPresenterOverrides
#ifndef __WXCIContentPresenterOverrides_DEFINED__
#define __WXCIContentPresenterOverrides_DEFINED__

@protocol WXCIContentPresenterOverrides
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector
              newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

#endif // __WXCIContentPresenterOverrides_DEFINED__

// Windows.UI.Xaml.Controls.ContentPresenter
#ifndef __WXCContentPresenter_DEFINED__
#define __WXCContentPresenter_DEFINED__

WINRT_EXPORT
@interface WXCContentPresenter : WXFrameworkElement
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMFontFamily* fontFamily;
@property (copy) WUXMATransitionCollection* contentTransitions;
@property (copy) WXCDataTemplateSelector* contentTemplateSelector;
@property (copy) WXDataTemplate* contentTemplate;
@property (copy) RTObject* content;
@property double fontSize;
@property int characterSpacing;
@property (copy) WUXMBrush* foreground;
@property (copy) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property WXOpticalMarginAlignment opticalMarginAlignment;
@property WXTextLineBounds textLineBounds;
@property BOOL isTextScaleFactorEnabled;
@property (copy) WXCornerRadius* cornerRadius;
@property (copy) WXThickness* borderThickness;
@property (copy) WUXMBrush* borderBrush;
@property (copy) WUXMBrush* background;
@property WXHorizontalAlignment horizontalContentAlignment;
@property WXVerticalAlignment verticalContentAlignment;
@property WXTextWrapping textWrapping;
@property (copy) WXThickness* padding;
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
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector
              newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

#endif // __WXCContentPresenter_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.GridViewItemPresenter
#ifndef __WUXCPGridViewItemPresenter_DEFINED__
#define __WUXCPGridViewItemPresenter_DEFINED__

WINRT_EXPORT
@interface WUXCPGridViewItemPresenter : WXCContentPresenter
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMBrush* dragBackground;
@property double disabledOpacity;
@property (copy) WXThickness* contentMargin;
@property (copy) WUXMBrush* selectedPointerOverBackground;
@property (copy) WUXMBrush* checkSelectingBrush;
@property (copy) WUXMBrush* checkHintBrush;
@property (copy) WUXMBrush* checkBrush;
@property (copy) WXThickness* gridViewItemPresenterPadding;
@property WXHorizontalAlignment gridViewItemPresenterHorizontalContentAlignment;
@property (copy) WUXMBrush* focusBorderBrush;
@property double dragOpacity;
@property (copy) WUXMBrush* dragForeground;
@property WXVerticalAlignment gridViewItemPresenterVerticalContentAlignment;
@property BOOL selectionCheckMarkVisualEnabled;
@property (copy) WUXMBrush* selectedPointerOverBorderBrush;
@property (copy) WUXMBrush* selectedForeground;
@property (copy) WXThickness* selectedBorderThickness;
@property (copy) WUXMBrush* selectedBackground;
@property double reorderHintOffset;
@property (copy) WXThickness* pointerOverBackgroundMargin;
@property (copy) WUXMBrush* pointerOverBackground;
@property (copy) WUXMBrush* placeholderBackground;
+ (WXDependencyProperty*)checkBrushProperty;
+ (WXDependencyProperty*)checkHintBrushProperty;
+ (WXDependencyProperty*)checkSelectingBrushProperty;
+ (WXDependencyProperty*)contentMarginProperty;
+ (WXDependencyProperty*)disabledOpacityProperty;
+ (WXDependencyProperty*)dragBackgroundProperty;
+ (WXDependencyProperty*)dragForegroundProperty;
+ (WXDependencyProperty*)dragOpacityProperty;
+ (WXDependencyProperty*)focusBorderBrushProperty;
+ (WXDependencyProperty*)gridViewItemPresenterHorizontalContentAlignmentProperty;
+ (WXDependencyProperty*)gridViewItemPresenterPaddingProperty;
+ (WXDependencyProperty*)gridViewItemPresenterVerticalContentAlignmentProperty;
+ (WXDependencyProperty*)placeholderBackgroundProperty;
+ (WXDependencyProperty*)pointerOverBackgroundMarginProperty;
+ (WXDependencyProperty*)pointerOverBackgroundProperty;
+ (WXDependencyProperty*)reorderHintOffsetProperty;
+ (WXDependencyProperty*)selectedBackgroundProperty;
+ (WXDependencyProperty*)selectedBorderThicknessProperty;
+ (WXDependencyProperty*)selectedForegroundProperty;
+ (WXDependencyProperty*)selectedPointerOverBackgroundProperty;
+ (WXDependencyProperty*)selectedPointerOverBorderBrushProperty;
+ (WXDependencyProperty*)selectionCheckMarkVisualEnabledProperty;
@end

#endif // __WUXCPGridViewItemPresenter_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ListViewItemPresenter
#ifndef __WUXCPListViewItemPresenter_DEFINED__
#define __WUXCPListViewItemPresenter_DEFINED__

WINRT_EXPORT
@interface WUXCPListViewItemPresenter : WXCContentPresenter
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMBrush* checkBrush;
@property (copy) WUXMBrush* dragForeground;
@property (copy) WUXMBrush* dragBackground;
@property double disabledOpacity;
@property (copy) WXThickness* contentMargin;
@property (copy) WUXMBrush* checkSelectingBrush;
@property (copy) WUXMBrush* placeholderBackground;
@property (copy) WUXMBrush* checkHintBrush;
@property double dragOpacity;
@property (copy) WUXMBrush* pointerOverBackground;
@property WXVerticalAlignment listViewItemPresenterVerticalContentAlignment;
@property (copy) WXThickness* listViewItemPresenterPadding;
@property WXHorizontalAlignment listViewItemPresenterHorizontalContentAlignment;
@property (copy) WUXMBrush* focusBorderBrush;
@property (copy) WXThickness* pointerOverBackgroundMargin;
@property (copy) WUXMBrush* selectedPointerOverBorderBrush;
@property (copy) WUXMBrush* selectedPointerOverBackground;
@property (copy) WUXMBrush* selectedForeground;
@property (copy) WXThickness* selectedBorderThickness;
@property (copy) WUXMBrush* selectedBackground;
@property double reorderHintOffset;
@property BOOL selectionCheckMarkVisualEnabled;
@property (copy) WUXMBrush* pressedBackground;
@property (copy) WUXMBrush* pointerOverForeground;
@property (copy) WUXMBrush* focusSecondaryBorderBrush;
@property (copy) WUXMBrush* selectedPressedBackground;
@property WUXCPListViewItemPresenterCheckMode checkMode;
@property (copy) WUXMBrush* checkBoxBrush;
+ (WXDependencyProperty*)checkSelectingBrushProperty;
+ (WXDependencyProperty*)checkBrushProperty;
+ (WXDependencyProperty*)checkHintBrushProperty;
+ (WXDependencyProperty*)contentMarginProperty;
+ (WXDependencyProperty*)disabledOpacityProperty;
+ (WXDependencyProperty*)dragBackgroundProperty;
+ (WXDependencyProperty*)dragForegroundProperty;
+ (WXDependencyProperty*)dragOpacityProperty;
+ (WXDependencyProperty*)focusBorderBrushProperty;
+ (WXDependencyProperty*)listViewItemPresenterHorizontalContentAlignmentProperty;
+ (WXDependencyProperty*)listViewItemPresenterPaddingProperty;
+ (WXDependencyProperty*)listViewItemPresenterVerticalContentAlignmentProperty;
+ (WXDependencyProperty*)placeholderBackgroundProperty;
+ (WXDependencyProperty*)pointerOverBackgroundMarginProperty;
+ (WXDependencyProperty*)pointerOverBackgroundProperty;
+ (WXDependencyProperty*)reorderHintOffsetProperty;
+ (WXDependencyProperty*)selectedBackgroundProperty;
+ (WXDependencyProperty*)selectedBorderThicknessProperty;
+ (WXDependencyProperty*)selectedForegroundProperty;
+ (WXDependencyProperty*)selectedPointerOverBackgroundProperty;
+ (WXDependencyProperty*)selectedPointerOverBorderBrushProperty;
+ (WXDependencyProperty*)selectionCheckMarkVisualEnabledProperty;
+ (WXDependencyProperty*)checkModeProperty;
+ (WXDependencyProperty*)focusSecondaryBorderBrushProperty;
+ (WXDependencyProperty*)pointerOverForegroundProperty;
+ (WXDependencyProperty*)pressedBackgroundProperty;
+ (WXDependencyProperty*)selectedPressedBackgroundProperty;
+ (WXDependencyProperty*)checkBoxBrushProperty;
@end

#endif // __WUXCPListViewItemPresenter_DEFINED__

// Windows.UI.Xaml.Controls.IContentControlOverrides
#ifndef __WXCIContentControlOverrides_DEFINED__
#define __WXCIContentControlOverrides_DEFINED__

@protocol WXCIContentControlOverrides
- (void)onContentChanged:(RTObject*)oldContent newContent:(RTObject*)newContent;
- (void)onContentTemplateChanged:(WXDataTemplate*)oldContentTemplate newContentTemplate:(WXDataTemplate*)newContentTemplate;
- (void)onContentTemplateSelectorChanged:(WXCDataTemplateSelector*)oldContentTemplateSelector
              newContentTemplateSelector:(WXCDataTemplateSelector*)newContentTemplateSelector;
@end

#endif // __WXCIContentControlOverrides_DEFINED__

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

#endif // __WXCIControlOverrides_DEFINED__

// Windows.UI.Xaml.Controls.Control
#ifndef __WXCControl_DEFINED__
#define __WXCControl_DEFINED__

WINRT_EXPORT
@interface WXCControl : WXFrameworkElement
+ (BOOL)getIsTemplateFocusTarget:(WXFrameworkElement*)element;
+ (void)setIsTemplateFocusTarget:(WXFrameworkElement*)element value:(BOOL)value;
+ (instancetype)create ACTIVATOR;
@property (copy) WUTFontWeight* fontWeight;
@property WUTFontStyle fontStyle;
@property WUTFontStretch fontStretch;
@property double fontSize;
@property (copy) WUXMBrush* background;
@property (copy) WUXMFontFamily* fontFamily;
@property (copy) WUXMBrush* foreground;
@property int characterSpacing;
@property (copy) WXThickness* borderThickness;
@property (copy) WUXMBrush* borderBrush;
@property WXHorizontalAlignment horizontalContentAlignment;
@property WXVerticalAlignment verticalContentAlignment;
@property (copy) WXCControlTemplate* Template;
@property int tabIndex;
@property (copy) WXThickness* padding;
@property BOOL isTabStop;
@property BOOL isEnabled;
@property WUXIKeyboardNavigationMode tabNavigation;
@property (readonly) WXFocusState focusState;
@property BOOL isTextScaleFactorEnabled;
@property BOOL useSystemFocusVisuals;
@property (copy) RTObject* defaultStyleKey;
+ (WXDependencyProperty*)fontSizeProperty;
+ (WXDependencyProperty*)backgroundProperty;
+ (WXDependencyProperty*)borderBrushProperty;
+ (WXDependencyProperty*)borderThicknessProperty;
+ (WXDependencyProperty*)characterSpacingProperty;
+ (WXDependencyProperty*)defaultStyleKeyProperty;
+ (WXDependencyProperty*)focusStateProperty;
+ (WXDependencyProperty*)fontFamilyProperty;
+ (WXDependencyProperty*)fontStretchProperty;
+ (WXDependencyProperty*)fontStyleProperty;
+ (WXDependencyProperty*)fontWeightProperty;
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
+ (WXDependencyProperty*)useSystemFocusVisualsProperty;
+ (WXDependencyProperty*)isTemplateFocusTargetProperty;
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

// Windows.UI.Xaml.Controls.Primitives.Thumb
#ifndef __WUXCPThumb_DEFINED__
#define __WUXCPThumb_DEFINED__

WINRT_EXPORT
@interface WUXCPThumb : WXCControl
+ (instancetype)create ACTIVATOR;
@property (readonly) BOOL isDragging;
+ (WXDependencyProperty*)isDraggingProperty;
- (EventRegistrationToken)addDragCompletedEvent:(WUXCPDragCompletedEventHandler)del;
- (void)removeDragCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragDeltaEvent:(WUXCPDragDeltaEventHandler)del;
- (void)removeDragDeltaEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addDragStartedEvent:(WUXCPDragStartedEventHandler)del;
- (void)removeDragStartedEvent:(EventRegistrationToken)tok;
- (void)cancelDrag;
@end

#endif // __WUXCPThumb_DEFINED__

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

// Windows.UI.Xaml.Controls.Primitives.ScrollBar
#ifndef __WUXCPScrollBar_DEFINED__
#define __WUXCPScrollBar_DEFINED__

WINRT_EXPORT
@interface WUXCPScrollBar : WUXCPRangeBase
+ (instancetype)create ACTIVATOR;
@property double viewportSize;
@property WXCOrientation orientation;
@property WUXCPScrollingIndicatorMode indicatorMode;
+ (WXDependencyProperty*)indicatorModeProperty;
+ (WXDependencyProperty*)orientationProperty;
+ (WXDependencyProperty*)viewportSizeProperty;
- (EventRegistrationToken)addScrollEvent:(WUXCPScrollEventHandler)del;
- (void)removeScrollEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCPScrollBar_DEFINED__

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
- (void)onItemContainerStyleSelectorChanged:(WXCStyleSelector*)oldItemContainerStyleSelector
              newItemContainerStyleSelector:(WXCStyleSelector*)newItemContainerStyleSelector;
- (void)onItemTemplateChanged:(WXDataTemplate*)oldItemTemplate newItemTemplate:(WXDataTemplate*)newItemTemplate;
- (void)onItemTemplateSelectorChanged:(WXCDataTemplateSelector*)oldItemTemplateSelector
              newItemTemplateSelector:(WXCDataTemplateSelector*)newItemTemplateSelector;
- (void)onGroupStyleSelectorChanged:(WXCGroupStyleSelector*)oldGroupStyleSelector
              newGroupStyleSelector:(WXCGroupStyleSelector*)newGroupStyleSelector;
@end

#endif // __WXCIItemsControlOverrides_DEFINED__

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

// Windows.UI.Xaml.Controls.ItemsControl
#ifndef __WXCItemsControl_DEFINED__
#define __WXCItemsControl_DEFINED__

WINRT_EXPORT
@interface WXCItemsControl : WXCControl <WXCIItemContainerMapping>
+ (WXCItemsControl*)getItemsOwner:(WXDependencyObject*)element;
+ (WXCItemsControl*)itemsControlFromItemContainer:(WXDependencyObject*)container;
+ (instancetype)create ACTIVATOR;
@property (copy) WXCItemsPanelTemplate* itemsPanel;
@property (copy) RTObject* itemsSource;
@property (copy) WXCDataTemplateSelector* itemTemplateSelector;
@property (copy) WXDataTemplate* itemTemplate;
@property (copy) WXCStyleSelector* itemContainerStyleSelector;
@property (copy) WXStyle* itemContainerStyle;
@property (copy) WXCGroupStyleSelector* groupStyleSelector;
@property (copy) WUXMATransitionCollection* itemContainerTransitions;
@property (copy) NSString* displayMemberPath;
@property (readonly) WXCItemContainerGenerator* itemContainerGenerator;
@property (readonly) WXCItemCollection* items;
@property (readonly) NSMutableArray<RTObservableCollection>* groupStyle;
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
- (void)onItemContainerStyleSelectorChanged:(WXCStyleSelector*)oldItemContainerStyleSelector
              newItemContainerStyleSelector:(WXCStyleSelector*)newItemContainerStyleSelector;
- (void)onItemTemplateChanged:(WXDataTemplate*)oldItemTemplate newItemTemplate:(WXDataTemplate*)newItemTemplate;
- (void)onItemTemplateSelectorChanged:(WXCDataTemplateSelector*)oldItemTemplateSelector
              newItemTemplateSelector:(WXCDataTemplateSelector*)newItemTemplateSelector;
- (void)onGroupStyleSelectorChanged:(WXCGroupStyleSelector*)oldGroupStyleSelector
              newGroupStyleSelector:(WXCGroupStyleSelector*)newGroupStyleSelector;
- (RTObject*)itemFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromItem:(RTObject*)item;
- (int)indexFromContainer:(WXDependencyObject*)container;
- (WXDependencyObject*)containerFromIndex:(int)index;
- (WXDependencyObject*)groupHeaderContainerFromItemContainer:(WXDependencyObject*)itemContainer;
@end

#endif // __WXCItemsControl_DEFINED__

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
@property (copy) id isSynchronizedWithCurrentItem;
+ (WXDependencyProperty*)isSynchronizedWithCurrentItemProperty;
+ (WXDependencyProperty*)selectedIndexProperty;
+ (WXDependencyProperty*)selectedItemProperty;
+ (WXDependencyProperty*)selectedValuePathProperty;
+ (WXDependencyProperty*)selectedValueProperty;
- (EventRegistrationToken)addSelectionChangedEvent:(WXCSelectionChangedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCPSelector_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.RepeatButton
#ifndef __WUXCPRepeatButton_DEFINED__
#define __WUXCPRepeatButton_DEFINED__

WINRT_EXPORT
@interface WUXCPRepeatButton : WUXCPButtonBase
+ (instancetype)create ACTIVATOR;
@property int interval;
@property int delay;
+ (WXDependencyProperty*)delayProperty;
+ (WXDependencyProperty*)intervalProperty;
@end

#endif // __WUXCPRepeatButton_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.ToggleButton
#ifndef __WUXCPToggleButton_DEFINED__
#define __WUXCPToggleButton_DEFINED__

WINRT_EXPORT
@interface WUXCPToggleButton : WUXCPButtonBase
+ (instancetype)create ACTIVATOR;
@property BOOL isThreeState;
@property (copy) id isChecked;
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

// Windows.UI.Xaml.Data.IValueConverter
#ifndef __WUXDIValueConverter_DEFINED__
#define __WUXDIValueConverter_DEFINED__

@protocol WUXDIValueConverter
- (RTObject*)convert:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
- (RTObject*)convertBack:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
@end

#endif // __WUXDIValueConverter_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.JumpListItemBackgroundConverter
#ifndef __WUXCPJumpListItemBackgroundConverter_DEFINED__
#define __WUXCPJumpListItemBackgroundConverter_DEFINED__

WINRT_EXPORT
@interface WUXCPJumpListItemBackgroundConverter : WXDependencyObject <WUXDIValueConverter>
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMBrush* enabled;
@property (copy) WUXMBrush* disabled;
+ (WXDependencyProperty*)disabledProperty;
+ (WXDependencyProperty*)enabledProperty;
- (RTObject*)convert:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
- (RTObject*)convertBack:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
@end

#endif // __WUXCPJumpListItemBackgroundConverter_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.JumpListItemForegroundConverter
#ifndef __WUXCPJumpListItemForegroundConverter_DEFINED__
#define __WUXCPJumpListItemForegroundConverter_DEFINED__

WINRT_EXPORT
@interface WUXCPJumpListItemForegroundConverter : WXDependencyObject <WUXDIValueConverter>
+ (instancetype)create ACTIVATOR;
@property (copy) WUXMBrush* enabled;
@property (copy) WUXMBrush* disabled;
+ (WXDependencyProperty*)disabledProperty;
+ (WXDependencyProperty*)enabledProperty;
- (RTObject*)convert:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
- (RTObject*)convertBack:(RTObject*)value targetType:(WUXITypeName*)targetType parameter:(RTObject*)parameter language:(NSString*)language;
@end

#endif // __WUXCPJumpListItemForegroundConverter_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.PickerFlyoutBase
#ifndef __WUXCPPickerFlyoutBase_DEFINED__
#define __WUXCPPickerFlyoutBase_DEFINED__

WINRT_EXPORT
@interface WUXCPPickerFlyoutBase : WUXCPFlyoutBase
+ (NSString*)getTitle:(WXDependencyObject*)element;
+ (void)setTitle:(WXDependencyObject*)element value:(NSString*)value;
+ (instancetype)create ACTIVATOR;
+ (WXDependencyProperty*)titleProperty;
- (void)onConfirmed;
- (BOOL)shouldShowConfirmationButtons;
@end

#endif // __WUXCPPickerFlyoutBase_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.LoopingSelector
#ifndef __WUXCPLoopingSelector_DEFINED__
#define __WUXCPLoopingSelector_DEFINED__

WINRT_EXPORT
@interface WUXCPLoopingSelector : WXCControl
@property BOOL shouldLoop;
@property (copy) RTObject* selectedItem;
@property int selectedIndex;
@property (copy) NSMutableArray* items;
@property int itemWidth;
@property (copy) WXDataTemplate* itemTemplate;
@property int itemHeight;
+ (WXDependencyProperty*)itemHeightProperty;
+ (WXDependencyProperty*)itemTemplateProperty;
+ (WXDependencyProperty*)itemWidthProperty;
+ (WXDependencyProperty*)itemsProperty;
+ (WXDependencyProperty*)selectedIndexProperty;
+ (WXDependencyProperty*)selectedItemProperty;
+ (WXDependencyProperty*)shouldLoopProperty;
- (EventRegistrationToken)addSelectionChangedEvent:(WXCSelectionChangedEventHandler)del;
- (void)removeSelectionChangedEvent:(EventRegistrationToken)tok;
@end

#endif // __WUXCPLoopingSelector_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.PivotPanel
#ifndef __WUXCPPivotPanel_DEFINED__
#define __WUXCPPivotPanel_DEFINED__

WINRT_EXPORT
@interface WUXCPPivotPanel : WXCPanel <WUXCPIScrollSnapPointsInfo>
+ (instancetype)create ACTIVATOR;
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (NSArray*)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WUXCPPivotPanel_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.LoopingSelectorItem
#ifndef __WUXCPLoopingSelectorItem_DEFINED__
#define __WUXCPLoopingSelectorItem_DEFINED__

WINRT_EXPORT
@interface WUXCPLoopingSelectorItem : WXCContentControl
@end

#endif // __WUXCPLoopingSelectorItem_DEFINED__

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

// Windows.UI.Xaml.Controls.Primitives.LoopingSelectorPanel
#ifndef __WUXCPLoopingSelectorPanel_DEFINED__
#define __WUXCPLoopingSelectorPanel_DEFINED__

WINRT_EXPORT
@interface WUXCPLoopingSelectorPanel : WXCCanvas <WUXCPIScrollSnapPointsInfo>
@property (readonly) BOOL areHorizontalSnapPointsRegular;
@property (readonly) BOOL areVerticalSnapPointsRegular;
- (EventRegistrationToken)addHorizontalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeHorizontalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addVerticalSnapPointsChangedEvent:(void (^)(RTObject*, RTObject*))del;
- (void)removeVerticalSnapPointsChangedEvent:(EventRegistrationToken)tok;
- (NSArray*)getIrregularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment;
- (float)getRegularSnapPoints:(WXCOrientation)orientation alignment:(WUXCPSnapPointsAlignment)alignment offset:(float*)offset;
@end

#endif // __WUXCPLoopingSelectorPanel_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.PivotHeaderItem
#ifndef __WUXCPPivotHeaderItem_DEFINED__
#define __WUXCPPivotHeaderItem_DEFINED__

WINRT_EXPORT
@interface WUXCPPivotHeaderItem : WXCContentControl
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXCPPivotHeaderItem_DEFINED__

// Windows.UI.Xaml.Controls.Primitives.PivotHeaderPanel
#ifndef __WUXCPPivotHeaderPanel_DEFINED__
#define __WUXCPPivotHeaderPanel_DEFINED__

WINRT_EXPORT
@interface WUXCPPivotHeaderPanel : WXCCanvas
+ (instancetype)create ACTIVATOR;
@end

#endif // __WUXCPPivotHeaderPanel_DEFINED__
