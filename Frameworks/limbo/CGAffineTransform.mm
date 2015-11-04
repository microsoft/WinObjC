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
#include <math.h>

const CGAffineTransform CGAffineTransformIdentity = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformConcat(CGAffineTransform t2, CGAffineTransform t1) {
    CGAffineTransform ret;

    ret.a = t2.a * t1.a + t2.b * t1.c;
    ret.b = t2.a * t1.b + t2.b * t1.d;
    ret.c = t2.c * t1.a + t2.d * t1.c;
    ret.d = t2.c * t1.b + t2.d * t1.d;
    ret.tx = t2.tx * t1.a + t2.ty * t1.c + t1.tx;
    ret.ty = t2.tx * t1.b + t2.ty * t1.d + t1.ty;

    return ret;
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformMake(float a, float b, float c, float d, float tx, float ty) {
    CGAffineTransform ret;

    ret.a = a;
    ret.b = b;
    ret.c = c;
    ret.d = d;
    ret.tx = tx;
    ret.ty = ty;

    return ret;
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformMakeTranslation(float tx, float ty) {
    CGAffineTransform ret;

    ret.a = 1.0f;
    ret.b = 0.0f;
    ret.c = 0.0f;
    ret.d = 1.0f;
    ret.tx = tx;
    ret.ty = ty;

    return ret;
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformMakeScale(float sx, float sy) {
    CGAffineTransform ret;
    ret.a = sx;
    ret.b = 0.0f;
    ret.c = 0.0f;
    ret.d = sy;
    ret.tx = 0.0f;
    ret.ty = 0.0f;

    return ret;
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformMakeRotation(float angle) {
    CGAffineTransform ret;

    if (IS_NEAR(angle, ((float)kPi / 2.0f), 0.0001f)) {
        ret.a = 0;
        ret.b = 1.0f;
        ret.c = -1.0f;
        ret.d = 0.0f;
        ret.tx = 0.0f;
        ret.ty = 0.0f;

        return ret;
    }
    ret.a = cosf(angle);
    ret.b = sinf(angle);
    ret.c = -ret.b;
    ret.d = ret.a;
    ret.tx = 0.0f;
    ret.ty = 0.0f;

    return ret;
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformRotate(CGAffineTransform curTransform, float angle) {
    CGAffineTransform ret;

    ret = CGAffineTransformMakeRotation(angle);
    ret = CGAffineTransformConcat(ret, curTransform);

    return ret;
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformTranslate(CGAffineTransform curTransform, float x, float y) {
    CGAffineTransform trans;

    trans = CGAffineTransformMakeTranslation(x, y);
    trans = CGAffineTransformConcat(trans, curTransform);

    return trans;
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformScale(CGAffineTransform curTransform, float x, float y) {
    CGAffineTransform scale;

    scale = CGAffineTransformMakeScale(x, y);
    return CGAffineTransformConcat(scale, curTransform);
}

/**
 @Status Interoperable
*/
CGAffineTransform CGAffineTransformInvert(CGAffineTransform curTransform) {
    float determinant = (curTransform.a * curTransform.d - curTransform.c * curTransform.b);

    if (determinant == 0) {
        return curTransform;
    }

    CGAffineTransform ret;
    ret.a = curTransform.d / determinant;
    ret.b = -curTransform.b / determinant;
    ret.c = -curTransform.c / determinant;
    ret.d = curTransform.a / determinant;
    ret.tx = (-curTransform.d * curTransform.tx + curTransform.c * curTransform.ty) / determinant;
    ret.ty = (curTransform.b * curTransform.tx - curTransform.a * curTransform.ty) / determinant;

    return ret;
}

/**
 @Status Interoperable
*/
bool CGAffineTransformIsIdentity(CGAffineTransform curTransform) {
    if (memcmp(&curTransform, &CGAffineTransformIdentity, sizeof(curTransform)) == 0) {
        return true;
    } else {
        return false;
    }
}

/**
 @Status Interoperable
*/
bool CGAffineTransformEqualToTransform(CGAffineTransform t2, CGAffineTransform t1) {
    if (memcmp(&t1, &t2, sizeof(CGAffineTransform)) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }

    return 0;
}
