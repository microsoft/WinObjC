/*
* Copyright (c) 2011, The Iconfactory. All rights reserved.
*
* Copyright (c) 2015 Microsoft Corporation. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
* 2. Redistributions in binary form must reproduce the above copyright notice,
*    this list of conditions and the following disclaimer in the documentation
*    and/or other materials provided with the distribution.
*
* 3. Neither the name of The Iconfactory nor the names of its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
* LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
* ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#import <Foundation/Foundation.h>
#import <Foundation/NSString.h>

@class UIView;
@class UIBezierPath;

enum _UIAccessibilityNavigationStyle {
    UIAccessibilityNavigationStyleAutomatic,
    UIAccessibilityNavigationStyleSeparate,
    UIAccessibilityNavigationStyleCombined,
};
typedef NSUInteger UIAccessibilityNavigationStyle;

typedef uint64_t UIAccessibilityTraits;

UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitNone;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitButton;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitLink;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitSearchField;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitImage;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitSelected;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitPlaysSound;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitKeyboardKey;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitStaticText;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitSummaryElement;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitNotEnabled;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitUpdatesFrequently;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitStartsMediaSession;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitAdjustable;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitAllowsDirectInteraction;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitCausesPageTurn;
UIKIT_EXPORT UIAccessibilityTraits UIAccessibilityTraitHeader;

typedef uint32_t UIAccessibilityNotifications;
UIKIT_EXPORT UIAccessibilityNotifications UIAccessibilityScreenChangedNotification;
UIKIT_EXPORT UIAccessibilityNotifications UIAccessibilityLayoutChangedNotification;
UIKIT_EXPORT UIAccessibilityNotifications UIAccessibilityAnnouncementNotification;
UIKIT_EXPORT UIAccessibilityNotifications UIAccessibilityPageScrolledNotification;

// ----------------------------------------

@protocol UIAccessibility

- (void)initAccessibility;
- (void)updateAccessibility;

@property BOOL isAccessibilityElement;

@property (copy) NSString* accessibilityLabel;
@property (copy) NSString* accessibilityHint;
@property (copy) NSString* accessibilityValue;

@property UIAccessibilityTraits accessibilityTraits;
@property UIAccessibilityNavigationStyle accessibilityNavigationStyle;

@property (nonatomic) CGRect accessibilityFrame;
@property (copy) UIBezierPath* accessibilityPath;
@property CGPoint accessibilityActivationPoint;

@property (retain) NSString* accessibilityLanguage;

@property BOOL accessibilityElementsHidden;
@property BOOL shouldGroupAccessibilityChildren;

@property BOOL accessibilityViewIsModal;

@end

// ----------------------------------------

@protocol UIAccessibilityContainer
- (id)accessibilityElementAtIndex:(NSInteger)index;
- (NSInteger)indexOfAccessibilityElement:(id)element;

@property (readonly) NSInteger accessibilityElementCount;
@property (readonly) NSArray* accessibilityElements;

@end

// ----------------------------------------

@protocol UIAccessibilityFocus

- (void)accessibilityElementDidBecomeFocused;
- (void)accessibilityElementDidLoseFocus;
- (BOOL)accessibilityElementIsFocused;

@end

// ----------------------------------------

@protocol UIAccessibilityIdentification

@property (copy) NSString* accessibilityIdentifier;

@end

UIKIT_EXPORT void UIAccessibilityPostNotification(UIAccessibilityNotifications notification, id argument);
UIKIT_EXPORT BOOL UIAccessibilityIsVoiceOverRunning(void);
