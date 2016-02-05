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
#import <CoreGraphics/CGPDFScanner.h>

/**
 @Status Stub
 @Notes
*/
CGPDFScannerRef CGPDFScannerCreate(CGPDFContentStreamRef cs, CGPDFOperatorTableRef table, void* info) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFScannerRef CGPDFScannerRetain(CGPDFScannerRef scanner) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CGPDFScannerRelease(CGPDFScannerRef scanner) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerScan(CGPDFScannerRef scanner) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGPDFContentStreamRef CGPDFScannerGetContentStream(CGPDFScannerRef scanner) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopObject(CGPDFScannerRef scanner, CGPDFObjectRef _Nullable* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopBoolean(CGPDFScannerRef scanner, CGPDFBoolean* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopInteger(CGPDFScannerRef scanner, CGPDFInteger* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopNumber(CGPDFScannerRef scanner, CGPDFReal* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopName(CGPDFScannerRef scanner, const char* _Nullable* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopString(CGPDFScannerRef scanner, CGPDFStringRef _Nullable* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopArray(CGPDFScannerRef scanner, CGPDFArrayRef _Nullable* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopDictionary(CGPDFScannerRef scanner, CGPDFDictionaryRef _Nullable* value) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
bool CGPDFScannerPopStream(CGPDFScannerRef scanner, CGPDFStreamRef _Nullable* value) {
    UNIMPLEMENTED();
    return StubReturn();
}
