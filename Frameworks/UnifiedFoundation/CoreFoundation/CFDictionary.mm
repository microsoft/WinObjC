/* The MIT License

Copyright (c) 2008, 2009, 2011 by Attractive Chaos <attractor@live.co.uk>
Copyright (c) 2015 Microsoft Corporation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "Starboard.h"

#include "CoreFoundation/CFDictionary.h"
#include "Foundation/NSDictionary.h"
#include "Foundation/NSMutableDictionary.h"

#include "CFDictionaryInternal.h"

#include <sys/stat.h>
#include <new>

class __CFDictionary;

const void* CFNSCopy(CFAllocatorRef allocator, const void* obj) {
    return [static_cast<id>(obj) copy];
}

const void* CFNSRetain(CFAllocatorRef allocator, const void* obj) {
    return [static_cast<id>(obj) retain];
}

void CFNSRelease(CFAllocatorRef allocator, const void* obj) {
    [static_cast<id>(obj) release];
}

Boolean CFNSEqual(const void* obj1, const void* obj2) {
    return [static_cast<id>(obj1) isEqual:static_cast<id>(obj2)];
}

CFHashCode CFNSHash(const void* obj1) {
    return [static_cast<id>(obj1) hash];
}

int CFNSComparer(id obj1, id obj2, void* context) {
    return [obj1 compare:obj2];
}

int CFNSDescriptorCompare(id obj1, id obj2, void* descriptors) {
    id idDescriptors = static_cast<id>(descriptors);
    int count = [idDescriptors count];

    for (int i = 0; i < count; i++) {
        id curDesc = [idDescriptors objectAtIndex:i];

        int result = [curDesc compareObject:obj1 toObject:obj2];
        if (result != 0) {
            return result;
        }
    }

    return 0;
}

int CFNSBlockCompare(id obj1, id obj2, void* block) {
    int (^blockFunc)(id, id) = (int (^)(id, id))block;
    int ret = (int)blockFunc(obj1, obj2);

    return ret;
}

const CFDictionaryKeyCallBacks kCFTypeDictionaryKeyCallBacks = {
    0, CFNSRetain, CFNSRelease, 0, CFNSEqual, CFNSHash,
};
const CFDictionaryValueCallBacks kCFTypeDictionaryValueCallBacks = {
    0, CFNSRetain, CFNSRelease, 0, CFNSEqual,
};

const CFDictionaryKeyCallBacks kNSTypeDictionaryKeyCallBacks = { 0, CFNSRetain, CFNSRelease, 0, CFNSEqual, CFNSHash };
const CFDictionaryValueCallBacks kNSTypeDictionaryValueCallBacks = {
    0, CFNSRetain, CFNSRelease, 0, CFNSEqual,
};

struct dictIterator {
    khiter_t kIt;
    cf_dict_array* arr;
    int curIndex;
};

static kh_inline kh_cf_dictionary_t* kh_init_cf_dictionary(void) {
    return (kh_cf_dictionary_t*)kcalloc(1, sizeof(kh_cf_dictionary_t));
}
static kh_inline void kh_init_ptr_cf_dictionary(kh_cf_dictionary_t* h) {
    memset(h, 0, sizeof(kh_cf_dictionary_t));
}
static kh_inline void kh_destroy_cf_dictionary(kh_cf_dictionary_t* h) {
    if (h) {
        kfree((void*)h->keys);
        kfree(h->flags);
        kfree((void*)h->vals);
        kfree(h);
    }
}
static kh_inline void kh_destroy_ptr_cf_dictionary(kh_cf_dictionary_t* h) {
    if (h) {
        kfree((void*)h->keys);
        kfree(h->flags);
        kfree((void*)h->vals);
    }
}
static kh_inline void kh_clear_cf_dictionary(kh_cf_dictionary_t* h) {
    if (h && h->flags) {
        memset(h->flags, 0xaa, __ac_fsize(h->n_buckets) * sizeof(khint32_t));
        h->size = h->n_occupied = 0;
    }
}
static kh_inline khint_t kh_get_cf_dictionary(const kh_cf_dictionary_t* h, khint32_t key) {
    if (h->n_buckets) {
        khint_t k, i, last, mask, step = 0;
        mask = h->n_buckets - 1;
        k = kh_int_hash_func(key);
        i = k & mask;
        last = i;
        while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !kh_int_hash_equal(h->keys[i], key))) {
            i = (i + (++step)) & mask;
            if (i == last)
                return h->n_buckets;
        }
        return __ac_iseither(h->flags, i) ? h->n_buckets : i;
    } else
        return 0;
}
static kh_inline int kh_resize_cf_dictionary(kh_cf_dictionary_t* h, khint_t new_n_buckets) { /* This function uses 0.25*n_buckets bytes of
                                                                                                working space instead of
                                                                                                [sizeof(key_t+val_t)+.25]*n_buckets. */
    khint32_t* new_flags = 0;
    khint_t j = 1;
    {
        kroundup32(new_n_buckets);
        if (new_n_buckets < 4)
            new_n_buckets = 4;

        if (h->size >= (khint_t)(new_n_buckets * __ac_HASH_UPPER + 0.5)) {
            j = 0; /* requested size is too small */
        } else { /* hash table size to be changed (shrink or expand); rehash */
            new_flags = (khint32_t*)kmalloc(__ac_fsize(new_n_buckets) * sizeof(khint32_t));
            if (!new_flags)
                return -1;
            memset(new_flags, 0xaa, __ac_fsize(new_n_buckets) * sizeof(khint32_t));
            if (h->n_buckets < new_n_buckets) { /* expand */
                khint32_t* new_keys = (khint32_t*)krealloc((void*)h->keys, new_n_buckets * sizeof(khint32_t));

                if (!new_keys)
                    return -1;
                h->keys = new_keys;

                if (1) {
                    cf_dict_array* new_vals = (cf_dict_array*)krealloc((void*)h->vals, new_n_buckets * sizeof(cf_dict_array));
                    if (!new_vals)
                        return -1;
                    h->vals = new_vals;
                }
            } /* otherwise shrink */
        }
    }
    if (j) { /* rehashing is needed */
        for (j = 0; j != h->n_buckets; ++j) {
            if (__ac_iseither(h->flags, j) == 0) {
                khint32_t key = h->keys[j];
                cf_dict_array val;
                khint_t new_mask;
                new_mask = new_n_buckets - 1;
                if (1)
                    val = h->vals[j];
                __ac_set_isdel_true(h->flags, j);
                while (1) { /* kick-out process; sort of like in Cuckoo hashing */
                    khint_t k, i, step = 0;
                    k = kh_int_hash_func(key);
                    i = k & new_mask;
                    while (!__ac_isempty(new_flags, i))
                        i = (i + (++step)) & new_mask;
                    __ac_set_isempty_false(new_flags, i);
                    if (i < h->n_buckets && __ac_iseither(h->flags, i) == 0) { /* kick out the existing element */
                        {
                            khint32_t tmp = h->keys[i];
                            h->keys[i] = key;
                            key = tmp;
                        }
                        if (1) {
                            cf_dict_array tmp = h->vals[i];
                            h->vals[i] = val;
                            val = tmp;
                        }
                        __ac_set_isdel_true(h->flags, i); /* mark it as deleted in the old hash table */
                    } else { /* write the element and jump out of the loop */
                        h->keys[i] = key;
                        if (1)
                            h->vals[i] = val;
                        break;
                    }
                }
            }
        }
        if (h->n_buckets > new_n_buckets) { /* shrink the hash table */
            h->keys = (khint32_t*)krealloc((void*)h->keys, new_n_buckets * sizeof(khint32_t));
            if (1)
                h->vals = (cf_dict_array*)krealloc((void*)h->vals, new_n_buckets * sizeof(cf_dict_array));
        }
        kfree(h->flags); /* free the working space */
        h->flags = new_flags;
        h->n_buckets = new_n_buckets;
        h->n_occupied = h->size;
        h->upper_bound = (khint_t)(h->n_buckets * __ac_HASH_UPPER + 0.5);
    }
    return 0;
}

static kh_inline khint_t kh_put_cf_dictionary(kh_cf_dictionary_t* h, khint32_t key, int* ret) {
    khint_t x;

    if (h->n_occupied >= h->upper_bound) { /* update the hash table */
        if (h->n_buckets > (h->size << 1)) {
            if (kh_resize_cf_dictionary(h, h->n_buckets - 1) < 0) { /* clear "deleted" elements */
                *ret = -1;
                return h->n_buckets;
            }
        } else if (kh_resize_cf_dictionary(h, h->n_buckets + 1) < 0) { /* expand the hash table */
            *ret = -1;
            return h->n_buckets;
        }
    } /* TODO: to implement automatically shrinking; resize() already support
         shrinking */
    {
        khint_t k, i, site, last, mask = h->n_buckets - 1, step = 0;
        x = site = h->n_buckets;
        k = kh_int_hash_func(key);
        i = k & mask;
        if (__ac_isempty(h->flags, i)) {
            x = i; /* for speed up */
        } else {
            last = i;
            while (!__ac_isempty(h->flags, i) && (__ac_isdel(h->flags, i) || !kh_int_hash_equal(h->keys[i], key))) {
                if (__ac_isdel(h->flags, i))
                    site = i;
                i = (i + (++step)) & mask;
                if (i == last) {
                    x = site;
                    break;
                }
            }
            if (x == h->n_buckets) {
                if (__ac_isempty(h->flags, i) && site != h->n_buckets) {
                    x = site;
                } else
                    x = i;
            }
        }
    }

    if (__ac_isempty(h->flags, x)) { /* not present at all */
        h->keys[x] = key;
        __ac_set_isboth_false(h->flags, x);
        ++h->size;
        ++h->n_occupied;
        *ret = 1;
    } else if (__ac_isdel(h->flags, x)) { /* deleted */
        h->keys[x] = key;
        __ac_set_isboth_false(h->flags, x);
        ++h->size;
        *ret = 2;
    } else
        *ret = 0; /* Don't touch h->keys[x] if present and not deleted */

    return x;
}

static kh_inline void kh_del_cf_dictionary(kh_cf_dictionary_t* h, khint_t x) {
    if (x != h->n_buckets && !__ac_iseither(h->flags, x)) {
        __ac_set_isdel_true(h->flags, x);
        --h->size;
    }
}

EbrDictionary::EbrDictionary() {
    kh_init_ptr(cf_dictionary, this);
}

EbrDictionary::~EbrDictionary() {
    kh_destroy_ptr(cf_dictionary, this);
}

void EbrDictionary::setObjectKey(const void* key, const void* object, bool retain) {
    assert(key != 0);

    //  Call retain function on object
    if (retain)
        object = retainVal(object);

    //  Get key hash
    uint32_t keyHash = getHash(key);

    //  Find array for key
    cf_dict_array* arr;
    khiter_t k = kh_get(cf_dictionary, this, keyHash);
    if (k != kh_end(this) && (arr = &kh_value(this, k))) {
        //  Existing array - value already exists?
        arr->setObjectForKey(object, key, this, retain);
    } else {
        //  New array
        cf_dict_array arr, *arrPtr;
        int ret;

        k = kh_put(cf_dictionary, this, keyHash, &ret);
        arrPtr = &kh_value(this, k);
        memset(arrPtr, 0, sizeof(cf_dict_array));
        arrPtr->setObjectForKey(object, key, this, retain);
    }
}

bool EbrDictionary::objectForKey(const void* key, const void*& ret) {
    if (key == 0) {
        assert(0);
    }

    //  Get key hash
    uint32_t keyHash = getHash(key);

    //  Find array for key
    cf_dict_array* arr;
    khiter_t k = kh_get(cf_dictionary, this, keyHash);
    if (k != kh_end(this) && (arr = &kh_value(this, k))) {
        bool retVal = arr->objectForKey(key, &ret, this);

        return retVal;
    }

    return false;
}

void EbrDictionary::removeKey(const void* key) {
    assert(key != 0);

    //  Get key hash
    uint32_t keyHash = getHash(key);

    //  Find array for key
    cf_dict_array* arr;
    khiter_t k = kh_get(cf_dictionary, this, keyHash);
    if (k != kh_end(this) && (arr = &kh_value(this, k))) {
        bool empty = arr->removeObjectForKey(key, this);
        if (empty) {
            arr->destroy();
            kh_del(cf_dictionary, this, k);
        }
    }
}

void EbrDictionary::removeAllValues() {
    int count = getCount();
    const void** values = (const void**)EbrMalloc(sizeof(void*) * count);
    const void** keys = (const void**)EbrMalloc(sizeof(const void*) * count);

    getKeysAndValues(keys, values);
    khiter_t k;
    for (k = kh_begin(this); k != kh_end(this); ++k) {
        if (kh_exist(this, k)) {
            cf_dict_array* arr = &kh_value(this, k);
            arr->destroy();
        }
    }
    kh_clear(cf_dictionary, this);
    numKeys = 0;

    for (int i = 0; i < count; i++) {
        releaseKey(keys[i]);
        releaseVal(values[i]);
    }

    EbrFree(keys);
    EbrFree(values);
}

void EbrDictionary::initIterator(struct dictIterator* iter) {
    assert(sizeof(struct dictIterator) <= 5 * sizeof(const void*));
    iter->kIt = -1;
    iter->arr = NULL;
}

bool EbrDictionary::getNextKey(struct dictIterator* iter, const void*& keyRet) {
    if (iter->kIt == kh_end(this))
        return false;

    if (iter->arr == NULL) {
        for (;;) {
            iter->kIt++;
            if (iter->kIt == kh_end(this)) {
                return false;
            }

            if (kh_exist(this, iter->kIt)) {
                iter->arr = &kh_value(this, iter->kIt);
                break;
            }
        }
        iter->curIndex = 0;
    }

    keyRet = iter->arr->keyAtIndex(iter->curIndex);
    iter->curIndex++;

    if (iter->curIndex >= iter->arr->count()) {
        iter->arr = NULL;
    }

    return true;
}

bool EbrDictionary::getNextValue(struct dictIterator* iter, const void*& valueRet) {
    if (iter->kIt == kh_end(this))
        return false;

    if (iter->arr == NULL) {
        for (;;) {
            iter->kIt++;
            if (iter->kIt == kh_end(this)) {
                return false;
            }

            if (kh_exist(this, iter->kIt)) {
                iter->arr = &kh_value(this, iter->kIt);
                break;
            }
        }
        iter->curIndex = 0;
    }

    valueRet = iter->arr->valueAtIndex(iter->curIndex);
    iter->curIndex++;

    if (iter->curIndex >= iter->arr->count()) {
        iter->arr = NULL;
    }

    return true;
}

void EbrDictionary::getKeysAndValues(const void** keys, const void** values) {
    uint32_t numValues = 0;

    //  Grab all keys and values
    khiter_t k;
    for (k = kh_begin(this); k != kh_end(this); ++k) {
        if (kh_exist(this, k)) {
            cf_dict_array* arr = &kh_value(this, k);
            int count = arr->count();
            for (int i = 0; i < count; i++) {
                assert(numValues <= numKeys);
                if (keys)
                    keys[numValues] = arr->keyAtIndex(i);
                if (values)
                    values[numValues] = arr->valueAtIndex(i);

                numValues++;
            }
        }
    }

    assert(numValues == numKeys);
}

uint32_t EbrDictionary::getCount() {
    return numKeys;
}

class __CFDictionary : public EbrDictionary {
private:
    CFDictionaryKeyCallBacks keyCallbacks;
    CFDictionaryValueCallBacks valueCallbacks;
    CFAllocatorRef allocator;

public:
    __CFDictionary(const CFDictionaryKeyCallBacks* k, const CFDictionaryValueCallBacks* v) {
        if (k) {
            keyCallbacks = *k;
        } else
            memset(&keyCallbacks, 0, sizeof(keyCallbacks));
        if (v) {
            valueCallbacks = *v;
        } else
            memset(&valueCallbacks, 0, sizeof(valueCallbacks));
    }

    ~__CFDictionary() {
    }

    void copyFrom(__CFDictionary* dict) {
        kh_resize(cf_dictionary, this, dict->n_buckets);
        khiter_t k;
        for (k = kh_begin(dict); k != kh_end(dict); ++k) {
            if (kh_exist(dict, k)) {
                cf_dict_array* arr = &kh_value(dict, k);
                int count = arr->count();
                for (int i = 0; i < count; i++) {
                    const void* key = arr->keyAtIndex(i);
                    const void* val = arr->valueAtIndex(i);
                    setObjectKey(key, val);
                }
            }
        }
    }

    uint32_t getHash(const void* key) {
        if (keyCallbacks.hash != 0) {
            if (keyCallbacks.hash == kNSTypeDictionaryKeyCallBacks.hash) {
                return CFNSHash(key);
            } else {
                return keyCallbacks.hash(key);
            }
        } else {
            return (uint32_t)key;
        }
    }

    bool isEqual(const void* val1, const void* val2) {
        if (keyCallbacks.equal != 0) {
            if (keyCallbacks.equal == kNSTypeDictionaryKeyCallBacks.equal) {
                return CFNSEqual(val1, val2) != 0;
            } else {
                return (keyCallbacks.equal(val1, val2)) != 0;
            }
        } else {
            return val1 == val2;
        }
    }

    const void* retainKey(const void* key) {
        if (keyCallbacks.retain != 0) {
            if (keyCallbacks.retain == kNSTypeDictionaryKeyCallBacks.retain) {
                key = keyCallbacks.retain(allocator, key);
            } else {
                key = keyCallbacks.retain(allocator, key);
            }
        }

        return key;
    }

    const void* releaseKey(const void* key) {
        if (keyCallbacks.release != 0) {
            if (keyCallbacks.release == kNSTypeDictionaryKeyCallBacks.release) {
                CFNSRelease(allocator, key);
            } else {
                keyCallbacks.release(allocator, key);
            }
        }

        return key;
    }

    const void* releaseVal(const void* val) {
        if (valueCallbacks.release != 0) {
            if (valueCallbacks.release == kCFTypeDictionaryValueCallBacks.release) {
                CFNSRelease(allocator, val);
            } else {
                valueCallbacks.release(allocator, val);
            }
        }

        return val;
    }

    const void* retainVal(const void* val) {
        if (valueCallbacks.retain != 0) {
            if (valueCallbacks.retain == kCFTypeDictionaryValueCallBacks.retain) {
                val = (void*)CFNSRetain(allocator, val);
            } else {
                val = valueCallbacks.retain(allocator, val);
            }
        }

        return val;
    }
};

cf_dict_array::cf_dict_array() {
    hasItem = false;
    manyItems = NULL;
}

void cf_dict_array::destroy() {
    if (manyItems) {
        delete manyItems;
        manyItems = NULL;
        hasItem = false;
    }
}

int cf_dict_array::count() {
    if (!manyItems) {
        if (hasItem)
            return 1;

        return 0;
    }

    return manyItems->size();
}

const void* cf_dict_array::keyAtIndex(int idx) {
    if (!manyItems) {
        assert(idx == 0 && hasItem == true);
        return singleKey;
    }

    return (manyItems->begin() + idx)->first;
}

const void* cf_dict_array::valueAtIndex(int idx) {
    if (!manyItems) {
        assert(idx == 0 && hasItem == true);
        return singleValue;
    }

    return (manyItems->begin() + idx)->second;
}

void cf_dict_array::setObjectForKey(const void* object, const void* key, ICFDict* dict, bool retain) {
    if (manyItems) {
        cf_array::iterator curKey = manyItems->begin();

        while (curKey != manyItems->end()) {
            if (dict->isEqual(key, curKey->first)) {
                break;
            }

            curKey++;
        }

        if (curKey != manyItems->end()) {
            //  Key already exists - release existing value and set new value
            dict->releaseVal(curKey->second);
            curKey->second = object;
        } else {
            //  Key doesn't exist, just a hash collision - add to the array
            if (retain) {
                key = dict->retainKey(key);
            }
            manyItems->push_back(cf_dictpair(key, object));
            dict->numKeys++;
        }
    } else {
        if (hasItem) {
            if (dict->isEqual(key, singleKey)) {
                //  Same key, switch objects
                dict->releaseVal(singleValue);
                singleValue = object;
            } else {
                //  Multiple keys on same hash
                if (retain) {
                    key = dict->retainKey(key);
                }
                manyItems = new cf_array();

                manyItems->push_back(cf_dictpair(key, object));
                manyItems->push_back(cf_dictpair(singleKey, singleValue));
                dict->numKeys++;
            }
        } else {
            //  Adding item
            if (retain) {
                key = dict->retainKey(key);
            }

            singleKey = key;
            singleValue = object;
            dict->numKeys++;

            hasItem = true;
        }
    }
}

bool cf_dict_array::objectForKey(const void* key, const void** retVal, ICFDict* dict) {
    if (manyItems) {
        //  Found array
        cf_array::iterator curKey = manyItems->begin();

        while (curKey != manyItems->end()) {
            if (dict->isEqual(key, curKey->first)) {
                //  Found key
                *retVal = (void*)curKey->second;
                return true;
            }

            curKey++;
        }

        return false;
    } else {
        assert(hasItem == true);

        if (dict->isEqual(key, singleKey)) {
            //  Found key
            *retVal = (void*)singleValue;
            return true;
        }

        return false;
    }
}

bool cf_dict_array::removeObjectForKey(const void* key, ICFDict* dict) {
    if (manyItems) {
        //  Found array
        cf_array::iterator curKey = manyItems->begin();

        while (curKey != manyItems->end()) {
            if (dict->isEqual(key, curKey->first)) {
                const void* objKey = curKey->first;
                const void* objVal = curKey->second;
                bool isEmpty = false;

                manyItems->erase(curKey);
                if (manyItems->empty()) {
                    isEmpty = true;
                }

                dict->releaseKey(objKey);
                dict->releaseVal(objVal);

                dict->numKeys--;

                return isEmpty;
            }

            curKey++;
        }

        return false;
    } else {
        assert(hasItem == true);
        if (dict->isEqual(key, singleKey)) {
            //  Found key
            dict->releaseKey(singleKey);
            dict->releaseVal(singleValue);
            dict->numKeys--;
            return true; //  We are empty
        }

        return false;
    }
}

/**
 @Status Interoperable
*/
CFMutableDictionaryRef CFDictionaryCreateMutable(CFAllocatorRef allocator,
                                                 CFIndex max,
                                                 const CFDictionaryKeyCallBacks* keyCallbacks,
                                                 const CFDictionaryValueCallBacks* valueCallbacks) {
    NSDictionary* ret = [NSMutableDictionary alloc];
    ret->dict = new (ret->_dictSpace) __CFDictionary(keyCallbacks, valueCallbacks);

    return (CFMutableDictionaryRef)ret;
}

/**
 @Status Interoperable
*/
void CFDictionarySetValue(CFMutableDictionaryRef dict, const void* key, const void* value) {
    ((NSDictionary*)(dict))->dict->setObjectKey(key, value, true);
}

void CFDictionarySetValueUnretained(CFMutableDictionaryRef dict, const void* key, const void* value) {
    ((NSDictionary*)(dict))->dict->setObjectKey(key, value, false);
}

void CFDictionarySetValueExport(CFMutableDictionaryRef dict, const void* key, const void* value) {
    CFDictionarySetValue(dict, key, value);
}

/**
 @Status Interoperable
*/
CFDictionaryRef CFDictionaryCreate(void* allocator,
                                   const void** keys,
                                   void** values,
                                   CFIndex count,
                                   CFDictionaryKeyCallBacks* keyCallbacks,
                                   CFDictionaryValueCallBacks* valueCallbacks) {
    NSDictionary* ret = [NSDictionary alloc];
    ret->dict = new (ret->_dictSpace) __CFDictionary(keyCallbacks, valueCallbacks);

    for (unsigned i = 0; i < count; i++) {
        ((NSDictionary*)(ret))->dict->setObjectKey(keys[i], values[i]);
    }

    return (CFDictionaryRef)ret;
}

/**
 @Status Interoperable
*/
void CFDictionaryAddValue(CFDictionaryRef dict, const void* key, void* value) {
    const void* ret;

    if (!((NSDictionary*)(dict))->dict->objectForKey(key, ret)) {
        ((NSDictionary*)(dict))->dict->setObjectKey(key, value);
    }
}

/**
 @Status Interoperable
*/
Boolean CFDictionaryContainsKey(CFDictionaryRef dict, const void* key) {
    const void* ret;

    return ((NSDictionary*)(dict))->dict->objectForKey(key, ret);
}

/**
 @Status Interoperable
*/
void CFDictionaryRemoveValue(CFMutableDictionaryRef dict, const void* key) {
    ((NSDictionary*)(dict))->dict->removeKey(key);
}

/**
 @Status Interoperable
*/
CFIndex CFDictionaryGetCount(CFDictionaryRef dict) {
    return ((NSDictionary*)(dict))->dict->getCount();
}

/**
 @Status Interoperable
*/
void CFDictionaryRemoveAllValues(CFMutableDictionaryRef dict) {
    if (((NSDictionary*)(dict))->dict == NULL)
        return;

    ((NSDictionary*)(dict))->dict->removeAllValues();
}

/**
 @Status Interoperable
*/
const void* CFDictionaryGetValue(CFDictionaryRef dict, const void* key) {
    if (dict == nil) {
        return 0;
    }

    const void* ret = nil;

    ((NSDictionary*)(dict))->dict->objectForKey(key, ret);

    return ret;
}

/**
 @Status Interoperable
*/
Boolean CFDictionaryGetValueIfPresent(CFDictionaryRef dict, const void* key, const void** valRet) {
    const void* ret;

    if (((NSDictionary*)(dict))->dict->objectForKey(key, ret)) {
        *valRet = ret;
        return 1;
    }

    return 0;
}

/**
 @Status Interoperable
*/
void CFDictionaryApplyFunction(CFDictionaryRef dict, CFDictionaryApplierFunction function, void* context) {
    CFIndex count = CFDictionaryGetCount(dict);

    const void** keys = (const void**)EbrMalloc(count * sizeof(const void*));
    const void** vals = (const void**)EbrMalloc(count * sizeof(const void*));
    CFDictionaryGetKeysAndValues(dict, (const void**)keys, (const void**)vals);

    for (unsigned i = 0; i < count; i++) {
        function(keys[i], vals[i], context);
    }

    EbrFree(keys);
    EbrFree(vals);
}

/**
 @Status Interoperable
*/
void CFDictionaryGetKeysAndValues(CFDictionaryRef dict, const void** pKeys, const void** pValues) {
    ((NSDictionary*)(dict))->dict->getKeysAndValues((const void**)pKeys, pValues);
}

void CFDictionaryGetKeyEnumerator(CFDictionaryRef dict, void* enumeratorHolder) {
    ((NSDictionary*)(dict))->dict->initIterator((dictIterator*)enumeratorHolder);
}

int CFDictionaryGetNextKey(CFDictionaryRef dict, void* enumeratorHolder, id* ret, int count) {
    int retCount = 0;

    while (count--) {
        if (((NSDictionary*)(dict))->dict->getNextKey((dictIterator*)enumeratorHolder, (const void*&)ret[retCount]) == false)
            break;
        retCount++;
    }

    return retCount;
}

void CFDictionaryGetValueEnumerator(CFDictionaryRef dict, void* enumeratorHolder) {
    ((NSDictionary*)(dict))->dict->initIterator((dictIterator*)enumeratorHolder);
}

int CFDictionaryGetNextValue(CFDictionaryRef dict, void* enumeratorHolder, id* ret, int count) {
    int retCount = 0;

    while (count--) {
        if (((NSDictionary*)(dict))->dict->getNextValue((dictIterator*)enumeratorHolder, (const void*&)ret[retCount]) == false)
            break;
        retCount++;
    }

    return retCount;
}

void _CFDictionaryInitInternal(CFDictionaryRef dict) {
    NSDictionary* pDict = (NSDictionary*)dict;

    assert(sizeof(__CFDictionary) <= __CFDICTIONARY_SIZE_BYTES);
    pDict->dict = new (pDict->_dictSpace) __CFDictionary(&kNSTypeDictionaryKeyCallBacks, &kNSTypeDictionaryValueCallBacks);
}

void _CFDictionaryDestroyInternal(CFDictionaryRef dict) {
    ((NSDictionary*)(dict))->dict->~__CFDictionary();
}

void _CFDictionaryCopyInternal(CFDictionaryRef dict, CFDictionaryRef fromDict) {
    NSDictionary* pDict = (NSDictionary*)dict;
    NSDictionary* pDictFrom = (NSDictionary*)fromDict;
    _CFDictionaryInitInternal(dict);
    pDict->dict->copyFrom(pDictFrom->dict);
}
