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

static NSString* controllerKeyName = @"ViewController";
static NSString* viewTitleKeyName = @"ViewName";

@interface MenuTableViewController ()

@end

@implementation MenuTableViewController

- (id)init {
    self = [super init];

    [self setTitle:@"WOCCatalog"];

    self.menuItems = [[NSMutableArray alloc] init];

    return self;
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
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    //    cell.textLabel.text = [self.menuItems objectAtIndex:indexPath.row];
    cell.textLabel.text = [[self.menuItems objectAtIndex:indexPath.row] objectForKey:viewTitleKeyName];

    return cell;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    UIViewController* viewController = [[self.menuItems objectAtIndex:indexPath.row] objectForKey:controllerKeyName];
    [[self navigationController] pushViewController:viewController animated:YES];
}

@end
