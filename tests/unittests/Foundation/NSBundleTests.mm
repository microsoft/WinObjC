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

TEST(NSBundle, NSBundle_SanityTest) {
    LOG_INFO("NSBundle sanity test: ");

    NSString* filePath = [NSBundle mainBundle].bundlePath;
    NSURL* fileURL = [NSURL fileURLWithPath:filePath];

    NSBundle* bundle = [NSBundle bundleWithPath:filePath];
    ASSERT_OBJCEQ_MSG(filePath, [bundle bundlePath], @"Expected bundle path does not match the actual path");

    ASSERT_OBJCEQ_MSG(fileURL, [bundle bundleURL], @"Expected bundle URL does not match the actual URL");

    ASSERT_EQ_MSG(nil, [NSBundle bundleWithPath:nil], @"Bundle with nil path somehow not nil");
}

TEST(NSBundle, ClassNamed) {
    ASSERT_OBJCEQ([NSString class], [[NSBundle mainBundle] classNamed:@"NSString"]);
}