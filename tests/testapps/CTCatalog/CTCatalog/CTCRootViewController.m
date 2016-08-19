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
#import "CTCFontTestViewController.h"
#import "CTCRunTestViewController.h"
#import "CTCLineTestViewController.h"
#import "CTCFrameTestViewController.h"
#import "CTCParagraphStyleTestViewController.h"
#import "CTCFramesetterTestViewController.h"

@interface TestRow : NSObject

+ (TestRow*)row:(NSString*)name testClass:(Class)testClass;
@property (nonatomic, strong) NSString* name;
@property (nonatomic, strong) Class testClass;

@end

@implementation TestRow

+ (TestRow*)row:(NSString*)name testClass:(Class)testClass {
    TestRow* row = [TestRow new];
    row.name = name;
    row.testClass = testClass;
    return row;
}

@end

@interface CTCRootViewController () <UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong) NSArray<TestRow*>* tests;

@end

@implementation CTCRootViewController

- (NSArray*)tests {
    if (!_tests) {
        _tests = @[
            [TestRow row:@"Alignment" testClass:[CTCAlignmentTestViewController class]],
            [TestRow row:@"Font Functions" testClass:[CTCFontTestViewController class]],
            [TestRow row:@"Run Functions" testClass:[CTCRunTestViewController class]],
            [TestRow row:@"Frame Functions" testClass:[CTCFrameTestViewController class]],
            [TestRow row:@"ParagraphStyle Tests" testClass:[CTCParagraphStyleTestViewController class]],
            [TestRow row:@"Line Functions" testClass:[CTCLineTestViewController class]],
            [TestRow row:@"Framesetter Functions" testClass:[CTCFramesetterTestViewController class]]
        ];
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
    [self.navigationController pushViewController:[[self.tests[indexPath.row].testClass alloc] init] animated:YES];
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
