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

// Useful odds and ends that are generic enough to be reused:

#ifndef _UTILS_ETC_H_
#define _UTILS_ETC_H_

#include <assert.h>
#define _USE_MATH_DEFINES
#include <math.h>

static bool powerOfTwo(int x) {
    return (x & (x - 1)) == 0;
}

static int log2Ceil(int x) {
    assert(x > 0);

    bool pow2 = powerOfTwo(x);

    int lg = 0;
    while (x != 0) {
        ++lg;
        x >>= 1;
    }
    return pow2 ? lg - 1 : lg;
}

static inline float cubed(float value) {
    return value * value * value;
}

static inline double cubed(double value) {
    return value * value * value;
}

static inline float squared(float value) {
    return value * value;
}

static inline double squared(double value) {
    return value * value;
}

template <typename Type>
Type abs(const Type& val) {
    return (val > 0) ? val : -val;
}

#ifndef max
template <typename Type>
Type max(const Type& a, const Type& b) {
    return (a > b) ? a : b;
}
#endif

#ifndef min
template <typename Type>
Type min(const Type& a, const Type& b) {
    return (a < b) ? a : b;
}
#endif

template <typename Type>
static bool numEqual(Type a, Type b, Type epsilon = 0.01) {
    return abs(a - b) < epsilon;
}

template <typename Type>
static bool clamp(Type& val, Type min, Type max) {
    bool ret = false;
    assert(min <= max);
    if (val < min) {
        val = min;
        ret = true;
    }
    if (val > max) {
        val = max;
        ret = true;
    }

    return ret;
}

inline float DEG2RAD(float deg) {
    return ((deg * ((float)M_PI)) / 180.f);
}
inline float RAD2DEG(float rad) {
    return ((rad * 180.f) / ((float)M_PI));
}

#endif // _UTILS_ETC_H_
