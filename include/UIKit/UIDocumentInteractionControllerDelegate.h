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
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>

@class UIViewController;
@class UIDocumentInteractionController;
@class UIView;
@class NSString;

@protocol UIDocumentInteractionControllerDelegate <NSObject>
@optional
- (UIViewController*)documentInteractionControllerViewControllerForPreview:(UIDocumentInteractionController*)controller;
- (UIView*)documentInteractionControllerViewForPreview:(UIDocumentInteractionController*)controller;
- (CGRect)documentInteractionControllerRectForPreview:(UIDocumentInteractionController*)controller;
- (void)documentInteractionControllerWillBeginPreview:(UIDocumentInteractionController*)controller;
- (void)documentInteractionControllerDidEndPreview:(UIDocumentInteractionController*)controller;
- (void)documentInteractionControllerWillPresentOptionsMenu:(UIDocumentInteractionController*)controller;
- (void)documentInteractionControllerDidDismissOptionsMenu:(UIDocumentInteractionController*)controller;
- (void)documentInteractionControllerWillPresentOpenInMenu:(UIDocumentInteractionController*)controller;
- (void)documentInteractionControllerDidDismissOpenInMenu:(UIDocumentInteractionController*)controller;
- (void)documentInteractionController:(UIDocumentInteractionController*)controller willBeginSendingToApplication:(NSString*)application;
- (void)documentInteractionController:(UIDocumentInteractionController*)controller didEndSendingToApplication:(NSString*)application;
- (BOOL)documentInteractionController:(UIDocumentInteractionController*)controller canPerformAction:(SEL)action;
- (BOOL)documentInteractionController:(UIDocumentInteractionController*)controller performAction:(SEL)action;
@end
