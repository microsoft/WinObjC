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
#import "CGPathApplyCurveViewController.h"
#import "CGPathCloseSubpathViewController.h"
#import "CGPathContainsPointViewController.h"
#import "CGPathGetBoundingBoxViewController.h"
#import "CGPathAddArcViewController.h"
#import "CGPathAddArcToPointViewController.h"
#import "CGPathAddRoundedRectViewController.h"
#import "CGPathAddArcFullCircleViewController.h"

@interface CGContextNewTestsController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSArray<CGContextSampleRow*>* samples;
@property UITextField* lineWidthTextBox;
@property UITextField* redColor;
@property UITextField* greenColor;
@property UITextField* blueColor;
@property UITextField* alphaColor;
@property UITextField* dashPatternText;
@property UITextField* affineTransformText;

@property CGColorRef lineColor;
@property CGFloat lineWidth;
@property CGFloat* dashComponents;
@property CGFloat dashPhase;
@property size_t dashCount;
@property CGAffineTransform affineTransform;

@end

@implementation CGContextNewTestsController

- (NSArray*)samples {
    if (!_samples) {
        _samples = @[
            [CGContextSampleRow row:@"CGPathAddCurveToPoint" class:[CGPathAddCurveToPointViewController class]],
            [CGContextSampleRow row:@"CGPathAddEllipseInRect" class:[CGPathAddElipseViewController class]],
            [CGContextSampleRow row:@"CGPathAddLineToPoint" class:[CGPathAddLineToPointViewController class]],
            [CGContextSampleRow row:@"CGPathAddPath" class:[CGPathAddPathViewController class]],
            [CGContextSampleRow row:@"CGPathAddQuadCurveToPoint" class:[CGPathAddQuadCurveToPointViewController class]],
            [CGContextSampleRow row:@"CGPathAddRect" class:[CGPathAddRectViewController class]],
            [CGContextSampleRow row:@"CGPathApply" class:[CGPathApplyViewController class]],
            [CGContextSampleRow row:@"CGPathApply Curves" class:[CGPathApplyCurveViewController class]],
            [CGContextSampleRow row:@"CGPathCloseSubpath" class:[CGPathCloseSubpathViewController class]],
            [CGContextSampleRow row:@"CGPathContainsPoint" class:[CGPathContainsPointViewController class]],
            [CGContextSampleRow row:@"CGPathGetBoundingBox" class:[CGPathGetBoundingBoxViewController class]],
            [CGContextSampleRow row:@"CGPathAddArc" class:[CGPathAddArcViewController class]],
            [CGContextSampleRow row:@"CGPathAddArcToPoint" class:[CGPathAddArcToPointViewController class]],
            [CGContextSampleRow row:@"CGPathAddRoundedRect" class:[CGPathAddRoundedRectViewController class]],
            [CGContextSampleRow row:@"CGPathAddArcFullCircle" class:[CGPathAddArcFullCircleViewController class]],
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

- (void)createTransformFromTextBoxes {
    NSArray* components = [self.affineTransformText.text componentsSeparatedByString:@","];

    if (components.count != 6) {
        return;
    }

    CGFloat a, b, c, d, tx, ty;
    NSNumberFormatter* formatter = [[NSNumberFormatter alloc] init];
    formatter.numberStyle = NSNumberFormatterDecimalStyle;
    a = [formatter numberFromString:[components objectAtIndex:0]].floatValue;
    b = [formatter numberFromString:[components objectAtIndex:1]].floatValue;
    c = [formatter numberFromString:[components objectAtIndex:2]].floatValue;
    d = [formatter numberFromString:[components objectAtIndex:3]].floatValue;
    tx = [formatter numberFromString:[components objectAtIndex:4]].floatValue;
    ty = [formatter numberFromString:[components objectAtIndex:5]].floatValue;

    self.affineTransform = CGAffineTransformMake(a, b, c, d, tx, ty);
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

- (void)affineTransformCallback:(UITextField*)sender {
    NSCharacterSet* notNumericOrDeci = [[NSCharacterSet characterSetWithCharactersInString:@"0123456789.,"] invertedSet];
    if ([self.affineTransformText.text rangeOfCharacterFromSet:notNumericOrDeci].location == NSNotFound) {
        [self createTransformFromTextBoxes];
    }
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

- (void)refreshTransformText {
    NSNumberFormatter* formatter = [[NSNumberFormatter alloc] init];
    formatter.numberStyle = NSNumberFormatterDecimalStyle;
    [formatter setMaximumFractionDigits:2];
    NSMutableString* transforamtionText =
        [NSString stringWithFormat:@"%@, %@, %@, %@, %@, %@",
                                   [formatter stringFromNumber:[NSNumber numberWithFloat:self.affineTransform.a]],
                                   [formatter stringFromNumber:[NSNumber numberWithFloat:self.affineTransform.b]],
                                   [formatter stringFromNumber:[NSNumber numberWithFloat:self.affineTransform.c]],
                                   [formatter stringFromNumber:[NSNumber numberWithFloat:self.affineTransform.d]],
                                   [formatter stringFromNumber:[NSNumber numberWithFloat:self.affineTransform.tx]],
                                   [formatter stringFromNumber:[NSNumber numberWithFloat:self.affineTransform.ty]]];

    [self.affineTransformText setText:transforamtionText];
    [self createTransformFromTextBoxes];
}

- (void)rotateRight:(UIButton*)sender {
    self.affineTransform = CGAffineTransformRotate(self.affineTransform, M_PI / 36);
    [self refreshTransformText];
}

- (void)rotateLeft:(UIButton*)sender {
    self.affineTransform = CGAffineTransformRotate(self.affineTransform, -1 * M_PI / 36);
    [self refreshTransformText];
}

- (void)moveRight:(UIButton*)sender {
    self.affineTransform = CGAffineTransformTranslate(self.affineTransform, 10, 0);
    [self refreshTransformText];
}

- (void)moveLeft:(UIButton*)sender {
    self.affineTransform = CGAffineTransformTranslate(self.affineTransform, -10, 0);
    [self refreshTransformText];
}

- (void)moveUp:(UIButton*)sender {
    self.affineTransform = CGAffineTransformTranslate(self.affineTransform, 0, -10);
    [self refreshTransformText];
}

- (void)moveDown:(UIButton*)sender {
    self.affineTransform = CGAffineTransformTranslate(self.affineTransform, 0, 10);
    [self refreshTransformText];
}

- (void)loadView {
    [super loadView];
    [self.view setBackgroundColor:[UIColor clearColor]];

    UILabel* lineWidthText = [[UILabel alloc] initWithFrame:CGRectMake(0, 60, 100, 40)];
    [lineWidthText setBackgroundColor:[UIColor whiteColor]];
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
    [self.redColor setText:@"0"];
    [self.redColor addTarget:self action:@selector(colorTextBoxCallBack:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.redColor];

    self.greenColor = [[UITextField alloc] initWithFrame:CGRectMake(230, 60, 50, 40)];
    [self.greenColor setBackgroundColor:[UIColor whiteColor]];
    [self.greenColor setText:@"0"];
    [self.greenColor addTarget:self action:@selector(colorTextBoxCallBack:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.greenColor];

    self.blueColor = [[UITextField alloc] initWithFrame:CGRectMake(260, 60, 50, 40)];
    [self.blueColor setBackgroundColor:[UIColor whiteColor]];
    [self.blueColor setText:@"0"];
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

    UILabel* transformText = [[UILabel alloc] initWithFrame:CGRectMake(0, 140, 150, 40)];
    [transformText setBackgroundColor:[UIColor whiteColor]];
    [transformText setText:@"Affine Transform:"];
    [self.view addSubview:transformText];

    self.affineTransformText = [[UITextField alloc] initWithFrame:CGRectMake(150, 140, 250, 40)];
    [self.affineTransformText setBackgroundColor:[UIColor whiteColor]];
    [self.affineTransformText setText:@"1.0, 0.0, 0.0, 1.0, 0.0, 0.0"];
    [self.affineTransformText addTarget:self action:@selector(affineTransformCallback:) forControlEvents:UIControlEventEditingChanged];
    [self.view addSubview:self.affineTransformText];

    UIButton* rotateRightButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [rotateRightButton setBackgroundColor:[UIColor whiteColor]];
    [rotateRightButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [rotateRightButton addTarget:self action:@selector(rotateRight:) forControlEvents:UIControlEventTouchUpInside];
    rotateRightButton.frame = CGRectMake(0, 180, 50, 30);
    [rotateRightButton setTitle:@"+5\u00B0" forState:UIControlStateNormal];
    [self.view addSubview:rotateRightButton];

    UIButton* rotateLeftButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [rotateLeftButton setBackgroundColor:[UIColor whiteColor]];
    [rotateLeftButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [rotateLeftButton addTarget:self action:@selector(rotateLeft:) forControlEvents:UIControlEventTouchUpInside];
    rotateLeftButton.frame = CGRectMake(50, 180, 50, 30);
    [rotateLeftButton setTitle:@"-5\u00B0" forState:UIControlStateNormal];
    [self.view addSubview:rotateLeftButton];

    UIButton* moveRightButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [moveRightButton setBackgroundColor:[UIColor whiteColor]];
    [moveRightButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [moveRightButton addTarget:self action:@selector(moveRight:) forControlEvents:UIControlEventTouchUpInside];
    moveRightButton.frame = CGRectMake(100, 180, 60, 30);
    [moveRightButton setTitle:@"X+10" forState:UIControlStateNormal];
    [self.view addSubview:moveRightButton];

    UIButton* moveLeftButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [moveLeftButton setBackgroundColor:[UIColor whiteColor]];
    [moveLeftButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [moveLeftButton addTarget:self action:@selector(moveLeft:) forControlEvents:UIControlEventTouchUpInside];
    moveLeftButton.frame = CGRectMake(160, 180, 60, 30);
    [moveLeftButton setTitle:@"X-10" forState:UIControlStateNormal];
    [self.view addSubview:moveLeftButton];

    UIButton* moveUpButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [moveUpButton setBackgroundColor:[UIColor whiteColor]];
    [moveUpButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [moveUpButton addTarget:self action:@selector(moveUp:) forControlEvents:UIControlEventTouchUpInside];
    moveUpButton.frame = CGRectMake(220, 180, 60, 30);
    [moveUpButton setTitle:@"Y-10" forState:UIControlStateNormal];
    [self.view addSubview:moveUpButton];

    UIButton* moveDownButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [moveDownButton setBackgroundColor:[UIColor whiteColor]];
    [moveDownButton setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [moveDownButton addTarget:self action:@selector(moveDown:) forControlEvents:UIControlEventTouchUpInside];
    moveDownButton.frame = CGRectMake(280, 180, 60, 30);
    [moveDownButton setTitle:@"Y+10" forState:UIControlStateNormal];
    [self.view addSubview:moveDownButton];

    [self createTransformFromTextBoxes];
    [self createNewColorFromTextBoxes];
    [self createLineWidthFromText:nil];
    [self dashPatternCallback:nil];
    self.dashPhase = 0;

    UITableView* tableView = [[UITableView alloc] init];
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    CGRect viewBounds = self.view.bounds;

    CGRect newTableBounds =
        CGRectMake(0, 210, viewBounds.origin.x + viewBounds.size.width, viewBounds.origin.y + viewBounds.size.height - 260);
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
                                                            dashCount:self.dashCount
                                                            transform:self.affineTransform];
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
