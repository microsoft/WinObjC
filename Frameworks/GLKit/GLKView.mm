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

#define GL_GLEXT_PROTOTYPES
#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#include <OpenGLES/EAGL.h>

#import <StubReturn.h>
#import <Starboard.h>

#import <CoreGraphics/CGGeometry.h>

#import <GLKit/GLKitExport.h>
#import <GLKit/GLKView.h>

#import "CALayerInternal.h"

@implementation GLKView {
    CADisplayLink* _link;

    GLuint _framebuffer;
    GLuint _renderbuffer;
    GLuint _depthbuffer;

    CGSize _curSize;
    BOOL _drawableFormatsUpdated;

    GLKViewDrawableColorFormat _drawableColorFormat;
    GLKViewDrawableDepthFormat _drawableDepthFormat;
    GLKViewDrawableStencilFormat _drawableStencilFormat;
    GLKViewDrawableMultisample _drawableMultisample;
}

/**
 @Status Interoperable
 @Public No
*/
+ (Class)layerClass {
    return [CAEAGLLayer class];
}

/**
 @Status Interoperable
*/
- (NSInteger)drawableWidth {
    return self.frame.size.width;
}

/**
 @Status Interoperable
*/
- (NSInteger)drawableHeight {
    return self.frame.size.height;
}

/**
   @Status Interoperable
*/
- (GLKViewDrawableColorFormat)drawableColorFormat {
    return _drawableColorFormat;
}

/**
   @Status Interoperable
*/
- (GLKViewDrawableDepthFormat)drawableDepthFormat {
    return _drawableDepthFormat;
}

/**
   @Status Interoperable
*/
- (GLKViewDrawableStencilFormat)drawableStencilFormat {
    return _drawableStencilFormat;
}

/**
   @Status Interoperable
*/
- (GLKViewDrawableMultisample)drawableMultisample {
    return _drawableMultisample;
}

/**
   @Status Interoperable
*/
- (void)setDrawableColorFormat:(GLKViewDrawableColorFormat)colorFormat {
    if (_drawableColorFormat != colorFormat) {
        _drawableColorFormat = colorFormat;
        _drawableFormatsUpdated = TRUE;
        [self setNeedsLayout];
    }
}

/**
   @Status Interoperable
*/
- (void)setDrawableDepthFormat:(GLKViewDrawableDepthFormat)depthFormat {
    if (_drawableDepthFormat != depthFormat) {
        _drawableDepthFormat = depthFormat;
        _drawableFormatsUpdated = TRUE;
        [self setNeedsLayout];
    }
}

/**
   @Status Interoperable
*/
- (void)setDrawableStencilFormat:(GLKViewDrawableStencilFormat)stencilFormat {
    if (_drawableStencilFormat != stencilFormat) {
        _drawableStencilFormat = stencilFormat;
        _drawableFormatsUpdated = TRUE;
        [self setNeedsLayout];
    }
}

/**
   @Status Interoperable
*/
- (void)setDrawableMultisample:(GLKViewDrawableMultisample)multisample {
    if (_drawableMultisample != multisample) {
        _drawableMultisample = multisample;
        _drawableFormatsUpdated = TRUE;
        [self setNeedsLayout];
    }
}

- (void)commonInit {
    self.contentMode = UIViewContentModeRedraw;

    self.enableSetNeedsDisplay = TRUE;

    self.layer.opaque = TRUE;

    self.drawableColorFormat = GLKViewDrawableColorFormatWindow;
    self.drawableDepthFormat = GLKViewDrawableDepthFormatNone;
    self.drawableStencilFormat = GLKViewDrawableStencilFormatNone;
    self.drawableMultisample = GLKViewDrawableMultisampleNone;

    self.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    _drawableFormatsUpdated = FALSE;

    _link = [CADisplayLink displayLinkWithTarget:self selector:@selector(_renderFrame)];
    [_link retain];
}

- (void)dealloc {
    [_link release];
    [super dealloc];
}

/**
 @Status Interoperable
*/
- (id)initWithFrame:(CGRect)rect {
    self = [super initWithFrame:rect];
    if (self) {
        [self commonInit];
    }
    return self;
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithFrame:(CGRect)frame context:(EAGLContext*)context {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Interoperable
*/
- (id)initWithCoder:(NSCoder*)coder {
    self = [super initWithCoder:coder];
    if (self) {
        [self commonInit];
    }
    return self;
}

/**
 @Status Interoperable
 @Public No
*/
- (void)setNeedsDisplay {
    [super setNeedsDisplay];
    if (self.enableSetNeedsDisplay) {
        [_link addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    }
}

- (BOOL)_renderFrame {
    BOOL res = FALSE;

    [EAGLContext setCurrentContext:self.context];
    if ([self.delegate respondsToSelector:@selector(glkView:drawInRect:)]) {
        int width = (int)[(CAEAGLLayer*)self.layer _pixelWidth];
        int height = (int)[(CAEAGLLayer*)self.layer _pixelHeight];
        glViewport(0, 0, width, height);

        [self.delegate glkView:self drawInRect:CGRectMake(0, 0, (float)width, (float)height)];
        res = TRUE;
    }

    [self.context presentRenderbuffer:GL_RENDERBUFFER];

    if (self.enableSetNeedsDisplay) {
        [_link removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    }

    return res;
}

/**
 @Status Interoperable
 @Public No
*/
- (void)layoutSubviews {
    [super layoutSubviews];

    CGRect rect = [self frame];
    if (CGSizeEqualToSize(rect.size, _curSize) && !_drawableFormatsUpdated) {
        return;
    }

    _curSize = rect.size;
    _drawableFormatsUpdated = FALSE;

    self.layer.frame = rect;
    self.layer.bounds = rect;

    EAGLContext* ctx = self.context;
    [EAGLContext setCurrentContext:ctx];
    assert(ctx != nil);

    if (_renderbuffer != 0) {
        glDeleteRenderbuffers(1, &_renderbuffer);
        _renderbuffer = 0;
    }

    if (_depthbuffer != 0) {
        glDeleteRenderbuffers(1, &_depthbuffer);
        _depthbuffer = 0;
    }

    if (_framebuffer != 0) {
        glDeleteFramebuffers(1, &_framebuffer);
        _framebuffer = 0;
    }

    glGenFramebuffers(1, &_framebuffer);
    glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);

    glGenRenderbuffers(1, &_renderbuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, _renderbuffer);

#ifdef WINOBJC
    self.layer.contentsScale = [[UIApplication displayMode] currentMagnification] * [[UIApplication displayMode] hostScreenScale];
#endif

    // Assumes 4x from here on out, presumably other configs can be done.
    bool antialiased = (self.drawableMultisample != GLKViewDrawableMultisampleNone);

    CAEAGLLayer* glLayer = (CAEAGLLayer*)self.layer;
    NSMutableDictionary* drawProps = [[NSMutableDictionary alloc] init];

    if (self.drawableColorFormat != GLKViewDrawableColorFormatWindow) {
        if (self.drawableColorFormat == GLKViewDrawableColorFormatRGBA8888) {
            [drawProps setObject:kEAGLColorFormatRGBA8 forKey:kEAGLDrawablePropertyColorFormat];
        } else if (GLKViewDrawableColorFormatRGB565) {
            [drawProps setObject:kEAGLColorFormatRGB565 forKey:kEAGLDrawablePropertyColorFormat];
        } else if (GLKViewDrawableColorFormatSRGBA8888) {
            [drawProps setObject:kEAGLColorFormatRGBA8 forKey:kEAGLDrawablePropertyColorFormat];
        }
    }

    if (antialiased) {
        [drawProps setObject:kEAGLMultisample4X forKey:kEAGLMultisample4X];
    }

    glLayer.drawableProperties = drawProps;

    [ctx renderbufferStorage:GL_RENDERBUFFER fromDrawable:self.layer];
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _renderbuffer);

    int surfaceWidth = (int)[self.layer _pixelWidth];
    int surfaceHeight = (int)[self.layer _pixelHeight];

    if (self.drawableDepthFormat != GLKViewDrawableDepthFormatNone) {
        GLuint fmt = 0;
        if (self.drawableDepthFormat == GLKViewDrawableDepthFormat16) {
            if (self.drawableStencilFormat != GLKViewDrawableStencilFormatNone) {
                fmt = GL_DEPTH24_STENCIL8_OES;
            } else {
                fmt = GL_DEPTH_COMPONENT16;
            }
        } else if (self.drawableDepthFormat == GLKViewDrawableDepthFormat24) {
            fmt = GL_DEPTH24_STENCIL8_OES;
        }
        assert(fmt);

        glGenRenderbuffers(1, &_depthbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, _depthbuffer);
        if (antialiased) {
            glRenderbufferStorageMultisampleANGLE(GL_RENDERBUFFER, 4, fmt, surfaceWidth, surfaceHeight);
        } else {
            glRenderbufferStorage(GL_RENDERBUFFER, fmt, surfaceWidth, surfaceHeight);
        }
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _depthbuffer);
    }

    // Format for stencils will always be D24_S8 here.
    if (self.drawableStencilFormat != GLKViewDrawableStencilFormatNone) {
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _depthbuffer);
    }

    glBindRenderbuffer(GL_RENDERBUFFER, _renderbuffer);
}

/**
 @Status Stub
 @Notes
*/
- (void)bindDrawable {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)display {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)deleteDrawable {
    UNIMPLEMENTED();
}

@end
