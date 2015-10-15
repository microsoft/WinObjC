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
#import <Etc.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKEffect.h>
#import <GLKit/GLKShader.h>
#import <GLKit/GLKTexture.h>
#import "ShaderInfo.h"
#import "ShaderGen.h"
#import "ShaderProg.h"

#include <algorithm>

#define MAX_LIGHTS 3
#define MAX_TEXTURES 2

using namespace std;
using namespace GLKitShader;

struct LightVars {
    const char* color;
    const char* pos;
    const char* atten;
    const char* specular;
    const char* spotlight;
    const char* spotlightDir;
};

static LightVars lightVarNames[MAX_LIGHTS] = {
    { GLKSH_LIGHT0_COLOR, GLKSH_LIGHT0_POS, GLKSH_LIGHT0_ATTEN, GLKSH_LIGHT0_SPECULAR, GLKSH_LIGHT0_SPOT, GLKSH_LIGHT0_SPOTDIR },
    { GLKSH_LIGHT1_COLOR, GLKSH_LIGHT1_POS, GLKSH_LIGHT1_ATTEN, GLKSH_LIGHT1_SPECULAR, GLKSH_LIGHT1_SPOT, GLKSH_LIGHT1_SPOTDIR },
    { GLKSH_LIGHT2_COLOR, GLKSH_LIGHT2_POS, GLKSH_LIGHT2_ATTEN, GLKSH_LIGHT2_SPECULAR, GLKSH_LIGHT2_SPOT, GLKSH_LIGHT2_SPOTDIR },
};

@implementation GLKShaderEffect {
    ShaderMaterial _mat;
}

- (id)init {
    self = [super init];
    if (!self)
        return nil;
    _effectChanged = TRUE;

    _transform = [[GLKEffectPropertyTransform alloc] initWith:self];

    return self;
}

- (BOOL)updateShaderMaterialParams {
    return TRUE;
}

- (BOOL)prepareShaders {
    _shader = [[GLKShaderCache get] shaderNamed:self.shaderName];
    if (_shader == nil) {
        NSLog(@"Unable to find shader named %@, cannot setup for draw call!", self.shaderName);
        return FALSE;
    }

    return TRUE;
}

- (void)prepareToDraw {
    BOOL success = FALSE;

    _cameraRequired = FALSE;
    _modelRefTrans = GLKMatrix4Invert(self.transform.modelviewMatrix, &success);

    if (![self updateShaderMaterialParams])
        return;
    if (_cameraRequired) {
        auto res = GLKMatrix4MultiplyVector3WithTranslation(_modelRefTrans, GLKVector3Make(0, 0, 0));
        _mat.addMaterialVar(GLKSH_CAMERA, res);
        self.effectChanged = TRUE;
    }
    if (![self prepareShaders])
        return;

    glUseProgram(_shader.program);

    // Load ModelView * Projection matrix.
    GLKMatrix4 mvp = self.transform.mvp;
    GLint loc = _shader.mvploc;
    glUniformMatrix4fv(loc, 1, 0, (const GLfloat*)&mvp);

    // Set up shader constants.
    int curTexUnit = 0;

    _effectChanged = FALSE;

    ShaderLayout* l = (ShaderLayout*)_shader.layout;
    for (const auto& v : l->vars) {
        if (v.second.vertexAttr) {
            continue;
        }

        int loc;
        GLKShaderVarType type = _mat.findVariable(v.first, true, &loc);

        if (!type) {
            NSLog(@"ERROR: Shader variable %s not found in material!", v.first.c_str());
        } else {
            switch (type) {
                case GLKS_SAMPLER2D:
                    glActiveTexture(GL_TEXTURE0 + curTexUnit);
                    glBindTexture(GL_TEXTURE_2D, loc);
                    glUniform1i(v.second.loc, curTexUnit);
                    curTexUnit++;
                    break;
                case GLKS_SAMPLERCUBE:
                    glActiveTexture(GL_TEXTURE0 + curTexUnit);
                    glBindTexture(GL_TEXTURE_CUBE_MAP, loc);
                    glUniform1i(v.second.loc, curTexUnit);
                    curTexUnit++;
                    break;
                case GLKS_FLOAT:
                    glUniform1fv(v.second.loc, 1, &_mat.values[loc]);
                    break;
                case GLKS_FLOAT2:
                    glUniform2fv(v.second.loc, 1, &_mat.values[loc]);
                    break;
                case GLKS_FLOAT3:
                    glUniform3fv(v.second.loc, 1, &_mat.values[loc]);
                    break;
                case GLKS_FLOAT4:
                    glUniform4fv(v.second.loc, 1, &_mat.values[loc]);
                    break;
                case GLKS_MAT4:
                    glUniformMatrix4fv(v.second.loc, 1, 0, &_mat.values[loc]);
                    break;
            }
        }
    }
}

- (GLKShaderMaterialPtr)shaderMat {
    return &_mat;
}

@end

@implementation GLKBaseEffect {
    NSMutableArray* _textures;
    NSMutableArray* _lights;
    BOOL _useConstantColor;
    BOOL _lightingEnabled;
    GLKLightingType _lightingType;
}

- (id)init {
    self = [super init];
    if (!self)
        return nil;

    _lights = [[NSMutableArray alloc] init];
    [_lights addObject:[[GLKEffectPropertyLight alloc] initWith:self]];
    [_lights addObject:[[GLKEffectPropertyLight alloc] initWith:self]];
    [_lights addObject:[[GLKEffectPropertyLight alloc] initWith:self]];

    _lightingType = GLKLightingTypePerPixel;
    _lightModelAmbientColor = GLKVector4Make(0.2f, 0.2f, 0.2f, 1.f);
    _lightModelTwoSided = FALSE;
    _lightingEnabled = TRUE;

    _textures = [[NSMutableArray alloc] init];
    [_textures addObject:[[GLKEffectPropertyTexture alloc] initWith:self]];
    [_textures addObject:[[GLKEffectPropertyTexture alloc] initWith:self]];

    self.colorMaterialEnabled = FALSE;
    self.useConstantColor = TRUE;
    self.constantColor = GLKVector4White();
    self.shaderExtName = @"";

    _material = [[GLKEffectPropertyMaterial alloc] initWith:self];
    _fog = [[GLKEffectPropertyFog alloc] initWith:self];

    self.shaderName = @GLKSH_STANDARD_SHADER;

    return self;
}

- (GLKEffectPropertyTexture*)texture2d0 {
    unsigned int count = [_textures count];
    if (count > 0) {
        return [_textures objectAtIndex:0];
    }
    return nil;
}

- (GLKEffectPropertyTexture*)texture2d1 {
    unsigned int count = [_textures count];
    if (count > 1) {
        return [_textures objectAtIndex:1];
    }
    return nil;
}

- (NSArray*)textureOrder {
    return _textures;
}

- (void)setTextureOrder:(NSArray*)texin {
    [_textures removeAllObjects];
    for (NSObject* o in texin) {
        assert([o isKindOfClass:[GLKEffectPropertyTexture class]]);
        [_textures addObject:o];
    }
}

- (GLKEffectPropertyLight*)light0 {
    unsigned int count = [_lights count];
    if (count > 0) {
        return [_lights objectAtIndex:0];
    }
    return nil;
}

- (GLKEffectPropertyLight*)light1 {
    unsigned int count = [_lights count];
    if (count > 1) {
        return [_lights objectAtIndex:1];
    }
    return nil;
}

- (GLKEffectPropertyLight*)light2 {
    unsigned int count = [_lights count];
    if (count > 2) {
        return [_lights objectAtIndex:2];
    }
    return nil;
}

- (NSArray*)lightOrder {
    return _lights;
}

- (void)setLightOrder:(NSArray*)lightsIn {
    [_lights removeAllObjects];
    for (NSObject* o in lightsIn) {
        assert([o isKindOfClass:[GLKEffectPropertyLight class]]);
        [_lights addObject:o];
    }
}

- (BOOL)updateShaderMaterialParams {
    [super updateShaderMaterialParams];

    // TODO: don't duplicate code setting light/camera positions.
    bool pp = (_lightingType == GLKLightingTypePerPixel);

    // Assemble material, calculate name.
    // TODO: should be done in updateShaderMaterialParams, but it is fine here for now.
    ShaderMaterial* m = (ShaderMaterial*)self.shaderMat;

    auto matProps = self.material;
    string shaderName = GLKSH_STANDARD_SHADER "_";
    shaderName += pp ? "PL_" : "VL_"; // TODO: don't need this if unlit.
    m->reset();

    // We need these.
    m->defMatrix(GLKSH_MVP_NAME);
    m->defVertexAttr(GLKSH_POS_NAME);

    bool haveCM = false;
    if (self.colorMaterialEnabled) {
        haveCM = true;
        m->defVertexAttr(GLKSH_COLOR_NAME);
        shaderName += 'V';
    } else {
        shaderName += 'N';
    }

    shaderName += '_';

    // Always add these for now.  See if we can figure out if something is bound to them.
    m->defVertexAttr3(GLKSH_NORMAL_NAME);
    m->defVertexAttr2(GLKSH_UV0_NAME);
    m->defVertexAttr2(GLKSH_UV1_NAME);

    // Process texture variables.
    static const char* texNames[] = { GLKSH_TEX0_NAME, GLKSH_TEX1_NAME };
    static const char* texModes[] = { GLKSH_TEX0_MODE, GLKSH_TEX1_MODE };
    int texNum = 0;
    for (GLKEffectPropertyTexture* t in _textures) {
        if (t.enabled) {
            GLuint name = t.name;
            if (name > 0) {
                m->addTexture(texNames[texNum], name);
                m->addInputVar(texModes[texNum], t.envMode);
                shaderName += 'T';
            }
        } else {
            shaderName += 'U';
        }
        texNum++;
        if (texNum >= MAX_TEXTURES)
            break;
    }

    shaderName += '_';

    // Process lighting variables.
    bool isLit = false;
    int numEnabled = 0;
    int lightNum = 0;
    GLKVector4 ambient = matProps.ambientColor;
    float shininess = matProps.shininess;
    char specType = 's';
    char spotType = 't';
    GLuint specTex = matProps.specularTex;
    if (shininess > 0 && specTex > 0 && pp) {
        specType = 'S';
        m->addTexture(GLKSH_SPECULAR_TEX, specTex);
    }
    GLKVector4 specBase = matProps.specularColor;
    if (GLKVector4XYZEqualToScalar(specBase, 0.f))
        shininess = 0.f;

    if (self.lightingEnabled) {
        // TODO: sort lights so we don't get shader permutations such as LUL which is the same
        // as ULL and LLU.
        for (GLKEffectPropertyLight* l in _lights) {
            if (l.enabled) {
                isLit = true;
                char ltype = 'U';
                GLKVector4 finalColor = GLKVector4Multiply(l.diffuseColor, matProps.diffuseColor);
                if (!GLKVector4XYZEqualToScalar(finalColor, 0.f)) {
                    ltype = 'L';
                    m->addMaterialVar(lightVarNames[lightNum].color, finalColor);
                    m->addMaterialVar3(lightVarNames[lightNum].pos, GLKMatrix4MultiplyVector4(self.modelRefTrans, l.transformedPosition));
                    m->addMaterialVar(lightVarNames[lightNum].atten, l.attenuation);
                    float spot = l.spotCutoff;
                    if (spot < 180.f) {
                        spot = std::max(spot, 0.25f);
                        ltype = spotType;
                        float exp = std::max(spot - l.spotExponent - 0.01f, 0.01f);

                        // The difference between the cosines is used to find the spotlight attenuation.
                        spot = cosf(DEG2RAD(spot));
                        exp = cosf(DEG2RAD(exp));
                        float multiplier = 1.f / (exp - spot);

                        m->addMaterialVar(lightVarNames[lightNum].spotlight, GLKVector3Make(spot, exp, multiplier));
                        m->addMaterialVar(lightVarNames[lightNum].spotlightDir,
                                          GLKMatrix4MultiplyVector3(self.modelRefTrans, l.transformedSpotDirection));
                    }
                    if (shininess > 0.f) {
                        GLKVector4 spec = GLKVector4Multiply(l.specularColor, specBase);
                        if (!GLKVector4XYZEqualToScalar(spec, 0.f)) {
                            self.cameraRequired = true;
                            ltype = specType;
                            spec.w = shininess;
                            m->addMaterialVar(lightVarNames[lightNum].specular, spec);
                        }
                    }
                }
                ambient = GLKVector4Add(ambient, l.ambientColor);
                numEnabled++;
                shaderName += ltype;
            } else {
                shaderName += 'U';
            }

            lightNum++;
            if (lightNum >= MAX_LIGHTS)
                break;
        }
        ambient = GLKVector4Multiply(ambient, _lightModelAmbientColor);

        if (!GLKVector4XYZEqualToScalar(ambient, 0.f)) {
            shaderName += 'a';
            m->addMaterialVar(GLKSH_AMBIENT, ambient);
        } else {
            shaderName += 'n';
        }

        GLuint emissiveTex = matProps.emissiveTex;
        if (emissiveTex && pp) {
            shaderName += 'E';
            m->addTexture(GLKSH_EMISSIVE_TEX, emissiveTex);
        } else {
            GLKVector4 emissive = matProps.emissiveColor;
            if (!GLKVector4XYZEqualToScalar(emissive, 0.f)) {
                shaderName += 'e';
                m->addMaterialVar(GLKSH_EMISSIVE, emissive);
            } else {
                shaderName += 'n';
            }
        }
    } else {
        shaderName += "UUUnn";
    }

    // Setup fog parameters.
    auto fog = self.fog;
    if (fog.enabled) {
        auto mode = fog.mode;
        if (mode == GLKFogModeExp || mode == GLKFogModeExp2) {
            float density = fog.density;
            if (density > 0) {
                m->addMaterialVar(GLKSH_FOG_COLOR, fog.color);
                if (mode == GLKFogModeExp) {
                    shaderName += "eF";
                    m->addMaterialVar(GLKSH_FOG_DENSITY, -density);
                } else {
                    shaderName += "EF";
                    m->addMaterialVar(GLKSH_FOG_DENSITY2, -(density * density));
                }
            } else {
                shaderName += "NF";
            }
        } else {
            float start = fog.start;
            float end = fog.end;
            if (start >= 0 && end > start) {
                shaderName += "LF";
                m->addMaterialVar(GLKSH_FOG_COLOR, fog.color);
                m->addMaterialVar(GLKSH_FOG_DISTANCES, GLKVector2Make(end, 1.f / (end - start)));
            } else {
                shaderName += "NF";
            }
        }
    } else {
        shaderName += "NF";
    }

    // Set constant color if lighting is not on.
    if (!isLit) {
        if (self.useConstantColor && !GLKVector4XYZEqualToScalar(_constantColor, 1.f)) {
            shaderName += "_CC";
            m->addMaterialVar(GLKSH_CONSTCOLOR_NAME, _constantColor);
        } else if (!GLKVector4XYZEqualToScalar(matProps.diffuseColor, 0.f) && !GLKVector4XYZEqualToScalar(matProps.diffuseColor, 1.f)) {
            shaderName += "_CC";
            m->addMaterialVar(GLKSH_CONSTCOLOR_NAME, matProps.diffuseColor);
        }
    } else {
        m->addInputVar(GLKSH_LIGHTING_ENABLED, 1);
    }

    self.shaderName = [NSString stringWithCString:shaderName.c_str()];

    return TRUE;
}

- (BOOL)prepareShaders {
    // Account for subclasses.
    self.shaderName = [self.shaderName stringByAppendingString:self.shaderExtName];

    // Check for shader existence.
    self.shader = [[GLKShaderCache get] shaderNamed:self.shaderName];
    if (self.shader == nil) {
        bool pp = (_lightingType == GLKLightingTypePerPixel);

        // Need to generate a new shader based on the supplied material here.
        ShaderContext shd(pp ? pixelVsh : standardVsh, pp ? pixelPsh : standardPsh);
        ShaderMaterial* m = (ShaderMaterial*)self.shaderMat;
        GLKShaderPair* p = shd.generate(*m);
        if (p) {
            NSLog(@"For shader named: %@", self.shaderName);
            NSLog(@"---[ VERTEX SHADER ]------------------------------------------------------------");
            NSLog(p.vertexShader);
            NSLog(@"---[ PIXEL SHADER ]-------------------------------------------------------------");
            NSLog(p.pixelShader);
            self.shader = [[GLKShaderCache get] addShaderNamed:self.shaderName source:p];
            if (self.shader == nil) {
                NSLog(@"There was a problem generating a shader for material %@", self.shaderName);
                return FALSE;
            }
        }
    }

    return TRUE;
}

- (BOOL)useConstantColor {
    return _useConstantColor;
}

- (void)setUseConstantColor:(BOOL)use {
    if (_useConstantColor != use) {
        self.effectChanged = TRUE;
        _useConstantColor = use;
    }
}

- (BOOL)lightingEnabled {
    return _lightingEnabled;
}

- (void)setLightingEnabled:(BOOL)enabled {
    if (_lightingEnabled != enabled) {
        _lightingEnabled = enabled;
        self.effectChanged = TRUE;
    }
}

- (GLKLightingType)lightingType {
    return _lightingType;
}

- (void)setLightingType:(GLKLightingType)type {
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

- (BOOL)enabled {
    return _enabled;
}

- (void)setEnabled:(BOOL)e {
    if (e != _enabled) {
        _enabled = e;
        self.parent.effectChanged = TRUE;
    }
}

- (id)initWith:(GLKShaderEffect*)parent {
    [super init];
    _parent = parent;
    return self;
}

@end

@implementation GLKEffectPropertyFog
- (id)initWith:(GLKShaderEffect*)parent {
    [super initWith:parent];
    self.color = GLKVector4Black();
    self.mode = GLKFogModeExp;
    self.density = 1.f;
    self.start = 0.f;
    self.end = 1000.f;

    return self;
}

@end

@implementation GLKEffectPropertyLight {
    GLKVector4 _position;
    GLKVector3 _spotDirection;
}

- (id)initWith:(GLKShaderEffect*)parent {
    [super initWith:parent];
    _transform = [[GLKEffectPropertyTransform alloc] initWith:parent];

    self.position = GLKVector4Origin();

    self.ambientColor = GLKVector4Black();
    self.diffuseColor = GLKVector4White();
    self.specularColor = GLKVector4Black();

    // NOTE: total light atten: 1.f / (K2 * d^2 + K1 * d + K0)

    self.constantAttenuation = 1.f;
    self.linearAttenuation = 0.f;
    self.quadraticAttenuation = 0.f;

    self.spotDirection = GLKVector3Make(0.f, 0.f, -1.f);
    self.spotCutoff = 180.f;
    self.spotExponent = 0.f; // means super-sharp.

    return self;
}

- (GLKVector3)attenuation {
    GLKVector3 res = { _constantAttenuation, _linearAttenuation, _quadraticAttenuation };
    return res;
}

- (GLKVector4)position {
    return _position;
}

- (void)setPosition:(GLKVector4)pos {
    _position = pos;
    _transformedPosition = GLKMatrix4MultiplyVector4(self.parent.transform.modelviewMatrix, pos);
}

- (GLKVector3)spotDirection {
    return _spotDirection;
}

- (void)setSpotDirection:(GLKVector3)dir {
    _spotDirection = dir;
    _transformedSpotDirection = GLKMatrix4MultiplyVector3(self.parent.transform.modelviewMatrix, dir);
}

@end

@implementation GLKEffectPropertyMaterial

- (id)initWith:(GLKShaderEffect*)parent {
    [super initWith:parent];
    self.ambientColor = GLKVector4White();
    self.diffuseColor = GLKVector4White();
    self.specularColor = GLKVector4Black();
    self.emissiveColor = GLKVector4Black();
    self.shininess = 0.f;
    self.reflectionBlendAlpha = 1.f;

    return self;
}

@end

@implementation GLKEffectPropertyTexture

- (id)initWith:(GLKShaderEffect*)parent {
    [super initWith:parent];
    self.name = 0;
    self.envMode = GLKTextureEnvModeReplace;
    self.target = GLKTextureTarget2D;

    return self;
}

@end

@implementation GLKEffectPropertyTransform

- (id)initWith:(GLKShaderEffect*)parent {
    [super initWith:parent];
    self.modelviewMatrix = GLKMatrix4MakeIdentity();
    self.projectionMatrix = GLKMatrix4MakeIdentity();

    return self;
}

- (GLKMatrix3)normalMatrix {
    return GLKMatrix3FromMatrix4(self.modelviewMatrix);
}

- (GLKMatrix4)mvp {
    return GLKMatrix4Multiply(self.projectionMatrix, self.modelviewMatrix);
}

@end

// --------------------------------------------------------------------------------

@implementation GLKReflectionMapEffect

- (id)init {
    [super init];
    _textureCubeMap = [[GLKEffectPropertyTexture alloc] initWith:self];
    return self;
}

- (BOOL)updateShaderMaterialParams {
    [super updateShaderMaterialParams];

    string name; // no name by default, can re-use existing shaders with no cube mapping.

    if (_textureCubeMap.enabled) {
        name = "_CM";

        ShaderMaterial* mat = (ShaderMaterial*)self.shaderMat;
        GLuint name = _textureCubeMap.name;
        if (name > 0) {
            mat->addTexCube(GLKSH_TEXCUBE, _textureCubeMap.name);
            mat->addInputVar(GLKSH_TEXCUBE_MODE, _textureCubeMap.envMode);
            mat->addMaterialVar(GLKSH_REFL_XFORM, self.transform.modelviewMatrix);
            self.cameraRequired = TRUE;
        }

        auto matProps = self.material;
        float reflAlpha = matProps.reflectionBlendAlpha;
        if (reflAlpha != 1.f) {
            name += 'A';
            mat->addMaterialVar(GLKSH_REFL_ALPHA, reflAlpha);
        }
        GLuint reflTex = matProps.reflectionBlendTex;
        if (reflTex > 0) {
            name += 'T';
            mat->addTexture(GLKSH_REFL_TEX, reflTex);
        }
    }

    self.shaderExtName = [NSString stringWithCString:name.c_str()];
    return TRUE;
}

@end
