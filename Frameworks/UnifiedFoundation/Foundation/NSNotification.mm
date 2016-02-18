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
#import <Foundation/NSNotification.h>

@implementation NSNotification {
    NSString* notificationName;
    id notificationObj;
    id userInfo;
}

/**
 @Status Interoperable
*/
+ (NSNotification*)notificationWithName:(NSString*)name object:(id)obj {
    NSNotification* ret = [self alloc];

    ret->notificationName = [name retain];
    ret->notificationObj = [obj retain];
    ret->userInfo = nil;

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (NSNotification*)notificationWithName:(NSString*)name object:(id)obj userInfo:(NSDictionary*)info {
    NSNotification* ret = [self alloc];

    ret->notificationName = [name retain];
    ret->notificationObj = [obj retain];
    ret->userInfo = [info retain];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
- (id)object {
    return notificationObj;
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    return notificationName;
}

/**
 @Status Interoperable
*/
- (NSDictionary*)userInfo {
    return userInfo;
}

- (void)dealloc {
    [notificationName release];
    [notificationObj release];
    [userInfo release];

    [super dealloc];
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithName:(NSString*)aName object:(id)object userInfo:(NSDictionary*)userInfo {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

@end