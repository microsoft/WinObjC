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

#define GLKSH_STANDARD_SHADER   @"Standard"

#define GLKSH_POS_NAME          "_position"
#define GLKSH_NORMAL_NAME       "_normal"
#define GLKSH_COLOR_NAME        "_color"
#define GLKSH_UV0_NAME          "_uv0"
#define GLKSH_UV1_NAME          "_uv1"

#define GLKSH_MVP_NAME          "_mvp"

@class GLKShaderEffect;
@class GLKShader;

@interface GLKShaderCache : NSObject
+(instancetype) get;

-(GLKShader*)shaderForName: (NSString*)baseName effect: (GLKShaderEffect*)effect;
-(id)init;
@end

@interface GLKShaderSource : NSObject

@property(readonly) GLuint program;
@property(readonly) GLuint vsh;
@property(readonly) GLuint psh;

-(id)initWithVS: (const char*)baseVSource PS: (const char*)basePSource;
-(GLKShader*)shaderForEffect: (GLKShaderEffect*)effect;
@end

@interface GLKShader : NSObject

@property(readonly) GLuint program;
@property(readonly) GLuint vsh;
@property(readonly) GLuint psh;
@property(readonly) GLint mvploc;

-(id)initWith: (GLKShaderSource*)src;
@end

