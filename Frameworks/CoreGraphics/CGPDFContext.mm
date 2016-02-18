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

const CFStringRef kCGPDFContextAuthor = static_cast<CFStringRef>(@"kCGPDFContextAuthor");
const CFStringRef kCGPDFContextCreator = static_cast<CFStringRef>(@"kCGPDFContextCreator");
const CFStringRef kCGPDFContextTitle = static_cast<CFStringRef>(@"kCGPDFContextTitle");
const CFStringRef kCGPDFContextOwnerPassword = static_cast<CFStringRef>(@"kCGPDFContextOwnerPassword");
const CFStringRef kCGPDFContextUserPassword = static_cast<CFStringRef>(@"kCGPDFContextUserPassword");
const CFStringRef kCGPDFContextAllowsPrinting = static_cast<CFStringRef>(@"kCGPDFContextAllowsPrinting");
const CFStringRef kCGPDFContextAllowsCopying = static_cast<CFStringRef>(@"kCGPDFContextAllowsCopying");
const CFStringRef kCGPDFContextSubject = static_cast<CFStringRef>(@"kCGPDFContextSubject");
const CFStringRef kCGPDFContextKeywords = static_cast<CFStringRef>(@"kCGPDFContextKeywords");
const CFStringRef kCGPDFContextEncryptionKeyLength = static_cast<CFStringRef>(@"kCGPDFContextEncryptionKeyLength");
const CFStringRef kCGPDFContextMediaBox = static_cast<CFStringRef>(@"kCGPDFContextMediaBox");
const CFStringRef kCGPDFContextCropBox = static_cast<CFStringRef>(@"kCGPDFContextCropBox");
const CFStringRef kCGPDFContextBleedBox = static_cast<CFStringRef>(@"kCGPDFContextBleedBox");
const CFStringRef kCGPDFContextTrimBox = static_cast<CFStringRef>(@"kCGPDFContextTrimBox");
const CFStringRef kCGPDFContextArtBox = static_cast<CFStringRef>(@"kCGPDFContextArtBox");

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
