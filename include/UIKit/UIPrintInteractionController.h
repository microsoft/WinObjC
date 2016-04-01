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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>

@protocol UIPrintInteractionControllerDelegate;

@class UIPrintInteractionController;
@class UIPrintInfo;
@class UIPrintFormatter;
@class UIBarButtonItem;
@class NSError;

typedef void (^UIPrintInteractionCompletionHandler)(UIPrintInteractionController* printInteractionController,
                                                    BOOL completed,
                                                    NSError* error);
UIKIT_EXPORT NSString* const UIPrintErrorDomain;

UIKIT_EXPORT
@interface UIPrintInteractionController : NSObject

@property (nonatomic, retain) UIPrintInfo* printInfo;
@property (nonatomic, copy) id printingItem;
@property (nonatomic, assign) id<UIPrintInteractionControllerDelegate> delegate;
@property (nonatomic, retain) UIPrintFormatter* printFormatter;
@property (nonatomic) BOOL showsPageRange;

+ (UIPrintInteractionController*)sharedPrintController;
+ (BOOL)isPrintingAvailable;

- (BOOL)presentAnimated:(BOOL)animated completionHandler:(UIPrintInteractionCompletionHandler)completion;
- (void)dismissAnimated:(BOOL)animated;

- (BOOL)presentFromBarButtonItem:(UIBarButtonItem*)item
                        animated:(BOOL)animated
               completionHandler:(UIPrintInteractionCompletionHandler)completion;

@end
