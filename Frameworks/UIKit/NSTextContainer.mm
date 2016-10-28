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

#include "Starboard.h"

#include "UIKit/NSParagraphStyle.h"
#include <CGPathInternal.h>

@implementation NSTextContainer {
    CGSize _size;
    NSLayoutManager* _layoutManager;
    StrongId<NSArray> _exclusionPaths;
}

/**
 @Status Interoperable
*/

- (instancetype)initWithSize:(CGSize)size {
    _size = size;
    _lineFragmentPadding = 5.0f;

    return self;
}

/**
 @Status Interoperable
*/

- (void)setSize:(CGSize)size {
    _size = size;

    [_layoutManager textContainerChangedGeometry:self];
}

/**
 @Status Caveat

 @Notes Only CGPath objects containing lines are supported
*/

- (void)setExclusionPaths:(NSArray*)paths {
    _exclusionPaths.attach([paths copy]);

    [_layoutManager textContainerChangedGeometry:self];
}

- (NSArray*)exclusionPaths {
    return _exclusionPaths;
}

static CGFloat _leftMostLocationForPath(CGRect proposedRectangle, CGPathRef path, CGFloat bufferAmount, bool eoFill) {
    CGFloat topLocation = proposedRectangle.origin.y;

    for (CGFloat left = proposedRectangle.origin.x; left < proposedRectangle.origin.x + proposedRectangle.size.width;
         left += bufferAmount) {
        // Transform is ignored since UIBezierPath has already applied it
        if (!CGPathContainsPoint(path, NULL, CGPointMake(left, topLocation), eoFill)) {
            return left;
        }
    }

    return proposedRectangle.origin.x + proposedRectangle.size.width;
}

static CGFloat _rightMostLocationForPath(CGRect proposedRectangle, CGPathRef path, CGFloat bufferAmount, bool eoFill) {
    CGFloat topLocation = proposedRectangle.origin.y;
    CGFloat lastRight = proposedRectangle.origin.x;

    for (CGFloat right = proposedRectangle.origin.x; right < proposedRectangle.origin.x + proposedRectangle.size.width;
         right += bufferAmount) {
        // Transform is ignored since UIBezierPath has already applied it
        if (CGPathContainsPoint(path, NULL, CGPointMake(right, topLocation), eoFill)) {
            return lastRight;
        }
        lastRight = right;
    }
    // No exclusion zone hit.
    return proposedRectangle.origin.x + proposedRectangle.size.width;
}

/**
 @Status Caveat
 @Notes writingDirection and atIndex parameters are ignored
*/

- (CGRect)lineFragmentRectForProposedRect:(CGRect)proposed
                                  atIndex:(NSUInteger)idx
                         writingDirection:(NSWritingDirection)direction
                            remainingRect:(CGRect*)remainingRect {
    // Issue 1123 & 1143 : This requires further investigation after CGPath work.
    CGRect totalRect = CGRectMake(0, 0, _size.width, _size.height);
    CGRect ret = CGRectIntersection(proposed, totalRect);

    if (_exclusionPaths != nil) {
        CGFloat leftMostAllowedPosition = proposed.origin.x;
        CGFloat rightMostAllowedPosition = proposed.origin.x + proposed.size.width;

        for (UIBezierPath* path in (NSArray*)_exclusionPaths) {
            for (CGFloat yposition = proposed.origin.y; yposition < proposed.origin.y + proposed.size.height;
                 yposition += self.lineFragmentPadding) {
                CGFloat leftMost = _leftMostLocationForPath(proposed, path.CGPath, self.lineFragmentPadding, path.usesEvenOddFillRule);
                if (leftMostAllowedPosition < leftMost) {
                    leftMostAllowedPosition = leftMost;
                }

                CGFloat rightMost = _rightMostLocationForPath(proposed, path.CGPath, self.lineFragmentPadding, path.usesEvenOddFillRule);
                if (rightMostAllowedPosition < rightMost) {
                    rightMostAllowedPosition = rightMost;
                }
            }
        }

        CGRect fitRect = CGRectMake(leftMostAllowedPosition,
                                    proposed.origin.y,
                                    rightMostAllowedPosition - leftMostAllowedPosition,
                                    proposed.size.height);
        ret = CGRectIntersection(fitRect, ret);

        if (remainingRect) {
            *remainingRect =
                CGRectMake(rightMostAllowedPosition, proposed.origin.y, proposed.size.width - fitRect.size.width, proposed.size.height);
        }
    }

    return ret;
}

@end
