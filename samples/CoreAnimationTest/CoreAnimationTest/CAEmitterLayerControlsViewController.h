//
//  CAEmitterLayerControlsViewController.h
//  CALayerSubclassTour
//
//  Created by Scott Gardner on 5/16/14.
//  Copyright (c) 2014 Optimac, Inc. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^PickerActionBlock)(UIPickerView* picker, NSString* keyPath);
typedef void (^SliderActionBlock)(UISlider* slider, NSString* keyPath);
typedef void (^SwitchActionBlock)(UISwitch* theSwitch, NSString* keyPath);

@interface CAEmitterLayerControlsViewController : UITableViewController

@property (strong, nonatomic) CAEmitterLayer* emitterLayer;
@property (strong, nonatomic) CAEmitterCell* emitterCell;

@property (copy, nonatomic) PickerActionBlock pickerChangeHandler;
@property (copy, nonatomic) SliderActionBlock sliderChangeHandler;
@property (copy, nonatomic) SwitchActionBlock switchChangeHandler;

@property (copy, nonatomic) NSArray* emitterLayerRenderModes;

@end
