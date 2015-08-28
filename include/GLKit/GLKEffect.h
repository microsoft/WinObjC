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

@protocol GLKNamedEffect
-(void)prepareToDraw;
@end

GLKIT_EXPORT_CLASS
@interface GLKBaseEffect : NSObject
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectProperty : NSObject
@end

GLKIT_EXPORT_CLASS
@interface GLKReflectionMapEffect : GLKBaseEffect
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyFog : GLKEffectProperty
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyLight : GLKEffectProperty
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyMaterial : GLKEffectProperty
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTexture : GLKEffectProperty
@end

GLKIT_EXPORT_CLASS
@interface GLKEffectPropertyTransform : GLKEffectProperty
@end

