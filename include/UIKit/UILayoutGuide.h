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
@property (copy, nonatomic) NSString* identifier;
@property (readonly, nonatomic) CGRect layoutFrame;
@property (nonatomic) UIView* owningView;
@property (readonly, strong) NSLayoutYAxisAnchor* bottomAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* centerXAnchor;
@property (readonly, strong) NSLayoutYAxisAnchor* centerYAnchor;
@property (readonly, strong) NSLayoutDimension* heightAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* leadingAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* leftAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* rightAnchor;
@property (readonly, strong) NSLayoutYAxisAnchor* topAnchor;
@property (readonly, strong) NSLayoutXAxisAnchor* trailingAnchor;
@property (readonly, strong) NSLayoutDimension* widthAnchor;
@end
