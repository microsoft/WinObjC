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

#import <UIKit/UIApplication.h>
#import <UIKit/UIColor.h>
#import <UIKit/UIEvent.h>
#import <UIKit/UITouch.h>
#import <UIKit/UIGestureRecognizer.h>
#import <UIKit/UIScrollView.h>

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
#import <QuartzCore/CALayerDelegate.h>

#include "COMIncludes.h"
#import <winrt/Windows.UI.Xaml.Shapes.h>
#include "COMIncludes_End.h"

#import "_UIDirectManipulationRecognizer.h"
#import "CAAnimationInternal.h"
#import "CALayerInternal.h"
#import "StarboardXaml/DisplayProperties.h"
#import "UIEventInternal.h"
#import "UIViewInternal.h"
#import "UIScrollViewInternal.h"
#import "UIGestureRecognizerInternal.h"
#import "UIPanGestureRecognizerInternal.h"
#import "UITouchInternal.h"
#import "Etc.h"
#import "XamlControls.h"
#import "XamlUtilities.h"
#import "CppWinRTHelpers.h"
#import <cmath>

using namespace winrt::Windows::UI::Xaml;
namespace WF = winrt::Windows::Foundation;

static const wchar_t* TAG = L"UIScrollView";

static const bool DEBUG_ALL = false;
static const bool DEBUG_VERBOSE = DEBUG_ALL || false;
static const bool DEBUG_DELEGATE = DEBUG_ALL || false;
static const bool DEBUG_ZOOM = DEBUG_ALL || false;
static const bool DEBUG_DMANIP_GESTURE = DEBUG_ALL || false;

/** @Status Stub */
const float UIScrollViewDecelerationRateNormal = StubConstant();
/** @Status Stub */
const float UIScrollViewDecelerationRateFast = StubConstant();

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

    idretain _zoomView;
    float _zoomScale;
    BOOL _isZooming;
    BOOL _isZoomingToRect;

    // DManip gesture recognizer, used for detecting if DManip should start or not
    StrongId<_UIDMPanGestureRecognizer> _dManipGesture;

    // xaml visuals to back UIScrollView - includes Scrollviewer, ContentGrid, Insets, and ContentCanvas
    TrivialDefaultConstructor<Controls::ScrollViewer> _scrollViewer;
    TrivialDefaultConstructor<Controls::Canvas> _contentCanvas;

    winrt::event_token _directManipulationStartedEventToken;
    winrt::event_token _directManipulationCompletedEventToken;
    winrt::event_token _viewChangingEventToken;
    winrt::event_token _viewChangedEventToken;
    winrt::event_token _loadEventToken;

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
    Controls::ScrollBarVisibility _previousHorizontalScrollBarVisibility;

    // when scrolling is disabled, recording the previous vertical scrollbar visibility
    Controls::ScrollBarVisibility _previousVerticalScrollBarVisibility;
}

- (id)_dManipGestureCallback:(_UIDMPanGestureRecognizer*)gesture {
    if (DEBUG_DMANIP_GESTURE) {
        TraceVerbose(TAG, L"_dManipGestureCallback fired");
    }

    // check the gesture state, if it is already being cancelled, don't start direct manipulation
    if (gesture.state == UIGestureRecognizerStateCancelled) {
        if (DEBUG_DMANIP_GESTURE) {
            TraceVerbose(TAG, L"dManipGesture cancelled");
        }

        return self;
    }

    // setting manipulationMode of scrollview (on its canvas) chain to be System.
    // so that direct manipulation will be effective on all scrollviews
    [self _setManipulationMode:Input::ManipulationModes::System recursive:YES];

    for (auto const& pointer : [gesture _getTouches]) {
        UITouch* touch = pointer.touch;
        // start direct manipulation only if active touch presents
        if (touch.phase != UITouchPhaseCancelled && touch.phase != UITouchPhaseEnded &&
            touch->_routedEventArgs.Pointer().PointerDeviceType() == winrt::Windows::Devices::Input::PointerDeviceType::Touch) {
            if (!UIElement::TryStartDirectManipulation(touch->_routedEventArgs.Pointer())) {
                TraceWarning(TAG, L"DManip failed to start");
            }
        }
    }

    return self;
}

- (void)_initUIScrollView {
    FrameworkElement scrollView = [self _winrtXamlElement];
    if (!scrollView) {
        FAIL_FAST();
    }

    _scrollViewer = XamlControls::ScrollViewGetInnerScrollViewer(scrollView);
    if (!_scrollViewer) {
        // Definitely didn't receive any supported backing xaml elements
        FAIL_FAST();
    }

    self->_dManipGesture = [[_UIDMPanGestureRecognizer alloc] initWithTarget:self action:@selector(_dManipGestureCallback:)];
    [self addGestureRecognizer:self->_dManipGesture];

    [self setMultipleTouchEnabled:TRUE];

    // Grab the content canvas for our subviews
    _contentCanvas = XamlControls::ScrollViewGetSubLayerCanvas(scrollView);

    _loaded = NO;

    // setting up manipulation, viewchanging and viewchanged event handlers
    [self _setupManipulationEventHandlers];
    [self _setupViewChangingHandler];
    [self _setupViewChangedHandler];
    [self _setupLoadedEventHandler];

    // initial states of internal flags
    _isChangingContentOffset = NO;
    _previousHorizontalScrollBarVisibility = Controls::ScrollBarVisibility::Auto;
    _previousVerticalScrollBarVisibility = Controls::ScrollBarVisibility::Auto;
    _scrollingTriggeredByScrollviewer = NO;
    _isAnimating = NO;
    _manipulationStarted = NO;
    _decelerating = NO;
    _firedDelegatesAfterFingerLifted = NO;
    _contentOffset = CGPointZero;

    // init zoom scale
    self->_zoomScale = 1.0f;

    // by default, disable direct manipulation on backing scrollviewer
    [self _setManipulationMode:Input::ManipulationModes::All recursive:NO];
}

- (BOOL)_isAnimating {
    return _isAnimating;
}

- (void)_setupViewChangingHandler {
    __weak UIScrollView* weakself = self;
    _viewChangingEventToken = _scrollViewer.ViewChanging(objcwinrt::callback([weakself](
        const WF::IInspectable&, const Controls::ScrollViewerViewChangingEventArgs& arg) {
        __strong UIScrollView* strongSelf = weakself;
        if (strongSelf) {
            if (DEBUG_VERBOSE) {
                TraceVerbose(
                    TAG,
                    L"ViewChanging: currentOffset=[%f, %f], nextOffset=[%f, %f], finalOffset=[%f, %f], isAnimating=%d, "
                    L"isDragging=%d, isInertial=%d, isPagingEnabled=%d, firedDelegatesAfterFingerLifted=%d, "
                    L"manipulationStarted=%d, currentRecordedZoomFactor=%f, currentZoomFactor=%f, nextZoomFactor=%f, finalZoomFactor=%f",
                    strongSelf->_scrollViewer.HorizontalOffset(),
                    strongSelf->_scrollViewer.VerticalOffset(),
                    arg.NextView().HorizontalOffset(),
                    arg.NextView().VerticalOffset(),
                    arg.FinalView().HorizontalOffset(),
                    arg.FinalView().VerticalOffset(),
                    strongSelf->_isAnimating,
                    strongSelf->_isDragging,
                    arg.IsInertial(),
                    strongSelf->_pagingEnabled,
                    strongSelf->_firedDelegatesAfterFingerLifted,
                    strongSelf->_manipulationStarted,
                    strongSelf->_zoomScale,
                    strongSelf->_scrollViewer.ZoomFactor(),
                    arg.NextView().ZoomFactor(),
                    arg.FinalView().ZoomFactor());
            }

            // check if content offset changed, if so, we are scrolling.
            if ((strongSelf->_scrollViewer.HorizontalOffset() != arg.NextView().HorizontalOffset()) ||
                (strongSelf->_scrollViewer.VerticalOffset() != arg.FinalView().VerticalOffset())) {
                // view is about to change its position (or scrolling)
                if (strongSelf->_manipulationStarted) {
                    if (!arg.IsInertial()) {
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
                                // cancel the direct manipulation before we do manual animating to page boundary
                                strongSelf->_scrollViewer.CancelDirectManipulations();

                                // re-caculate scrolling boundary based on the predicted finalview offset
                                CGRect bound = [strongSelf bounds];
                                CGPoint offset;
                                if (strongSelf->_scrollViewer.HorizontalOffset() != arg.NextView().HorizontalOffset()) {
                                    int curScrollPage =
                                        int((arg.FinalView().HorizontalOffset() + bound.size.width / 2.0f) / bound.size.width);
                                    offset = { curScrollPage * bound.size.width, 0 };

                                } else {
                                    int curScrollPage =
                                        int((arg.FinalView().VerticalOffset() + bound.size.height / 2.0f) / bound.size.height);
                                    offset = { 0, curScrollPage * bound.size.height };
                                }

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
                                CGPoint offset = { arg.FinalView().HorizontalOffset(), arg.FinalView().VerticalOffset() };
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
            } else {
                // zooming is happening
                if (strongSelf->_manipulationStarted) {
                    // user is causing zooming using gesture
                    if (!strongSelf->_isZooming) {
                        strongSelf->_isZooming = YES;

                        // invoking scrollViewWillBeginZooming delegate, note: this delegate is only called with zoom gesture when zooming
                        // happens
                        if ([strongSelf.delegate respondsToSelector:@selector(scrollViewWillBeginZooming:withView:)]) {
                            [strongSelf.delegate scrollViewWillBeginZooming:strongSelf withView:strongSelf->_zoomView];
                        }
                    }
                }
            }
        }
    }));
}

- (void)_setupViewChangedHandler {
    __weak UIScrollView* weakself = self;
    _viewChangedEventToken = _scrollViewer.ViewChanged(objcwinrt::callback([weakself](
        const WF::IInspectable&, const Controls::ScrollViewerViewChangedEventArgs& arg) {
        __strong UIScrollView* strongSelf = weakself;
        if (strongSelf) {
            // when we get notification from scrollviewer, associated offset contains insets
            // we need to discount it before change the offset on UIScrollvew
            CGPoint offset;
            offset.x = strongSelf->_scrollViewer.HorizontalOffset() - strongSelf->_contentInset.left;
            offset.y = strongSelf->_scrollViewer.VerticalOffset() - strongSelf->_contentInset.top;

            if (DEBUG_VERBOSE) {
                TraceVerbose(TAG,
                             L"ViewChanged: interm=%d, currentOffset=[%f, %f], nextOffset=[%f, %f], zoomFactor=%f, contentSize=[%f, %f]",
                             arg.IsIntermediate(),
                             strongSelf->_contentOffset.x,
                             strongSelf->_contentOffset.y,
                             offset.x,
                             offset.y,
                             strongSelf->_scrollViewer.ZoomFactor(),
                             strongSelf->_contentSize.width,
                             strongSelf->_contentSize.height);
            }

            if (arg.IsIntermediate()) {
                // intermedia view changed event
                changeContentOffset(strongSelf, offset, FALSE);

                // check if zoom changed as well
                if (strongSelf->_scrollViewer.ZoomFactor() != strongSelf->_zoomScale) {
                    strongSelf->_zoomScale = strongSelf->_scrollViewer.ZoomFactor();

                    // when zoom scale changed, fire this delegate
                    if ([strongSelf.delegate respondsToSelector:@selector(scrollViewDidZoom:)]) {
                        [strongSelf.delegate scrollViewDidZoom:strongSelf];
                    }
                }
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
                if (strongSelf->_scrollViewer.ZoomFactor() != strongSelf->_zoomScale) {
                    strongSelf->_zoomScale = strongSelf->_scrollViewer.ZoomFactor();
                }

                if (strongSelf->_isZooming) {
                    // zooming is ended
                    strongSelf->_isZooming = NO;
                    if ([strongSelf.delegate respondsToSelector:@selector(scrollViewDidEndZooming:withView:atScale:)]) {
                        [strongSelf.delegate scrollViewDidEndZooming:strongSelf
                                                            withView:strongSelf->_zoomView
                                                             atScale:strongSelf->_zoomScale];
                    }
                }

                strongSelf->_scrollingTriggeredByScrollviewer = NO;
                strongSelf->_isChangingContentOffset = NO;
                if (DEBUG_VERBOSE) {
                    TraceVerbose(TAG,
                                 L"in view changed listener: _isChangingContentOffset set to %d in viewchanged final",
                                 strongSelf->_isChangingContentOffset);
                }
            }
        }
    }));
}

- (void)_setupManipulationEventHandlers {
    __weak UIScrollView* weakself = self;
    _directManipulationStartedEventToken =
        _scrollViewer.DirectManipulationStarted(objcwinrt::callback([weakself](const WF::IInspectable&, const WF::IInspectable&) {
            __strong UIScrollView* strongSelf = weakself;
            if (DEBUG_VERBOSE) {
                TraceVerbose(TAG, L"DirectManipulation----Started");
            }

            if (strongSelf) {
                strongSelf->_manipulationStarted = YES;
            }
        }));

    _directManipulationCompletedEventToken =
        _scrollViewer.DirectManipulationCompleted(objcwinrt::callback([weakself](const WF::IInspectable&, const WF::IInspectable&) {
            __strong UIScrollView* strongSelf = weakself;
            if (DEBUG_VERBOSE) {
                TraceVerbose(TAG, L"DirectManipulation----Completed");
            }

            if (strongSelf) {
                // re-setting manipulationMode of scrollview (on its canvas) chain to be ALL.
                // so that direct manipulation will be disabled on all scrollviews
                [strongSelf _setManipulationMode:Input::ManipulationModes::All recursive:YES];
                strongSelf->_manipulationStarted = NO;
                strongSelf->_isTracking = NO;
                strongSelf->_isDragging = NO;
            }
        }));
}

- (void)_setupLoadedEventHandler {
    __weak UIScrollView* weakSelf = self;
    _loadEventToken = self->_scrollViewer.Loaded(objcwinrt::callback([weakSelf](const WF::IInspectable&, const RoutedEventArgs&) {
        __strong UIScrollView* strongSelf = weakSelf;
        if (strongSelf && (strongSelf->_contentOffset != CGPointZero || strongSelf->_zoomScale != strongSelf->_scrollViewer.ZoomFactor())) {
            strongSelf->_loaded = YES;

            const double paddedOffsetX = (double)(strongSelf->_contentOffset.x + strongSelf->_contentInset.left);
            const double paddedOffsetY = (double)(strongSelf->_contentOffset.y + strongSelf->_contentInset.top);
            BOOL changeViewSucceed = strongSelf->_scrollViewer.ChangeView(objcwinrt::optional(paddedOffsetX),
                                                                          objcwinrt::optional(paddedOffsetY),
                                                                          objcwinrt::optional(strongSelf->_zoomScale),
                                                                          true);
            if (!changeViewSucceed) {
                TraceWarning(TAG,
                             L"changeViewWithOptionalAnimation failed, self->_scrollViewer.Visibility = %d",
                             strongSelf->_scrollViewer.Visibility());

            } else {
                strongSelf->_scrollViewer.UpdateLayout();
                [strongSelf setNeedsLayout];
            }
        }
    }));
}

/**
 @Status Caveat
 @Notes May not be fully implemented
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        [self _initUIScrollView];

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
    return [self initWithFrame:frame xamlElement:nil];
}

/**
 Microsoft Extension
*/
- (instancetype)initWithFrame:(CGRect)frame xamlElement:(RTObject*)xamlElement {
    if (self = [super initWithFrame:frame xamlElement:xamlElement]) {
        [self _initUIScrollView];
        [self setClipsToBounds:1];
        _delaysContentTouches = TRUE;
    }

    return self;
}

/**
 Microsoft Extension
*/
+ (RTObject*)createXamlElement {
    return objcwinrt::to_rtobj(XamlControls::CreateScrollView());
}

/**
 @Status Interoperable
*/
- (void)setScrollEnabled:(BOOL)enable {
    [self _setScrollEnabled:enable];
}

- (void)_setScrollEnabled:(BOOL)enable {
    // Setting ScrollMode to Disabled and ScrollBarVisibility to Hidden allows the ScrollViewer to be programmatically scrolled
    // but doesn't let the user scroll it which replicates the iOS behavior.
    _scrollViewer.HorizontalScrollBarVisibility(enable ? _previousHorizontalScrollBarVisibility : Controls::ScrollBarVisibility::Hidden);
    _scrollViewer.HorizontalScrollMode(enable ? Controls::ScrollMode::Enabled : Controls::ScrollMode::Disabled);

    _scrollViewer.VerticalScrollBarVisibility(enable ? _previousVerticalScrollBarVisibility : Controls::ScrollBarVisibility::Hidden);
    _scrollViewer.VerticalScrollMode(enable ? Controls::ScrollMode::Enabled : Controls::ScrollMode::Disabled);
}

/**
 @Status Interoperable
*/
- (BOOL)isScrollEnabled {
    BOOL disabled = (_scrollViewer.HorizontalScrollMode() == Controls::ScrollMode::Disabled) &&
                    (_scrollViewer.VerticalScrollMode() == Controls::ScrollMode::Disabled);
    return !disabled;
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

        _contentCanvas.Width(fmax(size.width, self.frame.size.width));
        _contentCanvas.Height(fmax(size.height, self.frame.size.height));

        // updateLayout is required to update the xaml visual for content size change
        _scrollViewer.UpdateLayout();
        [self setNeedsLayout];
    }

    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG,
                     L"setContentSize-end, contenSize=[%f, %f], CanvasSize=[%f, %f], ContentOffset=[%f, %f]",
                     _contentSize.width,
                     _contentSize.height,
                     _contentCanvas.Width(),
                     _contentCanvas.Height(),
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

    [self.layer _setOrigin:_contentOffset];
    [self setNeedsLayout];

    if ([self.delegate respondsToSelector:@selector(scrollViewDidScroll:)]) {
        [self.delegate scrollViewDidScroll:self];
    }
}

static void changeContentOffset(UIScrollView* self, CGPoint offset, BOOL animated, bool kvo = true) {
    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG,
                     L"changeContentOffset: from currentOffset=[%f, %f] to targetOffset=[%f, %f], animated=%d, kvo=%d, scrollEnabled=%s",
                     self->_contentOffset.x,
                     self->_contentOffset.y,
                     offset.x,
                     offset.y,
                     animated,
                     kvo,
                     self.isScrollEnabled == YES ? L"YES" : L"NO");
    }

    const double paddedOffsetX = (double)(offset.x + self->_contentInset.left);
    const double paddedOffsetY = (double)(offset.y + self->_contentInset.top);
    const double actualOffsetX = self->_scrollViewer.HorizontalOffset();
    const double actualOffsetY = self->_scrollViewer.VerticalOffset();

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

                    bool changeViewSucceed = self->_scrollViewer.ChangeView(objcwinrt::optional(paddedOffsetX),
                                                                            objcwinrt::optional(paddedOffsetY),
                                                                            nullptr,
                                                                            !animated);
                    if (!changeViewSucceed) {
                        TraceWarning(TAG,
                                     L"changeViewWithOptionalAnimation failed, self->_scrollViewer.Visibility = %d, loaded=%d",
                                     self->_scrollViewer.Visibility(),
                                     self->_loaded);
                        self->_isChangingContentOffset = NO;
                    } else {
                        self->_scrollViewer.UpdateLayout();
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

            self->_scrollViewer.CancelDirectManipulations();
            self->_isChangingContentOffset = YES;
            TraceVerbose(TAG,
                         L"_isChangingContentOffset set to %d in changeContentOffset (with Animation) ",
                         self->_isChangingContentOffset);
            BOOL changeViewSucceed =
                self->_scrollViewer.ChangeView(objcwinrt::optional(paddedOffsetX), objcwinrt::optional(paddedOffsetY), nullptr, !animated);
            if (!changeViewSucceed) {
                TraceWarning(TAG,
                             L"changeViewWithOptionalAnimation failed, self->_scrollViewer.Visibility = %d, loaded=%d",
                             self->_scrollViewer.Visibility(),
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
        double actualOffsetX = self->_scrollViewer.HorizontalOffset();
        double actualOffsetY = self->_scrollViewer.VerticalOffset();
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
        if (self.isScrollEnabled) {
            _scrollViewer.HorizontalScrollBarVisibility(Controls::ScrollBarVisibility::Auto);
        }
        _previousHorizontalScrollBarVisibility = Controls::ScrollBarVisibility::Auto;
    } else {
        if (self.isScrollEnabled) {
            _scrollViewer.HorizontalScrollBarVisibility(Controls::ScrollBarVisibility::Hidden);
        }
        _previousHorizontalScrollBarVisibility = Controls::ScrollBarVisibility::Hidden;
    }
}

/**
@Status Interoperable
*/
- (BOOL)showsHorizontalScrollIndicator {
    return _scrollViewer.HorizontalScrollBarVisibility() != Controls::ScrollBarVisibility::Hidden;
}

/**
@Status Interoperable
*/
- (BOOL)showsVerticalScrollIndicator {
    return _scrollViewer.VerticalScrollBarVisibility() != Controls::ScrollBarVisibility::Hidden;
}

/**
 @Status Interoperable
*/
- (void)setShowsVerticalScrollIndicator:(BOOL)show {
    if (show) {
        if (self.isScrollEnabled) {
            _scrollViewer.VerticalScrollBarVisibility(Controls::ScrollBarVisibility::Auto);
        }
        _previousVerticalScrollBarVisibility = Controls::ScrollBarVisibility::Auto;
    } else {
        if (self.isScrollEnabled) {
            _scrollViewer.VerticalScrollBarVisibility(Controls::ScrollBarVisibility::Hidden);
        }
        _previousVerticalScrollBarVisibility = Controls::ScrollBarVisibility::Hidden;
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

    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG, L"scrollRectToVisible rect=[%f, %f, %f, %f]", rect.origin.x, rect.origin.y, rect.size.height, rect.size.width);
        TraceVerbose(TAG,
                     L"scrollRectToVisible contentRect=[%f, %f, %f, %f]",
                     contentRect.origin.x,
                     contentRect.origin.y,
                     contentRect.size.height,
                     contentRect.size.width);
        TraceVerbose(TAG,
                     L"scrollRectToVisible visibleRect=[%f, %f, %f, %f]",
                     visibleRect.origin.x,
                     visibleRect.origin.y,
                     visibleRect.size.height,
                     visibleRect.size.width);
        TraceVerbose(TAG,
                     L"scrollRectToVisible goalRect=[%f, %f, %f, %f]",
                     goalRect.origin.x,
                     goalRect.origin.y,
                     goalRect.size.height,
                     goalRect.size.width);
    }

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

        if (DEBUG_VERBOSE) {
            TraceVerbose(TAG, L"scrollRectToVisible setContentOffset=[%f, %f]", offset.x, offset.y);
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
    if (_scrollViewer.MinZoomFactor() > scale) {
        _scrollViewer.MinZoomFactor(scale);
    }

    _scrollViewer.MaxZoomFactor(scale);

    _scrollViewer.ZoomMode((_scrollViewer.MinZoomFactor() != _scrollViewer.MaxZoomFactor()) ? Controls::ZoomMode::Enabled :
                                                                                              Controls::ZoomMode::Disabled);

    float newScale = _zoomScale;
    clamp(newScale, _scrollViewer.MinZoomFactor(), _scrollViewer.MaxZoomFactor());

    [self setZoomScale:newScale];
}

/**
 @Status Interoperable
*/
- (float)maximumZoomScale {
    return _scrollViewer.MaxZoomFactor();
}

/**
 @Status Interoperable
*/
- (void)setMinimumZoomScale:(float)scale {
    if (_scrollViewer.MaxZoomFactor() < scale) {
        _scrollViewer.MaxZoomFactor(scale);
    }

    _scrollViewer.MinZoomFactor(scale);

    _scrollViewer.ZoomMode((_scrollViewer.MinZoomFactor() != _scrollViewer.MaxZoomFactor()) ? Controls::ZoomMode::Enabled :
                                                                                              Controls::ZoomMode::Disabled);

    float newScale = _zoomScale;
    clamp(newScale, _scrollViewer.MinZoomFactor(), _scrollViewer.MaxZoomFactor());
    [self setZoomScale:newScale];
}

/**
 @Status Interoperable
*/
- (float)minimumZoomScale {
    return _scrollViewer.MinZoomFactor();
}

static void zoomToPoint(UIScrollView* self, NSNumber* x, NSNumber* y, NSNumber* scale, BOOL animated) {
    if (DEBUG_ZOOM) {
        TraceVerbose(TAG, L"zoomToPoint [%f, %f], zoomScale=%f", x, y, scale);
    }

    self->_zoomScale = scale.floatValue;

    UIView* view = self;
    if ([self.delegate respondsToSelector:@selector(viewForZoomingInScrollView:)]) {
        view = [self.delegate viewForZoomingInScrollView:self];
        self->_zoomView = view;
    }

    bool changeViewSucceed = self->_scrollViewer.ChangeView(x ? objcwinrt::optional(x.doubleValue) : nullptr,
                                                            y ? objcwinrt::optional(y.doubleValue) : nullptr,
                                                            scale ? objcwinrt::optional(scale.floatValue) : nullptr,
                                                            !animated);
    if (!changeViewSucceed) {
        TraceWarning(TAG, L"changeViewWithOptionalAnimation failed, self->_scrollViewer.Visibility=%d", self->_scrollViewer.Visibility());
    } else if (!animated) {
        // need to updateLayout if no animation is involved to reflect the change immeidately
        self->_scrollViewer.UpdateLayout();
    }

    [self setNeedsLayout];
}

/**
 @Status Interoperable
*/
- (void)setZoomScale:(float)scale animated:(BOOL)animated {
    clamp((float&)scale, _scrollViewer.MinZoomFactor(), _scrollViewer.MaxZoomFactor());
    if (scale == _zoomScale) {
        return;
    }

    _isZoomingToRect = TRUE;
    zoomToPoint(self, nil, nil, [NSNumber numberWithFloat:scale], animated);
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
    _isZoomingToRect = TRUE;

    CGRect bounds = [self bounds];

    if (DEBUG_ZOOM) {
        TraceVerbose(TAG,
                     L"bounds=[[%f,%f], [%f,%f]], contentOffset=[%f, %f], contentSize=[%f, %f]",
                     bounds.origin.x,
                     bounds.origin.y,
                     bounds.size.width,
                     bounds.size.height,
                     _contentOffset.x,
                     _contentOffset.y,
                     _contentSize.width,
                     _contentSize.height);
    }

    float scaleX = bounds.size.width / rect.size.width;
    float scaleY = bounds.size.height / rect.size.height;

    float newScale = min(scaleX, scaleY);
    clamp(newScale, _scrollViewer.MinZoomFactor(), _scrollViewer.MaxZoomFactor());

    zoomToPoint(self,
                [NSNumber numberWithDouble:rect.origin.x * newScale],
                [NSNumber numberWithDouble:rect.origin.y * newScale],
                [NSNumber numberWithFloat:newScale],
                animated);

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
 @Status Caveat
 @Notes UIScrollView does not support negative content insets. Clamped to 0 if insets values < 0.
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

    // Clamp inset values to 0 if they are negative
    if (inset.top < 0.0f) {
        TraceWarning(TAG, L"setContentInset: Clamping inset.top to 0");
        inset.top = 0.0f;
    }

    if (inset.right < 0.0f) {
        TraceWarning(TAG, L"setContentInset: Clamping inset.right to 0");
        inset.right = 0.0f;
    }

    if (inset.bottom < 0.0f) {
        TraceWarning(TAG, L"setContentInset: Clamping inset.bottom to 0");
        inset.bottom = 0.0f;
    }

    if (inset.left < 0.0f) {
        TraceWarning(TAG, L"setContentInset: Clamping inset.left to 0");
        inset.left = 0.0f;
    }

    _contentInset = inset;
    _contentCanvas.Margin(ThicknessHelper::FromLengths(inset.left, inset.top, inset.right, inset.bottom));
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
 @Status Interoperable
*/
- (void)setDirectionalLockEnabled:(BOOL)enabled {
    _scrollViewer.IsHorizontalRailEnabled(enabled);
    _scrollViewer.IsVerticalRailEnabled(enabled);
}

/**
 @Status Interoperable
*/
- (BOOL)isDirectionalLockEnabled {
    assert(_scrollViewer.IsHorizontalRailEnabled() == _scrollViewer.IsVerticalRailEnabled());
    return static_cast<BOOL>(_scrollViewer.IsHorizontalRailEnabled());
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

    _scrollViewer.DirectManipulationStarted(_directManipulationStartedEventToken);
    _scrollViewer.DirectManipulationCompleted(_directManipulationCompletedEventToken);
    _scrollViewer.ViewChanging(_viewChangingEventToken);
    _scrollViewer.ViewChanged(_viewChangedEventToken);
    _scrollViewer.Loaded(_loadEventToken);
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

- (void)_setManipulationMode:(Input::ManipulationModes)mode recursive:(BOOL)recursive {
    if (DEBUG_VERBOSE) {
        TraceVerbose(TAG,
                     L"_setManipulationMode: currentMode=%d, targetmode=%d, recursive=%d",
                     self->_contentCanvas.ManipulationMode(),
                     mode,
                     recursive);
    }

    if (_contentCanvas.ManipulationMode() != mode) {
        _contentCanvas.ManipulationMode(mode);

        if (recursive) {
            UIView* parent = [self superview];
            while (parent) {
                if ([parent isKindOfClass:[UIScrollView class]]) {
                    UIScrollView* parentUIScrollview = (UIScrollView*)parent;
                    [parentUIScrollview _setManipulationMode:mode recursive:NO];
                }

                parent = [parent superview];
            }
        }
    }
}

@end