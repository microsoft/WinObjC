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

// WindowsApplicationModelCalls.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WACLockScreenCallEndCallDeferral, WACLockScreenCallUI, WACLockScreenCallEndRequestedEventArgs;
@protocol WACILockScreenCallEndCallDeferral
, WACILockScreenCallEndRequestedEventArgs, WACILockScreenCallUI;

#include "WindowsFoundation.h"

// Windows.ApplicationModel.Calls.LockScreenCallEndCallDeferral
#ifndef __WACLockScreenCallEndCallDeferral_DEFINED__
#define __WACLockScreenCallEndCallDeferral_DEFINED__

WINRT_EXPORT
@interface WACLockScreenCallEndCallDeferral : RTObject
- (void)complete;
@end

#endif // __WACLockScreenCallEndCallDeferral_DEFINED__

// Windows.ApplicationModel.Calls.LockScreenCallUI
#ifndef __WACLockScreenCallUI_DEFINED__
#define __WACLockScreenCallUI_DEFINED__

WINRT_EXPORT
@interface WACLockScreenCallUI : RTObject
@property (copy) NSString* callTitle;
- (EventRegistrationToken)addClosedEvent:(void (^)(WACLockScreenCallUI*, RTObject*))del;
- (void)removeClosedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addEndRequestedEvent:(void (^)(WACLockScreenCallUI*, WACLockScreenCallEndRequestedEventArgs*))del;
- (void)removeEndRequestedEvent:(EventRegistrationToken)tok;
- (void)dismiss;
@end

#endif // __WACLockScreenCallUI_DEFINED__

// Windows.ApplicationModel.Calls.LockScreenCallEndRequestedEventArgs
#ifndef __WACLockScreenCallEndRequestedEventArgs_DEFINED__
#define __WACLockScreenCallEndRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WACLockScreenCallEndRequestedEventArgs : RTObject
@property (readonly) WFDateTime* deadline;
- (WACLockScreenCallEndCallDeferral*)getDeferral;
@end

#endif // __WACLockScreenCallEndRequestedEventArgs_DEFINED__
