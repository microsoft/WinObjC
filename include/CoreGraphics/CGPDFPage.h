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
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGPDFDocument.h>
#import <CoreGraphics/CGGeometry.h>

typedef enum {
    kCGPDFMediaBox = 0,
    kCGPDFCropBox = 1,
    kCGPDFBleedBox = 2,
    kCGPDFTrimBox = 3,
    kCGPDFArtBox = 4,
} CGPDFBox;

COREGRAPHICS_EXPORT CGPDFPageRef CGPDFPageRetain(CGPDFPageRef page) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFPageRelease(CGPDFPageRef page) STUB_METHOD;
COREGRAPHICS_EXPORT CFTypeID CGPDFPageGetTypeID() STUB_METHOD;
COREGRAPHICS_EXPORT CGRect CGPDFPageGetBoxRect(CGPDFPageRef page, CGPDFBox box) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFDictionaryRef CGPDFPageGetDictionary(CGPDFPageRef page) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFDocumentRef CGPDFPageGetDocument(CGPDFPageRef page) STUB_METHOD;
COREGRAPHICS_EXPORT CGAffineTransform
CGPDFPageGetDrawingTransform(CGPDFPageRef page, CGPDFBox box, CGRect rect, int rotate, bool preserveAspectRatio) STUB_METHOD;
COREGRAPHICS_EXPORT size_t CGPDFPageGetPageNumber(CGPDFPageRef page) STUB_METHOD;
COREGRAPHICS_EXPORT int CGPDFPageGetRotationAngle(CGPDFPageRef page) STUB_METHOD;