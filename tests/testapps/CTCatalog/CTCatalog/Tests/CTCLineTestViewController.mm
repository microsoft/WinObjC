
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
    UIColor* color = [UIColor blueColor];

    CGContextRef context = UIGraphicsGetCurrentContext();

    // Aligns origin for our frame
    CGContextTranslateCTM(context, 0.0f, self.bounds.size.height);

    // Flips y-axis for our frame
    CGContextScaleCTM(context, 1.0f, -1.0f);
    CGContextSetTextPosition(context, 0.0, 10.0);
    CTLineDraw(_lineRef, context);
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

    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)_text, (__bridge CFDictionaryRef)attributesDict);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFRelease(attrString);

    // Creates frame for framesetter with current attributed string
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CFArrayRef lines = CTFrameGetLines(frame);
    if (CFArrayGetCount(lines) > 0) {
        CTLineRef line = static_cast<CTLineRef>(CFArrayGetValueAtIndex(lines, 0));

        CGContextSetTextPosition(context, 0.0, 10.0);
        CTLineDraw(line, context);

        // Creates outline
        CGContextSetLineWidth(context, 2.0);
        CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
        CGContextSetStrokeColorWithColor(context, color.CGColor);
        CGContextMoveToPoint(context, 0, 0);
        CGContextAddRect(context, rect);
        CGContextStrokePath(context);

        CGColorSpaceRelease(colorspace);
        [_drawDelegate refreshValuesForLine:line];
    }
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
    // Adds textbox to change text
    _textField = [[UITextField alloc] initWithFrame:CGRectMake(40, 40, 300, 30)];
    _textField.text = @"the quick brown fox jumps over the lazy dog.";
    _textField.delegate = self;
    [self.view addSubview:_textField];

    _truncationSlider = [[UISlider alloc] initWithFrame:CGRectMake(440, 40, 100, 100)];
    _truncationSlider.minimumValue = 0.0;
    _truncationSlider.maximumValue = 400.0;
    _truncationSlider.value = 200.0;
    _truncationSlider.continuous = NO;
    [_truncationSlider addTarget:self action:@selector(refreshViews) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_truncationSlider];

    // Create table view to pair lines with frame origins
    _linesView = [[UITableView alloc] initWithFrame:CGRectMake(40, 300, 1000, 400) style:UITableViewStylePlain];
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

- (void)drawTests {
    // Create frame of text
    _lineView = [[CTLineTestView alloc] initWithFrame:CGRectMake(40, 100, 400, 60)];
    _lineView.backgroundColor = [UIColor whiteColor];
    // Allows input of \n and \t to insert newlines and tabs respectively
    _lineView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];

    // Sets view to call updateTableViews when done drawing
    _lineView.drawDelegate = self;
    [self.view addSubview:_lineView];
}

// Update texts to new font/size
- (void)refreshViews {
    [_lineView removeFromSuperview];
    [_truncatedLineView removeFromSuperview];
    [_functionCells removeAllObjects];
    [self drawTests];
}

// Called by text frame when done drawing to get lines from frame
- (void)refreshValuesForLine:(CTLineRef)line {
    _truncatedLineView = [[CTTruncatedLineTestView alloc] initWithFrame:CGRectMake(40, 180, 400, 60)];
    _truncatedLineView.backgroundColor = [UIColor whiteColor];
    // Allows input of \n and \t to insert newlines and tabs respectively
    _truncatedLineView.lineRef = CTLineCreateTruncatedLine(line, _truncationSlider.value, kCTLineTruncationEnd, NULL);
    [self.view addSubview:_truncatedLineView];

    [_functionCells addObject:createTextCell(@"CTLineGetGlyphCount", [NSString stringWithFormat:@"%d", CTLineGetGlyphCount(line)])];
    [_functionCells addObject:createTextCell(@"CTLineGetGlyphRuns- should be 1",
                                             [NSString stringWithFormat:@"%d", CFArrayGetCount(CTLineGetGlyphRuns(line))])];
    [_functionCells addObject:createTextCell(@"CTLineGetStringRange",
                                             [NSString stringWithFormat:@"{ %d, %d }",
                                                                        CTLineGetStringRange(line).location,
                                                                        CTLineGetStringRange(line).length])];

    CGFloat ascent, descent, leading;
    double width = CTLineGetTypographicBounds(line, &ascent, &descent, &leading);
    [_functionCells
        addObject:createTextCell(@"CTLineGetTypographicBounds",
                                 [NSString
                                     stringWithFormat:@"width: %f, ascent %f, descent %f, leading %f", width, ascent, descent, leading])];

    [_functionCells
        addObject:createTextCell(@"CTLineGetStringIndexForPosition (200px)",
                                 [NSString stringWithFormat:@"%d", CTLineGetStringIndexForPosition(line, CGPointMake(200.0, 0.0))])];

    CGFloat secondaryOffset;
    CGFloat primaryOffset = CTLineGetOffsetForStringIndex(line, 5, &secondaryOffset);
    [_functionCells addObject:createTextCell(@"CTLineGetOffsetForStringIndex (5)",
                                             [NSString stringWithFormat:@"primary %f, secondary %f", primaryOffset, secondaryOffset])];

    ADD_UNIMPLEMENTED(_functionCells, @"CTLineCreateJustifiedLine");
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineCreateWithAttributedString");
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetPenOffsetForFlush");
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetImageBounds");
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetTrailingWhitespaceWidth");
    ADD_UNIMPLEMENTED(_functionCells, @"CTLineGetTypeID");
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
