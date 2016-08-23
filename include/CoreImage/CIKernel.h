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
@class NSArray;
@class CIImage;

typedef CGRect (^CIKernelROICallback)(int index, CGRect rect);
COREIMAGE_EXPORT_CLASS
@interface CIKernel : NSObject
+ (instancetype)kernelWithString:(NSString*)string STUB_METHOD;
+ (NSArray*)kernelsWithString:(NSString*)s STUB_METHOD;
@property (readonly, atomic) NSString* name STUB_PROPERTY;
- (void)setROISelector:(SEL)aMethod STUB_METHOD;
- (CIImage*)applyWithExtent:(CGRect)extent roiCallback:(CIKernelROICallback)callback arguments:(NSArray*)args STUB_METHOD;
@end
