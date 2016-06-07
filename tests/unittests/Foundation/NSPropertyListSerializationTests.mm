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

#include <TestFramework.h>
#import <Foundation/Foundation.h>

TEST(NSPropertyListSerialization, PropertyListForDate) {
    NSString* xml = @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" "
                    @"\"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\n<plist version=\"1.0\">\n<dict>\n<key>Date "
                    @"Modified</key><date>2014-12-15T19:48:38Z</date>\n</dict>\n</plist>";

    NSDictionary* plistDict;
    ASSERT_NO_THROW({
        plistDict =
            [NSPropertyListSerialization propertyListWithData:[xml dataUsingEncoding:NSUTF8StringEncoding] options:0 format:nil error:nil];
    });
    ASSERT_NE(nil, plistDict);

    NSDateFormatter* formatter = [[NSDateFormatter new] autorelease];
    ASSERT_NE(nil, formatter);
    [formatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ss'Z'"];
    NSDate* date = [formatter dateFromString:@"2014-12-15T19:48:38Z"];
    ASSERT_NE(nil, date);
    ASSERT_OBJCEQ(date, plistDict[@"Date Modified"]);

    ASSERT_NO_THROW({ plistDict = [xml propertyList]; });
    ASSERT_OBJCEQ(date, plistDict[@"Date Modified"]);
}