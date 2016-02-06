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

@class UIView;

typedef enum {
    UIFocusHeadingUp = 1 << 0,
    UIFocusHeadingDown = 1 << 1,
    UIFocusHeadingLeft = 1 << 2,
    UIFocusHeadingRight = 1 << 3,
    UIFocusHeadingNext = 1 << 4,
    UIFocusHeadingPrevious = 1 << 5,
} UIFocusHeading;

UIKIT_EXPORT_CLASS
@interface UIFocusUpdateContext : NSObject
@property (readonly, nonatomic) UIView* previouslyFocusedView STUB_PROPERTY;
@property (readonly, nonatomic) UIView* nextFocusedView STUB_PROPERTY;
@property (readonly, assign, nonatomic) UIFocusHeading focusHeading STUB_PROPERTY;
@end
