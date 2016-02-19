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
#import <CoreGraphics/CGLayer.h>

/**
 @Status Stub
 @Notes
*/
CGLayerRef CGLayerCreateWithContext(CGContextRef context, CGSize size, CFDictionaryRef auxiliaryInfo) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
/*
void CGContextDrawLayerInRect(CGContextRef context, CGRect rect, CGLayerRef layer) {
    UNIMPLEMENTED();
}*/

/**
 @Status Stub
 @Notes
*/
/*
void CGContextDrawLayerAtPoint(CGContextRef context, CGPoint point, CGLayerRef layer) {
    UNIMPLEMENTED();
}*/

/**
 @Status Stub
 @Notes
*/
void CGLayerRelease(CGLayerRef layer) {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
CGLayerRef CGLayerRetain(CGLayerRef layer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CFTypeID CGLayerGetTypeID() {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGSize CGLayerGetSize(CGLayerRef layer) {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
CGContextRef CGLayerGetContext(CGLayerRef layer) {
    UNIMPLEMENTED();
    return StubReturn();
}
