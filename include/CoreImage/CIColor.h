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
#import <CoreGraphics/CoreGraphics.h>
#import <CoreImage/CIColor.h>

#import <Foundation/NSObject.h>

#import <math.h>

@class UIColor;
@class NSString;

COREIMAGE_EXPORT_CLASS
@interface CIColor : NSObject <NSCopying, NSSecureCoding> {
    CGColorRef _cgColor;
}

- (instancetype)initWithCGColor:(CGColorRef)c STUB_METHOD;
- (instancetype)initWithColor:(UIColor*)color STUB_METHOD;
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b;
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a;
+ (instancetype)colorWithCGColor:(CGColorRef)c STUB_METHOD;
+ (instancetype)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b;
+ (instancetype)colorWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)a;
+ (instancetype)colorWithString:(NSString*)representation STUB_METHOD;
@property (readonly) CGColorSpaceRef colorSpace STUB_PROPERTY;
@property (readonly) const CGFloat* components STUB_PROPERTY;
@property (readonly) size_t numberOfComponents STUB_PROPERTY;
@property (readonly) CGFloat red;
@property (readonly) CGFloat green;
@property (readonly) CGFloat blue;
@property (readonly) CGFloat alpha;
@property (readonly) NSString* stringRepresentation STUB_PROPERTY;
@end
