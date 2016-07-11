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

#import "TextFieldsViewController.h"

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 260;
static const CGFloat c_height = 40;
static const CGFloat c_labelFontSize = 17.0f;

@implementation TextFieldsViewController {
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
    textField.secureTextEntry = secureTextEntry;
    textField.font = [UIFont systemFontOfSize:17.0];
    textField.placeholder = placeHolder;
    textField.keyboardType = keyboardType;
    textField.borderStyle = borderStyle;
    textField.textAlignment = textAlignment;
    textField.spellCheckingType = spellCheckingType;
    textField.delegate = self;
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
    textField.delegate = self;
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
                                               placeHolder:@"password"
                                              keyboardType:UIKeyboardTypeNumberPad
                                               borderStyle:UITextBorderStyleRoundedRect
                                             textAlignment:UITextAlignmentLeft
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 1. Normal text with right aligned and blue ground
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor blueColor]
                                           secureTextEntry:NO
                                               placeHolder:@"blue background, right aligned"
                                              keyboardType:UIKeyboardTypeASCIICapable
                                               borderStyle:UITextBorderStyleRoundedRect
                                             textAlignment:UITextAlignmentRight
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 2. center aligned, red text, line border and spell check enabled
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor redColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"red text, alignment center"
                                              keyboardType:UIKeyboardTypeDefault
                                               borderStyle:UITextBorderStyleLine
                                             textAlignment:UITextAlignmentCenter
                                         spellCheckingType:UITextSpellCheckingTypeYes]];

    // Row 3. UITextField rejects focus
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"This control reject focus"
                                              keyboardType:UIKeyboardTypeDefault
                                               borderStyle:UITextBorderStyleLine
                                             textAlignment:UITextAlignmentCenter
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 4. URL keyboard and no border
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"type in URL"
                                              keyboardType:UIKeyboardTypeURL
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextAlignmentLeft
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 5. Name and Phone and using "UITextBorderStyleBezel" style border which is
    // treated as line
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"type in your Name and Phone"
                                              keyboardType:UIKeyboardTypeNamePhonePad
                                               borderStyle:UITextBorderStyleNone
                                             textAlignment:UITextBorderStyleBezel
                                         spellCheckingType:UITextSpellCheckingTypeNo]];

    // Row 6. Email address
    [_textFields addObject:[self _createTextFieldWithColor:[UIColor blackColor]
                                                background:[UIColor lightGrayColor]
                                           secureTextEntry:NO
                                               placeHolder:@"type in your email address"
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
                                               placeHolder:@"type in name or Phone Number"
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
                                               placeHolder:@"background image"
                                               borderStyle:UITextBorderStyleLine
                                           backgroundImage:[UIImage imageNamed:@"photo1.jpg"]]];

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
    if (textField == _textFields[3]) {
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
    }

    [cell addSubview:[_textFields objectAtIndex:indexPath.row]];
    return cell;
}

@end
