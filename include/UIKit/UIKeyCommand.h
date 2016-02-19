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

@class NSString;

typedef enum {
    UIKeyModifierAlphaShift = 1 << 16,
    UIKeyModifierShift = 1 << 17,
    UIKeyModifierControl = 1 << 18,
    UIKeyModifierAlternate = 1 << 19,
    UIKeyModifierCommand = 1 << 20,
    UIKeyModifierNumericPad = 1 << 21,
} UIKeyModifierFlags;

UIKIT_EXPORT NSString* const UIKeyInputUpArrow;
UIKIT_EXPORT NSString* const UIKeyInputDownArrow;
UIKIT_EXPORT NSString* const UIKeyInputLeftArrow;
UIKIT_EXPORT NSString* const UIKeyInputRightArrow;
UIKIT_EXPORT NSString* const UIKeyInputEscape;

UIKIT_EXPORT_CLASS
@interface UIKeyCommand : NSObject <NSCopying, NSObject, NSSecureCoding>
+ (UIKeyCommand*)keyCommandWithInput:(NSString*)input
                       modifierFlags:(UIKeyModifierFlags)modifierFlags
                              action:(SEL)action
                discoverabilityTitle:(NSString*)discoverabilityTitle STUB_METHOD;
+ (UIKeyCommand*)keyCommandWithInput:(NSString*)input modifierFlags:(UIKeyModifierFlags)modifierFlags action:(SEL)action STUB_METHOD;
@property (readonly, nonatomic) NSString* input STUB_PROPERTY;
@property (readonly, nonatomic) UIKeyModifierFlags modifierFlags STUB_PROPERTY;
@property (copy, nonatomic) NSString* discoverabilityTitle STUB_PROPERTY;
@end
