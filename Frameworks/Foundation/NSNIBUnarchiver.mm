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

#include "Starboard.h"
#include "Foundation/NSDictionary.h"
#include "Foundation/NSMutableString.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSKeyedUnarchiver.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSData.h"
#include "Foundation/NSNull.h"
#include "NSNibUnarchiver.h"

#define NIBOBJ_INT8 0x00
#define NIBOBJ_INT16 0x01
#define NIBOBJ_INT32 0x02
#define NIBOBJ_INT64 0x03
#define NIBOBJ_FALSE 0x04
#define NIBOBJ_TRUE 0x05
#define NIBOBJ_FLOAT 0x06
#define NIBOBJ_DOUBLE 0x07
#define NIBOBJ_DATA 0x08
#define NIBOBJ_NULL 0x09
#define NIBOBJ_UID 0x0A

class NSNibArchiver;

class Item {
public:
    int type;
    void* data;
    int dataLen;
    char* key;
    id cachedId;

    Item() {
        type = 0;
        data = NULL;
        dataLen = 0;
        key = NULL;
        cachedId = nil;
    }

    ~Item() {
        if (data)
            free(data);
    }

    void setItemData(void* pData, int len) {
        data = (void*)malloc(len);
        memcpy(data, pData, len);
        dataLen = len;
    }
};

class Object {
public:
    char* className;
    id classType;

    Item** items;
    int itemCount;
    id cachedId;

    Object() {
        cachedId = nil;
        className = NULL;
        items = NULL;
        itemCount = 0;
    }
};

@implementation NSNibUnarchiver : NSObject
static void pushObject(NSNibUnarchiver* self, Object* pCur) {
    assert(self->_curObjectLevel < 16);
    self->_curObjectLevel++;
    self->_curObject[self->_curObjectLevel] = pCur;
}
static void popObject(NSNibUnarchiver* self) {
    self->_curObjectLevel--;
}
static Object* curObject(NSNibUnarchiver* self) {
    assert(self->_curObjectLevel >= 0);
    return self->_curObject[self->_curObjectLevel];
}

static Item* itemForKey(NSNibUnarchiver* self, const char* keyName) {
    Object* cur = curObject(self);

    for (int i = 0; i < cur->itemCount; i++) {
        if (strcmp(cur->items[i]->key, keyName) == 0) {
            return cur->items[i];
        }
    }

    // EbrDebugLog("Key %s not found in %x\n", keyName, cur);

    return NULL;
}

static Object* objectForUid(NSNibUnarchiver* self, int uid) {
    return self->_objects[uid];
}

static id constructObject(NSNibUnarchiver* self, Object* pObj) {
    if (strcmp(pObj->className, "NSArray") == 0 || strcmp(pObj->className, "NSMutableArray") == 0) {
        id* arrayItems;
        int numArrayItems = 0;

        arrayItems = (id*)malloc(pObj->itemCount * sizeof(id));

        pObj->cachedId = (id)(void*)0xBAADF00D;

        for (int i = 0; i < pObj->itemCount; i++) {
            Item* curItem = pObj->items[i];

            if (strcmp(curItem->key, "UINibEncoderEmptyKey") == 0) {
                id item = idForItem(self, curItem);
                if (item == nil) {
                    // idForItem(self, curItem);
                    // assert(0);
                    // EbrDebugLog("Array initialization failed\n");
                } else {
                    arrayItems[numArrayItems++] = item;
                }
            }
        }

        if (strcmp(pObj->className, "NSArray") == 0) {
            pObj->cachedId = [NSArray arrayWithObjects:arrayItems count:numArrayItems];
        } else {
            pObj->cachedId = [NSMutableArray arrayWithObjects:arrayItems count:numArrayItems];
        }
        free(arrayItems);
    } else if (strcmp(pObj->className, "NSDictionary") == 0 || strcmp(pObj->className, "NSMutableDictionary") == 0) {
        id* keys;
        id* values;
        int numKeys = 0, numValues = 0;

        keys = (id*)malloc(pObj->itemCount * sizeof(id));
        values = (id*)malloc(pObj->itemCount * sizeof(id));

        pObj->cachedId = (id)(void*)0xBAADF00D;

        for (int i = 1; i < pObj->itemCount; i += 2) {
            Item* curItem = pObj->items[i];

            id item = idForItem(self, curItem);
            keys[numKeys++] = item;

            curItem = pObj->items[i + 1];

            item = idForItem(self, curItem);
            values[numValues++] = item;
        }

        if (strcmp(pObj->className, "NSDictionary") == 0) {
            pObj->cachedId = [NSDictionary dictionaryWithObjects:values forKeys:keys count:numKeys];
        } else {
            pObj->cachedId = [NSMutableDictionary dictionaryWithObjects:values forKeys:keys count:numKeys];
        }
        free(values);
        free(keys);
    } else if (strcmp(pObj->className, "NSString") == 0 || strcmp(pObj->className, "NSMutableString") == 0 ||
               strcmp(pObj->className, "NSLocalizableString") == 0) {
        pushObject(self, pObj);
        Item* strContents = itemForKey(self, "NS.bytes");

        if (strcmp(pObj->className, "NSString") == 0) {
            pObj->cachedId = [[[NSString alloc] initWithBytes:strContents->data
                                                       length:strContents->dataLen
                                                     encoding:NSUTF8StringEncoding] autorelease];
        } else {
            pObj->cachedId = [[[NSMutableString alloc] initWithBytes:strContents->data
                                                              length:strContents->dataLen
                                                            encoding:NSUTF8StringEncoding] autorelease];
        }
        popObject(self);
    } else if (strcmp(pObj->className, "NSData") == 0) {
        pushObject(self, pObj);
        Item* dataContents = itemForKey(self, "NS.bytes");
        pObj->cachedId = [NSData dataWithBytes:dataContents->data length:dataContents->dataLen];
        popObject(self);
    } else if (strcmp(pObj->className, "") == 0) {
        pushObject(self, pObj);
        pObj->cachedId = [NSNull null];
        popObject(self);
    } else {
        id classId = pObj->classType; // objc_getClass(pObj->className);
        assert(classId != nil);

        // EbrDebugLog("Instantiating %s\n", pObj->className);
        pObj->cachedId = [classId alloc];

        if ([pObj->cachedId respondsToSelector:@selector(instantiateWithCoder:)]) {
            pushObject(self, pObj);
            id orig = pObj->cachedId;
            pObj->cachedId = [pObj->cachedId instantiateWithCoder:(id)self];
            [orig autorelease];
            popObject(self);
        }

        pushObject(self, pObj);
        if ([pObj->cachedId respondsToSelector:@selector(initWithCoder:)]) {
            pObj->cachedId = [pObj->cachedId initWithCoder:(id)self];
        } else {
            if (pObj->cachedId) {
                EbrDebugLog("%s does not respond to initWithCoder\n", object_getClassName(pObj->cachedId));
            }
        }

        if ([pObj->cachedId respondsToSelector:@selector(awakeAfterUsingCoder:)]) {
            pObj->cachedId = [pObj->cachedId awakeAfterUsingCoder:(id)self];
        }
        [pObj->cachedId autorelease];
        popObject(self);
    }
    return pObj->cachedId;
}

static id idForItem(NSNibUnarchiver* self, Item* item) {
    if (item->cachedId == nil) {
        switch (item->type) {
            case NIBOBJ_UID: {
                Object* pObj = objectForUid(self, *((DWORD*)item->data));

                if (pObj->cachedId == nil) {
                    pObj->cachedId = constructObject(self, pObj);
                }
                item->cachedId = pObj->cachedId;
            } break;

            case NIBOBJ_FALSE:
                item->cachedId = [NSNumber numberWithBool:FALSE];
                break;

            case NIBOBJ_TRUE:
                item->cachedId = [NSNumber numberWithBool:TRUE];
                break;

            case NIBOBJ_FLOAT:
                item->cachedId = [NSNumber numberWithFloat:*((float*)item->data)];
                break;

            case NIBOBJ_DATA:
                item->cachedId = [NSData dataWithBytes:item->data length:item->dataLen];
                break;

            case NIBOBJ_NULL:
                item->cachedId = nil;
                break;

            default:
                assert(0);
                break;
        }
    }

    return item->cachedId;
}

static id getObjectForKey(NSNibUnarchiver* self, const char* keyName) {
    Item* item = itemForKey(self, keyName);
    if (!item)
        return nil;

    return idForItem(self, item);
}

- (instancetype)initForReadingWithData:(NSData*)data {
    _curObjectLevel = -1;

    _nibData = (char*)[data bytes];
    _nibLen = [data length];

    memcpy(_fixed, &_nibData[10], sizeof(_fixed));

    char* _curOffset;

    //  Read classes
    _classNames = (char**)EbrCalloc(_fixed[8], sizeof(char*));
    _classTypes = (id*)EbrCalloc(_fixed[8], sizeof(id));
    _curOffset = &_nibData[_fixed[9]];

    for (unsigned int i = 0; i < _fixed[8]; i++) {
        WORD len = 0;

        memcpy(&len, _curOffset, sizeof(WORD));
        _curOffset += 2;

        BYTE top = len >> 8;
        len &= 0xFF;

        if (len > 0x80) {
            len -= 0x80;
        }
        if (top == 0x81 || len == 0x1b) {
            _curOffset += 4; //  ????
        }

        _classNames[i] = (char*)malloc(len + 1);
        memcpy(_classNames[i], _curOffset, len);

        _classNames[i][len] = 0;
        _classTypes[i] = objc_getClass(_classNames[i]);
        if (_classTypes[i] == nil) {
            EbrDebugLog("Couldn't find class\n");
        }
        _curOffset += len;
    }

    //  Read keys
    _keyNames = (char**)malloc(_fixed[4] * sizeof(char*));
    _curOffset = &_nibData[_fixed[5]];

    for (unsigned int i = 0; i < _fixed[4]; i++) {
        WORD len = 0;

        memcpy(&len, _curOffset, 1);
        _curOffset += 1;

        len -= 0x80;

        _keyNames[i] = (char*)malloc(len + 1);
        memcpy(_keyNames[i], _curOffset, len);
        _keyNames[i][len] = 0;
        _curOffset += len;
    }

    //  Read items
    _objectItems = (Item**)malloc(_fixed[6] * sizeof(Item*));
    _curOffset = &_nibData[_fixed[7]];

    for (unsigned int i = 0; i < _fixed[6]; i++) {
        Item* curItem = new Item();
        _objectItems[i] = curItem;

        WORD itemKeyName = 0;

        memcpy(&itemKeyName, _curOffset, 1);
        _curOffset += 1;

        if (itemKeyName >= 0x80) {
            itemKeyName -= 0x80;
        } else {
            assert(0);
        }
        // itemKeyName -= 0x80;
        curItem->key = _keyNames[itemKeyName];

        WORD itemType = 0;

        memcpy(&itemType, _curOffset, 1);
        _curOffset += 1;

        curItem->type = itemType;

        switch (itemType) {
            case NIBOBJ_UID:
                curItem->setItemData(_curOffset, 4);
                _curOffset += 4;
                break;

            case NIBOBJ_TRUE:
                break;

            case NIBOBJ_FALSE:
                break;

            case NIBOBJ_INT8:
                curItem->setItemData(_curOffset, 1);
                _curOffset += 1;
                break;

            case NIBOBJ_NULL:
                break;

            case NIBOBJ_INT16:
                curItem->setItemData(_curOffset, 2);
                _curOffset += 2;
                break;

            case NIBOBJ_INT32:
                curItem->setItemData(_curOffset, 4);
                _curOffset += 4;
                break;

            case NIBOBJ_INT64:
                curItem->setItemData(_curOffset, 8);
                _curOffset += 8;
                break;

            case NIBOBJ_FLOAT:
                curItem->setItemData(_curOffset, 4);
                _curOffset += 4;
                break;

            case NIBOBJ_DOUBLE:
                curItem->setItemData(_curOffset, 8);
                _curOffset += 8;
                break;

            case NIBOBJ_DATA: {
                WORD itemDataLen = 0;

                memcpy(&itemDataLen, _curOffset, 1);
                _curOffset += 1;

                if (itemDataLen >= 0x80) {
                    itemDataLen -= 0x80;
                } else {
                    WORD _2nd = 0;
                    memcpy(&_2nd, _curOffset, 1);

                    if (_2nd < 0x80) {
                        assert(0);
                    }
                    _2nd -= 0x80;
                    _curOffset += 1;
                    itemDataLen |= (_2nd << 7);
                }

                curItem->setItemData(_curOffset, itemDataLen);
                _curOffset += itemDataLen;
                ;
            } break;

            default:
                assert(0);
                break;
        }
    }

    //  Read objects
    _objects = (Object**)malloc(_fixed[2] * sizeof(Object*));
    _curOffset = &_nibData[_fixed[3]];

    for (unsigned int i = 0; i < _fixed[2]; i++) {
        Object* curObject = new Object();
        _objects[i] = curObject;

        WORD objectClassName = 0;

        memcpy(&objectClassName, _curOffset, 1);
        _curOffset += 1;
        if (objectClassName < 0x80) {
            assert(0);
        }
        objectClassName -= 0x80;
        curObject->className = _classNames[objectClassName];
        curObject->classType = _classTypes[objectClassName];
        if (curObject->className == NULL || objectClassName >= _fixed[8]) {
            assert(0);
        }

        WORD objectItemStart = 0;

        memcpy(&objectItemStart, _curOffset, 1);
        _curOffset += 1;
        if (objectItemStart < 0x80) {
            WORD nextItem = 0;

            memcpy(&nextItem, _curOffset, 1);
            _curOffset += 1;
            if (nextItem < 0x80) {
                assert(0);
            }
            nextItem -= 0x80;
            objectItemStart |= (nextItem << 7);
        } else {
            objectItemStart -= 0x80;
        }

        curObject->items = &_objectItems[objectItemStart];

        WORD objectItemCount = 0;

        memcpy(&objectItemCount, _curOffset, 1);
        _curOffset += 1;
        if (objectItemCount < 0x80) {
            WORD nextItem = 0;

            memcpy(&nextItem, _curOffset, 1);
            _curOffset += 1;
            if (nextItem < 0x80) {
                assert(0);
            }
            nextItem -= 0x80;
            objectItemCount |= (nextItem << 7);
        } else {
            objectItemCount -= 0x80;
        }
        curObject->itemCount = objectItemCount;
    }

    pushObject(self, _objects[0]);
    return self;
}

- (NSObject*)decodeRootObject {
    assert(0);
    return nil;
}

- (NSObject*)decodeObjectForKey:(NSString*)key {
    id ret = getObjectForKey(self, [key UTF8String]);

    if ([ret isKindOfClass:[NSNull class]]) {
        return nil;
    }

    return ret;
}

- (BOOL)containsValueForKey:(NSString*)key {
    Item* pItem = itemForKey(self, [key UTF8String]);
    if (!pItem)
        return FALSE;

    return TRUE;
}

- (BOOL)decodeBoolForKey:(NSString*)key {
    return [self decodeInt32ForKey:key] != 0;
}

- (NSInteger)decodeIntForKey:(NSString*)key {
    return [self decodeInt32ForKey:key];
}

- (NSInteger)decodeIntegerForKey:(NSString*)key {
    return [self decodeInt32ForKey:key];
}

- (NSInteger)decodeInt32ForKey:(NSString*)key {
    Item* pItem = itemForKey(self, [key UTF8String]);
    if (!pItem)
        return 0;

    DWORD ret = 0;
    switch (pItem->type) {
        case NIBOBJ_INT8:
            ret = *((BYTE*)pItem->data);
            break;

        case NIBOBJ_INT16:
            ret = *((WORD*)pItem->data);
            break;

        case NIBOBJ_TRUE:
            ret = TRUE;
            break;

        case NIBOBJ_FALSE:
            ret = FALSE;
            break;

        case NIBOBJ_INT32:
            ret = *((DWORD*)pItem->data);
            break;

        case NIBOBJ_INT64:
            EbrDebugLog("Warning: 64-bit NIB item truncated to 32 bits\n");
            ret = *((DWORD*)pItem->data);
            break;

        default:
            assert(0);
            break;
    }
    return ret;
}

- (float)decodeFloatForKey:(id)key {
    Item* pItem = itemForKey(self, [key UTF8String]);
    if (!pItem)
        return 0;

    float ret = 0;
    switch (pItem->type) {
        case NIBOBJ_FLOAT:
            ret = *((float*)pItem->data);
            break;

        case NIBOBJ_DOUBLE:
            ret = (float)(*((double*)pItem->data));
            break;

        default:
            assert(0);
            break;
    }
    return ret;
}

- (double)decodeDoubleForKey:(id)key {
    Item* pItem = itemForKey(self, [key UTF8String]);
    if (!pItem)
        return 0;

    double ret = 0;
    switch (pItem->type) {
        case NIBOBJ_FLOAT:
            ret = *((float*)pItem->data);
            break;

        case NIBOBJ_DOUBLE:
            ret = *((double*)pItem->data);
            break;

        default:
            assert(0);
            break;
    }
    return ret;
}

+ (id)unarchiveObjectWithFile:(NSString*)file {
    id data = [NSData dataWithContentsOfFile:file];

    if ([data length] == 0)
        return nil;

    assert(0);

    return nil;
}

+ (id)unarchiveObjectWithData:(NSData*)data {
    if ([data length] == 0)
        return nil;

    assert(0);

    return nil;
}

- (void)finishDecoding {
}

- (void)_setBundle:(NSBundle*)bundle {
    _bundle = bundle;
}

- (NSBundle*)_bundle {
    return _bundle;
}

- (void)dealloc {
    if (_classNames) {
        for (unsigned int i = 0; i < _fixed[8]; i++) {
            free(_classNames[i]);
        }
        free(_classNames);
    }

    if (_keyNames) {
        for (unsigned int i = 0; i < _fixed[4]; i++) {
            free(_keyNames[i]);
        }
        free(_keyNames);
    }

    if (_objectItems) {
        for (unsigned int i = 0; i < _fixed[6]; i++) {
            delete _objectItems[i];
        }
        free(_objectItems);
    }

    if (_objects) {
        for (unsigned int i = 0; i < _fixed[2]; i++) {
            delete _objects[i];
        }
        free(_objects);
    }

    _bundle = nil;

    [super dealloc];
}

@end
