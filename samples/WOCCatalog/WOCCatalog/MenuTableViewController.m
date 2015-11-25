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
#import "ButtonsViewController.h"
#import "ControlsViewController.h"
#import "TextFieldsViewController.h"
#import "TextDisplayViewController.h"
#import "TransitionsViewController.h"
#import "AlertsViewController.h"
#import "ToolbarsViewController.h"
#import "SegmentsViewController.h"
#import "WebViewController.h"
#import "SearchBarViewController.h"
#import "PickersViewController.h"
#import "ImagesViewController.h"
#import "OpenGLES11Controller.h"
#import "OpenGLES20Controller.h"
#import "GLKitExampleController.h"
#import "PhotogridViewController.h"
#import "BezierViewController.h"
#import "AutoLayoutViewController.h"
#import "PageViewController.h"

#ifdef WINOBJC
#import "XamlViewController.h"
#import "DisplayModeViewController.h"
#endif

static NSString* controllerKeyName = @"ViewController";
static NSString* viewTitleKeyName = @"ViewName";
@interface MenuTableViewController ()
@end

@implementation MenuTableViewController
- (id)init {
    self = [super init];
    [self setTitle:@"WOCCatalog"];

    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];

    self.menuItems = [NSMutableArray array];

    // Controls
    ControlsViewController* controlsViewController = [[ControlsViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"Controls", viewTitleKeyName, controlsViewController, controllerKeyName, nil]];

    // Buttons
    SBButtonsViewController* buttonsViewController = [[SBButtonsViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"Buttons", viewTitleKeyName, buttonsViewController, controllerKeyName, nil]];

    // AutoLayout
    AutoLayoutViewController* autoLayoutViewController = [[AutoLayoutViewController alloc] init];
    [self.menuItems addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"Constraint Based Layout",
                                                                         viewTitleKeyName,
                                                                         autoLayoutViewController,
                                                                         controllerKeyName,
                                                                         nil]];

#ifdef WINOBJC
    // Controls
    XamlViewController* xamlViewController = [[XamlViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"XamlControls", viewTitleKeyName, xamlViewController, controllerKeyName, nil]];

    // Display mode
    SBDisplayModeViewController* displayModeViewController = [[SBDisplayModeViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"Display Mode", viewTitleKeyName, displayModeViewController, controllerKeyName, nil]];

#endif

    // TextFields
    TextFieldsViewController* textFieldsViewController = [[TextFieldsViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"TextFields", viewTitleKeyName, textFieldsViewController, controllerKeyName, nil]];

    // SearchBar
    SearchBarViewController* searchBarViewController = [[SearchBarViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"SearchBar", viewTitleKeyName, searchBarViewController, controllerKeyName, nil]];

    // OpenGL
    OpenGLES11ViewController* glViewController = [[OpenGLES11ViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"Open GLES 1.1", viewTitleKeyName, glViewController, controllerKeyName, nil]];

    // OpenGL 2.0
    OpenGLES20ViewController* gl20ViewController = [[OpenGLES20ViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"Open GLES 2.0", viewTitleKeyName, gl20ViewController, controllerKeyName, nil]];

    // GLKit
    GLKitExampleController* glkitController = [[GLKitExampleController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"GLKit", viewTitleKeyName, glkitController, controllerKeyName, nil]];

    // Text Display
    TextDrawerController* textDrawerController = [[TextDrawerController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"Text Display", viewTitleKeyName, textDrawerController, controllerKeyName, nil]];

    // Pickers
    PickersViewController* pickersViewController = [[PickersViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"Pickers", viewTitleKeyName, pickersViewController, controllerKeyName, nil]];

    // Images
    ImagesViewController* imagesViewController = [[ImagesViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"ImageView", viewTitleKeyName, imagesViewController, controllerKeyName, nil]];

    // Web
    WebViewController* webViewController = [[WebViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"WebView", viewTitleKeyName, webViewController, controllerKeyName, nil]];

    // Segment
    SegmentsViewController* segmentsViewController = [[SegmentsViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"Segments", viewTitleKeyName, segmentsViewController, controllerKeyName, nil]];

    // Alerts
    AlertsViewController* alertsViewController = [[AlertsViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"Alerts", viewTitleKeyName, alertsViewController, controllerKeyName, nil]];

    // CollectionView
    PhotogridViewController* photoGridViewController = [[PhotogridViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"CollectionView", viewTitleKeyName, photoGridViewController, controllerKeyName, nil]];

    // PageView
    PageViewController* pageViewController = [[PageViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary dictionaryWithObjectsAndKeys:@"Page View", viewTitleKeyName, pageViewController, controllerKeyName, nil]];
    // Bezier
    BezierViewController* bezierViewController = [[BezierViewController alloc] init];
    [self.menuItems
        addObject:[NSDictionary
                      dictionaryWithObjectsAndKeys:@"Beizier Paths", viewTitleKeyName, bezierViewController, controllerKeyName, nil]];
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
