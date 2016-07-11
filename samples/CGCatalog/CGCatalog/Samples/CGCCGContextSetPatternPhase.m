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

#import "CGCCGContextSetPatternPhase.h"

@interface PatternView : UIView

@end

static const int c_PatternSize = 48;

@implementation PatternView

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGFloat maxWidth = rect.size.width;
    CGFloat maxHeight = rect.size.height;

    // White background
    CGContextSetFillColorWithColor(context, [UIColor whiteColor].CGColor);
    CGContextFillRect(context, CGRectMake(0, 0, maxWidth, maxHeight));

    // Create the pattern
    static const CGPatternCallbacks callbacks = { 0, &_DrawCustomPattern, NULL };
    CGFloat alpha = 1;
    CGPatternRef pattern = CGPatternCreate(
        NULL, rect, CGAffineTransformIdentity, c_PatternSize, c_PatternSize, kCGPatternTilingConstantSpacing, true, &callbacks);
    CGContextSetFillPattern(context, pattern, &alpha);
    CGPatternRelease(pattern);

    // Set the pattern phase
    CGContextSetPatternPhase(context, CGSizeMake(c_PatternSize / 2, c_PatternSize / 2));

    // Fill using the pattern
    CGContextFillRect(context, rect);
}

void _DrawCustomPattern(void* info, CGContextRef context) {
    // Draw a circle inset from the pattern size
    CGRect circleRect = CGRectMake(0, 0, c_PatternSize, c_PatternSize);
    circleRect = CGRectInset(circleRect, 4, 4);
    CGContextFillEllipseInRect(context, circleRect);
    CGContextStrokeEllipseInRect(context, circleRect);
}

@end

@interface CGCCGContextSetPatternPhase ()

@property (strong, nonatomic, nullable) PatternView* customView;

@end

@implementation CGCCGContextSetPatternPhase

- (void)viewDidLoad {
    [super viewDidLoad];

    self.view.backgroundColor = [UIColor whiteColor];

    self.customView = [[PatternView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height)];
    [self.view addSubview:self.customView];
}

@end
