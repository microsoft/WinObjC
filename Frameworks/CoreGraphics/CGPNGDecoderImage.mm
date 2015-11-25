/* Derived from cairo-png.c
*
* Copyright © 2003 University of Southern California
*
* This library is free software; you can redistribute it and/or
* modify it either under the terms of the GNU Lesser General Public
* License version 2.1 as published by the Free Software Foundation
* (the "LGPL") or, at your option, under the terms of the Mozilla
* Public License Version 1.1 (the "MPL"). If you do not alter this
* notice, a recipient may use your version of this file under either
* the MPL or the LGPL.
*
* You should have received a copy of the LGPL along with this library
* in the file COPYING-LGPL-2.1; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA 02110-1335, USA
* You should have received a copy of the MPL along with this library
* in the file COPYING-MPL-1.1
*
* The contents of this file are subject to the Mozilla Public License
* Version 1.1 (the "License"); you may not use this file except in
* compliance with the License. You may obtain a copy of the License at
* http://www.mozilla.org/MPL/
*
* This software is distributed on an "AS IS" basis, WITHOUT WARRANTY
* OF ANY KIND, either express or implied. See the LGPL or the MPL for
* the specific language governing rights and limitations.
*
* The Original Code is the cairo graphics library.
*
* The Initial Developer of the Original Code is University of Southern
* California.
*
* Contributor(s):
*   Carl D. Worth <cworth@cworth.org>
*   Kristian Høgsberg <krh@redhat.com>
*   Chris Wilson <chris@chris-wilson.co.uk>
*/

#include <math.h>
#include <stdlib.h>
#include "CGContextInternal.h"

extern "C" {
#include <png.h>
};

CGPNGDecoderImage::CGPNGDecoderImage(const char* filename) {
    _img = new CGPNGImageBacking(filename);
    _img->_parent = this;
    _imgType = CGImageTypePNG;
}

CGPNGDecoderImage::CGPNGDecoderImage(id data) {
    _img = new CGPNGImageBacking(data);
    _img->_parent = this;
    _imgType = CGImageTypePNG;
}

static void PNG_read_data(png_structp png_ptr, png_bytep data, png_size_t length) {
    ImageDataStream* buf = (ImageDataStream*)png_get_io_ptr(png_ptr);

    int read = buf->readData(data, length);
    if (read < length) {
        memset(data + read, 0, length - read);
    }
}

static int PNG_unknown_chunk(png_structp png_ptr, png_unknown_chunkp chunk) {
    if (memcmp(chunk->name, "CgBI", 4) == 0) {
        int* flag = (int*)png_get_user_chunk_ptr(png_ptr);
        ;
        *flag = 1;

        png_cgbi_decode(png_ptr);
        /* flip the RGB pixels to BGR (or RGBA to BGRA) */
        png_set_bgr(png_ptr);

        return 1;
    }

    return 0;
}

static void PNG_error(png_structp png_ptr, png_const_charp str_err) {
    return;
}

static inline int multiply_alpha(int alpha, int color) {
    int temp = (alpha * color) + 0x80;
    return ((temp + (temp >> 8)) >> 8);
}

/* Premultiplies data and converts RGBA bytes => native endian */
static void premultiply_data(png_structp png, png_row_infop row_info, png_bytep data) {
    unsigned int i;
    int* cgbiFlag = (int*)png_get_user_chunk_ptr(png);
    uint8_t* base = (uint8_t*)data;
    CGImageRef pImage = (CGImageRef)png_get_user_transform_ptr(png);

    for (i = 0; i < row_info->rowbytes; i += 4) {
        uint8_t alpha = base[3];

        if (alpha == 0) {
            *((uint32_t*)base) = 0;
            if (pImage) {
                pImage->_has32BitAlpha = true;
            }
        } else {
            uint8_t red = base[0];
            uint8_t green = base[1];
            uint8_t blue = base[2];

            if (alpha != 0xff) {
                if (!*cgbiFlag) {
                    red = multiply_alpha(alpha, red);
                    green = multiply_alpha(alpha, green);
                    blue = multiply_alpha(alpha, blue);
                }
                if (pImage) {
                    pImage->_has32BitAlpha = true;
                }
            }

#ifndef QNX
            *((uint32_t*)base) = (alpha << 24) | (blue << 16) | (green << 8) | red;
#else
            *((uint32_t*)base) = (alpha << 24) | (red << 16) | (green << 8) | blue;
#endif
        }

        base += 4;
    }
}

/* Converts RGBx bytes to native endian xRGB */
static void convert_bytes_to_data(png_structp png, png_row_infop row_info, png_bytep data) {
    unsigned int i;
    uint8_t* base = (uint8_t*)data;

    for (i = 0; i < row_info->rowbytes; i += 4) {
        uint8_t red = base[0];
        uint8_t green = base[1];
        uint8_t blue = base[2];

#ifndef QNX
        *((uint32_t*)base) = (0xff << 24) | (blue << 16) | (green << 8) | red;
#else
        *((uint32_t*)base) = (0xff << 24) | (red << 16) | (green << 8) | blue;
#endif
        base += 4;
    }
}

void CGPNGImageBacking::DiscardIfPossible() {
    //  Can only discard images that can be reloaded from disk
    if (!_fileName) {
        return;
    }
    if (_forward) {
        EbrDebugLog("Discarding %s\n", _fileName);
    }
    CGDiscardableImageBacking::DiscardIfPossible();
}

CGImageBacking* CGPNGImageBacking::ConstructBacking() {
    EbrDebugLog("Delay-loading image %s\n", _fileName ? _fileName : "NIL");
    if (!_hasCachedInfo) {
        Decode(NULL, 0);
    }

    CGImageBacking* retBacking = NULL;

    if (_hasCachedInfo) {
        /* Allocate bitmap for our output */
        CGGraphicBufferImage* newImage;
        newImage = new CGGraphicBufferImage(_cachedWidth, _cachedHeight, _cachedSurfaceFormat);
        retBacking = newImage->DetachBacking(_parent);
        CGImageRelease(newImage);

        BYTE* imageData = (BYTE*)retBacking->LockImageData();
        int stride = retBacking->BytesPerRow();

        Decode(imageData, stride);
        retBacking->ReleaseImageData();
    }

    return retBacking;
}

void CGPNGImageBacking::Decode(void* imgDest, int stride) {
    EbrFile* fpIn;

    ImageDataStream* reader;

    if (_fileName) {
        fpIn = EbrFopen(_fileName, "rb");
        if (!fpIn) {
            assert(0);
        }

        reader = new ImageDataStreamFile(fpIn);
    } else {
        reader = new ImageDataStreamMemory((char*)[(NSData*)_data bytes], [(NSData*)_data length]);
    }

    png_struct* png = NULL;
    png_info* info;
    png_byte* data = NULL;
    png_uint_32 png_width, png_height;
    int depth, color_type, interlace;
    unsigned int i;
    int errorCode = 0;
    int isCGBI = 0;

    out = NULL;
    row_pointers = NULL;

    png = png_create_read_struct_2(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL, NULL, NULL, NULL);
    if (png == NULL) {
        EbrDebugLog("PNG load Error\n");
        errorCode = 1;
        goto error;
    }

    info = png_create_info_struct(png);
    if (info == NULL) {
        EbrDebugLog("PNG load Error\n");
        errorCode = 1;
        goto error;
    }

    png_set_read_fn(png, reader, PNG_read_data);
    png_set_read_user_chunk_fn(png, &isCGBI, PNG_unknown_chunk);

#ifdef PNG_SETJMP_SUPPORTED
    if (setjmp(png_jmpbuf(png))) {
        EbrDebugLog("PNG load Error\n");
        errorCode = 1;
        goto error;
    }
#endif

    png_read_info(png, info);

    png_get_IHDR(png, info, &png_width, &png_height, &depth, &color_type, &interlace, NULL, NULL);
    _cachedWidth = png_width;
    _cachedHeight = png_height;
    if (color_type == PNG_COLOR_TYPE_GRAY) {
        _cachedSurfaceFormat = _ColorGrayscale;
    } else {
#ifndef QNX
        _cachedSurfaceFormat = _ColorRGBA;
#else
        _cachedSurfaceFormat = _ColorARGB;
#endif
    }
    _hasCachedInfo = true;

    if (imgDest) {
        /* convert palette/gray image to rgb */
        if (color_type == PNG_COLOR_TYPE_PALETTE) {
            png_set_palette_to_rgb(png);
        }

        /* expand gray bit depth if needed */
        if (color_type == PNG_COLOR_TYPE_GRAY) {
            png_set_expand_gray_1_2_4_to_8(png);
        }

        /* transform transparency to alpha */
        if (color_type != PNG_COLOR_TYPE_GRAY && color_type != PNG_COLOR_TYPE_GRAY_ALPHA) {
            if (png_get_valid(png, info, PNG_INFO_tRNS)) {
                png_set_tRNS_to_alpha(png);
            }
        } else {
            //  Expand grayscale with alpha to RGBA
            if (color_type == PNG_COLOR_TYPE_GRAY_ALPHA) {
                png_set_gray_to_rgb(png);
                color_type = PNG_COLOR_TYPE_RGB_ALPHA;
            }
        }

        if (depth == 16) {
            png_set_strip_16(png);
        }

        if (depth < 8) {
            png_set_packing(png);
        }

        if (interlace != PNG_INTERLACE_NONE) {
            png_set_interlace_handling(png);
        }

        if (color_type != PNG_COLOR_TYPE_GRAY) {
            png_set_filler(png, 0xff, PNG_FILLER_AFTER);
        }
        png_set_user_transform_info(png, _parent, 0, 0);

        /* recheck header after setting EXPAND options */
        png_read_update_info(png, info);
        png_get_IHDR(png, info, &png_width, &png_height, &depth, &color_type, &interlace, NULL, NULL);
        if (depth != 8 ||
            !(color_type == PNG_COLOR_TYPE_RGB || color_type == PNG_COLOR_TYPE_RGB_ALPHA || color_type == PNG_COLOR_TYPE_GRAY ||
              color_type == PNG_COLOR_TYPE_GRAY_ALPHA)) {
            EbrDebugLog("PNG load Error\n");
            errorCode = 1;
            goto error;
        }

        switch (color_type) {
            case PNG_COLOR_TYPE_RGB_ALPHA:
                png_set_read_user_transform_fn(png, premultiply_data);
                break;

            case PNG_COLOR_TYPE_RGB:
                png_set_read_user_transform_fn(png, convert_bytes_to_data);
                break;
        }

        _parent->_has32BitAlpha = false;

        out = (BYTE*)imgDest;

        row_pointers = (BYTE**)EbrMalloc(png_height * sizeof(char*));

        for (i = 0; i < png_height; i++) {
            row_pointers[i] = (BYTE*)&out[i * stride];
        }

        png_read_image(png, (png_byte**)row_pointers);
        out = NULL;
        png_read_end(png, info);
        _data = nil;
    }

error:
    if (errorCode) {
        int curRow = png_get_current_row_number(png);
        if (curRow == 0) {
            if (row_pointers != NULL) {
                EbrFree(row_pointers);
            }
            if (png != NULL) {
                png_destroy_read_struct(&png, &info, NULL);
            }
            row_pointers = NULL;
            png = NULL;

            EbrDebugLog("Fatal error loading PNG\n");
        } else {
            EbrDebugLog("Warning: Broken PNG\n");
            //  Clear remaining rows
            for (int i = curRow; i < png_height; i++) {
                memset(row_pointers[i], 0, stride);
            }
        }
    }

    if (row_pointers != NULL) {
        EbrFree(row_pointers);
    }
    if (png != NULL) {
        png_destroy_read_struct(&png, &info, NULL);
    }
    delete reader;
}

bool CGPNGImageBacking::DrawDirectlyToContext(CGContextImpl* ctx, CGRect src, CGRect dest) {
    CGImageRef destImage = ctx->DestImage();

    if (_forward != NULL) {
        return false;
    }
    if (_fileName == NULL && _data == nil) {
        return false;
    }
    if (destImage->Backing()->SurfaceFormat() != _cachedSurfaceFormat) {
        return false;
    }
    if (src.origin.x != 0.0f || src.origin.y != 0.0f || src.size.width != _cachedWidth || src.size.height != _cachedHeight ||
        src.origin != dest.origin || !CGSizeEqualToSize(src.size, dest.size)) {
        return false;
    }
    if (destImage->Backing()->Width() != _cachedWidth || destImage->Backing()->Height() != _cachedHeight) {
        return false;
    }
    CGAffineTransform curTransform = ctx->CGContextGetCTM();
    if (memcmp(&curTransform, &CGAffineTransformIdentity, sizeof(CGAffineTransform)) != 0) {
        return false;
    }

    void* pDest = destImage->Backing()->LockImageData();
    int stride = destImage->Backing()->BytesPerRow();
    Decode(pDest, stride);

    return true;
}

CGPNGImageBacking::CGPNGImageBacking(const char* filename) {
    size_t fileNameSize = strlen(filename) + 1;
    _fileName = (char*)malloc(fileNameSize);
    strcpy_s(_fileName, fileNameSize, filename);
    Decode(NULL, 0);
}

CGPNGImageBacking::CGPNGImageBacking(id data) {
    _data.attach([data copy]);
    _fileName = NULL;
    Decode(NULL, 0);
}

CGPNGImageBacking::~CGPNGImageBacking() {
    _data = nil;
    if (_fileName) {
        free(_fileName);
    }
}
