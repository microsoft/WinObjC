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

#import "TilesViewController.h"
#import <UWP/WindowsSystemDiagnostics.h>
#import <UWP/WindowsUINotifications.h>
#import <UWP/WindowsDataXmlDom.h>

NSString* const kUpdatePrimaryTile = @"update primary tile";
NSString* const kScheduledTileUpdate = @"scheduled (1 min) tile update";
NSString* const kUpdateBadge = @"update badge";

@implementation TilesViewController {
    NSArray* menuItems;
    UIButton* updatePrimaryTileButton;
    UIButton* scheduledTileUpdateButton;
    UIButton* updateBadgeButton;
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
    self.title = @"Tiles";
    [self tableView].allowsSelection = NO;

    updatePrimaryTileButton = [self initializeButton:kUpdatePrimaryTile selector:@selector(updatePrimaryTile:)];
    scheduledTileUpdateButton = [self initializeButton:kScheduledTileUpdate selector:@selector(scheduledTileUpdate:)];
    updateBadgeButton = [self initializeButton:kUpdateBadge selector:@selector(updateBadge:)];

    self->menuItems =
        [NSArray arrayWithObjects:self->updatePrimaryTileButton, self->scheduledTileUpdateButton, self->updateBadgeButton, nil];
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

- (WDXDXmlDocument*)createTileXml {
    WDXDXmlDocument* tileXml = [WUNTileUpdateManager getTemplateContent:WUNTileTemplateTypeTileSquare150x150Text01];
    WDXDXmlNodeList* textNodes = [tileXml getElementsByTagName:@"text"];

    RTObject<WDXDIXmlNode>* node0 = [textNodes item:0];
    node0.innerText = @"FG";

    NSDateFormatter* formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"HH:mm:ss"];
    RTObject<WDXDIXmlNode>* node1 = [textNodes item:1];
    node1.innerText = [formatter stringFromDate:[NSDate date]];

    return tileXml;
}

- (void)updatePrimaryTile:(UIButton*)button {
    WDXDXmlDocument* tileXml = [self createTileXml];
    WUNTileNotification* tile = [WUNTileNotification makeTileNotification:tileXml];
    [[WUNTileUpdateManager createTileUpdaterForApplication] update:tile];
}

- (void)updateBadge:(UIButton*)button {
    NSString* xmlString = @"<badge value=\"10\"/>";

    WDXDXmlDocument* badgeXml = [WDXDXmlDocument make];
    [badgeXml loadXml:xmlString];
    WUNBadgeNotification* badge = [WUNBadgeNotification makeBadgeNotification:badgeXml];
    [[WUNBadgeUpdateManager createBadgeUpdaterForApplication] update:badge];
}

- (void)scheduledTileUpdate:(UIButton*)button {
    WDXDXmlDocument* tileXml = [self createTileXml];

    // TODO: Try converting NSDateTime to WFDateTime.
    WGCalendar* _calendar = [WGCalendar make];
    [_calendar setToNow];
    [_calendar addMinutes:1];
    WFDateTime* dt = [_calendar getDateTime];

    WUNScheduledTileNotification* tile = [WUNScheduledTileNotification makeScheduledTileNotification:tileXml deliveryTime:dt];
    [[WUNTileUpdateManager createTileUpdaterForApplication] addToSchedule:tile];
}
@end