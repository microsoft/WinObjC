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

@class CIImage, NSDictionary;

COREIMAGE_EXPORT_CLASS
@interface CIContext : NSObject

+ (CIContext*)contextWithCGContext:(CGContextRef)cgContext options:(NSDictionary*)options STUB_METHOD;
+ (CIContext*)contextWithOptions:(NSDictionary*)dict;

- (CGImageRef)createCGImage:(CIImage*)image fromRect:(CGRect)rect;
- (void)drawImage:(CIImage*)image atPoint:(CGPoint)atPoint fromRect:(CGRect)fromRect STUB_METHOD;
- (void)drawImage:(CIImage*)image inRect:(CGRect)inRect fromRect:(CGRect)fromRect STUB_METHOD;

@end
