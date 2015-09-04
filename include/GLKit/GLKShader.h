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

#import <GLKit/GLKitExport.h>
#import <GLKit/GLKShaderDefs.h>

@class GLKShaderEffect;
@class GLKShader;

typedef void* ShaderLayoutPtr;

GLKIT_EXPORT_CLASS
@interface GLKShaderPair : NSObject

@property NSString* vertexShader;
@property NSString* pixelShader;

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

@property(readonly) ShaderLayoutPtr layout;
@property(readonly) GLuint program;
@property(readonly) GLint mvploc;

-(id)initWith: (GLuint)program;
@end

