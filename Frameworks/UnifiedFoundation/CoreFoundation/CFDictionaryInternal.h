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

#pragma once

#include "Hash.h"
#include <vector>

typedef std::pair<const void*, const void*> cf_dictpair;
typedef std::vector<cf_dictpair> cf_array;

class ICFDict {
public:
    uint32_t numKeys;
    ICFDict() : numKeys(0) {
    }

    virtual uint32_t getHash(const void* key) = 0;
    virtual bool isEqual(const void* val1, const void* val2) = 0;
    virtual const void* retainKey(const void* key) = 0;
    virtual const void* releaseKey(const void* key) = 0;
    virtual const void* releaseVal(const void* val) = 0;
    virtual const void* retainVal(const void* val) = 0;
};

class cf_dict_array {
private:
    const void* singleKey;
    const void* singleValue;
    bool hasItem;
    cf_array* manyItems;

public:
    cf_dict_array();
    void destroy();
    int count();
    const void* keyAtIndex(int idx);
    const void* valueAtIndex(int idx);
    bool objectForKey(const void* key, const void** retVal, ICFDict* dict);
    void setObjectForKey(const void* object, const void* key, ICFDict* dict, bool retain);
    bool removeObjectForKey(const void* key, ICFDict* dict);
};

struct dictIterator;
#include "khash.h"

KHASH_DECLARE(cf_dictionary, khint32_t, cf_dict_array);
typedef khash_t(cf_dictionary) cf_dictionary;

class EbrDictionary : public cf_dictionary, public ICFDict {
public:
    EbrDictionary();
    ~EbrDictionary();
    void setObjectKey(const void* key, const void* object, bool retain = true);
    bool objectForKey(const void* key, const void*& ret);
    void removeKey(const void* key);
    void removeAllValues();
    void initIterator(struct dictIterator* iter);
    bool getNextKey(struct dictIterator* iter, const void*& keyRet);
    bool getNextValue(struct dictIterator* iter, const void*& valueRet);
    void getKeysAndValues(const void** keys, const void** values);
    uint32_t getCount();
};

int CFNSDescriptorCompare(id obj1, id obj2, void* descriptors);
int CFNSBlockCompare(id obj1, id obj2, void* block);