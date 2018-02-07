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

// WindowsGraphicsPrintingPrintTicket.h
// Generated from winmd2objc

#pragma once

#ifndef OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
#define OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT __declspec(dllimport)
#ifndef IN_WinObjC_Frameworks_UWP_BUILD
#pragma comment(lib, "ObjCUWPWindowsGraphicsPrintingPrintTicket.lib")
#endif
#endif
#include <UWP/interopBase.h>

@class WGPPPrintTicketValue, WGPPPrintTicketOption, WGPPPrintTicketFeature, WGPPPrintTicketParameterDefinition, WGPPPrintTicketCapabilities, WGPPPrintTicketParameterInitializer, WGPPWorkflowPrintTicketValidationResult, WGPPWorkflowPrintTicket;
@protocol WGPPIPrintTicketValue, WGPPIPrintTicketOption, WGPPIPrintTicketFeature, WGPPIPrintTicketParameterDefinition, WGPPIPrintTicketCapabilities, WGPPIPrintTicketParameterInitializer, WGPPIWorkflowPrintTicketValidationResult, WGPPIWorkflowPrintTicket;

// Windows.Graphics.Printing.PrintTicket.PrintTicketFeatureSelectionType
enum _WGPPPrintTicketFeatureSelectionType {
    WGPPPrintTicketFeatureSelectionTypePickOne = 0,
    WGPPPrintTicketFeatureSelectionTypePickMany = 1,
};
typedef unsigned WGPPPrintTicketFeatureSelectionType;

// Windows.Graphics.Printing.PrintTicket.PrintTicketParameterDataType
enum _WGPPPrintTicketParameterDataType {
    WGPPPrintTicketParameterDataTypeInteger = 0,
    WGPPPrintTicketParameterDataTypeNumericString = 1,
    WGPPPrintTicketParameterDataTypeString = 2,
};
typedef unsigned WGPPPrintTicketParameterDataType;

// Windows.Graphics.Printing.PrintTicket.PrintTicketValueType
enum _WGPPPrintTicketValueType {
    WGPPPrintTicketValueTypeInteger = 0,
    WGPPPrintTicketValueTypeString = 1,
    WGPPPrintTicketValueTypeUnknown = 2,
};
typedef unsigned WGPPPrintTicketValueType;

#include "WindowsDataXmlDom.h"
#include "WindowsFoundation.h"

#import <Foundation/Foundation.h>

// Windows.Graphics.Printing.PrintTicket.PrintTicketValue
#ifndef __WGPPPrintTicketValue_DEFINED__
#define __WGPPPrintTicketValue_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPPrintTicketValue : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPPrintTicketValueType type;
- (int)getValueAsInteger;
- (NSString *)getValueAsString;
@end

#endif // __WGPPPrintTicketValue_DEFINED__

// Windows.Graphics.Printing.PrintTicket.PrintTicketOption
#ifndef __WGPPPrintTicketOption_DEFINED__
#define __WGPPPrintTicketOption_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPPrintTicketOption : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) NSString * name;
@property (readonly) NSString * xmlNamespace;
@property (readonly) RTObject<WDXDIXmlNode>* xmlNode;
- (RTObject<WDXDIXmlNode>*)getPropertyNode:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
- (RTObject<WDXDIXmlNode>*)getScoredPropertyNode:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
- (WGPPPrintTicketValue*)getPropertyValue:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
- (WGPPPrintTicketValue*)getScoredPropertyValue:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
@end

#endif // __WGPPPrintTicketOption_DEFINED__

// Windows.Graphics.Printing.PrintTicket.PrintTicketFeature
#ifndef __WGPPPrintTicketFeature_DEFINED__
#define __WGPPPrintTicketFeature_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPPrintTicketFeature : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) NSString * displayName;
@property (readonly) NSString * name;
@property (readonly) NSArray* /* WGPPPrintTicketOption* */ options;
@property (readonly) WGPPPrintTicketFeatureSelectionType selectionType;
@property (readonly) NSString * xmlNamespace;
@property (readonly) RTObject<WDXDIXmlNode>* xmlNode;
- (WGPPPrintTicketOption*)getOption:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
- (WGPPPrintTicketOption*)getSelectedOption;
- (void)setSelectedOption:(WGPPPrintTicketOption*)value;
@end

#endif // __WGPPPrintTicketFeature_DEFINED__

// Windows.Graphics.Printing.PrintTicket.PrintTicketParameterDefinition
#ifndef __WGPPPrintTicketParameterDefinition_DEFINED__
#define __WGPPPrintTicketParameterDefinition_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPPrintTicketParameterDefinition : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPPrintTicketParameterDataType dataType;
@property (readonly) NSString * name;
@property (readonly) int rangeMax;
@property (readonly) int rangeMin;
@property (readonly) NSString * unitType;
@property (readonly) NSString * xmlNamespace;
@property (readonly) RTObject<WDXDIXmlNode>* xmlNode;
@end

#endif // __WGPPPrintTicketParameterDefinition_DEFINED__

// Windows.Graphics.Printing.PrintTicket.PrintTicketCapabilities
#ifndef __WGPPPrintTicketCapabilities_DEFINED__
#define __WGPPPrintTicketCapabilities_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPPrintTicketCapabilities : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPPrintTicketFeature* documentBindingFeature;
@property (readonly) WGPPPrintTicketFeature* documentCollateFeature;
@property (readonly) WGPPPrintTicketFeature* documentDuplexFeature;
@property (readonly) WGPPPrintTicketFeature* documentHolePunchFeature;
@property (readonly) WGPPPrintTicketFeature* documentInputBinFeature;
@property (readonly) WGPPPrintTicketFeature* documentNUpFeature;
@property (readonly) WGPPPrintTicketFeature* documentStapleFeature;
@property (readonly) WGPPPrintTicketFeature* jobPasscodeFeature;
@property (readonly) NSString * name;
@property (readonly) WGPPPrintTicketFeature* pageBorderlessFeature;
@property (readonly) WGPPPrintTicketFeature* pageMediaSizeFeature;
@property (readonly) WGPPPrintTicketFeature* pageMediaTypeFeature;
@property (readonly) WGPPPrintTicketFeature* pageOrientationFeature;
@property (readonly) WGPPPrintTicketFeature* pageOutputColorFeature;
@property (readonly) WGPPPrintTicketFeature* pageOutputQualityFeature;
@property (readonly) WGPPPrintTicketFeature* pageResolutionFeature;
@property (readonly) NSString * xmlNamespace;
@property (readonly) RTObject<WDXDIXmlNode>* xmlNode;
- (WGPPPrintTicketFeature*)getFeature:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
- (WGPPPrintTicketParameterDefinition*)getParameterDefinition:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
@end

#endif // __WGPPPrintTicketCapabilities_DEFINED__

// Windows.Graphics.Printing.PrintTicket.PrintTicketParameterInitializer
#ifndef __WGPPPrintTicketParameterInitializer_DEFINED__
#define __WGPPPrintTicketParameterInitializer_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPPrintTicketParameterInitializer : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (retain) WGPPPrintTicketValue* value;
@property (readonly) NSString * name;
@property (readonly) NSString * xmlNamespace;
@property (readonly) RTObject<WDXDIXmlNode>* xmlNode;
@end

#endif // __WGPPPrintTicketParameterInitializer_DEFINED__

// Windows.Graphics.Printing.PrintTicket.WorkflowPrintTicketValidationResult
#ifndef __WGPPWorkflowPrintTicketValidationResult_DEFINED__
#define __WGPPWorkflowPrintTicketValidationResult_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPWorkflowPrintTicketValidationResult : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) HRESULT extendedError;
@property (readonly) BOOL validated;
@end

#endif // __WGPPWorkflowPrintTicketValidationResult_DEFINED__

// Windows.Graphics.Printing.PrintTicket.WorkflowPrintTicket
#ifndef __WGPPWorkflowPrintTicket_DEFINED__
#define __WGPPWorkflowPrintTicket_DEFINED__

OBJCUWPWINDOWSGRAPHICSPRINTINGPRINTTICKETEXPORT
@interface WGPPWorkflowPrintTicket : RTObject
#if defined(__cplusplus)
+ (instancetype)createWith:(IInspectable*)obj __attribute__ ((ns_returns_autoreleased));
#endif
@property (readonly) WGPPPrintTicketFeature* documentBindingFeature;
@property (readonly) WGPPPrintTicketFeature* documentCollateFeature;
@property (readonly) WGPPPrintTicketFeature* documentDuplexFeature;
@property (readonly) WGPPPrintTicketFeature* documentHolePunchFeature;
@property (readonly) WGPPPrintTicketFeature* documentInputBinFeature;
@property (readonly) WGPPPrintTicketFeature* documentNUpFeature;
@property (readonly) WGPPPrintTicketFeature* documentStapleFeature;
@property (readonly) WGPPPrintTicketFeature* jobPasscodeFeature;
@property (readonly) NSString * name;
@property (readonly) WGPPPrintTicketFeature* pageBorderlessFeature;
@property (readonly) WGPPPrintTicketFeature* pageMediaSizeFeature;
@property (readonly) WGPPPrintTicketFeature* pageMediaTypeFeature;
@property (readonly) WGPPPrintTicketFeature* pageOrientationFeature;
@property (readonly) WGPPPrintTicketFeature* pageOutputColorFeature;
@property (readonly) WGPPPrintTicketFeature* pageOutputQualityFeature;
@property (readonly) WGPPPrintTicketFeature* pageResolutionFeature;
@property (readonly) NSString * xmlNamespace;
@property (readonly) RTObject<WDXDIXmlNode>* xmlNode;
- (WGPPPrintTicketCapabilities*)getCapabilities;
- (WGPPPrintTicketFeature*)getFeature:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
- (RTObject<WFIAsyncAction>*)notifyXmlChangedAsync;
- (void)validateAsyncWithSuccess:(void (^)(WGPPWorkflowPrintTicketValidationResult*))success failure:(void (^)(NSError*))failure;
- (WGPPPrintTicketParameterInitializer*)getParameterInitializer:(NSString *)name xmlNamespace:(NSString *)xmlNamespace;
- (WGPPPrintTicketParameterInitializer*)setParameterInitializerAsInteger:(NSString *)name xmlNamespace:(NSString *)xmlNamespace integerValue:(int)integerValue;
- (WGPPPrintTicketParameterInitializer*)setParameterInitializerAsString:(NSString *)name xmlNamespace:(NSString *)xmlNamespace stringValue:(NSString *)stringValue;
- (WGPPWorkflowPrintTicket*)mergeAndValidateTicket:(WGPPWorkflowPrintTicket*)deltaShemaTicket;
@end

#endif // __WGPPWorkflowPrintTicket_DEFINED__

