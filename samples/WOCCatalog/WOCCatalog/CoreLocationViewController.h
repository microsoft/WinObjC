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

#pragma once

#import <CoreLocation/CoreLocation.h>
#import <CoreMotion/CoreMotion.h>
#import <UIKit/UIKit.h>

@interface CoreLocationViewController : UIViewController <CLLocationManagerDelegate> {
    UILabel* locLabel;
    UILabel* locVal;
    UIButton* locStopButton;
    UIButton* locStartButton;
    UIButton* locUpdateButton;
    UIActivityIndicatorView* progressInd;

    UILabel* headingLabel;
    UILabel* headingVal;
    UIButton* headingStopButton;
    UIButton* headingStartButton;

    CLLocationManager* locationManager;
    CMMotionManager* motionManager;
    UIScrollView* scrollView;
    CGFloat locHeight;
    CGFloat headingHeight;
    CGFloat buttonLength;
}
@end
