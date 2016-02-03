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
#import <QuartzCore/CAMediaTiming.h>
#import <QuartzCore/CALayer.h>

@class NSString;

CA_EXPORT NSString* const kCAScrollNone;
CA_EXPORT NSString* const kCAScrollVertically;
CA_EXPORT NSString* const kCAScrollHorizontally;
CA_EXPORT NSString* const kCAScrollBoth;

CA_EXPORT_CLASS
@interface CAScrollLayer : CALayer <CAMediaTiming, NSCoding>
@property (copy) NSString* scrollMode STUB_PROPERTY;
- (void)scrollToPoint:(CGPoint)thePoint STUB_METHOD;
- (void)scrollToRect:(CGRect)theRect STUB_METHOD;
@end
