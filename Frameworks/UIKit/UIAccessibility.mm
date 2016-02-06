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

#include <StubReturn.h>
#include "Starboard.h"
#include "AccessibilityInternal.h"

#import <UIKit/UIAccessibility.h>

UIAccessibilityTraits UIAccessibilityTraitNone = 0;
UIAccessibilityTraits UIAccessibilityTraitButton = ACC_FLAG_BUTTON;
UIAccessibilityTraits UIAccessibilityTraitLink = ACC_FLAG_LINK;
UIAccessibilityTraits UIAccessibilityTraitSearchField = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitImage = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitSelected = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitPlaysSound = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitKeyboardKey = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitStaticText = ACC_FLAG_STATIC_TEXT;
UIAccessibilityTraits UIAccessibilityTraitSummaryElement = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitNotEnabled = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitUpdatesFrequently = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitStartsMediaSession = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitAdjustable = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitAllowsDirectInteraction = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitCausesPageTurn = ACC_FLAG_UNUSED;
UIAccessibilityTraits UIAccessibilityTraitHeader = ACC_FLAG_UNUSED;

UIAccessibilityNotifications UIAccessibilityScreenChangedNotification = 0;
UIAccessibilityNotifications UIAccessibilityLayoutChangedNotification = 1;
UIAccessibilityNotifications UIAccessibilityAnnouncementNotification = 2;
UIAccessibilityNotifications UIAccessibilityPageScrolledNotification = 3;
UIAccessibilityNotifications UIAccessibilityAnnouncementDidFinishNotification = 4;
UIAccessibilityNotifications UIAccessibilityBoldTextStatusDidChangeNotification = 5;
UIAccessibilityNotifications UIAccessibilityClosedCaptioningStatusDidChangeNotification = 6;
UIAccessibilityNotifications UIAccessibilityDarkerSystemColorsStatusDidChangeNotification = 7;
UIAccessibilityNotifications UIAccessibilityGrayscaleStatusDidChangeNotification = 8;
UIAccessibilityNotifications UIAccessibilityGuidedAccessStatusDidChangeNotification = 9;
UIAccessibilityNotifications UIAccessibilityInvertColorsStatusDidChangeNotification = 10;
UIAccessibilityNotifications UIAccessibilityPauseAssistiveTechnologyNotification = 11;
UIAccessibilityNotifications UIAccessibilityReduceMotionStatusDidChangeNotification = 12;
UIAccessibilityNotifications UIAccessibilityReduceTransparencyStatusDidChangeNotification = 13;
UIAccessibilityNotifications UIAccessibilityResumeAssistiveTechnologyNotification = 14;
UIAccessibilityNotifications UIAccessibilitySpeakScreenStatusDidChangeNotification = 15;
UIAccessibilityNotifications UIAccessibilitySpeakSelectionStatusDidChangeNotification = 16;
UIAccessibilityNotifications UIAccessibilitySwitchControlStatusDidChangeNotification = 17;

NSString* const UIAccessibilityAnnouncementKeyStringValue = @"UIAccessibilityAnnouncementKeyStringValue";
NSString* const UIAccessibilityAnnouncementKeyWasSuccessful = @"UIAccessibilityAnnouncementKeyWasSuccessful";
NSString* const UIAccessibilitySpeechAttributePunctuation = @"UIAccessibilitySpeechAttributePunctuation";
NSString* const UIAccessibilitySpeechAttributeLanguage = @"UIAccessibilitySpeechAttributeLanguage";
NSString* const UIAccessibilitySpeechAttributePitch = @"UIAccessibilitySpeechAttributePitch";
NSString* const UIAccessibilityMonoAudioStatusDidChangeNotification = @"UIAccessibilityMonoAudioStatusDidChangeNotification";
NSString* const UIAccessibilityNotificationSwitchControlIdentifier = @"UIAccessibilityNotificationSwitchControlIdentifier";
NSString* const UIAccessibilityVoiceOverStatusChanged = @"UIAccessibilityVoiceOverStatusChanged";

/**
 @Status Stub
 @Notes
*/
void UIAccessibilityPostNotification(UIAccessibilityNotifications notification, id argument) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CGRect UIAccessibilityConvertFrameToScreenCoordinates(CGRect rect, UIView* view) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
UIBezierPath* UIAccessibilityConvertPathToScreenCoordinates(UIBezierPath* path, UIView* view) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void UIAccessibilityRegisterGestureConflictWithZoom() {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void UIAccessibilityRequestGuidedAccessSession(BOOL enable, void (^completionHandler)(BOOL)) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void UIAccessibilityZoomFocusChanged(UIAccessibilityZoomType type, CGRect frame, UIView* view) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsBoldTextEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsClosedCaptioningEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityDarkerSystemColorsEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsGrayscaleEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsGuidedAccessEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsInvertColorsEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsMonoAudioEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsReduceMotionEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsReduceTransparencyEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsSpeakScreenEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsSpeakSelectionEnabled() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsSwitchControlRunning() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
BOOL UIAccessibilityIsVoiceOverRunning() {
    UNIMPLEMENTED();
    return StubReturn();
}

void IWUpdateAccessibility(id receiver, NSObject<UIAccessibility>* accessibilityObj) {
    IWAccessibilityInfo info;

    // traits are composed of accessibility flags, just copy them.
    info.flags = (IWAccessibilityFlags)accessibilityObj.accessibilityTraits;
    [receiver updateAccessibilityInfo:&info];
}
