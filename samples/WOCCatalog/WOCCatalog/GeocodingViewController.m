//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import "GeocodingViewController.h"
#include <mach/mach.h>
#include <CoreLocation/CoreLocation.h>

@interface GeocodingViewController ()
@property integer_t user_time_sec;
@property integer_t user_time_microsec;
@property integer_t system_time_sec;
@property integer_t system_time_microsec;
@property vm_size_t virtual_size;
@property vm_size_t resident_size;

@property CLLocation* location1;
@property CLLocation* location2;
@property NSString* locationName1;
@property NSString* locationName2;

@property NSString* rowLabel1;
@property NSString* rowLabelDetail1;
@property NSString* rowLabel2;
@property NSString* rowLabelDetail2;
@property NSString* rowLabel3;
@property NSString* rowLabelDetail3;
@property NSString* rowLabel4;
@property NSString* rowLabelDetail4;
@end

@implementation GeocodingViewController

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

- (void)startGeocodingCalls {
    self.location1 = [[CLLocation alloc] initWithLatitude:47.6062 longitude:-122.3321];
    self.location2 = [[CLLocation alloc] initWithLatitude:250 longitude:500];
    self.locationName1 = @"Moscow, Russia";
    self.locationName2 = @"Hollywood Walk of Fame";

    CLGeocoder* geocoder1 = [[CLGeocoder alloc] init];

    [geocoder1 reverseGeocodeLocation:self.location1
                    completionHandler:^(NSArray* placemarks, NSError* error) {
                        if (error) {
                            self.rowLabel1 = [NSString stringWithFormat:@"Error: %@", error];
                            self.rowLabelDetail1 = @"Error";
                        }

                        if ([placemarks count] > 0) {
                            CLPlacemark* firstPlacemark = [placemarks objectAtIndex:0];
                            self.rowLabel1 = @"Input: Lat: 47.6062, Long: -122.3321";
                            self.rowLabelDetail1 = [NSString stringWithFormat:@"Out: %@, %@, %@, %@",
                                                                              [firstPlacemark name],
                                                                              [firstPlacemark locality],
                                                                              [firstPlacemark administrativeArea],
                                                                              [firstPlacemark country]];
                        }

                        [self.tableView reloadData];
                    }];

    CLGeocoder* geocoder2 = [[CLGeocoder alloc] init];

    [geocoder2 reverseGeocodeLocation:self.location2
                    completionHandler:^(NSArray* placemarks, NSError* error) {
                        if (error) {
                            self.rowLabel2 = [NSString stringWithFormat:@"Error: %@", error];
                            self.rowLabelDetail2 = @"Error (Expect error in this row)";
                        }

                        if ([placemarks count] > 0) {
                            CLPlacemark* firstPlacemark = [placemarks objectAtIndex:0];
                            self.rowLabel2 = @"Input: Lat: 250, Long: 500";
                            self.rowLabelDetail2 = [NSString stringWithFormat:@"Out: %@, %@, %@, %@",
                                                                              [firstPlacemark name],
                                                                              [firstPlacemark locality],
                                                                              [firstPlacemark administrativeArea],
                                                                              [firstPlacemark country]];
                        }

                        [self.tableView reloadData];
                    }];

    CLGeocoder* geocoder3 = [[CLGeocoder alloc] init];

    [geocoder3 geocodeAddressString:self.locationName1
                  completionHandler:^(NSArray* placemarks, NSError* error) {
                      if (error) {
                          self.rowLabel3 = [NSString stringWithFormat:@"Error: %@", error];
                          self.rowLabelDetail3 = @"Error";
                      }

                      if ([placemarks count] > 0) {
                          CLPlacemark* firstPlacemark = [placemarks objectAtIndex:0];
                          self.rowLabel3 = @"Input: Moscow, Russia";
                          self.rowLabelDetail3 =
                              [NSString stringWithFormat:@"Out: %@ %@", [firstPlacemark name], [firstPlacemark location]];
                      }

                      [self.tableView reloadData];
                  }];

    CLGeocoder* geocoder4 = [[CLGeocoder alloc] init];
    CLLocationCoordinate2D coordinatesLosAngeles = CLLocationCoordinate2DMake(34.0522, -118.2437);
    CLCircularRegion* region1 = [[CLCircularRegion alloc] initWithCenter:coordinatesLosAngeles radius:1 identifier:@"Los Angeles"];

    [geocoder4 geocodeAddressString:self.locationName2
                           inRegion:region1
                  completionHandler:^(NSArray* placemarks, NSError* error) {
                      if (error) {
                          self.rowLabel4 = [NSString stringWithFormat:@"Error: %@", error];
                          self.rowLabelDetail4 = @"Error";
                      }

                      if ([placemarks count] > 0) {
                          CLPlacemark* firstPlacemark = [placemarks objectAtIndex:0];
                          self.rowLabel4 = @"Input: Hollywood Walk of Fame";
                          self.rowLabelDetail4 =
                              [NSString stringWithFormat:@"Out: %@ %@", [firstPlacemark name], [firstPlacemark location]];
                      }

                      [self.tableView reloadData];
                  }];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)viewWillAppear:(BOOL)animated {
    [self updateTaskInfo];
    [self startGeocodingCalls];
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
        cell.textLabel.text = self.rowLabel1;
        cell.detailTextLabel.text = self.rowLabelDetail1;
    } else if (indexPath.row == 1) {
        cell.textLabel.text = self.rowLabel2;
        cell.detailTextLabel.text = self.rowLabelDetail2;
    } else if (indexPath.row == 2) {
        cell.textLabel.text = self.rowLabel3;
        cell.detailTextLabel.text = self.rowLabelDetail3;
    } else if (indexPath.row == 3) {
        cell.textLabel.text = self.rowLabel4;
        cell.detailTextLabel.text = self.rowLabelDetail4;
    }
    return cell;
}

@end
