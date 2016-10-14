//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
#import <CoreGraphics/CGBitmapContext.h>
#import <CoreGraphics/CGContext.h>
#import "CGContextInternal.h"
#import <CoreGraphics/CGImage.h>

static const wchar_t* TAG = L"CGBitmapContext";

/**
 @Status Stub
*/
CGContextRef CGBitmapContextCreateWithData(void* data,
                                           size_t width,
                                           size_t height,
                                           size_t bitsPerComponent,
                                           size_t bytesPerRow,
                                           CGColorSpaceRef space,
                                           uint32_t bitmapInfo,
                                           CGBitmapContextReleaseDataCallback releaseCallback,
                                           void* releaseInfo) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGBitmapInfo CGBitmapContextGetBitmapInfo(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
CGImageAlphaInfo CGBitmapContextGetAlphaInfo(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
size_t CGBitmapContextGetBitsPerComponent(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Caveat
 @Notes UIView in Islandwood ignores alpha by default, which differs from iOS.
 Expect returns of 24 bits on Islandwood where 32 bits is expected on iOS.
*/
size_t CGBitmapContextGetBitsPerPixel(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}