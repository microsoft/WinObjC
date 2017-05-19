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
#import <UIKit/UITextInputTraits.h>
#import <UIKit/UITextInputTokenizer.h>
#import <UIKit/UIKeyInput.h>
#import <CoreGraphics/CGBase.h>

typedef enum {
    UITextLayoutDirectionRight = 2,
    UITextLayoutDirectionLeft,
    UITextLayoutDirectionUp,
    UITextLayoutDirectionDown
} UITextLayoutDirection;

typedef enum {
    UITextStorageDirectionForward = 0,
    UITextStorageDirectionBackward,
} UITextStorageDirection;

typedef enum {
    UITextWritingDirectionNatural = -1,
    UITextWritingDirectionLeftToRight = 0,
    UITextWritingDirectionRightToLeft,
} UITextWritingDirection;

UIKIT_EXPORT NSString* const UITextInputTextBackgroundColorKey;
UIKIT_EXPORT NSString* const UITextInputTextColorKey;
UIKIT_EXPORT NSString* const UITextInputTextFontKey;

@class UITextPosition, UITextRange;

@protocol UITextInput <UIKeyInput>

@property (nonatomic, readonly) UITextPosition* beginningOfDocument;
@property (readwrite, copy) UITextRange* selectedTextRange;
@property (nonatomic, readonly) UITextPosition* endOfDocument;

- (UITextPosition*)positionFromPosition:(UITextPosition*)position offset:(NSInteger)offset;
- (UITextRange*)textRangeFromPosition:(UITextPosition*)fromPosition toPosition:(UITextPosition*)toPosition;
- (CGRect)firstRectForRange:(UITextRange*)range;
- (CGRect)caretRectForPosition:(UITextPosition*)position;

@end

@protocol UITextInputDelegate <NSObject>
- (void)textWillChange:(id<UITextInput>)textInput;
- (void)textDidChange:(id<UITextInput>)textInput;
- (void)selectionWillChange:(id<UITextInput>)textInput;
- (void)selectionDidChange:(id<UITextInput>)textInput;
@end
