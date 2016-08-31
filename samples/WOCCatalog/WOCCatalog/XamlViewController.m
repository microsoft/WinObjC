//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
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

#ifdef WINOBJC

#import <QuartzCore/QuartzCore.h>
#import <QuartzCore/CALayer.h>
#import "XamlViewController.h"

//
// A special checkbox that is inheriting off the regular one and overriding the onToggle message:
//

#ifdef WINOBJC_WIN10

@interface OurCheckBox : WXCCheckBox <WUXCPIToggleButtonOverrides>
@end

@implementation OurCheckBox
- (void)onToggle {
    NSLog(@"Clicked!");
    [super onToggle];
}
@end

#endif

@implementation XamlViewController {
}

- (void)viewWillAppear:(BOOL)animated {
    self.playPauseButton.content = [WFPropertyValue createString:@"Pause"];
}

- (void)viewDidLoad {
    [super viewDidLoad];

    [self tableView].allowsSelection = NO;
    self.playPauseButton = [WXCButton make];
    self.playPauseButton.background = [WUXMSolidColorBrush makeInstanceWithColor:[WUColors cornflowerBlue]];
    self.playPauseButton.requestedTheme = WXApplicationThemeDark;
    self.playPauseButton.content = [WFPropertyValue createString:@"Pause"];

    __weak XamlViewController* weakSelf = self;

    [weakSelf.playPauseButton addClickEvent:^(RTObject* sender, WXRoutedEventArgs* e) {
        if ([weakSelf.mediaElement currentState] == WUXMMediaElementStatePlaying) {
            weakSelf.playPauseButton.content = [WFPropertyValue createString:@"Play"];
            [weakSelf.mediaElement pause];
        } else {
            weakSelf.playPauseButton.content = [WFPropertyValue createString:@"Pause"];
            [weakSelf.mediaElement play];
        }
    }];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
#ifdef __MAPSUPPORT
    return 6;
#else
    return 5;
#endif
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row == 3 || indexPath.row == 5) {
        return 360;
    }
    return 50;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    if (indexPath.row == 0) {
        WXCDatePicker* datePicker = [WXCDatePicker make];
        UIView* datePickerView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 280.0f, cell.frame.size.height)];
        [datePickerView setXamlElement:datePicker];
        cell.textLabel.text = @"DatePicker";
        cell.accessoryView = datePickerView;

    } else if (indexPath.row == 1) {
        UIView* buttonView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 100.0f, cell.frame.size.height)];
        [buttonView setXamlElement:self.playPauseButton];
        cell.textLabel.text = @"Button";
        cell.accessoryView = buttonView;
    } else if (indexPath.row == 2) {
#ifdef WINOBJC_WIN10
        WXCCheckBox* checkBox = [OurCheckBox make];
#else
        WXCCheckBox* checkBox = [WXCCheckBox make];
#endif
        checkBox.requestedTheme = WXApplicationThemeDark;
        checkBox.content = [WFPropertyValue createString:@"Check"];
        UIView* checkBoxView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 100.0f, cell.frame.size.height)];
        [checkBoxView setXamlElement:checkBox];
        cell.textLabel.text = @"Check Box";
        cell.accessoryView = checkBoxView;
    } else if (indexPath.row == 3) {
        self.mediaElement = [WXCMediaElement make];
        UIView* meView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 300.0f, 300.f)];
        self.mediaElement.autoPlay = YES;
        [meView setXamlElement:self.mediaElement];
        self.mediaElement.source = [WFUri makeUri:@"http://video.ch9.ms/ch9/189c/72816d8e-6ccb-4b42-aebd-325363c8189c/win10.mp4"];
        cell.textLabel.text = @"MSDN tv";
        cell.accessoryView = meView;
    } else if (indexPath.row == 4) {
        WXCSlider* slider = [WXCSlider make];
        slider.requestedTheme = WXApplicationThemeDark;
        slider.minimum = 0.0;
        slider.maximum = 100.0;
        slider.value = 25.0;
        slider.smallChange = 5.0;
        slider.largeChange = 20.0;
        UIView* sliderView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 300.0f, cell.frame.size.height)];
        [sliderView setXamlElement:slider];
        cell.textLabel.text = @"Slider";
        cell.accessoryView = sliderView;
    } else {
#ifdef __MAPSUPPORT
        self.mapElement = [WUXCMMapControl create];
        UIView* mapView = [[UIView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, 400.0f, 300.f)];
        [mapView setXamlElement:self.mapElement];
        cell.textLabel.text = @"Map Control";
        cell.accessoryView = mapView;
#endif
    }

    return cell;
}

@end

#endif
