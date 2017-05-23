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

@class UIViewController;
@class UIPrintInteractionController;
@class UIPrintPaper;

typedef enum UIPrinterCutterBehavior : NSInteger {
    UIPrinterCutterBehaviorNoCut,
    UIPrinterCutterBehaviorPrinterDefault,
    UIPrinterCutterBehaviorCutAfterEachPage,
    UIPrinterCutterBehaviorCutAfterEachCopy,
    UIPrinterCutterBehaviorCutAfterEachJob,
} UIPrinterCutterBehavior;

@protocol UIPrintInteractionControllerDelegate <NSObject>
@optional
- (UIViewController*)printInteractionControllerParentViewController:(UIPrintInteractionController*)printInteractionController;
- (UIPrintPaper*)printInteractionController:(UIPrintInteractionController*)printInteractionController choosePaper:(NSArray*)paperList;
- (CGFloat)printInteractionController:(UIPrintInteractionController*)printInteractionController cutLengthForPaper:(UIPrintPaper*)paper;
- (UIPrinterCutterBehavior)printInteractionController:(UIPrintInteractionController*)printInteractionController
                                 chooseCutterBehavior:(NSArray*)availableBehaviors;
- (void)printInteractionControllerWillPresentPrinterOptions:(UIPrintInteractionController*)printInteractionController;
- (void)printInteractionControllerDidPresentPrinterOptions:(UIPrintInteractionController*)printInteractionController;
- (void)printInteractionControllerWillDismissPrinterOptions:(UIPrintInteractionController*)printInteractionController;
- (void)printInteractionControllerDidDismissPrinterOptions:(UIPrintInteractionController*)printInteractionController;
- (void)printInteractionControllerWillStartJob:(UIPrintInteractionController*)printInteractionController;
- (void)printInteractionControllerDidFinishJob:(UIPrintInteractionController*)printInteractionController;
@end
