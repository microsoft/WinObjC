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

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#import <Starboard.h>

#import <CoreGraphics/CGGeometry.h>

#import <GLKit/GLKitExport.h>
#import <GLKit/GLKView.h>

@implementation GLKView {
    CADisplayLink* _link;

    GLuint _framebuffer;
    GLuint _renderbuffer;
    GLuint _depthbuffer;
    GLuint _stencilbuffer;

    CGSize _curSize;
}

+ (Class)layerClass {
    return [CAEAGLLayer class];
}

- (GLuint)drawableWidth {
    return (GLuint)self.frame.size.width;
}

- (GLuint)drawableHeight {
    return (GLuint)self.frame.size.height;
}

- (void)commonInit {
    self.contentMode = UIViewContentModeRedraw;

    self.enableSetNeedsDisplay = TRUE;

    self.layer.opaque = TRUE;

    self.drawableColorFormat = GLKViewDrawableColorFormatWindow;
    self.drawableDepthFormat = GLKViewDrawableDepthFormatNone;
    self.drawableStencilFormat = GLKViewDrawableStencilFormatNone;

    self.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    _link = [CADisplayLink displayLinkWithTarget:self selector:@selector(_renderFrame)];
    [_link retain];
}

- (void)dealloc {
    [_link release];
    [super dealloc];
}

- (id)initWithFrame:(CGRect)rect {
    self = [super initWithFrame:rect];
    if (self) {
        [self commonInit];
    }
    return self;
}

- (id)initWithCoder:(NSCoder*)coder {
    self = [super initWithCoder:coder];
    if (self) {
        [self commonInit];
    }
    return self;
}

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
        int width = (int)[self.layer _pixelWidth];
        int height = (int)[self.layer _pixelHeight];

        glViewport(0, 0, width, height);
        [self.delegate glkView:self drawInRect:self.frame];
        res = TRUE;
    }

    [self.context presentRenderbuffer:GL_RENDERBUFFER];

    if (self.enableSetNeedsDisplay) {
        [_link removeFromRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
    }

    return res;
}

- (void)layoutSubviews {
    [super layoutSubviews];

    CGRect rect = [self frame];
    if (CGSizeEqualToSize(rect.size, _curSize)) {
        return;
    }

    _curSize = rect.size;

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

    if (_stencilbuffer != 0) {
        glDeleteRenderbuffers(1, &_stencilbuffer);
        _stencilbuffer = 0;
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

    if (self.drawableColorFormat != GLKViewDrawableColorFormatWindow) {
        CAEAGLLayer* l = (CAEAGLLayer*)self.layer;
        NSMutableDictionary* md = [NSMutableDictionary dictionaryWithDictionary:l.drawableProperties];

        if (self.drawableColorFormat == GLKViewDrawableColorFormatRGBA8888) {
            [md setObject:kEAGLColorFormatRGBA8 forKey:kEAGLDrawablePropertyColorFormat];
        } else if (GLKViewDrawableColorFormatRGB565) {
            [md setObject:kEAGLColorFormatRGB565 forKey:kEAGLDrawablePropertyColorFormat];
        } else if (GLKViewDrawableColorFormatSRGBA8888) {
            [md setObject:kEAGLColorFormatRGBA8 forKey:kEAGLDrawablePropertyColorFormat];
        }

        l.drawableProperties = md;
    }

    [ctx renderbufferStorage:GL_RENDERBUFFER fromDrawable:self.layer];
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _renderbuffer);

    int surfaceWidth = (int)[self.layer _pixelWidth];
    int surfaceHeight = (int)[self.layer _pixelHeight];

    if (self.drawableDepthFormat != GLKViewDrawableDepthFormatNone) {
        GLuint fmt = 0;
        if (self.drawableDepthFormat == GLKViewDrawableDepthFormat16) {
            fmt = GL_DEPTH_COMPONENT16;
        } else if (self.drawableDepthFormat == GLKViewDrawableDepthFormat24) {
            // TODO: fix me.
            // fmt = GL_DEPTH_COMPONENT24_OES;
            fmt = GL_DEPTH_COMPONENT16;
        }
        assert(fmt);

        glGenRenderbuffers(1, &_depthbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, _depthbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, fmt, surfaceWidth, surfaceHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _depthbuffer);
    }

    if (self.drawableStencilFormat != GLKViewDrawableStencilFormatNone) {
        GLuint fmt = 0;
        if (self.drawableStencilFormat == GLKViewDrawableStencilFormat8) {
            fmt = GL_STENCIL_INDEX8;
        }
        assert(fmt);

        glGenRenderbuffers(1, &_stencilbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, _stencilbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, fmt, surfaceWidth, surfaceHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _stencilbuffer);
    }
    glBindRenderbuffer(GL_RENDERBUFFER, _renderbuffer);
}

@end
