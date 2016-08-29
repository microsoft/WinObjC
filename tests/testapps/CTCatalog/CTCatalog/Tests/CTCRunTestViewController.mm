
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

#import "CTCRunTestViewController.h"

@interface CTRunTestView : UIView {
}

@property (nonatomic) id<CTRunTestViewDelegate> drawDelegate;

@end

@implementation CTRunTestView {
}

- (void)drawRect:(CGRect)rect {
    UIColor* color = [UIColor blueColor];

    CGContextRef context = UIGraphicsGetCurrentContext();

    // Aligns origin for our frame
    CGContextTranslateCTM(context, 0.0f, self.bounds.size.height);

    // Flips y-axis for our frame
    CGContextScaleCTM(context, 1.0f, -1.0f);

    // Creates path with current rectangle
    CGMutablePathRef path = CGPathCreateMutable();
    CGPathAddRect(path, NULL, self.bounds);

    // Create style setting to match given alignment
    CTParagraphStyleSetting setting;

    setting.spec = kCTParagraphStyleSpecifierAlignment;
    setting.valueSize = sizeof(CTTextAlignment);
    CTTextAlignment alignment = kCTCenterTextAlignment;
    setting.value = &alignment;
    CTParagraphStyleRef paragraphStyle = CTParagraphStyleCreate(&setting, 1);

    UIFont* font = [UIFont systemFontOfSize:20];
    CTFontRef myCFFont = CTFontCreateWithName((__bridge CFStringRef)[font fontName], [font pointSize], NULL);
    // Make dictionary for attributed string with font, color, and alignment
    NSDictionary* attributesDict = [NSDictionary dictionaryWithObjectsAndKeys:(__bridge id)myCFFont,
                                                                              (id)kCTFontAttributeName,
                                                                              color.CGColor,
                                                                              (id)kCTForegroundColorAttributeName,
                                                                              (__bridge id)paragraphStyle,
                                                                              (id)kCTParagraphStyleAttributeName,
                                                                              nil];

    NSString* text = @"CTRun";
    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)text, (__bridge CFDictionaryRef)attributesDict);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFRelease(attrString);

    // Creates frame for framesetter with current attributed string
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CFArrayRef lines = CTFrameGetLines(frame);
    CTLineRef line = static_cast<CTLineRef>(CFArrayGetValueAtIndex(lines, 0));
    CFArrayRef runs = CTLineGetGlyphRuns(line);
    CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 0));

    // Flips y-axis for our frame
    CGContextSetTextPosition(context, 0.0, 10.0);
    CTRunDraw(run, context, CFRangeMake(0, 0));

    // Creates outline
    CGContextSetLineWidth(context, 2.0);
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGContextSetStrokeColorWithColor(context, color.CGColor);
    CGContextMoveToPoint(context, 0, 0);
    CGContextAddRect(context, rect);
    CGContextStrokePath(context);

    CGColorSpaceRelease(colorspace);
    [_drawDelegate refreshValuesForRun:run];
}

@end

@implementation CTCRunTestViewController {
    CTRunTestView* _runView;
    UITableView* _testsView;
    NSMutableArray* _testCells;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];

    // Create table view to pair lines with frame origins
    _testsView = [[UITableView alloc] initWithFrame:CGRectMake(40, 320, 1000, 400) style:UITableViewStylePlain];
    _testsView.dataSource = self;
    _testsView.delegate = self;
    [self.view addSubview:_testsView];

    _testCells = [NSMutableArray new];

    // Draws the frameview
    [self drawTests];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (void)drawTests {
    // Create frame of text
    _runView = [[CTRunTestView alloc] initWithFrame:CGRectMake(40, 100, 400, 200)];
    _runView.backgroundColor = [UIColor whiteColor];

    // Sets view to call updateTableViews when done drawing
    _runView.drawDelegate = self;
    [self.view addSubview:_runView];
}

// Update texts to new font/size
- (void)refreshViews {
    [_runView removeFromSuperview];
    [_testCells removeAllObjects];
    [self drawTests];
}

// Called by text frame when done drawing to get lines from frame
- (void)refreshValuesForRun:(CTRunRef)run {
    [_testCells addObject:createTextCell(@"CTRunGetGlyphCount", [NSString stringWithFormat:@"%ld", CTRunGetGlyphCount(run)])];
    [_testCells addObject:createTextCell(@"CTRunGetAttributes - Attributes:", @"Values:")];
    NSDictionary* attributes = (__bridge NSDictionary*)CTRunGetAttributes(run);
    for (NSString* key in attributes.allKeys) {
        [_testCells addObject:createTextCell(key, [[attributes objectForKey:key] description])];
    }

    CGPoint points[5];
    CTRunGetPositions(run, CFRangeMake(0, 0), points);
    [_testCells addObject:createTextCell(@"CTRunGetPositions - Index:", @"Point: {x, y}")];
    for (CFIndex i = 0; i < 5; ++i) {
        [_testCells addObject:createTextCell([NSString stringWithFormat:@"%ld", i],
                                             [NSString stringWithFormat:@"{%f, %f}", points[i].x, points[i].y])];
    }

    CGSize advances[5];
    CTRunGetAdvances(run, CFRangeMake(0, 0), advances);
    [_testCells addObject:createTextCell(@"CTRunGetAdvances - Index:", @"Advance: {width, height}")];
    for (CFIndex i = 0; i < 5; ++i) {
        [_testCells addObject:createTextCell([NSString stringWithFormat:@"%ld", i],
                                             [NSString stringWithFormat:@"{%f, %f}", advances[i].width, advances[i].height])];
    }

    CGFloat ascent, descent, leading;
    double width = CTRunGetTypographicBounds(run, CFRangeMake(0, 0), &ascent, &descent, &leading);
    [_testCells
        addObject:createTextCell(
                      @"CTRunGetTypographicBounds",
                      [NSString stringWithFormat:@"width: %f, ascent: %f, descent: %f, leading: %f", width, ascent, descent, leading])];

    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetStatus");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetGlyphsPtr");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetGlyphs");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetPositionsPtr");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetAdvancesPtr");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetStringIndicesPtr");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetStringIndices");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetImageBounds");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetTextMatrix");
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetTypeID");

    [_testsView reloadData];
}

// Text Field Methods

- (void)textFieldDidEndEditing:(UITextField*)textField {
    // User changed textbox value so we need to update text
    [self refreshViews];
}

// Table View Methods

- (float)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 80.0f;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_testCells count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    return [_testCells objectAtIndex:indexPath.row];
}
@end
