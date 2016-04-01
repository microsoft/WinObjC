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

#import "ToastsViewController.h"
#import <UWP/WindowsSystemDiagnostics.h>
#import <UWP/WindowsUINotifications.h>
#import <UWP/WindowsDataXmlDom.h>

NSString* const kSimpleText = @"simple text";
NSString* const kLocalImage = @"local image";
NSString* const kWebImage = @"web image";
NSString* const kSound = @"sound";
NSString* const kLongDuration = @"long-duration";
NSString* const kProtocol = @"protocol";
NSString* const kSnooze = @"snooze";
NSString* const kInput = @"input";
NSString* const kLogoOverride = @"logo override";
NSString* const kScheduled = @"scheduled (1 min) toast notification";

@implementation ToastsViewController {
    NSArray* menuItems;
    UIButton* simpleTextToastButton;
    UIButton* localImageToastButton;
    UIButton* webImageToastButton;
    UIButton* soundToastButton;
    UIButton* longDurationToastButton;
    UIButton* protocolToastButton;
    UIButton* snoozeToastButton;
    UIButton* inputToastButton;
    UIButton* logoOverrideToastButton;
    UIButton* scheduledToastButton;
}

- (id)init {
    self = [super init];
    return self;
}

- (UIButton*)initializeButton:(NSString*)title selector:(SEL)selector {
    UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [button setTitle:title forState:UIControlStateNormal];
    [button addTarget:self action:selector forControlEvents:UIControlEventTouchUpInside];
    return button;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.title = @"Buttons";

    [self tableView].allowsSelection = NO;

    simpleTextToastButton = [self initializeButton:kSimpleText selector:@selector(simpleTextToastGeneric:)];
    localImageToastButton = [self initializeButton:kLocalImage selector:@selector(localImageToastGeneric:)];
    webImageToastButton = [self initializeButton:kWebImage selector:@selector(webImageToastGeneric:)];
    soundToastButton = [self initializeButton:kSound selector:@selector(soundToastGeneric:)];
    longDurationToastButton = [self initializeButton:kLongDuration selector:@selector(longDurationToastGeneric:)];
    protocolToastButton = [self initializeButton:kProtocol selector:@selector(protocolToastGeneric:)];
    snoozeToastButton = [self initializeButton:kSnooze selector:@selector(snoozeToastGeneric:)];
    inputToastButton = [self initializeButton:kInput selector:@selector(inputToastGeneric:)];
    logoOverrideToastButton = [self initializeButton:kLogoOverride selector:@selector(logoOverrideToastGeneric:)];
    scheduledToastButton = [self initializeButton:kScheduled selector:@selector(scheduledToastGeneric:)];

    self->menuItems = [NSArray arrayWithObjects:self->simpleTextToastButton,
                                                self->localImageToastButton,
                                                self->webImageToastButton,
                                                self->soundToastButton,
                                                self->longDurationToastButton,
                                                self->protocolToastButton,
                                                self->snoozeToastButton,
                                                self->inputToastButton,
                                                self->logoOverrideToastButton,
                                                self->scheduledToastButton,
                                                nil];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self->menuItems count];
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 50;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    UIButton* button = [self->menuItems objectAtIndex:indexPath.row];
    button.frame = CGRectMake(5.0f, 5.0f, 400.0f, cell.frame.size.height - 5.0f);
    button.layer.cornerRadius = 5.0f;
    [cell addSubview:button];
    return cell;
}

- (void)sendNewToast:(NSString*)xmlString {
    WDXDXmlDocument* toastXml = [WDXDXmlDocument make];
    [toastXml loadXml:xmlString];

    WUNToastNotification* toast = [WUNToastNotification makeToastNotification:toastXml];
    [[WUNToastNotificationManager createToastNotifier] show:toast];
}

- (void)simpleTextToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<text>Espresso</text>"
                           "<text>Lorem ipsum dolor sit amet, consectetur elit.</text>"
                           "</binding>"
                           "</visual>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)localImageToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image src=\"ms-appx:///espresso.jpg\" alt=\"Espresso\"/>"
                           "<text>Espresso</text>"
                           "<text>Lorem ipsum dolor sit amet, consectetur elit.</text>"
                           "</binding>"
                           "</visual>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)webImageToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image "
                           "src=\"http://static.wixstatic.com/media/"
                           "66e425_c0daa1882f654b4199b296400e78ff57.jpg_srz_p_315_254_75_22_0.50_1.20_0.00_jpg_srz\" alt=\"Espresso\" />"
                           "<text>Espresso</text>"
                           "</binding>"
                           "</visual>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)soundToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image src=\"ms-appx:///espresso.jpg\" alt=\"Espresso\" />"
                           "<text>Espresso</text>"
                           "</binding>"
                           "</visual>"
                           "<audio src=\"ms-winsoundevent:Notification.IM\"/>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)longDurationToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image src=\"ms-appx:///espresso.jpg\" alt=\"Espresso\" />"
                           "<text>Espresso</text>"
                           "</binding>"
                           "</visual>"
                           "<audio src=\"ms-winsoundevent:Notification.Looping.Alarm\" loop=\"true\"/>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)protocolToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast activationType=\"protocol\" launch=\"http://www.bing.com/images/search?q=coffee\">"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image src=\"ms-appx:///espresso.jpg\" alt=\"Espresso\"/>"
                           "<text>Tap me!</text>"
                           "<text>...to find coffee images.</text>"
                           "</binding>"
                           "</visual>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)snoozeToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image src=\"ms-appx:///espresso.jpg\" alt=\"Espresso\"/>"
                           "<text>\"Espresso\"</text>"
                           "<text>\"Select snooze time.\"</text>"
                           "</binding>"
                           "</visual>"
                           "<actions>"
                           "<input id=\"snoozeTime\" type=\"selection\" defaultSelection=\"10\">"
                           "<selection id=\"1\" content=\"1 minute\" />"
                           "<selection id=\"5\" content=\"5 minutes\" />"
                           "<selection id=\"10\" content=\"10 minutes\" />"
                           "<selection id=\"30\" content=\"30 minutes\" />"
                           "<selection id=\"60\" content=\"1 hour\" />"
                           "</input>"
                           "<action activationType=\"system\" arguments=\"snooze\" hint-inputId=\"snoozeTime\" content=\"\"/>"
                           "<action activationType=\"system\" arguments=\"dismiss\" content=\"\"/>"
                           "</actions>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)inputToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image placement=\"appLogoOverride\" src=\"ms-appx:///espresso.jpg\"/>"
                           "<text hint-style=\"header\">Espresso</text>"
                           "<text hint-style=\"subheader\" hint-maxLines=\"2\">Lorem ipsum dolor sit amet, consectetur elit.</text>"
                           "</binding>"
                           "</visual>"
                           "<actions>"
                           "<input type=\"text\" id=\"1\" placeHolderContent=\"Type a message\"/>"
                           "<action content=\"send\" hint-inputId=\"1\" imageUri=\"ms-appx:///icon-white-espresso.png\" "
                           "activationType=\"foreground\" arguments=\"action?=send\"/>"
                           "</actions>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)logoOverrideToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<image src=\"ms-appx:///espresso.jpg\" alt=\"Espresso\" placement=\"appLogoOverride\"/>"
                           "<text>Espresso</text>"
                           "</binding>"
                           "</visual>"
                           "</toast>";

    [self sendNewToast:xmlString];
}

- (void)scheduledToastGeneric:(UIButton*)button {
    NSString* xmlString = @"<toast>"
                           "<visual>"
                           "<binding template=\"ToastGeneric\">"
                           "<text>Scheduled toast notification.</text>"
                           "</binding>"
                           "</visual>"
                           "</toast>";

    WDXDXmlDocument* toastXml = [WDXDXmlDocument make];
    [toastXml loadXml:xmlString];

    // TODO: Try converting NSDateTime to WFDateTime.
    WGCalendar* _calendar = [WGCalendar make];
    [_calendar setToNow];
    [_calendar addMinutes:1];
    WFDateTime* dt = [_calendar getDateTime];

    WUNScheduledToastNotification* toast = [WUNScheduledToastNotification makeScheduledToastNotification:toastXml deliveryTime:dt];
    [[WUNToastNotificationManager createToastNotifier] addToSchedule:toast];
}

@end
