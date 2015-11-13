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

// WindowsFoundationMetadata.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WFMApiInformation;
@protocol WFMIApiInformationStatics;

// Windows.Foundation.Metadata.GCPressureAmount
enum _WFMGCPressureAmount {
    WFMGCPressureAmountLow = 0,
    WFMGCPressureAmountMedium = 1,
    WFMGCPressureAmountHigh = 2,
};
typedef unsigned WFMGCPressureAmount;

// Windows.Foundation.Metadata.Platform
enum _WFMPlatform {
    WFMPlatformWindows = 0,
    WFMPlatformWindowsPhone = 1,
};
typedef unsigned WFMPlatform;

// Windows.Foundation.Metadata.AttributeTargets
enum _WFMAttributeTargets {
    WFMAttributeTargetsAll = -1,
    WFMAttributeTargetsDelegate = 1,
    WFMAttributeTargetsEnum = 2,
    WFMAttributeTargetsEvent = 4,
    WFMAttributeTargetsField = 8,
    WFMAttributeTargetsInterface = 16,
    WFMAttributeTargetsMethod = 64,
    WFMAttributeTargetsParameter = 128,
    WFMAttributeTargetsProperty = 256,
    WFMAttributeTargetsRuntimeClass = 512,
    WFMAttributeTargetsStruct = 1024,
    WFMAttributeTargetsInterfaceImpl = 2048,
    WFMAttributeTargetsApiContract = 8192,
};
typedef unsigned WFMAttributeTargets;

// Windows.Foundation.Metadata.CompositionType
enum _WFMCompositionType {
    WFMCompositionTypeProtected = 1,
    WFMCompositionTypePublic = 2,
};
typedef unsigned WFMCompositionType;

// Windows.Foundation.Metadata.ThreadingModel
enum _WFMThreadingModel {
    WFMThreadingModelSTA = 1,
    WFMThreadingModelMTA = 2,
    WFMThreadingModelBoth = 3,
    WFMThreadingModelInvalidThreading = 0,
};
typedef unsigned WFMThreadingModel;

// Windows.Foundation.Metadata.MarshalingType
enum _WFMMarshalingType {
    WFMMarshalingTypeNone = 1,
    WFMMarshalingTypeAgile = 2,
    WFMMarshalingTypeStandard = 3,
    WFMMarshalingTypeInvalidMarshaling = 0,
};
typedef unsigned WFMMarshalingType;

// Windows.Foundation.Metadata.DeprecationType
enum _WFMDeprecationType {
    WFMDeprecationTypeDeprecate = 0,
    WFMDeprecationTypeRemove = 1,
};
typedef unsigned WFMDeprecationType;

#import <Foundation/Foundation.h>

// Windows.Foundation.Metadata.ApiInformation
#ifndef __WFMApiInformation_DEFINED__
#define __WFMApiInformation_DEFINED__

WINRT_EXPORT
@interface WFMApiInformation : RTObject
+ (BOOL)isTypePresent:(NSString*)typeName;
+ (BOOL)isMethodPresent:(NSString*)typeName methodName:(NSString*)methodName;
+ (BOOL)isMethodPresentWithArity:(NSString*)typeName methodName:(NSString*)methodName inputParameterCount:(unsigned int)inputParameterCount;
+ (BOOL)isEventPresent:(NSString*)typeName eventName:(NSString*)eventName;
+ (BOOL)isPropertyPresent:(NSString*)typeName propertyName:(NSString*)propertyName;
+ (BOOL)isReadOnlyPropertyPresent:(NSString*)typeName propertyName:(NSString*)propertyName;
+ (BOOL)isWriteablePropertyPresent:(NSString*)typeName propertyName:(NSString*)propertyName;
+ (BOOL)isEnumNamedValuePresent:(NSString*)enumTypeName valueName:(NSString*)valueName;
+ (BOOL)isApiContractPresentByMajor:(NSString*)contractName majorVersion:(unsigned short)majorVersion;
+ (BOOL)isApiContractPresentByMajorAndMinor:(NSString*)contractName
                               majorVersion:(unsigned short)majorVersion
                               minorVersion:(unsigned short)minorVersion;
@end

#endif // __WFMApiInformation_DEFINED__
