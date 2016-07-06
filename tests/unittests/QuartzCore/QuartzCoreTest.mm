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

#include <TestFramework.h>

#import <QuartzCore/QuartzCore.h>

#include <math.h>
#include <windows.h>

struct Dword32 {
    union {
        unsigned int u32;
        float f32;
    };
};

static const float c_ComparisonEpsilon = 0.0000025f;

static void checkMatrixWithinTolerance(const char* errorString,
                                       const void* matrixTypeless,
                                       const void* goldenMatrixTypeless,
                                       int dimension = 4,
                                       float tolerance = c_ComparisonEpsilon) {
    const Dword32* matrix = reinterpret_cast<const Dword32*>(matrixTypeless);
    const Dword32* goldenMatrix = reinterpret_cast<const Dword32*>(goldenMatrixTypeless);

    assert(dimension <= 4);

    int index = 0;

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            // Catch cases where element data are for all relevant intents and purposes identical but 
            // ASSERT_NEAR and ASSERT_EQ identifies as different.
            // Specifically, ASSERT_NEAR incorrectly marks +/- NaN values as not being identical.
            if (matrix[index].u32 != goldenMatrix[index].u32) {
                ASSERT_NEAR_MSG(matrix[index].f32,
                                goldenMatrix[index].f32,
                                tolerance,
                                "TEST FAILED: %s \n\tMatrix mismatch at M[%i][%i]\n\t\tGOLDEN: %f\n\t\tACTUAL: %f\n",
                                errorString,
                                i,
                                j,
                                goldenMatrix[index].f32,
                                matrix[index].f32);
            }

            index++;
        }
    }
}

TEST(QuartzCore, MatrixMath) {
    const float rotAngle = M_PI / 3.0f;
    const float rotAxis[3] = { 1.0f, 0.0f, 0.0f };
    const float trans[3] = { 5.0f, 5.0f, 5.0f };

    const Dword32 transGolden[16] = {
        0x3F800000, 0x00000000, 0x00000000, 0x00000000, 
        0x00000000, 0x3F800000, 0x00000000, 0x00000000,
        0x00000000, 0x00000000, 0x3F800000, 0x00000000, 
        0x40a00000, 0x40a00000, 0x40a00000, 0x3F800000,
    };

    const Dword32 rotGolden[16] = {
        0x3F800000, 0x00000000, 0x00000000, 0x00000000, 
        0x00800000, 0x3EFFFFFF, 0x3F5DB3D8, 0x00000000,
        0x00000000, 0xBF5DB3D8, 0x3EFFFFFF, 0x00000000, 
        0x00000000, 0x00000000, 0x00000000, 0x3F800000,
    };

    const Dword32 rotTransGolden[16] = {
        0x3F800000, 0x00000000, 0x00000000, 0x00000000, 
        0x00800000, 0x3EFFFFFF, 0x3F5DB3D8, 0x00000000,
        0x00000000, 0xBF5DB3D8, 0x3EFFFFFF, 0x00000000, 
        0x40a00000, 0x40a00000, 0x40a00000, 0x3F800000,
    };

    const size_t matrixSizeBytes = 16 * sizeof(float);

    // Generate rotation matrix
    CATransform3D rotMatrix = CATransform3DMakeRotation(rotAngle, rotAxis[0], rotAxis[1], rotAxis[2]);
    checkMatrixWithinTolerance("FAILED: CATransform3DMakeRotation", rotMatrix.m[0], rotGolden);

    // Generate translation matrix
    CATransform3D transMatrix = CATransform3DMakeTranslation(trans[0], trans[1], trans[2]);
    checkMatrixWithinTolerance("FAILED: CATransform3DMakeTranslation", transMatrix.m[0], transGolden);

    // Rotation + Translation via Concat of above matrices
    CATransform3D rotTransMatrixConcat = CATransform3DConcat(rotMatrix, transMatrix);
    checkMatrixWithinTolerance("FAILED: CATransform3DConcat", rotTransMatrixConcat.m[0], rotTransGolden);

    // Rotation + Translation via premultiply methods CATransform3DTranslate and CATransform3DRotate
    CATransform3D rotTransMatrixPreMul = CATransform3DTranslate(CATransform3DIdentity, trans[0], trans[1], trans[2]);

    // Pre-multiply rotation matrix to get matrix which rotates then translates
    rotTransMatrixPreMul = CATransform3DRotate(rotTransMatrixPreMul, rotAngle, rotAxis[0], rotAxis[1], rotAxis[2]);
    checkMatrixWithinTolerance("FAILED: CATransform3DTranslate and CATransform3dRotate", rotTransMatrixPreMul.m[0], rotTransGolden);
}