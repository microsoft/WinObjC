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
#import "ShaderInfo.h"
#import "ShaderGen.h"
#import "ShaderProg.h"

@implementation GLKShaderEffect {
    ShaderMaterial _mat;
}

-(id)init {
    self = [super init];
    if (!self) return nil;
    
    _transform = [[GLKEffectPropertyTransform alloc] initWith: self];

    return self;
}

-(void)prepareToDraw
{
    _shader = [[GLKShaderCache get] shaderNamed: self.shaderName];
    if (_shader != nil) glUseProgram(_shader.program);
    
    GLKMatrix4 mvp = GLKMatrix4Transpose(self.transform.mvp);
    GLint loc = _shader.mvploc;
    glUniformMatrix4fv(loc, 1, 0, (const GLfloat*)&mvp);
}

-(GLKShaderMaterialPtr)shaderMat {
    return &_mat;
}

@end

@implementation GLKBaseEffect {
    NSMutableArray* _textures;
    NSMutableArray* _lights;
    bool            _effectChanged;
    bool            _useConstantColor;
}

-(id)init {
    self = [super init];
    if (!self) return nil;

    _lights =  [[NSMutableArray alloc] init];
    [_lights addObject: [[GLKEffectPropertyLight alloc] initWith: self]];
    [_lights addObject: [[GLKEffectPropertyLight alloc] initWith: self]];
    [_lights addObject: [[GLKEffectPropertyLight alloc] initWith: self]];
    self.lightingType = GLKLightingTypePerPixel;
    self.lightModelTwoSided = FALSE;

    _textures = [[NSMutableArray alloc] init];
    [_textures addObject: [[GLKEffectPropertyTexture alloc] initWith: self]];
    [_textures addObject: [[GLKEffectPropertyTexture alloc] initWith: self]];

    self.colorMaterialEnabled = FALSE;
    self.useConstantColor = FALSE;
    self.constantColor = GLKVector4Black();

    _material = [[GLKEffectPropertyMaterial alloc] initWith: self];
    _fog = [[GLKEffectPropertyFog alloc] initWith: self];

    self.shaderName = @GLKSH_STANDARD_SHADER;

    _effectChanged = true;
    
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

-(void)prepareToDraw
{
    // Assemble material, calculate name.
    ShaderMaterial* m = (ShaderMaterial*)self.shaderMat;    
    if (_effectChanged) {
        string shaderName = GLKSH_STANDARD_SHADER "_";
        m->reset();

        // We need these.
        m->mat(GLKSH_MVP_NAME);
        m->vertattr(GLKSH_POS_NAME);

        if (self.useConstantColor) {
            shaderName += 'C';
            m->addvar(GLKSH_CONSTCOLOR_NAME, (float*)&_constantColor);
        } else {
            m->vertattr(GLKSH_COLOR_NAME);
            shaderName += 'V';
        }

        // Add these, figure out if we want them later.
        m->vertattr(GLKSH_NORMAL_NAME);
        m->vertattr(GLKSH_UV0_NAME);
        m->vertattr(GLKSH_UV1_NAME);
    
        self.shaderName = [NSString stringWithCString: shaderName.c_str()];
    }

    // Check for shader existence.
    self.shader = [[GLKShaderCache get] shaderNamed: self.shaderName];
    if (self.shader == nil) {

        // Need to generate a new shader based on the supplied material here.
        ShaderContext shd(standardVsh, standardPsh);
        GLKShaderPair* p = shd.generate(*m);
        if (p) {
            NSLog(@"---[ VERTEX SHADER ]------------------------------------------------------------");
            NSLog(p.vertexShader);
            NSLog(@"---[ PIXEL SHADER ]-------------------------------------------------------------");
            NSLog(p.pixelShader);
            self.shader = [[GLKShaderCache get] addShaderNamed: self.shaderName source: p];
            if (self.shader == nil) {
                NSLog(@"There was a problem generating a shader for material %@", self.shaderName);
                return;
            }
        }
    }

    [super prepareToDraw];

    // Additional material parameters setting goes here.
    if (_effectChanged) {
        _effectChanged = false;

        ShaderLayout* l = (ShaderLayout*)self.shader.layout;
        for(auto v : l->vars) {
            if (v.second.vertexAttr) continue;
            auto mv = m->find(v.first);
            if (mv == nullptr) {
                NSLog(@"ERROR: Shader variable %s not found in material!", v.first.c_str());
            } else {
                glUniform4fv(v.second.loc, 1, &m->values[mv->loc]);
            }
        }
    }
}

-(BOOL)useConstantColor {
    return _useConstantColor;
}

-(void)setUseConstantColor: (BOOL)use {
    if (_useConstantColor != use) {
        _effectChanged = true;
        _useConstantColor = use;
    }
}

@end

// ----------------------------------------

@implementation GLKEffectProperty
@end

@implementation GLKEffectPropertyFog {
    GLKShaderEffect* _parent;
}

-(id)initWith: (GLKShaderEffect*)parent {
    [super init];
    _parent = parent;
    self.color = GLKVector4Black();
    self.mode = GLKFogModeLinear;
    self.density = 1.f;
    self.start = 0.f;
    self.end = 1000.f;

    return self;
}

@end

@implementation GLKEffectPropertyLight {
    GLKShaderEffect* _parent;
}

-(id)initWith: (GLKShaderEffect*)parent {
    [super init];
    _parent = parent;
    _transform = [[GLKEffectPropertyTransform alloc] initWith: parent];

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

@implementation GLKEffectPropertyMaterial {
    GLKShaderEffect* _parent;
}

-(id)initWith: (GLKShaderEffect*)parent {
    [super init];
    _parent = parent;
    self.ambientColor = GLKVector4Black();
    self.diffuseColor = GLKVector4White();
    self.specularColor = GLKVector4Black();
    self.emissiveColor = GLKVector4Black();
    self.shininess = 0.f;

    return self;
}

@end

@implementation GLKEffectPropertyTexture {
    GLKShaderEffect* _parent;
}

-(id)initWith: (GLKShaderEffect*)parent {
    [super init];
    _parent = parent;
    self.enabled = FALSE;
    self.name = 0;
    self.envMode = GLKTextureEnvModeReplace;
    self.target = GLKTextureTarget2D;

    return self;
}

@end

@implementation GLKEffectPropertyTransform {
    GLKShaderEffect* _parent;
}

-(id)initWith: (GLKShaderEffect*)parent {
    [super init];
    _parent = parent;
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
