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
#import "NSJSONInternal.h"
#include "Starboard.h"

#define NSJSONTYPENAMELENGTH 20

@implementation NSJSONSerialization

/**
 @Status Caveat
 @Notes Does not support NSJSONWritingPrettyPrinted
*/
+ (NSData*)dataWithJSONObject:(id)obj options:(NSJSONWritingOptions)opt error:(NSError**)error {
    NSError *internalError = nil;
    if (obj == nil) {
        THROW_NS_HR(E_INVALIDARG);
        return nil;
    }

    WDJJsonObject* jsonObject = [NSJSONSerialization _NSJSONToWDJJsonObject:obj error:&internalError isTopLevel:YES];
    if (internalError != nil) {
        if (error) {
            *error = internalError;
        }

        return nil;
    }

    return [[jsonObject stringify] dataUsingEncoding:NSUTF8StringEncoding];
}

/**
 @Status Caveat
 @Notes Only UTF8 encoding is supported
*/
+ (id)JSONObjectWithData:(NSData*)data options:(NSJSONReadingOptions)opt error:(NSError**)error {
    NSError *internalError = nil;
    if (data == nil) {
        THROW_NS_HR(E_INVALIDARG);
        return nil;
    }

    NSString* jsonString = [[[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] autorelease];
    WDJJsonValue* result;
    BOOL didParse = [WDJJsonValue tryParse:jsonString result:&result];
    id ret = nil;
    if (didParse) {
        ret = [NSJSONSerialization _WDJJsonValueToNSJSON:result
                                                   error:&internalError
                                           allowFragment:(opt & NSJSONReadingAllowFragments)];
    } else {
        internalError = [NSError errorWithDomain:NSCocoaErrorDomain
                                            code:NSPropertyListReadCorruptError
                                            userInfo:@{NSDebugDescriptionKey:@"Invalid JSON string."}];
    }

    if (internalError) {
        ret = nil;
        if (error) {
            *error = internalError;
        }
    }

    return ret;
}

// Copies WDJJsonObject* (a mapping from string to WDJJsonValue*) to NSMutableDictionary
+ (id)_WDJJsonObjectToNSJSON:(WDJJsonObject*)object error:(NSError**)error {
    NSArray* keys = [object allKeys];
    unsigned int size = [keys count];
    NSMutableDictionary* ret = [NSMutableDictionary dictionaryWithCapacity:size];

    for(unsigned int i = 0; i < size; i++) {
        id key = [keys objectAtIndex:i];
        WDJJsonValue* value = [object getNamedValue:(NSString*)key];
        [ret setObject:[NSJSONSerialization _WDJJsonValueToNSJSON:value error:error allowFragment:YES] forKey:key];
        if (*error != nil) {
            ret = nil;
            break;
        }
    }

    return ret;
}

// Copies WDJJsonArray* (an array of WDJJsonValue*) to NSMutableArray
+ (id)_WDJJsonArrayToNSJSON:(WDJJsonArray*)array error:(NSError**)error {
    unsigned int size = [array count];
    NSMutableArray* ret = [NSMutableArray arrayWithCapacity:size];

    for(unsigned int i = 0; i < size; i++) {
        WDJJsonValue* object = UWPObjectCast<WDJJsonValue>([array objectAtIndex:i]);
        [ret addObject:[NSJSONSerialization _WDJJsonValueToNSJSON:object error:error allowFragment:YES]];
        if (*error != nil) {
            ret = nil;
            break;
        }
    }

    return ret;
}

// Copies WDJJsonValue* to the appropriate foundation type
+ (id)_WDJJsonValueToNSJSON:(WDJJsonValue*)value error:(NSError**)error allowFragment:(BOOL)allowFragment {
    switch([value valueType]) {
        case WDJJsonValueTypeNull:
            return [NSNull null];
        case WDJJsonValueTypeBoolean:
            if (allowFragment) {
                return [NSNumber numberWithBool:[value getBoolean]];
            }
            // drop through to error case if allowFragment is false
        case WDJJsonValueTypeNumber:
            if (allowFragment) {
                return [NSNumber numberWithDouble:[value getNumber]];
            }
            // drop through to error case if allowFragment is false
        case WDJJsonValueTypeString:
            if (allowFragment) {
                return [value getString];
            } else {
                // error case - Fragment detected but NSJSONReadingAllowFragments option not specified.
                *error = [NSError errorWithDomain:NSCocoaErrorDomain
                        code:NSPropertyListReadCorruptError
                        userInfo:@{NSDebugDescriptionKey:
                        @"JSON text did not start with array or object and option to allow fragments not set."}];
            }
            break;
        case WDJJsonValueTypeArray:
            // Recursively copy the contents of the array to a new NSMutableArray
            return [NSJSONSerialization _WDJJsonArrayToNSJSON:[value getArray] error:error];
        case WDJJsonValueTypeObject:
            // Recursively copy the contents of the dictionary to a new NSMutableDictionary
            return [NSJSONSerialization _WDJJsonObjectToNSJSON:[value getObject] error:error];
        default:
            *error = [NSError errorWithDomain:NSCocoaErrorDomain code:NSPropertyListReadCorruptError userInfo:nil];
            return [NSNull null];
    }

    return [NSNull null];
}

+ (WDJJsonObject*)_NSJSONToWDJJsonObject:(id)object error:(NSError**)error isTopLevel:(BOOL)isTop {
    WDJJsonObject* ret = NULL;
    if ([object isKindOfClass:[NSDictionary class]]) {
        ret = [[WDJJsonObject create] autorelease];
        for (id key in (NSDictionary*)object) {
            id value = [(NSDictionary*)object objectForKey:key];
            id jsonValue = (id)[NSJSONSerialization _NSJSONToWDJJsonObject:value error:error isTopLevel:NO];
            if (*error != nil) {
                ret = nil;
                break;
            }

            [ret setObject:jsonValue forKey:key];
        }
    } else if ([object isKindOfClass:[NSArray class]]) {
        ret = (WDJJsonObject*)[[WDJJsonArray create] autorelease];
        for (id value in (NSArray*)object) {
            id jsonValue = (id)[NSJSONSerialization _NSJSONToWDJJsonObject:value error:error isTopLevel:NO];
            if (*error != nil) {
                ret = nil;
                break;
            }

            [(WDJJsonArray*)ret addObject:jsonValue];
        }
    } else if ((!isTop) && [object isKindOfClass:[NSNumber class]]) {
        if(strncmp(@encode(BOOL),[(NSNumber*)object objCType], NSJSONTYPENAMELENGTH)) {
            // NSNumber represents a boolean
            ret = (WDJJsonObject*)[WDJJsonValue createBooleanValue:[(NSNumber*)object boolValue]];
        } else {
            ret = (WDJJsonObject*)[WDJJsonValue createNumberValue:[(NSNumber*)object doubleValue]];
        }
    } else if ((!isTop) && [object isKindOfClass:[NSString class]]) {
        ret = (WDJJsonObject*)[WDJJsonValue createStringValue:object];
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

@end