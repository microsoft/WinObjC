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
#import "AudioToolboxViewController.h"
#import <AudioToolbox/AudioToolbox.h>

void soundCompletion(SystemSoundID ssID, void* self);

@implementation AudioToolboxViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    CGRect bounds = [[UIScreen mainScreen] bounds];
    
    scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, bounds.size.width, bounds.size.height)];
    scrollView.backgroundColor = [UIColor whiteColor];
    scrollView.contentSize = CGSizeMake(450, 900);
    scrollView.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);

    // Currently using the example wav file located at deps/3rdparty/openal-soft-winphone/examples.
    // The file duration 1 min 15 secs, which is a bit on the longer side.
    CFURLRef url = (__bridge CFURLRef)[[NSBundle mainBundle] URLForResource:@"test" withExtension:@"wav"];

    AudioServicesCreateSystemSoundID(url, &sid);

    systemSoundLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 50, 200, 50)];
    [systemSoundLabel setBackgroundColor:[UIColor whiteColor]];
    [systemSoundLabel setText:@"System Sound Services"];
    [systemSoundLabel setTextAlignment:NSTextAlignmentLeft];
    [scrollView addSubview:systemSoundLabel];

    playAlertSound = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [playAlertSound setTitle:@"Alert Sound" forState:UIControlStateNormal];
    playAlertSound.frame = CGRectMake(210, 50, 230, 40);
    [playAlertSound addTarget:self action:@selector(playAlertSoundPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:playAlertSound];

    playSystemSound = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [playSystemSound setTitle:@"System Sound" forState:UIControlStateNormal];
    playSystemSound.frame = CGRectMake(210, 100, 230, 40);
    [playSystemSound addTarget:self action:@selector(playSystemSoundPressed:) forControlEvents:UIControlEventTouchUpInside];
    [scrollView addSubview:playSystemSound];

    completionLabel = [[UILabel alloc] initWithFrame:CGRectMake(10, 150, 350, 50)];
    [completionLabel setBackgroundColor:[UIColor whiteColor]];
    [completionLabel setText:@"Completion Callback"];
    [completionLabel setTextAlignment:NSTextAlignmentLeft];
    [scrollView addSubview:completionLabel];

    callbackFunction = [[UISwitch alloc] initWithFrame:CGRectMake(400, 165, 100, 40)];
    [callbackFunction setBackgroundColor:[UIColor whiteColor]];
    [callbackFunction addTarget:self action:@selector(callbackFunctionChanged:) forControlEvents:UIControlEventValueChanged];
    [scrollView addSubview:callbackFunction];
    
    [self.view setBackgroundColor:[UIColor whiteColor]];
    [self.view addSubview:scrollView];
}


- (void)callbackFunctionChanged:(UISwitch*)callbackSwitch {
    
    if ([callbackSwitch isOn]) {
        AudioServicesAddSystemSoundCompletion(sid, nil, nil, soundCompletion, (__bridge void*)self); 
    } else {
        AudioServicesRemoveSystemSoundCompletion(sid);
    }
}


- (void)playAlertSoundPressed:(UIButton*)button {
    [self completionLabel:false];
    AudioServicesPlayAlertSound(sid);  
}


- (void)playSystemSoundPressed:(UIButton*)button {
    [self completionLabel:false];
    AudioServicesPlaySystemSound(sid);  
}

- (void)completionLabel:(BOOL)show {
    if (show) {
        [completionLabel setText:@"Completion Callback\tFinished Playing"];
    } else {
        [completionLabel setText:@"Completion Callback"];
    }
}

@end

void soundCompletion(SystemSoundID ssID, void* self) {

    [(__bridge AudioToolboxViewController*)self completionLabel:true];
}
