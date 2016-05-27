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
#pragma once

#import <ImageIO/ImageIOExport.h>

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFString.h>

#import <CoreFoundation/CFURL.h>

#import <CoreGraphics/CGDataProvider.h>
#import <CoreGraphics/CGImage.h>

typedef struct CGImageSource* CGImageSourceRef;

typedef enum CGImageSourceStatus {
    kCGImageStatusUnexpectedEOF = -5,
    kCGImageStatusInvalidData = -4,
    kCGImageStatusUnknownType = -3,
    kCGImageStatusReadingHeader = -2,
    kCGImageStatusIncomplete = -1,
    kCGImageStatusComplete = 0
} CGImageSourceStatus;

IMAGEIO_EXPORT const CFStringRef kCGImageSourceTypeIdentifierHint;
IMAGEIO_EXPORT const CFStringRef kCGImageSourceShouldAllowFloat;
IMAGEIO_EXPORT const CFStringRef kCGImageSourceShouldCache;
IMAGEIO_EXPORT const CFStringRef kCGImageSourceCreateThumbnailFromImageIfAbsent;
IMAGEIO_EXPORT const CFStringRef kCGImageSourceCreateThumbnailFromImageAlways;
IMAGEIO_EXPORT const CFStringRef kCGImageSourceThumbnailMaxPixelSize;
IMAGEIO_EXPORT const CFStringRef kCGImageSourceCreateThumbnailWithTransform;

IMAGEIO_EXPORT CGImageSourceRef CGImageSourceCreateWithDataProvider(CGDataProviderRef provider, CFDictionaryRef options);
IMAGEIO_EXPORT CGImageSourceRef CGImageSourceCreateWithData(CFDataRef data, CFDictionaryRef options);
IMAGEIO_EXPORT CGImageSourceRef CGImageSourceCreateWithURL(CFURLRef url, CFDictionaryRef options);
IMAGEIO_EXPORT CGImageRef CGImageSourceCreateImageAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options);
IMAGEIO_EXPORT CGImageRef CGImageSourceCreateThumbnailAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options);
IMAGEIO_EXPORT CGImageSourceRef CGImageSourceCreateIncremental(CFDictionaryRef options);
IMAGEIO_EXPORT void CGImageSourceUpdateData(CGImageSourceRef isrc, CFDataRef data, bool final);
IMAGEIO_EXPORT void CGImageSourceUpdateDataProvider(CGImageSourceRef isrc, CGDataProviderRef provider, bool final);
IMAGEIO_EXPORT CFTypeID CGImageSourceGetTypeID();
IMAGEIO_EXPORT CFStringRef CGImageSourceGetType(CGImageSourceRef isrc);
IMAGEIO_EXPORT CFArrayRef CGImageSourceCopyTypeIdentifiers();
IMAGEIO_EXPORT size_t CGImageSourceGetCount(CGImageSourceRef isrc);
IMAGEIO_EXPORT CFDictionaryRef CGImageSourceCopyProperties(CGImageSourceRef isrc, CFDictionaryRef options);
IMAGEIO_EXPORT CFDictionaryRef CGImageSourceCopyPropertiesAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options);
IMAGEIO_EXPORT CGImageSourceStatus CGImageSourceGetStatus(CGImageSourceRef isrc);
IMAGEIO_EXPORT CGImageSourceStatus CGImageSourceGetStatusAtIndex(CGImageSourceRef isrc, size_t index);
