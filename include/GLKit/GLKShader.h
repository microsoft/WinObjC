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

@class GLKShaderEffect;
@class GLKShader;

@interface GLKShaderCache : NSObject
+(instancetype) get;
+(instancetype) alloc;

-(GLKShader*)shaderForName: (NSString*)baseName effect: (GLKShaderEffect*)effect;
-(id)init;
@end

@interface GLKShaderSource : NSObject
-(id)initWithVS: (NSString*)baseVSource PS: (NSString*)basePSource;
@end

@interface GLKShader : NSObject

@property(readonly) GLuint program;
-(id)init;

@end

