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

#pragma once

#import <stubincludes.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreImage/CoreImageExport.h>

COREIMAGE_EXPORT_CLASS
@interface CIColor : NSObject <NSCopying, NSSecureCoding> {
    CGColorRef _cgColor;
}

+ (CIColor*)colorWithCGColor:(CGColorRef)cgColor STUB_METHOD;

@property(readonly) CGFloat red;
@property(readonly) CGFloat green;
@property(readonly) CGFloat blue;
@property(readonly) CGFloat alpha;

+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue;
+ (instancetype)colorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue alpha:(CGFloat)alpha;

- (CGColorSpaceRef)colorSpace STUB_METHOD;
- (const CGFloat*)components STUB_METHOD;
- (instancetype)initWithCGColor:(CGColorRef)cgColor STUB_METHOD;
- (instancetype)initWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue;
- (instancetype)initWithRed:(CGFloat)r green:(CGFloat)g blue:(CGFloat)b alpha:(CGFloat)alpha;
- (size_t)numberOfComponents STUB_METHOD;

@end
