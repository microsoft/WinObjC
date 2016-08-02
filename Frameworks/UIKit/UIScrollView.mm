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

#import <StubReturn.h>
#import "AssertARCEnabled.h"
#import "Starboard.h"
#import <cmath>
#import <Foundation/NSNumber.h>
#import <Foundation/NSTimer.h>
#import <Foundation/NSRunLoop.h>
#import <Foundation/NSSet.h>
#import <Foundation/NSString.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGeometry.h>
#import <QuartzCore/CABasicAnimation.h>
#import <QuartzCore/CADisplayLink.h>
#import <QuartzCore/CALayer.h>
#import <UIKit/UIApplication.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIEvent.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UIPanGestureRecognizer.h>
#import <UIKit/UIScrollView.h>
#import <UWP/WindowsUIXamlControls.h>
#import <UWP/WindowsUIXamlShapes.h>

#import "CAAnimationInternal.h"
#import "CALayerInternal.h"
#import "CACompositor.h"
#import "UIEventInternal.h"
#import "UIGestureRecognizerInternal.h"
#import "UITouchInternal.h"
#import "Etc.h"
#import "XamlUtilities.h"
#import "StarboardXaml/CompositorInterface.h"

static const wchar_t* TAG = L"UIScrollView";

static const bool DEBUG_ALL = false;
static const bool DEBUG_VERBOSE = DEBUG_ALL || false;
static const bool DEBUG_DELEGATE = DEBUG_ALL || false;
static const bool DEBUG_INSETS = DEBUG_ALL || false;

/** @Status Stub */
const float UIScrollViewDecelerationRateNormal = StubConstant();
/** @Status Stub */
const float UIScrollViewDecelerationRateFast = StubConstant();

// Customer CALayer for UIScrollview
@interface _UIScrollViewCALayer : CALayer
@end

@implementation _UIScrollViewCALayer
- (instancetype)init {
    self = [super init];
    return self;
}

// override setOrigin not to adjust its content origin because scrolling is now done by scrollviewer
// otherwise, it will cause double scrolling for the content
- (void)setOrigin:(CGPoint)origin {
    [self _setOrigin:origin updateContent:NO];
}
@end

@implementation UIScrollView {
    CGPoint _contentOffset;
    CGSize _contentSize;
    UIEdgeInsets _contentInset;
    UIEdgeInsets _scrollIndicatorInsets;
    BOOL _isDragging;
    BOOL _isTracking;
    BOOL _pagingEnabled;
    BOOL _canCancelContentTouches;
    BOOL _delaysContentTouches;

    // TODO: Zoom related properties and Pink gesture will be updated to
    // work with directManipulation Pinch Gesture in upcoming changes
    idretain _zoomView;
    float _zoomScale, _maximumZoomScale, _minimumZoomScale;
    idretain _pinchGesture;
    BOOL _isZooming, _isZoomingToRect;

    // xaml visuals to back UIScrollView - includes Scrollviewer, ContentGrid, Insets, and ContentCanvas
    StrongId<WXCScrollViewer> _scrollViewer;
    StrongId<WXCGrid> _contentGrid;
    StrongId<WUXSRectangle> _topInset;
    StrongId<WUXSRectangle> _rightInset;
    StrongId<WUXSRectangle> _bottomInset;
    StrongId<WUXSRectangle> _leftInset;
    StrongId<WXCCanvas> _contentCanvas;

    EventRegistrationToken _directManipulationStartedEventToken;
    EventRegistrationToken _directManipulationCompletedEventToken;
    EventRegistrationToken _viewChangingEventToken;
    EventRegistrationToken _viewChangedEventToken;
    EventRegistrationToken _loadEventToken;

    // flag to YES if the scrolling is triggered by underline xaml scrollviewer
    bool _scrollingTriggeredByScrollviewer;

    // when Srollviewer is animating, flag to YES, otherwise, NO
    BOOL _isAnimating;

    // when direct manipulation started, flag to YES, otherwise, NO
    BOOL _manipulationStarted;

    // when scrollviewer animation is decelerating, flag to YES, otherwise NO
    // currently this is only approxmiation
    BOOL _decelerating;

    // flag to YES after user lift up finger and associated delegates fired.
    BOOL _firedDelegatesAfterFingerLifted;

    // flag to YES after UISCroll has been loaded
    BOOL _loaded;

    // flag to YES if scrollviewer is still changing its contentOffset
    BOOL _isChangingContentOffset;

    // when scrolling is disabled, recording the previous  horizontal scrollbar visibility
    WXCScrollBarVisibility _previousHorizontalScrollBarVisibility;

    // when scrolling is disabled, recording the previous vertical scrollbar visibility
    WXCScrollBarVisibility _previousVerticalScrollBarVisibility;
}

- (void)_initUIScrollView {
    // TODO: gesture/zoom related code will be changed in upcoming change
    [self setMultipleTouchEnabled:TRUE];
    self->_zoomScale = self->_maximumZoomScale = self->_minimumZoomScale = 1.0f;
    self->_pinchGesture = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(_didPinch:)];
    [self->_pinchGesture setDelegate:self];
    [self addGestureRecognizer:self->_pinchGesture];

    // do necessary init for backing xaml elements
    [self _initScrollViewer];
}

- (void)_initScrollViewer {
    // creating backing scrollviewer
    _scrollViewer = [WXCScrollViewer make];

    // create insets, assign names to make it easy to debug in visual tree
    _topInset = [WUXSRectangle make];
    _topInset.name = @"top";
    _rightInset = [WUXSRectangle make];
    _rightInset.name = @"right";
    _bottomInset = [WUXSRectangle make];
    _bottomInset.name = @"bottom";
    _leftInset = [WUXSRectangle make];
    _leftInset.name = @"left";

    // create content canvas
    _contentCanvas = [WXCCanvas make];
    _contentCanvas.name = @"Content Canvas";

    // creating and build 3 X 3 content grid
    _contentGrid = [WXCGrid make];
    WXCColumnDefinition* column0 = [WXCColumnDefinition make];
    WXCColumnDefinition* column1 = [WXCColumnDefinition make];
    WXCColumnDefinition* column2 = [WXCColumnDefinition make];

    column0.width = [WXGridLengthHelper fromValueAndType:0 type:WXGridUnitTypeAuto];
    column1.width = [WXGridLengthHelper fromValueAndType:0 type:WXGridUnitTypeAuto];
    column2.width = [WXGridLengthHelper fromValueAndType:0 type:WXGridUnitTypeAuto];
    WXCRowDefinition* row0 = [WXCRowDefinition make];
    WXCRowDefinition* row1 = [WXCRowDefinition make];
    WXCRowDefinition* row2 = [WXCRowDefinition make];
    row0.height = [WXGridLengthHelper fromValueAndType:0 type:WXGridUnitTypeAuto];
    row1.height = [WXGridLengthHelper fromValueAndType:0 type:WXGridUnitTypeAuto];
    row2.height = [WXGridLengthHelper fromValueAndType:0 type:WXGridUnitTypeAuto];

    [_contentGrid.columnDefinitions addObject:column0];
    [_contentGrid.columnDefinitions addObject:column1];
    [_contentGrid.columnDefinitions addObject:column2];
    [_contentGrid.rowDefinitions addObject:row0];
    [_contentGrid.rowDefinitions addObject:row1];
    [_contentGrid.rowDefinitions addObject:row2];

    // put insets into top/right/bottom/left in Grid
    [_contentGrid.children addObject:_topInset];
    [WXCGrid setColumn:_topInset value:1];
    [WXCGrid setRow:_topInset value:0];

    [_contentGrid.children addObject:_rightInset];
    [WXCGrid setColumn:_rightInset value:2];
    [WXCGrid setRow:_rightInset value:1];

    [_contentGrid.children addObject:_bottomInset];
    [WXCGrid setColumn:_bottomInset value:1];
    [WXCGrid setRow:_bottomInset value:2];

    [_contentGrid.children addObject:_leftInset];
    [WXCGrid setColumn:_leftInset value:0];
    [WXCGrid setRow:_leftInset value:1];

    // put content canvas in the middle
    [_contentGrid.children addObject:_contentCanvas];
    [WXCGrid setColumn:_contentCanvas value:1];
    [WXCGrid setRow:_contentCanvas value:1];

    // set contentGrid as the content of the scrollviewer
    _scrollViewer.content = _contentGrid;

    // by default enable chaining
    _scrollViewer.isVerticalScrollChainingEnabled = YES;
    _scrollViewer.isHorizontalScrollChainingEnabled = YES;
    _loaded = NO;

    // setting the rootElement and the content element for scroll viewer
    DisplayNode* displayNode = [[self layer] _presentationNode];
    displayNode->SetScrollviewerControls(_scrollViewer.comObj.Get(), _contentCanvas.comObj.Get());

    // setting up manipulation, viewchanging and viewchanged event handlers
    [self _setupManipulationEventHandlers];
    [self _setupViewChangingHandler];
    [self _setupViewChangedHandler];
    [self _setupLoadedEventHandler];

    // initial states of internal flags
    _isChangingContentOffset = NO;
    _previousHorizontalScrollBarVisibility = WXCScrollBarVisibilityAuto;
    _previousVerticalScrollBarVisibility = WXCScrollBarVisibilityAuto;
    _scrollingTriggeredByScrollviewer = NO;
    _isAnimating = NO;
    _manipulationStarted = NO;
    _decelerating = NO;
    _firedDelegatesAfterFingerLifted = NO;
    _contentOffset = CGPointZero;

    // Set up our defaults:
    [self _setScrollEnabled:YES];
}

- (BOOL)_isAnimating {
    return _isAnimating;
}

- (void)_setBackgroundColor:(UIColor*)color {
    _scrollViewer.background = [WUXMSolidColorBrush makeInstanceWithColor:ConvertUIColorToWUColor(color)];
}

- (void)_setupViewChangingHandler {
    __weak UIScrollView* weakself = self;
    _viewChangingEventToken = [_scrollViewer addViewChangingEvent:^void(RTObject*, WXCScrollViewerViewChangingEventArgs* arg) {
        __strong UIScrollView* strongSelf = weakself;
        if (strongSelf) {
            if ((strongSelf->_scrollViewer.horizontalOffset != arg.nextView.horizontalOffset) ||
                (strongSelf->_scrollViewer.verticalOffset != arg.finalView.verticalOffset)) {
                if (DEBUG_VERBOSE) {
                    TraceVerbose(TAG,
                                 L"ViewChanging: currentOffset=[%f, %f], nextOffset=[%f, %f], finalOffset=[%f, %f], isAnimating=%d, "
                                 L"isDragging=%d, isInertial=%d, isPagingEnabled=%d, firedDelegatesAfterFingerLifted=%d, "
                                 L"manipulationStarted=%d",
                                 strongSelf->_scrollViewer.horizontalOffset,
                                 strongSelf->_scrollViewer.verticalOffset,
                                 arg.nextView.horizontalOffset,
                                 arg.nextView.verticalOffset,
                                 arg.finalView.horizontalOffset,
                                 arg.finalView.verticalOffset,
                                 strongSelf->_isAnimating,
                                 strongSelf->_isDragging,
                                 arg.isInertial,
                                 strongSelf->_pagingEnabled,
                                 strongSelf->_firedDelegatesAfterFingerLifted,
                                 strongSelf->_manipulationStarted);
                }

                // view is about to change its position (or scrolling)
                if (strongSelf->_manipulationStarted) {
                    if (!arg.isInertial) {
                        // reset this flag to fire delegates after user lift up finger
                        strongSelf->_firedDelegatesAfterFingerLifted = NO;

                        // if manipulation started and view is changing without inertial, it means user is dragging the view
                        if (!strongSelf->_isDragging) {
                            strongSelf->_isDragging = YES;

                            // NOTE: only fire scrollViewWillBeginDragging delegate once
                            if ([strongSelf.delegate respondsToSelector:@selector(scrollViewWillBeginDragging:)]) {
                                if (DEBUG_DELEGATE) {
                                    TraceVerbose(TAG, L"viewchanging invoke delegate scrollViewWillBeginDragging");
                                }

                                [strongSelf.delegate scrollViewWillBeginDragging:strongSelf];
                            }
                        }
                    } else {
                        // Inertial kicks in while manipuation is going on, user lift up the finger
                        // flag tracking and dragging to be NO, and anitmating starts
                        // scrolling will start to decelerate
                        strongSelf->_isTracking = NO;
                        strongSelf->_isAnimating = YES;

                        if (strongSelf->_isDragging) {
                            strongSelf->_isDragging = NO;
                            strongSelf->_decelerating = YES;

                            if (strongSelf->_pagingEnabled) {
                                // TODO: currently horizonal only and also consider using windows Snappoints for paging in the future

                                // cancel the direct manipulation before we do manual animating to page boundary
                                strongSelf->_decelerating = NO;
                                [strongSelf->_scrollViewer cancelDirectManipulations];

                                // re-caculate scrolling boundary based on the predicted finalview offset
                                CGRect bound = [strongSelf bounds];
                                int curScrollPage = int((arg.finalView.horizontalOffset + bound.size.width / 2.0f) / bound.size.width);
                                CGPoint offset = { curScrollPage * bound.size.width, 0 };

                                // re-target the scrollview to be the page boundary
                                changeContentOffset(strongSelf, offset, YES);
                            } else {
                                // paging is not enabled, no extra work in this case
                            }
                        } else if (!strongSelf->_firedDelegatesAfterFingerLifted) {
                            // user finer lifted and scrollviwer is doing inertial scrolling, fired delegates
                            if ([strongSelf.delegate
                                    respondsToSelector:@selector(scrollViewWillEndDragging:withVelocity:targetContentOffset:)]) {
                                if (DEBUG_DELEGATE) {
                                    TraceVerbose(
                                        TAG, L"viewchanging invoke delegate scrollViewWillEndDragging:withVelocity:targetContentOffset:");
                                }

                                // TODO: we current don't support velocity, currently no one is using veloctity, including pageview
                                // controller
                                CGPoint velocity = { 0 };
                                CGPoint offset = { arg.finalView.horizontalOffset, arg.finalView.verticalOffset };
                                [strongSelf.delegate scrollViewWillEndDragging:strongSelf
                                                                  withVelocity:velocity
                                                           targetContentOffset:&offset];
                            }

                            if ([strongSelf.delegate respondsToSelector:@selector(scrollViewDidEndDragging:willDecelerate:)]) {
                                if (DEBUG_DELEGATE) {
                                    TraceVerbose(TAG, L"viewchanging invoke delegate scrollViewDidEndDragging:willDecelerate:");
                                }

                                [strongSelf.delegate scrollViewDidEndDragging:strongSelf willDecelerate:YES];
                            }

                            // scrollview will begining decelerating now
                            if ([strongSelf.delegate respondsToSelector:@selector(scrollViewWillBeginDecelerating:)]) {
                                if (DEBUG_DELEGATE) {
                                    TraceVerbose(TAG, L"viewchanging invoking delegate scrollViewWillBeginDecelerating");
                                }

                                [strongSelf.delegate scrollViewWillBeginDecelerating:strongSelf];
                            }

                            strongSelf->_firedDelegatesAfterFingerLifted = YES;
                        } else {
                            // we have fired the delegates after user lift the finger
                            // no extra work to do
                        }
                    }
                }
            }
        }
    }];
}

- (void)_setupViewChangedHandler {
    __weak UIScrollView* weakself = self;
    _viewChangedEventToken = [_scrollViewer addViewChangedEvent:^void(RTObject*, WXCScrollViewerViewChangedEventArgs* arg) {
        __strong UIScrollView* strongSelf = weakself;
        if (strongSelf) {
            // when we get notification from scrollviewer, associated offset contains insets
            // we need to discount it before change the offset on UIScrollvew
            CGPoint offset;
            offset.x = strongSelf->_scrollViewer.horizontalOffset - strongSelf->_contentInset.left;
            offset.y = strongSelf->_scrollViewer.verticalOffset - strongSelf->_contentInset.top;

            if (DEBUG_VERBOSE) {
                TraceVerbose(TAG,
                             L"ViewChanged: interm=%d, currentOffset=[%f, %f], nextOffset=[%f, %f], contentSize=[%f, %f]",
                             arg.isIntermediate,
                             strongSelf->_contentOffset.x,
                             strongSelf->_contentOffset.y,
                             offset.x,
                             offset.y,
                             strongSelf->_contentSize.width,
                             strongSelf->_contentSize.height);
            }

            if (arg.isIntermediate) {
                // intermedia view changed event
                changeContentOffset(strongSelf, offset, FALSE);
            } else {
                // final view changed event
                strongSelf->_isAnimating = NO;

                // only invoke these two delegates when we are actually doing animation
                if (strongSelf->_decelerating) {
                    // when final viewchanged fires, the scrollview comes at halt, if previously it is decelerating
                    // flag decelerating to NO and invoke delegate that scrollViewDidEndDecelerating
                    strongSelf->_decelerating = NO;
                    if ([strongSelf.delegate respondsToSelector:@selector(scrollViewDidEndDecelerating:)]) {
                        if (DEBUG_DELEGATE) {
                            TraceVerbose(TAG, L"viewchanged invoke delegate scrollViewDidEndDecelerating");
                        }

                        [strongSelf.delegate scrollViewDidEndDecelerating:strongSelf];
                    }

                    // scrolling stopped, reset flags
                    if ([strongSelf.delegate respondsToSelector:@selector(scrollViewDidEndScrollingAnimation:)]) {
                        if (DEBUG_DELEGATE) {
                            TraceVerbose(TAG, L"viewchanged invoke delegate scrollViewDidEndScrollingAnimation");
                        }

                        [strongSelf.delegate scrollViewDidEndScrollingAnimation:strongSelf];

                        // relayout preparing for next scroll
                        if (DEBUG_VERBOSE) {
                            TraceVerbose(TAG,
                                         L"after called scrollViewDidEndScrollingAnimation: currentOffset=[%f, %f], contentSize=[%f, %f]",
                                         strongSelf->_contentOffset.x,
                                         strongSelf->_contentOffset.y,
                                         strongSelf->_contentSize.width,
                                         strongSelf->_contentSize.height);
                        }
                    }
                }

                changeContentOffset(strongSelf, offset, FALSE);
                strongSelf->_scrollingTriggeredByScrollviewer = NO;
                strongSelf->_isChangingContentOffset = NO;
                if (DEBUG_VERBOSE) {
                    TraceVerbose(TAG,
                                 L"in view changed listener: _isChangingContentOffset set to %d in viewchanged final",
                                 strongSelf->_isChangingContentOffset);
                }
            }
        }
    }];
}

- (void)_setupManipulationEventHandlers {
    __weak UIScrollView* weakself = self;
    _directManipulationStartedEventToken = [_scrollViewer addDirectManipulationStartedEvent:^void(RTObject*, RTObject*) {
        __strong UIScrollView* strongSelf = weakself;
        if (DEBUG_VERBOSE) {
            TraceVerbose(TAG, L"Manipulation----Started");
        }

        if (strongSelf) {
            strongSelf->_manipulationStarted = YES;
        }
    }];

    _directManipulationCompletedEventToken = [_scrollViewer addDirectManipulationCompletedEvent:^void(RTObject*, RTObject*) {
        __strong UIScrollView* strongSelf = weakself;
        if (DEBUG_VERBOSE) {
            TraceVerbose(TAG, L"Manipulation----Completed");
        }

        if (strongSelf) {
            strongSelf->_manipulationStarted = NO;
            strongSelf->_isTracking = NO;
            strongSelf->_isDragging = NO;
        }
    }];
}

- (void)_setupLoadedEventHandler {
    __weak UIScrollView* weakSelf = self;
    _loadEventToken = [self->_scrollViewer addLoadedEvent:^void(RTObject* sender, WXRoutedEventArgs* e) {
        __strong UIScrollView* strongSelf = weakSelf;
        if (strongSelf && _contentOffset != CGPointZero) {
            strongSelf->_loaded = YES;

            const double paddedOffsetX = (double)(strongSelf->_contentOffset.x + strongSelf->_contentInset.left);
            const double paddedOffsetY = (double)(strongSelf->_contentOffset.y + strongSelf->_contentInset.top);
            BOOL changeViewSucceed = [strongSelf->_scrollViewer changeViewWithOptionalAnimation:[NSNumber numberWithDouble:paddedOffsetX]
                                                             verticalOffset:[NSNumber numberWithFloat:paddedOffsetY]
                                                                 zoomFactor:[NSNumber numberWithDouble:1.0]
                                                           disableAnimation:YES];
            if (!changeViewSucceed) {
                TraceWarning(TAG,
                             L"changeViewWithOptionalAnimation failed, self->_scrollViewer.Visibility = %d",
                             strongSelf->_scrollViewer.visibility);
                
            } else {
                [strongSelf->_scrollViewer updateLayout];
            }
        }
    }];
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    [self _initUIScrollView];

    if (self = [super initWithCoder:coder]) {
        if ([coder containsValueForKey:@"UIDelaysContentTouches"]) {
            _delaysContentTouches = [coder decodeBoolForKey:@"UIDelaysContentTouches"];
        } else {
            _delaysContentTouches = TRUE;
        }

        _pagingEnabled = [coder decodeBoolForKey:@"UIPagingEnabled"];

        if ([coder containsValueForKey:@"UIScrollDisabled"]) {
            [self _setScrollEnabled:([coder decodeBoolForKey:@"UIScrollDisabled"] == 0)];
        }

        if ([coder containsValueForKey:@"UIShowsVerticalScrollIndicator"]) {
            [self setShowsVerticalScrollIndicator:[coder decodeBoolForKey:@"UIShowsVerticalScrollIndicator"] == 0];
        }

        if ([coder containsValueForKey:@"UIShowsHorizontalScrollIndicator"]) {
            [self setShowsHorizontalScrollIndicator:[coder decodeBoolForKey:@"UIShowsHorizontalScrollIndicator"] == 0];
        }

        CGRect bounds;
        bounds = [self bounds];
        _contentSize = bounds.size;

        if ([coder containsValueForKey:@"UIContentInset"]) {
            id obj = [coder decodeObjectForKey:@"UIContentInset"];
            UIEdgeInsets inset = { 0 };
            if ([obj isKindOfClass:[NSString class]]) {
                const char* str = [obj UTF8String];
                sscanf_s(str, "{%f, %f, %f, %f}", &inset.top, &inset.left, &inset.bottom, &inset.right);
            } else {
                CGRect* pRect = (CGRect*)((char*)[obj bytes]) + 1;
                memcpy(&inset, pRect, sizeof(CGRect));
            }

            [self setContentInset:inset];
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithFrame:(CGRect)frame {
    if (self = [super initWithFrame:frame]) {
        [self setClipsToBounds:1];
        _delaysContentTouches = TRUE;

        [self _initScrollViewer];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)setScrollEnabled:(BOOL)enable {
    [self _setScrollEnabled:enable];
}

- (void)_setScrollEnabled:(BOOL)enable {
    _scrollViewer.horizontalScrollBarVisibility = enable ? _previousHorizontalScrollBarVisibility : WXCScrollBarVisibilityDisabled;
    _scrollViewer.verticalScrollBarVisibility = enable ? _previousVerticalScrollBarVisibility : WXCScrollBarVisibilityDisabled;
}

/**
 @Status Interoperable
*/
- (BOOL)isScrollEnabled {
    return _scrollViewer.isEnabled;
}

/**
 @Status Interoperable
*/
- (void)setPagingEnabled:(BOOL)enable {
    _pagingEnabled = enable;
}

/**
 @Status Stub
*/
- (void)setBounces:(BOOL)enable {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)bounces {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setAlwaysBounceVertical:(BOOL)enable {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)alwaysBounceVertical {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setAlwaysBounceHorizontal:(BOOL)enable {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (BOOL)alwaysBounceHorizontal {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)setDelaysContentTouches:(BOOL)delay {
    UNIMPLEMENTED();
    _delaysContentTouches = delay;
}

/**
 @Status Interoperable
*/
- (BOOL)delayContentTouches {
    return _delaysContentTouches;
}

/**
 @Status Interoperable
*/
- (void)setContentSize:(CGSize)size {
    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG,
                     L"setContentSize-Begin: from [%f, %f] to [%f, %f], _isAnimating=%d",
                     _contentSize.width,
                     _contentSize.height,
                     size.width,
                     size.height,
                     _isAnimating);
    }

    if (_isAnimating) {
        TraceWarning(TAG,
                     L"setContentSize change scroll content size when animation is in flight, !!!NOT supported!!!, consider "
                     L"changeConteSize only when animating isn't in process");
    }

    if (_contentSize.width != size.width || _contentSize.height != size.height) {
        _contentSize = size;

        _contentCanvas.width = fmax(size.width, self.frame.size.width);
        _contentCanvas.height = fmax(size.height, self.frame.size.height);

        // updateLayout is required to update the xaml visual for content size change
        [_scrollViewer updateLayout];
        [self setNeedsLayout];
    }

    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG,
                     L"setContentSize-end, contenSize=[%f, %f], CanvasSize=[%f, %f], ContentOffset=[%f, %f]",
                     _contentSize.width,
                     _contentSize.height,
                     _contentCanvas.width,
                     _contentCanvas.height,
                     _contentOffset.x,
                     _contentOffset.y);
    }
}

/**
 @Status Interoperable
*/
- (CGSize)contentSize {
    return _contentSize;
}

/**
 @Status Interoperable
*/
- (CGPoint)contentOffset {
    return _contentOffset;
}

/**
 @Status Interoperable
*/
- (void)setContentOffset:(CGPoint)offset {
    if (_isChangingContentOffset) {
        TraceWarning(TAG, L"setContentOffset: waiting for scrollviewer to finish scroling before setting new contentOffset property");
        return;
    }

    changeContentOffset(self, offset, NO, false);
}

static void clipPoint(UIScrollView* o, CGPoint& p, bool bounce = true) {
    CGRect bounds;
    bounds = [o bounds];

    bool bounceVertical = false;
    bool bounceHorizontal = false;

    if (bounce) {
        if (o->_contentSize.width > bounds.size.width) {
            bounceHorizontal = true;
        }
        if (o->_contentSize.height > bounds.size.height) {
            bounceVertical = true;
        }
    }

    if (!bounceHorizontal) {
        clamp((float&)p.x, findMinX(o), max(findMaxX(o), findMinX(o)));
    }
    if (!bounceVertical) {
        clamp((float&)p.y, findMinY(o), max(findMaxY(o), findMinY(o)));
    }
}

- (void)_refreshOrigin {
    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG, L"refreshOrigin");
    }

    [self.layer setOrigin:_contentOffset];
    [self setNeedsLayout];

    if ([self.delegate respondsToSelector:@selector(scrollViewDidScroll:)]) {
        [self.delegate scrollViewDidScroll:self];
    }
}

static void changeContentOffset(UIScrollView* self, CGPoint offset, BOOL animated, bool kvo = true) {
    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG,
                     L"changeContentOffset: from currentOffset=[%f, %f] to targetOffset=[%f, %f], animated=%d, kvo=%d",
                     self->_contentOffset.x,
                     self->_contentOffset.y,
                     offset.x,
                     offset.y,
                     animated,
                     kvo);
    }

    const double paddedOffsetX = (double)(offset.x + self->_contentInset.left);
    const double paddedOffsetY = (double)(offset.y + self->_contentInset.top);
    const float zoomFactor = 1.0;
    const double actualOffsetX = self->_scrollViewer.horizontalOffset;
    const double actualOffsetY = self->_scrollViewer.verticalOffset;

    if (animated == NO) {
        if (self->_contentOffset != offset) {
            if (kvo) {
                setContentOffsetKVOed(self, offset);
            } else {
                self->_contentOffset = offset;
            }

            [self _refreshOrigin];

            if (!self->_scrollingTriggeredByScrollviewer) {
                self->_scrollingTriggeredByScrollviewer = YES;

                if (DEBUG_VERBOSE) {
                    TraceVerbose(TAG,
                                 L"changeContentOffset (without Animation): from [%f, %f] to [%f, %f], ScrollviewerOffset=[%f, %f], "
                                 L"contentsize = [%f, %f]",
                                 self->_contentOffset.x,
                                 self->_contentOffset.y,
                                 paddedOffsetX,
                                 paddedOffsetY,
                                 actualOffsetX,
                                 actualOffsetY,
                                 self->_contentSize.width,
                                 self->_contentSize.height);
                }

                if (paddedOffsetX != actualOffsetX || paddedOffsetY != actualOffsetY) {
                    self->_isChangingContentOffset = YES;
                    TraceVerbose(TAG,
                                 L"_isChangingContentOffset set to %d changeContentOffset (without Animation)",
                                 self->_isChangingContentOffset);
                    
                    BOOL changeViewSucceed = [self->_scrollViewer changeViewWithOptionalAnimation:[NSNumber numberWithDouble:paddedOffsetX]
                                                               verticalOffset:[NSNumber numberWithFloat:paddedOffsetY]
                                                                   zoomFactor:[NSNumber numberWithDouble:zoomFactor]
                                                             disableAnimation:!animated];
                    if (!changeViewSucceed) {
                        TraceWarning(TAG,
                                     L"changeViewWithOptionalAnimation failed, self->_scrollViewer.Visibility = %d, loaded=%d",
                                     self->_scrollViewer.visibility,
                                     self->_loaded);
                        self->_isChangingContentOffset = NO;
                    } else {
                        [self->_scrollViewer updateLayout];
                    }
                }
            }
        }
    } else {
        if (self->_contentOffset != offset) {
            // changeContentOffset is coming through the API call, we need trigger scrollviewer to scroll.
            // mark the scrolling is caused by Scrollviewer
            self->_scrollingTriggeredByScrollviewer = YES;

            if (DEBUG_VERBOSE) {
                TraceVerbose(TAG,
                             L"changeContentOffset (with Animation): Before changing: _contentOffset=[%f,%f], _contentSize=[%f,%f], "
                             L"targetOffset=[%f,%f], acutalScrollviewerOffset=[%f, %f]",
                             self->_contentOffset.x,
                             self->_contentOffset.y,
                             self->_contentSize.width,
                             self->_contentSize.height,
                             paddedOffsetX,
                             paddedOffsetY,
                             actualOffsetX,
                             actualOffsetY);
            }

            [self->_scrollViewer cancelDirectManipulations];
            self->_isChangingContentOffset = YES;
            TraceVerbose(TAG,
                         L"_isChangingContentOffset set to %d in changeContentOffset (with Animation) ",
                         self->_isChangingContentOffset);
            BOOL changeViewSucceed = [self->_scrollViewer changeViewWithOptionalAnimation:[NSNumber numberWithDouble:paddedOffsetX]
                                                       verticalOffset:[NSNumber numberWithFloat:paddedOffsetY]
                                                           zoomFactor:[NSNumber numberWithDouble:zoomFactor]
                                                     disableAnimation:!animated];
            if (!changeViewSucceed) {
                TraceWarning(TAG,
                             L"changeViewWithOptionalAnimation failed, self->_scrollViewer.Visibility = %d, loaded=%d",
                             self->_scrollViewer.visibility,
                             self->_loaded);
                self->_isChangingContentOffset = NO;
            }
        }
    }
}

/**
 @Status Interoperable
*/
- (void)setContentOffset:(CGPoint)offset animated:(BOOL)animated {
    if (_isChangingContentOffset) {
        TraceWarning(TAG, L"setContentOffset: waiting for scrollviewer to finish scroling before setting new contentOffset");
        return;
    }

    if (DEBUG_VERBOSE) {
        double actualOffsetX = self->_scrollViewer.horizontalOffset;
        double actualOffsetY = self->_scrollViewer.verticalOffset;
        TraceVerbose(TAG,
                     L"setContentOffset: from [%f,%f] to [%f,%f], actualOffset=[%f, %f], animated=%d",
                     _contentOffset.x,
                     _contentOffset.y,
                     offset.x,
                     offset.y,
                     actualOffsetX,
                     actualOffsetY,
                     animated);
    }

    changeContentOffset(self, offset, animated, false);
}

/**
 @Status Interoperable
*/
- (void)setShowsHorizontalScrollIndicator:(BOOL)show {
    if (show) {
        _scrollViewer.horizontalScrollBarVisibility = WXCScrollBarVisibilityAuto;
        _previousHorizontalScrollBarVisibility = WXCScrollBarVisibilityAuto;
    } else {
        _scrollViewer.horizontalScrollBarVisibility = WXCScrollBarVisibilityHidden;
        _previousHorizontalScrollBarVisibility = WXCScrollBarVisibilityHidden;
    }
}

/**
 @Status Interoperable
*/
- (void)setShowsVerticalScrollIndicator:(BOOL)show {
    if (show) {
        _scrollViewer.verticalScrollBarVisibility = WXCScrollBarVisibilityAuto;
        _previousVerticalScrollBarVisibility = WXCScrollBarVisibilityAuto;
    } else {
        _scrollViewer.verticalScrollBarVisibility = WXCScrollBarVisibilityHidden;
        _previousVerticalScrollBarVisibility = WXCScrollBarVisibilityHidden;
    }
}

/**
 @Status Stub
*/
- (void)setScrollsToTop:(BOOL)scrollsToTop {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)scrollRectToVisible:(CGRect)rect animated:(BOOL)animated {
    CGRect contentRect = { 0, 0, _contentSize.width, _contentSize.height };
    CGRect visibleRect = { 0 };

    visibleRect = [self bounds];
    CGRect goalRect;

    goalRect = CGRectIntersection(rect, contentRect);

    if (!CGRectIsNull(goalRect) && !CGRectContainsRect(visibleRect, goalRect)) {
        goalRect.size.width = min(goalRect.size.width, visibleRect.size.width);
        goalRect.size.height = min(goalRect.size.height, visibleRect.size.height);

        CGPoint offset = _contentOffset;

        if (CGRectGetMaxY(goalRect) > CGRectGetMaxY(visibleRect)) {
            offset.y += CGRectGetMaxY(goalRect) - CGRectGetMaxY(visibleRect);
        } else if (CGRectGetMinY(goalRect) < CGRectGetMinY(visibleRect)) {
            offset.y += CGRectGetMinY(goalRect) - CGRectGetMinY(visibleRect);
        }

        if (CGRectGetMaxX(goalRect) > CGRectGetMaxX(visibleRect)) {
            offset.x += CGRectGetMaxX(goalRect) - CGRectGetMaxX(visibleRect);
        } else if (CGRectGetMinX(goalRect) < CGRectGetMinX(visibleRect)) {
            offset.x += CGRectGetMinX(goalRect) - CGRectGetMinX(visibleRect);
        }

        if (offset.x > findMaxX(self)) {
            offset.x = findMaxX(self);
        }
        if (offset.x < findMinX(self)) {
            offset.x = findMinX(self);
        }
        if (offset.y > findMaxY(self)) {
            offset.y = findMaxY(self);
        }
        if (offset.y < findMinY(self)) {
            offset.y = findMinY(self);
        }

        [self setContentOffset:offset animated:animated];
    }
}

/**
 @Status Stub
*/
- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (BOOL)isDragging {
    return _isDragging;
}

/**
 @Status Interoperable
*/
- (BOOL)isZooming {
    return _isZooming;
}

/**
 @Status Interoperable
*/
- (BOOL)isTracking {
    return _isTracking;
}

/**
 @Status Interoperable
*/
- (BOOL)isDecelerating {
    return _decelerating;
}

/**
 @Status Stub
*/
- (float)decelerationRate {
    UNIMPLEMENTED();
    return 0.998f;
}

/**
 @Status Stub
*/
- (void)flashScrollIndicators {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (void)setMaximumZoomScale:(float)scale {
    _maximumZoomScale = scale;
    float newScale = _zoomScale;
    clamp(newScale, _minimumZoomScale, _maximumZoomScale);
    [self setZoomScale:newScale];
}

/**
 @Status Interoperable
*/
- (float)maximumZoomScale {
    return _maximumZoomScale;
}

/**
 @Status Interoperable
*/
- (void)setMinimumZoomScale:(float)scale {
    _minimumZoomScale = scale;
    if (_minimumZoomScale > _maximumZoomScale) {
        _maximumZoomScale = _minimumZoomScale;
    }
    float newScale = _zoomScale;
    clamp(newScale, _minimumZoomScale, _maximumZoomScale);
    [self setZoomScale:newScale];
}

/**
 @Status Interoperable
*/
- (float)minimumZoomScale {
    return _minimumZoomScale;
}

- (void)_zoomStopped {
    if ([self.delegate respondsToSelector:@selector(scrollViewDidEndZooming:withView:atScale:)]) {
        [self.delegate scrollViewDidEndZooming:self withView:_zoomView atScale:_zoomScale];
    }
}

static void setZoomTo(UIScrollView* self, float scale, BOOL animated) {
    float oldZoom = self->_zoomScale;
    self->_zoomScale = scale;

    UIView* view = self;
    if ([self.delegate respondsToSelector:@selector(viewForZoomingInScrollView:)]) {
        view = [self.delegate viewForZoomingInScrollView:self];
        self->_zoomView = view;
    }

    if (animated) {
        if ([self.delegate respondsToSelector:@selector(scrollViewWillBeginZooming:withView:)]) {
            [self.delegate scrollViewWillBeginZooming:self withView:self->_zoomView];
        }

        [UIView beginAnimations:@"ZoomAnimation" context:nil];
        [UIView setAnimationDelegate:self];
        [UIView setAnimationDidStopSelector:@selector(_zoomStopped)];
        [UIView setAnimationDuration:0.3];
    }

    CGAffineTransform trans;
    trans = CGAffineTransformMakeScale(self->_zoomScale, self->_zoomScale);
    if (self->_zoomView != nil) {
        [view setTransform:trans];

        CGRect frame;
        frame = [view frame];

        [self setContentSize:CGSizeMake(frame.size.width, frame.size.height)];
        clipPoint(self, self->_contentOffset, false);
        [self _refreshOrigin];
        CGPoint oldPos, newPos;
        oldPos = [[view layer] position];
        newPos.x = frame.size.width / 2.0f;
        newPos.y = frame.size.height / 2.0f;

        [self setNeedsLayout];
        [self layoutIfNeeded];

        // This breaks Salmaan's sample app and doesn't really make a lot of sense but I want to keep it
        // in here because it's apparently useful for other apps: document better.
        /*
        CGPoint curPos;
        curPos = [[view layer] position];
        if ( curPos.x == oldPos.x && curPos.y == oldPos.y ) {
        [[view layer] setPosition:newPos];
        }
        */
    } else {
        CGRect bounds;
        bounds = [view bounds];

        [view setTransform:trans];

        bounds.size.width = bounds.size.width * oldZoom / self->_zoomScale;
        bounds.size.height = bounds.size.height * oldZoom / self->_zoomScale;
        [view setBounds:bounds];

        clipPoint(self, self->_contentOffset, false);
        [self _refreshOrigin];

        [self setNeedsLayout];
        [self layoutIfNeeded];
    }

    if ([self.delegate respondsToSelector:@selector(scrollViewDidZoom:)]) {
        [self.delegate scrollViewDidZoom:self];
    }

    if (animated) {
        [UIView commitAnimations];
    }
    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)setZoomScale:(float)scale animated:(BOOL)animated {
    clamp((float&)scale, _minimumZoomScale, _maximumZoomScale);
    if (scale == _zoomScale) {
        return;
    }

    _isZoomingToRect = TRUE;
    setZoomTo(self, scale, animated);
    _isZoomingToRect = FALSE;
}

/**
 @Status Interoperable
*/
- (void)setZoomScale:(float)scale {
    [self setZoomScale:scale animated:FALSE];
}

// Internal set content offset that notifies the KVO stuff but doesn't do
// any of the external-facing content offset changing behaviour (stopping
// scrolling and killing gestures).
static void setContentOffsetKVOed(UIScrollView* self, CGPoint offs) {
    self->_contentOffset = offs;
    changeContentOffset(self, offs, NO, false);
}

/**
 @Status Interoperable
*/
- (void)zoomToRect:(CGRect)rect animated:(BOOL)animated {
    CGRect bounds;
    bounds = [self bounds];

    float scaleX = bounds.size.width / rect.size.width;
    float scaleY = bounds.size.height / rect.size.height;

    float newScale = min(scaleX, scaleY);
    clamp(newScale, _minimumZoomScale, _maximumZoomScale);

    setContentOffsetKVOed(self, rect.origin * newScale);
    _isZoomingToRect = TRUE;
    [self setZoomScale:newScale animated:animated];
    clipPoint(self, _contentOffset, false);
    _isZoomingToRect = FALSE;
}

/**
 @Status Interoperable
*/
- (float)zoomScale {
    return _zoomScale;
}

/**
 @Status Stub
*/
- (void)setDecelerationRate:(float)rate {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setBouncesZoom:(BOOL)bounces {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setScrollIndicatorInsets:(UIEdgeInsets)insets {
    UNIMPLEMENTED();
    _scrollIndicatorInsets = insets;
}

/**
 @Status Stub
*/
- (UIEdgeInsets)scrollIndicatorInsets {
    UNIMPLEMENTED();
    return _scrollIndicatorInsets;
}

/**
 @Status Interoperable
*/
- (void)setContentInset:(UIEdgeInsets)inset {
    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG,
                     L"setContentInset: [top, right, bottom, left] = [%f, %f, %f, %f]",
                     inset.top,
                     inset.right,
                     inset.bottom,
                     inset.left);
    }

    if (memcmp(&_contentInset, &inset, sizeof(UIEdgeInsets)) == 0) {
        return;
    }

    _contentInset = inset;
    _topInset.height = (double)inset.top;
    _topInset.width = (double)1;

    _rightInset.width = (double)inset.right;
    _rightInset.height = (double)1;

    _bottomInset.height = (double)inset.bottom;
    _bottomInset.width = (double)1;

    _leftInset.width = (double)inset.left;
    _leftInset.height = (double)1;

    if (DEBUG_INSETS) {
        // setting different color on insets for debugging
        _topInset.fill = [WUXMSolidColorBrush makeInstanceWithColor:ConvertUIColorToWUColor([UIColor redColor])];
        _bottomInset.fill = [WUXMSolidColorBrush makeInstanceWithColor:ConvertUIColorToWUColor([UIColor blueColor])];
        _leftInset.fill = [WUXMSolidColorBrush makeInstanceWithColor:ConvertUIColorToWUColor([UIColor redColor])];
        _rightInset.fill = [WUXMSolidColorBrush makeInstanceWithColor:ConvertUIColorToWUColor([UIColor blueColor])];
    }
}

- (void)_clampOffset {
    CGPoint curOffset = _contentOffset;
    clipPoint(self, curOffset, false);

    if (curOffset != _contentOffset) {
        [self setContentOffset:curOffset animated:NO];
    }
}

/**
 @Status Stub
*/
- (void)setIndicatorStyle:(UIScrollViewIndicatorStyle)style {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setDirectionalLockEnabled:(BOOL)enabled {
    UNIMPLEMENTED();
}

/**
 @Status Stub
*/
- (void)setCanCancelContentTouches:(BOOL)canCancel {
    UNIMPLEMENTED();
    _canCancelContentTouches = canCancel;
}

/**
 @Status Interoperable
*/
- (UIEdgeInsets)contentInset {
    return _contentInset;
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    _zoomView = nil;
    _pinchGesture = nil;

    [_scrollViewer removeDirectManipulationStartedEvent:_directManipulationStartedEventToken];
    [_scrollViewer removeDirectManipulationCompletedEvent:_directManipulationCompletedEventToken];
    [_scrollViewer removeViewChangingEvent:_viewChangingEventToken];
    [_scrollViewer removeViewChangedEvent:_viewChangedEventToken];
    [_scrollViewer removeLoadedEvent:_loadEventToken];
}

/**
 @Status Interoperable
*/
- (void)willMoveToWindow:(id)newWindow {
    [super willMoveToWindow:newWindow];
}

static float findMaxX(UIScrollView* o) {
    CGRect bounds;
    bounds = [o bounds];
    float ret = o->_contentSize.width - bounds.size.width + o->_contentInset.right;
    if (ret < findMinX(o)) {
        ret = findMinX(o);
    }

    return ret;
}

static float findMaxY(UIScrollView* o) {
    CGRect bounds;
    bounds = [o bounds];

    float ret = o->_contentSize.height - bounds.size.height + o->_contentInset.bottom;
    if (ret < findMinY(o)) {
        ret = findMinY(o);
    }

    return ret;
}

static float findMinX(UIScrollView* o) {
    return -o->_contentInset.left;
}

static float findMinY(UIScrollView* o) {
    return -o->_contentInset.top;
}

- (void)touchesEnded:(NSSet*)touches withEvent:(UIEvent*)event {
    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG, L"touchesEnded isDragging=%d, pagingEnabled=%d", _isDragging, _pagingEnabled);
    }

    _isTracking = NO;
}

- (void)_didPinch:(UIPinchGestureRecognizer*)gesture {
    if (_minimumZoomScale == _maximumZoomScale) {
        return;
    }

    UIGestureRecognizerState state = [gesture state];
    UIView* view = self;

    if ([self.delegate respondsToSelector:@selector(viewForZoomingInScrollView:)]) {
        view = [self.delegate viewForZoomingInScrollView:self];
    }
    if (state == UIGestureRecognizerStateBegan) {
        //  Cancel any other pans
        [_pinchGesture setScale:_zoomScale];
        _isZooming = true;
        [self setNeedsLayout];
    } else if (state == UIGestureRecognizerStateEnded || state == UIGestureRecognizerStatePossible) {
        BOOL fireEvent = _isZooming;
        _isZooming = false;

        if (fireEvent) {
            if ([self.delegate respondsToSelector:@selector(scrollViewDidEndZooming:withView:atScale:)]) {
                [self.delegate scrollViewDidEndZooming:self withView:view atScale:_zoomScale];
            }
        }
    } else if (state == UIGestureRecognizerStateChanged) {
        CGFloat scale = [static_cast<UIPinchGestureRecognizer*>(gesture) scale];
        clamp(scale, _minimumZoomScale, _maximumZoomScale);
        if (scale == _zoomScale) {
            return;
        }

        CGPoint start = _contentOffset, pinchPoint;
        pinchPoint = [gesture locationInView:self];
        CGPoint diff = pinchPoint - _contentOffset;

        CGRect viewBounds;
        viewBounds = [self bounds];

        CGRect bounds;
        bounds = [self bounds];

        double relativeScale = ((double)scale / (double)_zoomScale);
        //_contentOffset = start * relativeScale + diff * (1 - 1 / relativeScale);
        _contentOffset = ((view == self) ? start : (start * scale / _zoomScale)) + diff * ((float)(1.0 - 1.0 / relativeScale));
        clamp((float&)_contentOffset.x,
              (float)-_contentInset.left,
              max((float)(_contentSize.width - bounds.size.width + _contentInset.right), 0.f));
        clamp((float&)_contentOffset.y,
              (float)-_contentInset.top,
              max((float)(_contentSize.height - bounds.size.height + _contentInset.bottom), 0.f));

        if ([self.delegate respondsToSelector:@selector(scrollViewWillBeginZooming:withView:)]) {
            [self.delegate scrollViewWillBeginZooming:self withView:view];
        }
        setZoomTo(self, scale, FALSE);
    }
}

/**
 @Status Interoperable
*/
- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    [super touchesBegan:touches withEvent:event];
    _isTracking = YES;
}

/**
 @Status Stub
*/
- (BOOL)touchesShouldBegin:(NSSet*)touches withEvent:(UIEvent*)event inContentView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (BOOL)touchesShouldCancelInContentView:(UIView*)view {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (id<CAAction>)actionForLayer:(CALayer*)layer forKey:(NSString*)key {
    if (_isZoomingToRect) {
        return [super actionForLayer:layer forKey:key];
    }

    char* keyName = (char*)[key UTF8String];
    if (strcmp(keyName, "bounds.origin") == 0) {
        return (id<CAAction>)[NSNull null];
    }
    if (strcmp(keyName, "bounds") == 0) {
        return [super actionForLayer:layer forKey:@"bounds.size"];
    }

    return [super actionForLayer:layer forKey:key];
}

/**
 @Status Stub
*/
- (UIPinchGestureRecognizer*)pinchGestureRecognizer {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (UIPanGestureRecognizer*)panGestureRecognizer {
    UNIMPLEMENTED();
    return StubReturn();
}

+ (Class)layerClass {
    return [_UIScrollViewCALayer class];
}

@end
