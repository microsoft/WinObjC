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

// Windows-only:
//      NSString _reverseString

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import "NSStringInternal.h"

TEST(Foundation, ReverseString) {
    NSString* str = @"hello";
    NSString* reverse = [str _reverseString];
    ASSERT_TRUE_MSG(reverse != nil, "FAILED: String should not be nil");

    NSString* expectedValue = @"olleh";
    ASSERT_TRUE_MSG([reverse isEqualToString:expectedValue], "FAILED: ReverseString Invalid output");

    str = @"";
    reverse = [str _reverseString];
    ASSERT_TRUE_MSG(reverse != nil, "FAILED: String should not be nil");

    expectedValue = @"";
    ASSERT_TRUE_MSG([reverse isEqualToString:expectedValue], "FAILED: ReverseString Invalid output");

    str = @"e";
    reverse = [str _reverseString];
    ASSERT_TRUE_MSG(reverse != nil, "FAILED: String should not be nil");

    expectedValue = @"e";
    ASSERT_TRUE_MSG([reverse isEqualToString:expectedValue], "FAILED: ReverseString Invalid output");
}