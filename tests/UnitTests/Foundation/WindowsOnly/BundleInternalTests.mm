//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <TestFramework.h>
#import <Foundation/Foundation.h>
#import <objc/encoding.h>

static NSString* _bundleName = @"MyBundle.bundle";

class NSBundleLocalization : public ::testing::Test {
public:
    explicit NSBundleLocalization() : ::testing::Test() {
    }

protected:
    virtual void SetUp() {
        NSString* _subDirectory = @"en.lproj";
        NSString* localizationResourceName = @"Localizable.strings";
        // Create a unique test directory
        NSString* tempDir = [[@"./tmp_TestFoundation" stringByAppendingPathComponent:[NSUUID UUID].UUIDString] stringByAppendingPathComponent:@"/"];
        NSString* bundlePath = [tempDir stringByAppendingPathComponent:_bundleName];
        NSError* error = nil;

        NSString* localizationPath = [NSString stringWithFormat:@"%@/%@", bundlePath, _subDirectory];
        [[NSFileManager defaultManager] createDirectoryAtPath:localizationPath
                                  withIntermediateDirectories:true
                                                   attributes:nil
                                                        error:&error];
        ASSERT_EQ(nil, error);

        // Full path to the file name
        NSString* filepath = [NSString stringWithFormat:@"%@/%@", localizationPath, localizationResourceName];
        [[NSFileManager defaultManager] createFileAtPath:filepath contents:nil attributes:nil];

        // As translated by Bing translate using unicode escapes to properly write to file
        NSString* localization = @"\"Hello World\" = \"Hallo Welt\";\n\"Coding\" = \"\u7f16\u7801\";";
        [localization writeToFile:filepath atomically:YES encoding:NSUnicodeStringEncoding error:&error];

        _playground = tempDir;
    }

    virtual void TearDown() {
        NSError* error;
        [[NSFileManager defaultManager] removeItemAtPath:_playground error:&error];
        if (error) {
            // Oh well, temporary directories in taef are cleaned up automatically anyway
        }
    }

    StrongId<NSString> _playground;
};

TEST_F(NSBundleLocalization, LocalizedString) {
    if (!_playground) {
        ASSERT_TRUE_MSG(false, @"Unable to create bundle resources");
    }

    NSBundle* bundle = [NSBundle bundleWithPath:[_playground stringByAppendingPathComponent:_bundleName]];
    ASSERT_OBJCNE(bundle, nil);

    NSString* helloWorld = @"Hello World";
    NSString* coding = @"Coding";
    NSString* helloWorldInGerman = NSLocalizedStringFromTableInBundle(helloWorld, nil, bundle, nil);
    NSString* codingInChinese = NSLocalizedStringFromTableInBundle(coding, nil, bundle, nil);
    ASSERT_OBJCEQ(@"Hallo Welt", helloWorldInGerman);
    ASSERT_OBJCEQ(@"编码", codingInChinese);
}