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

#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSError.h"
#include "NSCFError.h"
#include "BridgeHelpers.h"

/* Error Domains */
NSString* const NSOSStatusErrorDomain = @"NSOSStatusErrorDomain";
NSString* const NSWINSOCKErrorDomain = @"NSWINSOCKErrorDomain";
NSString* const NSWin32ErrorDomain = @"NSWin32ErrorDomain";
NSString* const NSCocoaErrorDomain = @"NSCocoaErrorDomain";
NSString* const NSMachErrorDomain = @"NSMachErrorDomain";

/* Error Keys */
NSString* const NSUnderlyingErrorKey = @"NSUnderlyingErrorKey";
NSString* const NSLocalizedDescriptionKey = @"NSLocalizedDescriptionKey";
NSString* const NSLocalizedFailureReasonErrorKey = @"NSLocalizedFailureReasonErrorKey";
NSString* const NSLocalizedRecoveryOptionsErrorKey = @"NSLocalizedRecoveryOptionsErrorKey";
NSString* const NSLocalizedRecoverySuggestionErrorKey = @"NSLocalizedRecoverySuggestionErrorKey";
NSString* const NSRecoveryAttempterErrorKey = @"NSRecoveryAttempterErrorKey";
NSString* const NSStringEncodingErrorKey = @"NSStringEncodingErrorKey";
NSString* const NSErrorFailingURLStringKey = @"NSErrorFailingURLStringKey";
NSString* const NSURLErrorKey = @"NSURLErrorKey";
NSString* const NSDebugDescriptionKey = @"NSDebugDescription";

NSString* const NSFilePathErrorKey = @"NSFilePathErrorKey";
NSString* const NSHelpAnchorErrorKey = @"NSHelpAnchorErrorKey";
NSString* const NSURLErrorFailingURLErrorKey = @"NSURLErrorFailingURLErrorKey";
NSString* const NSURLErrorFailingURLStringErrorKey = @"NSURLErrorFailingURLStringErrorKey";
NSString* const NSURLErrorFailingURLPeerTrustErrorKey = @"NSURLErrorFailingURLPeerTrustErrorKey";

@implementation NSError

+ ALLOC_PROTOTYPE_SUBCLASS_WITH_ZONE(NSError, NSErrorPrototype);

/**
 @Status Interoperable
*/
+ (instancetype)errorWithDomain:(NSString*)domain code:(NSInteger)code userInfo:(NSDictionary*)dict {
    return [[[self alloc] initWithDomain:domain code:code userInfo:dict] autorelease];
}

/**
 @Status Interoperable
*/
- (instancetype)initWithDomain:(NSString*)domain code:(NSInteger)code userInfo:(NSDictionary*)dict {
    // Derived classes are required to implement this initializer.
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)description {
    return [self localizedDescription];
}

/**
 @Status Interoperable
*/
- (NSString*)domain {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (int)code {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSDictionary*)userInfo {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)localizedDescription {
    return NSInvalidAbstractInvocationReturn();
}

/**
 @Status Interoperable
*/
- (NSString*)localizedFailureReason {
    return NSInvalidAbstractInvocationReturn();
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
- (id)initWithCoder:(NSCoder*)decoder {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
- (BOOL)isEqual:(id)other {
    if (self == other) {
        return YES;
    }

    if (![other isKindOfClass:[NSError class]]) {
        return NO;
    }

    return ([[self domain] isEqual:[other domain]] &&
        [self code] == [other code] &&
        [[self userInfo] isEqual:[other userInfo]] &&
        [[self localizedDescription] isEqual:[other localizedDescription]]);
}

/**
 @Status Interoperable
*/
- (unsigned int)hash {
    return [self code] + [[self domain] hash];
}

@end