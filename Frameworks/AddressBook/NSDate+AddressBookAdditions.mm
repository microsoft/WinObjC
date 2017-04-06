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

#import <Foundation/Foundation.h>
#import "NSDate+AddressBookAdditions.h"

using namespace winrt::Windows::ApplicationModel::Contacts;
namespace WF = winrt::Windows::Foundation;

@implementation NSDate (AddressBookAdditions)

+ (NSDate*)dateWithContactDate:(const ContactDate&)date {
    NSCalendar* calendar = [NSCalendar currentCalendar];
    NSDateComponents* dateComponents = [[NSDateComponents alloc] init];

    // Grab the numerical values of the day/month/year,
    // and create an NSDate to match the same day as the
    // given NSDate. Default month of January and year
    // of 2004 are per the guidelines provided from
    // Windows.ApplicationModel.Contacts.ContactDate
    WF::IReference<unsigned int> day = date.Day();
    WF::IReference<unsigned int> month = date.Month();
    WF::IReference<int> year = date.Year();

    dateComponents.day = day.Value();
    dateComponents.month = month ? month.Value() : 1;
    dateComponents.year = year ? year.Value() : 2004;
    NSDate* resultDate = [calendar dateFromComponents:dateComponents];
    return resultDate;
}

@end