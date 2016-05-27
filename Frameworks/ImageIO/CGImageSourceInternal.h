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

#import <CoreFoundation/CFData.h>
#import <CoreFoundation/CFURL.h>
#import <CoreGraphics/CoreGraphicsExport.h>
#import <Foundation/NSObject.h>

@class NSData;

@interface ImageSource : NSObject
@property (atomic, copy) NSData* data;
@property (atomic) bool incrementalSource;
@property (atomic) CGImageSourceStatus loadStatus;
@property (atomic) int loadIndex;
@property (atomic) bool isFinalIncrementalSet;
- (instancetype)initWithData:(CFDataRef)data;
- (instancetype)initWithURL:(CFURLRef)url;
- (instancetype)initWithDataProvider:(CGDataProviderRef)provider;
- (instancetype)initIncremental;
- (CFStringRef)_getImageType;
- (CGImageSourceStatus)_getJPEGStatusAtIndex:(size_t)index;
- (CGImageSourceStatus)_getTIFFStatusAtIndex:(size_t)index;
- (CGImageSourceStatus)_getGIFStatusAtIndex:(size_t)index;
- (CGImageSourceStatus)_getBMPStatusAtIndex:(size_t)index;
- (CGImageSourceStatus)_getPNGStatusAtIndex:(size_t)index;
- (CGImageSourceStatus)_getICOStatusAtIndex:(size_t)index;
- (CGImageSourceStatus)_getStatusAtIndex:(size_t)index;
@end
