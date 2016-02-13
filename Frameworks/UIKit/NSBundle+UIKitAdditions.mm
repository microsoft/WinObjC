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
#import <Foundation/NSNib.h>
#import <UIKit/NSBundle+UIKitAdditions.h>
#import <StubReturn.h>
#include "Starboard.h"

NSString* const UINibProxiedObjectsKey = @"UINibProxiedObjectsKey";
NSString* const UINibExternalObjects = @"UINibExternalObjects";

@implementation NSBundle (UIKit)
/**
 @Status Caveat
 @Notes The 'options' argument is not yet supported.
*/
- (NSArray*)loadNibNamed:(NSString*)name owner:(id)owner options:(NSDictionary*)options {
    if (options) {
        UNIMPLEMENTED_WITH_MSG("The 'options' argument is not yet supported.");
    }

    NSString* nibFile = [self pathForResource:name ofType:@"nib"];
    if (!nibFile) {
        EbrDebugLog("NIB [%hs] not found!", [name UTF8String]);
        return nil;
    } else {
        NSNib* nib = [NSNib nibWithNibName:nibFile bundle:self];
        NSArray* topLevelObjects = [nib instantiateWithOwner:owner options:options];
        return topLevelObjects;
    }
}
@end
