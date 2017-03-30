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

#import <TestFramework.h>

#import <Starboard.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGBitmapContext.h>
#import <CoreGraphics/CGPattern.h>
#import <CppUtils.h>

#if TARGET_OS_WIN32
#import "CGContextInternal.h"
#import "TestUtils.h"

#endif

static NSString* const kPointsKey = @"PointsKey";
static NSString* const kTypeKey = @"TypeKey";
// Helper function to know # of points in an element
int cgContextPathPointCountForElementType(CGPathElementType type) {
    int pointCount = 0;

    switch (type) {
        case kCGPathElementMoveToPoint:
        case kCGPathElementAddLineToPoint:
            pointCount = 1;
            break;
        case kCGPathElementAddQuadCurveToPoint:
            pointCount = 2;
            break;
        case kCGPathElementAddCurveToPoint:
            pointCount = 3;
            break;
        case kCGPathElementCloseSubpath:
            pointCount = 0;
            break;
        default:
            break;
    }
    return pointCount;
}

// CGPathApplierFunction that adds elements to an NSMutableArray
void cgContextPathApplierFunction(void* info, const CGPathElement* element) {
    NSMutableArray* result = (__bridge NSMutableArray*)(info);

    int pointCount = cgContextPathPointCountForElementType(element->type);

    NSMutableArray* points = [NSMutableArray array];

    for (int i = 0; i < pointCount; i++) {
        CGPoint point = element->points[i];
        [points addObject:@(point.x)];
        [points addObject:@(point.y)];
    }

    [result addObject:@{ kTypeKey : @(element->type), kPointsKey : points }];
}

// Helper function that compares results from cgPathApplierFunction to expected results
void cgContextPathCompare(NSArray* expected, NSArray* result) {
    ASSERT_EQ(expected.count, result.count) << "Counts do not match for expected and result";

    [expected enumerateObjectsUsingBlock:^(NSDictionary* expectedDict, NSUInteger elementIndex, BOOL* stop) {
        NSDictionary* resultDict = result[elementIndex];
        CGPathElementType expectedType = (CGPathElementType)[expectedDict[kTypeKey] integerValue];
        CGPathElementType resultType = (CGPathElementType)[resultDict[kTypeKey] integerValue];
        ASSERT_EQ(expectedType, resultType) << "Elements in result and expected do not match";
        ASSERT_EQ([expectedDict[kPointsKey] count], [resultDict[kPointsKey] count])
            << "Point count in result and expected element do not match";

        [expectedDict[kPointsKey] enumerateObjectsUsingBlock:^(NSNumber* expectedPointValue, NSUInteger pointIndex, BOOL* stop) {
            float resultPoint = [resultDict[kPointsKey][pointIndex] floatValue];
            // Epsilon check for float precision
            ASSERT_LT(fabs(resultPoint - [expectedPointValue floatValue]), 0.01f);
            // ASSERT_FLOAT_EQ([expectedPointValue floatValue], resultPoint);
        }];
    }];
}

DISABLED_TEST(CGContext, CGContextCopyPathEllipse) {
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, rgbColorSpace, 0);
    // Ellipse Path Copy
    {
        CGMutablePathRef path = CGPathCreateMutable();

        CGRect rect = CGRectMake(40, 40, 200, 40);

        CGPathAddEllipseInRect(path, NULL, rect);
        // TODO :: Fix unit test expected results after Github Issue #621 is resolved.
        NSArray* expected = @[
            @{ kTypeKey : @(kCGPathElementMoveToPoint),
               kPointsKey : @[ @240, @60 ] },
            @{ kTypeKey : @(kCGPathElementAddCurveToPoint),
               kPointsKey : @[ @240, @71.045695, @195.228475, @80, @140, @80 ] },
            @{ kTypeKey : @(kCGPathElementAddCurveToPoint),
               kPointsKey : @[ @84.771525, @80, @40, @71.045695, @40, @60 ] },
            @{ kTypeKey : @(kCGPathElementAddCurveToPoint),
               kPointsKey : @[ @40, @48.954305, @84.771525, @40, @140, @40 ] },
            @{ kTypeKey : @(kCGPathElementAddCurveToPoint),
               kPointsKey : @[ @195.228475, @40, @240, @48.954305, @240, @60 ] },
            @{ kTypeKey : @(kCGPathElementCloseSubpath),
               kPointsKey : [NSArray array] },
            @{ kTypeKey : @(kCGPathElementMoveToPoint),
               kPointsKey : @[ @240, @60 ] }
        ];

        CGContextAddPath(context, path);
        CGPathRef copiedPath = CGContextCopyPath(context);

        CGContextBeginPath(context);

        NSMutableArray* result = [NSMutableArray array];

        CGPathApply(copiedPath, result, cgContextPathApplierFunction);

        cgContextPathCompare(expected, result);

        CGPathRelease(path);
        CGPathRelease(copiedPath);
    }

    CGContextRelease(context);
    CGColorSpaceRelease(rgbColorSpace);
}
DISABLED_TEST(CGContext, CGContextCopyPathArc) {
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, rgbColorSpace, 0);

    // Arc Path Copy
    {
        CGMutablePathRef path = CGPathCreateMutable();

        CGPathAddArc(path, NULL, 25, 100, 20, M_PI * 1.25, 0, 1);

        NSArray* expected = @[
            @{ kTypeKey : @(kCGPathElementMoveToPoint),
               kPointsKey : @[ @10.857863, @85.857865 ] },
            @{
                kTypeKey : @(kCGPathElementAddCurveToPoint),
                kPointsKey : @[ @3.047378, @93.668352, @3.047379, @106.331651, @10.857865, @114.142137 ]
            },
            @{
                kTypeKey : @(kCGPathElementAddCurveToPoint),
                kPointsKey : @[ @18.668352, @121.952622, @31.331651, @121.952621, @39.142137, @114.142135 ]
            },
            @{ kTypeKey : @(kCGPathElementAddCurveToPoint),
               kPointsKey : @[ @42.892864, @110.391407, @45, @105.304329, @45, @100 ] }
        ];

        CGContextAddPath(context, path);
        CGPathRef copiedPath = CGContextCopyPath(context);

        CGContextBeginPath(context);

        NSMutableArray* result = [NSMutableArray array];

        CGPathApply(copiedPath, result, cgContextPathApplierFunction);

        cgContextPathCompare(expected, result);

        CGPathRelease(path);
        CGPathRelease(copiedPath);
    }

    CGContextRelease(context);
    CGColorSpaceRelease(rgbColorSpace);
}
DISABLED_TEST(CGContext, CGContextCopyPathCGPathApplyAddArcToPoint) {
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, rgbColorSpace, 0);

    CGMutablePathRef path = CGPathCreateMutable();

    CGPathMoveToPoint(path, NULL, 400, 400);
    CGPathAddArcToPoint(path, NULL, 140, 250, 110, 180, 50);

    NSArray* expected = @[
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @400, @400 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @154.415379, @258.316565 ] },
        @{
            kTypeKey : @(kCGPathElementAddCurveToPoint),
            kPointsKey : @[ @145.057503, @252.917790, @137.699975, @244.633276, @133.444250, @234.703250 ]
        }
    ];

    CGContextAddPath(context, path);
    CGPathRef copiedPath = CGContextCopyPath(context);

    CGContextBeginPath(context);

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(copiedPath, result, cgContextPathApplierFunction);

    cgContextPathCompare(expected, result);

    CGPathRelease(path);
    CGPathRelease(copiedPath);

    CGContextRelease(context);
    CGColorSpaceRelease(rgbColorSpace);
}

DISABLED_TEST(CGPath, CGContextCopyPathCGPathAddQuadCurveToPoint) {
    CGColorSpaceRef rgbColorSpace = CGColorSpaceCreateDeviceRGB();
    CGContextRef context = CGBitmapContextCreate(0, 0, 0, 8, 0, rgbColorSpace, 0);

    CGMutablePathRef path = CGPathCreateMutable();

    CGPathMoveToPoint(path, NULL, 400, 400);
    CGPathAddQuadCurveToPoint(path, NULL, 140, 250, 110, 180);

    // TODO :: Fix unit test expected results after Github Issue #621 is resolved.
    // True Expected
    // kCGPathElementMoveToPoint
    //( 400.000000, 400.000000 )
    // kCGPathElementAddQuadCurveToPoint
    //( 140.000000, 250.000000 )
    //( 110.000000, 180.000000 )

    // Actual Produced
    // kCGPathElementMoveToPoint
    //( 400.000000, 400.000000 )
    // kCGPathElementAddCurveToPoint
    //( 226.667969, 300.000000 )
    //( 130.000000, 226.667969 )
    //( 110.000000, 180.000000 )

    NSArray* expected = @[
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @400, @400 ] },
        @{ kTypeKey : @(kCGPathElementAddCurveToPoint),
           kPointsKey : @[ @226.667969, @300, @130, @226.667969, @110, @180 ] }
    ];

    CGContextAddPath(context, path);
    CGPathRef copiedPath = CGContextCopyPath(context);

    CGContextBeginPath(context);

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(copiedPath, result, cgContextPathApplierFunction);

    cgContextPathCompare(expected, result);

    CGPathRelease(path);
    CGPathRelease(copiedPath);

    CGContextRelease(context);
    CGColorSpaceRelease(rgbColorSpace);
}

#if TARGET_OS_WIN32
class ContextCoordinateTest
    : public ::testing::TestWithParam<::testing::tuple<CGAffineTransform, std::vector<CGPoint>, std::vector<CGPoint>>> {
public:
    woc::unique_cf<CGContextRef> context;

    virtual void SetUp() {
        auto deviceColorSpace = woc::MakeStrongCF<CGColorSpaceRef>(CGColorSpaceCreateDeviceRGB());
        CGSize dimensions{ 100, 100 };
        context.reset(CGBitmapContextCreate(
            nullptr, dimensions.width, dimensions.height, 8, dimensions.width * 4, deviceColorSpace, kCGImageAlphaPremultipliedLast));

        ASSERT_NE(nullptr, context);

        CGAffineTransform contextTransform = ::testing::get<0>(GetParam());
        if (!CGAffineTransformIsIdentity(contextTransform)) {
            CGContextConcatCTM(context.get(), contextTransform);
        }
    }
};

static constexpr double c_errorDelta = 0.0001;
TEST_P(ContextCoordinateTest, ConvertToDeviceSpace) {
    const std::vector<CGPoint>& userSpacePoints = ::testing::get<1>(GetParam());
    const std::vector<CGPoint>& deviceSpacePoints = ::testing::get<2>(GetParam());
    for (unsigned int i = 0; i < userSpacePoints.size(); ++i) {
        const CGPoint& userSpacePoint = userSpacePoints[i];
        const CGPoint& deviceSpacePoint = deviceSpacePoints[i];
        CGPoint result = CGContextConvertPointToDeviceSpace(context.get(), userSpacePoint);
        EXPECT_NEAR(deviceSpacePoint.x, result.x, c_errorDelta);
        EXPECT_NEAR(deviceSpacePoint.y, result.y, c_errorDelta);
    }
}

TEST_P(ContextCoordinateTest, ConvertToUserSpace) {
    const std::vector<CGPoint>& userSpacePoints = ::testing::get<1>(GetParam());
    const std::vector<CGPoint>& deviceSpacePoints = ::testing::get<2>(GetParam());
    for (unsigned int i = 0; i < userSpacePoints.size(); ++i) {
        const CGPoint& userSpacePoint = userSpacePoints[i];
        const CGPoint& deviceSpacePoint = deviceSpacePoints[i];
        CGPoint result = CGContextConvertPointToUserSpace(context.get(), deviceSpacePoint);
        EXPECT_NEAR(userSpacePoint.x, result.x, c_errorDelta);
        EXPECT_NEAR(userSpacePoint.y, result.y, c_errorDelta);
    }
}

// clang-format off
::testing::tuple<CGAffineTransform, std::vector<CGPoint>, std::vector<CGPoint>> coordinateTestTuples[] = {
    // { Context Transform, Vector of user points, Vector of device points }
    {
        // CoreGraphics is a LLO drawing system, but Direct2D is ULO.
        // In device space, all coordinates are therefore inverted on the Y axis.
        // Our test images are 100x100, so 0, 0 maps to 100, 100.
        CGAffineTransformIdentity,
        { {  0,   0}, { 50,  50}, {100, 100} },
        { {  0, 100}, { 50,  50}, {100,   0} },
    },
    {
        // Coordinate system scaled by 2x
        CGAffineTransformMakeScale(2.0, 2.0),
        { {  0,   0}, { 25,  25}, { 50,  50} },
        { {  0, 100}, { 50,  50}, {100,   0} },
    },
    {
        // Coordinate system translated by 20, 20
        CGAffineTransformMakeTranslation(20, 20),
        { {  0,   0}, { 50,  50}, {100, 100} },
        { { 20,  80}, { 70,  30}, {120, -20} },
    },
    {
        // Coordinate system rotated by 45deg
        // Rotation should be COUNTERCLOCKWISE by default.
        CGAffineTransformMakeRotation(45. * M_PI / 180.),
        { {  0,   0}, { 20. * (M_SQRT2/2.), 20. * (M_SQRT2/2.)}, {                 0.,                        20.} },
        { {  0, 100}, {                 0.,                80.}, {-20. * (M_SQRT2/2.), 100. - (20. * (M_SQRT2/2))} },
    },
    {
        // Coordinate system transformed into ULO
        CGAffineTransformScale(CGAffineTransformMakeTranslation(0, 100), 1.0, -1.0),
        { {  0,   0}, { 50,  50}, {100, 100} },
        { {  0,   0}, { 50,  50}, {100, 100} },
    },
    {
        // Coordinate system transformed into ULO + 2x scale
        CGAffineTransformScale(CGAffineTransformScale(CGAffineTransformMakeTranslation(0, 100), 1.0, -1.0), 2.0, 2.0),
        { {  0,   0}, { 25,  25}, { 50,  50} },
        { {  0,   0}, { 50,  50}, {100, 100} },
    },
    {
        // Coordinate system transformed into ULO + 45deg rotation
        // Rotation should now be CLOCKWISE.
        CGAffineTransformRotate(CGAffineTransformScale(CGAffineTransformMakeTranslation(0, 100), 1.0, -1.0), 45. * M_PI / 180.),
        { {  0,   0}, { 20. * (M_SQRT2/2.), 20. * (M_SQRT2/2.)}, {                 0.,               20.} },
        { {  0,   0}, {                 0.,                20.}, {-20. * (M_SQRT2/2.), 20. * (M_SQRT2/2)} },
    },
};
// clang-format on

INSTANTIATE_TEST_CASE_P(CGContextCoordinateSpace, ContextCoordinateTest, ::testing::ValuesIn(coordinateTestTuples));
#endif

TEST(CGContext, DrawAnImageIntoContext) {
    woc::unique_cf<CGColorSpaceRef> rgbColorSpace(CGColorSpaceCreateDeviceRGB());

    // Create a canvas context
    woc::unique_cf<CGContextRef> context(CGBitmapContextCreate(nullptr,
                                                               512,
                                                               256,
                                                               8,
                                                               4 * 512 /* bytesPerRow = bytesPerPixel*width*/,
                                                               rgbColorSpace.get(),
                                                               kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big));

    // Load an image from file
    CFDataRef data = (CFDataRef)[NSData dataWithContentsOfFile:getPathToFile(@"data/jpg1.jpg")];
    woc::unique_cf<CGDataProviderRef> dataProvider(CGDataProviderCreateWithCFData(data));

    woc::unique_cf<CGImageRef> cgImage(CGImageCreateWithJPEGDataProvider(dataProvider.get(), NULL, NO, kCGRenderingIntentDefault));
    ASSERT_NE(cgImage, nullptr);

    CGRect bounds = { 0, 0, 512, 256 };
    CGAffineTransform flip = CGAffineTransformMakeScale(1, -1);
    CGAffineTransform shift = CGAffineTransformTranslate(flip, 0, bounds.size.height * -1);
    CGContextConcatCTM(context.get(), shift);

    // Check the canvas context pixel before drawing
    BYTE* dataPtr = static_cast<BYTE*>(CGBitmapContextGetData(context.get()));
    ASSERT_NE(dataPtr, nullptr);

    // Draw the image into the canvas context
    CGContextDrawImage(context.get(), bounds, cgImage.get());

    // Check the canvas context pixel after drawing
    dataPtr = static_cast<BYTE*>(CGBitmapContextGetData(context.get()));
    ASSERT_NE(dataPtr, nullptr);
    // Check the first pixel value of the drawn image.
    EXPECT_EQ(dataPtr[0], 0x98);
}

TEST(CGContext, DrawAContextImageIntoAContext) {
    woc::unique_cf<CGColorSpaceRef> rgbColorSpace(CGColorSpaceCreateDeviceRGB());

    // Create a bitmap context to draw into
    woc::unique_cf<CGContextRef> contextImage(CGBitmapContextCreate(
        nullptr, 10, 10, 8, 4 * 10 /* bytesPerRow = bytesPerPixel*width*/, rgbColorSpace.get(), kCGImageAlphaPremultipliedFirst));
    ASSERT_NE(contextImage, nullptr);

    // flood the bitmap context with a pretty color.
    CGContextSetRGBFillColor(contextImage.get(), 1.0, 0.0, 0.0, 1.0);
    CGContextFillRect(contextImage.get(), { 0, 0, 10, 10 });

    // Create a image out of the bitmap context
    woc::unique_cf<CGImageRef> image(CGBitmapContextCreateImage(contextImage.get()));
    ASSERT_NE(image, nullptr);

    // This will be the pseudo canvas context which we will draw into
    woc::unique_cf<CGContextRef> context(CGBitmapContextCreate(nullptr,
                                                               512,
                                                               256,
                                                               8,
                                                               4 * 512 /* bytesPerRow = bytesPerPixel*width*/,
                                                               rgbColorSpace.get(),
                                                               kCGImageAlphaPremultipliedLast | kCGBitmapByteOrder32Big));

    CGRect bounds = { 0, 0, 512, 256 };

    CGAffineTransform flip = CGAffineTransformMakeScale(1, -1);
    CGAffineTransform shift = CGAffineTransformTranslate(flip, 0, bounds.size.height * -1);
    CGContextConcatCTM(context.get(), shift);

    // Check the canvas context pixel before drawing
    BYTE* dataPtr = static_cast<BYTE*>(CGBitmapContextGetData(context.get()));
    ASSERT_NE(dataPtr, nullptr);

    // Draw the image into the canvas context
    CGContextDrawImage(context.get(), bounds, image.get());

    // Check the canvas context pixel after drawing
    dataPtr = static_cast<BYTE*>(CGBitmapContextGetData(context.get()));
    ASSERT_NE(dataPtr, nullptr);
    EXPECT_EQ(dataPtr[0], 0xff);
}

TEST(CGContext, TextPositionShouldBeInMatrix) {
    woc::unique_cf<CGColorSpaceRef> grayColorSpace{ CGColorSpaceCreateDeviceGray() };
    woc::unique_cf<CGContextRef> context{ CGBitmapContextCreate(0, 1, 1, 8, 1, grayColorSpace.get(), kCGImageAlphaOnly) };
    EXPECT_EQ(CGAffineTransformIdentity, CGContextGetTextMatrix(context.get()));
    EXPECT_EQ(CGPointMake(0, 0), CGContextGetTextPosition(context.get()));
    CGContextSetTextPosition(context.get(), 25, 50);
    EXPECT_EQ(CGAffineTransformMake(1, 0, 0, 1, 25, 50), CGContextGetTextMatrix(context.get()));
    EXPECT_EQ(CGPointMake(25, 50), CGContextGetTextPosition(context.get()));

    CGAffineTransform transform{ 2, 1, 0, 1, 15, -25 };
    CGContextSetTextMatrix(context.get(), transform);
    EXPECT_EQ(transform, CGContextGetTextMatrix(context.get()));
    EXPECT_EQ(CGPointMake(15, -25), CGContextGetTextPosition(context.get()));
}
