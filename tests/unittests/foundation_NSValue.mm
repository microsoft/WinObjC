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

#include "gtest-api.h"
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#include <objc/runtime.h>
#include <exception>

#if defined(ANSI_COLOR)
#define SGR_RED "\033[1;31m"
#define SGR_GREEN "\033[1;32m"
#define SGR_RESET "\033[0m"
#else
#define SGR_RED
#define SGR_GREEN
#define SGR_RESET
#endif

static bool globalFailure = false;

static void perform(const char* what, bool (^block)(), bool flipbit = false) {
    bool b = false;
    const char* xcp = NULL;
    char msgStr[BUFSIZ];
    try {
        b = block();
    } catch(const std::exception &e) {
        xcp = _strdup(e.what());
        b = false;
    } catch(...) {
        xcp = "unknown?";
        b = false;
    }
    snprintf(msgStr, sizeof(msgStr), "%s", " - ");
    if(flipbit != b) {
        snprintf(msgStr, sizeof(msgStr), "%s%s", msgStr, (SGR_GREEN "PASSED" SGR_RESET));
    } else {
        globalFailure = true;
        snprintf(msgStr, sizeof(msgStr), "%s%s", msgStr, (SGR_RED "FAILED"));
        if(xcp) {
            snprintf(msgStr, sizeof(msgStr), "%s (" SGR_RESET "%s" SGR_RED ") ", msgStr, xcp);
        }
    }
    snprintf(msgStr, sizeof(msgStr), "%s: %s", msgStr, what);
    LOG_INFO(msgStr);
}

struct ArbitrarilyComplexStruct {
    __m128 i;
    _Complex double c;
};

TEST(Foundation, NSValue) {
    perform("can store a pointer",
            ^bool {
                id val = [NSValue valueWithPointer:(void*)0x10101];
                if (!val) {
                    return false;
                }

                return ([val pointerValue] == (void*)0x10101);
            });
    perform("specialized instance is still an NSValue",
            ^bool {
                id val = [NSValue valueWithPointer:(void*)0x10101];
                return [val isKindOfClass:[NSValue class]];
            });
    perform("pointer instance cannot be accessed as rect",
            ^bool {
                id val = [NSValue valueWithPointer:(void*)0x10101];
                [val CGRectValue];
                return true;
            },
            true);
    perform("stored rect can be accessed as a rect",
            ^bool {
                id val = [NSValue valueWithCGRect:(CGRect){ 10, 20, 30, 40 }];
                [val CGRectValue];
                return true;
            });
    perform("rect stored through generic pointer can be accessed as a rect",
            ^bool {
                CGRect r = CGRectMake(10, 20, 30, 40);
                id val = [NSValue valueWithBytes:&r objCType:@encode(CGRect)];
                [val CGRectValue];
                return true;
            });
    perform("rect stored through generic pointer compares favorably to a rect stored via normal setter",
            ^bool {
                CGRect r = CGRectMake(10, 20, 30, 40);
                id val = [NSValue valueWithBytes:&r objCType:@encode(CGRect)];
                id val2 = [NSValue valueWithCGRect:CGRectMake(10, 20, 30, 40)];
                return [val isEqualToValue:val2] == YES;
            });
    perform("rect stored via normal setter memcmps rect that we create",
            ^bool {
                CGRect r = CGRectMake(10, 20, 30, 40);
                id val2 = [NSValue valueWithCGRect:CGRectMake(10, 20, 30, 40)];
                void* bytes = malloc(sizeof(CGRect));
                [val2 getValue:bytes];
                return memcmp(&r, bytes, sizeof(CGRect)) == 0;
            });

    ArbitrarilyComplexStruct acs{ 3.14, 1.9i };
    perform("arbitrary struct can be stored",
            ^bool {
                id val = [NSValue valueWithBytes:&acs objCType:@encode(ArbitrarilyComplexStruct)];
                return val != nil;
            });
    perform("arbitrary struct can be retrieved",
            ^bool {
                id val = [NSValue valueWithBytes:&acs objCType:@encode(ArbitrarilyComplexStruct)];
                void* bytes = malloc(sizeof(ArbitrarilyComplexStruct));
                [val getValue:bytes];
                return true;
            });
    perform("arbitrary struct can be retrieved _and contain the same values_",
            ^bool {
                id val = [NSValue valueWithBytes:&acs objCType:@encode(ArbitrarilyComplexStruct)];
                ArbitrarilyComplexStruct acs2{};
                [val getValue:&acs2];
                return acs.c == acs2.c;
            });
    perform("arbitrary struct can be serialized and deserialized",
            ^bool {
                id val = [NSValue valueWithBytes:&acs objCType:@encode(ArbitrarilyComplexStruct)];
                id data = [NSKeyedArchiver archivedDataWithRootObject:val];
                id val2 = [NSKeyedUnarchiver unarchiveObjectWithData:data];
                ArbitrarilyComplexStruct acs2{};
                [val2 getValue:&acs2];
                return acs.c == acs2.c;
            });
    ASSERT_FALSE(globalFailure);
}
