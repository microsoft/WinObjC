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

#import <UIKit/UIKitExport.h>
#import <Foundation/NSObject.h>
#import <CoreGraphics/CGGeometry.h>

@class UIPrinterPickerController;
@class NSError;
@class UIPrinter;
@protocol UIPrinterPickerControllerDelegate;
@class UIBarButtonItem;
@class UIView;

typedef void (^UIPrinterPickerCompletionHandler)(UIPrinterPickerController* printerPickerController, BOOL userDidSelect, NSError* error);

UIKIT_EXPORT_CLASS
@interface UIPrinterPickerController : NSObject
+ (UIPrinterPickerController*)printerPickerControllerWithInitiallySelectedPrinter:(UIPrinter*)printer STUB_METHOD;
@property (nonatomic) id<UIPrinterPickerControllerDelegate> delegate STUB_PROPERTY;
- (BOOL)presentAnimated:(BOOL)animated completionHandler:(UIPrinterPickerCompletionHandler)completion STUB_METHOD;
- (BOOL)presentFromBarButtonItem:(UIBarButtonItem*)item
                        animated:(BOOL)animated
               completionHandler:(UIPrinterPickerCompletionHandler)completion STUB_METHOD;
- (BOOL)presentFromRect:(CGRect)rect
                 inView:(UIView*)view
               animated:(BOOL)animated
      completionHandler:(UIPrinterPickerCompletionHandler)completion STUB_METHOD;
- (void)dismissAnimated:(BOOL)animated STUB_METHOD;
@property (readonly, nonatomic) UIPrinter* selectedPrinter STUB_PROPERTY;
@end
