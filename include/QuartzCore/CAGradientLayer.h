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

@class NSString;
@class NSArray;

CA_EXPORT NSString* const kCAGradientLayerAxial;

CA_EXPORT_CLASS
@interface CAGradientLayer : CALayer <CAMediaTiming, NSCoding>

@property (copy) NSArray* colors STUB_PROPERTY;
@property (copy) NSArray* locations STUB_PROPERTY;
@property CGPoint endPoint STUB_PROPERTY;
@property CGPoint startPoint STUB_PROPERTY;
@property (copy) NSString* type STUB_PROPERTY;

@end
