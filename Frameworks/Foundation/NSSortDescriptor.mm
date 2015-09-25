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
#include "Foundation/NSSortDescriptor.h"

@implementation NSSortDescriptor : NSObject {
    SEL _selector;
    idretaintype(NSString) _keyPath;
    BOOL _ascending;
}

- (instancetype)initWithKey:(NSString*)keyPath ascending:(BOOL)ascending {
    _selector = @selector(compare:);
    _keyPath = keyPath;
    _ascending = ascending;
    return self;
}

+ (instancetype)sortDescriptorWithKey:(NSString*)keyPath ascending:(BOOL)ascending {
    id ret = [[self alloc] initWithKey:keyPath ascending:ascending];
    return [ret autorelease];
}

+ (instancetype)sortDescriptorWithKey:(NSString*)keyPath ascending:(BOOL)ascending selector:(SEL)selector {
    id ret = [[self alloc] initWithKey:keyPath ascending:ascending selector:selector];
    return [ret autorelease];
}

- (instancetype)initWithKey:(NSString*)keyPath ascending:(BOOL)ascending selector:(SEL)selector {
    const char* keyName = (const char*)[keyPath UTF8String];

    if (selector == NULL) {
        _selector = @selector(compare:);
    } else {
        _selector = selector;
    }
    _keyPath = keyPath;
    _ascending = ascending;
    return self;
}

- (NSString*)key {
    return _keyPath;
}

- (NSInteger)compareObject:(NSObject*)object1 toObject:(NSObject*)object2 {
    id val1 = [object1 valueForKeyPath:_keyPath];
    id val2 = [object2 valueForKeyPath:_keyPath];

    int result = (NSInteger)[val1 performSelector:_selector withObject:val2];

    if (!_ascending)
        result = -result;

    return result;
}

@end
