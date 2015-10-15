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

struct NSPropertyListReaderA {
#define MAGIC "bplist"
#define FORMAT "00"
#define TRAILER_SIZE (sizeof(uint8_t) * 2 + sizeof(uint64_t) * 3)

    typedef enum {
        kCFPropertyListImmutable = 0,
        kCFPropertyListMutableContainers,
        kCFPropertyListMutableContainersAndLeaves
    } CFOptionFlags;

    idt(NSData) _data;
    CFOptionFlags _flags;

    uint8_t _trailerOffsetIntSize;
    uint8_t _trailerOffsetRefSize;
    uint64_t _trailerNumObjects;
    uint64_t _trailerTopObject;
    uint64_t _trailerOffsetTableOffset;

    uint8_t* _dataBytes;
    unsigned _length;

    uint64_t _readIntOfSize(size_t size, uint64_t* offsetPtr);
    double _readFloatOfSize(size_t size, uint64_t* offsetPtr);
    void _readHeader();

    static uint64_t ReadSizedInt(const uint8_t* ptr, unsigned length, uint64_t offset, uint8_t size) {
        assert(ptr != NULL && size >= 1 && size <= 8 && offset + size <= length);

        uint64_t result = 0;
        const uint8_t* byte = ptr + offset;

        do {
            result = (result << 8) | *byte++;
        } while (--size);

        return result;
    }

    static BOOL ReadSelfSizedInt(const uint8_t* ptr, unsigned length, uint64_t offset, uint64_t* outValue, size_t* outSize) {
        uint32_t size;
        int64_t value;

        assert(ptr != NULL && offset < length);

        size = 1 << (ptr[offset] & 0x0F);
        if (size > 8) {
            // Maximum allowable size in this implementation is 1<<3 = 8 bytes.
            // This also happens to be the biggest NSNumber can handle.
            return FALSE;
        }

        if (offset + 1 + size > length) {
            // Out of range.
            return FALSE;
        }

        value = ReadSizedInt(ptr, length, offset + 1, size);

        if (outValue != NULL)
            *outValue = value;
        if (outSize != NULL)
            *outSize = size + 1; // +1 for tag byte.
        return TRUE;
    }

    static idt(NSDictionary) ExtractUID(const uint8_t* ptr, unsigned length, uint64_t offset);

    int readLongLength(uint64_t* offset);
    id _readObjectAtOffset(uint64_t* offset);

    id _readInlineObjectAtOffset(uint64_t* offset);

    id read();

    idt(NSData) data() {
        return _data;
    }

    void init(idt(NSData) data) {
        _data = data;
    }

    void setMutabilityFlags(CFOptionFlags flags) {
        _flags = flags;
    }
};