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

#include <TestFramework.h>
#include <Foundation/Foundation.h>

TEST(NSFoundationGenerics, NSArray) {
    // just test that we can compile generics
    NSMutableArray<NSString*>* strArray = [[NSMutableArray new] autorelease];
    [strArray addObject:@"Hello"];

    // Following assignment should be okay and not genrate any warnings
    NSArray<NSString*>* strArray2 = strArray;
    // NSData* data = strArray2[0]; // this will generate a warning
    strArray2 = nil;
}

// Not testing NSCache because they are all stubs and will generate warnings.

TEST(NSFoundationGenerics, NSDictionary) {
    // just test that we can compile generics
    NSMutableDictionary<NSString*, NSString*>* dict = [[NSMutableDictionary new] autorelease];
    [dict setObject:@"Hello" forKey:@"Greeting"];

    // Following assignment should be okay and not genrate any warnings
    NSDictionary<NSString*, NSString*>* dict2 = dict;
    dict = nil;
}

TEST(NSFoundationGenerics, NSHashTable) {
    NSHashTable<NSString*>* table = [[NSHashTable new] autorelease];
    [table addObject:@"Hello"];
}

TEST(NSFoundationGenerics, NSSet) {
    // just test that we can compile generics
    NSMutableSet<NSString*>* set = [[NSMutableSet new] autorelease];
    [set addObject:@"Hello"];

    // Following assignment should be okay and not genrate any warnings
    NSSet<NSString*>* set2 = set;
    set = nil;
}

TEST(NSFoundationGenerics, NSMapTable) {
    // just test that we can compile generics
    NSMapTable<NSString*, NSString*>* table = [[NSMapTable new] autorelease];
    [table setObject:@"Hello" forKey:@"Greeting"];

    NSDictionary<NSString*, NSString*>* dict = table.dictionaryRepresentation;
}
