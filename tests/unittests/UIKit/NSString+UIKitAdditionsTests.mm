//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <TestFramework.h>
#import <UIKit/UIKit.h>
#import <CppUtils.h>

static constexpr double c_errorDelta = .0001;
TEST(NSString_UIKitAdditions, ShouldNotReturnSizeOfZeroWidth) {
    CGSize size =
        [@"TEST" sizeWithFont:[UIFont systemFontOfSize:12.0f] constrainedToSize:CGSizeZero lineBreakMode:NSLineBreakByWordWrapping];
    EXPECT_LT(0.0, size.width);
    EXPECT_LT(0.0, size.height);
}

TEST(NSString_UIKitAdditions, SizeWithFontShouldReturnLineHeightWhenConstrainedHeightIsTooSmall) {
    CGSize givenSize = { 0, 15 };
    UIFont* font = [UIFont systemFontOfSize:144];
    CGFloat lineHeight = [font ascender] - [font descender];
    CGSize size = [@"TEST" sizeWithFont:font constrainedToSize:givenSize];
    EXPECT_NEAR(lineHeight, size.height, c_errorDelta);

    size = [@"TEST\nTEST" sizeWithFont:font constrainedToSize:givenSize];
    EXPECT_NEAR(lineHeight, size.height, c_errorDelta);
}

TEST(NSString_UIKitAdditions, SizeWithNoFontShouldReturnCGSizeZero) {
    CGSize arbitrarySize = { 100, 150 };
    EXPECT_EQ(CGSizeZero, [@"TEST" sizeWithFont:nil constrainedToSize:arbitrarySize]);
}