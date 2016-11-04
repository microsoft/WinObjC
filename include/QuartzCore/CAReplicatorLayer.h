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
#import <QuartzCore/CAMediaTiming.h>
#import <QuartzCore/CALayer.h>

CA_EXPORT_CLASS
@interface CAReplicatorLayer : CALayer <CAMediaTiming, NSCoding>

@property NSInteger instanceCount STUB_PROPERTY;
@property CFTimeInterval instanceDelay STUB_PROPERTY;
@property CATransform3D instanceTransform STUB_PROPERTY;
@property BOOL preservesDepth STUB_PROPERTY;
@property CGColorRef instanceColor STUB_PROPERTY;
@property float instanceRedOffset STUB_PROPERTY;
@property float instanceGreenOffset STUB_PROPERTY;
@property float instanceBlueOffset STUB_PROPERTY;
@property float instanceAlphaOffset STUB_PROPERTY;

@end
