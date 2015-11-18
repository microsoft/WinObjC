#ifdef WINOBJC
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

#import "DisplayModeViewController.h"

@implementation SBDisplayModeViewController {
    NSArray* _informationLabels;
    NSArray* _presetNames;
    NSArray* _orientationNames;
    UITextField *fixedWidth, *nativeBounds, *fixedHeight, *magnification, *fixedAspect, *scale, *nativeScale, *uiScreenBrightness,
        *hostScreenScale;
    UIPickerView *presets, *orientations;
    UIScreen* uiScreen;
}

- (void)toggleFitToWindow:(UISwitch*)sender {
    UIApplication.displayMode.autoMagnification = sender.on;
    [UIApplication.displayMode updateDisplaySettings];
}

- (void)toggleAdjustWindowSize:(UISwitch*)sender {
    UIApplication.displayMode.sizeUIWindowToFit = sender.on;
    [UIApplication.displayMode updateDisplaySettings];
}

- (void)setWidth:(UITextField*)sender {
    float val = [sender.text floatValue];
    if (val != val) {
        val = 0.0f;
    }
    if (val < 0.0f) {
        val = 0.0f;
    }
    if (val < 200.0f && val > 0.0f) {
        val = 200.09f;
    }
    if (val > 2048.0f) {
        val = 2048.0f;
    }

    UIApplication.displayMode.fixedWidth = val;
    sender.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedWidth];
    [UIApplication.displayMode updateDisplaySettings];
    [presets selectRow:0 inComponent:0 animated:FALSE];
}

- (void)setHeight:(UITextField*)sender {
    float val = [sender.text floatValue];
    if (val != val) {
        val = 0.0f;
    }
    if (val < 0.0f) {
        val = 0.0f;
    }
    if (val < 200.0f && val > 0.0f) {
        val = 200.09f;
    }
    if (val > 2048.0f) {
        val = 2048.0f;
    }

    UIApplication.displayMode.fixedHeight = val;
    sender.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedHeight];
    [UIApplication.displayMode updateDisplaySettings];
    [presets selectRow:0 inComponent:0 animated:FALSE];
}

- (void)setMagnification:(UITextField*)sender {
    float val = [sender.text floatValue];
    if (val != val) {
        val = 0.0f;
    }
    if (val < 0.25f) {
        val = 0.25f;
    }
    if (val > 5.0f) {
        val = 5.0f;
    }

    UIApplication.displayMode.magnification = val;
    sender.text = [NSString stringWithFormat:@"%.2f", UIApplication.displayMode.magnification];
    [UIApplication.displayMode updateDisplaySettings];
    [presets selectRow:0 inComponent:0 animated:FALSE];
}

- (void)setAspect:(UITextField*)sender {
    float val = [sender.text floatValue];
    if (val != val) {
        val = 0.0f;
    }
    if (val > 0.0f && val < 0.2f) {
        val = 0.2f;
    }
    if (val > 5.0f) {
        val = 5.0f;
    }

    UIApplication.displayMode.fixedAspectRatio = val;
    sender.text = [NSString stringWithFormat:@"%.2f", UIApplication.displayMode.fixedAspectRatio];
    [UIApplication.displayMode updateDisplaySettings];
    [presets selectRow:0 inComponent:0 animated:FALSE];
}

- (void)updateLabels {
    for (NSDictionary* curItem in _informationLabels) {
        UITableViewCell* cell = curItem[@"Cell"];
        UILabel* label = (UILabel*)cell.accessoryView;

        label.text = [UIApplication.displayMode valueForKey:curItem[@"ValueName"]];
        cell.textLabel.text = curItem[@"LabelName"];
        cell.detailTextLabel.text = curItem[@"ValueName"];
    }

    fixedWidth.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedWidth];
    fixedHeight.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedHeight];
    fixedAspect.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedAspectRatio];
    magnification.text = [NSString stringWithFormat:@"%.2f", UIApplication.displayMode.magnification];
    hostScreenScale.text = [NSString stringWithFormat:@"%.2f", UIApplication.displayMode.hostScreenScale];
    scale.text = [NSString stringWithFormat:@"%.2f", [uiScreen scale]];
    nativeScale.text = [NSString stringWithFormat:@"%.2f", [uiScreen nativeScale]];
    CGRect nativeBoundRect = [uiScreen nativeBounds];
    nativeBounds.text = [NSString stringWithFormat:@"%.2f, %.2f", nativeBoundRect.size.width, nativeBoundRect.size.height];
}

- (NSInteger)pickerView:(UIPickerView*)view numberOfRowsInComponent:(NSInteger)component {
    if (view == presets) {
        return [_presetNames count];
    } else if (view == orientations) {
        return [_orientationNames count];
    } else {
        return 0;
    }
}

- (NSString*)pickerView:(UIPickerView*)view titleForRow:(NSInteger)row forComponent:(NSInteger)component {
    if (view == presets) {
        return _presetNames[row];
    } else if (view == orientations) {
        return _orientationNames[row];
    } else {
        return nil;
    }
}

- (NSInteger)numberOfComponentsInPickerView:(UIPickerView*)view {
    return 1;
}

- (void)pickerView:(UIPickerView*)view didSelectRow:(NSInteger)row inComponent:(NSInteger)component {
    if (view == presets) {
        if (row == 0) {
            return;
        }

        [UIApplication.displayMode setDisplayPreset:(WOCDisplayPreset)(row - 1)];
        [UIApplication.displayMode updateDisplaySettings];
    } else if (view == orientations) {
        switch (row) {
            case 0:
                UIApplication.displayMode.presentationTransform = UIInterfaceOrientationPortrait;
                break;

            case 1:
                UIApplication.displayMode.presentationTransform = UIInterfaceOrientationLandscapeLeft;
                break;

            case 2:
                UIApplication.displayMode.presentationTransform = UIInterfaceOrientationLandscapeRight;
                break;

            case 3:
                UIApplication.displayMode.presentationTransform = UIInterfaceOrientationPortraitUpsideDown;
                break;
        }
        [UIApplication.displayMode updateDisplaySettings];
    }
}

- (id)init {
    self = [super init];
    self.rows = [NSMutableArray new];

    UITableViewCell* cell;
    uiScreen = [[UIScreen alloc] init];
    presets = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = presets;
    cell.textLabel.text = @"Preset modes";
    [self.rows addObject:cell];
    presets.dataSource = self;

    _presetNames = @[
        @"Custom",
        @"Phone320x480",
        @"Phone320x568",
        @"Tablet768x1024",
        @"Native",
        @"Native2x",
        @"Native320Fixed",
        @"Native768Fixed",
        @"Native4x3Aspect",
        @"Native16x9Aspect"
    ];

    [presets selectRow:4 inComponent:0 animated:FALSE];
    presets.delegate = self;

    orientations = [[UIPickerView alloc] initWithFrame:CGRectMake(0, 0, 200, 200)];
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = orientations;
    cell.textLabel.text = @"Presentation Transform";
    [self.rows addObject:cell];
    orientations.dataSource = self;

    _orientationNames = @[ @"Portrait", @"LandscapeLeft", @"LandscapeRight", @"PortraitUpsideDown" ];

    [orientations selectRow:0 inComponent:0 animated:FALSE];
    orientations.delegate = self;

    UISwitch* fitToWindow = [UISwitch new];
    fitToWindow.on = UIApplication.displayMode.autoMagnification;
    [fitToWindow addTarget:self action:@selector(toggleFitToWindow:) forControlEvents:UIControlEventValueChanged];

    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = fitToWindow;
    cell.textLabel.text = @"Auto magnification";
    [self.rows addObject:cell];

    UISwitch* adjustWindowSize = [UISwitch new];
    adjustWindowSize.on = UIApplication.displayMode.sizeUIWindowToFit;
    [adjustWindowSize addTarget:self action:@selector(toggleAdjustWindowSize:) forControlEvents:UIControlEventValueChanged];

    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = adjustWindowSize;
    cell.textLabel.text = @"Size UIWindow to fit";
    [self.rows addObject:cell];

    fixedWidth = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
    fixedWidth.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedWidth];
    fixedWidth.borderStyle = UITextBorderStyleBezel;
    [fixedWidth addTarget:self action:@selector(setWidth:) forControlEvents:UIControlEventEditingDidEnd];

    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"MenuCell"];
    cell.accessoryView = fixedWidth;
    cell.textLabel.text = @"Fixed width";
    cell.detailTextLabel.text = @"0.0 = fit to window";
    [self.rows addObject:cell];

    fixedHeight = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
    fixedHeight.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedHeight];
    fixedHeight.borderStyle = UITextBorderStyleBezel;
    [fixedHeight addTarget:self action:@selector(setHeight:) forControlEvents:UIControlEventEditingDidEnd];
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"MenuCell"];
    cell.accessoryView = fixedHeight;
    cell.textLabel.text = @"Fixed height";
    cell.detailTextLabel.text = @"0.0 = fit to window";
    [self.rows addObject:cell];

    fixedAspect = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
    fixedAspect.text = [NSString stringWithFormat:@"%.1f", UIApplication.displayMode.fixedAspectRatio];
    fixedAspect.borderStyle = UITextBorderStyleBezel;
    [fixedAspect addTarget:self action:@selector(setAspect:) forControlEvents:UIControlEventEditingDidEnd];
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"MenuCell"];
    cell.accessoryView = fixedAspect;
    cell.textLabel.text = @"Fixed aspect ratio";
    cell.detailTextLabel.text = @"0.0 = none";
    [self.rows addObject:cell];

    magnification = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
    magnification.text = [NSString stringWithFormat:@"%.2f", UIApplication.displayMode.magnification];
    magnification.borderStyle = UITextBorderStyleBezel;
    [magnification addTarget:self action:@selector(setMagnification:) forControlEvents:UIControlEventEditingDidEnd];
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = magnification;
    cell.textLabel.text = @"Magnification";
    [self.rows addObject:cell];

    scale = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
    scale.text = [NSString stringWithFormat:@"%.2f", [uiScreen scale]];
    scale.borderStyle = UITextBorderStyleBezel;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = scale;
    cell.textLabel.text = @"Scale";
    [self.rows addObject:cell];

    nativeScale = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
    nativeScale.text = [NSString stringWithFormat:@"%.2f", [uiScreen nativeScale]];
    nativeScale.borderStyle = UITextBorderStyleBezel;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = nativeScale;
    cell.textLabel.text = @"Native Scale";
    [self.rows addObject:cell];

    nativeBounds = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 150, 20)];
    CGRect nativeBoundRect = [uiScreen nativeBounds];
    nativeBounds.text = [NSString stringWithFormat:@"%.2f, %.2f", nativeBoundRect.size.width, nativeBoundRect.size.height];
    nativeBounds.borderStyle = UITextBorderStyleBezel;
    nativeBounds.adjustsFontSizeToFitWidth = TRUE;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = nativeBounds;
    cell.textLabel.text = @"Native Bounds";
    [self.rows addObject:cell];

    uiScreenBrightness = [[UITextField alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
    uiScreenBrightness.text = [NSString stringWithFormat:@"%.2f", [uiScreen brightness]];
    uiScreenBrightness.borderStyle = UITextBorderStyleBezel;
    cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.accessoryView = uiScreenBrightness;
    cell.textLabel.text = @"Brightness";
    [self.rows addObject:cell];

    _informationLabels = @[
        [@{ @"LabelName" : @"Current App Size",
            @"ValueName" : @"currentSize" } mutableCopy],

        [@{ @"LabelName" : @"Current App Magnfication",
            @"ValueName" : @"currentMagnification" } mutableCopy],

        [@{ @"LabelName" : @"Host Window Size (Points)",
            @"ValueName" : @"hostWindowSize" } mutableCopy],

        [@{ @"LabelName" : @"Host Screen Size (Pixels)",
            @"ValueName" : @"hostScreenSizePixels" } mutableCopy],

        [@{ @"LabelName" : @"Host Screen Scale (pixels per point)",
            @"ValueName" : @"hostScreenScale" } mutableCopy],

        [@{ @"LabelName" : @"Host Screen Size (Points)",
            @"ValueName" : @"hostScreenSizePoints" } mutableCopy],

        [@{ @"LabelName" : @"Host Screen Size (Inches)",
            @"ValueName" : @"hostScreenSizeInches" } mutableCopy],

    ];

    for (NSMutableDictionary* curItem in _informationLabels) {
        UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 100, 20)];
        label.text = [UIApplication.displayMode valueForKey:curItem[@"ValueName"]];
        label.adjustsFontSizeToFitWidth = TRUE;
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"MenuCell"];
        cell.accessoryView = label;
        cell.textLabel.text = curItem[@"LabelName"];
        cell.detailTextLabel.text = curItem[@"ValueName"];
        [self.rows addObject:cell];
        curItem[@"Cell"] = cell;
    }

    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(updateLabels)
                                                 name:UIApplicationDidChangeDisplayModeNofication
                                               object:nil];

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.title = @"Display Mode";

    [self tableView].allowsSelection = NO;
}

- (float)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.row == 0 || indexPath.row == 1) {
        //  Picker view
        return 240.0f;
    }
    return 50.0f;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [_rows count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    return [_rows objectAtIndex:indexPath.row];
}

@end
#endif