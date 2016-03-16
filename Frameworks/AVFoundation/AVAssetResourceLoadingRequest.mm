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

#import <AVFoundation/AVFoundation.h>

#import <StubReturn.h>
#import "AssertARCEnabled.h"

@implementation AVAssetResourceLoadingRequest
/**
@Status Stub
@Notes
*/
- (NSData*)streamingContentKeyRequestDataForApp:(NSData*)appIdentifier
                              contentIdentifier:(NSData*)contentIdentifier
                                        options:(NSDictionary*)options
                                          error:(NSError* _Nullable*)outError {
    UNIMPLEMENTED();
    return StubReturn();
}

/**
@Status Stub
@Notes
*/
- (void)finishLoadingWithResponse:(NSURLResponse*)response data:(NSData*)data redirect:(NSURLRequest*)redirect {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)finishLoading {
    UNIMPLEMENTED();
}

/**
@Status Stub
@Notes
*/
- (void)finishLoadingWithError:(NSError*)error {
    UNIMPLEMENTED();
}

@end
