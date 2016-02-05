//******************************************************************************
//
// Copyright (c) 2016, Intel Corporation
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


#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <algorithm>
#include "Accelerate\vDSP.h"


void vDSP_vabs(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = abs(A[i*IA]);
    }
}


void vDSP_vabsD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = abs(A[i*IA]);
    }
}


void vDSP_vabsi(const int* A, vDSP_Stride IA, int* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = abs(A[i*IA]);
    }
}


void vDSP_zvabs(const DSPSplitComplex* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = hypot(A->realp[i*IA], A->imagp[i*IA]);
    }
}


void vDSP_zvabsD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = hypot(A->realp[i*IA], A->imagp[i*IA]);
    }
}


void vDSP_vnabs(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = -abs(A[i*IA]);
    }
}


void vDSP_vnabsD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = -abs(A[i*IA]);
    }
}


void vDSP_vneg(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = -A[i*IA];
    }
}


void vDSP_vnegD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = -A[i*IA];
    }
}


void vDSP_zvneg(const DSPSplitComplex* A, vDSP_Stride IA, const DSPSplitComplex* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = -A->realp[i*IA];
        C->imagp[i*IC] = -A->imagp[i*IA];
    }
}


void vDSP_zvnegD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, const DSPDoubleSplitComplex* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = -A->realp[i*IA];
        C->imagp[i*IC] = -A->imagp[i*IA];
    }
}


void vDSP_vfill(const float* A, float* C, vDSP_Stride IC, vDSP_Length N) {
    float a = *A;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = a;
    }
}


void vDSP_vfillD(const double* A, double* C, vDSP_Stride IC, vDSP_Length N) {
    double a = *A;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = a;
    }
}


void vDSP_vfilli(const int* A, int* C, vDSP_Stride IC, vDSP_Length N) {
    int a = *A;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = a;
    }
}


void vDSP_zvfill(const DSPSplitComplex* A, const DSPSplitComplex* C, vDSP_Stride IC, vDSP_Length N) {
    float real = *(A->realp);
    float imag = *(A->imagp);
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = real;
        C->imagp[i*IC] = imag;
    }
}


void vDSP_zvfillD(const DSPDoubleSplitComplex* A, const DSPDoubleSplitComplex* C, vDSP_Stride IC, vDSP_Length N) {
    double real = *(A->realp);
    double imag = *(A->imagp);
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = real;
        C->imagp[i*IC] = imag;
    }
}


void vDSP_vclr(float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = 0.0;
    }
}


void vDSP_vclrD(double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = 0.0;
    }
}


void vDSP_vramp(const float* A, const float* B, float* C, vDSP_Stride IC, vDSP_Length N) {
    float a = *A;
    float b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = a + i*b;
    }
}


void vDSP_vrampD(const double* A, const double* B, double* C, vDSP_Stride IC, vDSP_Length N) {
    double a = *A;
    double b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = a + i*b;
    }
}


void vDSP_vrampmul(const float* I, vDSP_Stride IS, float* Start, const float* Step, float* O, vDSP_Stride OS, vDSP_Length N) {
    float step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O[i*OS] = *Start * I[i*IS];
        *Start +=  step;
    }
}


void vDSP_vrampmulD(const double* I, vDSP_Stride IS, double* Start, const double* Step, double* O, vDSP_Stride OS, vDSP_Length N) {
    double step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O[i*OS] = *Start * I[i*IS];
        *Start +=  step;
    }
}


void vDSP_vrampmul2(const float* I0, const float* I1, vDSP_Stride IS, float* Start, const float* Step, float* O0, float* O1, 
                     vDSP_Stride OS, vDSP_Length N) {
    float step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O0[i*OS] = *Start * I0[i*IS];
        O1[i*OS] = *Start * I1[i*IS];
        *Start +=  step;
    }
}


void vDSP_vrampmul2D(const double* I0, const double* I1, vDSP_Stride IS, double* Start, const double* Step, double* O0, double* O1, 
                     vDSP_Stride OS, vDSP_Length N) {
    double step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O0[i*OS] = *Start * I0[i*IS];
        O1[i*OS] = *Start * I1[i*IS];
        *Start +=  step;
    }
}


void vDSP_vrampmuladd(const float* I, vDSP_Stride IS, float* Start, const float* Step, float* O, vDSP_Stride OS, vDSP_Length N) {
    float step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O[i*OS] +=  *Start * I[i*IS];
        *Start +=  step;
    }
}


void vDSP_vrampmuladdD(const double* I, vDSP_Stride IS, double* Start, const double* Step, double* O, vDSP_Stride OS, vDSP_Length N) {
    double step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O[i*OS] +=  *Start * I[i*IS];
        *Start +=  step;
    }
}


void vDSP_vrampmuladd2(const float* I0, const float* I1, vDSP_Stride IS, float* Start, const float* Step, float* O0, float* O1, 
                       vDSP_Stride OS, vDSP_Length N) {
    float step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O0[i*OS] +=  *Start * I0[i*IS];
        O1[i*OS] +=  *Start * I1[i*IS];
        *Start +=  step;
    }
}


void vDSP_vrampmuladd2D(const double* I0, const double* I1, vDSP_Stride IS, double* Start, const double* Step, double* O0, double* O1, 
                        vDSP_Stride OS, vDSP_Length N) {
    double step = *Step;
    for (vDSP_Length i = 0; i < N; ++i) {
        O0[i*OS] +=  *Start * I0[i*IS];
        O1[i*OS] +=  *Start * I1[i*IS];
        *Start +=  step;
    }
}


void vDSP_vgen(const float* A, const float* B, float* C, vDSP_Stride IC, vDSP_Length N) {
    float a = *A;
    float b = *B;
    unsigned long Nm1 = N - 1;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = a + (i * ((b - a) / Nm1));
    }
}


void vDSP_vgenD(const double* A, const double* B, double* C, vDSP_Stride IC, vDSP_Length N) {
    double a = *A;
    double b = *B;
    unsigned long Nm1 = N - 1;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = a + (i * ((b - a) / Nm1));
    }
}


void vDSP_vsq(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * A[i*IA];
    }
}


void vDSP_vsqD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * A[i*IA];
    }
}


void vDSP_vssq(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * abs(A[i*IA]);
    }
}


void vDSP_vssqD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * abs(A[i*IA]);
    }
}


void vDSP_zvmags(const DSPSplitComplex* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A->realp[i*IA] * A->realp[i*IA] + A->imagp[i*IA] * A->imagp[i*IA];
    }
}


void vDSP_zvmagsD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A->realp[i*IA] * A->realp[i*IA] + A->imagp[i*IA] * A->imagp[i*IA];
    }
}


void vDSP_zvmgsa(const DSPSplitComplex* A, vDSP_Stride IA, const float* B, vDSP_Stride IB, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A->realp[i*IA] * A->realp[i*IA] + A->imagp[i*IA] * A->imagp[i*IA] + B[i*IB];
    }
}


void vDSP_zvmgsaD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, const double* B, vDSP_Stride IB, double* C, vDSP_Stride IC, 
                  vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A->realp[i*IA] * A->realp[i*IA] + A->imagp[i*IA] * A->imagp[i*IA] + B[i*IB];
    }
}


void vDSP_vfrac(const float* A, vDSP_Stride IA, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] - trunc(A[i*IA]);
    }
}


void vDSP_vfracD(const double* A, vDSP_Stride IA, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] - trunc(A[i*IA]);
    }
}


void vDSP_vclip(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N) {
    float b = *B;
    float c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] < b) ? b : ((A[i*IA] > c) ? c : A[i*IA]);
    }
}


void vDSP_vclipD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID, vDSP_Length N) {
    double b = *B;
    double c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] < b) ? b : ((A[i*IA] > c) ? c : A[i*IA]);
    }
}


void vDSP_vclipc(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N, 
                 vDSP_Length* NLow, vDSP_Length* NHigh) {
    float b = *B;
    float c = *C;
    unsigned long nlow = 0;
    unsigned long nhigh = 0;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] < b) ? ++nlow, b : ((A[i*IA] > c) ? ++nhigh, c : A[i*IA]);
    }
    *NLow = nlow;
    *NHigh = nhigh;
}


void vDSP_vclipcD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID, vDSP_Length N, 
                  vDSP_Length* NLow, vDSP_Length* NHigh) {
    double b = *B;
    double c = *C;
    unsigned long nlow = 0;
    unsigned long nhigh = 0;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] < b) ? ++nlow, b : ((A[i*IA] > c) ? ++nhigh, c : A[i*IA]);
    }
    *NLow = nlow;
    *NHigh = nhigh;
}


void vDSP_viclip(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N) {
    float b = *B;
    float c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] <=  b || A[i*IA] >=  c) ? A[i*IA] : ((A[i*IA] < 0) ? b : c);
    }
}


void vDSP_viclipD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID, vDSP_Length N) {
    double b = *B;
    double c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] <=  b || A[i*IA] >=  c) ? A[i*IA] : ((A[i*IA] < 0) ? b : c);
    }
}


void vDSP_vlim(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N) {
    float b = *B;
    float c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] >=  b) ? c : -c;
    }
}


void vDSP_vlimD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID, vDSP_Length N) {
    double b = *B;
    double c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] >=  b) ? c : -c;
    }
}


void vDSP_vthr(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N) {
    float  b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = (A[i*IA] >=  b) ? A[i*IA] : b;
    }
}


void vDSP_vthrD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N) {
    double  b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = (A[i*IA] >=  b) ? A[i*IA] : b;
    }
}


void vDSP_vthres(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N) {
    float  b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = (A[i*IA] >=  b) ? A[i*IA] : 0;
    }
}


void vDSP_vthresD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N) {
    double  b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = (A[i*IA] >=  b) ? A[i*IA] : 0;
    }
}


void vDSP_vthrsc(const float* A, vDSP_Stride IA, const float* B, const float* C, float* D, vDSP_Stride ID, vDSP_Length N) {
    float b = *B;
    float c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] >=  b) ? c : -c;
    }
}


void vDSP_vthrscD(const double* A, vDSP_Stride IA, const double* B, const double* C, double* D, vDSP_Stride ID, vDSP_Length N) {
    double b = *B;
    double c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] >=  b) ? c : -c;
    }
}


void vDSP_vcmprs(const float* A, vDSP_Stride IA, const float* B, vDSP_Stride IB, float* C, vDSP_Stride IC, vDSP_Length N) {
    vDSP_Length j = 0;
    for (vDSP_Length i = 0; i < N; ++i) {
        if (B[i*IB] !=  0) {
            C[j++ * IC] = A[i*IA];
        }
    }
}


void vDSP_vcmprsD(const double* A, vDSP_Stride IA, const double* B, vDSP_Stride IB, double* C, vDSP_Stride IC, vDSP_Length N) {
    vDSP_Length j = 0;
    for (vDSP_Length i = 0; i < N; ++i) {
        if (B[i*IB] !=  0) {
            C[j++ * IC] = A[i*IA];
        }
    }
}


void vDSP_vgathr(const float* A, const vDSP_Length* B, vDSP_Stride IB, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[B[i*IB] - 1];
    }
}


void vDSP_vgathrD(const double* A, const vDSP_Length* B, vDSP_Stride IB, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[B[i*IB] - 1];
    }
}



void vDSP_vindex(const float* A, const float* B, vDSP_Stride IB, float* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[static_cast<vDSP_Length>(trunc(B[i*IB]))];
    }
}


void vDSP_vindexD(const double* A, const double* B, vDSP_Stride IB, double* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[static_cast<vDSP_Length>(trunc(B[i*IB]))];
    }
}


void vDSP_vrvrs(float* C, vDSP_Stride IC, vDSP_Length N) {
    vDSP_Length n = N / 2;
    float temp;
    for (vDSP_Length i = 0; i < n; ++i) {
        temp = C[i*IC];
        C[i*IC] = C[(N - i - 1)*IC];
        C[(N - i - 1)*IC] = temp;
    }
}


void vDSP_vrvrsD(double* C, vDSP_Stride IC, vDSP_Length N) {
    vDSP_Length n = N / 2;
    double temp;
    for (vDSP_Length i = 0; i < n; ++i) {
        temp = C[i*IC];
        C[i*IC] = C[(N - i - 1)*IC];
        C[(N - i - 1)*IC] = temp;
    }
}


void vDSP_zvmov(const DSPSplitComplex* A, vDSP_Stride IA, const DSPSplitComplex* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = A->realp[i*IA];
        C->imagp[i*IC] = A->imagp[i*IA];
    }
}


void vDSP_zvmovD(const DSPDoubleSplitComplex* A, vDSP_Stride IA, const DSPDoubleSplitComplex* C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = A->realp[i*IA];
        C->imagp[i*IC] = A->imagp[i*IA];
    }
}


void vDSP_nzcros(const float* A, vDSP_Stride IA, vDSP_Length B, vDSP_Length* C, vDSP_Length* D, vDSP_Length N) {
    vDSP_Length d = 0;
    for (vDSP_Length i = 1; i < N; ++i) {
        if (signbit(A[i*IA]) !=  signbit(A[(i - 1)*IA])) {
            if (++d ==  B) {
                *C = i*IA;
                break;
            }
        }
    }
    *D = d;
}


void vDSP_nzcrosD(const double* A, vDSP_Stride IA, vDSP_Length B, vDSP_Length* C, vDSP_Length* D, vDSP_Length N) {
    vDSP_Length d = 0;
    for (vDSP_Length i = 1; i < N; ++i) {
        if (signbit(A[i*IA]) !=  signbit(A[(i - 1)*IA])) {
            d++;
            if (d ==  B) {
                *C = i*IA;
                break;
            }
        }
    }
    *D = d;
}


void vDSP_vavlin(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N) {
    float b = *B;
    float bP1 = b + 1;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = (C[i*IC] / bP1)*b + A[i*IA] / bP1;
    }
}


void vDSP_vavlinD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N) {
    double b = *B;
    double bP1 = b + 1.0;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = (C[i*IC] / bP1)*b + A[i*IA] / bP1;
    }
}


void vDSP_vrsum(const float* A, vDSP_Stride IA, const float* S, float* C, vDSP_Stride IC, vDSP_Length N) {
    float s = *S;
    C[0] = 0.0;
    for (vDSP_Length i = 1; i < N; ++i) {
        C[i*IC] = C[(i - 1)*IC] + s*A[i*IA];
    }
}


void vDSP_vrsumD(const double* A, vDSP_Stride IA, const double* S, double* C, vDSP_Stride IC, vDSP_Length N) {
    double s = *S;
    C[0] = 0.0;
    for (vDSP_Length i = 1; i < N; ++i) {
        C[i*IC] = C[(i - 1)*IC] + s*A[i*IA];
    }
}


void vDSP_vtrapz(const float* A, vDSP_Stride IA, const float* B, float* C, vDSP_Stride IC, vDSP_Length N) {
    float b2 = *B / 2;
    C[0] = 0.0;
    for (vDSP_Length i = 1; i < N; ++i) {
        C[i*IC] = C[(i - 1)*IC] + b2*(A[(i - 1)*IA] + A[i*IA]);
    }
}


void vDSP_vtrapzD(const double* A, vDSP_Stride IA, const double* B, double* C, vDSP_Stride IC, vDSP_Length N) {
    double b2 = *B / 2;
    C[0] = 0.0;
    for (vDSP_Length i = 1; i < N; ++i) {
        C[i*IC] = C[(i - 1)*IC] + b2*(A[(i - 1)*IA] + A[i*IA]);
    }
}


void vDSP_vdbcon(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC,
                 vDSP_Length N, unsigned int F) {
    float b = *B;
    int alpha = (F == 0) ? 10 : 20;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = alpha * log10(A[i*IA] / b);
    }
}


void vDSP_vdbconD(const double *A, vDSP_Stride IA, const double *B, double *C, vDSP_Stride IC,
                  vDSP_Length N, unsigned int F) {
    double b = *B;
    int alpha = (F == 0) ? 10 : 20;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = alpha * log10(A[i*IA] / b);
    }
}


void vDSP_vsadd(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC, vDSP_Length N) {
    float b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] + b;
    }
}


void vDSP_vsaddD(const double *A, vDSP_Stride IA, const double *B, double *C, vDSP_Stride IC, vDSP_Length N) {
    double b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] + b;
    }
}


void vDSP_vsaddi(const int *A, vDSP_Stride IA, const int *B, int *C, vDSP_Stride IC, vDSP_Length N) {
    int b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] + b;
    }
}


void vDSP_vsmul(const float *A, vDSP_Stride IA, const float *B, float *C, vDSP_Stride IC, vDSP_Length N) {
    float b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * b;
    }
}


void vDSP_vsmulD(const double *A, vDSP_Stride IA, const double *B, double *C, vDSP_Stride IC, vDSP_Length N) {
    double b = *B;
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * b;
    }
}


void vDSP_zvzsml(const DSPSplitComplex *A, vDSP_Stride IA, const DSPSplitComplex *B, const DSPSplitComplex *C,
                 vDSP_Stride IC, vDSP_Length N) {
    float realB = *(B->realp);
    float imagB = *(B->imagp);
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = A->realp[i*IA] * realB - A->imagp[i*IA] * imagB;
        C->imagp[i*IC] = A->realp[i*IA] * imagB + A->imagp[i*IA] * realB;
    }
}


void vDSP_zvzsmlD(const DSPDoubleSplitComplex *A, vDSP_Stride IA, const DSPDoubleSplitComplex *B, const DSPDoubleSplitComplex *C,
                  vDSP_Stride IC, vDSP_Length N) {
    double realB = *(B->realp);
    double imagB = *(B->imagp);
    for (vDSP_Length i = 0; i < N; ++i) {
        C->realp[i*IC] = A->realp[i*IA] * realB - A->imagp[i*IA] * imagB;
        C->imagp[i*IC] = A->realp[i*IA] * imagB + A->imagp[i*IA] * realB;
    }
}


void vDSP_vadd(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, float *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] + B[i*IB];
    }
}


void vDSP_vaddD(const double *A, vDSP_Stride IA, const double *B, vDSP_Stride IB, double *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] + B[i*IB];
    }
}


void vDSP_vasm(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, const float *C, float *D, vDSP_Stride ID, vDSP_Length N) {
    float c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] + B[i*IB]) * c;
    }
}


void vDSP_vasmD(const double *A, vDSP_Stride IA, const double *B, vDSP_Stride IB, const double *C, double *D, vDSP_Stride ID, 
                vDSP_Length N) {
    double c = *C;
    for (vDSP_Length i = 0; i < N; ++i) {
        D[i*ID] = (A[i*IA] + B[i*IB]) * c;
    }
}


void vDSP_vmul(const float *A, vDSP_Stride IA, const float *B, vDSP_Stride IB, float *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * B[i*IB];
    }
}


void vDSP_vmulD(const double *A, vDSP_Stride IA, const double *B, vDSP_Stride IB, double *C, vDSP_Stride IC, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        C[i*IC] = A[i*IA] * B[i*IB];
    }
}


void vDSP_maxv(const float *A, vDSP_Stride IA, float *C, vDSP_Length N) {
    float c = FLT_MIN;
    for (vDSP_Length i = 0; i < N; ++i) {
        if (c < A[i*IA]) {
            c = A[i*IA];
        }
    }
    *C = c;
}


void vDSP_maxvD(const double *A, vDSP_Stride IA, double *C, vDSP_Length N) {
    double c = DBL_MIN;
    for (vDSP_Length i = 0; i < N; ++i) {
        if (c < A[i*IA]) {
            c = A[i*IA];
        }
    }
    *C = c;
}


void vDSP_measqv(const float *A, vDSP_Stride IA, float *C, vDSP_Length N) {
    float c = FP_ZERO;
    float t;
    if (N > 0) {
        float scale = 1.0f / sqrtf(static_cast<float>(N));
        for (vDSP_Length i = 0; i < N; ++i) {
            t = A[i*IA] * scale;
            c += t*t;
        }

        *C = c;
    }
    else {
        *C = FP_NAN;
    }
}


void vDSP_measqvD(const double *A, vDSP_Stride IA, double *C, vDSP_Length N) {
    double c = FP_ZERO;
    double t;
    if (N > 0) {
        double scale = 1.0 / sqrt(N);
        for (vDSP_Length i = 0; i < N; ++i) {
            t = A[i*IA] * scale;
            c += t*t;
        }

        *C = c;
    }
    else {
        *C = FP_NAN;
    }
}


void vDSP_rmsqv(const float *A, vDSP_Stride IA, float *C, vDSP_Length N) {
    float c = FP_ZERO;
    float t;
    if (N > 0) {
        float max = FP_ZERO;
        for (vDSP_Length i = 0; i < N; ++i) {
            float val = fabs(A[i*IA]);
            if (val > max) {
                max = val;
            }
        }
        if (max > 0) {
            float scale = 1.0f / (max * sqrtf(static_cast<float>(N)));
            for (vDSP_Length i = 0; i < N; ++i) {
                t = A[i*IA] * scale;
                c += t*t;
            }
            c = sqrt(c) * max;
        }
        *C = c;
    }
    else {
        *C = FP_NAN;
    }
}



void vDSP_rmsqvD(const double *A, vDSP_Stride IA, double *C, vDSP_Length N) {
    double c = FP_ZERO;
    double t;
    if (N > 0) {
        double max = FP_ZERO;
        for (vDSP_Length i = 0; i < N; ++i) {
            double val = fabs(A[i*IA]);
            if (val > max) {
                max = val;
            }
        }
        if (max > 0) {
            double scale = 1.0 / (max * sqrt(N));
            for (vDSP_Length i = 0; i < N; ++i) {
                t = A[i*IA] * scale;
                c += t*t;
            }
            c = sqrt(c) * max;
        }
        *C = c;
    }
    else {
        *C = FP_NAN;
    }
}


void vDSP_ctoz(const DSPComplex *C, vDSP_Stride IC, const DSPSplitComplex *Z, vDSP_Stride IZ, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        Z->realp[i*IZ] = C[i*IC/2].real;
        Z->imagp[i*IZ] = C[i*IC/2].imag;
    }
}


void vDSP_ctozD(const DSPDoubleComplex *C, vDSP_Stride IC, const DSPDoubleSplitComplex *Z, vDSP_Stride IZ, vDSP_Length N) {
    for (vDSP_Length i = 0; i < N; ++i) {
        Z->realp[i*IZ] = C[i*IC / 2].real;
        Z->imagp[i*IZ] = C[i*IC / 2].imag;
    }
}


void vDSP_blkman_window(float *C, vDSP_Length N, int Flag) {
    vDSP_Length n = (Flag == 0) ? N : (N + 1) / 2;
    for (vDSP_Length i = 0; i < n; ++i) {
        C[i] = 0.42f - (0.5f * cosf(2 * static_cast<float>(M_PI) * i / N)) + (0.08f * cosf(4 * static_cast<float>(M_PI)  * i / N));
    }
    
}

    
void vDSP_blkman_windowD(double *C, vDSP_Length N, int Flag) {
    vDSP_Length n = (Flag == 0) ? N : (N + 1) / 2;
    for (vDSP_Length i = 0; i < n; ++i) {
        C[i] = 0.42 - (0.5 * cos(2 * M_PI * i / N)) + (0.08 * cos(4 * M_PI * i / N));
    }
}

