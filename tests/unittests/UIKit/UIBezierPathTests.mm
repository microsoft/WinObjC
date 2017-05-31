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
#import <UIKit/UIBezierPath.h>
#import <Starboard/SmartTypes.h>

TEST(UIBezierPath, containsPoint) {
    UIBezierPath* path = [UIBezierPath bezierPathWithRect:CGRectMake(0, 0, 100, 100)];
    ASSERT_TRUE_MSG(path != nil, "Failed to instantiate UIBezierPath.");

    EXPECT_TRUE([path containsPoint:CGPointMake(50, 50)]);
    EXPECT_FALSE([path containsPoint:CGPointMake(150, 150)]);
}

TEST(UIBezierPath, isEmpty) {
    UIBezierPath* path = [UIBezierPath bezierPath];
    EXPECT_TRUE([path isEmpty]);
    [path moveToPoint:CGPointMake(0, 0)];
    [path addLineToPoint:CGPointMake(100, 100)];
    [path closePath];
    EXPECT_FALSE([path isEmpty]);
}

TEST(UIBezierPath, currentPoint) {
    UIBezierPath* path = [UIBezierPath bezierPath];

    CGPoint currentPoint = CGPointMake(0, 0);
    [path moveToPoint:currentPoint];
    EXPECT_TRUE([path currentPoint] == currentPoint);

    currentPoint = CGPointMake(50, 50);
    [path addLineToPoint:currentPoint];
    EXPECT_TRUE([path currentPoint] == currentPoint);

    currentPoint = CGPointMake(100, 40);
    [path addQuadCurveToPoint:currentPoint controlPoint:CGPointMake(100, 50)];
    EXPECT_TRUE([path currentPoint] == currentPoint);

    currentPoint = CGPointMake(0, 0);
    [path closePath];
    EXPECT_TRUE([path currentPoint] == currentPoint);
}