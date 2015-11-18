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
#import <Foundation/NSURLSessionConfiguration.h>

TEST(Foundation, NSURLSessionConfiguration_initValues) {
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    ASSERT_TRUE_MSG(sessionConfiguration != NULL, "FAILED: sessionConfiguration should be non-null!");

    ASSERT_EQ_MSG(YES, sessionConfiguration.allowsCellularAccess, "FAILED: allowsCellularAccess should be YES");
    ASSERT_EQ_MSG(60, sessionConfiguration.timeoutIntervalForRequest, "FAILED: timeoutIntervalForRequest should be %d", 60);
    ASSERT_EQ_MSG(7, sessionConfiguration.timeoutIntervalForResource, "FAILED: timeoutIntervalForResource should be %d", 7);
    ASSERT_EQ_MSG(NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain,
                  sessionConfiguration.HTTPCookieAcceptPolicy,
                  "FAILED: HTTPCookieAcceptPolicy should be %d",
                  NSHTTPCookieAcceptPolicyOnlyFromMainDocumentDomain);
    ASSERT_EQ_MSG(YES, sessionConfiguration.HTTPShouldSetCookies, "FAILED: HTTPShouldSetCookies should be YES");
    ASSERT_EQ_MSG(NSURLNetworkServiceTypeDefault,
                  sessionConfiguration.networkServiceType,
                  "FAILED: networkServiceType should be %d",
                  NSURLNetworkServiceTypeDefault);
    ASSERT_EQ_MSG(NSURLRequestUseProtocolCachePolicy,
                  sessionConfiguration.requestCachePolicy,
                  "FAILED: requestCachePolicy should be %d",
                  NSURLRequestUseProtocolCachePolicy);
    ASSERT_EQ_MSG(6, sessionConfiguration.HTTPMaximumConnectionsPerHost, "FAILED: HTTPMaximumConnectionsPerHost should be %d", 6);
    ASSERT_TRUE_MSG(sessionConfiguration.HTTPCookieStorage != NULL, "FAILED: HTTPCookieStorage should be non-null");
}

TEST(Foundation, NSURLSessionConfiguration_defaultSessionConfiguration) {
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration defaultSessionConfiguration];
    ASSERT_TRUE_MSG(sessionConfiguration != NULL, "FAILED: sessionConfiguration should be non-null!");

    ASSERT_EQ_MSG(YES, sessionConfiguration.allowsCellularAccess, "FAILED: allowsCellularAccess should be YES");
    ASSERT_EQ_MSG(kTLSProtocol12,
                  sessionConfiguration.TLSMaximumSupportedProtocol,
                  "FAILED: TLSMaximumSupportedProtocol should be %d",
                  kTLSProtocol12);
    ASSERT_EQ_MSG(kSSLProtocol3,
                  sessionConfiguration.TLSMinimumSupportedProtocol,
                  "FAILED: TLSMinimumSupportedProtocol should be %d",
                  kSSLProtocol3);
}

TEST(Foundation, NSURLSessionConfiguration_ephemeralSessionConfiguration) {
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration ephemeralSessionConfiguration];
    ASSERT_TRUE_MSG(sessionConfiguration != NULL, "FAILED: sessionConfiguration should be non-null!");

    ASSERT_EQ_MSG(kTLSProtocol12,
                  sessionConfiguration.TLSMaximumSupportedProtocol,
                  "FAILED: TLSMaximumSupportedProtocol should be %d",
                  kTLSProtocol12);
    ASSERT_EQ_MSG(kTLSProtocol1,
                  sessionConfiguration.TLSMinimumSupportedProtocol,
                  "FAILED: TLSMinimumSupportedProtocol should be %d",
                  kTLSProtocol1);
    ASSERT_TRUE_MSG(sessionConfiguration.URLCache != NULL, "FAILED: URLCache should be non-null");
}

TEST(Foundation, NSURLSessionConfiguration_backgroundSessionConfigurationWithIdentifier) {
    NSString* identifier = @"Microsoft";
    NSURLSessionConfiguration* sessionConfiguration = [NSURLSessionConfiguration backgroundSessionConfigurationWithIdentifier:identifier];
    ASSERT_TRUE_MSG(sessionConfiguration != NULL, "FAILED: sessionConfiguration should be non-null!");

    ASSERT_EQ_MSG(kTLSProtocol12,
                  sessionConfiguration.TLSMaximumSupportedProtocol,
                  "FAILED: TLSMaximumSupportedProtocol should be %d",
                  kTLSProtocol12);
    ASSERT_EQ_MSG(kTLSProtocol1,
                  sessionConfiguration.TLSMinimumSupportedProtocol,
                  "FAILED: TLSMinimumSupportedProtocol should be %d",
                  kTLSProtocol1);
    ASSERT_OBJCEQ_MSG(identifier, sessionConfiguration.identifier, "FAILED: identifier should be %d", identifier);
    ASSERT_TRUE_MSG(sessionConfiguration.URLCache != NULL, "FAILED: URLCache should be non-null");
}
