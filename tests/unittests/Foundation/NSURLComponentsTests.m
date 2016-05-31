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

TEST(NSURLComponents, Getters) {
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
    EXPECT_OBJCEQ(@"name1", components.queryItems[0].name);
    EXPECT_OBJCEQ(@"value1", components.queryItems[0].value);
    EXPECT_OBJCEQ(@"name2", components.queryItems[1].name);
    EXPECT_OBJCEQ(@"value2", components.queryItems[1].value);

    EXPECT_OBJCEQ(urlString, components.URL.absoluteString);

    // URL with a query string and percent encodings
    urlString = @"http://www.test.com/pa%20th?name%26=value%3D";
    components = [NSURLComponents componentsWithString:urlString];

    EXPECT_OBJCEQ(@"http", components.scheme);
    EXPECT_OBJCEQ(@"www.test.com", components.host);
    EXPECT_OBJCEQ(@"/pa th", components.path);
    ASSERT_EQ(1, components.queryItems.count);
    EXPECT_OBJCEQ(@"name&", components.queryItems[0].name);
    EXPECT_OBJCEQ(@"value=", components.queryItems[0].value);

    EXPECT_OBJCEQ(urlString, components.URL.absoluteString);

    // URL with a weird-looking query string
    urlString = @"http://www.test.com/path?name=&=value&&name&name=value=value";
    components = [NSURLComponents componentsWithString:urlString];

    EXPECT_OBJCEQ(@"http", components.scheme);
    EXPECT_OBJCEQ(@"www.test.com", components.host);
    EXPECT_OBJCEQ(@"/path", components.path);
    ASSERT_EQ(5, components.queryItems.count);
    EXPECT_OBJCEQ(@"name", components.queryItems[0].name);
    EXPECT_OBJCEQ(@"", components.queryItems[0].value);

    EXPECT_OBJCEQ(@"", components.queryItems[1].name);
    EXPECT_OBJCEQ(@"value", components.queryItems[1].value);

    EXPECT_OBJCEQ(@"", components.queryItems[2].name);
    EXPECT_EQ(nil, components.queryItems[2].value);

    EXPECT_OBJCEQ(@"name", components.queryItems[3].name);
    EXPECT_EQ(nil, components.queryItems[3].value);

    EXPECT_OBJCEQ(@"name", components.queryItems[4].name);
    EXPECT_OBJCEQ(@"value=value", components.queryItems[4].value);
}

TEST(NSURLComponents, Setters) {
    NSURLComponents* components = [[[NSURLComponents alloc] init] autorelease];

    components.fragment = @"fragment";
    components.host = @"host";
    components.password = @"password";
    components.path = @"/path";
    components.query = @"name1=value1&name2=value2";
    components.scheme = @"scheme";
    components.user = @"user";

    EXPECT_OBJCEQ(@"scheme://user:password@host/path?name1=value1&name2=value2#fragment", components.string);
}

TEST(NSURLComponents, PercentEncoding) {
    NSURLComponents* components = [[[NSURLComponents alloc] init] autorelease];

    components.percentEncodedFragment = @"%41";
    EXPECT_OBJCEQ(@"A", components.fragment);
    EXPECT_OBJCEQ(@"%41", components.percentEncodedFragment);

    components.percentEncodedHost = @"%41";
    EXPECT_OBJCEQ(@"A", components.host);
    EXPECT_OBJCEQ(@"%41", components.percentEncodedHost);

    components.percentEncodedUser = @"%41";
    EXPECT_OBJCEQ(@"A", components.user);
    EXPECT_OBJCEQ(@"%41", components.percentEncodedUser);

    components.percentEncodedPassword = @"%41";
    EXPECT_OBJCEQ(@"A", components.password);
    EXPECT_OBJCEQ(@"%41", components.percentEncodedPassword);

    components.percentEncodedPath = @"/%41";
    EXPECT_OBJCEQ(@"/A", components.path);
    EXPECT_OBJCEQ(@"/%41", components.percentEncodedPath);

    components.percentEncodedQuery = @"%41";
    EXPECT_OBJCEQ(@"A", components.query);
    EXPECT_OBJCEQ(@"%41", components.percentEncodedQuery);

    NSURLQueryItem* queryItem = [NSURLQueryItem queryItemWithName:@"{name}" value:@"{value}"];
    components.queryItems = @[queryItem];
    EXPECT_OBJCEQ(@"{name}={value}", components.query);
    EXPECT_OBJCEQ(@"%7Bname%7D=%7Bvalue%7D", components.percentEncodedQuery);
}