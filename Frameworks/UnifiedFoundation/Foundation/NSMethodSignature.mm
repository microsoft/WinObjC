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

#include <ctype.h>
#include "Starboard.h"
#include "StubReturn.h"
#include "Foundation/NSMethodSignature.h"
#include <objc/encoding.h>

#include <vector>

@interface NSMethodSignature () {
    std::string _returnType;
    uintptr_t _frameLength;
    std::vector<std::string> _arguments;
    std::vector<uintptr_t> _argumentOffsets;
}
@end

@implementation NSMethodSignature

/**
 @Status Interoperable
*/
+ (NSMethodSignature*)signatureWithObjCTypes:(const char*)funcTypes {
    // funcTypes here is a full method type encoding. Method encodings are
    // concatenations of individual type encodings and layout information.
    // For example, v12@0:4 represents a method that:
    //  - Returns void (v)
    //  - Has a stack frame length of 12 bytes
    //  - Takes an `id` argument (@) at stack frame offset 0
    //  - Takes a `SEL` argument (:) at stack frame offset 4
    return [[[self alloc] _initWithObjCTypes:funcTypes] autorelease];
}

- (instancetype)_initWithObjCTypes:(const char*)objcTypes {
    if (self = [super init]) {
        std::vector<std::string> types;
        std::vector<uintptr_t> offsets;

        const char* ptr = objcTypes;
        while (*ptr) {
            const char* typeBegin = ptr;

            ptr = objc_skip_typespec(ptr);

            types.emplace_back(typeBegin, ptr);

            uintptr_t offset = atoi(ptr);

            offsets.emplace_back(offset);

            while (*ptr && isdigit(*ptr)) {
                ptr++;
            }
        }

        _returnType = types.front();
        _frameLength = offsets.front();

        _arguments.assign(types.begin() + 1, types.end());
        _argumentOffsets.assign(offsets.begin() + 1, offsets.end());
    }
    return self;
}

/**
 @Status Interoperable
*/
- (NSUInteger)frameLength {
    return _frameLength;
}

/**
 @Status Interoperable
*/
- (NSUInteger)numberOfArguments {
    return _arguments.size();
}

/**
 @Status Interoperable
*/
- (const char*)methodReturnType {
    return _returnType.c_str();
}

/**
 @Status Interoperable
*/
- (const char*)getArgumentTypeAtIndex:(NSUInteger)index {
    return _arguments[index].c_str();
}

- (NSInteger)getArgumentSizeAtIndex:(NSUInteger)index {
    return objc_sizeof_type(_arguments[index].c_str());
}

/**
 @Status Interoperable
*/
- (NSUInteger)methodReturnLength {
    return objc_sizeof_type(_returnType.c_str());
}

/**
 @Status Stub
 @Notes
*/
- (BOOL)isOneway {
    UNIMPLEMENTED();
    return StubReturn();
}

@end
