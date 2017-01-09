
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

#import "CTCLineTestViewController.h"

@interface CTTruncatedLineTestView : UIView {
}

@property (nonatomic) CTLineRef lineRef;

@end

@implementation CTTruncatedLineTestView {
}

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();

    // Aligns origin for our frame
    CGContextTranslateCTM(context, 0.0f, self.bounds.size.height);

    // Flips y-axis for our frame
    CGContextScaleCTM(context, 1.0f, -1.0f);
    CGContextSetTextPosition(context, 0.0, 0.0);
    CTLineDraw(_lineRef, context);
    CFRelease(_lineRef);
}

@end

@interface CTLineTestView : UIView {
}

@property (nonatomic, copy) NSString* text;
@property (nonatomic) id<CTLineTestViewDelegate> drawDelegate;

@end

@implementation CTLineTestView {
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
                                                                              nil];

    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)_text, (__bridge CFDictionaryRef)attributesDict);
    CFAutorelease(attrString);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFAutorelease(framesetter);

    // Creates frame for framesetter with current attributed string
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CFAutorelease(frame);

    CFArrayRef lines = CTFrameGetLines(frame);
    if (CFArrayGetCount(lines) > 0) {
        CTLineRef line = static_cast<CTLineRef>(CFArrayGetValueAtIndex(lines, 0));

        CGContextSetTextPosition(context, 0.0, 10.0);

        CTLineDraw(line, context);

        // Creates outline
        CGContextSetLineWidth(context, 2.0);
        CGContextSetStrokeColorWithColor(context, color.CGColor);
        CGContextMoveToPoint(context, 0, 0);
        CGContextAddRect(context, rect);
        CGContextStrokePath(context);

        [_drawDelegate refreshValuesForLine:line];
    }

    CGPathRelease(path);
}

@end

@implementation CTCLineTestViewController {
    CTLineTestView* _lineView;
    CTTruncatedLineTestView* _truncatedLineView;
    UITableView* _linesView;
    UITextField* _textField;
    UISlider* _truncationSlider;
    NSMutableArray* _functionCells;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat width = CGRectGetWidth(self.view.bounds);
    // Adds textbox to change text
    _textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, width, 30)];
    _textField.text = @"the quick brown fox jumps over the lazy dog.";
    _textField.delegate = self;
    [self.view addSubview:_textField];

    _truncationSlider = [[UISlider alloc] initWithFrame:CGRectMake(0, 30, width, 70)];
    _truncationSlider.minimumValue = 0.0;
    _truncationSlider.maximumValue = width;
    _truncationSlider.value = width / 2;
    _truncationSlider.continuous = NO;
    [_truncationSlider addTarget:self action:@selector(refreshViews) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_truncationSlider];

    // Create frame for the text
    _lineView = [[CTLineTestView alloc] initWithFrame:CGRectMake(0, 100, width, 60)];
    _lineView.backgroundColor = [UIColor whiteColor];
    // Sets view to call updateTableViews when done drawing
    _lineView.drawDelegate = self;
    [self.view addSubview:_lineView];

    _truncatedLineView = [[CTTruncatedLineTestView alloc] initWithFrame:CGRectMake(0, 160, width, 60)];
    _truncatedLineView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:_truncatedLineView];

    // Create table view to pair lines with frame origins
    _linesView = [[UITableView alloc] initWithFrame:CGRectMake(0, 240, width, 400) style:UITableViewStylePlain];
    _linesView.dataSource = self;
    _linesView.delegate = self;
    [self.view addSubview:_linesView];

    _functionCells = [NSMutableArray new];

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

- (void)viewDidLayoutSubviews {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    _textField.frame = CGRectMake(0, 0, width, 50);
    [_textField setNeedsDisplay];
    _linesView.frame = CGRectMake(0, 240, width, 400);
    [_linesView setNeedsDisplay];
    _truncationSlider.frame = CGRectMake(0, 30, width, 70);
    _truncationSlider.maximumValue = width;
    [_truncationSlider setNeedsDisplay];
}

- (void)drawTests {
    // Update text in the frame
    // Allows input of \n and \t to insert newlines and tabs respectively
    _lineView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];
    [_lineView setNeedsDisplay];
}

// Update texts to new font/size
- (void)refreshViews {
    [_functionCells removeAllObjects];
    [self drawTests];
}

// Called by text frame when done drawing to get lines from frame
- (void)refreshValuesForLine:(CTLineRef)line {
    CGFloat width = CGRectGetWidth(self.view.bounds);

    _truncatedLineView.lineRef = CTLineCreateTruncatedLine(line, _truncationSlider.value, kCTLineTruncationEnd, NULL);
    [_truncatedLineView setNeedsDisplay];

    [_functionCells
        addObject:createTextCell(@"CTLineGetGlyphCount", [NSString stringWithFormat:@"%d", CTLineGetGlyphCount(line)], width / 2)];
    [_functionCells addObject:createTextCell(@"CTLineGetGlyphRuns- should be 1",
                                             [NSString stringWithFormat:@"%d", CFArrayGetCount(CTLineGetGlyphRuns(line))],
                                             width / 2)];
    [_functionCells addObject:createTextCell(@"CTLineGetStringRange",
                                             [NSString stringWithFormat:@"{ %d, %d }",
                                                                        CTLineGetStringRange(line).location,
                                                                        CTLineGetStringRange(line).length],
                                             width / 2)];

    CGFloat ascent, descent, leading;
    double totalWidth = CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
    [_functionCells
        addObject:createTextCell(
                      @"CTLineGetTypographicBounds",
                      [NSString stringWithFormat:@"width: %f, ascent %f, descent %f, leading %f", totalWidth, ascent, descent, leading],
                      width / 2)];

    [_functionCells
        addObject:createTextCell(@"CTLineGetStringIndexForPosition (width / 2px)",
                                 [NSString stringWithFormat:@"%d", CTLineGetStringIndexForPosition(line, CGPointMake(width / 2.0, 0.0))],
                                 width / 2)];

    CGFloat secondaryOffset;
    CGFloat primaryOffset = CTLineGetOffsetForStringIndex(line, 5, &secondaryOffset);
    [_functionCells addObject:createTextCell(@"CTLineGetOffsetForStringIndex (5)",
                                             [NSString stringWithFormat:@"primary %f, secondary %f", primaryOffset, secondaryOffset],
                                             width / 2)];

    ADD_UNIMPLEMENTED(_functionCells, @"CTLineCreateJustifiedLine", width / 2);
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetPenOffsetForFlush", width / 2);
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetImageBounds", width / 2);
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetTrailingWhitespaceWidth", width / 2);
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetTypeID", width / 2);
    [_linesView reloadData];
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
    return [_functionCells count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    return [_functionCells objectAtIndex:indexPath.row];
}

@end
