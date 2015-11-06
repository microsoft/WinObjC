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

#ifndef _UIACTIVITYVIEWCONTROLLER_H_
#define _UIACTIVITYVIEWCONTROLLER_H_

#import <UIKit/UIViewController.h>

@class NSString;

typedef void (^UIActivityViewControllerCompletionHandler)(NSString* activityType, BOOL completed);

@class UIPopoverPresentationController;

UIKIT_EXPORT_CLASS
@interface UIActivityViewController : UIViewController

- (id)initWithActivityItems:(NSArray*)activityItems applicationActivities:(NSArray*)applicationActivities;

@property (nonatomic, copy) UIActivityViewControllerCompletionHandler completionHandler;
@property (nonatomic, copy) NSArray* excludedActivityTypes;
@property (nonatomic, retain) UIPopoverPresentationController* popoverPresentationController;

@end

#endif /* _UIACTIVITYVIEWCONTROLLER_H_ */