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
#include "Foundation/NSMethodSignature.h"

bool getTypeSize(char type, int* size);
int getArgumentSize(const char* type);

@implementation NSMethodSignature : NSObject
+ (NSMethodSignature*)signatureWithObjCTypes:(char*)funcTypes {
    NSMethodSignature* ret = [self alloc];

    //  Count args
    char* curArg = funcTypes;

    while (*curArg) {
        char* typeStart = curArg;

        switch (*typeStart) {
            case '{': {
                int curCount = 0;
                while (*curArg) {
                    if (*curArg == '{') {
                        curCount++;
                    }
                    if (*curArg == '}') {
                        curCount--;
                        if (curCount == 0) {
                            break;
                        }
                    }
                    curArg++;
                }
                while (*curArg && !isdigit(*curArg)) {
                    curArg++;
                }
            } break;

            default: {
                int curCount = 0;
                while (*curArg) {
                    if (*curArg == '{') {
                        curCount++;
                    }
                    if (*curArg == '}') {
                        curCount--;
                        assert(curCount >= 0);
                    }
                    if (isdigit(*curArg) && curCount == 0) {
                        break;
                    }
                    curArg++;
                }
            } break;
        }

        char* typeEnd = curArg;

        int typeLength = typeEnd - typeStart;

        while (*curArg && isdigit(*curArg)) {
            curArg++;
        }

        char* argOffsetEnd = curArg;

        int offsetLength = argOffsetEnd - typeEnd;

        assert(typeLength > 0);
        assert(offsetLength > 0);

        if (ret->returnType == NULL) {
            ret->returnType = (char*)calloc(typeLength + 1, 1);
            strncpy(ret->returnType, typeStart, typeLength);
            ret->returnOffset = atoi(typeEnd);
        } else {
            ret->arguments[ret->numArguments] = (char*)calloc(typeLength + 1, 1);
            strncpy(ret->arguments[ret->numArguments], typeStart, typeLength);
            ret->argumentOffsets[ret->numArguments] = atoi(typeEnd);

            ret->numArguments++;
        }
    }

    return [ret autorelease];
}

- (NSUInteger)numberOfArguments {
    return numArguments;
}

- (const char*)methodReturnType {
    return returnType;
}

- (const char*)getArgumentTypeAtIndex:(int)index {
    assert(index < numArguments);

    return arguments[index];
}

- (NSInteger)getArgumentSizeAtIndex:(int)index {
    assert(index < numArguments);

    return getArgumentSize(arguments[index]);
}

- (NSInteger)methodReturnSize {
    return getArgumentSize(returnType);
}

- (NSInteger)methodReturnLength {
    return getArgumentSize(returnType);
}

- (void)dealloc {
    if (returnType) {
        free(returnType);
    }

    for (int i = 0; i < numArguments; i++) {
        if (arguments[i]) {
            free(arguments[i]);
        }
    }
    [super dealloc];
}

@end
