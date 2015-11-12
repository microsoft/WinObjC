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

#include "gtest-api.h"
#import <CoreLocation/CoreLocation.h>

TEST(CoreLocation, CLLocationManager_SanityTest) {
    LOG_INFO("CLLocationManager sanity test: ");

    ASSERT_FALSE_MSG([CLLocationManager deferredLocationUpdatesAvailable], "FAILED: deferredLocationUpdatesAvailable is not supported!\n");
    ASSERT_FALSE_MSG([CLLocationManager significantLocationChangeMonitoringAvailable],
                     "FAILED: significantLocationChangeMonitoringAvailable is not supported!\n");
    ASSERT_FALSE_MSG([CLLocationManager headingAvailable], "FAILED: headingAvailable is not supported!\n");
    ASSERT_FALSE_MSG([CLLocationManager isRangingAvailable], "FAILED: isRangingAvailable is not supported!\n");

    // TODO::
    // todo-nithishm-11022015 - Add more tests as the implementation gets completed.
}