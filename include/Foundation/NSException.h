//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
// Copyright (c) 2006-2007 Christopher J. W. Lloyd
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
#pragma once

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/FoundationExport.h>
#import <Foundation/NSObject.h>
#include <WinError.h>

@class NSString;
@class NSDictionary;
@class NSArray;

FOUNDATION_EXPORT NSString* const NSGenericException;
FOUNDATION_EXPORT NSString* const NSRangeException;
FOUNDATION_EXPORT NSString* const NSInvalidArgumentException;
FOUNDATION_EXPORT NSString* const NSInternalInconsistencyException;
FOUNDATION_EXPORT NSString* const NSMallocException;
FOUNDATION_EXPORT NSString* const NSObjectInaccessibleException;
FOUNDATION_EXPORT NSString* const NSObjectNotAvailableException;
FOUNDATION_EXPORT NSString* const NSDestinationInvalidException;
FOUNDATION_EXPORT NSString* const NSPortTimeoutException;
FOUNDATION_EXPORT NSString* const NSInvalidSendPortException;
FOUNDATION_EXPORT NSString* const NSInvalidReceivePortException;
FOUNDATION_EXPORT NSString* const NSPortSendException;
FOUNDATION_EXPORT NSString* const NSPortReceiveException;
FOUNDATION_EXPORT NSString* const NSParseErrorException;
FOUNDATION_EXPORT NSString* const NSInconsistentArchiveException;
FOUNDATION_EXPORT NSString* const NSOldStyleException;
FOUNDATION_EXPORT NSString* const NSOverflowException;

FOUNDATION_EXPORT_CLASS
@interface NSException : NSObject <NSCoding, NSCopying>
+ (NSException*)exceptionWithName:(NSString*)name reason:(NSString*)reason userInfo:(NSDictionary*)userInfo;
+ (void)raise:(NSString*)name format:(NSString*)format, ... NS_FORMAT_FUNCTION(2, 3);
+ (void)raise:(NSString*)name format:(NSString*)format arguments:(va_list)argList NS_FORMAT_FUNCTION(2, 0);
- (instancetype)initWithName:(NSString*)name reason:(NSString*)reason userInfo:(NSDictionary*)userInfo;
- (void)raise;
@property (readonly, copy) NSString* name;
@property (readonly, copy) NSString* reason;
@property (readonly, copy) NSDictionary* userInfo;
@property (readonly, copy) NSArray* callStackReturnAddresses;
@property (readonly, copy) NSArray* callStackSymbols;
@end

@interface NSException (WinObjC)
+ (void)raiseWithLogging:(NSString*)name format:(NSString*)format, ... NS_FORMAT_FUNCTION(2, 3);
+(NSString*)_exceptionNameForHRESULT:(int)errorCode;
+(HRESULT)_HRESULTForExceptionName:(NSString *)exceptionName;
+(instancetype)_exceptionWithHRESULT:(int)errorCode reason : (NSString*)reason userInfo : (NSDictionary*)userInfo;

-(HRESULT)_hresult;
-(void)_processException;
@end

typedef void NSUncaughtExceptionHandler(NSException* exception);

FOUNDATION_EXPORT NSUncaughtExceptionHandler* NSGetUncaughtExceptionHandler(void);
FOUNDATION_EXPORT void NSSetUncaughtExceptionHandler(NSUncaughtExceptionHandler*);

typedef struct NSExceptionFrame {
    jmp_buf state;
    struct NSExceptionFrame* parent;
    __unsafe_unretained NSException* exception;
} NSExceptionFrame;

FOUNDATION_EXPORT void __NSPushExceptionFrame(NSExceptionFrame* frame);
FOUNDATION_EXPORT void __NSPopExceptionFrame(NSExceptionFrame* frame);

#define NS_DURING                                  \
    {                                              \
        NSExceptionFrame __exceptionFrame;         \
        __NSPushExceptionFrame(&__exceptionFrame); \
        if (setjmp(__exceptionFrame.state) == 0) {
#define NS_HANDLER                            \
    __NSPopExceptionFrame(&__exceptionFrame); \
    }                                         \
    else {                                    \
        NSException* localException = __exceptionFrame.exception;

#define NS_ENDHANDLER \
    }                 \
    }

#define NS_VALUERETURN(val, type)                 \
    {                                             \
        __NSPopExceptionFrame(&__exceptionFrame); \
        return val;                               \
    }

#define NS_VOIDRETURN                             \
    {                                             \
        __NSPopExceptionFrame(&__exceptionFrame); \
        return;                                   \
    }
