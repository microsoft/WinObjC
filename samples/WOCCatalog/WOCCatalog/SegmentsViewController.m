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

#import "SegmentsViewController.h"

@implementation SegmentsViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    [self tableView].allowsSelection = NO;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    
    return 3;
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }
    
    if (indexPath.row == 0) {
        NSArray *segmentTextContent = [NSArray arrayWithObjects: @"Option 1", @"Option 2", @"Option 3", nil];
        
        UISegmentedControl *segmentedControl = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
        CGRect frame = CGRectMake( 5.0,
                           5.0,
                           cell.frame.size.width - 10.0,
                           cell.frame.size.height - 5.0);
        segmentedControl.frame = frame;
        segmentedControl.autoresizingMask = (UIViewAutoresizingFlexibleWidth);
        
        [cell addSubview: segmentedControl];

        
    } else if (indexPath.row == 1) {
        
        UISegmentedControl *segmentedControl = [[UISegmentedControl alloc] initWithItems:
                                                [NSArray arrayWithObjects:
                                                 [UIImage imageNamed:@"segment_check.png"],
                                                 [UIImage imageNamed:@"segment_search.png"],
                                                 [UIImage imageNamed:@"segment_tools.png"],
                                                 nil]];
        
        CGRect frame = CGRectMake( 5.0,
                                  5.0,
                           cell.frame.size.width - 10.0,
                           cell.frame.size.height - 5.0);
        segmentedControl.frame = frame;
        segmentedControl.autoresizingMask = (UIViewAutoresizingFlexibleWidth);
        
        [cell addSubview: segmentedControl];
        
    } else if (indexPath.row == 2) {
        NSArray *segmentTextContent = [NSArray arrayWithObjects: @"Option 1", @"Option 2", @"Option 3", nil];
        UISegmentedControl *segmentedControl = [[UISegmentedControl alloc] initWithItems:segmentTextContent];
        CGRect frame = CGRectMake( 5.0,
                                  5.0,
                           cell.frame.size.width - 10.0,
                           cell.frame.size.height - 5.0);
        segmentedControl.frame = frame;
        segmentedControl.autoresizingMask = (UIViewAutoresizingFlexibleWidth);
        
        segmentedControl.tintColor = [UIColor greenColor];
        
        [cell addSubview: segmentedControl];
    }
    
    return cell;
}

@end
