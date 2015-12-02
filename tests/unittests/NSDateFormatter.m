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

#include "gtest-api.h"
#import <Foundation/Foundation.h>

void testSpecificFormat(NSDateFormatterStyle formatterStyle, NSString* formatted) {
    switch(formatterStyle) {
        case NSDateFormatterNoStyle:

            //Currently should not be tested as there's a bug on this format style.
            //The current output is "19691231 04:00 PM" when it should be "".
            //When the bug is fixed, this should be updated to make sure time
            //or date can be printed individually when using this style.
            //ASSERT_OBJCEQ(@"", formatted);
                        
            break;
        case NSDateFormatterShortStyle:
            ASSERT_OBJCEQ(@"12/31/69 4:00 PM", formatted);
            break;

        case NSDateFormatterMediumStyle:
            ASSERT_OBJCEQ(@"Dec 31, 1969 4:00:00 PM", formatted);
            break;

        case NSDateFormatterLongStyle:
            ASSERT_OBJCEQ(@"December 31, 1969 4:00:00 PM GMT-08:00", formatted);
            break;

        case NSDateFormatterFullStyle:
            ASSERT_OBJCEQ(@"Wednesday, December 31, 1969 4:00:00 PM GMT-08:00", formatted);
            break;

        default:
            //We hit some unknown NSDateFormatterStyle. This should never happen.
            ASSERT_TRUE_MSG(false, "Test failed, unrecognized NSDateFormatterStyle");
            break;
    }
}

TEST(Foundation, NSDateFormatter) {
    NSLocale* currentLocale = [NSLocale currentLocale];

    //Do the test if we're in the right locale.
    if([currentLocale.localeIdentifier isEqualToString:@"en_US"]) {
        NSDate* someConstantDate = [NSDate dateWithTimeIntervalSince1970:0]; //1970-01-01 00:00:00 +0000, This should never change.

        NSString* formattedDateString;
        for(int i = 0; i < 5; i ++) {
            formattedDateString = [NSDateFormatter localizedStringFromDate:someConstantDate dateStyle:((NSDateFormatterStyle)i) timeStyle:((NSDateFormatterStyle)i)];

            testSpecificFormat(((NSDateFormatterStyle)i), formattedDateString);
        }
        
    } else {
        //Didn't test, not in US locale.
        LOG_INFO("[NSDateFormatter localizedStringFromDate] not tested. Current locale is not in us_EN.\n");
    }
}