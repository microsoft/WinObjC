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

// WindowsDataJson.h
// Generated from winmd2objc

#pragma once

#include "interopBase.h"
@class WDJJsonArray, WDJJsonObject, WDJJsonValue, WDJJsonError;
@protocol WDJIJsonValue
, WDJIJsonValueStatics, WDJIJsonObject, WDJIJsonObjectWithDefaultValues, WDJIJsonObjectStatics, WDJIJsonArray, WDJIJsonArrayStatics,
    WDJIJsonErrorStatics, WDJIJsonErrorStatics2;

// Windows.Data.Json.JsonValueType
enum _WDJJsonValueType {
    WDJJsonValueTypeNull = 0,
    WDJJsonValueTypeBoolean = 1,
    WDJJsonValueTypeNumber = 2,
    WDJJsonValueTypeString = 3,
    WDJJsonValueTypeArray = 4,
    WDJJsonValueTypeObject = 5,
};
typedef unsigned WDJJsonValueType;

// Windows.Data.Json.JsonErrorStatus
enum _WDJJsonErrorStatus {
    WDJJsonErrorStatusUnknown = 0,
    WDJJsonErrorStatusInvalidJsonString = 1,
    WDJJsonErrorStatusInvalidJsonNumber = 2,
    WDJJsonErrorStatusJsonValueNotFound = 3,
    WDJJsonErrorStatusImplementationLimit = 4,
};
typedef unsigned WDJJsonErrorStatus;

// Windows.Data.Json.IJsonValue
#ifndef __WDJIJsonValue_DEFINED__
#define __WDJIJsonValue_DEFINED__

@protocol WDJIJsonValue
@property (readonly) WDJJsonValueType valueType;
- (NSString*)stringify;
- (NSString*)getString;
- (double)getNumber;
- (BOOL)getBoolean;
- (WDJJsonArray*)getArray;
- (WDJJsonObject*)getObject;
@end

#endif // __WDJIJsonValue_DEFINED__

// Windows.Data.Json.JsonArray
#ifndef __WDJJsonArray_DEFINED__
#define __WDJJsonArray_DEFINED__

WINRT_EXPORT
@interface WDJJsonArray : RTObject <WDJIJsonValue>
+ (WDJJsonArray*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input result:(WDJJsonArray**)result;
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@property (readonly) WDJJsonValueType valueType;
- (WDJJsonObject*)getObjectAt:(unsigned)index;
- (WDJJsonArray*)getArrayAt:(unsigned)index;
- (NSString*)getStringAt:(unsigned)index;
- (double)getNumberAt:(unsigned)index;
- (BOOL)getBooleanAt:(unsigned)index;
- (NSString*)stringify;
- (NSString*)getString;
- (double)getNumber;
- (BOOL)getBoolean;
- (WDJJsonArray*)getArray;
- (WDJJsonObject*)getObject;
@end

#endif // __WDJJsonArray_DEFINED__

// Windows.Data.Json.JsonObject
#ifndef __WDJJsonObject_DEFINED__
#define __WDJJsonObject_DEFINED__

WINRT_EXPORT
@interface WDJJsonObject : RTObject <WDJIJsonValue>
+ (WDJJsonObject*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input result:(WDJJsonObject**)result;
+ (instancetype)create ACTIVATOR;
@property (readonly) unsigned size;
@property (readonly) WDJJsonValueType valueType;
- (WDJJsonValue*)getNamedValue:(NSString*)name;
- (void)setNamedValue:(NSString*)name value:(RTObject<WDJIJsonValue>*)value;
- (WDJJsonObject*)getNamedObject:(NSString*)name;
- (WDJJsonArray*)getNamedArray:(NSString*)name;
- (NSString*)getNamedString:(NSString*)name;
- (double)getNamedNumber:(NSString*)name;
- (BOOL)getNamedBoolean:(NSString*)name;
- (NSString*)stringify;
- (NSString*)getString;
- (double)getNumber;
- (BOOL)getBoolean;
- (WDJJsonArray*)getArray;
- (WDJJsonObject*)getObject;
// Could not find base class Windows.Foundation.Collections.IMap`2<String,Windows.Data.Json.IJsonValue> type information
- (WDJJsonValue*)getNamedValueOrDefault:(NSString*)name defaultValue:(WDJJsonValue*)defaultValue;
- (WDJJsonObject*)getNamedObjectOrDefault:(NSString*)name defaultValue:(WDJJsonObject*)defaultValue;
- (NSString*)getNamedStringOrDefault:(NSString*)name defaultValue:(NSString*)defaultValue;
- (WDJJsonArray*)getNamedArrayOrDefault:(NSString*)name defaultValue:(WDJJsonArray*)defaultValue;
- (double)getNamedNumberOrDefault:(NSString*)name defaultValue:(double)defaultValue;
- (BOOL)getNamedBooleanOrDefault:(NSString*)name defaultValue:(BOOL)defaultValue;
@end

#endif // __WDJJsonObject_DEFINED__

// Windows.Data.Json.JsonValue
#ifndef __WDJJsonValue_DEFINED__
#define __WDJJsonValue_DEFINED__

WINRT_EXPORT
@interface WDJJsonValue : RTObject <WDJIJsonValue>
+ (WDJJsonValue*)parse:(NSString*)input;
+ (BOOL)tryParse:(NSString*)input result:(WDJJsonValue**)result;
+ (WDJJsonValue*)createBooleanValue:(BOOL)input;
+ (WDJJsonValue*)createNumberValue:(double)input;
+ (WDJJsonValue*)createStringValue:(NSString*)input;
@property (readonly) WDJJsonValueType valueType;
- (NSString*)stringify;
- (NSString*)getString;
- (double)getNumber;
- (BOOL)getBoolean;
- (WDJJsonArray*)getArray;
- (WDJJsonObject*)getObject;
@end

#endif // __WDJJsonValue_DEFINED__

// Windows.Data.Json.JsonError
#ifndef __WDJJsonError_DEFINED__
#define __WDJJsonError_DEFINED__

WINRT_EXPORT
@interface WDJJsonError : RTObject
+ (WDJJsonErrorStatus)getJsonStatus:(int)hresult;
+ (WDJJsonErrorStatus)getStatus:(int)hresult;
@end

#endif // __WDJJsonError_DEFINED__
