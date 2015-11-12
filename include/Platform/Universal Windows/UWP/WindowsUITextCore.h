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

// WindowsUITextCore.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WUTCCoreTextTextRequest, WUTCCoreTextSelectionRequest, WUTCCoreTextLayoutBounds, WUTCCoreTextLayoutRequest,
    WUTCCoreTextCompositionSegment, WUTCCoreTextEditContext, WUTCCoreTextTextRequestedEventArgs, WUTCCoreTextSelectionRequestedEventArgs,
    WUTCCoreTextLayoutRequestedEventArgs, WUTCCoreTextTextUpdatingEventArgs, WUTCCoreTextSelectionUpdatingEventArgs,
    WUTCCoreTextFormatUpdatingEventArgs, WUTCCoreTextCompositionStartedEventArgs, WUTCCoreTextCompositionCompletedEventArgs,
    WUTCCoreTextServicesManager, WUTCCoreTextServicesConstants;
@class WUTCCoreTextRange;
@protocol WUTCICoreTextTextRequest
, WUTCICoreTextTextRequestedEventArgs, WUTCICoreTextSelectionRequest, WUTCICoreTextSelectionRequestedEventArgs, WUTCICoreTextLayoutBounds,
    WUTCICoreTextLayoutRequest, WUTCICoreTextLayoutRequestedEventArgs, WUTCICoreTextTextUpdatingEventArgs,
    WUTCICoreTextSelectionUpdatingEventArgs, WUTCICoreTextFormatUpdatingEventArgs, WUTCICoreTextCompositionStartedEventArgs,
    WUTCICoreTextCompositionCompletedEventArgs, WUTCICoreTextEditContext, WUTCICoreTextServicesManager, WUTCICoreTextServicesManagerStatics,
    WUTCICoreTextServicesStatics, WUTCICoreTextCompositionSegment;

// Windows.UI.Text.Core.CoreTextInputScope
enum _WUTCCoreTextInputScope {
    WUTCCoreTextInputScopeDefault = 0,
    WUTCCoreTextInputScopeUrl = 1,
    WUTCCoreTextInputScopeFilePath = 2,
    WUTCCoreTextInputScopeFileName = 3,
    WUTCCoreTextInputScopeEmailUserName = 4,
    WUTCCoreTextInputScopeEmailAddress = 5,
    WUTCCoreTextInputScopeUserName = 6,
    WUTCCoreTextInputScopePersonalFullName = 7,
    WUTCCoreTextInputScopePersonalNamePrefix = 8,
    WUTCCoreTextInputScopePersonalGivenName = 9,
    WUTCCoreTextInputScopePersonalMiddleName = 10,
    WUTCCoreTextInputScopePersonalSurname = 11,
    WUTCCoreTextInputScopePersonalNameSuffix = 12,
    WUTCCoreTextInputScopeAddress = 13,
    WUTCCoreTextInputScopeAddressPostalCode = 14,
    WUTCCoreTextInputScopeAddressStreet = 15,
    WUTCCoreTextInputScopeAddressStateOrProvince = 16,
    WUTCCoreTextInputScopeAddressCity = 17,
    WUTCCoreTextInputScopeAddressCountryName = 18,
    WUTCCoreTextInputScopeAddressCountryShortName = 19,
    WUTCCoreTextInputScopeCurrencyAmountAndSymbol = 20,
    WUTCCoreTextInputScopeCurrencyAmount = 21,
    WUTCCoreTextInputScopeDate = 22,
    WUTCCoreTextInputScopeDateMonth = 23,
    WUTCCoreTextInputScopeDateDay = 24,
    WUTCCoreTextInputScopeDateYear = 25,
    WUTCCoreTextInputScopeDateMonthName = 26,
    WUTCCoreTextInputScopeDateDayName = 27,
    WUTCCoreTextInputScopeNumber = 29,
    WUTCCoreTextInputScopeSingleCharacter = 30,
    WUTCCoreTextInputScopePassword = 31,
    WUTCCoreTextInputScopeTelephoneNumber = 32,
    WUTCCoreTextInputScopeTelephoneCountryCode = 33,
    WUTCCoreTextInputScopeTelephoneAreaCode = 34,
    WUTCCoreTextInputScopeTelephoneLocalNumber = 35,
    WUTCCoreTextInputScopeTime = 36,
    WUTCCoreTextInputScopeTimeHour = 37,
    WUTCCoreTextInputScopeTimeMinuteOrSecond = 38,
    WUTCCoreTextInputScopeNumberFullWidth = 39,
    WUTCCoreTextInputScopeAlphanumericHalfWidth = 40,
    WUTCCoreTextInputScopeAlphanumericFullWidth = 41,
    WUTCCoreTextInputScopeCurrencyChinese = 42,
    WUTCCoreTextInputScopeBopomofo = 43,
    WUTCCoreTextInputScopeHiragana = 44,
    WUTCCoreTextInputScopeKatakanaHalfWidth = 45,
    WUTCCoreTextInputScopeKatakanaFullWidth = 46,
    WUTCCoreTextInputScopeHanja = 47,
    WUTCCoreTextInputScopeHangulHalfWidth = 48,
    WUTCCoreTextInputScopeHangulFullWidth = 49,
    WUTCCoreTextInputScopeSearch = 50,
    WUTCCoreTextInputScopeFormula = 51,
    WUTCCoreTextInputScopeSearchIncremental = 52,
    WUTCCoreTextInputScopeChineseHalfWidth = 53,
    WUTCCoreTextInputScopeChineseFullWidth = 54,
    WUTCCoreTextInputScopeNativeScript = 55,
    WUTCCoreTextInputScopeText = 57,
    WUTCCoreTextInputScopeChat = 58,
    WUTCCoreTextInputScopeNameOrPhoneNumber = 59,
    WUTCCoreTextInputScopeEmailUserNameOrAddress = 60,
    WUTCCoreTextInputScopePrivate = 61,
    WUTCCoreTextInputScopeMaps = 62,
    WUTCCoreTextInputScopePasswordNumeric = 63,
    WUTCCoreTextInputScopeFormulaNumber = 67,
};
typedef unsigned WUTCCoreTextInputScope;

// Windows.UI.Text.Core.CoreTextInputPaneDisplayPolicy
enum _WUTCCoreTextInputPaneDisplayPolicy {
    WUTCCoreTextInputPaneDisplayPolicyAutomatic = 0,
    WUTCCoreTextInputPaneDisplayPolicyManual = 1,
};
typedef unsigned WUTCCoreTextInputPaneDisplayPolicy;

// Windows.UI.Text.Core.CoreTextTextUpdatingResult
enum _WUTCCoreTextTextUpdatingResult {
    WUTCCoreTextTextUpdatingResultSucceeded = 0,
    WUTCCoreTextTextUpdatingResultFailed = 1,
};
typedef unsigned WUTCCoreTextTextUpdatingResult;

// Windows.UI.Text.Core.CoreTextSelectionUpdatingResult
enum _WUTCCoreTextSelectionUpdatingResult {
    WUTCCoreTextSelectionUpdatingResultSucceeded = 0,
    WUTCCoreTextSelectionUpdatingResultFailed = 1,
};
typedef unsigned WUTCCoreTextSelectionUpdatingResult;

// Windows.UI.Text.Core.CoreTextFormatUpdatingResult
enum _WUTCCoreTextFormatUpdatingResult {
    WUTCCoreTextFormatUpdatingResultSucceeded = 0,
    WUTCCoreTextFormatUpdatingResultFailed = 1,
};
typedef unsigned WUTCCoreTextFormatUpdatingResult;

// Windows.UI.Text.Core.CoreTextFormatUpdatingReason
enum _WUTCCoreTextFormatUpdatingReason {
    WUTCCoreTextFormatUpdatingReasonNone = 0,
    WUTCCoreTextFormatUpdatingReasonCompositionUnconverted = 1,
    WUTCCoreTextFormatUpdatingReasonCompositionConverted = 2,
    WUTCCoreTextFormatUpdatingReasonCompositionTargetUnconverted = 3,
    WUTCCoreTextFormatUpdatingReasonCompositionTargetConverted = 4,
};
typedef unsigned WUTCCoreTextFormatUpdatingReason;

#include "WindowsFoundation.h"
#include "WindowsGlobalization.h"
#include "WindowsUIViewManagement.h"
#include "WindowsUIText.h"
#include "WindowsFoundationCollections.h"

#import <Foundation/Foundation.h>

// [struct] Windows.UI.Text.Core.CoreTextRange
WINRT_EXPORT
@interface WUTCCoreTextRange : NSObject
+ (instancetype) new;
@property int startCaretPosition;
@property int endCaretPosition;
@end

// Windows.UI.Text.Core.CoreTextTextRequest
#ifndef __WUTCCoreTextTextRequest_DEFINED__
#define __WUTCCoreTextTextRequest_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextTextRequest : RTObject
@property (copy) NSString* text;
@property (readonly) BOOL isCanceled;
@property (readonly) WUTCCoreTextRange* range;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextTextRequest_DEFINED__

// Windows.UI.Text.Core.CoreTextSelectionRequest
#ifndef __WUTCCoreTextSelectionRequest_DEFINED__
#define __WUTCCoreTextSelectionRequest_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextSelectionRequest : RTObject
@property (copy) WUTCCoreTextRange* selection;
@property (readonly) BOOL isCanceled;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextSelectionRequest_DEFINED__

// Windows.UI.Text.Core.CoreTextLayoutBounds
#ifndef __WUTCCoreTextLayoutBounds_DEFINED__
#define __WUTCCoreTextLayoutBounds_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextLayoutBounds : RTObject
@property (copy) WFRect* textBounds;
@property (copy) WFRect* controlBounds;
@end

#endif // __WUTCCoreTextLayoutBounds_DEFINED__

// Windows.UI.Text.Core.CoreTextLayoutRequest
#ifndef __WUTCCoreTextLayoutRequest_DEFINED__
#define __WUTCCoreTextLayoutRequest_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextLayoutRequest : RTObject
@property (readonly) BOOL isCanceled;
@property (readonly) WUTCCoreTextLayoutBounds* layoutBounds;
@property (readonly) WUTCCoreTextRange* range;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextLayoutRequest_DEFINED__

// Windows.UI.Text.Core.CoreTextCompositionSegment
#ifndef __WUTCCoreTextCompositionSegment_DEFINED__
#define __WUTCCoreTextCompositionSegment_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextCompositionSegment : RTObject
@property (readonly) NSString* preconversionString;
@property (readonly) WUTCCoreTextRange* range;
@end

#endif // __WUTCCoreTextCompositionSegment_DEFINED__

// Windows.UI.Text.Core.CoreTextEditContext
#ifndef __WUTCCoreTextEditContext_DEFINED__
#define __WUTCCoreTextEditContext_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextEditContext : RTObject
@property (copy) NSString* name;
@property BOOL isReadOnly;
@property WUTCCoreTextInputScope inputScope;
@property WUTCCoreTextInputPaneDisplayPolicy inputPaneDisplayPolicy;
- (EventRegistrationToken)addCompositionCompletedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextCompositionCompletedEventArgs*))del;
- (void)removeCompositionCompletedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addCompositionStartedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextCompositionStartedEventArgs*))del;
- (void)removeCompositionStartedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFocusRemovedEvent:(void (^)(WUTCCoreTextEditContext*, RTObject*))del;
- (void)removeFocusRemovedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addFormatUpdatingEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextFormatUpdatingEventArgs*))del;
- (void)removeFormatUpdatingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addLayoutRequestedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextLayoutRequestedEventArgs*))del;
- (void)removeLayoutRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionRequestedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionRequestedEventArgs*))del;
- (void)removeSelectionRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addSelectionUpdatingEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextSelectionUpdatingEventArgs*))del;
- (void)removeSelectionUpdatingEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextRequestedEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextTextRequestedEventArgs*))del;
- (void)removeTextRequestedEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addTextUpdatingEvent:(void (^)(WUTCCoreTextEditContext*, WUTCCoreTextTextUpdatingEventArgs*))del;
- (void)removeTextUpdatingEvent:(EventRegistrationToken)tok;
- (void)notifyFocusEnter;
- (void)notifyFocusLeave;
- (void)notifyTextChanged:(WUTCCoreTextRange*)modifiedRange newLength:(int)newLength newSelection:(WUTCCoreTextRange*)newSelection;
- (void)notifySelectionChanged:(WUTCCoreTextRange*)selection;
- (void)notifyLayoutChanged;
@end

#endif // __WUTCCoreTextEditContext_DEFINED__

// Windows.UI.Text.Core.CoreTextTextRequestedEventArgs
#ifndef __WUTCCoreTextTextRequestedEventArgs_DEFINED__
#define __WUTCCoreTextTextRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextTextRequestedEventArgs : RTObject
@property (readonly) WUTCCoreTextTextRequest* request;
@end

#endif // __WUTCCoreTextTextRequestedEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextSelectionRequestedEventArgs
#ifndef __WUTCCoreTextSelectionRequestedEventArgs_DEFINED__
#define __WUTCCoreTextSelectionRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextSelectionRequestedEventArgs : RTObject
@property (readonly) WUTCCoreTextSelectionRequest* request;
@end

#endif // __WUTCCoreTextSelectionRequestedEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextLayoutRequestedEventArgs
#ifndef __WUTCCoreTextLayoutRequestedEventArgs_DEFINED__
#define __WUTCCoreTextLayoutRequestedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextLayoutRequestedEventArgs : RTObject
@property (readonly) WUTCCoreTextLayoutRequest* request;
@end

#endif // __WUTCCoreTextLayoutRequestedEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextTextUpdatingEventArgs
#ifndef __WUTCCoreTextTextUpdatingEventArgs_DEFINED__
#define __WUTCCoreTextTextUpdatingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextTextUpdatingEventArgs : RTObject
@property WUTCCoreTextTextUpdatingResult result;
@property (readonly) WGLanguage* inputLanguage;
@property (readonly) BOOL isCanceled;
@property (readonly) WUTCCoreTextRange* newSelection;
@property (readonly) WUTCCoreTextRange* range;
@property (readonly) NSString* text;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextTextUpdatingEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextSelectionUpdatingEventArgs
#ifndef __WUTCCoreTextSelectionUpdatingEventArgs_DEFINED__
#define __WUTCCoreTextSelectionUpdatingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextSelectionUpdatingEventArgs : RTObject
@property WUTCCoreTextSelectionUpdatingResult result;
@property (readonly) BOOL isCanceled;
@property (readonly) WUTCCoreTextRange* selection;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextSelectionUpdatingEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextFormatUpdatingEventArgs
#ifndef __WUTCCoreTextFormatUpdatingEventArgs_DEFINED__
#define __WUTCCoreTextFormatUpdatingEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextFormatUpdatingEventArgs : RTObject
@property WUTCCoreTextFormatUpdatingResult result;
@property (readonly) id backgroundColor;
@property (readonly) BOOL isCanceled;
@property (readonly) WUTCCoreTextRange* range;
@property (readonly) WUTCCoreTextFormatUpdatingReason reason;
@property (readonly) id textColor;
@property (readonly) id underlineColor;
@property (readonly) id underlineType;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextFormatUpdatingEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextCompositionStartedEventArgs
#ifndef __WUTCCoreTextCompositionStartedEventArgs_DEFINED__
#define __WUTCCoreTextCompositionStartedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextCompositionStartedEventArgs : RTObject
@property (readonly) BOOL isCanceled;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextCompositionStartedEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextCompositionCompletedEventArgs
#ifndef __WUTCCoreTextCompositionCompletedEventArgs_DEFINED__
#define __WUTCCoreTextCompositionCompletedEventArgs_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextCompositionCompletedEventArgs : RTObject
@property (readonly) NSArray* compositionSegments;
@property (readonly) BOOL isCanceled;
- (WFDeferral*)getDeferral;
@end

#endif // __WUTCCoreTextCompositionCompletedEventArgs_DEFINED__

// Windows.UI.Text.Core.CoreTextServicesManager
#ifndef __WUTCCoreTextServicesManager_DEFINED__
#define __WUTCCoreTextServicesManager_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextServicesManager : RTObject
+ (WUTCCoreTextServicesManager*)getForCurrentView;
@property (readonly) WGLanguage* inputLanguage;
- (EventRegistrationToken)addInputLanguageChangedEvent:(void (^)(WUTCCoreTextServicesManager*, RTObject*))del;
- (void)removeInputLanguageChangedEvent:(EventRegistrationToken)tok;
- (WUTCCoreTextEditContext*)createEditContext;
@end

#endif // __WUTCCoreTextServicesManager_DEFINED__

// Windows.UI.Text.Core.CoreTextServicesConstants
#ifndef __WUTCCoreTextServicesConstants_DEFINED__
#define __WUTCCoreTextServicesConstants_DEFINED__

WINRT_EXPORT
@interface WUTCCoreTextServicesConstants : RTObject
+ (WCHAR)hiddenCharacter;
@end

#endif // __WUTCCoreTextServicesConstants_DEFINED__
