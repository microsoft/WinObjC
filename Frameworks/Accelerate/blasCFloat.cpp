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


//The following 5 macros are used by the Eigen-BLAS header files.

#define SCALAR std::complex<float>
#define SCALAR_SUFFIX c
#define SCALAR_SUFFIX_UP "C"
#define REAL_SCALAR_SUFFIX s
#define ISCOMPLEX 1

#include "Eigen\blas\level1_impl.h"
#include "Eigen\blas\level1_cplx_impl.h"
#include "Eigen\blas\level2_impl.h"
#include "Eigen\blas\level2_cplx_impl.h"
#include "Eigen\blas\level3_impl.h"

#include "Accelerate\Accelerate.h"

#ifdef __cplusplus
extern "C" {
#endif


void catlas_cset(const int N, const void* alpha, void* X, const int incX) {
    if (incX >= 1 && X != nullptr) {
        int n = N * 2;
        int incx = 2 * incX;
        float* x = VFLOATCAST(X);
        float* a = VFLOATCAST(alpha);
        float a0 = a[0]; 
        float a1 = a[1];
        for (int i = 0; i < n; i += incx) {
            x[i] = a0;
            x[i + 1] = a1;
        }
    }
}


void cblas_crotg(void* a, void* b, void* c, void* s) {
    EigenFunc_crotg(VFLOATCAST(a), RFLOATCAST(b), VFLOATCAST(c), VFLOATCAST(s));
}


void cblas_csrot(const int N, void* X, const int incX, void* Y, const int incY, const float c, const float s) {
    EigenFunc_csrot(INTCAST(&N), VFLOATCAST(X), INTCAST(&incX), VFLOATCAST(Y), INTCAST(&incY), FLOATCAST(&c), FLOATCAST(&s));
}


void __icamax_sub__(const int* N, void* X, const int* incX, int* iamax) {
    *iamax = EigenFunc_icamax(INTCAST(N), VFLOATCAST(X), INTCAST(incX));
}


void __scasum_sub__(const int* N, void* X, const int* incX, float* asum) {
    *asum = EigenFunc_scasum(INTCAST(N), VFLOATCAST(X), INTCAST(incX));
}


void __scnrm2_sub__(const int* N, void* X, const int* incX, float* nrm2) {
    *nrm2 = EigenFunc_scnrm2(INTCAST(N), VFLOATCAST(X), INTCAST(incX));
}


void __cdotu_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotu) {
    EigenFunc_cdotu_sub(INTCAST(N), VFLOATCAST(X), INTCAST(incX), VFLOATCAST(Y), INTCAST(incY), RFLOATCAST(dotu));
}


void __cdotc_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotc) {
    EigenFunc_cdotc_sub(INTCAST(N), VFLOATCAST(X), INTCAST(incX), VFLOATCAST(Y), INTCAST(incY), RFLOATCAST(dotc));
}


void __cswap__(const int* N, void* X, const int* incX, void* Y, const int* incY) {
    EigenFunc_cswap(INTCAST(N), RFLOATCAST(X), INTCAST(incX), RFLOATCAST(Y), INTCAST(incY));
}


void __ccopy__(const int* N, const void* X, const int* incX, void* Y, const int* incY) {
    EigenFunc_ccopy(INTCAST(N), VFLOATCAST(X), INTCAST(incX), RFLOATCAST(Y), INTCAST(incY));
}


void __caxpy__(const int* N, const void* alpha, const void* X, const int* incX, void* Y, const int* incY) {
    EigenFunc_caxpy(INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(X), INTCAST(incX), RFLOATCAST(Y), INTCAST(incY));
}


void __cscal__(const int* N, const void* alpha, void* X, const int* incX) {
    EigenFunc_cscal(INTCAST(N), VFLOATCAST(alpha), RFLOATCAST(X), INTCAST(incX));
}


void __csscal__(const int* N, const float* alpha, void* X, const int* incX) {
    EigenFunc_csscal(INTCAST(N), FLOATCAST(alpha), RFLOATCAST(X), INTCAST(incX));
}


void __cgemv__(char* TransA, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* X,
               const int* incX, const void* beta, void* Y, const int* incY) {
    EigenFunc_cgemv(TransA, INTCAST(M), INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(X),
                    INTCAST(incX), VFLOATCAST(beta), RFLOATCAST(Y), INTCAST(incY));
}


void __cgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const void* alpha, const void* A, 
               const int* lda, const void* X, const int* incX, const void* beta, void* Y, const int* incY) {
    EigenFunc_cgbmv(TransA, INTCAST(M), INTCAST(N), INTCAST(KL), INTCAST(KU), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda),
                    VFLOATCAST(X), INTCAST(incX), VFLOATCAST(beta), RFLOATCAST(Y), INTCAST(incY));
}


void __ctrmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX) {
    EigenFunc_ctrmv(Uplo, TransA, Diag, INTCAST(N), VFLOATCAST(A), INTCAST(lda), RFLOATCAST(X), INTCAST(incX));
}


void __ctpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX) {
    EigenFunc_ctpmv(Uplo, TransA, Diag, INTCAST(N), VFLOATCAST(Ap), RFLOATCAST(X), INTCAST(incX));
}


void __ctrsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX) {
    EigenFunc_ctrsv(Uplo, TransA, Diag, INTCAST(N), VFLOATCAST(A), INTCAST(lda), RFLOATCAST(X), INTCAST(incX));
}


void __ctbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const void* A, const int* lda,
               void* X, const int* incX) {
    EigenFunc_ctbsv(Uplo, TransA, Diag, INTCAST(N), INTCAST(K), VFLOATCAST(A), INTCAST(lda), RFLOATCAST(X), INTCAST(incX));
}


void __ctpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX) {
    EigenFunc_ctpsv(Uplo, TransA, Diag, INTCAST(N), VFLOATCAST(Ap), RFLOATCAST(X), INTCAST(incX));
}


void __chemv__(char* Uplo, const int* N, const void* alpha, const void* A, const int* lda, const void* X, const int* incX,
               const void* beta, void* Y, const int* incY) {
    EigenFunc_chemv(Uplo, INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(X), INTCAST(incX),
                    VFLOATCAST(beta), RFLOATCAST(Y), INTCAST(incY));
}


void __cgeru__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY,
               void* A, const int* lda) {
    EigenFunc_cgeru(INTCAST(M), INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(X), INTCAST(incX), VFLOATCAST(Y), INTCAST(incY),
                    RFLOATCAST(A), INTCAST(lda));
}


void __cgerc__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY,
               void* A, const int* lda) {
    EigenFunc_cgerc(INTCAST(M), INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(X), INTCAST(incX), VFLOATCAST(Y), INTCAST(incY),
                    RFLOATCAST(A), INTCAST(lda));
}


void __cher__(char* Uplo, const int* N, const float* alpha, const void* X, const int* incX, void* A, const int* lda) {
    EigenFunc_cher(Uplo, INTCAST(N), FLOATCAST(alpha), VFLOATCAST(X), INTCAST(incX), RFLOATCAST(A), INTCAST(lda));
}


void __chpr__(char* Uplo, const int* N, const float* alpha, const void* X, const int* incX, void* A) {
    EigenFunc_chpr(Uplo, INTCAST(N), FLOATCAST(alpha), VFLOATCAST(X), INTCAST(incX), RFLOATCAST(A));
}


void __cher2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
                 const int* lda) {
    EigenFunc_cher2(Uplo, INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(X), INTCAST(incX), VFLOATCAST(Y), INTCAST(incY), RFLOATCAST(A),
                 INTCAST(lda));
}


void __chpr2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* Ap) {
    EigenFunc_chpr2(Uplo, INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(X), INTCAST(incX), VFLOATCAST(Y), INTCAST(incY), RFLOATCAST(Ap));
}


void __cgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const void* alpha, const void* A, const int* lda,
                 const void* B, const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_cgemm(TransA, TransB, INTCAST(M), INTCAST(N), INTCAST(K), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(B),
                 INTCAST(ldb), VFLOATCAST(beta), RFLOATCAST(C), INTCAST(ldc));
}


void __csymm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
               const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_csymm(Side, Uplo, INTCAST(M), INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(B), INTCAST(ldb),
                 VFLOATCAST(beta), RFLOATCAST(C), INTCAST(ldc));
}


void __csyrk__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* beta,
               void* C, const int* ldc) {
    EigenFunc_csyrk(Uplo, Trans, INTCAST(N), INTCAST(K), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(beta),
                    RFLOATCAST(C), INTCAST(ldc));
}


void __csyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_csyr2k(Uplo, Trans, INTCAST(N), INTCAST(K), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(B), INTCAST(ldb),
                 VFLOATCAST(beta), RFLOATCAST(C), INTCAST(ldc));
}


void __ctrmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, 
               const int* lda, void* B, const int* ldb) {
    EigenFunc_ctrmm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(A), 
                    INTCAST(lda), RFLOATCAST(B), INTCAST(ldb));
}


void __ctrsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, 
               const int* lda, void* B, const int* ldb) {
    EigenFunc_ctrsm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(A), 
                    INTCAST(lda), RFLOATCAST(B), INTCAST(ldb));
}


void __chemm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
                 const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_chemm(Side, Uplo, INTCAST(M), INTCAST(N), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(B), INTCAST(ldb),
                 VFLOATCAST(beta), RFLOATCAST(C), INTCAST(ldc));
}


void __cherk__(char* Uplo, char* Trans, const int* N, const int* K, const float* alpha, const void* A, const int* lda, 
              const float* beta, void* C, const int* ldc) {
    EigenFunc_cherk(Uplo, Trans, INTCAST(N), INTCAST(K), FLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), 
                    FLOATCAST(beta), RFLOATCAST(C), INTCAST(ldc));
}


void __cher2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const float* beta, void* C, const int* ldc) {
    EigenFunc_cher2k(Uplo, Trans, INTCAST(N), INTCAST(K), VFLOATCAST(alpha), VFLOATCAST(A), INTCAST(lda), VFLOATCAST(B), INTCAST(ldb),
                     FLOATCAST(beta), RFLOATCAST(C), INTCAST(ldc));
}


#ifdef __cplusplus
}
#endif