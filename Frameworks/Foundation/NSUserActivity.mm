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
#import <Foundation/NSUserActivity.h>
#import "AssertARCEnabled.h"

@implementation NSUserActivity
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithActivityType:(NSString*)activityType {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)init {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)getContinuationStreamsWithCompletionHandler:(void (^)(NSInputStream*, NSOutputStream*, NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)addUserInfoEntriesFromDictionary:(NSDictionary*)otherDictionary {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)becomeCurrent {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)resignCurrent {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)invalidate {
    UNIMPLEMENTED();
}

@end
