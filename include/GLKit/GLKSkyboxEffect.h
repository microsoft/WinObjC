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
@property (readonly, nonatomic) GLKEffectPropertyTexture* textureCubeMap;

@property (assign, nonatomic) GLKVector3 center;
@property (assign, nonatomic) GLfloat xSize;
@property (assign, nonatomic) GLfloat ySize;
@property (assign, nonatomic) GLfloat zSize;

@property (retain) GLKShader* shader;
@property (retain) NSString* shaderName;

@property (readonly, nonatomic) GLKEffectPropertyTransform* transform STUB_PROPERTY;
@property (copy, nonatomic) NSString* label STUB_PROPERTY;

- (void)prepareToDraw;
- (void)draw;

- (BOOL)updateShaderMaterialParams;
@end
