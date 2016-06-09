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
#import <UIKit/UIColor.h>

TEST(UIColorTest, NamedUIColorMethods) {
    UIColor* color = [UIColor redColor];

    NSUInteger retainCount = [color retainCount];
    ASSERT_TRUE_MSG(retainCount == NSUIntegerMax, "Failed: RetainCount not correct for UICachedColor");

    [color release];
    [color release];
    [color release];
    [color release];
    retainCount = [color retainCount];
    ASSERT_TRUE_MSG(retainCount == NSUIntegerMax, "Failed: RetainCount not correct for UICachedColor");

    [color retain];
    [color retain];
    [color retain];
    [color retain];
    retainCount = [color retainCount];
    ASSERT_TRUE_MSG(retainCount == NSUIntegerMax, "Failed: RetainCount not correct for UICachedColor");

    color = [UIColor blueColor];
    retainCount = [color retainCount];
    ASSERT_TRUE_MSG(retainCount == NSUIntegerMax, "Failed: RetainCount not correct for UICachedColor");

    [color release];
    [color release];
    [color release];
    [color release];
    retainCount = [color retainCount];
    ASSERT_TRUE_MSG(retainCount == NSUIntegerMax, "Failed: RetainCount not correct for UICachedColor");

    [color retain];
    [color retain];
    [color retain];
    [color retain];
    retainCount = [color retainCount];
    ASSERT_TRUE_MSG(retainCount == NSUIntegerMax, "Failed: RetainCount not correct for UICachedColor");
}