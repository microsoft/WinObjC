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

#include "ImageComparison.h"
#include "DrawingTest.h"
#include "DrawingTestConfig.h"
#include "ImageHelpers.h"

#include <Starboard/SmartTypes.h>
#include <memory>
#include <TestFramework.h>
#include <CoreGraphics/CoreGraphics.h>

#include <Starboard/SmartTypes.h>
#include <type_traits>

static const CGSize g_defaultCanvasSize{ 512.f, 256.f };


namespace testing {
template <typename TComparator>
class DrawTest : public ::testing::Test {
    static_assert(std::is_default_constructible<TComparator>::value, "Comparator must be default constructible");
private:
    woc::unique_cf<CGContextRef> _context;
    CGRect _bounds;

protected:
    static woc::unique_cf<CGColorSpaceRef> s_deviceColorSpace;
public:
    static void SetUpTestCase() {
        s_deviceColorSpace.reset(CGColorSpaceCreateDeviceRGB());
    }

    static void TearDownTestCase() {
        s_deviceColorSpace.release();
    }

    virtual CFStringRef CreateAdditionalTestDescription() {
        return nullptr;
    }

    virtual CFStringRef CreateOutputFilename() {
        const ::testing::TestInfo* const test_info = ::testing::UnitTest::GetInstance()->current_test_info();
        woc::unique_cf<CFStringRef> additionalDesc{ CreateAdditionalTestDescription() };
        woc::unique_cf<CFStringRef> filename{ CFStringCreateWithFormat(nullptr,
                                                                       nullptr,
                                                                       CFSTR("TestImage.%s.%s%s%@.png"),
                                                                       test_info->test_case_name(),
                                                                       test_info->name(),
                                                                       (additionalDesc ? "." : ""),
                                                                       (additionalDesc ? additionalDesc.get() : CFSTR(""))) };
        return filename.release();
    }

    virtual CGSize CanvasSize() {
        return g_defaultCanvasSize;
    }

    virtual void SetUpContext() {
        // The default context is fine as-is.
    }

    virtual void SetUp() {
        CGSize size = CanvasSize();

        _context.reset(CGBitmapContextCreate(
            nullptr, size.width, size.height, 8, size.width * 4, s_deviceColorSpace.get(), kCGImageAlphaPremultipliedFirst));
        ASSERT_NE(nullptr, _context);

        _bounds = { CGPointZero, size };

        SetUpContext();
    }
    virtual void TearDown() {
        CGContextRef context = GetDrawingContext();

        // Generate image from context.
        woc::unique_cf<CGImageRef> image{ CGBitmapContextCreateImage(context) };
        ASSERT_NE(nullptr, image);

        // Generate output filename (generally, TestCase.TestName.png).
        woc::unique_cf<CFStringRef> originalFilename{ CreateOutputFilename() };

        woc::unique_cf<CFMutableStringRef> filename{ CFStringCreateMutableCopy(nullptr, 0, originalFilename.get()) };

        CFStringFindAndReplace(filename.get(), CFSTR("DISABLED_"), CFSTR(""), CFRange{ 0, CFStringGetLength(filename.get()) }, 0);
        CFStringFindAndReplace(filename.get(), CFSTR("/"), CFSTR("_"), CFRange{ 0, CFStringGetLength(filename.get()) }, 0);

        auto drawingConfig = DrawingTestConfig::Get();

        // Write the context image to the output file.
        woc::unique_cf<CFDataRef> actualImageData{ _CFDataCreatePNGFromCGImage(image.get()) };
        ASSERT_NE(nullptr, actualImageData);

        woc::unique_cf<CFStringRef> outputPath{
            CFStringCreateWithFormat(nullptr, nullptr, CFSTR("%s/%@"), drawingConfig->GetOutputPath().c_str(), filename.get())
        };
        ASSERT_NE(nullptr, outputPath);
        outputPath.reset(_CFStringCreateAbsolutePath(outputPath.get()));

        ASSERT_TRUE(_WriteCFDataToFile(actualImageData.get(), outputPath.get()));

        // For comparisons ...
        if (drawingConfig->GetMode() == DrawingTestMode::Compare) {
            // ... load the reference image (same name, different directory as the output image)
            woc::unique_cf<CFStringRef> referenceFilename{
                CFStringCreateWithFormat(nullptr, nullptr, CFSTR("%s/%@"), drawingConfig->GetComparisonPath().c_str(), filename.get())
            };
            referenceFilename.reset(_CFStringCreateAbsolutePath(referenceFilename.get()));

            woc::unique_cf<CGImageRef> referenceImage{ _CGImageCreateFromPNGFile(referenceFilename.get()) };
            ASSERT_NE(nullptr, referenceImage);

            // And fire off a comparator.
            TComparator comparator;
            auto delta = comparator.CompareImages(referenceImage.get(), image.get());

            if (delta.result != ImageComparisonResult::Same) {
                if (delta.result == ImageComparisonResult::Incomparable) {
                    ADD_FAILURE() << "images are incomparable due to a mismatch in dimensions, presence, or byte length";
                }
                else {
                    ADD_FAILURE() << "images differ nontrivially";
                }

                woc::unique_cf<CFStringRef> deltaFilename{
                    CFStringCreateWithFormat(nullptr, nullptr, CFSTR("%s/Greenline.%@"), drawingConfig->GetOutputPath().c_str(), filename.get())
                };
                deltaFilename.reset(_CFStringCreateAbsolutePath(deltaFilename.get()));

                woc::unique_cf<CFDataRef> encodedDeltaImageData{ _CFDataCreatePNGFromCGImage(delta.deltaImage.get()) };

                _WriteCFDataToFile(encodedDeltaImageData.get(), deltaFilename.get());

                RecordProperty("expectedImage", CFStringGetCStringPtr(referenceFilename.get(), kCFStringEncodingUTF8));
                RecordProperty("actualImage", CFStringGetCStringPtr(outputPath.get(), kCFStringEncodingUTF8));
                RecordProperty("deltaImage", CFStringGetCStringPtr(deltaFilename.get(), kCFStringEncodingUTF8));
            }
        }
    }

    virtual void TestBody() {
        // Nothing
    }

    CGContextRef GetDrawingContext() {
        return _context.get();
    }

    void SetDrawingBounds(CGRect bounds) {
        _bounds = bounds;
    }

    CGRect GetDrawingBounds() {
        return _bounds;
    }
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

template <typename TComparator>
class WhiteBackgroundTest : public ::testing::DrawTest<TComparator> {
protected:
    virtual void SetUpContext() {
        CGContextRef context = this->GetDrawingContext();
        CGRect bounds = this->GetDrawingBounds();

        CGContextSaveGState(context);
        CGContextSetRGBFillColor(context, 1.0, 1.0, 1.0, 1.0);
        CGContextFillRect(context, bounds);
        CGContextRestoreGState(context);

        CGContextSetRGBStrokeColor(context, 0.0, 0.0, 0.0, 1.0);
    }
};

template <typename TComparator>
class UIKitMimicTest : public WhiteBackgroundTest<TComparator> {
protected:
    virtual CGSize CanvasSize() {
        CGSize parent = WhiteBackgroundTest<TComparator>::CanvasSize();
        return{ parent.width * 2., parent.height * 2. };
    }

    virtual void SetUpContext() {
        WhiteBackgroundTest<TComparator>::SetUpContext();

        CGContextRef context = this->GetDrawingContext();
        CGRect bounds = this->GetDrawingBounds();

        CGContextScaleCTM(context, 1.0, -1.0);
        CGContextTranslateCTM(context, 0, -bounds.size.height);
        CGContextScaleCTM(context, 2.0, 2.0);
        bounds = CGRectApplyAffineTransform(bounds, CGAffineTransformMakeScale(.5, .5));

        this->SetDrawingBounds(bounds);
    }
};

template <typename TComparator>
woc::unique_cf<CGColorSpaceRef> testing::DrawTest<TComparator>::s_deviceColorSpace;

#define DRAW_TEST(test_case_name, test_name) \
    GTEST_TEST_(test_case_name, test_name, ::testing::DrawTest<PixelByPixelImageComparator<ComparisonMode::Exact, 1>>, ::testing::internal::GetTestTypeId())
#define DRAW_TEST_F(test_case_name, test_name, test_fixture) \
    GTEST_TEST_(test_case_name, test_name, test_fixture, ::testing::internal::GetTestTypeId())

#define DISABLED_DRAW_TEST(test_case_name, test_name) DRAW_TEST(test_case_name, DISABLED_##test_name)
#define DISABLED_DRAW_TEST_F(test_case_name, test_name, test_fixture) DRAW_TEST_F(test_case_name, DISABLED_##test_name, test_fixture)

#define DRAW_TEST_P(test_case_name, test_name) TEST_P(test_case_name, test_name)
#define DISABLED_DRAW_TEST_P(test_case_name, test_name) DRAW_TEST_P(test_case_name, DISABLED_##test_name)

#define TEXT_DRAW_TEST(test_case_name, test_name) \
    GTEST_TEST_(test_case_name, test_name, ::testing::DrawTest<PixelByPixelImageComparator<ComparisonMode::Mask, 1>>, ::testing::internal::GetTestTypeId())
#define TEXT_DRAW_TEST_F(test_case_name, test_name, test_fixture) \
    GTEST_TEST_(test_case_name, test_name, test_fixture, ::testing::internal::GetTestTypeId())

#define DISABLED_TEXT_DRAW_TEST(test_case_name, test_name) TEXT_DRAW_TEST(test_case_name, DISABLED_##test_name)
#define DISABLED_TEXT_DRAW_TEST_F(test_case_name, test_name, test_fixture) TEXT_DRAW_TEST_F(test_case_name, DISABLED_##test_name, test_fixture)

#define TEXT_DRAW_TEST_P(test_case_name, test_name) TEST_P(test_case_name, test_name)
#define DISABLED_TEXT_DRAW_TEST_P(test_case_name, test_name) TEXT_DRAW_TEST_P(test_case_name, DISABLED_##test_name)