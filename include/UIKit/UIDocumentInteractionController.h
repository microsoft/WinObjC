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

#import "UIKitExport.h"
#import <UIKit/UIActionSheet.h>

@protocol UIDocumentInteractionControllerDelegate;

UIKIT_EXPORT_CLASS
@interface UIDocumentInteractionController : NSObject <UIActionSheetDelegate>

@property (nonatomic, assign) id<UIDocumentInteractionControllerDelegate> delegate;

+ (UIDocumentInteractionController*)interactionControllerWithURL:(NSURL*)url;

- (BOOL)presentPreviewAnimated:(BOOL)animated;

@end
