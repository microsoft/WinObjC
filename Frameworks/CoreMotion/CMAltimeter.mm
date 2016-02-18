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

#import <CoreMotion/CMAltimeter.h>
#import <StubReturn.h>

@implementation CMAltimeter
/**
 @Status Stub
 @Notes
*/
+ (BOOL)isRelativeAltitudeAvailable {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)startRelativeAltitudeUpdatesToQueue:(NSOperationQueue*)queue withHandler:(CMAltitudeHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)stopRelativeAltitudeUpdates {
    UNIMPLEMENTED();
}

@end
