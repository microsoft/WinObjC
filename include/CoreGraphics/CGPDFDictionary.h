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
#import <CoreGraphics/CGPDFArray.h>
#import <CoreGraphics/CGPDFObject.h>
#import <CoreGraphics/CGPDFString.h>
#import <CoreGraphics/CGPDFStream.h>

typedef void (*CGPDFDictionaryApplierFunction)(const char* key, CGPDFObjectRef value, void* info);

COREGRAPHICS_EXPORT void CGPDFDictionaryApplyFunction(CGPDFDictionaryRef dict,
                                                      CGPDFDictionaryApplierFunction function,
                                                      void* info) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetArray(CGPDFDictionaryRef dict, const char* key, CGPDFArrayRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetBoolean(CGPDFDictionaryRef dict, const char* key, CGPDFBoolean* value) STUB_METHOD;
COREGRAPHICS_EXPORT size_t CGPDFDictionaryGetCount(CGPDFDictionaryRef dict) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetDictionary(CGPDFDictionaryRef dict,
                                                      const char* key,
                                                      CGPDFDictionaryRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetInteger(CGPDFDictionaryRef dict, const char* key, CGPDFInteger* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetName(CGPDFDictionaryRef dict, const char* key, const char* _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetNumber(CGPDFDictionaryRef dict, const char* key, CGPDFReal* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetObject(CGPDFDictionaryRef dict, const char* key, CGPDFObjectRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetStream(CGPDFDictionaryRef dict, const char* key, CGPDFStreamRef _Nullable* value) STUB_METHOD;
COREGRAPHICS_EXPORT bool CGPDFDictionaryGetString(CGPDFDictionaryRef dict, const char* key, CGPDFStringRef _Nullable* value) STUB_METHOD;
