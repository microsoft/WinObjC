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

#pragma once

#import <CoreFoundation/CoreFoundation.h>

#ifdef __LP64__
typedef double CGFloat;
#define CGFLOAT_MIN DBL_MIN
#define CGFLOAT_MAX DBL_MAX
#else
typedef float CGFloat;
#define CGFLOAT_MIN FLT_MIN
#define CGFLOAT_MAX FLT_MAX
#endif

#ifdef __cplusplus
struct CGPoint {
    CGFloat x, y;

    CGPoint operator+(const CGPoint& v) const {
        CGPoint ret = { x + v.x, y + v.y };
        return ret;
    }

    CGPoint operator-() const {
        CGPoint ret = { -x, -y };
        return ret;
    }

    CGPoint operator-(const CGPoint& v) const {
        CGPoint ret = { x - v.x, y - v.y };
        return ret;
    }

    CGPoint operator-=(const CGPoint& v) {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    CGPoint operator+=(const CGPoint& v) {
        x += v.x;
        y += v.y;
        return *this;
    }

    bool operator==(const CGPoint& v) {
        return x == v.x && y == v.y;
    }

    bool operator!=(const CGPoint& v) {
        return x != v.x || y != v.y;
    }

    CGPoint operator*(float scalar) const {
        CGPoint ret = { x * scalar, y * scalar };
        return ret;
    }

    CGPoint operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    CGPoint operator/(float scalar) const {
        CGPoint ret = { x / scalar, y / scalar };
        return ret;
    }

    CGPoint operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    CGFloat distSq(const CGPoint& v) const {
        CGPoint delta = *this - v;
        return delta.dot(delta);
    }

    CGFloat dist(const CGPoint& v) const {
        return sqrt(distSq(v));
    }

    bool distGr(const CGPoint& v, CGFloat dist) const {
        return distSq(v) > dist * dist;
    }

    CGFloat lenSq() const {
        return dot(*this);
    }

    CGFloat len() const {
        return sqrt(lenSq());
    }

    bool lenGe(float len) {
        return lenSq() >= len * len;
    }

    bool lenLe(float len) {
        return lenSq() < len * len;
    }

    CGFloat dot(const CGPoint& v) const {
        return v.x * x + v.y * y;
    }

    CGPoint normalized() const {
        float l = len();

        if (l != 0) {
            CGPoint ret = { x / l, y / l };
            return ret;
        } else {
            CGPoint ret = { 0, 0 };
            return ret;
        }
    }

    static inline CGPoint point(float x, float y) {
        CGPoint ret;

        ret.x = x;
        ret.y = y;

        return ret;
    }
};
#else
typedef struct CGPoint {
    CGFloat x;
    CGFloat y;
} CGPoint;
#endif

typedef struct CGSize {
    CGFloat width;
    CGFloat height;
} CGSize;

typedef struct CGRect {
    CGPoint origin;
    CGSize size;
} CGRect;
