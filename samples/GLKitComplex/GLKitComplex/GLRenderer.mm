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

#include "Mesh.h"

#import "GLRenderer.h"
#import <GLKit/GLKit.h>

#define AMBIENT_COLOR   GLKVector4Make(0.1f, 0.2f, 0.2f, 1.f)
#define ZERO_COLOR      GLKVector4Make(0.f, 0.f, 0.f, 0.f)
#define MAT_SHININESS   30.f

static void dumpMat(const GLKMatrix4& mat)
{
    const float* f = (const float*)&mat;
    NSLog(@"------------------------------");
    for(int i = 0; i < 4; i ++, f += 4) {
        NSLog(@"%6.2f  %6.2f  %6.2f  %6.2f", f[0], f[1], f[2], f[3]);
    }
}

@implementation GLRenderer {
    GLKBaseEffect*  _effect;
    float           _cubeAngle;
    Mesh*           _mesh;

    GLKTextureInfo* _tex1;
}

-(void)initGLData {
    _effect = [[GLKBaseEffect alloc] init];    
    _effect.constantColor = GLKVector4Make(1.f, 0.7f, 0.f, 1.f);
    _effect.colorMaterialEnabled = TRUE; // use vertex colors.
    _cubeAngle = 0.f;

    glClearColor(0.0, 0.35, 0.6, 1.0);
    glClearDepthf(1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);    
    glDepthFunc(GL_LEQUAL);

    // Load the mesh.
    _mesh = new Mesh();

    NSString *file = [[NSBundle mainBundle] pathForResource:@"utah-teapot" ofType:@"obj"];
    NSString *str = [NSString stringWithContentsOfFile: file encoding:NSUTF8StringEncoding error:NULL];
    if (str) {
        _mesh->parse([str UTF8String], [str length]);
        _mesh->calcColours();
    } else {
        _mesh->testMesh();
    }
    if (!_mesh->createOGLBuffers()) {
        NSLog(@"Unable to create OpenGL buffer objects for mesh!");
    }

    // Load the mesh's texture.
    UIImage* img = [UIImage imageNamed: @"seafloor.png"];
    if (img) {
        _tex1 = [GLKTextureLoader textureWithCGImage: img.CGImage options: nil error: NULL];
        _effect.texture2d0.name = _tex1.name;
    }
    
    // Set up lights.
    _effect.material.specularColor = GLKVector4Make(1.f, 1.f, 1.f, 1.f);
    
    GLKVector3 pos = GLKVector3Make(-_mesh->getRadius() * 1.5f, _mesh->getRadius() * 0.6f, 0.f);
    _effect.light0.position = pos;
    _effect.light0.diffuseColor = GLKVector4Make(2.0f, 1.8f, 0.7f, 1.f);
    _effect.light0.specularColor = GLKVector4Make(1.f, 1.f, 1.f, 1.f);
    _effect.light0.linearAttenuation = 10.f / _mesh->getRadius();

    // Set up draw mode.
    _mode = DM_LitSolidColor;
}

-(void)cleanupGLData {
    _effect = nil;

    delete _mesh;
    _mesh = nullptr;
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
    [self setupMaterials];

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float aspect = rect.size.width / rect.size.height;
    GLKMatrix4 proj = GLKMatrix4MakePerspective(M_PI / 3, aspect, 0.01f, 100.f);
    _effect.transform.projectionMatrix = proj;

    GLKMatrix4 rotate = GLKMatrix4MakeYRotation(_cubeAngle);
    static GLKMatrix4 translate = GLKMatrix4MakeTranslation(0.0f, 0.0f, -_mesh->getRadius() * 2.25f);
    GLKMatrix4 modelview = GLKMatrix4Multiply(translate, rotate);
    _effect.transform.modelviewMatrix = modelview;

    [_effect prepareToDraw];

    _mesh->bindVertexData();
    glDrawElements(GL_TRIANGLES, 3 * _mesh->faceCount(), GL_UNSIGNED_SHORT, 0);
}

-(void)nextDisplayMode {
    if (_mode == DM_Last) {
        _mode = DM_LitSolidColor;
    } else {
        _mode = _mode + 1;
    }
}

-(void)setupMaterials {
    switch(_mode) {
    case DM_LitSolidColor:
        _effect.material.shininess = 0.f;
        _effect.texture2d0.enabled = FALSE;
        _effect.useConstantColor = TRUE;
        _effect.light0.enabled = TRUE;
        _effect.lightingEnabled = TRUE;
        _effect.material.ambientColor = AMBIENT_COLOR;
        break;

    case DM_LitTextured:
        _effect.material.shininess = MAT_SHININESS;
        _effect.texture2d0.enabled = TRUE;
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = TRUE;
        _effect.lightingEnabled = TRUE;
        _effect.material.ambientColor = AMBIENT_COLOR;        
        break;
        
    case DM_VertexColor:
        _effect.texture2d0.enabled = FALSE;
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = FALSE;
        _effect.lightingEnabled = FALSE;
        _effect.material.ambientColor = ZERO_COLOR;
        break;
          
    case DM_SolidColor:
        _effect.texture2d0.enabled = FALSE;
        _effect.useConstantColor = TRUE;
        _effect.light0.enabled = FALSE;        
        _effect.lightingEnabled = FALSE;
        _effect.material.ambientColor = ZERO_COLOR;
        break;
          
    case DM_TexturedVertexColor:
        _effect.texture2d0.enabled = TRUE;
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = FALSE;        
        _effect.lightingEnabled = FALSE;
        _effect.material.ambientColor = ZERO_COLOR;
        break;
          
    case DM_TexturedSolidColor:
        _effect.texture2d0.enabled = TRUE;
        _effect.useConstantColor = TRUE;
        _effect.light0.enabled = FALSE;
        _effect.lightingEnabled = FALSE;
        _effect.material.ambientColor = ZERO_COLOR;
        break;
    };
}

@end
