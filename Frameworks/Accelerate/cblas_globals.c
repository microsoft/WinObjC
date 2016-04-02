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


//making global variable thread local
__declspec(thread) int CBLAS_CallFromC=0;
__declspec(thread) int RowMajorStrg=0;

void BLASDefaultErrorProc(const char *funcName, const char *paramName, const int *paramPos, const int *paramValue);
void (*__BLASErrorProc)(const char *funcName, const char *paramName, const int *paramPos, const int *paramValue) = BLASDefaultErrorProc;

