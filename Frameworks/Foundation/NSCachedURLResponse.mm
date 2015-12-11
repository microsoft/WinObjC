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
#import <Foundation/NSCachedURLResponse.h>

@interface NSCachedURLResponse ()
@property (readwrite, copy) NSData* data;
@property (readwrite, copy) NSURLResponse* response;
@property (readwrite) NSURLCacheStoragePolicy storagePolicy;
@property (readwrite, copy) NSDictionary* userInfo;
@end

@implementation NSCachedURLResponse

- (id)initWithResponse:(NSURLResponse*)response
                  data:(NSData*)data
              userInfo:(NSDictionary*)userInfo
         storagePolicy:(NSURLCacheStoragePolicy)storagePolicy {
    if (self = [self initWithResponse:response data:data]) {
        _userInfo = [userInfo copy];
        _storagePolicy = storagePolicy;
    }

    return self;
}

- (id)initWithResponse:(NSURLResponse*)response data:(NSData*)data {
    if (self = [super init]) {
        _response = [response copy];
        _data = [data copy];
        _storagePolicy = NSURLCacheStorageAllowed;
    }

    return self;
}

- (id)copyWithZone:(NSZone*)zone {
    NSCachedURLResponse* copy = [[self class] allocWithZone:zone];
    if (copy != nil) {
        copy.data = _data;
        copy.response = _response;
        copy.userInfo = _userInfo;
        copy.storagePolicy = _storagePolicy;
    }

    return copy;
}

+ (BOOL)supportsSecureCoding {
    return YES;
}

- (id)initWithCoder:(NSCoder*)coder {
    if (self = [super initWithCoder:coder]) {
        _data = [[coder decodeObjectForKey:@"data"] retain];
        _response = [[coder decodeObjectForKey:@"response"] retain];
        NSDictionary* userInfoDict = [coder decodeObjectForKey:@"userInfo"];
        _userInfo = [[[NSMutableDictionary alloc] initWithDictionary:_userInfo copyItems:YES] retain];
        self.storagePolicy = (NSURLCacheStoragePolicy)[coder decodeInt64ForKey:@"storagePolicy"];
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:_data forKey:@"data"];
    [coder encodeObject:_response forKey:@"response"];
    [coder encodeObject:_userInfo forKey:@"userInfo"];
    [coder encodeInt64:_storagePolicy forKey:@"storagePolicy"];
}

- (void)dealloc {
    [_response release];
    [_data release];
    [_userInfo release];
    [super dealloc];
}

@end
