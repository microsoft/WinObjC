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

GLKMatrix3 GLKMatrix3MakeIdentity()
{
    GLKMatrix3 res;

    res.m11 = 1.f;
    res.m12 = 0.f;
    res.m13 = 0.f;

    res.m21 = 0.f;
    res.m22 = 1.f;
    res.m23 = 0.f;

    res.m31 = 0.f;
    res.m32 = 0.f;
    res.m33 = 1.f;

    return res;
}

GLKMatrix3 GLKMatrix3FromMatrix4(GLKMatrix4 m)
{
    GLKMatrix3 res;

    res.m11 = m.m11;
    res.m12 = m.m12;
    res.m13 = m.m13;

    res.m21 = m.m21;
    res.m22 = m.m22;
    res.m23 = m.m23;

    res.m31 = m.m31;
    res.m32 = m.m32;
    res.m33 = m.m33;

    return res;
}

GLKMatrix4 GLKMatrix4MakeIdentity()
{
    GLKMatrix4 res;

    res.m11 = 1.f;
    res.m12 = 0.f;
    res.m13 = 0.f;
    res.m14 = 0.f;

    res.m21 = 0.f;
    res.m22 = 1.f;
    res.m23 = 0.f;
    res.m24 = 0.f;

    res.m31 = 0.f;
    res.m32 = 0.f;
    res.m33 = 1.f;
    res.m34 = 0.f;

    res.m41 = 0.f;
    res.m42 = 0.f;
    res.m43 = 0.f;
    res.m44 = 1.f;

    return res;
}

GLKMatrix4 GLKMatrix4Make(float m00, float m01, float m02, float m03,
                          float m10, float m11, float m12, float m13,
                          float m20, float m21, float m22, float m23,
                          float m30, float m31, float m32, float m33)
{
    GLKMatrix4 res;

    res.m11 = m00;
    res.m12 = m01;
    res.m13 = m02;
    res.m14 = m03;

    res.m21 = m10;
    res.m22 = m11;
    res.m23 = m12;
    res.m24 = m13;

    res.m31 = m20;
    res.m32 = m21;
    res.m33 = m22;
    res.m34 = m23;

    res.m41 = m30;
    res.m42 = m31;
    res.m43 = m32;
    res.m44 = m33;

    return res;
}

GLKMatrix4 GLKMatrix4Transpose(GLKMatrix4 mat)
{
    std::swap(mat.m12, mat.m21);
    std::swap(mat.m13, mat.m31);
    std::swap(mat.m14, mat.m41);
    std::swap(mat.m23, mat.m32);
    std::swap(mat.m24, mat.m42);                     
    std::swap(mat.m34, mat.m43);
                     
    return mat;
}

GLKMatrix4 GLKMatrix4MakeAndTranspose(float m00, float m01, float m02, float m03,
                                      float m10, float m11, float m12, float m13,
                                      float m20, float m21, float m22, float m23,
                                      float m30, float m31, float m32, float m33)
{
    GLKMatrix4 res;

    res.m11 = m00;
    res.m21 = m01;
    res.m31 = m02;
    res.m41 = m03;
           
    res.m12 = m10;
    res.m22 = m11;
    res.m32 = m12;
    res.m42 = m13;
           
    res.m13 = m20;
    res.m23 = m21;
    res.m33 = m22;
    res.m43 = m23;
           
    res.m14 = m30;
    res.m24 = m31;
    res.m34 = m32;
    res.m44 = m33;

    return res;    
}

GLKMatrix4 GLKMatrix4MakeWithArray(float* values)
{
    GLKMatrix4 res;

    res.m11 = values[0];
    res.m12 = values[1];
    res.m13 = values[2];
    res.m14 = values[3];

    res.m21 = values[4];
    res.m22 = values[5];
    res.m23 = values[6];
    res.m24 = values[7];

    res.m31 = values[8];
    res.m32 = values[9];
    res.m33 = values[10];
    res.m34 = values[11];

    res.m41 = values[12];
    res.m42 = values[13];
    res.m43 = values[14];
    res.m44 = values[15];

    return res;
}

GLKMatrix4 GLKMatrix4MakeWithArrayAndTranspose(float* values)
{
    GLKMatrix4 res;

    res.m11 = values[0];
    res.m21 = values[1];
    res.m31 = values[2];
    res.m41 = values[3];
           
    res.m12 = values[4];
    res.m22 = values[5];
    res.m32 = values[6];
    res.m42 = values[7];
           
    res.m13 = values[8];
    res.m23 = values[9];
    res.m33 = values[10];
    res.m43 = values[11];
           
    res.m14 = values[12];
    res.m24 = values[13];
    res.m34 = values[14];
    res.m44 = values[15];

    return res;
}

GLKMatrix4 GLKMatrix4MakeWithColumns(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3)
{
    GLKMatrix4 res;

    res.m11 = r0.x;
    res.m21 = r0.y;
    res.m31 = r0.z;
    res.m41 = r0.w;
           
    res.m12 = r1.x;
    res.m22 = r1.y;
    res.m32 = r1.z;
    res.m42 = r1.w;
           
    res.m13 = r2.x;
    res.m23 = r2.y;
    res.m33 = r2.z;
    res.m43 = r2.w;
           
    res.m14 = r3.x;
    res.m24 = r3.y;
    res.m34 = r3.z;
    res.m44 = r3.w;

    return res;    
}

GLKMatrix4 GLKMatrix4MakeWithRows(GLKVector4 r0, GLKVector4 r1, GLKVector4 r2, GLKVector4 r3)
{
    GLKMatrix4 res;

    res.m11 = r0.x;
    res.m12 = r0.y;
    res.m13 = r0.z;
    res.m14 = r0.w;

    res.m21 = r1.x;
    res.m22 = r1.y;
    res.m23 = r1.z;
    res.m24 = r1.w;

    res.m31 = r2.x;
    res.m32 = r2.y;
    res.m33 = r2.z;
    res.m34 = r2.w;

    res.m41 = r3.x;
    res.m42 = r3.y;
    res.m43 = r3.z;
    res.m44 = r3.w;

    return res;    
}

GLKMatrix4 GLKMatrix4MakeOrthonormalXform(GLKVector3 right, GLKVector3 up, GLKVector3 forward, GLKVector3 pos)
{
    GLKMatrix4 res;

    res.m11 = right.x;
    res.m12 = up.x;
    res.m13 = forward.x;
    res.m14 = pos.x;

    res.m21 = right.y;
    res.m22 = up.y;
    res.m23 = forward.y;
    res.m24 = pos.y;

    res.m31 = right.z;
    res.m32 = up.z;
    res.m33 = forward.z;
    res.m34 = pos.z;

    res.m41 = 0.f;
    res.m42 = 0.f;
    res.m43 = 0.f;
    res.m44 = 1.f;

    return res;    
}

GLKMatrix4 GLKMatrix4MakeLookAt(float eyeX, float eyeY, float eyeZ,
                                float lookX, float lookY, float lookZ,
                                float upX, float upY, float upZ)
{
    GLKVector3 eye = GLKVector3Make(eyeX, eyeY, eyeZ);
    GLKVector3 fwd = GLKVector3Normalize(GLKVector3Subtract(GLKVector3Make(lookX, lookY, lookZ), eye));
    GLKVector3 up = GLKVector3Normalize(GLKVector3Make(upX, upY, upZ));
    GLKVector3 right = GLKVector3CrossProduct(up, fwd);
    
    return GLKMatrix4MakeOrthonormalXform(right, up, fwd, GLKVector3Negate(eye));
}

GLKMatrix4 GLKMatrix4MakeOrtho(float left, float right, float bot, float top, float near, float far)
{
    GLKMatrix4 res;

    res.m11 = 2.f / (right - left);
    res.m12 = 0.f;
    res.m13 = 0.f;
    res.m14 = (0.f - right - left) / (right - left);

    res.m21 = 0.f;
    res.m22 = 2.f / (top - bot);
    res.m23 = 0.f;
    res.m24 = (0.f - top - bot) / (top - bot);

    res.m31 = 0.f;
    res.m32 = 0.f;
    res.m33 = -2.f / (far - near);
    res.m34 = (far + near) / (far - near);

    res.m41 = 0.f;
    res.m42 = 0.f;
    res.m43 = 0.f;
    res.m44 = 1.f;

    return res;
}

GLKMatrix4 GLKMatrix4MakePerspective(float yrad, float aspect, float near, float far)
{
    float yd = tanf(yrad / 2.f) * near;
    float xd = tanf(aspect * yrad / 2.f) * near;

    return GLKMatrix4MakeFrustum(-xd, xd, -yd, yd, near, far);
}

GLKMatrix4 GLKMatrix4MakeFrustum(float left, float right, float bottom, float top, float near, float far)
{
    GLKMatrix4 res;

    res.m11 = (2.f * near) / (right - left);
    res.m12 = 0.f;
    res.m13 = (right + left) / (right - left);
    res.m14 = 0.f;

    res.m21 = 0.f;
    res.m22 = (2.f * near) / (top - bottom);
    res.m23 = (top + bottom) / (top - bottom);
    res.m24 = 0.f;

    res.m31 = 0.f;
    res.m32 = 0.f;
    res.m33 = (far + near) / (near - far);
    res.m34 = (2.f * far * near) / (near - far);

    res.m41 = 0.f;
    res.m42 = 0.f;
    res.m43 = -1.f;
    res.m44 = 0.f;
    
    return res;
}

GLKMatrix4 GLKMatrix4Multiply(GLKMatrix4 m1, GLKMatrix4 m2)
{
    GLKMatrix4 res;

    res.m11 = m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31 + m1.m14 * m2.m41;
    res.m12 = m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32 + m1.m14 * m2.m42;
    res.m13 = m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33 + m1.m14 * m2.m43;
    res.m14 = m1.m11 * m2.m14 + m1.m12 * m2.m24 + m1.m13 * m2.m34 + m1.m14 * m2.m44;

    res.m21 = m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31 + m1.m24 * m2.m41;
    res.m22 = m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32 + m1.m24 * m2.m42;
    res.m23 = m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33 + m1.m24 * m2.m43;
    res.m24 = m1.m21 * m2.m14 + m1.m22 * m2.m24 + m1.m23 * m2.m34 + m1.m24 * m2.m44;

    res.m31 = m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31 + m1.m34 * m2.m41;
    res.m32 = m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32 + m1.m34 * m2.m42;
    res.m33 = m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33 + m1.m34 * m2.m43;
    res.m34 = m1.m31 * m2.m14 + m1.m32 * m2.m24 + m1.m33 * m2.m34 + m1.m34 * m2.m44;

    res.m41 = m1.m41 * m2.m11 + m1.m42 * m2.m21 + m1.m43 * m2.m31 + m1.m44 * m2.m41;
    res.m42 = m1.m41 * m2.m12 + m1.m42 * m2.m22 + m1.m43 * m2.m32 + m1.m44 * m2.m42;
    res.m43 = m1.m41 * m2.m13 + m1.m42 * m2.m23 + m1.m43 * m2.m33 + m1.m44 * m2.m43;
    res.m44 = m1.m41 * m2.m14 + m1.m42 * m2.m24 + m1.m43 * m2.m34 + m1.m44 * m2.m44;
    
    return res;
}

GLKMatrix3 GLKMatrix3Make(float m00, float m01, float m02,
                          float m10, float m11, float m12,
                          float m20, float m21, float m22)
{
    GLKMatrix3 res;

    res.m11 = m00;
    res.m12 = m01;
    res.m13 = m02;

    res.m21 = m10;
    res.m22 = m11;
    res.m23 = m12;

    res.m31 = m20;
    res.m32 = m21;
    res.m33 = m22;

    return res;
}

GLKMatrix4 GLKMatrix3Transpose(GLKMatrix4 mat)
{
    std::swap(mat.m12, mat.m21);
    std::swap(mat.m13, mat.m31);
    std::swap(mat.m23, mat.m32);

    return mat;
}

GLKMatrix3 GLKMatrix3MakeAndTranspose(float m00, float m01, float m02,
                                      float m10, float m11, float m12,
                                      float m20, float m21, float m22)
{
    GLKMatrix3 res;

    res.m11 = m00;
    res.m21 = m01;
    res.m31 = m02;
           
    res.m12 = m10;
    res.m22 = m11;
    res.m32 = m12;
           
    res.m13 = m20;
    res.m23 = m21;
    res.m33 = m22;

    return res;
}

GLKMatrix3 GLKMatrix3MakeWithArray(float* values)
{
    GLKMatrix3 res;

    res.m11 = values[0];
    res.m12 = values[1];
    res.m13 = values[2];
           
    res.m21 = values[3];
    res.m22 = values[4];
    res.m23 = values[5];
           
    res.m31 = values[6];
    res.m32 = values[7];
    res.m33 = values[8];

    return res;
}

GLKMatrix3 GLKMatrix3MakeWithArrayAndTranspose(float* values)
{
    GLKMatrix3 res;

    res.m11 = values[0];
    res.m21 = values[1];
    res.m31 = values[2];
           
    res.m12 = values[3];
    res.m22 = values[4];
    res.m32 = values[5];
           
    res.m13 = values[6];
    res.m23 = values[7];
    res.m33 = values[8];

    return res;
}

GLKMatrix3 GLKMatrix3MakeWithColumns(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2)
{
    GLKMatrix3 res;

    res.m11 = r0.x;
    res.m21 = r0.y;
    res.m31 = r0.z;
           
    res.m12 = r1.x;
    res.m22 = r1.y;
    res.m32 = r1.z;
           
    res.m13 = r2.x;
    res.m23 = r2.y;
    res.m33 = r2.z;

    return res;
}

GLKMatrix3 GLKMatrix3MakeWithRows(GLKVector3 r0, GLKVector3 r1, GLKVector3 r2)
{
    GLKMatrix3 res;

    res.m11 = r0.x;
    res.m12 = r0.y;
    res.m13 = r0.z;
           
    res.m21 = r1.x;
    res.m22 = r1.y;
    res.m23 = r1.z;
           
    res.m31 = r2.x;
    res.m32 = r2.y;
    res.m33 = r2.z;

    return res;
}

GLKMatrix4 GLKMatrix4Rotate(GLKMatrix4 m, float rad, float x, float y, float z)
{
    GLKMatrix4 r = GLKMatrix4MakeRotation(rad, x, y, z);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4RotateX(GLKMatrix4 m, float rad)
{
    GLKMatrix4 r = GLKMatrix4MakeXRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4RotateY(GLKMatrix4 m, float rad)
{
    GLKMatrix4 r = GLKMatrix4MakeYRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4RotateZ(GLKMatrix4 m, float rad)
{
    GLKMatrix4 r = GLKMatrix4MakeZRotation(rad);
    return GLKMatrix4Multiply(m, r);
}

GLKMatrix4 GLKMatrix4Translate(GLKMatrix4 m, float x, float y, float z)
{
    GLKMatrix4 t = GLKMatrix4MakeTranslation(x, y, z);
    return GLKMatrix4Multiply(m, t);
}

GLKMatrix4 GLKMatrix4Scale(GLKMatrix4 m, float x, float y, float z)
{
    GLKMatrix4 s = GLKMatrix4MakeScale(x, y, z);
    return GLKMatrix4Multiply(m, s);
}


GLKVector3 GLKMatrix4MultiplyVector3(GLKMatrix4 m, GLKVector3 vec)
{
    GLKVector3 res;

    res.x = m.m11 * vec.x + m.m21 * vec.y + m.m31 * vec.z;
    res.y = m.m12 * vec.x + m.m22 * vec.y + m.m32 * vec.z;
    res.z = m.m13 * vec.x + m.m23 * vec.y + m.m33 * vec.z;

    return res;
}

GLKVector3 GLKMatrix4MultiplyVector3WithTranslation(GLKMatrix4 m, GLKVector3 vec)
{
    GLKVector3 res;

    res.x = m.m11 * vec.x + m.m21 * vec.y + m.m31 * vec.z + m.m41;
    res.y = m.m12 * vec.x + m.m22 * vec.y + m.m32 * vec.z + m.m42;
    res.z = m.m13 * vec.x + m.m23 * vec.y + m.m33 * vec.z + m.m43;

    return res;
}

void GLKMatrix4MultiplyVector3ArrayWithTranslation(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs)
{
    for(size_t i = 0; i < numVecs; i ++) vecs[i] = GLKMatrix4MultiplyVector3WithTranslation(m, vecs[i]);
}

GLKVector4 GLKMatrix4MultiplyVector4(GLKMatrix4 m, GLKVector4 vec)
{
    GLKVector4 res;

    res.x = m.m11 * vec.x + m.m21 * vec.y + m.m31 * vec.z + m.m41 * vec.w;
    res.y = m.m12 * vec.x + m.m22 * vec.y + m.m32 * vec.z + m.m42 * vec.w;
    res.z = m.m13 * vec.x + m.m23 * vec.y + m.m33 * vec.z + m.m43 * vec.w;
    res.w = m.m14 * vec.x + m.m24 * vec.y + m.m34 * vec.z + m.m44 * vec.w;

    return res;
}

void GLKMatrix4MultiplyVector3Array(GLKMatrix4 m, GLKVector3* vecs, size_t numVecs)
{
    for(size_t i = 0; i < numVecs; i ++) vecs[i] = GLKMatrix4MultiplyVector3(m, vecs[i]);
}

void GLKMatrix4MultiplyVector4Array(GLKMatrix4 m, GLKVector4* vecs, size_t numVecs)
{
    for(size_t i = 0; i < numVecs; i ++) vecs[i] = GLKMatrix4MultiplyVector4(m, vecs[i]);
}

GLKMatrix4 GLKMatrix4Invert(GLKMatrix4 m, BOOL* isInvertible)
{
    GLKMatrix4 res = m;
    
    // This is only going to work in very limited circumstances.
    *isInvertible = true;

    std::swap(res.m12, res.m21);
    std::swap(res.m13, res.m31);
    std::swap(res.m23, res.m32);
    res.m14 = -res.m14;
    res.m24 = -res.m24;
    res.m34 = -res.m34;
    
    return res;
}
