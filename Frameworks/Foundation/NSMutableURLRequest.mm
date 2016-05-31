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
#import <Foundation/NSString.h>
#import <Foundation/NSMutableDictionary.h>
#import <Foundation/NSMutableURLRequest.h>
#import <NSURLRequestInternal.h>

@implementation NSMutableURLRequest

- (void)_lazyInitAllHTTPHeaderFields {
    if (!_allHTTPHeaderFields) {
        _allHTTPHeaderFields = [NSMutableDictionary new];
    }
}

/**
 @Status Interoperable
*/
- (void)addValue:(NSString*)value forHTTPHeaderField:(NSString*)headerName {
    id existing;

    @synchronized(self) {
        [self _lazyInitAllHTTPHeaderFields];

        // Check if there is a case-sensitive variant of headerName in the dictionary
        existing = [_allHTTPHeaderFields objectForKey:headerName];

        // Check if there is a case-insensitive variant of headerName in the dictionary
        if (!existing) {
            for (NSString* key in _allHTTPHeaderFields) {
                if ([headerName caseInsensitiveCompare:key] == NSOrderedSame) {
                    // There should only ever be one case-insensitive variant of headerName in the dictionary at a time
                    headerName = key;
                    existing = [_allHTTPHeaderFields objectForKey:key];
                    break;
                }
            }
        }

        if (existing) {
            value = [[existing stringByAppendingString:@","] stringByAppendingString:value];
        }
        [_allHTTPHeaderFields setObject:[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] forKey:headerName];
    }
}

/**
 @Status Interoperable
*/
- (void)setValue:(NSString*)value forHTTPHeaderField:(NSString*)headerName {
    @synchronized(self) {
        [self _lazyInitAllHTTPHeaderFields];

        // Remove any case-insensitive variants of headerName from the dictionary
        if (![_allHTTPHeaderFields objectForKey:headerName]) {
            for (NSString* key in _allHTTPHeaderFields) {
                if ([headerName caseInsensitiveCompare:key] == NSOrderedSame) {
                    // There should only ever be one case-insensitive variant of headerName in the dictionary at a time
                    [_allHTTPHeaderFields removeObjectForKey:key];
                    break;
                }
            }
        }

        [_allHTTPHeaderFields setObject:[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] forKey:headerName];
    }
}

@end
