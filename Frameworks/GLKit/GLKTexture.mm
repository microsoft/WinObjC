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

#include <utility>

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

template <int C>
class PixelByteChannel {
public:
    static const int sizeBytes = C;
    static const int channels = C;

    template <int CHANNEL>
    inline float getCh() const {
        return static_cast<float>(bytes[CHANNEL]) / 255.f;
    }

    template <int CHANNEL>
    inline void setChan(float* vals) {
        setChan<CHANNEL - 1>(vals);
        bytes[CHANNEL - 1] = (unsigned char)(vals[CHANNEL - 1] * 255.f);
    }
    template <>
    inline void setChan<0>(float* vals) {
    }

    inline void setCh(float* vals) {
        setChan<C>(vals);
    }
    inline void setCh0(float val) {
        bytes[0] = (unsigned char)(255.f * val);
    }

private:
    unsigned char bytes[sizeBytes];
};

class PixelRGB16 {
public:
    static const int sizeBytes = 2;
    static const int channels = 3;

    template <int C>
    inline float getCh() const {
    }
    template <>
    inline float getCh<0>() const {
        return static_cast<float>((val >> 11) & 0x1F) / 31.f;
    }
    template <>
    inline float getCh<1>() const {
        return static_cast<float>((val >> 5) & 0x3F) / 63.f;
    }
    template <>
    inline float getCh<2>() const {
        return static_cast<float>(val & 0x1F) / 31.f;
    }

    inline void setCh(float* vals) {
        val = ((unsigned short)(vals[0] * 31.f) << 11) | ((unsigned short)(vals[1] * 63.f) << 5) | ((unsigned short)(vals[2] * 31.f));
    }

private:
    unsigned short int val;
};

template <class PSRC>
void GreyscaleConvert(PixelByteChannel<1>* pdst, PSRC* psrc, int pixels) {
    for (int i = 0; i < pixels; i++) {
        float grey = (psrc[i].template getCh<0>() * 0.6f) + (psrc[i].template getCh<1>() * 0.3f) + (psrc[i].template getCh<2>() * 0.1f);
        pdst[i].setCh0(grey);
    }
}

bool getOpt(NSDictionary* d, NSString* opt) {
    if (d) {
        NSNumber* n = [d objectForKey:opt];
        if (n) {
            return ([n intValue] > 0);
        }
    }
    return false;
}

void swapRows(unsigned char* bytes, size_t rowSize, size_t h) {
    auto tmp = (unsigned char*)_alloca(rowSize);
    auto end = bytes + (rowSize * (h - 1));
    while (end > bytes) {
        memcpy(tmp, bytes, rowSize);
        memcpy(bytes, end, rowSize);
        memcpy(end, tmp, rowSize);

        end -= rowSize;
        bytes += rowSize;
    }
}

bool getBitmapFormat(GLint& fmt, GLint& type, GLKTextureInfoAlphaState& as, int bpp) {
    switch (bpp) {
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

template <typename PIX>
class BoxGen {
    template <int C>
    struct BoxCalc {
        inline static void apply(const PIX& s0, const PIX& s1, const PIX& s2, const PIX& s3, float* out) {
            out[C] = 0.25f * (s0.template getCh<C>() + s1.template getCh<C>() + s2.template getCh<C>() + s3.template getCh<C>());
            BoxCalc<C + 1>::apply(s0, s1, s2, s3, out);
        }
    };

    template <>
    struct BoxCalc<PIX::channels> {
        inline static void apply(const PIX&, const PIX&, const PIX&, const PIX&, float*) {
        }
    };

public:
    inline static void calculate(const PIX* in, PIX* out, size_t w, size_t mipW, size_t x, size_t y) {
        size_t ix = x << 1;
        size_t iy = y << 1;

        const PIX& src0 = in[iy * w + ix];
        const PIX& src1 = in[iy * w + ix + 1];
        const PIX& src2 = in[(iy + 1) * w + ix];
        const PIX& src3 = in[(iy + 1) * w + ix + 1];

        float outChans[PIX::channels];
        BoxCalc<0>::apply(src0, src1, src2, src3, outChans);
        out[y * mipW + x].setCh(outChans);
    }
};

template <typename PIX, typename FC>
void boxMipGen(GLenum targ, GLint fmt, GLint type, GLint level, size_t w, size_t h, const PIX* input) {
    size_t nw = w / 2;
    size_t nh = h / 2;

    if (nw == 0 || nh == 0) {
        return;
    }

    PIX* output = new PIX[nw * nh];
    for (size_t y = 0; y < nh; y++) {
        for (size_t x = 0; x < nw; x++) {
            FC::calculate(input, output, w, nw, x, y);
        }
    }

    glTexImage2D(targ, level, fmt, nw, nh, 0, fmt, type, output);
    GLint err = glGetError();
    if (err) {
        NSLog(@"Problem %d generating mip.", err);
    }

    boxMipGen<PIX, FC>(targ, fmt, type, level + 1, nw, nh, output);
    delete[] output;
}

void createMipmaps(GLenum targ, GLint fmt, GLint type, size_t w, size_t h, unsigned char* bytes) {
    if (fmt == GL_ALPHA) {
        const PixelByteChannel<1>* pix = (PixelByteChannel<1>*)bytes;
        boxMipGen<PixelByteChannel<1>, BoxGen<PixelByteChannel<1>>>(targ, fmt, type, 1, w, h, pix);
    } else if (fmt == GL_RGB) {
        if (type == GL_UNSIGNED_SHORT_5_6_5) {
            const PixelRGB16* pix = (PixelRGB16*)bytes;
            boxMipGen<PixelRGB16, BoxGen<PixelRGB16>>(targ, fmt, type, 1, w, h, pix);
        } else {
            const PixelByteChannel<3>* pix = (PixelByteChannel<3>*)bytes;
            boxMipGen<PixelByteChannel<3>, BoxGen<PixelByteChannel<3>>>(targ, fmt, type, 1, w, h, pix);
        }
    } else if (fmt == GL_RGBA) {
        const PixelByteChannel<4>* pix = (PixelByteChannel<4>*)bytes;
        boxMipGen<PixelByteChannel<4>, BoxGen<PixelByteChannel<4>>>(targ, fmt, type, 1, w, h, pix);
    }
}
}

@implementation GLKTextureInfo
- (id)initWith:(GLuint)tex target:(GLuint)targ width:(GLuint)width height:(GLuint)height alphaState:(GLKTextureInfoAlphaState)as {
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

+ (GLKTextureInfo*)textureWithContentsOfFile:(NSString*)fname options:(NSDictionary*)opts error:(NSError**)err {
    CGDataProviderRef provider = CGDataProviderCreateWithFilename([fname UTF8String]);
    CGImageRef img = CGImageCreateWithPNGDataProvider(provider, NULL, NO, kCGRenderingIntentDefault);

    GLKTextureInfo* res = [self textureWithCGImage:img options:opts error:err];

    CGImageRelease(img);
    CGDataProviderRelease(provider);

    return res;
}

+ (GLKTextureInfo*)textureWithContentsOfData:(NSData*)data options:(NSDictionary*)opts error:(NSError**)err {
    return nil;
}

+ (GLKTextureInfo*)textureWithCGImage:(CGImageRef)img options:(NSDictionary*)opts error:(NSError**)err {
    size_t w = CGImageGetWidth(img);
    size_t h = CGImageGetHeight(img);
    size_t bpp = CGImageGetBitsPerPixel(img);
    size_t rowSize = CGImageGetBytesPerRow(img);
    size_t expectedRowSize = (bpp / 8) * w;
    if (rowSize != expectedRowSize) {
        NSLog(@"WARNING - Image (%dx%d) - expected row size %d, got row size %d\n", w, h, expectedRowSize, rowSize);
    }

    CGDataProviderRef provider = CGImageGetDataProvider(img);
    NSData* data = (id)CGDataProviderCopyData(provider);
    [data autorelease];
    auto bytesIn = (unsigned char*)[data bytes];

    if (getOpt(opts, GLKTextureLoaderOriginBottomLeft)) {
        swapRows(bytesIn, rowSize, h);
    }

    GLuint tex;
    glGenTextures(1, &tex);

    bool genMips = getOpt(opts, GLKTextureLoaderGenerateMipmaps);

    glBindTexture(GL_TEXTURE_2D, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (!genMips) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    }

    GLint fmt, type;
    GLKTextureInfoAlphaState as;
    if (!getBitmapFormat(fmt, type, as, bpp)) {
        CGDataProviderRelease(provider);
        return nil;
    }

    if (bpp == 32 && getOpt(opts, GLKTextureLoaderApplyPremultiplication)) {
        size_t pixelCount = w * h;

        PixelByteChannel<4>* pixels = (PixelByteChannel<4>*)bytesIn;
        for (size_t i = 0; i < pixelCount; i++) {
            float alpha = pixels[i].template getCh<3>();
            float vals[3] = { pixels[i].template getCh<0>() * alpha,
                              pixels[i].template getCh<1>() * alpha,
                              pixels[i].template getCh<2>() * alpha };
            pixels[i].template setChan<3>(vals);
        }
    }

    auto bytes = bytesIn;
    bool deleteBytes = false;
    if (getOpt(opts, GLKTextureLoaderGrayscaleAsAlpha) && fmt != GL_ALPHA) {
        deleteBytes = true;
        int pixels = w * h;
        bytes = new unsigned char[pixels];
        if (bpp == 16) {
            GreyscaleConvert<PixelRGB16>((PixelByteChannel<1>*)bytes, (PixelRGB16*)bytesIn, pixels);
        } else if (bpp == 24) {
            GreyscaleConvert<PixelByteChannel<3>>((PixelByteChannel<1>*)bytes, (PixelByteChannel<3>*)bytesIn, pixels);
        } else if (bpp == 32) {
            GreyscaleConvert<PixelByteChannel<4>>((PixelByteChannel<1>*)bytes, (PixelByteChannel<4>*)bytesIn, pixels);
        }

        bpp = 8;
        fmt = GL_ALPHA;
        type = GL_UNSIGNED_BYTE;
    }

    NSLog(@"Creating %dx%d texture, %d bpp, fmt 0x%x type 0x%x.", w, h, bpp, fmt, type);

    glTexImage2D(GL_TEXTURE_2D, 0, fmt, w, h, 0, fmt, type, bytes);
    GLint i = glGetError();
    if (i != 0) {
        NSLog(@"Error %d creating texture.", i);
    }

    if (genMips) {
        createMipmaps(GL_TEXTURE_2D, fmt, type, w, h, bytes);
    }

    if (deleteBytes) {
        delete[] bytes;
    }
    CGDataProviderRelease(provider);

    return [[GLKTextureInfo alloc] initWith:tex target:GL_TEXTURE_2D width:w height:h alphaState:as];
}

+ (GLKTextureInfo*)cubeMapWithContentsOfFile:(NSString*)fname options:(NSDictionary*)opts error:(NSError**)err {
    CGDataProviderRef provider = CGDataProviderCreateWithFilename([fname UTF8String]);
    if (!provider) {
        return nil;
    }
    CGImageRef img = CGImageCreateWithPNGDataProvider(provider, NULL, NO, kCGRenderingIntentDefault);
    if (!img) {
        CGDataProviderRelease(provider);
        return nil;
    }

    size_t w = CGImageGetWidth(img);
    size_t h = CGImageGetHeight(img);
    size_t bpp = CGImageGetBitsPerPixel(img);
    size_t rowSize = CGImageGetBytesPerRow(img);
    size_t expectedRowSize = (bpp / 8) * w;
    if (rowSize != expectedRowSize) {
        NSLog(@"WARNING - Image (%dx%d) - expected row size %d, got row size %d\n", w, h, expectedRowSize, rowSize);
    }

    if (h != 6 * w) {
        NSLog(@"ERROR - Unexpected cube map format, expected 6 square textures aligned vertically.");
        CGImageRelease(img);
        CGDataProviderRelease(provider);
        return nil;
    }

    CGDataProviderRelease(provider);
    provider = CGImageGetDataProvider(img);
    NSData* data = (id)CGDataProviderCopyData(provider);
    [data autorelease];
    auto bytesIn = (unsigned char*)[data bytes];

    if (getOpt(opts, GLKTextureLoaderOriginBottomLeft)) {
        swapRows(bytesIn, rowSize, h);
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

    bool genMips = getOpt(opts, GLKTextureLoaderGenerateMipmaps);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (!genMips) {
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    } else {
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    GLint fmt, type;
    GLKTextureInfoAlphaState as;
    if (!getBitmapFormat(fmt, type, as, bpp)) {
        CGImageRelease(img);
        CGDataProviderRelease(provider);
        return nil;
    }

    if (bpp == 32 && getOpt(opts, GLKTextureLoaderApplyPremultiplication)) {
        size_t pixelCount = w * h;

        PixelByteChannel<4>* pixels = (PixelByteChannel<4>*)bytesIn;
        for (size_t i = 0; i < pixelCount; i++) {
            float alpha = pixels[i].template getCh<3>();
            float vals[3] = { pixels[i].template getCh<0>() * alpha,
                              pixels[i].template getCh<1>() * alpha,
                              pixels[i].template getCh<2>() * alpha };
            pixels[i].template setChan<3>(vals);
        }
    }

    auto bytes = bytesIn;
    bool deleteBytes = false;
    if (getOpt(opts, GLKTextureLoaderGrayscaleAsAlpha) && fmt != GL_ALPHA) {
        deleteBytes = true;
        int pixels = w * h;
        bytes = new unsigned char[pixels];
        if (bpp == 16) {
            GreyscaleConvert<PixelRGB16>((PixelByteChannel<1>*)bytes, (PixelRGB16*)bytesIn, pixels);
        } else if (bpp == 24) {
            GreyscaleConvert<PixelByteChannel<3>>((PixelByteChannel<1>*)bytes, (PixelByteChannel<3>*)bytesIn, pixels);
        } else if (bpp == 32) {
            GreyscaleConvert<PixelByteChannel<4>>((PixelByteChannel<1>*)bytes, (PixelByteChannel<4>*)bytesIn, pixels);
        }

        bpp = 8;
        fmt = GL_ALPHA;
        type = GL_UNSIGNED_BYTE;
        bpp = 1;
    }

    NSLog(@"Creating %dx%d cube map texture, %d bpp, fmt 0x%x type 0x%x.", w, h, bpp, fmt, type);

    size_t sideh = h / 6;
    for (int i = 0; i < 6; i++) {
        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, fmt, w, sideh, 0, fmt, type, bytes);
        GLint err = glGetError();
        if (err != 0) {
            NSLog(@"Error %d creating cube face %d.", err, i);
        }

        if (genMips) {
            createMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, fmt, type, w, h, bytes);
        }

        bytes += rowSize * sideh;
    }

    if (deleteBytes) {
        delete[] bytes;
    }
    CGImageRelease(img);
    CGDataProviderRelease(provider);
    return [[GLKTextureInfo alloc] initWith:tex target:GL_TEXTURE_2D width:w height:sideh alphaState:as];
}

+ (GLKTextureInfo*)cubeMapWithContentsOfFiles:(NSArray*)fnames options:(NSDictionary*)opts error:(NSError**)err {
    if ([fnames count] != 6) {
        return nil;
    }

    GLuint tex;
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_CUBE_MAP, tex);

    bool genMips = getOpt(opts, GLKTextureLoaderGenerateMipmaps);

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    if (!genMips) {
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    } else {
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    }
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    bool fmtInited = false;
    size_t sideW = 0, sideH = 0, imgBpp = 0, imgRowSize = 0;
    size_t curSide = 0;

    GLKTextureInfoAlphaState as;
    for (NSString* fn in fnames) {
        CGDataProviderRef provider = CGDataProviderCreateWithFilename([fn UTF8String]);
        if (!provider) {
            NSLog(@"Unable to open cube side texture %@", fn);
            curSide++;
            continue;
        }
        CGImageRef img = CGImageCreateWithPNGDataProvider(provider, NULL, NO, kCGRenderingIntentDefault);
        if (!img) {
            CGDataProviderRelease(provider);
            NSLog(@"Unable to create image from cube side texture %@", fn);
            curSide++;
            continue;
        }

        CGDataProviderRelease(provider);
        provider = CGImageGetDataProvider(img);
        NSData* data = (id)CGDataProviderCopyData(provider);
        [data autorelease];
        auto bytesIn = (unsigned char*)[data bytes];

        size_t w = CGImageGetWidth(img);
        size_t h = CGImageGetHeight(img);
        size_t bpp = CGImageGetBitsPerPixel(img);
        size_t rowSize = CGImageGetBytesPerRow(img);
        size_t expectedRowSize = (bpp / 8) * w;
        if (w != h || rowSize != expectedRowSize) {
            NSLog(@"WARNING - Image %@ (%dx%d) - is in an invalid format.", fn, w, h);
            curSide++;
            CGDataProviderRelease(provider);
            CGImageRelease(img);
            continue;
        }

        if (getOpt(opts, GLKTextureLoaderOriginBottomLeft)) {
            swapRows(bytesIn, rowSize, h);
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
                curSide++;
                CGDataProviderRelease(provider);
                CGImageRelease(img);
                continue;
            }
        }

        GLint fmt, type;
        if (!getBitmapFormat(fmt, type, as, bpp)) {
            CGDataProviderRelease(provider);
            CGImageRelease(img);
            return nil;
        }

        if (bpp == 32 && getOpt(opts, GLKTextureLoaderApplyPremultiplication)) {
            size_t pixelCount = w * h;

            PixelByteChannel<4>* pixels = (PixelByteChannel<4>*)bytesIn;
            for (size_t i = 0; i < pixelCount; i++) {
                float alpha = pixels[i].template getCh<3>();
                float vals[3] = { pixels[i].template getCh<0>() * alpha,
                                  pixels[i].template getCh<1>() * alpha,
                                  pixels[i].template getCh<2>() * alpha };
                pixels[i].template setChan<3>(vals);
            }
        }

        auto bytes = bytesIn;
        bool deleteBytes = false;
        if (getOpt(opts, GLKTextureLoaderGrayscaleAsAlpha) && fmt != GL_ALPHA) {
            deleteBytes = true;
            int pixels = w * h;
            bytes = new unsigned char[pixels];
            if (bpp == 16) {
                GreyscaleConvert<PixelRGB16>((PixelByteChannel<1>*)bytes, (PixelRGB16*)bytesIn, pixels);
            } else if (bpp == 24) {
                GreyscaleConvert<PixelByteChannel<3>>((PixelByteChannel<1>*)bytes, (PixelByteChannel<3>*)bytesIn, pixels);
            } else if (bpp == 32) {
                GreyscaleConvert<PixelByteChannel<4>>((PixelByteChannel<1>*)bytes, (PixelByteChannel<4>*)bytesIn, pixels);
            }

            bpp = 8;
            fmt = GL_ALPHA;
            type = GL_UNSIGNED_BYTE;
        }

        glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + curSide, 0, fmt, w, h, 0, fmt, type, bytes);
        GLint err = glGetError();
        if (err != 0) {
            NSLog(@"Error %d creating cube face %d.", err, curSide);
        }

        if (genMips) {
            createMipmaps(GL_TEXTURE_CUBE_MAP_POSITIVE_X + curSide, fmt, type, w, h, bytes);
        }

        if (deleteBytes) {
            delete[] bytes;
        }
        CGDataProviderRelease(provider);
        CGImageRelease(img);
        curSide++;
    }
    if (!fmtInited) {
        NSLog(@"Unable to create cube map.");
        return nil;
    }

    return [[GLKTextureInfo alloc] initWith:tex target:GL_TEXTURE_CUBE_MAP width:sideW height:sideH alphaState:as];
}

- (id)initWithShareContext:(NSOpenGLContext*)context {
    return self;
}

@end
