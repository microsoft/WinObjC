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

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UIEventType) {
    UIEventTypeTouches,
    UIEventTypeMotion,
    UIEventTypeRemoteControl,
    UIEventTypePresses,
};

typedef NS_ENUM(NSInteger, UIEventSubtype) {
    UIEventSubtypeNone = 0,
    UIEventSubtypeMotionShake = 1,
    UIEventSubtypeRemoteControlPlay = 100,
    UIEventSubtypeRemoteControlPause = 101,
    UIEventSubtypeRemoteControlStop = 102,
    UIEventSubtypeRemoteControlTogglePlayPause = 103,
    UIEventSubtypeRemoteControlNextTrack = 104,
    UIEventSubtypeRemoteControlPreviousTrack = 105,
    UIEventSubtypeRemoteControlBeginSeekingBackward = 106,
    UIEventSubtypeRemoteControlEndSeekingBackward = 107,
    UIEventSubtypeRemoteControlBeginSeekingForward = 108,
    UIEventSubtypeRemoteControlEndSeekingForward = 109,
};

@class UITouch, UIWindow, UIView, UIGestureRecognizer;

@interface UIEvent : NSObject

- (NSSet<UITouch*>*)allTouches;
- (NSSet<UITouch*>*)touchesForView:(UIView*)view;
- (NSSet<UITouch*>*)touchesForWindow:(UIWindow*)window;
- (NSSet<UITouch*>*)touchesForGestureRecognizer:(UIGestureRecognizer*)gesture;

@property (nonatomic, readonly) UIEventType type;
@property (nonatomic, readonly) UIEventSubtype subtype;
@property (nonatomic, readonly) NSTimeInterval timestamp;

@end
