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

#import <StubReturn.h>
#import <CoreGraphics/CGPDFContext.h>

const CFStringRef kCGPDFContextAuthor = CFSTR("kCGPDFContextAuthor");
const CFStringRef kCGPDFContextCreator = CFSTR("kCGPDFContextCreator");
const CFStringRef kCGPDFContextTitle = CFSTR("kCGPDFContextTitle");
const CFStringRef kCGPDFContextOwnerPassword = CFSTR("kCGPDFContextOwnerPassword");
const CFStringRef kCGPDFContextUserPassword = CFSTR("kCGPDFContextUserPassword");
const CFStringRef kCGPDFContextAllowsPrinting = CFSTR("kCGPDFContextAllowsPrinting");
const CFStringRef kCGPDFContextAllowsCopying = CFSTR("kCGPDFContextAllowsCopying");
const CFStringRef kCGPDFContextSubject = CFSTR("kCGPDFContextSubject");
const CFStringRef kCGPDFContextKeywords = CFSTR("kCGPDFContextKeywords");
const CFStringRef kCGPDFContextEncryptionKeyLength = CFSTR("kCGPDFContextEncryptionKeyLength");
const CFStringRef kCGPDFContextMediaBox = CFSTR("kCGPDFContextMediaBox");
const CFStringRef kCGPDFContextCropBox = CFSTR("kCGPDFContextCropBox");
const CFStringRef kCGPDFContextBleedBox = CFSTR("kCGPDFContextBleedBox");
const CFStringRef kCGPDFContextTrimBox = CFSTR("kCGPDFContextTrimBox");
const CFStringRef kCGPDFContextArtBox = CFSTR("kCGPDFContextArtBox");

/**
 @Status Stub
 @Notes
*/
CGContextRef CGPDFContextCreate(CGDataConsumerRef consumer, const CGRect* mediaBox, CFDictionaryRef auxiliaryInfo) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGContextRef CGPDFContextCreateWithURL(CFURLRef url, const CGRect* mediaBox, CFDictionaryRef auxiliaryInfo) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFContextBeginPage(CGContextRef context, CFDictionaryRef pageInfo) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFContextEndPage(CGContextRef context) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFContextAddDestinationAtPoint(CGContextRef context, CFStringRef name, CGPoint point) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFContextSetDestinationForRect(CGContextRef context, CFStringRef name, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFContextSetURLForRect(CGContextRef context, CFURLRef url, CGRect rect) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFContextAddDocumentMetadata(CGContextRef context, CFDataRef metadata) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFContextClose(CGContextRef context) {
    UNIMPLEMENTED();
}
