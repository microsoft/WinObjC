//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
#import <CoreGraphics/CGBase.h>
#import <Foundation/NSObject.h>

@class NSString;
@class CIImage;
@class NSDictionary;
@class CIFilterShape;

COREIMAGE_EXPORT NSString* const kCISamplerAffineMatrix;
COREIMAGE_EXPORT NSString* const kCISamplerWrapMode;
COREIMAGE_EXPORT NSString* const kCISamplerFilterMode;
COREIMAGE_EXPORT NSString* const kCISamplerColorSpace;
COREIMAGE_EXPORT NSString* const kCISamplerWrapBlack;
COREIMAGE_EXPORT NSString* const kCISamplerWrapClamp;
COREIMAGE_EXPORT NSString* const kCISamplerFilterNearest;
COREIMAGE_EXPORT NSString* const kCISamplerFilterLinear;
COREIMAGE_EXPORT_CLASS
@interface CISampler : NSObject <NSCopying>
+ (instancetype)samplerWithImage:(CIImage*)im STUB_METHOD;
+ (instancetype)samplerWithImage:(CIImage*)im keysAndValues:(id)key0 STUB_METHOD;
+ (instancetype)samplerWithImage:(CIImage*)im options:(NSDictionary*)dict STUB_METHOD;
- (instancetype)initWithImage:(CIImage*)im STUB_METHOD;
- (instancetype)initWithImage:(CIImage*)im keysAndValues:(id)key0 STUB_METHOD;
- (instancetype)initWithImage:(CIImage*)im options:(NSDictionary*)dict STUB_METHOD;
@property (readonly) CIFilterShape* definition STUB_PROPERTY;
@property (readonly) CGRect extent STUB_PROPERTY;
@end
