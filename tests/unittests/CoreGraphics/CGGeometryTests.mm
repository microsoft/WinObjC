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

#include <TestFramework.h>

#include <CoreGraphics/CoreGraphics.h>

TEST(CGSize, ApplyAffineTransform) {
    CGSize size{ 100, 100 };

    CGAffineTransform scaleX = CGAffineTransformMakeScale(2.0, 1.0);
    CGAffineTransform scaleY = CGAffineTransformMakeScale(1.0, 2.0);
    CGAffineTransform flipY = CGAffineTransformMakeScale(1.0, -1.0);
    CGAffineTransform translate = CGAffineTransformMakeTranslation(-10, -10);

    // Scaling is applied to the width and height.
    CGSize transformedSize = CGSizeApplyAffineTransform(size, scaleX);
    EXPECT_TRUE(CGSizeEqualToSize(CGSize{ 200, 100 }, transformedSize));

    transformedSize = CGSizeApplyAffineTransform(size, scaleY);
    EXPECT_TRUE(CGSizeEqualToSize(CGSize{ 100, 200 }, transformedSize));

    transformedSize = CGSizeApplyAffineTransform(size, flipY);
    EXPECT_TRUE(CGSizeEqualToSize(CGSize{ 100, -100 }, transformedSize));

    // Translation is not applied to the width and height.
    transformedSize = CGSizeApplyAffineTransform(size, translate);
    EXPECT_TRUE(CGSizeEqualToSize(size, transformedSize));

    // Identity transform evaluates to identity.
    transformedSize = CGSizeApplyAffineTransform(size, CGAffineTransformIdentity);
    EXPECT_TRUE(CGSizeEqualToSize(size, transformedSize));

    // Size transformation is invertible.
    CGAffineTransform rotate = CGAffineTransformMakeRotation(5. * M_PI / 180.);
    transformedSize = CGSizeApplyAffineTransform(size, rotate);
    EXPECT_FALSE(CGSizeEqualToSize(size, transformedSize));

    CGSize inverseTransformedSize = CGSizeApplyAffineTransform(transformedSize, CGAffineTransformInvert(rotate));
    EXPECT_NEAR(size.width, inverseTransformedSize.width, 0.001);
    EXPECT_NEAR(size.height, inverseTransformedSize.height, 0.001);
}