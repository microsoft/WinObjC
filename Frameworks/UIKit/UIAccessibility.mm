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

@implementation UIAccessibilityElement

- (id)initWithAccessibilityContainer:(UIView*)container {
    _accessibilityContainer = container;
    [self initAccessibility];
    return self;
}

/**
 @Status Stub
*/
- (void)initAccessibility {
}

/**
 @Status Stub
*/
- (void)updateAccessibility {
    IWUpdateAccessibility(self.accessibilityContainer.layer, self);
}

@end

@implementation UIView (Accessibility)
@end

/**
 @Status Stub
*/
void UIAccessibilityPostNotification(UIAccessibilityNotifications notification, id argument) {
}

/**
 @Status Stub
*/
BOOL UIAccessibilityIsVoiceOverRunning(void) {
    return FALSE;
}

void IWUpdateAccessibility(id receiver, NSObject<UIAccessibility>* accessibilityObj) {
    IWAccessibilityInfo info;

    // traits are composed of accessibility flags, just copy them.
    info.flags = (IWAccessibilityFlags)accessibilityObj.accessibilityTraits;
    [receiver updateAccessibilityInfo:&info];
}
