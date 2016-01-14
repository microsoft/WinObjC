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
/**
 @Status Interoperable
*/
- (void)addValue:(NSString*)value forHTTPHeaderField:(NSString*)headerName {
    id existing;

    existing = [_allHTTPHeaderFields objectForKey:headerName];
    if (existing != nil) {
        value = [[existing stringByAppendingString:@","] stringByAppendingString:value];
    }
    [_allHTTPHeaderFields setObject:[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] forKey:headerName];
}

/**
 @Status Interoperable
*/
- (void)setValue:(NSString*)value forHTTPHeaderField:(NSString*)headerName {
    [_allHTTPHeaderFields setObject:[value stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]] forKey:headerName];
}
@end
