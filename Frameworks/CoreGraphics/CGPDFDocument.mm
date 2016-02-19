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
#import <CoreGraphics/CGPDFDocument.h>

/**
 @Status Stub
 @Notes
*/
CGPDFDocumentRef CGPDFDocumentCreateWithProvider(CGDataProviderRef provider) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFDocumentRef CGPDFDocumentCreateWithURL(CFURLRef url) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFDocumentRelease(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CGPDFDocumentRef CGPDFDocumentRetain(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGPDFDocumentGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFDictionaryRef CGPDFDocumentGetCatalog(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CGPDFDocumentGetNumberOfPages(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFPageRef CGPDFDocumentGetPage(CGPDFDocumentRef document, size_t pageNumber) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFDocumentGetVersion(CGPDFDocumentRef document, int* majorVersion, int* minorVersion) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CGPDFDictionaryRef CGPDFDocumentGetInfo(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFArrayRef CGPDFDocumentGetID(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFDocumentAllowsCopying(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFDocumentAllowsPrinting(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFDocumentIsEncrypted(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFDocumentIsUnlocked(CGPDFDocumentRef document) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFDocumentUnlockWithPassword(CGPDFDocumentRef document, const char* password) {
    UNIMPLEMENTED();
    return StubReturn();
}
