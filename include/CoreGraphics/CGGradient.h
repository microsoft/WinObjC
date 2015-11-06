//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifndef _CGGRADIENT_H_
#define _CGGRADIENT_H_

#import <StarboardExport.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGColorSpace.h>

ENABLE_IMPLICIT_BRIDGING

typedef struct __CGGradient* CGGradientRef;

enum {
    kCGGradientDrawsBeforeStartLocation = 0x01,
    kCGGradientDrawsAfterEndLocation = 0x02,
};
typedef uint32_t CGGradientDrawingOptions;

COREGRAPHICS_EXPORT CGGradientRef CGGradientCreateWithColorComponents(CGColorSpaceRef colorSpace,
                                                                      const CGFloat components[],
                                                                      const CGFloat locations[],
                                                                      size_t count);
COREGRAPHICS_EXPORT CGGradientRef CGGradientCreateWithColors(CGColorSpaceRef colorSpace, CFArrayRef colors, const CGFloat locations[]);

COREGRAPHICS_EXPORT void CGGradientRelease(CGGradientRef self);
COREGRAPHICS_EXPORT CGGradientRef CGGradientRetain(CGGradientRef self);

DISABLE_IMPLICIT_BRIDGING

#endif // _CGGRADIENT_H_
