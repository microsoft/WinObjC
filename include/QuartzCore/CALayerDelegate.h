//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <QuartzCore/CoreAnimationExport.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGContext.h>

@class CALayer;
@protocol CAAction;
@class NSString;

@interface NSObject (CALayerDelegate)
- (void)displayLayer:(CALayer*)layer;
- (void)drawLayer:(CALayer*)layer inContext:(CGContextRef)ctx;
- (void)layoutSublayersOfLayer:(CALayer*)layer;
- (id<CAAction>)actionForLayer:(CALayer*)layer forKey:(NSString*)key;
@end
