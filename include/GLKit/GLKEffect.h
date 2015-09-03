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
#import "GLKit/GLKMath.h"
#import "GLKit/GLKEnums.h"

@class GLKShader;
@class GLKTextureInfo;

@protocol GLKNamedEffect
-(void)prepareToDraw;
@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKEffectProperty : NSObject
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTransform : GLKEffectProperty

@property(assign) GLKMatrix4 modelviewMatrix;
@property(readonly) GLKMatrix3 normalMatrix;
@property(assign) GLKMatrix4 projectionMatrix;
@property(readonly) GLKMatrix4 mvp;

-(id)init;
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyFog : GLKEffectProperty

@property BOOL enabled;
@property GLKFogMode mode;
@property float start;
@property float end;
@property float density;
@property(assign) GLKVector4 color;

-(id)init;
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyLight : GLKEffectProperty

@property BOOL enabled;

@property(assign) GLKVector3 position;
@property(assign) GLKVector4 ambientColor;
@property(assign) GLKVector4 diffuseColor;
@property(assign) GLKVector4 specularColor;

@property float constantAttenuation;
@property float linearAttenuation;
@property float quadraticAttenuation;

@property(assign) GLKVector3 spotDirection;
@property float spotCutoff;
@property float spotExponent;

@property(retain) GLKEffectPropertyTransform* transform;

-(id)init;
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyMaterial : GLKEffectProperty

@property (assign)GLKVector4 ambientColor;
@property (assign)GLKVector4 diffuseColor;
@property (assign)GLKVector4 specularColor;
@property (assign)GLKVector4 emissiveColor;
@property float shininess;

@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTexture : GLKEffectProperty

@property BOOL enabled;
@property GLuint name;
@property GLKTextureEnvMode envMode;
@property GLKTextureTarget target;

-(id)init;
-(id)initWith: (GLKTextureInfo*)tex;
@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKShaderEffect : NSObject<GLKNamedEffect>

@property(readonly) GLKEffectPropertyTransform* transform;
@property(readonly) GLKShader* shader;

-(id)init;
-(void)prepareToDraw;

@end

GLKIT_EXPORT_CLASS
@interface GLKBaseEffect : GLKShaderEffect

@property(readonly) GLKEffectPropertyLight* light0;
@property(readonly) GLKEffectPropertyLight* light1;
@property(readonly) GLKEffectPropertyLight* light2;
@property(copy) NSArray* lightOrder;

@property(assign) GLKLightingType lightingType;
@property(assign) BOOL lightModelTwoSided;

@property(readonly) GLKEffectPropertyTexture* texture2d0;
@property(readonly) GLKEffectPropertyTexture* texture2d1;
@property(copy) NSArray* textureOrder;

@property(readonly) GLKEffectPropertyMaterial* material;
@property(readonly) GLKEffectPropertyFog* fog;

@property BOOL colorMaterialEnabled;
@property BOOL useConstantColor;
@property(assign) GLKVector4 constantColor;

@property(readonly) NSString* shaderName;

-(id)init;
-(void)prepareToDraw;
@end

// ----------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKReflectionMapEffect : GLKBaseEffect
@end

