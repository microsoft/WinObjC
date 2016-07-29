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
#import <Starboard/SmartTypes.h>
#import <CoreGraphics\CGPath.h>
#import <Foundation\Foundation.h>

#import <CoreGraphics/CGColor.h>
#import <CoreGraphics/CGColorSpace.h>

static NSString* const kPointsKey = @"PointsKey";
static NSString* const kTypeKey = @"TypeKey";
// Helper function to know # of points in an element
int cgPathPointCountForElementType(CGPathElementType type) {
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
    }
    return pointCount;
}

// CGPathApplierFunction that adds elements to an NSMutableArray
void cgPathApplierFunction(void* info, const CGPathElement* element) {
    NSMutableArray* result = (__bridge NSMutableArray*)(info);

    int pointCount = cgPathPointCountForElementType(element->type);

    NSMutableArray* points = [NSMutableArray array];

    for (int i = 0; i < pointCount; i++) {
        CGPoint point = element->points[i];
        [points addObject:@(point.x)];
        [points addObject:@(point.y)];
    }

    [result addObject:@{ kTypeKey : @(element->type), kPointsKey : points }];
}

// Helper function that compares results from cgPathApplierFunction to expected results
void cgPathCompare(NSArray* expected, NSArray* result) {
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
            ASSERT_FLOAT_EQ([expectedPointValue floatValue], resultPoint);
        }];
    }];
}

TEST(CGPath, CGPathApplyAddRect) {
    CGMutablePathRef path = CGPathCreateMutable();

    CGRect rect = CGRectMake(2, 4, 8, 16);

    CGPathAddRect(path, NULL, rect);

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(path, result, cgPathApplierFunction);

    NSArray* expected = @[
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @2, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @10, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @10, @20 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @2, @20 ] },
        @{ kTypeKey : @(kCGPathElementCloseSubpath),
           kPointsKey : [NSArray array] }
    ];

    cgPathCompare(expected, result);

    CGPathRelease(path);
}

TEST(CGPath, CGPathApplyAddEllipse) {
    CGMutablePathRef path = CGPathCreateMutable();

    CGRect rect = CGRectMake(40, 40, 200, 40);

    CGPathAddEllipseInRect(path, NULL, rect);

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(path, result, cgPathApplierFunction);

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
           kPointsKey : [NSArray array] }
    ];

    cgPathCompare(expected, result);

    CGPathRelease(path);
}

TEST(CGPath, CGPathApplyAddArc) {
    CGMutablePathRef path = CGPathCreateMutable();

    CGPathAddArc(path, NULL, 25, 100, 20, M_PI * 1.25, 0, 1);

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(path, result, cgPathApplierFunction);

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

    cgPathCompare(expected, result);

    CGPathRelease(path);
}

TEST(CGPath, CGPathApplyAddArcToPoint) {
    CGMutablePathRef path = CGPathCreateMutable();

    CGPathMoveToPoint(path, NULL, 400, 400);
    CGPathAddArcToPoint(path, NULL, 140, 250, 110, 180, 50);

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(path, result, cgPathApplierFunction);

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

    cgPathCompare(expected, result);

    CGPathRelease(path);
}

TEST(CGPath, CGPathAddQuadCurveToPoint) {
    CGMutablePathRef path = CGPathCreateMutable();

    CGPathMoveToPoint(path, NULL, 400, 400);
    CGPathAddQuadCurveToPoint(path, NULL, 140, 250, 110, 180);

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(path, result, cgPathApplierFunction);

    NSArray* expected = @[
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @400, @400 ] },
        @{ kTypeKey : @(kCGPathElementAddQuadCurveToPoint),
           kPointsKey : @[ @140, @250, @110, @180 ] }
    ];

    cgPathCompare(expected, result);

    CGPathRelease(path);
}

TEST(CGPath, CGPathCreateMutableCopy) {
    CGMutablePathRef path1 = CGPathCreateMutable();

    CGRect rect = CGRectMake(2, 4, 8, 16);

    CGPathAddEllipseInRect(path1, NULL, rect);

    CGMutablePathRef path2 = CGPathCreateMutableCopy(path1);

    ASSERT_NE(path1, path2);

    ASSERT_TRUE(CGPathEqualToPath(path1, path2));

    CGPathRelease(path1);

    CGPathRelease(path2);
}

TEST(CGPath, CGPathEqualToPath) {
    CGMutablePathRef path1 = CGPathCreateMutable();

    CGRect rect = CGRectMake(2, 4, 8, 16);

    CGPathAddRect(path1, NULL, rect);

    // Create a copy of the path
    CGMutablePathRef path2 = CGPathCreateMutableCopy(path1);

    // Change the copy
    CGPathAddEllipseInRect(path2, NULL, rect);

    // Make sure the paths are not the same object
    ASSERT_NE(path1, path2);

    // Make sure paths are not equal
    ASSERT_FALSE(CGPathEqualToPath(path1, path2));

    // Release the copy
    CGPathRelease(path2);

    // Now test the original path to make sure it's still what we expect
    NSArray* expected = @[
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @2, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @10, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @10, @20 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @2, @20 ] },
        @{ kTypeKey : @(kCGPathElementCloseSubpath),
           kPointsKey : [NSArray array] }
    ];

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(path1, result, cgPathApplierFunction);

    cgPathCompare(expected, result);

    CGPathRelease(path1);
}

TEST(CGPath, CGPathApplyAddManyRects) {
    CGMutablePathRef path = CGPathCreateMutable();
    NSMutableArray* expected = [NSMutableArray array];
    for (int i = 0; i < 100; i++) {
        CGRect rect = CGRectMake(i, 4, 8, 16);

        CGPathAddRect(path, NULL, rect);

        NSArray* expectedRect = @[
            @{ kTypeKey : @(kCGPathElementMoveToPoint),
               kPointsKey : @[ @(i), @4 ] },
            @{ kTypeKey : @(kCGPathElementAddLineToPoint),
               kPointsKey : @[ @(i + 8), @4 ] },
            @{ kTypeKey : @(kCGPathElementAddLineToPoint),
               kPointsKey : @[ @(i + 8), @20 ] },
            @{ kTypeKey : @(kCGPathElementAddLineToPoint),
               kPointsKey : @[ @(i), @20 ] },
            @{ kTypeKey : @(kCGPathElementCloseSubpath),
               kPointsKey : [NSArray array] }
        ];
        [expected addObjectsFromArray:expectedRect];
    }

    NSMutableArray* result = [NSMutableArray array];

    CGPathApply(path, result, cgPathApplierFunction);

    cgPathCompare(expected, result);

    CGPathRelease(path);
}

TEST(CGPath, CGPathAddPath) {
    CGMutablePathRef path1 = CGPathCreateMutable();

    CGRect rect1 = CGRectMake(2, 4, 8, 16);

    CGPathAddRect(path1, NULL, rect1);

    CGMutablePathRef path2 = CGPathCreateMutable();

    CGRect rect2 = CGRectMake(4, 4, 8, 16);

    CGPathAddRect(path2, NULL, rect2);

    CGPathAddPath(path1, NULL, path2);

    NSArray* expected1 = @[
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @2, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @10, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @10, @20 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @2, @20 ] },
        @{ kTypeKey : @(kCGPathElementCloseSubpath),
           kPointsKey : [NSArray array] },
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @4, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @12, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @12, @20 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @4, @20 ] },
        @{ kTypeKey : @(kCGPathElementCloseSubpath),
           kPointsKey : [NSArray array] }
    ];

    NSArray* expected2 = @[
        @{ kTypeKey : @(kCGPathElementMoveToPoint),
           kPointsKey : @[ @4, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @12, @4 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @12, @20 ] },
        @{ kTypeKey : @(kCGPathElementAddLineToPoint),
           kPointsKey : @[ @4, @20 ] },
        @{ kTypeKey : @(kCGPathElementCloseSubpath),
           kPointsKey : [NSArray array] }
    ];

    NSMutableArray* result2 = [NSMutableArray array];

    CGPathApply(path1, result2, cgPathApplierFunction);

    cgPathCompare(expected1, result2);

    CGPathRelease(path2);

    NSMutableArray* result1 = [NSMutableArray array];

    CGPathApply(path1, result1, cgPathApplierFunction);

    cgPathCompare(expected1, result1);

    CGPathRelease(path1);
}

CGPathRef newPathForRoundRect(CGRect rect, CGFloat radius) {
    CGMutablePathRef path = CGPathCreateMutable();
    CGRect innerRect = CGRectInset(rect, radius, radius);
    CGFloat insideRight = innerRect.origin.x + innerRect.size.width;
    CGFloat outsideRight = rect.origin.x + rect.size.width;
    CGFloat insideBottom = innerRect.origin.y + innerRect.size.height;
    CGFloat outsideBottom = rect.origin.y + rect.size.height;

    CGFloat insideTop = innerRect.origin.y;
    CGFloat outsideTop = rect.origin.y;
    CGFloat outsideLeft = rect.origin.x;

    CGPathMoveToPoint(path, NULL, innerRect.origin.x, outsideTop);

    CGPathAddLineToPoint(path, NULL, insideRight, outsideTop);
    CGPathAddArcToPoint(path, NULL, outsideRight, outsideTop, outsideRight, insideTop, radius);

    CGPathAddLineToPoint(path, NULL, outsideRight, insideBottom);
    CGPathAddArcToPoint(path, NULL, outsideRight, outsideBottom, insideRight, outsideBottom, radius);

    CGPathAddLineToPoint(path, NULL, innerRect.origin.x, outsideBottom);
    CGPathAddArcToPoint(path, NULL, outsideLeft, outsideBottom, outsideLeft, insideBottom, radius);

    CGPathAddLineToPoint(path, NULL, outsideLeft, insideTop);
    CGPathAddArcToPoint(path, NULL, outsideLeft, outsideTop, innerRect.origin.x, outsideTop, radius);

    CGPathCloseSubpath(path);

    return path;
}

TEST(CGPath, CGPathContainsPointOutsideRect) {
    CGFloat originX = 10.0f;
    CGFloat originY = 20.0f;
    CGFloat pathWidth = 100.0f;
    CGFloat pathHeight = 200.0f;
    CGRect testRect = CGRectMake(originX, originY, pathWidth, pathHeight);
    CGFloat radius = 10.0f;
    CGPathRef path = newPathForRoundRect(testRect, radius);

    // test areas outside the rect
    CGPoint testPoint = CGPointMake(-1.0f, -1.0f);
    bool test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_FALSE(test);

    testPoint = CGPointMake(testRect.size.width + testRect.origin.x + 1, 0.f);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_FALSE(test);

    testPoint = CGPointMake(0.0f, testRect.size.height + testRect.origin.y + 1.0f);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_FALSE(test);
}

TEST(CGPath, CGPathContainsPointInsideRectOutsidePath) {
    CGFloat originX = 10.0f;
    CGFloat originY = 20.0f;
    CGFloat pathWidth = 100.0f;
    CGFloat pathHeight = 200.0f;
    CGRect testRect = CGRectMake(originX, originY, pathWidth, pathHeight);
    CGFloat radius = 10.0f;
    CGPathRef path = newPathForRoundRect(testRect, radius);

    // test areas inside the rect but NOT in the path
    CGPoint testPoint = CGPointMake(1.0f, 1.0f);
    bool test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_FALSE(test);

    testPoint = CGPointMake(testRect.origin.x, 0.0f);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_FALSE(test);

    testPoint = CGPointMake(0.0f, testRect.origin.y);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_FALSE(test);
}
TEST(CGPath, CGPathContainsPointShoulders) {
    CGFloat originX = 10.0f;
    CGFloat originY = 20.0f;
    CGFloat pathWidth = 100.0f;
    CGFloat pathHeight = 200.0f;
    CGRect testRect = CGRectMake(originX, originY, pathWidth, pathHeight);
    CGFloat radius = 10.0f;
    CGPathRef path = newPathForRoundRect(testRect, radius);

    // check the curve OUTSIDE the path's shoulders
    CGPoint testPoint = CGPointMake(testRect.origin.x + 1.0, testRect.origin.y + 1.0);
    bool test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_FALSE(test);

    // check the curve just INSIDE the path's shoulders
    testPoint = CGPointMake(testRect.origin.x + radius, testRect.origin.y + radius);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_TRUE(test);

    testPoint = CGPointMake(testRect.origin.x + testRect.size.width - radius - radius, testRect.origin.y + testRect.size.height - 20.0);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_TRUE(test);

    testPoint = CGPointMake(testRect.origin.x + radius, testRect.origin.y + testRect.size.height - radius - radius);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_TRUE(test);

    testPoint = CGPointMake(testRect.origin.x + testRect.size.width - radius - radius, testRect.origin.y + radius);
    test = CGPathContainsPoint(path, NULL, testPoint, YES);

    EXPECT_TRUE(test);
}

TEST(CGPath, CGPathContainsPointWithTransform) {
    CGFloat originX = 10.0f;
    CGFloat originY = 20.0f;
    CGFloat pathWidth = 100.0f;
    CGFloat pathHeight = 200.0f;
    CGRect testRect = CGRectMake(originX, originY, pathWidth, pathHeight);
    CGFloat radius = 10.0f;
    CGPathRef path = newPathForRoundRect(testRect, radius);

    // test areas inside the rect but NOT in the path ...
    CGPoint testPoint = CGPointMake(testRect.origin.x - 1.0f, testRect.origin.y - 1.0f);
    // ... and transform it in
    CGAffineTransform transform = CGAffineTransformMakeTranslation(testRect.origin.x, testRect.origin.y);
    bool test = CGPathContainsPoint(path, &transform, testPoint, YES);

    EXPECT_TRUE(test);
}

TEST(CGPath, CGPathContainsPointEOFillFalse) {
    CGFloat originX = 10.0f;
    CGFloat originY = 20.0f;
    CGFloat pathWidth = 100.0f;
    CGFloat pathHeight = 200.0f;
    CGRect testRect = CGRectMake(originX, originY, pathWidth, pathHeight);
    CGFloat radius = 10.0f;
    CGPathRef path = newPathForRoundRect(testRect, radius);

    // same tests inside the rect as above with eoFill false.
    // OUTSIDE rect tests are not needed, since they return before before any painting is done.

    // test areas inside the rect but NOT in the path
    CGPoint testPoint = CGPointMake(1.0f, 1.0f);
    bool test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_FALSE(test);

    testPoint = CGPointMake(testRect.origin.x, 0.0f);
    test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_FALSE(test);

    testPoint = CGPointMake(0.0f, testRect.origin.y);
    test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_FALSE(test);

    // check the curve OUTSIDE the path's shoulders
    testPoint = CGPointMake(testRect.origin.x + 1.0, testRect.origin.y + 1.0);
    test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_FALSE(test);

    // check the curve just INSIDE the path's shoulders
    testPoint = CGPointMake(testRect.origin.x + radius, testRect.origin.y + radius);
    test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_TRUE(test);

    testPoint = CGPointMake(testRect.origin.x + testRect.size.width - radius - radius, testRect.origin.y + testRect.size.height - 20.0);
    test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_TRUE(test);

    testPoint = CGPointMake(testRect.origin.x + radius, testRect.origin.y + testRect.size.height - radius - radius);
    test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_TRUE(test);

    testPoint = CGPointMake(testRect.origin.x + testRect.size.width - radius - radius, testRect.origin.y + radius);
    test = CGPathContainsPoint(path, NULL, testPoint, NO);

    EXPECT_TRUE(test);

    // test areas inside the rect but NOT in the path ...
    CGAffineTransform transform = CGAffineTransformMakeTranslation(testRect.origin.x, testRect.origin.y);

    testPoint = CGPointMake(testRect.origin.x - 1.0f, testRect.origin.y - 1.0f);
    test = CGPathContainsPoint(path, &transform, testPoint, NO);

    EXPECT_TRUE(test);
}
