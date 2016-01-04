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
#import <Foundation/NSURLRequest.h>
#import <Foundation/NSURL.h>

TEST(Foundation, NSURLRequest_requestWithURL) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];

    ASSERT_TRUE_MSG(url != NULL, "FAILED: url should be non-null!");
    NSURLRequest* urlRequest = [NSURLRequest requestWithURL:url];
    ASSERT_TRUE_MSG(urlRequest != NULL, "FAILED: urlRequest should be non-null!");
    ASSERT_OBJCEQ_MSG(url, [urlRequest URL], "FAILED: url is not valid.");
    ASSERT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  [urlRequest cachePolicy],
                  "FAILED:cachePolicy is not NSURLRequestUseProtocolCachePolicy.");
    ASSERT_EQ_MSG(60.0, [urlRequest timeoutInterval], "FAILED: timeoutInterval is not 60.0.");
    ASSERT_TRUE_MSG([urlRequest allHTTPHeaderFields] != NULL, "FAILED: allHTTPHeaderFields is null.");
    ASSERT_OBJCEQ_MSG(@"GET", [urlRequest HTTPMethod], "FAILED: HTTPMethod is not GET.");
    ASSERT_EQ_MSG(YES, [urlRequest HTTPShouldHandleCookies], "FAILED: HTTPShouldHandleCookies is not YES.");
}

TEST(Foundation, NSURLRequest_requestWithURLFull) {
    NSURL* url = [NSURL URLWithString:@"file:///foo/var/"];

    ASSERT_TRUE_MSG(url != NULL, "FAILED: url should be non-null!");
    NSURLRequest* urlRequest = [NSURLRequest requestWithURL:url cachePolicy:NSURLRequestReturnCacheDataElseLoad timeoutInterval:20.0];
    ASSERT_TRUE_MSG(urlRequest != NULL, "FAILED: urlRequest should be non-null!");
    ASSERT_OBJCEQ_MSG(url, [urlRequest URL], "FAILED: url is not valid.");
    ASSERT_EQ_MSG(NSURLRequestReturnCacheDataElseLoad,
                  [urlRequest cachePolicy],
                  "FAILED:cachePolicy is not NSURLRequestReturnCacheDataElseLoad.");
    ASSERT_EQ_MSG(20.0, [urlRequest timeoutInterval], "FAILED: timeoutInterval is not 20.0.");
    ASSERT_TRUE_MSG([urlRequest allHTTPHeaderFields] != NULL, "FAILED: allHTTPHeaderFields is null.");
    ASSERT_OBJCEQ_MSG(@"GET", [urlRequest HTTPMethod], "FAILED: HTTPMethod is not GET.");
    ASSERT_EQ_MSG(YES, [urlRequest HTTPShouldHandleCookies], "FAILED: HTTPShouldHandleCookies is not YES.");
}

TEST(Foundation, NSURLRequest_defaultInit) {
    NSURLRequest* urlRequest = [[NSURLRequest alloc] init];
    ASSERT_TRUE_MSG(urlRequest != NULL, "FAILED: urlRequest should be non-null!");
    ASSERT_OBJCEQ_MSG(NULL, [urlRequest URL], "FAILED: url is not null.");
    ASSERT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  [urlRequest cachePolicy],
                  "FAILED:cachePolicy is not NSURLRequestUseProtocolCachePolicy.");
    ASSERT_EQ_MSG(60.0, [urlRequest timeoutInterval], "FAILED: timeoutInterval is not 60.0.");
    ASSERT_TRUE_MSG([urlRequest allHTTPHeaderFields] != NULL, "FAILED: allHTTPHeaderFields is null.");
    ASSERT_OBJCEQ_MSG(@"GET", [urlRequest HTTPMethod], "FAILED: HTTPMethod is not GET.");
    ASSERT_EQ_MSG(YES, [urlRequest HTTPShouldHandleCookies], "FAILED: HTTPShouldHandleCookies is not YES.");
}