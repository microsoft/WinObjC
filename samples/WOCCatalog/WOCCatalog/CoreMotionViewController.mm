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
    scrollView.contentSize = CGSizeMake(450, 1200);
    scrollView.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
    
    buttonLength = 72;
    accHeight = 80;
    gyroHeight = 280;
    magnetoHeight = 480;
    deviceHeight = 680;
    
    motionManager = [[CMMotionManager alloc] init];
    
    if (motionManager.isAccelerometerAvailable) {
        accQueue = [[NSOperationQueue alloc] init];
        motionManager.accelerometerUpdateInterval = 0.016;
        [self setupAccelerometer];
    } else {
        accLabel = [[UILabel alloc] initWithFrame:CGRectMake(30, accHeight, 300, 50)];
        [accLabel setBackgroundColor:[UIColor whiteColor]];
        [accLabel setText:@"Accelerometer Not Available!"];
        [accLabel setTextAlignment:NSTextAlignmentLeft];
        [scrollView addSubview:accLabel];
    }

    if (motionManager.isGyroAvailable) {
        gyroQueue = [[NSOperationQueue alloc] init];
        motionManager.gyroUpdateInterval = 0.016;
        [self setupGyrometer];
    } else {
        gyroLabel = [[UILabel alloc] initWithFrame:CGRectMake(30, gyroHeight, 300, 50)];
        [gyroLabel setBackgroundColor:[UIColor whiteColor]];
        [gyroLabel setText:@"Gyrometer Not Available!"];
        [gyroLabel setTextAlignment:NSTextAlignmentLeft];
        [scrollView addSubview:gyroLabel];
    }
    
    if (motionManager.isMagnetometerAvailable) {
        magnetoQueue = [[NSOperationQueue alloc] init];
        motionManager.magnetometerUpdateInterval = 0.016;
        [self setupMagnetometer];
    } else {
        magnetoLabel = [[UILabel alloc] initWithFrame:CGRectMake(30, magnetoHeight, 300, 50)];
        [magnetoLabel setBackgroundColor:[UIColor whiteColor]];
        [magnetoLabel setText:@"Magnetometer Not Available!"];
        [magnetoLabel setTextAlignment:NSTextAlignmentLeft];
        [scrollView addSubview:magnetoLabel];
    }
    
    if (motionManager.isDeviceMotionAvailable) {
        deviceQueue = [[NSOperationQueue alloc] init];
        motionManager.deviceMotionUpdateInterval = 0.016;
        [self setupDeviceMotion];
    } else {
        deviceLabel = [[UILabel alloc] initWithFrame:CGRectMake(30, deviceHeight, 300, 50)];
        [deviceLabel setBackgroundColor:[UIColor whiteColor]];
        [deviceLabel setText:@"DeviceMotion Not Available!"];
        [deviceLabel setTextAlignment:NSTextAlignmentLeft];
        [scrollView addSubview:deviceLabel];
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


// Methods for DeviceMotion
-(void)setupDeviceMotion {
    deviceLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, deviceHeight - 5, 150, 50)];
    [deviceLabel setBackgroundColor:[UIColor whiteColor]];
    [deviceLabel setText:@"DeviceMotion"];
    [deviceLabel setTextAlignment:NSTextAlignmentLeft];
    [scrollView addSubview:deviceLabel];

    deviceStartButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [deviceStartButton setTitle:@"Start" forState:UIControlStateNormal];
    deviceStartButton.frame = CGRectMake(100, deviceHeight + 50, buttonLength, 40);
    [deviceStartButton addTarget:self action:@selector(deviceStartButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:deviceStartButton];

    deviceStopButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [deviceStopButton setTitle:@"Stop" forState:UIControlStateNormal];
    deviceStopButton.frame = CGRectMake(180, deviceHeight + 50, buttonLength, 40);
    deviceStopButton.enabled = NO;
    [deviceStopButton addTarget:self action:@selector(deviceStopButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:deviceStopButton];

    NSArray* segmentTextContent = [NSArray arrayWithObjects:@"with Handler", @"without Handler", nil];
    deviceHandlerSegment = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
    deviceHandlerSegment.frame = CGRectMake(130, deviceHeight, buttonLength * 3 + 20, 40);
    [deviceHandlerSegment addTarget:self action:@selector(deviceStopButtonPressed:) forControlEvents:UIControlEventValueChanged];
    deviceHandlerSegment.selectedSegmentIndex = 0;
    [scrollView addSubview:deviceHandlerSegment];

    deviceUpdateButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [deviceUpdateButton setTitle:@"Poll Values" forState:UIControlStateNormal];
    deviceUpdateButton.frame = CGRectMake(270, deviceHeight + 50, buttonLength * 1.3f, 40);
    [deviceUpdateButton addTarget:self action:@selector(deviceUpdateButtonPressed:) forControlEvents:UIControlEventTouchUpInside];
    deviceUpdateButton.enabled = NO;
    [scrollView addSubview:deviceUpdateButton];

    deviceVal = [[UILabel alloc] initWithFrame:CGRectMake(10, deviceHeight + 100, 350, 40)];
    [deviceVal setBackgroundColor:[UIColor whiteColor]];
    [deviceVal setText:@"roll: 0.000        pitch: 0.000        yaw: 0.000"];
    [deviceVal setTextAlignment:NSTextAlignmentRight];
    [scrollView addSubview:deviceVal];

    deviceQVal = [[UILabel alloc] initWithFrame:CGRectMake(30, deviceHeight + 150, 350, 80)];
    [deviceQVal setBackgroundColor:[UIColor whiteColor]];
    [deviceQVal setText:@"Quaternion:\n  W: 0.00      X: 0.00      Y: 0.00      Z: 0.00"];
    [deviceQVal setTextAlignment:NSTextAlignmentLeft];
    deviceQVal.numberOfLines = 0;
    [scrollView addSubview:deviceQVal];

    deviceRMVal = [[UILabel alloc] initWithFrame:CGRectMake(30, deviceHeight + 250, 350, 100)];
    [deviceRMVal setBackgroundColor:[UIColor whiteColor]];
    [deviceRMVal setText:@"Rotation Matrix:\n       0.000     0.000     0.000\
                                           \n       0.000     0.000     0.000\
                                           \n       0.000     0.000     0.000"];
    [deviceRMVal setTextAlignment:NSTextAlignmentLeft];
    deviceRMVal.numberOfLines = 0;
    [scrollView addSubview:deviceRMVal];
}


-(void)deviceStopUpdates {
    dispatch_queue_t backgroundQueue = dispatch_queue_create("stop", NULL);
    dispatch_async(backgroundQueue, ^{ [motionManager stopDeviceMotionUpdates]; }); 
}


-(void)deviceStartUpdatesWithHandler {
    [motionManager startDeviceMotionUpdatesToQueue:deviceQueue withHandler:^(CMDeviceMotion *motion, NSError* error) {
        dispatch_async(dispatch_get_main_queue(), ^{

            [deviceVal setText:[NSString stringWithFormat:@"roll: %.3f        pitch: %.3f        yaw: %.3f", 
                motion.attitude.roll, motion.attitude.pitch, motion.attitude.yaw]];

            [deviceQVal setText:[NSString stringWithFormat:@"Quaternion:\n  W: % 3.2f      X: % 3.2f      Y: % 3.2f      Z: % 3.2f",
                motion.attitude.quaternion.w, motion.attitude.quaternion.x, motion.attitude.quaternion.y, motion.attitude.quaternion.z]];

            [deviceRMVal setText:[NSString stringWithFormat:@"Rotation Matrix:\n    % 8.3f  % 8.3f  % 8.3f\
                                                                              \n    % 8.3f  % 8.3f  % 8.3f\
                                                                              \n    % 8.3f  % 8.3f  % 8.3f",
                motion.attitude.rotationMatrix.m11, motion.attitude.rotationMatrix.m12, motion.attitude.rotationMatrix.m13,
                motion.attitude.rotationMatrix.m21, motion.attitude.rotationMatrix.m22, motion.attitude.rotationMatrix.m23,
                motion.attitude.rotationMatrix.m31, motion.attitude.rotationMatrix.m32, motion.attitude.rotationMatrix.m33]];
         });         
    }];
}


-(void)deviceStopButtonPressed:(UIButton*)button {

    if ([motionManager isDeviceMotionActive]) {
        deviceStartButton.enabled = YES;
        deviceStopButton.enabled = NO;
        deviceUpdateButton.enabled = NO;
        [self deviceStopUpdates];
    }
}


-(void)deviceUpdateButtonPressed:(UIButton*)button {

    if ([motionManager isDeviceMotionActive]) { 
        dispatch_async(dispatch_get_main_queue(), ^{

            [deviceVal setText:[NSString stringWithFormat:@"roll: %.3f        pitch: %.3f        yaw: %.3f",
                motionManager.deviceMotion.attitude.roll, 
                motionManager.deviceMotion.attitude.pitch,
                motionManager.deviceMotion.attitude.yaw]];

            [deviceQVal setText:[NSString stringWithFormat:@"Quaternion:\n  W: % 3.2f      X: % 3.2f      Y: % 3.2f      Z: % 3.2f",
                motionManager.deviceMotion.attitude.quaternion.w, 
                motionManager.deviceMotion.attitude.quaternion.x, 
                motionManager.deviceMotion.attitude.quaternion.y, 
                motionManager.deviceMotion.attitude.quaternion.z]];

            [deviceRMVal setText:[NSString stringWithFormat:@"Rotation Matrix:\n    % 8.3f  % 8.3f  % 8.3f\
                                                                              \n    % 8.3f  % 8.3f  % 8.3f\
                                                                              \n    % 8.3f  % 8.3f  % 8.3f",
                motionManager.deviceMotion.attitude.rotationMatrix.m11, 
                motionManager.deviceMotion.attitude.rotationMatrix.m12, 
                motionManager.deviceMotion.attitude.rotationMatrix.m13,
                motionManager.deviceMotion.attitude.rotationMatrix.m21,
                motionManager.deviceMotion.attitude.rotationMatrix.m22, 
                motionManager.deviceMotion.attitude.rotationMatrix.m23,
                motionManager.deviceMotion.attitude.rotationMatrix.m31,
                motionManager.deviceMotion.attitude.rotationMatrix.m32,
                motionManager.deviceMotion.attitude.rotationMatrix.m33]];
        });
    }
}
            

-(void)deviceStartButtonPressed:(UIButton*)button {
    deviceStartButton.enabled = NO;
    deviceStopButton.enabled = YES;

    if (deviceHandlerSegment.selectedSegmentIndex == 0) {
        [self deviceStartUpdatesWithHandler];
    } else {
        deviceUpdateButton.enabled = YES;
        [motionManager startDeviceMotionUpdates];
    }
}

@end
