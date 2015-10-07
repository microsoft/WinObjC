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

@class GLKViewController;

@protocol GLKViewControllerDelegate
-(void)glkViewController: (GLKViewController*)controller willPause:(BOOL)paused;
-(void)glkViewControllerUpdate: (GLKViewController*)controller;
@end

// --------------------------------------------------------------------------------

GLKIT_EXPORT_CLASS
@interface GLKViewController : UIViewController

@property id<GLKViewControllerDelegate> delegate;

@property (readonly) NSTimeInterval     timeSinceFirstResume;
@property (readonly) NSTimeInterval     timeSinceLastResume;
@property (readonly) NSTimeInterval     timeSinceLastUpdate;
@property (readonly) NSTimeInterval     timeSinceLastDraw;

@property (readonly) unsigned int       framesDisplayed;
@property (readonly) unsigned int       framesPerSecond;
@property unsigned int                  preferredFramesPerSecond;

@property BOOL paused;
@property BOOL pauseOnWillResignActive;  // TODO: BK: should both be true.
@property BOOL resumeOnDidBecomeActive;

// ----------------------------------------


@end

