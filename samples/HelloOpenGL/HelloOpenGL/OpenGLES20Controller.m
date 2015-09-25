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

#import "OpenGLES20Controller.h"
#import <OpenGLES/EAGL.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>

static const char vertexShader[] =
"attribute vec4 _position;\n"
"attribute vec4 _color;\n"
"varying vec4 _outcolor;\n"
"uniform mat4 _projection;\n"
"uniform mat4 _rotate;\n"
"uniform mat4 _translate;\n"
"void main()\n"
"{\n"
 "_outcolor = _color;\n"
 "gl_Position = _projection * _translate * _rotate * _position;\n"
"}";

static const char fragShader[] =
"varying lowp vec4 _outcolor;\n"
"void main()\n"
"{\n"
"gl_FragColor = _outcolor;\n"
"}";

@interface OpenGLView : UIView
@end

@implementation OpenGLView
+(Class)layerClass {
    return [CAEAGLLayer class];
}
@end

typedef struct {
    float pps[3];
    float color[4];
} Vertex;

static Vertex cubeVertices[] = {
    { {-1.0f, -1.0f, -1.0f},
        {0.0f,  1.0f,  0.0f,  1.0f}},
    { {1.0f, -1.0f, -1.0f},
        {0.0f,  1.0f,  0.0f,  1.0f}},
    { {1.0f,  1.0f, -1.0f},
        {1.0f,  0.5f,  0.0f,  1.0f}},
    { {-1.0f, 1.0f, -1.0f},
        {1.0f,  0.5f,  0.0f,  1.0f}},
    { {-1.0f, -1.0f,  1.0f},
        {1.0f,  0.0f,  0.0f,  1.0f}},
    { { 1.0f, -1.0f,  1.0f},
        {1.0f,  0.0f,  0.0f,  1.0f}},
    { { 1.0f,  1.0f,  1.0f},
        {0.0f,  0.0f,  1.0f,  1.0f}},
    { {-1.0f,  1.0f,  1.0f},
        {1.0f,  0.0f,  1.0f,  1.0f }}};

static void CATransform3DToFloat(CATransform3D *in, float *out)
{
    out[0] = (float) in->m11;
    out[1] = (float) in->m12;
    out[2] = (float) in->m13;
    out[3] = (float) in->m14;
    out[4] = (float) in->m21;
    out[5] = (float) in->m22;
    out[6] = (float) in->m23;
    out[7] = (float) in->m24;
    out[8] = (float) in->m31;
    out[9] = (float) in->m32;
    out[10] = (float) in->m33;
    out[11] = (float) in->m34;
    out[12] = (float) in->m41;
    out[13] = (float) in->m42;
    out[14] = (float) in->m43;
    out[15] = (float) in->m44;
}

@implementation OpenGLES20ViewController {
    EAGLContext *_ctx;
    OpenGLView *_outputView;
    CADisplayLink *_displayLink;
    GLint rbWidth, rbHeight;
    float cubeAngle;
    CGSize _curSize;
    GLuint _framebuffer, _renderbuffer, _depthbuffer;
    GLuint _vertShaderHandle, _fragShaderHandle, _programHandle;
    GLuint _positionAttrib, _colorAttrib, _projectionAttrib, _rotateAttrib, _translateAttrib;
    GLfloat _aspect;
    GLuint _positionBuffer, _colorBuffer;
}

static void glPerspective(GLfloat fov, GLfloat aspect, GLfloat znear, GLfloat zfar, GLuint attrib)
{
    static GLfloat mat[4][4] = { 0 };

    mat[1][1] = cos(fov / 2.0f) / sin(fov / 2.0f);
    mat[0][0] = mat[1][1] / aspect;
    mat[2][2] = (zfar + znear) / (znear - zfar);
    mat[2][3] = -1.0f;
    mat[3][2] = 2.0f * znear * zfar / (znear - zfar);
    mat[3][3] = 1.0f;
    
    glUniformMatrix4fv(attrib, 1, 0, (const GLfloat *) mat);
}

-(void) viewWillLayoutSubviews
{
    [EAGLContext setCurrentContext: _ctx];
    if ( !CGSizeEqualToSize(_curSize, _outputView.bounds.size) ) {
        _curSize = _outputView.bounds.size;

        if ( _renderbuffer != 0 ) {
            glDeleteRenderbuffers(1, &_renderbuffer);
            _renderbuffer = 0;
        }

        if ( _depthbuffer != 0 ) {
            glDeleteRenderbuffers(1, &_depthbuffer);
            _depthbuffer = 0;
        }

        if ( _framebuffer != 0 ) {
            glDeleteFramebuffers(1, &_framebuffer);
            _depthbuffer = 0;
        }

        glGenFramebuffers(1, &_framebuffer);
        glGenRenderbuffers(1, &_renderbuffer);
        glBindFramebuffer(GL_FRAMEBUFFER, _framebuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, _renderbuffer);

#ifdef WINOBJC
        _outputView.layer.contentsScale = [[UIApplication displayMode] currentMagnification] * [[UIApplication displayMode] hostScreenScale];
#endif

        [_ctx renderbufferStorage: GL_RENDERBUFFER fromDrawable:(CAEAGLLayer *)_outputView.layer];
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, _renderbuffer); 

        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &rbWidth);
        glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &rbHeight);
    
        glGenRenderbuffers(1, &_depthbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, _depthbuffer);
        glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT16, rbWidth, rbHeight);
        glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, _depthbuffer);
        glBindRenderbuffer(GL_RENDERBUFFER, _renderbuffer);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClearDepthf(1.0f);
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);
        
        glGenBuffers(1, &_positionBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, _positionBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);
        
        glViewport(0, 0, rbWidth, rbHeight);
        _aspect = (GLfloat)rbWidth / (GLfloat)rbHeight;
        glPerspective(M_PI / 3, _aspect, 0.01f, 100.0f, _projectionAttrib);
    }
}

-(void) viewDidLoad
{   
    self.title = @"OpenGLES 2.0";

    _ctx = [[EAGLContext alloc] initWithAPI: kEAGLRenderingAPIOpenGLES2];
    [EAGLContext setCurrentContext: _ctx];

    _vertShaderHandle = glCreateShader(GL_VERTEX_SHADER);
    _fragShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);

    const GLchar *vertexShaderSrc[] = { vertexShader };
    const GLint vertexShaderLen[] = { sizeof(vertexShader) };

    const GLchar *fragShaderSrc[] = { fragShader };
    const GLint fragShaderLen[] = { sizeof(fragShader) };

    glShaderSource(_vertShaderHandle, 1, vertexShaderSrc, vertexShaderLen);
    glCompileShader(_vertShaderHandle);

    glShaderSource(_fragShaderHandle, 1, fragShaderSrc, fragShaderLen);
    glCompileShader(_fragShaderHandle);

    _programHandle = glCreateProgram();
    glAttachShader(_programHandle, _vertShaderHandle);
    glAttachShader(_programHandle, _fragShaderHandle);
    glLinkProgram(_programHandle);
    glUseProgram(_programHandle);

    _positionAttrib = glGetAttribLocation(_programHandle, "_position");
    _colorAttrib = glGetAttribLocation(_programHandle, "_color");
    _projectionAttrib = glGetUniformLocation(_programHandle, "_projection");
    _rotateAttrib = glGetUniformLocation(_programHandle, "_rotate");
    _translateAttrib = glGetUniformLocation(_programHandle, "_translate");

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

    glUseProgram(_programHandle);
    glEnableVertexAttribArray(_positionAttrib);
    glEnableVertexAttribArray(_colorAttrib); 

    glVertexAttribPointer(_positionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(_colorAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) (sizeof(float) * 3));

    CATransform3D rotate = CATransform3DMakeRotation(cubeAngle, 1.0f, 0.0f, 0.0f);
    rotate = CATransform3DRotate(rotate, cubeAngle, 0.0f, 1.0f, 0.0f);
    
    CATransform3D translate = CATransform3DMakeTranslation(0.0f, 0.0f, -5.0f);
    float floatMatrix[16] = { 0 };
    
    CATransform3DToFloat(&rotate, floatMatrix);
    glUniformMatrix4fv(_rotateAttrib, 1, 0, (const GLfloat *) floatMatrix);
    CATransform3DToFloat(&translate, floatMatrix);
    glUniformMatrix4fv(_translateAttrib, 1, 0, (const GLfloat *) floatMatrix);

    cubeAngle += 1.0f / 180.0f * M_PI;

    static uint8_t drawIndices[] = {
        0, 4, 5, 0, 5, 1,
        1, 5, 6, 1, 6, 2,
        2, 6, 7, 2, 7, 3,
        3, 7, 4, 3, 4, 0,
        4, 7, 6, 4, 6, 5,
        3, 0, 1, 3, 1, 2 };

    glDrawElements(GL_TRIANGLES, sizeof(drawIndices) / sizeof(uint8_t), GL_UNSIGNED_BYTE, drawIndices);
    
    [_ctx presentRenderbuffer: GL_RENDERBUFFER];
}
@end
 
