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

#import <Foundation/Foundation.h>
#import <Foundation/FoundationErrors.h>
#include "Starboard.h"
#include "StubReturn.h"

#include <COMIncludes.h>
#include <wrl\client.h>
#include <wrl\wrappers\corewrappers.h>
#include <windows.foundation.collections.h>
#include <windows.data.json.h>
#include <COMIncludes_End.h>

#include "StringHelpers.h"
#include "WRLHelpers.h"

using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::Data::Json;
using namespace Microsoft::WRL;
using namespace Windows::Foundation;

#define NSJSONTYPENAMELENGTH 20

@implementation NSJSONSerialization

// Helper to convert between NSJSon object model and winRT object model.
// Specifically converts between base foundation types like Dictionary/Array and
// coverts to a Windows::Data::Json::IJsonValue object.
ComPtr<IJsonValue> _NSJSONToWDJJsonValue(id object, BOOL isTop) {
    ComPtr<IJsonValue> ret;

    ComPtr<IJsonValueStatics> jsonValueStatics;
    THROW_NS_IF_FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Data_Json_JsonValue).Get(), &jsonValueStatics));

    if ([object isKindOfClass:[NSDictionary class]]) {
        ComPtr<IJsonObject> jsonObject;
        THROW_NS_IF_FAILED(ActivateInstance(Wrappers::HStringReference(RuntimeClass_Windows_Data_Json_JsonObject).Get(), &jsonObject));
        THROW_NS_IF_FAILED(jsonObject.As(&ret));

        for (id key in(NSDictionary*)object) {
            id value = [(NSDictionary*)object objectForKey:key];
            ComPtr<IJsonValue> jsonValue = _NSJSONToWDJJsonValue(value, NO);

            auto wrlKey = Strings::NarrowToWide<HSTRING>(key);
            THROW_NS_IF_FAILED(jsonObject->SetNamedValue(wrlKey.Get(), jsonValue.Get()));
        }
    } else if ([object isKindOfClass:[NSArray class]]) {
        ComPtr<IJsonArray> array;
        THROW_NS_IF_FAILED(ActivateInstance(Wrappers::HStringReference(RuntimeClass_Windows_Data_Json_JsonArray).Get(), &array));
        THROW_NS_IF_FAILED(array.As(&ret));
        for (id value in(NSArray*)object) {
            ComPtr<IJsonValue> jsonValue = _NSJSONToWDJJsonValue(value, NO);

            ComPtr<IVector<IJsonValue*>> jsonArray;
            THROW_NS_IF_FAILED(ret.As(&jsonArray));
            THROW_NS_IF_FAILED(jsonArray->Append(jsonValue.Get()));
        }
    } else if ((!isTop) && [object isKindOfClass:[NSNumber class]]) {
        // Check if the number is NSCFBoolean
        if ([object isKindOfClass:[static_cast<NSNumber*>(kCFBooleanTrue) class]]) {
            // NSNumber represents a boolean
            THROW_NS_IF_FAILED(jsonValueStatics->CreateBooleanValue([(NSNumber*)object boolValue], ret.GetAddressOf()));
        } else {
            THROW_NS_IF_FAILED(jsonValueStatics->CreateNumberValue([(NSNumber*)object doubleValue], ret.GetAddressOf()));
        }
    } else if ((!isTop) && [object isKindOfClass:[NSString class]]) {
        THROW_NS_IF_FAILED(jsonValueStatics->CreateStringValue(Strings::NarrowToWide<HSTRING>(object).Get(), ret.GetAddressOf()));
    } else {
        // Top level object must be one of NSDictionary or NSArray
        if (isTop) {
            THROW_NS_HR_MSG(E_INVALIDARG, "Invalid top-level type (%@) in JSON write", [object class]);
        } else {
            THROW_NS_HR_MSG(E_INVALIDARG, "Invalid type (%@) in JSON write", [object class]);
        }
    }

    return ret;
}

// Copies IJsonObject* (a mapping from string to WDJJsonValue*) to NSMutableDictionary
id _WDJJsonObjectToNSJSON(const ComPtr<IJsonObject>& object, NSError** error) {
    ComPtr<IMap<HSTRING, IJsonValue*>> map;

    THROW_NS_IF_FAILED(object.As(&map));
    NSMutableDictionary* ret = [NSMutableDictionary new];

    // clang-format off
    HRESULT hr = WRLHelpers::ForEach(
        map,
        [&ret, &error](
            const ComPtr<ABI::Windows::Foundation::Collections::IKeyValuePair<HSTRING, IJsonValue*>>& pair,
            boolean* stop) {
            
            // Get V from KVP and then add to dictionary
            ComPtr<IJsonValue> value;
            RETURN_IF_FAILED(pair->get_Value(&value));

            Wrappers::HString key;
            RETURN_IF_FAILED(pair->get_Key(key.GetAddressOf()));

            [ret setObject:_WDJJsonValueToNSJSON(value, error, YES) forKey:Strings::WideToNSString(key.Get())];


            if (*error != nil) {
                ret = nil;
                *stop = true;
            }

            return S_OK;
        });
    // clang-format on

    // Written as a separate line to avoid warnings about unused returns from inner lambda macros. Not exactly sure why but
    // this placates things.
    THROW_NS_IF_FAILED(hr);

    return ret;
}

// Copies ComPtr<IJsonArray> (an array of WDJJsonValue*) to NSMutableArray
id _WDJJsonArrayToNSJSON(const ComPtr<IJsonArray>& array, NSError** error) {
    NSMutableArray* ret = [NSMutableArray new];

    ComPtr<IVector<IJsonValue*>> vector;
    THROW_NS_IF_FAILED(array.As(&vector));

    // clang-format off
    THROW_NS_IF_FAILED(WRLHelpers::ForEach(
        vector,
        [&ret, &error](
            const ComPtr<IJsonValue>& value,
            boolean* stop) {

            [ret addObject:_WDJJsonValueToNSJSON(value, error, YES)];
            if (*error != nil) {
                ret = nil;
                *stop = true;
            }

            return S_OK;
        }));
    // clang-format on

    return ret;
}

// Copies ComPtr<IJsonValue> to the appropriate foundation type
id _WDJJsonValueToNSJSON(const ComPtr<IJsonValue>& value, NSError** error, BOOL allowFragment) {
    JsonValueType valueType;
    THROW_NS_IF_FAILED(value->get_ValueType(&valueType));

    switch (valueType) {
        case JsonValueType_Null:
            return [NSNull null];
        case JsonValueType_Boolean:
            if (allowFragment) {
                boolean boolValue = false;
                THROW_NS_IF_FAILED(value->GetBoolean(&boolValue));
                return [NSNumber numberWithBool:boolValue];
            }
        // drop through to error case if allowFragment is false
        case JsonValueType_Number:
            if (allowFragment) {
                double doubleValue = 0;
                THROW_NS_IF_FAILED(value->GetNumber(&doubleValue));
                return [NSNumber numberWithDouble:doubleValue];
            }
        // drop through to error case if allowFragment is false
        case JsonValueType_String:
            if (allowFragment) {
                Wrappers::HString string;
                THROW_NS_IF_FAILED(value->GetString(string.GetAddressOf()));
                return Strings::WideToNSString(string.Get());
            } else {
                // error case - Fragment detected but NSJSONReadingAllowFragments option not specified.
                *error = [NSError errorWithDomain:NSCocoaErrorDomain
                                             code:NSPropertyListReadCorruptError
                                         userInfo:@{
                                             NSDebugDescriptionKey :
                                                 @"JSON text did not start with array or object and option to allow fragments not set."
                                         }];
            }
            break;
        case JsonValueType_Array: {
            // Recursively copy the contents of the array to a new NSMutableArray
            ComPtr<IJsonArray> array;
            THROW_NS_IF_FAILED(value->GetArray(&array));
            return _WDJJsonArrayToNSJSON(array, error);
        }
        case JsonValueType_Object: {
            // Recursively copy the contents of the dictionary to a new NSMutableDictionary
            ComPtr<IJsonObject> object;
            THROW_NS_IF_FAILED(value->GetObject(&object));
            return _WDJJsonObjectToNSJSON(object, error);
        }
        default:
            *error = [NSError errorWithDomain:NSCocoaErrorDomain code:NSPropertyListReadCorruptError userInfo:nil];
            return [NSNull null];
    }

    return [NSNull null];
}

/**
 @Status Caveat
 @Notes Does not support NSJSONWritingPrettyPrinted
*/
+ (NSData*)dataWithJSONObject:(id)obj options:(NSJSONWritingOptions)opt error:(NSError**)error {
    NSError* internalError = nil;
    // THROW_NS_IF_NULL(E_INVALIDARG, obj);

    ComPtr<IJsonValue> jsonValue = _NSJSONToWDJJsonValue(obj, YES);
    Wrappers::HString stringObject;

    THROW_NS_IF_FAILED(jsonValue->Stringify(stringObject.GetAddressOf()));

    return [Strings::WideToNSString(stringObject.Get()) dataUsingEncoding:NSUTF8StringEncoding];
}

/**
 @Status Caveat
 @Notes Only UTF8 encoding is supported
*/
+ (id)JSONObjectWithData:(NSData*)data options:(NSJSONReadingOptions)opt error:(NSError**)error {
    NSError* internalError = nil;

    THROW_NS_IF_NULL(E_INVALIDARG, data);

    ComPtr<IJsonValueStatics> jsonValueStatics;
    THROW_NS_IF_FAILED(GetActivationFactory(Wrappers::HStringReference(RuntimeClass_Windows_Data_Json_JsonValue).Get(), &jsonValueStatics));

    NSString* jsonString = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];

    boolean didParse = false;
    ComPtr<IJsonValue> result;
    THROW_NS_IF_FAILED(jsonValueStatics->TryParse(Strings::NarrowToWide<HSTRING>(jsonString).Get(), &result, &didParse));

    id ret = nil;
    if (didParse) {
        ret = _WDJJsonValueToNSJSON(result, &internalError, (opt & NSJSONReadingAllowFragments));
    } else {
        internalError = [NSError errorWithDomain:NSCocoaErrorDomain
                                            code:NSPropertyListReadCorruptError
                                        userInfo:@{
                                            NSDebugDescriptionKey : @"Invalid JSON string."
                                        }];
    }

    if (internalError) {
        ret = nil;
        if (error) {
            *error = internalError;
        }
    }

    return ret;
}

/**
 @Status Stub
 @Notes
*/
+ (id)JSONObjectWithStream:(NSInputStream*)stream options:(NSJSONReadingOptions)opt error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSInteger)writeJSONObject:(id)obj toStream:(NSOutputStream*)stream options:(NSJSONWritingOptions)opt error:(NSError* _Nullable*)error {
    UNIMPLEMENTED();
    return StubReturn();
}

// Returns true if the dictionary or array value is a valid JSON leaf
static BOOL _isValidLeaf(id value) {
    if ([value isKindOfClass:[NSString class]]) {
        return YES;
    } else if ([value isKindOfClass:[NSNumber class]]) {
        if ([value isEqualToNumber:((NSNumber*)kCFNumberNaN)] || [value isEqualToNumber:((NSNumber*)kCFNumberPositiveInfinity)] ||
            [value isEqualToNumber:((NSNumber*)kCFNumberNegativeInfinity)]) {
            return NO;
        }

        return YES;
    } else if ([value isKindOfClass:[NSNull class]]) {
        return YES;
    }

    return NO;
}

/**
 @Status Interoperable
 @Notes An object that may be converted to JSON must have the following properties:
    -The top level object is an NSArray or NSDictionary.
    -All objects are instances of NSString, NSNumber, NSArray, NSDictionary, or NSNull.
    -All dictionary keys are instances of NSString.
    -Numbers are not NaN or infinity.
*/
+ (BOOL)isValidJSONObject:(id)object {
    if ([object isKindOfClass:[NSDictionary class]]) {
        for (id key in(NSDictionary*)object) {
            if (![key isKindOfClass:[NSString class]]) {
                return NO;
            }
            id value = [(NSDictionary*)object objectForKey:key];
            if (_isValidLeaf(value)) {
                continue;
            } else if (![NSJSONSerialization isValidJSONObject:value]) {
                return NO;
            }
        }
    } else if ([object isKindOfClass:[NSArray class]]) {
        for (id value in(NSArray*)object) {
            if (_isValidLeaf(value)) {
                continue;
            } else if (![NSJSONSerialization isValidJSONObject:value]) {
                return NO;
            }
        }
    } else {
        return NO;
    }

    return YES;
}
@end