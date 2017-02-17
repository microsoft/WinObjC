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
#import "Accelerate/Accelerate.h"

// Constants defining array strides and lengths
const vDSP_Stride strideA = 1;
const vDSP_Stride strideB = 1;
const vDSP_Stride strideC = 1;
const vDSP_Length lengthN = 5;

// Integer variables used for tests
int iArrayA[lengthN];
int iArrayC[lengthN];
int iVal[1];

// Single precision floating point variables used for tests
float fArrayA[lengthN];
float fArrayA2[lengthN];
float fArrayB[lengthN];
float fArrayC[lengthN];
float fArrayC2[lengthN];
float fVal[1];
float fASplitReal[lengthN];
float fASplitImag[lengthN];
float fCSplitReal[lengthN];
float fCSplitImag[lengthN];
DSPSplitComplex cArrayA[1];
DSPSplitComplex fBSplitComplex[1];
DSPSplitComplex cArrayC[1];

// Double precision floating point variables used for tests
double dArrayA[lengthN];
double dArrayA2[lengthN];
double dArrayA3[lengthN];
double dArrayB[lengthN];
double dArrayC[lengthN];
double dArrayC2[lengthN];
double dVal[1];
double dASplitReal[lengthN];
double dASplitImag[lengthN];
double dASplitReal2[lengthN];
double dASplitImag2[lengthN];
double dCSplitReal[lengthN];
double dCSplitImag[lengthN];
DSPDoubleSplitComplex zArrayA[1];
DSPDoubleSplitComplex zArrayA2[1];
DSPDoubleSplitComplex dBSplitComplex[1];
DSPDoubleSplitComplex zArrayC[1];

static void vDSPInit(void) {
    iArrayA[0] = 1;
    iArrayA[1] = -1;
    iArrayA[2] = 2;
    iArrayA[3] = 3;
    iArrayA[4] = -14;
    iVal[0] = 2;

    fArrayA[0] = 1.25f;
    fArrayA[1] = -1.35f;
    fArrayA[2] = 2.28f;
    fArrayA[3] = 3.5f;
    fArrayA[4] = -14.95f;

    fArrayA2[0] = 3.9f;
    fArrayA2[1] = 15.69f;
    fArrayA2[2] = -0.01f;
    fArrayA2[3] = -87.2f;
    fArrayA2[4] = 31.76f;

    fArrayB[0] = 2.0f;
    fArrayB[1] = 8.0f;
    fArrayB[2] = 0.0f;
    fArrayB[3] = 0.0f;
    fArrayB[4] = -5.2f;

    memset(fArrayC, 0, sizeof(fArrayC));
    memset(fArrayC2, 0, sizeof(fArrayC2));

    fVal[0]=2.0;

    fASplitReal[0] = 2.0f;
    fASplitReal[1] = -1.35f;
    fASplitReal[2] = 2.28f;
    fASplitReal[3] = 3.5f;
    fASplitReal[4] = -14.95f;

    fASplitImag[0] = 3.0f;
    fASplitImag[1] = 13.76f;
    fASplitImag[2] = -7.0f;
    fASplitImag[3] = 12.1f;
    fASplitImag[4] = -2.99f;

    memset(fCSplitReal, 0, sizeof(fCSplitReal));
    memset(fCSplitImag, 0, sizeof(fCSplitImag));

    cArrayA->realp = fASplitReal;
    cArrayA->imagp = fASplitImag;
    cArrayC->realp = fCSplitReal;
    cArrayC->imagp = fCSplitImag;

    fBSplitComplex->realp=fVal;
    fBSplitComplex->imagp=fVal;

    dArrayA[0] = 3.9;
    dArrayA[1] = 15.69;
    dArrayA[2] = -0.01;
    dArrayA[3] = -87.2;
    dArrayA[4] = 31.76;

    dArrayA2[0] = 1.25;
    dArrayA2[1] = -1.35;
    dArrayA2[2] = 2.28;
    dArrayA2[3] = 3.5;
    dArrayA2[4] = -14.95;

    dArrayA3[0] = -31.51;
    dArrayA3[1] =  11.33;
    dArrayA3[2] = 85.58;
    dArrayA3[3] = 1.051;
    dArrayA3[4] = -111.77;

    dArrayB[0] = 3.0;
    dArrayB[1] = 10.5;
    dArrayB[2] = 0.0;
    dArrayB[3] = 0.0;
    dArrayB[4] = 0.123;

    memset(dArrayC, 0, sizeof(dArrayC));
    memset(dArrayC2, 0, sizeof(dArrayC2));

    dVal[0]=2.0;

    dASplitReal[0] = 3.14;
    dASplitReal[1] = -5.0;
    dASplitReal[2] = 0.0;
    dASplitReal[3] = 3.5;
    dASplitReal[4] = 6.7;

    dASplitImag[0] = -6.3;
    dASplitImag[1] = 2.92;
    dASplitImag[2] = 0.99;
    dASplitImag[3] = -99.1;
    dASplitImag[4] = 12.34;

    dASplitReal2[0] = 72.0;
    dASplitReal2[1] = -1.39;
    dASplitReal2[2] = 23.78;
    dASplitReal2[3] = -33.55;
    dASplitReal2[4] = 197.05;

    dASplitImag2[0] = 13.0;
    dASplitImag2[1] = 19.71;
    dASplitImag2[2] = 17.42;
    dASplitImag2[3] = -2.19;
    dASplitImag2[4] = -2.19;

    memset(dCSplitReal, 0, sizeof(dCSplitReal));
    memset(dCSplitImag, 0, sizeof(dCSplitImag));
    
    zArrayA->realp = dASplitReal;
    zArrayA->imagp = dASplitImag;
    zArrayA2->realp = dASplitReal2;
    zArrayA2->imagp = dASplitImag2;
    zArrayC->realp = dCSplitReal;
    zArrayC->imagp = dCSplitImag;

    dBSplitComplex->realp=dVal;
    dBSplitComplex->imagp=dVal;
}

// Template for checking NAN values in floating points, not included in tests for BLAS as not needed
// Returns a true if either the expected value or the result are NAN, because we do not wish to compare NAN to anything
// If one value is NAN but not the other, throw the issue but do not terminate the function
template<class T> bool fail_nan_test(const T &result, const T &expected) {
    if (isnan(expected)) {
        if (isnan(result)) {
            return true;
        } else {
            EXPECT_TRUE(isnan(result));
            return true;
        }
    } else {
       if (isnan(result)) {
          EXPECT_TRUE(isnan(expected));
          return true;
       } else {
          return false;
       }
    }
}

static void checkArrayInt(int* result, int* expected, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        ASSERT_NEAR_MSG(result[i], expected[i], 0.001, "TEST FAILED: %s AT INDEX %i\nEXPECTED: %i\nFOUND: %i", name, i, expected[i], result[i]);
    }
}

static void checkArraySingle(float* result, float* expected, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (!fail_nan_test(result[i], expected[i])) {
            ASSERT_NEAR_MSG(result[i], expected[i], 0.001, "TEST FAILED: %s AT INDEX %i\nEXPECTED: %f\nFOUND: %f", name, i, expected[i], result[i]);
        }
    }
}

static void checkArrayDouble(double* result, double* expected, int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (!fail_nan_test(result[i], expected[i])) {
            ASSERT_NEAR_MSG(result[i], expected[i], 0.001, "TEST FAILED: %s AT INDEX %i\nEXPECTED: %f\nFOUND: %f", name, i, expected[i], result[i]);
        }
    }
}

TEST(Accelerate, vDSPFloat) {
    // Process: call the function, create array to hold expected result, then check if the results match
    // Results obtained by running the API call on Mac and recording the output

    vDSPInit();

    vDSP_vabs(fArrayA, strideA, fArrayC, strideC, lengthN);
    float vabs_exp[]= {1.25, 1.35, 2.28, 3.5, 14.95};
    checkArraySingle(fArrayC, vabs_exp, lengthN, "vabs");

    vDSP_vnabs(fArrayA, strideA, fArrayC, strideC, lengthN);
    float vnabs_exp[]= {-1.25, -1.35, -2.28, -3.5, -14.95};
    checkArraySingle(fArrayC, vnabs_exp, lengthN, "vnabs");

    vDSP_vneg(fArrayA, strideA, fArrayC, strideC, lengthN);
    float vneg_exp[]= {-1.25, 1.35, -2.28, -3.5, 14.95 };
    checkArraySingle(fArrayC, vneg_exp, lengthN, "vneg");

    vDSP_vfill(fVal, fArrayC, strideC, lengthN);
    float vfill_exp[]= {*fVal, *fVal, *fVal, *fVal, *fVal };
    checkArraySingle(fArrayC, vfill_exp, lengthN, "vfill");

    vDSP_zvmags(cArrayA, strideA, fArrayC, strideC, lengthN);
    float zvmags_exp[] = {13.000000, 191.160095, 54.198399, 158.660004, 232.442581};
    checkArraySingle(fArrayC, zvmags_exp, lengthN, "zvmags");

    vDSP_vdbcon(fArrayA, strideA, fVal, fArrayC, strideC, lengthN, 1);
    float vdbcon_exp[] = {-4.082399, NAN, 1.138097, 4.860761, NAN};
    checkArraySingle(fArrayC, vdbcon_exp, lengthN, "vdbcon");

    fArrayC[0]=2.45; fArrayC[1]=-21.43; fArrayC[2]=11.02; fArrayC[3]=0.45; fArrayC[4]=13.45;
    vDSP_vavlin(fArrayA, strideA, fVal, fArrayC, strideC, lengthN);
    float vavlin_exp[] = {2.050000, -14.736667, 8.106668, 1.466667, 3.983333};
    checkArraySingle(fArrayC, vavlin_exp, lengthN, "vavlin");

    vDSP_vsadd(fArrayA, strideA, fVal, fArrayC, strideC, lengthN);
    float vsadd_exp[] = {3.250000, 0.650000, 4.280000, 5.500000, -12.950000};
    checkArraySingle(fArrayC, vsadd_exp, lengthN, "vsadd");

    vDSP_vsmul(fArrayA, strideA, fVal, fArrayC, strideC, lengthN);
    float vsmul_exp[] = {2.500000, -2.700000, 4.560000, 7.000000, -29.900000};
    checkArraySingle(fArrayC, vsmul_exp, lengthN, "vsmul");

    vDSP_vadd(fArrayA, strideA, fArrayB, strideB, fArrayC, strideC, lengthN);
    float vadd_exp[] = {3.250000, 6.650000, 2.280000, 3.500000, -20.150000};
    checkArraySingle(fArrayC, vadd_exp, lengthN, "vadd");

    vDSP_vasm(fArrayA, strideA, fArrayB, strideB, fArrayB, fArrayC, strideC, lengthN);
    float vasm_exp[] = {6.500000, 13.300000, 4.560000, 7.000000, -40.299999};
    checkArraySingle(fArrayC, vasm_exp, lengthN, "vasm");

    vDSP_vmul(fArrayA, strideA, fArrayB, strideB, fArrayC, strideC, lengthN);
    float vmul_exp[] = {2.500000, -10.800000, 0.000000, 0.000000, 77.739998};
    checkArraySingle(fArrayC, vmul_exp, lengthN, "vmul");

    vDSP_maxv(fArrayA, strideA, fArrayC, lengthN);
    float maxv_exp[1] = {3.500000};
    checkArraySingle(fArrayC, maxv_exp, 1, "maxv");

    vDSP_measqv(fArrayA, strideA, fArrayC, lengthN);
    float measqv_exp[1] = {48.867180};
    checkArraySingle(fArrayC, measqv_exp, 1, "measqv");

    vDSP_rmsqv(fArrayA, strideA, fArrayC, lengthN);
    float rmsqv_exp[1] = {6.990506};
    checkArraySingle(fArrayC, rmsqv_exp, 1, "rmsqv");

    // Parameter 0 = full Blackman window
    vDSP_blkman_window(fArrayC, lengthN, 0);
    float blkman_window_exp[] = {0.000000, 0.200770, 0.849230, 0.849230, 0.200770};
    checkArraySingle(fArrayC, blkman_window_exp, lengthN, "blkman_window");

    vDSP_zvabs(cArrayA, strideA, fArrayC, strideC, lengthN);
    float zvabs_exp[] = {3.60555, 13.8261, 7.36196, 12.596, 15.2461};
    checkArraySingle(fArrayC, zvabs_exp, lengthN, "zvabs");

    vDSP_vclr(fArrayC, strideC, lengthN);
    float vclr_exp[] = {0, 0, 0, 0, 0};
    checkArraySingle(fArrayC, vclr_exp, lengthN, "vclr");

    vDSP_vramp(fArrayA, fArrayB, fArrayC, strideC, lengthN);
    float vramp_exp[] = {1.25, 3.25, 5.25, 7.25, 9.25};
    checkArraySingle(fArrayC, vramp_exp, lengthN, "vramp");

    float rampmulstart = 1;
    vDSP_vrampmul(fArrayA, strideA, &rampmulstart, fArrayB, fArrayC, strideC, lengthN);
    float vrampmul_exp[] = {1.25, -4.05, 11.4, 24.5, -134.55};
    checkArraySingle(fArrayC, vrampmul_exp, lengthN, "vrampmul");

    // Start value is changed by vrampmul
    rampmulstart = 1;
    vDSP_vrampmul2(fArrayA, fArrayA2, strideA, &rampmulstart, fArrayB, fArrayC, fArrayC2, strideC, lengthN);
    float vrampmul2_exp_1[] = {1.25, -4.05, 11.4, 24.5, -134.55};
    float vrampmul2_exp_2[] = {3.9, 47.07, -0.05, -610.4, 285.84};
    checkArraySingle(fArrayC, vrampmul2_exp_1, lengthN, "vrampmul2_1");
    checkArraySingle(fArrayC2, vrampmul2_exp_2, lengthN, "vrampmul2_2");

    rampmulstart = 1;
    vDSP_vrampmuladd(fArrayA, strideA, &rampmulstart, fArrayB, fArrayC, strideC, lengthN);
    float vrampmuladd_exp[] = {2.5, -8.1, 22.8, 49, -269.1};
    checkArraySingle(fArrayC, vrampmuladd_exp, lengthN, "vrampmuladd");

    // Resetting the values in output arrays so the values from rampmuladd aren't kept
    rampmulstart = 1;
    vDSP_vrampmul2(fArrayA, fArrayA2, strideA, &rampmulstart, fArrayB, fArrayC, fArrayC2, strideC, lengthN);

    rampmulstart = 1;
    vDSP_vrampmuladd2(fArrayA, fArrayA2, strideA, &rampmulstart, fArrayB, fArrayC, fArrayC2, strideC, lengthN);
    float vrampmuladd2_exp_1[] = {2.5, -8.1, 22.8, 49, -269.1};
    float vrampmuladd2_exp_2[] = {7.8, 94.14, -0.1, -1220.8, 571.68};
    checkArraySingle(fArrayC, vrampmuladd2_exp_1, lengthN, "vrampmuladd2_1");
    checkArraySingle(fArrayC2, vrampmuladd2_exp_2, lengthN, "vrampmuladd2_2");

    vDSP_vgen(fArrayA, &fArrayB[1], fArrayC, strideC, lengthN);
    float vgen_exp[] = {1.25, 2.9375, 4.625, 6.3125, 8};
    checkArraySingle(fArrayC, vgen_exp, lengthN, "vgen");

    vDSP_vsq(fArrayA, strideA, fArrayC, strideC, lengthN);
    float vsq_exp[] = {1.5625, 1.8225, 5.1984, 12.25, 223.502};
    checkArraySingle(fArrayC, vsq_exp, lengthN, "vsq");

    vDSP_vssq(fArrayA, strideA, fArrayC, strideC, lengthN);
    float vssq_exp[] = {1.5625, -1.8225, 5.1984, 12.25, -223.502};
    checkArraySingle(fArrayC, vssq_exp, lengthN, "vssq");

    // Clear C
    vDSP_vclr(fArrayC, strideC, lengthN);

    vDSP_zvmgsa(cArrayA, strideA, fArrayC, strideC, fArrayC, strideC, lengthN);
    float zvmgsa_exp[] = {13, 191.16, 54.1984, 158.66, 232.443};
    checkArraySingle(fArrayC, zvmgsa_exp, lengthN, "zvmgsa");

    vDSP_vfrac(fArrayA, strideA, fArrayC, strideC, lengthN);
    float vfrac_exp[] = {0.25, -0.35, 0.28, 0.5, -0.95};
    checkArraySingle(fArrayC, vfrac_exp, lengthN, "vfrac");

    vDSP_vclip(fArrayA, strideA, &fArrayB[0], &fArrayB[1], fArrayC, strideC, lengthN);
    float vclip_exp[] = {2, 2, 2.28, 3.5, 2};
    checkArraySingle(fArrayC, vclip_exp, lengthN, "vclip");

    vDSP_Length countLow = 0;
    vDSP_Length countHigh = 0;

    vDSP_vclipc(fArrayA, strideA, &fArrayB[0], &fArrayB[1], fArrayC, strideC, lengthN, &countLow, &countHigh);
    float vclipc_exp[] = {2, 2, 2.28, 3.5, 2};
    int vclipc_exp_low = 3;
    int vclipc_exp_high = 0;
    checkArraySingle(fArrayC, vclipc_exp, lengthN, "vclipc");
    ASSERT_EQ_MSG(countLow, vclipc_exp_low, "TEST FAILED: vclipc_low\nEXPECTED: %i\nFOUND: %i", vclipc_exp_low, countLow);
    ASSERT_EQ_MSG(countHigh, vclipc_exp_high, "TEST FAILED: vclipc_high\nEXPECTED: %i\nFOUND: %i", vclipc_exp_high, countHigh);

    vDSP_viclip(fArrayA, strideA, &fArrayB[0], &fArrayB[1], fArrayC, strideC, lengthN);
    float viclip_exp[] = {1.25, -1.35, 8, 8, -14.95};
    checkArraySingle(fArrayC, viclip_exp, lengthN, "viclip");

    vDSP_vlim(fArrayA, strideA, &fArrayB[0], &fArrayB[1], fArrayC, strideC, lengthN);
    float vlim_exp[] = {-8, -8, 8, 8, -8};
    checkArraySingle(fArrayC, vlim_exp, lengthN, "vlim");

    vDSP_vthr(fArrayA, strideA, &fArrayB[0], fArrayC, strideC, lengthN);
    float vthr_exp[] = {2, 2, 2.28, 3.5, 2};
    checkArraySingle(fArrayC, vthr_exp, lengthN, "vthr");

    vDSP_vthres(fArrayA, strideA, &fArrayB[0], fArrayC, strideC, lengthN);
    float vthres_exp[] = {0, 0, 2.28, 3.5, 0};
    checkArraySingle(fArrayC, vthres_exp, lengthN, "vthres");

    vDSP_vthrsc(fArrayA, strideA, &fArrayB[0], &fArrayB[1], fArrayC, strideC, lengthN);
    float vthrsc_exp[] = {-8, -8, 8, 8, -8};
    checkArraySingle(fArrayC, vthrsc_exp, lengthN, "vthrsc");

    // Clear C
    vDSP_vclr(fArrayC, strideC, lengthN);

    vDSP_vcmprs(fArrayA, strideA, fArrayB, strideB, fArrayC, strideC, lengthN);
    float vcmprs_exp[] = {1.25, -1.35, -14.95, 0, 0};
    checkArraySingle(fArrayC, vcmprs_exp, lengthN, "vcmprs");

    vDSP_Length gatherIndexes[] = {4, 4, 1, 2, 5};

    vDSP_vgathr(fArrayA, gatherIndexes, strideB, fArrayC, strideC, lengthN);
    float vgathr_exp[] = {3.5, 3.5, 1.25, -1.35, -14.95};
    checkArraySingle(fArrayC, vgathr_exp, lengthN, "vgathr");

    float* fAddressArray[lengthN];
    fAddressArray[0] = &fASplitReal[3];
    fAddressArray[1] = &fASplitReal[0];
    fAddressArray[2] = &fASplitReal[3];
    fAddressArray[3] = &fASplitReal[3];
    fAddressArray[4] = &fASplitReal[2];

    float fIndexes[] = {3.2, 3.4, 0.0, 1.1, 4.999};

    vDSP_vindex(fArrayA, fIndexes, strideB, fArrayC, strideC, lengthN);
    float vindex_exp[] = {3.5, 3.5, 1.25, -1.35, -14.95};
    checkArraySingle(fArrayC, vindex_exp, lengthN, "vindex");

    vDSP_vrvrs(fArrayC, strideC, lengthN);
    float vrvrs_exp[] = {-14.95, -1.35, 1.25, 3.5, 3.5};
    checkArraySingle(fArrayC, vrvrs_exp, lengthN, "vrvrs");

    vDSP_Length numberCross = 0;
    vDSP_Length lastCrossIndex = 0;
    vDSP_Length maxCross = 2;

    vDSP_nzcros(fArrayA, strideA, maxCross, &lastCrossIndex, &numberCross, lengthN);
    int nzcros_exp_numberCross = 2;
    int nzcros_exp_lastIndex = 2;
    ASSERT_EQ_MSG(numberCross, nzcros_exp_numberCross, "TEST FAILED: nzcros_numberCross\nEXPECTED: %i\nFOUND: %i", nzcros_exp_numberCross, numberCross);
    ASSERT_EQ_MSG(lastCrossIndex, nzcros_exp_lastIndex, "TEST FAILED: nzcros_lastCross\nEXPECTED: %i\nFOUND: %i", nzcros_exp_lastIndex, lastCrossIndex);

    vDSP_vrsum(fArrayA, strideA, fArrayB, fArrayC, strideC, lengthN);
    float vrsum_exp[] = {0, -2.7, 1.86, 8.86, -21.04};
    checkArraySingle(fArrayC, vrsum_exp, lengthN, "vrsum");

    vDSP_vtrapz(fArrayA, strideA, fArrayB, fArrayC, strideC, lengthN);
    float vtrapz_exp[] = {0, -0.1, 0.83, 6.61, -4.84};
    checkArraySingle(fArrayC, vtrapz_exp, lengthN, "vtrapz");
}

TEST(Accelerate, vDSPDouble) {  // See comments for Single Precision Test
    vDSPInit();

    vDSP_vabsD(dArrayA3, strideA, dArrayC, strideC, lengthN);
    double vabsD_exp[]={31.51, 11.33, 85.58, 1.051, 111.77};
    checkArrayDouble(dArrayC, vabsD_exp, lengthN, "vabsD");

    vDSP_vnabsD(dArrayA3, strideA, dArrayC, strideC, lengthN);
    double vnabsD_exp[]={-31.51, -11.33, -85.58, -1.051, -111.77};
    checkArrayDouble(dArrayC, vnabsD_exp, lengthN, "vnabsD");

    vDSP_vnegD(dArrayA3, strideA, dArrayC, strideC, lengthN);
    double vnegD_exp[]= {31.51, -11.33, -85.58, -1.051, 111.77};
    checkArrayDouble(dArrayC, vnegD_exp, lengthN, "vnegD");

    vDSP_vfillD(dVal, dArrayC, strideC, lengthN);
    double vfillD_exp[]= {*dVal, *dVal, *dVal, *dVal, *dVal };
    checkArrayDouble(dArrayC, vfillD_exp, lengthN, "vfillD");

    vDSP_zvmagsD(zArrayA2, strideA, dArrayC, strideC, lengthN);
    double zvmagsD_exp[] = {5353.000000, 390.416200, 868.944800, 1130.398600, 38833.498600};
    checkArrayDouble(dArrayC, zvmagsD_exp, lengthN, "zvmagsD");    

    vDSP_vdbconD(dArrayA3, strideA, dVal, dArrayC, strideC, lengthN, 1);
    double vdbconD_exp[] = {NAN, 15.063998, 32.626846, -5.588546, NAN};
    checkArrayDouble(dArrayC, vdbconD_exp, lengthN, "vdbconD");

    dArrayC[0]=2.45; dArrayC[1]=-21.43; dArrayC[2]=11.02; dArrayC[3]=0.45; dArrayC[4]=13.45;
    vDSP_vavlinD(dArrayA3, strideA, dVal, dArrayC, strideC, lengthN);
    double vavlinD_exp[] = {-8.870000, -10.510000, 35.873333, 0.650333, -28.290000};
    checkArrayDouble(dArrayC, vavlinD_exp, lengthN, "vavlinD");

    vDSP_vsaddD(dArrayA3, strideA, dVal, dArrayC, strideC, lengthN);
    double vsaddD_exp[] = {-29.510000, 13.330000, 87.580000, 3.051000, -109.770000};
    checkArrayDouble(dArrayC, vsaddD_exp, lengthN, "vsaddD");

    vDSP_vsmulD(dArrayA3, strideA, dVal, dArrayC, strideC, lengthN);
    double vsmulD_exp[] = {-63.020000, 22.660000, 171.160000, 2.102000, -223.540000};
    checkArrayDouble(dArrayC, vsmulD_exp, lengthN, "vsmulD");

    vDSP_vaddD(dArrayA3, strideA, dArrayB, strideB, dArrayC, strideC, lengthN);
    double vaddD_exp[] = {-28.510000, 21.830000, 85.580000, 1.051000, -111.647000};
    checkArrayDouble(dArrayC, vaddD_exp, lengthN, "vaddD");

    vDSP_vasmD(dArrayA3, strideA, dArrayB, strideB, dArrayB, dArrayC, strideC, lengthN);
    double vasmD_exp[] = {-85.530000, 65.490000, 256.740000, 3.153000, -334.941000};
    checkArrayDouble(dArrayC, vasmD_exp, lengthN, "vasmD");

    vDSP_vmulD(dArrayA3, strideA, dArrayB, strideB, dArrayC, strideC, lengthN);
    double vmulD_exp[] = {-94.530000, 118.965000, 0.000000, 0.000000, -13.747710};
    checkArrayDouble(dArrayC, vmulD_exp, lengthN, "vmulD");

    vDSP_maxvD(dArrayA3, strideA, dArrayC, lengthN);
    double maxvD_exp[1] = {85.580000};
    checkArrayDouble(dArrayC, maxvD_exp, 1, "maxvD");

    vDSP_measqvD(dArrayA3, strideA, dArrayC, lengthN);
    double measqvD_exp[1] = {4187.764580};
    checkArrayDouble(dArrayC, measqvD_exp, 1, "measqvD");

    vDSP_rmsqvD(dArrayA3, strideA, dArrayC, lengthN);
    double rmsqvD_exp[1] = {64.712940};
    checkArrayDouble(dArrayC, rmsqvD_exp, 1, "rmsqvD");

    vDSP_blkman_windowD(dArrayC, lengthN, 0);
    double blkman_windowD_exp[] = {0.000000, 0.200770, 0.849230, 0.849230, 0.200770};
    checkArrayDouble(dArrayC, blkman_windowD_exp, lengthN, "blkman_windowD");

    vDSP_zvabsD(zArrayA, strideA, dArrayC, strideC, lengthN);
    double zvabsD_exp[] = {7.03915, 5.7902, 0.99, 99.1618, 14.0416};
    checkArrayDouble(dArrayC, zvabsD_exp, lengthN, "zvabsD");

    vDSP_vclrD(dArrayC, strideC, lengthN);
    double vclrD_exp[] = {0, 0, 0, 0, 0};
    checkArrayDouble(dArrayC, vclrD_exp, lengthN, "vclrD");

    vDSP_vrampD(dArrayA, dArrayB, dArrayC, strideC, lengthN);
    double vrampD_exp[] = {3.9, 6.9, 9.9, 12.9, 15.9};
    checkArrayDouble(dArrayC, vrampD_exp, lengthN, "vrampD");
    
    double rampmulstartD = 1;
    vDSP_vrampmulD(dArrayA, strideA, &rampmulstartD, dArrayB, dArrayC, strideC, lengthN);
    double vrampmulD_exp[] = {3.9, 62.76, -0.07, -872, 412.88};
    checkArrayDouble(dArrayC, vrampmulD_exp, lengthN, "vrampmulD");
    
    rampmulstartD = 1;
    vDSP_vrampmul2D(dArrayA, dArrayA2, strideA, &rampmulstartD, dArrayB, dArrayC, dArrayC2, strideC, lengthN);
    double vrampmul2D_exp_1[] = {3.9, 62.76, -0.07, -872, 412.88};
    double vrampmul2D_exp_2[] = {1.25, -5.4, 15.96, 35, -194.35};
    checkArrayDouble(dArrayC, vrampmul2D_exp_1, lengthN, "vrampmul2D_1");
    checkArrayDouble(dArrayC2, vrampmul2D_exp_2, lengthN, "vrampmul2D_2");
    
    rampmulstartD = 1;
    vDSP_vrampmuladdD(dArrayA, strideA, &rampmulstartD, dArrayB, dArrayC, strideC, lengthN);
    double vrampmuladdD_exp[] = {7.8, 125.52, -0.14, -1744, 825.76};
    checkArrayDouble(dArrayC, vrampmuladdD_exp, lengthN, "vrampmuladdD");
    
    // Resetting the values in output arrays
    rampmulstartD = 1;
    vDSP_vrampmul2D(dArrayA, dArrayA2, strideA, &rampmulstartD, dArrayB, dArrayC, dArrayC2, strideC, lengthN);
    
    rampmulstartD = 1;
    vDSP_vrampmuladd2D(dArrayA, dArrayA2, strideA, &rampmulstartD, dArrayB, dArrayC, dArrayC2, strideC, lengthN);
    double vrampmuladd2D_exp_1[] = {7.8, 125.52, -0.14, -1744, 825.76};
    double vrampmuladd2D_exp_2[] = {2.5, -10.8, 31.92, 70, -388.7};
    checkArrayDouble(dArrayC, vrampmuladd2D_exp_1, lengthN, "vrampmuladd2D_1");
    checkArrayDouble(dArrayC2, vrampmuladd2D_exp_2, lengthN, "vrampmuladd2D_2");
    
    vDSP_vgenD(dArrayA, &dArrayB[1], dArrayC, strideC, lengthN);
    double vgenD_exp[] = {3.9, 5.55, 7.2, 8.85, 10.5};
    checkArrayDouble(dArrayC, vgenD_exp, lengthN, "vgenD");
    
    vDSP_vsqD(dArrayA, strideA, dArrayC, strideC, lengthN);
    double vsqD_exp[] = {15.21, 246.1761, 0.0001, 7603.84, 1008.6976};
    checkArrayDouble(dArrayC, vsqD_exp, lengthN, "vsqD");
    
    vDSP_vssqD(dArrayA, strideA, dArrayC, strideC, lengthN);
    double vssqD_exp[] = {15.21, 246.1761, -0.0001, -7603.84, 1008.6976};
    checkArrayDouble(dArrayC, vssqD_exp, lengthN, "vssqD");
    
    // Clear C
    vDSP_vclrD(dArrayC, strideC, lengthN);
    
    vDSP_zvmgsaD(zArrayA, strideA, dArrayC, strideC, dArrayC, strideC, lengthN);
    double zvmgsaD_exp[] = {49.5496, 33.5264, 0.9801, 9833.06, 197.166};
    checkArrayDouble(dArrayC, zvmgsaD_exp, lengthN, "zvmgsaD");
    
    vDSP_vfracD(dArrayA, strideA, dArrayC, strideC, lengthN);
    double vfracD_exp[] = {0.9, 0.69, -0.01, -0.2, 0.76};
    checkArrayDouble(dArrayC, vfracD_exp, lengthN, "vfracD");
    
    vDSP_vclipD(dArrayA, strideA, &dArrayB[0], &dArrayB[1], dArrayC, strideC, lengthN);
    double vclipD_exp[] = {3.9, 10.5, 3, 3, 10.5};
    checkArrayDouble(dArrayC, vclipD_exp, lengthN, "vclipD");
    
    vDSP_Length countLow = 0;
    vDSP_Length countHigh = 0;
    
    vDSP_vclipcD(dArrayA, strideA, &dArrayB[0], &dArrayB[1], dArrayC, strideC, lengthN, &countLow, &countHigh);
    double vclipcD_exp[] = {3.9, 10.5, 3, 3, 10.5};
    int vclipcD_exp_low = 2;
    int vclipcD_exp_high = 2;
    checkArrayDouble(dArrayC, vclipcD_exp, lengthN, "vclipcD");
    ASSERT_EQ_MSG(countLow, vclipcD_exp_low, "TEST FAILED: vclipcD_low\nEXPECTED: %i\nFOUND: %i", vclipcD_exp_low, countLow);
    ASSERT_EQ_MSG(countHigh, vclipcD_exp_high, "TEST FAILED: vclipcD_high\nEXPECTED: %i\nFOUND: %i", vclipcD_exp_high, countHigh);
    
    vDSP_viclipD(dArrayA, strideA, &dArrayB[0], &dArrayB[1], dArrayC, strideC, lengthN);
    double viclipD_exp[] = {10.5, 15.69, -0.01, -87.2, 31.76};
    checkArrayDouble(dArrayC, viclipD_exp, lengthN, "viclipD");
    
    vDSP_vlimD(dArrayA, strideA, &dArrayB[0], &dArrayB[1], dArrayC, strideC, lengthN);
    double vlimD_exp[] = {10.5, 10.5, -10.5, -10.5, 10.5};
    checkArrayDouble(dArrayC, vlimD_exp, lengthN, "vlimD");
    
    vDSP_vthrD(dArrayA, strideA, &dArrayB[0], dArrayC, strideC, lengthN);
    double vthrD_exp[] = {3.9, 15.69, 3, 3, 31.76};
    checkArrayDouble(dArrayC, vthrD_exp, lengthN, "vthrD");
    
    vDSP_vthresD(dArrayA, strideA, &dArrayB[0], dArrayC, strideC, lengthN);
    double vthresD_exp[] = {3.9, 15.69, 0, 0, 31.76};
    checkArrayDouble(dArrayC, vthresD_exp, lengthN, "vthresD");
    
    vDSP_vthrscD(dArrayA, strideA, &dArrayB[0], &dArrayB[1], dArrayC, strideC, lengthN);
    double vthrscD_exp[] = {10.5, 10.5, -10.5, -10.5, 10.5};
    checkArrayDouble(dArrayC, vthrscD_exp, lengthN, "vthrscD");
    
    // Clear C
    vDSP_vclrD(dArrayC, strideC, lengthN);
    
    vDSP_vcmprsD(dArrayA, strideA, dArrayB, strideB, dArrayC, strideC, lengthN);
    double vcmprsD_exp[] = {3.9, 15.69, 31.76, 0, 0};
    checkArrayDouble(dArrayC, vcmprsD_exp, lengthN, "vcmprsD");
    
    vDSP_Length gatherIndexes[] = {4, 4, 1, 2, 5};

    vDSP_vgathrD(dArrayA, gatherIndexes, strideB, dArrayC, strideC, lengthN);
    double vgathrD_exp[] = {-87.2, -87.2, 3.9, 15.69, 31.76};
    checkArrayDouble(dArrayC, vgathrD_exp, lengthN, "vgathrD");
    
    double* dAddressArray[lengthN];
    dAddressArray[0] = &dASplitReal[3];
    dAddressArray[1] = &dASplitImag[0];
    dAddressArray[2] = &dASplitImag[3];
    dAddressArray[3] = &dASplitImag[3];
    dAddressArray[4] = &dASplitReal[2];
    
    double dIndexes[] = {2.2, 3.4, 3.0, 0.999, 0.1234};
    
    vDSP_vindexD(dArrayA, dIndexes, strideB, dArrayC, strideC, lengthN);
    double vindexD_exp[] = {-0.01, -87.2, -87.2, 3.9, 3.9};
    checkArrayDouble(dArrayC, vindexD_exp, lengthN, "vindexD");
    
    vDSP_vrvrsD(dArrayC, strideC, lengthN);
    double vrvrsD_exp[] = {3.9, 3.9, -87.2, -87.2, -0.01};
    checkArrayDouble(dArrayC, vrvrsD_exp, lengthN, "vrvrsD");
    
    vDSP_Length numberCross = 0;
    vDSP_Length lastCrossIndex = 0;
    vDSP_Length maxCross = 2;
    
    vDSP_nzcrosD(dArrayA, strideA, maxCross, &lastCrossIndex, &numberCross, lengthN);
    int nzcrosD_exp_numberCross = 2;
    int nzcrosD_exp_lastIndex = 4;
    ASSERT_EQ_MSG(numberCross, nzcrosD_exp_numberCross, "TEST FAILED: nzcrosD_numberCross\nEXPECTED: %i\nFOUND: %i", nzcrosD_exp_numberCross, numberCross);
    ASSERT_EQ_MSG(lastCrossIndex, nzcrosD_exp_lastIndex, "TEST FAILED: nzcrosD_lastCross\nEXPECTED: %i\nFOUND: %i", nzcrosD_exp_lastIndex, lastCrossIndex);
    
    vDSP_vrsumD(dArrayA, strideA, dArrayB, dArrayC, strideC, lengthN);
    double vrsumD_exp[] = {0, 47.07, 47.04, -214.56, -119.28};
    checkArrayDouble(dArrayC, vrsumD_exp, lengthN, "vrsumD");
    
    vDSP_vtrapzD(dArrayA, strideA, dArrayB, dArrayC, strideC, lengthN);
    double vtrapzD_exp[] = {0, 29.385, 52.905, -77.91, -161.07};
    checkArrayDouble(dArrayC, vtrapzD_exp, lengthN, "vtrapzD");
}

TEST(Accelerate, vDSPInt) {  // See comments for Single Precision Test
    vDSPInit();

    vDSP_vabsi(iArrayA, strideA, iArrayC, strideC, lengthN);
    int vabsi_exp[]={1, 1, 2, 3, 14 };
    checkArrayInt(iArrayC, vabsi_exp, lengthN, "vabsi");
    
    vDSP_vfilli(iVal, iArrayC, strideC, lengthN);
    int vfilli_exp[]= {*iVal, *iVal, *iVal, *iVal, *iVal };
    checkArrayInt(iArrayC, vfilli_exp, lengthN, "vfilli");

    vDSP_vsaddi(iArrayA, strideA, iVal, iArrayC, strideC, lengthN);
    int vsaddi_exp[] = {3, 1, 4, 5, -12};
    checkArrayInt(iArrayC, vsaddi_exp, lengthN, "vsaddi");
}

TEST(Accelerate, vDSPComplexFloat) {  // See comments for Single Precision Test
    vDSPInit();
    
    vDSP_zvzsml(cArrayA, strideA, fBSplitComplex, cArrayC, strideC, lengthN);
    float zvzsml_exp_real[] = {-2.000000, -30.220001, 18.559999, -17.200001, -23.920000};
    float zvzsml_exp_imag[] = {10.000000, 24.820000, -9.440001, 31.200001, -35.880001};
    checkArraySingle(cArrayC->realp, zvzsml_exp_real, lengthN, "zvzsml_real");
    checkArraySingle(cArrayC->imagp, zvzsml_exp_imag, lengthN, "zvzsml_imag");

    DSPComplex interleavedComplexFloat[lengthN];
    interleavedComplexFloat[0].real = -8.90; interleavedComplexFloat[0].imag = -4.15;
    interleavedComplexFloat[1].real = -6.75; interleavedComplexFloat[1].imag =  6.74;
    interleavedComplexFloat[2].real = -2.17; interleavedComplexFloat[2].imag =  2.68;
    interleavedComplexFloat[3].real =  3.37; interleavedComplexFloat[3].imag = -9.50;
    interleavedComplexFloat[4].real = -5.98; interleavedComplexFloat[4].imag =  2.22;
    vDSP_Stride complexStride = 2;

    vDSP_ctoz(interleavedComplexFloat, complexStride, cArrayC, strideC, lengthN);
    float ctoz_exp_real[] = {-8.900000, -6.750000, -2.170000, 3.370000, -5.980000};
    float ctoz_exp_imag[] = {-4.150000, 6.740000, 2.680000, -9.500000, 2.220000};
    checkArraySingle(cArrayC->realp, ctoz_exp_real, lengthN, "ctoz_real");
    checkArraySingle(cArrayC->imagp, ctoz_exp_imag, lengthN, "ctoz_imag");

    vDSP_zvneg(cArrayA, strideA, cArrayC, strideC, lengthN);
    float zvneg_exp_real[] = {-2, 1.35, -2.28, -3.5, 14.95};
    float zvneg_exp_imag[] = {-3, -13.76, 7, -12.1, 2.99};
    checkArraySingle(cArrayC->realp, zvneg_exp_real, lengthN, "zvneg_real");
    checkArraySingle(cArrayC->imagp, zvneg_exp_imag, lengthN, "zvneg_imag");

    vDSP_zvfill(cArrayA, cArrayC, strideC, lengthN );
    float zvfill_exp_real[] = {2, 2, 2, 2, 2};
    float zvfill_exp_imag[] = {3, 3, 3, 3, 3};
    checkArraySingle(cArrayC->realp, zvfill_exp_real, lengthN, "zvfill_real");
    checkArraySingle(cArrayC->imagp, zvfill_exp_imag, lengthN, "zvfill_imag");

    vDSP_zvmov(cArrayA, strideA, cArrayC, strideC, lengthN);
    float zvmov_exp_real[] = {2, -1.35, 2.28, 3.5, -14.95};
    float zvmov_exp_imag[] = {3, 13.76, -7, 12.1, -2.99};
    checkArraySingle(cArrayC->realp, zvmov_exp_real, lengthN, "zvmov_real");
    checkArraySingle(cArrayC->imagp, zvmov_exp_imag, lengthN, "zvmov_imag");
}

TEST(Accelerate, vDSPComplexDouble) {  // See comments for Single Precision Test
    vDSPInit();

    vDSP_zvzsmlD(zArrayA2, strideA, dBSplitComplex, zArrayC, strideC, lengthN);
    double zvzsmlD_exp_real[] = {118.000000, -42.200000, 12.720000, -62.720000, 398.480000};
    double zvzsmlD_exp_imag[] = {170.000000, 36.640000, 82.400000, -71.480000, 389.720000};
    checkArrayDouble(zArrayC->realp, zvzsmlD_exp_real, lengthN, "zvzsmlD_real");
    checkArrayDouble(zArrayC->imagp, zvzsmlD_exp_imag, lengthN, "zvzsmlD_imag");

    DSPDoubleComplex interleavedComplexDouble[lengthN];
    interleavedComplexDouble[0].real =  0.43; interleavedComplexDouble[0].imag = -3.73;
    interleavedComplexDouble[1].real =  5.55; interleavedComplexDouble[1].imag = -6.11;
    interleavedComplexDouble[2].real = -4.28; interleavedComplexDouble[2].imag =  4.79;
    interleavedComplexDouble[3].real =  1.65; interleavedComplexDouble[3].imag = -3.71;
    interleavedComplexDouble[4].real =  9.93; interleavedComplexDouble[4].imag =  3.55;
    vDSP_Stride complexStride = 2;

    vDSP_ctozD(interleavedComplexDouble, complexStride, zArrayC, strideC, lengthN);
    double ctozD_exp_real[] = {0.430000, 5.550000, -4.280000, 1.650000, 9.930000};
    double ctozD_exp_imag[] = {-3.730000, -6.110000, 4.790000, -3.710000, 3.550000};
    checkArrayDouble(zArrayC->realp, ctozD_exp_real, lengthN, "ctozD_real");
    checkArrayDouble(zArrayC->imagp, ctozD_exp_imag, lengthN, "ctozD_imag");

    vDSP_zvnegD(zArrayA, strideA, zArrayC, strideC, lengthN);
    double zvnegD_exp_real[] = {-3.14, 5, -0, -3.5, -6.7};
    double zvnegD_exp_imag[] = {6.3, -2.92, -0.99, 99.1, -12.34};
    checkArrayDouble(zArrayC->realp, zvnegD_exp_real, lengthN, "zvnegD_real");
    checkArrayDouble(zArrayC->imagp, zvnegD_exp_imag, lengthN, "zvnegD_imag");

    vDSP_zvfillD(zArrayA, zArrayC, strideC, lengthN );
    double zvfillD_exp_real[] = {3.14, 3.14, 3.14, 3.14, 3.14};
    double zvfillD_exp_imag[] = {-6.3, -6.3, -6.3, -6.3, -6.3};
    checkArrayDouble(zArrayC->realp, zvfillD_exp_real, lengthN, "zvfillD_real");
    checkArrayDouble(zArrayC->imagp, zvfillD_exp_imag, lengthN, "zvfillD_imag");

    vDSP_zvmovD(zArrayA, strideA, zArrayC, strideC, lengthN);
    double zvmovD_exp_real[] = {3.14, -5, 0, 3.5, 6.7};
    double zvmovD_exp_imag[] = {-6.3, 2.92, 0.99, -99.1, 12.34};
    checkArrayDouble(zArrayC->realp, zvmovD_exp_real, lengthN, "zvmovD_real");
    checkArrayDouble(zArrayC->imagp, zvmovD_exp_imag, lengthN, "zvmovD_imag");
}

//Test for validating the single-precision real-to-complex DFT for a vector
TEST(Accelerate, vDSP_DFT_RealToComplex_Float) {  
    vDSP_DFT_Setup zrop_Setup = vDSP_DFT_zrop_CreateSetup(NULL, 8, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zrop_Setup != nullptr, "FAILED: vDSP_zop_CreateSetup failed!\n");
  
    //Scenario 1
    float RealIn1[] = {5, 10, 15, 20};
    float RealIn2[] = {2, -4, 9, -12};

    float RealOut1 [8] = {0};
    float ImgOut1[8] = {0};

    vDSP_DFT_Execute(zrop_Setup, RealIn1, RealIn2, RealOut1, ImgOut1);
    
    float DFT_exp_real1[] = {90.000000, -41.213204, -20.000000, 1.213204, 0.000000, 0.000000, 0.000000, 0.000000};
    float DFT_exp_imag1[] = {110.000000, 18.585786, -54.000000, -21.414214, 0.000000, 0.000000, 0.000000, 0.000000};

    checkArraySingle(RealOut1, DFT_exp_real1, 8, "DFT_RtoC_Real_S1");
    checkArraySingle(ImgOut1, DFT_exp_imag1, 8, "DFT_RtoC_Imag_S1");

    //Scenario 2
    float RealIn3[] = {1, 3, 5, 7};
    float RealIn4[] = {2, 4, 6, 8};

    vDSP_DFT_Execute(zrop_Setup, RealIn3, RealIn4, RealOut1, ImgOut1);

    float DFT_exp_real2[] = {72.000000, -8.000000, -8.000000, -8.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    float DFT_exp_imag2[] = {-8.000000, 19.313709, 8.000000, 3.313708, 0.000000, 0.000000, 0.000000, 0.000000};

    checkArraySingle(RealOut1, DFT_exp_real2, 8, "DFT_RtoC_Real_S2");
    checkArraySingle(ImgOut1, DFT_exp_imag2, 8, "DFT_RtoC_Imag_S2");

    //Scenario 3
    vDSP_DFT_Setup zrop_Setup_New = vDSP_DFT_zrop_CreateSetup(zrop_Setup, 8, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zrop_Setup != nullptr, "FAILED: vDSP_DFT_zrop_CreateSetup failed!\n");
    
    float RealIn5[4] = {1, 3, 5, 7};
    float RealIn6[4] = {2, 4, 6, 8};
  
    vDSP_DFT_Execute(zrop_Setup_New, RealIn5, RealIn6, RealOut1, ImgOut1);
    
    float DFT_exp_real3[] = {72.000000, -8.000000, -8.000000, -8.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    float DFT_exp_imag3[] = {-8.000000, 19.313709, 8.000000, 3.313708, 0.000000, 0.000000, 0.000000, 0.000000};

    checkArraySingle(RealOut1, DFT_exp_real3, 8, "DFT_RtoC_Real_S3");
    checkArraySingle(ImgOut1, DFT_exp_imag3, 8, "DFT_RtoC_Imag_S3");

    vDSP_DFT_DestroySetup(zrop_Setup);
}

//Test for validating the single-precision complex-to-real IDFT for a vector
TEST(Accelerate, vDSP_IDFT_ComplexToReal_Float) {
    vDSP_DFT_Setup zrop_Setup_Inverse = vDSP_DFT_zrop_CreateSetup(NULL, 8, vDSP_DFT_INVERSE);
    ASSERT_TRUE_MSG(zrop_Setup_Inverse != nullptr, "FAILED: vDSP_DFT_zrop_CreateSetup failed!\n");

    //Scenario 1
    float RealIn1 [] = {45, -20.606602, -10, 0.606602, 55, 0.606602, -10, -20.606602}; 
    float ImgIn1 [] = {0, 9.292893, -27, -10.707107, 0, 10.707107, 27, -9.292893};
    
    float RealOut1 [4] = {0};
    float RealOut2 [4] = {0};
    
    vDSP_DFT_Execute(zrop_Setup_Inverse, RealIn1, ImgIn1, RealOut1, RealOut2);

    float DFT_exp_real1[] = {-14.999998, 25, 65, 105};
    float DFT_exp_real2[] = {71, 23, 127, -41};

    checkArraySingle(RealOut1, DFT_exp_real1, 4, "IDFT_CtoR_Real1_S1");
    checkArraySingle(RealOut2, DFT_exp_real2, 4, "IDFT_CtoR_Real2_S1");

    //Scenario 2
    float RealIn2 [] = {36, -4, -4, -4, -4, -4, -4, -4}; 
    float ImgIn2 [] = {0, 9.66, 4, 1.66, 0, -1.66, -4, -9.66};
   
    vDSP_DFT_Execute(zrop_Setup_Inverse, RealIn2, ImgIn2, RealOut1, RealOut2);
    
    float DFT_exp_real3[] = {12, 28, 44, 60};
    float DFT_exp_real4[] = {11.991104, 27.991104, 44.008896, 60.008896};

    checkArraySingle(RealOut1, DFT_exp_real3, 4, "IDFT_CtoR_Real1_S2");
    checkArraySingle(RealOut2, DFT_exp_real4, 4, "IDFT_CtoR_Real2_S2");

    //Scenario 3
    float RealIn3 [] = {60, -2, -2, -2, -40, -2, -2, -2}; 
    float ImgIn3 [] = {0, 16.142136, 10, 12.142136, 0, -12.142136, -10, -16.142136};
    
    vDSP_DFT_Execute(zrop_Setup_Inverse, RealIn3, ImgIn3, RealOut1, RealOut2);
    
    float DFT_exp_real5[] = {48, 56, 64, 72};
    float DFT_exp_real6[] = {0, 40, 80, 120};

    checkArraySingle(RealOut1, DFT_exp_real5, 4, "IDFT_CtoR_Real1_S3");
    checkArraySingle(RealOut2, DFT_exp_real6, 4, "IDFT_CtoR_Real2_S3");

    vDSP_DFT_DestroySetup(zrop_Setup_Inverse);
}

//Test for validating the single-precision complex DFT for a vector
TEST(Accelerate, vDSP_DFT_ComplexToComplex_Float) {
    vDSP_DFT_Setup zop_Setup = vDSP_DFT_zop_CreateSetup(NULL, 8, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zop_Setup != nullptr, "FAILED: vDSP_DFT_zop_CreateSetup failed!\n");
    
    float RealIn1 [8] = {1, 3, 5, 7, 9, 11, 13, 15};
    float ImgIn1 [8] = {2, 4, 6, 8, 10, 12, 14, 16};
    float RealOut1 [8] = {0};
    float ImgOut1[8] = {0};
   
    vDSP_DFT_Execute(zop_Setup, RealIn1, ImgIn1, RealOut1, ImgOut1);

    float DFT_exp_real[] = {64.000000, -27.313709, -16.000000, -11.313708, -8.000000, -4.686292, 0.000000, 11.313708};
    float DFT_exp_imag[] = {72.000000, 11.313708, 0.000000, -4.686292, -8.000000, -11.313708, -16.000000, -27.313709};

    checkArraySingle(RealOut1, DFT_exp_real, 8, "DFT_CtoC_Real_S1");
    checkArraySingle(ImgOut1, DFT_exp_imag, 8, "DFT_CtoC_Imag_S1");

    vDSP_DFT_DestroySetup(zop_Setup);
}

//Test for validating the single-precision complex IDFT for a vector
TEST(Accelerate, vDSP_IDFT_ComplexToComplex_Float) {    
    vDSP_DFT_Setup zop_Setup_Inverse = vDSP_DFT_zop_CreateSetup(NULL, 8, vDSP_DFT_INVERSE);
    ASSERT_TRUE_MSG(zop_Setup_Inverse != nullptr, "FAILED: vDSP_DFT_zop_CreateSetup failed!\n");
    
    float RealIn1 [8] = {1, 3, 5, 7, 9, 11, 13, 15};
    float ImgIn1 [8] = {2, 4, 6, 8, 10, 12, 14, 16};
    float RealOut1 [8] = {0};
    float ImgOut1[8] = {0};
    
    vDSP_DFT_Execute(zop_Setup_Inverse, RealIn1, ImgIn1, RealOut1, ImgOut1);

    float DFT_exp_real[] = {64.000000, 11.313708, 0.000000, -4.686292, -8.000000, -11.313708, -16.000000, -27.313709};
    float DFT_exp_imag[] = {72.000000, -27.313709, -16.000000, -11.313708, -8.000000, -4.686292, 0.000000, 11.313708};

    checkArraySingle(RealOut1, DFT_exp_real, 8, "IDFT_CtoC_Real_S1");
    checkArraySingle(ImgOut1, DFT_exp_imag, 8, "IDFT_CtoC_Imag_S1");

    vDSP_DFT_DestroySetup(zop_Setup_Inverse);
}

//Test for validating the double-precision real-to-complex DFT for a vector
TEST(Accelerate, vDSP_DFT_RealToComplex_Double) {  
    vDSP_DFT_SetupD zrop_Setup = vDSP_DFT_zrop_CreateSetupD(NULL, 8, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zrop_Setup != nullptr, "FAILED: vDSP_DFT_zrop_CreateSetupD failed!\n");
    
    double RealIn1 [4] = {1, 3, 5, 7};
    double RealIn2 [4] = {2, 4, 6, 8};

    double RealOut1 [8] = {0};
    double ImgOut1[8] = {0};
    
    vDSP_DFT_ExecuteD(zrop_Setup, RealIn1, RealIn2, RealOut1, ImgOut1);

    double DFT_exp_real[] = {72.000000, -8.000000, -8.000000, -8.000000, 0.000000, 0.000000, 0.000000, 0.000000};
    double DFT_exp_imag[] = {-8.000000, 19.313708, 8.000000, 3.313708, 0.000000, 0.000000, 0.000000, 0.000000};

    checkArrayDouble(RealOut1, DFT_exp_real, 8, "DFT_RtoC_Real_S1");
    checkArrayDouble(ImgOut1, DFT_exp_imag, 8, "DFT_RtoC_Imag_S1");

    vDSP_DFT_DestroySetupD(zrop_Setup);
}

//Test for validating the double-precision complex-to-real IDFT for a vector
TEST(Accelerate, vDSP_IDFT_ComplexToReal_Double) {
    vDSP_DFT_SetupD zrop_Setup_Inverse = vDSP_DFT_zrop_CreateSetupD(NULL, 8, vDSP_DFT_INVERSE);
    ASSERT_TRUE_MSG(zrop_Setup_Inverse != nullptr, "FAILED: vDSP_DFT_zrop_CreateSetupD failed!\n");

    double RealIn1 [8] = {36, -4, -4, -4, -4, -4, -4, -4}; 
    double ImgIn1 [8] = {0, 9.66, 4, 1.66, 0, -1.66, -4, -9.66};

    double RealOut1 [4] = {0};
    double RealOut2 [4] = {0};
    
    vDSP_DFT_ExecuteD(zrop_Setup_Inverse, RealIn1, ImgIn1, RealOut1, RealOut2);

    double DFT_exp_real1[] = {12, 28, 44, 60};
    double DFT_exp_real2[] = {11.991102, 27.991102, 44.008898, 60.008898};

    checkArrayDouble(RealOut1, DFT_exp_real1, 4, "IDFT_CtoR_Real_S1");
    checkArrayDouble(RealOut2, DFT_exp_real2, 4, "IDFT_CtoR_Real_S1");

    vDSP_DFT_DestroySetupD(zrop_Setup_Inverse);
}

//Test for validating the double-precision complex DFT for a vector
TEST(Accelerate, vDSP_DFT_ComplexToComplex_Double) {
    vDSP_DFT_SetupD zop_Setup = vDSP_DFT_zop_CreateSetupD(NULL, 8, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zop_Setup != nullptr, "FAILED: vDSP_DFT_zop_CreateSetupD failed!\n");

    double RealIn1 [8] = {1, 3, 5, 7, 9, 11, 13, 15};
    double ImgIn1 [8] = {2, 4, 6, 8, 10, 12, 14, 16};
    double RealOut1 [8] = {0};
    double ImgOut1[8] = {0};
   
    vDSP_DFT_ExecuteD(zop_Setup, RealIn1, ImgIn1, RealOut1, ImgOut1);

    double DFT_exp_real[] = {64.000000, -27.313708, -16.000000, -11.313708, -8.000000, -4.686292, 0.000000, 11.313708};
    double DFT_exp_imag[] = {72.000000, 11.313708, 0.000000, -4.686292, -8.000000, -11.313708, -16.000000, -27.313708};

    checkArrayDouble(RealOut1, DFT_exp_real, 8, "DFT_CtoC_Real_S1");
    checkArrayDouble(ImgOut1, DFT_exp_imag, 8, "DFT_CtoC_Imag_S1");

    vDSP_DFT_DestroySetupD(zop_Setup);
}

//Test for validating the double-precision complex IDFT for a vector
TEST(Accelerate, vDSP_IDFT_ComplexToComplexDoubleCase1) {    
    vDSP_DFT_SetupD zop_Setup_Inverse = vDSP_DFT_zop_CreateSetupD(NULL, 8, vDSP_DFT_INVERSE);
    ASSERT_TRUE_MSG(zop_Setup_Inverse != nullptr, "FAILED: vDSP_DFT_zop_CreateSetupD failed!\n");
    
    double RealIn1 [8] = {1, 3, 5, 7, 9, 11, 13, 15};
    double ImgIn1 [8] = {2, 4, 6, 8, 10, 12, 14, 16};
    double RealOut1 [8] = {0};
    double ImgOut1[8] = {0};
    
    vDSP_DFT_ExecuteD(zop_Setup_Inverse, RealIn1, ImgIn1, RealOut1, ImgOut1);

    double DFT_exp_real[] = {64.000000, 11.313708, 0.000000, -4.686292, -8.000000, -11.313708, -16.000000, -27.313708};
    double DFT_exp_imag[] = {72.000000, -27.313709, -16.000000, -11.313708, -8.000000, -4.686292, 0.000000, 11.313708};

    checkArrayDouble(RealOut1, DFT_exp_real, 8, "IDFT_CtoC_Real_S1");
    checkArrayDouble(ImgOut1, DFT_exp_imag, 8, "IDFT_CtoC_Imag_S1");

    vDSP_DFT_DestroySetupD(zop_Setup_Inverse);
}

//Test for validating the DFT length requirements
TEST(Accelerate, vDSP_DFT_LengthCheck) {    
    vDSP_DFT_Setup zop_Setup1 = vDSP_DFT_zop_CreateSetup(NULL, 16, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zop_Setup1 != nullptr, "FAILED: vDSP_DFT_zop_CreateSetup failed!\n");
    vDSP_DFT_DestroySetup(zop_Setup1);

    vDSP_DFT_Setup zop_Setup2 = vDSP_DFT_zop_CreateSetup(NULL, 40, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zop_Setup2 != nullptr, "FAILED: vDSP_DFT_zop_CreateSetup failed!\n");
    vDSP_DFT_DestroySetup(zop_Setup2);

    vDSP_DFT_Setup zop_Setup3 = vDSP_DFT_zop_CreateSetup(NULL, 42, vDSP_DFT_FORWARD);
    ASSERT_TRUE_MSG(zop_Setup3 == nullptr, "FAILED: vDSP_DFT_zop_CreateSetup failed!\n");
    vDSP_DFT_DestroySetup(zop_Setup3);

    vDSP_DFT_Setup zrop_Setup_Inverse1 = vDSP_DFT_zrop_CreateSetup(NULL, 80, vDSP_DFT_INVERSE);
    ASSERT_TRUE_MSG(zrop_Setup_Inverse1 != nullptr, "FAILED: vDSP_DFT_zrop_CreateSetup failed!\n");
    vDSP_DFT_DestroySetup(zrop_Setup_Inverse1);

    vDSP_DFT_Setup zrop_Setup_Inverse2 = vDSP_DFT_zrop_CreateSetup(NULL, 40, vDSP_DFT_INVERSE);
    ASSERT_TRUE_MSG(zrop_Setup_Inverse2 == nullptr, "FAILED: vDSP_DFT_zrop_CreateSetup failed!\n");
    vDSP_DFT_DestroySetup(zrop_Setup_Inverse2);
}
