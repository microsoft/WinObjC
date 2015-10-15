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

#include <math.h>
#include <stdlib.h>
#include "Starboard.h"
#include "CGContextInternal.h"
#include "UIKit/UIImage.h"

#define EXTERN(type) extern type

extern "C" {
#include <jpeglib.h>
};

CGJPEGDecoderImage::CGJPEGDecoderImage(const char* filename) {
    _img = new CGJPEGImageBacking(filename);
    _img->_parent = this;
    _imgType = CGImageTypeJPEG;
}

CGJPEGDecoderImage::CGJPEGDecoderImage(id data) {
    _img = new CGJPEGImageBacking(data);
    _img->_parent = this;
    _imgType = CGImageTypeJPEG;
}

void CGJPEGImageBacking::DiscardIfPossible() {
    //  Can only discard images that can be reloaded from disk
    if (!_fileName) {
        return;
    }
    EbrDebugLog("Discarding %s\n", _fileName);
    CGDiscardableImageBacking::DiscardIfPossible();
}

struct my_error_mgr {
    struct jpeg_error_mgr pub; /* "public" fields */

    jmp_buf setjmp_buffer; /* for return to caller */
};

typedef struct my_error_mgr* my_error_ptr;

/*
* Here's the routine that will replace the standard error_exit method:
*/
static void jpegerrmgr_output(j_common_ptr cinfo) {
    char buf[JMSG_LENGTH_MAX];
    cinfo->err->format_message(cinfo, buf);
    EbrDebugLog("JPEG error: %s\n", buf);
}

METHODDEF(void)
my_error_exit(j_common_ptr cinfo) {
    /* cinfo->err really points to a my_error_mgr struct, so coerce pointer */
    my_error_ptr myerr = (my_error_ptr)cinfo->err;

    /* Always display the message. */
    /* We could postpone this until after returning, if we chose. */
    (*cinfo->err->output_message)(cinfo);

    /* Return control to the setjmp point */
    longjmp(myerr->setjmp_buffer, 1);
}

METHODDEF(void)
init_source(j_decompress_ptr cinfo) {
}

METHODDEF(void)
term_source(j_decompress_ptr cinfo) {
    /* no work necessary here */
}

METHODDEF(void)
jpeg_progress(j_common_ptr info) {
    /* no work necessary here */
}

static WORD readWord(const char*& curPos, int& left, BOOL bigEndian) {
    if (left < 2)
        return 0;
    WORD ret = 0;
    memcpy(&ret, curPos, 2);
    curPos += 2;
    left -= 2;

    if (bigEndian) {
        ret = (ret >> 8) | ((ret & 0xFF) << 8);
    }

    return ret;
}

static DWORD readDWord(const char*& curPos, int& left, BOOL bigEndian) {
    if (left < 4)
        return 0;
    DWORD ret = 0;
    memcpy(&ret, curPos, 4);
    curPos += 4;
    left -= 4;

    if (bigEndian) {
        ret = ((ret & 0xFF000000) >> 24) | ((ret & 0x00FF0000) >> 8) | ((ret & 0x0000FF00) << 8) | ((ret & 0x000000FF) << 24);
    }

    return ret;
}

static int jpeg_find_orientation(j_decompress_ptr cinfo) {
    jpeg_saved_marker_ptr curMarker = cinfo->marker_list;
    while (curMarker) {
        if (curMarker->marker == 0xE1) {
            const char start[] = "Exif\0\0";

            if (memcmp(curMarker->data, start, 6) == 0) {
                break;
            }
        }
        curMarker = curMarker->next;
    }

    if (!curMarker)
        return 0;

    //   Find TIFF header
    DWORD tiffHeader = 0x002A4949;
    DWORD tiffHeaderBE = 0x2A004D4D;
    BOOL bigEndian = FALSE;
    BOOL found = FALSE;

    DWORD curWord;
    const char* curPos = (const char*)curMarker->data;
    int left = curMarker->data_length;

    while (left >= 4) {
        memcpy(&curWord, curPos, sizeof(DWORD));

        if (curWord == tiffHeader) {
            curPos += 4;
            left -= 4;
            found = TRUE;
            break;
        }
        if (curWord == tiffHeaderBE) {
            curPos += 4;
            left -= 4;
            found = TRUE;
            bigEndian = TRUE;
            break;
        }

        curPos += 1;
        left -= 1;
    }

    if (!found)
        return 0;

    //  Find offset and tag count
    WORD offset = readWord(curPos, left, bigEndian);
    offset -= 8;
    if (offset > left)
        return 0;

    curPos += offset;
    left -= offset;

    WORD tagCount = readWord(curPos, left, bigEndian);
    if (tagCount == 0)
        return 0;

    while (tagCount && left > 0) {
        WORD id = readWord(curPos, left, bigEndian);
        WORD fmt = readWord(curPos, left, bigEndian);
        DWORD count = readDWord(curPos, left, bigEndian);
        WORD dataLo = readWord(curPos, left, bigEndian);
        WORD dataHi = readWord(curPos, left, bigEndian);

        if (id == 0x112) {
            if (count != 1 || fmt != 3)
                return 0;

            //  Found orientation tag
            return dataLo;
        }

        tagCount--;
    }

    return 0;
}

#define INPUT_BUFFER_SIZE 4096

class JPEGReader {
public:
    BYTE inputBuffer[INPUT_BUFFER_SIZE];
    ImageDataStream* reader;
    bool eof;

    JPEGReader() {
        reader = NULL;
        eof = false;
    }
};

METHODDEF(boolean)
fill_input_buffer(j_decompress_ptr cinfo) {
    struct jpeg_source_mgr* src = cinfo->src;
    JPEGReader* jpegData = (JPEGReader*)cinfo->client_data;

    if (!jpegData->eof) {
        int toRead = INPUT_BUFFER_SIZE;

        int read = jpegData->reader->readData(jpegData->inputBuffer, toRead);

        if (read <= 0) {
            jpegData->eof = true;
        } else {
            src->next_input_byte = jpegData->inputBuffer;
            src->bytes_in_buffer = read;
        }
    }

    if (jpegData->eof) {
        static JOCTET FakeEOI[] = { 0xFF, JPEG_EOI };

        /* Insert a fake EOI marker */
        src->next_input_byte = FakeEOI;
        src->bytes_in_buffer = 2;
    }

    return TRUE;
}

METHODDEF(void)
skip_input_data(j_decompress_ptr cinfo, long num_bytes) {
    struct jpeg_source_mgr* src = cinfo->src;

    while (num_bytes > 0) {
        if (src->bytes_in_buffer == 0) {
            JPEGReader* jpegData = (JPEGReader*)cinfo->client_data;
            if (jpegData->eof)
                return;

            fill_input_buffer(cinfo);
        }
        int toSkip = int(src->bytes_in_buffer) > num_bytes ? num_bytes : int(src->bytes_in_buffer);

        src->bytes_in_buffer -= toSkip;
        src->next_input_byte += toSkip;
        num_bytes -= toSkip;
    }
}

CGImageBacking* CGJPEGImageBacking::ConstructBacking() {
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

void CGJPEGImageBacking::Decode(void* imgDest, int stride) {
    EbrFile* fpIn;

    ImageDataStream* reader;

    if (_fileName) {
        fpIn = EbrFopen(_fileName, "rb");
        if (!fpIn) {
            assert(0);
            return;
        }

        reader = new ImageDataStreamFile(fpIn);
    } else {
        reader = new ImageDataStreamMemory((char*)[_data bytes], [_data length]);
    }

    struct jpeg_decompress_struct cinfo;
    struct my_error_mgr jerr;

    int row_stride;

    jpeg_create_decompress(&cinfo);

    cinfo.err = jpeg_std_error(&jerr.pub);
    jerr.pub.error_exit = my_error_exit;
    jerr.pub.output_message = jpegerrmgr_output;

    if (setjmp(jerr.setjmp_buffer)) {
        jpeg_destroy_decompress(&cinfo);
        return;
    }

    struct jpeg_source_mgr* src;

    if (cinfo.src == NULL) {
        cinfo.src =
            (struct jpeg_source_mgr*)(*cinfo.mem->alloc_small)((j_common_ptr)&cinfo, JPOOL_PERMANENT, sizeof(struct jpeg_source_mgr));
    }

    if (cinfo.progress == NULL) {
        cinfo.progress =
            (struct jpeg_progress_mgr*)(*cinfo.mem->alloc_small)((j_common_ptr)&cinfo, JPOOL_PERMANENT, sizeof(struct jpeg_progress_mgr));
        /* static callback function in JpegDecoder */
        cinfo.progress->progress_monitor = jpeg_progress;
    }

    JPEGReader jpegReader;
    jpegReader.reader = reader;
    cinfo.client_data = (void*)&jpegReader;

    src = cinfo.src;

    /* Set up function pointers */
    src->init_source = init_source;
    src->fill_input_buffer = fill_input_buffer;
    src->skip_input_data = skip_input_data;
    src->resync_to_restart = jpeg_resync_to_restart; /* use default method */
    src->term_source = term_source;

    /* Set up data pointer */
    src->bytes_in_buffer = 0;
    src->next_input_byte = (JOCTET*)jpegReader.inputBuffer;

    /* Step 3: read file parameters with jpeg_read_header() */
    jpeg_save_markers(&cinfo, 0xE1, 0xffff);
    (void)jpeg_read_header(&cinfo, TRUE);
/* We can ignore the return value from jpeg_read_header since
*   (a) suspension is not possible with the stdio data source, and
*   (b) we passed TRUE to reject a tables-only JPEG file as an error.
* See libjpeg.doc for more info.
*/

/* Step 4: set parameters for decompression */

/* In this example, we don't need to change any of the defaults set by
* jpeg_read_header(), so we do nothing here.
*/

/* Step 5: Start decompressor */
#ifdef ANDROID
    cinfo.out_color_space = JCS_EXT_RGBA;
    cinfo.dct_method = JDCT_FASTEST;
#endif

    int orientation = jpeg_find_orientation(&cinfo);
    switch (orientation) {
        case 0:
        case 1:
            _orientation = 0;
            break;

        case 3:
            _orientation = UIImageOrientationDown;
            break;
        case 6:
            _orientation = UIImageOrientationRight;
            break;
        case 8:
            _orientation = UIImageOrientationLeft;
            break;

        default:
            _orientation = -1;
            EbrDebugLog("Unknown JPEG orientation %d\n", orientation);
            break;
    }

    _cachedWidth = cinfo.image_width;
    _cachedHeight = cinfo.image_height;
#ifndef QNX
    _cachedSurfaceFormat = _ColorRGBA;
#else
    _cachedSurfaceFormat = _ColorARGB;
#endif
    _hasCachedInfo = true;

    if (imgDest) {
        (void)jpeg_start_decompress(&cinfo);
        /* We can ignore the return value since suspension is not possible
        * with the stdio data source.
        */

        /* We may need to do some setup of our own at this point before reading
        * the data.  After jpeg_start_decompress() we have the correct scaled
        * output image dimensions available, as well as the output colormap
        * if we asked for color quantization.
        * In this example, we need to make an output work buffer of the right size.
        */
        /* JSAMPLEs per row in output buffer */
        row_stride = cinfo.output_width * 4;

        //  Create our CGImage
        _parent->_has32BitAlpha = false;

        /* Allocate bitmap for our output */
        BYTE* imageData = (BYTE*)imgDest;

#ifndef ANDROID
        BYTE* scanline = (BYTE*)EbrCalloc(row_stride, 1);
#endif

        /* Step 6: while (scan lines remain to be read) */
        /*           jpeg_read_scanlines(...); */

        /* Here we use the library's state variable cinfo.output_scanline as the
        * loop counter, so that we don't have to keep track ourselves.
        */
        while (cinfo.output_scanline < cinfo.output_height) {
/* jpeg_read_scanlines expects an array of pointers to scanlines.
* Here the array is only one element long, but you could ask for
* more than one scanline at a time if that's more convenient.
*/

#ifdef ANDROID
            JSAMPROW curRow = (JSAMPROW)&imageData[cinfo.output_scanline * stride];
            (void)jpeg_read_scanlines(&cinfo, &curRow, 1);
#else
            JSAMPROW curRow = (JSAMPROW)scanline;
            int curScanline = cinfo.output_scanline;

            (void)jpeg_read_scanlines(&cinfo, &curRow, 1);

            int x = cinfo.output_width;

            if (cinfo.output_components == 3) {
                DWORD* outRow = (DWORD*)&imageData[curScanline * stride];
#ifndef QNX
                DWORD* inRow = (DWORD*)scanline;
#else
                BYTE* inRow = (BYTE*)scanline;
#endif

                //  Convert to 32-bit
                while (x--) {
#ifndef QNX
                    *outRow = *inRow | 0xFF000000;
                    inRow = (DWORD*)(((BYTE*)inRow) + 3);
#else
                    BYTE r = *(inRow);
                    BYTE g = *(inRow + 1);
                    BYTE b = *(inRow + 2);

                    *outRow = (b | (g << 8) | (r << 16)) | 0xFF000000;
                    inRow += 3;
#endif
                    outRow++;
                }
            } else {
                DWORD* outRow = (DWORD*)&imageData[curScanline * stride];
                BYTE* inRow = (BYTE*)scanline;

                //  Convert to 32-bit
                while (x--) {
                    DWORD inB = *inRow;
                    *outRow = 0xFF000000 | inB | (inB << 8) | (inB << 16);
                    inRow++;
                    outRow++;
                }
            }
#endif
        }

#ifndef ANDROID
        EbrFree(scanline);
#endif

        /* Step 7: Finish decompression */

        (void)jpeg_finish_decompress(&cinfo);
        /* We can ignore the return value since suspension is not possible
        * with the stdio data source.
        */
        _data = nil;
    }

    /* Step 8: Release JPEG decompression object */

    /* This is an important step since it will release a good deal of memory. */
    jpeg_destroy_decompress(&cinfo);

    delete reader;
}

bool CGJPEGImageBacking::DrawDirectlyToContext(CGContextImpl* ctx, CGRect src, CGRect dest) {
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

CGJPEGImageBacking::CGJPEGImageBacking(const char* filename) {
    _fileName = _strdup(filename);
    Decode(NULL, 0);
}

CGJPEGImageBacking::CGJPEGImageBacking(id data) {
    _data.attach([data copy]);
    _fileName = NULL;
    Decode(NULL, 0);
}

CGJPEGImageBacking::~CGJPEGImageBacking() {
    _data = nil;
    if (_fileName)
        free(_fileName);
}
