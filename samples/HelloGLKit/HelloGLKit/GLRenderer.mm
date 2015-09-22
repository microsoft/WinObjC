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
    { { 1.0f, -1.0f, -1.0f}, {0.0f,  1.0f,  0.0f,  1.0f}},
    { { 1.0f,  1.0f, -1.0f}, {1.0f,  0.5f,  0.0f,  1.0f}},
    { {-1.0f,  1.0f, -1.0f}, {1.0f,  0.5f,  0.0f,  1.0f}},
    { {-1.0f, -1.0f,  1.0f}, {1.0f,  0.0f,  0.0f,  1.0f}},
    { { 1.0f, -1.0f,  1.0f}, {1.0f,  0.0f,  0.0f,  1.0f}},
    { { 1.0f,  1.0f,  1.0f}, {0.0f,  0.0f,  1.0f,  1.0f}},
    { {-1.0f,  1.0f,  1.0f}, {1.0f,  0.0f,  1.0f,  1.0f }}
};

static uint8_t drawIndices[] = {
    0, 4, 5, 0, 5, 1,
    1, 5, 6, 1, 6, 2,
    2, 6, 7, 2, 7, 3,
    3, 7, 4, 3, 4, 0,
    4, 7, 6, 4, 6, 5,
    3, 0, 1, 3, 1, 2
};

static void dumpMat(const GLKMatrix4& mat)
{
    const float* f = (const float*)&mat;
    NSLog(@"------------------------------");
    for(int i = 0; i < 4; i ++, f += 4) {
        NSLog(@"%6.2f  %6.2f  %6.2f  %6.2f", f[0], f[1], f[2], f[3]);
    }
}

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
    _effect.constantColor = GLKVector4Make(1.f, 0.7f, 0.f, 1.f);
    _effect.colorMaterialEnabled = TRUE; // use vertex colors.
    _cubeAngle = 0.f;

    glClearColor(0.0, 0.3, 0.7, 1.0);
    glClearDepthf(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);    
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
    _cubeAngle += 1.0f / 180.0f * M_PI;
}

-(void)glkView:(GLKView*)view drawInRect:(CGRect)rect {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float aspect = rect.size.width / rect.size.height;
    GLKMatrix4 proj = GLKMatrix4MakePerspective(M_PI / 3, aspect, 0.01f, 100.f);
    _effect.transform.projectionMatrix = proj;

    GLKMatrix4 rotate = GLKMatrix4MakeYRotation(_cubeAngle);
    GLKMatrix4 translate = GLKMatrix4MakeTranslation(0.0f, 0.0f, -5.0f);
    GLKMatrix4 modelview = GLKMatrix4Multiply(translate, rotate);
    _effect.transform.modelviewMatrix = modelview;

    glEnableVertexAttribArray(GLKVertexAttribPosition);
    glEnableVertexAttribArray(GLKVertexAttribColor); 

    glVertexAttribPointer(GLKVertexAttribPosition, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
    glVertexAttribPointer(GLKVertexAttribColor, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid *) (sizeof(float) * 3));

    [_effect prepareToDraw];
    
    glDrawElements(GL_TRIANGLES, sizeof(drawIndices) / sizeof(uint8_t), GL_UNSIGNED_BYTE, drawIndices);
}

@end
