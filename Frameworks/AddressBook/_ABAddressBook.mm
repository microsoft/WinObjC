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

#import "_ABAddressBook.h"
#import "UWP/WindowsApplicationModelContacts.h"

@interface _ABAddressBook ()

@end

@implementation _ABAddressBook

- (id)init {
    self = [super init];
    if (self) {
        __block BOOL completed = NO;
        __block WACContactStore* result = nil;

        [WACContactManager requestStoreAsyncWithAccessType:WACContactStoreAccessTypeAllContactsReadOnly
            success:^(WACContactStore* success) {
                completed = YES;
                result = success;
            }
            failure:^(NSError* failure) {
                completed = YES;
            }];

        // Wait until async method completes.
        while (!completed) {
            [[NSRunLoop currentRunLoop] runMode:NSDefaultRunLoopMode beforeDate:[NSDate distantFuture]];
        }

        self.contactStore = result;
    }

    return self;
}

@end