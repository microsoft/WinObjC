//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
    
    scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, bounds.size.width, bounds.size.height)];
    scrollView.backgroundColor = [UIColor whiteColor];
    scrollView.contentSize = CGSizeMake(450, 960);
    scrollView.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    
    buttonLength = 72;
    accHeight = 80;
    gyroHeight = 280;
    magnetoHeight = 480;

    motionManager = [[CMMotionManager alloc] init];
    
    if (motionManager.isAccelerometerAvailable) {
        accQueue = [[NSOperationQueue alloc] init];
        motionManager.accelerometerUpdateInterval = 0.016;
        [self setupAccelerometer];
    } else {
        accLabel = [[UILabel alloc] initWithFrame:CGRectMake(30, 80, 300, 50)];
        [accLabel setBackgroundColor:nil];
        [accLabel setText:@"Accelerometer Not Available!"];
        [accLabel setTextAlignment:NSTextAlignmentLeft];
        [scrollView addSubview:accLabel];
    }

    if (motionManager.isGyroAvailable) {
        gyroQueue = [[NSOperationQueue alloc] init];
        motionManager.gyroUpdateInterval = 0.016;
        [self setupGyrometer];
    } else {
        gyroLabel = [[UILabel alloc] initWithFrame:CGRectMake(30, 280, 300, 50)];
        [gyroLabel setBackgroundColor:nil];
        [gyroLabel setText:@"Gyrometer Not Available!"];
        [gyroLabel setTextAlignment:NSTextAlignmentLeft];
        [scrollView addSubview:gyroLabel];
    }
    
    if (motionManager.isMagnetometerAvailable) {
        magnetoQueue = [[NSOperationQueue alloc] init];
        motionManager.magnetometerUpdateInterval = 0.016;
        [self setupMagnetometer];
    } else {
        magnetoLabel = [[UILabel alloc] initWithFrame:CGRectMake(30, 480, 300, 50)];
        [magnetoLabel setBackgroundColor:nil];
        [magnetoLabel setText:@"Magnetometer Not Available!"];
        [magnetoLabel setTextAlignment:NSTextAlignmentLeft];
        [scrollView addSubview:magnetoLabel];
    }
    
    [self.view setBackgroundColor:[UIColor whiteColor]];
    [self.view addSubview:scrollView];
}


// Methods for Accelerometer
-(void)setupAccelerometer {
    accLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, accHeight - 5, 150, 50)];
    [accLabel setBackgroundColor:[UIColor whiteColor]];
    [accLabel setText:@"Accelerometer"];
    [accLabel setTextAlignment:NSTextAlignmentLeft];
    [scrollView addSubview:accLabel];

    accStartButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [accStartButton setTitle:@"Start" forState:UIControlStateNormal];
    accStartButton.frame = CGRectMake(100, accHeight + 50, buttonLength, 40);
    [accStartButton addTarget:self action:@selector(accStartButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:accStartButton];

    accStopButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [accStopButton setTitle:@"Stop" forState:UIControlStateNormal];
    accStopButton.frame = CGRectMake(180, accHeight + 50, buttonLength, 40);
    accStopButton.enabled = NO;
    [accStopButton addTarget:self action:@selector(accStopButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:accStopButton];

    NSArray* segmentTextContent = [NSArray arrayWithObjects:@"with Handler", @"without Handler", nil];
    accHandlerSegment = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
    accHandlerSegment.frame = CGRectMake(130, accHeight, buttonLength * 3 + 20, 40);
    [accHandlerSegment addTarget:self action:@selector(accStopButtonPressed:) forControlEvents:UIControlEventValueChanged];
    accHandlerSegment.selectedSegmentIndex = 0;
    [scrollView addSubview:accHandlerSegment];

    accUpdateButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [accUpdateButton setTitle:@"Poll Values" forState:UIControlStateNormal];
    accUpdateButton.frame = CGRectMake(270, accHeight + 50, buttonLength * 1.3f, 40);
    [accUpdateButton addTarget:self action:@selector(accUpdateButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    accUpdateButton.enabled = NO;
    [scrollView addSubview:accUpdateButton];

    accVal = [[UILabel alloc] initWithFrame:CGRectMake(0, accHeight + 100, 350, 40)];
    [accVal setBackgroundColor:[UIColor whiteColor]];
    [accVal setText:@"X: 0.000        Y: 0.000        Z: 0.000"];
    [accVal setTextAlignment:NSTextAlignmentRight];
    [scrollView addSubview:accVal];
}


-(void)accStopUpdates {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{ [motionManager stopAccelerometerUpdates]; }); 
}


-(void)accStartUpdatesWithHandler {
    [motionManager startAccelerometerUpdatesToQueue:accQueue withHandler:^(CMAccelerometerData* accelerometerData, NSError* error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [accVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f", 
                accelerometerData.acceleration.x, accelerometerData.acceleration.y, accelerometerData.acceleration.z]];
         });         
    }];
}


-(void)accStopButtonPressed:(UIButton*)button {

    if ([motionManager isAccelerometerActive]) {
        accStartButton.enabled = YES;
        accStopButton.enabled = NO;
        accUpdateButton.enabled = NO;
        [self accStopUpdates];
    }
}


-(void)accUpdateButtonPressed:(UIButton*)button {

    if ([motionManager isAccelerometerActive]) { 
        CMAccelerometerData* accelerometerData = motionManager.accelerometerData;
        dispatch_async(dispatch_get_main_queue(), ^{
            [accVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f",
                accelerometerData.acceleration.x, 
                accelerometerData.acceleration.y,
                accelerometerData.acceleration.z]];
        });
    }
}
            

-(void)accStartButtonPressed:(UIButton*)button {
    accStartButton.enabled = NO;
    accStopButton.enabled = YES;

    if (accHandlerSegment.selectedSegmentIndex == 0) {
        [self accStartUpdatesWithHandler];
    } else {
        accUpdateButton.enabled = YES;
        [motionManager startAccelerometerUpdates];
    }
}


// Methods for Gyrometer
-(void)setupGyrometer {
    gyroLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, gyroHeight - 5, 150, 50)];
    [gyroLabel setBackgroundColor:[UIColor whiteColor]];
    [gyroLabel setText:@"Gyrometer"];
    [gyroLabel setTextAlignment:NSTextAlignmentLeft];
    [scrollView addSubview:gyroLabel];

    gyroStartButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [gyroStartButton setTitle:@"Start" forState:UIControlStateNormal];
    gyroStartButton.frame = CGRectMake(100, gyroHeight + 50, buttonLength, 40);
    [gyroStartButton addTarget:self action:@selector(gyroStartButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:gyroStartButton];

    gyroStopButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [gyroStopButton setTitle:@"Stop" forState:UIControlStateNormal];
    gyroStopButton.frame = CGRectMake(180, gyroHeight + 50, buttonLength, 40);
    gyroStopButton.enabled = NO;
    [gyroStopButton addTarget:self action:@selector(gyroStopButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:gyroStopButton];

    NSArray* segmentTextContent = [NSArray arrayWithObjects:@"with Handler", @"without Handler", nil];
    gyroHandlerSegment = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
    gyroHandlerSegment.frame = CGRectMake(130, gyroHeight, buttonLength * 3 + 20, 40);
    [gyroHandlerSegment addTarget:self action:@selector(gyroStopButtonPressed:) forControlEvents:UIControlEventValueChanged];
    gyroHandlerSegment.selectedSegmentIndex = 0;
    [scrollView addSubview:gyroHandlerSegment];

    gyroUpdateButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [gyroUpdateButton setTitle:@"Poll Values" forState:UIControlStateNormal];
    gyroUpdateButton.frame = CGRectMake(270, gyroHeight + 50, buttonLength * 1.3f, 40);
    [gyroUpdateButton addTarget:self action:@selector(gyroUpdateButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    gyroUpdateButton.enabled = NO;
    [scrollView addSubview:gyroUpdateButton];

    gyroVal = [[UILabel alloc] initWithFrame:CGRectMake(0, gyroHeight + 100, 350, 40)];
    [gyroVal setBackgroundColor:[UIColor whiteColor]];
    [gyroVal setText:@"X: 0.000        Y: 0.000        Z: 0.000"];
    [gyroVal setTextAlignment:NSTextAlignmentRight];
    [scrollView addSubview:gyroVal];
}


-(void)gyroStopUpdates {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{ [motionManager stopGyroUpdates]; });
}


-(void)gyroStartUpdatesWithHandler {
    [motionManager startGyroUpdatesToQueue:gyroQueue withHandler:^(CMGyroData* gyroData, NSError* error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [gyroVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f", 
                gyroData.rotationRate.x, gyroData.rotationRate.y, gyroData.rotationRate.z]];
         });         
    }];
}


-(void)gyroStopButtonPressed:(UIButton*)button {

    if ([motionManager isGyroActive]) {
        gyroStartButton.enabled = YES;
        gyroStopButton.enabled = NO;
        gyroUpdateButton.enabled = NO;
        [self gyroStopUpdates];
    }
}


-(void)gyroUpdateButtonPressed:(UIButton*)button {

    if ([motionManager isGyroActive]) {
        CMGyroData* gyroData = motionManager.gyroData; 
        dispatch_async(dispatch_get_main_queue(), ^{
            [gyroVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f",
                gyroData.rotationRate.x, 
                gyroData.rotationRate.y,
                gyroData.rotationRate.z]];
        });
    }
}
            

-(void)gyroStartButtonPressed:(UIButton*)button {
    gyroStartButton.enabled = NO;
    gyroStopButton.enabled = YES;

    if (gyroHandlerSegment.selectedSegmentIndex == 0) {
        [self gyroStartUpdatesWithHandler];
    } else {
        gyroUpdateButton.enabled = YES;
        [motionManager startGyroUpdates];
    }
}


// Methods for Magnetometer
-(void)setupMagnetometer {
    magnetoLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, magnetoHeight - 5, 150, 50)];
    [magnetoLabel setBackgroundColor:[UIColor whiteColor]];
    [magnetoLabel setText:@"Magnetometer"];
    [magnetoLabel setTextAlignment:NSTextAlignmentLeft];
    [scrollView addSubview:magnetoLabel];

    magnetoStartButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [magnetoStartButton setTitle:@"Start" forState:UIControlStateNormal];
    magnetoStartButton.frame = CGRectMake(100, magnetoHeight + 50, buttonLength, 40);
    [magnetoStartButton addTarget:self action:@selector(magnetoStartButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:magnetoStartButton];

    magnetoStopButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [magnetoStopButton setTitle:@"Stop" forState:UIControlStateNormal];
    magnetoStopButton.frame = CGRectMake(180, magnetoHeight + 50, buttonLength, 40);
    magnetoStopButton.enabled = NO;
    [magnetoStopButton addTarget:self action:@selector(magnetoStopButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:magnetoStopButton];

    NSArray* segmentTextContent = [NSArray arrayWithObjects:@"with Handler", @"without Handler", nil];
    magnetoHandlerSegment = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
    magnetoHandlerSegment.frame = CGRectMake(130, magnetoHeight, buttonLength * 3 + 20, 40);
    [magnetoHandlerSegment addTarget:self action:@selector(magnetoStopButtonPressed:) forControlEvents:UIControlEventValueChanged];
    magnetoHandlerSegment.selectedSegmentIndex = 0;
    [scrollView addSubview:magnetoHandlerSegment];

    magnetoUpdateButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [magnetoUpdateButton setTitle:@"Poll Values" forState:UIControlStateNormal];
    magnetoUpdateButton.frame = CGRectMake(270, magnetoHeight + 50, buttonLength * 1.3f, 40);
    [magnetoUpdateButton addTarget:self action:@selector(magnetoUpdateButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    magnetoUpdateButton.enabled = NO;
    [scrollView addSubview:magnetoUpdateButton];

    magnetoVal = [[UILabel alloc] initWithFrame:CGRectMake(0, magnetoHeight + 100, 350, 40)];
    [magnetoVal setBackgroundColor:[UIColor whiteColor]];
    [magnetoVal setText:@"X: 0.000        Y: 0.000        Z: 0.000"];
    [magnetoVal setTextAlignment:NSTextAlignmentRight];
    [scrollView addSubview:magnetoVal];
}


-(void)magnetoStopUpdates {
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_BACKGROUND, 0), ^{ [motionManager stopMagnetometerUpdates]; });
}


-(void)magnetoStartUpdatesWithHandler {
    [motionManager startMagnetometerUpdatesToQueue:magnetoQueue withHandler:^(CMMagnetometerData* magnetometerData, NSError* error) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [magnetoVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f", 
                magnetometerData.magneticField.x, magnetometerData.magneticField.y, magnetometerData.magneticField.z]];
         });         
    }];
}


-(void)magnetoStopButtonPressed:(UIButton*)button {

    if ([motionManager isMagnetometerActive]) {
        magnetoStartButton.enabled = YES;
        magnetoStopButton.enabled = NO;
        magnetoUpdateButton.enabled = NO;
        [self magnetoStopUpdates];
    }
}

    
-(void)magnetoUpdateButtonPressed:(UIButton*)button {

    if ([motionManager isMagnetometerActive]) {
        CMMagnetometerData* magnetometerData = motionManager.magnetometerData;
        dispatch_async(dispatch_get_main_queue(), ^{
            [magnetoVal setText:[NSString stringWithFormat:@"X: %.3f        Y: %.3f        Z: %.3f",
                magnetometerData.magneticField.x, 
                magnetometerData.magneticField.y,
                magnetometerData.magneticField.z]];
        });
    }
}
            

-(void)magnetoStartButtonPressed:(UIButton*)button {
    magnetoStartButton.enabled = NO;
    magnetoStopButton.enabled = YES;

    if (magnetoHandlerSegment.selectedSegmentIndex == 0) {
        [self magnetoStartUpdatesWithHandler];
    } else {
        magnetoUpdateButton.enabled = YES;
        [motionManager startMagnetometerUpdates];
    }
}

@end
