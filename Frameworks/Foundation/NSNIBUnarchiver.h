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

#ifndef __NSNIBUNARCHIVER_H
#define __NSNIBUNARCHIVER_H

class Object;
class Item;

@interface NSNibUnarchiver : NSObject {
@public
    char* _nibData;
    DWORD _nibLen;

    DWORD _fixed[10];

    char** _classNames;
    id* _classTypes;
    char** _keyNames;
    Object** _objects;
    Item** _objectItems;
    Object* _curObject[16];

    int _curObjectLevel;

    id _bundle;
}
- (double)decodeDoubleForKey:(id)key;
- (float)decodeFloatForKey:(id)key;
- (instancetype)initForReadingWithData:(NSData*)data;
- (NSObject*)decodeRootObject;
- (NSObject*)decodeObjectForKey:(NSString*)key;
- (BOOL)containsValueForKey:(NSString*)key;
- (BOOL)decodeBoolForKey:(NSString*)key;
- (NSInteger)decodeIntForKey:(NSString*)key;
- (NSInteger)decodeIntegerForKey:(NSString*)key;
- (NSInteger)decodeInt32ForKey:(NSString*)key;
- (void)finishDecoding;
- (void)_setBundle:(NSBundle*)bundle;
- (NSBundle*)_bundle;
- (void)dealloc;
+ (id)unarchiveObjectWithFile:(NSString*)file;
+ (id)unarchiveObjectWithData:(NSData*)data;
@end

#endif
