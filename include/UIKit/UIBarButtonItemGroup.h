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

@class NSArray;
@class UIBarButtonItem;

UIKIT_EXPORT_CLASS
@interface UIBarButtonItemGroup : NSObject <NSCoding>
- (instancetype)initWithBarButtonItems:(NSArray*)barButtonItems representativeItem:(UIBarButtonItem*)representativeItem STUB_METHOD;
@property (readwrite, copy, nonatomic) NSArray* barButtonItems STUB_PROPERTY;
@property (readwrite, nonatomic, strong) UIBarButtonItem* representativeItem STUB_PROPERTY;
@property (readonly, getter=isDisplayingRepresentativeItem, assign, nonatomic) BOOL displayingRepresentativeItem STUB_PROPERTY;
@end
