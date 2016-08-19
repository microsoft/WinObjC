
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

    // Draws the text in the frame
    CTFrameDraw(frame, context);

    // Creates outline
    CGContextSetLineWidth(context, 2.0);
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGContextSetStrokeColorWithColor(context, color.CGColor);
    CGContextMoveToPoint(context, 0, 0);
    CGContextAddRect(context, rect);
    CGContextStrokePath(context);

    CGColorSpaceRelease(colorspace);
    [_drawDelegate refreshValuesForFrame:frame];
}

@end

@implementation CTCFrameTestViewController {
    CTFrameTestView* _frameView;
    UITableView* _linesView;
    UITextField* _textField;
    NSMutableArray* _lineCells;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    // Adds textbox to change text
    _textField = [[UITextField alloc] initWithFrame:CGRectMake(40, 40, 300, 30)];
    _textField.text = @"the quick brown fox jumps over the lazy dog. THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    _textField.delegate = self;
    [self.view addSubview:_textField];

    // Create table view to pair lines with frame origins
    _linesView = [[UITableView alloc] initWithFrame:CGRectMake(40, 320, 1000, 400) style:UITableViewStylePlain];
    _linesView.dataSource = self;
    _linesView.delegate = self;
    [self.view addSubview:_linesView];

    _lineCells = [NSMutableArray new];

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
    _frameView = [[CTFrameTestView alloc] initWithFrame:CGRectMake(40, 100, 400, 200)];
    _frameView.backgroundColor = [UIColor whiteColor];
    // Allows input of \n and \t to insert newlines and tabs respectively
    _frameView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];

    // Sets view to call updateTableViews when done drawing
    _frameView.drawDelegate = self;
    [self.view addSubview:_frameView];
}

// Update texts to new font/size
- (void)refreshViews {
    [_frameView removeFromSuperview];
    [_lineCells removeAllObjects];
    [self drawTests];
}

// Called by text frame when done drawing to get lines from frame
- (void)refreshValuesForFrame:(CTFrameRef)frame {
    [_lineCells addObject:createTextCell(@"CTFrameGetLineOrigins", @"CTFrameGetLines")];

    CFArrayRef lines = CTFrameGetLines(frame);
    CFIndex count = CFArrayGetCount(lines);
    CGPoint lineOrigins[count];
    CTFrameGetLineOrigins(frame, CFRangeMake(0, count), lineOrigins);
    UITableViewCell* cell;
    for (CFIndex i = 0; i < count; ++i) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"FrameLines"];
        cell.textLabel.text = [NSString stringWithFormat:@"X: %f, Y: %f", lineOrigins[i].x, lineOrigins[i].y];
        CTFrameLineTestView* textLabel = [[CTFrameLineTestView alloc] initWithFrame:CGRectMake(0, 0, 400, 60)];
        textLabel.backgroundColor = [UIColor whiteColor];
        textLabel.lineRef = static_cast<CTLineRef>(CFArrayGetValueAtIndex(lines, i));
        cell.accessoryView = textLabel;
        [_lineCells addObject:cell];
    }

    ADD_UNIMPLEMENTED(_lineCells, @"CTFrameGetStringRange");
    ADD_UNIMPLEMENTED(_lineCells, @"CTFrameGetVisibleStringRange");
    ADD_UNIMPLEMENTED(_lineCells, @"CTFrameGetPath");
    ADD_UNIMPLEMENTED(_lineCells, @"CTFrameGetFrameAttributes");
    ADD_UNIMPLEMENTED(_lineCells, @"CTFrameGetTypeID");

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
