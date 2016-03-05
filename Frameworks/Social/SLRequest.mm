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

#import <StubReturn.h>
#import <Social/SLRequest.h>

NSString* const SLServiceTypeFacebook = @"Facebook";
NSString* const SLServiceTypeTwitter = @"Twitter";
NSString* const SLServiceTypeSinaWeibo = @"SinaWeibo";
NSString* const SLServiceTypeTencentWeibo = @"TencentWeibo";

@implementation SLRequest
/**
 @Status Stub
 @Notes
*/
+ (SLRequest*)requestForServiceType:(NSString*)serviceType
                      requestMethod:(SLRequestMethod)requestMethod
                                URL:(NSURL*)url
                         parameters:(NSDictionary*)parameters {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)performRequestWithHandler:(SLRequestHandler)handler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (NSURLRequest*)preparedURLRequest {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
 @Status Stub
 @Notes
*/
- (void)addMultipartData:(NSData*)data withName:(NSString*)name type:(NSString*)type filename:(NSString*)filename {
    UNIMPLEMENTED();
}

@end
