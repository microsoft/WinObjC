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
#import <CoreGraphics/CGPDFPage.h>

/**
 @Status Stub
 @Notes
*/
CGPDFPageRef CGPDFPageRetain(CGPDFPageRef page) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFPageRelease(CGPDFPageRef page) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGPDFPageGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGRect CGPDFPageGetBoxRect(CGPDFPageRef page, CGPDFBox box) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFDictionaryRef CGPDFPageGetDictionary(CGPDFPageRef page) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFDocumentRef CGPDFPageGetDocument(CGPDFPageRef page) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGAffineTransform CGPDFPageGetDrawingTransform(CGPDFPageRef page, CGPDFBox box, CGRect rect, int rotate, bool preserveAspectRatio) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CGPDFPageGetPageNumber(CGPDFPageRef page) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
int CGPDFPageGetRotationAngle(CGPDFPageRef page) {
    UNIMPLEMENTED();
    return StubReturn();
}
