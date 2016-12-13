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
#include <CGContextInternal.h>

#include <vector>
#include <algorithm>

static constexpr CGFloat c_defaultPadding = 5.0f;
@implementation NSTextContainer {
    CGSize _size;
    NSLayoutManager* _layoutManager;
    StrongId<NSArray> _exclusionPaths;
    // TODO 1394: Remove for CGD2D
    // All of the _exclusion* lists are expected to maintain the same lengths
    std::vector<woc::unique_cf<CGContextRef>> _exclusionContexts;
    std::vector<CGRect> _exclusionPathBoundingRects;
}

/**
 @Status Interoperable
*/

- (instancetype)initWithSize:(CGSize)size {
    if (self = [super init]) {
        _size = size;
        _lineFragmentPadding = c_defaultPadding;
    }

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
    // TODO 1394: Remove for CGD2D
    _exclusionContexts.clear();
    _exclusionPathBoundingRects.clear();
    for (UIBezierPath* path in static_cast<NSArray*>(_exclusionPaths)) {
        // Create an empty bitmap context to be as small as possible
        woc::unique_cf<CGContextRef> context{ CGBitmapContextCreate(nullptr, 1, 1, 1, 1, nullptr, 0) };
        CGContextAddPath(context.get(), path.CGPath);
        _exclusionContexts.emplace_back(std::move(context));
        _exclusionPathBoundingRects.emplace_back(CGPathGetBoundingBox(path.CGPath));
    }

    [_layoutManager textContainerChangedGeometry:self];
}

- (NSArray*)exclusionPaths {
    return _exclusionPaths;
}

// Finds the first viable region for the proposed rect given the exclusion areas based upon x positions
// Assumes writing direction is left to right, exclusionLines is sorted and preprocessed for y positions, and all inputs are valid
static CGRect __FirstPossibleRectForProposed(CGRect proposed,
                                             const std::vector<CGRect>& exclusionLines,
                                             CGFloat padding,
                                             CGFloat maxWidth) {
    for (auto path : exclusionLines) {
        if (proposed.origin.x < path.origin.x) {
            proposed.size.width = path.origin.x - proposed.origin.x - padding;
            if (proposed.size.width > padding) {
                break;
            }
        }
        if (path.origin.x + path.size.width > proposed.origin.x) {
            proposed.origin.x = (path.origin.x + path.size.width) + padding;
            proposed.size.width = maxWidth - proposed.origin.x;
        }
    }

    return proposed;
}

// Finds the first point at which the given rect intersects the given exclusionContext, moving by delta each iteration
static CGFloat __GetXPositionIntersectingZone(CGRect rect, const CGContextRef exclusionContext, CGFloat delta, CGFloat maxWidth) {
    while (0 <= rect.origin.x && rect.origin.x < maxWidth &&
           !CGContextIsPointInPath(exclusionContext, true, rect.origin.x + delta, rect.origin.y) &&
           !CGContextIsPointInPath(exclusionContext, true, rect.origin.x + delta, rect.origin.y + rect.size.height / 2.0) &&
           !CGContextIsPointInPath(exclusionContext, true, rect.origin.x + delta, rect.origin.y + rect.size.height)) {
        rect.origin.x += delta;
    }

    return rect.origin.x;
}

/**
 @Status Caveat
 @Notes writingDirection and atIndex parameters are ignored
 * TODO 1465: handle writing directions
*/

- (CGRect)lineFragmentRectForProposedRect:(CGRect)proposed
                                  atIndex:(NSUInteger)idx
                         writingDirection:(NSWritingDirection)direction
                            remainingRect:(CGRect*)remainingRect {
    if (remainingRect) {
        *remainingRect = CGRectZero;
    }

    CGRect totalRect = CGRectMake(0, 0, _size.width, _size.height);
    CGRect ret = CGRectIntersection(proposed, totalRect);
    if ([self.exclusionPaths count] == 0L || ret.size.width <= 0) {
        return ret;
    }

    CGFloat padding = self.lineFragmentPadding;
    if (padding <= 0.0) {
        // If padding is invalid we will go into an infinite loop, use a default
        padding = c_defaultPadding;
    }

    std::vector<CGRect> exclusionRectsForHorizontal{};
    for (size_t i = 0; i < _exclusionPathBoundingRects.size(); ++i) {
        CGRect boundingRect = _exclusionPathBoundingRects[i];
        // If our proposed area doesn't intersect the bounding box of the exclusion zone at all, no need to compare against it
        if (CGRectIntersectsRect(proposed, boundingRect)) {
            // Get maximum outer points to minimize stepping
            CGRect lineIntersection = CGRectMake(boundingRect.origin.x, proposed.origin.y, boundingRect.size.width, proposed.size.height);
            // TODO 1394: Remove and replace with CGPath
            CGContextRef exclusionContext = _exclusionContexts[i].get();

            // TODO 1394: Convert to CGPathContainsPoint for CGD2D
            // Find the leftmost and rightmost points of the exclusion zone intersecting the same horizontal region as the proposed rect
            lineIntersection.origin.x = __GetXPositionIntersectingZone(lineIntersection, exclusionContext, padding, _size.width);
            CGFloat rightmostPosition = __GetXPositionIntersectingZone(CGRectMake(lineIntersection.origin.x + lineIntersection.size.width,
                                                                                  lineIntersection.origin.y,
                                                                                  lineIntersection.size.width,
                                                                                  lineIntersection.size.height),
                                                                       exclusionContext,
                                                                       -padding,
                                                                       _size.width);
            lineIntersection.size.width = rightmostPosition - lineIntersection.origin.x;
            exclusionRectsForHorizontal.emplace_back(lineIntersection);
        }
    }

    // Remove any exclusion zones not intersecting horizontal with proposed rect
    std::remove_if(exclusionRectsForHorizontal.begin(), exclusionRectsForHorizontal.end(), [](CGRect rect) {
        return rect.size.width <= 0;
    });

    if (exclusionRectsForHorizontal.empty()) {
        return ret;
    }

    // Sort by X origin to prevent skipping possible areas not covered by an exclusion zone
    std::sort(exclusionRectsForHorizontal.begin(), exclusionRectsForHorizontal.end(), [](CGRect a, CGRect b) {
        return a.origin.x < b.origin.x;
    });
    ret = __FirstPossibleRectForProposed(ret, exclusionRectsForHorizontal, padding, _size.width);

    if (remainingRect) {
        // Should be padding to the right of whatever stopped the first rect, which is padding past the end of it
        CGFloat newXPosition = ret.origin.x + ret.size.width + 2 * padding;
        if (newXPosition < _size.width) {
            *remainingRect =
                __FirstPossibleRectForProposed(CGRectMake(newXPosition, ret.origin.y, _size.width - newXPosition, ret.size.height),
                                               exclusionRectsForHorizontal,
                                               padding,
                                               _size.width);
        }
    }

    return ret;
}

@end
