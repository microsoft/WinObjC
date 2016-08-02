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

#import "FunctionalTestHelpers.h"
#import <Foundation/Foundation.h>
#import <TestFramework.h>

#import <AssetsLibrary/ALAssetRepresentation.h>
#import <AssetsLibrary/AssetsLibrary.h>
#import <Starboard/SmartTypes.h>
#import <UWP/WindowsStorage.h>

TEST(AssetsLibrary, GetVideoAsset) {
    __block BOOL success = YES;
    __block StrongId<NSString> message = @"";
    __block unsigned int knownFileSize = 635445;
    __block StrongId<NSString> fileName = @"AssetsLibraryTestVideo.mp4";
    __block StrongId<NSURL> assetRepresentationUrl = nil;

    StrongId<NSURL> relativeURLToVideo = [NSURL URLWithString:@"assets-library://Pictures/AssetsLibraryTestVideo.mp4"];

    dispatch_group_t group = dispatch_group_create();
    dispatch_group_enter(group);

    ALAssetsLibrary* assetsLibrary = [[[ALAssetsLibrary alloc] init] autorelease];

    [assetsLibrary assetForURL:relativeURLToVideo
        resultBlock:^(ALAsset* asset) {
            if (asset == nil) {
                success = NO;
                message = @"FAILED: Invalid Asset.";
                dispatch_group_leave(group);
                return;
            }

            ALAssetRepresentation* _assetRepresentation = [asset defaultRepresentation];
            if (_assetRepresentation == nil) {
                success = NO;
                message = @"FAILED: Invalid Asset Representation.";
                dispatch_group_leave(group);
                return;
            }

            // Check this NSURL after assetForURL completes
            assetRepresentationUrl = [_assetRepresentation url];

            NSUInteger size = (NSUInteger)_assetRepresentation.size;
            if (size != knownFileSize) {
                success = NO;
                message = @"FAILED: Size of Asset Representation does not equal its file size.";
                dispatch_group_leave(group);
                return;
            }

            StrongId<NSMutableData> data = [NSMutableData dataWithLength:size];
            NSError* error = nil;
            NSUInteger length = [_assetRepresentation getBytes:(uint8_t*)[data mutableBytes] fromOffset:0 length:size error:&error];
            if (error != nil) {
                success = NO;
                message = [@"FAILED: Could not get bytes from asset representation - " stringByAppendingString:[error description]];
                dispatch_group_leave(group);
                return;
            }
            if (size != length) {
                success = NO;
                message = @"FAILED: Bytes received does not equal size of Asset.";
                dispatch_group_leave(group);
                return;
            }

            StrongId<NSString*> testFileFullPath = appendPathRelativeToFTModule([@"data" stringByAppendingPathComponent:fileName]);
            NSData* localFile = [[[NSData alloc] initWithContentsOfFile:testFileFullPath] autorelease];
            if (![data isEqualToData:localFile]) {
                success = NO;
                message = @"FAILED: Bytes recieved does not equal original file.";
                dispatch_group_leave(group);
                return;
            }

            dispatch_group_leave(group);
        }
        failureBlock:^(NSError* assetsLibError) {
            success = NO;
            message = [@"FAILED: Could not get asset - " stringByAppendingString:[assetsLibError description]];
            dispatch_group_leave(group);
        }];

    dispatch_group_wait(group, DISPATCH_TIME_FOREVER);
    dispatch_release(group);

    ASSERT_TRUE_MSG([assetRepresentationUrl isEqual:relativeURLToVideo], @"FAILED: NSURL of ALAssetRepresentation incorrect.");

    ASSERT_TRUE_MSG(success, message);
}
