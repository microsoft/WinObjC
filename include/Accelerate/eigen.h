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

#ifndef _EIGEN_H_
#define _EIGEN_H_

#define INTCAST(A)        const_cast<int *>(A)
#define FLOATCAST(A)    const_cast<float *>(A)
#define RFLOATCAST(A)    reinterpret_cast<float *>(A)
#define VFLOATCAST(A)    reinterpret_cast<float *>(const_cast<void *>(A))
#define DOUBLECAST(A)    const_cast<double *>(A)
#define RDOUBLECAST(A)    reinterpret_cast<double *>(A)
#define VDOUBLECAST(A)    reinterpret_cast<double *>(const_cast<void *>(A))

#define EigenFunc_snrm2  snrm2_
#define EigenFunc_sasum  sasum_
#define EigenFunc_isamax  isamax_
#define EigenFunc_dnrm2  dnrm2_
#define EigenFunc_dasum  dasum_
#define EigenFunc_idamax  idamax_
#define EigenFunc_scnrm2  scnrm2_
#define EigenFunc_scasum  scasum_
#define EigenFunc_icamax  icamax_
#define EigenFunc_dznrm2  dznrm2_
#define EigenFunc_dzasum  dzasum_
#define EigenFunc_izamax  izamax_
#define EigenFunc_sdot  sdot_
#define EigenFunc_ddot  ddot_
#define EigenFunc_cdotu_sub  cdotuw_
#define EigenFunc_cdotc_sub  cdotcw_
#define EigenFunc_zdotu_sub  zdotuw_
#define EigenFunc_zdotc_sub  zdotcw_
#define EigenFunc_csrot  csrot_
#define EigenFunc_crotg  crotg_ 
#define EigenFunc_zdrot  zdrot_
#define EigenFunc_zrotg  zrotg_ 
#define EigenFunc_sswap  sswap_
#define EigenFunc_scopy  scopy_
#define EigenFunc_saxpy  saxpy_
#define EigenFunc_dswap  dswap_
#define EigenFunc_dcopy  dcopy_
#define EigenFunc_daxpy  daxpy_
#define EigenFunc_cswap  cswap_
#define EigenFunc_ccopy  ccopy_
#define EigenFunc_caxpy  caxpy_
#define EigenFunc_zswap  zswap_
#define EigenFunc_zcopy  zcopy_
#define EigenFunc_zaxpy  zaxpy_
#define EigenFunc_srotg  srotg_
#define EigenFunc_srotmg  srotmg_
#define EigenFunc_srot  srot_
#define EigenFunc_srotm  srotm_
#define EigenFunc_drotg  drotg_
#define EigenFunc_drotmg  drotmg_
#define EigenFunc_drot  drot_
#define EigenFunc_drotm  drotm_
#define EigenFunc_sscal  sscal_
#define EigenFunc_dscal  dscal_
#define EigenFunc_cscal  cscal_
#define EigenFunc_zscal  zscal_
#define EigenFunc_csscal  csscal_
#define EigenFunc_zdscal  zdscal_
#define EigenFunc_sgemv  sgemv_
#define EigenFunc_sgbmv  sgbmv_
#define EigenFunc_strmv  strmv_
#define EigenFunc_stbmv  stbmv_
#define EigenFunc_stpmv  stpmv_
#define EigenFunc_strsv  strsv_
#define EigenFunc_stbsv  stbsv_
#define EigenFunc_stpsv  stpsv_
#define EigenFunc_dgemv  dgemv_
#define EigenFunc_dgbmv  dgbmv_
#define EigenFunc_dtrmv  dtrmv_
#define EigenFunc_dtbmv  dtbmv_
#define EigenFunc_dtpmv  dtpmv_
#define EigenFunc_dtrsv  dtrsv_
#define EigenFunc_dtbsv  dtbsv_
#define EigenFunc_dtpsv  dtpsv_
#define EigenFunc_cgemv  cgemv_
#define EigenFunc_cgbmv  cgbmv_
#define EigenFunc_ctrmv  ctrmv_
#define EigenFunc_ctbmv  ctbmv_
#define EigenFunc_ctpmv  ctpmv_
#define EigenFunc_ctrsv  ctrsv_
#define EigenFunc_ctbsv  ctbsv_
#define EigenFunc_ctpsv  ctpsv_
#define EigenFunc_zgemv  zgemv_
#define EigenFunc_zgbmv  zgbmv_
#define EigenFunc_ztrmv  ztrmv_
#define EigenFunc_ztbmv  ztbmv_
#define EigenFunc_ztpmv  ztpmv_
#define EigenFunc_ztrsv  ztrsv_
#define EigenFunc_ztbsv  ztbsv_
#define EigenFunc_ztpsv  ztpsv_
#define EigenFunc_ssymv  ssymv_
#define EigenFunc_ssbmv  ssbmv_
#define EigenFunc_sspmv  sspmv_
#define EigenFunc_sger  sger_
#define EigenFunc_ssyr  ssyr_
#define EigenFunc_sspr  sspr_
#define EigenFunc_ssyr2  ssyr2_
#define EigenFunc_sspr2  sspr2_
#define EigenFunc_dsymv  dsymv_
#define EigenFunc_dsbmv  dsbmv_
#define EigenFunc_dspmv  dspmv_
#define EigenFunc_dger  dger_
#define EigenFunc_dsyr  dsyr_
#define EigenFunc_dspr  dspr_
#define EigenFunc_dsyr2  dsyr2_
#define EigenFunc_dspr2  dspr2_
#define EigenFunc_chemv  chemv_
#define EigenFunc_chbmv  chbmv_
#define EigenFunc_chpmv  chpmv_
#define EigenFunc_cgeru  cgeru_
#define EigenFunc_cgerc  cgerc_
#define EigenFunc_cher  cher_
#define EigenFunc_chpr  chpr_
#define EigenFunc_cher2  cher2_
#define EigenFunc_chpr2  chpr2_
#define EigenFunc_zhemv  zhemv_
#define EigenFunc_zhbmv  zhbmv_
#define EigenFunc_zhpmv  zhpmv_
#define EigenFunc_zgeru  zgeru_
#define EigenFunc_zgerc  zgerc_
#define EigenFunc_zher  zher_
#define EigenFunc_zhpr  zhpr_
#define EigenFunc_zher2  zher2_
#define EigenFunc_zhpr2  zhpr2_
#define EigenFunc_sgemm  sgemm_
#define EigenFunc_ssymm  ssymm_
#define EigenFunc_ssyrk  ssyrk_
#define EigenFunc_ssyr2k  ssyr2k_
#define EigenFunc_strmm  strmm_
#define EigenFunc_strsm  strsm_
#define EigenFunc_dgemm  dgemm_
#define EigenFunc_dsymm  dsymm_
#define EigenFunc_dsyrk  dsyrk_
#define EigenFunc_dsyr2k  dsyr2k_
#define EigenFunc_dtrmm  dtrmm_
#define EigenFunc_dtrsm  dtrsm_
#define EigenFunc_cgemm  cgemm_
#define EigenFunc_csymm  csymm_
#define EigenFunc_csyrk  csyrk_
#define EigenFunc_csyr2k  csyr2k_
#define EigenFunc_ctrmm  ctrmm_
#define EigenFunc_ctrsm  ctrsm_
#define EigenFunc_zgemm  zgemm_
#define EigenFunc_zsymm  zsymm_
#define EigenFunc_zsyrk  zsyrk_
#define EigenFunc_zsyr2k  zsyr2k_
#define EigenFunc_ztrmm  ztrmm_
#define EigenFunc_ztrsm  ztrsm_
#define EigenFunc_chemm  chemm_
#define EigenFunc_cherk  cherk_
#define EigenFunc_cher2k  cher2k_
#define EigenFunc_zhemm  zhemm_
#define EigenFunc_zherk  zherk_
#define EigenFunc_zher2k  zher2k_

#endif  /* _EIGEN_H_ */