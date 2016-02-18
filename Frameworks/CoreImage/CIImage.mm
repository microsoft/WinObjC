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

#include "Starboard.h"
#import <math.h>
#import <StubReturn.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreImage/CIImage.h>
#import <CoreImage/CIColor.h>

@implementation CIImage {
    idretain _cgImage;
    idretain _color;
    CIFilter* _filter;
}

- (CIImage*)init {
    if (self = [super init]) {
        self->_cgImage = nil;
        self->_color = nil;
        self->_filter = nil;
        self->_extent = CGRectInfinite;
    }
    return self;
}

/**
 @Status Stub
*/
+ (CIImage*)emptyImage {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
+ (CIImage*)imageWithCGImage:(CGImageRef)image {
    CIImage* ret = [[CIImage alloc] init];
    if (ret != nil) {
        ret->_cgImage.attach([static_cast<id>(image) copy]);
        ret->_extent = CGRectMake(0, 0, CGImageGetWidth(image) , CGImageGetHeight(image));
    }
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (CIImage*)imageWithColor:(CIColor*)color {
    CIImage* ret = [[CIImage alloc] init];
    if (ret != nil) {
        ret->_color.attach([static_cast<id>(color) copy]);
        ret->_extent = CGRectMake(INFINITY, INFINITY, CGFLOAT_MAX, CGFLOAT_MAX);
    }
    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (CIImage*)imageByCroppingToRect:(CGRect)rect {
    CIImage* ret = [[CIImage alloc] init];
    if (ret == nil) {
        return nil;
    }

    ret->_extent = rect;
    if (self->_cgImage != nil) {
        CGImageRef croppedImage = CGImageCreateWithImageInRect(static_cast<CGImageRef>(self->_cgImage), rect);
        ret->_cgImage.attach([static_cast<id>(croppedImage) copy]);
    } else if (self->_color != nil) {
        ret->_color.attach([self->_color copy]);
        UIGraphicsBeginImageContext(rect.size);
        CGContextRef context = UIGraphicsGetCurrentContext();
        CIColor* color = static_cast<CIColor*>(self->_color);
        CGContextSetRGBFillColor(context, color.red, color.green, color.blue, color.alpha);
        CGContextFillRect(context, rect);
        CGImageRef imageRef = CGBitmapContextCreateImage(context);
        ret->_cgImage.attach([static_cast<id>(imageRef) copy]);
        UIGraphicsEndImageContext();
    } 

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCGImage:(CGImageRef)cgImage {
    self->_cgImage.attach([static_cast<id>(cgImage) copy]);
    self->_extent = CGRectMake(0, 0, CGImageGetWidth(cgImage) , CGImageGetHeight(cgImage));
    return self;
}

/**
 @Status Stub
*/
+ (BOOL)supportsSecureCoding {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @ Status Stub
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

- (void)dealloc {
    _color = nil;
    _cgImage = nil;
    [super dealloc];
}

@end
