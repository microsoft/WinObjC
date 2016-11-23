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

#include "DrawingTest.h"
#include "DrawingTestConfig.h"
#include "ImageComparison.h"
#include "ImageHelpers.h"

#include <Starboard/SmartTypes.h>
#include <memory>

static const CGSize g_defaultCanvasSize{ 512.f, 256.f };

woc::unique_cf<CGColorSpaceRef> testing::DrawTest::s_deviceColorSpace;

void testing::DrawTest::SetUpTestCase() {
    s_deviceColorSpace.reset(CGColorSpaceCreateDeviceRGB());
}

void testing::DrawTest::TearDownTestCase() {
    s_deviceColorSpace.release();
}

CGSize testing::DrawTest::CanvasSize() {
    return g_defaultCanvasSize;
}

void testing::DrawTest::SetUp() {
    CGSize size = CanvasSize();

    _context.reset(CGBitmapContextCreate(
        nullptr, size.width, size.height, 8, size.width * 4, s_deviceColorSpace.get(), kCGImageAlphaPremultipliedFirst));
    ASSERT_NE(nullptr, _context);

    _bounds = { CGPointZero, size };

    SetUpContext();
}

CFStringRef testing::DrawTest::CreateAdditionalTestDescription() {
    return nullptr;
}

CFStringRef testing::DrawTest::CreateOutputFilename() {
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

void testing::DrawTest::TearDown() {
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
        PixelByPixelImageComparator comparator;
        auto delta = comparator.CompareImages(referenceImage.get(), image.get());

        if (delta.result != ImageComparisonResult::Same) {
            if (delta.result == ImageComparisonResult::Incomparable) {
                ADD_FAILURE() << "images are incomparable due to a mismatch in dimensions, presence, or byte length";
            } else {
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

void testing::DrawTest::SetUpContext() {
    // The default context is fine as-is.
}

void testing::DrawTest::TestBody() {
    // Nothing.
}

CGContextRef testing::DrawTest::GetDrawingContext() {
    return _context.get();
}

void testing::DrawTest::SetDrawingBounds(CGRect bounds) {
    _bounds = bounds;
}

CGRect testing::DrawTest::GetDrawingBounds() {
    return _bounds;
}

void WhiteBackgroundTest::SetUpContext() {
    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextSaveGState(context);
    CGContextSetRGBFillColor(context, 1.0, 1.0, 1.0, 1.0);
    CGContextFillRect(context, bounds);
    CGContextRestoreGState(context);

    CGContextSetRGBStrokeColor(context, 0.0, 0.0, 0.0, 1.0);
}

CGSize UIKitMimicTest::CanvasSize() {
    CGSize parent = WhiteBackgroundTest::CanvasSize();
    return { parent.width * 2., parent.height * 2. };
}

void UIKitMimicTest::SetUpContext() {
    WhiteBackgroundTest::SetUpContext();

    CGContextRef context = GetDrawingContext();
    CGRect bounds = GetDrawingBounds();

    CGContextScaleCTM(context, 1.0, -1.0);
    CGContextTranslateCTM(context, 0, -bounds.size.height);
    CGContextScaleCTM(context, 2.0, 2.0);
    bounds = CGRectApplyAffineTransform(bounds, CGAffineTransformMakeScale(.5, .5));

    SetDrawingBounds(bounds);
}
