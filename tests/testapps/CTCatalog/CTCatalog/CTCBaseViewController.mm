//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
//*****************************************************************************

#import "CTCBaseViewController.h"

UITableViewCell* createTextCell(NSString* title, NSString* value) {
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.textLabel.text = title;
    UILabel* textLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 200, 20)];
    textLabel.text = value;
    cell.accessoryView = textLabel;
    return cell;
}

@interface CTCBaseViewController ()

@end

@implementation CTCBaseViewController

- (instancetype)init {
    if (self = [super init]) {
        self.title = [[NSStringFromClass([self class]) stringByReplacingOccurrencesOfString:@"CTC" withString:@""]
            stringByReplacingOccurrencesOfString:@"ViewController"
                                      withString:@""];
    }
    return self;
}
- (void)loadView {
    CGRect frame = self.navigationController.view.bounds;
    frame.size.height = frame.size.height - CGRectGetMaxY(self.navigationController.navigationBar.frame);
    UIView* view = [[UIView alloc] initWithFrame:frame];
    self.view = view;

    self.view.backgroundColor = [UIColor whiteColor];
    self.edgesForExtendedLayout = UIRectEdgeNone;
}

@end
