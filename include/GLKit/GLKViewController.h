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

#import <OpenGLES/ES2/gl.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKitExport.h>
#import <GLKit/GLKView.h>

@class GLKViewController;

@protocol GLKViewControllerDelegate <NSObject>

/**
 @Status Interoperable
*/
- (void)glkViewController:(GLKViewController*)controller willPause:(BOOL)paused;

/**
 @Status Interoperable
*/
- (void)glkViewControllerUpdate:(GLKViewController*)controller;
@end

// --------------------------------------------------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKViewController : UIViewController <GLKViewDelegate,
                                                 NSCoding,
                                                 NSObject,
                                                 UIAppearanceContainer,
                                                 UIContentContainer,
                                                 UIFocusEnvironment,
                                                 UITraitEnvironment>

@property (assign, nonatomic) id<GLKViewControllerDelegate> delegate;

@property (readonly, nonatomic) NSTimeInterval timeSinceFirstResume;
@property (readonly, nonatomic) NSTimeInterval timeSinceLastResume;
@property (readonly, nonatomic) NSTimeInterval timeSinceLastUpdate;
@property (readonly, nonatomic) NSTimeInterval timeSinceLastDraw;

@property (readonly, nonatomic) NSInteger framesDisplayed;
@property (readonly, nonatomic) NSInteger framesPerSecond;
@property (nonatomic) NSInteger preferredFramesPerSecond;

@property (getter=isPaused, nonatomic) BOOL paused;
@property (nonatomic) BOOL pauseOnWillResignActive; // TODO: BK: should both be true.
@property (nonatomic) BOOL resumeOnDidBecomeActive;

// ----------------------------------------

@end
