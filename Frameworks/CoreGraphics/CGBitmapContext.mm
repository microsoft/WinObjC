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
#import <CoreGraphics/CGContext.h>
#import "CGContextInternal.h"
#import <CoreGraphics/CGImage.h>

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
 @Status Caveat
 @Notes tied to underlying implementation caveats in CGImageGetBitmapInfo. 
*/
CGBitmapInfo CGBitmapContextGetBitmapInfo(CGContextRef context) {
	CGImageRef imageRef = context->Backing()->DestImage();
	CGBitmapInfo bitmapInfo = CGImageGetBitmapInfo(imageRef);
	return bitmapInfo;
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
 @Status Interoperable
 @Notes
*/
size_t CGBitmapContextGetBitsPerComponent(CGContextRef context) {
	  CGImageRef imageRef = context->Backing()->DestImage();
	  size_t bitsPerComponent = CGImageGetBitsPerComponent(imageRef);
      return bitsPerComponent;
}

/**
 @Status Caveat
 @Notes UIView in Islandwood ignores alpha by default, which differs from iOS.
 Expect returns of 24 bits on Islandwood where 32 bits is expected on iOS.
*/
size_t CGBitmapContextGetBitsPerPixel(CGContextRef context) {
	CGImageRef imageRef = context->Backing()->DestImage();
	size_t bytesPerPixel = imageRef->Backing()->BytesPerPixel();
	size_t bitesPerCompoenent = CGBitmapContextGetBitsPerComponent(context);
	return bytesPerPixel * bitesPerCompoenent;
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
