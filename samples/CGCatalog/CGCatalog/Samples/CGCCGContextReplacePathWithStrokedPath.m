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

#import "CGCCGContextReplacePathWithStrokedPath.h"

static const CGFloat c_LineWidth = 20;

@protocol DrawRectCompletionDelegate <NSObject>

- (void)didFinishDrawing;

@end


typedef NS_ENUM(NSInteger, StrokedPathType) {
    StrokedPathTypeLine = 0,
    StrokedPathTypeCopyStroke,
    StrokedPathTypeReplaceStroke
};


@interface StrokeView : UIView

@property (assign, nonatomic) StrokedPathType strokedPathType;
@property (strong, atomic, nullable) NSMutableArray<NSString*>* logs;
@property (assign, nonatomic) CGPoint highlightedPoint;
@property (weak, nonatomic, nullable) id<DrawRectCompletionDelegate> delegate;

@end


@implementation StrokeView

- (void)drawRect:(CGRect)rect {
    [self.logs removeAllObjects];
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGFloat maxWidth = rect.size.width;
    CGFloat maxHeight = rect.size.height;

    // White background
    CGContextSetFillColorWithColor(context, [UIColor whiteColor].CGColor);
    CGContextFillRect(context, CGRectMake(0, 0, maxWidth, maxHeight));

    // Create original path
    NSDictionary* params;
    NSMutableArray<NSValue*>* originalPoints = [NSMutableArray new];
    CGMutablePathRef path = CGPathCreateMutable();
    CGContextSetLineWidth(context, c_LineWidth);
    CGContextSetLineCap(context, kCGLineCapRound);
    CGContextSetLineJoin(context, kCGLineJoinMiter);
    CGContextSetMiterLimit(context, 1);
    CGPathMoveToPoint(path, NULL, 10, maxHeight / 2);
    CGPathAddLineToPoint(path, NULL, maxWidth / 4, maxHeight / 2);
    CGPathAddArcToPoint(path, NULL, maxWidth / 4 + 50, maxHeight * 2 + 50, maxWidth / 2, maxHeight * 3 / 4, 50);
    CGPathAddQuadCurveToPoint(path, NULL, maxWidth * 3 / 4, maxHeight * 1 / 4, maxWidth - 10, 10);
    // Log original path info
    [self.logs addObject:@"Original Path:"];
    params = @{ @"logs" : self.logs, @"points" : originalPoints };
    CGPathApply(path, (__bridge void*)params, _Applier);

    // Create stroked path
    // TODO: Change this to use CGContextReplacePathWithStrokedPath()

    // Draw the path
    NSMutableArray<NSValue*>* points;
    switch (self.strokedPathType) {
        case StrokedPathTypeLine:
        {
            CGContextSetStrokeColorWithColor(context, [UIColor greenColor].CGColor);
            CGContextAddPath(context, path);
            CGContextStrokePath(context);
            points = originalPoints;
        }
        break;
            
        case StrokedPathTypeCopyStroke:
        {
            NSMutableArray<NSValue*>* strokedPoints = [NSMutableArray new];
            CGPathRef newPath = CGPathCreateCopyByStrokingPath(path, NULL, c_LineWidth, kCGLineCapRound, kCGLineJoinMiter, 1);
            [self.logs addObject:@"Copy Stroke Path:"];
            params = @{ @"logs" : self.logs, @"points" : strokedPoints };
            CGPathApply(newPath, (__bridge void*)params, _Applier);
            
            CGContextSetFillColorWithColor(context, [UIColor blueColor].CGColor);
            CGContextAddPath(context, newPath);
            CGContextFillPath(context);
            
            points = strokedPoints;
            CGPathRelease(newPath);
        }
        break;

        case StrokedPathTypeReplaceStroke:
        {
            CGContextSetStrokeColorWithColor(context, [UIColor purpleColor].CGColor);
            CGContextAddPath(context, path);
            CGContextReplacePathWithStrokedPath(context);
            
            CGPathRef newPath = CGContextCopyPath(context);
            NSMutableArray<NSValue*>* strokedPoints = [NSMutableArray new];
            [self.logs addObject:@"Replace Stroke:"];
            params = @{ @"logs" : self.logs, @"points" : strokedPoints };
            CGPathApply(newPath, (__bridge void*)params, _Applier);
            
            CGContextSetFillColorWithColor(context, [UIColor orangeColor].CGColor);
            CGContextFillPath(context);
            
            points = strokedPoints;
            CGPathRelease(newPath);
        }
        break;
    }
    
    // Draw connecting points of elements
    CGContextSetLineWidth(context, 1);
    CGContextSetFillColorWithColor(context, [UIColor blackColor].CGColor);
    for (NSValue* value in points) {
        CGPoint point = value.CGPointValue;
        CGContextAddArc(context, point.x, point.y, 4, 0.0, M_PI * 2, YES);
        CGContextFillPath(context);
    }

    // Draw highlighted point
    if (self.highlightedPoint.x != 0 && self.highlightedPoint.y != 0) {
        CGContextSetLineWidth(context, 1);
        CGContextSetFillColorWithColor(context, [UIColor redColor].CGColor);
        CGContextAddArc(context, self.highlightedPoint.x, self.highlightedPoint.y, 4, 0.0, M_PI * 2, YES);
        CGContextFillPath(context);
    }

    CGPathRelease(path);
    if ([self.delegate respondsToSelector:@selector(didFinishDrawing)]) {
        [self.delegate didFinishDrawing];
    }
}

void _Applier(void* info, const CGPathElement* element) {
    NSString* description = nil;
    NSDictionary* params = (__bridge NSDictionary*)info;
    NSMutableArray* logs = params[@"logs"];
    NSMutableArray* points = params[@"points"];
    switch (element->type) {
        case kCGPathElementMoveToPoint: {
            CGPoint point = element->points[0];
            description = [NSString stringWithFormat:@"%@ %f %f", @"MoveTo ", point.x, point.y];
            [points addObject:[NSValue valueWithCGPoint:point]];
            break;
        }
        case kCGPathElementAddLineToPoint: {
            CGPoint point = element->points[0];
            description = [NSString stringWithFormat:@"%@ %f %f", @"LineTo   ", point.x, point.y];
            [points addObject:[NSValue valueWithCGPoint:point]];
            break;
        }
        case kCGPathElementAddQuadCurveToPoint: {
            CGPoint point1 = element->points[0];
            CGPoint point2 = element->points[1];
            description = [NSString stringWithFormat:@"%@ %f %f %f %f", @"QuadCurveTo", point1.x, point1.y, point2.x, point2.y];
            [points addObject:[NSValue valueWithCGPoint:point2]];
            break;
        }
        case kCGPathElementAddCurveToPoint: {
            CGPoint point1 = element->points[0];
            CGPoint point2 = element->points[1];
            CGPoint point3 = element->points[2];
            description = [NSString
                stringWithFormat:@"%@ %f %f %f %f %f %f", @"CurveTo ", point1.x, point1.y, point2.x, point2.y, point3.x, point3.y];
            [points addObject:[NSValue valueWithCGPoint:point3]];
            break;
        }
        case kCGPathElementCloseSubpath: {
            description = @"ClosePath";
            break;
        }
    }
    [logs addObject:description];
}

@end

@interface CGCCGContextReplacePathWithStrokedPath () <UITableViewDataSource, UITableViewDelegate, DrawRectCompletionDelegate>

@property (strong, nonatomic, nullable) StrokeView* customView;
@property (strong, nonatomic, nullable) UISegmentedControl* pathSegmentControl;
@property (strong, nonatomic, nullable) UITableView* consoleView;
@property (strong, nonatomic, nullable) NSNumberFormatter* formatter;

@end

@implementation CGCCGContextReplacePathWithStrokedPath

- (void)viewDidLoad {
    [super viewDidLoad];

    self.formatter = [NSNumberFormatter new];
    self.formatter.numberStyle = NSNumberFormatterDecimalStyle;

    self.view.backgroundColor = [UIColor whiteColor];

    self.customView = [[StrokeView alloc] initWithFrame:CGRectMake(0, 0, self.view.bounds.size.width, self.view.bounds.size.height / 2)];
    self.customView.delegate = self;
    self.customView.strokedPathType = StrokedPathTypeLine;
    self.customView.logs = [NSMutableArray new];
    [self.view addSubview:self.customView];

    UILabel* switchLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, self.view.bounds.size.height / 2 + 5, 150, 20)];
    switchLabel.text = @"Show Stroked Path:";
    [self.view addSubview:switchLabel];

    self.pathSegmentControl = [[UISegmentedControl alloc] initWithFrame:CGRectMake(8, 8, 300, 30)];
    [self.pathSegmentControl addTarget:self action:@selector(segmentedControlValueDidChange:) forControlEvents:UIControlEventValueChanged];
    [self.pathSegmentControl insertSegmentWithTitle:@"Line" atIndex:0 animated:false];
    [self.pathSegmentControl insertSegmentWithTitle:@"CopyStroke" atIndex:1 animated:false];
    [self.pathSegmentControl insertSegmentWithTitle:@"RepalceStroked" atIndex:2 animated:false];
    [self.pathSegmentControl setSelectedSegmentIndex:self.customView.strokedPathType];
    [self.view addSubview:self.self.pathSegmentControl];

    self.consoleView = [[UITableView alloc] initWithFrame:CGRectMake(0,
                                                                     self.view.bounds.size.height / 2 + 30,
                                                                     self.view.bounds.size.width,
                                                                     self.view.bounds.size.height / 2 - 30)];
    [self.consoleView setRowHeight:15];
    [self.consoleView setDataSource:self];
    [self.consoleView setDelegate:self];
    [self.view addSubview:self.consoleView];
}


-(void)segmentedControlValueDidChange:(UISegmentedControl *)segment
{
    switch (segment.selectedSegmentIndex) {
        case 0:
            self.customView.strokedPathType = StrokedPathTypeLine;
            break;
        case 1:
            self.customView.strokedPathType = StrokedPathTypeCopyStroke;
            break;
        case 2:
            self.customView.strokedPathType = StrokedPathTypeReplaceStroke;
            break;
    }
    
    self.customView.highlightedPoint = CGPointMake(0, 0);
    [self.customView setNeedsDisplay];
}



#pragma mark UITableViewDataSource

- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.customView.logs count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    static NSString* identifier = @"Cell";
    NSInteger logLabelTag = 1;
    UILabel* logLabel;
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
        logLabel = [UILabel new];
        [logLabel setBackgroundColor:[UIColor clearColor]];
        [logLabel setTextColor:[UIColor blackColor]];
        [logLabel setFont:[UIFont systemFontOfSize:10]];
        [logLabel setLineBreakMode:NSLineBreakByWordWrapping];
        [logLabel setTag:logLabelTag];
        [[cell contentView] addSubview:logLabel];
        [logLabel setTranslatesAutoresizingMaskIntoConstraints:NO];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:logLabel
                                                                     attribute:NSLayoutAttributeTop
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeTop
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:logLabel
                                                                     attribute:NSLayoutAttributeLeft
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeLeft
                                                                    multiplier:1.0f
                                                                      constant:10.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:logLabel
                                                                     attribute:NSLayoutAttributeRight
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeRight
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
        [cell.contentView addConstraint:[NSLayoutConstraint constraintWithItem:logLabel
                                                                     attribute:NSLayoutAttributeBottom
                                                                     relatedBy:NSLayoutRelationEqual
                                                                        toItem:cell.contentView
                                                                     attribute:NSLayoutAttributeBottom
                                                                    multiplier:1.0f
                                                                      constant:0.0f]];
    } else {
        logLabel = [[cell contentView] viewWithTag:logLabelTag];
    }

    if (indexPath.row < [self.customView.logs count]) {
        NSString* text = self.customView.logs[indexPath.row];
        [logLabel setText:text];
    }

    return cell;
}

#pragma mark UITableViewDelegate

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    NSString* selectionString = self.customView.logs[indexPath.row];
    NSArray<NSString*>* components = [selectionString componentsSeparatedByString:@" "];
    if ([components count] > 2) {
        NSString* xString = components[[components count] - 2];
        NSString* yString = components[[components count] - 1];
        NSNumber* x = [self.formatter numberFromString:xString];
        NSNumber* y = [self.formatter numberFromString:yString];
        if (x && y) {
            CGPoint point = CGPointMake([x floatValue], [y floatValue]);
            self.customView.highlightedPoint = point;
            [self.customView setNeedsDisplay];
        }
    }
    [tableView deselectRowAtIndexPath:indexPath animated:NO];
}

#pragma mark DrawRectCompletionDelegate

- (void)didFinishDrawing {
    [self.consoleView reloadData];
}

@end
