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

#pragma once

#include <math.h>
#import <Foundation/Foundation.h>
#import <GLKit/GLKitExport.h>

#define COMPARISON_EPSILON 0.0000025f
#define _GLK_MIN(a, b) ((a) < (b) ? (a) : (b))
#define _GLK_MAX(a, b) ((a) > (b) ? (a) : (b))

union _GLKVector2 {
    struct {
        float x, y;
    };
    struct {
        float s, t;
    };
    float v[2];
};
typedef union _GLKVector2 GLKVector2;

union _GLKVector3 {
    struct {
        float x, y, z;
    };
    struct {
        float s, t, p;
    };
    struct {
        float r, g, b;
    };
    float v[3];
};
typedef union _GLKVector3 GLKVector3;

union _GLKVector4 {
    struct {
        float x, y, z, w;
    };
    struct {
        float r, g, b, a;
    };
    struct {
        float s, t, p, q;
    };
    float v[4];
};
typedef union _GLKVector4 GLKVector4;

union _GLKMatrix2 {
    struct {
        float m00, m01;
        float m10, m11;
    };
    float m[4];
};
typedef union _GLKMatrix2 GLKMatrix2;

union _GLKMatrix3 {
    struct {
        float m00, m01, m02;
        float m10, m11, m12;
        float m20, m21, m22;
    };
    float m[9];
};
typedef union _GLKMatrix3 GLKMatrix3;

union _GLKMatrix4 {
    struct {
        float m00, m01, m02, m03;
        float m10, m11, m12, m13;
        float m20, m21, m22, m23;
        float m30, m31, m32, m33;
    };
    float m[16];
};
typedef union _GLKMatrix4 GLKMatrix4;

union _GLKQuaternion {
    struct {
        GLKVector3 v;
        float s;
    };
    struct {
        float x, y, z, w;
    };
    float q[4];
};
typedef union _GLKQuaternion GLKQuaternion;

GLKIT_EXPORT const GLKMatrix3 GLKMatrix3Identity;
GLKIT_EXPORT const GLKMatrix4 GLKMatrix4Identity;
GLKIT_EXPORT const GLKQuaternion GLKQuaternionIdentity;

GLKIT_EXPORT GLKVector3 GLKMathProject(GLKVector3 object, GLKMatrix4 model, GLKMatrix4 projection, int* viewport);
GLKIT_EXPORT GLKVector3 GLKMathUnproject(GLKVector3 window, GLKMatrix4 model, GLKMatrix4 projection, int* viewport, bool* success);

// --------------------------------------------------------------------------------

/**
 @Status Interoperable
*/
inline float GLKMathDegreesToRadians(float deg) {
    return deg * M_PI / 180.f;
}

/**
 @Status Interoperable
*/
inline float GLKMathRadiansToDegrees(float rad) {
    return rad * 180.f / M_PI;
}

// --------------------------------------------------------------------------------
// Matrices

GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeIdentity();
GLKIT_EXPORT GLKMatrix3 GLKMatrix3FromMatrix4(GLKMatrix4 m);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeIdentity();
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Make(float m00,
                                       float m01,
                                       float m02,
                                       float m03,
                                       float m10,
                                       float m11,
                                       float m12,
                                       float m13,
                                       float m20,
                                       float m21,
                                       float m22,
                                       float m23,
                                       float m30,
                                       float m31,
                                       float m32,
                                       float m33);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Make(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Transpose(GLKMatrix3 mat);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Multiply(GLKMatrix3 matrixLeft, GLKMatrix3 matrixRight);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Rotate(GLKMatrix3 matrix, float radians, float x, float y, float z);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3RotateWithVector3(GLKMatrix3 matrix, float radians, GLKVector3 axisVector);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3RotateWithVector4(GLKMatrix3 matrix, float radians, GLKVector4 axisVector);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3RotateX(GLKMatrix3 matrix, float radians);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3RotateY(GLKMatrix3 matrix, float radians);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3RotateZ(GLKMatrix3 matrix, float radians);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Scale(GLKMatrix3 matrix, float sx, float sy, float sz);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3ScaleWithVector3(GLKMatrix3 matrix, GLKVector3 scaleVector);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3ScaleWithVector4(GLKMatrix3 matrix, GLKVector4 scaleVector);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Add(GLKMatrix3 matrixLeft, GLKMatrix3 matrixRight);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Subtract(GLKMatrix3 matrixLeft, GLKMatrix3 matrixRight);
GLKIT_EXPORT GLKVector3 GLKMatrix3MultiplyVector3(GLKMatrix3 matrixLeft, GLKVector3 vectorRight);
GLKIT_EXPORT void GLKMatrix3MultiplyVector3Array(GLKMatrix3 matrix, GLKVector3* vectors, size_t vectorCount);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Transpose(GLKMatrix4 mat);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4InvertAndTranspose(GLKMatrix4 matrix, bool* isInvertible);
GLKIT_EXPORT GLKMatrix3
GLKMatrix3MakeAndTranspose(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeAndTranspose(float m00,
                                                   float m01,
                                                   float m02,
                                                   float m03,
                                                   float m10,
                                                   float m11,
                                                   float m12,
                                                   float m13,
                                                   float m20,
                                                   float m21,
                                                   float m22,
                                                   float m23,
                                                   float m30,
                                                   float m31,
                                                   float m32,
                                                   float m33);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithArray(float* values);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithArrayAndTranspose(float* values);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithColumns(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithRows(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithQuaternion(GLKQuaternion quaternion);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeOrthonormalXform(GLKVector3 right, GLKVector3 up, GLKVector3 forward, GLKVector3 pos);

GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithArray(float* values);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithArrayAndTranspose(float* values);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithColumns(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithRows(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithQuaternion(GLKQuaternion quaternion);

GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeScale(float sx, float sy, float sz);

GLKIT_EXPORT GLKMatrix2 GLKMatrix3GetMatrix2(GLKMatrix3 matrix);
GLKIT_EXPORT GLKVector3 GLKMatrix3GetColumn(GLKMatrix3 matrix, int column);
GLKIT_EXPORT GLKVector3 GLKMatrix3GetRow(GLKMatrix3 matrix, int row);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3SetColumn(GLKMatrix3 matrix, int column, GLKVector3 vector);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3SetRow(GLKMatrix3 matrix, int row, GLKVector3 vector);

GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeRotation(float rad, float x, float y, float z);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeXRotation(float rad);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeYRotation(float rad);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeZRotation(float rad);

GLKIT_EXPORT GLKMatrix2 GLKMatrix4GetMatrix2(GLKMatrix4 m);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Invert(GLKMatrix3 m, bool* isInvertible);
GLKIT_EXPORT GLKMatrix3 GLKMatrix3InvertAndTranspose(GLKMatrix3 m, bool* isInvertible);
GLKIT_EXPORT GLKMatrix3 GLKMatrix4GetMatrix3(GLKMatrix4 m);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4SetColumn(GLKMatrix4 matrix, int column, GLKVector4 vector);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4SetRow(GLKMatrix4 matrix, int row, GLKVector4 vector);
GLKIT_EXPORT GLKVector4 GLKMatrix4GetColumn(GLKMatrix4 matrix, int column);
GLKIT_EXPORT GLKVector4 GLKMatrix4GetRow(GLKMatrix4 matrix, int row);

GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeRotation(float rad, float x, float y, float z);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeXRotation(float rad);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeYRotation(float rad);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeZRotation(float rad);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeTranslation(float x, float y, float z);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeScale(float x, float y, float z);

GLKIT_EXPORT GLKMatrix4
GLKMatrix4MakeLookAt(float eyeX, float eyeY, float eyeZ, float lookX, float lookY, float lookZ, float upX, float upY, float upZ);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeOrtho(float left, float right, float bot, float top, float near, float far);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakePerspective(float yrad, float aspect, float near, float far);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeFrustum(float left, float right, float bottom, float top, float near, float far);

GLKIT_EXPORT GLKMatrix4 GLKMatrix4Multiply(GLKMatrix4 m1, GLKMatrix4 m2);

GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateWithVector3(GLKMatrix4 matrix, float radians, GLKVector3 axisVector);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateWithVector4(GLKMatrix4 matrix, float radians, GLKVector4 axisVector);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Rotate(GLKMatrix4 m, float rad, float x, float y, float z);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateX(GLKMatrix4 m, float rad);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateY(GLKMatrix4 m, float rad);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateZ(GLKMatrix4 m, float rad);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Translate(GLKMatrix4 m, float x, float y, float z);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4TranslateWithVector3(GLKMatrix4 matrix, GLKVector3 translationVector);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4TranslateWithVector4(GLKMatrix4 matrix, GLKVector4 translationVector);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Scale(GLKMatrix4 m, float x, float y, float z);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4ScaleWithVector3(GLKMatrix4 matrix, GLKVector3 scaleVector);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4ScaleWithVector4(GLKMatrix4 matrix, GLKVector4 scaleVector);

GLKIT_EXPORT GLKMatrix4 GLKMatrix4Add(GLKMatrix4 matrixLeft, GLKMatrix4 matrixRight);
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Subtract(GLKMatrix4 matrixLeft, GLKMatrix4 matrixRight);

GLKIT_EXPORT GLKVector3 GLKMatrix4MultiplyVector3(GLKMatrix4 m, GLKVector3 vec);
GLKIT_EXPORT GLKVector4 GLKMatrix4MultiplyVector4(GLKMatrix4 m, GLKVector4 vec);
GLKIT_EXPORT void GLKMatrix4MultiplyVector3Array(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs);
GLKIT_EXPORT void GLKMatrix4MultiplyVector4Array(GLKMatrix4 m, GLKVector4* vecs, size_t numVecs);
GLKIT_EXPORT GLKVector3 GLKMatrix4MultiplyVector3WithTranslation(GLKMatrix4 m, GLKVector3 vec);
GLKIT_EXPORT void GLKMatrix4MultiplyVector3ArrayWithTranslation(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs);
GLKIT_EXPORT GLKVector3 GLKMatrix4MultiplyAndProjectVector3(GLKMatrix4 matrixLeft, GLKVector3 vectorRight);
GLKIT_EXPORT void GLKMatrix4MultiplyAndProjectVector3Array(GLKMatrix4 matrix, GLKVector3* vectors, size_t vectorCount);

GLKIT_EXPORT GLKMatrix4 GLKMatrix4Invert(GLKMatrix4 m, bool* isInvertible);

GLKIT_EXPORT NSString* NSStringFromGLKMatrix2(GLKMatrix2 matrix);
GLKIT_EXPORT NSString* NSStringFromGLKMatrix3(GLKMatrix3 matrix);
GLKIT_EXPORT NSString* NSStringFromGLKMatrix4(GLKMatrix4 matrix);

// --------------------------------------------------------------------------------
// Vectors.

GLKIT_EXPORT NSString* NSStringFromGLKVector2(GLKVector2 vector);
GLKIT_EXPORT NSString* NSStringFromGLKVector3(GLKVector3 vector);
GLKIT_EXPORT NSString* NSStringFromGLKVector4(GLKVector4 vector);

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Make(float x, float y, float z) {
    GLKVector3 res;

    res.x = x;
    res.y = y;
    res.z = z;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Make(float x, float y, float z, float w) {
    GLKVector4 res;

    res.x = x;
    res.y = y;
    res.z = z;
    res.w = w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4MakeFromVec3(GLKVector3 v) {
    GLKVector4 res;

    res.x = v.x;
    res.y = v.y;
    res.z = v.z;
    res.w = 0.f;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3MakeWithArray(float* values) {
    GLKVector3 res;

    res.x = values[0];
    res.y = values[1];
    res.z = values[2];

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4MakeWithArray(float* values) {
    GLKVector4 res;

    res.x = values[0];
    res.y = values[1];
    res.z = values[2];
    res.w = values[3];

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4MakeWithVector3(GLKVector3 v, float w) {
    GLKVector4 res;

    res.x = v.x;
    res.y = v.y;
    res.z = v.z;
    res.w = w;

    return res;
}

/**
 @Status Interoperable
*/
inline float GLKVector3DotProduct(GLKVector3 v1, GLKVector3 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/**
 @Status Interoperable
*/
inline float GLKVector4DotProduct(GLKVector4 v1, GLKVector4 v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

/**
 @Status Interoperable
*/
inline float GLKVector3Length(GLKVector3 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
}

/**
 @Status Interoperable
*/
inline float GLKVector4Length(GLKVector4 v) {
    return sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Normalize(GLKVector3 v) {
    float invlen = 1.f / sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    return GLKVector3Make(v.x * invlen, v.y * invlen, v.z * invlen);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Normalize(GLKVector4 v) {
    float invlen = 1.f / sqrtf(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
    return GLKVector4Make(v.x * invlen, v.y * invlen, v.z * invlen, v.w * invlen);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Add(GLKVector3 v1, GLKVector3 v2) {
    return GLKVector3Make(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Add(GLKVector4 v1, GLKVector4 v2) {
    return GLKVector4Make(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3AddScalar(GLKVector3 v1, float s) {
    return GLKVector3Make(v1.x + s, v1.y + s, v1.z + s);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4AddScalar(GLKVector4 v1, float s) {
    return GLKVector4Make(v1.x + s, v1.y + s, v1.z + s, v1.w + s);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3SubtractScalar(GLKVector3 v1, float s) {
    return GLKVector3Make(v1.x - s, v1.y - s, v1.z - s);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4SubtractScalar(GLKVector4 v1, float s) {
    return GLKVector4Make(v1.x - s, v1.y - s, v1.z - s, v1.w - s);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3MultiplyScalar(GLKVector3 v1, float s) {
    return GLKVector3Make(v1.x * s, v1.y * s, v1.z * s);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4MultiplyScalar(GLKVector4 v1, float s) {
    return GLKVector4Make(v1.x * s, v1.y * s, v1.z * s, v1.w * s);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3DivideScalar(GLKVector3 v1, float s) {
    return GLKVector3MultiplyScalar(v1, 1.f / s);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4DivideScalar(GLKVector4 v1, float s) {
    return GLKVector4MultiplyScalar(v1, 1.f / s);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Subtract(GLKVector3 v1, GLKVector3 v2) {
    return GLKVector3Make(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Subtract(GLKVector4 v1, GLKVector4 v2) {
    return GLKVector4Make(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Negate(GLKVector3 v) {
    return GLKVector3Make(-v.x, -v.y, -v.z);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Negate(GLKVector4 v) {
    return GLKVector4Make(-v.x, -v.y, -v.z, -v.w);
}

/**
 @Status Interoperable
*/
inline float GLKVector3Distance(GLKVector3 v1, GLKVector3 v2) {
    GLKVector3 v = GLKVector3Subtract(v1, v2);
    return GLKVector3Length(v);
}

/**
 @Status Interoperable
*/
inline float GLKVector4Distance(GLKVector4 v1, GLKVector4 v2) {
    GLKVector4 v = GLKVector4Subtract(v1, v2);
    return GLKVector4Length(v);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Divide(GLKVector3 v1, GLKVector3 v2) {
    return GLKVector3Make(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Divide(GLKVector4 v1, GLKVector4 v2) {
    return GLKVector4Make(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Multiply(GLKVector3 v1, GLKVector3 v2) {
    return GLKVector3Make(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Multiply(GLKVector4 v1, GLKVector4 v2) {
    return GLKVector4Make(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z, v1.w * v2.w);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4CrossProduct(GLKVector4 l, GLKVector4 r) {
    return GLKVector4Make(l.y * r.z - l.z * r.y, l.z * r.x - l.x * r.z, l.x * r.y - l.y * r.x, 0.0f);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3CrossProduct(GLKVector3 l, GLKVector3 r) {
    return GLKVector3Make(l.y * r.z - l.z * r.y, l.z * r.x - l.x * r.z, l.x * r.y - l.y * r.x);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Lerp(GLKVector4 a, GLKVector4 b, float t) {
    float it = (1.f - t);
    GLKVector4 res;

    res.x = t * b.x + it * a.x;
    res.y = t * b.y + it * a.y;
    res.z = t * b.z + it * a.z;
    res.w = t * b.w + it * a.w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Lerp(GLKVector3 a, GLKVector3 b, float t) {
    float it = (1.f - t);
    GLKVector3 res;

    res.x = t * b.x + it * a.x;
    res.y = t * b.y + it * a.y;
    res.z = t * b.z + it * a.z;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Make(float x, float y) {
    GLKVector2 res;

    res.x = x;
    res.y = y;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2MakeWithArray(float* v) {
    GLKVector2 res;

    res.x = v[0];
    res.y = v[1];

    return res;
}

/**
 @Status Interoperable
*/
inline float GLKVector2Length(GLKVector2 v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Normalize(GLKVector2 v) {
    float invdist = 1.f / sqrtf(v.x * v.x + v.y * v.y);
    return GLKVector2Make(v.x * invdist, v.y * invdist);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Add(GLKVector2 v1, GLKVector2 v2) {
    return GLKVector2Make(v1.x + v2.x, v1.y + v2.y);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Subtract(GLKVector2 v1, GLKVector2 v2) {
    return GLKVector2Make(v1.x - v2.x, v1.y - v2.y);
}

/**
 @Status Interoperable
*/
inline float GLKVector2Distance(GLKVector2 v1, GLKVector2 v2) {
    return GLKVector2Length(GLKVector2Subtract(v1, v2));
}

/**
 @Status Interoperable
*/
inline float GLKVector2DotProduct(GLKVector2 v1, GLKVector2 v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Negate(GLKVector2 v) {
    return GLKVector2Make(-v.x, -v.y);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2AddScalar(GLKVector2 v, float val) {
    return GLKVector2Make(v.x + val, v.y + val);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2SubtractScalar(GLKVector2 v, float val) {
    return GLKVector2Make(v.x - val, v.y - val);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2MultiplyScalar(GLKVector2 v, float val) {
    return GLKVector2Make(v.x * val, v.y * val);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2DivideScalar(GLKVector2 v, float val) {
    return GLKVector2MultiplyScalar(v, 1.f / val);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Multiply(GLKVector2 v1, GLKVector2 v2) {
    return GLKVector2Make(v1.x * v2.x, v1.y * v2.y);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Divide(GLKVector2 v1, GLKVector2 v2) {
    return GLKVector2Make(v1.x / v2.x, v1.y / v2.y);
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Lerp(GLKVector2 v1, GLKVector2 v2, float t) {
    float it = 1.f - t;
    GLKVector2 res;

    res.x = v1.x * it + v2.x * t;
    res.y = v1.y * it + v2.y * t;

    return res;
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector4AllEqualToScalar(GLKVector4 v, float scalar) {
    GLKVector4 o = GLKVector4SubtractScalar(v, scalar);
    if ((fabsf(o.x) + fabsf(o.y) + fabsf(o.z) + fabsf(o.w)) < (4.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector3AllEqualToScalar(GLKVector3 v, float scalar) {
    GLKVector3 o = GLKVector3SubtractScalar(v, scalar);
    if ((fabsf(o.x) + fabsf(o.y) + fabsf(o.z)) < (3.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector2AllEqualToScalar(GLKVector2 v, float scalar) {
    GLKVector2 o = GLKVector2SubtractScalar(v, scalar);
    if ((fabsf(o.x) + fabsf(o.y)) < (2.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector4AllEqualToVector4(GLKVector4 v1, GLKVector4 v2) {
    GLKVector4 o = GLKVector4Subtract(v1, v2);
    if ((fabsf(o.x) + fabsf(o.y) + fabsf(o.z) + fabsf(o.w)) < (4.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector3AllEqualToVector3(GLKVector3 v1, GLKVector3 v2) {
    GLKVector3 o = GLKVector3Subtract(v1, v2);
    if ((fabsf(o.x) + fabsf(o.y) + fabsf(o.z)) < (3.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector2AllEqualToVector2(GLKVector2 v1, GLKVector2 v2) {
    GLKVector2 o = GLKVector2Subtract(v1, v2);
    if ((fabsf(o.x) + fabsf(o.y)) < (2.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector4XYZEqualToScalar(GLKVector4 v, float scalar) {
    GLKVector4 o = GLKVector4SubtractScalar(v, scalar);
    if ((fabsf(o.x) + fabsf(o.y) + fabsf(o.z)) < (3.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Maximum(GLKVector2 a, GLKVector2 b) {
    GLKVector2 res;

    res.x = _GLK_MAX(a.x, b.x);
    res.y = _GLK_MAX(a.y, b.y);

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Minimum(GLKVector2 a, GLKVector2 b) {
    GLKVector2 res;

    res.x = _GLK_MIN(a.x, b.x);
    res.y = _GLK_MIN(a.y, b.y);

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Maximum(GLKVector3 a, GLKVector3 b) {
    GLKVector3 res;

    res.x = _GLK_MAX(a.x, b.x);
    res.y = _GLK_MAX(a.y, b.y);
    res.z = _GLK_MAX(a.z, b.z);

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Minimum(GLKVector3 a, GLKVector3 b) {
    GLKVector3 res;

    res.x = _GLK_MIN(a.x, b.x);
    res.y = _GLK_MIN(a.y, b.y);
    res.z = _GLK_MIN(a.z, b.z);

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Maximum(GLKVector4 a, GLKVector4 b) {
    GLKVector4 res;

    res.x = _GLK_MAX(a.x, b.x);
    res.y = _GLK_MAX(a.y, b.y);
    res.z = _GLK_MAX(a.z, b.z);
    res.w = _GLK_MAX(a.w, b.w);

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Minimum(GLKVector4 a, GLKVector4 b) {
    GLKVector4 res;

    res.x = _GLK_MIN(a.x, b.x);
    res.y = _GLK_MIN(a.y, b.y);
    res.z = _GLK_MIN(a.z, b.z);
    res.w = _GLK_MIN(a.w, b.w);

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector2 GLKVector2Project(GLKVector2 v, GLKVector2 proj) {
    return GLKVector2MultiplyScalar(proj, GLKVector2DotProduct(v, proj) / GLKVector2Length(proj));
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Project(GLKVector3 v, GLKVector3 proj) {
    return GLKVector3MultiplyScalar(proj, GLKVector3DotProduct(v, proj) / GLKVector3Length(proj));
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Project(GLKVector4 v, GLKVector4 proj) {
    return GLKVector4MultiplyScalar(proj, GLKVector4DotProduct(v, proj) / GLKVector4Length(proj));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector2AllGreaterThanOrEqualToScalar(GLKVector2 v, float scalar) {
    return ((v.x >= scalar) && (v.y >= scalar));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector3AllGreaterThanOrEqualToScalar(GLKVector3 v, float scalar) {
    return ((v.x >= scalar) && (v.y >= scalar) && (v.z >= scalar));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector4AllGreaterThanOrEqualToScalar(GLKVector4 v, float scalar) {
    return ((v.x >= scalar) && (v.y >= scalar) && (v.z >= scalar) && (v.w >= scalar));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector2AllGreaterThanScalar(GLKVector2 v, float scalar) {
    return ((v.x > scalar) && (v.y > scalar));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector3AllGreaterThanScalar(GLKVector3 v, float scalar) {
    return ((v.x > scalar) && (v.y > scalar) && (v.z > scalar));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector4AllGreaterThanScalar(GLKVector4 v, float scalar) {
    return ((v.x > scalar) && (v.y > scalar) && (v.z > scalar) && (v.w > scalar));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector2AllGreaterThanOrEqualToVector2(GLKVector2 v, GLKVector2 v2) {
    return ((v.x >= v2.x) && (v.y >= v2.y));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector3AllGreaterThanOrEqualToVector3(GLKVector3 v, GLKVector3 v2) {
    return ((v.x >= v2.x) && (v.y >= v2.y) && (v.z >= v2.z));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector4AllGreaterThanOrEqualToVector4(GLKVector4 v, GLKVector4 v2) {
    return ((v.x >= v2.x) && (v.y >= v2.y) && (v.z >= v2.z) && (v.w >= v2.w));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector2AllGreaterThanVector2(GLKVector2 v, GLKVector2 v2) {
    return ((v.x > v2.x) && (v.y > v2.y));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector3AllGreaterThanVector3(GLKVector3 v, GLKVector3 v2) {
    return ((v.x > v2.x) && (v.y > v2.y) && (v.z > v2.z));
}

/**
 @Status Interoperable
*/
inline BOOL GLKVector4AllGreaterThanVector4(GLKVector4 v, GLKVector4 v2) {
    return ((v.x > v2.x) && (v.y > v2.y) && (v.z > v2.z) && (v.w > v2.w));
}

// --------------------------------------------------------------------------------
// Quaternions

GLKIT_EXPORT GLKQuaternion GLKQuaternionMakeIdentity();
GLKIT_EXPORT NSString* NSStringFromGLKQuaternion(GLKQuaternion quaternion);

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionMake(float x, float y, float z, float w) {
    GLKQuaternion res;

    res.x = x;
    res.y = y;
    res.z = z;
    res.w = w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionMakeWithArray(float* vals) {
    GLKQuaternion res;

    res.x = vals[0];
    res.y = vals[1];
    res.z = vals[2];
    res.w = vals[3];

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionMakeWithVector3(GLKVector3 v, float w) {
    GLKQuaternion res;

    res.x = v.x;
    res.y = v.y;
    res.z = v.z;
    res.w = w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionMakeWithAngleAndAxis(float angle, float x, float y, float z) {
    GLKQuaternion res;

    float halfAng = angle * 0.5f;
    float sa = sinf(halfAng);
    res.x = sa * x;
    res.y = sa * y;
    res.z = sa * z;
    res.w = cosf(halfAng);

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionMakeWithAngleAndVector3Axis(float angle, GLKVector3 axis) {
    GLKQuaternion res;

    float halfAng = angle * 0.5f;
    float sa = sinf(halfAng);
    res.x = sa * axis.x;
    res.y = sa * axis.y;
    res.z = sa * axis.z;
    res.w = cosf(halfAng);

    return res;
}

/**
 @Status Interoperable
*/
inline float GLKQuaternionLength(GLKQuaternion quat) {
    return sqrtf(quat.x * quat.x + quat.y * quat.y + quat.z * quat.z + quat.w * quat.w);
}

/**
 @Status Interoperable
*/
inline float GLKQuaternionDot(GLKQuaternion q1, GLKQuaternion q2) {
    return q1.x * q2.x + q1.y * q2.y + q1.z * q2.z + q1.w * q2.w;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionMultiply(GLKQuaternion q1, GLKQuaternion q2) {
    GLKQuaternion res;

    res.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
    res.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
    res.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
    res.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionMultiplyByScalar(float t, GLKQuaternion q) {
    GLKQuaternion res;

    res.x = t * q.x;
    res.y = t * q.y;
    res.z = t * q.z;
    res.w = t * q.w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionAdd(GLKQuaternion q1, GLKQuaternion q2) {
    GLKQuaternion res;

    res.x = q1.x + q2.x;
    res.y = q1.y + q2.y;
    res.z = q1.z + q2.z;
    res.w = q1.w + q2.w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionSubtract(GLKQuaternion q1, GLKQuaternion q2) {
    GLKQuaternion res;

    res.x = q1.x - q2.x;
    res.y = q1.y - q2.y;
    res.z = q1.z - q2.z;
    res.w = q1.w - q2.w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionConjugate(GLKQuaternion q) {
    GLKQuaternion res;

    res.x = -q.x;
    res.y = -q.y;
    res.z = -q.z;
    res.w = q.w;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionNormalize(GLKQuaternion q) {
    GLKQuaternion res;

    float invmag = 1.f / GLKQuaternionLength(q);
    res.x = q.x * invmag;
    res.y = q.y * invmag;
    res.z = q.z * invmag;
    res.w = q.w * invmag;

    return res;
}

/**
 @Status Interoperable
*/
inline float GLKQuaternionAngle(GLKQuaternion quat) {
    return 2.f * acosf(quat.w);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKQuaternionAxis(GLKQuaternion quat) {
    GLKVector3 res;

    float mf = 1.f / sinf(acosf(quat.w));
    res.x = mf * quat.x;
    res.y = mf * quat.y;
    res.z = mf * quat.z;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKQuaternion GLKQuaternionInvert(GLKQuaternion q) {
    GLKQuaternion res;

    float lsq = 1.f / (q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);

    res.x = -q.x * lsq;
    res.y = -q.y * lsq;
    res.z = -q.z * lsq;
    res.w = q.w * lsq;

    return res;
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKQuaternionRotateVector3(GLKQuaternion q, GLKVector3 v) {
    GLKVector3 axis = GLKQuaternionAxis(q);
    float angle = GLKQuaternionAngle(q);
    GLKMatrix4 m = GLKMatrix4MakeRotation(angle, axis.x, axis.y, axis.z);
    return GLKMatrix4MultiplyVector3(m, v);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKQuaternionRotateVector4(GLKQuaternion q, GLKVector4 v) {
    GLKVector3 axis = GLKQuaternionAxis(q);
    float angle = GLKQuaternionAngle(q);
    GLKMatrix4 m = GLKMatrix4MakeRotation(angle, axis.x, axis.y, axis.z);
    return GLKMatrix4MultiplyVector4(m, v);
}

GLKIT_EXPORT void GLKQuaternionRotateVector3Array(GLKQuaternion q, GLKVector3* vecs, size_t numVecs);
GLKIT_EXPORT void GLKQuaternionRotateVector4Array(GLKQuaternion q, GLKVector4* vecs, size_t numVecs);
GLKIT_EXPORT GLKQuaternion GLKQuaternionMakeWithMatrix3(GLKMatrix3 mat);
GLKIT_EXPORT GLKQuaternion GLKQuaternionMakeWithMatrix4(GLKMatrix4 mat);
GLKIT_EXPORT GLKQuaternion GLKQuaternionSlerp(GLKQuaternion quaternionStart, GLKQuaternion quaternionEnd, float t);

/**
@Status Interoperable
*/
inline BOOL GLKQuaternionAllEqualToQuaternion(GLKQuaternion v1, GLKQuaternion v2) {
    GLKQuaternion o = GLKQuaternionSubtract(v1, v2);
    if ((fabsf(o.x) + fabsf(o.y) + fabsf(o.z) + fabsf(o.w)) < (4.f * COMPARISON_EPSILON))
        return YES;
    return NO;
}
// --------------------------------------------------------------------------------
// Utilities.

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3Origin() {
    return GLKVector3Make(0.f, 0.f, 0.f);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3XAxis() {
    return GLKVector3Make(1.f, 0.f, 0.f);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3YAxis() {
    return GLKVector3Make(0.f, 1.f, 0.f);
}

/**
 @Status Interoperable
*/
inline GLKVector3 GLKVector3ZAxis() {
    return GLKVector3Make(0.f, 0.f, 1.f);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Black() {
    return GLKVector4Make(0.f, 0.f, 0.f, 1.f);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4White() {
    return GLKVector4Make(1.f, 1.f, 1.f, 1.f);
}

/**
 @Status Interoperable
*/
inline GLKVector4 GLKVector4Origin() {
    return GLKVector4Make(0.f, 0.f, 0.f, 0.f);
}
