//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <Starboard.h>
#import <StubReturn.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKMath.h>

#include <utility>

const GLKMatrix3 GLKMatrix3Identity = GLKMatrix3MakeIdentity();
const GLKMatrix4 GLKMatrix4Identity = GLKMatrix4MakeIdentity();
const GLKQuaternion GLKQuaternionIdentity = GLKQuaternionMakeIdentity();

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeIdentity() {
    GLKMatrix3 res;

    res.m00 = 1.f;
    res.m01 = 0.f;
    res.m02 = 0.f;

    res.m10 = 0.f;
    res.m11 = 1.f;
    res.m12 = 0.f;

    res.m20 = 0.f;
    res.m21 = 0.f;
    res.m22 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3FromMatrix4(GLKMatrix4 m) {
    GLKMatrix3 res;

    res.m00 = m.m00;
    res.m01 = m.m01;
    res.m02 = m.m02;

    res.m10 = m.m10;
    res.m11 = m.m11;
    res.m12 = m.m12;

    res.m20 = m.m20;
    res.m21 = m.m21;
    res.m22 = m.m22;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeIdentity() {
    GLKMatrix4 res;

    res.m00 = 1.f;
    res.m01 = 0.f;
    res.m02 = 0.f;
    res.m03 = 0.f;

    res.m10 = 0.f;
    res.m11 = 1.f;
    res.m12 = 0.f;
    res.m13 = 0.f;

    res.m20 = 0.f;
    res.m21 = 0.f;
    res.m22 = 1.f;
    res.m23 = 0.f;

    res.m30 = 0.f;
    res.m31 = 0.f;
    res.m32 = 0.f;
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKQuaternion GLKQuaternionMakeIdentity() {
    GLKQuaternion res;

    res.x = 0.0f;
    res.y = 0.0f;
    res.z = 0.0f;
    res.w = 1.0f;

    return res;
}

/**
 @Status Interoperable
*/
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
                                       float m33) {
    GLKMatrix4 res;

    res.m00 = m00;
    res.m01 = m01;
    res.m02 = m02;
    res.m03 = m03;

    res.m10 = m10;
    res.m11 = m11;
    res.m12 = m12;
    res.m13 = m13;

    res.m20 = m20;
    res.m21 = m21;
    res.m22 = m22;
    res.m23 = m23;

    res.m30 = m30;
    res.m31 = m31;
    res.m32 = m32;
    res.m33 = m33;

    return res;
}

/**
 @Status Interoperable
*/
GLKMatrix4 GLKMatrix4Transpose(GLKMatrix4 mat) {
    std::swap(mat.m01, mat.m10);
    std::swap(mat.m02, mat.m20);
    std::swap(mat.m03, mat.m30);
    std::swap(mat.m12, mat.m21);
    std::swap(mat.m13, mat.m31);
    std::swap(mat.m23, mat.m32);

    return mat;
}

/**
 @Status Interoperable
*/
GLKMatrix4 GLKMatrix4MakeAndTranspose(float m00,
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
                                      float m33) {
    GLKMatrix4 res;

    res.m00 = m00;
    res.m10 = m01;
    res.m20 = m02;
    res.m30 = m03;

    res.m01 = m10;
    res.m11 = m11;
    res.m21 = m12;
    res.m31 = m13;

    res.m02 = m20;
    res.m12 = m21;
    res.m22 = m22;
    res.m32 = m23;

    res.m03 = m30;
    res.m13 = m31;
    res.m23 = m32;
    res.m33 = m33;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithArray(float* values) {
    GLKMatrix4 res;

    res.m00 = values[0];
    res.m01 = values[1];
    res.m02 = values[2];
    res.m03 = values[3];

    res.m10 = values[4];
    res.m11 = values[5];
    res.m12 = values[6];
    res.m13 = values[7];

    res.m20 = values[8];
    res.m21 = values[9];
    res.m22 = values[10];
    res.m23 = values[11];

    res.m30 = values[12];
    res.m31 = values[13];
    res.m32 = values[14];
    res.m33 = values[15];

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithArrayAndTranspose(float* values) {
    GLKMatrix4 res;

    res.m00 = values[0];
    res.m10 = values[1];
    res.m20 = values[2];
    res.m30 = values[3];

    res.m01 = values[4];
    res.m11 = values[5];
    res.m21 = values[6];
    res.m31 = values[7];

    res.m02 = values[8];
    res.m12 = values[9];
    res.m22 = values[10];
    res.m32 = values[11];

    res.m03 = values[12];
    res.m13 = values[13];
    res.m23 = values[14];
    res.m33 = values[15];

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithColumns(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3) {
    GLKMatrix4 res;

    res.m00 = r0.x;
    res.m01 = r0.y;
    res.m02 = r0.z;
    res.m03 = r0.w;

    res.m10 = r1.x;
    res.m11 = r1.y;
    res.m12 = r1.z;
    res.m13 = r1.w;

    res.m20 = r2.x;
    res.m21 = r2.y;
    res.m22 = r2.z;
    res.m23 = r2.w;

    res.m30 = r3.x;
    res.m31 = r3.y;
    res.m32 = r3.z;
    res.m33 = r3.w;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeWithRows(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3) {
    GLKMatrix4 res;

    res.m00 = r0.x;
    res.m10 = r0.y;
    res.m20 = r0.z;
    res.m30 = r0.w;

    res.m01 = r1.x;
    res.m11 = r1.y;
    res.m21 = r1.z;
    res.m31 = r1.w;

    res.m02 = r2.x;
    res.m12 = r2.y;
    res.m22 = r2.z;
    res.m32 = r2.w;

    res.m03 = r3.x;
    res.m13 = r3.y;
    res.m23 = r3.z;
    res.m33 = r3.w;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeOrthonormalXform(GLKVector3 right, GLKVector3 up, GLKVector3 forward, GLKVector3 pos) {
    GLKMatrix4 res;

    res.m00 = right.x;
    res.m01 = up.x;
    res.m02 = forward.x;

    res.m10 = right.y;
    res.m11 = up.y;
    res.m12 = forward.y;

    res.m20 = right.z;
    res.m21 = up.z;
    res.m22 = forward.z;

    res.m30 = pos.x;
    res.m31 = pos.y;
    res.m32 = pos.z;

    res.m03 = 0.f;
    res.m13 = 0.f;
    res.m23 = 0.f;
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4
GLKMatrix4MakeLookAt(float eyeX, float eyeY, float eyeZ, float lookX, float lookY, float lookZ, float upX, float upY, float upZ) {
    GLKVector3 eye = GLKVector3Make(eyeX, eyeY, eyeZ);
    GLKVector3 initialUp = GLKVector3Make(upX, upY, upZ);
    GLKVector3 fwd = GLKVector3Normalize(GLKVector3Subtract(GLKVector3Make(lookX, lookY, lookZ), eye));
    GLKVector3 right = GLKVector3Normalize(GLKVector3CrossProduct(fwd, initialUp));
    GLKVector3 up = GLKVector3CrossProduct(right, fwd);

    GLKMatrix4 trans = GLKMatrix4MakeTranslation(-eyeX, -eyeY, -eyeZ);
    return GLKMatrix4Multiply(GLKMatrix4MakeOrthonormalXform(right, up, GLKVector3Negate(fwd), GLKVector3Origin()), trans);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeOrtho(float left, float right, float bot, float top, float near, float far) {
    GLKMatrix4 res;

    res.m00 = 2.f / (right - left);
    res.m10 = 0.f;
    res.m20 = 0.f;
    res.m30 = -(right + left) / (right - left);

    res.m01 = 0.f;
    res.m11 = 2.f / (top - bot);
    res.m21 = 0.f;
    res.m31 = -(top + bot) / (top - bot);

    res.m02 = 0.f;
    res.m12 = 0.f;
    res.m22 = -2.f / (far - near);
    res.m32 = -(far + near) / (far - near);

    res.m03 = 0.f;
    res.m13 = 0.f;
    res.m23 = 0.f;
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakePerspective(float yrad, float aspect, float near, float far) {
    float yd = tanf(yrad / 2.f) * near;
    float xd = tanf(aspect * yrad / 2.f) * near;

    return GLKMatrix4MakeFrustum(-xd, xd, -yd, yd, near, far);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeFrustum(float left, float right, float bottom, float top, float near, float far) {
    GLKMatrix4 res;

    res.m00 = (2.f * near) / (right - left);
    res.m10 = 0.f;
    res.m20 = (right + left) / (right - left);
    res.m30 = 0.f;

    res.m01 = 0.f;
    res.m11 = (2.f * near) / (top - bottom);
    res.m21 = (top + bottom) / (top - bottom);
    res.m31 = 0.f;

    res.m02 = 0.f;
    res.m12 = 0.f;
    res.m22 = (far + near) / (near - far);
    res.m32 = (2.f * far * near) / (near - far);

    res.m03 = 0.f;
    res.m13 = 0.f;
    res.m23 = -1.f;
    res.m33 = 0.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Multiply(GLKMatrix4 m1, GLKMatrix4 m2) {
    GLKMatrix4 res;

    res.m00 = m2.m00 * m1.m00 + m2.m01 * m1.m10 + m2.m02 * m1.m20 + m2.m03 * m1.m30;
    res.m01 = m2.m00 * m1.m01 + m2.m01 * m1.m11 + m2.m02 * m1.m21 + m2.m03 * m1.m31;
    res.m02 = m2.m00 * m1.m02 + m2.m01 * m1.m12 + m2.m02 * m1.m22 + m2.m03 * m1.m32;
    res.m03 = m2.m00 * m1.m03 + m2.m01 * m1.m13 + m2.m02 * m1.m23 + m2.m03 * m1.m33;

    res.m10 = m2.m10 * m1.m00 + m2.m11 * m1.m10 + m2.m12 * m1.m20 + m2.m13 * m1.m30;
    res.m11 = m2.m10 * m1.m01 + m2.m11 * m1.m11 + m2.m12 * m1.m21 + m2.m13 * m1.m31;
    res.m12 = m2.m10 * m1.m02 + m2.m11 * m1.m12 + m2.m12 * m1.m22 + m2.m13 * m1.m32;
    res.m13 = m2.m10 * m1.m03 + m2.m11 * m1.m13 + m2.m12 * m1.m23 + m2.m13 * m1.m33;

    res.m20 = m2.m20 * m1.m00 + m2.m21 * m1.m10 + m2.m22 * m1.m20 + m2.m23 * m1.m30;
    res.m21 = m2.m20 * m1.m01 + m2.m21 * m1.m11 + m2.m22 * m1.m21 + m2.m23 * m1.m31;
    res.m22 = m2.m20 * m1.m02 + m2.m21 * m1.m12 + m2.m22 * m1.m22 + m2.m23 * m1.m32;
    res.m23 = m2.m20 * m1.m03 + m2.m21 * m1.m13 + m2.m22 * m1.m23 + m2.m23 * m1.m33;

    res.m30 = m2.m30 * m1.m00 + m2.m31 * m1.m10 + m2.m32 * m1.m20 + m2.m33 * m1.m30;
    res.m31 = m2.m30 * m1.m01 + m2.m31 * m1.m11 + m2.m32 * m1.m21 + m2.m33 * m1.m31;
    res.m32 = m2.m30 * m1.m02 + m2.m31 * m1.m12 + m2.m32 * m1.m22 + m2.m33 * m1.m32;
    res.m33 = m2.m30 * m1.m03 + m2.m31 * m1.m13 + m2.m32 * m1.m23 + m2.m33 * m1.m33;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Make(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
    GLKMatrix3 res;

    res.m00 = m00;
    res.m01 = m01;
    res.m02 = m02;

    res.m10 = m10;
    res.m11 = m11;
    res.m12 = m12;

    res.m20 = m20;
    res.m21 = m21;
    res.m22 = m22;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Transpose(GLKMatrix3 mat) {
    std::swap(mat.m01, mat.m10);
    std::swap(mat.m02, mat.m20);
    std::swap(mat.m12, mat.m21);

    return mat;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3
GLKMatrix3MakeAndTranspose(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
    GLKMatrix3 res;

    res.m00 = m00;
    res.m10 = m01;
    res.m20 = m02;

    res.m01 = m10;
    res.m11 = m11;
    res.m21 = m12;

    res.m02 = m20;
    res.m12 = m21;
    res.m22 = m22;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithArray(float* values) {
    GLKMatrix3 res;

    res.m00 = values[0];
    res.m01 = values[1];
    res.m02 = values[2];

    res.m10 = values[3];
    res.m11 = values[4];
    res.m12 = values[5];

    res.m20 = values[6];
    res.m21 = values[7];
    res.m22 = values[8];

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithArrayAndTranspose(float* values) {
    GLKMatrix3 res;

    res.m00 = values[0];
    res.m10 = values[1];
    res.m20 = values[2];

    res.m01 = values[3];
    res.m11 = values[4];
    res.m21 = values[5];

    res.m02 = values[6];
    res.m12 = values[7];
    res.m22 = values[8];

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithColumns(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2) {
    GLKMatrix3 res;

    res.m00 = r0.x;
    res.m01 = r0.y;
    res.m02 = r0.z;

    res.m10 = r1.x;
    res.m11 = r1.y;
    res.m12 = r1.z;

    res.m20 = r2.x;
    res.m21 = r2.y;
    res.m22 = r2.z;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeWithRows(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2) {
    GLKMatrix3 res;

    res.m00 = r0.x;
    res.m10 = r0.y;
    res.m20 = r0.z;

    res.m01 = r1.x;
    res.m11 = r1.y;
    res.m21 = r1.z;

    res.m02 = r2.x;
    res.m12 = r2.y;
    res.m22 = r2.z;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Rotate(GLKMatrix4 m, float rad, float x, float y, float z) {
    GLKMatrix4 r = GLKMatrix4MakeRotation(rad, x, y, z);
    return GLKMatrix4Multiply(m, r);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateX(GLKMatrix4 m, float rad) {
    GLKMatrix4 r = GLKMatrix4MakeXRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateY(GLKMatrix4 m, float rad) {
    GLKMatrix4 r = GLKMatrix4MakeYRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4RotateZ(GLKMatrix4 m, float rad) {
    GLKMatrix4 r = GLKMatrix4MakeZRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Translate(GLKMatrix4 m, float x, float y, float z) {
    GLKMatrix4 t = GLKMatrix4MakeTranslation(x, y, z);
    return GLKMatrix4Multiply(m, t);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Scale(GLKMatrix4 m, float x, float y, float z) {
    GLKMatrix4 s = GLKMatrix4MakeScale(x, y, z);
    return GLKMatrix4Multiply(m, s);
}

/**
   @Status Interoperable
*/
GLKIT_EXPORT GLKVector3 GLKMatrix4MultiplyVector3(GLKMatrix4 m, GLKVector3 vec) {
    GLKVector3 res;

    res.x = m.m00 * vec.x + m.m10 * vec.y + m.m20 * vec.z;
    res.y = m.m01 * vec.x + m.m11 * vec.y + m.m21 * vec.z;
    res.z = m.m02 * vec.x + m.m12 * vec.y + m.m22 * vec.z;

    return res;
}

/**
   @Status Interoperable
*/
GLKIT_EXPORT GLKVector3 GLKMatrix3MultiplyVector3(GLKMatrix3 m, GLKVector3 vec) {
    GLKVector3 res;

    res.x = m.m00 * vec.x + m.m10 * vec.y + m.m20 * vec.z;
    res.y = m.m01 * vec.x + m.m11 * vec.y + m.m21 * vec.z;
    res.z = m.m02 * vec.x + m.m12 * vec.y + m.m22 * vec.z;

    return res;
}

/**
   @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix2 GLKMatrix3GetMatrix2(GLKMatrix3 m) {
    GLKMatrix2 res;

    res.m00 = m.m00;
    res.m01 = m.m01;

    res.m10 = m.m10;
    res.m11 = m.m11;

    return res;
}

/**
   @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix2 GLKMatrix4GetMatrix2(GLKMatrix4 m) {
    GLKMatrix2 res;

    res.m00 = m.m00;
    res.m01 = m.m01;

    res.m10 = m.m10;
    res.m11 = m.m11;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix4GetMatrix3(GLKMatrix4 m) {
    GLKMatrix3 res;

    res.m00 = m.m00;
    res.m01 = m.m01;
    res.m02 = m.m02;

    res.m10 = m.m10;
    res.m11 = m.m11;
    res.m12 = m.m12;

    res.m20 = m.m20;
    res.m21 = m.m21;
    res.m22 = m.m22;

    return res;
}

/**
   @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3Invert(GLKMatrix3 matrix, bool* isInvertible) {
    double doubleMatrixArray[9];

    doubleMatrixArray[0] = (double)matrix.m[0];
    doubleMatrixArray[1] = (double)matrix.m[1];
    doubleMatrixArray[2] = (double)matrix.m[2];
    doubleMatrixArray[3] = (double)matrix.m[3];
    doubleMatrixArray[4] = (double)matrix.m[4];
    doubleMatrixArray[5] = (double)matrix.m[5];
    doubleMatrixArray[6] = (double)matrix.m[6];
    doubleMatrixArray[7] = (double)matrix.m[7];
    doubleMatrixArray[8] = (double)matrix.m[8];

    double firstMinor = doubleMatrixArray[0] * (doubleMatrixArray[4] * doubleMatrixArray[8] - doubleMatrixArray[5] * doubleMatrixArray[7]);
    double secondMinor = doubleMatrixArray[1] * (doubleMatrixArray[3] * doubleMatrixArray[8] - doubleMatrixArray[5] * doubleMatrixArray[6]);
    double thirdMinor = doubleMatrixArray[2] * (doubleMatrixArray[3] * doubleMatrixArray[7] - doubleMatrixArray[4] * doubleMatrixArray[6]);

    double determinant = firstMinor - secondMinor + thirdMinor;

    bool canInvert = (determinant != 0.0);
    if (isInvertible) {
        *isInvertible = canInvert;
    }

    if (!canInvert) {
        return GLKMatrix3Identity;
    }

    double invdet = 1 / determinant; // inverse determinant

    GLKMatrix3 inverseMatrix; // inverse of matrix m
    inverseMatrix.m[0] = (doubleMatrixArray[4] * doubleMatrixArray[8] - doubleMatrixArray[7] * doubleMatrixArray[5]) * invdet;
    inverseMatrix.m[1] = (doubleMatrixArray[2] * doubleMatrixArray[7] - doubleMatrixArray[1] * doubleMatrixArray[8]) * invdet;
    inverseMatrix.m[2] = (doubleMatrixArray[1] * doubleMatrixArray[5] - doubleMatrixArray[2] * doubleMatrixArray[4]) * invdet;
    inverseMatrix.m[3] = (doubleMatrixArray[5] * doubleMatrixArray[6] - doubleMatrixArray[3] * doubleMatrixArray[8]) * invdet;
    inverseMatrix.m[4] = (doubleMatrixArray[0] * doubleMatrixArray[8] - doubleMatrixArray[2] * doubleMatrixArray[6]) * invdet;
    inverseMatrix.m[5] = (doubleMatrixArray[3] * doubleMatrixArray[2] - doubleMatrixArray[0] * doubleMatrixArray[5]) * invdet;
    inverseMatrix.m[6] = (doubleMatrixArray[3] * doubleMatrixArray[7] - doubleMatrixArray[6] * doubleMatrixArray[4]) * invdet;
    inverseMatrix.m[7] = (doubleMatrixArray[6] * doubleMatrixArray[1] - doubleMatrixArray[0] * doubleMatrixArray[7]) * invdet;
    inverseMatrix.m[8] = (doubleMatrixArray[0] * doubleMatrixArray[4] - doubleMatrixArray[3] * doubleMatrixArray[1]) * invdet;

    return inverseMatrix;
}

/**
   @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3InvertAndTranspose(GLKMatrix3 m, bool* isInvertible) {
    m = GLKMatrix3Invert(m, isInvertible);
    return GLKMatrix3Transpose(m);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKVector3 GLKMatrix4MultiplyVector3WithTranslation(GLKMatrix4 m, GLKVector3 vec) {
    GLKVector3 res;

    res.x = m.m00 * vec.x + m.m10 * vec.y + m.m20 * vec.z + m.m30;
    res.y = m.m01 * vec.x + m.m11 * vec.y + m.m21 * vec.z + m.m31;
    res.z = m.m02 * vec.x + m.m12 * vec.y + m.m22 * vec.z + m.m32;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT void GLKMatrix4MultiplyVector3ArrayWithTranslation(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs) {
    for (size_t i = 0; i < numVecs; i++)
        vecs[i] = GLKMatrix4MultiplyVector3WithTranslation(m, vecs[i]);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKVector4 GLKMatrix4MultiplyVector4(GLKMatrix4 m, GLKVector4 vec) {
    GLKVector4 res;

    res.x = m.m00 * vec.x + m.m10 * vec.y + m.m20 * vec.z + m.m30 * vec.w;
    res.y = m.m01 * vec.x + m.m11 * vec.y + m.m21 * vec.z + m.m31 * vec.w;
    res.z = m.m02 * vec.x + m.m12 * vec.y + m.m22 * vec.z + m.m32 * vec.w;
    res.w = m.m03 * vec.x + m.m13 * vec.y + m.m23 * vec.z + m.m33 * vec.w;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT void GLKMatrix4MultiplyVector3Array(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs) {
    for (size_t i = 0; i < numVecs; i++)
        vecs[i] = GLKMatrix4MultiplyVector3(m, vecs[i]);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT void GLKMatrix4MultiplyVector4Array(GLKMatrix4 m, GLKVector4* vecs, size_t numVecs) {
    for (size_t i = 0; i < numVecs; i++)
        vecs[i] = GLKMatrix4MultiplyVector4(m, vecs[i]);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4Invert(GLKMatrix4 matrix, bool* isInvertible) {
    // double for better precision
    double b00 = matrix.m[0] * matrix.m[5] - matrix.m[1] * matrix.m[4];
    double b01 = matrix.m[0] * matrix.m[6] - matrix.m[2] * matrix.m[4];
    double b02 = matrix.m[0] * matrix.m[7] - matrix.m[3] * matrix.m[4];
    double b03 = matrix.m[1] * matrix.m[6] - matrix.m[2] * matrix.m[5];
    double b04 = matrix.m[1] * matrix.m[7] - matrix.m[3] * matrix.m[5];
    double b05 = matrix.m[2] * matrix.m[7] - matrix.m[3] * matrix.m[6];
    double b06 = matrix.m[8] * matrix.m[13] - matrix.m[9] * matrix.m[12];
    double b07 = matrix.m[8] * matrix.m[14] - matrix.m[10] * matrix.m[12];
    double b08 = matrix.m[8] * matrix.m[15] - matrix.m[11] * matrix.m[12];
    double b09 = matrix.m[9] * matrix.m[14] - matrix.m[10] * matrix.m[13];
    double b10 = matrix.m[9] * matrix.m[15] - matrix.m[11] * matrix.m[13];
    double b11 = matrix.m[10] * matrix.m[15] - matrix.m[11] * matrix.m[14];

    // Calculate the determinant (inlined to avoid double-caching)
    double determinant = b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    if (isInvertible != NULL) {
        *isInvertible = determinant != 0.0;
    }

    if (determinant == 0) {
        return GLKMatrix4Identity;
    }

    double invDet = 1.0 / determinant;
    GLKMatrix4 m;

    m.m[0] = (matrix.m[5] * b11 - matrix.m[6] * b10 + matrix.m[7] * b09) * invDet;
    m.m[1] = (-matrix.m[1] * b11 + matrix.m[2] * b10 - matrix.m[3] * b09) * invDet;
    m.m[2] = (matrix.m[13] * b05 - matrix.m[14] * b04 + matrix.m[15] * b03) * invDet;
    m.m[3] = (-matrix.m[9] * b05 + matrix.m[10] * b04 - matrix.m[11] * b03) * invDet;
    m.m[4] = (-matrix.m[4] * b11 + matrix.m[6] * b08 - matrix.m[7] * b07) * invDet;
    m.m[5] = (matrix.m[0] * b11 - matrix.m[2] * b08 + matrix.m[3] * b07) * invDet;
    m.m[6] = (-matrix.m[12] * b05 + matrix.m[14] * b02 - matrix.m[15] * b01) * invDet;
    m.m[7] = (matrix.m[8] * b05 - matrix.m[10] * b02 + matrix.m[11] * b01) * invDet;
    m.m[8] = (matrix.m[4] * b10 - matrix.m[5] * b08 + matrix.m[7] * b06) * invDet;
    m.m[9] = (-matrix.m[0] * b10 + matrix.m[1] * b08 - matrix.m[3] * b06) * invDet;
    m.m[10] = (matrix.m[12] * b04 - matrix.m[13] * b02 + matrix.m[15] * b00) * invDet;
    m.m[11] = (-matrix.m[8] * b04 + matrix.m[9] * b02 - matrix.m[11] * b00) * invDet;
    m.m[12] = (-matrix.m[4] * b09 + matrix.m[5] * b07 - matrix.m[6] * b06) * invDet;
    m.m[13] = (matrix.m[0] * b09 - matrix.m[1] * b07 + matrix.m[2] * b06) * invDet;
    m.m[14] = (-matrix.m[12] * b03 + matrix.m[13] * b01 - matrix.m[14] * b00) * invDet;
    m.m[15] = (matrix.m[8] * b03 - matrix.m[9] * b01 + matrix.m[10] * b00) * invDet;

    return m;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeRotation(float rad, float x, float y, float z) {
    float magn = sqrtf(x * x + y * y + z * z);
    if (magn < COMPARISON_EPSILON) {
        return GLKMatrix3MakeIdentity();
    }

    float invMagn = 1.f / magn;
    x *= invMagn;
    y *= invMagn;
    z *= invMagn;

    GLKMatrix3 res = { 0 };

    res.m00 = 1.f + (1.f - cosf(rad)) * (x * x - 1.f);
    res.m10 = -z * sinf(rad) + (1.f - cosf(rad)) * x * y;
    res.m20 = y * sinf(rad) + (1.f - cosf(rad)) * x * z;
    res.m01 = z * sinf(rad) + (1.f - cosf(rad)) * x * y;
    res.m11 = 1.f + (1.f - cosf(rad)) * (y * y - 1.f);
    res.m21 = -x * sinf(rad) + (1.f - cosf(rad)) * y * z;
    res.m02 = -y * sinf(rad) + (1.f - cosf(rad)) * x * z;
    res.m12 = x * sinf(rad) + (1.f - cosf(rad)) * y * z;
    res.m22 = 1.f + (1.f - cosf(rad)) * (z * z - 1.f);

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeXRotation(float rad) {
    GLKMatrix3 res = { 0 };

    res.m00 = 1.f;
    res.m11 = res.m22 = cosf(rad);
    res.m12 = -sinf(rad);
    res.m21 = sinf(rad);

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeYRotation(float rad) {
    GLKMatrix3 res = { 0 };

    res.m11 = 1.f;
    res.m00 = res.m22 = cosf(rad);
    res.m02 = sinf(rad);
    res.m20 = -sinf(rad);

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix3 GLKMatrix3MakeZRotation(float rad) {
    GLKMatrix3 res = { 0 };

    res.m00 = res.m11 = cosf(rad);
    res.m01 = -sinf(rad);
    res.m10 = sinf(rad);
    res.m22 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeRotation(float rad, float x, float y, float z) {
    const float magn = sqrtf(x * x + y * y + z * z);
    GLKMatrix4 res = { 0 };
    float invMagn;

    if (magn < COMPARISON_EPSILON) {
        // Detect near zero magnitude vector and set the inverse to NaN value to avoid divide by zero situation
        // and return the same output as iOS does in this case.
        invMagn = -NAN;
    } else {
        invMagn = 1.f / magn;
    }

    x *= invMagn;
    y *= invMagn;
    z *= invMagn;

    res.m00 = 1.f + (1.f - cosf(rad)) * (x * x - 1.f);
    res.m10 = -z * sinf(rad) + (1.f - cosf(rad)) * x * y;
    res.m20 = y * sinf(rad) + (1.f - cosf(rad)) * x * z;
    res.m01 = z * sinf(rad) + (1.f - cosf(rad)) * x * y;
    res.m11 = 1.f + (1.f - cosf(rad)) * (y * y - 1.f);
    res.m21 = -x * sinf(rad) + (1.f - cosf(rad)) * y * z;
    res.m02 = -y * sinf(rad) + (1.f - cosf(rad)) * x * z;
    res.m12 = x * sinf(rad) + (1.f - cosf(rad)) * y * z;
    res.m22 = 1.f + (1.f - cosf(rad)) * (z * z - 1.f);
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeXRotation(float rad) {
    GLKMatrix4 res = { 0 };
    res.m00 = 1.f;
    res.m11 = res.m22 = cosf(rad);
    res.m12 = sinf(rad);
    res.m21 = -sinf(rad);
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeYRotation(float rad) {
    GLKMatrix4 res = { 0 };

    res.m11 = 1.f;
    res.m00 = res.m22 = cosf(rad);
    res.m02 = -sinf(rad);
    res.m20 = sinf(rad);
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeZRotation(float rad) {
    GLKMatrix4 res = { 0 };

    res.m00 = res.m11 = cosf(rad);
    res.m01 = sinf(rad);
    res.m10 = -sinf(rad);
    res.m22 = 1.f;
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeTranslation(float x, float y, float z) {
    GLKMatrix4 res = GLKMatrix4Identity;

    res.m30 = x;
    res.m31 = y;
    res.m32 = z;
    res.m33 = 1.0f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKMatrix4 GLKMatrix4MakeScale(float x, float y, float z) {
    GLKMatrix4 res = { 0 };

    res.m00 = x;
    res.m11 = y;
    res.m22 = z;
    res.m33 = 1.f;

    return res;
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT void GLKQuaternionRotateVector3Array(GLKQuaternion q, GLKVector3* vecs, size_t numVecs) {
    GLKVector3 axis = GLKQuaternionAxis(q);
    float angle = GLKQuaternionAngle(q);
    GLKMatrix4 m = GLKMatrix4MakeRotation(angle, axis.x, axis.y, axis.z);
    GLKMatrix4MultiplyVector3Array(m, vecs, numVecs);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT void GLKQuaternionRotateVector4Array(GLKQuaternion q, GLKVector4* vecs, size_t numVecs) {
    GLKVector3 axis = GLKQuaternionAxis(q);
    float angle = GLKQuaternionAngle(q);
    GLKMatrix4 m = GLKMatrix4MakeRotation(angle, axis.x, axis.y, axis.z);
    GLKMatrix4MultiplyVector4Array(m, vecs, numVecs);
}

/**
 @Status Interoperable
*/
GLKIT_EXPORT GLKQuaternion GLKQuaternionMakeWithMatrix3(GLKMatrix3 mat) {
    GLKQuaternion res;

    float trace = mat.m00 + mat.m11 + mat.m22;
    if (trace > COMPARISON_EPSILON) {
        float sqrtTrace = 2.f * sqrtf(trace + 1.f);
        float invTrace = 1.f / sqrtTrace;

        res.x = (mat.m21 - mat.m12) * invTrace;
        res.y = (mat.m02 - mat.m20) * invTrace;
        res.z = (mat.m10 - mat.m01) * invTrace;
        res.w = 0.25f * sqrtTrace;

    } else if ((mat.m00 > mat.m11) && (mat.m00 > mat.m22)) {
        float sqrtTrace = 2.f * sqrtf(1.f + mat.m00 - mat.m11 - mat.m22);
        float invTrace = 1.f / sqrtTrace;

        res.x = 0.25f * sqrtTrace;
        res.y = (mat.m10 + mat.m01) * invTrace;
        res.z = (mat.m02 + mat.m20) * invTrace;
        res.w = (mat.m21 - mat.m12) * invTrace;

    } else if (mat.m11 > mat.m22) {
        float sqrtTrace = 2.f * sqrtf(1.f + mat.m11 - mat.m00 - mat.m22);
        float invTrace = 1.f / sqrtTrace;

        res.x = (mat.m10 + mat.m01) * invTrace;
        res.y = 0.25f * sqrtTrace;
        res.z = (mat.m21 + mat.m12) * invTrace;
        res.w = (mat.m02 - mat.m20) * invTrace;

    } else {
        float sqrtTrace = 2.f * sqrtf(1.f + mat.m22 - mat.m00 - mat.m11);
        float invTrace = 1.f / sqrtTrace;

        res.x = (mat.m02 + mat.m20) * invTrace;
        res.y = (mat.m21 + mat.m12) * invTrace;
        res.z = 0.25f * sqrtTrace;
        res.w = (mat.m10 - mat.m01) * invTrace;
    }

    return res;
}

/**
 @Status Stub
*/
GLKIT_EXPORT GLKQuaternion GLKQuaternionMakeWithMatrix4(GLKMatrix4 mat) {
    UNIMPLEMENTED();
    GLKQuaternion res;
    return res;
}

/**
 @Status Interoperable
 @Notes
*/
GLKVector3 GLKMathProject(GLKVector3 object, GLKMatrix4 model, GLKMatrix4 projection, int* viewport) {
    GLKVector4 v4 = GLKVector4MakeWithVector3(object, 1.0);
    GLKVector4 v = GLKMatrix4MultiplyVector4(model, v4);
    v = GLKMatrix4MultiplyVector4(projection, v);

    v.w = 1.0 / v.w;
    v.x *= v.w;
    v.y *= v.w;
    v.z *= v.w;

    float x = (v.x * 0.5 + 0.5) * viewport[2] + viewport[0];
    float y = (v.y * 0.5 + 0.5) * viewport[3] + viewport[1];
    float z = (1.0 + v.z) * 0.5;

    return GLKVector3Make(x, y, z);
}

/**
 @Status Interoperable
*/
GLKVector3 GLKMathUnproject(GLKVector3 window, GLKMatrix4 model, GLKMatrix4 projection, int* viewport, bool* success) {
    bool canInvert = false;
    GLKMatrix4 inverted = GLKMatrix4Invert(GLKMatrix4Multiply(projection, model), &canInvert);
    if (success) {
        *success = canInvert;
    }

    if (!canInvert) {
        return GLKVector3Make(0.0f, 0.0f, 0.0f);
    }

    GLKVector4 nv = GLKVector4Make((2.0 * window.x / viewport[2] - 1.0),
                                   (2.0 * (window.y - (double)viewport[1]) / (double)viewport[3] - 1),
                                   2.0 * window.z - 1.0,
                                   1.0);

    GLKVector4 point = GLKMatrix4MultiplyVector4(inverted, nv);
    point.w = 1.0 / point.w;

    GLKVector3 vec = GLKVector3Make(point.x * point.w, point.y * point.w, point.z * point.w);

    return vec;
}

/**
 @Status Interoperable
*/
NSString* NSStringFromGLKMatrix2(GLKMatrix2 matrix) {
    return [NSString stringWithFormat:@"{{%f, %f}, {%f, %f}}", matrix.m00, matrix.m01, matrix.m10, matrix.m11];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromGLKMatrix3(GLKMatrix3 matrix) {
    return [NSString stringWithFormat:@"{{%f, %f, %f}, {%f, %f, %f}, {%f, %f, %f}}",
                                      matrix.m00,
                                      matrix.m01,
                                      matrix.m02,
                                      matrix.m10,
                                      matrix.m11,
                                      matrix.m12,
                                      matrix.m20,
                                      matrix.m21,
                                      matrix.m22];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromGLKMatrix4(GLKMatrix4 matrix) {
    return [NSString stringWithFormat:@"{{%f, %f, %f, %f}, {%f, %f, %f, %f}, {%f, %f, %f, %f}, {%f, %f, %f, %f}}",
                                      matrix.m00,
                                      matrix.m01,
                                      matrix.m02,
                                      matrix.m03,
                                      matrix.m10,
                                      matrix.m11,
                                      matrix.m12,
                                      matrix.m13,
                                      matrix.m20,
                                      matrix.m21,
                                      matrix.m22,
                                      matrix.m23,
                                      matrix.m30,
                                      matrix.m31,
                                      matrix.m32,
                                      matrix.m33];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromGLKVector2(GLKVector2 vector) {
    return [NSString stringWithFormat:@"{%f, %f}", vector.x, vector.y];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromGLKVector3(GLKVector3 vector) {
    return [NSString stringWithFormat:@"{%f, %f, %f}", vector.x, vector.y, vector.z];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromGLKVector4(GLKVector4 vector) {
    return [NSString stringWithFormat:@"{%f, %f, %f, %f}", vector.x, vector.y, vector.z, vector.w];
}

/**
 @Status Interoperable
*/
NSString* NSStringFromGLKQuaternion(GLKQuaternion quaternion) {
    return [NSString stringWithFormat:@"{%f, %f, %f, %f}", quaternion.x, quaternion.y, quaternion.z, quaternion.w];
}

/**
 @Status Interoperable
*/
GLKMatrix3 GLKMatrix3MakeWithQuaternion(GLKQuaternion quaternion) {
    quaternion = GLKQuaternionNormalize(quaternion);

    float x = quaternion.q[0];
    float y = quaternion.q[1];
    float z = quaternion.q[2];
    float w = quaternion.q[3];

    float _2x = x + x;
    float _2y = y + y;
    float _2z = z + z;
    float _2w = w + w;

    GLKMatrix3 m = GLKMatrix3Make(1.0f - _2y * y - _2z * z,
                                  _2x * y + _2w * z,
                                  _2x * z - _2w * y,
                                  _2x * y - _2w * z,
                                  1.0f - _2x * x - _2z * z,
                                  _2y * z + _2w * x,
                                  _2x * z + _2w * y,
                                  _2y * z - _2w * x,
                                  1.0f - _2x * x - _2y * y);

    return m;
}

/**
 @Status Interoperable
*/
GLKMatrix3 GLKMatrix3MakeScale(float sx, float sy, float sz) {
    GLKMatrix3 m = GLKMatrix3Identity;
    m.m[0] = sx;
    m.m[4] = sy;
    m.m[8] = sz;
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKVector3 GLKMatrix3GetColumn(GLKMatrix3 matrix, int column) {
    GLKVector3 v;
    v.x = matrix.m[column * 3 + 0];
    v.y = matrix.m[column * 3 + 1];
    v.z = matrix.m[column * 3 + 2];
    return v;
}

/**
 @Status Interoperable
 @Notes
*/
GLKVector3 GLKMatrix3GetRow(GLKMatrix3 matrix, int row) {
    GLKVector3 v;
    v.x = matrix.m[row];
    v.y = matrix.m[3 + row];
    v.z = matrix.m[6 + row];
    return v;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3SetColumn(GLKMatrix3 matrix, int column, GLKVector3 vector) {
    matrix.m[column * 3 + 0] = vector.x;
    matrix.m[column * 3 + 1] = vector.y;
    matrix.m[column * 3 + 2] = vector.z;
    return matrix;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3SetRow(GLKMatrix3 matrix, int row, GLKVector3 vector) {
    matrix.m[row] = vector.x;
    matrix.m[row + 3] = vector.y;
    matrix.m[row + 6] = vector.z;
    return matrix;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3Multiply(GLKMatrix3 matrixLeft, GLKMatrix3 matrixRight) {
    GLKMatrix3 m;

    m.m00 = matrixLeft.m00 * matrixRight.m00 + matrixLeft.m10 * matrixRight.m01 + matrixLeft.m20 * matrixRight.m02;

    m.m10 = matrixLeft.m00 * matrixRight.m10 + matrixLeft.m10 * matrixRight.m11 + matrixLeft.m20 * matrixRight.m12;

    m.m20 = matrixLeft.m00 * matrixRight.m20 + matrixLeft.m10 * matrixRight.m21 + matrixLeft.m20 * matrixRight.m22;

    m.m01 = matrixLeft.m01 * matrixRight.m00 + matrixLeft.m11 * matrixRight.m01 + matrixLeft.m21 * matrixRight.m02;

    m.m11 = matrixLeft.m01 * matrixRight.m10 + matrixLeft.m11 * matrixRight.m11 + matrixLeft.m21 * matrixRight.m12;

    m.m21 = matrixLeft.m01 * matrixRight.m20 + matrixLeft.m11 * matrixRight.m21 + matrixLeft.m21 * matrixRight.m22;

    m.m02 = matrixLeft.m02 * matrixRight.m00 + matrixLeft.m12 * matrixRight.m01 + matrixLeft.m22 * matrixRight.m02;

    m.m12 = matrixLeft.m02 * matrixRight.m10 + matrixLeft.m12 * matrixRight.m11 + matrixLeft.m22 * matrixRight.m12;

    m.m22 = matrixLeft.m02 * matrixRight.m20 + matrixLeft.m12 * matrixRight.m21 + matrixLeft.m22 * matrixRight.m22;

    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3Rotate(GLKMatrix3 matrix, float radians, float x, float y, float z) {
    GLKMatrix3 rm = GLKMatrix3MakeRotation(radians, x, y, z);
    return GLKMatrix3Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3RotateWithVector3(GLKMatrix3 matrix, float radians, GLKVector3 axisVector) {
    GLKMatrix3 rm = GLKMatrix3MakeRotation(radians, axisVector.x, axisVector.y, axisVector.z);
    return GLKMatrix3Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3RotateWithVector4(GLKMatrix3 matrix, float radians, GLKVector4 axisVector) {
    GLKMatrix3 rm = GLKMatrix3MakeRotation(radians, axisVector.x, axisVector.y, axisVector.z);
    return GLKMatrix3Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3RotateX(GLKMatrix3 matrix, float radians) {
    GLKMatrix3 rm = GLKMatrix3MakeXRotation(radians);
    return GLKMatrix3Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3RotateY(GLKMatrix3 matrix, float radians) {
    GLKMatrix3 rm = GLKMatrix3MakeYRotation(radians);
    return GLKMatrix3Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3RotateZ(GLKMatrix3 matrix, float radians) {
    GLKMatrix3 rm = GLKMatrix3MakeZRotation(radians);
    return GLKMatrix3Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3Scale(GLKMatrix3 matrix, float sx, float sy, float sz) {
    GLKMatrix3 m = GLKMatrix3Make(matrix.m00 * sx,
                                  matrix.m01 * sx,
                                  matrix.m02 * sx,
                                  matrix.m10 * sy,
                                  matrix.m11 * sy,
                                  matrix.m12 * sy,
                                  matrix.m20 * sz,
                                  matrix.m21 * sz,
                                  matrix.m22 * sz);
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3ScaleWithVector3(GLKMatrix3 matrix, GLKVector3 scaleVector) {
    GLKMatrix3 m = GLKMatrix3Scale(matrix, scaleVector.x, scaleVector.y, scaleVector.z);
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3ScaleWithVector4(GLKMatrix3 matrix, GLKVector4 scaleVector) {
    GLKMatrix3 m = GLKMatrix3Scale(matrix, scaleVector.x, scaleVector.y, scaleVector.z);
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3Add(GLKMatrix3 matrixLeft, GLKMatrix3 matrixRight) {
    GLKMatrix3 m;

    m.m[0] = matrixLeft.m[0] + matrixRight.m[0];
    m.m[1] = matrixLeft.m[1] + matrixRight.m[1];
    m.m[2] = matrixLeft.m[2] + matrixRight.m[2];

    m.m[3] = matrixLeft.m[3] + matrixRight.m[3];
    m.m[4] = matrixLeft.m[4] + matrixRight.m[4];
    m.m[5] = matrixLeft.m[5] + matrixRight.m[5];

    m.m[6] = matrixLeft.m[6] + matrixRight.m[6];
    m.m[7] = matrixLeft.m[7] + matrixRight.m[7];
    m.m[8] = matrixLeft.m[8] + matrixRight.m[8];

    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix3 GLKMatrix3Subtract(GLKMatrix3 matrixLeft, GLKMatrix3 matrixRight) {
    GLKMatrix3 m;

    m.m[0] = matrixLeft.m[0] - matrixRight.m[0];
    m.m[1] = matrixLeft.m[1] - matrixRight.m[1];
    m.m[2] = matrixLeft.m[2] - matrixRight.m[2];

    m.m[3] = matrixLeft.m[3] - matrixRight.m[3];
    m.m[4] = matrixLeft.m[4] - matrixRight.m[4];
    m.m[5] = matrixLeft.m[5] - matrixRight.m[5];

    m.m[6] = matrixLeft.m[6] - matrixRight.m[6];
    m.m[7] = matrixLeft.m[7] - matrixRight.m[7];
    m.m[8] = matrixLeft.m[8] - matrixRight.m[8];

    return m;
}

/**
 @Status Interoperable
 @Notes
*/
void GLKMatrix3MultiplyVector3Array(GLKMatrix3 matrix, GLKVector3* vectors, size_t vectorCount) {
    for (int i = 0; i < vectorCount; i++) {
        vectors[i] = GLKMatrix3MultiplyVector3(matrix, vectors[i]);
    }
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4MakeWithQuaternion(GLKQuaternion quaternion) {
    GLKQuaternion quaternionNormalized = GLKQuaternionNormalize(quaternion);

    float x = quaternionNormalized.q[0];
    float y = quaternionNormalized.q[1];
    float z = quaternionNormalized.q[2];
    float w = quaternionNormalized.q[3];

    float _2x = x + x;
    float _2y = y + y;
    float _2z = z + z;
    float _2w = w + w;

    GLKMatrix4 m = GLKMatrix4Make(1.0f - _2y * y - _2z * z,
                                  _2x * y + _2w * z,
                                  _2x * z - _2w * y,
                                  0.0f,
                                  _2x * y - _2w * z,
                                  1.0f - _2x * x - _2z * z,
                                  _2y * z + _2w * x,
                                  0.0f,
                                  _2x * z + _2w * y,
                                  _2y * z - _2w * x,
                                  1.0f - _2x * x - _2y * y,
                                  0.0f,
                                  0.0f,
                                  0.0f,
                                  0.0f,
                                  1.0f);

    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKQuaternion GLKQuaternionSlerp(GLKQuaternion quaternionStart, GLKQuaternion quaternionEnd, float t) {
    GLKQuaternion q1 = quaternionStart;
    GLKQuaternion q2 = quaternionEnd;

    double cosHalfTheta = GLKQuaternionDot(q1, q2);

    if (fabs(cosHalfTheta) >= 1.0) {
        // Lerp
        return GLKQuaternionAdd(GLKQuaternionMultiplyByScalar(1.0 - t, q1), GLKQuaternionMultiplyByScalar(t, quaternionEnd));
    }

    // Calculate temporary values.
    double halfTheta = acos(cosHalfTheta);
    double sinHalfTheta = sqrt(1.0 - cosHalfTheta * cosHalfTheta);

    // if theta = 180 degrees then result is not fully defined
    // we could rotate around any axis normal to qa or qb
    if (fabs(sinHalfTheta) < 0.001) { // fabs is floating point absolute
        return GLKQuaternionAdd(GLKQuaternionMultiplyByScalar(0.5, quaternionStart), GLKQuaternionMultiplyByScalar(0.5, quaternionEnd));
    }

    double ratioA = sin((1.0 - t) * halfTheta) / sinHalfTheta;
    double ratioB = sin(t * halfTheta) / sinHalfTheta;

    // calculate Quaternion.
    return GLKQuaternionAdd(GLKQuaternionMultiplyByScalar(ratioA, quaternionStart), GLKQuaternionMultiplyByScalar(ratioB, quaternionEnd));
}

/**
 @Status Interoperable
 @Notes
*/
GLKVector4 GLKMatrix4GetColumn(GLKMatrix4 matrix, int column) {
    GLKVector4 v = GLKVector4Make(matrix.m[column * 4 + 0], matrix.m[column * 4 + 1], matrix.m[column * 4 + 2], matrix.m[column * 4 + 3]);
    return v;
}

/**
 @Status Interoperable
 @Notes
*/
GLKVector4 GLKMatrix4GetRow(GLKMatrix4 matrix, int row) {
    GLKVector4 v = GLKVector4Make(matrix.m[row], matrix.m[4 + row], matrix.m[8 + row], matrix.m[12 + row]);
    return v;
}

/**
 @Status Caveat
 @Notes  Valid column values range from 0 to 3, inclusive.
*/
GLKMatrix4 GLKMatrix4SetColumn(GLKMatrix4 matrix, int column, GLKVector4 vector) {
    matrix.m[column * 4 + 0] = vector.x;
    matrix.m[column * 4 + 1] = vector.y;
    matrix.m[column * 4 + 2] = vector.z;
    matrix.m[column * 4 + 3] = vector.w;

    return matrix;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4SetRow(GLKMatrix4 matrix, int row, GLKVector4 vector) {
    matrix.m[row] = vector.x;
    matrix.m[row + 4] = vector.y;
    matrix.m[row + 8] = vector.z;
    matrix.m[row + 12] = vector.w;
    return matrix;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4InvertAndTranspose(GLKMatrix4 matrix, bool* isInvertible) {
    bool canInvert = false;
    GLKMatrix4 inverted = GLKMatrix4Invert(matrix, &canInvert);
    if (!canInvert) {
        return GLKMatrix4Identity;
    }
    return GLKMatrix4Transpose(inverted);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4RotateWithVector3(GLKMatrix4 matrix, float radians, GLKVector3 axisVector) {
    GLKMatrix4 rm = GLKMatrix4MakeRotation(radians, axisVector.v[0], axisVector.v[1], axisVector.v[2]);
    return GLKMatrix4Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4RotateWithVector4(GLKMatrix4 matrix, float radians, GLKVector4 axisVector) {
    GLKMatrix4 rm = GLKMatrix4MakeRotation(radians, axisVector.v[0], axisVector.v[1], axisVector.v[2]);
    return GLKMatrix4Multiply(matrix, rm);
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4ScaleWithVector3(GLKMatrix4 matrix, GLKVector3 scaleVector) {
    GLKMatrix4 m = GLKMatrix4Make(matrix.m[0] * scaleVector.x,
                                  matrix.m[1] * scaleVector.x,
                                  matrix.m[2] * scaleVector.x,
                                  matrix.m[3] * scaleVector.x,
                                  matrix.m[4] * scaleVector.y,
                                  matrix.m[5] * scaleVector.y,
                                  matrix.m[6] * scaleVector.y,
                                  matrix.m[7] * scaleVector.y,
                                  matrix.m[8] * scaleVector.z,
                                  matrix.m[9] * scaleVector.z,
                                  matrix.m[10] * scaleVector.z,
                                  matrix.m[11] * scaleVector.z,
                                  matrix.m[12],
                                  matrix.m[13],
                                  matrix.m[14],
                                  matrix.m[15]);
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4ScaleWithVector4(GLKMatrix4 matrix, GLKVector4 scaleVector) {
    GLKMatrix4 m = GLKMatrix4ScaleWithVector3(matrix, GLKVector3Make(scaleVector.x, scaleVector.y, scaleVector.z));
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4TranslateWithVector3(GLKMatrix4 matrix, GLKVector3 translationVector) {
    GLKMatrix4 m =
        GLKMatrix4Make(matrix.m00,
                       matrix.m01,
                       matrix.m02,
                       matrix.m03,
                       matrix.m10,
                       matrix.m11,
                       matrix.m12,
                       matrix.m13,
                       matrix.m20,
                       matrix.m21,
                       matrix.m22,
                       matrix.m23,
                       matrix.m00 * translationVector.x + matrix.m10 * translationVector.y + matrix.m20 * translationVector.z + matrix.m30,
                       matrix.m01 * translationVector.x + matrix.m11 * translationVector.y + matrix.m21 * translationVector.z + matrix.m31,
                       matrix.m02 * translationVector.x + matrix.m12 * translationVector.y + matrix.m22 * translationVector.z + matrix.m32,
                       matrix.m03 * translationVector.x + matrix.m13 * translationVector.y + matrix.m23 * translationVector.z + matrix.m33);
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4TranslateWithVector4(GLKMatrix4 matrix, GLKVector4 translationVector) {
    GLKMatrix4 m = GLKMatrix4TranslateWithVector3(matrix, GLKVector3Make(translationVector.x, translationVector.y, translationVector.z));
    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4Add(GLKMatrix4 matrixLeft, GLKMatrix4 matrixRight) {
    GLKMatrix4 m;

    m.m[0] = matrixLeft.m[0] + matrixRight.m[0];
    m.m[1] = matrixLeft.m[1] + matrixRight.m[1];
    m.m[2] = matrixLeft.m[2] + matrixRight.m[2];
    m.m[3] = matrixLeft.m[3] + matrixRight.m[3];

    m.m[4] = matrixLeft.m[4] + matrixRight.m[4];
    m.m[5] = matrixLeft.m[5] + matrixRight.m[5];
    m.m[6] = matrixLeft.m[6] + matrixRight.m[6];
    m.m[7] = matrixLeft.m[7] + matrixRight.m[7];

    m.m[8] = matrixLeft.m[8] + matrixRight.m[8];
    m.m[9] = matrixLeft.m[9] + matrixRight.m[9];
    m.m[10] = matrixLeft.m[10] + matrixRight.m[10];
    m.m[11] = matrixLeft.m[11] + matrixRight.m[11];

    m.m[12] = matrixLeft.m[12] + matrixRight.m[12];
    m.m[13] = matrixLeft.m[13] + matrixRight.m[13];
    m.m[14] = matrixLeft.m[14] + matrixRight.m[14];
    m.m[15] = matrixLeft.m[15] + matrixRight.m[15];

    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKMatrix4 GLKMatrix4Subtract(GLKMatrix4 matrixLeft, GLKMatrix4 matrixRight) {
    GLKMatrix4 m;

    m.m[0] = matrixLeft.m[0] - matrixRight.m[0];
    m.m[1] = matrixLeft.m[1] - matrixRight.m[1];
    m.m[2] = matrixLeft.m[2] - matrixRight.m[2];
    m.m[3] = matrixLeft.m[3] - matrixRight.m[3];

    m.m[4] = matrixLeft.m[4] - matrixRight.m[4];
    m.m[5] = matrixLeft.m[5] - matrixRight.m[5];
    m.m[6] = matrixLeft.m[6] - matrixRight.m[6];
    m.m[7] = matrixLeft.m[7] - matrixRight.m[7];

    m.m[8] = matrixLeft.m[8] - matrixRight.m[8];
    m.m[9] = matrixLeft.m[9] - matrixRight.m[9];
    m.m[10] = matrixLeft.m[10] - matrixRight.m[10];
    m.m[11] = matrixLeft.m[11] - matrixRight.m[11];

    m.m[12] = matrixLeft.m[12] - matrixRight.m[12];
    m.m[13] = matrixLeft.m[13] - matrixRight.m[13];
    m.m[14] = matrixLeft.m[14] - matrixRight.m[14];
    m.m[15] = matrixLeft.m[15] - matrixRight.m[15];

    return m;
}

/**
 @Status Interoperable
 @Notes
*/
GLKVector3 GLKMatrix4MultiplyAndProjectVector3(GLKMatrix4 matrixLeft, GLKVector3 vectorRight) {
    GLKVector4 v4 = GLKMatrix4MultiplyVector4(matrixLeft, GLKVector4Make(vectorRight.x, vectorRight.y, vectorRight.z, 1.0f));
    GLKVector3 v = GLKVector3MultiplyScalar(GLKVector3Make(v4.x, v4.y, v4.z), 1.0f / v4.w);
    return v;
}

/**
 @Status Interoperable
 @Notes
*/
void GLKMatrix4MultiplyAndProjectVector3Array(GLKMatrix4 matrix, GLKVector3* vectors, size_t vectorCount) {
    for (int i = 0; i < vectorCount; i++) {
        vectors[i] = GLKMatrix4MultiplyAndProjectVector3(matrix, vectors[i]);
    }
}
