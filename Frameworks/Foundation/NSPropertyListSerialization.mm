/* Copyright (c) 2006-2007 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit
persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

// Original - Christopher Lloyd <cjwl@objc.net>

#include "Starboard.h"

#include "Foundation/NSString.h"
#include "Foundation/NSMutableData.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSNull.h"
#include "Foundation/NSPropertyList.h"
#include "Foundation/NSKeyedArchiver.h"
#include "NSPropertyListReader.h"
#include "NSPropertyListWriter_binary.h"

#import "NSXMLPropertyList.h"

void printContents(int level, id obj);

@implementation NSPropertyListSerialization : NSObject
+ (id)propertyListFromData:(NSData*)data
          mutabilityOption:(unsigned)mutability
                    format:(NSPropertyListFormat*)formatOut
          errorDescription:(NSString**)error {
    if (data == nil) {
        EbrDebugLog("propertyListFromData: data is nil!\n");
        if (error)
            *error = @"Data was null.";

        return nil;
    }

    unsigned len = [data length];
    if (len == 0) {
        EbrDebugLog("propertyListFromData: data is too short!\n");
        if (error)
            *error = @"Data is too short.";

        return nil;
    }

    char* bytes = (char*)[data bytes];
    if (len >= 4 && memcmp(bytes, "<?xml", 4) == 0) {
        id ret = [NSXMLPropertyList propertyListFromData:data];

        if (ret == nil) {
            EbrDebugLog("propertyListFromData: return is nil!\n");
            if (error)
                *error = @"No objects.";

            return nil;
        }

        if (formatOut) {
            *formatOut = NSPropertyListXMLFormat_v1_0;
        }

        return ret;
    } else if (len >= 6 && memcmp(bytes, "bplist", 6) == 0) {
        /*
        NSPropertyListReader* reader = [[NSPropertyListReader alloc] initWithData:data];
        [reader setMutabilityFlags:mutability];
        id ret = [reader read];
        [reader release];
        */
        NSPropertyListReaderA read;
        read.init(data);
        id ret = read.read();

        if (ret == nil) {
            EbrDebugLog("propertyListFromData: return is nil!\n");
            if (error)
                *error = @"No objects.";

            return nil;
        }

        if (formatOut)
            *formatOut = NSPropertyListBinaryFormat_v1_0;

        return ret;
    } else if (len >= 2 && memcmp(bytes, "\xfe\xff", 2) == 0) {
        NSString* str = [[NSString alloc] initWithData:data encoding:NSUTF16BigEndianStringEncoding];
        id ret = [str propertyListFromStringsFileFormat];
        [str release];
        return ret;
    } else {
        return nil;
    }
}

+ (id)propertyListWithData:(NSData*)data
                   options:(unsigned)options
                    format:(NSPropertyListFormat*)formatOut
                     error:(NSError**)error {
    // [TODO] Not that this uses a different error format than ours. Below takes a string, we return an NSError.
    return [self propertyListFromData:data mutabilityOption:options format:formatOut errorDescription:NULL];
}

+ (NSData*)dataFromPropertyList:(id)plist format:(NSPropertyListFormat)format errorDescription:(NSString**)error {
    switch (format) {
        case NSPropertyListOpenStepFormat:
            assert(0);
            break;

#if 0
case NSPropertyListXMLFormat_v1_0:
return [NSPropertyListWriter_xml dataWithPropertyList:plist];
#endif

        case NSPropertyListBinaryFormat_v1_0: {
            NSMutableData* data = [NSMutableData data];
            [NSPropertyListWriter_Binary serializePropertyList:plist intoData:data];
            return data;
        }

        default:
#if 0
EbrDebugLog("Couldn't serialize to this format, defaulting to XML!\n");
return [NSPropertyListWriter_xml dataWithPropertyList:plist];
#endif
            break;
    }

    return nil;
}

@end
