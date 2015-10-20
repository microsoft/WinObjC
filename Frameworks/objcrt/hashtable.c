//******************************************************************************
//
// Copyright (c) 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015
//   Jonathan Schleifer <js@webkeks.org>. All rights reserved.
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

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include <assert.h>

#include "runtime.h"
#include "runtime-private.h"

#include <windows.h>

uint32_t objc_hash_string(const char* str) {
    uint32_t hash = 0;

    while (*str != 0) {
        hash += *str;
        hash += (hash << 10);
        hash ^= (hash >> 6);
        str++;
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

uint32_t objc_hash_ptr(const void* ptr) {
    uint32_t hash = 0;
    const char* in = (const char*)ptr;
    int size = sizeof(const void*);

    while (size--) {
        hash += *in;
        hash += (hash << 10);
        hash ^= (hash >> 6);
        in++;
    }

    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);

    return hash;
}

struct objc_hashtable* objc_hashtable_new(uint32_t size) {
    struct objc_hashtable* h;
    uint32_t i;

    if ((h = malloc(sizeof(struct objc_hashtable))) == NULL)
        OBJC_ERROR("Not enough memory to allocate hash table!");

    h->count = 0;
    h->last_idx = size - 1;
    h->data = malloc(size * sizeof(struct objc_hashtable_bucket*));

    if (h->data == NULL)
        OBJC_ERROR("Not enough memory to allocate hash table!");

    for (i = 0; i < size; i++)
        h->data[i] = NULL;

    return h;
}

static void insert(struct objc_hashtable* h, const char* key, const void* obj) {
    uint32_t i, hash, last;
    struct objc_hashtable_bucket* bucket;

    hash = objc_hash_string(key);
    assert(h->count + 1 <= UINT32_MAX / 4);

    if ((h->count + 1) * 4 / (h->last_idx + 1) >= 3) {
        struct objc_hashtable_bucket** ndata;
        uint32_t nsize = (h->last_idx + 1) << 1;

        assert(nsize > 0);

        ndata = malloc(nsize * sizeof(struct objc_hashtable_bucket*));
        if (ndata == NULL)
            OBJC_ERROR(
                "Not enough memory to insert into hash "
                "table!");

        for (i = 0; i < nsize; i++)
            ndata[i] = NULL;

        for (i = 0; i <= h->last_idx; i++) {
            if (h->data[i] != NULL) {
                uint32_t j;

                last = nsize;

                for (j = h->data[i]->hash & (nsize - 1); j < last && ndata[j] != NULL; j++)
                    ;

                if (j >= last) {
                    last = h->data[i]->hash & (nsize - 1);

                    for (j = 0; j < last && ndata[j] != NULL; j++)
                        ;
                }

                if (j >= last)
                    OBJC_ERROR("No free bucket!");

                ndata[j] = h->data[i];
            }
        }

        free(h->data);
        h->data = ndata;
        h->last_idx = nsize - 1;
    }

    last = h->last_idx + 1;

    for (i = hash & h->last_idx; i < last && h->data[i] != NULL; i++)
        ;

    if (i >= last) {
        last = hash & h->last_idx;

        for (i = 0; i < last && h->data[i] != NULL; i++)
            ;
    }

    if (i >= last)
        OBJC_ERROR("No free bucket!");

    if ((bucket = malloc(sizeof(struct objc_hashtable_bucket))) == NULL)
        OBJC_ERROR("Not enough memory to allocate hash table bucket!");

    bucket->key = key;
    bucket->hash = hash;
    bucket->obj = obj;

    h->data[i] = bucket;
    h->count++;
}

static void insert_ptr(struct objc_hashtable* h, const void* key, const void* obj) {
    uint32_t i, hash, last;
    struct objc_hashtable_bucket* bucket;

    hash = objc_hash_ptr(key);
    assert(h->count + 1 <= UINT32_MAX / 4);

    if ((h->count + 1) * 4 / (h->last_idx + 1) >= 3) {
        struct objc_hashtable_bucket** ndata;
        uint32_t nsize = (h->last_idx + 1) << 1;

        assert(nsize > 0);

        ndata = malloc(nsize * sizeof(struct objc_hashtable_bucket*));
        if (ndata == NULL)
            OBJC_ERROR(
                "Not enough memory to insert into hash "
                "table!");

        for (i = 0; i < nsize; i++)
            ndata[i] = NULL;

        for (i = 0; i <= h->last_idx; i++) {
            if (h->data[i] != NULL) {
                uint32_t j;

                last = nsize;

                for (j = h->data[i]->hash & (nsize - 1); j < last && ndata[j] != NULL; j++)
                    ;

                if (j >= last) {
                    last = h->data[i]->hash & (nsize - 1);

                    for (j = 0; j < last && ndata[j] != NULL; j++)
                        ;
                }

                if (j >= last)
                    OBJC_ERROR("No free bucket!");

                ndata[j] = h->data[i];
            }
        }

        free(h->data);
        h->data = ndata;
        h->last_idx = nsize - 1;
    }

    last = h->last_idx + 1;

    for (i = hash & h->last_idx; i < last && h->data[i] != NULL; i++)
        ;

    if (i >= last) {
        last = hash & h->last_idx;

        for (i = 0; i < last && h->data[i] != NULL; i++)
            ;
    }

    if (i >= last)
        OBJC_ERROR("No free bucket!");

    if ((bucket = malloc(sizeof(struct objc_hashtable_bucket))) == NULL)
        OBJC_ERROR("Not enough memory to allocate hash table bucket!");

    bucket->key = key;
    bucket->hash = hash;
    bucket->obj = obj;

    h->data[i] = bucket;
    h->count++;
}

static int64_t index_for_key(struct objc_hashtable* h, const char* key) {
    uint32_t i, hash;

    hash = objc_hash_string(key) & h->last_idx;

    for (i = hash; i <= h->last_idx && h->data[i] != NULL; i++)
        if (!strcmp(h->data[i]->key, key))
            return i;

    if (i <= h->last_idx)
        return -1;

    for (i = 0; i < hash && h->data[i] != NULL; i++)
        if (!strcmp(h->data[i]->key, key))
            return i;

    return -1;
}

static int64_t index_for_key_ptr(struct objc_hashtable* h, const void* key) {
    uint32_t i, hash;

    hash = objc_hash_ptr(key) & h->last_idx;

    for (i = hash; i <= h->last_idx && h->data[i] != NULL; i++)
        if (h->data[i]->key == key)
            return i;

    if (i <= h->last_idx)
        return -1;

    for (i = 0; i < hash && h->data[i] != NULL; i++)
        if (h->data[i]->key == key)
            return i;

    return -1;
}

void objc_hashtable_set(struct objc_hashtable* h, const char* key, const void* obj) {
    int64_t idx = index_for_key(h, key);

    if (idx < 0) {
        insert(h, key, obj);
        return;
    }

    h->data[idx]->obj = obj;
}

void objc_hashtable_set_ptr(struct objc_hashtable* h, const void* key, const void* obj) {
    int64_t idx = index_for_key_ptr(h, key);

    if (idx < 0) {
        insert_ptr(h, key, obj);
        return;
    }

    h->data[idx]->obj = obj;
}

void* objc_hashtable_get(struct objc_hashtable* h, const char* key) {
    int64_t idx = index_for_key(h, key);

    if (idx < 0)
        return NULL;

    return (void*)h->data[idx]->obj;
}

void* objc_hashtable_get_ptr(struct objc_hashtable* h, const void* key) {
    int64_t idx = index_for_key_ptr(h, key);

    if (idx < 0)
        return NULL;

    return (void*)h->data[idx]->obj;
}

void objc_hashtable_free(struct objc_hashtable* h) {
    uint32_t i;

    for (i = 0; i <= h->last_idx; i++)
        if (h->data[i] != NULL)
            free(h->data[i]);

    free(h->data);
    free(h);
}
