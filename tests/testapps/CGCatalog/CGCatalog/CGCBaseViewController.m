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
//******************************************************************************

#import "CGCBaseViewController.h"

@interface CGCBaseViewController ()

@end

@implementation CGCBaseViewController {
    BOOL _drawComparisonImage;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        self.title = [[NSStringFromClass([self class]) stringByReplacingOccurrencesOfString:@"CGC" withString:@""]
            stringByReplacingOccurrencesOfString:@"ViewController"
                                      withString:@""];
        _drawComparisonImage = NO;
    }
    return self;
}

- (instancetype)initWithDrawingOptions:(CGDrawOptions*)options {
    if (self = [self init]) {
        _options = options;
    }
    return self;
}

- (void)drawComparisonCGImageFromImageName:(NSString*)name intoContext:(CGContextRef)context {
    // Draw the reference platform's screenshot image

    UIImage* comparisonImage = [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:name ofType:@"png"]];
    CGAffineTransform flip = CGAffineTransformMakeScale(1, -1);
    CGAffineTransform shift = CGAffineTransformTranslate(flip, 0, comparisonImage.size.height * -1);
    CGContextConcatCTM(context, shift);

    UIGraphicsBeginImageContext(comparisonImage.size);
    CGContextDrawImage(context, CGRectMake(50, -300, comparisonImage.size.width, comparisonImage.size.height), comparisonImage.CGImage);
}

- (void)loadView {
    CGRect frame = self.navigationController.view.bounds;
    frame.size.height = frame.size.height - CGRectGetMaxY(self.navigationController.navigationBar.frame);
    UIView* view = [[UIView alloc] initWithFrame:frame];
    self.view = view;

    self.view.backgroundColor = [UIColor whiteColor];
    self.edgesForExtendedLayout = UIRectEdgeNone;
}

- (void)addComparisonLabel {
    UILabel* comparisonText = [[UILabel alloc] initWithFrame:CGRectMake(50, 250, 200, 50)];
    [comparisonText setBackgroundColor:[UIColor whiteColor]];
    [comparisonText setText:@"Comparison Image"];
    [self.view addSubview:comparisonText];
}

@end
