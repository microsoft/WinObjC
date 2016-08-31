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

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSURLResponse, SuggestedFilename_MatchingMIME) {
    NSURL* url = [NSURL URLWithString:@"a/test/name.extension.txt"];
    NSURLResponse* res =
        [[[NSURLResponse alloc] initWithURL:url MIMEType:@"text/plain" expectedContentLength:0 textEncodingName:nil] autorelease];
    ASSERT_OBJCEQ(@"name.extension.txt", res.suggestedFilename);
}

TEST(NSURLResponse, SuggestedFilename_QueryParameter_MatchingMIME) {
    NSURL* url = [NSURL URLWithString:@"a/test/name.extension.txt?foo=bar"];
    NSURLResponse* res =
        [[[NSURLResponse alloc] initWithURL:url MIMEType:@"text/plain" expectedContentLength:0 textEncodingName:nil] autorelease];
    ASSERT_OBJCEQ(@"name.extension.txt", res.suggestedFilename);
}

// These are the same tests as NSURLResponse, but with the isEqual: check removed
// so that we can test the archival behaviour on OS X.
// On OS X, NSURLResponse isEqual: only does a pointer comparison.
TEST(NSURLResponse, CanBeArchivedWithoutFullFidelity) {
    NSURLResponse* expected = [[[NSURLResponse alloc] initWithURL:[NSURL URLWithString:@"test"]
                                                         MIMEType:@"text/plain"
                                            expectedContentLength:100
                                                 textEncodingName:@"utf8"] autorelease];

    id data = nil;
    EXPECT_NO_THROW(data = [NSKeyedArchiver archivedDataWithRootObject:expected]);
    EXPECT_NO_THROW([NSKeyedUnarchiver unarchiveObjectWithData:data]);
}

TEST(NSHTTPURLResponse, CanBeArchivedWithoutFullFidelity) {
    NSURL* url = [NSURL URLWithString:@"https://www.swift.org"];
    auto f = @{ @"Content-Type" : @"text/HTML; charset=ISO-8859-4" };
    NSHTTPURLResponse* expected =
        [[[NSHTTPURLResponse alloc] initWithURL:url statusCode:200 HTTPVersion:@"HTTP/1.1" headerFields:f] autorelease];

    id data = nil;
    EXPECT_NO_THROW(data = [NSKeyedArchiver archivedDataWithRootObject:expected]);
    EXPECT_NO_THROW([NSKeyedUnarchiver unarchiveObjectWithData:data]);
}
