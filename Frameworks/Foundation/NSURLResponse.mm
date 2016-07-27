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

static NSString* const s_invalidFileNameChars = @"\\/:;*\"<>|?";
static NSString* const s_unknownFileName = @"Unknown";
static NSString* const s_defaultMimeType = @"application/octet-stream";
static NSString* const s_NSExpectedContentLength = @"NS.expectedContentLength";
static NSString* const s_NSArchivalMIMEType = @"NS.mimeType";
static NSString* const s_NSArchivalTextEncodingName = @"NS.textEncodingName";
static NSString* const s_NSArchivalSuggestedFilename = @"NS.suggestedFilename";
static NSString* const s_NSArchivalURL = @"NS.url";

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
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        _expectedContentLength = [coder decodeIntForKey:s_NSExpectedContentLength];
        _mimeType = [coder decodeObjectOfClass:[NSString class] forKey:s_NSArchivalMIMEType];
        _suggestedFilename = [coder decodeObjectOfClass:[NSString class] forKey:s_NSArchivalSuggestedFilename];
        _textEncodingName = [coder decodeObjectOfClass:[NSString class] forKey:s_NSArchivalTextEncodingName];
        _url = [coder decodeObjectOfClass:[NSURL class] forKey:s_NSArchivalURL];
    }

    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeInt:_expectedContentLength forKey:s_NSExpectedContentLength];
    [coder encodeObject:_mimeType forKey:s_NSArchivalMIMEType];
    [coder encodeObject:_suggestedFilename forKey:s_NSArchivalSuggestedFilename];
    [coder encodeObject:_textEncodingName forKey:s_NSArchivalTextEncodingName];
    [coder encodeObject:_url forKey:s_NSArchivalURL];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if (other == self) {
        return YES;
    }

    if (![other isKindOfClass:[NSURLResponse class]]) {
        return NO;
    }

    return ([self hash] == [other hash]);
}

/**
 @Status Interoperable
*/
- (NSUInteger)hash {
    unsigned ret = _expectedContentLength;
    if (_suggestedFilename) {
        ret ^= [_suggestedFilename hash];
    }

    if (_mimeType) {
        ret ^= [_mimeType hash];
    }

    if (_textEncodingName) {
        ret ^= [_textEncodingName hash];
    }

    if (_url) {
        ret ^= [_url hash];
    }

    return ret;
}

@end
