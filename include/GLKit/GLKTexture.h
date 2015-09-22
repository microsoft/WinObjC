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

#pragma once

#import "OpenGLES/ES2/gl.h"
#import "Foundation/NSObject.h"
#import "Foundation/NSData.h"
#import "CoreGraphics/CGImage.h"
#import "GLKit/GLKEnums.h"

@class NSOpenGLContext;
@class NSData;

extern GLKIT_EXPORT NSString* const GLKTextureLoaderApplyPremultiplication;
extern GLKIT_EXPORT NSString* const GLKTextureLoaderGenerateMipmaps;
extern GLKIT_EXPORT NSString* const GLKTextureLoaderOriginBottomLeft;
extern GLKIT_EXPORT NSString* const GLKTextureLoaderGrayscaleAsAlpha;
extern GLKIT_EXPORT NSString* const GLKTextureLoaderSRGB;

// --------------------------------------------------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKTextureInfo : NSObject

@property (readonly) GLuint name;
@property (readonly) GLuint target;

@property (readonly) GLuint width;
@property (readonly) GLuint height;
@property (readonly) GLKTextureInfoAlphaState alphaState;
@property (readonly) BOOL containsMipmaps;

@property (readonly) GLKTextureInfoOrigin textureOrigin;

-(id)initWith: (GLuint)tex target:(GLuint)targ width:(GLuint)width height:(GLuint)height alphaState:(GLKTextureInfoAlphaState)as;
@end

GLKIT_EXPORT_CLASS
@interface GLKTextureLoader : NSObject

+(GLKTextureInfo*)textureWithContentsOfFile: (NSString*)fname options: (NSDictionary*)opts error: (NSError**)err;
+(GLKTextureInfo*)textureWithContentsOfData: (NSData*)data options: (NSDictionary*)opts error: (NSError**)err;
+(GLKTextureInfo*)textureWithCGImage: (CGImageRef)img options: (NSDictionary*)opts error: (NSError**)err;

+(GLKTextureInfo*)cubeMapWithContentsOfFile: (NSString*)fname options: (NSDictionary*)opts error: (NSError**)err;
+(GLKTextureInfo*)cubeMapWithContentsOfFiles: (NSArray*)fnames options: (NSDictionary*)opts error: (NSError**)err;

-(id)initWithShareContext:(NSOpenGLContext*)context;

@end

