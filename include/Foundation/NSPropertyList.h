/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#import <Foundation/NSObject.h>
#import <CoreFoundation/CFPropertyList.h>

typedef uint32_t NSPropertyListWriteOptions;

@class NSData;
@class NSError;

enum {
   NSPropertyListImmutable = kCFPropertyListImmutable,
   NSPropertyListMutableContainers = kCFPropertyListMutableContainers,
   NSPropertyListMutableContainersAndLeaves = kCFPropertyListMutableContainersAndLeaves
};
typedef uint32_t NSPropertyListMutabilityOptions;

typedef uint32_t NSPropertyListReadOptions;

typedef enum {
   NSPropertyListOpenStepFormat,
   NSPropertyListXMLFormat_v1_0,
   NSPropertyListBinaryFormat_v1_0,
} NSPropertyListFormat;

FOUNDATION_EXPORT_CLASS
@interface NSPropertyListSerialization : NSObject

+(BOOL)propertyList:propertyList isValidForFormat:(NSPropertyListFormat)format;

+(NSData *)dataFromPropertyList:plist format:(NSPropertyListFormat)format errorDescription:(NSString **)errorDescriptionp;
+(NSData *)dataWithPropertyList:(id)plist format:(NSPropertyListFormat)format options:(NSPropertyListWriteOptions)opt error:(NSError **)error;

+propertyListFromData:(NSData *)data mutabilityOption:(NSPropertyListMutabilityOptions)mutability format:(NSPropertyListFormat *)format errorDescription:(NSString **)errorDescriptionp;

+(id)propertyListWithData:(NSData *)data options:(NSPropertyListReadOptions)opt format:(NSPropertyListFormat *)format error:(NSError **)error;

@end
