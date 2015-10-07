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

#pragma once

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#import "Foundation/NSObject.h"
#import <GLKit/GLKitExport.h>
#import "GLKit/GLKMath.h"
#import "GLKit/GLKEnums.h"

@class GLKShader;
@class GLKShaderEffect;
@class GLKTextureInfo;
@class NSArray;

typedef void* GLKShaderMaterialPtr;

// ----------------------------------------

@protocol GLKNamedEffect
-(void)prepareToDraw;
@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKEffectProperty : NSObject
@property BOOL enabled;
@property(readonly) GLKShaderEffect* parent;
-(id)initWith: (GLKShaderEffect*)parent;
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTransform : GLKEffectProperty

@property(assign) GLKMatrix4 modelviewMatrix;
@property(readonly) GLKMatrix3 normalMatrix;
@property(assign) GLKMatrix4 projectionMatrix;
@property(readonly) GLKMatrix4 mvp;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyFog : GLKEffectProperty

@property GLKFogMode mode;
@property float start;
@property float end;
@property float density;
@property(assign) GLKVector4 color;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyLight : GLKEffectProperty

@property(assign) GLKVector4 position;
@property(assign) GLKVector4 ambientColor;
@property(assign) GLKVector4 diffuseColor;
@property(assign) GLKVector4 specularColor;

@property float constantAttenuation;
@property float linearAttenuation;
@property float quadraticAttenuation;
@property(readonly) GLKVector3 attenuation;

@property(assign) GLKVector3 spotDirection;
@property float spotCutoff;
@property float spotExponent;

@property(readonly) GLKVector4 transformedPosition;
@property(readonly) GLKVector3 transformedSpotDirection;

@property(retain) GLKEffectPropertyTransform* transform;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyMaterial : GLKEffectProperty

@property (assign)GLKVector4 ambientColor;
@property (assign)GLKVector4 diffuseColor;
@property (assign)GLKVector4 specularColor;
@property (assign)GLKVector4 emissiveColor;
@property (assign)GLuint emissiveTex;
@property (assign)GLuint specularTex;
@property (assign)float reflectionBlendAlpha;
@property (assign)GLuint reflectionBlendTex;
@property float shininess;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTexture : GLKEffectProperty

@property GLuint name;
@property GLKTextureEnvMode envMode;
@property GLKTextureTarget target;

@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKShaderEffect : NSObject<GLKNamedEffect>

@property(readonly) GLKEffectPropertyTransform* transform;
@property(readonly) GLKShaderMaterialPtr        shaderMat;
@property(retain)   GLKShader*                  shader;
@property(retain)   NSString*                   shaderName;
@property(readonly) GLKMatrix4                  modelRefTrans;
@property           BOOL                        effectChanged;
@property           BOOL                        cameraRequired;         // set when a subclass needs the camera position in a shader.

-(id)init;
-(void)prepareToDraw;


-(BOOL)updateShaderMaterialParams;  // Used by subclasses to update all the required shader material parameters.
-(BOOL)prepareShaders;              // Make sure shaders are ready to run.  Called after updateShaderMaterialParams.

@end

GLKIT_EXPORT_CLASS
@interface GLKBaseEffect : GLKShaderEffect

@property(readonly) GLKEffectPropertyLight* light0;
@property(readonly) GLKEffectPropertyLight* light1;
@property(readonly) GLKEffectPropertyLight* light2;
@property(copy) NSArray* lightOrder;

@property(assign) GLKLightingType lightingType;
@property(assign) GLKVector4 lightModelAmbientColor;
@property(assign) BOOL lightModelTwoSided;
@property(assign) BOOL lightingEnabled;

@property(readonly) GLKEffectPropertyTexture* texture2d0;
@property(readonly) GLKEffectPropertyTexture* texture2d1;
@property(copy) NSArray* textureOrder;

@property BOOL colorMaterialEnabled;
@property(readonly) GLKEffectPropertyMaterial* material;
@property(readonly) GLKEffectPropertyFog* fog;

@property BOOL useConstantColor;
@property(assign) GLKVector4 constantColor;

// For subclasses of GLKBaseEffect that change their own parameters.
@property(assign) NSString* shaderExtName;

-(id)init;

-(BOOL)updateShaderMaterialParams;
-(BOOL)prepareShaders;
@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKReflectionMapEffect : GLKBaseEffect
@property(readonly) GLKEffectPropertyTexture* textureCubeMap;
@property(assign) GLKMatrix3 matrix;

-(id)init;

-(BOOL)updateShaderMaterialParams;
@end

