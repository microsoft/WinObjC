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

#import <Foundation/NSObject.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKShaderDefs.h>
#import <GLKit/GLKMath.h>

enum _GLKShaderVarType {
    GLKS_INVALID = 0,
    GLKS_SAMPLER2D,
    GLKS_SAMPLERCUBE,
    GLKS_FLOAT,
    GLKS_FLOAT2,
    GLKS_FLOAT3,
    GLKS_FLOAT4,
    GLKS_MAT4
};
typedef unsigned int GLKShaderVarType;

@class GLKShaderEffect;
@class GLKShader;

typedef void* GLKShaderLayoutPtr;
typedef void* GLKShaderMaterialPtr;

GLKIT_EXPORT_CLASS
@interface GLKShaderPair : NSObject

@property(retain) NSString* vertexShader;
@property(retain) NSString* pixelShader;

@end

GLKIT_EXPORT_CLASS
@interface GLKShaderCache : NSObject
+(instancetype) get;

-(GLKShader*)addShaderNamed: (NSString*)name source: (GLKShaderPair*)src;
-(GLKShader*)shaderNamed: (NSString*)name;

-(id)init;
@end

GLKIT_EXPORT_CLASS
@interface GLKShader : NSObject

@property(readonly) GLKShaderLayoutPtr layout;
@property(readonly) GLuint program;
@property(readonly) GLint mvploc;

-(id)initWith: (GLuint)program;
@end

// The next two classes wrap some internal C++ classes.  It isn't necessary to know about/use them
// for GLKit apps, but they're provided for those who want to add their own shaders to the pipeline.

GLKIT_EXPORT_CLASS
@interface GLKShaderMaterial : NSObject
-(id)initWith: (GLKShaderMaterialPtr)ptr;

-(void)reset;
-(void)addVec2: (GLKVector2)val named: (NSString*)name;
-(void)addVec3: (GLKVector3)val named: (NSString*)name;
-(void)addVec4: (GLKVector4)val named: (NSString*)name;
-(void)addTexture: (GLuint)texHandle named: (NSString*)name;
-(void)addTexCube: (GLuint)texHandle named: (NSString*)name;

@end

GLKIT_EXPORT_CLASS
@interface GLKShaderLayout : NSObject
-(id)initWith: (GLKShaderLayoutPtr)ptr;
-(NSArray /*NSString*/*)variables;
-(int)getLocationOf: (NSString*)var;
-(GLKShaderVarType)getTypeOf: (NSString*)var;
@end
