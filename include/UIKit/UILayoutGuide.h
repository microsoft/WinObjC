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

@class NSString;
@class UIView;
@class NSLayoutYAxisAnchor;
@class NSLayoutXAxisAnchor;
@class NSLayoutDimension;

UIKIT_EXPORT_CLASS
@interface UILayoutGuide : NSObject <NSCoding>
@property (copy, nonatomic) NSString* identifier STUB_PROPERTY;
@property (readonly, nonatomic) CGRect layoutFrame STUB_PROPERTY;
@property (nonatomic) UIView* owningView STUB_PROPERTY;
@property (readonly, strong) NSLayoutYAxisAnchor* bottomAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutXAxisAnchor* centerXAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutYAxisAnchor* centerYAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutDimension* heightAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutXAxisAnchor* leadingAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutXAxisAnchor* leftAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutXAxisAnchor* rightAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutYAxisAnchor* topAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutXAxisAnchor* trailingAnchor STUB_PROPERTY;
@property (readonly, strong) NSLayoutDimension* widthAnchor STUB_PROPERTY;
@end
