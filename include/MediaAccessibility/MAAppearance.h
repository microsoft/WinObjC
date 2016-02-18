//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <MediaAccessibility/MediaAccessibilityExport.h>
#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFString.h>
#import <CoreText/CTFontDescriptor.h>
#import <CoreGraphics/CGColor.h>

typedef enum : CFIndex {
    kMACaptionAppearanceDomainDefault = 0,
    kMACaptionAppearanceDomainUser = 1,
} MACaptionAppearanceDomain;

typedef enum : CFIndex {
    kMACaptionAppearanceDisplayTypeForcedOnly = 0,
    kMACaptionAppearanceDisplayTypeAutomatic = 1,
    kMACaptionAppearanceDisplayTypeAlwaysOn = 2,
} MACaptionAppearanceDisplayType;

typedef enum : CFIndex {
    kMACaptionAppearanceBehaviorUseValue = 0,
    kMACaptionAppearanceBehaviorUseContentIfAvailable = 1,
} MACaptionAppearanceBehavior;

typedef enum : CFIndex {
    kMACaptionAppearanceFontStyleDefault = 0,
    kMACaptionAppearanceFontStyleMonospacedWithSerif = 1,
    kMACaptionAppearanceFontStyleProportionalWithSerif = 2,
    kMACaptionAppearanceFontStyleMonospacedWithoutSerif = 3,
    kMACaptionAppearanceFontStyleProportionalWithoutSerif = 4,
    kMACaptionAppearanceFontStyleCasual = 5,
    kMACaptionAppearanceFontStyleCursive = 6,
    kMACaptionAppearanceFontStyleSmallCapital = 7,
} MACaptionAppearanceFontStyle;

typedef enum : CFIndex {
    kMACaptionAppearanceTextEdgeStyleUndefined = 0,
    kMACaptionAppearanceTextEdgeStyleNone = 1,
    kMACaptionAppearanceTextEdgeStyleRaised = 2,
    kMACaptionAppearanceTextEdgeStyleDepressed = 3,
    kMACaptionAppearanceTextEdgeStyleUniform = 4,
    kMACaptionAppearanceTextEdgeStyleDropShadow = 5,
} MACaptionAppearanceTextEdgeStyle;

MEDIAACCESSIBILITY_EXPORT CFArrayRef MACaptionAppearanceCopyPreferredCaptioningMediaCharacteristics(MACaptionAppearanceDomain domain)
    STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT MACaptionAppearanceDisplayType MACaptionAppearanceGetDisplayType(MACaptionAppearanceDomain domain) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT void MACaptionAppearanceSetDisplayType(MACaptionAppearanceDomain domain,
                                                                 MACaptionAppearanceDisplayType displayType) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT bool MACaptionAppearanceAddSelectedLanguage(MACaptionAppearanceDomain domain, CFStringRef language) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CFArrayRef MACaptionAppearanceCopySelectedLanguages(MACaptionAppearanceDomain domain) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CTFontDescriptorRef MACaptionAppearanceCopyFontDescriptorForStyle(
    MACaptionAppearanceDomain domain, MACaptionAppearanceBehavior* behavior, MACaptionAppearanceFontStyle fontStyle) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGColorRef MACaptionAppearanceCopyForegroundColor(MACaptionAppearanceDomain domain,
                                                                            MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGFloat MACaptionAppearanceGetForegroundOpacity(MACaptionAppearanceDomain domain,
                                                                          MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGFloat MACaptionAppearanceGetRelativeCharacterSize(MACaptionAppearanceDomain domain,
                                                                              MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT MACaptionAppearanceTextEdgeStyle
MACaptionAppearanceGetTextEdgeStyle(MACaptionAppearanceDomain domain, MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGColorRef MACaptionAppearanceCopyBackgroundColor(MACaptionAppearanceDomain domain,
                                                                            MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGFloat MACaptionAppearanceGetBackgroundOpacity(MACaptionAppearanceDomain domain,
                                                                          MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGColorRef MACaptionAppearanceCopyWindowColor(MACaptionAppearanceDomain domain,
                                                                        MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGFloat MACaptionAppearanceGetWindowOpacity(MACaptionAppearanceDomain domain,
                                                                      MACaptionAppearanceBehavior* behavior) STUB_METHOD;
MEDIAACCESSIBILITY_EXPORT CGFloat MACaptionAppearanceGetWindowRoundedCornerRadius(MACaptionAppearanceDomain domain,
                                                                                  MACaptionAppearanceBehavior* behavior) STUB_METHOD;
