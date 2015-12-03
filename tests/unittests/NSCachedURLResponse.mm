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
#import <Foundation/NSCachedURLResponse.h>

TEST(Foundation, NSCachedURLResponse_initWithResponseAndData) {
    NSData* data = [NSData data];
    ASSERT_TRUE_MSG(data != NULL, "FAILED: data should be non-null!");
    NSHTTPURLResponse* urlresponse =
        [[NSHTTPURLResponse alloc] initWithURL:[NSURL URLWithString:@"file:///foo/bar"] statusCode:200 HTTPVersion:@"1.1" headerFields:nil];
    ASSERT_TRUE_MSG(urlresponse != NULL, "FAILED: urlresponse should be non-null!");
    NSCachedURLResponse* cachedResponse = [[NSCachedURLResponse alloc] initWithResponse:urlresponse data:data];

    ASSERT_TRUE_MSG(cachedResponse != NULL, "FAILED: cachedUrlResponse should be non-null!");
    ASSERT_OBJCEQ_MSG(urlresponse, [cachedResponse response], "FAILED: response is not valid");
    ASSERT_OBJCEQ_MSG(data, [cachedResponse data], "FAILED: cachedResponse is not valid");
    ASSERT_EQ_MSG(NSURLCacheStorageAllowed,
                  [cachedResponse storagePolicy],
                  "FAILED: storagePolicy should be %ld",
                  NSURLCacheStorageAllowed);
    ASSERT_EQ_MSG(nil, [cachedResponse userInfo], "FAILED: userInfo should be nil");
    [urlresponse release];
    [cachedResponse release];
}

TEST(Foundation, NSCachedURLResponse_initWithResponseAll) {
    NSData* data = [NSData data];
    NSDictionary* dict = [NSDictionary dictionary];
    ASSERT_TRUE_MSG(data != NULL, "FAILED: data should be non-null!");
    NSHTTPURLResponse* urlresponse =
        [[NSHTTPURLResponse alloc] initWithURL:[NSURL URLWithString:@"file:///foo/bar"] statusCode:200 HTTPVersion:@"1.1" headerFields:nil];
    ASSERT_TRUE_MSG(urlresponse != NULL, "FAILED: urlresponse should be non-null!");
    NSCachedURLResponse* cachedResponse = [[NSCachedURLResponse alloc] initWithResponse:urlresponse
                                                                                   data:data
                                                                               userInfo:dict
                                                                          storagePolicy:NSURLCacheStorageAllowedInMemoryOnly];

    ASSERT_TRUE_MSG(cachedResponse != NULL, "FAILED: cachedUrlResponse should be non-null!");
    ASSERT_OBJCEQ_MSG(urlresponse, [cachedResponse response], "FAILED: response should be valid");
    ASSERT_OBJCEQ_MSG(data, [cachedResponse data], "FAILED: cachedResponse should be valid");
    ASSERT_EQ_MSG(NSURLCacheStorageAllowedInMemoryOnly,
                  [cachedResponse storagePolicy],
                  "FAILED: storagePolicy should be %ld",
                  NSURLCacheStorageAllowedInMemoryOnly);
    ASSERT_OBJCEQ_MSG(dict, [cachedResponse userInfo], "FAILED: userInfo should be valid");

    [urlresponse release];
    [cachedResponse release];
}
// TODO: add unit test for NSCoding - jejeyara
