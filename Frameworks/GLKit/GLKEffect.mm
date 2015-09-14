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

#define MAX_LIGHTS 3

struct LightVars {
    const char* color;
    const char* pos;
    const char* atten;
    const char* specular;
};

static LightVars lightVarNames[MAX_LIGHTS] = {
    { GLKSH_LIGHT0_COLOR, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_ATTEN, GLKSH_LIGHT0_SPECULAR },
    { GLKSH_LIGHT1_COLOR, GLKSH_LIGHT1_POS, GLKSH_LIGHT1_ATTEN, GLKSH_LIGHT1_SPECULAR },
    { GLKSH_LIGHT2_COLOR, GLKSH_LIGHT2_POS, GLKSH_LIGHT2_ATTEN, GLKSH_LIGHT2_SPECULAR },
};

@implementation GLKShaderEffect {
    ShaderMaterial  _mat;
}

-(id)init {
    self = [super init];
    if (!self) return nil;
    _effectChanged = TRUE;
    
    _transform = [[GLKEffectPropertyTransform alloc] initWith: self];

    return self;
}

-(void)prepareToDraw
{
    _shader = [[GLKShaderCache get] shaderNamed: self.shaderName];
    if (_shader != nil) glUseProgram(_shader.program);

    // Projection matrix.
    GLKMatrix4 mvp = self.transform.mvp;
    GLint loc = _shader.mvploc;
    glUniformMatrix4fv(loc, 1, 0, (const GLfloat*)&mvp);

    // Set up shader constants.
    int curTexUnit = 0;
    if (_effectChanged) {
        _effectChanged = FALSE;

        ShaderLayout* l = (ShaderLayout*)self.shader.layout;
        for(const auto& v : l->vars) {
            if (v.second.vertexAttr) continue;
            auto mv = _mat.find(v.first);
            if (mv == nullptr) {
                NSLog(@"ERROR: Shader variable %s not found in material!", v.first.c_str());
            } else {
                switch(mv->type) {
                case GLKS_SAMPLER2D:
                    glActiveTexture(GL_TEXTURE0 + curTexUnit);
                    glBindTexture(GL_TEXTURE_2D, mv->loc);
                    glUniform1i(v.second.loc, curTexUnit);
                    curTexUnit ++;
                    break;
                case GLKS_SAMPLERCUBE:
                    glActiveTexture(GL_TEXTURE0 + curTexUnit);
                    glBindTexture(GL_TEXTURE_CUBE_MAP, mv->loc);
                    glUniform1i(v.second.loc, curTexUnit);
                    curTexUnit ++;
                    break;
                case GLKS_FLOAT:
                    glUniform1fv(v.second.loc, 1, &_mat.values[mv->loc]);
                    break;
                case GLKS_FLOAT2:
                    glUniform2fv(v.second.loc, 1, &_mat.values[mv->loc]);
                    break;
                case GLKS_FLOAT3:
                    glUniform3fv(v.second.loc, 1, &_mat.values[mv->loc]);
                    break;
                case GLKS_FLOAT4:
                    glUniform4fv(v.second.loc, 1, &_mat.values[mv->loc]);
                    break;
                case GLKS_MAT4:
                    glUniformMatrix4fv(v.second.loc, 1, 0, &_mat.values[mv->loc]);
                    break;
                }
            }
        }
    }
}

-(GLKShaderMaterialPtr)shaderMat {
    return &_mat;
}

@end

@implementation GLKBaseEffect {
    NSMutableArray* _textures;
    NSMutableArray* _lights;
    BOOL            _useConstantColor;
    BOOL            _lightingEnabled;
    GLKLightingType _lightingType;
}

-(id)init {
    self = [super init];
    if (!self) return nil;

    _lights =  [[NSMutableArray alloc] init];
    [_lights addObject: [[GLKEffectPropertyLight alloc] initWith: self]];
    [_lights addObject: [[GLKEffectPropertyLight alloc] initWith: self]];
    [_lights addObject: [[GLKEffectPropertyLight alloc] initWith: self]];

    _lightingType = GLKLightingTypePerPixel;
    _lightModelTwoSided = FALSE;
    _lightingEnabled = TRUE;

    _textures = [[NSMutableArray alloc] init];
    [_textures addObject: [[GLKEffectPropertyTexture alloc] initWith: self]];
    [_textures addObject: [[GLKEffectPropertyTexture alloc] initWith: self]];

    self.colorMaterialEnabled = FALSE;
    self.useConstantColor = FALSE;
    self.constantColor = GLKVector4Black();

    _material = [[GLKEffectPropertyMaterial alloc] initWith: self];
    _fog = [[GLKEffectPropertyFog alloc] initWith: self];

    self.shaderName = @GLKSH_STANDARD_SHADER;

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
    if (self.effectChanged) {
        bool cameraRequired = false;
    
        string shaderName = GLKSH_STANDARD_SHADER "_";
        m->reset();

        // We need these.
        m->defmat(GLKSH_MVP_NAME);
        m->defvattr(GLKSH_POS_NAME);

        if (self.colorMaterialEnabled) {
            m->defvattr(GLKSH_COLOR_NAME);
            shaderName += 'V';
        } else if (self.useConstantColor) {
            shaderName += 'C';
            m->addvar(GLKSH_CONSTCOLOR_NAME, _constantColor);
        } else if(!GLKVector4XYZEqualToScalar(self.material.diffuseColor, 0.f)) {
            shaderName += 'C';
            m->addvar(GLKSH_CONSTCOLOR_NAME, self.material.diffuseColor);
        } else {
            shaderName += 'N';
        }

        shaderName += '_';
        
        // Always add these for now.  See if we can figure out if something is bound to them.
        m->defvattr3(GLKSH_NORMAL_NAME);
        m->defvattr2(GLKSH_UV0_NAME);
        m->defvattr2(GLKSH_UV1_NAME);

        // Process texture variables.
        for(GLKEffectPropertyTexture* t in _textures) {
            if (t.enabled) {
                GLuint name = t.name;
                if (name > 0) {
                    m->addtex(GLKSH_TEX0_NAME, name);
                    shaderName += 'T';
                    continue;
                }
            }
            shaderName += 'U';
        }

        shaderName += '_';

        // Process lighting variables.
        int numEnabled = 0;
        int lightNum = 0;
        GLKVector4 ambient = GLKVector4Make(0, 0, 0, 0);
        float shininess = self.material.shininess;
        GLKVector4 specBase = self.material.specularColor;
        if (GLKVector4XYZEqualToScalar(specBase, 0.f)) shininess = 0.f;
        if (self.lightingEnabled) {
            // TODO: sort lights so we don't get shader permutations such as LUL which is the same
            // as ULL and LLU.
            ambient = GLKVector4Add(ambient, self.material.ambientColor);
            for(GLKEffectPropertyLight* l in _lights) {
                if(l.enabled) {
                    char ltype = 'L';
                    if (!GLKVector4XYZEqualToScalar(l.diffuseColor, 0.f)) {
                        m->addvar(lightVarNames[lightNum].color, l.diffuseColor);
                        m->addvar3(lightVarNames[lightNum].pos, l.position);
                        m->addvar(lightVarNames[lightNum].atten, l.attenuation);
                        if (shininess > 0.f) {
                            GLKVector4 spec = GLKVector4Multiply(l.specularColor, specBase);
                            if (!GLKVector4XYZEqualToScalar(spec, 0.f)) {
                                cameraRequired = true;
                                ltype = 'S';
                                spec.w = shininess;
                                m->addvar(lightVarNames[lightNum].specular, spec);
                            }
                        }
                    }
                    ambient = GLKVector4Add(ambient, l.ambientColor);
                    numEnabled ++;
                    shaderName += ltype;
                } else {
                    shaderName += 'U';
                }

                lightNum ++;
                if (lightNum >= MAX_LIGHTS) break;
            }
            if (!GLKVector4XYZEqualToScalar(ambient, 0.f)) {
                shaderName += 'a';
                m->addvar(GLKSH_AMBIENT, ambient);
            } else {
                shaderName += 'n';
            }

            GLKVector4 emissive = self.material.emissiveColor;
            if (!GLKVector4XYZEqualToScalar(emissive, 0.f)) {
                shaderName += 'e';
                m->addvar(GLKSH_EMISSIVE, emissive);
            } else {
                shaderName += 'n';
            }
        } else {
            shaderName += "UUUnn";
        }

        if (cameraRequired) {
            // TODO: actual camera pos.
            m->addvar(GLKSH_CAMERA, GLKVector3Make(0, 0, 0));
        }

        // Save final shader name.
        NSString* s = [NSString stringWithCString: shaderName.c_str()];
        if (![s isEqualToString: self.shaderName]) {
            NSLog(@"Switching to shader [%@] from [%@]", s, self.shaderName);
            self.shaderName = s;
        }
    }

    // Check for shader existence.
    self.shader = [[GLKShaderCache get] shaderNamed: self.shaderName];
    if (self.shader == nil) {

        // Need to generate a new shader based on the supplied material here.
        ShaderContext shd(standardVsh, standardPsh);
        GLKShaderPair* p = shd.generate(*m);
        if (p) {
            NSLog(@"For shader named: %@", self.shaderName);
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
}

-(BOOL)useConstantColor {
    return _useConstantColor;
}

-(void)setUseConstantColor: (BOOL)use {
    if (_useConstantColor != use) {
        self.effectChanged = TRUE;
        _useConstantColor = use;
    }
}

-(BOOL)lightingEnabled {
    return _lightingEnabled;
}

-(void)setLightingEnabled: (BOOL)enabled {
    if (_lightingEnabled != enabled) {
        _lightingEnabled = enabled;
        self.effectChanged = TRUE;
    }
}

-(GLKLightingType)lightingType {
    return _lightingType;
}

-(void)setLightingType: (GLKLightingType)type {
    if (_lightingType != type) {
        _lightingType = type;
        self.effectChanged = TRUE;
    }
}

@end

// ----------------------------------------

@implementation GLKEffectProperty {
    GLKShaderEffect* _parent;
    BOOL _enabled;
}

-(BOOL)enabled {
    return _enabled;
}

-(void)setEnabled: (BOOL)e {
    if (e != _enabled) {
        _enabled = e;
        self.parent.effectChanged = TRUE;
    }
}

-(id)initWith: (GLKShaderEffect*)parent {
    [super init];
    _parent = parent;
    return self;
}

@end

@implementation GLKEffectPropertyFog
-(id)initWith: (GLKShaderEffect*)parent {
    [super initWith: parent];
    self.color = GLKVector4Black();
    self.mode = GLKFogModeLinear;
    self.density = 1.f;
    self.start = 0.f;
    self.end = 1000.f;

    return self;
}

@end

@implementation GLKEffectPropertyLight

-(id)initWith: (GLKShaderEffect*)parent {
    [super initWith: parent];
    _transform = [[GLKEffectPropertyTransform alloc] initWith: parent];

    self.position = GLKVector4Origin();

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

-(GLKVector3)attenuation {
    GLKVector3 res = { _constantAttenuation, _linearAttenuation, _quadraticAttenuation };
    return res;
}

@end

@implementation GLKEffectPropertyMaterial

-(id)initWith: (GLKShaderEffect*)parent {
    [super initWith: parent];
    self.ambientColor = GLKVector4Black();
    self.diffuseColor = GLKVector4White();
    self.specularColor = GLKVector4Black();
    self.emissiveColor = GLKVector4Black();
    self.shininess = 0.f;

    return self;
}

@end

@implementation GLKEffectPropertyTexture

-(id)initWith: (GLKShaderEffect*)parent {
    [super initWith: parent];
    self.name = 0;
    self.envMode = GLKTextureEnvModeReplace;
    self.target = GLKTextureTarget2D;

    return self;
}

@end

@implementation GLKEffectPropertyTransform

-(id)initWith: (GLKShaderEffect*)parent {
    [super initWith: parent];
    self.modelviewMatrix = GLKMatrix4MakeIdentity();
    self.projectionMatrix = GLKMatrix4MakeIdentity();

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
