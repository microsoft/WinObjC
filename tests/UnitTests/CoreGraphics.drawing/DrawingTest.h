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

#pragma once

#include <TestFramework.h>
#include <CoreGraphics/CoreGraphics.h>

#include <Starboard/SmartTypes.h>

namespace testing {
class DrawTest : public ::testing::Test {
private:
    woc::unique_cf<CGContextRef> _context;
    CGRect _bounds;

protected:
    static woc::unique_cf<CGColorSpaceRef> s_deviceColorSpace;

public:
    static void SetUpTestCase();
    static void TearDownTestCase();

    virtual CFStringRef CreateAdditionalTestDescription();
    virtual CFStringRef CreateOutputFilename();
    virtual CGSize CanvasSize();
    virtual void SetUpContext();
    virtual void SetUp();
    virtual void TearDown();
    virtual void TestBody();

    CGContextRef GetDrawingContext();
    void SetDrawingBounds(CGRect bounds);
    CGRect GetDrawingBounds();
};
}

inline CGPoint _CGRectGetCenter(CGRect rect) {
    return {
        rect.origin.x + (rect.size.width / 2.f), rect.origin.y + (rect.size.height / 2.f),
    };
}

inline CGRect _CGRectCenteredOnPoint(CGSize size, CGPoint point) {
    return {
        {
            point.x - (size.width / 2.f), point.y - (size.height / 2.f),
        },
        size,
    };
}

class WhiteBackgroundTest : public ::testing::DrawTest {
protected:
    virtual void SetUpContext();
};

class UIKitMimicTest : public WhiteBackgroundTest {
protected:
    virtual CGSize CanvasSize();
    virtual void SetUpContext();
};

#define DRAW_TEST(test_case_name, test_name) \
    GTEST_TEST_(test_case_name, test_name, ::testing::DrawTest, ::testing::internal::GetTestTypeId())
#define DRAW_TEST_F(test_case_name, test_name, test_fixture) \
    GTEST_TEST_(test_case_name, test_name, test_fixture, ::testing::internal::GetTestTypeId())

#define DISABLED_DRAW_TEST(test_case_name, test_name) DRAW_TEST(test_case_name, DISABLED_##test_name)
#define DISABLED_DRAW_TEST_F(test_case_name, test_name, test_fixture) DRAW_TEST_F(test_case_name, DISABLED_##test_name, test_fixture)

#define DRAW_TEST_P(test_case_name, test_name) TEST_P(test_case_name, test_name)
#define DISABLED_DRAW_TEST_P(test_case_name, test_name) DRAW_TEST_P(test_case_name, DISABLED_##test_name)