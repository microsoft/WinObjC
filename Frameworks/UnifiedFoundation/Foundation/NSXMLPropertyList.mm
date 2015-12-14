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

#define RAPIDXML_NO_EXCEPTIONS
#include <rapidxml.hpp>
using namespace rapidxml;
#include "Str.h"

#include "Starboard.h"
#include "Foundation/NSString.h"
#include "Foundation/NSMutableDictionary.h"
#include "Foundation/NSNumber.h"
#include "Foundation/NSDate.h"
#include "Foundation/NSMutableArray.h"
#include "Foundation/NSMutableData.h"
#include "NSXMLPropertyList.h"

namespace rapidxml {
// todo: setjump/longjump here O_O
void parse_error_handler(const char* what, void* where) {
    assert(false);
}
}

@implementation NSXMLPropertyList : NSObject
static id arrayFromElement(xml_node<>* arrayNode) {
    id result = [NSMutableArray array];

    for (xml_node<>* child = arrayNode->first_node(); child; child = child->next_sibling()) {
        [result addObject:propertyListFromElement(child)];
    }

    return result;
}

static id dataFromElement(xml_node<>* element) {
    id result = [NSMutableData data];

    for (xml_node<>* child = element->first_node(); child; child = child->next_sibling()) {
        [result appendData:dataFromBase64(child->value(), child->value_size())];
    }

    return result;
}

static id dataFromBase64(char* buffer, size_t length) {
    size_t resultLength = 0;
    unsigned char* result = (unsigned char*)EbrMalloc(length);
    unsigned char partial = 0;

    enum { load6High, load2Low, load4Low, load6Low } state = load6High;

    for (size_t i = 0; i < length; i++) {
        WORD code = buffer[i];
        unsigned char bits;

        if (code >= 'A' && code <= 'Z') {
            bits = code - 'A';
        } else if (code >= 'a' && code <= 'z') {
            bits = code - 'a' + 26;
        } else if (code >= '0' && code <= '9') {
            bits = code - '0' + 52;
        } else if (code == '+') {
            bits = 62;
        } else if (code == '/') {
            bits = 63;
        } else if (code == '=') {
            break;
        } else {
            continue;
        }

        switch (state) {
            case load6High:
                partial = bits << 2;
                state = load2Low;
                break;

            case load2Low:
                partial |= bits >> 4;
                result[resultLength++] = partial;
                partial = bits << 4;
                state = load4Low;
                break;

            case load4Low:
                partial |= bits >> 2;
                result[resultLength++] = partial;
                partial = bits << 6;
                state = load6Low;
                break;

            case load6Low:
                partial |= bits;
                result[resultLength++] = partial;
                state = load6High;
                break;
        }
    }

    id ret = [NSData dataWithBytes:result length:resultLength];
    EbrFree(result);

    return ret;
}

static id dictionaryFromElement(xml_node<>* dictElem) {
    id result = [NSMutableDictionary dictionary];
    id currentKey = nil;

    for (xml_node<>* child = dictElem->first_node(); child; child = child->next_sibling()) {
        if (strncmp(child->name(), "key", child->name_size()) == 0) {
            currentKey = [NSString stringWithCString:child->value() length:child->value_size()];
        } else {
            [result setObject:propertyListFromElement(child) forKey:currentKey];
        }
    }

    return result;
}

static id propertyListFromElement(xml_node<>* elem) {
    if (strncmp(elem->name(), "dict", elem->name_size()) == 0) {
        return dictionaryFromElement(elem);
    } else if (strncmp(elem->name(), "array", elem->name_size()) == 0) {
        return arrayFromElement(elem);
    } else if (strncmp(elem->name(), "string", elem->name_size()) == 0) {
        return [NSString stringWithCString:elem->value() length:elem->value_size()];
    } else if (strncmp(elem->name(), "integer", elem->name_size()) == 0) {
        Str numStr(elem->value(), elem->value_size());
        return [NSNumber numberWithInt:atoi(numStr.cstr())];
    } else if (strncmp(elem->name(), "real", elem->name_size()) == 0) {
        Str numStr(elem->value(), elem->value_size());
        //[[element stringValue] floatValue]);
        return [NSNumber numberWithFloat:(float)atof(numStr.cstr())];
    } else if (strncmp(elem->name(), "true", elem->name_size()) == 0) {
        return [NSNumber numberWithBool:TRUE];
    } else if (strncmp(elem->name(), "false", elem->name_size()) == 0) {
        return [NSNumber numberWithBool:FALSE];
    } else if (strncmp(elem->name(), "data", elem->name_size()) == 0) {
        return dataFromElement(elem);
    } else if (strncmp(elem->name(), "date", elem->name_size()) == 0) {
        Str numStr(elem->value(), elem->value_size());
        return [NSDate dateWithTimeIntervalSinceReferenceDate:atof(numStr.cstr())];
    } else {
        EbrDebugLog("Unrecognized element type!\n");
    }

    return nil;
}

static id propertyListFromXML(xml_node<>* node) {
    id result = nil;

    for (xml_node<>* child = node->first_node(); child; child = child->next_sibling()) {
        result = propertyListFromElement(child);
    }

    return result;
}

+ (id)propertyListFromData:(NSData*)data {
    xml_document<> doc;

    size_t length = [data length];
    char* text = doc.allocate_string(0, length + 1);
    memcpy(text, (char*)[data bytes], length);
    text[length] = '\0';

    doc.parse<0>(text);
    return propertyListFromXML(doc.first_node("plist"));
}

@end
