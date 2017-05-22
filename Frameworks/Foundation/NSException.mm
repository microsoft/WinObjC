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

#import <Starboard.h>
#import <StubReturn.h>
#import <Foundation/NSException.h>
#import <NSLogging.h>
#import <winstring.h>

#include <COMIncludes.h>
#import <roerrorapi.h>
#import <wrl/wrappers/corewrappers.h>
#include <COMIncludes_End.h>

#import <StringHelpers.h>

#import "NSExceptionInternal.h"

static const wchar_t* TAG = L"NSException";
NSString* const NSRangeException = @"NSRangeExcepton";
NSString* const NSGenericException = @"NSGenericException";
NSString* const NSInvalidArgumentException = @"NSInvalidArgumentException";
NSString* const NSInternalInconsistencyException = @"NSInternalInconsistencyException";
NSString* const NSObjectNotAvailableException = @"NSObjectNotAvailableException";
NSString* const NSDestinationInvalidException = @"NSDestinationInvalidException";
NSString* const NSURLErrorDomain = @"NSURLErrorDomain";
NSString* const NSOverflowException = @"NSOverflowException";
NSString* const NSObjectInaccessibleException = @"NSObjectInaccessibleException";
NSString* const NSMallocException = @"NSMallocException";
NSString* const WinObjCException = @"WinObjC Exception"; // not exported

// The uncaught exception handler is not thread-specific.
// Loads and stores of a single pointer's width are guaranteed to be atomic.
static NSUncaughtExceptionHandler* s_uncaughtExceptionHandler = nullptr;

// Entry point used by NSException_Win32.cpp after C++ ThrowInfo unboxing.
void _NSExceptionCallUnhandledExceptionHandler(void* untypedException) {
    if (s_uncaughtExceptionHandler) {
        // The machinery that calls this function only calls it for exceptions whose type descriptors
        // contain NSException* and objc_object*, making this cast safe.
        s_uncaughtExceptionHandler(reinterpret_cast<NSException*>(untypedException));
    }
}
/**
 @Status Interoperable
*/
void NSSetUncaughtExceptionHandler(NSUncaughtExceptionHandler* handler) {
    s_uncaughtExceptionHandler = handler;
}

/**
 @Status Interoperable
*/
NSUncaughtExceptionHandler* NSGetUncaughtExceptionHandler() {
    return s_uncaughtExceptionHandler;
}

@implementation NSException

/**
 @Status Interoperable
*/
- (instancetype)initWithName:(NSString*)name reason:(NSString*)reason userInfo:(NSDictionary*)userInfo {
    if (self = [super init]) {
        _name = [name copy];
        _reason = [reason copy];
        _userInfo = [userInfo copy];
        // VSO 6794375: Implement NSThread callStackReturnAddresses, callStackSymbols
        //_callStackReturnAddresses = [NSThread callStackReturnAddresses];
        //_callStackSymbols = [NSThread callStackSymbols];
    }

    return self;
}

/**
 @Status Interoperable
*/
+ (instancetype)exceptionWithName:(NSString*)name reason:(NSString*)reason userInfo:(NSDictionary*)userInfo {
    NSException* ret = [[self alloc] initWithName:name reason:reason userInfo:userInfo];

    return [ret autorelease];
}

/**
 @Status Interoperable
*/
+ (void)raise:(NSString*)name format:(NSString*)format, ... {
    va_list reader;
    va_start(reader, format);

    NSString* reason = [[NSString alloc] initWithFormat:format arguments:reader];
    va_end(reader);

    NSException* exception = [self exceptionWithName:name reason:reason userInfo:nil];
    [reason release];
    [exception raise];
}

/**
 @Status Interoperable
*/
+ (void)raiseWithLogging:(NSString*)name format:(NSString*)format, ... {
    va_list reader;
    va_start(reader, format);

    NSString* reason = [[NSString alloc] initWithFormat:format arguments:reader];
    va_end(reader);

    NSTraceError(TAG, @"Exception %@ raised!\nReason: %@\n", name, reason);

    NSException* exception = [self exceptionWithName:name reason:reason userInfo:nil];
    [reason release];

    [exception raise];
}

/**
 @Status Interoperable
*/
+ (void)raise:(NSString*)name format:(NSString*)format arguments:(va_list)args {
    NSString* reason = [[NSString alloc] initWithFormat:format arguments:args];
    NSException* exception = [self exceptionWithName:name reason:reason userInfo:nil];
    [reason release];
    [exception raise];
}

/**
 @Status Interoperable
*/
- (void)raise {
    @throw self;
}

/**
 @Status Interoperable
*/
- (NSObject*)copyWithZone:(NSZone*)zone {
    return [self retain];
}

/**
 @Status Interoperable
*/
+ (BOOL)supportsSecureCoding {
    return YES;
}

/**
 @Status Interoperable
*/
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        _name = [[coder decodeObjectOfClass:[NSString class] forKey:@"name"] retain];
        _reason = [[coder decodeObjectOfClass:[NSString class] forKey:@"reason"] retain];
        _userInfo = [[coder decodeObjectOfClass:[NSDictionary class] forKey:@"userInfo"] retain];
        _callStackReturnAddresses = [[coder decodeObjectOfClass:[NSArray class] forKey:@"callStackReturnAddresses"] retain];
        _callStackSymbols = [[coder decodeObjectOfClass:[NSArray class] forKey:@"callStackSymbols"] retain];
    }
    return self;
}

/**
 @Status Interoperable
*/
- (void)encodeWithCoder:(NSCoder*)coder {
    [coder encodeObject:_name forKey:@"name"];
    [coder encodeObject:_reason forKey:@"reason"];
    [coder encodeObject:_userInfo forKey:@"userInfo"];
    [coder encodeObject:_callStackReturnAddresses forKey:@"callStackReturnAddresses"];
    [coder encodeObject:_callStackSymbols forKey:@"callStackSymbols"];
}

/**
 @Status Interoperable
*/
- (void)dealloc {
    [_name release];
    [_reason release];
    [_userInfo release];
    [_callStackReturnAddresses release];
    [_callStackSymbols release];

    [super dealloc];
}

- (NSString*)description {
    return [self reason];
}

// Returns exception name from HRESULT.
+ (NSString*)_exceptionNameForHRESULT:(int)errorCode {
    switch (errorCode) {
        case E_INVALIDARG:
            return NSInvalidArgumentException;
        case E_FAIL:
            return NSGenericException;
        case E_BOUNDS:
            return NSRangeException;
        case E_ACCESSDENIED:
        case RPC_E_WRONG_THREAD:
            return NSObjectInaccessibleException;
        case E_UNEXPECTED:
            return NSInternalInconsistencyException;
        case E_OUTOFMEMORY:
            return NSMallocException;
        case __HRESULT_FROM_WIN32(ERROR_NOT_READY):
            return NSObjectNotAvailableException;
        default:
            break;
    }

    return WinObjCException;
}

// Returns a HRESULT for an exception name
// Note: The table is not the exact inverse of _exceptionNameForHRESULT.
// E.g. E_ACCESSDENIED and RPC_E_WRONG_THREAD both map to NSObjectInaccessibleException.
// However, NSObjectInaccessibleException only maps to E_ACCESSDENIED
+ (HRESULT)_HRESULTForExceptionName:(NSString*)exceptionName {
    if ([exceptionName isEqualToString:NSInvalidArgumentException]) {
        return E_INVALIDARG;
    } else if ([exceptionName isEqualToString:NSGenericException]) {
        return E_FAIL;
    } else if ([exceptionName isEqualToString:NSRangeException]) {
        return E_BOUNDS;
    } else if ([exceptionName isEqualToString:NSObjectInaccessibleException]) {
        return E_ACCESSDENIED;
    } else if ([exceptionName isEqualToString:NSInternalInconsistencyException]) {
        return E_UNEXPECTED;
    } else if ([exceptionName isEqualToString:NSMallocException]) {
        return E_OUTOFMEMORY;
    } else if ([exceptionName isEqualToString:NSObjectNotAvailableException]) {
        return __HRESULT_FROM_WIN32(ERROR_NOT_READY);
    }
    return E_UNEXPECTED;
}

// Returns exception with given HRESULT
+ (instancetype)_exceptionWithHRESULT:(int)errorCode reason:(NSString*)reason userInfo:(NSDictionary*)userInfo {
    NSException* ret = [[self alloc] initWithName:[self _exceptionNameForHRESULT:errorCode] reason:reason userInfo:userInfo];

    return [ret autorelease];
}

- (HRESULT)_hresult {
    // If we have an hresult in our user dict, use that, otherwise this was unexpected:
    NSNumber* hresultValue = [self.userInfo objectForKey:g_NSHResultErrorDictKey];
    if (hresultValue) {
        return [hresultValue unsignedIntValue];
    }

    return [[self class] _HRESULTForExceptionName:self.name];
}

- (void)_processException {
    HRESULT hr = [self _hresult];
    auto reason = Strings::NarrowToWide<HSTRING>(self.reason);
    ::SetRestrictedErrorInfo(nullptr); // Clear the COM Error Info
    RoOriginateLanguageException(hr, reason.Get(), nullptr);
}
@end

static __attribute__((constructor)) void _initExceptionHandling() {
    SetUnhandledExceptionFilter(&_NSWindowsUnhandledExceptionFilter);
}