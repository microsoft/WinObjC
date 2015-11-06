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

#ifndef _UICOLLECTIONVIEWCONTROLLER_H_
#define _UICOLLECTIONVIEWCONTROLLER_H_

#import "UIKitExport.h"
#import <UIKit/UIViewController.h>

@class UICollectionView;
@class UICollectionViewLayout;

UIKIT_EXPORT_CLASS
@interface UICollectionViewController : UIViewController

@property (nonatomic, retain) UICollectionView* collectionView;

- (id)initWithCollectionViewLayout:(UICollectionViewLayout*)layout;

@end

#endif /* _UICOLLECTIONVIEWCONTROLLER_H_ */