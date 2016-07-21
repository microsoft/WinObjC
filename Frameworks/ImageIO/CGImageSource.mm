//******************************************************************************
//
// Copyright (c) 2016 Intel Corporation. All rights reserved.
// Copyright (c) 2016 Microsoft Corporation. All rights reserved.
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

#import <CoreGraphics/CGDataProvider.h>
#import <Foundation/Foundation.h>
#import <ImageIO/CGImageSource.h>
#import "CGImageSourceInternal.h"
#import <ImageIO/ImageIO.h>
#include <NSLogging.h>
#import <Starboard.h>
#import <StubReturn.h>
#import <objc/runtime.h>
#include <vector>

#include "COMIncludes.h"
#include "Wincodec.h"
#include <wrl/client.h>
#include "COMIncludes_End.h"

using namespace Microsoft::WRL;

static const wchar_t* TAG = L"CGImageSource";
const CFStringRef kCGImageSourceTypeIdentifierHint = static_cast<CFStringRef>(@"kCGImageSourceTypeIdentifierHint");
const CFStringRef kCGImageSourceShouldAllowFloat = static_cast<CFStringRef>(@"kCGImageSourceShouldAllowFloat");
const CFStringRef kCGImageSourceShouldCache = static_cast<CFStringRef>(@"kCGImageSourceShouldCache");
const CFStringRef kCGImageSourceCreateThumbnailFromImageIfAbsent =
    static_cast<CFStringRef>(@"kCGImageSourceCreateThumbnailFromImageIfAbsent");
const CFStringRef kCGImageSourceCreateThumbnailFromImageAlways = static_cast<CFStringRef>(@"kCGImageSourceCreateThumbnailFromImageAlways");
const CFStringRef kCGImageSourceThumbnailMaxPixelSize = static_cast<CFStringRef>(@"kCGImageSourceThumbnailMaxPixelSize");
const CFStringRef kCGImageSourceCreateThumbnailWithTransform = static_cast<CFStringRef>(@"kCGImageSourceCreateThumbnailWithTransform");
const CFStringRef kUTTypeJPEG = static_cast<const CFStringRef>(@"public.jpeg");
const CFStringRef kUTTypeTIFF = static_cast<const CFStringRef>(@"public.tiff");
const CFStringRef kUTTypeGIF = static_cast<const CFStringRef>(@"com.compuserve.gif");
const CFStringRef kUTTypePNG = static_cast<const CFStringRef>(@"public.png");
const CFStringRef kUTTypeBMP = static_cast<const CFStringRef>(@"com.microsoft.bmp");
const CFStringRef kUTTypeICO = static_cast<const CFStringRef>(@"com.microsoft.ico");

const unsigned int c_minutesPerDegree = 60;
const unsigned int c_secondsPerDegree = 3600;
const size_t c_minDataStreamSize = 96;

@implementation ImageSource
- (instancetype)initWithData:(CFDataRef)data {
    if (self = [super init]) {
        _data = (NSData*)data;
    }

    return self;
}

- (instancetype)initWithURL:(CFURLRef)url {
    if (self = [super init]) {
        _data = [NSData dataWithContentsOfURL:(NSURL*)url];
    }

    return self;
}

- (instancetype)initWithDataProvider:(CGDataProviderRef)provider {
    if (self = [super init]) {
        _data = (NSData*)CGDataProviderCopyData(provider);
    }

    return self;
}

- (instancetype)initIncremental {
    if (self = [super init]) {
        _incrementalSource = true;
    }

    return self;
}

// Helper function to identify image format from image byte stream
- (CFStringRef)_getImageType {
    char imageIdentifier[12] = { 0 };
    [self.data getBytes:&imageIdentifier length:12];
    static const unsigned char BMPIdentifier[] = { 'B', 'M' };
    static const unsigned char GIFIdentifier[] = { 'G', 'I', 'F' };
    static const unsigned char ICOIdentifier[] = { 0x00, 0x00, 0x01, 0x00 };
    static const unsigned char JPEGIdentifier[] = { 0xFF, 0xD8, 0xFF };
    static const unsigned char PNGIdentifier[] = { 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a };
    static const unsigned char TIFFIdentifier1[] = { 'M', 'M', 0x00, 0x2A };
    static const unsigned char TIFFIdentifier2[] = { 'I', 'I', 0x2A, 0x00 };
    CFStringRef imageFormat;

    if (!memcmp(imageIdentifier, BMPIdentifier, 2)) {
        imageFormat = kUTTypeBMP;
    } else if (!memcmp(imageIdentifier, GIFIdentifier, 3)) {
        imageFormat = kUTTypeGIF;
    } else if (!memcmp(imageIdentifier, ICOIdentifier, 4)) {
        imageFormat = kUTTypeICO;
    } else if (!memcmp(imageIdentifier, JPEGIdentifier, 3)) {
        imageFormat = kUTTypeJPEG;
    } else if (!memcmp(imageIdentifier, PNGIdentifier, 8)) {
        imageFormat = kUTTypePNG;
    } else if (!memcmp(imageIdentifier, TIFFIdentifier1, 4) || !memcmp(imageIdentifier, TIFFIdentifier2, 4)) {
        imageFormat = kUTTypeTIFF;
    } else {
        imageFormat = nullptr;
    }

    if (!imageFormat) {
        UNIMPLEMENTED_WITH_MSG(
            "Image format is not supported. "
            "Current release supports JPEG, BMP, PNG, GIF, TIFF & ICO image formats only.");
    }

    return imageFormat;
}

// Helper functions used for getting multi-byte values from image data.
uint16_t get16BitValue(const uint8_t* data, size_t offset) {
    return data[offset] | (data[offset + 1] << 8);
}

uint32_t get32BitValue(const uint8_t* data, size_t offset) {
    return data[offset] | (data[offset + 1] << 8) | (data[offset + 2] << 16) | (data[offset + 3] << 24);
}

uint32_t get32BitValueBigEndian(const uint8_t* data, size_t offset) {
    return (data[offset] << 24) | (data[offset + 1] << 16) | (data[offset + 2] << 8) | data[offset + 3];
}

uint32_t get16BitValueBigEndian(const uint8_t* data, size_t offset) {
    return (data[offset] << 8) | data[offset + 1];
}

/**
 @Notes      Helper function to get the status of JPEG images at the provided index.
             Progressively encoded JPEG images are not supported by Apple APIs and the current implementation does not support it.

 @References https://en.wikipedia.org/wiki/JPEG
             https://en.wikipedia.org/wiki/JPEG_File_Interchange_Format
*/
- (CGImageSourceStatus)_getJPEGStatusAtIndex:(size_t)index {
    static const uint8_t c_imageEndIdentifier[2] = { 0xFF, 0xD9 };
    static const uint8_t c_scanStartIdentifier[2] = { 0xFF, 0xDA };

    // Return if requesting for invalid frames
    if (index != 0) {
        return kCGImageStatusUnknownType;
    }

    const uint8_t* imageData = static_cast<const uint8_t*>([self.data bytes]);
    NSUInteger imageLength = [self.data length];

    if (imageLength < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    // Check if the End Of Image marker is present in the data stream
    if (imageData[imageLength - 2] == c_imageEndIdentifier[0] && imageData[imageLength - 1] == c_imageEndIdentifier[1]) {
        return kCGImageStatusComplete;
    }

    // Check if the Start Of Scan marker is present in the data stream
    for (size_t offset = 2, blockLength = 0; offset < imageLength - 3; offset += blockLength + 2) {
        blockLength = get16BitValueBigEndian(imageData, offset + 2);

        if (imageData[offset] == c_scanStartIdentifier[0] && imageData[offset + 1] == c_scanStartIdentifier[1]) {
            if (offset + blockLength + 2 > imageLength) {
                return kCGImageStatusUnknownType;
            } else {
                return kCGImageStatusIncomplete;
            }
        }
    }

    return kCGImageStatusUnknownType;
}

// TIFF helper function to get the size of a specific tag given the offset of its tag block
// Assumes that imageData has already been confirmed to contain all of the tag block at the offset
uint32_t getTiffTagSize(const uint8_t* imageData, uint32_t offset) {
    static const size_t c_tagIDOffset = 2;
    static const size_t c_tagDataTypeOffset = 4;

    // Data store that fetches the size of an incoming data type
    static const uint8_t tagTypeSize[] = {
        1, // BYTE 8-bit unsigned integer
        1, // ASCII 8-bit, NULL-terminated string
        2, // SHORT 16-bit unsigned integer
        4, // LONG 32-bit unsigned integer
        8, // RATIONAL Two 32-bit unsigned integers
        1, // SBYTE 8-bit signed integer
        1, // UNDEFINE 8-bit byte
        2, // SSHORT 16-bit signed integer
        4, // SLONG 32-bit signed integer
        8, // SRATIONAL Two 32-bit signed integers
        4, // FLOAT 4-byte single-precision IEEE floating-point value
        8 // DOUBLE 8-byte double-precision IEEE floating-point value
    };

    uint16_t tagDataType = get16BitValue(imageData, offset + c_tagIDOffset);
    uint32_t tagDataCount = get32BitValue(imageData, offset + c_tagDataTypeOffset);

    return tagTypeSize[tagDataType - 1] * tagDataCount;
}

/**
 @Notes      Helper function to get the status of TIFF images at the provided index
             Current release supports TIFF sources with little-endian byte ordering only

 @References http://www.fileformat.info/format/tiff/egff.htm
             https://partners.adobe.com/public/developer/en/tiff/TIFF6.pdf
             http://www.awaresystems.be/imaging/tiff/faq.html
*/
- (CGImageSourceStatus)_getTIFFStatusAtIndex:(size_t)index {
    static const size_t c_ifdOffset = 4;
    static const size_t c_tagCountSize = 2;
    static const size_t c_tagIDSize = 2;
    static const size_t c_tagDataTypeSize = 2;
    static const size_t c_tagDataCountSize = 4;
    static const size_t c_tagDataOffsetSize = 4;
    static const size_t c_tagSize = 12;
    static const size_t c_16BitField = 2;
    static const size_t c_32BitField = 4;

    const uint8_t* imageData = static_cast<const uint8_t*>([self.data bytes]);
    NSUInteger imageLength = [self.data length];

    if (imageLength < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    // Offset into the first Image File Directory (IFD) starts at byte offset 4
    uint32_t offset = get32BitValue(imageData, c_ifdOffset);

    // Check if data for previous image frames is present
    for (size_t currentFrameIndex = 0; currentFrameIndex < index; currentFrameIndex++) {

        // Check if the stream is atleast 2 bytes longer to contain the Tag Count
        if (offset + c_16BitField > imageLength) {
            return kCGImageStatusUnknownType;
        }

        uint16_t tagCount = get16BitValue(imageData, offset);

        // Each tag is 12 bytes and each tag count size is 2 bytes
        offset += c_tagCountSize + (tagCount * c_tagSize);

        // Check if the stream is atleast 4 bytes longer to contain the IFD Offset for the next frame
        if (offset + c_32BitField > imageLength) {
            return kCGImageStatusUnknownType;
        }

        // Fetch the IFD offset for the next frame
        offset = get32BitValue(imageData, offset);
    }

    // Check if the stream is atleast 2 bytes longer to contain the requested frame's Tag Count
    if (offset + c_16BitField > imageLength) {
        return kCGImageStatusUnknownType;
    }

    // Make a copy of the IFD start offset. If the requested frame is the last, we need to check presence of the final tag's data.
    uint32_t startOffset = offset;
    uint16_t tagCount = get16BitValue(imageData, offset);

    // Each tag count size is 2 bytes and each tag is 12 bytes
    offset += c_tagCountSize + (tagCount * c_tagSize);

    // Check if the stream is atleast 4 bytes longer to contain the next IFD's offset
    if (offset + c_32BitField > imageLength) {
        return kCGImageStatusUnknownType;
    }

    // Get the next IFD's offset. Would be zero if the requested frame is the last.
    uint32_t nextOffset = get32BitValue(imageData, offset);

    // If the requested frame is either the last frame of the image or the next frame has not been loaded, check current frame
    if (nextOffset == 0 || nextOffset > imageLength) {
        // Reset the offset to point to the TagList without advancing past all the tags
        offset = startOffset + c_tagCountSize;

        bool completeTagFound = false;
        bool incompleteTagFound = false;

        // Iterate over all the tags until the first tag with data at an offset is loaded (if lastTagLoadCheck is false), or
        // the last tag with offset data is loaded (if lastTagLoadCheck is true).
        for (uint16_t i = 0; i < tagCount; i++) {
            // Check to make sure that the tag ID, DataType, and Count fields are all present.
            // Each tag block is 12 bytes, 2 bytes for tag ID, 2 bytes for data type of tag, 4 bytes for data size,
            // and 4 bytes for data offset, which is a pointer to where the tag data is stored.
            // If the tag list is not fully loaded, then we automatically return UnknownType.
            if (offset + 8 > imageLength) {
                return kCGImageStatusUnknownType;
            }

            // Compute the size of the current tag
            uint32_t tagDataSize = getTiffTagSize(imageData, offset);

            // Move offset to the beginning of the tag offset field
            offset += c_tagIDSize + c_tagDataTypeSize + c_tagDataCountSize;

            // If the tagDataSize is small enough, the tag data is stored in the tag offset field
            // Otherwise, it contains an index to where the data is stored
            if (tagDataSize > c_tagDataOffsetSize) {

                // Check if the stream is atleast 4 bytes longer to contain the Tag Data Offset
                if (offset + c_32BitField > imageLength) {
                    return kCGImageStatusUnknownType;
                }

                // Check the data pointed to by the tag data offset. If fully there, then at least some of the tag data is loaded.
                uint32_t tagDataOffset = get32BitValue(imageData, offset);
                if (tagDataOffset + tagDataSize <= imageLength) {
                    completeTagFound = true;
                } else {
                    incompleteTagFound = true;
                }
            }

            // Move the offset past the NextIFDOffset field
            offset += c_tagDataOffsetSize;
        }

        if (completeTagFound && incompleteTagFound) {
            // Some tag data present, but also some tag data incomplete
            return kCGImageStatusIncomplete;
        } else if (completeTagFound && !incompleteTagFound) {
            // All tags with data offsets are complete, so all data in current frame is there
            return kCGImageStatusComplete;
        } else if (!completeTagFound && incompleteTagFound) {
            // No tags with data offsets are loaded, so this is considered UnknownType
            return kCGImageStatusUnknownType;
        }

        // If no complete or incomplete tag data was found, that means that the IFD only contained data small enough to fit
        // in DataOffset fields, and since we confirmed that all the tags were loaded, this means the frame is complete.
        return kCGImageStatusComplete;
    }

    // If the requested frame is not the last frame and the next frame has been partially loaded, check the IFD of the next frame.
    offset = nextOffset;

    // Check if the stream is atleast 2 bytes longer to contain the Tag Count
    if (offset + c_16BitField > imageLength) {
        return kCGImageStatusIncomplete;
    }

    // Move the offset past the next IFD's Tag Entry Count and TagList. This is needed to be consistent with Apple's implementation
    tagCount = get16BitValue(imageData, offset);
    offset += c_tagCountSize + (tagCount * c_tagSize);
    return offset <= imageLength ? kCGImageStatusComplete : kCGImageStatusIncomplete;
}

// GIF helper function to parse various Extensions - Graphic Control, Plain Text, Application & Comment
// The offset to an extension is to be passed
// Returns the offset to an Image Descriptor or to the next extension
size_t parseGIFExtension(const uint8_t* data, NSUInteger length, size_t offset) {
    static const size_t c_extensionTypeSize = 2;

    // Advance offset past the extension labels
    offset += c_extensionTypeSize;

    // Iterate over all extension sub-blocks by checking the block length. A block length of 0 marks the end of current extension
    while (offset < length && data[offset] != 0) {
        offset += data[offset] + 1;
    }

    // Advance past the block terminator to the start of the next extension or frame
    return ++offset;
}

/**
 @Notes      Helper function to get the status of GIF images at the provided index
             Interlaced GIF images are not supported by Apple APIs and the current implementation does not support it.

 @References https://www.w3.org/Graphics/GIF/spec-gif89a.txt
             https://en.wikipedia.org/wiki/GIF
             http://giflib.sourceforge.net/whatsinagif/bits_and_bytes.html
*/
- (CGImageSourceStatus)_getGIFStatusAtIndex:(size_t)index {
    static const size_t c_headerSize = 6;
    static const size_t c_logicalDescriptorSize = 7;
    static const size_t c_packedFieldOffset = 10;
    static const uint8_t c_gifExtensionHeader = 0x21;
    static const uint8_t c_gifDescriptorHeader = 0x2C;
    static const uint8_t c_gifTrailer = 0x3B;
    static const size_t c_imageDescriptorSize = 10;
    static const size_t c_minDataBlocks = 3;

    const uint8_t* imageData = static_cast<const uint8_t*>([self.data bytes]);
    NSUInteger imageLength = [self.data length];

    if (imageLength < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    size_t offset = c_headerSize + c_logicalDescriptorSize;

    // Advance offset if global color table exists. Check for existence by reading MSB of packed byte
    if (imageData[c_packedFieldOffset] & 0x80) {
        // Extract the last three bits from packed byte to get the Global Color Table Size representation and compute actual size
        offset += 3 << ((imageData[c_packedFieldOffset] & 0x7) + 1);

        // Return unknown if offset is past the end of the image data before any image frames are found
        if (offset >= imageLength) {
            return kCGImageStatusUnknownType;
        }
    }

    // Parse all available Extensions before any of the Image Data is found
    while (imageData[offset] == c_gifExtensionHeader) {
        offset = parseGIFExtension(imageData, imageLength, offset);

        if (offset >= imageLength) {
            return kCGImageStatusUnknownType;
        }
    }

    for (size_t currentFrame = 0; currentFrame <= index; currentFrame++) {
        // Parse through the current frame
        if (imageData[offset] == c_gifDescriptorHeader) {
            // To replicate Apple's status change sequence, offset is initially moved past only the first (N - 1) bytes of Image Descriptor
            // A reading header status (for first frame), incomplete status (for other requested frames) or
            // unknown status (for non-requested frames) returned on stream interruption
            offset += c_imageDescriptorSize - 1;
            if (offset >= imageLength) {
                if (index == 0) {
                    return kCGImageStatusReadingHeader;
                } else {
                    return currentFrame == index ? kCGImageStatusIncomplete : kCGImageStatusUnknownType;
                }
            }

            // Offset moved past the last Image Descriptor byte
            // An unknown type status returned on stream interruption
            offset++;
            if (offset >= imageLength) {
                return kCGImageStatusUnknownType;
            }

            // Advance offset if local color table exists. Check for existence by reading MSB of packed byte
            if (imageData[offset - 1] & 0x80) {
                // Extract the last three bits from packed byte to get the Local Color Table Size representation and compute actual size
                offset += 3 << ((imageData[offset - 1] & 0x7) + 1);
            }

            // Advance to the Image Data section
            // An unknown type status returned on stream interruption
            offset++;
            if (offset >= imageLength) {
                return kCGImageStatusUnknownType;
            }

            // Iterate over all image data sub-blocks by checking the block length. A block length of 0 marks the end of current frame
            size_t imageBlocks = 0;
            while (imageData[offset] != 0) {
                // Move offset initially past the first (N - 1) data sub-blocks. This is done to match Apple's implementation.
                // An unknown status is returned until the sub-block after the fourth length field is reached.
                // An incomplete status is returned later.
                offset += imageData[offset];
                if (offset >= imageLength) {
                    return (currentFrame == index && imageBlocks >= c_minDataBlocks) ? kCGImageStatusIncomplete : kCGImageStatusUnknownType;
                }

                // Offset is made to point to the length field of the next block
                // An unknown status is returned until the sub-block after the fourth length field is found.
                // An incomplete status is returned later.
                offset++;
                imageBlocks++;
                if (offset >= imageLength) {
                    return (currentFrame == index && imageBlocks >= c_minDataBlocks) ? kCGImageStatusIncomplete : kCGImageStatusUnknownType;
                }
            }

            // Point offset to either the trailer byte or to the beginning of the next extension or frame
            // An incomplete status (for requested frames) or an UnknownType status (for non-requested frames) is returned on interruption
            offset++;
            if (offset >= imageLength) {
                return currentFrame == index ? kCGImageStatusIncomplete : kCGImageStatusUnknownType;
            }
        } else {
            // Image data not found
            return kCGImageStatusUnknownType;
        }

        // Parse all available Extensions before reaching the trailer or the next frame
        while (imageData[offset] == c_gifExtensionHeader) {
            offset = parseGIFExtension(imageData, imageLength, offset);

            if (offset >= imageLength) {
                return (currentFrame == index) ? kCGImageStatusIncomplete : kCGImageStatusUnknownType;
            }
        }
    }

    // The frame is completely loaded if either a GIF trailer or the Image Descriptor of the next frame are present.
    if (imageData[offset] == c_gifTrailer || imageData[offset] == c_gifDescriptorHeader) {
        return kCGImageStatusComplete;
    } else {
        return kCGImageStatusIncomplete;
    }
}

/**
 @Notes      Helper function to get the status of BMP images at the provided index

 @References https://en.wikipedia.org/wiki/BMP_file_format
             http://www.fileformat.info/format/bmp/egff.htm
*/
- (CGImageSourceStatus)_getBMPStatusAtIndex:(size_t)index {
    static const size_t c_fileSizeIndex = 2;

    // Return if requesting for invalid frames
    if (index != 0) {
        return kCGImageStatusUnknownType;
    }

    const uint8_t* imageData = static_cast<const uint8_t*>([self.data bytes]);
    NSUInteger imageLength = [self.data length];

    if (imageLength < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    // Check if incoming data stream size matches image file size
    if (imageLength == get32BitValue(imageData, c_fileSizeIndex)) {
        return kCGImageStatusComplete;
    } else {
        // Apple's implementation doesn't return kCGImageStatusIncomplete for BMP images
        return kCGImageStatusUnknownType;
    }
}

/**
 @Notes      Helper function to get the status of PNG images at the provided index
             Interlaced PNG images are not supported by Apple APIs and the current implementation does not support it.
             The PLTE chunk is mandatory for color type 3, optional for types 2 and 6, and absent for types 0 and 4.
             Apple verifies these requirements. The current release does not support this.

 @References https://www.w3.org/TR/PNG/
             https://en.wikipedia.org/wiki/Portable_Network_Graphics
*/
- (CGImageSourceStatus)_getPNGStatusAtIndex:(size_t)index {
    static const size_t c_imageEndIdentifierReverseIndex = 8;
    static const size_t c_headerSize = 8;
    static const size_t c_lengthSize = 4;
    static const size_t c_chunkTypeSize = 4;
    static const size_t c_chunkDataOffset = 7;
    static const size_t c_CRCSize = 4;
    static const uint8_t c_imageEndIdentifier[] = { 'I', 'E', 'N', 'D' };
    static const uint8_t c_frameStartIdentifier[] = { 'I', 'D', 'A', 'T' };

    // Return if requesting for invalid frames
    if (index != 0) {
        return kCGImageStatusUnknownType;
    }

    const uint8_t* imageData = static_cast<const uint8_t*>([self.data bytes]);
    NSUInteger imageLength = [self.data length];

    if (imageLength < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    // Check if the End of Image identifier is present in the data stream
    size_t endIndex = imageLength - c_imageEndIdentifierReverseIndex;

    // Check for Image End identifier
    if (imageData[endIndex] == c_imageEndIdentifier[0] && imageData[endIndex + 1] == c_imageEndIdentifier[1] &&
        imageData[endIndex + 2] == c_imageEndIdentifier[2] && imageData[endIndex + 3] == c_imageEndIdentifier[3]) {
        return kCGImageStatusComplete;
    }

    // Check if the Start of Frame identifier is present in the data stream
    size_t offset = c_headerSize;
    while (offset + c_chunkDataOffset < imageLength) {
        uint32_t chunkLength = get32BitValueBigEndian(imageData, offset);
        offset += c_lengthSize;
        if (imageData[offset] == c_frameStartIdentifier[0] && imageData[offset + 1] == c_frameStartIdentifier[1] &&
            imageData[offset + 2] == c_frameStartIdentifier[2] && imageData[offset + 3] == c_frameStartIdentifier[3]) {
            return kCGImageStatusIncomplete;
        }

        offset += c_chunkTypeSize + chunkLength + c_CRCSize;
    }

    return kCGImageStatusUnknownType;
}

/**
 @Notes      Helper function to get the status of ICO images at the provided index

 @References https://msdn.microsoft.com/en-us/library/ms997538.aspx
             https://en.wikipedia.org/wiki/ICO_(file_format)
*/
- (CGImageSourceStatus)_getICOStatusAtIndex:(size_t)index {
    static const size_t c_reservedOffset = 4;
    static const size_t c_imageCountOffset = 2;
    static const size_t c_sizeOffset = 8;
    static const size_t c_dataSize = 4;
    static const size_t c_offsetSize = 4;
    static const size_t c_16BitField = 2;
    static const size_t c_32BitField = 4;

    const uint8_t* imageData = static_cast<const uint8_t*>([self.data bytes]);
    NSUInteger imageLength = [self.data length];

    if (imageLength < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    // Move the offset through 4 of the header bytes to point to the number of images in the file
    size_t offset = c_reservedOffset;

    // Check if the stream is atleast 2 bytes longer to contain the Image Count
    if (offset + c_16BitField > imageLength) {
        return kCGImageStatusUnknownType;
    }

    size_t imageCount = get16BitValue(imageData, offset);

    // Move the offset to point to the header for the first image
    offset += c_imageCountOffset;

    // The offset is moved to the image data size field of the last frame header
    // This is consistent with Apple's implementation that refers to the last frame irrespective of the one requested for
    for (size_t currentFrameIndex = 0; currentFrameIndex < imageCount; currentFrameIndex++) {
        // Move the offset to point to the image data size field
        offset += c_sizeOffset;

        // Move the offset to the beginning of the next frame's header if available
        if (currentFrameIndex != imageCount - 1) {
            offset += c_dataSize + c_offsetSize;
        }
    }

    // Check if the stream is atleast 4 bytes longer to contain the total size of pixel data
    if (offset + c_32BitField > imageLength) {
        return kCGImageStatusUnknownType;
    }

    uint32_t imageDataLength = get32BitValue(imageData, offset);

    // Move the offset to the image data offset field of the header
    offset += c_dataSize;

    // Check if the stream is atleast 4 bytes longer to contain the pixel data offset
    if (offset + c_32BitField > imageLength) {
        return kCGImageStatusUnknownType;
    }

    uint32_t imagePixelOffset = get32BitValue(imageData, offset);

    // Check if all of the image data is present in the stream
    // Apple does not return kCGImageStatusIncomplete for the ICO format
    if (imageDataLength + imagePixelOffset <= imageLength) {
        return kCGImageStatusComplete;
    } else {
        return kCGImageStatusUnknownType;
    }
}

- (CGImageSourceStatus)_getStatusAtIndex:(size_t)index {
    if (!self.data) {
        return kCGImageStatusUnexpectedEOF;
    }

    if ([self.data length] < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    CFStringRef imageFormat = [self _getImageType];
    if (imageFormat == kUTTypeJPEG) {
        return [self _getJPEGStatusAtIndex:index];
    } else if (imageFormat == kUTTypeTIFF) {
        return [self _getTIFFStatusAtIndex:index];
    } else if (imageFormat == kUTTypeGIF) {
        return [self _getGIFStatusAtIndex:index];
    } else if (imageFormat == kUTTypePNG) {
        return [self _getPNGStatusAtIndex:index];
    } else if (imageFormat == kUTTypeBMP) {
        return [self _getBMPStatusAtIndex:index];
    } else if (imageFormat == kUTTypeICO) {
        return [self _getICOStatusAtIndex:index];
    } else {
        return kCGImageStatusUnknownType;
    }
}
@end

CFDictionaryRef readJPEGProperties(IWICMetadataQueryReader* imageMetadataReader) {
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary* properties = [[NSMutableDictionary alloc] init];

    // JPEG Properties - Common
    // DPIHeight and DPIWidth are saved in different places for different image formats, and these locations only represent
    // DPI if {ushort=1} is 1, otherwise they are other units.
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                       forKey:(id)kCGImagePropertyDPIWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                       forKey:(id)kCGImagePropertyDPIHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=258}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyDepth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyOrientation];
    }

    // JPEG Properties - Format-specific
    NSMutableDictionary* jfifProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);

    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=0}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        // NSArray doesn't print properly but this is how iOS does it
        NSMutableArray* jfifVersionArray = [NSMutableArray array];
        [jfifVersionArray addObject:[NSNumber numberWithInt:(propertyValue.uiVal >> 8) & 0xF]];
        [jfifVersionArray addObject:[NSNumber numberWithInt:(propertyValue.uiVal >> 4) & 0xF]];
        [jfifVersionArray addObject:[NSNumber numberWithInt:propertyValue.uiVal & 0xF]];
        [jfifProperties setObject:jfifVersionArray forKey:(id)kCGImagePropertyJFIFVersion];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=2}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [jfifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyJFIFXDensity];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=3}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [jfifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyJFIFYDensity];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app0/{ushort=1}", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [jfifProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyJFIFDensityUnit];
    }

    // Add the JFIF dictionary to the properties if there are any JFIF properties
    if ([jfifProperties count] != 0) {
        [properties setObject:jfifProperties forKey:(id)kCGImagePropertyJFIFDictionary];
    }
    CFRelease(jfifProperties);

    // GPS Properties - JPEG
    NSMutableDictionary* gpsProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=6}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSAltitude];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=5}", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [gpsProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyGPSAltitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=29}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSDateStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=11}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSDOP];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=17}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSImgDirection];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=16}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSImgDirectionRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=2}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart / propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart / propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart / propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties
                setObject:[NSNumber numberWithDouble:degreesPart + minutesPart / c_minutesPerDegree + secondsPart / (c_secondsPerDegree)]
                   forKey:(id)kCGImagePropertyGPSLatitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=1}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLatitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=4}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart / propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart / propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart / propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties
                setObject:[NSNumber numberWithDouble:degreesPart + minutesPart / c_minutesPerDegree + secondsPart / (c_secondsPerDegree)]
                   forKey:(id)kCGImagePropertyGPSLongitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=3}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLongitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=13}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSSpeed];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=12}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSSpeedRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=7}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        double timeStampHours = (double)propertyValue.cauh.pElems[0].LowPart / propertyValue.cauh.pElems[0].HighPart;
        double timeStampMinutes = (double)propertyValue.cauh.pElems[1].LowPart / propertyValue.cauh.pElems[1].HighPart;
        double timeStampSeconds = (double)propertyValue.cauh.pElems[2].LowPart / propertyValue.cauh.pElems[2].HighPart;
        [gpsProperties setObject:[NSString stringWithFormat:@"%.2d:%.2d:%.2f", (int)timeStampHours, (int)timeStampMinutes, timeStampSeconds]
                          forKey:(id)kCGImagePropertyGPSTimeStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=15}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSTrack];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=14}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSTrackRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/gps/{ushort=0}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI1)) {
        if (propertyValue.caub.cElems == 4) {
            NSMutableArray* gpsVersionArray = [NSMutableArray array];
            for (int index = 0; index < 4; index++) {
                [gpsVersionArray addObject:[NSNumber numberWithInt:propertyValue.caub.pElems[index]]];
            }

            [gpsProperties setObject:gpsVersionArray forKey:(id)kCGImagePropertyGPSVersion];
        }
    }

    // Add the GPS dictionary to the properties if there are any GPS properties
    if ([gpsProperties count] != 0) {
        [properties setObject:gpsProperties forKey:(id)kCGImagePropertyGPSDictionary];
    }
    CFRelease(gpsProperties);

    // Exif Properties - JPEG
    NSMutableDictionary* exifProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        // iOS can get both the general image dimension properties as well as Exif ones from this value
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=33434}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifExposureTime];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37378}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifApertureValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37379}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifBrightnessValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=36868}", &propertyValue)) &&
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeDigitized];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=36867}", &propertyValue)) &&
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeOriginal];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41988}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifDigitalZoomRatio];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41986}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=34850}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureProgram];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37385}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifFlash];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=33437}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifFNumber];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37386}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifFocalLength];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=34867}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifISOSpeedRatings];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=42035}", &propertyValue)) &&
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensMake];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=42036}", &propertyValue)) &&
        propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensModel];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37500}", &propertyValue)) &&
        propertyValue.vt == VT_BLOB) {
        [exifProperties setObject:[NSData dataWithBytes:propertyValue.blob.pBlobData length:propertyValue.blob.cbSize]
                           forKey:(id)kCGImagePropertyExifMakerNote];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37383}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifMeteringMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41990}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifSceneCaptureType];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37377}", &propertyValue)) && propertyValue.vt == VT_I8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.hVal.LowPart / propertyValue.hVal.HighPart]
                           forKey:(id)kCGImagePropertyExifShutterSpeedValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=37510}", &propertyValue)) &&
        propertyValue.vt == VT_LPWSTR) {
        [exifProperties setObject:[[NSString alloc] initWithBytes:propertyValue.pwszVal
                                                           length:wcslen(propertyValue.pwszVal) * sizeof(wchar_t)
                                                         encoding:NSUnicodeStringEncoding]
                           forKey:(id)kCGImagePropertyExifUserComment];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=36864}", &propertyValue)) &&
        propertyValue.vt == VT_BLOB) {
        NSData* exifVersion = [NSData dataWithBytesNoCopy:propertyValue.blob.pBlobData length:propertyValue.blob.cbSize freeWhenDone:YES];
        NSMutableArray* exifVersionArray = [NSMutableArray array];
        char* exifVersionCharacters = (char*)[exifVersion bytes];
        [exifVersionArray addObject:[NSNumber numberWithInt:exifVersionCharacters[1] - '0']];
        [exifVersionArray addObject:[NSNumber numberWithInt:exifVersionCharacters[2] - '0']];
        [exifVersionArray addObject:[NSNumber numberWithInt:exifVersionCharacters[3] - '0']];
        [exifProperties setObject:exifVersionArray forKey:(id)kCGImagePropertyExifVersion];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/exif/{ushort=41987}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifWhiteBalance];
    }

    // Add the Exif dictionary to the properties if there are any Exif properties
    if ([exifProperties count] != 0) {
        [properties setObject:exifProperties forKey:(id)kCGImagePropertyExifDictionary];
    }
    CFRelease(exifProperties);

    // The following properties are in TIFF property dictionary, but for /app1/ifd/, which is not a TIFF directory
    // This information gets read for JPEG files on iOS, and do in fact get added to a TIFF dictionary, even for a JPEG
    NSMutableDictionary* tiffProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFOrientation];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyTIFFXResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyTIFFYResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/app1/ifd/{ushort=296}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFResolutionUnit];
    }

    // Add the TIFF dictionary to the properties if there are any TIFF properties
    if ([tiffProperties count] != 0) {
        [properties setObject:tiffProperties forKey:(id)kCGImagePropertyTIFFDictionary];
    }
    CFRelease(tiffProperties);

    return (CFDictionaryRef)properties;
}

CFDictionaryRef readTIFFProperties(IWICMetadataQueryReader* imageMetadataReader) {
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary* properties = [[NSMutableDictionary alloc] init];

    // TIFF Properties - Common
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                       forKey:(id)kCGImagePropertyDPIHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [properties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                       forKey:(id)kCGImagePropertyDPIWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=256}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=257}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=258}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyDepth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyOrientation];
    }

    // TIFF Properties - Format-specific
    NSMutableDictionary* tiffProperties = [[NSMutableDictionary alloc] init];
    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=259}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFCompression];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=262}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFPhotometricInterpretation];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=270}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFImageDescription];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=271}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFMake];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=272}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFModel];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=274}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFOrientation];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=282}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyTIFFXResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=283}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [tiffProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyTIFFYResolution];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=296}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFResolutionUnit];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=305}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFSoftware];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=306}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFDateTime];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=315}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFArtist];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=33432}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [tiffProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyTIFFCopyright];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/{ushort=41987}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [tiffProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyTIFFWhitePoint];
    }

    // Add the TIFF dictionary to the properties if there are any TIFF properties
    if ([tiffProperties count] != 0) {
        [properties setObject:tiffProperties forKey:(id)kCGImagePropertyTIFFDictionary];
    }
    CFRelease(tiffProperties);

    // GPS Properties - TIFF - This is a copy of TIFF properties for JPEG but with different paths.
    NSMutableDictionary* gpsProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=6}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSAltitude];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=5}", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [gpsProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyGPSAltitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=29}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSDateStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=11}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSDOP];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=17}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSImgDirection];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=16}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSImgDirectionRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=2}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart / propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart / propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart / propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties
                setObject:[NSNumber numberWithDouble:degreesPart + minutesPart / c_minutesPerDegree + secondsPart / (c_secondsPerDegree)]
                   forKey:(id)kCGImagePropertyGPSLatitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=1}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLatitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=4}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        if (propertyValue.caub.cElems == 3) { // Validate number of fields
            double degreesPart = (double)propertyValue.cauh.pElems[0].LowPart / propertyValue.cauh.pElems[0].HighPart;
            double minutesPart = (double)propertyValue.cauh.pElems[1].LowPart / propertyValue.cauh.pElems[1].HighPart;
            double secondsPart = (double)propertyValue.cauh.pElems[2].LowPart / propertyValue.cauh.pElems[2].HighPart;
            [gpsProperties
                setObject:[NSNumber numberWithDouble:degreesPart + minutesPart / c_minutesPerDegree + secondsPart / (c_secondsPerDegree)]
                   forKey:(id)kCGImagePropertyGPSLongitude];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=3}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSLongitudeRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=13}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSSpeed];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=12}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSSpeedRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=7}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI8)) {
        double timeStampHours = (double)propertyValue.cauh.pElems[0].LowPart / propertyValue.cauh.pElems[0].HighPart;
        double timeStampMinutes = (double)propertyValue.cauh.pElems[1].LowPart / propertyValue.cauh.pElems[1].HighPart;
        double timeStampSeconds = (double)propertyValue.cauh.pElems[2].LowPart / propertyValue.cauh.pElems[2].HighPart;
        [gpsProperties setObject:[NSString stringWithFormat:@"%.2d:%.2d:%.2f", (int)timeStampHours, (int)timeStampMinutes, timeStampSeconds]
                          forKey:(id)kCGImagePropertyGPSTimeStamp];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=15}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [gpsProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                          forKey:(id)kCGImagePropertyGPSTrack];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=14}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [gpsProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyGPSTrackRef];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/gps/{ushort=0}", &propertyValue)) &&
        propertyValue.vt == (VT_VECTOR | VT_UI1)) {
        if (propertyValue.caub.cElems == 4) {
            NSMutableArray* gpsVersionArray = [NSMutableArray array];
            for (int index = 0; index < 4; index++) {
                [gpsVersionArray addObject:[NSNumber numberWithInt:propertyValue.caub.pElems[index]]];
            }

            [gpsProperties setObject:gpsVersionArray forKey:(id)kCGImagePropertyGPSVersion];
        }
    }

    // Add the GPS dictionary to the properties if there are any GPS properties
    if ([gpsProperties count] != 0) {
        [properties setObject:gpsProperties forKey:(id)kCGImagePropertyGPSDictionary];
    }
    CFRelease(gpsProperties);

    // Exif Properties - TIFF - This is a copy of Exif properties for JPEG but with different paths.
    NSMutableDictionary* exifProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40962}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelXDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=40963}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifPixelYDimension];
        [properties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=33434}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifExposureTime];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37378}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifApertureValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37379}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifBrightnessValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=36868}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeDigitized];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=36867}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifDateTimeOriginal];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41988}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifDigitalZoomRatio];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41986}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=34850}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifExposureProgram];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37385}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifFlash];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=33437}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifFNumber];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37386}", &propertyValue)) && propertyValue.vt == VT_UI8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.uhVal.LowPart / propertyValue.uhVal.HighPart]
                           forKey:(id)kCGImagePropertyExifFocalLength];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=34867}", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyExifISOSpeedRatings];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=42035}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensMake];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=42036}", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [exifProperties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyExifLensModel];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37500}", &propertyValue)) && propertyValue.vt == VT_BLOB) {
        [exifProperties setObject:[NSData dataWithBytes:propertyValue.blob.pBlobData length:propertyValue.blob.cbSize]
                           forKey:(id)kCGImagePropertyExifMakerNote];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37383}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifMeteringMode];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41990}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifSceneCaptureType];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37377}", &propertyValue)) && propertyValue.vt == VT_I8) {
        [exifProperties setObject:[NSNumber numberWithDouble:(double)propertyValue.hVal.LowPart / propertyValue.hVal.HighPart]
                           forKey:(id)kCGImagePropertyExifShutterSpeedValue];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=37510}", &propertyValue)) && propertyValue.vt == VT_LPWSTR) {
        [exifProperties setObject:[[NSString alloc] initWithBytes:propertyValue.pwszVal
                                                           length:wcslen(propertyValue.pwszVal) * sizeof(wchar_t)
                                                         encoding:NSUnicodeStringEncoding]
                           forKey:(id)kCGImagePropertyExifUserComment];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=36864}", &propertyValue)) && propertyValue.vt == VT_BLOB) {
        NSData* exifVersion = [NSData dataWithBytesNoCopy:propertyValue.blob.pBlobData length:propertyValue.blob.cbSize freeWhenDone:YES];
        NSMutableArray* exifVersionArray = [NSMutableArray array];
        char* exifVersionCharacters = (char*)[exifVersion bytes];
        [exifVersionArray addObject:[NSNumber numberWithInt:exifVersionCharacters[1] - '0']];
        [exifVersionArray addObject:[NSNumber numberWithInt:exifVersionCharacters[2] - '0']];
        [exifVersionArray addObject:[NSNumber numberWithInt:exifVersionCharacters[3] - '0']];
        [exifProperties setObject:exifVersionArray forKey:(id)kCGImagePropertyExifVersion];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/ifd/exif/{ushort=41987}", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [exifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyExifWhiteBalance];
    }

    // Add the Exif dictionary to the properties if there are any Exif properties
    if ([exifProperties count] != 0) {
        [properties setObject:exifProperties forKey:(id)kCGImagePropertyExifDictionary];
    }
    CFRelease(exifProperties);

    return (CFDictionaryRef)properties;
}

CFDictionaryRef readGIFProperties(IWICMetadataQueryReader* imageMetadataReader) {
    // GIF Properties - Common
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary* properties = [[NSMutableDictionary alloc] init];

    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/imgdesc/Width", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelWidth];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/imgdesc/Height", &propertyValue)) && propertyValue.vt == VT_UI2) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyPixelHeight];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/grctlext/TransparencyFlag", &propertyValue)) && propertyValue.vt == VT_BOOL) {
        [properties setObject:[NSNumber numberWithInt:propertyValue.boolVal] forKey:(id)kCGImagePropertyHasAlpha];
    }

    // GIF Properties - Format-specific
    NSMutableDictionary* gifProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/grctlext/Delay", &propertyValue)) && propertyValue.vt == VT_UI2) {
        // Delay time is represented in 1/100ths of a second, iOS records seconds
        double delayTime = propertyValue.uiVal / 100.0;
        if (delayTime < 0.1) {
            [gifProperties setObject:[NSNumber numberWithDouble:0.1] forKey:(id)kCGImagePropertyGIFDelayTime];
            [gifProperties setObject:[NSNumber numberWithDouble:delayTime] forKey:(id)kCGImagePropertyGIFUnclampedDelayTime];
        } else {
            [gifProperties setObject:[NSNumber numberWithDouble:delayTime] forKey:(id)kCGImagePropertyGIFDelayTime];
            [gifProperties setObject:[NSNumber numberWithDouble:delayTime] forKey:(id)kCGImagePropertyGIFUnclampedDelayTime];
        }
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/logscrdesc/GlobalColorTableFlag", &propertyValue)) &&
        propertyValue.vt == VT_UI2) {
        [gifProperties setObject:[NSNumber numberWithInt:propertyValue.uiVal] forKey:(id)kCGImagePropertyGIFHasGlobalColorMap];
    }

    // Add the GIF dictionary to the properties if there are any GIF properties
    if ([gifProperties count] != 0) {
        [properties setObject:gifProperties forKey:(id)kCGImagePropertyGIFDictionary];
    }
    CFRelease(gifProperties);

    return (CFDictionaryRef)properties;
}

CFDictionaryRef readPNGProperties(IWICMetadataQueryReader* imageMetadataReader) {
    PROPVARIANT propertyValue;
    PropVariantInit(&propertyValue);
    NSMutableDictionary* properties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/iCCP/ProfileName", &propertyValue)) && propertyValue.vt == VT_LPSTR) {
        [properties setObject:[NSString stringWithUTF8String:propertyValue.pszVal] forKey:(id)kCGImagePropertyProfileName];
    }

    // PNG Properties - Format-specific
    NSMutableDictionary* pngProperties = [[NSMutableDictionary alloc] init];

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/gAMA/ImageGamma", &propertyValue)) && propertyValue.vt == VT_UI4) {
        [pngProperties setObject:[NSNumber numberWithInt:propertyValue.ulVal] forKey:(id)kCGImagePropertyPNGGamma];
    }

    PropVariantClear(&propertyValue);
    if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/sRGB/RenderingIntent", &propertyValue)) && propertyValue.vt == VT_UI1) {
        [pngProperties setObject:[NSNumber numberWithInt:propertyValue.bVal] forKey:(id)kCGImagePropertyPNGsRGBIntent];
    }

    // Add the PNG dictionary to the properties if there are any PNG properties
    if ([pngProperties count] != 0) {
        [properties setObject:pngProperties forKey:(id)kCGImagePropertyPNGDictionary];
    }
    CFRelease(pngProperties);

    return (CFDictionaryRef)properties;
}

/**
 @Status Caveat
 @Notes The current implementation supports common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO.
        Not all formats are supported.
        kCGImageSourceTypeIdentifierHint is not supported when passed in as an options dictionary key.
*/
CGImageSourceRef CGImageSourceCreateWithDataProvider(CGDataProviderRef provider, CFDictionaryRef options) {
    RETURN_NULL_IF(!provider);
    if (options && CFDictionaryContainsKey(options, kCGImageSourceTypeIdentifierHint)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceTypeIdentifierHint is not supported in current implementation.");
    }

    return (CGImageSourceRef)[[ImageSource alloc] initWithDataProvider:provider];
}

/**
 @Status Caveat
 @Notes The current implementation supports common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO.
        Not all formats are supported.
        kCGImageSourceTypeIdentifierHint is not supported when passed in as an options dictionary key.
*/
CGImageSourceRef CGImageSourceCreateWithData(CFDataRef data, CFDictionaryRef options) {
    RETURN_NULL_IF(!data);
    if (options && CFDictionaryContainsKey(options, kCGImageSourceTypeIdentifierHint)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceTypeIdentifierHint is not supported in current implementation.");
    }

    return (CGImageSourceRef)[[ImageSource alloc] initWithData:data];
}

/**
 @Status Caveat
 @Notes The current implementation supports common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO.
        Not all formats are supported.
        kCGImageSourceTypeIdentifierHint is not supported when passed in as an options dictionary key.
*/
CGImageSourceRef CGImageSourceCreateWithURL(CFURLRef url, CFDictionaryRef options) {
    RETURN_NULL_IF(!url);
    if (options && CFDictionaryContainsKey(options, kCGImageSourceTypeIdentifierHint)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceTypeIdentifierHint is not supported in current implementation.");
    }

    return (CGImageSourceRef)[[ImageSource alloc] initWithURL:url];
}

/**
 @Status Caveat
 @Notes Current implementation does not support kCGImageSourceShouldAllowFloat & kCGImageSourceShouldCache
        when passed in as options dictionary keys
        During incremental loading of PNG images, decoder creation succeeds only when all image data is available
*/
CGImageRef CGImageSourceCreateImageAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options) {
    RETURN_NULL_IF(!isrc);
    ImageSource* source = (ImageSource*)isrc;
    NSData* imageData = source.data;
    RETURN_NULL_IF(!imageData);

    // Incremental image load properties
    // Get the incremental load status for the incoming data source at provided index
    source.loadStatus = [source _getStatusAtIndex:index];

    // Track the frame index for the source with an associated status fetched into loadStatus.
    // The default value for an un-initialized loadIndex is 0 and so it must not be stored as an index to avoid false 
    // positive matches. The loadIndex is bumped up by 1 and this value is checked for in the incremental status APIs.
    source.loadIndex = index + 1;

    // This API returns a reference to an image only if the current source status is either Incomplete or Complete 
    RETURN_NULL_IF(source.loadStatus != kCGImageStatusIncomplete && source.loadStatus != kCGImageStatusComplete);
    RETURN_NULL_IF(index > (CGImageSourceGetCount(isrc) - 1));

    MULTI_QI imageQueryInterface = { 0 };
    static const GUID IID_IWICImagingFactory = { 0xec5ec8a9, 0xc395, 0x4314, 0x9c, 0x77, 0x54, 0xd7, 0xa9, 0x35, 0xff, 0x70 };
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    RETURN_NULL_IF_FAILED(
        CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;
    RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    int imageLength = [imageData length];
    RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, imageLength));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
    }

    ComPtr<IWICBitmapDecoder> imageDecoder;
    RETURN_NULL_IF_FAILED(imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));

    ComPtr<IWICBitmapFrameDecode> imageFrame;
    RETURN_NULL_IF_FAILED(imageDecoder->GetFrame(index, &imageFrame));

    unsigned int frameWidth = 0;
    unsigned int frameHeight = 0;
    RETURN_NULL_IF_FAILED(imageFrame->GetSize(&frameWidth, &frameHeight));

    ComPtr<IWICFormatConverter> imageFormatConverter;
    RETURN_NULL_IF_FAILED(imageFactory->CreateFormatConverter(&imageFormatConverter));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldAllowFloat)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldAllowFloat is not supported in current implementation.");
    }

    RETURN_NULL_IF_FAILED(imageFormatConverter->Initialize(
        imageFrame.Get(), GUID_WICPixelFormat32bppRGBA, WICBitmapDitherTypeNone, nullptr, 0.f, WICBitmapPaletteTypeCustom));

    const unsigned int frameSize = frameWidth * frameHeight * 4;
    unsigned char* frameByteArray = static_cast<unsigned char*>(IwMalloc(frameSize));
    if (!frameByteArray) {
        NSTraceInfo(TAG, @"CGImageSourceCreateImageAtIndex cannot allocate memory");
        return nullptr;
    }

    auto cleanup = wil::ScopeExit([&]() { IwFree(frameByteArray); });
    RETURN_NULL_IF_FAILED(imageFormatConverter->CopyPixels(0, frameWidth * 4, frameSize, frameByteArray));
    cleanup.Dismiss();

    NSData* frameData = [NSData dataWithBytesNoCopy:frameByteArray length:frameSize freeWhenDone:YES];
    CGDataProviderRef frameDataProvider = CGDataProviderCreateWithCFData((CFDataRef)frameData);
    CGColorSpaceRef colorspaceRgb = CGColorSpaceCreateDeviceRGB();
    CGImageRef imageRef = CGImageCreate(frameWidth,
                                        frameHeight,
                                        8,
                                        32,
                                        frameWidth * 4,
                                        colorspaceRgb,
                                        kCGImageAlphaLast,
                                        frameDataProvider,
                                        nullptr,
                                        true,
                                        kCGRenderingIntentDefault);
    CGDataProviderRelease(frameDataProvider);
    CGColorSpaceRelease(colorspaceRgb);
    return imageRef;
}

/**
 @Status Caveat
 @Notes Current implementation does not support kCGImageSourceShouldAllowFloat, kCGImageSourceShouldCache &
        kCGImageSourceCreateThumbnailWithTransform when passed in as options dictionary keys
*/
CGImageRef CGImageSourceCreateThumbnailAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options) {
    RETURN_NULL_IF(!isrc);
    NSData* imageData = ((ImageSource*)isrc).data;
    RETURN_NULL_IF(!imageData);
    RETURN_NULL_IF(index > (CGImageSourceGetCount(isrc) - 1));

    MULTI_QI imageQueryInterface = { 0 };
    static const GUID IID_IWICImagingFactory = { 0xec5ec8a9, 0xc395, 0x4314, 0x9c, 0x77, 0x54, 0xd7, 0xa9, 0x35, 0xff, 0x70 };
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    RETURN_NULL_IF_FAILED(
        CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;
    RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    int imageLength = [imageData length];
    RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, imageLength));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
    }

    ComPtr<IWICBitmapDecoder> imageDecoder;
    RETURN_NULL_IF_FAILED(imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));

    ComPtr<IWICBitmapFrameDecode> imageFrame;
    RETURN_NULL_IF_FAILED(imageDecoder->GetFrame(index, &imageFrame));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailWithTransform)) {
        UNIMPLEMENTED_WITH_MSG(
            "kCGImageSourceCreateThumbnailWithTransform is not supported in "
            "current implementation.");
    }

    ComPtr<IWICFormatConverter> imageFormatConverter;
    RETURN_NULL_IF_FAILED(imageFactory->CreateFormatConverter(&imageFormatConverter));

    ComPtr<IWICBitmapScaler> imageScaler;
    RETURN_NULL_IF_FAILED(imageFactory->CreateBitmapScaler(&imageScaler));

    unsigned int thumbnailWidth = 0;
    unsigned int thumbnailHeight = 0;
    bool thumbnailExists = false;
    ComPtr<IWICBitmapSource> imageThumbnail;

    // Check if incoming image frame has an existing thumbnail. Return NULL if absent & thumbnail creation flags are not specified.
    if (!SUCCEEDED(imageFrame->GetThumbnail(&imageThumbnail))) {
        if (options && (CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailFromImageIfAbsent) ||
                        CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailFromImageAlways))) {
            RETURN_NULL_IF_FAILED(imageFrame->GetSize(&thumbnailWidth, &thumbnailHeight));
        }
    } else {
        thumbnailExists = true;
        RETURN_NULL_IF_FAILED(imageThumbnail->GetSize(&thumbnailWidth, &thumbnailHeight));
    }

    unsigned int maxThumbnailSize = 0;
    if (options && CFDictionaryContainsKey(options, kCGImageSourceThumbnailMaxPixelSize)) {
        maxThumbnailSize = [(id)CFDictionaryGetValue(options, kCGImageSourceThumbnailMaxPixelSize) intValue];
    }

    // Maintain aspect ratio if thumbnail size exceeds maximum thumbnail pixel size
    if (maxThumbnailSize && ((thumbnailWidth > maxThumbnailSize) || (thumbnailHeight > maxThumbnailSize))) {
        if (thumbnailWidth >= thumbnailHeight) {
            thumbnailHeight = thumbnailHeight / thumbnailWidth * maxThumbnailSize;
            thumbnailWidth = maxThumbnailSize;
        } else {
            thumbnailWidth = thumbnailWidth / thumbnailHeight * maxThumbnailSize;
            thumbnailHeight = maxThumbnailSize;
        }

        if (!thumbnailWidth || !thumbnailHeight) {
            thumbnailWidth = maxThumbnailSize;
            thumbnailHeight = maxThumbnailSize;
        }
    }

    // Scale thumbnail according to the calculated dimensions
    if (!thumbnailExists ||
        (thumbnailExists && options && CFDictionaryContainsKey(options, kCGImageSourceCreateThumbnailFromImageAlways))) {
        RETURN_NULL_IF_FAILED(imageScaler->Initialize(imageFrame.Get(), thumbnailWidth, thumbnailHeight, WICBitmapInterpolationModeCubic));
    } else {
        RETURN_NULL_IF_FAILED(
            imageScaler->Initialize(imageThumbnail.Get(), thumbnailWidth, thumbnailHeight, WICBitmapInterpolationModeCubic));
    }

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldAllowFloat)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldAllowFloat is not supported in current implementation.");
    }

    RETURN_NULL_IF_FAILED(imageFormatConverter->Initialize(
        imageScaler.Get(), GUID_WICPixelFormat32bppRGBA, WICBitmapDitherTypeNone, nullptr, 0.f, WICBitmapPaletteTypeCustom));

    const unsigned int thumbnailSize = thumbnailWidth * thumbnailHeight * 4;
    unsigned char* thumbnailByteArray = static_cast<unsigned char*>(IwMalloc(thumbnailSize));
    if (!thumbnailByteArray) {
        NSTraceInfo(TAG, @"CGImageSourceCreateThumbnailAtIndex cannot allocate memory");
        return nullptr;
    }

    auto cleanup = wil::ScopeExit([&]() { IwFree(thumbnailByteArray); });
    RETURN_NULL_IF_FAILED(imageFormatConverter->CopyPixels(0, thumbnailWidth * 4, thumbnailSize, thumbnailByteArray));
    cleanup.Dismiss();

    NSData* thumbnailData = [NSData dataWithBytesNoCopy:thumbnailByteArray length:thumbnailSize freeWhenDone:YES];
    CGDataProviderRef thumbnailDataProvider = CGDataProviderCreateWithCFData((CFDataRef)thumbnailData);
    CGColorSpaceRef colorspaceRgb = CGColorSpaceCreateDeviceRGB();
    CGImageRef imageRef = CGImageCreate(thumbnailWidth,
                                        thumbnailHeight,
                                        8,
                                        32,
                                        thumbnailWidth * 4,
                                        colorspaceRgb,
                                        kCGImageAlphaLast,
                                        thumbnailDataProvider,
                                        nullptr,
                                        true,
                                        kCGRenderingIntentDefault);
    CGDataProviderRelease(thumbnailDataProvider);
    CGColorSpaceRelease(colorspaceRgb);
    return imageRef;
}

/**
 @Status Caveat
 @Notes The current implementation supports incremental loading for common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO.
        Not all formats are supported.
*/
CGImageSourceRef CGImageSourceCreateIncremental(CFDictionaryRef options) {
    return (CGImageSourceRef)[[ImageSource alloc] initIncremental];
}

/**
 @Status Caveat
 @Notes The current implementation supports incremental loading for common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO.
        Not all formats are supported.
*/
void CGImageSourceUpdateData(CGImageSourceRef isrc, CFDataRef data, bool final) {
    if (!isrc || !data) {
        return;
    }

    ((ImageSource*)isrc).data = (NSData*)data;
    ((ImageSource*)isrc).isFinalIncrementalSet = final;
}

/**
 @Status Caveat
 @Notes The current implementation supports incremental loading for common image file formats such as JPEG, GIF, TIFF, BMP, PNG and ICO.
        Not all formats are supported.
*/
void CGImageSourceUpdateDataProvider(CGImageSourceRef isrc, CGDataProviderRef provider, bool final) {
    if (!isrc || !provider) {
        return;
    }

    ((ImageSource*)isrc).data = (NSData*)CGDataProviderCopyData(provider);
    ((ImageSource*)isrc).isFinalIncrementalSet = final;
}

/**
 @Status Caveat
 @Notes The CFTypeID for an opaque type differs across releases and has been hard-coded to one possible value in current implementation
*/
CFTypeID CGImageSourceGetTypeID() {
    static const int c_imageSourceTypeID = 286;
    return c_imageSourceTypeID;
}

/**
 @Status Caveat
 @Notes Current release supports JPEG, BMP, PNG, GIF, TIFF & ICO image formats only
*/
CFStringRef CGImageSourceGetType(CGImageSourceRef isrc) {
    RETURN_NULL_IF(!isrc);
    ImageSource* imageSrc = (ImageSource*)isrc;
    RETURN_NULL_IF(!imageSrc.data);
    return [imageSrc _getImageType];
}

/**
 @Status Caveat
 @Notes Current release supports JPEG, BMP, PNG, GIF, TIFF & ICO image formats only
*/
CFArrayRef CGImageSourceCopyTypeIdentifiers() {
    static const CFStringRef typeIdentifiers[] = { kUTTypePNG, kUTTypeJPEG, kUTTypeGIF, kUTTypeTIFF, kUTTypeICO, kUTTypeBMP };
    CFArrayRef imageTypeIdentifiers =
        CFArrayCreate(nullptr, (const void**)typeIdentifiers, ARRAYSIZE(typeIdentifiers), &kCFTypeArrayCallBacks);
    return imageTypeIdentifiers;
}

/**
 @Status Caveat
 @Notes Current release supports JPEG, BMP, PNG, GIF, TIFF & ICO image formats only
*/
size_t CGImageSourceGetCount(CGImageSourceRef isrc) {
    if (!isrc) {
        return 0;
    }

    NSData* imageData = ((ImageSource*)isrc).data;
    if (!imageData) {
        return 0;
    }

    MULTI_QI imageQueryInterface = { 0 };
    static const GUID IID_IWICImagingFactory = { 0xec5ec8a9, 0xc395, 0x4314, 0x9c, 0x77, 0x54, 0xd7, 0xa9, 0x35, 0xff, 0x70 };
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    HRESULT status = CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"CoCreateInstanceFromApp failed with status=%x\n", status);
        return 0;
    }

    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;
    status = imageFactory->CreateStream(&imageStream);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"IWICImagingFactory::CreateStream failed with status=%x\n", status);
        return 0;
    }

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    int imageLength = [imageData length];
    status = imageStream->InitializeFromMemory(imageByteArray, imageLength);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"IWICStream::InitializeFromMemory failed with status=%x\n", status);
        return 0;
    }

    ComPtr<IWICBitmapDecoder> imageDecoder;
    status = imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"IWICImagingFactory::CreateDecoderFromStream failed with status=%x\n", status);
        return 0;
    }

    size_t frameCount = 0;
    status = imageDecoder->GetFrameCount(&frameCount);
    if (!SUCCEEDED(status)) {
        NSTraceInfo(TAG, @"IWICBitmapDecoder::GetFrameCount failed with status=%x\n", status);
    }

    return frameCount;
}

/**
 @Status Caveat
 @Notes A limited subset of source container properties are supported currently
*/
CFDictionaryRef CGImageSourceCopyProperties(CGImageSourceRef isrc, CFDictionaryRef options) {
    static const uint8_t c_gifDataIdentifier[2] = { 3, 1 };

    RETURN_NULL_IF(!isrc);
    NSData* imageData = ((ImageSource*)isrc).data;
    RETURN_NULL_IF(!imageData);

    NSMutableDictionary* properties = [[NSMutableDictionary alloc] init];
    [properties setObject:[NSNumber numberWithInt:[imageData length]] forKey:(id)kCGImagePropertyFileSize];

    // Look for container-level metadata if the file is a GIF. Other image formats don't have container-level metadata
    // and the metadata is read as part of CGImageSourceCopyPropertiesAtIndex.
    CFStringRef imageFormat = CGImageSourceGetType(isrc);
    if (imageFormat == kUTTypeGIF) {
        MULTI_QI imageQueryInterface = { 0 };
        const GUID IID_IWICImagingFactory = { 0xec5ec8a9, 0xc395, 0x4314, 0x9c, 0x77, 0x54, 0xd7, 0xa9, 0x35, 0xff, 0x70 };
        imageQueryInterface.pIID = &IID_IWICImagingFactory;
        RETURN_NULL_IF_FAILED(
            CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

        ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
        ComPtr<IWICStream> imageStream;
        RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

        unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
        RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, [imageData length]));

        if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
            UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
        }

        ComPtr<IWICBitmapDecoder> imageDecoder;
        RETURN_NULL_IF_FAILED(
            imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));
        ComPtr<IWICMetadataQueryReader> imageMetadataReader;
        RETURN_NULL_IF_FAILED(imageDecoder->GetMetadataQueryReader(&imageMetadataReader));

        PROPVARIANT propertyValue;
        PropVariantInit(&propertyValue);
        NSMutableDictionary* gifProperties = [[NSMutableDictionary alloc] init];

        // The GIF metadata can contain a Netcape 2.0 looping block in /appext/Data. It contains 0x3, representing 3 bytes
        // of data, followed by 0x1, and then 2 bytes for the loop count in little-endian format.
        if (SUCCEEDED(imageMetadataReader->GetMetadataByName(L"/appext/Data", &propertyValue)) &&
            propertyValue.vt == (VT_VECTOR | VT_UI1)) {
            if (propertyValue.caub.pElems[0] == c_gifDataIdentifier[0] && propertyValue.caub.pElems[1] == c_gifDataIdentifier[1]) {
                NSNumber* loopCount = [NSNumber numberWithInt:propertyValue.caub.pElems[2] + (propertyValue.caub.pElems[3] << 8)];
                [gifProperties setObject:loopCount forKey:(id)kCGImagePropertyGIFLoopCount];
            }
        }

        if ([gifProperties count] != 0) {
            [properties setObject:gifProperties forKey:(id)kCGImagePropertyGIFDictionary];
        }
        CFRelease(gifProperties);
    }

    return (CFDictionaryRef)properties;
}

/**
 @Status Caveat
 @Notes A limited subset of frame properties are supported currently
*/
CFDictionaryRef CGImageSourceCopyPropertiesAtIndex(CGImageSourceRef isrc, size_t index, CFDictionaryRef options) {
    RETURN_NULL_IF(!isrc);
    NSData* imageData = ((ImageSource*)isrc).data;
    RETURN_NULL_IF(!imageData);

    MULTI_QI imageQueryInterface = { 0 };
    const GUID IID_IWICImagingFactory = { 0xec5ec8a9, 0xc395, 0x4314, 0x9c, 0x77, 0x54, 0xd7, 0xa9, 0x35, 0xff, 0x70 };
    imageQueryInterface.pIID = &IID_IWICImagingFactory;
    RETURN_NULL_IF_FAILED(
        CoCreateInstanceFromApp(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, nullptr, 1, &imageQueryInterface));

    ComPtr<IWICImagingFactory> imageFactory = (IWICImagingFactory*)imageQueryInterface.pItf;
    ComPtr<IWICStream> imageStream;
    RETURN_NULL_IF_FAILED(imageFactory->CreateStream(&imageStream));

    unsigned char* imageByteArray = (unsigned char*)[imageData bytes];
    RETURN_NULL_IF_FAILED(imageStream->InitializeFromMemory(imageByteArray, [imageData length]));

    if (options && CFDictionaryContainsKey(options, kCGImageSourceShouldCache)) {
        UNIMPLEMENTED_WITH_MSG("kCGImageSourceShouldCache is not supported in current implementation.");
    }

    ComPtr<IWICBitmapDecoder> imageDecoder;
    RETURN_NULL_IF_FAILED(imageFactory->CreateDecoderFromStream(imageStream.Get(), nullptr, WICDecodeMetadataCacheOnDemand, &imageDecoder));
    ComPtr<IWICBitmapFrameDecode> imageFrame;
    RETURN_NULL_IF_FAILED(imageDecoder->GetFrame(index, &imageFrame));
    ComPtr<IWICMetadataQueryReader> imageMetadataReader;
    RETURN_NULL_IF_FAILED(imageFrame->GetMetadataQueryReader(&imageMetadataReader));

    CFStringRef imageFormat = CGImageSourceGetType(isrc);
    if (imageFormat == kUTTypeJPEG) {
        return readJPEGProperties(imageMetadataReader.Get());
    } else if (imageFormat == kUTTypeTIFF) {
        return readTIFFProperties(imageMetadataReader.Get());
    } else if (imageFormat == kUTTypeGIF) {
        return readGIFProperties(imageMetadataReader.Get());
    } else if (imageFormat == kUTTypePNG) {
        return readPNGProperties(imageMetadataReader.Get());
    } else {
        return nullptr;
    }
}

/**
 @Status Caveat
 @Notes Current release returns kCGImageStatusComplete, kCGImageStatusIncomplete or kCGImageStatusInvalidData only.
        Other return values are not supported.
*/
CGImageSourceStatus CGImageSourceGetStatus(CGImageSourceRef isrc) {
    if (!isrc) {
        return kCGImageStatusInvalidData;
    }

    ImageSource* imageSrc = (ImageSource*)isrc;
    if (!imageSrc.data) {
        return kCGImageStatusInvalidData;
    }

    // Non-incremental sources always return complete
    if (!imageSrc.incrementalSource) {
        return kCGImageStatusComplete;
    }

    // Streams below a minimum size are considered to have invalid data. This is consistent with Apple's implementation.
    if ([imageSrc.data length] < c_minDataStreamSize) {
        return kCGImageStatusInvalidData;
    }

    // Streams having the final data set are considered to be complete 
    if (imageSrc.isFinalIncrementalSet) {
        return kCGImageStatusComplete;
    } else {
        return kCGImageStatusIncomplete;
    }
}

/**
 @Status Caveat
 @Notes The kCGImageStatusInvalidData status is not supported.
        Only Baseline DCT-based JPEG sources are supported by Apple and the current implementation.
        Progressive DCT-based JPEG sources are not supported.
        TIFF sources with big-endian byte ordering are not supported.
        Interlaced GIF and PNG sources are not supported by Apple and the current implementation.
        The PLTE chunk is mandatory for color type 3, optional for types 2 and 6, and absent for types 0 and 4.
        This verification of PLTE presence is not supported.
*/
CGImageSourceStatus CGImageSourceGetStatusAtIndex(CGImageSourceRef isrc, size_t index) {
    if (!isrc) {
        return kCGImageStatusReadingHeader;
    }

    ImageSource* imageSrc = (ImageSource*)isrc;
    if (!imageSrc.data) {
        return kCGImageStatusUnexpectedEOF;
    }

    // Non-incremental source handling
    if (!imageSrc.incrementalSource) {
        // Check if the CGImageSourceCreateImageAtIndex API was invoked previously for the requested index
        // Also make sure the requested frame doesn't exceed the frame count limits    
        if (index == imageSrc.loadIndex - 1 && index < CGImageSourceGetCount(isrc)) {
            return kCGImageStatusComplete;
        } else {
            return kCGImageStatusUnknownType;
        }
    }

    // Incremental source handling
    // Streams below a minimum size return the reading header status. This is consistent with Apple's implementation.
    if ([imageSrc.data length] < c_minDataStreamSize) {
        return kCGImageStatusReadingHeader;
    }

    // Check if the CGImageSourceCreateImageAtIndex API was invoked previously for the requested index
    if (index == imageSrc.loadIndex - 1) {
        return imageSrc.loadStatus;
    } else {
        return kCGImageStatusUnknownType;
    }
}
