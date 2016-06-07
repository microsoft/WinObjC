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

#include "Starboard.h"
#include "StubReturn.h"

#include <CoreFoundation/CFPropertyList.h>

#include <Foundation/NSError.h>
#include <Foundation/NSPropertyListSerialization.h>

@implementation NSPropertyListSerialization

/**
 @Status Interoperable
*/
+ (id)propertyListFromData:(NSData*)data
          mutabilityOption:(NSPropertyListMutabilityOptions)mutability
                    format:(NSPropertyListFormat*)formatOut
          errorDescription:(NSString**)errorString {
    NSError* error = nil;
    id toReturn = [self propertyListWithData:data options:mutability format:formatOut error:&error];

    if (errorString && error) {
        *errorString = [error localizedDescription];
    }

    return toReturn;
}

/**
 @Status Interoperable
*/
+ (id)propertyListWithData:(NSData*)data
                   options:(NSPropertyListReadOptions)options
                    format:(NSPropertyListFormat*)formatOut
                     error:(NSError**)error {
    CFErrorRef cfError = nullptr;
    woc::unique_cf<CFErrorRef> strongError;
    // Cast to result to id. This is safe because a CFPropertyListRef is one of a number of bridged classes but we don't know which ones.
    // Callers expect to be able to directly use them as well so we can't hide it behind a woc::unique_cf or similar composed class.
    id toReturn =
        [(id)CFPropertyListCreateWithData(nullptr, static_cast<CFDataRef>(data), options, (CFPropertyListFormat*)(formatOut), &cfError)
            autorelease];
    strongError.reset(cfError);

    if (error) {
        *error = [(__bridge NSError*)strongError.release() autorelease];
    }

    return toReturn;
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSData*)dataFromPropertyList:(id)plist format:(NSPropertyListFormat)format errorDescription:(NSString**)errorString {
    NSError* error = nil;
    id toReturn = [self dataWithPropertyList:plist format:format options:0 error:&error];

    if (errorString && error) {
        *errorString = [error localizedDescription];
    }

    return toReturn;
}

/**
 @Status Interoperable
 @Notes
*/
+ (NSData*)dataWithPropertyList:(id)plist
                         format:(NSPropertyListFormat)format
                        options:(NSPropertyListWriteOptions)opt
                          error:(NSError* _Nullable*)error {
    THROW_NS_IF_NULL(E_INVALIDARG, plist);

    CFErrorRef cfError = nullptr;
    woc::unique_cf<CFErrorRef> strongError;
    NSData* toReturn = [(__bridge NSData*)
            CFPropertyListCreateData(nullptr, (CFPropertyListRef)plist, static_cast<CFPropertyListFormat>(format), opt, &cfError)
        autorelease];
    strongError.reset(cfError);

    if (error) {
        *error = [(__bridge NSError*)strongError.release() autorelease];
    }

    return toReturn;
}

/**
 @Status Stub
 @Notes
*/
+ (NSInteger)writePropertyList:(id)plist
                      toStream:(NSOutputStream*)stream
                        format:(NSPropertyListFormat)format
                       options:(NSPropertyListWriteOptions)opt
                         error:(NSError* _Nullable*)error {
    // TODO 6669986: call CF version once stream is bridged
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (id)propertyListWithStream:(NSInputStream*)stream
                     options:(NSPropertyListReadOptions)opt
                      format:(NSPropertyListFormat*)format
                       error:(NSError* _Nullable*)error {
    // TODO 6669986: call CF version once stream is bridged
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
 @Notes
*/
+ (BOOL)propertyList:(id)plist isValidForFormat:(NSPropertyListFormat)format {
    return CFPropertyListIsValid((CFPropertyListRef)plist, static_cast<CFPropertyListFormat>(format));
}

@end
