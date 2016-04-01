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

#import <CoreImage/CoreImageExport.h>
#import <Foundation/NSObject.h>
#import <CoreImage/CIImage.h>

@class CIImage;

COREIMAGE_EXPORT_CLASS
@interface CIImageAccumulator : NSObject
+ (instancetype)imageAccumulatorWithExtent:(CGRect)extent format:(CIFormat)format STUB_METHOD;
+ (instancetype)imageAccumulatorWithExtent:(CGRect)extent format:(CIFormat)format colorSpace:(CGColorSpaceRef)colorSpace STUB_METHOD;
- (instancetype)initWithExtent:(CGRect)extent format:(CIFormat)format STUB_METHOD;
- (instancetype)initWithExtent:(CGRect)extent format:(CIFormat)format colorSpace:(CGColorSpaceRef)colorSpace STUB_METHOD;
- (void)setImage:(CIImage*)im STUB_METHOD;
- (void)setImage:(CIImage*)im dirtyRect:(CGRect)r STUB_METHOD;
@property (readonly) CGRect extent STUB_PROPERTY;
@property (readonly) CIFormat format STUB_PROPERTY;
- (CIImage*)image STUB_METHOD;
- (void)clear STUB_METHOD;
@end
