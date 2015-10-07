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

#ifndef _CATRANSFORM3D_H_
#define _CATRANSFORM3D_H_

#import <Foundation/NSValue.h>
#import <QuartzCore/CABase.h>
#import <CoreGraphics/CGAffineTransform.h>

typedef struct CATransform3D {
    union {
        struct {
            float m11, m12, m13, m14;
            float m21, m22, m23, m24;
            float m31, m32, m33, m34;
            float m41, m42, m43, m44;
        };
        float m[4][4];
    };

#ifdef __cplusplus
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

    void MultiplyBy(struct CATransform3D *matrix);
    void RMultiplyBy(struct CATransform3D *matrix);
    
    void TransformPoints(struct CAPoint3D *points, int count);
    void TransformPoints2D(struct CGPoint *points, int count);
    
    void GetScale(float *scale);
    void GetPosition(float *position);
#endif
} CATransform3D;

struct CAPoint3D;

CA_EXPORT const CATransform3D CATransform3DIdentity;
CA_EXPORT CATransform3D CATransform3DMakeScale(CGFloat sx, CGFloat sy, CGFloat sz);
CA_EXPORT CATransform3D CATransform3DRotate(CATransform3D t, CGFloat angle, CGFloat x, CGFloat y, CGFloat z);
CA_EXPORT CATransform3D CATransform3DScale(CATransform3D t, CGFloat sx, CGFloat sy, CGFloat sz);
CA_EXPORT CATransform3D CATransform3DTranslate(CATransform3D t, CGFloat tx, CGFloat ty, CGFloat tz);
CA_EXPORT CATransform3D CATransform3DInvert(CATransform3D t);
CA_EXPORT CATransform3D CATransform3DMakeRotation(CGFloat angle, CGFloat x, CGFloat y, CGFloat z);
CA_EXPORT CATransform3D CATransform3DMakeOrtho(CGFloat left, CGFloat right, CGFloat bottom, CGFloat top, CGFloat near, CGFloat far);
CA_EXPORT CATransform3D CATransform3DConcat(CATransform3D a, CATransform3D b);
CA_EXPORT bool CATransform3DIsIdentity(CATransform3D t);
CA_EXPORT CATransform3D CATransform3DMakeTranslation(CGFloat tx, CGFloat ty, CGFloat tz);
CA_EXPORT bool CATransform3DIsAffine(CATransform3D t);
CA_EXPORT CGAffineTransform CATransform3DGetAffineTransform(CATransform3D t);
CA_EXPORT CATransform3D CATransform3DMakeAffineTransform (CGAffineTransform m);
CA_EXPORT void CATransform3DTransformPoints(CATransform3D a, struct CAPoint3D *points, int count);
CA_EXPORT void CATransform3DGetScale(CATransform3D a, float *scale);
CA_EXPORT void CATransform3DGetPosition(CATransform3D a, float *position);

@interface NSValue (CATransform3DAdditions)
+ (NSValue *)valueWithCATransform3D:(CATransform3D)t;
- (CATransform3D)CATransform3DValue;
@end

#endif /* _CATRANSFORM3D_H_ */