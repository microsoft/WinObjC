//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#import "TextDisplayViewController.h"

int const NumberOfDrawWithAttrTestCases = 4;
int const NumberOfSizeWithAttrTestCases = 5;
int const DefaultHeightOfCell = 70;
int const DefaultWidthOfCell = 300;
int const DefaultHeightOfDrawArea = 60;
int const DefaultWidthOfDrawArea = 300;
int const CharsToDisplayInRing = 26;
int const DefaultFontSize = 16;
int const DefaultShadowWidth = 10;
int const DefaultShadowHeight = 10;
NSString* const TestString = @"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
NSMutableArray* rows;

@implementation TextDrawerController {
}

- (id)init {
    self = [super init];
    rows = [NSMutableArray new];

    NSString* title;

    // Add new test cases here order can effect cell height
    title = @"Blue Bold System Font Of Size 16";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:0]]];
    title = @"CGSize";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:1]]];

    title = @"Green Ariel System Font Of Size 16";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:2]]];
    title = @"CGSize";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:3]]];

    title = @"Default Bold Font of Size 16  with 10px Green Shadow";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:4]]];
    title = @"CGSizet";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:5]]];

    title = @"Default Bold Font of Size 16 Font with 10px Shadow";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:6]]];
    title = @"CGSize";
    [rows addObject:[self makeTestCellWithTitle:title WithAccessoryUIView:[self makeTextDrawer:7]]];

    title = @"Capatalized Alphabet Drawn in a circle. Black Background Green Text Size 12 Default Font";
    [rows
        addObject:[self makeTestCellWithTitle:title
                          WithAccessoryUIView:[self makeTextDrawer:8 WithCustomHeight:300 WithCustomBackgroundColor:[UIColor blackColor]]]];

    title = @"UITextView with 18pt Ariel Font Scrollable White Text";
    [rows addObject:[self makeTestCellWithTitle:title WithSubUIView:[self basicUITextView]]];

    return self;
}

- (TextDrawer*)makeTextDrawer:(int)testNumber {
    return [self makeTextDrawer:testNumber WithCustomHeight:DefaultHeightOfDrawArea WithCustomBackgroundColor:[UIColor whiteColor]];
}

- (TextDrawer*)makeTextDrawer:(int)testNumber WithCustomHeight:(int)customeHeight WithCustomBackgroundColor:(UIColor*)backgroundColor {
    TextDrawer* uiview;
    uiview = [[TextDrawer alloc] initWithFrame:CGRectMake(0, 0, DefaultWidthOfDrawArea, customeHeight) WithUICase:testNumber];
    uiview.backgroundColor = backgroundColor;
    return uiview;
}

- (UITableViewCell*)makeTestCellWithTitle:(NSString*)title WithSubUIView:(UIView*)uiView {
    UITableViewCell* cell = [self makeTestCellTitle:title];
    UIView* uiView2 = [[UIView alloc] initWithFrame:CGRectMake(0, 0, DefaultWidthOfDrawArea, 300)];
    [uiView2 addSubview:uiView];
    cell.accessoryView = uiView2;
    return cell;
}

- (UITableViewCell*)makeTestCellWithTitle:(NSString*)title WithAccessoryUIView:(UIView*)uiView {
    UITableViewCell* cell = [self makeTestCellTitle:title];
    cell.accessoryView = uiView;
    return cell;
}
- (UITableViewCell*)makeTestCellTitle:(NSString*)title {
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.backgroundColor = [UIColor whiteColor];
    cell.textLabel.text = title;
    cell.textLabel.textColor = [UIColor blackColor];
    return cell;
}

- (UITextView*)basicUITextView {
    UITextView* uiTextView = [[UITextView alloc] initWithFrame:CGRectMake(0, 0, DefaultWidthOfDrawArea, 300)];
    uiTextView.textColor = [UIColor blackColor];
    uiTextView.font = [UIFont fontWithName:@"Arial" size:18.0];
    uiTextView.backgroundColor = [UIColor whiteColor];

    uiTextView.text = @"Lorem ipsum dolor sit amet lorem a ut massa quam tempus maecenas. Eu consequat ipsum magnis quisque. Etiam luctus "
                      @"dictum natoque ullamcorper dolor quam quisque metus. Dui imperdiet eget ante tellus. Nullam sem aenean. Pede "
                      @"donec lorem ultricies eleifend imperdiet integer phasellus blandit dictum nulla eget. Nulla fringilla sit "
                      @"pulvinar eu vel semper orci. Vel lorem ante ut. Eleifend vulputate rhoncus. Ultricies dolor venenatis amet sit "
                      @"aenean ante magnis imperdiet rhoncus tellus elementum. Etiam amet ante enim. Tellus adipiscing consequat. Dolor "
                      @"justo adipiscing nisi amet. Adipiscing aliquam eleifend lorem ante fringilla integer elementum quis felis libero "
                      @"pretium justo. Veni tellus id. Etiam quam vitae leo aenean et vivamus rhoncus nec. Nulla adipiscing parturient "
                      @"sit porttitor et nec quam ultricies integer nullam. Lorem dui eu vitae ultricies tellus eget quis felis dolor "
                      @"tincidunt aenean semper. Vitae quis dolor natoque eleifend justo phasellus mollis pulvinar venenatis ac pede sem "
                      @"pellentesque. Eget commodo nam quam sem ipsum vici ligula ante.";

    uiTextView.returnKeyType = UIReturnKeyDefault;
    uiTextView.keyboardType = UIKeyboardTypeDefault;
    uiTextView.scrollEnabled = YES;
    uiTextView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    return uiTextView;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.title = @"Text Display Mode";

    [self tableView].allowsSelection = NO;
}

- (float)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    // Special height for circular word display
    if (indexPath.row == 8 || indexPath.row == 9) {
        //  Circular letter view and UITextView row need more height
        return 350.0f;
    }
    return DefaultHeightOfCell;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [rows count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    return [rows objectAtIndex:indexPath.row];
}

@end

@implementation TextDrawer {
    // Which test to run
    int testNumber;
}
- (id)initWithFrame:(CGRect)rect WithUICase:(int)testChoice {
    testNumber = testChoice;

    return [super initWithFrame:rect];
}

- (void)drawRect:(CGRect)rect {
    // Chooses which test to run
    switch (testNumber) {
        case 0:
            [self drawBasicAtPoint:rect];
            break;
        case 1:
            [self sizeBasic:rect];
            break;
        case 2:
            [self drawAtPointWithFont:rect];
            break;
        case 3:
            [self sizeWithFont:rect];
            break;
        case 4:
            [self drawAtPointWithShadowColorWithOffset:rect];
            break;
        case 5:
            [self sizeWithShadowColorWithOffset:rect];
            break;
        case 6:
            [self drawAtPointWithOffset:rect];
            break;
        case 7:
            [self sizeWithOffset:rect];
            break;
        case 8:
            [self drawAtPointCircleText:rect];
            break;
    }
}

- (void)drawBasicAtPoint:(CGRect)rect {
    UIFont* font = [UIFont boldSystemFontOfSize:DefaultFontSize];
    UIColor* color = [UIColor blueColor];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font, UITextAttributeFont, color, UITextAttributeTextColor, nil];
    [TestString drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2) withAttributes:attrs];
}

- (void)drawAtPointWithFont:(CGRect)rect {
    UIFont* font = [UIFont fontWithName:@"Arial" size:18];
    UIColor* color = [UIColor greenColor];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font, UITextAttributeFont, color, UITextAttributeTextColor, nil];
    [TestString drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2) withAttributes:attrs];
}

// ShadowColor and ShadowOffset is currently Unsupported
- (void)drawAtPointWithShadowColorWithOffset:(CGRect)rect {
    UIFont* font = [UIFont boldSystemFontOfSize:DefaultFontSize];
    UIColor* color = [UIColor blueColor];
    UIColor* shadowColor = [UIColor greenColor];
    CGSize size = CGSizeMake(DefaultShadowWidth, DefaultShadowHeight);
    NSValue* shadowOffset = [NSValue valueWithCGSize:size];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font,
                                                                     UITextAttributeFont,
                                                                     color,
                                                                     UITextAttributeTextColor,
                                                                     shadowColor,
                                                                     UITextAttributeTextShadowColor,
                                                                     shadowOffset,
                                                                     UITextAttributeTextShadowOffset,
                                                                     nil];
    [TestString drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2) withAttributes:attrs];
}

// ShadowOffset is currently Unsupported
- (void)drawAtPointWithOffset:(CGRect)rect {
    UIFont* font = [UIFont boldSystemFontOfSize:DefaultFontSize];
    UIColor* color = [UIColor blueColor];
    CGSize size = CGSizeMake(DefaultShadowWidth, DefaultShadowHeight);
    NSValue* shadowOffset = [NSValue valueWithCGSize:size];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font,
                                                                     UITextAttributeFont,
                                                                     color,
                                                                     UITextAttributeTextColor,
                                                                     shadowOffset,
                                                                     UITextAttributeTextShadowOffset,
                                                                     nil];
    [TestString drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2) withAttributes:attrs];
}

- (void)sizeBasic:(CGRect)rect {
    UIFont* font = [UIFont boldSystemFontOfSize:DefaultFontSize];
    UIColor* color = [UIColor blackColor];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font, UITextAttributeFont, color, UITextAttributeTextColor, nil];
    CGSize cgSize = [TestString sizeWithAttributes:attrs];
    [[NSString stringWithFormat:@"%f, %f", cgSize.width, cgSize.height] drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2)
                                                                     withAttributes:attrs];
}

- (void)sizeWithFont:(CGRect)rect {
    UIFont* font = [UIFont fontWithName:@"Arial" size:18];
    UIColor* color = [UIColor blackColor];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font, UITextAttributeFont, color, UITextAttributeTextColor, nil];
    CGSize cgSize = [TestString sizeWithAttributes:attrs];
    [[NSString stringWithFormat:@"%f, %f", cgSize.width, cgSize.height] drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2)
                                                                     withAttributes:attrs];
}

// ShadowColor and ShadowOffset is currently Unsupported
- (void)sizeWithShadowColorWithOffset:(CGRect)rect {
    UIFont* font = [UIFont boldSystemFontOfSize:DefaultFontSize];
    UIColor* color = [UIColor blackColor];
    UIColor* shadowColor = [UIColor greenColor];

    CGSize size = CGSizeMake(DefaultShadowWidth, DefaultShadowHeight);
    NSValue* shadowOffset = [NSValue valueWithCGSize:size];

    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font,
                                                                     UITextAttributeFont,
                                                                     color,
                                                                     UITextAttributeTextColor,
                                                                     shadowColor,
                                                                     UITextAttributeTextShadowColor,
                                                                     shadowOffset,
                                                                     UITextAttributeTextShadowOffset,
                                                                     nil];
    CGSize cgSize = [TestString sizeWithAttributes:attrs];
    [[NSString stringWithFormat:@"%f, %f", cgSize.width, cgSize.height] drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2)
                                                                     withAttributes:attrs];
}

// ShadowOffset is currently Unsupported
- (void)sizeWithOffset:(CGRect)rect {
    UIFont* font = [UIFont boldSystemFontOfSize:DefaultFontSize];
    UIColor* color = [UIColor blackColor];

    CGSize size = CGSizeMake(DefaultShadowWidth, DefaultShadowHeight);
    NSValue* shadowOffset = [NSValue valueWithCGSize:size];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font,
                                                                     UITextAttributeFont,
                                                                     color,
                                                                     UITextAttributeTextColor,
                                                                     shadowOffset,
                                                                     UITextAttributeTextShadowOffset,
                                                                     nil];
    CGSize cgSize = [TestString sizeWithAttributes:attrs];
    [[NSString stringWithFormat:@"%f, %f", cgSize.width, cgSize.height] drawAtPoint:CGPointMake(rect.origin.x, rect.size.height / 2)
                                                                     withAttributes:attrs];
}

- (void)drawAtPointCircleText:(CGRect)rect {
    UIFont* font = [UIFont boldSystemFontOfSize:12];
    UIColor* color = [UIColor greenColor];
    NSDictionary* attrs = [NSDictionary dictionaryWithObjectsAndKeys:font, UITextAttributeFont, color, UITextAttributeTextColor, nil];

    CGPoint center = CGPointMake(rect.size.width / 2, rect.size.height / 2);
    CGFloat radius = center.x * 0.50f;

    // Loop through each char in the string and place it around the center point.
    for (int i = 0; i < TestString.length; i++) {
        UIFont* font = [UIFont boldSystemFontOfSize:14];
        NSString* letter = [TestString substringWithRange:NSMakeRange(i, 1)];

        CGSize letterSize = [letter sizeWithAttributes:@{ UITextAttributeFont : font }];
        CGFloat temp = M_PI - (i * (2 * M_PI / CharsToDisplayInRing));
        CGFloat xCord = center.x + (radius * sin(temp)) - (letterSize.width / 2.0);
        CGFloat yCord = center.y + (radius * cos(temp)) - (letterSize.height / 2.0);

        [letter drawAtPoint:CGPointMake(xCord, yCord) withAttributes:attrs];
    }
}
@end