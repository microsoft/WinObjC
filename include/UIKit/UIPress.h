//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <UIKit/UIKitExport.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CGBase.h>

@class UIResponder;
@class UIWindow;

typedef enum : NSInteger {
    UIPressPhaseBegan,
    UIPressPhaseChanged,
    UIPressPhaseStationary,
    UIPressPhaseEnded,
    UIPressPhaseCancelled,
} UIPressPhase;

typedef enum : NSInteger {
    UIPressTypeUpArrow,
    UIPressTypeDownArrow,
    UIPressTypeLeftArrow,
    UIPressTypeRightArrow,
    UIPressTypeSelect,
    UIPressTypeMenu,
    UIPressTypePlayPause,
} UIPressType;

UIKIT_EXPORT_CLASS
@interface UIPress : NSObject
@property (readonly, nonatomic) CGFloat force STUB_PROPERTY;
@property (readonly, copy, nonatomic) NSArray* gestureRecognizers STUB_PROPERTY;
@property (readonly, nonatomic, strong) UIResponder* responder STUB_PROPERTY;
@property (readonly, nonatomic, strong) UIWindow* window STUB_PROPERTY;
@property (readonly, nonatomic) UIPressType type STUB_PROPERTY;
@property (readonly, nonatomic) UIPressPhase phase STUB_PROPERTY;
@property (readonly, nonatomic) NSTimeInterval timestamp STUB_PROPERTY;
@end
