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

#import <QuartzCore/QuartzCore.h>
#import <QuartzCore/CALayer.h>
#import <UWP/WindowsApplicationModelStore.h>
#import <UWP/WindowsUIXamlControls.h>
#import "IAPViewController.h"

NSString* const kProduct1 = @"product1";
NSString* const kProduct2 = @"product2";

@implementation IAPViewController {
    // Section 0 of the table contains the directions.
    UITableViewCell* dirCell;
    // Section 1 of the table view contains the buttons.
    NSMutableArray* buttons;
    // Section 2 of the table view contains the output.
    UITableViewCell* outputCell;

    UITextView* outputTextView;
    WSProductListing* product1;
    WSProductListing* product2;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    self.title = @"In-App Purchases";
    [self tableView].allowsSelection = NO;

    dirCell = [self makeCellFromTextView:[self makeTextView:@"This scenario shows two different in-app products. In this example, the "
                                                            @"customer has already bought the first product but not the second."]];
    outputTextView = [self makeTextView:@"Downloading Products"];
    outputCell = [self makeCellFromTextView:outputTextView];

    self->buttons = [NSMutableArray arrayWithObjects:nil];

    // Load up the listings.
    WFUri* mockStoreURI = [WFUri makeUri:@"ms-appx:///in-app-purchase.xml"];

    // Open our XML file containing the product information for our mock store.
    [WSStorageFile getFileFromApplicationUriAsync:mockStoreURI
        success:^void(WSStorageFile* result) {

            [WSCurrentAppSimulator reloadSimulatorAsync:result].completed =
                ^void(RTObject<WFIAsyncAction>* asyncInfo, WFAsyncStatus asyncStatus) {

                    [WSCurrentAppSimulator
                        loadListingInformationAsyncWithSuccess:^void(WSListingInformation* info) {
                            dispatch_async(dispatch_get_main_queue(),
                            ^{
                                //This needs to be dispatched on the UI thread since it manipultes the UI.
                                product1 = [info.productListings objectForKey:@"product1"];
                                NSString* button1Title = [NSString stringWithFormat:@"Buy %@ (%@)", product1.name, product1.formattedPrice];
                                UITableViewCell* buttonCell1 = [self makeButton:button1Title selector:@selector(purchaseProduct1:)];
                                [self->buttons addObject:buttonCell1];

                                product2 = [info.productListings objectForKey:@"product2"];
                                NSString* button2Title = [NSString stringWithFormat:@"Buy %@ (%@)", product2.name, product2.formattedPrice];
                                UITableViewCell* buttonCell2 = [self makeButton:button2Title selector:@selector(purchaseProduct2:)];
                                [self->buttons addObject:buttonCell2];

                                UITableView* tableView = self.tableView;

                                NSArray* insertIndexPaths = [NSArray
                                arrayWithObjects:[NSIndexPath indexPathForRow:0 inSection:1], [NSIndexPath indexPathForRow:1 inSection:1], nil];
                                [tableView beginUpdates];
                                [tableView insertRowsAtIndexPaths:insertIndexPaths withRowAnimation:UITableViewRowAnimationRight];
                                [tableView endUpdates];
                                outputTextView.text = @"Purchase something";
                            });
                        }
                        failure:^(NSError* err) {
                            NSLog(@"Hit error %@ when attempting to load listing information!", err);
                        }];
                };
        }
        failure:^(NSError* err) {
            NSLog(@"Hit error %@ when attempting to open mock store XML data!", err);
        }];
}

- (NSInteger)numberOfSectionsInTableView:(UITableView*)tableView {
    return 3;
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    if (section == 1) {
        return [self->buttons count];
    } else {
        return 1;
    }
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath {
    return 50;
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    if (indexPath.section == 0) {
        return dirCell;
    } else if (indexPath.section == 1) {
        return [self->buttons objectAtIndex:indexPath.row];
    } else {
        return outputCell;
    }
}

- (UITableViewCell*)makeButton:(NSString*)title selector:(SEL)selector {
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.backgroundColor = [UIColor whiteColor];
    cell.textLabel.textColor = [UIColor blackColor];

    UIButton* button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [button setTitle:title forState:UIControlStateNormal];
    [button addTarget:self action:selector forControlEvents:UIControlEventTouchUpInside];
    button.frame = CGRectMake(5.0f, 5.0f, 400.0f, cell.frame.size.height - 5.0f);
    button.layer.cornerRadius = 5.0f;
    [cell addSubview:button];

    return cell;
}

- (UITextView*)makeTextView:(NSString*)text {
    UITextView* textView = [[UITextView alloc] initWithFrame:CGRectMake(0, 0, 300, 300)];
    textView.textColor = [UIColor blackColor];
    textView.font = [UIFont fontWithName:@"Arial" size:18.0];
    textView.backgroundColor = [UIColor whiteColor];
    textView.text = text;
    textView.returnKeyType = UIReturnKeyDefault;
    textView.keyboardType = UIKeyboardTypeDefault;
    textView.scrollEnabled = YES;
    textView.editable = NO;
    textView.autoresizingMask = UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight;
    return textView;
}

- (UITableViewCell*)makeCellFromTextView:(UITextView*)textView {
    UITableViewCell* cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    cell.backgroundColor = [UIColor whiteColor];
    cell.textLabel.textColor = [UIColor blackColor];
    [cell addSubview:textView];
    return cell;
}

- (void)buyProduct:(NSString*)productId name:(NSString*)name {
    WSLicenseInformation* licenseInformation = [WSCurrentAppSimulator licenseInformation];
    NSDictionary* productLicenses = [licenseInformation productLicenses];
    WSProductLicense* license = productLicenses[productId];

    if (!license.isActive) {
        outputTextView.text = [NSString stringWithFormat:@"Buying %@", name];
        [WSCurrentAppSimulator requestProductPurchaseAsync:productId
            includeReceipt:TRUE
            success:^void(NSString* result) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    // validate the purchase.
                    NSDictionary* productLicenses = [[WSCurrentAppSimulator licenseInformation] productLicenses];
                    WSProductLicense* license = productLicenses[productId];
                    if (license.isActive) {
                        outputTextView.text = [NSString stringWithFormat : @"You bought %@", name];
                    }
                    else {
                        outputTextView.text = [NSString stringWithFormat : @"%@ was not bought", name];
                    }
                });
            }
            failure:^(NSError* err) {
                dispatch_async(dispatch_get_main_queue(), ^{
                    outputTextView.text = [NSString stringWithFormat:@"Failed to buy: %@\nError: %@", name, err];
                });
            }];
    } else {
        outputTextView.text = [NSString stringWithFormat:@"You already own %@", name];
    }
}

- (void)purchaseProduct1:(UIButton*)button {
    [self buyProduct:product1.productId name:product1.name];
}

- (void)purchaseProduct2:(UIButton*)button {
    [self buyProduct:product2.productId name:product2.name];
}

@end
