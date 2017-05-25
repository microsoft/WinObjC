//******************************************************************************
//
// Copyright (c) Microsoft. All rights reserved.
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

#import <Foundation/Foundation.h>
#import <TestFramework.h>

TEST(NSURLProtocol, PropertyForKey_InRequest) {
    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://notarealurl.not/"]];
    NSString* key = @"key";

    ASSERT_OBJCEQ(nil, [NSURLProtocol propertyForKey:key inRequest:request]);

    [NSURLProtocol setProperty:@2 forKey:key inRequest:request];
    ASSERT_OBJCEQ(@2, [NSURLProtocol propertyForKey:key inRequest:request]);

    NSMutableURLRequest* copiedRequest = [[request mutableCopy] autorelease];
    ASSERT_OBJCEQ(@2, [NSURLProtocol propertyForKey:key inRequest:copiedRequest]);

    NSData* data = nil;
    ASSERT_NO_THROW(data = [NSKeyedArchiver archivedDataWithRootObject:request]);

    NSMutableURLRequest* decodedRequest = nil;
    ASSERT_NO_THROW(decodedRequest = [NSKeyedUnarchiver unarchiveObjectWithData:data]);
    ASSERT_OBJCEQ(@2, [NSURLProtocol propertyForKey:key inRequest:decodedRequest]);

    // Properties affect equality but not hashing
    NSMutableURLRequest* requestWithoutProperty = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://notarealurl.not/"]];
    ASSERT_OBJCEQ(copiedRequest, request);
    ASSERT_OBJCNE(requestWithoutProperty, request);
    ASSERT_EQ([requestWithoutProperty hash], [request hash]);

    [NSURLProtocol removePropertyForKey:key inRequest:request];
    ASSERT_OBJCEQ(nil, [NSURLProtocol propertyForKey:key inRequest:request]);
}