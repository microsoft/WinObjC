//
//  CAEmitterLayerViewController.m
//  CALayerSubclassTour
//
//  Created by Scott Gardner on 4/21/14.
//  Copyright (c) 2014 Optimac, Inc. All rights reserved.
//

#import "CAEmitterLayerViewController.h"
#import "CAEmitterLayerControlsViewController.h"

#import "Constants.h"

@interface CAEmitterLayerViewController ()
@property (weak, nonatomic) IBOutlet UIView* viewForEmitterLayer;
@property (strong, nonatomic) CAEmitterLayer* emitterLayer;
@property (strong, nonatomic) CAEmitterCell* emitterCell;
@end

@implementation CAEmitterLayerViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.emitterLayer.emitterCells = @[ self.emitterCell ];
    [self.viewForEmitterLayer.layer addSublayer:self.emitterLayer];
}

- (void)prepareForSegue:(UIStoryboardSegue*)segue sender:(id)sender {
    if ([segue.identifier isEqualToString:@"DisplayEmitterControls"]) {
        CAEmitterLayerControlsViewController* controller = (CAEmitterLayerControlsViewController*)segue.destinationViewController;
        controller.emitterLayer = self.emitterLayer;
        controller.emitterCell = self.emitterCell;
        [self setEmitterLayerControllerControlsActions:controller];
    }
}

- (CAEmitterLayer*)emitterLayer {
    if (!_emitterLayer) {
        _emitterLayer = [CAEmitterLayer layer];
        _emitterLayer.frame = self.viewForEmitterLayer.bounds;
        _emitterLayer.seed = time(0);

        _emitterLayer.renderMode = kCAEmitterLayerAdditive;
        _emitterLayer.emitterPosition = (CGPoint){ CGRectGetWidth(_emitterLayer.frame) / Two, CGRectGetHeight(_emitterLayer.frame) / Two };
    }

    return _emitterLayer;
}

- (CAEmitterCell*)emitterCell {
    if (!_emitterCell) {
        _emitterCell = [CAEmitterCell emitterCell];
        _emitterCell.enabled = YES;
        _emitterCell.contents = (__bridge id)[UIImage imageNamed:@"star.png"].CGImage;
        _emitterCell.contentsRect = (CGRect){ CGPointZero, One, One };

        _emitterCell.color = [UIColor colorWithHue:Zero saturation:Zero brightness:Zero alpha:One].CGColor;
        _emitterCell.redRange = One;
        _emitterCell.greenRange = One;
        _emitterCell.blueRange = One;
        _emitterCell.alphaRange = Zero;
        _emitterCell.redSpeed = Zero;
        _emitterCell.greenSpeed = Zero;
        _emitterCell.blueSpeed = Zero;
        _emitterCell.alphaSpeed = -Half;
        _emitterCell.scale = One;
        _emitterCell.scaleRange = Zero;
        _emitterCell.scaleSpeed = 0.1f;
        _emitterCell.spin = DEGREES_TO_RADIANS(Zero);
        _emitterCell.spinRange = DEGREES_TO_RADIANS(Zero);
        _emitterCell.emissionLatitude = DEGREES_TO_RADIANS(Zero);
        _emitterCell.emissionLongitude = DEGREES_TO_RADIANS(Zero);
        _emitterCell.emissionRange = DEGREES_TO_RADIANS(360.0f);
        _emitterCell.lifetime = One;
        _emitterCell.lifetimeRange = Zero;
        _emitterCell.birthRate = 250.0f;
        _emitterCell.velocity = 50.0f;
        _emitterCell.velocityRange = 500.0f;
        _emitterCell.xAcceleration = Zero;
        _emitterCell.yAcceleration = Zero;
    }

    return _emitterCell;
}

- (void)setEmitterLayerControllerControlsActions:(CAEmitterLayerControlsViewController*)controller {
    __weak typeof(controller) weakController = controller;
    __weak typeof(self) weakSelf = self;

    controller.pickerChangeHandler = ^(UIPickerView* picker, NSString* keyPath) {
        __strong typeof(weakSelf) strongSelf = weakSelf;
        __strong typeof(controller) strongController = weakController;
        NSInteger index = [picker selectedRowInComponent:0];
        [strongSelf setValue:strongController.emitterLayerRenderModes[index] forKeyPath:keyPath];
    };

    controller.sliderChangeHandler = ^(UISlider* slider, NSString* keyPath) {
        __strong typeof(weakSelf) strongSelf = weakSelf;

        if ([keyPath isEqualToString:@"emitterCell.color"]) {
            UIColor* color = [UIColor colorWithHue:Zero saturation:Zero brightness:slider.value alpha:One];
            [strongSelf setValue:(__bridge id)color.CGColor forKeyPath:keyPath];
            strongSelf.emitterLayer.emitterCells = nil;
            strongSelf.emitterLayer.emitterCells = @[ strongSelf.emitterCell ];
        } else {
            [strongSelf setValue:@(slider.value) forKeyPath:keyPath];

            if ([keyPath hasSuffix:@"Range"] || [keyPath hasSuffix:@"Speed"] || [keyPath hasSuffix:@"tude"] ||
                [keyPath isEqualToString:@"emitterCell.scale"] || [keyPath isEqualToString:@"emitterCell.spin"] ||
                [keyPath rangeOfString:@"lifetime"].location || [keyPath hasSuffix:@"Rate"] ||
                [keyPath rangeOfString:@"velocity"].location || [keyPath hasSuffix:@"Acceleration"]) {
                strongSelf.emitterLayer.emitterCells = nil;
                strongSelf.emitterLayer.emitterCells = @[ strongSelf.emitterCell ];
            }
        }
    };

    controller.switchChangeHandler = ^(UISwitch* theSwitch, NSString* keyPath) {
        __strong typeof(weakSelf) strongSelf = weakSelf;
        [strongSelf setValue:@(theSwitch.on) forKeyPath:keyPath];

        if ([keyPath isEqualToString:@"emitterCell.enabled"]) {
            strongSelf.emitterLayer.emitterCells = nil;
            strongSelf.emitterLayer.emitterCells = @[ strongSelf.emitterCell ];
        }
    };
}

- (void)touchesBegan:(NSSet*)touches withEvent:(UIEvent*)event {
    self.emitterLayer.position = [[touches anyObject] locationInView:self.viewForEmitterLayer];
}

- (void)touchesMoved:(NSSet*)touches withEvent:(UIEvent*)event {
    self.emitterLayer.position = [[touches anyObject] locationInView:self.viewForEmitterLayer];
}

@end
