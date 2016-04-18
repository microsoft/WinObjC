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

#import "Starboard.h"
#import "UIClassSwapper.h"
#import "NSCoderInternal.h"
#import "LoggingNative.h"

static const wchar_t* TAG = L"UIClassSwapper";

@implementation UIClassSwapper

- (instancetype)initWithCoder:(NSCoder*)coder {
    _className = [[coder decodeObjectForKey:@"UIClassName"] copy];
    _originalClassName = [[coder decodeObjectForKey:@"UIOriginalClassName"] copy];
    const char* identifier = [_className UTF8String];
    const char* identifier2 = [_originalClassName UTF8String];

    TraceVerbose(TAG, L"Swap class: %hs->%hs", identifier2, identifier);
    id classNameId = objc_getClass(identifier);

    [self autorelease];

    if (classNameId != nil) {
        id ret = [classNameId alloc];
        [coder _swapActiveObject:ret];
        if ([ret respondsToSelector:@selector(initWithCoder:)]) {
            return [ret initWithCoder:coder];
        } else {
            return [ret init];
        }
    } else {
        TraceVerbose(TAG, L"Class %hs not found!", identifier);
        return nil;
    }
}

- (void)encodeWithCoder:(NSCoder*)coder {
    UNIMPLEMENTED();
}

- (void)dealloc {
    [_className release];
    [_originalClassName release];
    [super dealloc];
}

@end
