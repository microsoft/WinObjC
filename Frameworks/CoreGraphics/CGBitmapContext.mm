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
#import <CoreGraphics/CGBitmapContext.h>

/**
 @Status Stub
 @Notes
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
 @Status Stub
 @Notes
*/
/*
CGImageRef CGBitmapContextCreateImage(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}*/

/**
 @Status Stub
 @Notes
*/
CGBitmapInfo CGBitmapContextGetBitmapInfo(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
/*
CGImageAlphaInfo CGBitmapContextGetAlphaInfo(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}*/

/**
 @Status Stub
 @Notes
*/
size_t CGBitmapContextGetBitsPerComponent(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
size_t CGBitmapContextGetBitsPerPixel(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
/*
CGColorSpaceRef CGBitmapContextGetColorSpace(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}*/

/**
 @Status Stub
 @Notes
*/
/*
void * CGBitmapContextGetData(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}*/

/**
 @Status Stub
 @Notes
*/
/*
size_t CGBitmapContextGetHeight(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}*/

/**
 @Status Stub
 @Notes
*/
/*
size_t CGBitmapContextGetWidth(CGContextRef context) {
    UNIMPLEMENTED();
    return StubReturn();
}*/
