//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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
#pragma once

#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>

@class NSData;
@class NSOutputStream;
@class NSInputStream;

#import <CoreFoundation/CFPropertyList.h>
#import <Foundation/NSError.h>

enum {
    NSPropertyListImmutable = kCFPropertyListImmutable,
    NSPropertyListMutableContainers = kCFPropertyListMutableContainers,
    NSPropertyListMutableContainersAndLeaves = kCFPropertyListMutableContainersAndLeaves
};

enum {
    NSPropertyListOpenStepFormat = kCFPropertyListOpenStepFormat,
    NSPropertyListXMLFormat_v1_0 = kCFPropertyListXMLFormat_v1_0,
    NSPropertyListBinaryFormat_v1_0 = kCFPropertyListBinaryFormat_v1_0
};

typedef uint32_t NSPropertyListMutabilityOptions;
typedef uint32_t NSPropertyListFormat;
typedef NSPropertyListMutabilityOptions NSPropertyListReadOptions;
typedef NSPropertyListMutabilityOptions NSPropertyListWriteOptions;

FOUNDATION_EXPORT_CLASS
@interface NSPropertyListSerialization : NSObject
+ (NSData*)dataWithPropertyList:(id)plist
                         format:(NSPropertyListFormat)format
                        options:(NSPropertyListWriteOptions)opt
                          error:(NSError* _Nullable*)error;
+ (NSInteger)writePropertyList:(id)plist
                      toStream:(NSOutputStream*)stream
                        format:(NSPropertyListFormat)format
                       options:(NSPropertyListWriteOptions)opt
                         error:(NSError* _Nullable*)error STUB_METHOD;
+ (id)propertyListWithData:(NSData*)data
                   options:(NSPropertyListReadOptions)opt
                    format:(NSPropertyListFormat*)format
                     error:(NSError* _Nullable*)error;
+ (id)propertyListWithStream:(NSInputStream*)stream
                     options:(NSPropertyListReadOptions)opt
                      format:(NSPropertyListFormat*)format
                       error:(NSError* _Nullable*)error STUB_METHOD;
+ (BOOL)propertyList:(id)plist isValidForFormat:(NSPropertyListFormat)format;
+ (NSData*)dataFromPropertyList:(id)plist format:(NSPropertyListFormat)format errorDescription:(NSString* _Nullable*)errorString;
+ (id)propertyListFromData:(NSData*)data
          mutabilityOption:(NSPropertyListMutabilityOptions)opt
                    format:(NSPropertyListFormat*)format
          errorDescription:(NSString* _Nullable*)errorString;
@end
