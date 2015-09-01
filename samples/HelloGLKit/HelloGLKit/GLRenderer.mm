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

#import "GLRenderer.h"
#import <GLKit/GLKit.h>

struct Vertex {
    float pps[3];
    float color[4];
};

static Vertex cubeVertices[] = {
    { {-1.0f, -1.0f, -1.0f}, {0.0f,  1.0f,  0.0f,  1.0f}},
    { {1.0f, -1.0f, -1.0f}, {0.0f,  1.0f,  0.0f,  1.0f}},
    { {1.0f,  1.0f, -1.0f}, {1.0f,  0.5f,  0.0f,  1.0f}},
    { {-1.0f, 1.0f, -1.0f}, {1.0f,  0.5f,  0.0f,  1.0f}},
    { {-1.0f, -1.0f,  1.0f}, {1.0f,  0.0f,  0.0f,  1.0f}},
    { { 1.0f, -1.0f,  1.0f}, {1.0f,  0.0f,  0.0f,  1.0f}},
    { { 1.0f,  1.0f,  1.0f}, {0.0f,  0.0f,  1.0f,  1.0f}},
    { {-1.0f,  1.0f,  1.0f}, {1.0f,  0.0f,  1.0f,  1.0f }}
};

@implementation GLRenderer {
    GLuint          _positionBuffer;
    GLKBaseEffect*  _effect;
    float           _cubeAngle;
}

-(void)initGLData {
    glGenBuffers(1, &_positionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _positionBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    _effect = [[GLKBaseEffect alloc] init];

    _cubeAngle = 0.f;
}

-(void)cleanupGLData {
    _effect = nil;
    
    if (_positionBuffer) {
        glDeleteBuffers(1, &_positionBuffer);
        _positionBuffer = 0;
    }
}

-(void)glkViewController: (GLKViewController*)controller willPause:(BOOL)paused {
    if(paused) {
        NSLog(@"GLRenderer got pause event from controller.");
    } else {
        NSLog(@"GLRenderer got unpause event from controller.");
    }
}

-(void)glkViewControllerUpdate: (GLKViewController*)controller {
    NSLog(@"GLRenderer got update event from controller.");
}

-(void)glkView:(GLKView*)view drawInRect:(CGRect)rect {
    NSLog(@"GLRenderer got render framer request.");

    glClearColor(0.0, 0.1, 0.8, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    float aspect = rect.size.width / rect.size.height;
    
    GLKMatrix4 rotate = GLKMatrix4MakeYRotation(cubeAngle);
    GLKMatrix4 translate = GLKMatrix4MakeTranslation(0.0f, 0.0f, -5.0f);
    GLKMatrix4 proj = GLKMatrix4MakePerspective(M_PI / 3, aspect, 0.01f, 100.f);

    
    glEnableVertexAttribArray(_positionAttrib);
    glEnableVertexAttribArray(_colorAttrib); 

    glVertexAttribPointer(_positionAttrib, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(_colorAttrib, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) (sizeof(float) * 3));

    glPerspective(M_PI / 3, _aspect, 0.01f, 100.0f, _projectionAttrib);
    
    _cubeAngle += 1.0f / 180.0f * M_PI;
}

@end
