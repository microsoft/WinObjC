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

void testStringFromRange(NSString* testString, NSRange expectedRange) {
    NSRange actualRange = NSRangeFromString(testString);
    EXPECT_EQ(expectedRange.location, actualRange.location);
    EXPECT_EQ(expectedRange.length, actualRange.length);
}

TEST(NSRange, NSRangeTests) {
    testStringFromRange(@"{1, 2}", { 1, 2 });
    testStringFromRange(@"1, 2}", { 1, 2 });
    testStringFromRange(@"{1, 2", { 1, 2 });
    testStringFromRange(@"{a, 2}", { 2, 0 });
    testStringFromRange(@"{1,, 2}", { 1, 2 });
    testStringFromRange(@"{1.3, 2}", { 1, 3 });
    testStringFromRange(@"{2147483648, 2}", { 2147483648, 2 });
    testStringFromRange(@"\r\n{1, 2}", { 1, 2 });
    testStringFromRange(@"{  2, 4  }", { 2, 4 });
    testStringFromRange(@"{-1, -2}", { 1, 2 });
    testStringFromRange(@"1 2", { 1, 2 });
    testStringFromRange(@"{1,2,3}", { 1, 2 });
    testStringFromRange(@"", { 0, 0 });
}