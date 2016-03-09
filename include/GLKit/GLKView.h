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

#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/EAGL.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKEnums.h>

typedef NS_ENUM(NSUInteger, GLKViewDrawableMultisample) { GLKViewDrawableMultisampleNone, GLKViewDrawableMultisample4X };

@class GLKView;

@protocol GLKViewDelegate <NSObject>

/**
 @Status Interoperable
*/
- (void)glkView:(GLKView*)view drawInRect:(CGRect)rect;
@end

// --------------------------------------------------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKView : UIView <NSCoding,
                             NSObject,
                             UIAppearance,
                             UIAppearanceContainer,
                             UICoordinateSpace,
                             UIDynamicItem,
                             UIFocusEnvironment,
                             UITraitEnvironment>

@property (assign, nonatomic) id<GLKViewDelegate> delegate;
@property (retain, nonatomic) EAGLContext* context;

@property (readonly, nonatomic) NSInteger drawableHeight;
@property (readonly, nonatomic) NSInteger drawableWidth;

@property (nonatomic) GLKViewDrawableColorFormat drawableColorFormat;
@property (nonatomic) GLKViewDrawableDepthFormat drawableDepthFormat;
@property (nonatomic) GLKViewDrawableStencilFormat drawableStencilFormat;
@property (nonatomic) GLKViewDrawableMultisample drawableMultisample;

@property (readonly, strong) UIImage* snapshot STUB_PROPERTY;

@property (nonatomic) BOOL enableSetNeedsDisplay;

// ----------------------------------------

- (id)initWithFrame:(CGRect)rect;
- (instancetype)initWithFrame:(CGRect)frame context:(EAGLContext*)context STUB_METHOD;
- (id)initWithCoder:(NSCoder*)coder;

- (void)bindDrawable STUB_METHOD;
- (void)display STUB_METHOD;
- (void)deleteDrawable STUB_METHOD;
- (void)layoutSubviews;

@end
