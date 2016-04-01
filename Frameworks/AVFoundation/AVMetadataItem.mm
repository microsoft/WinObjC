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

@implementation AVMetadataItem
/**
@Status Stub
@Notes
*/
- (void)loadValuesAsynchronouslyForKeys:(NSArray*)keys completionHandler:(void (^)(void))handler {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (AVKeyValueStatus)statusOfValueForKey:(NSString*)key error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSString*)identifierForKey:(id)key keySpace:(NSString*)keySpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (id)keyForIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSString*)keySpaceForIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)metadataItemsFromArray:(NSArray*)array withKey:(id)key keySpace:(NSString*)keySpace {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)metadataItemsFromArray:(NSArray*)array withLocale:(NSLocale*)locale {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)metadataItemsFromArray:(NSArray*)metadataItems filteredAndSortedAccordingToPreferredLanguages:(NSArray*)preferredLanguages {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)metadataItemsFromArray:(NSArray*)metadataItems filteredByMetadataItemFilter:(AVMetadataItemFilter*)metadataItemFilter {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
+ (NSArray*)metadataItemsFromArray:(NSArray*)metadataItems filteredByIdentifier:(NSString*)identifier {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (id)mutableCopyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
