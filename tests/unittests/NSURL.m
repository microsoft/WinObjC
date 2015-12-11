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

void testNSURLMethod(SEL selector, NSURL* input, id argument, NSURL* expected) {
    NSURL* actual = [input performSelector:selector withObject:argument];
    ASSERT_OBJCEQ_MSG(expected, actual, "FAILED: expected != actual");
}

TEST(NSFoundation, NSURLTests) {
    NSURL* testURL = [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html?Foo#24"];
    NSURL* testURL2 = [[NSURL alloc] initWithString:@"http://www.test.com/"];
    NSURL* testURL3 = [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html?Foo#24"];
    NSURL* testURL4 = [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index.html?Foo#24"];
    NSURL* testURL5 = [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"];
    NSURL* testURL6 = [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"];
    NSURL* testURL7 = [[NSURL alloc] initWithString:@"http://www.test.com/.foo"];

    // URLByDeletingPathExtension tests
    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL4,
                    nil,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL5, nil, [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension),
                    testURL6,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"]);

    testNSURLMethod(@selector(URLByDeletingPathExtension), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    // URLByDeletingLastPathComponent
    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/../"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/.?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL4,
                    nil,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/.?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL5,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com../?Foo#24"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent),
                    testURL6,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page"]);

    testNSURLMethod(@selector(URLByDeletingLastPathComponent), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    // URLByStandardizingPath
    testNSURLMethod(@selector(URLByStandardizingPath),
                    testURL,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL2, nil, [[NSURL alloc] initWithString:@"http://www.test.com/"]);

    testNSURLMethod(@selector(URLByStandardizingPath),
                    testURL3,
                    nil,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath),
                    testURL4,
                    nil,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/index.html?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL5, nil, [[NSURL alloc] initWithString:@"http://www.test.com?Foo#24"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL6, nil, [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf"]);

    testNSURLMethod(@selector(URLByStandardizingPath), testURL7, nil, [[NSURL alloc] initWithString:@"http://www.test.com/.foo"]);

    // URLByAppendingPathExtension
    NSString* extension = @"txt";
    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL2,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/.txt"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL3,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home/asdf/./index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL4,
                    extension,
                    [[NSURL alloc] initWithString:@"file://www.test.com/home/../home/./index.html.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL5,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com.txt?Foo#24"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL6,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/home.page/asdf.txt"]);

    testNSURLMethod(@selector(URLByAppendingPathExtension:),
                    testURL7,
                    extension,
                    [[NSURL alloc] initWithString:@"http://www.test.com/.foo.txt"]);

    [testURL release];
    [testURL2 release];
    [testURL3 release];
    [testURL4 release];
    [testURL5 release];
    [testURL6 release];
    [testURL7 release];
}

TEST(NSFoundation, NSURL_URLByAppendingPathComponent) {
    NSURL* fileURL = [NSURL fileURLWithPath:@"."];
    NSURL* newFileURL = [fileURL URLByAppendingPathComponent:@"Hello.txt"];
    ASSERT_TRUE_MSG([newFileURL isFileURL], "The passed URL should be a file URL type");

    NSString* fileURLString = [fileURL absoluteString];
    NSString* newFileURLString = [newFileURL absoluteString];
    fileURLString = [fileURLString stringByAppendingString:@"Hello.txt"];
    ASSERT_OBJCEQ_MSG(fileURLString, newFileURLString, "File URLs do not match!");
}

TEST(NSFoundation, NSURL_URLByAppendingPathExtension) {
    NSURL* fileURL = [NSURL fileURLWithPath:@"usr"];
    NSURL* newFileURL = [fileURL URLByAppendingPathExtension:@"World.txt"];
    ASSERT_TRUE_MSG([newFileURL isFileURL], "The passed URL should be a file URL type");

    NSString* fileURLString = [fileURL absoluteString];
    NSString* newFileURLString = [newFileURL absoluteString];
    if ([fileURLString length] > 0) {
        fileURLString = [fileURLString substringToIndex:[fileURLString length] - 1];
    } else {
        ASSERT_TRUE_MSG(false, "fileURLString string length cannot be ZERO!");
    }
    fileURLString = [fileURLString stringByAppendingString:@".World.txt"];
    ASSERT_OBJCEQ_MSG(fileURLString, newFileURLString, "File URLs do not match!");
}

TEST(NSFoundation, NSURL_checkResourceIsReachable) {
    // construct target URL using current directory and relative URL
    NSFileManager* manager = [NSFileManager defaultManager];
    NSURL *baseURL = [NSURL URLWithString: [manager currentDirectoryPath]];
    NSURL *targetURL = [NSURL URLWithString: @"data/NSFileManagerUT.txt" relativeToURL:baseURL];
    ASSERT_TRUE_MSG([targetURL checkResourceIsReachableAndReturnError:nullptr], "The target URL %@ exists", targetURL);

    NSURL *targetURLNonExist = [NSURL URLWithString: @"data/foo.txt" relativeToURL:baseURL];
    ASSERT_FALSE_MSG([targetURLNonExist checkResourceIsReachableAndReturnError:nullptr], "The target %@URL does not exist", targetURLNonExist);
}
