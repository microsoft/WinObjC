/* Copyright (c) 2008 Christopher J. W. Lloyd

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef _CGIMAGESOURCE_H_
#define _CGIMAGESOURCE_H_

#import "StarboardExport.h"
#import <CoreFoundation/CFDictionary.h>
#import <CoreFoundation/CFURL.h>

typedef struct _O2ImageSource *CGImageSourceRef;

#import "CGImage.h"

SB_EXPORT CGImageSourceRef CGImageSourceCreateWithData(CFDataRef data,CFDictionaryRef options);
SB_EXPORT CGImageSourceRef CGImageSourceCreateWithURL(CFURLRef url,CFDictionaryRef options);

SB_EXPORT size_t CGImageSourceGetCount(CGImageSourceRef self);

SB_EXPORT CGImageRef CGImageSourceCreateImageAtIndex(CGImageSourceRef self, size_t index, CFDictionaryRef options);
SB_EXPORT CFDictionaryRef CGImageSourceCopyPropertiesAtIndex(CGImageSourceRef self, size_t index,CFDictionaryRef options);
SB_EXPORT CGImageSourceRef CGImageSourceCreateIncremental(CFDictionaryRef options);
SB_EXPORT void CGImageSourceUpdateData(CGImageSourceRef isrc, CFDataRef data, bool final);
SB_EXPORT CGImageSourceRef CGImageSourceCreateWithDataProvider(CGDataProviderRef provider, CFDictionaryRef options);

SB_EXPORT const CFStringRef kCGImageSourceShouldCache;

#endif /* _CGIMAGESOURCE_H_ */