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

@class UITabBar;
@class NSArray;
@class UITabBarItem;

@protocol UITabBarDelegate <NSObject>
@optional
- (void)tabBar:(UITabBar*)tabBar willBeginCustomizingItems:(NSArray*)items;
- (void)tabBar:(UITabBar*)tabBar didBeginCustomizingItems:(NSArray*)items;
- (void)tabBar:(UITabBar*)tabBar willEndCustomizingItems:(NSArray*)items changed:(BOOL)changed;
- (void)tabBar:(UITabBar*)tabBar didEndCustomizingItems:(NSArray*)items changed:(BOOL)changed;
- (void)tabBar:(UITabBar*)tabBar didSelectItem:(UITabBarItem*)item;
@end
