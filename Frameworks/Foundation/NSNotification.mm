//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Foundation/NSNotification.h>
#import <Foundation/NSCoder.h>
#import <NSRaise.h>

// NSNotification is a class cluster.
@interface _NSConcreteNotification : NSNotification {
    NSString* _name;
    id _object;
    NSDictionary* _userInfo;
}
@end

@implementation NSNotification
/**
 @Status Interoperable
*/
+ (id)allocWithZone:(NSZone*)zone {
    if (self == [NSNotification class]) {
        return [_NSConcreteNotification allocWithZone:zone];
    }
    return [super allocWithZone:zone];
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

- (Class)classForCoder {
    return [NSNotification class];
}

/**
 @Status Interoperable
*/
- (instancetype)init {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (instancetype)initWithName:(NSString*)aName object:(id)object userInfo:(NSDictionary*)info {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)name {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (id)object {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSDictionary*)userInfo {
    return NSInvalidAbstractInvocationReturn();
}

static NSString* s_NSNotificationKeyName = @"NS.name";
static NSString* s_NSNotificationKeyObject = @"NS.object";
static NSString* s_NSNotificationKeyUserInfo = @"NS.userinfo";

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)decoder {
    Class notificationClass = [self class];
    [self release];

    NSString* name = [decoder decodeObjectForKey:s_NSNotificationKeyName];
    id object = [decoder decodeObjectForKey:s_NSNotificationKeyObject];
    NSDictionary* userInfo = [decoder decodeObjectForKey:s_NSNotificationKeyUserInfo];
    return [[notificationClass alloc] initWithName:name object:object userInfo:userInfo];
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)encoder {
    [encoder encodeObject:self.name forKey:s_NSNotificationKeyName];
    [encoder encodeObject:self.object forKey:s_NSNotificationKeyObject];
    [encoder encodeObject:self.userInfo forKey:s_NSNotificationKeyUserInfo];
}

/**
 @Status Interoperable
*/
- (id)copyWithZone:(NSZone*)zone {
    // Since NSNotification is a class cluster, a consumer customizing its storage and behavior must override copyWithZone:.
    // All other notifications are immutable.
    return [self retain];
}

- (NSUInteger)hash {
    return [[self name] hash];
}
@end

@implementation _NSConcreteNotification
@synthesize name = _name, object = _object, userInfo = _userInfo;

- (instancetype)initWithName:(NSString*)aName object:(id)object userInfo:(NSDictionary*)info {
    // per documentation: ... be sure that your initializer does not call [super init] ...
    // NSNotification is not meant to be instantiated directly, and its init method raises an exception...
    _name = [aName copy];
    _object = [object retain];
    _userInfo = [info copy];
    return self;
}

- (void)dealloc {
    [_name release];
    [_object release];
    [_userInfo release];

    [super dealloc];
}
@end