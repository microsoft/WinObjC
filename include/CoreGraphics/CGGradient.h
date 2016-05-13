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
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGColorSpace.h>

CF_IMPLICIT_BRIDGING_ENABLED

typedef enum { kCGGradientDrawsBeforeStartLocation = (1 << 0), kCGGradientDrawsAfterEndLocation = (1 << 1) } CGGradientDrawingOptions;

COREGRAPHICS_EXPORT CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef space,
                                                                      const CGFloat* components,
                                                                      const CGFloat* locations,
                                                                      size_t count);
COREGRAPHICS_EXPORT CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef space, CFArrayRef colors, const CGFloat* locations);
COREGRAPHICS_EXPORT void CGGradientRelease(CGGradientRef gradient);
COREGRAPHICS_EXPORT CGGradientRef CGGradientRetain(CGGradientRef gradient);

COREGRAPHICS_EXPORT CFTypeID CGGradientGetTypeID() STUB_METHOD;

CF_IMPLICIT_BRIDGING_DISABLED
