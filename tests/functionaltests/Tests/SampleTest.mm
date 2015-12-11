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
#include <Foundation\Foundation.h>

// SampleTest
// Notes:
//     1. Tests are written exactly the way the Unit Tests are written and all tests use GTest macros.
//

TEST(SampleTest, Sanity) {
    LOG_INFO("SampleTest sanity test: ");

    NSArray* arr1 = [NSArray arrayWithObject:@1];
    NSArray* arr2 = [NSArray arrayWithObject:@1];

    ASSERT_OBJCEQ(arr1, arr2);
}

TEST(SampleTest, Failure) {
    LOG_INFO("SampleTest failure test: ");

    NSArray* arr1 = [NSArray arrayWithObject:@5];
    NSArray* arr2 = [NSArray arrayWithObject:@10];

    ASSERT_OBJCNE(arr1, arr2);
}
