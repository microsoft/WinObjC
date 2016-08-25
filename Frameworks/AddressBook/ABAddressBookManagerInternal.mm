//******************************************************************************
//
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

#import "ABAddressBookManagerInternal.h"
#import "ABContactInternal.h"
#import "UWP/WindowsApplicationModelContacts.h"

@interface _ABAddressBookManager ()

@end

@implementation _ABAddressBookManager

- (id)init {
    self = [super init];
    if (self) {
        __block WACContactStore* result = nil;
        __block BOOL failed = YES;
        dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

        [WACContactManager requestStoreAsyncWithAccessType:WACContactStoreAccessTypeAllContactsReadOnly
            success:^(WACContactStore* success) {
                result = success;
                failed = NO;
                dispatch_semaphore_signal(semaphore);
            }
            failure:^(NSError* failure) {
                failed = YES;
                dispatch_semaphore_signal(semaphore);
            }];

        // Wait until async method completes.
        dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
        dispatch_release(semaphore);

        if (failed) {
            return nil;
        } else {
            self.contactStore = result;
        }
    }

    return self;
}

- (NSArray*)getListOfContacts {
    __block NSMutableArray* result = nil;
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

    [self.contactStore findContactsAsyncWithSuccess:^(NSArray* success) {
        result = [NSMutableArray arrayWithCapacity:[success count]];

        // Copy over the contacts wrapped in _ABContacts.
        for (int i = 0; i < [success count]; i++) {
            result[i] = [[_ABContact alloc] initWithContact:success[i]];
        }

        dispatch_semaphore_signal(semaphore);
    }
        failure:^(NSError* failure) {
            // In the failure case, result will be nil.
            dispatch_semaphore_signal(semaphore);
        }];

    // Wait until async method completes.
    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);
    dispatch_release(semaphore);

    return result;
}

@end