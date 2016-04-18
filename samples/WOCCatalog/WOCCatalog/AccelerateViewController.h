//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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

#import <UIKit/UIKit.h>
#import <Accelerate/Accelerate.h>


@protocol PhotoSelectorControllerDelegate <NSObject>
- (void)imageFromController:(UIImage*)image;
@end


@interface SelectorCell : UICollectionViewCell

@property (nonatomic, strong) UIImageView* imageView;

-(void)setImage:(UIImage*)image;

@end

@interface PhotoSelectorController : UICollectionViewController <UICollectionViewDataSource, UICollectionViewDelegate>

@property (weak, nonatomic) id<PhotoSelectorControllerDelegate> delegate;
@property (retain, nonatomic) UIImage* img;

@end

@interface AccelerateViewController : UITableViewController <PhotoSelectorControllerDelegate>

@end