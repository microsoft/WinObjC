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

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#import <Starboard.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKTexture.h>

// TODO: BK: reorg, lots of cut & paste here.

NSString* const GLKTextureLoaderApplyPremultiplication = @"ApplyPremult";
NSString* const GLKTextureLoaderGenerateMipmaps = @"Mips";
NSString* const GLKTextureLoaderOriginBottomLeft = @"BottomLeft";
NSString* const GLKTextureLoaderGrayscaleAsAlpha = @"AlphaGrayscale";
NSString* const GLKTextureLoaderSRGB = @"SRGB";

namespace {

bool getOpt(NSDictionary* d, NSString* opt)
{
    if (d) {
        NSNumber* n = [d objectForKey: opt];
        if (n) {
            return ([n intValue] > 0);
        }
    }
    return false;
}

void swapRows(unsigned char* bytes, size_t rowSize, size_t h)
{
    auto tmp = (unsigned char*)_alloca(rowSize);
    auto end = bytes + (rowSize * (h - 1));
    while(end > bytes) {
        memcpy(tmp, bytes, rowSize);
        memcpy(bytes, end, rowSize);
        memcpy(end, tmp, rowSize);
        
        end -= rowSize;
        bytes += rowSize;
    }
}
 
bool getBitmapFormat(GLint& fmt, GLint& type, GLKTextureInfoAlphaState& as, int bpp)
{
    switch(bpp) {
      case 8:
          fmt = GL_ALPHA;
          type = GL_UNSIGNED_BYTE;
          as = GLKTextureInfoAlphaStateNonPremultiplied;
          break;
          
      case 16:
          fmt = GL_RGB;
          type = GL_UNSIGNED_SHORT_5_6_5;
          as = GLKTextureInfoAlphaStateNone;
          break;
          
      case 24:
          fmt = GL_RGB;
          type = GL_UNSIGNED_BYTE;
          as = GLKTextureInfoAlphaStateNone;
          break;
          
      case 32:
          fmt = GL_RGBA;
          type = GL_UNSIGNED_BYTE;
          as = GLKTextureInfoAlphaStateNonPremultiplied;
          break;

      default:
          NSLog(@"Unrecognized image format - %d bpp.", bpp);
          return false;
    }

    return true;
}

}
 
@implementation GLKTextureInfo
-(id)initWith: (GLuint)tex target:(GLuint)targ width:(GLuint)width height:(GLuint)height
   alphaState:(GLKTextureInfoAlphaState)as
{
    _name = tex;
    _target = targ;
    _width = width;
    _height = height;
    _alphaState = as;
    _containsMipmaps = FALSE;
    _textureOrigin = GLKTextureInfoOriginTopLeft;
    return self; 
}
@end

@implementation GLKTextureLoader {
}

+(GLKTextureInfo*)textureWithContentsOfFile: (NSString*)fname options: (NSDictionary*)opts error: (NSError**)err {
    CGDataProviderRef provider = CGDataProviderCreateWithFilename([fname UTF8String]);
    CGImageRef img = CGImageCreateWithPNGDataProvider(provider, NULL, NO, kCGRenderingIntentDefault);
    
    return [self textureWithCGImage: img options: opts error: err];
}

+(GLKTextureInfo*)textureWithContentsOfData: (NSData*)data options: (NSDictionary*)opts error: (NSError**)err {
    return nil;
}

+(GLKTextureInfo*)textureWithCGImage: (CGImageRef)img options: (NSDictionary*)opts error: (NSError**)err
{
    size_t w = CGImageGetWidth(img);
    size_t h = CGImageGetHeight(img);
    size_t bpp = CGImageGetBitsPerPixel(img);
    size_t rowSize = CGImageGetBytesPerRow(img);
    size_t expectedRowSize = (bpp / 8) * w;
    if(rowSize != expectedRowSize) {
        NSLog(@"WARNING - Image (%dx%d) - expected row size %d, got row size %d\n", w, h, expectedRowSize, rowSize);
    }
    
    CGDataProviderRef provider = CGImageGetDataProvider(img);
    NSData* data = (id)CGDataProviderCopyData(provider);
    [data autorelease];
    auto bytes = (unsigned char*)[data bytes];

    if (getOpt(opts, GLKTextureLoaderOriginBottomLeft)) {
        swapRows(bytes, rowSize, h);
    }
    
    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);    

    GLint fmt, type;
    GLKTextureInfoAlphaState as;
    if (!getBitmapFormat(fmt, type, as, bpp)) return nil;

    NSLog(@"Creating %dx%d texture, %d bpp, fmt 0x%x type 0x%x.", w, h, bpp, fmt, type);

    glTexImage2D(GL_TEXTURE_2D, 0, fmt, w, h, 0, fmt, type, bytes);
    GLint i = glGetError();
    if (i != 0) {
        NSLog(@"Error %d creating texture.", i);
    }

    return [[GLKTextureInfo alloc] initWith: tex target: GL_TEXTURE_2D width: w height: h alphaState: as];
}

+(GLKTextureInfo*)cubeMapWithContentsOfFile: (NSString*)fname options: (NSDictionary*)opts error: (NSError**)err
{
    CGDataProviderRef provider = CGDataProviderCreateWithFilename([fname UTF8String]);
    if (!provider) return nil;
    CGImageRef img = CGImageCreateWithPNGDataProvider(provider, NULL, NO, kCGRenderingIntentDefault);
    if (!img) return nil;
    
    size_t w = CGImageGetWidth(img);
    size_t h = CGImageGetHeight(img);
    size_t bpp = CGImageGetBitsPerPixel(img);
    size_t rowSize = CGImageGetBytesPerRow(img);
    size_t expectedRowSize = (bpp / 8) * w;
    if(rowSize != expectedRowSize) {
        NSLog(@"WARNING - Image (%dx%d) - expected row size %d, got row size %d\n", w, h, expectedRowSize, rowSize);
    }

    if (h != 6 * w) {
        NSLog(@"ERROR - Unexpected cube map format, expected 6 square textures aligned vertically.");
        return nil;
    }
    
    NSData* data = (id)CGDataProviderCopyData(provider);
    [data autorelease];
    auto bytes = (const unsigned char*)[data bytes];

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    GLint fmt, type;
    GLKTextureInfoAlphaState as;
    if (!getBitmapFormat(fmt, type, as, bpp)) return nil;

    NSLog(@"Creating %dx%d cube map texture, %d bpp, fmt 0x%x type 0x%x.", w, h, bpp, fmt, type);

    size_t sideh = h / 6;
    for(int i = 0; i < 6; i ++) {
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, fmt, w, sideh, 0, fmt, type, bytes);
        GLint err = glGetError();
        if (err != 0) {
            NSLog(@"Error %d creating cube face %d.", err, i);
        }
        bytes += rowSize * sideh;
    }

    return [[GLKTextureInfo alloc] initWith: tex target: GL_TEXTURE_2D width: w height: sideh alphaState: as];
}

+(GLKTextureInfo*)cubeMapWithContentsOfFiles: (NSArray*)fnames options: (NSDictionary*)opts error: (NSError**)err
{
    if ([fnames count] != 6) return nil;

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
    bool fmtInited = false;
    size_t sideW = 0, sideH = 0, imgBpp = 0, imgRowSize = 0;
    size_t curSide = 0;

    GLKTextureInfoAlphaState as;
    for(NSString* fn in fnames) {
        CGDataProviderRef provider = CGDataProviderCreateWithFilename([fn UTF8String]);
        if (!provider) {
            NSLog(@"Unable to open cube side texture %@", fn);
            curSide ++;
            continue;
        }
        CGImageRef img = CGImageCreateWithPNGDataProvider(provider, NULL, NO, kCGRenderingIntentDefault);
        if (!img) {
            NSLog(@"Unable to create image from cube side texture %@", fn);            
            curSide ++;
            continue;
        }

        NSData* data = (id)CGDataProviderCopyData(provider);
        [data autorelease];
        auto bytes = (const unsigned char*)[data bytes];

        size_t w = CGImageGetWidth(img);
        size_t h = CGImageGetHeight(img);
        size_t bpp = CGImageGetBitsPerPixel(img);
        size_t rowSize = CGImageGetBytesPerRow(img);
        size_t expectedRowSize = (bpp / 8) * w;
        if(w != h || rowSize != expectedRowSize) {
            NSLog(@"WARNING - Image %@ (%dx%d) - is in an invalid format.", fn, w, h);
            curSide ++;
            continue;
        }

        if (!fmtInited) {
            fmtInited = true;
            sideW = w;
            sideH = h;
            imgBpp = bpp;
            imgRowSize = rowSize;
        } else {
            if ((w != sideW) || (h != sideH) || (imgBpp != bpp)) {
                NSLog(@"WARNING - Image %@ (%dx%d) - does not match existing format.", fn, w, h);
                curSide ++;
                continue;
            }
        }

        GLint fmt, type;
        if (!getBitmapFormat(fmt, type, as, bpp)) return nil;

        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + curSide, 0, fmt, w, h, 0, fmt, type, bytes);
        GLint err = glGetError();
        if (err != 0) {
            NSLog(@"Error %d creating cube face %d.", err, curSide);
        }
        curSide ++;
    }
    if (!fmtInited) {
        NSLog(@"Unable to create cube map.");
        return nil;
    }
    
    return [[GLKTextureInfo alloc] initWith: tex target: GL_TEXTURE_2D width: sideW height: sideH alphaState: as];
}

-(id)initWithShareContext:(NSOpenGLContext*)context {
    return self;
}

@end

