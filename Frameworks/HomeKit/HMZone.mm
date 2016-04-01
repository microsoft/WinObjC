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

#import <HomeKit/HMZone.h>
#import "AssertARCEnabled.h"

@implementation HMZone

/**
 @Status Stub
 @Notes
*/
- (void)updateName:(NSString*)name completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addRoom:(HMRoom*)room completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)removeRoom:(HMRoom*)room completionHandler:(void (^)(NSError*))completion {
    UNIMPLEMENTED();
}

@end
