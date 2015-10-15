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

typedef enum _UICollectionUpdateAction {
    UICollectionUpdateActionInsert,
    UICollectionUpdateActionDelete,
    UICollectionUpdateActionReload,
    UICollectionUpdateActionMove,
    UICollectionUpdateActionNone
} _UICollectionUpdateAction;

typedef DWORD UICollectionUpdateAction;

@interface UICollectionViewUpdateItem : NSObject {
@public
    idretain _initialIndexPath; // nil for PSTCollectionUpdateActionInsert
    idretain _finalIndexPath; // nil for PSTCollectionUpdateActionDelete
    UICollectionUpdateAction _updateAction;
    id _gap;
}
- (UICollectionUpdateAction)updateAction;
- (BOOL)isSectionOperation;
/* annotate with type */ -(id)initWithAction : (UICollectionUpdateAction)updateAction forIndexPath : (id)indexPath;
/* annotate with type */ -(id)initWithInitialIndexPath : (id)initialIndexPath finalIndexPath : (id)finalIndexPath updateAction
                                                                                               : (UICollectionUpdateAction)updateAction;
/* annotate with type */ -(id)indexPathBeforeUpdate;
/* annotate with type */ -(id)setIndexPathBeforeUpdate : (id)indexPath;
/* annotate with type */ -(id)indexPathAfterUpdate;
@end
