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

#import "NSDate+AddressBookAdditions.h"
#import "UWP/WindowsApplicationModelContacts.h"

@implementation NSDate (AddressBookAdditions)

+ (NSDate*)dateWithWACContactDate:(WACContactDate*)date {
    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* dateComponents = [[NSDateComponents alloc] init];

    // Grab the numerical values of the day/month/year,
    // and create an NSDate to match the same day as the
    // given NSDate. Default month of January and year
    // of 2004 are per the guidelines provided from
    // Windows.ApplicationModel.Contacts.ContactDate
    dateComponents.day = [date.day integerValue];
    dateComponents.month = date.month ? [date.month integerValue] : 1;
    dateComponents.year = date.year ? [date.year integerValue] : 2004;
    NSDate* resultDate = [calendar dateFromComponents:dateComponents];
    return resultDate;
}

@end