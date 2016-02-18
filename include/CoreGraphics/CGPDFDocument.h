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
#import <CoreGraphics/CGDataProvider.h>
#import <CoreGraphics/CGPDFArray.h>
#import <CoreGraphics/CGPDFDictionary.h>
#import <CoreFoundation/CFURL.h>
#import <CoreGraphics/CGPDFPage.h>

COREGRAPHICS_EXPORT CGPDFDocumentRef CGPDFDocumentCreateWithProvider(CGDataProviderRef provider) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFDocumentRef CGPDFDocumentCreateWithURL(CFURLRef url) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFDocumentRelease(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFDocumentRef CGPDFDocumentRetain(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT CFTypeID CGPDFDocumentGetTypeID() STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFDictionaryRef CGPDFDocumentGetCatalog(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT size_t CGPDFDocumentGetNumberOfPages(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFPageRef CGPDFDocumentGetPage(CGPDFDocumentRef document, size_t pageNumber) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFDocumentGetVersion(CGPDFDocumentRef document, int* majorVersion, int* minorVersion) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFDictionaryRef CGPDFDocumentGetInfo(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFArrayRef CGPDFDocumentGetID(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDocumentAllowsCopying(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDocumentAllowsPrinting(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDocumentIsEncrypted(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDocumentIsUnlocked(CGPDFDocumentRef document) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDocumentUnlockWithPassword(CGPDFDocumentRef document, const char* password) STUB_METHOD;