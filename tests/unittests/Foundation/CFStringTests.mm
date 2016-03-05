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
#include <CoreFoundation/CFString.h>

TEST(Foundation, CFStrings_ConvertEncodingToIANACharSetName) {
    CFStringRef charSetName;

    // Simple test to check a valid character set name is returned for kCFStringEncodingASCII.
    charSetName = CFStringConvertEncodingToIANACharSetName(kCFStringEncodingASCII);
    ASSERT_OBJCEQ_MSG((NSString*)charSetName,
                      @"ANSI_X3.4-1968",
                      "Expected character set name does not match for kCFStringEncodingASCII encoding!");

    // Simple test to check "ANSI_X3.4-1968" character set name is returned for unsupported encoding.
    charSetName = CFStringConvertEncodingToIANACharSetName(kCFStringEncodingUTF16LE);
    ASSERT_OBJCEQ_MSG((NSString*)charSetName,
                      @"ANSI_X3.4-1968",
                      "Expected character set name does not match for kCFStringEncodingASCII encoding!");
}

TEST(Foundation, CFStrings_ConvertIANACharSetNameToEncoding) {
    CFStringEncoding encoding;

    // Simple test to check kCFStringEncodingASCII encoding is returned for the specified supported character set name.
    encoding = CFStringConvertIANACharSetNameToEncoding(static_cast<CFStringRef>(@"ANSI_X3.4-1968"));
    ASSERT_TRUE_MSG((encoding == kCFStringEncodingASCII),
                    "Expected kCFStringEncodingASCII encoding for character set name ANSI_X3.4-1968!");

    // Simple test to check kCFStringEncodingASCII encoding is returned for the specified unsupported character set name.
    encoding = CFStringConvertIANACharSetNameToEncoding(static_cast<CFStringRef>(@"ABC_XYZ_123"));
    ASSERT_TRUE_MSG((encoding == kCFStringEncodingASCII), "Expected kCFStringEncodingASCII encoding for unsupported character set name!");
}