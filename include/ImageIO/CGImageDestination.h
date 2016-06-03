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
#import <ImageIO/CGImageSource.h>

#import <CoreFoundation/CFArray.h>
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFString.h>

#import <CoreFoundation/CFURL.h>

#import <CoreGraphics/CGDataConsumer.h>
#import <CoreGraphics/CGImage.h>

typedef struct CGImageDestination* CGImageDestinationRef;

IMAGEIO_EXPORT const CFStringRef kCGImageDestinationLossyCompressionQuality;
IMAGEIO_EXPORT const CFStringRef kCGImageDestinationBackgroundColor;

IMAGEIO_EXPORT CGImageDestinationRef CGImageDestinationCreateWithDataConsumer(CGDataConsumerRef consumer,
    CFStringRef type,
    size_t count,
    CFDictionaryRef options) STUB_METHOD;
IMAGEIO_EXPORT CGImageDestinationRef CGImageDestinationCreateWithData(CFMutableDataRef data,
    CFStringRef type,
    size_t count,
    CFDictionaryRef options);
IMAGEIO_EXPORT CGImageDestinationRef CGImageDestinationCreateWithURL(CFURLRef url, CFStringRef type, size_t count, CFDictionaryRef options);
IMAGEIO_EXPORT void CGImageDestinationAddImage(CGImageDestinationRef idst, CGImageRef image, CFDictionaryRef properties);
IMAGEIO_EXPORT void CGImageDestinationAddImageFromSource(CGImageDestinationRef idst,
    CGImageSourceRef isrc,
    size_t index,
    CFDictionaryRef properties);
IMAGEIO_EXPORT CFArrayRef CGImageDestinationCopyTypeIdentifiers();
IMAGEIO_EXPORT CFTypeID CGImageDestinationGetTypeID();
IMAGEIO_EXPORT void CGImageDestinationSetProperties(CGImageDestinationRef idst, CFDictionaryRef properties);
IMAGEIO_EXPORT bool CGImageDestinationFinalize(CGImageDestinationRef idst);