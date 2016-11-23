//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#ifndef COREGRAPHICS_IMPEXP
#define COREGRAPHICS_IMPEXP __declspec(dllimport)
#endif

#ifndef COREGRAPHICS_EXPORT
#ifdef __cplusplus
#define COREGRAPHICS_EXPORT COREGRAPHICS_IMPEXP extern "C"
#else
#define COREGRAPHICS_EXPORT COREGRAPHICS_IMPEXP extern
#endif
#endif

#ifndef COREGRAPHICS_EXTERNC_BEGIN
#if defined(__cplusplus)
#define COREGRAPHICS_EXTERNC_BEGIN extern "C" {
#define COREGRAPHICS_EXTERNC_END }
#else
#define COREGRAPHICS_EXTERNC_BEGIN
#define COREGRAPHICS_EXTERNC_END
#endif
#endif

// import CoreGraphics opaque types here to avoid ugly public header
// and to avoid compiler errors caused by import ordering
typedef struct __CGPDFContentStream* CGPDFContentStreamRef;
typedef struct __CGPDFContext* CGPDFContextRef;
typedef struct __CGPDFString* CGPDFStringRef;
typedef struct __CGPDFArray* CGPDFArrayRef;
typedef struct __CGPDFDictionary* CGPDFDictionaryRef;
typedef struct __CGPDFDocument* CGPDFDocumentRef;
typedef struct __CGPDFOperatorTable* CGPDFOperatorTableRef;
typedef struct __CGPDFPage* CGPDFPageRef;
typedef struct __CGPDFScanner* CGPDFScannerRef;
typedef struct __CGPDFStream* CGPDFStreamRef;
typedef union __CGPDFObject* CGPDFObjectRef;
