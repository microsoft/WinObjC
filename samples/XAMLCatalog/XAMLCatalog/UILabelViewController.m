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

#import "UILabelViewController.h"

static const CGFloat c_originX = 5;
static const CGFloat c_originY = 8;
static const CGFloat c_width = 300;
static const CGFloat c_height = 50;
static const CGFloat c_labelFontSize = 17.0f;
static const int TAG_SUBVIEW_UILABEL = 1;

@implementation UILabelViewController {
@private
    NSMutableArray* _labels;
}

- (UILabel*)_createUILabelWithColor:(UIColor*)color
                               text:(NSString*)text
                      textAlignment:(NSTextAlignment)alignment
                      lineBreakMode:(UILineBreakMode)lineBreakMode
                      numberOfLines:(NSInteger)numberOfLines {
    CGRect frame = CGRectMake(c_originX, c_originY, c_width, c_height);
    UILabel* label = [[UILabel alloc] initWithFrame:frame];
    label.textColor = color;
    label.text = text;
    label.textAlignment = alignment;
    label.lineBreakMode = lineBreakMode;
    label.numberOfLines = numberOfLines;
    return label;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    // creating the text Fields
    _labels = [[NSMutableArray alloc] init];

    // Row 0. password with number keyboard with Round border
    [_labels addObject:[self _createUILabelWithColor:[UIColor blackColor]
                                                text:@"wordWrap test, You should see this string is wrapped around word"
                                       textAlignment:UITextAlignmentLeft
                                       lineBreakMode:UILineBreakModeWordWrap
                                       numberOfLines:0]];

    [_labels addObject:[self _createUILabelWithColor:[UIColor redColor]
                                                text:@"chararacterWrap is not supported, treated as wordWrap"
                                       textAlignment:UITextAlignmentLeft
                                       lineBreakMode:UILineBreakModeCharacterWrap
                                       numberOfLines:2]];

    [_labels addObject:[self _createUILabelWithColor:[UIColor blueColor]
                                                text:@"Clip and wrapping, the string is wrapped and clipped at the end of second line if "
                                                     @"the string is long enough"
                                       textAlignment:UITextAlignmentLeft
                                       lineBreakMode:UILineBreakModeClip
                                       numberOfLines:3]];

    [_labels
        addObject:[self _createUILabelWithColor:[UIColor grayColor]
                                           text:@"Clip and nowrapping, cliped at the end of first line and the rest will not wrap and show"
                                  textAlignment:UITextAlignmentLeft
                                  lineBreakMode:UILineBreakModeClip
                                  numberOfLines:1]];

    [_labels
        addObject:[self _createUILabelWithColor:[UIColor purpleColor]
                                           text:@"TailTruncation, this is a very long string, that we are using for testing TailTruncation"
                                  textAlignment:UITextAlignmentLeft
                                  lineBreakMode:UILineBreakModeTailTruncation
                                  numberOfLines:0]];

    [_labels addObject:[self _createUILabelWithColor:[UIColor blackColor]
                                                text:@"HeadTruncation but shown as TailTruncation, this is a very long string, that we are "
                                                     @"using for testing HeadTruncation"
                                       textAlignment:UITextAlignmentLeft
                                       lineBreakMode:UILineBreakModeHeadTruncation
                                       numberOfLines:2]];

    [_labels addObject:[self _createUILabelWithColor:[UIColor blackColor]
                                                text:@"MiddleTruncation but shown as TailTruncation, this is a very long string, that we "
                                                     @"are using for testing MiddleTruncation"
                                       textAlignment:UITextAlignmentLeft
                                       lineBreakMode:UILineBreakModeMiddleTruncation
                                       numberOfLines:3]];

    [self tableView].allowsSelection = NO;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_labels count];
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 60;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    } else {
        // Before reuse, check if any subview in contentview is tagged with TAG_SUBVIEW_UITEXTFIELD
        // if so, we know it is a custom view that we need to remove
        UIView* subView = (UIView*)[cell.contentView viewWithTag:TAG_SUBVIEW_UILABEL];
        [subView removeFromSuperview];
    }

    // Tag UITextField subview with TAG_SUBVIEW_TEXTFIELD before adding this subview into contentview
    UIView* subView = [_labels objectAtIndex:indexPath.row];
    subView.tag = TAG_SUBVIEW_UILABEL;
    [cell.contentView addSubview:subView];
    return cell;
}

@end
