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

// WindowsUIInputInkingCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUIICCoreInkIndependentInputSource;
@protocol WUIICICoreInkIndependentInputSource
, WUIICICoreInkIndependentInputSourceStatics;

#include "WindowsFoundation.h"
#include "WindowsUICore.h"
#include "WindowsUIInputInking.h"

#import <Foundation/Foundation.h>

// Windows.UI.Input.Inking.Core.CoreInkIndependentInputSource
#ifndef __WUIICCoreInkIndependentInputSource_DEFINED__
#define __WUIICCoreInkIndependentInputSource_DEFINED__

WINRT_EXPORT
@interface WUIICCoreInkIndependentInputSource : RTObject
+ (WUIICCoreInkIndependentInputSource*)create:(WUIIInkPresenter*)inkPresenter;
@property (readonly) WUIIInkPresenter* inkPresenter;
- (EventRegistrationToken)addPointerEnteringEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerEnteringEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerExitingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerExitingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerHoveringEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerHoveringEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerLostEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerLostEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerMovingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerMovingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerPressingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerPressingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addPointerReleasingEvent:(void (^)(WUIICCoreInkIndependentInputSource*, WUCPointerEventArgs*))del;
- (void)removePointerReleasingEvent:(EventRegistrationToken)tok;
@end

#endif // __WUIICCoreInkIndependentInputSource_DEFINED__
