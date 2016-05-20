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

TEST(CFStrings, ConvertEncodingToIANACharSetName) {
    CFStringRef charSetName;

    // Simple test to check a valid character set name is returned for kCFStringEncodingASCII.
    charSetName = CFStringConvertEncodingToIANACharSetName(kCFStringEncodingASCII);
    ASSERT_OBJCEQ_MSG((NSString*)charSetName,
                      @"us-ascii",
                      "Expected character set name does not match for kCFStringEncodingASCII encoding!");

    // Simple test to check "utf-16le" character set name is returned for kCFStringEncodingUTF16LE
    charSetName = CFStringConvertEncodingToIANACharSetName(kCFStringEncodingUTF16LE);
    ASSERT_OBJCEQ_MSG((NSString*)charSetName,
                      @"utf-16le",
                      "Expected character set name does not match for kCFStringEncodingUTF16LE encoding!");
}

TEST(CFStrings, ConvertIANACharSetNameToEncoding) {
    CFStringEncoding encoding;

    // Simple test to check kCFStringEncodingASCII encoding is returned for the specified supported character set name.
    encoding = CFStringConvertIANACharSetNameToEncoding(static_cast<CFStringRef>(@"us-ascii"));
    ASSERT_EQ_MSG(encoding, kCFStringEncodingASCII, "Expected kCFStringEncodingASCII encoding for character set name us-ascii!");

    // Simple test to check kCFStringEncodingInvalidId encoding is returned for the specified unsupported character set name.
    encoding = CFStringConvertIANACharSetNameToEncoding(static_cast<CFStringRef>(@"ABC_XYZ_123"));
    ASSERT_EQ_MSG(encoding, kCFStringEncodingInvalidId, "Expected kCFStringEncodingASCII encoding for unsupported character set name!");
}