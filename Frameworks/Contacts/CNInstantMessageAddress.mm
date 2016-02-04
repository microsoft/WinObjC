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

#import <Contacts/CNInstantMessageAddress.h>
#import <StubReturn.h>

NSString* const CNInstantMessageAddressUsernameKey = @"CNInstantMessageAddressUsernameKey";
NSString* const CNInstantMessageAddressServiceKey = @"CNInstantMessageAddressServiceKey";
NSString* const CNInstantMessageServiceAIM = @"CNInstantMessageServiceAIM";
NSString* const CNInstantMessageServiceFacebook = @"CNInstantMessageServiceFacebook";
NSString* const CNInstantMessageServiceGaduGadu = @"CNInstantMessageServiceGaduGadu";
NSString* const CNInstantMessageServiceGoogleTalk = @"CNInstantMessageServiceGoogleTalk";
NSString* const CNInstantMessageServiceICQ = @"CNInstantMessageServiceICQ";
NSString* const CNInstantMessageServiceJabber = @"CNInstantMessageServiceJabber";
NSString* const CNInstantMessageServiceMSN = @"CNInstantMessageServiceMSN";
NSString* const CNInstantMessageServiceQQ = @"CNInstantMessageServiceQQ";
NSString* const CNInstantMessageServiceSkype = @"CNInstantMessageServiceSkype";
NSString* const CNInstantMessageServiceYahoo = @"CNInstantMessageServiceYahoo";

@implementation CNInstantMessageAddress
/**
 @Status Stub
 @Notes
*/
- (instancetype)initWithUsername:(NSString*)username service:(NSString*)service {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)localizedStringForKey:(NSString*)key {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (NSString*)localizedStringForService:(NSString*)service {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (id)copyWithZone:(NSZone*)zone {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
+ (BOOL)supportsSecureCoding {
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

@end
