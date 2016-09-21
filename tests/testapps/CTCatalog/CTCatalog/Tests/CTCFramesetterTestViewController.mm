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

#import "CTCFramesetterTestViewController.h"

@interface CTFramesetterTestView : UIView {
}

@property (nonatomic, copy) NSString* text;
@property (nonatomic) id<CTFramesetterTestViewDelegate> drawDelegate;

@end

@implementation CTFramesetterTestView {
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
    CGColorSpaceRef colorspace = CGColorSpaceCreateDeviceRGB();
    CGContextSetStrokeColorWithColor(context, color.CGColor);
    CGContextMoveToPoint(context, 0, 0);
    CGContextAddRect(context, rect);
    CGContextStrokePath(context);

    CGPathRelease(path);
    CGColorSpaceRelease(colorspace);

    CFRetain(framesetter);
    [_drawDelegate refreshValuesForFramesetter:framesetter];
}

@end

@implementation CTCFramesetterTestViewController {
    CTFramesetterTestView* _framesetterView;
    CTFramesetterTestView* _suggestedFrameSizeView;
    UITextField* _textField;
    UITableView* _functionsView;
    UISlider* _widthSlider;
    UISlider* _heightSlider;
    NSMutableArray* _functionCells;
}

- (void)viewDidLayoutSubviews {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    _textField.frame = CGRectMake(0, 0, width, 30);
    [_textField setNeedsDisplay];
    _widthSlider.frame = CGRectMake(0, 30, width / 2, 70);
    [_widthSlider setNeedsDisplay];
    _heightSlider.frame = CGRectMake(width / 2, 30, width / 2, 70);
    [_heightSlider setNeedsDisplay];
    _functionsView.frame = CGRectMake(0, 300, width, 300);
    [_functionsView setNeedsDisplay];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];
    CGFloat width = CGRectGetWidth(self.view.bounds);
    // Adds textbox to change text
    _textField = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, width, 30)];
    _textField.text = @"the quick brown fox jumps over the lazy dog. THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
    _textField.delegate = self;
    [self.view addSubview:_textField];

    _widthSlider = [[UISlider alloc] initWithFrame:CGRectMake(0, 30, width / 2, 70)];
    _widthSlider.minimumValue = 20.0;
    _widthSlider.maximumValue = width;
    _widthSlider.value = width / 2;
    _widthSlider.continuous = NO;
    [_widthSlider addTarget:self action:@selector(refreshViews) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_widthSlider];

    _heightSlider = [[UISlider alloc] initWithFrame:CGRectMake(width / 2, 30, width / 2, 70)];
    _heightSlider.minimumValue = 20.0;
    _heightSlider.maximumValue = 100.0;
    _heightSlider.value = 100.0;
    _heightSlider.continuous = NO;
    [_heightSlider addTarget:self action:@selector(refreshViews) forControlEvents:UIControlEventValueChanged];
    [self.view addSubview:_heightSlider];

    // Create table view to pair function names with results/UNIMPLEMENTED
    _functionsView = [[UITableView alloc] initWithFrame:CGRectMake(0, 300, width, 300) style:UITableViewStylePlain];
    _functionsView.dataSource = self;
    _functionsView.delegate = self;
    [self.view addSubview:_functionsView];

    _functionCells = [NSMutableArray new];

    // Draws the three alignment boxes
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
    CGFloat width = CGRectGetWidth(self.view.bounds);
    // Create frame of text
    _framesetterView = [[CTFramesetterTestView alloc] initWithFrame:CGRectMake(0, 100, width, 100)];
    _framesetterView.backgroundColor = [UIColor whiteColor];
    // Allows input of \n and \t to insert newlines and tabs respectively
    _framesetterView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];

    // Sets view to call updateTableViews when done drawing
    _framesetterView.drawDelegate = self;
    [self.view addSubview:_framesetterView];
}

// Update frameview for new text or new boxsize
- (void)refreshViews {
    [_framesetterView removeFromSuperview];
    [_suggestedFrameSizeView removeFromSuperview];
    [_functionCells removeAllObjects];
    [self drawTests];
}

// Text Field Methods

- (void)textFieldDidEndEditing:(UITextField*)textField {
    // User changed textbox value so we need to update text
    [self refreshViews];
}

// Called by framesetter test view to give us framesetter for testing
- (void)refreshValuesForFramesetter:(CTFramesetterRef)framesetter {
    CGFloat width = CGRectGetWidth(self.view.bounds);
    CGSize suggestedSize = CTFramesetterSuggestFrameSizeWithConstraints(framesetter,
                                                                        CFRangeMake(0, 0),
                                                                        nullptr,
                                                                        CGSizeMake(_widthSlider.value, _heightSlider.value),
                                                                        nullptr);
    [_functionCells
        addObject:createTextCell(@"CTFramesetterSuggestFrameSizeWithConstraints",
                                 [NSString stringWithFormat:@"width: %f, height: %f", suggestedSize.width, suggestedSize.height])];
    [_functionCells addObject:createTextCell(@"CTFramesetterGetTypeSetter",
                                             [NSString stringWithFormat:@"%@", CTFramesetterGetTypesetter(framesetter)])];

    ADD_UNIMPLEMENTED(_functionCells, @"CTFramesetterGetTypeID");
    [_functionsView reloadData];

    _suggestedFrameSizeView = [[CTFramesetterTestView alloc] initWithFrame:CGRectMake(0, 200, suggestedSize.width, suggestedSize.height)];
    _suggestedFrameSizeView.backgroundColor = [UIColor whiteColor];
    _suggestedFrameSizeView.text =
        [[_textField.text stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"] stringByReplacingOccurrencesOfString:@"\\t"
                                                                                                                  withString:@"\t"];
    [self.view addSubview:_suggestedFrameSizeView];
    CFRelease(framesetter);
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
