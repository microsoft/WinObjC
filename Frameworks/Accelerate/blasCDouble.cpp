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

#define SCALAR std::complex<double>
#define SCALAR_SUFFIX z
#define SCALAR_SUFFIX_UP "Z"
#define REAL_SCALAR_SUFFIX d
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


void catlas_zset(const int N, const void* alpha, void* X, const int incX) {
    if (incX >= 1 && X != nullptr) {
        int n = 2 * N;
        int incx = 2 * incX;
        double* x = VDOUBLECAST(X);
        double* a = VDOUBLECAST(alpha);
        double a0 = a[0];
        double a1 = a[1];
        for (int i = 0; i < n; i += incx) {
            x[i] = a0;
            x[i + 1] = a1;
        }
    }
}


void cblas_zrotg(void* a, void* b, void* c, void* s) {
    EigenFunc_zrotg(VDOUBLECAST(a), VDOUBLECAST(b), VDOUBLECAST(c), VDOUBLECAST(s));
}


void cblas_zdrot(const int N, void* X, const int incX, void* Y, const int incY, const double c, const double s) {
    EigenFunc_zdrot(INTCAST(&N), VDOUBLECAST(X), INTCAST(&incX), VDOUBLECAST(Y), INTCAST(&incY), DOUBLECAST(&c), DOUBLECAST(&s));
}


void __izamax_sub__(const int* N, void* X, const int* incX, int* iamax) {
    *iamax = EigenFunc_izamax(INTCAST(N), VDOUBLECAST(X), INTCAST(incX));
}


void __dzasum_sub__(const int* N, void* X, const int* incX, double* asum) {
    *asum = EigenFunc_dzasum(INTCAST(N), VDOUBLECAST(X), INTCAST(incX));
}


void __dznrm2_sub__(const int* N, void* X, const int* incX, double* nrm2) {
    *nrm2 = EigenFunc_dznrm2(INTCAST(N), VDOUBLECAST(X), INTCAST(incX));
}


void __zdotu_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotu) {
    EigenFunc_zdotu_sub(INTCAST(N), VDOUBLECAST(X), INTCAST(incX), VDOUBLECAST(Y), INTCAST(incY), RDOUBLECAST(dotu));
}


void __zdotc_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotc) {
    EigenFunc_zdotc_sub(INTCAST(N), VDOUBLECAST(X), INTCAST(incX), VDOUBLECAST(Y), INTCAST(incY), RDOUBLECAST(dotc));
}


void __zswap__(const int* N, void* X, const int* incX, void* Y, const int* incY) {
    EigenFunc_zswap(INTCAST(N), RDOUBLECAST(X), INTCAST(incX), RDOUBLECAST(Y), INTCAST(incY));
}


void __zcopy__(const int* N, const void* X, const int* incX, void* Y, const int* incY) {
    EigenFunc_zcopy(INTCAST(N), VDOUBLECAST(X), INTCAST(incX), RDOUBLECAST(Y), INTCAST(incY));
}


void __zaxpy__(const int* N, const void* alpha, const void* X, const int* incX, void* Y, const int* incY) {
    EigenFunc_zaxpy(INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(X), INTCAST(incX), RDOUBLECAST(Y), INTCAST(incY));
}


void __zscal__(const int* N, const void* alpha, void* X, const int* incX) {
    EigenFunc_zscal(INTCAST(N), VDOUBLECAST(alpha), RDOUBLECAST(X), INTCAST(incX));
}


void __zdscal__(const int* N, const double* alpha, void* X, const int* incX) {
    EigenFunc_zdscal(INTCAST(N), DOUBLECAST(alpha), RDOUBLECAST(X), INTCAST(incX));
}


void __zgemv__(char* TransA, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* X, 
               const int* incX, const void* beta, void* Y, const int* incY) {
    EigenFunc_zgemv(TransA, INTCAST(M), INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(X), INTCAST(incX),
                    VDOUBLECAST(beta), RDOUBLECAST(Y), INTCAST(incY));
}


void __zgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const void* alpha, const void* A, const int* lda,
               const void* X, const int* incX, const void* beta, void* Y, const int* incY) {
    EigenFunc_zgbmv(TransA, INTCAST(M), INTCAST(N), INTCAST(KL), INTCAST(KU), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), 
                    VDOUBLECAST(X), INTCAST(incX), VDOUBLECAST(beta), RDOUBLECAST(Y), INTCAST(incY));
}


void __ztrmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX) {
    EigenFunc_ztrmv(Uplo, TransA, Diag, INTCAST(N), VDOUBLECAST(A), INTCAST(lda), RDOUBLECAST(X), INTCAST(incX));
}


void __ztpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX) {
    EigenFunc_ztpmv(Uplo, TransA, Diag, INTCAST(N), VDOUBLECAST(Ap), RDOUBLECAST(X), INTCAST(incX));
}


void __ztrsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX) {
    EigenFunc_ztrsv(Uplo, TransA, Diag, INTCAST(N), VDOUBLECAST(A), INTCAST(lda), RDOUBLECAST(X), INTCAST(incX));
}


void __ztbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const void* A, const int* lda, void* X, 
               const int* incX) {
    EigenFunc_ztbsv(Uplo, TransA, Diag, INTCAST(N), INTCAST(K), VDOUBLECAST(A), INTCAST(lda), RDOUBLECAST(X), INTCAST(incX));
}


void __ztpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX) {
    EigenFunc_ztpsv(Uplo, TransA, Diag, INTCAST(N), VDOUBLECAST(Ap), RDOUBLECAST(X), INTCAST(incX));
}


void __zhemv__(char* Uplo, const int* N, const void* alpha, const void* A, const int* lda, const void* X, const int* incX, 
               const void* beta, void* Y, const int* incY) {
    EigenFunc_zhemv(Uplo, INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(X), INTCAST(incX), 
                    VDOUBLECAST(beta), RDOUBLECAST(Y), INTCAST(incY));
}


void __zgeru__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, 
               void* A, const int* lda) {
    EigenFunc_zgeru(INTCAST(M), INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(X), INTCAST(incX), VDOUBLECAST(Y), INTCAST(incY), 
                    RDOUBLECAST(A), INTCAST(lda));
}


void __zgerc__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda) {
    EigenFunc_zgerc(INTCAST(M), INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(X), INTCAST(incX), VDOUBLECAST(Y), INTCAST(incY), 
                    RDOUBLECAST(A), INTCAST(lda));
}


void __zher__(char* Uplo, const int* N, const double* alpha, const void* X, const int* incX, void* A, const int* lda) {
    EigenFunc_zher(Uplo, INTCAST(N), DOUBLECAST(alpha), VDOUBLECAST(X), INTCAST(incX), RDOUBLECAST(A), INTCAST(lda));
}


void __zhpr__(char* Uplo, const int* N, const double* alpha, const void* X, const int* incX, void* A) {
    EigenFunc_zhpr(Uplo, INTCAST(N), DOUBLECAST(alpha), VDOUBLECAST(X), INTCAST(incX), RDOUBLECAST(A));
}


void __zher2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda) {
    EigenFunc_zher2(Uplo, INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(X), INTCAST(incX), VDOUBLECAST(Y), INTCAST(incY), RDOUBLECAST(A),
                    INTCAST(lda));
}


void __zhpr2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* Ap) {
    EigenFunc_zhpr2(Uplo, INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(X), INTCAST(incX), VDOUBLECAST(Y), INTCAST(incY), RDOUBLECAST(Ap));
}


void __zgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const void* alpha, const void* A, const int* lda,
               const void* B, const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_zgemm(TransA, TransB, INTCAST(M), INTCAST(N), INTCAST(K), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(B),
                    INTCAST(ldb), VDOUBLECAST(beta), RDOUBLECAST(C), INTCAST(ldc));
}


void __zsymm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
               const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_zsymm(Side, Uplo, INTCAST(M), INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(B), INTCAST(ldb),
                    VDOUBLECAST(beta), RDOUBLECAST(C), INTCAST(ldc));
}


void __zsyrk__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* beta,
               void* C, const int* ldc) {
    EigenFunc_zsyrk(Uplo, Trans, INTCAST(N), INTCAST(K), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(beta), 
                    RDOUBLECAST(C), INTCAST(ldc));
}


void __zsyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_zsyr2k(Uplo, Trans, INTCAST(N), INTCAST(K), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(B), INTCAST(ldb),
                     VDOUBLECAST(beta), RDOUBLECAST(C), INTCAST(ldc));
}


void __ztrmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, 
               const int* lda, void* B, const int* ldb) {
    EigenFunc_ztrmm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), RDOUBLECAST(B),
                    INTCAST(ldb));
}


void __ztrsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, 
               const int* lda, void* B, const int* ldb) {
    EigenFunc_ztrsm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), RDOUBLECAST(B),
                    INTCAST(ldb));
}


void __zhemm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
               const int* ldb, const void* beta, void* C, const int* ldc) {
    EigenFunc_zhemm(Side, Uplo, INTCAST(M), INTCAST(N), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(B), INTCAST(ldb),
                    VDOUBLECAST(beta), RDOUBLECAST(C), INTCAST(ldc));
}


void __zherk__(char* Uplo, char* Trans, const int* N, const int* K, const double* alpha, const void* A, const int* lda, 
               const double* beta, void* C, const int* ldc) {
    EigenFunc_zherk(Uplo, Trans, INTCAST(N), INTCAST(K), DOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), DOUBLECAST(beta), 
                    RDOUBLECAST(C), INTCAST(ldc));
}


void __zher2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const double* beta, void* C, const int* ldc) {
    EigenFunc_zher2k(Uplo, Trans, INTCAST(N), INTCAST(K), VDOUBLECAST(alpha), VDOUBLECAST(A), INTCAST(lda), VDOUBLECAST(B), INTCAST(ldb),
                     DOUBLECAST(beta), RDOUBLECAST(C), INTCAST(ldc));
}


#ifdef __cplusplus
}
#endif