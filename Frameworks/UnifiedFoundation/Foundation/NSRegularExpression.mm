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
#include "Foundation/NSRegularExpression.h"

@implementation NSRegularExpression
/**
@Status Interoperable
*/
+ (NSRegularExpression*)regularExpressionWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError**)error {
    return [[[self alloc] initWithPattern:pattern options:options error:error] autorelease];
}

/**
@Status Stub
*/
- (id)initWithPattern:(NSString*)pattern options:(NSRegularExpressionOptions)options error:(NSError**)error {
    UNIMPLEMENTED();
    return [super init];
}

/**
@Status Stub
*/
- (NSUInteger)numberOfMatchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    UNIMPLEMENTED();
    return 0;
}

/**
@Status Stub
*/
- (NSArray*)matchesInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    UNIMPLEMENTED();
    return nil;
}

/**
@Status Stub
*/
- (void)enumerateMatchesInString:(NSString*)string {
    UNIMPLEMENTED();
}

/**
@Status Stub
*/
- (NSTextCheckingResult*)firstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    UNIMPLEMENTED();
    return nil;
}

/**
@Status Stub
*/
- (NSRange)rangeOfFirstMatchInString:(NSString*)string options:(NSMatchingOptions)options range:(NSRange)range {
    UNIMPLEMENTED();
    return { NSNotFound, 0 };
}

/**
@Status Stub
*/
- (NSString*)stringByReplacingMatchesInString:(NSString*)string {
    UNIMPLEMENTED();
    return nil;
}

/**
@Status Stub
*/
- (NSUInteger)replaceMatchesInString:(NSMutableString*)string {
    UNIMPLEMENTED();
    return 0;
}

/**
@Status Stub
*/
- (void)enumerateMatchesInString:(NSString*)string
                         options:(NSMatchingOptions)options
                           range:(NSRange)range
                      usingBlock:(void (^)(NSTextCheckingResult* result, NSMatchingFlags flags, BOOL* stop))block {
    UNIMPLEMENTED();
}

/**
@Status Stub
*/
- (NSString*)stringByReplacingMatchesInString:(NSString*)string
                                      options:(NSMatchingOptions)options
                                        range:(NSRange)range
                                 withTemplate:(NSString*)tmplate {
    UNIMPLEMENTED();
    return nil;
}

/**
@Status Stub
*/
- (NSUInteger)replaceMatchesInString:(NSMutableString*)string
                             options:(NSMatchingOptions)options
                               range:(NSRange)range
                        withTemplate:(NSString*)tmplate {
    UNIMPLEMENTED();
    return 0;
}
@end
