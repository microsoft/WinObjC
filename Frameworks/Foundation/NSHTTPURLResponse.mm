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
#include "Foundation/NSString.h"
#include "Foundation/NSHTTPURLResponse.h"
#include "CoreFoundation/CFDictionary.h"
#include "NSURLResponseInternal.h"
#include "StubReturn.h"

static Boolean CFHTTPHeaderEqual(const void* obj1, const void* obj2) {
    return [(id)obj1 caseInsensitiveCompare:(NSString*)obj2] == 0;
}

static CFHashCode CFHTTPHeaderHash(const void* obj1) {
    return [[(id)obj1 lowercaseString] hash];
}

@implementation NSHTTPURLResponse {
    NSInteger _statusCode;
    StrongId<NSMutableDictionary> _allHeaderFields;
    StrongId<NSString> _HTTPVersion;
}

/**
 @Status Stub
*/
+ (NSString*)localizedStringForStatusCode:(int)code {
    UNIMPLEMENTED();
    return [NSString stringWithFormat:@"Status code %d", code];
}

/**
 @Status Interoperable
*/
- (id)initWithURL:(NSURL*)url statusCode:(NSInteger)statusCode HTTPVersion:(NSString*)HTTPVersion headerFields:(NSDictionary*)headerFields {
    int expectedContentLength = NSURLResponseUnknownLength;
    NSString* mimeType = nil;
    NSString* textEncodingName = nil;
    NSString* filename = nil;
    NSMutableDictionary* allHeaderFields = nil;

    if (headerFields != nil) {
        CFDictionaryKeyCallBacks caseInsensitiveKeyChecker = kCFTypeDictionaryKeyCallBacks;

        caseInsensitiveKeyChecker.equal = CFHTTPHeaderEqual;
        caseInsensitiveKeyChecker.hash = CFHTTPHeaderHash;

        allHeaderFields = (NSMutableDictionary*)
            CFDictionaryCreateMutable(NULL, [headerFields count], &caseInsensitiveKeyChecker, &kCFTypeDictionaryValueCallBacks);

        //  Case insensitive dictionary
        for (id key in [headerFields allKeys]) {
            id val = [headerFields objectForKey:key];
            [allHeaderFields setObject:val forKey:key];
        }

        NSString* expectedLength = [allHeaderFields objectForKey:@"Content-Length"];
        if (nil != expectedLength) {
            expectedContentLength = [expectedLength intValue];
        }

        NSString* contentDisposition = [allHeaderFields objectForKey:@"Content-Disposition"];
        NSRange filenameTagPosition = [contentDisposition rangeOfString:@"filename=" options:NSBackwardsSearch];
        NSCharacterSet* filenameEndDelimiter;

        if (filenameTagPosition.location != NSNotFound) {
            NSUInteger startPos = NSMaxRange(filenameTagPosition); // denotes the start position of the file name
            if ([[contentDisposition substringWithRange:{NSMaxRange(filenameTagPosition), 1}] isEqual:@"\""]) {
                filenameEndDelimiter = [NSCharacterSet characterSetWithCharactersInString:@"\""];
                startPos++; // " is not part of the file name, so start one character further
            } else {
                filenameEndDelimiter = [NSCharacterSet characterSetWithCharactersInString:@"; "];
            }

            NSRange nameRange = {startPos, [contentDisposition length] - startPos};
            NSRange filenameEndPosition = [contentDisposition rangeOfCharacterFromSet:filenameEndDelimiter options:0 range:nameRange];
            if (filenameEndPosition.location == NSNotFound) {
                filenameEndPosition.location = [contentDisposition length] - 1;
            }

            filename = _NSReplaceIllegalFileNameCharacters(
                [contentDisposition substringWithRange:{startPos, filenameEndPosition.location - startPos}]);
        }

        NSArray* contentTypeFields = [[allHeaderFields objectForKey:@"content-type"] componentsSeparatedByString:@";"];
        mimeType = [[contentTypeFields objectAtIndex:0] lowercaseString];
        if ([contentTypeFields count] > 1) {
            NSString* encodingName = [[contentTypeFields objectAtIndex:1] lowercaseString];
            NSRange encodingNameTagPosition = [encodingName rangeOfString:@"charset="];
            textEncodingName = [encodingName substringFromIndex:NSMaxRange(encodingNameTagPosition)];
        }
    }


    if (self = [super _initWithURL:url MIMEType:mimeType expectedContentLength:expectedContentLength textEncodingName:textEncodingName suggestedFilename:filename]) {
        _statusCode = statusCode;
        _HTTPVersion.attach([HTTPVersion copy]);
        _allHeaderFields.attach(allHeaderFields);
    }

    return self;

}

/**
 @Status Interoperable
*/
- (NSInteger)statusCode {
    return _statusCode;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)allHeaderFields {
    // consumers are not allowed to modify our internal state.
    return [[_allHeaderFields copy] autorelease];
}

@end
