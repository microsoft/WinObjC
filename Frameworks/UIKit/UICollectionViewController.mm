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

#include "Starboard.h"

#include "Foundation/NSString.h"
#include "CoreGraphics/CGGeometry.h"
#include "UIKit/UICollectionView.h"
#include "UIKit/UICollectionViewController.h"
#include "UIKit/UIView.h"
#include "UIKit/UIViewController.h"

@implementation UICollectionViewController : UIViewController
- (id)initWithCoder:(id)coder {
    return [super initWithCoder:coder];
}

- (void)loadView {
    [super loadView];

    if ([[self view] isKindOfClass:[UICollectionView class]]) {
        _collectionView = [self view];
        CGRect curBounds = { 0 };
        curBounds = [[self view] bounds];

        [self setView:[[UIView alloc] initWithFrame:curBounds]];
        [_collectionView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    }

    if ([_collectionView delegate] == nil) {
        [_collectionView setDelegate:(id<UIScrollViewDelegate>)self];
    }
    if ([_collectionView dataSource] == nil) {
        [_collectionView setDataSource:(UICollectionViewDataSource*)self];
    }

    // only create the collection view if it is not already created (by IB)
    if (!_collectionView) {
        CGRect curBounds = { 0 };
        curBounds = [[self view] bounds];

        _collectionView = [[UICollectionView alloc] initWithFrame:curBounds collectionViewLayout:[self layout]];
        [_collectionView setDelegate:(id<UIScrollViewDelegate>)self];
        [_collectionView setDataSource:(UICollectionViewDataSource*)self];
    }
}

- (BOOL)viewDidLoad {
    [super viewDidLoad];

    // This seems like a hack, but is needed for real compatibility
    // There can be implementations of loadView that don't call super and don't set the view, yet it works in
    // UICollectionViewController.
    if (![self isViewLoaded]) {
        [self setView:[[UIView alloc] initWithFrame:CGRectZero]];
    }

    // Attach the view
    if ([self view] != [self collectionView]) {
        [[self view] addSubview:[self collectionView]];

        CGRect curBounds = { 0 };
        curBounds = [[self view] bounds];

        [_collectionView setFrame:curBounds];
        [_collectionView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
    }
    return 0;
}

/**
 @Status Interoperable
*/
- (id)collectionView {
    if (!_collectionView) {
        CGRect mainScreenBounds;

        mainScreenBounds = [[UIScreen mainScreen] bounds];
        _collectionView = [[UICollectionView alloc] initWithFrame:mainScreenBounds collectionViewLayout:[self layout]];
        [_collectionView setDelegate:(id<UIScrollViewDelegate>)self];
        [_collectionView setDataSource:(UICollectionViewDataSource*)self];

        // If the collection view isn't the main view, add it.
        if ([self isViewLoaded] && [self view] != _collectionView) {
            [[self view] addSubview:(id)_collectionView];

            CGRect curBounds = { 0 };
            curBounds = [[self view] bounds];

            [_collectionView setFrame:curBounds];
            [_collectionView setAutoresizingMask:UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight];
        }
    }
    return _collectionView;
}

@end
