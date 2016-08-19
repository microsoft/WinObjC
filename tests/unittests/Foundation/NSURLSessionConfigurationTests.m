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

#include <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSURLSessionConfiguration, initValues) {
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    ASSERT_NE_MSG(nil, sessionConfiguration, "FAILED: sessionConfiguration should be non-null!");

    EXPECT_EQ_MSG(YES, sessionConfiguration.allowsCellularAccess, "FAILED: allowsCellularAccess should be YES");
    EXPECT_EQ_MSG(60, sessionConfiguration.timeoutIntervalForRequest, "FAILED: timeoutIntervalForRequest should be %d", 60);
    EXPECT_EQ_MSG(7 * 24 * 60 * 60,
                  sessionConfiguration.timeoutIntervalForResource,
                  "FAILED: timeoutIntervalForResource should be %d",
                  7 * 24 * 60 * 60);
    EXPECT_EQ_MSG(NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain,
                  sessionConfiguration.HTTPCookieAcceptPolicy,
                  "FAILED: HTTPCookieAcceptPolicy should be %d",
                  NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain);
    EXPECT_EQ_MSG(YES, sessionConfiguration.HTTPShouldSetCookies, "FAILED: HTTPShouldSetCookies should be YES");
    EXPECT_EQ_MSG(NSURLNetworkServiceTypeDefault,
                  sessionConfiguration.networkServiceType,
                  "FAILED: networkServiceType should be %d",
                  NSURLNetworkServiceTypeDefault);
    EXPECT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  sessionConfiguration.requestCachePolicy,
                  "FAILED: requestCachePolicy should be %d",
                  NSURLRequestUseProtocolCachePolicy);
    EXPECT_EQ_MSG(6, sessionConfiguration.HTTPMaximumConnectionsPerHost, "FAILED: HTTPMaximumConnectionsPerHost should be %d", 6);
    EXPECT_NE_MSG(nil, sessionConfiguration.HTTPCookieStorage, "FAILED: HTTPCookieStorage should be non-null");
}

TEST(NSURLSessionConfiguration, defaultSessionConfiguration) {
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    ASSERT_NE_MSG(nil, sessionConfiguration, "FAILED: sessionConfiguration should be non-null!");

    EXPECT_EQ_MSG(YES, sessionConfiguration.allowsCellularAccess, "FAILED: allowsCellularAccess should be YES");
    EXPECT_EQ_MSG(kTLSProtocol12,
                  sessionConfiguration.TLSMaximumSupportedProtocol,
                  "FAILED: TLSMaximumSupportedProtocol should be %d",
                  kTLSProtocol12);
    EXPECT_EQ_MSG(kTLSProtocol1,
                  sessionConfiguration.TLSMinimumSupportedProtocol,
                  "FAILED: TLSMinimumSupportedProtocol should be %d",
                  kTLSProtocol1);
}

TEST(NSURLSessionConfiguration, ephemeralSessionConfiguration) {
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration ephemeralSessionConfiguration];
    ASSERT_NE_MSG(nil, sessionConfiguration, "FAILED: sessionConfiguration should be non-null!");

    EXPECT_EQ_MSG(kTLSProtocol12,
                  sessionConfiguration.TLSMaximumSupportedProtocol,
                  "FAILED: TLSMaximumSupportedProtocol should be %d",
                  kTLSProtocol12);
    EXPECT_EQ_MSG(kTLSProtocol1,
                  sessionConfiguration.TLSMinimumSupportedProtocol,
                  "FAILED: TLSMinimumSupportedProtocol should be %d",
                  kTLSProtocol1);
    EXPECT_NE_MSG(nil, sessionConfiguration.URLCache, "FAILED: URLCache should be non-null");
}

TEST(NSURLSessionConfiguration, backgroundSessionConfigurationWithIdentifier) {
    NSString* identifier = @"Microsoft";
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:identifier];
    ASSERT_NE_MSG(nil, sessionConfiguration, "FAILED: sessionConfiguration should be non-null!");

    EXPECT_EQ_MSG(kTLSProtocol12,
                  sessionConfiguration.TLSMaximumSupportedProtocol,
                  "FAILED: TLSMaximumSupportedProtocol should be %d",
                  kTLSProtocol12);
    EXPECT_EQ_MSG(kTLSProtocol1,
                  sessionConfiguration.TLSMinimumSupportedProtocol,
                  "FAILED: TLSMinimumSupportedProtocol should be %d",
                  kTLSProtocol1);
    EXPECT_OBJCEQ_MSG(identifier, sessionConfiguration.identifier, "FAILED: identifier should be %d", identifier);
    EXPECT_EQ_MSG(nil, sessionConfiguration.URLCache, "FAILED: URLCache should be nil for background sessions");
}
