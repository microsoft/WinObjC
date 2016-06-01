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

#import "WindowViewController.h"
#import "AppDelegate.h"

@implementation WindowViewController

- (id)init {
    self = [super init];
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self tableView].allowsSelection = NO;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 1;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 50;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    if (indexPath.row == 0) {
        UIButton* levelTestButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        levelTestButton.frame = CGRectMake(5.0f, 5.0f, 150.0f, cell.frame.size.height - 5.0f);
        levelTestButton.layer.cornerRadius = 5.0f;
        [levelTestButton setTitle:@"WindowLevel" forState:UIControlStateNormal];
        [levelTestButton addTarget:self action:@selector(_btnClicked) forControlEvents:UIControlEventTouchUpInside];
        [cell addSubview:levelTestButton];
    }

    return cell;
}

- (void)_btnClicked {
    AppDelegate* appDelegate = (AppDelegate*)[[UIApplication sharedApplication] delegate];
    UIWindow* mainWindow = [appDelegate window];
    mainWindow.windowLevel = UIWindowLevelNormal;
    UIWindow* levelWindow = [appDelegate levelControlWindow];
    levelWindow.windowLevel = UIWindowLevelNormal + 1.0f;
    UIWindow* redWindow = [appDelegate redColorWindow];
    redWindow.windowLevel = UIWindowLevelNormal + 2.0f;
    UIWindow* blueWindow = [appDelegate blueColorWindow];
    blueWindow.windowLevel = UIWindowLevelNormal + 3.0f;
    UIWindow* yellowWindow = [appDelegate yellowColorWindow];
    yellowWindow.windowLevel = UIWindowLevelNormal + 4.0f;
}

@end
