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

#include "gtest-api.h"
#import <Foundation/Foundation.h>

static NSCachedURLResponse* _fakeCachedResponse(const std::string& url, size_t length) {
    std::string data(length, '0');
    NSData* cacheData = [NSData dataWithBytes:data.c_str() length:data.size()];
    NSHTTPURLResponse* urlResponse =
        [[NSHTTPURLResponse alloc] initWithURL:[NSURL URLWithString:[NSString stringWithUTF8String:url.c_str()]]
                                    statusCode:200
                                   HTTPVersion:@"1.1"
                                  headerFields:nil];
    NSCachedURLResponse* cachedResponse = [[NSCachedURLResponse alloc] initWithResponse:urlResponse data:cacheData];
    return [cachedResponse autorelease];
}

static void _addFakeCacheResponse(NSURLCache* cache, NSCachedURLResponse* response) {
    [cache storeCachedResponse:response forRequest:[NSURLRequest requestWithURL:[[response response] URL]]];
}

TEST(Foundation, NSURLCache_StorageAndRetrieval) {
    NSURLCache* cache = [[NSURLCache alloc] initWithMemoryCapacity:16 diskCapacity:0 diskPath:nil];
    EXPECT_NO_THROW(_addFakeCacheResponse(cache, _fakeCachedResponse("http://one.com", 4))); // 4 bytes

    EXPECT_OBJCEQ(nil, [cache cachedResponseForRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://not_there.com"]]]);

    NSCachedURLResponse* oneComCached =
        [cache cachedResponseForRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://one.com"]]];
    EXPECT_OBJCNE(nil, oneComCached);
}

TEST(Foundation, NSURLCache_Eviction) {
    NSURLCache* cache = [[NSURLCache alloc] initWithMemoryCapacity:16 diskCapacity:0 diskPath:nil];

    EXPECT_NO_THROW(_addFakeCacheResponse(cache, _fakeCachedResponse("http://one.com", 4))); // 4 bytes
    EXPECT_NO_THROW(_addFakeCacheResponse(cache, _fakeCachedResponse("http://two.com", 13))); // 13 bytes, enough to kick out one.com

    EXPECT_EQ(13, [cache currentMemoryUsage]);

    {
        NSCachedURLResponse* oneComCached =
            [cache cachedResponseForRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://one.com"]]];
        EXPECT_OBJCEQ(nil, oneComCached);
    }

    EXPECT_NO_THROW([cache removeAllCachedResponses]);
    EXPECT_EQ(0, [cache currentMemoryUsage]);
}

TEST(Foundation, NSURLCache_Promotion) {
    NSURLCache* cache = [[NSURLCache alloc] initWithMemoryCapacity:16 diskCapacity:0 diskPath:nil];

    EXPECT_NO_THROW(_addFakeCacheResponse(cache, _fakeCachedResponse("http://one.com", 4))); // 4 bytes
    EXPECT_NO_THROW(_addFakeCacheResponse(cache, _fakeCachedResponse("http://two.com", 4))); // 4 bytes
    EXPECT_NO_THROW(
        _addFakeCacheResponse(cache, _fakeCachedResponse("http://three.com", 9))); // 9 bytes, enough to kick out the oldest entry.

    // The oldest entry should have been bumped.
    EXPECT_OBJCEQ(nil, [cache cachedResponseForRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://one.com"]]]);

    // Adding another entry would bump two... but we want to make it the most recently used.
    // Requesting it promotes it to the head of the line.
    EXPECT_OBJCNE(nil, [cache cachedResponseForRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://two.com"]]]);

    EXPECT_NO_THROW(_addFakeCacheResponse(cache, _fakeCachedResponse("http://one.com", 4))); // 4 bytes, enough to kick out the oldest entry

    // The least recently used entry, three.com, should have disappeared
    EXPECT_OBJCEQ(nil, [cache cachedResponseForRequest:[NSURLRequest requestWithURL:[NSURL URLWithString:@"http://three.com"]]]);
}
