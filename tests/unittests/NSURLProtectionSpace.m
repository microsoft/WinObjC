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
#import <Foundation/NSURLProtectionSpace.h>

TEST(Foundation, NSURLProtectionSpace_initWithHost) {
    NSString* host = @"microsoft";
    NSURLProtectionSpace* protectionSpace =
        [[NSURLProtectionSpace alloc] initWithHost:host port:8080 protocol:NSURLProtectionSpaceHTTP realm:nil authenticationMethod:nil];
    ASSERT_TRUE_MSG(protectionSpace != NULL, "FAILED: protectionSpace should be non-null!");
    ASSERT_EQ_MSG(NSURLAuthenticationMethodDefault,
                  [protectionSpace authenticationMethod],
                  "FAILED: auth method is not NSURLAuthenticationMethodDefault.");
    ASSERT_EQ_MSG(host, [protectionSpace host], "FAILED: host is not valid.");
    ASSERT_EQ_MSG(8080, [protectionSpace port], "FAILED: port is not valid.");
    ASSERT_EQ_MSG(NSURLProtectionSpaceHTTP, [protectionSpace protocol], "FAILED: protocol is not valid.");
    ASSERT_EQ_MSG(nil, [protectionSpace realm], "FAILED: realm is non null.");
    ASSERT_EQ_MSG(NO, [protectionSpace isProxy], "FAILED: isProxy should be NO.");
    [host release];
    [protectionSpace release];
}

TEST(Foundation, NSURLProtectionSpace_initWithProxyHost) {
    NSString* host = @"microsoft";
    NSURLProtectionSpace* protectionSpace = [[NSURLProtectionSpace alloc] initWithProxyHost:host
                                                                                       port:8080
                                                                                       type:NSURLProtectionSpaceHTTPProxy
                                                                                      realm:nil
                                                                       authenticationMethod:NSURLAuthenticationMethodHTMLForm];
    ASSERT_TRUE_MSG(protectionSpace != NULL, "FAILED: protectionSpace should be non-null!");
    ASSERT_EQ_MSG(NSURLAuthenticationMethodHTMLForm,
                  [protectionSpace authenticationMethod],
                  "FAILED: auth method is not NSURLAuthenticationMethodHTMLForm.");
    ASSERT_EQ_MSG(host, [protectionSpace host], "FAILED: host is not valid.");
    ASSERT_EQ_MSG(8080, [protectionSpace port], "FAILED: port is not valid.");
    ASSERT_EQ_MSG(NSURLProtectionSpaceHTTPProxy, [protectionSpace proxyType], "FAILED: proxyType is not valid.");
    ASSERT_EQ_MSG(nil, [protectionSpace realm], "FAILED: realm is non null.");
    ASSERT_EQ_MSG(YES, [protectionSpace isProxy], "FAILED: isProxy should be YES.");
    [host release];
    [protectionSpace release];
}