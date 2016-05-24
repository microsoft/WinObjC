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
#include <Foundation\Foundation.h>

TEST(NSError, NSErrorSanity) {
    NSError* error1 = [NSError errorWithDomain:@"TestDomain" code:2 userInfo:@{@1 : @"foo", @2 : @"bar"}];
    NSError* error2 = [NSError errorWithDomain:@"TestDomain" code:2 userInfo:@{@1 : @"foo", @2 : @"bar"}];
    NSError* error3 = [NSError errorWithDomain:@"DifferentTestDomain" code:2 userInfo:@{@1 : @"foo", @2 : @"bar"}];

    ASSERT_OBJCEQ(error1, error2);
    ASSERT_EQ([error1 hash], [error2 hash]);
    ASSERT_OBJCNE(error1, error3);
    ASSERT_NE([error1 hash], [error3 hash]);
}

