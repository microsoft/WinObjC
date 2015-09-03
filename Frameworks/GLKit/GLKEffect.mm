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

#import <Starboard.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKEffect.h>
#import <GLKit/GLKShader.h>
#import <GLKit/GLKTexture.h>

@implementation GLKShaderEffect {
}

-(id)init {
    self = [super init];
    if (!self) return nil;
    
    _transform = [[GLKEffectPropertyTransform alloc] init];

    return self;
}

-(void)prepareToDraw {
    _shader = [[GLKShaderCache get] shaderForName: [self shaderName] effect: self];
    glUseProgram(_shader.program);
}

@end

@implementation GLKBaseEffect {
    NSMutableArray* _textures;
    NSMutableArray* _lights;
}

-(id)init {
    self = [super init];
    if (!self) return nil;

    _lights =  [[NSMutableArray alloc] init];
    self.lightingType = GLKLightingTypePerPixel;
    self.lightModelTwoSided = FALSE;

    _textures = [[NSMutableArray alloc] init];

    self.colorMaterialEnabled = FALSE;
    self.useConstantColor = FALSE;
    self.constantColor = GLKVector4Black();

    _material = [[GLKEffectPropertyMaterial alloc] init];
    _fog = [[GLKEffectPropertyFog alloc] init];

    _shaderName = GLKSH_STANDARD_SHADER;
    
    return self;
}

-(GLKEffectPropertyTexture*) texture2d0 {
    unsigned int count = [_textures count];
    if (count > 0) { return [_textures objectAtIndex: 0]; }
    return nil;
}

-(GLKEffectPropertyTexture*) texture2d1 {
    unsigned int count = [_textures count];
    if (count > 1) { return [_textures objectAtIndex: 1]; }
    return nil;
}

-(NSArray*)textureOrder { return _textures; }

-(void)setTextureOrder: (NSArray*)texin {
    [_textures removeAllObjects];
    for(NSObject* o in texin) {
        assert([o isKindOfClass: [GLKEffectPropertyTexture class]]);
        [_textures addObject: o];
    }
}

-(GLKEffectPropertyLight*) light0 {
    unsigned int count = [_lights count];
    if (count > 0) { return [_lights objectAtIndex: 0]; }
    return nil;
}

-(GLKEffectPropertyLight*) light1 {
    unsigned int count = [_lights count];
    if (count > 1) { return [_lights objectAtIndex: 1]; }
    return nil;
}

-(GLKEffectPropertyLight*) light2 {
    unsigned int count = [_lights count];
    if (count > 2) { return [_lights objectAtIndex: 2]; }
    return nil;
}

-(NSArray*)lightOrder { return _lights; }

-(void)setLightOrder: (NSArray*)lightsIn {
    [_lights removeAllObjects];
    for(NSObject* o in lightsIn) {
        assert([o isKindOfClass: [GLKEffectPropertyLight class]]);
        [_lights addObject: o];
    }
}

-(void)prepareToDraw {
    [super prepareToDraw];
    GLKMatrix4 mvp = GLKMatrix4Transpose(self.transform.mvp);
    GLint loc = self.shader.mvploc;
    glUniformMatrix4fv(loc, 1, 0, (const GLfloat*)&mvp);
}

@end

// ----------------------------------------

@implementation GLKEffectProperty
@end

@implementation GLKEffectPropertyFog

-(id)init {
    self.color = GLKVector4Black();
    self.mode = GLKFogModeLinear;
    self.density = 1.f;
    self.start = 0.f;
    self.end = 1000.f;

    return self;
}

@end

@implementation GLKEffectPropertyLight

-(id)init
{
    _transform = [[GLKEffectPropertyTransform alloc] init];

    self.enabled = TRUE;
    self.position = GLKVector3Origin();

    self.ambientColor = GLKVector4Black();
    self.diffuseColor = GLKVector4White();
    self.specularColor = GLKVector4Black();

    // NOTE: total light atten: 1.f / (K2 * d^2 + K1 * d + K0)
    
    self.constantAttenuation = 1.f;
    self.linearAttenuation = 0.f;
    self.quadraticAttenuation = 0.f;
    
    self.spotDirection = GLKVector3Make(0.f, -1.f, 0.f);
    self.spotCutoff = 180.f;
    self.spotExponent = 0.f;

    return self;
}   

@end

@implementation GLKEffectPropertyMaterial

-(id)init
{
    self.ambientColor = GLKVector4Black();
    self.diffuseColor = GLKVector4White();
    self.specularColor = GLKVector4Black();
    self.emissiveColor = GLKVector4Black();
    self.shininess = 0.f;

    return self;
}

@end

@implementation GLKEffectPropertyTexture

-(id)init
{
    self.enabled = FALSE;
    self.name = 0;
    self.envMode = GLKTextureEnvModeReplace;
    self.target = GLKTextureTarget2D;

    return self;
}

-(id)initWith: (GLKTextureInfo*)tex
{
    [self init];
    self.name = tex.name;
    self.enabled = TRUE;    
    return self;
}

@end

@implementation GLKEffectPropertyTransform

-(id)init {
    self.modelviewMatrix = GLKMatrix4Identity();
    self.projectionMatrix = GLKMatrix4Identity();

    return self;
}

-(GLKMatrix3)normalMatrix {
    return GLKMatrix3FromMatrix4(self.modelviewMatrix);
}

-(GLKMatrix4)mvp {
    return GLKMatrix4Multiply(self.projectionMatrix, self.modelviewMatrix);
}

@end

// --------------------------------------------------------------------------------

@implementation GLKReflectionMapEffect
@end
