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

#import "UITextFieldViewController.h"

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 260;
static const CGFloat c_height = 40;
static const CGFloat c_labelFontSize = 17.0f;
static const int TAG_SUBVIEW_UITEXTFIELD = 1;

@implementation UITextFieldViewController {
@private
    NSMutableArray* _textFields;
}

- (UITextField*)_createTextFieldWithColor:(UIColor*)color
                               background:(UIColor*)background
                          secureTextEntry:(BOOL)secureTextEntry
                              placeHolder:(NSString*)placeHolder
                             keyboardType:(UIKeyboardType)keyboardType
                              borderStyle:(UITextBorderStyle)borderStyle
                            textAlignment:(UITextAlignment)textAlignment
                        spellCheckingType:(UITextSpellCheckingType)spellCheckingType {
    CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
    UITextField* textField = [[UITextField alloc] initWithFrame:frame];
    textField.textColor = color;
    textField.backgroundColor = background;
    textField.font = [UIFont systemFontOfSize:17.0];
    textField.placeholder = placeHolder;
    textField.keyboardType = keyboardType;
    textField.borderStyle = borderStyle;
    textField.textAlignment = textAlignment;
    textField.spellCheckingType = spellCheckingType;
    textField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    textField.delegate = self;

    // intentially move down to make sure properties is transferred correctly
    textField.secureTextEntry = secureTextEntry;

    // Set the accessibility identifier so we can access these controls via automation
    textField.accessibilityIdentifier = [NSString stringWithFormat:@"textField_%ld", [_textFields count]];

    return textField;
}

- (UITextField*)_createTextFieldWithColor:(UIColor*)color
                              placeHolder:(NSString*)placeHolder
                              borderStyle:(UITextBorderStyle)borderStyle
                          backgroundImage:(UIImage*)backgroundImage {
    CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
    UITextField* textField = [[UITextField alloc] initWithFrame:frame];
    textField.textColor = color;
    textField.font = [UIFont systemFontOfSize:c_labelFontSize];
    textField.placeholder = placeHolder;
    textField.borderStyle = borderStyle;
    textField.background = backgroundImage;
    textField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    textField.delegate = self;

    // Set the accessibility identifier so we can access these controls via automation
    textField.accessibilityIdentifier = [NSString stringWithFormat:@"textField_%ld", [_textFields count]];

    return textField;
}

- (UITextField*)_createTextFieldWithColor:(UIColor*)color
                              placeHolder:(NSString*)placeHolder
                              borderStyle:(UITextBorderStyle)borderStyle
                                 fontSize:(CGFloat)fontSize
                          minimumFontSize:(CGFloat)minFontSize {
    CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
    UITextField* textField = [[UITextField alloc] initWithFrame:frame];
    textField.textColor = color;
    textField.font = [UIFont systemFontOfSize:fontSize];
    textField.placeholder = placeHolder;
    textField.borderStyle = borderStyle;
    textField.contentVerticalAlignment = UIControlContentVerticalAlignmentCenter;
    textField.delegate = self;
    textField.adjustsFontSizeToFitWidth = YES;
    textField.minimumFontSize = minFontSize;

    // Set the accessibility identifier so we can access these controls via automation
    textField.accessibilityIdentifier = [NSString stringWithFormat:@"textField_%ld", [_textFields count]];

    return textField;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // creating the text Fields
    _textFields = [[NSMutableArray alloc] init];

    // Row 0. password with number keyboard with Round border
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:YES
                                               placeHolder:@"Password"
                                              keyboardType:UIKeyboardTypeNumberPad
                                               borderStyle:UITextBorderStyleRoundedRect
                                             textAlignment:UITextAlignmentLeft
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 1. Normal text with right aligned and blue ground
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor blueColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Blue background, right aligned"
                                              keyboardType:UIKeyboardTypeASCIICapable
                                               borderStyle:UITextBorderStyleRoundedRect
                                             textAlignment:UITextAlignmentRight
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 2. center aligned, red text, line border and spell check enabled
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor redColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Red text, alignment center"
                                              keyboardType:UIKeyboardTypeDefault
                                               borderStyle:UITextBorderStyleLine
                                             textAlignment:UITextAlignmentCenter
                                         spellCheckingType:UITextSpellCheckingTypeYes]];

    // Row 3. UITextField rejects focus
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"This control rejects focus"
                                              keyboardType:UIKeyboardTypeDefault
                                               borderStyle:UITextBorderStyleLine
                                             textAlignment:UITextAlignmentCenter
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 4. URL keyboard and no border
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Type in URL"
                                              keyboardType:UIKeyboardTypeURL
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextAlignmentLeft
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 5. Name and Phone and using "UITextBorderStyleBezel" style border which is
    // treated as line
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Type in your Name and Phone"
                                              keyboardType:UIKeyboardTypeNamePhonePad
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextBorderStyleBezel
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 6. Email address
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Type in your email address"
                                              keyboardType:UIKeyboardTypeEmailAddress
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextBorderStyleLine
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 7. Decimal
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Decimal"
                                              keyboardType:UIKeyboardTypeDecimalPad
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextBorderStyleLine
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 8. Name or Phone number
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Type in name or Phone Number"
                                              keyboardType:UIKeyboardTypeNamePhonePad
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextBorderStyleLine
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 9. Decimal
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Phone Number"
                                              keyboardType:UIKeyboardTypePhonePad
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextBorderStyleLine
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 10. Enter to dismiss keyboard
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"Press enter to dismiss keyboard"
                                              keyboardType:UIKeyboardTypeNamePhonePad
                                               borderStyle:UIKeyboardTypePhonePad
                                             textAlignment:UITextBorderStyleLine
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 11. Background image
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor redColor]
                                               placeHolder:@"Background image"
                                               borderStyle:UITextBorderStyleLine
                                           backgroundImage:[UIImage imageNamed:@"blue_background.jpg"]]];

    // Row 12. Adjusts font size to fit width (should clamp to 14.0f)
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                               placeHolder:@"Adjusts font size 17pt"
                                               borderStyle:UITextBorderStyleLine
                                                  fontSize:17.0f
                                           minimumFontSize:1.0f]];

    // Row 13. Should not adjust font size to width (10.0f < system min size)
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                               placeHolder:@"Adjusts font size 10pt"
                                               borderStyle:UITextBorderStyleLine
                                                  fontSize:10.0f
                                           minimumFontSize:1.0f]];

    // Row 14. Adjusts font size to fit width down to 17.0f
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                               placeHolder:@"Adjusts font size 22pt"
                                               borderStyle:UITextBorderStyleLine
                                                  fontSize:22.0f
                                           minimumFontSize:17.0f]];

    // creating a Secured text entry and change it to non-secure
    UITextField* temp = [self _createTextFieldWithColor:[UIColor blackColor]
                                             background:[UIColor lightGrayColor]
                                        secureTextEntry:YES
                                            placeHolder:@"From Secure to Non-Secure"
                                           keyboardType:UIKeyboardTypeDefault
                                            borderStyle:UITextBorderStyleRoundedRect
                                          textAlignment:UITextAlignmentLeft
                                      spellCheckingType:UITextSpellCheckingTypeNo];
    temp.secureTextEntry = NO;
    [_textFields addObject:temp];

    [self tableView].allowsSelection = NO;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_textFields count];
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 60;
}

// Asks the delegate if editing should begin in the specified text field.
- (BOOL)textFieldShouldBeginEditing:(UITextField*)textField {
    if ([_textFields count] > 3 && textField == _textFields[3]) {
        return NO;
    }

    return YES;
}

- (BOOL)textFieldShouldEndEditing:(UITextField*)textField {
    return YES;
}

- (BOOL)textFieldShouldReturn:(UITextField*)textField {
    return YES;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    } else {
        // Before reuse, check if any subview in contentview is tagged with TAG_SUBVIEW_UITEXTFIELD
        // if so, we know it is a custom view that we need to remove
        UIView* subView = (UIView*)[cell.contentView viewWithTag:TAG_SUBVIEW_UITEXTFIELD];
        [subView removeFromSuperview];
    }

    // Tag UITextField subview with TAG_SUBVIEW_TEXTFIELD before adding this subview into contentview
    UIView* subView = [_textFields objectAtIndex:indexPath.row];
    subView.tag = TAG_SUBVIEW_UITEXTFIELD;
    [cell.contentView addSubview:subView];
    return cell;
}

@end
