//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#ifndef OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
#define OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphicsPrintingOptionDetails.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGPOPrintCopiesOptionDetails, WGPOPrintMediaSizeOptionDetails, WGPOPrintMediaTypeOptionDetails, WGPOPrintOrientationOptionDetails, WGPOPrintQualityOptionDetails, WGPOPrintColorModeOptionDetails, WGPOPrintDuplexOptionDetails, WGPOPrintCollationOptionDetails, WGPOPrintStapleOptionDetails, WGPOPrintHolePunchOptionDetails, WGPOPrintBindingOptionDetails, WGPOPrintBorderingOptionDetails, WGPOPrintCustomTextOptionDetails, WGPOPrintCustomItemDetails, WGPOPrintCustomItemListOptionDetails, WGPOPrintTaskOptionChangedEventArgs, WGPOPrintTaskOptionDetails;
@protocol WGPOIPrintOptionDetails, WGPOIPrintNumberOptionDetails, WGPOIPrintTextOptionDetails, WGPOIPrintItemListOptionDetails, WGPOIPrintCustomOptionDetails, WGPOIPrintCustomTextOptionDetails, WGPOIPrintCustomItemDetails, WGPOIPrintCustomItemListOptionDetails, WGPOIPrintTaskOptionChangedEventArgs, WGPOIPrintTaskOptionDetails, WGPOIPrintTaskOptionDetailsStatic;

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

#include "WindowsFoundation.h"
#include "WindowsGraphicsPrinting.h"

#import <Foundation/Foundation.h>

// Windows.Graphics.Printing.OptionDetails.IPrintOptionDetails
#ifndef __WGPOIPrintOptionDetails_DEFINED__
#define __WGPOIPrintOptionDetails_DEFINED__

@protocol WGPOIPrintOptionDetails
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property WGPOPrintOptionStates state;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOIPrintOptionDetails : RTObject <WGPOIPrintOptionDetails>
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

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOIPrintNumberOptionDetails : RTObject <WGPOIPrintNumberOptionDetails>
@end

#endif // __WGPOIPrintNumberOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.IPrintTextOptionDetails
#ifndef __WGPOIPrintTextOptionDetails_DEFINED__
#define __WGPOIPrintTextOptionDetails_DEFINED__

@protocol WGPOIPrintTextOptionDetails <WGPOIPrintOptionDetails>
@property (readonly) unsigned int maxCharacters;
- (BOOL)trySetValue:(RTObject*)value;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOIPrintTextOptionDetails : RTObject <WGPOIPrintTextOptionDetails>
@end

#endif // __WGPOIPrintTextOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.IPrintItemListOptionDetails
#ifndef __WGPOIPrintItemListOptionDetails_DEFINED__
#define __WGPOIPrintItemListOptionDetails_DEFINED__

@protocol WGPOIPrintItemListOptionDetails <WGPOIPrintOptionDetails>
@property (readonly) NSArray* /* RTObject* */ items;
- (BOOL)trySetValue:(RTObject*)value;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOIPrintItemListOptionDetails : RTObject <WGPOIPrintItemListOptionDetails>
@end

#endif // __WGPOIPrintItemListOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.IPrintCustomOptionDetails
#ifndef __WGPOIPrintCustomOptionDetails_DEFINED__
#define __WGPOIPrintCustomOptionDetails_DEFINED__

@protocol WGPOIPrintCustomOptionDetails <WGPOIPrintOptionDetails>
@property (retain) NSString * displayName;
- (BOOL)trySetValue:(RTObject*)value;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOIPrintCustomOptionDetails : RTObject <WGPOIPrintCustomOptionDetails>
@end

#endif // __WGPOIPrintCustomOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCopiesOptionDetails
#ifndef __WGPOPrintCopiesOptionDetails_DEFINED__
#define __WGPOPrintCopiesOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintCopiesOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintNumberOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) unsigned int maxValue;
@property (readonly) unsigned int minValue;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintCopiesOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintMediaSizeOptionDetails
#ifndef __WGPOPrintMediaSizeOptionDetails_DEFINED__
#define __WGPOPrintMediaSizeOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintMediaSizeOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintMediaSizeOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintMediaTypeOptionDetails
#ifndef __WGPOPrintMediaTypeOptionDetails_DEFINED__
#define __WGPOPrintMediaTypeOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintMediaTypeOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintMediaTypeOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintOrientationOptionDetails
#ifndef __WGPOPrintOrientationOptionDetails_DEFINED__
#define __WGPOPrintOrientationOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintOrientationOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintOrientationOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintQualityOptionDetails
#ifndef __WGPOPrintQualityOptionDetails_DEFINED__
#define __WGPOPrintQualityOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintQualityOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintQualityOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintColorModeOptionDetails
#ifndef __WGPOPrintColorModeOptionDetails_DEFINED__
#define __WGPOPrintColorModeOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintColorModeOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintColorModeOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintDuplexOptionDetails
#ifndef __WGPOPrintDuplexOptionDetails_DEFINED__
#define __WGPOPrintDuplexOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintDuplexOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintDuplexOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCollationOptionDetails
#ifndef __WGPOPrintCollationOptionDetails_DEFINED__
#define __WGPOPrintCollationOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintCollationOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintCollationOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintStapleOptionDetails
#ifndef __WGPOPrintStapleOptionDetails_DEFINED__
#define __WGPOPrintStapleOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintStapleOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintStapleOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintHolePunchOptionDetails
#ifndef __WGPOPrintHolePunchOptionDetails_DEFINED__
#define __WGPOPrintHolePunchOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintHolePunchOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintHolePunchOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintBindingOptionDetails
#ifndef __WGPOPrintBindingOptionDetails_DEFINED__
#define __WGPOPrintBindingOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintBindingOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintBindingOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintBorderingOptionDetails
#ifndef __WGPOPrintBorderingOptionDetails_DEFINED__
#define __WGPOPrintBorderingOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintBorderingOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintBorderingOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCustomTextOptionDetails
#ifndef __WGPOPrintCustomTextOptionDetails_DEFINED__
#define __WGPOPrintCustomTextOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintCustomTextOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintCustomOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * displayName;
@property unsigned int maxCharacters;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
@end

#endif // __WGPOPrintCustomTextOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCustomItemDetails
#ifndef __WGPOPrintCustomItemDetails_DEFINED__
#define __WGPOPrintCustomItemDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintCustomItemDetails : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * itemDisplayName;
@property (readonly) NSString * itemId;
@end

#endif // __WGPOPrintCustomItemDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintCustomItemListOptionDetails
#ifndef __WGPOPrintCustomItemListOptionDetails_DEFINED__
#define __WGPOPrintCustomItemListOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintCustomItemListOptionDetails : RTObject <WGPOIPrintOptionDetails, WGPOIPrintCustomOptionDetails, WGPOIPrintItemListOptionDetails>
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) NSString * displayName;
@property (readonly) NSArray* /* RTObject* */ items;
@property WGPOPrintOptionStates state;
@property (retain) NSString * errorText;
@property (readonly) NSString * optionId;
@property (readonly) WGPOPrintOptionType optionType;
@property (readonly) RTObject* value;
- (BOOL)trySetValue:(RTObject*)value;
- (void)addItem:(NSString *)itemId displayName:(NSString *)displayName;
@end

#endif // __WGPOPrintCustomItemListOptionDetails_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintTaskOptionChangedEventArgs
#ifndef __WGPOPrintTaskOptionChangedEventArgs_DEFINED__
#define __WGPOPrintTaskOptionChangedEventArgs_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintTaskOptionChangedEventArgs : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) RTObject* optionId;
@end

#endif // __WGPOPrintTaskOptionChangedEventArgs_DEFINED__

// Windows.Graphics.Printing.IPrintTaskOptionsCore
#ifndef __WGPIPrintTaskOptionsCore_DEFINED__
#define __WGPIPrintTaskOptionsCore_DEFINED__

@protocol WGPIPrintTaskOptionsCore
- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPIPrintTaskOptionsCore : RTObject <WGPIPrintTaskOptionsCore>
@end

#endif // __WGPIPrintTaskOptionsCore_DEFINED__

// Windows.Graphics.Printing.IPrintTaskOptionsCoreUIConfiguration
#ifndef __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__
#define __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__

@protocol WGPIPrintTaskOptionsCoreUIConfiguration
@property (readonly) NSMutableArray* /* NSString * */ displayedOptions;
@end

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPIPrintTaskOptionsCoreUIConfiguration : RTObject <WGPIPrintTaskOptionsCoreUIConfiguration>
@end

#endif // __WGPIPrintTaskOptionsCoreUIConfiguration_DEFINED__

// Windows.Graphics.Printing.OptionDetails.PrintTaskOptionDetails
#ifndef __WGPOPrintTaskOptionDetails_DEFINED__
#define __WGPOPrintTaskOptionDetails_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGOPTIONDETAILSEXPORT
@interface WGPOPrintTaskOptionDetails : RTObject <WGPIPrintTaskOptionsCore, WGPIPrintTaskOptionsCoreUIConfiguration>
+ (WGPOPrintTaskOptionDetails*)getFromPrintTaskOptions:(WGPPrintTaskOptions*)printTaskOptions;
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSMutableArray* /* NSString * */ displayedOptions;
@property (readonly) NSDictionary* /* NSString *, RTObject<WGPOIPrintOptionDetails>* */ options;
- (EventRegistrationToken)addBeginValidationEvent:(void(^)(WGPOPrintTaskOptionDetails*, RTObject*))del;
- (void)removeBeginValidationEvent:(EventRegistrationToken)tok;
- (EventRegistrationToken)addOptionChangedEvent:(void(^)(WGPOPrintTaskOptionDetails*, WGPOPrintTaskOptionChangedEventArgs*))del;
- (void)removeOptionChangedEvent:(EventRegistrationToken)tok;
- (WGPOPrintCustomItemListOptionDetails*)createItemListOption:(NSString *)optionId displayName:(NSString *)displayName;
- (WGPOPrintCustomTextOptionDetails*)createTextOption:(NSString *)optionId displayName:(NSString *)displayName;
- (WGPPrintPageDescription*)getPageDescription:(unsigned int)jobPageNumber;
@end

#endif // __WGPOPrintTaskOptionDetails_DEFINED__

