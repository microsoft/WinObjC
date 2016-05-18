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

#import "CACompositor.h"

@interface CATransaction (Internal)

+ (std::shared_ptr<DisplayTransaction>)_currentDisplayTransaction;

+ (void)_addSublayerToLayer:(CALayer*)layer sublayer:(CALayer*)sublayer;
+ (void)_addSublayerToLayer:(CALayer*)layer sublayer:(CALayer*)sublayer before:(CALayer*)before;
+ (void)_addSublayerToLayer:(CALayer*)layer sublayer:(CALayer*)sublayer after:(CALayer*)after;
+ (void)_addSublayerToTop:(CALayer*)layer;

+ (void)_replaceInLayer:(CALayer*)layer sublayer:(CALayer*)sublayer withSublayer:(CALayer*)newlayer;
+ (void)_moveLayer:(CALayer*)layer beforeLayer:(CALayer*)before afterLayer:(CALayer*)after;
+ (void)_removeLayer:(CALayer*)layer;

+ (void)_addAnimationToLayer:(CALayer*)layer animation:(CAAnimation*)anim forKey:(NSString*)key;
+ (CAAnimation*)_implicitAnimationForKey:(NSString*)forKey;
+ (void)_commitRootQueue;

+ (void)_setPropertyForLayer:(CALayer*)layer name:(NSString*)propertyName value:(NSObject*)newValue;
+ (void)_addSublayerToTop:(CALayer*)layer;
+ (void)_removeAnimationFromLayer:(CALayer*)layer animation:(DisplayAnimation*)anim;
@end
