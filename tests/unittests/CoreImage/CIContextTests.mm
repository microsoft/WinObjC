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

#import <UIKit/UIKit.h>
#import <CoreImage/CoreImage.h>
#import "Starboard/SmartTypes.h"
#import "CALayerInternal.h"
#import "../UIKit/NullCompositor.h"

#include <windows.h>

TEST(CoreImage, CGImageFromRect) {
    SetCACompositor(new NullCompositor);
    CIContext* context = [CIContext contextWithOptions:nil];
    ASSERT_TRUE_MSG(context != nil, "Failed: CIContext is nil.");

    char fullPath[_MAX_PATH];
    GetModuleFileNameA(NULL, fullPath, _MAX_PATH);
    char* executablePath = strrchr(fullPath, '\\');
    const char* relativePathToPhoto = "\\Photo2.jpg";
    strncpy(executablePath, relativePathToPhoto, strlen(relativePathToPhoto) + 1);
    UIImage* photo = [UIImage imageNamed:[NSString stringWithCString:fullPath]];
    CIImage* ciImage = [CIImage imageWithCGImage:photo.CGImage];
    CGImageRef cgImage = [context createCGImage:ciImage fromRect:CGRectMake(300, 600, 200, 200)];
    photo = [UIImage imageWithCGImage:cgImage];

    const char* relativePathToCroppedPhoto = "\\CroppedPhoto2.jpg";
    strncpy(executablePath, relativePathToCroppedPhoto, strlen(relativePathToCroppedPhoto) + 1);
    UIImage* croppedPhoto = [UIImage imageNamed:[NSString stringWithCString:fullPath]];

    NSData* photoData = UIImagePNGRepresentation(photo);
    NSData* croppedPhotoData = UIImagePNGRepresentation(croppedPhoto);

    ASSERT_TRUE_MSG([photoData isEqualToData:croppedPhotoData], "Failed: Cropped image does not match reference image");
}