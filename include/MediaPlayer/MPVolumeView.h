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

#import <MediaPlayer/MediaPlayerExport.h>
#import <UIKit/UIAppearance.h>
#import <UIKit/UIView.h>
#import <UIKit/UIControl.h>

@class UIImage;

MEDIAPLAYER_EXPORT_CLASS
@interface MPVolumeView : UIView <NSCoding, UIAppearance, UIAppearanceContainer>

@property (nonatomic) BOOL showsVolumeSlider STUB_PROPERTY;
@property (nonatomic) BOOL showsRouteButton STUB_PROPERTY;

- (CGSize)sizeThatFits:(CGSize)size STUB_METHOD;
- (UIImage*)maximumVolumeSliderImageForState:(UIControlState)state STUB_METHOD;
- (UIImage*)minimumVolumeSliderImageForState:(UIControlState)state STUB_METHOD;
- (void)setMaximumVolumeSliderImage:(UIImage*)image forState:(UIControlState)state STUB_METHOD;
- (void)setMinimumVolumeSliderImage:(UIImage*)image forState:(UIControlState)state STUB_METHOD;
- (void)setVolumeThumbImage:(UIImage*)image forState:(UIControlState)state STUB_METHOD;
- (CGRect)volumeSliderRectForBounds:(CGRect)bounds STUB_METHOD;
- (UIImage*)volumeThumbImageForState:(UIControlState)state STUB_METHOD;
- (CGRect)volumeThumbRectForBounds:(CGRect)bounds volumeSliderRect:(CGRect)rect value:(float)value STUB_METHOD;
- (UIImage*)routeButtonImageForState:(UIControlState)state STUB_METHOD;
- (CGRect)routeButtonRectForBounds:(CGRect)bounds STUB_METHOD;
- (void)setRouteButtonImage:(UIImage*)image forState:(UIControlState)state STUB_METHOD;

@end
