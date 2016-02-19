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
#include "UIRuntimeOutletCollectionConnection.h"

@implementation UIRuntimeOutletCollectionConnection : NSObject
- (instancetype)initWithCoder:(NSCoder*)coder {
    if (self = [super init]) {
        source = [coder decodeObjectForKey:@"UISource"];
        dest = [coder decodeObjectForKey:@"UIDestination"];
        label = [coder decodeObjectForKey:@"UILabel"];
    }

    return self;
}

- (void)_makeConnection {
    NSMutableArray* collection = [source valueForKey:label];
    [collection addObject:dest];
}

@end
