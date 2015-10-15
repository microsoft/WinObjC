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

#include "Starboard.h"
#include "CGPatternInternal.h"
#include "CGContextInternal.h"

@implementation CGPattern {
    CGImageRef generatedImage;
    CGImageRef simpleImage;
}
+ (instancetype)patternWithImage:(CGImageRef)img {
    CGPattern* ret = [CGPattern new];

    ret->matrix = CGAffineTransformIdentity;
    ret->simpleImage = img;
    CFRetain((id)img);

    return ret;
}

- (CGImageRef)getPatternImage {
    if (simpleImage) {
        CGImageRetain(simpleImage);
        return simpleImage;
    }

    float width = bounds.size.width;
    float height = bounds.size.height;

    if (width <= 0.0f || height <= 0.0f) {
        return nil;
    }

    // TODO: Take into account x/yStep, to justify the two calls here.
    CGContextRef patternCtx;
    if (isColored) {
        patternCtx = CGBitmapContextCreate32((DWORD)ceilf(width), (DWORD)ceilf(height));
    } else {
        patternCtx = CGBitmapContextCreate(NULL, (DWORD)ceilf(width), (DWORD)ceilf(height), 8, 0, NULL, 0);
    }

    CGContextTranslateCTM(patternCtx, 0.0f, height);
    CGContextScaleCTM(patternCtx, 1.0f, -1.0f);

    callbacks.drawPattern(info, patternCtx);

    CGImageRef tilePattern = CGBitmapContextCreateImage(patternCtx);

    CGContextRelease(patternCtx);

    float outWidth = width, outHeight = height;
    // TODO: Min limit on tiling or something?
    /*      while (outWidth < 256) {
    outWidth += width;
    }
    while (outHeight < 256) {
    outHeight += height;
    }*/

    if (isColored) {
        patternCtx = CGBitmapContextCreate32((DWORD)ceilf(outWidth), (DWORD)ceilf(outHeight));
    } else {
        patternCtx = CGBitmapContextCreate(NULL, (DWORD)ceilf(outWidth), (DWORD)ceilf(outHeight), 8, 0, NULL, 0);
    }

    CGRect rect = { 0, 0, width, height };
    CGContextDrawTiledImage(patternCtx, rect, tilePattern);

    CGImageRelease(tilePattern);

    if (generatedImage) {
        CGImageRelease(generatedImage);
    }

    // TODO: Caching.
    generatedImage = CGBitmapContextCreateImage(patternCtx);
    CGImageRetain(generatedImage);

    CGContextRelease(patternCtx);

    return generatedImage;
}

- (CGAffineTransform)getPatternTransform {
    return matrix;
}

- (void)dealloc {
    if (generatedImage) {
        CGImageRelease(generatedImage);
    }
    if (simpleImage) {
        CGImageRelease(simpleImage);
    }
    if (callbacks.releaseInfo) {
        callbacks.releaseInfo(info);
    }
    [super dealloc];
}
@end

CGPatternRef CGPatternCreateColorspace(void* info,
                                       CGRect bounds,
                                       CGAffineTransform matrix,
                                       CGFloat xStep,
                                       CGFloat yStep,
                                       CGPatternTiling tiling,
                                       bool isColored,
                                       const CGPatternCallbacks* callbacks,
                                       surfaceFormat fmt) {
    CGPattern* ret = [CGPattern new];

    // TODO: Obey the colorspace.
    ret->info = info;
    ret->bounds = bounds;
    ret->matrix = matrix;
    ret->xStep = xStep;
    ret->yStep = yStep;
    ret->tiling = tiling;
    ret->isColored = isColored;
    ret->callbacks = *callbacks;
    ret->surfaceFmt = fmt;

    return ret;
}

CGPatternRef CGPatternCreate(void* info,
                             CGRect bounds,
                             CGAffineTransform matrix,
                             CGFloat xStep,
                             CGFloat yStep,
                             CGPatternTiling tiling,
                             bool isColored,
                             const CGPatternCallbacks* callbacks) {
    return CGPatternCreateColorspace(info, bounds, matrix, xStep, yStep, tiling, isColored, callbacks, isColored ? _ColorRGBA : _ColorA8);
}

void CGPatternRelease(CGPatternRef pattern) {
    CFRelease(pattern);
}

CGPatternRef CGPatternCreateFromImage(CGImageRef img) {
    return [CGPattern patternWithImage:img];
}
