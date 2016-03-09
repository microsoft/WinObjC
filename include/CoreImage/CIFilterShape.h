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
#import <CoreGraphics/CGAffineTransform.h>
#import <Foundation/NSObject.h>

COREIMAGE_EXPORT_CLASS
@interface CIFilterShape : NSObject <NSCopying>
+ (instancetype)shapeWithRect:(CGRect)r STUB_METHOD;
- (instancetype)initWithRect:(CGRect)r STUB_METHOD;
@property (readonly) CGRect extent STUB_PROPERTY;
- (CIFilterShape*)insetByX:(int)dx Y:(int)dy STUB_METHOD;
- (CIFilterShape*)intersectWith:(CIFilterShape*)s2 STUB_METHOD;
- (CIFilterShape*)intersectWithRect:(CGRect)rect STUB_METHOD;
- (CIFilterShape*)transformBy:(CGAffineTransform)m interior:(BOOL)flag STUB_METHOD;
- (CIFilterShape*)unionWith:(CIFilterShape*)s2 STUB_METHOD;
- (CIFilterShape*)unionWithRect:(CGRect)rect STUB_METHOD;
@end
