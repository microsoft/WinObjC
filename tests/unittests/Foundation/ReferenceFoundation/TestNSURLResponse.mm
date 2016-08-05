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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2016 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSURLResponse, URL) {
    NSURL* url = [NSURL URLWithString:@"a/test/path"];
    NSURLResponse* res = [[[NSURLResponse alloc] initWithURL:url MIMEType:@"txt" expectedContentLength:0 textEncodingName:nil] autorelease];
    ASSERT_OBJCEQ_MSG(url, res.URL, @"should be the expected url");
}

TEST(NSURLResponse, MIMEType_1) {
    auto mimetype = @"text/plain";
    NSURLResponse* res =
        [[[NSURLResponse alloc] initWithURL:[NSURL URLWithString:@"test"] MIMEType:mimetype expectedContentLength:0 textEncodingName:nil]
            autorelease];
    ASSERT_OBJCEQ_MSG(mimetype, res.MIMEType, @"should be the passed in mimetype");
}

TEST(NSURLResponse, MIMEType_2) {
    auto mimetype = @"APPlication/wordperFECT";
    NSURLResponse* res =
        [[[NSURLResponse alloc] initWithURL:[NSURL URLWithString:@"test"] MIMEType:mimetype expectedContentLength:0 textEncodingName:nil]
            autorelease];
    ASSERT_OBJCEQ_MSG(mimetype, res.MIMEType, @"should be the other mimetype");
}

TEST(NSURLResponse, ExpectedContentLength) {
    auto zeroContentLength = 0;
    auto positiveContentLength = 100;
    NSURL* url = [NSURL URLWithString:@"test"];
    NSURLResponse* res1 =
        [[[NSURLResponse alloc] initWithURL:url MIMEType:@"text/plain" expectedContentLength:zeroContentLength textEncodingName:nil]
            autorelease];
    ASSERT_EQ_MSG(int64_t(zeroContentLength), res1.expectedContentLength, @"should be int64_t of the zero length");
    NSURLResponse* res2 =
        [[[NSURLResponse alloc] initWithURL:url MIMEType:@"text/plain" expectedContentLength:positiveContentLength textEncodingName:nil]
            autorelease];
    ASSERT_EQ_MSG(int64_t(positiveContentLength), res2.expectedContentLength, @"should be int64_t of the positive content length");
}

TEST(NSURLResponse, TextEncodingName) {
    auto encoding = @"utf8";
    NSURL* url = [NSURL URLWithString:@"test"];
    NSURLResponse* res1 =
        [[[NSURLResponse alloc] initWithURL:url MIMEType:nil expectedContentLength:0 textEncodingName:encoding] autorelease];
    ASSERT_OBJCEQ_MSG(encoding, res1.textEncodingName, @"should be the utf8 encoding");
    NSURLResponse* res2 = [[[NSURLResponse alloc] initWithURL:url MIMEType:nil expectedContentLength:0 textEncodingName:nil] autorelease];
    ASSERT_OBJCEQ(nil, res2.textEncodingName);
}

TEST(NSURLResponse, SuggestedFilename) {
    NSURL* url = [NSURL URLWithString:@"a/test/name.extension"];
    NSURLResponse* res = [[[NSURLResponse alloc] initWithURL:url MIMEType:@"txt" expectedContentLength:0 textEncodingName:nil] autorelease];
    ASSERT_OBJCEQ(@"name.extension", res.suggestedFilename);
}

TEST(NSURLResponse, SuggestedFilename_2) {
    NSURL* url = [NSURL URLWithString:@"a/test/name.extension?foo=bar"];
    NSURLResponse* res = [[[NSURLResponse alloc] initWithURL:url MIMEType:@"txt" expectedContentLength:0 textEncodingName:nil] autorelease];
    ASSERT_OBJCEQ(@"name.extension", res.suggestedFilename);
}

TEST(NSURLResponse, SuggestedFilename_3) {
    NSURL* url = [NSURL URLWithString:@"a://bar"];
    NSURLResponse* res = [[[NSURLResponse alloc] initWithURL:url MIMEType:@"txt" expectedContentLength:0 textEncodingName:nil] autorelease];
    ASSERT_OBJCEQ(@"Unknown", res.suggestedFilename);
}

TEST(NSHTTPURLResponse, URL_and_status_1) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:@{
            @"Content-Length" : @"5299"
        }] autorelease];
    ASSERT_OBJCEQ(url, response.URL);
    ASSERT_EQ(200, response.statusCode);
}

TEST(NSHTTPURLResponse, URL_and_status_2) {
    NSURL* url = [NSURL URLWithString:@"http://www.apple.com"];
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:302 HTTPVersion:@"HTTP/1.1" headerFields:@{
            @"Content-Length" : @"5299"
        }] autorelease];
    ASSERT_OBJCEQ(url, response.URL);
    ASSERT_EQ(302, response.statusCode);
}

TEST(NSHTTPURLResponse, HeaderFields_1) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:nil] autorelease];
    ASSERT_EQ(0, response.allHeaderFields.count);
}
TEST(NSHTTPURLResponse, HeaderFields_2) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:@{}] autorelease];
    ASSERT_EQ(0, response.allHeaderFields.count);
}

TEST(NSHTTPURLResponse, HeaderFields_3) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"A" : @"1", @"B" : @"2" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(2, response.allHeaderFields.count);
    ASSERT_OBJCEQ(@"1", response.allHeaderFields[@"A"]);
    ASSERT_OBJCEQ(@"2", response.allHeaderFields[@"B"]);
}

// Note that the message content length is different from the message
// transfer length.
// The transfer length can only be derived when the Transfer-Encoding is identity (default).
// For compressed content (Content-Encoding other than identity), there is not way to derive the
// content length from the transfer length.
//
// C.f. <https://tools.ietf.org/html/rfc2616#section-4.4>

TEST(NSHTTPURLResponse, ContentLength_available_1) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_available_2) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997", @"Transfer-Encoding" : @"identity" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_available_3) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997", @"Content-Encoding" : @"identity" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_available_4) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997", @"Content-Encoding" : @"identity", @"Transfer-Encoding" : @"identity" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_notAvailable) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Server" : @"Apache" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(-1, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_withTransferEncoding) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997", @"Transfer-Encoding" : @"chunked" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_withContentEncoding) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997", @"Content-Encoding" : @"deflate" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_withContentEncodingAndTransferEncoding) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997", @"Content-Encoding" : @"deflate", @"Transfer-Encoding" : @"identity" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

TEST(NSHTTPURLResponse, ContentLength_withContentEncodingAndTransferEncoding_2) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Length" : @"997", @"Content-Encoding" : @"identity", @"Transfer-Encoding" : @"chunked" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_EQ(997, response.expectedContentLength);
}

// The `suggestedFilename` can be derived from the @"Content-Disposition"
// header as defined in RFC 1806 and more recently RFC 2183
// https://tools.ietf.org/html/rfc1806
// https://tools.ietf.org/html/rfc2183
//
// Typical use looks like this:
//     Content-Disposition: attachment; filename=@"fname.ext"
//
// As noted in https://tools.ietf.org/html/rfc2616#section-19.5.1 the
// receiving user agent SHOULD NOT respect any directory path information
// present in the filename-parm parameter.
//

TEST(NSHTTPURLResponse, SuggestedFilename_notAvailable_1) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = [NSDictionary<NSString*, NSString*> dictionary];
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"Unknown", response.suggestedFilename);
}

TEST(NSHTTPURLResponse, SuggestedFilename_notAvailable_2) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Disposition" : @"inline" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"Unknown", response.suggestedFilename);
}

TEST(NSHTTPURLResponse, SuggestedFilename_1) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Disposition" : @"attachment; filename=\"fname.ext\"" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"fname.ext", response.suggestedFilename);
}

TEST(NSHTTPURLResponse, SuggestedFilename_2) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Disposition" : @"attachment; filename=genome.jpeg; modification-date=\"Wed, 12 Feb 1997 16:29:51 -0500\";" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"genome.jpeg", response.suggestedFilename);
}

TEST(NSHTTPURLResponse, SuggestedFilename_3) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Disposition" : @"attachment; filename=\";.ext\"" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"_.ext", response.suggestedFilename); // Differs from reference platform because ; is an illegal filename character
}

TEST(NSHTTPURLResponse, SuggestedFilename_4) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Disposition" : @"attachment; aa=bb\\; filename=\"wrong.ext\"; filename=\"fname.ext\"; cc=dd" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"fname.ext", response.suggestedFilename);
}

TEST(NSHTTPURLResponse, SuggestedFilename_removeSlashes_1) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Disposition" : @"attachment; filename=\"/a/b/name\"" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"_a_b_name", response.suggestedFilename);
}

TEST(NSHTTPURLResponse, SuggestedFilename_removeSlashes_2) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Disposition" : @"attachment; filename=\"a/../b/name\"" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"a_.._b_name", response.suggestedFilename);
}

// The MIME type / character encoding

TEST(NSHTTPURLResponse, mimetypeAndCharacterEncoding_1) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Server" : @"Apache" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(nil, response.MIMEType);
    ASSERT_OBJCEQ(nil, response.textEncodingName);
}

TEST(NSHTTPURLResponse, mimetypeAndCharacterEncoding_2) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Type" : @"text/html" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"text/html", response.MIMEType);
    ASSERT_OBJCEQ(nil, response.textEncodingName);
}

TEST(NSHTTPURLResponse, mimetypeAndCharacterEncoding_3) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Type" : @"text/HTML; charset=ISO-8859-4" };
    NSHTTPURLResponse* response =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];
    ASSERT_OBJCEQ(@"text/html", response.MIMEType);
    ASSERT_OBJCEQ(@"iso-8859-4", response.textEncodingName);
}

// Archival
TEST(NSURLResponse, canBeArchived) {
    NSURLResponse* expected = [[[NSURLResponse alloc] initWithURL:[NSURL URLWithString:@"test"]
                                                MIMEType:@"txt"
                                                expectedContentLength:100
                                                textEncodingName:@"utf8"] autorelease];

    id data = [NSKeyedArchiver archivedDataWithRootObject:expected];
    id actual = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_OBJCEQ(expected, actual);
}

TEST(NSHTTPURLResponse, canBeArchived) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Type" : @"text/HTML; charset=ISO-8859-4" };
    NSHTTPURLResponse* expected =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];

    id data = [NSKeyedArchiver archivedDataWithRootObject:expected];
    id actual = [NSKeyedUnarchiver unarchiveObjectWithData:data];
    ASSERT_OBJCEQ(expected, actual);
}
