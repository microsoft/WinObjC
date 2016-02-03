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

#import <AVKit/AVKitExport.h>
#import <UIKit/UIAppearanceContainer.h>
#import <UIKit/UIFocusEnvironment.h>
#import <UIKit/UITraitEnvironment.h>
#import <UIKit/UIViewController.h>

@class AVPlayer;
@protocol AVPlayerViewControllerDelegate;
@protocol UIContentContainer;
@class UIView;
@class NSString;

AVKIT_EXPORT_CLASS
@interface AVPlayerViewController
    : UIViewController <NSCoding, UIAppearanceContainer, UIContentContainer, UIFocusEnvironment, UITraitEnvironment>
@property (nonatomic, strong) AVPlayer* player STUB_PROPERTY;
@property (nonatomic, weak) id<AVPlayerViewControllerDelegate> delegate STUB_PROPERTY;
@property (nonatomic) BOOL showsPlaybackControls STUB_PROPERTY;
@property (nonatomic) BOOL allowsPictureInPicturePlayback STUB_PROPERTY;
@property (readonly, nonatomic) UIView* contentOverlayView STUB_PROPERTY;
@property (readonly, getter=isReadyForDisplay, nonatomic) BOOL readyForDisplay STUB_PROPERTY;
@property (readonly, nonatomic) CGRect videoBounds STUB_PROPERTY;
@property (copy, nonatomic) NSString* videoGravity STUB_PROPERTY;
@property (nonatomic, weak, readonly) UIView* preferredFocusedView STUB_PROPERTY;
@property (nonatomic, readonly) UITraitCollection* traitCollection STUB_PROPERTY;
@end
