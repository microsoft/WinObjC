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
#import <CoreLocation/CoreLocationConstants.h>

NSString* const kCLErrorDomain = @"kCLErrorDomain";
NSString* const kCLErrorUserInfoAlternateRegionKey = @"kCLErrorUserInfoAlternateRegionKey";
const CLLocationAccuracy kCLLocationAccuracyBestForNavigation = -2.0;
const CLLocationAccuracy kCLLocationAccuracyBest = -1.0;
const CLLocationAccuracy kCLLocationAccuracyNearestTenMeters = 10.0;
const CLLocationAccuracy kCLLocationAccuracyHundredMeters = 100.0;
const CLLocationAccuracy kCLLocationAccuracyKilometer = 1000.0;
const CLLocationAccuracy kCLLocationAccuracyThreeKilometers = 3000.0;
const CLLocationCoordinate2D kCLLocationCoordinate2DInvalid = { -180.0, -180.0 };
const CLLocationDistance kCLDistanceFilterNone = -1.0;
const CLLocationDegrees kCLHeadingFilterNone = -1.0;