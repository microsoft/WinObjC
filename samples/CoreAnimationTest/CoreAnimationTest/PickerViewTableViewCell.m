//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "PickerViewTableViewCell.h"
#import "CALayerMultipleViewController.h"

@interface PickerViewTableViewCell ()

@property UIPickerView* pickerView;

@end

@implementation PickerViewTableViewCell {
    NSArray* _options;
}

- (instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString*)reuseIdentifier {
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.pickerView = [UIPickerView new];
        self.pickerView.dataSource = self;
        self.pickerView.delegate = self;
        self.pickerView.translatesAutoresizingMaskIntoConstraints = NO;
        [self addSubview:self.pickerView];

        NSDictionary* views = @{ @"titleLabel" : self.titleLabel, @"pickerView" : self.pickerView };
        NSDictionary* metrics = @{ @"pad" : @(kPadding) };
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-pad-[titleLabel]-(>=pad)-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"H:|-(>=pad)-[pickerView]-pad-|"
                                                                     options:0
                                                                     metrics:metrics
                                                                       views:views]];
        [self.pickerView.widthAnchor constraintLessThanOrEqualToAnchor:self.widthAnchor multiplier:0.5].active = YES;
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[titleLabel]|" options:0 metrics:metrics views:views]];
        [self addConstraints:[NSLayoutConstraint constraintsWithVisualFormat:@"V:|[pickerView]|" options:0 metrics:metrics views:views]];
    }

    return self;
}

- (void)setUpWithName:(NSString*)name
              options:(NSArray*)options
         currentIndex:(NSInteger)idx
             delegate:(id<PickerViewTableViewCellDelegate>)delegate {
    self.titleLabel.text = name;
    _options = options;
    [self.pickerView selectRow:idx inComponent:0 animated:NO];
    self.delegate = delegate;
    [self.pickerView reloadAllComponents];
}

- (void)setDisabled:(BOOL)disabled {
    [super setDisabled:disabled];
    self.pickerView.userInteractionEnabled = !disabled;
}

- (void)prepareForReuse {
    [super prepareForReuse];
    [self.pickerView reloadAllComponents];
}

#pragma mark Picker view data source

- (NSInteger)pickerView:(UIPickerView*)pickerView numberOfRowsInComponent:(NSInteger)component {
    return _options.count;
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView*)pickerView {
    return 1;
}

#pragma mark Picker view delegate

- (NSString*)pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    return _options[row];
}

- (UIView*)pickerView:(UIPickerView*)pickerView viewForRow:(NSInteger)row forComponent:(NSInteger)component reusingView:(UIView*)view {
    UILabel* label = (UILabel*)view;

    if (!label) {
        label = [UILabel new];
        label.font = [UIFont systemFontOfSize:[UIFont smallSystemFontSize]];
        label.textColor = [UIColor darkGrayColor];
        label.textAlignment = NSTextAlignmentRight;
    }

    label.text = _options[row];

    return label;
}

- (CGFloat)pickerView:(UIPickerView*)pickerView rowHeightForComponent:(NSInteger)component {
    return kPropertyCellHeight;
}

- (void)pickerView:(UIPickerView*)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    if ([self.delegate respondsToSelector:@selector(pickerViewWithName:didChangeToIndex:)]) {
        [self.delegate pickerViewWithName:self.titleLabel.text didChangeToIndex:row];
    }
}

@end
