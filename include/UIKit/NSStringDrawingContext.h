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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>
#import <Foundation/NSObject.h>

UIKIT_EXPORT_CLASS
@interface NSStringDrawingContext : NSObject
@property (nonatomic) CGFloat minimumTrackingAdjustment STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat actualTrackingAdjustment STUB_PROPERTY;
@property (nonatomic) CGFloat minimumScaleFactor STUB_PROPERTY;
@property (readonly, nonatomic) CGFloat actualScaleFactor STUB_PROPERTY;
@property (readonly, nonatomic) CGRect totalBounds STUB_PROPERTY;
@end
