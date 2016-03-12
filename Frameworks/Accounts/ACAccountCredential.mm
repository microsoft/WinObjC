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

#import "Accounts/Accounts.h"
#include "Starboard.h"
#import "AssertARCEnabled.h"

@implementation ACAccountCredential

/**
 @Status Stub
*/
- (instancetype)initWithOAuthToken:(NSString*)token tokenSecret:(NSString*)secret {
    if (self = [super init]) {
    }

    UNIMPLEMENTED();
    return self;
}

/**
 @Status Stub
*/
- (instancetype)initWithOAuth2Token:(NSString*)token refreshToken:(NSString*)refreshToken expiryDate:(NSDate*)expiryDate {
    if (self = [super init]) {
    }

    UNIMPLEMENTED();
    return self;
}

@end