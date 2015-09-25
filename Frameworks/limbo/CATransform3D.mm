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
#include <algorithm>

void CATransform3D::MakeTranslation(float tx, float ty, float tz) {
    memset(this, 0, sizeof(CATransform3D));

    m11 = 1.0f;
    m22 = 1.0f;
    m33 = 1.0f;
    m44 = 1.0f;
    m41 = tx;
    m42 = ty;
    m43 = tz;
}

void CATransform3D::MakeIdentity() {
    memset(this, 0, sizeof(CATransform3D));

    m11 = 1.0f;
    m22 = 1.0f;
    m33 = 1.0f;
    m44 = 1.0f;
}

void CATransform3D::Translate(float tx, float ty, float tz) {
    m41 += tx;
    m42 += ty;
    m43 += tz;
}

void CATransform3D::MakeRotation(float angle, float x, float y, float z) {
    memset(this, 0, sizeof(CATransform3D));

    m11 = 1.0f + (1 - cosf(angle)) * (x * x - 1);
    m21 = -z * sinf(angle) + (1.0f - cosf(angle)) * x * y;
    m31 = y * sinf(angle) + (1.0f - cosf(angle)) * x * z;
    m12 = z * sinf(angle) + (1.0f - cosf(angle)) * x * y;
    m22 = 1.0f + (1.0f - cos(angle)) * (y * y - 1.0f);
    m32 = -x * sinf(angle) + (1.0f - cosf(angle)) * y * z;
    m13 = -y * sinf(angle) + (1.0f - cosf(angle)) * x * z;
    m23 = x * sinf(angle) + (1.0f - cos(angle)) * y * z;
    m33 = 1.0f + (1.0f - cosf(angle)) * (z * z - 1.0f);
    m44 = 1.0f;
}

void CATransform3D::MakeScale(float x, float y, float z) {
    memset(this, 0, sizeof(CATransform3D));

    m11 = x;
    m22 = y;
    m33 = z;
    m44 = 1.0f;
}

void CATransform3D::MakeOrtho(float left, float right, float bottom, float top, float near, float far) {
    m11 = 2.f / (right - left);
    m21 = 0.f;
    m31 = 0.f;
    m41 = -((right + left) / (right - left));
    m12 = 0.f;
    m22 = 2.f / (top - bottom);
    m32 = 0.f;
    m42 = -((top + bottom) / (top - bottom));
    m13 = 0.f;
    m23 = 0.f;
    // m33 = -2.f / (far - near);
    // m43 = -((far + near) / (far - near));
    m33 = 1.f;
    m43 = 0.f;
    //
    m14 = 0.f;
    m24 = 0.f;
    m34 = 0.f;
    m44 = 1.f;
}

CATransform3D
CATransform3DMakeOrtho(CGFloat left, CGFloat right, CGFloat bottom, CGFloat top, CGFloat near, CGFloat far) {
    CATransform3D ret;

    ret.MakeOrtho(left, right, bottom, top, near, far);

    return ret;
}

void CATransform3D::MultByTranslation(float tx, float ty, float tz) {
    CATransform3D other;
    other.MakeTranslation(tx, ty, tz);
    RMultiplyBy(&other);
}

void CATransform3D::MultByRotation(float angle, float x, float y, float z) {
    CATransform3D other;
    other.MakeRotation(angle, x, y, z);
    RMultiplyBy(&other);
}

void CATransform3D::MultByScale(float x, float y, float z) {
    CATransform3D other;
    other.MakeScale(x, y, z);
    RMultiplyBy(&other);
}

void CATransform3D::MultByOrtho(float left, float right, float bottom, float top, float near, float far) {
    CATransform3D other;
    other.MakeOrtho(left, right, bottom, top, near, far);
    RMultiplyBy(&other);
}

void CATransform3D::GetScale(float* scale) {
    int i;

    for (i = 0; i < 3; i++) {
        scale[i] = sqrt(m[0][i] * m[0][i] + m[1][i] * m[1][i] + m[2][i] * m[2][i]);
    }
}

void CATransform3D::GetPosition(float* position) {
    position[0] = m[3][0];
    position[1] = m[3][1];
    position[2] = m[3][2];
}

void CATransform3D::MultiplyBy(CATransform3D* matrix) {
    float mOut[4][4];
    int i, j, k;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            for (k = 0, mOut[i][j] = 0; k < 4; k++)
                mOut[i][j] += m[i][k] * matrix->m[k][j];

    memcpy(m, mOut, sizeof(mOut));
}

const CATransform3D CATransform3DIdentity = { 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                                              0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f };

bool CATransform3DIsIdentity(CATransform3D curTransform) {
    if (memcmp(&curTransform, &CATransform3DIdentity, sizeof(curTransform)) == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

void CATransform3D::RMultiplyBy(CATransform3D* matrix) {
#if 0
#define A(row, col) (((float*)&m[0][0])[4 * col + row])
#define B(row, col) (((float*)&matrix->m[0][0])[4 * col + row])
#define P(row, col) (((float*)&m[0][0])[4 * col + row])

if ( memcmp(&matrix->m[0], &_identity.m[0], sizeof(float) * 4) == 0 &&
memcmp(&matrix->m[1], &_identity.m[1], sizeof(float) * 4) == 0 &&
memcmp(&matrix->m[2], &_identity.m[2], sizeof(float) * 4) == 0 &&
matrix->m44                                               == 1.0f ) {
if ( matrix->m41 == 0.0f && matrix->m42 == 0.0f && matrix->m43 == 0.0f ) {
//  Identity
return;
}
m41 += m11 * matrix->m41 + m21 * matrix->m42 + m31 * matrix->m43;
m42 += m12 * matrix->m41 + m22 * matrix->m42 + m32 * matrix->m43;
m43 += m13 * matrix->m41 + m23 * matrix->m42 + m33 * matrix->m43;
m44 += m14 * matrix->m41 + m24 * matrix->m42 + m34 * matrix->m43;
return;
}

#define A(row, col) (((float*)&m[0][0])[4 * col + row])
#define B(row, col) (((float*)&matrix->m[0][0])[4 * col + row])
#define P(row, col) (((float*)&m[0][0])[4 * col + row])

int i;

for (i=0; i<4; i++) {
const float ai0=A(i,0),  ai1=A(i,1),  ai2=A(i,2),  ai3=A(i,3);
P(i,0) = ai0 * B(0,0) + ai1 * B(1,0) + ai2 * B(2,0) + ai3 * B(3,0);
P(i,1) = ai0 * B(0,1) + ai1 * B(1,1) + ai2 * B(2,1) + ai3 * B(3,1);
P(i,2) = ai0 * B(0,2) + ai1 * B(1,2) + ai2 * B(2,2) + ai3 * B(3,2);
P(i,3) = ai0 * B(0,3) + ai1 * B(1,3) + ai2 * B(2,3) + ai3 * B(3,3);
}
#else
    float mOut[4][4];
    int i, j, k;

    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            for (k = 0, mOut[i][j] = 0; k < 4; k++)
                mOut[i][j] += matrix->m[i][k] * m[k][j];

    memcpy(m, mOut, sizeof(mOut));
#endif
}

void CATransform3D::TransformPoints(struct CAPoint3D* points, int count) {
    while (count--) {
        float inX = points->x;
        float inY = points->y;
        float inZ = points->z;

        points->x = m11 * inX + m21 * inY + m31 * inZ + m41;
        points->y = m12 * inX + m22 * inY + m32 * inZ + m42;
        points->z = m13 * inX + m23 * inY + m33 * inZ + m43;

        points++;
    }
}

void CATransform3D::TransformPoints2D(struct CGPoint* points, int count) {
    for (int i = 0; i < count; i++) {
        CGPoint outPt;
        float* out = &((float&)outPt.x);
        float* m = &((float&)this->m[0][0]);
        float* in = &((float&)points[i].x);
        out[0] = m[0] * in[0] + m[4] * in[1] + +m[12];
        out[1] = m[1] * in[0] + m[5] * in[1] + +m[13];
        points[i] = outPt;
    }
}

DEFINE_FUNCTION_STRET_3(CATransform3D, CATransform3DMakeScale, float, x, float, y, float, z) {
    CATransform3D ret;

    ret.MakeScale(x, y, z);

    return ret;
}

DEFINE_FUNCTION_STRET_4(CATransform3D, CATransform3DScale, CATransform3D, cur, float, x, float, y, float, z) {
    CATransform3D rot;

    rot.MakeScale(x, y, z);
    rot.MultiplyBy(&cur);

    return rot;
}

DEFINE_FUNCTION_STRET_5(
    CATransform3D, CATransform3DRotate, CATransform3D, cur, float, angle, float, x, float, y, float, z) {
    CATransform3D rot;

    rot.MakeRotation(angle, -x, -y, -z);
    (*((CATransform3D*)&cur)).MultiplyBy(&rot);

    return cur;
}

DEFINE_FUNCTION_STRET_4(CATransform3D, CATransform3DMakeRotation, float, angle, float, x, float, y, float, z) {
    CATransform3D ret;

    ret.MakeRotation(angle, x, y, z);

    return ret;
}

DEFINE_FUNCTION_STRET_3(CATransform3D, CATransform3DMakeTranslation, float, x, float, y, float, z) {
    CATransform3D ret;

    ret.MakeTranslation(x, y, z);

    return ret;
}

DEFINE_FUNCTION_STRET_4(CATransform3D, CATransform3DTranslate, CATransform3D, cur, float, x, float, y, float, z) {
    CATransform3D rot;

    rot.MakeTranslation(x, y, z);
    rot.MultiplyBy(&cur);

    return rot;
}

DEFINE_FUNCTION_STRET_2(CATransform3D, CATransform3DConcat, CATransform3D, a, CATransform3D, b) {
    (*((CATransform3D*)&a)).MultiplyBy(&b);

    return a;
}

void CATransform3DTransformPoints(CATransform3D a, CAPoint3D* points, int count) {
    (*((CATransform3D*)&a)).TransformPoints(points, count);
}

void CATransform3DGetScale(CATransform3D a, float* scale) {
    (*((CATransform3D*)&a)).GetScale(scale);
}

void CATransform3DGetPosition(CATransform3D a, float* position) {
    (*((CATransform3D*)&a)).GetPosition(position);
}
