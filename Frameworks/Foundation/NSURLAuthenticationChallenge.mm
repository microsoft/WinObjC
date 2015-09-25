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

#include "Starboard.h"
#include "Foundation/NSString.h"
#include "Foundation/NSURLAuthenticationChallenge.h"
#include "Foundation/NSURLProtectionSpace.h"

@implementation NSURLProtectionSpace : NSObject

@end

@implementation NSURLAuthenticationChallenge : NSObject
- (NSUInteger)previousFailureCount {
    return 0;
}

- (id)protectionSpace {
    return _protectionSpace;
}

- (id)init {
    _protectionSpace = [NSURLProtectionSpace new];

    return self;
}

- (id)sender {
    return _sender;
}

- (id)setSender:(id)sender {
    _sender = sender;

    return self;
}

@end
