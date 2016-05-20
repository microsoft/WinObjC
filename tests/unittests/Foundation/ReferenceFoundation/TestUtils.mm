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

BOOL ensureFiles(NSArray* fileNames) {
    BOOL result = YES;
    NSFileManager* fm = [NSFileManager defaultManager];
    for (NSString* name in fileNames) {
        if ([fm fileExistsAtPath:name]) {
            continue;
        }

        if ([name hasSuffix:@"/"]) {
            try {
                [fm createDirectoryAtPath:name withIntermediateDirectories:YES attributes:nil error:nullptr];
            } catch (...) {
                return NO;
            }
        } else {
            BOOL isDir = NO;
            NSString* dir = [name stringByDeletingLastPathComponent];
            if (![fm fileExistsAtPath:dir isDirectory:&isDir]) {
                try {
                    [fm createDirectoryAtPath:dir withIntermediateDirectories:YES attributes:nil error:nullptr];
                } catch (...) {
                    return NO;
                }
            } else if (!isDir) {
                return NO;
            }

            result = result && [fm createFileAtPath:name contents:nil attributes:nil];
        }
    }
    return result;
}

NSBundle* testBundle() {
    return [NSBundle mainBundle];
}