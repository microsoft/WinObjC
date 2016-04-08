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

#define SCALAR float
#define SCALAR_SUFFIX s
#define SCALAR_SUFFIX_UP "S"
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


void catlas_sset(const int N, const float alpha, float* X, const int incX) {
    if (incX >= 1 && X != nullptr) {
        for (int i = 0; i < N; i += incX) {
            X[i] = alpha;
        }
    }
}


void __sdot_sub__(const int* N, float* X, const int* incX, float* Y, const int* incY, float* dot) {
    *dot = EigenFunc_sdot(INTCAST(N), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY));
}


void __isamax_sub__(const int* N, float* X, const int* incX, int* iamax) {
    *iamax = EigenFunc_isamax(INTCAST(N), FLOATCAST(X), INTCAST(incX));
}


void __sasum_sub__(const int* N, float* X, const int* incX, float* asum) {
    *asum = EigenFunc_sasum(INTCAST(N), FLOATCAST(X), INTCAST(incX));
}


void __snrm2_sub__(const int* N, float* X, const int* incX, float* nrm2) {
    *nrm2 = EigenFunc_snrm2(INTCAST(N), FLOATCAST(X), INTCAST(incX));
}


void __sswap__(const int* N, float* X, const int* incX, float* Y, const int* incY) {
    EigenFunc_sswap(INTCAST(N), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY));
}


void __scopy__(const int* N, const float* X, const int* incX, float* Y, const int* incY) {
    EigenFunc_scopy(INTCAST(N), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY));
}


void __saxpy__(const int* N, const float* alpha, const float* X, const int* incX, float* Y, const int* incY) {
    EigenFunc_saxpy(INTCAST(N), FLOATCAST(alpha), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY));
}


void __srotg__(float* a, float* b, float* c, float* s) {
    EigenFunc_srotg(FLOATCAST(a), FLOATCAST(b), FLOATCAST(c), FLOATCAST(s));
}


void __srot__(const int* N, float* X, const int* incX, float* Y, const int* incY, const float* c, const float* s) {
    EigenFunc_srot(INTCAST(N), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY), FLOATCAST(c), FLOATCAST(s));
}


void __sscal__(const int* N, const float* alpha, float* X, const int* incX) {
    EigenFunc_sscal(INTCAST(N), FLOATCAST(alpha), FLOATCAST(X), INTCAST(incX));
}


void __sgemv__(char* TransA, const int* M, const int* N, const float* alpha, const float* A, const int* lda, const float* X, 
               const int* incX, const float* beta, float* Y, const int* incY) {
    EigenFunc_sgemv(TransA, INTCAST(M), INTCAST(N), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), FLOATCAST(X), 
                    INTCAST(incX), FLOATCAST(beta), FLOATCAST(Y), INTCAST(incY));
}


void __sgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const float* alpha, const float* A, 
               const int* lda, const float* X, const int* incX, const float* beta, float* Y, const int* incY) {
    EigenFunc_sgbmv(TransA, INTCAST(M), INTCAST(N), INTCAST(KL), INTCAST(KU), FLOATCAST(alpha), FLOATCAST(A), 
                    INTCAST(lda), FLOATCAST(X), INTCAST(incX), FLOATCAST(beta), FLOATCAST(Y), INTCAST(incY));
}


void __strmv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* A, const int* lda, float* X, const int* incX) {
    EigenFunc_strmv(Uplo, TransA, Diag, INTCAST(N), FLOATCAST(A), INTCAST(lda), FLOATCAST(X), INTCAST(incX));
}


void __stpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* Ap, float* X, const int* incX) {
    EigenFunc_stpmv(Uplo, TransA, Diag, INTCAST(N), FLOATCAST(Ap), FLOATCAST(X), INTCAST(incX));
}


void __strsv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* A, const int* lda, float* X, const int* incX) {
    EigenFunc_strsv(Uplo, TransA, Diag, INTCAST(N), FLOATCAST(A), INTCAST(lda), FLOATCAST(X), INTCAST(incX));
}


void __stbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const float* A, const int* lda, float* X, 
               const int* incX) {
    EigenFunc_stbsv(Uplo, TransA, Diag, INTCAST(N), INTCAST(K), FLOATCAST(A), INTCAST(lda), FLOATCAST(X), INTCAST(incX));
}


void __stpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* Ap, float* X, const int* incX) {
    EigenFunc_stpsv(Uplo, TransA, Diag, INTCAST(N), FLOATCAST(Ap), FLOATCAST(X), INTCAST(incX));
}


void __ssymv__(char* Uplo, const int* N, const float* alpha, const float* A, const int* lda, const float* X, const int* incX, 
               const float* beta, float* Y, const int* incY) {
    EigenFunc_ssymv(Uplo, INTCAST(N), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), FLOATCAST(X), INTCAST(incX), 
                    FLOATCAST(beta), FLOATCAST(Y), INTCAST(incY));
}


void __sger__(const int* M, const int* N, const float* alpha, const float* X, const int* incX, const float* Y, const int* incY, 
              float* A, const int* lda) {
    EigenFunc_sger(INTCAST(M), INTCAST(N), FLOATCAST(alpha), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY),
                   FLOATCAST(A), INTCAST(lda));
}


void __ssyr__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, float* A, const int* lda) {
    EigenFunc_ssyr(Uplo, INTCAST(N), FLOATCAST(alpha), FLOATCAST(X), INTCAST(incX), FLOATCAST(A), INTCAST(lda));
}


void __sspr__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, float* Ap) {
    EigenFunc_sspr(Uplo, INTCAST(N), FLOATCAST(alpha), FLOATCAST(X), INTCAST(incX), FLOATCAST(Ap));
}


void __ssyr2__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, const float* Y, const int* incY, 
               float* A, const int* lda) {
    EigenFunc_ssyr2(Uplo, INTCAST(N), FLOATCAST(alpha), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY), FLOATCAST(A), 
                    INTCAST(lda));
}


void __sspr2__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, const float* Y, const int* incY, 
               float* A) {
    EigenFunc_sspr2(Uplo, INTCAST(N), FLOATCAST(alpha), FLOATCAST(X), INTCAST(incX), FLOATCAST(Y), INTCAST(incY), FLOATCAST(A));
}


void __sgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const float* alpha, const float* A, const int* lda,
               const float* B, const int* ldb, const float* beta, float* C, const int* ldc) {
    EigenFunc_sgemm(TransA, TransB, INTCAST(M), INTCAST(N), INTCAST(K), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), FLOATCAST(B),
                    INTCAST(ldb), FLOATCAST(beta), FLOATCAST(C), INTCAST(ldc));
}


void __ssymm__(char* Side, char* Uplo, const int* M, const int* N, const float* alpha, const float* A, const int* lda, const float* B,
               const int* ldb, const float* beta, float* C, const int* ldc) {
    EigenFunc_ssymm(Side, Uplo, INTCAST(M), INTCAST(N), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), FLOATCAST(B), INTCAST(ldb), 
                    FLOATCAST(beta), FLOATCAST(C), INTCAST(ldc));
}


void __ssyrk__(char* Uplo, char* Trans, const int* N, const int* K, const float* alpha, const float* A, const int* lda, 
               const float* beta, float* C, const int* ldc) {
    EigenFunc_ssyrk(Uplo, Trans, INTCAST(N), INTCAST(K), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), FLOATCAST(beta), 
                    FLOATCAST(C), INTCAST(ldc));
}


void __ssyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const float* alpha, const float* A, const int* lda, const float* B,
                const int* ldb, const float* beta, float* C, const int* ldc) {
    EigenFunc_ssyr2k(Uplo, Trans, INTCAST(N), INTCAST(K), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), FLOATCAST(B), INTCAST(ldb),
                     FLOATCAST(beta), FLOATCAST(C), INTCAST(ldc));
}


void __strmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const float* alpha, const float* A, 
               const int* lda, float* B, const int* ldb) {
    EigenFunc_strmm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), 
                    FLOATCAST(B), INTCAST(ldb));
}


void __strsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const float* alpha, const float* A, 
               const int* lda, float* B, const int* ldb) {
    EigenFunc_strsm(Side, Uplo, TransA, Diag, INTCAST(M), INTCAST(N), FLOATCAST(alpha), FLOATCAST(A), INTCAST(lda), FLOATCAST(B),
                    INTCAST(ldb));
}


#ifdef __cplusplus
}
#endif