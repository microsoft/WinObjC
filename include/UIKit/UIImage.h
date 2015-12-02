/*
 * Copyright (c) 2011, The Iconfactory. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of The Iconfactory nor the names of its contributors may
 *    be used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE ICONFACTORY BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _UIIMAGE_H_
#define _UIIMAGE_H_

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIGeometry.h>
#import <StarboardExport.h>
#import <QuartzCore/CALayer.h>

enum {
    UIImageOrientationUp,
    UIImageOrientationDown, // 180 deg rotation
    UIImageOrientationLeft, // 90 deg CCW
    UIImageOrientationRight, // 90 deg CW
    UIImageOrientationUpMirrored, // as above but image mirrored along
    // other axis. horizontal flip
    UIImageOrientationDownMirrored, // horizontal flip
    UIImageOrientationLeftMirrored, // vertical flip
    UIImageOrientationRightMirrored, // vertical flip
};
typedef uint32_t UIImageOrientation;

enum {
    UIImageResizingModeTile,
    UIImageResizingModeStretch,
};
typedef uint32_t UIImageResizingMode;

enum { UIImageRenderingModeAutomatic, UIImageRenderingModeAlwaysOriginal, UIImageRenderingModeAlwaysTemplate };
typedef int32_t UIImageRenderingMode;

UIKIT_EXPORT_CLASS
@interface UIImage : NSObject

+ (UIImage*)imageNamed:(NSString*)name; // Note, this caches the images somewhat like iPhone OS 2ish in that it never releases them. :)
+ (UIImage*)imageWithData:(NSData*)data;
+ (UIImage*)imageWithContentsOfFile:(NSString*)path;
+ (UIImage*)imageWithCGImage:(CGImageRef)imageRef;
+ (UIImage*)imageWithCGImage:(CGImageRef)imageRef scale:(CGFloat)scale orientation:(UIImageOrientation)orientation;
+ (UIImage*)imageWithData:(NSData*)data scale:(CGFloat)scale;
+ (UIImage*)animatedImageWithImages:(NSArray*)images duration:(NSTimeInterval)duration;

// Starboard additions:
- (CGRect)_imageStretch;

- (id)initWithData:(NSData*)data;
- (id)initWithContentsOfFile:(NSString*)path;
- (id)initWithCGImage:(CGImageRef)imageRef;
- (id)initWithCGImage:(CGImageRef)imageRef scale:(CGFloat)scale orientation:(UIImageOrientation)orientation;

- (UIImage*)stretchableImageWithLeftCapWidth:(NSInteger)leftCapWidth topCapHeight:(NSInteger)topCapHeight;
- (UIImage*)resizableImageWithCapInsets:(UIEdgeInsets)capInsets;

// the draw methods will all check the scale of the current context and attempt to use the best representation it can
- (void)drawAtPoint:(CGPoint)point blendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha;
- (void)drawInRect:(CGRect)rect blendMode:(CGBlendMode)blendMode alpha:(CGFloat)alpha;
- (void)drawAtPoint:(CGPoint)point;
- (void)drawInRect:(CGRect)rect;

- (UIImage*)resizableImageWithCapInsets:(UIEdgeInsets)capInsets resizingMode:(UIImageResizingMode)resizingMode;
- (id)initWithData:(NSData*)data scale:(CGFloat)scale;
- (UIImage*)imageWithRenderingMode:(UIImageRenderingMode)renderingMode;

@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) NSTimeInterval duration;
@property (nonatomic, readonly) NSInteger leftCapWidth;
@property (nonatomic, readonly) NSInteger topCapHeight;
@property (nonatomic, readonly) UIImageRenderingMode renderingMode;
@property (nonatomic, readonly) UIImageOrientation imageOrientation; // not implemented

// note that these properties return always the 2x represention if it exists!
@property (nonatomic, readonly) CGImageRef CGImage;
@property (nonatomic, readonly) CGFloat scale;
@property (nonatomic, readonly) NSArray* images;

@end

UIKIT_EXPORT void UIImageWriteToSavedPhotosAlbum(UIImage* image, id completionTarget, SEL completionSelector, void* contextInfo);
UIKIT_EXPORT void UISaveVideoAtPathToSavedPhotosAlbum(NSString* videoPath, id completionTarget, SEL completionSelector, void* contextInfo);
UIKIT_EXPORT BOOL UIVideoAtPathIsCompatibleWithSavedPhotosAlbum(NSString* videoPath);

// both of these use .CGImage to generate the image data - note what this means for multi-scale images!
UIKIT_EXPORT NSData* UIImageJPEGRepresentation(UIImage* image, CGFloat compressionQuality);
UIKIT_EXPORT NSData* UIImagePNGRepresentation(UIImage* image);

void UIImageSetLayerContents(CALayer* layer, UIImage* image);

#endif /* _UIIMAGE_H_ */