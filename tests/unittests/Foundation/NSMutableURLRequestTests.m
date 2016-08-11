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

    ASSERT_NE(url, nil);
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_NE(urlRequest, nil);
    EXPECT_OBJCEQ(url, [urlRequest URL]);
    EXPECT_EQ(NSURLRequestUseProtocolCachePolicy, [urlRequest cachePolicy]);
    EXPECT_EQ(60.0, [urlRequest timeoutInterval]);
    EXPECT_EQ([urlRequest allHTTPHeaderFields], nil);
    EXPECT_OBJCEQ(@"GET", [urlRequest HTTPMethod]);
    EXPECT_EQ(YES, [urlRequest HTTPShouldHandleCookies]);

    // verify sets
    NSString* contentData = @"ContentData";
    NSString* content = @"Content-Data";
    [urlRequest setValue:contentData forHTTPHeaderField:content];
    NSDictionary* httpFields = [urlRequest allHTTPHeaderFields];
    EXPECT_OBJCEQ(contentData, [httpFields objectForKey:content]);
    [contentData release];
    [content release];
}

TEST(NSMutableURLRequest, addValue) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];

    ASSERT_NE(url, nil);
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_NE(urlRequest, nil);
    EXPECT_OBJCEQ(url, [urlRequest URL]);
    EXPECT_EQ(NSURLRequestUseProtocolCachePolicy, [urlRequest cachePolicy]);
    EXPECT_EQ(60.0, [urlRequest timeoutInterval]);
    EXPECT_EQ([urlRequest allHTTPHeaderFields], nil);
    EXPECT_OBJCEQ(@"GET", [urlRequest HTTPMethod]);
    EXPECT_EQ(YES, [urlRequest HTTPShouldHandleCookies]);

    // verify add
    NSString* contentData = @"ContentData";
    NSString* content = @"Content-Data";
    [urlRequest addValue:contentData forHTTPHeaderField:content];
    NSDictionary* httpFields = [urlRequest allHTTPHeaderFields];
    EXPECT_OBJCEQ(contentData, [httpFields objectForKey:content]);
    [contentData release];
    [content release];
}

TEST(NSMutableURLRequest, mutableCopy) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];
    ASSERT_NE(url, nil);
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_NE(urlRequest, nil);
    NSMutableURLRequest* copyRequest = [urlRequest copy];
    EXPECT_TRUE([copyRequest isKindOfClass:[NSMutableURLRequest class]]);
    EXPECT_OBJCEQ([copyRequest URL], [urlRequest URL]);
    EXPECT_NE(copyRequest, urlRequest);

    [copyRequest setValue:@"VALUE" forHTTPHeaderField:@"httpHeaderField"];
    EXPECT_EQ([urlRequest valueForHTTPHeaderField:@"httpHeaderField"], nil);
    EXPECT_OBJCEQ([copyRequest valueForHTTPHeaderField:@"httpHeaderField"], @"VALUE");
}