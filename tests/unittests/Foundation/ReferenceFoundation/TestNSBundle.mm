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
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//

#import <Foundation/Foundation.h>
#import <TestFramework.h>
#import <LoggingNative.h>

TEST(NSBundle, Paths) {
    auto bundle = [NSBundle mainBundle];

    // bundlePath
    ASSERT_GE(bundle.bundlePath.length, 0);
    ASSERT_OBJCEQ(bundle.bundleURL.path, bundle.bundlePath);
    auto path = bundle.bundlePath;

    // etc
    // #if os(OSX)
    //     ASSERT_OBJCEQ(@"\(path)/Contents/Resources", bundle.resourcePath);
    //     ASSERT_OBJCEQ(@"\(path)/Contents/MacOS/TestFoundation", bundle.executablePath);
    //     ASSERT_OBJCEQ(@"\(path)/Contents/Frameworks", bundle.privateFrameworksPath);
    //     ASSERT_OBJCEQ(@"\(path)/Contents/SharedFrameworks", bundle.sharedFrameworksPath);
    //     ASSERT_OBJCEQ(@"\(path)/Contents/SharedSupport", bundle.sharedSupportPath);
    // #endif

    ASSERT_OBJCEQ([bundle pathForAuxiliaryExecutable:@"no_such_file"], nil);
    ASSERT_OBJCEQ(bundle.appStoreReceiptURL, nil);
}

TEST(NSBundle, Resources) {
    auto bundle = [NSBundle mainBundle];

    // bad resources
    ASSERT_OBJCEQ([bundle URLForResource:nil withExtension:nil subdirectory:nil], nil);
    ASSERT_OBJCEQ([bundle URLForResource:@"" withExtension:@"" subdirectory:nil], nil);
    ASSERT_OBJCEQ([bundle URLForResource:@"no_such_file" withExtension:nil subdirectory:nil], nil);

    // test file
    auto testPlist = [bundle URLForResource:@"Test" withExtension:@"plist"];
    ASSERT_OBJCNE(testPlist, nil);
    ASSERT_OBJCEQ(@"Test.plist", testPlist.lastPathComponent);
    ASSERT_TRUE([[NSFileManager defaultManager] fileExistsAtPath:testPlist.path]);

    // aliases, paths
    ASSERT_OBJCEQ(testPlist.path, [bundle URLForResource:@"Test" withExtension:@"plist" subdirectory:nil].path);
    ASSERT_OBJCEQ(testPlist.path, [bundle pathForResource:@"Test" ofType:@"plist"]);
    ASSERT_OBJCEQ(testPlist.path, [bundle pathForResource:@"Test" ofType:@"plist" inDirectory:nil]);
}

TEST(NSBundle, InfoPlist) {
    auto bundle = [NSBundle mainBundle];

    // bundleIdentifier
    ASSERT_OBJCEQ(@"org.swift.TestFoundation", bundle.bundleIdentifier);

    // infoDictionary
    auto info = bundle.infoDictionary;
    ASSERT_OBJCNE(info, nil);
    ASSERT_OBJCEQ(@"org.swift.TestFoundation", info[@"CFBundleIdentifier"]);
    ASSERT_OBJCEQ(@"TestFoundation", info[@"CFBundleName"]);

    // localizedInfoDictionary
    ASSERT_OBJCEQ(bundle.localizedInfoDictionary, nil); // FIXME: Add a localized Info.plist for testing
}

TEST(NSBundle, Localizations) {
    auto bundle = [NSBundle mainBundle];

    ASSERT_OBJCEQ(@[ @"en" ], bundle.localizations);
    ASSERT_OBJCEQ(@[ @"en" ], bundle.preferredLocalizations);
    auto preferredLocalizationsFromArray = [NSBundle preferredLocalizationsFromArray:@[ @"en", @"pl", @"es" ]];
    ASSERT_OBJCEQ(@[ @"en" ], preferredLocalizationsFromArray);
}

static NSString* _bundleName = @"MyBundle.bundle";
static NSString* _subDirectory = @"Sources";
static NSString* _main = @"main";
static NSString* _type = @"swift";

static NSString* _setupPlayground() {
    NSArray* _bundleResourceNames = @[ @"hello.world", @"goodbye.world", @"swift.org" ];

    // Make sure the directory is uniquely named
    // WINOBJC: test environment is different, '/tmp/' is not a top-level directory
    // NSString* tempDir =
    //     [[@"/tmp/TestFoundation_Playground_" stringByAppendingString:[NSUUID UUID].UUIDString] stringByAppendingString:@"/"];
    NSString* tempDir =
        [[@"./tmp/TestFoundation_Playground_" stringByAppendingString:[NSUUID UUID].UUIDString] stringByAppendingString:@"/"];

    NSError* error = nil;
    [[NSFileManager defaultManager] createDirectoryAtPath:tempDir withIntermediateDirectories:false attributes:nil error:&error];
    if (error) {
        TraceError(L"TestNSBundle", L"%hs", [[error description] UTF8String]);
        return nil;
    }

    // Make a flat bundle in the playground
    auto bundlePath = [tempDir stringByAppendingString:_bundleName];
    [[NSFileManager defaultManager] createDirectoryAtPath:bundlePath withIntermediateDirectories:false attributes:nil error:&error];
    if (error) {
        TraceError(L"TestNSBundle", L"%hs", [[error description] UTF8String]);
        return nil;
    }

    // Put some resources in the bundle
    for (NSString* n in _bundleResourceNames) {
        [[NSFileManager defaultManager] createFileAtPath:[[bundlePath stringByAppendingString:@"/"] stringByAppendingString:n]
                                                contents:nil
                                              attributes:nil];
    }
    // Add a resource into a subdirectory
    auto subDirPath = [[bundlePath stringByAppendingString:@"/"] stringByAppendingString:_subDirectory];
    [[NSFileManager defaultManager] createDirectoryAtPath:subDirPath withIntermediateDirectories:false attributes:nil error:&error];
    if (error) {
        TraceError(L"TestNSBundle", L"%hs", [[error description] UTF8String]);
        return nil;
    }
    [[NSFileManager defaultManager] createFileAtPath:[@[ subDirPath, @"/", _main, @".", _type ] componentsJoinedByString:@""]
                                            contents:nil
                                          attributes:nil];

    return tempDir;
}

static void _cleanupPlayground(NSString* location) {
    NSError* error;
    [[NSFileManager defaultManager] removeItemAtPath:location error:&error];
    if (error) {
        // Oh well
    }
}

TEST(NSBundle, URLsForResourcesWithExtension) {
    NSString* playground = _setupPlayground();

    if (!playground) {
        ASSERT_TRUE_MSG(false, @"Unable to create playground");
        return;
    }

    NSBundle* bundle = [NSBundle bundleWithPath:[playground stringByAppendingString:_bundleName]];
    ASSERT_OBJCNE(bundle, nil);

    auto worldResources = [bundle URLsForResourcesWithExtension:@"world" subdirectory:nil];
    ASSERT_OBJCNE(worldResources, nil);
    ASSERT_EQ(worldResources.count, 2);

    auto path = [bundle pathForResource:_main ofType:_type inDirectory:_subDirectory];
    ASSERT_OBJCNE(path, nil);

    _cleanupPlayground(playground);
}
