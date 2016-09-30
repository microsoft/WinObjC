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

#import "CGCRootViewController.h"
#import "CGCCGBitmapContentViewController.h"
#import "CGCCGContextBeginEndTransparencyLayer.h"
#import "CGCCGContextBeginTransparencyLayerWithRect.h"
#import "CGCCGContextReplacePathWithStrokedPath.h"
#import "CGCCGContextSetPatternPhase.h"
#import "CGCCGContextViewController.h"
#import "CGCCGPathApplyViewController.h"
#import "CGCCGPathContainsPointViewController.h"

#import "CGContextSampleRow.h"

@interface CGCRootViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSArray<CGContextSampleRow*>* samples;

@end

@implementation CGCRootViewController

- (NSArray*)samples {
    if (!_samples) {
        _samples = @[
            [CGContextSampleRow row:@"CGPathApply" class:[CGCCGPathApplyViewController class]],
            [CGContextSampleRow row:@"CGContext" class:[CGCCGContextViewController class]],
            [CGContextSampleRow row:@"CGBitmapContext" class:[CGCCGBitmapContentViewController class]],
            [CGContextSampleRow row:@"CGContextBeginEndTransparencyLayer" class:[CGCCGContextBeginEndTransparencyLayer class]],
            [CGContextSampleRow row:@"CGContextBeginTransparencyLayerWithRect" class:[CGCCGContextBeginTransparencyLayerWithRect class]],
            [CGContextSampleRow row:@"CGContextSetPatternPhase" class:[CGCCGContextSetPatternPhase class]],
            [CGContextSampleRow row:@"CGContextReplacePathWithStrokedPath" class:[CGCCGContextReplacePathWithStrokedPath class]],
            [CGContextSampleRow row:@"CGCCGPathContainsPointViewController" class:[CGCCGPathContainsPointViewController class]],
        ];
    }
    return _samples;
}

- (NSString*)title {
    return @"Samples";
}

- (void)loadView {
    [super loadView];
    // Do any additional setup after loading the view, typically from a nib.

    UITableView* tableView = [[UITableView alloc] init];
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    [tableView setFrame:self.view.bounds];
    [self.view addSubview:tableView];
}

// UITableViewDelegate

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    [self.navigationController pushViewController:[[self.samples[indexPath.row].class alloc] init] animated:YES];
}

// UITableViewDataSource

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.samples count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    NSString* reuseIdentifier = @"reuseIdentifier";

    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:reuseIdentifier];

    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdentifier];
    }

    [cell.textLabel setText:self.samples[indexPath.row].name];

    return cell;
}

@end
