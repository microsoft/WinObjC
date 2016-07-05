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

// Compile-time check to ensure EIGEN_MPL2_ONLY is always set
// when we build any of the Accelerate BLAS APIs using deps\3rdparty\Eigen

#ifndef EIGEN_MPL2_ONLY
#error Including non-MPL2 code in EIGEN_MPL2_ONLY mode
#endif

#define F77_snrm2_sub  __snrm2_sub__
#define F77_sasum_sub  __sasum_sub__
#define F77_isamax_sub  __isamax_sub__
#define F77_dnrm2_sub  __dnrm2_sub__
#define F77_dasum_sub  __dasum_sub__
#define F77_idamax_sub  __idamax_sub__
#define F77_scnrm2_sub  __scnrm2_sub__
#define F77_scasum_sub  __scasum_sub__
#define F77_icamax_sub  __icamax_sub__
#define F77_dznrm2_sub  __dznrm2_sub__
#define F77_dzasum_sub  __dzasum_sub__
#define F77_izamax_sub  __izamax_sub__
#define F77_sdot_sub  __sdot_sub__
#define F77_ddot_sub  __ddot_sub__
#define F77_cdotu_sub  __cdotu_sub__
#define F77_cdotc_sub  __cdotc_sub__
#define F77_zdotu_sub  __zdotu_sub__
#define F77_zdotc_sub  __zdotc_sub__
#define F77_sswap  __sswap__
#define F77_scopy  __scopy__
#define F77_saxpy  __saxpy__
#define F77_dswap  __dswap__
#define F77_dcopy  __dcopy__
#define F77_daxpy  __daxpy__
#define F77_cswap  __cswap__
#define F77_ccopy  __ccopy__
#define F77_caxpy  __caxpy__
#define F77_zswap  __zswap__
#define F77_zcopy  __zcopy__
#define F77_zaxpy  __zaxpy__
#define F77_srotg  __srotg__
#define F77_srotmg  __srotmg__
#define F77_srot  __srot__
#define F77_srotm  __srotm__
#define F77_drotg  __drotg__
#define F77_drotmg  __drotmg__
#define F77_drot  __drot__
#define F77_drotm  __drotm__
#define F77_sscal  __sscal__
#define F77_dscal  __dscal__
#define F77_cscal  __cscal__
#define F77_zscal  __zscal__
#define F77_csscal  __csscal__
#define F77_zdscal  __zdscal__
#define F77_sgemv  __sgemv__
#define F77_sgbmv  __sgbmv__
#define F77_strmv  __strmv__
#define F77_stbmv  __stbmv__
#define F77_stpmv  __stpmv__
#define F77_strsv  __strsv__
#define F77_stbsv  __stbsv__
#define F77_stpsv  __stpsv__
#define F77_dgemv  __dgemv__
#define F77_dgbmv  __dgbmv__
#define F77_dtrmv  __dtrmv__
#define F77_dtbmv  __dtbmv__
#define F77_dtpmv  __dtpmv__
#define F77_dtrsv  __dtrsv__
#define F77_dtbsv  __dtbsv__
#define F77_dtpsv  __dtpsv__
#define F77_cgemv  __cgemv__
#define F77_cgbmv  __cgbmv__
#define F77_ctrmv  __ctrmv__
#define F77_ctbmv  __ctbmv__
#define F77_ctpmv  __ctpmv__
#define F77_ctrsv  __ctrsv__
#define F77_ctbsv  __ctbsv__
#define F77_ctpsv  __ctpsv__
#define F77_zgemv  __zgemv__
#define F77_zgbmv  __zgbmv__
#define F77_ztrmv  __ztrmv__
#define F77_ztbmv  __ztbmv__
#define F77_ztpmv  __ztpmv__
#define F77_ztrsv  __ztrsv__
#define F77_ztbsv  __ztbsv__
#define F77_ztpsv  __ztpsv__
#define F77_ssymv  __ssymv__
#define F77_ssbmv  __ssbmv__
#define F77_sspmv  __sspmv__
#define F77_sger  __sger__
#define F77_ssyr  __ssyr__
#define F77_sspr  __sspr__
#define F77_ssyr2  __ssyr2__
#define F77_sspr2  __sspr2__
#define F77_dsymv  __dsymv__
#define F77_dsbmv  __dsbmv__
#define F77_dspmv  __dspmv__
#define F77_dger  __dger__
#define F77_dsyr  __dsyr__
#define F77_dspr  __dspr__
#define F77_dsyr2  __dsyr2__
#define F77_dspr2  __dspr2__
#define F77_chemv  __chemv__
#define F77_chbmv  __chbmv__
#define F77_chpmv  __chpmv__
#define F77_cgeru  __cgeru__
#define F77_cgerc  __cgerc__
#define F77_cher  __cher__
#define F77_chpr  __chpr__
#define F77_cher2  __cher2__
#define F77_chpr2  __chpr2__
#define F77_zhemv  __zhemv__
#define F77_zhbmv  __zhbmv__
#define F77_zhpmv  __zhpmv__
#define F77_zgeru  __zgeru__
#define F77_zgerc  __zgerc__
#define F77_zher  __zher__
#define F77_zhpr  __zhpr__
#define F77_zher2  __zher2__
#define F77_zhpr2  __zhpr2__
#define F77_sgemm  __sgemm__
#define F77_ssymm  __ssymm__
#define F77_ssyrk  __ssyrk__
#define F77_ssyr2k  __ssyr2k__
#define F77_strmm  __strmm__
#define F77_strsm  __strsm__
#define F77_dgemm  __dgemm__
#define F77_dsymm  __dsymm__
#define F77_dsyrk  __dsyrk__
#define F77_dsyr2k  __dsyr2k__
#define F77_dtrmm  __dtrmm__
#define F77_dtrsm  __dtrsm__
#define F77_cgemm  __cgemm__
#define F77_csymm  __csymm__
#define F77_csyrk  __csyrk__
#define F77_csyr2k  __csyr2k__
#define F77_ctrmm  __ctrmm__
#define F77_ctrsm  __ctrsm__
#define F77_zgemm  __zgemm__
#define F77_zsymm  __zsymm__
#define F77_zsyrk  __zsyrk__
#define F77_zsyr2k  __zsyr2k__
#define F77_ztrmm  __ztrmm__
#define F77_ztrsm  __ztrsm__
#define F77_chemm  __chemm__
#define F77_cherk  __cherk__
#define F77_cher2k  __cher2k__
#define F77_zhemm  __zhemm__
#define F77_zherk  __zherk__
#define F77_zher2k  __zher2k__
#define F77_xerbla  xerbla_

#ifdef __cplusplus
extern "C" {
#endif

void __sdot_sub__(const int* N, const float* X, const int* incX, const float* Y, const int* incY, float* dot);

void __isamax_sub__(const int* N, const float* X, const int* incX, int* iamax);

void __sasum_sub__(const int* N, const float* X, const int* incX, float* asum);

void __snrm2_sub__(const int* N, const float* X, const int* incX, float* nrm2);

void __ddot_sub__(const int* N, const double* X, const int* incX, const double* Y, const int* incY, double* dot);

void __idamax_sub__(const int* N, const double* X, const int* incX, int* iamax);

void __dasum_sub__(const int* N, const double* X, const int* incX, double* asum);

void __dnrm2_sub__(const int* N, const double* X, const int* incX, double* nrm2);

void __icamax_sub__(const int* N, const void* X, const int* incX, int* iamax);

void __scasum_sub__(const int* N, const void* X, const int* incX, float* asum);

void __scnrm2_sub__(const int* N, const void* X, const int* incX, float* nrm2);

void __izamax_sub__(const int* N, const void* X, const int* incX, int* iamax);

void __dzasum_sub__(const int* N, const void* X, const int* incX, double* asum);

void __dznrm2_sub__(const int* N, const void* X, const int* incX, double* nrm2);

void __cdotu_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotu);

void __cdotc_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotc);

void __zdotu_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotu);

void __zdotc_sub__(const int* N, const void* X, const int* incX, const void* Y, const int* incY, void* dotc);

void __sswap__(const int* N, float* X, const int* incX, float* Y, const int* incY);

void __scopy__(const int* N, const float* X, const int* incX, float* Y, const int* incY);

void __saxpy__(const int* N, const float* alpha, const float* X, const int* incX, float* Y, const int* incY);

void __dswap__(const int* N, double* X, const int* incX, double* Y, const int* incY);

void __dcopy__(const int* N, const double* X, const int* incX, double* Y, const int* incY);

void __daxpy__(const int* N, const double* alpha, const double* X, const int* incX, double* Y, const int* incY);

void __cswap__(const int* N, void* X, const int* incX, void* Y, const int* incY);

void __ccopy__(const int* N, const void* X, const int* incX, void* Y, const int* incY);

void __caxpy__(const int* N, const void* alpha, const void* X, const int* incX, void* Y, const int* incY);

void __zswap__(const int* N, void* X, const int* incX, void* Y, const int* incY);

void __zcopy__(const int* N, const void* X, const int* incX, void* Y, const int* incY);

void __zaxpy__(const int* N, const void* alpha, const void* X, const int* incX, void* Y, const int* incY);

void __srotg__(float* a, float* b, float* c, float* s);

void __srotmg__(float* d1, float* d2, float* b1, const float* b2, float* P);

void __srot__(const int* N, float* X, const int* incX, float* Y, const int* incY, const float* c, const float* s);

void __srotm__(const int* N, float* X, const int* incX, float* Y, const int* incY, const float* P);

void __drotg__(double* a, double* b, double* c, double* s);

void __drotmg__(double* d1, double* d2, double* b1, const double* b2, double* P);

void __drot__(const int* N, double* X, const int* incX, double* Y, const int* incY, const double* c, const double* s);

void __drotm__(const int* N, double* X, const int* incX, double* Y, const int* incY, const double* P);

void __sscal__(const int* N, const float* alpha, float* X, const int* incX);

void __dscal__(const int* N, const double* alpha, double* X, const int* incX);

void __cscal__(const int* N, const void* alpha, void* X, const int* incX);

void __zscal__(const int* N, const void* alpha, void* X, const int* incX);

void __csscal__(const int* N, const float* alpha, void* X, const int* incX);

void __zdscal__(const int* N, const double* alpha, void* X, const int* incX);

void __sgemv__(char* TransA, const int* M, const int* N, const float* alpha, const float* A, const int* lda, const float* X, const int* incX,
               const float* beta, float* Y, const int* incY);

void __sgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const float* alpha, const float* A, const int* lda,
               const float* X, const int* incX, const float* beta, float* Y, const int* incY);

void __strmv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* A, const int* lda, float* X, const int* incX);

void __stbmv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const float* A, const int* lda, float* X, const int* incX);

void __stpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* Ap, float* X, const int* incX);

void __strsv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* A, const int* lda, float* X, const int* incX);

void __stbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const float* A, const int* lda, float* X, const int* incX);

void __stpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const float* Ap, float* X, const int* incX);

void __dgemv__(char* TransA, const int* M, const int* N, const double* alpha, const double* A, const int* lda, const double* X, const int* incX,
               const double* beta, double* Y, const int* incY);

void __dgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const double* alpha, const double* A, const int* lda,
               const double* X, const int* incX, const double* beta, double* Y, const int* incY);

void __dtrmv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* A, const int* lda, double* X, const int* incX);

void __dtbmv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const double* A, const int* lda, double* X, const int* incX);

void __dtpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* Ap, double* X, const int* incX);

void __dtrsv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* A, const int* lda, double* X, const int* incX);

void __dtbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const double* A, const int* lda, double* X, const int* incX);

void __dtpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const double* Ap, double* X, const int* incX);

void __cgemv__(char* TransA, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* X, const int* incX,
               const void* beta, void* Y, const int* incY);

void __cgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const void* alpha, const void* A, const int* lda,
               const void* X, const int* incX, const void* beta, void* Y, const int* incY);

void __ctrmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX);

void __ctbmv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const void* A, const int* lda, void* X, const int* incX);

void __ctpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX);

void __ctrsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX);

void __ctbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const void* A, const int* lda, void* X, const int* incX);

void __ctpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX);

void __zgemv__(char* TransA, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* X, const int* incX,
               const void* beta, void* Y, const int* incY);

void __zgbmv__(char* TransA, const int* M, const int* N, const int* KL, const int* KU, const void* alpha, const void* A, const int* lda,
               const void* X, const int* incX, const void* beta, void* Y, const int* incY);

void __ztrmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX);

void __ztbmv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const void* A, const int* lda, void* X, const int* incX);

void __ztpmv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX);

void __ztrsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* A, const int* lda, void* X, const int* incX);

void __ztbsv__(char* Uplo, char* TransA, char* Diag, const int* N, const int* K, const void* A, const int* lda, void* X, const int* incX);

void __ztpsv__(char* Uplo, char* TransA, char* Diag, const int* N, const void* Ap, void* X, const int* incX);

void __ssymv__(char* Uplo, const int* N, const float* alpha, const float* A, const int* lda, const float* X, const int* incX, const float* beta,
               float* Y, const int* incY);

void __ssbmv__(char* Uplo, const int* N, const int* K, const float* alpha, const float* A, const int* lda, const float* X, const int* incX,
               const float* beta, float* Y, const int* incY);

void __sspmv__(char* Uplo, const int* N, const float* alpha, const float* Ap, const float* X, const int* incX, const float* beta, float* Y,
               const int* incY);

void __sger__(const int* M, const int* N, const float* alpha, const float* X, const int* incX, const float* Y, const int* incY, float* A,
              const int* lda);

void __ssyr__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, float* A, const int* lda);

void __sspr__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, float* Ap);

void __ssyr2__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, const float* Y, const int* incY, float* A,
               const int* lda);

void __sspr2__(char* Uplo, const int* N, const float* alpha, const float* X, const int* incX, const float* Y, const int* incY, float* A);

void __dsymv__(char* Uplo, const int* N, const double* alpha, const double* A, const int* lda, const double* X, const int* incX, const double* beta,
               double* Y, const int* incY);

void __dsbmv__(char* Uplo, const int* N, const int* K, const double* alpha, const double* A, const int* lda, const double* X, const int* incX,
               const double* beta, double* Y, const int* incY);

void __dspmv__(char* Uplo, const int* N, const double* alpha, const double* Ap, const double* X, const int* incX, const double* beta,
               double* Y, const int* incY);

void __dger__(const int* M, const int* N, const double* alpha, const double* X, const int* incX, const double* Y, const int* incY, double* A,
               const int* lda);

void __dsyr__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, double* A, const int* lda);

void __dspr__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, double* Ap);

void __dsyr2__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, const double* Y, const int* incY, double* A,
               const int* lda);

void __dspr2__(char* Uplo, const int* N, const double* alpha, const double* X, const int* incX, const double* Y, const int* incY, double* A);

void __chemv__(char* Uplo, const int* N, const void* alpha, const void* A, const int* lda, const void* X, const int* incX, const void* beta,
               void* Y, const int* incY);

void __chbmv__(char* Uplo, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* X, const int* incX,
               const void* beta, void* Y, const int* incY);

void __chpmv__(char* Uplo, const int* N, const void* alpha, const void* Ap, const void* X, const int* incX, const void* beta, void* Y,
               const int* incY);

void __cgeru__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda);

void __cgerc__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda);

void __cher__(char* Uplo, const int* N, const float* alpha, const void* X, const int* incX, void* A, const int* lda);

void __chpr__(char* Uplo, const int* N, const float* alpha, const void* X, const int* incX, void* A);

void __cher2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda);

void __chpr2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* Ap);

void __zhemv__(char* Uplo, const int* N, const void* alpha, const void* A, const int* lda, const void* X, const int* incX, const void* beta,
               void* Y, const int* incY);

void __zhbmv__(char* Uplo, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* X, const int* incX,
               const void* beta, void* Y, const int* incY);

void __zhpmv__(char* Uplo, const int* N, const void* alpha, const void* Ap, const void* X, const int* incX, const void* beta, void* Y,
               const int* incY);

void __zgeru__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda);

void __zgerc__(const int* M, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda);

void __zher__(char* Uplo, const int* N, const double* alpha, const void* X, const int* incX, void* A, const int* lda);

void __zhpr__(char* Uplo, const int* N, const double* alpha, const void* X, const int* incX, void* A);

void __zher2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* A,
               const int* lda);

void __zhpr2__(char* Uplo, const int* N, const void* alpha, const void* X, const int* incX, const void* Y, const int* incY, void* Ap);

void __sgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const float* alpha, const float* A, const int* lda,
               const float* B, const int* ldb, const float* beta, float* C, const int* ldc);

void __ssymm__(char* Side, char* Uplo, const int* M, const int* N, const float* alpha, const float* A, const int* lda, const float* B,
               const int* ldb, const float* beta, float* C, const int* ldc);

void __ssyrk__(char* Uplo, char* Trans, const int* N, const int* K, const float* alpha, const float* A, const int* lda, const float* beta,
               float* C, const int* ldc);

void __ssyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const float* alpha, const float* A, const int* lda, const float* B,
                const int* ldb, const float* beta, float* C, const int* ldc);

void __strmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const float* alpha, const float* A, const int* lda,
               float* B, const int* ldb);

void __strsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const float* alpha, const float* A, const int* lda,
               float* B, const int* ldb);

void __dgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const double* alpha, const double* A, const int* lda,
               const double* B, const int* ldb, const double* beta, double* C, const int* ldc);

void __dsymm__(char* Side, char* Uplo, const int* M, const int* N, const double* alpha, const double* A, const int* lda, const double* B,
               const int* ldb, const double* beta, double* C, const int* ldc);

void __dsyrk__(char* Uplo, char* Trans, const int* N, const int* K, const double* alpha, const double* A, const int* lda, const double* beta,
               double* C, const int* ldc);

void __dsyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const double* alpha, const double* A, const int* lda, const double* B,
                const int* ldb, const double* beta, double* C, const int* ldc);

void __dtrmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const double* alpha, const double* A, const int* lda,
               double* B, const int* ldb);

void __dtrsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const double* alpha, const double* A, const int* lda,
               double* B, const int* ldb);

void __cgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const void* alpha, const void* A, const int* lda,
               const void* B, const int* ldb, const void* beta, void* C, const int* ldc);

void __csymm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
               const int* ldb, const void* beta, void* C, const int* ldc);

void __csyrk__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* beta,
               void* C, const int* ldc);

void __csyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const void* beta, void* C, const int* ldc);

void __ctrmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, const int* lda,
               void* B, const int* ldb);

void __ctrsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, const int* lda,
               void* B, const int* ldb);

void __zgemm__(char* TransA, char* TransB, const int* M, const int* N, const int* K, const void* alpha, const void* A, const int* lda,
               const void* B, const int* ldb, const void* beta, void* C, const int* ldc);

void __zsymm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
               const int* ldb, const void* beta, void* C, const int* ldc);

void __zsyrk__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* beta,
               void* C, const int* ldc);

void __zsyr2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const void* beta, void* C, const int* ldc);

void __ztrmm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, const int* lda,
               void* B, const int* ldb);

void __ztrsm__(char* Side, char* Uplo, char* TransA, char* Diag, const int* M, const int* N, const void* alpha, const void* A, const int* lda,
               void* B, const int* ldb);

void __chemm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
               const int* ldb, const void* beta, void* C, const int* ldc);

void __cherk__(char* Uplo, char* Trans, const int* N, const int* K, const float* alpha, const void* A, const int* lda, const float* beta,
               void* C, const int* ldc);

void __cher2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const float* beta, void* C, const int* ldc);

void __zhemm__(char* Side, char* Uplo, const int* M, const int* N, const void* alpha, const void* A, const int* lda, const void* B,
               const int* ldb, const void* beta, void* C, const int* ldc);

void __zherk__(char* Uplo, char* Trans, const int* N, const int* K, const double* alpha, const void* A, const int* lda, const double* beta,
               void* C, const int* ldc);

void __zher2k__(char* Uplo, char* Trans, const int* N, const int* K, const void* alpha, const void* A, const int* lda, const void* B,
                const int* ldb, const double* beta, void* C, const int* ldc);


#ifdef __cplusplus
}
#endif

