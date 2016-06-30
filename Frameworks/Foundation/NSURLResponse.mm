/* Copyright (c) 2006-2007 Christopher J. W. Lloyd
   Copyright (c) 2016 Microsoft Corporation. All rights reserved.

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

#include <Starboard.h>
#include <StubReturn.h>
#include <Foundation/NSURLResponse.h>
#include "NSURLResponseInternal.h"

@interface NSURLResponse() {
    int _expectedContentLength;
    StrongId<NSString> _mimeType;
    StrongId<NSString> _suggestedFilename;
    StrongId<NSString> _textEncodingName;
    StrongId<NSURL> _url;
}
@end

@implementation NSURLResponse

static NSString* s_invalidFileNameChars = @"\\/:;*\"<>|?";
static NSString* s_unknownFileName = @"Unknown";
static NSString* s_defaultMimeType = @"application/octet-stream";

NSString* _NSReplaceIllegalFileNameCharacters(NSString* fileName) {
    static StrongId<NSCharacterSet> invalidFileNameCharacterSet = [NSCharacterSet characterSetWithCharactersInString:s_invalidFileNameChars];

    if (fileName) {
        if (!NSEqualRanges({NSNotFound, 0}, [fileName rangeOfCharacterFromSet:invalidFileNameCharacterSet])) {
            // remove illegal characters
            NSArray<NSString*>* substrings = [fileName componentsSeparatedByCharactersInSet:invalidFileNameCharacterSet];
            fileName = [substrings componentsJoinedByString:@"_"];
        }

        if ([fileName length] > 0) {
            return fileName;
        }
    }

    return s_unknownFileName;
}

/**
 @Status Interoperable
*/
- (id)init {
    return [self initWithURL:nil MIMEType:s_defaultMimeType expectedContentLength:0 textEncodingName:nil];
}

/**
 @Status Interoperable
*/
- (id)initWithURL:(NSURL*)url MIMEType:(NSString*)mimeType expectedContentLength:(NSInteger)expectedContentLength textEncodingName:(NSString*)textEncodingName {
    return [self _initWithURL:url
        MIMEType:mimeType
        expectedContentLength:expectedContentLength
        textEncodingName:textEncodingName
        suggestedFilename:_NSReplaceIllegalFileNameCharacters([url lastPathComponent])];
}

- (id)_initWithURL:(NSURL*)url
        MIMEType:(NSString*)mimeType
        expectedContentLength:(NSInteger)expectedContentLength
        textEncodingName:(NSString*)textEncodingName
        suggestedFilename:(NSString*)fileName {

    if (self = [super init]) {
        _expectedContentLength = expectedContentLength;
        _url.attach([url copy]);
        _mimeType.attach([mimeType copy]);
        _textEncodingName.attach([textEncodingName copy]);
        if (nil != fileName) {
            _suggestedFilename.attach([fileName copy]);
        } else {
            _suggestedFilename.attach([s_unknownFileName copy]);
        }
    }

    return self;
}

/**
 @Status Interoperable
*/
- (NSString*)MIMEType {
    return [[_mimeType retain] autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)textEncodingName {
    return [[_textEncodingName retain] autorelease];
}

/**
 @Status Interoperable
*/
- (__int64)expectedContentLength {
    return _expectedContentLength;
}

/**
 @Status Interoperable
*/
- (NSURL*)URL {
    return [[_url retain] autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)suggestedFilename {
    return [[_suggestedFilename retain] autorelease];
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

@end
