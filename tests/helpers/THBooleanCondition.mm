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

#import <Helpers/TestHelpers.h>

@implementation THBooleanCondition
- (instancetype)init {
    if (self = [super init]) {
        _condition = [NSCondition new];
        _isOpen = false;
    }
    return self;
}

- (void)dealloc {
    [_condition release];
    [super dealloc];
}

- (BOOL)waitUntilDate:(NSDate*)limit {
    BOOL ret = YES;
    [_condition lock];
    while (!_isOpen && ret) {
        ret = [_condition waitUntilDate:limit];
    }
    [_condition unlock];
    return ret;
}

- (void)signal {
	[_condition lock];
	_isOpen = YES;
	[_condition signal];
	[_condition unlock];
}

- (void)broadcast {
    [_condition lock];
    _isOpen = YES;
    [_condition broadcast];
    [_condition unlock];
}
@end
