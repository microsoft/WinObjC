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

/**
 @Status Interoperable
*/
- (void)prepareToDraw;
@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKEffectProperty : NSObject
@property (assign, nonatomic) BOOL enabled;
@property (readonly) GLKShaderEffect* parent;
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTransform : GLKEffectProperty <NSObject>

@property (assign, nonatomic) GLKMatrix4 modelviewMatrix;
@property (readonly, nonatomic) GLKMatrix3 normalMatrix;
@property (assign, nonatomic) GLKMatrix4 projectionMatrix;
@property (readonly) GLKMatrix4 mvp;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyFog : GLKEffectProperty <NSObject>

@property (assign, nonatomic) GLint mode;
@property (assign, nonatomic) GLfloat start;
@property (assign, nonatomic) GLfloat end;
@property (assign, nonatomic) GLfloat density;
@property (assign, nonatomic) GLKVector4 color;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyLight : GLKEffectProperty <NSObject>

@property (assign, nonatomic) GLKVector4 position;
@property (assign, nonatomic) GLKVector4 ambientColor;
@property (assign, nonatomic) GLKVector4 diffuseColor;
@property (assign, nonatomic) GLKVector4 specularColor;

@property (assign, nonatomic) GLfloat constantAttenuation;
@property (assign, nonatomic) GLfloat linearAttenuation;
@property (assign, nonatomic) GLfloat quadraticAttenuation;
@property (readonly) GLKVector3 attenuation;

@property (assign, nonatomic) GLfloat spotCutoff;
@property (assign, nonatomic) GLKVector3 spotDirection;
@property (assign, nonatomic) GLfloat spotExponent;

@property (readonly) GLKVector4 transformedPosition;
@property (readonly) GLKVector3 transformedSpotDirection;

@property (retain, nonatomic) GLKEffectPropertyTransform* transform;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyMaterial : GLKEffectProperty <NSObject>

@property (assign, nonatomic) GLKVector4 ambientColor;
@property (assign, nonatomic) GLKVector4 diffuseColor;
@property (assign, nonatomic) GLKVector4 specularColor;
@property (assign, nonatomic) GLKVector4 emissiveColor;
@property (assign) GLuint emissiveTex;
@property (assign) GLuint specularTex;
@property (assign) float reflectionBlendAlpha;
@property (assign) GLuint reflectionBlendTex;
@property (assign, nonatomic) GLfloat shininess;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTexture : GLKEffectProperty <NSObject>

@property (assign, nonatomic) GLuint name;
@property (assign, nonatomic) GLKTextureEnvMode envMode;
@property (assign, nonatomic) GLKTextureTarget target;

@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKShaderEffect : NSObject <GLKNamedEffect, NSObject>

@property (readonly, nonatomic) GLKEffectPropertyTransform* transform;
@property (readonly) GLKShaderMaterialPtr shaderMat;
@property (retain) GLKShader* shader;
@property (retain) NSString* shaderName;
@property (readonly) GLKMatrix4 modelRefTrans;
@property BOOL effectChanged;
@property BOOL cameraRequired; // set when a subclass needs the camera position in a shader.

- (id)init;
- (void)prepareToDraw;

- (BOOL)updateShaderMaterialParams; // Used by subclasses to update all the required shader material parameters.
- (BOOL)prepareShaders; // Make sure shaders are ready to run.  Called after updateShaderMaterialParams.

@end

GLKIT_EXPORT_CLASS
@interface GLKBaseEffect : GLKShaderEffect

@property (readonly, nonatomic) GLKEffectPropertyLight* light0;
@property (readonly, nonatomic) GLKEffectPropertyLight* light1;
@property (readonly, nonatomic) GLKEffectPropertyLight* light2;
@property (copy) NSArray* lightOrder;

@property (assign, nonatomic) GLKLightingType lightingType;
@property (assign, nonatomic) GLKVector4 lightModelAmbientColor;
@property (assign, nonatomic) GLboolean lightModelTwoSided;
@property (assign) BOOL lightingEnabled;

@property (readonly, nonatomic) GLKEffectPropertyTexture* texture2d0;
@property (readonly, nonatomic) GLKEffectPropertyTexture* texture2d1;
@property (copy, nonatomic) NSArray* textureOrder;

@property (assign, nonatomic) GLboolean colorMaterialEnabled;
@property (readonly, nonatomic) GLKEffectPropertyMaterial* material;
@property (readonly, nonatomic) GLKEffectPropertyFog* fog;

@property (assign, nonatomic) GLboolean useConstantColor;
@property (assign, nonatomic) GLKVector4 constantColor;

// For subclasses of GLKBaseEffect that change their own parameters.
@property (assign) NSString* shaderExtName;

@property (copy, nonatomic) NSString* label STUB_PROPERTY;

- (id)init;

- (BOOL)updateShaderMaterialParams;
- (BOOL)prepareShaders;
@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKReflectionMapEffect : GLKBaseEffect
@property (readonly, nonatomic) GLKEffectPropertyTexture* textureCubeMap;
@property (assign, nonatomic) GLKMatrix3 matrix;

- (id)init;

- (BOOL)updateShaderMaterialParams;
@end
