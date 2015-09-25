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

#import "Foundation/NSObject.h"
#import "GLKit/GLKEffect.h"

GLKIT_EXPORT_CLASS
@interface GLKSkyboxEffect : GLKShaderEffect
@property(readonly) GLKEffectPropertyTexture* textureCubeMap;

@property(assign) GLKVector3 center;
@property(assign) float xSize;
@property(assign) float ySize;
@property(assign) float zSize;

@property(retain) GLKShader* shader;
@property(retain) NSString* shaderName;

-(void)prepareToDraw;
-(void)draw;

-(BOOL)updateShaderMaterialParams;
@end
