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

// This code is an adaptation of CURL's cookie parsing. It is redone in a more modern style
// but ultimately I tried to stay close to the spirit.

#include "Starboard.h"
#include "Foundation/NSString.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSHTTPCookie.h"
#include "Etc.h"
#include <cctype>
#include <ctype.h>

#define CFREGISTER_STRING(name) const CFStringRef name = (const CFStringRef) @ #name;
#define REGISTER_STRING(name) NSString* const name = @ #name;

REGISTER_STRING(NSHTTPCookieDiscard)
REGISTER_STRING(NSHTTPCookieSecure)
REGISTER_STRING(NSHTTPCookieVersion)
REGISTER_STRING(NSHTTPCookieMaximumAge)
REGISTER_STRING(NSHTTPCookieComment)
REGISTER_STRING(NSHTTPCookieCommentURL)
REGISTER_STRING(NSHTTPCookieOriginURL)
REGISTER_STRING(NSHTTPCookiePort)
REGISTER_STRING(NSHTTPCookieExpires)
REGISTER_STRING(NSPOSIXErrorDomain)
REGISTER_STRING(NSHTTPCookieValue)
REGISTER_STRING(NSHTTPCookieName)
REGISTER_STRING(NSHTTPCookiePath)
REGISTER_STRING(NSHTTPCookieDomain)

/* This is the maximum line length we accept for a cookie line. RFC 2109
section 6.3 says:

"at least 4096 bytes per cookie (as measured by the size of the characters
that comprise the cookie non-terminal in the syntax description of the
Set-Cookie header)"

*/
#define MAX_COOKIE_LINE 5000
#define MAX_COOKIE_LINE_TXT "4999"

/* This is the maximum length of a cookie name we deal with: */
#define MAX_NAME 1024
#define MAX_NAME_TXT "1023"

#define ISBLANK(x) ((((unsigned char)x) == ' ') || (((unsigned char)x) == '\t'))

// This is a simple case-independent string comparison. In CURL this is implemented by hand
// because locales on POSIX make stricmp do nasty things. We're on Windows so don't care. For
// more information see CURL's rawstr.c:88.
bool Curl_raw_equal(const char* a, const char* b) {
    return strcasecmp(a, b) == 0;
}

// Read things from the cookies line and add them to the dictionary
void parseCookies(const char* lineptr, id dict) {
    char name[MAX_NAME], what[MAX_COOKIE_LINE];

    const char* ptr = lineptr;
    const char* nextptr = strchr(ptr, ';');

    do {
        name[0] = what[0] = '\0';
        if (sscanf(ptr, "%" MAX_NAME_TXT "[^;\r\n =]=%" MAX_COOKIE_LINE_TXT "[^;\r\n]", name, what) > 0) {
            const char* endOfName = ptr + strlen(name);
            while (*endOfName && ISBLANK(*endOfName))
                ++endOfName;

            bool sep = *endOfName == '=';

            // Trim first post then pre spaces on the what string.
            size_t whatLen = strlen(what);
            while (whatLen && ISBLANK(what[whatLen - 1])) {
                what[--whatLen] = 0;
            }
            char* whatptr = what;
            while (ISBLANK(*whatptr))
                ++whatptr;

            bool done = false;
            if (whatLen == 0) {
                done = true;
                if (Curl_raw_equal(name, "secure"))
                    [dict setObject:[NSNumber numberWithBool:YES] forKey:NSHTTPCookieSecure];
                else if (Curl_raw_equal(name, "httponly"))
                    ; // CURL cares about httponly cookies but it doesn't seem like we do (in the old impl)
                else if (sep)
                    done = false;
            }

#define ADD_COOKIE_VALUE(name, str) [dict setObject:[NSString stringWithUTF8String:str] forKey:name];

            if (done) {
            } else if ([dict count] == 0) {
                // The first key/val pair are an identifier:
                ADD_COOKIE_VALUE(NSHTTPCookieName, name);
                ADD_COOKIE_VALUE(NSHTTPCookieValue, whatptr);
            } else if (Curl_raw_equal("domain", name)) {
                // CURL validates based on the number of dots in the domain, but this doesn't seem
                // necessary for us.

                if (whatptr[0] == '.')
                    ++whatptr;

                // We should eventually validate this against the domain we're expecting but this wasn't
                // in the original impl so we should do it as needed.

                ADD_COOKIE_VALUE(NSHTTPCookieDomain, whatptr);
            } else if (Curl_raw_equal("path", name)) {
                ADD_COOKIE_VALUE(NSHTTPCookiePath, whatptr);
            } else if (Curl_raw_equal("version", name)) {
                ADD_COOKIE_VALUE(NSHTTPCookieVersion, whatptr);
            } else if (Curl_raw_equal("max-age", name)) {
                ADD_COOKIE_VALUE(NSHTTPCookieMaximumAge, whatptr);
            } else if (Curl_raw_equal("comment", name)) {
                ADD_COOKIE_VALUE(NSHTTPCookieComment, whatptr);
            } else if (Curl_raw_equal("commenturl", name)) {
                ADD_COOKIE_VALUE(NSHTTPCookieCommentURL, whatptr);
            } else if (Curl_raw_equal("originalurl", name)) {
                ADD_COOKIE_VALUE(NSHTTPCookieOriginURL, whatptr);
            } else if (Curl_raw_equal("port", name)) {
                ADD_COOKIE_VALUE(NSHTTPCookiePort, whatptr);
            } else if (Curl_raw_equal("discard", name)) {
                [dict setObject:[NSNumber numberWithBool:YES] forKey:NSHTTPCookieDiscard];
            } else if (Curl_raw_equal("expires", name)) {
                EbrDebugLog("Should parse and set cookie expiration dates!");
            } else {
                EbrDebugLog("Unrecognized cookie name: %s", name);
            }

#undef ADD_COOKIE_VALUE

            if (!nextptr || !*nextptr) {
                nextptr = 0;
                continue;
            }

            // We're done with this one, advance to the next.
            ptr = nextptr + 1;
            while (ISBLANK(*ptr))
                ++ptr;

            nextptr = strchr(ptr, ';');
            if (!nextptr && *ptr) {
                // If we're
                nextptr = strchr(ptr, '\0');
            }
        }
    } while (nextptr);
}

@implementation NSHTTPCookie : NSObject
+ (id)_parseField:(id)field forHeader:(id)header andURL:(id)url {
    // The default path settings:
    id defaultPath = [url path];
    if ([[url absoluteString] hasSuffix:@"/"] == NO)
        defaultPath = [defaultPath stringByDeletingLastPathComponent];
    if (defaultPath == nil)
        defaultPath = @"/";

    id cookieDict = [[NSMutableDictionary alloc] initWithCapacity:0];
    parseCookies([field UTF8String], cookieDict);

    id cookies = [NSMutableArray array];
    if ([cookieDict count] > 0) {
        // Fill in some extra information if we didn't get it in the HTTP request:
        if ([cookieDict objectForKey:NSHTTPCookiePath] == nil)
            [cookieDict setObject:defaultPath forKey:NSHTTPCookiePath];
        if ([cookieDict objectForKey:NSHTTPCookieDomain] == nil)
            [cookieDict setObject:[url host] forKey:NSHTTPCookieDomain];

        id cookie = [NSHTTPCookie cookieWithProperties:cookieDict];

        if (cookie) {
            EbrDebugLog("Added cookie with name=%s value=%s domain=%s\n",
                        [[cookie name] UTF8String],
                        [[cookie value] UTF8String],
                        [[cookie domain] UTF8String]);
            [cookies addObject:cookie];
        }
    }

    return cookies;
}

+ (id)cookiesWithResponseHeaderFields:(id)headerFields forURL:(id)url {
    id cookies = [NSMutableArray array];

    for (id header in [headerFields keyEnumerator]) {
        [cookies addObjectsFromArray:[self _parseField:[headerFields objectForKey:header] forHeader:header andURL:url]];
    }

    return cookies;
}

+ (id)cookieWithProperties:(id)properties {
    return [[[self alloc] initWithProperties:properties] autorelease];
}

+ (id)requestHeaderFieldsWithCookies:(id)cookies {
    // redo me using FOREACH_BEGIN for DD
    id s = nil;
    id e = [cookies objectEnumerator];

    id c;
    while ((c = [e nextObject])) {
        id ss = [NSString stringWithFormat:@"%@=%@", [c name], [c value]]; // On MacOS this method is not protected
                                                                           // against = and ; characters in cookie name
                                                                           // or value - only \n can't occur
        if (s)
            s = [s stringByAppendingFormat:@"; %@", ss];
        else
            s = ss; // first
    }
    if (s) {
        EbrDebugLog("Cookies are %s\n", [s UTF8String]);
        return [NSDictionary dictionaryWithObject:s forKey:@"Cookie"]; // put them all into a single header line
    } else
        return [NSDictionary dictionary]; // empty
}

// Generate these with a macro:

#define GEN_FIELD_GETTER(name, fieldName)            \
                                                     \
    -(id)name {                                      \
        return [_properties objectForKey:fieldName]; \
    }

GEN_FIELD_GETTER(comment, NSHTTPCookieComment)
GEN_FIELD_GETTER(commentURL, NSHTTPCookieCommentURL)
GEN_FIELD_GETTER(domain, NSHTTPCookieDomain)
GEN_FIELD_GETTER(expiresDate, NSHTTPCookieExpires)
GEN_FIELD_GETTER(name, NSHTTPCookieName)
GEN_FIELD_GETTER(path, NSHTTPCookiePath)
GEN_FIELD_GETTER(value, NSHTTPCookieValue)

#undef GEN_FIELD_GETTER

- (unsigned)version {
    return [[_properties objectForKey:NSHTTPCookieVersion] unsignedIntValue];
}

- (id)portList {
    return [[_properties objectForKey:NSHTTPCookiePort] componentsSeparatedByString:@","];
}

- (BOOL)isSecure {
    // return [[_properties objectForKey:NSHTTPCookieSecure] intValue], @"TRUE");
    return TRUE;
}

- (id)isSessionOnly {
    return NO;
}

- (id)properties {
    return _properties;
}

- (id)initWithProperties:(id)properties {
    self = [super init];

    // The following are necessary fields
    assert([[properties objectForKey:NSHTTPCookieName] length] > 0 && [properties objectForKey:NSHTTPCookieValue] &&
           [properties objectForKey:NSHTTPCookiePath] && [properties objectForKey:NSHTTPCookieDomain]);

    NSRange nameNLOffset, valueNLOffset;
    nameNLOffset = [[properties objectForKey:NSHTTPCookieName] rangeOfString:@"\n"];
    valueNLOffset = [[properties objectForKey:NSHTTPCookieValue] rangeOfString:@"\n"];

    assert(nameNLOffset.length == 0 && valueNLOffset.length == 0);

    _properties = [properties mutableCopy];
    [_properties setObject:[NSNumber numberWithDouble:[NSDate timeIntervalSinceReferenceDate]] forKey:@"Created"];
    if (![_properties objectForKey:NSHTTPCookieDiscard])
        [_properties setObject:([[_properties objectForKey:NSHTTPCookieVersion] intValue] >= 1 &&
                                ![_properties objectForKey:NSHTTPCookieMaximumAge])
                                   ? @"TRUE"
                                   : @"FALSE"
                        forKey:NSHTTPCookieDiscard];
    if (![_properties objectForKey:NSHTTPCookieDomain])
        [_properties setObject:[[_properties objectForKey:NSHTTPCookieOriginURL] host] forKey:NSHTTPCookieDomain];

    return self;
}

- (void)dealloc {
    [_properties release];
    [super dealloc];
}

- (id)_setExternal:(bool)external {
    _external = external;
    return self;
}

- (BOOL)_isExternal {
    return _external;
}
@end
