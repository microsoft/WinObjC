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
#import <CoreGraphics/CGPDFObject.h>
#import <CoreGraphics/CGPDFDictionary.h>
#import <CoreGraphics/CGPDFString.h>
#import <CoreGraphics/CGPDFStream.h>

COREGRAPHICS_EXPORT bool CGPDFArrayGetArray(CGPDFArrayRef array, size_t index, CGPDFArrayRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetBoolean(CGPDFArrayRef array, size_t index, CGPDFBoolean* value) STUB_METHOD;
COREGRAPHICS_EXPORT size_t CGPDFArrayGetCount(CGPDFArrayRef array) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetDictionary(CGPDFArrayRef array, size_t index, CGPDFDictionaryRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetInteger(CGPDFArrayRef array, size_t index, CGPDFInteger* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetName(CGPDFArrayRef array, size_t index, const char* _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetNull(CGPDFArrayRef array, size_t index) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetNumber(CGPDFArrayRef array, size_t index, CGPDFReal* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetObject(CGPDFArrayRef array, size_t index, CGPDFObjectRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetString(CGPDFArrayRef array, size_t index, CGPDFStringRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFArrayGetStream(CGPDFArrayRef array, size_t index, CGPDFStreamRef _Nullable* value) STUB_METHOD;