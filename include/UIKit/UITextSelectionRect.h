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
#import <UIKit/UITextInput.h>

UIKIT_EXPORT_CLASS
@interface UITextSelectionRect : NSObject
@property (readonly, nonatomic) CGRect rect STUB_PROPERTY;
@property (readonly, nonatomic) UITextWritingDirection writingDirection STUB_PROPERTY;
@property (readonly, nonatomic) BOOL isVertical STUB_PROPERTY;
@property (readonly, nonatomic) BOOL containsStart STUB_PROPERTY;
@property (readonly, nonatomic) BOOL containsEnd STUB_PROPERTY;
@end
