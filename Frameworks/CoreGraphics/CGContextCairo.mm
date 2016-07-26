//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <CoreGraphics/CGGeometry.h>
#import <Starboard.h>
#import <memory>

#import "CGColorSpaceInternal.h"
#import "CGContextCairo.h"
#import "CGContextImpl.h"
#import "CGFontInternal.h"
#import "CGGradientInternal.h"
#import "CGImageInternal.h"
#import "CGPathInternal.h"
#import "CGPatternInternal.h"
#import "UIColorInternal.h"
#import "CGSurfaceInfoInternal.h"

#define CAIRO_WIN32_STATIC_BUILD

#import "cairo-ft.h"

extern "C" {
#import <ft2build.h>
#import FT_FREETYPE_H
#import <ftadvanc.h>
#import <ftglyph.h>
#import <ftsizes.h>
#import <tttables.h>
}

#include "LoggingNative.h"

static const wchar_t* TAG = L"CGContextCairo";

static IWLazyClassLookup _LazyUIFont("UIFont");
static IWLazyIvarLookup<float> _LazyUIFontHorizontalScale(_LazyUIFont, "_horizontalScale");
static IWLazyIvarLookup<void*> _LazyUIFontHandle(_LazyUIFont, "_font");
static IWLazyIvarLookup<void*> _LazyUISizingFontHandle(_LazyUIFont, "_sizingFont");

CGContextCairo::CGContextCairo(CGContextRef base, CGImageRef destinationImage)
    : CGContextImpl(base, destinationImage), _drawContext(0), _filter(CAIRO_FILTER_BILINEAR) {
}

CGContextCairo::~CGContextCairo() {
    ReleaseLock();
}

void CGContextCairo::ObtainLock() {
    if (_drawContext != NULL)
        return;

    LOCK_CAIRO();
    _drawContext = cairo_create(_imgDest->Backing()->LockCairoSurface());
    UNLOCK_CAIRO();
    // cairo_set_antialias(_drawContext, CAIRO_ANTIALIAS_NONE);
}

void CGContextCairo::ReleaseLock() {
    if (_drawContext) {
        LOCK_CAIRO();
        cairo_destroy(_drawContext);
        UNLOCK_CAIRO();
        _imgDest->Backing()->ReleaseCairoSurface();
        _drawContext = NULL;
    }
}

void CGContextCairo::_assignAndResetFilter(cairo_pattern_t* pattern) {
    cairo_pattern_set_filter(pattern, _filter);
    _filter = CAIRO_FILTER_BILINEAR;
}

// This function quotes an open source function from Github.
// An OSS request has been submitted. The link for the request is:
// https://osstool.microsoft.com/palamida/RequestDetails.htm?rid=40072&projectId=1
void CGContextCairo::_cairoImageSurfaceBlur(cairo_surface_t* surface) {
    double blur = curState->shadowBlur;

    if (surface == NULL || blur <= 0) {
        return;
    }

    int width = cairo_image_surface_get_width(surface);
    int height = cairo_image_surface_get_height(surface);
    std::unique_ptr<unsigned char[]> dstPtr = std::make_unique<unsigned char[]>(width * height * 4);
    std::unique_ptr<unsigned[]> precalPtr = std::make_unique<unsigned[]>(width * height);
    unsigned char* dst = dstPtr.get();
    unsigned* precalc = precalPtr.get();
    unsigned char* src = cairo_image_surface_get_data(surface);
    double mul = 1.f / ((blur * 2) * (blur * 2));
    int channel;

    // The number of times to perform the averaging. According to wikipedia,
    // three iterations is good enough to pass for a gaussian.
    const int MAX_ITERATIONS = 3;
    int iteration;

    memcpy(dst, src, width * height * 4);

    for (iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        for (channel = 0; channel < 4; channel++) {
            int x, y;

            // precomputation step.
            unsigned char* pix = src;
            unsigned* pre = precalc;

            pix += channel;
            for (y = 0; y < height; y++) {
                for (x = 0; x < width; x++) {
                    int tot = pix[0];
                    if (x > 0)
                        tot += pre[-1];
                    if (y > 0)
                        tot += pre[-width];
                    if (x > 0 && y > 0)
                        tot -= pre[-width - 1];
                    *pre++ = tot;
                    pix += 4;
                }
            }

            // blur step.
            pix = dst + (int)blur * width * 4 + (int)blur * 4 + channel;
            for (y = blur; y < height - blur; y++) {
                for (x = blur; x < width - blur; x++) {
                    int l = MAX(0, x - blur);
                    int t = MAX(0, y - blur);
                    int r = MIN(width - 1, x + blur);
                    int b = MIN(height - 1, y + blur);
                    int tot = precalc[r + b * width] + precalc[l + t * width] - precalc[l + b * width] - precalc[r + t * width];
                    *pix = (unsigned char)(tot * mul);
                    pix += 4;
                }
                pix += (int)blur * 2 * 4;
            }
        }
        memcpy(src, dst, width * height * 4);
    }
}

void CGContextCairo::_cairoContextStrokePathShadow() {
    int i;
    double width, height, deltaWidth, deltaHeight;

    cairo_save(_drawContext);

    // In order to calculate the shadow near the boundary of surface,
    // the width and height will be enlarged for delta_width and delta_height.
    if (curState->shadowOffset.width >= 0) {
        deltaWidth = curState->shadowOffset.width + 2 * curState->shadowBlur;
    } else {
        deltaWidth = (-1) * curState->shadowOffset.width + 2 * curState->shadowBlur;
    }

    if (curState->shadowOffset.height >= 0) {
        deltaHeight = curState->shadowOffset.height + 2 * curState->shadowBlur;
    } else {
        deltaHeight = (-1) * curState->shadowOffset.height + 2 * curState->shadowBlur;
    }

    cairo_path_t* originalPath = cairo_copy_path(_drawContext);
    cairo_path_t* path = cairo_copy_path(_drawContext);

    // Modify the path to adapt to the enlarged surface.
    for (i = 0; i < path->num_data; i += path->data[i].header.length) {
        cairo_path_data_t* data = &path->data[i];

        switch (data->header.type) {
            case CAIRO_PATH_MOVE_TO:
                data[1].point.x += deltaWidth;
                data[1].point.y += deltaHeight;
                break;
            case CAIRO_PATH_LINE_TO:
                data[1].point.x += deltaWidth;
                data[1].point.y += deltaHeight;
                break;
            case CAIRO_PATH_CURVE_TO:
                data[1].point.x += deltaWidth;
                data[1].point.y += deltaHeight;
                data[2].point.x += deltaWidth;
                data[2].point.y += deltaHeight;
                data[3].point.x += deltaWidth;
                data[3].point.y += deltaHeight;
                break;
            case CAIRO_PATH_CLOSE_PATH:
                break;
        }
    }

    cairo_surface_t* surface = cairo_get_group_target(_drawContext);
    width = cairo_image_surface_get_width(surface);
    height = cairo_image_surface_get_height(surface);

    // Enlarge the width and heigth of the image surface. Then draw the shadow on the surface.
    surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width + 2 * deltaWidth, height + 2 * deltaHeight);
    cairo_t* ctx = cairo_create(surface);

    cairo_append_path(ctx, path);

    NSUInteger componentsNum = CGColorGetNumberOfComponents(curState->shadowColor);
    const CGFloat* components = CGColorGetComponents(curState->shadowColor);
    if (componentsNum == 2) {
        cairo_set_source_rgba(ctx, components[0], components[0], components[0], components[1]);
    } else if (componentsNum == 4) {
        cairo_set_source_rgba(ctx, components[0], components[1], components[2], components[3]);
    }

    // Make the stroke style same as _drawContext
    cairo_set_line_width(ctx, cairo_get_line_width(_drawContext));
    cairo_set_line_cap(ctx, cairo_get_line_cap(_drawContext));
    cairo_set_line_join(ctx, cairo_get_line_join(_drawContext));
    cairo_set_miter_limit(ctx, cairo_get_miter_limit(_drawContext));

    int dashCount = cairo_get_dash_count(_drawContext);
    double offset;
    double* dash = (double*)IwMalloc(sizeof(double) * dashCount);
    cairo_get_dash(_drawContext, dash, &offset);
    cairo_set_dash(ctx, dash, dashCount, offset);
    IwFree(dash);

    cairo_stroke(ctx);

    // Blur the surface for shadow here
    _cairoImageSurfaceBlur(surface);

    cairo_destroy(ctx);
    cairo_new_path(_drawContext);

    // Select the right scope to surface_rect
    cairo_surface_t* surfaceRect = cairo_surface_create_for_rectangle(surface,
                                                                      deltaWidth - curState->shadowOffset.width,
                                                                      deltaHeight - curState->shadowOffset.height,
                                                                      width,
                                                                      height);

    cairo_pattern_t* shadowPattern = cairo_pattern_create_for_surface(surfaceRect);
    cairo_set_source(_drawContext, shadowPattern);
    cairo_rectangle(_drawContext, 0, 0, width, height);
    cairo_fill(_drawContext);

    cairo_pattern_destroy(shadowPattern);
    cairo_surface_destroy(surface);
    cairo_surface_destroy(surfaceRect);

    cairo_restore(_drawContext);
    cairo_new_path(_drawContext);
    cairo_append_path(_drawContext, originalPath);

    cairo_path_destroy(path);
    cairo_path_destroy(originalPath);
}

void CGContextCairo::Clear(float r, float g, float b, float a) {
    ObtainLock();

    CGRect rct;

    rct.origin.x = 0;
    rct.origin.y = 0;
    rct.size.width = float(_imgDest->Backing()->Width());
    rct.size.height = float(_imgDest->Backing()->Height());

    cairo_save(_drawContext);
    cairo_new_path(_drawContext);
    cairo_rectangle(_drawContext, rct.origin.x, rct.origin.y, rct.size.width, rct.size.height);

    cairo_set_source_rgba(_drawContext, r, g, b, a);
    cairo_fill(_drawContext);

    cairo_restore(_drawContext);
}

void CGContextCairo::DrawImage(CGImageRef img, CGRect src, CGRect dest, bool tiled) {
    ObtainLock();

    if (dest.size.width == 0.0f || dest.size.height == 0.0f)
        return;

    LOCK_CAIRO();
    _isDirty = true;

    if (!tiled && img->Backing()->DrawDirectlyToContext(this, src, dest)) {
        UNLOCK_CAIRO();
        return;
    }
    if (src.size.width == 1 && dest.size.height == 1) { /* [BUG: Cairo doesn't like 1x1 source images] */
        TraceInfo(TAG, L"1x1 source image");
        cairo_path_t* curPath = cairo_copy_path(_drawContext);
        cairo_save(_drawContext);

        cairo_matrix_t m;
        float trans[6];
        memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

        m.xx = trans[0];
        m.yx = trans[1];
        m.xy = trans[2];
        m.yy = trans[3];
        m.x0 = trans[4];
        m.y0 = trans[5];

        cairo_set_matrix(_drawContext, &m);
        cairo_translate(_drawContext, dest.origin.x, dest.origin.y);

        float r, g, b, a;
        img->Backing()->GetPixel(int(src.origin.x), int(src.origin.y), r, g, b, a);
        cairo_set_source_rgba(_drawContext, r, g, b, a);
        cairo_pattern_t* pattern = cairo_get_source(_drawContext);
        _assignAndResetFilter(pattern);
        cairo_new_path(_drawContext);
        cairo_rectangle(_drawContext, 0, 0, dest.size.width, dest.size.height);
        cairo_clip(_drawContext);
        cairo_paint_with_alpha(_drawContext, curState->curFillColor.a);

        cairo_restore(_drawContext);
        cairo_new_path(_drawContext);
        cairo_append_path(_drawContext, curPath);
        cairo_path_destroy(curPath);
    } else {
        cairo_path_t* curPath = cairo_copy_path(_drawContext);
        cairo_save(_drawContext);

        cairo_matrix_t srcMatrix;
        cairo_pattern_t* p = cairo_pattern_create_for_surface(img->Backing()->LockCairoSurface());
        _assignAndResetFilter(p);

        if (tiled) {
            cairo_pattern_set_extend(p, CAIRO_EXTEND_REPEAT);

            double x, y, x2, y2;

            //  Fill entire clip region
            cairo_clip_extents(_drawContext, &x, &y, &x2, &y2);
            dest.origin.x = float(x);
            dest.origin.y = float(y);
            dest.size.width = float(x2 - x);
            dest.size.height = float(y2 - y);
        } else {
            cairo_matrix_init(
                &srcMatrix, src.size.width / dest.size.width, 0, 0, src.size.height / dest.size.height, src.origin.x, src.origin.y);
            cairo_pattern_set_matrix(p, &srcMatrix);
        }

        cairo_matrix_t m = { 0 };
        float trans[6];
        memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

        m.xx = trans[0];
        m.yx = trans[1];
        m.xy = trans[2];
        m.yy = trans[3];
        m.x0 = trans[4];
        m.y0 = trans[5];

        cairo_set_matrix(_drawContext, &m);
        cairo_translate(_drawContext, dest.origin.x, dest.origin.y);
        cairo_set_source(_drawContext, p);
        cairo_new_path(_drawContext);
        cairo_rectangle(_drawContext, 0, 0, dest.size.width, dest.size.height);
        cairo_clip(_drawContext);

        if (curState->_imgMask == NULL) {
            cairo_paint_with_alpha(_drawContext, curState->curFillColor.a);
        } else {
            cairo_mask_surface(_drawContext, curState->_imgMask->Backing()->LockCairoSurface(), 0.0, 0.0);
            curState->_imgMask->Backing()->ReleaseCairoSurface();
        }

        cairo_pattern_destroy(p);

        cairo_restore(_drawContext);
        cairo_new_path(_drawContext);
        cairo_append_path(_drawContext, curPath);
        cairo_path_destroy(curPath);

        img->Backing()->ReleaseCairoSurface();
    }
    UNLOCK_CAIRO();
}

cairo_operator_t blendMapping[] = {
    CAIRO_OPERATOR_OVER, // kCGBlendModeNormal,
    CAIRO_OPERATOR_MULTIPLY, // kCGBlendModeMultiply,
    CAIRO_OPERATOR_SCREEN, // kCGBlendModeScreen,
    CAIRO_OPERATOR_OVERLAY, // kCGBlendModeOverlay,
    CAIRO_OPERATOR_DARKEN, // kCGBlendModeDarken,
    CAIRO_OPERATOR_DARKEN, // kCGBlendModeLighten,
    CAIRO_OPERATOR_COLOR_DODGE, // kCGBlendModeColorDodge,
    CAIRO_OPERATOR_COLOR_BURN, // kCGBlendModeColorBurn,
    CAIRO_OPERATOR_SOFT_LIGHT, // kCGBlendModeSoftLight,
    CAIRO_OPERATOR_HARD_LIGHT, // kCGBlendModeHardLight,
    CAIRO_OPERATOR_DIFFERENCE, // kCGBlendModeDifference,
    CAIRO_OPERATOR_EXCLUSION, // kCGBlendModeExclusion,
    CAIRO_OPERATOR_HSL_HUE, // kCGBlendModeHue,
    CAIRO_OPERATOR_HSL_SATURATION, // kCGBlendModeSaturation,
    CAIRO_OPERATOR_HSL_COLOR, // kCGBlendModeColor,
    CAIRO_OPERATOR_HSL_LUMINOSITY, // kCGBlendModeLuminosity,
    CAIRO_OPERATOR_CLEAR, // kCGBlendModeClear,
    CAIRO_OPERATOR_SOURCE, // kCGBlendModeCopy,
    CAIRO_OPERATOR_IN, // kCGBlendModeSourceIn,
    CAIRO_OPERATOR_OUT, // kCGBlendModeSourceOut,
    CAIRO_OPERATOR_ATOP, // kCGBlendModeSourceAtop,
    CAIRO_OPERATOR_DEST_OVER, // kCGBlendModeDestinationOver,
    CAIRO_OPERATOR_DEST_IN, // kCGBlendModeDestinationIn,
    CAIRO_OPERATOR_DEST_OUT, // kCGBlendModeDestinationOut,
    CAIRO_OPERATOR_DEST_ATOP, // kCGBlendModeDestinationAtop,
    CAIRO_OPERATOR_XOR, // kCGBlendModeXOR,
    CAIRO_OPERATOR_ADD, // kCGBlendModePlusDarker,   [BUG: Not implemented]
    CAIRO_OPERATOR_ADD // kCGBlendModePlusLighter,
};

void CGContextCairo::CGContextSetBlendMode(CGBlendMode mode) {
    ObtainLock();

    assert(mode < sizeof(blendMapping) / sizeof(cairo_operator_t));

    curState->curBlendMode = mode;
    LOCK_CAIRO();
    cairo_set_operator(_drawContext, blendMapping[mode]);
    UNLOCK_CAIRO();
}

CGBlendMode CGContextCairo::CGContextGetBlendMode() {
    return curState->curBlendMode;
}

void CGContextCairo::CGContextShowTextAtPoint(float x, float y, const char* str, DWORD length) {
    WORD* glyphs = (WORD*)IwMalloc(length * sizeof(WORD));
    DWORD i;

    _isDirty = true;

    for (i = 0; i < length; i++) {
        glyphs[i] = str[i];
    }

    CGFontGetGlyphs(curState->getCurFont(), glyphs, length, glyphs);
    CGContextShowGlyphsAtPoint(x, y, glyphs, length);

    IwFree(glyphs);
}

void CGContextCairo::CGContextShowGlyphsAtPoint(float x, float y, WORD* glyphs, int count) {
    CGSize size;

    _isDirty = true;

    switch (curState->textDrawingMode) {
        case kCGTextFill:
        case kCGTextStroke:
        case kCGTextFillStroke:
        case kCGTextFillClip:
        case kCGTextStrokeClip:
        case kCGTextFillStrokeClip:
            size = CGFontDrawGlyphsToContext(glyphs, count, x, y);
            break;

        case kCGTextClip:
        case kCGTextInvisible:
            CGFontMeasureGlyphs(curState->getCurFont(), curState->fontSize, glyphs, count, &size);
            break;
    }

    curState->curTextPosition.x = x + size.width;
    curState->curTextPosition.y = y;
}

void CGContextCairo::CGContextShowGlyphsWithAdvances(WORD* glyphs, CGSize* advances, int count) {
    CGPoint curPos = { curState->curTextPosition.x, curState->curTextPosition.y };
    _isDirty = true;

    for (int i = 0; i < count; i++) {
        CGFontDrawGlyphsToContext(&glyphs[i], 1, curPos.x, curPos.y);
        curPos.x += advances[i].width;
        curPos.y += advances[i].height;
    }
    curState->curTextPosition = curPos;
}

void CGContextCairo::CGContextShowGlyphs(WORD* glyphs, int count) {
    CGContextShowGlyphsAtPoint(curState->curTextPosition.x, curState->curTextPosition.y, glyphs, count);
}

void CGContextCairo::CGContextSetFont(id font) {
    curState->setCurFont(font);
}

void CGContextCairo::CGContextSetFontSize(float ptSize) {
    curState->fontSize = ptSize;
}

void CGContextCairo::CGContextSetTextMatrix(CGAffineTransform matrix) {
    curState->curTextMatrix = matrix;
}

void CGContextCairo::CGContextGetTextMatrix(CGAffineTransform* ret) {
    *ret = curState->curTextMatrix;
}

void CGContextCairo::CGContextSetTextPosition(float x, float y) {
    curState->curTextPosition.x = x;
    curState->curTextPosition.y = y;
}

void CGContextCairo::CGContextSetTextDrawingMode(CGTextDrawingMode mode) {
    curState->textDrawingMode = mode;
}

void CGContextCairo::CGContextTranslateCTM(float x, float y) {
    ObtainLock();

    curState->curTransform = CGAffineTransformTranslate(curState->curTransform, x, y);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    LOCK_CAIRO();
    cairo_set_matrix(_drawContext, &m);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextScaleCTM(float sx, float sy) {
    ObtainLock();

    curState->curTransform = CGAffineTransformScale(curState->curTransform, sx, sy);
    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    LOCK_CAIRO();
    cairo_set_matrix(_drawContext, &m);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextRotateCTM(float angle) {
    ObtainLock();

    curState->curTransform = CGAffineTransformRotate(curState->curTransform, angle);
    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    LOCK_CAIRO();
    cairo_set_matrix(_drawContext, &m);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextConcatCTM(CGAffineTransform t) {
    ObtainLock();

    // CGAffineTransformConcat(&curState->curTransform, curState->curTransform,
    // t);
    curState->curTransform = CGAffineTransformConcat(t, curState->curTransform);
    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    LOCK_CAIRO();
    cairo_set_matrix(_drawContext, &m);
    UNLOCK_CAIRO();
}

CGAffineTransform CGContextCairo::CGContextGetCTM() {
    return curState->curTransform;
}

void CGContextCairo::CGContextSetCTM(CGAffineTransform transform) {
    ObtainLock();

    curState->curTransform = transform;

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    LOCK_CAIRO();
    cairo_set_matrix(_drawContext, &m);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextDrawImage(CGRect rct, CGImageRef img) {
    if (img == NULL) {
        TraceWarning(TAG, L"Img == NULL!");
        return;
    }

    ObtainLock();
    _isDirty = true;

    CGRect src;

    src = rct;
    src.origin.x = 0;
    src.origin.y = 0;
    src.size.width = (float)img->Backing()->Width();
    src.size.height = (float)img->Backing()->Height();

    // rct.origin.y = (_imgDest->_height - rct.origin.y) - img->_height;

    DrawImage(img, src, rct);
}

void CGContextCairo::CGContextClipToMask(CGRect dest, CGImageRef img) {
    ObtainLock();

    if (curState->_imgMask != NULL) {
        delete curState->_imgMask;
        curState->_imgMask = NULL;
    }

    if (img->Backing()->SurfaceFormat() != _ColorGrayscale) {
        curState->_imgMask = img->Backing()->Copy();
    } else {
        __CGSurfaceInfo surfaceInfo = _CGSurfaceInfoInit(img->Backing()->Width(), img->Backing()->Height(), _ColorABGR);

        CGBitmapImage* pNewImage = new CGBitmapImage(surfaceInfo);

        BYTE* imgData = (BYTE*)img->Backing()->LockImageData();
        BYTE* newImgData = (BYTE*)pNewImage->Backing()->LockImageData();

        for (int y = 0; y < img->Backing()->Height(); y++) {
            BYTE* imageIn = ((BYTE*)imgData) + y * img->Backing()->BytesPerRow();
            BYTE* curScanline = ((BYTE*)newImgData) + y * pNewImage->Backing()->BytesPerRow();
            for (int x = 0; x < img->Backing()->Width(); x++) {
                *curScanline++ = 0;
                *curScanline++ = 0;
                *curScanline++ = 0;
                *curScanline++ = *imageIn++;
            }
        }

        img->Backing()->ReleaseImageData();
        pNewImage->Backing()->ReleaseImageData();

        curState->_imgMask = pNewImage;
    }
}

void CGContextCairo::CGContextSetGrayFillColor(float gray, float alpha) {
    curState->curFillColor.r = gray;
    curState->curFillColor.g = gray;
    curState->curFillColor.b = gray;
    curState->curFillColor.a = alpha;
}

void CGContextCairo::CGContextSetStrokeColor(float* components) {
    curState->curStrokeColor.r = components[0];
    curState->curStrokeColor.g = components[1];
    curState->curStrokeColor.b = components[2];
    curState->curStrokeColor.a = components[3];
}

void CGContextCairo::CGContextSetStrokeColorWithColor(id color) {
    if (color) {
        curState->curStrokeColor = *[(UIColor*)color _getColors];
    } else {
        _ClearColorQuad(curState->curStrokeColor);
    }
}

void CGContextCairo::CGContextSetFillColorWithColor(id color) {
    if ((int)[(UIColor*)color _type] == solidBrush) {
        if (color) {
            curState->curFillColor = *[(UIColor*)color _getColors];
        } else {
            _ClearColorQuad(curState->curFillColor);
        }
        curState->curFillColorObject = nil;
    } else {
        curState->curFillColorObject = [color retain];
    }
}

void CGContextCairo::CGContextSetFillColor(float* components) {
    curState->curFillColor.r = components[0];
    curState->curFillColor.g = components[1];
    curState->curFillColor.b = components[2];
    curState->curFillColor.a = components[3];
}

void CGContextCairo::CGContextSelectFont(char* name, float size, DWORD encoding) {
    // curState->curFont = [UIFont class]("fontWithName:size:", @name, size);
    curState->fontSize = size;
}

void CGContextCairo::CGContextGetTextPosition(CGPoint* pos) {
    pos->x = curState->curTextPosition.x;
    pos->y = curState->curTextPosition.y;
}

void CGContextCairo::CGContextSaveGState() {
    ObtainLock();

    curStateNum++;
    assert(curStateNum < MAX_CG_STATES);

    LOCK_CAIRO();
    cairo_save(_drawContext);
    UNLOCK_CAIRO();

    states[curStateNum].curFillColorObject = curState->curFillColorObject;
    states[curStateNum].curFillColor = curState->curFillColor;
    states[curStateNum].curStrokeColor = curState->curStrokeColor;
    states[curStateNum].curTextColor = curState->curTextColor;
    states[curStateNum].curPenColor = curState->curPenColor;
    states[curStateNum].curForegroundColor = curState->curForegroundColor;
    states[curStateNum].setCurFont(curState->getCurFont());
    states[curStateNum].fontSize = curState->fontSize;
    states[curStateNum].textDrawingMode = curState->textDrawingMode;
    states[curStateNum].curTextMatrix = curState->curTextMatrix;
    states[curStateNum].curTextPosition = curState->curTextPosition;
    states[curStateNum].curBlendMode = curState->curBlendMode;
    states[curStateNum]._imgClip = NULL;
    states[curStateNum]._imgMask = NULL;
    states[curStateNum].shadowColor = NULL;

    if (curState->_imgClip) {
        states[curStateNum]._imgClip = curState->_imgClip->Backing()->Copy();
    }

    if (curState->_imgMask) {
        states[curStateNum]._imgMask = curState->_imgMask->Backing()->Copy();
    }

    if (curState->shadowColor) {
        states[curStateNum].shadowColor = CGColorCreateCopy(curState->shadowColor);
    }

    memcpy(&states[curStateNum].curTransform, &curState->curTransform, sizeof(curState->curTransform));

    curState = &states[curStateNum];
}

void CGContextCairo::CGContextRestoreGState() {
    ObtainLock();

    if (curStateNum == 0) {
        TraceWarning(TAG, L"CGContextRestoreGState: no state to restore!");
        return;
    }

    if (curState->_imgClip) {
        delete curState->_imgClip;
    }

    if (curState->_imgMask) {
        delete curState->_imgMask;
    }

    if (curState->shadowColor) {
        CGColorRelease(curState->shadowColor);
    }

    curStateNum--;
    curState = &states[curStateNum];

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    LOCK_CAIRO();
    cairo_restore(_drawContext);
    cairo_set_matrix(_drawContext, &m);
    cairo_set_operator(_drawContext, blendMapping[curState->curBlendMode]);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextClearRect(CGRect rct) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);
    cairo_new_path(_drawContext);
    cairo_rectangle(_drawContext, rct.origin.x, rct.origin.y, rct.size.width, rct.size.height);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    cairo_set_source_rgba(_drawContext, 1, 1, 1, 1);
    cairo_operator_t oldOp = cairo_get_operator(_drawContext);
    cairo_set_operator(_drawContext, CAIRO_OPERATOR_CLEAR);
    cairo_fill(_drawContext);
    cairo_set_operator(_drawContext, oldOp);

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextFillRect(CGRect rct) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);
    cairo_new_path(_drawContext);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    cairo_rectangle(_drawContext, rct.origin.x, rct.origin.y, rct.size.width, rct.size.height);

    setFillColorSource();

    if (curState->_imgMask == NULL) {
        cairo_fill(_drawContext);
#if defined(__i386__)
        // There's a missing call to _mm_empty in cairo somewhere, this will clear out the state so the FPU doesn't return bogus results.
        __builtin_ia32_emms();
#endif
    } else {
        cairo_mask_surface(_drawContext, curState->_imgMask->Backing()->LockCairoSurface(), 0.0, 0.0);
        curState->_imgMask->Backing()->ReleaseCairoSurface();
    }

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextClosePath() {
    ObtainLock();

    LOCK_CAIRO();
    cairo_close_path(_drawContext);
    cairo_new_sub_path(_drawContext);

    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextAddRect(CGRect rct) {
    ObtainLock();

    LOCK_CAIRO();
    cairo_rectangle(_drawContext, rct.origin.x, rct.origin.y, rct.size.width, rct.size.height);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextAddLineToPoint(float x, float y) {
    ObtainLock();

    LOCK_CAIRO();
    cairo_line_to(_drawContext, x, y);
    UNLOCK_CAIRO();

    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextCairo::CGContextAddCurveToPoint(float cp1x, float cp1y, float cp2x, float cp2y, float x, float y) {
    ObtainLock();

    LOCK_CAIRO();
    cairo_curve_to(_drawContext, cp1x, cp1y, cp2x, cp2y, x, y);
    UNLOCK_CAIRO();

    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextCairo::CGContextAddQuadCurveToPoint(float cpx, float cpy, float x, float y) {
    ObtainLock();

    CGPoint curr = curPathPosition;

    CGContextAddCurveToPoint((curr.x / 3.f) + (2 * cpx / 3),
                             (curr.y / 3) + (2 * cpy / 3),
                             (2.f * cpx / 3.f) + (x / 3.f),
                             (2 * cpy / 3) + (y / 3),
                             x,
                             y);

    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextCairo::CGContextMoveToPoint(float x, float y) {
    ObtainLock();

    LOCK_CAIRO();
    cairo_move_to(_drawContext, x, y);
    UNLOCK_CAIRO();

    curPathPosition.x = x;
    curPathPosition.y = y;
}

void CGContextCairo::CGContextAddArc(float x, float y, float radius, float startAngle, float endAngle, int clockwise) {
    ObtainLock();

    CGContextAddLineToPoint(x + radius * cos(startAngle), y + radius * sin(startAngle));
    LOCK_CAIRO();
    if (clockwise) {
        cairo_arc_negative(_drawContext, x, y, radius, startAngle, endAngle);
    } else {
        cairo_arc(_drawContext, x, y, radius, startAngle, endAngle);
    }
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextAddArcToPoint(float x1, float y1, float x2, float y2, float radius) {
    ObtainLock();

    float x0, y0;
    float dx0, dy0, dx2, dy2, xl0, xl2;
    float san, n0x, n0y, n2x, n2y, t;

    x0 = curPathPosition.x;
    y0 = curPathPosition.y;

    dx0 = x0 - x1;
    dy0 = y0 - y1;
    xl0 = sqrt(dx0 * dx0 + dy0 * dy0);
    if (xl0 == 0)
        return;

    dx2 = x2 - x1;
    dy2 = y2 - y1;
    xl2 = sqrt(dx2 * dx2 + dy2 * dy2);

    san = dx2 * dy0 - dx0 * dy2;
    if (san == 0) {
        CGContextAddLineToPoint(x1, y1);
        return;
    }

    if (san < 0) {
        n0x = -dy0 / xl0;
        n0y = dx0 / xl0;
        n2x = dy2 / xl2;
        n2y = -dx2 / xl2;
    } else {
        n0x = dy0 / xl0;
        n0y = -dx0 / xl0;
        n2x = -dy2 / xl2;
        n2y = dx2 / xl2;
    }
    t = (dx2 * n2y - dx2 * n0y - dy2 * n2x + dy2 * n0x) / san;
    CGContextAddArc(x1 + radius * (t * dx0 + n0x), y1 + radius * (t * dy0 + n0y), radius, atan2f(-n0y, -n0x), atan2(-n2y, -n2x), (san < 0));
}

void CGContextCairo::CGContextAddEllipseInRect(CGRect rct) {
    ObtainLock();

    LOCK_CAIRO();
    cairo_save(_drawContext);
    cairo_translate(_drawContext, rct.origin.x + rct.size.width / 2.0f, rct.origin.y + rct.size.height / 2.0f);
    cairo_scale(_drawContext, rct.size.width / 2.0f, rct.size.height / 2.0f);
    cairo_arc(_drawContext, 0., 0., 1., 0., 2 * kPi);
    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::setFillColorSource() {
    if (curState->curFillColorObject == 0) {
        cairo_set_source_rgba(_drawContext,
                              curState->curFillColor.r,
                              curState->curFillColor.g,
                              curState->curFillColor.b,
                              curState->curFillColor.a);
    } else {
        // TODO: Patterns are supposed to take "isColored" into account by either
        // replacing/multiplying
        //       the alpha channel or filling the with the colour using the pattern
        //       as a mask.
        // TODO: Refactor UIColor. Image and pattern are the same concept, and
        // BrushType is superfluous.
        CGImageRef pattern = (CGImageRef)[curState->curFillColorObject getPatternImage];
        CGAffineTransform patTrans = CGAffineTransformIdentity;
        if ([curState->curFillColorObject isKindOfClass:[CGPattern class]]) {
            patTrans = [(CGPattern*)curState->curFillColorObject getPatternTransform];
        }

        cairo_pattern_t* p = cairo_pattern_create_for_surface(pattern->Backing()->LockCairoSurface());
        cairo_pattern_set_extend(p, CAIRO_EXTEND_REPEAT);

        cairo_matrix_t m = { 0 };
        float trans[6];
        memcpy(trans, &patTrans, sizeof(patTrans));

        m.xx = trans[0];
        m.yx = trans[1];
        m.xy = trans[2];
        m.yy = trans[3];
        m.x0 = trans[4];
        m.y0 = trans[5];

        cairo_pattern_set_matrix(p, &m);

        cairo_set_source(_drawContext, p);
        cairo_pattern_destroy(p);

        pattern->Backing()->ReleaseCairoSurface();
        CGImageRelease(pattern);
    }
}

void CGContextCairo::CGContextStrokeEllipseInRect(CGRect rct) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);

    cairo_new_path(_drawContext);

    cairo_translate(_drawContext, rct.origin.x + rct.size.width / 2.0f, rct.origin.y + rct.size.height / 2.0f);
    cairo_scale(_drawContext, rct.size.width / 2.0f, rct.size.height / 2.0f);
    cairo_arc(_drawContext, 0., 0., 1., 0., 2 * kPi);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    setFillColorSource();
    cairo_stroke(_drawContext);

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextFillEllipseInRect(CGRect rct) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);

    cairo_new_path(_drawContext);

    cairo_translate(_drawContext, rct.origin.x + rct.size.width / 2.0f, rct.origin.y + rct.size.height / 2.0f);
    cairo_scale(_drawContext, rct.size.width / 2.0f, rct.size.height / 2.0f);
    cairo_arc(_drawContext, 0.f, 0.f, 1.f, 0.f, 2 * kPi);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    setFillColorSource();
    cairo_fill(_drawContext);

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextAddPath(CGPathRef path) {
    ObtainLock();

    _CGPathApplyPath(path, _rootContext);
}

void CGContextCairo::CGContextStrokePath() {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);
    if (curState->shadowColor != NULL) {
        _cairoContextStrokePathShadow();
    }

    cairo_set_source_rgba(_drawContext,
                          curState->curStrokeColor.r,
                          curState->curStrokeColor.g,
                          curState->curStrokeColor.b,
                          curState->curStrokeColor.a);

    // cairo_set_operator(_drawContext, CAIRO_OPERATOR_SCREEN);
    cairo_stroke(_drawContext);
    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextStrokeRect(CGRect rct) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);
    cairo_new_path(_drawContext);
    cairo_rectangle(_drawContext, rct.origin.x, rct.origin.y, rct.size.width, rct.size.height);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    cairo_set_source_rgba(_drawContext,
                          curState->curStrokeColor.r,
                          curState->curStrokeColor.g,
                          curState->curStrokeColor.b,
                          curState->curStrokeColor.a);
    cairo_stroke(_drawContext);

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextStrokeRectWithWidth(CGRect rct, float width) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);
    cairo_new_path(_drawContext);
    cairo_set_line_width(_drawContext, width);
    cairo_rectangle(_drawContext, rct.origin.x, rct.origin.y, rct.size.width, rct.size.height);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    setFillColorSource();
    cairo_stroke(_drawContext);

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextFillPath() {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    setFillColorSource();
    cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_WINDING);
    cairo_fill_preserve(_drawContext);

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextEOFillPath() {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    setFillColorSource();
    cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_EVEN_ODD);
    cairo_fill_preserve(_drawContext);

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextEOClip() {
    ObtainLock();

    TraceWarning(TAG, L"CGContextEOClip not supported");
    LOCK_CAIRO();
    cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_EVEN_ODD);
    cairo_clip(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextDrawPath(CGPathDrawingMode mode) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_save(_drawContext);

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);
    setFillColorSource();

    switch (mode) {
        case kCGPathFill:
            cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_WINDING);
            cairo_fill(_drawContext);
            break;

        case kCGPathEOFill:
            cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_EVEN_ODD);
            cairo_fill(_drawContext);
            break;

        case kCGPathFillStroke:
            cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_WINDING);
            cairo_fill_preserve(_drawContext);

            cairo_set_source_rgba(_drawContext,
                                  curState->curStrokeColor.r,
                                  curState->curStrokeColor.g,
                                  curState->curStrokeColor.b,
                                  curState->curStrokeColor.a);
            cairo_stroke(_drawContext);
            break;

        case kCGPathEOFillStroke:
            cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_EVEN_ODD);
            cairo_fill_preserve(_drawContext);

            cairo_set_source_rgba(_drawContext,
                                  curState->curStrokeColor.r,
                                  curState->curStrokeColor.g,
                                  curState->curStrokeColor.b,
                                  curState->curStrokeColor.a);
            cairo_stroke(_drawContext);
            break;

        case kCGPathStroke:
            cairo_set_source_rgba(_drawContext,
                                  curState->curStrokeColor.r,
                                  curState->curStrokeColor.g,
                                  curState->curStrokeColor.b,
                                  curState->curStrokeColor.a);
            cairo_stroke(_drawContext);
            break;

        default:
            assert(0);
    }

    cairo_restore(_drawContext);
    UNLOCK_CAIRO();
}

BOOL CGContextCairo::CGContextIsPathEmpty() {
    ObtainLock();

    double x1, y1, x2, y2;

    LOCK_CAIRO();
    cairo_path_extents(_drawContext, &x1, &y1, &x2, &y2);
    UNLOCK_CAIRO();

    if (x1 == 0.0 && y1 == 0.0 && x2 == 0.0 && y2 == 0.0) {
        return TRUE;
    }

    return FALSE;
}

void CGContextCairo::CGContextBeginPath() {
    ObtainLock();

    LOCK_CAIRO();
    cairo_new_path(_drawContext);
    UNLOCK_CAIRO();
    curPathPosition.x = 0;
    curPathPosition.y = 0;
}

void CGContextCairo::CGContextDrawLinearGradient(CGGradientRef gradient, CGPoint startPoint, CGPoint endPoint, DWORD options) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_pattern_t* pattern = cairo_pattern_create_linear(startPoint.x, startPoint.y, endPoint.x, endPoint.y);
    _assignAndResetFilter(pattern);

    switch (gradient->_format) {
        case _ColorABGR:
            for (unsigned i = 0; i < gradient->_count; i++) {
                float* curColor = &gradient->_components[i * 4];
                cairo_pattern_add_color_stop_rgba(pattern, gradient->_locations[i], curColor[0], curColor[1], curColor[2], curColor[3]);
            }
            break;

        case _ColorGrayscale:
            for (unsigned i = 0; i < gradient->_count; i++) {
                float* curColor = &gradient->_components[i * 2];
                cairo_pattern_add_color_stop_rgba(pattern, gradient->_locations[i], curColor[0], curColor[0], curColor[0], curColor[1]);
            }
            break;

        default:
            assert(0);
            break;
    }

    cairo_set_source(_drawContext, pattern);
    if (curState->_imgMask != NULL) {
        cairo_mask_surface(_drawContext, curState->_imgMask->Backing()->LockCairoSurface(), 0.0, 0.0);
        curState->_imgMask->Backing()->ReleaseCairoSurface();
    } else {
        cairo_paint_with_alpha(_drawContext, curState->curFillColor.a);
    }
    cairo_pattern_destroy(pattern);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextDrawRadialGradient(
    CGGradientRef gradient, CGPoint startCenter, float startRadius, CGPoint endCenter, float endRadius, DWORD options) {
    ObtainLock();

    _isDirty = true;

    LOCK_CAIRO();
    cairo_pattern_t* pattern = cairo_pattern_create_radial(startCenter.x, startCenter.y, startRadius, endCenter.x, endCenter.y, endRadius);
    _assignAndResetFilter(pattern);

    switch (gradient->_format) {
        case _ColorABGR:
            for (unsigned i = 0; i < gradient->_count; i++) {
                float* curColor = &gradient->_components[i * 4];
                cairo_pattern_add_color_stop_rgba(pattern, gradient->_locations[i], curColor[0], curColor[1], curColor[2], curColor[3]);
            }
            break;

        case _ColorGrayscale:
            for (unsigned i = 0; i < gradient->_count; i++) {
                float* curColor = &gradient->_components[i * 2];
                cairo_pattern_add_color_stop_rgba(pattern, gradient->_locations[i], curColor[0], curColor[0], curColor[0], curColor[1]);
            }
            break;

        default:
            assert(0);
            break;
    }

    cairo_set_source(_drawContext, pattern);
    if (curState->_imgMask != NULL) {
        cairo_mask_surface(_drawContext, curState->_imgMask->Backing()->LockCairoSurface(), 0.0, 0.0);
        curState->_imgMask->Backing()->ReleaseCairoSurface();
    } else {
        cairo_paint_with_alpha(_drawContext, curState->curFillColor.a);
    }
    cairo_pattern_destroy(pattern);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextDrawLayerInRect(CGRect destRect, CGLayerRef layer) {
#if 0
ObtainLock();

_isDirty = true;

CGRect src;

src.origin.x = 0;
src.origin.y = 0;
src.size.width = (float) layer->_layerBacking->Backing()->Width();
src.size.height = (float) layer->_layerBacking->Backing()->Height();

DrawImage(layer->_layerBacking, src, destRect);
#endif
}

void CGContextCairo::CGContextDrawLayerAtPoint(CGPoint destPoint, CGLayerRef layer) {
#if 0
ObtainLock();

_isDirty = true;

CGRect src, destRect;

src.origin.x = 0;
src.origin.y = 0;
src.size.width = (float) layer->_layerBacking->Backing()->Width();
src.size.height = (float) layer->_layerBacking->Backing()->Height();

destRect.origin = destPoint;
destRect.size.width = (float) layer->_layerBacking->Backing()->Width();
destRect.size.height = (float) layer->_layerBacking->Backing()->Height();

DrawImage(layer->_layerBacking, src, destRect);
#endif
}

CGInterpolationQuality CGContextCairo::CGContextGetInterpolationQuality() {
    CGInterpolationQuality quality = kCGInterpolationDefault;

    // Convert cairo_filter_t to CGInterpolationQuality
    switch (_filter) {
        case CAIRO_FILTER_NEAREST:
            quality = kCGInterpolationNone;
            break;

        case CAIRO_FILTER_FAST:
            quality = kCGInterpolationLow;
            break;

        case CAIRO_FILTER_GOOD:
            quality = kCGInterpolationMedium;
            break;

        case CAIRO_FILTER_BEST:
            quality = kCGInterpolationHigh;
            break;

        case CAIRO_FILTER_BILINEAR:
            quality = kCGInterpolationDefault;
            break;

        default:
            // Apple framework allows invalid values to be set for interpolation quality.
            // We are emulating this behavior so _filter could be having a value
            // which is beyond the enums defined for cairo_filter_t,
            // nevertheless we still return this value as CGInterpolationQuality.
            quality = static_cast<CGInterpolationQuality>(_filter);
    }

    return quality;
}

void CGContextCairo::CGContextSetInterpolationQuality(CGInterpolationQuality quality) {
    // Convert CGInterpolationQuality to cairo_filter_t
    switch (quality) {
        case kCGInterpolationNone:
            _filter = CAIRO_FILTER_NEAREST;
            break;

        case kCGInterpolationLow:
            _filter = CAIRO_FILTER_FAST;
            break;

        case kCGInterpolationMedium:
            _filter = CAIRO_FILTER_GOOD;
            break;

        case kCGInterpolationHigh:
            _filter = CAIRO_FILTER_BEST;
            break;

        case kCGInterpolationDefault:
            _filter = CAIRO_FILTER_BILINEAR;
            break;

        default:
            // Apple framework allows invalid values to be set for interpolation quality.
            // We are emulating this behavior so quality could be having a value
            // which is beyond the enums defined for CGInterpolationQuality,
            // nevertheless we still store and use this value as cairo_filter_t.
            _filter = static_cast<cairo_filter_t>(quality);
    }
}

void CGContextCairo::CGContextSetLineDash(float phase, float* lengths, DWORD count) {
    ObtainLock();

    double* dLengths = (double*)IwMalloc(count * sizeof(double));
    for (unsigned i = 0; i < count; i++)
        dLengths[i] = lengths[i];

    LOCK_CAIRO();
    cairo_set_dash(_drawContext, dLengths, count, phase);
    UNLOCK_CAIRO();

    IwFree(dLengths);
}

void CGContextCairo::CGContextSetMiterLimit(float limit) {
    ObtainLock();

    LOCK_CAIRO();
    cairo_set_miter_limit(_drawContext, limit);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextSetLineJoin(DWORD lineJoin) {
    ObtainLock();

    LOCK_CAIRO();
    cairo_set_line_join(_drawContext, (cairo_line_join_t)lineJoin);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextSetLineCap(DWORD lineCap) {
    ObtainLock();

    curState->lineCap = lineCap;
    LOCK_CAIRO();
    cairo_set_line_cap(_drawContext, (cairo_line_cap_t)curState->lineCap);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextSetLineWidth(float width) {
    ObtainLock();

    curState->lineWidth = width;
    LOCK_CAIRO();
    cairo_set_line_width(_drawContext, curState->lineWidth);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextSetShouldAntialias(DWORD shouldAntialias) {
    ObtainLock();

    LOCK_CAIRO();
    if (shouldAntialias) {
        cairo_set_antialias(_drawContext, CAIRO_ANTIALIAS_DEFAULT);
    } else {
        cairo_set_antialias(_drawContext, CAIRO_ANTIALIAS_NONE);
    }
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextClip() {
    ObtainLock();

    LOCK_CAIRO();
    cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_WINDING);
    cairo_clip(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextGetClipBoundingBox(CGRect* ret) {
    ObtainLock();

    double x, y, x2, y2;

    LOCK_CAIRO();
    cairo_clip_extents(_drawContext, &x, &y, &x2, &y2);
    UNLOCK_CAIRO();
    ret->origin.x = float(x);
    ret->origin.y = float(y);
    ret->size.width = float(x2 - x);
    ret->size.height = float(y2 - y);
}

void CGContextCairo::CGContextGetPathBoundingBox(CGRect* ret) {
    ObtainLock();

    double x, y, x2, y2;

    LOCK_CAIRO();
    cairo_path_extents(_drawContext, &x, &y, &x2, &y2);
    UNLOCK_CAIRO();
    ret->origin.x = float(x);
    ret->origin.y = float(y);
    ret->size.width = float(x2 - x);
    ret->size.height = float(y2 - y);
}

void CGContextCairo::CGContextClipToRect(CGRect rect) {
    ObtainLock();
    LOCK_CAIRO();
    cairo_path_t* oldPath = cairo_copy_path(_drawContext);
    cairo_new_path(_drawContext);
    cairo_rectangle(_drawContext, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height);
    cairo_clip(_drawContext);

    cairo_new_path(_drawContext);
    cairo_append_path(_drawContext, oldPath);
    cairo_path_destroy(oldPath);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextBeginTransparencyLayer(id auxInfo) {
    ObtainLock();
    LOCK_CAIRO();
    cairo_save(_drawContext);
    CGContextSaveGState();
    // Set defaults for new group/layer
    CGContextSetAlpha(1.0);
    CGContextSetShadowWithColor(CGSizeMake(0, 0), 0, NULL);
    CGContextSetBlendMode(kCGBlendModeNormal);
    // Create group
    cairo_push_group(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextBeginTransparencyLayerWithRect(CGRect rect, id auxInfo) {
    ObtainLock();
    LOCK_CAIRO();
    cairo_save(_drawContext);
    // Add rect and clip with it
    cairo_new_path(_drawContext);
    CGContextAddRect(rect);
    cairo_clip(_drawContext);
    CGContextSaveGState();
    // Set defaults for new group/layer
    CGContextSetAlpha(1.0);
    CGContextSetShadowWithColor(CGSizeMake(0, 0), 0, NULL);
    CGContextSetBlendMode(kCGBlendModeNormal);
    // Create group
    cairo_push_group(_drawContext);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextEndTransparencyLayer() {
    ObtainLock();
    LOCK_CAIRO();
    // Retrieve the group as a pattern
    cairo_pattern_t* group = cairo_pop_group(_drawContext);
    // Restore the CG state before the group was created
    CGContextRestoreGState();
    // Set the transform matrix
    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));
    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];
    cairo_set_matrix(_drawContext, &m);
    // Draw the group
    cairo_set_source(_drawContext, group);
    cairo_paint_with_alpha(_drawContext, curState->curFillColor.a);
    cairo_restore(_drawContext);
    cairo_pattern_destroy(group);
    UNLOCK_CAIRO();
}

void CGContextCairo::CGContextSetGrayStrokeColor(float gray, float alpha) {
    curState->curStrokeColor.r = gray;
    curState->curStrokeColor.g = gray;
    curState->curStrokeColor.b = gray;
    curState->curStrokeColor.a = alpha;
}

void CGContextCairo::CGContextSetAlpha(float a) {
    curState->curFillColor.a = a;
}

void CGContextCairo::CGContextSetRGBFillColor(float r, float g, float b, float a) {
    curState->curFillColor.r = r;
    curState->curFillColor.g = g;
    curState->curFillColor.b = b;
    curState->curFillColor.a = a;
}

void CGContextCairo::CGContextSetRGBStrokeColor(float r, float g, float b, float a) {
    curState->curStrokeColor.r = r;
    curState->curStrokeColor.g = g;
    curState->curStrokeColor.b = b;
    curState->curStrokeColor.a = a;
}

CGSize CGContextCairo::CGFontDrawGlyphsToContext(WORD* glyphs, DWORD length, float x, float y) {
    ObtainLock();

    LOCK_CAIRO();

    CGSize ret = { 0.0f, 0.0f };

    cairo_glyph_t* cairoGlyphs = (cairo_glyph_t*)IwMalloc(sizeof(cairo_glyph_t) * length);

    _CGFontLock();

    //  Get the font
    FT_Face face = (FT_Face)_LazyUISizingFontHandle.member(curState->getCurFont());
    if (!face) {
        _CGFontUnlock();
        UNLOCK_CAIRO();
        return ret;
    }
    FT_Error error;
    FT_GlyphSlot slot = face->glyph;

    FT_Pos penX = 0;
    FT_Pos penY = 0;

    UIFont* uiFont = curState->getCurFont();
    CGFontSetFTFontSize(curState->getCurFont(), face, curState->fontSize);

    CGPoint curOff = { 0, 0 };

    //  Lookup each glyph
    for (unsigned i = 0; i < length; i++) {
        error = FT_Load_Glyph(face, glyphs[i], FT_LOAD_NO_HINTING);
        if (error != 0) {
            cairoGlyphs[i].index = -1;
            curOff.x = (((float)penX) / 64.0f);
        } else {
            cairoGlyphs[i].index = glyphs[i];
            curOff.x = (((float)penX) / 64.0f);

            /* increment pen position */
            penX += slot->advance.x;
            penY += slot->advance.y;
        }

        CGPoint out;
        out = CGPointApplyAffineTransform(curOff, curState->curTextMatrix);
        cairoGlyphs[i].x = out.x + x;
        cairoGlyphs[i].y = out.y + y;
    }

    ret.width = ((float)penX) / 64.0f;
    ret.height = ((float)(face->size->metrics.ascender - face->size->metrics.descender)) / 64.0f;

    FT_Face fontFace = (FT_Face)_LazyUIFontHandle.member(curState->getCurFont());
    cairo_font_face_t* cairoFace = cairo_ft_font_face_create_for_ft_face(fontFace, 0);
    cairo_save(_drawContext);
    cairo_path_t* curPath = cairo_copy_path(_drawContext);

    cairo_matrix_t fontCTM, fontSizeMatrix;

    cairo_matrix_t m;
    float trans[6];
    memcpy(trans, &curState->curTransform, sizeof(curState->curTransform));

    m.xx = trans[0];
    m.yx = trans[1];
    m.xy = trans[2];
    m.yy = trans[3];
    m.x0 = trans[4];
    m.y0 = trans[5];

    cairo_set_matrix(_drawContext, &m);

    fontCTM.xx = curState->curTextMatrix.a;
    fontCTM.yx = curState->curTextMatrix.b;
    fontCTM.xy = curState->curTextMatrix.c;
    fontCTM.yy = curState->curTextMatrix.d;
    fontCTM.x0 = curState->curTextMatrix.tx;
    fontCTM.y0 = curState->curTextMatrix.ty;

    cairo_matrix_init_identity(&fontSizeMatrix);
    cairo_matrix_scale(&fontSizeMatrix, 1, -1);
    // cairo_matrix_translate(&fontSizeMatrix, 0, -1);

    cairo_matrix_scale(&fontSizeMatrix, curState->fontSize * _LazyUIFontHorizontalScale.member(uiFont), curState->fontSize);
    cairo_matrix_multiply(&fontSizeMatrix, &fontSizeMatrix, &fontCTM);

    cairo_set_font_matrix(_drawContext, &fontSizeMatrix);
    cairo_set_font_face(_drawContext, cairoFace);

    switch (curState->textDrawingMode) {
        case kCGTextFill:
            cairo_set_source_rgba(_drawContext,
                                  curState->curFillColor.r,
                                  curState->curFillColor.g,
                                  curState->curFillColor.b,
                                  curState->curFillColor.a);

            cairo_show_glyphs(_drawContext, cairoGlyphs, length);
            break;

        case kCGTextStroke: {
            cairo_new_path(_drawContext);
            cairo_glyph_path(_drawContext, cairoGlyphs, length);
            cairo_set_source_rgba(_drawContext,
                                  curState->curStrokeColor.r,
                                  curState->curStrokeColor.g,
                                  curState->curStrokeColor.b,
                                  curState->curStrokeColor.a);
            cairo_stroke(_drawContext);
            break;
        }

        case kCGTextFillStroke: {
            cairo_new_path(_drawContext);
            cairo_glyph_path(_drawContext, cairoGlyphs, length);
            cairo_set_source_rgba(_drawContext,
                                  curState->curFillColor.r,
                                  curState->curFillColor.g,
                                  curState->curFillColor.b,
                                  curState->curFillColor.a);
            cairo_fill(_drawContext);

            cairo_new_path(_drawContext);
            cairo_glyph_path(_drawContext, cairoGlyphs, length);
            cairo_set_source_rgba(_drawContext,
                                  curState->curStrokeColor.r,
                                  curState->curStrokeColor.g,
                                  curState->curStrokeColor.b,
                                  curState->curStrokeColor.a);
            cairo_stroke(_drawContext);
            break;
        }

        case kCGTextFillClip:
        case kCGTextStrokeClip:
        case kCGTextFillStrokeClip:
        default:
            UNIMPLEMENTED_WITH_MSG("Unsupported text drawing mode %d", curState->textDrawingMode);
            break;
    }

    cairo_set_font_face(_drawContext, NULL);
    cairo_font_face_destroy(cairoFace);
    cairo_restore(_drawContext);
    cairo_new_path(_drawContext);
    cairo_append_path(_drawContext, curPath);
    cairo_path_destroy(curPath);

    IwFree(cairoGlyphs);
    _CGFontUnlock();
    UNLOCK_CAIRO();

    return ret;
}

bool CGContextCairo::CGContextIsPointInPath(bool eoFill, float x, float y) {
    ObtainLock();
    LOCK_CAIRO();
    if (eoFill) {
        cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_EVEN_ODD);
    } else {
        cairo_set_fill_rule(_drawContext, CAIRO_FILL_RULE_WINDING);
    }
    bool returnValue = cairo_in_fill(_drawContext, x, y);
    UNLOCK_CAIRO();
    return returnValue;
}
CGPathRef CGContextCairo::CGContextCopyPath(void) {
    CGMutablePathRef copyPath = CGPathCreateMutable();
    ObtainLock();
    LOCK_CAIRO();
    cairo_path_t* caPath = cairo_copy_path(_drawContext);
    UNLOCK_CAIRO();
    cairo_path_data_t* data;

    for (int i = 0; i < caPath->num_data; i += caPath->data[i].header.length) {
        data = &caPath->data[i];
        switch (data->header.type) {
            case CAIRO_PATH_MOVE_TO:
                CGPathMoveToPoint(copyPath, NULL, data[1].point.x, data[1].point.y);
                break;
            case CAIRO_PATH_LINE_TO:
                CGPathAddLineToPoint(copyPath, NULL, data[1].point.x, data[1].point.y);
                break;
            case CAIRO_PATH_CURVE_TO:
                CGPathAddCurveToPoint(
                    copyPath, NULL, data[1].point.x, data[1].point.y, data[2].point.x, data[2].point.y, data[3].point.x, data[3].point.y);
                break;
            case CAIRO_PATH_CLOSE_PATH:
                CGPathCloseSubpath(copyPath);
                break;
            default:
                FAIL_FAST();
                break;
        }
    }
    cairo_path_destroy(caPath);
    return (CGPathRef)copyPath;
}
