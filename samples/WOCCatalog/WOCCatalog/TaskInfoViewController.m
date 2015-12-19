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

#import "TaskInfoViewController.h"
#include <mach/mach.h>

@interface TaskInfoViewController ()
@property integer_t user_time_sec;
@property integer_t user_time_microsec;
@property integer_t system_time_sec;
@property integer_t system_time_microsec;
@property vm_size_t virtual_size;
@property vm_size_t resident_size;
@end

@implementation TaskInfoViewController

- (void)updateTaskInfo {
    struct task_basic_info basic_info;
    mach_msg_type_number_t size = sizeof(basic_info) / sizeof(integer_t);

    task_info(mach_task_self(), TASK_BASIC_INFO, (task_info_t)(&basic_info), &size);
    self.virtual_size = basic_info.virtual_size;
    self.resident_size = basic_info.resident_size;

    struct task_thread_times_info thread_times_info;
    size = sizeof(thread_times_info) / sizeof(integer_t);

    task_info(mach_task_self(), TASK_THREAD_TIMES_INFO, (task_info_t)(&thread_times_info), &size);
    self.user_time_sec = thread_times_info.user_time.seconds;
    self.user_time_microsec = thread_times_info.user_time.microseconds;
    self.system_time_sec = thread_times_info.system_time.seconds;
    self.system_time_microsec = thread_times_info.system_time.microseconds;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)viewWillAppear:(BOOL)animated {
    [self updateTaskInfo];
    [self.tableView reloadData];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return 4;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"TableCell"];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleSubtitle reuseIdentifier:@"MenuCell"];
    }

    if (indexPath.row == 0) {
        cell.textLabel.text = @"User time";
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%ds %dms", self.user_time_sec, self.user_time_microsec / 1000];
    } else if (indexPath.row == 1) {
        cell.textLabel.text = @"System time";
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%ds %dms", self.system_time_sec, self.system_time_microsec / 1000];
    } else if (indexPath.row == 2) {
        cell.textLabel.text = @"Virtual Memory";
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%luMB", self.virtual_size / (1024 * 1024)];
    } else if (indexPath.row == 3) {
        cell.textLabel.text = @"Resident Memory";
        cell.detailTextLabel.text = [NSString stringWithFormat:@"%luMB", self.resident_size / (1024 * 1024)];
    }
    return cell;
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
