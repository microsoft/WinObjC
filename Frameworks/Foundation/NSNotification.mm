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
    return [self notificationWithName:name object:obj userInfo:nil];
}

/**
 @Status Interoperable
*/
+ (NSNotification*)notificationWithName:(NSString*)name object:(id)obj userInfo:(NSDictionary*)info {
    return [[[self alloc] initWithName:name object:obj userInfo:info] autorelease];
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

/**
 @Status Interoperable
*/
- (void)dealloc {
    [notificationObj release];
    [notificationName release];
    [userInfo release];

    [super dealloc];
}

/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithName:(NSString*)aName object:(id)object userInfo:(NSDictionary*)info {
    if ((self = [super init]) != nil) {
        notificationObj = [object retain];
        notificationName = [aName copy];
        userInfo = [userInfo retain];
    }
    return self;
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