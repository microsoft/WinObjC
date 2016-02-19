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
#import <GameKit/GKTurnBasedExchange.h>

/** @Status Stub */
const NSTimeInterval GKExchangeTimeoutDefault = StubConstant();
/** @Status Stub */
const NSTimeInterval GKExchangeTimeoutNone = StubConstant();

@implementation GKTurnBasedExchange
/**
 @Status Stub
 @Notes
*/
- (void)cancelWithLocalizableMessageKey:(NSString*)key
                              arguments:(NSArray*)arguments
                      completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

/**
 @Status Stub
 @Notes
*/
- (void)replyWithLocalizableMessageKey:(NSString*)key
                             arguments:(NSArray*)arguments
                                  data:(NSData*)data
                     completionHandler:(void (^)(NSError*))completionHandler {
    UNIMPLEMENTED();
}

@end
