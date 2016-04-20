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

#import <CoreImage/CoreImageExport.h>
#import <Foundation/NSObject.h>
#import <CoreImage/CIImage.h>
#import <CoreGraphics/CoreGraphics.h>

@class NSString;
@class NSDictionary;
@class EAGLContext;
@protocol MTLDevice;
@class CIImage;
@protocol MTLTexture;
@protocol MTLCommandBuffer;

COREIMAGE_EXPORT NSString* const kCIContextOutputColorSpace;
COREIMAGE_EXPORT NSString* const kCIContextWorkingColorSpace;
COREIMAGE_EXPORT NSString* const kCIContextUseSoftwareRenderer;
COREIMAGE_EXPORT NSString* const kCIContextPriorityRequestLow;
COREIMAGE_EXPORT NSString* const kCIContextWorkingFormat;
COREIMAGE_EXPORT_CLASS
@interface CIContext : NSObject
+ (CIContext*)contextWithCGContext:(CGContextRef)ctx options:(NSDictionary*)dict STUB_METHOD;
+ (CIContext*)contextWithEAGLContext:(EAGLContext*)eaglContext STUB_METHOD;
+ (CIContext*)contextWithEAGLContext:(EAGLContext*)eaglContext options:(NSDictionary*)options STUB_METHOD;
+ (CIContext*)contextWithOptions:(NSDictionary*)dict;
+ (CIContext*)contextWithMTLDevice:(id<MTLDevice>)device STUB_METHOD;
+ (CIContext*)contextWithMTLDevice:(id<MTLDevice>)device options:(NSDictionary*)options STUB_METHOD;
- (CGImageRef)createCGImage:(CIImage*)im fromRect:(CGRect)r;
- (CGImageRef)createCGImage:(CIImage*)im fromRect:(CGRect)r format:(CIFormat)f colorSpace:(CGColorSpaceRef)cs STUB_METHOD;
- (void)drawImage:(CIImage*)im atPoint:(CGPoint)p fromRect:(CGRect)src STUB_METHOD;
- (void)drawImage:(CIImage*)im inRect:(CGRect)dest fromRect:(CGRect)src STUB_METHOD;
- (void)render:(CIImage*)im
      toBitmap:(void*)data
      rowBytes:(ptrdiff_t)rb
        bounds:(CGRect)r
        format:(CIFormat)f
    colorSpace:(CGColorSpaceRef)cs STUB_METHOD;
- (void)render:(CIImage*)image toCVPixelBuffer:(CVPixelBufferRef)buffer STUB_METHOD;
- (void)render:(CIImage*)image toCVPixelBuffer:(CVPixelBufferRef)buffer bounds:(CGRect)r colorSpace:(CGColorSpaceRef)cs STUB_METHOD;
- (void)render:(CIImage*)image
  toMTLTexture:(id<MTLTexture>)texture
 commandBuffer:(id<MTLCommandBuffer>)commandBuffer
        bounds:(CGRect)bounds
    colorSpace:(CGColorSpaceRef)colorSpace STUB_METHOD;
- (CGSize)inputImageMaximumSize STUB_METHOD;
- (CGSize)outputImageMaximumSize STUB_METHOD;
@property (readonly, nonatomic) CGColorSpaceRef workingColorSpace STUB_PROPERTY;
@end
