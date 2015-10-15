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

Boolean CFHTTPHeaderEqual(const void* obj1, const void* obj2) {
    return [(id)obj1 caseInsensitiveCompare:(NSString*)obj2] == 0;
}

CFHashCode CFHTTPHeaderHash(const void* obj1) {
    return [[(id)obj1 lowercaseString] hash];
}

@implementation NSHTTPURLResponse {
    NSInteger _statusCode;
    NSDictionary* _allHeaderFields;

    idretain _statusLine, _statusVersion;
}
+ (id)localizedStringForStatusCode:(int)code {
    return @"HTTP error";
}

- (id)initWithURL:(id)url statusCode:(DWORD)statusCode headers:(id)headers expectedContentLength:(int)expectedContentLength {
    CFDictionaryKeyCallBacks caseInsensitiveKeyChecker = kCFTypeDictionaryKeyCallBacks;

    caseInsensitiveKeyChecker.equal = CFHTTPHeaderEqual;
    caseInsensitiveKeyChecker.hash = CFHTTPHeaderHash;

    _allHeaderFields =
        (NSDictionary*)CFDictionaryCreateMutable(NULL, [headers count], &caseInsensitiveKeyChecker, &kCFTypeDictionaryValueCallBacks);

    //  Case insensitive dictionary
    for (id key in [headers allKeys]) {
        id val = [headers objectForKey:key];
        [_allHeaderFields setObject:val forKey:key];
    }

    _expectedContentLength = expectedContentLength;
    _url = url;
    _statusCode = statusCode;

    return self;
}

- (int)statusCode {
    return _statusCode;
}

- (id)MIMEType {
    id ret = [[[_allHeaderFields objectForKey:@"content-type"] componentsSeparatedByString:@";"] objectAtIndex:0];
    return ret;
}

- (id)textEncodingName {
    id contentTypeFields = [[_allHeaderFields objectForKey:@"content-type"] componentsSeparatedByString:@"; "];
    if ([contentTypeFields count] > 1) {
        return [contentTypeFields objectAtIndex:1];
    } else {
        return nil;
    }
}

- (NSStringEncoding)encoding {
    id encodingList = [[_allHeaderFields objectForKey:@"content-type"] componentsSeparatedByString:@"; "];

    if ([encodingList count] > 1) {
        id type = [encodingList objectAtIndex:1];
        assert(0);
        return NSUTF8StringEncoding;
    } else {
        return NSUTF8StringEncoding;
    }
}

- (id)allHeaderFields {
    return _allHeaderFields;
}

- (id)setStatusLine:(id)status {
    _statusLine = status;
    return self;
}

- (id)statusLine {
    return _statusLine;
}

- (id)setStatusVersion:(id)version {
    _statusVersion = version;
    return self;
}

- (id)statusVersion {
    return _statusVersion;
}

- (void)dealloc {
    _statusLine = nil;
    _statusVersion = nil;
    [_allHeaderFields release];
    [super dealloc];
}

@end
