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

typedef struct __CGPattern* CGPatternRef;

#import <CoreGraphics/CGContext.h>
#import <CoreGraphics/CGAffineTransform.h>
#import <CoreGraphics/CGGeometry.h>
#import <CoreGraphics/CGImage.h>

typedef void (*CGPatternDrawPatternCallback)(void* info, CGContextRef context);
typedef void (*CGPatternReleaseInfoCallback)(void* info);
typedef struct {
    unsigned int version;
    CGPatternDrawPatternCallback drawPattern;
    CGPatternReleaseInfoCallback releaseInfo;
} CGPatternCallbacks;

typedef CF_ENUM(CFIndex, CGPatternTiling) {
    kCGPatternTilingNoDistortion,
    kCGPatternTilingConstantSpacingMinimalDistortion,
    kCGPatternTilingConstantSpacing,
};

COREGRAPHICS_EXPORT CGPatternRef CGPatternCreate(void* info,
                                                 CGRect bounds,
                                                 CGAffineTransform matrix,
                                                 CGFloat xStep,
                                                 CGFloat yStep,
                                                 CGPatternTiling tiling,
                                                 bool isColored,
                                                 const CGPatternCallbacks* callbacks);

COREGRAPHICS_EXPORT CGPatternRef CGPatternRetain(CGPatternRef pattern);
COREGRAPHICS_EXPORT void CGPatternRelease(CGPatternRef pattern);

COREGRAPHICS_EXPORT CFTypeID CGPatternGetTypeID();
