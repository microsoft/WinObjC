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
#import <CoreGraphics/CGPDFStream.h>
#import <CoreGraphics/CGPDFPage.h>
#import <CoreGraphics/CGPDFDictionary.h>

COREGRAPHICS_EXPORT CGPDFContentStreamRef CGPDFContentStreamCreateWithPage(CGPDFPageRef page) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFContentStreamRef CGPDFContentStreamCreateWithStream(CGPDFStreamRef stream,
                                                                             CGPDFDictionaryRef streamResources,
                                                                             CGPDFContentStreamRef parent) STUB_METHOD;
COREGRAPHICS_EXPORT CFArrayRef CGPDFContentStreamGetStreams(CGPDFContentStreamRef cs) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFObjectRef CGPDFContentStreamGetResource(CGPDFContentStreamRef cs,
                                                                 const char* category,
                                                                 const char* name) STUB_METHOD;
COREGRAPHICS_EXPORT CGPDFContentStreamRef CGPDFContentStreamRetain(CGPDFContentStreamRef cs) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContentStreamRelease(CGPDFContentStreamRef cs) STUB_METHOD;
