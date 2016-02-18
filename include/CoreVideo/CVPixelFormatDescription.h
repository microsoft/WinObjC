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

#import <CoreVideo/CoreVideoExport.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFBase.h>
#import <CoreFoundation/CFArray.h>
#import <CoreVideo/CVPixelBuffer.h>
#import <CoreFoundation/CFString.h>

typedef Boolean (*CVFillExtendedPixelsCallBack)(CVPixelBufferRef pixelBuffer, void* refCon);
typedef struct {
    CFIndex version;
    CVFillExtendedPixelsCallBack fillCallBack;
    void* refCon;
} CVFillExtendedPixelsCallBackData;

COREVIDEO_EXPORT void CVPixelFormatDescriptionRegisterDescriptionWithPixelFormatType(CFDictionaryRef description,
                                                                                     OSType pixelFormat) STUB_METHOD;
COREVIDEO_EXPORT CFDictionaryRef CVPixelFormatDescriptionCreateWithPixelFormatType(CFAllocatorRef allocator,
                                                                                   OSType pixelFormat) STUB_METHOD;
COREVIDEO_EXPORT CFArrayRef CVPixelFormatDescriptionArrayCreateWithAllPixelFormatTypes(CFAllocatorRef allocator) STUB_METHOD;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatName;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatConstant;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatCodecType;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatFourCC;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatContainsAlpha;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatPlanes;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatBlockWidth;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatBlockHeight;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatBitsPerBlock;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatBlockHorizontalAlignment;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatBlockVerticalAlignment;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatBlackBlock;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatHorizontalSubsampling;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatVerticalSubsampling;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatOpenGLFormat;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatOpenGLType;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatOpenGLInternalFormat;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatCGBitmapInfo;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatQDCompatibility;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatCGBitmapContextCompatibility;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatCGImageCompatibility;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatOpenGLCompatibility;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatOpenGLESCompatibility;
COREVIDEO_EXPORT const CFStringRef kCVPixelFormatFillExtendedPixelsCallback;

enum {
    kCVPixelFormatType_1Monochrome = 0x00000001,
    kCVPixelFormatType_2Indexed = 0x00000002,
    kCVPixelFormatType_4Indexed = 0x00000004,
    kCVPixelFormatType_8Indexed = 0x00000008,
    kCVPixelFormatType_1IndexedGray_WhiteIsZero = 0x00000021,
    kCVPixelFormatType_2IndexedGray_WhiteIsZero = 0x00000022,
    kCVPixelFormatType_4IndexedGray_WhiteIsZero = 0x00000024,
    kCVPixelFormatType_8IndexedGray_WhiteIsZero = 0x00000028,
    kCVPixelFormatType_16BE555 = 0x00000010,
    kCVPixelFormatType_16LE555 = 'L555',
    kCVPixelFormatType_16LE5551 = '5551',
    kCVPixelFormatType_16BE565 = 'B565',
    kCVPixelFormatType_16LE565 = 'L565',
    kCVPixelFormatType_24RGB = 0x00000018,
    kCVPixelFormatType_24BGR = '24BG',
    kCVPixelFormatType_32ARGB = 0x00000020,
    kCVPixelFormatType_32BGRA = 'BGRA',
    kCVPixelFormatType_32ABGR = 'ABGR',
    kCVPixelFormatType_32RGBA = 'RGBA',
    kCVPixelFormatType_64ARGB = 'b64a',
    kCVPixelFormatType_48RGB = 'b48r',
    kCVPixelFormatType_32AlphaGray = 'b32a',
    kCVPixelFormatType_16Gray = 'b16g',
    kCVPixelFormatType_30RGB = 'R10k',
    kCVPixelFormatType_422YpCbCr8 = '2vuy',
    kCVPixelFormatType_4444YpCbCrA8 = 'v408',
    kCVPixelFormatType_4444YpCbCrA8R = 'r408',
    kCVPixelFormatType_4444AYpCbCr8 = 'y408',
    kCVPixelFormatType_4444AYpCbCr16 = 'y416',
    kCVPixelFormatType_444YpCbCr8 = 'v308',
    kCVPixelFormatType_422YpCbCr16 = 'v216',
    kCVPixelFormatType_422YpCbCr10 = 'v210',
    kCVPixelFormatType_444YpCbCr10 = 'v410',
    kCVPixelFormatType_420YpCbCr8Planar = 'y420',
    kCVPixelFormatType_420YpCbCr8PlanarFullRange = 'f420',
    kCVPixelFormatType_422YpCbCr_4A_8BiPlanar = 'a2vy',
    kCVPixelFormatType_420YpCbCr8BiPlanarVideoRange = '420v',
    kCVPixelFormatType_420YpCbCr8BiPlanarFullRange = '420f',
    kCVPixelFormatType_422YpCbCr8_yuvs = 'yuvs',
    kCVPixelFormatType_422YpCbCr8FullRange = 'yuvf',
    kCVPixelFormatType_OneComponent8 = 'L008',
    kCVPixelFormatType_TwoComponent8 = '2C08',
    kCVPixelFormatType_OneComponent16Half = 'L00h',
    kCVPixelFormatType_OneComponent32Float = 'L00f',
    kCVPixelFormatType_TwoComponent16Half = '2C0h',
    kCVPixelFormatType_TwoComponent32Float = '2C0f',
    kCVPixelFormatType_64RGBAHalf = 'RGhA',
    kCVPixelFormatType_128RGBAFloat = 'RGfA',
};
