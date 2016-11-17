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

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, MoveDirection) { MoveUp = 0, MoveDown };

@protocol LayerTableViewCellDelegate <NSObject>

@optional
- (void) cellWithLayer:(CALayer*)layer shouldMove:(MoveDirection)direction;

@end

@interface LayerTableViewCell : UITableViewCell

- (void)setUpWithLayer:(CALayer*)layer
              andTitle:(NSString*)title
    shouldShowUpButton:(BOOL)showUpButton
  shouldShowDownButton:(BOOL)showDownButton;

@property (nonatomic, assign) id<LayerTableViewCellDelegate> delegate;

@end
