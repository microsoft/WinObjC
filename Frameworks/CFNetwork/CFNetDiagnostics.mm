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
#import <CFNetwork/CFNetDiagnostics.h>

/**
 @Status Stub
 @Notes
*/
CFNetDiagnosticRef CFNetDiagnosticCreateWithStreams(CFAllocatorRef alloc, CFReadStreamRef readStream, CFWriteStreamRef writeStream) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFNetDiagnosticRef CFNetDiagnosticCreateWithURL(CFAllocatorRef alloc, CFURLRef url) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
void CFNetDiagnosticSetName(CFNetDiagnosticRef details, CFStringRef name) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CFNetDiagnosticStatus CFNetDiagnosticDiagnoseProblemInteractively(CFNetDiagnosticRef details) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFNetDiagnosticStatus CFNetDiagnosticCopyNetworkStatusPassively(CFNetDiagnosticRef details, CFStringRef _Nullable* description) {
    UNIMPLEMENTED();
    return StubReturn();
}
