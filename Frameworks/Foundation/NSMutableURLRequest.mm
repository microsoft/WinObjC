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
    @synchronized(self) {
        [self _lazyInitAllHTTPHeaderFields];

        // Update all variants (case-insensitive and case-sensitive) of headerName in the dictionary
        for (NSString* key in _allHTTPHeaderFields.allKeys) {
            if ([headerName caseInsensitiveCompare:key] == NSOrderedSame) {
                static NSString* newValue =
                    [[[_allHTTPHeaderFields objectForKey:key] stringByAppendingString:@","] stringByAppendingString:value];
                [_allHTTPHeaderFields setObject:[newValue stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]]
                                         forKey:key];
            }
        }
    }
}

/**
 @Status Interoperable
*/
- (void)setValue:(NSString*)value forHTTPHeaderField:(NSString*)headerName {
    @synchronized(self) {
        [self _lazyInitAllHTTPHeaderFields];

        // Update any case-insensitive variants of headerName from the dictionary
        for (NSString* key in _allHTTPHeaderFields.allKeys) {
            if ([headerName caseInsensitiveCompare:key] == NSOrderedSame) {
                [_allHTTPHeaderFields setObject:[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] forKey:key];
            }
        }

        // Update the case-sensitive variant of headerName in the dictionary
        [_allHTTPHeaderFields setObject:[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] forKey:headerName];
    }
}

@end
