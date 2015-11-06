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

// WindowsGraphicsPrintingOptionDetails.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WGPOPrintCopiesOptionDetails, WGPOPrintMediaSizeOptionDetails, WGPOPrintMediaTypeOptionDetails, WGPOPrintOrientationOptionDetails,
    WGPOPrintQualityOptionDetails, WGPOPrintColorModeOptionDetails, WGPOPrintDuplexOptionDetails, WGPOPrintCollationOptionDetails,
    WGPOPrintStapleOptionDetails, WGPOPrintHolePunchOptionDetails, WGPOPrintBindingOptionDetails, WGPOPrintCustomTextOptionDetails,
    WGPOPrintCustomItemDetails, WGPOPrintCustomItemListOptionDetails, WGPOPrintTaskOptionChangedEventArgs, WGPOPrintTaskOptionDetails;
@protocol WGPOIPrintOptionDetails
, WGPOIPrintNumberOptionDetails, WGPOIPrintTextOptionDetails, WGPOIPrintItemListOptionDetails, WGPOIPrintCustomOptionDetails,
    WGPOIPrintCustomTextOptionDetails, WGPOIPrintCustomItemDetails, WGPOIPrintCustomItemListOptionDetails,
    WGPOIPrintTaskOptionChangedEventArgs, WGPOIPrintTaskOptionDetails, WGPOIPrintTaskOptionDetailsStatic;

// Windows.Graphics.Printing.OptionDetails.PrintOptionStates
enum _WGPOPrintOptionStates {
    WGPOPrintOptionStatesNone = 0,
    WGPOPrintOptionStatesEnabled = 1,
    WGPOPrintOptionStatesConstrained = 2,
};
typedef unsigned WGPOPrintOptionStates;

// Windows.Graphics.Printing.OptionDetails.PrintOptionType
enum _WGPOPrintOptionType {
    WGPOPrintOptionTypeUnknown = 0,
    WGPOPrintOptionTypeNumber = 1,
    WGPOPrintOptionTypeText = 2,
    WGPOPrintOptionTypeItemList = 3,
};
typedef unsigned WGPOPrintOptionType;

#include "WindowsFoundationCollections.h"
#include "WindowsFoundation.h"
#include "WindowsGraphicsPrinting.h"

#import <Foundation/Foundation.h>

// Windows.Graphics.Printing.OptionDetails.IPrintOptionDetails
#ifndef __WGPOIPrintOptionDetails_DEFINED__
#define __WGPOIPrintOptionDetails_DEFINED__

@protocol WGPOIPrintOptionDetails
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property WGPOPrintOptionStates state;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOIPrintOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.IPrintNumberOptionDetails
#ifndef __WGPOIPrintNumberOptionDetails_DEFINED__
#define __WGPOIPrintNumberOptionDetails_DEFINED__

@protocol WGPOIPrintNumberOptionDetails <WGPOIPrintOptionDetails>
@property (readonly) unsigned int maxValue;
@property (readonly) unsigned int minValue;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOIPrintNumberOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.IPrintTextOptionDetails
#ifndef __WGPOIPrintTextOptionDetails_DEFINED__
#define __WGPOIPrintTextOptionDetails_DEFINED__

@protocol WGPOIPrintTextOptionDetails <WGPOIPrintOptionDetails>
@property (readonly) unsigned int maxCharacters;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOIPrintTextOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.IPrintItemListOptionDetails
#ifndef __WGPOIPrintItemListOptionDetails_DEFINED__
#define __WGPOIPrintItemListOptionDetails_DEFINED__

@protocol WGPOIPrintItemListOptionDetails <WGPOIPrintOptionDetails>
@property (readonly) NSArray* items;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOIPrintItemListOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.IPrintCustomOptionDetails
#ifndef __WGPOIPrintCustomOptionDetails_DEFINED__
#define __WGPOIPrintCustomOptionDetails_DEFINED__

@protocol WGPOIPrintCustomOptionDetails <WGPOIPrintOptionDetails>
@property (copy) NSString* displayName;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOIPrintCustomOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCopiesOptionDetails
#ifndef __WGPOPrintCopiesOptionDetails_DEFINED__
#define __WGPOPrintCopiesOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintCopiesOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintNumberOptionDetails>
@property (readonly) unsigned int maxValue;
@property (readonly) unsigned int minValue;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintCopiesOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintMediaSizeOptionDetails
#ifndef __WGPOPrintMediaSizeOptionDetails_DEFINED__
#define __WGPOPrintMediaSizeOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintMediaSizeOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintMediaSizeOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintMediaTypeOptionDetails
#ifndef __WGPOPrintMediaTypeOptionDetails_DEFINED__
#define __WGPOPrintMediaTypeOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintMediaTypeOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintMediaTypeOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintOrientationOptionDetails
#ifndef __WGPOPrintOrientationOptionDetails_DEFINED__
#define __WGPOPrintOrientationOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintOrientationOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintOrientationOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintQualityOptionDetails
#ifndef __WGPOPrintQualityOptionDetails_DEFINED__
#define __WGPOPrintQualityOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintQualityOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintQualityOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintColorModeOptionDetails
#ifndef __WGPOPrintColorModeOptionDetails_DEFINED__
#define __WGPOPrintColorModeOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintColorModeOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintColorModeOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintDuplexOptionDetails
#ifndef __WGPOPrintDuplexOptionDetails_DEFINED__
#define __WGPOPrintDuplexOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintDuplexOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintDuplexOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCollationOptionDetails
#ifndef __WGPOPrintCollationOptionDetails_DEFINED__
#define __WGPOPrintCollationOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintCollationOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintCollationOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintStapleOptionDetails
#ifndef __WGPOPrintStapleOptionDetails_DEFINED__
#define __WGPOPrintStapleOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintStapleOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintStapleOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintHolePunchOptionDetails
#ifndef __WGPOPrintHolePunchOptionDetails_DEFINED__
#define __WGPOPrintHolePunchOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintHolePunchOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintHolePunchOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintBindingOptionDetails
#ifndef __WGPOPrintBindingOptionDetails_DEFINED__
#define __WGPOPrintBindingOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintBindingOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintBindingOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCustomTextOptionDetails
#ifndef __WGPOPrintCustomTextOptionDetails_DEFINED__
#define __WGPOPrintCustomTextOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintCustomTextOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintCustomOptionDetails>
@property (copy) NSString* displayName;
@property unsigned int maxCharacters;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintCustomTextOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCustomItemDetails
#ifndef __WGPOPrintCustomItemDetails_DEFINED__
#define __WGPOPrintCustomItemDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintCustomItemDetails : RTObject
@property (copy) NSString* itemDisplayName;
@property (readonly) NSString* itemId;
@end

#endif // __WGPOPrintCustomItemDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCustomItemListOptionDetails
#ifndef __WGPOPrintCustomItemListOptionDetails_DEFINED__
#define __WGPOPrintCustomItemListOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintCustomItemListOptionDetails
    : RTObject <WGPOIPrintOptionDetails, WGPOIPrintCustomOptionDetails, WGPOIPrintItemListOptionDetails>
@property (copy) NSString* displayName;
@property (readonly) NSArray* items;
@property WGPOPrintOptionStates state;
@property (copy) NSString* errorText;
@property (readonly) NSString* optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
- (void)addItem:(NSString*)itemId displayName:(NSString*)displayName;
@end

#endif // __WGPOPrintCustomItemListOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintTaskOptionChangedEventArgs
#ifndef __WGPOPrintTaskOptionChangedEventArgs_DEFINED__
#define __WGPOPrintTaskOptionChangedEventArgs_DEFINED__

WINRT_EXPORT
@interface WGPOPrintTaskOptionChangedEventArgs : RTObject
@property (readonly) RTObject* optionId;
@end

#endif // __WGPOPrintTaskOptionChangedEventArgs_DEFINED__

// Windows.Graphics.Printing.IPrintTaskOptionsCore
#ifndef __WGPIPrintTaskOptionsCore_DEFINED__
#define __WGPIPrintTaskOptionsCore_DEFINED__

@protocol WGPIPrintTaskOptionsCore
- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber;
@end

#endif // __WGPIPrintTaskOptionsCore_DEFINED__

// Windows.Graphics.Printing.IPrintTaskOptionsCoreUIConfiguration
#ifndef __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__
#define __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__

@protocol WGPIPrintTaskOptionsCoreUIConfiguration
@property (readonly) NSMutableArray* displayedOptions;
@end

#endif // __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintTaskOptionDetails
#ifndef __WGPOPrintTaskOptionDetails_DEFINED__
#define __WGPOPrintTaskOptionDetails_DEFINED__

WINRT_EXPORT
@interface WGPOPrintTaskOptionDetails : RTObject <WGPIPrintTaskOptionsCore, WGPIPrintTaskOptionsCoreUIConfiguration>
+ (WGPOPrintTaskOptionDetails*)getFromPrintTaskOptions:(WGPPrintTaskOptions*)printTaskOptions;
@property (readonly) NSMutableArray* displayedOptions;
@property (readonly) NSDictionary* options;
- (EventRegistrationToken)addBeginValidationEvent:(void (^)(WGPOPrintTaskOptionDetails*, RTObject*))del;
- (void)removeBeginValidationEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionChangedEvent:(void (^)(WGPOPrintTaskOptionDetails*, WGPOPrintTaskOptionChangedEventArgs*))del;
- (void)removeOptionChangedEvent:(EventRegistrationToken)tok;
- (WGPOPrintCustomItemListOptionDetails*)createItemListOption:(NSString*)optionId displayName:(NSString*)displayName;
- (WGPOPrintCustomTextOptionDetails*)createTextOption:(NSString*)optionId displayName:(NSString*)displayName;
- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber;
@end

#endif // __WGPOPrintTaskOptionDetails_DEFINED__
