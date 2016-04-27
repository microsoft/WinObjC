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

#import "OpenGLES11Controller.h"
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

@interface OpenGLView : UIView
@end

@implementation OpenGLView
    +(Class) layerClass
    {
        return [CAEAGLLayer class];
    }
@end

@implementation OpenGLES11ViewController {
    EAGLContext *_ctx;
    OpenGLView *_outputView;
    CADisplayLink *_displayLink;
    GLint rbWidth, rbHeight;
    float cubeAngle;
    CGSize _curSize;
    GLuint _framebuffer, _renderbuffer, _depthbuffer;
}

static void glPerspective(GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar)
{
    GLfloat mat[4][4] = { 0 };

    mat[1][1] = cos(fov / 2.0f) / sin(fov / 2.0f);
    mat[0][0] = mat[1][1] / aspect;
    mat[2][2] = (zfar + znear) / (znear - zfar);
    mat[2][3] = -1.0f;
    mat[3][2] = 2.0f * znear * zfar / (znear - zfar);
    mat[3][3] = 1.0f;

    glMultMatrixf((const GLfloat *) mat);
}

-(void) viewWillLayoutSubviews
{
    [EAGLContext setCurrentContext: _ctx];
    if ( !CGSizeEqualToSize(_curSize, _outputView.bounds.size) ) {
        _curSize = _outputView.bounds.size;

        if ( _renderbuffer != 0 ) {
            glDeleteRenderbuffersOES(1, &_renderbuffer);
            _renderbuffer = 0;
        }

        if ( _depthbuffer != 0 ) {
            glDeleteRenderbuffersOES(1, &_depthbuffer);
            _depthbuffer = 0;
        }

        if ( _framebuffer != 0 ) {
            glDeleteFramebuffersOES(1, &_framebuffer);
            _depthbuffer = 0;
        }

        glGenFramebuffersOES(1, &_framebuffer);
        glGenRenderbuffersOES(1, &_renderbuffer);
        glBindFramebufferOES(GL_FRAMEBUFFER_OES, _framebuffer);
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, _renderbuffer);

#ifdef WINOBJC
        _outputView.layer.contentsScale = [[UIApplication displayMode] currentMagnification] * [[UIApplication displayMode] hostScreenScale];
#endif

        [_ctx renderbufferStorage: GL_RENDERBUFFER_OES fromDrawable:(CAEAGLLayer *)_outputView.layer];
        glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_COLOR_ATTACHMENT0_OES, GL_RENDERBUFFER_OES, _renderbuffer); 

        glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_WIDTH_OES, &rbWidth);
        glGetRenderbufferParameterivOES(GL_RENDERBUFFER_OES, GL_RENDERBUFFER_HEIGHT_OES, &rbHeight);
    
        glGenRenderbuffersOES(1, &_depthbuffer);
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, _depthbuffer);
        glRenderbufferStorageOES(GL_RENDERBUFFER_OES, GL_DEPTH_COMPONENT16_OES, rbWidth, rbHeight);
        glFramebufferRenderbufferOES(GL_FRAMEBUFFER_OES, GL_DEPTH_ATTACHMENT_OES, GL_RENDERBUFFER_OES, _depthbuffer);
        glBindRenderbufferOES(GL_RENDERBUFFER_OES, _renderbuffer);
        glClearColor(0.0f, 0.25f, 0.55f, 1.0f);
        glClearDepthf(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
    
        glMatrixMode(GL_MODELVIEW);
        glViewport(0, 0, rbWidth, rbHeight);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        GLfloat aspect = (GLfloat)rbWidth / (GLfloat)rbHeight;

        glPerspective(M_PI / 3, aspect, 0.01f, 100.0f);
    }
}

-(void) viewDidLoad
{   
    self.title = @"OpenGLES 1.1";

    _ctx = [[EAGLContext alloc] initWithAPI: kEAGLRenderingAPIOpenGLES1];
    [EAGLContext setCurrentContext: _ctx];

    CGRect frame = CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height);
    _outputView = [[OpenGLView alloc] initWithFrame: frame];
    _outputView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;

    _displayLink = [CADisplayLink displayLinkWithTarget: self selector: @selector(render)];

    self.view.backgroundColor = [UIColor blackColor];
    [self.view addSubview: _outputView];
}

-(void)viewWillAppear:(BOOL)animated
{
    [_displayLink addToRunLoop: [NSRunLoop currentRunLoop] forMode: NSDefaultRunLoopMode];
}

-(void)viewWillDisappear:(BOOL)animated
{
    [_displayLink removeFromRunLoop: [NSRunLoop currentRunLoop] forMode: NSDefaultRunLoopMode];
}

-(void)render
{
    [EAGLContext setCurrentContext: _ctx];
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDisable(GL_CULL_FACE);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(cubeAngle, 1.0f, 0.0f, 0.0f);
    glRotatef(cubeAngle, 0.0f, 1.0f, 0.0f);
    cubeAngle += 1.0f;

    static float cubeVertices[] = {
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, -1.0f,
        1.0f,  1.0f, -1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f };

    static float cubeColors[] = {
        0.0f,  1.0f,  0.0f,  1.0f,
        0.0f,  1.0f,  0.0f,  1.0f,
        1.0f,  0.5f,  0.0f,  1.0f,
        1.0f,  0.5f,  0.0f,  1.0f,
        1.0f,  0.0f,  0.0f,  1.0f,
        1.0f,  0.0f,  0.0f,  1.0f,
        0.0f,  0.0f,  1.0f,  1.0f,
        1.0f,  0.0f,  1.0f,  1.0f };
   
    static uint8_t drawIndices[] = {
        0, 4, 5, 0, 5, 1,
        1, 5, 6, 1, 6, 2,
        2, 6, 7, 2, 7, 3,
        3, 7, 4, 3, 4, 0,
        4, 7, 6, 4, 6, 5,
        3, 0, 1, 3, 1, 2 };

    glVertexPointer(3, GL_FLOAT, 0, cubeVertices);
    glColorPointer(4, GL_FLOAT, 0, cubeColors);
            
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
             
    glDrawElements(GL_TRIANGLES, sizeof(drawIndices) / sizeof(uint8_t), GL_UNSIGNED_BYTE, drawIndices);

    [_ctx presentRenderbuffer: GL_RENDERBUFFER_OES];
}
@end
 
