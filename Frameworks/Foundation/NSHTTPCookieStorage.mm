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

#import "Starboard.h"
#import "StubReturn.h"
#import "Foundation/NSMutableArray.h"
#import "Foundation/NSString.h"
#import "Foundation/NSMutableDictionary.h"
#import "Foundation/NSHTTPCookieStorage.h"
#import "Foundation/NSHTTPCookie.h"
#import "LoggingNative.h"
#import "NSHTTPCookieInternal.h"

static const wchar_t* TAG = L"NSHTTPCookieStorage";

void EbrDeleteExternalCookie(id cookie) {
}
id EbrGetExternalCookies(id url) {
    return nil;
}

@implementation NSHTTPCookieStorage

/**
 @Status Caveat
 @Notes Only shared with NSURLProtocol request.  Not shared with WebView control.
*/
+ (NSHTTPCookieStorage*)sharedHTTPCookieStorage {
    static id _shared;
    if (!_shared) {
        _shared = [[self alloc] init];
    }
    return _shared;
}

- (id)_sync {
    static BOOL changed = NO;

    if (!_cookies) {
#ifdef PERSIST_COOKIES
        id cookiesLoader = [NSMutableDictionary alloc];
        id loadedCookies = [_cookies initWithContentsOfFile:@"/Documents/Library/Cookies.plist"];
        if (loadedCookies == nil) {
            [cookiesLoader release];
            _cookies = [[NSMutableDictionary alloc] initWithCapacity:100];
        } else {
            _cookies = [[NSMutableDictionary alloc] initWithCapacity:100];

            for (id curKey in loadedCookies) {
                id cookieProperties = [loadedCookies objectForKey:curKey];
                id curCookie = [[NSHTTPCookie alloc] initWithProperties:cookieProperties];
                [_cookies setObject:curCookie forKey:curKey];
                [curCookie release];
            }
            [cookiesLoader release];
        }
#else
        _cookies = [[NSMutableDictionary alloc] initWithCapacity:100];
#endif
    }

    if (_touched) {
#ifdef PERSIST_COOKIES
        id serializedCookies = [NSMutableDictionary new];
        for (id curCookieKey in _cookies) {
            id curCookie = [_cookies objectForKey:curCookieKey];
            id curCookieProperties = [curCookie properties];
            [serializedCookies setObject:curCookieProperties forKey:curCookieKey];
        }
        [serializedCookies writeToFile:@"/Documents/Library/Cookies.plist" atomically:FALSE];
        [serializedCookies release];
#endif
        _touched = FALSE;
    }
    return self;
}

/**
 @Status Interoperable
*/
- (id)cookies {
    if (!_cookies) {
        [self _sync];
    }

    return [_cookies allValues];
}

/**
 @Status Interoperable
*/
- (NSArray*)cookiesForURL:(NSURL*)url {
    id r = [NSMutableArray arrayWithCapacity:[[self cookies] count]];
    id c = [_cookies objectEnumerator];
    id cookie;
    id urlPath = [url path];
    id urlPathWithSlash = [urlPath stringByAppendingString:@"/"];

    TraceVerbose(TAG, L"Called cookiesForURL!");
    while ((cookie = [c nextObject])) {
        id domain = [cookie domain];
        id path;
        id portList;

        TraceVerbose(TAG, L"domain is %hs", [domain UTF8String]);
        TraceVerbose(TAG, L"host is %hs", [[url host] UTF8String]);
        TraceVerbose(TAG, L"path is %hs", [[url path] UTF8String]);
        if ([domain hasPrefix:@"."]) {
            if (![[url host] hasSuffix:domain]) {
                continue; // does not match suffix
            }
        } else if (![[url host] isEqualToString:domain]) {
            continue; // does not match exact domain
        }

        path = [cookie path];

        if (![path isEqualToString:@"/"] && ![urlPath hasPrefix:path] && ![urlPathWithSlash hasPrefix:path]) {
            continue; // neither "all paths" nor specific path
        }
        /*
        if ([cookie isSecure] && ![[url scheme] hasSuffix:@"s"])
        continue;   // not requested by secure protocol
        */
        // This is very suspect:
        if ((portList = [cookie portList])) {
            if (![portList containsObject:[url port]]) {
                continue; // no match with port list
            }
        }
        [r addObject:cookie]; // exact match
    }

    id externalCookies = EbrGetExternalCookies(url);
    for (id curCookie in externalCookies) {
        [r addObject:curCookie];
    }
    return r;
}

/**
 @Status Interoperable
*/
- (void)deleteCookie:(id)cookie {
    if ([cookie _isExternal]) {
        EbrDeleteExternalCookie(cookie);
    } else {
        [_cookies removeObjectForKey:[NSString stringWithFormat:@"%@/%@/%@", [cookie domain], [cookie path], [cookie name]]];
        _touched = TRUE;
    }
    [self _sync];
}

/**
 @Status Interoperable
*/
- (void)setCookie:(id)cookie {
    id key;
    if (_cookieAcceptPolicy == NSHTTPCookieAcceptPolicyNever) {
        return;
    }
    key = [NSString stringWithFormat:@"%@/%@/%@", [cookie domain], [cookie path], [cookie name]];
    [self _sync];
    [_cookies setObject:cookie forKey:key];
    _touched = YES;
    [self _sync];
}

/**
 @Status Caveat
 @Notes forURL and mainDocumentURL parameters not supported
*/
- (void)setCookies:(id)cookies forURL:(id)url mainDocumentURL:(id)mainURL {
    id c;
    id cookie;
    if (_cookieAcceptPolicy == NSHTTPCookieAcceptPolicyNever) {
        return;
    }
    c = [cookies objectEnumerator];
    while ((cookie = [c nextObject])) {
        [self setCookie:cookie];
    }
}

/**
 @Status Stub
 @Notes
*/
- (id)initWithStorageLocation:(NSURL*)storageFileURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (NSArray*)sortedCookiesUsingDescriptors:(NSArray*)sortOrder {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
