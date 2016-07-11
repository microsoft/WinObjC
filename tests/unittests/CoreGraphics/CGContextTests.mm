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
#import <CoreGraphics\CGContext.h>
#import "CGContextInternal.h"
#import "CGContextImpl.h"
#import <Foundation\Foundation.h>
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
    CGContextRef ctx = CGBitmapContextCreate24(1000, 1000);
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
    CGContextRef ctx = CGBitmapContextCreate24(1000, 1000);
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
    CGContextRef ctx = CGBitmapContextCreate24(1000, 1000);
    CGContextImpl* backing = CGContextGetBacking(ctx);

    CGRect boundsRect = CGRectMake(0, 0,1000, 1000);
    const CGPatternCallbacks callbacks = { 0, &_DrawCustomPattern, NULL };
    CGFloat alpha = 1;
    CGAffineTransform transform = CGAffineTransformMakeTranslation(10, 10);
    CGPatternRef pattern = CGPatternCreate(
        NULL, boundsRect, transform, 50, 50, kCGPatternTilingConstantSpacing, true, &callbacks);
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
    CGContextRef ctx = CGBitmapContextCreate24(1000, 1000);
    CGContextImpl* backing = CGContextGetBacking(ctx);

    CGRect boundsRect = CGRectMake(0, 0,1000, 1000);
    const CGPatternCallbacks callbacks = { 0, &_DrawCustomPattern, NULL };
    CGFloat alpha = 1;
    CGAffineTransform transform = CGAffineTransformMakeTranslation(300, 500);
    CGPatternRef pattern = CGPatternCreate(
        NULL, boundsRect, transform, 50, 50, kCGPatternTilingConstantSpacing, true, &callbacks);
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
