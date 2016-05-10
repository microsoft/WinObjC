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

#import <Foundation/Foundation.h>
#import <CoreGraphics/CGDataProvider.h>
#import <ImageIO/ImageIO.h>
#import <ImageIO/CGImageDestination.h>
#import <objc/runtime.h>
#include <NSLogging.h>
#import <Starboard.h>

#include "COMIncludes.h"
#include "Wincodec.h"
#include <wrl/client.h>
#include "COMIncludes_End.h"

using namespace Microsoft::WRL;

@interface ImageDestination : NSObject
@property (atomic)enum imageTypes type;
@property (atomic)size_t count;
@property (atomic)size_t expectedCount;
@property (atomic)CFMutableDataRef outData;
@property (atomic)ComPtr<IWICImagingFactory> idFactory;
@property (atomic)ComPtr<IWICStream> idStream;
@property (atomic)ComPtr<IWICBitmapEncoder> idEncoder;
@property (atomic)ComPtr<IWICMetadataQueryWriter> idGifEncoderMetadataQueryWriter;

-(instancetype)initToDestination:(size_t)frames
                            type:(CFStringRef)type
                            data:(CFMutableDataRef)data
                             url:(CFURLRef)url;
@end