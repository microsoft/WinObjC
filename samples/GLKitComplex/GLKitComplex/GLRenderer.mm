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

#include "Mesh.h"

#import "GLRenderer.h"
#import <GLKit/GLKit.h>

#define AMBIENT_COLOR   GLKVector4Make(0.25f, 0.45f, 0.45f, 1.f)
#define ZERO_COLOR      GLKVector4Make(0.f, 0.f, 0.f, 0.f)
#define MAT_SHININESS   35.f

static void dumpMat(const GLKMatrix4& mat)
{
    const float* f = (const float*)&mat;
    NSLog(@"------------------------------");
    for(int i = 0; i < 4; i ++, f += 4) {
        NSLog(@"%6.2f  %6.2f  %6.2f  %6.2f", f[0], f[1], f[2], f[3]);
    }
}

@implementation GLRenderer {
    GLKReflectionMapEffect* _effect;
    float                   _cubeAngle;
    Mesh*                   _mesh;

    GLKTextureInfo*         _tex1;
    GLKTextureInfo*         _tex2;
    GLKTextureInfo*         _emissive;
    GLKTextureInfo*         _specular;

    GLKSkyboxEffect*        _skybox;
    GLKTextureInfo*         _skyboxTex;
    bool                    _skyboxXformInited;
}

#ifdef STARBOARD

-(void)reflBlendOn {
    _effect.material.reflectionBlendAlpha = 0.6f;
    if (_specular) {
        _effect.material.reflectionBlendTex = _specular.name;
    }
}

-(void)reflBlendOff {
    _effect.material.reflectionBlendAlpha = 1.f;
    _effect.material.reflectionBlendTex = 0;
}

#endif 

-(void)initGLData {
    GLint curErr;

    _effect = [[GLKReflectionMapEffect alloc] init];    
    _effect.constantColor = GLKVector4Make(1.f, 0.7f, 0.f, 1.f);
    _effect.colorMaterialEnabled = TRUE; // use vertex colors.
    _cubeAngle = 0.f;
    _skyboxXformInited = false;

    _effect.lightModelAmbientColor = GLKVector4Make(0.5f, 0.5f, 0.5f, 1.f);
    
    _skybox = [[GLKSkyboxEffect alloc] init];

    glClearColor(0.0, 0.35, 0.6, 1.0);
    glClearDepthf(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    curErr = glGetError();
    if (curErr) {
        NSLog(@"GL Error 0x%x before creating mesh.", curErr);
    }

    // Load the mesh.
    _mesh = new Mesh();
    curErr = glGetError();
    if (curErr) {
        NSLog(@"GL Error 0x%x before creating mesh.", curErr);
    }

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

    // Load the various textures.
    NSDictionary* baseOpts = @{ GLKTextureLoaderGenerateMipmaps : @1 };
    NSDictionary* alphaTexOpts = @{ GLKTextureLoaderGenerateMipmaps : @1, 
                                    GLKTextureLoaderGrayscaleAsAlpha : @1 };
    UIImage* img = [UIImage imageNamed: @"seafloor.png"];
    if (img) {
        _tex1 = [GLKTextureLoader textureWithCGImage: img.CGImage options: baseOpts error: NULL];
        _effect.texture2d0.name = _tex1.name;
        _effect.texture2d0.envMode = GLKTextureEnvModeModulate;
    }
    img = [UIImage imageNamed: @"teapot_decal.png"];
    if (img) {
        _tex2 = [GLKTextureLoader textureWithCGImage: img.CGImage options: baseOpts error: NULL];
        _effect.texture2d1.name = _tex2.name;
        _effect.texture2d1.envMode = GLKTextureEnvModeDecal;
    }
    img = [UIImage imageNamed: @"teapot_emissive.png"];
    if (img) _emissive = [GLKTextureLoader textureWithCGImage: img.CGImage options: baseOpts error: NULL];
    img = [UIImage imageNamed: @"teapot_specular.png"];
    if (img) _specular = [GLKTextureLoader textureWithCGImage: img.CGImage options: alphaTexOpts error: NULL];

    // Set up lights.
    _effect.material.specularColor = GLKVector4Make(1.f, 1.f, 1.f, 1.f);
    
    _effect.light0.position = GLKVector4Make(-_mesh->getRadius() * 3.0f, _mesh->getRadius() * 1.8f, _mesh->getRadius() * 0.3f, 0.f);
    _effect.light0.diffuseColor = GLKVector4Make(1.0f, 0.8f, 0.35f, 1.f);
    _effect.light0.specularColor = GLKVector4Make(1.f, 1.f, 1.f, 1.f);

    // Set up skybox.
    auto files = @[ @"lobbyxneg.JPG", @"lobbyxpos.JPG",
                    @"lobbyyneg.JPG", @"lobbyypos.JPG",
                    @"lobbyzneg.JPG", @"lobbyzpos.JPG" ];                     
    _skyboxTex = [GLKTextureLoader cubeMapWithContentsOfFiles: files options: baseOpts error: nullptr];
    NSLog(@"Have skybox tex: %d", _skyboxTex.name);
    _skybox.textureCubeMap.name = _skyboxTex.name;
    _skybox.textureCubeMap.enabled = TRUE;

    _skybox.transform.modelviewMatrix = GLKMatrix4MakeScale(-1.f, 1.f, 1.f);

    _effect.textureCubeMap.name = _skyboxTex.name;
    _effect.textureCubeMap.envMode = GLKTextureEnvModeDecal;
    _effect.textureCubeMap.enabled = FALSE;
    
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

    if (!_skyboxXformInited) {
        _skyboxXformInited = true;
        _skybox.transform.projectionMatrix = proj;
    }
    
    [_skybox prepareToDraw];
    [_skybox draw];
    
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
        _effect.lightingType = GLKLightingTypePerVertex;
        _effect.material.shininess = 0.f;
        _effect.texture2d0.enabled = FALSE;
        _effect.texture2d1.enabled = FALSE;
        _effect.textureCubeMap.enabled = FALSE;        
        _effect.useConstantColor = TRUE;
        _effect.light0.enabled = TRUE;
        _effect.material.ambientColor = AMBIENT_COLOR;
        _effect.colorMaterialEnabled = FALSE;
#ifdef STARBOARD
        _effect.lightingEnabled = TRUE;
        _effect.material.emissiveTex = 0;
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;

    case DM_PixSolidColor:
        _effect.lightingType = GLKLightingTypePerPixel;
        _effect.material.shininess = 0.f;
        _effect.texture2d0.enabled = FALSE;
        _effect.texture2d1.enabled = FALSE;
        _effect.textureCubeMap.enabled = FALSE;        
        _effect.useConstantColor = TRUE;
        _effect.light0.enabled = TRUE;
        _effect.material.ambientColor = AMBIENT_COLOR;
        _effect.colorMaterialEnabled = FALSE;
#ifdef STARBOARD
        _effect.lightingEnabled = TRUE;
        _effect.material.emissiveTex = 0;        
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;

    case DM_ReflSpecular:
        _effect.lightingType = GLKLightingTypePerPixel;
        _effect.material.shininess = MAT_SHININESS;
        _effect.texture2d0.enabled = TRUE;
        _effect.texture2d1.enabled = TRUE;
        _effect.textureCubeMap.enabled = TRUE;
        _effect.textureCubeMap.envMode = GLKTextureEnvModeReplace;
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = TRUE;
        _effect.material.ambientColor = AMBIENT_COLOR;
        _effect.colorMaterialEnabled = FALSE;
#ifdef STARBOARD
        _effect.lightingEnabled = TRUE;
        _effect.material.emissiveTex = 0;
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;
        
    case DM_LitTextured:
        _effect.lightingType = GLKLightingTypePerVertex;
        _effect.material.shininess = MAT_SHININESS;
        _effect.texture2d0.enabled = TRUE;
        _effect.texture2d1.enabled = TRUE;
        _effect.textureCubeMap.enabled = FALSE;        
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = TRUE;
        _effect.material.ambientColor = AMBIENT_COLOR;
        _effect.colorMaterialEnabled = TRUE;
#ifdef STARBOARD
        _effect.lightingEnabled = TRUE;
        _effect.material.emissiveTex = 0;
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;

    case DM_PixelLitTextured:
        _effect.lightingType = GLKLightingTypePerPixel;
        _effect.material.shininess = MAT_SHININESS;
        _effect.texture2d0.enabled = TRUE;
        _effect.texture2d1.enabled = TRUE;
        _effect.textureCubeMap.enabled = TRUE;
        _effect.textureCubeMap.envMode = GLKTextureEnvModeDecal;        
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = TRUE;
        _effect.material.ambientColor = AMBIENT_COLOR;
        _effect.colorMaterialEnabled = TRUE;
#ifdef STARBOARD
        _effect.lightingEnabled = TRUE;
        if (_emissive) _effect.material.emissiveTex = _emissive.name;
        if (_specular) _effect.material.specularTex = _specular.name;
        [self reflBlendOn];
#endif 
        break;
        
    case DM_VertexColor:
        _effect.lightingType = GLKLightingTypePerVertex;
        _effect.texture2d0.enabled = FALSE;
        _effect.texture2d1.enabled = FALSE;
        _effect.textureCubeMap.enabled = FALSE;        
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = FALSE;
        _effect.material.ambientColor = ZERO_COLOR;
        _effect.colorMaterialEnabled = TRUE;
#ifdef STARBOARD
        _effect.lightingEnabled = FALSE;
        _effect.material.emissiveTex = 0;        
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;
          
    case DM_SolidColor:
        _effect.lightingType = GLKLightingTypePerVertex;
        _effect.texture2d0.enabled = FALSE;
        _effect.texture2d1.enabled = FALSE;
        _effect.textureCubeMap.enabled = FALSE;        
        _effect.useConstantColor = TRUE;
        _effect.light0.enabled = FALSE;
        _effect.material.ambientColor = ZERO_COLOR;
        _effect.colorMaterialEnabled = FALSE;
#ifdef STARBOARD
        _effect.lightingEnabled = FALSE;
        _effect.material.emissiveTex = 0;        
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;
          
    case DM_TexturedVertexColor:
        _effect.lightingType = GLKLightingTypePerVertex;
        _effect.texture2d0.enabled = TRUE;
        _effect.texture2d1.enabled = FALSE;
        _effect.textureCubeMap.enabled = FALSE;        
        _effect.useConstantColor = FALSE;
        _effect.light0.enabled = FALSE;        
        _effect.material.ambientColor = ZERO_COLOR;
        _effect.colorMaterialEnabled = TRUE;
#ifdef STARBOARD
        _effect.lightingEnabled = FALSE;
        _effect.material.emissiveTex = 0;        
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;
          
    case DM_TexturedSolidColor:
        _effect.lightingType = GLKLightingTypePerVertex;
        _effect.texture2d0.enabled = TRUE;
        _effect.texture2d1.enabled = TRUE;
        _effect.textureCubeMap.enabled = FALSE;        
        _effect.useConstantColor = TRUE;
        _effect.light0.enabled = FALSE;
        _effect.material.ambientColor = ZERO_COLOR;
        _effect.colorMaterialEnabled = FALSE;
#ifdef STARBOARD
        _effect.lightingEnabled = FALSE;
        _effect.material.emissiveTex = 0;        
        _effect.material.specularTex = 0;
        [self reflBlendOff];
#endif 
        break;
    };
}

@end
