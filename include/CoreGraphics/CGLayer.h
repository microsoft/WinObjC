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
#pragma once

#import <CoreGraphics/CoreGraphicsExport.h>

typedef struct __CGLayer* CGLayerRef;

#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGContext.h>

COREGRAPHICS_EXPORT CGLayerRef CGLayerCreateWithContext(CGContextRef context, CGSize size, CFDictionaryRef auxiliaryInfo) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextDrawLayerInRect(CGContextRef context, CGRect rect, CGLayerRef layer) STUB_METHOD;
COREGRAPHICS_EXPORT void CGContextDrawLayerAtPoint(CGContextRef context, CGPoint point, CGLayerRef layer) STUB_METHOD;
COREGRAPHICS_EXPORT void CGLayerRelease(CGLayerRef layer) STUB_METHOD;
COREGRAPHICS_EXPORT CGLayerRef CGLayerRetain(CGLayerRef layer) STUB_METHOD;
COREGRAPHICS_EXPORT CFTypeID CGLayerGetTypeID() STUB_METHOD;
COREGRAPHICS_EXPORT CGSize CGLayerGetSize(CGLayerRef layer) STUB_METHOD;
COREGRAPHICS_EXPORT CGContextRef CGLayerGetContext(CGLayerRef layer) STUB_METHOD;