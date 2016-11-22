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

#import <QuartzCore/CoreAnimationExport.h>
#import <QuartzCore/CALayer.h>
#import <QuartzCore/CAMediaTiming.h>

CA_EXPORT NSString* const kCAEmitterLayerPoint;
CA_EXPORT NSString* const kCAEmitterLayerLine;
CA_EXPORT NSString* const kCAEmitterLayerRectangle;
CA_EXPORT NSString* const kCAEmitterLayerCuboid;
CA_EXPORT NSString* const kCAEmitterLayerCircle;
CA_EXPORT NSString* const kCAEmitterLayerSphere;
CA_EXPORT NSString* const kCAEmitterLayerPoints;
CA_EXPORT NSString* const kCAEmitterLayerOutline;
CA_EXPORT NSString* const kCAEmitterLayerSurface;
CA_EXPORT NSString* const kCAEmitterLayerVolume;
CA_EXPORT NSString* const kCAEmitterLayerUnordered;
CA_EXPORT NSString* const kCAEmitterLayerOldestFirst;
CA_EXPORT NSString* const kCAEmitterLayerOldestLast;
CA_EXPORT NSString* const kCAEmitterLayerBackToFront;
CA_EXPORT NSString* const kCAEmitterLayerAdditive;

@class NSArray;
@class CAEmitterCell;
@class NSString;

CA_EXPORT_CLASS
@interface CAEmitterLayer : CALayer <CAMediaTiming, NSCoding>

@property (copy) NSArray* emitterCells;
@property (copy) NSString* renderMode STUB_PROPERTY;
@property CGPoint emitterPosition;
@property (copy) NSString* emitterShape STUB_PROPERTY;
@property CGFloat emitterZPosition STUB_PROPERTY;
@property CGFloat emitterDepth STUB_PROPERTY;
@property CGSize emitterSize STUB_PROPERTY;
@property float scale STUB_PROPERTY;
@property unsigned int seed STUB_PROPERTY;
@property float spin STUB_PROPERTY;
@property float velocity STUB_PROPERTY;
@property float birthRate STUB_PROPERTY;
@property (copy) NSString* emitterMode STUB_PROPERTY;
@property float lifetime STUB_PROPERTY;
@property BOOL preservesDepth STUB_PROPERTY;

@end
