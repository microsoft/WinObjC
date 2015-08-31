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

#include <Starboard.h>
#include <GLKit/GLKMath.h>

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

