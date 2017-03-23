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
#include <tuple>
#include "CppUtils.h"

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

class CGGeometryDivRect : public ::testing::TestWithParam<::testing::tuple<CGRect, CGFloat, CGRectEdge, CGRect, CGRect>> {};

TEST_P(CGGeometryDivRect, RectDivide) {
    CGRect rect = ::testing::get<0>(GetParam());
    CGFloat amount = ::testing::get<1>(GetParam());
    CGRectEdge edge = ::testing::get<2>(GetParam());
    CGRect rSlice = ::testing::get<3>(GetParam());
    CGRect rRemainder = ::testing::get<4>(GetParam());

    CGRect slice, remainder;
    CGRectDivide(rect, &slice, &remainder, amount, edge);

    EXPECT_EQ(rSlice, slice);
    EXPECT_EQ(rRemainder, remainder);
}

// clang-format off
static const ::testing::tuple<CGRect, CGFloat, CGRectEdge, /*slice*/ CGRect, /*remainder*/ CGRect> s_cCGRectDivideResults[] = {
    
    //Advances in X direction (edge:min/max) valid amount
    ::testing::make_tuple(CGRectMake(0, 0, 100, 100),
                          10.35,
                          CGRectMaxXEdge,
                          CGRectMake(89.65, 0, 10.35, 100),
                          CGRectMake(0, 0, 89.65, 100)),

    ::testing::make_tuple(CGRectMake(0, 0, 100, 100),
                          10.35,
                          CGRectMinXEdge,
                          CGRectMake(0, 0, 10.35, 100),
                          CGRectMake(10.35, 0, 89.65, 100)),

    ::testing::make_tuple(CGRectMake(100, 100, 125, 250),
                          50.34,
                          CGRectMaxXEdge,
                          CGRectMake(174.66, 100, 50.34, 250),
                          CGRectMake(100, 100, 74.66, 250)), 
    
    ::testing::make_tuple(CGRectMake(100, 100, 125, 250),
                          32,
                          CGRectMinXEdge,
                          CGRectMake(100, 100, 32, 250),
                          CGRectMake(132, 100, 93, 250)),


    ::testing::make_tuple(CGRectMake(10.50, 25.60, 300, 500),
                          10,
                          CGRectMinXEdge,
                          CGRectMake(10.50, 25.60, 10, 500),
                          CGRectMake(20.50, 25.60, 290, 500)),
    
    ::testing::make_tuple(CGRectMake(10.50, 25.60, 300, 500),
                          0.34,
                          CGRectMaxYEdge,
                          CGRectMake(10.50, 525.26, 300, 0.34),
                          CGRectMake(10.50, 25.60, 300, 499.66)),

    //Advances in Y direction (edge:min/max) valid amount
    ::testing::make_tuple(CGRectMake(10.50, 25.60, 300, 500),
                          120,
                          CGRectMinYEdge,
                          CGRectMake(10.50, 25.60, 300, 120),
                          CGRectMake(10.50, 145.60, 300, 380)),
  
    ::testing::make_tuple(CGRectMake(100, 100, 125, 250),
                          20,
                          CGRectMaxYEdge,
                          CGRectMake(100, 330, 125, 20),
                          CGRectMake(100, 100, 125, 230)),

    ::testing::make_tuple(CGRectMake(0, 0, 100, 100),
                          10.35,
                          CGRectMinYEdge,
                          CGRectMake(0, 0, 100, 10.35),
                          CGRectMake(0, 10.35, 100, 89.65)),
    
    ::testing::make_tuple(CGRectMake(0, 0, 900, 800),
                          0.34,
                          CGRectMaxYEdge,
                          CGRectMake(0, 799.66, 900, 0.34),
                          CGRectMake(0, 0, 900, 799.66)),

    ::testing::make_tuple(CGRectMake(0, 0, 100, 100),
                          10.35,
                          CGRectMaxYEdge,
                          CGRectMake(0, 89.65, 100, 10.35),
                          CGRectMake(0, 0, 100, 89.65)),


    //Advances in X direction (edge:min/max) negative
    ::testing::make_tuple(CGRectMake(0, 0, 900, 800),
                          -50,
                          CGRectMaxXEdge,
                          CGRectMake(900, 0, 0, 800),
                          CGRectMake(0, 0, 900, 800)),
    
    ::testing::make_tuple(CGRectMake(0, 0, 900, 800),
                          -502,
                          CGRectMinXEdge,
                          CGRectMake(0, 0, 0, 800),
                          CGRectMake(0, 0, 900, 800)),

    //Advances in Y direction (edge:min/max) negative
    ::testing::make_tuple(CGRectMake(100, 100, 125, 250),
                          -50.24,
                          CGRectMinYEdge,
                          CGRectMake(100, 100, 125, 0),
                          CGRectMake(100, 100, 125, 250)),
   
    ::testing::make_tuple(CGRectMake(10.50, 25.60, 300, 500),
                          -50,
                          CGRectMaxXEdge,
                          CGRectMake(310.50, 25.60, 0, 500),
                          CGRectMake(10.50, 25.60, 300, 500)),
    
    //Advances out of range X,Y (edge: min max)
    ::testing::make_tuple(CGRectMake(0, 0, 900, 800),
                          905,
                          CGRectMinYEdge,
                          CGRectMake(0, 0, 900, 800),
                          CGRectMake(0, 800, 900, 0)),

    ::testing::make_tuple(CGRectMake(0, 0, 200, 800),
                          905,
                          CGRectMaxYEdge,
                          CGRectMake(0, 0, 200, 800),
                          CGRectMake(0, 0, 200, 0)),

    ::testing::make_tuple(CGRectMake(0, 0, 200, 800),
                          300,
                          CGRectMinXEdge,
                          CGRectMake(0, 0, 200, 800),
                          CGRectMake(200, 0, 0, 800)),

    ::testing::make_tuple(CGRectMake(0, 0, 200, 800),
                          300,
                          CGRectMaxXEdge,
                          CGRectMake(0, 0, 200, 800),
                          CGRectMake(0, 0, 0, 800)),

    ::testing::make_tuple(CGRectMake(50, 100, 900, 800),
                          905,
                          CGRectMinYEdge,
                          CGRectMake(50, 100, 900, 800),
                          CGRectMake(50, 900, 900, 0)),

    ::testing::make_tuple(CGRectMake(50, 100, 900, 800),
                          905,
                          CGRectMaxYEdge,
                          CGRectMake(50, 100, 900, 800),
                          CGRectMake(50, 100, 900, 0)),

    ::testing::make_tuple(CGRectMake(50, 100, 200, 800),
                          300, CGRectMaxXEdge,
                          CGRectMake(50, 100, 200, 800),
                          CGRectMake(50, 100, 0, 800)),

    ::testing::make_tuple(CGRectMake(50, 100,200, 800),
                          300,
                          CGRectMinXEdge,
                          CGRectMake(50, 100, 200, 800),
                          CGRectMake(250, 100, 0, 800)),

    //Advances in X,Y direction for CGRectNULL (edge:min/max)
    ::testing::make_tuple(CGRectNull,
                        -50.24,
                        CGRectMaxXEdge,
                        CGRectNull,
                        CGRectNull),

    ::testing::make_tuple(CGRectNull,
                        150.240000,
                        CGRectMinXEdge,
                        CGRectNull,
                        CGRectNull),

    ::testing::make_tuple(CGRectNull,
                        -50.24,
                        CGRectMaxYEdge,
                        CGRectNull,
                        CGRectNull),

    ::testing::make_tuple(CGRectNull,
                        150.240000,
                        CGRectMinYEdge,
                        CGRectNull,
                        CGRectNull),

    //Advances in X,Y direction (edge:min/max) amount 0
    ::testing::make_tuple(CGRectMake(0, 0, 900, 800),
                          0,
                          CGRectMaxXEdge,
                          CGRectMake(900, 0, 0, 800),
                          CGRectMake(0, 0, 900, 800)),
    
    ::testing::make_tuple(CGRectMake(0, 0, 900, 800),
                          0,
                          CGRectMinXEdge,
                          CGRectMake(0, 0, 0, 800),
                          CGRectMake(0, 0, 900, 800)),

    ::testing::make_tuple(CGRectMake(100, 100, 125, 250),
                          0,
                          CGRectMinYEdge,
                          CGRectMake(100, 100, 125, 0),
                          CGRectMake(100, 100, 125, 250)),
   
    ::testing::make_tuple(CGRectMake(10.50, 25.60, 300, 500),
                          0,
                          CGRectMaxXEdge,
                          CGRectMake(310.50, 25.60, 0, 500),
                          CGRectMake(10.50, 25.60, 300, 500)),
};
// clang-format on

INSTANTIATE_TEST_CASE_P(CGGeometry, CGGeometryDivRect, ::testing::ValuesIn(s_cCGRectDivideResults));

TEST(CGGeometry, RectDivideInf) {
    CGRect expectedSlice = CGRectInfinite;
    expectedSlice.size.width = 0;

    CGRect slice, remainder;
    CGRectDivide(CGRectInfinite, &slice, &remainder, -50.24, CGRectMaxXEdge);
    EXPECT_EQ(expectedSlice, slice);
    EXPECT_EQ(CGRectInfinite, remainder);

    expectedSlice = CGRectInfinite;
    expectedSlice.size.width = 500;
    CGRectDivide(CGRectInfinite, &slice, &remainder, 500, CGRectMinXEdge);
    EXPECT_EQ(expectedSlice, slice);
    EXPECT_EQ(CGRectInfinite, remainder);

    expectedSlice = CGRectInfinite;
    expectedSlice.size.height = 500;
    CGRectDivide(CGRectInfinite, &slice, &remainder, 500, CGRectMaxYEdge);
    EXPECT_EQ(expectedSlice, slice);
    EXPECT_EQ(CGRectInfinite, remainder);

    expectedSlice = CGRectInfinite;
    expectedSlice.size.height = 0;
    CGRectDivide(CGRectInfinite, &slice, &remainder, -50, CGRectMinYEdge);
    EXPECT_EQ(expectedSlice, slice);
    EXPECT_EQ(CGRectInfinite, remainder);
}
