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

#include "Starboard.h"
#include "Etc.h"

#include <limits>

//  INCORRECT
const CGRect CGRectNull = { std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), 0.0f, 0.0f };

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

/**
 @Status Interoperable
*/
extern "C" CGRect CGRectStandardize(CGRect r) {
    CGRect out;

    if (r.size.width < 0.0f) {
        out.origin.x = r.origin.x + r.size.width;
        out.size.width = -r.size.width;
    } else {
        out.origin.x = r.origin.x;
        out.size.width = r.size.width;
    }

    if (r.size.height < 0.0f) {
        out.origin.y = r.origin.y + r.size.height;
        out.size.height = -r.size.height;
    } else {
        out.origin.y = r.origin.y;
        out.size.height = r.size.height;
    }
    return out;
}

/**
 @Status Interoperable
*/
CGRect CGRectIntersection(CGRect r1, CGRect r2) {
    r1 = CGRectStandardize(r1);
    r2 = CGRectStandardize(r2);

    float x1, y1, x2, y2;
    bool isNull = false;

    if (r1.origin.x < r2.origin.x) {
        if (r1.origin.x + r1.size.width < r2.origin.x) {
            isNull = true;
        } else {
            x1 = min(r1.origin.x + r1.size.width, r2.origin.x);
            x2 = min(r1.origin.x + r1.size.width, r2.origin.x + r2.size.width);
        }
    } else {
        if (r2.origin.x + r2.size.width < r1.origin.x) {
            isNull = true;
        } else {
            x1 = min(r2.origin.x + r2.size.width, r1.origin.x);
            x2 = min(r2.origin.x + r2.size.width, r1.origin.x + r1.size.width);
        }
    }

    if (r1.origin.y < r2.origin.y) {
        if (r1.origin.y + r1.size.height < r2.origin.y) {
            isNull = true;
        } else {
            y1 = min(r1.origin.y + r1.size.height, r2.origin.y);
            y2 = min(r1.origin.y + r1.size.height, r2.origin.y + r2.size.height);
        }
    } else {
        if (r2.origin.y + r2.size.height < r1.origin.y) {
            isNull = true;
        } else {
            y1 = min(r2.origin.y + r2.size.height, r1.origin.y);
            y2 = min(r2.origin.y + r2.size.height, r1.origin.y + r1.size.height);
        }
    }

    CGRect out;

    if (isNull == true) {
        memcpy(&out, &CGRectNull, sizeof(CGRect));
    } else {
        out.origin.x = x1;
        out.origin.y = y1;
        out.size.width = x2 - x1;
        out.size.height = y2 - y1;
    }

    return out;
}

/**
 @Status Interoperable
*/
CGRect CGRectIntegral(CGRect r) {
    r = CGRectStandardize(r);

    r.size.width = ceilf(r.origin.x + r.size.width);
    r.size.height = ceilf(r.origin.y + r.size.height);
    r.origin.x = floorf(r.origin.x);
    r.origin.y = floorf(r.origin.y);
    r.size.width -= r.origin.x;
    r.size.height -= r.origin.y;

    return r;
}

/**
 @Status Interoperable
*/
CGRect CGRectUnion(CGRect r1, CGRect r2) {
    r1 = CGRectStandardize(r1);
    r2 = CGRectStandardize(r2);

    float x1, y1, x2, y2;

    if (r1.origin.x < r2.origin.x) {
        x1 = r1.origin.x;
    } else {
        x1 = r2.origin.x;
    }
    if (r1.origin.y < r2.origin.y) {
        y1 = r1.origin.y;
    } else {
        y1 = r2.origin.y;
    }

    if (r1.origin.x + r1.size.width > r2.origin.x + r2.size.width) {
        x2 = r1.origin.x + r1.size.width;
    } else {
        x2 = r2.origin.x + r2.size.width;
    }
    if (r1.origin.y + r1.size.height > r2.origin.y + r2.size.height) {
        y2 = r1.origin.y + r1.size.height;
    } else {
        y2 = r2.origin.y + r2.size.height;
    }

    CGRect ret;
    ret.origin.x = x1;
    ret.origin.y = y1;
    ret.size.width = x2 - x1;
    ret.size.height = y2 - y1;

    return ret;
}
