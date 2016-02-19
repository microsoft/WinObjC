//******************************************************************************
//
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

#import <CoreGraphics/CoreGraphicsExport.h>
#import <CoreGraphics/CGPDFString.h>
#import <CoreGraphics/CGPDFContentStream.h>
#import <CoreGraphics/CGPDFObject.h>
#import <CoreGraphics/CGPDFOperatorTable.h>

COREGRAPHICS_EXPORT CGPDFScannerRef CGPDFScannerCreate(CGPDFContentStreamRef cs, CGPDFOperatorTableRef table, void* info) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFScannerRef CGPDFScannerRetain(CGPDFScannerRef scanner) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFScannerRelease(CGPDFScannerRef scanner) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerScan(CGPDFScannerRef scanner) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFContentStreamRef CGPDFScannerGetContentStream(CGPDFScannerRef scanner) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopObject(CGPDFScannerRef scanner, CGPDFObjectRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopBoolean(CGPDFScannerRef scanner, CGPDFBoolean* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopInteger(CGPDFScannerRef scanner, CGPDFInteger* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopNumber(CGPDFScannerRef scanner, CGPDFReal* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopName(CGPDFScannerRef scanner, const char* _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopString(CGPDFScannerRef scanner, CGPDFStringRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopArray(CGPDFScannerRef scanner, CGPDFArrayRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopDictionary(CGPDFScannerRef scanner, CGPDFDictionaryRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFScannerPopStream(CGPDFScannerRef scanner, CGPDFStreamRef _Nullable* value) STUB_METHOD;
