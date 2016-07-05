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

// This file is based on CBLAS http://www.netlib.org/blas/#_cblas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "Accelerate\cblas.h"
#include "CBLAS/cblas_f77.h"

// Default error handler for BLAS routines 
// For details, refer to developer.apple.com for cblas_xerbla
void cblas_xerbla(int info, const char* rout, const char* form, ...) {
    extern int RowMajorStrg;
    va_list argptr;

    va_start(argptr, form);

    char buf[256];
    int val = 0;

    // Rearranges parameter order to match the Fortran implementation 
    if (RowMajorStrg) {
        if (strstr(rout, "gemm") != 0) {
            if (info == 5) {
                info = 4;
            } else if (info == 4) {
                info = 5;
            } else if (info == 11) {
                info = 9;
            } else if (info == 9) {
                info = 11;
            }
        } else if (strstr(rout, "symm") != 0 || strstr(rout, "hemm") != 0) {
            if (info == 5) {
                info = 4;
            } else if (info == 4) {
                info = 5;
            }
        } else if (strstr(rout, "trmm") != 0 || strstr(rout, "trsm") != 0) {
            if (info == 7) {
                info = 6;
            } else if (info == 6) {
                info = 7;
            }
        } else if (strstr(rout, "gemv") != 0) {
            if (info == 4) {
                info = 3;
            } else if (info == 3) {
                info = 4;
            }
        } else if (strstr(rout, "gbmv") != 0) {
            if (info == 4) {
                info = 3;
            } else if (info == 3) {
                info = 4;
            } else if (info == 6) {
                info = 5;
            } else if (info == 5) {
                info = 6;
            }
        } else if (strstr(rout, "ger") != 0) {
            if (info == 3) {
                info = 2;
            } else if (info == 2) {
                info = 3;
            } else if (info == 8) {
                info = 6;
            } else if (info == 6) {
                info = 8;
            }
        } else if ((strstr(rout, "her2") != 0 || strstr(rout, "hpr2") != 0) && strstr(rout, "her2k") == 0) {
            if (info == 8) {
                info = 6;
            } else if (info == 6) {
                info = 8;
            }
        }
    }

    va_start(argptr, form);
    vsnprintf_s(buf, sizeof(buf), _TRUNCATE, form, argptr);
    va_end(argptr);
    __BLASErrorProc(rout, buf, &info, &val);
}


// Defined in ErrorHandler.mm
extern void AccelerateThrowFatal(const char*);

// Our helper Function for Default error handling
void BLASDefaultErrorProc(const char* funcName, const char* paramName, const int* paramPos, const int* paramValue) {
    char buf[BUFSIZ];
    int length;
    if (paramPos != NULL && funcName != NULL && funcName[0] != 0) {
        length = sprintf_s(buf, BUFSIZ, "Parameter %d to routine %s was incorrect\n", *paramPos, funcName);
    }
    if (paramName != NULL && paramName[0] != 0) {
        sprintf_s(buf+length-1, BUFSIZ-length, paramName);
    }
    AccelerateThrowFatal(buf);
}

// Sets an error handler function
// For more details, refer to developer.apple.com for SetBLASParamErrorProc
void SetBLASParamErrorProc(BLASParamErrorProc __ErrorProc) {
    __BLASErrorProc = __ErrorProc ? __ErrorProc : BLASDefaultErrorProc;
}