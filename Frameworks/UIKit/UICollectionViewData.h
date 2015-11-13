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

@interface UICollectionViewData : NSObject {
@public
    CGRect _validLayoutRect;
    UICollectionView* _collectionView;
    UICollectionViewFlowLayout* _layout;
    idretain _cachedLayoutAttributes;
    CGSize _contentSize;
    struct {
        unsigned int contentSizeIsValid : 1;
        unsigned int itemCountsAreValid : 1;
        unsigned int layoutIsPrepared : 1;
    } _collectionViewDataFlags;

    NSInteger _numItems;
    NSInteger _numSections;
    NSInteger* _sectionItemCounts;
}
- (BOOL)_filterAttribs:(id)evaluatedObject bindings:(id)bindings;
- (void)validateItemCounts;
- (BOOL)layoutIsPrepared;
- (unsigned)numberOfSections;
- (unsigned)numberOfItems;
- (unsigned)numberOfItemsInSection:(int)section;
- (unsigned)numberOfItemsBeforeSection:(int)section;
- (unsigned)globalIndexForItemAtIndexPath:(id)indexPath;
- (CGRect)collectionViewContentRect;
- (id)initWithCollectionView:(id)collectionView layout:(id)layout;
- (id)validateLayoutInRect:(CGRect)rect;
- (id)setLayoutIsPrepared:(BOOL)layoutIsPrepared;
- (id)setContentSize:(CGSize)size;
- (id)prepareToLoadData;
- (id)layoutAttributesForElementsInRect:(CGRect)rect;
- (id)updateItemCounts;
- (id)invalidate;
- (id)indexPathForItemAtGlobalIndex:(NSInteger)index;
@end
