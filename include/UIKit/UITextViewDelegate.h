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
#import <UIKit/UIScrollViewDelegate.h>
#import <Foundation/Foundation.h>

@class UITextView;
@class NSString;
@class NSTextAttachment;
@class NSURL;

@protocol UITextViewDelegate <UIScrollViewDelegate>
@optional
- (BOOL)textViewShouldBeginEditing:(UITextView*)textView;
- (void)textViewDidBeginEditing:(UITextView*)textView;
- (BOOL)textViewShouldEndEditing:(UITextView*)textView;
- (void)textViewDidEndEditing:(UITextView*)textView;
- (BOOL)textView:(UITextView*)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString*)text;
- (void)textViewDidChange:(UITextView*)textView;
- (void)textViewDidChangeSelection:(UITextView*)textView;
- (BOOL)textView:(UITextView*)textView shouldInteractWithTextAttachment:(NSTextAttachment*)textAttachment inRange:(NSRange)characterRange;
- (BOOL)textView:(UITextView*)textView shouldInteractWithURL:(NSURL*)URL inRange:(NSRange)characterRange;
@end
