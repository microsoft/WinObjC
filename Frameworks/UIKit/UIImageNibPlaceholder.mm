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

#import "Starboard.h"
#import "UIImageNibPlaceholder.h"
#import "UIKit/UIView.h"
#import "UIKit/UIImage.h"
#import "LoggingNative.h"
#import "UINibUnarchiver.h"
#import "NSCoderInternal.h"

static const wchar_t* TAG = L"UIImageNibPlaceholder";

@implementation UIImageNibPlaceholder
- (instancetype)initWithCoder:(NSCoder*)coder {
    id result = self;
    NSString* resourcePath = [coder decodeObjectForKey:@"UIResourceName"];
    if (resourcePath != nil) {
        id bundle = [coder _bundle];

        if (bundle != nil) {
            id pathFind = [bundle pathForResource:resourcePath ofType:nil];
            if (pathFind != nil) {
                resourcePath = pathFind;
            }
        }

        id ret = [[UIImage imageNamed:resourcePath] retain];
        if (ret == nil) {
            TraceError(TAG, L"**** Failed to initialize image ****");
        }

        if ([coder containsValueForKey:@"UIImageWidth"] || [coder containsValueForKey:@"UIImageHeight"]) {
            float width = [coder decodeFloatForKey:@"UIImageWidth"];
            float height = [coder decodeFloatForKey:@"UIImageHeight"];

            if (width != 1.0 || height != 1.0) {
                assert(0);
                // ret = [[ret stretchableImageWithLeftCapWidth:width topCapHeight:height] retain];
            }
        }

        [self autorelease];
        result = ret;
    }

    return result;
}

@end
