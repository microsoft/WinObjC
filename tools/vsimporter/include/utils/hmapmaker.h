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

#ifndef _HMAPMAKER_H_
#define _HMAPMAKER_H_

#include <stdint.h>
#include <string.h>
#include <string>
#include <fstream>

class IncludeMapMaker {
public:
    IncludeMapMaker();
    ~IncludeMapMaker();
    void addMapping(const std::string& from, const std::string& to);
    void writeMap(std::ofstream& outFile);
    bool writeMap(const std::string& fileName);

private:
    enum {
        HMAP_HeaderMagicNumber = ('h' << 24) | ('m' << 16) | ('a' << 8) | 'p',
        HMAP_HeaderVersion = 1,

        HMAP_EmptyBucketKey = 0
    };

    struct HMapBucket {
        uint32_t Key; // Offset (into strings) of key.

        uint32_t Prefix; // Offset (into strings) of value prefix.
        uint32_t Suffix; // Offset (into strings) of value suffix.
    };

    struct HMapHeader {
        uint32_t Magic; // Magic word, also indicates byte order.
        uint16_t Version; // Version number -- currently 1.
        uint16_t Reserved; // Reserved for future use - zero for now.
        uint32_t StringsOffset; // Offset to start of string pool.
        uint32_t NumEntries; // Number of entries in the string table.
        uint32_t NumBuckets; // Number of buckets (always a power of 2).
        uint32_t MaxValueLength; // Length of longest result path (excluding nul).
        // An array of 'NumBuckets' HMapBucket objects follows this header.
        // Strings follow the buckets, at StringsOffset.
    };

    struct MapEntry {
        char* from;
        char* toDirectory; //  prefix
        char* toFilename; //  suffix

        uint32_t fromOffset, prefixOffset, suffixOffset;
    };

    MapEntry* headerMaps;
    int mapCount, mapCountMax;

    char** strings;
    int numStrings;
    char* stringsBlock;
    int stringsBlockLen;
    int maxStringLen;

    HMapBucket* buckets;
    int numBuckets, numAdded;

    static int compareStringPtrs(const char** a, const char** b) {
        return strcmp(*a, *b);
    }

    static uint32_t nextPow2(uint32_t v) {
        v--;
        v |= v >> 1;
        v |= v >> 2;
        v |= v >> 4;
        v |= v >> 8;
        v |= v >> 16;
        v++;
        return v;
    }

    /// HashHMapKey - This is the 'well known' hash function required by the file
    /// format, used to look up keys in the hash table.  The hash table uses simple
    /// linear probing based on this function.
    static inline unsigned HashHMapKey(const char* Str) {
        unsigned Result = 0;
        const char *S = Str, *End = Str + strlen(Str);

        for (; S != End; S++)
            Result += *S * 13;
        return Result;
    }

    void buildStrings();
    void buildHash();
    void createHashMapping(MapEntry* entry);
};

#endif /* _HMAPMAKER_H_ */
