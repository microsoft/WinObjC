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

TEST(UIColor, ColorTests) {
    UIColor* color = [UIColor redColor];
    UIColor* color2 = [UIColor colorWithRed:1 green:0 blue:0 alpha:1];
    EXPECT_OBJCEQ(color, color2);

    color = [UIColor blackColor];
    color2 = [UIColor colorWithWhite:0 alpha:1];
    EXPECT_OBJCEQ(color, color2);

    color = [UIColor blackColor];
    color2 = [UIColor colorWithRed:0 green:0 blue:0 alpha:1];
    EXPECT_OBJCNE(color, color2);
}