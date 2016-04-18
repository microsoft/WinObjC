//******************************************************************************
//
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <Twitter/Twitter.h>
#import <StubReturn.h>
#import "AssertARCEnabled.h"

@implementation TWRequest
/**
 @Status Stub
 @Notes
*/
- (id)initWithURL:(NSURL*)url parameters:(NSDictionary*)parameters requestMethod:(TWRequestMethod)requestMethod {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addMultiPartData:(NSData*)data withName:(NSString*)name type:(NSString*)type {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)performRequestWithHandler:(TWRequestHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSURLRequest*)signedURLRequest {
    UNIMPLEMENTED();
    return StubReturn();
}

@end