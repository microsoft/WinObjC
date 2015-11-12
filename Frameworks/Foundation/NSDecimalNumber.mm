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
#include <Foundation/Foundation.h>

@implementation NSDecimalNumber : NSNumber

/**
 @Status Stub
*/
+ (NSDecimalNumber*)decimalNumberWithString:(NSString*)str {
    UNIMPLEMENTED();
    NSDecimalNumber* ret = [self alloc];
    const char* pStr = [str UTF8String];
    if (strstr(pStr, ".") != NULL) {
        double fVal = strtod(pStr, NULL);
        ret->val.f = fVal;
        ret->type = floatType;
        ret->objCType = "f";
    } else {
        int64_t val;
        val = _strtoi64(pStr, NULL, 10);
        ret->val.i = val;
        ret->type = int64Type;
        ret->objCType = "q";
    }
    return ret;
}

@end
