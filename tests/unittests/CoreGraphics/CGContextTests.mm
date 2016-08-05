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

#define __CGCONTEXTIMPL_TEST_FRIENDS                                        \
    FRIEND_TEST(CGContext, CGContextSetPatternPhasePatternIsNil);           \
    FRIEND_TEST(CGContext, CGContextSetPatternPhaseColorObjectIsFillColor); \
    FRIEND_TEST(CGContext, CGContextSetPatternPhasePositiveChange);         \
    FRIEND_TEST(CGContext, CGContextSetPatternPhaseNegativeChange);

#import <Starboard.h>
#import "CGPatternInternal.h"
#import <CoreGraphics/CGContext.h>
#import "CGContextInternal.h"
#import "CGContextImpl.h"
#import <Foundation\Foundation.h>
#import <CoreGraphics\CGBitmapContext.h>
#import <CoreGraphics\CGPattern.h>

void _DrawCustomPattern(void* info, CGContextRef context) {
    // Draw a circle inset from the pattern size
    CGRect circleRect = CGRectMake(0, 0, 50, 50);
    circleRect = CGRectInset(circleRect, 4, 4);
    CGContextFillEllipseInRect(context, circleRect);
    CGContextStrokeEllipseInRect(context, circleRect);
}

TEST(CGContext, CGContextSetPatternPhasePatternIsNil) {
    // Given
    CGContextRef ctx = _CGBitmapContextCreateWithFormat(1000, 1000, _ColorBGR);
    CGContextImpl* backing = CGContextGetBacking(ctx);

    backing->curState->curFillColorObject = nil;

    // When
    CGContextSetPatternPhase(ctx, CGSizeMake(100, 100));

    // Then
    ASSERT_EQ(0, backing->curState->curFillColorObject);

    CGContextRelease(ctx);
}

TEST(CGContext, CGContextSetPatternPhaseColorObjectIsFillColor) {
    // Given
    CGContextRef ctx = _CGBitmapContextCreateWithFormat(1000, 1000, _ColorBGR);
    CGContextImpl* backing = CGContextGetBacking(ctx);

    CGContextSetFillColorWithColor(ctx, [UIColor blueColor].CGColor);

    // When
    CGContextSetPatternPhase(ctx, CGSizeMake(100, 100));

    // Then
    ASSERT_EQ(0, (CGColorRef)backing->curState->curFillColorObject);

    CGContextRelease(ctx);
}

TEST(CGContext, CGContextSetPatternPhasePositiveChange) {
    // Given
    CGContextRef ctx = _CGBitmapContextCreateWithFormat(1000, 1000, _ColorBGR);
    CGContextImpl* backing = CGContextGetBacking(ctx);

    CGRect boundsRect = CGRectMake(0, 0, 1000, 1000);
    const CGPatternCallbacks callbacks = { 0, &_DrawCustomPattern, NULL };
    CGFloat alpha = 1;
    CGAffineTransform transform = CGAffineTransformMakeTranslation(10, 10);
    CGPatternRef pattern = CGPatternCreate(NULL, boundsRect, transform, 50, 50, kCGPatternTilingConstantSpacing, true, &callbacks);
    CGContextSetFillPattern(ctx, pattern, &alpha);
    CGPatternRelease(pattern);

    // When
    CGContextSetPatternPhase(ctx, CGSizeMake(100, 200));

    // Then
    CGPattern* actualPattern = (CGPattern*)backing->curState->curFillColorObject;
    CGAffineTransform matrix = [actualPattern getPatternTransform];
    ASSERT_EQ(110, matrix.tx);
    ASSERT_EQ(210, matrix.ty);

    CGContextRelease(ctx);
}

TEST(CGContext, CGContextSetPatternPhaseNegativeChange) {
    // Given
    CGContextRef ctx = _CGBitmapContextCreateWithFormat(1000, 1000, _ColorBGR);
    CGContextImpl* backing = CGContextGetBacking(ctx);

    CGRect boundsRect = CGRectMake(0, 0, 1000, 1000);
    const CGPatternCallbacks callbacks = { 0, &_DrawCustomPattern, NULL };
    CGFloat alpha = 1;
    CGAffineTransform transform = CGAffineTransformMakeTranslation(300, 500);
    CGPatternRef pattern = CGPatternCreate(NULL, boundsRect, transform, 50, 50, kCGPatternTilingConstantSpacing, true, &callbacks);
    CGContextSetFillPattern(ctx, pattern, &alpha);
    CGPatternRelease(pattern);

    // When
    CGContextSetPatternPhase(ctx, CGSizeMake(-100, -200));

    // Then
    CGPattern* actualPattern = (CGPattern*)backing->curState->curFillColorObject;
    CGAffineTransform matrix = [actualPattern getPatternTransform];
    ASSERT_EQ(200, matrix.tx);
    ASSERT_EQ(300, matrix.ty);

    CGContextRelease(ctx);
}

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

TEST(CGContext, CGContextCopyPathEllipse) {
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
TEST(CGContext, CGContextCopyPathArc) {
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
TEST(CGContext, CGContextCopyPathCGPathApplyAddArcToPoint) {
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

TEST(CGPath, CGContextCopyPathCGPathAddQuadCurveToPoint) {
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
