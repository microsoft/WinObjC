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

#import "MenuTableViewController.h"

static NSString* viewKeyName = @"View";
static NSString* controllerKeyName = @"ViewController";
static NSString* viewTitleKeyName = @"ViewName";

@implementation MenuTableViewController

- (id)init {
    if (self = [super init]) {
        self.menuItems = [[NSMutableArray alloc] init];
    }

    return self;
}

- (instancetype)initWithCoder:(NSCoder *)aDecoder {
    if (self = [super initWithCoder:aDecoder]) {
        self.menuItems = [[NSMutableArray alloc] init];
    }

    return self;
}

- (void)addMenuItemView:(UIView*)view andTitle:(NSString*)title {
    [self.menuItems addObject:[NSDictionary dictionaryWithObjectsAndKeys:title, viewTitleKeyName, view, viewKeyName, nil]];
}

- (void)addMenuItemViewController:(UIViewController*)controller andTitle:(NSString*)title {
    [self.menuItems addObject:[NSDictionary dictionaryWithObjectsAndKeys:title, viewTitleKeyName, controller, controllerKeyName, nil]];
}

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.menuItems count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    NSDictionary* currentObject = [self.menuItems objectAtIndex:indexPath.row];
    if (currentObject != nil && [currentObject isKindOfClass:[UIViewController class]]) {
        cell.textLabel.text = [currentObject objectForKey:viewTitleKeyName];
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    } else {
        cell.textLabel.text = [currentObject objectForKey:viewTitleKeyName];
        cell.accessoryView = [currentObject objectForKey:viewKeyName];
    }

    return cell;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    UIViewController* viewController = [[self.menuItems objectAtIndex:indexPath.row] objectForKey:controllerKeyName];
    if ([viewController isKindOfClass:[UIViewController class]]) {
        [[super navigationController] pushViewController:viewController animated:YES];
    }
}
@end
