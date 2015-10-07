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

#ifndef _CAREPLICATORLAYER_H_
#define _CAREPLICATORLAYER_H_

#import <QuartzCore/CALayer.h>
#import <QuartzCore/CATransform3D.h>

@interface CAReplicatorLayer : CALayer

@property CATransform3D instanceTransform;
@property NSInteger instanceCount;
@property float instanceRedOffset;
@property float instanceGreenOffset;
@property float instanceBlueOffset;

@end

#endif /* _CAREPLICATORLAYER_H_ */