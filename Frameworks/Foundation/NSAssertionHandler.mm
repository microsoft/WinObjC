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
#import <Foundation/NSAssertionHandler.h>
#import <Foundation/NSException.h>
#import <Foundation/NSThread.h>
#import <Foundation/NSString.h>

const NSString* NSAssertionHandlerKey = @"NSAssertionHandlerKey";

@implementation NSAssertionHandler

+ (NSAssertionHandler*)currentHandler {
    id currentHandlerForThread = [[[NSThread currentThread] threadDictionary] objectForKey:NSAssertionHandlerKey];

    if (currentHandlerForThread == nil) {
        if ((currentHandlerForThread = [[[self alloc] init] autorelease]) != nil) {
            [[[NSThread currentThread] threadDictionary] setObject:currentHandlerForThread forKey:NSAssertionHandlerKey];
        }
    }

    return currentHandlerForThread;
}

- (void)handleFailureInMethod:(SEL)selector
                       object:(id)object
                         file:(NSString*)fileName
                   lineNumber:(NSInteger)line
                  description:(NSString*)format, ... {
    NSLog(@"*** Assertion failure in %c[%@ %@], %@:%ld",
          (object == [object class]) ? '+' : '-',
          NSStringFromClass([object class]),
          NSStringFromSelector(selector),
          fileName,
          (long)line);

    va_list arguments;
    va_start(arguments, format);
    [NSException raise:NSInternalInconsistencyException format:format arguments:arguments];
    va_end(arguments);
}

- (void)handleFailureInFunction:(NSString*)functionName
                           file:(NSString*)fileName
                     lineNumber:(NSInteger)line
                    description:(NSString*)format, ... {
    NSLog(@"*** Assertion failure in %@, %@:%ld", functionName, fileName, (long)line);

    va_list arguments;
    va_start(arguments, format);
    [NSException raise:NSInternalInconsistencyException format:format arguments:arguments];
    va_end(arguments);
}

@end