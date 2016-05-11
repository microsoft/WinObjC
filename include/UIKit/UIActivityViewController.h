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

#import <UIKit/UIViewController.h>

@class NSString;

typedef void (^UIActivityViewControllerCompletionHandler)(NSString* activityType, BOOL completed);

@class UIPopoverPresentationController;

UIKIT_EXPORT_CLASS
@interface UIActivityViewController : UIViewController

- (instancetype)initWithActivityItems:(NSArray*)activityItems applicationActivities:(NSArray*)applicationActivities STUB_METHOD;

@property (nonatomic, copy) UIActivityViewControllerCompletionHandler completionHandler STUB_PROPERTY;
@property (nonatomic, copy) NSArray* excludedActivityTypes STUB_PROPERTY;

@end
