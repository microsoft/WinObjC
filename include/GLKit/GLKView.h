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

#import <GLES2/gl2.h>
#import <OpenGLES/EAGL.h>
#import <UIKit/UIKit.h>

enum _GLKViewDrawableColorFormat {
    GLKViewDrawableColorFormatRGBA8888 = 0,
    GLKViewDrawableColorFormatRGB565,
    GLKViewDrawableColorFormatSRGBA8888
};
typedef GLuint GLKViewDrawableColorFormat;

enum _GLKViewDrawableDepthFormat {
    GLKViewDrawableDepthFormatNone = 0,
    GLKViewDrawableDepthFormat16,
    GLKViewDrawableDepthFormat24
};
typedef GLuint GLKViewDrawableDepthFormat;

enum _GLKViewDrawableStencilFormat {
    GLKViewDrawableStencilFormatNone = 0,
    GLKViewDrawableStencilFormat8
};
typedef GLuint GLKViewDrawableStencilFormat;

@class GLKView;

@protocol GLKViewDelegate
-(void)glkView:(GLKView*) drawInRect:(CGRect)rect;
@end

// --------------------------------------------------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKView : UIView

@property (assign) id<GLKViewDelegate>  delegate;
@property (retain) EAGLContext*         context;

@property (readonly) GLuint             drawableWidth;
@property (readonly) GLuint             drawableHeight;

@property GLKViewDrawableColorFormat    drawableColorFormat;
@property GLKViewDrawableDepthFormat    drawableDepthFormat;
@property GLKViewDrawableStencilFormat  drawableStencilFormat;

@property BOOL enableSetNeedsDisplay;

-(void) bindDrawable;

@end
