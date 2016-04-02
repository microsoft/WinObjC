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


//The following 4 macros are used by the Eigen-BLAS header files.

#define SCALAR double
#define SCALAR_SUFFIX d
#define SCALAR_SUFFIX_UP "D"
#define ISCOMPLEX 0

#include "Eigen\blas\level1_impl.h"
#include "Eigen\blas\level2_impl.h"
#include "Eigen\blas\level3_impl.h"
#include "Eigen\blas\level1_real_impl.h"
#include "Eigen\blas\level2_real_impl.h"

#include "Accelerate\Accelerate.h"

#ifdef __cplusplus
extern "C" {
#endif


void catlas_dset(const int N, const double alpha, double* X, const int incX) {
    if (incX >= 1 && X != nullptr) {
        for (int i = 0; i < N; i += incX) {
            X[i] = alpha;
        }
    }
}


void __ddot_sub__(const int* N, double* X, const int* incX, double* Y, const int* incY, double* dot) {
    *dot = EigenFunc_ddot(INTCAST(N), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY));
}


void __idamax_sub__(const int* N, double* X, const int* incX, int* iamax) {
    *iamax = EigenFunc_idamax(INTCAST(N), DOUBLECAST(X), INTCAST(incX));
}


void __dasum_sub__(const int* N, const double* X, const int* incX, double* asum) {
    *asum = EigenFunc_dasum(INTCAST(N), DOUBLECAST(X), INTCAST(incX));
}


void __dnrm2_sub__(const int* N, double* X, const int* incX, double* nrm2) {
    *nrm2 = EigenFunc_dnrm2(INTCAST(N), DOUBLECAST(X), INTCAST(incX));
}


void __dswap__(const int* N, double* X, const int* incX, double* Y, const int* incY) {
    EigenFunc_dswap(INTCAST(N), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY));
}


void __dcopy__(const int* N, const double* X, const int* incX, double* Y, const int* incY) {
    EigenFunc_dcopy(INTCAST(N), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY));
}


void __daxpy__(const int* N, const double* alpha, const double* X, const int* incX, double* Y, const int* incY) {
    EigenFunc_daxpy(INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY));
}


void __drotg__(double* a, double* b, double* c, double* s) {
    EigenFunc_drotg(DOUBLECAST(a), DOUBLECAST(b), DOUBLECAST(c), DOUBLECAST(s));
}


void __drot__(const int* N, double* X, const int* incX, double* Y, const int* incY, const double* c, const double* s) {
    EigenFunc_drot(INTCAST(N), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY), DOUBLECAST(c), DOUBLECAST(s));
}


void __dscal__(const int* N, const double* alpha, double* X, const int* incX) {
    EigenFunc_dscal(INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(X), INTCAST(incX));
}


void __dgemv__(char* TransA, const int* M, const int* N, const double* alpha, const double* A, const int* lda, const double* X,
               const int* incX, const double* beta, double* Y, const int* incY) {
    EigenFunc_dgemv(TransA, INTCAST(M), INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(A), INTCAST(lda), DOUBLECAST(X),
                    INTCAST(incX), DOUBLECAST(beta), DOUBLECAST(Y), INTCAST(incY));
}


void __dgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const double* alpha, const double* A,
               const int* lda, const double* X, const int* incX, const double* beta, double* Y, const int* incY) {
    EigenFunc_dgbmv(TransA, INTCAST(M), INTCAST(N), INTCAST(KL), INTCAST(KU), DOUBLECAST(alpha), DOUBLECAST(A), 
                    INTCAST(lda), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(beta), DOUBLECAST(Y), INTCAST(incY));
}


void __dtrmv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* A, const int* lda, double* X, const int* incX) {
    EigenFunc_dtrmv(Uplo, TransA, Diag, INTCAST(N), DOUBLECAST(A), INTCAST(lda), DOUBLECAST(X), INTCAST(incX));
}


void __dtpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* Ap, double* X, const int* incX) {
    EigenFunc_dtpmv(Uplo, TransA, Diag, INTCAST(N), DOUBLECAST(Ap), DOUBLECAST(X), INTCAST(incX));
}


void __dtrsv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* A, const int* lda, double* X, const int* incX) {
    EigenFunc_dtrsv(Uplo, TransA, Diag, INTCAST(N), DOUBLECAST(A), INTCAST(lda), DOUBLECAST(X), INTCAST(incX));
}


void __dtbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const double* A, const int* lda, double* X, 
               const int* incX) {
    EigenFunc_dtbsv(Uplo, TransA, Diag, INTCAST(N), INTCAST(K), DOUBLECAST(A), INTCAST(lda), DOUBLECAST(X), INTCAST(incX));
}


void __dtpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* Ap, double* X, const int* incX) {
    EigenFunc_dtpsv(Uplo, TransA, Diag, INTCAST(N), DOUBLECAST(Ap), DOUBLECAST(X), INTCAST(incX));
}


void __dsymv__(char* Uplo, const int* N, const double* alpha, const double* A, const int* lda, const double* X, const int* incX, 
               const double* beta, double* Y, const int* incY) {
    EigenFunc_dsymv(Uplo, INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(A), INTCAST(lda), DOUBLECAST(X), INTCAST(incX), 
                    DOUBLECAST(beta), DOUBLECAST(Y), INTCAST(incY));
}


void __dger__(const int* M, const int* N, const double* alpha, const double* X, const int* incX, const double* Y, const int* incY, 
              double* A, const int* lda) {
    EigenFunc_dger(INTCAST(M), INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY), 
                   DOUBLECAST(A), INTCAST(lda));
}


void __dsyr__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, double* A, const int* lda) {
    EigenFunc_dsyr(Uplo, INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(A), INTCAST(lda));
}


void __dspr__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, double* Ap) {
    EigenFunc_dspr(Uplo, INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Ap));
}


void __dsyr2__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, const double* Y, const int* incY,
               double* A, const int* lda) {
    EigenFunc_dsyr2(Uplo, INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY), DOUBLECAST(A),
                    INTCAST(lda));
}


void __dspr2__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, const double* Y, const int* incY, 
               double* A) {
    EigenFunc_dspr2(Uplo, INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(X), INTCAST(incX), DOUBLECAST(Y), INTCAST(incY), DOUBLECAST(A));
}


void __dgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const double* alpha, const double* A, 
               const int* lda, const double* B, const int* ldb, const double* beta, double* C, const int* ldc) {
    EigenFunc_dgemm(TransA, TransB, INTCAST(M), INTCAST(N), INTCAST(K), DOUBLECAST(alpha), DOUBLECAST(A), 
                    INTCAST(lda), DOUBLECAST(B), INTCAST(ldb), DOUBLECAST(beta), DOUBLECAST(C), INTCAST(ldc));
}


void __dsymm__(char* Side, char* Uplo, const int* M, const int* N, const double* alpha, const double* A, const int* lda, 
               const double* B, const int* ldb, const double* beta, double* C, const int* ldc) {
    EigenFunc_dsymm(Side, Uplo, INTCAST(M), INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(A), INTCAST(lda), 
                    DOUBLECAST(B), INTCAST(ldb), DOUBLECAST(beta), DOUBLECAST(C), INTCAST(ldc));
}


void __dsyrk__(char* Uplo, char* Trans, const int* N, const int* K, const double* alpha, const double* A, const int* lda, 
               const double* beta, double* C, const int* ldc) {
    EigenFunc_dsyrk(Uplo, Trans, INTCAST(N), INTCAST(K), DOUBLECAST(alpha), DOUBLECAST(A), INTCAST(lda), 
                    DOUBLECAST(beta), DOUBLECAST(C), INTCAST(ldc));
}


void __dsyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const double* alpha, const double* A, const int* lda, 
                const double* B, const int* ldb, const double* beta, double* C, const int* ldc) {
    EigenFunc_dsyr2k(Uplo, Trans, INTCAST(N), INTCAST(K), DOUBLECAST(alpha), DOUBLECAST(A), INTCAST(lda), 
                     DOUBLECAST(B), INTCAST(ldb), DOUBLECAST(beta), DOUBLECAST(C), INTCAST(ldc));
}


void __dtrmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const double* alpha, const double* A,
               const int* lda, double* B, const int* ldb) {
    EigenFunc_dtrmm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(A), INTCAST(lda), DOUBLECAST(B),
                    INTCAST(ldb));
}


void __dtrsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const double* alpha, const double* A, 
               const int* lda, double* B, const int* ldb) {
    EigenFunc_dtrsm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), DOUBLECAST(alpha), DOUBLECAST(A), INTCAST(lda), DOUBLECAST(B),
                    INTCAST(ldb));
}


#ifdef __cplusplus
}
#endif