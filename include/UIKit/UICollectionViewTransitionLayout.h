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
#import <UIKit/UICollectionViewLayout.h>
#import <Foundation/NSObject.h>

@class UICollectionViewLayout;
@class NSString;

UIKIT_EXPORT_CLASS
@interface UICollectionViewTransitionLayout : UICollectionViewLayout
- (id)initWithCurrentLayout:(UICollectionViewLayout*)currentLayout nextLayout:(UICollectionViewLayout*)newLayout STUB_METHOD;
@property (assign, nonatomic) CGFloat transitionProgress STUB_PROPERTY;
- (void)updateValue:(CGFloat)value forAnimatedKey:(NSString*)key STUB_METHOD;
- (CGFloat)valueForAnimatedKey:(NSString*)key STUB_METHOD;
@property (readonly, nonatomic) UICollectionViewLayout* currentLayout STUB_PROPERTY;
@property (readonly, nonatomic) UICollectionViewLayout* nextLayout STUB_PROPERTY;
@end
