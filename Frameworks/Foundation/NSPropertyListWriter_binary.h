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

#include <vector>

@interface NSPropertyListWriter_Binary : NSObject {
@public
    id _dest;
    CFMutableDictionaryRef _objList;
    id objectsToDoList;
    id root;

    // Number of bytes per object table index
    unsigned int index_size;
    // Number of bytes per object table entry
    unsigned int offset_size;

    unsigned int table_start;
    unsigned int table_size;
    unsigned int* table;

    char* outBuf;
    int outBufLen;
    int outBufMaxLen;
}
- (NSPropertyListWriter_Binary*)initWithPropertyList:(id)aPropertyList intoData:(NSMutableData*)destination;
- (void)dealloc;
- (NSMutableData*)data;
- (void)setup;
- (void)cleanup;
- (void)writeObjects;
-(void) markOffset:(unsigned int)offset for:(id)object;
- (void)writeObjectTable;
- (void)writeMetaData;
- (unsigned)indexForObject:(id)object;
- (void)storeIndex:(int)index;
- (void)storeCount:(int)count;
- (void)storeData:(id)data;
- (void)storeString:(NSString*)string;
- (void)storeNumber:(NSNumber*)number;
- (void)storeDate:(id)date;
- (void)storeArray:(id)array;
- (void)storeDictionary:(id)dict;
- (void)storeObject:(id)object;
- (void)generate;
+ (void)serializePropertyList:(id)aPropertyList intoData:(NSMutableData*)destination;
@end
