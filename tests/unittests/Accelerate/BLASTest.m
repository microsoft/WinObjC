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
#import <Foundation/Foundation.h>
#import <Accelerate/Accelerate.h>

/* Note the following abbreviations used at the beginnings of variable and function names:
d - Double precision real values
s - Single precision real values
z - Double precision complex values
c - Single precision complex values

Complex values are stored as {real0, imag0, real1, imag1, ..., realN, imagN}
*/

// Constants for sizes of arrays and scaling factors
const int arraySize = 9;
const int vectorSize = 3;
const int matrixN = 3;
const int matrixM = 3;
const int matrixK = 3;
const int leadingDimension = 3;
const double noScale = 1.0;
const int arrayStride = 1;
const double zeroScale = 0.0;
const double scaleUp = 3.0;
const double zScaleFactor[2] = {1.0, 0.0};
const double zScaleFactor2[2] = {1.0, 1.0};
const double zScaleFactor3[2] = {-1.0, 2.5};
const double zZeroScale[2] = {0.0, 0.0};
const float cScaleFactor[2] = {1.0f, 0.0f};
const float cScaleFactor2[2] = {1.0f, 1.0f};
const float cScaleFactor3[2] = {-1.0, 2.5};
const float cZeroScale[2] = {0.0f, 0.0f};

// Arrays (Matrices) used for tests
double dMatrixA[arraySize];
double dMatrixB[arraySize];
double dMatrixC[arraySize]; // Base DP arrays (3x3 matrices)
double zMatrixA[2*arraySize];
double zMatrixB[2*arraySize];
double zMatrixC[2*arraySize]; // Complex DP arrays
double dTriangularMatrixA[arraySize];
double dTriangularMatrixB[arraySize]; // Used for triangular matrix system of equations
double zTriangularMatrixA[2*arraySize];
double zTriangularMatrixB[2*arraySize]; // Used for complex triangular matrix system of equations

float sMatrixA[arraySize];
float sMatrixB[arraySize];
float sMatrixC[arraySize]; // Base SP arrays (3x3 matrices)
float cMatrixA[2*arraySize];
float cMatrixB[2*arraySize];
float cMatrixC[2*arraySize]; // Complex SP arrays
float sTriangularMatrixA[arraySize];
float sTriangularMatrixB[arraySize]; // SP version of triangular matrices
float cTriangularMatrixA[2*arraySize];
float cTriangularMatrixB[2*arraySize]; // SP complex version of triangular matrices

// Smaller vectors for matrix * vector calculations
double dVectorX[vectorSize];
double dVectorY[vectorSize];
float sVectorX[vectorSize];
float sVectorY[vectorSize];
double zVectorX[2*vectorSize];
double zVectorY[2*vectorSize];
float cVectorX[2*vectorSize];
float cVectorY[2*vectorSize];

// Globals needed by the error handling tests
char functionNameExpected[20];
int parameterPositionExpected;
int errorFlag = 0;

// Default values for matrices and arrays
double dMatrixADefaults[] = {4.3, -9.0, -2.3, 3.0, 0.0, -4.0, 5.9, -6.4, 9.5};
double dMatrixBDefaults[] = {-7.6, 9.6, -1.3, -1.1, -1.6, 7.4, 1.4, -3.5, -3.6};
double zMatrixADefaults[] = {-5.5, -6.4, -2.3, -1.4, -9.7, 0.3, 3.8, 4.4, -9.2, 3.1, 3.6, 6.7, 3.9, 8.8, -9.1, -8.0, 8.3, -1.5};
double zMatrixBDefaults[] = {-7.0, -3.7, 6.4, -0.7, -6.5, -0.6, 4.3, 0.4, -5.4, 2.9, 0.1, -6.8, -9.7, 7.7, 8.5, 8.7, 5.8, -3.2};
double dTriangularMatrixADefaults[] = {1.0, 4.0, 2.0, 0.0, 3.0, 4.0, 0.0, 0.0, 1.0};
double dTriangularMatrixBDefaults[] = {-9.2, -3.8, 21.1, 2.3, -18.8, 7.8, 1.4, -3.5, -3.6};
double zTriangularMatrixADefaults[] = {1.0, 0.0, 4.0, 0.0, 2.0, 0.0, 0.0, 0.0, 3.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0};
double zTriangularMatrixBDefaults[] = {-9.2, 13.3, 1.8, 28.3, 5.5, -34.2, -25.9, 32.0, 17.8, 43.5, 23.5, -33.2, -9.7, 7.7, 8.5, 8.7, 5.8, -3.2};

double dVectorXDefaults[] = {1.0, 2.0, 3.0};
double dVectorYDefaults[] = {0.0, 0.0, 0.0};
double zVectorXDefaults[] = {1.0, 1.0, 2.0, -1.0, 3.0, -1.5};
double zVectorYDefaults[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

// Custom error handler that checks values sent by xerbla against expected values
void BLASTestErrorProc(const char *functionName, const char *parameterName, const int *parameterPosition, const int *parameterValue) {
    ASSERT_STREQ_MSG(functionNameExpected, functionName, "XERBLA TEST FAILED, NAME MISMATCH: EXPECTED: %s FOUND: %s", functionNameExpected, functionName);
    ASSERT_EQ_MSG(*parameterPosition, 
                  parameterPositionExpected, 
                  "XERBLA TEST FAILED, PARAM POS MISMATCH: EXPECTED: %i FOUND: %i FUNCTION: %s", 
                  parameterPositionExpected, 
                  *parameterPosition,
                  functionName);

    errorFlag = 1;
}

static void BLASInit(void) {
    // Array values for tests
    memcpy(dMatrixA, dMatrixADefaults, sizeof(dMatrixADefaults));
    memcpy(dMatrixB, dMatrixBDefaults, sizeof(dMatrixBDefaults));
    memset(dMatrixC, 0, sizeof(dMatrixC));
        
    memcpy(zMatrixA, zMatrixADefaults, sizeof(zMatrixADefaults));
    memcpy(zMatrixB, zMatrixBDefaults, sizeof(zMatrixBDefaults));
    memset(zMatrixC, 0, sizeof(zMatrixC));
        
    memcpy(dTriangularMatrixA, dTriangularMatrixADefaults, sizeof(dTriangularMatrixADefaults));
    memcpy(dTriangularMatrixB, dTriangularMatrixBDefaults, sizeof(dTriangularMatrixBDefaults));
        
    memcpy(zTriangularMatrixA, zTriangularMatrixADefaults, sizeof(zTriangularMatrixADefaults));
    memcpy(zTriangularMatrixB, zTriangularMatrixBDefaults, sizeof(zTriangularMatrixBDefaults));
    
    // Set vector values for the matrix * vector calls
    memcpy(dVectorX, dVectorXDefaults, sizeof(dVectorXDefaults));
    memset(dVectorY, 0, sizeof(dVectorY));
    memcpy(zVectorX, zVectorXDefaults, sizeof(zVectorXDefaults));
    memset(zVectorY, 0, sizeof(zVectorY));

    for (int i = 0; i < arraySize; i++) {
        sMatrixA[i] = static_cast<float>(dMatrixA[i]);
        sMatrixB[i] = static_cast<float>(dMatrixB[i]);
        sMatrixC[i] = static_cast<float>(dMatrixC[i]);
        sTriangularMatrixA[i] = static_cast<float>(dTriangularMatrixA[i]);
        sTriangularMatrixB[i] = static_cast<float>(dTriangularMatrixB[i]);
    } // Copy double matrices as floats

    for (int i = 0; i < 2*arraySize; i++) {
        cMatrixA[i] = static_cast<float>(zMatrixA[i]);
        cMatrixB[i] = static_cast<float>(zMatrixB[i]);
        cMatrixC[i] = static_cast<float>(zMatrixC[i]);
        cTriangularMatrixA[i] = static_cast<float>(zTriangularMatrixA[i]);
        cTriangularMatrixB[i] = static_cast<float>(zTriangularMatrixB[i]);
    } // Copy double matrices as floats

    for (int i = 0; i < vectorSize; i++) {
        sVectorX[i] = static_cast<float>(dVectorX[i]);
        sVectorY[i] = static_cast<float>(dVectorY[i]);
    } // Copy double arrays as floats

    for (int i = 0; i < 2*vectorSize; i++) {
        cVectorX[i] = static_cast<float>(zVectorX[i]);
        cVectorY[i] = static_cast<float>(zVectorY[i]);
    } // Copy double arrays as floats
}

static void resetMatrices(void) {
    memcpy(dMatrixA, dMatrixADefaults, sizeof(dMatrixADefaults));
    memcpy(dMatrixB, dMatrixBDefaults, sizeof(dMatrixBDefaults));
        
    memcpy(zMatrixA, zMatrixADefaults, sizeof(zMatrixADefaults));
    memcpy(zMatrixB, zMatrixBDefaults, sizeof(zMatrixBDefaults));

    for (int i = 0; i < arraySize; i++) {
        sMatrixA[i] = static_cast<float>(dMatrixA[i]);
        sMatrixB[i] = static_cast<float>(dMatrixB[i]);
    }

    for (int i = 0; i < 2*arraySize; i++) {
        cMatrixA[i] = static_cast<float>(zMatrixA[i]);
        cMatrixB[i] = static_cast<float>(zMatrixB[i]);
    }
}

static void resetVectors(void) {
    memcpy(dVectorX, dVectorXDefaults, sizeof(dVectorXDefaults));
    memset(dVectorY, 0, sizeof(dVectorY));
    memcpy(zVectorX, zVectorXDefaults, sizeof(zVectorXDefaults));
    memset(zVectorY, 0, sizeof(zVectorY));

    for (int i = 0; i < vectorSize; i++) {
        sVectorX[i] = static_cast<float>(dVectorX[i]);
        sVectorY[i] = static_cast<float>(dVectorY[i]);
    }

    for (int i = 0; i < 2*vectorSize; i++) {
        cVectorX[i] = static_cast<float>(zVectorX[i]);
        cVectorY[i] = static_cast<float>(zVectorY[i]);
    }
}

static void checkArraySingle(float* res, float* expected, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        ASSERT_NEAR_MSG(res[i], expected[i], 0.001, "TEST FAILED: %s AT INDEX %i\nEXPECTED: %f\nFOUND: %f", name, i, expected[i], res[i]);
    }
}

static void checkArrayDouble(double* res, double* expected, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        ASSERT_NEAR_MSG(res[i], expected[i], 0.001, "TEST FAILED: %s AT INDEX %i\nEXPECTED: %f\nFOUND: %f", name, i, expected[i], res[i]);
    }
}

TEST(Accelerate, BLASDPReal) {
    BLASInit();

    // Process: call the cblas function, create array to hold expected result, then check if the results match
    // Results obtained by running the API call on Mac and recording the output
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                dMatrixA, 
                leadingDimension, 
                dMatrixB, 
                leadingDimension, 
                noScale, 
                dMatrixC, 
                leadingDimension);
    double dgemmExpected[] = {-26,63.73,-63.91,-28.4,42.8,10.5,-24.5,33.63,-89.23};
    checkArrayDouble(dMatrixC, dgemmExpected, 9, "dgemm");

    cblas_dtrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                dTriangularMatrixA, 
                leadingDimension, 
                dTriangularMatrixB, 
                leadingDimension);
    double dtrsmExpected[] = {-7.6,9.6,-1.3,-1.1,-1.6,7.4,1.4,-3.5,-3.6};
    checkArrayDouble(dTriangularMatrixB, dtrsmExpected, 9, "dtrsm");

    cblas_dgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, dMatrixA, leadingDimension, dVectorX, arrayStride, zeroScale, dVectorY, arrayStride);
    double dgemvExpected[] = {-20.6,-9,21.6};
    checkArrayDouble(dVectorY, dgemvExpected, 3, "dgemv");
    resetVectors();

    // Only 1 double is output as result, so checkArrayDouble doesn't need to be called
    double ddot_out = cblas_ddot(arraySize, dMatrixA, arrayStride, dMatrixB, arrayStride);
    double ddotExpected = -152.53;
    ASSERT_NEAR(ddot_out, ddotExpected, 0.0001);

    cblas_daxpy(arraySize, scaleUp, dMatrixA, arrayStride, dMatrixB, arrayStride);
    double daxpyExpected[] = {5.3,-17.4,-8.2,7.9,-1.6,-4.6,19.1,-22.7,24.9};
    checkArrayDouble(dMatrixB, daxpyExpected, 9, "daxpy");
    resetMatrices();
    // Modifies dMatrixB, make sure to reset it

    cblas_dscal(arraySize, scaleUp, dMatrixA, arrayStride);
    double dscalExpected[] = {12.9,-27,-6.9,9,0,-12,17.7,-19.2,28.5};
    checkArrayDouble(dMatrixA, dscalExpected, 9, "dscal");
    resetMatrices();
    // Modifies dMatrixA, make sure to reset it

    cblas_dsymm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                matrixM, 
                matrixN, 
                noScale, 
                dTriangularMatrixA, 
                leadingDimension, 
                dMatrixB, 
                leadingDimension, 
                zeroScale, 
                dTriangularMatrixB, 
                leadingDimension);
    double dsymmExpected[] = {-9.2,-3.8,21.1,-28.1,19.6,2.6,-18.2,9.3,23.4};
    checkArrayDouble(dTriangularMatrixB, dsymmExpected, 9, "dsymm");

    cblas_dtrmm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                dTriangularMatrixA, 
                leadingDimension, 
                dMatrixB, 
                leadingDimension);
    double dtrmmExpected[] = {-9.2,-3.8,21.1,2.3,-18.8,7.8,1.4,-3.5,-3.6};
    checkArrayDouble(dMatrixB, dtrmmExpected, 9, "dtrmm");
    resetMatrices();
    
    cblas_dsymv(CblasRowMajor, CblasUpper, matrixN, noScale, dTriangularMatrixA, leadingDimension, dVectorX, arrayStride, noScale, dVectorY, arrayStride);
    double dsymvExpected[] = {15,22,13};
    checkArrayDouble(dVectorY, dsymvExpected, 3, "dsymv");
    resetVectors();

    cblas_dtrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, dTriangularMatrixA, leadingDimension, dVectorX, arrayStride);
    double dtrmvExpected[] = {15,18,3};
    checkArrayDouble(dVectorX, dtrmvExpected, 3, "dtrmv");
    resetVectors();

    dVectorX[0] = 15.0; dVectorX[1] = 18.0; dVectorX[2] = 3.0;
    cblas_dtrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, dTriangularMatrixA, leadingDimension, dVectorX, arrayStride);
    double dtrsvExpected[] = {1,2,3};
    checkArrayDouble(dVectorX, dtrsvExpected, 3, "dtrsv");
    resetVectors();

    cblas_dswap(matrixN, dMatrixA, arrayStride, dMatrixB, arrayStride);
    double dswapExpected_A[] = {-7.6,9.6,-1.3};
    double dswapExpected_B[] = {4.3,-9,-2.3};
    checkArrayDouble(dMatrixA, dswapExpected_A, 3, "dswap_A");
    checkArrayDouble(dMatrixB, dswapExpected_B, 3, "dswap_B"); // check both arrays after the swap to ensure the values are both changed correctly
    resetMatrices();

    // Only 1 int is output as result, so checkArrayDouble doesn't need to be called
    int idamax_out = cblas_idamax(arraySize, dMatrixA, arrayStride);
    int idamaxExpected = 8;
    ASSERT_EQ(idamax_out, idamaxExpected);

    // Results saved to the copy array that's constantly modified
    cblas_dcopy(arraySize, dMatrixA, arrayStride, dMatrixA, arrayStride);
    double dcopyExpected[] = {4.3,-9.0,-2.3,3.0,0.0,-4.0,5.9,-6.4,9.5};
    checkArrayDouble(dMatrixA, dcopyExpected, 9, "dcopy");
    resetMatrices();

    double dasum_out = cblas_dasum(arraySize, dMatrixA, arrayStride);
    double dasumExpected = 44.4;
    ASSERT_NEAR(dasum_out, dasumExpected, 0.0001);

    double dnrm2_out = cblas_dnrm2(arraySize, dMatrixA, arrayStride);
    double dnrm2Expected = 17.1988;
    ASSERT_NEAR(dnrm2_out, dnrm2Expected, 0.0001);

    cblas_drot(arraySize, dMatrixA, arrayStride, dMatrixB, arrayStride, 0.866025, 0.5);
    double drotExpected_A[] = {-0.0760925,-2.99423,-2.64186,2.04807,-0.8,0.2359,5.80955,-7.29256,6.42724};
    double drotExpected_B[] = {-8.73179,12.8138,0.0241675,-2.45263,-1.38564,8.40859,-1.73757,0.168913,-7.86769};
    checkArrayDouble(dMatrixA, drotExpected_A, 9, "drot_A");
    checkArrayDouble(dMatrixB, drotExpected_B, 9, "drot_A"); // check both arrays after the swap to ensure the values are both changed correctly
    resetMatrices();

    // drotg needs specific array with 4 elements, the first two are inputs and all four are used as outputs
    double drotgvec[] = {4.3, -7.6, 0.0, 0.0};
    cblas_drotg(&drotgvec[0], &drotgvec[1], &drotgvec[2], &drotgvec[3]);
    double drotgExpected[] = {-8.73212,-2.03073,-0.492435,0.870349};
    checkArrayDouble(drotgvec, drotgExpected, 4, "drotg");

    cblas_dger(CblasRowMajor, matrixM, matrixN, noScale, dVectorX, arrayStride, dVectorX, arrayStride, dMatrixA, leadingDimension);
    double dgerExpected[] = {5.3,-7.0,0.7,5.0,4.0,2.0,8.9,-0.4,18.5};
    checkArrayDouble(dMatrixA, dgerExpected, 9, "dger");
    resetMatrices();

    cblas_dsyr(CblasRowMajor, CblasUpper, matrixN, noScale, dVectorX, arrayStride, dMatrixA, leadingDimension);
    double dsyrExpected[] = {5.3,-7.0,0.7,3.0,4.0,2.0,5.9,-6.4,18.5};
    checkArrayDouble(dMatrixA, dsyrExpected, 9, "dsyr");
    resetMatrices();

    cblas_dsyr2(CblasRowMajor, CblasUpper, matrixN, noScale, dVectorX, arrayStride, dVectorX, arrayStride, dMatrixA, leadingDimension);
    double dsyr2Expected[] = {6.3,-5.0,3.7,3.0,8.0,8.0,5.9,-6.4,27.5};
    checkArrayDouble(dMatrixA, dsyr2Expected, 9, "dsyr2");
    resetMatrices();

    memset(dMatrixC, 0, sizeof(dMatrixC));
    cblas_dsyr2k(CblasRowMajor, 
                 CblasUpper, 
                 CblasNoTrans, 
                 matrixN, 
                 matrixK, 
                 noScale, 
                 dMatrixA, 
                 leadingDimension, 
                 dMatrixB, 
                 leadingDimension, 
                 noScale, 
                 dMatrixC, 
                 leadingDimension);
    double dsyr2kExpected[] = {-232.18,-24.95,-72.83,0.0,-65.8,92.65,0.0,0.0,-7.08};
    checkArrayDouble(dMatrixC, dsyr2kExpected, 9, "dsyr2k");

    memset(dMatrixC, 0, sizeof(dMatrixC));
    cblas_dsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, matrixN, matrixK, noScale, dMatrixA, leadingDimension, noScale, dMatrixC, leadingDimension);
    double dsyrkExpected[] = {104.78,22.1,61.12,0,25,-20.3,0,0,166.02};
    checkArrayDouble(dMatrixC, dsyrkExpected, 9, "dsyrk");

    catlas_dset(arraySize, scaleUp, dMatrixC, arrayStride);
    double dsetExpected[] = {3,3,3,3,3,3,3,3,3};
    checkArrayDouble(dMatrixC, dsetExpected, 9, "dset");

    cblas_dgbmv(CblasRowMajor, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                1, // Bands above diagonal
                1, // Bands below diagonal
                noScale, 
                dMatrixA, 
                leadingDimension, 
                dVectorX, 
                arrayStride, 
                noScale, 
                dVectorX, 
                arrayStride);
    double dgbmvExpected[] = {-12.6,-47.8,-298.22};
    checkArrayDouble(dVectorX, dgbmvExpected, 3, "dgbmv");
    resetVectors();

    cblas_dspr(CblasRowMajor, CblasUpper, matrixN, noScale, dVectorX, arrayStride, dMatrixA);
    double dsprExpected[] = {5.3,-7,0.7,7,6,5,5.9,-6.4,9.5};
    checkArrayDouble(dMatrixA, dsprExpected, 9, "dspr");
    resetMatrices();

    cblas_dspr2(CblasRowMajor, CblasUpper, matrixN, noScale, dVectorX, arrayStride, dVectorX, arrayStride, dMatrixA);
    double dspr2Expected[] = {6.3,-5,3.7,11,12,14,5.9,-6.4,9.5};
    checkArrayDouble(dMatrixA, dspr2Expected, 9, "dspr2");
    resetMatrices();

    cblas_dtbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, 2, dMatrixA, leadingDimension, dVectorX, arrayStride);
    // K is set to 2 instead of matrixK because of banded format
    double dtbsvExpected[] = {1.89988,0.666667,0.508475};
    checkArrayDouble(dVectorX, dtbsvExpected, 3, "dtbsv");
    resetVectors();

    cblas_dtpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, dMatrixA, dVectorX, arrayStride);
    double dtpsvExpected[] = {1.22674,0.666667,-0.75};
    checkArrayDouble(dVectorX, dtpsvExpected, 3, "dtpsv");
    resetVectors();
}

TEST(Accelerate, BLASSPReal) { // See comments for DP Real Test
    BLASInit();

    cblas_sgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                sMatrixA, 
                leadingDimension, 
                sMatrixB, 
                leadingDimension, 
                noScale, 
                sMatrixC, 
                leadingDimension);
    float sgemmExpected[] = {-26.0f,63.73f,-63.91f,-28.4f,42.8f,10.5f,-24.5f,33.63f,-89.23f};
    checkArraySingle(sMatrixC, sgemmExpected, 9, "sgemm");

    cblas_strsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                sTriangularMatrixA, 
                leadingDimension, 
                sTriangularMatrixB, 
                leadingDimension);
    float strsmExpected[] = {-7.6f,9.6f,-1.3f,-1.1f,-1.6f,7.4f,1.4f,-3.5f,-3.6f};
    checkArraySingle(sTriangularMatrixB, strsmExpected, 9, "strsm");

    cblas_sgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, sMatrixA, leadingDimension, sVectorX, arrayStride, zeroScale, sVectorY, arrayStride);
    float sgemvExpected[] = {-20.6f,-9.0f,21.6f};
    checkArraySingle(sVectorY, sgemvExpected, 3, "sgemv");
    resetVectors();

    double sdot_out = cblas_sdot(arraySize, sMatrixA, arrayStride, sMatrixB, arrayStride);
    double sdotExpected = -152.53f;
    ASSERT_NEAR(sdot_out, sdotExpected, 0.0001);

    cblas_saxpy(arraySize, scaleUp, sMatrixA, arrayStride, sMatrixB, arrayStride);
    float saxpyExpected[] = {5.3f,-17.4f,-8.2f,7.9f,-1.6f,-4.6f,19.1f,-22.7f,24.9f};
    checkArraySingle(sMatrixB, saxpyExpected, 9, "saxpy");
    resetMatrices();

    cblas_sscal(arraySize, scaleUp, sMatrixA, arrayStride);
    float sscalExpected[] = {12.9f,-27.0f,-6.9f,9.0f,0.0f,-12.0f,17.7f,-19.2f,28.5f};
    checkArraySingle(sMatrixA, sscalExpected, 9, "sscal");
    resetMatrices();

    cblas_ssymm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                matrixM, 
                matrixN, 
                noScale, 
                sTriangularMatrixA, 
                leadingDimension, 
                sMatrixB, 
                leadingDimension, 
                zeroScale, 
                sTriangularMatrixB, 
                leadingDimension);
    float ssymmExpected[] = {-9.2f,-3.8f,21.1f,-28.1f,19.6f,2.6f,-18.2f,9.3f,23.4f};
    checkArraySingle(sTriangularMatrixB, ssymmExpected, 9, "ssymm");

    cblas_strmm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                sTriangularMatrixA, 
                leadingDimension, 
                sMatrixB, 
                leadingDimension);
    float strmmExpected[] = {-9.2f,-3.8f,21.1f,2.3f,-18.8f,7.8f,1.4f,-3.5f,-3.6f};
    checkArraySingle(sMatrixB, strmmExpected, 9, "strmm");
    resetMatrices();

    cblas_ssymv(CblasRowMajor, CblasUpper, matrixN, noScale, sTriangularMatrixA, leadingDimension, sVectorX, arrayStride, noScale, sVectorY, arrayStride);
    float ssymvExpected[] = {15.0f,22.0f,13.0f};
    checkArraySingle(sVectorY, ssymvExpected, 3, "ssymv");
    resetVectors();

    cblas_strmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, sTriangularMatrixA, leadingDimension, sVectorX, arrayStride);
    float strmvExpected[] = {15.0f,18.0f,3.0f};
    checkArraySingle(sVectorX, strmvExpected, 3, "strmv");
    resetVectors();

    sVectorX[0] = 15.0f; sVectorX[1] = 18.0f; sVectorX[2] = 3.0f;
    cblas_strsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, sTriangularMatrixA, leadingDimension, sVectorX, arrayStride);
    float strsvExpected[] = {1.0f,2.0f,3.0f};
    checkArraySingle(sVectorX, strsvExpected, 3, "strsv");
    resetVectors();

    cblas_sswap(matrixN, sMatrixA, arrayStride, sMatrixB, arrayStride);
    float sswapExpected_A[] = {-7.6f,9.6f,-1.3f};
    float sswapExpected_B[] = {4.3f,-9.0f,-2.3f};
    checkArraySingle(sMatrixA, sswapExpected_A, 3, "sswap_A");
    checkArraySingle(sMatrixB, sswapExpected_B, 3, "sswap_B");
    resetMatrices();

    int isamax_out = cblas_isamax(arraySize, sMatrixA, arrayStride);
    int isamaxExpected = 8;
    ASSERT_EQ(isamax_out, isamaxExpected);

    cblas_scopy(arraySize, sMatrixA, arrayStride, sMatrixB, arrayStride);
    float scopyExpected[] = {4.3f,-9.0f,-2.3f,3.0f,0.0f,-4.0f,5.9f,-6.4f,9.5f};
    checkArraySingle(sMatrixB, scopyExpected, 9, "scopy");
    resetMatrices();

    float sasum_out = cblas_sasum(arraySize, sMatrixA, arrayStride);
    float sasumExpected = 44.4;
    ASSERT_NEAR(sasum_out, sasumExpected, 0.0001);

    float snrm2_out = cblas_snrm2(arraySize, sMatrixA, arrayStride);
    float snrm2Expected = 17.1988f;
    ASSERT_NEAR(snrm2_out, snrm2Expected, 0.0001);

    cblas_srot(arraySize, sMatrixA, arrayStride, sMatrixB, arrayStride, 0.866025f, 0.5f);
    float srotExpected_A[] = {-0.0760925f,-2.99423f,-2.64186f,2.04807f,-0.8f,0.2359f,5.80955f,-7.29256f,6.42724f};
    float srotExpected_B[] = {-8.73179f,12.8138f,0.0241675f,-2.45263f,-1.38564f,8.40859f,-1.73757f,0.168913f,-7.86769f};
    checkArraySingle(sMatrixA, srotExpected_A, 9, "srot_A");
    checkArraySingle(sMatrixB, srotExpected_B, 9, "srot_B");
    resetMatrices();

    float srotgvec[] = {4.3f, -7.6f, 0.0f, 0.0f};
    cblas_srotg(&srotgvec[0], &srotgvec[1], &srotgvec[2], &srotgvec[3]);
    float srotgExpected[] = {-8.73212f,-2.03073f,-0.492435f,0.870349f};
    checkArraySingle(srotgvec, srotgExpected, 4, "srotg");

    cblas_sger(CblasRowMajor, matrixM, matrixN, noScale, sVectorX, arrayStride, sVectorX, arrayStride, sMatrixA, leadingDimension);
    float sgerExpected[] = {5.3f,-7.0f,0.7f,5.0f,4.0f,2.0f,8.9f,-0.4f,18.5f};
    checkArraySingle(sMatrixA, sgerExpected, 9, "sger");
    resetMatrices();

    cblas_ssyr(CblasRowMajor, CblasUpper, matrixN, noScale, sVectorX, arrayStride, sMatrixA, leadingDimension);
    float ssyrExpected[] = {5.3f,-7.0f,0.7f,3.0f,4.0f,2.0f,5.9f,-6.4f,18.5f};
    checkArraySingle(sMatrixA, ssyrExpected, 9, "ssyr");
    resetMatrices();

    cblas_ssyr2(CblasRowMajor, CblasUpper, matrixN, noScale, sVectorX, arrayStride, sVectorX, arrayStride, sMatrixA, leadingDimension);
    float ssyr2Expected[] = {6.3f,-5.0f,3.7f,3.0f,8.0f,8.0f,5.9f,-6.4f,27.5f};
    checkArraySingle(sMatrixA, ssyr2Expected, 9, "ssyr2");
    resetMatrices();

    memset(sMatrixC, 0, sizeof(sMatrixC));
    cblas_ssyr2k(CblasRowMajor, 
                 CblasUpper, 
                 CblasNoTrans, 
                 matrixN, 
                 matrixK, 
                 noScale, 
                 sMatrixA, 
                 leadingDimension, 
                 sMatrixB, 
                 leadingDimension, 
                 noScale, 
                 sMatrixC, 
                 leadingDimension);
    float ssyr2kExpected[] = {-232.18f,-24.95f,-72.83f,0.0f,-65.8f,92.65f,0.0f,0.0f,-7.08f};
    checkArraySingle(sMatrixC, ssyr2kExpected, 9, "ssyr2k");

    memset(sMatrixC, 0, sizeof(sMatrixC));
    cblas_ssyrk(CblasRowMajor, CblasUpper, CblasNoTrans, matrixN, matrixK, noScale, sMatrixA, leadingDimension, noScale, sMatrixC, leadingDimension);
    float ssyrkExpected[] = {104.78f,22.1f,61.12f,0.0f,25.0f,-20.3f,0.0f,0.0f,166.02f};
    checkArraySingle(sMatrixC, ssyrkExpected, 9, "ssyrk");

    catlas_sset(arraySize, scaleUp, sMatrixC, arrayStride);
    float ssetExpected[] = {3,3,3,3,3,3,3,3,3};
    checkArraySingle(sMatrixC, ssetExpected, 9, "sset");

    cblas_sgbmv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, 1, 1, noScale, sMatrixA, leadingDimension, sVectorX, arrayStride, noScale, sVectorX, arrayStride);
    float sgbmvExpected[] = {-12.6f,-47.8f,-298.22f};
    checkArraySingle(sVectorX, sgbmvExpected, 3, "sgbmv");
    resetVectors();

    cblas_sspr(CblasRowMajor, CblasUpper, matrixN, noScale, sVectorX, arrayStride, sMatrixA);
    float ssprExpected[] = {5.3f,-7.0f,0.7f,7.0f,6.0f,5.0f,5.9f,-6.4f,9.5f};
    checkArraySingle(sMatrixA, ssprExpected, 9, "sspr");
    resetMatrices();

    cblas_sspr2(CblasRowMajor, CblasUpper, matrixN, noScale, sVectorX, arrayStride, sVectorX, arrayStride, sMatrixA);
    float sspr2Expected[] = {6.3f,-5.0f,3.7f,11.0f,12.0f,14.0f,5.9f,-6.4f,9.5f};
    checkArraySingle(sMatrixA, sspr2Expected, 9, "sspr2");
    resetMatrices();

    cblas_stbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, 2, sMatrixA, leadingDimension, sVectorX, arrayStride);
    float stbsvExpected[] = {1.89988f,0.666667f,0.508475f};
    checkArraySingle(sVectorX, stbsvExpected, 3, "stbsv");
    resetVectors();

    cblas_stpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, sMatrixA, sVectorX, arrayStride);
    float stpsvExpected[] = {1.22674f,0.666667f,-0.75f};
    checkArraySingle(sVectorX, stpsvExpected, 3, "stpsv");
    resetVectors();
}

TEST(Accelerate, BLASDPComplex) { // See comments for DP Real Test
    BLASInit();

    cblas_zgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension, 
                zScaleFactor, 
                zMatrixC, 
                leadingDimension);
    double zgemmExpected[] = {97.27,
                          -19.39,
                          -108.26,
                          -118.06,
                          -33.14,
                          93.18,
                          -137.63,
                          -72.48,
                          40.4,
                          70.35,
                          40.42,
                          59.33,
                          -99.63,
                          -35.61,
                          187.06,
                          129.86,
                          -32.04,
                          -33.72};
    checkArrayDouble(zMatrixC, zgemmExpected, 18, "zgemm");

    cblas_ztrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                zScaleFactor, 
                zTriangularMatrixA, 
                leadingDimension, 
                zTriangularMatrixB, 
                leadingDimension);
    double ztrsmExpected[] = {-7,-3.7,6.4,-0.7,-6.5,-0.6,4.3,0.4,-5.4,2.9,0.1,-6.8,-9.7,7.7,8.5,8.7,5.8,-3.2};
    checkArrayDouble(zTriangularMatrixB, ztrsmExpected, 18, "ztrsm");

    cblas_zgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, zScaleFactor, zMatrixA, leadingDimension, zVectorX, arrayStride, zScaleFactor, zVectorY, arrayStride);
    double zgemvExpected[] = {-33.75,3.05,4.95,38.3,-8.45,-11.15};
    checkArrayDouble(zVectorY, zgemvExpected, 6, "zgemv");
    resetVectors();

    double zdotc_sub_out[2];
    cblas_zdotc_sub(arraySize, zMatrixA, arrayStride, zMatrixB, arrayStride, zdotc_sub_out);
    double zdotc_subExpected[] = {78.8,27.76};
    checkArrayDouble(zdotc_sub_out, zdotc_subExpected, 2, "zdotc_sub");

    double zdotu_sub_out[2];
    cblas_zdotu_sub(arraySize, zMatrixA, arrayStride, zMatrixB, arrayStride, zdotu_sub_out);
    double zdotu_subExpected[] = {93.54,-222.88};
    checkArrayDouble(zdotu_sub_out, zdotu_subExpected, 2, "zdotu_sub");

    cblas_zaxpy(arraySize, zScaleFactor2, zMatrixA, arrayStride, zMatrixB, arrayStride);
    double zaxpyExpected[] = {-6.1,-15.6,5.5,-4.4,-16.5,-10,3.7,8.6,-17.7,-3.2,-3,3.5,-14.6,20.4,7.4,-8.4,15.6,3.6};
    checkArrayDouble(zMatrixB, zaxpyExpected, 18, "zaxpy");
    resetMatrices();

    cblas_zscal(arraySize, zScaleFactor2, zMatrixA, arrayStride);
    double zscalExpected[] = {0.9,-11.9,-0.9,-3.7,-10,-9.4,-0.6,8.2,-12.3,-6.1,-3.1,10.3,-4.9,12.7,-1.1,-17.1,9.8,6.8};
    checkArrayDouble(zMatrixA, zscalExpected, 18, "zscal");
    resetMatrices();

    cblas_zdscal(arraySize, scaleUp, zMatrixA, arrayStride);
    double zdscalExpected[] = {-16.5,-19.2,-6.9,-4.2,-29.1,0.9,11.4,13.2,-27.6,9.3,10.8,20.1,11.7,26.4,-27.3,-24,24.9,-4.5};
    checkArrayDouble(zMatrixA, zdscalExpected, 18, "zdscal");
    resetMatrices();

    cblas_zsymm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                matrixM, 
                matrixN, 
                zScaleFactor, 
                zTriangularMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension, 
                zZeroScale, 
                zTriangularMatrixB, 
                leadingDimension);
    double zsymmExpected[] = {-9.2,13.3,1.8,28.3,5.5,-34.2,-53.9,17.2,43.4,40.7,-2.5,-35.6,-6.5,1.9,-0.3,18.9,-6.8,-31.6};
    checkArrayDouble(zTriangularMatrixB, zsymmExpected, 18, "zsymm");

    cblas_ztrmm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                zScaleFactor, 
                zTriangularMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension);
    double ztrmmExpected[] = {-9.2,13.3,1.8,28.3,5.5,-34.2,-25.9,32,17.8,43.5,23.5,-33.2,-9.7,7.7,8.5,8.7,5.8,-3.2};
    checkArrayDouble(zMatrixB, ztrmmExpected, 18, "ztrmm");
    resetMatrices();

    cblas_zhemv(CblasRowMajor, CblasUpper, matrixN, zScaleFactor, zTriangularMatrixA, leadingDimension, zVectorX, arrayStride, zScaleFactor, zVectorY, arrayStride);
    double zhemvExpected[] = {15,-6,22,-5,13,-3.5};
    checkArrayDouble(zVectorY, zhemvExpected, 6, "zhemv");
    resetVectors();

    cblas_ztrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, zTriangularMatrixA, leadingDimension, zVectorX, arrayStride);
    double ztrmvExpected[] = {15,-6,18,-9,3,-1.5};
    checkArrayDouble(zVectorX, ztrmvExpected, 6, "ztrmv");
    resetVectors();

    zVectorX[0] = 15.0; zVectorX[1] = -6.0; zVectorX[2] = 18.0; zVectorX[3] = -9.0; zVectorX[4] = 3.0; zVectorX[5] = -1.5;
    cblas_ztrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, zTriangularMatrixA, leadingDimension, zVectorX, arrayStride);
    double ztrsvExpected[] = {1,1,2,-1,3,-1.5};
    checkArrayDouble(zVectorX, ztrsvExpected, 6, "ztrsv");
    resetVectors();

    cblas_zswap(matrixN, zMatrixA, arrayStride, zMatrixB, arrayStride);
    double zswapExpected_A[] = {-7,-3.7,6.4,-0.7,-6.5,-0.6};
    double zswapExpected_B[] = {-5.5,-6.4,-2.3,-1.4,-9.7,0.3};
    checkArrayDouble(zMatrixA, zswapExpected_A, 6, "zswap_A");
    checkArrayDouble(zMatrixB, zswapExpected_B, 6, "zswap_B");
    resetMatrices();

    int izamax_out = cblas_izamax(arraySize, zMatrixA, arrayStride);
    int izamaxExpected = 7;
    ASSERT_EQ(izamax_out, izamaxExpected);

    cblas_zcopy(arraySize, zMatrixA, arrayStride, zMatrixB, arrayStride);
    double zcopyExpected[] = {-5.5,-6.4,-2.3,-1.4,-9.7,0.3,3.8,4.4,-9.2,3.1,3.6,6.7,3.9,8.8,-9.1,-8,8.3,-1.5};
    checkArrayDouble(zMatrixB, zcopyExpected, 18, "zcopy");
    resetMatrices();

    double dzasum_out = cblas_dzasum(arraySize, zMatrixA, arrayStride);
    double dzasumExpected = 96.0;
    ASSERT_NEAR(dzasum_out, dzasumExpected, 0.0001);

    double dznrm2_out = cblas_dznrm2(arraySize, zMatrixA, arrayStride);
    double dznrm2Expected = 25.8677;
    ASSERT_NEAR(dznrm2_out, dznrm2Expected, 0.0001);

    // Setting up the Y vector for this
    cblas_zgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, zScaleFactor, zMatrixA, leadingDimension, zVectorX, arrayStride, zScaleFactor, zVectorY, arrayStride);

    cblas_zgerc(CblasRowMajor, matrixM, matrixN, zScaleFactor, zVectorX, arrayStride, zVectorY, arrayStride, zMatrixA, leadingDimension);
    double zgercExpected[] = {-36.2,
                          -43.2,
                          40.95,
                          -34.75,
                          -29.3,
                          3.0,
                          -66.75,
                          32.05,
                          -37.6,
                          -78.45,
                          -2.15,
                          37.45,
                          -101.925,
                          50.275,
                          -51.7,
                          -130.325,
                          -0.325,
                          44.625};
    checkArrayDouble(zMatrixA, zgercExpected, 18, "zgerc");
    resetMatrices();

    cblas_zgeru(CblasRowMajor, matrixM, matrixN, zScaleFactor, zVectorX, arrayStride, zVectorY, arrayStride, zMatrixA, leadingDimension);
    double zgeruExpected[] = {-42.3,-37.1,-35.65,41.85,-7,-19.3,-60.65,44.25,39,74.75,-24.45,-7.15,-92.775,68.575,63.2,99.475,-33.775,-22.275};
    checkArrayDouble(zMatrixA, zgeruExpected, 18, "zgeru");
    resetMatrices();

    memset(zMatrixC, 0, sizeof(zMatrixC));
    cblas_zhemm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                matrixM, 
                matrixN, 
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension, 
                zScaleFactor, 
                zMatrixC, 
                leadingDimension);
    double zhemmExpected[] = {120.95,-64.19,-103.78,-77.1,-29.3,51.58,-104.79,-42.24,8.25,72.16,57.19,82.18,4.44,74.53,8.25,123.7,65.81,-43.94};
    checkArrayDouble(zMatrixC, zhemmExpected, 18, "zhemm");

    cblas_zher(CblasRowMajor, CblasUpper, matrixN, noScale, zVectorX, arrayStride, zMatrixA, leadingDimension);
    double zherExpected[] = {-3.5,0,-1.3,1.6,-8.2,4.8,3.8,4.4,-4.2,0,11.1,6.7,3.9,8.8,-9.1,-8,19.55,0};
    checkArrayDouble(zMatrixA, zherExpected, 18, "zher");
    resetMatrices();

    cblas_zher2(CblasRowMajor, CblasUpper, matrixN, zScaleFactor, zVectorX, arrayStride, zVectorX, arrayStride, zMatrixA, leadingDimension);
    double zher2Expected[] = {-1.5,0,-0.3,4.6,-6.7,9.3,3.8,4.4,0.8,0,18.6,6.7,3.9,8.8,-9.1,-8,30.8,0};
    checkArrayDouble(zMatrixA, zher2Expected, 18, "zher2");
    resetMatrices();

    memset(zMatrixC, 0, sizeof(zMatrixC));
    cblas_zher2k(CblasRowMajor, 
                 CblasUpper, 
                 CblasNoTrans, 
                 matrixN, 
                 matrixK, 
                 zScaleFactor, 
                 zMatrixA, 
                 leadingDimension, 
                 zMatrixB, 
                 leadingDimension, 
                 noScale, 
                 zMatrixC, 
                 leadingDimension);
    double zher2kExpected[] = {222.62,0,-152.21,-32.29,-250.43,173.25,0,0,63.14,0,2.49,-77.33,0,0,0,0,-128.16,0};
    checkArrayDouble(zMatrixC, zher2kExpected, 18, "zher2k");

    memset(zMatrixC, 0, sizeof(zMatrixC));
    cblas_zherk(CblasRowMajor, CblasUpper, CblasNoTrans, matrixN, matrixK, noScale, zMatrixA, leadingDimension, noScale, zMatrixC, leadingDimension);
    double zherkExpected[] = {172.64,0,-65.15,85.96,-126.6,5.72,0,0,185.9,0,132.29,-57.08,0,0,0,0,310.6,0};
    checkArrayDouble(zMatrixC, zherkExpected, 18, "zherk");

    memset(zMatrixC, 0, sizeof(zMatrixC));
    cblas_zsyr2k(CblasRowMajor, 
                 CblasUpper, 
                 CblasNoTrans, 
                 matrixN, 
                 matrixK, 
                 zScaleFactor, 
                 zMatrixA, 
                 leadingDimension, 
                 zMatrixB, 
                 leadingDimension, 
                 zScaleFactor, 
                 zMatrixC, 
                 leadingDimension);
    double zsyr2kExpected[] = {124.7,123.34,-89.95,-27.13,-73.47,-95.49,0,0,202.38,-93.58,-57.37,-40.15,0,0,0,0,-140,-475.52};
    checkArrayDouble(zMatrixC, zsyr2kExpected, 18, "zsyr2k");

    memset(zMatrixC, 0, sizeof(zMatrixC));
    cblas_zsyrk(CblasRowMajor, CblasUpper, CblasNoTrans, matrixN, matrixK, zScaleFactor, zMatrixA, leadingDimension, zScaleFactor, zMatrixC, leadingDimension);
    double zsyrkExpected[] = {86.62,71.02,-4.17,-106.68,-35.46,-25.18,0,0,38.18,24.64,124.55,146.2,0,0,0,0,23.22,189.34};
    checkArrayDouble(zMatrixC, zsyrkExpected, 18, "zsyrk");

    catlas_zset(arraySize, zScaleFactor3, zMatrixC, arrayStride);
    double zsetExpected[] = {-1,2.5,-1,2.5,-1,2.5,-1,2.5,-1,2.5,-1,2.5,-1,2.5,-1,2.5,-1,2.5};
    checkArrayDouble(zMatrixC, zsetExpected, 18, "zset");

    cblas_zgbmv(CblasRowMajor, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                1,
                1,
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zVectorX, 
                arrayStride, 
                zScaleFactor, 
                zVectorX, 
                arrayStride);
    double zgbmvExpected[] = {-19,7.6,-98.09,-25.62,-193.395,-974.96};
    checkArrayDouble(zVectorX, zgbmvExpected, 6, "zgbmv");
    resetVectors();

    cblas_zhpr(CblasRowMajor, CblasUpper, matrixN, noScale, zVectorX, arrayStride, zMatrixA);
    double zhprExpected[] = {-3.5,0,-1.3,1.6,-8.2,4.8,8.8,0,-1.7,3.1,14.85,0,3.9,8.8,-9.1,-8,8.3,-1.5};
    checkArrayDouble(zMatrixA, zhprExpected, 18, "zhpr");
    resetMatrices();

    cblas_zhpr2(CblasRowMajor, CblasUpper, matrixN, zScaleFactor, zVectorX, arrayStride, zVectorX, arrayStride, zMatrixA);
    double zhpr2Expected[] = {-1.5,0,-0.3,4.6,-6.7,9.3,13.8,0,5.8,3.1,26.1,0,3.9,8.8,-9.1,-8,8.3,-1.5};
    checkArrayDouble(zMatrixA, zhpr2Expected, 18, "zhpr2");
    resetMatrices();

    cblas_ztbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, 2, zMatrixA, leadingDimension, zVectorX, arrayStride);
    double ztbsvExpected[] = {0.349721,0.376977,-0.453729,-0.56731,-0.01619,-0.348084};
    checkArrayDouble(zVectorX, ztbsvExpected, 6, "ztbsv");
    resetVectors();

    cblas_ztpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, zMatrixA, zVectorX, arrayStride);
    double ztpsvExpected[] = {0.459766,0.489136,-0.578685,-0.670866,0.0129646,-0.440795};
    checkArrayDouble(zVectorX, ztpsvExpected, 6, "ztpsv");
    resetVectors();
}

TEST(Accelerate, BLASSPComplex) { // See comments for DP Real Test
    BLASInit();

    cblas_cgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension, 
                cScaleFactor, 
                cMatrixC, 
                leadingDimension);
    float cgemmExpected[] = {97.27f,
                         -19.39f,
                         -108.26f,
                         -118.06f,
                         -33.14f,
                         93.18f,
                         -137.63f,
                         -72.48f,
                         40.4f,
                         70.35f,
                         40.42f,
                         59.33f,
                         -99.63f,
                         -35.61f,
                         187.06f,
                         129.86f,
                         -32.04f,
                         -33.72f};
    checkArraySingle(cMatrixC, cgemmExpected, 18, "cgemm");

    cblas_ctrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                cScaleFactor, 
                cTriangularMatrixA, 
                leadingDimension, 
                cTriangularMatrixB, 
                leadingDimension);
    float ctrsmExpected[] = {-7.0f,-3.7f,6.4f,-0.7f,-6.5f,-0.6f,4.3f,0.4f,-5.4f,2.9f,0.1f,-6.8f,-9.7f,7.7f,8.5f,8.7f,5.8f,-3.2f};
    checkArraySingle(cTriangularMatrixB, ctrsmExpected, 18, "ctrsm");

    cblas_cgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, cScaleFactor, cMatrixA, leadingDimension, cVectorX, arrayStride, cScaleFactor, cVectorY, arrayStride);
    float cgemvExpected[] = {-33.75f,3.05f,4.95f,38.3f,-8.45f,-11.15f};
    checkArraySingle(cVectorY, cgemvExpected, 6, "cgemv");
    resetVectors();

    float cdotc_sub_out[2];
    cblas_cdotc_sub(arraySize, cMatrixA, arrayStride, cMatrixB, arrayStride, cdotc_sub_out);
    float cdotc_subExpected[] = {78.8f,27.76f};
    checkArraySingle(cdotc_sub_out, cdotc_subExpected, 2, "cdotc_sub");

    float cdotu_sub_out[2];
    cblas_cdotu_sub(arraySize, cMatrixA, arrayStride, cMatrixB, arrayStride, cdotu_sub_out);
    float cdotu_subExpected[] = {93.54f,-222.88f};
    checkArraySingle(cdotu_sub_out, cdotu_subExpected, 2, "cdotu_sub");

    cblas_caxpy(arraySize, cScaleFactor2, cMatrixA, arrayStride, cMatrixB, arrayStride);
    float caxpyExpected[] = {-6.1f,-15.6f,5.5f,-4.4f,-16.5f,-10.0f,3.7f,8.6f,-17.7f,-3.2f,-3.0f,3.5f,-14.6f,20.4f,7.4f,-8.4f,15.6f,3.6f};
    checkArraySingle(cMatrixB, caxpyExpected, 18, "caxpy");
    resetMatrices();

    cblas_cscal(arraySize, cScaleFactor2, cMatrixA, arrayStride);
    float cscalExpected[] = {0.9f,-11.9f,-0.9f,-3.7f,-10.0f,-9.4f,-0.6f,8.2f,-12.3f,-6.1f,-3.1f,10.3f,-4.9f,12.7f,-1.1f,-17.1f,9.8f,6.8f};
    checkArraySingle(cMatrixA, cscalExpected, 18, "cscal");
    resetMatrices();

    cblas_csscal(arraySize, scaleUp, cMatrixA, arrayStride);
    float csscalExpected[] = {-16.5f,-19.2f,-6.9f,-4.2f,-29.1f,0.9f,11.4f,13.2f,-27.6f,9.3f,10.8f,20.1f,11.7f,26.4f,-27.3f,-24.0f,24.9f,-4.5f};
    checkArraySingle(cMatrixA, csscalExpected, 18, "csscal");
    resetMatrices();

    cblas_csymm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                matrixM, 
                matrixN, 
                cScaleFactor, 
                cTriangularMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension, 
                cZeroScale, 
                cTriangularMatrixB, 
                leadingDimension);
    float csymmExpected[] = {-9.2f,13.3f,1.8f,28.3f,5.5f,-34.2f,-53.9f,17.2f,43.4f,40.7f,-2.5f,-35.6f,-6.5f,1.9f,-0.3f,18.9f,-6.8f,-31.6f};
    checkArraySingle(cTriangularMatrixB, csymmExpected, 18, "csymm");

    cblas_ctrmm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                cScaleFactor, 
                cTriangularMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension);
    float ctrmmExpected[] = {-9.2f,13.3f,1.8f,28.3f,5.5f,-34.2f,-25.9f,32.0f,17.8f,43.5f,23.5f,-33.2f,-9.7f,7.7f,8.5f,8.7f,5.8f,-3.2f};
    checkArraySingle(cMatrixB, ctrmmExpected, 18, "ctrmm");
    resetMatrices();

    cblas_chemv(CblasRowMajor, CblasUpper, matrixN, cScaleFactor, cTriangularMatrixA, leadingDimension, cVectorX, arrayStride, cScaleFactor, cVectorY, arrayStride);
    float chemvExpected[] = {15.0f,-6.0f,22.0f,-5.0f,13.0f,-3.5f};
    checkArraySingle(cVectorY, chemvExpected, 6, "chemv");
    resetVectors();

    cblas_ctrmv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, cTriangularMatrixA, leadingDimension, cVectorX, arrayStride);
    float ctrmvExpected[] = {15.0f,-6.0f,18.0f,-9.0f,3.0f,-1.5f};
    checkArraySingle(cVectorX, ctrmvExpected, 6, "ctrmv");
    resetVectors();

    cVectorX[0] = 15.0f; cVectorX[1] = -6.0f; cVectorX[2] = 18.0f; cVectorX[3] = -9.0f; cVectorX[4] = 3.0f; cVectorX[5] = -1.5f;
    cblas_ctrsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, cTriangularMatrixA, leadingDimension, cVectorX, arrayStride);
    float ctrsvExpected[] = {1.0f,1.0f,2.0f,-1.0f,3.0f,-1.5f};
    checkArraySingle(cVectorX, ctrsvExpected, 6, "ctrsv");
    resetVectors();

    cblas_cswap(matrixN, cMatrixA, arrayStride, cMatrixB, arrayStride);
    float cswapExpected_A[] = {-7.0f,-3.7f,6.4f,-0.7f,-6.5f,-0.6f};
    float cswapExpected_B[] = {-5.5f,-6.4f,-2.3f,-1.4f,-9.7f,0.3f};
    checkArraySingle(cMatrixA, cswapExpected_A, 6, "cswap_A");
    checkArraySingle(cMatrixB, cswapExpected_B, 6, "cswap_B");
    resetMatrices();

    int icamax_out = cblas_icamax(arraySize, cMatrixA, arrayStride);
    int icamaxExpected = 7;
    ASSERT_EQ(icamax_out, icamaxExpected);

    cblas_ccopy(arraySize, cMatrixA, arrayStride, cMatrixB, arrayStride);
    float ccopyExpected[] = {-5.5f,-6.4f,-2.3f,-1.4f,-9.7f,0.3f,3.8f,4.4f,-9.2f,3.1f,3.6f,6.7f,3.9f,8.8f,-9.1f,-8.0f,8.3f,-1.5f};
    checkArraySingle(cMatrixB, ccopyExpected, 18, "ccopy");
    resetMatrices();

    float scasum_out = cblas_scasum(arraySize, cMatrixA, arrayStride);
    float scasumExpected = 96.0f;
    ASSERT_NEAR(scasum_out, scasumExpected, 0.0001);

    float scnrm2_out = cblas_scnrm2(arraySize, cMatrixA, arrayStride);
    float scnrm2Expected = 25.8677f;
    ASSERT_NEAR(scnrm2_out, scnrm2Expected, 0.0001);

    float crotgvec[] = {-5.5f, -6.4f, -7.0f, -3.7f, 0.0f, 0.0f, 0.0f, 0.0f};
    cblas_crotg(&crotgvec[0], &crotgvec[2], &crotgvec[4], &crotgvec[6]);
    float crotgExpected[] = {-7.54193f,-8.77606f,-7.0f,-3.7f,0.729256f,0.0f,0.636781f,0.250391f};
    checkArraySingle(crotgvec, crotgExpected, 8, "crotg");

    cblas_csrot(arraySize, cMatrixA, arrayStride, cMatrixB, arrayStride, 0.866025f, 0.5f);
    float csrotExpected_A[] = {-8.26314f,
                           -7.39256f,
                           1.20814f,
                           -1.56243f,
                           -11.6504f,
                           -0.0401925f,
                           5.4409f,
                           4.01051f,
                           -10.6674f,
                           4.13468f,
                           3.16769f,
                           2.40237f,
                           -1.4725f,
                           11.471f,
                           -3.63083f,
                           -2.5782f,
                           10.088f,
                           -2.89904f};
    float csrotExpected_B[] = {-3.31217f,
                           -0.00429249f,
                           6.69256f,
                           0.0937825f,
                           -0.779162f,
                           -0.669615f,
                           1.82391f,
                           -1.85359f,
                           -0.0765352f,
                           0.961473f,
                           -1.7134f,
                           -9.23897f,
                           -10.3504f,
                           2.26839f,
                           11.9112f,
                           11.5344f,
                           0.872945f,
                           -2.02128f};
    checkArraySingle(cMatrixA, csrotExpected_A, 18, "csrot_A");
    checkArraySingle(cMatrixB, csrotExpected_B, 18, "csrot_B");
    resetMatrices();

    // Setting up the Y vector
    cblas_cgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, cScaleFactor, cMatrixA, leadingDimension, cVectorX, arrayStride, cScaleFactor, cVectorY, arrayStride);

    cblas_cgerc(CblasRowMajor, matrixM, matrixN, cScaleFactor, cVectorX, arrayStride, cVectorY, arrayStride, cMatrixA, leadingDimension);
    float cgercExpected[] = {-36.2f,
                         -43.2f,
                         40.95f,
                         -34.75f,
                         -29.3f,
                         3.0f,
                         -66.75f,
                         32.05f,
                         -37.6f,
                         -78.45f,
                         -2.15f,
                         37.45f,
                         -101.925f,
                         50.275f,
                         -51.7f,
                         -130.325f,
                         -0.324998f,
                         44.625f};
    checkArraySingle(cMatrixA, cgercExpected, 18, "cgerc");
    resetMatrices();

    cblas_cgeru(CblasRowMajor, matrixM, matrixN, cScaleFactor, cVectorX, arrayStride, cVectorY, arrayStride, cMatrixA, leadingDimension);
    float cgeruExpected[] = {-42.3f,
                         -37.1f,
                         -35.65f,
                         41.85f,
                         -7.0f,
                         -19.3f,
                         -60.65f,
                         44.25f,
                         39.0f,
                         74.75f,
                         -24.45f,
                         -7.15f,
                         -92.775f,
                         68.575f,
                         63.2f,
                         99.475f,
                         -33.775f,
                         -22.275f};
    checkArraySingle(cMatrixA, cgeruExpected, 18, "cgeru");
    resetMatrices();

    memset(cMatrixC, 0, sizeof(cMatrixC));
    cblas_chemm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                matrixM, 
                matrixN, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension, 
                cScaleFactor, 
                cMatrixC, 
                leadingDimension);
    float chemmExpected[] = {120.95f,
                         -64.19f,
                         -103.78f,
                         -77.1f,
                         -29.3f,
                         51.58f,
                         -104.79f,
                         -42.24f,
                         8.25f,
                         72.16f,
                         57.19f,
                         82.18f,
                         4.44f,
                         74.53f,
                         8.25001f,
                         123.7f,
                         65.81f,
                         -43.94f};
    checkArraySingle(cMatrixC, chemmExpected, 18, "chemm");

    cblas_cher(CblasRowMajor, CblasUpper, matrixN, noScale, cVectorX, arrayStride, cMatrixA, leadingDimension);
    float cherExpected[] = {-3.5f,0.0f,-1.3f,1.6f,-8.2f,4.8f,3.8f,4.4f,-4.2f,0.0f,11.1f,6.7f,3.9f,8.8f,-9.1f,-8.0f,19.55f,0.0f};
    checkArraySingle(cMatrixA, cherExpected, 18, "cher");
    resetMatrices();

    cblas_cher2(CblasRowMajor, CblasUpper, matrixN, cScaleFactor, cVectorX, arrayStride, cVectorX, arrayStride, cMatrixA, leadingDimension);
    float cher2Expected[] = {-1.5f,0.0f,-0.3f,4.6f,-6.7f,9.3f,3.8f,4.4f,0.8f,0.0f,18.6f,6.7f,3.9f,8.8f,-9.1f,-8.0f,30.8f,0.0f};
    checkArraySingle(cMatrixA, cher2Expected, 18, "cher2");
    resetMatrices();

    memset(cMatrixC, 0, sizeof(cMatrixC));
    cblas_cher2k(CblasRowMajor, 
                 CblasUpper, 
                 CblasNoTrans, 
                 matrixN, 
                 matrixK, 
                 cScaleFactor, 
                 cMatrixA, 
                 leadingDimension, 
                 cMatrixB, 
                 leadingDimension, 
                 noScale, 
                 cMatrixC, 
                 leadingDimension);
    float cher2kExpected[] = {222.62f,
                          0.0f,
                          -152.21f,
                          -32.29f,
                          -250.43f,
                          173.25f,
                          0.0f,
                          0.0f,
                          63.14f,
                          0.0f,
                          2.49001f,
                          -77.33f,
                          0.0f,
                          0.0f,
                          0.0f,
                          0.0f,
                          -128.16f,
                          0.0f};
    checkArraySingle(cMatrixC, cher2kExpected, 18, "cher2k");

    memset(cMatrixC, 0, sizeof(cMatrixC));
    cblas_cherk(CblasRowMajor, CblasUpper, CblasNoTrans, matrixN, matrixK, noScale, cMatrixA, leadingDimension, noScale, cMatrixC, leadingDimension);
    float cherkExpected[] = {172.64f,0.0f,-65.15f,85.96f,-126.6f,5.72f,0.0f,0.0f,185.9f,0.0f,132.29f,-57.08f,0.0f,0.0f,0.0f,0.0f,310.6f,0.0f};
    checkArraySingle(cMatrixC, cherkExpected, 18, "cherk");

    memset(cMatrixC, 0, sizeof(cMatrixC));
    cblas_csyr2k(CblasRowMajor, 
                 CblasUpper, 
                 CblasNoTrans, 
                 matrixN, 
                 matrixK, 
                 cScaleFactor, 
                 cMatrixA, 
                 leadingDimension, 
                 cMatrixB, 
                 leadingDimension, 
                 cScaleFactor, 
                 cMatrixC, 
                 leadingDimension);
    float csyr2kExpected[] = {124.7f,
                          123.34f,
                          -89.95f,
                          -27.13f,
                          -73.47f,
                          -95.49f,
                          0.0f,
                          0.0f,
                          202.38f,
                          -93.58f,
                          -57.37f,
                          -40.15f,
                          0.0f,
                          0.0f,
                          0.0f,
                          0.0f,
                          -140.0f,
                          -475.52f};
    checkArraySingle(cMatrixC, csyr2kExpected, 18, "csyr2k");

    memset(cMatrixC, 0, sizeof(cMatrixC));
    cblas_csyrk(CblasRowMajor, CblasUpper, CblasNoTrans, matrixN, matrixK, cScaleFactor, cMatrixA, leadingDimension, cScaleFactor, cMatrixC, leadingDimension);
    float csyrkExpected[] = {86.62f,
                         71.02f,
                         -4.17f,
                         -106.68f,
                         -35.46f,
                         -25.18f,
                         0.0f,
                         0.0f,
                         38.18f,
                         24.64f,
                         124.55f,
                         146.2f,
                         0.0f,
                         0.0f,
                         0.0f,
                         0.0f,
                         23.22f,
                         189.34f};
    checkArraySingle(cMatrixC, csyrkExpected, 18, "csyrk");

    catlas_cset(arraySize, cScaleFactor3, cMatrixC, arrayStride);
    float csetExpected[] = {-1.0f,2.5f,-1.0f,2.5f,-1.0f,2.5f,-1.0f,2.5f,-1.0f,2.5f,-1.0f,2.5f,-1.0f,2.5f,-1.0f,2.5f,-1.0f,2.5f};
    checkArraySingle(cMatrixC, csetExpected, 18, "cset");

    cblas_cgbmv(CblasRowMajor, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                1, 
                1, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cVectorX, 
                arrayStride, 
                cScaleFactor, 
                cVectorX, 
                arrayStride);
    float cgbmvExpected[] = {-19.0f,7.6f,-98.09f,-25.62f,-193.395f,-974.96f};
    checkArraySingle(cVectorX, cgbmvExpected, 6, "cgbmv");
    resetVectors();

    cblas_chpr(CblasRowMajor, CblasUpper, matrixN, noScale, cVectorX, arrayStride, cMatrixA);
    float chprExpected[] = {-3.5f,0.0f,-1.3f,1.6f,-8.2f,4.8f,8.8f,0.0f,-1.7f,3.1f,14.85f,0.0f,3.9f,8.8f,-9.1f,-8.0f,8.3f,-1.5f};
    checkArraySingle(cMatrixA, chprExpected, 18, "chpr");
    resetMatrices();

    cblas_chpr2(CblasRowMajor, CblasUpper, matrixN, cScaleFactor, cVectorX, arrayStride, cVectorX, arrayStride, cMatrixA);
    float chpr2Expected[] = {-1.5f,0.0f,-0.3f,4.6f,-6.7f,9.3f,13.8f,0.0f,5.8f,3.1f,26.1f,0.0f,3.9f,8.8f,-9.1f,-8.0f,8.3f,-1.5f};
    checkArraySingle(cMatrixA, chpr2Expected, 18, "chpr2");
    resetMatrices();

    cblas_ctbsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, 2, cMatrixA, leadingDimension, cVectorX, arrayStride);
    float ctbsvExpected[] = {0.349721f,0.376977f,-0.453729f,-0.56731f,-0.01619f,-0.348084f};
    checkArraySingle(cVectorX, ctbsvExpected, 6, "ctbsv");
    resetVectors();

    cblas_ctpsv(CblasRowMajor, CblasUpper, CblasNoTrans, CblasNonUnit, matrixN, cMatrixA, cVectorX, arrayStride);
    float ctpsvExpected[] = {0.459766f,0.489136f,-0.578685f,-0.670866f,0.0129646f,-0.440795f};
    checkArraySingle(cVectorX, ctpsvExpected, 6, "ctpsv");
    resetVectors();
}

TEST(Accelerate, BLASXerbla) {
    BLASInit();
    
    // Set xerbla to call our test error handler to check for functionality
    SetBLASParamErrorProc(BLASTestErrorProc);

    // Process: clear error flag, set expected function name, set expected parameter number, call function, check error flag
    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemm ");
    parameterPositionExpected = 4;
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans, 
                -1, 
                matrixN, 
                matrixK, 
                noScale, 
                dMatrixA, 
                leadingDimension, 
                dMatrixB, 
                leadingDimension, 
                noScale, 
                dMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemm ");
    parameterPositionExpected = 5;
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans, 
                matrixM, 
                -1, 
                matrixK, 
                noScale, 
                dMatrixA, 
                leadingDimension, 
                dMatrixB, 
                leadingDimension, 
                noScale, 
                dMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemm ");
    parameterPositionExpected = 6;
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                -1, 
                noScale, 
                dMatrixA, 
                leadingDimension, 
                dMatrixB, 
                leadingDimension, 
                noScale, 
                dMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemm ");
    parameterPositionExpected = 9;
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                dMatrixA, 
                2, 
                dMatrixB, 
                leadingDimension, 
                noScale, 
                dMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemm ");
    parameterPositionExpected = 11;
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                dMatrixA, 
                leadingDimension, 
                dMatrixB, 
                2, 
                noScale, 
                dMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemm ");
    parameterPositionExpected = 14;
    cblas_dgemm(CblasRowMajor,
                CblasNoTrans,
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                dMatrixA, 
                leadingDimension, 
                dMatrixB, 
                leadingDimension, 
                noScale, 
                dMatrixC, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemm ");
    parameterPositionExpected = 4;
    cblas_sgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                -1, 
                matrixN, 
                matrixK, 
                noScale, 
                sMatrixA, 
                leadingDimension, 
                sMatrixB, 
                leadingDimension, 
                noScale, 
                sMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemm ");
    parameterPositionExpected = 5;
    cblas_sgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                -1, 
                matrixK, 
                noScale, 
                sMatrixA, 
                leadingDimension, 
                sMatrixB, 
                leadingDimension, 
                noScale, 
                sMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemm ");
    parameterPositionExpected = 6;
    cblas_sgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                -1, 
                noScale, 
                sMatrixA, 
                leadingDimension, 
                sMatrixB, 
                leadingDimension, 
                noScale, 
                sMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemm ");
    parameterPositionExpected = 9;
    cblas_sgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                sMatrixA, 
                2, 
                sMatrixB, 
                leadingDimension, 
                noScale, 
                sMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemm ");
    parameterPositionExpected = 11;
    cblas_sgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                sMatrixA, 
                leadingDimension, 
                sMatrixB, 
                2, 
                noScale, 
                sMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemm ");
    parameterPositionExpected = 14;
    cblas_sgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                noScale, 
                sMatrixA, 
                leadingDimension, 
                sMatrixB, 
                leadingDimension, 
                noScale, 
                sMatrixC, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemm ");
    parameterPositionExpected = 4;
    cblas_zgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                -1, 
                matrixN, 
                matrixK, 
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension, 
                zScaleFactor, 
                zMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemm ");
    parameterPositionExpected = 5;
    cblas_zgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                -1, 
                matrixK, 
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension, 
                zScaleFactor, 
                zMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemm ");
    parameterPositionExpected = 6;
    cblas_zgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                -1, 
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension, 
                zScaleFactor, 
                zMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemm ");
    parameterPositionExpected = 9;
    cblas_zgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                zScaleFactor, 
                zMatrixA, 
                2, 
                zMatrixB, 
                leadingDimension, 
                zScaleFactor, 
                zMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemm ");
    parameterPositionExpected = 11;
    cblas_zgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zMatrixB, 
                2, 
                zScaleFactor, 
                zMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemm ");
    parameterPositionExpected = 14;
    cblas_zgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                zScaleFactor, 
                zMatrixA, 
                leadingDimension, 
                zMatrixB, 
                leadingDimension, 
                zScaleFactor, 
                zMatrixC, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemm ");
    parameterPositionExpected = 4;
    cblas_cgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                -1, 
                matrixN, 
                matrixK, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension, 
                cScaleFactor, 
                cMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemm ");
    parameterPositionExpected = 5;
    cblas_cgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                -1, 
                matrixK, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension, 
                cScaleFactor, 
                cMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemm ");
    parameterPositionExpected = 6;
    cblas_cgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                -1, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension, 
                cScaleFactor, 
                cMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemm ");
    parameterPositionExpected = 9;
    cblas_cgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                cScaleFactor, 
                cMatrixA, 
                2, 
                cMatrixB, 
                leadingDimension, 
                cScaleFactor, 
                cMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemm ");
    parameterPositionExpected = 11;
    cblas_cgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cMatrixB, 
                2, 
                cScaleFactor, 
                cMatrixC, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemm ");
    parameterPositionExpected = 14;
    cblas_cgemm(CblasRowMajor, 
                CblasNoTrans, 
                CblasNoTrans, 
                matrixM, 
                matrixN, 
                matrixK, 
                cScaleFactor, 
                cMatrixA, 
                leadingDimension, 
                cMatrixB, 
                leadingDimension, 
                cScaleFactor, 
                cMatrixC, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    
    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dtrsm ");
    parameterPositionExpected = 6;
    cblas_dtrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                -1, 
                matrixN, 
                noScale, 
                dTriangularMatrixA, 
                leadingDimension, 
                dTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dtrsm ");
    parameterPositionExpected = 7;
    cblas_dtrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                -1, 
                noScale, 
                dTriangularMatrixA, 
                leadingDimension, 
                dTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dtrsm ");
    parameterPositionExpected = 10;
    cblas_dtrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                dTriangularMatrixA, 
                2, 
                dTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dtrsm ");
    parameterPositionExpected = 12;
    cblas_dtrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                dTriangularMatrixA, 
                leadingDimension, 
                dTriangularMatrixB, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_strsm ");
    parameterPositionExpected = 6;
    cblas_strsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                -1, 
                matrixN, 
                noScale, 
                sTriangularMatrixA, 
                leadingDimension, 
                sTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_strsm ");
    parameterPositionExpected = 7;
    cblas_strsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                -1, 
                noScale, 
                sTriangularMatrixA, 
                leadingDimension, 
                sTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_strsm ");
    parameterPositionExpected = 10;
    cblas_strsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                sTriangularMatrixA, 
                2, 
                sTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_strsm ");
    parameterPositionExpected = 12;
    cblas_strsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                noScale, 
                sTriangularMatrixA, 
                leadingDimension, 
                sTriangularMatrixB, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ztrsm ");
    parameterPositionExpected = 6;
    cblas_ztrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                -1, 
                matrixN, 
                zScaleFactor, 
                zTriangularMatrixA, 
                leadingDimension, 
                zTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ztrsm ");
    parameterPositionExpected = 7;
    cblas_ztrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                -1, 
                zScaleFactor, 
                zTriangularMatrixA, 
                leadingDimension, 
                zTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ztrsm ");
    parameterPositionExpected = 10;
    cblas_ztrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                zScaleFactor, 
                zTriangularMatrixA, 
                2, 
                zTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ztrsm ");
    parameterPositionExpected = 12;
    cblas_ztrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                zScaleFactor, 
                zTriangularMatrixA, 
                leadingDimension, 
                zTriangularMatrixB, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    
    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ctrsm ");
    parameterPositionExpected = 6;
    cblas_ctrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                -1, 
                matrixN, 
                cScaleFactor, 
                cTriangularMatrixA, 
                leadingDimension, 
                cTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ctrsm ");
    parameterPositionExpected = 7;
    cblas_ctrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                -1, 
                cScaleFactor, 
                cTriangularMatrixA, 
                leadingDimension, 
                cTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ctrsm ");
    parameterPositionExpected = 10;
    cblas_ctrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                cScaleFactor, 
                cTriangularMatrixA, 
                2, 
                cTriangularMatrixB, 
                leadingDimension);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_ctrsm ");
    parameterPositionExpected = 12;
    cblas_ctrsm(CblasRowMajor, 
                CblasLeft, 
                CblasUpper, 
                CblasNoTrans, 
                CblasNonUnit, 
                matrixM, 
                matrixN, 
                cScaleFactor, 
                cTriangularMatrixA, 
                leadingDimension, 
                cTriangularMatrixB, 
                2);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemv ");
    parameterPositionExpected = 3;
    cblas_dgemv(CblasRowMajor, CblasNoTrans, -1, matrixN, noScale, dMatrixA, leadingDimension, dVectorX, arrayStride, zeroScale, dVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemv ");
    parameterPositionExpected = 4;
    cblas_dgemv(CblasRowMajor, CblasNoTrans, matrixM, -1, noScale, dMatrixA, leadingDimension, dVectorX, arrayStride, zeroScale, dVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemv ");
    parameterPositionExpected = 7;
    cblas_dgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, dMatrixA, 2, dVectorX, arrayStride, zeroScale, dVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemv ");
    parameterPositionExpected = 9;
    cblas_dgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, dMatrixA, leadingDimension, dVectorX, 0, zeroScale, dVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_dgemv ");
    parameterPositionExpected = 12;
    cblas_dgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, dMatrixA, leadingDimension, dVectorX, arrayStride, zeroScale, dVectorY, 0);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemv ");
    parameterPositionExpected = 3;
    cblas_sgemv(CblasRowMajor, CblasNoTrans, -1, matrixN, noScale, sMatrixA, leadingDimension, sVectorX, arrayStride, zeroScale, sVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemv ");
    parameterPositionExpected = 4;
    cblas_sgemv(CblasRowMajor, CblasNoTrans, matrixM, -1, noScale, sMatrixA, leadingDimension, sVectorX, arrayStride, zeroScale, sVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemv ");
    parameterPositionExpected = 7;
    cblas_sgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, sMatrixA, 2, sVectorX, arrayStride, zeroScale, sVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemv ");
    parameterPositionExpected = 9;
    cblas_sgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, sMatrixA, leadingDimension, sVectorX, 0, zeroScale, sVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_sgemv ");
    parameterPositionExpected = 12;
    cblas_sgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, noScale, sMatrixA, leadingDimension, sVectorX, arrayStride, zeroScale, sVectorY, 0);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemv ");
    parameterPositionExpected = 3;
    cblas_zgemv(CblasRowMajor, CblasNoTrans, -1, matrixN, zScaleFactor, zMatrixA, leadingDimension, zVectorX, arrayStride, zScaleFactor, zVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemv ");
    parameterPositionExpected = 4;
    cblas_zgemv(CblasRowMajor, CblasNoTrans, matrixM, -1, zScaleFactor, zMatrixA, leadingDimension, zVectorX, arrayStride, zScaleFactor, zVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemv ");
    parameterPositionExpected = 7;
    cblas_zgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, zScaleFactor, zMatrixA, 2, zVectorX, arrayStride, zScaleFactor, zVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemv ");
    parameterPositionExpected = 9;
    cblas_zgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, zScaleFactor, zMatrixA, leadingDimension, zVectorX, 0, zScaleFactor, zVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_zgemv ");
    parameterPositionExpected = 12;
    cblas_zgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, zScaleFactor, zMatrixA, leadingDimension, zVectorX, arrayStride, zScaleFactor, zVectorY, 0);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);


    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemv ");
    parameterPositionExpected = 3;
    cblas_cgemv(CblasRowMajor, CblasNoTrans, -1, matrixN, cScaleFactor, cMatrixA, leadingDimension, cVectorX, arrayStride, cScaleFactor, cVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemv ");
    parameterPositionExpected = 4;
    cblas_cgemv(CblasRowMajor, CblasNoTrans, matrixM, -1, cScaleFactor, cMatrixA, leadingDimension, cVectorX, arrayStride, cScaleFactor, cVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemv ");
    parameterPositionExpected = 7;
    cblas_cgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, cScaleFactor, cMatrixA, 2, cVectorX, arrayStride, cScaleFactor, cVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemv ");
    parameterPositionExpected = 9;
    cblas_cgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, cScaleFactor, cMatrixA, leadingDimension, cVectorX, 0, cScaleFactor, cVectorY, arrayStride);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);

    errorFlag = 0;
    strcpy(functionNameExpected, "cblas_cgemv ");
    parameterPositionExpected = 12;
    cblas_cgemv(CblasRowMajor, CblasNoTrans, matrixM, matrixN, cScaleFactor, cMatrixA, leadingDimension, cVectorX, arrayStride, cScaleFactor, cVectorY, 0);
    ASSERT_EQ_MSG(errorFlag, 1, "XERBLA TEST FAILED, NO ERROR: NAME: %s POS: %i", functionNameExpected, parameterPositionExpected);
}