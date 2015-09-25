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
#include "Foundation/NSURLRequest.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSMutableURLRequest.h"
#include "NSURLRequestInternal.h"

@implementation NSURLRequest

- (id)initWithURL:(id)url cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(double)timeout {
    _url = [url absoluteURL];
    _timeoutInterval = timeout;
    _headerFields = [NSMutableDictionary new];
    _method = @"GET";
    _shouldHandleCookies = true;
    _cachePolicy = cachePolicy;
    return self;
}

- (id)init {
    _url = nil;
    _timeoutInterval = 30.0;
    _headerFields = [NSMutableDictionary new];
    _method = @"GET";
    _shouldHandleCookies = true;
    return self;
}

- (id)initWithURL:(id)url {
    return [self initWithURL:url cachePolicy:nil timeoutInterval:30.0];
}

+ (id)requestWithURL:(id)url {
    id ret = [[self alloc] initWithURL:url cachePolicy:nil timeoutInterval:30.0];

    return [ret autorelease];
}

- (id)URL {
    return _url;
}

- (id)allHTTPHeaderFields {
    return _headerFields;
}

- (id)HTTPBody {
    return _body;
}

- (id)HTTPBodyStream {
    return _bodyStream;
}

- (id)HTTPMethod {
    if (_method == nil) {
        _method = @"GET";
    }

    return _method;
}

- (BOOL)HTTPShouldHandleCookies {
    return _shouldHandleCookies;
}

+ (id)requestWithURL:(id)url cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(double)timeout {
    id ret = [[self alloc] initWithURL:url cachePolicy:cachePolicy timeoutInterval:timeout];

    return [ret autorelease];
}

- (id)mutableCopy {
    NSURLRequest* ret = [[NSMutableURLRequest alloc] initWithURL:(id)_url cachePolicy:0 timeoutInterval:30.0];
    ret->_headerFields = [_headerFields mutableCopy];
    ret->_method.attach([_method copy]);
    ret->_body.attach([_body copy]);
    ret->_shouldHandleCookies = _shouldHandleCookies;
    ret->_shouldDiscardData = _shouldDiscardData;
    ret->_cachePolicy = _cachePolicy;
    ret->_bodyStream = _bodyStream;

    return ret;
}

- (id)copyWithZone:(NSZone*)zone {
    return [self retain];
}

- (double)timeoutInterval {
    return _timeoutInterval;
}

- (id)valueForHTTPHeaderField:(id)field {
    id ret = [_headerFields objectForKey:field];
    const char* pName = [field UTF8String];

    if (strcmp(pName, "Accept-Language") == 0) {
        return @"en-us";
    } else if (strcmp(pName, "X-HTTP-Method-Override") == 0) {
        return nil;
    } else {
        if (ret) {
            return ret;
        }

        if (strcmp(pName, "User-Agent") == 0) {
            return nil;
        }
        assert(0);
    }

    return nil;
}

- (id)_setShouldDiscardData:(BOOL)shouldDiscardData {
    _shouldDiscardData = shouldDiscardData != FALSE;

    return 0;
}

- (BOOL)_shouldDiscardData {
    return _shouldDiscardData;
}

- (NSURLRequestCachePolicy)cachePolicy {
    return _cachePolicy;
}

- (void)dealloc {
    _bodyStream = nil;
    _url = nil;
    _method = nil;
    _body = nil;
    [_headerFields release];

    [super dealloc];
}

@end
