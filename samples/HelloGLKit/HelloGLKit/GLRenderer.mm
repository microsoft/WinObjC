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
}

-(void)initGLData {
    glGenBuffers(1, &_positionBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, _positionBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(cubeVertices), cubeVertices, GL_STATIC_DRAW);

    _effect = [[GLKBaseEffect alloc] init];
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

    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

@end
