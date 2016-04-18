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
#include <memory>
#include <unordered_map>

@interface NSMethodSignature () {
    std::string _returnType;
    uintptr_t _frameLength;

    std::vector<std::pair<std::string, uintptr_t>> _arguments;
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
    static std::unordered_map<std::string, StrongId<NSMethodSignature>> s_cachedMethodSignatures;
    @synchronized(self) {
        std::string objCTypes(funcTypes);
        const auto found = s_cachedMethodSignatures.find(objCTypes);
        if (found != s_cachedMethodSignatures.end()) {
            return found->second;
        }
        NSMethodSignature* newMethodSignature = [[[self alloc] _initWithObjCTypes:funcTypes] autorelease];
        s_cachedMethodSignatures.emplace(std::piecewise_construct,
                                         std::forward_as_tuple(std::move(objCTypes)),
                                         std::forward_as_tuple(newMethodSignature));
        return newMethodSignature;
    }
}

- (instancetype)_initWithObjCTypes:(const char*)objcTypes {
    if (self = [super init]) {
        _arguments.reserve(16);

        const char* ptr = objcTypes;
        while (*ptr) {
            const char* typeBegin = ptr;

            ptr = objc_skip_typespec(ptr);

            std::string argumentType(typeBegin, ptr);
            uintptr_t offset = atoi(ptr);

            // The first entry is the return type and the stack frame length.
            if (typeBegin == objcTypes) {
                _returnType = std::move(argumentType);
                _frameLength = offset;
            } else {
                _arguments.emplace_back(std::move(argumentType), offset);
            }

            while (*ptr && isdigit(*ptr)) {
                ptr++;
            }
        }
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
    return _arguments[index].first.c_str();
}

- (NSInteger)getArgumentSizeAtIndex:(NSUInteger)index {
    return objc_sizeof_type(_arguments[index].first.c_str());
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
