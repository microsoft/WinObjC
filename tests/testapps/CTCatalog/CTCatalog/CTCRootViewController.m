//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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
//*****************************************************************************

#import "CTCRootViewController.h"
#import "CTCAlignmentTestViewController.h"

@interface TestRow : NSObject

+ (TestRow*)row:(NSString*)name class:(Class) class;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) Class class;

@end

@implementation TestRow

+ (TestRow*)row:(NSString*)name class:(Class) class {
    TestRow* row = [TestRow new];
    row.name = name;
    row.class = class;
    return row;
}

@end

@interface CTCRootViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSArray <TestRow*>* tests;

@end

@implementation CTCRootViewController

- (NSArray*)tests {
    if (!_tests) {
        _tests = @[ [TestRow row:@"CTCAlignmentTest" class:[CTCAlignmentTestViewController class]] ];
    }
    return _tests;
}

- (NSString*)title {
    return @"Tests";
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    UITableView* tableView = [[UITableView alloc] init];
    [tableView setDelegate:self];
    [tableView setDataSource:self];
    [tableView setFrame:self.view.bounds];
    [self.view addSubview:tableView];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

// UITableViewDelegate

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    [self.navigationController pushViewController:[[self.tests[indexPath.row].class alloc] init] animated:YES];
}

// UITableViewDataSource

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.tests count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    NSString* reuseIdentifier = @"reuseIdentifier";

    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:reuseIdentifier];

    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:reuseIdentifier];
    }

    [cell.textLabel setText:self.tests[indexPath.row].name];

    return cell;
}

@end
