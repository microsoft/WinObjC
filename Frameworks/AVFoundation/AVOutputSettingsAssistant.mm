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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

NSString* const AVOutputSettingsPreset640x480 = @"AVOutputSettingsPreset640x480";
NSString* const AVOutputSettingsPreset960x540 = @"AVOutputSettingsPreset960x540";
NSString* const AVOutputSettingsPreset1280x720 = @"AVOutputSettingsPreset1280x720";
NSString* const AVOutputSettingsPreset1920x1080 = @"AVOutputSettingsPreset1920x1080";

@implementation AVOutputSettingsAssistant
/**
@Status Stub
@Notes
*/
+ (instancetype)outputSettingsAssistantWithPreset:(NSString*)presetIdentifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)availableOutputSettingsPresets {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
