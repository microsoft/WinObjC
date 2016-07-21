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

#include <TestFramework.h>
#import <UIKit/UIImage.h>

static NSString* findImage(char* imageName) {
    char fullPath[_MAX_PATH];
    GetModuleFileNameA(NULL, fullPath, _MAX_PATH);
    char* executablePath = strrchr(fullPath, '\\');
    const char* relativePathToPhoto = imageName;
    strncpy(executablePath, relativePathToPhoto, strlen(relativePathToPhoto) + 1);
    return [NSString stringWithCString:fullPath];
}

TEST(UIImage, UIImageJPEGRepresentation) {
    UIImage* originalImage = [UIImage imageNamed:findImage("\\rightOrientationPhoto.jpg")];
    NSData* data = UIImageJPEGRepresentation(originalImage, 0.5);
    ASSERT_TRUE_MSG(data != nil, "Failed: Nil data returned.");
    UIImage* imageFromData = [UIImage imageWithData:data];
    ASSERT_TRUE_MSG(imageFromData != nil, "Failed: Can not init an UIImage with returned data.");
}

TEST(UIImage, jpeg_find_orientation) {
    UIImage* image = [UIImage imageNamed:findImage("\\rightOrientationPhoto.jpg")];
    ASSERT_TRUE_MSG((UIImageOrientation)[image imageOrientation] == UIImageOrientationRight, "Failed: Orientation got %d, should be 6.", [image imageOrientation]);
}

TEST(UIImage, CacheImage) {
    UIImage* image = [UIImage imageNamed:findImage("\\rightOrientationPhoto.jpg")];
    UIImage* image2 = [UIImage imageNamed:findImage("\\rightOrientationPhoto.jpg")];
    ASSERT_TRUE_MSG([image imageOrientation] == [image2 imageOrientation], "Failed: Different orientations in image and image2.");
	ASSERT_TRUE_MSG([image scale] == [image2 scale], "Failed: Different scales in image and image2.");
	ASSERT_TRUE_MSG([image CGImage] == [image2 CGImage], "Failed: Different CGImage in image and image2.");
}