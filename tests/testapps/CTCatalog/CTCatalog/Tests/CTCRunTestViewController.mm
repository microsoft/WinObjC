
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

static const NSString* c_text = @"XCTRunX";
static const CFRange c_visibleRange = CFRangeMake(1, 5);

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
    CFAutorelease(paragraphStyle);

    UIFont* font = [UIFont systemFontOfSize:20];
    CTFontRef myCFFont = CTFontCreateWithName((__bridge CFStringRef)[font fontName], [font pointSize], NULL);
    CFAutorelease(myCFFont);
    // Make dictionary for attributed string with font, color, and alignment
    NSDictionary* attributesDict = [NSDictionary dictionaryWithObjectsAndKeys:(__bridge id)myCFFont,
                                                                              (id)kCTFontAttributeName,
                                                                              color.CGColor,
                                                                              (id)kCTForegroundColorAttributeName,
                                                                              (__bridge id)paragraphStyle,
                                                                              (id)kCTParagraphStyleAttributeName,
                                                                              nil];

    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)c_text, (__bridge CFDictionaryRef)attributesDict);
    CFAutorelease(attrString);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFAutorelease(framesetter);

    // Creates frame for framesetter with current attributed string
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CFAutorelease(frame);

    CFArrayRef lines = CTFrameGetLines(frame);
    CTLineRef line = static_cast<CTLineRef>(CFArrayGetValueAtIndex(lines, 0));
    CFArrayRef runs = CTLineGetGlyphRuns(line);
    CTRunRef run = static_cast<CTRunRef>(CFArrayGetValueAtIndex(runs, 0));

    // Flips y-axis for our frame
    CGContextSetTextPosition(context, 0.0, 0.0);
    CTRunDraw(run, context, c_visibleRange);

    // Creates outline
    CGContextSetLineWidth(context, 2.0);
    CGContextSetStrokeColorWithColor(context, color.CGColor);
    CGContextMoveToPoint(context, 0, 0);
    CGContextAddRect(context, rect);
    CGContextStrokePath(context);

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

    CGFloat width = CGRectGetWidth(self.view.bounds);

    // Create frame of text
    _runView = [[CTRunTestView alloc] initWithFrame:CGRectMake(0, 0, width, 200)];
    _runView.backgroundColor = [UIColor whiteColor];
    // Sets view to call updateTableViews when done drawing
    _runView.drawDelegate = self;
    [self.view addSubview:_runView];

    // Create table view to pair lines with frame origins
    _testsView = [[UITableView alloc] initWithFrame:CGRectMake(0, 200, width, 400) style:UITableViewStylePlain];
    _testsView.dataSource = self;
    _testsView.delegate = self;
    [self.view addSubview:_testsView];

    _testCells = [NSMutableArray new];

    // Draws the frameview
    [self drawTests];
}

- (void)viewDidLayoutSubviews {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    _testsView.frame = CGRectMake(0, 200, width, 400);
    [_testsView setNeedsDisplay];
    _runView.frame = CGRectMake(0, 0, width, 200);
    [_runView setNeedsDisplay];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (void)drawTests {
    [_runView setNeedsDisplay];
}

// Update texts to new font/size
- (void)refreshViews {
    [_testCells removeAllObjects];
    [self drawTests];
}

// Called by text frame when done drawing to get lines from frame
- (void)refreshValuesForRun:(CTRunRef)run {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    [_testCells addObject:createTextCell(@"CTRunGetGlyphCount", [NSString stringWithFormat:@"%ld", CTRunGetGlyphCount(run)], width / 2)];
    [_testCells addObject:createTextCell(@"CTRunGetAttributes - Attributes:", @"Values:", width / 2)];
    NSDictionary* attributes = (__bridge NSDictionary*)CTRunGetAttributes(run);
    for (NSString* key in attributes.allKeys) {
        [_testCells addObject:createTextCell(key, [[attributes objectForKey:key] description], width / 2)];
    }

    CGPoint points[5];
    CTRunGetPositions(run, c_visibleRange, points);
    const CGPoint* pointPtr = CTRunGetPositionsPtr(run);
    [_testCells addObject:createTextCell(@"CTRunGetPositions - {x, y}:", @"CTRunGetPositionsPtr - {x, y}", width / 2)];
    for (CFIndex i = 0; i < 5; ++i) {
        [_testCells addObject:createTextCell([NSString stringWithFormat:@"{%f, %f}", points[i].x, points[i].y],
                                             [NSString stringWithFormat:@"{%f, %f}", pointPtr[i].x, pointPtr[i].y],
                                             width / 2)];
    }

    CGSize advances[5];
    CTRunGetAdvances(run, c_visibleRange, advances);
    const CGSize* advancePtr = CTRunGetAdvancesPtr(run);
    [_testCells addObject:createTextCell(@"CTRunGetAdvances - {width, height}:", @"CTRunGetAdvancesPtr {width, height}", width / 2)];
    for (CFIndex i = 0; i < 5; ++i) {
        [_testCells addObject:createTextCell([NSString stringWithFormat:@"{%f, %f}", advances[i].width, advances[i].height],
                                             [NSString stringWithFormat:@"{%f, %f}", advancePtr[i].width, advancePtr[i].height],
                                             width / 2)];
    }

    CGGlyph glyphs[5];
    CTRunGetGlyphs(run, c_visibleRange, glyphs);
    const CGGlyph* glyphPtr = CTRunGetGlyphsPtr(run);
    [_testCells addObject:createTextCell(@"CTRunGetGlyphs:", @"CTRunGetGlyphsPtr:", width / 2)];
    for (CFIndex i = 0; i < 5; ++i) {
        [_testCells addObject:createTextCell([NSString stringWithFormat:@"%d", glyphs[i]],
                                             [NSString stringWithFormat:@"%d", glyphPtr[i]],
                                             width / 2)];
    }

    CFIndex indices[5];
    CTRunGetStringIndices(run, c_visibleRange, indices);
    const CFIndex* indicesPtr = CTRunGetStringIndicesPtr(run);
    [_testCells addObject:createTextCell(@"CTRunGetStringIndices:", @"CTRunGetStringIndicesPtr:", width / 2)];
    for (CFIndex i = 0; i < 5; ++i) {
        [_testCells addObject:createTextCell([NSString stringWithFormat:@"%d", indices[i]],
                                             [NSString stringWithFormat:@"%d", indicesPtr[i]],
                                             width / 2)];
    }

    CGFloat ascent, descent, leading;
    double totalWidth = CTRunGetTypographicBounds(run, c_visibleRange, &ascent, &descent, &leading);
    [_testCells
        addObject:createTextCell(@"CTRunGetTypographicBounds",
                                 [NSString
                                     stringWithFormat:@"width: %f, ascent: %f, descent: %f, leading: %f", width, ascent, descent, leading],
                                 width / 2)];

    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetStatus", width / 2);
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetImageBounds", width / 2);
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetTextMatrix", width / 2);
    ADD_UNIMPLEMENTED(_testCells, @"CTRunGetTypeID", width / 2);

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
