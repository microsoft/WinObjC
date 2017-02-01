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

typedef struct __CGShading* CGShadingRef;

#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGColorSpace.h>
#import <CoreGraphics/CGFunction.h>

COREGRAPHICS_EXPORT CGShadingRef CGShadingCreateAxial(
    CGColorSpaceRef space, CGPoint start, CGPoint end, CGFunctionRef function, bool extendStart, bool extendEnd) STUB_METHOD;
COREGRAPHICS_EXPORT CGShadingRef CGShadingCreateRadial(CGColorSpaceRef space,
                                                       CGPoint start,
                                                       CGFloat startRadius,
                                                       CGPoint end,
                                                       CGFloat endRadius,
                                                       CGFunctionRef function,
                                                       bool extendStart,
                                                       bool extendEnd) STUB_METHOD;
COREGRAPHICS_EXPORT CGShadingRef CGShadingRetain(CGShadingRef shading) STUB_METHOD;
COREGRAPHICS_EXPORT void CGShadingRelease(CGShadingRef shading) STUB_METHOD;
COREGRAPHICS_EXPORT CFTypeID CGShadingGetTypeID() STUB_METHOD;