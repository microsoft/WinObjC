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

#import "FunctionalTestHelpers.h"
#include "UIKit/UIApplication.h"
#import <Starboard/SmartTypes.h>
#import <UWP/WindowsApplicationModel.h>

// Prevents UIApplication state from carrying over between functional tests
void FunctionalTestCleanupUIApplication() {
    [[UIApplication sharedApplication] _destroy];
}

// Gets the path to the app installation location
// Returned path is formatted with double backslashes
NSString* getModulePath() {
    return [[[WAPackage current] installedLocation] path];
}

// Gets path to functional test module and appends path component
// Returned path is formatted with double backslashes
NSString* appendPathRelativeToFTModule(NSString* pathAppendage) {
    StrongId<NSString> refPath = getModulePath();
    refPath = [refPath stringByAppendingPathComponent:pathAppendage];
    return [refPath stringByReplacingOccurrencesOfString:@"/" withString:@"\\"];
}
