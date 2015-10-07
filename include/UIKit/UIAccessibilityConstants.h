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

#ifndef _UIACCESSIBILITYCONSTANTS_H_
#define _UIACCESSIBILITYCONSTANTS_H_

#import <StarboardExport.h>
#import <Foundation/NSObject.h>

typedef uint64_t UIAccessibilityTraits;

SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitNone;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitButton;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitLink;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitSearchField;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitImage;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitSelected;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitPlaysSound;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitKeyboardKey;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitStaticText;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitSummaryElement;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitNotEnabled;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitUpdatesFrequently;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitStartsMediaSession;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitAdjustable;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitAllowsDirectInteraction;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitCausesPageTurn;
SB_EXPORT UIAccessibilityTraits UIAccessibilityTraitHeader;

#endif /* _UIACCESSIBILITYCONSTANTS_H_ */