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

static Boolean _CFHTTPHeaderEqual(const void* obj1, const void* obj2) {
    return [(id)obj1 caseInsensitiveCompare:(NSString*)obj2] == 0;
}

static CFHashCode _CFHTTPHeaderHash(const void* obj1) {
    return [[(id)obj1 lowercaseString] hash];
}

- (void)_lazyInitAllHTTPHeaderFields {
    if (!_allHTTPHeaderFields) {
        CFDictionaryKeyCallBacks caseInsensitiveKeyChecker = kCFTypeDictionaryKeyCallBacks;

        caseInsensitiveKeyChecker.equal = _CFHTTPHeaderEqual;
        caseInsensitiveKeyChecker.hash = _CFHTTPHeaderHash;

        _allHTTPHeaderFields =
            (NSMutableDictionary*)CFDictionaryCreateMutable(NULL, 0, &caseInsensitiveKeyChecker, &kCFTypeDictionaryValueCallBacks);
    }
}

/**
 @Status Interoperable
*/
- (void)addValue:(NSString*)value forHTTPHeaderField:(NSString*)headerName {
    @synchronized(self) {
        [self _lazyInitAllHTTPHeaderFields];

        id existingValue = [_allHTTPHeaderFields objectForKey:headerName];
        if (existingValue) {
            value = [[existingValue stringByAppendingString:@","] stringByAppendingString:value];
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

        [_allHTTPHeaderFields setObject:[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] forKey:headerName];
    }
}

/**
 @Status Interoperable
*/
- (instancetype)copyWithZone:(NSZone*)zone {
    return [self mutableCopyWithZone:zone];
}

@end
