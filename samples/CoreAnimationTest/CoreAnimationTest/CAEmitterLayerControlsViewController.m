//
//  CAEmitterLayerControlsViewController.m
//  CALayerSubclassTour
//
//  Created by Scott Gardner on 5/16/14.
//  Copyright (c) 2014 Optimac, Inc. All rights reserved.
//

#import "CAEmitterLayerControlsViewController.h"
#import "CAEmitterLayerViewController.h"

#import "Constants.h"

typedef enum : NSUInteger { SectionEmitterLayer, SectionEmitterCell } Section;

typedef enum : NSUInteger { PickerEmitterRenderMode } Picker;

typedef enum : NSUInteger {
    SliderEmitterCellColor,
    SliderEmitterCellRedRange,
    SliderEmitterCellGreenRange,
    SliderEmitterCellBlueRange,
    SliderEmitterCellAlphaRange,
    SliderEmitterCellRedSpeed,
    SliderEmitterCellGreenSpeed,
    SliderEmitterCellBlueSpeed,
    SliderEmitterCellAlphaSpeed,
    SliderEmitterCellScale,
    SliderEmitterCellScaleRange,
    SliderEmitterCellSpin,
    SliderEmitterCellSpinRange,
    SliderEmitterCellEmissionLatitude,
    SliderEmitterCellEmissionLongitude,
    SliderEmitterCellEmissionRange,
    SliderEmitterCellLifetime,
    SliderEmitterCellLifetimeRange,
    SliderEmitterCellBirthRate,
    SliderEmitterCellVelocity,
    SliderEmitterCellVelocityRange,
    SliderEmitterCellXAcceleration,
    SliderEmitterCellYAcceleration,
    SliderEnd
} Slider;

typedef enum : NSUInteger { SwitchEmitterCellEnabled } Switch;

@interface CAEmitterLayerControlsViewController () <UIPickerViewDataSource, UIPickerViewDelegate>
@property (strong, nonatomic) IBOutletCollection(UILabel) NSArray* pickerValueLabels;
@property (strong, nonatomic) IBOutletCollection(UIPickerView) NSArray* pickers;
@property (assign, nonatomic) BOOL emitterLayerRenderModePickerVisible;
@property (strong, nonatomic) IBOutletCollection(UILabel) NSArray* sliderValueLabels;
@property (strong, nonatomic) IBOutletCollection(UISlider) NSArray* sliders;
@property (weak, nonatomic) IBOutlet UISlider* emitterCellColorSlider;
@property (strong, nonatomic) IBOutletCollection(UISwitch) NSArray* switches;

@end

@implementation CAEmitterLayerControlsViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.emitterLayerRenderModes = @[
        kCAEmitterLayerUnordered,
        kCAEmitterLayerOldestFirst,
        kCAEmitterLayerOldestLast,
        kCAEmitterLayerBackToFront,
        kCAEmitterLayerAdditive
    ];
    [self updatePickerValueLabel:PickerEmitterRenderMode];
    [self updateAllSliderValueLabels];
    UISwitch* emitterCellEnabledSwitch = self.switches[SwitchEmitterCellEnabled];
    emitterCellEnabledSwitch.on = self.emitterCell.enabled;
}

- (void)updatePickerValueLabel:(Picker)index {
    UILabel* label = self.pickerValueLabels[index];

    switch (index) {
        case PickerEmitterRenderMode: {
            label.text = self.emitterLayer.renderMode;
        } break;
    }
}

- (void)updateAllSliderValueLabels {
    for (Slider i = SliderEmitterCellColor; i < SliderEnd; i++) {
        [self updateSliderValueLabel:i];
    }
}

- (void)updateSliderValueLabel:(Slider)index {
    UILabel* label = self.sliderValueLabels[index];
    UISlider* slider = self.sliders[index];

    switch (index) {
        case SliderEmitterCellRedRange:
        case SliderEmitterCellGreenRange:
        case SliderEmitterCellBlueRange:
        case SliderEmitterCellAlphaRange:
        case SliderEmitterCellRedSpeed:
        case SliderEmitterCellGreenSpeed:
        case SliderEmitterCellBlueSpeed:
        case SliderEmitterCellAlphaSpeed:
        case SliderEmitterCellScale:
        case SliderEmitterCellScaleRange:
        case SliderEmitterCellLifetime:
        case SliderEmitterCellLifetimeRange:
            label.text = [NSString stringWithFormat:@"%.1f", slider.value];
            break;

        case SliderEmitterCellColor:
            label.text = [NSString stringWithFormat:@"%.0f", slider.value * 100];
            break;

        case SliderEmitterCellSpin:
        case SliderEmitterCellSpinRange:
        case SliderEmitterCellEmissionLatitude:
        case SliderEmitterCellEmissionLongitude:
        case SliderEmitterCellEmissionRange:
            label.text = [NSString stringWithFormat:@"%.0f", RADIANS_TO_DEGREES(slider.value)];
            break;

        case SliderEmitterCellBirthRate:
        case SliderEmitterCellVelocity:
        case SliderEmitterCellVelocityRange:
        case SliderEmitterCellXAcceleration:
        case SliderEmitterCellYAcceleration:
            label.text = [NSString stringWithFormat:@"%.0f", slider.value];

        case SliderEnd:
            break;
    }
}

- (void)showEmitterLayerRenderModePicker {
    self.emitterLayerRenderModePickerVisible = YES;
    [self relayoutTableViewCells];
    UIPickerView* picker = self.pickers[PickerEmitterRenderMode];
    NSInteger index = [self.emitterLayerRenderModes indexOfObject:self.emitterLayer.renderMode];
    [picker selectRow:index inComponent:0 animated:NO];
    picker.hidden = NO;
    picker.alpha = Zero;

    [UIView animateWithDuration:0.25
                     animations:^{
                         picker.alpha = One;
                     }];

    [self.tableView scrollToNearestSelectedRowAtScrollPosition:UITableViewScrollPositionMiddle animated:YES];
}

- (void)hideEmitterLayerRenderModePicker {
    if (self.emitterLayerRenderModePickerVisible) {
        self.emitterLayerRenderModePickerVisible = NO;
        [self relayoutTableViewCells];
        UIPickerView* picker = self.pickers[PickerEmitterRenderMode];

        [UIView animateWithDuration:0.25
            animations:^{
                picker.alpha = Zero;
            }
            completion:^(BOOL finished) {
                picker.hidden = YES;
            }];
    }

    [self.tableView scrollToNearestSelectedRowAtScrollPosition:UITableViewScrollPositionTop animated:YES];
}

- (void)relayoutTableViewCells {
    [self.tableView beginUpdates];
    [self.tableView endUpdates];
}

#pragma mark - IBActions

- (IBAction)sliderChanged:(UISlider*)sender {
    Slider index = [self.sliders indexOfObject:sender];
    NSString* keyPath;

    switch (index) {
        case SliderEmitterCellColor:
            keyPath = @"emitterCell.color";
            break;
        case SliderEmitterCellRedRange:
            keyPath = @"emitterCell.redRange";
            break;
        case SliderEmitterCellGreenRange:
            keyPath = @"emitterCell.greenRange";
            break;
        case SliderEmitterCellBlueRange:
            keyPath = @"emitterCell.blueRange";
            break;
        case SliderEmitterCellAlphaRange:
            keyPath = @"emitterCell.alphaRange";
            break;
        case SliderEmitterCellRedSpeed:
            keyPath = @"emitterCell.redSpeed";
            break;
        case SliderEmitterCellGreenSpeed:
            keyPath = @"emitterCell.greenSpeed";
            break;
        case SliderEmitterCellBlueSpeed:
            keyPath = @"emitterCell.blueSpeed";
            break;
        case SliderEmitterCellAlphaSpeed:
            keyPath = @"emitterCell.alphaSpeed";
            break;
        case SliderEmitterCellScale:
            keyPath = @"emitterCell.scale";
            break;
        case SliderEmitterCellScaleRange:
            keyPath = @"emitterCell.scaleRange";
            break;
        case SliderEmitterCellSpin:
            keyPath = @"emitterCell.spin";
            break;
        case SliderEmitterCellSpinRange:
            keyPath = @"emitterCell.spinRange";
            break;
        case SliderEmitterCellEmissionLatitude:
            keyPath = @"emitterCell.emissionLatitude";
            break;
        case SliderEmitterCellEmissionLongitude:
            keyPath = @"emitterCell.emissionLongitude";
            break;
        case SliderEmitterCellEmissionRange:
            keyPath = @"emitterCell.emissionRange";
            break;
        case SliderEmitterCellLifetime:
            keyPath = @"emitterCell.lifetime";
            break;
        case SliderEmitterCellLifetimeRange:
            keyPath = @"emitterCell.lifetimeRange";
            break;
        case SliderEmitterCellBirthRate:
            keyPath = @"emitterCell.birthRate";
            break;
        case SliderEmitterCellVelocity:
            keyPath = @"emitterCell.velocity";
            break;
        case SliderEmitterCellVelocityRange:
            keyPath = @"emitterCell.velocityRange";
            break;
        case SliderEmitterCellXAcceleration:
            keyPath = @"emitterCell.xAcceleration";
            break;
        case SliderEmitterCellYAcceleration:
            keyPath = @"emitterCell.yAcceleration";
            break;
        case SliderEnd:
            break;
    }

    [self updateSliderValueLabel:index];
    self.sliderChangeHandler(sender, keyPath);
}

- (IBAction)emitterCellEnabledSwitchChanged:(UISwitch*)sender {
    self.switchChangeHandler(sender, @"emitterCell.enabled");
}

#pragma mark - UITableViewDelegate

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    Section section = indexPath.section;

    if (section == SectionEmitterLayer && indexPath.row == 1) {
        return self.emitterLayerRenderModePickerVisible ? 162.0f : Zero;
    } else {
        return 44.0f;
    }
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    Section section = indexPath.section;

    if (section == SectionEmitterLayer) {
        if (!self.emitterLayerRenderModePickerVisible) {
            [self showEmitterLayerRenderModePicker];
        } else {
            [self hideEmitterLayerRenderModePicker];
        }
    }
}

#pragma mark - UIPickerViewDataSource

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView*)pickerView {
    return 1;
}

- (NSInteger)pickerView:(UIPickerView*)pickerView numberOfRowsInComponent:(NSInteger)component {
    NSIndexPath* indexPath = [self.tableView indexPathForSelectedRow];
    Section section = indexPath.section;
    NSInteger numberOfRows = 0;

    switch (section) {
        case SectionEmitterLayer:
            switch (indexPath.row) {
                case 0:
                    numberOfRows = [self.emitterLayerRenderModes count];
                    break;

                default:
                    break;
            }
            break;

        case SectionEmitterCell:
            //
            break;
    }

    return numberOfRows;
}

#pragma mark - UIPickerViewDelegate

- (NSString*)pickerView:(UIPickerView*)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    NSIndexPath* indexPath = [self.tableView indexPathForSelectedRow];
    Section section = indexPath.section;
    NSString* title;

    switch (section) {
        case SectionEmitterLayer:
            switch (indexPath.row) {
                case 0:
                    title = self.emitterLayerRenderModes[row];
                    break;

                default:
                    break;
            }
            break;

        case SectionEmitterCell:
            //
            break;
    }

    return title;
}

- (void)pickerView:(UIPickerView*)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    NSIndexPath* indexPath = [self.tableView indexPathForSelectedRow];
    Section section = indexPath.section;

    switch (section) {
        case SectionEmitterLayer:
            switch (indexPath.row) {
                case PickerEmitterRenderMode:
                    self.pickerChangeHandler(pickerView, @"emitterLayer.renderMode");
                    [self updatePickerValueLabel:PickerEmitterRenderMode];
                    break;

                default:
                    break;
            }
            break;

        case SectionEmitterCell:
            //
            break;
    }
}

@end
