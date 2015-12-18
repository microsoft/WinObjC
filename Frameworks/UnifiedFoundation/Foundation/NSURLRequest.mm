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

#import <Starboard.h>
#import <Foundation/NSURLRequest.h>
#import <Foundation/NSString.h>
#import <Foundation/NSMutableDictionary.h>
#import <NSURLRequestInternal.h>

@interface NSURLRequest ()
@property (readwrite, copy) NSURL* URL;
@property (readwrite) NSURLRequestCachePolicy cachePolicy;
@property (readwrite) NSTimeInterval timeoutInterval;
@property (readwrite, copy) NSURL* mainDocumentURL;
@property (readwrite) NSURLRequestNetworkServiceType networkServiceType;
@property (readwrite) BOOL HTTPShouldUsePipelining;

@property (readwrite, copy) NSString* HTTPMethod;
@property (readwrite, copy) NSData* HTTPBody;
@property (readwrite, retain) NSInputStream* HTTPBodyStream;
@property (readwrite, copy) NSMutableDictionary* allHTTPHeaderFields;
@property (readwrite) BOOL HTTPShouldHandleCookies;
@property (readwrite) BOOL allowsCellularAccess;
@end

@implementation NSURLRequest
/**
 @Status Caveat
 @Notes cachePolicy and timeoutInterval not supported
*/
- (instancetype)initWithURL:(NSURL*)theURL cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(NSTimeInterval)timeout {
    if (self = [super init]) {
        _URL = [[theURL absoluteURL] retain];
        _timeoutInterval = timeout;
        _allHTTPHeaderFields = [NSMutableDictionary new];
        _HTTPMethod = @"GET";
        _HTTPShouldHandleCookies = YES;
        _cachePolicy = cachePolicy;
    }
    return self;
}

- (instancetype)init {
    return [self initWithURL:nil];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithURL:(NSURL*)theURL {
    return [self initWithURL:theURL cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:60.0];
}

/**
 @Status Interoperable
*/
+ (instancetype)requestWithURL:(NSURL*)theURL {
    return [[[self alloc] initWithURL:theURL] autorelease];
}

/**
 @Status Caveat
 @Notes cachePolicy and timeoutInterval not supported
*/
+ (instancetype)requestWithURL:(NSURL*)theURL cachePolicy:(NSURLRequestCachePolicy)cachePolicy timeoutInterval:(double)timeout {
    return [[[self alloc] initWithURL:theURL cachePolicy:cachePolicy timeoutInterval:timeout] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopyWithZone:(NSZone*)zone {
    NSURLRequest* ret = [[NSMutableURLRequest alloc] initWithURL:_URL cachePolicy:_cachePolicy timeoutInterval:_timeoutInterval];
    ret.allHTTPHeaderFields = _allHTTPHeaderFields;
    ret.HTTPMethod = _HTTPMethod;
    ret.HTTPBody = _HTTPBody;
    ret.HTTPShouldHandleCookies = _HTTPShouldHandleCookies;
    ret.HTTPBodyStream = _HTTPBodyStream;
    ret.mainDocumentURL = _mainDocumentURL;
    ret.networkServiceType = _networkServiceType;
    ret.HTTPShouldUsePipelining = _HTTPShouldUsePipelining;
    ret.allowsCellularAccess = _allowsCellularAccess;
    return ret;
}

/**
 @Status Interoperable
*/
- (void)setAllHTTPHeaderFields:(NSDictionary*)allHTTPHeaderFields {
    id oldValue = _allHTTPHeaderFields;
    _allHTTPHeaderFields = [allHTTPHeaderFields mutableCopy];
    [oldValue release];
}

/**
 @Status Interoperable
*/
- (NSDictionary*)getAllHTTPHeaderFields {
    return _allHTTPHeaderFields;
}

/**
 @Status Interoperable
*/
- (instancetype)mutableCopy {
    return [self mutableCopyWithZone:nil];
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
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
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:_URL forKey:@"URL"];
    [coder encodeObject:_mainDocumentURL forKey:@"mainDocumentURL"];
    [coder encodeObject:_HTTPMethod forKey:@"HTTPMethod"];
    [coder encodeObject:_HTTPBody forKey:@"HTTPBody"];
    //[coder encodeObject:_HTTPBodyStream forKey:@"HTTPBodyStream"];
    [coder encodeObject:_allHTTPHeaderFields forKey:@"allHTTPHeaderFields"];
    [coder encodeInt64:_cachePolicy forKey:@"cachePolicy"];
    [coder encodeDouble:_timeoutInterval forKey:@"timeoutInterval"];
    [coder encodeInt64:_networkServiceType forKey:@"networkServiceType"];
    [coder encodeBool:_HTTPShouldUsePipelining forKey:@"HTTPShouldUsePipelining"];
    [coder encodeBool:_HTTPShouldHandleCookies forKey:@"HTTPShouldHandleCookies"];
    [coder encodeBool:_allowsCellularAccess forKey:@"allowsCellularAccess"];
}

/**
 @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        _URL = [[coder decodeObjectOfClass:[NSURL class] forKey:@"URL"] retain];
        _mainDocumentURL = [[coder decodeObjectOfClass:[NSURL class] forKey:@"mainDocumentURL"] retain];
        _HTTPMethod = [[coder decodeObjectOfClass:[NSString class] forKey:@"HTTPMethod"] retain];
        _HTTPBody = [[coder decodeObjectOfClass:[NSData class] forKey:@"HTTPBody"] retain];
        //_HTTPBodyStream = [[coder decodeObjectOfClass:[NSInputStream class] forKey:@"HTTPBodyStream"] retain];
        _allHTTPHeaderFields = [[coder decodeObjectOfClass:[NSDictionary class] forKey:@"allHTTPHeaderFields"] retain];
        _cachePolicy = (NSURLRequestCachePolicy)[coder decodeInt64ForKey:@"cachePolicy"];
        _timeoutInterval = [coder decodeDoubleForKey:@"timeoutInterval"];
        _networkServiceType = (NSURLRequestNetworkServiceType)[coder decodeInt64ForKey:@"networkServiceType"];
        _HTTPShouldUsePipelining = [coder decodeBoolForKey:@"HTTPShouldUsePipelining"];
        _HTTPShouldHandleCookies = [coder decodeBoolForKey:@"HTTPShouldHandleCookies"];
        _allowsCellularAccess = [coder decodeBoolForKey:@"allowsCellularAccess"];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (NSString*)valueForHTTPHeaderField:(NSString*)field {
    id ret = [_allHTTPHeaderFields objectForKey:field];
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

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_HTTPBodyStream release];
    [_URL release];
    [_mainDocumentURL release];
    [_HTTPMethod release];
    [_HTTPBody release];
    [_allHTTPHeaderFields release];
    [super dealloc];
}

@end
