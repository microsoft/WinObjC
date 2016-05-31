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

#import <Starboard.h>
#import <StubReturn.h>
#import <Foundation/Foundation.h>

#import <Corefoundation/CFURLComponents.h>

@implementation NSURLComponents {
@private
    woc::unique_cf<CFURLComponentsRef> _cf;
}

/**
 @Status Interoperable
 @Notes
*/
+ (instancetype)componentsWithString:(NSString*)URLString {
    return [[[NSURLComponents alloc] initWithString:URLString] autorelease];
}

/**
 @Status Interoperable
*/
+ (instancetype)componentsWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve {
    return [[[NSURLComponents alloc] initWithURL:url resolvingAgainstBaseURL:resolve] autorelease];
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)init {
    if (self = [super init]) {
        _cf.reset(_CFURLComponentsCreate(kCFAllocatorDefault));
    }
    return self;
}

/**
 @Status Interoperable
 @Notes
*/
- (instancetype)initWithString:(NSString*)URLString {
    if (self = [super init]) {
        _cf.reset(_CFURLComponentsCreateWithString(kCFAllocatorDefault, static_cast<CFStringRef>(URLString)));
    }
    return self;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithURL:(NSURL*)url resolvingAgainstBaseURL:(BOOL)resolve {
    if (self = [super init]) {
        _cf.reset(_CFURLComponentsCreateWithURL(kCFAllocatorDefault, static_cast<CFURLRef>(url), resolve));
    }
    return self;
}

/**
 @Status Interoperable
*/
- (NSString*)string {
    return [static_cast<NSString*>(_CFURLComponentsCopyString(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSURL*)URL {
    return [static_cast<NSURL*>(_CFURLComponentsCopyURL(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (NSURL*)URLRelativeToURL:(NSURL*)baseURL {
    return [static_cast<NSURL*>(_CFURLComponentsCopyURLRelativeToURL(_cf.get(), static_cast<CFURLRef>(baseURL))) autorelease];
}

/**
 @Status Interoperable
*/
- (NSString*)fragment {
    return [static_cast<NSString*>(_CFURLComponentsCopyFragment(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setFragment:(NSString*)fragment {
    _CFURLComponentsSetFragment(_cf.get(), static_cast<CFStringRef>(fragment));
}

/**
 @Status Interoperable
*/
- (NSString*)host {
    return [static_cast<NSString*>(_CFURLComponentsCopyHost(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setHost:(NSString*)host {
    _CFURLComponentsSetHost(_cf.get(), static_cast<CFStringRef>(host));
}

/**
 @Status Interoperable
*/
- (NSString*)password {
    return [static_cast<NSString*>(_CFURLComponentsCopyPassword(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPassword:(NSString*)password {
    _CFURLComponentsSetPassword(_cf.get(), static_cast<CFStringRef>(password));
}

/**
 @Status Interoperable
*/
- (NSString*)path {
    return [static_cast<NSString*>(_CFURLComponentsCopyPath(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPath:(NSString*)path {
    _CFURLComponentsSetPath(_cf.get(), static_cast<CFStringRef>(path));
}

/**
 @Status Interoperable
*/
- (NSNumber*)port {
    return [static_cast<NSNumber*>(_CFURLComponentsCopyPort(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPort:(NSNumber*)port {
    _CFURLComponentsSetPort(_cf.get(), static_cast<CFNumberRef>(port));
}

/**
 @Status Interoperable
*/
- (NSString*)query {
    return [static_cast<NSString*>(_CFURLComponentsCopyQuery(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setQuery:(NSString*)query {
    _CFURLComponentsSetQuery(_cf.get(), static_cast<CFStringRef>(query));
}

/**
 @Status Interoperable
*/
- (NSArray<NSURLQueryItem*>*)queryItems {
    // CF returns this as an array of dictionaries, whereas NS expects an array of NSURLQueryItems
    // Need to do some conversion here
    NSArray<NSDictionary*>* cfQueryItems = [static_cast<NSArray<NSDictionary*>*>(_CFURLComponentsCopyQueryItems(_cf.get())) autorelease];
    NSMutableArray<NSURLQueryItem*>* ret = [NSMutableArray arrayWithCapacity:[cfQueryItems count]];

    for (NSDictionary* queryItem in cfQueryItems) {
        // @"name" and @"value" match keys in CFURLComponents.c
        [ret addObject:[NSURLQueryItem queryItemWithName:queryItem[@"name"] value:queryItem[@"value"]]];
    }

    return ret;
}

/**
 @Status Interoperable
*/
- (void)setQueryItems:(NSArray<NSURLQueryItem*>*)queryItems {
    // NS takes a single array of NSURLQueryItem*s here,
    // whereas CF takes two separate arrays of names and values
    // Need to convert before passing to CF
    NSMutableArray<NSString*>* names = [NSMutableArray arrayWithCapacity:[queryItems count]];
    NSMutableArray<NSString*>* values = [NSMutableArray arrayWithCapacity:[queryItems count]];

    for (NSURLQueryItem* queryItem in queryItems) {
        [names addObject:[queryItem name]];
        [values addObject:[queryItem value]];
    }

    _CFURLComponentsSetQueryItems(_cf.get(), static_cast<CFArrayRef>(names), static_cast<CFArrayRef>(values));
}

/**
 @Status Interoperable
*/
- (NSString*)scheme {
    return [static_cast<NSString*>(_CFURLComponentsCopyScheme(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setScheme:(NSString*)scheme {
    _CFURLComponentsSetScheme(_cf.get(), static_cast<CFStringRef>(scheme));
}

/**
 @Status Interoperable
*/
- (NSString*)user {
    return [static_cast<NSString*>(_CFURLComponentsCopyUser(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setUser:(NSString*)user {
    _CFURLComponentsSetUser(_cf.get(), static_cast<CFStringRef>(user));
}

/**
 @Status Interoperable
*/
- (NSString*)percentEncodedFragment {
    return [static_cast<NSString*>(_CFURLComponentsCopyPercentEncodedFragment(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPercentEncodedFragment:(NSString*)percentEncodedFragment {
    _CFURLComponentsSetPercentEncodedFragment(_cf.get(), static_cast<CFStringRef>(percentEncodedFragment));
}

/**
 @Status Interoperable
*/
- (NSString*)percentEncodedHost {
    return [static_cast<NSString*>(_CFURLComponentsCopyPercentEncodedHost(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPercentEncodedHost:(NSString*)percentEncodedHost {
    _CFURLComponentsSetPercentEncodedHost(_cf.get(), static_cast<CFStringRef>(percentEncodedHost));
}

/**
 @Status Interoperable
*/
- (NSString*)percentEncodedPassword {
    return [static_cast<NSString*>(_CFURLComponentsCopyPercentEncodedPassword(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPercentEncodedPassword:(NSString*)percentEncodedPassword {
    _CFURLComponentsSetPercentEncodedPassword(_cf.get(), static_cast<CFStringRef>(percentEncodedPassword));
}

/**
 @Status Interoperable
*/
- (NSString*)percentEncodedPath {
    return [static_cast<NSString*>(_CFURLComponentsCopyPercentEncodedPath(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPercentEncodedPath:(NSString*)percentEncodedPath {
    _CFURLComponentsSetPercentEncodedPath(_cf.get(), static_cast<CFStringRef>(percentEncodedPath));
}

/**
 @Status Interoperable
*/
- (NSString*)percentEncodedQuery {
    return [static_cast<NSString*>(_CFURLComponentsCopyPercentEncodedQuery(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPercentEncodedQuery:(NSString*)percentEncodedQuery {
    _CFURLComponentsSetPercentEncodedQuery(_cf.get(), static_cast<CFStringRef>(percentEncodedQuery));
}

/**
 @Status Interoperable
*/
- (NSString*)percentEncodedUser {
    return [static_cast<NSString*>(_CFURLComponentsCopyPercentEncodedUser(_cf.get())) autorelease];
}

/**
 @Status Interoperable
*/
- (void)setPercentEncodedUser:(NSString*)percentEncodedUser {
    _CFURLComponentsSetPercentEncodedUser(_cf.get(), static_cast<CFStringRef>(percentEncodedUser));
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    NSURLComponents* ret = [[self class] new];
    if (ret) {
        ret->_cf.reset(_CFURLComponentsCreateCopy(kCFAllocatorDefault, _cf.get()));
    }
    return ret;
}

/**
 @Status Interoperable
 @Notes
*/
- (NSString*)description {
    return [[self URL] description];
}

@end
