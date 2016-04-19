//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <StubReturn.h>
#import <NSLogging.h>
#import <Foundation/Foundation.h>

static const wchar_t* TAG = L"NSURLComponents";

@implementation NSURLComponents
/**
 @Status Interoperable
 @Notes
*/
+ (instancetype)componentsWithString:(NSString*)URLString {
    return [[[NSURLComponents alloc] initWithString:URLString] autorelease];
}

/**
 @Status Caveat
 @Notes resolvingAgainstBaseURL is not supported
*/
+ (instancetype)componentsWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve {
    return [[[NSURLComponents alloc] initWithURL:url resolvingAgainstBaseURL:resolve] autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)init {
    return [super init];
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)initWithString:(NSString*)URLString {
    NSURL* url = [NSURL URLWithString:URLString];
    return [self initWithURL:url resolvingAgainstBaseURL:NO];
}

/**
 @Status Caveat
 @Notes resolvingAgainstBaseURL is not supported
*/
- (instancetype)initWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve {
    if (resolve) {
        UNIMPLEMENTED_WITH_MSG("resolvingAgainstBaseURL not supported");
        [self release];
        return StubReturn();
    }

    if (self = [super init]) {
        _scheme = [url.scheme copy];
        _host = [url.host copy];
        _path = [url.path copy];
        _queryItems = [[self _parseQuery:url.query] retain];
    }

    return self;
}

- (NSArray*)_parseQuery:(NSString*)query {
    NSMutableArray* queryItems = [NSMutableArray array];

    NSArray* nameValuePairs = [query componentsSeparatedByString:@"&"];

    for (NSString* nameValuePair in nameValuePairs) {
        NSArray* nameAndValue = [nameValuePair componentsSeparatedByString:@"="];

        NSString* name = static_cast<NSString*>(nameAndValue[0]);
        NSString* value = nil;

        if ([nameAndValue count] > 1) {
            NSArray* values = [nameAndValue subarrayWithRange:NSMakeRange(1, [nameAndValue count] - 1)];
            value = [values componentsJoinedByString:@"="];
        }

        name = name.stringByRemovingPercentEncoding;
        value = value.stringByRemovingPercentEncoding;

        NSURLQueryItem* queryItem = [NSURLQueryItem queryItemWithName:name value:value];
        [queryItems addObject:queryItem];
    }

    return queryItems;
}

/**
 @Status Stub
 @Notes
*/
- (NSURL*)URLRelativeToURL:(NSURL*)baseURL {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 These are the characters that won't be percent-encoded in a URL query string
 */
+ (NSCharacterSet*)_unencodedQueryCharacters {
    return [NSCharacterSet characterSetWithCharactersInString:@"*-._abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"];
}

/**
 @Status Caveat
 @Notes Only the scheme, host, path, and query URL components are supported
*/
- (NSURL*)URL {
    @synchronized(self) {
        NSCharacterSet* unencodedChars = [NSURLComponents _unencodedQueryCharacters];
        NSMutableString* urlString = [NSMutableString stringWithCapacity:100];

        // Scheme
        [urlString appendFormat:@"%@:", _scheme];

        // Host
        if (_host != nil) {
            [urlString appendFormat:@"//%@", _host];
        }
        
        // Path
        NSString* encodedPath = [_path stringByAddingPercentEncodingWithAllowedCharacters:[NSCharacterSet URLPathAllowedCharacterSet]];
        [urlString appendString:encodedPath];

        // Query
        BOOL firstItem = YES;

        for (NSURLQueryItem* item in _queryItems) {
            [urlString appendFormat:@"%c%@",
                                    (firstItem ? '?' : '&'),
                                    [item.name stringByAddingPercentEncodingWithAllowedCharacters:unencodedChars]];

            if (item.value != nil) {
                [urlString appendFormat:@"=%@", [item.value stringByAddingPercentEncodingWithAllowedCharacters:unencodedChars]];
            }

            firstItem = NO;
        }

        return [NSURL URLWithString:urlString];
    }
}

/**
 @Status Interoperable
 @Notes
*/
- (NSString*)description {
    return [[self URL] description];
}

- (void)dealloc {
    [_scheme release];
    [_host release];
    [_path release];
    [_queryItems release];
    [super dealloc];
}

@end
