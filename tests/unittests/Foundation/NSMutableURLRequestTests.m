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

TEST(NSMutableURLRequest, setValue) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];

    ASSERT_NE_MSG(url, nullptr, "FAILED: url should be non-null!");
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_NE_MSG(urlRequest, nullptr, "FAILED: urlRequest should be non-null!");
    EXPECT_OBJCEQ_MSG(url, [urlRequest URL], "FAILED: url is not valid.");
    EXPECT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  [urlRequest cachePolicy],
                  "FAILED:cachePolicy is not NSURLRequestUseProtocolCachePolicy.");
    EXPECT_EQ_MSG(60.0, [urlRequest timeoutInterval], "FAILED: timeoutInterval is not 60.0.");
    EXPECT_EQ_MSG([urlRequest allHTTPHeaderFields], nil, "FAILED: allHTTPHeaderFields is not null.");
    EXPECT_OBJCEQ_MSG(@"GET", [urlRequest HTTPMethod], "FAILED: HTTPMethod is not GET.");
    EXPECT_EQ_MSG(YES, [urlRequest HTTPShouldHandleCookies], "FAILED: HTTPShouldHandleCookies is not YES.");

    // verify sets
    NSString* contentData = @"ContentData";
    NSString* content = @"Content-Data";
    [urlRequest setValue:contentData forHTTPHeaderField:content];
    NSDictionary* httpFields = [urlRequest allHTTPHeaderFields];
    EXPECT_OBJCEQ_MSG(contentData, [httpFields objectForKey:content], "FAILED: objectForKey is not valid.");
    [contentData release];
    [content release];
}

TEST(NSMutableURLRequest, addValue) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];

    ASSERT_NE_MSG(url, nullptr, "FAILED: url should be non-null!");
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_NE_MSG(urlRequest, nullptr, "FAILED: urlRequest should be non-null!");
    EXPECT_OBJCEQ_MSG(url, [urlRequest URL], "FAILED: url is not valid.");
    EXPECT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  [urlRequest cachePolicy],
                  "FAILED:cachePolicy is not NSURLRequestUseProtocolCachePolicy.");
    EXPECT_EQ_MSG(60.0, [urlRequest timeoutInterval], "FAILED: timeoutInterval is not 60.0.");
    EXPECT_EQ_MSG([urlRequest allHTTPHeaderFields], nil, "FAILED: allHTTPHeaderFields is not null.");
    EXPECT_OBJCEQ_MSG(@"GET", [urlRequest HTTPMethod], "FAILED: HTTPMethod is not GET.");
    EXPECT_EQ_MSG(YES, [urlRequest HTTPShouldHandleCookies], "FAILED: HTTPShouldHandleCookies is not YES.");

    // verify add
    NSString* contentData = @"ContentData";
    NSString* content = @"Content-Data";
    [urlRequest addValue:contentData forHTTPHeaderField:content];
    NSDictionary* httpFields = [urlRequest allHTTPHeaderFields];
    EXPECT_OBJCEQ_MSG(contentData, [httpFields objectForKey:content], "FAILED: objectForKey is not valid.");
    [contentData release];
    [content release];
}

TEST(NSMutableURLRequest, mutableCopy) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];
    ASSERT_NE_MSG(url, nullptr, "FAILED: url should be non-null!");
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_NE_MSG(urlRequest, nullptr, "FAILED: urlRequest should be non-null!");
    NSMutableURLRequest* copyRequest = [urlRequest copy];
    EXPECT_TRUE_MSG([copyRequest isKindOfClass:[NSMutableURLRequest class]], "FAILED: a copy of NSMutableURLRequest should be mutable");
    EXPECT_OBJCEQ_MSG([copyRequest URL], [urlRequest URL], "FAILED: the copy should have the same URL as the original");
    EXPECT_NE_MSG(copyRequest, urlRequest, "FAILED: the copy should not be the same object");
}