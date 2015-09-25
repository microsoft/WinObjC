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
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSHTTPCookieStorage.h"
#include "Foundation/NSHTTPCookie.h"

void EbrDeleteExternalCookie(id cookie) {
}
id EbrGetExternalCookies(id url) {
    return nil;
}

@implementation NSHTTPCookieStorage : NSObject
+ (NSHTTPCookieStorage*)sharedHTTPCookieStorage {
    static id _shared;
    if (!_shared)
        _shared = [[self alloc] init];
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

- (id)cookies {
    if (!_cookies)
        [self _sync];

    return [_cookies allValues];
}

- (NSArray*)cookiesForURL:(NSURL*)url {
    id r = [NSMutableArray arrayWithCapacity:[[self cookies] count]];
    id c = [_cookies objectEnumerator];
    id cookie;
    id urlPath = [url path];
    id urlPathWithSlash = [urlPath stringByAppendingString:@"/"];

    EbrDebugLog("Called cookiesForURL!\n");
    while ((cookie = [c nextObject])) {
        id domain = [cookie domain];
        id path;
        id portList;

        EbrDebugLog("domain is %s\n", [domain UTF8String]);
        EbrDebugLog("host is %s\n", [[url host] UTF8String]);
        EbrDebugLog("path is %s\n", [[url path] UTF8String]);
        if ([domain hasPrefix:@"."]) {
            if (![[url host] hasSuffix:domain])
                continue; // does not match suffix
        } else if (![[url host] isEqualToString:domain])
            continue; // does not match exact domain

        path = [cookie path];

        if (![path isEqualToString:@"/"] && ![urlPath hasPrefix:path] && ![urlPathWithSlash hasPrefix:path])
            continue; // neither "all paths" nor specific path
        /*
        if ([cookie isSecure] && ![[url scheme] hasSuffix:@"s"])
        continue;   // not requested by secure protocol
        */
        // This is very suspect:
        if ((portList = [cookie portList])) {
            if (![portList containsObject:[url port]])
                continue; // no match with port list
        }
        [r addObject:cookie]; // exact match
    }

    id externalCookies = EbrGetExternalCookies(url);
    for (id curCookie in externalCookies) {
        [r addObject:curCookie];
    }
    return r;
}

- (void)deleteCookie:(id)cookie {
    if ([cookie _isExternal]) {
        EbrDeleteExternalCookie(cookie);
    } else {
        [_cookies
            removeObjectForKey:[NSString stringWithFormat:@"%@/%@/%@", [cookie domain], [cookie path], [cookie name]]];
        _touched = TRUE;
    }
    [self _sync];
}

- (void)setCookie:(id)cookie {
    id key;
    if (_cookieAcceptPolicy == NSHTTPCookieAcceptPolicyNever)
        return;
    key = [NSString stringWithFormat:@"%@/%@/%@", [cookie domain], [cookie path], [cookie name]];
    [self _sync];
    [_cookies setObject:cookie forKey:key];
    _touched = YES;
    [self _sync];
}

- (void)setCookies:(id)cookies forURL:(id)url mainDocumentURL:(id)mainURL {
    id c;
    id cookie;
    if (_cookieAcceptPolicy == NSHTTPCookieAcceptPolicyNever)
        return;
    c = [cookies objectEnumerator];
    while ((cookie = [c nextObject])) {
        [self setCookie:cookie];
    }
}

- (void)setCookieAcceptPolicy:(int)policy {
    _cookieAcceptPolicy = (NSHTTPCookieAcceptPolicy)policy;
}

@end
