//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
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
#import <CoreLocation/CoreLocationFunctions.h>

/**
 @Status Interoperable
*/
BOOL CLLocationCoordinate2DIsValid(CLLocationCoordinate2D coord) {
    if (coord.latitude > 90.0 || coord.latitude < -90.0) {
        return NO;
    }

    if (coord.longitude > 180.0 || coord.longitude < -180.0) {
        return NO;
    }

    return YES;
}

/**
 @Status Interoperable
*/
CLLocationCoordinate2D CLLocationCoordinate2DMake(CLLocationDegrees latitude, CLLocationDegrees longitude) {
    CLLocationCoordinate2D returnCoordinate = { latitude, longitude };
    return returnCoordinate;
}
