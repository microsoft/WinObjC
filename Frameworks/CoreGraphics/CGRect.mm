//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Starboard.h>

#import <CoreGraphics/CGAffineTransform.h>

#import <limits>
#import "Etc.h"

#import <CoreGraphics/CGAffineTransform.h>

/**
 @Status Interoperable
*/
CGPoint CGPointApplyAffineTransform(CGPoint pt, CGAffineTransform t) {
    CGPoint ret;

    ret.x = (CGFloat)((double)t.a * pt.x + (double)t.c * pt.y + t.tx);
    ret.y = (CGFloat)((double)t.b * pt.x + (double)t.d * pt.y + t.ty);

    return ret;
}

/**
 @Status Interoperable
*/
CGRect CGRectApplyAffineTransform(CGRect rect, CGAffineTransform curTransform) {
    CGPoint pts[4];

    pts[0].x = rect.origin.x;
    pts[0].y = rect.origin.y;
    pts[1].x = rect.origin.x + rect.size.width;
    pts[1].y = rect.origin.y;
    pts[2].x = rect.origin.x + rect.size.width;
    pts[2].y = rect.origin.y + rect.size.height;
    pts[3].x = rect.origin.x;
    pts[3].y = rect.origin.y + rect.size.height;

    pts[0] = CGPointApplyAffineTransform(pts[0], curTransform);
    pts[1] = CGPointApplyAffineTransform(pts[1], curTransform);
    pts[2] = CGPointApplyAffineTransform(pts[2], curTransform);
    pts[3] = CGPointApplyAffineTransform(pts[3], curTransform);

    bool haveMinX = false, haveMaxX = false;
    bool haveMinY = false, haveMaxY = false;

    float minX = 0, maxX = 0, minY = 0, maxY = 0;

    for (int i = 0; i < 4; i++) {
        if (!haveMinX || pts[i].x < minX) {
            haveMinX = true;
            minX = pts[i].x;
        }
        if (!haveMaxX || pts[i].x > maxX) {
            haveMaxX = true;
            maxX = pts[i].x;
        }
        if (!haveMinY || pts[i].y < minY) {
            haveMinY = true;
            minY = pts[i].y;
        }
        if (!haveMaxY || pts[i].y > maxY) {
            haveMaxY = true;
            maxY = pts[i].y;
        }
    }

    CGRect ret;

    ret.origin.x = minX;
    ret.origin.y = minY;
    ret.size.width = maxX - minX;
    ret.size.height = maxY - minY;

    return ret;
}
