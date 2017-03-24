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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#include "hmapmaker.h"

#if !defined(_MSC_VER)
void strlwr(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}
#endif

void IncludeMapMaker::buildStrings() {
    if (strings)
        free(strings);
    if (stringsBlock)
        free(stringsBlock);

    strings = (char**)malloc((mapCount * 3 + 16) * sizeof(char*));
    numStrings = 0;

    //  Empty string first
    strings[numStrings++] = "";

    //  Grab all strings
    int i;
    for (i = 0; i < mapCount; i++) {
        if (headerMaps[i].from)
            strings[numStrings++] = headerMaps[i].from;
        if (headerMaps[i].toDirectory)
            strings[numStrings++] = headerMaps[i].toDirectory;
        if (headerMaps[i].toFilename)
            strings[numStrings++] = headerMaps[i].toFilename;
    }

    //  Sort them
    qsort(strings, numStrings, sizeof(char*), (int (*)(const void*, const void*))compareStringPtrs);

    //  Remove duplicate strings
    int count = numStrings;
    numStrings = 0;
    char* lastString = NULL;

    for (i = 0; i < count; i++) {
        if (lastString && strcmp(lastString, strings[i]) == 0) {
            continue;
        }
        strings[numStrings++] = strings[i];
        lastString = strings[i];
    }

    //  Build string block and remap strings array to point to it
    stringsBlock = NULL;
    stringsBlockLen = 0;

    int totalSize = 0;

    for (i = 0; i < numStrings; i++) {
        totalSize += strlen(strings[i]) + 1;
    }

    stringsBlock = (char*)malloc(totalSize);
    maxStringLen = 0;

    for (i = 0; i < numStrings; i++) {
        int strLen = strlen(strings[i]);

        strcpy(&stringsBlock[stringsBlockLen], strings[i]);
        strings[i] = &stringsBlock[stringsBlockLen];
        stringsBlockLen += strLen + 1;
        if (strLen > maxStringLen)
            maxStringLen = strLen;
    }

    //  Calculate string offsets for header maps
    for (i = 0; i < mapCount; i++) {
        char** stringPos =
            (char**)bsearch(&headerMaps[i].from, strings, numStrings, sizeof(char*), (int (*)(const void*, const void*))compareStringPtrs);
        assert(stringPos != NULL);

        headerMaps[i].fromOffset = *stringPos - stringsBlock;

        if (headerMaps[i].toDirectory) {
            char** stringPos = (char**)bsearch(&headerMaps[i].toDirectory,
                                               strings,
                                               numStrings,
                                               sizeof(char*),
                                               (int (*)(const void*, const void*))compareStringPtrs);
            assert(stringPos != NULL);

            headerMaps[i].prefixOffset = *stringPos - stringsBlock;
        } else {
            headerMaps[i].prefixOffset = 0;
        }

        if (headerMaps[i].toFilename) {
            char** stringPos = (char**)bsearch(&headerMaps[i].toFilename,
                                               strings,
                                               numStrings,
                                               sizeof(char*),
                                               (int (*)(const void*, const void*))compareStringPtrs);
            assert(stringPos != NULL);

            headerMaps[i].suffixOffset = *stringPos - stringsBlock;
        } else {
            headerMaps[i].suffixOffset = 0;
        }
    }
}

void IncludeMapMaker::buildHash() {
    if (buckets)
        free(buckets);
    numBuckets = nextPow2(mapCount + 1);
    buckets = (HMapBucket*)calloc(numBuckets, sizeof(HMapBucket));
    numAdded = 0;

    int i;
    for (i = 0; i < mapCount; i++) {
        createHashMapping(&headerMaps[i]);
    }
}

void IncludeMapMaker::createHashMapping(MapEntry* entry) {
    HMapBucket newItem;
    newItem.Key = entry->fromOffset;
    newItem.Prefix = entry->prefixOffset;
    newItem.Suffix = entry->suffixOffset;

    char* fromName = stringsBlock + newItem.Key;
    uint32_t hashKey = HashHMapKey(fromName);
    int curIdx = hashKey & (numBuckets - 1);

    //  Find an empty spot
    for (;;) {
        if (buckets[curIdx].Key == HMAP_EmptyBucketKey) {
            buckets[curIdx] = newItem;
            break;
        }

        curIdx = (curIdx + 1) & (numBuckets - 1);
    }

    numAdded++;
}

IncludeMapMaker::IncludeMapMaker() {
    headerMaps = NULL;
    mapCount = 0;
    mapCountMax = 0;

    strings = NULL;
    stringsBlock = NULL;

    buckets = NULL;
}

IncludeMapMaker::~IncludeMapMaker() {
    int i;

    for (i = 0; i < mapCount; i++) {
        if (headerMaps[i].from)
            free(headerMaps[i].from);
        if (headerMaps[i].toDirectory)
            free(headerMaps[i].toDirectory);
        if (headerMaps[i].toFilename)
            free(headerMaps[i].toFilename);
    }

    if (headerMaps)
        free(headerMaps);
    if (strings)
        free(strings);
    if (stringsBlock)
        free(stringsBlock);

    if (buckets)
        free(buckets);
}

void IncludeMapMaker::addMapping(const std::string& fromStr, const std::string& toStr) {
    const char* from = fromStr.c_str();
    const char* to = toStr.c_str();

    if (mapCount + 1 >= mapCountMax) {
        mapCountMax += 4096;
        headerMaps = (MapEntry*)realloc(headerMaps, mapCountMax * sizeof(MapEntry));
    }

    MapEntry* out = (MapEntry*)&headerMaps[mapCount];
    mapCount++;
    memset(out, 0, sizeof(MapEntry));
    out->from = (char*)malloc(strlen(from) + 1);
    strcpy(out->from, from);
    strlwr(out->from);

    const char* lastSlash = strrchr(to, '/');
    if (lastSlash) {
        lastSlash++;
        out->toDirectory = (char*)malloc(lastSlash - to + 1);
        strncpy(out->toDirectory, to, lastSlash - to);
        out->toDirectory[lastSlash - to] = 0;

        out->toFilename = (char*)malloc(strlen(lastSlash) + 1);
        strcpy(out->toFilename, lastSlash);
    } else {
        out->toDirectory = NULL;
        out->toFilename = (char*)malloc(strlen(to) + 1);
        strcpy(out->toFilename, to);
    }
}

void IncludeMapMaker::writeMap(std::ofstream& outFile) {
    //  Build the string table
    buildStrings();

    //  Build the hash table
    buildHash();

    //  Setup header
    HMapHeader header;
    header.Magic = HMAP_HeaderMagicNumber;
    header.Version = HMAP_HeaderVersion;
    header.Reserved = 0;
    header.StringsOffset = sizeof(HMapHeader) + numBuckets * sizeof(HMapBucket);
    header.NumEntries = numStrings;
    header.NumBuckets = numBuckets;
    header.MaxValueLength = maxStringLen;

    //  Write header
    outFile.write((char*)&header, sizeof(HMapHeader));

    //  Write buckets
    outFile.write((char*)buckets, sizeof(HMapBucket) * numBuckets);

    //  Write string table
    outFile.write((char*)stringsBlock, stringsBlockLen);
}

bool IncludeMapMaker::writeMap(const std::string& fileName) {
    std::ofstream ofs;
    ofs.open(fileName.c_str(), std::ofstream::out | std::ofstream::binary);

    if (ofs.is_open()) {
        writeMap(ofs);
        return true;
    } else {
        return false;
    }
}
