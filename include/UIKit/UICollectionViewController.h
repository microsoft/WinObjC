//******************************************************************************
//
// UICollectionViewController.h
// PSPDFKit
//
// Copyright (c) 2012-2013 Peter Steinberger. All rights reserved.
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

#import <UIKit/UIKit.h>
#import <UIKit/UIKitExport.h>

@class UICollectionView;
@class UICollectionViewLayout;
@class UICollectionViewController;

// Simple controller-wrapper around UICollectionView.
UIKIT_EXPORT_CLASS
@interface UICollectionViewController : UIViewController <UICollectionViewDelegate, UICollectionViewDataSource>

// Designated initializer.
- (id)initWithCollectionViewLayout:(UICollectionViewLayout*)layout;

// Internally used collection view. If not set, created during loadView.
@property (nonatomic, strong) UICollectionView* collectionView;

// Defaults to YES, and if YES, any selection is cleared in viewWillAppear:
@property (nonatomic, assign) BOOL clearsSelectionOnViewWillAppear;

@end
