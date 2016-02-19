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

#import <AVFoundation/AVFoundationExport.h>
#import <QuartzCore/CAMediaTiming.h>
#import <Foundation/NSObject.h>
#import <QuartzCore/CALayer.h>

@class AVPlayer;
@class NSString;

AVFOUNDATION_EXPORT_CLASS
@interface AVPlayerLayer : CALayer <CAMediaTiming, NSCoding>
+ (AVPlayerLayer*)playerLayerWithPlayer:(AVPlayer*)player STUB_METHOD;
@property (retain, nonatomic) AVPlayer* player STUB_PROPERTY;
@property (readonly, getter=isReadyForDisplay, nonatomic) BOOL readyForDisplay STUB_PROPERTY;
@property (copy) NSString* videoGravity STUB_PROPERTY;
@property (readonly, nonatomic) CGRect videoRect STUB_PROPERTY;
@end
