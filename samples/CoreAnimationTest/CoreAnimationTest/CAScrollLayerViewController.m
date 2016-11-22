//
//  CAScrollLayerViewController.m
//  CALayerSubclassTour
//
//  Created by Scott Gardner on 4/21/14.
//  Copyright (c) 2014 Optimac, Inc. All rights reserved.
//

#import "CAScrollLayerViewController.h"
#import "ScrollingView.h"

@interface CAScrollLayerViewController ()
@property (weak, nonatomic) IBOutlet ScrollingView* scrollingView;
@property (weak, nonatomic) IBOutlet UISwitch* horizontalScrollingSwitch;
@property (weak, nonatomic) IBOutlet UISwitch* verticalScrollingSwitch;
@end

@implementation CAScrollLayerViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [(CAScrollLayer*)self.scrollingView.layer setScrollMode:kCAScrollBoth];

    UIPanGestureRecognizer* panRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(pan:)];
    [self.scrollingView addGestureRecognizer:panRecognizer];
}

- (void)pan:(UIPanGestureRecognizer*)panRecognizer {
    CGPoint newPoint = self.scrollingView.bounds.origin;
    newPoint.x -= [panRecognizer translationInView:self.scrollingView].x;
    newPoint.y -= [panRecognizer translationInView:self.scrollingView].y;
    [panRecognizer setTranslation:CGPointZero inView:self.scrollingView];
    [(CAScrollLayer*)self.scrollingView.layer scrollToPoint:newPoint];

    if (panRecognizer.state == UIGestureRecognizerStateEnded) {
        [UIView animateWithDuration:0.3f
                              delay:0
                            options:UIViewAnimationOptionCurveEaseInOut
                         animations:^{
                             [(CAScrollLayer*)self.scrollingView.layer scrollToPoint:CGPointZero];
                         }
                         completion:nil];
    }
}

- (IBAction)scrollingSwitchChanged:(id)sender {
    if (self.horizontalScrollingSwitch.on) {
        if (self.verticalScrollingSwitch.on) {
            [(CAScrollLayer*)self.scrollingView.layer setScrollMode:kCAScrollBoth];
        } else {
            [(CAScrollLayer*)self.scrollingView.layer setScrollMode:kCAScrollHorizontally];
        }
    } else if (self.verticalScrollingSwitch.on) {
        [(CAScrollLayer*)self.scrollingView.layer setScrollMode:kCAScrollVertically];
    } else {
        [(CAScrollLayer*)self.scrollingView.layer setScrollMode:kCAScrollNone];
    }
}

@end
