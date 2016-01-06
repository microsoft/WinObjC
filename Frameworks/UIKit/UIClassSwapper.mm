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

@implementation UIClassSwapper
- (id)instantiateWithCoder:(id)coder {
    _className = [[coder decodeObjectForKey:@"UIClassName"] copy];
    _originalClassName = [[coder decodeObjectForKey:@"UIOriginalClassName"] copy];
    const char* identifier = [_className UTF8String];
    const char* identifier2 = [_originalClassName UTF8String];

    EbrDebugLog("Swap class: %s->%s\n", identifier2, identifier);
    id classNameId = objc_getClass(identifier);

    if (classNameId != nil) {
        return [classNameId alloc];
    } else {
        EbrDebugLog("Class %s not found!\n", identifier);
        return nil;
    }
}

- (void)dealloc {
    [_className release];
    [_originalClassName release];
    [super dealloc];
}

@end
