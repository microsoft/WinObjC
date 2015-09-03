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
    return nil;
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
    auto bytes = (const unsigned char*)[data bytes];

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);

    GLint fmt, type;
    GLKTextureInfoAlphaState as;
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
        NSLog(@"Unrecognized image format - %d bpp, (%dx%d) image.", bpp, w, h);
        return nil;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, fmt, w, h, 0, fmt, type, bytes);
    GLint i = glGetError();
    if (i != 0) {
        NSLog(@"Error %d creating texture.", i);
    }

    return [[GLKTextureInfo alloc] initWith: tex target: GL_TEXTURE_2D width: w height: h alphaState: as];
}   

-(id)initWithShareContext:(NSOpenGLContext*)context {
    return self;
}

@end

