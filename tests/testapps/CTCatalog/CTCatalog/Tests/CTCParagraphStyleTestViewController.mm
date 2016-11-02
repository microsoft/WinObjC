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

#import "CTCParagraphStyleTestViewController.h"
#include <vector>

// clang-format makes these macros really nasty looking
// clang-format off

// We need the references to the pickers to be able to get the correct data for each one
// So we can't create it in a function like we do for text cells
#define ADD_PICKER(ARRAY, PICKER, TITLE, WIDTH)                                                                       \
cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"SHARED_PARAGRAPH_INPUT"]; \
cell.textLabel.text = TITLE;                                                                                          \
PICKER = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 0, WIDTH, 200)];                                           \
PICKER.delegate = self;                                                                                               \
PICKER.dataSource = self;                                                                                             \
cell.accessoryView = PICKER;                                                                                          \
[ARRAY addObject:cell];

#define ADD_TEXT_FIELD(ARRAY, FIELD, TITLE, DEFAULT_VALUE, WIDTH)                                                     \
cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"SHARED_PARAGRAPH_INPUT"]; \
cell.textLabel.text = TITLE;                                                                                          \
FIELD = [[UITextField alloc] initWithFrame:CGRectMake(0, 10, WIDTH, 30)];                                             \
FIELD.text = DEFAULT_VALUE;                                                                                           \
FIELD.delegate = self;                                                                                                \
cell.accessoryView = FIELD;                                                                                           \
[ARRAY addObject:cell];
// clang-format on

@interface CTParagraphStyleTestView : UIView {
}

@property (nonatomic) CTParagraphStyleRef paragraphStyle;

@end

@implementation CTParagraphStyleTestView {
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

    UIFont* font = [UIFont systemFontOfSize:20];
    CTFontRef myCFFont = CTFontCreateWithName((__bridge CFStringRef)[font fontName], [font pointSize], NULL);
    CFAutorelease(myCFFont);
    // Make dictionary for attributed string with font, color, and alignment
    NSDictionary* attributesDict = [NSDictionary dictionaryWithObjectsAndKeys:(__bridge id)myCFFont,
                                                                              (id)kCTFontAttributeName,
                                                                              color.CGColor,
                                                                              (id)kCTForegroundColorAttributeName,
                                                                              (__bridge id)_paragraphStyle,
                                                                              (id)kCTParagraphStyleAttributeName,
                                                                              nil];

    NSString* text = @"The quick brown fox jumps over the lazy dog.";
    CFAttributedStringRef attrString =
        CFAttributedStringCreate(kCFAllocatorDefault, (__bridge CFStringRef)text, (__bridge CFDictionaryRef)attributesDict);
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
    CFRelease(_paragraphStyle);
}

@end

@implementation CTCParagraphStyleTestViewController {
    CTParagraphStyleTestView* _styleView;
    CTParagraphStyleTestView* _styleCopyView;
    UITableView* _inputsTable;

    UITextField* _specifierFirstLineHeadIndent;
    UITextField* _specifierHeadIndent;
    UITextField* _specifierTailIndent;
    UITextField* _specifierDefaultTabInterval;
    UITextField* _specifierLineHeightMultiple;
    UITextField* _specifierMaximumLineHeight;
    UITextField* _specifierMinimumLineHeight;
    UITextField* _specifierLineSpacing;
    UITextField* _specifierParagraphSpacing;
    UITextField* _specifierParagraphSpacingBefore;
    UITextField* _specifierMaximumLineSpacing;
    UITextField* _specifierMinimumLineSpacing;
    UITextField* _specifierLineSpacingAdjustment;

    UIPickerView* _specifierAlignment;
    UIPickerView* _specifierLineBreakMode;
    UIPickerView* _specifierBaseWritingDirection;

    NSMutableArray* _inputCells;

    NSArray* _alignments;
    NSArray* _lineBreakModes;
    NSArray* _baseWritingDirections;

    NSString* _alignment;
    NSString* _lineBreakMode;
    NSString* _baseWritingDirection;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.view.backgroundColor = [UIColor whiteColor];

    _inputCells = [NSMutableArray new];

    _alignments = @[
        @"kCTLeftTextAlignment",
        @"kCTRightTextAlignment",
        @"kCTCenterTextAlignment",
        @"kCTJustifiedTextAlignment",
        @"kCTNaturalTextAlignment",
    ];

    _lineBreakModes = @[
        @"kCTLineBreakByWordWrapping",
        @"kCTLineBreakByCharWrapping",
        @"kCTLineBreakByClipping",
        @"kCTLineBreakByTruncatingHead",
        @"kCTLineBreakByTruncatingTail",
        @"kCTLineBreakByTruncatingMiddle",
    ];

    _baseWritingDirections = @[ @"kCTWritingDirectionNatural", @"kCTWritingDirectionLeftToRight", @"kCTWritingDirectionRightToLeft" ];

    UITableViewCell* cell;

    CGFloat width = CGRectGetWidth(self.view.bounds);
    ADD_PICKER(_inputCells, _specifierAlignment, @"kCTParagraphStyleSpecifierAlignment", width / 2);
    ADD_PICKER(_inputCells, _specifierLineBreakMode, @"kCTParagraphStyleSpecifierLineBreakMode", width / 2);
    ADD_PICKER(_inputCells, _specifierBaseWritingDirection, @"kCTParagraphStyleSpecifierBaseWritingDirection", width / 2);

    ADD_TEXT_FIELD(_inputCells, _specifierFirstLineHeadIndent, @"kCTParagraphStyleSpecifierFirstLineHeadIndent", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierHeadIndent, @"kCTParagraphStyleSpecifierHeadIndent", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierTailIndent, @"kCTParagraphStyleSpecifierTailIndent", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierDefaultTabInterval, @"kCTParagraphStyleSpecifierDefaultTabInterval", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierLineHeightMultiple, @"kCTParagraphStyleSpecifierLineHeightMultiple", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierMaximumLineHeight, @"kCTParagraphStyleSpecifierMaximumLineHeight", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierMinimumLineHeight, @"kCTParagraphStyleSpecifierMinimumLineHeight", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierLineSpacing, @"kCTParagraphStyleSpecifierLineSpacing", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierParagraphSpacing, @"kCTParagraphStyleSpecifierParagraphSpacing", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierParagraphSpacingBefore, @"kCTParagraphStyleSpecifierParagraphSpacingBefore", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierMaximumLineSpacing, @"kCTParagraphStyleSpecifierMaximumLineSpacing", @"10000000.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierMinimumLineSpacing, @"kCTParagraphStyleSpecifierMinimumLineSpacing", @"0.0", width / 2);
    ADD_TEXT_FIELD(_inputCells, _specifierLineSpacingAdjustment, @"kCTParagraphStyleSpecifierLineSpacingAdjustment", @"0.0", width / 2);

    ADD_UNIMPLEMENTED(_inputCells, @"kCTParagraphStyleSpecifierTabStops", width / 2);

    // Create original view with input style settings
    _styleView = [[CTParagraphStyleTestView alloc] initWithFrame:CGRectMake(0, 20, width / 2, 200)];
    _styleView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:_styleView];

    // Create new view with copied style to show no changes
    _styleCopyView = [[CTParagraphStyleTestView alloc] initWithFrame:CGRectMake(width / 2, 20, width / 2, 200)];
    _styleCopyView.backgroundColor = [UIColor whiteColor];
    [self.view addSubview:_styleCopyView];

    _inputsTable = [[UITableView alloc] initWithFrame:CGRectMake(0, 220, width, 400) style:UITableViewStylePlain];
    _inputsTable.dataSource = self;
    _inputsTable.delegate = self;
    [self.view addSubview:_inputsTable];

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
    _inputsTable.frame = CGRectMake(0, 220, width, 400);
    [_inputsTable setNeedsDisplay];
}

- (void)drawTests {
    // Creates array to hold all of the settings which will be used to create CTParagraphStyleRef
    std::vector<CTParagraphStyleSetting> settings;

    // Add alignment based on selection
    CTTextAlignment alignment;
    if ([_alignment isEqualToString:@"kCTLeftTextAlignment"]) {
        alignment = kCTLeftTextAlignment;
    } else if ([_alignment isEqualToString:@"kCTRightTextAlignment"]) {
        alignment = kCTRightTextAlignment;
    } else if ([_alignment isEqualToString:@"kCTCenterTextAlignment"]) {
        alignment = kCTCenterTextAlignment;
    } else if ([_alignment isEqualToString:@"kCTJustifiedTextAlignment"]) {
        alignment = kCTJustifiedTextAlignment;
    } else {
        alignment = kCTNaturalTextAlignment;
    }
    settings.emplace_back(CTParagraphStyleSetting{ kCTParagraphStyleSpecifierAlignment, sizeof(alignment), &alignment });

    // Add line break mode based on selection
    CTLineBreakMode lineBreakMode;
    if ([_lineBreakMode isEqualToString:@"kCTLineBreakByWordWrapping"]) {
        lineBreakMode = kCTLineBreakByWordWrapping;
    } else if ([_lineBreakMode isEqualToString:@"kCTLineBreakByCharWrapping"]) {
        lineBreakMode = kCTLineBreakByCharWrapping;
    } else if ([_lineBreakMode isEqualToString:@"kCTLineBreakByClipping"]) {
        lineBreakMode = kCTLineBreakByClipping;
    } else if ([_lineBreakMode isEqualToString:@"kCTLineBreakByTruncatingHead"]) {
        lineBreakMode = kCTLineBreakByTruncatingHead;
    } else if ([_lineBreakMode isEqualToString:@"kCTLineBreakByTruncatingTail"]) {
        lineBreakMode = kCTLineBreakByTruncatingTail;
    } else {
        lineBreakMode = kCTLineBreakByTruncatingMiddle;
    }
    settings.emplace_back(CTParagraphStyleSetting{ kCTParagraphStyleSpecifierLineBreakMode, sizeof(lineBreakMode), &lineBreakMode });

    // Add base writing direction based on selection
    CTWritingDirection direction;
    if ([_baseWritingDirection isEqualToString:@"kCTWritingDirectionRightToLeft"]) {
        direction = kCTWritingDirectionRightToLeft;
    } else if ([_baseWritingDirection isEqualToString:@"kCTWritingDirectionLeftToRight"]) {
        direction = kCTWritingDirectionLeftToRight;
    } else {
        direction = kCTWritingDirectionNatural;
    }
    settings.emplace_back(CTParagraphStyleSetting{ kCTParagraphStyleSpecifierBaseWritingDirection, sizeof(direction), &direction });

    // Add the rest of the supported settings, which are all CGFloats, based on inputs
    CGFloat settingFirstLineHeadIndent = [_specifierFirstLineHeadIndent.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierFirstLineHeadIndent, sizeof(CGFloat), &settingFirstLineHeadIndent });

    CGFloat settingHeadIndent = [_specifierHeadIndent.text floatValue];
    settings.emplace_back(CTParagraphStyleSetting{ kCTParagraphStyleSpecifierHeadIndent, sizeof(CGFloat), &settingHeadIndent });

    CGFloat settingTailIndent = [_specifierTailIndent.text floatValue];
    settings.emplace_back(CTParagraphStyleSetting{ kCTParagraphStyleSpecifierTailIndent, sizeof(CGFloat), &settingTailIndent });

    CGFloat settingDefaultTabInterval = [_specifierDefaultTabInterval.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierDefaultTabInterval, sizeof(CGFloat), &settingDefaultTabInterval });

    CGFloat settingLineHeightMultiple = [_specifierLineHeightMultiple.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierLineHeightMultiple, sizeof(CGFloat), &settingLineHeightMultiple });

    CGFloat settingMaximumLineHeight = [_specifierMaximumLineHeight.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierMaximumLineHeight, sizeof(CGFloat), &settingMaximumLineHeight });

    CGFloat settingMinimumLineHeight = [_specifierMinimumLineHeight.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierMinimumLineHeight, sizeof(CGFloat), &settingMinimumLineHeight });

    CGFloat settingLineSpacing = [_specifierLineSpacing.text floatValue];
    settings.emplace_back(CTParagraphStyleSetting{ kCTParagraphStyleSpecifierLineSpacing, sizeof(CGFloat), &settingLineSpacing });

    CGFloat settingParagraphSpacing = [_specifierParagraphSpacing.text floatValue];
    settings.emplace_back(CTParagraphStyleSetting{ kCTParagraphStyleSpecifierParagraphSpacing, sizeof(CGFloat), &settingParagraphSpacing });

    CGFloat settingParagraphSpacingBefore = [_specifierParagraphSpacingBefore.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierParagraphSpacingBefore, sizeof(CGFloat), &settingParagraphSpacingBefore });

    CGFloat settingMaximumLineSpacing = [_specifierMaximumLineSpacing.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierMaximumLineSpacing, sizeof(CGFloat), &settingMaximumLineSpacing });

    CGFloat settingMinimumLineSpacing = [_specifierMinimumLineSpacing.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierMinimumLineSpacing, sizeof(CGFloat), &settingMinimumLineSpacing });

    CGFloat settingLineSpacingAdjustment = [_specifierLineSpacingAdjustment.text floatValue];
    settings.emplace_back(
        CTParagraphStyleSetting{ kCTParagraphStyleSpecifierLineSpacingAdjustment, sizeof(CGFloat), &settingLineSpacingAdjustment });

    // Create the style with the array of settings
    CTParagraphStyleRef style = CTParagraphStyleCreate(&settings[0], settings.size());

    // Update the view with input style settings
    _styleView.paragraphStyle = style;
    [_styleView setNeedsDisplay];

    // Copy style
    CTParagraphStyleRef styleCopy = CTParagraphStyleCreateCopy(style);

    // Update new view with copied style to show no changes
    _styleCopyView.paragraphStyle = styleCopy;
    [_styleCopyView setNeedsDisplay];
}

// Update texts to new font/size
- (void)refreshViews {
    [self drawTests];
}

// Text Field Methods

- (void)textFieldDidEndEditing:(UITextField*)textField {
    // User changed textbox value so we need to update text
    [self refreshViews];
}

// Table View Methods

- (float)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    if (tableView == _inputsTable && indexPath.row < 3) {
        // Pickers
        return 300.0f;
    }
    return 80.0f;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_inputCells count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    return [_inputCells objectAtIndex:indexPath.row];
}

// Picker Methods

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView*)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView*)pickerView numberOfRowsInComponent:(NSInteger)component {
    if (pickerView == _specifierAlignment) {
        return [_alignments count];
    } else if (pickerView == _specifierLineBreakMode) {
        return [_lineBreakModes count];
    }
    return [_baseWritingDirections count];
}

- (NSString*)pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    if (pickerView == _specifierAlignment) {
        return _alignments[row];
    } else if (pickerView == _specifierLineBreakMode) {
        return _lineBreakModes[row];
    }
    return _baseWritingDirections[row];
}

- (void)pickerView:(UIPickerView*)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    if (pickerView == _specifierAlignment) {
        _alignment = _alignments[row];
    } else if (pickerView == _specifierLineBreakMode) {
        _lineBreakMode = _lineBreakModes[row];
    } else {
        _baseWritingDirection = _baseWritingDirections[row];
    }
    [self refreshViews];
}
@end
