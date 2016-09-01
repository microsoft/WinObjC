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
#import <Foundation/NSMutableAttributedString.h>
#import <CoreGraphics/CGBase.h>

@class NSLayoutManager;
@protocol NSTextStorageDelegate;

typedef enum {
    NSTextStorageEditedAttributes = 0x01,
    NSTextStorageEditedCharacters = 0x02,
} _NSTextStorageEditActions;
typedef int32_t NSTextStorageEditActions;

UIKIT_EXPORT NSString* const NSTextStorageDidProcessEditingNotification;
UIKIT_EXPORT NSString* const NSTextStorageWillProcessEditingNotification;

UIKIT_EXPORT_CLASS
@interface NSTextStorage : NSMutableAttributedString
@property (nonatomic) CGSize size;
@property (assign, nonatomic) id<NSTextStorageDelegate> delegate STUB_PROPERTY;
@property (readonly, nonatomic) NSTextStorageEditActions editedMask STUB_PROPERTY;
@property (readonly, nonatomic) NSInteger changeInLength STUB_PROPERTY;
@property (readonly, nonatomic) NSRange editedRange STUB_PROPERTY;
- (void)edited:(NSTextStorageEditActions)editedMask range:(NSRange)editedRange changeInLength:(NSInteger)delta STUB_METHOD;
- (void)ensureAttributesAreFixedInRange:(NSRange)range STUB_METHOD;
@property (readonly, nonatomic) BOOL fixesAttributesLazily STUB_PROPERTY;
- (void)invalidateAttributesInRange:(NSRange)range STUB_METHOD;
- (void)processEditing;
- (void)addLayoutManager:(NSLayoutManager*)manager;
- (void)removeLayoutManager:(NSLayoutManager*)aLayoutManager STUB_METHOD;
@property (readonly, copy, nonatomic) NSArray* layoutManagers STUB_PROPERTY;
@end
