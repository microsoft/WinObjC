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

#import "CTCFontTestViewController.h"

// Creates table cell with title and button which responds to UIControlEventTouchDown with [target action]
static UITableViewCell* createButtonCell(NSString* title, id target, SEL action) {
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.textLabel.text = title;
    UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.frame = CGRectMake(0, 0, 200, 50);
    [button addTarget:target action:action forControlEvents:UIControlEventTouchDown];
    [button setTitle:@"SELECT" forState:UIControlStateNormal];
    cell.accessoryView = button;
    return cell;
}

@interface CTFontTestView : UIView {
}

@property (nonatomic) CTFontRef font;

@end

@implementation CTFontTestView {
}

- (void)drawRect:(CGRect)rect {
    UIColor* color = [UIColor blueColor];

    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetFillColorWithColor(context, color.CGColor);

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
    CTTextAlignment alignment = kCTRightTextAlignment;
    setting.value = &alignment;
    CTParagraphStyleRef paragraphStyle = CTParagraphStyleCreate(&setting, 1);
    CFAutorelease(paragraphStyle);

    CTFontRef myCFFont = CTFontCreateWithName(CTFontCopyFullName(_font), CTFontGetSize(_font), NULL);
    CFAutorelease(myCFFont);

    // Make dictionary for attributed string with font, color, and alignment
    NSDictionary* attributesDict = [NSDictionary dictionaryWithObjectsAndKeys:(__bridge id)myCFFont,
                                                                              (id)kCTFontAttributeName,
                                                                              kCFBooleanFalse,
                                                                              (id)kCTForegroundColorFromContextAttributeName,
                                                                              (__bridge id)paragraphStyle,
                                                                              (id)kCTParagraphStyleAttributeName,
                                                                              nil];

    NSString* text = @"jackdaws love my big sphinx of quartz. JACKDAWS LOVE MY BIG SPHINX OF QUARTZ.";
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
}
@end

@implementation CTCFontTestViewController {
    UIPickerView* _fontPicker;
    CTFontRef _font;
    NSArray* _fonts;

    UIPickerView* _nameKeyPicker;
    CFStringRef _nameKey;
    NSArray* _nameKeys;
}

- (instancetype)init {
    if (self = [super init]) {
        // This inherits from table view so we can't inherit from base, meaning we have to set our title and background here
        self.title = [[NSStringFromClass([self class]) stringByReplacingOccurrencesOfString:@"CTC" withString:@""]
            stringByReplacingOccurrencesOfString:@"ViewController"
                                      withString:@""];

        self.tableView.allowsSelection = NO;
        self.view.backgroundColor = [UIColor whiteColor];

        // Query all available fonts and add them to array by name
        NSMutableArray* fonts = [NSMutableArray new];
        for (NSString* familyName in [UIFont familyNames]) {
            [fonts addObjectsFromArray:[UIFont fontNamesForFamilyName:familyName]];
        }
        _fonts = [fonts sortedArrayUsingSelector:@selector(localizedCaseInsensitiveCompare:)];

        // Set current font to the default size of 20
        _font = CTFontCreateWithName((__bridge CFStringRef)_fonts[0], 20, NULL);

        // Creates picker to choose font by name
        _fontPicker = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
        _fontPicker.delegate = self;
        _fontPicker.dataSource = self;

        // Creates array of rows in the table
        _rows = [NSMutableArray new];

        // Creates a cell to house the font picker and adds it to the beginning of the table
        UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"CTFontPickerCell"];
        cell.accessoryView = _fontPicker;
        cell.textLabel.text = @"Select font";
        [_rows addObject:cell];

        // Array of NameKeys for CTFontCopyName
        _nameKeys = @[
            (__bridge NSString*)kCTFontCopyrightNameKey,
            (__bridge NSString*)kCTFontFamilyNameKey,
            (__bridge NSString*)kCTFontSubFamilyNameKey,
            (__bridge NSString*)kCTFontStyleNameKey,
            (__bridge NSString*)kCTFontUniqueNameKey,
            (__bridge NSString*)kCTFontFullNameKey,
            (__bridge NSString*)kCTFontVersionNameKey,
            (__bridge NSString*)kCTFontPostScriptNameKey,
            (__bridge NSString*)kCTFontTrademarkNameKey,
            (__bridge NSString*)kCTFontManufacturerNameKey,
            (__bridge NSString*)kCTFontDesignerNameKey,
            (__bridge NSString*)kCTFontDescriptionNameKey,
            (__bridge NSString*)kCTFontVendorURLNameKey,
            (__bridge NSString*)kCTFontDesignerURLNameKey,
            (__bridge NSString*)kCTFontLicenseNameKey,
            (__bridge NSString*)kCTFontLicenseURLNameKey,
            (__bridge NSString*)kCTFontSampleTextNameKey,
            (__bridge NSString*)kCTFontPostScriptCIDNameKey,
            (__bridge NSString*)kCTFontVariationAxisIdentifierKey,
            (__bridge NSString*)kCTFontVariationAxisMinimumValueKey,
            (__bridge NSString*)kCTFontVariationAxisMaximumValueKey,
            (__bridge NSString*)kCTFontVariationAxisDefaultValueKey,
            (__bridge NSString*)kCTFontVariationAxisNameKey,
            (__bridge NSString*)kCTFontFeatureTypeIdentifierKey,
            (__bridge NSString*)kCTFontFeatureTypeNameKey,
            (__bridge NSString*)kCTFontFeatureTypeExclusiveKey,
            (__bridge NSString*)kCTFontFeatureTypeSelectorsKey,
            (__bridge NSString*)kCTFontFeatureSelectorIdentifierKey,
            (__bridge NSString*)kCTFontFeatureSelectorNameKey,
            (__bridge NSString*)kCTFontFeatureSelectorDefaultKey,
            (__bridge NSString*)kCTFontFeatureSelectorSettingKey
        ];

        // Sets current nameKey to first in array
        _nameKey = (__bridge CFStringRef)_nameKeys[0];

        // Creates a picker to choose nameKey by value
        _nameKeyPicker = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
        _nameKeyPicker.delegate = self;
        _nameKeyPicker.dataSource = self;

        // Creates cell to house namekey picker and adds it below font picker in the table
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"CTFontPickerCell"];
        cell.accessoryView = _nameKeyPicker;
        cell.textLabel.text = @"Select nameKey";
        [_rows addObject:cell];

        // Draws the rest of the rows in the table holding the tests
        [self createTests];
    }
    return self;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
}

// Creates a row in the table for each CTFont function with the title of the function
// For functions returning some value from the font, creates a row with the return value
// For functions creating a CTFont, creates a row with a button updating the current font to the returned value
// For unimplemented functions, creates a row with the value "UNIMPLEMENTED"
- (void)createTests {
    // Adds row with pangram in selected font
    CGFloat width = CGRectGetWidth(self.view.bounds);
    CTFontTestView* pangramView = [[CTFontTestView alloc] initWithFrame:CGRectMake(0, 0, width / 2, 100)];
    pangramView.backgroundColor = [UIColor whiteColor];
    pangramView.font = _font;
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.textLabel.text = @"Example Text";
    cell.accessoryView = pangramView;
    [_rows addObject:cell];

    // Creation functions
    [_rows addObject:createButtonCell(@"CTFontCreateWithName", self, @selector(createWithNameWasSelected))];
    [_rows addObject:createButtonCell(@"CTFontCreateCopyWithSymbolicTraits", self, @selector(createCopyWithSymbolicTraitsWasSelected))];
    [_rows addObject:createButtonCell(@"CTFontCreateWithGraphicsFont", self, @selector(createWithGraphicsFontWasSelected))];

    // There is no straightforward way to show this works properly without rigorously testing, which is beyond the scope of this test page
    CGFontRef cgFont = CTFontCopyGraphicsFont(_font, nullptr);
    NSString* result = [NSString stringWithFormat:@"%d", CFStringCompare(CGFontCopyFullName(cgFont), CTFontCopyFullName(_font), 0)];
    [_rows addObject:createTextCell(@"CTFontCopyGraphicsFont- should be 0", result, width / 2)];

    // Copy and Get functions
    [_rows addObject:createTextCell(@"CTFontCopyPostScriptName", (__bridge NSString*)CTFontCopyPostScriptName(_font), width / 2)];
    [_rows addObject:createTextCell(@"CTFontCopyFamilyName", (__bridge NSString*)CTFontCopyFamilyName(_font), width / 2)];
    [_rows addObject:createTextCell(@"CTFontCopyFullName", (__bridge NSString*)CTFontCopyFullName(_font), width / 2)];
    [_rows addObject:createTextCell([NSString stringWithFormat:@"CTFontCopyName:%@", _nameKey],
                                    (__bridge NSString*)CTFontCopyName(_font, _nameKey),
                                    width / 2)];

    [_rows addObject:createTextCell(@"CTFontGetAscent", [NSString stringWithFormat:@"%f", CTFontGetAscent(_font)], width / 2)];
    [_rows addObject:createTextCell(@"CTFontGetDescent", [NSString stringWithFormat:@"%f", CTFontGetDescent(_font)], width / 2)];
    [_rows addObject:createTextCell(@"CTFontGetSize", [NSString stringWithFormat:@"%f", CTFontGetSize(_font)], width / 2)];

    UniChar characters[6];
    [@"Glyphs" getCharacters:characters range:NSMakeRange(0, 6)];
    CGGlyph glyphs[6];
    CTFontGetGlyphsForCharacters(_font, characters, glyphs, 6);
    [_rows addObject:createTextCell(
                         @"CTFontGetGlyphsForCharacters:Glyphs",
                         [NSString stringWithFormat:@"%d %d %d %d %d %d", glyphs[0], glyphs[1], glyphs[2], glyphs[3], glyphs[4], glyphs[5]],
                         width / 2)];

    CGSize advances[6];
    double totalWidth = CTFontGetAdvancesForGlyphs(_font, kCTFontDefaultOrientation, glyphs, advances, 6);
    [_rows addObject:createTextCell(@"CTFontGetAdvancesForGlyphs:Glyphs - Total Width",
                                    [NSString stringWithFormat:@"%f", totalWidth],
                                    width / 2)];
    [_rows addObject:createTextCell(@"CTFontGetAdvancesForGlyphs:Glyphs - Individual Widths",
                                    [NSString stringWithFormat:@"%f %f %f %f %f %f",
                                                               advances[0].width,
                                                               advances[1].width,
                                                               advances[2].width,
                                                               advances[3].width,
                                                               advances[4].width,
                                                               advances[5].width],
                                    width / 2)];

    // Unimplemented functions
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyAttribute", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyAvailableTables", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyCharacterSet", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyDisplayName", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyFeatureSettings", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyFeatures", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyFontDescriptor", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyLocalizedName", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopySupportedLanguages", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyTable", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyTraits", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyVariation", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyVariationAxes", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCopyWithFamily", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCreateCopyWithAttributes", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCreateFontDescriptorAndOptions", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCreateForString", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCreatePathForGlyph", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCreateUIFontForLanguage", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontCreateWithNameAndOptions", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontDrawGlyphs", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetBoundingBox", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetBoundingRectsForGlyphs", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetCapHeight", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetGlyphCount", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetGlyphWithName", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetGlyphsForCharacters", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetLeading", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetLigatureCaretPositions", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetMatrix", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetSlantAngle", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetStringEncoding", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetTypeID", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetUnderlinePosition", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetUnderlineThickness", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetUnitsPerEm", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetVerticalTranslationsForGlyphs", width / 2);
    ADD_UNIMPLEMENTED(_rows, @"CTFontGetXHeight", width / 2);

    CGFontRelease(cgFont);
}

- (void)refreshTests {
    // Remove all rows from table except the pickers, which should not change during tests
    [_rows removeObjectsInRange:NSMakeRange(2, _rows.count - 2)];

    // Generate test cells and add them to the table
    [self createTests];

    // Force table to reload to show updated tests
    [self.tableView reloadData];
}

// Font Picker Methods
// Argument pickerView will either be _fontPicker or _nameKeysPicker

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView*)pickerView {
    // Both pickers only have one column
    return 1;
}

- (NSInteger)pickerView:(UIPickerView*)pickerView numberOfRowsInComponent:(NSInteger)component {
    if (pickerView == _fontPicker) {
        return _fonts.count;
    }
    return _nameKeys.count;
}

- (NSString*)pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    if (pickerView == _fontPicker) {
        return _fonts[row];
    }
    return _nameKeys[row];
}
- (void)pickerView:(UIPickerView*)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    if (pickerView == _fontPicker) {
        _font = CTFontCreateWithName((__bridge CFStringRef)_fonts[row], 20, NULL);
    } else {
        _nameKey = (__bridge CFStringRef)_nameKeys[row];
    }
    [self refreshTests];
}

// Table View Methods

- (float)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row < 3) {
        // Picker views and pangram view
        return 240.0f;
    }
    return 50.0f;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_rows count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    return [_rows objectAtIndex:indexPath.row];
}

// Button Methods

- (void)createWithNameWasSelected {
    CFStringRef name = CTFontCopyFullName(_font);
    CFRelease(_font);
    _font = CTFontCreateWithName(name, 20, nullptr);
    CFRelease(name);
    [self refreshTests];
}

- (void)createCopyWithSymbolicTraitsWasSelected {
    CTFontRef temp = _font;
    _font = CTFontCreateCopyWithSymbolicTraits(_font, 20, nullptr, 0, 0);
    CFRelease(temp);
    [self refreshTests];
}

- (void)createWithGraphicsFontWasSelected {
    CGFontRef cgFont = CTFontCopyGraphicsFont(_font, nullptr);
    CFRelease(_font);
    _font = CTFontCreateWithGraphicsFont(cgFont, 20, nullptr, nullptr);
    [self refreshTests];
}

@end
