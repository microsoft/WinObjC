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

#import <Starboard.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKMath.h>

#include <utility>

GLKMatrix3 GLKMatrix3Identity = GLKMatrix3MakeIdentity();
GLKMatrix4 GLKMatrix4Identity = GLKMatrix4MakeIdentity();

GLKMatrix3 GLKMatrix3MakeIdentity() {
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

GLKMatrix3 GLKMatrix3FromMatrix4(GLKMatrix4 m) {
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

GLKMatrix4 GLKMatrix4MakeIdentity() {
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

GLKMatrix4 GLKMatrix4Make(float m00,
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

GLKMatrix4 GLKMatrix4Transpose(GLKMatrix4 mat) {
    std::swap(mat.m01, mat.m10);
    std::swap(mat.m02, mat.m20);
    std::swap(mat.m03, mat.m30);
    std::swap(mat.m12, mat.m21);
    std::swap(mat.m13, mat.m31);
    std::swap(mat.m23, mat.m32);

    return mat;
}

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

GLKMatrix4 GLKMatrix4MakeWithArray(float* values) {
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

GLKMatrix4 GLKMatrix4MakeWithArrayAndTranspose(float* values) {
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

GLKMatrix4 GLKMatrix4MakeWithColumns(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3) {
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

GLKMatrix4 GLKMatrix4MakeWithRows(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3) {
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

GLKMatrix4 GLKMatrix4MakeOrthonormalXform(GLKVector3 right, GLKVector3 up, GLKVector3 forward, GLKVector3 pos) {
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

GLKMatrix4 GLKMatrix4MakeLookAt(
    float eyeX, float eyeY, float eyeZ, float lookX, float lookY, float lookZ, float upX, float upY, float upZ) {
    GLKVector3 eye = GLKVector3Make(eyeX, eyeY, eyeZ);
    GLKVector3 initialUp = GLKVector3Make(upX, upY, upZ);
    GLKVector3 fwd = GLKVector3Normalize(GLKVector3Subtract(GLKVector3Make(lookX, lookY, lookZ), eye));
    GLKVector3 right = GLKVector3Normalize(GLKVector3CrossProduct(fwd, initialUp));
    GLKVector3 up = GLKVector3CrossProduct(right, fwd);

    GLKMatrix4 trans = GLKMatrix4MakeTranslation(-eyeX, -eyeY, -eyeZ);
    return GLKMatrix4Multiply(GLKMatrix4MakeOrthonormalXform(right, up, GLKVector3Negate(fwd), GLKVector3Origin()),
                              trans);
}

GLKMatrix4 GLKMatrix4MakeOrtho(float left, float right, float bot, float top, float near, float far) {
    GLKMatrix4 res;

    res.m00 = 2.f / (right - left);
    res.m10 = 0.f;
    res.m20 = 0.f;
    res.m30 = (0.f - right - left) / (right - left);

    res.m01 = 0.f;
    res.m11 = 2.f / (top - bot);
    res.m21 = 0.f;
    res.m31 = (0.f - top - bot) / (top - bot);

    res.m02 = 0.f;
    res.m12 = 0.f;
    res.m22 = -2.f / (far - near);
    res.m32 = (far + near) / (far - near);

    res.m03 = 0.f;
    res.m13 = 0.f;
    res.m23 = 0.f;
    res.m33 = 1.f;

    return res;
}

GLKMatrix4 GLKMatrix4MakePerspective(float yrad, float aspect, float near, float far) {
    float yd = tanf(yrad / 2.f) * near;
    float xd = tanf(aspect * yrad / 2.f) * near;

    return GLKMatrix4MakeFrustum(-xd, xd, -yd, yd, near, far);
}

GLKMatrix4 GLKMatrix4MakeFrustum(float left, float right, float bottom, float top, float near, float far) {
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

GLKMatrix4 GLKMatrix4Multiply(GLKMatrix4 m1, GLKMatrix4 m2) {
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

GLKMatrix3
GLKMatrix3Make(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
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

GLKMatrix4 GLKMatrix3Transpose(GLKMatrix4 mat) {
    std::swap(mat.m01, mat.m10);
    std::swap(mat.m02, mat.m20);
    std::swap(mat.m12, mat.m21);

    return mat;
}

GLKMatrix3 GLKMatrix3MakeAndTranspose(
    float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
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

GLKMatrix3 GLKMatrix3MakeWithArray(float* values) {
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

GLKMatrix3 GLKMatrix3MakeWithArrayAndTranspose(float* values) {
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

GLKMatrix3 GLKMatrix3MakeWithColumns(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2) {
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

GLKMatrix3 GLKMatrix3MakeWithRows(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2) {
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

GLKMatrix4 GLKMatrix4Rotate(GLKMatrix4 m, float rad, float x, float y, float z) {
    GLKMatrix4 r = GLKMatrix4MakeRotation(rad, x, y, z);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4RotateX(GLKMatrix4 m, float rad) {
    GLKMatrix4 r = GLKMatrix4MakeXRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4RotateY(GLKMatrix4 m, float rad) {
    GLKMatrix4 r = GLKMatrix4MakeYRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4RotateZ(GLKMatrix4 m, float rad) {
    GLKMatrix4 r = GLKMatrix4MakeZRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4Translate(GLKMatrix4 m, float x, float y, float z) {
    GLKMatrix4 t = GLKMatrix4MakeTranslation(x, y, z);
    return GLKMatrix4Multiply(m, t);
}

GLKMatrix4 GLKMatrix4Scale(GLKMatrix4 m, float x, float y, float z) {
    GLKMatrix4 s = GLKMatrix4MakeScale(x, y, z);
    return GLKMatrix4Multiply(m, s);
}

GLKVector3 GLKMatrix4MultiplyVector3(GLKMatrix4 m, GLKVector3 vec) {
    GLKVector3 res;

    res.x = m.m00 * vec.x + m.m10 * vec.y + m.m20 * vec.z;
    res.y = m.m01 * vec.x + m.m11 * vec.y + m.m21 * vec.z;
    res.z = m.m02 * vec.x + m.m12 * vec.y + m.m22 * vec.z;

    return res;
}

GLKVector3 GLKMatrix4MultiplyVector3WithTranslation(GLKMatrix4 m, GLKVector3 vec) {
    GLKVector3 res;

    res.x = m.m00 * vec.x + m.m10 * vec.y + m.m20 * vec.z + m.m30;
    res.y = m.m01 * vec.x + m.m11 * vec.y + m.m21 * vec.z + m.m31;
    res.z = m.m02 * vec.x + m.m12 * vec.y + m.m22 * vec.z + m.m32;

    return res;
}

void GLKMatrix4MultiplyVector3ArrayWithTranslation(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs) {
    for (size_t i = 0; i < numVecs; i++)
        vecs[i] = GLKMatrix4MultiplyVector3WithTranslation(m, vecs[i]);
}

GLKVector4 GLKMatrix4MultiplyVector4(GLKMatrix4 m, GLKVector4 vec) {
    GLKVector4 res;

    res.x = m.m00 * vec.x + m.m10 * vec.y + m.m20 * vec.z + m.m30 * vec.w;
    res.y = m.m01 * vec.x + m.m11 * vec.y + m.m21 * vec.z + m.m31 * vec.w;
    res.z = m.m02 * vec.x + m.m12 * vec.y + m.m22 * vec.z + m.m32 * vec.w;
    res.w = m.m03 * vec.x + m.m13 * vec.y + m.m23 * vec.z + m.m33 * vec.w;

    return res;
}

void GLKMatrix4MultiplyVector3Array(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs) {
    for (size_t i = 0; i < numVecs; i++)
        vecs[i] = GLKMatrix4MultiplyVector3(m, vecs[i]);
}

void GLKMatrix4MultiplyVector4Array(GLKMatrix4 m, GLKVector4* vecs, size_t numVecs) {
    for (size_t i = 0; i < numVecs; i++)
        vecs[i] = GLKMatrix4MultiplyVector4(m, vecs[i]);
}

GLKMatrix4 GLKMatrix4Invert(GLKMatrix4 m, BOOL* isInvertible) {
    GLKMatrix4 rotated = m;
    GLKMatrix4 translated = GLKMatrix4Identity;

    // This is only going to work in very limited circumstances.
    // (ie, m is of the form translate(rotate(m))
    *isInvertible = true;

    std::swap(rotated.m01, rotated.m10);
    std::swap(rotated.m02, rotated.m20);
    std::swap(rotated.m12, rotated.m21);
    rotated.m30 = 0.f;
    rotated.m31 = 0.f;
    rotated.m32 = 0.f;

    translated.m30 = -m.m30;
    translated.m31 = -m.m31;
    translated.m32 = -m.m32;

    return GLKMatrix4Multiply(rotated, translated);
}

GLKMatrix4 GLKMatrix4MakeRotation(float rad, float x, float y, float z) {
    float magn = 1.0f / sqrtf(x * x + y * y + z * z);
    x *= magn;
    y *= magn;
    z *= magn;

    GLKMatrix4 res = { 0 };

    res.m00 = 1.0f + (1 - cosf(rad)) * (x * x - 1);
    res.m10 = -z * sinf(rad) + (1.0f - cosf(rad)) * x * y;
    res.m20 = y * sinf(rad) + (1.0f - cosf(rad)) * x * z;
    res.m01 = z * sinf(rad) + (1.0f - cosf(rad)) * x * y;
    res.m11 = 1.0f + (1.0f - cosf(rad)) * (y * y - 1.0f);
    res.m21 = -x * sinf(rad) + (1.0f - cosf(rad)) * y * z;
    res.m02 = -y * sinf(rad) + (1.0f - cosf(rad)) * x * z;
    res.m12 = x * sinf(rad) + (1.0f - cosf(rad)) * y * z;
    res.m22 = 1.0f + (1.0f - cosf(rad)) * (z * z - 1.0f);
    res.m33 = 1.0f;

    return res;
}

GLKMatrix4 GLKMatrix4MakeXRotation(float rad) {
    GLKMatrix4 res = { 0 };

    res.m00 = 1.f;
    res.m11 = res.m22 = cosf(rad);
    res.m12 = -sinf(rad);
    res.m21 = sinf(rad);
    res.m33 = 1.0f;

    return res;
}

GLKMatrix4 GLKMatrix4MakeYRotation(float rad) {
    GLKMatrix4 res = { 0 };

    res.m11 = 1.f;
    res.m00 = res.m22 = cosf(rad);
    res.m02 = -sinf(rad);
    res.m20 = sinf(rad);
    res.m33 = 1.0f;

    return res;
}

GLKMatrix4 GLKMatrix4MakeZRotation(float rad) {
    GLKMatrix4 res = { 0 };

    res.m00 = res.m11 = cosf(rad);
    res.m01 = -sinf(rad);
    res.m10 = sinf(rad);
    res.m22 = 1.f;
    res.m33 = 1.0f;

    return res;
}

GLKMatrix4 GLKMatrix4MakeTranslation(float x, float y, float z) {
    GLKMatrix4 res = GLKMatrix4Identity;

    res.m30 = x;
    res.m31 = y;
    res.m32 = z;

    return res;
}

GLKMatrix4 GLKMatrix4MakeScale(float x, float y, float z) {
    GLKMatrix4 res = { 0 };

    res.m00 = x;
    res.m11 = y;
    res.m22 = z;
    res.m33 = 1.f;

    return res;
}
