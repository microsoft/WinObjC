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

#import <StubReturn.h>
#import <MapKit/MKMapItem.h>

NSString* const MKLaunchOptionsDirectionsModeKey = @"MKLaunchOptionsDirectionsModeKey";
NSString* const MKLaunchOptionsMapTypeKey = @"MKLaunchOptionsMapTypeKey";
NSString* const MKLaunchOptionsMapCenterKey = @"MKLaunchOptionsMapCenterKey";
NSString* const MKLaunchOptionsMapSpanKey = @"MKLaunchOptionsMapSpanKey";
NSString* const MKLaunchOptionsShowsTrafficKey = @"MKLaunchOptionsShowsTrafficKey";
NSString* const MKLaunchOptionsCameraKey = @"MKLaunchOptionsCameraKey";
NSString* const MKLaunchOptionsDirectionsModeDriving = @"MKLaunchOptionsDirectionsModeDriving";
NSString* const MKLaunchOptionsDirectionsModeWalking = @"MKLaunchOptionsDirectionsModeWalking";
NSString* const MKLaunchOptionsDirectionsModeTransit = @"MKLaunchOptionsDirectionsModeTransit";

@implementation MKMapItem
/**
 @Status Stub
 @Notes
*/
+ (MKMapItem*)mapItemForCurrentLocation {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithPlacemark:(MKPlacemark*)placemark {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)openMapsWithItems:(NSArray*)mapItems launchOptions:(NSDictionary*)launchOptions {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)openInMapsWithLaunchOptions:(NSDictionary*)launchOptions {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
