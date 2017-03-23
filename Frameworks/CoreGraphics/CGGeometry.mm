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

#import <StubReturn.h>
#import <Starboard.h>
#import <CoreGraphics/CGGeometry.h>
#import <LoggingNative.h>
#import <limits>
#import <algorithm>

#import "Etc.h"

static const wchar_t* TAG = L"CGGeometry";

const CGRect CGRectInfinite = CGRectMake(std::numeric_limits<float>::infinity(),
                                         std::numeric_limits<float>::infinity(),
                                         std::numeric_limits<float>::infinity(),
                                         std::numeric_limits<float>::infinity());
const CGPoint CGPointZero = CGPointMake(0, 0);
const CGRect CGRectZero = CGRectMake(0, 0, 0, 0);
const CGSize CGSizeZero = CGSizeMake(0, 0);
const CGRect CGRectNull = CGRectMake(std::numeric_limits<float>::infinity(), std::numeric_limits<float>::infinity(), 0.0f, 0.0f);

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CGPointCreateDictionaryRepresentation(CGPoint point) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CGSizeCreateDictionaryRepresentation(CGSize size) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFDictionaryRef CGRectCreateDictionaryRepresentation(CGRect) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPointMakeWithDictionaryRepresentation(CFDictionaryRef dict, CGPoint* point) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGSizeMakeWithDictionaryRepresentation(CFDictionaryRef dict, CGSize* size) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGRectMakeWithDictionaryRepresentation(CFDictionaryRef dict, CGRect* rect) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
void CGRectDivide(CGRect rect, CGRect* slice, CGRect* remainder, CGFloat amount, CGRectEdge edge) {
    RETURN_IF(slice == nullptr);
    RETURN_IF(remainder == nullptr);

    if (CGRectIsNull(rect)) {
        *slice = CGRectNull;
        *remainder = CGRectNull;
        return;
    }

    amount = std::max(0.0f, amount);
    rect = CGRectStandardize(rect);

    /*
    * (0,0)                      (width,0)
    * x-----------------------------x
    * |                             |
    * |                             |
    * |                             |
    * |                             |
    * |                             |
    * x-----------------------------x
    * (0,height)               (width,height)
    *
    *
    * The division is based on CGRectEdge, which edge to divide.
    * e.g CGRectMinYEdge
    *
    *   (0,0)                      (width,0)
    *    x-----------------------------x
    *    | slice            | (amount) |
    *    |                  v          |
    * (0,amount)------------------(width,amount)
    *    | reminder                    |
    *    |                             |
    *    x-----------------------------x
    *   0,height-amount)               (width,height-amount)
    */

    // Set both to rect, then update the sizes.
    *slice = rect;
    *remainder = rect;

    switch (edge) {
        case CGRectMinYEdge:
            amount = (amount > rect.size.height) ? rect.size.height : amount;
            remainder->origin.y += amount;
            if (amount >= rect.size.height) {
                remainder->size.height = 0;
            } else {
                slice->size.height = amount;
                remainder->size.height -= amount;
            }
            break;
        case CGRectMaxYEdge:
            if (amount >= rect.size.height) {
                remainder->size.height = 0;
            } else {
                slice->origin.y += (rect.size.height - amount);
                slice->size.height = amount;
                remainder->size.height -= amount;
            }
            break;
        case CGRectMinXEdge:
            amount = (amount > rect.size.width) ? rect.size.width : amount;
            remainder->origin.x += amount;
            if (amount >= rect.size.width) {
                remainder->size.width = 0;
            } else {
                slice->size.width = amount;
                remainder->size.width -= amount;
            }
            break;
        case CGRectMaxXEdge:
            if (amount >= rect.size.width) {
                remainder->size.width = 0;
            } else {
                remainder->size.width -= amount;
                slice->origin.x += rect.size.width - amount;
                slice->size.width = amount;
            }
            break;
        default:
            TraceError(TAG, L"Invalid CGRectEdge.");
            break;
    }
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
CGRect CGRectStandardize(CGRect r) {
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
CGRect CGRectUnion(CGRect r1, CGRect r2) {
    if (CGRectIsInfinite(r1)) {
        return r2;
    }
    if (CGRectIsInfinite(r2)) {
        return r1;
    }

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
