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
#import <CoreGraphics/CGPDFSCanner.h>

typedef void (*CGPDFOperatorCallback)(CGPDFScannerRef scanner, void* info);

COREGRAPHICS_EXPORT CGPDFOperatorTableRef CGPDFOperatorTableCreate() STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFOperatorTableSetCallback(CGPDFOperatorTableRef table,
                                                       const char* name,
                                                       CGPDFOperatorCallback callback) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFOperatorTableRef CGPDFOperatorTableRetain(CGPDFOperatorTableRef table) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFOperatorTableRelease(CGPDFOperatorTableRef table) STUB_METHOD;
