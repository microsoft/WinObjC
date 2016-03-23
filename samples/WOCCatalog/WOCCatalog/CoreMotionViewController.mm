//******************************************************************************
//
// Copyright (c) 2016, Intel Corporation
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

#import "CoreMotionViewController.h"

@implementation CoreMotionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
 
    CGRect bounds = [[UIScreen mainScreen] bounds];

    int accHeight = 80;
    int accStartX = -20;
    int buttonLength = 72;   

    accLabel = [[UILabel alloc] initWithFrame:bounds];
    [self.view setBackgroundColor:[UIColor whiteColor]];
    [accLabel setText:@"Accelerometer"];
    [accLabel setTextAlignment:NSTextAlignmentLeft];
    accLabel.frame = CGRectMake(accStartX + 30, accHeight - 5, 150, 50);
    [self.view addSubview:accLabel];

    accStartButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [accStartButton setTitle:@"Start" forState:UIControlStateNormal];
    accStartButton.frame = CGRectMake(accStartX + 120, accHeight + 50, buttonLength, 40);
    [accStartButton addTarget:self action:@selector(startButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:accStartButton];

    accStopButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [accStopButton setTitle:@"Stop" forState:UIControlStateNormal];
    accStopButton.frame = CGRectMake(accStartX + 200, accHeight + 50, buttonLength, 40);
    accStopButton.enabled = NO;
    [accStopButton addTarget:self action:@selector(stopButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:accStopButton];

    NSArray* segmentTextContent = [NSArray arrayWithObjects:@"with Handler", @"without Handler", nil];
    accHandlerSegment = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
    accHandlerSegment.frame = CGRectMake(accStartX + 150, accHeight, buttonLength * 3 + 20, 40);
    [accHandlerSegment addTarget:self action:@selector(handlerChanged:) forControlEvents:UIControlEventValueChanged];
    accHandlerSegment.selectedSegmentIndex = 0;
    [self.view addSubview:accHandlerSegment];

    accUpdateButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [accUpdateButton setTitle:@"Poll Values" forState:UIControlStateNormal];
    accUpdateButton.frame = CGRectMake(accStartX + 290, accHeight + 50, buttonLength * 1.3f, 40);
    [accUpdateButton addTarget:self action:@selector(updateButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    accUpdateButton.enabled = NO;
    [self.view addSubview:accUpdateButton];

    accVal = [[UILabel alloc] initWithFrame:bounds];
    [self.view setBackgroundColor:[UIColor whiteColor]];
    [accVal setText:@"X: 0.000        Y: 0.000        Z: 0.000"];
    [accVal setTextAlignment:NSTextAlignmentRight];
    accVal.frame = CGRectMake(accStartX + 20, accHeight + 100, 350, 40);
    [self.view addSubview:accVal];

    progressInd = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    progressInd.frame = CGRectMake(accStartX + 220, accHeight + 150, 50, 50);
    [progressInd sizeToFit];
    [self.view addSubview:progressInd];
    
    [self.view setBackgroundColor:[UIColor whiteColor]];
  
    accQueue = [[NSOperationQueue alloc] init];

    motionManager = [[CMMotionManager alloc] init];
    motionManager.accelerometerUpdateInterval = 0.016;
}


-(void)stopUpdates {
    [progressInd startAnimating];

    dispatch_queue_t backgroundQueue = dispatch_queue_create("stop", NULL);

    dispatch_async(backgroundQueue, ^{
        [motionManager stopAccelerometerUpdates];

        dispatch_async(dispatch_get_main_queue(), ^{
            [progressInd stopAnimating];
        }); 
    });
}


-(void)startUpdatesWithHandler {
    [motionManager startAccelerometerUpdatesToQueue:accQueue withHandler:^(CMAccelerometerData* accelerometerData, NSError* error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [accVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f", 
                accelerometerData.acceleration.x, accelerometerData.acceleration.y, accelerometerData.acceleration.z]];
         });         
    }];
}


-(void)handlerChanged:(UISegmentedControl*)segment {

    if ([motionManager isAccelerometerActive]) {
        accStartButton.enabled = YES;
        accStopButton.enabled = NO;
        accUpdateButton.enabled = NO;
        [self stopUpdates];
    }
}


-(void)stopButtonPressed:(UIButton*)button {

    if ([motionManager isAccelerometerActive]) {
        accStartButton.enabled = YES;
        accStopButton.enabled = NO;
        accUpdateButton.enabled = NO;
        [self stopUpdates];
    }
}


-(void)updateButtonPressed:(UIButton*)button {

    if ([motionManager isAccelerometerActive]) { 
        dispatch_async(dispatch_get_main_queue(), ^{
            [accVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f",
                motionManager.accelerometerData.acceleration.x, 
                motionManager.accelerometerData.acceleration.y,
                motionManager.accelerometerData.acceleration.z]];
        });
    }
}
            

-(void)startButtonPressed:(UIButton*)button {
    accStartButton.enabled = NO;
    accStopButton.enabled = YES;

    if (accHandlerSegment.selectedSegmentIndex == 0) {
        [self startUpdatesWithHandler];
    } else {
        accUpdateButton.enabled = YES;
        [motionManager startAccelerometerUpdates];
    }
}


@end
