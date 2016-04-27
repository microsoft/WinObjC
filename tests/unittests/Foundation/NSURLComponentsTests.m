//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

TEST(NSFoundation, NSURLComponentsTests) {
    // Simple URL
    NSString* urlString = @"http://www.test.com/";
    NSURLComponents* components = [NSURLComponents componentsWithString:urlString];

    EXPECT_OBJCEQ(@"http", components.scheme);
    EXPECT_OBJCEQ(@"www.test.com", components.host);
    EXPECT_OBJCEQ(@"/", components.path);
    EXPECT_EQ(0, components.queryItems.count);

    EXPECT_OBJCEQ(urlString, components.URL.absoluteString);

    // URL with a query string
    urlString = @"https://www.test.com/path?name1=value1&name2=value2";
    components = [NSURLComponents componentsWithString:urlString];

    EXPECT_OBJCEQ(@"https", components.scheme);
    EXPECT_OBJCEQ(@"www.test.com", components.host);
    EXPECT_OBJCEQ(@"/path", components.path);
    ASSERT_EQ(2, components.queryItems.count);
    EXPECT_OBJCEQ(@"name1", ((NSURLQueryItem*)components.queryItems[0]).name);
    EXPECT_OBJCEQ(@"value1", ((NSURLQueryItem*)components.queryItems[0]).value);
    EXPECT_OBJCEQ(@"name2", ((NSURLQueryItem*)components.queryItems[1]).name);
    EXPECT_OBJCEQ(@"value2", ((NSURLQueryItem*)components.queryItems[1]).value);

    EXPECT_OBJCEQ(urlString, components.URL.absoluteString);

    // URL with a query string and percent encodings
    urlString = @"http://www.test.com/pa%20th?name%26=value%3D";
    components = [NSURLComponents componentsWithString:urlString];

    EXPECT_OBJCEQ(@"http", components.scheme);
    EXPECT_OBJCEQ(@"www.test.com", components.host);
    EXPECT_OBJCEQ(@"/pa th", components.path);
    ASSERT_EQ(1, components.queryItems.count);
    EXPECT_OBJCEQ(@"name&", ((NSURLQueryItem*)components.queryItems[0]).name);
    EXPECT_OBJCEQ(@"value=", ((NSURLQueryItem*)components.queryItems[0]).value);

    EXPECT_OBJCEQ(urlString, components.URL.absoluteString);

    // URL with a weird-looking query string
    urlString = @"http://www.test.com/path?name=&=value&&name&name=value=value";
    components = [NSURLComponents componentsWithString:urlString];

    EXPECT_OBJCEQ(@"http", components.scheme);
    EXPECT_OBJCEQ(@"www.test.com", components.host);
    EXPECT_OBJCEQ(@"/path", components.path);
    ASSERT_EQ(5, components.queryItems.count);
    EXPECT_OBJCEQ(@"name", ((NSURLQueryItem*)components.queryItems[0]).name);
    EXPECT_OBJCEQ(@"", ((NSURLQueryItem*)components.queryItems[0]).value);

    EXPECT_OBJCEQ(@"", ((NSURLQueryItem*)components.queryItems[1]).name);
    EXPECT_OBJCEQ(@"value", ((NSURLQueryItem*)components.queryItems[1]).value);

    EXPECT_OBJCEQ(@"", ((NSURLQueryItem*)components.queryItems[2]).name);
    EXPECT_EQ(nil, ((NSURLQueryItem*)components.queryItems[2]).value);

    EXPECT_OBJCEQ(@"name", ((NSURLQueryItem*)components.queryItems[3]).name);
    EXPECT_EQ(nil, ((NSURLQueryItem*)components.queryItems[3]).value);

    EXPECT_OBJCEQ(@"name", ((NSURLQueryItem*)components.queryItems[4]).name);
    EXPECT_OBJCEQ(@"value=value", ((NSURLQueryItem*)components.queryItems[4]).value);
}
