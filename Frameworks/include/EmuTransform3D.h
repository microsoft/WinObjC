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

#ifndef __EMUTRANSFORM3D
#define __EMUTRANSFORM3D

// WARNING: the member variable names here are for a row-major matrix.  However,
// the various functions use matrices in a column-major way.  (See MakeTranslation).
// therefore, the indices below are backwards.  To access the 4th row and 3rd column,
// you would need to use m34 below.  (Again, see MakeTranslation for an example).
//
struct CATransform3D {
    union {
        struct {
            float m11, m12, m13, m14;
            float m21, m22, m23, m24;
            float m31, m32, m33, m34;
            float m41, m42, m43, m44;
        };
        float m[4][4];
    };

    void MakeIdentity();

    void Translate(float tx, float ty, float tz);

    void MakeTranslation(float tx, float ty, float tz);
    void MakeRotation(float angle, float x, float y, float z);
    void MakeScale(float x, float y, float z);
    void MakeOrtho(float left, float right, float bottom, float top, float near, float far);

    void MultByTranslation(float tx, float ty, float tz);
    void MultByRotation(float angle, float x, float y, float z);
    void MultByScale(float x, float y, float z);
    void MultByOrtho(float left, float right, float bottom, float top, float near, float far);

    void MultiplyBy(struct CATransform3D* matrix);
    void RMultiplyBy(struct CATransform3D* matrix);

    void TransformPoints(struct CAPoint3D* points, int count);
    void TransformPoints2D(struct CGPoint* points, int count);

    void GetScale(float* scale);
    void GetPosition(float* position);

    void Transpose();
    void TransposeFrom(const float* matrix);
    void TransposeTo(float* matrix) const;
};

CATransform3D CATransform3DMakeTranslation(float x, float y, float z);
CATransform3D CATransform3DTranslate(CATransform3D cur, float x, float y, float z);
CATransform3D CATransform3DConcat(CATransform3D a, CATransform3D b);
void CATransform3DTransformPoints(CATransform3D a, CAPoint3D* points, int count);
void CATransform3DGetScale(CATransform3D a, float* scale);
#endif
