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
#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGDataConsumer.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGPDFDictionary.h>
#import <CoreGraphics/CGPDFArray.h>
#import <CoreFoundation/CFURL.h>

COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextAuthor;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextCreator;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextTitle;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextOwnerPassword;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextUserPassword;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextAllowsPrinting;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextAllowsCopying;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextSubject;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextKeywords;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextEncryptionKeyLength;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextMediaBox;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextCropBox;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextBleedBox;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextTrimBox;
COREGRAPHICS_EXPORT const CFStringRef kCGPDFContextArtBox;

COREGRAPHICS_EXPORT CGContextRef CGPDFContextCreate(CGDataConsumerRef consumer,
                                                    const CGRect* mediaBox,
                                                    CFDictionaryRef auxiliaryInfo) STUB_METHOD;
COREGRAPHICS_EXPORT CGContextRef CGPDFContextCreateWithURL(CFURLRef url, const CGRect* mediaBox, CFDictionaryRef auxiliaryInfo) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContextBeginPage(CGContextRef context, CFDictionaryRef pageInfo) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContextEndPage(CGContextRef context) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContextAddDestinationAtPoint(CGContextRef context, CFStringRef name, CGPoint point) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContextSetDestinationForRect(CGContextRef context, CFStringRef name, CGRect rect) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContextSetURLForRect(CGContextRef context, CFURLRef url, CGRect rect) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContextAddDocumentMetadata(CGContextRef context, CFDataRef metadata) STUB_METHOD;
COREGRAPHICS_EXPORT void CGPDFContextClose(CGContextRef context) STUB_METHOD;
