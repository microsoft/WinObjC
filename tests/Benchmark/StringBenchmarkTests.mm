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

#import <Starboard/SmartTypes.h>
#import "Benchmark.h"

BENCHMARK(String, StringLiteral_Hash, 1000) {
    for (size_t i = 0; i < 10000; ++i) {
        [@"test string" hash];
    }
}

BENCHMARK(String, StringLiteral_IsEqual_Equal, 2000) {
    for (size_t i = 0; i < 10000; ++i) {
        [@"test string" isEqual:@"test string"];
    }
}

BENCHMARK(String, StringLiteral_IsEqual_NotEqual, 1000) {
    for (size_t i = 0; i < 1000; ++i) {
        [@"test string" isEqual:@"test STRING"];
    }
}

BENCHMARK(String, StringNonLiteral_IsEqual_Equal, 1000) {
    NSMutableString* a = [NSMutableString stringWithString:@"test string"];
    NSMutableString* b = [NSMutableString stringWithString:@"test string"];
    for (size_t i = 0; i < 10000; ++i) {
        [a isEqual:b];
    }
}

BENCHMARK(String, StringNonLiteral_IsEqual_NotEqual, 1000) {
    NSMutableString* a = [NSMutableString stringWithString:@"test string"];
    NSMutableString* b = [NSMutableString stringWithString:@"test STRING"];
    for (size_t i = 0; i < 1000; ++i) {
        [a isEqual:b];
    }
}