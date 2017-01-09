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

#import "CGContextNewTestsController.h"

#import "CGDrawOptions.h"

#import "CGContextSampleRow.h"
#import "CGPathAddCurveToPointViewController.h"
#import "CGPathAddElipseViewController.h"
#import "CGPathAddLineToPointViewController.h"
#import "CGPathAddPathViewController.h"
#import "CGPathAddQuadCurveToPointViewController.h"
#import "CGPathAddRectViewController.h"
#import "CGPathApplyViewController.h"
#import "CGPathCloseSubpathViewController.h"
#import "CGPathContainsPointViewController.h"
#import "CGPathGetBoundingBoxViewController.h"

@interface CGContextNewTestsController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSArray<CGContextSampleRow*>* samples;
@property UITextField* lineWidthTextBox;
@property UITextField* redColor;
@property UITextField* greenColor;
@property UITextField* blueColor;
@property UITextField* alphaColor;
@property UITextField* dashPatternText;

@property CGColorRef lineColor;
@property CGFloat lineWidth;
@property CGFloat* dashComponents;
@property CGFloat dashPhase;
@property size_t dashCount;

@end

@implementation CGContextNewTestsController

- (NSArray*)samples {
    if (!_samples) {
        _samples = @[
            [CGContextSampleRow row:@"CGPathAddCurveToPoint" class:[CGPathAddCurveToPointViewController class]],
            [CGContextSampleRow row:@"CGPathAddEllipse" class:[CGPathAddElipseViewController class]],
            [CGContextSampleRow row:@"CGPathAddLineToPoint" class:[CGPathAddLineToPointViewController class]],
            [CGContextSampleRow row:@"CGPathAddPath" class:[CGPathAddPathViewController class]],
            [CGContextSampleRow row:@"CGPathAddQuadCurveToPoint" class:[CGPathAddQuadCurveToPointViewController class]],
            [CGContextSampleRow row:@"CGPathAddRect" class:[CGPathAddRectViewController class]],
            [CGContextSampleRow row:@"CGPathApply" class:[CGPathApplyViewController class]],
            [CGContextSampleRow row:@"CGPathCloseSubpath" class:[CGPathCloseSubpathViewController class]],
            [CGContextSampleRow row:@"CGPathContainsPoint" class:[CGPathContainsPointViewController class]],
            [CGContextSampleRow row:@"CGPathGetBoundingBox" class:[CGPathGetBoundingBoxViewController class]],
        ];
    }
    return _samples;
}

- (NSString*)title {
    return @"New Samples";
}

- (void)createLineWidthFromText:(UITextField*)sender {
    NSCharacterSet* notNumericOrDeci = [[NSCharacterSet characterSetWithCharactersInString:@"0123456789."] invertedSet];
    if ([self.lineWidthTextBox.text rangeOfCharacterFromSet:notNumericOrDeci].location == NSNotFound) {
        NSNumberFormatter* formatter = [[NSNumberFormatter alloc] init];
        formatter.numberStyle = NSNumberFormatterDecimalStyle;
        CGFloat lineValue = [formatter numberFromString:self.lineWidthTextBox.text].floatValue;

        if (lineValue < 0) {
            lineValue = 0;
        }

        self.lineWidth = lineValue;
    }
}

- (void)createNewColorFromTextBoxes {
    NSNumberFormatter* formatter = [[NSNumberFormatter alloc] init];
    formatter.numberStyle = NSNumberFormatterDecimalStyle;
    CGFloat redValue = [formatter numberFromString:self.redColor.text].floatValue;

    if (redValue < 0 || redValue > 1) {
        return;
    }

    CGFloat greenValue = [formatter numberFromString:self.greenColor.text].floatValue;

    if (greenValue < 0 || greenValue > 1) {
        return;
    }

    CGFloat blueValue = [formatter numberFromString:self.blueColor.text].floatValue;

    if (blueValue < 0 || blueValue > 1) {
        return;
    }

    CGFloat alphaValue = [formatter numberFromString:self.alphaColor.text].floatValue;

    if (alphaValue < 0 || alphaValue > 1) {
        return;
    }

    CGColorRelease(self.lineColor);
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGFloat colorComponents[4];
    colorComponents[0] = redValue;
    colorComponents[1] = greenValue;
    colorComponents[2] = blueValue;
    colorComponents[3] = alphaValue;
    self.lineColor = CGColorCreate(colorspace, colorComponents);
    CGColorSpaceRelease(colorspace);
}

- (void)colorTextBoxCallBack:(UITextField*)sender {
    NSCharacterSet* notNumericOrDeci = [[NSCharacterSet characterSetWithCharactersInString:@"0123456789."] invertedSet];
    if ([self.dashPatternText.text rangeOfCharacterFromSet:notNumericOrDeci].location == NSNotFound) {
        [self createNewColorFromTextBoxes];
    }
}

- (void)dashPatternCallback:(UITextField*)sender {
    if (self.dashComponents) {
        free(self.dashComponents);
    }

    NSCharacterSet* notAllowedCharacters = [[NSCharacterSet characterSetWithCharactersInString:@"0123456789., "] invertedSet];

    if ([sender.text rangeOfCharacterFromSet:notAllowedCharacters].location != NSNotFound) {
        self.dashComponents = malloc(sizeof(CGFloat));
        self.dashComponents[0] = 0;
        return;
    }

    NSArray* components = [self.dashPatternText.text componentsSeparatedByString:@","];

    self.dashCount = components.count;
    self.dashComponents = malloc(sizeof(CGFloat) * self.dashCount);

    NSNumberFormatter* formatter = [[NSNumberFormatter alloc] init];
    formatter.numberStyle = NSNumberFormatterDecimalStyle;

    for (int i = 0; i < self.dashCount; i++) {
        self.dashComponents[i] = [formatter numberFromString:[components objectAtIndex:i]].floatValue;
    }
}

- (void)touchesBegan:(NSSet<UITouch*>*)touches withEvent:(UIEvent*)event {
    [self.view endEditing:YES];
}

- (void)loadView {
    [super loadView];
    [self.view setBackgroundColor:[UIColor clearColor]];

    UILabel* lineWidthText = [[UILabel alloc] initWithFrame:CGRectMake(0, 60, 100, 40)];
    [lineWidthText setBackgroundColor:[UIColor whiteColor]];
    [lineWidthText setText:@"LineWidth:"];
    [self.view addSubview:lineWidthText];

    self.lineWidthTextBox = [[UITextField alloc] initWithFrame:CGRectMake(82, 60, 50, 40)];
    [self.lineWidthTextBox setBackgroundColor:[UIColor whiteColor]];
    [self.lineWidthTextBox setText:@"2.0"];
    [self.lineWidthTextBox addTarget:self action:@selector(createLineWidthFromText:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.lineWidthTextBox];

    UILabel* lineColorText = [[UILabel alloc] initWithFrame:CGRectMake(122, 60, 100, 40)];
    [lineColorText setBackgroundColor:[UIColor whiteColor]];
    [lineColorText setText:@"R/G/B/A:"];
    [self.view addSubview:lineColorText];

    self.redColor = [[UITextField alloc] initWithFrame:CGRectMake(200, 60, 50, 40)];
    [self.redColor setBackgroundColor:[UIColor whiteColor]];
    [self.redColor setText:@"1.0"];
    [self.redColor addTarget:self action:@selector(colorTextBoxCallBack:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.redColor];

    self.greenColor = [[UITextField alloc] initWithFrame:CGRectMake(230, 60, 50, 40)];
    [self.greenColor setBackgroundColor:[UIColor whiteColor]];
    [self.greenColor setText:@"1.0"];
    [self.greenColor addTarget:self action:@selector(colorTextBoxCallBack:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.greenColor];

    self.blueColor = [[UITextField alloc] initWithFrame:CGRectMake(260, 60, 50, 40)];
    [self.blueColor setBackgroundColor:[UIColor whiteColor]];
    [self.blueColor setText:@"1.0"];
    [self.blueColor addTarget:self action:@selector(colorTextBoxCallBack:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.blueColor];

    self.alphaColor = [[UITextField alloc] initWithFrame:CGRectMake(290, 60, 50, 40)];
    [self.alphaColor setBackgroundColor:[UIColor whiteColor]];
    [self.alphaColor setText:@"1.0"];
    [self.alphaColor addTarget:self action:@selector(colorTextBoxCallBack:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.alphaColor];

    UILabel* dashText = [[UILabel alloc] initWithFrame:CGRectMake(0, 100, 150, 40)];
    [dashText setBackgroundColor:[UIColor whiteColor]];
    [dashText setText:@"Dash Pattern:"];
    [self.view addSubview:dashText];

    self.dashPatternText = [[UITextField alloc] initWithFrame:CGRectMake(150, 100, 200, 40)];
    [self.dashPatternText setBackgroundColor:[UIColor whiteColor]];
    [self.dashPatternText setText:@"1.0"];
    [self.dashPatternText addTarget:self action:@selector(dashPatternCallback:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.dashPatternText];

    [self createNewColorFromTextBoxes];
    [self createLineWidthFromText:nil];
    [self dashPatternCallback:nil];
    self.dashPhase = 0;

    UITableView* tableView = [[UITableView alloc] init];
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    CGRect viewBounds = self.view.bounds;

    CGRect newTableBounds = CGRectMake(0, 150, viewBounds.origin.x + viewBounds.size.width, viewBounds.origin.y + viewBounds.size.height);
    [tableView setFrame:newTableBounds];
    [self.view addSubview:tableView];
}

- (void)tableView:(UITableView*)tableView didHighlightRowAtIndexPath:(NSIndexPath*)indexPath {
    [self.view endEditing:YES];
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    CGDrawOptions* options = [[CGDrawOptions alloc] initWithLineWidth:self.lineWidth
                                                            lineColor:self.lineColor
                                                            fillColor:self.lineColor
                                                      lineDashPattern:self.dashComponents
                                                            linePhase:self.dashPhase
                                                            dashCount:self.dashCount];
    [self.navigationController pushViewController:[[self.samples[indexPath.row].class alloc] initWithDrawingOptions:options] animated:YES];
}

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

- (void)dealloc {
    CGColorRelease(self.lineColor);
}

@end
