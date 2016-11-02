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

#import "CTCFrameTestViewController.h"

@interface CTFrameLineTestView : UIView {
}

@property (nonatomic) CTLineRef lineRef;

@end

@implementation CTFrameLineTestView {
}

- (void)setLineRef:(CTLineRef)lineRef {
    if (_lineRef) {
        CFRelease(_lineRef);
    }

    _lineRef = lineRef;
    CFRetain(_lineRef);
}

- (void)dealloc {
    if (_lineRef) {
        CFRelease(_lineRef);
    }
}

- (void)drawRect:(CGRect)rect {
    CGContextRef context = UIGraphicsGetCurrentContext();

    // Aligns origin for our frame
    CGContextTranslateCTM(context, 0.0f, self.bounds.size.height);

    // Flips y-axis for our frame
    CGContextScaleCTM(context, 1.0f, -1.0f);
    CGContextSetTextPosition(context, 0.0, 10.0);
    CTLineDraw(_lineRef, context);
}

@end

@interface CTFrameTestView : UIView {
}

@property (nonatomic, copy) NSString* text;
@property (nonatomic) id<CTFrameTestViewDelegate> drawDelegate;

@end

@implementation CTFrameTestView {
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
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)_text, (__bridge CFDictionaryRef)attributesDict);
    CFAutorelease(attrString);

    CTFramesetterRef framesetter = CTFramesetterCreateWithAttributedString(attrString);
    CFAutorelease(framesetter);

    // Creates frame for framesetter with current attributed string
    CTFrameRef frame = CTFramesetterCreateFrame(framesetter, CFRangeMake(0, 0), path, NULL);
    CFAutorelease(frame);

    // Draws the text in the frame
    CTFrameDraw(frame, context);

    // Creates outline
    CGContextSetLineWidth(context, 2.0);
    CGContextSetStrokeColorWithColor(context, color.CGColor);
    CGContextMoveToPoint(context, 0, 0);
    CGContextAddRect(context, rect);
    CGContextStrokePath(context);

    CGPathRelease(path);

    [_drawDelegate refreshValuesForFrame:frame];
}

@end

@implementation CTCFrameTestViewController {
    CTFrameTestView* _frameView;
    UITableView* _linesView;
    UITextField* _textField;
    UIButton* _refreshButton;
    NSMutableArray* _lineCells;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat width = CGRectGetWidth(self.view.bounds);
    // Adds textbox to change text
    _textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 2 * width / 3, 50)];
    _textField.text = @"the quick brown fox jumps over the lazy dog. THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    _textField.delegate = self;
    [self.view addSubview:_textField];

    _refreshButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    _refreshButton.frame = CGRectMake(2 * width / 3, 0, width / 3, 50);
    [_refreshButton addTarget:self action:@selector(refreshViews) forControlEvents:UIControlEventTouchDown];
    [_refreshButton setTitle:@"Refresh" forState:UIControlStateNormal];
    [self.view addSubview:_refreshButton];

    // Create frame of text
    _frameView = [[CTFrameTestView alloc] initWithFrame:CGRectMake(0, 50, 2 * width / 3, 200)];
    _frameView.backgroundColor = [UIColor whiteColor];
    _frameView.autoresizingMask = UIViewAutoresizingFlexibleWidth;
    // Sets view to call updateTableViews when done drawing
    _frameView.drawDelegate = self;
    [self.view addSubview:_frameView];

    // Create table view to pair lines with frame origins
    _linesView = [[UITableView alloc] initWithFrame:CGRectMake(0, 250, width, 400) style:UITableViewStylePlain];
    _linesView.dataSource = self;
    _linesView.delegate = self;
    [self.view addSubview:_linesView];

    _lineCells = [NSMutableArray new];

    // Draws the frameview
    [self drawTests];
}

- (void)viewDidLayoutSubviews {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    _textField.frame = CGRectMake(0, 0, 2 * width / 3, 50);
    [_textField setNeedsDisplay];
    _refreshButton.frame = CGRectMake(2 * width / 3, 0, width / 3, 50);
    [_refreshButton setNeedsDisplay];
    _linesView.frame = CGRectMake(0, 250, width, 400);
    [_linesView setNeedsDisplay];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

- (void)drawTests {
    // Update the text in the frame
    // Allows input of \n and \t to insert newlines and tabs respectively
    _frameView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];
    [_frameView setNeedsDisplay];
}

// Update texts to new font/size
- (void)refreshViews {
    [_lineCells removeAllObjects];
    [self drawTests];
}

// Called by text frame when done drawing to get lines from frame
- (void)refreshValuesForFrame:(CTFrameRef)frame {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    [_lineCells addObject:createTextCell(@"CTFrameGetLineOrigins", @"CTFrameGetLines", width / 2)];

    CFArrayRef lines = CTFrameGetLines(frame);
    CFIndex count = CFArrayGetCount(lines);
    CGPoint lineOrigins[count];
    CTFrameGetLineOrigins(frame, CFRangeMake(0, count), lineOrigins);
    UITableViewCell* cell;
    for (CFIndex i = 0; i < count; ++i) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"FrameLines"];
        cell.textLabel.text = [NSString stringWithFormat:@"X: %f, Y: %f", lineOrigins[i].x, lineOrigins[i].y];
        CTFrameLineTestView* textLabel = [[CTFrameLineTestView alloc] initWithFrame:CGRectMake(0, 0, 2 * width / 3, 60)];
        textLabel.backgroundColor = [UIColor whiteColor];
        textLabel.lineRef = static_cast<CTLineRef>(CFArrayGetValueAtIndex(lines, i));
        cell.accessoryView = textLabel;
        [_lineCells addObject:cell];
    }

    [_lineCells addObject:createTextCell(@"CTFrameGetStringRange",
                                         [NSString stringWithFormat:@"{ %ld, %ld }",
                                                                    CTFrameGetStringRange(frame).location,
                                                                    CTFrameGetStringRange(frame).length],
                                         width / 2)];

    [_lineCells addObject:createTextCell(@"CTFrameGetVisibleStringRange",
                                         [NSString stringWithFormat:@"{ %ld, %ld }",
                                                                    CTFrameGetVisibleStringRange(frame).location,
                                                                    CTFrameGetVisibleStringRange(frame).length],
                                         width / 2)];

    [_lineCells addObject:createTextCell(@"CTFrameGetPath", [NSString stringWithFormat:@"%@", CTFrameGetPath(frame)], width / 2)];
    ADD_UNIMPLEMENTED(_lineCells, @"CTFrameGetFrameAttributes", width / 2);
    ADD_UNIMPLEMENTED(_lineCells, @"CTFrameGetTypeID", width / 2);

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
    return [_lineCells count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    return [_lineCells objectAtIndex:indexPath.row];
}
@end
