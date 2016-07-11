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

#import "CGCCGPathApplyViewController.h"

@interface CGCCGPathApplyViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSMutableArray* functions;
@property (nonatomic, strong) UIImageView* testViewDisplayView;
@property (nonatomic, strong) UITableView* consoleView;
@property (nonatomic, strong) UISlider* slider;

@end

@implementation CGCCGPathApplyViewController

- (void)loadView {
    [super loadView];

    self.testViewDisplayView =
        [[UIImageView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, self.view.bounds.size.width, self.view.bounds.size.height / 2.0f)];
    [self.testViewDisplayView setBackgroundColor:[UIColor redColor]];
    [self.view addSubview:self.testViewDisplayView];

    self.consoleView = [[UITableView alloc] initWithFrame:CGRectMake(0.0f,
                                                                     self.view.bounds.size.height / 2.0f,
                                                                     self.view.bounds.size.width,
                                                                     self.view.bounds.size.height / 2.0f)];
    [self.consoleView setRowHeight:500.0f];
    [self.consoleView setEstimatedRowHeight:100];
    [self.consoleView setDelegate:self];
    [self.consoleView setDataSource:self];
    [self.view addSubview:self.consoleView];

    self.slider = [[UISlider alloc] init];
    [self.slider setFrame:CGRectMake(50, self.testViewDisplayView.frame.size.height - 50, self.view.bounds.size.width - 100, 50)];
    [self.view addSubview:self.slider];
    [self.slider setMinimumValue:0];
    [self.slider setMaximumValue:1.0f];
    [self.slider addTarget:self action:@selector(sliderMoved:) forControlEvents:UIControlEventValueChanged];
    [self sliderMoved:self.slider];
}

- (void)sliderMoved:(UISlider*)slider {
    CGAffineTransform transform = CGAffineTransformIdentity;
    transform = CGAffineTransformTranslate(transform, 300 * slider.value, 300 * slider.value);
    transform = CGAffineTransformScale(transform, 1.0f - 1.0 * slider.value, 1.0f - .5 * slider.value);
    transform = CGAffineTransformRotate(transform, slider.value * 2.0 * M_PI);
    [self drawPaths:transform];
}

- (void)drawPaths:(CGAffineTransform)transform {
    UIGraphicsBeginImageContextWithOptions(self.testViewDisplayView.frame.size, NO, 0);

    self.functions = [[NSMutableArray alloc] init];

    void (^addFunctions)(CGPathRef path, NSArray* functions) = ^(CGPathRef path, NSArray* functions) {
        if ([self.functions count] == self.consoleView.indexPathForSelectedRow.row) {
            [[UIColor whiteColor] set];
        } else {
            [[UIColor blackColor] set];
        }
        CGContextAddPath(UIGraphicsGetCurrentContext(), path);
        CGContextStrokePath(UIGraphicsGetCurrentContext());

        NSMutableString* processedString = [NSMutableString string];
        CGPathApply(path, (__bridge void* _Nullable)(processedString), cgPathApplierFunction);

        NSMutableString* originalString = [NSMutableString string];
        for (NSDictionary* function in functions) {
            [originalString appendString:[NSString stringWithFormat:@"%@\n", function[@"name"]]];
            for (NSValue* point in function[@"points"]) {
                [originalString appendString:[NSString stringWithFormat:@"\t( %@ )\n", point]];
            }
        }

        [self.functions addObject:@{ @"original" : originalString, @"processed" : processedString }];
    };

    {
        CGMutablePathRef path = CGPathCreateMutable();
        NSArray* points = @[ [NSValue valueWithCGRect:CGRectMake(40, 40, 200, 40)] ];
        CGPathAddEllipseInRect(path, &transform, [points[0] CGRectValue]);

        addFunctions(path, @[ @{ @"name" : @"CGPathAddEllipseInRect", @"points" : points } ]);
    }
    {
        CGMutablePathRef path = CGPathCreateMutable();
        NSArray* points = @[ [NSValue valueWithCGRect:CGRectMake(140, 140, 20, 10)] ];
        CGPathAddRect(path, &transform, [points[0] CGRectValue]);

        addFunctions(path, @[ @{ @"name" : @"CGPathAddRect", @"points" : points } ]);
    }
    {
        CGMutablePathRef path = CGPathCreateMutable();
        NSArray* points = @[ [NSValue valueWithCGPoint:CGPointMake(25, 100)], @20, @(1.25 * M_PI), @(0), @YES ];
        CGPathAddArc(path,
                     &transform,
                     [points[0] CGPointValue].x,
                     [points[0] CGPointValue].y,
                     [points[1] floatValue],
                     [points[2] floatValue],
                     [points[3] floatValue],
                     [points[4] boolValue]);

        addFunctions(path, @[ @{ @"name" : @"CGPathAddArc", @"points" : points } ]);
    }
    {
        CGMutablePathRef path = CGPathCreateMutable();

        NSArray* movePoints = @[ [NSValue valueWithCGPoint:CGPointMake(10, 20)] ];
        CGPathMoveToPoint(path, &transform, [movePoints[0] CGPointValue].x, [movePoints[0] CGPointValue].y);

        NSArray* curvePoints = @[
            [NSValue valueWithCGPoint:CGPointMake(50, 60)],
            [NSValue valueWithCGPoint:CGPointMake(10, 20)],
            [NSValue valueWithCGPoint:CGPointMake(300, 70)]
        ];
        CGPathAddCurveToPoint(path,
                              &transform,
                              [curvePoints[0] CGPointValue].x,
                              [curvePoints[0] CGPointValue].y,
                              [curvePoints[1] CGPointValue].x,
                              [curvePoints[1] CGPointValue].y,
                              [curvePoints[2] CGPointValue].x,
                              [curvePoints[2] CGPointValue].y);

        addFunctions(path, @[
            @{ @"name" : @"CGPathMoveToPoint",
               @"points" : movePoints },
            @{ @"name" : @"CGPathAddCurveToPoint",
               @"points" : curvePoints }
        ]);
    }
    {
        CGMutablePathRef path = CGPathCreateMutable();

        NSArray* movePoints = @[ [NSValue valueWithCGPoint:CGPointMake(400, 400)] ];
        CGPathMoveToPoint(path, &transform, [movePoints[0] CGPointValue].x, [movePoints[0] CGPointValue].y);

        NSArray* curvePoints = @[ [NSValue valueWithCGPoint:CGPointMake(140, 250)], [NSValue valueWithCGPoint:CGPointMake(110, 180)], @50 ];

        CGPathAddArcToPoint(path,
                            &transform,
                            [curvePoints[0] CGPointValue].x,
                            [curvePoints[0] CGPointValue].y,
                            [curvePoints[1] CGPointValue].x,
                            [curvePoints[1] CGPointValue].y,
                            [curvePoints[2] floatValue]);

        addFunctions(path, @[
            @{ @"name" : @"CGPathMoveToPoint",
               @"points" : movePoints },
            @{ @"name" : @"CGPathAddArcToPoint",
               @"points" : curvePoints }
        ]);
    }

    UIImage* image = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    self.testViewDisplayView.image = image;

    [self.consoleView reloadData];
}

// UITableViewDelegat

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    [self sliderMoved:self.slider];
}

// UITableViewDataSource

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.functions count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    NSString* reuseIdentifier = @"reuseIdentifier";

    NSInteger originalLabelTag = 1;
    NSInteger processedLabelTag = 2;

    UILabel* originalLabel;
    UILabel* processedLabel;

    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:reuseIdentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdentifier];

        originalLabel = [[UILabel alloc] init];
        [originalLabel setBackgroundColor:[UIColor clearColor]];
        [originalLabel setFont:[UIFont systemFontOfSize:10]];
        [originalLabel setNumberOfLines:0];
        [originalLabel setLineBreakMode:NSLineBreakByWordWrapping];

        [[cell contentView] addSubview:originalLabel];
        [originalLabel setTag:originalLabelTag];
        [originalLabel setTranslatesAutoresizingMaskIntoConstraints:NO];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:originalLabel
                                                                     attribute:NSLayoutAttributeTop
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeTop
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:originalLabel
                                                                     attribute:NSLayoutAttributeLeft
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeLeft
                                                                    multiplier:1.0f
                                                                      constant:10.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:originalLabel
                                                                     attribute:NSLayoutAttributeRight
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeRight
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:originalLabel
                                                                     attribute:NSLayoutAttributeBottom
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeBottom
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];

        processedLabel = [[UILabel alloc] init];
        [processedLabel setBackgroundColor:[UIColor clearColor]];
        [processedLabel setFont:[UIFont systemFontOfSize:10]];
        [processedLabel setNumberOfLines:0];
        [processedLabel setLineBreakMode:NSLineBreakByWordWrapping];

        [[cell contentView] addSubview:processedLabel];
        [processedLabel setTag:processedLabelTag];
        [processedLabel setTranslatesAutoresizingMaskIntoConstraints:NO];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:processedLabel
                                                                     attribute:NSLayoutAttributeTop
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeTop
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:processedLabel
                                                                     attribute:NSLayoutAttributeLeft
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeLeft
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:processedLabel
                                                                     attribute:NSLayoutAttributeRight
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeRight
                                                                    multiplier:1.0f
                                                                      constant:-10.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:processedLabel
                                                                     attribute:NSLayoutAttributeBottom
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeBottom
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
        [processedLabel setTextAlignment:NSTextAlignmentRight];
    } else {
        originalLabel = [[cell contentView] viewWithTag:originalLabelTag];
        processedLabel = [[cell contentView] viewWithTag:processedLabelTag];
    }

    NSDictionary* function = self.functions[[indexPath row]];
    [originalLabel setText:function[@"original"]];
    [processedLabel setText:function[@"processed"]];

    return cell;
}

void cgPathApplierFunction(void* info, const CGPathElement* element) {
    NSMutableString* elementString = (__bridge NSMutableString*)(info);
    NSString* pointCountKey = @"pointCountKey";
    NSString* nameKey = @"nameKey";
    NSDictionary* elementsInfo = @{
        @(kCGPathElementMoveToPoint) : @{ pointCountKey : @1, nameKey : @"kCGPathElementMoveToPoint" },
        @(kCGPathElementAddLineToPoint) : @{ pointCountKey : @1, nameKey : @"kCGPathElementAddLineToPoint" },
        @(kCGPathElementAddQuadCurveToPoint) : @{ pointCountKey : @2, nameKey : @"kCGPathElementAddQuadCurveToPoint" },
        @(kCGPathElementAddCurveToPoint) : @{ pointCountKey : @3, nameKey : @"kCGPathElementAddCurveToPoint" },
        @(kCGPathElementCloseSubpath) : @{ pointCountKey : @0, nameKey : @"kCGPathElementCloseSubpath" }
    };
    NSDictionary* elementInfo = elementsInfo[@(element->type)];
    [elementString appendString:[NSString stringWithFormat:@"%@\n", elementInfo[nameKey]]];
    for (NSInteger i = 0; i < [elementInfo[pointCountKey] integerValue]; i++) {
        CGPoint point = element->points[i];
        [elementString appendString:[NSString stringWithFormat:@"\t( %f, %f )\n", point.x, point.y]];
    }
}

@end
