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
#import <Foundation/NSMutableURLRequest.h>
#import <Foundation/NSURL.h>

TEST(Foundation, NSMutableURLRequest_setValue) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];

    ASSERT_TRUE_MSG(url != NULL, "FAILED: url should be non-null!");
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_TRUE_MSG(urlRequest != NULL, "FAILED: urlRequest should be non-null!");
    ASSERT_OBJCEQ_MSG(url, [urlRequest URL], "FAILED: url is not valid.");
    ASSERT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  [urlRequest cachePolicy],
                  "FAILED:cachePolicy is not NSURLRequestUseProtocolCachePolicy.");
    ASSERT_EQ_MSG(60.0, [urlRequest timeoutInterval], "FAILED: timeoutInterval is not 60.0.");
    ASSERT_TRUE_MSG([urlRequest allHTTPHeaderFields] != nil, "FAILED: allHTTPHeaderFields is null.");
    ASSERT_OBJCEQ_MSG(@"GET", [urlRequest HTTPMethod], "FAILED: HTTPMethod is not GET.");
    ASSERT_EQ_MSG(YES, [urlRequest HTTPShouldHandleCookies], "FAILED: HTTPShouldHandleCookies is not YES.");

    // verify sets
    NSString* contentData = @"ContentData";
    NSString* content = @"Content-Data";
    [urlRequest setValue:contentData forHTTPHeaderField:content];
    NSDictionary* httpFields = [urlRequest allHTTPHeaderFields];
    ASSERT_OBJCEQ_MSG(contentData, [httpFields objectForKey:content], "FAILED: objectForKey is not valid.");
    [contentData release];
    [content release];
}

TEST(Foundation, NSMutableURLRequest_addValue) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];

    ASSERT_TRUE_MSG(url != NULL, "FAILED: url should be non-null!");
    NSMutableURLRequest* urlRequest = [NSMutableURLRequest requestWithURL:url];
    ASSERT_TRUE_MSG(urlRequest != NULL, "FAILED: urlRequest should be non-null!");
    ASSERT_OBJCEQ_MSG(url, [urlRequest URL], "FAILED: url is not valid.");
    ASSERT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  [urlRequest cachePolicy],
                  "FAILED:cachePolicy is not NSURLRequestUseProtocolCachePolicy.");
    ASSERT_EQ_MSG(60.0, [urlRequest timeoutInterval], "FAILED: timeoutInterval is not 60.0.");
    ASSERT_TRUE_MSG([urlRequest allHTTPHeaderFields] != nil, "FAILED: allHTTPHeaderFields is null.");
    ASSERT_OBJCEQ_MSG(@"GET", [urlRequest HTTPMethod], "FAILED: HTTPMethod is not GET.");
    ASSERT_EQ_MSG(YES, [urlRequest HTTPShouldHandleCookies], "FAILED: HTTPShouldHandleCookies is not YES.");

    // verify add
    NSString* contentData = @"ContentData";
    NSString* content = @"Content-Data";
    [urlRequest addValue:contentData forHTTPHeaderField:content];
    NSDictionary* httpFields = [urlRequest allHTTPHeaderFields];
    ASSERT_OBJCEQ_MSG(contentData, [httpFields objectForKey:content], "FAILED: objectForKey is not valid.");
    [contentData release];
    [content release];
}