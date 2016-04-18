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

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

@interface CoreMotionViewController : UIViewController
{
    UILabel* accLabel;
    UILabel* accVal;
    UIButton* accStopButton;
    UIButton* accStartButton;
    UIButton* accUpdateButton;
    UISegmentedControl* accHandlerSegment;
    NSOperationQueue* accQueue;
    UIActivityIndicatorView* progressInd;
    int accHeight;

    UILabel* gyroLabel;
    UILabel* gyroVal;
    UIButton* gyroStopButton;
    UIButton* gyroStartButton;
    UIButton* gyroUpdateButton;
    UISegmentedControl* gyroHandlerSegment;
    NSOperationQueue* gyroQueue;
    int gyroHeight;
    
    UILabel* magnetoLabel;
    UILabel* magnetoVal;
    UIButton* magnetoStopButton;
    UIButton* magnetoStartButton;
    UIButton* magnetoUpdateButton;
    UISegmentedControl* magnetoHandlerSegment;
    NSOperationQueue* magnetoQueue;
    int magnetoHeight;
    
    UILabel* deviceLabel;
    UILabel* deviceVal;
    UILabel* deviceQVal;
    UILabel* deviceRMVal;
    UIButton* deviceStopButton;
    UIButton* deviceStartButton;
    UIButton* deviceUpdateButton;
    UISegmentedControl*deviceHandlerSegment;
    NSOperationQueue* deviceQueue;
    int deviceHeight;

    CMMotionManager* motionManager;
    UIScrollView* scrollView;
    int buttonLength;
}
@end
