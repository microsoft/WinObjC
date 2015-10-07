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

#ifndef _CAMEDIATIMING_H_
#define _CAMEDIATIMING_H_

#import <Foundation/NSString.h>
#import <QuartzCore/CABase.h>
#import <QuartzCore/CoreAnimationExport.h>

CA_EXPORT NSString * const kCAFillModeRemoved;
CA_EXPORT NSString * const kCAFillModeForwards;
CA_EXPORT NSString * const kCAFillModeBackwards;
CA_EXPORT NSString * const kCAFillModeBoth;
CA_EXPORT NSString * const kCAFillModeFrozen;

@protocol CAMediaTiming

@property BOOL autoreverses;
@property CFTimeInterval beginTime;
@property CFTimeInterval duration;
@property(copy) NSString *fillMode;
@property float repeatCount;
@property CFTimeInterval repeatDuration;
@property float speed;
@property CFTimeInterval timeOffset;

@end

#endif // _CAMEDIATIMING_H_