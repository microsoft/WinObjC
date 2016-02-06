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
#import <Foundation/NSMutableAttributedString.h>

@class NSLayoutManager;

typedef enum { NSTextStorageEditedAttributes = 0x01, NSTextStorageEditedCharacters = 0x02 } _NSTextStorageEditActions;
typedef int32_t NSTextStorageEditActions;

UIKIT_EXPORT_CLASS
@interface NSTextStorage : NSMutableAttributedString
@property (nonatomic) CGSize size;

- (void)addLayoutManager:(NSLayoutManager*)manager;
@end
