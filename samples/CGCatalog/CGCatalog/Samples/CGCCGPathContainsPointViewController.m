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

#import "CGCCGPathContainsPointViewController.h"

@interface CustomHitTestPathView : UIView {
}

@property (nonatomic, assign) BOOL testResult;
@property (nonatomic, assign) CGPathRef path;

@end

@implementation CustomHitTestPathView {
}

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGFloat components[] = { 1.0, 1.0, 1.0, 1.0 };

    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGColorRef color = CGColorCreate(colorspace, components);

    CGContextSetStrokeColorWithColor(context, color);
    CGContextSetFillColor(context, components);

    CGRect pathRect = self.bounds;
    pathRect.size.height *= 0.5;
    pathRect.size.width *= 0.5;
    pathRect.origin.x = pathRect.size.width * 0.25;
    pathRect.origin.y = pathRect.size.height * 0.5;

    CGFloat strokeWidth = 1.0;
    if (!_path) {
        _path = [self newPathForRoundRect:pathRect radius:20.0];
    }
    CGContextSetLineWidth(context, strokeWidth);
    CGContextAddPath(context, _path);
    CGContextStrokePath(context);
    CGColorSpaceRelease(colorspace);
    CGColorRelease(color);
}

- (void)touchesBegan:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event {
    [super touchesBegan:touches withEvent:event];
    for (UITouch* touch in touches) {
        CGPoint pointInView = [touch locationInView:self];
        self.testResult = CGPathContainsPoint(_path, NULL, pointInView, YES);
    }
}

- (CGPathRef)newPathForRoundRect:(CGRect)rect radius:(CGFloat)radius {
    CGMutablePathRef path = CGPathCreateMutable();

    CGRect innerRect = CGRectInset(rect, radius, radius);

    CGFloat insideRight = innerRect.origin.x + innerRect.size.width;
    CGFloat outsideRight = rect.origin.x + rect.size.width;
    CGFloat insideBottom = innerRect.origin.y + innerRect.size.height;
    CGFloat outsideBottom = rect.origin.y + rect.size.height;

    CGFloat insideTop = innerRect.origin.y;
    CGFloat outsideTop = rect.origin.y;
    CGFloat outsideLeft = rect.origin.x;

    CGPathMoveToPoint(path, NULL, innerRect.origin.x, outsideTop);

    CGPathAddLineToPoint(path, NULL, insideRight, outsideTop);
    CGPathAddArcToPoint(path, NULL, outsideRight, outsideTop, outsideRight, insideTop, radius);

    CGPathAddLineToPoint(path, NULL, outsideRight, insideBottom);
    CGPathAddArcToPoint(path, NULL, outsideRight, outsideBottom, insideRight, outsideBottom, radius);

    CGPathAddLineToPoint(path, NULL, innerRect.origin.x, outsideBottom);
    CGPathAddArcToPoint(path, NULL, outsideLeft, outsideBottom, outsideLeft, insideBottom, radius);

    CGPathAddLineToPoint(path, NULL, outsideLeft, insideTop);
    CGPathAddArcToPoint(path, NULL, outsideLeft, outsideTop, innerRect.origin.x, outsideTop, radius);

    CGPathCloseSubpath(path);

    return path;
}

- (void)dealloc {
    if (_path) {
        CGPathRelease(_path);
        _path = nil;
    }
}

@end

@interface CGCCGPathContainsPointViewController ()

@property (nonatomic, strong) CustomHitTestPathView* customView;
@property (nonatomic, strong) UILabel* testResultLabel;
@end

void* gKVOContext = &gKVOContext;

@implementation CGCCGPathContainsPointViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CustomHitTestPathView* customView = [[CustomHitTestPathView alloc] initWithFrame:CGRectMake(50, 100, 200, 300)];

    [self setCustomView:customView];
    [_customView addObserver:self forKeyPath:@"testResult" options:0 context:gKVOContext];
    [self.view addSubview:_customView];

    _testResultLabel = [[UILabel alloc] initWithFrame:CGRectMake(50, 440, 200, 80)];
    [_testResultLabel setNumberOfLines:0];
    [_testResultLabel setText:@"Touch in the view above."];
    [self.view addSubview:_testResultLabel];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [_customView removeObserver:self forKeyPath:@"testResult" context:gKVOContext];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)observeValueForKeyPath:(NSString*)keyPath ofObject:(id)object change:(NSDictionary*)change context:(void*)context {
    if (context == gKVOContext && [keyPath isEqualToString:@"testResult"]) {
        if (_customView.testResult) {
            [_testResultLabel setText:@"Touch was within the path."];
        } else {
            [_testResultLabel setText:@"Touch was NOT within the path."];
        }
    } else
        [super observeValueForKeyPath:keyPath ofObject:object change:change context:context];
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
