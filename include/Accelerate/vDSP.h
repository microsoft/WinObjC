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

#pragma once
#include "AccelerateExport.h"

typedef unsigned long vDSP_Length;
typedef long vDSP_Stride;

typedef struct { 
    float real; 
    float imag; 
} DSPComplex;

typedef struct { 
    float* realp; 
    float* imagp; 
} DSPSplitComplex;

typedef struct { 
    double real; 
    double imag; 
} DSPDoubleComplex;

typedef struct { 
    double* realp; 
    double* imagp; 
} DSPDoubleSplitComplex;

//Specifies whether to perform a Forward or inverse DFT
typedef enum {
    vDSP_DFT_FORWARD = +1,
    vDSP_DFT_INVERSE = -1
} vDSP_DFT_Direction;

//Specifies whether the DFT transformation is complex-to-complex or real-to-complex and vice versa for IDFT
typedef enum {
    ZOP = 1,
    ZROP = 2
} vDSP_DFT_TransformType;

//Setup object to be fed while computing the DFT/IDFT for a set of single-precision vectors   
typedef struct vDSP_DFT_SetupStruct {
    vDSP_Length transformLength;
    vDSP_DFT_Direction transformDirection;
    vDSP_DFT_TransformType transformType;
} *vDSP_DFT_Setup;

//Setup object to be fed while computing the DFT/IDFT for a set of double-precision vectors
typedef struct vDSP_DFT_SetupStructD {
    vDSP_Length transformLength;
    vDSP_DFT_Direction transformDirection;
    vDSP_DFT_TransformType transformType;
} *vDSP_DFT_SetupD;

ACCELERATE_EXPORT void vDSP_vabs(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vabsD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vabsi(const int* A, vDSP_Stride IA, int* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvabs(const DSPSplitComplex* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length _N);
ACCELERATE_EXPORT void vDSP_zvabsD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vnabs(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vnabsD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vneg(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vnegD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvneg(const DSPSplitComplex* A, vDSP_Stride IA, const DSPSplitComplex* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvnegD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, const DSPDoubleSplitComplex* C, vDSP_Stride IC, 
                                   vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vfill(const float* A, float* C, vDSP_Stride IC, vDSP_Length N);            
ACCELERATE_EXPORT void vDSP_vfillD(const double* A, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vfilli(const int* A, int* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvfill(const DSPSplitComplex* A, const DSPSplitComplex* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvfillD(const DSPDoubleSplitComplex* A, const DSPDoubleSplitComplex* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vclr(float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vclrD(double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vramp(const float* A, const float* B, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampD(const double* A, const double* B, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmul(const float* I, vDSP_Stride IS, float* Start, const float* Step, float* O, vDSP_Stride OS,
                                     vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmulD(const double* I, vDSP_Stride IS, double* Start, const double* Step, double* O, vDSP_Stride OS,
                                      vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmul2(const float* I0, const float* I1, vDSP_Stride IS, float* Start, const float* Step, float* O0,
                                      float* O1, vDSP_Stride OS, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmul2D(const double* I0, const double* I1, vDSP_Stride IS, double* Start, const double* Step, double* O0,
                                       double* O1, vDSP_Stride OS, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmuladd(const float* I, vDSP_Stride IS, float* Start, const float* Step, float* O, vDSP_Stride OS,
                                        vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmuladdD(const double* I, vDSP_Stride IS, double* Start, const double* Step, double* O, vDSP_Stride OS,
                                         vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmuladd2(const float* I0, const float* I1, vDSP_Stride IS, float* Start, const float* Step, float* O0,
                                         float* O1, vDSP_Stride OS, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrampmuladd2D(const double* I0, const double* I1, vDSP_Stride IS, double* Start, const double* Step, 
                                          double* O0, double* O1, vDSP_Stride OS, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vgen(const float* A, const float* B, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vgenD(const double* A, const double* B, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vsq(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vsqD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vssq(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vssqD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvmags(const DSPSplitComplex* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvmagsD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvmgsa(const DSPSplitComplex* A, vDSP_Stride IA, const float* B, vDSP_Stride IB, float* C, vDSP_Stride IC,
                                   vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvmgsaD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, const double* B, vDSP_Stride IB, double* C,
                                    vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vfrac(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vfracD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vclip(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vclipD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID,
                                   vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vclipc(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N,
                                   vDSP_Length* NLow, vDSP_Length* NHigh);
ACCELERATE_EXPORT void vDSP_vclipcD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID,
                                    vDSP_Length N, vDSP_Length* NLow, vDSP_Length* NHigh);
ACCELERATE_EXPORT void vDSP_viclip(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID,
                                   vDSP_Length N);
ACCELERATE_EXPORT void vDSP_viclipD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID,
                                    vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vlim(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vlimD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID,
                                  vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vthr(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vthrD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vthres(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vthresD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vthrsc(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID,
                                   vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vthrscD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID,
                                    vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vcmprs(const float* A, vDSP_Stride IA, const float* B, vDSP_Stride IB, float* C, vDSP_Stride IC,
                                   vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vcmprsD(const double* A, vDSP_Stride IA, const double* B, vDSP_Stride IB, double* C, vDSP_Stride IC,
                                    vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vgathr(const float* A, const vDSP_Length* B, vDSP_Stride IB, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vgathrD(const double* A, const vDSP_Length* B, vDSP_Stride IB, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vindex(const float* A, const float* B, vDSP_Stride IB, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vindexD(const double* A, const double* B, vDSP_Stride IB, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrvrs(float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrvrsD(double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvmov(const DSPSplitComplex* A, vDSP_Stride IA, const DSPSplitComplex* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvmovD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, const DSPDoubleSplitComplex* C, vDSP_Stride IC,
                                   vDSP_Length N);
ACCELERATE_EXPORT void vDSP_nzcros(const float* A, vDSP_Stride IA, vDSP_Length B, vDSP_Length* C, vDSP_Length* D, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_nzcrosD(const double* A, vDSP_Stride IA, vDSP_Length B, vDSP_Length* C, vDSP_Length* D, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vavlin(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vavlinD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrsum(const float* A, vDSP_Stride IA, const float* S, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vrsumD(const double* A, vDSP_Stride IA, const double* S, double* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vtrapz(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vtrapzD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N);

ACCELERATE_EXPORT void vDSP_vdbcon(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC,
                                   vDSP_Length N, unsigned int F);
ACCELERATE_EXPORT void vDSP_vdbconD(const double *A, vDSP_Stride IA, const double *B, double *C, vDSP_Stride IC,
                                    vDSP_Length N, unsigned int F);
ACCELERATE_EXPORT void vDSP_vsadd(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vsaddD(const double *A, vDSP_Stride IA, const double *B, double *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vsaddi(const int *A, vDSP_Stride IA, const int *B, int *C, vDSP_Stride IC, vDSP_Length N);

ACCELERATE_EXPORT void vDSP_vsmul(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vsmulD(const double *A, vDSP_Stride IA, const double *B, double *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvzsml(const DSPSplitComplex *A, vDSP_Stride IA, const DSPSplitComplex *B, const DSPSplitComplex *C, 
                                   vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_zvzsmlD(const DSPDoubleSplitComplex *A, vDSP_Stride IA, const DSPDoubleSplitComplex *B, const DSPDoubleSplitComplex *C,
                                    vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vadd(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, float *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vaddD(const double *A, vDSP_Stride IA, const double *B, vDSP_Stride IB, double *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vasm(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, const float *C, float *D, vDSP_Stride ID, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vasmD(const double *A, vDSP_Stride IA, const double *B, vDSP_Stride IB, const double *C, double *D, vDSP_Stride ID, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vmul(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, float *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_vmulD(const double *A, vDSP_Stride IA, const double *B, vDSP_Stride IB, double *C, vDSP_Stride IC, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_maxv(const float *A, vDSP_Stride IA, float *C, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_maxvD(const double *A, vDSP_Stride IA, double *C, vDSP_Length N); 
ACCELERATE_EXPORT void vDSP_measqv(const float *A, vDSP_Stride IA, float *C, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_measqvD(const double *A, vDSP_Stride IA, double *C, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_rmsqv(const float *A, vDSP_Stride IA, float *C, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_rmsqvD(const double *A, vDSP_Stride IA, double *C, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_ctoz(const DSPComplex *C, vDSP_Stride IC, const DSPSplitComplex *Z, vDSP_Stride IZ, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_ctozD(const DSPDoubleComplex *C, vDSP_Stride IC, const DSPDoubleSplitComplex *Z, vDSP_Stride IZ, vDSP_Length N);
ACCELERATE_EXPORT void vDSP_blkman_window(float *C, vDSP_Length N, int Flag);
ACCELERATE_EXPORT void vDSP_blkman_windowD(double *C, vDSP_Length N, int Flag);
ACCELERATE_EXPORT vDSP_DFT_Setup vDSP_DFT_zop_CreateSetup(vDSP_DFT_Setup __Previous, vDSP_Length __Length,
                                                          vDSP_DFT_Direction __Direction);
ACCELERATE_EXPORT vDSP_DFT_SetupD vDSP_DFT_zop_CreateSetupD(vDSP_DFT_SetupD __Previous, vDSP_Length __Length,
                                                            vDSP_DFT_Direction __Direction);
ACCELERATE_EXPORT vDSP_DFT_Setup vDSP_DFT_zrop_CreateSetup(vDSP_DFT_Setup __Previous, vDSP_Length __Length,
                                                           vDSP_DFT_Direction __Direction);
ACCELERATE_EXPORT vDSP_DFT_SetupD vDSP_DFT_zrop_CreateSetupD(vDSP_DFT_SetupD __Previous, vDSP_Length __Length,
                                                             vDSP_DFT_Direction __Direction);
ACCELERATE_EXPORT void vDSP_DFT_DestroySetup(vDSP_DFT_Setup __Setup);
ACCELERATE_EXPORT void vDSP_DFT_DestroySetupD(vDSP_DFT_SetupD __Setup);
ACCELERATE_EXPORT void vDSP_DFT_Execute(const struct vDSP_DFT_SetupStruct *__Setup, const float *__Ir, const float *__Ii, float *__Or,
                                        float *__Oi);
ACCELERATE_EXPORT void vDSP_DFT_ExecuteD(const struct vDSP_DFT_SetupStructD *__Setup, const double *__Ir, const double *__Ii, double *__Or,
                                         double *__Oi);